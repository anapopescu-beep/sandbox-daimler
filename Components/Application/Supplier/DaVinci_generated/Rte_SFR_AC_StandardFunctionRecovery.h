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
 *             File:  Rte_SFR_AC_StandardFunctionRecovery.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <SFR_AC_StandardFunctionRecovery>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SFR_AC_STANDARDFUNCTIONRECOVERY_H
# define RTE_SFR_AC_STANDARDFUNCTIONRECOVERY_H

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

# include "Rte_SFR_AC_StandardFunctionRecovery_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_BCK_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_BCK_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_BCK_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_HRD_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_HRD_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_HRD_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_PAT_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_PAT_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_PAT_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_SMO_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_SMO_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_SMO_u8TriggeringSource;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_SFR_psrBeltStackAntipatina_b8BeltStack;
extern VAR(b8IsCarAccelerationLowType, RTE_VAR_NOINIT) Rte_CIL_psrCarAcceleration_b8IsCarAccelerationLow;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8HardReleaseRequest;
extern VAR(b8IsCarCrashDetectedType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsCarCrashDetected;
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedCycle_u8CycleNumber;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_prrCarAcceleration_b8IsCarAccelerationLow (170U)
#  define Rte_InitValue_prrCustomerSpecific_b8HardReleaseRequest (85U)
#  define Rte_InitValue_prrCustomerSpecific_b8IsCarCrankingActive (170U)
#  define Rte_InitValue_prrCustomerSpecific_b8IsCarCrashDetected (85U)
#  define Rte_InitValue_prrCustomerSpecific_b8PreCrashRequestEnable (85U)
#  define Rte_InitValue_prrCustomerSpecific_u8BeltSlackStatus (2U)
#  define Rte_InitValue_prrCustomerSpecific_u8HapticRequest (8U)
#  define Rte_InitValue_prrCustomerSpecific_u8PreCrashRequest (255U)
#  define Rte_InitValue_prrExecutedCycle_u8CycleNumber (255U)
#  define Rte_InitValue_psrAlgo_Flags_BCK_b8InterruptFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HRD_b8InterruptFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HRD_b8PreActivationFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HRD_b8PreConditionsFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HRD_b8TriggerFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HRD_u8TriggeringSource (0U)
#  define Rte_InitValue_psrAlgo_Flags_PAT_b8InterruptFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_PAT_b8PreActivationFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_PAT_b8PreConditionsFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_PAT_b8TriggerFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_PAT_u8TriggeringSource (0U)
#  define Rte_InitValue_psrAlgo_Flags_SMO_b8InterruptFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_SMO_b8PreActivationFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_SMO_b8PreConditionsFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_SMO_b8TriggerFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_SMO_u8TriggeringSource (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_prrCarAcceleration_b8IsCarAccelerationLow Rte_Read_SFR_AC_StandardFunctionRecovery_prrCarAcceleration_b8IsCarAccelerationLow
#  define Rte_Read_SFR_AC_StandardFunctionRecovery_prrCarAcceleration_b8IsCarAccelerationLow(data) (*(data) = Rte_CIL_psrCarAcceleration_b8IsCarAccelerationLow, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrCustomerSpecific_b8HardReleaseRequest Rte_Read_SFR_AC_StandardFunctionRecovery_prrCustomerSpecific_b8HardReleaseRequest
#  define Rte_Read_SFR_AC_StandardFunctionRecovery_prrCustomerSpecific_b8HardReleaseRequest(data) (*(data) = Rte_CIL_psrCustomerSpecific_b8HardReleaseRequest, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrCustomerSpecific_b8IsCarCrashDetected Rte_Read_SFR_AC_StandardFunctionRecovery_prrCustomerSpecific_b8IsCarCrashDetected
#  define Rte_Read_SFR_AC_StandardFunctionRecovery_prrCustomerSpecific_b8IsCarCrashDetected(data) (*(data) = Rte_CIL_psrCustomerSpecific_b8IsCarCrashDetected, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrExecutedCycle_u8CycleNumber Rte_Read_SFR_AC_StandardFunctionRecovery_prrExecutedCycle_u8CycleNumber
#  define Rte_Read_SFR_AC_StandardFunctionRecovery_prrExecutedCycle_u8CycleNumber(data) (*(data) = Rte_BFE_psrExecutedCycle_u8CycleNumber, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_psrAlgo_Flags_BCK_b8InterruptFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_BCK_b8InterruptFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_BCK_b8InterruptFlag(data) (Rte_SFR_psrAlgo_Flags_BCK_b8InterruptFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_BCK_b8PreActivationFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_BCK_b8PreActivationFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_BCK_b8PreActivationFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_BCK_b8PreConditionsFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_BCK_b8PreConditionsFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_BCK_b8PreConditionsFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_BCK_b8TriggerFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_BCK_b8TriggerFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_BCK_b8TriggerFlag(data) (Rte_SFR_psrAlgo_Flags_BCK_b8TriggerFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_BCK_u8TriggeringSource Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_BCK_u8TriggeringSource
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_BCK_u8TriggeringSource(data) (Rte_SFR_psrAlgo_Flags_BCK_u8TriggeringSource = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HRD_b8InterruptFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_HRD_b8InterruptFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_HRD_b8InterruptFlag(data) (Rte_SFR_psrAlgo_Flags_HRD_b8InterruptFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HRD_b8PreActivationFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_HRD_b8PreActivationFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_HRD_b8PreActivationFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HRD_b8PreConditionsFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_HRD_b8PreConditionsFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_HRD_b8PreConditionsFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HRD_b8TriggerFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_HRD_b8TriggerFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_HRD_b8TriggerFlag(data) (Rte_SFR_psrAlgo_Flags_HRD_b8TriggerFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HRD_u8TriggeringSource Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_HRD_u8TriggeringSource
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_HRD_u8TriggeringSource(data) (Rte_SFR_psrAlgo_Flags_HRD_u8TriggeringSource = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_PAT_b8InterruptFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_PAT_b8InterruptFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_PAT_b8InterruptFlag(data) (Rte_SFR_psrAlgo_Flags_PAT_b8InterruptFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_PAT_b8PreActivationFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_PAT_b8PreActivationFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_PAT_b8PreActivationFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_PAT_b8PreConditionsFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_PAT_b8PreConditionsFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_PAT_b8PreConditionsFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_PAT_b8TriggerFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_PAT_b8TriggerFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_PAT_b8TriggerFlag(data) (Rte_SFR_psrAlgo_Flags_PAT_b8TriggerFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_PAT_u8TriggeringSource Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_PAT_u8TriggeringSource
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_PAT_u8TriggeringSource(data) (Rte_SFR_psrAlgo_Flags_PAT_u8TriggeringSource = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_SMO_b8InterruptFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_SMO_b8InterruptFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_SMO_b8InterruptFlag(data) (Rte_SFR_psrAlgo_Flags_SMO_b8InterruptFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_SMO_b8PreActivationFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_SMO_b8PreActivationFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_SMO_b8PreActivationFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_SMO_b8PreConditionsFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_SMO_b8PreConditionsFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_SMO_b8PreConditionsFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_SMO_b8TriggerFlag Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_SMO_b8TriggerFlag
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_SMO_b8TriggerFlag(data) (Rte_SFR_psrAlgo_Flags_SMO_b8TriggerFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_SMO_u8TriggeringSource Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_SMO_u8TriggeringSource
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrAlgo_Flags_SMO_u8TriggeringSource(data) (Rte_SFR_psrAlgo_Flags_SMO_u8TriggeringSource = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrBeltStackAntipatina_b8BeltStack Rte_Write_SFR_AC_StandardFunctionRecovery_psrBeltStackAntipatina_b8BeltStack
#  define Rte_Write_SFR_AC_StandardFunctionRecovery_psrBeltStackAntipatina_b8BeltStack(data) (Rte_SFR_psrBeltStackAntipatina_b8BeltStack = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ATM_AC_AUTOTESTMANAGER_APPL_CODE) ATM_runGetTestResult(u8AutoTestIdType u8AutoTestId, P2VAR(u8TestResultType, AUTOMATIC, RTE_ATM_AC_AUTOTESTMANAGER_APPL_VAR) u8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DIA_AC_DIAGONCAN_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runClearDiagRequestCycle(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runGetDiagRequestCycle(P2VAR(u8CycleNumberType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) u8DiagRequestCycle); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DIA_AC_DIAGONCAN_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetAecStatus(u8AecIdentifierType u8AecIdentifier, P2VAR(u8AecStatusType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu8AecStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_MMG_AC_MODEMANAGEMENT_APPL_CODE) MMG_runCheckModeStatus(u32ModeMaskType u32ModesToCheck, P2VAR(u8ModeStatusType, AUTOMATIC, RTE_MMG_AC_MODEMANAGEMENT_APPL_VAR) bModeStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE) SCM_runGetLastTensioningState(P2VAR(u8CycleNumberType, AUTOMATIC, RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_VAR) pu8LastExecutedCycle); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_pclAecStatus_GetAecStatus(arg1, arg2) (ERH_runGetAecStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAutotestServices_GetTestResult(arg1, arg2) (ATM_runGetTestResult(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclDiagRequestCycle_ClearDiagRequestCycle() (DIA_runClearDiagRequestCycle(), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclDiagRequestCycle_GetDiagRequestCycle(arg1) (DIA_runGetDiagRequestCycle(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclEvtInfoHallSensor_GetEventStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclModeManagement_CheckModeStatus(arg1, arg2) (MMG_runCheckModeStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclSystemContextManagement_GetLastTensionningState(arg1) (SCM_runGetLastTensioningState(arg1), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define SFR_AC_StandardFunctionRecovery_START_SEC_CODE
# include "SFR_AC_StandardFunctionRecovery_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_SFR_runStandardFunctionRecovery SFR_runStandardFunctionRecovery
# endif

FUNC(void, SFR_AC_StandardFunctionRecovery_CODE) SFR_runStandardFunctionRecovery(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SFR_AC_StandardFunctionRecovery_STOP_SEC_CODE
# include "SFR_AC_StandardFunctionRecovery_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Dem_ASR42_DiagnosticInfo_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SFR_AC_STANDARDFUNCTIONRECOVERY_H */

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
