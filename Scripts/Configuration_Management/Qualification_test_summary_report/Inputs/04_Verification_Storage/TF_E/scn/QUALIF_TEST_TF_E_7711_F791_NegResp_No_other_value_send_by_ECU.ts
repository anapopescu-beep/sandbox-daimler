/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_7711_F791_NegResp_No_other_value_send_by_ECU
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_E_7711
Description of the requirement: 
ALV_EXT_TF_E_7711: No other value shall be send by the ECU.
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
var sNegativeResponse_NRC_RDBLI13 = "0x7F 0x31 0x13"; /* IncorrectMessageLengthOrInvalidFormat */
var sNegativeResponse_NRC_RDBLI31 = "0x7F 0x31 0x31"; /* RequestOutOfRange */
var sNegativeResponse_NRC_RDBLI12 = "0x7F 0x31 0x12";

var sRequest_DefaultSession = "0x10 0x01";
var sRequest_ExtendedSession = "0x10 0x03";
var sRequest_SupplierSession = "0x10 0x7E";
var sRequest_ProgrammingSession = "0x10 0x02";

var sDefaultSessionResponse = "0x50 0x01 0x00 0x32 0x01 0xF4";
var sExtendedSessionResponse = "0x50 0x03 0x00 0x32 0x01 0xF4";
var sSupplierSessionResponse = "0x50 0x7E 0x00 0x64 0x01 0xF4";
var sProgrammingSessionResponse = "0x50 0x02 0x00 0x32 0x01 0xF4";

var vRetFunction = null;
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
	//RESULT.InterpretEqualResult("Remove OpenCircuit on channel "+29, FIB.RemoveFault(29), "Remove fault performed OK on channel " + 29);
    Thread.Sleep(1000);
	for(var count2=1; count2<=3; count2++)
	{
//	RESULT.InterpretEqualResult("Reset channel "+count2, FIB.RestartBoard(count2), "Restart board " + count2 + " performed OK.")
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
  	    CommentStep("***WriteDataByIdentifier - DIDFEFF :***");
		for (var iSize = 0; iSize <= 15; iSize++)
		{
			sResponse = CAN.SendDiagByValues(sRequest_SupplierSession);
			EvalManStepEqual("Enter in Supplier session (" + sRequest_SupplierSession + ") - Positive Response:", sResponse[1], sSupplierSessionResponse);

			sRequest ="0x27 0x61 and 0x27 0x62"
			sResponse = CAN.SecurityAccess(0x61)
			EvalManStepEqual("Get Security Access (" + sRequest + ") - Positive Response:", sResponse[1], "0x67 0x62")

			sRequest = "0x31 0x01 0xF7 0x81"
			sResponse = CAN.SendDiagByValues(sRequest);
			EvalManStepEqual("Unlock the ECU: (" + sRequest + ") - Positive Response:", sResponse[1], "0x71 0x01 0xF7 0x81 0xFF")
			RESULT.InsertComment(" ");
			
			Wait(100)
					
			sRequest = "0x31 0x0" + SwDevLib_decimalToHexString(iSize) + " 0xF7 0x91";
			sResponse = CAN.SendDiagByValues(sRequest);
			if ((iSize != 1) && (iSize != 3))
            EvalManStepEqual("Check negative response for request (" + sRequest + ") - Negative Response:", sResponse[1], sNegativeResponse_NRC_RDBLI12);
		}
		
		Wait(500)
		for (var iSize = 0; iSize <= 15; iSize++)
		{
			sResponse = CAN.SendDiagByValues(sRequest_SupplierSession);
			EvalManStepEqual("Enter in Supplier session (" + sRequest_SupplierSession + ") - Positive Response:", sResponse[1], sSupplierSessionResponse);

			sRequest ="0x27 0x61 and 0x27 0x62"
			sResponse = CAN.SecurityAccess(0x61)
			EvalManStepEqual("Get Security Access (" + sRequest + ") - Positive Response:", sResponse[1], "0x67 0x62")

			sRequest = "0x31 0x01 0xF7 0x81"
			sResponse = CAN.SendDiagByValues(sRequest);
			EvalManStepEqual("Unlock the ECU: (" + sRequest + ") - Positive Response:", sResponse[1], "0x71 0x01 0xF7 0x81 0xFF")
			RESULT.InsertComment(" ");
			
			Wait(100)
			
			sRequest = "0x31 0x01 0xF" + SwDevLib_decimalToHexString(iSize) + " 0x91";
			sResponse = CAN.SendDiagByValues(sRequest);
			if ((iSize != 7))
            EvalManStepEqual("Check negative response for request (" + sRequest + ") - Negative Response:", sResponse[1], sNegativeResponse_NRC_RDBLI31);
		}
		
		Wait(500)
						
		for (var iSize = 0; iSize <= 15; iSize++)
		{
			sResponse = CAN.SendDiagByValues(sRequest_SupplierSession);
			EvalManStepEqual("Enter in Supplier session (" + sRequest_SupplierSession + ") - Positive Response:", sResponse[1], sSupplierSessionResponse);

			sRequest ="0x27 0x61 and 0x27 0x62"
			sResponse = CAN.SecurityAccess(0x61)
			EvalManStepEqual("Get Security Access (" + sRequest + ") - Positive Response:", sResponse[1], "0x67 0x62")

			sRequest = "0x31 0x01 0xF7 0x81"
			sResponse = CAN.SendDiagByValues(sRequest);
			EvalManStepEqual("Unlock the ECU: (" + sRequest + ") - Positive Response:", sResponse[1], "0x71 0x01 0xF7 0x81 0xFF")
			RESULT.InsertComment(" ");
			
			Wait(100)
			
			sRequest = "0x31 0x01 0xF7 0x91 0x0" + SwDevLib_decimalToHexString(iSize);
			sResponse = CAN.SendDiagByValues(sRequest);
            EvalManStepEqual("Check negative response for request (" + sRequest + ") - Negative Response:", sResponse[1], sNegativeResponse_NRC_RDBLI13);
		}
	
		CommentStep(" ***| END OF TEST |*** ");	
		RESULT.InsertComment(" ");
        RESULT.InsertComment(" ");
    }
    else 
    {
        winIDEAWorkspace_closeDiscard();
        RESULT.ExpectTestResult("Test failed about environment initialization failed", false, true);
    }

    CommentStep(" ***| END OF TEST |*** ");
}
catch (exError) 
{
    RESULT.ExpectTestResult("Test failed about exception occurs :" + exError, cException_Catched, false);
    RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}