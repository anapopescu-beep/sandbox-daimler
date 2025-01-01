/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_To_Handle_Reset_Causes
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_1326, ALV_EXT_TF_H_1330
Description of the requirement:
ALV_EXT_TF_H_1326 : Reset causes are evaluated.
ALV_EXT_TF_H_1330 : IF 	([RST_Cause] = (CRYSTAL_FAILURE OR PLL_FAILURE OR ECC_RAM OR ECC P-FLASH OR OS EXCEPTION INVALID_INTERRUPT OR ECC_UNIDENTIFIED OR ECC_E2P STACK_OVERFLOW OR EXTERNAL_WDG ))
					THEN 
						Test is NOK
					ELSE
						Test is OK


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


/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50"; 

/* WinIDEA intialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResethOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOn";    /* [RunOn, RunOff] */


/* Function name used to place a breakpoint */
const CFGc_FunctionToTest1: String = "RCM_Autotest_RunResetCause";
const CFGc_FunctionToTest2: String = "RCM_runGetResetCause";


/* breakpoint offset declaration */
const CFGc_BP1Offset1: Number = 7; 
const CFGc_BP1Offset2: Number = 11;
const CFGc_BP1Offset3: Number = 30;
const CFGc_BP1Offset4: Number = 10;

/*Parameter, Registers and variables address*/ 
var CFGc_VariableAddress1 = "0x1FFFB500";
var CFGc_VariableAddress2 = "0x200010C0";

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/


/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Boolean used to check if the test is succesful */
var bRetFunction: Boolean = false;
/* variable used to set breakpoint in the function tested */
var addressBP1;
/* variable used to get stackTrace */
var stackTrace;
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
  
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_1326")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset1)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function RCM_Autotest_RunResetCause", debugger_isCPUStoppedAtAddress(addressBP1), true);
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2,CFGc_BP1Offset2)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function RCM_runGetResetCause", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("read the variable value rcm_u32ResetCause, corresponding software Reset Cause", debugger_readMemory(CFGc_VariableAddress1, 1, "hex"), "01");		
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);		
		
		debugger_reset();		
		
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_1330")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset3)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function RCM_Autotest_RunResetCause", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value u8ResultOfAutoTest is set 2, corresponding to KU8_ATM_TEST_NOK,", debugger_readRegister("R0","uint8"),2);			
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);			
		
		debugger_reset();	

		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset4)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function RCM_Autotest_RunResetCause", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("change the value of variable u32ResetCause allowing to pass condition in the function",debugger_writeMemory(CFGc_VariableAddress2,"00000001",4),true);
		RESULT.ExpectTestResult("read the variable value u32ResetCause", debugger_readMemory(CFGc_VariableAddress2, 4, "hex"), "00000001");
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset3)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function RCM_Autotest_RunResetCause", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value u8ResultOfAutoTest is set 1, corresponding to KU8_ATM_TEST_OK,", debugger_readRegister("R0","uint8"),1);			
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);	
		
		debugger_reset();		
	  /*------------------------------------------------------------------------------
                              DEINITIALIZATION ENVIRONMENT
      ------------------------------------------------------------------------------*/
       // RESULT.ExpectTestResult("Reset the debugger",
			 // debugger_reset(),
			 // cTEST_OK
			 // )

        // RESULT.ExpectTestResult("Close environment test",
        // winIDEAWorkspace_closeDiscard(),
        // cTEST_OK
      // );
      
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