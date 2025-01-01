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
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: .\vBrsCfg.h
 *   Generation Time: 2023-07-10 14:36:13
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

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

#define BRS_GENERATED_HW_CONFIG_VERSION 385U

/*******************************************************************************
 Standard BRS configuration
*******************************************************************************/
/*******************************************************************************
 Generic TestSuite Support
 *******************************************************************************/
/* Enable support of the Generic TestSuite connection.
   Via the define BRS_ENABLE_TESTSUITE_SUPPORT, the Generic TestSuite concept 
   headerfile BrsTestsuite.h will be included and the Generic Testsuite init 
   function BrsTestsuiteInit() will be called within BrsMain.c. */
/* Testsuite support is disabled (#define BRS_ENABLE_TESTSUITE_SUPPORT) */

/* TCC support is disabled (#define BRS_ENABLE_TCC_COMIF_SUPPORT) */

/* LED support is disabled (#define BRS_ENABLE_SUPPORT_LEDS) */

/* Toggle custom pin support is disabled (#define BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN) */

/* Toggle watchdog pin support is disabled (#define BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN) */


/* Not the first execution instance of BRS within the system. 
   (#define BRS_FIRST_EXECUTION_INSTANCE) */

/*******************************************************************************
 Additional BRS support features
*******************************************************************************/
/* Enable support of SafeContext OS (used for OS partitioning UseCase). */
/* SafeContext support is disabled (#define BRS_ENABLE_SAFECTXSUPPORT) */

/* Enable support of MultiCore OS. */
/* MultiCore OS support is disabled (#define BRS_ENABLE_OS_MULTICORESUPPORT) */

/* Switches to enable support of FlashBootLoader and to define the FBL Type. */
/* FlashBootLoader support is disabled (#define BRS_ENABLE_FBL_SUPPORT) */

/* Switch to enable support of Hardware Security Module (HSM). */
/* HSM support is disabled (#define BRS_ENABLE_HSM_SUPPORT) */

/* Switch to enable support of OS UseCase "Interrupt Only". */
/* OS UseCase "Interrupt Only" is disabled (#define BRS_ENABLE_OS_INTERRUPT_ONLY) */

/*******************************************************************************
 BRS hardware configuration constants
*******************************************************************************/
/* Frequency of the board specific external oscillator. */
/* Main Oscillator Clock (MHz) */
#define BRS_OSC_CLK 20

/* Frequency, used for PLL calculation (normally used as CPU core clock). */
/* Timebase Clock (MHz) */
#define BRS_TIMEBASE_CLOCK 160

/* Frequency of the controller peripherals, at least for the default timer, used by the OS.
   This frequency value is used to calculate the proper value of the TicksPerBase value inside 
   the OS configuration.
   If the frequencies for communication peripherals differ from this peripheral clock, 
   they could be configured within the depending communictaion channel configuration 
   (e.g. vBRSHwConfig/vBRSDriverHandlingCAN/vBRSDriverHandlingCAN_Clock). */
/* Peripheral Clock (MHz) */
#define BRS_PERIPH_CLOCK 80

/* Frequency, used for PLL calculation of CAN driver peripheral clock. */
/* CAN Clock (MHz) */
#define BRS_CAN_CLOCK 80

/*******************************************************************************
 BRS software modules
*******************************************************************************/
/* Enable the handling of Watchdog configuration inside BrsHw. */
#define BRS_ENABLE_WATCHDOG

/*******************************************************************************
 BRS communication interface configuration
*******************************************************************************/
/* This switch enables the handling of driver specific settings of
  - PLL and clock settings
  - Port Pin settings
  - On some platforms additional register settings, e.g. inside 
    BrsHwPreInitPowerOn() or BrsHw_EnableHwAccess()
*/
#define BRS_ENABLE_CAN_SUPPORT


/*******************************************************************************
 Tested Derivative: Infineon Aurix 2G TC32x Family
*******************************************************************************/
#define BRS_DERIVATIVE_TC32x

/*******************************************************************************
 CPU Core
 possible values are:
 BRS_CPU_CORE_OTHER: Generic value for cores with no specific value
 BRS_CPU_CORE_CORTEX_M0: Arm Cortex M0
 BRS_CPU_CORE_CORTEX_M0PLUS: Arm Cortex M0+
 BRS_CPU_CORE_CORTEX_M3: Arm Cortex M3
 BRS_CPU_CORE_CORTEX_M4: Arm Cortex M4
 BRS_CPU_CORE_CORTEX_M4F: Arm Cortex M4F
 BRS_CPU_CORE_CORTEX_M7: Arm Cortex M7
 BRS_CPU_CORE_CORTEX_M33: Arm Cortex M33
 BRS_CPU_CORE_CORTEX_R4: Arm Cortex R4
 BRS_CPU_CORE_CORTEX_R4F: Arm Cortex R4F
 BRS_CPU_CORE_CORTEX_R5: ARM Cortex R5
 BRS_CPU_CORE_CORTEX_R5F: Arm Cortex R5F
 BRS_CPU_CORE_CORTEX_R7: ARM Cortex R7
 BRS_CPU_CORE_CORTEX_R52: Arm Cortex R52
 BRS_CPU_CORE_E200Z0: NXP/ST PowerPC RISC Core e200z0
 BRS_CPU_CORE_E200Z210: NXP/ST PowerPC RISC Core e200z210
 BRS_CPU_CORE_E200Z215: NXP/ST PowerPC RISC Core e200z215
 BRS_CPU_CORE_E200Z225: NXP/ST PowerPC RISC Core e200z225
 BRS_CPU_CORE_E200Z410: NXP/ST PowerPC RISC Core e200z410
 BRS_CPU_CORE_E200Z420: NXP/ST PowerPC RISC Core e200z420
 BRS_CPU_CORE_E200Z425: NXP/ST PowerPC RISC Core e200z425
 BRS_CPU_CORE_E200Z710: NXP/ST PowerPC RISC Core e200z710
 BRS_CPU_CORE_E200Z720: NXP/ST PowerPC RISC Core e200z720
 BRS_CPU_CORE_E200Z726: NXP/ST PowerPC RISC Core e200z726
 BRS_CPU_CORE_E200Z759: NXP/ST PowerPC RISC Core e200z759
 BRS_CPU_CORE_G3K: Renesas G3K
 BRS_CPU_CORE_G3KH: Renesas G3KH
 BRS_CPU_CORE_G3M: Renesas G3M
 BRS_CPU_CORE_G4MH: Renesas G4MH
 BRS_CPU_CORE_TC161: Infineon TriCore Aurix Core
 BRS_CPU_CORE_TC162: Infineon TriCore AurixPlus Core
 BRS_CPU_CORE_TC18: Infineon TriCore Aurix 3G (TC4xx)
*******************************************************************************/
#define BRS_CPU_CORE_TC162

