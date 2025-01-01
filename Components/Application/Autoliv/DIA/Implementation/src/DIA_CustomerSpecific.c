/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version:
Template version: AEM_PROCESS_1.17.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2021-10
******************************************************************************/
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.58 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/DIA/Implementation/src/project.pj $
*/

/**
 *  @defgroup TEMPLATE_FILES_Group_Example Group_Example_Name_In_Document
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_DIA_AC_DiagOnCAN.h"
#include "DIA.h"
#include "Nvp_Generated.h"
#include "vstdlib.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/

#define KU8_TWENTYFIVE 25u
#define ROUTINE_TERMINATED_SUCCESSFULY 0x00u
#define ROUTINE_STILL_RUNNING 0x01u
#define ROUTINE_STOPPED_WITHOUT_RESULT 0x02u

#define ECU_SIDE_RBTM_FR 0x99u

#define SUPBAT_CONVERSION_FACTOR (uint8)4

#define DIA_MASK_FOR_FIRST_BIT 0x01u
#define DIA_MASK_FOR_FIRST_2_BITS 0x03u
#define DIA_MASK_FOR_FIRST_3_BITS 0x07u
#define DIA_MASK_FOR_FIRST_4_BITS 0x0Fu
#define DIA_MASK_FOR_FIRST_6_BITS 0x3Fu

#define DIA_EXT_TESTER_PRESENT_SNA I_C02_NDEF_FALSE_TRUE_ST3_SNA
#define DIA_EXT_TESTER_PRESENT_FALSE I_C02_NDEF_FALSE_TRUE_ST3_FALSE
#define DIA_EXT_TESTER_PRESENT_TRUE I_C02_NDEF_FALSE_TRUE_ST3_TRUE
#define DIA_PRESF_ENBL_ST3_SNA I_C02_FALSE_TRUE_SNA_FALSE
#define DIA_PRESF_ACCELRESET_NOTEXCEEDED_ST3_SNA I_C02_NDEF_FALSE_TRUE_ST3_SNA
#define DIA_RESFACT_TENSSUPP_RQ_ST3_NO I_C03_NO_LT_RT_BOTH_NO
#define DIA_RESFACT_TENSSUPP_RQ_ST3_LEFT I_C03_NO_LT_RT_BOTH_LEFT
#define DIA_RESFACT_TENSSUPP_RQ_ST3_RIGHT I_C03_NO_LT_RT_BOTH_RIGHT
#define DIA_RESFACT_TENSSUPP_RQ_ST3_BOTH I_C03_NO_LT_RT_BOTH_BOTH
#define DIA_RESFACT_TENSSUPP_RQ_ST3_SNA I_C03_NO_LT_RT_BOTH_SNA
#define DIA_PTCOOR_ENGSTARTPN14_STAT_ST3_SNA I_C03_ENGSTARTPN14_STAT_SNA

#define DIA_OBSOLESCENSE_DATA_MEMBER_SIZE 2u

#define DIA_PRESAFE_RECORDER_LENGTH 22u

#define PRESAFE_RECORDER_RESET_VALUE 0x01u

#define DIA_ECUM_STATE_STARTUP 0x10
#define DIA_ECUM_STATE_WAKEUP 0x20
#define DIA_ECUM_STATE_RUN 0x30
#define DIA_ECUM_STATE_SHUTDOWN 0x40
#define DIA_ECUM_STATE_SLEEP 0x50

#define DIA_KU16_VOLTAGE_CONVERSION               (100u)
#define DIA_KU16_TEMPERATURE_FACTOR               (2325u)
#define DIA_KU16_TEMPERATURE_OFFSET               (527875u)
#define DIA_KU16_TEMPERATURE_MUL1000              (1000u)
#define DIA_KU16_TEMPERATURE_MUL10                (10u)
#define DIA_KU32_CURRENT_MUL10                    (10u)
#define DIA_U16_CONVERT_TEMP_TO_RAW(PMP_TEMP)     ( (uint16) (( (uint32) ((sint32)(PMP_TEMP) * DIA_KU16_TEMPERATURE_MUL1000*DIA_KU16_TEMPERATURE_MUL10) + DIA_KU16_TEMPERATURE_OFFSET) / DIA_KU16_TEMPERATURE_FACTOR))
#define DIA_KU32_CONVERT_CURENT(PAL_CURRENT)      ( (uint32) ( (sint32)(PAL_CURRENT)/DIA_KU32_CURRENT_MUL10) )

/* Defines for Pre-Safe Recorder 1 Fields in NVP */
#define KU8_PRESAFE_1_ECUTEMPSTART_FIELD_0 (uint8)0
#define KU8_PRESAFE_1_ECUTEMPSTART_FIELD_1 (uint8)1
#define KU8_PRESAFE_1_ECUTEMPSTOP_FIELD_0 (uint8)0
#define KU8_PRESAFE_1_ECUTEMPSTOP_FIELD_1 (uint8)1
#define KU8_PRESAFE_1_LOCAL_VOLTAGE_START (uint8)0
#define KU8_PRESAFE_1_LOCAL_VOLTAGE_STOP (uint8)0
#define KU8_PRESAFE_1_START_FIELD_0 (uint8)0
#define KU8_PRESAFE_1_START_FIELD_1 (uint8)1
#define KU8_PRESAFE_1_STATE_FIELD_0 (uint8)0
#define KU8_PRESAFE_1_STATE_FIELD_1 (uint8)1
#define KU8_PRESAFE_1_STOP_FIELD_0 (uint8)0
#define KU8_PRESAFE_1_STOP_FIELD_1 (uint8)1

/* Defines for Pre-Safe Recorder 2 Fields in NVP */
#define KU8_PRESAFE_2_ECUTEMPSTART_FIELD_0 (uint8)0
#define KU8_PRESAFE_2_ECUTEMPSTART_FIELD_1 (uint8)1
#define KU8_PRESAFE_2_ECUTEMPSTOP_FIELD_0 (uint8)0
#define KU8_PRESAFE_2_ECUTEMPSTOP_FIELD_1 (uint8)1
#define KU8_PRESAFE_2_LOCAL_VOLTAGE_START (uint8)0
#define KU8_PRESAFE_2_LOCAL_VOLTAGE_STOP (uint8)0
#define KU8_PRESAFE_2_START_FIELD_0 (uint8)0
#define KU8_PRESAFE_2_START_FIELD_1 (uint8)1
#define KU8_PRESAFE_2_STATE_FIELD_0 (uint8)0
#define KU8_PRESAFE_2_STATE_FIELD_1 (uint8)1
#define KU8_PRESAFE_2_STOP_FIELD_0 (uint8)0
#define KU8_PRESAFE_2_STOP_FIELD_1 (uint8)1

#define DIA_KU32_AEC_GROUP_MASK_BSR_INHIBIT       (KU32_AEC_GROUP_MASK_EOL_COMFORT|KU32_AEC_GROUP_MASK_EOL_LOW_HIGH|KU32_AEC_GROUP_MASK_HARDWARE)
/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
static FUNC(Std_ReturnType, DiagFunction_CODE) ConditionCheckRead_General(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode);

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
************************************************x******************************/
/**
 * \brief
 * 		Request result status for RID 0329
 */
LOCAL uint8 dia_u8RequestResult0329 = KU8_ROUTINE_NOT_SUPPORTED;
/**
 * \brief
 * 		Request result status for RID 0330
 */
LOCAL uint8 dia_u8RequestResult0330 = KU8_ROUTINE_NOT_SUPPORTED;

/******************************************************************************
DEFINITION OF GLOBAL VARIABLES
******************************************************************************/
/**
 * \brief
 * 		Request result status for RID 0302
 */
uint8 dia_u8RequestResult0302 = KU8_ROUTINE_NOT_SUPPORTED;
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
 ******************************************************************************/

#define DIA_AC_DiagOnCAN_START_SEC_CONST_UNSPECIFIED
#include <DIA_AC_DiagOnCAN_MemMap.h>
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		This variable should be in upper defined group.
 * \remarks
 *		This is a example of remark of a variable.
 */

static const uint8 DIA_u8TensioningCycleLUT[] =
{
		KU8_BELT_FUNCTION_00,
		KU8_BELT_FUNCTION_18, /*CYCLE_19?*/
		KU8_BELT_FUNCTION_01,
		KU8_BELT_FUNCTION_02,
		KU8_BELT_FUNCTION_03,
		KU8_BELT_FUNCTION_04,
		KU8_BELT_FUNCTION_05,
		KU8_BELT_FUNCTION_06,
		KU8_BELT_FUNCTION_07,
		KU8_BELT_FUNCTION_08,
		KU8_BELT_FUNCTION_09,
		KU8_BELT_FUNCTION_10,
		KU8_BELT_FUNCTION_11,
		KU8_BELT_FUNCTION_12,
		KU8_BELT_FUNCTION_13,
		KU8_BELT_FUNCTION_20, /*CYCLE_21?*/
		KU8_BELT_FUNCTION_22, /*CYCLE_23?*/
		KU8_BELT_FUNCTION_24, /*CYCLE_25?*/
		KU8_BELT_FUNCTION_26,
		KU8_BELT_FUNCTION_27,
		KU8_BELT_FUNCTION_28,
		KU8_BELT_FUNCTION_14,
		KU8_BELT_FUNCTION_15,
		KU8_BELT_FUNCTION_16,
		KU8_BELT_FUNCTION_17
};

