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
/** \file  File:  BrsHw.h
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsHw for platform Infineon Aurix/AurixPlus
 *
 *  \brief Description:  This is the hardware specific header file for Vector Basic Runtime System (BRS).
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
 *  01.00.00  2020-05-19  virrlu  New branch for vBaseEnv 2.0, based on zBrs_Aurix BrsHw.c 3.00.12
 *            2020-05-28  vismaa  Changed pin naming for BRS_ENABLE_FLEXRAY_CHANNEL_x_B from FRxB_ERRNA TO FRxB_ERRNB
 *  01.00.01  2020-06-16  vismaa  Changed brsStartupEntry into StartupEntry (Symbol is used with vLinGen 2.0),
 *                                added support for 40MHz OSC (AurixPlus)
 *  01.00.02  2020-06-26  visbpz  Implemented BrsHw_UnlockCores() as an empty function
 *  01.00.03  2020-07-15  visrgm  Fixed ETH port initialization due to support quest
 *  01.00.04  2020-07-22  visto   HALBE-2249: Remove unecessary inline function prototypes -> all prototypes are
 *                                            declared within tcasm.h
 *  01.01.00  2020-07-28  virrlu  Fixed Tasking BRS_STARTUP_LABEL in BrsHw.h to support default startup label,
 *                                changed Tasking startup stack labels in BrsHwStartup.c
 *  01.02.00  2020-08-04  visbwa  Experimental support for FBL UseCase Legacy w/o OS
 *            2020-09-17  visbwa  Fixed initialization of BRSHW_PORT_ETH0_MDIO
 *            2020-09-18  visrgm  Added linking of StartupCode to section .brsStartup in BrsHwStartup.c
 *            2020-09-20  vismaa  Added BRS_PORT_GROUP_C (TC49xx)
 *            2020-09-22  visto   HALBE-2176 create inline functions for ENDINIT handling
 *  01.03.00  2020-10-26  visto   HALBE-2633 - vBaseEnv_TricoreAurix: Adaptions for FBL UseCase,
 *                                             introduction of BrsHwIntTb_TCxxx.c
 *  01.03.01  2020-10-28  visbpz  Added inline to HighTec BRS_FUNC_DECLARATION in BrsHw.h, to get rid of "always_inline
 *                                function might not be inlinable [-Wattributes]" compiler warning
 *            2020-10-29  vishci  removed Author Identity and added wait status between PLL up rampings
 *  01.03.02  2021-01-15  visto   ESCAN00108312 - Incorrect condition on Wait for System PLL to be stable
 *  01.03.03  2021-01-20  visto   HALBE-2832 - Fix wrong implemented Errata PLL_TC.005 fix and add safety endinit
 *                                             handling
 *  01.03.04  2021-01-25  visto   HALBE-3613 - Setting up STM Frequency to 100 MHz
 *  01.03.05  2021-03-12  vismaa  Changed fOSCREF for BRS_PLL_GROUP_B, OSCVAL calcualation has changed
 *  01.04.00  2021-04-01  visbwa  Update to Brs_Template 1.02.01, moved revision histories of all files into BrsHw.h,
 *                                removed BMHD1..3, BMHD0 should always be sufficient,
 *                                changed BMHD0 of TC3xx to boot from 0xA0000000 instead of 0xA00A0020,
 *                                removed BRS_STARTUP_LABEL (not needed any more as linking of StartUpCode was changed)
 *********************************************************************************************************************/

#ifndef _BRSHW_H_
#define _BRSHW_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/*
 * Description: The BrsCfg header is used to configure different types of
 *              tests and system setups. Therefore it must be included first
 *              in each BRS and test module.
 *              This file is part of the BRS.
 */
#include "vBrsCfg.h"

/**********************************************************************************************************************
 *  MODULE VERSION
 *********************************************************************************************************************/
/*
 * Description: This is the BrsHw main and bug fix version. The version numbers are BCD coded.
 *              E.g. a main version of 1.23 is coded with 0x0123, a bug fix version of 9 is coded 0x09.
 */

