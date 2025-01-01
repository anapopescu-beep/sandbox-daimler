/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

 *******************************************************************************
C-File Template Version:
Template version: AEM_PROCESS_1.17.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2021-10
 ******************************************************************************/
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.1.4.1.6.3.38 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/ATM/Implementation/src/project.pj $
 */
/**
 *  @defgroup TEMPLATE_FILES_Group_Example Group_Example_Name_In_Document
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */
/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "common.h"
#include "Rte_ATM_AC_AutoTestManager.h"
#include "ATM_public.h"
#include "ATM_private.h"

/*************************************************************************
Declaration of macros
 *************************************************************************/
/*************************************************************************
LOCAL variables declaration
 *************************************************************************/

/*************************************************************************
LOCAL constant data declaration
 **************************************************************************/
/* Main timing Auto tests parameters macros, to be used in "castATMConfig" definition
  (considering the ATM main function execution period is 2ms) */
/**
 * \brief
 *    Main timing (10 ms) Auto tests manager parameters macros, to be used in "castATMConfig" definition
 */
#define  KU8_ATM_PERIODIC_10_MS                 (uint16)1u, (uint8)0u
/**
 * \brief
 *    Main timing (100 ms) Auto tests manager parameters macros, to be used in "castATMConfig" definition
 */
#define  KU8_ATM_PERIODIC_200_MS(decade)         (uint16)20u, (decade)
/**
 * \brief
 *     Main timing (100 ms) of ECU_KNOCKOUT_TIMEOUT Auto test, to be used in ATM_cbk_CheckEcuKnockout_Timeout function
 */
#define  KU8_ATM_PERIODIC_100_MS(decade)        (uint16)10u, (decade)
/**
 * \brief
 *    Main timing (10 ms) Auto tests manager parameters macros, to be used in "castATMConfig" definition
 */
#define  KU8_ATM_PERIODIC_500_MS(decade)        (uint16)50u, (decade)
/**
 * \brief
 *    Main timing (1 s) Auto tests manager parameters macros, to be used in "castATMConfig" definition
 */
#define  KU8_ATM_PERIODIC_1_S(decade)           (uint16)100u, (decade)
/**
 * \brief
 *    Delimiter used between lists. Indicates to the ATM main function to continue with its current indexes.
 */
#define  KU8_END_OF_SUB_LIST                    (uint16)0, (uint8)1, (uint8)0
/**
 * \brief
 *    Delimiter used to terminate the  list. Indicates to the ATM main function to loop back to the first list and reset all its indexes.
 */
#define  KU8_END_OF_THE_WHOLE_LIST              (uint16)0, (uint8)0, (uint8)0
/**
 * \brief
 *     The autotest is periodically called until its result is OK or NOK. It is considered as finished only when its result is OK or NOK.
 */
#define  KU8_ATM_ONE_SHOT_ABORT(step_period)    (step_period), KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_ABORT
/**
 * \brief
 *     The autotest is periodically called until its result is OK. It is considered as finished only when its result is OK.
 */
#define  KU8_ATM_ONE_SHOT_RETRY(step_period)    (step_period), KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_RETRY
/**
 * \brief
 *     The autotest is called only once and it is considered as finished whatever its result is : OK, NOK, NotDecided
 */
#define  KU8_ATM_ONE_SHOT(step_period)          (step_period), KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT
/**
 * \brief
 *     The autotest is periodically called until its result is OK, NOK or NOT DECIDED. It is considered as finished only when its result is OK,  NOK or NOT DECIDED.
 */
#define  KU8_ATM_ONE_SHOT_DECIDED(step_period)  (step_period), KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_DECIDED

/* 'decade' argument value for macro above */
/**
 * \brief
 *     Decade used for macros - example: KU8_ATM_PERIODIC_100_MS(decade)
 */
#define  IN_DECADE_0                     ((uint8)0)
/**
 * \brief
 *     Decade used for macros - example: KU8_ATM_PERIODIC_100_MS(decade)
 */
#define  IN_DECADE_1                     ((uint8)1)
/**
 * \brief
 *     Decade used for macros - example: KU8_ATM_PERIODIC_100_MS(decade)
 */
#define  IN_DECADE_2                     ((uint8)2)
/**
 * \brief
 *     Decade used for macros - example: KU8_ATM_PERIODIC_100_MS(decade)
 */
#define  IN_DECADE_3                     ((uint8)3)
/**
 * \brief
 *     Decade used for macros - example: KU8_ATM_PERIODIC_100_MS(decade)
 */
#define  IN_DECADE_4                     ((uint8)4)
/**
 * \brief
 *     Decade used for macros - example: KU8_ATM_PERIODIC_100_MS(decade)
 */
#define  IN_DECADE_5                     ((uint8)5)
/**
 * \brief
 *     Decade used for macros - example: KU8_ATM_PERIODIC_100_MS(decade)
 */
#define  IN_DECADE_6                     ((uint8)6)
/**
 * \brief
 *     Decade used for macros - example: KU8_ATM_PERIODIC_100_MS(decade)
 */
#define  IN_DECADE_7                     ((uint8)7)
/**
 * \brief
 *     Decade used for macros - example: KU8_ATM_PERIODIC_100_MS(decade)
 */
#define  IN_DECADE_8                     ((uint8)8)
/**
 * \brief
 *     Decade used for macros - example: KU8_ATM_PERIODIC_100_MS(decade)
 */
#define  IN_DECADE_9                     ((uint8)9)

/* 'decade' argument value for macro above */
/**
 * \brief
 *     Decade argument value for macro
 */
#define  KU16_STEP_EVERY_2MS             ((uint16)0)
/**
 * \brief
 *     Decade argument value for macro
 */
