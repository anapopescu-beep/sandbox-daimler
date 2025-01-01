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
 *             File:  Ct_ResourceMeasurement.c
 *           Config:  S:\Tools\Vector_configuration\Workspace\Daimler MMA/S:/Tools/Vector_configuration/Workspace/Daimler MMA/StartApplication.dpa
 *        SW-C Type:  Ct_ResourceMeasurement
 *  Generation Time:  2023-12-13 12:40:14
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  C-Code implementation template for SW-C <Ct_ResourceMeasurement>
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
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_OpStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_Clear_Resource_Consumption_Data_Start_routineInfoPrimitiveType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_Clear_Resource_Consumption_Data_Start_routineInfoType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_Ct_ResourceMeasurement.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "vstdlib.h"
#include "Rtm.h"
#include "Fee.h"

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
 * Dcm_NegativeResponseCodeType: Integer in interval [0...255]
 * Dcm_OpStatusType: Integer in interval [0...64]
 * Dcm_StartDataOut_Routine_Clear_Resource_Consumption_Data_Start_routineInfoPrimitiveType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_Clear_Resource_Consumption_Data_Start_routineInfoType: Integer in interval [0...255]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * Dcm_Data1275ByteType: Array with 1275 element(s) of type uint8
 * Dcm_Data3060ByteType: Array with 3060 element(s) of type uint8
 * Dcm_Data4080ByteType: Array with 4080 element(s) of type uint8
 * Dcm_Data510ByteType: Array with 510 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define Ct_ResourceMeasurement_START_SEC_CODE
#include "Ct_ResourceMeasurement_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_CPU_Load_Read_CPU_load_histograms_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_CPU_Load_Read_CPU_load_histograms>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_CPU_Load_Read_CPU_load_histograms_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_CPU_Load_Read_CPU_load_histograms_DCM_E_PENDING
 *   RTE_E_DataServices_CPU_Load_Read_CPU_load_histograms_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_CPU_Load_Read_CPU_load_histograms_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_CPU_Load_Read_CPU_load_histograms_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_CPU_Load_Read_CPU_load_histograms_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_CPU_Load_Read_CPU_load_histograms_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_CPU_Load_Read_CPU_load_histograms>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_CPU_Load_Read_CPU_load_histograms_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3060ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_CPU_Load_Read_CPU_load_histograms_DCM_E_PENDING
 *   RTE_E_DataServices_CPU_Load_Read_CPU_load_histograms_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_CPU_Load_Read_CPU_load_histograms_ReadData_doc
 *********************************************************************************************************************/

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
*   [COVERS: DSG_DIA_MMA_0234]
**/

