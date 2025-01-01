/* Kernbauer Version: 1.12 Konfiguration: FBL Erzeugungsgangnummer: 1 */

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application dependent nonvolatile memory access routines
 *
 *  \note          Please note, that this file contains a collection of callback functions to be used with the
 *                 Flash Bootloader. These functions may influence the behavior of the bootloader in principle.
 *                 Therefore, great care must be taken to verify the correctness of the implementation.
 *                 The contents of the originally delivered files are only examples resp. implementation proposals.
 *                 With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                 Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                 admissible by law or statute.
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *  02.00.00   2019-03-12  visrie  ESCAN00102453    Added support for LibNvPattern, LibLbtAccess and SecureBoot
 *  03.00.00   2020-10-14  viscb   FBL-2177         DRECU2020-01 adaptions, additional callout functions7
 *  03.01.00   2021-01-19  viscb   ESCAN00107756    Sw-Sw compatibility check always succeeds for presence patterns
 *                         viscb   FBL-2244         DRECU2020-01 adaptions
 *                                                    - Adapted interface for secure boot
 *                                                    - Simplified updater integration
 *                                                    - Added support for OTA
 *                                                    - Added support for downgrade protection
 *                                                    - Migration to MISRA 2012
 *  03.01.01   2021-02-02  viscb   ESCAN00108450    QM release
 *  03.02.00   2021-04-21  viscb   ESCAN00108552    Downgrade protection check may falsely fail
 *                         viscb   ESCAN00108672    Downgrade protection check may falsely succeed
 *                         viscb   ESCAN00108921    ApplFblGetNvModuleId() returns invalid module id
 *  03.03.00   2022-03-16  vishor  FBL-4621         MB MMA Rework
 *                                 ESCAN00110813    Compiler error: identifiers "blockFilter"and "iterBlock"
 *                                                   are undefined
 *                                 ESCAN00110836    Compiler error: argument of type "vuint8 const *" is incompatible
 *                                                   with parameter of type "vuint8 *"
 *  03.04.00   2022-06-01  vishor  FBL-5094         MB MMA Rework
 *                                 ESCAN00111479    Downgrade Protection uses DPV instead of software version
 *                                                   for comparison
 *  03.04.01   2022-08-31  visjns  FBL-5754         Programming attempts check fails with OTA update
 *  03.04.02   2022-12-15  visjdn  ESCAN00112522    Downgrade protection check fails because of wrong byte order
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY (kbFbl_apAPI.c)
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2018-09-14  visrie  ESCAN00100739    Added support for FblLib_NvPattern
 *                                                  Removed unused code
 *                         viscb   ESCAN00101418    Callout function for memory condition check
 *                         visach  ESCAN00101686    Added interface definition for vendor verification routine
 *  02.01.00   2019-02-26  visrie  ESCAN00102257    Added additional callout functions
 *  02.01.01   2019-09-23  visrie  FBL-452          Added support for FrArTp
 *  02.02.00   2019-12-05  visrie  FBL-458          Added FblMio callout functions
 *  02.03.00   2020-05-07  visrie  FBL-1414         Added callout functions for One-Step-Updater
 *  02.03.01   2020-06-02  visjdn  ESCAN00106533    Update to latest MISRA version
 *  02.03.02   2020-09-14  visrcn  FBL-2257         Add MISRA justifications
 *  02.03.03   2020-11-23  visrcn  FBL-2564         Add MISRA justifications
 *  02.03.04   2021-03-19  visjdn  FBL-2916         Add MISRA justifications
 *  02.04.00   2021-05-26  vishor  FBL-3165         MISRA corrections and justifications
 *  02.05.00   2021-06-15  visrie  FBL-3591         Provide default implementation for ApplFbl_DetEntryHandler
 *                                                  Add MISRA justifications
 *  02.06.00   2021-07-15  visjdn  FBL-3381         Re-mapping of EcuM_SetWakeupEvent
 *  02.07.00   2021-07-22  visrie  FBL-3822         Update to QAC9 Helix-2021
 *  02.08.00   2021-09-14  visjdn  FBL-2859         Add MISRA justifications
 *  02.09.00   2021-10-12  vistmo  FBL-3901         Add authentication callbacks
 *  02.10.00   2021-10-15  visrie  FBL-3945         Remove content of ApplFblStartApplication
 *  02.10.01   2021-11-12  vishor  ESCAN00110133    Compiler error: Unknown symbols
 *                                                   ApplFblSave/RestoreStatusSector/Dynamic
 *  02.10.02   2022-06-27  visrie  FBL-4694         Add MISRA justifications
 *  02.10.03   2022-10-20  visjns  FBL-5452         Add MISRA justifications
 *  02.11.00   2022-12-22  vistbe  FBL-5691         Add support for LZSS compression
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2019-03-12  visrie  ESCAN00102454    Added support for LibNvPattern, LibLbtAccess and SecureBoot
 *  02.00.01   2019-04-29  viscb   ESCAN00102998    Clear internal state flag for resume after erase
 *  03.00.00   2020-10-06  viscb   FBL-2177         DRECU2020-01 adaptions, data processing
 *  03.01.00   2021-01-19  viscb   FBL-2244         DRECU2020-01 adaptions
 *                                                    - Simplified updater integration
 *                                                    - Added support for OTA
 *                                                    - Added support for downgrade protection
 *                                                    - Migration to MISRA 2012
 *  03.01.01   2021-02-02  viscb   ESCAN00108447    QM release
 *  03.02.00   2021-04-21  viscb   ESCAN00108550    ReadDataByIdentifier returns incorrect data for requested meta data
 *                                 ESCAN00108549    Fingerprint status is not updated correctly
 *                                 ESCAN00108532    Signature verification of downloaded block fails
 *                                 ESCAN00108591    Application is not started after OFR swap
 *  03.03.00   2021-07-12  vishor  FBL-3567         Add support for Csm-based suspend/resume
 *  03.03.01   2021-08-24  vishor  ESCAN00109880    Resume information from OFR download is not invalidated in
 *                                                  case FBL download is started
 *  03.03.02   2021-08-27  vishor  ESCAN00109972    Compiler error: Incompatible type for
 *                                                  ApplFblNvWriteSegmentCount/ApplFblNvReadSegmentCount
 *  03.03.03   2021-10-19  vistmo  ESCAN00110504    Compiler error: 'SecM_CancelAllJobs' undefined
 *  03.03.04   2021-11-19  visjdn  ESCAN00108780    [XCP] Bootloader does not process XCP messages
 *  03.04.00   2022-03-16  vishor  FBL-4621         MB MMA Rework
 *                                 ESCAN00107629    Compressed and encrypted download stops with NRC 0x72 in service
 *                                                   Request Transfer Exit
 *                                 ESCAN00110835    Compiler error: kEepApplInconsistent not defined
 *                                 ESCAN00110881    Compiler error: identifier "consumedLen" and "producedLen"
 *                                                   are undefined
 *  03.05.00   2022-06-01  vishor  FBL-5094         MB MMA Rework
 *                                 ESCAN00112002    DID 0xEF02 - Standard Bootloader Software Information implemented
 *                                                   with wrong number of bytes
 *  03.05.01   2022-06-23  vishor  ESCAN00112105    AES IV is not extracted from downloaded data
 *                                 ESCAN00112155    Decryption is not correctly finalized during download
 *  03.05.02   2022-08-29  visjns  ESCAN00112404    Missing implementation of DID 0xEF05: Minimum Software Version
 *                                 ESCAN00112298    Programming attempts check fails with OTA update
 *  03.05.03   2022-12-12  vismix  ESCAN00112835    Access to programming attempt counter fails
 **********************************************************************************************************************/


#define FBL_APNV_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

#include "BrsMain.h"
#include "BrsHw.h"
# include "Det.h"
# if (DET_ENABLED == STD_ON)
#  if defined( FBL_APPL_ENABLE_BUSTYPE_CAN )
#   include "Can.h"
#   include "CanTp.h"
#  endif
#  if defined( FBL_APPL_ENABLE_BUSTYPE_FR )
#    include "FrTp.h"
#    include "FrTp_Common.h"
#  endif
#  if defined( FBL_APPL_ENABLE_DOIP )
#   include "DoIP.h"
#  endif
# endif

#ifdef VSWT_USED
# include "fbl_vSwt_Helper.h"
#endif

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLKBAPI_FRAMENV_DAIMLER_VERSION != 0x0304u ) || \
    ( FBLKBAPI_FRAMENV_DAIMLER_RELEASE_VERSION != 0x02u )
# error "Error in FBL_APNV.C: Source and header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Logical block table dependency and validity check configuration */
/* PRQA S 3453 TAG_FblApNv_3453_2 */ /* MD_CBD_19.7 */
/** System must consist of at least two logical blocks to activate dependency check */
#define FBL_MIN_BLOCKS_FOR_DEPENDENCY    2
/** First logical block number of the application */
#define FBL_START_LBT_APP                0
/* PRQA L:TAG_FblApNv_3453_2 */

/* PreCheck Programming Dependencies */

/* Request format per block:
 * 1 byte logcal block number,
   1 byte len,
   2 bytes SW  compatibility,
   1 byte No of hw version bytes
   n*2 bytes HW compatibity version */

#define kFblPreChkSwVerSize         2u
#define kFblPreChkHwVerSize         2u

/* Fix length of blockNr, length, SwVersion */
#define kFblPreChkRecordSize        (2u + kFblPreChkSwVerSize + 1u)

#define kFblBlockNrOffset(baseOffset)  (baseOffset)
#define kFblLengthOffset(baseOffset)   ((baseOffset) + 1u)
#define kFblSwVerOffset(baseOffset)    ((baseOffset) + 2u)
#define kFblHwLengthOffset(baseOffset) ((baseOffset) + 4u)
#define kFblHwVerOffset(baseOffset)    ((baseOffset) + 5u)

#define kFblBmFblApplUpdatedMagicByte0        0x41u /* 'A' */
#define kFblBmFblApplUpdatedMagicByte1        0x70u /* 'p' */
#define kFblBmFblApplUpdatedMagicByte2        0x70u /* 'p' */
#define kFblBmFblApplUpdatedMagicByte3        0x6cu /* 'l' */
#define kFblBmFblApplUpdatedMagicByte4        0x75u /* 'u' */
#define kFblBmFblApplUpdatedMagicByte5        0x70u /* 'p' */
#define kFblBmFblApplUpdatedMagicByte6        0x64u /* 'd' */
#define kFblBmFblApplUpdatedMagicByte7        0x74u /* 't' */
#define kFblApplicationUpdated         0xA5u
/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/* copied from Dcm_CoreTypes of Dcm version 15.00.00 */
/*! Programming condition information */
struct DCM_PROGCONDITIONSTYPE_TAG
{
//# if (DCM_NET_GENERIC_CONNECTION_ENABLED == STD_ON)
//  uint16  ConnectionId;         /*!< Unique connection identifier */
//# endif
  uint16  TesterSourceAddr;     /*!< The client ID (source address). Note: AR 4.0.3 specifics the client ID to be a U8 for this API, but the connection configuration has a 16 Bit value! */
  uint8   ProtocolId;           /*!< The protocol ID */
  uint8   Sid;                  /*!< The request SID to be responded to */
  uint8   SubFuncId;            /*!< The sub-function ID to be responded to */
  boolean ReprogrammingRequest; /*!< Specifies whether an ECU preprogramming is needed (TRUE - ECU reprogramming, FALSE - no ECU reprogramming) */
  boolean ApplUpdated;          /*!< Specifies whether the application has been updated (TRUE - application updated, FALSE - no application updated) */
  boolean ResponseRequired;     /*!< Specifies whether a response to the SID and sub-function has to be sent (TRUE) or just the requested diagnostic session shall be entered (FALSE) */
};
typedef struct DCM_PROGCONDITIONSTYPE_TAG Dcm_ProgConditionsType;

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define FBLAP_PROGCONDITION_START_SEC_VAR_NOINIT
#include "MemMap.h"
Dcm_ProgConditionsType Fbl_ProgConditions;
#define FBLAP_PROGCONDITION_STOP_SEC_VAR_NOINIT
#include "MemMap.h"

/* Internal buffers */
static vuint8 blockFingerprint[kEepSizeFingerprint];
#if !defined( FBL_ENABLE_OTA ) && \
     defined( FBL_ENABLE_PRESENCE_PATTERN )
V_MEMRAM0 static V_MEMRAM1 tBlockDescriptor V_MEMRAM2 currentValidatedBlock;
#endif

/*Vehicle Identification Number (VIN) needed for DoIP Vehicle Announcement/Identification*/
static const vuint8 kVin[] = { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x30 };
static const vuint8 kDiagPowerMode = 0x00u;

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/* The following constant is used by the HW/SW compatibility check. *
 * This value has to be replaced by the ECU-specific data.         */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 HardwareCompatibilityVersion[2] = {0x00u,0x12u};
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 g_isvHsmUpdBlock;

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
#else
static tFblResult ApplFblChgBlockValid( vuint8 mode, tBlockDescriptor descriptor );
#endif /* FBL_ENABLE_PRESENCE_PATTERN */

/* Configuration checks ******************************************************/
#if defined( FBL_ENABLE_PRESENCE_PATTERN )
/* we have no validity flags in NvM -> create define here for local variables */
#define kEepSizeValidityFlags (((FBL_MTAB_NO_OF_BLOCKS-1)/8)+1)
#else
/* verify if the validity flags are the correct size */
# if ( kEepSizeValidityFlags != (((FBL_MTAB_NO_OF_BLOCKS-1)/8)+1) )
#  error "Size of block validity data is not correct. Check GENy configuration of size."
# endif
#endif

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
#else
/***********************************************************************************************************************
 *  ApplFblChgBlockValid
 **********************************************************************************************************************/
/*! \brief       This function changes the validation flag of a logical block. The state information is stored inverted.
 *  \pre         EEPROM driver must be initialized before call
 *  \param[in]   mode (kEepValidateBlock/kEepInvalidateBlock)
 *  \param[in]   descriptor
 *  \return      kFblOk/kFblFailed
 **********************************************************************************************************************/
