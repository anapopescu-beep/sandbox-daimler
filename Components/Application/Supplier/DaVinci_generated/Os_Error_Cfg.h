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
 *              File: Os_Error_Cfg.h
 *   Generation Time: 2023-07-10 14:36:12
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_ERROR_CFG_H
# define OS_ERROR_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether Os assertions are active (STD_ON) or not (STD_OFF). */
# define OS_CFG_ASSERTIONS                       (STD_OFF)

/*! Defines whether OSEK extended checks are active (STD_ON) or not (STD_OFF). */
# define OS_CFG_EXTENDED_STATUS                  (STD_ON)

/*! Defines whether forcible termination (killing) is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_KILLING                          (STD_OFF)

/*! Defines whether AUTOSAR service checks are active (STD_ON) or not (STD_OFF). */
# define OS_CFG_SERVICE_PROTECTION               (STD_OFF)

/*! Defines whether internal exception detection is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_INTERNAL_EXCEPTION_DETECTION     (STD_ON)

/*! Defines the number of Os code sections. */
# define OS_CFG_NUM_OSCODE_SECTIONS              (1u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_ERROR_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Error_Cfg.h
 *********************************************************************************************************************/
