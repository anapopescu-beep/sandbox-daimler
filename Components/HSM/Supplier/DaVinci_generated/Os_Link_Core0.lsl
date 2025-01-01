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
 *              File: Os_Link_Core0.lsl
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CODE SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_INTVEC_CODE )
if (exists(".text.OS_INTVEC_CORE0_CODE"))
{
  group OS_INTVEC_CORE0_CODE_GROUP(align=2048)
  {
    select "[.]text.OS_INTVEC_CORE0_CODE";
  }
  "_OS_INTVEC_CORE0_CODE_START" = "_lc_gb_OS_INTVEC_CORE0_CODE_GROUP";
  "_OS_INTVEC_CORE0_CODE_END" = "_lc_ge_OS_INTVEC_CORE0_CODE_GROUP" - 1;
  "_OS_INTVEC_CORE0_CODE_LIMIT" = "_lc_ge_OS_INTVEC_CORE0_CODE_GROUP";
}
else
{
  "_OS_INTVEC_CORE0_CODE_START" = 0;
  "_OS_INTVEC_CORE0_CODE_END" = 0;
  "_OS_INTVEC_CORE0_CODE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_EXCVEC_CODE )
if (exists(".text.OS_EXCVEC_CORE0_CODE"))
{
  group OS_EXCVEC_CORE0_CODE_GROUP
  {
    select "[.]text.OS_EXCVEC_CORE0_CODE";
  }
  "_OS_EXCVEC_CORE0_CODE_START" = "_lc_gb_OS_EXCVEC_CORE0_CODE_GROUP";
  "_OS_EXCVEC_CORE0_CODE_END" = "_lc_ge_OS_EXCVEC_CORE0_CODE_GROUP" - 1;
  "_OS_EXCVEC_CORE0_CODE_LIMIT" = "_lc_ge_OS_EXCVEC_CORE0_CODE_GROUP";
}
else
{
  "_OS_EXCVEC_CORE0_CODE_START" = 0;
  "_OS_EXCVEC_CORE0_CODE_END" = 0;
  "_OS_EXCVEC_CORE0_CODE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CALLOUT_CODE )
if (exists(".text.OS_Default_Init_Task_CODE"))
{
  group OS_Default_Init_Task_CODE_GROUP
  {
    select "[.]text.OS_Default_Init_Task_CODE";
  }
  "_OS_Default_Init_Task_CODE_START" = "_lc_gb_OS_Default_Init_Task_CODE_GROUP";
  "_OS_Default_Init_Task_CODE_END" = "_lc_ge_OS_Default_Init_Task_CODE_GROUP" - 1;
  "_OS_Default_Init_Task_CODE_LIMIT" = "_lc_ge_OS_Default_Init_Task_CODE_GROUP";
}
else
{
  "_OS_Default_Init_Task_CODE_START" = 0;
  "_OS_Default_Init_Task_CODE_END" = 0;
  "_OS_Default_Init_Task_CODE_LIMIT" = 0;
}
if (exists(".text.OS_Default_Init_Task_Trusted_CODE"))
{
  group OS_Default_Init_Task_Trusted_CODE_GROUP
  {
    select "[.]text.OS_Default_Init_Task_Trusted_CODE";
  }
  "_OS_Default_Init_Task_Trusted_CODE_START" = "_lc_gb_OS_Default_Init_Task_Trusted_CODE_GROUP";
  "_OS_Default_Init_Task_Trusted_CODE_END" = "_lc_ge_OS_Default_Init_Task_Trusted_CODE_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_CODE_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_CODE_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_CODE_START" = 0;
  "_OS_Default_Init_Task_Trusted_CODE_END" = 0;
  "_OS_Default_Init_Task_Trusted_CODE_LIMIT" = 0;
}
if (exists(".text.OS_OsTask_CODE"))
{
  group OS_OsTask_CODE_GROUP
  {
    select "[.]text.OS_OsTask_CODE";
  }
  "_OS_OsTask_CODE_START" = "_lc_gb_OS_OsTask_CODE_GROUP";
  "_OS_OsTask_CODE_END" = "_lc_ge_OS_OsTask_CODE_GROUP" - 1;
  "_OS_OsTask_CODE_LIMIT" = "_lc_ge_OS_OsTask_CODE_GROUP";
}
else
{
  "_OS_OsTask_CODE_START" = 0;
  "_OS_OsTask_CODE_END" = 0;
  "_OS_OsTask_CODE_LIMIT" = 0;
}
if (exists(".text.OS_Ostask_HighPrio_CODE"))
{
  group OS_Ostask_HighPrio_CODE_GROUP
  {
    select "[.]text.OS_Ostask_HighPrio_CODE";
  }
  "_OS_Ostask_HighPrio_CODE_START" = "_lc_gb_OS_Ostask_HighPrio_CODE_GROUP";
  "_OS_Ostask_HighPrio_CODE_END" = "_lc_ge_OS_Ostask_HighPrio_CODE_GROUP" - 1;
  "_OS_Ostask_HighPrio_CODE_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_CODE_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_CODE_START" = 0;
  "_OS_Ostask_HighPrio_CODE_END" = 0;
  "_OS_Ostask_HighPrio_CODE_LIMIT" = 0;
}
if (exists(".text.OS_vHsmMainFunctionTask_CODE"))
{
  group OS_vHsmMainFunctionTask_CODE_GROUP
  {
    select "[.]text.OS_vHsmMainFunctionTask_CODE";
  }
  "_OS_vHsmMainFunctionTask_CODE_START" = "_lc_gb_OS_vHsmMainFunctionTask_CODE_GROUP";
  "_OS_vHsmMainFunctionTask_CODE_END" = "_lc_ge_OS_vHsmMainFunctionTask_CODE_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_CODE_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_CODE_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_CODE_START" = 0;
  "_OS_vHsmMainFunctionTask_CODE_END" = 0;
  "_OS_vHsmMainFunctionTask_CODE_LIMIT" = 0;
}
if (exists(".text.OS_vHsm_Hal_InternalRequestIsr_CODE"))
{
  group OS_vHsm_Hal_InternalRequestIsr_CODE_GROUP
  {
    select "[.]text.OS_vHsm_Hal_InternalRequestIsr_CODE";
  }
  "_OS_vHsm_Hal_InternalRequestIsr_CODE_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_CODE_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_CODE_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_CODE_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_CODE_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_CODE_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_CODE_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_CODE_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_CODE_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_INTVEC_CODE
# undef OS_LINK_INTVEC_CODE
#endif

#ifdef OS_LINK_EXCVEC_CODE
# undef OS_LINK_EXCVEC_CODE
#endif

#ifdef OS_LINK_CALLOUT_CODE
# undef OS_LINK_CALLOUT_CODE
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_FAR )
if (exists(".rodata.OS_CORE0_CONST"))
{
  group OS_CORE0_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_CORE0_CONST";
  }
  "_OS_CORE0_CONST_START" = "_lc_gb_OS_CORE0_CONST_GROUP";
  "_OS_CORE0_CONST_END" = "_lc_ge_OS_CORE0_CONST_GROUP" - 1;
  "_OS_CORE0_CONST_LIMIT" = "_lc_ge_OS_CORE0_CONST_GROUP";
}
else
{
  "_OS_CORE0_CONST_START" = 0;
  "_OS_CORE0_CONST_END" = 0;
  "_OS_CORE0_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_NEAR )
if (exists(".zrodata.OS_CORE0_CONST_FAST"))
{
  group OS_CORE0_CONST_FAST_GROUP(ordered, contiguous, fill)
  {
    select "[.]zrodata.OS_CORE0_CONST_FAST";
  }
  "_OS_CORE0_CONST_FAST_START" = "_lc_gb_OS_CORE0_CONST_FAST_GROUP";
  "_OS_CORE0_CONST_FAST_END" = "_lc_ge_OS_CORE0_CONST_FAST_GROUP" - 1;
  "_OS_CORE0_CONST_FAST_LIMIT" = "_lc_ge_OS_CORE0_CONST_FAST_GROUP";
}
else
{
  "_OS_CORE0_CONST_FAST_START" = 0;
  "_OS_CORE0_CONST_FAST_END" = 0;
  "_OS_CORE0_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_INTVEC_CONST )
if (exists(".rodata.OS_INTVEC_CORE0_CONST"))
{
  group OS_INTVEC_CORE0_CONST_GROUP(align=2048)
  {
    select "[.]rodata.OS_INTVEC_CORE0_CONST";
  }
  "_OS_INTVEC_CORE0_CONST_START" = "_lc_gb_OS_INTVEC_CORE0_CONST_GROUP";
  "_OS_INTVEC_CORE0_CONST_END" = "_lc_ge_OS_INTVEC_CORE0_CONST_GROUP" - 1;
  "_OS_INTVEC_CORE0_CONST_LIMIT" = "_lc_ge_OS_INTVEC_CORE0_CONST_GROUP";
}
else
{
  "_OS_INTVEC_CORE0_CONST_START" = 0;
  "_OS_INTVEC_CORE0_CONST_END" = 0;
  "_OS_INTVEC_CORE0_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_EXCVEC_CONST )
if (exists(".rodata.OS_EXCVEC_CORE0_CONST"))
{
  group OS_EXCVEC_CORE0_CONST_GROUP
  {
    select "[.]rodata.OS_EXCVEC_CORE0_CONST";
  }
  "_OS_EXCVEC_CORE0_CONST_START" = "_lc_gb_OS_EXCVEC_CORE0_CONST_GROUP";
  "_OS_EXCVEC_CORE0_CONST_END" = "_lc_ge_OS_EXCVEC_CORE0_CONST_GROUP" - 1;
  "_OS_EXCVEC_CORE0_CONST_LIMIT" = "_lc_ge_OS_EXCVEC_CORE0_CONST_GROUP";
}
else
{
  "_OS_EXCVEC_CORE0_CONST_START" = 0;
  "_OS_EXCVEC_CORE0_CONST_END" = 0;
  "_OS_EXCVEC_CORE0_CONST_LIMIT" = 0;
}
#endif


#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_FAR )
if (exists(".rodata.OS_SystemApplication_OsCore0_CONST"))
{
  group OS_SystemApplication_OsCore0_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_SystemApplication_OsCore0_CONST";
  }
  "_OS_SystemApplication_OsCore0_CONST_START" = "_lc_gb_OS_SystemApplication_OsCore0_CONST_GROUP";
  "_OS_SystemApplication_OsCore0_CONST_END" = "_lc_ge_OS_SystemApplication_OsCore0_CONST_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_CONST_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_CONST_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_CONST_START" = 0;
  "_OS_SystemApplication_OsCore0_CONST_END" = 0;
  "_OS_SystemApplication_OsCore0_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_NEAR )
if (exists(".zrodata.OS_SystemApplication_OsCore0_CONST_FAST"))
{
  group OS_SystemApplication_OsCore0_CONST_FAST_GROUP(ordered, contiguous, fill)
  {
    select "[.]zrodata.OS_SystemApplication_OsCore0_CONST_FAST";
  }
  "_OS_SystemApplication_OsCore0_CONST_FAST_START" = "_lc_gb_OS_SystemApplication_OsCore0_CONST_FAST_GROUP";
  "_OS_SystemApplication_OsCore0_CONST_FAST_END" = "_lc_ge_OS_SystemApplication_OsCore0_CONST_FAST_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_CONST_FAST_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_CONST_FAST_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_CONST_FAST_START" = 0;
  "_OS_SystemApplication_OsCore0_CONST_FAST_END" = 0;
  "_OS_SystemApplication_OsCore0_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_INIT )
















#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_FAR
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_FAR
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_INIT
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_FAR )
if (exists(".rodata.OS_Default_Init_Task_CONST"))
{
  group OS_Default_Init_Task_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_Default_Init_Task_CONST";
  }
  "_OS_Default_Init_Task_CONST_START" = "_lc_gb_OS_Default_Init_Task_CONST_GROUP";
  "_OS_Default_Init_Task_CONST_END" = "_lc_ge_OS_Default_Init_Task_CONST_GROUP" - 1;
  "_OS_Default_Init_Task_CONST_LIMIT" = "_lc_ge_OS_Default_Init_Task_CONST_GROUP";
}
else
{
  "_OS_Default_Init_Task_CONST_START" = 0;
  "_OS_Default_Init_Task_CONST_END" = 0;
  "_OS_Default_Init_Task_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_NEAR )
if (exists(".zrodata.OS_Default_Init_Task_CONST_FAST"))
{
  group OS_Default_Init_Task_CONST_FAST_GROUP(ordered, contiguous, fill)
  {
    select "[.]zrodata.OS_Default_Init_Task_CONST_FAST";
  }
  "_OS_Default_Init_Task_CONST_FAST_START" = "_lc_gb_OS_Default_Init_Task_CONST_FAST_GROUP";
  "_OS_Default_Init_Task_CONST_FAST_END" = "_lc_ge_OS_Default_Init_Task_CONST_FAST_GROUP" - 1;
  "_OS_Default_Init_Task_CONST_FAST_LIMIT" = "_lc_ge_OS_Default_Init_Task_CONST_FAST_GROUP";
}
else
{
  "_OS_Default_Init_Task_CONST_FAST_START" = 0;
  "_OS_Default_Init_Task_CONST_FAST_END" = 0;
  "_OS_Default_Init_Task_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR )
if (exists(".rodata.OS_Default_Init_Task_Trusted_CONST"))
{
  group OS_Default_Init_Task_Trusted_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_Default_Init_Task_Trusted_CONST";
  }
  "_OS_Default_Init_Task_Trusted_CONST_START" = "_lc_gb_OS_Default_Init_Task_Trusted_CONST_GROUP";
  "_OS_Default_Init_Task_Trusted_CONST_END" = "_lc_ge_OS_Default_Init_Task_Trusted_CONST_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_CONST_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_CONST_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_CONST_START" = 0;
  "_OS_Default_Init_Task_Trusted_CONST_END" = 0;
  "_OS_Default_Init_Task_Trusted_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR )
if (exists(".zrodata.OS_Default_Init_Task_Trusted_CONST_FAST"))
{
  group OS_Default_Init_Task_Trusted_CONST_FAST_GROUP(ordered, contiguous, fill)
  {
    select "[.]zrodata.OS_Default_Init_Task_Trusted_CONST_FAST";
  }
  "_OS_Default_Init_Task_Trusted_CONST_FAST_START" = "_lc_gb_OS_Default_Init_Task_Trusted_CONST_FAST_GROUP";
  "_OS_Default_Init_Task_Trusted_CONST_FAST_END" = "_lc_ge_OS_Default_Init_Task_Trusted_CONST_FAST_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_CONST_FAST_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_CONST_FAST_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_CONST_FAST_START" = 0;
  "_OS_Default_Init_Task_Trusted_CONST_FAST_END" = 0;
  "_OS_Default_Init_Task_Trusted_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_TRUSTED_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0_FAR )
if (exists(".rodata.OS_IdleTask_OsCore0_CONST"))
{
  group OS_IdleTask_OsCore0_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_IdleTask_OsCore0_CONST";
  }
  "_OS_IdleTask_OsCore0_CONST_START" = "_lc_gb_OS_IdleTask_OsCore0_CONST_GROUP";
  "_OS_IdleTask_OsCore0_CONST_END" = "_lc_ge_OS_IdleTask_OsCore0_CONST_GROUP" - 1;
  "_OS_IdleTask_OsCore0_CONST_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_CONST_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_CONST_START" = 0;
  "_OS_IdleTask_OsCore0_CONST_END" = 0;
  "_OS_IdleTask_OsCore0_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0_NEAR )
if (exists(".zrodata.OS_IdleTask_OsCore0_CONST_FAST"))
{
  group OS_IdleTask_OsCore0_CONST_FAST_GROUP(ordered, contiguous, fill)
  {
    select "[.]zrodata.OS_IdleTask_OsCore0_CONST_FAST";
  }
  "_OS_IdleTask_OsCore0_CONST_FAST_START" = "_lc_gb_OS_IdleTask_OsCore0_CONST_FAST_GROUP";
  "_OS_IdleTask_OsCore0_CONST_FAST_END" = "_lc_ge_OS_IdleTask_OsCore0_CONST_FAST_GROUP" - 1;
  "_OS_IdleTask_OsCore0_CONST_FAST_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_CONST_FAST_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_CONST_FAST_START" = 0;
  "_OS_IdleTask_OsCore0_CONST_FAST_END" = 0;
  "_OS_IdleTask_OsCore0_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_FAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_FAR
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_NEAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_INIT
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_FAR )
if (exists(".rodata.OS_OsTask_CONST"))
{
  group OS_OsTask_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_OsTask_CONST";
  }
  "_OS_OsTask_CONST_START" = "_lc_gb_OS_OsTask_CONST_GROUP";
  "_OS_OsTask_CONST_END" = "_lc_ge_OS_OsTask_CONST_GROUP" - 1;
  "_OS_OsTask_CONST_LIMIT" = "_lc_ge_OS_OsTask_CONST_GROUP";
}
else
{
  "_OS_OsTask_CONST_START" = 0;
  "_OS_OsTask_CONST_END" = 0;
  "_OS_OsTask_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_NEAR )
if (exists(".zrodata.OS_OsTask_CONST_FAST"))
{
  group OS_OsTask_CONST_FAST_GROUP(ordered, contiguous, fill)
  {
    select "[.]zrodata.OS_OsTask_CONST_FAST";
  }
  "_OS_OsTask_CONST_FAST_START" = "_lc_gb_OS_OsTask_CONST_FAST_GROUP";
  "_OS_OsTask_CONST_FAST_END" = "_lc_ge_OS_OsTask_CONST_FAST_GROUP" - 1;
  "_OS_OsTask_CONST_FAST_LIMIT" = "_lc_ge_OS_OsTask_CONST_FAST_GROUP";
}
else
{
  "_OS_OsTask_CONST_FAST_START" = 0;
  "_OS_OsTask_CONST_FAST_END" = 0;
  "_OS_OsTask_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_OSTASK
# undef OS_LINK_CONST_TASK_OSTASK
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_FAR
# undef OS_LINK_CONST_TASK_OSTASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_INIT
# undef OS_LINK_CONST_TASK_OSTASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_CONST_TASK_OSTASK_HIGHPRIO_FAR )
if (exists(".rodata.OS_Ostask_HighPrio_CONST"))
{
  group OS_Ostask_HighPrio_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_Ostask_HighPrio_CONST";
  }
  "_OS_Ostask_HighPrio_CONST_START" = "_lc_gb_OS_Ostask_HighPrio_CONST_GROUP";
  "_OS_Ostask_HighPrio_CONST_END" = "_lc_ge_OS_Ostask_HighPrio_CONST_GROUP" - 1;
  "_OS_Ostask_HighPrio_CONST_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_CONST_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_CONST_START" = 0;
  "_OS_Ostask_HighPrio_CONST_END" = 0;
  "_OS_Ostask_HighPrio_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_CONST_TASK_OSTASK_HIGHPRIO_NEAR )
if (exists(".zrodata.OS_Ostask_HighPrio_CONST_FAST"))
{
  group OS_Ostask_HighPrio_CONST_FAST_GROUP(ordered, contiguous, fill)
  {
    select "[.]zrodata.OS_Ostask_HighPrio_CONST_FAST";
  }
  "_OS_Ostask_HighPrio_CONST_FAST_START" = "_lc_gb_OS_Ostask_HighPrio_CONST_FAST_GROUP";
  "_OS_Ostask_HighPrio_CONST_FAST_END" = "_lc_ge_OS_Ostask_HighPrio_CONST_FAST_GROUP" - 1;
  "_OS_Ostask_HighPrio_CONST_FAST_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_CONST_FAST_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_CONST_FAST_START" = 0;
  "_OS_Ostask_HighPrio_CONST_FAST_END" = 0;
  "_OS_Ostask_HighPrio_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_CONST_TASK_OSTASK_HIGHPRIO_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_HIGHPRIO
# undef OS_LINK_CONST_TASK_OSTASK_HIGHPRIO
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_HIGHPRIO_FAR
# undef OS_LINK_CONST_TASK_OSTASK_HIGHPRIO_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_HIGHPRIO_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_HIGHPRIO_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_HIGHPRIO_INIT
# undef OS_LINK_CONST_TASK_OSTASK_HIGHPRIO_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK_FAR )
if (exists(".rodata.OS_vHsmMainFunctionTask_CONST"))
{
  group OS_vHsmMainFunctionTask_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_vHsmMainFunctionTask_CONST";
  }
  "_OS_vHsmMainFunctionTask_CONST_START" = "_lc_gb_OS_vHsmMainFunctionTask_CONST_GROUP";
  "_OS_vHsmMainFunctionTask_CONST_END" = "_lc_ge_OS_vHsmMainFunctionTask_CONST_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_CONST_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_CONST_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_CONST_START" = 0;
  "_OS_vHsmMainFunctionTask_CONST_END" = 0;
  "_OS_vHsmMainFunctionTask_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK_NEAR )
if (exists(".zrodata.OS_vHsmMainFunctionTask_CONST_FAST"))
{
  group OS_vHsmMainFunctionTask_CONST_FAST_GROUP(ordered, contiguous, fill)
  {
    select "[.]zrodata.OS_vHsmMainFunctionTask_CONST_FAST";
  }
  "_OS_vHsmMainFunctionTask_CONST_FAST_START" = "_lc_gb_OS_vHsmMainFunctionTask_CONST_FAST_GROUP";
  "_OS_vHsmMainFunctionTask_CONST_FAST_END" = "_lc_ge_OS_vHsmMainFunctionTask_CONST_FAST_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_CONST_FAST_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_CONST_FAST_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_CONST_FAST_START" = 0;
  "_OS_vHsmMainFunctionTask_CONST_FAST_END" = 0;
  "_OS_vHsmMainFunctionTask_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK
# undef OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK
#endif

#ifdef OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK_FAR
# undef OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK_NEAR
# undef OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK_INIT
# undef OS_LINK_CONST_TASK_VHSMMAINFUNCTIONTASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_FAR )
if (exists(".rodata.OS_CounterIsr_SystemTimer_CONST"))
{
  group OS_CounterIsr_SystemTimer_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_CounterIsr_SystemTimer_CONST";
  }
  "_OS_CounterIsr_SystemTimer_CONST_START" = "_lc_gb_OS_CounterIsr_SystemTimer_CONST_GROUP";
  "_OS_CounterIsr_SystemTimer_CONST_END" = "_lc_ge_OS_CounterIsr_SystemTimer_CONST_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_CONST_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_CONST_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_CONST_START" = 0;
  "_OS_CounterIsr_SystemTimer_CONST_END" = 0;
  "_OS_CounterIsr_SystemTimer_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_NEAR )
if (exists(".zrodata.OS_CounterIsr_SystemTimer_CONST_FAST"))
{
  group OS_CounterIsr_SystemTimer_CONST_FAST_GROUP(ordered, contiguous, fill)
  {
    select "[.]zrodata.OS_CounterIsr_SystemTimer_CONST_FAST";
  }
  "_OS_CounterIsr_SystemTimer_CONST_FAST_START" = "_lc_gb_OS_CounterIsr_SystemTimer_CONST_FAST_GROUP";
  "_OS_CounterIsr_SystemTimer_CONST_FAST_END" = "_lc_ge_OS_CounterIsr_SystemTimer_CONST_FAST_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_CONST_FAST_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_CONST_FAST_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_CONST_FAST_START" = 0;
  "_OS_CounterIsr_SystemTimer_CONST_FAST_END" = 0;
  "_OS_CounterIsr_SystemTimer_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_FAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_FAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_NEAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_INIT
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR )
if (exists(".rodata.OS_vHsm_Hal_InternalRequestIsr_CONST"))
{
  group OS_vHsm_Hal_InternalRequestIsr_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_vHsm_Hal_InternalRequestIsr_CONST";
  }
  "_OS_vHsm_Hal_InternalRequestIsr_CONST_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_CONST_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_CONST_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_CONST_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_CONST_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_CONST_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_CONST_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_CONST_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR )
if (exists(".zrodata.OS_vHsm_Hal_InternalRequestIsr_CONST_FAST"))
{
  group OS_vHsm_Hal_InternalRequestIsr_CONST_FAST_GROUP(ordered, contiguous, fill)
  {
    select "[.]zrodata.OS_vHsm_Hal_InternalRequestIsr_CONST_FAST";
  }
  "_OS_vHsm_Hal_InternalRequestIsr_CONST_FAST_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_CONST_FAST_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_CONST_FAST_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_CONST_FAST_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_CONST_FAST_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_CONST_FAST_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_CONST_FAST_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_CONST_FAST_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR
# undef OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR
#endif

#ifdef OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR
# undef OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR
# undef OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR_INIT
# undef OS_LINK_CONST_ISR_VHSM_HAL_INTERNALREQUESTISR_INIT
#endif



#ifdef OS_LINK_CONST
# undef OS_LINK_CONST
#endif

#ifdef OS_LINK_CONST_APP
# undef OS_LINK_CONST_APP
#endif

#ifdef OS_LINK_CONST_TASK
# undef OS_LINK_CONST_TASK
#endif

#ifdef OS_LINK_CONST_ISR
# undef OS_LINK_CONST_ISR
#endif

#ifdef OS_LINK_CONST_KERNEL
# undef OS_LINK_CONST_KERNEL
#endif

#ifdef OS_LINK_CONST_KERNEL_FAR
# undef OS_LINK_CONST_KERNEL_FAR
#endif

#ifdef OS_LINK_CONST_KERNEL_NEAR
# undef OS_LINK_CONST_KERNEL_NEAR
#endif

#ifdef OS_LINK_INTVEC_CONST
# undef OS_LINK_INTVEC_CONST
#endif

#ifdef OS_LINK_EXCVEC_CONST
# undef OS_LINK_EXCVEC_CONST
#endif


/**********************************************************************************************************************
 *  VAR SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_INIT )
if (exists(".data.OS_CORE0_VAR"))
{
  group OS_CORE0_VAR_GROUP(ordered, contiguous, fill)
  {
    section "OS_CORE0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CORE0_VAR";
    }
  }
  "_OS_CORE0_VAR_START" = "_lc_gb_OS_CORE0_VAR_GROUP";
  "_OS_CORE0_VAR_END" = "_lc_ge_OS_CORE0_VAR_GROUP" - 1;
  "_OS_CORE0_VAR_LIMIT" = "_lc_ge_OS_CORE0_VAR_GROUP";
}
else
{
  "_OS_CORE0_VAR_START" = 0;
  "_OS_CORE0_VAR_END" = 0;
  "_OS_CORE0_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT )
if (exists(".bss.OS_CORE0_VAR_NOINIT"))
{
  group OS_CORE0_VAR_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CORE0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CORE0_VAR_NOINIT";
    }
  }
  "_OS_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_NOINIT_GROUP";
  "_OS_CORE0_VAR_NOINIT_END" = "_lc_ge_OS_CORE0_VAR_NOINIT_GROUP" - 1;
  "_OS_CORE0_VAR_NOINIT_LIMIT" = "_lc_ge_OS_CORE0_VAR_NOINIT_GROUP";
}
else
{
  "_OS_CORE0_VAR_NOINIT_START" = 0;
  "_OS_CORE0_VAR_NOINIT_END" = 0;
  "_OS_CORE0_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT )
if (exists(".zdata.OS_CORE0_VAR_FAST"))
{
  group OS_CORE0_VAR_FAST_GROUP(ordered, contiguous, fill)
  {
    section "OS_CORE0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CORE0_VAR_FAST";
    }
  }
  "_OS_CORE0_VAR_FAST_START" = "_lc_gb_OS_CORE0_VAR_FAST_GROUP";
  "_OS_CORE0_VAR_FAST_END" = "_lc_ge_OS_CORE0_VAR_FAST_GROUP" - 1;
  "_OS_CORE0_VAR_FAST_LIMIT" = "_lc_ge_OS_CORE0_VAR_FAST_GROUP";
}
else
{
  "_OS_CORE0_VAR_FAST_START" = 0;
  "_OS_CORE0_VAR_FAST_END" = 0;
  "_OS_CORE0_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_CORE0_VAR_FAST_NOINIT"))
{
  group OS_CORE0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CORE0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CORE0_VAR_FAST_NOINIT";
    }
  }
  "_OS_CORE0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_FAST_NOINIT_GROUP";
  "_OS_CORE0_VAR_FAST_NOINIT_END" = "_lc_ge_OS_CORE0_VAR_FAST_NOINIT_GROUP" - 1;
  "_OS_CORE0_VAR_FAST_NOINIT_LIMIT" = "_lc_ge_OS_CORE0_VAR_FAST_NOINIT_GROUP";
}
else
{
  "_OS_CORE0_VAR_FAST_NOINIT_START" = 0;
  "_OS_CORE0_VAR_FAST_NOINIT_END" = 0;
  "_OS_CORE0_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT )
if (exists(".data.OS_CORE0_VAR_NOCACHE"))
{
  group OS_CORE0_VAR_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_CORE0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CORE0_VAR_NOCACHE";
    }
  }
  "_OS_CORE0_VAR_NOCACHE_START" = "_lc_gb_OS_CORE0_VAR_NOCACHE_GROUP";
  "_OS_CORE0_VAR_NOCACHE_END" = "_lc_ge_OS_CORE0_VAR_NOCACHE_GROUP" - 1;
  "_OS_CORE0_VAR_NOCACHE_LIMIT" = "_lc_ge_OS_CORE0_VAR_NOCACHE_GROUP";
}
else
{
  "_OS_CORE0_VAR_NOCACHE_START" = 0;
  "_OS_CORE0_VAR_NOCACHE_END" = 0;
  "_OS_CORE0_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_CORE0_VAR_NOCACHE_NOINIT"))
{
  group OS_CORE0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CORE0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CORE0_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_CORE0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CORE0_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_CORE0_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_CORE0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_CORE0_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_CORE0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CORE0_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_CORE0_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_CORE0_VAR_FAST_NOCACHE"))
{
  group OS_CORE0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_CORE0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CORE0_VAR_FAST_NOCACHE";
    }
  }
  "_OS_CORE0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CORE0_VAR_FAST_NOCACHE_GROUP";
  "_OS_CORE0_VAR_FAST_NOCACHE_END" = "_lc_ge_OS_CORE0_VAR_FAST_NOCACHE_GROUP" - 1;
  "_OS_CORE0_VAR_FAST_NOCACHE_LIMIT" = "_lc_ge_OS_CORE0_VAR_FAST_NOCACHE_GROUP";
}
else
{
  "_OS_CORE0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_CORE0_VAR_FAST_NOCACHE_END" = 0;
  "_OS_CORE0_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_CORE0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CORE0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CORE0_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_FAR )
if (exists(".bss.OS_PUBLIC_CORE0_VAR_NOINIT"))
{
  group OS_PUBLIC_CORE0_VAR_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_PUBLIC_CORE0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_PUBLIC_CORE0_VAR_NOINIT";
    }
  }
  "_OS_PUBLIC_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_PUBLIC_CORE0_VAR_NOINIT_GROUP";
  "_OS_PUBLIC_CORE0_VAR_NOINIT_END" = "_lc_ge_OS_PUBLIC_CORE0_VAR_NOINIT_GROUP" - 1;
  "_OS_PUBLIC_CORE0_VAR_NOINIT_LIMIT" = "_lc_ge_OS_PUBLIC_CORE0_VAR_NOINIT_GROUP";
}
else
{
  "_OS_PUBLIC_CORE0_VAR_NOINIT_START" = 0;
  "_OS_PUBLIC_CORE0_VAR_NOINIT_END" = 0;
  "_OS_PUBLIC_CORE0_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_NEAR )
if (exists(".bss.OS_PUBLIC_CORE0_VAR_FAST_NOINIT"))
{
  group OS_PUBLIC_CORE0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_PUBLIC_CORE0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_PUBLIC_CORE0_VAR_FAST_NOINIT";
    }
  }
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_GROUP";
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_END" = "_lc_ge_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_GROUP" - 1;
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_LIMIT" = "_lc_ge_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_GROUP";
}
else
{
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_START" = 0;
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_END" = 0;
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_FAR )
if (exists(".bss.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT"))
{
  group OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_NEAR )
if (exists(".bss.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_FAR )
if (exists(".bss.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT"))
{
  group OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_NEAR )
if (exists(".bss.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif


#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0
group OS_SystemApplication_OsCore0_VAR_ALL_GROUP(ordered, contiguous, fill)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_INIT )
if (exists(".data.OS_SystemApplication_OsCore0_VAR"))
{
  group OS_SystemApplication_OsCore0_VAR_GROUP(ordered, contiguous, fill)
  {
    section "OS_SystemApplication_OsCore0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_SystemApplication_OsCore0_VAR";
    }
  }
  "_OS_SystemApplication_OsCore0_VAR_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_END" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_VAR_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_SystemApplication_OsCore0_VAR_NOINIT"))
{
  group OS_SystemApplication_OsCore0_VAR_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_SystemApplication_OsCore0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_SystemApplication_OsCore0_VAR_NOINIT";
    }
  }
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_END" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_NOINIT_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_NOINIT_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_SystemApplication_OsCore0_VAR_ZERO_INIT") || exists(".data.OS_SystemApplication_OsCore0_VAR_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_SystemApplication_OsCore0_VAR_ZERO_INIT";
      select "[.]data.OS_SystemApplication_OsCore0_VAR_ZERO_INIT";
    }
  }
  "_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_END" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_SystemApplication_OsCore0_VAR_FAST"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_GROUP(ordered, contiguous, fill)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST";
    }
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_END" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_FAST_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_VAR_FAST_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_FAST_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT";
    }
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_END" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT") || exists(".zdata.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT";
      select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT";
    }
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_END" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_SystemApplication_OsCore0_VAR_NOCACHE"))
{
  group OS_SystemApplication_OsCore0_VAR_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_SystemApplication_OsCore0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_SystemApplication_OsCore0_VAR_NOCACHE";
    }
  }
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_NOCACHE_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_END" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_NOCACHE_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_NOCACHE_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT"))
{
  group OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT") || exists(".data.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT";
      select "[.]data.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE";
    }
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_END" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT") || exists(".zdata.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
      select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0
} /* OS_SystemApplication_OsCore0_VAR_ALL_GROUP */
"_OS_SystemApplication_OsCore0_VAR_ALL_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_ALL_GROUP";
"_OS_SystemApplication_OsCore0_VAR_ALL_END" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_ALL_GROUP" - 1;
"_OS_SystemApplication_OsCore0_VAR_ALL_LIMIT" = "_lc_ge_OS_SystemApplication_OsCore0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK
group OS_Default_Init_Task_VAR_ALL_GROUP(ordered, contiguous, fill)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_INIT )
if (exists(".data.OS_Default_Init_Task_VAR"))
{
  group OS_Default_Init_Task_VAR_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_Init_Task_VAR";
    }
  }
  "_OS_Default_Init_Task_VAR_START" = "_lc_gb_OS_Default_Init_Task_VAR_GROUP";
  "_OS_Default_Init_Task_VAR_END" = "_lc_ge_OS_Default_Init_Task_VAR_GROUP" - 1;
  "_OS_Default_Init_Task_VAR_LIMIT" = "_lc_ge_OS_Default_Init_Task_VAR_GROUP";
}
else
{
  "_OS_Default_Init_Task_VAR_START" = 0;
  "_OS_Default_Init_Task_VAR_END" = 0;
  "_OS_Default_Init_Task_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Default_Init_Task_VAR_NOINIT"))
{
  group OS_Default_Init_Task_VAR_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_VAR_NOINIT";
    }
  }
  "_OS_Default_Init_Task_VAR_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_NOINIT_GROUP";
  "_OS_Default_Init_Task_VAR_NOINIT_END" = "_lc_ge_OS_Default_Init_Task_VAR_NOINIT_GROUP" - 1;
  "_OS_Default_Init_Task_VAR_NOINIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_VAR_NOINIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_VAR_NOINIT_START" = 0;
  "_OS_Default_Init_Task_VAR_NOINIT_END" = 0;
  "_OS_Default_Init_Task_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_VAR_ZERO_INIT") || exists(".data.OS_Default_Init_Task_VAR_ZERO_INIT"))
{
  group OS_Default_Init_Task_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_VAR_ZERO_INIT";
      select "[.]data.OS_Default_Init_Task_VAR_ZERO_INIT";
    }
  }
  "_OS_Default_Init_Task_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_VAR_ZERO_INIT_END" = "_lc_ge_OS_Default_Init_Task_VAR_ZERO_INIT_GROUP" - 1;
  "_OS_Default_Init_Task_VAR_ZERO_INIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_VAR_ZERO_INIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_VAR_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_VAR_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Default_Init_Task_VAR_FAST"))
{
  group OS_Default_Init_Task_VAR_FAST_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_Init_Task_VAR_FAST";
    }
  }
  "_OS_Default_Init_Task_VAR_FAST_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_END" = "_lc_ge_OS_Default_Init_Task_VAR_FAST_GROUP" - 1;
  "_OS_Default_Init_Task_VAR_FAST_LIMIT" = "_lc_ge_OS_Default_Init_Task_VAR_FAST_GROUP";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_END" = 0;
  "_OS_Default_Init_Task_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Default_Init_Task_VAR_FAST_NOINIT"))
{
  group OS_Default_Init_Task_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_VAR_FAST_NOINIT";
    }
  }
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_END" = "_lc_ge_OS_Default_Init_Task_VAR_FAST_NOINIT_GROUP" - 1;
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_VAR_FAST_NOINIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_END" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_VAR_FAST_ZERO_INIT") || exists(".zdata.OS_Default_Init_Task_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_Init_Task_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_VAR_FAST_ZERO_INIT";
      select "[.]zdata.OS_Default_Init_Task_VAR_FAST_ZERO_INIT";
    }
  }
  "_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_END" = "_lc_ge_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_GROUP" - 1;
  "_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_INIT )
