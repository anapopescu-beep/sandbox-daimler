/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         SecureBoot implementation
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
 *  01.00.00   2020-01-07  visrie  FBL-524          Initial release
 *  01.00.01   2020-04-27  visrie  FBL-1773         No changes
 *  02.00.00   2020-05-19  vistbe  FBL-1016         Support EcuM_Init() mechanism
 *  02.01.00   2021-01-19  visrie  FBL-2648         Added support of new SecureBoot verify variant
 *                                 FBL-2641         Updated to new API version
 *  02.02.00   2021-09-03  visjdn  FBL-3352         No changes
 **********************************************************************************************************************/

#define FBL_SECBOOT_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "Std_Types.h"
#include "Csm.h"
#include "bm_types.h"
#include "bm_hdr.h"
#include "fbl_secboot.h"

#if defined( FBLSB_ENABLE_COPY_FLASH_DRIVER )
#  include "FlashRom.h"
#endif /* FBLSB_ENABLE_COPY_FLASH_DRIVER */

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLLIB_SECBOOT_VHSM_VERSION != 0x0202u ) || \
    ( FBLLIB_SECBOOT_VHSM_RELEASE_VERSION != 0x00u )
# error "Error in FBL_SECBOOT.C: Source and Header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/** Watchdog triggered every n-th cycle (has to power of two) */
#if !defined( FBLSB_WATCHDOG_CYCLE_COUNT )
# define FBLSB_WATCHDOG_CYCLE_COUNT    0x20u
#endif
/** Trigger watchdog every n-th cycle */ /* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define FBLSB_TRIGGER_WATCHDOG(cycle)                             \
{                                                                 \
   if (((cycle) & (FBLSB_WATCHDOG_CYCLE_COUNT - 1u)) == 0x00u)    \
   {                                                              \
      (void)FblLookForWatchdog();                                 \
   }                                                              \
}

/* PRQA S 3453 6 */ /* MD_MSR_FctLikeMacro */
#define FBLSB_VHSM_AUTHENTICATION_HEADER_LENGTH_BASE                    6u  /* GroupId (4) + NoOfSegments (2) */
#define FBLSB_VHSM_AUTHENTICATION_HEADER_LENGTH_SEGMENT                 42u /* Address (4) + Length (4) + Mode (2) + Hash (32) */
#define FBLSB_VHSM_AUTHENTICATION_HEADER_LENGTH_SEGMENTS(noOfSegments)  \
   ((noOfSegments) * FBLSB_VHSM_AUTHENTICATION_HEADER_LENGTH_SEGMENT)
#define FBLSB_VHSM_AUTHENTICATION_HEADER_LENGTH(noOfSegments)           \
   (FBLSB_VHSM_AUTHENTICATION_HEADER_LENGTH_BASE + FBLSB_VHSM_AUTHENTICATION_HEADER_LENGTH_SEGMENTS(noOfSegments))

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

V_MEMRAM0 static V_MEMRAM1 tFblSbExtErrCode V_MEMRAM2 sbExtErrCode;

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if defined( FBLSB_ENABLE_GENERATE_CMAC )
static tFblLength FblSb_GetAuthenticationHeaderLength(const V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * dataPtr);
static tFblResult FblSb_UpdateCommonMac(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor);
#endif /* FBLSB_ENABLE_GENERATE_CMAC */

/***********************************************************************************************************************
 *  EXTERNAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#if defined( FBLSB_ENABLE_GENERATE_CMAC )
/***********************************************************************************************************************
 *  FblSb_GetAuthenticationHeaderLength
**********************************************************************************************************************/
/*! \brief      Calculates the length of the vHsm authentication header
 *  \param[in]  dataPtr  Pointer to the vHsm authentication header
 *  \return     Length of the authentication header
 **********************************************************************************************************************/
static tFblLength FblSb_GetAuthenticationHeaderLength(const V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * dataPtr)
{
   tFblLength authHeaderLength;
   vuint32 noOfSegments;

   noOfSegments = FblMemGetInteger(2u, &dataPtr[4u]);
   authHeaderLength = FBLSB_VHSM_AUTHENTICATION_HEADER_LENGTH(noOfSegments);

   return authHeaderLength;
}

/***********************************************************************************************************************
 *  FblSb_UpdateCommonMac
 **********************************************************************************************************************/
