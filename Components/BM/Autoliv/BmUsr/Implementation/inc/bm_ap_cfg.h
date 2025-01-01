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
 *                                 ESCAN00103026    No changes
 *  03.00.00   2019-07-17  visrie  ESCAN00103750    Removed target order list configuration
 *  03.01.00   2019-08-14  visrie  FBL-487          Exclude callouts if overwritten by OEM/HW layer
 *  03.01.01   2019-09-04  visrcn  ESCAN00103607    No changes
 *  04.00.00   2019-12-04  visrie  FBL-456          No changes
 *                                 ESCAN00105135    No changes
 *  04.01.00   2020-01-16  visrie  FBL-524          No changes
 *  05.00.00   2020-04-09  visrie  FBL-1016         No changes
 *  05.01.00   2020-04-29  vistmo  FBL-1584         No changes
 *  05.02.00   2020-08-13  vistmo  FBL-1489         No changes
 *  05.02.01   2021-03-17  vishor  ESCAN00108386    No changes
 *                                 FBL-3018         No changes
 *  05.03.00   2021-08-11  visrie  FBL-3394         Move default implementation of CheckReprogFlag into FblBm_Ap
 *  05.04.00   2021-09-17  visjdn  FBL-3865         No changes
 *  05.04.01   2022-04-06  vismix  FBL-4773         No changes
 *  05.05.00   2022-04-07  vishor  FBL-4822         No changes
 *  05.05.01   2022-06-23  vismix  ESCAN00111879    No changes
 *  05.06.00   2022-07-13  vismix  FBL-5391         Add callout for missing optional dependency
 *  05.06.01   2022-11-29  vishor  ESCAN00112986    No changes
 **********************************************************************************************************************/

#ifndef BM_AP_CFG_H
#define BM_AP_CFG_H

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/*-- Processing hook functions ---------------------------------------------------------------------------------------*/

/*-- Callout functions -----------------------------------------------------------------------------------------------*/

/* Callout implementation is mandatory, but could be overwritten by OEM- or platform-specific variant */

/** HW specific initialization callout */
#if !defined( FBLBM_CALLOUT_POWER_ON_PRE_HW)
# define FBLBM_CALLOUT_POWER_ON_PRE_HW()
#endif /* FBLBM_CALLOUT_POWER_ON_PRE_HW */

/** OEM specific initialization callout */
#if !defined( FBLBM_CALLOUT_POWER_ON_PRE_OEM )
# define FBLBM_CALLOUT_POWER_ON_PRE_OEM()
#endif /* FBLBM_CALLOUT_POWER_ON_PRE_OEM */

/** Initialization callout */
#if !defined( FBLBM_CALLOUT_POWER_ON_PRE )
# define FBLBM_CALLOUT_POWER_ON_PRE                            ApplFblBmPowerOnPre
#endif /* FBLBM_CALLOUT_POWER_ON_PRE */

/** HW specific initialization callout */
#if !defined( FBLBM_CALLOUT_POWER_ON_POST_HW )
# define FBLBM_CALLOUT_POWER_ON_POST_HW()
#endif /* FBLBM_CALLOUT_POWER_ON_POST_HW */

/** OEM specific initialization callout */
#if !defined( FBLBM_CALLOUT_POWER_ON_POST_OEM )
# define FBLBM_CALLOUT_POWER_ON_POST_OEM()
#endif /* FBLBM_CALLOUT_POWER_ON_POST_OEM */

/** Initialization callout */
#if !defined( FBLBM_CALLOUT_POWER_ON_POST )
# define FBLBM_CALLOUT_POWER_ON_POST                           ApplFblBmPowerOnPost
#endif /* FBLBM_CALLOUT_POWER_ON_POST */

/** HW specific initialization callout */
#if !defined( FBLBM_CALLOUT_INIT_PRE_HW )
# define FBLBM_CALLOUT_INIT_PRE_HW()
#endif /* FBLBM_CALLOUT_INIT_PRE_HW */

/** OEM specific initialization callout */
#if !defined( FBLBM_CALLOUT_INIT_PRE_OEM )
# define FBLBM_CALLOUT_INIT_PRE_OEM()
#endif /* FBLBM_CALLOUT_INIT_PRE_OEM */

/** Initialization callout */
#if !defined( FBLBM_CALLOUT_INIT_PRE )
# define FBLBM_CALLOUT_INIT_PRE                                ApplFblBmInitPre
#endif /* FBLBM_CALLOUT_INIT_PRE */

/** HW specific initialization callout */
#if !defined( FBLBM_CALLOUT_INIT_POST_HW )
# define FBLBM_CALLOUT_INIT_POST_HW()
#endif /* FBLBM_CALLOUT_INIT_POST_HW */

