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
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000614_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: MemMap_Common.h
 *   Generation Time: 2022-02-25 10:25:43
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2000614_D04
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

#if defined START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CODE_OPEN

# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CODE_OPEN
#  error Using STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CODE_FAST
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CODE_FAST is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CODE_OPEN

# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CODE_FAST
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CODE_FAST is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CODE_OPEN
#  error Using STOP_SEC_CODE_FAST is not possible as the corresponding memory section has not been opened.
# endif
# undef CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CODE_ISR
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CODE_ISR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CODE_OPEN

# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CODE_ISR
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CODE_ISR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CODE_OPEN
#  error Using STOP_SEC_CODE_ISR is not possible as the corresponding memory section has not been opened.
# endif
# undef CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_64BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_64BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_64BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_64BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_FAST_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_FAST_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_FAST_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_FAST_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_FAST_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_FAST_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_FAST_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_FAST_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_FAST_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_FAST_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_FAST_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_FAST_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_FAST_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_FAST_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_FAST_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_FAST_64BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_FAST_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_FAST_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_FAST_64BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_FAST_64BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_FAST_64BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_FAST_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_FAST_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_FAST_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_FAST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_FAST_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_FAST_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_FAST_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_FAST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_FAST_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_FAST_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_FAST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_FAST_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_FAST_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_FAST_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_FAST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_FAST_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_FAST_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_FAST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_FAST_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_FAST_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_FAST_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_FAST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_FAST_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_FAST_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_FAST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_FAST_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_FAST_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_FAST_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_FAST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_FAST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_FAST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_FAST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_FAST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_FAST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_CONST_PBCFG
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_CONST_PBCFG is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_CONST_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_CONST_PBCFG
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_CONST_PBCFG is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_CONST_PBCFG is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_CONST_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_PBCFG_GLOBALROOT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_PBCFG_GLOBALROOT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CONST_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_PBCFG_GLOBALROOT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_PBCFG_GLOBALROOT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CONST_OPEN
#  error Using STOP_SEC_PBCFG_GLOBALROOT is not possible as the corresponding memory section has not been opened.
# endif
# undef CONST_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_INIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_INIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_INIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_INIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_INIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_INIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_INIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_INIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_INIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_INIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_INIT_64BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_INIT_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_INIT_64BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_INIT_64BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_INIT_64BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOINIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOINIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOINIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOINIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOINIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOINIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOINIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOINIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOINIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOINIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOINIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOINIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOINIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOINIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOINIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOINIT_64BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOINIT_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOINIT_64BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOINIT_64BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOINIT_64BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_ZERO_INIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_ZERO_INIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_ZERO_INIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_ZERO_INIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_ZERO_INIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_ZERO_INIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_ZERO_INIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_ZERO_INIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_ZERO_INIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_ZERO_INIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_ZERO_INIT_64BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_ZERO_INIT_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_ZERO_INIT_64BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_ZERO_INIT_64BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_ZERO_INIT_64BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_INIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_INIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_INIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_INIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_INIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_INIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_INIT_64BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_INIT_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_INIT_64BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_64BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_64BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_NOINIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_NOINIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_NOINIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_NOINIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_NOINIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_NOINIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_NOINIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_NOINIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_NOINIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_NOINIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_NOINIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_NOINIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_NOINIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_NOINIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_NOINIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_NOINIT_64BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_NOINIT_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_NOINIT_64BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_NOINIT_64BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_NOINIT_64BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_ZERO_INIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_ZERO_INIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_ZERO_INIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_ZERO_INIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_ZERO_INIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_ZERO_INIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_ZERO_INIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_ZERO_INIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_ZERO_INIT_64BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_ZERO_INIT_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_ZERO_INIT_64BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_ZERO_INIT_64BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_ZERO_INIT_64BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_INIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_INIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_INIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_INIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_INIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_INIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_INIT_64BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_INIT_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_INIT_64BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_64BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_64BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_NOINIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_NOINIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NOINIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NOINIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_NOINIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_NOINIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NOINIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NOINIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_NOINIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_NOINIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NOINIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NOINIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_NOINIT_64BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_NOINIT_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_NOINIT_64BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NOINIT_64BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NOINIT_64BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined START_SEC_VAR_PBCFG
# ifdef MEMMAP_SECTION_OPEN
#  error Using START_SEC_VAR_PBCFG is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define VAR_OPEN

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined STOP_SEC_VAR_PBCFG
# ifndef MEMMAP_SECTION_OPEN
#  error Using STOP_SEC_VAR_PBCFG is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef VAR_OPEN
#  error Using STOP_SEC_VAR_PBCFG is not possible as the corresponding memory section has not been opened.
# endif
# undef VAR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