if (exists(".data.OS_Default_Init_Task_VAR_NOCACHE"))
{
  group OS_Default_Init_Task_VAR_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_Init_Task_VAR_NOCACHE";
    }
  }
  "_OS_Default_Init_Task_VAR_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_VAR_NOCACHE_GROUP";
  "_OS_Default_Init_Task_VAR_NOCACHE_END" = "_lc_ge_OS_Default_Init_Task_VAR_NOCACHE_GROUP" - 1;
  "_OS_Default_Init_Task_VAR_NOCACHE_LIMIT" = "_lc_ge_OS_Default_Init_Task_VAR_NOCACHE_GROUP";
}
else
{
  "_OS_Default_Init_Task_VAR_NOCACHE_START" = 0;
  "_OS_Default_Init_Task_VAR_NOCACHE_END" = 0;
  "_OS_Default_Init_Task_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Default_Init_Task_VAR_NOCACHE_NOINIT"))
{
  group OS_Default_Init_Task_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT") || exists(".data.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT";
      select "[.]data.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Default_Init_Task_VAR_FAST_NOCACHE"))
{
  group OS_Default_Init_Task_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_Init_Task_VAR_FAST_NOCACHE";
    }
  }
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_END" = "_lc_ge_OS_Default_Init_Task_VAR_FAST_NOCACHE_GROUP" - 1;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_LIMIT" = "_lc_ge_OS_Default_Init_Task_VAR_FAST_NOCACHE_GROUP";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_END" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT") || exists(".zdata.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT";
      select "[.]zdata.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK
} /* OS_Default_Init_Task_VAR_ALL_GROUP */
"_OS_Default_Init_Task_VAR_ALL_START" = "_lc_gb_OS_Default_Init_Task_VAR_ALL_GROUP";
"_OS_Default_Init_Task_VAR_ALL_END" = "_lc_ge_OS_Default_Init_Task_VAR_ALL_GROUP" - 1;
"_OS_Default_Init_Task_VAR_ALL_LIMIT" = "_lc_ge_OS_Default_Init_Task_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED
group OS_Default_Init_Task_Trusted_VAR_ALL_GROUP(ordered, contiguous, fill)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE_INIT )
if (exists(".data.OS_Default_Init_Task_Trusted_VAR"))
{
  group OS_Default_Init_Task_Trusted_VAR_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_Trusted_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_Init_Task_Trusted_VAR";
    }
  }
  "_OS_Default_Init_Task_Trusted_VAR_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_END" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Default_Init_Task_Trusted_VAR_NOINIT"))
{
  group OS_Default_Init_Task_Trusted_VAR_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_Trusted_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Trusted_VAR_NOINIT";
    }
  }
  "_OS_Default_Init_Task_Trusted_VAR_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_NOINIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_NOINIT_END" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_NOINIT_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_NOINIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_NOINIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_Trusted_VAR_ZERO_INIT") || exists(".data.OS_Default_Init_Task_Trusted_VAR_ZERO_INIT"))
{
  group OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Trusted_VAR_ZERO_INIT";
      select "[.]data.OS_Default_Init_Task_Trusted_VAR_ZERO_INIT";
    }
  }
  "_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_END" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Default_Init_Task_Trusted_VAR_FAST"))
{
  group OS_Default_Init_Task_Trusted_VAR_FAST_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_Trusted_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_Init_Task_Trusted_VAR_FAST";
    }
  }
  "_OS_Default_Init_Task_Trusted_VAR_FAST_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_FAST_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_FAST_END" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_FAST_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_FAST_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_FAST_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT"))
{
  group OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT";
    }
  }
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_END" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT") || exists(".zdata.OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT";
      select "[.]zdata.OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT";
    }
  }
  "_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_END" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE_INIT )
