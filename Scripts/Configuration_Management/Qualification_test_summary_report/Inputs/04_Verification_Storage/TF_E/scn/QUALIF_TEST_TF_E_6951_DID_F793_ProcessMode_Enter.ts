/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_6951_DID_F793_ProcessMode_Enter
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_E_6951
Description of the requirement: 
ALV_EXT_TF_E_6951: The Positive Response shall be sent if the process mode is already active.

************************************************************************************************
Equipment: PowerSupply, CanCaseXL, MockUp
Test Notes: CPU load shall be enabled in the SW
Full Automation: Yes
Global Result Assignment: Neeva
************************************************************************************************

/********************************************************************************/
/*                             Format test script                               */
/********************************************************************************/
/*------------------------------------------------------------------------------
                                IMPORT LIBRARY
 ------------------------------------------------------------------------------*/

/**** USE RELATIVE PATH TO IMPORT A SBE LIBRARY ****/
CALL(/../../ProjectLib_Development/SBE_Configuration.ts); 
CALL(Config/QUALIF_TESTCFG_TF_TF_E_DID_F793_ProcessMode.ts);

 /*------------------------------------------------------------------------------
                                CONSTANTS
 ------------------------------------------------------------------------------*/
const cTEST_OK = true;// Constant for the tests
const cTest_NOK = false;
const cENV_NON_INITIALIZED = "NO_INIT";// Mandatory constant
const cENV_NOK = false;// Mandatory constant
const cException_Catched = true;// MANDATORY CONSTANT FOR ALL TEST SCRIPTS

/* Delay to let ECU wakeup */
const CFGc_WakeupDelay = 5000;
/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
var sRequest;
var sResponse;
var addressBP1;
var addressBP2;

/* Variable used to check the test initialization phase */
var vRetFunction = null;

/* Boolean used to check if the test configuration is succesful */
var bRetFunction: Boolean = false;

/*------------------------------------------------------------------------------
                                    Core Test
------------------------------------------------------------------------------*/

