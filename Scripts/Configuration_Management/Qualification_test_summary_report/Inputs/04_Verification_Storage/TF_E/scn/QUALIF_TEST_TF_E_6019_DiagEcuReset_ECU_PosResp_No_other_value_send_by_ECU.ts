/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_6019_DiagEcuReset_ECU_PosResp_No_other_value_send_by_ECU
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_E_6019
Description of the requirement: 
ALV_EXT_TF_E_6019: No other value shall be sent by the ECU.
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

/* Delay to let ECU wakeup */
const CFGc_WakeupDelay = 5000;

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

            /* ECU Reset : Software Reset */
            sRequest = "0x11 0x03";
            sResponse = CAN.SendDiagByValues(sRequest);
            Wait(CFGc_WakeupDelay);
            EvalManStepEqual("Send SW Reset request (" + sRequest + ") - Positive Response:", sResponse[1], "0x51 0x03");
            
            SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOn", "RunOn", "5");
            Wait(CFGc_WakeupDelay);

            /* ECU Reset : Hardware Reset */
            sRequest = "0x11 0x01";
            sResponse = CAN.SendDiagByValues(sRequest);
            Wait(CFGc_WakeupDelay);
            EvalManStepEqual("Send HW Reset request (" + sRequest + ") - Positive Response:", sResponse[1], "0x51 0x01");
            
            SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOn", "RunOn", "5");
            Wait(CFGc_WakeupDelay);
            RESULT.InsertComment(" ");

            /* ECU Reset : Software Reset with suppressPosRspMsgIndication set (Byte 2 bit 7=1) - no Positive Response shall be sent on the network */
            sRequest = "0x11 0x83";
            sResponse = CAN.SendDiagByValues(sRequest);
            Wait(CFGc_WakeupDelay);
            EvalManStepEqual("Send SW Reset with suppressPosRspMsgIndication set (Byte 2 bit 7=1) request (" + sRequest + ") - No response:", sResponse[1], "TIMEOUT");
            RESULT.InsertComment("TIMEOUT because suppressPosRspMsgIndication is set - no Positive Response shall be sent on the network ==> requirement shall be clarify for better understanding");

            SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOn", "RunOn", "5");
            Wait(CFGc_WakeupDelay);

            /* ECU Reset : Hardware Reset with suppressPosRspMsgIndication set (Byte 2 bit 7=1) - no Positive Response shall be sent on the network */
            sRequest = "0x11 0x81";
            sResponse = CAN.SendDiagByValues(sRequest);
            Wait(CFGc_WakeupDelay);
            EvalManStepEqual("Send HW Reset with suppressPosRspMsgIndication set (Byte 2 bit 7=1) request (" + sRequest + ") - No response:", sResponse[1], "TIMEOUT");
            RESULT.InsertComment("TIMEOUT because suppressPosRspMsgIndication is set - no Positive Response shall be sent on the network ==> requirement shall be clarify for better understanding");

            SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOn", "RunOn", "5");
            Wait(CFGc_WakeupDelay);
            RESULT.InsertComment(" ");

            /* Send Undefined ResetType */
            for (var iSize = 0; iSize <= 15; iSize++)
            {
                sRequest = "0x11 0x0" + SwDevLib_decimalToHexString(iSize);

                if ((iSize != 1) && (iSize != 3))
                {
                    sResponse = CAN.SendDiagByValues(sRequest);
                    EvalManStepEqual("Send undefined ResetType (" + sRequest + ") - Negative Response (NRC 0x12 SubFunctionNotSupported):", sResponse[1], "0x7F 0x11 0x12");
                }
            }
            for (iSize = 16; iSize <= 255; iSize++)
            {
                sRequest = "0x11 0x" + SwDevLib_decimalToHexString(iSize);
                if((iSize != 129) && (iSize != 131))
                {
                    sResponse = CAN.SendDiagByValues(sRequest);
                    EvalManStepEqual("Send undefined ResetType (" + sRequest + ") - Negative Response (NRC 0x12 SubFunctionNotSupported):", sResponse[1], "0x7F 0x11 0x12");
                }
            }
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
    
    // CAN.StopLoggingToFile();

    CommentStep(" ***| END OF TEST |*** ");
}
catch(exError)
{
    RESULT.ExpectTestResult("Test failed about exception occurs :"+exError, cException_Catched, false);
    RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}