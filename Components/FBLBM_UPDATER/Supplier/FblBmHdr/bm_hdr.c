/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         BM Header module
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
 *  01.00.00   2019-31-01  visrie  -                Initial release
 *  01.01.00   2019-02-18  vismvi  -                No changes
 *                         visrie  ESCAN00102184    Maximum number of verification entries are not correctly evaluated
 *  01.02.00   2019-07-22  visrie  ESCAN00103790    Support invalid entry address configuration
 *                                 ESCAN00103791    Support of custom verification
 *                                 ESCAN00103803    No changes
 *  02.00.00   2019-12-03  visrie  FBL-456          Added support for new FblLibSecBoot interface
 *  02.00.01   2020-01-15  visrie  ESCAN00105368    Added missing encapsulation
 *  02.01.00   2022-02-25  vistbe  FBL-4128         Added/adapted MemMap sections
 **********************************************************************************************************************/

#define BM_HDR_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "bm_main.h"
#include "fbl_lbt_access.h"

#if defined( FBLBM_ENABLE_SECURE_BOOT )
# include "fbl_secboot.h"
#endif

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLBM_HDR_VERSION != 0x0201u ) || \
    ( FBLBM_HDR_RELEASE_VERSION != 0x00u )
# error "Error in BM_HDR.C: Source and Header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
#define FBLBMHDR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  FblBmHdrGetBmHeader
 **********************************************************************************************************************/
/*! \brief        Validate a specific bootmanager header of a logical block
 *  \param[in]    targetHandle    Target handle (e.g. Bootloader, Application)
 *  \param[in]    bmHeaderAddress Location of the BmHeader structure.
 *  \param[out]   bmHeader        Buffer for the BmHeader
 *  \return       Result of operation
 *                   FBLBMHDR_CHKHDR_OK                  when operation succeeded
 *                   FBLBMHDR_CHKHDR_READ_FAIL           when reading the BmHeader failed
 *                   FBLBMHDR_CHKHDR_HEADER_INCONSISTENT when the BmHeader is inconsistent
 *                   FBLBMHDR_CHKHDR_WRONG_TARGET        when the BmHeader is for another target
 **********************************************************************************************************************/
tFblBmHdrCheckBmHeaderResult FblBmHdrGetBmHeader(tFblBmHdrTargetHandle targetHandle, tFblAddress bmHeaderAddress,
   V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 V_MEMRAM3 * bmHeader)
{
   tFblBmHdrCheckBmHeaderResult result;

   result = FBLBMHDR_CHKHDR_OK;

   if (FblReadProm(bmHeaderAddress, (vuint8 *)bmHeader, sizeof(tFblBmHdrHeader)) != sizeof(tFblBmHdrHeader))
   {
      result = FBLBMHDR_CHKHDR_READ_FAIL;
   }

   /* Check for correct target handle */
   if (result == FBLBMHDR_CHKHDR_OK)
   {
      if (bmHeader->bmTargetHandle != targetHandle)
      {
         result = FBLBMHDR_CHKHDR_WRONG_TARGET;
      }
   }

   /* Check for consistency errors */
   if (result == FBLBMHDR_CHKHDR_OK)
   {
      if (kFblOk != FblBmHdrCheckConsistency(bmHeader))
      {
         result = FBLBMHDR_CHKHDR_HEADER_INCONSISTENT;
      }
   }

   return result;
} /* PRQA S 6010 */ /* MD_MSR_STPTH */

/***********************************************************************************************************************
 *  FblBmHdrCheckConsistency
 **********************************************************************************************************************/
/*! \brief        Checks the consistency of the BM header structure
 *  \param[in]    bmHeader: Pointer to the BM Header structure
 *  \return       Result of operation
 **********************************************************************************************************************/