if (exists(".data.OS_Default_Init_Task_Trusted_VAR_NOCACHE"))
{
  group OS_Default_Init_Task_Trusted_VAR_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_Trusted_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_Init_Task_Trusted_VAR_NOCACHE";
    }
  }
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_NOCACHE_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_END" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_NOCACHE_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_NOCACHE_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT"))
{
  group OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT") || exists(".data.OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT";
      select "[.]data.OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE"))
{
  group OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE";
    }
  }
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_END" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT") || exists(".zdata.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT";
      select "[.]zdata.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED
} /* OS_Default_Init_Task_Trusted_VAR_ALL_GROUP */
"_OS_Default_Init_Task_Trusted_VAR_ALL_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_ALL_GROUP";
"_OS_Default_Init_Task_Trusted_VAR_ALL_END" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_ALL_GROUP" - 1;
"_OS_Default_Init_Task_Trusted_VAR_ALL_LIMIT" = "_lc_ge_OS_Default_Init_Task_Trusted_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0
group OS_IdleTask_OsCore0_VAR_ALL_GROUP(ordered, contiguous, fill)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_INIT )
if (exists(".data.OS_IdleTask_OsCore0_VAR"))
{
  group OS_IdleTask_OsCore0_VAR_GROUP(ordered, contiguous, fill)
  {
    section "OS_IdleTask_OsCore0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_IdleTask_OsCore0_VAR";
    }
  }
  "_OS_IdleTask_OsCore0_VAR_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_GROUP";
  "_OS_IdleTask_OsCore0_VAR_END" = "_lc_ge_OS_IdleTask_OsCore0_VAR_GROUP" - 1;
  "_OS_IdleTask_OsCore0_VAR_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_VAR_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_IdleTask_OsCore0_VAR_NOINIT"))
{
  group OS_IdleTask_OsCore0_VAR_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_IdleTask_OsCore0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_IdleTask_OsCore0_VAR_NOINIT";
    }
  }
  "_OS_IdleTask_OsCore0_VAR_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_NOINIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_NOINIT_END" = "_lc_ge_OS_IdleTask_OsCore0_VAR_NOINIT_GROUP" - 1;
  "_OS_IdleTask_OsCore0_VAR_NOINIT_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_VAR_NOINIT_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOINIT_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_IdleTask_OsCore0_VAR_ZERO_INIT") || exists(".data.OS_IdleTask_OsCore0_VAR_ZERO_INIT"))
{
  group OS_IdleTask_OsCore0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_IdleTask_OsCore0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_IdleTask_OsCore0_VAR_ZERO_INIT";
      select "[.]data.OS_IdleTask_OsCore0_VAR_ZERO_INIT";
    }
  }
  "_OS_IdleTask_OsCore0_VAR_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_ZERO_INIT_END" = "_lc_ge_OS_IdleTask_OsCore0_VAR_ZERO_INIT_GROUP" - 1;
  "_OS_IdleTask_OsCore0_VAR_ZERO_INIT_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_VAR_ZERO_INIT_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_ZERO_INIT_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_IdleTask_OsCore0_VAR_FAST"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_GROUP(ordered, contiguous, fill)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_IdleTask_OsCore0_VAR_FAST";
    }
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_END" = "_lc_ge_OS_IdleTask_OsCore0_VAR_FAST_GROUP" - 1;
  "_OS_IdleTask_OsCore0_VAR_FAST_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_VAR_FAST_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_IdleTask_OsCore0_VAR_FAST_NOINIT"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_IdleTask_OsCore0_VAR_FAST_NOINIT";
    }
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END" = "_lc_ge_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_GROUP" - 1;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT") || exists(".zdata.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT";
      select "[.]zdata.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT";
    }
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_END" = "_lc_ge_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_GROUP" - 1;
  "_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_IdleTask_OsCore0_VAR_NOCACHE"))
{
  group OS_IdleTask_OsCore0_VAR_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_IdleTask_OsCore0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_IdleTask_OsCore0_VAR_NOCACHE";
    }
  }
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_NOCACHE_GROUP";
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_END" = "_lc_ge_OS_IdleTask_OsCore0_VAR_NOCACHE_GROUP" - 1;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_VAR_NOCACHE_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT"))
{
  group OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT") || exists(".data.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT";
      select "[.]data.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE";
    }
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_END" = "_lc_ge_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_GROUP" - 1;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT") || exists(".zdata.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
      select "[.]zdata.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0
} /* OS_IdleTask_OsCore0_VAR_ALL_GROUP */
"_OS_IdleTask_OsCore0_VAR_ALL_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_ALL_GROUP";
"_OS_IdleTask_OsCore0_VAR_ALL_END" = "_lc_ge_OS_IdleTask_OsCore0_VAR_ALL_GROUP" - 1;
"_OS_IdleTask_OsCore0_VAR_ALL_LIMIT" = "_lc_ge_OS_IdleTask_OsCore0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK
group OS_OsTask_VAR_ALL_GROUP(ordered, contiguous, fill)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR_CACHE_INIT )
if (exists(".data.OS_OsTask_VAR"))
{
  group OS_OsTask_VAR_GROUP(ordered, contiguous, fill)
  {
    section "OS_OsTask_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_OsTask_VAR";
    }
  }
  "_OS_OsTask_VAR_START" = "_lc_gb_OS_OsTask_VAR_GROUP";
  "_OS_OsTask_VAR_END" = "_lc_ge_OS_OsTask_VAR_GROUP" - 1;
  "_OS_OsTask_VAR_LIMIT" = "_lc_ge_OS_OsTask_VAR_GROUP";
}
else
{
  "_OS_OsTask_VAR_START" = 0;
  "_OS_OsTask_VAR_END" = 0;
  "_OS_OsTask_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR_CACHE_NOINIT )
if (exists(".bss.OS_OsTask_VAR_NOINIT"))
{
  group OS_OsTask_VAR_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_OsTask_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsTask_VAR_NOINIT";
    }
  }
  "_OS_OsTask_VAR_NOINIT_START" = "_lc_gb_OS_OsTask_VAR_NOINIT_GROUP";
  "_OS_OsTask_VAR_NOINIT_END" = "_lc_ge_OS_OsTask_VAR_NOINIT_GROUP" - 1;
  "_OS_OsTask_VAR_NOINIT_LIMIT" = "_lc_ge_OS_OsTask_VAR_NOINIT_GROUP";
}
else
{
  "_OS_OsTask_VAR_NOINIT_START" = 0;
  "_OS_OsTask_VAR_NOINIT_END" = 0;
  "_OS_OsTask_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_OsTask_VAR_ZERO_INIT") || exists(".data.OS_OsTask_VAR_ZERO_INIT"))
{
  group OS_OsTask_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_OsTask_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsTask_VAR_ZERO_INIT";
      select "[.]data.OS_OsTask_VAR_ZERO_INIT";
    }
  }
  "_OS_OsTask_VAR_ZERO_INIT_START" = "_lc_gb_OS_OsTask_VAR_ZERO_INIT_GROUP";
  "_OS_OsTask_VAR_ZERO_INIT_END" = "_lc_ge_OS_OsTask_VAR_ZERO_INIT_GROUP" - 1;
  "_OS_OsTask_VAR_ZERO_INIT_LIMIT" = "_lc_ge_OS_OsTask_VAR_ZERO_INIT_GROUP";
}
else
{
  "_OS_OsTask_VAR_ZERO_INIT_START" = 0;
  "_OS_OsTask_VAR_ZERO_INIT_END" = 0;
  "_OS_OsTask_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE_INIT )
if (exists(".zdata.OS_OsTask_VAR_FAST"))
{
  group OS_OsTask_VAR_FAST_GROUP(ordered, contiguous, fill)
  {
    section "OS_OsTask_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_OsTask_VAR_FAST";
    }
  }
  "_OS_OsTask_VAR_FAST_START" = "_lc_gb_OS_OsTask_VAR_FAST_GROUP";
  "_OS_OsTask_VAR_FAST_END" = "_lc_ge_OS_OsTask_VAR_FAST_GROUP" - 1;
  "_OS_OsTask_VAR_FAST_LIMIT" = "_lc_ge_OS_OsTask_VAR_FAST_GROUP";
}
else
{
  "_OS_OsTask_VAR_FAST_START" = 0;
  "_OS_OsTask_VAR_FAST_END" = 0;
  "_OS_OsTask_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_OsTask_VAR_FAST_NOINIT"))
{
  group OS_OsTask_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_OsTask_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsTask_VAR_FAST_NOINIT";
    }
  }
  "_OS_OsTask_VAR_FAST_NOINIT_START" = "_lc_gb_OS_OsTask_VAR_FAST_NOINIT_GROUP";
  "_OS_OsTask_VAR_FAST_NOINIT_END" = "_lc_ge_OS_OsTask_VAR_FAST_NOINIT_GROUP" - 1;
  "_OS_OsTask_VAR_FAST_NOINIT_LIMIT" = "_lc_ge_OS_OsTask_VAR_FAST_NOINIT_GROUP";
}
else
{
  "_OS_OsTask_VAR_FAST_NOINIT_START" = 0;
  "_OS_OsTask_VAR_FAST_NOINIT_END" = 0;
  "_OS_OsTask_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_OsTask_VAR_FAST_ZERO_INIT") || exists(".zdata.OS_OsTask_VAR_FAST_ZERO_INIT"))
{
  group OS_OsTask_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_OsTask_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsTask_VAR_FAST_ZERO_INIT";
      select "[.]zdata.OS_OsTask_VAR_FAST_ZERO_INIT";
    }
  }
  "_OS_OsTask_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_OsTask_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_OsTask_VAR_FAST_ZERO_INIT_END" = "_lc_ge_OS_OsTask_VAR_FAST_ZERO_INIT_GROUP" - 1;
  "_OS_OsTask_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ge_OS_OsTask_VAR_FAST_ZERO_INIT_GROUP";
}
else
{
  "_OS_OsTask_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_OsTask_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_OsTask_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE_INIT )
if (exists(".data.OS_OsTask_VAR_NOCACHE"))
{
  group OS_OsTask_VAR_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_OsTask_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_OsTask_VAR_NOCACHE";
    }
  }
  "_OS_OsTask_VAR_NOCACHE_START" = "_lc_gb_OS_OsTask_VAR_NOCACHE_GROUP";
  "_OS_OsTask_VAR_NOCACHE_END" = "_lc_ge_OS_OsTask_VAR_NOCACHE_GROUP" - 1;
  "_OS_OsTask_VAR_NOCACHE_LIMIT" = "_lc_ge_OS_OsTask_VAR_NOCACHE_GROUP";
}
else
{
  "_OS_OsTask_VAR_NOCACHE_START" = 0;
  "_OS_OsTask_VAR_NOCACHE_END" = 0;
  "_OS_OsTask_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_OsTask_VAR_NOCACHE_NOINIT"))
{
  group OS_OsTask_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_OsTask_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsTask_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_OsTask_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_OsTask_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_OsTask_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_OsTask_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_OsTask_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_OsTask_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_OsTask_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_OsTask_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_OsTask_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_OsTask_VAR_NOCACHE_ZERO_INIT") || exists(".data.OS_OsTask_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_OsTask_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_OsTask_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsTask_VAR_NOCACHE_ZERO_INIT";
      select "[.]data.OS_OsTask_VAR_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_OsTask_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_OsTask_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_OsTask_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_OsTask_VAR_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_OsTask_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_OsTask_VAR_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_OsTask_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_OsTask_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_OsTask_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_OsTask_VAR_FAST_NOCACHE"))
{
  group OS_OsTask_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_OsTask_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_OsTask_VAR_FAST_NOCACHE";
    }
  }
  "_OS_OsTask_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_OsTask_VAR_FAST_NOCACHE_GROUP";
  "_OS_OsTask_VAR_FAST_NOCACHE_END" = "_lc_ge_OS_OsTask_VAR_FAST_NOCACHE_GROUP" - 1;
  "_OS_OsTask_VAR_FAST_NOCACHE_LIMIT" = "_lc_ge_OS_OsTask_VAR_FAST_NOCACHE_GROUP";
}
else
{
  "_OS_OsTask_VAR_FAST_NOCACHE_START" = 0;
  "_OS_OsTask_VAR_FAST_NOCACHE_END" = 0;
  "_OS_OsTask_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_OsTask_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_OsTask_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_OsTask_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsTask_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_OsTask_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_OsTask_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_OsTask_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_OsTask_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_OsTask_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_OsTask_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_OsTask_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_OsTask_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_OsTask_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT") || exists(".zdata.OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT";
      select "[.]zdata.OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_OsTask_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK
} /* OS_OsTask_VAR_ALL_GROUP */
"_OS_OsTask_VAR_ALL_START" = "_lc_gb_OS_OsTask_VAR_ALL_GROUP";
"_OS_OsTask_VAR_ALL_END" = "_lc_ge_OS_OsTask_VAR_ALL_GROUP" - 1;
"_OS_OsTask_VAR_ALL_LIMIT" = "_lc_ge_OS_OsTask_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_OSTASK
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_FAR
# undef OS_LINK_VAR_TASK_OSTASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO
group OS_Ostask_HighPrio_VAR_ALL_GROUP(ordered, contiguous, fill)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE_INIT )
if (exists(".data.OS_Ostask_HighPrio_VAR"))
{
  group OS_Ostask_HighPrio_VAR_GROUP(ordered, contiguous, fill)
  {
    section "OS_Ostask_HighPrio_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Ostask_HighPrio_VAR";
    }
  }
  "_OS_Ostask_HighPrio_VAR_START" = "_lc_gb_OS_Ostask_HighPrio_VAR_GROUP";
  "_OS_Ostask_HighPrio_VAR_END" = "_lc_ge_OS_Ostask_HighPrio_VAR_GROUP" - 1;
  "_OS_Ostask_HighPrio_VAR_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_VAR_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_VAR_START" = 0;
  "_OS_Ostask_HighPrio_VAR_END" = 0;
  "_OS_Ostask_HighPrio_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Ostask_HighPrio_VAR_NOINIT"))
{
  group OS_Ostask_HighPrio_VAR_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Ostask_HighPrio_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Ostask_HighPrio_VAR_NOINIT";
    }
  }
  "_OS_Ostask_HighPrio_VAR_NOINIT_START" = "_lc_gb_OS_Ostask_HighPrio_VAR_NOINIT_GROUP";
  "_OS_Ostask_HighPrio_VAR_NOINIT_END" = "_lc_ge_OS_Ostask_HighPrio_VAR_NOINIT_GROUP" - 1;
  "_OS_Ostask_HighPrio_VAR_NOINIT_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_VAR_NOINIT_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_VAR_NOINIT_START" = 0;
  "_OS_Ostask_HighPrio_VAR_NOINIT_END" = 0;
  "_OS_Ostask_HighPrio_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Ostask_HighPrio_VAR_ZERO_INIT") || exists(".data.OS_Ostask_HighPrio_VAR_ZERO_INIT"))
{
  group OS_Ostask_HighPrio_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Ostask_HighPrio_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Ostask_HighPrio_VAR_ZERO_INIT";
      select "[.]data.OS_Ostask_HighPrio_VAR_ZERO_INIT";
    }
  }
  "_OS_Ostask_HighPrio_VAR_ZERO_INIT_START" = "_lc_gb_OS_Ostask_HighPrio_VAR_ZERO_INIT_GROUP";
  "_OS_Ostask_HighPrio_VAR_ZERO_INIT_END" = "_lc_ge_OS_Ostask_HighPrio_VAR_ZERO_INIT_GROUP" - 1;
  "_OS_Ostask_HighPrio_VAR_ZERO_INIT_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_VAR_ZERO_INIT_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_VAR_ZERO_INIT_START" = 0;
  "_OS_Ostask_HighPrio_VAR_ZERO_INIT_END" = 0;
  "_OS_Ostask_HighPrio_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Ostask_HighPrio_VAR_FAST"))
{
  group OS_Ostask_HighPrio_VAR_FAST_GROUP(ordered, contiguous, fill)
  {
    section "OS_Ostask_HighPrio_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Ostask_HighPrio_VAR_FAST";
    }
  }
  "_OS_Ostask_HighPrio_VAR_FAST_START" = "_lc_gb_OS_Ostask_HighPrio_VAR_FAST_GROUP";
  "_OS_Ostask_HighPrio_VAR_FAST_END" = "_lc_ge_OS_Ostask_HighPrio_VAR_FAST_GROUP" - 1;
  "_OS_Ostask_HighPrio_VAR_FAST_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_VAR_FAST_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_VAR_FAST_START" = 0;
  "_OS_Ostask_HighPrio_VAR_FAST_END" = 0;
  "_OS_Ostask_HighPrio_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Ostask_HighPrio_VAR_FAST_NOINIT"))
{
  group OS_Ostask_HighPrio_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Ostask_HighPrio_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Ostask_HighPrio_VAR_FAST_NOINIT";
    }
  }
  "_OS_Ostask_HighPrio_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Ostask_HighPrio_VAR_FAST_NOINIT_GROUP";
  "_OS_Ostask_HighPrio_VAR_FAST_NOINIT_END" = "_lc_ge_OS_Ostask_HighPrio_VAR_FAST_NOINIT_GROUP" - 1;
  "_OS_Ostask_HighPrio_VAR_FAST_NOINIT_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_VAR_FAST_NOINIT_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_VAR_FAST_NOINIT_START" = 0;
  "_OS_Ostask_HighPrio_VAR_FAST_NOINIT_END" = 0;
  "_OS_Ostask_HighPrio_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT") || exists(".zdata.OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT"))
{
  group OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT";
      select "[.]zdata.OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT";
    }
  }
  "_OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT_END" = "_lc_ge_OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT_GROUP" - 1;
  "_OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_Ostask_HighPrio_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE_INIT )
