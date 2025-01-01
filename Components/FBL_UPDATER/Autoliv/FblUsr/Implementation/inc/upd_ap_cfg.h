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
 *                         visshs  ESCAN00101664    No changes
 *  02.01.00   2019-02-07  visrie  ESCAN00102028    No changes
 *  02.01.01   2019-03-22  visrie  ESCAN00102576    No changes
 *  02.01.02   2019-08-12  visrcn  ESCAN00102954    No changes
 *  03.00.00   2020-04-14  visrie  FBL-1016         No changes
 *  03.01.00   2021-03-12  visjdn  FBL-2206         No changes
 *  03.01.01   2021-08-27  visjdn  ESCAN00109619    No changes
 *  03.01.02   2021-10-28  visrie  ESCAN00110007    No changes
 **********************************************************************************************************************/

#ifndef UPD_AP_CFG_H
#define UPD_AP_CFG_H

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/*-- Processing hook functions ---------------------------------------------------------------------------------------*/

/* Enabel hook to overwrite default functionality implemented in main updater component */

/** Initalization hook */
#if !defined( FBL_UPD_HOOK_INIT )
/*# define FBL_UPD_HOOK_INIT                           ApplFblUpdInit*/
#endif /* FBL_UPD_HOOK_INIT */

/** Send pending response (RCR-RP) */
#if !defined( FBL_UPD_HOOK_SEND_RESPONSE )
/*# define FBL_UPD_HOOK_SEND_RESPONSE                  ApplFblUpdSendResponse*/
#endif /* FBL_UPD_HOOK_SEND_RESPONSE */

/** Pre-erase hook (e.g. invalidate FBL for reset-safe operation) */
#if defined( FBLBM_ENABLE_STANDALONE_MODE )
# if !defined( FBL_UPD_HOOK_PREPARE_ERASE )
#  define FBL_UPD_HOOK_PREPARE_ERASE                   ApplFblUpdPrepareErase
# else
#  error Bootmanager is used to handle reset safe operations. Remove hardware specific reset safe mechanism.
# endif /* FBL_UPD_HOOK_PREPARE_ERASE */
#else
# if !defined( FBL_UPD_HOOK_PREPARE_ERASE )
/*# define FBL_UPD_HOOK_PREPARE_ERASE                  ApplFblUpdPrepareErase*/
# endif /* FBL_UPD_HOOK_PREPARE_ERASE */
#endif /* FBLBM_ENABLE_STANDALONE_MODE */

/** Post-erase hook */
#if !defined( FBL_UPD_HOOK_FINALIZE_ERASE )
/*# define FBL_UPD_HOOK_FINALIZE_ERASE                 ApplFblUpdFinalizeErase*/
#endif /* FBL_UPD_HOOK_FINALIZE_ERASE */

/** Pre-programming hook */
#if !defined( FBL_UPD_HOOK_PREPARE_PROGRAM )
/*# define FBL_UPD_HOOK_PREPARE_PROGRAM                ApplFblUpdPrepareProgram*/
#endif /* FBL_UPD_HOOK_PREPARE_PROGRAM */

/** Post-programming hook */
#if !defined( FBL_UPD_HOOK_FINALIZE_PROGRAM )
/*# define FBL_UPD_HOOK_FINALIZE_PROGRAM               ApplFblUpdFinalizeProgram*/
#endif /* FBL_UPD_HOOK_FINALIZE_PROGRAM */

/** Post-verification hook (e.g. validate FBL for reset-safe operation) */
#if defined( FBLBM_ENABLE_STANDALONE_MODE )
# if !defined( FBL_UPD_HOOK_FINALIZE_VERIFY )
#  define FBL_UPD_HOOK_FINALIZE_VERIFY                 ApplFblUpdFinalizeVerify
# else
#  error Bootmanager is used to handle reset safe operations. Remove hardware specific reset safe mechanism.
# endif /* FBL_UPD_HOOK_FINALIZE_VERIFY */
#else
# if !defined( FBL_UPD_HOOK_FINALIZE_VERIFY )
/*# define FBL_UPD_HOOK_FINALIZE_VERIFY                ApplFblUpdFinalizeVerify*/
# endif /* FBL_UPD_HOOK_FINALIZE_VERIFY */
#endif /* FBLBM_ENABLE_STANDALONE_MODE */

/** Updater invalidation hook */
#if !defined( FBL_UPD_HOOK_INVALIDATE_UPDATER )
/*# define FBL_UPD_HOOK_INVALIDATE_UPDATER             ApplFblUpdInvalidateUpdater*/
#endif /* FBL_UPD_HOOK_INVALIDATE_UPDATER */

/** Reset hook */
#if !defined( FBL_UPD_HOOK_RESET )
/*# define FBL_UPD_HOOK_RESET                          ApplFblUpdRemoveAndReset*/
#endif /* FBL_UPD_HOOK_RESET */

/*-- Segment handling hook functions ---------------------------------------------------------------------------------*/

/** Get segment information */
#if !defined( FBL_UPD_HOOK_GET_SEGMENT )
/*# define FBL_UPD_HOOK_GET_SEGMENT                    ApplFblUpdGetSegment*/
#endif /* FBL_UPD_HOOK_GET_SEGMENT */

/** Adjust segment information for programming and verification */
#if !defined( FBL_UPD_HOOK_ADJUST_SEGMENT_PROGRAM )
/*# define FBL_UPD_HOOK_ADJUST_SEGMENT_PROGRAM         ApplFblUpdAdjustSegmentProgram*/
#endif /* FBL_UPD_HOOK_ADJUST_SEGMENT_PROGRAM */

