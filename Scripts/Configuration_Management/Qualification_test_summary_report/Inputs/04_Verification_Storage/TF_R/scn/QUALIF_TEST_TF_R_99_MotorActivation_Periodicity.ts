/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_R_99_MotorActivation_Periodicity
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_R_99 
Description of the requirement:
The function to detect motor activation shall be executed every 10ms.
************************************************************************************************
Equipment: PowerSupply, CanCaseXL, MockUp, IC5000 debugger
Test Notes: 
Full Automation: Yes
Global Result Assignment: Neeva
************************************************************************************************/
/********************************************************************************/
/*                             Format test script                               */
/********************************************************************************/
/*------------------------------------------------------------------------------
                                IMPORT LIBRARY
 ------------------------------------------------------------------------------*/
 CALL(/../../ProjectLib_Development/SBE_Configuration.ts);
 CALL(/../../ProjectLib_Development/INTEG_LIB/PP4G_LIB_INTEG_SCH.ts);

 /*------------------------------------------------------------------------------
                                CONSTANTS
 ------------------------------------------------------------------------------*/
const cTEST_OK = true;// Constant for the tests
const cTEST_NOK = false;
const cENV_NON_INITIALIZED = "NO_INIT";// Mandatory constant
const cENV_NOK = false;// Mandatory constant
const cException_Catched = true;// MANDATORY CONSTANT FOR ALL TEST SCRIPTS

/* Function name used to place a breakpoint */
const CFGc_CallingFunctionToTest: String = "EOL_runMainFunction";
const CFGc_CalledFunctionToTest: String = "ManageCycleCounters";
const CFGc_CallingFunctionToTest_1: String = "ManageCommonInputsForAllSFR";
const CFGc_CalledFunctionToTest_1: String = "EvaluateSuccessfullCyclesForAllSFR";

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50"; 

/* WinIDEA intialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResethOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */

/*number of OS tick */ 
var CFGc_NumberCounterAddress = 536851192; // OS_counterDynamic_core0
var CFGc_NumberOfData = 1;
var CFGc_Periodicity = 10;
 
/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/


/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Boolean used to check if the test is succesful */
var bRetFunction: Boolean = false;


/*------------------------------------------------------------------------------
                                    Core Test
------------------------------------------------------------------------------*/

try
{
   /*------------------------------------------------------------------------------
                           INITIALIZATION ENVIRONMENT
   ------------------------------------------------------------------------------*/
   /**** This function is parametrable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/

   /****** WARNING : check optionnal parameter of the next function :it's very IMPORTANT ***********/
   vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply(CFGc_FlashMode, CFGc_ResetMode, CFGc_RunMode, CFGc_MinCurrentToRunTest);
   if(vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK)
   {
      /*------------------------------------------------------------------------------
                                 EXECUTION TEST
      ------------------------------------------------------------------------------*/
      /* Call integration library to check if the function is correctly called */
	  
	  CommentStep("Periodicity of New started cycle Detection - EOL")
      bRetFunction = PP4G_LibInteg_CheckPeriodicityFunctionCall(CFGc_CalledFunctionToTest,CFGc_CallingFunctionToTest,CFGc_NumberCounterAddress, CFGc_Periodicity);

      /*** Check result of test ****/
      RESULT.ExpectTestResult("Global Verification of test",
      bRetFunction,
      cTEST_OK
      );
	  
	  RESULT.ExpectTestResult("Delete all breakpoints", debugger_deleteAllBreakpoints(), true);
      debugger_run();
      Wait(100);
	  
	  /* Call integration library to check if the function is correctly called */
	  CommentStep("Periodicity of New ended cycle Detection - SFR")
      bRetFunction = PP4G_LibInteg_CheckPeriodicityFunctionCall(CFGc_CalledFunctionToTest_1,CFGc_CallingFunctionToTest_1,CFGc_NumberCounterAddress, CFGc_Periodicity);

      /*** Check result of test ****/
      RESULT.ExpectTestResult("Global Verification of test",
      bRetFunction,
      cTEST_OK
      );

      /*------------------------------------------------------------------------------
                              DEINITIALIZATION ENVIRONMENT
      ------------------------------------------------------------------------------*/
      RESULT.ExpectTestResult("Reset the debugger",
         debugger_reset(),
         cTEST_OK
      );

        // "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger). This function is mandatory
         RESULT.ExpectTestResult("Close environment test",
         winIDEAWorkspace_closeDiscard(),
         cTEST_OK
      );
    }
   else
   {
      winIDEAWorkspace_closeDiscard();
   }
}
catch(exError)
{
   RESULT.ExpectTestResult("Test failed about exception occurs :"+exError,
      cException_Catched,
      false
   );

   RESULT.ExpectTestResult("Close environment test",
      winIDEAWorkspace_closeDiscard(),
      cTEST_OK
   );
}