/** OEM specific initialization callout */
#if !defined( FBLBM_CALLOUT_INIT_POST_OEM )
# define FBLBM_CALLOUT_INIT_POST_OEM()
#endif /* FBLBM_CALLOUT_INIT_POST_OEM */

/** Initialization callout */
#if !defined( FBLBM_CALLOUT_INIT_POST )
# define FBLBM_CALLOUT_INIT_POST                               ApplFblBmInitPost
#endif /* FBLBM_CALLOUT_INIT_POST */

/** HW specific deinitialization callout */
#if !defined( FBLBM_CALLOUT_DEINIT_PRE_HW )
# define FBLBM_CALLOUT_DEINIT_PRE_HW()
#endif /* FBLBM_CALLOUT_DEINIT_PRE_HW */

/** OEM specific deinitialization callout */
#if !defined( FBLBM_CALLOUT_DEINIT_PRE_OEM )
# define FBLBM_CALLOUT_DEINIT_PRE_OEM()
#endif /* FBLBM_CALLOUT_DEINIT_PRE_OEM */

/** Denitialization callout */
#if !defined( FBLBM_CALLOUT_DEINIT_PRE )
# define FBLBM_CALLOUT_DEINIT_PRE()
#endif /* FBLBM_CALLOUT_DEINIT_PRE */

/** HW specific deinitialization callout */
#if !defined( FBLBM_CALLOUT_DEINIT_POST_HW )
# define FBLBM_CALLOUT_DEINIT_POST_HW()
#endif /* FBLBM_CALLOUT_DEINIT_HW */

/** OEM specific deinitialization callout */
#if !defined( FBLBM_CALLOUT_DEINIT_POST_OEM )
# define FBLBM_CALLOUT_DEINIT_POST_OEM()
#endif /* FBLBM_CALLOUT_DEINIT_POST_OEM */

/** Denitialization callout */
#if !defined( FBLBM_CALLOUT_DEINIT_POST )
# define FBLBM_CALLOUT_DEINIT_POST()
#endif /* FBLBM_CALLOUT_DEINIT_POST */

/** Callout to perform reset */
#if !defined( FBLBM_CALLOUT_RESET )
# define FBLBM_CALLOUT_RESET                                   ApplFblBmReset
# define FBLBM_AP_CALLOUT_RESET
#endif /* FBLBM_CALLOUT_RESET */

/** Check appl validity callout */
#if !defined( FBLBM_CALLOUT_CHECK_TARGET_VALIDITY )
# define FBLBM_CALLOUT_CHECK_TARGET_VALIDITY                   ApplFblBmCheckTargetValidity
# define FBLBM_AP_CALLOUT_CHECK_TARGET_VALIDITY
#endif /* FBLBM_CALLOUT_CHECK_TARGET_VALIDITY */

/** Checks if the block is valid callout */
#if !defined( FBLBM_CALLOUT_IS_VALIDBLOCK )
# define FBLBM_CALLOUT_IS_VALIDBLOCK                           ApplFblBmIsValidBlock
# define FBLBM_AP_CALLOUT_IS_VALIDBLOCK
#endif /* FBLBM_CALLOUT_IS_VALIDBLOCK */

/** Callout when the block is optional */
#if !defined( FBLBM_CALLOUT_IS_OPTIONALBLOCK )
# define FBLBM_CALLOUT_IS_OPTIONALBLOCK                        ApplFblBmIsOptionalBlock
# define FBLBM_AP_CALLOUT_IS_OPTIONALBLOCK
#endif /* FBLBM_CALLOUT_IS_OPTIONALBLOCK */

/** Start the Application */
#if !defined( FBLBM_CALLOUT_CALL_TARGET )
# define FBLBM_CALLOUT_CALL_TARGET                             ApplFblBmStartSoftware
# if !defined( FBLBM_AP_CALLOUT_START_SOFTWARE )
#  define FBLBM_AP_CALLOUT_START_SOFTWARE
# endif /* FBLBM_AP_CALLOUT_START_SOFTWARE */
#endif /* FBLBM_CALLOUT_CALL_TARGET */

/** Start the FBL */
#if !defined( FBLBM_CALLOUT_CALL_FBL )
# define FBLBM_CALLOUT_CALL_FBL                                ApplFblBmStartSoftware
# if !defined( FBLBM_AP_CALLOUT_START_SOFTWARE )
#  define FBLBM_AP_CALLOUT_START_SOFTWARE
# endif /* FBLBM_AP_CALLOUT_START_SOFTWARE */
#endif /* FBLBM_CALLOUT_CALL_FBL */

