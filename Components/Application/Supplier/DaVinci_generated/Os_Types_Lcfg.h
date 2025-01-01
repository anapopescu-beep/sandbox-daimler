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
 *              File: Os_Types_Lcfg.h
 *   Generation Time: 2024-02-15 10:45:19
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_TYPES_LCFG_H
# define OS_TYPES_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* OS-Application identifiers. */
#define OsApplication_Trusted_Core0 OsApplication_Trusted_Core0
#define SystemApplication_OsCore0 SystemApplication_OsCore0

/* Trusted function identifiers. */

/* Non-trusted function identifiers. */

/* Fast trusted function identifiers. */

/* Task identifiers. */
#define ApplBackgroundTask_Core0 ApplBackgroundTask_Core0
#define ApplInitTask_Core0 ApplInitTask_Core0
#define ApplTask_Core0_HighPrio ApplTask_Core0_HighPrio
#define ApplTask_Core0_LowPrio ApplTask_Core0_LowPrio
#define BackgroundTask_Core0 BackgroundTask_Core0
#define BswTask_Core0_HighPrio BswTask_Core0_HighPrio
#define BswTask_Core0_LowPrio BswTask_Core0_LowPrio
#define Default_Init_Task Default_Init_Task
#define Default_Init_Task_Trusted Default_Init_Task_Trusted
#define IdleTask_OsCore0 IdleTask_OsCore0
#define OsTask_ALV_BeltFunctionAlgo OsTask_ALV_BeltFunctionAlgo

/* Category 2 ISR identifiers. */
#define CanIsr_1 CanIsr_1
#define CounterIsr_SystemTimer CounterIsr_SystemTimer
#define RCM_PFlashEccFailure_Notification RCM_PFlashEccFailure_Notification
#define RCM_SRamEccFailure_Notification RCM_SRamEccFailure_Notification
#define vHsmResponseIsr vHsmResponseIsr

/* Alarm identifiers. */
#define Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms
#define Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms
#define Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms
#define Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms
#define Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms
#define Rte_Al_TE_AdcIf_AdcIf_MainFunction Rte_Al_TE_AdcIf_AdcIf_MainFunction
#define Rte_Al_TE_ApplTask_Core0_LowPrio_0_1000ms Rte_Al_TE_ApplTask_Core0_LowPrio_0_1000ms
#define Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms
#define Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms
#define Rte_Al_TE_ApplTask_Core0_LowPrio_0_1ms Rte_Al_TE_ApplTask_Core0_LowPrio_0_1ms
#define Rte_Al_TE_ApplTask_Core0_LowPrio_0_250ms Rte_Al_TE_ApplTask_Core0_LowPrio_0_250ms
#define Rte_Al_TE_ApplTask_Core0_LowPrio_0_2ms Rte_Al_TE_ApplTask_Core0_LowPrio_0_2ms
#define Rte_Al_TE_BFE_BFE_runExecuteStandardSteps Rte_Al_TE_BFE_BFE_runExecuteStandardSteps
#define Rte_Al_TE_BaseFunction_BaseFunction_Main Rte_Al_TE_BaseFunction_BaseFunction_Main
#define Rte_Al_TE_DIA_DIA_cyclicProcessingTask Rte_Al_TE_DIA_DIA_cyclicProcessingTask
#define Rte_Al_TE_DiagFunction_DiagFunction_MainFunction Rte_Al_TE_DiagFunction_DiagFunction_MainFunction
#define Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms
#define Rte_Al_TE_SBC_SBC_MainFunction Rte_Al_TE_SBC_SBC_MainFunction

/* Counter identifiers. */
#define SystemTimer SystemTimer

/* ScheduleTable identifiers. */

/* Resource identifiers. */
#define OsResource_EcuM OsResource_EcuM

/* Spinlock identifiers. */

/* Peripheral identifiers. */

/* Barrier identifiers. */

/* Trace OS-Application identifiers (All OS-Applications inclusive system objects). */
#define Os_TraceId_OsApplication_Trusted_Core0 Os_TraceId_OsApplication_Trusted_Core0
#define Os_TraceId_SystemApplication_OsCore0 Os_TraceId_SystemApplication_OsCore0

