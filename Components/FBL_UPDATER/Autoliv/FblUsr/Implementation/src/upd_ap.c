/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        FBL updater callback routines
 *
 *  \note         Please note, that this file contains a collection of callback functions to be used with the
 *                FBL Updater. These functions may influence the behavior of the updater in principle.
 *                Therefore, great care must be taken to verify the correctness of the implementation.
 *                The contents of the originally delivered files are only examples resp. implementation proposals.
 *                With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                admissible by law or statute.
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2019-02-01  visrie  ESCAN00102012    Support for BootManager configuration
 *                         visshs  ESCAN00101664    Support for BRS
 *  02.01.00   2019-02-07  visrie  ESCAN00102028    vHSM is not set in RAM loop
 *  02.01.01   2019-03-22  visrie  ESCAN00102576    No changes
 *  02.01.02   2019-08-12  visrcn  ESCAN00102954    vHSM driver waits infinite for vHSM core
 *  03.00.00   2020-04-14  visrie  FBL-1016         Support of vBaseEnv
 *  03.01.00   2021-03-12  visjdn  FBL-2206         MISRA2012 analysis and rework
 *  03.01.01   2021-08-27  visjdn  ESCAN00109619    FBL updates may not be reset safe
 *  03.01.02   2021-10-28  visrie  ESCAN00110007    Presence patterns of bootloader not set in alternate partition
 **********************************************************************************************************************/

#define UPD_AP_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "upd_ap.h"
#include "upd_main.h"
#include "fbl_inc.h"
#include "FblBm_Cfg.h"
#include "Mcu.h"
# include "Det.h"
# if (DET_ENABLED == STD_ON)
#  if defined( FBL_APPL_ENABLE_BUSTYPE_CAN)
#   include "Can.h"
#   include "CanTp.h"
#  endif
#  if defined( FBL_APPL_ENABLE_BUSTYPE_FR)
#   include "FrTp.h"
#   include "FrTp_Common.h"
#  endif
#  if defined( FBL_APPL_ENABLE_DOIP)
#   include "DoIP.h"
#  endif
# endif

# if defined( FBLBM_ENABLE_SECURE_BOOT )
#  include "Crypto_30_vHsm.h"
#  include "Crypto_30_vHsm_Custom.h"
# endif /* FBLBM_ENABLE_SECURE_BOOT */

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLUPD_AP_VERSION != 0x0301u ) || \
    ( FBLUPD_AP_RELEASE_VERSION != 0x02u )
# error "Error in upd_ap.c: Source and Header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

typedef uint16 WRAPNV_PositionType;

/* Application software information */
#define kApplInfoSizeSwVersion                  0x03u
#define kApplInfoSizeSwPartNumber               0x0Au
#define kApplInfoSizeSwSupplierInformation      0x02u
#define kApplInfoSizeSwInfo                     (kApplInfoSizeSwVersion+    \
                                                 kApplInfoSizeSwPartNumber+ \
                                                 kApplInfoSizeSwSupplierInformation)
#define kApplInfoOffsetSwVersion                0x00u
#define kApplInfoOffsetSwPartNumber             (kApplInfoSizeSwVersion)
#define kApplInfoOffsetSwSupplierInformation    (kApplInfoOffsetSwPartNumber + kApplInfoSizeSwPartNumber)

#define FBLUPD_AP_FBL_BLOCK_NO                  0u
#define FBLUPD_AP_UPD_BLOCK_NO                  1u

/* Fingerprint status information */
#define kDiagFpStatApplValid                             0x01u
#define kDiagFpStatSwSwMismatch                          0x02u
#define kDiagFpStatSwHwMismatch                          0x04u
#define kDiagFpStatMemErased                             0x08u
#define kDiagFpStatMemProgrammed                         0x00u

/* Reprogramming process state of fingerprint status */
#define kDiagFpStatMask                                  0x70u
#define kDiagFpStatEraseStarted                          0x10u
#define kDiagFpStatEraseFinished                         0x20u
#define kDiagFpStatReprogStarted                         0x30u
#define kDiagFpStatMemCheckSucceeded                     0x40u
#define kDiagFpStatMemCheckFailed                        0x50u
#define kDiagFpStatCompatCheckFailed                     0x60u
#define kDiagFpStatOk                                    0x00u

#define kApplicationNvBlockNr 0x01
#define kFblNvBlockNr         0x00

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# if defined( FBLBM_ENABLE_SECURE_BOOT )
#  if ( FBLLIB_SECBOOT_VERSION < 0x0103u )
static tFblResult ApplFblUpdSetHsmRamLoop( void );
static tFblResult ApplFblUpdLeaveHsmRamLoop( void );
#  endif /* FBLLIB_SECBOOT_VERSION < 0x0103u */
# endif /* FBLBM_ENABLE_SECURE_BOOT */

