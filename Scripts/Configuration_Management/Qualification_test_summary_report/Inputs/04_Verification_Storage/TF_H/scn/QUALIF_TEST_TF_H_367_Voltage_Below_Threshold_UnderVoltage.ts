/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_367_Voltage_Below_Threshold_UnderVoltage
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_367
Description of the requirement:
- The Voltage threshold below which the [KL30_Vlevel] shall be considered in Under-Voltage [NVP_u16UnderKL30QualificationThrs]
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
 CALL(/../../ProjectLib_Development/SBE_Configuration.ts);
 CALL(/../../ProjectLib_Development/INTEG_LIB/PP4G_LIB_INTEG_OS.ts);

 /*------------------------------------------------------------------------------
                                CONSTANTS
 ------------------------------------------------------------------------------*/
const cTEST_OK = true;// Constant for the tests
const cTEST_NOK = false;
const cENV_NON_INITIALIZED = "NO_INIT";// Mandatory constant
const cENV_NOK = false;// Mandatory constant
const cException_Catched = true;// MANDATORY CONSTANT FOR ALL TEST SCRIPTS

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
/* Boolean used to check if the test is succesful */
var bRetFunction: Boolean = false;
/* Variable containing the request */
var sRequest
/* Variable containing the answer */
var sResponse

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
   /**** This function is parameterizable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/

   /****** WARNING : check optional parameter of the next function :it's very IMPORTANT ***********/
   CommentStep("Initialize environment");
   vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply(CFGc_FlashMode, CFGc_ResetMode, CFGc_RunMode, CFGc_MinCurrentToRunTest);

   /****** WARNING : check optionnal parameter of the next function :it's very IMPORTANT ***********/
   PS.Write(_sPS1Name, "CH 1");
   RESULT.ExpectTestResult("Set the KL30 to 11.9V" , PS.SetVoltage(_sPS1Name, 11.9)[0],"0000");

   Wait(5000);
   /*Entering Supplier session */     
   sRequest ="0x10 0x7E"
   sResponse = CAN.SendDiagByValues(sRequest);
   EvalManStepEqual("Enter in supplier session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x7E 0x00 0x64 0x01 0xF4")

   /* Enter supplier session */
   sRequest ="0x22 0xFE 0x00";
   sResponse = CAN.SendDiagByValues("0x22 0xFE 0x00")[1].Split(' ');

   /* Parse table */
   var j = 3;
   do
   {
     if (j == 93)
     {
       RESULT.ExpectTestResult("Under Voltage status is OK",
       sResponse[j + 2],
       "0x00");
     }   
    
     j += 1;
   } while (j < 94);

   CommentStep("Wait ECU to wake up");
   Wait(7000);
   CommentStep("Qualification Under Voltage");
   RESULT.ExpectTestResult("Set the KL30 to 8,4V" , PS.SetVoltage(_sPS1Name, 8.4)[0],"0000");
   Wait(7000);
 
   /*Entering Supplier session */     
   sRequest ="0x10 0x7E"
   sResponse = CAN.SendDiagByValues(sRequest);
   EvalManStepEqual("Enter in supplier session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x7E 0x00 0x64 0x01 0xF4")

   /* Enter supplier session */
   sRequest ="0x22 0xFE 0x00";
   sResponse = CAN.SendDiagByValues("0x22 0xFE 0x00")[1].Split(' ');

   /* Parse table */
   var j = 3;
   do
   {
       if (j == 93)
       {
          RESULT.ExpectTestResult("Under Voltage is qualified",
          sResponse[j + 2],
          "0x27");
       }   
     
     j += 1;
   } while (j < 94);

   RESULT.ExpectTestResult("Set the KL30 to 11.9V" , PS.SetVoltage(_sPS1Name, 11.9)[0],"0000");
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