/* This is the BrsHw template main and bug fix version, the platform BrsHw is reviewed to */
#define BRSHW_SOURCECODE_TEMPLATE_VERSION        0x0102u
#define BRSHW_SOURCECODE_TEMPLATE_BUGFIX_VERSION 0x01u

/* This is the BrsHw main and bug fix version */
#define BRSHW_VERSION        0x0104u
#define BRSHW_BUGFIX_VERSION 0x00u

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 *********************************************************************************************************************/
/* The following parameters are necessary for this platform, to be generated by BRS-Cfg5-Generator into BrsCfg.h */

#if !defined (BRS_CPU_MAX_FREQUENCY)
  #error "BRS CHECK: The parameter BRS_CPU_MAX_FREQUENCY is missing! Please check your BRS Cfg5 configuration."
#endif

#if !(defined (BRS_CPU_CORE_TC161) || defined (BRS_CPU_CORE_TC162) || defined (BRS_CPU_CORE_TC18))
  #error "BRS CHECK: The parameter BRS_CPU_CORE_x is missing or not supported! Please check your BRS Cfg5 configuration."
#endif

#if !defined (BRS_CPU_CORE_AMOUNT)
  #error "BRS CHECK: The parameter BRS_CPU_CORE_AMOUNT is missing! Please check your BRS Cfg5 configuration."
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
 * Description: Macro for access to IO addresses
 */
#define BRSHW_IOS(type, address) (*((volatile type *)(address)))

/* STATIC */
#define BRSHW_DERIVATIVE_CORE0_ID  0x0
#define BRSHW_DERIVATIVE_CORE1_ID  0x1
#define BRSHW_DERIVATIVE_CORE2_ID  0x2
#define BRSHW_DERIVATIVE_CORE3_ID  0x3
#define BRSHW_DERIVATIVE_CORE4_ID  0x4
#define BRSHW_DERIVATIVE_CORE5_ID  0x6

/* DERIVATIVE DEPENDENT STATIC */
#define BRSHW_INIT_CORE_ID  BRSHW_DERIVATIVE_CORE0_ID

#define BRS_CORE_ID_REGISTER  0xFE1C
#define BRS_PCXI_OFFSET       0xFE00
#define BRS_PSW_OFFSET        0xFE04
#define BRS_FCX_OFFSET        0xFE38
#define BRS_LCX_OFFSET        0xFE3C
#define BRS_BTV_OFFSET        0xFE24
#define BRS_BIV_OFFSET        0xFE20
#define BRS_PCON0_OFFSET      0x920C

/**********************************************************************************************************************
 * Compiler abstraction
 *********************************************************************************************************************/
#if defined (BRS_COMP_TASKING)
  #define nop()                    __nop()

  #define BRS_FORCE_ACTIVE         __attribute__((protect))

  #define BRS_ISYNC()              __isync()
  #define BRS_DSYNC()              __dsync()

  #define BRS_HAL_EXPAND(x)        #x

  #define BRS_MOVE_FROM_CSFR(x)    (uint32)__mfcr((sint32)(x))
  #define BRS_MOVE_TO_CSFR(x, y)   BRS_DSYNC(); __asm("mtcr  #"BRS_HAL_EXPAND(x)", %0" ::"d"(y):); BRS_ISYNC()

  #define BRS_SET_SP(x)            __asm("mov.a  a10, %0" ::"d"(x):"a10")

  #define BRS_FUNC_DECLARATION(rettype, attribute, functionName, arguments) \
    rettype functionName (arguments) __attribute__((attribute))

  #define BRS_FUNC_DECLARATION_PROTOTYPE(rettype, attribute, functionName, arguments) \
    rettype functionName (arguments) __attribute__((attribute))
 
#else
  #error "Compiler not yet supported"
#endif /*BRS_COMP_x*/

/* Reads core id value */
#define BRS_READ_COREID()  BRS_MOVE_FROM_CSFR(BRS_CORE_ID_REGISTER)

/**********************************************************************************************************************
 *  BrsHW configuration
 *********************************************************************************************************************/

/*******************************************************************************
  WATCHDOG  GROUP  CONFIG
*******************************************************************************/
#define BRS_SAFETY_WATCHDOG_INDEX  -1