static tFblResult ApplFblStoreSwInformation(vuint32 nvModuleId, vuint8 *buffer);
static tFblResult ApplFblUpdateFingerprintStatus(vuint32 nvModuleId, vuint8 fpStatus);

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

# if defined( FBLBM_ENABLE_SECURE_BOOT )
#  if ( FBLLIB_SECBOOT_VERSION < 0x0103u )
/***********************************************************************************************************************
 *  ApplFblUpdSetHsmRamLoop
 **********************************************************************************************************************/
/*! \brief        Set vHSM to special mode not executing from flash any more (required during flash programming)
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult ApplFblUpdSetHsmRamLoop( void )
{
   vuint8 opMode;
   tFblResult result;

   /* Initialize variables */
   result = kFblFailed;

   /* suspend vHSM operations in data flash */
   opMode = CRYPTO_30_VHSM_DATAFLASH_START;
   if (E_OK == Crypto_30_vHsm_KeyElementSet(CryptoConf_CryptoKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u))
   {
      /* Suspend vHSM operations in code flash -> send it to RAM loop*/
      opMode = CRYPTO_30_VHSM_CODEFLASH_START;
      if (E_OK == Crypto_30_vHsm_KeyElementSet(CryptoConf_CryptoKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u))
      {
         result = kFblOk;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  LeaveHsmRamloop
 **********************************************************************************************************************/
/*! \brief        vHSM is set to normal operation again (required during vHSM execution)
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult ApplFblUpdLeaveHsmRamLoop( void )
{
   vuint8 opMode;
   tFblResult result;

   /* Initialize variables */
   result = kFblFailed;

   /* Get vHSM back from RAM loop */
   opMode = CRYPTO_30_VHSM_CODEFLASH_STOP;
   if (E_OK == Crypto_30_vHsm_KeyElementSet(CryptoConf_CryptoKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u))
   {
      /* Give vHSM access to data flash operations */
      opMode = CRYPTO_30_VHSM_DATAFLASH_STOP;
      if (E_OK == Crypto_30_vHsm_KeyElementSet(CryptoConf_CryptoKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u))
      {
         result = kFblOk;
      }
   }

   return result;
}
#  endif /* FBLLIB_SECBOOT_VERSION < 0x0103u */
# endif /* FBLBM_ENABLE_SECURE_BOOT */

/***********************************************************************************************************************
 *  ApplFblStoreSwInformation
 **********************************************************************************************************************/
/*! \brief        Local function to write sw version, part number and supplier information into nv-memory
 *  \param[in]    nvModuleId Module idx for NV data structure
 *  \param[in]    buffer Contains the data to be written to nv-memory
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult ApplFblStoreSwInformation(vuint32 nvModuleId, vuint8 *buffer)
{
   tFblResult result;

   result = kFblOk;

   /* Write software information into NVM */
   result |= ApplFblNvWriteSwVersion((WRAPNV_PositionType)nvModuleId, &buffer[kApplInfoOffsetSwVersion]);
   result |= ApplFblNvWriteSwPartNumber((WRAPNV_PositionType)nvModuleId, &buffer[kApplInfoOffsetSwPartNumber]);
   result |= ApplFblNvWriteSwSupplierInformation((WRAPNV_PositionType)nvModuleId,
      &buffer[kApplInfoOffsetSwSupplierInformation]);

   return result;
}

/***********************************************************************************************************************
 *  ApplFblUpdateFingerprintStatus
 **********************************************************************************************************************/
/*! \brief        Update fingerprint status of updater block
 *  \param[in]    nvModuleId Module idx for NV data structure
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult ApplFblUpdateFingerprintStatus(vuint32 nvModuleId, vuint8 fpStatus)
{
   tFblResult result;

   result = ApplFblNvWriteFpStatusInfo(nvModuleId, &fpStatus);

   return result;
}

/***********************************************************************************************************************
 *  ApplFblUpdOemUpdateMetadata
 **********************************************************************************************************************/