static tFblResult ApplFblChgBlockValid( vuint8 mode, tBlockDescriptor descriptor )
{
   vuint8         blockAddress;
   vuint8         validityFlags[kEepSizeValidityFlags];
   vuint8         validityMask;
   vuint8         validityCheck[kEepSizeValidityFlags];
   tFblResult     result;

   blockAddress = (descriptor.blockNr >> 3u);
   validityMask = (vuint8)(1u << (descriptor.blockNr & 0x07u));

   result = kFblFailed;

   if (ApplFblNvReadValidityFlags(validityFlags) == kFblOk)
   {
      if (mode == kEepValidateBlock)
      {
         validityFlags[blockAddress] &= FblInvert8Bit(validityMask);
      }
      else
      {
         validityFlags[blockAddress] |= validityMask;
      }

      /* Modify validity flags */
      if (ApplFblNvWriteValidityFlags(validityFlags) == kFblOk)
      {
         /* Read modified flags */
         if (ApplFblNvReadValidityFlags(validityCheck) == kFblOk)
         {
            /* Check if flags were written correctly */
            if (validityCheck[blockAddress] == validityFlags[blockAddress])
            {
               result = kFblOk;
            }
         }
      }
   }
   return result;
}
#endif /* FBL_ENABLE_PRESENCE_PATTERN */

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ApplFblAdjustLbtBlockData
 **********************************************************************************************************************/
/*! \brief         This function is called whenever the bootloader queries the range for the logical blocks.
 *  \details       This info is typically stored in fbl_mtab.c and generated from GENy. This function
 *                 can be used to spare a range from the LBT at runtime that shall not be flashed, e.g. PresencePattern.
 *  \param[in,out] blockDescriptor Pointer to LBT-Descriptor
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblAdjustLbtBlockData( tBlockDescriptor * blockDescriptor )
{
   tFblResult        result;
#if defined( FBL_ENABLE_PRESENCE_PATTERN )
   IO_PositionType   presPtnAddress;
   IO_SizeType       presPtnLen;
#endif
#if defined( FBLBM_ENABLE_SECURE_BOOT )
   tFblAddress       macStructAddress;
   tFblLength        macStructLength;
#endif

   /* Initialize variables */
   result = kFblOk;

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
   /* Calculate location of presence pattern.
    * Note that the end of the block descriptor already points to the presence pattern itself.
    */
#ifdef VSWT_USED
   /* Switch blocks don't use presence pattern, but NVRam. Thus, the length of switch blocks remains untouched. */
   if (0 == vSwt_IsFlashedBlockASwitchBlock(blockDescriptor->blockNr))
   {
#endif
      if (result == kFblOk) /* PRQA S 2991, 2995 */ /* MD_FblKbApiOem_2991_2995 */
      {
         /* PRQA S 4342,4521 1 */ /* MD_FblKbApiOem_4342_4521_ConfigurationEnumLengthCast */
         memSegment = FblNvPatternGetBaseAddr(blockDescriptor->blockNr, (tFblNvPatternId)(kFblNvPatternId_Last - 1u), &presPtnAddress, &presPtnLen);

         if (memSegment >= 0)
         {
            /* Reduce length for presence pattern and mask */
            blockDescriptor->blockLength = presPtnAddress - blockDescriptor->blockStartAddress;
         }
         else
         {
            result = kFblFailed;
         }
      }
#ifdef VSWT_USED
   }
#endif
#endif

#if defined( FBLBM_ENABLE_SECURE_BOOT )
   if (result == kFblOk)
   {
      /* Calculate location of MACs */
      if (ApplFblSbGetBaseAddrByBlockNr(blockDescriptor->blockNr, &macStructAddress, &macStructLength) == kFblOk)
      {
         /* Reduce length for MACs */
         blockDescriptor->blockLength -= macStructLength;
      }
      else
      {
         result = kFblFailed;
      }
   }
#endif

   return result;
}

/***********************************************************************************************************************
 *  ApplFblGetModuleHeaderAddress
 **********************************************************************************************************************/
/*! \brief       This function has to return the address of the module header.
 *  \pre         Logical blocks need a module header
 *  \param[in]   blockNr
 *  \return      Address of module header information structure
 **********************************************************************************************************************/
tFblAddress ApplFblGetModuleHeaderAddress( vuint8 blockNr )
{
   tFblAddress moduleHeaderAddr;
   tBlockDescriptor blockDescriptor;

   /* The module header (containing the software identification information   *
    * and the interface version for consistency check) may be placed          *
    * at e.g.                                                                 *
    * - the beginning of the logical block (offset = +0x00 ) or               *
    * - with an offset to the beginning of the block (offset = +0xXX)         *
    * - with an offset to the end of the block (offset = -0xXX)               *
    * To provide an application specific flexibility, this function can       *
    * return the address depending on the block type and -number.             */

   /* Determine the module header address: */
   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      if (blockNr == 0u)
      {
         /* This is just a demonstration, that e.g. a certain block  *
          * can be treated different (with a certain offset):        */
         moduleHeaderAddr = blockDescriptor.blockStartAddress; /* + 0x00u */
      }
#ifdef VSWT_USED
      else if (blockNr == FBL_LBT_VSWT_FIRMWARE_BLOCK_NUMBER)
      {
         moduleHeaderAddr = blockDescriptor.blockStartAddress + 0x2000; /* AppInfoHeader behind 8KB TIM structure */
      }
#if defined FBL_LBT_VSWT_FIREWALL_BLOCK_NUMBER
      else if (blockNr == FBL_LBT_VSWT_FIREWALL_BLOCK_NUMBER)
      {
         moduleHeaderAddr = blockDescriptor.blockStartAddress + blockDescriptor.blockLength - 0x100; /* AppInfoHeader in last 256Byte */
      }
#endif /* FBL_LBT_VSWT_FIREWALL_BLOCK_NUMBER */
#endif /* VSWT_USED */
      else
      {
         /* For all other blocks: */
         moduleHeaderAddr = blockDescriptor.blockStartAddress;
      }
   }
   else
   {
      /* PRQA S 2741,4558 1 */ /* MD_FblKbApiOem_2741_4558 */
      assertFbl(0u, kFblSysAssertParameterOutOfRange);
      moduleHeaderAddr = 0u;
   }

   return moduleHeaderAddr;
}

/***********************************************************************************************************************
 *  ReadApplInfoHeader
 **********************************************************************************************************************/
/*! \brief       This function returns parts of the applInfoHeader
 *  \details     The ApplInfoHeader of Switchs blocks is not local - RPC communication is involved
 *  \pre         Logical blocks need a module header
 *  \pre         For non local blocks a working RPC mechanism to remote side must be established
 *  \param[in]   blockNr         Number of the logical block
 *  \param[in]   offset          Data offset in ApplInfoHeader
 *  \param[out]  targetBuf       Pointer to buffer where result is copied to
 *  \param[in]   size            Size of data to be copied (caller must ensure that it fits into targetBuf!)
 *  \return      Address of module header information structure
 **********************************************************************************************************************/
vuint8 ReadApplInfoHeader(vuint8 blockNr, vuint8 offset, vuint8* targetBuf, vuint8 size)
{
   vuint8 returnValue = kFblFailed;

#ifdef VSWT_USED
   if (vSwt_IsFlashedBlockASwitchBlock(blockNr) == 1)
   {
      if (vSwt_IsFlashedBlockFlashed(blockNr) == 1)
      {
         /* If a block has been flashed in this cycle, the ApplInfoHeader from the 'new' data must be returned */
         /* The data is still in the temporary partition */
         /* The FblReadProm will use the vMemAccM -> vMemAccM_vRpcProxy -> vRpcProxy way */
         (void)FblReadProm(ApplFblGetModuleHeaderAddress(blockNr) + offset, targetBuf, size);

         returnValue = kFblOk;
      }
      else
      {
         vuint8* applInfoHeaderPointer;
         tFblLbtBlockIndex blockIndex;

         if (FblLbtGetBlockIndexByNr(blockNr, &blockIndex) == kFblOk)
         {
            /* not flashed. Request the Header from the Switch - RPC communication */
            if (vSwt_ReadApplInfoHeader(applInfoHdrLength, blockIndex, &applInfoHeaderPointer) == E_OK)
            {
               vuint8 i;

               /* Bytewise copy of requested parts */
               for (i = 0; i < size ; ++i)
               {
                  targetBuf[i] = applInfoHeaderPointer[offset+i];
               }

               returnValue = kFblOk;
            }
         }
      }
   }
   else
   {
#endif /* VSWT_USED */

      /* Read the requests parts from the local ApplInfoHeader and return them */
      (void)FblReadProm(ApplFblGetModuleHeaderAddress(blockNr) + offset, targetBuf, size);
      returnValue  = kFblOk;

#ifdef VSWT_USED
   }
#endif /* VSWT_USED */

   return returnValue;
}

/***********************************************************************************************************************
 *  ApplFblCheckHwSwCompatibility
 **********************************************************************************************************************/
/*! \brief       Check if current logical block is compatible with hardware
 *  \pre         Logical block has to be valid
 *  \param[in]   blockIdx Index of logical block
 *  \return      Status of hardware-software compatibility check
 **********************************************************************************************************************/
vuint8 ApplFblCheckHwSwCompatibility(vuint8 blockIdx)
{
   vuint8 compatibilityListLength;
   FBL_ADDR_TYPE pCompatibilityField;
   vuint8 versionBuffer[2];
   vuint8 listIndex;
   vuint8 returnValue;

   /* Preset values */
   listIndex = 0u;
   returnValue = kDiagDependencyCheckOk;
   // jivan
#if 0
   /* Get address of compatibility list */
   pCompatibilityField = (ApplFblGetModuleHeaderAddress(blockIdx) + kApplInfoOffsetHwCompatibilityCounter );

   /* Read length of compatibility list */
   (void)FblReadProm(pCompatibilityField, &compatibilityListLength, 1u);
   pCompatibilityField += kApplInfoSizeHwCompatibilityCounter;

   /* Compare compatibility list to hardware compatibility version */
   while ((listIndex < compatibilityListLength) && (returnValue == kDiagDependencyCheckFailedSwHw))
   {
      (void)FblReadProm(pCompatibilityField, versionBuffer, 2u);
      if ((versionBuffer[0] == HardwareCompatibilityVersion[0]) &&
          (versionBuffer[1] == HardwareCompatibilityVersion[1]))
      {
         returnValue = kDiagDependencyCheckOk;
      }
      pCompatibilityField += 2u;
      listIndex++;
   }
#endif

   return returnValue;
}

/***********************************************************************************************************************
 *  ApplFblCheckSwSwCompatibility
 **********************************************************************************************************************/
/*! \brief       Check if logical blocks are compatible
 *  \return      Status of software-software compatibility check
 **********************************************************************************************************************/
vuint8 ApplFblCheckSwSwCompatibility( void )
{
#if (FBL_MTAB_NO_OF_BLOCKS < FBL_MIN_BLOCKS_FOR_DEPENDENCY)
   /* Only one block, no inconsistency possible */
   return kDiagDependencyCheckOk;
#else
   vuint8  actualVersion[2u];
   vuint8  referenceVersion[2u];
   vuint8  validityFlags[kEepSizeValidityFlags];
#ifdef VSWT_USED
   vuint8  validityFlagsTemp[kEepSizeValidityFlags];
#endif /* VSWT_USED */
   vuint8  result;
   boolean referenceBlockFound;
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
   vuint8  idx;
   tBlockDescriptor iterBlock;
   tFblLbtBlockFilter blockFilter;
# endif /* FBL_ENABLE_PRESENCE_PATTERN */

   result = kDiagDependencyCheckOk;
   /* Read validity flags */
# if defined(FBL_ENABLE_PRESENCE_PATTERN)
   /* Initialize all validity flags to invalid */
   for (idx = 0u; idx < kEepSizeValidityFlags; idx++)
   {
      validityFlags[idx] = 0xFF;
   }

   FblLbtBlockFilterInit(&blockFilter);
   iterBlock = FblLbtBlockFirst(&blockFilter);
   while (FblLbtBlockDone() == FALSE)
   {
      if (iterBlock.blockType != kBlockTypeBoot)
      {
#ifdef VSWT_USED
         /* Switch block meta data is saved in NVRam */ 
         if (1u == vSwt_IsFlashedBlockASwitchBlock(iterBlock.blockNr))
         {
            /* Read ValidityFlags from NVRam, don't override actual validityFlags */
            if(ApplFblNvReadValidityFlags_vSwt(validityFlagsTemp) == kFblOk)
            {
               /* If block presence is set in NVRam, update local validityFlags */
               if ((validityFlagsTemp[iterBlock.blockNr >> 3u] & (vuint8)(1u << (iterBlock.blockNr & 7u))) == 0u)
               {
                  validityFlags[(iterBlock.blockNr >> 3u)] &= FblInvert8Bit(1u << (iterBlock.blockNr & 7u));
               }
            }
            else
            {
               /* Report internal error */
               result = kFblFailed;
            }
         }
         else if (ApplFblChkModulePresence(&iterBlock) == kFblOk)
#else 
         if (ApplFblChkModulePresence(&iterBlock) == kFblOk)
#endif /* VSWT_USED */
         {
            /* If present, clear the validity flag (inverse logic!!) */
            validityFlags[(iterBlock.blockNr >> 3u)] &= FblInvert8Bit(1u << (iterBlock.blockNr & 7u));
         }
      }

      /* Prepare next cycle */
      iterBlock = FblLbtBlockNext();
   }

# else
   if (ApplFblNvReadValidityFlags(validityFlags) != kFblOk)
   {
      /* Report internal error */
      result = kFblFailed;
   }
   if (result == kDiagDependencyCheckOk)
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
   {
      /* Compare the 'reference' version against all other valid logical blocks
       * Old implementation chose the first non boot block as 'reference'
       * Problem: The order of entries in the LBT changes due to generation
       *   It happened that the reference block is a switch block
       * To avoid that, a two pass check is implemented
       *  1 - find reference block first - ensure that its local
       *  2 - check compatibility
      */

      /* Step 1: find (local) reference block */
      FblLbtBlockFilterInit(&blockFilter);
      iterBlock = FblLbtBlockFirst(&blockFilter);
      referenceBlockFound = FALSE;

      while ((FblLbtBlockDone() == FALSE) && (result == kDiagDependencyCheckOk))
      {
         /* Boot blocks are not considered for compatibility check */
         if (iterBlock.blockType != kBlockTypeBoot)
         {
            if (referenceBlockFound != TRUE)
            {
#ifdef VSWT_USED
               if (vSwt_IsFlashedBlockASwitchBlock(iterBlock.blockNr) == 0)
               {
#endif
               /* First local non-Boot block is used as reference */
               /* Attention: Ensure that Switch blocks are not found first! (Order in LBT) */
               (void)FblReadProm(ApplFblGetModuleHeaderAddress(iterBlock.blockNr) + kApplInfoOffsetSwCompatibility,
                  (vuint8 *)&referenceVersion, kApplInfoSizeSwCompatibility);
               referenceBlockFound = TRUE;

#ifdef VSWT_USED
               }
#endif
            }
         }

         iterBlock = FblLbtBlockNext();
      }

      /* For the next step the reference block is mandatory */
      if (referenceBlockFound != TRUE)
      {
         result = kDiagDependencyCheckFailedSwSw;
      }

      /* Step 2: compare valid logical blocks against reference block */
      FblLbtBlockFilterInit(&blockFilter);
      iterBlock = FblLbtBlockFirst(&blockFilter);

      while ((FblLbtBlockDone() == FALSE) && (result == kDiagDependencyCheckOk))
      {
         /* Boot blocks are not considered for compatibility check */
         if (iterBlock.blockType != kBlockTypeBoot)
         {
            /* Check is performed for valid logical blocks only. If an optional block  *
            * is not valid, the compatibility status will be ignored.                 */
            if ((validityFlags[iterBlock.blockNr >> 3u] & (vuint8)(1u << (iterBlock.blockNr & 7u))) == 0u)
            {
               /* Check if module version matches */
               /* (void)FblReadProm(ApplFblGetModuleHeaderAddress(iterBlock.blockNr) + kApplInfoOffsetSwCompatibility, (vuint8 *)&actualVersion, kApplInfoSizeSwCompatibility); */

               if (ReadApplInfoHeader(iterBlock.blockNr, kApplInfoOffsetSwCompatibility, &(actualVersion[0]), kApplInfoSizeSwCompatibility) == kFblOk)
               {
                  if ((referenceVersion[0u] != actualVersion[0u]) ||
                     (referenceVersion[1u] != actualVersion[1u]))
                  {
                     /* Inconsistency found */
                     result = kDiagDependencyCheckFailedSwSw;
                  }
               }
               else
               {
                  result = kDiagDependencyCheckFailedSwSw;
               }
            }
         }

         /* Prepare next cycle */
         iterBlock = FblLbtBlockNext();
      }
   }

   /* All blocks successfully checked */
   return result;
#endif /* (FBL_MTAB_NO_OF_BLOCKS < FBL_MIN_BLOCKS_FOR_DEPENDENCY) */
}  /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  ApplFblDowngradeProtectionInit
 **********************************************************************************************************************/
