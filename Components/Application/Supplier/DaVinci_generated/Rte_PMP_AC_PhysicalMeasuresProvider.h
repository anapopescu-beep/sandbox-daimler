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
 *             File:  Rte_PMP_AC_PhysicalMeasuresProvider.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <PMP_AC_PhysicalMeasuresProvider>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_PMP_AC_PHYSICALMEASURESPROVIDER_H
# define RTE_PMP_AC_PHYSICALMEASURESPROVIDER_H

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

# include "Rte_PMP_AC_PhysicalMeasuresProvider_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

#  include "Com.h"


/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_PMP_isrSupBatStatus_b8SupBatStatus;
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_u8TriggerRequest;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_R_PN14_SupBat_Volt_ST3_PN14_SupBat_Volt_ST3 (1023U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(u32DeficiencyLevelType, RTE_VAR_NOINIT) Rte_Irv_PMP_u32DeficiencyLevel;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_PN14_SupBat_Volt_ST3_PN14_SupBat_Volt_ST3 Rte_Read_PMP_AC_PhysicalMeasuresProvider_R_PN14_SupBat_Volt_ST3_PN14_SupBat_Volt_ST3
#  define Rte_Read_PMP_AC_PhysicalMeasuresProvider_R_PN14_SupBat_Volt_ST3_PN14_SupBat_Volt_ST3(data) (Com_ReceiveSignal(ComConf_ComSignal_PN14_SupBat_Volt_ST3_946fd9c6_Rx, (data)))
#  define Rte_Read_prrCustomerSpecific_u8TriggerRequest Rte_Read_PMP_AC_PhysicalMeasuresProvider_prrCustomerSpecific_u8TriggerRequest
#  define Rte_Read_PMP_AC_PhysicalMeasuresProvider_prrCustomerSpecific_u8TriggerRequest(data) (*(data) = Rte_CIL_psrCustomerSpecific_u8TriggerRequest, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_isrSupBatStatus_b8SupBatStatus Rte_Write_PMP_AC_PhysicalMeasuresProvider_isrSupBatStatus_b8SupBatStatus
#  define Rte_Write_PMP_AC_PhysicalMeasuresProvider_isrSupBatStatus_b8SupBatStatus(data) (Rte_PMP_isrSupBatStatus_b8SupBatStatus = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ATM_AC_AUTOTESTMANAGER_APPL_CODE) ATM_runGetTestResult(u8AutoTestIdType u8AutoTestId, P2VAR(u8TestResultType, AUTOMATIC, RTE_ATM_AC_AUTOTESTMANAGER_APPL_VAR) u8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ADCIF_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetHS1_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetKL30_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetKL30_V_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetKL30_V_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetKL30_V_20ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetKL30_V_2ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMcu_T_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_Vn(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_Vn_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_Vn_20ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_Vp(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_Vp_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_Vp_20ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetRefCpuReg_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetRefHigh_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetRefLow_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetRefMid_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ADCIF_APPL_CODE
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

#  define RTE_START_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_runReadMotorCurrentInA(P2VAR(s8MotorCurrentInAType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) ps8MotorCurrentInA); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_pclAecStatus_GetAecStatus(arg1, arg2) (ERH_runGetAecStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAutotestServices_GetTestResult(arg1, arg2) (ATM_runGetTestResult(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHS1_V_raw_Get(arg1) (AdcIf_runGetHS1_V(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_raw_Get(arg1) (AdcIf_runGetKL30_V(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_raw_Get_100ms(arg1) (AdcIf_runGetKL30_V_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_raw_Get_10ms(arg1) (AdcIf_runGetKL30_V_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_raw_Get_20ms(arg1) (AdcIf_runGetKL30_V_20ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_raw_Get_2ms(arg1) (AdcIf_runGetKL30_V_2ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMcu_T_raw_Get_10ms(arg1) (AdcIf_runGetMcu_T_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclModeManagement_CheckModeStatus(arg1, arg2) (MMG_runCheckModeStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_I_Get_A(arg1) (PAL_runReadMotorCurrentInA(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vn_raw_Get(arg1) (AdcIf_runGetMotor_Vn(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vn_raw_Get_100ms(arg1) (AdcIf_runGetMotor_Vn_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vn_raw_Get_20ms(arg1) (AdcIf_runGetMotor_Vn_20ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vp_raw_Get(arg1) (AdcIf_runGetMotor_Vp(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vp_raw_Get_100ms(arg1) (AdcIf_runGetMotor_Vp_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vp_raw_Get_20ms(arg1) (AdcIf_runGetMotor_Vp_20ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclREFCpuReg_V_Raw_Get(arg1) (AdcIf_runGetRefCpuReg_V(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclREFHigh_V_raw_Get(arg1) (AdcIf_runGetRefHigh_V(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclREFLow_V_raw_Get(arg1) (AdcIf_runGetRefLow_V(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclREFMid_V_raw_Get(arg1) (AdcIf_runGetRefMid_V(arg1), ((Std_ReturnType)RTE_E_OK))

/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_PMP_runComputeDeficiencyLevel_u32DeficiencyLevel() \
  Rte_Irv_PMP_u32DeficiencyLevel
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_PMP_runComputeDeficiencyLevel_u32DeficiencyLevel(data) \
  (Rte_Irv_PMP_u32DeficiencyLevel = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_PMP_runGetDeficiencyLevel_u32DeficiencyLevel() \
  Rte_Irv_PMP_u32DeficiencyLevel
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_PMP_runInitializeDeficiencyLevel_u32DeficiencyLevel(data) \
  (Rte_Irv_PMP_u32DeficiencyLevel = (data))
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define PMP_AC_PhysicalMeasuresProvider_START_SEC_CODE
# include "PMP_AC_PhysicalMeasuresProvider_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_PMP_Autotest_CheckPowerSupplyOV PMP_Autotest_CheckPowerSupplyOV
#  define RTE_RUNNABLE_PMP_Autotest_CheckPowerSupplyOVDuringActivation PMP_Autotest_CheckPowerSupplyOVDuringActivation
#  define RTE_RUNNABLE_PMP_Autotest_CheckPowerSupplyUV PMP_Autotest_CheckPowerSupplyUV
#  define RTE_RUNNABLE_PMP_Autotest_CheckPowerSupplyUVDuringActivation PMP_Autotest_CheckPowerSupplyUVDuringActivation
#  define RTE_RUNNABLE_PMP_Autotest_CheckSystemOV PMP_Autotest_CheckSystemOV
#  define RTE_RUNNABLE_PMP_Autotest_CheckSystemUV PMP_Autotest_CheckSystemUV
#  define RTE_RUNNABLE_PMP_Autotest_CheckTemperatureSensor PMP_Autotest_CheckTemperatureSensor
#  define RTE_RUNNABLE_PMP_Init PMP_Init
#  define RTE_RUNNABLE_PMP_runComputeDeficiencyLevel PMP_runComputeDeficiencyLevel
#  define RTE_RUNNABLE_PMP_runGetBatteryVoltage PMP_runGetBatteryVoltage
#  define RTE_RUNNABLE_PMP_runGetBatteryVoltageSurveyStatus PMP_runGetBatteryVoltageSurveyStatus
#  define RTE_RUNNABLE_PMP_runGetBatteryVoltage_100ms PMP_runGetBatteryVoltage_100ms
#  define RTE_RUNNABLE_PMP_runGetBatteryVoltage_10ms PMP_runGetBatteryVoltage_10ms
#  define RTE_RUNNABLE_PMP_runGetBatteryVoltage_20ms PMP_runGetBatteryVoltage_20ms
#  define RTE_RUNNABLE_PMP_runGetBatteryVoltage_2ms PMP_runGetBatteryVoltage_2ms
#  define RTE_RUNNABLE_PMP_runGetBoardResistance PMP_runGetBoardResistance
#  define RTE_RUNNABLE_PMP_runGetCpuRegulatorVoltage PMP_runGetCpuRegulatorVoltage
#  define RTE_RUNNABLE_PMP_runGetDeficiencyLevel PMP_runGetDeficiencyLevel
#  define RTE_RUNNABLE_PMP_runGetFilteredTemperature PMP_runGetFilteredTemperature
#  define RTE_RUNNABLE_PMP_runGetFilteredTemperature_deg PMP_runGetFilteredTemperature_deg
#  define RTE_RUNNABLE_PMP_runGetHS1Level PMP_runGetHS1Level
#  define RTE_RUNNABLE_PMP_runGetHighReferenceVoltage PMP_runGetHighReferenceVoltage
#  define RTE_RUNNABLE_PMP_runGetLowReferenceVoltage PMP_runGetLowReferenceVoltage
#  define RTE_RUNNABLE_PMP_runGetLowReferenceVoltage_100ms PMP_runGetLowReferenceVoltage_100ms
#  define RTE_RUNNABLE_PMP_runGetLowReferenceVoltage_20ms PMP_runGetLowReferenceVoltage_20ms
#  define RTE_RUNNABLE_PMP_runGetMidReferenceVoltage PMP_runGetMidReferenceVoltage
#  define RTE_RUNNABLE_PMP_runGetMotorResistance PMP_runGetMotorResistance
#  define RTE_RUNNABLE_PMP_runGetMotorVn PMP_runGetMotorVn
#  define RTE_RUNNABLE_PMP_runGetMotorVn_100ms PMP_runGetMotorVn_100ms
#  define RTE_RUNNABLE_PMP_runGetMotorVn_20ms PMP_runGetMotorVn_20ms
#  define RTE_RUNNABLE_PMP_runGetMotorVp PMP_runGetMotorVp
#  define RTE_RUNNABLE_PMP_runGetMotorVp_100ms PMP_runGetMotorVp_100ms
#  define RTE_RUNNABLE_PMP_runGetMotorVp_20ms PMP_runGetMotorVp_20ms
#  define RTE_RUNNABLE_PMP_runInitializeDeficiencyLevel PMP_runInitializeDeficiencyLevel
#  define RTE_RUNNABLE_PMP_runSurveyBatteryVoltage PMP_runSurveyBatteryVoltage
# endif

FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_Autotest_CheckPowerSupplyOV(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_Autotest_CheckPowerSupplyOVDuringActivation(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_Autotest_CheckPowerSupplyUV(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_Autotest_CheckPowerSupplyUVDuringActivation(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_Autotest_CheckSystemOV(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_Autotest_CheckSystemUV(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_Autotest_CheckTemperatureSensor(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runComputeDeficiencyLevel(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetBatteryVoltage(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetBatteryVoltageSurveyStatus(P2VAR(u8BatteryVoltageSurveyStatusType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8BatteryVoltageSurveyStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetBatteryVoltage_100ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetBatteryVoltage_10ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetBatteryVoltage_20ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetBatteryVoltage_2ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetBoardResistance(u16InternalTemperatureType u16ECUInternalTemperature, P2VAR(u16Resistance_mOhmType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Resistance_mOhm); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetCpuRegulatorVoltage(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetDeficiencyLevel(P2VAR(u32DeficiencyLevelType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu32DeficiencyLevel); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetFilteredTemperature(P2VAR(u16InternalTemperatureType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16FilteredTemperature); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetFilteredTemperature_deg(P2VAR(s16InternalTemperature_deg_Type, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) ps16InternalTemperature_deg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetHS1Level(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetHighReferenceVoltage(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetLowReferenceVoltage(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetLowReferenceVoltage_100ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetLowReferenceVoltage_20ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetMidReferenceVoltage(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetMotorResistance(u16InternalTemperatureType u16ECUInternalTemperature, P2VAR(u16Resistance_mOhmType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Resistance_mOhm); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetMotorVn(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetMotorVn_100ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetMotorVn_20ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetMotorVp(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetMotorVp_100ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runGetMotorVp_20ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runInitializeDeficiencyLevel(u32DeficiencyLevelType u32DeficiencyLevel); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PMP_AC_PhysicalMeasuresProvider_CODE) PMP_runSurveyBatteryVoltage(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define PMP_AC_PhysicalMeasuresProvider_STOP_SEC_CODE
# include "PMP_AC_PhysicalMeasuresProvider_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_PMP_AC_PHYSICALMEASURESPROVIDER_H */

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