#define  KU16_STEP_EVERY_10MS            ((uint16)4)
/**
 * \brief
 *     Decade argument value for macro
 */
#define  KU16_STEP_EVERY_20MS            ((uint16)9)
/**
 * \brief
 *     Decade argument value for macro
 */
#define  KU16_STEP_EVERY_100MS           ((uint16)49)


#define ATM_AC_AutoTestManager_START_SEC_CODE
#include "ATM_AC_AutoTestManager_MemMap.h"

/**
 * \brief
 *     Callback of Rte_Call_pclCheckAdc autotest to check ADC
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
LOCAL u8TestResultType ADC_cbk_CheckAdc (void)
{
   const u8TestResultType u8TestResult = KU8_ATM_TEST_OK;

   return u8TestResult;
}
/**
 * \brief
 *     Callback of Rte_Call_pclRunResetCause autotest to check if an unexpected reset cause has been detected.
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0028;] */
LOCAL u8TestResultType RCM_cbk_RunResetCause_Autotest (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclRunResetCause_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of Rte_Call_pclRunExtWatchogTest autotest to check an unexpected reset.
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0027;] */
LOCAL u8TestResultType RCM_cbk_ExtWatchdogTest_Autotest (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclRunExtWatchogTest_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of Rte_Call_pclCheckHighSideSwRegulation autotest to test the High Side Switch regulation.
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0009;] */
LOCAL u8TestResultType PAL_cbk_CheckHighSideSwRegulation (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckHighSideSwRegulation_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckCommandConsistency autotest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0010;] */
LOCAL u8TestResultType PAL_cbk_CheckCommandConsistency (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckCommandConsistency_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of Rte_Call_pclCheckMosfetHighSC autotest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0011;] */
LOCAL u8TestResultType PAL_cbk_CheckMosfetHighSC (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckMosfetHighSC_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of Rte_Call_pclCheckMosfetLowSC autotest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0012;] */
LOCAL u8TestResultType PAL_cbk_CheckMosfetLowSC (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckMosfetLowSC_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of Rte_Call_pclCheckMotorConnection autotest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0013;] */
LOCAL u8TestResultType PAL_cbk_CheckMotorConnection (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckMotorConnection_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckHWSelfProtection autotest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0014;] */
LOCAL u8TestResultType PAL_cbk_CheckHWSelfProtection (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckHWSelfProtection_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckMosfetOCA autotest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0015;] */
LOCAL u8TestResultType PAL_cbk_CheckMosfetOCAT (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckMosfetOCAT_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckMotorCurrent autotest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0017;] */
LOCAL u8TestResultType PAL_cbk_CheckMotorCurrent (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckMotorCurrent_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckMotorDisengagement autotest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0018;] */
LOCAL u8TestResultType PAL_cbk_CheckMotorDisengagement (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckMotorDisengagement_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckMotorThermalProctection - SWSelfProtection AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0019;] */
LOCAL u8TestResultType PAL_cbk_CheckMotorThermalProctection (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckMotorThermalProctection_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckMotorSC AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0020;] */
LOCAL u8TestResultType PAL_cbk_CheckMotorSC (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckMotorSC_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckMotorPowerOrder AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0022;] */
LOCAL u8TestResultType PAL_cbk_CheckMotorPowerOrder (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckMotorPowerOrder_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of  Rte_Call_pclCheckHallEffectSensor AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0016;] */
LOCAL u8TestResultType BMM_cbk_CheckHallEffectSensor (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckHallEffectSensor_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckTemperatureSensor AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0021;] */
LOCAL u8TestResultType PMP_cbk_CheckTemperatureSensor (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckTemperatureSensor_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckPowerSupplyUV AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0023;] */
LOCAL u8TestResultType PMP_cbk_CheckPowerSupplyUV (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckPowerSupplyUV_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckPowerSupplyOV AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0024;] */
LOCAL u8TestResultType PMP_cbk_CheckPowerSupplyOV (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckPowerSupplyOV_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckPowerSupplyUVDuringActivation AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0025;] */
LOCAL u8TestResultType PMP_cbk_CheckPowerSupplyUVDuringActivation (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckPowerSupplyUVDuringActivation_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckPowerSupplyOVDuringActivation AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0026;] */
LOCAL u8TestResultType PMP_cbk_CheckPowerSupplyOVDuringActivation (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckPowerSupplyOVDuringActivation_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of PMP_Autotest_CheckSystemUV AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0046;] */
LOCAL u8TestResultType PMP_cbk_CheckSystemUV (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckSystemUV_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of PMP_Autotest_CheckSystemOV AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0045;] */
LOCAL u8TestResultType PMP_cbk_CheckSystemOV (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckSystemOV_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of Rte_Call_pclCheckProductEndOfLifeLowForce AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0029;] */
LOCAL u8TestResultType EOL_cbk_CheckProductEndOfLifeLowForce (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckProductEndOfLifeLowForce_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckProductEndOfLifeHighForce AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0030;] */
LOCAL u8TestResultType EOL_cbk_CheckProductEndOfLifeHighForce (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckProductEndOfLifeHighForce_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
 * \brief
 *     Callback of Rte_Call_pclCheckProductEndOfLifeComfort_AutotestCallback AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0031;] */
