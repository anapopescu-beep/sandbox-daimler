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
 *              File: Os_Alarm_Lcfg.h
 *   Generation Time: 2024-02-15 10:45:17
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_ALARM_LCFG_H
# define OS_ALARM_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Alarm_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Alarm configuration data: Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms;

/*! Alarm configuration data: Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms;

/*! Alarm configuration data: Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms;

/*! Alarm configuration data: Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms;

/*! Alarm configuration data: Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms;

/*! Alarm configuration data: Rte_Al_TE_AdcIf_AdcIf_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_AdcIf_AdcIf_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_1000ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_1000ms;

/*! Alarm configuration data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms;

/*! Alarm configuration data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms;

/*! Alarm configuration data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_1ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_1ms;

/*! Alarm configuration data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_250ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_250ms;

/*! Alarm configuration data: Rte_Al_TE_ApplTask_Core0_LowPrio_0_2ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_ApplTask_Core0_LowPrio_0_2ms;

/*! Alarm configuration data: Rte_Al_TE_BFE_BFE_runExecuteStandardSteps */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_BFE_BFE_runExecuteStandardSteps;

/*! Alarm configuration data: Rte_Al_TE_BaseFunction_BaseFunction_Main */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_BaseFunction_BaseFunction_Main;

/*! Alarm configuration data: Rte_Al_TE_DIA_DIA_cyclicProcessingTask */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_DIA_DIA_cyclicProcessingTask;

/*! Alarm configuration data: Rte_Al_TE_DiagFunction_DiagFunction_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_DiagFunction_DiagFunction_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms;

/*! Alarm configuration data: Rte_Al_TE_SBC_SBC_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SBC_SBC_MainFunction;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for alarms. */
extern CONSTP2CONST(Os_AlarmConfigType, OS_CONST, OS_CONST) OsCfg_AlarmRefs[OS_ALARMID_COUNT + 1];            /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ALARM_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Alarm_Lcfg.h
 *********************************************************************************************************************/