#if defined (BRS_WATCHDOG_GROUP_A)
  #define BRS_SFR_WDTCPU0CON0_ADDRESS 0xF0036100
  #define BRS_SFR_WDTCPU1CON0_ADDRESS 0xF003610C
  #define BRS_SFR_WDTCPU2CON0_ADDRESS 0xF0036118
  #define BRS_SFR_WDTSCON0_ADDRESS    0xF00360F0

  #define BRS_SFR_WDTCPU0CON0  BRSHW_IOS(uint32, BRS_SFR_WDTCPU0CON0_ADDRESS)  /* original name: SCU_WDTCPU0CON0 */
  #define BRS_SFR_WDTCPU0CON1  BRSHW_IOS(uint32, 0xF0036104)  /* original name: SCU_WDTCPU0CON1 */

  #define BRS_SFR_WDTCPU1CON0  BRSHW_IOS(uint32, BRS_SFR_WDTCPU1CON0_ADDRESS)  /* original name: SCU_WDTCPU1CON0 */
  #define BRS_SFR_WDTCPU1CON1  BRSHW_IOS(uint32, 0xF0036110)  /* original name: SCU_WDTCPU1CON1 */

  #define BRS_SFR_WDTCPU2CON0  BRSHW_IOS(uint32, BRS_SFR_WDTCPU2CON0_ADDRESS)  /* original name: SCU_WDTCPU2CON0 */
  #define BRS_SFR_WDTCPU2CON1  BRSHW_IOS(uint32, 0xF003611C)  /* original name: SCU_WDTCPU2CON1 */

  #define BRS_SFR_WDTSCON0     BRSHW_IOS(uint32, BRS_SFR_WDTSCON0_ADDRESS)  /* original name: SCU_WDTSCON0 */
  #define BRS_SFR_WDTSCON1     BRSHW_IOS(uint32, 0xF00360F4)  /* original name: SCU_WDTSCON1 */
  
  #define BRS_SAFETY_WATCHDOG_ARRAY_INDEX 3

