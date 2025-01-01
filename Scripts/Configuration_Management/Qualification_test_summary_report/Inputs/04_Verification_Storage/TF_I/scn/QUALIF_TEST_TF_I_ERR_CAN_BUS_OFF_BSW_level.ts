/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_I_ERR_CAN_BUS_OFF_BSW_level
Result Test:
************************************************************************************************
Requirement under test: TR6_DES_TF_I_8834

Description of the requirement: Qualification for ERR_CAN_BUS_OFF managed by BSW level
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
const CFGc_SetEventFunction: String = "Com_EB_InitTxIPdu_PduBuffer";
const CFGc_SetEventFunctionOffset1: Number = 0; // should be configured

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
		RESULT.ExpectTestResult("Delete all breakpoints",
			debugger_deleteAllBreakpoints(),
			true
		);
      
		CommentStep("Set a BP on the configured function")
		/*Set a breakpoint in Com_EB_InitTxIPdu_PduBuffer at the beginning*/
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction, CFGc_SetEventFunctionOffset1);
		Wait(sintBPTimeout*3);
            
		CommentStep("Run the debugger")
		debugger_run();      
		Wait(sintWaitInit);
		
		/*Force the software to enter the Com_EB_InitTxIPdu_PduBuffer function*/
		result = CAN.SendDiagByValues("0x11 0x03");
		Wait(sintWaitInit);
		
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset1	  
		RESULT.ExpectTestResult(sBPDescription + " is reached, ERR_CAN_BUS_OFF is managed by BSW", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
		ResultStep("Function reached is managed by BSW", "Correct");

		CommentStep("Run the debugger")
		debugger_run();
		Wait(sintWaitInit);
		      
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