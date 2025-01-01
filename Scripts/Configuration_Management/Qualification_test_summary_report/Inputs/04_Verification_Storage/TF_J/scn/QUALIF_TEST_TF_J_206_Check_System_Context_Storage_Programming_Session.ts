/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_J_206_Check_System_Context_Storage_Programming_Session
Result Test: 
************************************************************************************************
Requirement under test: TR6_EXT_TF_J_206
Description of the requirement: The system context shall be stored before opening bootloader session from application session.

Note: See TF_E: TR6_EXT_TF_E_7759
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
const cTEST_OK = true;                                 // Constant for tests returning OK
const cTEST_NOK = false;                               // Constant for tests returning NOK
const cENV_NON_INITIALIZED = "NO_INIT";                // Constant for non initialized environment
const cENV_NOK = false;                                // Mandatory constant
const cException_Catched = true;                       // Mandatory constant

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50"; 

/* WinIDEA initialization options */
const CFGc_FlashMode: String  = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String  = "ResetOn";   /* [ResetOn, ResetOff] */
const CFGc_RunMode: String    = "RunOff";    /* [RunOn, RunOff] */

/* Diagnostic Specific variables */
const iSupplierSecurityLevel: Number = 0x61;

/* CAN Communication Specific variables */
const iMeasurementFrameId: Number = 0x7C4;
const iMeasurementFrameCycleTime: Number = 5

const iStatusFrameId: Number = 0x3D8;
const iStatusFrameCycleTime: Number = 500

const iNMFrameId: Number = 0x1B00005E;
const iNMFrameCycleTime: Number = 200

/* AEC Specific variables */
const iKL30OvervoltageValue = 18;
const iKL30DefaultVoltageValue = 12;

const iKL30OffoltageValue = 5;

/* System Context Specific Variables */
const sSCM_Block0Address = "EE 1D 00 00";
const sSCM_Block1Address = "EE 1E 00 00";
const sSCM_Block2Address = "EE 1F 00 00";
            
const iDiagRequestTimeout = 15;

/* ignore 0x63 0x24 of positive response */
const iRMBA_DiagOffset = 5;
/* no of bytes in SCM structure */
const iSCM_SystemTimeByteNo = 4;
const iSCM_DeficiencyLevelByteNo = 4;
const iSCM_BatteryLossByteNo = 1;
const iSCM_LastCycleByteNo = 1;
const iSCM_eCPLByteNo = 1;

/* free dangling space */
const iDanglingSpace = 1;

var aSCM_SystemContext = [];

var bSCM_Block0Active = false
var bSCM_Block1Active = false
var bSCM_Block2Active = false

var currentSubstrOffset
var oldSubstrOffset

var iSCM_LastSCMBlock = 0;

var sAns_SCM_eCPL_Status = "";
var sAns_SCM_Deficiency_Level = "";
var sAns_SCM_System_Time = "";
var sAns_SCM_Battery_Loss_Status = "";
var sAns_SCM_Interrupted_Cycle = "";

var bSCM_Block_Invalid = false;

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/
/* Variable used to check the test initialization phase */
var vRetFunction = null; 
/* Boolean used to check if the test is successful */
var bRetFunction: Boolean = false;
/* Variable containing the request */
var sRequest
/* Variable containing the answer */
var sResponse
/* Variable for breakpoint result*/
var bIsBPset
/* Variable for breakpoint timeout */
var sintBPTimeout: Number = 2000;
/* Variable for default wait period */
var sintDefaultWait: Number = 250;
/* Variable for default init period */
var sintWaitInit: Number = 2250;
/* Variable for breakpoint result*/
var bBreakPointResult;
var bWriteVariableResult: Boolean = false;
var bReadVariableResult: Boolean = false;
var iReadVariableValue: Number = 0;
var tRelativeBreakPointParam = [];
var sBPDescription;
var i;

/*------------------------------------------------------------------------------
                                    Function definition
------------------------------------------------------------------------------*/
function getSubStrByteNo(byteNo)
{
	return ((byteNo*4)+(byteNo-1))
}

