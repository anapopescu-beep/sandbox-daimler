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
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000612_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: .\vBrsCfg.h
 *   Generation Time: 2022-04-13 13:52:50
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2000612_D04
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

#ifndef _VBRSCFG_H_
#define _VBRSCFG_H_

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#if !defined (BRS_INCLUDED_BY_ASM_FILE)
# include "Std_Types.h"
#endif

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#define BASIC_RUNTIME_SYSTEM_TYPE_MSR4

#define BRS_GENERATED_HW_CONFIG_VERSION 362U

/*******************************************************************************
 Standard BRS configuration
*******************************************************************************/
/* Testsuite support is disabled (#define BRS_ENABLE_TESTSUITE_SUPPORT) */

/* TCC support is disabled (#define BRS_ENABLE_TCC_COMIF_SUPPORT) */

/* LED support is disabled (#define BRS_ENABLE_SUPPORT_LEDS) */

/* Toggle custom pin support is disabled (#define BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN) */

/* Toggle watchdog pin support is disabled (#define BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN) */


/*******************************************************************************
 Additional BRS support features
*******************************************************************************/
/* Switch to enable support of SafeContext OS */
/* SafeContext support is disabled (#define BRS_ENABLE_SAFECTXSUPPORT) */

/* Switch to enable support of MultiCore OS */
/* MultiCore OS support is disabled (#define BRS_ENABLE_OS_MULTICORESUPPORT) */

/* Switches to enable support of FlashBootLoader and to define the FBL Type */
/* FlashBootLoader support is disabled (#define BRS_ENABLE_FBL_SUPPORT) */

/* Switch to enable support of Hardware Security Module (HSM) */
#define BRS_ENABLE_HSM_SUPPORT

/* Switch to enable support of OS UseCase "Interrupt Only" */
#define BRS_ENABLE_OS_INTERRUPT_ONLY

/*******************************************************************************
 BRS hardware configuration constants
*******************************************************************************/
/* Main Oscillator Clock (MHz) */
#define BRS_OSC_CLK 20

/* Timebase Clock (Hz) */
#define BRS_TIMEBASE_CLOCK 6250000

/* Peripheral Clock (MHz) */
#define BRS_PERIPH_CLOCK 100

/*******************************************************************************
 BRS software modules
*******************************************************************************/
#define BRS_ENABLE_WATCHDOG
#define BRS_ENABLE_PLLCLOCKS

/*******************************************************************************
 Tested Derivative: Infineon Aurix TC3xx Family - HSM Core
*******************************************************************************/
#define BRS_DERIVATIVE_TC3xx

/*******************************************************************************
 CPU Core
*******************************************************************************/
#define BRS_CPU_CORE_CORTEX_M3

/*******************************************************************************
 CPU Max Frequency (Hz)
*******************************************************************************/
#define BRS_CPU_MAX_FREQUENCY 6250000

/*******************************************************************************
 CPU Core Amount (number of cores)
*******************************************************************************/
#define BRS_CPU_CORE_AMOUNT 1

/*******************************************************************************
 Instruction Set
*******************************************************************************/
#define BRS_INSTRUCTION_SET_THUMB

/*******************************************************************************
 Init Patterns
*******************************************************************************/
#define BRS_INIT_PATTERN_BLOCKS (0x0UL)
#define BRS_INIT_PATTERN_HARDRESET_BLOCKS (0x0UL)
#define BRS_INIT_PATTERN_AREAS (0x0UL)
#define BRS_INIT_PATTERN_HARDRESET_AREAS (0x0UL)

#endif /*_VBRSCFG_H_*/

