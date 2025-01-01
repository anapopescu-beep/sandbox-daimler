/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_6538_ReadMemoryByAddress_NegResp_No_other_value_send_by_ECU
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_E_6538
Description of the requirement: 
ALV_EXT_TF_E_6538: No other value shall be send by the ECU.
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
var sNegativeResponse_NRC_RDTCI12 = "0x7F 0x23 0x12"; /* SubFunctionNotSupported */
var sNegativeResponse_NRC_RDTCI13 = "0x7F 0x23 0x13"; /* IncorrectMessageLengthOrInvalidFormat */

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
//	RESULT.InterpretEqualResult("Remove OpenCircuit on channel "+29, FIB.RemoveFault(29), "Remove fault performed OK on channel " + 29);
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
        CommentStep("***ReadMemoryByAddress  : NRC 0x33***");
		RESULT.InsertComment(" ");
        CommentStep("***Verify NRC33 is not received received in <Supplier session> ***");                                                                               
		sResponse = CAN.SendDiagByValues(sRequest_SupplierSession);
		EvalManStepEqual("Enter in Supplier session (" + sRequest_SupplierSession + ") - Positive Response:", sResponse[1], sSupplierSessionResponse);                                                                                                           
		Wait(2000)
		
		sRequest = "0x23 0x24 0x14 0x00 0x00 0x5C 0x00 0x01";
		sResponse = CAN.SendDiagByValues(sRequest);
		EvalManStepEqual("Check negative response for request (" + sRequest + ") - Negative Response:", sResponse[1], "TIMEOUT");
		
        CommentStep("***NRC33 shall be part of the ignored NRC according to specification. TEST is FAILED**");
		
		CommentStep(" ***| END OF TEST |*** ");	
		sResponse = CAN.SendDiagByValues(sRequest_SupplierSession);
		EvalManStepEqual("Enter in supplier session (" + sRequest_SupplierSession + ") - Positive Response:", sResponse[1], sSupplierSessionResponse);                            
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