/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file  File:  BrsMain.h
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsMain
 *
 *  \brief Description:  Main header of BRS contains
 *                       - Main function (called from StartUpCode and calls stack entry EcuM_Init())
 *                       - Call of BrsHw HW initialization routines
 *                       - 1ms handler, with support of cycle functions with several cycle times
 *                       - Exception handling
 *                       - Default_Init_Task, Main and Background Task which can be used by the operating system
 *
 *  \attention Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Description
 *  --------  ----------  ------  -------------------------------------------------------------------------------------
 *  01.00.00  2018-03-20  visbwa  Initial creation of new BRS code basis
 *            2018-03-27  visbwa  Renamed BrsAsrStartup into BrsStartup, added version check, reworked includes,
 *                                added example code text in BrsMainStartup.c
 *            2018-05-08  visbwa  Introduced support for Generic Testsuite (BRS_ENABLE_TESTSUITE_SUPPORT),
 *                                removed support for all other testsuites,
 *                                introduced BRS_ENABLE_1MS_HANDLER and brsMain_CallCounter1sec
 *            2018-05-16  visbwa  Added extern declaration of brsHwZeroRamAreaSet and brsHwInitRamAreaSet in
 *                                BrsMainStartup.c
 *  01.00.01  2018-06-22  visbwa  Added CAN stack exclusive area workaround from former BswInit_Callout_Stubs.c
 *  01.00.02  2018-06-25  visbwa  Added configuration check for OS_MS2TICKS_SystemTimer into BrsMain.h
 *  01.00.03  2018-07-02  visces  Removed outdated brsHwZeroRamAreaSet and brsHwInitRamAreaSet in BrsMainStartup.c
 *  01.00.04  2018-07-18  visbwa  Moved BrsHwDisableInterruptAtPowerOn() from BrsMainInit() into main()
 *                                (OS specifies, this has to be called before Os_Init() and for every Core)
 *  01.00.05  2018-07-26  visbwa  No changes in sourcecode, only within ALM package
 *  01.00.06  2018-07-30  visbwa  Encapsuled call of BrsHwDisableInterruptAtPowerOn() with usecase != VTT
 *  01.01.00  2018-08-16  visbwa  Replaced include of RamInitSections.h by vLinkGen_RamInitSections.h in
 *                                BrsMainStartup.c to support vLinkGen
 *  01.02.00  2018-10-04  visbwa  No changes in sourcecode, only within ALM package
 *  01.03.00  2018-10-08  visbwa  Changed include of BrsCfg.h into vBrsCfg.h (vBaseEnv 1.1.0)
 *  01.03.01  2018-10-10  visbwa  Moved BrsTestsuiteInit() from BrsMainInit() into Default_Init_Task(),
 *                                removed usage of BRS_ENABLE_HLPTEST_SUPPORT (generic Testsuite concept!)
 *  01.03.02  2018-11-05  visbwa  Fixed include order (Can.h previous to BrsTestsuite.h)
 *  01.03.03  2018-11-13  visbwa  Implemented Default_Init_Tasks for projects with up to 6 Cores,
 *                                fixed VTT support within IdleTasks (CANoeAPI_ConsumeTicks)
 *  01.04.00  2018-11-21  visbwa  Added testsuite callouts into every function
 *  01.04.01  2018-11-30  visbwa  Removed include of Rte_Main.h (Rte_Start() not called any more)
 *  01.05.00  2018-12-21  visbwa  Added call of new API Os_InitialEnableInterruptSources() within every core
 *                                Default_Init_Task
 *  01.05.01  2019-03-06  visbwa  Added hint for DrvCan using infix, added wrapper for Can_30_Mcan
 *  01.06.00  2019-05-06  visbwa  Support for vLinkGen 1.04; renamed struct names of vlinkGen areas in BrsMainStartup.c
 *                                - added support for zero init blocks
 *                                - renamed Brs_RamZeroInit() to Brs_MemoryZeroInit() and Brs_RomToRamInit() to
 *                                  Brs_MemoryInit()
 *                                - check for missing hard reset detection
 *  01.06.01  2019-05-10  visbwa  Changed include of vLinkGen header to support new vLinkGen file structure in
 *                                BrsMainStartup.c
 *  01.06.02  2019-06-13  vismaa  Added additional Default_Init_Task_Core6
 *  01.06.03  2019-06-26  visbwa  Moved call of BrsMainInit() previous to call of Os_Init()
 *  01.07.00  2019-07-02  visbwa  Enhanced FBL support (encapsulations, call of fblmain())
 *  01.07.01  2019-07-22  visbwa  Added check for VLINKGEN_ZERO_INIT_BLOCK_COUNT_HARD_RESET in BrsMainStartup.c
 *  01.07.02  2019-07-29  visbwa  Added implementation of BrsMainExceptionStartup() for calls from assembly StartUpCode
 *  01.08.00  2019-08-08  visbwa  Implemented support for different FBL usecases Legacy, WithoutOSScheduling and
 *                                OSScheduling, added BrsMainExceptionHandler module code for BrsMainStartup, changed
 *                                FBL call from fblmain() to FblMain() for legacy mode, removed include of fbl_main.h,
 *                                added InitPattern parameter to Brs_MemoryZeroInit() and added the new configuration
 *                                values for the init pattern to the depending calls in BrsMainStartup.c,
 *                                added sample implementation for Hard-reset blocks and areas in BrsMainStartup.c
 *  01.09.00  2019-08-28  visbwa  Changed encapsulation of task implementations (not used for FBL usecases Legacy and
 *                                WithoutOSScheduling any more)
 *            2019-10-07  visbwa  Added support of platform individual ZeroInit function BrsHw_AsmMemoryZeroInitLoop()
 *                                in Brs_MemoryZeroInit() in BrsMainStartup.c
 *            2019-10-09  visbwa  Enhanced support for VTT platform
 *  01.09.01  2019-11-04  visbwa  Changed include of Can.h into CanIf.h (get rid of DrvCan with infix (Can_30_Mcan.h)),
 *                                enhanced MemMap + SchM exclusive area abstraction for Mcan driver (uses infixes)
 *  01.09.02  2020-11-04  visbwa  No changes in sourcecode, only within ALM package
 *  01.10.00  2019-11-25  visbwa  Implemented Default_Init_Task_Trusted and Default_Init_Task_Corex_Trusted to allow
 *                                the SafeContext partitioning UseCase
 *            2019-11-27  visbwa  Changed include structure for vBrsCfg.h in BrsMain.h (does now also exist for VTT)
 *            2019-11-29  visbwa  Enhanced encapsulation with _MICROSOFT_C_VTT_ for DualTarget UseCase (no BrsHw!)
 *            2019-12-04  visbwa  Fixed encapsulation of DrvCan parts
 *  01.11.00  2020-02-11  visbwa  Support for UseCase HSM (BRS_ENABLE_HSM_SUPPORT, no EcuM),
 *                                added filtering of MultiCore parts through C_BRSASR_USECASE_SINGLECORE_COMMENT,
 *                                support for generated DrvCan macros to support modules with infix names,
 *                                removed error directive at usage of BrsHwGetResetReason() in BrsMainStartup.c
 *  01.12.00  2020-03-12  visbwa  Encapsulation of SchM implementation with MemMap defines for UseCase FBL,
 *                                encapsulation of struct brsMain_Cyclic_Callbacks with MemMap and 1ms-handler defines
 *  01.12.01  2020-04-22  visbwa  Added conditional call of BrsHwDisableEccErrorReporting() for FBL UseCase
 *  02.00.00  2020-05-29  visbwa  Major updates for vBaseEnv 2.0.0
 *                                - added BrsMainTogglePin() (moved from BrsHw.c BrsHwTogglePin())
 *                                - introduction of BrsMain_Callout_Stubs.c
 *                                - updated vLinkGen define and struct names to new vLinkGen 2.0 naming schema,
 *                                  added version check for vLinkGen version in BrsMainStartup.c
 *  02.01.00  2020-06-29  visbwa  Added support for preferred PLL and Watchdog init in BrsMainInit() and
 *                                BrsMain_MemoryInit_StageOne_Hook(), reduced calls of BrsHw_GetCore() inside
 *                                Brs_PreMainStartup() of BrsMainStartup.c to a single call
 *  02.01.01  2020-07-24  visbwa  Soft increase for FBL_Legacy support
 *  02.02.00  2020-08-10  visbwa  Support for FBL Legacy UseCase w/o OS, usage of new FBL UseCase defines;
 *                                MemMap encapsulation of BrsMainExceptionHandler(), enabled 1ms handler also for FBL,
 *                                BrsMainCyclic1ms() usable from extern, removed usage of BrsAsrApplCanInterruptLockCtr
 *                                for FBL (FBL is always in polling mode),
 *                                added BrsMain_SoftwareResetECU_Hook() in BrsMain_Callout_Stubs.c,
 *                                encapsuled memPtr in Brs_MemoryZeroInit() of BrsMainStartup.c (compiler warnings)
 *  02.02.01  2020-10-29  visbwa  No changes in sourcecode, only within ALM package
 *  02.02.02  2020-10-29  visbwa  No changes in sourcecode, only within ALM package
 *  02.02.03  2020-10-30  visbwa  Added include of Os.h for VTT (usage of ShutdownOS()), removed AUTHOR IDENTITY
 *  02.02.04  2020-12-07  visbwa  Increased for loop variable in Brs_MemoryZeroInit() and Brs_MemoryInit() from uint8
 *                                to uint32 (depending datatypes are increased in vLinkGen) in BrsMainStartup.c
 *  02.02.05  2021-01-14  visbwa  Adapted main() to also call Os_Init() for FBL with VTT
 *  02.03.00  2021-03-17  visbwa  Moved revision history of all .c and .h files into BrsMain.h, elimination of
 *                                BrsMainStartup.h, added support for new OS UseCase INTERRUPT_ONLY and call of
 *                                BrsMainExceptionHandler() at the end of main() for IllegalReturnFromMain
 *  02.03.01  2021-03-22  visbwa  Added definition of _BRSMAIN_C_ in BrsMain.c, to solve issues in vBrsCfg.h if DIO
 *                                channels are used for TogglePin functionality
 *  02.04.00  2021-04-07  visbwa  Added implementation of BrsMainSuspendAllInterrupts() and
 *                                BrsMainResumeAllInterrupts() for new OS UseCase INTERRUPT_ONLY
 *  02.04.01  2021-04-13  visbwa  Encapsulation of int main(void) declaration to not appear for VTT, as VTT expects
 *                                void main(void)
 *  02.05.00  2021-07-02  visbwa  Added support for upcoming Brs_Template 1.03:
 *                                - call of BrsHw_ExceptionTable_Init() in main()
 *                                - introduction of BrsMain_Types.h
 *                                - new MainExceptionHandler ErrorCode kBrsInvalidCoreConfig
 *  02.05.01  2021-07-19  visbwa  ESCAN00109765 - Fixed VTT encapsulation in main() to solve compiler error
 *  02.05.02  2021-08-02  visbwa  Fixed BrsHw_ExceptionTable_Init() call in main() for FBL Ram exception table
 *  02.05.03  2021-08-02  visbwa  Fixed BRSMAIN_BUGFIX_VERSION in several files of the package
 *  02.05.04  2021-09-17  visbwa  Added call of BrsHwEarlyInitPowerOn() at the beginning of Brs_PreMainStartup() 
 *********************************************************************************************************************/

