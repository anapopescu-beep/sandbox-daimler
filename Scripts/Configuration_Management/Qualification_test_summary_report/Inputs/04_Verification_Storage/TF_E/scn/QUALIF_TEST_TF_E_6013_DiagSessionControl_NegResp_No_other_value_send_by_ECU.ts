/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_6013_DiagSessionControl_NegResp_No_other_value_send_by_ECU
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_E_6013
Description of the requirement: 
ALV_EXT_TF_E_6013: No other value shall be send by the ECU.
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
var iLengthRequest;
var iNumberDataToAdd;
var sAdditionalData;

/* NRCs */
var sNegativeResponseID = "0x7F ";
var sNRC12 = " 0x12"; /* SubFunctionNotSupported */
var sNRC13 = " 0x13"; /* IncorrectMessageLengthOrInvalidFormat */
var sNRC22 = " 0x22"; /* ConditionNotCorrect */
var sNRC72 = " 0x72"; /* GeneralProgrammingFailure */
var sNRC7E = " 0x7E"; /* SubFunctionNotSupportedInActiveSession */

/* 0x10 - Session Control */
var sSessionControlRequest = "0x10";
var sSessionControlResponse = "0x50";

var sRequest_DefaultSession = sSessionControlRequest + " 0x01";
var sRequest_ProgrammingSession = sSessionControlRequest + " 0x02";
var sRequest_ExtendedSession = sSessionControlRequest + " 0x03";
var sRequest_SupplierSession = sSessionControlRequest + " 0x7E";

var sDefaultSessionResponse = " 0x01 0x00 0x32 0x01 0xF4";
var sProgrammingSessionResponse = " 0x02 0x00 0x32 0x01 0xF4";
var sExtendedSessionResponse = " 0x03 0x00 0x32 0x01 0xF4";
var sSupplierSessionResponse = " 0x7E 0x00 0x64 0x01 0xF4";

