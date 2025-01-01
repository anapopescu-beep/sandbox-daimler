/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_2128_CheckPowerSupplyUV_Startup
Result Test:
************************************************************************************************
Requirement under test: TR6_EXT_TF_H_2128
Description of the requirement: 
TR6_EXT_TF_H_2128: This autotest shall be performed periodically, every 10 ms (without Pre²Tensionning on going), in both startup autotest phase and running autotest phase.
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
const cTEST_OK = true;/* Constant for the tests */
const cTest_NOK = false;
const cException_Catched = true;/* MANDATORY CONSTANT FOR ALL TEST SCRIPTS */

/* Parameters used by the period check function */
/* Function name used to set the breakpoint */
const CFGc_FunctionName = "PMP_cbk_CheckPowerSupplyUV";

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
const CFGc_ATPosition = 1; /* Auto-test position starts at 0. A position N in architecture document represents a position N-1 in the code */

/* Delay to let ECU wakeup */
const CFGc_WakeupDelay = 5000;

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
var bRetFunction:boolean = true;// Boolean of function return 

/*------------------------------------------------------------------------------
                                GLOBAL FUNCTIONS
 ------------------------------------------------------------------------------*/
/*********************************************************************
* @name : PP4G_LibQualif_CheckPeriodicalFunctionATM_AtStartup(strFunctionNameBreakpoint,sintOffsetFunction,sintPeriodicalFunction,sintTolerantPeriod)
*
* @brief : This function verifies the periodicity of one auto-test executed by ATM scheduler at startup
*
* param : strFunctionNameBreakpoint : function name of the breakpoint
*         sintOffsetFunction : offset in function breakpoint
*         sintPeriodicalFunction : period of the function
*         sintTolerantPeriod :tolerance of period
*         sintNbCycleVerify : Number of call function
*         bVerbose : if true insert comments in the result file
*         sintTestIndexVarName : Name of ATM variable index list
*         sintATPosition : Expected call index
*
* @return : The result of the periodical verification (true or false:boolean)
***********************************************************************/
function PP4G_LibQualif_CheckPeriodicalFunctionATM_AtStartup(
    strFunctionNameBreakpoint: String,
    sintOffsetFunction: int,
    sintPeriodicalFunction: int,
    sintTolerantPeriod: int,
    sintNbCycleVerify: int,
    bVerbose: boolean,
    sintTestIndexVarName: String,
    sintATPosition: int)
{
    const cVAR_dec = "u16CurrentDecade";
    const cVAR_TimeSlotIndex = "u8CurrentTask";
    var strAddrBP: String = "";
    var sintPreviewTimeStamp: int = 0;
    var sintPeriodFctMin;
    var sintPeriodFctMax;
    var sintNbCycle: int = 0;
    var sintNBLoop: int = 0;
    var bRetFct: boolean = false;
    var InfoBreakp;
    var ToleranceOk;
    var diff;
    var sintTickMs: int = 0;
    var sintATMTestIndex: int = 0;

    /* Calculate expected range according to tolerance */
    if (sintPeriodicalFunction > 2)
    {
        sintPeriodicalFunction /= 10;
    }
    else
    {
        sintPeriodicalFunction = 0;
    }
    sintPeriodFctMin = sintPeriodicalFunction * (1 - (sintTolerantPeriod / 100));
    sintPeriodFctMax = sintPeriodicalFunction * (1 + (sintTolerantPeriod / 100));

    /* Set breakpoint */
    InfoBreakp = debugger_setRelativeFunctionBpAtLine(strFunctionNameBreakpoint, sintOffsetFunction);

    if (InfoBreakp[0])
    {
        /* Get adress of breakpoint */
        strAddrBP = InfoBreakp[3];
        bRetFct = true;
    }
    else
    {
        bRetFct = false;
    }
    /* if OK */
    if (bRetFct)
    {
        /* run debugger */
        bRetFct = debugger_run();
    }
    /* while no error and number of loop < sintNbCycleVerify */
    do {
        /* Wait 5s or stop debugger at breakpoint */
        bRetFct = debugger_waitWhileRunning(5000);
        if (bRetFct)
        {
            /* Verify debugger stop at specific breakpoint */
            var ResultBreakpoint = debugger_isCPUStoppedAtBP();
            if (ResultBreakpoint[0])
            {
                /* Verify if the right breakpoint */
                if (parseInt(ResultBreakpoint[1], 16) == parseInt(strAddrBP, 16))
                {
                    /* Compute diff between call */
                    sintPreviewTimeStamp = sintTickMs;
                    sintTickMs = debugger_readVariable(cVAR_dec, "uint16", 0, "int");

                    if (bVerbose == true)
                    {
                        RESULT.InsertComment("sintPreviewTimeStamp = " + sintPreviewTimeStamp);
                        RESULT.InsertComment("sintTickMs = " + sintTickMs);
                    }

                    /* The scheduler only counts from 0 to 255: so if (previous time > current time) there is an overflow --> add 255 to current time */
                    if (sintPreviewTimeStamp > sintTickMs)
                    {
                        diff = 60001 - sintPreviewTimeStamp + sintTickMs;
                    }
                    else
                    {
                        /* RESULT.InsertComment(" Current TimeStamp2 = " + f32CurrentTimeStamp); */
                        diff = sintTickMs - sintPreviewTimeStamp;

                    }

                    if (bVerbose == true)
                    {
                        RESULT.InsertComment("diff = " + diff);
                    }

                    /* Diff with tolerance in excluding first occurence */
                    if (0 != sintNBLoop)
                    {
                        /* Check tolerance */
                        ToleranceOk = (diff > sintPeriodFctMin) && (diff < sintPeriodFctMax);

                        if (bVerbose == true)
                        {
                            RESULT.ExpectTestResult("Test occurence " + sintNbCycle + " : Is the periodicity in the expected range ?",
                                ToleranceOk,
                                true);
                        }
                        if (ToleranceOk)
                        {
                            sintATMTestIndex = debugger_readVariable(sintTestIndexVarName, "uint8", 0, "int"),

                                /* Check ATM list number */
                                RESULT.ExpectTestResult("The test is expected to be played in timeslot: " + LIBc_ATM_StartupCyclicTests_MAP[sintATMTestIndex][LIBc_TestTimeslot_Index],
                                    debugger_readVariable(cVAR_TimeSlotIndex, "uint8", 0, "int"),
                                    LIBc_ATM_StartupCyclicTests_MAP[sintATMTestIndex][LIBc_TestTimeslot_Index]
                                );

                            /* Check ATM test index */
                            RESULT.ExpectTestResult("The test is expected to be executed at position: " + LIBc_ATM_StartupCyclicTests_MAP[sintATMTestIndex][LIBc_TestPosition_Index],
                                sintATPosition,
                                LIBc_ATM_StartupCyclicTests_MAP[sintATMTestIndex][LIBc_TestPosition_Index]
                                
                            );

                            CommentStep("Get CPU call trace")
                            var stack = debugger_GetStackTrace(2);
                            RESULT.ExpectTestResult("Check that the top level of the call trace is the expected function",
                                stack[0].getFunction().getName(),
                                LIBc_ATM_StartupCyclicTests_MAP[sintATMTestIndex][LIBc_TestName_Index]
                            );

                            RESULT.ExpectTestResult("Check that function has been called by the ATM_runMainFunction",
                                stack[3].getFunction().getName(),
                                "ATM_runMainFunction"
                            );

                            sintNbCycle++;
                        }
                        else {
                            /* Do not increment as periodicity is outside tolerance */
                        }
                    }
                    else {
                        /* Do nothing as first occurence */
                    }
                }
                else {
                    if (bVerbose == true)
                    {
                        RESULT.InsertComment(" Stopped at unexpected breakpoint !!! ");
                    }
                }
            }
            else
            {
                if (bVerbose == true)
                {
                    RESULT.InsertComment(" CPU running or Stopped by a cause different from a breakpoint !!! ");
                }
            }
        }
        /* Next loop */
        sintNBLoop++;
        bRetFct = debugger_run();
    } while (bRetFct && (sintNBLoop <= (sintNbCycleVerify)));

    /* Delete the specific breakpoint */
    Wait(2000);
    if (bVerbose == true)
    {
        RESULT.InsertComment(" strAddrBP = " + strAddrBP);
    }

    debugger_deleteAddressBreakpoint("0x" + strAddrBP);
    debugger_run();

    /* Test of periodical function execution */
    if ((sintNbCycleVerify) == sintNbCycle)
    {
        bRetFct = true;
    }
    else
    {
        bRetFct = false;
    }

    return bRetFct;
}