#ifndef _BRSMAIN_H_
#define _BRSMAIN_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Compiler.h"

#include "vBrsCfg.h"

#if !defined (BRS_ENABLE_FBL_SUPPORT)
#include "Os.h"
#endif

#if defined (BRS_ENABLE_HSM_SUPPORT)
  #include "vHsm.h"
#else
# if !defined (BRS_FBL_NO_ECUMINIT)
/* Ecu State Manager has to be available in system (BSW module or BRS Stub) */
  #include "EcuM.h"
# endif
#endif

/**********************************************************************************************************************
 *  MODULE VERSION
 *********************************************************************************************************************/
/*
 * Description: This is the BrsMain main and bug fix version. The version numbers are BCD coded.
 *              E.g. a main version of 1.23 is coded with 0x0123, a bug fix version of 9 is coded 0x09.
 */
#define BRSMAIN_VERSION        0x0205u
#define BRSMAIN_BUGFIX_VERSION 0x04u

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL TYPE DEFINITIONS
 *********************************************************************************************************************/
#if defined (BRS_ENABLE_TESTSUITE_SUPPORT) || defined (BRS_ENABLE_SUPPORT_LEDS) || \
    defined (BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN) || defined (BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN)
  #define BRS_ENABLE_1MS_HANDLER
#endif