# pragma section nearrom restore
# pragma section farrom restore

# undef STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/* If the memory allocation keyword can't be handled the Os MemMap will be used */
#include "Os_MemMap.h"

/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef START_SEC_CODE
# error Using START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CODE
# error Using STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CODE_FAST
# error Using START_SEC_CODE_FAST is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CODE_FAST
# error Using STOP_SEC_CODE_FAST is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CODE_ISR
# error Using START_SEC_CODE_ISR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CODE_ISR
# error Using STOP_SEC_CODE_ISR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST
# error Using START_SEC_CONST is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST
# error Using STOP_SEC_CONST is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_8BIT
# error Using START_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_8BIT
# error Using STOP_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_16BIT
# error Using START_SEC_CONST_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_16BIT
# error Using STOP_SEC_CONST_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_32BIT
# error Using START_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_32BIT
# error Using STOP_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_64BIT
# error Using START_SEC_CONST_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_64BIT
# error Using STOP_SEC_CONST_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_8
# error Using START_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_8
# error Using STOP_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_16
# error Using START_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_16
# error Using STOP_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_32
# error Using START_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_32
# error Using STOP_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_64
# error Using START_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_64
# error Using STOP_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_UNSPECIFIED
# error Using START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_UNSPECIFIED
# error Using STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_FAST_8BIT
# error Using START_SEC_CONST_FAST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_FAST_8BIT
# error Using STOP_SEC_CONST_FAST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_FAST_16BIT
# error Using START_SEC_CONST_FAST_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_FAST_16BIT
# error Using STOP_SEC_CONST_FAST_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_FAST_32BIT
# error Using START_SEC_CONST_FAST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_FAST_32BIT
# error Using STOP_SEC_CONST_FAST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_FAST_64BIT
# error Using START_SEC_CONST_FAST_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_FAST_64BIT
# error Using STOP_SEC_CONST_FAST_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_FAST_8
# error Using START_SEC_CONST_FAST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_FAST_8
# error Using STOP_SEC_CONST_FAST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_FAST_16
# error Using START_SEC_CONST_FAST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_FAST_16
# error Using STOP_SEC_CONST_FAST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_FAST_32
# error Using START_SEC_CONST_FAST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_FAST_32
# error Using STOP_SEC_CONST_FAST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_FAST_64
# error Using START_SEC_CONST_FAST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_FAST_64
# error Using STOP_SEC_CONST_FAST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_FAST_UNSPECIFIED
# error Using START_SEC_CONST_FAST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_FAST_UNSPECIFIED
# error Using STOP_SEC_CONST_FAST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_CONST_PBCFG
# error Using START_SEC_CONST_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_CONST_PBCFG
# error Using STOP_SEC_CONST_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_PBCFG_GLOBALROOT
# error Using START_SEC_PBCFG_GLOBALROOT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_PBCFG_GLOBALROOT
# error Using STOP_SEC_PBCFG_GLOBALROOT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR
# error Using START_SEC_VAR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR
# error Using STOP_SEC_VAR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_INIT_8BIT
# error Using START_SEC_VAR_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_INIT_8BIT
# error Using STOP_SEC_VAR_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_INIT_16BIT
# error Using START_SEC_VAR_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_INIT_16BIT
# error Using STOP_SEC_VAR_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_INIT_32BIT
# error Using START_SEC_VAR_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_INIT_32BIT
# error Using STOP_SEC_VAR_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_INIT_64BIT
# error Using START_SEC_VAR_INIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_INIT_64BIT
# error Using STOP_SEC_VAR_INIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_INIT_8
# error Using START_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_INIT_8
# error Using STOP_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_INIT_16
# error Using START_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_INIT_16
# error Using STOP_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_INIT_32
# error Using START_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_INIT_32
# error Using STOP_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_INIT_64
# error Using START_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_INIT_64
# error Using STOP_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_INIT_UNSPECIFIED
# error Using START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOINIT_8BIT
# error Using START_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOINIT_8BIT
# error Using STOP_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOINIT_16BIT
# error Using START_SEC_VAR_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOINIT_16BIT
# error Using STOP_SEC_VAR_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOINIT_32BIT
# error Using START_SEC_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOINIT_32BIT
# error Using STOP_SEC_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOINIT_64BIT
# error Using START_SEC_VAR_NOINIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOINIT_64BIT
# error Using STOP_SEC_VAR_NOINIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NO_INIT_8
# error Using START_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NO_INIT_8
# error Using STOP_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NO_INIT_16
# error Using START_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NO_INIT_16
# error Using STOP_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NO_INIT_32
# error Using START_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NO_INIT_32
# error Using STOP_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NO_INIT_64
# error Using START_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NO_INIT_64
# error Using STOP_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_ZERO_INIT_8BIT
# error Using START_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_ZERO_INIT_8BIT
# error Using STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_ZERO_INIT_16BIT
# error Using START_SEC_VAR_ZERO_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_ZERO_INIT_16BIT
# error Using STOP_SEC_VAR_ZERO_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_ZERO_INIT_32BIT
# error Using START_SEC_VAR_ZERO_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_ZERO_INIT_32BIT
# error Using STOP_SEC_VAR_ZERO_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_ZERO_INIT_64BIT
# error Using START_SEC_VAR_ZERO_INIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_ZERO_INIT_64BIT
# error Using STOP_SEC_VAR_ZERO_INIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_CLEARED_8
# error Using START_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_CLEARED_8
# error Using STOP_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_CLEARED_16
# error Using START_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_CLEARED_16
# error Using STOP_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_CLEARED_32
# error Using START_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_CLEARED_32
# error Using STOP_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_CLEARED_64
# error Using START_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_CLEARED_64
# error Using STOP_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED
# error Using START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_CLEARED_UNSPECIFIED
# error Using STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_INIT_8BIT
# error Using START_SEC_VAR_FAST_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_INIT_8BIT
# error Using STOP_SEC_VAR_FAST_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_INIT_16BIT
# error Using START_SEC_VAR_FAST_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_INIT_16BIT
# error Using STOP_SEC_VAR_FAST_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_INIT_32BIT
# error Using START_SEC_VAR_FAST_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_INIT_32BIT
# error Using STOP_SEC_VAR_FAST_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_INIT_64BIT
# error Using START_SEC_VAR_FAST_INIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_INIT_64BIT
# error Using STOP_SEC_VAR_FAST_INIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_INIT_8
# error Using START_SEC_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_INIT_8
# error Using STOP_SEC_VAR_FAST_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_INIT_16
# error Using START_SEC_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_INIT_16
# error Using STOP_SEC_VAR_FAST_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_INIT_32
# error Using START_SEC_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_INIT_32
# error Using STOP_SEC_VAR_FAST_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_INIT_64
# error Using START_SEC_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_INIT_64
# error Using STOP_SEC_VAR_FAST_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_INIT_UNSPECIFIED
# error Using START_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# error Using STOP_SEC_VAR_FAST_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_NOINIT_8BIT
# error Using START_SEC_VAR_FAST_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_NOINIT_8BIT
# error Using STOP_SEC_VAR_FAST_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_NOINIT_16BIT
# error Using START_SEC_VAR_FAST_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_NOINIT_16BIT
# error Using STOP_SEC_VAR_FAST_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_NOINIT_32BIT
# error Using START_SEC_VAR_FAST_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_NOINIT_32BIT
# error Using STOP_SEC_VAR_FAST_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_NOINIT_64BIT
# error Using START_SEC_VAR_FAST_NOINIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_NOINIT_64BIT
# error Using STOP_SEC_VAR_FAST_NOINIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_NO_INIT_8
# error Using START_SEC_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_NO_INIT_8
# error Using STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_NO_INIT_16
# error Using START_SEC_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_NO_INIT_16
# error Using STOP_SEC_VAR_FAST_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_NO_INIT_32
# error Using START_SEC_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_NO_INIT_32
# error Using STOP_SEC_VAR_FAST_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_NO_INIT_64
# error Using START_SEC_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_NO_INIT_64
# error Using STOP_SEC_VAR_FAST_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# error Using START_SEC_VAR_FAST_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# error Using STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using START_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED
# error Using STOP_SEC_VAR_FAST_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_ZERO_INIT_8BIT
# error Using START_SEC_VAR_FAST_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# error Using STOP_SEC_VAR_FAST_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_ZERO_INIT_16BIT
# error Using START_SEC_VAR_FAST_ZERO_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# error Using STOP_SEC_VAR_FAST_ZERO_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_ZERO_INIT_32BIT
# error Using START_SEC_VAR_FAST_ZERO_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# error Using STOP_SEC_VAR_FAST_ZERO_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_ZERO_INIT_64BIT
# error Using START_SEC_VAR_FAST_ZERO_INIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_ZERO_INIT_64BIT
# error Using STOP_SEC_VAR_FAST_ZERO_INIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_CLEARED_8
# error Using START_SEC_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_CLEARED_8
# error Using STOP_SEC_VAR_FAST_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_CLEARED_16
# error Using START_SEC_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_CLEARED_16
# error Using STOP_SEC_VAR_FAST_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_CLEARED_32
# error Using START_SEC_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_CLEARED_32
# error Using STOP_SEC_VAR_FAST_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_CLEARED_64
# error Using START_SEC_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_CLEARED_64
# error Using STOP_SEC_VAR_FAST_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# error Using START_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
# error Using STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# error Using START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# error Using STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_INIT_8BIT
# error Using START_SEC_VAR_NOCACHE_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_INIT_8BIT
# error Using STOP_SEC_VAR_NOCACHE_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_INIT_16BIT
# error Using START_SEC_VAR_NOCACHE_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_INIT_16BIT
# error Using STOP_SEC_VAR_NOCACHE_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_INIT_32BIT
# error Using START_SEC_VAR_NOCACHE_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_INIT_32BIT
# error Using STOP_SEC_VAR_NOCACHE_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_INIT_64BIT
# error Using START_SEC_VAR_NOCACHE_INIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_INIT_64BIT
# error Using STOP_SEC_VAR_NOCACHE_INIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_INIT_8
# error Using START_SEC_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_INIT_8
# error Using STOP_SEC_VAR_NOCACHE_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_INIT_16
# error Using START_SEC_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_INIT_16
# error Using STOP_SEC_VAR_NOCACHE_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_INIT_32
# error Using START_SEC_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_INIT_32
# error Using STOP_SEC_VAR_NOCACHE_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_INIT_64
# error Using START_SEC_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_INIT_64
# error Using STOP_SEC_VAR_NOCACHE_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_NOINIT_8BIT
# error Using START_SEC_VAR_NOCACHE_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# error Using STOP_SEC_VAR_NOCACHE_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_NOINIT_16BIT
# error Using START_SEC_VAR_NOCACHE_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# error Using STOP_SEC_VAR_NOCACHE_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_NOINIT_32BIT
# error Using START_SEC_VAR_NOCACHE_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# error Using STOP_SEC_VAR_NOCACHE_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_NOINIT_64BIT
# error Using START_SEC_VAR_NOCACHE_NOINIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_NOINIT_64BIT
# error Using STOP_SEC_VAR_NOCACHE_NOINIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_NO_INIT_8
# error Using START_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_NO_INIT_8
# error Using STOP_SEC_VAR_NOCACHE_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_NO_INIT_16
# error Using START_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_NO_INIT_16
# error Using STOP_SEC_VAR_NOCACHE_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_NO_INIT_32
# error Using START_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_NO_INIT_32
# error Using STOP_SEC_VAR_NOCACHE_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_NO_INIT_64
# error Using START_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_NO_INIT_64
# error Using STOP_SEC_VAR_NOCACHE_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# error Using START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# error Using STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using START_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED
# error Using STOP_SEC_VAR_NOCACHE_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# error Using START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# error Using START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# error Using START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT
# error Using START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT
# error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_CLEARED_8
# error Using START_SEC_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_CLEARED_8
# error Using STOP_SEC_VAR_NOCACHE_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_CLEARED_16
# error Using START_SEC_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_CLEARED_16
# error Using STOP_SEC_VAR_NOCACHE_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_CLEARED_32
# error Using START_SEC_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_CLEARED_32
# error Using STOP_SEC_VAR_NOCACHE_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_CLEARED_64
# error Using START_SEC_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_CLEARED_64
# error Using STOP_SEC_VAR_NOCACHE_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using START_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED
# error Using STOP_SEC_VAR_NOCACHE_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# error Using START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# error Using STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef START_SEC_VAR_PBCFG
# error Using START_SEC_VAR_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef STOP_SEC_VAR_PBCFG
# error Using STOP_SEC_VAR_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#ifdef MEMMAP_ERROR
# error No MemMap section found in MemMap_Common.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: MemMap_Common.h
 *********************************************************************************************************************/

