
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  ARMBrsHw.h
      Project:  Vector Basic Runtime System
       Module:  BrsHw for all platforms with ARM core

  \brief Description:  This is a global, hardware-independent header file for the ARM-BRS.
                       This file includes all non-hardware dependent functions, e.g. the timer-configuration for the
                       Millisecond-Timebase. All the (hardware depending) rest needs to be defined in BrsHw.c

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

#ifndef _ARMBRSHW_H_
#define _ARMBRSHW_H_

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
/*
 * Description: The BrsCfg header is used to configure different types of
 *              tests and system setups. Therefore it must be included first
 *              in each BRS and test module.
 *              This file is part of the BRS.
 */
#include "vBrsCfg.h"

/**********************************************************************************************************************
  MODULE VERSION
**********************************************************************************************************************/
/*
 * Description: This is the BrsHw main and bug fix version. The version numbers are BCD coded.
 *              E.g. a main version of 1.23 is coded with 0x0123, a bug fix version of 9 is coded 0x09.
 */
#define ARMBRSHW_CORTEXM_VERSION        0x0409u
#define ARMBRSHW_CORTEXM_BUGFIX_VERSION 0x02u

#define ARMBRSHW_CORTEXA_VERSION        0x0407u
#define ARMBRSHW_CORTEXA_BUGFIX_VERSION 0x01u

/**********************************************************************************************************************
  CONFIGURATION CHECK
**********************************************************************************************************************/
/* Configuration checks performed within platform specific code */

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
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

#if defined (BRS_CPU_CORE_CORTEX_M0) || defined (BRS_CPU_CORE_CORTEX_M0PLUS) || defined (BRS_CPU_CORE_CORTEX_M3) || \
    defined (BRS_CPU_CORE_CORTEX_M4) || defined (BRS_CPU_CORE_CORTEX_M4F) || defined (BRS_CPU_CORE_CORTEX_M7)
  /**********************************************************
   * NVIC Interrupt Controller Macros
   *********************************************************/
  /* If default address for NVIC_BASE is not sufficient for the depending platform,
   * the NVIC_BASE define for NVIC Base address definition has to be declared inside
   * platform specific BrsHw.h, just before ArmBrsHw.h is included. */
# if !defined (NVIC_BASE)
  #define NVIC_BASE  0xE000E000UL  /* NVIC Base address definition */
# endif
  #define NVIC_ISER(x)  BRSHW_IOS(uint32, NVIC_BASE + 0x100UL + x*4U) /* Interrupt Set-Enable Registers */
  #define NVIC_ICER(x)  BRSHW_IOS(uint32, NVIC_BASE + 0x180UL + x*4U) /* Interrupt Clear-Enable Registers */
  #define NVIC_ISPR(x)  BRSHW_IOS(uint32, NVIC_BASE + 0x200UL + x*4U) /* Interrupt Set-Pending Registers */
  #define NVIC_ICPR(x)  BRSHW_IOS(uint32, NVIC_BASE + 0x280UL + x*4U) /* Interrupt Clear-Pending Registers */
  #define NVIC_IPR(x)   BRSHW_IOS(uint8, NVIC_BASE + 0x400UL + x)     /* Interrupt Priority Registers */
#endif /*BRS_CPU_CORE_CORTEX_Mx*/

/**********************************************************************************************************************
  Compiler abstraction
**********************************************************************************************************************/
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
  BrsHW configuration
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global variables
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global const variables
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global function prototypes
**********************************************************************************************************************/

/*****************************************************************************/
/**
 * @brief      Disable the global system interrupt and initialize the INT
 *             lock handler variables.
 * @pre        Must be the first function call in main@BrsMain
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from main@BrsMain at power on initialization
 */
/*****************************************************************************/
void BrsHwDisableInterruptAtPowerOn(void);

/*****************************************************************************/
/**
 * @brief      This API is used for the BRS time measurement support to get a
 *             default time value for all measurements with this platform to
 *             be able to compare time measurements on different dates based
 *             on this time result.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from TimeMeasurement
 */
/*****************************************************************************/
void BrsHwTime100NOP(void);

#if defined (BRS_CPU_CORE_CORTEX_M0) || defined (BRS_CPU_CORE_CORTEX_M0PLUS) || defined (BRS_CPU_CORE_CORTEX_M3) || \
    defined (BRS_CPU_CORE_CORTEX_M4) || defined (BRS_CPU_CORE_CORTEX_M4F) || defined (BRS_CPU_CORE_CORTEX_M7)
/*****************************************************************************/
/**
 * @brief      restart ECU (issue a software reset or jump to startup code)
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from e.g. ECU state handling
 */
/*****************************************************************************/
void BrsHwSoftwareResetECU(void);

/*****************************************************************************/
/**
 * @brief      This API is used to enable an interrupt source in the core
 *             interrupt controller (NVIC).
 * @pre        -
 * @param[in]  Source to be enabled.
 * @param[in]  Priority level to be set.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 */
/*****************************************************************************/
void BrsHw_EnableInterrupt(uint32, uint8);

/*****************************************************************************/
/**
 * @brief      This API is used to disable an interrupt source in the core
 *             interrupt controller (NVIC).
 * @pre        -
 * @param[in]  Source to be disabled.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 */
/*****************************************************************************/
void BrsHw_DisableInterrupt(uint32);

/*****************************************************************************/
/**
 * @brief      This API is used to trigger the given software interrupt source.
 * @pre        
 * @param[in]  Source to be triggered.
 *             Some derivatives only support few software triggerable sources,
 *             check for their validity.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 */
/*****************************************************************************/
void BrsHw_TriggerSoftwareInterrupt(uint32);

#endif /*BRS_CPU_CORE_CORTEX_Mx*/

#endif /*_ARMBRSHW_H_*/
