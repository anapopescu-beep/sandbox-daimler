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
 *            Module: Os
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_EntryAsm_Lcfg.asm
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

#include "Os_Cfg.h"
#if defined(OS_CFG_COMPILER_IAR)
# include "Os_Hal_Entry_IAR.inc"
#else
# include "Os_Hal_Entry.inc"
#endif

  OS_HAL_ASM_PRESERVE8


  OS_HAL_ASM_CODE_SECTION(OS_INTVEC_CORE0_CODE)
  OS_HAL_ASM_ALIGN4

  /* Export of the ISR wrappers on OsCore0 */
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Exception_15)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_17)
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_19)


   /* Definitions of the ISR wrappers on OsCore0 */
  OS_HAL_ASM_IMPORT(OsCfg_Isr_CounterIsr_SystemTimer)
  OS_HAL_ASM_THUMB_FUNCTION
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Exception_15)
  Os_Hal_Cat2Entry_Interrupt OsCfg_Isr_CounterIsr_SystemTimer /* COMP_WARN_OS_HAL_MOV_PC_BIT_ZERO_NOT_SET */
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Exception_15)

  OS_HAL_ASM_IMPORT(OsCfg_Isr_vHsm_Hal_InternalRequestIsr)
  OS_HAL_ASM_THUMB_FUNCTION
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_17)
  Os_Hal_Cat2Entry_Interrupt OsCfg_Isr_vHsm_Hal_InternalRequestIsr /* COMP_WARN_OS_HAL_MOV_PC_BIT_ZERO_NOT_SET */
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_17)

  OS_HAL_ASM_IMPORT(vHsm_Hal_ExternalRequestIsr)
  OS_HAL_ASM_THUMB_FUNCTION
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_19)
  Os_Hal_Entry_Interrupt vHsm_Hal_ExternalRequestIsr /* COMP_WARN_OS_HAL_MOV_PC_BIT_ZERO_NOT_SET */
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_19)



  OS_HAL_ASM_SECTION_END


  OS_HAL_ASM_MODULE_END