LOCAL u8TestResultType EOL_cbk_CheckProductEndOfLifeComfort (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckProductEndOfLifeComfort_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of EOL_Autotest_CheckProductEndOfLifeMaxForce AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0037;] */
LOCAL u8TestResultType EOL_cbk_CheckProductEndOfLifeMaxForce (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckProductEndOfLifeMaxForce_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of Rte_Call_pclCheckTimeoutError_AutotestCallbacks AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0032;] */
LOCAL u8TestResultType CIL_cbk_Presafe_CheckTimeoutError (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckTimeoutError_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of Rte_Call_pclCheckTimeoutErrorBuckle_AutotestCallback AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0033;] */
LOCAL u8TestResultType CIL_cbk_Buckle_CheckTimeoutError (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckTimeoutErrorBuckle_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_cbk_CheckImplausibleData_Buckle AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0036;] */
LOCAL u8TestResultType CIL_cbk_CheckImplausibleData_Buckle (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckImplausibleDataBuckle_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckImplausibleData_Ignition AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0035;] */
LOCAL u8TestResultType CIL_cbk_CheckImplausibleData_Ignition (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckImplausibleDataIgnition_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckImplausibleData_Presafe AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0034;] */
LOCAL u8TestResultType CIL_cbk_CheckImplausibleData_Presafe (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckImplausibleDataPresafe_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckSteeringConfiguration AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0053;] */
LOCAL u8TestResultType CIL_cbk_CheckSteeringConfiguration (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckSteeringConfiguration_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckTimeoutError_API AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0044;] */
LOCAL u8TestResultType CIL_cbk_CheckTimeoutError_API (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckTimeoutErrorAPI_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckTimeoutError_BelthandoverL AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0042;] */
LOCAL u8TestResultType CIL_cbk_CheckTimeoutError_BelthandoverL (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckTimeoutErrorBelthandoverL_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckTimeoutError_BelthandoverR AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0043;] */
LOCAL u8TestResultType CIL_cbk_CheckTimeoutError_BelthandoverR (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckTimeoutErrorBelthandoverR_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckTimeoutError_Ignition AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0038;] */
LOCAL u8TestResultType CIL_cbk_CheckTimeoutError_Ignition (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckTimeoutErrorIgnition_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckTimeoutError_Powertrain AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0039;] */
LOCAL u8TestResultType CIL_cbk_CheckTimeoutError_Powertrain (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckTimeoutErrorPowertrain_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckImplausibleData_ORC AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0041;] */
LOCAL u8TestResultType CIL_cbk_CheckImplausibleData_ORC (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckImplausibleDataORC_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckImplausibleData_PowertrainRdy AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0040;] */
LOCAL u8TestResultType CIL_cbk_CheckImplausibleData_Powertrain_Rdy (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckImplausibleDataPowertrainRdy_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckImplausibleData_PowertrainDrv AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0048;] */
LOCAL u8TestResultType CIL_cbk_CheckImplausibleData_Powertrain_Drv (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckImplausibleDataPowertrainDrv_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckTimeoutError_OdoSpeedometer AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0049;] */
LOCAL u8TestResultType CIL_cbk_CheckTimeoutError_Odospeedometer (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckTimeoutErrorOdoSpeedometer_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckImplausibleData_PowertrainRdy AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0050;] */
LOCAL u8TestResultType CIL_cbk_CheckImplausibleData_API (void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckImplausibleDataAPI_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckVariantCoding AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0051;] */
LOCAL u8TestResultType CIL_cbk_CheckVariantCoding(void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckVariantCodining_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of CIL_Autotest_CheckTimeoutError_BeltAdj AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0053;] */
LOCAL u8TestResultType CIL_cbk_CheckTimeoutError_BeltAdj(void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pclCheckTimeoutErrorBeltAdj_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
 * \brief
 *     Callback of SBC_ServiceAutotest_GetTestResult AutoTest
 * \param
 *     void
 * \return
 *     u8TestResult
 * \remark
 *     None
 **/
/* [COVERS: DSG_ATM_0053;] */
LOCAL u8TestResultType SBC_cbk_SPIError(void)
{
   u8TestResultType u8TestResult;

   Rte_Call_pcs_ServiceAutotest_GetTestResult(&u8TestResult);

   return u8TestResult;
}
#define ATM_AC_AutoTestManager_STOP_SEC_CODE
#include "ATM_AC_AutoTestManager_MemMap.h"

/*************************************************************************
Label: COD_ATM_00009
Object: This structure describes the constant data of an autotest :
 - Pointer to function callback
 - Type (KU8_AUTO_TEST_CONFIG_TYPE_PERIODIC, ATM_KU8_CONFIG_TYPE_ON_DEMAND, or
     KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT)
 - Period and offset (to access with the appropriate macros)
 - Running context mask
Unit: None.
 **************************************************************************/

#define ATM_AC_AutoTestManager_START_SEC_CONST_UNSPECIFIED
#include "ATM_AC_AutoTestManager_MemMap.h"

/* QAC_WARNING S 3211 2 */ /* The global identifier 'cau32InhibitingModes' is defined here but is not used in this translation unit. */
/* This table of constants is used in the ATM.c file. */
/**
 * \brief
 *    List of possible inhibition modes combinations that can be checked before test executions.
        Goal: As several tests execution share the same combination, theses combinations (32 bits bitfield)
        are stored in this array, and tests attributes can be only a 8 bits index to save flash memory.
 * \var
 *     u32ModeMaskType cau32InhibitingModes
 */
const u32ModeMaskType cau32InhibitingModes[KU8_NUMBER_OF_INHIBITING_MODES] = {
      /*                                                         -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
      /*                                                          MMG_KU32_MASK_BELTFUNCTIONS_DELAY          | MMG_KU32_MASK_POWER_VOLTAGE_UNSTABLE                                                       | ENABLE CONDITIONS MASK                                 */
      /*                                                         ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
      /* KU8_MODES_______________INHIB */                        (KU32_MASK_NO_MODE),
      /* KU8_MODES________VOLTAG_INHIB */                        (                                             MMG_KU32_MASK_POWER_VOLTAGE_UNSTABLE),
      /* KU8_MODES_BELTFN_VOLTAG_INHIB */                        (MMG_KU32_MASK_BELTFUNCTIONS_DELAY          | MMG_KU32_MASK_POWER_VOLTAGE_UNSTABLE),
      /* KU8_MODES_BELTFN________INHIB */                        (MMG_KU32_MASK_BELTFUNCTIONS_DELAY_UV),
      /* KU8_MODES_ENABLE_____IGNITION */                                                                                                                                                                    (MMG_KU32_MASK_ENABLE_IGNITION_ON),
      /* KU8_MODES_ENABLE__________API */                                                                                                                                                                    (MMG_KU32_MASK_ENABLE_CODING_API),
      /* KU8_MODES_ENABLE_CodingBLTHov */                                                                                                                                                                    (MMG_KU32_MASK_ENABLE_CODING_BLT)};

/* QAC_WARNING S 3211 3 */ /* The global identifier 'castATMConfig' is defined here but is not used in this translation unit. */
/* It was precisely the aim to isolate configuration data from the generic ATM engine! */
/* Common test properties, independent to the execution timing parameters */
/**
 * \brief
 *    This array configures autotests common attributes and store the test ID for autotes:
 *    - Pointer to text execution function.
 *    - The corresponding AEC index for AEC status update according to test result.
 * \var
 *    stAutoTestConfigurationType castATMConfig
 */
const stAutoTestConfigurationType  castATMConfig[ATM_KU8_NB_OF_AUTOTEST] =
{
      /* ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
      /*                    ATM Ids                               |         auto test executing function           |      AEC ID                               |  Index of inhibition mode combination */
      /* ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
      /* 0  : ATM_KU8_ID_TEST_ADC                              */   {&ADC_cbk_CheckAdc,                              ERH_KU8_ADC_AEC_CFG,                               KU8_MODES_______________INHIB},
      /* 1  : ATM_KU8_ID_TEST_HIGH_SIDE_SWITCH                 */   {&PAL_cbk_CheckHighSideSwRegulation,             ERH_KU8_HIGH_SIDE_SWITCH_AEC_CFG,                  KU8_MODES________VOLTAG_INHIB},
      /* 2  : ATM_KU8_ID_TEST_DRIVER_COMMAND                   */   {&PAL_cbk_CheckCommandConsistency,               ERH_KU8_ENABLE_OUT_OF_ORDER_AEC_CFG,               KU8_MODES_______________INHIB},
      /* 3  : ATM_KU8_ID_TEST_MOSFET_HIGH_SHORT_CIRCUIT        */   {&PAL_cbk_CheckMosfetHighSC,                     ERH_KU8_MOSFET_HIGH_SC_AEC_CFG,                    KU8_MODES_BELTFN_VOLTAG_INHIB},
      /* 4  : ATM_KU8_ID_TEST_MOSFET_LOW_SHORT_CIRCUIT         */   {&PAL_cbk_CheckMosfetLowSC,                      ERH_KU8_MOSFET_LOW_SC_AEC_CFG,                     KU8_MODES_BELTFN_VOLTAG_INHIB},
      /* 5  : ATM_KU8_ID_TEST_MOTOR_DISCONNECTION              */   {&PAL_cbk_CheckMotorConnection,                  ERH_KU8_MOTOR_DISCONNECTED_AEC_CFG,                KU8_MODES_BELTFN_VOLTAG_INHIB},
      /* 6  : ATM_KU8_ID_TEST_DRIVER_SELF_PROTECTION           */   {&PAL_cbk_CheckHWSelfProtection,                 ERH_KU8_HW_SELF_PROTECTION_AEC_CFG,                KU8_MODES_______________INHIB},
      /* 7  : ATM_KU8_ID_TEST_MOSFET_OPEN_CIRCUIT              */   {&PAL_cbk_CheckMosfetOCAT,                       ERH_KU8_MOSFET_OC_AEC_CFG,                         KU8_MODES_BELTFN_VOLTAG_INHIB},
      /* 8  : ATM_KU8_ID_SPI_ERROR                             */   {&SBC_cbk_SPIError,                              ERH_KU8_SPI_ERROR_AEC_CFG,                         KU8_MODES_______________INHIB},
      /* 9  : ATM_KU8_ID_TEST_HALL_EFFECT_SENSORS              */   {&BMM_cbk_CheckHallEffectSensor,                 ERH_KU8_HALL_SENSOR_AEC_CFG,                       KU8_MODES________VOLTAG_INHIB},
      /* 10 : ATM_KU8_ID_TEST_MOTOR_CURRENT                    */   {&PAL_cbk_CheckMotorCurrent,                     ERH_KU8_MOTOR_CURRENT_AEC_CFG,                     KU8_MODES________VOLTAG_INHIB},
      /* 11 : ATM_KU8_ID_TEST_MOTOR_BLOCKED                    */   {&PAL_cbk_CheckMotorDisengagement,               ERH_KU8_MOTOR_BLOCKED_AEC_CFG,                     KU8_MODES________VOLTAG_INHIB},
      /* 12 : ATM_KU8_ID_TEST_MOTOR_TEMPERATURE                */   {&PAL_cbk_CheckMotorThermalProctection,          ERH_KU8_SW_SELF_PROTECTION_AEC_CFG,                KU8_MODES_______________INHIB},
      /* 13 : ATM_KU8_ID_TEST_SENSOR_TEMPERATURE               */   {&PMP_cbk_CheckTemperatureSensor,                ERH_KU8_TEMPERATURE_SENSOR_FAILURE_AEC_CFG,        KU8_MODES_______________INHIB},
      /* 14 : ATM_KU8_ID_TEST_MOTOR_SHORT_CIRCUIT              */   {&PAL_cbk_CheckMotorSC,                          ERH_KU8_MOTOR_IN_SC_AEC_CFG,                       KU8_MODES________VOLTAG_INHIB},
      /* 15 : ATM_KU8_ID_TEST_PWM_ORDER                        */   {&PAL_cbk_CheckMotorPowerOrder,                  ERH_KU8_MOTOR_ORDER_AEC_CFG,                       KU8_MODES________VOLTAG_INHIB},
      /* 16 : ATM_KU8_ID_TEST_UNDER_VOLTAGE_POWER              */   {&PMP_cbk_CheckPowerSupplyUV,                    ERH_KU8_UVO_POWER_AEC_CFG,                         KU8_MODES_______________INHIB},
      /* 17 : ATM_KU8_ID_TEST_OVER_VOLTAGE_POWER               */   {&PMP_cbk_CheckPowerSupplyOV,                    ERH_KU8_OVO_POWER_AEC_CFG,                         KU8_MODES_______________INHIB},
      /* 18 : ATM_KU8_ID_TEST_UNDER_VOLTAGE_TENSIONING_POWER   */   {&PMP_cbk_CheckPowerSupplyUVDuringActivation,    ERH_KU8_UVO_TENSIONING_POWER_AEC_CFG,              KU8_MODES_______________INHIB},
      /* 19 : ATM_KU8_ID_TEST_OVER_VOLTAGE_TENSIONING_POWER    */   {&PMP_cbk_CheckPowerSupplyOVDuringActivation,    ERH_KU8_OVO_TENSIONING_POWER_AEC_CFG,              KU8_MODES_______________INHIB},
      /* 20 : ATM_KU8_ID_EXT_WDG_OUT_OF_ORDER                  */   {&RCM_cbk_ExtWatchdogTest_Autotest,              ERH_KU8_EXT_WDG_OUT_OF_ORDER_AEC_CFG,              KU8_MODES_______________INHIB},
      /* 21 : ATM_KU8_ID_FLS_OUT_OF_ORDER                      */   {KPF_NULL,                                       ERH_KU8_UNDEFINED_AEC_CFG,                         KU8_MODES_______________INHIB},
      /* 22 : ATM_KU8_ID_NVM_NOT_PROG                          */   {KPF_NULL,                                       ERH_KU8_UNDEFINED_AEC_CFG,                         KU8_MODES_______________INHIB},
      /* 23 : ATM_KU8_ID_NVM_MEMORY_CORRUPTION                 */   {KPF_NULL,                                       ERH_KU8_UNDEFINED_AEC_CFG,                         KU8_MODES_______________INHIB},
      /* 24 : ATM_KU8_ID_RAM_MEMORY_CORRUPTION                 */   {KPF_NULL,                                       ERH_KU8_UNDEFINED_AEC_CFG,                         KU8_MODES_______________INHIB},
      /* 25 : ATM_KU8_ID_TFLASH_MEMORY_CORRUPTION              */   {KPF_NULL,                                       ERH_KU8_UNDEFINED_AEC_CFG,                         KU8_MODES_______________INHIB},
      /* 26 : ATM_KU8_ID_CAN_BUS_OFF                           */   {KPF_NULL,                                       ERH_KU8_CAN_BUS_OFF_AEC_CFG,                       KU8_MODES_______________INHIB},
      /* 27 : ATM_KU8_ID_RESET_CAUSE                           */   {&RCM_cbk_RunResetCause_Autotest,                ERH_KU8_WARM_RESET_AEC_CFG,                        KU8_MODES_______________INHIB},
      /* 28 : ATM_KU8_ID_END_OF_LIFE_LOW_FORCE                 */   {&EOL_cbk_CheckProductEndOfLifeLowForce,         ERH_KU8_END_OF_LIFE_LOW_AEC_CFG,                   KU8_MODES_______________INHIB},
      /* 29 : ATM_KU8_ID_END_OF_LIFE_HIGH_FORCE                */   {&EOL_cbk_CheckProductEndOfLifeHighForce,        ERH_KU8_END_OF_LIFE_HIGH_AEC_CFG,                  KU8_MODES_______________INHIB},
      /* 30 : ATM_KU8_ID_END_OF_LIFE_COMFORT                   */   {&EOL_cbk_CheckProductEndOfLifeComfort,          ERH_KU8_END_OF_LIFE_COMFORT_AEC_CFG,               KU8_MODES_______________INHIB},
      /* 31 : ATM_KU8_ID_END_OF_LIFE_MAX_FORCE                 */   {&EOL_cbk_CheckProductEndOfLifeMaxForce,         ERH_KU8_END_OF_LIFE_MAX_FORCE_AEC_CFG,             KU8_MODES_______________INHIB},
      /* 32 : ATM_KU8_ID_TEST_NVM_CHECKSUM                     */   {KPF_NULL,                                       ERH_KU8_UNDEFINED_AEC_CFG,                         KU8_MODES_______________INHIB},
      /* 33 : ATM_KU8_ID_TIMEOUT_PRESAFE                       */   {&CIL_cbk_Presafe_CheckTimeoutError,             ERH_KU8_TIMEOUT_PRESAFE_AEC_CFG,                   KU8_MODES_______________INHIB},
      /* 34 : ATM_KU8_ID_TIMEOUT_BUCKLE                        */   {&CIL_cbk_Buckle_CheckTimeoutError,              ERH_KU8_TIMEOUT_BUCKLE_AEC_CFG,                    (KU8_MODES_______________INHIB | KU8_MODES_ENABLE_____IGNITION)},
      /* 35 : ATM_KU8_ID_IMPLAUSIBLE_DATA_PRESAFE              */   {&CIL_cbk_CheckImplausibleData_Presafe,          ERH_KU8_IMPLAUSIBLE_DATA_PRESAFE_AEC_CFG,          (KU8_MODES_______________INHIB | KU8_MODES_ENABLE_____IGNITION)},
      /* 36 : ATM_KU8_ID_IMPLAUSIBLE_DATA_IGNITION             */   {&CIL_cbk_CheckImplausibleData_Ignition,         ERH_KU8_IMPLAUSIBLE_DATA_IGNITION_AEC_CFG,         (KU8_MODES_______________INHIB | KU8_MODES_ENABLE_____IGNITION)},
      /* 37 : ATM_KU8_ID_IMPLAUSIBLE_DATA_BUCKLE               */   {&CIL_cbk_CheckImplausibleData_Buckle,           ERH_KU8_IMPLAUSIBLE_DATA_BUCKLE_AEC_CFG,           (KU8_MODES_______________INHIB | KU8_MODES_ENABLE_____IGNITION)},
      /* 38 : ATM_KU8_ID_TIMEOUT_BLTHD_R                       */   {&CIL_cbk_CheckTimeoutError_BelthandoverR,       ERH_KU8_TIMEOUT_BLTHD_R_AEC_CFG,                   (KU8_MODES_______________INHIB | KU8_MODES_ENABLE_CodingBLTHov)},
      /* 39 : ATM_KU8_ID_TIMEOUT_BLTHD_L                       */   {&CIL_cbk_CheckTimeoutError_BelthandoverL,       ERH_KU8_TIMEOUT_BLTHD_L_AEC_CFG,                   (KU8_MODES_______________INHIB | KU8_MODES_ENABLE_CodingBLTHov)},
      /* 40 : ATM_KU8_ID_TIMEOUT_IGNITION                      */   {&CIL_cbk_CheckTimeoutError_Ignition,            ERH_KU8_TIMEOUT_IGNITION_AEC_CFG,                  KU8_MODES_______________INHIB},
      /* 41 : ATM_KU8_ID_IMPLAUSIBLE_DATA_ORC                  */   {&CIL_cbk_CheckImplausibleData_ORC,              ERH_KU8_IMPLAUSIBLE_DATA_ORC_AEC_CFG,              (KU8_MODES_______________INHIB | KU8_MODES_ENABLE_____IGNITION)},
      /* 42 : ATM_KU8_ID_IMPLAUSIBLE_DATA_POWERTRAIN_RDY       */   {&CIL_cbk_CheckImplausibleData_Powertrain_Rdy,   ERH_KU8_IMPLAUSIBLE_DATA_POWERTRAIN_RDY_AEC_CFG,   (KU8_MODES_______________INHIB | KU8_MODES_ENABLE_____IGNITION)},
      /* 43 : ATM_KU8_ID_TIMEOUT_POWERTRAIN                    */   {&CIL_cbk_CheckTimeoutError_Powertrain,          ERH_KU8_TIMEOUT_POWERTRAIN_AEC_CFG,                KU8_MODES_______________INHIB},
      /* 44 : ATM_KU8_ID_STEERING_CONFIGURATION                */   {&CIL_cbk_CheckSteeringConfiguration,            ERH_KU8_STEERING_CONFIG_AEC_CFG,                   KU8_MODES_______________INHIB},
      /* 45 : ATM_KU8_ID_SYSTEM_OV                             */   {&PMP_cbk_CheckSystemOV,                         ERH_KU8_SYSTEM_OV_AEC_CFG,                         KU8_MODES_______________INHIB},
      /* 46 : ATM_KU8_ID_SYSTEM_UV                             */   {&PMP_cbk_CheckSystemUV,                         ERH_KU8_SYSTEM_UV_AEC_CFG,                         KU8_MODES_______________INHIB},
      /* 47 : ATM_KU8_ID_TIMEOUT_API                           */   {&CIL_cbk_CheckTimeoutError_API,                 ERH_KU8_TIMEOUT_API,                               (KU8_MODES_______________INHIB | KU8_MODES_ENABLE_____IGNITION | KU8_MODES_ENABLE__________API)},
      /* 48 : ATM_KU8_ID_IMPLAUSIBLE_DATA_POWERTRAIN_DRV       */   {&CIL_cbk_CheckImplausibleData_Powertrain_Drv,   ERH_KU8_IMPLAUSIBLE_DATA_POWERTRAIN_DRV_AEC_CFG,   KU8_MODES_______________INHIB},
      /* 49 : ATM_KU8_ID_TIMEOUT_ODOSPEEDOMETER                */   {&CIL_cbk_CheckTimeoutError_Odospeedometer,      ERH_KU8_TIMEOUT_ODOSPEEDOMETER_AEC_CFG,            KU8_MODES_______________INHIB},
      /* 51 : ATM_KU8_ID_IMPLAUSIBLE_DATA_API                  */   {&CIL_cbk_CheckImplausibleData_API,              ERH_KU8_IMPLAUSIBLE_DATA_API_AEC_CFG,              (KU8_MODES_______________INHIB | KU8_MODES_ENABLE_____IGNITION | KU8_MODES_ENABLE__________API)},
      /* 52 : ATM_KU8_ID_VARIANT_CODING                        */   {&CIL_cbk_CheckVariantCoding,                    ERH_KU8_VARIANT_CODING_AEC_CFG,                    KU8_MODES_______________INHIB},
      /* 53 : ATM_KU8_ID_TIMEOUT_BELT_ADJ                      */   {&CIL_cbk_CheckTimeoutError_BeltAdj,             ERH_KU8_TIMEOUT_BELT_ADJ_AEC_CFG,                  KU8_MODES_______________INHIB},
      /* ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
};

/* QAC_WARNING S 3211 3 */ /* The global identifier 'castStartupSequentialList' is defined here but is not used in this translation unit. */
/* It was precisely the aim to isolate configuration data from the generic ATM engine! */
/* This table of "one shot" tests is run once at startup. Each test is run only after the previous one completion. */
/**
 * \brief
 *    This array of "one shot" tests is run once at startup. Each test is run only after the previous one completion.
 * \var
 *        stStartupEltType castStartupSequentialList
 */
const stStartupEltType castStartupSequentialList[ATM_KU8_NB_OF_STARTUP_AUTO_TESTS] =
{
      /* 0  */  { KU8_ATM_ONE_SHOT_DECIDED (KU16_STEP_EVERY_2MS),    ATM_KU8_ID_NVM_NOT_PROG},
      /* 1  */  { KU8_ATM_ONE_SHOT_ABORT   (KU16_STEP_EVERY_10MS),   ATM_KU8_ID_NVM_MEMORY_CORRUPTION},
      /* 2  */  { KU8_ATM_ONE_SHOT         (KU16_STEP_EVERY_10MS),   ATM_KU8_ID_RAM_MEMORY_CORRUPTION},
      /* 3  */  { KU8_ATM_ONE_SHOT         (KU16_STEP_EVERY_10MS),   ATM_KU8_ID_RESET_CAUSE},
      /* 4  */  { KU8_ATM_ONE_SHOT         (KU16_STEP_EVERY_10MS),   ATM_KU8_ID_END_OF_LIFE_LOW_FORCE},
      /* 5  */  { KU8_ATM_ONE_SHOT         (KU16_STEP_EVERY_10MS),   ATM_KU8_ID_END_OF_LIFE_HIGH_FORCE},
      /* 6  */  { KU8_ATM_ONE_SHOT         (KU16_STEP_EVERY_10MS),   ATM_KU8_ID_END_OF_LIFE_COMFORT},
      /* 7  */  { KU8_ATM_ONE_SHOT         (KU16_STEP_EVERY_10MS),   ATM_KU8_ID_END_OF_LIFE_MAX_FORCE},
      /* 8  */  { KU8_ATM_ONE_SHOT_RETRY   (KU16_STEP_EVERY_2MS),    ATM_KU8_ID_TEST_ADC},
      /* 9  */  { KU8_ATM_ONE_SHOT_ABORT   (KU16_STEP_EVERY_10MS),   ATM_KU8_ID_TEST_HIGH_SIDE_SWITCH},
      /* 10 */  { KU8_ATM_ONE_SHOT_RETRY   (KU16_STEP_EVERY_100MS),  ATM_KU8_ID_TEST_DRIVER_COMMAND},
      /* 11 */  { KU8_ATM_ONE_SHOT_RETRY   (KU16_STEP_EVERY_100MS),  ATM_KU8_ID_TEST_MOSFET_HIGH_SHORT_CIRCUIT},
      /* 12 */  { KU8_ATM_ONE_SHOT_RETRY   (KU16_STEP_EVERY_100MS),  ATM_KU8_ID_TEST_MOSFET_LOW_SHORT_CIRCUIT},
      /* 13 */  { KU8_ATM_ONE_SHOT_RETRY   (KU16_STEP_EVERY_100MS),  ATM_KU8_ID_TEST_MOTOR_DISCONNECTION},
      /* 14 */  { KU8_ATM_ONE_SHOT_RETRY   (KU16_STEP_EVERY_10MS),   ATM_KU8_ID_TEST_DRIVER_SELF_PROTECTION},
      /* 15 */  { KU8_ATM_ONE_SHOT_ABORT   (KU16_STEP_EVERY_20MS),   ATM_KU8_ID_TEST_MOSFET_OPEN_CIRCUIT},
};

/* QAC_WARNING S 3211 3 */ /* The global identifier 'castStartupCyclicList' is defined here but is not used in this translation unit. */
/* It was precisely the aim to isolate configuration data from the generic ATM engine! */
/* This table of cyclic tests is run in parallel with the "one shot" tests list. */
/**
 * \brief
 *    This table of cyclic tests is run in parallel with the "one shot" tests list.
 * \var
 *       const stCyclicListEltType
 */
const stCyclicListEltType castStartupCyclicList[KU8_NB_OF_STARTUP_CYCLIC_ELTS] =
{
      /* Start Of Test List Executed during the 4th Time Slot */
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_0),            ATM_KU8_ID_TEST_UNDER_VOLTAGE_POWER},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_0),            ATM_KU8_ID_TEST_OVER_VOLTAGE_POWER},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_1),            ATM_KU8_ID_SYSTEM_UV},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_1),            ATM_KU8_ID_SYSTEM_OV},
      { KU8_END_OF_SUB_LIST},

      /* Start Of Test List Executed during the 5th Time Slot */
      { KU8_END_OF_THE_WHOLE_LIST}
};

