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
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200333_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Link_Core0_Stacks.lsl
 *   Generation Time: 2022-10-10 07:56:35
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D02
 *      Tool Version: DaVinci Configurator Classic (beta) 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 *  STACK SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_KERNEL_STACKS )
group OS_CORE0_STACKS_GROUP(ordered, contiguous, fill)
{

/* Stack: ApplTask_Core0_HighPrio (512 Byte) */
group OS_STACK_APPLTASK_CORE0_HIGHPRIO_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_APPLTASK_CORE0_HIGHPRIO_VAR_NOINIT";
}
"_OS_STACK_APPLTASK_CORE0_HIGHPRIO_VAR_NOINIT_START" = "_lc_gb_OS_STACK_APPLTASK_CORE0_HIGHPRIO_VAR_NOINIT_GROUP";
"_OS_STACK_APPLTASK_CORE0_HIGHPRIO_VAR_NOINIT_END" = "_lc_ge_OS_STACK_APPLTASK_CORE0_HIGHPRIO_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_APPLTASK_CORE0_HIGHPRIO_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_APPLTASK_CORE0_HIGHPRIO_VAR_NOINIT_GROUP";

/* Stack: ApplTask_Core0_LowPrio (1280 Byte) */
group OS_STACK_APPLTASK_CORE0_LOWPRIO_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_APPLTASK_CORE0_LOWPRIO_VAR_NOINIT";
}
"_OS_STACK_APPLTASK_CORE0_LOWPRIO_VAR_NOINIT_START" = "_lc_gb_OS_STACK_APPLTASK_CORE0_LOWPRIO_VAR_NOINIT_GROUP";
"_OS_STACK_APPLTASK_CORE0_LOWPRIO_VAR_NOINIT_END" = "_lc_ge_OS_STACK_APPLTASK_CORE0_LOWPRIO_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_APPLTASK_CORE0_LOWPRIO_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_APPLTASK_CORE0_LOWPRIO_VAR_NOINIT_GROUP";

/* Stack: BswTask_Core0_HighPrio (2048 Byte) */
group OS_STACK_BSWTASK_CORE0_HIGHPRIO_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_BSWTASK_CORE0_HIGHPRIO_VAR_NOINIT";
}
"_OS_STACK_BSWTASK_CORE0_HIGHPRIO_VAR_NOINIT_START" = "_lc_gb_OS_STACK_BSWTASK_CORE0_HIGHPRIO_VAR_NOINIT_GROUP";
"_OS_STACK_BSWTASK_CORE0_HIGHPRIO_VAR_NOINIT_END" = "_lc_ge_OS_STACK_BSWTASK_CORE0_HIGHPRIO_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_BSWTASK_CORE0_HIGHPRIO_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_BSWTASK_CORE0_HIGHPRIO_VAR_NOINIT_GROUP";

/* Stack: BswTask_Core0_LowPrio (2048 Byte) */
group OS_STACK_BSWTASK_CORE0_LOWPRIO_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_BSWTASK_CORE0_LOWPRIO_VAR_NOINIT";
}
"_OS_STACK_BSWTASK_CORE0_LOWPRIO_VAR_NOINIT_START" = "_lc_gb_OS_STACK_BSWTASK_CORE0_LOWPRIO_VAR_NOINIT_GROUP";
"_OS_STACK_BSWTASK_CORE0_LOWPRIO_VAR_NOINIT_END" = "_lc_ge_OS_STACK_BSWTASK_CORE0_LOWPRIO_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_BSWTASK_CORE0_LOWPRIO_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_BSWTASK_CORE0_LOWPRIO_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Error (1024 Byte) */
group OS_STACK_OSCORE0_ERROR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_ERROR_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Init (1024 Byte) */
group OS_STACK_OSCORE0_INIT_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_INIT_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_INIT_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_INIT_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_INIT_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_INIT_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_INIT_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_INIT_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Isr_Core (1024 Byte) */
group OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Kernel (1024 Byte) */
group OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_KERNEL_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Shutdown (1024 Byte) */
group OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio0 (1280 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO0_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO0_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO0_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO0_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO0_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO0_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO0_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio100 (1024 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio4294967295 (64 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio5 (4096 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO5_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO5_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO5_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO5_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO5_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO5_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO5_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO5_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio90 (256 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio99 (256 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO99_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO99_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO99_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO99_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO99_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO99_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO99_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO99_VAR_NOINIT_GROUP";

/* Stack: OsTask_ALV_BeltFunctionAlgo (512 Byte) */
group OS_STACK_OSTASK_ALV_BELTFUNCTIONALGO_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select "[.]bss.OS_STACK_OSTASK_ALV_BELTFUNCTIONALGO_VAR_NOINIT";
}
"_OS_STACK_OSTASK_ALV_BELTFUNCTIONALGO_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSTASK_ALV_BELTFUNCTIONALGO_VAR_NOINIT_GROUP";
"_OS_STACK_OSTASK_ALV_BELTFUNCTIONALGO_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSTASK_ALV_BELTFUNCTIONALGO_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSTASK_ALV_BELTFUNCTIONALGO_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSTASK_ALV_BELTFUNCTIONALGO_VAR_NOINIT_GROUP";

} /* OS_CORE0_STACKS_GROUP */
"_OS_CORE0_STACKS_START" = "_lc_gb_OS_CORE0_STACKS_GROUP";
"_OS_CORE0_STACKS_END" = "_lc_ge_OS_CORE0_STACKS_GROUP" - 1;
"_OS_CORE0_STACKS_LIMIT" = "_lc_ge_OS_CORE0_STACKS_GROUP";
"_OS_CORE0_STACKS_END_ALIAS" = (("_lc_ge_OS_CORE0_STACKS_GROUP")&~0xF0000000)|0xD0000000;
"_OS_CORE0_STACKS_LIMIT_ALIAS" = (("_lc_ge_OS_CORE0_STACKS_GROUP")&~0xF0000000)|0xD0000000;

#endif

#ifdef OS_LINK_KERNEL_STACKS
# undef OS_LINK_KERNEL_STACKS
#endif


