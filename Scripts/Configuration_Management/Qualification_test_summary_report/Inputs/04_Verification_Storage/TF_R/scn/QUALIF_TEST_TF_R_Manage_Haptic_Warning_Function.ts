/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_R_Manage_Haptic_Warning_Function
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_R_1620, ALV_EXT_TF_R_1720, ALV_EXT_TF_R_1724
Description of the requirement:
ALV_EXT_TF_R_1620: The [Internal Haptic Warning abortion status] shall be initialized to ABORTED.
ALV_EXT_TF_R_1720: The [Haptic warning phase] shall be initialized to PHASE_1 (belt slack will be first executed).
ALV_EXT_TF_R_1724: The [Haptic warning cycle #1 request] shall be initialized to NONE.	
				
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

 /*------------------------------------------------------------------------------
                                CONSTANTS
 ------------------------------------------------------------------------------*/
const cTEST_OK = true;// Constant for the tests
const cTEST_NOK = false;
const cENV_NON_INITIALIZED = "NO_INIT";// Mandatory constant
const cENV_NOK = false;// Mandatory constant
const cException_Catched = true;// MANDATORY CONSTANT FOR ALL TEST SCRIPTS

/* Function name used to place a breakpoint */
const CFGc_FunctionToTest1: String = "AbortHWA1";
const CFGc_FunctionToTest2: String = "AbortHWA0";
const CFGc_FunctionToTest3: String = "DetectActivationsForHWA";
const CFGc_FunctionToTest4: String = "TriggerHWA0";
// const CFGc_FunctionToTest4: String = "TriggerHWA1";

/* breakpoint offset declaration */
const CFGc_BP1Offset: Number = 35; 
const CFGc_BP2Offset: Number = 126;
const CFGc_BP3Offset: Number = 37;
/*Parameter and variables address*/ 
var CFGc_VariableAddress1 = "0x1FFFA81B"; // u8HapticPhase 

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "5"; 

/* WinIDEA intialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResethOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */
/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Boolean used to check if the test is succesful */
var bRetFunction: Boolean = false;
/* variable used to set breakpoint in the function tested */
var addressBP1;
/* variable used to send routine control request */
var sRequest;
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
		Wait(2000);
        debugger_stop();

		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_R_1620")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check value of variable bAbortionFlag_HWA1, corresponding to Internal Haptic warning abortion status", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value bAbortionFlag_HWA1 is set to 0, corresponding to status ABORTED", debugger_readRegister("R0","uint8"),0);
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
		
		debugger_run();
		Wait(2000);
        debugger_stop();
		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2,CFGc_BP1Offset)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check value of variable bAbortionFlag_HWA0, corresponding to Internal Haptic warning abortion status", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value bAbortionFlag_HWA0 is set to 0, corresponding to status ABORTED", debugger_readRegister("R0","uint8"),0);
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);			

		debugger_reset();
	
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_R_1720")
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest3,CFGc_BP2Offset)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check value of variable u8HapticPhase", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value u8HapticPhase is set to 255, corresponding to PHASE_1", debugger_readMemory(CFGc_VariableAddress1, 1, "int"), 255);
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);	 

		debugger_reset();	

		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_R_1724")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest4,CFGc_BP3Offset)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check value of variable bNewDiagRequest_HWA0, corresponding to the Haptic warning cycle 1 request", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value bNewDiagRequest_HWA0 is set to 0, corresponding to NONE", debugger_readRegister("R3","uint8"),0);
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);	  

		debugger_reset();

	
      /*------------------------------------------------------------------------------
                              DEINITIALIZATION ENVIRONMENT
      ------------------------------------------------------------------------------*/
        RESULT.ExpectTestResult("Reset the debugger",
			  debugger_reset(),
			  cTEST_OK
			  )

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