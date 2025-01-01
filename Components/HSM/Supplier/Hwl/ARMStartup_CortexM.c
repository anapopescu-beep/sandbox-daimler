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
/** \file  File:  ARMStartup_CortexM.c
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsHw for all platforms with ARM core Cortex-M
 *     Template:  This file is reviewed according to Brs_Template@Implementation[1.02.00]
 *
 *  \brief Description:  This file contains the assembler part of the BRS StartUpCode.
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
#include "BrsMain.h"
#include "vLinkGen_Lcfg.h"

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 *********************************************************************************************************************/
#if defined (BRS_COMP_TASKING)    

#else
  #error "Unknown compiler specified!"
#endif

#if (BRS_CPU_CORE_AMOUNT > 3)
  #error "Only up to 3 cores are supported by this StartupCode yet!"
#endif

#if (VLINKGEN_CFG_MAJOR_VERSION != 2u)
  #error "This StartUpCode is dependent to the vLinkGen version! vLinkGen major version does not fit!"
#else
# if (VLINKGEN_CFG_MINOR_VERSION < 0u)
  #error "This StartUpCode is dependent to the vLinkGen version! Your vLinkGen minor version is too old!"
# endif
#endif

/* =========================================================================== */
/*                                                                             */
/* Description: Definition of external functions                               */
/*                                                                             */
/* =========================================================================== */



#if defined (BRS_FPU_USED)
#define BRSHW_CPACR (*((volatile uint32 *)(0xE000ED88UL)))
#define BRSHW_FPCCR (*((volatile uint32 *)(0xE000EF34UL)))
/* Enable the FPU coprocessors, because some HwSpec functions and tests use floating point numbers. */
/* must be called from startup code as Os_Init expects the FPU registers to be setup by the customer. */
void Brs_EnableFpu(void)
{
  BRSHW_CPACR = BRSHW_CPACR | (0xFUL << 20);
  BRSHW_FPCCR = (BRSHW_FPCCR & ~(0x1UL << 30)) | (0x1UL << 31); /* Set FPCCR.ASPEN, Reset FPCCR.LSPEN. */
}
#endif /*BRS_FPU_USED*/

/* =========================================================================== */
/*                                                                             */
/* Description: Entry point for all cores                                      */
/*                                                                             */
/* =========================================================================== */


#if defined (BRS_COMP_TASKING)
  ___asm(.EXTERN __section_stack_c0_end)
  ___asm(.EXTERN Brs_PreMainStartup)
  ___asm(.EXTERN BrsMainExceptionStartup)
  ___asm(.EXTERN vLinkGen_ZeroInit_Early_Blocks)
  ___asm(.EXTERN vLinkGen_ZeroInit_Early_Groups)
#endif /*BRS_COMP_TASKING*/

BRS_SECTION_CODE(brsStartup)
/* reset */
 BRS_GLOBAL(brsStartupEntry)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(brsStartupEntry)


 BRS_BRANCH(brsPreAsmStartupHook)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()


/* =========================================================================== */
/*                                                                             */
/* Description: Optional hook for platform specific tasks                      */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(brsPreAsmStartupHook)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(brsPreAsmStartupHook)
/* Nothing to do here */

 BRS_BRANCH(coreRegisterInit)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize core ID independent core registers                  */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(coreRegisterInit)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(coreRegisterInit)
/* Nothing to do for Cortex-M */

 BRS_BRANCH(coreRegisterInit2)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core ID dependent core registers                */
/*              Configure INTBP and EBASE address.                             */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(coreRegisterInit2)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(coreRegisterInit2)
/* Nothing to do for Cortex-M */

 BRS_BRANCH(brsStartupZeroInitLoop)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize memory blocks and areas with zero                   */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(brsStartupZeroInitLoop)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(brsStartupZeroInitLoop)

 BRS_READ_COREID(R0)

/* Initialize memory sections with zeros */
#if defined (VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS)
# if (VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS>1uL)
 __as1(LDR  R1, =vLinkGen_ZeroInit_Early_Blocks)

