/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_1059_1062_Input_NVP_Parameters
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_1059, ALV_EXT_TF_H_1062
Description of the requirement:
- Temperature Threshold above which SW Thermal NVP_u32SWThermalProtectionValidationThrs protection shall be actived shall be an input to the autest which monitors the system temperature evolution
- Temperature Threshold below which SW Thermal NVP_u32SWThermalProtectionDeskillingThrs protection shall be actived shall be an input to the autest which monitors the system temperature evolution
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
 CALL(/../../ProjectLib_Development/INTEG_LIB/PP4G_LIB_INTEG_OS.ts);
 CALL(Config/QUALIF_TESTCFG_TF_H_1059_1062_Input_NVP_Parameters.ts);

 /*------------------------------------------------------------------------------
                                CONSTANTS
 ------------------------------------------------------------------------------*/
const cTEST_OK = true;// Constant for the tests
const cTEST_NOK = false;
const cENV_NON_INITIALIZED = "NO_INIT";// Mandatory constant
const cENV_NOK = false;// Mandatory constant
const cException_Catched = true;// MANDATORY CONSTANT FOR ALL TEST SCRIPTS
var CFGc_NumberOfData = 1;
var numberOfTickInit; 
var numberOfTick;
var periodicity;
var ExperyPoint;
var addressBP1;
var addressBP2;
var bIsBPset: Boolean = false;
var sintBPTimeout: Number = 5000;
var bBreakPointResult: Boolean = false;
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
            debugger_run();

            CommentStep("Wait ECU to wake up");
            Wait(5000);

            /* Set a breakpoint in the tested function */
            addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,0)[3] 
            RESULT.ExpectTestResult("Run application", debugger_run(), true);
            RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
            RESULT.ExpectTestResult("The function "+CFGc_FunctionToTest1+" is reached", debugger_isCPUStoppedAtAddress(addressBP1), true);
			
             
             /* Set a breakpoint in the tested function */
            addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,sintOffsetBP2)[3] 
            RESULT.ExpectTestResult("Run application", debugger_run(), true);
            RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(2000), true);
            CommentStep("The NVP_u32SWThermalProtectionDeskillingThrs parameter is reached at line 3506");
   

            /* Set a breakpoint in the tested function */
            addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,sintOffsetBP3)[3] 
            RESULT.ExpectTestResult("Run application", debugger_run(), true);
            RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(2000), true);
            RESULT.ExpectTestResult("The NVP_u32SWThermalProtectionValidationThrs parameter is reached", debugger_isCPUStoppedAtAddress(addressBP1), true);
		
			 
			//RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
      /*------------------------------------------------------------------------------
                              DEINITIALIZATION ENVIRONMENT
      ------------------------------------------------------------------------------*/
      RESULT.ExpectTestResult("Reset the debugger",
			debugger_reset(),
			cTEST_OK
			);

        // "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger). This function is mandatory
        /* RESULT.ExpectTestResult("Close environment test",
         winIDEAWorkspace_closeDiscard(),
           cTEST_OK
      );*/
    }
   else
   {
      //winIDEAWorkspace_closeDiscard();
   }
}
catch(exError)
{
   RESULT.ExpectTestResult("Test failed about exception occurs :"+exError,
      cException_Catched,
      false
   );

  /* RESULT.ExpectTestResult("Close environment test",
      winIDEAWorkspace_closeDiscard(),
      cTEST_OK
   );*/
}