#elif defined (BRS_WATCHDOG_GROUP_B)
  #define BRS_SFR_WDTCPU0CON0_ADDRESS 0xF003624C
  #define BRS_SFR_WDTCPU1CON0_ADDRESS 0xF0036258
  #define BRS_SFR_WDTCPU2CON0_ADDRESS 0xF0036264
  #define BRS_SFR_WDTCPU3CON0_ADDRESS 0xF0036270
  #define BRS_SFR_WDTCPU4CON0_ADDRESS 0xF003627C
  #define BRS_SFR_WDTCPU5CON0_ADDRESS 0xF0036288
  #define BRS_SFR_WDTSCON0_ADDRESS    0xF00362A8

  #define BRS_SFR_WDTCPU0CON0  BRSHW_IOS(uint32, BRS_SFR_WDTCPU0CON0_ADDRESS)  /* CPU0 WDT Control Register 0 - original name: SCU_WDTCPU0CON0 */
  #define BRS_SFR_WDTCPU0CON1  BRSHW_IOS(uint32, 0xF0036250)  /* CPU0 WDT Control Register 1 - original name: SCU_WDTCPU0CON1 */
  #define BRS_SFR_WDTCPU0_SR   BRSHW_IOS(uint32, 0xF0036254)  /* CPU0 WDT Status Register - original name: SCU_WDTCPU0_SR */

  #define BRS_SFR_WDTCPU1CON0  BRSHW_IOS(uint32, BRS_SFR_WDTCPU1CON0_ADDRESS)  /* CPU1 WDT Control Register 0 - original name: SCU_WDTCPU1CON0 */
  #define BRS_SFR_WDTCPU1CON1  BRSHW_IOS(uint32, 0xF003625C)  /* CPU1 WDT Control Register 1 - original name: SCU_WDTCPU1CON1 */
  #define BRS_SFR_WDTCPU1_SR   BRSHW_IOS(uint32, 0xF0036260)  /* CPU1 WDT Status Register - original name: SCU_WDTCPU1_SR */

  #define BRS_SFR_WDTCPU2CON0  BRSHW_IOS(uint32, BRS_SFR_WDTCPU2CON0_ADDRESS)  /* CPU2 WDT Control Register 0 - original name: SCU_WDTCPU2CON0 */
  #define BRS_SFR_WDTCPU2CON1  BRSHW_IOS(uint32, 0xF0036268)  /* CPU2 WDT Control Register 1 - original name: SCU_WDTCPU2CON1 */
  #define BRS_SFR_WDTCPU2_SR   BRSHW_IOS(uint32, 0xF003626C)  /* CPU2 WDT Status Register - original name: SCU_WDTCPU2_SR */

  #define BRS_SFR_WDTCPU3CON0  BRSHW_IOS(uint32, BRS_SFR_WDTCPU3CON0_ADDRESS)  /* CPU3 WDT Control Register 0 - original name: SCU_WDTCPU3CON0 */
  #define BRS_SFR_WDTCPU3CON1  BRSHW_IOS(uint32, 0xF0036274)  /* CPU3 WDT Control Register 1 - original name: SCU_WDTCPU3CON1 */
  #define BRS_SFR_WDTCPU3_SR   BRSHW_IOS(uint32, 0xF0036278)  /* CPU3 WDT Status Register - original name: SCU_WDTCPU3_SR */

  #define BRS_SFR_WDTCPU4CON0  BRSHW_IOS(uint32, BRS_SFR_WDTCPU4CON0_ADDRESS)  /* CPU4 WDT Control Register 0 - original name: SCU_WDTCPU4CON0 */
  #define BRS_SFR_WDTCPU4CON1  BRSHW_IOS(uint32, 0xF0036280)  /* CPU4 WDT Control Register 1 - original name: SCU_WDTCPU4CON1 */
  #define BRS_SFR_WDTCPU4_SR   BRSHW_IOS(uint32, 0xF0036284)  /* CPU4 WDT Status Register - original name: SCU_WDTCPU4_SR */

  #define BRS_SFR_WDTCPU5CON0  BRSHW_IOS(uint32, BRS_SFR_WDTCPU5CON0_ADDRESS)  /* CPU5 WDT Control Register 0 - original name: SCU_WDTCPU5CON0 */
  #define BRS_SFR_WDTCPU5CON1  BRSHW_IOS(uint32, 0xF003628C)  /* CPU5 WDT Control Register 1 - original name: SCU_WDTCPU5CON1 */
  #define BRS_SFR_WDTCPU5_SR   BRSHW_IOS(uint32, 0xF0036290)  /* CPU5 WDT Status Register - original name: SCU_WDTCPU5_SR */

  #define BRS_SFR_WDTSCON0     BRSHW_IOS(uint32, BRS_SFR_WDTSCON0_ADDRESS)  /* Safety WDT Control Register 0 - original name: SCU_WDTS_CON0 */
  #define BRS_SFR_WDTSCON1     BRSHW_IOS(uint32, 0xF00362AC)  /* Safety WDT Control Register 1 - original name: SCU_WDTS_CON1 */

  #define BRS_SAFETY_WATCHDOG_ARRAY_INDEX 7

  #define BRS_SFR_WDTS_SR      BRSHW_IOS(uint32, 0xF00362B0)  /* Safety WDT Status Register - original name: SCU_WDTS_SR */
#endif /*BRS_WATCHDOG_GROUP_x*/

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/
/*
 * Description: These constants are used to propagate the Versions over module boundaries.
 *              The version numbers are BCD coded. E.g. a sub version of 23 is coded with 0x23, 
 *              a bug fix version of 9 is coded 0x09.
 */
extern uint8 const kBrsHwMainVersion;
extern uint8 const kBrsHwSubVersion;
extern uint8 const kBrsHwBugfixVersion;

