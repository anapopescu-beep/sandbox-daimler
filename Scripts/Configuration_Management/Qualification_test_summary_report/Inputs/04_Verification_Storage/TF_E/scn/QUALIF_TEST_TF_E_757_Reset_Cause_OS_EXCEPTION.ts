/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_757_Reset_Cause_OS_EXCEPTION
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_E_757
Description of the requirement: ⦁	The value 0x10 shall correspond to the last reset cause: OS EXCEPTION  
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

 /*------------------------------------------------------------------------------
                                CONSTANTS
------------------------------------------------------------------------------*/
const cTEST_OK = true;                                 // Constant for tests returning OK
const cTEST_NOK = false;                               // Constant for tests returning NOK
const cENV_NON_INITIALIZED = "NO_INIT";                // Constant for non initialized environment
const cENV_NOK = false;                                // Mandatory constant
const cException_Catched = true;                       // Mandatory constant

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50"; 

/* WinIDEA initialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */

const iSupplierSecurityLevel = 0x61;
/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
/* Variable used to check the test initialization phase */
var vRetFunction = null; 

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
   
   if(vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK)
   {
      /*------------------------------------------------------------------------------
                                      CONFIGURATION TEST
      ------------------------------------------------------------------------------*/
      CommentStep("Let ECU wakeup");
      Wait(2250);

      /*------------------------------------------------------------------------------
                                      EXECUTION TEST
      ------------------------------------------------------------------------------*/
      CommentStep("Clear all breakpoints");
      RESULT.ExpectTestResult("Delete all breakpoints",
         debugger_deleteAllBreakpoints(),
         true
      );
      
      debugger_stop();

      /* Set Reset Cause into the RCM to ECC E2P */
      EvalManStepEqual("Write reset Value",debugger_writeVariable("rcm_u32ResetCause","uint32","00000400",0),true);

      debugger_run()

      /* Entering Supplier session */                
      sRequest ="0x10 0x7E"
      sResponse = CAN.SendDiagByValues(sRequest);
      EvalManStepEqual("Enter in supplier session (" + sRequest + ") - Positive Response:", sResponse[1], "0x50 0x7E 0x00 0x64 0x01 0xF4")

      /*Security Access */
      sRequest ="0x27 0x61 and 0x27 0x62"
      sResponse = CAN.SecurityAccess(0x61)
      EvalManStepEqual("Get Security Access (" + sRequest + ") - Positive Response:", sResponse[1], "0x67 0x62")

      /*Unlock the ECU */
      sRequest = "0x31 0x01 0xF7 0x81"
      sResponse = CAN.SendDiagByValues(sRequest);
      EvalManStepEqual("Unlock the ECU: (" + sRequest + ") - Positive Response:", sResponse[1], "0x71 0x01 0xF7 0x81 0xFF")
      RESULT.InsertComment(" ");

      Wait(1000)

      sRequest = "0x22 0xFD 0x08"
      sResponse = CAN.SendDiagByValues(sRequest);
      EvalManStepEqual("Read Last ECU Reset Cause",sResponse[1],"0x62 0xFD 0x08 0x10")

      /*------------------------------------------------------------------------------
                                      RESET CONFIGURATION TEST
      ------------------------------------------------------------------------------*/

      /*------------------------------------------------------------------------------
                                      DEINITIALIZATION ENVIRONMENT
      ------------------------------------------------------------------------------*/
      // "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger). This function is mandatory
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