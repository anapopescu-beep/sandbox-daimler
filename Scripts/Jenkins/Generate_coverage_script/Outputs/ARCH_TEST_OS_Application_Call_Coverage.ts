/***********************************AUTOLIV ELECTRONICS document******************************** 
Test case ID: PYTHON GENERATED COVERAGE SCRIPT 
Result Test: 
************************************************************************************************ 
Requirement under test: NONE 
Description of the requirement: NONE 
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
/* CALL PRECONDITIONS CONFIG SCRIPT ( if exist ) */ 

/*------------------------------------------------------------------------------ 
                                CONSTANTS 
------------------------------------------------------------------------------*/ 

/* Constant for the tests */ 
const cTEST_OK = true; 
const cTEST_NOK = false; 

/* Mandatory constants */ 
const cENV_NON_INITIALIZED = "NO_INIT";  
const cENV_NOK = false; 
const cException_Catched = true; 
const NO_CYCLE = 255; 

/* Power supply configuration for this test */ 
/* 5 means that a logical power supply is OK */ 
/* 50 means that a power supply which can support 40A shall be used */ 
const CFGc_MinCurrentToRunTest: String = "50";  

/* WinIDEA intialization options */ 
const CFGc_FlashMode: String  = "FlashOn"; /* [FlashOn, FlashOff] */ 
const CFGc_ResetMode: String  = "ResetOn"; /* [ResetOn, ResetOff] */ 
const CFGc_RunMode: String    = "RunOn"; /* [RunOn, RunOff] */ 

/*------------------------------------------------------------------------------ 
                                VARIABLES 
------------------------------------------------------------------------------*/ 
/* Variable used to check the test initialization phase */ 
var vRetFunction = null; 
/* Boolean used to check if the test is successful */ 
var bRetFunction: Boolean = false; 
/* Variable for breakpoint result*/ 
var tRelativeBreakPointParam; 
/* Variable for offset of all functions */ 
var CFGc_FunctionOffsetToTest = 0; 
/* Variable for iterating in array list */ 
var iterating_functions_counter = 0 
/* Function name used to place a breakpoint */ 
var CFGc_CallingFunctionToTest_Array = [ 

/* Functions from ATM module */ 
"ATM_runMainFunction", 
"ATM_runGetTestResult", 
"ATM_Shutdown", 

/* Functions from AudiTr6_HardwareAspects.do module */ 

/* Functions from BFD module */ 
"BFD_Init", 
"BFD_GetCanResponse", 

/* Functions from BFE module */ 
"BFS", 
"BFE_runScheduleStep", 
"BFE_runExecuteStandardSteps", 
"BFE_runExecuteHighPowerStep", 
"BFE_runExecuteEmergencyBrakingSequence", 
"BFE_runResetMotorStageStatus", 

/* Functions from CIL module */ 
"CIL_runInit", 
"CIL_runCANToAppli", 
"CIL_runGetReleaseAllowed", 
"CIL_runAppliToCAN", 
"CIL_runManageMeasurementFrame", 
"CIL_CbkRxAck_RGS_Anf_01", 
"CIL_CbkRxTout_RGS_Anf_01", 
"CIL_Autotest_CheckTimeout_RGS_Anf_01", 
"CIL_runDetermineEcuLocation", 
"CIL_runGetActivationRequest", 
"CIL_runIsSetUnterSpannung", 
"CIL_runIsHWErrorPresent", 
"CIL_CbkRxAck_NVEM_12", 
"CIL_CbkRxTout_NVEM_12", 
"CIL_PduReceiveCallout", 
"CIL_CbkRxAck_ClampControl_01", 
"CIL_CheckBusCommunication_Timeout", 
"CIL_GetShutdownLevel_Status", 
"CIL_GetClampControl_01_KST_KL_15_Status", 
"CIL_runIsSetKeineStraffung", 

/* Functions from EOL module */ 
"EOL_Init", 
"EOL_runMainFunction", 
"EOL_cbk_CheckProductEndOfLifeLowForce", 
"EOL_cbk_CheckProductEndOfLifeComfort", 
"EOL_cbk_CheckProductEndOfLifeHapticWarning", 

/* Functions from ERH module */ 
"ERR_HIGH_FORCE_END_OF_LIFE", 
"ERH_Init", 
"ERH_StoreEverQualifiedAECsToNVP", 
"ERH_runGetAecStatus", 
"ERH_runSetAecEvent", 
"operation", 
"ERH_runGetAecQualificationCount", 

/* Functions from MMG module */ 
"MMG_Init", 
"MMG_runCheckModeStatus", 
"MMG_runUpdateModeStatus", 
"MMG_runManageModeDelays", 

/* Functions from NmIf module */ 
"NM_RGS_VL_SNI_10", 
"NmIf_MainFunction", 
"Nm_StateChangeNotificationCallout", 
"Nm_StateChangeNotification", 

/* Functions from SCM module */ 
"SCM_runManageSystemContext", 
"SCM_runKL30bgSupervision", 
"SCM_runMonitoreExecutedCycle", 
"SCM_runWriteSystemContextShutdown", 
"SCM_runRestoreSystemContext", 
"SCM_runGetLastTensioningState", 
"SCM_runGetLastMonitoredCycle", 
"SCM_runCBNvmJobEndSystemContextB0", 
"SCM_runCBNvmJobEndSystemContextB1", 
"SCM_runCBNvmJobEndSystemContextB2", 
"SCM_runRestoreValueSystemContext"] 

