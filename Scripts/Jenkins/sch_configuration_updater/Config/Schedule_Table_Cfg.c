/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

Definition of functions exported by the component "Schedule_Table_Cfg.c"
------------------------------------------------------------------
This file "SCH_Data.c" will generate a file "SCH_Data.o",
including object code of the functions exported by the component.
- Macros, constants and types local to the component
are defined in this file.
- Variables and functions local to the component are defined in this file
preceded by the keyword static.

Current revision: $Revision: 1.1 $
Checked in:       $Date: 2020/05/12 16:29:28CEST $

**************************************************************************

Overview of the component :
Part of the package SCHEDULE_TABLE

------------------------------------------------------------------------

Design document:
SCH - SW Module Design Document .docx  (SCHEDULER design)
SCH_TBL - SW Module Design Document .docx (SCHEDULE_TABLE design)

*************************************************************************/

/*************************************************************************
Packages inclusion
*************************************************************************/
#include "common.h"
#include "Config.h"
#include "Std_Types.h"
#include "ESM_cfg_generic.h"
#include "com_dcm.h"

/*************************************************************************
Intra-package inclusions
*************************************************************************/
#include "Scheduler.h"
#include "Schedule_Table_Cfg.h"

/*************************************************************************
Private inclusion
*************************************************************************/

/*************************************************************************
Declaration of constants
*************************************************************************/

/*************************************************************************
Declaration of macros
*************************************************************************/

/*************************************************************************
Declaration of types
*************************************************************************/

/*************************************************************************
LOCAL variables declaration
*************************************************************************/
/* Stores time-slot overflow informations for debug in case of
 * defense function call by the scheduler (only if configured) */
#ifndef SCH_CFG_DEFENSE_FUNC
#else

#define SCH_AC_Scheduler_START_SEC_VAR_INIT_32
#include "SCH_AC_Scheduler_MemMap.h"
/* The 2 following variables only exist to be checked with the debugger, to verify if time slot
 * overrun has occurred. If an application use is added, the following QAC deviations can be removed. */
/* QAC_WARNING S 3229 3 */ /* File scope static, 'M_u32OverflowDelay', is written but never used */
LOCAL uint32 M_u32OverflowDelay = KU32_ZERO;
/* QAC_WARNING S 3229 3 */ /* File scope static, 'M_u8OverflowTimeSlot', is written but never used */
LOCAL uint8 M_u8OverflowTimeSlot = KU8_ZERO;

#define SCH_AC_Scheduler_STOP_SEC_VAR_INIT_32
#include "SCH_AC_Scheduler_MemMap.h"

#endif

/*************************************************************************
LOCAL constant data declaration
**************************************************************************/

/*************************************************************************
EXPORTED variables declaration
*************************************************************************/
#define SCH_AC_Scheduler_START_SEC_CODE
#include "SCH_AC_Scheduler_MemMap.h"

extern void SCM_runManageSystemContext             (void);
extern void ADC_runManageFilters                   (void);
extern void ATM_runMainFunction                    (void);
extern void BFE_runExecuteStandardSteps            (void);
extern void PAL_runMainFunction                    (void);
extern void NVP_runMainFunction                    (void);
extern void FEE_MainFunction                       (void);
extern void FLS_MainFunction                       (void);
extern void WDG_Refresh                            (void);
extern void PRT_Refresh                            (void);
extern void CIL_runCANToAppli                      (void);
extern void MMG_runManageModeDelays                (void);
extern void MMG_runUpdateModeStatus                (void);
extern void MMG_runUpdateVbatStatus                (void);
extern void ERH_runStoreEverQualifiedAECsToNVP     (void);
extern void FLT_runStoreEverQualifiedDTCsToNVP     (void);
extern void VDA_runMainFunction                    (void);
extern void PRE_runPreTensioning                   (void);
extern void PRO_runProductionCycles                (void);
extern void SFR_runStandardFunctionRecovery        (void);
extern void BFS_runBeltFunctionSelection           (void);
extern void BFE_runScheduleStep                    (void);
extern void EOL_runMainFunction                    (void);
extern void STM_runIncreaseSystemTime              (void);
extern void CIL_runAppliToCAN                      (void);
extern void ESM_MainFunction                       (void);
extern void PMP_runComputeDeficiencyLevel          (void);
extern void SCM_runWriteSystemContextShutdown      (void);
extern void SCM_runMonitoreExecutedCycle           (void);
extern void CIL_runMF24Logger                      (void);
extern void COM_RX_MainFunction                    (void);
extern void COM_TX_MainFunction                    (void);
extern void COM_NM_MainFunction                    (void);
extern void COM_DCM_TM_MainFunction                (void);
extern void COM_DCM_NL_MainFunction                (void);
extern void COM_DCM_DG_MainFunction                (void);
extern void COM_DCM_DTC_MainFunction               (void);
extern void FLT_runMainFunction                    (void);
extern void MMG_runComputeCalibrationData          (void);