if (exists(".data.OS_Ostask_HighPrio_VAR_NOCACHE"))
{
  group OS_Ostask_HighPrio_VAR_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_Ostask_HighPrio_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Ostask_HighPrio_VAR_NOCACHE";
    }
  }
  "_OS_Ostask_HighPrio_VAR_NOCACHE_START" = "_lc_gb_OS_Ostask_HighPrio_VAR_NOCACHE_GROUP";
  "_OS_Ostask_HighPrio_VAR_NOCACHE_END" = "_lc_ge_OS_Ostask_HighPrio_VAR_NOCACHE_GROUP" - 1;
  "_OS_Ostask_HighPrio_VAR_NOCACHE_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_VAR_NOCACHE_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_VAR_NOCACHE_START" = 0;
  "_OS_Ostask_HighPrio_VAR_NOCACHE_END" = 0;
  "_OS_Ostask_HighPrio_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Ostask_HighPrio_VAR_NOCACHE_NOINIT"))
{
  group OS_Ostask_HighPrio_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Ostask_HighPrio_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Ostask_HighPrio_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_Ostask_HighPrio_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Ostask_HighPrio_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Ostask_HighPrio_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_Ostask_HighPrio_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_Ostask_HighPrio_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Ostask_HighPrio_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_Ostask_HighPrio_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT") || exists(".data.OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT";
      select "[.]data.OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_Ostask_HighPrio_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Ostask_HighPrio_VAR_FAST_NOCACHE"))
{
  group OS_Ostask_HighPrio_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_Ostask_HighPrio_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Ostask_HighPrio_VAR_FAST_NOCACHE";
    }
  }
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_GROUP";
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_END" = "_lc_ge_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_GROUP" - 1;
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_END" = 0;
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Ostask_HighPrio_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Ostask_HighPrio_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Ostask_HighPrio_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Ostask_HighPrio_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT") || exists(".zdata.OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT";
      select "[.]zdata.OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_Ostask_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO
} /* OS_Ostask_HighPrio_VAR_ALL_GROUP */
"_OS_Ostask_HighPrio_VAR_ALL_START" = "_lc_gb_OS_Ostask_HighPrio_VAR_ALL_GROUP";
"_OS_Ostask_HighPrio_VAR_ALL_END" = "_lc_ge_OS_Ostask_HighPrio_VAR_ALL_GROUP" - 1;
"_OS_Ostask_HighPrio_VAR_ALL_LIMIT" = "_lc_ge_OS_Ostask_HighPrio_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_HIGHPRIO_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK
group OS_vHsmMainFunctionTask_VAR_ALL_GROUP(ordered, contiguous, fill)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE_INIT )
if (exists(".data.OS_vHsmMainFunctionTask_VAR"))
{
  group OS_vHsmMainFunctionTask_VAR_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsmMainFunctionTask_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_vHsmMainFunctionTask_VAR";
    }
  }
  "_OS_vHsmMainFunctionTask_VAR_START" = "_lc_gb_OS_vHsmMainFunctionTask_VAR_GROUP";
  "_OS_vHsmMainFunctionTask_VAR_END" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_VAR_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_VAR_START" = 0;
  "_OS_vHsmMainFunctionTask_VAR_END" = 0;
  "_OS_vHsmMainFunctionTask_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE_NOINIT )
