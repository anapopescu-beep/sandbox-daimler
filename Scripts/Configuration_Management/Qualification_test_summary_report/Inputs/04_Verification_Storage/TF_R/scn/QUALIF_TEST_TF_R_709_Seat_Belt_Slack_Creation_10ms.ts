/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_R_709_Seat_Belt_Slack_Creation_10ms
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_R_709
Description of the requirement: 
ALV_EXT_TF_R_709: This technical function will be executed every 10ms.
************************************************************************************************
Equipment: PP4G Mockup + iSYSTEM IC5000 + power supply + CAN case
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
const cTest_NOK = false;

/* Mandatory constants for test scripts */
const cENV_NON_INITIALIZED = "NO_INIT";
const cENV_NOK = false;
const cException_Catched = true;

/* WinIDEA intialization options */
const CFGc_FlashMode: String = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String = "RunOn";    /* [RunOn, RunOff] */

/* Delay to let ECU wakeup */
const CFGc_WakeupDelay = 5000;

/* Function name used to place a breakpoint */
const CFGc_FunctionToTest: String = "BSR_runBeltSlackReductionAlgo";

/* offset Breakpoint */
const sintOffsetBP1: Number = 0;

/* get variable address */
const CFGc_VariableAddress: String = "OS_counterDynamic_core0";

/* number of OS tick */
const CFGc_NumberOfData = 1;
const CFGc_Periodicity = 10;

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/

/* Variable used to check the test initialization phase */
var vRetFunction = null;

/* Boolean used to check if the test configuration is succesful */
var bRetFunction: Boolean = false;

var addressBP1;
var index;
var sintAddressVariable;
var numberOfTickInit;
var numberOfTick;
var periodicity;

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
   /**** This function is parametrable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/

   /****** WARNING : check optionnal parameter of the next function :it's very IMPORTANT ***********/
   vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOn", "RunOn", "5");
   if (vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK)
   {

      /*------------------------------------------------------------------------------
                                 CONFIGURATION TEST
      ------------------------------------------------------------------------------*/

         /* Wait until ECU is up running */
         CommentStep(" ***| Let ECU wakeup |*** ");
         Wait(CFGc_WakeupDelay);

         /* Configure test */
         bRetFunction = true;

      /*------------------------------------------------------------------------------
                                 EXECUTION TEST
      ------------------------------------------------------------------------------*/
      if (cTEST_OK == bRetFunction) 
      {
         CommentStep(" ***| START OF TEST |*** ");
         RESULT.InsertComment(" ");

         for (index = 0; index < 3; index++)
         {
            CommentStep(">>>>>>>>>>> Call of the function " + CFGc_FunctionToTest + " n°" + index + "<<<<<<<<<<<<<<<<")
            /* Set a breakpoint in the tested function */
            addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest, sintOffsetBP1)[3]
            RESULT.ExpectTestResult("Run application", debugger_run(), true);
            RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(CFGc_WakeupDelay), true);
            RESULT.ExpectTestResult("The function " + CFGc_FunctionToTest + " is reached", debugger_isCPUStoppedAtAddress(addressBP1), true);

            sintAddressVariable = debugger_getVariableAddress(CFGc_VariableAddress);

            numberOfTickInit = debugger_readMemory((sintAddressVariable + 12), CFGc_NumberOfData, "int"); 

            RESULT.ExpectTestResult("Run application", debugger_run(), true);
            RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(CFGc_WakeupDelay), true);

            numberOfTick = debugger_readMemory((sintAddressVariable + 12), CFGc_NumberOfData, "int"); 

            periodicity = (numberOfTick - numberOfTickInit);
            /* The function is called after 10ms (400 000 ticks) */
            RESULT.ExpectTestResult("Periodicity of measurement : Function called after 10ms ? ", periodicity, CFGc_Periodicity);

            RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);

         }   
      }
      else 
      {
         /* Warn the tester that the test isn't executed */
         RESULT.ExpectTestResult("Tests isn't executed : configuration NOK", false, cTEST_OK);
      }

      /*------------------------------------------------------------------------------
                              RESET CONFIGURATION TEST
      ------------------------------------------------------------------------------*/
      bRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOn", "RunOn", "5");
      // this check is mandatory to verify the configuration of test
      RESULT.ExpectTestResult("Reset Configuration Test ", bRetFunction, cTEST_OK);

      /*------------------------------------------------------------------------------
                              DEINITIALIZATION ENVIRONMENT
      ------------------------------------------------------------------------------*/
      // "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger). This function is mandatory
      // RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
   }
   else 
   {
      winIDEAWorkspace_closeDiscard();
      RESULT.ExpectTestResult("Test failed about environment initialization failed", false, true);
   }

   // CAN.StopLoggingToFile(); ?? don't work

   CommentStep(" ***| END OF TEST |*** ");
}
catch (exError) 
{
   RESULT.ExpectTestResult("Test failed about exception occurs :" + exError, cException_Catched, false);
   RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}