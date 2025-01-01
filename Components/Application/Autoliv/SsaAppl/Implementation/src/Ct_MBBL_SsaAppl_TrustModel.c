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
 *  BETA MODULE
 *  -------------------------------------------------------------------------------------------------------------------
 *  Beta Modules and Beta Features are basically operable, but not sufficiently tested, verified and/or qualified
 *  for use in series production and/or in vehicles operating on public or non-public roads.
 *  Please consult the Product Information for details.
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Ct_MBBL_SsaAppl_TrustModel.c
 *           Config:  D:/starter_kit_classic/examples/can_lin_eth/msr/MBBL_EthCanLin.dpa
 *        SW-C Type:  Ct_MBBL_SsaAppl_TrustModel
 *  Generation Time:  2021-09-15 18:29:43
 *
 *        Generator:  MICROSAR RTE Generator Version 4.25.0.38097
 *                    RTE Core Version 1.25.0
 *          License:  PAI1580
 *
 *      Description:  C-Code implementation template for SW-C <Ct_MBBL_SsaAppl_TrustModel>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW
 *  configuration. The Example Code has not passed any quality control measures and may be incomplete. The
 *  Example Code is neither intended nor qualified for use in series production. The Example Code as well
 *  as any of its modifications and/or implementations must be tested with diligent care and must comply
 *  with all quality requirements which are necessary according to the state of the art before their use.
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
 * TimeM_CompareOperatorType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TimeM_RealTimeChangeReasonType
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
 * EcuM_Mode
 *   The modes of the ECU State Manager
 *
 * MDG_EcuActivationReason
 *   Activation Reason of ECU (FIRST_POWER_ON, POWER_ON_RESET, WAKE_UP)
 *
 * MDG_EcuWakeUpReason
 *   MDG Ecu Wake Up Reason
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
 * POST_RUN of Mode Declaration Group EcuM_Mode
 *   PREP SHUTDOWN or RUN III
 *
 * RUN of Mode Declaration Group EcuM_Mode
 *   RUN II
 *
 * SHUTDOWN of Mode Declaration Group EcuM_Mode
 *   GO OFF I
 *
 * SLEEP of Mode Declaration Group EcuM_Mode
 *   WAKEUP or SLEEP or GO SLEEP
 *
 * STARTUP of Mode Declaration Group EcuM_Mode
 *   STARTUP II
 *
 * WAKE_SLEEP of Mode Declaration Group EcuM_Mode
 *   Time Triggered Increased Inoperation
 *
 * FIRST_POWER_ON of Mode Declaration Group MDG_EcuActivationReason
 *   FIRST_POWER_ON
 *
 * POWER_ON_RESET of Mode Declaration Group MDG_EcuActivationReason
 *   POWER_ON_RESET
 *
 * WAKE_UP of Mode Declaration Group MDG_EcuActivationReason
 *   WAKE_UP
 *
 * WKSTATUS_NONE of Mode Declaration Group MDG_EcuWakeUpReason
 *   WKSTATUS_NONE
 *
 * WKSTATUS_VALIDATED of Mode Declaration Group MDG_EcuWakeUpReason
 *   WKSTATUS_VALIDATED
 *
 *********************************************************************************************************************/

#include "Rte_Ct_MBBL_SsaAppl_TrustModel.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "KeyM.h"
#include "Ssa_Cfg.h"
#include "vstdlib.h"
#include "Nvp_Generated.h"

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
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * TimeM_CompareOperatorType: Enumeration of integer in interval [0...255] with enumerators
 *   TIMEM_IS_GREATER (0U)
 *   TIMEM_IS_LESS (1U)
 * TimeM_RealTimeChangeReasonType: Enumeration of integer in interval [0...255] with enumerators
 *   TIMEM_REALTIMECHANGEREASON_NOTBEFORE (0U)
 *   TIMEM_REALTIMECHANGEREASON_NONCE (1U)
 *
 * Record Types:
 * =============
 * TimeM_DateTimeType: Record with elements
 *   year of type uint16
 *   month of type uint8
 *   day of type uint8
 *   hour of type uint8
 *   minute of type uint8
 *   second of type uint8
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint64 *Rte_Pim_Pim_RealTime_Unix(void)
 *
 *********************************************************************************************************************/


#define Ct_MBBL_SsaAppl_TrustModel_START_SEC_CODE
#include "Ct_MBBL_SsaAppl_TrustModel_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ct_MBBL_SsaAppl_TrustModel_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ct_MBBL_SsaAppl_TrustModel_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ct_MBBL_SsaAppl_TrustModel_CODE) Ct_MBBL_SsaAppl_TrustModel_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ct_MBBL_SsaAppl_TrustModel_Init
 *********************************************************************************************************************/

	// Set the dummy date and real time for SSA

	//TimeM_DateTimeType realTime = { 2021,12,23,0,0,0 };
	//TimeM_RealTimeChangeReasonType Reason = TIMEM_REALTIMECHANGEREASON_NOTBEFORE;


	/////* #10 Set the current real-time. */
	//Rte_Call_TimeM_RealTime_Set((P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR))&realTime, Reason);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_KeyM_GeCurrentTime
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_TimeM_RealTime_Compare(const TimeM_DateTimeType *t1, TimeM_CompareOperatorType compareOp, const TimeM_DateTimeType *t2, boolean *result)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_RealTime_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_RealTime_Get(TimeM_DateTimeType *realTime)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_RealTime_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_RealTime_Set(const TimeM_DateTimeType *realTime, TimeM_RealTimeChangeReasonType changeReason)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_RealTime_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_KeyM_GeCurrentTime_doc
 *********************************************************************************************************************/
 /**********************************************************************************************************************
 *  ConvertDateToUnixTime()
 *********************************************************************************************************************/

