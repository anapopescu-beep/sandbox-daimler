/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_2127_CheckPowerSupplyOV_Running
Result Test:
************************************************************************************************
Requirement under test: TR6_EXT_TF_H_2127
Description of the requirement:
TR6_EXT_TF_H_2127: This autotest shall be performed periodically, every 10 ms, in both startup autotest phase and running autotest phase.
************************************************************************************************
Equipment: PP4G Mockup + iSYSTEM IC5000 + power supply + CAN case
Test Notes: Check auto-test configuration (Period / Timeslot / position)
Full Automation: Yes
Global Result Assignment: Neeva 
************************************************************************************************/

/*------------------------------------------------------------------------------
                                IMPORT LIBRARY
 ------------------------------------------------------------------------------*/
 /**** USE RELATIVE PATH FOR IMPORT LIBRARY ****/
CALL(/../../ProjectLib_Development/SBE_Configuration.ts);
CALL(/../../ProjectLib_Development/INTEG_LIB/PP4G_LIB_INTEG_ATM.ts);
 /*------------------------------------------------------------------------------
                                CONSTANTS
 ------------------------------------------------------------------------------*/
const cTEST_OK = true; // Constant for the tests
const cTest_NOK = false;
const cException_Catched = true; // MANDATORY CONSTANT FOR ALL TEST SCRIPTS

/* Parameters used by the period check function */
/* Function name used to set the breakpoint */
const CFGc_FunctionName = "PMP_cbk_CheckPowerSupplyOV";

/* Breakpoint point offset */
const CFGc_OffsetFunction = 0;

/* Auto-test period */
const CFGc_FunctionPeriod = 10;  /* 100ms */

/* Maximum tolerance allowed for the period check */
const CFGc_PeriodTolerance = 10; /* 10% */

/* Number of cycle used to check the function period */
const CFGc_NbCycleVerify = 4;

/* Parameter used in the LIB function in order to get more information */
const CFGc_Verbose = false;

/* Name of the ATM index variable (Cyclic list or startup list)  */
const CFGc_ListIndex = "u8CyclicTestIndex";

/* Auto-test position in a timeslot */
const CFGc_ATPosition = 2; /* Auto-test position starts at 0. A position N in architecture document represents a position N-1 in the code */

/* Delay to let ECU wakeup */
const CFGc_WakeupDelay = 5000;

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
var bRetFunction:boolean = true; // Boolean of function return 

/*------------------------------------------------------------------------------
                                GLOBAL FUNCTIONS
 ------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                                    Core Test
------------------------------------------------------------------------------*/

try
{
    /*------------------------------------------------------------------------------
                            INITIALIZATION ENVIRONMENT
    ------------------------------------------------------------------------------*/
    /**** This function is parametrable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/
    RESULT.ExpectTestResult("Init Environment test",
        SwDevLib_InitBenchEnvironment(),
        true
    );
    /*------------------------------------------------------------------------------
                                 CONFIGURATION TEST
    ------------------------------------------------------------------------------*/

    CommentStep("Lets ECU wakeup and enter ATM running phase");
    Wait(CFGc_WakeupDelay);
   
    /*------------------------------------------------------------------------------
                                   EXECUTION TEST
    ------------------------------------------------------------------------------*/
    if(cTEST_OK == bRetFunction)
    {
        /*** Call function of test ***/
		CommentStep("Set a breakpoint in PMP_cbk_CheckPowerSupplyOV");
        RESULT.ExpectTestResult( CFGc_FunctionName + " correctly called every " + CFGc_FunctionPeriod + "ms" ,
		  PP4G_LibInteg_CheckPeriodicalFunctionATM(CFGc_FunctionName, CFGc_OffsetFunction, CFGc_FunctionPeriod, CFGc_PeriodTolerance, CFGc_NbCycleVerify, CFGc_Verbose, CFGc_ListIndex, CFGc_ATPosition ),
		  true
        );
		ResultStep("PMP_cbk_CheckPowerSupplyOV it's test periodically, every 10 ms, in both startup autotest phase and running autotest phase, TEST OK","PMP_cbk_CheckPowerSupplyOV it's test periodically, every 10 ms, in both startup autotest phase and running autotest phase, TEST OK");
        
      /*------------------------------------------------------------------------------
                              DEINITIALIZATION ENVIRONMENT
      ------------------------------------------------------------------------------*/
      RESULT.ExpectTestResult("Reset the debugger",
         debugger_reset(),
         cTEST_OK
      );

      /* "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger). This function is mandatory */
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

   CommentStep("Close test environment");
   RESULT.ExpectTestResult("Close environment test",
      winIDEAWorkspace_closeDiscard(),
      cTEST_OK
   );
}