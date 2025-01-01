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
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Task_Lcfg.c
 *   Generation Time: 2023-07-10 14:36:15
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_TASK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"
#include "Os_Error.h"
#include "Os_Ioc.h"
#include "Os_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Scheduler_Types.h"
#include "Os_Stack_Lcfg.h"
#include "Os_TaskInt.h"
#include "Os_Thread.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"

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

/*! Dynamic task data: ApplBackgroundTask_Core0 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_ApplBackgroundTask_Core0_Dyn;

/*! Dynamic task data: ApplInitTask_Core0 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_ApplInitTask_Core0_Dyn;

/*! Dynamic task data: ApplTask_Core0_HighPrio */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_ApplTask_Core0_HighPrio_Dyn;

/*! Dynamic task data: ApplTask_Core0_LowPrio */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_ApplTask_Core0_LowPrio_Dyn;

/*! Dynamic task data: BackgroundTask_Core0 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_BackgroundTask_Core0_Dyn;

/*! Dynamic task data: BswTask_Core0_HighPrio */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_BswTask_Core0_HighPrio_Dyn;

/*! Dynamic task data: BswTask_Core0_LowPrio */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_BswTask_Core0_LowPrio_Dyn;

/*! Dynamic task data: Default_Init_Task */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Default_Init_Task_Dyn;

/*! Dynamic task data: Default_Init_Task_Trusted */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Default_Init_Task_Trusted_Dyn;

/*! Dynamic task data: IdleTask_OsCore0 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_IdleTask_OsCore0_Dyn;

/*! Dynamic task data: OsTask_ALV_BeltFunctionAlgo */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_ALV_BeltFunctionAlgo_Dyn;

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


/*! Task configuration data: ApplBackgroundTask_Core0 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_ApplBackgroundTask_Core0 =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ApplBackgroundTask_Core0,
    /* .Context               = */ &OsCfg_Hal_Context_ApplBackgroundTask_Core0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio5,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_ApplBackgroundTask_Core0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_ApplBackgroundTask_Core0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)8u,
  /* .TaskId                 = */ ApplBackgroundTask_Core0,
  /* .RunningPriority        = */ (Os_TaskPrioType)8u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: ApplInitTask_Core0 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_ApplInitTask_Core0 =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ApplInitTask_Core0,
    /* .Context               = */ &OsCfg_Hal_Context_ApplInitTask_Core0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio90,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_ApplInitTask_Core0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_ApplInitTask_Core0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)2u,
  /* .TaskId                 = */ ApplInitTask_Core0,
  /* .RunningPriority        = */ (Os_TaskPrioType)0u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: ApplTask_Core0_HighPrio */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_ApplTask_Core0_HighPrio =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ApplTask_Core0_HighPrio,
    /* .Context               = */ &OsCfg_Hal_Context_ApplTask_Core0_HighPrio_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_ApplTask_Core0_HighPrio,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_ApplTask_Core0_HighPrio_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_ApplTask_Core0_HighPrio,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)4u,
  /* .TaskId                 = */ ApplTask_Core0_HighPrio,
  /* .RunningPriority        = */ (Os_TaskPrioType)4u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: ApplTask_Core0_LowPrio */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_ApplTask_Core0_LowPrio =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ApplTask_Core0_LowPrio,
    /* .Context               = */ &OsCfg_Hal_Context_ApplTask_Core0_LowPrio_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_ApplTask_Core0_LowPrio,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_ApplTask_Core0_LowPrio_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_ApplTask_Core0_LowPrio,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)7u,
  /* .TaskId                 = */ ApplTask_Core0_LowPrio,
  /* .RunningPriority        = */ (Os_TaskPrioType)7u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: BackgroundTask_Core0 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_BackgroundTask_Core0 =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_BackgroundTask_Core0,
    /* .Context               = */ &OsCfg_Hal_Context_BackgroundTask_Core0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio0,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_BackgroundTask_Core0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_BackgroundTask_Core0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)9u,
  /* .TaskId                 = */ BackgroundTask_Core0,
  /* .RunningPriority        = */ (Os_TaskPrioType)9u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: BswTask_Core0_HighPrio */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_BswTask_Core0_HighPrio =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_BswTask_Core0_HighPrio,
    /* .Context               = */ &OsCfg_Hal_Context_BswTask_Core0_HighPrio_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_BswTask_Core0_HighPrio,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_BswTask_Core0_HighPrio_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_BswTask_Core0_HighPrio,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)3u,
  /* .TaskId                 = */ BswTask_Core0_HighPrio,
  /* .RunningPriority        = */ (Os_TaskPrioType)0u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: BswTask_Core0_LowPrio */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_BswTask_Core0_LowPrio =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_BswTask_Core0_LowPrio,
    /* .Context               = */ &OsCfg_Hal_Context_BswTask_Core0_LowPrio_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_BswTask_Core0_LowPrio,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_BswTask_Core0_LowPrio_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_BswTask_Core0_LowPrio,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)5u,
  /* .TaskId                 = */ BswTask_Core0_LowPrio,
  /* .RunningPriority        = */ (Os_TaskPrioType)5u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Default_Init_Task */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Default_Init_Task =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Default_Init_Task,
    /* .Context               = */ &OsCfg_Hal_Context_Default_Init_Task_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio100,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Default_Init_Task_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Default_Init_Task,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)0u,
  /* .TaskId                 = */ Default_Init_Task,
  /* .RunningPriority        = */ (Os_TaskPrioType)0u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OSDEFAULTAPPMODE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Default_Init_Task_Trusted */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Default_Init_Task_Trusted =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Default_Init_Task_Trusted,
    /* .Context               = */ &OsCfg_Hal_Context_Default_Init_Task_Trusted_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio99,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Default_Init_Task_Trusted_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Default_Init_Task_Trusted,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)1u,
  /* .TaskId                 = */ Default_Init_Task_Trusted,
  /* .RunningPriority        = */ (Os_TaskPrioType)1u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OSDEFAULTAPPMODE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: IdleTask_OsCore0 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore0 =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_IdleTask_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_IdleTask_OsCore0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio4294967295,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_IdleTask_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_IdleTask_OsCore0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)10u,
  /* .TaskId                 = */ IdleTask_OsCore0,
  /* .RunningPriority        = */ (Os_TaskPrioType)10u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_ANY,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: OsTask_ALV_BeltFunctionAlgo */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_ALV_BeltFunctionAlgo =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_ALV_BeltFunctionAlgo,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_ALV_BeltFunctionAlgo_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsTask_ALV_BeltFunctionAlgo,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_ALV_BeltFunctionAlgo_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_OsTask_ALV_BeltFunctionAlgo,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)6u,
  /* .TaskId                 = */ OsTask_ALV_BeltFunctionAlgo,
  /* .RunningPriority        = */ (Os_TaskPrioType)6u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for tasks. */
CONSTP2CONST(Os_TaskConfigType, OS_CONST, OS_CONST) OsCfg_TaskRefs[OS_TASKID_COUNT + 1] =   /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_ApplBackgroundTask_Core0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_ApplInitTask_Core0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_ApplTask_Core0_HighPrio),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_ApplTask_Core0_LowPrio),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_BackgroundTask_Core0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_BswTask_Core0_HighPrio),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_BswTask_Core0_LowPrio),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task_Trusted),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_ALV_BeltFunctionAlgo),
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
 *  END OF FILE: Os_Task_Lcfg.c
 *********************************************************************************************************************/