/*------------------------------------------------------------------------------
                                    Core Test
------------------------------------------------------------------------------*/

try
{
    /*------------------------------------------------------------------------------
                            INITIALIZATION ENVIRONMENT
    ------------------------------------------------------------------------------*/
    /**** This function is parametrable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/
    RESULT.ExpectTestResult("Init Environment test", SwDevLib_InitBenchEnvironment("FlashOn", "ResetOn", "RunOff"), true );
    
    /*------------------------------------------------------------------------------
                                 CONFIGURATION TEST
    ------------------------------------------------------------------------------*/

    /*------------------------------------------------------------------------------
                                   EXECUTION TEST
    ------------------------------------------------------------------------------*/
    if(cTEST_OK == bRetFunction)
    {
        /*** Call function of test ***/
		CommentStep("Set a breakpoint in PMP_cbk_CheckPowerSupplyUV");
        RESULT.ExpectTestResult(CFGc_FunctionName + " correctly called every " + CFGc_FunctionPeriod + "ms",
            PP4G_LibQualif_CheckPeriodicalFunctionATM_AtStartup(CFGc_FunctionName, CFGc_OffsetFunction, CFGc_FunctionPeriod, CFGc_PeriodTolerance, CFGc_NbCycleVerify, CFGc_Verbose, CFGc_ListIndex, CFGc_ATPosition),
            true
        );
		ResultStep("PMP_cbk_CheckPowerSupplyUV it's test periodically, every 10 ms, in both startup autotest phase and running autotest phase, TEST OK","PMP_cbk_CheckPowerSupplyUV it's test periodically, every 10 ms, in both startup autotest phase and running autotest phase, TEST OK");
        
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