#define ROUTINE_TRIGGER_BSR_CYCLE KU8_BELT_FUNCTION_26

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define DIA_AC_DiagOnCAN_STOP_SEC_CONST_UNSPECIFIED
#include <DIA_AC_DiagOnCAN_MemMap.h>

static FUNC(Std_ReturnType, DiagFunction_CODE) ConditionCheckRead_General(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */

#define DIA_AC_DiagOnCAN_START_SEC_CODE
#include "DIA_AC_DiagOnCAN_MemMap.h"

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Here write function parameters.
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Here write return variables.
 *   [COVERS: DSG_DIA_MMA_0002 ]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidF18C_EcuSerialNumberConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0001, DSG_DIA_MMA_0014 ]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidF18C_EcuSerialNumberRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData, sizeof(NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData));

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Here write function parameters.
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Here write return variables.
 *   [COVERS: DSG_DIA_MMA_0003, DSG_DIA_MMA_0220]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidF18C_EcuSerialNumberReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != DataLength)
   {
      *DataLength = sizeof(NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData);
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Here write function parameters.
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Here write return variables.
 *   [COVERS: DSG_DIA_MMA_0004 ]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0340_UniqueSeatbeltSerialNumberConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0005, DSG_DIA_MMA_0015 ]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0340_UniqueSeatbeltSerialNumberRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{

   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_RamBlockData, sizeof(NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_RamBlockData));

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0006, DSG_DIA_MMA_0016 ]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0340_UniqueSeatbeltSerialNumberWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret;

   VStdMemCpy(&NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_RamBlockData, Data, sizeof(NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_RamBlockData));

   ret = Rte_Call_NvMService_NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_WriteBlock(Data);

   *ErrorCode = DCM_E_POSITIVERESPONSE;
   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     routineInfo - pointer to routine status
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 *     Result - pointer to routine result
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0041, DSG_DIA_MMA_0198]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runRid0329_TriggerBSRRequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Trigger_BSR_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_RequestDataOut_Routine_Trigger_BSR_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = RTE_E_OK;
   /* Local variable used to retrieve the executed cycle */
   uint8 u8CurrentCycleExecutedByBFE = KU8_NO_CYCLE;
   uint8 u8DiagRequestedCycle = KU8_NO_CYCLE;

   /* Get the executed cycle number */
   Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8CurrentCycleExecutedByBFE);
   u8DiagRequestedCycle = Rte_IrvRead_DIA_runRid0329_TriggerBSRRequestResults_u8DiagRequestedCycle();

   if ((u8DiagRequestedCycle == u8CurrentCycleExecutedByBFE) && (KU8_NO_CYCLE != u8CurrentCycleExecutedByBFE))
   {
      *routineInfo = KU8_ROUTINE_IN_PROGRESS;
      ret = RTE_E_OK;
      *Result = ROUTINE_STILL_RUNNING;
   }
   else
   {
      if (KU8_NO_CYCLE == u8CurrentCycleExecutedByBFE)
      {
         *routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
         ret = RTE_E_OK;
         *Result = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
         dia_u8RequestResult0329 = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
      }
      else if (KU8_ROUTINE_STOPPED_WITHOUT_RESULTS == dia_u8RequestResult0329)
      {
         *routineInfo = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
         ret = RTE_E_OK;
         *Result = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
      }
      else if (KU8_ROUTINE_IN_PROGRESS == dia_u8RequestResult0329)
      {
         *routineInfo = KU8_ROUTINE_IN_PROGRESS;
         ret = RTE_E_OK;
         *Result = ROUTINE_STILL_RUNNING;
      }
      else
      {
         ret = RTE_E_RoutineServices_Routine_Trigger_BSR_Start_E_NOT_OK;
         *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
         *Result = ROUTINE_STOPPED_WITHOUT_RESULT;
      }
   }
   return (ret);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     routineInfo - pointer to routine status
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 *     Result - pointer to routine result
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0039, DSG_DIA_MMA_0197]
 **/

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runRid0329_TriggerBSRStart(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Trigger_BSR_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Trigger_BSR_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = RTE_E_OK;

   static uint8 dia_u8StartCyclePendingCounter = KU8_ZERO;

   /* Get the cycle to execute */
   const uint8 u8CycleToExecute = ROUTINE_TRIGGER_BSR_CYCLE;

   uint32 u32AECGroupStatus = KU32_ZERO;

   /* Local variable used to retrieve the executed cycle */
   uint8 u8CurrentCycleExecutedByBFE = KU8_NO_CYCLE;

    /*Get AEC Group Status*/
   (void) Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);

   /*Check if AECs are qualified*/
   if ( (KU32_ZERO == (u32AECGroupStatus & DIA_KU32_AEC_GROUP_MASK_BSR_INHIBIT)) )
   {
	   /*Check buckle switch on driver and passenger side*/
	   if (I_C02_BCKL_SW_STAT_OK == dia_u8BcklSwStatSignal)
	   {   /*Check if we reached the maximum number of call*/
	       if (KU8_START_CYCLE_MAXIMUM_TRY > dia_u8StartCyclePendingCounter)
		   {
			   /* Check if the requested cycle is running */
			   Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8CurrentCycleExecutedByBFE);

			   if ((u8CycleToExecute == u8CurrentCycleExecutedByBFE) && (KU8_NO_CYCLE != u8CycleToExecute))
			   {
				   /* Terminate the service */
				   *routineInfo = KU8_ROUTINE_IN_PROGRESS;
				   ret = RTE_E_OK;
				   dia_u8StartCyclePendingCounter = KU8_ZERO;
				   *Result = ROUTINE_STILL_RUNNING;
				   dia_u8RequestResult0329 = KU8_ROUTINE_IN_PROGRESS;
			   }
			   else
			   {
				   /* First call of the start function, check if the cycle is supported and send the request */
				   if (KU8_ZERO == dia_u8StartCyclePendingCounter)
				   {
					   /* Check if requested cycle is supported */
					   if ((KU8_NB_MAX_CYCLES - KU8_ONE) < u8CycleToExecute)
					   {
						   /* The requested cycle is not supported. Return NOK and set the dedicated NRC */
						   *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
						   ret = RTE_E_RoutineServices_Routine_Trigger_BSR_Start_E_NOT_OK;
						   dia_u8StartCyclePendingCounter = KU8_ZERO;
						   *Result = ROUTINE_STOPPED_WITHOUT_RESULT;
					   }
					   else
					   {
						   /* The requested cycle is supported. So execute the cycle */
						   Rte_IrvWrite_DIA_runRid0329_TriggerBSRStart_u8DiagRequestedCycle(u8CycleToExecute);
						   /* QAC_WARNING S 4570 1 */ /* The operand of this ~ operator has an 'essential type' which is narrower than type 'int'. */
						   /* Prepare the next function call */
						   OpStatus = RTE_E_RoutineServices_Routine_Trigger_BSR_Start_DCM_E_PENDING;
						   dia_u8StartCyclePendingCounter += KU8_ONE;
						   ret = RTE_E_RoutineServices_Routine_Trigger_BSR_Start_DCM_E_PENDING;

						   dia_u8RequestResult0329 = KU8_ROUTINE_IN_PROGRESS;
					   }
				   }
				   else
				   { /* Cycle request currently handled */
					   /* The maximum number of call is not reached, prepare the next call*/
					   OpStatus = RTE_E_RoutineServices_Routine_Trigger_BSR_Start_DCM_E_PENDING;
					   dia_u8StartCyclePendingCounter += KU8_ONE;
					   ret = RTE_E_RoutineServices_Routine_Trigger_BSR_Start_DCM_E_PENDING;
				   }
			   }
		   }
		   else
		   {
			   /* The requested cycle cannot be started. Return NOK and set the dedicated NRC */
			   dia_u8StartCyclePendingCounter = KU8_ZERO;

			   /* Update Requested Cycle and its complement */
			   Rte_IrvWrite_DIA_runRid0329_TriggerBSRStart_u8DiagRequestedCycle(KU8_NO_CYCLE);

			   *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			   ret = RTE_E_RoutineServices_Routine_Trigger_BSR_Start_E_NOT_OK;
			   *Result = ROUTINE_STOPPED_WITHOUT_RESULT;
		   }
	   }
	   else
	   {
		   *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		   ret = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_E_NOT_OK;
		   *Result = ROUTINE_STOPPED_WITHOUT_RESULT;
	   }
   }
   else
   {
	   *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
	   ret = RTE_E_RoutineServices_Routine_Trigger_BSR_Start_E_NOT_OK;
	   *Result = ROUTINE_STOPPED_WITHOUT_RESULT;
   }
   return (ret);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     routineInfo - pointer to routine status
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0040]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runRid0329_TriggerBSRStop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Trigger_BSR_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = RTE_E_OK;

   /* Local variable used to retrieve the executed cycle */
   uint8 u8CurrentCycleExecutedByBFE = KU8_NO_CYCLE;

   /* Local variable used to retrieve the Diag requested cycle */
   u8CycleNumberType u8DiagRequestedCycle = KU8_NO_CYCLE;

   /* Read the current executed cycle */
   Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8CurrentCycleExecutedByBFE);

   /* Read the current requested cycle */
   u8DiagRequestedCycle = Rte_IrvRead_DIA_runRid0330_TriggerTensioningCycleRequestResults_u8DiagRequestedCycle();

   /* Check if the requested cycle is running */
   /* Or if no Start routine was executed */
   if ((KU8_NO_CYCLE == u8CurrentCycleExecutedByBFE) ||
       (KU8_NO_CYCLE == u8DiagRequestedCycle))
   {
      if (KU8_ROUTINE_SUCCESSFULLY_COMPLETED == dia_u8RequestResult0329)
      {
         *routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
         ret = RTE_E_OK;
      }
      else if (KU8_ROUTINE_STOPPED_WITHOUT_RESULTS == dia_u8RequestResult0329)
      {
         *routineInfo = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
         ret = RTE_E_OK;
      }
      else if (KU8_ROUTINE_IN_PROGRESS == dia_u8RequestResult0329)
      {
         dia_u8RequestResult0329 = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
         /* Cycle stopped, the routine info byte (fifth byte) should be equal to 0xFF */
         *routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
      }
      else
      {
         *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
         ret = RTE_E_RoutineServices_Routine_Trigger_BSR_Start_E_NOT_OK;
      }
   }
   else
   {
      /* Update Requested Cycle and its complement */
      Rte_IrvWrite_DIA_runRid0330_TriggerTensioningCycleStart_u8DiagRequestedCycle(KU8_NO_CYCLE);

      DIA_stTensioningCycleStarted.routineStatus = TENSIONING_ROUTINE_STOPPED;

      /* Cycle stopped, the routine info byte (fifth byte) should be equal to 0xFF */
      *routineInfo = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;

      dia_u8RequestResult0329 = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
      ret = RTE_E_OK;
   }

   return (ret);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     routineInfo - pointer to routine status
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 *     Result - pointer to routine result
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0044, DSG_DIA_MMA_0202]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runRid0330_TriggerTensioningCycleRequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = RTE_E_OK;
   /* Local variable used to retrieve the executed cycle */
   uint8 u8CurrentCycleExecutedByBFE = KU8_NO_CYCLE;
   uint8 u8DiagRequestedCycle = KU8_NO_CYCLE;

   /* Get the executed cycle number */
   Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8CurrentCycleExecutedByBFE);
   u8DiagRequestedCycle = Rte_IrvRead_DIA_runRid0330_TriggerTensioningCycleRequestResults_u8DiagRequestedCycle();

   if ((u8DiagRequestedCycle == u8CurrentCycleExecutedByBFE) && (KU8_NO_CYCLE != u8CurrentCycleExecutedByBFE))
   {
      *routineInfo = KU8_ROUTINE_IN_PROGRESS;
      ret = RTE_E_OK;
      *Result = ROUTINE_STILL_RUNNING;
   }
   else if ( ((KU8_BELT_FUNCTION_18 == u8DiagRequestedCycle) && (KU8_BELT_FUNCTION_19 == u8CurrentCycleExecutedByBFE)) ||
		   ((KU8_BELT_FUNCTION_20 == u8DiagRequestedCycle) && (KU8_BELT_FUNCTION_21 == u8CurrentCycleExecutedByBFE)) ||
		   ((KU8_BELT_FUNCTION_22 == u8DiagRequestedCycle) && (KU8_BELT_FUNCTION_23 == u8CurrentCycleExecutedByBFE)) ||
		   ((KU8_BELT_FUNCTION_24 == u8DiagRequestedCycle) && (KU8_BELT_FUNCTION_25 == u8CurrentCycleExecutedByBFE)))
   {
      *routineInfo = KU8_ROUTINE_IN_PROGRESS;
      ret = RTE_E_OK;
      *Result = ROUTINE_STILL_RUNNING;
   }
   else
   {
      if (KU8_NO_CYCLE == u8CurrentCycleExecutedByBFE)
      {
         *routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
         ret = RTE_E_OK;
         *Result = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
         dia_u8RequestResult0330 = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
      }
      else if (KU8_ROUTINE_STOPPED_WITHOUT_RESULTS == dia_u8RequestResult0330)
      {
         *routineInfo = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
         ret = RTE_E_OK;
         *Result = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
      }
      else if (KU8_ROUTINE_IN_PROGRESS == dia_u8RequestResult0330)
      {
         *routineInfo = KU8_ROUTINE_IN_PROGRESS;
         ret = RTE_E_OK;
         *Result = ROUTINE_STILL_RUNNING;
      }
      else
      {
         ret = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_E_NOT_OK;
         *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
         *Result = ROUTINE_STOPPED_WITHOUT_RESULT;
      }
   }
   return (ret);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     routineInfo - pointer to routine status
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 *     Result - pointer to routine result
 *     Type_of_tensioning_cycle - type of tensioning cycle to trigger
 *     PreSafe_Duration - requested duration
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0043, DSG_DIA_MMA_0199, DSG_DIA_MMA_0200, DSG_DIA_MMA_0201]
 **/

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runRid0330_TriggerTensioningCycleStart(Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_Type_of_tensioning_cycleType Type_of_tensioning_cycle, Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_PreSafe_DurationType PreSafe_Duration, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = RTE_E_OK;
   static uint8 dia_u8StartCyclePendingCounter = KU8_ZERO;
   /* Get the cycle to execute */
   uint8 u8CycleToExecute;
   /* Local variable used to retrieve the executed cycle */
   uint8 u8CurrentCycleExecutedByBFE = KU8_NO_CYCLE;

   uint32 u32AECGroupStatus = KU32_ZERO;

   (void) Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);

   /*Check if AECs are qualified*/
   if (KU32_ZERO == u32AECGroupStatus)
   {	/*Check buckle switch on driver and passenger side*/
	   if (I_C02_BCKL_SW_STAT_OK == dia_u8BcklSwStatSignal)
	   {
		   if ((KU8_ZERO != Type_of_tensioning_cycle) && (KU8_TWENTYFIVE >= Type_of_tensioning_cycle))
		   {
			   u8CycleToExecute = DIA_u8TensioningCycleLUT[Type_of_tensioning_cycle - KU8_ONE]; /*LUT Cycle starts from 0; input requests starts from 1*/

			   /* Check if we reached the maximum number of call */
			   if (KU8_START_CYCLE_MAXIMUM_TRY > dia_u8StartCyclePendingCounter)
			   {
				   /* Check if the requested cycle is running */
				   Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8CurrentCycleExecutedByBFE);

				   if ((u8CycleToExecute == u8CurrentCycleExecutedByBFE) && (KU8_NO_CYCLE != u8CycleToExecute))
				   {
					   /* Terminate the service */
					   *routineInfo = KU8_ROUTINE_IN_PROGRESS;
					   ret = RTE_E_OK;
					   dia_u8StartCyclePendingCounter = KU8_ZERO;
					   *Result = ROUTINE_STILL_RUNNING;

					   /*Start timing task for*/
					   DIA_stTensioningCycleStarted.routineStatus = TENSIONING_ROUTINE_STARTED;
					   DIA_stTensioningCycleStarted.timeToRun = PreSafe_Duration;
					   DIA_stTensioningCycleStarted.requestedCycle = u8CycleToExecute;
					   dia_u8RequestResult0330 = KU8_ROUTINE_IN_PROGRESS;

				   }
				   else
				   {
					   /* First call of the start function, check if the cycle is supported and send the request */
					   if (KU8_ZERO == dia_u8StartCyclePendingCounter)
					   {
						   /* Check if requested cycle is supported */
						   if ((KU8_NB_MAX_CYCLES - KU8_ONE) < u8CycleToExecute)
						   {
							   /* The requested cycle is not supported. Return NOK and set the dedicated NRC */
							   *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
							   ret = RTE_E_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_E_NOT_OK;
							   dia_u8StartCyclePendingCounter = KU8_ZERO;
							   *Result = ROUTINE_STOPPED_WITHOUT_RESULT;
						   }
						   else
						   {
							   /* The requested cycle is supported. So execute the cycle */
							   Rte_IrvWrite_DIA_runRid0330_TriggerTensioningCycleStart_u8DiagRequestedCycle(u8CycleToExecute);
							   /* QAC_WARNING S 4570 1 */ /* The operand of this ~ operator has an 'essential type' which is narrower than type 'int'. */

							   /* Prepare the next function call */
							   OpStatus = RTE_E_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_DCM_E_PENDING;
							   dia_u8StartCyclePendingCounter += KU8_ONE;
							   ret = RTE_E_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_DCM_E_PENDING;
							   dia_u8RequestResult0330 = KU8_ROUTINE_IN_PROGRESS;
						   }
					   }
					   else
					   { /* Cycle request currently handled */
						   /* The maximum number of call is not reached, prepare the next call*/
						   OpStatus = RTE_E_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_DCM_E_PENDING;
						   dia_u8StartCyclePendingCounter += KU8_ONE;
						   ret = RTE_E_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_DCM_E_PENDING;
					   }
				   }
			   }
			   else
			   {
				   /* The requested cycle cannot be started. Return NOK and set the dedicated NRC */
				   dia_u8StartCyclePendingCounter = KU8_ZERO;

				   /* Update Requested Cycle and its complement */
				   Rte_IrvWrite_DIA_runRid0330_TriggerTensioningCycleStart_u8DiagRequestedCycle(KU8_NO_CYCLE);

				   *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
				   ret = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_E_NOT_OK;
				   *Result = ROUTINE_STOPPED_WITHOUT_RESULT;
			   }
		   }
		   else
		   {
			   *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
			   ret = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_E_NOT_OK;
			   *Result = ROUTINE_STOPPED_WITHOUT_RESULT;
		   }
	   }
	   else
	   {
		   *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		   ret = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_E_NOT_OK;
		   *Result = ROUTINE_STOPPED_WITHOUT_RESULT;
	   }
   }
   else
   {
	   *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
	   ret = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_E_NOT_OK;
	   *Result = ROUTINE_STOPPED_WITHOUT_RESULT;
   }
   	return (ret);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     routineInfo - pointer to routine status
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0042]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runRid0330_TriggerTensioningCycleStop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = RTE_E_OK;

   /* Local variable used to retrieve the executed cycle */
   uint8 u8CurrentCycleExecutedByBFE = KU8_NO_CYCLE;

   /* Local variable used to retrieve the Diag requested cycle */
   u8CycleNumberType u8DiagRequestedCycle = KU8_NO_CYCLE;

   /* Read the current executed cycle */
   Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8CurrentCycleExecutedByBFE);

   /* Read the current requested cycle */
   u8DiagRequestedCycle = Rte_IrvRead_DIA_runRid0330_TriggerTensioningCycleRequestResults_u8DiagRequestedCycle();

   /* Check if the requested cycle is running */
   /* Or if no Start routine was executed */
   if ((KU8_NO_CYCLE == u8CurrentCycleExecutedByBFE) ||
       (KU8_NO_CYCLE == u8DiagRequestedCycle))
   {
      if (KU8_ROUTINE_SUCCESSFULLY_COMPLETED == dia_u8RequestResult0330)
      {
         *routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
         ret = RTE_E_OK;
      }
      else if (KU8_ROUTINE_STOPPED_WITHOUT_RESULTS == dia_u8RequestResult0330)
      {
         *routineInfo = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
         ret = RTE_E_OK;
      }
      else if (KU8_ROUTINE_IN_PROGRESS == dia_u8RequestResult0330)
      {
         dia_u8RequestResult0330 = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
         /* Cycle stopped, the routine info byte (fifth byte) should be equal to 0xFF */
         *routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
      }
      else
      {
         *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
         ret = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_E_NOT_OK;
      }
   }
   else
   {
      /* Update Requested Cycle and its complement */
      Rte_IrvWrite_DIA_runRid0330_TriggerTensioningCycleStart_u8DiagRequestedCycle(KU8_NO_CYCLE);

      DIA_stTensioningCycleStarted.routineStatus = TENSIONING_ROUTINE_STOPPED;

      /* Cycle stopped, the routine info byte (fifth byte) should be equal to 0xFF */
      *routineInfo = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;

      dia_u8RequestResult0330 = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
      ret = RTE_E_OK;
   }

   return (ret);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     OpStatus - Operation status
 *     routineInfo
 *     Result
 *     ErrorCode - Negative response code
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0205, DSG_DIA_MMA_0206]
 **/
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE)
DIA_runRid0302_TriggerPresafeDisplayRequestRequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = RTE_E_OK;

   if (KU8_ROUTINE_IN_PROGRESS == dia_u8RequestResult0302)
   {
      *routineInfo = KU8_ROUTINE_IN_PROGRESS;
      *Result = ROUTINE_STILL_RUNNING;
      ret = RTE_E_OK;
   }
   else if (KU8_ROUTINE_SUCCESSFULLY_COMPLETED == dia_u8RequestResult0302)
   {
      *routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
      *Result = ROUTINE_TERMINATED_SUCCESSFULY;
      ret = RTE_E_OK;
   }
   else if (KU8_ROUTINE_STOPPED_WITHOUT_RESULTS == dia_u8RequestResult0302)
   {
      *routineInfo = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
      *Result = ROUTINE_STOPPED_WITHOUT_RESULT;
      ret = RTE_E_OK;
   }
   else
   {
      *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      *Result = ROUTINE_STOPPED_WITHOUT_RESULT;
      ret = RTE_E_RoutineServices_Routine_Trigger_Presafe_Display_Request_Start_E_NOT_OK;
   }

   return (ret);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     OpStatus - Operation status
 *     routineInfo
 *     Result
 *     ErrorCode - Negative response code
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0207]
 **/
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE)
DIA_runRid0302_TriggerPresafeDisplayRequestStart(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = RTE_E_OK;

   DIA_u8TriggerPreSafeRequest = KU8_TRIGGER_PRESAFE_ROUTINE_STARTED;
   /* Terminate the service */
   *routineInfo = KU8_ROUTINE_IN_PROGRESS;
   *Result = ROUTINE_STILL_RUNNING;

   return (ret);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     OpStatus - Operation status
 *     routineInfo
 *     ErrorCode - Negative response code
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0208]
 **/
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE)
DIA_runRid0302_TriggerPresafeDisplayRequestStop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
	Std_ReturnType ret = RTE_E_OK;

	if (KU16_ZERO == DIA_u16TriggerPreSafeCounter)
	{
		if(KU8_TRIGGER_PRESAFE_ROUTINE_STOPED == DIA_u8TriggerPreSafeRequest)
		{
			dia_u8RequestResult0302 = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
			*routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
		}
		else
		{
	        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
	        ret = RTE_E_RoutineServices_Routine_Trigger_BSR_Start_E_NOT_OK;
		}

	}
	else
	{
		dia_u8RequestResult0302 = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
		DIA_u8TriggerPreSafeRequest = KU8_TRIGGER_PRESAFE_ROUTINE_STOPED;
		DIA_u16TriggerPreSafeCounter = KU16_ZERO;
		Rte_Write_psePresafeDisplay_b8TriggerPreSafeRequestStatus(KU8_FALSE);
		*routineInfo = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
	}



   return (ret);
}
/**
* \brief
*     RID 0203
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0282]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRid0203_CheckProgrammingPreconditionsStart(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_Number_of_Unfulfilled_PreconditionsType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Number_of_Unfulfilled_Preconditions, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) List_of_Preconditions, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = RTE_E_OK;
   
   *Number_of_Unfulfilled_Preconditions = DIA_u8ActiveProgrammingPreconditions;
   VStdMemCpy(List_of_Preconditions, DIA_u8ProgrammingPreconditionsList, DIA_u8ActiveProgrammingPreconditions);
   *DataLength = DIA_u8ActiveProgrammingPreconditions;
   *routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;

   return ret;
}

FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE)
DIA_runDid0142_AvailabilityDataConditionsCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0209, DSG_DIA_MMA_0210]
 **/
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE)
DIA_runDid0142_AvailabilityDataRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;
   uint8 AvailabilityDataCategory;

   if (NULL_PTR != Data)
   {
      (void)Rte_Read_R_AvailabilityDataHandler_AvailabilityDataCategory(&AvailabilityDataCategory);

      *Data = AvailabilityDataCategory;

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     DataLength - Size of the Diagnostic Buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0211, DSG_DIA_MMA_0212]
 **/
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE)
DIA_runDid0241_PRE_SAFE_Recorder_1_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != DataLength)
   {
      *DataLength = (uint16)DIA_PRESAFE_RECORDER_LENGTH;

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE)
DIA_runDid0241_PRE_SAFE_Recorder_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE)
DIA_runDid0241_PRE_SAFE_Recorder_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData, sizeof(NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData));

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0250, DSG_DIA_MMA_0251]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0241_PRE_SAFE_Recorder_1_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   if (PRESAFE_RECORDER_RESET_VALUE == Data[0])
   {
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8EcuTemperatureStart[KU8_PRESAFE_1_ECUTEMPSTART_FIELD_0] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8EcuTemperatureStart[KU8_PRESAFE_1_ECUTEMPSTART_FIELD_1] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8EcuTemperatureStop[KU8_PRESAFE_1_ECUTEMPSTOP_FIELD_0] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8EcuTemperatureStop[KU8_PRESAFE_1_ECUTEMPSTOP_FIELD_1] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8LocalVoltageStart[KU8_PRESAFE_1_LOCAL_VOLTAGE_START] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8LocalVoltageStop[KU8_PRESAFE_1_LOCAL_VOLTAGE_STOP] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderStart[KU8_PRESAFE_1_START_FIELD_0] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderStart[KU8_PRESAFE_1_START_FIELD_1] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderState[KU8_PRESAFE_1_STATE_FIELD_0] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderState[KU8_PRESAFE_1_STATE_FIELD_1] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderStop[KU8_PRESAFE_1_STOP_FIELD_0] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderStop[KU8_PRESAFE_1_STOP_FIELD_1] = KU16_ZERO;
      for (uint8 startIterator = 0u; startIterator < sizeof(NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStart); startIterator++)
      {
         NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStart[startIterator] = KU16_ZERO;
      }
      for (uint8 stopIterator = 0u; stopIterator < sizeof(NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStart); stopIterator++)
      {
         NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStop[stopIterator] = KU16_ZERO;
      }

      /* Notify NVM of changes in the ram mirror */
      (void)Rte_Call_NvMService_NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_SetRamBlockStatus(TRUE);
   }
   else
   {
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
   }

   return E_OK;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     DataLength - Size of the Diagnostic Buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0213, DSG_DIA_MMA_0214]
 **/
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE)
DIA_runDid0242_PRE_SAFE_Recorder_2_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != DataLength)
   {
      *DataLength = (uint16)DIA_PRESAFE_RECORDER_LENGTH;

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE)
DIA_runDid0242_PRE_SAFE_Recorder_2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}
/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to the Diagnostic Buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0213, DSG_DIA_MMA_0214]
 **/
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE)
DIA_runDid0242_PRE_SAFE_Recorder_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData, sizeof(NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData));

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0252, DSG_DIA_MMA_0253]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0242_PRE_SAFE_Recorder_2_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   if (PRESAFE_RECORDER_RESET_VALUE == Data[0])
   {
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8EcuTemperatureStart[KU8_PRESAFE_2_ECUTEMPSTART_FIELD_0] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8EcuTemperatureStart[KU8_PRESAFE_2_ECUTEMPSTART_FIELD_1] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8EcuTemperatureStop[KU8_PRESAFE_2_ECUTEMPSTOP_FIELD_0] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8EcuTemperatureStop[KU8_PRESAFE_2_ECUTEMPSTOP_FIELD_1] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8LocalVoltageStart[KU8_PRESAFE_2_LOCAL_VOLTAGE_START] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8LocalVoltageStop[KU8_PRESAFE_2_LOCAL_VOLTAGE_STOP] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderStart[KU8_PRESAFE_2_START_FIELD_0] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderStart[KU8_PRESAFE_2_START_FIELD_1] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderState[KU8_PRESAFE_2_STATE_FIELD_0] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderState[KU8_PRESAFE_2_STATE_FIELD_1] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderStop[KU8_PRESAFE_2_STOP_FIELD_0] = KU16_ZERO;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderStop[KU8_PRESAFE_2_STOP_FIELD_1] = KU16_ZERO;
      for (uint8 startIterator = 0u; startIterator < sizeof(NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStart); startIterator++)
      {
         NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStart[startIterator] = KU16_ZERO;
      }
      for (uint8 stopIterator = 0u; stopIterator < sizeof(NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStart); stopIterator++)
      {
         NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStop[stopIterator] = KU16_ZERO;
      }

      /* Notify NVM of changes in the ram mirror */
      (void)Rte_Call_NvMService_NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_SetRamBlockStatus(TRUE);
   }
   else
   {
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
   }

   return E_OK;
}

FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0242, DSG_DIA_MMA_0243]
 **/
FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;
   REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96 stIgnitionSwitchState;

   Rte_Read_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3(&stIgnitionSwitchState);
   Rte_Read_DIA_AC_DiagOnCAN_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3(&stBckl_Sw_Fx_Stat);

   stIgnitionSwitchState.ISw_Stat_ST3 &= DIA_MASK_FOR_FIRST_3_BITS;
   stBckl_Sw_Fx_Stat.Bckl_Sw_D_Stat_ST3 &= DIA_MASK_FOR_FIRST_2_BITS;
   stBckl_Sw_Fx_Stat.Bckl_Sw_FP_Stat_ST3 &= DIA_MASK_FOR_FIRST_2_BITS;

   if (NULL_PTR != Data)
   {
      /*Set to 0 for reserved*/
      Data[0] = KU8_ZERO;
      /*Store 3 bits of ignition switch state*/
      Data[0] = stIgnitionSwitchState.ISw_Stat_ST3;
      /*1 bit rsereved*/
      /*Store 2 bits of buckle switch state for driver*/
      Data[0] |= (stBckl_Sw_Fx_Stat.Bckl_Sw_D_Stat_ST3 << 4);
      /*Store 2 bits of buckle switch state for front passenger*/
      Data[0] |= (stBckl_Sw_Fx_Stat.Bckl_Sw_FP_Stat_ST3) << 6;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0242, DSG_DIA_MMA_0243]
 **/
FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;
   REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j stPresfAct;

   Rte_Read_DIA_AC_DiagOnCAN_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3(&stPresfAct);

   stPresfAct.Presf_Lvl_ST3 &= DIA_MASK_FOR_FIRST_4_BITS;
   stPresfAct.Presf_Enbl_ST3 &= DIA_MASK_FOR_FIRST_2_BITS;

   if (DIA_RESFACT_TENSSUPP_RQ_ST3_SNA <= stPresfAct.PresfAct_TensSupp_Rq_ST3)
   {
      stPresfAct.PresfAct_TensSupp_Rq_ST3 = 0;
   }
   else
   {
      stPresfAct.PresfAct_TensSupp_Rq_ST3 &= DIA_MASK_FOR_FIRST_2_BITS;
   }

   if (NULL_PTR != Data)
   {
      /*Store 2 bit of presafe enabled*/
      Data[0] = stPresfAct.Presf_Enbl_ST3;
      /*Store 2 bit of presafe actuator tensioning supress request*/
      Data[0] |= (stPresfAct.PresfAct_TensSupp_Rq_ST3 << 2);
      /*Store 4 bits of presafe level*/
      Data[0] |= (stPresfAct.Presf_Lvl_ST3 << 4);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0242, DSG_DIA_MMA_0243]
 **/
FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;
   uint8 u8BeltHdOvr_FL, u8BeltHdOvr_FR;
   REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw stPTCoor4;

   Rte_Read_DIA_AC_DiagOnCAN_IF_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3(&u8BeltHdOvr_FL);
   Rte_Read_DIA_AC_DiagOnCAN_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3(&stPTCoor4);

   u8BeltHdOvr_FL &= DIA_MASK_FOR_FIRST_2_BITS;
   stPTCoor4.PT4_PTCoor_EngStartPN14_Stat_ST3 &= DIA_MASK_FOR_FIRST_3_BITS;

   if (ECU_SIDE_RBTM_FR == NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation)
   {
      u8BeltHdOvr_FR = u8BeltHdOvr_FL;
      u8BeltHdOvr_FL = KU8_ZERO;
   }
   else
   {
      u8BeltHdOvr_FR = KU8_ZERO;
   }

   if (NULL_PTR != Data)
   {
      /*Set to 0 for reserved*/
      Data[0] = KU8_ZERO;
      /*Store 2 bits of Belt hand over left state*/
      Data[0] = u8BeltHdOvr_FL;
      /*Store 2 bits of Belt hand over right state*/
      Data[0] |= (u8BeltHdOvr_FR << 2);
      /*Store 3 bits of Engine start state*/
      Data[0] |= (stPTCoor4.PT4_PTCoor_EngStartPN14_Stat_ST3 << 4);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0242, DSG_DIA_MMA_0243]
 **/
FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;
   REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19 stImpact3;
   REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw stEVC_Cfg_List;

   Rte_Read_DIA_AC_DiagOnCAN_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3(&stImpact3);
   Rte_Read_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3(&stEVC_Cfg_List);

   stImpact3.Impact_X_ST3 &= DIA_MASK_FOR_FIRST_BIT;
   stImpact3.Impact_RO_type1_ST3 &= DIA_MASK_FOR_FIRST_BIT;
   stImpact3.Impact_RO_type2_ST3 &= DIA_MASK_FOR_FIRST_BIT;
   stEVC_Cfg_List.EVC_List03_StStyle_ST3 &= DIA_MASK_FOR_FIRST_2_BITS;

   if (NULL_PTR != Data)
   {
      /*Set to 0 for reserved*/
      Data[0] = KU8_ZERO;
      /*Store 1 bit of Impact event X*/
      Data[0] = stImpact3.Impact_X_ST3;
      /*1 Byte reserved */
      /*Store 1 bit of Impact_RO_Type1_ST3*/
      Data[0] |= (stImpact3.Impact_RO_type1_ST3 << 2);
      Data[0] |= (stImpact3.Impact_RO_type2_ST3 << 3);
      /*Store 2 bit of EVC_List03_StStyle_ST3*/
      Data[0] |= (stEVC_Cfg_List.EVC_List03_StStyle_ST3 << 4);
      /*Last 2 bits are reserved*/

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0242, DSG_DIA_MMA_0243]
 **/
FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{

   Std_ReturnType ret = E_NOT_OK;
   uint8 u8ProdMdStat, u8TransMdStat;
   uint8 u8DDP_Sw_Stat;

   Rte_Read_IF_PN14_ProdMd_Stat_ST3_PN14_ProdMd_Stat_ST3(&u8ProdMdStat);
   Rte_Read_IF_PN14_TransMd_Stat_ST3_PN14_TransMd_Stat_ST3(&u8TransMdStat);
   Rte_Read_IF_PN14_DDP_Sw_Stat_ST3_PN14_DDP_Sw_Stat_ST3(&u8DDP_Sw_Stat);

   u8ProdMdStat &= DIA_MASK_FOR_FIRST_3_BITS;
   u8TransMdStat &= DIA_MASK_FOR_FIRST_2_BITS;
   u8DDP_Sw_Stat &= DIA_MASK_FOR_FIRST_3_BITS;

   if (NULL_PTR != Data)
   {
      /*Store 3 bits Supply battery cutoff switch status*/
      Data[0] = u8DDP_Sw_Stat;
      /*Store 3 bits Powernet Production mode status*/
      Data[0] |= (u8ProdMdStat << 3);
      /*Store 2 bits Powernet transport mode status*/
      Data[0] |= (u8TransMdStat << 6);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0242, DSG_DIA_MMA_0243]
 **/
FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;
   REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw stPTCoor4;
   REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh stDrvPosn_Gear;
   uint8 u8BltSlckDec;
   /*Get BltSlckDec_Md_Rq_HU_ST3*/
   Rte_Read_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3(&u8BltSlckDec);

   Rte_Read_DIA_AC_DiagOnCAN_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3(&stPTCoor4);
   Rte_Read_DIA_AC_DiagOnCAN_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(&stDrvPosn_Gear);

   stPTCoor4.PT4_PTCoor_PT_Rdy_ST3 &= DIA_MASK_FOR_FIRST_2_BITS;
   stDrvPosn_Gear.PT4_PTCoor_DrvPosn_Stat_ST3 &= DIA_MASK_FOR_FIRST_4_BITS;
   u8BltSlckDec &= DIA_MASK_FOR_FIRST_2_BITS;

   if (NULL_PTR != Data)
   {
      /*Store 2 bits of BltSlckDec_Md_Rq_HU_ST3*/
      Data[0] = u8BltSlckDec;
      /*Store 2 bits of Powertrain ready*/
      Data[0] |= (stPTCoor4.PT4_PTCoor_PT_Rdy_ST3 << 2);
      /*Store 4 bits of DrvPosn*/
      Data[0] |= (stDrvPosn_Gear.PT4_PTCoor_DrvPosn_Stat_ST3 << 4);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0242, DSG_DIA_MMA_0243]
 **/
FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;
   uint16 u16SuppBatRaw;
   uint8 u8SuppBat;

   Rte_Read_IF_PN14_SupBat_Volt_ST3_PN14_SupBat_Volt_ST3(&u16SuppBatRaw);
   u8SuppBat = (uint8)(u16SuppBatRaw / SUPBAT_CONVERSION_FACTOR);

   if (NULL_PTR != Data)
   {
      Data[0] = u8SuppBat;

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0242, DSG_DIA_MMA_0243]
 **/

FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;
   uint8 u8ExtTestPres;
   uint8 u8ExtTestPres_flag;
   boolean bDTCConfirmed;
   boolean bTimeoutExtTest;

   REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt stSBeltTens_SP;

   Rte_Read_IF_DidA_ExtTest_Pres_ST3_DidA_ExtTest_Pres_ST3(&u8ExtTestPres);
   Rte_Read_DIA_AC_DiagOnCAN_prrExtTestPres_b8ExtTesterPresent(&bTimeoutExtTest);
   Rte_Read_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3(&stSBeltTens_SP);
   Rte_Read_DIA_AC_DiagOnCAN_prrDTCConfirmed_b8DTCConfirmed (&bDTCConfirmed);
   if (TRUE == bTimeoutExtTest)
   {
	   u8ExtTestPres_flag = DIA_EXT_TESTER_PRESENT_SNA;
   }
   else if( ((B_TRUE == bTimeoutExtTest) && (B_TRUE ==bDTCConfirmed)) )
   {
    	u8ExtTestPres_flag =DIA_EXT_TESTER_PRESENT_FALSE;
   }
   else if ( ((DIA_EXT_TESTER_PRESENT_TRUE == u8ExtTestPres)  && (B_TRUE ==bDTCConfirmed)) )
   {
       u8ExtTestPres_flag =DIA_EXT_TESTER_PRESENT_TRUE;
    }
   else
   {
       u8ExtTestPres_flag =DIA_EXT_TESTER_PRESENT_FALSE;
   }

   stSBeltTens_SP.RBTMFL_SP_Lvl_Rq_ST35 &= DIA_MASK_FOR_FIRST_6_BITS;
   u8ExtTestPres_flag &= DIA_MASK_FOR_FIRST_2_BITS;

   if (NULL_PTR != Data)
   {
      Data[0] = stSBeltTens_SP.RBTMFL_SP_Lvl_Rq_ST35;
      Data[0] |= (u8ExtTestPres_flag << 6);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0242, DSG_DIA_MMA_0243]
 **/
FUNC(Std_ReturnType, DiagFunction_CODE)
DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;
   REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j stPresfAct;
   REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt stSBeltTens_SP;

   Rte_Read_DIA_AC_DiagOnCAN_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3(&stPresfAct);
   Rte_Read_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3(&stSBeltTens_SP);

   stSBeltTens_SP.RBTMFR_SP_Lvl_Rq_ST35 &= DIA_MASK_FOR_FIRST_6_BITS;

   if (NULL_PTR != Data)
   {
      Data[0] = stSBeltTens_SP.RBTMFR_SP_Lvl_Rq_ST35;
      Data[0] |= (stPresfAct.PresfAccelReset_NotExcd_ST3) << 6;

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0232, DSG_DIA_MMA_0233]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   Impl_Obsolescense_Data stObsolescenseData;

   Rte_Call_If_Obsolescence_Data_Get_Data(&stObsolescenseData);

   if (NULL_PTR != Data)
   {
      Data[0] = U16_GET_HIGH_BYTE(stObsolescenseData.BSR.Current_Value);
      Data[1] = U16_GET_LOW_BYTE(stObsolescenseData.BSR.Current_Value);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0232, DSG_DIA_MMA_0233]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   Impl_Obsolescense_Data stObsolescenseData;

   Rte_Call_If_Obsolescence_Data_Get_Data(&stObsolescenseData);

   if (NULL_PTR != Data)
   {
      Data[0] = U16_GET_HIGH_BYTE(stObsolescenseData.BSR.Threshold_Green_to_Yellow);
      Data[1] = U16_GET_LOW_BYTE(stObsolescenseData.BSR.Threshold_Green_to_Yellow);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0232, DSG_DIA_MMA_0233]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   Impl_Obsolescense_Data stObsolescenseData;

   Rte_Call_If_Obsolescence_Data_Get_Data(&stObsolescenseData);

   if (NULL_PTR != Data)
   {
      Data[0] = U16_GET_HIGH_BYTE(stObsolescenseData.BSR.Threshold_Yellow_to_Red);
      Data[1] = U16_GET_LOW_BYTE(stObsolescenseData.BSR.Threshold_Yellow_to_Red);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0232, DSG_DIA_MMA_0233]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   Impl_Obsolescense_Data stObsolescenseData;

   Rte_Call_If_Obsolescence_Data_Get_Data(&stObsolescenseData);

   if (NULL_PTR != Data)
   {
      Data[0] = U16_GET_HIGH_BYTE(stObsolescenseData.Haptic_Warning.Current_Value);
      Data[1] = U16_GET_LOW_BYTE(stObsolescenseData.Haptic_Warning.Current_Value);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0232, DSG_DIA_MMA_0233]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   Impl_Obsolescense_Data stObsolescenseData;

   Rte_Call_If_Obsolescence_Data_Get_Data(&stObsolescenseData);

   if (NULL_PTR != Data)
   {
      Data[0] = U16_GET_HIGH_BYTE(stObsolescenseData.Haptic_Warning.Threshold_Green_to_Yellow);
      Data[1] = U16_GET_LOW_BYTE(stObsolescenseData.Haptic_Warning.Threshold_Green_to_Yellow);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0232, DSG_DIA_MMA_0233]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   Impl_Obsolescense_Data stObsolescenseData;

   Rte_Call_If_Obsolescence_Data_Get_Data(&stObsolescenseData);

   if (NULL_PTR != Data)
   {
      Data[0] = U16_GET_HIGH_BYTE(stObsolescenseData.Haptic_Warning.Threshold_Yellow_to_Red);
      Data[1] = U16_GET_LOW_BYTE(stObsolescenseData.Haptic_Warning.Threshold_Yellow_to_Red);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0232, DSG_DIA_MMA_0233]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   Impl_Obsolescense_Data stObsolescenseData;

   Rte_Call_If_Obsolescence_Data_Get_Data(&stObsolescenseData);

   if (NULL_PTR != Data)
   {
      Data[0] = U16_GET_HIGH_BYTE(stObsolescenseData.PRE_CRASH.Current_Value);
      Data[1] = U16_GET_LOW_BYTE(stObsolescenseData.PRE_CRASH.Current_Value);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0232, DSG_DIA_MMA_0233]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   Impl_Obsolescense_Data stObsolescenseData;

   Rte_Call_If_Obsolescence_Data_Get_Data(&stObsolescenseData);

   if (NULL_PTR != Data)
   {
      Data[0] = U16_GET_HIGH_BYTE(stObsolescenseData.PRE_CRASH.Threshold_Green_to_Yellow);
      Data[1] = U16_GET_LOW_BYTE(stObsolescenseData.PRE_CRASH.Threshold_Green_to_Yellow);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0232, DSG_DIA_MMA_0233]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   Impl_Obsolescense_Data stObsolescenseData;

   Rte_Call_If_Obsolescence_Data_Get_Data(&stObsolescenseData);

   if (NULL_PTR != Data)
   {
      Data[0] = U16_GET_HIGH_BYTE(stObsolescenseData.PRE_CRASH.Threshold_Yellow_to_Red);
      Data[1] = U16_GET_LOW_BYTE(stObsolescenseData.PRE_CRASH.Threshold_Yellow_to_Red);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0232, DSG_DIA_MMA_0233]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   Impl_Obsolescense_Data stObsolescenseData;

   Rte_Call_If_Obsolescence_Data_Get_Data(&stObsolescenseData);

   if (NULL_PTR != Data)
   {
      Data[0] = U16_GET_HIGH_BYTE(stObsolescenseData.PRE_SAFE_LVL_4_5.Current_Value);
      Data[1] = U16_GET_LOW_BYTE(stObsolescenseData.PRE_SAFE_LVL_4_5.Current_Value);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0232, DSG_DIA_MMA_0233]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   Impl_Obsolescense_Data stObsolescenseData;

   Rte_Call_If_Obsolescence_Data_Get_Data(&stObsolescenseData);

   if (NULL_PTR != Data)
   {
      Data[0] = U16_GET_HIGH_BYTE(stObsolescenseData.PRE_SAFE_LVL_4_5.Threshold_Green_to_Yellow);
      Data[1] = U16_GET_LOW_BYTE(stObsolescenseData.PRE_SAFE_LVL_4_5.Threshold_Green_to_Yellow);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0232, DSG_DIA_MMA_0233]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   Impl_Obsolescense_Data stObsolescenseData;

   Rte_Call_If_Obsolescence_Data_Get_Data(&stObsolescenseData);

   if (NULL_PTR != Data)
   {
      Data[0] = U16_GET_HIGH_BYTE(stObsolescenseData.PRE_SAFE_LVL_4_5.Threshold_Yellow_to_Red);
      Data[1] = U16_GET_LOW_BYTE(stObsolescenseData.PRE_SAFE_LVL_4_5.Threshold_Yellow_to_Red);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* [COVERS: DSG_DIA_MMA_0263]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0210_CAN_output_Read_CANoutput1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
* [COVERS: DSG_DIA_MMA_0263]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0210_CAN_output_Read_CANoutput1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   c02_Presf_Disp_Rq presfDispReq;
   c02_Off_On BltSlckDecMD;
   
   /*Read needed signals*/
   if (ECU_SIDE_RBTM_FR == NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation)
   {
      Rte_Read_IF_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3(&presfDispReq);
   }
   else
   {
      Rte_Read_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3(&presfDispReq);
   }

   Rte_Read_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3(&BltSlckDecMD);

   /*Prepare diagnostic response*/
   Data[0] = presfDispReq;
   Data[0] |= (BltSlckDecMD << 2);

   return RTE_E_OK;
}

/**
* [COVERS: DSG_DIA_MMA_0263]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
* [COVERS: DSG_DIA_MMA_0263]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   c02_Off_Stage1_Stage2 PSCurve;

   /*Read needed signals*/
   if (ECU_SIDE_RBTM_FR == NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation)
   {
      Rte_Read_IF_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3(&PSCurve);
   }
   else
   {

      Rte_Read_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3(&PSCurve);
   }

   /*Prepare diagnostic response*/
   Data[0] = PSCurve;

   return RTE_E_OK;
}