/*------------------------------------------------------------------------------
                                    Core Test
------------------------------------------------------------------------------*/
try
{
   /*------------------------------------------------------------------------------
                           INITIALIZATION ENVIRONMENT
   ------------------------------------------------------------------------------*/
   /**** This function is parameterizable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/

   /****** WARNING : check optional parameter of the next function :it's very IMPORTANT ***********/
   CommentStep("Initialize environment");
   vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply(CFGc_FlashMode, CFGc_ResetMode, CFGc_RunMode, CFGc_MinCurrentToRunTest);
   
   if(vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK)
   {
      /*------------------------------------------------------------------------------
                              EXECUTION TEST
      ------------------------------------------------------------------------------*/
      CommentStep("Clear all breakpoints");
      RESULT.ExpectTestResult("Delete all breakpoints",
         debugger_deleteAllBreakpoints(),
         true
      );
      
      CommentStep("Run the debugger")
      debugger_run();
      
      Wait(sintWaitInit);
      
      CommentStep("Check supplier session availability");
      sendCANDiagRequest("Enter supplier session", sReq_SupplierSession, sAns_SupplierSession);

      CommentStep("Check supplier security level");
      requestCANSecurityAccess(iSupplierSecurityLevel);

      CommentStep("Unlocking ECU");
      sendCANDiagRequest("Unlocking ECU", sReq_UnlockECU, sAns_UnlockECU);
      Thread.Sleep(sintDefaultWait);
      
      CommentStep("Issue erase all routine");
      sendCANDiagRequest("Clear warm reset counter", sReq_StartEraseAll, sAns_StartEraseAll);
      
      CommentStep("Write measurement frame configuration");
      sendCANDiagRequest("Write measurement frame configuration", "0x2E 0xFE 0xFF 0x01 0x00 0x00 0x01", "0x6E 0xFE 0xFF");
      Thread.Sleep(sintDefaultWait);

      CommentStep("Lock ECU");
      sendCANDiagRequest("Lock ECU", sReq_LockECU, sAns_LockECU);
      Thread.Sleep(sintDefaultWait);

      CommentStep("Simulate three power cycles to save SCM")
      
      SwDevLib_PS1_SetVoltage(iKL30OffoltageValue);
      Wait(sintWaitInit);
      SwDevLib_PS1_SetVoltage(iKL30DefaultVoltageValue);
      Wait(sintWaitInit);
      
      debugger_run();
      
      SwDevLib_PS1_SetVoltage(iKL30OffoltageValue);
      Wait(sintWaitInit);
      SwDevLib_PS1_SetVoltage(iKL30DefaultVoltageValue);
      Wait(sintWaitInit);
      
      debugger_run();
      
      SwDevLib_PS1_SetVoltage(iKL30OffoltageValue);     
      Wait(sintWaitInit);
      SwDevLib_PS1_SetVoltage(iKL30DefaultVoltageValue);      
      Wait(sintWaitInit);
      
      debugger_run();
      
      /* Set preconditions */
      SetTriggeringPrecond("PRECRASH_0");

      /* Start the PRE_CRASH_0 cycle */
      LaunchMasterBeltProfile("PRECRASH_0");
      
      Wait(5000);
      
      /* Set release allowed conditions */
      SetReleaseCondition("ALLOWED");
      
      /* Remove belt profile activation */
      RemoveMasterBeltProfile("PRECRASH_0");
      
      Wait(5000);
      
      CommentStep("Transition through Bootloader")
      
      sendCANDiagRequest("Send extended request", sReq_ExtendedSession, sAns_ExtendedSession);
      
      sendCANDiagRequest("Send programming request", sReq_ProgrammingSession, sAns_ProgrammingSession);
      
      Wait(sintWaitInit);
      
      sendCANDiagRequest("Send default session request", sReq_DefaultSession, sAns_DefaultSession);
      
      Wait(sintWaitInit);
      
      sendCANDiagRequest("Enter supplier session", sReq_SupplierSession, sAns_SupplierSession);

      requestCANSecurityAccess(iSupplierSecurityLevel);
            
      sResponse = CAN.SendDiagByValues("23 24 " + sSCM_Block0Address + " 00 0C")
      RESULT.InsertComment(sResponse)
      if (sResponse[1].Split(" ")[0] != "0x7F")
      {
         bSCM_Block0Active = true
         aSCM_SystemContext[0] = sResponse[1];
      }

      sResponse = CAN.SendDiagByValues("23 24 " + sSCM_Block1Address + " 00 0C")
      RESULT.InsertComment(sResponse)
      if (sResponse[1].Split(" ")[0] != "0x7F")
      {
         bSCM_Block1Active = true
         aSCM_SystemContext[1] = sResponse[1];
      }

      sResponse = CAN.SendDiagByValues("23 24 " + sSCM_Block2Address + " 00 0C")
      RESULT.InsertComment(sResponse)
      if (sResponse[1].Split(" ")[0] != "0x7F")
      {
         bSCM_Block2Active = true
         aSCM_SystemContext[2] = sResponse[1];
      }

      if (bSCM_Block0Active == false)
      {
         RESULT.InsertComment("Block2 was the last block recorded")
         iSCM_LastSCMBlock = 2;
      }
      else if (bSCM_Block1Active == false)
      {
         RESULT.InsertComment("Block0 was the last block recorded")
         iSCM_LastSCMBlock = 0;
      }
      else if (bSCM_Block2Active == false)
      {
         RESULT.InsertComment("Block1 was the last block recorded")
         iSCM_LastSCMBlock = 1;
      }
      else
      {
         /* do nothing */
      }
      
       sAns_SCM_System_Time = "0x?? 0x?? 0x?? 0x??";
       sAns_SCM_Deficiency_Level = "0x?? 0x?? 0x?? 0x??";
       sAns_SCM_Battery_Loss_Status = "0x55";
       sAns_SCM_Interrupted_Cycle = "0xFF";
       sAns_SCM_eCPL_Status = "0x55";

      if (iSCM_LastSCMBlock == 0)
      {
         CommentStep("Block0");

         /* get 4 bytes from start of string */
         currentSubstrOffset = iRMBA_DiagOffset + getSubStrByteNo(iSCM_SystemTimeByteNo)
         // RESULT.InsertComment(aSCM_SystemContext[0].substring(iRMBA_DiagOffset, currentSubstrOffset));
         
         bSCM_Block_Invalid = false;
         
         for(i= 0; i < sAns_SCM_System_Time.Split(" ").length; i++)
         {
            if((sAns_SCM_System_Time.Split(" ")[i] != aSCM_SystemContext[0].substring(iRMBA_DiagOffset, currentSubstrOffset).Split(" ")[i]) && (sAns_SCM_System_Time.Split(" ")[i] != "0x??"))
            {
               bSCM_Block_Invalid = true;
            }
         }
         
         if (bSCM_Block_Invalid == false)
         {
            RESULT.LogCustomAction("system time", aSCM_SystemContext[0].substring(iRMBA_DiagOffset, currentSubstrOffset), sAns_SCM_System_Time, "Passed");
         }
         else
         {
            RESULT.LogCustomAction("system time", aSCM_SystemContext[0].substring(iRMBA_DiagOffset, currentSubstrOffset), sAns_SCM_System_Time, "Failed");
         }
         
         /* get next 4 bytes from old position */
         oldSubstrOffset = currentSubstrOffset + iDanglingSpace 
         currentSubstrOffset += getSubStrByteNo(iSCM_DeficiencyLevelByteNo) + iDanglingSpace
         // RESULT.InsertComment(aSCM_SystemContext[0].substring(oldSubstrOffset, currentSubstrOffset));
         
         bSCM_Block_Invalid = false;
         
         for(i= 0; i < sAns_SCM_Deficiency_Level.Split(" ").length; i++)
         {
            if((sAns_SCM_Deficiency_Level.Split(" ")[i] != aSCM_SystemContext[0].substring(oldSubstrOffset, currentSubstrOffset).Split(" ")[i]) && (sAns_SCM_Deficiency_Level.Split(" ")[i] != "0x??"))
            
            {
               bSCM_Block_Invalid = true;
            }
         }
         
         if (bSCM_Block_Invalid == false)
         {
            RESULT.LogCustomAction("deficiency level", aSCM_SystemContext[0].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_Deficiency_Level, "Passed");
         }
         else
         {
            RESULT.LogCustomAction("deficiency level", aSCM_SystemContext[0].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_Deficiency_Level, "Passed");
         }
         
         /* get next byte from old position */
         oldSubstrOffset = currentSubstrOffset + iDanglingSpace
         currentSubstrOffset += getSubStrByteNo(iSCM_BatteryLossByteNo) + iDanglingSpace
         // RESULT.InsertComment(aSCM_SystemContext[0].substring(oldSubstrOffset, currentSubstrOffset));
         RESULT.ExpectTestResult("battery loss", aSCM_SystemContext[0].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_Battery_Loss_Status);

         /* get next byte from old position */
         oldSubstrOffset = currentSubstrOffset + iDanglingSpace
         currentSubstrOffset += getSubStrByteNo(iSCM_LastCycleByteNo) + iDanglingSpace
         // RESULT.InsertComment(aSCM_SystemContext[0].substring(oldSubstrOffset, currentSubstrOffset));
         RESULT.ExpectTestResult("last interrupted cycle", aSCM_SystemContext[0].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_Interrupted_Cycle);

         /* get next byte from old position */
         oldSubstrOffset = currentSubstrOffset + iDanglingSpace
         currentSubstrOffset += getSubStrByteNo(iSCM_eCPLByteNo) + iDanglingSpace
         // RESULT.InsertComment(aSCM_SystemContext[0].substring(oldSubstrOffset, currentSubstrOffset));
         RESULT.ExpectTestResult("eCPL status", aSCM_SystemContext[0].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_eCPL_Status);
      }

      if (iSCM_LastSCMBlock == 1)
      {
         CommentStep("Block1");
            
         /* get 4 bytes from start of string */
         currentSubstrOffset = iRMBA_DiagOffset + getSubStrByteNo(iSCM_SystemTimeByteNo)
         // RESULT.InsertComment(aSCM_SystemContext[1].substring(iRMBA_DiagOffset, currentSubstrOffset));
         bSCM_Block_Invalid = false;
         
         for(i= 0; i < sAns_SCM_System_Time.Split(" ").length; i++)
         {
            if((sAns_SCM_System_Time.Split(" ")[i] != aSCM_SystemContext[1].substring(iRMBA_DiagOffset, currentSubstrOffset).Split(" ")[i]) && (sAns_SCM_System_Time.Split(" ")[i] != "0x??"))
            {
               bSCM_Block_Invalid = true;
            }
         }
         
         if (bSCM_Block_Invalid == false)
         {
            RESULT.LogCustomAction("system time", aSCM_SystemContext[1].substring(iRMBA_DiagOffset, currentSubstrOffset), sAns_SCM_System_Time, "Passed");
         }
         else
         {
            RESULT.LogCustomAction("system time", aSCM_SystemContext[1].substring(iRMBA_DiagOffset, currentSubstrOffset), sAns_SCM_System_Time, "Failed");
         }
         
         /* get next 4 bytes from old position */
         oldSubstrOffset = currentSubstrOffset + iDanglingSpace 
         currentSubstrOffset += getSubStrByteNo(iSCM_DeficiencyLevelByteNo) + iDanglingSpace
         // RESULT.InsertComment(aSCM_SystemContext[1].substring(oldSubstrOffset, currentSubstrOffset));
         bSCM_Block_Invalid = false;
         
         for(i= 0; i < sAns_SCM_Deficiency_Level.Split(" ").length; i++)
         {
            if((sAns_SCM_Deficiency_Level.Split(" ")[i] != aSCM_SystemContext[1].substring(oldSubstrOffset, currentSubstrOffset).Split(" ")[i]) && (sAns_SCM_Deficiency_Level.Split(" ")[i] != "0x??"))
            {
               bSCM_Block_Invalid = true;
            }
         }
         
         if (bSCM_Block_Invalid == false)
         {
            RESULT.LogCustomAction("deficiency level", aSCM_SystemContext[1].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_Deficiency_Level, "Passed");
         }
         else
         {
            RESULT.LogCustomAction("deficiency level", aSCM_SystemContext[1].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_Deficiency_Level, "Passed");
         }

         /* get next byte from old position */
         oldSubstrOffset = currentSubstrOffset + iDanglingSpace
         currentSubstrOffset += getSubStrByteNo(iSCM_BatteryLossByteNo) + iDanglingSpace
         // RESULT.InsertComment(aSCM_SystemContext[1].substring(oldSubstrOffset, currentSubstrOffset));
         RESULT.ExpectTestResult("battery loss", aSCM_SystemContext[1].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_Battery_Loss_Status);

         /* get next byte from old position */
         oldSubstrOffset = currentSubstrOffset + iDanglingSpace
         currentSubstrOffset += getSubStrByteNo(iSCM_LastCycleByteNo) + iDanglingSpace
         // RESULT.InsertComment(aSCM_SystemContext[1].substring(oldSubstrOffset, currentSubstrOffset));
         RESULT.ExpectTestResult("last interrupted cycle", aSCM_SystemContext[1].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_Interrupted_Cycle);

         /* get next byte from old position */
         oldSubstrOffset = currentSubstrOffset + iDanglingSpace
         currentSubstrOffset += getSubStrByteNo(iSCM_eCPLByteNo) + iDanglingSpace
         // RESULT.InsertComment(aSCM_SystemContext[1].substring(oldSubstrOffset, currentSubstrOffset));
         RESULT.ExpectTestResult("eCPL status", aSCM_SystemContext[1].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_eCPL_Status);
      }

      if (iSCM_LastSCMBlock == 2)
      {
         CommentStep("Block2");
         
         /* get 4 bytes from start of string */
         currentSubstrOffset = iRMBA_DiagOffset + getSubStrByteNo(iSCM_SystemTimeByteNo)
         // RESULT.InsertComment(aSCM_SystemContext[2].substring(iRMBA_DiagOffset, currentSubstrOffset));
         bSCM_Block_Invalid = false;
         
         for(i= 0; i < sAns_SCM_System_Time.Split(" ").length; i++)
         {
            if((sAns_SCM_System_Time.Split(" ")[i] != aSCM_SystemContext[2].substring(iRMBA_DiagOffset, currentSubstrOffset).Split(" ")[i])  || (sAns_SCM_System_Time.Split(" ")[i] != "0x??"))
            {
               bSCM_Block_Invalid = true;
            }
         }
         
         if (bSCM_Block_Invalid == false)
         {
            RESULT.LogCustomAction("system time", aSCM_SystemContext[2].substring(iRMBA_DiagOffset, currentSubstrOffset), sAns_SCM_System_Time, "Passed");
         }
         else
         {
            RESULT.LogCustomAction("system time", aSCM_SystemContext[2].substring(iRMBA_DiagOffset, currentSubstrOffset), sAns_SCM_System_Time, "Failed");
         }
         
         /* get next 4 bytes from old position */
         oldSubstrOffset = currentSubstrOffset + iDanglingSpace 
         currentSubstrOffset += getSubStrByteNo(iSCM_DeficiencyLevelByteNo) + iDanglingSpace
         // RESULT.InsertComment(aSCM_SystemContext[2].substring(oldSubstrOffset, currentSubstrOffset));
         
         bSCM_Block_Invalid = false;
         
         for(i= 0; i < sAns_SCM_Deficiency_Level.Split(" ").length; i++)
         {
            if((sAns_SCM_Deficiency_Level.Split(" ")[i] != aSCM_SystemContext[2].substring(oldSubstrOffset, currentSubstrOffset).Split(" ")[i])  || (sAns_SCM_Deficiency_Level.Split(" ")[i] != "0x??"))
            {
               bSCM_Block_Invalid = true;
            }
         }
         
         if (bSCM_Block_Invalid == false)
         {
            RESULT.LogCustomAction("deficiency level", aSCM_SystemContext[2].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_Deficiency_Level, "Passed");
         }
         else
         {
            RESULT.LogCustomAction("deficiency level", aSCM_SystemContext[2].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_Deficiency_Level, "Passed");
         }
         
         /* get next byte from old position */
         oldSubstrOffset = currentSubstrOffset + iDanglingSpace
         currentSubstrOffset += getSubStrByteNo(iSCM_BatteryLossByteNo) + iDanglingSpace
         // RESULT.InsertComment(aSCM_SystemContext[2].substring(oldSubstrOffset, currentSubstrOffset));
         RESULT.ExpectTestResult("battery loss", aSCM_SystemContext[2].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_Battery_Loss_Status);

         /* get next byte from old position */
         oldSubstrOffset = currentSubstrOffset + iDanglingSpace
         currentSubstrOffset += getSubStrByteNo(iSCM_LastCycleByteNo) + iDanglingSpace
         // RESULT.InsertComment(aSCM_SystemContext[2].substring(oldSubstrOffset, currentSubstrOffset));
         RESULT.ExpectTestResult("last interrupted cycle", aSCM_SystemContext[2].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_Interrupted_Cycle);

         /* get next byte from old position */
         oldSubstrOffset = currentSubstrOffset + iDanglingSpace
         currentSubstrOffset += getSubStrByteNo(iSCM_eCPLByteNo) + iDanglingSpace
         // RESULT.InsertComment(aSCM_SystemContext[2].substring(oldSubstrOffset, currentSubstrOffset));
         RESULT.ExpectTestResult("eCPL status", aSCM_SystemContext[2].substring(oldSubstrOffset, currentSubstrOffset), sAns_SCM_eCPL_Status);
      }

           
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
      
      CommentStep("Set normal voltage conditions")
      SwDevLib_PS1_SetVoltage(iKL30DefaultVoltageValue);
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
   
   CommentStep("Set normal voltage conditions")
   SwDevLib_PS1_SetVoltage(iKL30DefaultVoltageValue);
   
}