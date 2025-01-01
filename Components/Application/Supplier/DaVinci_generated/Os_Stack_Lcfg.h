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
 *              File: Os_Stack_Lcfg.h
 *   Generation Time: 2023-10-11 10:58:55
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_STACK_LCFG_H
# define OS_STACK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Stack_Cfg.h"
# include "Os_Stack_Types.h"

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

# define OS_START_SEC_STACK_APPLTASK_CORE0_HIGHPRIO_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: ApplTask_Core0_HighPrio */
/* User: [ApplTask_Core0_HighPrio] */
extern OS_STACK_DECLARE(OsCfg_Stack_ApplTask_Core0_HighPrio_Dyn, OS_CFG_SIZE_APPLTASK_CORE0_HIGHPRIO_STACK);

# define OS_STOP_SEC_STACK_APPLTASK_CORE0_HIGHPRIO_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_APPLTASK_CORE0_LOWPRIO_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: ApplTask_Core0_LowPrio */
/* User: [ApplTask_Core0_LowPrio] */
extern OS_STACK_DECLARE(OsCfg_Stack_ApplTask_Core0_LowPrio_Dyn, OS_CFG_SIZE_APPLTASK_CORE0_LOWPRIO_STACK);

# define OS_STOP_SEC_STACK_APPLTASK_CORE0_LOWPRIO_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_BSWTASK_CORE0_HIGHPRIO_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: BswTask_Core0_HighPrio */
/* User: [BswTask_Core0_HighPrio] */
extern OS_STACK_DECLARE(OsCfg_Stack_BswTask_Core0_HighPrio_Dyn, OS_CFG_SIZE_BSWTASK_CORE0_HIGHPRIO_STACK);

# define OS_STOP_SEC_STACK_BSWTASK_CORE0_HIGHPRIO_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_BSWTASK_CORE0_LOWPRIO_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: BswTask_Core0_LowPrio */
/* User: [BswTask_Core0_LowPrio] */
extern OS_STACK_DECLARE(OsCfg_Stack_BswTask_Core0_LowPrio_Dyn, OS_CFG_SIZE_BSWTASK_CORE0_LOWPRIO_STACK);

# define OS_STOP_SEC_STACK_BSWTASK_CORE0_LOWPRIO_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core error stack: OsCore0_Error */
/* User: [ErrorHook_OsCore0, OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Error_Dyn, OS_CFG_SIZE_OSCORE0_ERROR_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore0_Init */
/* User: [OsCore0, Os_CoreInitHook_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Init_Dyn, OS_CFG_SIZE_OSCORE0_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore0_Isr_Core */
/* User: [CanIsr_1, CounterIsr_SystemTimer, RCM_PFlashEccFailure_Notification, RCM_SRamEccFailure_Notification, vHsmResponseIsr] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore0_Kernel */
/* User: [OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Kernel_Dyn, OS_CFG_SIZE_OSCORE0_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core shutdown stack: OsCore0_Shutdown */
/* User: [OsCore0, ShutdownHook_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Shutdown_Dyn, OS_CFG_SIZE_OSCORE0_SHUTDOWN_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio0 */
/* User: [BackgroundTask_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio0_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO0_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio100 */
/* User: [Default_Init_Task] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio100_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO100_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio4294967295 */
/* User: [IdleTask_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio5 */
/* User: [ApplBackgroundTask_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio5_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO5_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio90 */
/* User: [ApplInitTask_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio90_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO90_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO99_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio99 */
/* User: [Default_Init_Task_Trusted] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio99_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO99_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO99_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_ALV_BELTFUNCTIONALGO_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_ALV_BeltFunctionAlgo */
/* User: [OsTask_ALV_BeltFunctionAlgo] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_ALV_BeltFunctionAlgo_Dyn, OS_CFG_SIZE_OSTASK_ALV_BELTFUNCTIONALGO_STACK);

# define OS_STOP_SEC_STACK_OSTASK_ALV_BELTFUNCTIONALGO_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: ApplTask_Core0_HighPrio */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_ApplTask_Core0_HighPrio;

/*! Stack configuration data: ApplTask_Core0_LowPrio */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_ApplTask_Core0_LowPrio;

/*! Stack configuration data: BswTask_Core0_HighPrio */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_BswTask_Core0_HighPrio;

/*! Stack configuration data: BswTask_Core0_LowPrio */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_BswTask_Core0_LowPrio;

/*! Stack configuration data: OsCore0_Error */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Error;

/*! Stack configuration data: OsCore0_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Init;

/*! Stack configuration data: OsCore0_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Isr_Core;

/*! Stack configuration data: OsCore0_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Kernel;

/*! Stack configuration data: OsCore0_Shutdown */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Shutdown;

/*! Stack configuration data: OsCore0_Task_Prio0 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio0;

/*! Stack configuration data: OsCore0_Task_Prio100 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio100;

/*! Stack configuration data: OsCore0_Task_Prio4294967295 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio4294967295;

/*! Stack configuration data: OsCore0_Task_Prio5 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio5;

/*! Stack configuration data: OsCore0_Task_Prio90 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio90;

/*! Stack configuration data: OsCore0_Task_Prio99 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio99;

/*! Stack configuration data: OsTask_ALV_BeltFunctionAlgo */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_ALV_BeltFunctionAlgo;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_STACK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Lcfg.h
 *********************************************************************************************************************/
