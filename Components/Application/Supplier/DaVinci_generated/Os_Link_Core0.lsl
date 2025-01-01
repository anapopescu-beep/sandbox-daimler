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
 *              File: Os_Link_Core0.lsl
 *   Generation Time: 2022-10-10 07:56:34
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
 *  CODE SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_INTVEC_CODE )
if (exists(".text.OS_INTVEC_CORE0_CODE"))
{
  group OS_INTVEC_CORE0_CODE_GROUP(align=8192)
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
  group OS_EXCVEC_CORE0_CODE_GROUP(align=256)
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
if (exists(".text.OS_ApplBackgroundTask_Core0_CODE"))
{
  group OS_ApplBackgroundTask_Core0_CODE_GROUP(align=8)
  {
    select "[.]text.OS_ApplBackgroundTask_Core0_CODE";
  }
  "_OS_ApplBackgroundTask_Core0_CODE_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_CODE_GROUP";
  "_OS_ApplBackgroundTask_Core0_CODE_END" = "_lc_ge_OS_ApplBackgroundTask_Core0_CODE_GROUP" - 1;
  "_OS_ApplBackgroundTask_Core0_CODE_LIMIT" = "_lc_ge_OS_ApplBackgroundTask_Core0_CODE_GROUP";
}
else
{
  "_OS_ApplBackgroundTask_Core0_CODE_START" = 0;
  "_OS_ApplBackgroundTask_Core0_CODE_END" = 0;
  "_OS_ApplBackgroundTask_Core0_CODE_LIMIT" = 0;
}
if (exists(".text.OS_ApplInitTask_Core0_CODE"))
{
  group OS_ApplInitTask_Core0_CODE_GROUP(align=8)
  {
    select "[.]text.OS_ApplInitTask_Core0_CODE";
  }
  "_OS_ApplInitTask_Core0_CODE_START" = "_lc_gb_OS_ApplInitTask_Core0_CODE_GROUP";
  "_OS_ApplInitTask_Core0_CODE_END" = "_lc_ge_OS_ApplInitTask_Core0_CODE_GROUP" - 1;
  "_OS_ApplInitTask_Core0_CODE_LIMIT" = "_lc_ge_OS_ApplInitTask_Core0_CODE_GROUP";
}
else
{
  "_OS_ApplInitTask_Core0_CODE_START" = 0;
  "_OS_ApplInitTask_Core0_CODE_END" = 0;
  "_OS_ApplInitTask_Core0_CODE_LIMIT" = 0;
}
if (exists(".text.OS_ApplTask_Core0_HighPrio_CODE"))
{
  group OS_ApplTask_Core0_HighPrio_CODE_GROUP(align=8)
  {
    select "[.]text.OS_ApplTask_Core0_HighPrio_CODE";
  }
  "_OS_ApplTask_Core0_HighPrio_CODE_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_CODE_GROUP";
  "_OS_ApplTask_Core0_HighPrio_CODE_END" = "_lc_ge_OS_ApplTask_Core0_HighPrio_CODE_GROUP" - 1;
  "_OS_ApplTask_Core0_HighPrio_CODE_LIMIT" = "_lc_ge_OS_ApplTask_Core0_HighPrio_CODE_GROUP";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_CODE_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_CODE_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_CODE_LIMIT" = 0;
}
if (exists(".text.OS_ApplTask_Core0_LowPrio_CODE"))
{
  group OS_ApplTask_Core0_LowPrio_CODE_GROUP(align=8)
  {
    select "[.]text.OS_ApplTask_Core0_LowPrio_CODE";
  }
  "_OS_ApplTask_Core0_LowPrio_CODE_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_CODE_GROUP";
  "_OS_ApplTask_Core0_LowPrio_CODE_END" = "_lc_ge_OS_ApplTask_Core0_LowPrio_CODE_GROUP" - 1;
  "_OS_ApplTask_Core0_LowPrio_CODE_LIMIT" = "_lc_ge_OS_ApplTask_Core0_LowPrio_CODE_GROUP";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_CODE_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_CODE_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_CODE_LIMIT" = 0;
}
if (exists(".text.OS_BackgroundTask_Core0_CODE"))
{
  group OS_BackgroundTask_Core0_CODE_GROUP(align=8)
  {
    select "[.]text.OS_BackgroundTask_Core0_CODE";
  }
  "_OS_BackgroundTask_Core0_CODE_START" = "_lc_gb_OS_BackgroundTask_Core0_CODE_GROUP";
  "_OS_BackgroundTask_Core0_CODE_END" = "_lc_ge_OS_BackgroundTask_Core0_CODE_GROUP" - 1;
  "_OS_BackgroundTask_Core0_CODE_LIMIT" = "_lc_ge_OS_BackgroundTask_Core0_CODE_GROUP";
}
else
{
  "_OS_BackgroundTask_Core0_CODE_START" = 0;
  "_OS_BackgroundTask_Core0_CODE_END" = 0;
  "_OS_BackgroundTask_Core0_CODE_LIMIT" = 0;
}
if (exists(".text.OS_BswTask_Core0_HighPrio_CODE"))
{
  group OS_BswTask_Core0_HighPrio_CODE_GROUP(align=8)
  {
    select "[.]text.OS_BswTask_Core0_HighPrio_CODE";
  }
  "_OS_BswTask_Core0_HighPrio_CODE_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_CODE_GROUP";
  "_OS_BswTask_Core0_HighPrio_CODE_END" = "_lc_ge_OS_BswTask_Core0_HighPrio_CODE_GROUP" - 1;
  "_OS_BswTask_Core0_HighPrio_CODE_LIMIT" = "_lc_ge_OS_BswTask_Core0_HighPrio_CODE_GROUP";
}
else
{
  "_OS_BswTask_Core0_HighPrio_CODE_START" = 0;
  "_OS_BswTask_Core0_HighPrio_CODE_END" = 0;
  "_OS_BswTask_Core0_HighPrio_CODE_LIMIT" = 0;
}
if (exists(".text.OS_BswTask_Core0_LowPrio_CODE"))
{
  group OS_BswTask_Core0_LowPrio_CODE_GROUP(align=8)
  {
    select "[.]text.OS_BswTask_Core0_LowPrio_CODE";
  }
  "_OS_BswTask_Core0_LowPrio_CODE_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_CODE_GROUP";
  "_OS_BswTask_Core0_LowPrio_CODE_END" = "_lc_ge_OS_BswTask_Core0_LowPrio_CODE_GROUP" - 1;
  "_OS_BswTask_Core0_LowPrio_CODE_LIMIT" = "_lc_ge_OS_BswTask_Core0_LowPrio_CODE_GROUP";
}
else
{
  "_OS_BswTask_Core0_LowPrio_CODE_START" = 0;
  "_OS_BswTask_Core0_LowPrio_CODE_END" = 0;
  "_OS_BswTask_Core0_LowPrio_CODE_LIMIT" = 0;
}
if (exists(".text.OS_CanIsr_1_CODE"))
{
  group OS_CanIsr_1_CODE_GROUP(align=8)
  {
    select "[.]text.OS_CanIsr_1_CODE";
  }
  "_OS_CanIsr_1_CODE_START" = "_lc_gb_OS_CanIsr_1_CODE_GROUP";
  "_OS_CanIsr_1_CODE_END" = "_lc_ge_OS_CanIsr_1_CODE_GROUP" - 1;
  "_OS_CanIsr_1_CODE_LIMIT" = "_lc_ge_OS_CanIsr_1_CODE_GROUP";
}
else
{
  "_OS_CanIsr_1_CODE_START" = 0;
  "_OS_CanIsr_1_CODE_END" = 0;
  "_OS_CanIsr_1_CODE_LIMIT" = 0;
}
if (exists(".text.OS_Default_Init_Task_CODE"))
{
  group OS_Default_Init_Task_CODE_GROUP(align=8)
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
  group OS_Default_Init_Task_Trusted_CODE_GROUP(align=8)
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
if (exists(".text.OS_OsTask_ALV_BeltFunctionAlgo_CODE"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_CODE_GROUP(align=8)
  {
    select "[.]text.OS_OsTask_ALV_BeltFunctionAlgo_CODE";
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_CODE_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_CODE_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_CODE_END" = "_lc_ge_OS_OsTask_ALV_BeltFunctionAlgo_CODE_GROUP" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_CODE_LIMIT" = "_lc_ge_OS_OsTask_ALV_BeltFunctionAlgo_CODE_GROUP";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_CODE_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_CODE_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_CODE_LIMIT" = 0;
}
if (exists(".text.OS_vHsmResponseIsr_CODE"))
{
  group OS_vHsmResponseIsr_CODE_GROUP(align=8)
  {
    select "[.]text.OS_vHsmResponseIsr_CODE";
  }
  "_OS_vHsmResponseIsr_CODE_START" = "_lc_gb_OS_vHsmResponseIsr_CODE_GROUP";
  "_OS_vHsmResponseIsr_CODE_END" = "_lc_ge_OS_vHsmResponseIsr_CODE_GROUP" - 1;
  "_OS_vHsmResponseIsr_CODE_LIMIT" = "_lc_ge_OS_vHsmResponseIsr_CODE_GROUP";
}
else
{
  "_OS_vHsmResponseIsr_CODE_START" = 0;
  "_OS_vHsmResponseIsr_CODE_END" = 0;
  "_OS_vHsmResponseIsr_CODE_LIMIT" = 0;
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
  group OS_CORE0_CONST_GROUP(ordered, contiguous, fill, align=8)
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
  group OS_CORE0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
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
  group OS_INTVEC_CORE0_CONST_GROUP(align=8192)
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
  group OS_EXCVEC_CORE0_CONST_GROUP(align=256)
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


#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0_FAR )
if (exists(".rodata.OS_OsApplication_Trusted_Core0_CONST"))
{
  group OS_OsApplication_Trusted_Core0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_OsApplication_Trusted_Core0_CONST";
  }
  "_OS_OsApplication_Trusted_Core0_CONST_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_CONST_GROUP";
  "_OS_OsApplication_Trusted_Core0_CONST_END" = "_lc_ge_OS_OsApplication_Trusted_Core0_CONST_GROUP" - 1;
  "_OS_OsApplication_Trusted_Core0_CONST_LIMIT" = "_lc_ge_OS_OsApplication_Trusted_Core0_CONST_GROUP";
}
else
{
  "_OS_OsApplication_Trusted_Core0_CONST_START" = 0;
  "_OS_OsApplication_Trusted_Core0_CONST_END" = 0;
  "_OS_OsApplication_Trusted_Core0_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR )
if (exists(".zrodata.OS_OsApplication_Trusted_Core0_CONST_FAST"))
{
  group OS_OsApplication_Trusted_Core0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_OsApplication_Trusted_Core0_CONST_FAST";
  }
  "_OS_OsApplication_Trusted_Core0_CONST_FAST_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_CONST_FAST_GROUP";
  "_OS_OsApplication_Trusted_Core0_CONST_FAST_END" = "_lc_ge_OS_OsApplication_Trusted_Core0_CONST_FAST_GROUP" - 1;
  "_OS_OsApplication_Trusted_Core0_CONST_FAST_LIMIT" = "_lc_ge_OS_OsApplication_Trusted_Core0_CONST_FAST_GROUP";
}
else
{
  "_OS_OsApplication_Trusted_Core0_CONST_FAST_START" = 0;
  "_OS_OsApplication_Trusted_Core0_CONST_FAST_END" = 0;
  "_OS_OsApplication_Trusted_Core0_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0_INIT )
















#endif

#ifdef OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0
# undef OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0
#endif

#ifdef OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0_FAR
# undef OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0_FAR
#endif

#ifdef OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR
# undef OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR
#endif

#ifdef OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0_INIT
# undef OS_LINK_CONST_APP_OSAPPLICATION_TRUSTED_CORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_FAR )
if (exists(".rodata.OS_SystemApplication_OsCore0_CONST"))
{
  group OS_SystemApplication_OsCore0_CONST_GROUP(ordered, contiguous, fill, align=8)
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
  group OS_SystemApplication_OsCore0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
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



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0_FAR )
if (exists(".rodata.OS_ApplBackgroundTask_Core0_CONST"))
{
  group OS_ApplBackgroundTask_Core0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_ApplBackgroundTask_Core0_CONST";
  }
  "_OS_ApplBackgroundTask_Core0_CONST_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_CONST_GROUP";
  "_OS_ApplBackgroundTask_Core0_CONST_END" = "_lc_ge_OS_ApplBackgroundTask_Core0_CONST_GROUP" - 1;
  "_OS_ApplBackgroundTask_Core0_CONST_LIMIT" = "_lc_ge_OS_ApplBackgroundTask_Core0_CONST_GROUP";
}
else
{
  "_OS_ApplBackgroundTask_Core0_CONST_START" = 0;
  "_OS_ApplBackgroundTask_Core0_CONST_END" = 0;
  "_OS_ApplBackgroundTask_Core0_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0_NEAR )
if (exists(".zrodata.OS_ApplBackgroundTask_Core0_CONST_FAST"))
{
  group OS_ApplBackgroundTask_Core0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_ApplBackgroundTask_Core0_CONST_FAST";
  }
  "_OS_ApplBackgroundTask_Core0_CONST_FAST_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_CONST_FAST_GROUP";
  "_OS_ApplBackgroundTask_Core0_CONST_FAST_END" = "_lc_ge_OS_ApplBackgroundTask_Core0_CONST_FAST_GROUP" - 1;
  "_OS_ApplBackgroundTask_Core0_CONST_FAST_LIMIT" = "_lc_ge_OS_ApplBackgroundTask_Core0_CONST_FAST_GROUP";
}
else
{
  "_OS_ApplBackgroundTask_Core0_CONST_FAST_START" = 0;
  "_OS_ApplBackgroundTask_Core0_CONST_FAST_END" = 0;
  "_OS_ApplBackgroundTask_Core0_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0
# undef OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0
#endif

#ifdef OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0_FAR
# undef OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0_FAR
#endif

#ifdef OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0_NEAR
# undef OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0_INIT
# undef OS_LINK_CONST_TASK_APPLBACKGROUNDTASK_CORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_CONST_TASK_APPLINITTASK_CORE0_FAR )
if (exists(".rodata.OS_ApplInitTask_Core0_CONST"))
{
  group OS_ApplInitTask_Core0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_ApplInitTask_Core0_CONST";
  }
  "_OS_ApplInitTask_Core0_CONST_START" = "_lc_gb_OS_ApplInitTask_Core0_CONST_GROUP";
  "_OS_ApplInitTask_Core0_CONST_END" = "_lc_ge_OS_ApplInitTask_Core0_CONST_GROUP" - 1;
  "_OS_ApplInitTask_Core0_CONST_LIMIT" = "_lc_ge_OS_ApplInitTask_Core0_CONST_GROUP";
}
else
{
  "_OS_ApplInitTask_Core0_CONST_START" = 0;
  "_OS_ApplInitTask_Core0_CONST_END" = 0;
  "_OS_ApplInitTask_Core0_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_CONST_TASK_APPLINITTASK_CORE0_NEAR )
if (exists(".zrodata.OS_ApplInitTask_Core0_CONST_FAST"))
{
  group OS_ApplInitTask_Core0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_ApplInitTask_Core0_CONST_FAST";
  }
  "_OS_ApplInitTask_Core0_CONST_FAST_START" = "_lc_gb_OS_ApplInitTask_Core0_CONST_FAST_GROUP";
  "_OS_ApplInitTask_Core0_CONST_FAST_END" = "_lc_ge_OS_ApplInitTask_Core0_CONST_FAST_GROUP" - 1;
  "_OS_ApplInitTask_Core0_CONST_FAST_LIMIT" = "_lc_ge_OS_ApplInitTask_Core0_CONST_FAST_GROUP";
}
else
{
  "_OS_ApplInitTask_Core0_CONST_FAST_START" = 0;
  "_OS_ApplInitTask_Core0_CONST_FAST_END" = 0;
  "_OS_ApplInitTask_Core0_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_CONST_TASK_APPLINITTASK_CORE0_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_APPLINITTASK_CORE0
# undef OS_LINK_CONST_TASK_APPLINITTASK_CORE0
#endif

#ifdef OS_LINK_CONST_TASK_APPLINITTASK_CORE0_FAR
# undef OS_LINK_CONST_TASK_APPLINITTASK_CORE0_FAR
#endif

#ifdef OS_LINK_CONST_TASK_APPLINITTASK_CORE0_NEAR
# undef OS_LINK_CONST_TASK_APPLINITTASK_CORE0_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_APPLINITTASK_CORE0_INIT
# undef OS_LINK_CONST_TASK_APPLINITTASK_CORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO_FAR )
if (exists(".rodata.OS_ApplTask_Core0_HighPrio_CONST"))
{
  group OS_ApplTask_Core0_HighPrio_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_ApplTask_Core0_HighPrio_CONST";
  }
  "_OS_ApplTask_Core0_HighPrio_CONST_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_CONST_GROUP";
  "_OS_ApplTask_Core0_HighPrio_CONST_END" = "_lc_ge_OS_ApplTask_Core0_HighPrio_CONST_GROUP" - 1;
  "_OS_ApplTask_Core0_HighPrio_CONST_LIMIT" = "_lc_ge_OS_ApplTask_Core0_HighPrio_CONST_GROUP";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_CONST_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_CONST_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR )
if (exists(".zrodata.OS_ApplTask_Core0_HighPrio_CONST_FAST"))
{
  group OS_ApplTask_Core0_HighPrio_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_ApplTask_Core0_HighPrio_CONST_FAST";
  }
  "_OS_ApplTask_Core0_HighPrio_CONST_FAST_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_CONST_FAST_GROUP";
  "_OS_ApplTask_Core0_HighPrio_CONST_FAST_END" = "_lc_ge_OS_ApplTask_Core0_HighPrio_CONST_FAST_GROUP" - 1;
  "_OS_ApplTask_Core0_HighPrio_CONST_FAST_LIMIT" = "_lc_ge_OS_ApplTask_Core0_HighPrio_CONST_FAST_GROUP";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_CONST_FAST_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_CONST_FAST_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO
# undef OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO
#endif

#ifdef OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO_FAR
# undef OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO_FAR
#endif

#ifdef OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR
# undef OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO_INIT
# undef OS_LINK_CONST_TASK_APPLTASK_CORE0_HIGHPRIO_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO_FAR )
if (exists(".rodata.OS_ApplTask_Core0_LowPrio_CONST"))
{
  group OS_ApplTask_Core0_LowPrio_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_ApplTask_Core0_LowPrio_CONST";
  }
  "_OS_ApplTask_Core0_LowPrio_CONST_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_CONST_GROUP";
  "_OS_ApplTask_Core0_LowPrio_CONST_END" = "_lc_ge_OS_ApplTask_Core0_LowPrio_CONST_GROUP" - 1;
  "_OS_ApplTask_Core0_LowPrio_CONST_LIMIT" = "_lc_ge_OS_ApplTask_Core0_LowPrio_CONST_GROUP";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_CONST_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_CONST_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO_NEAR )
if (exists(".zrodata.OS_ApplTask_Core0_LowPrio_CONST_FAST"))
{
  group OS_ApplTask_Core0_LowPrio_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_ApplTask_Core0_LowPrio_CONST_FAST";
  }
  "_OS_ApplTask_Core0_LowPrio_CONST_FAST_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_CONST_FAST_GROUP";
  "_OS_ApplTask_Core0_LowPrio_CONST_FAST_END" = "_lc_ge_OS_ApplTask_Core0_LowPrio_CONST_FAST_GROUP" - 1;
  "_OS_ApplTask_Core0_LowPrio_CONST_FAST_LIMIT" = "_lc_ge_OS_ApplTask_Core0_LowPrio_CONST_FAST_GROUP";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_CONST_FAST_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_CONST_FAST_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO
# undef OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO
#endif

#ifdef OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO_FAR
# undef OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO_FAR
#endif

#ifdef OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO_NEAR
# undef OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO_INIT
# undef OS_LINK_CONST_TASK_APPLTASK_CORE0_LOWPRIO_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0_FAR )
if (exists(".rodata.OS_BackgroundTask_Core0_CONST"))
{
  group OS_BackgroundTask_Core0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_BackgroundTask_Core0_CONST";
  }
  "_OS_BackgroundTask_Core0_CONST_START" = "_lc_gb_OS_BackgroundTask_Core0_CONST_GROUP";
  "_OS_BackgroundTask_Core0_CONST_END" = "_lc_ge_OS_BackgroundTask_Core0_CONST_GROUP" - 1;
  "_OS_BackgroundTask_Core0_CONST_LIMIT" = "_lc_ge_OS_BackgroundTask_Core0_CONST_GROUP";
}
else
{
  "_OS_BackgroundTask_Core0_CONST_START" = 0;
  "_OS_BackgroundTask_Core0_CONST_END" = 0;
  "_OS_BackgroundTask_Core0_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0_NEAR )
if (exists(".zrodata.OS_BackgroundTask_Core0_CONST_FAST"))
{
  group OS_BackgroundTask_Core0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_BackgroundTask_Core0_CONST_FAST";
  }
  "_OS_BackgroundTask_Core0_CONST_FAST_START" = "_lc_gb_OS_BackgroundTask_Core0_CONST_FAST_GROUP";
  "_OS_BackgroundTask_Core0_CONST_FAST_END" = "_lc_ge_OS_BackgroundTask_Core0_CONST_FAST_GROUP" - 1;
  "_OS_BackgroundTask_Core0_CONST_FAST_LIMIT" = "_lc_ge_OS_BackgroundTask_Core0_CONST_FAST_GROUP";
}
else
{
  "_OS_BackgroundTask_Core0_CONST_FAST_START" = 0;
  "_OS_BackgroundTask_Core0_CONST_FAST_END" = 0;
  "_OS_BackgroundTask_Core0_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0
# undef OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0
#endif

#ifdef OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0_FAR
# undef OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0_FAR
#endif

#ifdef OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0_NEAR
# undef OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0_INIT
# undef OS_LINK_CONST_TASK_BACKGROUNDTASK_CORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO_FAR )
if (exists(".rodata.OS_BswTask_Core0_HighPrio_CONST"))
{
  group OS_BswTask_Core0_HighPrio_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_BswTask_Core0_HighPrio_CONST";
  }
  "_OS_BswTask_Core0_HighPrio_CONST_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_CONST_GROUP";
  "_OS_BswTask_Core0_HighPrio_CONST_END" = "_lc_ge_OS_BswTask_Core0_HighPrio_CONST_GROUP" - 1;
  "_OS_BswTask_Core0_HighPrio_CONST_LIMIT" = "_lc_ge_OS_BswTask_Core0_HighPrio_CONST_GROUP";
}
else
{
  "_OS_BswTask_Core0_HighPrio_CONST_START" = 0;
  "_OS_BswTask_Core0_HighPrio_CONST_END" = 0;
  "_OS_BswTask_Core0_HighPrio_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR )
if (exists(".zrodata.OS_BswTask_Core0_HighPrio_CONST_FAST"))
{
  group OS_BswTask_Core0_HighPrio_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_BswTask_Core0_HighPrio_CONST_FAST";
  }
  "_OS_BswTask_Core0_HighPrio_CONST_FAST_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_CONST_FAST_GROUP";
  "_OS_BswTask_Core0_HighPrio_CONST_FAST_END" = "_lc_ge_OS_BswTask_Core0_HighPrio_CONST_FAST_GROUP" - 1;
  "_OS_BswTask_Core0_HighPrio_CONST_FAST_LIMIT" = "_lc_ge_OS_BswTask_Core0_HighPrio_CONST_FAST_GROUP";
}
else
{
  "_OS_BswTask_Core0_HighPrio_CONST_FAST_START" = 0;
  "_OS_BswTask_Core0_HighPrio_CONST_FAST_END" = 0;
  "_OS_BswTask_Core0_HighPrio_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO
# undef OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO
#endif

#ifdef OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO_FAR
# undef OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO_FAR
#endif

#ifdef OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR
# undef OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO_INIT
# undef OS_LINK_CONST_TASK_BSWTASK_CORE0_HIGHPRIO_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO_FAR )
if (exists(".rodata.OS_BswTask_Core0_LowPrio_CONST"))
{
  group OS_BswTask_Core0_LowPrio_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_BswTask_Core0_LowPrio_CONST";
  }
  "_OS_BswTask_Core0_LowPrio_CONST_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_CONST_GROUP";
  "_OS_BswTask_Core0_LowPrio_CONST_END" = "_lc_ge_OS_BswTask_Core0_LowPrio_CONST_GROUP" - 1;
  "_OS_BswTask_Core0_LowPrio_CONST_LIMIT" = "_lc_ge_OS_BswTask_Core0_LowPrio_CONST_GROUP";
}
else
{
  "_OS_BswTask_Core0_LowPrio_CONST_START" = 0;
  "_OS_BswTask_Core0_LowPrio_CONST_END" = 0;
  "_OS_BswTask_Core0_LowPrio_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO_NEAR )
if (exists(".zrodata.OS_BswTask_Core0_LowPrio_CONST_FAST"))
{
  group OS_BswTask_Core0_LowPrio_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_BswTask_Core0_LowPrio_CONST_FAST";
  }
  "_OS_BswTask_Core0_LowPrio_CONST_FAST_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_CONST_FAST_GROUP";
  "_OS_BswTask_Core0_LowPrio_CONST_FAST_END" = "_lc_ge_OS_BswTask_Core0_LowPrio_CONST_FAST_GROUP" - 1;
  "_OS_BswTask_Core0_LowPrio_CONST_FAST_LIMIT" = "_lc_ge_OS_BswTask_Core0_LowPrio_CONST_FAST_GROUP";
}
else
{
  "_OS_BswTask_Core0_LowPrio_CONST_FAST_START" = 0;
  "_OS_BswTask_Core0_LowPrio_CONST_FAST_END" = 0;
  "_OS_BswTask_Core0_LowPrio_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO
# undef OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO
#endif

#ifdef OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO_FAR
# undef OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO_FAR
#endif

#ifdef OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO_NEAR
# undef OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO_INIT
# undef OS_LINK_CONST_TASK_BSWTASK_CORE0_LOWPRIO_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_FAR )
if (exists(".rodata.OS_Default_Init_Task_CONST"))
{
  group OS_Default_Init_Task_CONST_GROUP(ordered, contiguous, fill, align=8)
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
  group OS_Default_Init_Task_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
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
  group OS_Default_Init_Task_Trusted_CONST_GROUP(ordered, contiguous, fill, align=8)
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
  group OS_Default_Init_Task_Trusted_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
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
  group OS_IdleTask_OsCore0_CONST_GROUP(ordered, contiguous, fill, align=8)
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
  group OS_IdleTask_OsCore0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
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



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR )
if (exists(".rodata.OS_OsTask_ALV_BeltFunctionAlgo_CONST"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_OsTask_ALV_BeltFunctionAlgo_CONST";
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_CONST_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_CONST_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_CONST_END" = "_lc_ge_OS_OsTask_ALV_BeltFunctionAlgo_CONST_GROUP" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_CONST_LIMIT" = "_lc_ge_OS_OsTask_ALV_BeltFunctionAlgo_CONST_GROUP";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_CONST_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_CONST_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR )
if (exists(".zrodata.OS_OsTask_ALV_BeltFunctionAlgo_CONST_FAST"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_OsTask_ALV_BeltFunctionAlgo_CONST_FAST";
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_CONST_FAST_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_CONST_FAST_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_CONST_FAST_END" = "_lc_ge_OS_OsTask_ALV_BeltFunctionAlgo_CONST_FAST_GROUP" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_CONST_FAST_LIMIT" = "_lc_ge_OS_OsTask_ALV_BeltFunctionAlgo_CONST_FAST_GROUP";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_CONST_FAST_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_CONST_FAST_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO
# undef OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR
# undef OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO_INIT
# undef OS_LINK_CONST_TASK_OSTASK_ALV_BELTFUNCTIONALGO_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISR_1 ) || defined ( OS_LINK_CONST_ISR_CANISR_1_FAR )
if (exists(".rodata.OS_CanIsr_1_CONST"))
{
  group OS_CanIsr_1_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_CanIsr_1_CONST";
  }
  "_OS_CanIsr_1_CONST_START" = "_lc_gb_OS_CanIsr_1_CONST_GROUP";
  "_OS_CanIsr_1_CONST_END" = "_lc_ge_OS_CanIsr_1_CONST_GROUP" - 1;
  "_OS_CanIsr_1_CONST_LIMIT" = "_lc_ge_OS_CanIsr_1_CONST_GROUP";
}
else
{
  "_OS_CanIsr_1_CONST_START" = 0;
  "_OS_CanIsr_1_CONST_END" = 0;
  "_OS_CanIsr_1_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISR_1 ) || defined ( OS_LINK_CONST_ISR_CANISR_1_NEAR )
if (exists(".zrodata.OS_CanIsr_1_CONST_FAST"))
{
  group OS_CanIsr_1_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_CanIsr_1_CONST_FAST";
  }
  "_OS_CanIsr_1_CONST_FAST_START" = "_lc_gb_OS_CanIsr_1_CONST_FAST_GROUP";
  "_OS_CanIsr_1_CONST_FAST_END" = "_lc_ge_OS_CanIsr_1_CONST_FAST_GROUP" - 1;
  "_OS_CanIsr_1_CONST_FAST_LIMIT" = "_lc_ge_OS_CanIsr_1_CONST_FAST_GROUP";
}
else
{
  "_OS_CanIsr_1_CONST_FAST_START" = 0;
  "_OS_CanIsr_1_CONST_FAST_END" = 0;
  "_OS_CanIsr_1_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISR_1 ) || defined ( OS_LINK_CONST_ISR_CANISR_1_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_CANISR_1
# undef OS_LINK_CONST_ISR_CANISR_1
#endif

#ifdef OS_LINK_CONST_ISR_CANISR_1_FAR
# undef OS_LINK_CONST_ISR_CANISR_1_FAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISR_1_NEAR
# undef OS_LINK_CONST_ISR_CANISR_1_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISR_1_INIT
# undef OS_LINK_CONST_ISR_CANISR_1_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_FAR )
if (exists(".rodata.OS_CounterIsr_SystemTimer_CONST"))
{
  group OS_CounterIsr_SystemTimer_CONST_GROUP(ordered, contiguous, fill, align=8)
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
  group OS_CounterIsr_SystemTimer_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
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



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_CONST_ISR_VHSMRESPONSEISR_FAR )
if (exists(".rodata.OS_vHsmResponseIsr_CONST"))
{
  group OS_vHsmResponseIsr_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_vHsmResponseIsr_CONST";
  }
  "_OS_vHsmResponseIsr_CONST_START" = "_lc_gb_OS_vHsmResponseIsr_CONST_GROUP";
  "_OS_vHsmResponseIsr_CONST_END" = "_lc_ge_OS_vHsmResponseIsr_CONST_GROUP" - 1;
  "_OS_vHsmResponseIsr_CONST_LIMIT" = "_lc_ge_OS_vHsmResponseIsr_CONST_GROUP";
}
else
{
  "_OS_vHsmResponseIsr_CONST_START" = 0;
  "_OS_vHsmResponseIsr_CONST_END" = 0;
  "_OS_vHsmResponseIsr_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_CONST_ISR_VHSMRESPONSEISR_NEAR )
if (exists(".zrodata.OS_vHsmResponseIsr_CONST_FAST"))
{
  group OS_vHsmResponseIsr_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_vHsmResponseIsr_CONST_FAST";
  }
  "_OS_vHsmResponseIsr_CONST_FAST_START" = "_lc_gb_OS_vHsmResponseIsr_CONST_FAST_GROUP";
  "_OS_vHsmResponseIsr_CONST_FAST_END" = "_lc_ge_OS_vHsmResponseIsr_CONST_FAST_GROUP" - 1;
  "_OS_vHsmResponseIsr_CONST_FAST_LIMIT" = "_lc_ge_OS_vHsmResponseIsr_CONST_FAST_GROUP";
}
else
{
  "_OS_vHsmResponseIsr_CONST_FAST_START" = 0;
  "_OS_vHsmResponseIsr_CONST_FAST_END" = 0;
  "_OS_vHsmResponseIsr_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_CONST_ISR_VHSMRESPONSEISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_VHSMRESPONSEISR
# undef OS_LINK_CONST_ISR_VHSMRESPONSEISR
#endif

#ifdef OS_LINK_CONST_ISR_VHSMRESPONSEISR_FAR
# undef OS_LINK_CONST_ISR_VHSMRESPONSEISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_VHSMRESPONSEISR_NEAR
# undef OS_LINK_CONST_ISR_VHSMRESPONSEISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_VHSMRESPONSEISR_INIT
# undef OS_LINK_CONST_ISR_VHSMRESPONSEISR_INIT
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
  group OS_CORE0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CORE0_VAR";
    }
    reserved ".pad.OS_CORE0_VAR" (size=16);
  }
  "_OS_CORE0_VAR_START" = "_lc_gb_OS_CORE0_VAR_GROUP";
  "_OS_CORE0_VAR_END" = "_lc_ub__pad_OS_CORE0_VAR" - 1;
  "_OS_CORE0_VAR_LIMIT" = "_lc_ub__pad_OS_CORE0_VAR";
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
  group OS_CORE0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CORE0_VAR_NOINIT";
    }
    reserved ".pad.OS_CORE0_VAR_NOINIT" (size=16);
  }
  "_OS_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_NOINIT_GROUP";
  "_OS_CORE0_VAR_NOINIT_END" = "_lc_ub__pad_OS_CORE0_VAR_NOINIT" - 1;
  "_OS_CORE0_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_CORE0_VAR_NOINIT";
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
  group OS_CORE0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CORE0_VAR_FAST";
    }
    reserved ".pad.OS_CORE0_VAR_FAST" (size=16);
  }
  "_OS_CORE0_VAR_FAST_START" = "_lc_gb_OS_CORE0_VAR_FAST_GROUP";
  "_OS_CORE0_VAR_FAST_END" = "_lc_ub__pad_OS_CORE0_VAR_FAST" - 1;
  "_OS_CORE0_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_CORE0_VAR_FAST";
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
  group OS_CORE0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CORE0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_CORE0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_CORE0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_FAST_NOINIT_GROUP";
  "_OS_CORE0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_CORE0_VAR_FAST_NOINIT" - 1;
  "_OS_CORE0_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_CORE0_VAR_FAST_NOINIT";
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
  group OS_CORE0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CORE0_VAR_NOCACHE";
    }
    reserved ".pad.OS_CORE0_VAR_NOCACHE" (size=16);
  }
  "_OS_CORE0_VAR_NOCACHE_START" = "_lc_gb_OS_CORE0_VAR_NOCACHE_GROUP";
  "_OS_CORE0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_CORE0_VAR_NOCACHE" - 1;
  "_OS_CORE0_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_CORE0_VAR_NOCACHE";
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
  group OS_CORE0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CORE0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORE0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORE0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CORE0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORE0_VAR_NOCACHE_NOINIT" - 1;
  "_OS_CORE0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CORE0_VAR_NOCACHE_NOINIT";
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
  group OS_CORE0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CORE0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_CORE0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_CORE0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CORE0_VAR_FAST_NOCACHE_GROUP";
  "_OS_CORE0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_CORE0_VAR_FAST_NOCACHE" - 1;
  "_OS_CORE0_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_CORE0_VAR_FAST_NOCACHE";
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
  group OS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CORE0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORE0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORE0_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CORE0_VAR_FAST_NOCACHE_NOINIT";
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
  group OS_PUBLIC_CORE0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_PUBLIC_CORE0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_PUBLIC_CORE0_VAR_NOINIT";
    }
    reserved ".pad.OS_PUBLIC_CORE0_VAR_NOINIT" (size=16);
  }
  "_OS_PUBLIC_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_PUBLIC_CORE0_VAR_NOINIT_GROUP";
  "_OS_PUBLIC_CORE0_VAR_NOINIT_END" = "_lc_ub__pad_OS_PUBLIC_CORE0_VAR_NOINIT" - 1;
  "_OS_PUBLIC_CORE0_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_PUBLIC_CORE0_VAR_NOINIT";
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
  group OS_PUBLIC_CORE0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_PUBLIC_CORE0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_PUBLIC_CORE0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_PUBLIC_CORE0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_GROUP";
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_PUBLIC_CORE0_VAR_FAST_NOINIT" - 1;
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_PUBLIC_CORE0_VAR_FAST_NOINIT";
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
  group OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT" - 1;
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT";
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
  group OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT";
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
  group OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT" - 1;
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT";
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
  group OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif


