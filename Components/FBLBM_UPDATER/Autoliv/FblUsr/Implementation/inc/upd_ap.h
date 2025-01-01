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
 *  02.01.01   2019-03-22  visrie  ESCAN00102576    Fixed FblRealTimeSupport redefinition
 *  02.01.02   2019-08-12  visrcn  ESCAN00102954    No changes
 *  03.00.00   2020-04-14  visrie  FBL-1016         No changes
 *  03.01.00   2021-03-12  visjdn  FBL-2206         No changes
 *  03.01.01   2021-08-27  visjdn  ESCAN00109619    No changes
 *  03.01.02   2021-10-28  visrie  ESCAN00110007    No changes
 **********************************************************************************************************************/

#ifndef UPD_AP_H
#define UPD_AP_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblUpd_Ap CQComponent : Implementation */
#define FBLUPD_AP_VERSION              0x0301u
#define FBLUPD_AP_RELEASE_VERSION      0x02u

/* Interface version */
/** Major interface version identifies incompatible changes */
#define FBL_UPD_AP_API_VERSION_MAJOR      0x01u
/** Minor interface version identifies backward compatible changes */
#define FBL_UPD_AP_API_VERSION_MINOR      0x02u
/** Release interface version identifies cosmetic changes */
#define FBL_UPD_AP_API_VERSION_RELEASE    0x00u

/***********************************************************************************************************************
*  INCLUDES
**********************************************************************************************************************/

#include "upd_types.h"
#include "upd_cfg.h"
#include "upd_hw_ap.h"
#include "upd_oem_ap.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Remove comment in case FblRealTimeSupport is not defined */
/* #define FblRealTimeSupport()     FblLookForWatchdog() */


/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/*-- Processing hook functions ---------------------------------------------------------------------------------------*/

void ApplFblUpdInitPowerOn( void );
void ApplFblUpdSetVfp( void );
void ApplFblUpdResetVfp( void );
void ApplFblUpdReset( void );
void ApplFblUpdTrcvrNormalMode( void );

/*-- Segment handling hook functions ---------------------------------------------------------------------------------*/

tFblResult ApplFblUpdGetSegment( vuintx index, V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegment );
tFblResult ApplFblUpdAdjustSegmentProgram( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount );
tFblResult ApplFblUpdAdjustSegmentValidity( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount );

/*-- Updater callout functions ---------------------------------------------------------------------------------------*/

tFblResult ApplFblUpdInit( void );
tFblResult ApplFblUpdSendResponse( void );
tFblResult ApplFblUpdPrepareErase( void );
tFblResult ApplFblUpdFinalizeErase( void );
tFblResult ApplFblUpdPrepareProgram( void );
tFblResult ApplFblUpdFinalizeProgram( void );
tFblResult ApplFblUpdFinalizeVerify( void );
tFblResult ApplFblUpdInvalidateUpdater( void );

#define FBL_UPD_AP_RAMCODE_START_SEC_CODE
#include "MemMap.h"
tFblResult ApplFblUpdRemoveAndReset( void );
#define FBL_UPD_AP_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"

void ApplFblUpdPrepareResponsePending( V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pResponse );

/*-- Other callout functions -----------------------------------------------------------------------------------------*/

void ApplFblUpdSwapMetadata( void );
void ApplTrcvrNormalMode( void );
void ApplFblCanBusOff( void );
#if defined( FBL_ENABLE_ASSERTION )
void ApplFblFatalError( FBL_DECL_ASSERT_EXTENDED_INFO(vuint8 errorCode) );
#endif /* FBL_ENABLE_ASSERTION */

# if defined( FBLCW_MODULE_COMM )
#  if ( FBLCW_MODULE_COMM == STD_ON )
#   define FBL_UPD_AP_RAMCODE_START_SEC_CODE
#   include "MemMap.h"
FUNC(void, FBLCW_CODE) ApplFbl_ComM_SilentComModeEntered( NetworkHandleType channel );
FUNC(void, FBLCW_CODE) ApplFbl_ComM_NoComModeEntered( NetworkHandleType channel );
FUNC(void, FBLCW_CODE) ApplFbl_ComM_FullComModeEntered( NetworkHandleType channel );
#   define FBL_UPD_AP_RAMCODE_STOP_SEC_CODE
#   include "MemMap.h"
#  endif /* FBLCW_MODULE_COMM == STD_ON */
# endif /* FBLCW_MODULE_COMM */

#endif /* UPD_AP_H */

/***********************************************************************************************************************
 *  END OF FILE: UPD_AP.H
 **********************************************************************************************************************/