/***************************************************************************************/
/********* The TRY and CATCH words are mandatory to catch every error of test **********/
/***************************************************************************************/
try
{
	RESULT.InterpretEqualResult("Remove OpenCircuit on channel "+29, FIB.RemoveFault(29), "Remove fault performed OK on channel " + 29);
    Thread.Sleep(1000);
	for(var count2=1; count2<=3; count2++)
	{
	   RESULT.InterpretEqualResult("Reset channel "+count2, FIB.RestartBoard(count2), "Restart board " + count2 + " performed OK.")
	   Thread.Sleep(100)
	}
    Thread.Sleep(100);
	
	
    /*------------------------------------------------------------------------------
                            INITIALIZATION ENVIRONMENT
    ------------------------------------------------------------------------------*/
    /**** This function is parametrable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/
    
    /****** WARNING : check optionnal parameter of the next function :it's very IMPORTANT ***********/
    vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn","ResetOn","RunOn","5");
    if (vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK)
    {
        // CAN.StartLoggingToFile(cLINTraceFile + ".txt");  ?? don't work

        /*------------------------------------------------------------------------------
                                    CONFIGURATION TEST
        ------------------------------------------------------------------------------*/

            /* Wait until ECU is up running */
            CommentStep(" ***| Let ECU wakeup |*** ");
			
            Wait(CFGc_WakeupDelay);

            /* Configure test */
            bRetFunction = true;

        /*------------------------------------------------------------------------------
                                    EXECUTION TEST
        ------------------------------------------------------------------------------*/
        if (cTEST_OK == bRetFunction)
        {
            CommentStep(" ***| START OF TEST |*** ");
            
            Wait(CFGc_WakeupDelay);
		
		CommentStep(" ***| Activate Enter Process Mode |*** ");
			
		/* Entering Supplier session */
		sRequest = "0x10 0x7E";
        sResponse = CAN.SendDiagByValues(sRequest);
        Wait(CFGc_WakeupDelay);
        EvalManStepEqual("Enter in supplier session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x7E 0x00 0x64 0x01 0xF4");        
		
		/* Entering Supplier session */     
		sRequest ="0x10 0x7E"
		sResponse = CAN.SendDiagByValues(sRequest);
		EvalManStepEqual("Enter in supplier session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x7E 0x00 0x64 0x01 0xF4")
		
		Wait(500);

		/* Getting security access required for writing into sensitive memory */
		sRequest ="0x27 0x61 and 0x27 0x62 "; 
		sResponse = CAN.SecurityAccess(0x61);
		EvalManStepEqual("Get Security Access (" + sRequest + ") - Positive Response:", sResponse[1], "0x67 0x62");
		
		Wait(500);
		
			/* Ecu Unlock */
		sRequest ="0x31 0x01 0xF7 0x81";
		sResponse = CAN.SendDiagByValues(sRequest);
		EvalManStepEqual("Ecu unlock (" + sRequest + ") - Positive Response:", sResponse[1], "0x71 0x01 0xF7 0x81 0xFF");
		
        Wait(500);
	
		/* TestMode 03 / Process Mode  - RID F793 */
		sRequest ="0x31 0x01 0xF7 0x93";
		sResponse = CAN.SendDiagByValues(sRequest);
		EvalManStepEqual("Process Mode - RID F793 (" + sRequest + ") - Positive Response:", sResponse[1], "0x71 0x01 0xF7 0x93 0xFF");
		
		Wait(500);
		
			/* Entering Supplier session */     
		sRequest ="0x10 0x7E"
		sResponse = CAN.SendDiagByValues(sRequest);
		EvalManStepEqual("Enter in supplier session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x7E 0x00 0x64 0x01 0xF4")
		
			  
		/* Set a breakpoint in the tested function DIA_runRidF793_ProcessModeStart */
              addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,sintOffsetBP1)[3] 
              RESULT.ExpectTestResult("Run application", debugger_run(), true);	
			  	
		/* Entering Supplier session */     
		sRequest ="0x10 0x7E"
		sResponse = CAN.SendDiagByValues(sRequest);
		EvalManStepEqual("Enter in supplier session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x7E 0x00 0x64 0x01 0xF4")
		
		Wait(500);

		/* Getting security access required for writing into sensitive memory */
		sRequest ="0x27 0x61 and 0x27 0x62 "; 
		sResponse = CAN.SecurityAccess(0x61);
		EvalManStepEqual("Get Security Access (" + sRequest + ") - Positive Response:", sResponse[1], "0x67 0x62");
		
		Wait(500);
		
			/* Ecu Unlock */
		sRequest ="0x31 0x01 0xF7 0x81";
		sResponse = CAN.SendDiagByValues(sRequest);
		EvalManStepEqual("Ecu unlock (" + sRequest + ") - Positive Response:", sResponse[1], "0x71 0x01 0xF7 0x81 0xFF");
		
        Wait(500);
	
		/* TestMode 03 / Process Mode  - RID F793 */
		sRequest ="0x31 0x01 0xF7 0x93";
		sResponse = CAN.SendDiagByValues(sRequest);
		EvalManStepEqual("Process Mode - RID F793 (" + sRequest + ") - Positive Response:", sResponse[1], "TIMEOUT");
		
		Wait(5000);
		
		      RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
              RESULT.ExpectTestResult(" DIA_runRidF793_ProcessModeStart  is Reached", debugger_isCPUStoppedAtAddress(addressBP1), true);
		
		Wait(5000);
		
		
		CommentStep(" ***|process mode is already active *** ");
	
		
			   /* Set a breakpoint in the tested function DIA_runRidF793_ProcessModeStart */
              addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,sintOffsetBP2)[3] 
              RESULT.ExpectTestResult("Run application", debugger_run(), true);
              RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
              RESULT.ExpectTestResult("Check if Process Mode is activated or the writing process has already been started", debugger_isCPUStoppedAtAddress(addressBP1), true);
			  
			  
               CommentStep(" ***|process mode is already active *** ");
			   
			  RESULT.ExpectTestResult(" process mode is already active: KU8_NVP_PROCESS_MODE_ACTIVE = TRUE ",debugger_readMemory(cPROCESS_MODEAddress,1,"int"),170);
			  
			   /* Set a breakpoint in the tested function DIA_runRidF793_ProcessModeStart */
              addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,sintOffsetBP3)[3] 
              RESULT.ExpectTestResult("Run application", debugger_run(), true);
              RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
              RESULT.ExpectTestResult("Process Mode is already activated. Return OK by default", debugger_isCPUStoppedAtAddress(addressBP1), true);
		
		
		// RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
		      
      }
        else
        {
            /* Warn the tester that the test isn't executed */
            RESULT.ExpectTestResult("Tests isn't executed : configuration NOK", false, cTEST_OK);  
        }
  
      /*------------------------------------------------------------------------------
                              RESET CONFIGURATION TEST
      ------------------------------------------------------------------------------*/

        /*------------------------------------------------------------------------------
                                DEINITIALIZATION ENVIRONMENT
        ------------------------------------------------------------------------------*/
        // "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger). This function is mandatory
        // RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
    }
    else
    {
        winIDEAWorkspace_closeDiscard();
        RESULT.ExpectTestResult("Test failed about environment initialization failed", false, true);
    }
    
    CommentStep(" ***| END OF TEST |*** ");
}
catch(exError)
{
    RESULT.ExpectTestResult("Test failed about exception occurs :"+exError, cException_Catched, false);
    RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}