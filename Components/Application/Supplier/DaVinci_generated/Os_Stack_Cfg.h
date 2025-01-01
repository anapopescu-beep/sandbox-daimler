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
 *              File: Os_Stack_Cfg.h
 *   Generation Time: 2024-03-01 08:50:29
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_STACK_CFG_H
# define OS_STACK_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether stack monitoring is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMONITORING                  (STD_ON)

/*! Defines whether stack measurement is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMEASUREMENT                 (STD_ON)

/* Configured stack sizes (Total: 23360 Byte) */
# define OS_CFG_SIZE_APPLTASK_CORE0_HIGHPRIO_STACK     (512u)
# define OS_CFG_SIZE_APPLTASK_CORE0_LOWPRIO_STACK     (1536u)
# define OS_CFG_SIZE_BSWTASK_CORE0_HIGHPRIO_STACK     (2048u)
# define OS_CFG_SIZE_BSWTASK_CORE0_LOWPRIO_STACK     (4096u)
# define OS_CFG_SIZE_OSCORE0_ERROR_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_INIT_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_KERNEL_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_SHUTDOWN_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO0_STACK     (3584u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO100_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK     (64u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO5_STACK     (4096u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO90_STACK     (512u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO99_STACK     (256u)
# define OS_CFG_SIZE_OSTASK_ALV_BELTFUNCTIONALGO_STACK     (512u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_STACK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Cfg.h
 *********************************************************************************************************************/
