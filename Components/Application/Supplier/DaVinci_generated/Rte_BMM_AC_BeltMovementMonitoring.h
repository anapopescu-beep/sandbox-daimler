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
 *             File:  Rte_BMM_AC_BeltMovementMonitoring.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <BMM_AC_BeltMovementMonitoring>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_BMM_AC_BELTMOVEMENTMONITORING_H
# define RTE_BMM_AC_BELTMOVEMENTMONITORING_H

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

# include "Rte_BMM_AC_BeltMovementMonitoring_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

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

FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetHBS_A_V_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetHBS_A_V_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetHBS_B_V_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetHBS_B_V_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

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

#  define Rte_Call_pclAECStatus_GetAecStatus(arg1, arg2) (ERH_runGetAecStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAutotestServices_GetTestResult(arg1, arg2) (ATM_runGetTestResult(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclEvtInfoBatPwrUnderVoltage_GetEventStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclHBS_A_V_raw_Get_100ms(arg1) (AdcIf_runGetHBS_A_V_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHBS_A_V_raw_Get_10ms(arg1) (AdcIf_runGetHBS_A_V_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHBS_B_V_raw_Get_100ms(arg1) (AdcIf_runGetHBS_B_V_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHBS_B_V_raw_Get_10ms(arg1) (AdcIf_runGetHBS_B_V_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclModeManagement_CheckModeStatus(arg1, arg2) (MMG_runCheckModeStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define BMM_AC_BeltMovementMonitoring_START_SEC_CODE
# include "BMM_AC_BeltMovementMonitoring_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BMM_Autotest_CheckHallEffectSensor BMM_Autotest_CheckHallEffectSensor
#  define RTE_RUNNABLE_BMM_runDisableHBSMonitoring BMM_runDisableHBSMonitoring
#  define RTE_RUNNABLE_BMM_runEnableHBSMonitoring BMM_runEnableHBSMonitoring
#  define RTE_RUNNABLE_BMM_runGetPositionFromMinPos_deg BMM_runGetPositionFromMinPos_deg
#  define RTE_RUNNABLE_BMM_runGetPositionFromMinPos_mm BMM_runGetPositionFromMinPos_mm
#  define RTE_RUNNABLE_BMM_runGetPositionFromT0_deg BMM_runGetPositionFromT0_deg
#  define RTE_RUNNABLE_BMM_runGetPositionFromT0_mm BMM_runGetPositionFromT0_mm
#  define RTE_RUNNABLE_BMM_runGetPositionRange_deg BMM_runGetPositionRange_deg
#  define RTE_RUNNABLE_BMM_runGetPositionRange_mm BMM_runGetPositionRange_mm
#  define RTE_RUNNABLE_BMM_runGetPyroActivationStatus BMM_runGetPyroActivationStatus
#  define RTE_RUNNABLE_BMM_runGetSpeed_SingleEdge_deg_s BMM_runGetSpeed_SingleEdge_deg_s
#  define RTE_RUNNABLE_BMM_runGetSpeed_deg_s BMM_runGetSpeed_deg_s
#  define RTE_RUNNABLE_BMM_runGetSpeed_mm_s BMM_runGetSpeed_mm_s
#  define RTE_RUNNABLE_BMM_runInit BMM_runInit
#  define RTE_RUNNABLE_BMM_runMainFunction BMM_runMainFunction
# endif

FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_Autotest_CheckHallEffectSensor(P2VAR(u8TestResultType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runDisableHBSMonitoring(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runEnableHBSMonitoring(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runGetPositionFromMinPos_deg(P2VAR(s16BeltPosition_degType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_deg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runGetPositionFromMinPos_mm(P2VAR(s16BeltPosition_mmType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_mm); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runGetPositionFromT0_deg(P2VAR(s16BeltPosition_degType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_deg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runGetPositionFromT0_mm(P2VAR(s16BeltPosition_mmType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_mm); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runGetPositionRange_deg(P2VAR(s16BeltPosition_degType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_min_deg, P2VAR(s16BeltPosition_degType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_max_deg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runGetPositionRange_mm(P2VAR(s16BeltPosition_mmType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_min_mm, P2VAR(s16BeltPosition_mmType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_max_mm); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runGetPyroActivationStatus(P2VAR(b8PyroActivationStatusType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) pb8PyroActivationStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runGetSpeed_SingleEdge_deg_s(P2VAR(s32BeltSpeed_deg_sType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps32BeltSpeed_SE_deg_s); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runGetSpeed_deg_s(P2VAR(s32BeltSpeed_deg_sType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps32BeltSpeed_deg_s); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runGetSpeed_mm_s(P2VAR(s32BeltSpeed_mm_sType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps32BeltSpeed_mm_s); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runInit(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, BMM_AC_BeltMovementMonitoring_CODE) BMM_runMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define BMM_AC_BeltMovementMonitoring_STOP_SEC_CODE
# include "BMM_AC_BeltMovementMonitoring_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Dem_ASR42_DiagnosticInfo_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_BMM_AC_BELTMOVEMENTMONITORING_H */

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
