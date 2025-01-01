/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_1799_Context_Inhibit
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_1799
Description of the requirement: 
ALV_EXT_TF_H_1799: It shall be possible to dynamically enable/disable autotest execution regarding ECU current context.
************************************************************************************************
Equipment: PP4G Mockup + iSYSTEM IC5000 + power supply + CAN case
Test Notes: Check auto-test configuration (Period / Timeslot / position)
Full Automation: Yes
Global Result Assignment: Neeva 
************************************************************************************************/
/********************************************************************************/
/*                             Format test script                               */
/********************************************************************************/
/*------------------------------------------------------------------------------
                                IMPORT LIBRARY
 ------------------------------------------------------------------------------*/

/**** USE RELATIVE PATH FOR IMPORT LIBRARY ****/
CALL(/../../ProjectLib_Development/SBE_Configuration.ts);
 
/*------------------------------------------------------------------------------
                                CONSTANTS
 ------------------------------------------------------------------------------*/

const cTEST_OK 							= true;
const cTest_NOK 						= false;

const cENV_NON_INITIALIZED 				= "NO_INIT";
const cENV_NOK 							= false;
const cException_Catched 				= true;

const CFGc_FunctionToTest1		 		= "executeAutoTest";		// Function in which the breakpoints will be set
const sintOffsetBP1			 			= 17;						// Line in which the breakpoint will be set
const sintOffsetBP2			 			= 27;						// Line in which the breakpoint will be set
const sintOffsetBP3			 			= 58;						// Line in which the breakpoint will be set

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String 	= "50"; 

/* WinIDEA intialization options */
const CFGc_FlashMode: String  			= "FlashOn";   				// [FlashOn, FlashOff]
const CFGc_ResetMode: String  			= "ResethOn";  				// [ResetOn, ResetOff]
const CFGc_RunMode: String    			= "RunOn";    				// [RunOn, RunOff] 

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/

var vRetFunction;
var addressBP1;
var addressBP2;
var addressBP3;

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
		/* Start of the test */
		CommentStep(" ***| START OF TEST |*** ");	
	  
		/* Set a breakpoint in the tested function */
		CommentStep("Set the breakpoints in the "+ CFGc_FunctionToTest1 + " function");
        addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,sintOffsetBP1)[3] 
		
		/* Wait for the software to reach the breakpoint */
		CommentStep("Run the application and wait for the breakpoint to be reached")
		RESULT.ExpectTestResult("Run application", debugger_run(), true);
		RESULT.ExpectTestResult("Wait until the breakpoint is reached", debugger_waitWhileRunning(5000), true);
		
		/* Breakpoint reached */
		CommentStep("Breakpoint reached, we will inhibit the autotest")
		Wait(1000)
		/* Forcing the inhibition status to False */
		MessageBox.Show("Force u8InhibitingContextStatus to value 170");
		Wait(5000);
		
		/* Remove all the breakpoints */
		CommentStep("Remove all breakpoints")
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
		
		/* Set a breakpoint in the tested function */
		CommentStep("Set the breakpoints in the "+ CFGc_FunctionToTest1 + " function");
        addressBP2 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,sintOffsetBP2)[3] 
        addressBP3 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,sintOffsetBP3)[3] 
		
		/* Check if the test is inhibited */
		CommentStep("Run the software and check if the test is inhibited due to the inhibition status");
		RESULT.ExpectTestResult("Run application", debugger_run(), true);
		RESULT.ExpectTestResult("Wait until the breakpoint is reached", debugger_waitWhileRunning(1000), true);
		RESULT.ExpectTestResult("Verify if we executed the test", debugger_isCPUStoppedAtAddress(addressBP2), false);
		RESULT.ExpectTestResult("Verify if we didn't execute the test", debugger_isCPUStoppedAtAddress(addressBP3), true);
		
		/* Remove all breakpoints */
		CommentStep("Remove all breakpoints")
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
		
		/* End of the test */
		CommentStep(" ***| END OF TEST |*** ");
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