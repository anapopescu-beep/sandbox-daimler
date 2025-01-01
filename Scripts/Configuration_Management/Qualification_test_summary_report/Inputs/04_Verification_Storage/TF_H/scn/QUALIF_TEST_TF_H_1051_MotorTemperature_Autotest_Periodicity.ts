/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_1051_MotorTemperature_Autotest_Periodicity
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_1051
Description of the requirement: Motor Temperature test shall be performed periodically, every 100 ms, only during running auto test phase.
************************************************************************************************
Equipment: PowerSupply, CanCaseXL, MockUp, Debugger
Test Notes: This script checks the periodicity of Motor Temperature autotest (running phase)
Full Automation: Yes
Global Result Assignment: Neeva
***********************************************************************************************/

/*------------------------------------------------------------------------------
                                LIBRARY IMPORT 
 ------------------------------------------------------------------------------*/
CALL(/../../ProjectLib_Development/SBE_Configuration.ts);
CALL(/../../ProjectLib_Development/QUALIF_LIB/PP4G_LIB_QUALIF_TF_H.ts);
/*------------------------------------------------------------------------------
                               CONSTANTS
 ------------------------------------------------------------------------------*/
/* Constants for the tests */
const cTEST_OK             = true; 
const cTEST_NOK            = false;

/* Mandatory constants */
const cENV_NON_INITIALIZED = "NO_INIT";
const cENV_NOK             = false;
const cEXCEPTION_CATCHED   = true;

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
var bRetFunction: Boolean;
/*------------------------------------------------------------------------------
                                   Test Core
 ------------------------------------------------------------------------------*/
try {
   /*------------------------------------------------------------------------------
                           ENVIRONMENT INITIALIZATION 
    ------------------------------------------------------------------------------*/
   bRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOn", "RunOff", "50");
   if (bRetFunction != cENV_NON_INITIALIZED && bRetFunction != cENV_NOK) {

      /*------------------------------------------------------------------------------
                                       TEST EXECUTION
       ------------------------------------------------------------------------------*/
      PP4G_LibQualif_Check_AtPeriodicity_Run(
         CFGc_MotorThermalProtc_At_FctName,
         CFGc_MotorThermalProtc_At_Period,
         Libc_BPOffset
      );
	  
	  

      /*------------------------------------------------------------------------------
                              ENVIRONMENT DEINITIALIZATION 
       ------------------------------------------------------------------------------*/
      RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
   }
   else 
   {
      winIDEAWorkspace_closeDiscard();
      RESULT.ExpectTestResult("Test failed about environment initialization failed", cTEST_NOK, cTEST_OK);
   }
}
catch (exError) 
{
   RESULT.ExpectTestResult("Test failed about exception occurs :" + exError, cEXCEPTION_CATCHED, cTEST_NOK);
   RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}