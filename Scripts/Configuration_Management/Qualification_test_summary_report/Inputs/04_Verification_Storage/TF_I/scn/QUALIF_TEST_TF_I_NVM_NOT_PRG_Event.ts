/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_I_NVM_NOT_PRG_Event
Result Test:
************************************************************************************************
Requirement under test: DES_TF_I_7165
Description of the requirement: ERR_NVM_NOT_PRG_FAILURE shall be defined as a Counter based AEC.
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
const CFGc_AutotestFunction: String = "NVMIF_cbk_RunEepromMemoryNotProgrammed_Autotest"; // should be configured

const CFGc_ATMSetEventFunction: String = "atm_SetDemEvent";
const CFGc_ATMSetEventFunctionOffset: Number = 96; // should be configured
const CFGc_DemSetEventFunction: String = "Dem_SetEventStatus";
const CFGc_DemSetEventFunctionOffset: Number = 3;

const CFGc_ERHQualifyEventFunction:String = "erh_ManageFailedCounterEvent";
const CFGc_ERHDequalifyEventFunction:String = "erh_ManagePassedCounterEvent";

const CFGc_ERHQualifyEventFunctionOffset:Number = 9;
const CFGc_ERHDequalifyEventFunctionOffset:Number = 7;

const CFGc_DemEventID = 32 // should be configured

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50"; 

/* WinIDEA initialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOff";    /* [RunOn, RunOff] */

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/

/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Boolean used to check if the test is successful */
var bRetFunction: Boolean = false;
/* Variable containing the request */
var sRequest
/* Variable containing the answer */
var sResponse
/* Variable for breakpoint result*/
var bIsBPset
/* Variable for breakpoint timeout */
var sintBPTimeout: Number = 2000;
/* Variable for default wait period */
var sintDefaultWait: Number = 250;
/* Variable for default init period */
var sintWaitInit: Number = 1250;
/* Variable for breakpoint result*/
var bBreakPointResult;
var bWriteVariableResult: Boolean = false;
var bReadVariableResult: Boolean = false;
var iReadVariableValue: Number = 0;
var tRelativeBreakPointParam = [];
var tRelativeBreakPointParam2 = [];
var sBPDescription;
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
      
      CommentStep("Set a BP on the configured function")
      
      bBreakPointResult = debugger_setBreakPointAtFunction(CFGc_AutotestFunction);
      
      RESULT.ExpectTestResult("Set a breakpoint on: " + CFGc_AutotestFunction,
        bBreakPointResult,
        true
      );
      
      CommentStep("Run the debugger")
      
      debugger_run();
      
      Wait(sintWaitInit*5);
       
      CommentStep("Check if the debugger is stopped on the correct function")
      
      debugger_waitUntilStopped(sintWaitInit);
   
      /* Check if the debugger is stopped on the correct function */
     bBreakPointResult = debugger_isCPUstoppedAtFunction(CFGc_AutotestFunction)
     RESULT.ExpectTestResult("Debugger stopped on " + CFGc_AutotestFunction + " ?",
         bBreakPointResult,
         true
     );
   
      CommentStep("Clear all breakpoints");
      RESULT.ExpectTestResult("Delete all breakpoints",
         debugger_deleteAllBreakpoints(),
         true
      );
      
      CommentStep("Set a BP on the configured function")

      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_ATMSetEventFunction, CFGc_ATMSetEventFunctionOffset);
      
      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_ATMSetEventFunction + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_ATMSetEventFunctionOffset
		
      RESULT.InsertComment(sBPDescription)
      
      Wait(sintDefaultWait);
      
      CommentStep("Run the debugger")
      
      debugger_run();
         
      debugger_waitUntilStopped(sintWaitInit);
       
      CommentStep("Check if the debugger is stopped on the correct function")
      
      RESULT.ExpectTestResult(CFGc_ATMSetEventFunction + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);   
      
      ResultStep("true", "true")
      
      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_DemSetEventFunction, CFGc_DemSetEventFunctionOffset);
      
      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_DemSetEventFunction + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_DemSetEventFunctionOffset
      
      RESULT.InsertComment(sBPDescription)
      
      Wait(sintDefaultWait);
      
      CommentStep("Run the debugger")
      
      debugger_run();
      
      debugger_waitUntilStopped(sintWaitInit);
    
      CommentStep("Check if the debugger is stopped on the correct function")
    
      RESULT.ExpectTestResult(CFGc_DemSetEventFunction + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

      ResultStep("true", "true")

      CommentStep("read memory - EventId")
      
      iReadVariableValue = debugger_evaluate("EventId");

      RESULT.ExpectTestResult("Evaluate EventId",
         iReadVariableValue,
         CFGc_DemEventID.toString()
      );
      
      ResultStep("EventId is correctly configured", "EventId is correctly configured")
            
      /* Clear all breakpoints */
      CommentStep("Clear all breakpoints");
      RESULT.ExpectTestResult("Delete all breakpoints",
         debugger_deleteAllBreakpoints(),
         true
      );
            
      CommentStep("Set a BP on the configured function")

      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_ERHQualifyEventFunction, CFGc_ERHQualifyEventFunctionOffset);
      
      tRelativeBreakPointParam2 = debugger_setRelativeFunctionBpAtLine(CFGc_ERHDequalifyEventFunction, CFGc_ERHDequalifyEventFunctionOffset);
      
      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_ERHQualifyEventFunction + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_ERHQualifyEventFunctionOffset
      
      RESULT.InsertComment(sBPDescription)
      
      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_ERHDequalifyEventFunction + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_ERHDequalifyEventFunctionOffset
      
      RESULT.InsertComment(sBPDescription)
      
      Wait(sintDefaultWait);
      
      CommentStep("Run the debugger")
      
      debugger_run();
      
      debugger_waitUntilStopped(sintWaitInit);
    
      CommentStep("Check if the debugger is stopped on the correct function")
    
      if(debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]) == true)
      {
            RESULT.ExpectTestResult(CFGc_ERHQualifyEventFunction + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
            
            CommentStep("read memory - u16AECQualificationThresold")
            
            iReadVariableValue = debugger_evaluate("u16AECQualificationThresold");

            RESULT.LogCustomAction("Read u16AECQualificationThresold", iReadVariableValue, "??", "Passed");
            
            CommentStep("read memory - u16AECDeskillThresold")
            
            iReadVariableValue = debugger_evaluate("u16AECDeskillThresold");
            
            RESULT.LogCustomAction("Read u16AECDeskillThresold", iReadVariableValue, "??", "Passed");

      }
      else if(debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam2[3]) == true)
      {
            RESULT.ExpectTestResult(CFGc_ERHDequalifyEventFunction + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam2[3]), true);
            
            CommentStep("read memory - u16AECDeskillThresold")
            
            iReadVariableValue = debugger_evaluate("u16AECDeskillThresold");
            
            RESULT.LogCustomAction("Read u16AECDeskillThresold", iReadVariableValue, "??", "Passed");
      }
      
      ResultStep("AEC is configured as counter-based", "AEC is configured as counter-based");
            
      /* Clear all breakpoints */
      CommentStep("Clear all breakpoints");
      RESULT.ExpectTestResult("Delete all breakpoints",
         debugger_deleteAllBreakpoints(),
         true
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
}