#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0
group OS_OsApplication_Trusted_Core0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE_INIT )
if (exists(".data.OS_OsApplication_Trusted_Core0_VAR"))
{
  group OS_OsApplication_Trusted_Core0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_Trusted_Core0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_OsApplication_Trusted_Core0_VAR";
    }
    reserved ".pad.OS_OsApplication_Trusted_Core0_VAR" (size=16);
  }
  "_OS_OsApplication_Trusted_Core0_VAR_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_GROUP";
  "_OS_OsApplication_Trusted_Core0_VAR_END" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR" - 1;
  "_OS_OsApplication_Trusted_Core0_VAR_LIMIT" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR";
}
else
{
  "_OS_OsApplication_Trusted_Core0_VAR_START" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_END" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_OsApplication_Trusted_Core0_VAR_NOINIT"))
{
  group OS_OsApplication_Trusted_Core0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_Trusted_Core0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsApplication_Trusted_Core0_VAR_NOINIT";
    }
    reserved ".pad.OS_OsApplication_Trusted_Core0_VAR_NOINIT" (size=16);
  }
  "_OS_OsApplication_Trusted_Core0_VAR_NOINIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_NOINIT_GROUP";
  "_OS_OsApplication_Trusted_Core0_VAR_NOINIT_END" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_NOINIT" - 1;
  "_OS_OsApplication_Trusted_Core0_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_NOINIT";
}
else
{
  "_OS_OsApplication_Trusted_Core0_VAR_NOINIT_START" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_NOINIT_END" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss") || exists(".data.OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT"))
{
  group OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss";
      select "[.]data.OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_GROUP";
  "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" - 1;
  "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT";
}
else
{
  "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_START" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_END" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_OsApplication_Trusted_Core0_VAR_FAST"))
{
  group OS_OsApplication_Trusted_Core0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_Trusted_Core0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_OsApplication_Trusted_Core0_VAR_FAST";
    }
    reserved ".pad.OS_OsApplication_Trusted_Core0_VAR_FAST" (size=16);
  }
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_GROUP";
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_END" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_FAST" - 1;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_FAST";
}
else
{
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_START" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_END" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT"))
{
  group OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_GROUP";
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" - 1;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT";
}
else
{
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_START" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_END" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT"))
{
  group OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" - 1;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_OsApplication_Trusted_Core0_VAR_NOCACHE"))
{
  group OS_OsApplication_Trusted_Core0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_Trusted_Core0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_OsApplication_Trusted_Core0_VAR_NOCACHE";
    }
    reserved ".pad.OS_OsApplication_Trusted_Core0_VAR_NOCACHE" (size=16);
  }
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_GROUP";
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_NOCACHE" - 1;
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_NOCACHE";
}
else
{
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_START" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_END" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT"))
{
  group OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT" - 1;
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE"))
{
  group OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_GROUP";
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE" - 1;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_END" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0
} /* OS_OsApplication_Trusted_Core0_VAR_ALL_GROUP */
"_OS_OsApplication_Trusted_Core0_VAR_ALL_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_ALL_GROUP";
"_OS_OsApplication_Trusted_Core0_VAR_ALL_END" = "_lc_ge_OS_OsApplication_Trusted_Core0_VAR_ALL_GROUP" - 1;
"_OS_OsApplication_Trusted_Core0_VAR_ALL_LIMIT" = "_lc_ge_OS_OsApplication_Trusted_Core0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_TRUSTED_CORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0
group OS_SystemApplication_OsCore0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_INIT )
if (exists(".data.OS_SystemApplication_OsCore0_VAR"))
{
  group OS_SystemApplication_OsCore0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_SystemApplication_OsCore0_VAR";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR" - 1;
  "_OS_SystemApplication_OsCore0_VAR_LIMIT" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR";
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
  group OS_SystemApplication_OsCore0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_SystemApplication_OsCore0_VAR_NOINIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_NOINIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_NOINIT" - 1;
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_NOINIT";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss") || exists(".data.OS_SystemApplication_OsCore0_VAR_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss";
      select "[.]data.OS_SystemApplication_OsCore0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_ZERO_INIT" - 1;
  "_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_ZERO_INIT";
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
  group OS_SystemApplication_OsCore0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_FAST" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST" - 1;
  "_OS_SystemApplication_OsCore0_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST";
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
  group OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" - 1;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" - 1;
  "_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT";
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
  group OS_SystemApplication_OsCore0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_SystemApplication_OsCore0_VAR_NOCACHE";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_NOCACHE" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_NOCACHE_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_NOCACHE" - 1;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_NOCACHE";
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
  group OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" - 1;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT";
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
  group OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE" - 1;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE";
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
  group OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
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



#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0
group OS_ApplBackgroundTask_Core0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE_INIT )
if (exists(".data.OS_ApplBackgroundTask_Core0_VAR"))
{
  group OS_ApplBackgroundTask_Core0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplBackgroundTask_Core0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_ApplBackgroundTask_Core0_VAR";
    }
    reserved ".pad.OS_ApplBackgroundTask_Core0_VAR" (size=16);
  }
  "_OS_ApplBackgroundTask_Core0_VAR_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_VAR_GROUP";
  "_OS_ApplBackgroundTask_Core0_VAR_END" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR" - 1;
  "_OS_ApplBackgroundTask_Core0_VAR_LIMIT" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR";
}
else
{
  "_OS_ApplBackgroundTask_Core0_VAR_START" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_END" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_ApplBackgroundTask_Core0_VAR_NOINIT"))
{
  group OS_ApplBackgroundTask_Core0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplBackgroundTask_Core0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplBackgroundTask_Core0_VAR_NOINIT";
    }
    reserved ".pad.OS_ApplBackgroundTask_Core0_VAR_NOINIT" (size=16);
  }
  "_OS_ApplBackgroundTask_Core0_VAR_NOINIT_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_VAR_NOINIT_GROUP";
  "_OS_ApplBackgroundTask_Core0_VAR_NOINIT_END" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_NOINIT" - 1;
  "_OS_ApplBackgroundTask_Core0_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_NOINIT";
}
else
{
  "_OS_ApplBackgroundTask_Core0_VAR_NOINIT_START" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_NOINIT_END" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT_bss") || exists(".data.OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT"))
{
  group OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT_bss";
      select "[.]data.OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT_GROUP";
  "_OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT" - 1;
  "_OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT";
}
else
{
  "_OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT_START" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT_END" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_ApplBackgroundTask_Core0_VAR_FAST"))
{
  group OS_ApplBackgroundTask_Core0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplBackgroundTask_Core0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_ApplBackgroundTask_Core0_VAR_FAST";
    }
    reserved ".pad.OS_ApplBackgroundTask_Core0_VAR_FAST" (size=16);
  }
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_VAR_FAST_GROUP";
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_END" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_FAST" - 1;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_FAST";
}
else
{
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_START" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_END" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT"))
{
  group OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT_GROUP";
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT" - 1;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT";
}
else
{
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT_START" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT_END" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT"))
{
  group OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT" - 1;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_ApplBackgroundTask_Core0_VAR_NOCACHE"))
{
  group OS_ApplBackgroundTask_Core0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplBackgroundTask_Core0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_ApplBackgroundTask_Core0_VAR_NOCACHE";
    }
    reserved ".pad.OS_ApplBackgroundTask_Core0_VAR_NOCACHE" (size=16);
  }
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_GROUP";
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_NOCACHE" - 1;
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_NOCACHE";
}
else
{
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_START" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_END" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT"))
{
  group OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT" - 1;
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE"))
{
  group OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_GROUP";
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE" - 1;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_END" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_ApplBackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0
} /* OS_ApplBackgroundTask_Core0_VAR_ALL_GROUP */
"_OS_ApplBackgroundTask_Core0_VAR_ALL_START" = "_lc_gb_OS_ApplBackgroundTask_Core0_VAR_ALL_GROUP";
"_OS_ApplBackgroundTask_Core0_VAR_ALL_END" = "_lc_ge_OS_ApplBackgroundTask_Core0_VAR_ALL_GROUP" - 1;
"_OS_ApplBackgroundTask_Core0_VAR_ALL_LIMIT" = "_lc_ge_OS_ApplBackgroundTask_Core0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLBACKGROUNDTASK_CORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0
group OS_ApplInitTask_Core0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE_INIT )
if (exists(".data.OS_ApplInitTask_Core0_VAR"))
{
  group OS_ApplInitTask_Core0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplInitTask_Core0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_ApplInitTask_Core0_VAR";
    }
    reserved ".pad.OS_ApplInitTask_Core0_VAR" (size=16);
  }
  "_OS_ApplInitTask_Core0_VAR_START" = "_lc_gb_OS_ApplInitTask_Core0_VAR_GROUP";
  "_OS_ApplInitTask_Core0_VAR_END" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR" - 1;
  "_OS_ApplInitTask_Core0_VAR_LIMIT" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR";
}
else
{
  "_OS_ApplInitTask_Core0_VAR_START" = 0;
  "_OS_ApplInitTask_Core0_VAR_END" = 0;
  "_OS_ApplInitTask_Core0_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_ApplInitTask_Core0_VAR_NOINIT"))
{
  group OS_ApplInitTask_Core0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplInitTask_Core0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplInitTask_Core0_VAR_NOINIT";
    }
    reserved ".pad.OS_ApplInitTask_Core0_VAR_NOINIT" (size=16);
  }
  "_OS_ApplInitTask_Core0_VAR_NOINIT_START" = "_lc_gb_OS_ApplInitTask_Core0_VAR_NOINIT_GROUP";
  "_OS_ApplInitTask_Core0_VAR_NOINIT_END" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_NOINIT" - 1;
  "_OS_ApplInitTask_Core0_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_NOINIT";
}
else
{
  "_OS_ApplInitTask_Core0_VAR_NOINIT_START" = 0;
  "_OS_ApplInitTask_Core0_VAR_NOINIT_END" = 0;
  "_OS_ApplInitTask_Core0_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_ApplInitTask_Core0_VAR_ZERO_INIT_bss") || exists(".data.OS_ApplInitTask_Core0_VAR_ZERO_INIT"))
{
  group OS_ApplInitTask_Core0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplInitTask_Core0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplInitTask_Core0_VAR_ZERO_INIT_bss";
      select "[.]data.OS_ApplInitTask_Core0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_ApplInitTask_Core0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_ApplInitTask_Core0_VAR_ZERO_INIT_START" = "_lc_gb_OS_ApplInitTask_Core0_VAR_ZERO_INIT_GROUP";
  "_OS_ApplInitTask_Core0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_ZERO_INIT" - 1;
  "_OS_ApplInitTask_Core0_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_ZERO_INIT";
}
else
{
  "_OS_ApplInitTask_Core0_VAR_ZERO_INIT_START" = 0;
  "_OS_ApplInitTask_Core0_VAR_ZERO_INIT_END" = 0;
  "_OS_ApplInitTask_Core0_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_ApplInitTask_Core0_VAR_FAST"))
{
  group OS_ApplInitTask_Core0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplInitTask_Core0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_ApplInitTask_Core0_VAR_FAST";
    }
    reserved ".pad.OS_ApplInitTask_Core0_VAR_FAST" (size=16);
  }
  "_OS_ApplInitTask_Core0_VAR_FAST_START" = "_lc_gb_OS_ApplInitTask_Core0_VAR_FAST_GROUP";
  "_OS_ApplInitTask_Core0_VAR_FAST_END" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_FAST" - 1;
  "_OS_ApplInitTask_Core0_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_FAST";
}
else
{
  "_OS_ApplInitTask_Core0_VAR_FAST_START" = 0;
  "_OS_ApplInitTask_Core0_VAR_FAST_END" = 0;
  "_OS_ApplInitTask_Core0_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_ApplInitTask_Core0_VAR_FAST_NOINIT"))
{
  group OS_ApplInitTask_Core0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplInitTask_Core0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplInitTask_Core0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_ApplInitTask_Core0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_ApplInitTask_Core0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_ApplInitTask_Core0_VAR_FAST_NOINIT_GROUP";
  "_OS_ApplInitTask_Core0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_FAST_NOINIT" - 1;
  "_OS_ApplInitTask_Core0_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_FAST_NOINIT";
}
else
{
  "_OS_ApplInitTask_Core0_VAR_FAST_NOINIT_START" = 0;
  "_OS_ApplInitTask_Core0_VAR_FAST_NOINIT_END" = 0;
  "_OS_ApplInitTask_Core0_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT"))
{
  group OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT" - 1;
  "_OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_ApplInitTask_Core0_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_ApplInitTask_Core0_VAR_NOCACHE"))
{
  group OS_ApplInitTask_Core0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplInitTask_Core0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_ApplInitTask_Core0_VAR_NOCACHE";
    }
    reserved ".pad.OS_ApplInitTask_Core0_VAR_NOCACHE" (size=16);
  }
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_START" = "_lc_gb_OS_ApplInitTask_Core0_VAR_NOCACHE_GROUP";
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_NOCACHE" - 1;
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_NOCACHE";
}
else
{
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_START" = 0;
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_END" = 0;
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT"))
{
  group OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT" - 1;
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_ApplInitTask_Core0_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_ApplInitTask_Core0_VAR_FAST_NOCACHE"))
{
  group OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_ApplInitTask_Core0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_ApplInitTask_Core0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_GROUP";
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE" - 1;
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_END" = 0;
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_ApplInitTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0
} /* OS_ApplInitTask_Core0_VAR_ALL_GROUP */
"_OS_ApplInitTask_Core0_VAR_ALL_START" = "_lc_gb_OS_ApplInitTask_Core0_VAR_ALL_GROUP";
"_OS_ApplInitTask_Core0_VAR_ALL_END" = "_lc_ge_OS_ApplInitTask_Core0_VAR_ALL_GROUP" - 1;
"_OS_ApplInitTask_Core0_VAR_ALL_LIMIT" = "_lc_ge_OS_ApplInitTask_Core0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLINITTASK_CORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO
group OS_ApplTask_Core0_HighPrio_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE_INIT )
if (exists(".data.OS_ApplTask_Core0_HighPrio_VAR"))
{
  group OS_ApplTask_Core0_HighPrio_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_HighPrio_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_ApplTask_Core0_HighPrio_VAR";
    }
    reserved ".pad.OS_ApplTask_Core0_HighPrio_VAR" (size=16);
  }
  "_OS_ApplTask_Core0_HighPrio_VAR_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_VAR_GROUP";
  "_OS_ApplTask_Core0_HighPrio_VAR_END" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR" - 1;
  "_OS_ApplTask_Core0_HighPrio_VAR_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_VAR_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE_NOINIT )
