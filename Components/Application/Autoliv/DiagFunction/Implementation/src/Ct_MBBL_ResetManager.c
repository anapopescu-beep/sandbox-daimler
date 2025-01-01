/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Ct_MBBL_ResetManager.c
 *           Config:  S:\Tools\Vector_configuration\Workspace\Daimler MMA/S:/Tools/Vector_configuration/Workspace/Daimler MMA/StartApplication.dpa
 *        SW-C Type:  Ct_MBBL_ResetManager
 *  Generation Time:  2021-10-26 17:23:54
 *
 *        Generator:  MICROSAR RTE Generator Version 4.24.0
 *                    RTE Core Version 1.24.0
 *          License:  PAI981
 *
 *      Description:  C-Code implementation template for SW-C <Ct_MBBL_ResetManager>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Dcm_ConfirmationStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *
 * Mode Declaration Groups:
 * ========================
 * Coding_MemoryStatus
 *   Notifies the Ssa of memory status changes while storing or restoring the Variant Coding Data to or from non-volatile memory.
 *
 * Coding_Mode
 *   Coding state
 *
 * Coding_Mode
 *   Notifies application about an ongoing, successful or failed coding attempt.
 *
 * RightsM_AuthenticationMode
 *   RIGHTSM_AUTHENTICATED - A Tester was successfully authenticated
 *      RIGHTSM_UNAUTHENTICATED - No tester was authenticated
 *
 * WdgM_Mode
 *   The mode declaration group WdgMMode represents the modes of the Watchdog Manager module that will be notified to the SW-Cs / CDDs and the RTE.
 *
 *
 * Mode Declarations:
 * ==================
 * CODING_ACTIVE of Mode Declaration Group Coding_Mode
 *   Active
 *
 * CODING_FAILED of Mode Declaration Group Coding_Mode
 *   Failed
 *
 * CODING_OK of Mode Declaration Group Coding_Mode
 *   Ok
 *
 *
 * Runnable Entities:
 * ==================
 * Ct_MBBL_ResetManager_Init
 *      -------------------------------------------------------------------------------------
 *      This runnable is currently not used.
 *      -------------------------------------------------------------------------------------
 *
 * DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Confirmation
 *      -------------------------------------------------------------------------------------
 *      This runnable is currently not used, but since there is no way to generate the
 *      _Indication-runnable without this, it must be implemented nevertheless.
 *      -------------------------------------------------------------------------------------
 *
 * DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication
 *      -------------------------------------------------------------------------------------
 *      This runnable called whenever any diagnostic request is received by the ECU.
 *      It performs the following checks:
 *      Service $10 - Programming Session (0x02): 
 *        Checks preconditions for this request by calling services provided by
 *        Pp_MBBL_BootloaderPreconditions and triggers the DCM to send negative 
 *        response codes if those fail.
 *      Service $11 - Soft-Reset (0x01) or Hard-Reset (0x03):
 *        Checks preconditions for this request by calling services provided by
 *        Pp_MBBL_ResetPreconditions and triggers the DCM to send negative 
 *        response codes if those fail.
 *      -------------------------------------------------------------------------------------
 *
 * ResetServiceExecution
 *      -------------------------------------------------------------------------------------
 *      This runnable is executed by the DCM multiple times during reset procedure. 
 *      It checks the required reset mode and triggers the application to shut 
 *      down by calling the services provided by Pp_MBBL_ApplicationShutdown.
 *      After this it requests the actual reset by calling the services provided 
 *      by Pp_ResetExecution.
 *      -------------------------------------------------------------------------------------
 *
 *********************************************************************************************************************/