#if defined (BRS_WATCHDOG_GROUP_A)
extern const uint32 kBrsWdtCon0Addresses[4];
#elif defined (BRS_WATCHDOG_GROUP_B)
extern const uint32 kBrsWdtCon0Addresses[8];
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 /*******************************************************************************
 CPU Core Amount (number of cores)
*******************************************************************************/
BRS_FUNC_DECLARATION_PROTOTYPE(static uint32 *, always_inline, BrsHw_GetAddrWDTCON0, sint32 nr);
BRS_FUNC_DECLARATION(static uint32 *, always_inline, BrsHw_GetAddrWDTCON0, sint32 nr)
{
  if (nr == BRS_SAFETY_WATCHDOG_INDEX)
  {
    return (uint32*)(kBrsWdtCon0Addresses[BRS_SAFETY_WATCHDOG_ARRAY_INDEX]);
  }
  else
  {
    return (uint32*)(kBrsWdtCon0Addresses[nr]);
  }
}

/*****************************************************************************/
/* @brief Routine to unlock registers that are normally protected
 * @pre   Interrupts must be disabled
 *****************************************************************************/
BRS_FUNC_DECLARATION_PROTOTYPE(static void, always_inline, BrsHwUnlockInitInline, sint32 coreID);
BRS_FUNC_DECLARATION(static void, always_inline, BrsHwUnlockInitInline, sint32 coreID)
{
  volatile uint32 wdtcon0value;
  uint32 *WDTCON0;

  WDTCON0 = BrsHw_GetAddrWDTCON0(coreID);

  /*
   * 1st step: Password access (create password and send to WDT_CON0)
   */
  wdtcon0value = *WDTCON0;
  wdtcon0value &= 0xFFFFFF01;  /* clear WDTLCK, WDTHPW0, WDTHPW1 */
  wdtcon0value |= 0xF0;        /* set WDTHPW1 to 0xf */
  wdtcon0value |= 0x01;        /* 1 must be written to ENDINIT for password access
                                (but this will not actually modify the bit) */
  *WDTCON0 = wdtcon0value; /* modify access to WDTCON0 */
  /*
   * 2nd step: Modify access, set the bit ENDINIT to 1 or 0 to allow access to
   *           registers: WDT_CON1, BTV, BIV, ISP and mod_CLC
   */
  wdtcon0value &= 0xFFFFFFF0;  /* clear WDTHPW0, WDTLCK, ENDINIT  */
  wdtcon0value |= 0x02;        /* WDTHPW0=0, WDTLCK=1, ENDINIT=0 */
  BRS_ISYNC();
  *WDTCON0 = wdtcon0value;
  wdtcon0value = *WDTCON0; /* read is required */
  BRS_ISYNC();
  BRS_DSYNC();
}

/*****************************************************************************/
/* @brief Routine to lock registers that are normally protected
 * @pre   Interrupts must be disabled
 *****************************************************************************/
BRS_FUNC_DECLARATION_PROTOTYPE(static void, always_inline, BrsHwLockInitInline, sint32 coreID);
BRS_FUNC_DECLARATION(static void, always_inline, BrsHwLockInitInline, sint32 coreID)
{
  volatile uint32 wdtcon0value;
  uint32 *WDTCON0;
  WDTCON0 = BrsHw_GetAddrWDTCON0(coreID);
  /*
   * 1st step: Password access (create password and send to WDT_CON0)
   */
  wdtcon0value = *WDTCON0;
  wdtcon0value &= 0xFFFFFF01;  /* clear WDTLCK, WDTHPW0, WDTHPW1 */
  wdtcon0value |= 0xF0;        /* set WDTHPW1 to 0xf */
  wdtcon0value |= 0x01;        /* 1 must be written to ENDINIT for password access
                                 (but this will not actually modify the bit) */
  *WDTCON0 = wdtcon0value; /* modify access to WDTCON0 */
  /*
   * 2nd step: Modify access, set the bit ENDINIT to 1 or 0 to allow access to
   *           registers: WDT_CON1, BTV, BIV, ISP and mod_CLC
   */
  wdtcon0value &= 0xFFFFFFF0;  /* clear WDTHPW0, WDTLCK, ENDINIT  */
  wdtcon0value |= 0x03;        /* WDTHPW0=0, WDTLCK=1, ENDINIT=1 */
  BRS_ISYNC();
  *WDTCON0 = wdtcon0value;
  wdtcon0value = *WDTCON0; /* read is required */
  BRS_ISYNC();
  BRS_DSYNC();
}

