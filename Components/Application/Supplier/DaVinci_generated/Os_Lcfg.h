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
 *              File: Os_Lcfg.h
 *   Generation Time: 2023-10-05 14:21:23
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_LCFG_H
# define OS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Lcfg.h"

/* User file includes */


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

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_ApplBackgroundTask_Core0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ApplBackgroundTask_Core0()
 *********************************************************************************************************************/
extern FUNC(void, OS_APPLBACKGROUNDTASK_CORE0_CODE) Os_Task_ApplBackgroundTask_Core0(void);

# define OS_STOP_SEC_ApplBackgroundTask_Core0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_ApplInitTask_Core0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ApplInitTask_Core0()
 *********************************************************************************************************************/
extern FUNC(void, OS_APPLINITTASK_CORE0_CODE) Os_Task_ApplInitTask_Core0(void);

# define OS_STOP_SEC_ApplInitTask_Core0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_ApplTask_Core0_HighPrio_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ApplTask_Core0_HighPrio()
 *********************************************************************************************************************/
extern FUNC(void, OS_APPLTASK_CORE0_HIGHPRIO_CODE) Os_Task_ApplTask_Core0_HighPrio(void);

# define OS_STOP_SEC_ApplTask_Core0_HighPrio_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_ApplTask_Core0_LowPrio_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ApplTask_Core0_LowPrio()
 *********************************************************************************************************************/
extern FUNC(void, OS_APPLTASK_CORE0_LOWPRIO_CODE) Os_Task_ApplTask_Core0_LowPrio(void);

# define OS_STOP_SEC_ApplTask_Core0_LowPrio_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_BackgroundTask_Core0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  BackgroundTask_Core0()
 *********************************************************************************************************************/
extern FUNC(void, OS_BACKGROUNDTASK_CORE0_CODE) Os_Task_BackgroundTask_Core0(void);

# define OS_STOP_SEC_BackgroundTask_Core0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_BswTask_Core0_HighPrio_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  BswTask_Core0_HighPrio()
 *********************************************************************************************************************/
extern FUNC(void, OS_BSWTASK_CORE0_HIGHPRIO_CODE) Os_Task_BswTask_Core0_HighPrio(void);

# define OS_STOP_SEC_BswTask_Core0_HighPrio_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_BswTask_Core0_LowPrio_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  BswTask_Core0_LowPrio()
 *********************************************************************************************************************/
extern FUNC(void, OS_BSWTASK_CORE0_LOWPRIO_CODE) Os_Task_BswTask_Core0_LowPrio(void);

# define OS_STOP_SEC_BswTask_Core0_LowPrio_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Default_Init_Task_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Default_Init_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_INIT_TASK_CODE) Os_Task_Default_Init_Task(void);

# define OS_STOP_SEC_Default_Init_Task_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Default_Init_Task_Trusted_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Default_Init_Task_Trusted()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_INIT_TASK_TRUSTED_CODE) Os_Task_Default_Init_Task_Trusted(void);

# define OS_STOP_SEC_Default_Init_Task_Trusted_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_ALV_BeltFunctionAlgo_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_ALV_BeltFunctionAlgo()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_ALV_BELTFUNCTIONALGO_CODE) Os_Task_OsTask_ALV_BeltFunctionAlgo(void);

# define OS_STOP_SEC_OsTask_ALV_BeltFunctionAlgo_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsr_1_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsr_1()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISR_1_CODE) Os_Isr_CanIsr_1(void);

# define OS_STOP_SEC_CanIsr_1_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_RCM_PFlashEccFailure_Notification_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  RCM_PFlashEccFailure_Notification()
 *********************************************************************************************************************/
extern FUNC(void, OS_RCM_PFLASHECCFAILURE_NOTIFICATION_CODE) Os_Isr_RCM_PFlashEccFailure_Notification(void);

# define OS_STOP_SEC_RCM_PFlashEccFailure_Notification_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_RCM_SRamEccFailure_Notification_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  RCM_SRamEccFailure_Notification()
 *********************************************************************************************************************/
extern FUNC(void, OS_RCM_SRAMECCFAILURE_NOTIFICATION_CODE) Os_Isr_RCM_SRamEccFailure_Notification(void);

# define OS_STOP_SEC_RCM_SRamEccFailure_Notification_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_vHsmResponseIsr_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmResponseIsr()
 *********************************************************************************************************************/
extern FUNC(void, OS_VHSMRESPONSEISR_CODE) Os_Isr_vHsmResponseIsr(void);

# define OS_STOP_SEC_vHsmResponseIsr_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Lcfg.h
 *********************************************************************************************************************/
