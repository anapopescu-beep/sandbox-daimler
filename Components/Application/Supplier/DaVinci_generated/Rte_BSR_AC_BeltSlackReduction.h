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
 *             File:  Rte_BSR_AC_BeltSlackReduction.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <BSR_AC_BeltSlackReduction>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_BSR_AC_BELTSLACKREDUCTION_H
# define RTE_BSR_AC_BELTSLACKREDUCTION_H

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

# include "Rte_BSR_AC_BeltSlackReduction_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_b8PreActivationFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_b8PreConditionsFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_u8TriggeringSource;
extern VAR(u8lBuckleSwitchStatusType, RTE_VAR_NOINIT) Rte_CIL_psrBuckleDoorSwitch_u8BuckleSwitch;
extern VAR(b8IsCarCrashDetectedType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsCarCrashDetected;
extern VAR(u8BeltSlackStatusType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_u8BeltSlackStatus;
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedCycle_u8CycleNumber;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_prrBuckleDoorSwitch_u8BuckleSwitch (255U)
#  define Rte_InitValue_prrBuckleDoorSwitch_u8DoorSwitch (255U)
#  define Rte_InitValue_prrCustomerSpecific_b8IsCarCrankingActive (170U)
#  define Rte_InitValue_prrCustomerSpecific_b8IsCarCrashDetected (85U)
#  define Rte_InitValue_prrCustomerSpecific_b8PreCrashRequestEnable (85U)
#  define Rte_InitValue_prrCustomerSpecific_u8BeltSlackStatus (2U)
#  define Rte_InitValue_prrCustomerSpecific_u8HapticRequest (8U)
#  define Rte_InitValue_prrCustomerSpecific_u8PreCrashRequest (255U)
#  define Rte_InitValue_prrDriverControls_b8VehicleMovingBackwards (85U)
#  define Rte_InitValue_prrDriverControls_s16AccelerationPedalPositionRate (0)
#  define Rte_InitValue_prrDriverControls_s16BrakePressureRate (0)
#  define Rte_InitValue_prrDriverControls_s16HWAngle (0)
#  define Rte_InitValue_prrDriverControls_s16HWRate (0)
#  define Rte_InitValue_prrDriverControls_u16BrakePressure (0U)
#  define Rte_InitValue_prrDriverControls_u16VehicleSpeed (0U)
#  define Rte_InitValue_prrDriverControls_u8AccelerationPedalPosition (0U)
#  define Rte_InitValue_prrDriverControls_u8KlemmenStatus (0U)
#  define Rte_InitValue_prrExecutedCycle_u8CycleNumber (255U)
#  define Rte_InitValue_psrAlgo_Flags_BSR_b8InterruptFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_BSR_b8PreActivationFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_BSR_b8PreConditionsFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_BSR_b8TriggerFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_BSR_u8TriggeringSource (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_prrBuckleDoorSwitch_u8BuckleSwitch Rte_Read_BSR_AC_BeltSlackReduction_prrBuckleDoorSwitch_u8BuckleSwitch
#  define Rte_Read_BSR_AC_BeltSlackReduction_prrBuckleDoorSwitch_u8BuckleSwitch(data) (*(data) = Rte_CIL_psrBuckleDoorSwitch_u8BuckleSwitch, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrCustomerSpecific_b8IsCarCrashDetected Rte_Read_BSR_AC_BeltSlackReduction_prrCustomerSpecific_b8IsCarCrashDetected
#  define Rte_Read_BSR_AC_BeltSlackReduction_prrCustomerSpecific_b8IsCarCrashDetected(data) (*(data) = Rte_CIL_psrCustomerSpecific_b8IsCarCrashDetected, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrCustomerSpecific_u8BeltSlackStatus Rte_Read_BSR_AC_BeltSlackReduction_prrCustomerSpecific_u8BeltSlackStatus
#  define Rte_Read_BSR_AC_BeltSlackReduction_prrCustomerSpecific_u8BeltSlackStatus(data) (*(data) = Rte_CIL_psrCustomerSpecific_u8BeltSlackStatus, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrDriverControls_u16VehicleSpeed Rte_Read_BSR_AC_BeltSlackReduction_prrDriverControls_u16VehicleSpeed

#  define Rte_Read_BSR_AC_BeltSlackReduction_prrDriverControls_u16VehicleSpeed(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrExecutedCycle_u8CycleNumber Rte_Read_BSR_AC_BeltSlackReduction_prrExecutedCycle_u8CycleNumber
#  define Rte_Read_BSR_AC_BeltSlackReduction_prrExecutedCycle_u8CycleNumber(data) (*(data) = Rte_BFE_psrExecutedCycle_u8CycleNumber, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_psrAlgo_Flags_BSR_b8InterruptFlag Rte_Write_BSR_AC_BeltSlackReduction_psrAlgo_Flags_BSR_b8InterruptFlag
#  define Rte_Write_BSR_AC_BeltSlackReduction_psrAlgo_Flags_BSR_b8InterruptFlag(data) (Rte_BSR_psrAlgo_Flags_BSR_b8InterruptFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_BSR_b8PreActivationFlag Rte_Write_BSR_AC_BeltSlackReduction_psrAlgo_Flags_BSR_b8PreActivationFlag
#  define Rte_Write_BSR_AC_BeltSlackReduction_psrAlgo_Flags_BSR_b8PreActivationFlag(data) (Rte_BSR_psrAlgo_Flags_BSR_b8PreActivationFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_BSR_b8PreConditionsFlag Rte_Write_BSR_AC_BeltSlackReduction_psrAlgo_Flags_BSR_b8PreConditionsFlag
#  define Rte_Write_BSR_AC_BeltSlackReduction_psrAlgo_Flags_BSR_b8PreConditionsFlag(data) (Rte_BSR_psrAlgo_Flags_BSR_b8PreConditionsFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_BSR_b8TriggerFlag Rte_Write_BSR_AC_BeltSlackReduction_psrAlgo_Flags_BSR_b8TriggerFlag
#  define Rte_Write_BSR_AC_BeltSlackReduction_psrAlgo_Flags_BSR_b8TriggerFlag(data) (Rte_BSR_psrAlgo_Flags_BSR_b8TriggerFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_BSR_u8TriggeringSource Rte_Write_BSR_AC_BeltSlackReduction_psrAlgo_Flags_BSR_u8TriggeringSource
#  define Rte_Write_BSR_AC_BeltSlackReduction_psrAlgo_Flags_BSR_u8TriggeringSource(data) (Rte_BSR_psrAlgo_Flags_BSR_u8TriggeringSource = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ATM_AC_AUTOTESTMANAGER_APPL_CODE) ATM_runGetTestResult(u8AutoTestIdType u8AutoTestId, P2VAR(u8TestResultType, AUTOMATIC, RTE_ATM_AC_AUTOTESTMANAGER_APPL_VAR) u8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetPositionFromT0_deg(P2VAR(s16BeltPosition_degType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_deg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
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

#  define Rte_Call_pclAecStatus_GetAecStatus(arg1, arg2) (ERH_runGetAecStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAutotestServices_GetTestResult(arg1, arg2) (ATM_runGetTestResult(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclBelt_D_GetFromT0_deg(arg1) (BMM_runGetPositionFromT0_deg(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclDiagRequestCycle_ClearDiagRequestCycle() (DIA_runClearDiagRequestCycle(), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclDiagRequestCycle_GetDiagRequestCycle(arg1) (DIA_runGetDiagRequestCycle(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclEvtInfoBatPwrOverVoltage_GetEventStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclEvtInfoBatPwrUnderVoltageDuringTens_GetEventStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclEvtInfoComfortEndOfLife_GetEventStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclModeManagement_CheckModeStatus(arg1, arg2) (MMG_runCheckModeStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define BSR_AC_BeltSlackReduction_START_SEC_CODE
# include "BSR_AC_BeltSlackReduction_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BSR_runBeltSlackReductionAlgo BSR_runBeltSlackReductionAlgo
# endif

FUNC(void, BSR_AC_BeltSlackReduction_CODE) BSR_runBeltSlackReductionAlgo(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define BSR_AC_BeltSlackReduction_STOP_SEC_CODE
# include "BSR_AC_BeltSlackReduction_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Dem_ASR42_DiagnosticInfo_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_BSR_AC_BELTSLACKREDUCTION_H */

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
