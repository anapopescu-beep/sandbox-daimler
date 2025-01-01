/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_6025_DiagEcuReset_NegResp_No_other_value_send_by_ECU
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_E_6025
Description of the requirement: 
ALV_EXT_TF_E_6025: No other value shall be send by the ECU.
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

/* Service configuration */
const CFGc_SupplierSession: String = "supplier";
const CFGc_SupplierSak: String = "supplier";

/* Path log file */
const cLINTraceFile = "S:\\Tools\\ARIA\\Config\\Neeva_Configuration\\TestEnvironment_Automation\\Neeva_config\\LastOutput\\trace_trame"; // *****WARNING***** : Mount S:

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
var sRequest;
var sResponse;
var iLengthRequest;
var iNumberDataToAdd;
var sAdditionalData;

/* NRCs */
var sNegativeResponseID = "0x7F ";
var sNRC12 = " 0x12"; /* SubFunctionNotSupported */
var sNRC13 = " 0x13"; /* IncorrectMessageLengthOrInvalidFormat */
var sNRC22 = " 0x22"; /* ConditionNotCorrect */

/* 0x11 - Ecu Reset */
var sEcuResetRequest = "0x11";
var sEcuResetResponse = "0x51";
var sId_HwReset = " 0x01";
var sId_SwReset = " 0x03";

var sRequest_HwReset = sEcuResetRequest + sId_HwReset;
var sRequest_SwReset = sEcuResetRequest + sId_SwReset;

var sNegResponse_EcuReset = sNegativeResponseID + sEcuResetRequest;

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
try {
    /*------------------------------------------------------------------------------
                            INITIALIZATION ENVIRONMENT
    ------------------------------------------------------------------------------*/
    /**** This function is parametrable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/

    /****** WARNING : check optionnal parameter of the next function :it's very IMPORTANT ***********/
    vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOn", "RunOn", "5");
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
            RESULT.InsertComment(" ");

            CommentStep(" ***| SERVICE 0x11 DIAGNOSTIC ECU RESET : NRC 0x12 SubFunctionNotSupported |*** ");

            CommentStep(" *** Verify NRC12 is received when SessionId of DiagnosticEcuReset is not a defined session *** ");
            for (var iSize = 0; iSize <= 15; iSize++)
            {
                if ((iSize != 1) && (iSize != 3))
                {
                    sRequest = sEcuResetRequest + " 0x0" + SwDevLib_decimalToHexString(iSize);
                    sResponse = CAN.SendDiagByValues(sRequest);
                    EvalManStepEqual("Enter in undefined session (" + sRequest + ") - Negative Response:", sResponse[1], sNegResponse_EcuReset + sNRC12);
                }
            }
            for (iSize = 16; iSize <= 255; iSize++)
            {
                if ((iSize != 129) && (iSize != 131))
                {
                    sRequest = sEcuResetRequest + " 0x" + SwDevLib_decimalToHexString(iSize);
                    sResponse = CAN.SendDiagByValues(sRequest);
                    EvalManStepEqual("Enter in undefined session (" + sRequest + ") - Negative Response:", sResponse[1], sNegResponse_EcuReset + sNRC12);
                }
            }

            RESULT.InsertComment(" ");
            RESULT.InsertComment(" ");

            CommentStep(" ***| SERVICE 0x11 DIAGNOSTIC ECU RESET : NRC 0x13 IncorrectMessageLengthOrInvalidFormat |*** ");
            
            CommentStep(" *** Verify NRC13 is received when DiagnosticEcuReset length is lower than 2 bytes (HW Reset) *** ");
            for (iLengthRequest = 1; iLengthRequest < 2; iLengthRequest++) 
            {
                RESULT.InsertComment("Request : " + sRequest_HwReset.substring(0, iLengthRequest * 5 - 1));
                sResponse = CAN.SendDiagByValues(sRequest_HwReset.substring(0, iLengthRequest * 5 - 1));
                EvalManStepEqual("DiagnosticEcuReset response ", sResponse[1], sNegResponse_EcuReset + sNRC13);
            }

            CommentStep(" *** Verify NRC13 is received when DiagnosticEcuReset length is greater than 2 bytes (HW Reset) *** ");
            sRequest = sRequest_HwReset;
            for (iLengthRequest = 2 + 1; iLengthRequest < 30; iLengthRequest++)
            {
                sRequest += " 0x00";
                RESULT.InsertComment(sRequest);
                sResponse = CAN.SendDiagByValues(sRequest);
                EvalManStepEqual("DiagnosticEcuReset response", sResponse[1], sNegResponse_EcuReset + sNRC13);
            }

            RESULT.InsertComment(" ");

            CommentStep(" *** Verify NRC13 is received when DiagnosticEcuReset length is lower than 2 bytes (SW Reset) *** ");
            for (iLengthRequest = 1; iLengthRequest < 2; iLengthRequest++)
            {
                RESULT.InsertComment("Request : " + sRequest_SwReset.substring(0, iLengthRequest * 5 - 1));
                sResponse = CAN.SendDiagByValues(sRequest_SwReset.substring(0, iLengthRequest * 5 - 1));
                EvalManStepEqual("DiagnosticEcuReset response ", sResponse[1], sNegResponse_EcuReset + sNRC13);
            }
            Wait(CFGc_WakeupDelay);

            CommentStep(" *** Verify NRC13 is received when DiagnosticEcuReset length is greater than 2 bytes (SW Reset) *** ");
            sRequest = sRequest_SwReset;
            for (iLengthRequest = 2 + 1; iLengthRequest < 30; iLengthRequest++)
            {
                sRequest += " 0x00";
                RESULT.InsertComment(sRequest);
                sResponse = CAN.SendDiagByValues(sRequest);
                EvalManStepEqual("DiagnosticEcuReset response", sResponse[1], sNegResponse_EcuReset + sNRC13);
            }
            
            RESULT.InsertComment(" ");
            RESULT.InsertComment(" ");
            
            CommentStep(" ***| SERVICE 0x11 DIAGNOSTIC ECU RESET : NRC 0x22 ConditionNotCorrect |*** ");

            CommentStep(" *** Verify NRC22 is received when the motor is activated (HW Reset) *** ");
            EnterDiagSession(CFGc_SupplierSession);
            GetSecurityAccess(CFGc_SupplierSak);
            Wait(500);

            // Start an ALV cycle PreCrash0 //
            sRequest = "0x31 0x01 0xF7 0x03 0x00";
            sResponse = CAN.SendDiagByValues(sRequest);
            EvalManStepEqual("Start ALV cycle PreCrash0(" + sRequest + ") - Positive Response:", sResponse[1], "0x71 0x01 0xF7 0x03 0xFF");

            sResponse = CAN.SendDiagByValues(sRequest_HwReset);
            EvalManStepEqual("DiagnosticEcuReset response ", sResponse[1], sNegResponse_EcuReset + sNRC22);
            
            RESULT.InsertComment(" ");

            CommentStep(" *** Verify NRC22 is received when the motor is activated (HW Reset) *** ");
            EnterDiagSession(CFGc_SupplierSession);
            GetSecurityAccess(CFGc_SupplierSak);
            Wait(500);

            CommentStep(" *** Verify NRC22 is received when the motor is activated (SW Reset) *** ");
            sResponse = CAN.SendDiagByValues(sRequest_SwReset);
            EvalManStepEqual("DiagnosticEcuReset response ", sResponse[1], sNegResponse_EcuReset + sNRC22);
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
catch (exError) 
{
    RESULT.ExpectTestResult("Test failed about exception occurs :" + exError, cException_Catched, false);
    RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}