/*! \brief    Update meta data information in nv-memory after FBL is successfully updated
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/

#if 0
tFblResult ApplFblUpdOemUpdateMetadata(void)
{
   tFblResult result;
   tBlockDescriptor fblBlockDescriptor;
   vuint8 swInfoBuffer[kApplInfoSizeSwInfo];
   vuint8 fpBuffer[kEepSizeFingerprint];

   vuint16 activePartitionIdx;
   vuint16 inactivePartitionIdx;
   vuint32 nvModuleId;

   /* Get block descriptor of updater block to update meta data
   * In this example the ApplInfoHeader structure is located at the start address of the logical block */
   result = FblLbtGetBlockDescriptorByNr(FBLUPD_AP_UPD_BLOCK_NO, &fblBlockDescriptor);
   if( result == kFblOk)
   {
      activePartitionIdx = (vuint16)(FLASH_SCU_SWAPCTRL - 0x01ul);
      inactivePartitionIdx = (vuint16)(1ul - (FLASH_SCU_SWAPCTRL - 0x01ul));

      /* Set active address area to read software information from updater block */
      MemDriver_SetAddressArea((vMemAccM_AddressAreaIdType)vOtaM_Partition[activePartitionIdx]);

      /* Set updater nv module index */
      nvModuleId = (FBLUPD_AP_UPD_BLOCK_NO + (activePartitionIdx * FBL_LBT_BLOCK_COUNT));

      /* Read software and hardware part number, version and supplier information
         from flashware */
      (void)FblReadProm(fblBlockDescriptor.blockStartAddress, swInfoBuffer, kApplInfoSizeSwInfo);

      /* Clear memory erase flag, set erase started state */
      result |= ApplFblUpdateFingerprintStatus(nvModuleId, kDiagFpStatEraseStarted);

      /* Read fingerprint from updater block and write into FBL blocks */
      result |= ApplFblNvReadFingerprint(nvModuleId, fpBuffer);

      /* Compute module Id of FBL block to store meta data in NV memory */
      nvModuleId = (FBLUPD_AP_FBL_BLOCK_NO + (activePartitionIdx * FBL_LBT_BLOCK_COUNT));
      result |= ApplFblStoreSwInformation(nvModuleId, swInfoBuffer);
      result |= ApplFblNvWriteFingerprint((WRAPNV_PositionType)nvModuleId, fpBuffer);

      /* Additionally, fingerprint status of FBL block is now: CRC and signature valid */
      result |= ApplFblUpdateFingerprintStatus(nvModuleId, kDiagFpStatApplValid);

#if defined( FBL_ENABLE_OTA )
      /* Compute module Id of meta data of alternate partition in NV memory */
      nvModuleId = (FBLUPD_AP_FBL_BLOCK_NO + (inactivePartitionIdx * FBL_LBT_BLOCK_COUNT));
      result |= ApplFblStoreSwInformation(nvModuleId, swInfoBuffer);
      result |= ApplFblNvWriteFingerprint((WRAPNV_PositionType)nvModuleId, fpBuffer);

      /* Additionally, fingerprint status of FBL block is now: CRC and signature valid */
      result |= ApplFblUpdateFingerprintStatus(nvModuleId, kDiagFpStatApplValid);
#endif
   }

   return result;
}
#endif 

/***********************************************************************************************************************

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/*-- Processing hook functions ---------------------------------------------------------------------------------------*/

/***********************************************************************************************************************
 *  ApplFblUpdInit
 **********************************************************************************************************************/
/*! \brief        First hook function of the update process
 *  \details      In case communication is required during update: start the communication stack here
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdInit( void )
{
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdSendResponse
 **********************************************************************************************************************/
/*! \brief        Send pending response (RCR-RP)
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdSendResponse( void )
{
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdPrepareErase
 **********************************************************************************************************************/
/*! \brief        Pre-erase hook (e.g. invalidate FBL for reset-safe operation)
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdPrepareErase( void )
{
#if defined( FBLBM_ENABLE_STANDALONE_MODE )
   tFblResult result;
   vsint16 ppblock;
   IO_PositionType patternAddress;
   IO_SizeType patternLength;
   tBlockDescriptor fblBlockDescriptor;

   /* Initialize variables */
   result = kFblFailed;

#  if defined( FBLBM_ENABLE_SECURE_BOOT )
#   if ( FBLLIB_SECBOOT_VERSION < 0x0103u )
   if (ApplFblUpdSetHsmRamLoop() == kFblOk)
