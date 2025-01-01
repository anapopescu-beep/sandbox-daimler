/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_R_Manage_Releasing_Function
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_R_1829, ALV_EXT_TF_R_1862, ALV_EXT_TF_R_1917, ALV_EXT_TF_R_1920, ALV_EXT_TF_R_1923
Description of the requirement:
ALV_EXT_TF_R_1829: The [Releasing Function inhibition status] shall be initialized to INHIBITED.
ALV_EXT_TF_R_1862: The [Anti-Patina cycle request] shall be initialized to TRUE.
ALV_EXT_TF_R_1917: The [Hard Releasing cycle request] shall be initialized to NONE.	
ALV_EXT_TF_R_1920: The [Smooth Releasing cycle request] shall be initialized to NONE.
ALV_EXT_TF_R_1923: The [Backup Releasing cycle request] shall be initialized to NONE.

				
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
// CALL(/../../ProjectLib_Development/INTEG_LIB/PP4G_LIB_INTEG_SCH.ts);

 /*------------------------------------------------------------------------------
                                CONSTANTS
 ------------------------------------------------------------------------------*/
const cTEST_OK = true;// Constant for the tests
const cTEST_NOK = false;
const cENV_NON_INITIALIZED = "NO_INIT";// Mandatory constant
const cENV_NOK = false;// Mandatory constant
const cException_Catched = true;// MANDATORY CONSTANT FOR ALL TEST SCRIPTS

/* Function name used to place a breakpoint */
const CFGc_FunctionToTest1: String = "SFR_runStandardFunctionRecovery";
const CFGc_FunctionToTest3: String = "TriggerHRD";
const CFGc_FunctionToTest4: String = "TriggerSMO";
const CFGc_FunctionToTest5: String = "TriggerBCK";


/* breakpoint offset declaration */
const CFGc_BP1Offset: Number = 82; 
const CFGc_BP2Offset: Number = 118; 
const CFGc_BP3Offset: Number = 0; 
const CFGc_BP4Offset: Number = 0; 
const CFGc_BP5Offset: Number = 0;

/*Parameter and variables address*/ 
var CFGc_VariableAddress1 = "0x1FFFA8FD"; // b8NewInterruptFlag_SMO
var CFGc_VariableAddress2 = "0x1FFFA900"; // b8NewPreActivationFlag_PAT
var CFGc_VariableAddress3 = "0x1FFFA92C"; // X_u8PreviousTriggeringSource_HRD
var CFGc_VariableAddress4 = "0x1FFFA930"; // X_u8PreviousTriggeringSource_SMO
var CFGc_VariableAddress5 = "0x1FFFA92A"; // X_u8PreviousTriggeringSource_BCK

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

		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_R_1829")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check value of variable b8NewInterruptFlag_SMO, corresponding to the Releasing Function Inhibition status", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value b8NewInterruptFlag_SMO is set to FALSE, corresponding to Inhibitied", debugger_readMemory(CFGc_VariableAddress1, 1, "int"),"85");
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
		
		debugger_reset();

		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_R_1862")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP2Offset)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check value of variable b8NewPreActivationFlag_PAT, corresponding to Anti-Patina cycle request", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value b8NewPreActivationFlag_PAT is set to 170, corresponding to TRUE", debugger_readMemory(CFGc_VariableAddress2, 1, "int"), 170);
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
		
		debugger_reset();	

		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_R_1917")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest4,CFGc_BP3Offset)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check value of variable b8NewPreActivationFlag_HRD, corresponding to Hard Releasing cycle request", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value b8NewPreActivationFlag_HRD is set to 0, corresponding to NONE", debugger_readMemory(CFGc_VariableAddress3, 1, "int"), 0);
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
		
		debugger_reset();
		
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_R_1920")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest4,CFGc_BP4Offset)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check value of variable X_u8PreviousTriggeringSource_SMO, corresponding to Smooth Releasing cycle request", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value X_u8PreviousTriggeringSource_SMO is set to 0, corresponding to NONE", debugger_readMemory(CFGc_VariableAddress4, 1, "int"), 0);
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
		
		debugger_reset();	

		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_R_1923")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest5,CFGc_BP5Offset)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check value of variable X_u8PreviousTriggeringSource_BCK, corresponding to Backup Releasing cycle request", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value X_u8PreviousTriggeringSource_BCK is set to 0, corresponding to NONE", debugger_readMemory(CFGc_VariableAddress5, 1, "int"), 0);
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