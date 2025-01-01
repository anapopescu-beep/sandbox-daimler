/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_108_Unstable_Battery
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_108
Description of the requirement: 
ALV_EXT_TF_H_108: The last [NVP_u8NbOccurenceToValidateBatteryVoltage] differences between 2 consecutives measurements (based on the last 4 consecutives power battery voltage measurements) are less than [NVP_u16MinDiffVoltageToValidateBatterySurvey].
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

const CFGc_FunctionToTest1		 		= "PMP_runSurveyBatteryVoltage";		// Function in which the breakpoints will be set
const sintOffsetBP1			 			= 26;									// Line in which the breakpoint will be set
const sintOffsetBP2			 			= 53;									// Line in which the breakpoint will be set

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String 	= "50"; 

/* WinIDEA intialization options */
const CFGc_FlashMode: String  			= "FlashOn";   							// [FlashOn, FlashOff]
const CFGc_ResetMode: String  			= "ResethOn";  							// [ResetOn, ResetOff]
const CFGc_RunMode: String    			= "RunOn";    							// [RunOn, RunOff] 

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/

var vRetFunction;

var addressBP1;
var addressBP2;

var batteryStatus;

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
		CommentStep("Let the ECU wait up and the battery to be stable");	
		debugger_run();
		Wait(5000);
	  
		/* Set a breakpoint in the tested function */
		CommentStep("Set the breakpoints in the "+ CFGc_FunctionToTest1 + " function");
        addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,sintOffsetBP1)[3] 
		
		/* Wait for the software to reach the breakpoint */
		CommentStep("Wait for the breakpoint to be reached")
		RESULT.ExpectTestResult("Wait until the breakpoint is reached", debugger_waitWhileRunning(10000), true);
		
		/* Breakpoint reached */
		CommentStep("Breakpoint reached, we will force the value of the u16MinDiffVoltageToValidateBatterySurvey to 0 to force an unstable battery")
		MessageBox.Show("Force the u16MinDiffVoltageToValidateBatterySurvey to 0");
		Wait(15000)
		
		/* Remove all the breakpoints */
		CommentStep("Remove all breakpoints")
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
	  
		/* Set a breakpoint in the tested function */
		CommentStep("Set the breakpoints in the "+ CFGc_FunctionToTest1 + " function");
        addressBP2 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,sintOffsetBP2)[3] 
		
		/* Breakpoint reached */
		CommentStep("Breakpoint reached")
		RESULT.ExpectTestResult("Run application", debugger_run(), true);
		RESULT.ExpectTestResult("Wait until the breakpoint is reached", debugger_waitWhileRunning(1000), true);
		
		/* Read the battery voltage status */
		CommentStep("Read the battery voltage status (must still be stable since it's the first unstable iteration)")
		batteryStatus = debugger_readMemory("0x1FFFA3E1",1, "int")
		/* Check the battery voltage status */
		RESULT.ExpectTestResult("The battery status is :"+ batteryStatus, batteryStatus, 0)
		
		/* Remove all the breakpoints */
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