#   endif
#  endif /* FBLBM_ENABLE_SECURE_BOOT */
   {
      /* Clear FBL block validity by writing the mask pattern */
      result = FblLbtGetBlockDescriptorByNr(FBL_LBT_FBL_BLOCK_NUMBER, &fblBlockDescriptor);

      if (result == kFblOk)
      {
         /* Clear updater valid pattern */
         result = FblNvPatternClr(&fblBlockDescriptor, kFblNvPatternId_BlockValidity);
      }

      if (result == kFblOk)
      {
         /* Get segment which contains PP */
         ppblock = FblNvPatternGetBaseAddr(FBL_LBT_FBL_BLOCK_NUMBER, kFblNvPatternId_BlockValidity, &patternAddress, &patternLength);

         if (ppblock >= 0)
         {
            /* Erase PP block completely to make sure that the PP area is erased */
            if (kFlashOk == MemDriver_REraseSync((FlashBlock[ppblock].end - FlashBlock[ppblock].begin) + 1u,
                     FlashBlock[ppblock].begin))
            {
               result = kFblOk;
            }
         }
      }

   }

   return result;
#else
   return kFblOk;
#endif /* FBLBM_ENABLE_STANDALONE_MODE */
}

/***********************************************************************************************************************
 *  ApplFblIncFblProgAttempts
 **********************************************************************************************************************/
/*! \brief       Increment programming attempt counter
 *  \param[in]   blockDescriptor Block descriptor
 *  \return      kFblOk / kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblIncFblProgAttempts( )
{
   tFblResult status;
   vuint8 nvBuffer[sizeof(vuint16)];
   vuint16 progAttempts;

   status = (tFblResult)ApplFblNvReadProgAttempts(kFblNvBlockNr, nvBuffer);
   progAttempts = (vuint16)FblMemGetInteger(sizeof(nvBuffer), nvBuffer);

   if (status == kFblOk)
   {
      /* Value is stored inverted because of erase value */
      progAttempts = FblInvert16Bit(progAttempts);
      progAttempts++;
      progAttempts = FblInvert16Bit(progAttempts);

      FblMemSetInteger(sizeof(nvBuffer), progAttempts, nvBuffer);
      status = (tFblResult)ApplFblNvWriteProgAttempts((IO_PositionType)kFblNvBlockNr, nvBuffer);
   }

   return status;
}

/***********************************************************************************************************************
 *  ApplFblUpdSwapMetadata
 **********************************************************************************************************************/
void ApplFblUpdSwapMetadata( void )
{
   static uint8 blockFingerprint[kEepSizeFingerprint];
   static uint8 fpStatus_u8;
   static uint16 progAttempts_u16;
   static uint32 swVersion[3];

   /*Set Fingeprint Status Information to Valid (0x01)*/
   fpStatus_u8 = kDiagFpStatApplValid;
   ApplFblNvWriteFpStatusInfo(0, &fpStatus_u8);

   /*Transfer fingerprint data from application block to bootloader block*/
   /*Read application stored fingeprint and transfer to boot fingerprint (0 - Fbl, 1 - Application)*/
   ApplFblNvReadFingerprint(kApplicationNvBlockNr, blockFingerprint);
   ApplFblNvWriteFingerprint(kFblNvBlockNr, blockFingerprint);

   ApplFblIncFblProgAttempts();

   ApplFblNvReadSwVersion(kApplicationNvBlockNr, swVersion);
   ApplFblNvWriteSwVersion(kFblNvBlockNr, swVersion);

   fpStatus_u8 = kDiagFpStatEraseStarted;

   swVersion[0] = 0xFF;
   swVersion[1] = 0xFF;
   swVersion[2] = 0xFF;

   /*Replace SW version and Status Info for application block*/
   ApplFblNvWriteFpStatusInfo(kApplicationNvBlockNr, &fpStatus_u8);
   ApplFblNvWriteSwVersion(kApplicationNvBlockNr, swVersion);
}


/***********************************************************************************************************************
 *  ApplFblUpdFinalizeErase
 **********************************************************************************************************************/
/*! \brief        Post-erase hook
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdFinalizeErase( void )
{
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdPrepareProgram
 **********************************************************************************************************************/
/*! \brief        Pre-programming hook
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdPrepareProgram( void )
{
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdFinalizeProgram
 **********************************************************************************************************************/
/*! \brief        Pre-programming hook
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdFinalizeProgram( void )
{
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdFinalizeVerify
 **********************************************************************************************************************/
/*! \brief        Hook function when the verification was successful
 *  \details      Additional flash operations possible after code verification (e.g. TriCore: write BMIHD)
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdFinalizeVerify( void )
{
#if defined( FBLBM_ENABLE_STANDALONE_MODE )
   tFblResult result;

   tFblHeader fblHeader;
   tBlockDescriptor fblBlockDescriptor;

   /* Read FblHeader */
   /* PRQA S 0306 1 */ /* MD_FblUpdAp_0306 */
   if (FblReadProm(FblBmHeaderTable->fblHeaderAddress, (vuint8 *)&fblHeader, sizeof(tFblHeader)) != sizeof(tFblHeader))
   {
      result = kFblFailed;
   }
   else
   {
      result = kFblOk;
   }