#define SCH_AC_Scheduler_STOP_SEC_CODE
#include "SCH_AC_Scheduler_MemMap.h"


/*************************************************************************
EXPORTED constant data declaration
**************************************************************************/

/*************************************************************************
Syntax: const SCH_ST_TASK_ITEM_T SCH_ast_Run_Schedule_Table[]+
Object: The Schedule Table of the application.
   Configures all tasks to schedule with their respective attributes.
Unit: N.A. Structure array.
Range: Up to 250 item in the array.
**************************************************************************/
#define SCH_AC_Scheduler_START_SEC_CONST_UNSPECIFIED
#include "SCH_AC_Scheduler_MemMap.h"


/* QAC_WARNING S 3120 ++ */ /* Hard-coded 'magic' integer constant.
                      * Each task has its own time offset attribute expressed in second.
                      * In each periodicity, all tasks shall be sorted regarding this time offset attribute. */
/* QAC_WARNING S 3211 2 */ /* The global identifier 'SCH_ast_Run_Schedule_Table' is defined here but is not used in this translation unit.
                     * In fact, defining the schedule table is a separate file was the goal! */
EXPORTED const SCH_ST_TASK_ITEM_T SCH_ast_Run_Schedule_Table[] = {
/* QAC_WARNING S 0703 3 */ /* Structure has fewer initializers than its declared size.
                     * In fact, the schedule table shall be seen as list finished with a terminal element, not like finite size array */
   /* 1 ms periodic tasks: ------------------------------------------------------*/
   /* 2 ms periodic tasks: ------------------------------------------------------*/
   {&SCM_runManageSystemContext,          SCH_MS(0)},
   {&ADC_runManageFilters,                SCH_MS(0)},
   {&MMG_runUpdateVbatStatus,             SCH_MS(0)},
   {&ATM_runMainFunction,                 SCH_MS(0)},
   {&BFE_runExecuteStandardSteps,         SCH_MS(1)},
   {&PAL_runMainFunction,                 SCH_MS(1)},
   {&NVP_runMainFunction,                 SCH_MS(1)},
   {&FEE_MainFunction,                    SCH_MS(1)},
   {&FLS_MainFunction,                    SCH_MS(1)},
   {&WDG_Refresh,                         SCH_MS(1)},
   {SCH_END_OF_LIST,                      SCH_MS(2u)},

   /* 5 ms periodic tasks: ------------------------------------------------------*/
   {&COM_RX_MainFunction,                 SCH_MS(0)},
   {&COM_DCM_TM_MainFunction,             SCH_MS(1)},
   {&COM_DCM_NL_MainFunction,             SCH_MS(1)},
   {&COM_DCM_DTC_MainFunction,            SCH_MS(1)},
   {&COM_DCM_DG_MainFunction,             SCH_MS(1)},
   {&COM_TX_MainFunction,                 SCH_MS(1)},
   {SCH_END_OF_LIST,                      SCH_MS(5u)},

   /* 10 ms periodic tasks: -----------------------------------------------------*/
   {&PRT_Refresh,                         SCH_MS(0)},
   {&CIL_runCANToAppli,                   SCH_MS(0)},
   {&MMG_runManageModeDelays,             SCH_MS(1)},
   {&MMG_runUpdateModeStatus,             SCH_MS(1)},
   {&ERH_runStoreEverQualifiedAECsToNVP,  SCH_MS(2)},
   {&VDA_runMainFunction,                 SCH_MS(2)},
   {&PRE_runPreTensioning,                SCH_MS(3)},
   {&PRO_runProductionCycles,             SCH_MS(4)},
   {&SFR_runStandardFunctionRecovery,     SCH_MS(4)},
   {&BFS_runBeltFunctionSelection,        SCH_MS(5)},
   {&BFE_runScheduleStep,                 SCH_MS(5)},
   {&SCM_runMonitoreExecutedCycle,        SCH_MS(5)},
   {&MMG_runComputeCalibrationData,       SCH_MS(6)},
   {&EOL_runMainFunction,                 SCH_MS(6)},
   {&STM_runIncreaseSystemTime,           SCH_MS(6)},
   {&CIL_runAppliToCAN,                   SCH_MS(7)},
   {&CIL_runMF24Logger,                   SCH_MS(7)},
   {&COM_NM_MainFunction,                 SCH_MS(8)},
   {&FLT_runMainFunction,                 SCH_MS(8)},
   /* ESM can potentially request the scheduler to switch to another schedule table
    * (change is effective at the end of its time slot). To ensure the 10 time slots
    * cycle integrity and synchronization between schedule tables (especially the
    * WDG_Refresh task), ESM_MainFunction shall be allocated to time slot 9. */
   {&FLT_runStoreEverQualifiedDTCsToNVP,  SCH_MS(9)},
   {&ESM_MainFunction,                    SCH_MS(9)},
   {SCH_END_OF_LIST,                      SCH_MS(10u)},

   /* 100 ms periodic tasks: ----------------------------------------------------*/
   {&PMP_runComputeDeficiencyLevel,       SCH_MS(9)},

   {SCH_END_OF_LIST,                      SCH_MS(100u)},

   /* End of schedule table ---------------------------------------------------- */
   {SCH_END_OF_LIST,                      SCH_MS(0u)}
};


