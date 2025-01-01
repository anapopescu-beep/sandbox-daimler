/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_To_Check_ADC
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_270, ALV_EXT_TF_H_278, ALV_EXT_TF_H_279, ALV_EXT_TF_H_280 
Description of the requirement:
ALV_EXT_TF_H_270 : AD Converter shall already have performed at least ONE sampling. 
ALV_EXT_TF_H_278 : IF  [NVP_u16ADCLowVoltageThrs ]< [u16ADCRefLowVoltage] 
				   THEN     The test is NOK 
ALV_EXT_TF_H_279 : ELSE IF   [u16ADCRefHighVoltage] < [NVP_u16ADCHighVoltageThrs]
				   THEN     The test is NOK 
ALV_EXT_TF_H_280 : ELSE the test is OK 


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
const CFGc_FunctionToTest1: String = "AdcIf_Autotest_CheckAdc";

/* breakpoint offset declaration */
const CFGc_BP1Offset1: Number = 18; 
const CFGc_BP1Offset2: Number = 36; 

/*Parameter, Registers and variables address*/ 
var CFGc_VariableAddress1 = "0x200010C0";
var CFGc_VariableAddress2 = "0x200010C2";


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
	  
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_270")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset1)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check value of variable u16ADCRefLowVoltage and  u16ADCRefHighVoltage in the function " + CFGc_FunctionToTest1, debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("read the variable value u16ADCRefLowVoltage, corresponding to the filtered raw value of measured voltage on ADC test pins", debugger_readMemory(CFGc_VariableAddress1, 1, "int"), 131);
		RESULT.ExpectTestResult("read the variable value u16ADCRefHighVoltage, corresponding to the filtered raw value of measured voltage on ADC test pins", debugger_readMemory(CFGc_VariableAddress2, 1, "int"), 4);
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
		
		debugger_reset();		
 		
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_278")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset1)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in the function " + CFGc_FunctionToTest1, debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("write variable u16ADCRefLowVoltage, set a value upper than NVP_u16ADCLowVoltageThrs = 14",debugger_writeMemory(CFGc_VariableAddress2,"0F",1),true);
		RESULT.ExpectTestResult("read the variable u16ADCRefLowVoltage", debugger_readMemory(CFGc_VariableAddress2, 1, "int"),15);
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset2)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check variable u8ResultOfAutoTest, corresponding to autotest result", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value u8ResultOfAutoTest is set 2, corresponding to KU8_ATM_TEST_NOK,", debugger_readRegister("R0","uint8"),2);			
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
		
		debugger_reset();		
 		
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_279")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset1)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in the function " + CFGc_FunctionToTest1, debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("write variable u16ADCRefHighVoltage, set a value lower than NVP_u16ADCLowVoltageThrs = 14",debugger_writeMemory(CFGc_VariableAddress1,"0D",1),true);
		RESULT.ExpectTestResult("read the variable u16ADCRefHighVoltage", debugger_readMemory(CFGc_VariableAddress1, 1, "int"),13);
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset2)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check variable u8ResultOfAutoTest, corresponding to autotest result", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value u8ResultOfAutoTest is set 2, corresponding to KU8_ATM_TEST_NOK,", debugger_readRegister("R0","uint8"),2);			
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);
		
		debugger_reset();		
 		
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_280")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset2)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check variable u8ResultOfAutoTest, corresponding to autotest result", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value u8ResultOfAutoTest is set 1, corresponding to KU8_ATM_TEST_OK,", debugger_readRegister("R0","uint8"),1);			
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);		
		
		


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