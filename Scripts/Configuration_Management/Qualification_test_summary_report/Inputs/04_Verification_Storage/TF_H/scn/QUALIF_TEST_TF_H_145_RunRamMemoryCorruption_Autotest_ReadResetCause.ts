/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_145_RunRamMemoryCorruption_Autotest_ReadResetCause
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_145 
Description of the requirement:
For the Ram Memory Corruption autotest, the reset cause shall be read

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

const cNameFunction1: String = "MIC_cbk_RunRamMemoryCorruption_Autotest";
const cNameFunction2: String = "MIC_Autotest_RunRamMemoryCorruption";
const cNameFunction3: String = "RCM_runGetResetCause";

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
var stackTrace;

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
      RESULT.ExpectTestResult("Delete all breakpoints", debugger_deleteAllBreakpoints(), true);
      addressBP1 = debugger_setBreakPointAtFunction(cNameFunction1);
      RESULT.ExpectTestResult("Run application", debugger_run(), true);
      RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
      RESULT.ExpectTestResult(cNameFunction1+" function is reached", debugger_isCPUstoppedAtFunction(cNameFunction1), true);



      RESULT.ExpectTestResult("Delete all breakpoints", debugger_deleteAllBreakpoints(), true);
      addressBP2 = debugger_setBreakPointAtFunction(cNameFunction2);
      RESULT.ExpectTestResult("Run application", debugger_run(), true);
      RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
      RESULT.ExpectTestResult(cNameFunction2+" function is reached", debugger_isCPUstoppedAtFunction(cNameFunction2), true);
      /* Get CPU call stack */
      //CommentStep("Get CPU call trace")
      stackTrace = debugger_GetStackTrace(2);
      RESULT.ExpectTestResult("Check that the top level of the call trace is the expected function", stackTrace[1].getFunction().getName(), cNameFunction1);


      RESULT.ExpectTestResult("Delete all breakpoints", debugger_deleteAllBreakpoints(), true);
      addressBP3 = debugger_setBreakPointAtFunction(cNameFunction3);
      RESULT.ExpectTestResult("Run application", debugger_run(), true);
      RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
      RESULT.ExpectTestResult(cNameFunction3+" function is reached", debugger_isCPUstoppedAtFunction(cNameFunction3), true);
      /* Get CPU call stack */
      //CommentStep("Get CPU call trace")
      stackTrace = debugger_GetStackTrace(2);
      RESULT.ExpectTestResult("Check that the top level of the call trace is the expected function", stackTrace[1].getFunction().getName(), cNameFunction2);

      RESULT.ExpectTestResult("The reset cause value is",debugger_readVariable("rcm_u32ResetCause", "uint32", 0, "int"), 1);

      /*------------------------------------------------------------------------------
                              DEINITIALIZATION ENVIRONMENT
      ------------------------------------------------------------------------------*/
      RESULT.ExpectTestResult("Reset the debugger",
         debugger_reset(),
         cTEST_OK
      );

        // "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger). This function is mandatory
         RESULT.ExpectTestResult("Close environment test",
         winIDEAWorkspace_closeDiscard(),
         cTEST_OK
      );
    }
   else
   {
      winIDEAWorkspace_closeDiscard();
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