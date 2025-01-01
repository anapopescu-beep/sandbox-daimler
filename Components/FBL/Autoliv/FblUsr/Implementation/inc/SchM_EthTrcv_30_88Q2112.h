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
 *    License Scope : The usage is restricted to CBD2000614_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ..\Include\SchM_EthTrcv_30_88Q2112.h
 *   Generation Time: 2020-10-21 09:38:27
 *           Project: CBD2000614_FblEth - Version 1.0
 *          Delivery: CBD2000614_D00
 *      Tool Version: DaVinci Configurator (beta) 5.22.35 SP1
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

#ifndef SCHM_ETHTRCV_30_88Q2112_H
# define SCHM_ETHTRCV_30_88Q2112_H

# include "Os.h"

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "Std_Types.h"

# define ETHTRCV_30_88Q2112_START_SEC_CODE
# include "MemMap.h"

FUNC(void, ETHTRCV_30_88Q2112_CODE) EthTrcv_30_88Q2112_MainFunction(void);
FUNC(void, ETHTRCV_30_88Q2112_CODE) EthTrcv_30_88Q2112_MainFunctionLinkHandling(void);

# define ETHTRCV_30_88Q2112_STOP_SEC_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

# define SchM_Enter_EthTrcv_30_88Q2112_ETHTRCV_30_88Q2112_EXCLUSIVE_AREA_SEQUENCE() SuspendAllInterrupts()
# define SchM_Exit_EthTrcv_30_88Q2112_ETHTRCV_30_88Q2112_EXCLUSIVE_AREA_SEQUENCE() ResumeAllInterrupts()

#endif /* SCHM_ETHTRCV_30_88Q2112_H */