/*! \brief       Initialize downgrade protection
 *  \return      Status of downgrade-protection check - kFblOk if initialization succeeded
 **********************************************************************************************************************/
tFblResult ApplFblDowngradeProtectionInit(void)
{
#if 0    
   tFblLbtBlockFilter blockFilter;
   tBlockDescriptor iterBlock;
   vuint32 nvModuleId;
   vuint32 minimumVersion;
   vuint8 minSwVer[kEepSizeMinimumSoftwareVersion];
   tFblResult result;

   /* Initialize Minimum Software Version for downgrade protection */
   /* Please Note: This code may be replaced by any other strategy
   * to initialize the non-volatilve memory default values        */
   FblLbtBlockFilterInit(&blockFilter);
   iterBlock = FblLbtBlockFirst(&blockFilter);
   result = kFblOk;
   while ((FblLbtBlockDone() == FALSE) && (result == kFblOk))
   {
      if (iterBlock.blockType != kBlockTypeBoot)
      {
         nvModuleId = ApplFblGetNvModuleId(iterBlock.blockNr);
         result = ApplFblNvReadMinimumSoftwareVersion((WRAPNV_PositionType)nvModuleId, minSwVer);

         minimumVersion = FblMemGetInteger(kEepSizeMinimumSoftwareVersion, minSwVer);

         if (result == kFblOk)
         {
            if (minimumVersion == 0x00FFFFFFuL)
            {
               FblMemSetInteger(kEepSizeMinimumSoftwareVersion, 0x00000000uL, minSwVer);

               result = ApplFblNvWriteMinimumSoftwareVersion((WRAPNV_PositionType)nvModuleId, minSwVer);
            }
         }
      }
      /* Prepare next cycle */
      iterBlock = FblLbtBlockNext();
   }

   return result;
#endif
    return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblDowngradeProtectionCheck
 **********************************************************************************************************************/
/*! \brief       Check for unsupported software downgrade
 *  \return      Status of downgrade-protection check - kFblOk if versions are accepted
 **********************************************************************************************************************/
tFblResult ApplFblDowngradeProtectionCheck(void)
{
#if 0
   tFblLbtBlockFilter blockFilter;
   tBlockDescriptor iterBlock;
   vuint32 nvModuleId;
   tFblResult result;
   vuint8 minSwVer[kEepSizeMinimumSoftwareVersion];
   vuint32 minimumVersion;
   vuint8 dpVersion[kApplInfoSizeSwVersion];
   vuint32 currentVersion;

   result = kFblOk;
   FblLbtBlockFilterInit(&blockFilter);
   iterBlock = FblLbtBlockFirst(&blockFilter);
   while ((FblLbtBlockDone() == FALSE) && (result == kFblOk))
   {
      if (iterBlock.blockType != kBlockTypeBoot)
      {
         nvModuleId = ApplFblGetNvModuleId(iterBlock.blockNr);
         /* Read minimum software version from NvM */
         result = ApplFblNvReadMinimumSoftwareVersion((WRAPNV_PositionType)nvModuleId, minSwVer);
         if (result == kFblOk)
         {
            /* Read downgrade protection version of logical block */
            /* PRQA S 2985 1 */  /* MD_FblKbApiFrameNv_2985 */
            (void)FblReadProm(ApplFblGetModuleHeaderAddress(iterBlock.blockNr) + kApplInfoOffsetSwVersion,
               dpVersion, kApplInfoSizeSwVersion);

            /* Check versions */
            minimumVersion = FblMemGetInteger(kEepSizeMinimumSoftwareVersion, minSwVer);
            currentVersion = FblMemGetInteger(kApplInfoSizeSwVersion, dpVersion);

            if (currentVersion < minimumVersion)
            {
               result = kFblFailed;
            }
         }
      } /* iterBlock.blockType != kBlockTypeBoot */
      /* Prepare next cycle */
      iterBlock = FblLbtBlockNext();
   }

   return result;
#else
   return kFblOk;
#endif
}

/***********************************************************************************************************************
 *  ApplFblCheckProgDependencies
 **********************************************************************************************************************/
/*! \brief       Check if programming dependencies are given
 *  \return      Status of programming dependencies (OEM specific)
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
vuint8 ApplFblCheckProgDependencies( void )
{
   vuint8 blockIdx;
   vuint32 nvModuleId;
   vuint8 status;
   vuint8 swSwStatus;
   tBlockDescriptor iterBlock;
   tFblLbtBlockFilter blockFilter;
   tFblLbtBlockCount blockCount;

   /* Buffer for fingerprint status of all blocks */
   vuint8 localFingerprintStatus[FBL_MTAB_NO_OF_BLOCKS];
   vuint8 validityFlags[kEepSizeValidityFlags];

   status = kFblOk;
   swSwStatus = kDiagDependencyCheckFailedSwSw;

   /* TODO_CUSTOMER: Check timing of NV-Memory access                            *
    * If necessary, a response pending frame has to be sent, depending. *
    * on the amount of time needed by the EEPROM driver or EEPROM       *
    * emulation.                                                        */
   /* DiagExRCRResponsePending(kForceSendResponsePending); */

   blockCount = FblLbtGetBlockCount();

   /* Read all fingerprint status values */
   for (blockIdx = 0; blockIdx < blockCount; blockIdx++)
   {
      nvModuleId = ApplFblGetNvModuleId(blockIdx);
      status |= ApplFblNvReadFpStatusInfo((WRAPNV_PositionType)nvModuleId, &localFingerprintStatus[blockIdx]);
   }

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
   for (blockIdx = 0u; blockIdx < sizeof(validityFlags); blockIdx++)
   {
      validityFlags[blockIdx] = 0xFFu;
   }
   FblLbtBlockFilterInit(&blockFilter);
   iterBlock = FblLbtBlockFirst(&blockFilter);
   while (FblLbtBlockDone() == FALSE)
   {
      if (ApplFblChkModulePresence(&iterBlock) == kFblOk)
      {
         /* If present, clear the validity flag (inverse logic!!) */
         validityFlags[(iterBlock.blockNr >> 3u)] &= FblInvert8Bit(1u << (iterBlock.blockNr & 7u));
      }

      /* Prepare next cycle */
      iterBlock = FblLbtBlockNext();
   }
#else
   /* Read validity flags */
   status |= ApplFblNvReadValidityFlags(validityFlags);
#endif

   /* Check if read succeeded */
   if (status == kFblOk)
   {
      /* Step1: Check if all (mandatory) logical blocks are valid */
      FblLbtBlockFilterInit(&blockFilter);
      FblLbtBlockFilterSetMandatoryType(&blockFilter, TRUE);
      iterBlock = FblLbtBlockFirst(&blockFilter);
      while ((FblLbtBlockDone() == FALSE) && (status == kFblOk))
      {
         /* A set bit means that the block is not present */
         if ((validityFlags[(iterBlock.blockNr >> 3u)] & (1u << (iterBlock.blockNr & 7u))) != 0u)
         {
            if( (iterBlock.blockType == 1) && (TRUE == g_isvHsmUpdBlock) )
            {
               /*Do nothing*/
            }
            else
            {
               /* At least one logical block is not valid */
               status = kDiagDependencyCheckFailedBlkNotValid;
            }
         }
         /* Prepare next cycle */
         iterBlock = FblLbtBlockNext();
      }
   }
   #ifdef VSWT_USED
   /* Step 1a: Validate all programmed switch blocks (marvell internal check)*/
   if (status == kFblOk)
   {
      FblLbtBlockFilterInit(&blockFilter);
      iterBlock = FblLbtBlockFirst(&blockFilter);
      while (FblLbtBlockDone() == FALSE)
      {
         /* only process switch blocks */
         if(1u == vSwt_IsFlashedBlockASwitchBlock(iterBlock.blockNr))
         {
            /* only process programmed blocks */
            if(1u == vSwt_IsFlashedBlockFlashed(iterBlock.blockNr))
            {
               /* use blockIndex instead of blockNr. The blockNr magically reorders during generation */
               status |= vSwt_ValidateLogicalBlock(iterBlock.blockIndex);
            }
         }
         /* Prepare next cycle */
         iterBlock = FblLbtBlockNext();
      }
   }
#endif /* VSWT_USED */

   /* Step 2: Check compatibility between valid logical blocks and bootloader */
   if (status == kFblOk)
   {
      vuint8 hwSwStatus;

      /* Check SwSw compatibility */
      swSwStatus = ApplFblCheckSwSwCompatibility();

      /* Check Hw/Sw-compatibility of all programmed logical blocks */
      FblLbtBlockFilterInit(&blockFilter);
      iterBlock = FblLbtBlockFirst(&blockFilter);
      while (FblLbtBlockDone() == FALSE)
      {
         /* Check if block is programmed */
         if (((validityFlags[iterBlock.blockNr >> 3u] & (vuint8)(1u << (iterBlock.blockNr & 7u))) == 0u) &&
            (iterBlock.blockType != kBlockTypeBoot))
         {
            hwSwStatus = ApplFblCheckHwSwCompatibility((vuint8)iterBlock.blockNr);

            /* Update fingerprint status */
            if (hwSwStatus == kDiagDependencyCheckOk)
            {
               /* Clear HwSw mismatch flag in fingerprint status */
               localFingerprintStatus[iterBlock.blockNr] &= FblInvert8Bit(kDiagFpStatSwHwMismatch);
            }
            else
            {
               /* Store mismatch status for final result */
               status |= hwSwStatus;
            }
         }

         /* Prepare next cycle */
         iterBlock = FblLbtBlockNext();
      }
   }

   /* Store fingerprint status */
   FblLbtBlockFilterInit(&blockFilter);
   iterBlock = FblLbtBlockFirst(&blockFilter);
   while (FblLbtBlockDone() == FALSE)
   {
      /* Fingerprint status of bootloader should be changed by updater only */
      if (iterBlock.blockType != kBlockTypeBoot)
      {
         /* Set status of Sw/Sw compatibility */
         if (swSwStatus == kDiagDependencyCheckOk)
         {
            localFingerprintStatus[iterBlock.blockNr] &= FblInvert8Bit(kDiagFpStatSwSwMismatch);
         }
         else
         {
            localFingerprintStatus[iterBlock.blockNr] |= kDiagFpStatSwSwMismatch;
         }

         /* Update reprogramming process state */
         if ((localFingerprintStatus[iterBlock.blockNr] & (kDiagFpStatSwSwMismatch | kDiagFpStatSwHwMismatch)) == 0x00u)
         {
            /* PRQA S 2985 1 */ /* MD_FblKbApiOem_2985 */
            SetReprogProcessState(localFingerprintStatus[iterBlock.blockNr], kDiagFpStatOk);
         }
         else
         {
            SetReprogProcessState(localFingerprintStatus[iterBlock.blockNr], kDiagFpStatCompatCheckFailed);
         }

         nvModuleId = ApplFblGetNvModuleId(iterBlock.blockNr);
         /* Write fingerprint status to NVM */
         status |= ApplFblNvWriteFpStatusInfo((WRAPNV_PositionType)nvModuleId, &localFingerprintStatus[iterBlock.blockNr]);
      }
      /* Prepare next cycle */
      iterBlock = FblLbtBlockNext();
   }

   /* Rollback Lock / downgrade protection */
   if (status == kFblOk)
   {
      if (ApplFblDowngradeProtectionCheck() != kFblOk)
      {
         status = kDiagDependencyCheckFailedDowngrade;
      }
   }

   /* Priority of return code */
   if (status == kFblOk)
   {
      status = swSwStatus;
   }

   return status;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/***********************************************************************************************************************
 *  ApplFblPreChkProgDependencies
 **********************************************************************************************************************/
/*! \brief       Pre-check programming dependencies with the given version information in the routine option record
 *  \return      Status of programming dependencies
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
vuint8 ApplFblPreChkProgDependencies( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
   tFblResult result;
   vuint8 status;
   vuint16 sourceIdx;         /* Index for pbDiagData */
   vuint8 idx;
   vuint8 hwVerIdx;           /* Index in hardware version list */
   vuint8 blockNr;
   vuint8 routineOptBlockCount;
   vuint8 validityFlags[kEepSizeValidityFlags];
#ifdef VSWT_USED
   vuint8  validityFlagsTemp[kEepSizeValidityFlags];
#endif /* VSWT_USED */
   vuint8 blockMask[kEepSizeValidityFlags];        /* Flags of logical blocks which are part of the request */
   vuint8 versionInfo[kApplInfoSizeSwCompatibility * FBL_MTAB_NO_OF_BLOCKS];
   tBlockDescriptor iterBlock;
   tFblLbtBlockFilter blockFilter;
   tFblLbtBlockCount blockCount;

   /* This function assumes that the version information in the routineOption record has got the
    * following format (for each logical block record):
    * Offset 0: 1 byte logical block number
    * Offset 1: 1 byte length of compatibility information
    * Offset 2: 2 bytes software compatibility version
    * Offset 4: 1 bytes length of hw compatibility information
    * Offset 5: 2*n bytes hardware compatibility version
    */

   result = kFblOk;

   /* Check request length */
   if (diagReqDataLen < (kFblPreChkRecordSize + kDiagLocFmtRoutineOption))
   {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
      result = kFblFailed;
   }
   else
   {
      /* Initialize variables */
      sourceIdx = kDiagLocFmtRoutineOption;
      routineOptBlockCount = 0u;
      blockCount = FblLbtGetBlockCount();

      DiagExRCRResponsePending(kNotForceSendResponsePending);

      while((sourceIdx < diagReqDataLen) && (result == kFblOk))
      {
         /* Count number of block version information sets in routine option record */
         routineOptBlockCount++;

         /* Check length information in current record */
         if (pbDiagData[kFblLengthOffset(sourceIdx)] != (kFblPreChkSwVerSize + 1u + pbDiagData[kFblHwLengthOffset(sourceIdx)]))
         {
            result = kFblFailed;
         }
         else
         {
            /* Start index of next record */
            sourceIdx += (kFblPreChkRecordSize + (vuint16)(pbDiagData[kFblHwLengthOffset(sourceIdx)]));
            if (sourceIdx > diagReqDataLen )
            {
               result = kFblFailed;
            }
         }
      }

      if (result == kFblFailed)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
      }
      else
      {
         if (routineOptBlockCount > blockCount)
         {
            /* More blocks than configured */
            DiagNRCRequestOutOfRange();
            result = kFblFailed;
         }
      }
   }

   if (result == kFblOk) /* PRQA S 2991, 2995 */ /* MD_FblKbApiOem_2991_2995 */
   {
      /* Initialize flags for requested logical blocks */
      for (idx = 0u; idx < kEepSizeValidityFlags; idx++)
      {
         blockMask[idx] = 0xFFu;
      }

      /* Read block validity flags */
#if defined( FBL_ENABLE_PRESENCE_PATTERN )
      for (idx = 0u; idx < sizeof(validityFlags); idx++)
      {
         validityFlags[idx] = 0xFFu;
      }
      FblLbtBlockFilterInit(&blockFilter);
      iterBlock = FblLbtBlockFirst(&blockFilter);
      while (FblLbtBlockDone() == FALSE)
      {
#ifdef VSWT_USED
         /* Switch block meta data is saved in NVRam */ 
         if (1u == vSwt_IsFlashedBlockASwitchBlock(iterBlock.blockNr))
         {
            /* Read ValidityFlags from NVRam, don't override actual validityFlags */
            result = ApplFblNvReadValidityFlags_vSwt(validityFlagsTemp);
            if (result == kFblOk)
            {
               /* If block presence is set in NVRam, update local validityFlags */
               if ((validityFlagsTemp[iterBlock.blockNr >> 3u] & (vuint8)(1u << (iterBlock.blockNr & 7u))) == 0u)
               {
                  validityFlags[(iterBlock.blockNr >> 3u)] &= FblInvert8Bit(1u << (iterBlock.blockNr & 7u));
               }
            }
         }
         else if (ApplFblChkModulePresence(&iterBlock) == kFblOk)
#else 
         if (ApplFblChkModulePresence(&iterBlock) == kFblOk)
#endif /* VSWT_USED */
         {
            /* If present, clear the validity flag (inverse logic!!) */
            validityFlags[(iterBlock.blockNr >> 3u)] &= FblInvert8Bit(1u << (iterBlock.blockNr & 7u));
         }

         /* Prepare next cycle */
         iterBlock = FblLbtBlockNext();
      }
#else
      result = ApplFblNvReadValidityFlags(validityFlags);
#endif

      if (result == kFblOk) /* PRQA S 2991, 2995 */ /* MD_FblKbApiOem_2991_2995 */
      {
         /* Copy all received software versions into local buffer */
         idx = 0u;
         sourceIdx = kDiagLocFmtRoutineOption;
         while((idx < routineOptBlockCount) && (result == kFblOk))
         {
            /* Map block index of request data to blockNr, check if block number is valid */
            if (FblLbtGetBlockNrByIndex(pbDiagData[kFblBlockNrOffset(sourceIdx)], &blockNr) == kFblOk)
            {
               /* Copy version info */
               versionInfo[(2u * blockNr)] = pbDiagData[kFblSwVerOffset(sourceIdx)];
               versionInfo[(2u * blockNr) + 1u] = pbDiagData[kFblSwVerOffset(sourceIdx) + 1u];

               /* Set marker for current logical block */
               blockMask[blockNr >> 3u] &= FblInvert8Bit((vuint8)(1u << (blockNr & 7u)));
            }
            else
            {
               /* Requested block index not found */
               DiagNRCRequestOutOfRange();
               result = kFblFailed;
            }
            idx++;
            sourceIdx += kFblPreChkRecordSize + (vuint16)(pbDiagData[kFblHwLengthOffset(sourceIdx)]);
         }
      }

      if (result == kFblOk)
      {
         /* Check hardware versions for all received logical block versions */
         idx = 0u;
         status = kDiagDependencyCheckOk;

         sourceIdx = kDiagLocFmtRoutineOption;
         /* Loop over requested logical blocks as long as no incompatibility has been detected */
         while((idx < routineOptBlockCount) && (status == kDiagDependencyCheckOk))
         {
            status = kDiagDependencyCheckFailedSwHw;
            hwVerIdx = 0u;

            /* pbDiagData at index kFblHwLengthOffset contains the number of hw compatibility version bytes */
            while ( (hwVerIdx < pbDiagData[kFblHwLengthOffset(sourceIdx)]) && (status == kDiagDependencyCheckFailedSwHw))
            {
               /* Check if one of the requested harware version is compatible with current hardware */
               if (  (HardwareCompatibilityVersion[0] == pbDiagData[kFblHwVerOffset(sourceIdx) + hwVerIdx]) &&
                     (HardwareCompatibilityVersion[1] == pbDiagData[kFblHwVerOffset(sourceIdx) + hwVerIdx + 1u]))
               {
                  status = kDiagDependencyCheckOk;
               }

               hwVerIdx += kFblPreChkHwVerSize;
            }
            idx++;
            sourceIdx += kFblPreChkRecordSize + (vuint16)(pbDiagData[kFblHwLengthOffset(sourceIdx)]);
         }
      }

      if ((result == kFblOk) && (status == kDiagDependencyCheckOk))
      {
         /* Check if mandatory blocks are present or version info is available in routine option */
         for (idx = 0u; idx < kEepSizeValidityFlags; idx++)
         {
            if (((validityFlags[idx] & blockMask[idx]) & FblLogicalBlockTable.assignFlags[idx]) != 0u)
            {
               /*
               * At least one logical block is not valid and no version information is present in request.
               * We could send kDiagDependencyCheckFailedBlockNotValid but this return code is not
               * specified for dependency check verification result.
               */
               status = kDiagDependencyCheckFailedSwSw;
            }
         }
      }

      if ((result == kFblOk) && (status == kDiagDependencyCheckOk))
      {
         vuint8 startBlockNr;
         vuint16 refVerIdx;

         /* Check sw-sw compatibility */
         startBlockNr = 0xFFu;
         FblLbtBlockFilterInit(&blockFilter);
         iterBlock = FblLbtBlockFirst(&blockFilter);
         while ((FblLbtBlockDone() == FALSE) && (status == kDiagDependencyCheckOk))
         {
            /* Versions are not compared for boot block and for optional blocks which are not programmed */
            if ((iterBlock.blockType != kBlockTypeBoot) &&
               (((blockMask[iterBlock.blockNr >> 3u] & validityFlags[iterBlock.blockNr >> 3u]) & (1u << (iterBlock.blockNr & 7u))) == 0u))
            {
               if (startBlockNr == 0xFFu)
               {
                  /* Number of first logical block to be used as reference version */
                  startBlockNr = iterBlock.blockNr;
               }

               /* Load all other versions which are not part of the routineOption from PROM */
               if ((blockMask[iterBlock.blockNr >> 3u] & (vuint8)(1u << (iterBlock.blockNr & 7u))) != 0u)
               {
                  (void)FblReadProm(ApplFblGetModuleHeaderAddress(iterBlock.blockNr) + kApplInfoOffsetSwCompatibility,
                     (vuint8 *)&versionInfo[kApplInfoSizeSwCompatibility * iterBlock.blockNr], kApplInfoSizeSwCompatibility);

                  refVerIdx = (vuint16)startBlockNr * 2u;
                  /* Compare versions with version of first logical block */
                  if ((versionInfo[refVerIdx]       != versionInfo[ iterBlock.blockNr * 2u]) ||
                     (versionInfo[refVerIdx + 1u] != versionInfo[(iterBlock.blockNr * 2u) + 1u]))
                  {
                     status = kDiagDependencyCheckFailedSwSw;
                  }
               }
            }

            /* Prepare next cycle */
            iterBlock = FblLbtBlockNext();
         }
      }

      if (result == kFblOk)
      {
         /* Set routine info to successfully completed */
         pbDiagData[kDiagLocFmtRoutineInfo] = kDiagRoutineInfoSuccessful;

         pbDiagData[kDiagLocFmtRoutineStatus] = status;

         DiagProcessingDone(5u);
      }
   }
   return result;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

