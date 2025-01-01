/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_357_CheckPowerSupplyUV_Running
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_357
Description of the requirement:
ALV_EXT_TF_H_357: This autotest shall be performed periodically, every 100 ms (without Pre²Tensionning on going), in both startup autotest phase and running autotest phase.
ARCH_SW_ATM_0214: ATM_runMainFunction shall call the PMP_cbk_CheckPowerSupplyOV function. 
                  Time slot: #4.2 (3.1 in code starts from 0)
                  Call period: 100ms
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

/* Mandatory constants for test scripts */
const cENV_NON_INITIALIZED = "NO_INIT";
const cENV_NOK = false;
const cException_Catched = true;

/* WinIDEA intialization options */
const CFGc_FlashMode: String = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String = "RunOff";    /* [RunOn, RunOff] */

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50";

/* Parameters used by the period check function */
/* Function name used to set the breakpoint */
const CFGc_FunctionName = "PMP_cbk_CheckPowerSupplyUV";

/* Breakpoint point offset */
const CFGc_OffsetFunction = 0;

/* Auto-test period */
const CFGc_FunctionPeriod = 100;  /* 100ms */

/* Maximum tolerance allowed for the period check */
const CFGc_PeriodTolerance = 10; /* 10% */

/* Number of cycle used to check the function period */
const CFGc_NbCycleVerify = 4;

/* Parameter used in the LIB function in order to get more information */
const CFGc_Verbose = false;

/* Name of the ATM index variable (Cyclic list or startup list)  */
const CFGc_ListIndex = "u8CyclicTestIndex";

/* Auto-test position in a timeslot */
const CFGc_ATPosition = 1; /* Auto-test position starts at 0. A position N in architecture document represents a position N-1 in the code */

/* Delay to let ECU wakeup */
const CFGc_WakeupDelay = 5000;

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
var vRetFunction;
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
    /****** WARNING : check optionnal parameter of the next function :it's very IMPORTANT ***********/
    vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply(CFGc_FlashMode, CFGc_ResetMode, CFGc_RunMode, CFGc_MinCurrentToRunTest);
    
    if(vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK)
    {
            
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
            RESULT.ExpectTestResult( CFGc_FunctionName + " correctly called every " + CFGc_FunctionPeriod + "ms" ,
              PP4G_LibInteg_CheckPeriodicalFunctionATM(CFGc_FunctionName, CFGc_OffsetFunction, CFGc_FunctionPeriod, CFGc_PeriodTolerance, CFGc_NbCycleVerify, CFGc_Verbose, CFGc_ListIndex, CFGc_ATPosition ),
              true
            );
            /*------------------------------------------------------------------------------
                                        RESET CONFIGURATION TEST
            ------------------------------------------------------------------------------*/
            RESULT.ExpectTestResult("Init Environment test", SwDevLib_InitBenchEnvironment(), cTEST_OK);
        }
        else
        {
            /*** Warn the tester that the test isn't executed ****/
            RESULT.InsertComment("Tests is not executed : configuration of test failed")
        }
    }
    else 
    {
        winIDEAWorkspace_closeDiscard();
        RESULT.ExpectTestResult("Test failed about environment initialization failed", false, true);
    }

    /*------------------------------------------------------------------------------
                            DEINITIALIZATION ENVIRONMENT
    ------------------------------------------------------------------------------*/
    // "winIDEAWorkspace_closeDiscard()" function close the winIdea workspace (debugger)
    // RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK );
}
catch(exError)
{
    RESULT.ExpectTestResult("Test failed about exception occurs :" + exError, cException_Catched, false);
    RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}