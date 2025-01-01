/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_B_RGS_HR_Temp
Result Test:
************************************************************************************************
Requirement under test: TR6_EXT_TF_B_2250, TR6_EXT_TF_B_2251, TR6_EXT_TF_B_2252, TR6_EXT_TF_B_2253, TR6_EXT_TF_B_2254, TR6_EXT_TF_B_2255, TR6_EXT_TF_B_2256
Description of the requirement: TR6_EXT_TF_B_2250: RGS sends the internal ECU temperature (detected using SBC temperature sensor) on this signal.
TR6_EXT_TF_B_2251: Position in frame:
	Startbyte: 6
 	Startbit: 0
 	Length: 8
TR6_EXT_TF_B_2252: The Init value [dec] shall be: 254
TR6_EXT_TF_B_2253: The Value range [dec] shall be: 0 .. 253

Note:
Temperature range -40 .. 86.5 degree Celsius
TR6_EXT_TF_B_2254: Coding: 
	254==Init
	255==Error
TR6_EXT_TF_B_2255: The Scaling shall be: 0.5
TR6_EXT_TF_B_2256: The Offset shall be: -40
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
const CFGc_FunctionToTest1: String = "cil_ComputeSignalTemp";
const CFGc_FunctionOffsetToTest1: Number = 7;
const CFGc_FunctionToTest2: String = "CIL_runAppliToCAN";
const CFGc_FunctionOffsetToTest2: Number = 298;

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50"; 

/* WinIDEA initialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */

