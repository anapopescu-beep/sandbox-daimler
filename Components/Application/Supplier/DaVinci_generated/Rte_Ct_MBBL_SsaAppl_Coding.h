/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Ct_MBBL_SsaAppl_Coding.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ct_MBBL_SsaAppl_Coding>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CT_MBBL_SSAAPPL_CODING_H
# define RTE_CT_MBBL_SSAAPPL_CODING_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Ct_MBBL_SsaAppl_Coding_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8CodingValidity;
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8VehicleEquipValidity;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_psrVariantCodingValidity_u8CodingValidity (85U)
#  define Rte_InitValue_psrVariantCodingValidity_u8VehicleEquipValidity (85U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(uint8, RTE_CODE) Rte_Mode_Ct_MBBL_SsaAppl_Coding_P_MDG_Coding_Stat_ST3_Coding_Status(void);







# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_psrVariantCodingValidity_u8CodingValidity Rte_Write_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8CodingValidity
#  define Rte_Write_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8CodingValidity(data) (Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8CodingValidity = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrVariantCodingValidity_u8VehicleEquipValidity Rte_Write_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8VehicleEquipValidity
#  define Rte_Write_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8VehicleEquipValidity(data) (Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8VehicleEquipValidity = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_P_MDG_Coding_Stat_ST3_Coding_Status Rte_Mode_Ct_MBBL_SsaAppl_Coding_P_MDG_Coding_Stat_ST3_Coding_Status


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_Ct_MBBL_SsaAppl_Coding_CodingNvBlockNeed_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)3, arg1))
#  define Rte_Call_NvMCalID_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)32, arg1))
#  define Rte_Call_NvMCalID_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)32, arg1))
#  define Rte_Call_NvMCalID_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)32, arg1))
#  define Rte_Call_NvMPresafeCyclesLevel_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)29, arg1))
#  define Rte_Call_NvMPresafeCyclesLevel_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)29, arg1))
#  define Rte_Call_NvMPresafeCyclesLevel_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)29, arg1))
#  define Rte_Call_NvMReleaseCyclesBsrAndPreSafe_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)30, arg1))
#  define Rte_Call_NvMReleaseCyclesBsrAndPreSafe_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)30, arg1))
#  define Rte_Call_NvMReleaseCyclesBsrAndPreSafe_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)30, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_CYCLE_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)43, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_CYCLE_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)43, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_CYCLE_DELAYS_MB_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)44, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_CYCLE_DELAYS_MB_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)44, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_EOL_MAPPING_MB_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)46, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_EOL_MAPPING_MB_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)46, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_HAPTIC_CONFIG_MB_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)45, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_HAPTIC_CONFIG_MB_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)45, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_STEP_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)47, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_STEP_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)47, arg1))
#  define Rte_Call_NvMTensioningCycleBSR_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)28, arg1))
#  define Rte_Call_NvMTensioningCycleBSR_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)28, arg1))
#  define Rte_Call_NvMTensioningCycleBSR_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)28, arg1))
#  define Rte_Call_NvMVehicleEquipment_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)27, arg1))
#  define Rte_Call_NvMVehicleEquipment_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)27, arg1))
#  define Rte_Call_NvMVehicleEquipment_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)27, arg1))
#  define Rte_Call_NvMZZZ_VehicleEquipment_Development_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)31, arg1))
#  define Rte_Call_NvMZZZ_VehicleEquipment_Development_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)31, arg1))
#  define Rte_Call_NvMZZZ_VehicleEquipment_Development_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)31, arg1))

/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_Coding_ExclusiveArea_CalID() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_Coding_ExclusiveArea_CalID() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Enter_Coding_ExclusiveArea_PreSafeCyclesLevel() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) (optimized, tasks cannot interrupt each other) */

#  define Rte_Exit_Coding_ExclusiveArea_PreSafeCyclesLevel() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) (optimized, tasks cannot interrupt each other)*/

#  define Rte_Enter_Coding_ExclusiveArea_ReleaseCyclesBsrAndPreSafe() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) (optimized, tasks cannot interrupt each other) */

