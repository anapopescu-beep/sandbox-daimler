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
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Stack_Cfg.h
 *   Generation Time: 2023-04-06 15:03:16
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
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
# define OS_CFG_STACKMEASUREMENT                 (STD_OFF)

/* Configured stack sizes (Total: 23808 Byte) */
# define OS_CFG_SIZE_OSCORE0_ERROR_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_INIT_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_KERNEL_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_SHUTDOWN_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_STARTUP_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO10_STACK     (4096u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO20_STACK     (4096u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967293_STACK     (256u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967294_STACK     (4096u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK     (1024u)
# define OS_CFG_SIZE_VHSMMAINFUNCTIONTASK_STACK     (4096u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_STACK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Cfg.h
 *********************************************************************************************************************/
