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
 *              File: Os_Link_Core0_Stacks.lsl
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  STACK SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_KERNEL_STACKS )
group OS_CORE0_STACKS_GROUP(ordered, contiguous, fill)
{

/* Stack: vHsmMainFunctionTask (4096 Byte) */
group OS_STACK_VHSMMAINFUNCTIONTASK_VAR_NOINIT_GROUP(ordered, contiguous, fill)
{
  select "[.]bss.OS_STACK_VHSMMAINFUNCTIONTASK_VAR_NOINIT";
}
"_OS_STACK_VHSMMAINFUNCTIONTASK_VAR_NOINIT_START" = "_lc_gb_OS_STACK_VHSMMAINFUNCTIONTASK_VAR_NOINIT_GROUP";
"_OS_STACK_VHSMMAINFUNCTIONTASK_VAR_NOINIT_END" = "_lc_ge_OS_STACK_VHSMMAINFUNCTIONTASK_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_VHSMMAINFUNCTIONTASK_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_VHSMMAINFUNCTIONTASK_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio4294967294 (4096 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO4294967294_VAR_NOINIT_GROUP(ordered, contiguous, fill)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO4294967294_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO4294967294_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO4294967294_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO4294967294_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO4294967294_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO4294967294_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO4294967294_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio20 (4096 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO20_VAR_NOINIT_GROUP(ordered, contiguous, fill)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO20_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO20_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO20_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO20_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO20_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO20_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO20_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio10 (4096 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO10_VAR_NOINIT_GROUP(ordered, contiguous, fill)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO10_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO10_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO10_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO10_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO10_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO10_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO10_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio4294967295 (1024 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_GROUP(ordered, contiguous, fill)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Startup (1024 Byte) */
group OS_STACK_OSCORE0_STARTUP_VAR_NOINIT_GROUP(ordered, contiguous, fill)
{
  select "[.]bss.OS_STACK_OSCORE0_STARTUP_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_STARTUP_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_STARTUP_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_STARTUP_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_STARTUP_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_STARTUP_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_STARTUP_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Shutdown (1024 Byte) */
group OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_GROUP(ordered, contiguous, fill)
{
  select "[.]bss.OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Kernel (1024 Byte) */
group OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_GROUP(ordered, contiguous, fill)
{
  select "[.]bss.OS_STACK_OSCORE0_KERNEL_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_KERNEL_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Isr_Core (1024 Byte) */
group OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_GROUP(ordered, contiguous, fill)
{
  select "[.]bss.OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Init (1024 Byte) */
group OS_STACK_OSCORE0_INIT_VAR_NOINIT_GROUP(ordered, contiguous, fill)
{
  select "[.]bss.OS_STACK_OSCORE0_INIT_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_INIT_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_INIT_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_INIT_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_INIT_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_INIT_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_INIT_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Error (1024 Byte) */
group OS_STACK_OSCORE0_ERROR_VAR_NOINIT_GROUP(ordered, contiguous, fill)
{
  select "[.]bss.OS_STACK_OSCORE0_ERROR_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_ERROR_VAR_NOINIT_GROUP";

/* Stack: OsCore0_Task_Prio4294967293 (256 Byte) */
group OS_STACK_OSCORE0_TASK_PRIO4294967293_VAR_NOINIT_GROUP(ordered, contiguous, fill)
{
  select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO4294967293_VAR_NOINIT";
}
"_OS_STACK_OSCORE0_TASK_PRIO4294967293_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE0_TASK_PRIO4294967293_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE0_TASK_PRIO4294967293_VAR_NOINIT_END" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO4294967293_VAR_NOINIT_GROUP" - 1;
"_OS_STACK_OSCORE0_TASK_PRIO4294967293_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACK_OSCORE0_TASK_PRIO4294967293_VAR_NOINIT_GROUP";

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


