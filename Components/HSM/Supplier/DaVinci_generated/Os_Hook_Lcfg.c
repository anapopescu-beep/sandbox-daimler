/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hook_Lcfg.c
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HOOK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"
#include "Os_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "OsInt.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic hook data: Os_CoreInitHook_OsCore0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_Os_CoreInitHook_OsCore0_Dyn;

/*! Dynamic hook data: StartupHook_OsCore0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_StartupHook_OsCore0_Dyn;

/*! Dynamic hook data: ShutdownHook_OsCore0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_ShutdownHook_OsCore0_Dyn;

/*! Dynamic hook data: ErrorHook_OsCore0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_ErrorHook_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Hook configuration data: Os_CoreInitHook_OsCore0 */
CONST(Os_HookInitHookConfigType, OS_CONST) OsCfg_Hook_Os_CoreInitHook_OsCore0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Os_CoreInitHook_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Init,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_Os_CoreInitHook_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_INITHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_INITHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_INITHOOK,
    /* .Id           = */ (Os_HookIdType)0,
    /* .TaskReturn   = */ Os_HookTaskReturn_BeginScheduling
  },
  /* .Callback = */ &Os_CoreInitHook
};

/*! Hook configuration data: StartupHook_OsCore0 */
CONST(Os_HookCallbackConfigType, OS_CONST) OsCfg_Hook_StartupHook_OsCore0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_StartupHook_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_StartupHook_OsCore0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Startup,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_StartupHook_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_STARTUPHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_STARTUPHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_STARTUPHOOK,
    /* .Id           = */ (Os_HookIdType)1,
    /* .TaskReturn   = */ Os_HookTaskReturn_ToCallerTask
  },
  /* .Callback = */ &StartupHook
};

/*! Hook configuration data: ShutdownHook_OsCore0 */
CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ShutdownHook_OsCore0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ShutdownHook_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_ShutdownHook_OsCore0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Shutdown,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_ShutdownHook_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_SHUTDOWNHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_SHUTDOWNHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_SHUTDOWNHOOK,
    /* .Id           = */ (Os_HookIdType)2,
    /* .TaskReturn   = */ Os_HookTaskReturn_ToCallerTask
  },
  /* .Callback = */ &ShutdownHook
};

/*! Hook configuration data: ErrorHook_OsCore0 */
CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ErrorHook_OsCore0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ErrorHook_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Error,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_ErrorHook_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ERRORHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_ERRORHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_ERRORHOOK,
    /* .Id           = */ (Os_HookIdType)3,
    /* .TaskReturn   = */ Os_HookTaskReturn_WithSchedule
  },
  /* .Callback = */ &ErrorHook
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for hook callbacks. */
CONSTP2CONST(Os_HookConfigType, OS_CONST, OS_CONST) OsCfg_HookRefs[OS_CFG_NUM_HOOKS + 1u] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore0),
  OS_HOOK_CASTCONFIG_CALLBACK_2_HOOK(OsCfg_Hook_StartupHook_OsCore0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ShutdownHook_OsCore0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ErrorHook_OsCore0),
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Hook_Lcfg.c
 *********************************************************************************************************************/
