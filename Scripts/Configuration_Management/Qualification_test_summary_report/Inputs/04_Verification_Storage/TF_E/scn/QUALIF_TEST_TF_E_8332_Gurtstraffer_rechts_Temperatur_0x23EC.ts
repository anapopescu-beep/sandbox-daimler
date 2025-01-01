/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_E_8332_Gurtstraffer_rechts_Temperatur_0x23EC
Result Test:
************************************************************************************************
Requirement under test: TR6_EXT_TF_E_8332
Description of the requirement: TR6_EXT_TF_E_8111: "DB1" DataByte1 shall be equal 0xFC, if the temperature of RGS_L is < -40°C
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
const CFGc_FunctionToTest: String = "DIA_runDid23EC_ECUTemperatureRightRead";
const CFGc_FunctionOffsetToTest1: Number = 15;
const CFGc_FunctionOffsetToTest2: Number = 17;

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

      CommentStep("Soft Reset");
      sendCANDiagRequest("Soft Reset", sReq_SwReset, sAns_SwReset);
      Thread.Sleep(sintWaitInit*3);
      
      CommentStep("Enter supplier session");
      sendCANDiagRequest("Enter supplier session", sReq_SupplierSession, sAns_SupplierSession);
      Thread.Sleep(sintDefaultWait);
      
      CommentStep("Issue supplier security level");
      requestCANSecurityAccess(iSupplierSecurityLevel);
      Thread.Sleep(sintDefaultWait);
      
      CommentStep("Unlocking ECU");
      sendCANDiagRequest("Unlocking ECU", sReq_UnlockECU, sAns_UnlockECU);
      Thread.Sleep(sintDefaultWait);
      
      CommentStep("Change side allocation");
      sendCANDiagRequest("Change side allocation", "0x2E 0xFD 0x2F 0x99", "0x6E 0xFD 0x2F");
      Thread.Sleep(sintDefaultWait);

      CommentStep("Lock ECU");
      sendCANDiagRequest("Lock ECU", sReq_LockECU, sAns_LockECU);
      Thread.Sleep(sintDefaultWait);
      
      CommentStep("Soft Reset");
      sendCANDiagRequest("Soft Reset", sReq_SwReset, sAns_SwReset);
      Thread.Sleep(sintWaitInit*3);
   
      debugger_reset();

      CommentStep("Run the debugger")

      debugger_run();

      RESULT.InsertComment(CAN.SetDiagnosticAdressingMode(CAN.ActiveChannel,_iDiagRequestFrameIdFR,_iDiagResponseFrameIdFR) );

      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest, CFGc_FunctionOffsetToTest1);
      
      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest1
		
      CommentStep(sBPDescription)
      
      Wait(sintDefaultWait);
      
      CommentStep("Run the debugger")
      
      debugger_run();
      Wait(sintWaitInit);
    
      CommentStep("Read DID 0x23EC");
      sendCANDiagRequest("Read DID 0x23EC", "0x22 0x23 0xEC", "TIMEOUT");
      Thread.Sleep(sintDefaultWait);
      
      Wait(sintWaitInit);
    
      CommentStep("Check if the debugger is stopped on the correct function")
    
      RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

      ResultStep("true", "true")

      CommentStep("write memory - s16Temperature_Deg set to -45*C")
         
      bWriteVariableResult = debugger_modify("s16Temperature_Deg", -45) 
      
      if (true == bWriteVariableResult)
      {
         CommentStep("read memory - s16Temperature_Deg")
         
         iReadVariableValue = debugger_evaluate("s16Temperature_Deg");

         RESULT.ExpectTestResult("Evaluate s16Temperature_Deg ",
            iReadVariableValue,
            "-45" 
         );
         
         ResultStep("s16Temperature_Deg - -45*C", "s16Temperature_Deg - -45*C")
         
         Thread.Sleep(sintDefaultWait);
         
         tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest, CFGc_FunctionOffsetToTest2);
         
         sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest1
		 
         CommentStep(sBPDescription)
       
         CommentStep("Run the debugger")
       
         debugger_run();
      
         Wait(sintDefaultWait);
         
         CommentStep("Check if the debugger is stopped on the correct function")
          
         RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);
         
         ResultStep("*pu8Data - KU8_VALUE_UNDER_LIMIT", "*pu8Data - KU8_VALUE_UNDER_LIMIT")
      }
      
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
      
      CAN.SetDiagnosticAdressingMode(CAN.ActiveChannel,_iDiagRequestFrameIdFL,_iDiagResponseFrameIdFL) 
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
   
   CAN.SetDiagnosticAdressingMode(CAN.ActiveChannel,_iDiagRequestFrameIdFL,_iDiagResponseFrameIdFL) 
}