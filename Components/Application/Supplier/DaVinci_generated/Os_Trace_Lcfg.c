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
 *              File: Os_Trace_Lcfg.c
 *   Generation Time: 2023-10-05 14:21:24
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_TRACE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Trace_Lcfg.h"
#include "Os_Trace.h"

/* Os kernel module dependencies */
#include "Os_Common_Types.h"

/* Os hal dependencies */


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

#define OS_START_SEC_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic trace data: OsCore0 */
VAR(Os_TraceCoreType, OS_VAR_NOINIT) OsCfg_Trace_OsCore0_Dyn;

/*! Dynamic trace data: ApplBackgroundTask_Core0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_ApplBackgroundTask_Core0_Dyn;

/*! Dynamic trace data: ApplInitTask_Core0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_ApplInitTask_Core0_Dyn;

/*! Dynamic trace data: ApplTask_Core0_HighPrio */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_ApplTask_Core0_HighPrio_Dyn;

/*! Dynamic trace data: ApplTask_Core0_LowPrio */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_ApplTask_Core0_LowPrio_Dyn;

/*! Dynamic trace data: BackgroundTask_Core0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_BackgroundTask_Core0_Dyn;

/*! Dynamic trace data: BswTask_Core0_HighPrio */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_BswTask_Core0_HighPrio_Dyn;

/*! Dynamic trace data: BswTask_Core0_LowPrio */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_BswTask_Core0_LowPrio_Dyn;

/*! Dynamic trace data: Default_Init_Task */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Default_Init_Task_Dyn;

/*! Dynamic trace data: Default_Init_Task_Trusted */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_Default_Init_Task_Trusted_Dyn;

/*! Dynamic trace data: IdleTask_OsCore0 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_IdleTask_OsCore0_Dyn;

/*! Dynamic trace data: OsTask_ALV_BeltFunctionAlgo */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_OsTask_ALV_BeltFunctionAlgo_Dyn;

/*! Dynamic trace data: CanIsr_1 */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_CanIsr_1_Dyn;

/*! Dynamic trace data: CounterIsr_SystemTimer */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_CounterIsr_SystemTimer_Dyn;

/*! Dynamic trace data: RCM_PFlashEccFailure_Notification */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_RCM_PFlashEccFailure_Notification_Dyn;

/*! Dynamic trace data: RCM_SRamEccFailure_Notification */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_RCM_SRamEccFailure_Notification_Dyn;

/*! Dynamic trace data: vHsmResponseIsr */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_vHsmResponseIsr_Dyn;

/*! Dynamic trace data: OsCore0_Hooks */
OS_LOCAL VAR(Os_TraceThreadType, OS_VAR_NOINIT) OsCfg_Trace_OsCore0_Hooks_Dyn;

#define OS_STOP_SEC_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Trace configuration data: OsApplication_Trusted_Core0 */
CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_OsApplication_Trusted_Core0 =
{
  /* .Id   = */ Os_TraceId_OsApplication_Trusted_Core0
};

/*! Trace configuration data: SystemApplication_OsCore0 */
CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_SystemApplication_OsCore0 =
{
  /* .Id   = */ Os_TraceId_SystemApplication_OsCore0
};

