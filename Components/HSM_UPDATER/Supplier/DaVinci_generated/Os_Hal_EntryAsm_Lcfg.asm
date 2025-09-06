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
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000612_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_EntryAsm_Lcfg.asm
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
  OS_HAL_ASM_EXPORT(Os_Isr_Core0_Interrupt_19)


   /* Definitions of the ISR wrappers on OsCore0 */
  OS_HAL_ASM_IMPORT(OsCfg_Isr_vHsm_Hal_ExternalRequestIsr)
  OS_HAL_ASM_THUMB_FUNCTION
OS_HAL_ASM_FUNCTION_BEGIN(Os_Isr_Core0_Interrupt_19)
  Os_Hal_Cat2Entry_Interrupt OsCfg_Isr_vHsm_Hal_ExternalRequestIsr /* COMP_WARN_OS_HAL_MOV_PC_BIT_ZERO_NOT_SET */
  OS_HAL_ASM_FUNCTION_END(Os_Isr_Core0_Interrupt_19)



  OS_HAL_ASM_SECTION_END


  OS_HAL_ASM_MODULE_END

