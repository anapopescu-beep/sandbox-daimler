/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_341_OverVoltage_KL30_Level_measurement
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_341
Description of the requirement: 
ALV_EXT_TF_H_341: ⦁	The battery voltage shall be measured [KL30_Vlevel]
************************************************************************************************
Equipment: PowerSupply, CanCaseXL, MockUp
Test Notes: Test objective same as requirement objective
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
 
 /*------------------------------------------------------------------------------
                                CONSTANTS
 ------------------------------------------------------------------------------*/

/* Constants used for the test results */
const cTEST_OK = true;// Constant for the tests
const cTest_NOK = false;

/* Mandatory constants for test scripts */
const cENV_NON_INITIALIZED = "NO_INIT";
const cENV_NOK = false;
const cException_Catched = true;

const cBPCpuStopIdx = 0;
const cBPAddrIdx = 1;
const cStackTopIdx = 0;

/* WinIDEA intialization options */
const CFGc_FlashMode: String = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String = "RunOff";    /* [RunOn, RunOff] */

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50";

/* Function name used to place a breakpoint */
const CFGc_FunctionToTest: String = "PMP_Autotest_CheckPowerSupplyOV";
const CFGc_SubFunctionToTest: String = "PMP_runGetBatteryVoltage_100ms";

/* Expected call stack */
const CFGc_CallStack: String[] =
[
    "PMP_runGetBatteryVoltage_100ms",
    "PMP_Autotest_CheckPowerSupplyOV"
];

/* Delay to let ECU wakeup */
const CFGc_WakeupDelay = 5000;

/* Path log file */
// const cLINTraceFile = "S:\\Tools\\ARIA\\Config\\Neeva_Configuration\\TestEnvironment_Automation\\Neeva_config\\LastOutput\\trace_trame"; // *****WARNING***** : Mount S:

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/

/* Variable used to check the test initialization phase */
var vRetFunction = null;

/* Boolean used to check if the test configuration is succesful */
var bRetFunction: Boolean = true;

/*------------------------------------------------------------------------------
                                GLOBAL FUNCTIONS
 ------------------------------------------------------------------------------*/