# if defined( FBLBM_ENABLE_SECURE_BOOT )
#   if ( FBLLIB_SECBOOT_VERSION < 0x0103u )
    if (result == kFblOk)
    {
       result = ApplFblUpdLeaveHsmRamLoop();
    }
#   endif
#  if defined( FBLSB_ENABLE_GENERATE_CMAC )
   if (result == kFblOk)
   {
      result = FblSb_UpdateFblMac(&fblHeader);
   }
#  endif /* FBLSB_ENABLE_GENERATE_CMAC */
# endif /* FBLBM_ENABLE_SECURE_BOOT */

   if (result == kFblOk)
   {
      /* Initialize FBL block descriptor */
      fblBlockDescriptor.blockStartAddress = fblHeader.fblStartAddress;
      fblBlockDescriptor.blockLength = fblHeader.fblLength;
      /* PRQA S 0306 1 */ /* MD_FblUpdAp_0306 */
      fblBlockDescriptor.bmHeaderAddress = (tFblAddress)fblHeader.bmHeader;
      fblBlockDescriptor.mandatoryType = TRUE;
      fblBlockDescriptor.blockNr = 0x00u;

      /* Set presence pattern of Bootloader in active partition */
      result = FblNvPatternSetByBlockDescriptor(&fblBlockDescriptor, kFblNvPatternId_BlockValidity);
#if defined( FBL_ENABLE_OTA )
      if (result == kFblOk)
      {
         /* Also set presence pattern of Bootloader in inactive partition */
         fblBlockDescriptor.blockStartAddress = fblHeader.fblStartAddress + 0x600000ul;
         result = FblNvPatternSetByBlockDescriptor(&fblBlockDescriptor, kFblNvPatternId_BlockValidity);
      }
#endif
   }

   /*Swap metadata*/
   ApplFblUpdSwapMetadata();

   return result;
#else
   return kFblOk;
#endif /* FBLBM_ENABLE_STANDALONE_MODE */
}

/***********************************************************************************************************************
 *  ApplFblUpdInvalidateUpdater
 **********************************************************************************************************************/
/*! \brief        Callback function to invalidate the updater/application
 *  \details      Update validity information of e.g. NV-data
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdInvalidateUpdater( void )
{
   return kFblOk;
}

#define FBL_UPD_AP_RAMCODE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  ApplFblUpdRemoveAndReset
 **********************************************************************************************************************/
/*! \brief        Last callback function in the update process. This function shall not return.
 *  \details      Removes (invalidates) the updater/application if required and performs a reset.
 *                The function has to be located in RAM when the whole updater should get erased
 *                (this also affects the functionality that is used within this function).
 *  \return       Should never return
 **********************************************************************************************************************/
tFblResult ApplFblUpdRemoveAndReset( void )
{
   FBL_UPD_CALLOUT_RESET_VFP();
   FBL_UPD_CALLOUT_RESET();

   while (1)
   {
      ;
   }

   return kFblFailed; /* PRQA S 2880 */ /* MD_MSR_Unreachable */
}
#define FBL_UPD_AP_RAMCODE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*-- Segment handling hook functions ---------------------------------------------------------------------------------*/

/***********************************************************************************************************************
 *  ApplFblUpdGetSegment
 **********************************************************************************************************************/
/*! \brief        Get segment of new FBL referenced by given index
 *  \param[in]    index Index of referenced segment
 *  \param[out]   pSegment Pointer resulting segment information
 *  \return       Result of operation
 *                   kFblOk when referenced segment is available
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdGetSegment( vuintx index, V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegment )
{
   tFblResult result;

   result = kFblFailed;

   if (index < 1u)
   {
      /* Initialize single example segment */
      pSegment->source  = 0x10000u;
      pSegment->target  = 0x0000u;
      pSegment->length  = 0x1000u;

      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblUpdAdjustSegmentProgram
 **********************************************************************************************************************/
/*! \brief        Adjust segments for programming / verification operation
 *  \param[in,out]   pSegmentList Pointer to segment list, first entry contains input segment
 *  \param[in,out]   pSegmentCount Input: Size of segment list
 *                      Output: Number of resulting segments
 *  \return       Result of operation
 *                   kFblOk when segment adjustment was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
tFblResult ApplFblUpdAdjustSegmentProgram( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)pSegmentList;
#endif
   /* No adjustment performed */
   *pSegmentCount = 1u;

   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdAdjustSegmentValidity
 **********************************************************************************************************************/
/*! \brief        Adjust segments for validation operation
 *  \param[in,out]   pSegmentList Pointer to segment list, first entry contains input segment
 *  \param[in,out]   pSegmentCount Input: Size of segment list
 *                      Output: Number of resulting segments
 *  \return       Result of operation
 *                   kFblOk when segment adjustment was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
tFblResult ApplFblUpdAdjustSegmentValidity( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)pSegmentList;
#endif
   /* No special handling for validity range */
   *pSegmentCount = 0u;

   return kFblOk;
}

/*-- Updater callout functions ---------------------------------------------------------------------------------------*/

/***********************************************************************************************************************
 *  ApplFblUpdInitPowerOn
 ***********************************************************************************************************************/
/*! \brief        Initialization callout
 ***********************************************************************************************************************/
void ApplFblUpdInitPowerOn( void )
{
# if defined( BRS_FBL_LEGACY )
#  if defined( BRSHW_PREINIT_AVAILABLE )
   /* HW specific pre-initialization. */
   BrsHwPreInitPowerOn();
#  endif /* BRSHW_PREINIT_AVAILABLE */

#  if defined( BRS_ENABLE_WATCHDOG )
   /* Disable Watchdog */
   BrsHwWatchdogInitPowerOn();
#  endif /* BRS_ENABLE_WATCHDOG */

#  if defined( BRS_ENABLE_PLLCLOCKS )
   /* Initialize the PLLs. */
   BrsHwPllInitPowerOn();
#  endif /* BRS_ENABLE_PLLCLOCKS */

#  if defined( BRSHW_DISABLE_ECC_AVAILABLE )
   /* Disable Flash ECC error reporting. */
   BrsHwDisableEccErrorReporting();
#  endif /* BRSHW_DISABLE_ECC_AVAILABLE */

#  if defined( FBL_ENABLE_PRE_TIMERINIT )
   /* Timer is stopped by mode switch and has to be re-initialized. */
   FblTimerInit();
#  endif /* FBL_ENABLE_PRE_TIMERINIT */

#  if defined( FBL_ENABLE_VECTOR_HW ) && \
      defined( BRS_ENABLE_PORT )
   /* Perform Port configuration. */
   BrsHwPortInitPowerOn();
   BrsHwEvaBoardInitPowerOn();
#  endif /* FBL_ENABLE_VECTOR_HW && BRS_ENABLE_PORT */
# endif /* BRS_FBL_LEGACY */

   FBL_UPD_CALLOUT_INIT_POWER_ON_HW();
   FBL_UPD_CALLOUT_INIT_POWER_ON_OEM();
}

/***********************************************************************************************************************
 *  ApplFblUpdSetVfp
 ***********************************************************************************************************************/
/*! \brief        Callout to enable programming voltage
 ***********************************************************************************************************************/
void ApplFblUpdSetVfp( void )
{
# if defined( BRSHW_VOLTAGE_FOR_FLASH_PROGRAMMING_AVAILABLE )
   /* Set flash programming voltage */
   BrsHwSetVfp();
# endif /* BRSHW_VOLTAGE_FOR_FLASH_PROGRAMMING_AVAILABLE */
}

/***********************************************************************************************************************
*  ApplFblUpdResetVfp
***********************************************************************************************************************/
/*! \brief        Callout to disable programming voltage
 ***********************************************************************************************************************/
void ApplFblUpdResetVfp( void )
{
# if defined( BRSHW_VOLTAGE_FOR_FLASH_PROGRAMMING_AVAILABLE )
   /* Reset flash programming voltage */
   BrsHwResetVfp();
# endif /* BRSHW_VOLTAGE_FOR_FLASH_PROGRAMMING_AVAILABLE */
}

/***********************************************************************************************************************
 *  ApplFblUpdReset
 ***********************************************************************************************************************/
/*! \brief        Callout to perform reset
 ***********************************************************************************************************************/
void ApplFblUpdReset( void )
{
  Mcu_PerformReset();
}

/***********************************************************************************************************************
 *  ApplFblUpdTrcvrNormalMode
 **********************************************************************************************************************/
/*! \brief       Activate transceiver if necessary (e.g. pin configuration ENABLE = 1, _STDBY = 1)
 **********************************************************************************************************************/
void ApplFblUpdTrcvrNormalMode( void )
{
}

/***********************************************************************************************************************
 *  ApplFblUpdPrepareResponsePending
 ***********************************************************************************************************************/
