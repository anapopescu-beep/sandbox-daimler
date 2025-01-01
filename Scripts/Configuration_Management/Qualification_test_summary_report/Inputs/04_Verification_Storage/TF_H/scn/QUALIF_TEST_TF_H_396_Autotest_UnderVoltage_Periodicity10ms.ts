/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_396_Autotest_UnderVoltage_Periodicity10ms
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_396
Description of the requirement:
- This autotest shall be performed periodically, every 10 ms, only during running autotest phase.
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
 CALL(Config/QUALIF_TESTCFG_TF_H_396_Autotest_UnderVoltage_Periodicity10ms.ts);

 /*------------------------------------------------------------------------------
                                CONSTANTS
 ------------------------------------------------------------------------------*/
const cTEST_OK = true;// Constant for the tests
const cTEST_NOK = false;
const cENV_NON_INITIALIZED = "NO_INIT";// Mandatory constant
const cENV_NOK = false;// Mandatory constant
const cException_Catched = true;// MANDATORY CONSTANT FOR ALL TEST SCRIPTS
var CFGc_NumberOfData = 1;
var numberOfTickInit; 
var numberOfTick;
var periodicity;
var ExperyPoint;
var addressBP1;
var addressBP2;
var bIsBPset: Boolean = false;
var sintBPTimeout: Number = 5000;
var bBreakPointResult: Boolean = false;
/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/

/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Boolean used to check if the test is succesful */
var bRetFunction: Boolean = false;


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
            debugger_run();

            CommentStep("Wait ECU to wake up");
            Wait(5000);

            debugger_stop();

            CommentStep("Place a beakpoint on the tested function")
            bIsBPset = debugger_setBreakPointAtFunction(CFGc_FunctionToTest1);
            RESULT.ExpectTestResult("Set a breakpoint on: " + CFGc_FunctionToTest1,bIsBPset,true);
            RESULT.ExpectTestResult("Run application", debugger_run(), true);
            RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(2000), true);
            
            bBreakPointResult = debugger_isCPUstoppedAtFunction(CFGc_FunctionToTest1)
            RESULT.ExpectTestResult("Debugger stopped on recall of the function " + CFGc_FunctionToTest1 + " ?",
            bBreakPointResult,
            true
            );               
        
            numberOfTickInit = debugger_readMemory(CFGc_NumberCounterAddress, CFGc_NumberOfData, "int");
            
            /* Place a breakpoint on the required function */
            CommentStep("Place a beakpoint on the tested function")
            bIsBPset = debugger_setBreakPointAtFunction(CFGc_FunctionToTest1);
            RESULT.ExpectTestResult("Set a breakpoint on: " + CFGc_FunctionToTest1,bIsBPset,true);

            RESULT.ExpectTestResult("Run application", debugger_run(), true);
            RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(2000), true);

            /* Check if the debugger is stopped on the correct function */
            bBreakPointResult = debugger_isCPUstoppedAtFunction(CFGc_FunctionToTest1)
            RESULT.ExpectTestResult("Debugger stopped on recall of the function " + CFGc_FunctionToTest1 + " ?",
            bBreakPointResult,
            true
            );      

            numberOfTick = debugger_readMemory(CFGc_NumberCounterAddress, CFGc_NumberOfData, "int");
               
            periodicity = (numberOfTick - numberOfTickInit);
            /* The function is called after 10ms (400 000 ticks) */ 
            RESULT.ExpectTestResult("Periodicity : Function called after 10ms ? ",periodicity,CFGc_Periodicity); 

            RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
        
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