/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_364_UnderVoltage_Current_QualificationDeskill_status
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_364
Description of the requirement:
ALV_EXT_TF_H_364:   ⦁	The Under-Voltage current Qualification/Deskill status [u8AECBatteryUVStatus]
************************************************************************************************
Equipment: PowerSupply, CanCaseXL, MockUp, IC5000 debugger
Test Notes: 
Full Automation: Yes
Global Result Assignment: Neeva
************************************************************************************************/
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

/* Function name used to place a breakpoint */
const CFGc_FunctionToTest: String = "PMP_Autotest_CheckPowerSupplyUV";
const CFGc_OffsetFunction = 34; // Where Rte_Call_pclEvtInfoBatPwrUnderVoltage_GetEventStatus(&u8AECBatteryUVStatus) is used 
const CFGc_Line_OffsetFunction = 227;

/* Delay to let ECU wakeup */
const CFGc_WakeupDelay = 5000;

/* Service configuration */
const CFGc_SupplierSession: String = "supplier";
const CFG_ClearFaultsReq: String = "0x14 0xFF 0xFF 0xFF";
const CFG_ClearFaultsResp: String = "0x54"; 

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/

/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Boolean used to check if the test is succesful */
var bRetFunction: Boolean = true;

var bIsBPset: Boolean = false;
var bBreakPointResult: Boolean = false;
var aBreakPointResult = [];

/*------------------------------------------------------------------------------
                                GLOBAL FUNCTIONS
 ------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                                    Core Test
------------------------------------------------------------------------------*/

try
{
   /*------------------------------------------------------------------------------
                           INITIALIZATION ENVIRONMENT
   ------------------------------------------------------------------------------*/
   /**** This function is parametrable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/
   RESULT.ExpectTestResult("Init Environment test", SwDevLib_InitBenchEnvironment(), true);
   /*------------------------------------------------------------------------------
                                 CONFIGURATION TEST
   ------------------------------------------------------------------------------*/

   CommentStep("Lets ECU wakeup and enter ATM running phase");
   Wait(CFGc_WakeupDelay);

   CommentStep("Enter in supplier session");
   EnterDiagSession(CFGc_SupplierSession);
   Wait(1000);
   CommentStep("Clear Faults");
   var sResponse = CAN.SendDiagByValues(CFG_ClearFaultsReq);
   RESULT.InsertComment("Response CFG_ClearFaultsReq : " + sResponse[1]);
   Wait(CFGc_WakeupDelay);

   /*------------------------------------------------------------------------------
                                    EXECUTION TEST
   ------------------------------------------------------------------------------*/
   if (cTEST_OK == bRetFunction)
   {
      /* Check if the function is correctly called */
      //bRetFunction = PP4G_LibInteg_CheckSubFunctionCall(CFGc_FunctionToTest, CFGc_SubFunctionToTest, CFGc_CallStack);

      // Place a breakpoint on the required function //
      CommentStep("Place a breakpoint on " + CFGc_FunctionToTest + " function")
      bIsBPset = debugger_setBreakPointAtFunction(CFGc_FunctionToTest);
      RESULT.ExpectTestResult("Set a breakpoint on: " + CFGc_FunctionToTest, bIsBPset, true);
      
      if (true == bIsBPset)
      {
         // Run & Let ECU wake up //
         CommentStep("Run & Let ECU wake up");
         debugger_run();
         Wait(CFGc_WakeupDelay);

         // Check if the debugger is stopped on the correct function //
         bBreakPointResult = debugger_isCPUstoppedAtFunction(CFGc_FunctionToTest);
         RESULT.ExpectTestResult("Debugger stopped on " + CFGc_FunctionToTest + " ?", bBreakPointResult, true);
         
         if (true == bBreakPointResult)
         {
            // Place a breakpoint where we get u8AECBatteryOVStatus input //
            CommentStep("Place a breakpoint on  line " + CFGc_Line_OffsetFunction + " where we get u8AECBatteryUVStatus input")
            aBreakPointResult = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest, CFGc_OffsetFunction);
            RESULT.ExpectTestResult("Set a breakpoint on  line " + CFGc_Line_OffsetFunction + " : Rte_Call_pclEvtInfoBatPwrUnderVoltage_GetEventStatus(&u8AECBatteryUVStatus)", aBreakPointResult[0], true);

            if (true == aBreakPointResult[0])
            {
               // Run & Let ECU wake up //
               CommentStep("Run & Let ECU wake up");
               debugger_run();
               Wait(CFGc_WakeupDelay);

               // Check if the debugger is stopped on the correct function //
               bBreakPointResult = debugger_isCPUStoppedAtAddress(aBreakPointResult[3]);
               RESULT.ExpectTestResult("Debugger stopped on line " + CFGc_Line_OffsetFunction + " :  Rte_Call_pclEvtInfoBatPwrUnderVoltage_GetEventStatus(&u8AECBatteryUVStatus);  ?", bBreakPointResult, true);

               if (true == bBreakPointResult)
               {
                  // Resume code execution //
                  debugger_run();

                  bRetFunction = true;
               }

            }
            else
            {
               // Cannot set the breakpoint, leave test in a stable state //
               CommentStep("Cannot set the breakpoint on  line " + CFGc_Line_OffsetFunction + ". Function may not be implemented or there is a problem with the debugger.");
               bRetFunction = false;
            }
         }
         else
         {
            CommentStep("Debugger is not stopped on the correct function " + CFGc_FunctionToTest + " !");
            bRetFunction = false;
         }
      }
      else
      {
         // Cannot set the breakpoint, leave test in a stable state //
         CommentStep("Cannot set the breakpoint on function " + CFGc_FunctionToTest + ". Function may not be implemented or there is a problem with the debugger.");
         bRetFunction = false;
      }

      /*** Check result of test ****/
      RESULT.ExpectTestResult("Global Verification of test", bRetFunction, cTEST_OK);

      /*------------------------------------------------------------------------------
                                    RESET CONFIGURATION TEST
      ------------------------------------------------------------------------------*/
      RESULT.ExpectTestResult("Init Environment test", SwDevLib_InitBenchEnvironment(), cTEST_OK);
   }
   else
   {
      /*** Warn the tester that the test isn't executed ****/
      RESULT.InsertComment("Tests is not executed : configuration of test failed")
   }

   /*------------------------------------------------------------------------------
                           DEINITIALIZATION ENVIRONMENT
   ------------------------------------------------------------------------------*/
    // "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger)
    // RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK );
}
catch (exError)
{
   RESULT.ExpectTestResult("Test failed about exception occurs :" + exError, cException_Catched, false);

   RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}