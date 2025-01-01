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
 *              File: ..\Include\EcuM_Generated_Types.h
 *   Generation Time: 2022-02-21 13:41:16
 *           Project: CBD2000614_Upd - Version 1.0
 *          Delivery: CBD2000614_D04
 *      Tool Version: DaVinci Configurator (beta) 5.24.30 SP1
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
/***************************************************************************************************
 * Note:
 * The use of this file or any part of this file is limited to vBRS.
 * The file may be incomplete with respect to ASR Module requirements, defined by the
 * AUTOSAR Standard.
 ***************************************************************************************************/

#if !defined(ECUM_GENERATED_TYPES_H)
#define ECUM_GENERATED_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! This type is a 32bit bitmask where each bit represents a wakeup source. */
typedef uint32 EcuM_WakeupSourceType;

/* ------------------------------------- Symbolic Name Defines for EcuM_WakeupSourceType ---------------------------- */
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_POWER          (0UL) 
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_RESET          (1UL)
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_INTERNAL_RESET (2UL) 
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_INTERNAL_WDG   (3UL)
#define EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_EXTERNAL_WDG   (4UL)
 
/* ------------------------------------- Range of EcuM_WakeupSourceType -------------------------------------------- */
#define ECUM_WKSOURCE_NONE (EcuM_WakeupSourceType)(0x00000000UL)
#define ECUM_WKSOURCE_ALL_SOURCES (~((EcuM_WakeupSourceType)0UL))
#define ECUM_WKSOURCE_EcuMWakeupSource_LIN (EcuM_WakeupSourceType)(31UL)
#define ECUM_WKSOURCE_ECUM_WKSOURCE_INTERNAL_WDG (EcuM_WakeupSourceType)(3UL)
#define ECUM_WKSOURCE_ECUM_WKSOURCE_POWER (EcuM_WakeupSourceType)(0UL)
#define ECUM_WKSOURCE_ECUM_WKSOURCE_RESET (EcuM_WakeupSourceType)(1UL)
#define ECUM_WKSOURCE_ECUM_WKSOURCE_INTERNAL_RESET (EcuM_WakeupSourceType)(2UL)
#define ECUM_WKSOURCE_ECUM_WKSOURCE_EXTERNAL_WDG (EcuM_WakeupSourceType)(4UL)

#endif /* ECUM_GENERATED_TYPES_H */