#define RESOURCE_MEASUREMENT_DIAG_STUB_NUMBER_OF_CPULOAD_PERCENTILES          RTM_NUMBER_OF_CPULOAD_PERCENTILES + 1
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_CPU_Load_Read_CPU_load_histograms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_CPU_Load_Read_CPU_load_histograms_ReadData (returns application error)
 *********************************************************************************************************************/

    uint8 locCPULoadHistogramsData[RTM_NUMBER_OF_CORES * (1 + RESOURCE_MEASUREMENT_DIAG_STUB_NUMBER_OF_CPULOAD_PERCENTILES)];
    Rtm_CpuLoadHistogramType locCpuLoadHistograms;
    uint8 locCoreOffset = 0;

    locCPULoadHistogramsData[locCoreOffset] = 0u;
    Rtm_GetCpuLoadHistogram(0u, &locCpuLoadHistograms);
    VStdLib_MemCpy(&locCPULoadHistogramsData[locCoreOffset+1], &locCpuLoadHistograms, RESOURCE_MEASUREMENT_DIAG_STUB_NUMBER_OF_CPULOAD_PERCENTILES);

    VStdLib_MemCpy(Data, &locCPULoadHistogramsData, (RTM_NUMBER_OF_CORES * (1 + RESOURCE_MEASUREMENT_DIAG_STUB_NUMBER_OF_CPULOAD_PERCENTILES)));
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_CPU_Load_Read_CPU_load_histograms_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_CPU_Load_Read_CPU_load_histograms>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_CPU_Load_Read_CPU_load_histograms_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_CPU_Load_Read_CPU_load_histograms_DCM_E_PENDING
 *   RTE_E_DataServices_CPU_Load_Read_CPU_load_histograms_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_CPU_Load_Read_CPU_load_histograms_ReadDataLength_doc
 *********************************************************************************************************************/

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
*   [COVERS: DSG_DIA_MMA_0235]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_CPU_Load_Read_CPU_load_histograms_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_CPU_Load_Read_CPU_load_histograms_ReadDataLength (returns application error)
 *********************************************************************************************************************/

  *DataLength = RTM_NUMBER_OF_CORES * (1 + RESOURCE_MEASUREMENT_DIAG_STUB_NUMBER_OF_CPULOAD_PERCENTILES);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_DCM_E_PENDING
 *   RTE_E_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1275ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_DCM_E_PENDING
 *   RTE_E_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData_doc
 *********************************************************************************************************************/

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
*   [COVERS: DSG_DIA_MMA_0240]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType feeRetValue = RTE_E_INVALID;
  uint32 feeCounter = 0;
  uint16 blockCounter = 0;

  for (uint8 block = 0; block < Fee_Config.FeeBlkCnt; block++)
  {
      /* get counter of fee block. If return value is not ok, set value to -1 */
      feeRetValue = Fee_17_GetCycleCount(Fee_Config.FeeBlockConfigPtr[block].BlockNumber, &feeCounter);
      if (feeRetValue != RTE_E_OK) {
          feeCounter = -1;
      }
      Data[blockCounter++] = block;

      /* change MSB <-> LSB for feeCounter */
      Data[blockCounter++] = (uint8)(feeCounter >> 24);
      Data[blockCounter++] = (uint8)(feeCounter >> 16);
      Data[blockCounter++] = (uint8)(feeCounter >> 8);
      Data[blockCounter++] = (uint8)(feeCounter >> 0);
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_DCM_E_PENDING
 *   RTE_E_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadDataLength_doc
 *********************************************************************************************************************/

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
*   [COVERS: DSG_DIA_MMA_0241]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  *DataLength = 5u * Fee_Config.FeeBlkCnt; /* 8 bit blockId + 32 bit writeCounter = 5 Byte per block */
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Stack_Load_Read_Maximum_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Stack_Load_Read_Maximum>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Stack_Load_Read_Maximum_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Stack_Load_Read_Maximum_DCM_E_PENDING
 *   RTE_E_DataServices_Stack_Load_Read_Maximum_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Stack_Load_Read_Maximum_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Stack_Load_Read_Maximum_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Stack_Load_Read_Maximum_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Stack_Load_Read_Maximum_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Stack_Load_Read_Maximum>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Stack_Load_Read_Maximum_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data510ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Stack_Load_Read_Maximum_DCM_E_PENDING
 *   RTE_E_DataServices_Stack_Load_Read_Maximum_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Stack_Load_Read_Maximum_ReadData_doc
 *********************************************************************************************************************/

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
*   [COVERS: DSG_DIA_MMA_0238]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Stack_Load_Read_Maximum_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Stack_Load_Read_Maximum_ReadData (returns application error)
 *********************************************************************************************************************/

 uint8 locTaskUsageData[2 * Rtm_GetSizeOfOsTaskInfoOfPCConfig()];
 Rtm_TaskStackUsageInfoType taskStackUsage;

 for (uint8 taskId = 0; taskId < Rtm_GetSizeOfOsTaskInfoOfPCConfig(); taskId++) {
     Rtm_GetTaskStackUsage(taskId, &taskStackUsage);
     locTaskUsageData[taskId * 2] = Rtm_GetTaskIdOfOsTaskInfo(taskId);
     locTaskUsageData[(taskId * 2) + 1] = (uint8)(taskStackUsage.MaxStackUsage/(taskStackUsage.TaskStackSize * 0.01));
 }

  VStdLib_MemCpy(Data, &locTaskUsageData, (2 * RTM_NUMBER_OF_TASKS));
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Stack_Load_Read_Maximum_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Stack_Load_Read_Maximum>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Stack_Load_Read_Maximum_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Stack_Load_Read_Maximum_DCM_E_PENDING
 *   RTE_E_DataServices_Stack_Load_Read_Maximum_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Stack_Load_Read_Maximum_ReadDataLength_doc
 *********************************************************************************************************************/

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
*   [COVERS: DSG_DIA_MMA_0239]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Stack_Load_Read_Maximum_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Stack_Load_Read_Maximum_ReadDataLength (returns application error)
 *********************************************************************************************************************/

  *DataLength = RTM_NUMBER_OF_TASKS * 2;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Task_Response_Time_Read_Task_histograms_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Task_Response_Time_Read_Task_histograms>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Task_Response_Time_Read_Task_histograms_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Task_Response_Time_Read_Task_histograms_DCM_E_PENDING
 *   RTE_E_DataServices_Task_Response_Time_Read_Task_histograms_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Task_Response_Time_Read_Task_histograms_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0274]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Task_Response_Time_Read_Task_histograms_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Task_Response_Time_Read_Task_histograms_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Task_Response_Time_Read_Task_histograms_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Task_Response_Time_Read_Task_histograms>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Task_Response_Time_Read_Task_histograms_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4080ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Task_Response_Time_Read_Task_histograms_DCM_E_PENDING
 *   RTE_E_DataServices_Task_Response_Time_Read_Task_histograms_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Task_Response_Time_Read_Task_histograms_ReadData_doc
 *********************************************************************************************************************/
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
*   [COVERS: DSG_DIA_MMA_0274]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Task_Response_Time_Read_Task_histograms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Task_Response_Time_Read_Task_histograms_ReadData (returns application error)
 *********************************************************************************************************************/

  Rtm_TaskResponseTimeHistogramType taskResponseTime;
  uint16 i = 0;

  for (uint8 taskId = 0; taskId < RTM_NUMBER_OF_TASKS; taskId++) {
      Rtm_GetTaskResponseTimeHistogram(taskId, &taskResponseTime);

      Data[i++] = taskId;
      VStdLib_MemCpy(&Data[i], &taskResponseTime.Percentiles, RTM_NUMBER_OF_TASKRESPONSETIME_PERCENTILES+1);
      i = i + RTM_NUMBER_OF_TASKRESPONSETIME_PERCENTILES+1;
      /* change MSB <-> LSB for max response time */
      Data[i++] = (uint8)(taskResponseTime.MaxRuntimeInUs >> 24);
      Data[i++] = (uint8)(taskResponseTime.MaxRuntimeInUs >> 16);
      Data[i++] = (uint8)(taskResponseTime.MaxRuntimeInUs >> 8);
      Data[i++] = (uint8)(taskResponseTime.MaxRuntimeInUs >> 0);
  }
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Task_Response_Time_Read_Task_histograms_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Task_Response_Time_Read_Task_histograms>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Task_Response_Time_Read_Task_histograms_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Task_Response_Time_Read_Task_histograms_DCM_E_PENDING
 *   RTE_E_DataServices_Task_Response_Time_Read_Task_histograms_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Task_Response_Time_Read_Task_histograms_ReadDataLength_doc
 *********************************************************************************************************************/
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
*   [COVERS: DSG_DIA_MMA_0274]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Task_Response_Time_Read_Task_histograms_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Task_Response_Time_Read_Task_histograms_ReadDataLength (returns application error)
 *********************************************************************************************************************/

  *DataLength = (RTM_NUMBER_OF_TASKRESPONSETIME_PERCENTILES + 6) * RTM_NUMBER_OF_TASKS; /* add uint8 taskId + uint32 maxValue + uint8 >200% Percentile */
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Clear_Resource_Consumption_Data_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_Start(Dcm_OpStatusType OpStatus, Dcm_StartDataOut_Routine_Clear_Resource_Consumption_Data_Start_routineInfoType *routineInfo, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_Start_doc
 *********************************************************************************************************************/
/**
* \brief
*     Here write function descriptions.
* \param
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0296]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Clear_Resource_Consumption_Data_Start_routineInfoType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_Start (returns application error)
 *********************************************************************************************************************/

  (void)Rtm_ClearHistogramResults(0u, RTM_ALL_HISTOGRAM_AND_TASK_STACK_RESULTS);
  *routineInfo = 0x00u; /* routine completed successfully */

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Ct_ResourceMeasurement_STOP_SEC_CODE
#include "Ct_ResourceMeasurement_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: documentation area:Ct_ResourceMeasurement_BackgroundEvent_doc)  **********/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:Ct_ResourceMeasurement_BackgroundEvent)  *********/
    //Rtm_CpuLoadMeasurementFunction();

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_E2E_Timing_Read_Maximum_ReadDataLength)  */
  *DataLength = 2u;
  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_E2E_Timing_Read_Maximum_ConditionCheckRead)  */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_E2E_Timing_Read_Maximum_ReadDataLength_doc)  */

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
*   [COVERS: DSG_DIA_MMA_0237]
**/

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_E2E_Timing_Read_Maximum_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_E2E_Timing_Read_Maximum_ReadData)  **/
  Data[0u] = 0x0u;   /* E2E ID */
  Data[1u] = 0x01u; /* Maximum percent */

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_E2E_Timing_Read_Maximum_ReadData_doc)  ***/

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
*   [COVERS: DSG_DIA_MMA_0236]
**/

/***  End of saved code  ************************************************************************************/
#endif

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
