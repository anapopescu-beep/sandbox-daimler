/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_To_Check_High_Side_Switch_Regulation
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_1236, ALV_EXT_TF_H_1242, ALV_EXT_TF_H_1243
Description of the requirement:
ALV_EXT_TF_H_1236 : The AD converter autotest has been successfully passed. 
ALV_EXT_TF_H_1242 : 1st step:
					[HS_SW] shall be measured and checked if null
					The booster HW stage shall be activated
					
ALV_EXT_TF_H_1243 : 2nd step:
					[HS_SW] level shall be measured.

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
const CFGc_FunctionToTest1: String = "PAL_Autotest_CheckHighSideSwRegulation";
const CFGc_FunctionToTest2: String = "AdcIf_Autotest_CheckAdc";
const CFGc_FunctionToTest3: String = "pal_u8HighSideSWRegStep_1";
const CFGc_FunctionToTest4: String = "PMP_runGetHS1Level";
const CFGc_FunctionToTest5: String = "pal_u8HighSideSWRegStep_2";




/* breakpoint offset declaration */
const CFGc_BP1Offset1: Number = 17; 
const CFGc_BP1Offset2: Number = 36;
const CFGc_BP1Offset3: Number = 57;
const CFGc_BP1Offset4: Number = 14;
const CFGc_BP1Offset5: Number = 16;
const CFGc_BP1Offset6: Number = 50;
const CFGc_BP1Offset7: Number = 66;
const CFGc_BP1Offset8: Number = 12;


/*Parameter, Registers and variables address*/ 
var CFGc_VariableAddress1 = "0x200010B0";
var CFGc_VariableAddress2 = "0x200010A0";
var CFGc_VariableAddress3 = "0x1FFFA3BE";


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
	  
		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_1236")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest2,CFGc_BP1Offset2)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check if ADC autotest has been successfully passed", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("check that the variable value u8ResultOfAutoTest is set 1, corresponding to KU8_ATM_TEST_OK,", debugger_readRegister("R0","uint8"),1);			
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset1)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to check if PAL_Autotest_CheckHighSideSwRegulation could be performed ", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);		
		
		debugger_reset();	

		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_1242")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset3)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function PAL_Autotest_CheckHighSideSwRegulation", debugger_isCPUStoppedAtAddress(addressBP1), true);
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest3,CFGc_BP1Offset4)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function pal_u8HighSideSWRegStep_1", debugger_isCPUStoppedAtAddress(addressBP1), true);
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest4,CFGc_BP1Offset5)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function PMP_runGetHS1Level", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("read the variable value u16InternalAnalogSignal, corresponding to HighSide Switch Voltage", debugger_readMemory(CFGc_VariableAddress2, 1, "hex"), "00");		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest3,CFGc_BP1Offset6)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
		RESULT.ExpectTestResult("Setting breakpoint in order to stop in function pal_u8HighSideSWRegStep_1", debugger_isCPUStoppedAtAddress(addressBP1), true);
		CommentStep("The booster HW stage is activated by the execution if function ACTIVATE_BOOST_STAGE()")	
		RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true);		
		
		debugger_reset();

		CommentStep("TEST QUALIFICATION - ALV_EXT_TF_H_1243")		
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset1)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function PAL_Autotest_CheckHighSideSwRegulation", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("change the value of switch PAL_Cfg_AT_InternalData.u8HighSideSw_TestState, To force state machine to PAL_KU8_HIGH_SIDE_SW_REG_ALGO_STEP_2",debugger_writeMemory(CFGc_VariableAddress3,"02",1),true);
		RESULT.ExpectTestResult("read the value of switch PAL_Cfg_AT_InternalData.u8HighSideSw_TestState, it shall correspond to PAL_KU8_HIGH_SIDE_SW_REG_ALGO_STEP_2", debugger_readMemory(CFGc_VariableAddress3, 1, "int"), 2);
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest1,CFGc_BP1Offset7)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function PAL_Autotest_CheckHighSideSwRegulation", debugger_isCPUStoppedAtAddress(addressBP1), true);
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest5,CFGc_BP1Offset8)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function pal_u8HighSideSWRegStep_2", debugger_isCPUStoppedAtAddress(addressBP1), true);	
		addressBP1 = debugger_setRelativeFunctionBpAtLine(CFGc_FunctionToTest4,CFGc_BP1Offset5)[3] 
        RESULT.ExpectTestResult("Run application", debugger_run(), true);
        RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
        RESULT.ExpectTestResult("Setting breakpoint in order to stop in function PMP_runGetHS1Level", debugger_isCPUStoppedAtAddress(addressBP1), true);
		RESULT.ExpectTestResult("read the variable value u16InternalAnalogSignal, corresponding to HighSide Switch Voltage", debugger_readMemory(CFGc_VariableAddress2, 1, "hex"), "00");		
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