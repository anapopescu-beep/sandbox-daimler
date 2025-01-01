/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_24_25_Autotests_Status
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_24, ALV_EXT_TF_H_25
Description of the requirement: 
A global CRITICAL_AUTOTESTS_STATUS for all the critical autotests shall be available.
By default, the CRITICAL_AUTOTESTS_STATUS shall be set to NOT_DECIDED, before starting the autotests execution
************************************************************************************************
Equipment: PP4G Mockup + iSYSTEM IC5000 + power supply + CAN case
Test Notes: Some Comments..
Full Automation: Yes
Global Result Assignment: Neeva
************************************************************************************************

/*------------------------------------------------------------------------------
                            LIBRARY IMPORT
 ------------------------------------------------------------------------------*/
/* USE RELATIVE PATH TO IMPORT A SBE LIBRARY */
CALL(\..\..\ProjectLib_Development\SBE_Configuration.ts);
/* USE RELATIVE PATH TO IMPORT A CONFIGURATION FILE */
/*------------------------------------------------------------------------------
                               Parameters
------------------------------------------------------------------------------*/
var 		vRetFunction
var			addressBP1


var 		cENV_NON_INITIALIZED 	= "NO_INIT"
var 		cENV_NOK  				= false




/*------------------------------------------------------------------------------
                                 Test Core
------------------------------------------------------------------------------*/
/***************************************************************************************/
/*         The TRY and CATCH words are mandatory to catch every error of test           /
/***************************************************************************************/
try 
{
    /*RESULT.InterpretEqualResult("Remove OpenCircuit on channel "+29, FIB.RemoveFault(29), "Remove fault performed OK on channel " + 29);
    Thread.Sleep(1000);
    for(var count2=1; count2<=3; count2++)
    {
        RESULT.InterpretEqualResult("Reset channel "+count2, FIB.RestartBoard(count2), "Restart board " + count2 + " performed OK.")
        Thread.Sleep(100)
    }
    Thread.Sleep(100);*/
   /*------------------------------------------------------------------------------
                            ENVIRONMENT INITIALIZATION
   ------------------------------------------------------------------------------*/

   /* WARNING : check optionnal parameters of the next function :it's very IMPORTANT */
   /* This function is parametrable see Utilities_Lib.ts library located on S:\Tools\ARIA\Config\Neeva_Configuration\TestEnvironment_Automation\GenericLib_Development */

   vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOff", "RunOff", "5");
  
 
   if (vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK) 
   {
		/*------------------------------------------------------------------------------
                                    TEST CONFIGURATION
		------------------------------------------------------------------------------*/
		/*------------------------------------------------------------------------------
                                    TEST EXECUTION
		------------------------------------------------------------------------------*/
		/*debugger_AttachFunctionDisable();*/
   
    
		/* Set a breakpoint in the function ATM_Init */ 
		CommentStep(" Check the initialized value of the tests status" )
		RESULT.ExpectTestResult("Delete all breakpoints", debugger_deleteAllBreakpoints(), true);
	  
	  
		addressBP1 = debugger_setRelativeFunctionBpAtLine("ATM_Init", 11)[3]
		RESULT.ExpectTestResult("Run application", debugger_run(), true);
		RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(2000), true);
		Wait(1000);
		RESULT.ExpectTestResult("ATM_Init is reached", debugger_isCPUStoppedAtAddress(addressBP1), true);
		
		Wait(3000);
		
		for(var iLength = 0; iLength < 36; iLength++)
		{
			/* Read the value of the autotests status */
			RESULT.ExpectTestResult("Autotest status number " + iLength, debugger_readMemory(536842768 + iLength, 1, "hex"), "04");
		}

   }  
}
        
catch (exError) 
{
   RESULT.ExpectTestResult("Test failed about exception occurs :" + exError, true, false);
  
   /*RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(),cTEST_OK);*/
}