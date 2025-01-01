/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_140_Positive_Response
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_E_140
Description of the requirement:
- By default, this mode shall be initialized at activated status.
- This mode shall be activated if one critical autotest fails at least once. This mode shall stay activated until next software reset.

************************************************************************************************
Equipment: PowerSupply, CanCaseXL, MockUp, IC5000 debugger
Test Notes: 
Full Automation: Yes
Global Result Assignment: Neeva
************************************************************************************************/
/********************************************************************************/
/*                             Format test script                               */
/********************************************************************************/
/*------------------------------------------------------------------------------
                                IMPORT LIBRARY
 ------------------------------------------------------------------------------*/
/* Import SBE library */
CALL(/../../ProjectLib_Development/SBE_Configuration.ts)
CALL(/../../ProjectLib_Development/INTEG_LIB/PP4G_LIB_INTEG_DIA.ts)

 /*------------------------------------------------------------------------------
                                CONSTANTS
 ------------------------------------------------------------------------------*/
const cTEST_OK = true;											// Constant for tests returning OK
const cTEST_NOK = false;										// Constant for tests returning NOK
const cENV_NON_INITIALIZED = "NO_INIT";							// Constant for non initialized environment
const cENV_NOK = false;											// Mandatory constant
const cException_Catched = true;								// Mandatory constant

/* WinIDEA initialization options */
const CFGc_FlashMode: String  = "FlashOn";   					// [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";  					// [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    					// [RunOn, RunOff] */
const CFGc_MinCurrentToRunTest: String = "50"; 					// 50 means that a power supply which can support 40A shall be used
/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/

var vRetFunction = null;          								// Variable used to check the test initialization phase
var bRetFunction: Boolean = false;								// Boolean used to check if the test is successful
var sRequest													// Variable containing the request
var sResponse													// Variable containing the answer

/*------------------------------------------------------------------------------
                                    Core Test
------------------------------------------------------------------------------*/

try
{
   /*------------------------------------------------------------------------------
                           INITIALIZATION ENVIRONMENT
   ------------------------------------------------------------------------------*/
   /**** This function is parametrable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/

   /****** WARNING : check optionnal parameter of the next function :it's very IMPORTANT ***********/
   vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply(CFGc_FlashMode, CFGc_ResetMode, CFGc_RunMode, CFGc_MinCurrentToRunTest);
   if(vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK)
   {
		  /*------------------------------------------------------------------------------
									 EXECUTION TEST
		  ------------------------------------------------------------------------------*/
		CommentStep("Let ECU wakeup");
		Wait(10000);

		sRequest = "0x14 0xff 0xff 0xff"
		sResponse = CAN.SendDiagByValues(sRequest);
		EvalManStepEqual("Reset performed (" + sRequest + ") - Positive Response:", sResponse[1], "0x54");

		Wait (500)

		sRequest = "0x14 0xff 0xff 0xff"
		sResponse = CAN.SendDiagByValues(sRequest);
		EvalManStepEqual("Reset performed (" + sRequest + ") - Positive Response:", sResponse[1], "0x54");
	
	}
	else
	{
		winIDEAWorkspace_closeDiscard();
	}
}
catch(exError)
{
	RESULT.ExpectTestResult("Test failed about exception occurs :"+exError, cException_Catched, false);

	RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}