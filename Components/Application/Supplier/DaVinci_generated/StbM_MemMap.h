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
 *              File: StbM_MemMap.h
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

#if defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_NO_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_NO_INIT_64_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_CLEARED_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_CLEARED_16_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_INIT_64_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_CLEARED_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_CLEARED_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_CLEARED_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_CLEARED_16_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NO_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NO_INIT_16_OPEN
#  error Using STBM_STOP_SEC_VAR_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_CONST_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_CONST_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_CONST_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_CommonSharedMemory_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_CONST_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_CONST_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_CONST_8_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_CONST_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_CONST_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_CommonSharedMemory_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CONST_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CONST_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CONST_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CONST_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CONST_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CONST_16_OPEN
#  error Using STBM_STOP_SEC_CONST_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CONST_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_CLEARED_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_CLEARED_8_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NO_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NO_INIT_16_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_INIT_16_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_INIT_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CODE_OPEN
#  error Using STBM_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_CLEARED_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_CLEARED_64_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_CLEARED_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_CLEARED_16_OPEN
#  error Using STBM_STOP_SEC_VAR_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_CONST_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_CONST_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_INIT_16_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_NO_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_NO_INIT_16_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_CLEARED_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_CLEARED_64_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_CONST_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_CONST_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_CONST_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_CONST_32_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_CONST_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_INIT_32_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_CommonSharedMemory_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_CONST_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_CommonSharedMemory_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NO_INIT_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NO_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_CLEARED_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_CLEARED_8_OPEN
#  error Using STBM_STOP_SEC_VAR_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_CLEARED_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_CLEARED_16_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_32_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_64_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CONST_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CONST_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CONST_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CONST_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CONST_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CONST_32_OPEN
#  error Using STBM_STOP_SEC_CONST_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CONST_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_INIT_32_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_64_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NO_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NO_INIT_32_OPEN
#  error Using STBM_STOP_SEC_VAR_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_CONST_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_CONST_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_CONST_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_CONST_64_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_CONST_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_CLEARED_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_CLEARED_32_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_INIT_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_NO_INIT_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_NO_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_CLEARED_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_CLEARED_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_CLEARED_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_CLEARED_32_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_CLEARED_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_CLEARED_8_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_32_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_INIT_64_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_CLEARED_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_CLEARED_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_CLEARED_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_CLEARED_32_OPEN
#  error Using STBM_STOP_SEC_VAR_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_32_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NO_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NO_INIT_32_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_CONST_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_CONST_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_CONST_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_CommonSharedMemory_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_CONST_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_CONST_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_CONST_16_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_CONST_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_CONST_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_CommonSharedMemory_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_CONST_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_CONST_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_CONST_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_CommonSharedMemory_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_CONST_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_CONST_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_CONST_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_CONST_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_CommonSharedMemory_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_INIT_32_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_INIT_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_INIT_8_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_INIT_16_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CONST_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CONST_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CONST_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CONST_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CONST_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CONST_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_CONST_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_INIT_8_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_16_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_INIT_16_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_8_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_NO_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_NO_INIT_16_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NO_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NO_INIT_8_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_CLEARED_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_CLEARED_16_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NO_INIT_8_OPEN
#  error Using STBM_STOP_SEC_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_64_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_16_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_8_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CONST_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CONST_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CONST_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CONST_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CONST_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CONST_64_OPEN
#  error Using STBM_STOP_SEC_CONST_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CONST_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_16_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_CLEARED_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_CLEARED_8_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_CONST_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_CONST_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_CONST_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_CommonSharedMemory_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_CONST_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_CONST_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_CONST_32_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_CONST_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_CONST_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_CommonSharedMemory_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_CONST_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_CONST_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_CONST_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_CONST_8_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_CONST_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NO_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NO_INIT_64_OPEN
#  error Using STBM_STOP_SEC_VAR_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_INIT_8_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_CLEARED_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_CLEARED_64_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_INIT_32_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_CLEARED_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_CLEARED_8_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_INIT_16_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_CLEARED_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_CLEARED_16_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_INIT_8_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_CLEARED_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_CLEARED_64_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CONST_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_CLEARED_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_CLEARED_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_NO_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_NO_INIT_32_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_INIT_8_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_INIT_64_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_CLEARED_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_CLEARED_64_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_INIT_64_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_NO_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_NO_INIT_16_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_INIT_CONFIGPTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_INIT_CONFIGPTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_INIT_CONFIGPTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_INIT_CONFIGPTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_INIT_CONFIGPTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_CONFIGPTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_INIT_CONFIGPTR_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_CONFIGPTR is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_INIT_CONFIGPTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_INIT_CONFIGPTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_NO_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_NO_INIT_64_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_INIT_8_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_INIT_8_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_CLEARED_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_CLEARED_64_OPEN
#  error Using STBM_STOP_SEC_VAR_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_INIT_16_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_CONST_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NO_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NO_INIT_64_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_INIT_64_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_CLEARED_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_CLEARED_32_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_INIT_64_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_INIT_64_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_CLEARED_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_CLEARED_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_VAR_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NO_INIT_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NO_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_VAR_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT/OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_NO_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_NO_INIT_64_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_CLEARED_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_CLEARED_32_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_INIT_32_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_INIT_64_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_INIT_32_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_CLEARED_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_CLEARED_8_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CONST_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CONST_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CONST_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CONST_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CONST_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CONST_8_OPEN
#  error Using STBM_STOP_SEC_CONST_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CONST_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_NO_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_NO_INIT_32_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_NO_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_NO_INIT_32_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_NO_INIT_8_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_INIT_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_CONST_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_CONST_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_CONST_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_CONST_16_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_CONST_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_FAST_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_FAST_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_FAST_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_FAST_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_FAST_INIT_16_OPEN
#  error Using STBM_STOP_SEC_VAR_FAST_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_FAST_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_VAR_NOCACHE_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_VAR_NOCACHE_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_VAR_NOCACHE_NO_INIT_8_OPEN
#  error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_VAR_NOCACHE_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_INIT_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_INIT_32_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_CLEARED_32_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_CLEARED_32_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_CONST_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_CONST_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_CONST_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_START_SEC_CommonSharedMemory_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_CONST_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_CONST_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_CONST_64_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_CONST_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_CONST_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef STBM_STOP_SEC_CommonSharedMemory_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_NOINIT/OS_OsApplication_Trusted_Core0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_OsApplication_Trusted_Core0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_OsApplication_Trusted_Core0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_OsApplication_Trusted_Core0_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_8_OPEN
#  error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_OsApplication_Trusted_Core0_VAR_FAST_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_Trusted_Core0_VAR_INIT/OS_OsApplication_Trusted_Core0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_ZERO_INIT/OS_GLOBALSHARED_VAR_ZERO_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define STBM_CommonSharedMemory_VAR_FAST_NO_INIT_8_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss "OS_GLOBALSHARED_VAR_FAST_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata "OS_GLOBALSHARED_VAR_FAST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef STBM_CommonSharedMemory_VAR_FAST_NO_INIT_8_OPEN
#  error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef STBM_CommonSharedMemory_VAR_FAST_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_NOINIT/OS_GLOBALSHARED_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section nearbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section neardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_64
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_64
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using STBM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_16
# error Using STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_16
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_INIT_64
# error Using STBM_START_SEC_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_INIT_64
# error Using STBM_STOP_SEC_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# error Using STBM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# error Using STBM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_CLEARED_16
# error Using STBM_START_SEC_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_CLEARED_16
# error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NO_INIT_16
# error Using STBM_START_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NO_INIT_16
# error Using STBM_STOP_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_CONST_8
# error Using STBM_START_SEC_CommonSharedMemory_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_CONST_8
# error Using STBM_STOP_SEC_CommonSharedMemory_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CONST_16
# error Using STBM_START_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CONST_16
# error Using STBM_STOP_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_CLEARED_8
# error Using STBM_START_SEC_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_CLEARED_8
# error Using STBM_STOP_SEC_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_16
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_16
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_16
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_16
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_INIT_BOOLEAN
# error Using STBM_START_SEC_CommonSharedMemory_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_BOOLEAN
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CODE
# error Using STBM_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CODE
# error Using STBM_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_64
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_64
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_CLEARED_16
# error Using STBM_START_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_CLEARED_16
# error Using STBM_STOP_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_INIT_16
# error Using STBM_START_SEC_CommonSharedMemory_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_16
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_NO_INIT_16
# error Using STBM_START_SEC_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_NO_INIT_16
# error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_64
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_64
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_CONST_32
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_32
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_INIT_32
# error Using STBM_START_SEC_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_INIT_32
# error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_CONST_UNSPECIFIED
# error Using STBM_START_SEC_CommonSharedMemory_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_CONST_UNSPECIFIED
# error Using STBM_STOP_SEC_CommonSharedMemory_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_BOOLEAN
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_BOOLEAN
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_CLEARED_8
# error Using STBM_START_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_CLEARED_8
# error Using STBM_STOP_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_CLEARED_16
# error Using STBM_START_SEC_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_CLEARED_16
# error Using STBM_STOP_SEC_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_32
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_32
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_64
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_64
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CONST_32
# error Using STBM_START_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CONST_32
# error Using STBM_STOP_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_INIT_32
# error Using STBM_START_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_INIT_32
# error Using STBM_STOP_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_64
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_64
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NO_INIT_32
# error Using STBM_START_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NO_INIT_32
# error Using STBM_STOP_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_CONST_64
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_64
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_32
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_32
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN
# error Using STBM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN
# error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN
# error Using STBM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN
# error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_CLEARED_BOOLEAN
# error Using STBM_START_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
# error Using STBM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_32
# error Using STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_32
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_8
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_8
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_32
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_32
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_64
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_64
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_CLEARED_UNSPECIFIED
# error Using STBM_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# error Using STBM_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_CLEARED_32
# error Using STBM_START_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_CLEARED_32
# error Using STBM_STOP_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_32
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_32
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_32
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_32
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_CONST_16
# error Using STBM_START_SEC_CommonSharedMemory_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_CONST_16
# error Using STBM_STOP_SEC_CommonSharedMemory_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_CONST_BOOLEAN
# error Using STBM_START_SEC_CommonSharedMemory_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_CONST_BOOLEAN
# error Using STBM_STOP_SEC_CommonSharedMemory_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_32
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_32
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_INIT_BOOLEAN
# error Using STBM_START_SEC_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_INIT_BOOLEAN
# error Using STBM_STOP_SEC_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using STBM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_INIT_8
# error Using STBM_START_SEC_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_INIT_8
# error Using STBM_STOP_SEC_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_INIT_16
# error Using STBM_START_SEC_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_INIT_16
# error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CONST_BOOLEAN
# error Using STBM_START_SEC_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CONST_BOOLEAN
# error Using STBM_STOP_SEC_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_INIT_8
# error Using STBM_START_SEC_CommonSharedMemory_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_8
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_16
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_16
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_INIT_16
# error Using STBM_START_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_INIT_16
# error Using STBM_STOP_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_INIT_UNSPECIFIED
# error Using STBM_START_SEC_CommonSharedMemory_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_8
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_8
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_NO_INIT_16
# error Using STBM_START_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_16
# error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_8
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_8
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_16
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_16
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NO_INIT_8
# error Using STBM_START_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NO_INIT_8
# error Using STBM_STOP_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_64
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_64
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_16
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_16
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_8
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_8
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CONST_64
# error Using STBM_START_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CONST_64
# error Using STBM_STOP_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_16
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_16
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_CLEARED_8
# error Using STBM_START_SEC_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_CLEARED_8
# error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_CONST_32
# error Using STBM_START_SEC_CommonSharedMemory_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_CONST_32
# error Using STBM_STOP_SEC_CommonSharedMemory_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_CONST_8
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_8
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using STBM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NO_INIT_64
# error Using STBM_START_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NO_INIT_64
# error Using STBM_STOP_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_8
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_8
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_CLEARED_64
# error Using STBM_START_SEC_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_CLEARED_64
# error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_INIT_32
# error Using STBM_START_SEC_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_INIT_32
# error Using STBM_STOP_SEC_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_8
# error Using STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_8
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_16
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_16
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_16
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_16
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_INIT_8
# error Using STBM_START_SEC_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_INIT_8
# error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_64
# error Using STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_64
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CONST_UNSPECIFIED
# error Using STBM_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CONST_UNSPECIFIED
# error Using STBM_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_BOOLEAN
# error Using STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_BOOLEAN
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_NO_INIT_32
# error Using STBM_START_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_32
# error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_8
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_8
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_INIT_64
# error Using STBM_START_SEC_CommonSharedMemory_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_64
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_CLEARED_64
# error Using STBM_START_SEC_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_CLEARED_64
# error Using STBM_STOP_SEC_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_64
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_64
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_16
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_16
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_INIT_CONFIGPTR
# error Using STBM_START_SEC_VAR_INIT_CONFIGPTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_INIT_CONFIGPTR
# error Using STBM_STOP_SEC_VAR_INIT_CONFIGPTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_NO_INIT_64
# error Using STBM_START_SEC_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_NO_INIT_64
# error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_INIT_8
# error Using STBM_START_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_INIT_8
# error Using STBM_STOP_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_8
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_8
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_CLEARED_64
# error Using STBM_START_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_CLEARED_64
# error Using STBM_STOP_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_16
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_16
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_64
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_64
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_INIT_64
# error Using STBM_START_SEC_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_INIT_64
# error Using STBM_STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_CLEARED_32
# error Using STBM_START_SEC_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_CLEARED_32
# error Using STBM_STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_64
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_64
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_CLEARED_BOOLEAN
# error Using STBM_START_SEC_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_CLEARED_BOOLEAN
# error Using STBM_STOP_SEC_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NO_INIT_BOOLEAN
# error Using STBM_START_SEC_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NO_INIT_BOOLEAN
# error Using STBM_STOP_SEC_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_NO_INIT_64
# error Using STBM_START_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_64
# error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_CLEARED_32
# error Using STBM_START_SEC_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_CLEARED_32
# error Using STBM_STOP_SEC_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using STBM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_INIT_32
# error Using STBM_START_SEC_CommonSharedMemory_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_32
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_INIT_64
# error Using STBM_START_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_INIT_64
# error Using STBM_STOP_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_32
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_32
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_8
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_8
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_INIT_UNSPECIFIED
# error Using STBM_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CONST_8
# error Using STBM_START_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CONST_8
# error Using STBM_STOP_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_NO_INIT_32
# error Using STBM_START_SEC_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_NO_INIT_32
# error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using STBM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# error Using STBM_START_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_32
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_32
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_NO_INIT_8
# error Using STBM_START_SEC_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_NO_INIT_8
# error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using STBM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_INIT_BOOLEAN
# error Using STBM_START_SEC_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_INIT_BOOLEAN
# error Using STBM_STOP_SEC_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_CONST_16
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_16
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_FAST_INIT_16
# error Using STBM_START_SEC_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_FAST_INIT_16
# error Using STBM_STOP_SEC_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_VAR_NOCACHE_NO_INIT_8
# error Using STBM_START_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
# error Using STBM_STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_32
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_32
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_32
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_32
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_CONST_64
# error Using STBM_START_SEC_CommonSharedMemory_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_CONST_64
# error Using STBM_STOP_SEC_CommonSharedMemory_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using STBM_START_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_8
# error Using STBM_START_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_8
# error Using STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED
# error Using STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_8
# error Using STBM_START_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_8
# error Using STBM_STOP_SEC_CommonSharedMemory_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#ifdef MEMMAP_ERROR
# error No MemMap section found in StbM_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: StbM_MemMap.h
 *********************************************************************************************************************/

/* PRQA S 0883 */ /* MD_MSR_MemMap */

