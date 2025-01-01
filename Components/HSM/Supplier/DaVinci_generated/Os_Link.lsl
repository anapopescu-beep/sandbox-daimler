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
 *              File: Os_Link.lsl
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CODE SECTIONS  (Tasking)
 *********************************************************************************************************************/

#if defined ( OS_LINK_CODE )
if (exists(".text.OS_CODE"))
{
  group OS_CODE_GROUP
  {
    select "[.]text.OS_CODE";
  }
  "_OS_CODE_START" = "_lc_gb_OS_CODE_GROUP";
  "_OS_CODE_END" = "_lc_ge_OS_CODE_GROUP" - 1;
  "_OS_CODE_LIMIT" = "_lc_ge_OS_CODE_GROUP";
}
else
{
  "_OS_CODE_START" = 0;
  "_OS_CODE_END" = 0;
  "_OS_CODE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_INTVEC_CODE )
if (exists(".text.OS_INTVEC_CODE"))
{
  group OS_INTVEC_CODE_GROUP(align=2048)
  {
    select "[.]text.OS_INTVEC_CODE";
  }
  "_OS_INTVEC_CODE_START" = "_lc_gb_OS_INTVEC_CODE_GROUP";
  "_OS_INTVEC_CODE_END" = "_lc_ge_OS_INTVEC_CODE_GROUP" - 1;
  "_OS_INTVEC_CODE_LIMIT" = "_lc_ge_OS_INTVEC_CODE_GROUP";
}
else
{
  "_OS_INTVEC_CODE_START" = 0;
  "_OS_INTVEC_CODE_END" = 0;
  "_OS_INTVEC_CODE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CALLOUT_CODE )
if (exists(".text.OS_ERRORHOOK_CODE"))
{
  group OS_ERRORHOOK_CODE_GROUP
  {
    select "[.]text.OS_ERRORHOOK_CODE";
  }
  "_OS_ERRORHOOK_CODE_START" = "_lc_gb_OS_ERRORHOOK_CODE_GROUP";
  "_OS_ERRORHOOK_CODE_END" = "_lc_ge_OS_ERRORHOOK_CODE_GROUP" - 1;
  "_OS_ERRORHOOK_CODE_LIMIT" = "_lc_ge_OS_ERRORHOOK_CODE_GROUP";
}
else
{
  "_OS_ERRORHOOK_CODE_START" = 0;
  "_OS_ERRORHOOK_CODE_END" = 0;
  "_OS_ERRORHOOK_CODE_LIMIT" = 0;
}
if (exists(".text.OS_OS_COREINITHOOK_CODE"))
{
  group OS_OS_COREINITHOOK_CODE_GROUP
  {
    select "[.]text.OS_OS_COREINITHOOK_CODE";
  }
  "_OS_OS_COREINITHOOK_CODE_START" = "_lc_gb_OS_OS_COREINITHOOK_CODE_GROUP";
  "_OS_OS_COREINITHOOK_CODE_END" = "_lc_ge_OS_OS_COREINITHOOK_CODE_GROUP" - 1;
  "_OS_OS_COREINITHOOK_CODE_LIMIT" = "_lc_ge_OS_OS_COREINITHOOK_CODE_GROUP";
}
else
{
  "_OS_OS_COREINITHOOK_CODE_START" = 0;
  "_OS_OS_COREINITHOOK_CODE_END" = 0;
  "_OS_OS_COREINITHOOK_CODE_LIMIT" = 0;
}
if (exists(".text.OS_PANICHOOK_CODE"))
{
  group OS_PANICHOOK_CODE_GROUP
  {
    select "[.]text.OS_PANICHOOK_CODE";
  }
  "_OS_PANICHOOK_CODE_START" = "_lc_gb_OS_PANICHOOK_CODE_GROUP";
  "_OS_PANICHOOK_CODE_END" = "_lc_ge_OS_PANICHOOK_CODE_GROUP" - 1;
  "_OS_PANICHOOK_CODE_LIMIT" = "_lc_ge_OS_PANICHOOK_CODE_GROUP";
}
else
{
  "_OS_PANICHOOK_CODE_START" = 0;
  "_OS_PANICHOOK_CODE_END" = 0;
  "_OS_PANICHOOK_CODE_LIMIT" = 0;
}
if (exists(".text.OS_SHUTDOWNHOOK_CODE"))
{
  group OS_SHUTDOWNHOOK_CODE_GROUP
  {
    select "[.]text.OS_SHUTDOWNHOOK_CODE";
  }
  "_OS_SHUTDOWNHOOK_CODE_START" = "_lc_gb_OS_SHUTDOWNHOOK_CODE_GROUP";
  "_OS_SHUTDOWNHOOK_CODE_END" = "_lc_ge_OS_SHUTDOWNHOOK_CODE_GROUP" - 1;
  "_OS_SHUTDOWNHOOK_CODE_LIMIT" = "_lc_ge_OS_SHUTDOWNHOOK_CODE_GROUP";
}
else
{
  "_OS_SHUTDOWNHOOK_CODE_START" = 0;
  "_OS_SHUTDOWNHOOK_CODE_END" = 0;
  "_OS_SHUTDOWNHOOK_CODE_LIMIT" = 0;
}
if (exists(".text.OS_STARTUPHOOK_CODE"))
{
  group OS_STARTUPHOOK_CODE_GROUP
  {
    select "[.]text.OS_STARTUPHOOK_CODE";
  }
  "_OS_STARTUPHOOK_CODE_START" = "_lc_gb_OS_STARTUPHOOK_CODE_GROUP";
  "_OS_STARTUPHOOK_CODE_END" = "_lc_ge_OS_STARTUPHOOK_CODE_GROUP" - 1;
  "_OS_STARTUPHOOK_CODE_LIMIT" = "_lc_ge_OS_STARTUPHOOK_CODE_GROUP";
}
else
{
  "_OS_STARTUPHOOK_CODE_START" = 0;
  "_OS_STARTUPHOOK_CODE_END" = 0;
  "_OS_STARTUPHOOK_CODE_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_CODE
# undef OS_LINK_CODE
#endif

#ifdef OS_LINK_INTVEC_CODE
# undef OS_LINK_INTVEC_CODE
#endif

#ifdef OS_LINK_CALLOUT_CODE
# undef OS_LINK_CALLOUT_CODE
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_FAR )
if (exists(".rodata.OS_CONST"))
{
  group OS_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_CONST";
  }
  "_OS_CONST_START" = "_lc_gb_OS_CONST_GROUP";
  "_OS_CONST_END" = "_lc_ge_OS_CONST_GROUP" - 1;
  "_OS_CONST_LIMIT" = "_lc_ge_OS_CONST_GROUP";
}
else
{
  "_OS_CONST_START" = 0;
  "_OS_CONST_END" = 0;
  "_OS_CONST_LIMIT" = 0;
}
if (exists(".rodata.OS_GLOBALSHARED_CONST"))
{
  group OS_GLOBALSHARED_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_GLOBALSHARED_CONST";
  }
  "_OS_GLOBALSHARED_CONST_START" = "_lc_gb_OS_GLOBALSHARED_CONST_GROUP";
  "_OS_GLOBALSHARED_CONST_END" = "_lc_ge_OS_GLOBALSHARED_CONST_GROUP" - 1;
  "_OS_GLOBALSHARED_CONST_LIMIT" = "_lc_ge_OS_GLOBALSHARED_CONST_GROUP";
}
else
{
  "_OS_GLOBALSHARED_CONST_START" = 0;
  "_OS_GLOBALSHARED_CONST_END" = 0;
  "_OS_GLOBALSHARED_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_NEAR )
if (exists(".zrodata.OS_CONST_FAST"))
{
  group OS_CONST_FAST_GROUP(ordered, contiguous, fill)
  {
    select "[.]zrodata.OS_CONST_FAST";
  }
  "_OS_CONST_FAST_START" = "_lc_gb_OS_CONST_FAST_GROUP";
  "_OS_CONST_FAST_END" = "_lc_ge_OS_CONST_FAST_GROUP" - 1;
  "_OS_CONST_FAST_LIMIT" = "_lc_ge_OS_CONST_FAST_GROUP";
}
else
{
  "_OS_CONST_FAST_START" = 0;
  "_OS_CONST_FAST_END" = 0;
  "_OS_CONST_FAST_LIMIT" = 0;
}
if (exists(".zrodata.OS_GLOBALSHARED_CONST_FAST"))
{
  group OS_GLOBALSHARED_CONST_FAST_GROUP(ordered, contiguous, fill)
  {
    select "[.]zrodata.OS_GLOBALSHARED_CONST_FAST";
  }
  "_OS_GLOBALSHARED_CONST_FAST_START" = "_lc_gb_OS_GLOBALSHARED_CONST_FAST_GROUP";
  "_OS_GLOBALSHARED_CONST_FAST_END" = "_lc_ge_OS_GLOBALSHARED_CONST_FAST_GROUP" - 1;
  "_OS_GLOBALSHARED_CONST_FAST_LIMIT" = "_lc_ge_OS_GLOBALSHARED_CONST_FAST_GROUP";
}
else
{
  "_OS_GLOBALSHARED_CONST_FAST_START" = 0;
  "_OS_GLOBALSHARED_CONST_FAST_END" = 0;
  "_OS_GLOBALSHARED_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_NEAR ) || defined ( OS_LINK_CONST_GLOBALSHARED_NEAR_INIT )


#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_NEAR ) || defined ( OS_LINK_CONST_GLOBALSHARED_NEAR_ZERO_INIT )


#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_FAR ) || defined ( OS_LINK_CONST_GLOBALSHARED_FAR_INIT )


#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_FAR ) || defined ( OS_LINK_CONST_GLOBALSHARED_FAR_ZERO_INIT )


#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_NEAR ) || defined ( OS_LINK_CONST_NEAR_INIT )

#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_FAR ) || defined ( OS_LINK_CONST_FAR_INIT )

#endif

#if defined ( OS_LINK_INTVEC_CONST )
if (exists(".rodata.OS_INTVEC_CONST"))
{
  group OS_INTVEC_CONST_GROUP(ordered, contiguous, fill)
  {
    select "[.]rodata.OS_INTVEC_CONST";
  }
  "_OS_INTVEC_CONST_START" = "_lc_gb_OS_INTVEC_CONST_GROUP";
  "_OS_INTVEC_CONST_END" = "_lc_ge_OS_INTVEC_CONST_GROUP" - 1;
  "_OS_INTVEC_CONST_LIMIT" = "_lc_ge_OS_INTVEC_CONST_GROUP";
}
else
{
  "_OS_INTVEC_CONST_START" = 0;
  "_OS_INTVEC_CONST_END" = 0;
  "_OS_INTVEC_CONST_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_CONST
# undef OS_LINK_CONST
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED
# undef OS_LINK_CONST_GLOBALSHARED
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_NEAR
# undef OS_LINK_CONST_GLOBALSHARED_NEAR
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_FAR
# undef OS_LINK_CONST_GLOBALSHARED_FAR
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_NEAR_INIT
# undef OS_LINK_CONST_GLOBALSHARED_NEAR_INIT
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_FAR_INIT
# undef OS_LINK_CONST_GLOBALSHARED_FAR_INIT
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_NEAR_ZERO_INIT
# undef OS_LINK_CONST_GLOBALSHARED_NEAR_ZERO_INIT
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_FAR_ZERO_INIT
# undef OS_LINK_CONST_GLOBALSHARED_FAR_ZERO_INIT
#endif

#ifdef OS_LINK_CONST_NEAR_INIT
# undef OS_LINK_CONST_NEAR_INIT
#endif

#ifdef OS_LINK_CONST_FAR_INIT
# undef OS_LINK_CONST_FAR_INIT
#endif

#ifdef OS_LINK_INTVEC_CONST
# undef OS_LINK_INTVEC_CONST
#endif


/**********************************************************************************************************************
 *  KERNEL VAR SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_INIT )
if (exists(".data.OS_VAR_NOCACHE"))
{
  group OS_VAR_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_VAR_NOCACHE";
    }
  }
  "_OS_VAR_NOCACHE_START" = "_lc_gb_OS_VAR_NOCACHE_GROUP";
  "_OS_VAR_NOCACHE_END" = "_lc_ge_OS_VAR_NOCACHE_GROUP" - 1;
  "_OS_VAR_NOCACHE_LIMIT" = "_lc_ge_OS_VAR_NOCACHE_GROUP";
}
else
{
  "_OS_VAR_NOCACHE_START" = 0;
  "_OS_VAR_NOCACHE_END" = 0;
  "_OS_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOINIT )
if (exists(".bss.OS_VAR_NOCACHE_NOINIT"))
{
  group OS_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_INIT )
if (exists(".zdata.OS_VAR_FAST_NOCACHE"))
{
  group OS_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_VAR_FAST_NOCACHE";
    }
  }
  "_OS_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_VAR_FAST_NOCACHE_GROUP";
  "_OS_VAR_FAST_NOCACHE_END" = "_lc_ge_OS_VAR_FAST_NOCACHE_GROUP" - 1;
  "_OS_VAR_FAST_NOCACHE_LIMIT" = "_lc_ge_OS_VAR_FAST_NOCACHE_GROUP";
}
else
{
  "_OS_VAR_FAST_NOCACHE_START" = 0;
  "_OS_VAR_FAST_NOCACHE_END" = 0;
  "_OS_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOINIT )
if (exists(".zbss.OS_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_KERNEL
# undef OS_LINK_VAR_KERNEL
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR
# undef OS_LINK_VAR_KERNEL_FAR
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_INIT
# undef OS_LINK_VAR_KERNEL_FAR_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR
# undef OS_LINK_VAR_KERNEL_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOINIT
#endif


/**********************************************************************************************************************
 *  GLOBALSHARED VAR SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_INIT )
if (exists(".data.OS_GLOBALSHARED_VAR"))
{
  group OS_GLOBALSHARED_VAR_GROUP(ordered, contiguous, fill)
  {
    section "OS_GLOBALSHARED_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_GLOBALSHARED_VAR";
    }
  }
  "_OS_GLOBALSHARED_VAR_START" = "_lc_gb_OS_GLOBALSHARED_VAR_GROUP";
  "_OS_GLOBALSHARED_VAR_END" = "_lc_ge_OS_GLOBALSHARED_VAR_GROUP" - 1;
  "_OS_GLOBALSHARED_VAR_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_GROUP";
}
else
{
  "_OS_GLOBALSHARED_VAR_START" = 0;
  "_OS_GLOBALSHARED_VAR_END" = 0;
  "_OS_GLOBALSHARED_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_INIT )
if (exists(".data.OS_GLOBALSHARED_VAR_NOCACHE"))
{
  group OS_GLOBALSHARED_VAR_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_GLOBALSHARED_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_GLOBALSHARED_VAR_NOCACHE";
    }
  }
  "_OS_GLOBALSHARED_VAR_NOCACHE_START" = "_lc_gb_OS_GLOBALSHARED_VAR_NOCACHE_GROUP";
  "_OS_GLOBALSHARED_VAR_NOCACHE_END" = "_lc_ge_OS_GLOBALSHARED_VAR_NOCACHE_GROUP" - 1;
  "_OS_GLOBALSHARED_VAR_NOCACHE_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_NOCACHE_GROUP";
}
else
{
  "_OS_GLOBALSHARED_VAR_NOCACHE_START" = 0;
  "_OS_GLOBALSHARED_VAR_NOCACHE_END" = 0;
  "_OS_GLOBALSHARED_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_NOINIT )
if (exists(".bss.OS_GLOBALSHARED_VAR_NOINIT"))
{
  group OS_GLOBALSHARED_VAR_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_GLOBALSHARED_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_GLOBALSHARED_VAR_NOINIT";
    }
  }
  "_OS_GLOBALSHARED_VAR_NOINIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_NOINIT_GROUP";
  "_OS_GLOBALSHARED_VAR_NOINIT_END" = "_lc_ge_OS_GLOBALSHARED_VAR_NOINIT_GROUP" - 1;
  "_OS_GLOBALSHARED_VAR_NOINIT_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_NOINIT_GROUP";
}
else
{
  "_OS_GLOBALSHARED_VAR_NOINIT_START" = 0;
  "_OS_GLOBALSHARED_VAR_NOINIT_END" = 0;
  "_OS_GLOBALSHARED_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_GLOBALSHARED_VAR_NOCACHE_NOINIT"))
{
  group OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_GLOBALSHARED_VAR_NOCACHE_NOINIT";
    }
  }
  "_OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_END" = "_lc_ge_OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_GLOBALSHARED_VAR_ZERO_INIT") || exists(".data.OS_GLOBALSHARED_VAR_ZERO_INIT"))
{
  group OS_GLOBALSHARED_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_GLOBALSHARED_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_GLOBALSHARED_VAR_ZERO_INIT";
      select "[.]data.OS_GLOBALSHARED_VAR_ZERO_INIT";
    }
  }
  "_OS_GLOBALSHARED_VAR_ZERO_INIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_ZERO_INIT_GROUP";
  "_OS_GLOBALSHARED_VAR_ZERO_INIT_END" = "_lc_ge_OS_GLOBALSHARED_VAR_ZERO_INIT_GROUP" - 1;
  "_OS_GLOBALSHARED_VAR_ZERO_INIT_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_ZERO_INIT_GROUP";
}
else
{
  "_OS_GLOBALSHARED_VAR_ZERO_INIT_START" = 0;
  "_OS_GLOBALSHARED_VAR_ZERO_INIT_END" = 0;
  "_OS_GLOBALSHARED_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT") || exists(".data.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT";
      select "[.]data.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_INIT )
if (exists(".zdata.OS_GLOBALSHARED_VAR_FAST"))
{
  group OS_GLOBALSHARED_VAR_FAST_GROUP(ordered, contiguous, fill)
  {
    section "OS_GLOBALSHARED_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_GLOBALSHARED_VAR_FAST";
    }
  }
  "_OS_GLOBALSHARED_VAR_FAST_START" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_GROUP";
  "_OS_GLOBALSHARED_VAR_FAST_END" = "_lc_ge_OS_GLOBALSHARED_VAR_FAST_GROUP" - 1;
  "_OS_GLOBALSHARED_VAR_FAST_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_FAST_GROUP";
}
else
{
  "_OS_GLOBALSHARED_VAR_FAST_START" = 0;
  "_OS_GLOBALSHARED_VAR_FAST_END" = 0;
  "_OS_GLOBALSHARED_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_GLOBALSHARED_VAR_FAST_NOCACHE"))
{
  group OS_GLOBALSHARED_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill)
  {
    section "OS_GLOBALSHARED_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_GLOBALSHARED_VAR_FAST_NOCACHE";
    }
  }
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_NOCACHE_GROUP";
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_END" = "_lc_ge_OS_GLOBALSHARED_VAR_FAST_NOCACHE_GROUP" - 1;
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_FAST_NOCACHE_GROUP";
}
else
{
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_START" = 0;
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_END" = 0;
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_GLOBALSHARED_VAR_FAST_NOINIT"))
{
  group OS_GLOBALSHARED_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_GLOBALSHARED_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_GLOBALSHARED_VAR_FAST_NOINIT";
    }
  }
  "_OS_GLOBALSHARED_VAR_FAST_NOINIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_NOINIT_GROUP";
  "_OS_GLOBALSHARED_VAR_FAST_NOINIT_END" = "_lc_ge_OS_GLOBALSHARED_VAR_FAST_NOINIT_GROUP" - 1;
  "_OS_GLOBALSHARED_VAR_FAST_NOINIT_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_FAST_NOINIT_GROUP";
}
else
{
  "_OS_GLOBALSHARED_VAR_FAST_NOINIT_START" = 0;
  "_OS_GLOBALSHARED_VAR_FAST_NOINIT_END" = 0;
  "_OS_GLOBALSHARED_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT";
    }
  }
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ge_OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_GROUP" - 1;
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_GROUP";
}
else
{
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT") || exists(".zdata.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT"))
{
  group OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT";
      select "[.]zdata.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT";
    }
  }
  "_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_END" = "_lc_ge_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_GROUP" - 1;
  "_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_GROUP";
}
else
{
  "_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT") || exists(".zdata.OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill)
  {
    section "OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT";
      select "[.]zdata.OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT";
    }
  }
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ge_OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_GROUP" - 1;
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
}
else
{
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED
# undef OS_LINK_VAR_GLOBALSHARED
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR
# undef OS_LINK_VAR_GLOBALSHARED_NEAR
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR
# undef OS_LINK_VAR_GLOBALSHARED_FAR
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE
# undef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE
# undef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_ZERO_INIT
#endif


/**********************************************************************************************************************
 *  CORESHARED VAR SECTIONS
 *********************************************************************************************************************/

#ifdef OS_LINK_VAR_CORESHARED
# undef OS_LINK_VAR_CORESHARED
#endif


/**********************************************************************************************************************
 *  APPSHARED VAR SECTIONS
 *********************************************************************************************************************/

#ifdef OS_LINK_VAR_APPSHARED
# undef OS_LINK_VAR_APPSHARED
#endif

#ifdef OS_LINK_VAR
# undef OS_LINK_VAR
#endif


