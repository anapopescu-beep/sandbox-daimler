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
 *              File: BswM_MemMap.h
 *   Generation Time: 2023-07-10 14:36:04
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

#if defined BSWM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_INIT_64_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_CLEARED_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_CLEARED_UNSPECIFIED_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NO_INIT_8_OPEN
#  error Using BSWM_STOP_SEC_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_CLEARED_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_CLEARED_16_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NO_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NO_INIT_16_OPEN
#  error Using BSWM_STOP_SEC_VAR_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_CONST_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_CONST_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_CONST_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_CONST_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_CONST_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_CONST_16_OPEN
#  error Using BSWM_STOP_SEC_CONST_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_CONST_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_CLEARED_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_CLEARED_8_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_CODE_OPEN
#  error Using BSWM_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_CONST_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_CONST_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_CONST_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_CONST_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_CONST_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_CONST_64_OPEN
#  error Using BSWM_STOP_SEC_CONST_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_CONST_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_CLEARED_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_CLEARED_8_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_CLEARED_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_CLEARED_16_OPEN
#  error Using BSWM_STOP_SEC_VAR_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_NO_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_NO_INIT_16_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NO_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NO_INIT_64_OPEN
#  error Using BSWM_STOP_SEC_VAR_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_CLEARED_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_CLEARED_64_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_INIT_32_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_INIT_32_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_CLEARED_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_CLEARED_8_OPEN
#  error Using BSWM_STOP_SEC_VAR_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_CLEARED_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_CLEARED_16_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_INIT_8_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_CONST_UNSPECIFIED_OPEN
#  error Using BSWM_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_NO_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_NO_INIT_32_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_CONST_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_CONST_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_CONST_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_CONST_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_CONST_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_CONST_32_OPEN
#  error Using BSWM_STOP_SEC_CONST_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_CONST_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_CLEARED_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_CLEARED_64_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_INIT_32_OPEN
#  error Using BSWM_STOP_SEC_VAR_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_NO_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_NO_INIT_64_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_INIT_8_OPEN
#  error Using BSWM_STOP_SEC_VAR_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_CLEARED_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_CLEARED_64_OPEN
#  error Using BSWM_STOP_SEC_VAR_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NO_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NO_INIT_32_OPEN
#  error Using BSWM_STOP_SEC_VAR_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_INIT_64_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_CLEARED_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_CLEARED_32_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_INIT_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_INIT_BOOLEAN_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_NO_INIT_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_NO_INIT_BOOLEAN_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_CLEARED_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_CLEARED_BOOLEAN_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_CLEARED_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_CLEARED_BOOLEAN_OPEN
#  error Using BSWM_STOP_SEC_VAR_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NO_INIT_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NO_INIT_BOOLEAN_OPEN
#  error Using BSWM_STOP_SEC_VAR_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_NO_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_NO_INIT_64_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_CLEARED_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_CLEARED_32_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_INIT_64_OPEN
#  error Using BSWM_STOP_SEC_VAR_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_CLEARED_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_CLEARED_UNSPECIFIED_OPEN
#  error Using BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_INIT_UNSPECIFIED_OPEN
#  error Using BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_CONST_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_CONST_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_CONST_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_CONST_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_CONST_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_CONST_8_OPEN
#  error Using BSWM_STOP_SEC_CONST_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_CONST_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_NO_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_NO_INIT_32_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_CLEARED_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_CLEARED_32_OPEN
#  error Using BSWM_STOP_SEC_VAR_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_INIT_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_INIT_BOOLEAN_OPEN
#  error Using BSWM_STOP_SEC_VAR_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_INIT_UNSPECIFIED_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_NO_INIT_8_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_INIT_8_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_INIT_16_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_INIT_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_INIT_BOOLEAN_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_FAST_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_FAST_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_FAST_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_FAST_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_FAST_INIT_16_OPEN
#  error Using BSWM_STOP_SEC_VAR_FAST_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_FAST_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_NO_INIT_8_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_CONST_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_CONST_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_CONST_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_CONST_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_CONST_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_CONST_BOOLEAN_OPEN
#  error Using BSWM_STOP_SEC_CONST_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_INIT_16_OPEN
#  error Using BSWM_STOP_SEC_VAR_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BSWM_START_SEC_VAR_NOCACHE_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using BSWM_START_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BSWM_VAR_NOCACHE_NO_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_START_SEC_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BSWM_VAR_NOCACHE_NO_INIT_16_OPEN
#  error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef BSWM_VAR_NOCACHE_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BswM_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using BswM_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BswM_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BswM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BswM_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using BswM_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BswM_CODE_OPEN
#  error Using BswM_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef BswM_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BswM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BswM_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BswM_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BswM_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BswM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BswM_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BswM_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BswM_CONST_UNSPECIFIED_OPEN
#  error Using BswM_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BswM_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BswM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BswM_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BswM_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BswM_VAR_NOINIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BswM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BswM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BswM_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BswM_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using BswM_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BswM_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BswM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BswM_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BswM_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BswM_VAR_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BswM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BswM_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BswM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BswM_VAR_INIT_UNSPECIFIED_OPEN
#  error Using BswM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BswM_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BswM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined BswM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using BswM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define BswM_VAR_ZERO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BswM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined BswM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using BswM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef BswM_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Using BswM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef BswM_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef BswM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef BSWM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using BSWM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_INIT_64
# error Using BSWM_START_SEC_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_INIT_64
# error Using BSWM_STOP_SEC_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# error Using BSWM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NO_INIT_8
# error Using BSWM_START_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NO_INIT_8
# error Using BSWM_STOP_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_CLEARED_16
# error Using BSWM_START_SEC_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_16
# error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NO_INIT_16
# error Using BSWM_START_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NO_INIT_16
# error Using BSWM_STOP_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_CONST_16
# error Using BSWM_START_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_CONST_16
# error Using BSWM_STOP_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_CLEARED_8
# error Using BSWM_START_SEC_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_CLEARED_8
# error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_CODE
# error Using BSWM_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_CODE
# error Using BSWM_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_CONST_64
# error Using BSWM_START_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_CONST_64
# error Using BSWM_STOP_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_CLEARED_8
# error Using BSWM_START_SEC_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_8
# error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_CLEARED_16
# error Using BSWM_START_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_CLEARED_16
# error Using BSWM_STOP_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using BSWM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_NO_INIT_16
# error Using BSWM_START_SEC_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_NO_INIT_16
# error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NO_INIT_64
# error Using BSWM_START_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NO_INIT_64
# error Using BSWM_STOP_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_CLEARED_64
# error Using BSWM_START_SEC_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_64
# error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_INIT_32
# error Using BSWM_START_SEC_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_INIT_32
# error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_INIT_32
# error Using BSWM_START_SEC_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_INIT_32
# error Using BSWM_STOP_SEC_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_CLEARED_8
# error Using BSWM_START_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_CLEARED_8
# error Using BSWM_STOP_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_CLEARED_16
# error Using BSWM_START_SEC_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_CLEARED_16
# error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_INIT_8
# error Using BSWM_START_SEC_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_INIT_8
# error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_CONST_UNSPECIFIED
# error Using BSWM_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_CONST_UNSPECIFIED
# error Using BSWM_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_NO_INIT_32
# error Using BSWM_START_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_32
# error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_CONST_32
# error Using BSWM_START_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_CONST_32
# error Using BSWM_STOP_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_CLEARED_64
# error Using BSWM_START_SEC_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_CLEARED_64
# error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_INIT_32
# error Using BSWM_START_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_INIT_32
# error Using BSWM_STOP_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_NO_INIT_64
# error Using BSWM_START_SEC_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_NO_INIT_64
# error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_INIT_8
# error Using BSWM_START_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_INIT_8
# error Using BSWM_STOP_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_CLEARED_64
# error Using BSWM_START_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_CLEARED_64
# error Using BSWM_STOP_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NO_INIT_32
# error Using BSWM_START_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NO_INIT_32
# error Using BSWM_STOP_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_INIT_64
# error Using BSWM_START_SEC_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_INIT_64
# error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_CLEARED_32
# error Using BSWM_START_SEC_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_32
# error Using BSWM_STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN
# error Using BSWM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN
# error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN
# error Using BSWM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN
# error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_CLEARED_BOOLEAN
# error Using BSWM_START_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
# error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_CLEARED_BOOLEAN
# error Using BSWM_START_SEC_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_CLEARED_BOOLEAN
# error Using BSWM_STOP_SEC_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NO_INIT_BOOLEAN
# error Using BSWM_START_SEC_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NO_INIT_BOOLEAN
# error Using BSWM_STOP_SEC_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_NO_INIT_64
# error Using BSWM_START_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_64
# error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_CLEARED_32
# error Using BSWM_START_SEC_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_CLEARED_32
# error Using BSWM_STOP_SEC_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using BSWM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_INIT_64
# error Using BSWM_START_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_INIT_64
# error Using BSWM_STOP_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
# error Using BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# error Using BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_INIT_UNSPECIFIED
# error Using BSWM_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_CONST_8
# error Using BSWM_START_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_CONST_8
# error Using BSWM_STOP_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_NO_INIT_32
# error Using BSWM_START_SEC_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_NO_INIT_32
# error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_CLEARED_32
# error Using BSWM_START_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_CLEARED_32
# error Using BSWM_STOP_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using BSWM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_INIT_BOOLEAN
# error Using BSWM_START_SEC_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_INIT_BOOLEAN
# error Using BSWM_STOP_SEC_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using BSWM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# error Using BSWM_START_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# error Using BSWM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_NO_INIT_8
# error Using BSWM_START_SEC_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_NO_INIT_8
# error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_INIT_8
# error Using BSWM_START_SEC_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_INIT_8
# error Using BSWM_STOP_SEC_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_INIT_16
# error Using BSWM_START_SEC_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_INIT_16
# error Using BSWM_STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using BSWM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using BSWM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_INIT_BOOLEAN
# error Using BSWM_START_SEC_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_INIT_BOOLEAN
# error Using BSWM_STOP_SEC_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_FAST_INIT_16
# error Using BSWM_START_SEC_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_FAST_INIT_16
# error Using BSWM_STOP_SEC_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_NO_INIT_8
# error Using BSWM_START_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
# error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_CONST_BOOLEAN
# error Using BSWM_START_SEC_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_CONST_BOOLEAN
# error Using BSWM_STOP_SEC_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_INIT_16
# error Using BSWM_START_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_INIT_16
# error Using BSWM_STOP_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_START_SEC_VAR_NOCACHE_NO_INIT_16
# error Using BSWM_START_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_16
# error Using BSWM_STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BswM_START_SEC_CODE
# error Using BswM_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BswM_STOP_SEC_CODE
# error Using BswM_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BswM_START_SEC_CONST_UNSPECIFIED
# error Using BswM_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BswM_STOP_SEC_CONST_UNSPECIFIED
# error Using BswM_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BswM_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using BswM_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BswM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using BswM_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BswM_START_SEC_VAR_INIT_UNSPECIFIED
# error Using BswM_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BswM_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using BswM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BswM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using BswM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef BswM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using BswM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#ifdef MEMMAP_ERROR
# error No MemMap section found in BswM_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: BswM_MemMap.h
 *********************************************************************************************************************/

/* PRQA S 0883 */ /* MD_MSR_MemMap */

