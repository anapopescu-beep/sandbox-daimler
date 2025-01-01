/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_27_Autotest_Status
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_27
Description of the requirement: 
ALV_EXT_TF_H_27: Once the CRITICAL_AUTOTESTS_STATUS is set to OK, the CRITICAL_AUTOTESTS_STATUS shall not change until ECU shutdown. 
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
const sintOffsetBP2			 			= 58;						// Line in which the breakpoint will be set

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
		
		/* Wait for the Motor Disconnected Event to be passed */
		CommentStep("Wait for the Motor Disconnected Event to be passed");	
		Wait(1000);
		
		/* Enter Supplier Session */
		CommentStep("Enter Supplier Session")              
        sRequest ="0x10 0x7E"
        sResponse = CAN.SendDiagByValues(sRequest);
        EvalManStepEqual("Enter in supplier session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x7E 0x00 0x64 0x01 0xF4")
                
        /* Read motor disconnected Event status */
		CommentStep("Read the motor disconnected event status")  
        sRequest = "0x22 0xFE 0x00";
        sResponse = CAN.SendDiagByValues(sRequest);
        EvalManStepEqual("Read Event Motor Disconnected",sResponse[1].split(' ')[50],"0x00");
		
		/* Force a motor disconnected event */
		CommentStep("Force the motor disconnected event status")  
		MessageBox.Show("Force a motor disconnection by removing the motor cables")
		
		/* Wait for motor disconnected to be qualified */
		CommentStep("Wait for motor disconnected to be qualified")
		Wait(2000)
		
		/* Enter Supplier Session */
		CommentStep("Enter Supplier Session")              
        sRequest ="0x10 0x7E"
        sResponse = CAN.SendDiagByValues(sRequest);
        EvalManStepEqual("Enter in supplier session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x7E 0x00 0x64 0x01 0xF4")
                
        /* Read motor disconnected Event status */
		CommentStep("Read the motor disconnected event status")  
        sRequest = "0x22 0xFE 0x00";
        sResponse = CAN.SendDiagByValues(sRequest);
        EvalManStepEqual("Read Event Motor Disconnected",sResponse[1].split(' ')[50],"0x00");
		
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