var sNegResponse_SessionControl = sNegativeResponseID + sSessionControlRequest;

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
            Wait(1000);

            /* Configure test */
            bRetFunction = true;

        /*------------------------------------------------------------------------------
                                    EXECUTION TEST
        ------------------------------------------------------------------------------*/
        if (cTEST_OK == bRetFunction) 
        {
            CommentStep(" ***| START OF TEST |*** ");
            RESULT.InsertComment(" ");

            //*
            CommentStep(" ***| SERVICE 0x10 DIAGNOSTIC SESSION CONTROL : NRC 0x12 SubFunctionNotSupported |*** ");

            CommentStep(" *** Verify NRC12 is received when SessionId of DiagnosticSessionControl is not a defined session *** ");
            for (var iSize = 0; iSize <= 15; iSize++)
            {
                sRequest = sSessionControlRequest + " 0x0" + SwDevLib_decimalToHexString(iSize);
                sResponse = CAN.SendDiagByValues(sRequest);

                if ((iSize != 1) && (iSize != 2) && (iSize != 3))
                    EvalManStepEqual("Enter in undefined session (" + sRequest + ") - Negative Response:", sResponse[1], sNegResponse_SessionControl + sNRC12);
            }
            for (iSize = 16; iSize <= 255; iSize++)
            {
                sRequest = sSessionControlRequest + " 0x" + SwDevLib_decimalToHexString(iSize);
                sResponse = CAN.SendDiagByValues(sRequest);

                if ((iSize != 126) && (iSize != 129) && (iSize != 130) && (iSize != 131) && (iSize != 254))
                    EvalManStepEqual("Enter in undefined session (" + sRequest + ") - Negative Response:", sResponse[1], sNegResponse_SessionControl + sNRC12);
            }
            //*/

            RESULT.InsertComment(" ");
            RESULT.InsertComment(" ");

            //*
            CommentStep(" ***| SERVICE 0x10 DIAGNOSTIC SESSION CONTROL : NRC 0x13 IncorrectMessageLengthOrInvalidFormat |*** ");
            
            CommentStep(" *** Verify NRC13 is received when DiagnosticSessionControl length is lower than 2 bytes with default session *** ");
            for (iLengthRequest = 1; iLengthRequest < 2; iLengthRequest++) 
            {
                RESULT.InsertComment("Request : " + sRequest_DefaultSession.substring(0, iLengthRequest * 5 - 1));
                sResponse = CAN.SendDiagByValues(sRequest_DefaultSession.substring(0, iLengthRequest * 5 - 1));
                EvalManStepEqual("DiagnosticSessionControl response ", sResponse[1], sNegResponse_SessionControl + sNRC13);
            }

            CommentStep(" *** Verify NRC13 is received when DiagnosticSessionControl length is greater than 2 bytes with default session *** ");
            sRequest = sRequest_DefaultSession;
            for (iLengthRequest = 2 + 1; iLengthRequest < 30; iLengthRequest++)
            {
                sRequest += " 0x00";
                RESULT.InsertComment(sRequest);
                sResponse = CAN.SendDiagByValues(sRequest);
                EvalManStepEqual("DiagnosticSessionControl response", sResponse[1], sNegResponse_SessionControl + sNRC13);
            }

            RESULT.InsertComment(" ");

            CommentStep(" *** Verify NRC13 is received when DiagnosticSessionControl length is lower than 2 bytes with extended session *** ");
            for (iLengthRequest = 1; iLengthRequest < 2; iLengthRequest++) {
                RESULT.InsertComment("Request : " + sRequest_ExtendedSession.substring(0, iLengthRequest * 5 - 1));
                sResponse = CAN.SendDiagByValues(sRequest_ExtendedSession.substring(0, iLengthRequest * 5 - 1));
                EvalManStepEqual("DiagnosticSessionControl response ", sResponse[1], sNegResponse_SessionControl + sNRC13);
            }
            Wait(5000);

            CommentStep(" *** Verify NRC13 is received when DiagnosticSessionControl length is greater than 2 bytes with extended session *** ");
            sRequest = sRequest_ExtendedSession;
            for (iLengthRequest = 2 + 1; iLengthRequest < 30; iLengthRequest++) {
                sRequest += " 0x00";
                RESULT.InsertComment(sRequest);
                sResponse = CAN.SendDiagByValues(sRequest);
                EvalManStepEqual("DiagnosticSessionControl response", sResponse[1], sNegResponse_SessionControl + sNRC13);
            }

            CommentStep(" *** Verify NRC13 is received when DiagnosticSessionControl length is lower than 2 bytes with supplier session *** ");
            for (iLengthRequest = 1; iLengthRequest < 2; iLengthRequest++) {
                RESULT.InsertComment("Request : " + sRequest_SupplierSession.substring(0, iLengthRequest * 5 - 1));
                sResponse = CAN.SendDiagByValues(sRequest_SupplierSession.substring(0, iLengthRequest * 5 - 1));
                EvalManStepEqual("DiagnosticSessionControl response ", sResponse[1], sNegResponse_SessionControl + sNRC13);
            }

            CommentStep(" *** Verify NRC13 is received when DiagnosticSessionControl length is greater than 2 bytes with supplier session *** ");
            sRequest = sRequest_SupplierSession
            for (iLengthRequest = 2 + 1; iLengthRequest < 30; iLengthRequest++) {
                sRequest += " 0x00";
                RESULT.InsertComment(sRequest);
                sResponse = CAN.SendDiagByValues(sRequest);
                EvalManStepEqual("DiagnosticSessionControl response", sResponse[1], sNegResponse_SessionControl + sNRC13);
            }
            //*/
            
            RESULT.InsertComment(" ");
            RESULT.InsertComment(" ");
            
            //*
            CommentStep(" ***| SERVICE 0x10 DIAGNOSTIC SESSION CONTROL : NRC 0x7E SubFunctionNotSupportedInActiveSession |*** ");

            CommentStep(" *** Verify NRC7E is received when attempt to go from default to programming session *** ");
            sResponse = CAN.SendDiagByValues(sRequest_DefaultSession);
            EvalManStepEqual("Enter in default session (" + sRequest_DefaultSession + ") - Positive Response:", sResponse[1], sSessionControlResponse + sDefaultSessionResponse);
            sResponse = CAN.SendDiagByValues(sRequest_ProgrammingSession);
            EvalManStepEqual("Enter in programming session (" + sRequest_ProgrammingSession + ") - Negative Response:", sResponse[1], sNegResponse_SessionControl + sNRC7E);
            Wait(5000);

            RESULT.InsertComment(" ");
            CommentStep(" *** Verify NRC7E is received when attempt to go from supplier to extended session *** ");
            sResponse = CAN.SendDiagByValues(sRequest_SupplierSession);
            EvalManStepEqual("Enter in supplier session (" + sRequest_SupplierSession + ") - Positive Response:", sResponse[1], sSessionControlResponse + sSupplierSessionResponse);
            sResponse = CAN.SendDiagByValues(sRequest_ExtendedSession);
            EvalManStepEqual("Enter in extended session (" + sRequest_ExtendedSession + ") - Negative Response:", sResponse[1], sNegResponse_SessionControl + sNRC7E);
            Wait(5000);

            RESULT.InsertComment(" ");
            CommentStep(" *** Verify NRC7E is received when attempt to go from supplier to programming session *** ");
            sResponse = CAN.SendDiagByValues(sRequest_SupplierSession);
            EvalManStepEqual("Enter in supplier session (" + sRequest_SupplierSession + ") - Positive Response:", sResponse[1], sSessionControlResponse + sSupplierSessionResponse);
            sResponse = CAN.SendDiagByValues(sRequest_ProgrammingSession);
            EvalManStepEqual("Enter in programming session (" + sRequest_ProgrammingSession + ") - Negative Response:", sResponse[1], sNegResponse_SessionControl + sNRC7E);
            Wait(5000);
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
catch (exError) 
{
    RESULT.ExpectTestResult("Test failed about exception occurs :" + exError, cException_Catched, false);
    RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}