#if defined (BRS_ENABLE_1MS_HANDLER)
typedef enum
{
  BRSMAIN_CYCLETIME_BACKGROUND,
  BRSMAIN_CYCLETIME_1MS,
  BRSMAIN_CYCLETIME_10MS,
  BRSMAIN_CYCLETIME_100MS,
  BRSMAIN_CYCLETIME_250MS,
  BRSMAIN_CYCLETIME_500MS,
  BRSMAIN_CYCLETIME_1000MS
}brsMain_Cyclic_Cycletime;
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*******************************************************************************
 * ModuleCode for BrsMainExceptionHandler
 ******************************************************************************/
#define BRSERROR_MODULE_BRSHW           0x01
#define BRSERROR_MODULE_BRSMAIN         0x02
#define BRSERROR_MODULE_BRSSTARTUP      0x03
#define BRSERROR_MODULE_BRSMAINSTARTUP  0x04

/*******************************************************************************
 * ErrorCodes for BrsMainExceptionHandler
 * 0x00 to 0x7f are assigned to the BRS
 * 0x80 to 0xff are assigned to the application
 ******************************************************************************/
/* General error which is not assigned to a special error class */
#define kBrsUndefinedError                   0x00

/* No handler is installed in interrupt vector table for given interrupt */
#define kBrsInterruptHandlerNotInstalled     0x01

