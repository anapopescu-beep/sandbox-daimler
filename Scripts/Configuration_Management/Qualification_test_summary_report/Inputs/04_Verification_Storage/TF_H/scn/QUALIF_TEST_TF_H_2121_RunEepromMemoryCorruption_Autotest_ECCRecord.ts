/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_2121_RunEepromMemoryCorruption_Autotest_ECCRecord
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_2121
Description of the requirement:
ECC DFLASH counter block shall be recorded in the EEPROM during the shutdown.

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



const cNameFunction1: String = "MIC_cbk_RunEepromMemoryCorruption_Autotest";
const cNameFunction2: String = "MIC_Autotest_RunEepromMemoryCorruption";
const cNameFunction3: String = "NvM_ASR42_Rte_SetRamBlockStatus";


/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/


/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Boolean used to check if the test is succesful */
var bRetFunction: Boolean = false;
var addressBP1;
var addressBP2;
var addressBP3;
var addressBP4;
var addressBP5;
var stackTrace;

var sintOffsetBP1: Number = 0;
var sintOffsetBP2: Number = 17; //  KU32_ECC_E2P_MASK == (u32ResetCause & KU32_ECC_E2P_MASK)
var sintOffsetBP3: Number = 27; //  Rte_Call_pclNvmServicesEccCounters_SetRamBlockStatus


/*Read register*/
var CFGc_ReadRegisterName: String = "R0";

var temp_init;
var temp;  

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
   vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOff", "RunOff", "5");
   if(vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK)
   {
      /*------------------------------------------------------------------------------
                                 EXECUTION TEST
      ------------------------------------------------------------------------------*/
      debugger_AttachFunctionDisable();

      RESULT.ExpectTestResult("Delete all breakpoints", debugger_deleteAllBreakpoints(), true);
      addressBP1 = debugger_setRelativeFunctionBpAtLine(cNameFunction1, sintOffsetBP1);
      RESULT.ExpectTestResult("Run application", debugger_run(), true);
      RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
      RESULT.ExpectTestResult(cNameFunction1+" function is reached", debugger_isCPUstoppedAtFunction(cNameFunction1), true);

      RESULT.ExpectTestResult("Delete all breakpoints", debugger_deleteAllBreakpoints(), true);
      addressBP2 = debugger_setRelativeFunctionBpAtLine(cNameFunction2, sintOffsetBP2);
      RESULT.ExpectTestResult("Run application", debugger_run(), true);
      RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
      stackTrace = debugger_GetStackTrace(2);
      RESULT.ExpectTestResult("Check that the top level of the call trace is the expected function", stackTrace[1].getFunction().getName(), cNameFunction1);
      MessageBox.Show("Change the value u32ResetCause of to 32768", "pause");
	  
	  
	  MessageBox.Show("Do a step until NvM_ASR42_Rte_SetRamBlockStatus is reached");
			  
	  var resultMessageBox = MessageBox.Show(" Is NvM_ASR42_Rte_SetRamBlockStatus reached ??", "yes/No", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
	  RESULT.InsertComment(resultMessageBox);
			  
	  if (resultMessageBox == 7)
	  {
		  RESULT.ExpectTestResult("NvM_ASR42_Rte_SetRamBlockStatus is not reached",6,7);		
	  }	
	  else 
	  {
		  RESULT.ExpectTestResult("NvM_ASR42_Rte_SetRamBlockStatus is reached",6,6);   	
	  }   


      /*------------------------------------------------------------------------------
                              DEINITIALIZATION ENVIRONMENT
      ------------------------------------------------------------------------------*/
      
      RESULT.ExpectTestResult("Reset the debugger",
         debugger_reset(),
         cTEST_OK
      );

        // "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger). This function is mandatory
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