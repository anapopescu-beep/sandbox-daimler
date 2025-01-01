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
 *              File: Os_Core_Cfg.h
 *   Generation Time: 2023-04-06 15:03:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

#ifndef OS_CORE_CFG_H
# define OS_CORE_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether all the threads use the FPU unit (STD_ON) or not (STD_OFF). */
# define OS_CFG_THREAD_FPU_CONTEXT_FOR_ALL_THREADS_ENABLED       (STD_OFF)

/*! Defines whether the FPU context support is enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_THREAD_FPU_CONTEXT_ENABLED                       (STD_OFF)

/*! Defines whether at least for one core a PreStartTask is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_OS_PRESTARTTASK                                  (STD_OFF)

/*! Number of user barriers. */
# define OS_CFG_NUM_BARRIERS                                     (0u)

/*! Number of ISR2 nesting levels. */
# define OS_CFG_NUM_ISRLEVELS                                    (2u)

/*! Number of all spinlocks. */
# define OS_CFG_NUM_SYSTEM_SPINLOCKS                             (0u)

/*! Number of physical core identifiers. */
# define OS_CFG_COREPHYSICALID_COUNT                             (1u)

/* Number of core objects: OsCore0 */
# define OS_CFG_NUM_CORE_OSCORE0_APPS             (0u)
# define OS_CFG_NUM_CORE_OSCORE0_HOOKS            (4u)
# define OS_CFG_NUM_CORE_OSCORE0_IOCS             (0u)
# define OS_CFG_NUM_CORE_OSCORE0_RESOURCES        (0u)
# define OS_CFG_NUM_CORE_OSCORE0_STACKS           (12u)
# define OS_CFG_NUM_CORE_OSCORE0_ISRS             (2u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_CORE_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Core_Cfg.h
 *********************************************************************************************************************/

