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
 *             File:  Rte_SCM_AC_SystemContextManagement.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <SCM_AC_SystemContextManagement>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_H
# define RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_H

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

# include "Rte_SCM_AC_SystemContextManagement_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_SMO_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_HRD_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_BCK_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_PAT_b8InterruptFlag;
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedCycle_u8CycleNumber;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_prrAlgo30_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo30_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo30_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo30_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo30_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo31_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo31_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo31_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo31_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo31_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo32_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo32_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo32_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo32_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo32_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo33_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo33_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo33_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo33_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo33_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrExecutedCycle_u8CycleNumber (255U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_Irv_SCM_u8CurrentTensioningState;
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_Irv_SCM_u8LastTensioningSituation;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_prrAlgo30_Flags_b8InterruptFlag Rte_Read_SCM_AC_SystemContextManagement_prrAlgo30_Flags_b8InterruptFlag
#  define Rte_Read_SCM_AC_SystemContextManagement_prrAlgo30_Flags_b8InterruptFlag(data) (*(data) = Rte_SFR_psrAlgo_Flags_SMO_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo31_Flags_b8InterruptFlag Rte_Read_SCM_AC_SystemContextManagement_prrAlgo31_Flags_b8InterruptFlag
#  define Rte_Read_SCM_AC_SystemContextManagement_prrAlgo31_Flags_b8InterruptFlag(data) (*(data) = Rte_SFR_psrAlgo_Flags_HRD_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo32_Flags_b8InterruptFlag Rte_Read_SCM_AC_SystemContextManagement_prrAlgo32_Flags_b8InterruptFlag
#  define Rte_Read_SCM_AC_SystemContextManagement_prrAlgo32_Flags_b8InterruptFlag(data) (*(data) = Rte_SFR_psrAlgo_Flags_BCK_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo33_Flags_b8InterruptFlag Rte_Read_SCM_AC_SystemContextManagement_prrAlgo33_Flags_b8InterruptFlag
#  define Rte_Read_SCM_AC_SystemContextManagement_prrAlgo33_Flags_b8InterruptFlag(data) (*(data) = Rte_SFR_psrAlgo_Flags_PAT_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrExecutedCycle_u8CycleNumber Rte_Read_SCM_AC_SystemContextManagement_prrExecutedCycle_u8CycleNumber
#  define Rte_Read_SCM_AC_SystemContextManagement_prrExecutedCycle_u8CycleNumber(data) (*(data) = Rte_BFE_psrExecutedCycle_u8CycleNumber, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetPyroActivationStatus(P2VAR(b8PyroActivationStatusType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) pb8PyroActivationStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DIAGFUNCTION_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_DIAGFUNCTION_APPL_CODE) DiagFunction_runReadGlobalTime(P2VAR(stAbsoluteSystemTimeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) pstAbsoluteSystemTime); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DIAGFUNCTION_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetAecStatus(u8AecIdentifierType u8AecIdentifier, P2VAR(u8AecStatusType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu8AecStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runSetAecEvent(u8AecIdentifierType u8AecIdentifier, u8AecCommandType u8Command); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_MMG_AC_MODEMANAGEMENT_APPL_CODE) MMG_runCheckModeStatus(u32ModeMaskType u32ModesToCheck, P2VAR(u8ModeStatusType, AUTOMATIC, RTE_MMG_AC_MODEMANAGEMENT_APPL_VAR) bModeStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetDeficiencyLevel(P2VAR(u32DeficiencyLevelType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu32DeficiencyLevel); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runInitializeDeficiencyLevel(u32DeficiencyLevelType u32DeficiencyLevel); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE) RCM_runGetResetCause(P2VAR(u32ResetCauseType, AUTOMATIC, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_VAR) pu32ResetCause); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE) RCM_runNotifyResetCause(u32ResetReasonNotificationType u32ResetCauseNotification, u32ResetReasonNotificationStatusType u32ResetCauseStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_SYSTEM_CONTEXT_0_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)77))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_0_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)77, arg1))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_0_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)77))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_0_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)77, arg1))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_0_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)77, arg1))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_1_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)78))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_1_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)78, arg1))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_1_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)78))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_1_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)78, arg1))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_1_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)78, arg1))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_2_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)79))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_2_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)79, arg1))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_2_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)79))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_2_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)79, arg1))
#  define Rte_Call_NvMService_SYSTEM_CONTEXT_2_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)79, arg1))
#  define Rte_Call_pclAecStatus_GetAecStatus(arg1, arg2) (ERH_runGetAecStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAecStatus_SetAecEvent(arg1, arg2) (ERH_runSetAecEvent(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclModeManagement_CheckModeStatus(arg1, arg2) (MMG_runCheckModeStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_T_GetDeficiencyLevel(arg1) (PMP_runGetDeficiencyLevel(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_T_InitializeDeficiencyLevel(arg1) (PMP_runInitializeDeficiencyLevel(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclPyroDevice_GetPyroActivationStatus(arg1) (BMM_runGetPyroActivationStatus(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclResetCause_GetResetCause(arg1) (RCM_runGetResetCause(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclResetCauseNotification_NotifyResetCause(arg1, arg2) (RCM_runNotifyResetCause(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclSystemTime_ReadAbsoluteSystemTime(arg1) (DiagFunction_runReadGlobalTime(arg1), ((Std_ReturnType)RTE_E_OK))

/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_SCM_runGetLastTensioningState_u8LastTensioningSituation() \
  Rte_Irv_SCM_u8LastTensioningSituation
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_SCM_runManageSystemContext_u8CurrentTensioningState() \
  Rte_Irv_SCM_u8CurrentTensioningState
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_SCM_runManageSystemContext_u8CurrentTensioningState(data) \
  (Rte_Irv_SCM_u8CurrentTensioningState = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_SCM_runRestoreSystemContext_u8LastTensioningSituation(data) \
  (Rte_Irv_SCM_u8LastTensioningSituation = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_SCM_runRestoreValueSystemContext_u8LastTensioningSituation() \
  Rte_Irv_SCM_u8LastTensioningSituation
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_SCM_runRestoreValueSystemContext_u8LastTensioningSituation(data) \
  (Rte_Irv_SCM_u8LastTensioningSituation = (data))
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define SCM_AC_SystemContextManagement_START_SEC_CODE
# include "SCM_AC_SystemContextManagement_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_SCM_runGetBatteryHysteresisThrs SCM_runGetBatteryHysteresisThrs
#  define RTE_RUNNABLE_SCM_runGetLastTensioningState SCM_runGetLastTensioningState
#  define RTE_RUNNABLE_SCM_runKL30bgSupervision SCM_runKL30bgSupervision
#  define RTE_RUNNABLE_SCM_runManageSystemContext SCM_runManageSystemContext
#  define RTE_RUNNABLE_SCM_runManageSystemContextStorage SCM_runManageSystemContextStorage
#  define RTE_RUNNABLE_SCM_runMonitoreExecutedCycle SCM_runMonitoreExecutedCycle
#  define RTE_RUNNABLE_SCM_runRestoreSystemContext SCM_runRestoreSystemContext
#  define RTE_RUNNABLE_SCM_runRestoreValueSystemContext SCM_runRestoreValueSystemContext
# endif

FUNC(void, SCM_AC_SystemContextManagement_CODE) SCM_runGetBatteryHysteresisThrs(P2VAR(uint16, AUTOMATIC, RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_VAR) pu16BatteryHysteresisThrs); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SCM_AC_SystemContextManagement_CODE) SCM_runGetLastTensioningState(P2VAR(u8CycleNumberType, AUTOMATIC, RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_VAR) pu8LastExecutedCycle); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SCM_AC_SystemContextManagement_CODE) SCM_runKL30bgSupervision(u16SampledSignalType u16KL30bgLevel); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SCM_AC_SystemContextManagement_CODE) SCM_runManageSystemContext(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SCM_AC_SystemContextManagement_CODE) SCM_runManageSystemContextStorage(b8BooleanType b8IsBatteryLoss); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SCM_AC_SystemContextManagement_CODE) SCM_runMonitoreExecutedCycle(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SCM_AC_SystemContextManagement_CODE) SCM_runRestoreSystemContext(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SCM_AC_SystemContextManagement_CODE) SCM_runRestoreValueSystemContext(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SCM_AC_SystemContextManagement_STOP_SEC_CODE
# include "SCM_AC_SystemContextManagement_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_H */

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
