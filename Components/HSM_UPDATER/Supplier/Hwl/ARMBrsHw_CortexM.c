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
/** \file  File:  ARMBrsHw_CortexM.c
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsHw for all platforms with ARM core Cortex-M
 *     Template:  This file is reviewed according to Brs_Template@Implementation[1.02.01]
 *
 *  \brief Description:  This is a global, platform-independent file for the ARM-BRS.
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
 *  Refer to BrsHw.h.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "BrsHw.h"

#if !defined (BRS_ENABLE_FBL_SUPPORT)
  #include "Os.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if (ARMBRSHW_CORTEXM_VERSION != 0x0102u)
  #error "Header and source file are inconsistent!"
#endif
#if (ARMBRSHW_CORTEXM_BUGFIX_VERSION != 0x02u)
  #error "Different versions of bugfix in Header and Source used!"
#endif

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 *********************************************************************************************************************/
#if defined (BRS_COMP_TASKING)    

#else
  #error "Unknown compiler specified!"
#endif

/**********************************************************************************************************************
 *  DEFINITION + MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONST VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL VARIABLES AND LOCAL HW REGISTERS
 *********************************************************************************************************************/
/* Needed for BASEPRI analyzation within BrsHwDisableInterruptAtPowerOn() */
volatile uint8 brsDisIntPrioTmp;
volatile uint8 brsDisIntITmp;

/**********************************************************************************************************************
 *  CONTROLLER CONFIGURATION REGISTERS
 *********************************************************************************************************************/
/* lowest 4 bit -> INTLINESNUM -> No. of last implemented NVIC_IPR-Register (4 int prios / 32bit-Register) */
#define BRSHW_MCORE_NVIC_ICTR    BRSHW_IOS(uint32, (0xE000E004UL))
#define BRSHW_MCORE_NVIC_IPR(X)  BRSHW_IOS(uint8, (0xE000E400UL+(X)))

/* Reset control registers */
#define BRSHW_MCORE_SCS_AIRCR    BRSHW_IOS(uint32, 0xE000ED0CUL)  /* Reset control registers for Cortex-M */

/**********************************************************************************************************************
 *  LOCAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONST VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PROTOTYPES OF GLOBAL FUNCTIONS
 *********************************************************************************************************************/
extern void BrsMain_SoftwareResetECU_Hook(void);

/**********************************************************************************************************************
 *  PROTOTYPES OF LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/*****************************************************************************/
/* @brief      Disable the global system interrupt.
 * @pre        Must be the first function call in main@BrsMain
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from main@BrsMain at power on initialization
 *****************************************************************************/
void BrsHwDisableInterruptAtPowerOn(void)
{
#if defined (BRS_CPU_CORE_CORTEX_M0) || defined (BRS_CPU_CORE_CORTEX_M0PLUS)
  /* Global disable IRQs, EXCEPT HardFault and NMI! */



#else
  uint8 brsIdx;

  brsDisIntITmp = 0; /* prevent compiler warning */

  /* get pointer to brsDisIntITmp */
  __as1(LDR  R4, =brsDisIntITmp)
  /* analyze amount of supported bits in priority registers and BASEPRI
   * (BASEPRI bits not supported are "Read All Zero, Ignore Writes") */
   /* BASEPRI = 255 */
  __as1(MOV  R2, #255)
  __as1(MSR  basepri, R2)
  /* brsDisIntITmp = BASEPRI */
  __as1(MRS  R2, basepri)
  __as1(STRB R2, [R4])

  brsDisIntPrioTmp = 0xFF;
  for (brsIdx = 0; brsIdx < 8; brsIdx++)
  {
    if (((uint8)(1 << brsIdx)) & brsDisIntITmp) 
    {
      brsDisIntPrioTmp = (uint8)(1 << brsIdx);
      break;
    }
  }
  if (brsDisIntPrioTmp == 0xFF)
  {
    /* BASEPRI not writable! */
    while (1);
  }

  /* get pointer to brsDisIntPrioTmp */
  __as1(LDR  R4, =brsDisIntPrioTmp)
  __as1(LDR  R2, [R4])
  /* BASEPRI = brsDisIntPrioTmp */
  __as1(MSR  basepri, R2)

  /* evaluate amount of available NVIC_IPR regs within this Cortex-M* core */
  brsDisIntITmp = ((BRSHW_MCORE_NVIC_ICTR & 0x0000000F)+1) << 5;

  /* set all interrupt priorities to BASEPRI priority -> disable all interrupts
   * (if an interrupts shall be enabled -> set its NVIC_IPR reg to 0) */
  for (brsIdx = 0; brsIdx < brsDisIntITmp; brsIdx++)
  {
    BRSHW_MCORE_NVIC_IPR(brsIdx) = brsDisIntPrioTmp;
  }
#endif /*BRS_CPU_CORE_CORTEX_Mx*/
}

/*****************************************************************************/
/* @brief      Restart ECU (issue a software reset or jump to startup code)
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from e.g. ECU state handling
 *****************************************************************************/
void BrsHwSoftwareResetECU(void)
{
  BrsMain_SoftwareResetECU_Hook();

#if !defined (BRS_ENABLE_FBL_SUPPORT) /* FBL is always running in polling mode with interrupts disabled */
  DisableAllInterrupts();
#endif

  /* Vector Key 0x05FA has to be writen together with setting the SYSRESETREQ to 1,
   * otherwise the reset request is not accepted */

  BRSHW_MCORE_SCS_AIRCR = 0x05FA0004;

  while (1)
  {
    /* Wait until reset/watchdog reset occurs */
  }
}

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
void BrsHwTime100NOP(void)
{
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
  BRSHWNOP10();
}

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
void BrsHw_EnableInterrupt(uint32 Source, uint8 Priority)
{
  NVIC_ICPR((uint32)(Source/32)) = (1UL << (Source%32)); /* Clear pending interrupt source. */

  NVIC_IPR(Source) = Priority; /* Set interrupt priority. */

  NVIC_ISER((uint32)(Source/32)) = (1UL << (Source%32)); /* Enable interrupt source. */
}

/*****************************************************************************/
/* @brief      This API is used to disable an interrupt source in the core
 *             interrupt controller (NVIC).
 * @pre        -
 * @param[in]  Source to be disabled.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 *****************************************************************************/
void BrsHw_DisableInterrupt(uint32 Source)
{
  NVIC_ICER((uint32)(Source/32)) = (1UL << (Source%32)); /* Disable interrupt source. */
}

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
void BrsHw_TriggerSoftwareInterrupt(uint32 Source)
{
  NVIC_ISPR((uint32)(Source/32)) = (1UL << (Source%32)); /* Trigger software interrupt source. */
}
