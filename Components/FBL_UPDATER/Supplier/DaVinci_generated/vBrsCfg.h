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
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: .\vBrsCfg.h
 *   Generation Time: 2023-07-24 13:42:12
 *           Project: CBD2000614_Upd - Version 1.0
 *          Delivery: CBD2200332_D02
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


/*******************************************************************************
 First execution instance of BRS
 *******************************************************************************/
/* Configure, if this executable is the first instance of the system.
   Set this parameter to enabled, if this instance should contain the 
   brsStartupEntry and initialize the core.
   Only one single executable of a system with several executables should be the 
   first instance. All other executables are starting with Brs_ApplicationEntry().
   E.g. in a FBL UseCase with standalone BM, the BM is the first executable and 
   the FBL, Updater, MSR-Application are not.
   If there is only a single executable in the system, of course this application 
   is also the first one. */
#define BRS_FIRST_EXECUTION_INSTANCE

/*******************************************************************************
 Additional BRS support features
*******************************************************************************/
/* Enable support of SafeContext OS (used for OS partitioning UseCase). */
/* SafeContext support is disabled (#define BRS_ENABLE_SAFECTXSUPPORT) */

/* Enable support of MultiCore OS. */
/* MultiCore OS support is disabled (#define BRS_ENABLE_OS_MULTICORESUPPORT) */

/* Switches to enable support of FlashBootLoader and to define the FBL Type. */
#define BRS_ENABLE_FBL_SUPPORT
/* Definition of the FBL Execution Instance. */
#define BRS_FBL_INSTANCE_FBL
/* Configure, if the FBL stack should be started inside main() via a call 
   of EcuM_Init() or a call of FblMain().
   This parameter only has an effect, if Execution Instance is "FBL", 
   "FBL_Updater", "BM" or "BM_FBL".
   FBL without EcuM_Init() is the oldstyle FBL integration, started with 
   a direct call of FblMain().
   FBL with EcuM_Init() means, module initialization is done in EcuM_Init() 
   (real EcuM or EcuM Stub), but the cyclic handling is done in FBL. */
#define BRS_FBL_WITH_ECUMINIT
/* Configure, if the additional ExceptionTable in RAM should be initialized.
   This will cause a call of BrsHw_ExceptionTable_Init() in main(), which 
   will program the vector table base address to Brs_ExcVectRam. The 
   depending SectionGroup needs to be configured with Init Policy COPY_TO_RAM 
   in vLinkGen as well.
   This allows proper exception handling during erase/re-program of flash. */
#define BRS_FBL_EXCEPTIONTABLE_IN_RAM

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
#define BRS_TIMEBASE_CLOCK 100

/* Frequency of the controller peripherals, at least for the default timer, used by the OS.
   This frequency value is used to calculate the proper value of the TicksPerBase value inside 
   the OS configuration.
   If the frequencies for communication peripherals differ from this peripheral clock, 
   they could be configured within the depending communictaion channel configuration 
   (e.g. vBRSHwConfig/vBRSDriverHandlingCAN/vBRSDriverHandlingCAN_Clock). */
/* Peripheral Clock (MHz) */
#define BRS_PERIPH_CLOCK 20

/*******************************************************************************
 BRS software modules
*******************************************************************************/
/* Enable the handling of Watchdog configuration inside BrsHw. */
#define BRS_ENABLE_WATCHDOG

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

#endif /*_VBRSCFG_H_*/

