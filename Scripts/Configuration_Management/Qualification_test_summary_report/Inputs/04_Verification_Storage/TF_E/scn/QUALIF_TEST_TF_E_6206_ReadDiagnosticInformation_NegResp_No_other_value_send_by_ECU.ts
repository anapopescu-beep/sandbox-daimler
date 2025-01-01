/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_6206_ReadDiagnosticInformation_NegResp_No_other_value_send_by_ECU
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_E_6206
Description of the requirement: 
ALV_EXT_TF_E_6206: No other value shall be send by the ECU.
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
const cTEST_NOK = false;

/* Mandatory constants for test scripts */
const cENV_NON_INITIALIZED = "NO_INIT";
const cENV_NOK = false;
const cException_Catched = true;

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
var sRequest;
var sResponse;

/* NRCs */
var sNegativeResponse_NRC_RDTCI12 = "0x7F 0x19 0x12"; /* SubFunctionNotSupported */
var sNegativeResponse_NRC_RDTCI13 = "0x7F 0x19 0x13"; /* IncorrectMessageLengthOrInvalidFormat */

var sRequest_DefaultSession = "0x10 0x01";
var sRequest_ExtendedSession = "0x10 0x03";
var sRequest_SupplierSession = "0x10 0x7E";
var sRequest_ProgrammingSession = "0x10 0x02";

