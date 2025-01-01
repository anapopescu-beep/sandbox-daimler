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
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: MemMap_Compatibility.h
 *   Generation Time: 2023-10-12 12:28:12
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
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

#if defined PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_CLEARED_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_CLEARED_8_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_INIT_16_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_INIT_64_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_CLEARED_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_CLEARED_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_INIT_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_CLEARED_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_CLEARED_64_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_CLEARED_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_CLEARED_16_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NO_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NO_INIT_16_OPEN
#  error Using PDUR_STOP_SEC_VAR_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_CLEARED_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_CLEARED_64_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_CONST_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_CONST_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_CONST_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_CONST_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_CONST_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_CONST_16_OPEN
#  error Using PDUR_STOP_SEC_CONST_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_CONST_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_CLEARED_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_CLEARED_8_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_CODE_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_CODE_OPEN
#  error Using PDUR_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_CLEARED_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_CLEARED_16_OPEN
#  error Using PDUR_STOP_SEC_VAR_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_NO_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_NO_INIT_64_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NO_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NO_INIT_64_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_NO_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_NO_INIT_16_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_INIT_32_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_INIT_32_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_CONST_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_CONST_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_CONST_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_CONST_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_CONST_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_CONST_16_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_CONST_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_CONST_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NO_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NO_INIT_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_CLEARED_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_CLEARED_8_OPEN
#  error Using PDUR_STOP_SEC_VAR_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_CLEARED_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_CLEARED_16_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_CLEARED_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_CLEARED_64_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_CONST_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_CONST_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_CONST_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_CONST_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_CONST_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_CONST_32_OPEN
#  error Using PDUR_STOP_SEC_CONST_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_CONST_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_INIT_32_OPEN
#  error Using PDUR_STOP_SEC_VAR_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_INIT_32_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NO_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NO_INIT_32_OPEN
#  error Using PDUR_STOP_SEC_VAR_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_INIT_32_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_CLEARED_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_CLEARED_16_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_INIT_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_NO_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_NO_INIT_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_CLEARED_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_CLEARED_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_NO_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_NO_INIT_8_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_INIT_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_CLEARED_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_CLEARED_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_INIT_64_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_CLEARED_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_CLEARED_32_OPEN
#  error Using PDUR_STOP_SEC_VAR_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_CLEARED_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_CLEARED_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_INIT_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_INIT_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_VAR_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_INIT_8_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_INIT_8_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_INIT_16_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_CLEARED_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_CLEARED_32_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_CONST_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_CONST_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_CONST_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_CONST_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_CONST_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_CONST_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_CONST_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_INIT_16_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_INIT_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NO_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NO_INIT_16_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_INIT_16_OPEN
#  error Using PDUR_STOP_SEC_VAR_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_NO_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_NO_INIT_64_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_CLEARED_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_CLEARED_8_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_NO_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_NO_INIT_16_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_NO_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_NO_INIT_32_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_CLEARED_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_CLEARED_32_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_CONST_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_CONST_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_CONST_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_CONST_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_CONST_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_CONST_64_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_CONST_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_CONST_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_INIT_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_NO_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_NO_INIT_16_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NO_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NO_INIT_8_OPEN
#  error Using PDUR_STOP_SEC_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_NO_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_NO_INIT_16_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_CONST_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_CONST_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_CONST_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_CONST_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_CONST_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_CONST_64_OPEN
#  error Using PDUR_STOP_SEC_CONST_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_CONST_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_CLEARED_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_CLEARED_16_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_CLEARED_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_CLEARED_8_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NO_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NO_INIT_64_OPEN
#  error Using PDUR_STOP_SEC_VAR_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_CLEARED_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_CLEARED_64_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_CONST_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_CONST_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_CONST_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_CONST_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_CONST_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_CONST_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_CONST_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_INIT_32_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_CLEARED_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_CLEARED_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_CLEARED_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_CLEARED_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_INIT_8_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_INIT_64_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_CLEARED_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_CLEARED_32_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_CONST_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_CONST_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_NO_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_NO_INIT_32_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_CLEARED_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_CLEARED_64_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_NO_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_NO_INIT_64_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_INIT_8_OPEN
#  error Using PDUR_STOP_SEC_VAR_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_CLEARED_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_CLEARED_64_OPEN
#  error Using PDUR_STOP_SEC_VAR_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NO_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NO_INIT_32_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_INIT_64_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_CLEARED_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_CLEARED_32_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_INIT_64_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_CONST_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_CONST_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_CONST_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_CONST_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_CONST_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_CONST_8_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_CONST_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_CONST_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_CLEARED_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_CLEARED_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_VAR_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NO_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NO_INIT_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_VAR_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_NO_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_NO_INIT_64_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_CLEARED_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_CLEARED_32_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_NO_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_NO_INIT_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_INIT_64_OPEN
#  error Using PDUR_STOP_SEC_VAR_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_CONST_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_CONST_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_INIT_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_CONST_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_CONST_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_CONST_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_CONST_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_CONST_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_CONST_8_OPEN
#  error Using PDUR_STOP_SEC_CONST_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_CONST_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_NO_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_NO_INIT_32_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_NO_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_NO_INIT_8_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_NO_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_NO_INIT_32_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NO_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NO_INIT_8_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_CONST_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_CONST_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_CONST_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_CONST_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_CONST_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_CONST_32_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_CONST_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_CONST_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_CLEARED_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_CLEARED_8_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_CLEARED_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_CLEARED_16_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_INIT_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_NO_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_NO_INIT_8_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_NOCACHE_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_NOCACHE_INIT_8_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_NOCACHE_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_INIT_BOOLEAN_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_FAST_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_FAST_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_FAST_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_FAST_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_FAST_INIT_16_OPEN
#  error Using PDUR_STOP_SEC_VAR_FAST_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_FAST_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_VAR_NOCACHE_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_VAR_NOCACHE_NO_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_VAR_NOCACHE_NO_INIT_8_OPEN
#  error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_VAR_NOCACHE_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_INIT_8_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined PDUR_START_SEC_BUFFER_VAR_FAST_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using PDUR_START_SEC_BUFFER_VAR_FAST_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define PDUR_BUFFER_VAR_FAST_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef PDUR_START_SEC_BUFFER_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef PDUR_BUFFER_VAR_FAST_INIT_16_OPEN
#  error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef PDUR_BUFFER_VAR_FAST_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_CODE_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_CODE_OPEN
#  error Using CANIF_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_APPL_CODE_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_APPL_CODE_OPEN
#  error Using CANIF_STOP_SEC_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_PBCFG
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_PBCFG is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_PBCFG_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_PBCFG_CONST/MSR_PBCFG_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_PBCFG
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_PBCFG is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_PBCFG_OPEN
#  error Using CANIF_STOP_SEC_PBCFG is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_PBCFG_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_PBCFG_CONST/MSR_PBCFG_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_CONST_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_CONST_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_CONST_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_CONST_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_CONST_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_CONST_8BIT_OPEN
#  error Using CANIF_STOP_SEC_CONST_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_CONST_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_CONST_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_CONST_16BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_CONST_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_CONST_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_CONST_16BIT_OPEN
#  error Using CANIF_STOP_SEC_CONST_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_CONST_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_CONST_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_CONST_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_CONST_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_CONST_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_CONST_32BIT_OPEN
#  error Using CANIF_STOP_SEC_CONST_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_CONST_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_CONST_UNSPECIFIED_OPEN
#  error Using CANIF_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_CONST_FAST_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_CONST_FAST_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_CONST_FAST_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_CONST_FAST_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_CONST_FAST_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_CONST_FAST_8BIT_OPEN
#  error Using CANIF_STOP_SEC_CONST_FAST_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_CONST_FAST_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_CONST_FAST_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_CONST_FAST_16BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_CONST_FAST_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_CONST_FAST_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_CONST_FAST_16BIT_OPEN
#  error Using CANIF_STOP_SEC_CONST_FAST_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_CONST_FAST_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_CONST_FAST_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_CONST_FAST_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_CONST_FAST_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_CONST_FAST_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_CONST_FAST_32BIT_OPEN
#  error Using CANIF_STOP_SEC_CONST_FAST_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_CONST_FAST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_CONST_FAST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_CONST_FAST_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_CONST_FAST_UNSPECIFIED_OPEN
#  error Using CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_PBCFG
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_PBCFG is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_PBCFG_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_PBCFG_VAR/MSR_PBCFG_VAR */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_PBCFG
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_PBCFG is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_PBCFG_OPEN
#  error Using CANIF_STOP_SEC_VAR_PBCFG is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_PBCFG_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_PBCFG_VAR/MSR_PBCFG_VAR */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_NOINIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_NOINIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_NOINIT_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_NOINIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_NOINIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_NOINIT_8BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_NOINIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_NOINIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_NOINIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_NOINIT_16BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_NOINIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_NOINIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_NOINIT_16BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_NOINIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_NOINIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_NOINIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_NOINIT_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_NOINIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_NOINIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_NOINIT_32BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_NOINIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_NOINIT_64BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_NOINIT_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_NOINIT_64BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_NOINIT_64BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_NOINIT_64BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_NOINIT_64BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_NOINIT_64BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_NOINIT_64BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_NOINIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_INIT_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_INIT_8BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_INIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_INIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_INIT_16BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_INIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_INIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_INIT_16BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_INIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_INIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_INIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_INIT_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_INIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_INIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_INIT_32BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_INIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_INIT_UNSPECIFIED_OPEN
#  error Using CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_ZERO_INIT_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_ZERO_INIT_8BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_ZERO_INIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_ZERO_INIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_ZERO_INIT_16BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_ZERO_INIT_16BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_ZERO_INIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_ZERO_INIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_ZERO_INIT_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_ZERO_INIT_32BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_ZERO_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Using CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_FAST_NOINIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_FAST_NOINIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_FAST_NOINIT_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_FAST_NOINIT_8BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_FAST_NOINIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_FAST_NOINIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_FAST_NOINIT_16BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_FAST_NOINIT_16BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_FAST_NOINIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_FAST_NOINIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_FAST_NOINIT_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_FAST_NOINIT_32BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_FAST_NOINIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_FAST_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_FAST_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_FAST_INIT_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_FAST_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_FAST_INIT_8BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_FAST_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_FAST_INIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_FAST_INIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_FAST_INIT_16BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_FAST_INIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_INIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_FAST_INIT_16BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_INIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_FAST_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_FAST_INIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_FAST_INIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_FAST_INIT_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_FAST_INIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_INIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_FAST_INIT_32BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_INIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_FAST_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_FAST_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_FAST_INIT_UNSPECIFIED_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_FAST_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_FAST_ZERO_INIT_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_FAST_ZERO_INIT_16BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_FAST_ZERO_INIT_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CANIF_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CANIF_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Using CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CANIF_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DET_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using DET_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DET_CODE_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef DET_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DET_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using DET_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DET_CODE_OPEN
#  error Using DET_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef DET_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore

# undef DET_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DET_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DET_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DET_CONST_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef DET_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DET_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DET_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DET_CONST_UNSPECIFIED_OPEN
#  error Using DET_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DET_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef DET_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DET_START_SEC_VAR_NOINIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using DET_START_SEC_VAR_NOINIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DET_VAR_NOINIT_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef DET_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DET_STOP_SEC_VAR_NOINIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using DET_STOP_SEC_VAR_NOINIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DET_VAR_NOINIT_8BIT_OPEN
#  error Using DET_STOP_SEC_VAR_NOINIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef DET_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef DET_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DET_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DET_VAR_NOINIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef DET_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DET_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DET_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DET_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DET_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DET_VAR_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef DET_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DET_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DET_VAR_INIT_UNSPECIFIED_OPEN
#  error Using DET_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DET_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef DET_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined Det_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using Det_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define Det_CODE_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef Det_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined Det_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using Det_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef Det_CODE_OPEN
#  error Using Det_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef Det_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore

# undef Det_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_SAVED_ZONE0_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_SAVED_ZONE0_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_SAVED_ZONE0_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_SAVED_ZONE0_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_SAVED_ZONE0_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_SAVED_ZONE0_8_OPEN
#  error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_SAVED_ZONE0_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_SAVED_ZONE0_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_INIT_64_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_CLEARED_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_CLEARED_UNSPECIFIED_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NO_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NO_INIT_8_OPEN
#  error Using COMM_STOP_SEC_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_CLEARED_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_CLEARED_16_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NO_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NO_INIT_16_OPEN
#  error Using COMM_STOP_SEC_VAR_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_SAVED_ZONE0_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_SAVED_ZONE0_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_SAVED_ZONE0_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_SAVED_ZONE0_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_SAVED_ZONE0_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_SAVED_ZONE0_16_OPEN
#  error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_SAVED_ZONE0_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_SAVED_ZONE0_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_CONST_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_CONST_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_CONST_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_CONST_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_CONST_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_CONST_16_OPEN
#  error Using COMM_STOP_SEC_CONST_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_CONST_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_SAVED_ZONE0_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_SAVED_ZONE0_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_SAVED_ZONE0_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_SAVED_ZONE0_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_SAVED_ZONE0_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_SAVED_ZONE0_BOOLEAN_OPEN
#  error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_SAVED_ZONE0_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_SAVED_ZONE0_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_CLEARED_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_CLEARED_8_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_CODE_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_CODE_OPEN
#  error Using COMM_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_SAVED_ZONE0_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_SAVED_ZONE0_8_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_SAVED_ZONE0_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_CONST_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_CONST_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_CONST_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_CONST_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_CONST_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_CONST_64_OPEN
#  error Using COMM_STOP_SEC_CONST_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_CONST_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_CLEARED_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_CLEARED_8_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_CLEARED_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_CLEARED_16_OPEN
#  error Using COMM_STOP_SEC_VAR_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_NO_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_NO_INIT_16_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NO_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NO_INIT_64_OPEN
#  error Using COMM_STOP_SEC_VAR_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_CLEARED_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_CLEARED_64_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_INIT_32_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_INIT_32_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_SAVED_ZONE0_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_SAVED_ZONE0_16_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_SAVED_ZONE0_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_CLEARED_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_CLEARED_8_OPEN
#  error Using COMM_STOP_SEC_VAR_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_CLEARED_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_CLEARED_16_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_INIT_8_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_CONST_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_CONST_UNSPECIFIED_OPEN
#  error Using COMM_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_NO_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_NO_INIT_32_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_CONST_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_CONST_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_CONST_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_CONST_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_CONST_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_CONST_32_OPEN
#  error Using COMM_STOP_SEC_CONST_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_CONST_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_CLEARED_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_CLEARED_64_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_INIT_32_OPEN
#  error Using COMM_STOP_SEC_VAR_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_NO_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_NO_INIT_64_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_INIT_8_OPEN
#  error Using COMM_STOP_SEC_VAR_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_CLEARED_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_CLEARED_64_OPEN
#  error Using COMM_STOP_SEC_VAR_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NO_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NO_INIT_32_OPEN
#  error Using COMM_STOP_SEC_VAR_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_INIT_64_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_CLEARED_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_CLEARED_32_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_INIT_BOOLEAN_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_NO_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_NO_INIT_BOOLEAN_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_SAVED_ZONE0_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_SAVED_ZONE0_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_SAVED_ZONE0_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_SAVED_ZONE0_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_SAVED_ZONE0_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_SAVED_ZONE0_32_OPEN
#  error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_SAVED_ZONE0_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_SAVED_ZONE0_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_CLEARED_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_CLEARED_BOOLEAN_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_SAVED_ZONE0_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_SAVED_ZONE0_UNSPECIFIED_OPEN
#  error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_SAVED_ZONE0_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_CLEARED_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_CLEARED_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_CLEARED_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_CLEARED_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_CLEARED_BOOLEAN_OPEN
#  error Using COMM_STOP_SEC_VAR_CLEARED_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_CLEARED_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_CLEARED_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_SAVED_ZONE0_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_SAVED_ZONE0_64_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_SAVED_ZONE0_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NO_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NO_INIT_BOOLEAN_OPEN
#  error Using COMM_STOP_SEC_VAR_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_NO_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_NO_INIT_64_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_CLEARED_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_CLEARED_32_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_INIT_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_INIT_64_OPEN
#  error Using COMM_STOP_SEC_VAR_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_CLEARED_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_CLEARED_UNSPECIFIED_OPEN
#  error Using COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_INIT_UNSPECIFIED_OPEN
#  error Using COMM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_CONST_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_CONST_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_CONST_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_CONST_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_CONST_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_CONST_8_OPEN
#  error Using COMM_STOP_SEC_CONST_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_CONST_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_NO_INIT_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_NO_INIT_32_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_CLEARED_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_CLEARED_32_OPEN
#  error Using COMM_STOP_SEC_VAR_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_NO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_INIT_BOOLEAN_OPEN
#  error Using COMM_STOP_SEC_VAR_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_INIT_UNSPECIFIED_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_NO_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_NO_INIT_8_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_INIT_8_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_INIT_16_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_SAVED_ZONE0_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_SAVED_ZONE0_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_SAVED_ZONE0_64_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_SAVED_ZONE0_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_SAVED_ZONE0_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_SAVED_ZONE0_64_OPEN
#  error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_SAVED_ZONE0_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_SAVED_ZONE0_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_INIT_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_INIT_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_INIT_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_INIT_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_INIT_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_INIT_BOOLEAN_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_INIT_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_FAST_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_FAST_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_FAST_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_FAST_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_FAST_INIT_16_OPEN
#  error Using COMM_STOP_SEC_VAR_FAST_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_FAST_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_NO_INIT_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_NO_INIT_8_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_CONST_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_CONST_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_CONST_BOOLEAN_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_CONST_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_CONST_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_CONST_BOOLEAN_OPEN
#  error Using COMM_STOP_SEC_CONST_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_SAVED_ZONE0_32_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_SAVED_ZONE0_32_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_SAVED_ZONE0_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_SAVED_ZONE/MSR_VAR_SAVED_ZONE */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_INIT_16_OPEN
#  error Using COMM_STOP_SEC_VAR_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_INIT/MSR_VAR_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined COMM_START_SEC_VAR_NOCACHE_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using COMM_START_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define COMM_VAR_NOCACHE_NO_INIT_16_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef COMM_START_SEC_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef COMM_VAR_NOCACHE_NO_INIT_16_OPEN
#  error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef COMM_VAR_NOCACHE_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_LIBCV_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_LIBCV_CODE_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CRYPTO_30_LIBCV_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_LIBCV_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_LIBCV_CODE_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_LIBCV_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore

# undef CRYPTO_30_LIBCV_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_START_SEC_CONST_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_LIBCV_CONST_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CRYPTO_30_LIBCV_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_LIBCV_CONST_8BIT_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_LIBCV_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_LIBCV_START_SEC_CONST_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_START_SEC_CONST_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_LIBCV_CONST_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CRYPTO_30_LIBCV_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_LIBCV_STOP_SEC_CONST_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_CONST_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_LIBCV_CONST_32BIT_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_CONST_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_LIBCV_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef CRYPTO_30_LIBCV_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_LIBCV_CONST_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_LIBCV_CONST_UNSPECIFIED_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_LIBCV_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_LIBCV_VAR_NOINIT_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_LIBCV_VAR_NOINIT_8BIT_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_LIBCV_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_LIBCV_VAR_NOINIT_16BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_LIBCV_VAR_NOINIT_16BIT_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_LIBCV_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_LIBCV_VAR_NOINIT_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_LIBCV_VAR_NOINIT_32BIT_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_LIBCV_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_LIBCV_VAR_NOINIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_LIBCV_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_LIBCV_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_NO_INIT/MSR_VAR_NO_INIT */
# pragma section nearrom restore
# pragma section farrom restore

# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_LIBCV_START_SEC_VAR_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_START_SEC_VAR_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_LIBCV_VAR_ZERO_INIT_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef CRYPTO_30_LIBCV_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_LIBCV_VAR_ZERO_INIT_8BIT_OPEN
#  error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_LIBCV_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma section nearrom restore
# pragma section farrom restore

# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VSECPRIM_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using VSECPRIM_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VSECPRIM_CODE_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef VSECPRIM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VSECPRIM_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using VSECPRIM_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VSECPRIM_CODE_OPEN
#  error Using VSECPRIM_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef VSECPRIM_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore

# undef VSECPRIM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VSECPRIM_START_SEC_CONST_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using VSECPRIM_START_SEC_CONST_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VSECPRIM_CONST_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef VSECPRIM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VSECPRIM_STOP_SEC_CONST_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using VSECPRIM_STOP_SEC_CONST_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VSECPRIM_CONST_8BIT_OPEN
#  error Using VSECPRIM_STOP_SEC_CONST_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VSECPRIM_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef VSECPRIM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VSECPRIM_START_SEC_CONST_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using VSECPRIM_START_SEC_CONST_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VSECPRIM_CONST_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef VSECPRIM_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VSECPRIM_STOP_SEC_CONST_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using VSECPRIM_STOP_SEC_CONST_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VSECPRIM_CONST_32BIT_OPEN
#  error Using VSECPRIM_STOP_SEC_CONST_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VSECPRIM_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef VSECPRIM_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VSECPRIM_START_SEC_CONST_64BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using VSECPRIM_START_SEC_CONST_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VSECPRIM_CONST_64BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef VSECPRIM_START_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VSECPRIM_STOP_SEC_CONST_64BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using VSECPRIM_STOP_SEC_CONST_64BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VSECPRIM_CONST_64BIT_OPEN
#  error Using VSECPRIM_STOP_SEC_CONST_64BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VSECPRIM_CONST_64BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef VSECPRIM_STOP_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined VSECPRIM_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using VSECPRIM_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VSECPRIM_CONST_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef VSECPRIM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using VSECPRIM_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VSECPRIM_CONST_UNSPECIFIED_OPEN
#  error Using VSECPRIM_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VSECPRIM_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section nearrom restore
# pragma section farrom restore

# undef VSECPRIM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_VHSM_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_VHSM_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_VHSM_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_VHSM_CODE_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_VHSM_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_VHSM_START_SEC_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_START_SEC_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_VHSM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_VHSM_STOP_SEC_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_VHSM_APPL_CODE_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_VHSM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_VHSM_START_SEC_CODE_ISR
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_START_SEC_CODE_ISR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_VHSM_CODE_ISR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_VHSM_STOP_SEC_CODE_ISR
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_CODE_ISR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_VHSM_CODE_ISR_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_CODE_ISR is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_VHSM_CODE_ISR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_VHSM_START_SEC_RAMCODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_START_SEC_RAMCODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_VHSM_RAMCODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_START_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_VHSM_STOP_SEC_RAMCODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_RAMCODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_VHSM_RAMCODE_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_RAMCODE is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_VHSM_RAMCODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_STOP_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_VHSM_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_VHSM_CONST_UNSPECIFIED_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_VHSM_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_VHSM_IPC_MEMORY_VAR_NOINIT_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/vHsmIpcMemory/vHsmIpcMemory */
#pragma section all "vHsmIpcMemory"

# undef CRYPTO_30_VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_VHSM_IPC_MEMORY_VAR_NOINIT_32BIT_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_VHSM_IPC_MEMORY_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/vHsmIpcMemory/vHsmIpcMemory */
#pragma section all restore

# undef CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_VHSM_GLOBAL_VAR_NOINIT_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/vHsmGlobalRamBuffer/vHsmGlobalRamBuffer */
#pragma section all "vHsmGlobalRamBuffer"

# undef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_VHSM_GLOBAL_VAR_NOINIT_32BIT_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_VHSM_GLOBAL_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/vHsmGlobalRamBuffer/vHsmGlobalRamBuffer */
#pragma section all restore

# undef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_VHSM_GLOBAL_VAR_NOINIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/vHsmGlobalRamBuffer/vHsmGlobalRamBuffer */
#pragma section all "vHsmGlobalRamBuffer"

# undef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_VHSM_GLOBAL_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_VHSM_GLOBAL_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/vHsmGlobalRamBuffer/vHsmGlobalRamBuffer */
#pragma section all restore

