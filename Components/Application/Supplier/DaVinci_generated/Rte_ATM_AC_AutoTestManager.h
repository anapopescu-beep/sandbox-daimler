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
 *             File:  Rte_ATM_AC_AutoTestManager.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <ATM_AC_AutoTestManager>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_ATM_AC_AUTOTESTMANAGER_H
# define RTE_ATM_AC_AUTOTESTMANAGER_H

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

# include "Rte_ATM_AC_AutoTestManager_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_Autotest_CheckHallEffectSensor(P2VAR(u8TestResultType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckImplausibleData_API(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckImplausibleData_Buckle(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckImplausibleData_Ignition(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckImplausibleData_ORC(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckImplausibleData_PowertrainDrv(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckImplausibleData_PowertrainRdy(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckImplausibleData_Presafe(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckSteeringConfiguration(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_Presafe_CheckTimeoutError(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckTimeoutError_API(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckTimeoutError_BeltAdj(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckTimeoutError_BelthandoverL(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckTimeoutError_BelthandoverR(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_Buckle_CheckTimeoutError(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckTimeoutError_Ignition(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckTimeoutError_OdoSpeedometer(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckTimeoutError_Powertrain(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE) CIL_Autotest_CheckVariantCoding(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE) EOL_Autotest_CheckProductEndOfLifeComfort(P2VAR(u8TestResultType, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE) EOL_Autotest_CheckProductEndOfLifeHighForce(P2VAR(u8TestResultType, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE) EOL_Autotest_CheckProductEndOfLifeLowForce(P2VAR(u8TestResultType, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE) EOL_Autotest_CheckProductEndOfLifeMaxForce(P2VAR(u8TestResultType, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetAecDeskillThrs(u8AecIdentifierType u8AecId, P2VAR(UInt16, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu16AecDeskillThrs); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetAecStatus(u8AecIdentifierType u8AecIdentifier, P2VAR(u8AecStatusType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu8AecStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runSetAecEvent(u8AecIdentifierType u8AecIdentifier, u8AecCommandType u8Command); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_MMG_AC_MODEMANAGEMENT_APPL_CODE) MMG_runCheckModeStatus(u32ModeMaskType u32ModesToCheck, P2VAR(u8ModeStatusType, AUTOMATIC, RTE_MMG_AC_MODEMANAGEMENT_APPL_VAR) bModeStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_Autotest_CheckCommandConsistency(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_Autotest_CheckHWSelfProtection(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_Autotest_CheckHighSideSwRegulation(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_Autotest_CheckMosfetHighSC(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_Autotest_CheckMosfetLowSC(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_Autotest_CheckMosfetOCAT(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_Autotest_CheckMotorConnection(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_Autotest_CheckMotorCurrent(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_Autotest_CheckMotorDisengagement(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_Autotest_CheckMotorPowerOrder(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_Autotest_CheckMotorSC(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_Autotest_CheckMotorThermalProctection(P2VAR(u8TestResultType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_Autotest_CheckPowerSupplyOV(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_Autotest_CheckPowerSupplyOVDuringActivation(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_Autotest_CheckPowerSupplyUV(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_Autotest_CheckPowerSupplyUVDuringActivation(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_Autotest_CheckSystemOV(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_Autotest_CheckSystemUV(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_Autotest_CheckTemperatureSensor(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE) RCM_Autotest_RunExtWDTest(P2VAR(u8TestResultType, AUTOMATIC, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE) RCM_Autotest_RunResetCause(P2VAR(u8TestResultType, AUTOMATIC, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SBC_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_SBC_APPL_CODE) SBC_ServiceAutotest_GetTestResult(P2VAR(u8TestResultType, AUTOMATIC, RTE_SBC_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SBC_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_pclAcknowledgeEccError_AcknowledgeEccError(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclAecStatus_GetAecDeskillThrs(arg1, arg2) (ERH_runGetAecDeskillThrs(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAecStatus_GetAecStatus(arg1, arg2) (ERH_runGetAecStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAecStatus_SetAecEvent(arg1, arg2) (ERH_runSetAecEvent(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckAdc_AutotestCallback(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclCheckAdcCalib_AutotestCallback(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclCheckCommandConsistency_AutotestCallback(arg1) (PAL_Autotest_CheckCommandConsistency(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckHWSelfProtection_AutotestCallback(arg1) (PAL_Autotest_CheckHWSelfProtection(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckHallEffectSensor_AutotestCallback(arg1) (BMM_Autotest_CheckHallEffectSensor(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckHighSideSwRegulation_AutotestCallback(arg1) (PAL_Autotest_CheckHighSideSwRegulation(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckImplausibleDataAPI_AutotestCallback(arg1) (CIL_Autotest_CheckImplausibleData_API(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckImplausibleDataBuckle_AutotestCallback(arg1) (CIL_Autotest_CheckImplausibleData_Buckle(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckImplausibleDataIgnition_AutotestCallback(arg1) (CIL_Autotest_CheckImplausibleData_Ignition(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckImplausibleDataORC_AutotestCallback(arg1) (CIL_Autotest_CheckImplausibleData_ORC(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckImplausibleDataPowertrainDrv_AutotestCallback(arg1) (CIL_Autotest_CheckImplausibleData_PowertrainDrv(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckImplausibleDataPowertrainRdy_AutotestCallback(arg1) (CIL_Autotest_CheckImplausibleData_PowertrainRdy(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckImplausibleDataPresafe_AutotestCallback(arg1) (CIL_Autotest_CheckImplausibleData_Presafe(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckLogicalSupplyImplausible_AutotestCallback(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclCheckMosfetHighSC_AutotestCallback(arg1) (PAL_Autotest_CheckMosfetHighSC(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckMosfetLowSC_AutotestCallback(arg1) (PAL_Autotest_CheckMosfetLowSC(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckMosfetOCAT_AutotestCallback(arg1) (PAL_Autotest_CheckMosfetOCAT(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckMotorConnection_AutotestCallback(arg1) (PAL_Autotest_CheckMotorConnection(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckMotorCurrent_AutotestCallback(arg1) (PAL_Autotest_CheckMotorCurrent(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckMotorDisengagement_AutotestCallback(arg1) (PAL_Autotest_CheckMotorDisengagement(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckMotorPowerOrder_AutotestCallback(arg1) (PAL_Autotest_CheckMotorPowerOrder(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckMotorSC_AutotestCallback(arg1) (PAL_Autotest_CheckMotorSC(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckMotorThermalProctection_AutotestCallback(arg1) (PAL_Autotest_CheckMotorThermalProctection(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckPowerSupplyOV_AutotestCallback(arg1) (PMP_Autotest_CheckPowerSupplyOV(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckPowerSupplyOVDuringActivation_AutotestCallback(arg1) (PMP_Autotest_CheckPowerSupplyOVDuringActivation(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckPowerSupplyUV_AutotestCallback(arg1) (PMP_Autotest_CheckPowerSupplyUV(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckPowerSupplyUVDuringActivation_AutotestCallback(arg1) (PMP_Autotest_CheckPowerSupplyUVDuringActivation(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckPreliminaryBoost_AutotestCallback(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclCheckProductEndOfLifeComfort_AutotestCallback(arg1) (EOL_Autotest_CheckProductEndOfLifeComfort(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckProductEndOfLifeHighForce_AutotestCallback(arg1) (EOL_Autotest_CheckProductEndOfLifeHighForce(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckProductEndOfLifeLowForce_AutotestCallback(arg1) (EOL_Autotest_CheckProductEndOfLifeLowForce(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckProductEndOfLifeMaxForce_AutotestCallback(arg1) (EOL_Autotest_CheckProductEndOfLifeMaxForce(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckSteeringConfiguration_AutotestCallback(arg1) (CIL_Autotest_CheckSteeringConfiguration(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckSystemOV_AutotestCallback(arg1) (PMP_Autotest_CheckSystemOV(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckSystemUV_AutotestCallback(arg1) (PMP_Autotest_CheckSystemUV(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckTemperatureSensor_AutotestCallback(arg1) (PMP_Autotest_CheckTemperatureSensor(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckTimeoutError_AutotestCallback(arg1) (CIL_Autotest_Presafe_CheckTimeoutError(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckTimeoutErrorAPI_AutotestCallback(arg1) (CIL_Autotest_CheckTimeoutError_API(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckTimeoutErrorBeltAdj_AutotestCallback(arg1) (CIL_Autotest_CheckTimeoutError_BeltAdj(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckTimeoutErrorBelthandoverL_AutotestCallback(arg1) (CIL_Autotest_CheckTimeoutError_BelthandoverL(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckTimeoutErrorBelthandoverR_AutotestCallback(arg1) (CIL_Autotest_CheckTimeoutError_BelthandoverR(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckTimeoutErrorBuckle_AutotestCallback(arg1) (CIL_Autotest_Buckle_CheckTimeoutError(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckTimeoutErrorIgnition_AutotestCallback(arg1) (CIL_Autotest_CheckTimeoutError_Ignition(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckTimeoutErrorOdoSpeedometer_AutotestCallback(arg1) (CIL_Autotest_CheckTimeoutError_OdoSpeedometer(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckTimeoutErrorPowertrain_AutotestCallback(arg1) (CIL_Autotest_CheckTimeoutError_Powertrain(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclCheckVariantCodining_AutotestCallback(arg1) (CIL_Autotest_CheckVariantCoding(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclGetEccErrorStatus_GetEccError(arg1, arg2) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclModeManagement_CheckModeStatus(arg1, arg2) (MMG_runCheckModeStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclRunEepromMemoryCorruption_AutotestCallback(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclRunEepromMemoryNotProgrammed_AutotestCallback(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclRunExtWatchogTest_AutotestCallback(arg1) (RCM_Autotest_RunExtWDTest(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclRunPFlashMemoryCorruption_AutotestCallback(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclRunRamMemoryCorruption_AutotestCallback(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pclRunResetCause_AutotestCallback(arg1) (RCM_Autotest_RunResetCause(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclRunTFlashMemoryCorruption_AutotestCallback(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_pcs_ServiceAutotest_GetTestResult(arg1) (SBC_ServiceAutotest_GetTestResult(arg1), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define ATM_AC_AutoTestManager_START_SEC_CODE
# include "ATM_AC_AutoTestManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ATM_Init ATM_Init
#  define RTE_RUNNABLE_ATM_runGetLastCriticalAutotestId ATM_runGetLastCriticalAutotestId
#  define RTE_RUNNABLE_ATM_runGetTestResult ATM_runGetTestResult
#  define RTE_RUNNABLE_ATM_runMainFunction ATM_runMainFunction
# endif

FUNC(void, ATM_AC_AutoTestManager_CODE) ATM_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, ATM_AC_AutoTestManager_CODE) ATM_runGetLastCriticalAutotestId(P2VAR(UInt8, AUTOMATIC, RTE_ATM_AC_AUTOTESTMANAGER_APPL_VAR) u8AutoTestId); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ATM_AC_AutoTestManager_CODE) ATM_runGetTestResult(u8AutoTestIdType u8AutoTestId, P2VAR(u8TestResultType, AUTOMATIC, RTE_ATM_AC_AUTOTESTMANAGER_APPL_VAR) u8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ATM_AC_AutoTestManager_CODE) ATM_runMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define ATM_AC_AutoTestManager_STOP_SEC_CODE
# include "ATM_AC_AutoTestManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_ATM_AC_AUTOTESTMANAGER_H */

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