# if defined( FBL_CW_ENABLE_MULTIPLE_CONNECTIONS )
/***********************************************************************************************************************
*  ApplFblWriteDcmDslRxTesterSourceAddr
**********************************************************************************************************************/
/*! \brief       Function to write DcmDsl Rx Tester Source Address to non-volatile memory
 *  \param[in]   buffer Pointer to byte array containing the tester source address
 *  \return      Result of write operation
**********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblWriteDcmDslRxTesterSourceAddr(vuint8* buffer)
{
   uint16 testerAddress;

   /* restore uint16 representation and write to temporary variable */
   testerAddress = FblMemGetInteger(sizeof(FblCw_RxTesterSourceAddressOfDcmDslConnectionInfo16BitType), buffer);
   
   /* write in shared RAM area */
   Fbl_ProgConditions.TesterSourceAddr = testerAddress;
   
   return kFblOk;
   /* return ApplFblNvWriteDcmDslRxTesterSourceAddr(buffer); */
}

/***********************************************************************************************************************
*  ApplFblReadDcmDslRxTesterSourceAddr
**********************************************************************************************************************/
/*! \brief       Function to read DcmDsl Rx Tester Source Address from non-volatile memory
 *  \param[out]  buffer Pointer to byte array containing the tester source address
 *  \return      Result of read operation
**********************************************************************************************************************/
tFblResult ApplFblReadDcmDslRxTesterSourceAddr(vuint8* buffer)
{
   uint16 testerAddress;
   
   /* read from shared RAM area */
   testerAddress = Fbl_ProgConditions.TesterSourceAddr;
   
   /* change representation to uint8 array and store in target buffer */
   FblMemSetInteger(sizeof(FblCw_RxTesterSourceAddressOfDcmDslConnectionInfo16BitType), testerAddress, buffer);
   
   return kFblOk;
   /* return ApplFblNvReadDcmDslRxTesterSourceAddr(buffer); */
}
# endif /* FBL_CW_ENABLE_MULTIPLE_CONNECTIONS */

/***********************************************************************************************************************
 *  ApplFblExtProgRequest
 **********************************************************************************************************************/
/*! \brief       Function is called on power-on reset to check if an external programming request exists.
 *  \details     If the flag is set, the flag is cleared and the function returns kProgRequest.
 *  \return      kProgRequest = external programming request, kNoProgRequest = programming request flag not set
 **********************************************************************************************************************/