# undef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_VHSM_VAR_NOINIT_8BIT_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_VHSM_VAR_NOINIT_8BIT_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_VHSM_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_VHSM_VAR_NOINIT_32BIT_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_VHSM_VAR_NOINIT_32BIT_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_VHSM_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_VHSM_VAR_NOINIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_VHSM_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_VHSM_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_30_VHSM_START_SEC_VAR_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_START_SEC_VAR_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_30_VHSM_VAR_ZERO_INIT_8BIT_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_30_VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_30_VHSM_VAR_ZERO_INIT_8BIT_OPEN
#  error Using CRYPTO_30_VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_30_VHSM_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_30_VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_8
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_8
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using PDUR_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_16
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_16
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_INIT_64
# error Using PDUR_START_SEC_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_INIT_64
# error Using PDUR_STOP_SEC_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# error Using PDUR_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_INIT_BOOLEAN
# error Using PDUR_START_SEC_BUFFER_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_INIT_BOOLEAN
# error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_64
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_64
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_CLEARED_16
# error Using PDUR_START_SEC_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_16
# error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NO_INIT_16
# error Using PDUR_START_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NO_INIT_16
# error Using PDUR_STOP_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_64
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_64
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_CONST_16
# error Using PDUR_START_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_CONST_16
# error Using PDUR_STOP_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_CLEARED_8
# error Using PDUR_START_SEC_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_CLEARED_8
# error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_CODE
# error Using PDUR_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_CODE
# error Using PDUR_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_CLEARED_16
# error Using PDUR_START_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_CLEARED_16
# error Using PDUR_STOP_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_64
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_64
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NO_INIT_64
# error Using PDUR_START_SEC_BUFFER_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_64
# error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_NO_INIT_16
# error Using PDUR_START_SEC_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_NO_INIT_16
# error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_INIT_32
# error Using PDUR_START_SEC_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_INIT_32
# error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_INIT_32
# error Using PDUR_START_SEC_BUFFER_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_INIT_32
# error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_CONST_16
# error Using PDUR_START_SEC_BUFFER_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_CONST_16
# error Using PDUR_STOP_SEC_BUFFER_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NO_INIT_BOOLEAN
# error Using PDUR_START_SEC_BUFFER_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_BOOLEAN
# error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_CLEARED_8
# error Using PDUR_START_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_CLEARED_8
# error Using PDUR_STOP_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_CLEARED_16
# error Using PDUR_START_SEC_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_CLEARED_16
# error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_CLEARED_64
# error Using PDUR_START_SEC_BUFFER_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_CLEARED_64
# error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_CONST_32
# error Using PDUR_START_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_CONST_32
# error Using PDUR_STOP_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_INIT_32
# error Using PDUR_START_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_INIT_32
# error Using PDUR_STOP_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_INIT_32
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_32
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NO_INIT_32
# error Using PDUR_START_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NO_INIT_32
# error Using PDUR_STOP_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_32
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_32
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_CLEARED_16
# error Using PDUR_START_SEC_BUFFER_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_CLEARED_16
# error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_INIT_BOOLEAN
# error Using PDUR_START_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN
# error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_NO_INIT_BOOLEAN
# error Using PDUR_START_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN
# error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_CLEARED_BOOLEAN
# error Using PDUR_START_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
# error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_8
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_8
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_INIT_UNSPECIFIED
# error Using PDUR_START_SEC_BUFFER_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_INIT_UNSPECIFIED
# error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED
# error Using PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# error Using PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_INIT_64
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_64
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_CLEARED_32
# error Using PDUR_START_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_CLEARED_32
# error Using PDUR_STOP_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_CLEARED_UNSPECIFIED
# error Using PDUR_START_SEC_BUFFER_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_CLEARED_UNSPECIFIED
# error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_INIT_UNSPECIFIED
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_UNSPECIFIED
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_INIT_BOOLEAN
# error Using PDUR_START_SEC_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_INIT_BOOLEAN
# error Using PDUR_STOP_SEC_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using PDUR_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_INIT_8
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_8
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_INIT_8
# error Using PDUR_START_SEC_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_INIT_8
# error Using PDUR_STOP_SEC_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_INIT_16
# error Using PDUR_START_SEC_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_INIT_16
# error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_32
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_32
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_CONST_BOOLEAN
# error Using PDUR_START_SEC_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_CONST_BOOLEAN
# error Using PDUR_STOP_SEC_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_INIT_16
# error Using PDUR_START_SEC_BUFFER_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_INIT_16
# error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_BOOLEAN
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_BOOLEAN
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NO_INIT_16
# error Using PDUR_START_SEC_BUFFER_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_16
# error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_INIT_16
# error Using PDUR_START_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_INIT_16
# error Using PDUR_STOP_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_64
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_64
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_8
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_8
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_NO_INIT_16
# error Using PDUR_START_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_16
# error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_32
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_32
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_CLEARED_32
# error Using PDUR_START_SEC_BUFFER_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_CLEARED_32
# error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_CONST_64
# error Using PDUR_START_SEC_BUFFER_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_CONST_64
# error Using PDUR_STOP_SEC_BUFFER_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_INIT_BOOLEAN
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_BOOLEAN
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_16
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_16
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NO_INIT_8
# error Using PDUR_START_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NO_INIT_8
# error Using PDUR_STOP_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_16
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_16
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_CONST_64
# error Using PDUR_START_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_CONST_64
# error Using PDUR_STOP_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_16
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_16
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_CLEARED_8
# error Using PDUR_START_SEC_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_8
# error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using PDUR_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NO_INIT_64
# error Using PDUR_START_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NO_INIT_64
# error Using PDUR_STOP_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_CLEARED_64
# error Using PDUR_START_SEC_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_64
# error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_CONST_BOOLEAN
# error Using PDUR_START_SEC_BUFFER_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_CONST_BOOLEAN
# error Using PDUR_STOP_SEC_BUFFER_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_INIT_32
# error Using PDUR_START_SEC_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_INIT_32
# error Using PDUR_STOP_SEC_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_CLEARED_BOOLEAN
# error Using PDUR_START_SEC_BUFFER_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_CLEARED_BOOLEAN
# error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_BOOLEAN
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_BOOLEAN
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NO_INIT_UNSPECIFIED
# error Using PDUR_START_SEC_BUFFER_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_UNSPECIFIED
# error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_INIT_8
# error Using PDUR_START_SEC_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_INIT_8
# error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_64
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_64
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_32
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_32
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_CONST_UNSPECIFIED
# error Using PDUR_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_CONST_UNSPECIFIED
# error Using PDUR_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_NO_INIT_32
# error Using PDUR_START_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_32
# error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_CLEARED_64
# error Using PDUR_START_SEC_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_CLEARED_64
# error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_NO_INIT_64
# error Using PDUR_START_SEC_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_NO_INIT_64
# error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_INIT_8
# error Using PDUR_START_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_INIT_8
# error Using PDUR_STOP_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_CLEARED_64
# error Using PDUR_START_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_CLEARED_64
# error Using PDUR_STOP_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NO_INIT_32
# error Using PDUR_START_SEC_BUFFER_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_32
# error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_INIT_64
# error Using PDUR_START_SEC_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_INIT_64
# error Using PDUR_STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_CLEARED_32
# error Using PDUR_START_SEC_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_32
# error Using PDUR_STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_INIT_64
# error Using PDUR_START_SEC_BUFFER_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_INIT_64
# error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_CONST_8
# error Using PDUR_START_SEC_BUFFER_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_CONST_8
# error Using PDUR_STOP_SEC_BUFFER_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_CLEARED_BOOLEAN
# error Using PDUR_START_SEC_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_CLEARED_BOOLEAN
# error Using PDUR_STOP_SEC_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NO_INIT_BOOLEAN
# error Using PDUR_START_SEC_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NO_INIT_BOOLEAN
# error Using PDUR_STOP_SEC_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_NO_INIT_64
# error Using PDUR_START_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_64
# error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_CLEARED_32
# error Using PDUR_START_SEC_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_CLEARED_32
# error Using PDUR_STOP_SEC_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_BOOLEAN
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_BOOLEAN
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using PDUR_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_INIT_64
# error Using PDUR_START_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_INIT_64
# error Using PDUR_STOP_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_CONST_UNSPECIFIED
# error Using PDUR_START_SEC_BUFFER_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_CONST_UNSPECIFIED
# error Using PDUR_STOP_SEC_BUFFER_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_INIT_UNSPECIFIED
# error Using PDUR_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using PDUR_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_CONST_8
# error Using PDUR_START_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_CONST_8
# error Using PDUR_STOP_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_NO_INIT_32
# error Using PDUR_START_SEC_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_NO_INIT_32
# error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_8
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_8
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using PDUR_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_32
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_32
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NO_INIT_8
# error Using PDUR_START_SEC_BUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_8
# error Using PDUR_STOP_SEC_BUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_CONST_32
# error Using PDUR_START_SEC_BUFFER_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_CONST_32
# error Using PDUR_STOP_SEC_BUFFER_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_CLEARED_8
# error Using PDUR_START_SEC_BUFFER_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_CLEARED_8
# error Using PDUR_STOP_SEC_BUFFER_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_16
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_16
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# error Using PDUR_START_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# error Using PDUR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_NO_INIT_8
# error Using PDUR_START_SEC_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_NO_INIT_8
# error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using PDUR_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using PDUR_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_8
# error Using PDUR_START_SEC_BUFFER_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_8
# error Using PDUR_STOP_SEC_BUFFER_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_INIT_BOOLEAN
# error Using PDUR_START_SEC_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_INIT_BOOLEAN
# error Using PDUR_STOP_SEC_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_FAST_INIT_16
# error Using PDUR_START_SEC_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_FAST_INIT_16
# error Using PDUR_STOP_SEC_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_VAR_NOCACHE_NO_INIT_8
# error Using PDUR_START_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_8
# error Using PDUR_STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_INIT_8
# error Using PDUR_START_SEC_BUFFER_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_INIT_8
# error Using PDUR_STOP_SEC_BUFFER_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_START_SEC_BUFFER_VAR_FAST_INIT_16
# error Using PDUR_START_SEC_BUFFER_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_16
# error Using PDUR_STOP_SEC_BUFFER_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_CODE
# error Using CANIF_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_CODE
# error Using CANIF_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_APPL_CODE
# error Using CANIF_START_SEC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_APPL_CODE
# error Using CANIF_STOP_SEC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_PBCFG
# error Using CANIF_START_SEC_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_PBCFG
# error Using CANIF_STOP_SEC_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_CONST_8BIT
# error Using CANIF_START_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_CONST_8BIT
# error Using CANIF_STOP_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_CONST_16BIT
# error Using CANIF_START_SEC_CONST_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_CONST_16BIT
# error Using CANIF_STOP_SEC_CONST_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_CONST_32BIT
# error Using CANIF_START_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_CONST_32BIT
# error Using CANIF_STOP_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_CONST_UNSPECIFIED
# error Using CANIF_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_CONST_UNSPECIFIED
# error Using CANIF_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_CONST_FAST_8BIT
# error Using CANIF_START_SEC_CONST_FAST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_CONST_FAST_8BIT
# error Using CANIF_STOP_SEC_CONST_FAST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_CONST_FAST_16BIT
# error Using CANIF_START_SEC_CONST_FAST_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_CONST_FAST_16BIT
# error Using CANIF_STOP_SEC_CONST_FAST_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_CONST_FAST_32BIT
# error Using CANIF_START_SEC_CONST_FAST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_CONST_FAST_32BIT
# error Using CANIF_STOP_SEC_CONST_FAST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_CONST_FAST_UNSPECIFIED
# error Using CANIF_START_SEC_CONST_FAST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED
# error Using CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_PBCFG
# error Using CANIF_START_SEC_VAR_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_PBCFG
# error Using CANIF_STOP_SEC_VAR_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_NOINIT_8BIT
# error Using CANIF_START_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_NOINIT_8BIT
# error Using CANIF_STOP_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_NOINIT_16BIT
# error Using CANIF_START_SEC_VAR_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_NOINIT_16BIT
# error Using CANIF_STOP_SEC_VAR_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_NOINIT_32BIT
# error Using CANIF_START_SEC_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_NOINIT_32BIT
# error Using CANIF_STOP_SEC_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_NOINIT_64BIT
# error Using CANIF_START_SEC_VAR_NOINIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_NOINIT_64BIT
# error Using CANIF_STOP_SEC_VAR_NOINIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_INIT_8BIT
# error Using CANIF_START_SEC_VAR_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_INIT_8BIT
# error Using CANIF_STOP_SEC_VAR_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_INIT_16BIT
# error Using CANIF_START_SEC_VAR_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_INIT_16BIT
# error Using CANIF_STOP_SEC_VAR_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_INIT_32BIT
# error Using CANIF_START_SEC_VAR_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_INIT_32BIT
# error Using CANIF_STOP_SEC_VAR_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_INIT_UNSPECIFIED
# error Using CANIF_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_ZERO_INIT_8BIT
# error Using CANIF_START_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# error Using CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_ZERO_INIT_16BIT
# error Using CANIF_START_SEC_VAR_ZERO_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT
# error Using CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_ZERO_INIT_32BIT
# error Using CANIF_START_SEC_VAR_ZERO_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT
# error Using CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_FAST_NOINIT_8BIT
# error Using CANIF_START_SEC_VAR_FAST_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT
# error Using CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_FAST_NOINIT_16BIT
# error Using CANIF_START_SEC_VAR_FAST_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT
# error Using CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_FAST_NOINIT_32BIT
# error Using CANIF_START_SEC_VAR_FAST_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT
# error Using CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# error Using CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# error Using CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_FAST_INIT_8BIT
# error Using CANIF_START_SEC_VAR_FAST_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_INIT_8BIT
# error Using CANIF_STOP_SEC_VAR_FAST_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_FAST_INIT_16BIT
# error Using CANIF_START_SEC_VAR_FAST_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_INIT_16BIT
# error Using CANIF_STOP_SEC_VAR_FAST_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_FAST_INIT_32BIT
# error Using CANIF_START_SEC_VAR_FAST_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_INIT_32BIT
# error Using CANIF_STOP_SEC_VAR_FAST_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# error Using CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# error Using CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# error Using CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# error Using CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# error Using CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# error Using CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# error Using CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# error Using CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# error Using CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# error Using CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DET_START_SEC_CODE
# error Using DET_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DET_STOP_SEC_CODE
# error Using DET_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DET_START_SEC_CONST_UNSPECIFIED
# error Using DET_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DET_STOP_SEC_CONST_UNSPECIFIED
# error Using DET_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DET_START_SEC_VAR_NOINIT_8BIT
# error Using DET_START_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_8BIT
# error Using DET_STOP_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using DET_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DET_START_SEC_VAR_INIT_UNSPECIFIED
# error Using DET_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using DET_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef Det_START_SEC_CODE
# error Using Det_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef Det_STOP_SEC_CODE
# error Using Det_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_SAVED_ZONE0_8
# error Using COMM_START_SEC_VAR_SAVED_ZONE0_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_SAVED_ZONE0_8
# error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using COMM_START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_INIT_64
# error Using COMM_START_SEC_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_INIT_64
# error Using COMM_STOP_SEC_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# error Using COMM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# error Using COMM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NO_INIT_8
# error Using COMM_START_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NO_INIT_8
# error Using COMM_STOP_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_CLEARED_16
# error Using COMM_START_SEC_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_CLEARED_16
# error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NO_INIT_16
# error Using COMM_START_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NO_INIT_16
# error Using COMM_STOP_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_SAVED_ZONE0_16
# error Using COMM_START_SEC_VAR_SAVED_ZONE0_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_SAVED_ZONE0_16
# error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_CONST_16
# error Using COMM_START_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_CONST_16
# error Using COMM_STOP_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_SAVED_ZONE0_BOOLEAN
# error Using COMM_START_SEC_VAR_SAVED_ZONE0_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_SAVED_ZONE0_BOOLEAN
# error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_CLEARED_8
# error Using COMM_START_SEC_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_CLEARED_8
# error Using COMM_STOP_SEC_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_CODE
# error Using COMM_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_CODE
# error Using COMM_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_8
# error Using COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_8
# error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_CONST_64
# error Using COMM_START_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_CONST_64
# error Using COMM_STOP_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_CLEARED_8
# error Using COMM_START_SEC_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_CLEARED_8
# error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_CLEARED_16
# error Using COMM_START_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_CLEARED_16
# error Using COMM_STOP_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using COMM_START_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN
# error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_NO_INIT_16
# error Using COMM_START_SEC_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_NO_INIT_16
# error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NO_INIT_64
# error Using COMM_START_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NO_INIT_64
# error Using COMM_STOP_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_CLEARED_64
# error Using COMM_START_SEC_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_CLEARED_64
# error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_INIT_32
# error Using COMM_START_SEC_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_INIT_32
# error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_INIT_32
# error Using COMM_START_SEC_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_INIT_32
# error Using COMM_STOP_SEC_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_16
# error Using COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_16
# error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_CLEARED_8
# error Using COMM_START_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_CLEARED_8
# error Using COMM_STOP_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_CLEARED_16
# error Using COMM_START_SEC_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_CLEARED_16
# error Using COMM_STOP_SEC_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_INIT_8
# error Using COMM_START_SEC_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_INIT_8
# error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_CONST_UNSPECIFIED
# error Using COMM_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_CONST_UNSPECIFIED
# error Using COMM_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_NO_INIT_32
# error Using COMM_START_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_32
# error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_CONST_32
# error Using COMM_START_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_CONST_32
# error Using COMM_STOP_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_CLEARED_64
# error Using COMM_START_SEC_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_CLEARED_64
# error Using COMM_STOP_SEC_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_INIT_32
# error Using COMM_START_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_INIT_32
# error Using COMM_STOP_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_NO_INIT_64
# error Using COMM_START_SEC_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_NO_INIT_64
# error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_INIT_8
# error Using COMM_START_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_INIT_8
# error Using COMM_STOP_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_CLEARED_64
# error Using COMM_START_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_CLEARED_64
# error Using COMM_STOP_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NO_INIT_32
# error Using COMM_START_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NO_INIT_32
# error Using COMM_STOP_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_INIT_64
# error Using COMM_START_SEC_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_INIT_64
# error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_CLEARED_32
# error Using COMM_START_SEC_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_CLEARED_32
# error Using COMM_STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN
# error Using COMM_START_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN
# error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN
# error Using COMM_START_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN
# error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_SAVED_ZONE0_32
# error Using COMM_START_SEC_VAR_SAVED_ZONE0_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_SAVED_ZONE0_32
# error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_CLEARED_BOOLEAN
# error Using COMM_START_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN
# error Using COMM_STOP_SEC_VAR_FAST_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# error Using COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_CLEARED_BOOLEAN
# error Using COMM_START_SEC_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
# error Using COMM_STOP_SEC_VAR_CLEARED_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_64
# error Using COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_64
# error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NO_INIT_BOOLEAN
# error Using COMM_START_SEC_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NO_INIT_BOOLEAN
# error Using COMM_STOP_SEC_VAR_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_NO_INIT_64
# error Using COMM_START_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_64
# error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_CLEARED_32
# error Using COMM_START_SEC_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_CLEARED_32
# error Using COMM_STOP_SEC_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using COMM_START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_INIT_64
# error Using COMM_START_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_INIT_64
# error Using COMM_STOP_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN
# error Using COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN
# error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_CLEARED_UNSPECIFIED
# error Using COMM_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# error Using COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_INIT_UNSPECIFIED
# error Using COMM_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using COMM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_CONST_8
# error Using COMM_START_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_CONST_8
# error Using COMM_STOP_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED
# error Using COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED
# error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_NO_INIT_32
# error Using COMM_START_SEC_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_NO_INIT_32
# error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_CLEARED_32
# error Using COMM_START_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_CLEARED_32
# error Using COMM_STOP_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using COMM_START_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN
# error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_INIT_BOOLEAN
# error Using COMM_START_SEC_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_INIT_BOOLEAN
# error Using COMM_STOP_SEC_VAR_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using COMM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# error Using COMM_START_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# error Using COMM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_NO_INIT_8
# error Using COMM_START_SEC_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_NO_INIT_8
# error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_INIT_8
# error Using COMM_START_SEC_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_INIT_8
# error Using COMM_STOP_SEC_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_INIT_16
# error Using COMM_START_SEC_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_INIT_16
# error Using COMM_STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using COMM_START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using COMM_STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_SAVED_ZONE0_64
# error Using COMM_START_SEC_VAR_SAVED_ZONE0_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_SAVED_ZONE0_64
# error Using COMM_STOP_SEC_VAR_SAVED_ZONE0_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_INIT_BOOLEAN
# error Using COMM_START_SEC_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_INIT_BOOLEAN
# error Using COMM_STOP_SEC_VAR_FAST_INIT_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_FAST_INIT_16
# error Using COMM_START_SEC_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_FAST_INIT_16
# error Using COMM_STOP_SEC_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_NO_INIT_8
# error Using COMM_START_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
# error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_CONST_BOOLEAN
# error Using COMM_START_SEC_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_CONST_BOOLEAN
# error Using COMM_STOP_SEC_CONST_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_32
# error Using COMM_START_SEC_VAR_NOCACHE_SAVED_ZONE0_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_32
# error Using COMM_STOP_SEC_VAR_NOCACHE_SAVED_ZONE0_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_INIT_16
# error Using COMM_START_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_INIT_16
# error Using COMM_STOP_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_START_SEC_VAR_NOCACHE_NO_INIT_16
# error Using COMM_START_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_16
# error Using COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_START_SEC_CODE
# error Using CRYPTO_30_LIBCV_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_CODE
# error Using CRYPTO_30_LIBCV_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
# error Using CRYPTO_30_LIBCV_START_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
# error Using CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_START_SEC_CONST_32BIT
# error Using CRYPTO_30_LIBCV_START_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_CONST_32BIT
# error Using CRYPTO_30_LIBCV_STOP_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
# error Using CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
# error Using CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
# error Using CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
# error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_16BIT
# error Using CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT
# error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
# error Using CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
# error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_START_SEC_VAR_ZERO_INIT_8BIT
# error Using CRYPTO_30_LIBCV_START_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT
# error Using CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_START_SEC_CODE
# error Using VSECPRIM_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_STOP_SEC_CODE
# error Using VSECPRIM_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_START_SEC_CONST_8BIT
# error Using VSECPRIM_START_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_STOP_SEC_CONST_8BIT
# error Using VSECPRIM_STOP_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_START_SEC_CONST_32BIT
# error Using VSECPRIM_START_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_STOP_SEC_CONST_32BIT
# error Using VSECPRIM_STOP_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_START_SEC_CONST_64BIT
# error Using VSECPRIM_START_SEC_CONST_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_STOP_SEC_CONST_64BIT
# error Using VSECPRIM_STOP_SEC_CONST_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_START_SEC_CONST_UNSPECIFIED
# error Using VSECPRIM_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# error Using VSECPRIM_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_START_SEC_CODE
# error Using CRYPTO_30_VHSM_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_CODE
# error Using CRYPTO_30_VHSM_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_START_SEC_APPL_CODE
# error Using CRYPTO_30_VHSM_START_SEC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_APPL_CODE
# error Using CRYPTO_30_VHSM_STOP_SEC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_START_SEC_CODE_ISR
# error Using CRYPTO_30_VHSM_START_SEC_CODE_ISR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_CODE_ISR
# error Using CRYPTO_30_VHSM_STOP_SEC_CODE_ISR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_START_SEC_RAMCODE
# error Using CRYPTO_30_VHSM_START_SEC_RAMCODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_RAMCODE
# error Using CRYPTO_30_VHSM_STOP_SEC_RAMCODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
# error Using CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
# error Using CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# error Using CRYPTO_30_VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# error Using CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
# error Using CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
# error Using CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
# error Using CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
# error Using CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT
# error Using CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT
# error Using CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT
# error Using CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT
# error Using CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_START_SEC_VAR_ZERO_INIT_8BIT
# error Using CRYPTO_30_VHSM_START_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# error Using CRYPTO_30_VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: MemMap_Compatibility.h
 *********************************************************************************************************************/

/* PRQA S 0883 */ /* MD_MSR_MemMap */

