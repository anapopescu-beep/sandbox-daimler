/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_45_DiagSessionControl_ECU_Ignored_value
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_E_45
Description of the requirement: 
ALV_EXT_TF_E_45: Other value shall be ignored by the ECU.
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

/* WinIDEA intialization options */
const CFGc_FlashMode: String = "FlashOff";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String = "ResethOff";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String = "RunOff";    /* [RunOn, RunOff] */

/* Path log file */
const cLINTraceFile = "S:\\Tools\\ARIA\\Config\\Neeva_Configuration\\TestEnvironment_Automation\\Neeva_config\\LastOutput\\trace_trame"; // *****WARNING***** : Mount S:

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
var sRequest;
var sResponse;

/* Variable used to check the test initialization phase */
var vRetFunction = null;

/* Boolean used to check if the test configuration is succesful */
var bRetFunction: Boolean = false;

/*------------------------------------------------------------------------------
                                GLOBAL FUNCTIONS
 ------------------------------------------------------------------------------*/
 

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
    vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn","ResetOn","RunOn","5");
    if(vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK)
    {
        // CAN.StartLoggingToFile(cLINTraceFile + ".txt");  ?? don't work

        /*------------------------------------------------------------------------------
                                    CONFIGURATION TEST
        ------------------------------------------------------------------------------*/
        
			/* Wait until ECU is up running */
			CommentStep(" ***| Let ECU wakeup |*** ");
			Wait(1000);
        
			/* Configure test */
			bRetFunction = true;
			
        /*------------------------------------------------------------------------------
                                    EXECUTION TEST
        ------------------------------------------------------------------------------*/
        if (cTEST_OK == bRetFunction)
        {
            CommentStep(" ***| START OF TEST |*** ");

            /* Entering Undefined session 
            sRequest = "0x10 0x81";
            sResponse = CAN.SendDiagByValues(sRequest);
            EvalManStepEqual("Enter in undefined session (" + sRequest + ") - Positive Response:", sResponse[1], "0x7F 0x10 0x12");
            Wait(5000);
            */

            /* Entering Allowed and Undefined sessions */
            //*
            for (var iSize = 0; iSize <= 15; iSize++)
            {
                sRequest = "0x10 0x0" + SwDevLib_decimalToHexString(iSize);
                sResponse = CAN.SendDiagByValues(sRequest);

                if (iSize == 1)
                {
                    /* Entering Default session */
                    EvalManStepEqual("Enter in default session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x01 0x00 0x32 0x01 0xF4");
                    Wait(5000);
                }
                else if (iSize == 2)
                {
                    /* Entering Programming session */
                    EvalManStepEqual("Enter in programming session (" + sRequest + ") - Negative Response (NRC 0x7E ServiceNotSupportedInActiveSession):", sResponse[1], "0x7F 0x10 0x7E");
                    RESULT.InsertComment("NRC 0x7E Because we can't reach programming session since default session. Besides, Programming session is not required for R1.1");
                }
                else if (iSize == 3)
                {
                    /* Entering Extended session */
                    EvalManStepEqual("Enter in extended session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x03 0x00 0x32 0x01 0xF4");
                    Wait(5000);
                }
                else
                {
                    EvalManStepEqual("Enter in undefined session (" + sRequest + ") - Negative Response (NRC 0x12 SubFunctionNotSupported):", sResponse[1], "0x7F 0x10 0x12");
                }
            }
            for (iSize = 16; iSize <= 255; iSize++)
            {
                sRequest = "0x10 0x" + SwDevLib_decimalToHexString(iSize);
                sResponse = CAN.SendDiagByValues(sRequest);

                if (iSize == 126)
                {
                    /* Entering Supplier session */
                    EvalManStepEqual("Enter in supplier session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x7E 0x00 0x64 0x01 0xF4");
                    Wait(5000);
                }
                else if ((iSize == 129) || (iSize == 131) || (iSize == 254))
                {
                    /* Entering undefined session - with TIMEOUT */
                    EvalManStepEqual("Enter in undefined session (" + sRequest + ") - No response:", sResponse[1], "TIMEOUT");
                    RESULT.InsertComment("TIMEOUT because suppressPosRspMsgIndication is set - no Positive Response shall be sent on the network => requirement shall be clarify for better understanding");
                }
                else if (iSize == 130)
                {
                    /* Entering undefined session with the same behavior than Programming session */
                    EvalManStepEqual("Enter in programming session like (" + sRequest + ") - Negative Response (NRC 0x7E ServiceNotSupportedInActiveSession):", sResponse[1], "0x7F 0x10 0x7E");
                    RESULT.InsertComment("NRC 0x7E Because we can't reach programming session since default session. Besides, Programming session is not required for R1.1");
                }
                else
                {
                    EvalManStepEqual("Enter in undefined session (" + sRequest + ") - Negative Response (NRC 0x12 SubFunctionNotSupported):", sResponse[1], "0x7F 0x10 0x12");
                }
            }
            //*/
        }
        else
        {
            /* Warn the tester that the test isn't executed */
            RESULT.ExpectTestResult("Tests isn't executed : configuration NOK", false, cTEST_OK);  
        }

        /*------------------------------------------------------------------------------
                                RESET CONFIGURATION TEST
        ------------------------------------------------------------------------------*/
        bRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOn", "RunOn", "5");
        // this check is mandatory to verify the configuration of test
        RESULT.ExpectTestResult("Reset Configuration Test ", bRetFunction, cTEST_OK);

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
    
    // CAN.StopLoggingToFile(); ?? don't work

    CommentStep(" ***| END OF TEST |*** ");
}
catch(exError)
{
    RESULT.ExpectTestResult("Test failed about exception occurs :"+exError, cException_Catched, false);
    RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}