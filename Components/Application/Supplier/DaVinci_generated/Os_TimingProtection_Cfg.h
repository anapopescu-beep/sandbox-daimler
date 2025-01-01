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
 *              File: Os_TimingProtection_Cfg.h
 *   Generation Time: 2023-07-10 14:36:15
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_TIMINGPROTECTION_CFG_H
# define OS_TIMINGPROTECTION_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SWITCHES
 *********************************************************************************************************************/
/*! \variation Defines whether timing protection module is active:
 *     OS_CFG_TP_NO_CORE     No timing protection configured on any ASR core.
 *     OS_CFG_TP_SOME_CORES  Timing protection configured on some ASR cores.
 *     OS_CFG_TP_ALL_CORES   Timing protection configured for all ASR cores.
 */
# define OS_CFG_TIMING_PROTECTION                (OS_CFG_TP_NO_CORE)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_TIMINGPROTECTION_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_TimingProtection_Cfg.h
 *********************************************************************************************************************/
