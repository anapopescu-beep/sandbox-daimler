/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application dependent routines
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
 *  01.00.00   2019-01-28  visrie  -                Initial version
 *  01.01.00   2019-02-18  vismvi  ESCAN00102171    No changes
 *                         visrie  ESCAN00102310    Added callout to check reprogramming flag
 *  01.01.01   2019-03-07  visrie  ESCAN00102386    No changes
 *                                 ESCAN00102399    No changes
 *  02.00.00   2019-05-02  visrie  ESCAN00102518    No changes
 *                                 ESCAN00102761    No changes
 *                                 ESCAN00103026    Provide BmHeader instead of StartAddress to ApplFblBmStartSoftware
 *  03.00.00   2019-07-17  visrie  ESCAN00103750    Removed target order list configuration
 *  03.01.00   2019-08-14  visrie  FBL-487          Exclude callouts if overwritten by OEM/HW layer
 *  03.01.01   2019-09-04  visrcn  ESCAN00103607    Memory qualifier mismatch
 *  04.00.00   2019-12-04  visrie  FBL-456          No changes
 *                                 ESCAN00105135    No changes
 *  04.01.00   2020-01-16  visrie  FBL-524          Added support for vHsm SecBoot library
 *  05.00.00   2020-04-09  visrie  FBL-1016         No changes
 *  05.01.00   2020-04-29  vistmo  FBL-1584         No changes
 *  05.02.00   2020-08-13  vistmo  FBL-1489         No changes
 *  05.02.01   2021-03-17  vishor  ESCAN00108386    No changes
 *                                 FBL-3018         Added/adapted MemMap sections
 *  05.03.00   2021-08-11  visrie  FBL-3394         Move default implementation of CheckReprogFlag into FblBm_Ap
 *  05.04.00   2021-09-17  visjdn  FBL-3865         No changes
 *  05.04.01   2022-04-06  vismix  FBL-4773         No changes
 *  05.05.00   2022-04-07  vishor  FBL-4822         No changes
 *  05.05.01   2022-06-23  vismix  ESCAN00111879    No changes
 *  05.06.00   2022-07-13  vismix  FBL-5391         Add callout for missing optional dependency
 *  05.06.01   2022-11-29  vishor  ESCAN00112986    Compiler error: Undefined symbols
 *                                                   ApplFblPreMemDriver/ApplFblPostMemDriver
 **********************************************************************************************************************/

#ifndef BM_AP_H
#define BM_AP_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblBm_Ap CQComponent : Implementation */
#define FBLBM_AP_VERSION               0x0506u
#define FBLBM_AP_RELEASE_VERSION       0x01u

/* Interface version */
/** Major interface version identifies incompatible changes */
#define FBLBM_AP_API_VERSION_MAJOR     0x03u
/** Minor interface version identifies backward compatible changes */
#define FBLBM_AP_API_VERSION_MINOR     0x00u
/** Release interface version identifies cosmetic changes */
#define FBLBM_AP_API_VERSION_RELEASE   0x00u

/***********************************************************************************************************************
*  INCLUDES
**********************************************************************************************************************/

#include "FblBm_Cfg.h"
#include "bm_types.h"
#include "bm_hdr.h"

#include "fbl_inc.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
# define FblRealTimeSupport()     FblLookForWatchdog()
#endif

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLBMAP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

void ApplFblBmPowerOnPre(void);
void ApplFblBmPowerOnPost(void);
void ApplFblBmInitPre(void);
void ApplFblBmInitPost(void);

#if defined( FBLBM_AP_CALLOUT_RESET )
void ApplFblBmReset(void);
#endif /* FBLBM_AP_CALLOUT_RESET */

#if defined( FBLBM_AP_CALLOUT_CHECK_TARGET_VALIDITY )
tFblResult ApplFblBmCheckTargetValidity(tFblBmHdrTargetHandle targetHandle);
#endif /* FBLBM_AP_CALLOUT_CHECK_TARGET_VALIDITY */
#if defined( FBLBM_AP_CALLOUT_IS_VALIDBLOCK )
tFblResult ApplFblBmIsValidBlock(tFblBmHdrTargetHandle targetHandle,
   const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * pLogicalBlock);
#endif /* FBLBM_AP_CALLOUT_IS_VALIDBLOCK */
#if defined( FBLBM_AP_CALLOUT_IS_OPTIONALBLOCK )
void ApplFblBmIsOptionalBlock(tFblBmHdrTargetHandle targetHandle,
   const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * pLogicalBlock);
#endif /* FBLBM_AP_CALLOUT_IS_OPTIONALBLOCK */
#if defined( FBLBM_AP_CALLOUT_START_SOFTWARE )
void ApplFblBmStartSoftware(const V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 V_MEMRAM3 * bmHeader);
#endif /* FBLBM_AP_CALLOUT_START_SOFTWARE* */

#if defined( FBLBM_ENABLE_SECURE_BOOT )
# if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY )
#  if defined( FBLBM_AP_CALLOUT_GET_KEYEMPTY )
tFblBmKeyEmptyResult ApplFblBmGetKeyEmpty( void );
#  endif /* FBLBM_AP_CALLOUT_GET_KEYEMPTY */
# endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY */
# if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
#  if defined( FBLBM_AP_CALLOUT_GET_FBL_CMACERASED )
tFblBmMacEmptyResult ApplFblBmGetFblCmacErased( const tFblBmBlockInfo * fblBlockInfo );
#  endif /* FBLBM_AP_CALLOUT_GET_FBL_CMACERASED */
# endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */
#endif /* FBLBM_ENABLE_SECURE_BOOT */

#if defined( FBLBM_AP_CALLOUT_CHECKREPROGFLAG )
tFblResult ApplFblBmCheckReprogFlag( void );
#endif /* FBLBM_AP_CALLOUT_CHECKREPROGFLAG */

#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
# if defined( FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_INIT )
tFblResult ApplFblBmSearchUpdaterHeaderInit(void);
# endif /* FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_INIT */
# if defined( FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_HEADER_ADDRESS )
tFblResult ApplFblBmSearchUpdaterHeaderAddress(vuint32 * headerAddress);
# endif /* FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_HEADER_ADDRESS */
# if defined( FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_NEXT )
tFblResult ApplFblBmSearchUpdaterHeaderNext(void);
# endif /* FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_NEXT */
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */

#if defined( FBLBM_AP_CALLOUT_FATAL_ERROR )
void ApplFblBmFatalError(tFblBmError error);
#endif /* FBLBM_AP_CALLOUT_FATAL_ERROR */

/*-- Other callout functions -----------------------------------------------------------------------------------------*/

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
# if defined( FBL_ENABLE_ASSERTION )
void ApplFblFatalError( FBL_DECL_ASSERT_EXTENDED_INFO(vuint8 errorCode) );
# endif /* FBL_ENABLE_ASSERTION */
# if defined( FBL_MIO_ENABLE_HOOKS )
void ApplFblPreMemDriver( vuint8 device, vuint8 function );
void ApplFblPostMemDriver( vuint8 device, vuint8 function );
# endif /* FBL_MIO_ENABLE_HOOKS */
#endif /* FBLBM_ENABLE_STANDALONE_MODE */

#define FBLBMAP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* BM_AP_H */

/***********************************************************************************************************************
 *  END OF FILE: BM_AP.H
 **********************************************************************************************************************/