const iKL30OvervoltageValue = 18;
const iKL30DefaultVoltageValue = 12;

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
      
      Wait(sintWaitInit);
   
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
      sendCANDiagRequest("Change side allocation", "0x2E 0xFD 0x2F 0xA9", "0x6E 0xFD 0x2F");
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

      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1, CFGc_FunctionOffsetToTest1);

      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest1 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest1

      CommentStep(sBPDescription)

      CommentStep("Run the debugger")

      Wait(sintWaitInit);

      CommentStep("Check if the debugger is stopped on the correct function")

      RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

      ResultStep("true", "true")

      CommentStep("read memory - cil_u8RGS_Temp")

      iReadVariableValue = debugger_evaluate("cil_u8RGS_Temp");

      RESULT.ExpectTestResult("Evaluate cil_u8RGS_Temp ",
         iReadVariableValue,
         "254"
      );

      ResultStep("cil_u8RGS_Temp - 254(init value)", "cil_u8RGS_Temp - 254(init value)")

      CommentStep("write memory - s16InternalTemperature_deg - 22 degrees")

      bWriteVariableResult = debugger_modify("s16InternalTemperature_deg", 22)

      if (true == bWriteVariableResult)
      {
         CommentStep("read memory - s16InternalTemperature_deg")

         iReadVariableValue = debugger_evaluate("s16InternalTemperature_deg");

         RESULT.ExpectTestResult("Evaluate s16InternalTemperature_deg ",
            iReadVariableValue,
            "22"
         );

         ResultStep("s16InternalTemperature_deg - 22", "s16InternalTemperature_deg - 22")

         Thread.Sleep(sintDefaultWait);

         tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2, CFGc_FunctionOffsetToTest2);

         sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest2 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest2

         CommentStep(sBPDescription)

         CommentStep("Run the debugger")

         debugger_run();

         Wait(sintDefaultWait);

         CommentStep("Check if the debugger is stopped on the correct function")

         RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

         ResultStep("true", "true")

         CommentStep("read memory - cil_u8RGS_Temp")

         iReadVariableValue = debugger_evaluate("cil_u8RGS_Temp");

         RESULT.ExpectTestResult("Evaluate cil_u8RGS_Temp ",
            iReadVariableValue,
            "124"
         );

         ResultStep("cil_u8RGS_Temp - 124", "cil_u8RGS_Temp - 124")
      }

      debugger_run();

      Wait(sintDefaultWait);

      RESULT.ExpectTestResult("Read RGS_VL_Temp from CAN bus", CAN.GetSignalFromFrame("RGS_VL_01", "RGS_VL_Temp")[1], "0x7C");

      /* Clear all breakpoints */
      CommentStep("Clear all breakpoints");
      RESULT.ExpectTestResult("Delete all breakpoints",
         debugger_deleteAllBreakpoints(),
         true
      );

      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1, CFGc_FunctionOffsetToTest1);

      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest1 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest1

      CommentStep(sBPDescription)

      Wait(sintDefaultWait);

      CommentStep("Run the debugger")

      debugger_run();

      Wait(sintWaitInit);

      CommentStep("Check if the debugger is stopped on the correct function")

      RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

      ResultStep("true", "true")

      CommentStep("write memory - s16InternalTemperature_deg - -40 degrees")

      bWriteVariableResult = debugger_modify("s16InternalTemperature_deg", -40)

      if (true == bWriteVariableResult)
      {
         CommentStep("read memory - s16InternalTemperature_deg")

         iReadVariableValue = debugger_evaluate("s16InternalTemperature_deg");

         RESULT.ExpectTestResult("Evaluate s16InternalTemperature_deg ",
            iReadVariableValue,
            "-40"
         );

         ResultStep("s16InternalTemperature_deg - -40", "s16InternalTemperature_deg - -40")

         Thread.Sleep(sintDefaultWait);

         tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2, CFGc_FunctionOffsetToTest2);

         sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest2 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest2

         CommentStep(sBPDescription)

         CommentStep("Run the debugger")

         debugger_run();

         Wait(sintDefaultWait);

         CommentStep("Check if the debugger is stopped on the correct function")

         RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

         ResultStep("true", "true")

         CommentStep("read memory - cil_u8RGS_Temp")

         iReadVariableValue = debugger_evaluate("cil_u8RGS_Temp");

         RESULT.ExpectTestResult("Evaluate cil_u8RGS_Temp ",
            iReadVariableValue,
            "0"
         );

         ResultStep("cil_u8RGS_Temp - 0", "cil_u8RGS_Temp - 0")

         debugger_run();

         Wait(sintDefaultWait);

         RESULT.ExpectTestResult("Read RGS_VL_Temp from CAN bus", CAN.GetSignalFromFrame("RGS_VL_01", "RGS_VL_Temp")[1], "0x00");
      }

      /* Clear all breakpoints */
      CommentStep("Clear all breakpoints");
      RESULT.ExpectTestResult("Delete all breakpoints",
         debugger_deleteAllBreakpoints(),
         true
      );

      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1, CFGc_FunctionOffsetToTest1);

      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest1 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest1

      CommentStep(sBPDescription)

      Wait(sintDefaultWait);

      CommentStep("Run the debugger")

      debugger_run();

      Wait(sintWaitInit);

      CommentStep("Check if the debugger is stopped on the correct function")

      RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

      ResultStep("true", "true")

      CommentStep("write memory - s16InternalTemperature_deg - 86 degrees")

      bWriteVariableResult = debugger_modify("s16InternalTemperature_deg", 86)

      if (true == bWriteVariableResult)
      {
         CommentStep("read memory - s16InternalTemperature_deg")

         iReadVariableValue = debugger_evaluate("s16InternalTemperature_deg");

         RESULT.ExpectTestResult("Evaluate s16InternalTemperature_deg ",
            iReadVariableValue,
            "86"
         );

         ResultStep("s16InternalTemperature_deg - 86", "s16InternalTemperature_deg - 86")

         Thread.Sleep(sintDefaultWait);

         tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2, CFGc_FunctionOffsetToTest2);

         sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest2 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest2

         CommentStep(sBPDescription)

         CommentStep("Run the debugger")

         debugger_run();

         Wait(sintDefaultWait);

         CommentStep("Check if the debugger is stopped on the correct function")

         RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

         ResultStep("true", "true")

         CommentStep("read memory - cil_u8RGS_Temp")

         iReadVariableValue = debugger_evaluate("cil_u8RGS_Temp");

         RESULT.ExpectTestResult("Evaluate cil_u8RGS_Temp ",
            iReadVariableValue,
            "252"
         );

         ResultStep("cil_u8RGS_Temp - 252", "cil_u8RGS_Temp - 252")

         debugger_run();

         Wait(sintDefaultWait);

         RESULT.ExpectTestResult("Read RGS_VL_Temp from CAN bus", CAN.GetSignalFromFrame("RGS_VL_01", "RGS_VL_Temp")[1], "0xFC");
      }

      /* Clear all breakpoints */
      CommentStep("Clear all breakpoints");
      RESULT.ExpectTestResult("Delete all breakpoints",
         debugger_deleteAllBreakpoints(),
         true
      );

      tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1, CFGc_FunctionOffsetToTest1);

      sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest1 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest1

      CommentStep(sBPDescription)

      Wait(sintDefaultWait);

      CommentStep("Run the debugger")

      debugger_run();

      Wait(sintWaitInit);

      CommentStep("Check if the debugger is stopped on the correct function")

      RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

      ResultStep("true", "true")

      CommentStep("write memory - s16InternalTemperature_deg - 90 degrees")

      bWriteVariableResult = debugger_modify("s16InternalTemperature_deg", 90)

      if (true == bWriteVariableResult)
      {
         CommentStep("read memory - s16InternalTemperature_deg")

         iReadVariableValue = debugger_evaluate("s16InternalTemperature_deg");

         RESULT.ExpectTestResult("Evaluate s16InternalTemperature_deg ",
            iReadVariableValue,
            "90"
         );

         ResultStep("s16InternalTemperature_deg - 90", "s16InternalTemperature_deg - 90")

         Thread.Sleep(sintDefaultWait);

         tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2, CFGc_FunctionOffsetToTest2);

         sBPDescription = "BP: File Name = " + tRelativeBreakPointParam[2] + ", Function = " + CFGc_FunctionToTest2 + ", Line Number = " + tRelativeBreakPointParam[1] + ", @ = 0x"   + tRelativeBreakPointParam[3] + "; Function Line offset =" + CFGc_FunctionOffsetToTest2

         CommentStep(sBPDescription)

         CommentStep("Run the debugger")

         debugger_run();

         Wait(sintDefaultWait);

         CommentStep("Check if the debugger is stopped on the correct function")

         RESULT.ExpectTestResult(sBPDescription + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true);

         ResultStep("true", "true")

         CommentStep("read memory - cil_u8RGS_Temp")

         iReadVariableValue = debugger_evaluate("cil_u8RGS_Temp");

         RESULT.ExpectTestResult("Evaluate cil_u8RGS_Temp ",
            iReadVariableValue,
            "255"
         );

         ResultStep("cil_u8RGS_Temp - 255", "cil_u8RGS_Temp - 255")

         debugger_run();

         Wait(sintDefaultWait);

         RESULT.ExpectTestResult("Read RGS_VL_Temp from CAN bus", CAN.GetSignalFromFrame("RGS_VL_01", "RGS_VL_Temp")[1], "0xFF");
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