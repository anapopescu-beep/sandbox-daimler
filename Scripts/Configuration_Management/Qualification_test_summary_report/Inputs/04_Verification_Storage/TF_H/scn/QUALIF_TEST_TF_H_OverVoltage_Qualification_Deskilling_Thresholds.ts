/***********************************AUTOLIV ELECTRONICS document********************************
Test case ID: QUALIF_TEST_TF_H_OverVoltage_Qualification_Deskilling_Thresholds
Result Test:
************************************************************************************************
Requirement under test: ALV_EXT_TF_H_328, ALV_EXT_TF_H_331
Description of the requirement: 
ALV_EXT_TF_H_328: - The Voltage threshold above which the [KL30_Vlevel] is in Over-Voltage [NVP_u16OverKL30QualificationThrs]
ALV_EXT_TF_E_331: - The Voltage threshold below which the [KL30_Vlevel] is back in normal range when Over_Voltage is qualified [NVP_u16OverKL30DeskillingThrs]
************************************************************************************************
Equipment: PowerSupply, CanCaseXL, MockUp
Test Notes: Test objective same as requirement objective
Full Automation: No
Global Result Assignment: Neeva
************************************************************************************************

/********************************************************************************/
/*                             Format test script                               */
/********************************************************************************/
/*------------------------------------------------------------------------------
                                IMPORT LIBRARY
 ------------------------------------------------------------------------------*/
  /**** USE RELATIVE PATH TO IMPORT A SBE LIBRARY ****/
CALL(/../../ProjectLib_Development/SBE_Configuration.ts);
 
 /*------------------------------------------------------------------------------
                                CONSTANTS
 ------------------------------------------------------------------------------*/

/* Constants used for the test results */
const cTEST_OK = true;// Constant for the tests
const cTest_NOK = false;

/* Mandatory constants for test scripts */
const cENV_NON_INITIALIZED = "NO_INIT";
const cENV_NOK = false;
const cException_Catched = true;

const cBPCpuStopIdx = 0;
const cBPAddrIdx = 1;
const cStackTopIdx = 0;

/* WinIDEA intialization options */
const CFGc_FlashMode: String = "FlashOn";   /* [FlashOn, FlashOff] */
const CFGc_ResetMode: String = "ResetOn";  /* [ResetOn, ResetOff] */
const CFGc_RunMode: String = "RunOff";    /* [RunOn, RunOff] */

/* Power supply configuration for this test */
/* 5 means that a logical power supply is OK */
/* 50 means that a power supply which can support 40A shall be used */
const CFGc_MinCurrentToRunTest: String = "50";

/* Delay to let ECU wakeup */
const CFGc_WakeupDelay = 10000;

// To manage power supply
const sPowerOffVoltageLevelSituation = "0"; // V
const sNominalVoltageLevelSituation = "11.8"; // V
const sUnderVoltageLevelSituation = "8.5"; // V
const sOverVoltageLevelSituation = "17.5"; // V
const sOverKL30QualificationThrs = "17.5"; // V
const sOverKL30DeskillingThrs = "17"; // V

/* Service configuration */
const CFGc_SupplierSession: String = "supplier";
const CFG_ReadAllAECsReq: String = "0x22 0xFE 0x00";
const CFG_ReadAllAECsResp: String = "0x62 0xFE 0x00 0x00 0x01 0x40 0x00 0x02 0x40 0x00 0x03 0x40 0x00 0x04 0x40 0x00 0x05 0x40 0x00 0x06 0x40 0x00 0x07 0x40 0x00 0x08 0x27 0x00 0x09 0x40 0x00 0x0A 0x40 0x00 0x0B 0x00 0x00 0x0C 0x40 0x00 0x0D 0x50 0x00 0x0E 0x40 0x00 0x0F 0x40 0x00 0x10 0x40 0x00 0x11 0x40 0x00 0x12 0x40 0x00 0x13 0x00 0x00 0x14 0x50 0x00 0x15 0x50 0x00 0x16 0x50 0x00 0x17 0x50 0x00 0x18 0x00 0x00 0x19 0x00 0x00 0x1A 0x50 0x00 0x1B 0x00 0x00 0x1C 0x00 0x00 0x1D 0x00 0x00 0x1E 0x00 0x00 0x1F 0x00 0x00 0x20 0x40 0x00 0x21 0x00 0x00 0x22 0x00 0x00 0x23 0x40 0x00 0x24 0x40 0x00 0x25 0x00 0x00 0x26 0x00 0x00 0x27 0x00 0x00 0x28 0x00 0x00 0x29 0x00";
const CFG_ReadAllAECsRespSplit: String = "0x62,0xFE,0x00,0x00,0x01,0x40,0x00,0x02,0x40,0x00,0x03,0x40,0x00,0x04,0x40,0x00,0x05,0x40,0x00,0x06,0x40,0x00,0x07,0x40,0x00,0x08,0x27,0x00,0x09,0x40,0x00,0x0A,0x40,0x00,0x0B,0x00,0x00,0x0C,0x40,0x00,0x0D,0x50,0x00,0x0E,0x40,0x00,0x0F,0x40,0x00,0x10,0x40,0x00,0x11,0x40,0x00,0x12,0x40,0x00,0x13,0x00,0x00,0x14,0x50,0x00,0x15,0x50,0x00,0x16,0x50,0x00,0x17,0x50,0x00,0x18,0x00,0x00,0x19,0x00,0x00,0x1A,0x50,0x00,0x1B,0x00,0x00,0x1C,0x00,0x00,0x1D,0x00,0x00,0x1E,0x00,0x00,0x1F,0x00,0x00,0x20,0x40,0x00,0x21,0x00,0x00,0x22,0x00,0x00,0x23,0x40,0x00,0x24,0x40,0x00,0x25,0x00,0x00,0x26,0x00,0x00,0x27,0x00,0x00,0x28,0x00,0x00,0x29,0x00"

