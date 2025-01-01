/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_I_562_FlsEccIdentifier
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_I_562
Description of the requirement:
The Fls ECC error shall have the id 0x13
************************************************************************************************
Equipment: PP4G Mockup + iSYSTEM IC5000 + power supply + CAN case
Test Notes: Some Comments..
Full Automation: Yes
Global Result Assignment: Neeva
************************************************************************************************

/*------------------------------------------------------------------------------
                            LIBRARY IMPORT
 ------------------------------------------------------------------------------*/
/* USE RELATIVE PATH TO IMPORT A SBE LIBRARY */
CALL(\..\..\ProjectLib_Development\SBE_Configuration.ts);
/* USE RELATIVE PATH TO IMPORT A CONFIGURATION FILE */
/*------------------------------------------------------------------------------
                               CONSTANTS
------------------------------------------------------------------------------*/
/* Mandatory constants */
const cTEST_OK             = true; 
const cTEST_NOK            = false;
const cENV_NON_INITIALIZED = "NO_INIT";
const cENV_NOK             = false;
const cEXCEPTION_CATCHED   = true;
const cNameFunction1: String = "MIC_Autotest_RunPFlashMemoryCorruption";
const cNameFunction2: String = "atm_SetDemEvent";
const cNameFunction3: String = "MIC_Init";
const cNameFunction4: String = "MIC_LLD_GetFaultAddress";
const cNameRegister1: String = "GEIEN";
const cRegistreAddress1: int = 1073844484; /* 0x40019104 */
const cRegistreAddress2: int = 1073844224; /* 0x40019000 */
const cRegistreAddress3: int = 1073844228; /* 0x40019004 */
const cRegistreAddress4: Number = 3758148904; /* 0xE000ED28 */
const cValue1RegistreR0: int = 268435456; /* 0x10000000 */
const cValue2RegistreR0: int = 143360; /* 0x00023000 */
const cValueStackOverFlow: int = 20000000; /* 0x20000000 */
/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/

var sRequest;
var sResponse;
var bRetFunction: Boolean;
var vRetFunction = null; 
var addressBP1;
var addressBP2;
var addressBP3;
var addressBP4;
/*------------------------------------------------------------------------------
                                GLOBAL FUNCTIONS
 ------------------------------------------------------------------------------*/

/********************************************************************* 
* @name : PP4G_ExecuteTestIntegrationOrualification
* @brief : This function executes a specific test
* param : aInformationAutoliv : Use to define the tempate
* @return : boolean result of test
***********************************************************************/

/*------------------------------------------------------------------------------
                                 Test Core
------------------------------------------------------------------------------*/
/***************************************************************************************/
/*         The TRY and CATCH words are mandatory to catch every error of test           /
/***************************************************************************************/
try 
{
    /*RESULT.InterpretEqualResult("Remove OpenCircuit on channel "+29, FIB.RemoveFault(29), "Remove fault performed OK on channel " + 29);
    Thread.Sleep(1000);
    for(var count2=1; count2<=3; count2++)
    {
        RESULT.InterpretEqualResult("Reset channel "+count2, FIB.RestartBoard(count2), "Restart board " + count2 + " performed OK.")
        Thread.Sleep(100)
    }
    Thread.Sleep(100);*/
   /*------------------------------------------------------------------------------
                            ENVIRONMENT INITIALIZATION
   ------------------------------------------------------------------------------*/

   /* WARNING : check optionnal parameters of the next function :it's very IMPORTANT */
   /* This function is parametrable see Utilities_Lib.ts library located on S:\Tools\ARIA\Config\Neeva_Configuration\TestEnvironment_Automation\GenericLib_Development */

   vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply("FlashOn", "ResetOff", "RunOff", "5");
  
 
   if (vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK) 
   {
      /*------------------------------------------------------------------------------
                                    TEST CONFIGURATION
      ------------------------------------------------------------------------------*/
      /*------------------------------------------------------------------------------
                                    TEST EXECUTION
      ------------------------------------------------------------------------------*/
      /*debugger_AttachFunctionDisable();*/
   
    
      /* Set a breakpoint in the function MIC_HardFaultException */ 
      CommentStep(" Qualify the autotest PFlash_ECC" )
          
      RESULT.ExpectTestResult("Delete all breakpoints", debugger_deleteAllBreakpoints(), true);
      addressBP1 = debugger_setRelativeFunctionBpAtLine(cNameFunction1, 12)[3]
      RESULT.ExpectTestResult("Run application", debugger_run(), true);
      RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
      RESULT.ExpectTestResult("MIC_Autotest_RunPFlashMemoryCorruptionfunction is reached", debugger_isCPUStoppedAtAddress(addressBP1), true);
      
/* Set 512 to u32ResetCause to qualify the event FLS_ECC */
      RESULT.ExpectTestResult("Qualify the autotest PFLASHECC", debugger_writeMemory(536876224, "0002", 2), true);
      
      addressBP2 = debugger_setRelativeFunctionBpAtLine(cNameFunction1, 15)[3]
      RESULT.ExpectTestResult("Run application", debugger_run(), true);
      RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
      RESULT.ExpectTestResult("Verify that the ECC_FLASH event is qualify", debugger_isCPUStoppedAtAddress(addressBP2), true);
   
    /* Set Breakpoint to atm_SetDemEvent to see the qualification of event with the matching ID */
      addressBP2 = debugger_setRelativeFunctionBpAtLine(cNameFunction2, 45)[3]
      RESULT.ExpectTestResult("Run application", debugger_run(), true);
      RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);
      RESULT.ExpectTestResult("Reached the function atm_SetDemEvent ", debugger_isCPUStoppedAtAddress(addressBP2), true);
   
      RESULT.ExpectTestResult("The event ID 19 (0x13) PFLASHECC is qualified", debugger_readMemory(536846391, 1, "hex"), "27");          
      /*winIDEAWorkspace_closeDiscard();*/

   }  
}
        
catch (exError) 
{
   RESULT.ExpectTestResult("Test failed about exception occurs :" + exError, cEXCEPTION_CATCHED, cTEST_NOK);
  
   /*RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(),cTEST_OK);*/
}