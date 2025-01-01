/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Implementation of pattern/mask based non-volatile information storage
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  TEMPLATE REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.04.00   2019-01-25  viskjs  ESCAN00101824    Added patterns that can be validated multiple times
 *                                 ESCAN00101823    Added feature to store arbitrary values at end of logical block
 *  01.04.01   2019-03-26  viskjs  ESCAN00102200    No changes
 *                                 ESCAN00102204    No changes
 *                                 ESCAN00102646    No changes
 *  01.04.02   2019-07-22  vistbe  ESCAN00103605    No changes
 *  01.04.03   2020-05-07  visjdn  ESCAN00106002    No changes
 *  01.04.04   2021-03-03  visrie  ESCAN00108616    No changes
 *                                 ESCAN00108753    No changes
 *                                 FBL-3129         Added/adapted MemMap sections
 *                                                  Update to MISRA 2012
 *  01.04.05   2021-03-16  visrie  ESCAN00108859    No changes
 *  01.05.00   2021-06-16  visrie  FBL-3641         Support OTA use case and user extension
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  10.01.00   2021-01-19  viscb   FBL-2244         DRECU2020-01 adaptions, added support for OTA
 *  10.01.01   2021-02-02  viscb   ESCAN00108445    QM release
 *  10.01.02   2021-04-21  viscb   ESCAN00108537    No changes
 *                                 ESCAN00108093    No changes
 *                                 ESCAN00108139    No changes
 *                                 FBL-3360         Added/adapted MemMap sections
 *  10.01.03   2021-05-28  viscb   ESCAN00109398    No changes
 *                                 ESCAN00109400    No changes
 *  10.01.04   2021-06.07  viscb   ESCAN00109435    No changes
 *                                 ESCAN00109437    No changes
 *  10.02.00   2021-07-09  vishor  FBL-3567         Updated MISRA justifications
 *                                 ESCAN00107081    No changes
 *  10.02.01   2021-08-26  visjdn  ESCAN00109069    No changes
 *  10.02.02   2021-10-27  visrie  ESCAN00109153    No changes
 *  10.03.00   2022-03-15  vishor  FBL-4621         No changes
 *                                 ESCAN00110728    No changes
 *                                 ESCAN00110898    No changes
 *                                 ESCAN00110960    No changes
 *                                 ESCAN00111146    No changes
 *                                 ESCAN00111396    No changes
 *  10.04.00   2022-06-01  vishor  FBL-5094         No changes
 *                                 ESCAN00110486    No changes
 *  10.04.01   2022-06-27  vismix  ESCAN00112173    No changes
 *                                 ESCAN00112160    No changes
 *  10.04.02   2022-08-26  vismix  FBL-5754         No changes
 *                                 ESCAN00112447    No changes
 *                                 ESCAN00112459    No changes
 *  10.04.03   2023-01-09  vismix  ESCAN00112744    No changes
 *                                 ESCAN00113013    No changes
 *                                 ESCAN00113078    No changes
 **********************************************************************************************************************/

#define FBL_NVPATTERN_OEM_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "fbl_nvpattern_oem.h"

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLNVPATTERN_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined ( FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION )
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 fblNvPatternMultiplicity[] =
{
   1u /**< kFblNvPatternId_ModuleValidity can be validated/invalidated once after erasure */
  ,1u /**< kFblNvPatternId_PartitionValidity can be validated/invalidated once after erasure */
# if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
  ,1u /**< kFblNvPatternId_ErasedState can be validated/invalidated once */
# endif /* FBL_ENABLE_FLASH_ERASED_DETECTION */
# if defined( FBL_ENABLE_OTA )
  ,FBL_NVPATTERN_ACTIVATION_PENDING_NUM  /**< kFblNvPatternId_ActivationPending can be validated/invalidated a
                                              configurable amount of times */
# endif /* FBL_ENABLE_OTA */
   FBL_NVPATTERN_USER_PATTERN_MULTIPLICITY
};
#endif /* FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION */

#if defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
V_MEMROM0 V_MEMROM1 tFblBlockProperty V_MEMROM2 fblNvBlockProperties[] =
{
# if defined( FBL_ENABLE_OTA )
   {
      FBL_NVPATTERN_REVISION_SIZE,      /**< Size of kFblNvProperty_PartitionRev in bytes */
      kFblNvPatternId_PartitionValidity /**< Property only valid if partition is valid. The partition validity is always
                                             set in the same module as the partition revision. */
   },
   {
      FBL_NVPATTERN_REVISION_SIZE,   /**< Size of kFblNvProperty_ModuleRev in bytes */
      kFblNvPatternId_ModuleValidity /**< Property only valid if module is valid. */
   }
# endif /* FBL_ENABLE_OTA */
   FBL_NVPATTERN_USER_PROPERTY_ENTRY
};
#endif /* FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */

#define FBLNVPATTERN_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* module specific MISRA deviations:

   MD_FblNvPatternOem_0724_EnumValNotUnique:
      Reason:     The same numerical value is associated to different enum entries, to allows each entry value to be used in
                  the appropriate context, keeping a better code structure and understanding.
      Risk:       Enum values can potentially be assigned with the same value unintentionally.
      Prevention: Correct design.

   MD_FblNvPatternOem_3684:
     Reason:      The size of the array is determined only at compile time.
     Risk:        The code is less clear and require more analysis for a deep understanding.
     Prevention:  No prevention defined.
*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_NVPATTERN_OEM.C
 **********************************************************************************************************************/