if (exists(".bss.OS_vHsmMainFunctionTask_VAR_NOINIT"))
{
  group OS_vHsmMainFunctionTask_VAR_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsmMainFunctionTask_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsmMainFunctionTask_VAR_NOINIT";
    }
  }
  "_OS_vHsmMainFunctionTask_VAR_NOINIT_START" = "_lc_gb_OS_vHsmMainFunctionTask_VAR_NOINIT_GROUP";
  "_OS_vHsmMainFunctionTask_VAR_NOINIT_END" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_NOINIT_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_VAR_NOINIT_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_NOINIT_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_VAR_NOINIT_START" = 0;
  "_OS_vHsmMainFunctionTask_VAR_NOINIT_END" = 0;
  "_OS_vHsmMainFunctionTask_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_vHsmMainFunctionTask_VAR_ZERO_INIT") || exists(".data.OS_vHsmMainFunctionTask_VAR_ZERO_INIT"))
{
  group OS_vHsmMainFunctionTask_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsmMainFunctionTask_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsmMainFunctionTask_VAR_ZERO_INIT";
      select "[.]data.OS_vHsmMainFunctionTask_VAR_ZERO_INIT";
    }
  }
  "_OS_vHsmMainFunctionTask_VAR_ZERO_INIT_START" = "_lc_gb_OS_vHsmMainFunctionTask_VAR_ZERO_INIT_GROUP";
  "_OS_vHsmMainFunctionTask_VAR_ZERO_INIT_END" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_ZERO_INIT_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_VAR_ZERO_INIT_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_ZERO_INIT_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_VAR_ZERO_INIT_START" = 0;
  "_OS_vHsmMainFunctionTask_VAR_ZERO_INIT_END" = 0;
  "_OS_vHsmMainFunctionTask_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE_INIT )
