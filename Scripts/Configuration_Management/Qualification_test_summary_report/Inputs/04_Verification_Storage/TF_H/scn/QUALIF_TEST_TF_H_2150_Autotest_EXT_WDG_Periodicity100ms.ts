/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_2150_Autotest_EXT_WDG_Periodicity100ms
Result Test:
************************************************************************************************
Requirement under test: TR6_EXT_TF_H_2150
Description of the requirement:
- This autotest shall be performed periodically, every 100 ms, since the running autotest phase
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

/* Function name used to place a breakpoint */
const CFGc_FunctionToTest1: String = "RCM_Autotest_RunExtWDTest";

/* offset Breakpoint */
var sintOffsetBP1: Number = 0;

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "5"; 

/* WinIDEA intialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */

/*number of OS tick */ 
const CFGc_OSCounterVariable = "OS_counterDynamic_core0"; /* HW Timer; 40Mhz */
var sintPeriodicity;
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

            /* Set a breakpoint in the function RCM_Autotest_RunExtWDTest */
            addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1, sintOffsetBP1)[3] 
            RESULT.ExpectTestResult("Run application", debugger_run(), true);
            RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(2000), true);
            RESULT.ExpectTestResult("The function "+CFGc_FunctionToTest1+" is reached", debugger_isCPUStoppedAtAddress(addressBP1), true);
          
            numberOfTickInit = debugger_readVariable(CFGc_OSCounterVariable, "uint32", 0, "dec");
            
            RESULT.ExpectTestResult("Run application", debugger_run(), true);
            RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(2000), true);

            /* Check if the debugger is stopped on the correct function */
            RESULT.ExpectTestResult("The function"+CFGc_FunctionToTest1+" is reached", debugger_isCPUStoppedAtAddress(addressBP1), true);
  
            numberOfTick = debugger_readVariable(CFGc_OSCounterVariable, "uint32", 0, "dec");
               
			CommentStep("Calculate duration until BP was hit")
			sintPeriodicity = (numberOfTick - numberOfTickInit)*25/1000000; // 40Mhz and convert from to us
			sintPeriodicity = Math.round(sintPeriodicity)
      
			CommentStep("Check if periodicity of CIL_runCantoAppli() is correct. ")
			RESULT.ExpectTestResult("Check sintPeriodicity", sintPeriodicity, 100);
			ResultStep("Function periodicity is correct", "Function periodicity is correct");

            RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
        
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