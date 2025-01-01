/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_7053_DID_F703_Stop_CycleNumber
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_E_7053
Description of the requirement: 
ALV_EXT_TF_E_7053: The integrity of the received cycle number recording shall be guaranteed 
at SW level

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
CALL(Config/QUALIF_TESTCFG_TF_E_7053_DID_F703_CycleNumber.ts);

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
			
		/* Entering Supplier session */
		sRequest = "0x10 0x7E";
        sResponse = CAN.SendDiagByValues(sRequest);
        Wait(CFGc_WakeupDelay);
        EvalManStepEqual("Enter in supplier session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x7E 0x00 0x64 0x01 0xF4");
		
		
		
	   /* Set a breakpoint in the tested function DIA_runRidF703_AutolivCyclesStop */
              addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2,sintOffsetBP1)[3] 
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

	
		/* Start  ALV Cycles - RID F703 */
		sRequest ="0x31 0x02 0xF7 0x03";
		sResponse = CAN.SendDiagByValues(sRequest);
		EvalManStepEqual("Stop  ALV Cycles - RID F703 (" + sRequest + ") - Positive Response:", sResponse[1], "TIMEOUT");
		
		Wait(5000);
		
		
		RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("DIA_runRidF703_AutolivCyclesStop Is Reached ", debugger_isCPUStoppedAtAddress(addressBP1), true);
		
		Wait(5000);
			   
	   /* Set a breakpoint in the tested function DIA_runRidF703_AutolivCyclesStop */
              addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2,sintOffsetBP4)[3] 
              RESULT.ExpectTestResult("Run application", debugger_run(), true);
              RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
              RESULT.ExpectTestResult(" Check if the requested cycle is running Or if no Start routine was executed ", debugger_isCPUStoppedAtAddress(addressBP1), true);
		
		Wait(3000);
			  
			  /*u8CurrentCycleExecutedByBFE = R4*/
			  RESULT.ExpectTestResult("u8CurrentCycleExecutedByBFE <> NO_CYCLE ", debugger_writeRegister("R7", 2, "uint32"), true); 
			  RESULT.ExpectTestResult(" u8DiagRequestedCycle <> NO_CYCLE",debugger_writeMemory(RequestedCycleAddress,"02",1),true);
			  
		Wait(3000);
		
	   
	   /* Set a breakpoint in the tested function DIA_runRidF703_AutolivCyclesStop */
              addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2,sintOffsetBP5)[3] 
              RESULT.ExpectTestResult("Run application", debugger_run(), true);
              RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
              RESULT.ExpectTestResult("Requested Cycle supported ( Cycle Number : u8CycleToExecute is taken into consideration )", debugger_isCPUStoppedAtAddress(addressBP1), true);
	
		Wait(5000);	  
			  
			  
		/* Set a breakpoint in the tested function DIA_runRidF703_AutolivCyclesStop */
              addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2,sintOffsetBP6)[3] 
              RESULT.ExpectTestResult("Run application", debugger_run(), true);
              RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
              RESULT.ExpectTestResult("Requested Cycle's complement supported ( Cycle Number's complement : ~u8CycleToExecute ( complement of u8CycleToExecute)  is taken into consideration :  )", debugger_isCPUStoppedAtAddress(addressBP1), true);
             
			 CommentStep("The integrity of the received cycle number recording was  guaranteed at SW level by associating a complemtn number to the Requested Cycle Number")
 
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