/* Trace thread identifiers (Tasks and ISRs inclusive system objects). */
#define Os_TraceId_ApplBackgroundTask_Core0 Os_TraceId_ApplBackgroundTask_Core0
#define Os_TraceId_ApplInitTask_Core0 Os_TraceId_ApplInitTask_Core0
#define Os_TraceId_ApplTask_Core0_HighPrio Os_TraceId_ApplTask_Core0_HighPrio
#define Os_TraceId_ApplTask_Core0_LowPrio Os_TraceId_ApplTask_Core0_LowPrio
#define Os_TraceId_BackgroundTask_Core0 Os_TraceId_BackgroundTask_Core0
#define Os_TraceId_BswTask_Core0_HighPrio Os_TraceId_BswTask_Core0_HighPrio
#define Os_TraceId_BswTask_Core0_LowPrio Os_TraceId_BswTask_Core0_LowPrio
#define Os_TraceId_Default_Init_Task Os_TraceId_Default_Init_Task
#define Os_TraceId_Default_Init_Task_Trusted Os_TraceId_Default_Init_Task_Trusted
#define Os_TraceId_IdleTask_OsCore0 Os_TraceId_IdleTask_OsCore0
#define Os_TraceId_OsTask_ALV_BeltFunctionAlgo Os_TraceId_OsTask_ALV_BeltFunctionAlgo
#define Os_TraceId_CanIsr_1 Os_TraceId_CanIsr_1
#define Os_TraceId_CounterIsr_SystemTimer Os_TraceId_CounterIsr_SystemTimer
#define Os_TraceId_RCM_PFlashEccFailure_Notification Os_TraceId_RCM_PFlashEccFailure_Notification
#define Os_TraceId_RCM_SRamEccFailure_Notification Os_TraceId_RCM_SRamEccFailure_Notification
#define Os_TraceId_vHsmResponseIsr Os_TraceId_vHsmResponseIsr
#define Os_TraceId_OsCore0_Hooks Os_TraceId_OsCore0_Hooks

/* Trace spinlock identifiers (All spinlocks inclusive system objects). */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32  Os_AppAccessMaskType;

/*! OS-Application identifiers. */
typedef enum
{
  OsApplication_Trusted_Core0 = 0, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemApplication_OsCore0 = 1, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_APPID_COUNT = 2,
  INVALID_OSAPPLICATION = OS_APPID_COUNT
} ApplicationType;

/*! Trusted function identifiers. */
typedef enum
{
  OS_TRUSTEDFUNCTIONID_COUNT = 0
} TrustedFunctionIndexType;

/*! Non-trusted function identifiers. */
typedef enum
{
  OS_NONTRUSTEDFUNCTIONID_COUNT = 0
} Os_NonTrustedFunctionIndexType;

/*! Fast trusted function identifiers. */
typedef enum
{
  OS_FASTTRUSTEDFUNCTIONID_COUNT = 0
} Os_FastTrustedFunctionIndexType;

/*! Task identifiers. */
typedef enum
{
  ApplBackgroundTask_Core0 = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  ApplInitTask_Core0 = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  ApplTask_Core0_HighPrio = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  ApplTask_Core0_LowPrio = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  BackgroundTask_Core0 = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  BswTask_Core0_HighPrio = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  BswTask_Core0_LowPrio = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_Init_Task = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_Init_Task_Trusted = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore0 = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsTask_ALV_BeltFunctionAlgo = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_TASKID_COUNT = 11,
  INVALID_TASK = OS_TASKID_COUNT
} TaskType;

/*! Category 2 ISR identifiers. */
typedef enum
{
  CanIsr_1 = 0,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer = 1,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  RCM_PFlashEccFailure_Notification = 2,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  RCM_SRamEccFailure_Notification = 3,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  vHsmResponseIsr = 4,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ISRID_COUNT = 5,
  INVALID_ISR = OS_ISRID_COUNT
} ISRType;

