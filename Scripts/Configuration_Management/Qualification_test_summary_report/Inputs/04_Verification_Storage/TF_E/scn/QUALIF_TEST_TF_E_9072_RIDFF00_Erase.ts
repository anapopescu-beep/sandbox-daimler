/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_9072_RIDFF00_Erase
Result Test:
************************************************************************************************
Requirement under test: TR6_EXT_TF_E_9072
Description of the requirement: Erase Memory supported by Autosat Bootloader Stack
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
const cTEST_OK = true;                                 // Constant for tests returning OK
const cTEST_NOK = false;                               // Constant for tests returning NOK
const cENV_NON_INITIALIZED = "NO_INIT";                // Constant for non initialized environment
const cENV_NOK = false;                                // Mandatory constant
const cException_Catched = true;                       // Mandatory constant

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "5"; 

/* WinIDEA initialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOff";    /* [RunOn, RunOff] */

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/

/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Boolean used to check if the test is successful */
var bRetFunction: Boolean = false;
/* Variable containing the request */
var sRequest
/* Variable containing the answer */
var sResponse
/* Variable for breakpoint result*/
var bIsBPset
/* Variable for breakpoint timeout */
var sintBPTimeout: Number = 2000;
/* Variable for default wait period */
var sintDefaultWait: Number = 250;
/* Variable for default init period */
var sintWaitInit: Number = 1250;
/* Variable for breakpoint result*/
var bBreakPointResult;
var bWriteVariableResult: Boolean = false;
var bReadVariableResult: Boolean = false;
var iReadVariableValue: Number = 0;
var tRelativeBreakPointParam = [];
var tRelativeBreakPointParam2 = [];
var result;
var tDataResponse1;
var tDataResponse2;
var tDataResponse3;
var tDataResponse4;
var sRequestToSend: String ="0x27 0x12 ";
/*------------------------------------------------------------------------------
                                    Core Test
------------------------------------------------------------------------------*/
try
{
   /*------------------------------------------------------------------------------
                           INITIALIZATION ENVIRONMENT
   ------------------------------------------------------------------------------*/
   /**** This function is parameterizable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/

   /****** WARNING : check optional parameter of the next function :it's very IMPORTANT ***********/
   CommentStep("Initialize environment");
   vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply(CFGc_FlashMode, CFGc_ResetMode, CFGc_RunMode, CFGc_MinCurrentToRunTest);
   
   if(vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK)
   {
		/*------------------------------------------------------------------------------
                              EXECUTION TEST
		------------------------------------------------------------------------------*/
		CommentStep("Clear all breakpoints");
		RESULT.ExpectTestResult("Delete all breakpoints",
			debugger_deleteAllBreakpoints(),
			true
		);
         
		CommentStep("Run the debugger")
		debugger_run();      
		Wait(1000);
		
		/* ----- Switch to extended session ----- */
 		CommentStep("Enter extended session");
		sendCANDiagRequest("Enter extended session", "0x10 0x03","0x50 0x03");
		Thread.Sleep(10);
		
		/* ----- Switch to programming session ----- */
		RESULT.InsertComment("Switching to programming Session");
		sendCANDiagRequest("Switch to programming session: 0x10 0x02 ", "0x10 0x02", "0x50 0x02", "False");
		Thread.Sleep(10);
		
		/* ----- Issue security access ----- */
 		CommentStep("Issue security access");
		result = CAN.SendDiagByValues("0x27 0x11");
		Thread.Sleep(10);
		
		result=result[1].Split(' '); 
		CommentStep("Security access gained: "+result);
		var tDataResponse1=parseInt(result[2].replace(/ 0x/g,""))
		if (tDataResponse1<0xFF)
		{
			tDataResponse1++;
		}
		sRequestToSend = sRequestToSend+" "+decimalToPaddedHexString(tDataResponse1);

		var tDataResponse2=parseInt(result[3].replace(/ 0x/g,""))
		if (tDataResponse2<0xFE)
		{
			tDataResponse2=tDataResponse2+2;
		}
		else 
		{
			tDataResponse2 = 0xFF & tDataResponse2;
		}
		sRequestToSend = sRequestToSend+" "+decimalToPaddedHexString(tDataResponse2);
		
		var tDataResponse3=parseInt(result[4].replace(/ 0x/g,""))
		if (tDataResponse3<0xFD)
		{
			tDataResponse3=tDataResponse3+3;
		}
		else
		{
			tDataResponse3 = 0xFF & tDataResponse3;
		}
		sRequestToSend = sRequestToSend+" "+decimalToPaddedHexString(tDataResponse3);
		
		var tDataResponse4=parseInt(result[5].replace(/ 0x/g,""))
		if (tDataResponse4<0xFC)
		{
			tDataResponse4=tDataResponse4+4;
		}
		else 
		{
			tDataResponse4 = 0xFF & tDataResponse4;
		}
		sRequestToSend = sRequestToSend+" "+decimalToPaddedHexString(tDataResponse4);
		
		CommentStep("Issue sending the second key"+sRequestToSend);
		sendCANDiagRequest("Second key: "+sRequestToSend, sRequestToSend, "0x67 0x12", "False");		
		
		CommentStep("Sendig the fingerprint");
		sendCANDiagRequest("Fingerprint: ", "0x2e 0xf1 0x5a 0x30 0x32 0x34 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00", "0x6E 0xF1 0x5A");
		
		ResultStep("Request sequence is correct", "Request sequence is correct");
		CommentStep("Sending the erase command");
		result = sendCANDiagRequest("Send the erase memory command: ", "0x31 0x01 0xFF 0x00 0x02 0x00 0x01", "0x71 0x01 0xFF");

		if (result == 0)
		{
			CommentStep("Correct functionality");
			ResultStep("Functionality is correct", "Functionality is correct");
		}
		else
		{
			CommentStep("Incorrect functionality, Test Failed");
		}

		/*------------------------------------------------------------------------------
								DEINITIALIZATION ENVIRONMENT
		------------------------------------------------------------------------------*/
		SwDevLib_InitBenchEnvironmentAndPowerSupply(CFGc_FlashMode, CFGc_ResetMode, CFGc_RunMode, CFGc_MinCurrentToRunTest);
		
		RESULT.ExpectTestResult("Reset the debugger",
			debugger_reset(),
			cTEST_OK
		);
		
		LaunchMasterBeltProfile("NO_ACTION");
		Wait(500);
		
		/* "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger). This function is mandatory */
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

	CommentStep("Close test environment");
	RESULT.ExpectTestResult("Close environment test",
		winIDEAWorkspace_closeDiscard(),
		cTEST_OK
	);
}