/** Adjust segment information for validity handling */
#if !defined( FBL_UPD_HOOK_ADJUST_SEGMENT_VALIDITY )
/*# define FBL_UPD_HOOK_ADJUST_SEGMENT_VALIDITY        ApplFblUpdAdjustSegmentValidity*/
#endif /* FBL_UPD_HOOK_ADJUST_SEGMENT_VALIDITY */

/*-- Further hook functions -------------------------------------------------------------------------------------------*/

/** Erase hook to check memSegment. Return kFblOk: erase shall happen, kFblFailed: erase shall not happen. Type: tFblResult */
#if !defined( FBL_UPD_HOOK_CHECK_MEMSEGMENT_ERASE )
/*# define FBL_UPD_HOOK_CHECK_MEMSEGMENT_ERASE(inSegment)     kFblOk */
#endif /* FBL_UPD_HOOK_CHECK_MEMSEGMENT_ERASE */

/** Read data from source segment */
#if !defined( FBL_UPD_HOOK_READ_SOURCE_SEGMENT )
/* Memory mapped access not possible as updated bootloader is located in flash
   Use flash driver instead */
/*# define FBL_UPD_HOOK_READ_SOURCE_SEGMENT(address, buffer, length)   ((IO_E_OK == FlashDriver_RReadSync((buffer), (length), (address))) ? kFblOk : kFblFailed)*/
#endif /* FBL_UPD_HOOK_READ_SOURCE_SEGMENT */

/*-- Callout functions -----------------------------------------------------------------------------------------------*/

/* Callout implementation is mandatory, but could be overwritten by OEM- or platform-specific variant */

/** Initialization callout */
#if !defined( FBL_UPD_CALLOUT_INIT_POWER_ON )
# define FBL_UPD_CALLOUT_INIT_POWER_ON                ApplFblUpdInitPowerOn
#endif /* FBL_UPD_CALLOUT_INIT_POWER_ON */

/** OEM specific initialization callout */
#if !defined( FBL_UPD_CALLOUT_INIT_POWER_ON_HW )
# define FBL_UPD_CALLOUT_INIT_POWER_ON_HW()
#endif /* FBL_UPD_CALLOUT_INIT_POWER_ON_HW */

/** Hardware specific initialization callout */
#if !defined( FBL_UPD_CALLOUT_INIT_POWER_ON_OEM )
# define FBL_UPD_CALLOUT_INIT_POWER_ON_OEM()
#endif /* FBL_UPD_CALLOUT_INIT_POWER_ON_OEM */

/** Callout to enable programming voltage */
#if !defined( FBL_UPD_CALLOUT_SET_VFP )
# define FBL_UPD_CALLOUT_SET_VFP                      ApplFblUpdSetVfp
#endif /* FBL_UPD_CALLOUT_SET_VFP */

/** Callout to disable programming voltage */
#if !defined( FBL_UPD_CALLOUT_RESET_VFP )
# define FBL_UPD_CALLOUT_RESET_VFP                    ApplFblUpdResetVfp
#endif /* FBL_UPD_CALLOUT_RESET_VFP */

/** Callout to perform reset */
#if !defined( FBL_UPD_CALLOUT_RESET )
# define FBL_UPD_CALLOUT_RESET                        ApplFblUpdReset
#endif /* FBL_UPD_CALLOUT_RESET */

/** Callout to check if response pending (RCR-RP) message needs to be send */
#if !defined( FBL_UPD_CALLOUT_CHECK_RESPONSE_PENDING )
# define FBL_UPD_CALLOUT_CHECK_RESPONSE_PENDING()     kFblOk
#endif /* FBL_UPD_CALLOUT_CHECK_RESPONSE_PENDING */

/** Callout to activate transceiver */
#if !defined( FBL_UPD_CALLOUT_ACTIVATE_TRANSCEIVER )
# define FBL_UPD_CALLOUT_ACTIVATE_TRANSCEIVER         ApplFblUpdTrcvrNormalMode
#endif /* FBL_UPD_CALLOUT_ACTIVATE_TRANSCEIVER */

/** Callout to prepare buffer with response pending (RCR-RP) message */
#if !defined( FBL_UPD_CALLOUT_PREPARE_RESPONSE_PENDING )
# define FBL_UPD_CALLOUT_PREPARE_RESPONSE_PENDING     ApplFblUpdPrepareResponsePending
#endif /* FBL_UPD_CALLOUT_PREPARE_RESPONSE_PENDING */

/*-- Configuration parameters ----------------------------------------------------------------------------------------*/

/* Validity range must be erased first and programmed last to ensure reset-safe operation */
/** Start of validity range */
#if !defined( FBL_UPD_VALIDITY_RANGE_ADDR )
/*# define FBL_UPD_VALIDITY_RANGE_ADDR       0x00000000ul*/
#endif /*FBL_UPD_VALIDITY_RANGE_ADDR  */
/** Size of validity range */
#if !defined( FBL_UPD_VALIDITY_RANGE_SIZE )
/*# define FBL_UPD_VALIDITY_RANGE_SIZE       8u*/
#endif /* FBL_UPD_VALIDITY_RANGE_SIZE */

#endif /* UPD_AP_CFG_H */

/***********************************************************************************************************************
 *  END OF FILE: UPD_AP_CFG.H
 **********************************************************************************************************************/
