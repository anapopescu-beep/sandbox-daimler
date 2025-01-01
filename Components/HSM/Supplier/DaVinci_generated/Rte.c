/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte.c
 *           Config:  vHsmConfig.dpa
 *      ECU-Project:  vHsmConfig
 *
 *        Generator:  MICROSAR RTE Generator Version 4.28.0
 *                    RTE Core Version 1.28.0
 *          License:  CBD2200336
 *
 *      Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0857 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_Dir1.1, MD_Rte_Os */
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_Csm.h"
#include "Rte_KeyM.h"
#include "Rte_NvM.h"
#include "Rte_Os_OsCore0_swc.h"
#include "SchM_BswModuleDescriptions_30_vHsm_Hal.h"
#include "SchM_Crypto_30_Hwa.h"
#include "SchM_Crypto_30_LibCv.h"
#include "SchM_Csm.h"
#include "SchM_Fee.h"
#include "SchM_Fls_17_Dmu.h"
#include "SchM_KeyM.h"
#include "SchM_NvM.h"
#include "SchM_vHsm.h"

#include "Rte_Hook.h"

/* AUTOSAR 3.x compatibility */
#if !defined (RTE_LOCAL)
# define RTE_LOCAL static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelKM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_8BIT
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState = RTE_STATE_UNINIT; /* PRQA S 3408 */ /* MD_Rte_3408 */
volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_StartTiming_InitState = RTE_STATE_UNINIT; /* PRQA S 0850, 3408, 1514 */ /* MD_MSR_MacroArgumentEmpty, MD_Rte_3408, MD_Rte_1514 */

#define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if defined OS_US2TICKS_SystemTimer
# define RTE_USEC_SystemTimer OS_US2TICKS_SystemTimer
#else
# define RTE_USEC_SystemTimer(val) ((TickType)RTE_CONST_USEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer
# define RTE_MSEC_SystemTimer OS_MS2TICKS_SystemTimer
#else
# define RTE_MSEC_SystemTimer(val) ((TickType)RTE_CONST_MSEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer
# define RTE_SEC_SystemTimer OS_SEC2TICKS_SystemTimer
#else
# define RTE_SEC_SystemTimer(val)  ((TickType)RTE_CONST_SEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#define RTE_CONST_MSEC_SystemTimer_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer_10 (10UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * Buffers for Basic Tasks triggered by OS Schedule Table
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint32, RTE_VAR_ZERO_INIT) Rte_ScheduleTable_OsTask_Step = 0U;
VAR(uint32, RTE_VAR_ZERO_INIT) Rte_ScheduleTable_Ostask_HighPrio_Step = 0U;

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) SchM_Init(void)
{
  /* activate the tasks */
  (void)ActivateTask(vHsmMainFunctionTask); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE2_vHsmMainFunctionTask_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */

  Rte_InitState = RTE_STATE_SCHM_INIT;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void)
{
  Rte_StartTiming_InitState = RTE_STATE_INIT;
  Rte_InitState = RTE_STATE_INIT;

  return RTE_E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void)
{
  Rte_StartTiming_InitState = RTE_STATE_UNINIT;
  Rte_InitState = RTE_STATE_SCHM_INIT;

  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE2_vHsmMainFunctionTask_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_UNINIT;
}

FUNC(void, RTE_CODE) Rte_InitMemory(void)
{
  Rte_InitState = RTE_STATE_UNINIT;
  Rte_StartTiming_InitState = RTE_STATE_UNINIT;

  /* reset OsScheduleTable variables */
  Rte_ScheduleTable_OsTask_Step = 0U;
  Rte_ScheduleTable_Ostask_HighPrio_Step = 0U;

}

#ifdef BRE_ENABLE_UNCONNECTED_RTE_APIS


/**********************************************************************************************************************
 * Exclusive area access
 *********************************************************************************************************************/

#endif

#ifdef BRE_ENABLE_UNCONNECTED_RTE_APIS

#endif

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/
#define RTE_START_SEC_OSTASK_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     OsTask
 * Priority: 10
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(OsTask) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{

  if (Rte_ScheduleTable_OsTask_Step == 0U) /* COV_RTE_STATE_MACHINE_LAST_STATE */
  {
    /* call schedulable entity */
    vHsm_MainFunction_vHsmSchedulableEntities_Unmapped();

    Rte_ScheduleTable_OsTask_Step = 0;
  }

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_OSTASK_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_OSTASK_HIGHPRIO_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Ostask_HighPrio
 * Priority: 20
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Ostask_HighPrio) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{

  if (Rte_ScheduleTable_Ostask_HighPrio_Step == 0U) /* COV_RTE_STATE_MACHINE_LAST_STATE */
  {
    /* call schedulable entity */
    vHsm_MainFunction_vHsmSchedulableEntities_HighPrio();

    Rte_ScheduleTable_Ostask_HighPrio_Step = 0;
  }

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_OSTASK_HIGHPRIO_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VHSMMAINFUNCTIONTASK_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     vHsmMainFunctionTask
 * Priority: 0
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(vHsmMainFunctionTask) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;)
  {
    /* Wait event skipped for background task */
    (void)GetEvent(vHsmMainFunctionTask, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_vHsmMainFunctionTask_0_10ms | Rte_Ev_Run1_Crypto_30_LibCv_Crypto_30_LibCv_MainFunction | Rte_Ev_Run1_Csm_Csm_MainFunction | Rte_Ev_Run1_KeyM_KeyM_MainFunction | Rte_Ev_Run1_NvM_NvM_MainFunction | Rte_Ev_RunS1_Csm_Csm_MainFunction | Rte_Ev_RunS1_KeyM_KeyM_MainFunction | Rte_Ev_RunS1_NvM_NvM_MainFunction)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_vHsmMainFunctionTask_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Fee_MainFunction();

      /* call schedulable entity */
      Fls_17_Dmu_MainFunction();
    }

    /* call schedulable entity */
    KeyM_MainBackgroundFunction();

    if ((ev & Rte_Ev_Run1_KeyM_KeyM_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      KeyM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run1_Crypto_30_LibCv_Crypto_30_LibCv_MainFunction) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Crypto_30_LibCv_MainFunction();
    }

    /* call schedulable entity */
    Crypto_30_Hwa_MainFunction();

    if ((ev & Rte_Ev_Run1_Csm_Csm_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      Csm_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    /* call schedulable entity */
    vHsm_MainFunction();

    if ((ev & Rte_Ev_Run1_NvM_NvM_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      NvM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_VHSMMAINFUNCTIONTASK_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1514:  MISRA rule: Rule8.9
     Reason:     Because of external definition, misra does not see the call.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2987:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: Rule8.4
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/

/**********************************************************************************************************************
 Code coverage justifications
 *********************************************************************************************************************/

/* COV_JUSTIFICATION_BEGIN
   \ID COV_RTE_STATE_MACHINE_LAST_STATE
     \ACCEPT TX
     \REASON The condition realizes a state of a cyclic state machine. At each time one of the implemented states is valid. Because of the
             "else if" construction the last state can never be covered false.

COV_JUSTIFICATION_END */