BRS_LABEL(startup_block_zero_init_start)
 __as1(MOV  R2, R1)

 __as2(ADD  R1, R1, #16)

 __as1(LDR  R3, [R2])     /* vLinkGen_ZeroInit_Early_Blocks->start */
 __as2(LDR  R4, [R2,#4])  /* vLinkGen_ZeroInit_Early_Blocks->end */
 __as2(LDR  R5, [R2, #8]) /* vLinkGen_ZeroInit_Early_Blocks->core */
 /* Alignment parameter actually not used here */

/* Verify if the end of struct vLinkGen_ZeroInit_Early_Blocks is reached, by checking if start == 0, end == 0 and core == 0 */
#   if defined (BRS_CPU_CORE_CORTEX_M0) || defined (BRS_CPU_CORE_CORTEX_M0PLUS)
 __as1(MOVS  R6, #0)
#   else
 __as1(MOV  R6, #0)
#   endif

  __as2(ORR  R6, R6, R3) /* Or with vLinkGen_ZeroInit_Early_Blocks->start */
  __as2(ORR  R6, R6, R4) /* Or with vLinkGen_ZeroInit_Early_Blocks->end */
  __as2(ORR  R6, R6, R5) /* Or with vLinkGen_ZeroInit_Early_Blocks->core */

 BRS_BRANCH_EQUAL(R6, #0, startup_block_zero_init_end) /* If Start, end and core is equal to zero -> Finished */

 BRS_BRANCH_NOT_EQUAL(R0, R5, startup_block_zero_init_start) /* If InitCore is not running -> go to the next array entry */

#   if defined (BRS_CPU_CORE_CORTEX_M0) || defined (BRS_CPU_CORE_CORTEX_M0PLUS)
 __as1(MOVS  R6, #0)
#   else
 __as1(MOV  R6, #0)
#   endif

BRS_LABEL(startup_block_zero_init_loop_start)
 __as1(STR  R6, [R3]) /* must be an aligned memory access! */

 __as2(ADD  R3, R3, #4)

 BRS_BRANCH_EQUAL(R3, R4, startup_block_zero_init_start) /* If Start is same with End address-> Finished. */

 BRS_BRANCH(startup_block_zero_init_loop_start)
BRS_LABEL(startup_block_zero_init_end)
# endif /*VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS>1uL*/

#else
  #error "Mandatory define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS missing within vLinkGen configuration!"
#endif /*VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS*/

#if defined (VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS)
# if (VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS>1uL)
 __as1(LDR  R1, =vLinkGen_ZeroInit_Early_Groups)

BRS_LABEL(startup_area_zero_init_start)
 __as1(MOV  R2, R1)

 __as2(ADD  R1, R1, #16)

 __as1(LDR  R3, [R2])     /* vLinkGen_ZeroInit_Early_Groups->start */
 __as2(LDR  R4, [R2,#4])  /* vLinkGen_ZeroInit_Early_Groups->end */
 __as2(LDR  R5, [R2, #8]) /* vLinkGen_ZeroInit_Early_Groups->core */
 /* Alignment parameter actually not used here */

/* Verify if the end of struct vLinkGen_ZeroInit_Early_Groups is reached, by checking if start == 0, end == 0 and core == 0 */
#   if defined (BRS_CPU_CORE_CORTEX_M0) || defined (BRS_CPU_CORE_CORTEX_M0PLUS)
 __as1(MOVS  R6, #0)
#   else
 __as1(MOV  R6, #0)
#   endif

  __as2(ORR  R6, R6, R3) /* Or with vLinkGen_ZeroInit_Early_Groups->start */
  __as2(ORR  R6, R6, R4) /* Or with vLinkGen_ZeroInit_Early_Groups->end */
  __as2(ORR  R6, R6, R5) /* Or with vLinkGen_ZeroInit_Early_Groups->core */

 BRS_BRANCH_EQUAL(R6, #0,  startup_area_zero_init_end) /* If Start, end and core is equal to zero -> Finished */

 BRS_BRANCH_NOT_EQUAL(R0, R5, startup_area_zero_init_start) /* If InitCore is not running -> go to the next array entry */

#   if defined (BRS_CPU_CORE_CORTEX_M0) || defined (BRS_CPU_CORE_CORTEX_M0PLUS)
 __as1(MOVS  R6, #0)
#   else
 __as1(MOV  R6, #0)
#   endif

BRS_LABEL(startup_area_zero_init_loop_start)
 __as1(STR  R6, [R3]) /* must be an aligned memory access! */

 __as2(ADD  R3, R3, #4)

 BRS_BRANCH_EQUAL(R3, R4, startup_area_zero_init_start) /* If Start is same with End address-> Finished. */

 BRS_BRANCH(startup_area_zero_init_loop_start)
BRS_LABEL(startup_area_zero_init_end)
# endif /*VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS>1uL*/

#else
  #error "Mandatory define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS missing within vLinkGen configuration!"
#endif /*VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS*/

/* Branch to the core ID specific stack pointer init routines */
#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
# if (BRS_CPU_CORE_AMOUNT > 2)
 BRS_BRANCH_EQUAL(r0,BRSHW_DERIVATIVE_CORE2_ID,StackPointerInit_c2)
# endif

 BRS_BRANCH_EQUAL(r0,BRSHW_DERIVATIVE_CORE1_ID,StackPointerInit_c1)

 BRS_BRANCH_EQUAL(r0,BRSHW_DERIVATIVE_CORE0_ID,StackPointerInit_c0)

 /* Still here? ID is not supported yet -> BrsMainExceptionStartup */
 BRS_EXTERN_BRANCH(BrsMainExceptionStartup)
#endif /*BRS_ENABLE_OS_MULTICORESUPPORT*/

/* Jump to Core0 init function for singlecore derivatives */
 BRS_BRANCH(StackPointerInit_c0)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()

#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
# if (BRS_CPU_CORE_AMOUNT > 2)
/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core registers with specific init values        */
/*              (Core 2).                                                      */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(StackPointerInit_c2)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(StackPointerInit_c2)

/* Initialization of the stack pointer */
 __as1(LDR  R0, =__section_stack_c2_end)
 __as1(MOV  SP, R0)

 BRS_BRANCH(coreRegisterInit3)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()
# endif /*BRS_CPU_CORE_AMOUNT>2*/

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core registers with specific init values        */
/*              (Core 1).                                                      */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(StackPointerInit_c1)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(StackPointerInit_c1)

/* Initialization of the stack pointer */
 __as1(LDR  R0, =__section_stack_c1_end)
 __as1(MOV  SP, R0)

 BRS_BRANCH(coreRegisterInit3)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()
#endif /*BRS_ENABLE_OS_MULTICORESUPPORT*/

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core registers with specific init values        */
/*              (Core 0). Also used for singlecore derivatives                 */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(StackPointerInit_c0)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(StackPointerInit_c0)

/* Initialization of the stack pointer */
 __as1(LDR  R0, =__section_stack_c0_end)
 __as1(MOV  SP, R0)

 BRS_BRANCH(coreRegisterInit3)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize additional core registers                           */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(coreRegisterInit3)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(coreRegisterInit3)
BRS_MULTILINE_ASM_END()
#if defined (BRS_FPU_USED)
BRS_EXTERN_BRANCH(Brs_EnableFpu)
#endif

/* =========================================================================== */
/*                                                                             */
/* Description: Jump to Brs_PreMainStartup() (BrsMainStartup.c)                */
/*                                                                             */
/* =========================================================================== */
 BRS_EXTERN_BRANCH(Brs_PreMainStartup)

/* =========================================================================== */
/*                                                                             */
/* Description: Jump to BrsMainExceptionStartup() in case of an unexpected     */
/*              return from PreMain/main                                       */
/*                                                                             */
/* =========================================================================== */
 BRS_EXTERN_BRANCH(BrsMainExceptionStartup)

BRS_GLOBAL_END()


#if defined (BRS_COMP_TASKING)
BRS_END_SEC()
#endif
