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
 *            Module: MemMap
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: StbM_SystemApplication_OsCore0_MemMap.h
 *   Generation Time: 2023-07-10 14:36:06
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef MICROSAR_DISABLE_MEMMAP

/**********************************************************************************************************************
 *  PRE USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

/**********************************************************************************************************************
 *  MEMMAP SECTIONS
 *********************************************************************************************************************/

#define MEMMAP_ERROR

#if defined StbM_SystemApplication_OsCore0_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using StbM_SystemApplication_OsCore0_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define StbM_SystemApplication_OsCore0_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef StbM_SystemApplication_OsCore0_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined StbM_SystemApplication_OsCore0_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using StbM_SystemApplication_OsCore0_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef StbM_SystemApplication_OsCore0_CODE_OPEN
#  error Using StbM_SystemApplication_OsCore0_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef StbM_SystemApplication_OsCore0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef StbM_SystemApplication_OsCore0_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined StbM_SystemApplication_OsCore0_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using StbM_SystemApplication_OsCore0_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define StbM_SystemApplication_OsCore0_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef StbM_SystemApplication_OsCore0_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined StbM_SystemApplication_OsCore0_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using StbM_SystemApplication_OsCore0_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef StbM_SystemApplication_OsCore0_CONST_UNSPECIFIED_OPEN
#  error Using StbM_SystemApplication_OsCore0_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef StbM_SystemApplication_OsCore0_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef StbM_SystemApplication_OsCore0_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined StbM_SystemApplication_OsCore0_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using StbM_SystemApplication_OsCore0_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define StbM_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_CORE0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_CORE0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_CORE0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef StbM_SystemApplication_OsCore0_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined StbM_SystemApplication_OsCore0_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using StbM_SystemApplication_OsCore0_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef StbM_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using StbM_SystemApplication_OsCore0_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef StbM_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef StbM_SystemApplication_OsCore0_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined StbM_SystemApplication_OsCore0_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using StbM_SystemApplication_OsCore0_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define StbM_SystemApplication_OsCore0_VAR_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_CORE0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_CORE0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_CORE0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef StbM_SystemApplication_OsCore0_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined StbM_SystemApplication_OsCore0_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using StbM_SystemApplication_OsCore0_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef StbM_SystemApplication_OsCore0_VAR_INIT_UNSPECIFIED_OPEN
#  error Using StbM_SystemApplication_OsCore0_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef StbM_SystemApplication_OsCore0_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef StbM_SystemApplication_OsCore0_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined StbM_SystemApplication_OsCore0_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using StbM_SystemApplication_OsCore0_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define StbM_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_ZERO_INIT/OS_SystemApplication_OsCore0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_CORE0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef StbM_SystemApplication_OsCore0_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined StbM_SystemApplication_OsCore0_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using StbM_SystemApplication_OsCore0_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef StbM_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Using StbM_SystemApplication_OsCore0_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef StbM_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_ZERO_INIT/OS_SystemApplication_OsCore0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef StbM_SystemApplication_OsCore0_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef StbM_SystemApplication_OsCore0_START_SEC_CODE
# error Using StbM_SystemApplication_OsCore0_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef StbM_SystemApplication_OsCore0_STOP_SEC_CODE
# error Using StbM_SystemApplication_OsCore0_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef StbM_SystemApplication_OsCore0_START_SEC_CONST_UNSPECIFIED
# error Using StbM_SystemApplication_OsCore0_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef StbM_SystemApplication_OsCore0_STOP_SEC_CONST_UNSPECIFIED
# error Using StbM_SystemApplication_OsCore0_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef StbM_SystemApplication_OsCore0_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using StbM_SystemApplication_OsCore0_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef StbM_SystemApplication_OsCore0_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using StbM_SystemApplication_OsCore0_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef StbM_SystemApplication_OsCore0_START_SEC_VAR_INIT_UNSPECIFIED
# error Using StbM_SystemApplication_OsCore0_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef StbM_SystemApplication_OsCore0_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using StbM_SystemApplication_OsCore0_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef StbM_SystemApplication_OsCore0_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using StbM_SystemApplication_OsCore0_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef StbM_SystemApplication_OsCore0_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using StbM_SystemApplication_OsCore0_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#ifdef MEMMAP_ERROR
# error No MemMap section found in StbM_SystemApplication_OsCore0_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: StbM_SystemApplication_OsCore0_MemMap.h
 *********************************************************************************************************************/

/* PRQA S 0883 */ /* MD_MSR_MemMap */

