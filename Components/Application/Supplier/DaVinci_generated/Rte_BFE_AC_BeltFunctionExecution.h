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
 *             File:  Rte_BFE_AC_BeltFunctionExecution.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <BFE_AC_BeltFunctionExecution>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_BFE_AC_BELTFUNCTIONEXECUTION_H
# define RTE_BFE_AC_BELTFUNCTIONEXECUTION_H

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

# include "Rte_BFE_AC_BeltFunctionExecution_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedCycle_u8CycleNumber;
extern VAR(u8StepNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedStep_u8StepNumber;
extern VAR(b8IsCarAccelerationLowType, RTE_VAR_NOINIT) Rte_PRE_psrTrigOFF_b8IsCarAccelerationLow;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsTrigOffEventAllowed;
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFS_psrSelectedCycle_u8CycleNumber;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_prrCarAcceleration_b8IsCarAccelerationLow (170U)
#  define Rte_InitValue_prrCustomerSpecific_b8IsTrigOffEventAllowed (85U)
#  define Rte_InitValue_prrSelectedCycle_u8CycleNumber (255U)
#  define Rte_InitValue_psrExecutedCycle_u8CycleNumber (255U)
#  define Rte_InitValue_psrExecutedStep_u8StepNumber (255U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(s16MotorPowerOrderType, RTE_VAR_NOINIT) Rte_Irv_BFE_s16MotorPowerOrder;
extern VAR(s32OrderValueType, RTE_VAR_NOINIT) Rte_Irv_BFE_s32FirstOrderValue;
extern VAR(s32OrderValueType, RTE_VAR_NOINIT) Rte_Irv_BFE_s32OrderIncrementValue;
extern VAR(u16StepDurationType, RTE_VAR_NOINIT) Rte_Irv_BFE_u16StepDuration;
extern VAR(u8MotorStageStatusType, RTE_VAR_NOINIT) Rte_Irv_BFE_u8MotorStageStatus;
extern VAR(u8OrdersListType, RTE_VAR_NOINIT) Rte_Irv_BFE_u8OrderType;
extern VAR(u8VelocityTargetType, RTE_VAR_NOINIT) Rte_Irv_BFE_u8VelocityTarget;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/


# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_prrCarAcceleration_b8IsCarAccelerationLow Rte_Read_BFE_AC_BeltFunctionExecution_prrCarAcceleration_b8IsCarAccelerationLow
#  define Rte_Read_BFE_AC_BeltFunctionExecution_prrCarAcceleration_b8IsCarAccelerationLow(data) (*(data) = Rte_PRE_psrTrigOFF_b8IsCarAccelerationLow, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrCustomerSpecific_b8IsTrigOffEventAllowed Rte_Read_BFE_AC_BeltFunctionExecution_prrCustomerSpecific_b8IsTrigOffEventAllowed
#  define Rte_Read_BFE_AC_BeltFunctionExecution_prrCustomerSpecific_b8IsTrigOffEventAllowed(data) (*(data) = Rte_CIL_psrCustomerSpecific_b8IsTrigOffEventAllowed, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrSelectedCycle_u8CycleNumber Rte_Read_BFE_AC_BeltFunctionExecution_prrSelectedCycle_u8CycleNumber
#  define Rte_Read_BFE_AC_BeltFunctionExecution_prrSelectedCycle_u8CycleNumber(data) (*(data) = Rte_BFS_psrSelectedCycle_u8CycleNumber, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_psrExecutedCycle_u8CycleNumber Rte_Write_BFE_AC_BeltFunctionExecution_psrExecutedCycle_u8CycleNumber
#  define Rte_Write_BFE_AC_BeltFunctionExecution_psrExecutedCycle_u8CycleNumber(data) (Rte_BFE_psrExecutedCycle_u8CycleNumber = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrExecutedStep_u8StepNumber Rte_Write_BFE_AC_BeltFunctionExecution_psrExecutedStep_u8StepNumber
#  define Rte_Write_BFE_AC_BeltFunctionExecution_psrExecutedStep_u8StepNumber(data) (Rte_BFE_psrExecutedStep_u8StepNumber = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetPositionFromMinPos_mm(P2VAR(s16BeltPosition_mmType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_mm); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetPositionFromT0_mm(P2VAR(s16BeltPosition_mmType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_mm); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetSpeed_SingleEdge_deg_s(P2VAR(s32BeltSpeed_deg_sType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps32BeltSpeed_SE_deg_s); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetSpeed_mm_s(P2VAR(s32BeltSpeed_mm_sType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps32BeltSpeed_mm_s); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetAecStatus(u8AecIdentifierType u8AecIdentifier, P2VAR(u8AecStatusType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu8AecStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_runReadMotorCurrentInA(P2VAR(s8MotorCurrentInAType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) ps8MotorCurrentInA); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_runReadMotorCurrentInmA(P2VAR(s32MotorCurrentInmAType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) ps32MotorCurrentInmA); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_runSetPowerOrder(s16MotorPowerOrderType s16MotorPowerOrder, u16BoostPWMOrderType u16BoostDutyCycle); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBoardResistance(u16InternalTemperatureType u16ECUInternalTemperature, P2VAR(u16Resistance_mOhmType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Resistance_mOhm); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetFilteredTemperature(P2VAR(u16InternalTemperatureType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16FilteredTemperature); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetFilteredTemperature_deg(P2VAR(s16InternalTemperature_deg_Type, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) ps16InternalTemperature_deg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltage(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltage_10ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltage_2ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMotorResistance(u16InternalTemperatureType u16ECUInternalTemperature, P2VAR(u16Resistance_mOhmType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Resistance_mOhm); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_pclAecStatus_GetAecStatus(arg1, arg2) (ERH_runGetAecStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclBelt_D_GetFromMinPos_mm(arg1) (BMM_runGetPositionFromMinPos_mm(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclBelt_D_GetFromT0_mm(arg1) (BMM_runGetPositionFromT0_mm(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclECU_R_Get(arg1, arg2) (PMP_runGetBoardResistance(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclECU_T_GetFiltered(arg1) (PMP_runGetFilteredTemperature(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclECU_T_GetFiltered_deg(arg1) (PMP_runGetFilteredTemperature_deg(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclEvtInfoHallSensors_GetEventStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclKL30_V_Get(arg1) (PMP_runGetBatteryVoltage(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_Get_10ms(arg1) (PMP_runGetBatteryVoltage_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_Get_2ms(arg1) (PMP_runGetBatteryVoltage_2ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_I_Get_A(arg1) (PAL_runReadMotorCurrentInA(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_I_Get_mA(arg1) (PAL_runReadMotorCurrentInmA(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_P_SetPowerOrder(arg1, arg2) (PAL_runSetPowerOrder(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_R_Get(arg1, arg2) (PMP_runGetMotorResistance(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pseBelt_S_GetSpeed_SingleEdge_deg_s(arg1) (BMM_runGetSpeed_SingleEdge_deg_s(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pseBelt_S_GetSpeed_mm_s(arg1) (BMM_runGetSpeed_mm_s(arg1), ((Std_ReturnType)RTE_E_OK))

/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_BFE_EXCLUSIVE_AREA() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_BFE_EXCLUSIVE_AREA() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runExecuteEmergencyBrakingSequence_s16MotorPowerOrder() \
  Rte_Irv_BFE_s16MotorPowerOrder
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runExecuteEmergencyBrakingSequence_u8MotorStageStatus() \
  Rte_Irv_BFE_u8MotorStageStatus
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_BFE_runExecuteEmergencyBrakingSequence_s16MotorPowerOrder(data) \
  (Rte_Irv_BFE_s16MotorPowerOrder = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_BFE_runExecuteEmergencyBrakingSequence_u8MotorStageStatus(data) \
  (Rte_Irv_BFE_u8MotorStageStatus = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runExecuteHighPowerStep_s16MotorPowerOrder() \
  Rte_Irv_BFE_s16MotorPowerOrder
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runExecuteHighPowerStep_s32FirstOrderValue() \
  Rte_Irv_BFE_s32FirstOrderValue
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runExecuteHighPowerStep_u16StepDuration() \
  Rte_Irv_BFE_u16StepDuration
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runExecuteHighPowerStep_u8MotorStageStatus() \
  Rte_Irv_BFE_u8MotorStageStatus
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runExecuteHighPowerStep_u8OrderType() \
  Rte_Irv_BFE_u8OrderType
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_BFE_runExecuteHighPowerStep_s16MotorPowerOrder(data) \
  (Rte_Irv_BFE_s16MotorPowerOrder = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runExecuteStandardSteps_s16MotorPowerOrder() \
  Rte_Irv_BFE_s16MotorPowerOrder
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runExecuteStandardSteps_s32FirstOrderValue() \
  Rte_Irv_BFE_s32FirstOrderValue
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runExecuteStandardSteps_s32OrderIncrementValue() \
  Rte_Irv_BFE_s32OrderIncrementValue
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runExecuteStandardSteps_u8MotorStageStatus() \
  Rte_Irv_BFE_u8MotorStageStatus
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runExecuteStandardSteps_u8OrderType() \
  Rte_Irv_BFE_u8OrderType
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runExecuteStandardSteps_u8VelocityTarget() \
  Rte_Irv_BFE_u8VelocityTarget
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_BFE_runExecuteStandardSteps_s16MotorPowerOrder(data) \
  (Rte_Irv_BFE_s16MotorPowerOrder = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_BFE_runResetMotorStageStatus_u8MotorStageStatus(data) \
  (Rte_Irv_BFE_u8MotorStageStatus = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runScheduleStep_s16MotorPowerOrder() \
  Rte_Irv_BFE_s16MotorPowerOrder
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runScheduleStep_u8MotorStageStatus() \
  Rte_Irv_BFE_u8MotorStageStatus
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BFE_runScheduleStep_u8OrderType() \
  Rte_Irv_BFE_u8OrderType
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_BFE_runScheduleStep_s32FirstOrderValue(data) \
  (Rte_Irv_BFE_s32FirstOrderValue = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_BFE_runScheduleStep_s32OrderIncrementValue(data) \
  (Rte_Irv_BFE_s32OrderIncrementValue = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_BFE_runScheduleStep_u16StepDuration(data) \
  (Rte_Irv_BFE_u16StepDuration = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_BFE_runScheduleStep_u8OrderType(data) \
  (Rte_Irv_BFE_u8OrderType = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_BFE_runScheduleStep_u8VelocityTarget(data) \
  (Rte_Irv_BFE_u8VelocityTarget = (data))
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define BFE_AC_BeltFunctionExecution_START_SEC_CODE
# include "BFE_AC_BeltFunctionExecution_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BFE_runExecuteEmergencyBrakingSequence BFE_runExecuteEmergencyBrakingSequence
#  define RTE_RUNNABLE_BFE_runExecuteHighPowerStep BFE_runExecuteHighPowerStep
#  define RTE_RUNNABLE_BFE_runExecuteStandardSteps BFE_runExecuteStandardSteps
#  define RTE_RUNNABLE_BFE_runResetMotorStageStatus BFE_runResetMotorStageStatus
#  define RTE_RUNNABLE_BFE_runScheduleStep BFE_runScheduleStep
# endif

FUNC(void, BFE_AC_BeltFunctionExecution_CODE) BFE_runExecuteEmergencyBrakingSequence(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BFE_AC_BeltFunctionExecution_CODE) BFE_runExecuteHighPowerStep(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BFE_AC_BeltFunctionExecution_CODE) BFE_runExecuteStandardSteps(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, BFE_AC_BeltFunctionExecution_CODE) BFE_runResetMotorStageStatus(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BFE_AC_BeltFunctionExecution_CODE) BFE_runScheduleStep(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define BFE_AC_BeltFunctionExecution_STOP_SEC_CODE
# include "BFE_AC_BeltFunctionExecution_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Dem_ASR42_DiagnosticInfo_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_BFE_AC_BELTFUNCTIONEXECUTION_H */

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