/** Start the FBL to initialize the Key */
#if !defined( FBLBM_CALLOUT_CALL_FBL_INIT_KEYS )
# define FBLBM_CALLOUT_CALL_FBL_INIT_KEYS                      ApplFblBmStartSoftware
# if !defined( FBLBM_AP_CALLOUT_START_SOFTWARE )
#  define FBLBM_AP_CALLOUT_START_SOFTWARE
# endif /* FBLBM_AP_CALLOUT_START_SOFTWARE */
#endif /* FBLBM_CALLOUT_CALL_FBL_INIT_KEYS */

/** Start the FBL to initialize its CMAC */
#if !defined( FBLBM_CALLOUT_CALL_FBL_INIT_CMAC )
# define FBLBM_CALLOUT_CALL_FBL_INIT_CMAC                      ApplFblBmStartSoftware
# if !defined( FBLBM_AP_CALLOUT_START_SOFTWARE )
#  define FBLBM_AP_CALLOUT_START_SOFTWARE
# endif /* FBLBM_AP_CALLOUT_START_SOFTWARE */
#endif /* FBLBM_CALLOUT_CALL_FBL_INIT_CMAC */

/** Start the Updater */
#if !defined( FBLBM_CALLOUT_CALL_FAILSAFE_UPDATER )
# define FBLBM_CALLOUT_CALL_FAILSAFE_UPDATER                   ApplFblBmStartSoftware
# if !defined( FBLBM_AP_CALLOUT_START_SOFTWARE )
#  define FBLBM_AP_CALLOUT_START_SOFTWARE
# endif /* FBLBM_AP_CALLOUT_START_SOFTWARE */
#endif /* FBLBM_CALLOUT_CALL_FAILSAFE_UPDATER */

/** Get information if Key is available for MAC verification */
#if !defined( FBLBM_CALLOUT_GET_KEYEMPTY )
# define FBLBM_CALLOUT_GET_KEYEMPTY                            ApplFblBmGetKeyEmpty
# define FBLBM_AP_CALLOUT_GET_KEYEMPTY
#endif /* FBLBM_CALLOUT_GET_KEYEMPTY */

/** Check if FBL MAC is available */
#if !defined( FBLBM_CALLOUT_GET_FBL_CMACERASED )
# define FBLBM_CALLOUT_GET_FBL_CMACERASED                      ApplFblBmGetFblCmacErased
# define FBLBM_AP_CALLOUT_GET_FBL_CMACERASED
#endif /* FBLBM_CALLOUT_GET_FBL_CMACERASED */

/** Check if the programming request flag is set */
#if !defined( FBLBM_CALLOUT_CHECKREPROGFLAG )
# define FBLBM_CALLOUT_CHECKREPROGFLAG                         ApplFblBmCheckReprogFlag
# define FBLBM_AP_CALLOUT_CHECKREPROGFLAG
#endif /* FBLBM_CALLOUT_CHECKREPROGFLAG */

/** Failsafe Updater */
#if !defined( FBLBM_CALLOUT_SEARCH_FAILSAFE_UPDATER_INIT )
#define FBLBM_CALLOUT_SEARCH_FAILSAFE_UPDATER_INIT             ApplFblBmSearchUpdaterHeaderInit
# define FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_INIT
#endif /* FBLBM_CALLOUT_SEARCH_FAILSAFE_UPDATER_INIT */

/** Failsafe Updater */
#if !defined( FBLBM_CALLOUT_SEARCH_FAILSAFE_UPDATER_HEADER_ADDRESS )
#define FBLBM_CALLOUT_SEARCH_FAILSAFE_UPDATER_HEADER_ADDRESS   ApplFblBmSearchUpdaterHeaderAddress
# define FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_HEADER_ADDRESS
#endif /* FBLBM_CALLOUT_SEARCH_FAILSAFE_UPDATER_HEADER_ADDRESS */

/** Failsafe Updater */
#if !defined( FBLBM_CALLOUT_SEARCH_FAILSAFE_UPDATER_NEXT )
#define FBLBM_CALLOUT_SEARCH_FAILSAFE_UPDATER_NEXT             ApplFblBmSearchUpdaterHeaderNext
# define FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_NEXT
#endif /* FBLBM_CALLOUT_SEARCH_FAILSAFE_UPDATER_NEXT */

/** Fatal error callout */
#if !defined( FBLBM_CALLOUT_FATAL_ERROR )
# define FBLBM_CALLOUT_FATAL_ERROR                             ApplFblBmFatalError
# define FBLBM_AP_CALLOUT_FATAL_ERROR
#endif /* FBLBM_CALLOUT_FATAL_ERROR */

#endif /* BM_AP_CFG_H */

/***********************************************************************************************************************
 *  END OF FILE: BM_AP_CFG.H
 **********************************************************************************************************************/
