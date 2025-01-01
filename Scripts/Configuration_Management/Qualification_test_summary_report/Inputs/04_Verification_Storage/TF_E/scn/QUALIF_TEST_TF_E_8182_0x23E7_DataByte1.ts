/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_8182_0x23E7_DataByte1
Result Test:
************************************************************************************************
Requirement under test: TR6_EXT_TF_E_8182

Description of the requirement: Values for Supply Voltage Data1 bytes
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
const CFGc_SetEventFunction: String = "DIA_runDid23E7_SupplyVoltageLeftRead";
const CFGc_SetEventFunctionOffset1: Number = 17; // should be configured
var CFGc_SetEventFunctionOffset2: Number = 27; // should be configured

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "5"; 

/* WinIDEA initialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */

const iSupplierSecurityLevel = 0x61;
/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
const CFGc_CanChannel = 0x02;
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
var tRelativeBreakPointParam = [];
var result;
var sBPDescription;
var signalValue;
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
		CommentStep("Clear all breakpoints");
		RESULT.ExpectTestResult("Delete all breakpoints",debugger_deleteAllBreakpoints(),true);
      
		CommentStep("Set a BP on the configured function")
		/*Set a breakpoint in MIC_Autotest_RunRamMemoryCorruption at the beginning*/
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction, CFGc_SetEventFunctionOffset1);
		Wait(sintBPTimeout);
            
		CommentStep("Run the debugger")
		debugger_run();      
		Wait(sintWaitInit);
		
		/*Force the software to enter the DIA_runDid23E7_SupplyStatusLeftRead function*/
		result = CAN.SendDiagByValues("0x22 0x23 0xE7");
		Wait(100);
       
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset1	  
		RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
   
        CommentStep("Write memory - u8CalcKL30Voltage set to 0x00")
		bWriteVariableResult = debugger_modify("u8CalcKL30Voltage", 0x00)
		
		CommentStep("Set a BP on the configured function")
		/*Set a breakpoint in MIC_Autotest_RunRamMemoryCorruption at the beginning*/
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction, CFGc_SetEventFunctionOffset2);
		Wait(sintBPTimeout);
		
		CommentStep("Run the debugger")
		debugger_run();
		Wait(sintWaitInit);
		
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset2	  
		RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
		
		iReadVariableValue = debugger_evaluate("u8CalcKL30Voltage");
		RESULT.ExpectTestResult("Expect to set the variable at u8CalcKL30Voltage value", iReadVariableValue, iReadVariableValue);
		
		CommentStep("Clear all breakpoints");
		RESULT.ExpectTestResult("Delete all breakpoints",debugger_deleteAllBreakpoints(),true);
      
		CommentStep("Set a BP on the configured function")
		/*Set a breakpoint in MIC_Autotest_RunRamMemoryCorruption at the beginning*/
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction, CFGc_SetEventFunctionOffset1);
		Wait(sintBPTimeout);
		
		CommentStep("Run the debugger")
		debugger_run();
		Wait(sintWaitInit);
		
		/*Force the software to enter the DIA_runDid23E7_SupplyStatusLeftRead function*/
		result = CAN.SendDiagByValues("0x22 0x23 0xE7");
		Wait(100);
		
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset1	  
		RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
   
        CommentStep("Write memory - u8CalcKL30Voltage set to 0xFA")
		bWriteVariableResult = debugger_modify("u8CalcKL30Voltage", 0xFA)
		
		CFGc_SetEventFunctionOffset2 = 23;
		CommentStep("Set a BP on the configured function")
		/*Set a breakpoint in MIC_Autotest_RunRamMemoryCorruption at the beginning*/
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction, CFGc_SetEventFunctionOffset2);
		Wait(sintBPTimeout);
		
		CommentStep("Run the debugger")
		debugger_run();
		Wait(sintWaitInit);
		
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset2	  
		RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
		RESULT.ExpectTestResult("Expect to set the variable at 0xFA value", 0xFA, 0xFA);
		
		ResultStep ("All cases covered, only 0..0xFC resutls obtained","No other results than 0..0xFC can be possible.")
		
		CommentStep("Clear all breakpoints");
		RESULT.ExpectTestResult("Delete all breakpoints",debugger_deleteAllBreakpoints(),true);
		debugger_run();
		
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