tFblResult FblBmHdrCheckConsistency( const V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 V_MEMRAM3 * pBmHeader )
{
   tFblResult result;
#if defined( FBLBMHDR_ENABLE_HEADER_VERIFICATION_LIST )
   vuintx i;
#endif /* FBLBMHDR_ENABLE_HEADER_VERIFICATION_LIST */

   /* Initialize variables */
   result = kFblOk;

   /* Check magic value */
   if (pBmHeader->bmMagicFlag != FBLBMHDR_MAGIC_FLAG)
   {
      result = kFblFailed;
   }

#if defined( FBLBMHDR_ENABLE_HEADER_VERIFICATION_LIST )
   /* Check number of verification regions */
   if (result == kFblOk)
   {
      if (pBmHeader->bmVerificationListEntries > FBLBMHDR_NUM_OF_VERIFICATION_ENTRIES)
      {
         result = kFblFailed;
      }
   }

   /* Check if a verification region contains the entry address */
   if (   (result == kFblOk)
       && (pBmHeader->bmEntryAddress != FBLBMHDR_ENTRY_ADDRESS_INVALID))
   {
      /* Change result to failed, it will be set back to OK if a valid region was found */
      result = kFblFailed;

      for (i = 0u; i < pBmHeader->bmVerificationListEntries; i++)
      {
         if (   (pBmHeader->bmEntryAddress >= pBmHeader->bmVerificationList[i].address)
             && (pBmHeader->bmEntryAddress < (pBmHeader->bmVerificationList[i].address + pBmHeader->bmVerificationList[i].length)))
         {
            /* Entry address is in a verification range */
            result = kFblOk;
            break;
         }
      }
   }
#endif /* FBLBMHDR_ENABLE_HEADER_VERIFICATION_LIST */

   return result;
}

#if defined( FBLBM_INSTANCE_BOOTMANAGER )
/***********************************************************************************************************************
 *  FblBmHdrFindValidHeader
 **********************************************************************************************************************/
/*! \brief        Find a valid bootmanager header structure for the given target
 *  \param[in]    targetHandle Target handle (e.g. Bootloader, Application)
 *  \param[in,out] pBlockInfo Pointer to a structure which holds a pointer to the BM header and the corresponding
 *                 logical block.
 *  \return       Result of operation
 *                   FBLBMHDR_CHKHDR_OK             A valid BmHeader is found
 *                   FBLBMHDR_CHKHDR_NOT_FOUND      No BmHeader found
 *                   FBLBMHDR_CHKHDR_BLOCK_INVALID  Logical block is not valid
 *                   see FblBmHdrCheckBmHeader      for further return values.
 *                   see FblBmHdrVerifyBmHeader     for further return values.
 **********************************************************************************************************************/
tFblBmHdrCheckBmHeaderResult FblBmHdrFindValidHeader(tFblBmHdrTargetHandle targetHandle,
   V_MEMRAM1 tFblBmBlockInfo V_MEMRAM2 V_MEMRAM3 * pBlockInfo)
{
   tFblBmHdrCheckBmHeaderResult result;
   tFblLbtBlockFilter blockFilter;

   /* Initialize variables */
   result = FBLBMHDR_CHKHDR_NOT_FOUND;

   /* Iterate over all mandatory blocks */
   FblLbtBlockFilterInit(&blockFilter);
   pBlockInfo->logicalBlock = FblLbtBlockFirst(&blockFilter);
   while (FblLbtBlockDone() == FALSE)
   {

      if (kFblOk == FBLBM_CALLOUT_IS_VALIDBLOCK(targetHandle, &pBlockInfo->logicalBlock))
      {
         result = FblBmHdrGetBmHeader(targetHandle, pBlockInfo->logicalBlock.bmHeaderAddress, &pBlockInfo->bmHeader);
      }
      else
      {
         result = FBLBMHDR_CHKHDR_BLOCK_INVALID;
      }

      if (result == FBLBMHDR_CHKHDR_OK)
      {
         /* Leave loop after first hit */
         break;
      }

      /* Prepare next cycle */
      pBlockInfo->logicalBlock = FblLbtBlockNext();
   }

   return result;
}
#endif /* FBLBM_INSTANCE_BOOTMANAGER */

#define FBLBMHDR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  END OF FILE: BM_HDR.C
 **********************************************************************************************************************/