/*! Alarm identifiers. */
typedef enum
{
  Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_AdcIf_AdcIf_MainFunction = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_ApplTask_Core0_LowPrio_0_1000ms = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_ApplTask_Core0_LowPrio_0_1ms = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_ApplTask_Core0_LowPrio_0_250ms = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_ApplTask_Core0_LowPrio_0_2ms = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_BFE_BFE_runExecuteStandardSteps = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_BaseFunction_BaseFunction_Main = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_DIA_DIA_cyclicProcessingTask = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_DiagFunction_DiagFunction_MainFunction = 15,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms = 16,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SBC_SBC_MainFunction = 17,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ALARMID_COUNT = 18
} AlarmType;

/*! Counter identifiers. */
typedef enum
{
  SystemTimer = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_COUNTERID_COUNT = 1
} CounterType;

/*! ScheduleTable identifiers. */
typedef enum
{
  OS_SCHTID_COUNT = 0
} ScheduleTableType;

/*! Resource identifiers. */
typedef enum
{
  OsResource_EcuM = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_RESOURCEID_COUNT = 1
} ResourceType;

/*! Spinlock identifiers. */
typedef enum
{
  OS_SPINLOCKID_COUNT = 0,
  INVALID_SPINLOCK = OS_SPINLOCKID_COUNT
} SpinlockIdType;

/*! Peripheral identifiers. */
typedef enum
{
  OS_PERIPHERALID_COUNT = 0
} Os_PeripheralIdType;

/*! Barrier identifiers. */
typedef enum
{
  OS_BARRIERID_COUNT = 0
} Os_BarrierIdType;

/*! Trace OS-Application identifiers (All OS-Applications inclusive system objects). */
typedef enum
{
  Os_TraceId_OsApplication_Trusted_Core0 = 0,
  Os_TraceId_SystemApplication_OsCore0 = 1,
  OS_TRACE_APPID_COUNT = 2,
  OS_TRACE_INVALID_APPLICATION = OS_TRACE_APPID_COUNT + 1
} Os_TraceAppIdType;

/*! Trace thread identifiers (Tasks and ISRs inclusive system objects). */
typedef enum
{
  Os_TraceId_ApplBackgroundTask_Core0 = 0,
  Os_TraceId_ApplInitTask_Core0 = 1,
  Os_TraceId_ApplTask_Core0_HighPrio = 2,
  Os_TraceId_ApplTask_Core0_LowPrio = 3,
  Os_TraceId_BackgroundTask_Core0 = 4,
  Os_TraceId_BswTask_Core0_HighPrio = 5,
  Os_TraceId_BswTask_Core0_LowPrio = 6,
  Os_TraceId_Default_Init_Task = 7,
  Os_TraceId_Default_Init_Task_Trusted = 8,
  Os_TraceId_IdleTask_OsCore0 = 9,
  Os_TraceId_OsTask_ALV_BeltFunctionAlgo = 10,
  Os_TraceId_CanIsr_1 = 11,
  Os_TraceId_CounterIsr_SystemTimer = 12,
  Os_TraceId_RCM_PFlashEccFailure_Notification = 13,
  Os_TraceId_RCM_SRamEccFailure_Notification = 14,
  Os_TraceId_vHsmResponseIsr = 15,
  Os_TraceId_OsCore0_Hooks = 16,
  OS_TRACE_THREADID_COUNT = 17,
  OS_TRACE_INVALID_THREAD = OS_TRACE_THREADID_COUNT + 1
} Os_TraceThreadIdType;

/*! Trace spinlock identifiers (All spinlocks inclusive system objects). */
typedef enum
{
  OS_TRACE_NUMBER_OF_CONFIGURED_SPINLOCKS = 0,
  OS_TRACE_NUMBER_OF_ALL_SPINLOCKS = 0,
  OS_TRACE_INVALID_SPINLOCK = OS_TRACE_NUMBER_OF_ALL_SPINLOCKS + 1
} Os_TraceSpinlockIdType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TYPES_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Types_Lcfg.h
 *********************************************************************************************************************/
