/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_To_Check_Mosfet_Open_Circuit
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_785, ALV_EXT_TF_H_807, ALV_EXT_TF_H_817, ALV_EXT_TF_H_827, ALV_EXT_TF_H_837, ALV_EXT_TF_H_840
Description of the requirement:
ALV_EXT_TF_H_785 : The AD converter autotest has been successfully passed. 
ALV_EXT_TF_H_807 : [MOTOR_P_Vlevel] voltage shall be measured after taking into account IO response time.
ALV_EXT_TF_H_817 : [MOTOR_P_Vlevel] voltage shall be measured  after taking into account IO response time.
ALV_EXT_TF_H_827 : [MOTOR_N_Vlevel] voltage shall be measured after taking into account IO response time.
ALV_EXT_TF_H_837 : [MOTOR_N_Vlevel] voltage shall be measured after taking into account IO response time.
ALV_EXT_TF_H_840 : IF (([MOTOR_N_Vlevel] - [V_GND_Level]) > [NVP_u16MOSFETinOCMinDropVoltage])
				   THEN
						Step 4 is NOK
						Goto Test Output
				   ELSE 
						Step 4 is OK
						Goto Test Output


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
const CFGc_FunctionToTest1: String = "PAL_Autotest_CheckMosfetOCAT";
const CFGc_FunctionToTest2: String = "AdcIf_Autotest_CheckAdc";
const CFGc_FunctionToTest3: String = "PMP_runGetMotorVp_20ms";
const CFGc_FunctionToTest4: String = "PMP_runGetMotorVn_20ms";
/* breakpoint offset declaration */
const CFGc_BP1Offset1: Number = 64; 
const CFGc_BP1Offset2: Number = 36;
const CFGc_BP1Offset3: Number = 72; 
const CFGc_BP1Offset4: Number = 16;
const CFGc_BP1Offset5: Number = 76; 
const CFGc_BP1Offset6: Number = 166;
const CFGc_BP1Offset7: Number = 176;






/*Parameter, Registers and variables address*/ 
var CFGc_VariableAddress1 = "0x200010B0";
var CFGc_VariableAddress2 = "0x200010A0";
var CFGc_VariableAddress3 = "0x200010B6";
var CFGc_VariableAddress4 = "0x200010BA";
var CFGc_VariableAddress5 = "0x1400015E";
var CFGc_RegisterAddress1 = "R5";


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
	  
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_785")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2,CFGc_BP1Offset2)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check if ADC autotest has been successfully passed", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value u8ResultOfAutoTest is set 1, corresponding to KU8_ATM_TEST_OK,", debugger_readRegister("R0","uint8"),1);			
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset1)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check if PAL_Autotest_CheckMosfetOCAT could be performed ", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);		

		debugger_reset();
		
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_807 and ALV_EXT_TF_H_817")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset5)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function " + CFGc_FunctionToTest1, debugger_isCPUStoppedAtAddress(addressBP1), true);
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest3,CFGc_BP1Offset4)[3] 		
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function " + CFGc_FunctionToTest3, debugger_isCPUStoppedAtAddress(addressBP1), true);			
		RESULT.ExpectTestResult("read the variable value u16InternalAnalogSignal, corresponding to The [MOTOR_P_Vlevel] voltage which shall be measured.", debugger_readMemory(CFGc_VariableAddress2, 2, "hex"), "FE00");
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);		

		debugger_reset();		
		
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_827 and ALV_EXT_TF_H_837")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset3)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function " + CFGc_FunctionToTest1, debugger_isCPUStoppedAtAddress(addressBP1), true);
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest4,CFGc_BP1Offset4)[3] 		
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function " + CFGc_FunctionToTest4, debugger_isCPUStoppedAtAddress(addressBP1), true);			
		RESULT.ExpectTestResult("read the variable value u16InternalAnalogSignal, corresponding to The [MOTOR_N_Vlevel] voltage which shall be measured.", debugger_readMemory(CFGc_VariableAddress2, 2, "hex"), "6800");
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);		

		debugger_reset();		

		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_840")
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset6)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function " + CFGc_FunctionToTest1, debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("read the variable value u16FilteredMotorMinusVoltage, corresponding to MOTOR_N_Vlevel", debugger_readMemory(CFGc_VariableAddress3, 2, "hex"), "1101");
		RESULT.ExpectTestResult("read the variable value u16FilteredGroundLevel, corresponding to V_GND_Level", debugger_readMemory(CFGc_VariableAddress4, 2, "hex"), "0400");
		RESULT.ExpectTestResult("read the variable value NVP_u16MOSFETinOCMinDropVoltage", debugger_readMemory(CFGc_VariableAddress5, 2, "hex"), "B80B");
		CommentStep("we can observe that [MOTOR_N_Vlevel] - [V_GND_Level]) < [NVP_u16MOSFETinOCMinDropVoltage]")
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset7)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
		RESULT.ExpectTestResult("read the variable value u8ResultOfAutoTest, corresponding to PAL_Autotest_CheckMosfetOCAT result KU8_ATM_TEST_OK", debugger_readRegister(CFGc_RegisterAddress1,"uint8"),1);

		debugger_reset();		

		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset6)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function " + CFGc_FunctionToTest1, debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("read the variable value u16FilteredMotorMinusVoltage, corresponding to MOTOR_N_Vlevel", debugger_readMemory(CFGc_VariableAddress3, 2, "hex"), "1101");
		RESULT.ExpectTestResult("change the value of variable u16FilteredMotorMinusVoltage, corresponding to MOTOR_N_Vlevel",debugger_writeMemory(CFGc_VariableAddress3,"C350",2),true);
		RESULT.ExpectTestResult("read the variable value u16FilteredMotorMinusVoltage, corresponding to MOTOR_N_Vlevel", debugger_readMemory(CFGc_VariableAddress3, 2, "hex"), "C350");
		RESULT.ExpectTestResult("read the variable value u16FilteredGroundLevel, corresponding to V_GND_Level", debugger_readMemory(CFGc_VariableAddress4, 2, "hex"), "0400");
		RESULT.ExpectTestResult("read the variable value NVP_u16MOSFETinOCMinDropVoltage", debugger_readMemory(CFGc_VariableAddress5, 2, "hex"), "B80B");		
		CommentStep("we can observe that [MOTOR_N_Vlevel] - [V_GND_Level]) > [NVP_u16MOSFETinOCMinDropVoltage]")
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset7)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
		RESULT.ExpectTestResult("read the variable value u8ResultOfAutoTest, corresponding to PAL_Autotest_CheckMosfetOCAT result KU8_ATM_TEST_NOK", debugger_readRegister(CFGc_RegisterAddress1,"uint8"),2);		
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