/*! \brief      Generate and write the common MACs
 *  \param[in]  blockDescriptor  Pointer to the block descriptor
 *  \return     Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult FblSb_UpdateCommonMac(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor)
{
   tFblResult result;
   tFblBmHdrHeader bmHeader;
   Crypto_VerifyResultType verifyResult = CRYPTO_E_VER_NOT_OK;
   uint32 jobId;
   vuint32 macId;
   const uint8 * dataPtr;
   uint32 dataLength;
   uint32 signatureAddress;
   uint32 signatureLength;

   /* Clear any previous errors */
   sbExtErrCode = FBLSB_EXT_ERR_CODE_NONE;

   /* Read BM Header */
   if (FblReadProm(blockDescriptor->bmHeaderAddress, (vuint8 *)&bmHeader, sizeof(bmHeader)) != sizeof(bmHeader))
   {
      sbExtErrCode = FBLSB_EXT_ERR_CODE_MEMORY;
      result = kFblFailed;
   }
   else
   {
      result = FblBmHdrCheckConsistency(&bmHeader);
   }

   if (result == kFblOk)
   {
      macId = FblBmHdr_GetFblSbMacId(bmHeader.bmTargetHandle);

      /* Check if the SecureBootGroup can be updated */
      if (macId < FBLSB_NUM_OF_MAC_OPERATIONS)
      {
         jobId = FblSb_GetCsmJobIdOfMacUpdate();
         dataPtr = (const uint8 *)bmHeader.bmAuthenticationHeaderAddress;  /* PRQA S 0306 */ /* MD_FblLibSecBoot_0306 */
         dataLength = FblSb_GetAuthenticationHeaderLength(dataPtr);
         ApplFblSbGetSignatureInfo(blockDescriptor, &bmHeader, &signatureAddress, &signatureLength);

         /* PRQA S 0306 2 */ /* MD_FblLibSecBoot_0306 */
         if (E_OK != Csm_SignatureVerify(jobId, CRYPTO_OPERATIONMODE_SINGLECALL, dataPtr, dataLength,
                                        (P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR))signatureAddress, signatureLength, &verifyResult))
         {
            result = kFblFailed;
         }
      }
      else
      {
         /* This block has no SecureBootGroup and therefore can not be updated */
         result = kFblFailed;
      }
   }

   if (   (result == kFblOk)
       && (verifyResult != CRYPTO_E_VER_OK))
   {
      result = kFblFailed;
   }

   if (   (result != kFblOk)
       && (sbExtErrCode == FBLSB_EXT_ERR_CODE_NONE) )
   {
      sbExtErrCode = FBLSB_EXT_ERR_CODE_GENERAL;
   }

   return result;
}
#endif /* FBLSB_ENABLE_GENERATE_CMAC */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#if defined( FBLSB_ENABLE_COPY_FLASH_DRIVER )
/***********************************************************************************************************************
 *  FblUpdCopyFlashDriver
 ***********************************************************************************************************************/
/*! \brief        Copies the flashdriver from the ROM table into flashCode buffer
 ***********************************************************************************************************************/
void FblSb_CopyFlashDriver( void )
{
   vuint16 index;

   /* flashCode buffer location must match the flashdriver start address */
# if defined( FLASH_DRIVER_RELOCATABLE )
# else
   if ( (flashCode == (IO_U8 *)FLASHDRV_BLOCK0_ADDRESS) )
# endif /* FLASH_DRIVER_RELOCATABLE */
   {
      /* Copy all flash driver code from ROM into the flashCode buffer */
      for (index = 0u; index < FLASHDRV_BLOCK0_LENGTH; index++)
      {
         FBLSB_TRIGGER_WATCHDOG(index);
         flashCode[index] = FLASHDRV_DECRYPTDATA(flashDrvBlk0[index]);
      }
   }
}
#endif /* FBLSB_ENABLE_COPY_FLASH_DRIVER */

/***********************************************************************************************************************
 *  FblSb_Init
 ***********************************************************************************************************************/
/*! \brief        Initializes the SecureBoot module
 *  \details      Initializes the complete crypto stack
 ***********************************************************************************************************************/
void FblSb_Init(void)
{
   /* Crypto stack is initialized via EcuM_Init */

   sbExtErrCode = FBLSB_EXT_ERR_CODE_NONE;
}

/***********************************************************************************************************************
 *  FblSb_VerifyFblLbt
 **********************************************************************************************************************/
/*! \brief      Verifies the LogicalBlockTable of the bootloader
 *  \param[in]  fblHeader      Pointer to the FBL Header
 *  \return     Result of operation
 *                   kFblFailed always (unsupported feature)
 **********************************************************************************************************************/
tFblResult FblSb_VerifyFblLbt(const V_MEMRAM1 tFblHeader V_MEMRAM2 V_MEMRAM3 * fblHeader)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_DummyStmt */
   (void)fblHeader;
#endif

   return kFblFailed;
}

/***********************************************************************************************************************
 *  FblSb_VerifyHeader
 **********************************************************************************************************************/
/*! \brief      Verifies the header
 *  \param[in]  bmHdrHeader      Pointer to the FblBmHdrHeader structure
 *  \return     Result of operation
 *                   kFblFailed always (unsupported feature)
 **********************************************************************************************************************/
tFblResult FblSb_VerifyHeader(const V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 V_MEMRAM3 * bmHdrHeader)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_DummyStmt */
   (void)bmHdrHeader;
#endif

   return kFblFailed;
}

/***********************************************************************************************************************
 *  FblSb_UpdateInitialSegments
 **********************************************************************************************************************/
/*! \brief      Updates the SecureBootSegments based on the initial values.
 *  \return     Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblSb_UpdateInitialSegments(void)
{
   tFblResult result = kFblOk;
   Crypto_VerifyResultType verifyResult;
   uint32 jobId;
   vuint32 macOperationIdx;
   uint32 groupId;

   /* Iterrate over the configuration */
   for (macOperationIdx = 0u; ((macOperationIdx < FBLSB_NUM_OF_MAC_OPERATIONS) && (result == kFblOk)); macOperationIdx++)
   {
      jobId = FblSb_GetCsmJobIdOfMacVerifyForceSequential();

      if (FblSb_IsVerifyForceSequentialOfMacOperation(macOperationIdx))
      {
         result = kFblFailed;
         verifyResult = CRYPTO_E_VER_NOT_OK;
         groupId = FblSb_GetGroupIdOfMacOperation(macOperationIdx);
         if (Csm_MacVerify(jobId, CRYPTO_OPERATIONMODE_SINGLECALL, (uint8 *)&groupId, sizeof(groupId), NULL_PTR, 0u, &verifyResult) == E_OK)
         {
            if (verifyResult == CRYPTO_E_VER_OK)
            {
               result = kFblOk;
            }
         }
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblSb_VerifySegments
 **********************************************************************************************************************/
/*! \brief      Verifies the segments
 *  \details    Triggers a verification of the configured SecureBootGroup.
 *  \param[in]  bmHdrHeader      Pointer to the FblBmHdrHeader structure
 *  \return     Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblSb_VerifySegments(const V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 V_MEMRAM3 * bmHdrHeader)
{
   tFblResult result = kFblFailed;
   Crypto_VerifyResultType verifyResult = CRYPTO_E_VER_NOT_OK;
   uint32 macId = FblBmHdr_GetFblSbMacId(bmHdrHeader->bmTargetHandle);
   uint32 jobId;
   uint32 groupId;

   if (macId < FBLSB_NUM_OF_MAC_OPERATIONS)
   {
      jobId = FblSb_GetCsmJobIdOfMacVerify();
      groupId = FblSb_GetGroupIdOfMacOperation(macId);
      if (E_OK == Csm_MacVerify(jobId, CRYPTO_OPERATIONMODE_SINGLECALL, (uint8 *)&groupId, sizeof(groupId), NULL_PTR, 0u, &verifyResult))
      {
         result = kFblOk;
      }
   }

   if(   (result == kFblOk)
      && (verifyResult != CRYPTO_E_VER_OK))
   {
      result = kFblFailed;
   }

   return result;
}

#if defined( FBLSB_ENABLE_GENERATE_CMAC )
/***********************************************************************************************************************
 *  FblSb_UpdateFblMac
 **********************************************************************************************************************/
/*! \brief      Generate and write the necessary MACs for the FBL
 *  \param[in]  fblHeader      Pointer to the FBL Header
 *  \return     Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblSb_UpdateFblMac(V_MEMROM1 tFblHeader V_MEMROM2 V_MEMROM3 * fblHeader)
{
   tFblResult result;
   tBlockDescriptor fblBlockDescriptor;

   /* Initialize FBL block descriptor */
   fblBlockDescriptor.blockStartAddress = fblHeader->fblStartAddress;
   fblBlockDescriptor.blockLength = fblHeader->fblLength;
   fblBlockDescriptor.bmHeaderAddress = (tFblAddress)fblHeader->bmHeader;  /* PRQA S 0306 */ /* MD_FblLibSecBoot_0306 */
   fblBlockDescriptor.mandatoryType = TRUE;
   fblBlockDescriptor.blockNr = 0x00u;

   result = FblSb_UpdateCommonMac(&fblBlockDescriptor);

   return result;
}

/***********************************************************************************************************************
 *  FblSb_UpdateBlockMac
 **********************************************************************************************************************/
/*! \brief      Generate and write the necessary MACs for a logical block
 *  \param[in]  blockDescriptor  Pointer to the logical block
 *  \param[in]  segmentList      Pointer to the segments
 *  \return     Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
/* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
tFblResult FblSb_UpdateBlockMac(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
   V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * segmentList)
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_DummyStmt */
   (void)segmentList;
#endif

   result = FblSb_UpdateCommonMac(blockDescriptor);

   return result;
}
#endif /* FBLSB_ENABLE_GENERATE_CMAC */

/***********************************************************************************************************************
 *  FblSb_GetExtendedErrorCode
 **********************************************************************************************************************/
/*! \brief        Returns an extended error information from previous call to FblSb_UpdateBlockMac/FblSb_UpdateFblMac
 *  \return       Extended error code
 **********************************************************************************************************************/
tFblSbExtErrCode FblSb_GetExtendedErrorCode(void)
{
   return sbExtErrCode;
}

/***********************************************************************************************************************
 *  MISRA
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_FblLibSecBoot_0306:
      Reason:     Address conversion between integer values and pointers is required to allow for hardware independent
                  configuration and address range checks.
      Risk:       The size of integer required to hold the result of a pointer cast is implementation-defined.
      Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
                  specific basis. The correctness of the respective implementation is verified by runtime tests.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_SECBOOT.C
 **********************************************************************************************************************/
