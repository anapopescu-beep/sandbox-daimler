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
/** \file  File:  ARMBrsHw_CortexM.h
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsHw for all platforms with ARM core Cortex-M
 *
 *  \brief Description:  This is a global, platform-independent header file for the ARM-BRS.
 *                       This file includes all non-platform dependent functions.
 *                       All the (platform depending) rest needs to be defined in BrsHw.c
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
 *  01.00.00  2020-05-20  visbwa  New code basis for vBaseEnv 2.0 (based on zBrs_ArmCommon ARMBrsHw_CortexM.c 4.09.02)
 *  01.00.01  2020-06-05  visbwa  Fixed support for Tasking compiler in ARMStartup_CortexM.c
 *  01.00.02  2020-06-08  visbwa  Fixed usage of struct vLinkGen_MemArea (vLinkGen_ZeroInit_Early_Blocks,
 *                                vLinkGen_ZeroInit_Early_Groups) -> size is 16Byte per entry in ARMStartup_CortexM.c
 *  01.00.03  2020-06-09  visbwa  Fixed IAR code to load stack symbols (Brs_IarLoadStackSymbols_cx()) in
 *                                ARMStartup_CortexM.c
 *  01.00.04  2020-07-03  visbwa  Fixed MultiCore define, added check for derivatives with more than 2 cores in
 *                                ARMStartup_CortexM.c
 *  01.00.05  2020-07-27  vismun  Extended MultiCore implementation up to 3 cores in ARMStartup_CortexM.c
 *  01.00.06  2020-07-28  visbwa  Experimental support for FBL Legacy UseCase w/o OS (will became Brs_Template 1.01.00)
 *            2020-07-28  visbwa  Initial creation of ARMBrsHwIntTb_CortexM.c
 *            2020-08-24  visjhr  HALBE-1770 Problems with ARM common startup code with Hightec compiler
 *  01.01.00  2020-09-18  visbwa  Review according to Brs_Template 1.01.00
 *  01.01.01  2020-10-06  visbwa  Fixed BRS_ISR_KEYWORD of Arm5, Gnu and Iar compiler abstraction in
 *                                ARMBrsHw_CortexM.h, update to Brs_Template 1.01.01, removed AUTHOR IDENTITY
 *  01.00.02  2020-10-09  visbwa  Fixed Iar support (use default label for stack) in ARMStartup_CortexM.c
 *  01.00.03  2020-10-13  visbwa  Fixed thumb support for entry brsStartupEntry in ARMStartup_CortexM.c
 *  01.00.04  2020-10-15  visbwa  Fixed thumb support for entry brsStartupEntry in ARMStartup_CortexM.c
 *  01.00.05  2020-10-21  visbwa  Fixed TI support (use default label for stack) in ARMStartup_CortexM.c
 *  01.01.06  2020-11-09  visbwa  Updates in ALM package only, to support GccGnu
 *  01.01.07  2020-12-14  visrgm  Added PUSH & POP for ARM5 inline assembly helper functions
 *  01.01.08  2021-01-14  visbwa  Fixed BRANCH to startup_block_zero_init_loop_start for ARM compilers in
 *                                ARMStartup_CortexM.c
 *  01.02.00  2021-04-22  vismaa  Added support for compiler GccNxp
 *            2021-05-04  vishci  Renamed HIGHTEC to GCCHIGHTEC
 *            2021-04-05  visbwa  Update to Brs_Template 1.02.01, moved revision history of all .c and .h files to here
 *  01.02.01  2021-06-07  vishci  Fixed Arm5 compiler support for Cortex-M0+
 *  01.02.02  2021-07-12  visbwa  Fixed SP reset value and Reset Handler for IAR compiler in ARMBrsHwIntTb_CortexM.c,
 *                                fixed STACK_Cx label handling for IAR compiler in ARMStartup_CortexM.c
 *********************************************************************************************************************/

#ifndef _ARMBRSHW_CORTEX_M_H_
#define _ARMBRSHW_CORTEX_M_H_

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
#define ARMBRSHW_CORTEXM_VERSION        0x0102u
#define ARMBRSHW_CORTEXM_BUGFIX_VERSION 0x02u

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 *********************************************************************************************************************/
/* Configuration checks performed within platform specific code (BrsHw) */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
 * Description: Macro for access to IO addresses
 */
#define BRSHW_IOS(type, address) (*((volatile type *)(address)))

#define BRSHWNOP10() do { \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  __asm(" NOP");          \
  } while(0)

/**********************************************************
 * NVIC Interrupt Controller Macros
 *********************************************************/
/* If default address for NVIC_BASE is not sufficient for the depending platform,
 * the NVIC_BASE define for NVIC Base address definition has to be declared inside
 * platform specific BrsHw.h, just before ArmBrsHw.h is included. */
#if !defined (NVIC_BASE)
  #define NVIC_BASE  0xE000E000UL  /* NVIC Base address definition */
#endif
  #define NVIC_ISER(x)  BRSHW_IOS(uint32, NVIC_BASE + 0x100UL + x*4U) /* Interrupt Set-Enable Registers */
  #define NVIC_ICER(x)  BRSHW_IOS(uint32, NVIC_BASE + 0x180UL + x*4U) /* Interrupt Clear-Enable Registers */
  #define NVIC_ISPR(x)  BRSHW_IOS(uint32, NVIC_BASE + 0x200UL + x*4U) /* Interrupt Set-Pending Registers */
  #define NVIC_ICPR(x)  BRSHW_IOS(uint32, NVIC_BASE + 0x280UL + x*4U) /* Interrupt Clear-Pending Registers */
  #define NVIC_IPR(x)   BRSHW_IOS(uint8, NVIC_BASE + 0x400UL + x)     /* Interrupt Priority Registers */

/**********************************************************************************************************************
 * Compiler abstraction
 *********************************************************************************************************************/
#if defined (BRS_COMP_TASKING)
  #define ___asm(c)                __asm_(c)
  #define __asm_(c)                __asm(#c);
  #define __as1(c, d)              __as1_(c, d)
  #define __as1_(c, d)             __asm( #c " , " #d);
  #define __as2(c, d, e)           __as2_(c, d, e)
  #define __as2_(c, d, e)          __asm( #c " , " #d " , " #e);
  #define __as3(c, d, e, f)        __as3_(c, d, e, f)
  #define __as3_(c, d, e, f)       __asm( #c " , " #d " , " #e " , " #f);
  #define __as4(c, d, e, f, g)     __as4_(c, d, e, f, g)
  #define __as4_(c, d, e, f, g)    __asm( #c " , " #d " , " #e " , " #f  " , " #g);
  #define __as5(c, d, e, f, g, h)  __as5_(c, d, e, f, g, h)
  #define __as5_(c, d, e, f, g, h) __asm( #c " , " #d " , " #e " , " #f  " , " #g " , " #h);

  #define BRS_MULTILINE_ASM_BEGIN()
  #define BRS_MULTILINE_ASM_END()
  #define BRS_END_SEC()            ___asm(.endsec)

  #define BRS_ASM_EQU(Label, Value) __as1(Label .EQU Value)

  #define BRS_ISR_KEYWORD __attribute__ ((interrupt)(IRQ))

  #define BRS_SECTION_CODE(c)     ___asm(.section .text.c )
  #define BRS_GLOBAL(c)           ___asm(.GLOBAL c)
  #define BRS_LABEL(c)            ___asm(c:)
  #define BRS_GLOBAL_END()

  /* Unconditional branch to c */
  #define BRS_BRANCH(c)           ___asm(B c)
# if defined (BRS_CPU_CORE_CORTEX_M0) || defined (BRS_CPU_CORE_CORTEX_M0PLUS)
  #define BRS_EXTERN_BRANCH(c)    __as1(LDR R1, =c) \
                                  ___asm(BX R1)
# else
  #define BRS_EXTERN_BRANCH(c)    ___asm(B c)
# endif

  /* Branch to e if c and d are equal */
  #define BRS_BRANCH_EQUAL(c,d,e)  __as1(CMP   c, d) \
                                   ___asm(BEQ   e)

  /* Branch to e if c and d are NOT equal */
  #define BRS_BRANCH_NOT_EQUAL(c,d,e)  __as1(CMP   c, d) \
                                       ___asm(BNE   e)

  /* Branch to e if c is greater than d*/
  #define BRS_BRANCH_GREATER_THAN(c,d,e)  __as1(CMP   c, d) \
                                          ___asm(BGT   e)

#else
  #error "Compiler not yet supported"
#endif /*BRS_COMP_x*/

/**********************************************************************************************************************
 *  BrsHW configuration
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

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
/* @brief      This API is used to enable an interrupt source in the core
 *             interrupt controller (NVIC).
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
 *             interrupt controller (NVIC).
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

#endif /*_ARMBRSHW_CORTEX_M_H_*/
