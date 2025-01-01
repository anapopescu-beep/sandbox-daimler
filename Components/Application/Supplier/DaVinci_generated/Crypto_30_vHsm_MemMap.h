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
 *              File: Crypto_30_vHsm_MemMap.h
 *   Generation Time: 2023-07-18 10:50:23
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

#if defined CRYPTO_30_VHSM_START_SEC_CODE
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

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/CRYPTO_30_VHSM_IPC_MEMORY_VAR_NOINIT/MemMapAddressingMode */
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

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/CRYPTO_30_VHSM_IPC_MEMORY_VAR_NOINIT/MemMapAddressingMode */
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

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/CRYPTO_30_VHSM_GLOBAL_VAR_NOINIT/MemMapAddressingMode */
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

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/CRYPTO_30_VHSM_GLOBAL_VAR_NOINIT/MemMapAddressingMode */
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

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/CRYPTO_30_VHSM_GLOBAL_VAR_NOINIT/MemMapAddressingMode */
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

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/CRYPTO_30_VHSM_GLOBAL_VAR_NOINIT/MemMapAddressingMode */
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

#ifdef MEMMAP_ERROR
# error No MemMap section found in Crypto_30_vHsm_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_MemMap.h
 *********************************************************************************************************************/

/* PRQA S 0883 */ /* MD_MSR_MemMap */