if (exists(".zdata.OS_vHsmMainFunctionTask_VAR_FAST"))
{
  group OS_vHsmMainFunctionTask_VAR_FAST_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsmMainFunctionTask_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_vHsmMainFunctionTask_VAR_FAST";
    }
  }
  "_OS_vHsmMainFunctionTask_VAR_FAST_START" = "_lc_gb_OS_vHsmMainFunctionTask_VAR_FAST_GROUP";
  "_OS_vHsmMainFunctionTask_VAR_FAST_END" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_FAST_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_VAR_FAST_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_FAST_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_VAR_FAST_START" = 0;
  "_OS_vHsmMainFunctionTask_VAR_FAST_END" = 0;
  "_OS_vHsmMainFunctionTask_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_vHsmMainFunctionTask_VAR_FAST_NOINIT"))
{
  group OS_vHsmMainFunctionTask_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsmMainFunctionTask_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsmMainFunctionTask_VAR_FAST_NOINIT";
    }
  }
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOINIT_START" = "_lc_gb_OS_vHsmMainFunctionTask_VAR_FAST_NOINIT_GROUP";
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOINIT_END" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_FAST_NOINIT_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOINIT_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_FAST_NOINIT_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOINIT_START" = 0;
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOINIT_END" = 0;
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT") || exists(".zdata.OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT"))
{
  group OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT";
      select "[.]zdata.OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT";
    }
  }
  "_OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT_END" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_vHsmMainFunctionTask_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE_INIT )
