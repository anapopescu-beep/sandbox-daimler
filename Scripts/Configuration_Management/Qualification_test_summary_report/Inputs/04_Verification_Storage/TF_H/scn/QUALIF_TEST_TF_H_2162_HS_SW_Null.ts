/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_2162_HS_SW_Null
Result Test:
************************************************************************************************
Requirement under test: TR6_EXT_TF_H_2162
Description of the requirement:
- This autotest shall be performed ho check High side switch step 1
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
const CFGc_FunctionToTest1: String = "pal_u8HighSideSWRegStep_1";

/* offset Breakpoint */
var sintOffsetBP1: Number = 50;

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "5"; 

/* WinIDEA intialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */
/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/

/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Boolean used to check if the test is succesful */
var bRetFunction: Boolean = false;
var result;
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
            Wait(1000);

            debugger_stop();

            /* Set a breakpoint in the function pal_u8HighSideSWRegStep_1 */
            addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1, sintOffsetBP1)[3] 
            RESULT.ExpectTestResult("Run application", debugger_run(), true);
			
			/*Force the software to enter the pal_u8HighSideSWRegStep_1 function*/
			result = CAN.SendDiagByValues("0x11 0x03");
			Wait(1000);
			
            RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(2000), true);
            RESULT.ExpectTestResult("The function "+CFGc_FunctionToTest1+" is reached", debugger_isCPUStoppedAtAddress(addressBP1), true);
          
            ResultStep("Function reached", "Debugger stopped in BP where HSS is null");

            RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
			
			RESULT.ExpectTestResult("Run application", debugger_run(), true);
        
      /*------------------------------------------------------------------------------
                              DEINITIALIZATION ENVIRONMENT
      ------------------------------------------------------------------------------*/
     
        /*"winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger). This function is mandatory*/
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