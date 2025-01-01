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
 *              File: Os_MemMapInt.h
 *   Generation Time: 2023-04-06 15:03:16
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

                                                                                                                        /* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */

/**********************************************************************************************************************
 *  CODE SECTIONS  (Tasking)
 *********************************************************************************************************************/

#ifdef OS_START_SEC_ERRORHOOK_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_ERRORHOOK_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_ERRORHOOK_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_ERRORHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_ERRORHOOK_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_ERRORHOOK_CODE_OPEN
#  error Section OS_ERRORHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_ERRORHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_ERRORHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OS_COREINITHOOK_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OS_COREINITHOOK_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_OS_COREINITHOOK_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OS_COREINITHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OS_COREINITHOOK_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OS_COREINITHOOK_CODE_OPEN
#  error Section OS_OS_COREINITHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_OS_COREINITHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OS_COREINITHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_PANICHOOK_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_PANICHOOK_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_PANICHOOK_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_PANICHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_PANICHOOK_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_PANICHOOK_CODE_OPEN
#  error Section OS_PANICHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_PANICHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_PANICHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SHUTDOWNHOOK_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SHUTDOWNHOOK_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SHUTDOWNHOOK_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SHUTDOWNHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SHUTDOWNHOOK_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SHUTDOWNHOOK_CODE_OPEN
#  error Section OS_SHUTDOWNHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SHUTDOWNHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SHUTDOWNHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_STARTUPHOOK_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STARTUPHOOK_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_STARTUPHOOK_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_STARTUPHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_STARTUPHOOK_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_STARTUPHOOK_CODE_OPEN
#  error Section OS_STARTUPHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_STARTUPHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_STARTUPHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Default_Init_Task_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Default_Init_Task_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_Default_Init_Task_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Default_Init_Task_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Default_Init_Task_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Default_Init_Task_CODE_OPEN
#  error Section OS_Default_Init_Task_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Default_Init_Task_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Default_Init_Task_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Default_Init_Task_Trusted_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Default_Init_Task_Trusted_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_Default_Init_Task_Trusted_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Default_Init_Task_Trusted_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Default_Init_Task_Trusted_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Default_Init_Task_Trusted_CODE_OPEN
#  error Section OS_Default_Init_Task_Trusted_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Default_Init_Task_Trusted_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Default_Init_Task_Trusted_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_OsTask_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OsTask_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_OsTask_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_OsTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_OsTask_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_OsTask_CODE_OPEN
#  error Section OS_OsTask_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_OsTask_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_OsTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_Ostask_HighPrio_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Ostask_HighPrio_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_Ostask_HighPrio_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_Ostask_HighPrio_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_Ostask_HighPrio_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_Ostask_HighPrio_CODE_OPEN
#  error Section OS_Ostask_HighPrio_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Ostask_HighPrio_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_Ostask_HighPrio_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_vHsmMainFunctionTask_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_vHsmMainFunctionTask_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_vHsmMainFunctionTask_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_vHsmMainFunctionTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_vHsmMainFunctionTask_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_vHsmMainFunctionTask_CODE_OPEN
#  error Section OS_vHsmMainFunctionTask_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_vHsmMainFunctionTask_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_vHsmMainFunctionTask_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_vHsm_Hal_InternalRequestIsr_CODE
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_vHsm_Hal_InternalRequestIsr_CODE_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_vHsm_Hal_InternalRequestIsr_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_vHsm_Hal_InternalRequestIsr_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_vHsm_Hal_InternalRequestIsr_CODE
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_vHsm_Hal_InternalRequestIsr_CODE_OPEN
#  error Section OS_vHsm_Hal_InternalRequestIsr_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_vHsm_Hal_InternalRequestIsr_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_vHsm_Hal_InternalRequestIsr_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_GLOBALSHARED_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


/**********************************************************************************************************************
 *  VAR SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_GLOBALSHARED_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_START_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# pragma section restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# undef OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif


/* PRQA S 0883 */ /* MD_Os_Dir4.10_0883_MemMap */
