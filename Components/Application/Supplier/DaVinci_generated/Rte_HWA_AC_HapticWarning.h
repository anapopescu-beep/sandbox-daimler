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
 *             File:  Rte_HWA_AC_HapticWarning.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <HWA_AC_HapticWarning>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_HWA_AC_HAPTICWARNING_H
# define RTE_HWA_AC_HAPTICWARNING_H

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

# include "Rte_HWA_AC_HapticWarning_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA10_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA10_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA10_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA11_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA11_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA11_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA20_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA20_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA20_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA21_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA21_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA21_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA30_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA30_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA30_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA31_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA31_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA31_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA40_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA40_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA40_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA41_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA41_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA41_u8TriggeringSource;
extern VAR(b8IsCarCrankingActiveType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsCarCrankingActive;
extern VAR(b8IsCarCrashDetectedType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsCarCrashDetected;
extern VAR(u8HapticRequestType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_u8HapticRequest;
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedCycle_u8CycleNumber;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_prrBuckleDoorSwitch_u8BuckleSwitch (85U)
#  define Rte_InitValue_prrBuckleDoorSwitch_u8DoorSwitch (255U)
#  define Rte_InitValue_prrCustomerSpecific_b8IsCarCrankingActive (170U)
#  define Rte_InitValue_prrCustomerSpecific_b8IsCarCrashDetected (85U)
#  define Rte_InitValue_prrCustomerSpecific_b8PreCrashRequestEnable (85U)
#  define Rte_InitValue_prrCustomerSpecific_u8BeltSlackStatus (2U)
#  define Rte_InitValue_prrCustomerSpecific_u8HapticRequest (8U)
#  define Rte_InitValue_prrCustomerSpecific_u8PreCrashRequest (255U)
#  define Rte_InitValue_prrExecutedCycle_u8CycleNumber (255U)
#  define Rte_InitValue_psrAlgo_Flags_HWA10_b8InterruptFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA10_b8PreActivationFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA10_b8PreConditionsFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA10_b8TriggerFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA10_u8TriggeringSource (0U)
#  define Rte_InitValue_psrAlgo_Flags_HWA11_b8InterruptFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA11_b8PreActivationFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA11_b8PreConditionsFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA11_b8TriggerFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA11_u8TriggeringSource (0U)
#  define Rte_InitValue_psrAlgo_Flags_HWA20_b8InterruptFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA20_b8PreActivationFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA20_b8PreConditionsFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA20_b8TriggerFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA20_u8TriggeringSource (0U)
#  define Rte_InitValue_psrAlgo_Flags_HWA21_b8InterruptFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA21_b8PreActivationFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA21_b8PreConditionsFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA21_b8TriggerFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA21_u8TriggeringSource (0U)
#  define Rte_InitValue_psrAlgo_Flags_HWA30_b8InterruptFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA30_b8PreActivationFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA30_b8PreConditionsFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA30_b8TriggerFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA30_u8TriggeringSource (0U)
#  define Rte_InitValue_psrAlgo_Flags_HWA31_b8InterruptFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA31_b8PreActivationFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA31_b8PreConditionsFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA31_b8TriggerFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA31_u8TriggeringSource (0U)
#  define Rte_InitValue_psrAlgo_Flags_HWA40_b8InterruptFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA40_b8PreActivationFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA40_b8PreConditionsFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA40_b8TriggerFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA40_u8TriggeringSource (0U)
#  define Rte_InitValue_psrAlgo_Flags_HWA41_b8InterruptFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA41_b8PreActivationFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA41_b8PreConditionsFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA41_b8TriggerFlag (85U)
#  define Rte_InitValue_psrAlgo_Flags_HWA41_u8TriggeringSource (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_prrBuckleDoorSwitch_u8BuckleSwitch Rte_Read_HWA_AC_HapticWarning_prrBuckleDoorSwitch_u8BuckleSwitch

#  define Rte_Read_HWA_AC_HapticWarning_prrBuckleDoorSwitch_u8BuckleSwitch(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrCustomerSpecific_b8IsCarCrankingActive Rte_Read_HWA_AC_HapticWarning_prrCustomerSpecific_b8IsCarCrankingActive
#  define Rte_Read_HWA_AC_HapticWarning_prrCustomerSpecific_b8IsCarCrankingActive(data) (*(data) = Rte_CIL_psrCustomerSpecific_b8IsCarCrankingActive, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrCustomerSpecific_b8IsCarCrashDetected Rte_Read_HWA_AC_HapticWarning_prrCustomerSpecific_b8IsCarCrashDetected
#  define Rte_Read_HWA_AC_HapticWarning_prrCustomerSpecific_b8IsCarCrashDetected(data) (*(data) = Rte_CIL_psrCustomerSpecific_b8IsCarCrashDetected, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrCustomerSpecific_u8HapticRequest Rte_Read_HWA_AC_HapticWarning_prrCustomerSpecific_u8HapticRequest
#  define Rte_Read_HWA_AC_HapticWarning_prrCustomerSpecific_u8HapticRequest(data) (*(data) = Rte_CIL_psrCustomerSpecific_u8HapticRequest, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrExecutedCycle_u8CycleNumber Rte_Read_HWA_AC_HapticWarning_prrExecutedCycle_u8CycleNumber
#  define Rte_Read_HWA_AC_HapticWarning_prrExecutedCycle_u8CycleNumber(data) (*(data) = Rte_BFE_psrExecutedCycle_u8CycleNumber, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_psrAlgo_Flags_HWA10_b8InterruptFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA10_b8InterruptFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA10_b8InterruptFlag(data) (Rte_HWA_psrAlgo_Flags_HWA10_b8InterruptFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA10_b8PreActivationFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA10_b8PreActivationFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA10_b8PreActivationFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA10_b8PreConditionsFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA10_b8PreConditionsFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA10_b8PreConditionsFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA10_b8TriggerFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA10_b8TriggerFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA10_b8TriggerFlag(data) (Rte_HWA_psrAlgo_Flags_HWA10_b8TriggerFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA10_u8TriggeringSource Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA10_u8TriggeringSource
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA10_u8TriggeringSource(data) (Rte_HWA_psrAlgo_Flags_HWA10_u8TriggeringSource = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA11_b8InterruptFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA11_b8InterruptFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA11_b8InterruptFlag(data) (Rte_HWA_psrAlgo_Flags_HWA11_b8InterruptFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA11_b8PreActivationFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA11_b8PreActivationFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA11_b8PreActivationFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA11_b8PreConditionsFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA11_b8PreConditionsFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA11_b8PreConditionsFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA11_b8TriggerFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA11_b8TriggerFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA11_b8TriggerFlag(data) (Rte_HWA_psrAlgo_Flags_HWA11_b8TriggerFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA11_u8TriggeringSource Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA11_u8TriggeringSource
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA11_u8TriggeringSource(data) (Rte_HWA_psrAlgo_Flags_HWA11_u8TriggeringSource = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA20_b8InterruptFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA20_b8InterruptFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA20_b8InterruptFlag(data) (Rte_HWA_psrAlgo_Flags_HWA20_b8InterruptFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA20_b8PreActivationFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA20_b8PreActivationFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA20_b8PreActivationFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA20_b8PreConditionsFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA20_b8PreConditionsFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA20_b8PreConditionsFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA20_b8TriggerFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA20_b8TriggerFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA20_b8TriggerFlag(data) (Rte_HWA_psrAlgo_Flags_HWA20_b8TriggerFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA20_u8TriggeringSource Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA20_u8TriggeringSource
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA20_u8TriggeringSource(data) (Rte_HWA_psrAlgo_Flags_HWA20_u8TriggeringSource = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA21_b8InterruptFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA21_b8InterruptFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA21_b8InterruptFlag(data) (Rte_HWA_psrAlgo_Flags_HWA21_b8InterruptFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA21_b8PreActivationFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA21_b8PreActivationFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA21_b8PreActivationFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA21_b8PreConditionsFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA21_b8PreConditionsFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA21_b8PreConditionsFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA21_b8TriggerFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA21_b8TriggerFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA21_b8TriggerFlag(data) (Rte_HWA_psrAlgo_Flags_HWA21_b8TriggerFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA21_u8TriggeringSource Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA21_u8TriggeringSource
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA21_u8TriggeringSource(data) (Rte_HWA_psrAlgo_Flags_HWA21_u8TriggeringSource = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA30_b8InterruptFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA30_b8InterruptFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA30_b8InterruptFlag(data) (Rte_HWA_psrAlgo_Flags_HWA30_b8InterruptFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA30_b8PreActivationFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA30_b8PreActivationFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA30_b8PreActivationFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA30_b8PreConditionsFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA30_b8PreConditionsFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA30_b8PreConditionsFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA30_b8TriggerFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA30_b8TriggerFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA30_b8TriggerFlag(data) (Rte_HWA_psrAlgo_Flags_HWA30_b8TriggerFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA30_u8TriggeringSource Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA30_u8TriggeringSource
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA30_u8TriggeringSource(data) (Rte_HWA_psrAlgo_Flags_HWA30_u8TriggeringSource = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA31_b8InterruptFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA31_b8InterruptFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA31_b8InterruptFlag(data) (Rte_HWA_psrAlgo_Flags_HWA31_b8InterruptFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA31_b8PreActivationFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA31_b8PreActivationFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA31_b8PreActivationFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA31_b8PreConditionsFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA31_b8PreConditionsFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA31_b8PreConditionsFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA31_b8TriggerFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA31_b8TriggerFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA31_b8TriggerFlag(data) (Rte_HWA_psrAlgo_Flags_HWA31_b8TriggerFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA31_u8TriggeringSource Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA31_u8TriggeringSource
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA31_u8TriggeringSource(data) (Rte_HWA_psrAlgo_Flags_HWA31_u8TriggeringSource = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA40_b8InterruptFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA40_b8InterruptFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA40_b8InterruptFlag(data) (Rte_HWA_psrAlgo_Flags_HWA40_b8InterruptFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA40_b8PreActivationFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA40_b8PreActivationFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA40_b8PreActivationFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA40_b8PreConditionsFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA40_b8PreConditionsFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA40_b8PreConditionsFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA40_b8TriggerFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA40_b8TriggerFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA40_b8TriggerFlag(data) (Rte_HWA_psrAlgo_Flags_HWA40_b8TriggerFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA40_u8TriggeringSource Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA40_u8TriggeringSource
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA40_u8TriggeringSource(data) (Rte_HWA_psrAlgo_Flags_HWA40_u8TriggeringSource = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA41_b8InterruptFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA41_b8InterruptFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA41_b8InterruptFlag(data) (Rte_HWA_psrAlgo_Flags_HWA41_b8InterruptFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA41_b8PreActivationFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA41_b8PreActivationFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA41_b8PreActivationFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA41_b8PreConditionsFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA41_b8PreConditionsFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA41_b8PreConditionsFlag(data) (RTE_E_OK)
#  define Rte_Write_psrAlgo_Flags_HWA41_b8TriggerFlag Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA41_b8TriggerFlag
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA41_b8TriggerFlag(data) (Rte_HWA_psrAlgo_Flags_HWA41_b8TriggerFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrAlgo_Flags_HWA41_u8TriggeringSource Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA41_u8TriggeringSource
#  define Rte_Write_HWA_AC_HapticWarning_psrAlgo_Flags_HWA41_u8TriggeringSource(data) (Rte_HWA_psrAlgo_Flags_HWA41_u8TriggeringSource = (data), ((Std_ReturnType)RTE_E_OK))


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

#  define Rte_Call_pclAecStatus_GetAecStatus(arg1, arg2) (ERH_runGetAecStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAutotestServices_GetTestResult(arg1, arg2) (ATM_runGetTestResult(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclDiagRequestCycle_ClearDiagRequestCycle() (DIA_runClearDiagRequestCycle(), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclDiagRequestCycle_GetDiagRequestCycle(arg1) (DIA_runGetDiagRequestCycle(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclModeManagement_CheckModeStatus(arg1, arg2) (MMG_runCheckModeStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define HWA_AC_HapticWarning_START_SEC_CODE
# include "HWA_AC_HapticWarning_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_HWA_runMainFunction HWA_runMainFunction
# endif

FUNC(void, HWA_AC_HapticWarning_CODE) HWA_runMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define HWA_AC_HapticWarning_STOP_SEC_CODE
# include "HWA_AC_HapticWarning_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_HWA_AC_HAPTICWARNING_H */

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