#include "Rte_Ct_MBBL_ResetManager.h"
#include "Rte_RCM_AC_ResetCauseManagement_Type.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "SBC_cfg.h"
#include "RCM_Public.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dcm_ConfirmationStatusType: Enumeration of integer in interval [0...3] with enumerators
 *   DCM_RES_POS_OK (0U)
 *   DCM_RES_POS_NOT_OK (1U)
 *   DCM_RES_NEG_OK (2U)
 *   DCM_RES_NEG_NOT_OK (3U)
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_E_POSITIVERESPONSE (0U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_AUTHENTICATIONREQUIRED (52U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_CVF_INVALIDTIMEPERIOD (80U)
 *   DCM_E_CVF_INVALIDSIGNATURE (81U)
 *   DCM_E_CVF_INVALIDCHAINOFTRUST (82U)
 *   DCM_E_CVF_INVALIDTYPE (83U)
 *   DCM_E_CVF_INVALIDFORMAT (84U)
 *   DCM_E_CVF_INVALIDCONTENT (85U)
 *   DCM_E_CVF_INVALIDSCOPE (86U)
 *   DCM_E_CVF_INVALIDCERTIFICATEREVOKED (87U)
 *   DCM_E_OWNERSHIPVERIFICATIONFAILED (88U)
 *   DCM_E_CHALLENGECALCULATIONFAILED (89U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 *
 * Array Types:
 * ============
 * Dcm_Data8195ByteType: Array with 8195 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define Ct_MBBL_ResetManager_START_SEC_CODE
#include "Ct_MBBL_ResetManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ct_MBBL_ResetManager_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ct_MBBL_ResetManager_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ct_MBBL_ResetManager_CODE) Ct_MBBL_ResetManager_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ct_MBBL_ResetManager_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Confirmation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Confirmation> of PortPrototype <ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ServiceRequestNotification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Confirmation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_ResetManager_CODE) DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Confirmation (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Indication> of PortPrototype <ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Pp_MBBL_BootloaderPreconditions_CheckConditions(boolean *resetAllowed, Dcm_NegativeResponseCodeType *errorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Pp_MBBL_ResetPreconditions_CheckConditions(boolean *resetAllowed, Dcm_NegativeResponseCodeType *errorCode)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication(uint8 SID, const uint8 *RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument RequestData: uint8* is of type Dcm_Data8195ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ServiceRequestNotification_E_NOT_OK
 *   RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_ResetManager_CODE) DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_OK;

  if (SID == 0x10u)
  {
    uint8 requestedSession = (uint8)RequestData[0];
    boolean locResetAllowed = FALSE;
    Dcm_NegativeResponseCodeType locErrorCode = 0x00;

    if (requestedSession == 0x02u)
    {
      (void)Rte_Call_Pp_MBBL_BootloaderPreconditions_CheckConditions(&locResetAllowed, &locErrorCode);

      if (locResetAllowed == FALSE)
      {
        retVal = RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED;
        *ErrorCode = locErrorCode;
      }
      else
      {
        retVal = RTE_E_OK;
      }
    }
  }

  if (SID == 0x11u)
  {
    uint8 requestedResetType = (uint8)RequestData[0];
    boolean locResetAllowed = FALSE;
    Dcm_NegativeResponseCodeType locErrorCode = 0x00;

    if ((requestedResetType == 0x01u) || (requestedResetType == 0x03u))
    {
      (void)Rte_Call_Pp_MBBL_ResetPreconditions_CheckConditions(&locResetAllowed, &locErrorCode);

      if (locResetAllowed == FALSE)
      {
        retVal = RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED;
        *ErrorCode = locErrorCode;
      }
      else
      {
        retVal = RTE_E_OK;
      }
    }
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ResetServiceExecution
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <EXECUTE> of ModeDeclarationGroupPrototype <DcmEcuReset> of PortPrototype <Pp_DcmEcuReset>
 *   - triggered on entering of Mode <HARD> of ModeDeclarationGroupPrototype <DcmEcuReset> of PortPrototype <Pp_DcmEcuReset>
 *   - triggered on entering of Mode <JUMPTOBOOTLOADER> of ModeDeclarationGroupPrototype <DcmEcuReset> of PortPrototype <Pp_DcmEcuReset>
 *   - triggered on entering of Mode <JUMPTOSYSSUPPLIERBOOTLOADER> of ModeDeclarationGroupPrototype <DcmEcuReset> of PortPrototype <Pp_DcmEcuReset>
 *   - triggered on entering of Mode <SOFT> of ModeDeclarationGroupPrototype <DcmEcuReset> of PortPrototype <Pp_DcmEcuReset>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_Pp_DcmEcuReset_DcmEcuReset(uint8 *previousMode, uint8 *nextMode)
 *   Modes of Rte_ModeType_DcmEcuReset:
 *   - RTE_MODE_DcmEcuReset_EXECUTE
 *   - RTE_MODE_DcmEcuReset_HARD
 *   - RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
 *   - RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
 *   - RTE_MODE_DcmEcuReset_KEYONOFF
 *   - RTE_MODE_DcmEcuReset_NONE
 *   - RTE_MODE_DcmEcuReset_SOFT
 *   - RTE_TRANSITION_DcmEcuReset
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Pp_MBBL_ApplicationShutdown_ShutdownAppl_HardReset(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Pp_MBBL_ApplicationShutdown_ShutdownAppl_SoftReset(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Pp_ResetExecution_HardReset(boolean prepareWatchdog)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Pp_ResetExecution_SoftReset(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Pi_ResetExecution_EXECUTION_FAILED
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ResetServiceExecution_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     None
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0221]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ct_MBBL_ResetManager_CODE) ResetServiceExecution(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ResetServiceExecution
 *********************************************************************************************************************/
  uint8 locCurrentMode, locPreviousMode, locNextMode;
  uint8 u8WdgRegister[2U] = {(uint8)0x83, (uint8)0x87};    /* watchdog timer period = 10s => 0x87 */

  locCurrentMode = Rte_Mode_Pp_DcmEcuReset_DcmEcuReset(&locPreviousMode, &locNextMode);

  /* Trigger watchdog and set period to 10s to avoid sbc resets */     
  SBC_REFRESH_WDG_REQUEST(u8WdgRegister);

  switch (locNextMode)
  {
  case RTE_MODE_DcmEcuReset_SOFT:
    (void)Rte_Call_Pp_MBBL_ApplicationShutdown_ShutdownAppl_SoftReset();
    break;

  case RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER:             /* Fall through: Same treatment as for hard reset */
  case RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER:  /* Fall through: Same treatment as for hard reset */
  case RTE_MODE_DcmEcuReset_HARD:
    (void)Rte_Call_Pp_MBBL_ApplicationShutdown_ShutdownAppl_HardReset();
    break;

  case RTE_MODE_DcmEcuReset_EXECUTE:
    if (locPreviousMode == RTE_MODE_DcmEcuReset_SOFT)
    {
      RCM_runNotifyResetCause(KU32_DIAG_SOFT_RESET_NOTIFICATION, KU32_RESET_CAUSE_ACTIVE);
      (void)Rte_Call_Pp_ResetExecution_SoftReset();
    }

    if ((locPreviousMode == RTE_MODE_DcmEcuReset_HARD) ||
      (locPreviousMode == RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER) ||
      (locPreviousMode == RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER))
    {
      if (locPreviousMode != RTE_MODE_DcmEcuReset_HARD)
      {
        RCM_runNotifyResetCause(KU32_BTLD_RESET_NOTIFICATION, KU32_RESET_CAUSE_ACTIVE);
      }
      else
      {
        RCM_runNotifyResetCause(KU32_DIAG_HARD_RESET_NOTIFICATION, KU32_RESET_CAUSE_ACTIVE);
      }
      
      /* Never returns */
      (void)Rte_Call_Pp_ResetExecution_HardReset(TRUE);
    }

    break;

  default:
    break;
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Ct_MBBL_ResetManager_STOP_SEC_CODE
#include "Ct_MBBL_ResetManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