/**
* [COVERS: DSG_DIA_MMA_0263]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
* [COVERS: DSG_DIA_MMA_0263]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   c06_RBTM_Lvl_Stat ActvLvl;

   /*Read needed signals*/
   if (ECU_SIDE_RBTM_FR == NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation)
   {
      Rte_Read_IF_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35(&ActvLvl);
   }
   else
   {
      Rte_Read_IF_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35(&ActvLvl);
   }

   /*Prepare diagnostic response*/
   Data[0] = ActvLvl;

   return RTE_E_OK;
}

/**
* [COVERS: DSG_DIA_MMA_0263]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
* [COVERS: DSG_DIA_MMA_0263]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   c04_RBTM_ActvClient ActvClient;

   /*Read needed signals*/
   if (ECU_SIDE_RBTM_FR == NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation)
   {
      Rte_Read_IF_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35(&ActvClient);
   }
   else
   {
      Rte_Read_IF_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35(&ActvClient);
   }

   /*Prepare diagnostic response*/
   Data[0] = ActvClient;

   return RTE_E_OK;
}

/**
* [COVERS: DSG_DIA_MMA_0263]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
* [COVERS: DSG_DIA_MMA_0263]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   c10_RBTM_Fct_Precond FctPrecond;

   /*Read needed signals*/
   if (ECU_SIDE_RBTM_FR == NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation)
   {
      Rte_Read_IF_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35(&FctPrecond);
   }
   else
   {
      Rte_Read_IF_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35(&FctPrecond);
   }

   /*Prepare diagnostic response*/
   Data[1] = (uint8)FctPrecond;
   Data[0] = (uint8)(FctPrecond >> 8);
   return RTE_E_OK;
}

