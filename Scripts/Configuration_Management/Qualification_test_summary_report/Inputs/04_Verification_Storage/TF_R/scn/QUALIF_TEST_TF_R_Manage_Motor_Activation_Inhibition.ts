/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_R_Manage_Motor_Activation_Inhibition
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_R_158, ALV_EXT_TF_R_161
Description of the requirement:
ALV_EXT_TF_R_158: The [Motor Activation Inhibition Status] shall be initialized to INHIBITED.
ALV_EXT_TF_R_161: IF  ["To Check ADC" AEC status] is QUALIFIED 
					THEN [Motor Activation Inhibition Status] = INHIBITED
				
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
const cTEST_OK = true;// Constant for the tests
const cTEST_NOK = false;
const cENV_NON_INITIALIZED = "NO_INIT";// Mandatory constant
const cENV_NOK = false;// Mandatory constant
const cException_Catched = true;// MANDATORY CONSTANT FOR ALL TEST SCRIPTS

/* Function name used to place a breakpoint */
const CFGc_FunctionToTest1: String = "UpdateModeStatus_InhibitionOfCyclesByInternalFailure_AllCycles";


/* breakpoint offset declaration */
const CFGc_BP1Offset: Number = 10;
const CFGc_BP3Offset: Number = 39; //  u8AecStatus = (u8AecStatus_AllCycles[KU8_IDX_ADC_OUT_OF_ORDER]
const CFGc_BP4Offset: Number = 42; // u8ModeStatusIsOk = KU8_FALSE

/*Parameter and variables address*/ 
var CFGc_VariableAddress1 = "0x200010D8"; // u8AecStatus_AllCycles[KU8_IDX_ADC_OUT_OF_ORDER]

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "5"; 

/* WinIDEA intialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResethOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */
/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Boolean used to check if the test is succesful */
var bRetFunction: Boolean = false;
/* variable used to set breakpoint in the function tested */
var addressBP1;
/* variable used to send routine control request */
var sRequest;
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
		Wait(2000);
        debugger_stop();	
		
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_R_158")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check value of variable u8ModeStatusIsOk, corresponding to motor activation inhibition status", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value u8ModeStatusIsOk is set to 170, corresponding to Inhibited (TRUE)", debugger_readRegister("R4","uint8"),170);
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);	  	  

		debugger_reset();

		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_R_161")			
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP3Offset)[3]  
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
		RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
		RESULT.ExpectTestResult("Set u8AecStatus_AllCycles[KU8_IDX_ADC_OUT_OF_ORDER] to 1, corresponding ADC AEC qualified",debugger_writeMemory(CFGc_VariableAddress1,"01",1),true);
		RESULT.ExpectTestResult("check that the variable value u8AecStatus_AllCycles[KU8_IDX_ADC_OUT_OF_ORDER] is 1, corresponding ADC AEC qualified", debugger_readMemory(CFGc_VariableAddress1, 1, "int"),1);
        
		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP4Offset)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
		RESULT.ExpectTestResult("Wait until u8ModeStatusIsOk = FALSE is reached", debugger_waitWhileRunning(4000), true);		
		debugger_reset();
		

		
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