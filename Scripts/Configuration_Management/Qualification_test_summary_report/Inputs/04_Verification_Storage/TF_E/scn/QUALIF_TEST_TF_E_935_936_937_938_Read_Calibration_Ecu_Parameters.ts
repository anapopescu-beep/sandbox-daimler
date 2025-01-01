/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_935_936_937_938_Read_Calibration_Ecu_Parameters
Result Test:
************************************************************************************************
Requirement under test: :ALV_EXT_TF_E_935, ALV_EXT_TF_E_936, ALV_EXT_TF_E_937, ALV_EXT_TF_E_938.
Description of the requirement: The Read ECU Calibration Parameters allows to read out the stored half-Bridge calibration data,
 for both tensioning/Design and releasing/Presenting directions. 
 A table of up to 5 functioning points in each direction is available for calibration. 
REQ1: Description 1
REQ2: Description 2
************************************************************************************************
Equipment: PowerSupply, CanCaseXL, MockUp
Test Notes: Some Comments..
Full Automation: (Yes/No)
Global Result Assignment: (Neeva / Tester)
************************************************************************************************

/********************************************************************************/
/*                             Format test script                               */
/********************************************************************************/
/*------------------------------------------------------------------------------
                                IMPORT LIBRARY
 ------------------------------------------------------------------------------*/
 /**** USE RELATIVE PATH TO IMPORT A INTEG LIBRARY ****/
/*CALL(/../../ProjectLib_Development/INTEG_LIB/Template_Lib_Integration.ts); */
  /**** USE RELATIVE PATH TO IMPORT A QUALIF LIBRARY ****/
/*CALL(/../../ProjectLib_Development/QUALIF_LIB/Template_Lib_Qualification.ts); */
  /**** USE RELATIVE PATH TO IMPORT A SBE LIBRARY ****/
 CALL(/../../ProjectLib_Development/SBE_Configuration.ts);
 /**** USE RELATIVE PATH TO IMPORT A CONFIGURATION FILE *****/
/*CALL(\Config\Template_Config.ts);*/
 /*------------------------------------------------------------------------------
                                CONSTANTS
 ------------------------------------------------------------------------------*/
const cTEST_OK = true;/* Constant for the tests */
const cTest_NOK = false;
const cENV_NON_INITIALIZED = "NO_INIT";/* Mandatory constant */
const cENV_NOK = false;/* Mandatory constant */
const cException_Catched = true;/* MANDATORY CONSTANT FOR ALL TEST SCRIPTS */

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50"; 

/* WinIDEA initialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Variable containing the request */
var sRequest

var sintIndex :int = 0;
var astrNamefunction:String[] = ["NameFunction0","NameFunction1"];
var strNameFunction:String = "NameFunction";
var aInformationAutoliv = new Array(); /*table of Element with different types */
var f32MaxValue :float = 0.26;
var vUndefinedType; /* Variable with type undefined but defined at assignation */
var vBreakPointResetCauseLine : int = 402;

var bConfRet: Boolean = false;
var sintInitValue:int; 
var MAU =0x4;

