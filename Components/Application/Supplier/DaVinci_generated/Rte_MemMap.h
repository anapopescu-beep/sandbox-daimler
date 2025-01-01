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
 *              File: Rte_MemMap.h
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

#if defined RTE_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CODE_OPEN
#  error Using RTE_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_NOINIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_ZERO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_ZERO_INIT_8BIT_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_ZERO_INIT_8BIT_OPEN
#  error Using RTE_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CONST_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_ADCIF_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_ADCIF_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_ADCIF_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_ADCIF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_ADCIF_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_ADCIF_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_ADCIF_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_ADCIF_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_ADCIF_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_ADCIF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_BASEFUNCTION_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_BASEFUNCTION_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_BASEFUNCTION_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_BASEFUNCTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_BASEFUNCTION_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_BASEFUNCTION_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_BASEFUNCTION_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_BASEFUNCTION_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_BASEFUNCTION_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_BASEFUNCTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_BELTADJFUNCTION_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_BELTADJFUNCTION_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_BELTADJFUNCTION_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_BELTADJFUNCTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_BELTADJFUNCTION_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_BELTADJFUNCTION_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_BELTADJFUNCTION_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_BELTADJFUNCTION_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_BELTADJFUNCTION_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_BELTADJFUNCTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_BELTTENSIONERFUNCTION_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_BELTTENSIONERFUNCTION_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_BELTTENSIONERFUNCTION_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_BELTTENSIONERFUNCTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_BELTTENSIONERFUNCTION_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_BELTTENSIONERFUNCTION_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_BELTTENSIONERFUNCTION_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_BELTTENSIONERFUNCTION_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_BELTTENSIONERFUNCTION_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_BELTTENSIONERFUNCTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_BSWM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_BSWM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_BSWM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_BSWM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_BSWM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_BSWM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_BSWM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_BSWM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_BSWM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_BSWM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CDD_MBBL_ECUSTATHANDLER_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CDD_MBBL_ECUSTATHANDLER_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CDD_MBBL_ECUSTATHANDLER_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CDD_MBBL_ECUSTATHANDLER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CDD_MBBL_ECUSTATHANDLER_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CDD_MBBL_ECUSTATHANDLER_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CDD_MBBL_ECUSTATHANDLER_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_CDD_MBBL_ECUSTATHANDLER_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CDD_MBBL_ECUSTATHANDLER_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CDD_MBBL_ECUSTATHANDLER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CDD_MBBL_RESETEXECUTOR_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CDD_MBBL_RESETEXECUTOR_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CDD_MBBL_RESETEXECUTOR_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CDD_MBBL_RESETEXECUTOR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CDD_MBBL_RESETEXECUTOR_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CDD_MBBL_RESETEXECUTOR_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CDD_MBBL_RESETEXECUTOR_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_CDD_MBBL_RESETEXECUTOR_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CDD_MBBL_RESETEXECUTOR_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CDD_MBBL_RESETEXECUTOR_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_COMM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_COMM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_COMM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_COMM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_COMM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_COMM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_COMM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_COMM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_COMM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_COMM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CSM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CSM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CSM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CSM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CSM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CSM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CSM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_CSM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CSM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CSM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CT_MBBL_RESETMANAGER_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CT_MBBL_RESETMANAGER_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CT_MBBL_RESETMANAGER_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CT_MBBL_RESETMANAGER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CT_MBBL_RESETMANAGER_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CT_MBBL_RESETMANAGER_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CT_MBBL_RESETMANAGER_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_CT_MBBL_RESETMANAGER_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CT_MBBL_RESETMANAGER_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CT_MBBL_RESETMANAGER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CT_MBBL_SSAAPPL_CODING_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CT_MBBL_SSAAPPL_CODING_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CT_MBBL_SSAAPPL_CODING_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CT_MBBL_SSAAPPL_CODING_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CT_MBBL_SSAAPPL_CODING_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_CT_MBBL_SSAAPPL_CODING_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CT_MBBL_SSAAPPL_CODING_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CT_PROJECTINFORMATION_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CT_PROJECTINFORMATION_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CT_PROJECTINFORMATION_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CT_PROJECTINFORMATION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CT_PROJECTINFORMATION_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CT_PROJECTINFORMATION_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CT_PROJECTINFORMATION_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_CT_PROJECTINFORMATION_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CT_PROJECTINFORMATION_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CT_PROJECTINFORMATION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DCM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DCM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DCM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DCM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DCM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DCM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DCM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_DCM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DCM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DCM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DEMMASTER_0_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DEMMASTER_0_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DEMMASTER_0_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DEMMASTER_0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DEMMASTER_0_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DEMMASTER_0_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_DEMMASTER_0_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DEMMASTER_0_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DEMMASTER_0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DEMSATELLITE_0_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DEMSATELLITE_0_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DEMSATELLITE_0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DEMSATELLITE_0_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DEMSATELLITE_0_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DET_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DET_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DET_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DET_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DET_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DET_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DET_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_DET_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DET_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DET_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DIAGFUNCTION_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DIAGFUNCTION_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DIAGFUNCTION_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DIAGFUNCTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DIAGFUNCTION_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DIAGFUNCTION_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DIAGFUNCTION_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_DIAGFUNCTION_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DIAGFUNCTION_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DIAGFUNCTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DIA_AC_DIAGONCAN_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DIA_AC_DIAGONCAN_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DIA_AC_DIAGONCAN_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DIA_AC_DIAGONCAN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DIA_AC_DIAGONCAN_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DIA_AC_DIAGONCAN_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DIA_AC_DIAGONCAN_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_DIA_AC_DIAGONCAN_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DIA_AC_DIAGONCAN_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DIA_AC_DIAGONCAN_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_ECUM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_ECUM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_ECUM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_ECUM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_ECUM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_ECUM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_ECUM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_ECUM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_ECUM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_ECUM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_KEYM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_KEYM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_KEYM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_KEYM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_KEYM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_KEYM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_KEYM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_KEYM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_KEYM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_KEYM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_MMG_AC_MODEMANAGEMENT_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_MMG_AC_MODEMANAGEMENT_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_MMG_AC_MODEMANAGEMENT_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_NVM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_NVM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_NVM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_NVM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_NVM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_NVM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_NVM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_NVM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_NVM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_NVM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_OS_OSCORE0_SWC_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_OS_OSCORE0_SWC_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_OS_OSCORE0_SWC_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_OS_OSCORE0_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_OS_OSCORE0_SWC_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_OS_OSCORE0_SWC_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_PRE_AC_PRETENSIONING_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_PRE_AC_PRETENSIONING_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_PRE_AC_PRETENSIONING_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_PRE_AC_PRETENSIONING_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_PRE_AC_PRETENSIONING_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_PRE_AC_PRETENSIONING_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_PRE_AC_PRETENSIONING_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_PRE_AC_PRETENSIONING_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_PRE_AC_PRETENSIONING_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_PRE_AC_PRETENSIONING_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_PWMIF_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_PWMIF_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_PWMIF_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_PWMIF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_PWMIF_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_PWMIF_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_PWMIF_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_PWMIF_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_PWMIF_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_PWMIF_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SBC_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SBC_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SBC_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SBC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SBC_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SBC_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SBC_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SBC_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SBC_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SBC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SECOC_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SECOC_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SECOC_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SECOC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SECOC_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SECOC_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SECOC_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SECOC_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SECOC_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SECOC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SSA_BCTP_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SSA_BCTP_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SSA_BCTP_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SSA_BCTP_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SSA_BCTP_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SSA_BCTP_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SSA_BCTP_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SSA_BCTP_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SSA_BCTP_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SSA_BCTP_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SSA_CDD_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SSA_CDD_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SSA_CDD_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SSA_CDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SSA_CDD_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SSA_CDD_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SSA_CDD_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SSA_CDD_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SSA_CDD_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SSA_CDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SSA_CERTP_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SSA_CERTP_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SSA_CERTP_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SSA_CERTP_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SSA_CERTP_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SSA_CERTP_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SSA_CERTP_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SSA_CERTP_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SSA_CERTP_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SSA_CERTP_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SSA_CODING_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SSA_CODING_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SSA_CODING_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SSA_CODING_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SSA_CODING_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SSA_CODING_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SSA_CODING_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SSA_CODING_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SSA_CODING_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SSA_CODING_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SSA_FVM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SSA_FVM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SSA_FVM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SSA_FVM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SSA_FVM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SSA_FVM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SSA_FVM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SSA_FVM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SSA_FVM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SSA_FVM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SSA_KEYM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SSA_KEYM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SSA_KEYM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SSA_KEYM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SSA_KEYM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SSA_KEYM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SSA_KEYM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SSA_KEYM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SSA_KEYM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SSA_KEYM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SSA_PROCCTRL_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SSA_PROCCTRL_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SSA_PROCCTRL_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SSA_PROCCTRL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SSA_PROCCTRL_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SSA_PROCCTRL_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SSA_PROCCTRL_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SSA_PROCCTRL_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SSA_PROCCTRL_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SSA_PROCCTRL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SSA_RIGHTSM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SSA_RIGHTSM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SSA_RIGHTSM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SSA_RIGHTSM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SSA_RIGHTSM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SSA_RIGHTSM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SSA_RIGHTSM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SSA_RIGHTSM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SSA_RIGHTSM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SSA_RIGHTSM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SSA_SECLOG_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SSA_SECLOG_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SSA_SECLOG_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SSA_SECLOG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SSA_SECLOG_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SSA_SECLOG_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SSA_SECLOG_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SSA_SECLOG_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SSA_SECLOG_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SSA_SECLOG_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SSA_TIMEM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SSA_TIMEM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SSA_TIMEM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SSA_TIMEM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SSA_TIMEM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SSA_TIMEM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SSA_TIMEM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SSA_TIMEM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SSA_TIMEM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SSA_TIMEM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_WDGM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_WDGM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_WDGM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_WDGM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_WDGM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_WDGM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_WDGM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_WDGM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_WDGM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_WDGM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_BSR_AC_BELTSLACKREDUCTION_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_BSR_AC_BELTSLACKREDUCTION_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_BSR_AC_BELTSLACKREDUCTION_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_BSR_AC_BELTSLACKREDUCTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_BSR_AC_BELTSLACKREDUCTION_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_BSR_AC_BELTSLACKREDUCTION_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_BSR_AC_BELTSLACKREDUCTION_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_BSR_AC_BELTSLACKREDUCTION_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_BSR_AC_BELTSLACKREDUCTION_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_BSR_AC_BELTSLACKREDUCTION_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_HWA_AC_HAPTICWARNING_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_HWA_AC_HAPTICWARNING_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_HWA_AC_HAPTICWARNING_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_HWA_AC_HAPTICWARNING_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_HWA_AC_HAPTICWARNING_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_HWA_AC_HAPTICWARNING_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_HWA_AC_HAPTICWARNING_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_HWA_AC_HAPTICWARNING_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_HWA_AC_HAPTICWARNING_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_HWA_AC_HAPTICWARNING_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_ATM_AC_AUTOTESTMANAGER_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_ATM_AC_AUTOTESTMANAGER_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_ATM_AC_AUTOTESTMANAGER_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_ERH_AC_ERRORHANDLER_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_ERH_AC_ERRORHANDLER_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_ERH_AC_ERRORHANDLER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_ERH_AC_ERRORHANDLER_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_ERH_AC_ERRORHANDLER_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_PRO_AC_PRODUCTIONCYCLES_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_PRO_AC_PRODUCTIONCYCLES_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_PRO_AC_PRODUCTIONCYCLES_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_PRO_AC_PRODUCTIONCYCLES_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_PRO_AC_PRODUCTIONCYCLES_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_PRO_AC_PRODUCTIONCYCLES_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_PRO_AC_PRODUCTIONCYCLES_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_PRO_AC_PRODUCTIONCYCLES_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_PRO_AC_PRODUCTIONCYCLES_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_PRO_AC_PRODUCTIONCYCLES_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_APPLBACKGROUNDTASK_CORE0_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_APPLBACKGROUNDTASK_CORE0_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_APPLBACKGROUNDTASK_CORE0_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_APPLBACKGROUNDTASK_CORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_APPLBACKGROUNDTASK_CORE0_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_APPLBACKGROUNDTASK_CORE0_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_APPLBACKGROUNDTASK_CORE0_CODE_OPEN
#  error Using RTE_STOP_SEC_APPLBACKGROUNDTASK_CORE0_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_APPLBACKGROUNDTASK_CORE0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_APPLBACKGROUNDTASK_CORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_APPLINITTASK_CORE0_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_APPLINITTASK_CORE0_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_APPLINITTASK_CORE0_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_APPLINITTASK_CORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_APPLINITTASK_CORE0_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_APPLINITTASK_CORE0_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_APPLINITTASK_CORE0_CODE_OPEN
#  error Using RTE_STOP_SEC_APPLINITTASK_CORE0_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_APPLINITTASK_CORE0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_APPLINITTASK_CORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_APPLTASK_CORE0_HIGHPRIO_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_APPLTASK_CORE0_HIGHPRIO_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_APPLTASK_CORE0_HIGHPRIO_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_APPLTASK_CORE0_HIGHPRIO_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_APPLTASK_CORE0_HIGHPRIO_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_APPLTASK_CORE0_HIGHPRIO_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_APPLTASK_CORE0_HIGHPRIO_CODE_OPEN
#  error Using RTE_STOP_SEC_APPLTASK_CORE0_HIGHPRIO_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_APPLTASK_CORE0_HIGHPRIO_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_APPLTASK_CORE0_HIGHPRIO_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_APPLTASK_CORE0_LOWPRIO_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_APPLTASK_CORE0_LOWPRIO_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_APPLTASK_CORE0_LOWPRIO_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_APPLTASK_CORE0_LOWPRIO_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_APPLTASK_CORE0_LOWPRIO_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_APPLTASK_CORE0_LOWPRIO_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_APPLTASK_CORE0_LOWPRIO_CODE_OPEN
#  error Using RTE_STOP_SEC_APPLTASK_CORE0_LOWPRIO_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_APPLTASK_CORE0_LOWPRIO_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_APPLTASK_CORE0_LOWPRIO_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_BACKGROUNDTASK_CORE0_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_BACKGROUNDTASK_CORE0_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_BACKGROUNDTASK_CORE0_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_BACKGROUNDTASK_CORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_BACKGROUNDTASK_CORE0_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_BACKGROUNDTASK_CORE0_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_BACKGROUNDTASK_CORE0_CODE_OPEN
#  error Using RTE_STOP_SEC_BACKGROUNDTASK_CORE0_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_BACKGROUNDTASK_CORE0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_BACKGROUNDTASK_CORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_BSWTASK_CORE0_HIGHPRIO_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_BSWTASK_CORE0_HIGHPRIO_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_BSWTASK_CORE0_HIGHPRIO_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_BSWTASK_CORE0_HIGHPRIO_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_BSWTASK_CORE0_HIGHPRIO_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_BSWTASK_CORE0_HIGHPRIO_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_BSWTASK_CORE0_HIGHPRIO_CODE_OPEN
#  error Using RTE_STOP_SEC_BSWTASK_CORE0_HIGHPRIO_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_BSWTASK_CORE0_HIGHPRIO_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_BSWTASK_CORE0_HIGHPRIO_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_BSWTASK_CORE0_LOWPRIO_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_BSWTASK_CORE0_LOWPRIO_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_BSWTASK_CORE0_LOWPRIO_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_BSWTASK_CORE0_LOWPRIO_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_BSWTASK_CORE0_LOWPRIO_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_BSWTASK_CORE0_LOWPRIO_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_BSWTASK_CORE0_LOWPRIO_CODE_OPEN
#  error Using RTE_STOP_SEC_BSWTASK_CORE0_LOWPRIO_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_BSWTASK_CORE0_LOWPRIO_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_BSWTASK_CORE0_LOWPRIO_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DEFAULT_INIT_TASK_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DEFAULT_INIT_TASK_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DEFAULT_INIT_TASK_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DEFAULT_INIT_TASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DEFAULT_INIT_TASK_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DEFAULT_INIT_TASK_CODE_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DEFAULT_INIT_TASK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DEFAULT_INIT_TASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DEFAULT_INIT_TASK_TRUSTED_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DEFAULT_INIT_TASK_TRUSTED_CODE_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DEFAULT_INIT_TASK_TRUSTED_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_IDLETASK_OSCORE0_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_IDLETASK_OSCORE0_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_IDLETASK_OSCORE0_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_IDLETASK_OSCORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_IDLETASK_OSCORE0_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_IDLETASK_OSCORE0_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_IDLETASK_OSCORE0_CODE_OPEN
#  error Using RTE_STOP_SEC_IDLETASK_OSCORE0_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_IDLETASK_OSCORE0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_IDLETASK_OSCORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_OSTASK_ALV_BELTFUNCTIONALGO_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_OSTASK_ALV_BELTFUNCTIONALGO_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_OSTASK_ALV_BELTFUNCTIONALGO_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_OSTASK_ALV_BELTFUNCTIONALGO_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_OSTASK_ALV_BELTFUNCTIONALGO_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_OSTASK_ALV_BELTFUNCTIONALGO_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_OSTASK_ALV_BELTFUNCTIONALGO_CODE_OPEN
#  error Using RTE_STOP_SEC_OSTASK_ALV_BELTFUNCTIONALGO_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_OSTASK_ALV_BELTFUNCTIONALGO_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_OSTASK_ALV_BELTFUNCTIONALGO_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CT_RESOURCEMEASUREMENT_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CT_RESOURCEMEASUREMENT_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CT_RESOURCEMEASUREMENT_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CT_RESOURCEMEASUREMENT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CT_RESOURCEMEASUREMENT_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CT_RESOURCEMEASUREMENT_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CT_RESOURCEMEASUREMENT_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_CT_RESOURCEMEASUREMENT_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CT_RESOURCEMEASUREMENT_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CT_RESOURCEMEASUREMENT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CODE
# error Using RTE_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CODE
# error Using RTE_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_ZERO_INIT_8BIT
# error Using RTE_START_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
# error Using RTE_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CONST_UNSPECIFIED
# error Using RTE_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CONST_UNSPECIFIED
# error Using RTE_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_APPL_CODE
# error Using RTE_START_SEC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_APPL_CODE
# error Using RTE_STOP_SEC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_ADCIF_APPL_CODE
# error Using RTE_START_SEC_ADCIF_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_ADCIF_APPL_CODE
# error Using RTE_STOP_SEC_ADCIF_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_BASEFUNCTION_APPL_CODE
# error Using RTE_START_SEC_BASEFUNCTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_BASEFUNCTION_APPL_CODE
# error Using RTE_STOP_SEC_BASEFUNCTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_BELTADJFUNCTION_APPL_CODE
# error Using RTE_START_SEC_BELTADJFUNCTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_BELTADJFUNCTION_APPL_CODE
# error Using RTE_STOP_SEC_BELTADJFUNCTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_BELTTENSIONERFUNCTION_APPL_CODE
# error Using RTE_START_SEC_BELTTENSIONERFUNCTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_BELTTENSIONERFUNCTION_APPL_CODE
# error Using RTE_STOP_SEC_BELTTENSIONERFUNCTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE
# error Using RTE_START_SEC_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE
# error Using RTE_STOP_SEC_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE
# error Using RTE_START_SEC_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE
# error Using RTE_STOP_SEC_BFS_AC_BELTFUNCTIONSELECTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_BSWM_APPL_CODE
# error Using RTE_START_SEC_BSWM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_BSWM_APPL_CODE
# error Using RTE_STOP_SEC_BSWM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CDD_MBBL_ECUSTATHANDLER_APPL_CODE
# error Using RTE_START_SEC_CDD_MBBL_ECUSTATHANDLER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CDD_MBBL_ECUSTATHANDLER_APPL_CODE
# error Using RTE_STOP_SEC_CDD_MBBL_ECUSTATHANDLER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CDD_MBBL_RESETEXECUTOR_APPL_CODE
# error Using RTE_START_SEC_CDD_MBBL_RESETEXECUTOR_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CDD_MBBL_RESETEXECUTOR_APPL_CODE
# error Using RTE_STOP_SEC_CDD_MBBL_RESETEXECUTOR_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE
# error Using RTE_START_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE
# error Using RTE_STOP_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_COMM_APPL_CODE
# error Using RTE_START_SEC_COMM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_COMM_APPL_CODE
# error Using RTE_STOP_SEC_COMM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CSM_APPL_CODE
# error Using RTE_START_SEC_CSM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CSM_APPL_CODE
# error Using RTE_STOP_SEC_CSM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CT_MBBL_RESETMANAGER_APPL_CODE
# error Using RTE_START_SEC_CT_MBBL_RESETMANAGER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CT_MBBL_RESETMANAGER_APPL_CODE
# error Using RTE_STOP_SEC_CT_MBBL_RESETMANAGER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE
# error Using RTE_START_SEC_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE
# error Using RTE_STOP_SEC_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CT_MBBL_SSAAPPL_CODING_APPL_CODE
# error Using RTE_START_SEC_CT_MBBL_SSAAPPL_CODING_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CT_MBBL_SSAAPPL_CODING_APPL_CODE
# error Using RTE_STOP_SEC_CT_MBBL_SSAAPPL_CODING_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE
# error Using RTE_START_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE
# error Using RTE_STOP_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE
# error Using RTE_START_SEC_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE
# error Using RTE_STOP_SEC_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE
# error Using RTE_START_SEC_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE
# error Using RTE_STOP_SEC_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CT_PROJECTINFORMATION_APPL_CODE
# error Using RTE_START_SEC_CT_PROJECTINFORMATION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CT_PROJECTINFORMATION_APPL_CODE
# error Using RTE_STOP_SEC_CT_PROJECTINFORMATION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DCM_APPL_CODE
# error Using RTE_START_SEC_DCM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DCM_APPL_CODE
# error Using RTE_STOP_SEC_DCM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DEMMASTER_0_APPL_CODE
# error Using RTE_START_SEC_DEMMASTER_0_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
# error Using RTE_STOP_SEC_DEMMASTER_0_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
# error Using RTE_START_SEC_DEMSATELLITE_0_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
# error Using RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DET_APPL_CODE
# error Using RTE_START_SEC_DET_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DET_APPL_CODE
# error Using RTE_STOP_SEC_DET_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DIAGFUNCTION_APPL_CODE
# error Using RTE_START_SEC_DIAGFUNCTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DIAGFUNCTION_APPL_CODE
# error Using RTE_STOP_SEC_DIAGFUNCTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DIA_AC_DIAGONCAN_APPL_CODE
# error Using RTE_START_SEC_DIA_AC_DIAGONCAN_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DIA_AC_DIAGONCAN_APPL_CODE
# error Using RTE_STOP_SEC_DIA_AC_DIAGONCAN_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_ECUM_APPL_CODE
# error Using RTE_START_SEC_ECUM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_ECUM_APPL_CODE
# error Using RTE_STOP_SEC_ECUM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_KEYM_APPL_CODE
# error Using RTE_START_SEC_KEYM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_KEYM_APPL_CODE
# error Using RTE_STOP_SEC_KEYM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE
# error Using RTE_START_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE
# error Using RTE_STOP_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_NVM_APPL_CODE
# error Using RTE_START_SEC_NVM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_NVM_APPL_CODE
# error Using RTE_STOP_SEC_NVM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_OS_OSCORE0_SWC_APPL_CODE
# error Using RTE_START_SEC_OS_OSCORE0_SWC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE
# error Using RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
# error Using RTE_START_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
# error Using RTE_STOP_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
# error Using RTE_START_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
# error Using RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_PRE_AC_PRETENSIONING_APPL_CODE
# error Using RTE_START_SEC_PRE_AC_PRETENSIONING_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_PRE_AC_PRETENSIONING_APPL_CODE
# error Using RTE_STOP_SEC_PRE_AC_PRETENSIONING_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_PWMIF_APPL_CODE
# error Using RTE_START_SEC_PWMIF_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_PWMIF_APPL_CODE
# error Using RTE_STOP_SEC_PWMIF_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SBC_APPL_CODE
# error Using RTE_START_SEC_SBC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SBC_APPL_CODE
# error Using RTE_STOP_SEC_SBC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SECOC_APPL_CODE
# error Using RTE_START_SEC_SECOC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SECOC_APPL_CODE
# error Using RTE_STOP_SEC_SECOC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE
# error Using RTE_START_SEC_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE
# error Using RTE_STOP_SEC_SFR_AC_STANDARDFUNCTIONRECOVERY_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SSA_BCTP_APPL_CODE
# error Using RTE_START_SEC_SSA_BCTP_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SSA_BCTP_APPL_CODE
# error Using RTE_STOP_SEC_SSA_BCTP_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SSA_CDD_APPL_CODE
# error Using RTE_START_SEC_SSA_CDD_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SSA_CDD_APPL_CODE
# error Using RTE_STOP_SEC_SSA_CDD_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SSA_CERTP_APPL_CODE
# error Using RTE_START_SEC_SSA_CERTP_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SSA_CERTP_APPL_CODE
# error Using RTE_STOP_SEC_SSA_CERTP_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SSA_CODING_APPL_CODE
# error Using RTE_START_SEC_SSA_CODING_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SSA_CODING_APPL_CODE
# error Using RTE_STOP_SEC_SSA_CODING_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SSA_FVM_APPL_CODE
# error Using RTE_START_SEC_SSA_FVM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SSA_FVM_APPL_CODE
# error Using RTE_STOP_SEC_SSA_FVM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SSA_KEYM_APPL_CODE
# error Using RTE_START_SEC_SSA_KEYM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SSA_KEYM_APPL_CODE
# error Using RTE_STOP_SEC_SSA_KEYM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SSA_PROCCTRL_APPL_CODE
# error Using RTE_START_SEC_SSA_PROCCTRL_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SSA_PROCCTRL_APPL_CODE
# error Using RTE_STOP_SEC_SSA_PROCCTRL_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SSA_RIGHTSM_APPL_CODE
# error Using RTE_START_SEC_SSA_RIGHTSM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SSA_RIGHTSM_APPL_CODE
# error Using RTE_STOP_SEC_SSA_RIGHTSM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SSA_SECLOG_APPL_CODE
# error Using RTE_START_SEC_SSA_SECLOG_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SSA_SECLOG_APPL_CODE
# error Using RTE_STOP_SEC_SSA_SECLOG_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SSA_TIMEM_APPL_CODE
# error Using RTE_START_SEC_SSA_TIMEM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SSA_TIMEM_APPL_CODE
# error Using RTE_STOP_SEC_SSA_TIMEM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_WDGM_APPL_CODE
# error Using RTE_START_SEC_WDGM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_WDGM_APPL_CODE
# error Using RTE_STOP_SEC_WDGM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
# error Using RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
# error Using RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
# error Using RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
# error Using RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
# error Using RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_BSR_AC_BELTSLACKREDUCTION_APPL_CODE
# error Using RTE_START_SEC_BSR_AC_BELTSLACKREDUCTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_BSR_AC_BELTSLACKREDUCTION_APPL_CODE
# error Using RTE_STOP_SEC_BSR_AC_BELTSLACKREDUCTION_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE
# error Using RTE_START_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE
# error Using RTE_STOP_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_HWA_AC_HAPTICWARNING_APPL_CODE
# error Using RTE_START_SEC_HWA_AC_HAPTICWARNING_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_HWA_AC_HAPTICWARNING_APPL_CODE
# error Using RTE_STOP_SEC_HWA_AC_HAPTICWARNING_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
# error Using RTE_START_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
# error Using RTE_STOP_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
# error Using RTE_START_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
# error Using RTE_STOP_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
# error Using RTE_START_SEC_ERH_AC_ERRORHANDLER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
# error Using RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_PRO_AC_PRODUCTIONCYCLES_APPL_CODE
# error Using RTE_START_SEC_PRO_AC_PRODUCTIONCYCLES_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_PRO_AC_PRODUCTIONCYCLES_APPL_CODE
# error Using RTE_STOP_SEC_PRO_AC_PRODUCTIONCYCLES_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
# error Using RTE_START_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
# error Using RTE_STOP_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_APPLBACKGROUNDTASK_CORE0_CODE
# error Using RTE_START_SEC_APPLBACKGROUNDTASK_CORE0_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_APPLBACKGROUNDTASK_CORE0_CODE
# error Using RTE_STOP_SEC_APPLBACKGROUNDTASK_CORE0_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_APPLINITTASK_CORE0_CODE
# error Using RTE_START_SEC_APPLINITTASK_CORE0_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_APPLINITTASK_CORE0_CODE
# error Using RTE_STOP_SEC_APPLINITTASK_CORE0_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_APPLTASK_CORE0_HIGHPRIO_CODE
# error Using RTE_START_SEC_APPLTASK_CORE0_HIGHPRIO_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_APPLTASK_CORE0_HIGHPRIO_CODE
# error Using RTE_STOP_SEC_APPLTASK_CORE0_HIGHPRIO_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_APPLTASK_CORE0_LOWPRIO_CODE
# error Using RTE_START_SEC_APPLTASK_CORE0_LOWPRIO_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_APPLTASK_CORE0_LOWPRIO_CODE
# error Using RTE_STOP_SEC_APPLTASK_CORE0_LOWPRIO_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_BACKGROUNDTASK_CORE0_CODE
# error Using RTE_START_SEC_BACKGROUNDTASK_CORE0_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_BACKGROUNDTASK_CORE0_CODE
# error Using RTE_STOP_SEC_BACKGROUNDTASK_CORE0_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_BSWTASK_CORE0_HIGHPRIO_CODE
# error Using RTE_START_SEC_BSWTASK_CORE0_HIGHPRIO_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_BSWTASK_CORE0_HIGHPRIO_CODE
# error Using RTE_STOP_SEC_BSWTASK_CORE0_HIGHPRIO_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_BSWTASK_CORE0_LOWPRIO_CODE
# error Using RTE_START_SEC_BSWTASK_CORE0_LOWPRIO_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_BSWTASK_CORE0_LOWPRIO_CODE
# error Using RTE_STOP_SEC_BSWTASK_CORE0_LOWPRIO_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DEFAULT_INIT_TASK_CODE
# error Using RTE_START_SEC_DEFAULT_INIT_TASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DEFAULT_INIT_TASK_CODE
# error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE
# error Using RTE_START_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE
# error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_IDLETASK_OSCORE0_CODE
# error Using RTE_START_SEC_IDLETASK_OSCORE0_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_IDLETASK_OSCORE0_CODE
# error Using RTE_STOP_SEC_IDLETASK_OSCORE0_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_OSTASK_ALV_BELTFUNCTIONALGO_CODE
# error Using RTE_START_SEC_OSTASK_ALV_BELTFUNCTIONALGO_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_OSTASK_ALV_BELTFUNCTIONALGO_CODE
# error Using RTE_STOP_SEC_OSTASK_ALV_BELTFUNCTIONALGO_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE
# error Using RTE_START_SEC_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE
# error Using RTE_STOP_SEC_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
# error Using RTE_START_SEC_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
# error Using RTE_STOP_SEC_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CT_RESOURCEMEASUREMENT_APPL_CODE
# error Using RTE_START_SEC_CT_RESOURCEMEASUREMENT_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CT_RESOURCEMEASUREMENT_APPL_CODE
# error Using RTE_STOP_SEC_CT_RESOURCEMEASUREMENT_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
# error Using RTE_START_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
# error Using RTE_STOP_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#ifdef MEMMAP_ERROR
# error No MemMap section found in Rte_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: Rte_MemMap.h
 *********************************************************************************************************************/

/* PRQA S 0883 */ /* MD_MSR_MemMap */