/* Number of all functions to iterate */ 
var number_of_all_functions = 62; 

/* DEFINE FUNCTION TO CHECK IF PRECODINTIONS EXIST */ 
/*------------------------------------------------------------------------------ 
                                    Core Test 
------------------------------------------------------------------------------*/
try 
{ 
   /*------------------------------------------------------------------------------
                           INITIALIZATION ENVIRONMENT 
   ------------------------------------------------------------------------------*/ 
   /**** This function is parameterizable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/ 
   /****** WARNING : check optional parameter of the next function :its very IMPORTANT ***********/ 
   CommentStep("Initialize environment"); 
   vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply(CFGc_FlashMode, CFGc_ResetMode, CFGc_RunMode, CFGc_MinCurrentToRunTest); 
   if(vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK) 
   { 

       /*------------------------------------------------------------------------------ 
                              EXECUTION TEST 
      ------------------------------------------------------------------------------*/ 

      /* Clear all breakpoints */ 
      CommentStep("Clear all breakpoints"); 
      RESULT.ExpectTestResult("Delete all breakpoints",debugger_deleteAllBreakpoints(),true); 

      debugger_run(); 
      CommentStep("Wait ECU to wake up"); 
      Wait(5000); 

      RESULT.ExpectTestResult("Run application", debugger_run(), true); 
      sendCANDiagRequest("SOFT RESET", "0x11 0x03", "0x51 0x03"); 
      CommentStep("Wait ECU to wake up"); 
      waitFrameReception(); 

      /* CALL LIST OF FUNCTION TO TEST */ 
      for ( iterating_functions_counter = 0; iterating_functions_counter < number_of_all_functions; iterating_functions_counter++ ) 
      { 

         CommentStep("Place a breakpoint in the tested function: " + CFGc_CallingFunctionToTest_Array[iterating_functions_counter] );  
         tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_CallingFunctionToTest_Array[iterating_functions_counter], CFGc_FunctionOffsetToTest);  

         /* CALL PRECONDITIONS Function ( if preconditions ts config exist ) */ 

         RESULT.InsertComment("Check if the debugger is stopped on the correct function"); 
         RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);  
         RESULT.ExpectTestResult(CFGc_CallingFunctionToTest_Array[iterating_functions_counter] + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true); 

         RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true); 
         RESULT.ExpectTestResult("Reset the debugger", debugger_reset(), cTEST_OK ); 
         RESULT.ExpectTestResult("Run application", debugger_run(), true); 
         Wait(1000); 
       } 

      RESULT.InsertComment("100% call coverage achieved for configured scope!"); 
      /* Clear all breakpoints */ 
      CommentStep("Clear all breakpoints"); 
      RESULT.ExpectTestResult("Delete all breakpoints",debugger_deleteAllBreakpoints(),true); 
      /*------------------------------------------------------------------------------ 
                              DEINITIALIZATION ENVIRONMENT 
      ------------------------------------------------------------------------------*/ 
      RESULT.ExpectTestResult("Reset the debugger", debugger_reset(), cTEST_OK ); 

      RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK ); 
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
