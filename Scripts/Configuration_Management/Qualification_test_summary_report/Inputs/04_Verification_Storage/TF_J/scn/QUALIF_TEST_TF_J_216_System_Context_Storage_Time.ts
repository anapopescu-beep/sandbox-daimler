/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_J_216_System_Context_Storage_Time
Result Test:
************************************************************************************************
Requirement under test: TR6_EXT_TF_J_216 
Description of the requirement: In case of battery loss, system context recording shall be completed in less than 2.6 ms (Energy reserve worst case calculation - see E704929).
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

/* Function name used to place a breakpoint */
const CFGc_CallingFunctionToTest: String = "scm_ManageSystemContextStorage";
const CFGc_CalledFunctionToTest: String = "SCM_StoreSystemContext";
const CFGc_CalledFunctionToTest_Offset: Number = 66;
const CFGc_CallingFunctionToTest_Offset: Number = 96;

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50"; 

/* WinIDEA initialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";   /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */

/* AEC Specific variables */
const iKL30OvervoltageValue = 18;
const iKL30DefaultVoltageValue = 12;

const iKL30SystemContextStorageVoltageValue = 7.8;

/*number of OS tick */ 
var CFGc_OSCounterVariable = "OS_counterDynamic_core0"; /* HW Timer; 40Mhz */
var CFGc_NumberOfData = 1;
var CFGc_iMaxDuration = 0.6; /* 2ms worst case until decision to write System Context is taken + 0.6ms */

var tRelativeBreakPointParam;
var sBPDescription;

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Boolean used to check if the test is succesful */
var bRetFunction: Boolean = false;

/* Test variables */
var sintBPTimeout: Number = 2000;
/* Variable for default wait period */
var sintDefaultWait: Number = 250;
/* Variable for default init period */
var sintWaitInit: Number = 2250;

var numberOfTickInit; 
var numberOfTick;
var fDuration: float;

/*------------------------------------------------------------------------------
                                    Core Test
------------------------------------------------------------------------------*/
 
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
                              EXECUTION TEST
      ------------------------------------------------------------------------------*/
      CommentStep("Clear all breakpoints");
      RESULT.ExpectTestResult("Delete all breakpoints",
         debugger_deleteAllBreakpoints(),
         true
      );
      
      CommentStep("Run the debugger")
      debugger_run();

      CommentStep("Ensure normal run operation")
      Wait(sintWaitInit*2);
            
      /* Place a breakpoint on the required function */
      CommentStep("Place a beakpoint on the tested function")
      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_CallingFunctionToTest, CFGc_CallingFunctionToTest_Offset);

      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_CallingFunctionToTest + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_CallingFunctionToTest_Offset
      
      RESULT.InsertComment(sBPDescription);      
      
      CommentStep("Set KL30 under 8V to trigger System Context Storage")
      SwDevLib_PS1_SetVoltage(iKL30SystemContextStorageVoltageValue);

      CommentStep("Check if the debugger is stopped on the correct function")
      
      Wait(sintWaitInit);
    
      RESULT.ExpectTestResult(CFGc_CallingFunctionToTest + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
      
      ResultStep("Debugger stopped on the correct function", "Debugger stopped on the correct function");
      
      CommentStep("Read the OS HW counter")
      numberOfTickInit = debugger_readVariable(CFGc_OSCounterVariable, "uint32", 0, "dec");

      /* Clear all breakpoints */
      CommentStep("Clear all breakpoints");
      RESULT.ExpectTestResult("Delete all breakpoints",
      debugger_deleteAllBreakpoints(),
      true
      );
            
       /* Place a breakpoint on the required function */
      CommentStep("Place a breakpoint on the tested function")
      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_CalledFunctionToTest, CFGc_CalledFunctionToTest_Offset);
      
      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_CalledFunctionToTest + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_CalledFunctionToTest_Offset
   
      RESULT.InsertComment(sBPDescription);      
      
      CommentStep("Run the debugger")
      debugger_run();
      
      debugger_waitWhileRunning(sintBPTimeout);

      CommentStep("Check if the debugger is stopped on the correct function")
    
      RESULT.ExpectTestResult(CFGc_CalledFunctionToTest + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

      CommentStep("Get CPU call trace")
      
      var stackTrace = debugger_GetStackTrace(2);
      RESULT.ExpectTestResult("Check that the top level of the call trace is the expected function",
         stackTrace[1].getFunction().getName(),
         CFGc_CallingFunctionToTest
      );

      CommentStep("Read the OS HW counter")
      numberOfTick = debugger_readVariable(CFGc_OSCounterVariable, "uint32", 0, "dec")
               
      CommentStep("Calculate duration until BP was hit")
      fDuration = (numberOfTick - numberOfTickInit)*25/1000000; // 40Mhz and convert from ns to ms
      
      if(fDuration <= CFGc_iMaxDuration)
      {
          RESULT.LogCustomAction("Time to hit BP is less than " + CFGc_iMaxDuration + " ms", fDuration + " ms", CFGc_iMaxDuration + " ms", "Passed") 
      }
      else
      {
          RESULT.LogCustomAction("Time to hit BP is less than " + CFGc_iMaxDuration + " ms", fDuration + " ms", CFGc_iMaxDuration + " ms", "Failed") 
      }
      
      ResultStep("Time to hit BP is within limits", "Time to hit BP is within limits");
      
      /*** Check result of test ****/
      RESULT.ExpectTestResult("Global Verification of test",
      bRetFunction,
      cTEST_OK
      );

      /*------------------------------------------------------------------------------
                              DEINITIALIZATION ENVIRONMENT
      ------------------------------------------------------------------------------*/
      RESULT.ExpectTestResult("Reset the debugger",
         debugger_reset(),
         cTEST_OK
      );

      /* "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger). This function is mandatory */
      RESULT.ExpectTestResult("Close environment test",
         winIDEAWorkspace_closeDiscard(),
         cTEST_OK
      );
      
      CommentStep("Set normal voltage conditions")
      SwDevLib_PS1_SetVoltage(iKL30DefaultVoltageValue);
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

   CommentStep("Close test environment");
   RESULT.ExpectTestResult("Close environment test",
      winIDEAWorkspace_closeDiscard(),
      cTEST_OK
   );
   
   CommentStep("Set normal voltage conditions")
   SwDevLib_PS1_SetVoltage(iKL30DefaultVoltageValue);
   
}