tFblProgStatus ApplFblExtProgRequest( void )
{
   tFblProgStatus progStatus;
# if defined( FBL_ENABLE_FBL_START )
# else
   vuint8 progReqFlag;
# endif /* FBL_ENABLE_FBL_START */

   /* Initialize variables */
   progStatus = kNoProgRequest;

# if defined( FBL_ENABLE_FBL_START )
   /* Check a pattern in uninitialized RAM to see if this
    * is a reprogramming request from the application */
   if (FblBmChkFblStartMagicFlag())
   {
      /* currently, the ReprogrammingRequest flag from the application is not checked. It's only cleared */
      //if (TRUE == Fbl_ProgConditions.ReprogrammingRequest)
      {
         /* Clear immediately the request */
         FblBmClrMagicFlag();
         Fbl_ProgConditions.ReprogrammingRequest = FALSE;

         progStatus = kProgRequest;
      }
   }
# else /* ! FBL_ENABLE_FBL_START */
   vuint8 progReqFlag;

   /* Check the reprogramming request flag */
   if (ApplFblNvReadProgReqFlag(&progReqFlag) == kFblOk)
   {
      if (progReqFlag == kEepFblReprogram)
      {
         /* Reprogramming flag is set, clear flag */
         progReqFlag = 0u;
         (void)ApplFblNvWriteProgReqFlag(&progReqFlag); /* PRQA S 3425 */ /* MD_FblKbApiOem_3425 */

         progStatus = kProgRequest;
      }
#  if defined( FBL_ENABLE_OTA )
      /* Check explicit OTA request */
      else if (progReqFlag == kEepFblOtaReprogram)
      {
         /* Reprogramming flag is set, clear flag */
         progReqFlag = 0u;
         (void)ApplFblNvWriteProgReqFlag(&progReqFlag); /* PRQA S 3425 */ /* MD_FblKbApiOem_3425 */

         progStatus = kProgRequestOta;
      }
#  endif /* FBL_ENABLE_OTA */
      else /* != kEepFblReprogram */
      {
         progStatus = kNoProgRequest;
      }
   }
# endif /* ! FBL_ENABLE_FBL_START */
   else
   {
      progStatus = kNoProgRequest;
   }
# if defined( FBLBM_ENABLE_SECURE_BOOT )
#  if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY )
   if (FblBmChkInitKeysMagicFlag())
   {
      /* Do not clear magic flag, as it is later evaluated again */
      progStatus = kInitKeysRequest;
   }
#  endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY */
#  if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
   if (FblBmChkInitCmacMagicFlag())
   {
      /* Do not clear magic flag, as it is later evaluated again */
      progStatus = kInitMacsRequest;
   }
#  endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */
# endif /* FBLBM_ENABLE_SECURE_BOOT */
   return progStatus;
}

/***********************************************************************************************************************
 *  ApplFblIsValidBlock
 **********************************************************************************************************************/
/*! \brief       Check if a logical block is valid or not.
 *  \param[in]   blockNr The number of the logical block.
 *  \return      Returns kFblOk if the logical block is valid. Otherwise it returns kFblFailed.
 **********************************************************************************************************************/
tFblResult ApplFblIsValidBlock( vuint8 blockNr )
{
#if defined( FBL_ENABLE_PRESENCE_PATTERN )
   tBlockDescriptor checkBlock;
#ifdef VSWT_USED
   vuint8  validityFlagsTemp[kEepSizeValidityFlags];
#endif /* VSWT_USED */
#else
   vuint8 validityFlags[kEepSizeValidityFlags];
   vuint8 validityMask;
   vuint8 byteIdx;
#endif
   tFblResult result;

   /* Assume block is invalid */
   result = kFblFailed;

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
   /* Get logical block data structure */
   if (FblLbtGetBlockDescriptorByNr(blockNr, &checkBlock) == kFblOk)
   {
      /* Check presence pattern in logical block */
#ifdef VSWT_USED
      /* Switch block meta data is saved in NVRam */ 
      if (1u == vSwt_IsFlashedBlockASwitchBlock(blockNr))
      {
         /* Read ValidityFlags from NVRam, don't override actual validityFlags */
         if(ApplFblNvReadValidityFlags_vSwt(validityFlagsTemp) == kFblOk)
         {
            if ((validityFlagsTemp[(blockNr >> 0x03u)] & (vuint8)(0x01u << (blockNr & 0x07u))) == 0u)
            {
               /* Block is valid */
               result = kFblOk;
            }
         }
      }
      else if (ApplFblChkModulePresence(&checkBlock) == kFblOk)
#else 
      if (ApplFblChkModulePresence(&checkBlock) == kFblOk)
#endif /* VSWT_USED */
      {
         result = kFblOk;
      }
   }
#else
   /* Calculate index and mask for validity bit of logical block */
   byteIdx        = (blockNr >> 0x03u);
   validityMask   = (vuint8)(0x01u << (blockNr & 0x07u));

   /* Read validity information from non-volatile memory */
   if (ApplFblNvReadValidityFlags(validityFlags) == kFblOk)
   {
      if ((validityFlags[byteIdx] & validityMask) == 0u)
      {
         /* Block is valid */
         result = kFblOk;
      }
   }
#endif /* FBL_ENABLE_PRESENCE_PATTERN */

   return result;
}

/***********************************************************************************************************************
 *  ApplFblValidateBlock
 **********************************************************************************************************************/
/*! \brief       Function is called after a successful download (CRC check was successful) to validate the logical block
 *  \pre         Logical block must be successfully downloaded
 *  \param[in]   blockDescriptor Block descriptor structure
 *  \return      kFblOk: validation successfully performed, kFblFailed: validation failed
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
tFblResult ApplFblValidateBlock( tBlockDescriptor blockDescriptor )
{
   vuint8 buffer[kApplInfoSizeSwInfo];
   FBL_ADDR_TYPE applHdrAddr;
   tFblResult returnCode;
   tBlockDescriptor localBlockDescriptor;
   vuint8 fpStatus;
#if defined( FBL_ENABLE_OTA )
   vOtaM_ModuleIdType moduleToValidate;
   vOtaM_PartitionInfoType* part;
#endif
   vuint32 nvModuleId;

   g_isvHsmUpdBlock = FALSE;
   localBlockDescriptor = blockDescriptor;
   nvModuleId = ApplFblGetNvModuleId(localBlockDescriptor.blockNr);

   /* Read software and hardware part number, version and supplier information
      from flashware */
   /* applHdrAddr = ApplFblGetModuleHeaderAddress(localBlockDescriptor.blockNr); */
   /* (void)FblReadProm(applHdrAddr, buffer, kApplInfoSizeSwInfo); */
   if (ReadApplInfoHeader(localBlockDescriptor.blockNr, 0, &(buffer[0]), kApplInfoSizeSwInfo) == kFblOk)
   {
      /* Write software information into NVM */
      returnCode = ApplFblNvWriteSwVersion((WRAPNV_PositionType)nvModuleId, &buffer[kApplInfoOffsetSwVersion]);
      returnCode |= ApplFblNvWriteSwPartNumber((WRAPNV_PositionType)nvModuleId, &buffer[kApplInfoOffsetSwPartNumber]);
      returnCode |= ApplFblNvWriteSwSupplierInformation((WRAPNV_PositionType)nvModuleId,
         &buffer[kApplInfoOffsetSwSupplierInformation]);
   }
   else
   {
      returnCode = kFblFailed;
   }

   /* TODO - vikarat: Darf der fpStatus auf OK gesetzt werden obwohl das NVRAM schreiben nicht funktioniert hat? */

   /* memory status = programmed, appl valid, compatibility mismatch */
   fpStatus = kDiagFpStatApplValid | kDiagFpStatSwSwMismatch | kDiagFpStatSwHwMismatch;

   /* Reprogramming process state, memory check successful */
   SetReprogProcessState(fpStatus, kDiagFpStatMemCheckSucceeded);

   returnCode |= ApplFblNvWriteFpStatusInfo((WRAPNV_PositionType)nvModuleId, &fpStatus);

   if (returnCode == kFblOk)
   {
      /* Check for a verfication key update and store it in NvM */
      returnCode = ApplFblWriteVerificationKey((vuint8)localBlockDescriptor.blockNr);
   }

   if(kFblOk == ApplFblCheckForMagicPattern(localBlockDescriptor) )
   {
	   g_isvHsmUpdBlock = TRUE;
	   returnCode = ApplFblHsmReEncrypt(localBlockDescriptor);
	   if (returnCode == kFblOk)
	   { 
		   returnCode = ApplFblStartHsmUpdAndWait();
	   }
   }
   
   /* Set current block valid */
   if (returnCode == kFblOk)
   {
#if defined( FBL_ENABLE_OTA )
      /* Get working partition and validate block */
      if (vOtaMGetPartitionByAddrAreaId(MemDriver_GetAddressArea(), &part) == E_OK)
      {
         if (vOtaMGetModuleByLogicalBlockNumber(localBlockDescriptor.blockNr, &moduleToValidate) == E_OK)
         {
            returnCode = (vOtaM_SetModuleValid(part->Id, moduleToValidate) == E_OK)
               ? kFblOk : kFblFailed;
         }
      }
#else
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
      /* Save block descriptor of currently validated block.
       * The block descriptor will be used to validate the application. */
      currentValidatedBlock = blockDescriptor;

      returnCode = ApplFblSetModulePresence(&localBlockDescriptor);

      if(g_isvHsmUpdBlock == TRUE)
	  {

		  returnCode = ApplFblClrModulePresence(&localBlockDescriptor);
	  }

# else
      returnCode = ApplFblChgBlockValid(kEepValidateBlock, localBlockDescriptor);
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
#endif /* FBL_ENABLE_OTA */
   }

   return returnCode;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  ApplFblInvalidateBlock
 **********************************************************************************************************************/
/*! \brief       Whenever the bootloader needs to delete data, this function is called
 *               to invalidate the current logical block.
 *  \param[in]   blockDescriptor Block descriptor structure
 *  \return      kFblOk: invalidation successfully performed, kFblFailed: invalidation failed
 **********************************************************************************************************************/
tFblResult ApplFblInvalidateBlock( tBlockDescriptor blockDescriptor )
{
   tFblResult returnCode;
   tBlockDescriptor localBlockDescriptor;
   vuint8 fpStatus;
   vuint32 nvModuleId;
#if defined( FBL_ENABLE_OTA )
   vOtaM_PartitionInfoType* part;
   vOtaM_ModuleIdType moduleToInvalidate;
#else
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
# else /* ! FBL_ENABLE_PRESENCE_PATTERN */
   vuint8 applValid;
# endif /* ! FBL_ENABLE_PRESENCE_PATTERN */
#endif /* FBL_ENABLE_OTA */

   /* Initialize variables */
   fpStatus = 0u;
   localBlockDescriptor = blockDescriptor;
   nvModuleId = ApplFblGetNvModuleId(localBlockDescriptor.blockNr);

   /* Invalidate application */
#ifdef VSWT_USED
    /* If only Switch blocks get updated - dont invalidate the host application
     *   The new software for the switch will be downloaded (and checked) in the temporary partition
     *   Even if there is a problem - the switch will come up with the old software
     *     Check with your OEM requirements if this assumed behavior is correct */
   if (0 == vSwt_IsFlashedBlockASwitchBlock(nvModuleId))
   {
      returnCode = ApplFblInvalidateApp();
   }
   else
   {
      returnCode = kFblOk;
   }
#else
   returnCode = ApplFblInvalidateApp();
#endif

   /* Update fingerprint status information - clear applValid,    *
    * set SwSw and SwHw mismatch                                  */
   if (returnCode == kFblOk)
   {
      returnCode = ApplFblNvReadFpStatusInfo((WRAPNV_PositionType)nvModuleId, &fpStatus);
   }
   if (returnCode == kFblOk)
   {
      fpStatus &= FblInvert8Bit(kDiagFpStatApplValid);
      fpStatus |= (kDiagFpStatSwSwMismatch | kDiagFpStatSwHwMismatch);
      returnCode = ApplFblNvWriteFpStatusInfo((WRAPNV_PositionType)nvModuleId, &fpStatus);
   }
   /* Erase valid flag of current block */
   if (returnCode == kFblOk)
   {
#if defined( FBL_ENABLE_OTA )
      /* TODO_CUSTOMER: Erase OFR information here. Example is given for using the WrapNv to erase
       * OFR information from NV memory */

      /* OFR information erase example start
      vuint8 ofrData[kEepSizeOfrInfo];
      vuintx idx;

      for (idx = 0u; idx < kEepSizeOfrInfo; idx++)
      {
         ofrData[idx] = 0x00u;
      }
      returnCode = ApplFblNvWriteOfrInfo((WRAPNV_PositionType)nvModuleId, ofrData);
   }

   if (returnCode == kFblOk)
   {
    * OFR information erase example end */
      /* Get working partition and invalidate block */
      if (vOtaMGetPartitionByAddrAreaId(MemDriver_GetAddressArea(), &part) == E_OK)
      {
         if (vOtaMGetModuleByLogicalBlockNumber(localBlockDescriptor.blockNr, &moduleToInvalidate) == E_OK)
         {
            returnCode = (vOtaM_SetModuleInvalid(part->Id, moduleToInvalidate) == E_OK)
               ? kFblOk : kFblFailed;
         }
      }
#else
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
      /* Only invalidate block if it is not valid */
      returnCode = ApplFblClrModulePresence(&localBlockDescriptor);
# else
      returnCode = ApplFblChgBlockValid(kEepInvalidateBlock, localBlockDescriptor);
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
#endif /* FBL_ENABLE_OTA */
   }

   if (returnCode == kFblOk)
   {
      /* Write fingerprint (from RAM buffer) into meta data table */
      returnCode = ApplFblNvWriteFingerprint((WRAPNV_PositionType)nvModuleId, blockFingerprint);
   }

   return returnCode;
}

/***********************************************************************************************************************
 *  ApplFblIsValidApp
 **********************************************************************************************************************/
/*! \brief       Function is called on power-up to check if the application is successfully validated or not.
 *  \details     Returns kApplValid if application is valid (all mandatory blocks available) and application start is
 *               allowed. Otherwise it returns kApplInvalid.
 **********************************************************************************************************************/
