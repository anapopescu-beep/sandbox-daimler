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
 *              File: Os_Link_Core0.lsl
 *   Generation Time: 2022-04-13 13:52:51
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
if (exists(".text.OS_vHsm_Hal_ExternalRequestIsr_CODE"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_CODE_GROUP
  {
    select "[.]text.OS_vHsm_Hal_ExternalRequestIsr_CODE";
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_CODE_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_CODE_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_CODE_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_CODE_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_CODE_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_CODE_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_CODE_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_CODE_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_CODE_LIMIT" = 0;
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



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR )
if (exists(".rodata.OS_vHsm_Hal_ExternalRequestIsr_CONST"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_vHsm_Hal_ExternalRequestIsr_CONST";
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_CONST_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_CONST_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_CONST_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_CONST_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_CONST_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_CONST_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_CONST_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_CONST_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR )
if (exists(".zrodata.OS_vHsm_Hal_ExternalRequestIsr_CONST_FAST"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_CONST_FAST_GROUP(ordered, contiguous, fill)
  {
    select "[.]zrodata.OS_vHsm_Hal_ExternalRequestIsr_CONST_FAST";
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_CONST_FAST_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_CONST_FAST_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_CONST_FAST_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_CONST_FAST_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_CONST_FAST_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_CONST_FAST_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_CONST_FAST_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_CONST_FAST_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR
# undef OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR
#endif

#ifdef OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR
# undef OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR
# undef OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR_INIT
# undef OS_LINK_CONST_ISR_VHSM_HAL_EXTERNALREQUESTISR_INIT
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



#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR
group OS_vHsm_Hal_ExternalRequestIsr_VAR_ALL_GROUP(ordered, contiguous, fill)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE_INIT )
if (exists(".data.OS_vHsm_Hal_ExternalRequestIsr_VAR"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_VAR_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_ExternalRequestIsr_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_vHsm_Hal_ExternalRequestIsr_VAR";
    }
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_VAR_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_vHsm_Hal_ExternalRequestIsr_VAR_NOINIT"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_VAR_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_ExternalRequestIsr_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsm_Hal_ExternalRequestIsr_VAR_NOINIT";
    }
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOINIT_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOINIT_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOINIT_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOINIT_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOINIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOINIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOINIT_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOINIT_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT") || exists(".data.OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT";
      select "[.]data.OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT";
    }
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST";
    }
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOINIT"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOINIT";
    }
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOINIT_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOINIT_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOINIT_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOINIT_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOINIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOINIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOINIT_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOINIT_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT") || exists(".zdata.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT";
      select "[.]zdata.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT";
    }
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE";
    }
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_NOINIT"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT") || exists(".data.OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT";
      select "[.]data.OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE";
    }
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT") || exists(".zdata.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT";
      select "[.]zdata.OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_vHsm_Hal_ExternalRequestIsr_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR
} /* OS_vHsm_Hal_ExternalRequestIsr_VAR_ALL_GROUP */
"_OS_vHsm_Hal_ExternalRequestIsr_VAR_ALL_START" = "_lc_gb_OS_vHsm_Hal_ExternalRequestIsr_VAR_ALL_GROUP";
"_OS_vHsm_Hal_ExternalRequestIsr_VAR_ALL_END" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_ALL_GROUP" - 1;
"_OS_vHsm_Hal_ExternalRequestIsr_VAR_ALL_LIMIT" = "_lc_ge_OS_vHsm_Hal_ExternalRequestIsr_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_VHSM_HAL_EXTERNALREQUESTISR_NEAR_NOCACHE_ZERO_INIT
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