/*! Trace configuration data: ApplBackgroundTask_Core0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_ApplBackgroundTask_Core0 =
{
  /* .Dyn  = */ &OsCfg_Trace_ApplBackgroundTask_Core0_Dyn,
  /* .Id   = */ Os_TraceId_ApplBackgroundTask_Core0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: ApplInitTask_Core0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_ApplInitTask_Core0 =
{
  /* .Dyn  = */ &OsCfg_Trace_ApplInitTask_Core0_Dyn,
  /* .Id   = */ Os_TraceId_ApplInitTask_Core0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: ApplTask_Core0_HighPrio */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_ApplTask_Core0_HighPrio =
{
  /* .Dyn  = */ &OsCfg_Trace_ApplTask_Core0_HighPrio_Dyn,
  /* .Id   = */ Os_TraceId_ApplTask_Core0_HighPrio,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: ApplTask_Core0_LowPrio */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_ApplTask_Core0_LowPrio =
{
  /* .Dyn  = */ &OsCfg_Trace_ApplTask_Core0_LowPrio_Dyn,
  /* .Id   = */ Os_TraceId_ApplTask_Core0_LowPrio,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: BackgroundTask_Core0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_BackgroundTask_Core0 =
{
  /* .Dyn  = */ &OsCfg_Trace_BackgroundTask_Core0_Dyn,
  /* .Id   = */ Os_TraceId_BackgroundTask_Core0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: BswTask_Core0_HighPrio */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_BswTask_Core0_HighPrio =
{
  /* .Dyn  = */ &OsCfg_Trace_BswTask_Core0_HighPrio_Dyn,
  /* .Id   = */ Os_TraceId_BswTask_Core0_HighPrio,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: BswTask_Core0_LowPrio */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_BswTask_Core0_LowPrio =
{
  /* .Dyn  = */ &OsCfg_Trace_BswTask_Core0_LowPrio_Dyn,
  /* .Id   = */ Os_TraceId_BswTask_Core0_LowPrio,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Default_Init_Task */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Default_Init_Task =
{
  /* .Dyn  = */ &OsCfg_Trace_Default_Init_Task_Dyn,
  /* .Id   = */ Os_TraceId_Default_Init_Task,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: Default_Init_Task_Trusted */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Default_Init_Task_Trusted =
{
  /* .Dyn  = */ &OsCfg_Trace_Default_Init_Task_Trusted_Dyn,
  /* .Id   = */ Os_TraceId_Default_Init_Task_Trusted,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: IdleTask_OsCore0 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_IdleTask_OsCore0 =
{
  /* .Dyn  = */ &OsCfg_Trace_IdleTask_OsCore0_Dyn,
  /* .Id   = */ Os_TraceId_IdleTask_OsCore0,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: OsTask_ALV_BeltFunctionAlgo */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsTask_ALV_BeltFunctionAlgo =
{
  /* .Dyn  = */ &OsCfg_Trace_OsTask_ALV_BeltFunctionAlgo_Dyn,
  /* .Id   = */ Os_TraceId_OsTask_ALV_BeltFunctionAlgo,
  /* .Type = */ OS_TRACE_THREAD_TYPE_TASK
};

/*! Trace configuration data: CanIsr_1 */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CanIsr_1 =
{
  /* .Dyn  = */ &OsCfg_Trace_CanIsr_1_Dyn,
  /* .Id   = */ Os_TraceId_CanIsr_1,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: CounterIsr_SystemTimer */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CounterIsr_SystemTimer =
{
  /* .Dyn  = */ &OsCfg_Trace_CounterIsr_SystemTimer_Dyn,
  /* .Id   = */ Os_TraceId_CounterIsr_SystemTimer,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: RCM_PFlashEccFailure_Notification */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_RCM_PFlashEccFailure_Notification =
{
  /* .Dyn  = */ &OsCfg_Trace_RCM_PFlashEccFailure_Notification_Dyn,
  /* .Id   = */ Os_TraceId_RCM_PFlashEccFailure_Notification,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: RCM_SRamEccFailure_Notification */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_RCM_SRamEccFailure_Notification =
{
  /* .Dyn  = */ &OsCfg_Trace_RCM_SRamEccFailure_Notification_Dyn,
  /* .Id   = */ Os_TraceId_RCM_SRamEccFailure_Notification,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: vHsmResponseIsr */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_vHsmResponseIsr =
{
  /* .Dyn  = */ &OsCfg_Trace_vHsmResponseIsr_Dyn,
  /* .Id   = */ Os_TraceId_vHsmResponseIsr,
  /* .Type = */ OS_TRACE_THREAD_TYPE_ISR
};

/*! Trace configuration data: OsCore0_Hooks */
CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsCore0_Hooks =
{
  /* .Dyn  = */ &OsCfg_Trace_OsCore0_Hooks_Dyn,
  /* .Id   = */ Os_TraceId_OsCore0_Hooks,
  /* .Type = */ OS_TRACE_THREAD_TYPE_MISC
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
 *  END OF FILE: Os_Trace_Lcfg.c
 *********************************************************************************************************************/
