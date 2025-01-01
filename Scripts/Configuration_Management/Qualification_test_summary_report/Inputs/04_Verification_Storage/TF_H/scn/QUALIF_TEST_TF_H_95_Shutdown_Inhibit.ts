/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_95_Shutdown_Inhibit
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_95
Description of the requirement: 
ALV_EXT_TF_H_95: Except if explicitly defined in Autotest description, all autotests shall be aborted/inhibited when SBE ECU shutdown procedure is started.
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
const CFGc_FunctionToTest2		 		= "BswM_OnGoOffOneA";		// Function in which the breakpoints will be set
const sintOffsetBP1			 			= 0;						// Line in which the breakpoint will be set
const sintOffsetBP2			 			= 3;						// Line in which the breakpoint will be set

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

var sRequest;
var sResponse;

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
		
		/* Let the ECU wake up */
		CommentStep("Let the ECU wait up");	
		debugger_run();
		Wait(5000);
		
		/* Set a breakpoint in the tested function */
		CommentStep("Set the breakpoint in the "+ CFGc_FunctionToTest2 + " function");
        addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2,sintOffsetBP2)[3]
		Wait(500)
		
		/* Send a shutdown request */
		CommentStep("Send a shutdown request")
		sRequest = "0x11 0x03";
		sResponse = CAN.SendDiagByValues(sRequest);
		
		/* The software should arrive at the start of the shutdown sequence */
		CommentStep("Run the application wait until we reach the shutdown sequence function")
		RESULT.ExpectTestResult("Wait until we reach the breakpoint", debugger_waitWhileRunning(5000), true);
		RESULT.ExpectTestResult("Verify if the software has reached the shutdown sequence function", debugger_isCPUStoppedAtAddress(addressBP1), true);
		Wait(1000)
		
		/* Remove all the breakpoints */
		CommentStep("Remove all breakpoints")
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
		
		/* Set a breakpoint in the tested function */
		CommentStep("Set the breakpoint in the "+ CFGc_FunctionToTest1 + " function");
        addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,sintOffsetBP1)[3]
		Wait(500)
		
		/* The software should not reach the autotest function breakpoint */
		CommentStep("Run the application and see if any autotest is executed")
		RESULT.ExpectTestResult("Run application", debugger_run(), true);
		RESULT.ExpectTestResult("Wait until the breakpoint is supposed to be reached", debugger_waitWhileRunning(5000), false);
		RESULT.ExpectTestResult("Verify if no autotest was executed", debugger_isCPUStoppedAtAddress(addressBP1), false);
		
		/* End of the test */
		CommentStep(" ***| END OF TEST |*** ");
			
		winIDEAWorkspace_closeDiscard();
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