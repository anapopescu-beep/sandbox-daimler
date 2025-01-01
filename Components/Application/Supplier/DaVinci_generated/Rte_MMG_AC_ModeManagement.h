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
 *             File:  Rte_MMG_AC_ModeManagement.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <MMG_AC_ModeManagement>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_MMG_AC_MODEMANAGEMENT_H
# define RTE_MMG_AC_MODEMANAGEMENT_H

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

# include "Rte_MMG_AC_ModeManagement_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle0_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle1_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle10_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle11_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle12_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle13_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle14_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle15_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle16_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle17_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle18_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle19_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle2_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle20_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle21_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle22_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle23_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle24_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle25_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle26_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle27_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle28_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle3_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle4_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle5_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle6_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle7_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle8_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle9_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition;
extern VAR(b8IsCarCrankingActiveType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsCarCrankingActive;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8SignalRelInhibition;
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedCycle_u8CycleNumber;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AvailabilityDataHandler_AvailabilityDataCategory (0U)
#  define Rte_InitValue_pclIgnitionStatus_b8TriggerIgnitionStatus (85U)
#  define Rte_InitValue_pclIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition (85U)
#  define Rte_InitValue_prrAECsBlockStatus_b8NVMBlockStatus (85U)
#  define Rte_InitValue_prrCANInputBlockStatus_b8NVMBlockStatus (85U)
#  define Rte_InitValue_prrCustomerSpecific_b8IsCarCrankingActive (170U)
#  define Rte_InitValue_prrCustomerSpecific_b8IsCarCrashDetected (85U)
#  define Rte_InitValue_prrCustomerSpecific_b8PreCrashRequestEnable (85U)
#  define Rte_InitValue_prrCustomerSpecific_u8BeltSlackStatus (2U)
#  define Rte_InitValue_prrCustomerSpecific_u8HapticRequest (8U)
#  define Rte_InitValue_prrCustomerSpecific_u8PreCrashRequest (255U)
#  define Rte_InitValue_prrExecutedCycle_u8CycleNumber (255U)
#  define Rte_InitValue_prrExecutionCountersBlockStatus_b8NVMBlockStatus (85U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Irv_MMG_b8PreSafeRecorder1Update;
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Irv_MMG_b8PreSafeRecorder2Update;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MMG_AC_ModeManagement_prrAECsBlockStatus_b8NVMBlockStatus(P2VAR(b8BooleanType, AUTOMATIC, RTE_MMG_AC_MODEMANAGEMENT_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MMG_AC_ModeManagement_prrCANInputBlockStatus_b8NVMBlockStatus(P2VAR(b8BooleanType, AUTOMATIC, RTE_MMG_AC_MODEMANAGEMENT_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MMG_AC_ModeManagement_prrExecutionCountersBlockStatus_b8NVMBlockStatus(P2VAR(b8BooleanType, AUTOMATIC, RTE_MMG_AC_MODEMANAGEMENT_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MMG_AC_ModeManagement_AvailabilityDataHandler_AvailabilityDataCategory(UInt8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_pclIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition Rte_Read_MMG_AC_ModeManagement_pclIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition
#  define Rte_Read_MMG_AC_ModeManagement_pclIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition(data) (*(data) = Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAECsBlockStatus_b8NVMBlockStatus Rte_Read_MMG_AC_ModeManagement_prrAECsBlockStatus_b8NVMBlockStatus
#  define Rte_Read_prrCANInputBlockStatus_b8NVMBlockStatus Rte_Read_MMG_AC_ModeManagement_prrCANInputBlockStatus_b8NVMBlockStatus
#  define Rte_Read_prrCustomerSpecific_b8IsCarCrankingActive Rte_Read_MMG_AC_ModeManagement_prrCustomerSpecific_b8IsCarCrankingActive
#  define Rte_Read_MMG_AC_ModeManagement_prrCustomerSpecific_b8IsCarCrankingActive(data) (*(data) = Rte_CIL_psrCustomerSpecific_b8IsCarCrankingActive, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrCustomerSpecific_b8SignalRelInhibition Rte_Read_MMG_AC_ModeManagement_prrCustomerSpecific_b8SignalRelInhibition
#  define Rte_Read_MMG_AC_ModeManagement_prrCustomerSpecific_b8SignalRelInhibition(data) (*(data) = Rte_CIL_psrCustomerSpecific_b8SignalRelInhibition, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrExecutedCycle_u8CycleNumber Rte_Read_MMG_AC_ModeManagement_prrExecutedCycle_u8CycleNumber
#  define Rte_Read_MMG_AC_ModeManagement_prrExecutedCycle_u8CycleNumber(data) (*(data) = Rte_BFE_psrExecutedCycle_u8CycleNumber, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrExecutionCountersBlockStatus_b8NVMBlockStatus Rte_Read_MMG_AC_ModeManagement_prrExecutionCountersBlockStatus_b8NVMBlockStatus


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_prrAECsBlockStatus_b8NVMBlockStatus Rte_IsUpdated_MMG_AC_ModeManagement_prrAECsBlockStatus_b8NVMBlockStatus
#  define Rte_IsUpdated_MMG_AC_ModeManagement_prrAECsBlockStatus_b8NVMBlockStatus() (Rte_RxUpdateFlags.Rte_RxUpdate_MMG_prrAECsBlockStatus_b8NVMBlockStatus == 1U)
#  define Rte_IsUpdated_prrCANInputBlockStatus_b8NVMBlockStatus Rte_IsUpdated_MMG_AC_ModeManagement_prrCANInputBlockStatus_b8NVMBlockStatus
#  define Rte_IsUpdated_MMG_AC_ModeManagement_prrCANInputBlockStatus_b8NVMBlockStatus() (Rte_RxUpdateFlags.Rte_RxUpdate_MMG_prrCANInputBlockStatus_b8NVMBlockStatus == 1U)
#  define Rte_IsUpdated_prrExecutionCountersBlockStatus_b8NVMBlockStatus Rte_IsUpdated_MMG_AC_ModeManagement_prrExecutionCountersBlockStatus_b8NVMBlockStatus
#  define Rte_IsUpdated_MMG_AC_ModeManagement_prrExecutionCountersBlockStatus_b8NVMBlockStatus() (Rte_RxUpdateFlags.Rte_RxUpdate_MMG_prrExecutionCountersBlockStatus_b8NVMBlockStatus == 1U)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_AvailabilityDataHandler_AvailabilityDataCategory Rte_Write_MMG_AC_ModeManagement_AvailabilityDataHandler_AvailabilityDataCategory
#  define Rte_Write_psrEnableCycle0_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle0_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle0_b8CycleValidity(data) (Rte_MMG_psrEnableCycle0_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle1_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle1_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle1_b8CycleValidity(data) (Rte_MMG_psrEnableCycle1_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle10_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle10_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle10_b8CycleValidity(data) (Rte_MMG_psrEnableCycle10_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle11_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle11_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle11_b8CycleValidity(data) (Rte_MMG_psrEnableCycle11_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle12_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle12_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle12_b8CycleValidity(data) (Rte_MMG_psrEnableCycle12_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle13_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle13_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle13_b8CycleValidity(data) (Rte_MMG_psrEnableCycle13_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle14_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle14_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle14_b8CycleValidity(data) (Rte_MMG_psrEnableCycle14_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle15_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle15_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle15_b8CycleValidity(data) (Rte_MMG_psrEnableCycle15_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle16_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle16_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle16_b8CycleValidity(data) (Rte_MMG_psrEnableCycle16_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle17_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle17_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle17_b8CycleValidity(data) (Rte_MMG_psrEnableCycle17_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle18_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle18_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle18_b8CycleValidity(data) (Rte_MMG_psrEnableCycle18_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle19_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle19_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle19_b8CycleValidity(data) (Rte_MMG_psrEnableCycle19_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle2_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle2_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle2_b8CycleValidity(data) (Rte_MMG_psrEnableCycle2_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle20_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle20_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle20_b8CycleValidity(data) (Rte_MMG_psrEnableCycle20_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle21_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle21_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle21_b8CycleValidity(data) (Rte_MMG_psrEnableCycle21_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle22_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle22_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle22_b8CycleValidity(data) (Rte_MMG_psrEnableCycle22_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle23_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle23_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle23_b8CycleValidity(data) (Rte_MMG_psrEnableCycle23_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle24_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle24_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle24_b8CycleValidity(data) (Rte_MMG_psrEnableCycle24_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle25_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle25_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle25_b8CycleValidity(data) (Rte_MMG_psrEnableCycle25_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle26_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle26_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle26_b8CycleValidity(data) (Rte_MMG_psrEnableCycle26_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle27_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle27_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle27_b8CycleValidity(data) (Rte_MMG_psrEnableCycle27_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle28_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle28_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle28_b8CycleValidity(data) (Rte_MMG_psrEnableCycle28_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle3_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle3_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle3_b8CycleValidity(data) (Rte_MMG_psrEnableCycle3_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle4_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle4_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle4_b8CycleValidity(data) (Rte_MMG_psrEnableCycle4_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle5_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle5_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle5_b8CycleValidity(data) (Rte_MMG_psrEnableCycle5_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle6_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle6_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle6_b8CycleValidity(data) (Rte_MMG_psrEnableCycle6_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle7_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle7_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle7_b8CycleValidity(data) (Rte_MMG_psrEnableCycle7_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle8_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle8_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle8_b8CycleValidity(data) (Rte_MMG_psrEnableCycle8_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrEnableCycle9_b8CycleValidity Rte_Write_MMG_AC_ModeManagement_psrEnableCycle9_b8CycleValidity
#  define Rte_Write_MMG_AC_ModeManagement_psrEnableCycle9_b8CycleValidity(data) (Rte_MMG_psrEnableCycle9_b8CycleValidity = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ATM_AC_AUTOTESTMANAGER_APPL_CODE) ATM_runGetLastCriticalAutotestId(P2VAR(UInt8, AUTOMATIC, RTE_ATM_AC_AUTOTESTMANAGER_APPL_VAR) u8AutoTestId); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ATM_AC_AUTOTESTMANAGER_APPL_CODE) ATM_runGetTestResult(u8AutoTestIdType u8AutoTestId, P2VAR(u8TestResultType, AUTOMATIC, RTE_ATM_AC_AUTOTESTMANAGER_APPL_VAR) u8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetPyroActivationStatus(P2VAR(b8PyroActivationStatusType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) pb8PyroActivationStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runDisableHBSMonitoring(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runEnableHBSMonitoring(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_runGetInputSignalPresafeRecorderInfo(P2VAR(REC_PreSafeRecInputType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pustPreSafeRecInput); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_SetEnableCondition(uint8 parg0, boolean ConditionFulfilled); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetAecGroupsStatus(P2VAR(u32AecGroupsType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu32AecGroupsStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetAecStatus(u8AecIdentifierType u8AecIdentifier, P2VAR(u8AecStatusType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu8AecStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetNumberOfImplementedAec(P2VAR(UInt8, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu8NbOfAec); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetFilteredTemperature_deg(P2VAR(s16InternalTemperature_deg_Type, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) ps16InternalTemperature_deg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltage(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetDeficiencyLevel(P2VAR(u32DeficiencyLevelType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu32DeficiencyLevel); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltageSurveyStatus(P2VAR(u8BatteryVoltageSurveyStatusType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8BatteryVoltageSurveyStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE) RCM_runGetResetCause(P2VAR(u32ResetCauseType, AUTOMATIC, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_VAR) pu32ResetCause); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE) SCM_runGetLastTensioningState(P2VAR(u8CycleNumberType, AUTOMATIC, RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_VAR) pu8LastExecutedCycle); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE) StbM_GetCurrentTime(StbM_SynchronizedTimeBaseType parg0, P2VAR(StbM_TimeStampType, AUTOMATIC, RTE_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_VAR) timeStampPtr, P2VAR(StbM_UserDataType, AUTOMATIC, RTE_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_VAR) userDataPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_STBM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_GlobalTime_Slave_GTD_BODY3_0_14e64f11_GetCurrentTime(arg1, arg2) (StbM_GetCurrentTime((StbM_SynchronizedTimeBaseType)0, arg1, arg2))
#  define Rte_Call_pclAecStatus_GetAecGroupsStatus(arg1) (ERH_runGetAecGroupsStatus(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAecStatus_GetAecStatus(arg1, arg2) (ERH_runGetAecStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAecStatus_GetNumberOfImplementedAec(arg1) (ERH_runGetNumberOfImplementedAec(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAutotestServices_GetLastCriticalAutotestID(arg1) (ATM_runGetLastCriticalAutotestId(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAutotestServices_GetTestResult(arg1, arg2) (ATM_runGetTestResult(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclECUT_T_GetFiltered_deg(arg1) (PMP_runGetFilteredTemperature_deg(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclEnableCondition1_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)5, arg1))
#  define Rte_Call_pclEnableCondition2_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)3, arg1))
#  define Rte_Call_pclEnableCondition3_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)4, arg1))
#  define Rte_Call_pclEnableCondition4_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)2, arg1))
#  define Rte_Call_pclEnableCondition5_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)1, arg1))
#  define Rte_Call_pclKL30_Get(arg1) (PMP_runGetBatteryVoltage(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_T_GetDeficiencyLevel(arg1) (PMP_runGetDeficiencyLevel(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclNvmServicesAECStatus_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)81, arg1))
#  define Rte_Call_pclNvmServicesAECStatus_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)81, arg1))
#  define Rte_Call_pclNvmServicesCANInputSignals_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)73, arg1))
#  define Rte_Call_pclNvmServicesCANInputSignals_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)73, arg1))
#  define Rte_Call_pclNvmServicesExecutionCounters_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)39, arg1))
#  define Rte_Call_pclNvmServicesExecutionCounters_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)39, arg1))
#  define Rte_Call_pclNvmServicesRecorder1_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)71, arg1))
#  define Rte_Call_pclNvmServicesRecorder1_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)71, arg1))
#  define Rte_Call_pclNvmServicesRecorder2_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)74, arg1))
#  define Rte_Call_pclNvmServicesRecorder2_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)74, arg1))
#  define Rte_Call_pclNvmServicesRecorderID_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)72, arg1))
#  define Rte_Call_pclNvmServicesRecorderID_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)72, arg1))
#  define Rte_Call_pclPreSafeRecInput_GetInputSignals(arg1) (CIL_runGetInputSignalPresafeRecorderInfo(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclPyroDevice_GetPyroActivationStatus(arg1) (BMM_runGetPyroActivationStatus(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclResetCause_GetResetCause(arg1) (RCM_runGetResetCause(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclSurveyBatteryVoltage_GetStatus(arg1) (PMP_runGetBatteryVoltageSurveyStatus(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclSystemContextManagement_GetLastTensionningState(arg1) (SCM_runGetLastTensioningState(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pcl_HBSControl_DisableHBSMonitoring() (BMM_runDisableHBSMonitoring(), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pcl_HBSControl_EnableHBSMonitoring() (BMM_runEnableHBSMonitoring(), ((Std_ReturnType)RTE_E_OK))

/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_MMG_runPreSafeRecorder_b8PreSafeRecorder1Update(data) \
  (Rte_Irv_MMG_b8PreSafeRecorder1Update = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_MMG_runPreSafeRecorder_b8PreSafeRecorder2Update(data) \
  (Rte_Irv_MMG_b8PreSafeRecorder2Update = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_MMG_runUpdateNVMBlocks_b8PreSafeRecorder1Update() \
  Rte_Irv_MMG_b8PreSafeRecorder1Update
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_MMG_runUpdateNVMBlocks_b8PreSafeRecorder2Update() \
  Rte_Irv_MMG_b8PreSafeRecorder2Update
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define MMG_AC_ModeManagement_START_SEC_CODE
# include "MMG_AC_ModeManagement_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_MMG_Init MMG_Init
#  define RTE_RUNNABLE_MMG_runCheckModeStatus MMG_runCheckModeStatus
#  define RTE_RUNNABLE_MMG_runManageModeDelays MMG_runManageModeDelays
#  define RTE_RUNNABLE_MMG_runPreSafeRecorder MMG_runPreSafeRecorder
#  define RTE_RUNNABLE_MMG_runUpdateModeStatus MMG_runUpdateModeStatus
#  define RTE_RUNNABLE_MMG_runUpdateNVMBlocks MMG_runUpdateNVMBlocks
# endif

FUNC(void, MMG_AC_ModeManagement_CODE) MMG_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, MMG_AC_ModeManagement_CODE) MMG_runCheckModeStatus(u32ModeMaskType u32ModesToCheck, P2VAR(u8ModeStatusType, AUTOMATIC, RTE_MMG_AC_MODEMANAGEMENT_APPL_VAR) bModeStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, MMG_AC_ModeManagement_CODE) MMG_runManageModeDelays(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, MMG_AC_ModeManagement_CODE) MMG_runPreSafeRecorder(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, MMG_AC_ModeManagement_CODE) MMG_runUpdateModeStatus(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, MMG_AC_ModeManagement_CODE) MMG_runUpdateNVMBlocks(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define MMG_AC_ModeManagement_STOP_SEC_CODE
# include "MMG_AC_ModeManagement_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_EnableCondition_E_NOT_OK (1U)

#  define RTE_E_EnableCondition_E_OK (0U)

#  define RTE_E_GlobalTime_Slave_GTD_BODY3_0_14e64f11_E_NOT_OK (1U)

#  define RTE_E_GlobalTime_Slave_GTD_BODY3_0_14e64f11_E_OK (0U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_MMG_AC_MODEMANAGEMENT_H */

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
