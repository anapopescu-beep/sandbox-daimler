/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_G_783_FromDiagnosticToIdle_Mode
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_G_783
Description of the requirement:
IF all HW critical autotests have been executed successfully 
THEN the application swithes to the Idle mode.
ENDIF

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
const cTEST_OK = true;// Constant for the tests
const cTEST_NOK = false;
const cENV_NON_INITIALIZED = "NO_INIT";// Mandatory constant
const cENV_NOK = false;// Mandatory constant
const cException_Catched = true;// MANDATORY CONSTANT FOR ALL TEST SCRIPTS


/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50"; 

/* WinIDEA intialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResethOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */



const cNameFunction1: String = "PAL_runMainFunction";
const cNameFunction2: String = "MIC_Autotest_RunRamMemoryCorruption";


/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/


/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Boolean used to check if the test is succesful */
var bRetFunction: Boolean = false;
var addressBP1;
var addressBP2;
var addressBP3;
var addressBP4;
var addressBP5;
var stackTrace;

var sintOffsetBP1: Number = 0;
var sintOffsetBP2: Number = 37; //  if (KU8_MODE_STATUS_OFF == bModeStatus)
var sintOffsetBP3: Number = 40; //  pal_u8ModeState = PAL_KU8_IDLE_MODE_STATE
var sintOffsetBP4: Number = 31; // KU8_ATM_TEST_OK

var temp_init;
var temp;  

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
   vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOff", "RunOff", "5");
   if(vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK)
   {
      /*------------------------------------------------------------------------------
                                 EXECUTION TEST
      ------------------------------------------------------------------------------*/
      debugger_AttachFunctionDisable();

      RESULT.ExpectTestResult("Delete all breakpoints", debugger_deleteAllBreakpoints(), true);
      addressBP1 = debugger_setRelativeFunctionBpAtLine(cNameFunction1, sintOffsetBP1);
      RESULT.ExpectTestResult("Run application", debugger_run(), true);
      RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
      RESULT.ExpectTestResult(cNameFunction1+" function is reached", debugger_isCPUstoppedAtFunction(cNameFunction1), true);

      RESULT.ExpectTestResult("Delete all breakpoints", debugger_deleteAllBreakpoints(), true);
      addressBP2 = debugger_setRelativeFunctionBpAtLine(cNameFunction1, sintOffsetBP2);
      RESULT.ExpectTestResult("Run application", debugger_run(), true);
      RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
      stackTrace = debugger_GetStackTrace(2);
      MessageBox.Show("Change the value bModeStatus of to 85");
	  
	  MessageBox.Show("Do a step");
	  CommentStep("Reach pal_u8ModeState");
	  var resultMessageBox = MessageBox.Show("pal_u8ModeState = PAL_KU8_IDLE_MODE_STATE reached ??", "yes/No", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
      RESULT.InsertComment(resultMessageBox);
	  
	  MessageBox.Show("Do a step");
	  CommentStep("Read pal_u8ModeState");
	  var resultMessageBox = MessageBox.Show("pal_u8ModeState = 2 ??", "yes/No", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
      RESULT.InsertComment(resultMessageBox);
	  
	  if (resultMessageBox == 7)
	  {
		  RESULT.ExpectTestResult("pal_u8ModeState is not set to 2",6,7);		
	  }	
	  else 
	  {
		  RESULT.ExpectTestResult("pal_u8ModeState is et to 2",6,6);   	
	  }
	  
	  RESULT.ExpectTestResult("Delete all breakpoints", debugger_deleteAllBreakpoints(), true);

      /*------------------------------------------------------------------------------
                              DEINITIALIZATION ENVIRONMENT
      ------------------------------------------------------------------------------*/
      
      RESULT.ExpectTestResult("Reset the debugger",
         debugger_reset(),
         cTEST_OK
      );

        // "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger). This function is mandatory
    /*     RESULT.ExpectTestResult("Close environment test",
         winIDEAWorkspace_closeDiscard(),
         cTEST_OK
      );*/
      
    }
   else
   {
  //    winIDEAWorkspace_closeDiscard();
   }
}
catch(exError)
{
   RESULT.ExpectTestResult("Test failed about exception occurs :"+exError,
      cException_Catched,
      false
   );

/*   RESULT.ExpectTestResult("Close environment test",
      winIDEAWorkspace_closeDiscard(),
      cTEST_OK
   );*/
}