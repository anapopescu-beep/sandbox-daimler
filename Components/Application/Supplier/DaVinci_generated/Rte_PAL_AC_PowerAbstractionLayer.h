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
 *             File:  Rte_PAL_AC_PowerAbstractionLayer.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <PAL_AC_PowerAbstractionLayer>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_PAL_AC_POWERABSTRACTIONLAYER_H
# define RTE_PAL_AC_POWERABSTRACTIONLAYER_H

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

# include "Rte_PAL_AC_PowerAbstractionLayer_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedCycle_u8CycleNumber;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_prrExecutedCycle_u8CycleNumber (255U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_prrExecutedCycle_u8CycleNumber Rte_Read_PAL_AC_PowerAbstractionLayer_prrExecutedCycle_u8CycleNumber
#  define Rte_Read_PAL_AC_PowerAbstractionLayer_prrExecutedCycle_u8CycleNumber(data) (*(data) = Rte_BFE_psrExecutedCycle_u8CycleNumber, ((Std_ReturnType)RTE_E_OK))


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

FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_In(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_In_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_Ip(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_Ip_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

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

#  define RTE_START_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetFilteredTemperature_deg(P2VAR(s16InternalTemperature_deg_Type, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) ps16InternalTemperature_deg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetLowReferenceVoltage_100ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetLowReferenceVoltage_20ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetHS1Level(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltage_100ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltage_10ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltage_20ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetDeficiencyLevel(P2VAR(u32DeficiencyLevelType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu32DeficiencyLevel); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMotorVn_100ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMotorVn_20ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMotorVp_100ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMotorVp_20ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMotorResistance(u16InternalTemperatureType u16ECUInternalTemperature, P2VAR(u16Resistance_mOhmType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Resistance_mOhm); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltageSurveyStatus(P2VAR(u8BatteryVoltageSurveyStatusType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8BatteryVoltageSurveyStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_PWMIF_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PWMIF_APPL_CODE) PwmIf_DisablePWM(u8PwmChannelIdType arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PWMIF_APPL_CODE) PwmIf_EnablePWM(u8PwmChannelIdType arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PWMIF_APPL_CODE) PwmIf_SetDutyCycle(u8PwmChannelIdType arg, UInt16 arg_1); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PWMIF_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE) SCM_runGetLastTensioningState(P2VAR(u8CycleNumberType, AUTOMATIC, RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_VAR) pu8LastExecutedCycle); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_pclAecStatus_GetAecStatus(arg1, arg2) (ERH_runGetAecStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAutotestServices_GetTestResult(arg1, arg2) (ATM_runGetTestResult(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclECU_T_GetFiltered_deg(arg1) (PMP_runGetFilteredTemperature_deg(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclGND_V_Get_100ms(arg1) (PMP_runGetLowReferenceVoltage_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclGND_V_Get_20ms(arg1) (PMP_runGetLowReferenceVoltage_20ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHS1_V_Get(arg1) (PMP_runGetHS1Level(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_Get_100ms(arg1) (PMP_runGetBatteryVoltage_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_Get_10ms(arg1) (PMP_runGetBatteryVoltage_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_Get_20ms(arg1) (PMP_runGetBatteryVoltage_20ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclModeManagement_CheckModeStatus(arg1, arg2) (MMG_runCheckModeStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_In_raw_Get(arg1) (AdcIf_runGetMotor_In(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_In_raw_Get_10ms(arg1) (AdcIf_runGetMotor_In_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Ip_raw_Get(arg1) (AdcIf_runGetMotor_Ip(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Ip_raw_Get_10ms(arg1) (AdcIf_runGetMotor_Ip_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_T_GetDeficiencyLevel(arg1) (PMP_runGetDeficiencyLevel(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vn_Get_100ms(arg1) (PMP_runGetMotorVn_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vn_Get_20ms(arg1) (PMP_runGetMotorVn_20ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vp_Get_100ms(arg1) (PMP_runGetMotorVp_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vp_Get_20ms(arg1) (PMP_runGetMotorVp_20ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclPwmServices_DisablePWM(arg1) (PwmIf_DisablePWM(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclPwmServices_EnablePWM(arg1) (PwmIf_EnablePWM(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclPwmServices_SetDutyCycle(arg1, arg2) (PwmIf_SetDutyCycle(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclResistance_Get(arg1, arg2) (PMP_runGetMotorResistance(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclSurveyBatteryVoltage_GetStatus(arg1) (PMP_runGetBatteryVoltageSurveyStatus(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclSystemContextManagement_GetLastTensionningState(arg1) (SCM_runGetLastTensioningState(arg1), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define PAL_AC_PowerAbstractionLayer_START_SEC_CODE
# include "PAL_AC_PowerAbstractionLayer_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_PAL_Autotest_CheckCommandConsistency PAL_Autotest_CheckCommandConsistency
#  define RTE_RUNNABLE_PAL_Autotest_CheckHWSelfProtection PAL_Autotest_CheckHWSelfProtection
#  define RTE_RUNNABLE_PAL_Autotest_CheckHighSideSwRegulation PAL_Autotest_CheckHighSideSwRegulation
#  define RTE_RUNNABLE_PAL_Autotest_CheckMosfetHighSC PAL_Autotest_CheckMosfetHighSC
#  define RTE_RUNNABLE_PAL_Autotest_CheckMosfetLowSC PAL_Autotest_CheckMosfetLowSC
#  define RTE_RUNNABLE_PAL_Autotest_CheckMosfetOCAT PAL_Autotest_CheckMosfetOCAT
#  define RTE_RUNNABLE_PAL_Autotest_CheckMotorConnection PAL_Autotest_CheckMotorConnection
#  define RTE_RUNNABLE_PAL_Autotest_CheckMotorCurrent PAL_Autotest_CheckMotorCurrent
#  define RTE_RUNNABLE_PAL_Autotest_CheckMotorDisengagement PAL_Autotest_CheckMotorDisengagement
#  define RTE_RUNNABLE_PAL_Autotest_CheckMotorPowerOrder PAL_Autotest_CheckMotorPowerOrder
#  define RTE_RUNNABLE_PAL_Autotest_CheckMotorSC PAL_Autotest_CheckMotorSC
#  define RTE_RUNNABLE_PAL_Autotest_CheckMotorThermalProctection PAL_Autotest_CheckMotorThermalProctection
#  define RTE_RUNNABLE_PAL_Init PAL_Init
#  define RTE_RUNNABLE_PAL_runGetPWMOrder PAL_runGetPWMOrder
#  define RTE_RUNNABLE_PAL_runMainFunction PAL_runMainFunction
#  define RTE_RUNNABLE_PAL_runReadMotorCurrentInA PAL_runReadMotorCurrentInA
#  define RTE_RUNNABLE_PAL_runReadMotorCurrentInmA PAL_runReadMotorCurrentInmA
#  define RTE_RUNNABLE_PAL_runSetPowerOrder PAL_runSetPowerOrder
# endif

FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_Autotest_CheckCommandConsistency(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_Autotest_CheckHWSelfProtection(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_Autotest_CheckHighSideSwRegulation(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_Autotest_CheckMosfetHighSC(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_Autotest_CheckMosfetLowSC(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_Autotest_CheckMosfetOCAT(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_Autotest_CheckMotorConnection(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_Autotest_CheckMotorCurrent(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_Autotest_CheckMotorDisengagement(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_Autotest_CheckMotorPowerOrder(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_Autotest_CheckMotorSC(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_Autotest_CheckMotorThermalProctection(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_runGetPWMOrder(P2VAR(s16MotorPowerOrderType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) ps16MotorPowerOrder); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_runMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_runReadMotorCurrentInA(P2VAR(s8MotorCurrentInAType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) ps8MotorCurrentInA); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_runReadMotorCurrentInmA(P2VAR(s32MotorCurrentInmAType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) ps32MotorCurrentInmA); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, PAL_AC_PowerAbstractionLayer_CODE) PAL_runSetPowerOrder(s16MotorPowerOrderType s16MotorPowerOrder, u16BoostPWMOrderType u16BoostDutyCycle); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define PAL_AC_PowerAbstractionLayer_STOP_SEC_CODE
# include "PAL_AC_PowerAbstractionLayer_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_PAL_AC_POWERABSTRACTIONLAYER_H */

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
