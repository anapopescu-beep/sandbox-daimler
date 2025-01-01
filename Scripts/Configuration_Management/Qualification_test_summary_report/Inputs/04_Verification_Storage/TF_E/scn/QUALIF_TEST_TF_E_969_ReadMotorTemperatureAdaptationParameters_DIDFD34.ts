/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_969_ReadMotorTemperatureAdaptationParameters_DIDFD34
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_E_969
Description of the requirement: 
ALV_EXT_TF_E_969: Each TEMPx field is equivalent to an ADC output monitoring the temperature sensor, with nominal values:
Resolution = 0.967 °C / LSB
Offset = -295.0000 (i.e. 0x0000 equals -295°C)
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

var TemperatureMotorResist0_Param = "0x01 0x01 ";	//LSB MSB
var TemperatureMotorResist1_Param = "0x25 0x01 ";	//LSB MSB
var TemperatureMotorResist2_Param = "0x3F 0x01 ";	//LSB MSB
var TemperatureMotorResist3_Param = "0x55 0x01 "; 	//LSB MSB
var TemperatureMotorResist4_Param = "0x65 0x01 ";	//LSB MSB
var TemperatureMotorResist5_Param = "0x7A 0x01 "; 	//LSB MSB
var TemperatureMotorResist6_Param = "0x87 0x01 ";	// LSB MSB

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
        CommentStep("***Verify that each TEMPx field is equivalent to an ADC output monitoring the temperature sensor, with nominal values***");
		sResponse = CAN.SendDiagByValues(sRequest_SupplierSession);
		EvalManStepEqual("Enter in Supplier session (" + sRequest_SupplierSession + ") - Positive Response:", sResponse[1], sSupplierSessionResponse);
		ResultStep("Positive Response for supplier sesion", "Positive Response for supplier sesion");                                                                                                           
		Wait(2000)
		sRequest = "0x22 0xFD 0x34";
		sResponse = CAN.SendDiagByValues(sRequest);		
		EvalManStepEqual("Read CAN response for the following request : (" + sRequest + ") - Positive Response:", sResponse[1], "0x62 0xFD 0x34 " + TemperatureMotorResist0_Param + TemperatureMotorResist1_Param + TemperatureMotorResist2_Param + TemperatureMotorResist3_Param + TemperatureMotorResist4_Param + TemperatureMotorResist5_Param + TemperatureMotorResist6_Param + "0x?? 0x?? 0x?? 0x?? 0x?? 0x?? 0x??");                                                                                                           
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