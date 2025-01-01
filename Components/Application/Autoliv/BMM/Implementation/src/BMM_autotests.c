
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
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.1.3.2.6 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/BMM/Implementation/src/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup BMM_AC_BeltMovementMonitoring BMM
 *  Evaluates the belt Displacement (in millimeters and in degrees of the
 *  bobbin rotation) and the belt speed (in millimeters per seconds and
 *  in degrees of the bobbin rotation per seconds).
 */

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_BMM_AC_BeltMovementMonitoring.h"
#include "common.h"
#include "Nvp_Generated.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/
/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
#define BMM_AC_BeltMovementMonitoring_START_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

/**
* \brief
*	This auto-test aims at checking whether both Hall-effect sensors
*       are working properly.
*       This autotest retrieves each HES input voltage value from de
*       ASM module and checks them if they are in correct range.
*       If at least one of both values is out of range, this autotest
*       returns "failed" result, otherwise it returns "passed" result.
* \param
*     u8TestResultType * pu8TestResult Pointer to write the AEC to ATM.
* \exception
*     None.
* \pre
*     None.
* \post
*     None.
* \return
*     uint8
*      - KU8_ATM_TEST_OK
*  	   - KU8_ATM_TEST_NOK
*  	   - KU8_ATM_TEST_NOT_DECIDED.
**/
void BMM_Autotest_CheckHallEffectSensor(u8TestResultType * pu8TestResult)
{
   /* These are the filtered physical values measured on each Hall Effect Sensor
    * power input provided by ASM */
   uint16 u16FilteredHESAInputVoltage_lsb;
   uint16 u16FilteredHESBInputVoltage_lsb;

   /* This is the status of the AEC associated to Battery Under voltage auto-test */
   u8AecStatusType u8AECBatteryUVStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

   /* Returned status */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* Get UV AEC status */
   /* QAC_WARNING S 3417 5 */ /* The comma operator has been used outside a 'for' statement. */
                       /* QAC warning due to comma operator into RTE macro */
   /* QAC_WARNING S 3426 3 */ /* Right hand side of comma expression has no side effect and its value is not used.*/
                       /* QAC does not recognize RTE macros */
   Rte_Call_pclAECStatus_GetAecStatus(ERH_KU8_UVO_POWER_AEC_CFG, &u8AECBatteryUVStatus);

   /* Check if all pre conditions are met (ADC OK + UV not qualified)*/
   if(ERH_KU8_AEC_QUALIFIED_STATUS_MASK  != (u8AECBatteryUVStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
   {
      /* [COVERS: DSG_BMM_0018] */
      /* All pre-conditions are met */
      /* Get the filtered physical value measured of Hall Effect Sensor A from ASM */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
	   Rte_Call_pclHBS_A_V_raw_Get_10ms(& u16FilteredHESAInputVoltage_lsb);

      /* Get the filtered physical value measured of Hall Effect Sensor B from ASM */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
	   Rte_Call_pclHBS_B_V_raw_Get_10ms(& u16FilteredHESBInputVoltage_lsb);

      if( (u16FilteredHESAInputVoltage_lsb > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HESTestHighThrs) ||
          (u16FilteredHESBInputVoltage_lsb > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HESTestHighThrs) )
      {
         /* One of the HES input voltage is out of range : return NOK */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
      else if( (u16FilteredHESAInputVoltage_lsb <= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HESTestLowThrs) ||
               (u16FilteredHESBInputVoltage_lsb <= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HESTestLowThrs) )
      {
         /* One of the HES input voltage is out of range : return NOK */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
      else
      {
         /* Input voltage of both HES are in correct range : return OK */
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
   }
   else
   {
      /* One of the pre-conditions is not met, return NOT_DECIDED */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   }

   /* Return the computed test result */
   *pu8TestResult = u8ResultOfAutoTest;
}
#define BMM_AC_BeltMovementMonitoring_STOP_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
