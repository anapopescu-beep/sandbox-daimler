/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_RCM_AC_ResetCauseManagement.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <RCM_AC_ResetCauseManagement>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_RCM_AC_RESETCAUSEMANAGEMENT_H
# define RTE_RCM_AC_RESETCAUSEMANAGEMENT_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_RCM_AC_ResetCauseManagement_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(u32ResetCauseType, RTE_VAR_NOINIT) Rte_Irv_RCM_u8ResetCause;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetAecStatus(u8AecIdentifierType u8AecIdentifier, P2VAR(u8AecStatusType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu8AecStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE) SCM_runManageSystemContextStorage(b8BooleanType b8IsBatteryLoss); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_pclAecStatus_GetAecStatus(arg1, arg2) (ERH_runGetAecStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclNvmServicesWarmReset_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)70, arg1))
#  define Rte_Call_pclStartupSystemContext_ManageSystemContextStorage(arg1) (SCM_runManageSystemContextStorage(arg1), ((Std_ReturnType)RTE_E_OK))

/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_RCM_runConfirmResetCause_u8ResetCause() \
  Rte_Irv_RCM_u8ResetCause
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_RCM_runConfirmResetCause_u8ResetCause(data) \
  (Rte_Irv_RCM_u8ResetCause = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_RCM_runGetResetCause_u8ResetCause() \
  Rte_Irv_RCM_u8ResetCause
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define RCM_AC_ResetCauseManagement_START_SEC_CODE
# include "RCM_AC_ResetCauseManagement_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RCM_Autotest_RunExtWDTest RCM_Autotest_RunExtWDTest
#  define RTE_RUNNABLE_RCM_Autotest_RunResetCause RCM_Autotest_RunResetCause
#  define RTE_RUNNABLE_RCM_runConfirmResetCause RCM_runConfirmResetCause
#  define RTE_RUNNABLE_RCM_runDetermineResetCause RCM_runDetermineResetCause
#  define RTE_RUNNABLE_RCM_runGetResetCause RCM_runGetResetCause
#  define RTE_RUNNABLE_RCM_runGetTestResult RCM_runGetTestResult
#  define RTE_RUNNABLE_RCM_runLaunchExtWdgTest RCM_runLaunchExtWdgTest
#  define RTE_RUNNABLE_RCM_runNotifyResetCause RCM_runNotifyResetCause
# endif

FUNC(void, RCM_AC_ResetCauseManagement_CODE) RCM_Autotest_RunExtWDTest(P2VAR(u8TestResultType, AUTOMATIC, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RCM_AC_ResetCauseManagement_CODE) RCM_Autotest_RunResetCause(P2VAR(u8TestResultType, AUTOMATIC, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RCM_AC_ResetCauseManagement_CODE) RCM_runConfirmResetCause(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, RCM_AC_ResetCauseManagement_CODE) RCM_runDetermineResetCause(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, RCM_AC_ResetCauseManagement_CODE) RCM_runGetResetCause(P2VAR(u32ResetCauseType, AUTOMATIC, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_VAR) pu32ResetCause); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RCM_AC_ResetCauseManagement_CODE) RCM_runGetTestResult(P2VAR(u8WdgTestResultType, AUTOMATIC, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_VAR) pu8WdgTestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RCM_AC_ResetCauseManagement_CODE) RCM_runLaunchExtWdgTest(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RCM_AC_ResetCauseManagement_CODE) RCM_runNotifyResetCause(u32ResetReasonNotificationType u32ResetCauseNotification, u32ResetReasonNotificationStatusType u32ResetCauseStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RCM_AC_ResetCauseManagement_STOP_SEC_CODE
# include "RCM_AC_ResetCauseManagement_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_RCM_AC_RESETCAUSEMANAGEMENT_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
