/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Main module of FBL
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
 *  05.00.00   2019-10-10  vistmo  FBL-388          Adapt main function interface for vBaseEnv
 *  05.01.00   2019-11-14  visrcn  FBL-830          No changes
 *  05.01.01   2020-02-27  vistbe  ESCAN00105432    No changes
 *  06.00.00   2020-04-08  visrie  FBL-1016         No changes
 *  06.01.00   2020-04-29  vistmo  FBL-1584         Adding OTA startup support
 *  06.01.01   2020-10-28  visrcn  ESCAN00107190    Compiler error: Wrong definition for FblMain function
 *  06.01.02   2020-11-26  visrcn  ESCAN00107979    No changes
 *  06.02.00   2022-04-08  vishor  FBL-4852         No changes
 *  06.03.00   2022-05-06  vishor  FBL-5148         No changes
 *  06.04.00   2022-07-06  vismix  FBL-5235         No changes
 *  06.05.00   2022-11-30  visrie  FBL-6065         Encapsulate FblMain declaration
 **********************************************************************************************************************/

#ifndef FBL_MAIN_H
#define FBL_MAIN_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_main_types.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblMain CQComponent : Implementation */
#define FBL_MAIN_VERSION           0x0605u
#define FBL_MAIN_RELEASE_VERSION   0x00u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Main state definitions
 **********************************************************************************************************************/
#define kFblMainStateStartFromReset             0u
#define kFblMainStateStartFromAppl              1u
#define kFblMainStateStartFromXcp               2u
#define kFblMainStateStartFromOta               3u
#define kFblMainStateApplicationValid           4u
#define kFblMainStateWaitStartMessage           5u
#define kFblMainStateStartMessageReceived       6u
#define kFblMainStateFblShutdownRequest         7u

#define kFblMainNumberOfStates                  8u

/***********************************************************************************************************************
 *  State handling framework
 **********************************************************************************************************************/
/* PRQA S 3453 3 */ /* MD_MSR_FctLikeMacro */
#define GetFblMainState(state)                  FBL_STATE_TEST(fblMainStates, (state)) /**< Read fbl_main state bit */
#define SetFblMainState(state)                  FBL_STATE_SET(fblMainStates, state)    /**< Set fbl_main state bit */
#define ClrFblMainState(state)                  FBL_STATE_CLR(fblMainStates, state)    /**< Clear fbl_main state bit */

#define FblMainGetStartFromReset()              GetFblMainState( kFblMainStateStartFromReset )
#define FblMainGetStartFromAppl()               GetFblMainState( kFblMainStateStartFromAppl )
#define FblMainGetStartFromXcp()                GetFblMainState( kFblMainStateStartFromXcp )
#define FblMainGetStartFromOta()                GetFblMainState( kFblMainStateStartFromOta )
#define FblMainGetApplicationValid()            GetFblMainState( kFblMainStateApplicationValid )
#define FblMainGetWaitStartMessage()            GetFblMainState( kFblMainStateWaitStartMessage )
#define FblMainGetStartMessageReceived()        GetFblMainState( kFblMainStateStartMessageReceived )
#define FblMainGetFblShutdownRequest()          GetFblMainState( kFblMainStateFblShutdownRequest )

#define FblMainSetFblShutdownRequest()          SetFblMainState( kFblMainStateFblShutdownRequest )
#define FblMainClrFblShutdownRequest()          ClrFblMainState( kFblMainStateFblShutdownRequest )
#define FblSetShutdownRequest()                 FblMainSetFblShutdownRequest()

/***********************************************************************************************************************
 *  Initialization steps
 **********************************************************************************************************************/
#define kFblInitPowerOn                      0x00u /**< Power-on initialization step */
#define kFblInitBaseInitialization           0x01u /**< Init steps before application validity check */
#define kFblInitFblCommunication             0x02u /**< Bootloader initialization first part - mainly communication */
#define kFblInitFblFinalize                  0x03u /**< Finalize Bootloader initialization if application isn't started */

#define kFblInitPreCallback                  0x00u /**< Initialization callback before core init function */
#define kFblInitPostCallback                 0x80u /**< Initialization callback after core init function */

/***********************************************************************************************************************
*  COM WRAPPER COMPATIBILITY DEFINITIONS
**********************************************************************************************************************/

/* Define interface version for classic FblWrapperCom modules */
# if !defined( FBL_CW_API_REFERENCE_VERSION_MAJOR )
/** Major interface version identifies incompatible changes */
#  define FBL_CW_API_REFERENCE_VERSION_MAJOR     0x01u
/** Minor interface version identifies backward compatible changes */
#  define FBL_CW_API_REFERENCE_VERSION_MINOR     0x00u
/** Release interface version identifies cosmetic changes */
#  define FBL_CW_API_REFERENCE_VERSION_RELEASE   0x00u
# endif /* !defined FBL_CW_API_REFERENCE_VERSION_MAJOR */

# if !defined( FBL_CW_CFG_PTR )
#  define FBL_CW_CFG_PTR V_NULL
# endif /* !defined FBL_CW_CFG_PTR */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLMAIN_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

V_MEMRAM0 extern V_MEMRAM1_NEAR tFblStateBitmap V_MEMRAM2_NEAR fblMainStates[FBL_STATE_INDEX(kFblMainNumberOfStates - 1u) + 1u];

# define FBLMAIN_STOP_SEC_VAR
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define FBLHEADER_START_SEC_CONST
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMROM0 extern V_MEMROM1 tFblHeader V_MEMROM2 FblHeader;
# define FBLHEADER_STOP_SEC_CONST
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLMAIN_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if !defined( FBLBM_INSTANCE_BOOTMANAGER )
void V_API_NEAR FblMain( void ); /* PRQA S 5209 */ /* MD_FblMain_5209 */
#endif /* !FBLBM_INSTANCE_BOOTMANAGER */
void V_API_NEAR FblMainInternal( void ); /* PRQA S 5209 */ /* MD_FblMain_5209 */

#define FBLMAIN_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/
/* Check diagnostic task call cycle */
# if defined( kDiagCallCycle )
#  if( kDiagCallCycle != 1u )
#   error "Diagnostic task call cycle has to be configured to 1ms."
#  endif
# endif /* kDiagCallCycle */

#endif /* FBL_MAIN_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_MAIN.H
 **********************************************************************************************************************/
