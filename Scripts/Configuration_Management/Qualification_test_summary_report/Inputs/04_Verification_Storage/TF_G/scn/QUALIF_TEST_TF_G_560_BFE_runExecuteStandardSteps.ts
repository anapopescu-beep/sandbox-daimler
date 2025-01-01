/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_G_560_BFE_runExecuteStandardSteps
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_G_560
Description of the requirement:
ALV_EXT_TF_G_560: The current regulation shall be executed every 2 ms without High Power regulation 
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
var index;
var bIsBPset: Boolean = false;
var sintBPTimeout: Number = 5000;
var bBreakPointResult: Boolean = false;

const CFGc_FunctionToTest1: String = "BFE_runExecuteStandardSteps";
const CFGc_FunctionToTest2: String = "Rte_Call_pclMotor_I_Get_mA";

/* offset Breakpoint */
var sintOffsetBP1: Number = 0;
var sintOffsetBP2: Number = 19; //Rte_Call_pclMotor_I_Get_mA(&ps32MotorCurrentInmA_c)

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50"; 

/* WinIDEA intialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */

/*number of OS tick */ 
var CFGc_NumberCounterAddress = 536851192; // OS_counterDynamic_core0
var CFGc_NumberOfData = 1;
var CFGc_Periodicity = 2;

/*Read register*/
var CFGc_ReadRegisterName: String = "R0";
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
          for (index = 0; index < 3; index++)
          {
             CommentStep(">>>>>>>>>>> Call of the function " + CFGc_FunctionToTest1 +" n°"+index+"<<<<<<<<<<<<<<<<")
             /* Set a breakpoint in the tested function */
             addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,sintOffsetBP1)[3] 
             RESULT.ExpectTestResult("Run application", debugger_run(), true);
             RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
             RESULT.ExpectTestResult("The function " + CFGc_FunctionToTest1 + " is reached", debugger_isCPUStoppedAtAddress(addressBP1), true);
            
             numberOfTickInit = debugger_readMemory(CFGc_NumberCounterAddress, CFGc_NumberOfData, "int");
                         
             RESULT.ExpectTestResult("Run application", debugger_run(), true);
             RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);

             numberOfTick = debugger_readMemory(CFGc_NumberCounterAddress, CFGc_NumberOfData, "int");
               
             periodicity = (numberOfTick - numberOfTickInit);
             /* The function is called after 10ms (400 000 ticks) */ 
             RESULT.ExpectTestResult("Periodicity of measurement : Function called after 2ms ? ",periodicity,CFGc_Periodicity); 

             RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);

          }
		  /* Set a breakpoint in the tested function */
             addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,sintOffsetBP2)[3] 
             RESULT.ExpectTestResult("Run application", debugger_run(), true);
             RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
             RESULT.ExpectTestResult("PAL_runReadMotorCurrentInmA; is reached", debugger_isCPUStoppedAtAddress(addressBP1), true);
             
             RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
      /*------------------------------------------------------------------------------
                              DEINITIALIZATION ENVIRONMENT
      ------------------------------------------------------------------------------*/
      RESULT.ExpectTestResult("Reset the debugger",
			debugger_reset(),
			cTEST_OK
			)

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