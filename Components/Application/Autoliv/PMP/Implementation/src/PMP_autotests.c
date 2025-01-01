
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
$Revision: 1.1.7.27 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/PMP/Implementation/src/project.pj $
 */
/* PRQA S 0288 -- */

/**
 *  @defgroup PMP_autotest.c PMP
 *  This is a new created group, this will create a new man3 file with 
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file. 
 */

/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "common.h"
#include "Rte_PMP_AC_PhysicalMeasuresProvider.h"

#include "PMP_private.h"
#include "Nvp_Generated.h"
#include "Nvp_Cfg.h"

/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
/**
 * \brief
 *    Internal macro for value 500.
 */
#define PMP_KU16_FIVE_HUNDRED                            ((uint16)500)
/**
 * \brief
 *    Internal macro for no request.
 */
#define PMP_KU8_NO_REQUEST                                (255U)
/**
 * \brief
 *    Internal macro for no request.
 */
#define PMP_KU16_SUPBAT_SNA                                (1023U)

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
/**
 * \brief
 *		Defined macro from C file.
 */
#define PMP_AC_PhysicalMeasuresProvider_START_SEC_CODE
#include "PMP_AC_PhysicalMeasuresProvider_MemMap.h"

/**
* \brief
*     This is the test function for overvoltage on the Power stage battery voltage.
* \param
*      [u8TestResultType * pu8TestResult]      
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None. 
* \pre
*     This test is deactivated during cranking, and resumes when cranking finish is confirmed.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0022] */
void PMP_Autotest_CheckPowerSupplyOV(u8TestResultType * pu8TestResult)
{
   /* This is the filtered physical value measured on ADC Power Vbat pin that will be provided by PMP */
   u16VoltageType pmp_u16FilteredVbatPowerVoltage;

   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType pmp_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

   /* Returned status */
   u8TestResultType pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* To store ADC auto-test status from ATM */
   uint8 u8PreviousADCTestResult;

   /* Get ADC auto-test result */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC, &u8PreviousADCTestResult);

   /* To execute this auto-test, ADC auto-test shall be passed and battery under voltage
    * AEC shall not be qualified */
   if(KU8_ATM_TEST_OK == u8PreviousADCTestResult)
   {
      /* ADC auto-test are OK, we can get the battery voltage */
      /* Get the filtered physical value measured on ADC Power Vbat pin from PMP */
	   PMP_runGetBatteryVoltage_10ms(&pmp_u16FilteredVbatPowerVoltage);

      /* Read last state of autotest */
      Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_OVO_POWER_AEC_CFG, &pmp_u8AECStatus);

      /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
      if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK != (pmp_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
      {
         /* The associated AEC is deskilled: Check if KL30 is under NVP_u16OverKL30QualificationThrs*/
         if (NVP_stVehicleEquipmentData.Overvoltage > pmp_u16FilteredVbatPowerVoltage)
            /* [COVERS: DSG_PMP_0026] */
         {
            /* Voltage is below the threshold, return OK */
            pmp_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         else
            /* [COVERS: DSG_PMP_0027] */
         {
            /* Voltage is over the threshold, return NOK */
            pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }
      else
      {
         /* The associated AEC is qualified: Check if KL30 is under NVP_u16OverKL30DeskillingThrs */
         if ((NVP_stVehicleEquipmentData.Overvoltage - PMP_KU16_FIVE_HUNDRED) > pmp_u16FilteredVbatPowerVoltage)
            /* [COVERS: DSG_PMP_0024] */
         {
            /* Voltage is below the threshold, return OK */
            pmp_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         else
            /* [COVERS: DSG_PMP_0025] */
         {
            /* Voltage is over the threshold, return NOK */
            pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }
   }
   else
      /* [COVERS: DSG_PMP_0023] */
   {
      /* Conditions are not correct to execute the test, do nothing.
       * Test output has been already initialized to NOT_DECIDED */
   }

   /* Return the auto test status */
   *pu8TestResult = pmp_u8ResultOfAutoTest;
}

/**
* \brief
*     This is the test function for undervoltage on the Power stage battery voltage.
* \param
*      [u8TestResultType * pu8TestResult]      
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None. 
* \pre
*     This test is deactivated during cranking or tensioning, and resumes when cranking finish is confirmed.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0028] */
void PMP_Autotest_CheckPowerSupplyUV(u8TestResultType * pu8TestResult)
{
   /* This is the filtered physical value measured on ADC Power Vbat pin that will be provided by PMP */
   u16VoltageType pmp_u16FilteredVbatPowerVoltage ;

   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType pmp_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

   /* To store ADC auto-test status from ATM */
   uint8  u8PreviousADCTestResult;

   /* Returned status */
   u8TestResultType pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* Get ADC auto-test result */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC, &u8PreviousADCTestResult);

   /* This auto-test shall be executed only if ADC auto-test are passed and
    * AEC battery over voltage is not qualified                            */
   if(KU8_ATM_TEST_OK == u8PreviousADCTestResult)
   {
      /* All pre conditions are met, the test can be executed */
      /* Get the filtered physical value measured on ADC Power Vbat pin from PMP */
	   PMP_runGetBatteryVoltage_10ms(&pmp_u16FilteredVbatPowerVoltage);

      /* Read last state of autotest */
      Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_UVO_POWER_AEC_CFG, &pmp_u8AECStatus);

      /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
      if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK != (pmp_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
      {
         /* The associated AEC is deskilled: Check if KL30 is over NVP_u16UnderKL30QualificationThrs*/
         if (NVP_stVehicleEquipmentData.Undervoltage <= pmp_u16FilteredVbatPowerVoltage)
            /* [COVERS: DSG_PMP_0032] */
         {
            /* Voltage is over the threshold, return OK */
            pmp_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         else
            /* [COVERS: DSG_PMP_0033] */
         {
            /* Voltage is below the threshold, return NOK */
            pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }
      else
      {
         /* The associated AEC is qualified: Check if KL30 is over NVP_u16UnderKL30DeskillingThrs */
         if ((NVP_stVehicleEquipmentData.Undervoltage + PMP_KU16_FIVE_HUNDRED) <= pmp_u16FilteredVbatPowerVoltage)
            /* [COVERS: DSG_PMP_0030] */
         {
            /* Voltage is over the threshold, return OK */
            pmp_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         else
            /* [COVERS: DSG_PMP_0031] */
         {
            /* Voltage is below the threshold, return NOK */
            pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }
   }
   else
      /* [COVERS: DSG_PMP_0029] */
   {
      /* Conditions are not correct to execute the test, do nothing.
       * Test output has been already initialized to NOT_DECIDED */
   }

   /* Return the auto test status */
   *pu8TestResult = pmp_u8ResultOfAutoTest;
}

/**
* \brief
*     his is the test function for undervoltage on the Power stage battery voltage during tensioning.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
*     This test is deactivated during cranking or tensioning, and resumes when cranking finish is confirmed.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0035] */
void PMP_Autotest_CheckPowerSupplyUVDuringActivation(u8TestResultType *pu8TestResult)
{
   /* This is the filtered physical value measured on ADC Power Vbat pin that will
      be provided by ASM */
   u16VoltageType u16FilteredVbatPowerVoltage;

   /* To store ADC auto-test status from ATM */
   uint8 u8PreviousADCTestResult;

   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType pmp_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

   /* Returned status */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* To check there is a tensioning cycle */
   u8ModeStatusType u8TensioningModeStatus = KU8_MODE_STATUS_ON;

   /* To check if trigger is active or not */
   uint8 u8PresafeTriggerRequest = PMP_KU8_NO_REQUEST;

   /* Get ADC auto-test result */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC, &u8PreviousADCTestResult);

   /* This auto-test can be played only if ADC auto-tests are passed and under voltage
    * AEC is not qualified */
   if (KU8_ATM_TEST_OK == u8PreviousADCTestResult)
   {
      /* Get the "tensioning" system context status */
      Rte_Call_pclModeManagement_CheckModeStatus(MMG_KU32_MASK_TENSIONING, &u8TensioningModeStatus);

      /* Get status of request */
      (void)Rte_Read_prrCustomerSpecific_u8TriggerRequest(&u8PresafeTriggerRequest);

      /* Get the filtered physical value measured on ADC Power Vbat pin from PMP */
      PMP_runGetBatteryVoltage_10ms(&u16FilteredVbatPowerVoltage);

      /* Read last state of autotest */
      Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_UVO_TENSIONING_POWER_AEC_CFG, &pmp_u8AECStatus);

      /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
      if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK != (pmp_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
      {
         /* AEC deskilled, use the qualify threshold to determine test output */
         /* Trigger request, case*/
         if(PMP_KU8_NO_REQUEST != u8PresafeTriggerRequest)
         {
            if (NVP_stVehicleEquipmentData.Undervoltage <= u16FilteredVbatPowerVoltage)
            {
               /* Voltage is over the threshold, return OK */
               u8ResultOfAutoTest = KU8_ATM_TEST_OK;
            }
            else
            {
               /* Voltage is under the Threshold, return NOK */
               u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            }
         }
         /* Request cycle is on, case */
         else
         {
            /* Do nothing */
         }
         if(KU8_MODE_STATUS_ON == u8TensioningModeStatus)
         {
            if (NVP_stVehicleEquipmentData.UndervoltageAbort <= u16FilteredVbatPowerVoltage)
            {
               /* [COVERS: DSG_PMP_0039] */
               /* Voltage is over the threshold, return OK */
               u8ResultOfAutoTest = KU8_ATM_TEST_OK;
            }
            else
            {
               /* [COVERS: DSG_PMP_0038]
            /* Voltage is under the Threshold, return NOK */
               u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            }
         }
         else
         {
            /* Do nothing */
         }
      }
      /* AEC  qualified */
      else
      {
         /* Trigger request case*/
         if(PMP_KU8_NO_REQUEST != u8PresafeTriggerRequest)
         {
            /* Autotest  qualified and a trigger on, use the qualification threshold to determine test output */
            if ((NVP_stVehicleEquipmentData.Undervoltage + PMP_KU16_FIVE_HUNDRED) <= u16FilteredVbatPowerVoltage)
            {
               /* Voltage is over the threshold, return OK */
               u8ResultOfAutoTest = KU8_ATM_TEST_OK;
            }
            else
            {
               /* Voltage is under the Threshold, return NOK */
               u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            }
         }
         /* Request cycle on case */
         else
         {
        	 /* Autotest qualified and a tensioning cycle is going on, use the qualification threshold to determine test output */
        	 if ((NVP_stVehicleEquipmentData.Undervoltage) <= u16FilteredVbatPowerVoltage)
        	 {
        		 /* [COVERS: DSG_PMP_0037] */
        		 /* Voltage is over the threshold, return OK */
        		 u8ResultOfAutoTest = KU8_ATM_TEST_OK;
        	 }
        	 else
        	 {
        		 /* [COVERS: DSG_PMP_0040] */
        		 /* Voltage is under the Threshold, return NOK */
        		 u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
        	 }
         }
      }
   }
   else
   {
      /* [COVERS: DSG_PMP_0036] */
      /* One of the three pre-conditions are not set, return NOT_DECIDED */
      /* Do nothing, the return value has already been initialized to NOT_DECIDED */
   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
* \brief
*     This is the test function for overvoltage on the Power stage battery voltage during tensioning.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
*     This test is deactivated during cranking, and resumes when cranking finish is confirmed.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0041] */
void PMP_Autotest_CheckPowerSupplyOVDuringActivation(u8TestResultType * pu8TestResult)
{
   /* This is the filtered physical value measured on ADC Power Vbat pin that will be provided by PMP */
   u16VoltageType pmp_u16FilteredVbatPowerVoltage;

   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType pmp_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

   /* Returned status */
   u8TestResultType pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* To store ADC auto-test status from ATM */
   uint8  u8PreviousADCTestResult;

   /* To check there is a tensioning cycle */
   u8ModeStatusType u8TensioningModeStatus;

   /* To check if trigger is active or not */
   uint8 u8PresafeTriggerRequest = PMP_KU8_NO_REQUEST;

   /* Get ADC auto-test result */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC, &u8PreviousADCTestResult);

   /* To execute this auto-test, ADC auto-test shall be passed and logic battery under voltage
    * AEC shall not be qualified */
   if(KU8_ATM_TEST_OK == u8PreviousADCTestResult)
   {
      /* Get the "tensioning" system context status */
      Rte_Call_pclModeManagement_CheckModeStatus(MMG_KU32_MASK_TENSIONING, &u8TensioningModeStatus);

      /* Get status of request */
      (void)Rte_Read_prrCustomerSpecific_u8TriggerRequest(&u8PresafeTriggerRequest);

      /* ADC auto-test are OK and LOG_UV AEC is not qualified, we can get the logical battery voltage */
      /* Get the filtered physical value measured on ADC Power Vbat pin from PMP */
      PMP_runGetBatteryVoltage_10ms(&pmp_u16FilteredVbatPowerVoltage);

      /* Read last state of autotest */
      Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_OVO_TENSIONING_POWER_AEC_CFG, &pmp_u8AECStatus);

      /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
      if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK != (pmp_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
      {
         /* Trigger request, case*/
         if(PMP_KU8_NO_REQUEST != u8PresafeTriggerRequest)
         {
            /* The associated autotest is deskilled: Check if KL30 is under NVP_u16OverKL30QualificationThrs*/
            if (NVP_stVehicleEquipmentData.Overvoltage > pmp_u16FilteredVbatPowerVoltage)
               /* [COVERS: DSG_PMP_0045] */
            {
               /* Voltage is below the threshold, return OK */
               pmp_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
            }
            else
               /* [COVERS: DSG_PMP_0046] */
            {
               /* Voltage is over the threshold, return NOK */
               pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            }
         }
         /* Request cycle is on, case */
         else
         {
            /* Do nothing */
         }
         if(KU8_MODE_STATUS_ON == u8TensioningModeStatus)
         {
            /* The associated autotest is deskilled: Check if KL30 is under NVP_u16OverKL30QualificationThrs*/
            if (NVP_stVehicleEquipmentData.OvervoltageAbort > pmp_u16FilteredVbatPowerVoltage)
               /* [COVERS: DSG_PMP_0045] */
            {
               /* Voltage is below the threshold, return OK */
               pmp_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
            }
            else
               /* [COVERS: DSG_PMP_0046] */
            {
               /* Voltage is over the threshold, return NOK */
               pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            }
         }
         else
         {
            /* Do nothing */
         }

      }
      else
      {
         if(PMP_KU8_NO_REQUEST != u8PresafeTriggerRequest)
         {
            /* The associated AEC is qualified: Check if KL30 is under NVP_u16OverKL30DeskillingThrs */
            if ((NVP_stVehicleEquipmentData.Overvoltage - PMP_KU16_FIVE_HUNDRED) > pmp_u16FilteredVbatPowerVoltage)
               /* [COVERS: DSG_PMP_0043] */
            {
               /* Voltage is below the threshold, return OK */
               pmp_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
            }
            else
               /* [COVERS: DSG_PMP_0044] */
            {
               /* Voltage is over the threshold, return NOK */
               pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            }
         }
         else
         {
            /* The associated autotest is qualified: Check if KL30 is under NVP_u16OverKL30DeskillingThrs */
            if ((NVP_stVehicleEquipmentData.Overvoltage) > pmp_u16FilteredVbatPowerVoltage)
               /* [COVERS: DSG_PMP_0043] */
            {
               /* Voltage is below the threshold, return OK */
               pmp_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
            }
            else
               /* [COVERS: DSG_PMP_0044] */
            {
               /* Voltage is over the threshold, return NOK */
               pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            }
         }

      }
   }
   else
      /* [COVERS: DSG_PMP_0042] */
   {
      /* Conditions are not correct to execute the test, do nothing.
       * Test output has been already initialized to NOT_DECIDED */
   }

   /* Return the auto test status */
   *pu8TestResult = pmp_u8ResultOfAutoTest;
}
/**
* \brief
*     This is the test function for System overvoltage.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
*     This test is deactivated during cranking or tensioning, and resumes when cranking finish is confirmed.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0028] */
void PMP_Autotest_CheckSystemUV(u8TestResultType * pu8TestResult)
{
   /* [COVERS: DSG_PMP_0055] */
   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType pmp_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

   /* Returned status */
   /* [COVERS: DSG_PMP_0056] */
   u8TestResultType pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* This is the value of system voltage signal*/
   uint16 pmp_SystemVoltageSignal = KU8_ZERO;

   /* This is value in V for system voltage signal*/
   uint16 pmp_SystemVoltage = KU8_ZERO;

   /* Read last state of autotest */
   Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_SYSTEM_UV_AEC_CFG, &pmp_u8AECStatus);

   /*Read signal for system voltage */
   Rte_Read_R_PN14_SupBat_Volt_ST3_PN14_SupBat_Volt_ST3(&pmp_SystemVoltageSignal);


   if(PMP_KU16_SUPBAT_SNA == pmp_SystemVoltageSignal)
   {
	   (void)Rte_Write_isrSupBatStatus_b8SupBatStatus(KU8_TRUE);
   }
   else
	   (void)Rte_Write_isrSupBatStatus_b8SupBatStatus(KU8_FALSE);

   /* Conversion of signal PN14_SupBat_Volt_ST3 in V*/
   /* [COVERS: DSG_PMP_0061] */
   pmp_SystemVoltage = pmp_SystemVoltageSignal * PMP_KU8_VOLTAGE_CONVERSION;

   /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
   if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK != (pmp_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
   {
      /* The associated AEC is deskilled: Check if KL30 is over NVP_u16UnderKL30QualificationThrs*/
      if (NVP_stVehicleEquipmentData.Undervoltage <= pmp_SystemVoltage)
         /* [COVERS: DSG_PMP_0059] */
      {
         /* Voltage is over the threshold, return OK */
         pmp_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
      else
         /* [COVERS: DSG_PMP_0060] */
      {
         /* Voltage is below the threshold, return NOK */
         pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
   }
   else
   {
      /* The associated AEC is qualified: Check if KL30 is over NVP_u16UnderKL30DeskillingThrs */
      if ((NVP_stVehicleEquipmentData.Undervoltage + PMP_KU16_FIVE_HUNDRED) <= pmp_SystemVoltage)
         /* [COVERS: DSG_PMP_0057] */
      {
         /* Voltage is over the threshold, return OK */
         pmp_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
      else
         /* [COVERS: DSG_PMP_0058] */
      {
         /* Voltage is below the threshold, return NOK */
         pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
   }


   /* Return the auto test status */
   *pu8TestResult = pmp_u8ResultOfAutoTest;
}
/**
* \brief
*     This is the test function for System overvoltage.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
*     This test is deactivated during cranking, and resumes when cranking finish is confirmed.
* \post
*     None.
* \return
*     None.
**/

void PMP_Autotest_CheckSystemOV(u8TestResultType * pu8TestResult)
{
   /* [COVERS: DSG_PMP_0053] */
   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType pmp_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

   /* This is the value of system voltage signal*/
   uint16 pmp_SystemVoltageSignal = KU8_ZERO;

   /* This is value in V for system voltage signal*/
   uint16 pmp_SystemVoltage = KU8_ZERO;

   /* Returned status */
   /* [COVERS: DSG_PMP_0054] */
   u8TestResultType pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* Read last state of autotest */
   Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_SYSTEM_OV_AEC_CFG, &pmp_u8AECStatus);

   /*Read signal for system voltage */
   Rte_Read_R_PN14_SupBat_Volt_ST3_PN14_SupBat_Volt_ST3(&pmp_SystemVoltageSignal);

   /* Conversion of signal PN14_SupBat_Volt_ST3 in V*/
   /* [COVERS: DSG_PMP_0061] */
   pmp_SystemVoltage = pmp_SystemVoltageSignal * PMP_KU8_VOLTAGE_CONVERSION;

   /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
   if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK != (pmp_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
   {
      /* The associated AEC is deskilled: Check if KL30 is under NVP_u16OverKL30QualificationThrs*/
      if (NVP_stVehicleEquipmentData.Overvoltage >= pmp_SystemVoltage)
         /* [COVERS: DSG_PMP_0051] */
      {
         /* Voltage is below the threshold, return OK */
         pmp_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
      else
         /* [COVERS: DSG_PMP_0052] */
      {
         /* Voltage is over the threshold, return NOK */
         pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
   }
   else
   {
      /* The associated AEC is qualified: Check if KL30 is under NVP_u16OverKL30DeskillingThrs */
      if ((NVP_stVehicleEquipmentData.Overvoltage - PMP_KU16_FIVE_HUNDRED) >= pmp_SystemVoltage)
         /* [COVERS: DSG_PMP_0049] */
      {
         /* Voltage is below the threshold, return OK */
         pmp_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
      else
         /* [COVERS: DSG_PMP_0050] */
      {
         /* Voltage is over the threshold, return NOK */
         pmp_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
   }

   /* Return the auto test status */
   *pu8TestResult = pmp_u8ResultOfAutoTest;
}

/**
* \brief
*     This autotest aims at detecting a SBC temperature error. The temperature provided by the SBC module is compared 
*     to a low and high threshold. If the temperature value is out of range, 
*     this autotest returns "failed" result, otherwise it returns "passed" result.
* \param
*      [u8TestResultType * pu8TestResult]      
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None. 
* \pre
*     this test is deactivated during cranking situation. It resumes after all situations are confirmed finish by RCM.
* \post
*     None.
* \return
*     None.
**/
void PMP_Autotest_CheckTemperatureSensor(u8TestResultType * pu8TestResult)
{
   /* To store the previous ADC test execution result */
   u8TestResultType u8PreviousADCTestResult;

   /* Returned status */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /*Used to get internal temp value*/
   uint16 u16InternalECUTemperature;

   /* Get previous ADC auto-test result */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC, &u8PreviousADCTestResult);

   /* Check if ADC pre-condition is met */
   if(KU8_ATM_TEST_OK == u8PreviousADCTestResult)
      /* [COVERS: DSG_PMP_0047] */
   {  /*Get the internal temperature*/
	   pmp_GetCorrectedTemperature(&u16InternalECUTemperature);

      /*Check if internal temp is between thresholds*/
	  if ((NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16TemperatureSensorLowThrs <= u16InternalECUTemperature) && (NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16TemperatureSensorHighThrs >= u16InternalECUTemperature))
	  {
          u8ResultOfAutoTest = KU8_ATM_TEST_OK;
	  }
	  else
	  {
          u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
	  }
   }
   else if (KU8_ATM_TEST_NOK == u8PreviousADCTestResult)
      /* [COVERS: DSG_PMP_0048] */
   {
      /* ADC out of order, sensor will be out of order too */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }
   else
   {
      u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   }

   /* Return the computed test result */
   *pu8TestResult = u8ResultOfAutoTest;
}


/**
 * \brief
 *		Defined macro from C file.
 */
#define PMP_AC_PhysicalMeasuresProvider_STOP_SEC_CODE
#include "PMP_AC_PhysicalMeasuresProvider_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
