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
 *              File: Os_MemoryProtection_Cfg.h
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

#ifndef OS_MEMORYPROTECTION_CFG_H
# define OS_MEMORYPROTECTION_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether memory protection is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_MEMORY_PROTECTION                          (STD_OFF)

/*! Defines whether access rights switching for applications is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_MEMORY_PROTECTION_FOR_APPLICATIONS         (STD_OFF)

/*! Defines whether access rights switching for threads is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_MEMORY_PROTECTION_FOR_THREADS              (STD_OFF)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_MEMORYPROTECTION_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_MemoryProtection_Cfg.h
 *********************************************************************************************************************/