#  define Rte_Exit_Coding_ExclusiveArea_ReleaseCyclesBsrAndPreSafe() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) (optimized, tasks cannot interrupt each other)*/

#  define Rte_Enter_Coding_ExclusiveArea_TensioningCycleBSR() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) (optimized, tasks cannot interrupt each other) */

#  define Rte_Exit_Coding_ExclusiveArea_TensioningCycleBSR() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) (optimized, tasks cannot interrupt each other)*/

#  define Rte_Enter_Coding_ExclusiveArea_VehicleEquipment() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_Coding_ExclusiveArea_VehicleEquipment() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Enter_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Idt_codingData, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_Cal_CodingDataInit;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_Cal_CodingDataInit() (&Rte_Ct_MBBL_SsaAppl_Coding_Cal_CodingDataInit)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_PIM_OldCodingState;
extern VAR(CalibrationIdentifications_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_CalibrationID;
extern VAR(CalibrationIdentifications_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_CalibrationID_Mirror;
extern VAR(Idt_codingData, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_PIM_CodingData;
extern VAR(PreSafeCyclesLevel_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_PreSafeCyclesLevel;
extern VAR(PreSafeCyclesLevel_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_PreSafeCyclesLevel_Mirror;
extern VAR(ReleaseCyclesBSRAndPresafe_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_ReleaseCyclesBsrAndPreSafe;
extern VAR(ReleaseCyclesBSRAndPresafe_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_ReleaseCyclesBsrAndPreSafe_Mirror;
extern VAR(TensioningCycleBSR_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_TensioningCycleBSR;
extern VAR(TensioningCycleBSR_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_TensioningCycleBSR_Mirror;
extern VAR(VehicleEquipment_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_VehicleEquipment;
extern VAR(VehicleEquipment_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_VehicleEquipment_Mirror;
extern VAR(ZZZ_VehicleEquipment_Development_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_ZZZ_VehicleEquipment_Development;
extern VAR(ZZZ_VehicleEquipment_Development_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_ZZZ_VehicleEquipment_Development_Mirror;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_PIM_OldCodingState() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_PIM_OldCodingState)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_CalibrationID() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_CalibrationID)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_CalibrationID_Mirror() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_CalibrationID_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_PIM_CodingData() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_PIM_CodingData)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_PreSafeCyclesLevel() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_PreSafeCyclesLevel)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_PreSafeCyclesLevel_Mirror() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_PreSafeCyclesLevel_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_ReleaseCyclesBsrAndPreSafe() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_ReleaseCyclesBsrAndPreSafe)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_ReleaseCyclesBsrAndPreSafe_Mirror() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_ReleaseCyclesBsrAndPreSafe_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_TensioningCycleBSR() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_TensioningCycleBSR)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_TensioningCycleBSR_Mirror() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_TensioningCycleBSR_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_VehicleEquipment() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_VehicleEquipment)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_VehicleEquipment_Mirror() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_VehicleEquipment_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_ZZZ_VehicleEquipment_Development() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_ZZZ_VehicleEquipment_Development)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_ZZZ_VehicleEquipment_Development_Mirror() \
  (&Rte_Ct_MBBL_SsaAppl_Coding_ZZZ_VehicleEquipment_Development_Mirror)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Ct_MBBL_SsaAppl_Coding_START_SEC_CODE
# include "Ct_MBBL_SsaAppl_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ct_MBBL_SsaAppl_Coding_Init Ct_MBBL_SsaAppl_Coding_Init
#  define RTE_RUNNABLE_Ct_MBBL_SsaAppl_Coding_MainFunction Ct_MBBL_SsaAppl_Coding_MainFunction
#  define RTE_RUNNABLE_DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ConditionCheckRead DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadData DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadData
#  define RTE_RUNNABLE_DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadDataLength DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadDataLength
#  define RTE_RUNNABLE_DataServices_Calibration_Identifications_CAL_ID_Write_CombinedDataElement_WriteData DataServices_Calibration_Identifications_CAL_ID_Write_CombinedDataElement_WriteData
#  define RTE_RUNNABLE_DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items
#  define RTE_RUNNABLE_DataServices_DID_0131_SAR_Data_Storage_Status_ConditionCheckRead DataServices_DID_0131_SAR_Data_Storage_Status_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_DID_0131_SAR_Data_Storage_Status_ReadData DataServices_DID_0131_SAR_Data_Storage_Status_ReadData
#  define RTE_RUNNABLE_DataServices_DID_0131_SAR_Data_Storage_Status_WriteData DataServices_DID_0131_SAR_Data_Storage_Status_WriteData
#  define RTE_RUNNABLE_DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ConditionCheckRead DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ReadData DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ReadData
#  define RTE_RUNNABLE_DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_WriteData DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_WriteData
#  define RTE_RUNNABLE_DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ConditionCheckRead DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData
#  define RTE_RUNNABLE_DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData_WriteData DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData_WriteData
#  define RTE_RUNNABLE_DataServices_Tensioning_Cycle_BSR_CombinedSignal_ConditionCheckRead DataServices_Tensioning_Cycle_BSR_CombinedSignal_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Tensioning_Cycle_BSR_CombinedSignal_ReadData DataServices_Tensioning_Cycle_BSR_CombinedSignal_ReadData
#  define RTE_RUNNABLE_DataServices_Tensioning_Cycle_BSR_CombinedSignal_WriteData DataServices_Tensioning_Cycle_BSR_CombinedSignal_WriteData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_1_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Equipment_1_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_2_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Equipment_2_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_3_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Equipment_3_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_4_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Equipment_4_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_5_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Equipment_5_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_6_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Equipment_6_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ReadData DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ReadData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_WriteData DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_WriteData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ReadData DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ReadData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_WriteData DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_WriteData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData
#  define RTE_RUNNABLE_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData
#  define RTE_RUNNABLE_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ConditionCheckRead DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData
#  define RTE_RUNNABLE_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData
#  define RTE_RUNNABLE_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ConditionCheckRead DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData
#  define RTE_RUNNABLE_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData
# endif

FUNC(void, Ct_MBBL_SsaAppl_Coding_CODE) Ct_MBBL_SsaAppl_Coding_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_SsaAppl_Coding_CODE) Ct_MBBL_SsaAppl_Coding_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data320ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Calibration_Identifications_CAL_ID_Write_CombinedDataElement_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Calibration_Identifications_CAL_ID_Write_CombinedDataElement_WriteData(P2CONST(Dcm_Data320ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_DID_0131_SAR_Data_Storage_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_DID_0131_SAR_Data_Storage_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_DID_0131_SAR_Data_Storage_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_DID_0131_SAR_Data_Storage_Status_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_DID_0131_SAR_Data_Storage_Status_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1073ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_WriteData(P2CONST(Dcm_Data1073ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data144ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData_WriteData(P2CONST(Dcm_Data144ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Tensioning_Cycle_BSR_CombinedSignal_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Tensioning_Cycle_BSR_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Tensioning_Cycle_BSR_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data233ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Tensioning_Cycle_BSR_CombinedSignal_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Tensioning_Cycle_BSR_CombinedSignal_WriteData(P2CONST(Dcm_Data233ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_3_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_4_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_5_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_6_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define Ct_MBBL_SsaAppl_Coding_STOP_SEC_CODE
# include "Ct_MBBL_SsaAppl_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Calibration_Identifications_CAL_ID_Write_Calibration_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Calibration_Identifications_CAL_ID_Write_Calibration_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0131_SAR_Data_Storage_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0131_SAR_Data_Storage_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_1_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_2_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_2_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_3_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_3_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_4_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_4_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_5_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_5_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_6_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_6_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_E_NOT_OK (1U)

#  define RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_E_NOT_OK (1U)

#  define RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CT_MBBL_SSAAPPL_CODING_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