if (exists(".data.OS_vHsmMainFunctionTask_VAR_NOCACHE"))
{
  group OS_vHsmMainFunctionTask_VAR_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsmMainFunctionTask_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_vHsmMainFunctionTask_VAR_NOCACHE";
    }
  }
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_START" = "_lc_gb_OS_vHsmMainFunctionTask_VAR_NOCACHE_GROUP";
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_END" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_NOCACHE_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_NOCACHE_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_START" = 0;
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_END" = 0;
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_vHsmMainFunctionTask_VAR_NOCACHE_NOINIT"))
{
  group OS_vHsmMainFunctionTask_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsmMainFunctionTask_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsmMainFunctionTask_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_vHsmMainFunctionTask_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT") || exists(".data.OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT";
      select "[.]data.OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_vHsmMainFunctionTask_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE"))
{
  group OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE";
    }
  }
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_GROUP";
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_END" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_START" = 0;
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_END" = 0;
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT") || exists(".zdata.OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT";
      select "[.]zdata.OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_vHsmMainFunctionTask_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK
} /* OS_vHsmMainFunctionTask_VAR_ALL_GROUP */
"_OS_vHsmMainFunctionTask_VAR_ALL_START" = "_lc_gb_OS_vHsmMainFunctionTask_VAR_ALL_GROUP";
"_OS_vHsmMainFunctionTask_VAR_ALL_END" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_ALL_GROUP" - 1;
"_OS_vHsmMainFunctionTask_VAR_ALL_LIMIT" = "_lc_ge_OS_vHsmMainFunctionTask_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_VHSMMAINFUNCTIONTASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER
group OS_CounterIsr_SystemTimer_VAR_ALL_GROUP(ordered, contiguous, fill)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_INIT )
if (exists(".data.OS_CounterIsr_SystemTimer_VAR"))
{
  group OS_CounterIsr_SystemTimer_VAR_GROUP(ordered, contiguous, fill)
  {
    section "OS_CounterIsr_SystemTimer_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CounterIsr_SystemTimer_VAR";
    }
  }
  "_OS_CounterIsr_SystemTimer_VAR_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_END" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_NOINIT )
