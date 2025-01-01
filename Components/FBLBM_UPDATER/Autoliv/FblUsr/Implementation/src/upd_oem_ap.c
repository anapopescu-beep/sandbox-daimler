/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         FBL updater callout routines - OEM specific
 *
 *  \note          Please note, that this file contains a collection of callback functions to be used with the
 *                 FBL Updater. These functions may influence the behavior of the updater in principle.
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
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Marco Riedl                   Rie           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2019-03-13  Rie     ESCAN00102469    Added support for LibNvPattern
 **********************************************************************************************************************/

#define UPD_OEM_AP

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "upd_oem_ap.h"
#include "Fbl_Lbt.h"
#include "fbl_lbt_access.h"
#include "WrapNv_inc.h"
#if defined( FBL_ENABLE_PRESENCE_PATTERN )
# include "fbl_nvpattern.h"
#endif

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLUPD_AP_DAIMLER_VERSION != 0x0200u ) || \
    ( FBLUPD_AP_DAIMLER_RELEASE_VERSION != 0x00u )
# error "Error in upd_oem_ap.c: Source and Header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Application software information */
#define kApplInfoSizeSwVersion                  0x03u
#define kApplInfoSizeSwPartNumber               0x0Au
#define kApplInfoSizeSwSupplierInformation      0x02u
#define kApplSizeDDSPackageReleaseAppl          0x02u
#define kApplInfoSizeDowngradeProtVersion       0x03u
#define kApplInfoSizeVerificationKeyState       0x01u
#define kApplInfoSizeVerificationKey            0x20u
#define kApplInfoSizeSwCompatibility            0x02u
#define kApplInfoSizeHwCompatibilityCounter     0x01u
#define kApplInfoSizeHwCompatibility            0x02u
#define kApplInfoNumberHwCompatibilityEntries   0x03u

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/* The following structure is used to get information from the downloaded logical block */
typedef struct
{
   vuint8 kApplSwVersion[kApplInfoSizeSwVersion];
   vuint8 kApplSwPartNumber[kApplInfoSizeSwPartNumber];
   vuint8 kApplSwSupplierInformation[kApplInfoSizeSwSupplierInformation];
   vuint8 kApplDDSPackageReleaseAppl[kApplSizeDDSPackageReleaseAppl];
   vuint8 kApplDowngradeProtVersion[kApplInfoSizeDowngradeProtVersion];
   vuint8 kApplVerificationKeyState;
   vuint8 kApplVerificationKeyValue[kApplInfoSizeVerificationKey];
   vuint8 kApplSwCompatibilityField[kApplInfoSizeSwCompatibility];
   vuint8 kApplHwCompatibilityLength;
   vuint8 kApplHwCompatibilityField[kApplInfoSizeHwCompatibility * kApplInfoNumberHwCompatibilityEntries];
} tApplInfoHeader;


/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
/** Reset response flag */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 resetRespFlag;
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define APPL_FBL_INFO_HEADER_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMROM0 V_MEMROM1 tApplInfoHeader V_MEMROM2 ApplInfoHeader =
{
   {0x15, 0x33, 0x00},
   {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a},
   {0xa0, 0x50},
   {0x0E, 0x01},
   {0x00u, 0x01u},
   kApplInfoNumberHwCompatibilityEntries,
   {0x00, 0x11u, 0x00u, 0x12u, 0x00, 0x13u}
};
#define APPL_FBL_INFO_HEADER_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
#else
static tFblResult ApplFblChgBlockValid( vuint8 mode, tBlockDescriptor descriptor );
#endif /* FBL_ENABLE_PRESENCE_PATTERN */

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
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ApplFblUpdOemInit
 **********************************************************************************************************************/
/*! \brief       Callback function to initialize OEM specifics
 **********************************************************************************************************************/
void ApplFblUpdOemInit(void)
{
   /* Initialize NvM-Stack */
#if defined( WRAPNV_USECASE_FEE )
   WrapNv_Init();
#else
   /* Initialize EEPROM-Driver */
   (void)EepromDriver_InitSync(V_NULL);
#endif /* WRAPNV_USECASE_FEE */
}

/***********************************************************************************************************************
 *  ApplFblUpdOemInvalidateUpdater
 **********************************************************************************************************************/
/*! \brief    Callback function to invalidate the updater/application
 *  \details  Update validity information of e.g. Eep-data
 *  \return   invalidation state
 **********************************************************************************************************************/
tFblResult ApplFblUpdOemInvalidateUpdater( void )
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;

   if (FblLbtGetBlockDescriptorByNr(FBL_UPD_LBT_NR_OF_UPDATER, &blockDescriptor) == kFblOk)
   {
#if defined( FBL_ENABLE_PRESENCE_PATTERN )
      result = FblNvPatternClr(&blockDescriptor, kFblNvPatternId_BlockValidity);
#else
      result = ApplFblChgBlockValid(kEepInvalidateBlock, blockDescriptor);
#endif /* FBL_ENABLE_PRESENCE_PATTERN */
   }

   return result;
}

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
/***********************************************************************************************************************
 *  ApplFblUpdOemCheckResponsePending
 **********************************************************************************************************************/
/*! \brief    Callback function to check if response pending message is needed
 *  \return   invalidation state
 **********************************************************************************************************************/
tFblResult ApplFblUpdOemCheckResponsePending( void )
{
   tFblResult result;

   result = kFblFailed;

   /* Check if reset-flag is set */
   if (kFblOk == ApplFblReadResetResponseFlag(&resetRespFlag))
   {
      if (   (resetRespFlag == RESET_RESPONSE_SDS_REQUIRED)
          || (resetRespFlag == RESET_RESPONSE_ECURESET_REQUIRED))
      {
         result = kFblOk;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblUpdOemPrepareResponsePending
 ***********************************************************************************************************************/
/*! \brief        Callout to prepare buffer with response pending (RCR-RP) message
 ***********************************************************************************************************************/
void ApplFblUpdOemPrepareResponsePending(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pResponse)
{
   if (resetRespFlag == RESET_RESPONSE_SDS_REQUIRED)
   {
      /* Prepare RCR-RP for service DiagnosticSession */
      pResponse[0u] = 0x7Fu;
      pResponse[1u] = 0x10u;
      pResponse[2u] = 0x78u;
   }
   else if (resetRespFlag == RESET_RESPONSE_ECURESET_REQUIRED)
   {
      /* Prepare RCR-RP for service EcuReset */
      pResponse[0u] = 0x7Fu;
      pResponse[1u] = 0x11u;
      pResponse[2u] = 0x78u;
   }
   else
   {
      /* Satisfy MISRA */
   }
}

#  if ( FblCw_GetSizeOfDcmDslConnectionInfo() > 1u )
/***********************************************************************************************************************
*  ApplFblWriteDcmDslRxTesterSourceAddr
**********************************************************************************************************************/
/*! \brief       Function to write DcmDsl Rx Tester Source Address to non-volatile memory
 *  \param[in]   buffer Pointer to byte array containing the tester source address
 *  \return      Result of write operation
**********************************************************************************************************************/
tFblResult ApplFblWriteDcmDslRxTesterSourceAddr(vuint8* buffer)
{
   return ApplFblNvWriteDcmDslRxTesterSourceAddr(buffer);
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
   return ApplFblNvReadDcmDslRxTesterSourceAddr(buffer);
}
#  endif /* ( FblCw_GetSizeOfDcmDslConnectionInfo() > 1u ) */
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */

/***********************************************************************************************************************
 *  END OF FILE: UPD_OEM_AP.C
 **********************************************************************************************************************/