const CFGc_AECStatus_Passed = "0x00";
const CFGc_AECStatus_Qualified = "0x27";
const CFGc_AECStatus_Disqualified = "0x26";

/* Path log file */
// const cLINTraceFile = "S:\\Tools\\ARIA\\Config\\Neeva_Configuration\\TestEnvironment_Automation\\Neeva_config\\LastOutput\\trace_trame"; // *****WARNING***** : Mount S:

/*------------------------------------------------------------------------------
                                GLOBAL VARIABLES
 ------------------------------------------------------------------------------*/

/* Variable used to check the test initialization phase */
var vRetFunction = null;

/* Boolean used to check if the test configuration is succesful */
var bRetFunction: Boolean = true;

/*------------------------------------------------------------------------------
                                GLOBAL FUNCTIONS
 ------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                                    Core Test
------------------------------------------------------------------------------*/

/***************************************************************************************/
/********* The TRY and CATCH words are mandatory to catch every error of test **********/
/***************************************************************************************/
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
		if (cTEST_OK == bRetFunction)
		{

			// Set NOMINAL voltage situation
			CommentStep(" *** SET NOMINAL VOLTAGE SITUATION *** ");
			//var voltageStatus = SwDevLib_PS1_SetVoltage(sNominalVoltageLevelSituation);
			//RESULT.ExpectTestResult("Set power supply at " + sNominalVoltageLevelSituation + " V", voltageStatus.toString().substr(0, 4), "0000");
			//RESULT.ExpectTestResult("Set power supply at " + sNominalVoltageLevelSituation + " V", (PS.SetVoltage(_sPS1Name, sNominalVoltageLevelSituation))[0], "0000");
			MessageBox.Show("Set power supply at " + sNominalVoltageLevelSituation + " V");
			var resultMessageBox = MessageBox.Show(" Is power supply set at " + sNominalVoltageLevelSituation + " V ?", "Power supply voltage",
				MessageBoxButtons.YesNo, MessageBoxIcon.Question ); 
			Wait(CFGc_WakeupDelay);

			if (resultMessageBox == 6) // If you click Yes => resultMessageBox = 6      If you click No => resultMessageBox = 7 //
			{
				// Enter supplier session //
				CommentStep(" *** ENTER IN SUPPLIER SESSION *** ");
				EnterDiagSession(CFGc_SupplierSession);
				Wait(1000);


				// Check AEC default status
				CommentStep(" *** CHECK DEFAULT OVER VOLTAGE STATE *** ");
				var sResponse = CAN.SendDiagByValues(CFG_ReadAllAECsReq);
				RESULT.InsertComment("Response CFGc_requestReadAllAECStatus : " + sResponse[1]);
				RESULT.ExpectTestResult("Check OVO power event identifier in Read all AECs response",
					sResponse[1].substring(15 + 15 * parseInt(_sERR_BAT_PWR_OVER_VOLTAGE - 1), 24 + 15 * parseInt(_sERR_BAT_PWR_OVER_VOLTAGE - 1)),
					"0x00 " + _sERR_BAT_PWR_OVER_VOLTAGE);
				RESULT.ExpectTestResult("Check OVO power event is not qualified",
					sResponse[1].substring(10 + 15 * parseInt(_sERR_BAT_PWR_OVER_VOLTAGE), 14 + 15 * parseInt(_sERR_BAT_PWR_OVER_VOLTAGE)),
					CFGc_AECStatus_Passed);
				
		
				// Set OVER voltage situation
				CommentStep(" *** SET OVER VOLTAGE SITUATION *** ");
				//voltageStatus = SwDevLib_PS1_SetVoltage(sOverKL30QualificationThrs);
				//RESULT.ExpectTestResult("Set power supply at " + sOverKL30QualificationThrs + " V", voltageStatus.toString().substr(0, 4), "0000");
				//RESULT.ExpectTestResult("Set power supply at " + sOverKL30QualificationThrs + " V", (PS.SetVoltage(_sPS1Name, sOverKL30QualificationThrs))[0], "0000");
				MessageBox.Show("Set power supply at " + sOverKL30QualificationThrs + " V");
				var resultMessageBox = MessageBox.Show(" Is power supply set at " + sOverKL30QualificationThrs + " V ?", "Power supply voltage",
					MessageBoxButtons.YesNo, MessageBoxIcon.Question);
				Wait(CFGc_WakeupDelay);

				if (resultMessageBox == 6) // If you click Yes => resultMessageBox = 6      If you click No => resultMessageBox = 7 //
				{
					// Enter supplier session //
					CommentStep(" *** ENTER IN SUPPLIER SESSION *** ");
					EnterDiagSession(CFGc_SupplierSession);
					Wait(1000);


					// Check AEC is qualified
					CommentStep(" *** CHECK OVER VOLTAGE IS QUALIFIED *** ");
					sResponse = CAN.SendDiagByValues(CFG_ReadAllAECsReq);
					RESULT.InsertComment("Response CFGc_requestReadAllAECStatus : " + sResponse[1]);
					RESULT.ExpectTestResult("Check OVO power event identifier in Read all AECs response",
						sResponse[1].substring(15 + 15 * parseInt(_sERR_BAT_PWR_OVER_VOLTAGE - 1), 24 + 15 * parseInt(_sERR_BAT_PWR_OVER_VOLTAGE - 1)),
						"0x00 " + _sERR_BAT_PWR_OVER_VOLTAGE);
					RESULT.ExpectTestResult("Check OVO power event is qualified",
						sResponse[1].substring(10 + 15 * parseInt(_sERR_BAT_PWR_OVER_VOLTAGE), 14 + 15 * parseInt(_sERR_BAT_PWR_OVER_VOLTAGE)),
						CFGc_AECStatus_Qualified);

					
					// Clear OVER voltage situation
					CommentStep(" *** CLEAR OVER VOLTAGE SITUATION *** ");
					//voltageStatus = SwDevLib_PS1_SetVoltage(sOverKL30DeskillingThrs);
					//RESULT.ExpectTestResult("Set power supply below " + sOverKL30DeskillingThrs + " V", voltageStatus.toString().substr(0, 4), "0000");
					//RESULT.ExpectTestResult("Set power supply below " + sOverKL30DeskillingThrs + " V", (PS.SetVoltage(_sPS1Name, sOverKL30DeskillingThrs))[0], "0000");
					MessageBox.Show("Set power supply below " + sOverKL30DeskillingThrs + " V (~16.7 V)");
					var resultMessageBox = MessageBox.Show(" Is power supply set below " + sOverKL30DeskillingThrs + " V ? (~16.7 V)", "Power supply voltage",
						MessageBoxButtons.YesNo, MessageBoxIcon.Question);
					Wait(CFGc_WakeupDelay);

					if (resultMessageBox == 6) // If you click Yes => resultMessageBox = 6      If you click No => resultMessageBox = 7 //
					{
						// Enter supplier session //
						CommentStep(" *** ENTER IN SUPPLIER SESSION *** ");
						EnterDiagSession(CFGc_SupplierSession);
						Wait(1000);


						// Check AEC is disqualified
						CommentStep(" *** CHECK OVER VOLTAGE IS DISQUALIFIED *** ");
						sResponse = CAN.SendDiagByValues(CFG_ReadAllAECsReq);
						RESULT.InsertComment("Response CFGc_requestReadAllAECStatus : " + sResponse[1]);
						RESULT.ExpectTestResult("Check OVO power event identifier in Read all AECs response",
							sResponse[1].substring(15 + 15 * parseInt(_sERR_BAT_PWR_OVER_VOLTAGE - 1), 24 + 15 * parseInt(_sERR_BAT_PWR_OVER_VOLTAGE - 1)),
							"0x00 " + _sERR_BAT_PWR_OVER_VOLTAGE);
						RESULT.ExpectTestResult("Check OVO power event is disqualified",
							sResponse[1].substring(10 + 15 * parseInt(_sERR_BAT_PWR_OVER_VOLTAGE), 14 + 15 * parseInt(_sERR_BAT_PWR_OVER_VOLTAGE)),
							CFGc_AECStatus_Disqualified);
					}
					else
					{
						RESULT.InsertComment("Configuration of power supply at " + sOverKL30DeskillingThrs + " V failed");
					}
				}
				else
				{
					RESULT.InsertComment("Configuration of power supply at " + sOverKL30QualificationThrs + " V failed");
				}
			}
			else
			{
					RESULT.InsertComment("Configuration of power supply at " + sNominalVoltageLevelSituation + " V failed");
			}


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
catch (exError)
{
    RESULT.ExpectTestResult("Test failed about exception occurs :" + exError, cException_Catched, false);
    RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK);
}