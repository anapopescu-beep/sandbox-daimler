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
 *            Module: vBRS
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to -
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ..\Include\SchM_vHsm.h
 *   Generation Time: 2020-04-24 07:47:28
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: -
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/

#ifndef SCHM_VHSM_H
# define SCHM_VHSM_H

# include "Os.h"

void vHsm_MainFunction(void);

# define SchM_Enter_vHsm_VHSM_EXCLUSIVE_AREA_0() SuspendAllInterrupts()
# define SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_0() ResumeAllInterrupts()

#endif /* SCHM_VHSM_H */
