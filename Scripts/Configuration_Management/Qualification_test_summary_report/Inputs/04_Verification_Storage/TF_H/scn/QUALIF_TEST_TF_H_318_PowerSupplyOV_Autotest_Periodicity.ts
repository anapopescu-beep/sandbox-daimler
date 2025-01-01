/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_318_PowerSupplyOV_Autotest_Periodicity
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_318
Description of the requirement: Power Supply OV test shall be performed periodically, every 100 ms, in both startup auto test phase and running auto test phase.
************************************************************************************************
Equipment: PowerSupply, CanCaseXL, MockUp, Debugger
Test Notes: This script checks the periodicity of Power Supply OV autotest (start up and running phases)
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
      PP4G_LibQualif_CheckPeriodicity_StartUp_And_Run(
         CFGc_PowerSupplyOV_At_FctName,
         CFGc_PowerSupplyOV_At_Period,
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