/**
* [COVERS: DSG_DIA_MMA_0266]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0220_HW_input_Read_Voltage_KL30t_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
* [COVERS: DSG_DIA_MMA_0266]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0220_HW_input_Read_Voltage_KL30t_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;
   uint16 batteryVoltage;

   (void)Rte_Call_pclKL30_V_Get(&batteryVoltage);

   if (NULL_PTR != Data)
   {
      Data[0] = batteryVoltage / DIA_KU16_VOLTAGE_CONVERSION;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* [COVERS: DSG_DIA_MMA_0266]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0220_HW_input_Read_Voltage_Motor_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
  return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
* [COVERS: DSG_DIA_MMA_0266]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0220_HW_input_Read_Voltage_Motor_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;
   uint16 motorVoltage;

   (void)Rte_Call_pclMotor_Vp_Get(&motorVoltage);

   if (NULL_PTR != Data)
   {
      Data[0] = motorVoltage / DIA_KU16_VOLTAGE_CONVERSION;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* [COVERS: DSG_DIA_MMA_0267]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
* [COVERS: DSG_DIA_MMA_0267]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;
   Rte_ModeType_EcuM_Mode ecuM_Mode;

   ecuM_Mode = Rte_Mode_DIA_AC_DiagOnCAN_EcuM_CurrentMode_currentMode();

   switch (ecuM_Mode)
   {
   case 0:
      ecuM_Mode = DIA_ECUM_STATE_STARTUP;
      break;
   case 1:
      ecuM_Mode = DIA_ECUM_STATE_WAKEUP;
      break;
   case 2:
      ecuM_Mode = DIA_ECUM_STATE_RUN;
      break;
   case 3:
      ecuM_Mode = DIA_ECUM_STATE_SHUTDOWN;
      break;
   case 4:
      ecuM_Mode = DIA_ECUM_STATE_SLEEP;
      break;
   case 5:
      ecuM_Mode = DIA_ECUM_STATE_SLEEP;
      break;
   case 6:
      ecuM_Mode = DIA_ECUM_STATE_SLEEP;
      break;
   default:
      break;
   }

   if (NULL_PTR != Data)
   {
      Data[0] = ecuM_Mode;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* [COVERS: DSG_DIA_MMA_0267]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
  return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
* [COVERS: DSG_DIA_MMA_0267]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;
   sint16 filteredTemperature_deg;
   uint16 convertedTemperature_deg;

   (void)Rte_Call_pclECUT_T_GetFiltered_deg(&filteredTemperature_deg);
   convertedTemperature_deg = DIA_U16_CONVERT_TEMP_TO_RAW(filteredTemperature_deg);

   if (NULL_PTR != Data)
   {
      Data[0] = (uint8)U16_GET_HIGH_BYTE((uint16)convertedTemperature_deg);
      Data[1] = (uint8)U16_GET_LOW_BYTE((uint16)convertedTemperature_deg);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* [COVERS: DSG_DIA_MMA_0267]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
  return ConditionCheckRead_General(OpStatus, ErrorCode);
}

/**
* [COVERS: DSG_DIA_MMA_0267]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;
   sint32 s32ScaledMotorCurrent;
   uint32 u32convertedMotorCurrent;

   (void)Rte_Call_pclMotor_I_Get_mA(&s32ScaledMotorCurrent);
   u32convertedMotorCurrent = DIA_KU32_CONVERT_CURENT(s32ScaledMotorCurrent);

   if (NULL_PTR != Data)
   {
      Data[1] = (uint8)U32_GET_LOW_MIDDLE_BYTE( (uint32)(u32convertedMotorCurrent) );
      Data[0] = (uint8)U32_GET_LOW_BYTE( (uint32)(u32convertedMotorCurrent) );

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

#define DIA_AC_DiagOnCAN_STOP_SEC_CODE
#include "DIA_AC_DiagOnCAN_MemMap.h"

/******************************************************************************
 Evolution of the component

 created by : T. DEMIREL

 $Log: DIA_CustomerSpecific.c  $
 Revision 1.58 2024/03/06 11:23:40CET Madalina Serban (madalina.serban) 
 Small fix
 Revision 1.57 2024/03/04 08:49:21EET Madalina Serban (madalina.serban) 
 Trigger routine updated
 Revision 1.56 2024/02/01 14:24:02EET Madalina Serban (madalina.serban) 
 Fixed always in progress issue
 Revision 1.55 2024/01/18 10:17:12EET Tudor Gligor (tudor.gligor) 
 Update Design Traceability for DIA R8.1 Release
 Revision 1.54 2024/01/09 14:13:01EET Madalina Serban (madalina.serban) 
 Minor fix
 Revision 1.53 2024/01/09 13:44:13EET Madalina Serban (madalina.serban) 
 Updated code for ExtTester present signal
 Revision 1.52 2024/01/05 14:12:41EET Emanuel Jivan (emanuel.jivan) 
 Implemented Check Programming Preconditions, including during programming session request.
 Revision 1.51 2023/11/03 11:41:51EET Madalina Serban (madalina.serban) 
 Routine 0302 fixed
 Revision 1.50 2023/11/02 14:41:55EET Madalina Serban (madalina.serban) 
 Small fix
 Revision 1.49 2023/11/02 10:46:37EET Madalina Serban (madalina.serban) 
 Updated Results for 0329, 0330
 Revision 1.48 2023/10/30 15:46:24EET Madalina Serban (madalina.serban) 
 Fix after review
 Revision 1.47 2023/10/25 09:40:18EEST Madalina Serban (madalina.serban) 
 Fix after review
 Revision 1.46 2023/10/23 11:07:33EEST Madalina Serban (madalina.serban) 
 HWA 2,3,4 fix
 Revision 1.45 2023/10/16 09:32:19EEST Madalina Serban (madalina.serban) 
 Updated conversion factor
 Revision 1.44 2023/08/07 10:11:48EEST Andreea Negrea (andreea.negrea) 
 Update service 0240
 Revision 1.43 2023/07/24 10:07:11EEST Madalina Serban (madalina.serban) 
 Fixes after review
 Revision 1.42 2023/07/20 10:28:29EEST Madalina Serban (madalina.serban) 
 QAC fixes
 Revision 1.41 2023/07/19 10:01:13EEST Madalina Serban (madalina.serban) 
 Routines 0x0329, 0x0330 fix
 Revision 1.40 2023/06/20 16:07:22EEST Tudor Gligor (tudor.gligor) 
 Update DIA Design Document for R6.1 Release + Code Traceability in DIA_CustomerSpecific for the 2 DIDs 0220/0240
 Revision 1.39 2023/06/15 08:31:38EEST Emanuel Jivan (emanuel.jivan) 
 Corrected CAN Input read.
 Revision 1.38 2023/06/14 10:56:22EEST Tudor Gligor (tudor.gligor) 
 Update HW Input Read with the correct Voltage Conversion received from PMP and according with CDD formula.
 Revision 1.37 2023/06/09 14:01:05EEST Tudor Gligor (tudor.gligor) 
 Update HW Input Read & Internal ECU Information Read according to the CDD Requirements
 Revision 1.36 2023/06/07 14:19:33EEST Tudor Gligor (tudor.gligor) 
 Populate 0220 & 0240 Routines with Data from PMP & PAL
 Revision 1.35 2023/05/30 17:58:21EEST Tudor Gligor (tudor.gligor) 
 Create dummy and compilable 0220 & 0240 in DIA_CustomerSpecific with all dependencies
 Revision 1.34 2023/05/11 10:40:08EEST Tudor Gligor (tudor.gligor) 
 Update DIA Design Document, DIA Code Design Traceability & DIA Design Configurator Traceability
 Revision 1.33 2023/05/04 13:41:30EEST Tudor Gligor (tudor.gligor) 
 Minor QAC fixes for DIA - R6.0
 Revision 1.32 2023/04/27 12:21:06EEST Emanuel Jivan (emanuel.jivan) 
 Fixed FctPrecond runnable for 0x0210.
 Revision 1.31 2023/04/13 16:24:59EEST Emanuel Jivan (emanuel.jivan) 
 Implemented 22 0210.
 Revision 1.30 2023/03/08 11:48:21EET Andreea Negrea (andreea.negrea)
 Fix after review
 Revision 1.29 2023/03/08 10:48:52EET Tudor Gligor (tudor.gligor)
 Update the code with fixes related to the Review Findings
 Revision 1.28 2023/03/07 15:38:55EET Madalina Serban (madalina.serban)
 Updated implementation
 Revision 1.27 2023/03/06 17:17:36EET Andreea Negrea (andreea.negrea)
 Update RID 0329 and 0330
 Revision 1.26 2023/03/01 16:31:22EET Tudor Gligor (tudor.gligor)
 Update Pre-Safe Recorder 1/2 Reset with SetRamBlockStatus API
 Revision 1.25 2023/02/22 18:16:22EET Tudor Gligor (tudor.gligor)
 Update Design traceability in the code for R5.0 Release for DIA Component
 Revision 1.24 2023/02/01 10:41:23EET Madalina Serban (madalina.serban)
 Implementation for Presafe display request
 Revision 1.23 2023/01/31 18:20:44EET Stefan Dominte (stefan.dominte)
 Presafe recorder 1 and 2 length was chaged to a fixed 22 bytes.
 Revision 1.22 2023/01/31 11:45:19EET Tudor Gligor (tudor.gligor)
 Implement RoELite for the following PDUs:
 AvailabilityData
 ObsolescenceData
 DiagSessionChange
 Dependencies in MMG, EOL & DiagFunction
 Revision 1.21 2023/01/27 10:35:31EET Emanuel Jivan (emanuel.jivan)
 Fully implemented 0140 with EOL data handling.
 Revision 1.19 2023/01/10 11:44:53EET Emanuel Jivan (emanuel.jivan)
 Updated diagnostics with V060 config, modified 0241 and 0200 format and added 22 FD01.
 Revision 1.18 2022/12/22 17:12:10EET Mirela Obada (mirela.obada)
 Update code because of new name of Mask of an AEC group
 Revision 1.17 2022/12/13 11:24:23EET Emanuel Jivan (emanuel.jivan)
 Fixed build error.
 Revision 1.16 2022/12/09 18:21:48EET Emanuel Jivan (emanuel.jivan)
 Implemented DID 0200.
 Revision 1.15 2022/11/24 11:17:15EET Tudor Gligor (tudor.gligor)
 Stub the new ST3 signals to 0 instead of 160 to return a value as default as possible to avoid out of ranges.
 Revision 1.14 2022/11/24 09:43:04EET Stefan Dominte (stefan.dominte)
 DIA runnables and input interfaces created for CAN input 0x0200 DID
 Revision 1.13 2022/11/04 13:49:12EET Tudor Gligor (tudor.gligor)
 Update indentation for DIA_CustomerSpecific after QAC Analysis
 Revision 1.12 2022/11/03 14:04:32EET Tudor Gligor (tudor.gligor)
 Initial implementation of RWDBI 0241/0242 for the Pre-Safe Recorder1/2 mechanism
 Revision 1.11 2022/11/03 12:11:15EET Mirela Obada (mirela.obada)
 Add implementation for Trigger Presafe Request(0302) and Availability Data Read (0142)
 Revision 1.10 2022/11/01 13:16:07EET Mirela Obada (mirela.obada)
 Added function for 4.0 diagnosis implementation
 Revision 1.9 2022/10/31 15:49:26EET Emanuel Jivan (emanuel.jivan)
 Diagnostic CDD integration for 05.05.03. Added routine 0302.
 Revision 1.8 2022/10/31 11:53:22EET Emanuel Jivan (emanuel.jivan)
 Reverted changes due to Configurator error.
 Revision 1.6 2022/09/06 17:28:10EEST Tudor Gligor (tudor.gligor)
 [SRC] Code Update for QAC fixes - DIA
 Revision 1.5 2022/08/09 13:10:56EEST Emanuel Jivan (emanuel.jivan)
 Implemented RID 0329 and 0330; added 50ms cyclic task.
 Revision 1.4 2022/08/04 09:30:44EEST Emanuel Jivan (emanuel.jivan)
 R3.0 diag update; added runnables, code to be added later.
 Revision 1.3 2022/03/25 15:06:55EET Emanuel Jivan (emanuel.jivan)
 Updated code template, added tracebility in code and fixed tracebility in design.
 Revision 1.2 2022/01/21 10:18:18EET Emanuel Jivan (emanuel.jivan)
 Moved 0340 and F18C here, added write for 0340.
 Revision 1.1 2022/01/07 15:24:33EET Andreea Negrea (andreea.negrea)
 Initial revision
 Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/DIA/Implementation/src/project.pj
 Revision 1.1 2021/11/01 10:25:52EET Andreea Negrea (andreea.negrea)
 First revision

******************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