static FUNC(Std_ReturnType, KEYM_CODE) ConvertDateToUnixTime(
	P2CONST(TimeM_DateTimeType, AUTOMATIC, AUTOMATIC) date,
	P2VAR(uint64, AUTOMATIC, AUTOMATIC) unixTime)
{
	/* ----- Local Variables ---------------------------------------------- */
	Std_ReturnType retVal = E_OK;
	uint64 y;
	uint64 m;
	uint64 d;

	/* ----- Implementation ----------------------------------------------- */
	/* Year */
	y = date->year;
	/* Month of year */
	m = date->month;
	/* Day of month */
	d = date->day;

	/* January and February are counted as months 13 and 14 of the previous year */
	if (m <= 2u)
	{
		m += 12u;
		y -= 1u;
	}

	/* # Convert years to days */
	/* A leap year must be evenly divisible by 4. If the year can also be evenly divided by 100, it is not a leap year, unless
	the year is also evenly divisible by 400. */
	*unixTime = ((365u * y) + (y / 4u) - (y / 100u) + (y / 400u));

	/* # Convert months to days */
	/* This formula takes into account the uneven number of days in the months across a year */
	*unixTime += ((30u * m) + (3u * (m + 1u) / 5u) + d);

	/* # Unix time starts on January 1st, 1970 */
	if (*unixTime < 719561u)
	{
		retVal = E_NOT_OK;
	}
	else
	{
		*unixTime -= 719561u;
		/* # Convert days to seconds */
		*unixTime *= 86400u;
		/* # Add hours, minutes and seconds */
		*unixTime += ((3600u * (uint64)(date->hour)) + (60u * (uint64)(date->minute)) + (uint64)(date->second));
	}

	return retVal;
}

Std_ReturnType TscAppl_KeyMCertificateGetCurrentTimeCalloutFunc(KeyM_CertificateIdType CertId, P2VAR(uint64, AUTOMATIC, KEYM_APPL_VAR) timeStamp)
{
	//Updated because of Discussion in: https://issue.swf.daimler.com/browse/AUTOSARBAS-9799
	// Asr KeyM shall no longer check the validity Time, as it is checked by the SSA.
	// For the VI MICROSAR Stack, this is handled by returning KEYM_E_NO_PERIOD_VALIDITY_CHECK
	
	return KEYM_E_NO_PERIOD_VALIDITY_CHECK;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ct_MBBL_SsaAppl_TrustModel_CODE) Ssa_KeyM_GeCurrentTime(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_KeyM_GeCurrentTime
 *********************************************************************************************************************/
	Std_ReturnType ret;
	TimeM_DateTimeType realTime = { 0 };


	/* #10 Get the current real-time. */
	ret = Rte_Call_TimeM_RealTime_Get((P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR))&realTime);

	if (ret == RTE_E_OK)
	{
		/* # Convert real standard time to unix time */
		ret = ConvertDateToUnixTime(&realTime, Rte_Pim_Pim_RealTime_Unix());
	}
	else
	{
		ret = E_NOT_OK;
	}
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TrustModelCsr_GetCommonName
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetCommonName> of PortPrototype <Ssa_TrustModelCsr>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TrustModelCsr_GetCommonName(uint8 *data, uint16 *dataLength)
 *     Argument data: uint8* is of type Ssa_Data30ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Ssa_TrustModelCsr_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TrustModelCsr_GetCommonName_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_TrustModel_CODE) Ssa_TrustModelCsr_GetCommonName(P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR) data, P2VAR(uint16, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR) dataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TrustModelCsr_GetCommonName (returns application error)
 *********************************************************************************************************************/

    /* Supplier identification - AUTOLIV=0077 */
    data[0u] = '0';
    data[1u] = '0';
    data[2u] = '7';
    data[3u] = '7';

    /* ECU Serial number */
    VStdMemCpy((data+4u), &NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData, sizeof(NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData));

    *dataLength = 4u + sizeof(NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData);

    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_onVedocInformation_called
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetData> of PortPrototype <Ssa_VeDocRelevantInfo>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_onVedocInformation_called(uint8 *data, uint16 *dataLength)
 *     Argument data: uint8* is of type Ssa_Data64ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Ssa_VeDocRelevantInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_onVedocInformation_called_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_TrustModel_CODE) Ssa_onVedocInformation_called(P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR) data, P2VAR(uint16, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR) dataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_onVedocInformation_called (returns application error)
 *********************************************************************************************************************/
  uint8 vedocInfo[64]={0};
  uint16 vedocLength=0;
  uint16 index=0;
  Std_ReturnType retVal=E_NOT_OK;

  retVal= Rte_Call_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData(0, vedocInfo);
  retVal|= Rte_Call_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength(0, &vedocLength);

  if(0!=data && 0!=dataLength)
  {
      for(index=0; index<vedocLength; index++)
      {
          data[index]=vedocInfo[index];
      }
      *dataLength=vedocLength;
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#define Ct_MBBL_SsaAppl_TrustModel_STOP_SEC_CODE
#include "Ct_MBBL_SsaAppl_TrustModel_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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