/*------------------------------------------------------------------------------
                                GLOBAL FUNCTIONS
 ------------------------------------------------------------------------------*/
 /********************************************************************* 
 * @name : PP4G_ExecuteTestIntegrationOrualification
 * @brief : This function executes a specific test
 * param : aInformationAutoliv : Use to define the tempate
 * @return : boolean result of test
***********************************************************************/
function PP4G_ExecuteTestIntegrationOrQualification(aInformationAutoliv:Array[]):boolean
{
    /**** LOCAL VARIABLES ****/
    var bRetLocalFunction:boolean = false;

    RESULT.InsertComment("PP4G project is so COOL");
    bRetLocalFunction = cTEST_OK;

    return bRetLocalFunction
}

 function TestConfiguration(): Boolean
 {
    var resultSig;
    var ret: boolean = true;
 
    /* Enable MF block 18 to monitor belt profile execution */
    ActivateMeasurementFrame(18);
 
    return (ret);
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
   /**** This function is parameterizable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/

   /****** WARNING : check optional parameter of the next function :it's very IMPORTANT ***********/
   CommentStep("Initialize environment");
   vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply(CFGc_FlashMode, CFGc_ResetMode, CFGc_RunMode, CFGc_MinCurrentToRunTest);
   
    if(vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK)
    {
        /*------------------------------------------------------------------------------
                                    CONFIGURATION TEST
        ------------------------------------------------------------------------------*/

        /* Wait until ECU is up running */
	    CommentStep("Let ECU wakeup");
		Wait(10000);
        
		/* Configure test */
		bConfRet = TestConfiguration();
		Wait(10000);
        /*------------------------------------------------------------------------------
                                    EXECUTION TEST
        ------------------------------------------------------------------------------*/

        if (true == bConfRet )
        {
            CommentStep("Configuration needed for the F781 service");
            RESULT.InsertComment(" ");
        
        
        /* Entering Supplier session */                
        sRequest ="0x10 0x7E"
		CommentStep("Check Supplier session availability");
        sResponse = CAN.SendDiagByValues(sRequest);
        EvalManStepEqual("Enter in supplier session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x7E 0x00 0x64 0x01 0xF4")
		ResultStep("Positive Response for supplier sesion", "Positive Response for supplier sesion");
        
        /*Security Access */
        sRequest ="0x27 0x61 and 0x27 0x62"
		CommentStep("Check Security Access availability");
        sResponse = CAN.SecurityAccess(0x61)
        EvalManStepEqual("Get Security Access (" + sRequest + ") - Positive Response:", sResponse[1], "0x67 0x62")
		ResultStep("Positive Response for security access", "Positive Response for security access");
        
        /*Unlock the ECU */
		CommentStep("Unlocking ECU");
        sRequest = "0x31 0x01 0xF7 0x81"
        sResponse = CAN.SendDiagByValues(sRequest);
        EvalManStepEqual("Unlock the ECU: (" + sRequest + ") - Positive Response:", sResponse[1], "0x71 0x01 0xF7 0x81 0xFF")
        RESULT.InsertComment(" ");
		ResultStep("Positive Response for ECU unlock", "Positive Response for ECU unlock");

        
        Wait(1000)

        sRequest = "0x22 0xFD 0x31"
        sResponse = CAN.SendDiagByValues(sRequest);
       
			EvalManStepEqual("Reading DataIdentifier of ECU Calibration parameters (" + sRequest + ") - Positive Response:", sResponse[1].substring(0, 14), "0x62 0xFD 0x31");
            Wait(500);

            
			EvalManStepEqual("current sense : reading ADR1  A/D register value at the releasing/Presenting (" + sRequest + ") - Positive Response:", sResponse[1].substring(15, 24), "0x00 0x32");
			EvalManStepEqual("current sense : reading ADR2  A/D register value at the releasing/Presenting (" + sRequest + ") - Positive Response:", sResponse[1].substring(25, 34), "0x00 0x89");
			EvalManStepEqual("current sense : reading ADR3 A/D register value at the releasing/Presenting (" + sRequest + ") - Positive Response:", sResponse[1].substring(35, 44), "0x01 0x36");
            EvalManStepEqual("current sense : reading ADR4 A/D register value at the releasing/Presenting (" + sRequest + ") - Positive Response:", sResponse[1].substring(45, 54), "0x03 0xFF");
            EvalManStepEqual("current sense : reading ADR4 A/D register value at the releasing/Presenting (" + sRequest + ") - Positive Response:", sResponse[1].substring(55, 64), "0x03 0xFF");
			EvalManStepEqual("current sense : reading ADT1  A/D register value at the tensioning/Design (" + sRequest + ") - Positive Response:", sResponse[1].substring(65,74 ), "0x00 0x33");
			EvalManStepEqual("current sense : reading ADT2  A/D register value at the tensioning/Design (" + sRequest + ") - Positive Response:", sResponse[1].substring(75,84 ), "0x00 0x7B");
			EvalManStepEqual("current sense : reading ADT3  A/D register value at the tensioning/Design (" + sRequest + ") - Positive Response:", sResponse[1].substring(85,94 ), "0x01 0x08");
			EvalManStepEqual("current sense : reading ADT4  A/D register value at the tensioning/Design (" + sRequest + ") - Positive Response:", sResponse[1].substring(95,104 ), "0x02 0x8A");
			EvalManStepEqual("current sense : reading ADT5  A/D register value at the tensioning/Design (" + sRequest + ") - Positive Response:", sResponse[1].substring(105,114 ), "0x03 0xFF");
			EvalManStepEqual("the motor current : IMR1 the motor current value at the releasing/Presenting functional point x (" + sRequest + ") - Positive Response:", sResponse[1].substring(115, 124), "0x00 0x00");
			EvalManStepEqual("the motor current : IMR2 the motor current value at the releasing/Presenting functional point x (" + sRequest + ") - Positive Response:", sResponse[1].substring(125, 134), "0x04 0x56");
			EvalManStepEqual("the motor current : IMR3 the motor current value at the releasing/Presenting functional point x (" + sRequest + ") - Positive Response:", sResponse[1].substring(135, 144), "0x08 0x18");
            EvalManStepEqual("the motor current : IMR4 the motor current value at the releasing/Presenting functional point x (" + sRequest + ") - Positive Response:", sResponse[1].substring(145, 154), "0x1C 0x01");
            EvalManStepEqual("the motor current : IMR4 the motor current value at the releasing/Presenting functional point x (" + sRequest + ") - Positive Response:", sResponse[1].substring(155, 164), "0x1C 0x01");
			EvalManStepEqual("the motor current : IMT1 the motor current value at the tensioning/Design functional point x(" + sRequest + ") - Positive Response:", sResponse[1].substring(165, 174), "0x00 0x00");
			EvalManStepEqual("the motor current : IMT2 the motor current value at the tensioning/Design functional point x(" + sRequest + ") - Positive Response:", sResponse[1].substring(175, 184), "0x03 0x47");
			EvalManStepEqual("the motor current : IMT3 the motor current value at the tensioning/Design functional point x(" + sRequest + ") - Positive Response:", sResponse[1].substring(185, 194), "0x07 0xAC");
			EvalManStepEqual("the motor current : IMT4 the motor current value at the tensioning/Design functional point x(" + sRequest + ") - Positive Response:", sResponse[1].substring(195, 204), "0x14 0x4E");
			EvalManStepEqual("the motor current : IMT5 the motor current value at the tensioning/Design functional point x(" + sRequest + ") - Positive Response:", sResponse[1].substring(205, 214), "0x20 0x98");
            
        }
        else
        {
            /*** Warn the tester that the test isn't executed ****/
            RESULT.InsertComment("Tests isn't executed : confuguration of test failed")
        }
        /*------------------------------------------------------------------------------
                                RESET CONFIGURATION TEST
        ------------------------------------------------------------------------------*/

        /*------------------------------------------------------------------------------
                                DEINITIALIZATION ENVIRONMENT
        ------------------------------------------------------------------------------*/
        RESULT.ExpectTestResult("Close environment test",
            winIDEAWorkspace_closeDiscard(),
            cTEST_OK
        );
    }
    else
    {
        winIDEAWorkspace_closeDiscard();
        RESULT.ExpectTestResult("Test failed about environment initialization failed",
            false,
            true
        );
    }
}
catch(exError)
{
    RESULT.ExpectTestResult("Test failed about exception occurs :"+exError,
        cException_Catched,
        false
    );
    RESULT.ExpectTestResult("Close environment test",
        winIDEAWorkspace_closeDiscard(),
        cTEST_OK
    );
}