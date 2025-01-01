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
 *              File: Os_Application_Lcfg.c
 *   Generation Time: 2024-02-15 10:45:17
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_APPLICATION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Application_Cfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Application.h"

/* Os kernel module dependencies */
#include "Os_Alarm_Lcfg.h"
#include "Os_Alarm.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_ScheduleTable_Lcfg.h"
#include "Os_ScheduleTable.h"
#include "Os_ServiceFunction_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Timer.h"

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

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic application data: OsApplication_Trusted_Core0 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_OsApplication_Trusted_Core0_Dyn;

/*! Dynamic application data: SystemApplication_OsCore0 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore0_Dyn;

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

/*! Object reference table for application alarms: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_AlarmRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_AdcIf_AdcIf_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_1000ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_1ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_250ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_2ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_BFE_BFE_runExecuteStandardSteps),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_BaseFunction_BaseFunction_Main),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_DIA_DIA_cyclicProcessingTask),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_DiagFunction_DiagFunction_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms),
  NULL_PTR
};

/*! Object reference table for application counters: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_CounterRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_COUNTERS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application hooks: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_HookRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_IsrRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_vHsmResponseIsr),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_Cat1IsrRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_CAT1ISRS + 1u] =
{
  (Os_IsrCat1ConfigRefType) &OsCfg_Cat1Isr_OS_ISR_BMM_HES_IT,
  (Os_IsrCat1ConfigRefType) &OsCfg_Cat1Isr_OS_ISR_BMM_HES_TOUT,
  NULL_PTR
};

/*! Object reference table for application schedule tables: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_SchTRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_TaskRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_TASKS + 1u] =
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
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_ALV_BeltFunctionAlgo),
  NULL_PTR
};

/*! Object reference table for application trusted functions: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_ServiceRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: OsApplication_Trusted_Core0 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0 =
{
  /* .Dyn                  = */ &OsCfg_App_OsApplication_Trusted_Core0_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId        = */ OS_APPID2MASK(OsApplication_Trusted_Core0),
  /* .TaskRefs             = */ OsCfg_App_OsApplication_Trusted_Core0_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_OsApplication_Trusted_Core0_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_OsApplication_Trusted_Core0_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_OsApplication_Trusted_Core0_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_OsApplication_Trusted_Core0_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_OsApplication_Trusted_Core0_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_OsApplication_Trusted_Core0_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_OsApplication_Trusted_Core0_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_HOOKS,
  /* .TraceAppl            = */ &OsCfg_Trace_OsApplication_Trusted_Core0,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ OsApplication_Trusted_Core0
};

/*! Object reference table for application alarms: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SBC_SBC_MainFunction),
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_1),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_RCM_PFlashEccFailure_Notification),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_RCM_SRamEccFailure_Notification),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore0),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore0 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore0 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore0_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId        = */ OS_APPID2MASK(SystemApplication_OsCore0),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore0_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore0_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore0_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore0_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore0_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore0_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore0_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS,
  /* .TraceAppl            = */ &OsCfg_Trace_SystemApplication_OsCore0,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore0
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for applications. */
CONSTP2CONST(Os_AppConfigType, OS_CONST, OS_CONST) OsCfg_AppRefs[OS_APPID_COUNT + 1] =   /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  &OsCfg_App_OsApplication_Trusted_Core0,
  &OsCfg_App_SystemApplication_OsCore0,
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
 *  END OF FILE: Os_Application_Lcfg.c
 *********************************************************************************************************************/