if (exists(".bss.OS_ApplTask_Core0_HighPrio_VAR_NOINIT"))
{
  group OS_ApplTask_Core0_HighPrio_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_HighPrio_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplTask_Core0_HighPrio_VAR_NOINIT";
    }
    reserved ".pad.OS_ApplTask_Core0_HighPrio_VAR_NOINIT" (size=16);
  }
  "_OS_ApplTask_Core0_HighPrio_VAR_NOINIT_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_VAR_NOINIT_GROUP";
  "_OS_ApplTask_Core0_HighPrio_VAR_NOINIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_NOINIT" - 1;
  "_OS_ApplTask_Core0_HighPrio_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_NOINIT";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_VAR_NOINIT_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_NOINIT_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT_bss") || exists(".data.OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT"))
{
  group OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT_bss";
      select "[.]data.OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT" (size=16);
  }
  "_OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT_GROUP";
  "_OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT" - 1;
  "_OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE_INIT )
if (exists(".zdata.OS_ApplTask_Core0_HighPrio_VAR_FAST"))
{
  group OS_ApplTask_Core0_HighPrio_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_HighPrio_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_ApplTask_Core0_HighPrio_VAR_FAST";
    }
    reserved ".pad.OS_ApplTask_Core0_HighPrio_VAR_FAST" (size=16);
  }
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_VAR_FAST_GROUP";
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_END" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_FAST" - 1;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_FAST";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT"))
{
  group OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT_GROUP";
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT" - 1;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT"))
{
  group OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT" - 1;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE_INIT )
if (exists(".data.OS_ApplTask_Core0_HighPrio_VAR_NOCACHE"))
{
  group OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_ApplTask_Core0_HighPrio_VAR_NOCACHE";
    }
    reserved ".pad.OS_ApplTask_Core0_HighPrio_VAR_NOCACHE" (size=16);
  }
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_GROUP";
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_END" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE" - 1;
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT"))
{
  group OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT" - 1;
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE"))
{
  group OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_GROUP";
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE" - 1;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_ApplTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO
} /* OS_ApplTask_Core0_HighPrio_VAR_ALL_GROUP */
"_OS_ApplTask_Core0_HighPrio_VAR_ALL_START" = "_lc_gb_OS_ApplTask_Core0_HighPrio_VAR_ALL_GROUP";
"_OS_ApplTask_Core0_HighPrio_VAR_ALL_END" = "_lc_ge_OS_ApplTask_Core0_HighPrio_VAR_ALL_GROUP" - 1;
"_OS_ApplTask_Core0_HighPrio_VAR_ALL_LIMIT" = "_lc_ge_OS_ApplTask_Core0_HighPrio_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO
group OS_ApplTask_Core0_LowPrio_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE_INIT )
if (exists(".data.OS_ApplTask_Core0_LowPrio_VAR"))
{
  group OS_ApplTask_Core0_LowPrio_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_LowPrio_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_ApplTask_Core0_LowPrio_VAR";
    }
    reserved ".pad.OS_ApplTask_Core0_LowPrio_VAR" (size=16);
  }
  "_OS_ApplTask_Core0_LowPrio_VAR_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_VAR_GROUP";
  "_OS_ApplTask_Core0_LowPrio_VAR_END" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR" - 1;
  "_OS_ApplTask_Core0_LowPrio_VAR_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_VAR_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE_NOINIT )