/*! \brief        Callout to prepare buffer with response pending (RCR-RP) message
 ***********************************************************************************************************************/
void ApplFblUpdPrepareResponsePending(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pResponse)
{
   /* Prepare RCR-RP for service EcuReset */
   pResponse[0u] = 0x7Fu;
   pResponse[1u] = 0x11u;
   pResponse[2u] = 0x78u;
}

/*-- Other callout functions -----------------------------------------------------------------------------------------*/

/***********************************************************************************************************************
 *  ApplTrcvrNormalMode
 **********************************************************************************************************************/
/*! \brief       Activate transceiver if necessary (e.g. pin configuration ENABLE = 1, _STDBY = 1)
 **********************************************************************************************************************/
void ApplTrcvrNormalMode( void )
{
   /* Leave this function empty */
}

/***********************************************************************************************************************
 *  ApplFblCanBusOff
 **********************************************************************************************************************/
/*! \brief       This call-back function is called if the CAN controller enters bus-off state.
 **********************************************************************************************************************/
void ApplFblCanBusOff( void )
{
}

#if defined( DTL_ENABLE_DEBUG )
#define FBLDTLLIN_RAMCODE_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  ApplDtlFatalError
 **********************************************************************************************************************/
/*! \brief       Indication of fatal errors detected by the diagnostic transport layer
 *  \param[in]   error error code
 **********************************************************************************************************************/
void ApplDtlFatalError( vuint8 error )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)error;
#endif
}
#define FBLDTLLIN_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

#define FBLDRVLIN_RAMCODE_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_MemMap */
#if defined( LIN_APISTYLE_VECTOR )
/***********************************************************************************************************************
 *  ApplLinWakeUp
 **********************************************************************************************************************/
/*! \brief       Notification of a transition to wakeup after reception or transmission of a wakeup frame
 **********************************************************************************************************************/
void ApplLinWakeUp( void )
{
}

/***********************************************************************************************************************
 *  ApplLinBusSleep
 **********************************************************************************************************************/
/*! \brief       Notification of a transition to sleep mode
 *  \details     The transition to sleep mode is performed after the transmission or reception
 *               of a sleep mode frame or after a bus idle timeout
 **********************************************************************************************************************/
void ApplLinBusSleep( void )
{
}


/***********************************************************************************************************************
 *  ApplLinProtocolError
 **********************************************************************************************************************/
/*! \brief       Indication of protocol errors detected by the LIN driver
 *  \param[in]   error The error code of the detected error
 *               vMsgHandle The handle of the message processed when the error is detected.
 *               When no message can be assigned, kMsgHandleDummy is used
 **********************************************************************************************************************/
void ApplLinProtocolError(vuint8 error, tLinFrameHandleType vMsgHandle )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)error;
   (void)vMsgHandle;
#endif
}
#endif /* LIN_APISTYLE_VECTOR */
#define FBLDRVLIN_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBL_ENABLE_ASSERTION )
/***********************************************************************************************************************
 *  ApplFblFatalError
 **********************************************************************************************************************/
/*! \brief       Will be called in case of an urecoverable error
 **********************************************************************************************************************/
void ApplFblFatalError( FBL_DECL_ASSERT_EXTENDED_INFO(vuint8 errorCode) )
{
   /* Change this variable in debugger in order to return to caller */
   volatile vuint8 stayInWhile = 1u;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)errorCode;
#endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   while (0u != stayInWhile)
   {
      (void)FblLookForWatchdog();
   }
}
#endif /* FBL_ENABLE_ASSERTION */


# define FBL_UPD_AP_RAMCODE_START_SEC_CODE
# include "MemMap.h"

# if (DET_ENABLED == STD_ON)
/***********************************************************************************************************************
 *  ApplFbl_DetEntryHandler
 **********************************************************************************************************************/
/*! \brief       Called by DET module to check if a DET error is intended bootloader behavior or not.
 *  \param[in]   ModuleId Code number of the encountered assertion
 *  \param[in]   InstanceId Name of the affected module (Only if extended info is enabled)
 *  \param[in]   ApiId Line number where the assertion occurred (Only if extended info is enabled)
 *  \param[in]   ErrorId Line number where the assertion occurred (Only if extended info is enabled)
 *  \return      Report if error should be handed over to DET or not
 **********************************************************************************************************************/