/* A GenTool setting is different to the excepted value */
#define kBrsWrongGenToolSettings             0x02

/* BrsHwRestoreInterrupt is called more often than BrsHwDisableInterrupt */
#define kBrsIllegalInterruptRestoration      0x03

/* Hardware configuration like clock setting is wrong */
#define kBrsIllegalHardwareConfiguration     0x04

/* Illegal parameter used like wrong channel parameter */
#define kBrsIllegalParameter                 0x05

/* Illegal TCC channel used */
#define kBrsTccChannelOutOfRange             0x06

/* Interrupt from unknown source occurred */
#define kBrsUnknownInterrupt                 0x07

/* CAN1 and CAN2 interrupts cannot be distinguished from each other */
#define kBrsAmbiguousInterruptSource         0x08

/* Execution of library version check in Common_SipVersionCheck failed */
#define kBrsLibraryVersionCheckFailed        0x09

/* OS ErrorHook called */
#define kBrsOsErrorHookCall                  0x0A

/* BRS not properly initialized */
#define kBrsConfigUninit                     0x0B

/* Application software returned to main */
#define kBrsIllegalReturnFromMain            0x0C

/* Assembler code reached, which should never be handled */
#define kBrsIllegalAssemblerReached          0x0D

/* No Core config foud for actual physical core */
#define kBrsInvalidCoreConfig                0x0E

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void BrsMainInit(void);

#if defined (BRS_ENABLE_1MS_HANDLER)
void BrsMainRegisterCyclic(void (*)(void), brsMain_Cyclic_Cycletime);

void BrsMainCyclic1ms(void);

# if !defined (BRS_ENABLE_FBL_SUPPORT) && !defined (BRS_ENABLE_OS_INTERRUPT_ONLY)
TASK(BrsMainTask);
TASK(BrsMainBackgroundTask);
# endif
#endif

#if !defined (BRS_ENABLE_FBL_SUPPORT) && !defined (BRS_ENABLE_OS_INTERRUPT_ONLY)
TASK(Default_Init_Task);
TASK(Default_Init_Task_Trusted);
#endif



#if defined (BRS_ENABLE_SUPPORT_LEDS)          || \
    defined (BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN) || \
    defined (BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN)
typedef enum
{
  BRSMAIN_TOGGLEPIN_LED,
  BRSMAIN_TOGGLEPIN_WD,
  BRSMAIN_TOGGLEPIN_CUSTOM
}brsMain_TogglePin;

# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_START_SEC_RAM_CODE
  #include "Brs_MemMap.h"
# endif
/*****************************************************************************/
/* @brief      This API is used to toggle a PortPin.
 *             Per default, the following parameters are available:
 *               BRSMAIN_TOGGLEPIN_LED
 *               BRSMAIN_TOGGLEPIN_WD
 *               BRSMAIN_TOGGLEPIN_CUSTOM
 *             Depending pins must be configured and initialized within BrsHw.
 * @pre        -
 * @param[in]  Pin to be toggled
 * @param[out] -
 * @return     -
 * @context    Function is called from all modules to set or clear a PortPin
 *****************************************************************************/
void BrsMainTogglePin(brsMain_TogglePin);
# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_STOP_SEC_RAM_CODE
  #include "Brs_MemMap.h"
# endif
#endif /*BRS_ENABLE_SUPPORT_LEDS||BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN||BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN*/

#if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_START_SEC_RAM_CODE
  #include "Brs_MemMap.h"
#endif
void BrsMainExceptionHandler(uint8 ErrorCode, uint8 ModuleCode, uint16 LineNumber);
#if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_STOP_SEC_RAM_CODE
  #include "Brs_MemMap.h"
#endif

void BrsMainExceptionStartup(void);

#if defined (BRS_ENABLE_OS_INTERRUPT_ONLY)
void BrsMainSuspendAllInterrupts(void);
void BrsMainResumeAllInterrupts(void);
#endif

void Brs_PreMainStartup(void); /* implemented in BrsMainStartup.c */

#if !defined (_MICROSOFT_C_VTT_)
int main(void);
#endif

#endif /*_BRSMAIN_H_*/