/*******************************************************************************
 CPU Max Frequency (MHz)
*******************************************************************************/
/* Configure the maximum frequency of this derivative.
   This value is used to validate the vBRS PLL configuration. */
#define BRS_CPU_MAX_FREQUENCY 160

/*******************************************************************************
 CPU Core Amount (number of cores)
*******************************************************************************/
/* Configure the amount of cores, available on this derivative. */
#define BRS_CPU_CORE_AMOUNT 1

/*******************************************************************************
 Derivative Group
*******************************************************************************/
/* This parameter allows to group the implementation for several derivatives. */
#define BRS_DERIVATIVE_GROUP_TC3xx

/*******************************************************************************
 Pll Group
*******************************************************************************/
/* This parameter allows to group the implementation for several derivatives. */
#define BRS_PLL_GROUP_B

/*******************************************************************************
 Port Group
*******************************************************************************/
/* This parameter allows to group the implementation for several derivatives. */
#define BRS_PORT_GROUP_B

/*******************************************************************************
 Reset Group
*******************************************************************************/
/* This parameter allows to group the implementation for several derivatives. */
#define BRS_RESET_GROUP_B

/*******************************************************************************
 Watchdog Group
*******************************************************************************/
/* This parameter allows to group the implementation for several derivatives. */
#define BRS_WATCHDOG_GROUP_B

/*******************************************************************************
 Init Patterns
*******************************************************************************/
/* Configure the init pattern for the Brs_MemoryZeroInit() call within 
   Brs_ApplicationEntry().
   This value is for the blocks, configured with "Init Policy" = ZERO_INIT and 
   a "Init Stage" from ZERO up to THREE within the vLinkGen configuration.
   The pattern must be 32-bit aligned. Default value is 0x0. */
#define BRS_INIT_PATTERN_BLOCKS (0x0UL)

/* Configure the init pattern for the Brs_MemoryZeroInit() call within 
   Brs_ApplicationEntry().
   This value is for the blocks, configured with "Init Policy" = ZERO_INIT and 
   the "Init Stage" HARD_RESET_ONLY within the vLinkGen configuration.
   The pattern must be 32-bit aligned. Default value is 0x0. */
#define BRS_INIT_PATTERN_HARDRESET_BLOCKS (0x0UL)

/* Configure the init pattern for the Brs_MemoryZeroInit() call within 
   Brs_ApplicationEntry().
   This value is for the groups, configured with "Init Policy" = ZERO_INIT and 
   a "Init Stage" from ZERO up to THREE within the vLinkGen configuration.
   The pattern must be 32-bit aligned. Default value is 0x0. */
#define BRS_INIT_PATTERN_AREAS (0x0UL)

/* Configure the init pattern for the Brs_MemoryZeroInit() call within
   Brs_ApplicationEntry().
   This value is for the groups, configured with "Init Policy" = ZERO_INIT and 
   the "Init Stage" HARD_RESET_ONLY within the vLinkGen configuration.
   The pattern must be 32-bit aligned. Default value is 0x0. */
#define BRS_INIT_PATTERN_HARDRESET_AREAS (0x0UL)

/*******************************************************************************
 DrvCan Handling
*******************************************************************************/
/* These are macros to also support DrvCan modules with infixing 
   (e.g. Can_30_Mcan). 
   They are used by the UserDefined ExclusiveArea handling for CAN channels 
   in BrsMain.c. 
   The implementation is according to CanDriver ApplicationNote AN-ISC-8-1149 */
#define BRS_DRVCAN_HEADER_FILENAME "Can.h"
#define BRS_DRVCAN_EXCLUSIVE_AREA_INFIX(a, b) void SchM_##a##_Can_CAN_##b(void)
#define BRS_DRVCAN_ControllerInterrupts_INFIX(a) Can_##a##ControllerInterrupts

#endif /*_VBRSCFG_H_*/

/* The following lines are needed for the UserDefined ExclusiveArea handling
   for CAN channels , according to AN-ISC-8-1149, implemented in BrsMain.c. 
   To support drivers with infix and there name specific MemMap sections, 
   this will forward the correct MemMap defines to the MemMap.h file. */
   
#ifdef CAN_START_SEC_CODE
#include "MemMap.h"
#endif

#ifdef CAN_STOP_SEC_CODE
#include "MemMap.h"
#endif

#ifdef CAN_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"
#endif

#ifdef CAN_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"
#endif