if (exists(".bss.OS_ApplTask_Core0_LowPrio_VAR_NOINIT"))
{
  group OS_ApplTask_Core0_LowPrio_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_LowPrio_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplTask_Core0_LowPrio_VAR_NOINIT";
    }
    reserved ".pad.OS_ApplTask_Core0_LowPrio_VAR_NOINIT" (size=16);
  }
  "_OS_ApplTask_Core0_LowPrio_VAR_NOINIT_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_VAR_NOINIT_GROUP";
  "_OS_ApplTask_Core0_LowPrio_VAR_NOINIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_NOINIT" - 1;
  "_OS_ApplTask_Core0_LowPrio_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_NOINIT";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_VAR_NOINIT_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_NOINIT_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT_bss") || exists(".data.OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT"))
{
  group OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT_bss";
      select "[.]data.OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT" (size=16);
  }
  "_OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT_GROUP";
  "_OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT" - 1;
  "_OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE_INIT )
if (exists(".zdata.OS_ApplTask_Core0_LowPrio_VAR_FAST"))
{
  group OS_ApplTask_Core0_LowPrio_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_LowPrio_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_ApplTask_Core0_LowPrio_VAR_FAST";
    }
    reserved ".pad.OS_ApplTask_Core0_LowPrio_VAR_FAST" (size=16);
  }
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_VAR_FAST_GROUP";
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_END" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_FAST" - 1;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_FAST";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT"))
{
  group OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT_GROUP";
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT" - 1;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT"))
{
  group OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT" - 1;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE_INIT )
if (exists(".data.OS_ApplTask_Core0_LowPrio_VAR_NOCACHE"))
{
  group OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_ApplTask_Core0_LowPrio_VAR_NOCACHE";
    }
    reserved ".pad.OS_ApplTask_Core0_LowPrio_VAR_NOCACHE" (size=16);
  }
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_GROUP";
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_END" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE" - 1;
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT"))
{
  group OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT" - 1;
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE"))
{
  group OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_GROUP";
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE" - 1;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_ApplTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO
} /* OS_ApplTask_Core0_LowPrio_VAR_ALL_GROUP */
"_OS_ApplTask_Core0_LowPrio_VAR_ALL_START" = "_lc_gb_OS_ApplTask_Core0_LowPrio_VAR_ALL_GROUP";
"_OS_ApplTask_Core0_LowPrio_VAR_ALL_END" = "_lc_ge_OS_ApplTask_Core0_LowPrio_VAR_ALL_GROUP" - 1;
"_OS_ApplTask_Core0_LowPrio_VAR_ALL_LIMIT" = "_lc_ge_OS_ApplTask_Core0_LowPrio_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APPLTASK_CORE0_LOWPRIO_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0
group OS_BackgroundTask_Core0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE_INIT )
if (exists(".data.OS_BackgroundTask_Core0_VAR"))
{
  group OS_BackgroundTask_Core0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BackgroundTask_Core0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_BackgroundTask_Core0_VAR";
    }
    reserved ".pad.OS_BackgroundTask_Core0_VAR" (size=16);
  }
  "_OS_BackgroundTask_Core0_VAR_START" = "_lc_gb_OS_BackgroundTask_Core0_VAR_GROUP";
  "_OS_BackgroundTask_Core0_VAR_END" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR" - 1;
  "_OS_BackgroundTask_Core0_VAR_LIMIT" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR";
}
else
{
  "_OS_BackgroundTask_Core0_VAR_START" = 0;
  "_OS_BackgroundTask_Core0_VAR_END" = 0;
  "_OS_BackgroundTask_Core0_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_BackgroundTask_Core0_VAR_NOINIT"))
{
  group OS_BackgroundTask_Core0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BackgroundTask_Core0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BackgroundTask_Core0_VAR_NOINIT";
    }
    reserved ".pad.OS_BackgroundTask_Core0_VAR_NOINIT" (size=16);
  }
  "_OS_BackgroundTask_Core0_VAR_NOINIT_START" = "_lc_gb_OS_BackgroundTask_Core0_VAR_NOINIT_GROUP";
  "_OS_BackgroundTask_Core0_VAR_NOINIT_END" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_NOINIT" - 1;
  "_OS_BackgroundTask_Core0_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_NOINIT";
}
else
{
  "_OS_BackgroundTask_Core0_VAR_NOINIT_START" = 0;
  "_OS_BackgroundTask_Core0_VAR_NOINIT_END" = 0;
  "_OS_BackgroundTask_Core0_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_BackgroundTask_Core0_VAR_ZERO_INIT_bss") || exists(".data.OS_BackgroundTask_Core0_VAR_ZERO_INIT"))
{
  group OS_BackgroundTask_Core0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BackgroundTask_Core0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BackgroundTask_Core0_VAR_ZERO_INIT_bss";
      select "[.]data.OS_BackgroundTask_Core0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_BackgroundTask_Core0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_BackgroundTask_Core0_VAR_ZERO_INIT_START" = "_lc_gb_OS_BackgroundTask_Core0_VAR_ZERO_INIT_GROUP";
  "_OS_BackgroundTask_Core0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_ZERO_INIT" - 1;
  "_OS_BackgroundTask_Core0_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_ZERO_INIT";
}
else
{
  "_OS_BackgroundTask_Core0_VAR_ZERO_INIT_START" = 0;
  "_OS_BackgroundTask_Core0_VAR_ZERO_INIT_END" = 0;
  "_OS_BackgroundTask_Core0_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_BackgroundTask_Core0_VAR_FAST"))
{
  group OS_BackgroundTask_Core0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BackgroundTask_Core0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_BackgroundTask_Core0_VAR_FAST";
    }
    reserved ".pad.OS_BackgroundTask_Core0_VAR_FAST" (size=16);
  }
  "_OS_BackgroundTask_Core0_VAR_FAST_START" = "_lc_gb_OS_BackgroundTask_Core0_VAR_FAST_GROUP";
  "_OS_BackgroundTask_Core0_VAR_FAST_END" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_FAST" - 1;
  "_OS_BackgroundTask_Core0_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_FAST";
}
else
{
  "_OS_BackgroundTask_Core0_VAR_FAST_START" = 0;
  "_OS_BackgroundTask_Core0_VAR_FAST_END" = 0;
  "_OS_BackgroundTask_Core0_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_BackgroundTask_Core0_VAR_FAST_NOINIT"))
{
  group OS_BackgroundTask_Core0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BackgroundTask_Core0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BackgroundTask_Core0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_BackgroundTask_Core0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_BackgroundTask_Core0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_BackgroundTask_Core0_VAR_FAST_NOINIT_GROUP";
  "_OS_BackgroundTask_Core0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_FAST_NOINIT" - 1;
  "_OS_BackgroundTask_Core0_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_FAST_NOINIT";
}
else
{
  "_OS_BackgroundTask_Core0_VAR_FAST_NOINIT_START" = 0;
  "_OS_BackgroundTask_Core0_VAR_FAST_NOINIT_END" = 0;
  "_OS_BackgroundTask_Core0_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT"))
{
  group OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT" - 1;
  "_OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_BackgroundTask_Core0_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_BackgroundTask_Core0_VAR_NOCACHE"))
{
  group OS_BackgroundTask_Core0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BackgroundTask_Core0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_BackgroundTask_Core0_VAR_NOCACHE";
    }
    reserved ".pad.OS_BackgroundTask_Core0_VAR_NOCACHE" (size=16);
  }
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_START" = "_lc_gb_OS_BackgroundTask_Core0_VAR_NOCACHE_GROUP";
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_NOCACHE" - 1;
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_NOCACHE";
}
else
{
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_START" = 0;
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_END" = 0;
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT"))
{
  group OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT" - 1;
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_BackgroundTask_Core0_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_BackgroundTask_Core0_VAR_FAST_NOCACHE"))
{
  group OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_BackgroundTask_Core0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_BackgroundTask_Core0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_GROUP";
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE" - 1;
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_END" = 0;
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_BackgroundTask_Core0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0
} /* OS_BackgroundTask_Core0_VAR_ALL_GROUP */
"_OS_BackgroundTask_Core0_VAR_ALL_START" = "_lc_gb_OS_BackgroundTask_Core0_VAR_ALL_GROUP";
"_OS_BackgroundTask_Core0_VAR_ALL_END" = "_lc_ge_OS_BackgroundTask_Core0_VAR_ALL_GROUP" - 1;
"_OS_BackgroundTask_Core0_VAR_ALL_LIMIT" = "_lc_ge_OS_BackgroundTask_Core0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BACKGROUNDTASK_CORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO
group OS_BswTask_Core0_HighPrio_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE_INIT )
if (exists(".data.OS_BswTask_Core0_HighPrio_VAR"))
{
  group OS_BswTask_Core0_HighPrio_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_HighPrio_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_BswTask_Core0_HighPrio_VAR";
    }
    reserved ".pad.OS_BswTask_Core0_HighPrio_VAR" (size=16);
  }
  "_OS_BswTask_Core0_HighPrio_VAR_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_VAR_GROUP";
  "_OS_BswTask_Core0_HighPrio_VAR_END" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR" - 1;
  "_OS_BswTask_Core0_HighPrio_VAR_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR";
}
else
{
  "_OS_BswTask_Core0_HighPrio_VAR_START" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_END" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE_NOINIT )
if (exists(".bss.OS_BswTask_Core0_HighPrio_VAR_NOINIT"))
{
  group OS_BswTask_Core0_HighPrio_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_HighPrio_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BswTask_Core0_HighPrio_VAR_NOINIT";
    }
    reserved ".pad.OS_BswTask_Core0_HighPrio_VAR_NOINIT" (size=16);
  }
  "_OS_BswTask_Core0_HighPrio_VAR_NOINIT_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_VAR_NOINIT_GROUP";
  "_OS_BswTask_Core0_HighPrio_VAR_NOINIT_END" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_NOINIT" - 1;
  "_OS_BswTask_Core0_HighPrio_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_NOINIT";
}
else
{
  "_OS_BswTask_Core0_HighPrio_VAR_NOINIT_START" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_NOINIT_END" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT_bss") || exists(".data.OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT"))
{
  group OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT_bss";
      select "[.]data.OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT" (size=16);
  }
  "_OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT_GROUP";
  "_OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT" - 1;
  "_OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT";
}
else
{
  "_OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT_START" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT_END" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE_INIT )
if (exists(".zdata.OS_BswTask_Core0_HighPrio_VAR_FAST"))
{
  group OS_BswTask_Core0_HighPrio_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_HighPrio_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_BswTask_Core0_HighPrio_VAR_FAST";
    }
    reserved ".pad.OS_BswTask_Core0_HighPrio_VAR_FAST" (size=16);
  }
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_VAR_FAST_GROUP";
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_END" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_FAST" - 1;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_FAST";
}
else
{
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_START" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_END" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT"))
{
  group OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT_GROUP";
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT" - 1;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT";
}
else
{
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT_START" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT_END" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT"))
{
  group OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT" - 1;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE_INIT )
if (exists(".data.OS_BswTask_Core0_HighPrio_VAR_NOCACHE"))
{
  group OS_BswTask_Core0_HighPrio_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_HighPrio_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_BswTask_Core0_HighPrio_VAR_NOCACHE";
    }
    reserved ".pad.OS_BswTask_Core0_HighPrio_VAR_NOCACHE" (size=16);
  }
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_GROUP";
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_END" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_NOCACHE" - 1;
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_NOCACHE";
}
else
{
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_START" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_END" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT"))
{
  group OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT" - 1;
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE"))
{
  group OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_GROUP";
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE" - 1;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE";
}
else
{
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_START" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_END" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_BswTask_Core0_HighPrio_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO
} /* OS_BswTask_Core0_HighPrio_VAR_ALL_GROUP */
"_OS_BswTask_Core0_HighPrio_VAR_ALL_START" = "_lc_gb_OS_BswTask_Core0_HighPrio_VAR_ALL_GROUP";
"_OS_BswTask_Core0_HighPrio_VAR_ALL_END" = "_lc_ge_OS_BswTask_Core0_HighPrio_VAR_ALL_GROUP" - 1;
"_OS_BswTask_Core0_HighPrio_VAR_ALL_LIMIT" = "_lc_ge_OS_BswTask_Core0_HighPrio_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_HIGHPRIO_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO
group OS_BswTask_Core0_LowPrio_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE_INIT )
if (exists(".data.OS_BswTask_Core0_LowPrio_VAR"))
{
  group OS_BswTask_Core0_LowPrio_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_LowPrio_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_BswTask_Core0_LowPrio_VAR";
    }
    reserved ".pad.OS_BswTask_Core0_LowPrio_VAR" (size=16);
  }
  "_OS_BswTask_Core0_LowPrio_VAR_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_VAR_GROUP";
  "_OS_BswTask_Core0_LowPrio_VAR_END" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR" - 1;
  "_OS_BswTask_Core0_LowPrio_VAR_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR";
}
else
{
  "_OS_BswTask_Core0_LowPrio_VAR_START" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_END" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE_NOINIT )
if (exists(".bss.OS_BswTask_Core0_LowPrio_VAR_NOINIT"))
{
  group OS_BswTask_Core0_LowPrio_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_LowPrio_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BswTask_Core0_LowPrio_VAR_NOINIT";
    }
    reserved ".pad.OS_BswTask_Core0_LowPrio_VAR_NOINIT" (size=16);
  }
  "_OS_BswTask_Core0_LowPrio_VAR_NOINIT_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_VAR_NOINIT_GROUP";
  "_OS_BswTask_Core0_LowPrio_VAR_NOINIT_END" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_NOINIT" - 1;
  "_OS_BswTask_Core0_LowPrio_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_NOINIT";
}
else
{
  "_OS_BswTask_Core0_LowPrio_VAR_NOINIT_START" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_NOINIT_END" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT_bss") || exists(".data.OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT"))
{
  group OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT_bss";
      select "[.]data.OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT" (size=16);
  }
  "_OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT_GROUP";
  "_OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT" - 1;
  "_OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT";
}
else
{
  "_OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT_START" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT_END" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE_INIT )
if (exists(".zdata.OS_BswTask_Core0_LowPrio_VAR_FAST"))
{
  group OS_BswTask_Core0_LowPrio_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_LowPrio_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_BswTask_Core0_LowPrio_VAR_FAST";
    }
    reserved ".pad.OS_BswTask_Core0_LowPrio_VAR_FAST" (size=16);
  }
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_VAR_FAST_GROUP";
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_END" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_FAST" - 1;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_FAST";
}
else
{
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_START" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_END" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT"))
{
  group OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT_GROUP";
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT" - 1;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT";
}
else
{
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT_START" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT_END" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT"))
{
  group OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT" - 1;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE_INIT )
if (exists(".data.OS_BswTask_Core0_LowPrio_VAR_NOCACHE"))
{
  group OS_BswTask_Core0_LowPrio_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_LowPrio_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_BswTask_Core0_LowPrio_VAR_NOCACHE";
    }
    reserved ".pad.OS_BswTask_Core0_LowPrio_VAR_NOCACHE" (size=16);
  }
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_GROUP";
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_END" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_NOCACHE" - 1;
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_NOCACHE";
}
else
{
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_START" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_END" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT"))
{
  group OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT" - 1;
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE"))
{
  group OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_GROUP";
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE" - 1;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE";
}
else
{
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_START" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_END" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_BswTask_Core0_LowPrio_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO
} /* OS_BswTask_Core0_LowPrio_VAR_ALL_GROUP */
"_OS_BswTask_Core0_LowPrio_VAR_ALL_START" = "_lc_gb_OS_BswTask_Core0_LowPrio_VAR_ALL_GROUP";
"_OS_BswTask_Core0_LowPrio_VAR_ALL_END" = "_lc_ge_OS_BswTask_Core0_LowPrio_VAR_ALL_GROUP" - 1;
"_OS_BswTask_Core0_LowPrio_VAR_ALL_LIMIT" = "_lc_ge_OS_BswTask_Core0_LowPrio_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BSWTASK_CORE0_LOWPRIO_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK
group OS_Default_Init_Task_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_INIT )
if (exists(".data.OS_Default_Init_Task_VAR"))
{
  group OS_Default_Init_Task_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_Init_Task_VAR";
    }
    reserved ".pad.OS_Default_Init_Task_VAR" (size=16);
  }
  "_OS_Default_Init_Task_VAR_START" = "_lc_gb_OS_Default_Init_Task_VAR_GROUP";
  "_OS_Default_Init_Task_VAR_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR" - 1;
  "_OS_Default_Init_Task_VAR_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_VAR";
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
  group OS_Default_Init_Task_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_VAR_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_NOINIT_GROUP";
  "_OS_Default_Init_Task_VAR_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_NOINIT" - 1;
  "_OS_Default_Init_Task_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_VAR_NOINIT";
}
else
{
  "_OS_Default_Init_Task_VAR_NOINIT_START" = 0;
  "_OS_Default_Init_Task_VAR_NOINIT_END" = 0;
  "_OS_Default_Init_Task_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_VAR_ZERO_INIT_bss") || exists(".data.OS_Default_Init_Task_VAR_ZERO_INIT"))
{
  group OS_Default_Init_Task_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_VAR_ZERO_INIT_bss";
      select "[.]data.OS_Default_Init_Task_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_VAR_ZERO_INIT";
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
  group OS_Default_Init_Task_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_Init_Task_VAR_FAST";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_FAST" (size=16);
  }
  "_OS_Default_Init_Task_VAR_FAST_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST" - 1;
  "_OS_Default_Init_Task_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST";
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
  group OS_Default_Init_Task_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_NOINIT" - 1;
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_NOINIT";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_END" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Default_Init_Task_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_Init_Task_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_Default_Init_Task_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_ZERO_INIT";
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
  group OS_Default_Init_Task_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_Init_Task_VAR_NOCACHE";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_NOCACHE" (size=16);
  }
  "_OS_Default_Init_Task_VAR_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_VAR_NOCACHE_GROUP";
  "_OS_Default_Init_Task_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_NOCACHE" - 1;
  "_OS_Default_Init_Task_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_VAR_NOCACHE";
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
  group OS_Default_Init_Task_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_NOCACHE_NOINIT" - 1;
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT";
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
  group OS_Default_Init_Task_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_Init_Task_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_NOCACHE" - 1;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_NOCACHE";
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
  group OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT";
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
group OS_Default_Init_Task_Trusted_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE_INIT )
if (exists(".data.OS_Default_Init_Task_Trusted_VAR"))
{
  group OS_Default_Init_Task_Trusted_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Trusted_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_Init_Task_Trusted_VAR";
    }
    reserved ".pad.OS_Default_Init_Task_Trusted_VAR" (size=16);
  }
  "_OS_Default_Init_Task_Trusted_VAR_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_END" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR";
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
  group OS_Default_Init_Task_Trusted_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Trusted_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Trusted_VAR_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_Trusted_VAR_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_Trusted_VAR_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_NOINIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_NOINIT" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_NOINIT";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_bss") || exists(".data.OS_Default_Init_Task_Trusted_VAR_ZERO_INIT"))
{
  group OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_bss";
      select "[.]data.OS_Default_Init_Task_Trusted_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_Trusted_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_ZERO_INIT";
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
  group OS_Default_Init_Task_Trusted_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Trusted_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_Init_Task_Trusted_VAR_FAST";
    }
    reserved ".pad.OS_Default_Init_Task_Trusted_VAR_FAST" (size=16);
  }
  "_OS_Default_Init_Task_Trusted_VAR_FAST_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_FAST_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_FAST_END" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_FAST" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_FAST";
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
  group OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_FAST_ZERO_INIT";
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
  group OS_Default_Init_Task_Trusted_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Trusted_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_Init_Task_Trusted_VAR_NOCACHE";
    }
    reserved ".pad.OS_Default_Init_Task_Trusted_VAR_NOCACHE" (size=16);
  }
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_NOCACHE_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_NOCACHE" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_NOCACHE";
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
  group OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_NOCACHE_ZERO_INIT";
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
  group OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE";
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
  group OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_TRUSTED_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Trusted_VAR_FAST_NOCACHE_ZERO_INIT";
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
group OS_IdleTask_OsCore0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_INIT )
if (exists(".data.OS_IdleTask_OsCore0_VAR"))
{
  group OS_IdleTask_OsCore0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_IdleTask_OsCore0_VAR";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_GROUP";
  "_OS_IdleTask_OsCore0_VAR_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR" - 1;
  "_OS_IdleTask_OsCore0_VAR_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR";
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
  group OS_IdleTask_OsCore0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_IdleTask_OsCore0_VAR_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_NOINIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_NOINIT" - 1;
  "_OS_IdleTask_OsCore0_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOINIT_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_IdleTask_OsCore0_VAR_ZERO_INIT_bss") || exists(".data.OS_IdleTask_OsCore0_VAR_ZERO_INIT"))
{
  group OS_IdleTask_OsCore0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_IdleTask_OsCore0_VAR_ZERO_INIT_bss";
      select "[.]data.OS_IdleTask_OsCore0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_ZERO_INIT" - 1;
  "_OS_IdleTask_OsCore0_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_ZERO_INIT";
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
  group OS_IdleTask_OsCore0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_IdleTask_OsCore0_VAR_FAST";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_FAST" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST" - 1;
  "_OS_IdleTask_OsCore0_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST";
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
  group OS_IdleTask_OsCore0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_IdleTask_OsCore0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_NOINIT" - 1;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT" - 1;
  "_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT";
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
  group OS_IdleTask_OsCore0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_IdleTask_OsCore0_VAR_NOCACHE";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_NOCACHE" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_NOCACHE_GROUP";
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_NOCACHE" - 1;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_NOCACHE";
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
  group OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT" - 1;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT";
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
  group OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE" - 1;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE";
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
  group OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
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



#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO
group OS_OsTask_ALV_BeltFunctionAlgo_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE_INIT )
if (exists(".data.OS_OsTask_ALV_BeltFunctionAlgo_VAR"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsTask_ALV_BeltFunctionAlgo_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_OsTask_ALV_BeltFunctionAlgo_VAR";
    }
    reserved ".pad.OS_OsTask_ALV_BeltFunctionAlgo_VAR" (size=16);
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_VAR_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_END" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_LIMIT" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE_NOINIT )
if (exists(".bss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT";
    }
    reserved ".pad.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT" (size=16);
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT_END" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT_bss") || exists(".data.OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT_bss";
      select "[.]data.OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT" (size=16);
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE_INIT )
if (exists(".zdata.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST";
    }
    reserved ".pad.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST" (size=16);
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_END" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE_INIT )
if (exists(".data.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE";
    }
    reserved ".pad.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE" (size=16);
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_END" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_OsTask_ALV_BeltFunctionAlgo_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO
} /* OS_OsTask_ALV_BeltFunctionAlgo_VAR_ALL_GROUP */
"_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ALL_START" = "_lc_gb_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ALL_GROUP";
"_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ALL_END" = "_lc_ge_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ALL_GROUP" - 1;
"_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ALL_LIMIT" = "_lc_ge_OS_OsTask_ALV_BeltFunctionAlgo_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_ALV_BELTFUNCTIONALGO_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_CANISR_1
group OS_CanIsr_1_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_1 ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE_INIT )
if (exists(".data.OS_CanIsr_1_VAR"))
{
  group OS_CanIsr_1_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_1_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CanIsr_1_VAR";
    }
    reserved ".pad.OS_CanIsr_1_VAR" (size=16);
  }
  "_OS_CanIsr_1_VAR_START" = "_lc_gb_OS_CanIsr_1_VAR_GROUP";
  "_OS_CanIsr_1_VAR_END" = "_lc_ub__pad_OS_CanIsr_1_VAR" - 1;
  "_OS_CanIsr_1_VAR_LIMIT" = "_lc_ub__pad_OS_CanIsr_1_VAR";
}
else
{
  "_OS_CanIsr_1_VAR_START" = 0;
  "_OS_CanIsr_1_VAR_END" = 0;
  "_OS_CanIsr_1_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_1 ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE_NOINIT )
if (exists(".bss.OS_CanIsr_1_VAR_NOINIT"))
{
  group OS_CanIsr_1_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_1_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CanIsr_1_VAR_NOINIT";
    }
    reserved ".pad.OS_CanIsr_1_VAR_NOINIT" (size=16);
  }
  "_OS_CanIsr_1_VAR_NOINIT_START" = "_lc_gb_OS_CanIsr_1_VAR_NOINIT_GROUP";
  "_OS_CanIsr_1_VAR_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_1_VAR_NOINIT" - 1;
  "_OS_CanIsr_1_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_CanIsr_1_VAR_NOINIT";
}
else
{
  "_OS_CanIsr_1_VAR_NOINIT_START" = 0;
  "_OS_CanIsr_1_VAR_NOINIT_END" = 0;
  "_OS_CanIsr_1_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_1 ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_CanIsr_1_VAR_ZERO_INIT_bss") || exists(".data.OS_CanIsr_1_VAR_ZERO_INIT"))
{
  group OS_CanIsr_1_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_1_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CanIsr_1_VAR_ZERO_INIT_bss";
      select "[.]data.OS_CanIsr_1_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_1_VAR_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_1_VAR_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_1_VAR_ZERO_INIT_GROUP";
  "_OS_CanIsr_1_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_1_VAR_ZERO_INIT" - 1;
  "_OS_CanIsr_1_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_CanIsr_1_VAR_ZERO_INIT";
}
else
{
  "_OS_CanIsr_1_VAR_ZERO_INIT_START" = 0;
  "_OS_CanIsr_1_VAR_ZERO_INIT_END" = 0;
  "_OS_CanIsr_1_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_1 ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE_INIT )
if (exists(".zdata.OS_CanIsr_1_VAR_FAST"))
{
  group OS_CanIsr_1_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_1_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CanIsr_1_VAR_FAST";
    }
    reserved ".pad.OS_CanIsr_1_VAR_FAST" (size=16);
  }
  "_OS_CanIsr_1_VAR_FAST_START" = "_lc_gb_OS_CanIsr_1_VAR_FAST_GROUP";
  "_OS_CanIsr_1_VAR_FAST_END" = "_lc_ub__pad_OS_CanIsr_1_VAR_FAST" - 1;
  "_OS_CanIsr_1_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_CanIsr_1_VAR_FAST";
}
else
{
  "_OS_CanIsr_1_VAR_FAST_START" = 0;
  "_OS_CanIsr_1_VAR_FAST_END" = 0;
  "_OS_CanIsr_1_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_1 ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_CanIsr_1_VAR_FAST_NOINIT"))
{
  group OS_CanIsr_1_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_1_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CanIsr_1_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_CanIsr_1_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_CanIsr_1_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CanIsr_1_VAR_FAST_NOINIT_GROUP";
  "_OS_CanIsr_1_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_1_VAR_FAST_NOINIT" - 1;
  "_OS_CanIsr_1_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_CanIsr_1_VAR_FAST_NOINIT";
}
else
{
  "_OS_CanIsr_1_VAR_FAST_NOINIT_START" = 0;
  "_OS_CanIsr_1_VAR_FAST_NOINIT_END" = 0;
  "_OS_CanIsr_1_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_1 ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_CanIsr_1_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_CanIsr_1_VAR_FAST_ZERO_INIT"))
{
  group OS_CanIsr_1_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_1_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CanIsr_1_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_CanIsr_1_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_1_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_1_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_1_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_CanIsr_1_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_1_VAR_FAST_ZERO_INIT" - 1;
  "_OS_CanIsr_1_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_CanIsr_1_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_CanIsr_1_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_CanIsr_1_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_CanIsr_1_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_1 ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE_INIT )
if (exists(".data.OS_CanIsr_1_VAR_NOCACHE"))
{
  group OS_CanIsr_1_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_1_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CanIsr_1_VAR_NOCACHE";
    }
    reserved ".pad.OS_CanIsr_1_VAR_NOCACHE" (size=16);
  }
  "_OS_CanIsr_1_VAR_NOCACHE_START" = "_lc_gb_OS_CanIsr_1_VAR_NOCACHE_GROUP";
  "_OS_CanIsr_1_VAR_NOCACHE_END" = "_lc_ub__pad_OS_CanIsr_1_VAR_NOCACHE" - 1;
  "_OS_CanIsr_1_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_CanIsr_1_VAR_NOCACHE";
}
else
{
  "_OS_CanIsr_1_VAR_NOCACHE_START" = 0;
  "_OS_CanIsr_1_VAR_NOCACHE_END" = 0;
  "_OS_CanIsr_1_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_1 ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_CanIsr_1_VAR_NOCACHE_NOINIT"))
{
  group OS_CanIsr_1_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_1_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CanIsr_1_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CanIsr_1_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CanIsr_1_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CanIsr_1_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CanIsr_1_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_1_VAR_NOCACHE_NOINIT" - 1;
  "_OS_CanIsr_1_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CanIsr_1_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CanIsr_1_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CanIsr_1_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_CanIsr_1_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_1 ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_CanIsr_1_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_1 ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_CanIsr_1_VAR_FAST_NOCACHE"))
{
  group OS_CanIsr_1_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_1_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CanIsr_1_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_CanIsr_1_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CanIsr_1_VAR_FAST_NOCACHE_GROUP";
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_CanIsr_1_VAR_FAST_NOCACHE" - 1;
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_CanIsr_1_VAR_FAST_NOCACHE";
}
else
{
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_START" = 0;
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_END" = 0;
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_1 ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_1 ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_CanIsr_1_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1
} /* OS_CanIsr_1_VAR_ALL_GROUP */
"_OS_CanIsr_1_VAR_ALL_START" = "_lc_gb_OS_CanIsr_1_VAR_ALL_GROUP";
"_OS_CanIsr_1_VAR_ALL_END" = "_lc_ge_OS_CanIsr_1_VAR_ALL_GROUP" - 1;
"_OS_CanIsr_1_VAR_ALL_LIMIT" = "_lc_ge_OS_CanIsr_1_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_CANISR_1
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_FAR
# undef OS_LINK_VAR_ISR_CANISR_1_FAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE
# undef OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_1_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_1_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_NEAR
# undef OS_LINK_VAR_ISR_CANISR_1_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE
# undef OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_1_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_1_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER
group OS_CounterIsr_SystemTimer_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_INIT )
if (exists(".data.OS_CounterIsr_SystemTimer_VAR"))
{
  group OS_CounterIsr_SystemTimer_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CounterIsr_SystemTimer_VAR";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR";
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
  group OS_CounterIsr_SystemTimer_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CounterIsr_SystemTimer_VAR_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_NOINIT" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_bss") || exists(".data.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_bss";
      select "[.]data.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT";
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
  group OS_CounterIsr_SystemTimer_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CounterIsr_SystemTimer_VAR_FAST";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_FAST" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST";
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
  group OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT";
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
  group OS_CounterIsr_SystemTimer_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CounterIsr_SystemTimer_VAR_NOCACHE";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_NOCACHE" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_NOCACHE_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_NOCACHE" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_NOCACHE";
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
  group OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT";
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
  group OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE";
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
  group OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT";
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



#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR
group OS_vHsmResponseIsr_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE_INIT )
if (exists(".data.OS_vHsmResponseIsr_VAR"))
{
  group OS_vHsmResponseIsr_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_vHsmResponseIsr_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_vHsmResponseIsr_VAR";
    }
    reserved ".pad.OS_vHsmResponseIsr_VAR" (size=16);
  }
  "_OS_vHsmResponseIsr_VAR_START" = "_lc_gb_OS_vHsmResponseIsr_VAR_GROUP";
  "_OS_vHsmResponseIsr_VAR_END" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR" - 1;
  "_OS_vHsmResponseIsr_VAR_LIMIT" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR";
}
else
{
  "_OS_vHsmResponseIsr_VAR_START" = 0;
  "_OS_vHsmResponseIsr_VAR_END" = 0;
  "_OS_vHsmResponseIsr_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_vHsmResponseIsr_VAR_NOINIT"))
{
  group OS_vHsmResponseIsr_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_vHsmResponseIsr_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsmResponseIsr_VAR_NOINIT";
    }
    reserved ".pad.OS_vHsmResponseIsr_VAR_NOINIT" (size=16);
  }
  "_OS_vHsmResponseIsr_VAR_NOINIT_START" = "_lc_gb_OS_vHsmResponseIsr_VAR_NOINIT_GROUP";
  "_OS_vHsmResponseIsr_VAR_NOINIT_END" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_NOINIT" - 1;
  "_OS_vHsmResponseIsr_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_NOINIT";
}
else
{
  "_OS_vHsmResponseIsr_VAR_NOINIT_START" = 0;
  "_OS_vHsmResponseIsr_VAR_NOINIT_END" = 0;
  "_OS_vHsmResponseIsr_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_vHsmResponseIsr_VAR_ZERO_INIT_bss") || exists(".data.OS_vHsmResponseIsr_VAR_ZERO_INIT"))
{
  group OS_vHsmResponseIsr_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_vHsmResponseIsr_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsmResponseIsr_VAR_ZERO_INIT_bss";
      select "[.]data.OS_vHsmResponseIsr_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_vHsmResponseIsr_VAR_ZERO_INIT" (size=16);
  }
  "_OS_vHsmResponseIsr_VAR_ZERO_INIT_START" = "_lc_gb_OS_vHsmResponseIsr_VAR_ZERO_INIT_GROUP";
  "_OS_vHsmResponseIsr_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_ZERO_INIT" - 1;
  "_OS_vHsmResponseIsr_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_ZERO_INIT";
}
else
{
  "_OS_vHsmResponseIsr_VAR_ZERO_INIT_START" = 0;
  "_OS_vHsmResponseIsr_VAR_ZERO_INIT_END" = 0;
  "_OS_vHsmResponseIsr_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_vHsmResponseIsr_VAR_FAST"))
{
  group OS_vHsmResponseIsr_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_vHsmResponseIsr_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_vHsmResponseIsr_VAR_FAST";
    }
    reserved ".pad.OS_vHsmResponseIsr_VAR_FAST" (size=16);
  }
  "_OS_vHsmResponseIsr_VAR_FAST_START" = "_lc_gb_OS_vHsmResponseIsr_VAR_FAST_GROUP";
  "_OS_vHsmResponseIsr_VAR_FAST_END" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_FAST" - 1;
  "_OS_vHsmResponseIsr_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_FAST";
}
else
{
  "_OS_vHsmResponseIsr_VAR_FAST_START" = 0;
  "_OS_vHsmResponseIsr_VAR_FAST_END" = 0;
  "_OS_vHsmResponseIsr_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_vHsmResponseIsr_VAR_FAST_NOINIT"))
{
  group OS_vHsmResponseIsr_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_vHsmResponseIsr_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsmResponseIsr_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_vHsmResponseIsr_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_vHsmResponseIsr_VAR_FAST_NOINIT_START" = "_lc_gb_OS_vHsmResponseIsr_VAR_FAST_NOINIT_GROUP";
  "_OS_vHsmResponseIsr_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_FAST_NOINIT" - 1;
  "_OS_vHsmResponseIsr_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_FAST_NOINIT";
}
else
{
  "_OS_vHsmResponseIsr_VAR_FAST_NOINIT_START" = 0;
  "_OS_vHsmResponseIsr_VAR_FAST_NOINIT_END" = 0;
  "_OS_vHsmResponseIsr_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT"))
{
  group OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT" - 1;
  "_OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_vHsmResponseIsr_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_vHsmResponseIsr_VAR_NOCACHE"))
{
  group OS_vHsmResponseIsr_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_vHsmResponseIsr_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_vHsmResponseIsr_VAR_NOCACHE";
    }
    reserved ".pad.OS_vHsmResponseIsr_VAR_NOCACHE" (size=16);
  }
  "_OS_vHsmResponseIsr_VAR_NOCACHE_START" = "_lc_gb_OS_vHsmResponseIsr_VAR_NOCACHE_GROUP";
  "_OS_vHsmResponseIsr_VAR_NOCACHE_END" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_NOCACHE" - 1;
  "_OS_vHsmResponseIsr_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_NOCACHE";
}
else
{
  "_OS_vHsmResponseIsr_VAR_NOCACHE_START" = 0;
  "_OS_vHsmResponseIsr_VAR_NOCACHE_END" = 0;
  "_OS_vHsmResponseIsr_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT"))
{
  group OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT" - 1;
  "_OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_vHsmResponseIsr_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_vHsmResponseIsr_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_vHsmResponseIsr_VAR_FAST_NOCACHE"))
{
  group OS_vHsmResponseIsr_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_vHsmResponseIsr_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_vHsmResponseIsr_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_vHsmResponseIsr_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_GROUP";
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_FAST_NOCACHE" - 1;
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_FAST_NOCACHE";
}
else
{
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_START" = 0;
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_END" = 0;
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_vHsmResponseIsr_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR
} /* OS_vHsmResponseIsr_VAR_ALL_GROUP */
"_OS_vHsmResponseIsr_VAR_ALL_START" = "_lc_gb_OS_vHsmResponseIsr_VAR_ALL_GROUP";
"_OS_vHsmResponseIsr_VAR_ALL_END" = "_lc_ge_OS_vHsmResponseIsr_VAR_ALL_GROUP" - 1;
"_OS_vHsmResponseIsr_VAR_ALL_LIMIT" = "_lc_ge_OS_vHsmResponseIsr_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_VHSMRESPONSEISR_NEAR_NOCACHE_ZERO_INIT
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


