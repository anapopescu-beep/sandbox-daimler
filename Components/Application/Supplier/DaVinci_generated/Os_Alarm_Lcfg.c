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
 *              File: Os_Alarm_Lcfg.c
 *   Generation Time: 2024-02-15 10:45:17
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_ALARM_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Alarm_Lcfg.h"
#include "Os_Alarm.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Cfg.h"
#include "Os_Common.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"
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

/*! Dynamic alarm data: Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_AdcIf_AdcIf_MainFunction */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_AdcIf_AdcIf_MainFunction_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_1000ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_1000ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_1ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_1ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_250ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_250ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_2ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_2ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_BFE_BFE_runExecuteStandardSteps */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_BFE_BFE_runExecuteStandardSteps_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_BaseFunction_BaseFunction_Main */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_BaseFunction_BaseFunction_Main_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_DIA_DIA_cyclicProcessingTask */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_DIA_DIA_cyclicProcessingTask_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_DiagFunction_DiagFunction_MainFunction */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_DiagFunction_DiagFunction_MainFunction_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_SBC_SBC_MainFunction */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_SBC_SBC_MainFunction_Dyn;

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


/*! Alarm configuration data: Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_BswTask_Core0_HighPrio,
  /* .Mask  = */ Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_10ms
};


/*! Alarm configuration data: Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_BswTask_Core0_HighPrio,
  /* .Mask  = */ Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_3ms
};


/*! Alarm configuration data: Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_BswTask_Core0_HighPrio,
  /* .Mask  = */ Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_5ms
};


/*! Alarm configuration data: Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_BswTask_Core0_LowPrio,
  /* .Mask  = */ Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_10ms
};


/*! Alarm configuration data: Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_BswTask_Core0_LowPrio,
  /* .Mask  = */ Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_5ms
};


/*! Alarm configuration data: Rte_Al_TE_AdcIf_AdcIf_MainFunction */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_AdcIf_AdcIf_MainFunction =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_AdcIf_AdcIf_MainFunction_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_BswTask_Core0_LowPrio,
  /* .Mask  = */ Rte_Ev_Run_AdcIf_AdcIf_MainFunction
};


/*! Alarm configuration data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_1000ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_1000ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_1000ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_ApplTask_Core0_LowPrio,
  /* .Mask  = */ Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_1000ms
};


/*! Alarm configuration data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_ApplTask_Core0_LowPrio,
  /* .Mask  = */ Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_100ms
};


/*! Alarm configuration data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_ApplTask_Core0_LowPrio,
  /* .Mask  = */ Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_10ms
};


/*! Alarm configuration data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_1ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_1ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_1ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_ApplTask_Core0_LowPrio,
  /* .Mask  = */ Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_1ms
};


/*! Alarm configuration data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_250ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_250ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_250ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_ApplTask_Core0_LowPrio,
  /* .Mask  = */ Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_250ms
};


/*! Alarm configuration data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_2ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_2ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_2ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_ApplTask_Core0_LowPrio,
  /* .Mask  = */ Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_2ms
};


/*! Alarm configuration data: Rte_Al_TE_BFE_BFE_runExecuteStandardSteps */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_BFE_BFE_runExecuteStandardSteps =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_BFE_BFE_runExecuteStandardSteps_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_OsTask_ALV_BeltFunctionAlgo,
  /* .Mask  = */ Rte_Ev_Run_BFE_BFE_runExecuteStandardSteps
};


/*! Alarm configuration data: Rte_Al_TE_BaseFunction_BaseFunction_Main */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_BaseFunction_BaseFunction_Main =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_BaseFunction_BaseFunction_Main_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_ApplTask_Core0_LowPrio,
  /* .Mask  = */ Rte_Ev_Run_BaseFunction_BaseFunction_Main
};


/*! Alarm configuration data: Rte_Al_TE_DIA_DIA_cyclicProcessingTask */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_DIA_DIA_cyclicProcessingTask =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_DIA_DIA_cyclicProcessingTask_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_ApplTask_Core0_LowPrio,
  /* .Mask  = */ Rte_Ev_Run_DIA_DIA_cyclicProcessingTask
};


/*! Alarm configuration data: Rte_Al_TE_DiagFunction_DiagFunction_MainFunction */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_DiagFunction_DiagFunction_MainFunction =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_DiagFunction_DiagFunction_MainFunction_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_ApplTask_Core0_LowPrio,
  /* .Mask  = */ Rte_Ev_Run_DiagFunction_DiagFunction_MainFunction
};


/*! Alarm configuration data: Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0
  },
  /* .Task  = */ &OsCfg_Task_OsTask_ALV_BeltFunctionAlgo,
  /* .Mask  = */ Rte_Ev_Cyclic_OsTask_ALV_BeltFunctionAlgo_0_10ms
};


/*! Alarm configuration data: Rte_Al_TE_SBC_SBC_MainFunction */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SBC_SBC_MainFunction =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_SBC_SBC_MainFunction_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0u, /* 0.0 sec */
      /* .Cycle            = */ 0u, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0
  },
  /* .Task  = */ &OsCfg_Task_BswTask_Core0_HighPrio,
  /* .Mask  = */ Rte_Ev_Run_SBC_SBC_MainFunction
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for alarms. */
CONSTP2CONST(Os_AlarmConfigType, OS_CONST, OS_CONST) OsCfg_AlarmRefs[OS_ALARMID_COUNT + 1] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
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
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SBC_SBC_MainFunction),
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
 *  END OF FILE: Os_Alarm_Lcfg.c
 *********************************************************************************************************************/
