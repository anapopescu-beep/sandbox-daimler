/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_B_RHS_VR_EEPROM_RAM_ROM_Fehler_Event
Result Test:
************************************************************************************************
Requirement under test: TR6_DES_TF_B_2904, TR6_DES_TF_B_2905

Description of the requirement: Qualification for ERR_FLS_ECC to modify the signal
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
const CFGc_SetEventFunction: String = "MIC_Autotest_RunPFlashMemoryCorruption";
const CFGc_SetEventFunctionOffset1: Number = 12; // should be configured

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50"; 

/* WinIDEA initialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */

const iSupplierSecurityLevel = 0x61;
/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
const CFGc_CanChannel = 0x02;
const CFGc_StatusFrame = "RGS_VR_01";
const CFGc_StatusSignal = "RGS_VR_EEPROM_RAM_ROM_Fehler";

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
		RESULT.ExpectTestResult("Delete all breakpoints",
			debugger_deleteAllBreakpoints(),
			true
		);
		
		CommentStep("Run the debugger")
		debugger_run();

		waitFrameReception();
		CommentStep("Check supplier session availability");
		sendCANDiagRequest("Enter supplier session", sReq_SupplierSession, sAns_SupplierSession);
		CommentStep("Check supplier security level");
		requestCANSecurityAccess(iSupplierSecurityLevel);
		CommentStep("Unlocking ECU");
		sendCANDiagRequest("Unlocking ECU", sReq_UnlockECU, sAns_UnlockECU);
		Thread.Sleep(sintDefaultWait);
		CommentStep("Write measurement frame configuration");
		sendCANDiagRequest("Write measurement frame configuration", "0x2E 0xFE 0xFF 0x01 0x00 0x00 0x01", "0x6E 0xFE 0xFF");
		Thread.Sleep(sintDefaultWait);
		CommentStep("Lock ECU");
		sendCANDiagRequest("Lock ECU", sReq_LockECU, sAns_LockECU);
		Thread.Sleep(sintDefaultWait);

		CommentStep("Unlocking ECU");
		sendCANDiagRequest("Unlocking ECU", sReq_UnlockECU, sAns_UnlockECU);
		Thread.Sleep(sintDefaultWait);
		CommentStep("Write NVM configuration");
		sendCANDiagRequest("Write NVM configuration", "0x2E 0xFD 0x31 0x00 0x32 0x00 0x89 0x01 0x36 0x03 0xFF 0x03 0xFF 0x00 0x33 0x00 0x7B 0x01 0x08 0x02 0x8A 0x03 0xFF 0x00 0x00 0x04 0x56 0x08 0x18 0x1C 0x01 0x1C 0x01 0x00 0x00 0x03 0x47 0x07 0xAC 0x14 0x4E 0x20 0x98", "0x6E 0xFD 0x31");
		Thread.Sleep(sintDefaultWait);
		CommentStep("Lock ECU");
		sendCANDiagRequest("Lock ECU", sReq_LockECU, sAns_LockECU);
		Thread.Sleep(sintDefaultWait);
		sendCANDiagRequest("SOFT RESET", "0x11 0x03", "0x51 0x03");
		CommentStep("Ensure normal run operation")
		Wait(sintWaitInit*3);

		CommentStep("Check AEC reporting");
		readQualifiedAec("WARM_RESET", "NVM_NOT_PROG");
		CommentStep("Check supplier session availability");
		sendCANDiagRequest("Enter supplier session", sReq_SupplierSession, sAns_SupplierSession);
		sendCANDiagRequest("SOFT RESET", "0x11 0x03", "0x51 0x03");
		CommentStep("Ensure normal run operation")
		waitFrameReception();
		Wait(sintWaitInit*5);
		CommentStep("Change ECU Side to: right");
		ChangeECUSide("right");
		ResultStep("Change ECU Side to: right", "Change ECU Side to: right")
		
		CommentStep("Set a BP on the configured function")
		/*Set a breakpoint in MIC_Autotest_RunPFlashMemoryCorruption at the beginning*/
		tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_SetEventFunction, CFGc_SetEventFunctionOffset1);
		Wait(sintBPTimeout);
            
		CommentStep("Run the debugger")
		debugger_run();      
		Wait(sintWaitInit);
		
		/*Force the software to enter the NvM_ReportReadProductionErrors function*/
		result = CAN.SendDiagByValues("0x11 0x03");
		Wait(sintWaitInit*5);
       
		/* Check if the debugger is stopped on the correct function */
		CommentStep("Check if the debugger is stopped on the correct function") 
		sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_SetEventFunction + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_SetEventFunctionOffset1	  
		RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
   
        CommentStep("Write memory - u32ResetCause set to 0x200")
		bWriteVariableResult = debugger_modify("u32ResetCause", 0x200)
		
		CommentStep("Run the debugger")
		debugger_run();
		Wait(sintWaitInit*3);
		      
		signalValue = CAN.GetSignalFromFrame (CFGc_CanChannel, CFGc_StatusFrame, CFGc_StatusSignal)[1];
		
		if (signalValue == 0)
		{
			CommentStep("Test OK")
		}
		else
		{
			CommentStep("Test NOT OK")
		}
		
		result = CAN.SendDiagByValues("0x11 0x03");
		Wait(sintWaitInit*3);

		/*------------------------------------------------------------------------------
							  DEINITIALIZATION ENVIRONMENT
		------------------------------------------------------------------------------*/
		CommentStep("Run the debugger")
		debugger_run();

		waitFrameReception();
		CommentStep("Check supplier session availability");
		sendCANDiagRequest("Enter supplier session", sReq_SupplierSession, sAns_SupplierSession);
		CommentStep("Check supplier security level");
		requestCANSecurityAccess(iSupplierSecurityLevel);
		CommentStep("Unlocking ECU");
		sendCANDiagRequest("Unlocking ECU", sReq_UnlockECU, sAns_UnlockECU);
		Thread.Sleep(sintDefaultWait);
		CommentStep("Write measurement frame configuration");
		sendCANDiagRequest("Write measurement frame configuration", "0x2E 0xFE 0xFF 0x01 0x00 0x00 0x01", "0x6E 0xFE 0xFF");
		Thread.Sleep(sintDefaultWait);
		CommentStep("Lock ECU");
		sendCANDiagRequest("Lock ECU", sReq_LockECU, sAns_LockECU);
		Thread.Sleep(sintDefaultWait);
		CommentStep("Check AEC reporting");
		readQualifiedAec("WARM_RESET", "NVM_NOT_PROG");
		CommentStep("Check supplier session availability");
		sendCANDiagRequest("Enter supplier session", sReq_SupplierSession, sAns_SupplierSession);
		sendCANDiagRequest("SOFT RESET", "0x11 0x03", "0x51 0x03");
		CommentStep("Ensure normal run operation")
		waitFrameReception();

		CommentStep("Change ECU Side to: left");
		ChangeECUSide("left");
		ResultStep("Change ECU Side to: left", "Change ECU Side to: left")
		Wait(sintWaitInit);
		
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