/* QAC_WARNING S 3211 3 */ /* The global identifier 'castRunningCyclicList' is defined here but is not used in this translation unit. */
/* It was precisely the aim to isolate configuration data from the generic ATM engine! */
/* This table of cyclic tests is run after the last "one shot" test. */
/**
 * \brief
 *    This table of cyclic tests is run in parallel with the "one shot" tests list.
 * \var
 *        stCyclicListEltType castRunningCyclicList
 */
const stCyclicListEltType castRunningCyclicList[KU8_NB_OF_RUNNING_CYCLIC_ELTS] =
{
      /* Start Of Test List Executed during the 1st Time Slot */
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_TEST_ADC},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_TEST_UNDER_VOLTAGE_TENSIONING_POWER},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_TEST_OVER_VOLTAGE_TENSIONING_POWER},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_0),             ATM_KU8_ID_SYSTEM_UV},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_1),             ATM_KU8_ID_SYSTEM_OV},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_SPI_ERROR},
      { KU8_END_OF_SUB_LIST},

      /* Start Of Test List Executed during the 2nd Time Slot */
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_TEST_ADC},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_0),             ATM_KU8_ID_TEST_DRIVER_COMMAND},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_1),             ATM_KU8_ID_TEST_MOSFET_HIGH_SHORT_CIRCUIT},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_2),             ATM_KU8_ID_TEST_MOSFET_LOW_SHORT_CIRCUIT},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_3),             ATM_KU8_ID_TEST_MOTOR_DISCONNECTION},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_TEST_DRIVER_SELF_PROTECTION},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_TEST_MOTOR_BLOCKED},
      { KU8_END_OF_SUB_LIST},

      /* Start Of Test List Executed during the 3rd Time Slot */
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_TEST_ADC},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_0),             ATM_KU8_ID_TEST_HALL_EFFECT_SENSORS},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_TEST_MOTOR_CURRENT},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_END_OF_LIFE_LOW_FORCE},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_STEERING_CONFIGURATION },
      { KU8_END_OF_SUB_LIST},

      /* Start Of Test List Executed during the 4th Time Slot */
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_TEST_ADC},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_VARIANT_CODING},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_0),             ATM_KU8_ID_TEST_UNDER_VOLTAGE_POWER},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_0),             ATM_KU8_ID_TEST_OVER_VOLTAGE_POWER},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_1),             ATM_KU8_ID_IMPLAUSIBLE_DATA_PRESAFE},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_1),             ATM_KU8_ID_IMPLAUSIBLE_DATA_IGNITION},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_2),             ATM_KU8_ID_IMPLAUSIBLE_DATA_BUCKLE},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_2),             ATM_KU8_ID_TIMEOUT_POWERTRAIN},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_3),             ATM_KU8_ID_TIMEOUT_IGNITION},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_3),             ATM_KU8_ID_IMPLAUSIBLE_DATA_POWERTRAIN_RDY},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_4),             ATM_KU8_ID_IMPLAUSIBLE_DATA_POWERTRAIN_DRV},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_4),             ATM_KU8_ID_IMPLAUSIBLE_DATA_ORC},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_4),             ATM_KU8_ID_IMPLAUSIBLE_DATA_API},
      { KU8_ATM_PERIODIC_200_MS (IN_DECADE_0),             ATM_KU8_ID_TIMEOUT_PRESAFE},
      { KU8_ATM_PERIODIC_200_MS (IN_DECADE_1),             ATM_KU8_ID_TIMEOUT_BUCKLE},
      { KU8_ATM_PERIODIC_200_MS (IN_DECADE_2),             ATM_KU8_ID_TIMEOUT_API},
      { KU8_ATM_PERIODIC_500_MS (IN_DECADE_0),             ATM_KU8_ID_TIMEOUT_BLTHD_L},
      { KU8_ATM_PERIODIC_500_MS (IN_DECADE_1),             ATM_KU8_ID_TIMEOUT_BLTHD_R},
      { KU8_ATM_PERIODIC_1_S (IN_DECADE_0),                ATM_KU8_ID_TIMEOUT_ODOSPEEDOMETER},
      { KU8_ATM_PERIODIC_1_S (IN_DECADE_1),                ATM_KU8_ID_TIMEOUT_BELT_ADJ},
      { KU8_END_OF_SUB_LIST},

      /* Start Of Test List Executed during the 5th Time Slot */
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_TEST_ADC},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_TEST_PWM_ORDER},
      { KU8_ATM_PERIODIC_1_S    (IN_DECADE_0),             ATM_KU8_ID_TEST_SENSOR_TEMPERATURE},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_END_OF_LIFE_HIGH_FORCE},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_END_OF_LIFE_COMFORT},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_TEST_MOTOR_SHORT_CIRCUIT},
      { KU8_ATM_PERIODIC_100_MS (IN_DECADE_0),             ATM_KU8_ID_TEST_MOTOR_TEMPERATURE},
      { KU8_ATM_PERIODIC_10_MS,                            ATM_KU8_ID_END_OF_LIFE_MAX_FORCE},
      { KU8_END_OF_THE_WHOLE_LIST},
};
#define ATM_AC_AutoTestManager_STOP_SEC_CONST_UNSPECIFIED
#include "ATM_AC_AutoTestManager_MemMap.h"

