/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_To_Check_ADC_Calibration
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_299, ALV_EXT_TF_H_300
Description of the requirement:
ALV_EXT_TF_H_299 : Test output shall be initialized to NOT_DECIDED.. 
ALV_EXT_TF_H_300 : IF  ADC HW unit Status 0 and ADC HW unit Status 1 are both calibrated
					THEN  the test is OK
					ELSE  the test is NOK 


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
const CFGc_FunctionToTest1: String = "AdcIf_Autotest_CheckAdcCalib";


/* breakpoint offset declaration */
const CFGc_BP1Offset1: Number = 6; 
const CFGc_BP1Offset2: Number = 20; 


/*Parameter, Registers and variables address*/ 
var CFGc_RegisterAddress1 = "R1";
var CFGc_VariableAddress0 = "0x1FFFA4CE";
var CFGc_VariableAddress1 = "0x1FFFA4CF";

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
	  
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_299")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset1)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function AdcIf_Autotest_CheckAdcCalib", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value u8ResultOfAutoTest is set 1, corresponding to KU8_ATM_TEST_NOT_DECIDED,", debugger_readRegister(CFGc_RegisterAddress1,"uint8"),4);				

		debugger_reset();	

		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_300")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset1)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function AdcIf_Autotest_CheckAdcCalib", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("read the variable value Adc_CalibrationStatus0.Adc_UnitSelfTestStatus, corresponding to ADC HW unit Status 0, The value Shall be 0 (calibrated) ", debugger_readMemory(CFGc_VariableAddress0, 1, "hex"), "00");
		RESULT.ExpectTestResult("read the variable value Adc_CalibrationStatus1.Adc_UnitSelfTestStatus, corresponding to ADC HW unit Status 1, The value Shall be 0 (calibrated)", debugger_readMemory(CFGc_VariableAddress1, 1, "hex"), "00");
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset2)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function AdcIf_Autotest_CheckAdcCalib", debugger_isCPUStoppedAtAddress(addressBP1), true);		
		RESULT.ExpectTestResult("check that the variable value u8ResultOfAutoTest is set 1, corresponding to KU8_ATM_TEST_OK,", debugger_readRegister(CFGc_RegisterAddress1,"uint8"),1);				
		debugger_reset();
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset1)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function AdcIf_Autotest_CheckAdcCalib", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("change the value of variable Adc_CalibrationStatus0.Adc_UnitSelfTestStatus, corresponding to ADC HW unit Status 0",debugger_writeMemory(CFGc_VariableAddress0,"01",1),true);
		RESULT.ExpectTestResult("read the variable value Adc_CalibrationStatus0.Adc_UnitSelfTestStatus, corresponding to ADC HW unit Status 0, The value Shall be 1 (not calibrated) ", debugger_readMemory(CFGc_VariableAddress0, 1, "hex"), "01");
		RESULT.ExpectTestResult("read the variable value Adc_CalibrationStatus1.Adc_UnitSelfTestStatus, corresponding to ADC HW unit Status 1, The value Shall be 0 (calibrated)", debugger_readMemory(CFGc_VariableAddress1, 1, "hex"), "00");
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset2)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function AdcIf_Autotest_CheckAdcCalib", debugger_isCPUStoppedAtAddress(addressBP1), true);		
		RESULT.ExpectTestResult("check that the variable value u8ResultOfAutoTest is set 2, corresponding to KU8_ATM_TEST_NOK,", debugger_readRegister(CFGc_RegisterAddress1,"uint8"),2);				
	
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