/* PRQA S 2889 1 */ /* MD_FblKbApi_2889 */
tApplStatus ApplFblIsValidApp( void )
{
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
   tBlockDescriptor iterBlock;
   tFblLbtBlockFilter blockFilter;
# else
   vuint8 applValidity;
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
   tApplStatus applicationStatus;

   /* Initialize variables */
   applicationStatus = kApplInvalid;

# if defined( FBL_ENABLE_PRESENCE_PATTERN )
   /* Read validity from application validity pattern
    * Scan all logical blocks until one block with application valid flag is found */
   FblLbtBlockFilterInit(&blockFilter);
   iterBlock = FblLbtBlockFirst(&blockFilter);
   while ((FblLbtBlockDone() == FALSE) && (applicationStatus == kApplInvalid))
   {
#ifdef VSWT_USED
      if (0 == vSwt_IsFlashedBlockASwitchBlock(iterBlock.blockNr))
      {
#endif
         if (ApplFblChkApplPresence(&iterBlock) == kFblOk)
         {
            applicationStatus = kApplValid;
         }
#ifdef VSWT_USED
      }
#endif
      /* Prepare next cycle */
      iterBlock = FblLbtBlockNext();
   }
# else
   /* Read validity from NV-memory */
   if (ApplFblNvReadApplValidity(&applValidity) == kFblOk)
   {
      if (applValidity == kFblApplicationValid)
      {
         applicationStatus = kApplValid;
      }
   }
#  endif /* FBL_ENABLE_PRESENCE_PATTERN */
//jivan?
#if 0
# if ( FBL_PROJECT_STATE == FBL_INTEGRATION )
   if ((applicationStatus == kApplValid) && (FblCheckBootVectTableIsValid()))
   {
      /* Application is valid but contains an APPLVECT_FROM_BOOT.
       * Therefore it is not possible to jump to startup code of application.
       * Probably the Bootloader was reprogrammed with a debugger. */
      applicationStatus = kApplInvalid;
   }
# endif /* FBL_PROJECT_STATE */
#endif
   return applicationStatus;
}

/***********************************************************************************************************************
 *  ApplFblInvalidateApp
 **********************************************************************************************************************/
/*! \brief       Function is called before erasure of the application
 *  \return      kFblOk = invalidation successfully performed, kFblFailed = invalidation failed
 **********************************************************************************************************************/
tFblResult ApplFblInvalidateApp( void )
{
   tFblResult result;

#if defined( FBL_ENABLE_OTA )
#else
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
   tBlockDescriptor iterBlock;
   tFblLbtBlockFilter blockFilter;
# else
   vuint8 applValidity;
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
#endif /* FBL_ENABLE_OTA */

#if defined( FBL_ENABLE_OTA )
   if (vOtaM_SetActivePartitionInvalid() == E_OK)
   {
      result = kFblOk;
   }
   else
   {
      result = kFblFailed;
   }
#else
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
   result = kFblOk;
   /* Loop over all logical blocks to invalidate application flag */
   FblLbtBlockFilterInit(&blockFilter);
   iterBlock = FblLbtBlockFirst(&blockFilter);
   while ((FblLbtBlockDone() == FALSE) && (result == kFblOk))
   {
      if (iterBlock.blockType != kBlockTypeBoot)
      {
         result = ApplFblClrApplPresence(&iterBlock);
      }

      /* Prepare next cycle */
      iterBlock = FblLbtBlockNext();
   }
# else
   applValidity = kFblApplicationInvalid;
   result = (tFblResult)ApplFblNvWriteApplValidity(&applValidity);
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
#endif /* FBL_ENABLE_OTA */

   return result;
}

/***********************************************************************************************************************
 *  ApplFblGetPromMaxProgAttempts
 **********************************************************************************************************************/
/*! \brief       Get the maximum programming attempt value
 *  \param[in]   blockNr Number of the block
 *  \return      Maximum programming attempt value
 **********************************************************************************************************************/
tFblLbtMaxProgAttempts ApplFblGetPromMaxProgAttempts(tFblLbtBlockNr blockNr)
{
   tFblLbtMaxProgAttempts maxProgAttempt;

   if (FblLbtGetBlockMaxProgAttemptsByNr(blockNr, &maxProgAttempt) != kFblOk)
   {
      /* Error reading the maximum programming attempt value, return default value */
      maxProgAttempt = 0u;
   }

   return maxProgAttempt;
}

/***********************************************************************************************************************
 *  ApplFblIncProgAttempts
 **********************************************************************************************************************/
/*! \brief       Increment programming attempt counter
 *  \param[in]   blockDescriptor Block descriptor
 *  \return      kFblOk / kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblIncProgAttempts( tBlockDescriptor blockDescriptor )
{
   tFblResult status;
   vuint8 nvBuffer[sizeof(vuint16)];
   vuint16 progAttempts;
   vuint32 nvModuleId;

   nvModuleId = ApplFblGetNvModuleId(blockDescriptor.blockNr);
   status = (tFblResult)ApplFblNvReadProgAttempts((IO_PositionType)nvModuleId, nvBuffer);
   progAttempts = (vuint16)FblMemGetInteger(sizeof(nvBuffer), nvBuffer);

   if (status == kFblOk)
   {
      /* Value is stored inverted because of erase value */
      progAttempts = FblInvert16Bit(progAttempts);
      progAttempts++;
      progAttempts = FblInvert16Bit(progAttempts);

      FblMemSetInteger(sizeof(nvBuffer), progAttempts, nvBuffer);
      status = (tFblResult)ApplFblNvWriteProgAttempts((IO_PositionType)nvModuleId, nvBuffer);
   }

   return status;
}

/***********************************************************************************************************************
 *  ApplFblGetProgAttempts
 **********************************************************************************************************************/
/*! \brief       Get programming attempt counter
 *  \param[in]   blockDescriptor Block descriptor
 *  \param[out]  progAttempts The returned programming attempts
 *  \return      kFblOk / kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblGetProgAttempts( tBlockDescriptor blockDescriptor, V_MEMRAM1 vuint16 V_MEMRAM2 V_MEMRAM3 * progAttempts )
{
   tFblResult status;
   vuint8 nvBuffer[sizeof(vuint16)];
   vuint16 tempCount;
   vuint32 nvModuleId;

   nvModuleId = ApplFblGetNvModuleId(blockDescriptor.blockNr);
   status = (tFblResult)ApplFblNvReadProgAttempts((IO_PositionType)nvModuleId, nvBuffer);
   tempCount = (vuint16)FblMemGetInteger(sizeof(nvBuffer), nvBuffer);
   *progAttempts = FblInvert16Bit(tempCount);

   return status;
}

#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
/***********************************************************************************************************************
 *  ApplFblRWSecurityAccessDelayFlag
 **********************************************************************************************************************/
/*! \brief       Read/write security access delay flag.
 *  \details     In read mode, the function will return the current value of the security access delay flag. In write
 *               mode it will return the return code of the EEPROM driver.
 *  \param[in]   mode The mode to be used (kEepReadData/kEepWriteData)
 *  \param[in]   value The value to be written
 *  \return      Status of access delay flag/return code of EEPROM driver
 **********************************************************************************************************************/
vuint8 ApplFblRWSecurityAccessDelayFlag( vuint8 mode, vuint8 value )
{
   vuint8 buffer;
   vuint8 result;

   if (mode == kEepWriteData)
   {
      buffer = value;
      result = (vuint8)ApplFblNvWriteSecAccessDelayFlag(&buffer);
   }
   else
   {
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
      (void)value;
#endif
      /* Read security access delay flag */
      if (ApplFblNvReadSecAccessDelayFlag(&buffer) != kFblOk)
      {
         /* Read failed! Return kEepSecAccessDelayActive */
         result = kEepSecAccessDelayActive;
      }
      else
      {
         result = buffer;
      }
   }

   return result;
}
#endif

/***********************************************************************************************************************
 *  ApplFblStoreFingerprint
 **********************************************************************************************************************/
/*! \brief       This function is called by the WriteDataByIdentifier service
 *               to store the received fingerprint in a temporary RAM buffer.
 *  \details     The fingerprint is written into a non-volatile memory when the corresponding logical block is invalidated.
 *  \param[in]   buffer Pointer to received fingerprint
 *  \return      kFblOk = fingerprint successfully stored
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblStoreFingerprint( vuint8 * buffer )
{
   /* Store fingerprint in temporary RAM buffer */
   /* PRQA S 0314 1 */ /* MD_FblKbApiOem_0314 */
   (void)MEMCPY(blockFingerprint, buffer, kEepSizeFingerprint);
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblErrorNotification
 **********************************************************************************************************************/
/*! \brief       Call-back function for diagnostic trouble code entries.
 *  \details     This function is called whenever a flash programming error occurred.
 *  \param[in]   errorType The error type
 *  \param[in]   errorCode The error code
 **********************************************************************************************************************/
void ApplFblErrorNotification( tFblErrorType errorType, tFblErrorCode errorCode )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)errorType;
   (void)errorCode;
#endif
}

/***********************************************************************************************************************
 *  ApplFblValidateApp
 **********************************************************************************************************************/
/*! \brief       Function is called after a successful download to validate a file.
 *  \pre         Complete file must be successfully downloaded
 *  \return      kFblOk = validation successfully performed, kFblFailed = validation failed
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
tFblResult ApplFblValidateApp( void )
{
   tFblResult result;
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
# else
   vuint8 applValid;
# endif /* FBL_ENABLE_PRESENCE_PATTERN */

   /* If checksum verification, HwSw and SwSW compatibility    *
    * dependencies check are successfully completed,           *
    * the NvM information is updated and                       *
    * the downloaded block is set to valid.                    */

#if defined( FBL_ENABLE_OTA )
   vOtaM_PartitionInfoType* part;

   result = kFblFailed;
   /* Get working partition */
   if (vOtaMGetPartitionByAddrAreaId(MemDriver_GetAddressArea(), &part) == E_OK)
   {
      /* Set partition revision first */
      if (vOtaM_SetNewPartitionRevision() == E_OK)
      {
         /* Validate partition */
         if (vOtaM_SetPartitionValid(part->Id) == E_OK)
         {
            result = kFblOk;
         }
      }
   }
#else
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
   /* Set presence pattern in last flashed logical block. */
   result = ApplFblSetApplPresence(&currentValidatedBlock);
# else
   applValid = kFblApplicationValid;
   result = ApplFblNvWriteApplValidity(&applValid);
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
#endif /* FBL_ENABLE_OTA */

   if (kFblOk == result)
   {
     /* inform application about successful application update */
     Fbl_ProgConditions.ApplUpdated = TRUE;
     fblBmMagicFlag[0] = kFblBmFblApplUpdatedMagicByte0;
     fblBmMagicFlag[1] = kFblBmFblApplUpdatedMagicByte1;
     fblBmMagicFlag[2] = kFblBmFblApplUpdatedMagicByte2;
     fblBmMagicFlag[3] = kFblBmFblApplUpdatedMagicByte3;
     fblBmMagicFlag[4] = kFblBmFblApplUpdatedMagicByte4;
     fblBmMagicFlag[5] = kFblBmFblApplUpdatedMagicByte5;
     fblBmMagicFlag[6] = kFblBmFblApplUpdatedMagicByte6;
     fblBmMagicFlag[7] = kFblBmFblApplUpdatedMagicByte7;
   }
 
   return result;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

# if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
/***********************************************************************************************************************
 *  ApplFblGetBlockErased
 **********************************************************************************************************************/
/*! \brief       Function is called by the diagnostic layer to check if the erase procedure can be omitted or not.
 *  \param[in]   blockDescriptor Block descriptor structure with information about the region
 *  \return      kFlashErased = Region is in erased state, kFlashNotErased = Region is not in erased state
 **********************************************************************************************************************/
tFlashStatus ApplFblGetBlockErased( tBlockDescriptor blockDescriptor )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)blockDescriptor; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

   /* This function is called when the Memory Status Information in  *
    * the fingerprint status is in state "erased".                   *
    *                                                                *
    * Please note, that this function may be also called for other   *
    * memory devices types than flash if multiple memory devices are *
    * configured (e.g. EEPROM).                                      */

   /* TODO_CUSTOMER: Make sure that the given logical block is really erased. *
    *       Otherwise, kFlashNotErased must be returned.             */

   return kFlashNotErased;
}
# endif /* FBL_ENABLE_FLASH_ERASED_DETECTION */

/***********************************************************************************************************************
 *  ApplFblWriteSegmentList
 **********************************************************************************************************************/
/*! \brief       Store the segment list structure.
 *  \details     The segment list structure must be stored to be able to calculate the checksum again when a
 *               RoutineControl-VerifyMemoryContent request is received.
 *  \param[in]   blockNr Correlates to the member of tBlockDescriptor to identify the logical block
 *  \param[in]   segmentList Structure was passed to the security module to calculate the signature/checksum
 *  \return      Returns kFblOk if the write operation was successful. Otherwise it returns kFblFailed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblWriteSegmentList( vuint8 blockNr, V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * segmentList )
{
   tFblResult result;
   vuint8 segmentAddrList[kEepSizeSegmentAddrList] = { 0u };
   vuint8 segmentLengthList[kEepSizeSegmentLengthList] = { 0u };
   vuint32 nvModuleId;
   vuint8 localNrOfSegments[kEepSizeSegmentCount];

   vuintx segIndx;
   nvModuleId = ApplFblGetNvModuleId(blockNr);

   /* Verify parameters */ /* PRQA S 2742, 2880 2 */ /* MD_FblKbApiOem_2742, MD_MSR_Unreachable */
   assertFblInternal(sizeof(segmentList->segmentInfo[0u].length) == kDiagFmtFixedLengthSize, kFblOemAssertParameterOutOfRange);
   assertFblInternal(segmentList->nrOfSegments <= SWM_DATA_MAX_NOAR, kFblOemAssertParameterOutOfRange);

   /* Serialize address- and length information */
   for (segIndx = 0u; segIndx < segmentList->nrOfSegments; segIndx++)
   {
      FblMemSetInteger(kDiagFmtFixedAddrSize, segmentList->segmentInfo[segIndx].targetAddress, &segmentAddrList[segIndx * kDiagFmtFixedAddrSize]);
      FblMemSetInteger(kDiagFmtFixedLengthSize, segmentList->segmentInfo[segIndx].length, &segmentLengthList[segIndx * kDiagFmtFixedLengthSize]);
   }

   /* Store data in non-volatile memory */
   FblMemSetInteger(kEepSizeSegmentCount, segmentList->nrOfSegments, localNrOfSegments);
   result = ApplFblNvWriteSegmentCount((WRAPNV_PositionType)nvModuleId, localNrOfSegments);
   result |= (tFblResult)ApplFblNvWriteSegmentAddrList((WRAPNV_PositionType)nvModuleId, segmentAddrList);
   result |= (tFblResult)ApplFblNvWriteSegmentLengthList((WRAPNV_PositionType)nvModuleId, segmentLengthList);

   return result;
}