/**************************************************************************
Exported Functions
 **************************************************************************/
#define ATM_AC_AutoTestManager_START_SEC_CODE
#include "ATM_AC_AutoTestManager_MemMap.h"

/**
 * \brief
 *     Configurabled function for Init, called in ATM_Init function.
 * \param
 *     void
 * \return
 *     void
 * \remark
 *     None
 **/
void  Cfg_SpecificFunction_Init_ATM(void)
{
   /* To be completed if necessary */
}

/**
 * \brief
 *  Configurabled function for Shutdown called in ATM_Shutdown function..
 * \param
 *     u8TestResult
 * \return
 *     void
 * \remark
 *     None
 **/
void  Cfg_SpecificFunction_Shutdown_ATM(void)
{
   /* To be completed if necessary */
}

/**
 * \brief
 *     Configurabled function called in ATM MainFcuntion , before any other functionalities.
 * \param
 *     void
 * \return
 *     void
 * \remark
 *     None
 **/
void  Cfg_SpecificFunction_StartMain_ATM(void)
{
   /* To be completed if necessary */
}

/**
 * \brief
 *    Configurabled function called in ATM MainFcuntion at the and of all functionalities.
 * \param
 *     void
 * \return
 *     void
 * \remark
 *     None
 **/
void  Cfg_SpecificFunction_EndMain_ATM(void)
{
   /* To be completed if necessary */
}

#define ATM_AC_AutoTestManager_STOP_SEC_CODE
#include "ATM_AC_AutoTestManager_MemMap.h"

/* end of file */
