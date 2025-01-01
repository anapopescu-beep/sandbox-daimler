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
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000614_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ..\Include\SchM_Crypto_30_vHsm.h
 *   Generation Time: 2022-02-24 16:08:15
 *           Project: CBD2000614_FblEth - Version 1.0
 *          Delivery: CBD2000614_D04
 *      Tool Version: DaVinci Configurator (beta) 5.24.36 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 * Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

#ifndef SCHM_CRYPTO_30_VHSM_H
# define SCHM_CRYPTO_30_VHSM_H

# include "Os.h"

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "Std_Types.h"

# define CRYPTO_30_VHSM_START_SEC_CODE
# include "MemMap.h"

FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_MainFunction(void);

# define CRYPTO_30_VHSM_STOP_SEC_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

# define SchM_Enter_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_0() SuspendAllInterrupts()
# define SchM_Exit_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_0() ResumeAllInterrupts()

# define SchM_Enter_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_1() SuspendAllInterrupts()
# define SchM_Exit_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_1() ResumeAllInterrupts()

# define SchM_Enter_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_2() SuspendAllInterrupts()
# define SchM_Exit_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_2() ResumeAllInterrupts()

# define SchM_Enter_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_3() SuspendAllInterrupts()
# define SchM_Exit_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_3() ResumeAllInterrupts()

#endif /* SCHM_CRYPTO_30_VHSM_H */