#  if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
FUNC(Std_ReturnType, DET_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
#  else
FUNC(boolean, DET_APPL_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
#  endif /* DET_AR_RELEASE_ */
{
#  if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
   Std_ReturnType result = E_OK;
   Std_ReturnType ignoreResult = E_NOT_OK;
#  else
   boolean result = FALSE;
   boolean ignoreResult = TRUE;
#  endif /* DET_AR_RELEASE_ */

   switch (ModuleId)
   {
#  if defined( FBL_APPL_ENABLE_BUSTYPE_CAN )
      case CANTP_MODULE_ID:
      {
         switch (ErrorId)
         {
            /* CAN TP errors which can be triggered from outside shouldn't trigger a DET. */
            case CANTP_E_INVALID_RX_BUFFER:
            case CANTP_E_INVALID_RX_LENGTH:
            case CANTP_E_INVALID_TATYPE:
            case CANTP_E_INVALID_FRAME_TYPE:
            case CANTP_E_RX_TIMEOUT_AR:
            case CANTP_E_RX_TIMEOUT_BR:
            case CANTP_E_RX_TIMEOUT_CR:
            case CANTP_E_RX_INVALID_SN:
            case CANTP_E_RX_WFTMAX:
            case CANTP_E_RX_RESTART:
            case CANTP_E_NO_ERROR:
            {
               result = ignoreResult;
               break;
            }
            default:
            {
               break;
            }
         }
         break;
      }
      case CAN_MODULE_ID:
      {
         switch (ErrorId)
         {
            case CAN_E_DATALOST:
            {
               result = ignoreResult;
               break;
            }
            default:
            {
               break;
            }
         }
      }
#  endif /* FBL_APPL_ENABLE_BUSTYPE_CAN */
#  if defined( FBL_APPL_ENABLE_BUSTYPE_FR )
      case FRTP_MODULE_ID:
      {
         switch (ErrorId)
         {
            case FRTP_E_SEG_ERROR:
            case FRTP_E_UMSG_LENGTH_ERROR:
            case FRTP_E_NO_CHANNEL:
            {
               result = ignoreResult;
               break;
            }
            default:
            {
               break;
            }
         }
         break;
      }
#  endif /* FBL_APPL_ENABLE_BUSTYPE_FR */
#  if defined( FBL_APPL_ENABLE_DOIP )
      case DOIP_MODULE_ID:
      {
         switch (ErrorId)
         {
            case DOIP_E_NOBUFS:
            {
               result = ignoreResult;
               break;
            }
            default:
            {
               break;
            }
         }
         break;
      }
#  endif /* FBL_APPL_ENABLE_DOIP */
      default:
      {
         /* Unknown module. Keep error. */
         break;
      }
   }

   return result;
}
# endif /* DET_ENABLED == STD_ON */

# if defined( FBLCW_MODULE_COMM ) && ( FBLCW_MODULE_COMM == STD_ON )
/***********************************************************************************************************************
 *  ApplFbl_ComM_SilentComModeEntered
 **********************************************************************************************************************/
/*! \brief       Indication that silent communication mode has been entered
 *  \param[in]   channel ComM channel index
 **********************************************************************************************************************/
FUNC(void, FBLCW_CODE) ApplFbl_ComM_SilentComModeEntered( NetworkHandleType channel )
{
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)channel;
#  endif
}

/***********************************************************************************************************************
 *  ApplFbl_ComM_NoComModeEntered
 **********************************************************************************************************************/
/*! \brief       Indication that no communication mode has been entered
 *  \param[in]   channel ComM channel index
 **********************************************************************************************************************/
FUNC(void, FBLCW_CODE) ApplFbl_ComM_NoComModeEntered( NetworkHandleType channel )
{
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)channel;
#  endif
}

/***********************************************************************************************************************
 *  ApplFbl_ComM_FullComModeEntered
 **********************************************************************************************************************/
/*! \brief       Indication that full communication mode has been entered
 *  \param[in]   channel ComM channel index
 **********************************************************************************************************************/
FUNC(void, FBLCW_CODE) ApplFbl_ComM_FullComModeEntered( NetworkHandleType channel )
{
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)channel;
#  endif
}
# endif /* FBLCW_MODULE_COMM == STD_ON */

# define FBL_UPD_AP_RAMCODE_STOP_SEC_CODE
# include "MemMap.h"


/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_FblUpdAp_0306:
      Reason:     Address conversion between integer values and pointers is required to allow for hardware independent
                  configuration and address range checks.
      Risk:       The size of integer required to hold the result of a pointer cast is implementation-defined.
      Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
                  specific basis. The correctness of the respective implementation is verified by runtime tests.

*/

/***********************************************************************************************************************
 *  END OF FILE: UPD_AP.C
 **********************************************************************************************************************/
