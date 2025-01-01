/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_971_ReadMotorTemperatureAdaptationParameters_DIDFD34
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_E_971
Description of the requirement: 
ALV_EXT_TF_E_971: Each MRRx field is equivalent to a motor resistance reference factor corresponding to the respective temperature:
Resolution = 1
Offset = 0
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
var sRequest_SupplierSession = "0x10 0x7E";
var sSupplierSessionResponse = "0x50 0x7E 0x00 0x64 0x01 0xF4";
var vRetFunction = null;
var bRetFunction: Boolean = false;

var MotorResistRef0_Param = "0x78 ";
var MotorResistRef1_Param = "0x82 ";
var MotorResistRef2_Param = "0x8C ";
var MotorResistRef3_Param = "0x96 ";
var MotorResistRef4_Param = "0xA0 ";
var MotorResistRef5_Param = "0xAA ";
var MotorResistRef6_Param = "0xB4";
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
        CommentStep("***Read Motor Temperature Adaptation Parameters - DID FD34 : Positive response formatted as follow ***");
		CommentStep("***0x62 0xFD 0x34 TEMP1 TEMP2 TEMP3 TEMP5 TEMP6 TEMP7 MRR1 MRR2 MRR3 MRR4 MRR5 MRR6 MRR7***");
		RESULT.InsertComment(" ");
        CommentStep("***Verify that each MRRx field is equivalent to a Motor resistance reference factor corresponding to the respective temperature***");
		sResponse = CAN.SendDiagByValues(sRequest_SupplierSession);
		EvalManStepEqual("Enter in default session (" + sRequest_SupplierSession + ") - Positive Response:", sResponse[1], sSupplierSessionResponse);ResultStep("Positive Response for supplier sesion", "Positive Response for supplier sesion");                                                                                                           
		Wait(2000)
		sRequest = "0x22 0xFD 0x34"; 
		sResponse = CAN.SendDiagByValues(sRequest);		
		EvalManStepEqual("Read CAN response for the following request : (" + sRequest + ") - Positive Response:", sResponse[1], "0x62 0xFD 0x34 0x01 0x01 0x25 0x01 0x3F 0x01 0x55 0x01 0x65 0x01 0x7A 0x01 0x87 0x01 " + MotorResistRef0_Param + MotorResistRef1_Param + MotorResistRef2_Param + MotorResistRef3_Param + MotorResistRef4_Param + MotorResistRef5_Param + MotorResistRef6_Param);                                                                                                           
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

    CommentStep(" ***| END OF TEST |*** ");
}
catch (exError) 
{
    RESULT.ExpectTestResult("Test failed about exception occurs :" + exError, cException_Catched, false);
    RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}