/* QAC_WARNING S 3211 2 */ /* The global identifier 'SCH_ast_Wakeup_Schedule_Table' is defined here but is not used in this translation unit.
                     * In fact, defining the schedule table in a separate file was the goal! */
EXPORTED const SCH_ST_TASK_ITEM_T SCH_ast_Wakeup_Schedule_Table[] = {
/* QAC_WARNING S 0703 3 */ /* Structure has fewer initializers than its declared size.
                     * In fact, the schedule table shall be seen as list finished with a terminal element, not like finite size array */

/* 1 ms periodic tasks: ------------------------------------------------------*/
/* 2 ms periodic tasks: ------------------------------------------------------*/
   {&ADC_runManageFilters,                SCH_MS(0u)},
   {&MMG_runUpdateVbatStatus,             SCH_MS(1u)},
   {&WDG_Refresh,                         SCH_MS(1u)},
   {SCH_END_OF_LIST,                      SCH_MS(2u)},
/* 5 ms periodic tasks: ------------------------------------------------------*/
   {&COM_RX_MainFunction,                 SCH_MS(0)},
   {&COM_TX_MainFunction,                 SCH_MS(1)},
   {SCH_END_OF_LIST,                      SCH_MS(5u)},
/* 10 ms periodic tasks: ------------------------------------------------------*/
#if ESM_CFG_WIRED_WAKEUP == ESM_WIRED_WAKEUP_ENABLED
   {&ESM_ValidateWiredWakeUpSituation, SCH_MS(8u)},
#endif
   {&MMG_runManageModeDelays,             SCH_MS(1u)},
   {&MMG_runUpdateModeStatus,             SCH_MS(1u)},
   {&COM_NM_MainFunction,                 SCH_MS(1u)},
   /* ESM can potentially request the scheduler to switch to another schedule table
    * (change is effective at the end of its time slot). To ensure the 10 time slots
    * cycle integrity and synchronization between schedule tables (especially the
    * WDG_Refresh task), ESM_MainFunction shall be allocated to time slot 9. */
   {&ESM_MainFunction,                    SCH_MS(9)},
   {SCH_END_OF_LIST,                      SCH_MS(10u)},
/* End of schedule table ---------------------------------------------------- */
   {SCH_END_OF_LIST,                      SCH_MS(0u)}};


/* QAC_WARNING S 3211 2 */ /* The global identifier 'SCH_ast_Shutdown_Schedule_Table' is defined here but is not used in this translation unit.
                     * In fact, defining the schedule table in a separate file was the goal! */
EXPORTED const SCH_ST_TASK_ITEM_T SCH_ast_Shutdown_Schedule_Table[] = {
/* QAC_WARNING S 0703 3 */ /* Structure has fewer initializers than its declared size.
                     * In fact, the schedule table shall be seen as list finished with a terminal element, not like finite size array */
/* 1 ms periodic tasks: ------------------------------------------------------*/
/* 2 ms periodic tasks: ------------------------------------------------------*/
   {&ADC_runManageFilters,                SCH_MS(0u)},
   {&SCM_runWriteSystemContextShutdown,   SCH_MS(0u)},
   {&MMG_runUpdateVbatStatus,             SCH_MS(1u)},
   {&NVP_runMainFunction,                 SCH_MS(1u)},
   {&FEE_MainFunction,                    SCH_MS(1u)},
   {&FLS_MainFunction,                    SCH_MS(1u)},
   {&WDG_Refresh,                         SCH_MS(1u)},
   {SCH_END_OF_LIST,                      SCH_MS(2u)},
/* 10 ms periodic tasks: ------------------------------------------------------*/
   /* ESM can potentially request the scheduler to switch to another schedule table
    * (change is effective at the end of its time slot). To ensure the 10 time slots
    * cycle integrity and synchronization between schedule tables (especially the
    * WDG_Refresh task), ESM_MainFunction shall be allocated to time slot 9. */
   {&ESM_MainFunction,                    SCH_MS(9)},
   {SCH_END_OF_LIST,                      SCH_MS(10u)},
/* End of schedule table ---------------------------------------------------- */
   {SCH_END_OF_LIST,                      SCH_MS(0u)}};

/* QAC_WARNING S 3211 2 */ /* The global identifier 'SCH_ast_Post_Run_Schedule_Table' is defined here but is not used in this translation unit.
                     * In fact, defining the schedule table in a separate file was the goal! */
EXPORTED const SCH_ST_TASK_ITEM_T SCH_ast_Post_Run_Schedule_Table[] = {
/* QAC_WARNING S 0703 3 */ /* Structure has fewer initializers than its declared size.
                     * In fact, the schedule table shall be seen as list finished with a terminal element, not like finite size array */

/* 1 ms periodic tasks: ------------------------------------------------------*/
/* 2 ms periodic tasks: ------------------------------------------------------*/
   {&ADC_runManageFilters,                SCH_MS(0u)},
   {&MMG_runUpdateVbatStatus,             SCH_MS(1u)},
   {&WDG_Refresh,                         SCH_MS(1u)},
   {SCH_END_OF_LIST,                      SCH_MS(2u)},

   /* 5 ms periodic tasks: ------------------------------------------------------*/
   {&COM_RX_MainFunction,                 SCH_MS(0)},
   {&COM_TX_MainFunction,                 SCH_MS(1)},
   {SCH_END_OF_LIST,                      SCH_MS(5u)},

/* 10 ms periodic tasks: ------------------------------------------------------*/
   {&MMG_runManageModeDelays,             SCH_MS(1u)},
   {&MMG_runUpdateModeStatus,             SCH_MS(1u)},
   {&COM_NM_MainFunction,                 SCH_MS(1u)},
   /* ESM can potentially request the scheduler to switch to another schedule table
    * (change is effective at the end of its time slot). To ensure the 10 time slots
    * cycle integrity and synchronization between schedule tables (especially the
    * WDG_Refresh task), ESM_MainFunction shall be allocated to time slot 9. */
   {&ESM_MainFunction,                    SCH_MS(9)},
   {SCH_END_OF_LIST,                      SCH_MS(10u)},
/* End of schedule table ---------------------------------------------------- */
   {SCH_END_OF_LIST,                      SCH_MS(0u)}};

/* QAC_WARNING S 3120 -- */

#define SCH_AC_Scheduler_STOP_SEC_CONST_UNSPECIFIED
#include "SCH_AC_Scheduler_MemMap.h"

/**************************************************************************
Private Functions
**************************************************************************/
/**************************************************************************
Label:
Object: Call back function called by the scheduler only in case of time
   execution time exceeded (if configured).
Parameters:
   sint16 s16Delay : Elapsed time since the time slot expected end.
   uint8 u8TimeSlot: Time slot index in the major cycle.
Return: boolean
   B_TRUE : To request the scheduler to re-synchronize following time-slot.
   B_FALSE: To request the scheduler to keep the expected time-slot timings.
**************************************************************************/
#ifndef SCH_CFG_DEFENSE_FUNC
#else
#define SCH_AC_Scheduler_START_SEC_CODE
#include "SCH_AC_Scheduler_MemMap.h"

boolean SCH_Defense(const uint32 u32Delay, const uint8 u8TimeSlot)
{
   /* Stores the overflow informations into static variables to make them viewable
    * without breakpoint in the debugger. */
   M_u32OverflowDelay   = u32Delay;
   M_u8OverflowTimeSlot = u8TimeSlot;
   /* Do not ask the scheduler to re-synchronize - try to recover expected task timing */
   return B_FALSE;
}
#define SCH_AC_Scheduler_STOP_SEC_CODE
#include "SCH_AC_Scheduler_MemMap.h"

#endif

/**************************************************************************
Exported Functions
**************************************************************************/

/*************************************************************************
Evolution of the component SCH_Data.c

Created by :  S. CLAVEAU

$Log: Schedule_Table_Cfg.c  $
Revision 1.1 2020/05/12 16:29:28CEST Lucian Ardeleanu (lucian.ardeleanu) 
Initial revision
Member added to project e:/MKSProjects/SBE/Exploration/Python_Workspace/sch_configuration_updater/Config/project.pj
Revision 1.2.3.26 2020/04/22 10:49:56EEST Dan Dustinta (dan.dustinta) 
reduce CPU Load
Revision 1.2.3.25 2020/04/16 10:19:34EEST Dan Dustinta (dan.dustinta) 
update in order to optimize DTC qualification
Revision 1.2.3.24 2020/04/10 12:12:43EEST Bogdan Suto (bogdan.suto) 
add COM_RX_MainFunction and COM_TX_MainFunction in the 5ms task of the wakeup schedule table
Revision 1.2.3.23 2020/02/20 18:02:00EET Dan Dustinta (dan.dustinta) 
update
Revision 1.2.3.22 2020/01/31 14:37:20EET Dan Dustinta (dan.dustinta) 
remove ALV_CAL_CKS from unused blocks
Revision 1.2.3.21 2020/01/30 13:23:24EET Dan Dustinta (dan.dustinta) 
update function scheduling
Revision 1.2.3.20 2020/01/29 15:19:18EET Dan Dustinta (dan.dustinta) 
rearrange tasks
Revision 1.2.3.19 2020/01/29 14:22:03EET Dan Dustinta (dan.dustinta) 
split write function
Revision 1.2.3.18 2020/01/29 13:38:41EET Dan Dustinta (dan.dustinta) 
distribute functions more evenly
Revision 1.2.3.17 2019/09/27 16:02:18EEST Dan Dustinta (dan.dustinta) 
remove HWA BPA
Revision 1.2.3.16 2019/08/26 10:21:09EEST Vlad Chioveanu (vlad.chioveanu) 
Calibration data files
Revision 1.2.3.15 2019/07/04 17:45:28EEST Bogdan Suto (bogdan.suto) 
Moved COM_RX_MainFunction and COM_TX_MainFunction from the 10ms task to 5ms task
Revision 1.2.3.14 2019/05/27 15:09:11EEST Bogdan Suto (bogdan.suto)
Added task to 2ms schedule table to monitor the voltage stability
Revision 1.2.3.13 2019/05/09 11:28:13EEST Bogdan Suto (bogdan.suto)
Moved COM_DCM_MainFunction from the 10ms task to 5ms
Revision 1.2.3.12 2019/05/07 13:46:39EEST Dan Dustinta (dan.dustinta)
remove BPA module
Revision 1.2.3.11 2019/04/22 17:50:38EEST Bogdan Suto (bogdan.suto)
Removed the COM_RX_MainFunction, COM_DCM_MainFunction and COM_TX_MainFunction functions from the WAKE-UP and POST RUN schedule table
Revision 1.2.3.10 2019/02/13 09:57:08EET Razvan Badiu (razvan.badiu)
add FLT manager
Revision 1.2.3.9 2019/01/30 11:18:19EET Razvan Badiu (razvan.badiu)
remove unused modules
Revision 1.2.3.8 2019/01/10 15:39:59EET Bogdan Suto (bogdan.suto)
renamed the NM_Scheduler to COM_NM_MainFunction
Revision 1.2.3.7 2019/01/09 10:22:36EET Dan Dustinta (dan.dustinta)
remove SCH_END_OF_LIST for 1ms task
Revision 1.2.3.6 2019/01/09 10:16:10EET Dan Dustinta (dan.dustinta)
remove duplicate functions
Revision 1.2.3.5 2019/01/09 10:08:13EET Dan Dustinta (dan.dustinta)
remove unused functions
Revision 1.2.3.4 2018/12/06 12:39:09EET Bogdan Suto (bogdan.suto)
renamed the COM_DCM_Scheduler function to COM_DCM_MainFunction
Revision 1.2.3.3 2018/12/03 16:07:34EET Dan Dustinta (dan.dustinta)
add COM_DCM scheduler
Revision 1.2.3.2 2018/11/27 17:23:57EET Bogdan Suto (bogdan.suto)
added NM_Scheduler and NM_Scheduler in the Run, Wakeup and PostRun schedule table
Revision 1.2.3.1 2018/11/22 14:51:44EET Bogdan Suto (bogdan.suto)
added COM_RX_MainFunction and COM_TX_MainFunction in the Run, Wakeup and PostRun schedule table
Revision 1.2 2017/08/04 14:55:49EEST Pierre-Olivier Pilot (pierre-olivier.pilot)
Add VIP in compiler toolchain
Revision 1.1 2017/01/31 14:40:01CET Michael Pastor (michael.pastor)
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_03/View_Development/Components/Application/SCH/Implementation/src/project.pj
Revision 1.1 2016/11/25 14:32:31CET Michael Pastor (michael.pastor)
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Automation/PropagationProject_054/Platform_Mainstream_Phase_01/Dev_View/Components/Application/SCH/Implementation/src/project.pj
Revision 1.1 2016/10/05 10:13:31CEST Michael Pastor (michael.pastor)
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Components/Application/SCH/Implementation/src/project.pj
Revision 1.2 2016/10/05 09:54:40CEST Audrey Vache (audrey.vache)
migration from ETAS sandbox to Core one (diff from checkpt 1.5 to 1.6)
Revision 1.10 2016/09/29 18:36:37CEST Pierre-Olivier Pilot (pierre-olivier.pilot)
Fix Measurement frame 24 logger (Separated runnable + init runnable)
Revision 1.9 2016/09/05 10:39:30CEST Sabine Flechelle (sabine.flechelle)
PP4G R3.0M 444498 - Remove P R Q A
Revision 1.8 2016/09/05 10:28:17CEST Sabine Flechelle (sabine.flechelle)
PP4G R3.0M 444498 - Remove P R Q A
Replace by P R Q A in comments
Revision 1.7 2016/09/05 10:02:25CEST Sabine Flechelle (sabine.flechelle)
PP4G R3.0M 444498 - Remove all P R Q As
P R Q A is replaced by QAC_WARNING
Revision 1.6 2016/06/17 09:47:03CEST Audrey Vache (avache)
Issue 415530 - Integrate SCM and SCH modifications of issue 234177
Revision 1.5 2016/06/07 12:52:23CEST Audrey Vache (avache)
Memory mapping implementation
Revision 1.4 2016/05/24 10:48:28CEST Maxime Bourdon (mbourdon)
SCH migration completion
Revision 1.3 2015/11/10 11:22:34CET Maxime Bourdon (mbourdon)
Inclusion clean up
Revision 1.2 2015/11/06 14:11:31CET Maxime Bourdon (mbourdon)
Pass ATM Autotests calls through RTE + includes clean up
Revision 1.1 2015/10/15 11:41:12CEST Cedric Sauvage (csauvage)
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/_SCH/src/project.pj
Revision 1.30 2015/04/23 18:12:04CEST Pierre-Olivier Pilot (ppilot)
PMP integ
Revision 1.29 2015/04/23 10:25:23CEST Sebastien Claveau (sclaveau)
Better share CPU load in schedule tables
Revision 1.28 2015/04/08 16:23:57CEST Sebastien Claveau (sclaveau)
Fix CAN TP stMin management + set time granularity from 5ms to 1ms
Revision 1.27 2015/04/01 15:38:31CEST Pierre-Olivier Pilot (ppilot)
Put ERH_mainFunction into #if/#endif directive
Revision 1.26 2015/03/16 17:16:08CET Cedric Sauvage (csauvage)
Correction of NM management in order to go back or stay in NORMAL NM state in case of active diagnostic session or belt function on going.
Revision 1.25 2015/02/13 15:25:01CET Sabine Flechelle (sflechelle)
Issue 167292 - Split MMG into 2 runnables
Goal is to separate actions to update mode status and actions to manage timers,
as updating mode status is needed to be scheduled as often as necessary
(before belt functions and before auto tests).
- MMG_runUpdateModeStatus
- MMG_runManageModeDelays.
Revision 1.24 2015/01/13 10:42:45CET Sebastien Claveau (sclaveau)
Integrates the configurable ADC IIR filtering feature
Revision 1.23 2014/12/12 16:35:13CET Pierre-Olivier Pilot (ppilot)
Add the erh mainfunction in RUN schedule table (10ms slot 4)
Revision 1.22 2014/11/27 10:27:03CET Sebastien Claveau (sclaveau)
Reactivates port refresh since it preserves PWM boost direction
Revision 1.21 2014/11/25 17:15:04CET Sebastien Claveau (sclaveau)
Clarify the presentation of schedule tables definition
Revision 1.20 2014/11/21 11:06:08CET Sebastien Claveau (sclaveau)
Modif job monitoring + QAC
Revision 1.19 2014/06/24 21:08:58CEST Cedric Sauvage (csauvage)
Remove CAN_xxx main functions from Shutdown Schedule Table
Revision 1.18 2014/06/16 17:12:00CEST Cedric Sauvage (csauvage)
NVP operation in Shutdown added
Revision 1.17 2014/06/13 21:07:51CEST Cedric Sauvage (csauvage)
Integration of Low Power mode + CAN wake up
SW Workaround with ADC peripheral to be confirmed with Freescale later
ESM cleaned code
Add Post Run state in ESM
Synchronization between WDG refresh command (COP) and Shutdown Sequence
Add a new MCU API to de-init all peripherals
Register init for MCU Voltage domain VDDC/VDDX
Revision 1.16 2014/06/04 13:40:10CEST Temel Demirel (tdemirel)
Adding the ERH_StoreEverQualifiedAECsToNVP() function to check perdiodicaly if AECs status shal be stored in NVP or not
Revision 1.15 2014/05/28 14:43:42CEST Cedric Sauvage (csauvage)
NVP stack rescheduled every 2 ms instead of 5ms
PRT_Refresh fct call removed
Revision 1.14 2014/05/21 15:40:39CEST Sebastien Claveau (sclaveau)
Add session and security access services inside DCM, modify regarding QAC checking.
Revision 1.13 2014/05/14 17:33:58CEST Sebastien Claveau (sclaveau)
Finish CAN TP/DCM integration & development
Revision 1.12 2014/05/07 14:32:13CEST Sebastien Claveau (sclaveau)
CAN TP and DCM first integration
Revision 1.11 2014/05/07 11:44:10CEST Temel Demirel (tdemirel)
Integration of DIA component
Revision 1.10 2014/05/06 15:01:15CEST Sabine Flechelle (sflechelle)
Issue_143068 - Schedule Belt Functions components
Schedule the periodic runnables of new components:
BFE, BFS, BPA, BSR, EOL, MMG, PAL-A, PAL-S, PCM, PRE, PRO, SFR
Revision 1.9 2014/05/05 16:36:20CEST Cedric Sauvage (csauvage)
Integration of E2P stack
Revision 1.8 2014/04/28 10:34:33CEST Temel Demirel (tdemirel)
ATM/ERH modules integration
Revision 1.7 2014/03/31 17:15:12CEST Francois.Gilbert (fgilbert)
CIL functions moved to 10ms task
Revision 1.6 2014/03/31 09:44:42CEST Francois.Gilbert (fgilbert)
CIL integration into SCH table
Revision 1.5 2014/03/20 15:22:57CET Sebastien Claveau (sclaveau)
Integration of _CAN module
Revision 1.4 2014/02/19 15:44:27CET Cedric Sauvage (csauvage)
Add Port register refresh function call in the RUN schedule table
Reorganize existing schedule table in order to put the sub tables with the lowest period at the begining
Add PWM test macro for eval board. (will be removed with eval board test code in future)
Revision 1.3 2014/01/29 10:39:04CET Cedric Sauvage (csauvage)
Add Support for Wired wake up in the ESM (as test feature to test the low power mode - and mcu wake up)

By default in config.h this feature is disabled in order to stay alive during development phase (precompilation key __AUTOMATIC_WAKE_UP__)
Revision 1.2 2014/01/27 15:19:15CET Cedric Sauvage (csauvage)
Add periodical call to WDG routine in order to refresh internal WDG
Revision 1.1 2014/01/24 17:00:17CET Sebastien Claveau (sclaveau)
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/_SCH/src/project.pj

*************************************************************************/

/* end of file */
