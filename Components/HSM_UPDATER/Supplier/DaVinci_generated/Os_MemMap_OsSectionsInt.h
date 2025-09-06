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
 *              File: Os_MemMap_OsSectionsInt.h
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

                                                                                                                        /* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */

/**********************************************************************************************************************
 *  CODE SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_INTVEC_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_INTVEC_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_INTVEC_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_INTVEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_INTVEC_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_INTVEC_CODE_OPEN
#  error Section OS_INTVEC_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_INTVEC_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_INTVEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


#ifdef OS_START_SEC_INTVEC_CORE0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_INTVEC_CORE0_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_INTVEC_CORE0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_INTVEC_CORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_INTVEC_CORE0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_INTVEC_CORE0_CODE_OPEN
#  error Section OS_INTVEC_CORE0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_INTVEC_CORE0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_INTVEC_CORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_EXCVEC_CORE0_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_EXCVEC_CORE0_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_EXCVEC_CORE0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_EXCVEC_CORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_EXCVEC_CORE0_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_EXCVEC_CORE0_CODE_OPEN
#  error Section OS_EXCVEC_CORE0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_EXCVEC_CORE0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_EXCVEC_CORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CONST_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CONST_UNSPECIFIED_OPEN
#  error Section OS_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_INTVEC_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_INTVEC_CONST_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_INTVEC_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_INTVEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_INTVEC_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_INTVEC_CONST_UNSPECIFIED_OPEN
#  error Section OS_INTVEC_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_INTVEC_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_INTVEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


#ifdef OS_START_SEC_CORE0_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CORE0_CONST_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_CORE0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_CORE0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_CONST_UNSPECIFIED_OPEN
#  error Section OS_CORE0_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_CORE0_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_CORE0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_INTVEC_CORE0_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_INTVEC_CORE0_CONST_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_INTVEC_CORE0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_INTVEC_CORE0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_INTVEC_CORE0_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_INTVEC_CORE0_CONST_UNSPECIFIED_OPEN
#  error Section OS_INTVEC_CORE0_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_INTVEC_CORE0_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_INTVEC_CORE0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_EXCVEC_CORE0_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_EXCVEC_CORE0_CONST_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_EXCVEC_CORE0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_EXCVEC_CORE0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_EXCVEC_CORE0_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_EXCVEC_CORE0_CONST_UNSPECIFIED_OPEN
#  error Section OS_EXCVEC_CORE0_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_EXCVEC_CORE0_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_EXCVEC_CORE0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


/**********************************************************************************************************************
 *  KERNEL VAR SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


#ifdef OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_CORE0_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_CORE0_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_CORE0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_CORE0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_PUBLIC_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_BARRIER_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_BARRIER_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_BARRIER_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_BARRIER_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


/**********************************************************************************************************************
 *  CORESHARED VAR SECTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  APPSHARED VAR SECTIONS
 *********************************************************************************************************************/

/* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */
