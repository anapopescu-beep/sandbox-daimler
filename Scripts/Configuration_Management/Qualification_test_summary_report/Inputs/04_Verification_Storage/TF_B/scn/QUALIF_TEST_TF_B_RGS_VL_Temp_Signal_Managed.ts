/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_B_RGS_VL_Temp_Signal_Managed
Result Test:
************************************************************************************************
Requirement under test: TR6_EXT_TF_B_2118, TR6_EXT_TF_B_2119, TR6_EXT_TF_B_2120, TR6_EXT_TF_B_2122,
                        TR6_EXT_TF_B_2121, TR6_EXT_TF_B_2124, TR6_EXT_TF_B_2125
						
Description of the requirement: Managing RGS_VL_Temp
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

/* Function name used to place a breakpoint */
const CFGc_SetEventFunction: String = "CIL_runAppliToCAN";
const CFGc_SetEventFunctionOffset1: Number = 370; // should be configured

const CFGc_SetEventFunction2: String = "cil_ComputeSignalTemp";
var CFGc_SetEventFunctionOffset2: Number = 9; // should be configured

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "5"; 

/* WinIDEA initialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */

const iSupplierSecurityLevel = 0x61;

const iTempOffset = 40;
const iTempScalling = 2;
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
var sintWaitInit: Number = 750;
/* Variable for signal change period */
var sintWaitSignal: Number = 500;
/* Variable for breakpoint result*/
var bBreakPointResult;
var bWriteVariableResult: Boolean = false;
var bReadVariableResult: Boolean = false;
var iReadVariableValue: Number = 0;
var iReadVariableValue2: Number = 0;
var tRelativeBreakPointParam = [];
var result;
var sBPDescription;
var signalValue;

var fname ="../../Config/Neeva_Configuration/TestEnvironment_Automation/Neeva_config/Scripts/TR6_EXT_TF_B_RGS_VL_Temp";
RESULT.InsertComment("Log name: " +fname)
/*------------------------------------------------------------------------------
                                TEST SPECIFIC VARIABLES
 ------------------------------------------------------------------------------*/
 var vFALLING_EDGE: Number = 0x00;
 var vRISING_EDGE: Number = 0x01;
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
		
		var sFilePath = fname+".log"

		CommentStep("Power OFF ECU - set ecu in OFF State");
		PS.PowerOff(_sPS1Name);

		CommentStep("Wait 3000");
		Wait(3000);

		CommentStep("Start logging to file"); 
		CAN.StartLoggingToFile(sFilePath, UInt64(0x3D8), UInt64(0x3D8));

		CommentStep("Power ON ECU");
		PS.PowerOn(_sPS1Name);

		CommentStep("Wait 6s");
		Wait(6000);

		CommentStep("Stop logging to file");
		RESULT.InsertComment(CAN.StopLogging()[1]);

		CommentStep("Split the Log file into 5 Arrays: Direction, Channel, Time, Id, Length, Data")

		CommentStep("Clear all breakpoints");
		RESULT.ExpectTestResult("Delete all breakpoints",
			debugger_deleteAllBreakpoints(),
			true
		);
      
		CommentStep("Set a BP on the configured function")
		/*Set a breakpoint in CIL_runAppliToCAN */
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction, CFGc_SetEventFunctionOffset1);
		Wait(sintBPTimeout);
            
		CommentStep("Run the debugger")
		debugger_run();      
		Wait(sintWaitInit);
		
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset1	  
		RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
		ResultStep("Debugger is stopped on the correct function", "Debugger is stopped on the correct function");
		
		CommentStep("Clear all breakpoints");
		RESULT.ExpectTestResult("Delete all breakpoints",debugger_deleteAllBreakpoints(),true);
		
		CommentStep("Reflash to gain the init values")
		vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply(CFGc_FlashMode, CFGc_ResetMode, "RunOff", CFGc_MinCurrentToRunTest);
		Wait(sintWaitInit);
		
		CommentStep("Set a BP on the configured function")
		/*Set a breakpoint in cil_ComputeSignalTemp */
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction2, CFGc_SetEventFunctionOffset2);
		
		CommentStep("Run the debugger")
		debugger_run();
		Wait(sintWaitInit);
		
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction2 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset2  
		RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
		ResultStep("Debugger is stopped on the correct function", "Debugger is stopped on the correct function");
	
		iReadVariableValue = debugger_evaluate("cil_u8RGS_Temp");
		RESULT.ExpectTestResult("The init value of TEMP should be 0xFE", iReadVariableValue, 0xFE);
	
		CommentStep("Clear all breakpoints");
		RESULT.ExpectTestResult("Delete all breakpoints",debugger_deleteAllBreakpoints(),true);
		
		CommentStep("Run the debugger")
		debugger_run();
		
		CFGc_SetEventFunctionOffset2 = 25;
		CommentStep("Set a BP on the configured function")
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction2, CFGc_SetEventFunctionOffset2);
		Wait(sintBPTimeout);
		
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction2 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset2	  
		RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
		ResultStep("Debugger is stopped on the correct function", "Debugger is stopped on the correct function");
		
		CommentStep("Write memory - s16InternalTemperature_deg set to -41")
		bWriteVariableResult = debugger_modify("s16InternalTemperature_deg", -41)
		ResultStep("Value of s16InternalTemperature_deg is -41, AEC is qualified", "Value of u8FaultStatus is -41, AEC is qualified");
		
		RESULT.ExpectTestResult("Delete all breakpoints",debugger_deleteAllBreakpoints(),true);
		
		CFGc_SetEventFunctionOffset2 = 39;
		CommentStep("Set a BP on the configured function")
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction2, CFGc_SetEventFunctionOffset2);
		Wait(sintBPTimeout);
		
		CommentStep("Run the debugger")
		debugger_run();
		
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction2 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset2	  
		RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
		ResultStep("Debugger is stopped on the correct function", "Debugger is stopped on the correct function");
		
		iReadVariableValue = debugger_evaluate("cil_u8RGS_Temp");
		RESULT.ExpectTestResult("The temperature variable should be at minimum level", iReadVariableValue, 0x00);
		
		CommentStep("Clear all breakpoints");
		RESULT.ExpectTestResult("Delete all breakpoints",debugger_deleteAllBreakpoints(),true);
		
		CommentStep("Run the debugger")
		debugger_run();
		
		CFGc_SetEventFunctionOffset2 = 25;
		CommentStep("Set a BP on the configured function")
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction2, CFGc_SetEventFunctionOffset2);
		Wait(sintBPTimeout);
		
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction2 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset2	  
		RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
		ResultStep("Debugger is stopped on the correct function", "Debugger is stopped on the correct function");
		
		CommentStep("Write memory - u8Calc_Temp set to -41")
		bWriteVariableResult = debugger_modify("u8Calc_Temp", 255)
		ResultStep("Value of u8Calc_Temp is 255, AEC is qualified", "Value of u8Calc_Temp is 255, AEC is qualified");
		
		RESULT.ExpectTestResult("Delete all breakpoints",debugger_deleteAllBreakpoints(),true);
		
		CFGc_SetEventFunctionOffset2 = 39;
		CommentStep("Set a BP on the configured function")
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction2, CFGc_SetEventFunctionOffset2);
		Wait(sintBPTimeout);
		
		CommentStep("Run the debugger")
		debugger_run();
		
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction2 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset2	  
		RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
		ResultStep("Debugger is stopped on the correct function", "Debugger is stopped on the correct function");
		
		iReadVariableValue = debugger_evaluate("cil_u8RGS_Temp");
		RESULT.ExpectTestResult("The temperature variable should be at minimum level", iReadVariableValue, 253);
		
		CommentStep("Clear all breakpoints");
		RESULT.ExpectTestResult("Delete all breakpoints",debugger_deleteAllBreakpoints(),true);
		
		CommentStep("Run the debugger")
		debugger_run();
		
		CFGc_SetEventFunctionOffset2 = 25;
		CommentStep("Set a BP on the configured function")
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction2, CFGc_SetEventFunctionOffset2);
		Wait(sintBPTimeout);
		
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction2 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset2	  
		RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
		ResultStep("Debugger is stopped on the correct function", "Debugger is stopped on the correct function");
		
		iReadVariableValue = debugger_evaluate("cil_u8RGS_Temp");
		iReadVariableValue2 = debugger_evaluate("s16InternalTemperature_deg");

		CommentStep("Check if the debugger is stopped on the correct function") 
		if (iReadVariableValue == (iReadVariableValue2 + iTempOffset)*iTempScalling)
		{
			CommentStep("Test OK, Offset =40, scalling = 0,5") 	
		}
		CommentStep(iReadVariableValue)
		CommentStep(iReadVariableValue2)
		/*------------------------------------------------------------------------------
							  DEINITIALIZATION ENVIRONMENT
		------------------------------------------------------------------------------*/
		RESULT.ExpectTestResult("Reset the debugger",
		 debugger_reset(),
		 cTEST_OK
		);
		
		LaunchMasterBeltProfile("NO_ACTION");
		Wait(sintWaitSignal);

		/* "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger). This function is mandatory */
		RESULT.ExpectTestResult("Close environment test",
		 winIDEAWorkspace_closeDiscard(),
		 cTEST_OK
		);

		CAN.SetDiagnosticAdressingMode(CAN.ActiveChannel,_iDiagRequestFrameIdFL,_iDiagResponseFrameIdFL) 
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

	CAN.SetDiagnosticAdressingMode(CAN.ActiveChannel,_iDiagRequestFrameIdFL,_iDiagResponseFrameIdFL) 
}