var sDefaultSessionResponse = "0x50 0x01 0x00 0x32 0x01 0xF4";
var sExtendedSessionResponse = "0x50 0x03 0x00 0x32 0x01 0xF4";
var sSupplierSessionResponse = "0x50 0x7E 0x00 0x64 0x01 0xF4";
var sProgrammingSessionResponse = "0x50 0x02 0x00 0x32 0x01 0xF4";

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
	RESULT.InterpretEqualResult("Remove OpenCircuit on channel "+29, FIB.RemoveFault(29), "Remove fault performed OK on channel " + 29);
    Thread.Sleep(1000);
	for(var count2=1; count2<=3; count2++)
	{
	RESULT.InterpretEqualResult("Reset channel "+count2, FIB.RestartBoard(count2), "Restart board " + count2 + " performed OK.")
	Thread.Sleep(100)
	}
    Thread.Sleep(100);
	
    vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOn", "RunOn", "5");
    if (vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK)
    {
        CommentStep("Wait ECU to wake up");
        Wait(5000);
        debugger_stop();
        /*------------------------------------------------------------------------------
                                    EXECUTION TEST
        ------------------------------------------------------------------------------*/
		debugger_run();
		RESULT.InsertComment(" ");
		RESULT.InsertComment(" ");
        CommentStep(" ***| START OF TEST |*** ");
		RESULT.InsertComment(" ");
		RESULT.InsertComment(" ");
		/***********************************************************************************************************************************************
		************************************************************************************************************************************************/
        CommentStep("***ReadDiagnosticInformation - ReportFirstConfirmedDTC (RFCDTC) : NRC 0x12 SubFunctionNotSupported***");
		RESULT.InsertComment(" ");
        CommentStep("***Verify NRC12 is received in <Default session> when the request parameter <ReportType> is invalid value***");
		sResponse = CAN.SendDiagByValues(sRequest_DefaultSession);
		EvalManStepEqual("Enter in default session (" + sRequest_DefaultSession + ") - Positive Response:", sResponse[1], sDefaultSessionResponse);                                                                                                           
		Wait(2000)
		for (var iSize = 0; iSize <= 15; iSize++)
		{
			sRequest = "0x19 0x0" + SwDevLib_decimalToHexString(iSize);
			sResponse = CAN.SendDiagByValues(sRequest);
			if ((iSize != 1) && (iSize != 2) && (iSize != 10) && (iSize != 11) && (iSize != 12) && (iSize != 13) && (iSize != 14))
            EvalManStepEqual("Check negative response for request (" + sRequest + ") - Negative Response:", sResponse[1], sNegativeResponse_NRC_RDTCI12);
		}
        CommentStep("***Verify NRC12 is received in <Extended session> when the request parameter <ReportType> is invalid value***");
		sResponse = CAN.SendDiagByValues(sRequest_ExtendedSession);
		EvalManStepEqual("Enter in default session (" + sRequest_ExtendedSession + ") - Positive Response:", sResponse[1], sExtendedSessionResponse);                                                                                                           
		Wait(2000)
		for (var iSize = 0; iSize <= 15; iSize++)
		{
			sRequest = "0x19 0x0" + SwDevLib_decimalToHexString(iSize);
			sResponse = CAN.SendDiagByValues(sRequest);
			if ((iSize != 1) && (iSize != 2) && (iSize != 10) && (iSize != 11) && (iSize != 12) && (iSize != 13) && (iSize != 14))
            EvalManStepEqual("Check negative response for request (" + sRequest + ") - Negative Response:", sResponse[1], sNegativeResponse_NRC_RDTCI12);
		}
		CommentStep("***Verify NRC12 is received in <Supplier session> when the request parameter <ReportType> is invalid value***");
		sResponse = CAN.SendDiagByValues(sRequest_SupplierSession);
		EvalManStepEqual("Enter in default session (" + sRequest_SupplierSession + ") - Positive Response:", sResponse[1], sSupplierSessionResponse);                                                                                                           
		Wait(2000)
		for (var iSize = 0; iSize <= 15; iSize++)
		{
			sRequest = "0x19 0x0" + SwDevLib_decimalToHexString(iSize);
			sResponse = CAN.SendDiagByValues(sRequest);
			if ((iSize != 1) && (iSize != 2) && (iSize != 10) && (iSize != 11) && (iSize != 12) && (iSize != 13) && (iSize != 14))
            EvalManStepEqual("Check negative response for request (" + sRequest + ") - Negative Response:", sResponse[1], sNegativeResponse_NRC_RDTCI12);
		}
		CommentStep("***Verify NRC12 is received in <Programming session> when the request parameter <ReportType> is invalid value***");
		CommentStep("***PROGRAMMING SESSION CAN NOT BE REACHED IN WHITE BOX : issue not yet corrected***");
		RESULT.InsertComment(" ");
        RESULT.InsertComment(" ");
		/***********************************************************************************************************************************************
		************************************************************************************************************************************************/
		CommentStep("***ReadDiagnosticInformation - ReportFirstConfirmedDTC (RFCDTC) : NRC 0x13 IncorrectMessageLengthOrInvalidFormat***");
		RESULT.InsertComment(" ");
		CommentStep("***Verify NRC13 is received in <Default session> when the data length is lower than 2 bytes with default session***");
		sResponse = CAN.SendDiagByValues(sRequest_DefaultSession);
		EvalManStepEqual("Enter in default session (" + sRequest_DefaultSession + ") - Positive Response:", sResponse[1], sDefaultSessionResponse);                                                                                                           
		Wait(2000)
		sRequest = "0x19 0x0C"; 
		for (var iLengthRequest = 1; iLengthRequest < 2; iLengthRequest++)
		{	
            sResponse = CAN.SendDiagByValues(sRequest.substring(0, iLengthRequest * 4 + 1));
            EvalManStepEqual("Check negative response for request (" + sRequest.substring(0, iLengthRequest * 4 + 1) + ") Negative Response: ", sResponse[1], sNegativeResponse_NRC_RDTCI13);
		}
		CommentStep(" ***Verify NRC13 is received in <Default session> when the data length is greater than 2 bytes with default session*** ");
		sRequest = "0x19 0x0C";  
        for (var iLengthRequest = 3; iLengthRequest < 10; iLengthRequest++)
        {
            sRequest += " 0x00";
            sResponse = CAN.SendDiagByValues(sRequest);
            EvalManStepEqual("Check negative response for request (" + sRequest + ") Negative Response: ", sResponse[1], sNegativeResponse_NRC_RDTCI13);
        }
		CommentStep("***Verify NRC13 is received in <Extended session> when the data length is lower than 2 bytes with default session***");
		sResponse = CAN.SendDiagByValues(sRequest_ExtendedSession);
		EvalManStepEqual("Enter in Extended session (" + sRequest_ExtendedSession + ") - Positive Response:", sResponse[1], sExtendedSessionResponse);                                                                                                           
		Wait(2000)
		sRequest = "0x19 0x0C";  
		for (var iLengthRequest = 1; iLengthRequest < 2; iLengthRequest++)
		{	
            sResponse = CAN.SendDiagByValues(sRequest.substring(0, iLengthRequest * 4 + 1));
            EvalManStepEqual("Check negative response for request (" + sRequest.substring(0, iLengthRequest * 4 + 1) + ") Negative Response: ", sResponse[1], sNegativeResponse_NRC_RDTCI13);
		}
		CommentStep(" ***Verify NRC13 is received in <Extended session> when the data length is greater than 2 bytes with default session*** ");
		sRequest = "0x19 0x0C";  
        for (var iLengthRequest = 3; iLengthRequest < 10; iLengthRequest++)
        {
            sRequest += " 0x00";
            sResponse = CAN.SendDiagByValues(sRequest);
            EvalManStepEqual("Check negative response for request (" + sRequest + ") Negative Response: ", sResponse[1], sNegativeResponse_NRC_RDTCI13);
        }
		CommentStep("***Verify NRC13 is received in <Supplier session> when the data length is lower than 2 bytes with default session***");
		sResponse = CAN.SendDiagByValues(sRequest_SupplierSession);
		EvalManStepEqual("Enter in Supplier session (" + sRequest_SupplierSession + ") - Positive Response:", sResponse[1], sSupplierSessionResponse);                                                                                                           
		Wait(2000)
		sRequest = "0x19 0x0C";  
		for (var iLengthRequest = 1; iLengthRequest < 2; iLengthRequest++)
		{	
            sResponse = CAN.SendDiagByValues(sRequest.substring(0, iLengthRequest * 4 + 1));
            EvalManStepEqual("Check negative response for request (" + sRequest.substring(0, iLengthRequest * 4 + 1) + ") Negative Response: ", sResponse[1], sNegativeResponse_NRC_RDTCI13);
			
		}
		CommentStep(" ***Verify NRC13 is received in <Supplier session> when the data length is greater than 2 bytes with default session*** ");
		sRequest = "0x19 0x0C";  
        for (var iLengthRequest = 3; iLengthRequest < 10; iLengthRequest++)
        {
            sRequest += " 0x00";
            sResponse = CAN.SendDiagByValues(sRequest);
            EvalManStepEqual("Check negative response for request (" + sRequest + ") Negative Response: ", sResponse[1], sNegativeResponse_NRC_RDTCI13);
        }
		CommentStep(" ***Verify NRC13 is received in <Programming session> when the data length is lower than 2 bytes with default session*** ");		
		CommentStep("***PROGRAMMING SESSION CAN NOT BE REACHED IN WHITE BOX : issue not yet corrected***");
		RESULT.InsertComment(" ");
        RESULT.InsertComment(" ");
		CommentStep(" ***| END OF TEST |*** ");	
		RESULT.InsertComment(" ");
        RESULT.InsertComment(" ");
    }
    else 
    {
		winIDEAWorkspace_closeDiscard();
        RESULT.ExpectTestResult("Test failed about environment initialization failed", false, true);
    }

}
catch (exError) 
{
    RESULT.ExpectTestResult("Test failed about exception occurs :" + exError, cException_Catched, false);
    RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}