/*********************************************************************
* @name : PP4G_LibInteg_CheckSubFunctionCall(strFunctionToTest:String, strSubFunctionToTest: String, astrCallStack: String[])
*
* @brief : Check if the sub function passed in parameter is correctly called in the SW.
*
* param : strFunctionToTest: Name of the function to test (Used to place a breakpoint)
*         strSubFunctionToTest: Name of the sub function to test (Used to place a breakpoint)
*         astrCallStack: Call stack information (List of function name)
*         
* @return : True if the function is called false otherwise
***********************************************************************/
function PP4G_LibInteg_CheckSubFunctionCall(strFunctionToTest: String, strSubFunctionToTest: String, astrCallStack: String[]): Boolean
{
    /* Local variables */
    var bIsBPset: Boolean = false;
    var sintBPTimeout: Number = 5000;
    var bBreakPointResult: Boolean = false;
    var aBreakPointResult = [];
    var stackTrace;
    var bRetFunction: Boolean = false;

    /* Place a breakpoint on the required function */
    CommentStep("Place a beakpoint on the main function")
    bIsBPset = debugger_setBreakPointAtFunction(strFunctionToTest);
    RESULT.ExpectTestResult("Set a breakpoint on: " + strFunctionToTest,
        bIsBPset,
        true
    );

    if (true == bIsBPset)
    {
        debugger_run();

        /* Let ECU wake up */
        CommentStep("Wait ECU to wake up");
        Wait(sintBPTimeout);

        /* Check if the debugger is stopped on the correct function */
        bBreakPointResult = debugger_isCPUstoppedAtFunction(strFunctionToTest)
        RESULT.ExpectTestResult("Debugger stopped on " + strFunctionToTest + " ?",
            bBreakPointResult,
            true
        );

        if (true == bBreakPointResult)
        {
            /* Get CPU call stack */
            CommentStep("Get CPU call trace")
            stackTrace = debugger_GetStackTrace(1);
            RESULT.ExpectTestResult("Check that the top level of the call trace is the expected function",
                stackTrace[cStackTopIdx].getFunction().getName(),
                strFunctionToTest
            );

            /* Place a breakpoint on the sub function */
            CommentStep("Place a breakpoint on the tested Sub function used to Get the filtered physical value measured on ADC Power Vbat pin from PMP");
            bIsBPset = debugger_setBreakPointAtFunction(strSubFunctionToTest);
            RESULT.ExpectTestResult("Set a breakpoint on: " + strSubFunctionToTest,
                bIsBPset,
                true
            );

            if (true == bIsBPset) {
                /* Run the debugger and wait 1s */
                debugger_run();
                debugger_waitWhileRunning(sintBPTimeout);

                /* Check that Debugger is stopped on a breakpoint */
                CommentStep("Verify that the debugger is stopped on the breakpoint");
                aBreakPointResult = debugger_isCPUStoppedAtBP();
                RESULT.ExpectTestResult("Debugger stopped on a breakpoint",
                    aBreakPointResult[cBPCpuStopIdx],
                    true
                );

                /* Check that the Debugger is stopped on the correct function (address is checked) */
                CommentStep("Compare BP address and " + strSubFunctionToTest + " address")
                RESULT.ExpectTestResult("Verify the address of the breakpoint with address of " + strSubFunctionToTest,
                    aBreakPointResult[cBPAddrIdx],
                    debugger_getFunctionAddress(strSubFunctionToTest).toString(16).ToUpper()
                );

                if (aBreakPointResult[cBPAddrIdx] == debugger_getFunctionAddress(strSubFunctionToTest).toString(16).ToUpper())
                {
                    /* Get CPU call stack */
                    CommentStep("Get CPU call trace")
                    stackTrace = debugger_GetStackTrace();

                    for (var index = 0; index < astrCallStack.length; index++)
                    {
                        /* Compare the call stack with the one passed in parameter */
                        RESULT.ExpectTestResult("Check the call stack " + index,
                            stackTrace[index].getFunction().getName(),
                            astrCallStack[index]
                        );
                    }
                    /* Resume code execution */
                    debugger_run();

                    bRetFunction = true;
                }
                else
                {
                    bRetFunction = false;
                }
            }
            else
            {
                /* Cannot set the breakpoint, leave test in a stable state */
                CommentStep("Cannot set the breakpoint, function may not be implemented or there is a problem with the debugger.");
                CommentStep("Exception: " + bIsBPset);

                bRetFunction = false;
            }
        }
        else
        {
            bRetFunction = false;
        }
    }
    else
    {
        /* Cannot set the breakpoint, leave test in a stable state */
        CommentStep("Cannot set the breakpoint, function may not be implemented or there is a problem with the debugger.");
        CommentStep("Exception: " + bIsBPset);

        bRetFunction = false;
    }

    return bRetFunction;
}

/*------------------------------------------------------------------------------
                                    Core Test
------------------------------------------------------------------------------*/

/***************************************************************************************/
/********* The TRY and CATCH words are mandatory to catch every error of test **********/
/***************************************************************************************/
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
									 CONFIGURATION TEST
		------------------------------------------------------------------------------*/

		CommentStep("Lets ECU wakeup and enter ATM running phase");
		Wait(CFGc_WakeupDelay);

		/*------------------------------------------------------------------------------
									   EXECUTION TEST
		------------------------------------------------------------------------------*/
		if (cTEST_OK == bRetFunction)
		{
			/* Check if the function is correctly called */
			bRetFunction = PP4G_LibInteg_CheckSubFunctionCall(CFGc_FunctionToTest, CFGc_SubFunctionToTest, CFGc_CallStack);

			/*** Check result of test ****/
			RESULT.ExpectTestResult("Global Verification of test", bRetFunction, cTEST_OK );

			/*------------------------------------------------------------------------------
										RESET CONFIGURATION TEST
			------------------------------------------------------------------------------*/
			RESULT.ExpectTestResult("Init Environment test", SwDevLib_InitBenchEnvironment(), cTEST_OK);
		}
		else
		{
			/*** Warn the tester that the test isn't executed ****/
			RESULT.InsertComment("Tests is not executed : configuration of test failed")
		}
	}
	else 
    {
        winIDEAWorkspace_closeDiscard();
        RESULT.ExpectTestResult("Test failed about environment initialization failed", false, true);
    }

    /*------------------------------------------------------------------------------
                            DEINITIALIZATION ENVIRONMENT
    ------------------------------------------------------------------------------*/
    // "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger)
    // RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK );
}
catch (exError)
{
    RESULT.ExpectTestResult("Test failed about exception occurs :" + exError, cException_Catched, false);
    RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}