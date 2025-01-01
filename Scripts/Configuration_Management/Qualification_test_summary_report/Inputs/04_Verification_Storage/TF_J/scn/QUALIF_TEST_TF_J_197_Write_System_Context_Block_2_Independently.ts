/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_J_197_Write_System_Context_Block_2_Independently
Result Test:
************************************************************************************************
Requirement under test: TR6_EXT_TF_J_197
Description of the requirement: Constraints: Each system context block shall be writable independently from other system context blocks.
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
const CFGc_FunctionToTest1: String = "SCM_runManageSystemContext";
const CFGc_FunctionOffsetToTest1: Number = 2;
const CFGc_FunctionToTest2: String = "scm_ManageSystemContextStorage";
const CFGc_FunctionOffsetToTest2: Number = 89;
const CFGc_FunctionToTest3: String = "SCM_StoreSystemContext";
const CFGc_FunctionOffsetToTest3: Number = 6;
const CFGc_FunctionOffsetToTest4: Number = 28;

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
var sintWaitInit: Number = 750;
/* Variable for breakpoint result*/
var bBreakPointResult;
var bWriteVariableResult: Boolean = false;
var bReadVariableResult: Boolean = false;
var iReadVariableValue: Number = 0;
var tRelativeBreakPointParam = [];
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
      
      CommentStep("Run the debugger to allow SCM reallocation")
      
      debugger_run();
      
      Wait(5000);

      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1, CFGc_FunctionOffsetToTest1);
      
      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest1 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest1
		
      RESULT.InsertComment(sBPDescription)
      
      Wait(sintDefaultWait);
      
      CommentStep("Run the debugger")
      
      debugger_run();
      
      Wait(sintWaitInit);
      
      CommentStep("Check if the debugger is stopped on the correct function")
    
      RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

      ResultStep("true", "true")
            
      CommentStep("write memory - SCM_bIsSystemContextStorageRequested set to B_TRUE in order to trigger system context storage")
         
      bWriteVariableResult = debugger_modify("SCM_bIsSystemContextStorageRequested", 170) // 0xAA
      
      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2, CFGc_FunctionOffsetToTest2);
      
      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest2 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest2
      
      RESULT.InsertComment(sBPDescription)
      
      Wait(sintDefaultWait);
      
      CommentStep("Run the debugger")
      
      debugger_run();
      
      Wait(sintDefaultWait);
      
      CommentStep("Check if the debugger is stopped on the correct function")
 
      RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

      ResultStep("true", "true")
      
      CommentStep("write memory - u32DelaySystemContextStorage set to 5s")
   
      bWriteVariableResult = debugger_modify("u32DelaySystemContextStorage", 5) 
      
      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest3, CFGc_FunctionOffsetToTest3);
      
      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest3 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest3
      
      RESULT.InsertComment(sBPDescription)
      
      Wait(sintDefaultWait);
      
      CommentStep("Run the debugger")

      debugger_run();
      
      Wait(sintDefaultWait);
      
      CommentStep("Check if the debugger is stopped on the correct function")

      RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
      
      CommentStep("write memory - scm_u8IndexCurrentSystemContext set to 2")
      
      bWriteVariableResult = debugger_modify("scm_u8IndexCurrentSystemContext", 2) 
      
      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest3, CFGc_FunctionOffsetToTest4);
      
      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest3 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest4
      
      RESULT.InsertComment(sBPDescription)
      
      Wait(sintDefaultWait);
      
      CommentStep("Run the debugger")
       
      debugger_run();

      Wait(sintDefaultWait);
      
      CommentStep("Check if the debugger is stopped on the correct function")
 
      RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

      ResultStep("true", "true")
      
      ResultStep("Block 2 can be written independently", "Block 2 can be written independently")
      
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