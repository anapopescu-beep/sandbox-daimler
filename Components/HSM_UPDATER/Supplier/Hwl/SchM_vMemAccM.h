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
 *           Program: HSM_Vector_SLP1
 *          Customer: Huizhou Desay SVAutomotive Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC397 B-Step
 *    License Scope : The usage is restricted to CBD2100788_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ..\Include\SchM_vMemAccM.h
 *   Generation Time: 2021-09-26 14:36:57
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2100788_D00
 *      Tool Version: DaVinci Configurator  5.24.21
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

#ifndef SCHM_VMEMACCM_H
# define SCHM_VMEMACCM_H

# include "BrsMain.h"

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "Std_Types.h"

# define VMEMACCM_START_SEC_CODE
# include "MemMap.h"

FUNC(void, VMEMACCM_CODE) vMemAccM_MainFunction(void);

# define VMEMACCM_STOP_SEC_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

# define SchM_Enter_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0() BrsMainSuspendAllInterrupts()
# define SchM_Exit_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0() BrsMainResumeAllInterrupts()

#endif /* SCHM_VMEMACCM_H */
