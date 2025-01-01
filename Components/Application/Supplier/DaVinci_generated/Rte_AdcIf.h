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
 *             File:  Rte_AdcIf.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <AdcIf>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_ADCIF_H
# define RTE_ADCIF_H

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

# include "Rte_AdcIf_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE) BFE_runExecuteEmergencyBrakingSequence(void); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE) BFE_runExecuteHighPowerStep(void); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE) BFE_runResetMotorStageStatus(void); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_BFE_AC_BELTFUNCTIONEXECUTION_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetPyroActivationStatus(P2VAR(b8PyroActivationStatusType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) pb8PyroActivationStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runSurveyBatteryVoltage(void); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE) SCM_runKL30bgSupervision(u16SampledSignalType u16KL30bgLevel); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SCM_AC_SYSTEMCONTEXTMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_pclPyroDevice_GetPyroActivationStatus(arg1) (BMM_runGetPyroActivationStatus(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclSurveyBatteryVoltage_Monitor() (PMP_runSurveyBatteryVoltage(), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclSynchronousMotorControl_ExecuteEmergencyBrakingSequence() (BFE_runExecuteEmergencyBrakingSequence(), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclSynchronousMotorControl_ExecuteHighPowerStep() (BFE_runExecuteHighPowerStep(), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclSynchronousMotorControl_ResetMotorStageStatus() (BFE_runResetMotorStageStatus(), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclSystemContextSuperviseKL30bg_SuperviseKL30bg(arg1) (SCM_runKL30bgSupervision(arg1), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define AdcIf_START_SEC_CODE
# include "AdcIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_AdcIf_MainFunction AdcIf_MainFunction
#  define RTE_RUNNABLE_AdcIf_runGetHBS_A_V AdcIf_runGetHBS_A_V
#  define RTE_RUNNABLE_AdcIf_runGetHBS_A_V_100ms AdcIf_runGetHBS_A_V_100ms
#  define RTE_RUNNABLE_AdcIf_runGetHBS_A_V_10ms AdcIf_runGetHBS_A_V_10ms
#  define RTE_RUNNABLE_AdcIf_runGetHBS_B_V AdcIf_runGetHBS_B_V
#  define RTE_RUNNABLE_AdcIf_runGetHBS_B_V_100ms AdcIf_runGetHBS_B_V_100ms
#  define RTE_RUNNABLE_AdcIf_runGetHBS_B_V_10ms AdcIf_runGetHBS_B_V_10ms
#  define RTE_RUNNABLE_AdcIf_runGetHS1_V AdcIf_runGetHS1_V
#  define RTE_RUNNABLE_AdcIf_runGetHS1_V_100ms AdcIf_runGetHS1_V_100ms
#  define RTE_RUNNABLE_AdcIf_runGetHS1_V_10ms AdcIf_runGetHS1_V_10ms
#  define RTE_RUNNABLE_AdcIf_runGetHS1_V_20ms AdcIf_runGetHS1_V_20ms
#  define RTE_RUNNABLE_AdcIf_runGetKL30_V AdcIf_runGetKL30_V
#  define RTE_RUNNABLE_AdcIf_runGetKL30_V_100ms AdcIf_runGetKL30_V_100ms
#  define RTE_RUNNABLE_AdcIf_runGetKL30_V_10ms AdcIf_runGetKL30_V_10ms
#  define RTE_RUNNABLE_AdcIf_runGetKL30_V_20ms AdcIf_runGetKL30_V_20ms
#  define RTE_RUNNABLE_AdcIf_runGetKL30_V_2ms AdcIf_runGetKL30_V_2ms
#  define RTE_RUNNABLE_AdcIf_runGetMcu_T_10ms AdcIf_runGetMcu_T_10ms
#  define RTE_RUNNABLE_AdcIf_runGetMotor_In AdcIf_runGetMotor_In
#  define RTE_RUNNABLE_AdcIf_runGetMotor_In_10ms AdcIf_runGetMotor_In_10ms
#  define RTE_RUNNABLE_AdcIf_runGetMotor_Ip AdcIf_runGetMotor_Ip
#  define RTE_RUNNABLE_AdcIf_runGetMotor_Ip_10ms AdcIf_runGetMotor_Ip_10ms
#  define RTE_RUNNABLE_AdcIf_runGetMotor_Vn AdcIf_runGetMotor_Vn
#  define RTE_RUNNABLE_AdcIf_runGetMotor_Vn_100ms AdcIf_runGetMotor_Vn_100ms
#  define RTE_RUNNABLE_AdcIf_runGetMotor_Vn_20ms AdcIf_runGetMotor_Vn_20ms
#  define RTE_RUNNABLE_AdcIf_runGetMotor_Vp AdcIf_runGetMotor_Vp
#  define RTE_RUNNABLE_AdcIf_runGetMotor_Vp_100ms AdcIf_runGetMotor_Vp_100ms
#  define RTE_RUNNABLE_AdcIf_runGetMotor_Vp_20ms AdcIf_runGetMotor_Vp_20ms
#  define RTE_RUNNABLE_AdcIf_runGetRefCpuReg_V AdcIf_runGetRefCpuReg_V
#  define RTE_RUNNABLE_AdcIf_runGetRefHigh_V AdcIf_runGetRefHigh_V
#  define RTE_RUNNABLE_AdcIf_runGetRefLow_V AdcIf_runGetRefLow_V
#  define RTE_RUNNABLE_AdcIf_runGetRefLow_V_100ms AdcIf_runGetRefLow_V_100ms
#  define RTE_RUNNABLE_AdcIf_runGetRefLow_V_10ms AdcIf_runGetRefLow_V_10ms
#  define RTE_RUNNABLE_AdcIf_runGetRefMid_V AdcIf_runGetRefMid_V
# endif

FUNC(void, AdcIf_CODE) AdcIf_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, AdcIf_CODE) AdcIf_runGetHBS_A_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetHBS_A_V_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetHBS_A_V_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetHBS_B_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetHBS_B_V_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetHBS_B_V_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetHS1_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetHS1_V_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetHS1_V_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetHS1_V_20ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetKL30_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetKL30_V_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetKL30_V_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetKL30_V_20ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetKL30_V_2ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetMcu_T_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetMotor_In(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetMotor_In_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetMotor_Ip(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetMotor_Ip_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetMotor_Vn(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetMotor_Vn_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetMotor_Vn_20ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetMotor_Vp(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetMotor_Vp_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetMotor_Vp_20ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetRefCpuReg_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetRefHigh_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetRefLow_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetRefLow_V_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetRefLow_V_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AdcIf_CODE) AdcIf_runGetRefMid_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define AdcIf_STOP_SEC_CODE
# include "AdcIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_ADCIF_H */

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

   MD_Rte_1330:  MISRA rule: Rule8.3
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
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
