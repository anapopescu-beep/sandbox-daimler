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
 *              File: Os_MemMap_OsCodeInt.h
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

                                                                                                                        /* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */

/*******  CODE sections  *********************************************************************************************/

#ifdef OS_START_SEC_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CODE_OPEN
#  error Section OS_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */
