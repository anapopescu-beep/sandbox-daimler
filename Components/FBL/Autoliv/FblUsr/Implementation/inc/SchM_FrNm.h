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
 *              File: ..\Include\SchM_FrNm.h
 *   Generation Time: 2020-10-21 09:38:52
 *           Project: CBD2000614_FblFlexray - Version 1.0
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

#ifndef SCHM_FRNM_H
# define SCHM_FRNM_H

# include "Os.h"

void FrNm_MainFunction_0(void);

# define SchM_Enter_FrNm_FRNM_EXCLUSIVE_AREA_0() SuspendAllInterrupts()
# define SchM_Exit_FrNm_FRNM_EXCLUSIVE_AREA_0() ResumeAllInterrupts()

# define SchM_Enter_FrNm_FRNM_EXCLUSIVE_AREA_1() SuspendAllInterrupts()
# define SchM_Exit_FrNm_FRNM_EXCLUSIVE_AREA_1() ResumeAllInterrupts()

# define SchM_Enter_FrNm_FRNM_EXCLUSIVE_AREA_2() SuspendAllInterrupts()
# define SchM_Exit_FrNm_FRNM_EXCLUSIVE_AREA_2() ResumeAllInterrupts()

# define SchM_Enter_FrNm_FRNM_EXCLUSIVE_AREA_3() SuspendAllInterrupts()
# define SchM_Exit_FrNm_FRNM_EXCLUSIVE_AREA_3() ResumeAllInterrupts()

# define SchM_Enter_FrNm_FRNM_EXCLUSIVE_AREA_4() SuspendAllInterrupts()
# define SchM_Exit_FrNm_FRNM_EXCLUSIVE_AREA_4() ResumeAllInterrupts()

# define SchM_Enter_FrNm_FRNM_EXCLUSIVE_AREA_5() SuspendAllInterrupts()
# define SchM_Exit_FrNm_FRNM_EXCLUSIVE_AREA_5() ResumeAllInterrupts()

# define SchM_Enter_FrNm_FRNM_EXCLUSIVE_AREA_6() SuspendAllInterrupts()
# define SchM_Exit_FrNm_FRNM_EXCLUSIVE_AREA_6() ResumeAllInterrupts()

#endif /* SCHM_FRNM_H */