if (exists(".bss.OS_CounterIsr_SystemTimer_VAR_NOINIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CounterIsr_SystemTimer_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CounterIsr_SystemTimer_VAR_NOINIT";
    }
  }
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_END" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_NOINIT_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_NOINIT_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT") || exists(".data.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT";
      select "[.]data.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT";
    }
  }
  "_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_END" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_INIT )
if (exists(".zdata.OS_CounterIsr_SystemTimer_VAR_FAST"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_GROUP(ordered, contiguous, fill)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CounterIsr_SystemTimer_VAR_FAST";
    }
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_END" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_FAST_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_FAST_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT";
    }
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT") || exists(".zdata.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT";
      select "[.]zdata.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT";
    }
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_END" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_INIT )
if (exists(".data.OS_CounterIsr_SystemTimer_VAR_NOCACHE"))
{
  group OS_CounterIsr_SystemTimer_VAR_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_CounterIsr_SystemTimer_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CounterIsr_SystemTimer_VAR_NOCACHE";
    }
  }
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_NOCACHE_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_END" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_NOCACHE_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_NOCACHE_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT") || exists(".data.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT";
      select "[.]data.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE";
    }
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_END" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT") || exists(".zdata.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT";
      select "[.]zdata.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER
} /* OS_CounterIsr_SystemTimer_VAR_ALL_GROUP */
"_OS_CounterIsr_SystemTimer_VAR_ALL_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_ALL_GROUP";
"_OS_CounterIsr_SystemTimer_VAR_ALL_END" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_ALL_GROUP" - 1;
"_OS_CounterIsr_SystemTimer_VAR_ALL_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR
group OS_vHsm_Hal_InternalRequestIsr_VAR_ALL_GROUP(ordered, contiguous, fill)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE_INIT )
if (exists(".data.OS_vHsm_Hal_InternalRequestIsr_VAR"))
{
  group OS_vHsm_Hal_InternalRequestIsr_VAR_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_InternalRequestIsr_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_vHsm_Hal_InternalRequestIsr_VAR";
    }
  }
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_VAR_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_vHsm_Hal_InternalRequestIsr_VAR_NOINIT"))
{
  group OS_vHsm_Hal_InternalRequestIsr_VAR_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_InternalRequestIsr_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsm_Hal_InternalRequestIsr_VAR_NOINIT";
    }
  }
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOINIT_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_VAR_NOINIT_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOINIT_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_NOINIT_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOINIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_NOINIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOINIT_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOINIT_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT") || exists(".data.OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT"))
{
  group OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT";
      select "[.]data.OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT";
    }
  }
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST"))
{
  group OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST";
    }
  }
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOINIT"))
{
  group OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOINIT";
    }
  }
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOINIT_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOINIT_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOINIT_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOINIT_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOINIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOINIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOINIT_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOINIT_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT") || exists(".zdata.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT"))
{
  group OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT";
      select "[.]zdata.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT";
    }
  }
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE"))
{
  group OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE";
    }
  }
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_NOINIT"))
{
  group OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT") || exists(".data.OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT";
      select "[.]data.OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE"))
{
  group OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE";
    }
  }
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT") || exists(".zdata.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT";
      select "[.]zdata.OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_vHsm_Hal_InternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR
} /* OS_vHsm_Hal_InternalRequestIsr_VAR_ALL_GROUP */
"_OS_vHsm_Hal_InternalRequestIsr_VAR_ALL_START" = "_lc_gb_OS_vHsm_Hal_InternalRequestIsr_VAR_ALL_GROUP";
"_OS_vHsm_Hal_InternalRequestIsr_VAR_ALL_END" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_ALL_GROUP" - 1;
"_OS_vHsm_Hal_InternalRequestIsr_VAR_ALL_LIMIT" = "_lc_ge_OS_vHsm_Hal_InternalRequestIsr_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_INTERNALREQUESTISR_NEAR_NOCACHE_ZERO_INIT
#endif


#ifdef OS_LINK_VAR
# undef OS_LINK_VAR
#endif

#ifdef OS_LINK_VAR_APP
# undef OS_LINK_VAR_APP
#endif

#ifdef OS_LINK_VAR_TASK
# undef OS_LINK_VAR_TASK
#endif

#ifdef OS_LINK_VAR_ISR
# undef OS_LINK_VAR_ISR
#endif

#ifdef OS_LINK_KERNEL_TRACE
# undef OS_LINK_KERNEL_TRACE
#endif

#ifdef OS_LINK_KERNEL_TRACE_FAR
# undef OS_LINK_KERNEL_TRACE_FAR
#endif

#ifdef OS_LINK_KERNEL_TRACE_NEAR
# undef OS_LINK_KERNEL_TRACE_NEAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS
# undef OS_LINK_KERNEL_BARRIERS
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_FAR
# undef OS_LINK_KERNEL_BARRIERS_FAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_NEAR
# undef OS_LINK_KERNEL_BARRIERS_NEAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS
# undef OS_LINK_KERNEL_CORESTATUS
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_FAR
# undef OS_LINK_KERNEL_CORESTATUS_FAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_NEAR
# undef OS_LINK_KERNEL_CORESTATUS_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL
# undef OS_LINK_VAR_KERNEL
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR
# undef OS_LINK_VAR_KERNEL_FAR
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE
# undef OS_LINK_VAR_KERNEL_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR
# undef OS_LINK_VAR_KERNEL_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif


