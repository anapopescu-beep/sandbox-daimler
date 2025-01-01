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
 *              File: Os_TimingProtection_Cfg.h
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
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
