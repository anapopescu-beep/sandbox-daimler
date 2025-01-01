/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_I_ADC_CALIBRATION
Result Test:
************************************************************************************************
Requirement under test: TR6_DES_TF_I_8922, TR6_DES_TF_I_8923
Description of the requirement: ERR_NVM_E_ADC_CALIBRATION AEC qualification and deskill instantaneously.
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
const AEC_var = "ADC_CALIBRATION_FAILED"

const cTEST_OK = true;                                 // Constant for tests returning OK
const cTEST_NOK = false;                               // Constant for tests returning NOK
const cENV_NON_INITIALIZED = "NO_INIT";                // Constant for non initialized environment
const cENV_NOK = false;                                // Mandatory constant
const cException_Catched = true;                       // Mandatory constant

/* Function name used to place a breakpoint */
const CFGc_SetEventFunction: String = "AdcIf_Autotest_CheckAdcCalib";
const CFGc_SetEventFunctionOffset1: Number = 6; // should be configured

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
var sBPDescription;
var result;
var tempResult;
var idx;
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
      
		CommentStep("Set a BP on the configured function")
		/*Set a breakpoint in AdcIf_Autotest_CheckAdcCalib at the first condition*/
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction, CFGc_SetEventFunctionOffset1);
		Wait(sintBPTimeout);
            
		CommentStep("Run the debugger")
		debugger_run();      
		Wait(500);
		
		/*Force the software to enter the AdcIf_Autotest_CheckAdcCalib function*/
		result = CAN.SendDiagByValues("0x11 0x03");
		Wait(sintWaitInit*5)
       
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset1	  
		RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
   
        CommentStep("Write memory - Adc_CalibrationStatus0.Adc_UnitSelfTestStatus set to 0x01")
		bWriteVariableResult = debugger_modify("Adc_CalibrationStatus0.Adc_UnitSelfTestStatus", 0x01)
		
		CommentStep("Clear all breakpoints");
		RESULT.ExpectTestResult("Delete all breakpoints",
			debugger_deleteAllBreakpoints(),
			true
		);
		
		CommentStep("Run the debugger")
		debugger_run();
		Wait(sintWaitInit);
		
		result = CAN.SendDiagByValues("0x11 0x03");
		Wait(sintWaitInit*5);
		
		/* ----- Switch to supplier session ----- */
 		CommentStep("Check supplier session availability");
		sendCANDiagRequest("Enter supplier session", "0x10 0x7E","0x50 0x7E");
		Thread.Sleep(10);
		
		var error;
		error = checlAecStatus(AEC_var,0x20)
		if (error == 0)
		{
			RESULT.InsertComment("Qualification instantaneously after reset is present, Test OK");
		}
		else
		{
			RESULT.InsertComment("Test Not OK");
		}
			

		sendCANDiagRequest("Clear all AECs ", "0x14 0xFF 0xFF 0xFF", "0x54", "False");
		result = CAN.SendDiagByValues("0x11 0x03");
		Wait(sintWaitInit*5);
		
		/* ----- Switch to supplier session ----- */
		RESULT.InsertComment("Switching to Supplier Session");
		sendCANDiagRequest("Switch to Supplier session: 0x10 0x7E ", "0x10 0x7E", "0x50 0x7E", "False");
		Thread.Sleep(10);
		
		error = checlAecStatus(AEC_var,0x00)
		if (error == 0)
		{
			RESULT.InsertComment("Deskill instantaneously after reset is present, Test OK");
		}
		else
		{
			RESULT.InsertComment("Test Not OK");
		}
			
		/*------------------------------------------------------------------------------
								DEINITIALIZATION ENVIRONMENT
		------------------------------------------------------------------------------*/
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