#if defined (BRS_ENABLE_WATCHDOG)
/*****************************************************************************/
/* @brief      This function must be used to initialize the Watchdog.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 *****************************************************************************/
void BrsHwWatchdogInitPowerOn(void);
#endif /*BRS_ENABLE_WATCHDOG*/


/*****************************************************************************/
/* @brief      Disable the global system interrupt.
 * @pre        Must be the first function call in main@BrsMain
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from main@BrsMain at power on initialization
 *****************************************************************************/
void BrsHwDisableInterruptAtPowerOn(void);

/*****************************************************************************/
/* @brief      Restart ECU (issue a software reset or jump to startup code)
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from e.g. ECU state handling
 *****************************************************************************/
void BrsHwSoftwareResetECU(void);

typedef enum
{
  BRSHW_RESET_SW,
  BRSHW_RESET_OTHER
}brsHw_ResetReasonType;

/*****************************************************************************/
/* @brief      Get reset reason
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     Reset reason
 * @context    Function is called from BrsMainStartup to determine if reset
 *             was triggered through software call (BrsHwSoftwareResetECU()).
 *****************************************************************************/
brsHw_ResetReasonType BrsHwGetResetReason(void);

/*****************************************************************************/
/* @brief      This API is used for the BRS time measurement support to get a
 *             default time value for all measurements with this platform to
 *             be able to compare time measurements on different dates based
 *             on this time result.
 * @pre        Should be called with interrupts global disabled
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from e.g. component testsuits for calibration
 *****************************************************************************/
void BrsHwTime100NOP(void);


/*****************************************************************************/
/* @brief      This API is used to read the core ID of the actual running core
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     Core ID of the actual running core
 * @context    Function is e.g. called from main@BrsMain, to only call HW-init
 *             code once, on the boot core.
 *             In MultiCore setups, additional BRSHW_INIT_CORE_ID must be
 *             declared inside BrsHw.h, to configure the proper core ID value
 *             of that boot core.
 *****************************************************************************/
uint32 BrsHw_GetCore(void);

/*****************************************************************************/
/* @brief      This API is used to enable an interrupt source in the core
 *             interrupt controller.
 * @pre        -
 * @param[in]  Source to be enabled.
 * @param[in]  Priority level to be set.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 *****************************************************************************/
void BrsHw_EnableInterrupt(uint32, uint8);

/*****************************************************************************/
/* @brief      This API is used to disable an interrupt source in the core
 *             interrupt controller.
 * @pre        -
 * @param[in]  Source to be disabled.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 *****************************************************************************/
void BrsHw_DisableInterrupt(uint32);

/*****************************************************************************/
/* @brief      This API is used to trigger the given software interrupt source.
 * @pre        -
 * @param[in]  Source to be triggered.
 *             Some derivatives only support few software triggerable sources,
 *             check for their validity.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 *****************************************************************************/
void BrsHw_TriggerSoftwareInterrupt(uint32);

#if defined (BRS_ENABLE_FBL_SUPPORT)
#define BRSHW_DISABLE_ECC_AVAILABLE
/*****************************************************************************/
/* @brief      This API is used to disable the flash ECC error reporting,
 *             if this is necessary on the platform to grant access to it.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from FBL boot code, before flash is accessed.
 *****************************************************************************/
void BrsHwDisableEccErrorReporting(void);
#endif /*BRS_ENABLE_FBL_SUPPORT*/

# if defined (BRS_ENABLE_FLEXRAY_SUPPORT)
/*****************************************************************************/
/**
 * @brief      Callback from communication stack. Init E-RAY RAM to avoid ECC errors
 * @pre        
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called Fr_InitMemory(). It is just an empty function
 *             because the RAM init is already done during startup.
 */
/*****************************************************************************/
void Appl_TricoreAurixInit(void);
# endif /* BRS_ENABLE_FLEXRAY_SUPPORT */

#endif /*_BRSHW_H_*/