/***********************************************************************************************************************
 *  ApplFblReadSegmentList
 **********************************************************************************************************************/
/*! \brief       Retrieve the whole segment list structure.
 *  \details     The whole segment list structure must be retrieved to calculate the checksum again after a
 *               RoutineControl-VerifyMemoryContent request was received.
 *  \param[in]   blockNr Correlates to the member of tBlockDescriptor to identify the logical block
 *  \param[out]  segmentList Structure will be passed to the security module to calculate the signature/checksum again
 *  \return      Returns kFblOk if the read operation was successful. Otherwise it returns kFblFailed.
 **********************************************************************************************************************/
tFblResult ApplFblReadSegmentList( vuint8 blockNr, V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * segmentList )
{
   tFblResult result;
   vuint8 segmentAddrList[kEepSizeSegmentAddrList];
   vuint8 segmentLengthList[kEepSizeSegmentLengthList];
   vuintx segIndx;
   V_MEMRAM1 FL_SegmentInfoType V_MEMRAM2 V_MEMRAM3 * segInfo;
   vuint32 nvModuleId;
   vuint8 localNrOfSegments[kEepSizeSegmentCount];

   nvModuleId = ApplFblGetNvModuleId(blockNr);

   result = ApplFblNvReadSegmentCount((WRAPNV_PositionType)nvModuleId, localNrOfSegments);
   if (result == kFblOk)
   {
      segmentList->nrOfSegments = FblMemGetInteger(kEepSizeSegmentCount, localNrOfSegments);
      assertFblInternal(segmentList->nrOfSegments <= SWM_DATA_MAX_NOAR, kFblOemAssertParameterOutOfRange);

      result = ApplFblNvReadSegmentAddrList((WRAPNV_PositionType)nvModuleId, segmentAddrList);
      result |= (tFblResult)ApplFblNvReadSegmentLengthList((WRAPNV_PositionType)nvModuleId, segmentLengthList);
   }

   if (result == kFblOk)
   {
      segInfo = segmentList->segmentInfo;

      for (segIndx = 0u; segIndx < segmentList->nrOfSegments; segIndx++)
      {
         /* De-serialze data from non-volatile memory */
         segInfo[segIndx].transferredAddress = FblMemGetInteger(kDiagFmtFixedAddrSize, &segmentAddrList[segIndx * kDiagFmtFixedAddrSize]);
         segInfo[segIndx].targetAddress = segInfo[segIndx].transferredAddress;
         segInfo[segIndx].length = FblMemGetInteger(kDiagFmtFixedLengthSize, &segmentLengthList[segIndx * kDiagFmtFixedLengthSize]);
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblReadFpStatusInfo
 **********************************************************************************************************************/
/*! \brief       Read fingerprint status byte
 *  \details     This function copies the fingerprint status from NvM to the destination buffer
 *  \param[in]   descriptor Identifies the corresponding logical block
 *  \param[out]  buffer Pointer to destination buffer
 *  \return      Result of operation
 *                  kFblOk when operation succeeded
 *                  kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblReadFpStatusInfo(tBlockDescriptor descriptor, vuint8 * buffer)
{
   return ApplFblNvReadFpStatusInfo((WRAPNV_PositionType)ApplFblGetNvModuleId(descriptor.blockNr), buffer);
}

/***********************************************************************************************************************
 *  ApplFblWriteFpStatusInfo
 **********************************************************************************************************************/
/*! \brief       Write fingerprint status byte
 *  \details     The new fingerprint status is stored in NvM
 *  \param[in]   descriptor Identifies the corresponding logical block
 *  \param[in]   buffer Pointer to source buffer
 *  \return      Result of operation
 *                  kFblOk when operation succeeded
 *                  kFblFailed otherwise
 **********************************************************************************************************************/
/* PRQA S 3673 1 */  /* MD_MSR_Rule8.13 */
tFblResult ApplFblWriteFpStatusInfo(tBlockDescriptor descriptor, vuint8 * buffer)
{
   return ApplFblNvWriteFpStatusInfo((WRAPNV_PositionType)ApplFblGetNvModuleId(descriptor.blockNr), buffer);
}

/***********************************************************************************************************************
 *  ApplFblCRCWrittenValueWrite
 **********************************************************************************************************************/
/*! \brief       Write CRC Written value into NV-memory
 *  \param[in]   descriptor Identifies the corresponding logical block
 *  \param[in]   buffer Pointer to source buffer
 *  \return      Result of operation
 *                  kFblOk when operation succeeded
 *                  kFblFailed otherwise
 **********************************************************************************************************************/
/* PRQA S 3673 1 */  /* MD_MSR_Rule8.13 */
tFblResult ApplFblCRCWrittenValueWrite(tBlockDescriptor descriptor, vuint8 * buffer)
{
   return ApplFblNvWriteCRCWritten((WRAPNV_PositionType)ApplFblGetNvModuleId(descriptor.blockNr), buffer);
}

#if defined( SEC_ENABLE_CRC_TOTAL )
/***********************************************************************************************************************
 *  ApplFblCRCTotalValueWrite
 **********************************************************************************************************************/
/*! \brief       Write CRC Total value into NV-memory
 *  \param[in]   descriptor Identifies the corresponding logical block
 *  \param[in]   buffer Pointer to source buffer
 *  \return      Result of operation
 *                  kFblOk when operation succeeded
 *                  kFblFailed otherwise
 **********************************************************************************************************************/
/* PRQA S 3673 1 */  /* MD_MSR_Rule8.13 */
tFblResult ApplFblCRCTotalValueWrite(tBlockDescriptor descriptor, vuint8 * buffer)
{
   return ApplFblNvWriteCRCTotal((WRAPNV_PositionType)ApplFblGetNvModuleId(descriptor.blockNr), buffer);
}
#endif /* SEC_ENABLE_CRC_TOTAL */

/***********************************************************************************************************************
 *  ApplFblReadVerificationKey
 **********************************************************************************************************************/
/*! \brief       Check if a new public key is available in Nvm to replace the originally configured one
 *  \details     This function copies the new key for signature verification from NvM to the destination buffer. The
 *               key from NvM is used for signature verification instead of the configured one.
 *  \param[out]  key Pointer to destination buffer
 *  \return      Number of copied bytes
 **********************************************************************************************************************/
SecM_LengthType ApplFblReadVerificationKey( V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * key )
{
   SecM_ByteType keyState;
   SecM_LengthType resultLen;

   resultLen = 0u;

   if (ApplFblNvReadVerificationKeyState(0, &keyState) == kFblOk)
   {
      if (keyState == kFblVerificationKeyPresent)
      {
         /* Please check if key in NvM needs to be secured by signaure */
         if (ApplFblNvReadVerificationKeyValue(0, key) == kFblOk)
         {
            resultLen = kEepSizeVerificationKeyValue;
         }
      }
   }

   return resultLen;
}

/***********************************************************************************************************************
 *  ApplFblWriteVerificationKey
 **********************************************************************************************************************/
/*! \brief       Check if a new public key is available in the download to replace the originally configured one
 *  \details     The downloaded block may contain a new verfication key. If a new key is available, it is stored in NvM
 *  \param[in]   blockNr Number of logical block
 *  \return      Result of operation
 *                  kFblOk when operation succeeded
 *                  kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblWriteVerificationKey( vuint8 blockNr )
{
   tFblResult result;
   /*tFblAddress applHdrAddr;*/
   vuint8 keyBuffer[kApplInfoSizeVerificationKeyState + kApplInfoSizeVerificationKey];

   result = kFblOk;
   /*applHdrAddr = ApplFblGetModuleHeaderAddress(blockNr);*/

   /* Check if logical block contains a verification key update */
   /* (void)FblReadProm(applHdrAddr + kApplInfoOffsetVerificationKeyState, keyBuffer, kApplInfoSizeVerificationKeyState + kApplInfoSizeVerificationKey); */
   if (ReadApplInfoHeader(blockNr, kApplInfoOffsetVerificationKeyState, &(keyBuffer[0]), kApplInfoSizeVerificationKeyState + kApplInfoSizeVerificationKey) == kFblOk)
   {
      if (keyBuffer[0] == kApplInfoVerificationKeyPresent)
      {
         /* Store verification key in NvM */
         result = ApplFblNvWriteVerificationKeyValue(0, &keyBuffer[1]);
         if (result == kFblOk)
         {
            result = ApplFblNvWriteVerificationKeyState(0, keyBuffer);
         }
      }
   }
   else
   {
      result = kFblFailed;
   }

   return result;
}

#if defined( FBL_ENABLE_OTA )
/***********************************************************************************************************************
 *  ApplFblVerifyModule
 **********************************************************************************************************************/
/*! \brief       Function is called after the vOtaM swapped/copied a module.
 *  \param[in]   partitionId Destination partition ID
 *  \param[in]   moduleId Module ID
 *  \return      Returns E_OK if the verification was sucessful, otherwise E_NOT_OK
 **********************************************************************************************************************/
/* PRQA S 6050, 6080 1 */  /* MD_MSR_STCAL, MD_MSR_STMIF */
Std_ReturnType ApplFblVerifyModule(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId)
{
   Std_ReturnType retVal;
   tFblResult result;
   vOtaM_PartitionInfoType sourcePart;
   vuint32 nvModuleId;
   vOtaM_PartitionInfoType part;
   tFblLbtBlockNr blockNr;

   /* Local buffers for NVM data */
   vuint8 nvmFingerprintStatus;
   vuint8 nvmFingerprint[kEepSizeFingerprint];
   vuint8 nvmProgAttemts[kEepSizeProgAttempts];
   vuint8 nvmSegmentCount;
   vuint8 nvmSegmentAddrList[kEepSizeSegmentAddrList];
   vuint8 nvmSegmentLengthList[kEepSizeSegmentLengthList];
   vuint8 cmac[SEC_SIZE_CMAC_AES];
   vuint8 nvmCrcWritten[kEepSizeCRCWritten];
# if defined( SEC_ENABLE_CRC_TOTAL )
   vuint8 nvmCrcTotal[kEepSizeCRCTotal];
# endif

   retVal = E_NOT_OK;
   result = kFblFailed;
   blockNr = vOtaM_GetLogicalBlockNumberOfModule(moduleId);
   sourcePart = vOtaM_GetSourcePartition();

   /* Switch to source partition to read all NVM data */
   if (vOtaM_ActivatePartition(sourcePart.Id, &part, VOTAM_ACTIVATION_STATE_USE_PARTITION) == E_OK)
   {
      nvModuleId = ApplFblGetNvModuleId(blockNr);

      /* Read meta data of module in source partition */
      result = ApplFblNvReadCmac((WRAPNV_PositionType)nvModuleId, cmac);
      result |= ApplFblNvReadSegmentCount((WRAPNV_PositionType)nvModuleId, &nvmSegmentCount);
      result |= ApplFblNvReadSegmentAddrList((WRAPNV_PositionType)nvModuleId, nvmSegmentAddrList);
      result |= ApplFblNvReadSegmentLengthList((WRAPNV_PositionType)nvModuleId, nvmSegmentLengthList);
      result |= ApplFblNvReadFpStatusInfo((WRAPNV_PositionType)nvModuleId, &nvmFingerprintStatus);
      result |= ApplFblNvReadFingerprint((WRAPNV_PositionType)nvModuleId, nvmFingerprint);
      result |= ApplFblNvReadProgAttempts((WRAPNV_PositionType)nvModuleId, nvmProgAttemts);
      result |= ApplFblNvReadCRCWritten((WRAPNV_PositionType)nvModuleId, nvmCrcWritten);
# if defined( SEC_ENABLE_CRC_TOTAL )
      result |= ApplFblNvReadCRCTotal((WRAPNV_PositionType)nvModuleId, nvmCrcTotal);
# endif

# if defined( FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC )
      if (result == kFblOk)
      {
         SecM_StatusType secStatus;
         vuintx idx;
         tFblAddress segStartAddr;
         tFblLength segLength;
         tFblAddress segEndAddr;
         tFblLength readLength;
         vuint8 readData[128u];

         /* Verify written data with stored CMAC */
         secStatus = SecM_MacVerifyJob(SmhConf_SmhJob_SmhMacVerify, SECM_OPERATIONMODE_START, NULL_PTR, NULL_PTR, 0u, NULL_PTR, 0u);

         /* Calculate CMAC over all written segments */
         for (idx = 0u; (idx < nvmSegmentCount) && (secStatus == SECM_OK); idx++)
         {
            segStartAddr = FblMemGetInteger(kDiagFmtFixedAddrSize, &nvmSegmentAddrList[idx * kDiagFmtFixedAddrSize]);
            segLength = FblMemGetInteger(kDiagFmtFixedAddrSize, &nvmSegmentLengthList[idx * kDiagFmtFixedAddrSize]);
            segEndAddr = segStartAddr + segLength;

            while ((segStartAddr < segEndAddr) && (secStatus == SECM_OK))
            {
               if (segLength > sizeof(readData))
               {
                  readLength = sizeof(readData);
               }
               else
               {
                  readLength = segLength;
               }
               (void)FblReadProm(segStartAddr, readData, readLength);
               secStatus = SecM_MacVerifyJob(SmhConf_SmhJob_SmhMacVerify, SECM_OPERATIONMODE_UPDATE, NULL_PTR, readData, readLength, NULL_PTR, 0u);
               segStartAddr += readLength;
               segLength -= readLength;
            }            
         }
         /* Verify that CMAC in NVM matches to logical block data */
         secStatus = SecM_MacVerifyJob(SmhConf_SmhJob_SmhMacVerify, SECM_OPERATIONMODE_FINISH, NULL_PTR, NULL_PTR, 0u, cmac, SEC_SIZE_CMAC_AES);

         if (secStatus != SECM_OK)
         {
            result = kFblFailed;
         }
      }
# endif /* FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC */
   }

   if (result == kFblOk)
   {
      /* Switch to destination partition to write all NVM data */
      if (vOtaM_ActivatePartition(partitionId, &part, VOTAM_ACTIVATION_STATE_USE_PARTITION) == E_OK)
      {
         nvModuleId = ApplFblGetNvModuleId(blockNr);

         /* Store module meta data in target partition */
         result = ApplFblNvWriteCmac((WRAPNV_PositionType)nvModuleId, cmac);
         result |= ApplFblNvWriteSegmentCount((WRAPNV_PositionType)nvModuleId, &nvmSegmentCount);
         result |= ApplFblNvWriteSegmentAddrList((WRAPNV_PositionType)nvModuleId, nvmSegmentAddrList);
         result |= ApplFblNvWriteSegmentLengthList((WRAPNV_PositionType)nvModuleId, nvmSegmentLengthList);
         result |= ApplFblNvWriteFpStatusInfo((WRAPNV_PositionType)nvModuleId, &nvmFingerprintStatus);
         result |= ApplFblNvWriteFingerprint((WRAPNV_PositionType)nvModuleId, nvmFingerprint);
         result |= ApplFblNvWriteProgAttempts((WRAPNV_PositionType)nvModuleId, nvmProgAttemts);
         result |= ApplFblNvWriteCRCWritten((WRAPNV_PositionType)nvModuleId, nvmCrcWritten);
# if defined( SEC_ENABLE_CRC_TOTAL )
         result |= ApplFblNvWriteCRCTotal((WRAPNV_PositionType)nvModuleId, nvmCrcTotal);
# endif
      }
      else
      {
         result = kFblFailed;
      }
   }

   if (result == kFblOk)
   {
      retVal = E_OK;
   }

   return retVal;
}
#endif /* FBL_ENABLE_OTA */

# if defined( FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC )
#  if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT )
/***********************************************************************************************************************
 *  ApplFblOutputCalculateOfrLightCmac
 **********************************************************************************************************************/
/*! \brief       This function calculates the OFR light CMAC of the downloaded logical block
 *  \details     The CMAC is calculated based on the segment list and does not take start address and length of
 *               segments into account. The calculated CMAC will be stored in NVM.
 *  \return      kFlashErased if block is already erased, kFlashNotErased if block is not erased
 **********************************************************************************************************************/
tFblResult ApplFblOutputCalculateOfrLightCmac(tFblLbtBlockNr blockNr, const V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam)
{
   SecM_StatusType secmResult;
   tFblResult retval = kFblOk;
   vuint8 cmac[SEC_SIZE_CMAC_AES];
   SecM_WordType cmacLength;
   vuintx idx;
   tFblAddress segEndAddr;
   tFblLength readLength;
   vuint8 readData[128u];
   tFblAddress segStartAddr;
   tFblLength segLength;

   secmResult = SecM_MacGenerateJob(SmhConf_SmhJob_SmhJob_MacGenerate, SECM_OPERATIONMODE_START, NULL_PTR, NULL_PTR, 0u, NULL_PTR, NULL_PTR);

   for (idx = 0u; (idx < pVerifyParam->segmentList.nrOfSegments) && (secmResult == SECM_OK); idx++)
   {
      segStartAddr = pVerifyParam->segmentList.segmentInfo[idx].targetAddress;
      segLength = pVerifyParam->segmentList.segmentInfo[idx].length;
      segEndAddr = segStartAddr + segLength;

      while ((segStartAddr < segEndAddr) && (secmResult == SECM_OK))
      {
         if (segLength > sizeof(readData))
         {
            readLength = sizeof(readData);
         }
         else
         {
            readLength = segLength;
         }
         pVerifyParam->readMemory(segStartAddr, readData, readLength);
         secmResult = SecM_MacGenerateJob(SmhConf_SmhJob_SmhJob_MacGenerate, SECM_OPERATIONMODE_UPDATE, NULL_PTR, readData, readLength, NULL_PTR, NULL_PTR);
         segStartAddr += readLength;
         segLength -= readLength;
      }
   }

   if (secmResult == SECM_OK)
   {
      secmResult = SecM_MacGenerateJob(SmhConf_SmhJob_SmhJob_MacGenerate, SECM_OPERATIONMODE_FINISH, NULL_PTR, NULL_PTR, 0u, cmac, &cmacLength);
   }

   if (secmResult == SECM_OK)
   {
      if (WRAPNV_E_OK != ApplFblNvWriteCmac(ApplFblGetNvModuleId(blockNr), cmac))
      {
         secmResult = SECM_NOT_OK;
      }
   }

   if (secmResult != SECM_OK)
   {
      retval = kFblFailed;
   }

   return retval;
}
#  else /* FBL_MEM_ENABLE_VERIFY_OUTPUT */
/***********************************************************************************************************************
 *  ApplFblPipelinedCalculateOfrLightCmac
 **********************************************************************************************************************/
/*! \brief       This function calculates the OFR light CMAC of the downloaded logical block
 *  \details     Only CMAC calculation start and update are triggered. Finalization of the the CMAC calculation will
 *               be done by ApplFblPipelinedFinalizeOfrLightCmac
 *  \return      SECM_OK: CMAC calculation start/update successful; Other: CMAC calculation start/update failed
 **********************************************************************************************************************/
SecM_StatusType ApplFblPipelinedCalculateOfrLightCmac(const V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam)
{
   SecM_StatusType result = SECM_OK;
   SecM_OperationModeType mode = SECM_OPERATIONMODE_NONE;
   vuint8 cmac[SEC_SIZE_CMAC_AES];
   SecM_WordType cmacLength;

   if (pVerifyParam->sigState == SEC_HASH_INIT)
   {
      mode = SECM_OPERATIONMODE_START;
   }
   if (pVerifyParam->sigState == SEC_HASH_COMPUTE)
   {
      mode = SECM_OPERATIONMODE_UPDATE;
   }

   if (mode != SECM_OPERATIONMODE_NONE)
   {
      result = SecM_MacGenerateJob(SmhConf_SmhJob_SmhJob_MacGenerate, mode, NULL_PTR, pVerifyParam->sigSourceBuffer, pVerifyParam->sigByteCount, cmac, &cmacLength);
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblPipelinedFinalizeOfrLightCmac
 **********************************************************************************************************************/
/*! \brief       This function finalizes the OFR light CMAC calculation of the downloaded logical block
 *  \details     CMAC is only finalized by this function. The data for the CMAC calculation are fed via the function
 *               ApplFblPipelinedCalculateOfrLightCmac
 *  \return      kFlashErased if block is already erased, kFlashNotErased if block is not erased
 **********************************************************************************************************************/
tFblResult ApplFblPipelinedFinalizeOfrLightCmac(tFblLbtBlockNr blockNr)
{
   tFblResult retval = kFblOk;
   SecM_StatusType secmResult;
   vuint8 cmac[SEC_SIZE_CMAC_AES];
   SecM_WordType cmacLength;

   secmResult = SecM_MacGenerateJob(SmhConf_SmhJob_SmhJob_MacGenerate, SECM_OPERATIONMODE_FINISH, NULL_PTR, NULL_PTR, 0u, cmac, &cmacLength);

   if (secmResult == SECM_OK)
   {
      if (WRAPNV_E_OK != ApplFblNvWriteCmac(ApplFblGetNvModuleId(blockNr), cmac))
      {
         secmResult = SECM_NOT_OK;
      }
   }

   if (secmResult != SECM_OK)
   {
      retval = kFblFailed;
   }

   return retval;
}
#  endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT */
# endif /* FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC */
 /* FBL_ENABLE_OTA */

/***********************************************************************************************************************
 *  ApplFblGetModuleId
 **********************************************************************************************************************/
/*! \brief       Function is called to get module idx for NV data structure
 *  \param[in]   blockNr Logical block number
 *  \return      Module idx for NV data structure
 **********************************************************************************************************************/
vuint32 ApplFblGetNvModuleId(tFblLbtBlockNr blockNr)
{
   vuint32 nvmModuleIndex;
#if defined( FBL_ENABLE_OTA )
   Std_ReturnType result;
   vOtaM_PartitionInfoType* part;

   /* PRQA S 2983 1 */ /* MD_FblKbApiFrameNV_2983 */
   result = vOtaMGetPartitionByAddrAreaId(MemDriver_GetAddressArea(), &part);
   assertFblUser((result == kFblOk), kFblOemAssertIllegalReturnValue);

   /* Calculate index for NV data structure */
   nvmModuleIndex = (blockNr + (part->Id * FBL_LBT_BLOCK_COUNT));
#else
   nvmModuleIndex = blockNr;
#endif /* FBL_ENABLE_OTA */

   return nvmModuleIndex;
}

/***********************************************************************************************************************
 *  ApplFblGetVin
 **********************************************************************************************************************/
/*! \brief       Returns VIN and it's length
 *  \param[in]   DataPtr Return parameter for pointer to VIN array
 *  \param[in]   LenBytePtr Return parameter for length of VIN array
 **********************************************************************************************************************/
void ApplFblGetVin( vuint8 ** DataPtr, vuint16 * LenBytePtr )
{
  *DataPtr = (vuint8 *) &(kVin[0]);
  *LenBytePtr = sizeof(kVin);
}
/***********************************************************************************************************************
 *  ApplFblGetDiagPowerMode
 **********************************************************************************************************************/
/*! \brief       Returns the Diagnostic Power Mode
 *  \param[in]   DiagPowerModePtr Return parameter for Diagnostic Power Mode
 **********************************************************************************************************************/
void ApplFblGetDiagPowerMode ( vuint8 * DiagPowerModePtr )
{
   *DiagPowerModePtr = kDiagPowerMode;
}

/* module specific MISRA deviations:


   MD_FblKbApi_2889:
      Reason:     Multiple return paths are used to reduce code complexity, increase readability and reducing nesting level.
      Risk:       Some operations intended to conclude the function (e.g. states cleaning) can be unintentionally jumped.
      Prevention: Code inspection and runtime tests.

   MD_FblKbApi_3201:
      Reason: Configuration or platform specific dependent unreachable code.
      Risk: Incorrect behavior depend on settings.
      Prevention: No prevention required.

   MD_FblKbApi_3206:
      Reason:     Function is part of the bootloader API and the modification or not of the parameter is dependent on
                  configuration and/or platform.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApi_3218_FileScopeStatic:
      Reason: Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk: Unintended use of object in wrong scope.
      Prevention: Architectural pattern supports prevention of incorrect use of objects in wrong context.
                  Code inspection focus on correct use of objects.

   MD_FblKbApi_3325:
      Reason: This control expression is always true or false depend on configuration aspect and used platform specific
              implementation.
      Risk: Incorrect behavior depend on settings.
      Prevention: No prevention required.

   MD_FblKbApi_3353:
      Reason: Variable is set in an other function via call-by-reference.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApi_3673:
      Reason: Function is part of the bootloader API which provides the possibility to influence the bootloader behavior
              by modifying the output parameters. The provided default implementation of the function doesn't
              necessarily make use of all available parameters.
      Risk: The parameter value might be changed unintentionally, thus causing malfunction in the calling instance.
      Prevention: Provide detailed information about the API and its usage in the user documentation.

   MD_FblKbApiOem_0313:
      Reason:     The watchdog trigger function is stored as void pointers as actual type
      Risk:       Function signature not compatible with expected type.
      Prevention: No prevention required.

   MD_FblKbApiOem_0314:
      Reason:     Type conversion to void * is necessary to use the standard MEMCPY API
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_0314_VoidPtrTypedPtr:
      Reason:     SecM uses untyped void pointers for context.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_2741_4558:
      Reason:     Assertion macros have to be disabled in production code and are used only for development.
      Risk:       Assertion code may be enabled in production code unintentionally. If a assertion condition is unexpectedly
                  false, the code is active. A problem may occur if the Macro is additionally changed from single statement
                  to multiple statement.
      Prevention: Macro is not allowed to be changed without review. Development code is automatically disabled via
                  configuration of project state "Production".

   MD_FblKbApiOem_2742:
      Reason:     Compiler related constand expression to check actual size.
      Risk:       No risk.
      Prevention: No prevention required. (Note: assertions are disabled in production software).

   MD_FblKbApiOem_2985:
      Reason:     Macro SetReprogProcessState clears the reprogramming process state flags and then
                  assigns a value of 0.
      Risk:       No identifiable risk
      Prevention: No prevention required.

   MD_FblKbApiOem_2987_EmptyFunction:
      Reason:     Function is empty depending on configuration aspects and platform specific implementation.
      Risk:       Function implementation missing.
      Prevention: Code inspection and test in the component test.

   MD_FblKbApiOem_2991_2995:
      Reason:     Code is shared between different configurations. In other configurations,
                  the result of the comparison/logical operation is not invariant.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_3218_FileScopeStatic:
      Reason:     Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk:       Unintended use of object in wrong scope.
      Prevention: Architectural pattern supports prevention of incorrect use of objects in wrong context.
                  Code inspection focus on correct use of objects.

   MD_FblKbApiOem_3425:
      Reason:     The WrapNv call uses the ternary operator to remap the return value of IO_E_OK to kFblOk.As both of
                  them are defined to the value zero the remapping has no side affects.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_4342_4521_ConfigurationEnumLengthCast:
      Reason:     The last element of an enum is used to determine the number of entries. This is required for
                  configurable code. The enum must have more than one entry - therefore it is always possible to
                  determine the last (length - 1) one.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiFrameNV_2983:
      Reason:     Value assignment is done but assigned value is not used in all configurations.
      Risk:       Adds an possibly unused assignment which could result in a compiler warning.
      Prevention: Ignore compiler warning if observed.

   MD_FblKbApiFrameNv_2985:
      Reason:     Some defines are placeholders/set to 0 depending on the configuration
      Risk:       No identifiable risk
      Prevention: No prevention required.

*/
/***********************************************************************************************************************
 *  FBL_APNV.C
 **********************************************************************************************************************/
