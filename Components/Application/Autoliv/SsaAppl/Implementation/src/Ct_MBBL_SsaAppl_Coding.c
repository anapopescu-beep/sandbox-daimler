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
 *             File:  Ct_MBBL_SsaAppl_Coding.c
 *           Config:  S:\Tools\Vector_configuration\Workspace\Daimler MMA/S:/Tools/Vector_configuration/Workspace/Daimler MMA/StartApplication.dpa
 *        SW-C Type:  Ct_MBBL_SsaAppl_Coding
 *  Generation Time:  2023-08-23 15:49:12
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  C-Code implementation template for SW-C <Ct_MBBL_SsaAppl_Coding>
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
 * DT_uint8
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
 * Dcm_OpStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * UInt8
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *
 * Mode Declaration Group Prototypes:
 * ==================================
 * Mode Declaration Group Prototype Coding_Status of Port Interface P_MDG_Coding_Stat_ST3
 *   Coding state
 *
 *
 * Mode Declaration Groups:
 * ========================
 * Coding_Mode
 *   Coding state
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
 *********************************************************************************************************************/

#include "common.h"
#include "Rte_Ct_MBBL_SsaAppl_Coding.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#ifdef _MICROSOFT_C_VTT_
#include "CANoeAPI.h"
#include "vstdlib.h"
#endif

#include "Nvp_Generated.h"
#include "Nvp_Cfg.h"

#if !defined(CODING_LOCAL) /* COV_SSA_LOCAL */
#define CODING_LOCAL static
#endif

/* Vehicle Equipment types */
#define VEHICLE_EQUIPMENT_1 (0U)
#define VEHICLE_EQUIPMENT_2 (1U)
#define VEHICLE_EQUIPMENT_3 (2U)
#define VEHICLE_EQUIPMENT_4 (3U)
#define VEHICLE_EQUIPMENT_5 (4U)
#define VEHICLE_EQUIPMENT_6 (5U)
#define VEHICLE_RESERVED_1 (6U)
#define VEHICLE_RESERVED_2 (7U)
#define UNTERSPANNUNGSABBRUCHSCHWELLE (8U)
#define UNTERSPANNUNGSBEREICHSSCHWELLE (9U)
#define UBERSPANNUNGSBEREICHSSCHWELLE (10U)
#define UBERSPANNUNGSABBRUCHSCHWELLE (11U)

/* Vehicle equipment size */
#define VEHICLE_EQUIPMENT_EQUIPMENT1_SIZE (1U)
#define VEHICLE_EQUIPMENT_EQUIPMENT2_SIZE (1U)
#define VEHICLE_EQUIPMENT_EQUIPMENT3_SIZE (1U)
#define VEHICLE_EQUIPMENT_EQUIPMENT4_SIZE (1U)
#define VEHICLE_EQUIPMENT_EQUIPMENT5_SIZE (1U)
#define VEHICLE_EQUIPMENT_EQUIPMENT6_SIZE (1U)
#define VEHICLE_EQUIPMENT_RESERVED1_SIZE (1U)
#define VEHICLE_EQUIPMENT_RESERVED2_SIZE (1U)
#define VEHICLE_EQUIPMENT_UNTERSPANNUNGSABBRUCHSCHWELLE_SIZE (2U)
#define VEHICLE_EQUIPMENT_UNTERSPANNUNGSBEREICHSSCHWELLE_SIZE (2U)
#define VEHICLE_EQUIPMENT_UBERSPANNUNGSBEREICHSSCHWELLE_SIZE (2U)
#define VEHICLE_EQUIPMENT_UBERSPANNUNGSABBRUCHSCHWELLE_SIZE (2U)

/* Variant coding */
#define CODING_CYCLE_SIZE               12u
#define CODING_PRESAFE_CYCLES_SIZE      312u
#define CODING_COUNTER_SIZE             11u
#define CODING_STEP_SIZE                8u
#define CODING_BSR_CYCLE_NUMBER         26u
#define CODING_BSR_STEP_NUMBER          92u 
#define CODING_BSR_NUMBER_OF_CYCLES     3u 
#define CODING_RELEASE_CYCLE_NUMBER     29u
#define CODING_RELEASE_STEP_NUMBER      116u
#define CODING_RELEASE_NUMBER_OF_CYCLES 4u  

/* Presafe Cycles Level size */
#define PRESAFE_CYCLES_LEVEL_SIZE (1073U)

/* Release cycles BSR and Presafe size */
#define RELEASE_CYCLES_BSR_AND_PRESAFE_SIZE (144U)

/* Tensioning Cycle BSR size */
#define TENSIONING_CYCLE_BSR_SIZE (233u)

/* ZZZ Vehicle Equipment Development types */
#define ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_BITFIELD (0U)
#define ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_ZYKLUSZEIT_MESSTECHNIK (1U)

/* ZZZ Vehicle Equipment size */
#define ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_BITFIELD_SIZE (2U)
#define ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_ZYKLUSZEIT_MESSTECHNIK_SIZE (1U)

/* CAL ID size */
#define CAL_ID_SIZE (17U)

FUNC(void, Ssa_Coding_CODE)CodingAppl_Copy(P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) targetBuf, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) dataBuf, uint32_least dataLength);
FUNC(boolean, Ssa_Coding_CODE)Coding_CompareData(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) buffer1, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) buffer2, uint32 size);
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangeVehicleEquipment(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) vechicleEquipment, uint8 equipmentType);
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangeTensioningCycleBSR(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) tensioningCycleBSR);
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangePreSafeCyclesLevel(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) preSafeCyclesLevel);
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangeReleaseCyclesBsrAndPreSafe(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) releaseCyclesBsrAndPreSafe);
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangeZZZVehicleEquipmentDevelopment(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) zzzVechicleEquipmentDevelopment, uint8 equipmentType);
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangeCalID(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) calId);
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ManageVariantCoding(void);
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
 * DT_uint8: Integer in interval [0...255]
 * Dcm_NegativeResponseCodeType: Integer in interval [0...255]
 * Dcm_OpStatusType: Integer in interval [0...64]
 * NvM_RequestResultType: Integer in interval [0...8]
 * NvM_RequestResultType: Integer in interval [0...255]
 * UInt8: Integer in interval [0...255]
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * Dcm_Data1073ByteType: Array with 1073 element(s) of type uint8
 * Dcm_Data12ByteType: Array with 12 element(s) of type uint8
 * Dcm_Data144ByteType: Array with 144 element(s) of type uint8
 * Dcm_Data17ByteType: Array with 17 element(s) of type uint8
 * Dcm_Data192ByteType: Array with 192 element(s) of type DT_uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data233ByteType: Array with 233 element(s) of type uint8
 * Dcm_Data2ByteType: Array with 2 element(s) of type uint8
 * Dcm_Data320ByteType: Array with 320 element(s) of type uint8
 * Dcm_Data96ByteType: Array with 96 element(s) of type DT_uint8
 * PreSafeCyclesLevel_AssociatedCounterDataType: Array with 11 element(s) of type DT_uint8
 * PreSafeCyclesLevel_HapticDataType: Array with 24 element(s) of type DT_uint8
 * PreSafeCyclesLevel_LibraryDataType: Array with 736 element(s) of type DT_uint8
 *
 * Record Types:
 * =============
 * CalibrationIdentifications_StorageType: Record with elements
 *   NumberOfDataItems of type Dcm_Data1ByteType
 *   CalibrationIdentification of type Dcm_Data17ByteType
 * Idt_codingData: Record with elements
 *   SarDataStorageStatus of type uint8
 *   MaxNumberOfSARWriteCycles of type uint32
 *   NumberOfSARWriteCycles of type uint32
 * PreSafeCyclesLevel_StorageType: Record with elements
 *   Presafe1 of type Dcm_Data12ByteType
 *   Presafe2 of type Dcm_Data12ByteType
 *   Presafe3 of type Dcm_Data12ByteType
 *   Presafe4 of type Dcm_Data12ByteType
 *   Presafe5 of type Dcm_Data12ByteType
 *   Presafe6 of type Dcm_Data12ByteType
 *   Presafe7 of type Dcm_Data12ByteType
 *   Presafe8 of type Dcm_Data12ByteType
 *   Presafe9 of type Dcm_Data12ByteType
 *   Presafe10 of type Dcm_Data12ByteType
 *   Presafe11 of type Dcm_Data12ByteType
 *   Presafe12 of type Dcm_Data12ByteType
 *   Presafe13 of type Dcm_Data12ByteType
 *   Presafe14 of type Dcm_Data12ByteType
 *   Curve1 of type Dcm_Data12ByteType
 *   Curve2 of type Dcm_Data12ByteType
 *   Curve3 of type Dcm_Data12ByteType
 *   Curve4 of type Dcm_Data12ByteType
 *   Haptic1 of type PreSafeCyclesLevel_HapticDataType
 *   Haptic2 of type PreSafeCyclesLevel_HapticDataType
 *   Haptic3 of type PreSafeCyclesLevel_HapticDataType
 *   Haptic4 of type PreSafeCyclesLevel_HapticDataType
 *   Library of type PreSafeCyclesLevel_LibraryDataType
 *   TimeoutPresafe5 of type Dcm_Data2ByteType
 *   DurationHaptic1 of type Dcm_Data2ByteType
 *   DurationHaptic2 of type Dcm_Data2ByteType
 *   DurationHaptic3 of type Dcm_Data2ByteType
 *   DurationHaptic4 of type Dcm_Data2ByteType
 *   HapticType of type Dcm_Data1ByteType
 *   PRESAFEAccelerationTimeout of type Dcm_Data1ByteType
 *   Haptic1AccelerationTimeout of type Dcm_Data1ByteType
 *   APIAccelerationTimeout of type Dcm_Data1ByteType
 *   AssociatedCounter of type PreSafeCyclesLevel_AssociatedCounterDataType
 * ReleaseCyclesBSRAndPresafe_StorageType: Record with elements
 *   Soft of type Dcm_Data12ByteType
 *   Hard1 of type Dcm_Data12ByteType
 *   Hard2 of type Dcm_Data12ByteType
 *   Hard3 of type Dcm_Data12ByteType
 *   Library of type Dcm_Data96ByteType
 * TensioningCycleBSR_StorageType: Record with elements
 *   BSR1 of type Dcm_Data12ByteType
 *   BSR2 of type Dcm_Data12ByteType
 *   BSR3 of type Dcm_Data12ByteType
 *   Library of type Dcm_Data192ByteType
 *   AfterBuckle of type Dcm_Data1ByteType
 *   AfterMd of type Dcm_Data1ByteType
 *   PwtDelay of type Dcm_Data1ByteType
 *   BSR1AccelerationTimeout of type Dcm_Data1ByteType
 *   AssociatedCounterBSR of type Dcm_Data1ByteType
 * VehicleEquipment_StorageType: Record with elements
 *   Equipment1 of type Dcm_Data1ByteType
 *   Equipment2 of type Dcm_Data1ByteType
 *   Equipment3 of type Dcm_Data1ByteType
 *   Equipment4 of type Dcm_Data1ByteType
 *   Equipment5 of type Dcm_Data1ByteType
 *   Equipment6 of type Dcm_Data1ByteType
 *   Reserved1 of type Dcm_Data1ByteType
 *   Reserved2 of type Dcm_Data1ByteType
 *   Uberspannungsabbruchschwelle of type Dcm_Data2ByteType
 *   Uberspannungsbereichsschwelle of type Dcm_Data2ByteType
 *   Unterspannungsbereichsschwelle of type Dcm_Data2ByteType
 *   Unterspannungsabbruchschwelle of type Dcm_Data2ByteType
 * ZZZ_VehicleEquipment_Development_StorageType: Record with elements
 *   Bitfield of type Dcm_Data2ByteType
 *   Zykluszeit_Messtechnik of type Dcm_Data1ByteType
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_PIM_OldCodingState(void)
 *   CalibrationIdentifications_StorageType *Rte_Pim_CalibrationID(void)
 *   CalibrationIdentifications_StorageType *Rte_Pim_CalibrationID_Mirror(void)
 *   Idt_codingData *Rte_Pim_PIM_CodingData(void)
 *   PreSafeCyclesLevel_StorageType *Rte_Pim_PreSafeCyclesLevel(void)
 *   PreSafeCyclesLevel_StorageType *Rte_Pim_PreSafeCyclesLevel_Mirror(void)
 *   ReleaseCyclesBSRAndPresafe_StorageType *Rte_Pim_ReleaseCyclesBsrAndPreSafe(void)
 *   ReleaseCyclesBSRAndPresafe_StorageType *Rte_Pim_ReleaseCyclesBsrAndPreSafe_Mirror(void)
 *   TensioningCycleBSR_StorageType *Rte_Pim_TensioningCycleBSR(void)
 *   TensioningCycleBSR_StorageType *Rte_Pim_TensioningCycleBSR_Mirror(void)
 *   VehicleEquipment_StorageType *Rte_Pim_VehicleEquipment(void)
 *   VehicleEquipment_StorageType *Rte_Pim_VehicleEquipment_Mirror(void)
 *   ZZZ_VehicleEquipment_Development_StorageType *Rte_Pim_ZZZ_VehicleEquipment_Development(void)
 *   ZZZ_VehicleEquipment_Development_StorageType *Rte_Pim_ZZZ_VehicleEquipment_Development_Mirror(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   Idt_codingData *Rte_CData_Cal_CodingDataInit(void)
 *
 *********************************************************************************************************************/


#define Ct_MBBL_SsaAppl_Coding_START_SEC_CODE
#include "Ct_MBBL_SsaAppl_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ct_MBBL_SsaAppl_Coding_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_psrVariantCodingValidity_u8CodingValidity(UInt8 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_NVP_BLOCK_ID_CYCLE_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_NVP_BLOCK_ID_CYCLE_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_NVP_BLOCK_ID_CYCLE_DELAYS_MB_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_NVP_BLOCK_ID_CYCLE_DELAYS_MB_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_NVP_BLOCK_ID_EOL_MAPPING_MB_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_NVP_BLOCK_ID_EOL_MAPPING_MB_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_NVP_BLOCK_ID_HAPTIC_CONFIG_MB_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_NVP_BLOCK_ID_HAPTIC_CONFIG_MB_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_NVP_BLOCK_ID_STEP_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_NVP_BLOCK_ID_STEP_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ct_MBBL_SsaAppl_Coding_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ct_MBBL_SsaAppl_Coding_CODE) Ct_MBBL_SsaAppl_Coding_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ct_MBBL_SsaAppl_Coding_Init
 *********************************************************************************************************************/

    *Rte_Pim_PIM_OldCodingState() = 0;

    /* get all variant coding data from NVM */
    Rte_Call_NvMCalID_ReadBlock((dtRef_const_VOID)(Rte_Pim_CalibrationID()));
    Rte_Call_NvMPresafeCyclesLevel_ReadBlock((dtRef_const_VOID)(Rte_Pim_PreSafeCyclesLevel()));
    Rte_Call_NvMReleaseCyclesBsrAndPreSafe_ReadBlock((dtRef_const_VOID)(Rte_Pim_ReleaseCyclesBsrAndPreSafe()));
    Rte_Call_NvMTensioningCycleBSR_ReadBlock((dtRef_const_VOID)(Rte_Pim_TensioningCycleBSR()));
    Rte_Call_NvMVehicleEquipment_ReadBlock((dtRef_const_VOID)(Rte_Pim_VehicleEquipment()));
    Rte_Call_NvMZZZ_VehicleEquipment_Development_ReadBlock((dtRef_const_VOID)(Rte_Pim_ZZZ_VehicleEquipment_Development()));

    NVP_Init();

    Coding_ManageVariantCoding();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ct_MBBL_SsaAppl_Coding_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_P_MDG_Coding_Stat_ST3_Coding_Status(void)
 *   Modes of Rte_ModeType_Coding_Mode:
 *   - RTE_MODE_Coding_Mode_CODING_ACTIVE
 *   - RTE_MODE_Coding_Mode_CODING_FAILED
 *   - RTE_MODE_Coding_Mode_CODING_OK
 *   - RTE_TRANSITION_Coding_Mode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Ct_MBBL_SsaAppl_Coding_CodingNvBlockNeed_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMCalID_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMCalID_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMCalID_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMPresafeCyclesLevel_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMPresafeCyclesLevel_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMPresafeCyclesLevel_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMReleaseCyclesBsrAndPreSafe_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMReleaseCyclesBsrAndPreSafe_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMReleaseCyclesBsrAndPreSafe_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMTensioningCycleBSR_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMTensioningCycleBSR_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMTensioningCycleBSR_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMVehicleEquipment_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMVehicleEquipment_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMVehicleEquipment_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMZZZ_VehicleEquipment_Development_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMZZZ_VehicleEquipment_Development_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMZZZ_VehicleEquipment_Development_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_CalID(void)
 *   void Rte_Exit_Coding_ExclusiveArea_CalID(void)
 *   void Rte_Enter_Coding_ExclusiveArea_PreSafeCyclesLevel(void)
 *   void Rte_Exit_Coding_ExclusiveArea_PreSafeCyclesLevel(void)
 *   void Rte_Enter_Coding_ExclusiveArea_ReleaseCyclesBsrAndPreSafe(void)
 *   void Rte_Exit_Coding_ExclusiveArea_ReleaseCyclesBsrAndPreSafe(void)
 *   void Rte_Enter_Coding_ExclusiveArea_TensioningCycleBSR(void)
 *   void Rte_Exit_Coding_ExclusiveArea_TensioningCycleBSR(void)
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Enter_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ct_MBBL_SsaAppl_Coding_MainFunction_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ct_MBBL_SsaAppl_Coding_CODE) Ct_MBBL_SsaAppl_Coding_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ct_MBBL_SsaAppl_Coding_MainFunction
 *********************************************************************************************************************/

    if (*Rte_Pim_PIM_OldCodingState() != Rte_Mode_P_MDG_Coding_Stat_ST3_Coding_Status())
    {
        switch (Rte_Mode_P_MDG_Coding_Stat_ST3_Coding_Status())
        {
        case RTE_MODE_Coding_Mode_CODING_ACTIVE:
#ifdef _MICROSOFT_C_VTT_
            CANoeAPI_WriteString("Coding active.");
#endif
            break;

        case RTE_MODE_Coding_Mode_CODING_FAILED:
#ifdef _MICROSOFT_C_VTT_
            CANoeAPI_WriteString("Coding failed.");
#endif
            break;

        case RTE_MODE_Coding_Mode_CODING_OK:
#ifdef _MICROSOFT_C_VTT_
            CANoeAPI_WriteString("Coding ok.");
#endif
            break;
        }
    }

    *Rte_Pim_PIM_OldCodingState() = Rte_Mode_P_MDG_Coding_Stat_ST3_Coding_Status();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_CalID(void)
 *   void Rte_Exit_Coding_ExclusiveArea_CalID(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ConditionCheckRead_doc
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
*   [COVERS: DSG_DIA_MMA_0284]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of CAL ID NVM block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMCalID_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_DCM_E_PENDING;
        }
    }

    return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_CalID(void)
 *   void Rte_Exit_Coding_ExclusiveArea_CalID(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data320ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0284]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy CAL ID Data to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_CalID();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_CalibrationID()->CalibrationIdentification, CAL_ID_SIZE - 1U); /* size = cal id size - number of data items(1byte) */
    Rte_Exit_Coding_ExclusiveArea_CalID();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_CalID(void)
 *   void Rte_Exit_Coding_ExclusiveArea_CalID(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadDataLength_doc
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
*   [COVERS: DSG_DIA_MMA_0284]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadDataLength (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = CAL_ID_SIZE - 1U; /* only the size of calibration identification */
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Calibration_Identifications_CAL_ID_Write_CombinedDataElement_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Calibration_Identifications_CAL_ID_Write_Calibration_Identification>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_CalID(void)
 *   void Rte_Exit_Coding_ExclusiveArea_CalID(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Calibration_Identifications_CAL_ID_Write_CombinedDataElement_WriteData(const uint8 *Data, uint16 DataLength, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data320ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Calibration_Identifications_CAL_ID_Write_Calibration_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_Calibration_Identifications_CAL_ID_Write_Calibration_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Calibration_Identifications_CAL_ID_Write_CombinedDataElement_WriteData_doc
 *********************************************************************************************************************/
/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     DataLength - Size of the Diagnostic Buffer
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
*   [COVERS: DSG_DIA_MMA_0280]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Calibration_Identifications_CAL_ID_Write_CombinedDataElement_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Calibration_Identifications_CAL_ID_Write_CombinedDataElement_WriteData (returns application error)
 *********************************************************************************************************************/

   (void)Coding_ChangeCalID(Data);

   *ErrorCode = DCM_E_POSITIVERESPONSE;

   return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items_DCM_E_PENDING
 *   RTE_E_DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items_doc
 *********************************************************************************************************************/
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
*   [COVERS: DSG_DIA_MMA_0280]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items (returns application error)
 *********************************************************************************************************************/
  /* #40 Change persistent CAL ID to the retrieved one. */
  CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_CalibrationID()->NumberOfDataItems, Data, 1u);
  *ErrorCode = DCM_E_POSITIVERESPONSE;

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DID_0131_SAR_Data_Storage_Status_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0131_SAR_Data_Storage_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DID_0131_SAR_Data_Storage_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0131_SAR_Data_Storage_Status_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0131_SAR_Data_Storage_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DID_0131_SAR_Data_Storage_Status_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_DID_0131_SAR_Data_Storage_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DID_0131_SAR_Data_Storage_Status_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DID_0131_SAR_Data_Storage_Status_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0131_SAR_Data_Storage_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DID_0131_SAR_Data_Storage_Status_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0131_SAR_Data_Storage_Status_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0131_SAR_Data_Storage_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DID_0131_SAR_Data_Storage_Status_ReadData_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_DID_0131_SAR_Data_Storage_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DID_0131_SAR_Data_Storage_Status_ReadData (returns application error)
 *********************************************************************************************************************/

    *Data = (*Rte_Pim_PIM_CodingData()).SarDataStorageStatus;
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DID_0131_SAR_Data_Storage_Status_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_DID_0131_SAR_Data_Storage_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DID_0131_SAR_Data_Storage_Status_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0131_SAR_Data_Storage_Status_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0131_SAR_Data_Storage_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DID_0131_SAR_Data_Storage_Status_WriteData_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_DID_0131_SAR_Data_Storage_Status_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DID_0131_SAR_Data_Storage_Status_WriteData (returns application error)
 *********************************************************************************************************************/

    (*Rte_Pim_PIM_CodingData()).SarDataStorageStatus = *Data;
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_DCM_E_PENDING
 *   RTE_E_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0046]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of PresafeCyclesLevel block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMPresafeCyclesLevel_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1073ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_DCM_E_PENDING
 *   RTE_E_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0045, DSG_DIA_MMA_0110, DSG_DIA_MMA_0111]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy PreSafeCyclesLevel to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_PreSafeCyclesLevel();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_PreSafeCyclesLevel(), PRESAFE_CYCLES_LEVEL_SIZE);
    Rte_Exit_Coding_ExclusiveArea_PreSafeCyclesLevel();

    /* #20 Always return successfully. */
    return RTE_E_OK;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1073ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_DCM_E_PENDING
 *   RTE_E_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0047, DSG_DIA_MMA_0112, DSG_DIA_MMA_0113]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_WriteData (returns application error)
 *********************************************************************************************************************/

   uint8 retVal = RTE_E_OK;
   PreSafeCyclesLevel_StorageType *codingCycles;

   (void)Coding_ChangePreSafeCyclesLevel(Data);

   codingCycles = Rte_Pim_PreSafeCyclesLevel();

   return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_DCM_E_PENDING
 *   RTE_E_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0049]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of ReleaseCyclesBsrAndPreSafe block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMReleaseCyclesBsrAndPreSafe_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data144ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_DCM_E_PENDING
 *   RTE_E_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0048, DSG_DIA_MMA_0114, DSG_DIA_MMA_0115]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData (returns application error)
 *********************************************************************************************************************/

	/* #10 Copy PreSafeCyclesLevel to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_ReleaseCyclesBsrAndPreSafe();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_ReleaseCyclesBsrAndPreSafe(), RELEASE_CYCLES_BSR_AND_PRESAFE_SIZE);
    Rte_Exit_Coding_ExclusiveArea_ReleaseCyclesBsrAndPreSafe();

    /* #20 Always return successfully. */
    return RTE_E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data144ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_DCM_E_PENDING
 *   RTE_E_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0050, DSG_DIA_MMA_0116, DSG_DIA_MMA_0117]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData_WriteData (returns application error)
 *********************************************************************************************************************/

   uint8 retVal = RTE_E_OK;
   ReleaseCyclesBSRAndPresafe_StorageType *codingRelease;

   (void)Coding_ChangeReleaseCyclesBsrAndPreSafe(Data);

   codingRelease = Rte_Pim_ReleaseCyclesBsrAndPreSafe();

   return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Tensioning_Cycle_BSR_CombinedSignal_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Tensioning_Cycle_BSR_CombinedSignal_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_DCM_E_PENDING
 *   RTE_E_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Tensioning_Cycle_BSR_CombinedSignal_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0051]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Tensioning_Cycle_BSR_CombinedSignal_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Tensioning_Cycle_BSR_CombinedSignal_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of TensioningCycleBSR block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMTensioningCycleBSR_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Tensioning_Cycle_BSR_CombinedSignal_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Tensioning_Cycle_BSR_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data233ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_DCM_E_PENDING
 *   RTE_E_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Tensioning_Cycle_BSR_CombinedSignal_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0052, DSG_DIA_MMA_0118, DSG_DIA_MMA_0119]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Tensioning_Cycle_BSR_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Tensioning_Cycle_BSR_CombinedSignal_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy TensioningCycleBSR to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_TensioningCycleBSR();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_TensioningCycleBSR(), TENSIONING_CYCLE_BSR_SIZE);
    Rte_Exit_Coding_ExclusiveArea_TensioningCycleBSR();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Tensioning_Cycle_BSR_CombinedSignal_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Tensioning_Cycle_BSR_CombinedSignal_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data233ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_DCM_E_PENDING
 *   RTE_E_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Tensioning_Cycle_BSR_CombinedSignal_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0053, DSG_DIA_MMA_0120, DSG_DIA_MMA_0121]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Tensioning_Cycle_BSR_CombinedSignal_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Tensioning_Cycle_BSR_CombinedSignal_WriteData (returns application error)
 *********************************************************************************************************************/

   uint8 retVal = RTE_E_OK;
   TensioningCycleBSR_StorageType* codingBSR;

   (void)Coding_ChangeTensioningCycleBSR(Data);

   codingBSR = Rte_Pim_TensioningCycleBSR();

   return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_1_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_1>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_1_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_1_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0054]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_1_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of VehicleEquipment NVRAM block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMVehicleEquipment_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_1_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_1>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_1_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0064, DSG_DIA_MMA_0122, DSG_DIA_MMA_0123]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy Equipment 1 Data to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VehicleEquipment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_VehicleEquipment()->Equipment1, VEHICLE_EQUIPMENT_EQUIPMENT1_SIZE);
    Rte_Exit_Coding_ExclusiveArea_VehicleEquipment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_1>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_1_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0074, DSG_DIA_MMA_0124, DSG_DIA_MMA_0125]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData (returns application error)
 *********************************************************************************************************************/

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeVehicleEquipment(Data, VEHICLE_EQUIPMENT_1);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_2_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_2>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_2_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_2_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_2_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0055]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_2_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of VehicleEquipment NVRAM block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMVehicleEquipment_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_2_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_2>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_2_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0065, DSG_DIA_MMA_0126, DSG_DIA_MMA_0127]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy Equipment 2 Data to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VehicleEquipment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_VehicleEquipment()->Equipment2, VEHICLE_EQUIPMENT_EQUIPMENT2_SIZE);
    Rte_Exit_Coding_ExclusiveArea_VehicleEquipment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_2>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_2_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0075, DSG_DIA_MMA_0128, DSG_DIA_MMA_0129]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData (returns application error)
 *********************************************************************************************************************/

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeVehicleEquipment(Data, VEHICLE_EQUIPMENT_2);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_3_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_3>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_3_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_3_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_3_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_3_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0056]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_3_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_3_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of VehicleEquipment NVRAM block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMVehicleEquipment_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_3_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_3>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_3_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_3_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0066, DSG_DIA_MMA_0130, DSG_DIA_MMA_0131]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy Equipment 3 Data to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VehicleEquipment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_VehicleEquipment()->Equipment3, VEHICLE_EQUIPMENT_EQUIPMENT3_SIZE);
    Rte_Exit_Coding_ExclusiveArea_VehicleEquipment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_3>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_3_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_3_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0076, DSG_DIA_MMA_0132, DSG_DIA_MMA_0133]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData (returns application error)
 *********************************************************************************************************************/

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeVehicleEquipment(Data, VEHICLE_EQUIPMENT_3);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_4_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_4>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_4_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_4_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_4_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_4_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0057]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_4_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_4_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of VehicleEquipment NVRAM block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMVehicleEquipment_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_4_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_4>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_4_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_4_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0067, DSG_DIA_MMA_0134, DSG_DIA_MMA_0135]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy Equipment 4 Data to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VehicleEquipment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_VehicleEquipment()->Equipment4, VEHICLE_EQUIPMENT_EQUIPMENT4_SIZE);
    Rte_Exit_Coding_ExclusiveArea_VehicleEquipment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_4>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_4_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_4_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0077, DSG_DIA_MMA_0136, DSG_DIA_MMA_0137]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData (returns application error)
 *********************************************************************************************************************/

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeVehicleEquipment(Data, VEHICLE_EQUIPMENT_4);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_5_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_5>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_5_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_5_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_5_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_5_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0058]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_5_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_5_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of VehicleEquipment NVRAM block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMVehicleEquipment_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_5_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_5>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_5_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_5_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0068, DSG_DIA_MMA_0138, DSG_DIA_MMA_0139]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy Equipment 5 Data to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VehicleEquipment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_VehicleEquipment()->Equipment5, VEHICLE_EQUIPMENT_EQUIPMENT5_SIZE);
    Rte_Exit_Coding_ExclusiveArea_VehicleEquipment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_5>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_5_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_5_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0078, DSG_DIA_MMA_0140, DSG_DIA_MMA_0141]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData (returns application error)
 *********************************************************************************************************************/

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeVehicleEquipment(Data, VEHICLE_EQUIPMENT_5);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_6_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_6>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_6_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_6_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_6_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_6_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0059]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_6_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_6_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of VehicleEquipment NVRAM block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMVehicleEquipment_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_6_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_6>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_6_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_6_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0069, DSG_DIA_MMA_0142, DSG_DIA_MMA_0143, DSG_DIA_MMA_0203]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy Equipment 6 Data to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VehicleEquipment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_VehicleEquipment()->Equipment6, VEHICLE_EQUIPMENT_EQUIPMENT6_SIZE);

    /* Set 0x00 in reserved fields which are right after equipment 6, in order to prevent dummy data to be read */
    Data[1] = 0x00; /* Reserved 1 */
    Data[2] = 0x00; /* Reserved 2*/

    Rte_Exit_Coding_ExclusiveArea_VehicleEquipment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Equipment_6>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_6_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_6_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0079, DSG_DIA_MMA_0144, DSG_DIA_MMA_0145, DSG_DIA_MMA_0204]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData (returns application error)
 *********************************************************************************************************************/

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeVehicleEquipment(Data, VEHICLE_EQUIPMENT_6);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0060]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of VehicleEquipment NVRAM block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMVehicleEquipment_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0070, DSG_DIA_MMA_0146, DSG_DIA_MMA_0147, DSG_DIA_MMA_0148, DSG_DIA_MMA_0149]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy Ueberspannungsabbruchschwelle Data to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VehicleEquipment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_VehicleEquipment()->Uberspannungsabbruchschwelle, VEHICLE_EQUIPMENT_UNTERSPANNUNGSABBRUCHSCHWELLE_SIZE);
    Rte_Exit_Coding_ExclusiveArea_VehicleEquipment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0080]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_WriteData (returns application error)
 *********************************************************************************************************************/

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeVehicleEquipment(Data, UBERSPANNUNGSABBRUCHSCHWELLE);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0061]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of VehicleEquipment NVRAM block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMVehicleEquipment_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_DCM_E_PENDING;
        }
    }

    return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0071, DSG_DIA_MMA_0150, DSG_DIA_MMA_0151, DSG_DIA_MMA_0152, DSG_DIA_MMA_0153]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy Ueberspannungsbereichsschwelle Data to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VehicleEquipment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_VehicleEquipment()->Uberspannungsbereichsschwelle, VEHICLE_EQUIPMENT_UNTERSPANNUNGSBEREICHSSCHWELLE_SIZE);
    Rte_Exit_Coding_ExclusiveArea_VehicleEquipment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0081]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_WriteData (returns application error)
 *********************************************************************************************************************/

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeVehicleEquipment(Data, UBERSPANNUNGSBEREICHSSCHWELLE);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0063]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of VehicleEquipment NVRAM block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMVehicleEquipment_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0072, DSG_DIA_MMA_0154, DSG_DIA_MMA_0155, DSG_DIA_MMA_0156, DSG_DIA_MMA_0157]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy Unterspannungsabbruchschwelle Data to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VehicleEquipment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_VehicleEquipment()->Unterspannungsabbruchschwelle, VEHICLE_EQUIPMENT_UBERSPANNUNGSBEREICHSSCHWELLE_SIZE);
    Rte_Exit_Coding_ExclusiveArea_VehicleEquipment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0082]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData (returns application error)
 *********************************************************************************************************************/

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeVehicleEquipment(Data, UNTERSPANNUNGSABBRUCHSCHWELLE);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0062]
**/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of VehicleEquipment NVRAM block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMVehicleEquipment_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0073, DSG_DIA_MMA_0158, DSG_DIA_MMA_0159, DSG_DIA_MMA_0160, DSG_DIA_MMA_0161]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy Unterspannungsbereichsschwelle Data to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VehicleEquipment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_VehicleEquipment()->Unterspannungsbereichsschwelle, VEHICLE_EQUIPMENT_UBERSPANNUNGSABBRUCHSCHWELLE_SIZE);
    Rte_Exit_Coding_ExclusiveArea_VehicleEquipment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VehicleEquipment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VehicleEquipment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0083]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData (returns application error)
 *********************************************************************************************************************/

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeVehicleEquipment(Data, UNTERSPANNUNGSBEREICHSSCHWELLE);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_DCM_E_PENDING
 *   RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0084]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of ZZZ_Vehicle_Equipment_Development block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMZZZ_VehicleEquipment_Development_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_DCM_E_PENDING
 *   RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0086, DSG_DIA_MMA_0166, DSG_DIA_MMA_0167]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy ZZZ_Vehicle_Equipment_Development to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_ZZZ_VehicleEquipment_Development()->Bitfield, ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_BITFIELD_SIZE);
    Rte_Exit_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_DCM_E_PENDING
 *   RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0088, DSG_DIA_MMA_0168, DSG_DIA_MMA_0169]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData (returns application error)
 *********************************************************************************************************************/

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeZZZVehicleEquipmentDevelopment(Data, ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_BITFIELD);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_DCM_E_PENDING
 *   RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0085]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of ZZZ_Vehicle_Equipment_Development block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMZZZ_VehicleEquipment_Development_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_DCM_E_PENDING;
        }
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_DCM_E_PENDING
 *   RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData_doc
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
*   [COVERS: DSG_DIA_MMA_0087, DSG_DIA_MMA_0162, DSG_DIA_MMA_0163]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData (returns application error)
 *********************************************************************************************************************/

    /* #10 Copy ZZZ_Vehicle_Equipment_Development to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_ZZZ_VehicleEquipment_Development()->Zykluszeit_Messtechnik, ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_ZYKLUSZEIT_MESSTECHNIK_SIZE);
    Rte_Exit_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *   void Rte_Exit_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_DCM_E_PENDING
 *   RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData_doc
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
*   [COVERS: DSG_DIA_MMA_0089, DSG_DIA_MMA_0164, DSG_DIA_MMA_0165]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_Coding_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData (returns application error)
 *********************************************************************************************************************/

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeZZZVehicleEquipmentDevelopment(Data, ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_ZYKLUSZEIT_MESSTECHNIK);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Ct_MBBL_SsaAppl_Coding_STOP_SEC_CODE
#include "Ct_MBBL_SsaAppl_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * CodingAppl_Copy()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, Ssa_Coding_CODE)
CodingAppl_Copy(P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) targetBuf, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) dataBuf, uint32_least dataLength)
{
    uint32_least byteIdx;

    /* #10 Copy data from input buffer to the target buffer byte-by-byte. */
    for (byteIdx = 0u; byteIdx < dataLength; byteIdx++)
    {
        targetBuf[byteIdx] = dataBuf[byteIdx];
    }
}

/**********************************************************************************************************************
 * Coding_CompareData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, Ssa_Coding_CODE)
Coding_CompareData(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) buffer1, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) buffer2, uint32 size)
{
    boolean isEqual = TRUE;
    uint16 i;
    /* #10 Compare two buffers byte-by-byte. */
    for (i = 0u; i < size; i++)
    {
        if (buffer1[i] != buffer2[i])
        {
            isEqual = FALSE;
            break;
        }
    }
    return isEqual;
}

/**********************************************************************************************************************
 * Coding_ManageVariantCoding()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ManageVariantCoding(void)
{
    ReleaseCyclesBSRAndPresafe_StorageType * codingRelease;
    TensioningCycleBSR_StorageType* codingBSR;
    PreSafeCyclesLevel_StorageType *codingCycles;
    VehicleEquipment_StorageType *codingVehicleEquip;

    uint16 index;

    uint8 u8CodingValidity = KU8_TRUE;
    uint8 u8VehicleEquip = KU8_TRUE;

    codingVehicleEquip = Rte_Pim_ReleaseCyclesBsrAndPreSafe();
    if( (KU8_ZERO == codingVehicleEquip->Unterspannungsabbruchschwelle[KU8_ZERO]) && (KU8_ZERO == codingVehicleEquip->Unterspannungsbereichsschwelle[KU8_ZERO])
       && (KU8_ZERO == codingVehicleEquip->Uberspannungsabbruchschwelle[KU8_ZERO]) && (KU8_ZERO == codingVehicleEquip->Uberspannungsbereichsschwelle[KU8_ZERO]) )
    {
       u8VehicleEquip = KU8_FALSE;
    }

    codingRelease = Rte_Pim_ReleaseCyclesBsrAndPreSafe();
    if( (KU8_ZERO == codingRelease->Soft[KU8_ZERO]) && (KU8_ZERO == codingRelease->Soft[KU8_ONE]) && 
        (KU8_ZERO == codingRelease->Soft[KU8_TWO]) )
    {
        u8CodingValidity = KU8_FALSE;
    }

    codingBSR = Rte_Pim_TensioningCycleBSR();
    if( (KU8_ZERO == codingBSR->BSR1[KU8_ZERO]) && (KU8_ZERO == codingBSR->BSR1[KU8_ONE]) && 
        (KU8_ZERO == codingBSR->BSR1[KU8_TWO]) )
    {
        u8CodingValidity = KU8_FALSE;
    }

    codingCycles = Rte_Pim_PreSafeCyclesLevel();
    if( (KU8_ZERO == codingCycles->Presafe1[KU8_ZERO]) && (KU8_ZERO == codingCycles->Presafe1[KU8_ONE]) && 
        (KU8_ZERO == codingCycles->Presafe1[KU8_TWO]) )
    {
        u8CodingValidity = KU8_FALSE;
    }

    /* Check Vehicle equipment Release memory bit */
    if(NVP_stVehicleEquipmentData.ReleaseOutOfMemory != KU8_ONE)
    {
        if(KU8_FALSE != u8CodingValidity)
        {
            index = CODING_CYCLE_SIZE * CODING_RELEASE_CYCLE_NUMBER;
            CodingAppl_Copy(&NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[index], &codingRelease->Soft, CODING_CYCLE_SIZE * CODING_RELEASE_NUMBER_OF_CYCLES);

            index = CODING_STEP_SIZE * CODING_RELEASE_STEP_NUMBER;
            CodingAppl_Copy(&NVP_BLOCK_ID_STEP_0_RamBlockData.NVP_au8StepsDefinitions[index], &codingRelease->Library, sizeof(codingRelease->Library));

        }
    }

    /* Check Vehicle equipment BSR memory bit */
    if(NVP_stVehicleEquipmentData.BSROutOfMemory != KU8_ONE)
    {
        if(KU8_FALSE != u8CodingValidity)
        {
            index = CODING_CYCLE_SIZE * CODING_BSR_CYCLE_NUMBER;
            CodingAppl_Copy(&NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[index], &codingBSR->BSR1, (CODING_BSR_NUMBER_OF_CYCLES * CODING_CYCLE_SIZE) );

            index = CODING_STEP_SIZE * CODING_BSR_STEP_NUMBER;
            CodingAppl_Copy(&NVP_BLOCK_ID_STEP_0_RamBlockData.NVP_au8StepsDefinitions[index], &codingBSR->Library, sizeof(codingBSR->Library));

            CodingAppl_Copy(&NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8AfterBuckle, &codingBSR->AfterBuckle, KU8_ONE);

            CodingAppl_Copy(&NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8AfterMd, &codingBSR->AfterMd, KU8_ONE);

            CodingAppl_Copy(&NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8PwtDelay, &codingBSR->PwtDelay, KU8_ONE);

            CodingAppl_Copy(&NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8BSR1AccelerationTimeout, &codingBSR->BSR1AccelerationTimeout, KU8_ONE);

            CodingAppl_Copy(&NVP_BLOCK_ID_EOL_MAPPING_MB_RamBlockData.NVP_u8AssociatedCounterBSR, &codingBSR->AssociatedCounterBSR, KU8_ONE);
        }
    }

    /* Check Vehicle equipment Presafe memory bit */
    if(NVP_stVehicleEquipmentData.PreSafeOutOfMemory != KU8_ONE)
    {
        if(KU8_FALSE != u8CodingValidity)
        {
            CodingAppl_Copy(&NVP_BLOCK_ID_CYCLE_0_RamBlockData, &codingCycles->Presafe1, CODING_PRESAFE_CYCLES_SIZE);

            CodingAppl_Copy(&NVP_BLOCK_ID_STEP_0_RamBlockData, &codingCycles->Library, sizeof(codingCycles->Library));

            CodingAppl_Copy(&NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u16TimeoutPresafe5, &codingCycles->TimeoutPresafe5, KU8_TWO);

            CodingAppl_Copy(&NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData.NVP_u16DurationHaptic1, &codingCycles->DurationHaptic1, KU8_TWO);
            CodingAppl_Copy(&NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData.NVP_u16DurationHaptic2, &codingCycles->DurationHaptic2, KU8_TWO);
            CodingAppl_Copy(&NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData.NVP_u16DurationHaptic3, &codingCycles->DurationHaptic3, KU8_TWO);
            CodingAppl_Copy(&NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData.NVP_u16DurationHaptic4, &codingCycles->DurationHaptic4, KU8_TWO);

            CodingAppl_Copy(&NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData.NVP_u8HapticType, &codingCycles->HapticType, KU8_ONE);

            CodingAppl_Copy(&NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8PRESAFEAccelerationTimeout, &codingCycles->PRESAFEAccelerationTimeout, KU8_ONE);
            CodingAppl_Copy(&NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8Haptic1AccelerationTimeout, &codingCycles->Haptic1AccelerationTimeout, KU8_ONE);
            CodingAppl_Copy(&NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8APIAccelerationTimeout, &codingCycles->APIAccelerationTimeout, KU8_ONE);

            CodingAppl_Copy(&NVP_BLOCK_ID_EOL_MAPPING_MB_RamBlockData.NVP_uAssociatedCounter, &codingCycles->AssociatedCounter, CODING_COUNTER_SIZE);
        }
    }

    Rte_Write_psrVariantCodingValidity_u8CodingValidity(u8CodingValidity);
    Rte_Write_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8VehicleEquipValidity(u8VehicleEquip);
}

/**********************************************************************************************************************
 * Coding_ChangeVehicleEquipment()
 *********************************************************************************************************************/
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangeVehicleEquipment(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) vehicleEquipment, uint8 equipmentType)
      {
   Std_ReturnType retVal = E_OK;
   Rte_Enter_Coding_ExclusiveArea_VehicleEquipment();

   switch (equipmentType)
   {
   case VEHICLE_EQUIPMENT_1:
      /* #30 Proceed only if the new VehicleEquipment is different from the CurrentVehicleEquipment. */
      if (!Coding_CompareData(vehicleEquipment, Rte_Pim_VehicleEquipment()->Equipment1, VEHICLE_EQUIPMENT_EQUIPMENT1_SIZE))
      {
         /* #40 Change persistent Equipment1 to the retrieved one. */
         CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_VehicleEquipment()->Equipment1, vehicleEquipment, VEHICLE_EQUIPMENT_EQUIPMENT1_SIZE);
      }
      break;
   case VEHICLE_EQUIPMENT_2:
      if (!Coding_CompareData(vehicleEquipment, Rte_Pim_VehicleEquipment()->Equipment2, VEHICLE_EQUIPMENT_EQUIPMENT2_SIZE))
      {
         /* #40 Change persistent Equipment2 to the retrieved one. */
         CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_VehicleEquipment()->Equipment2, vehicleEquipment, VEHICLE_EQUIPMENT_EQUIPMENT2_SIZE);
      }
      break;
   case VEHICLE_EQUIPMENT_3:
      if (!Coding_CompareData(vehicleEquipment, Rte_Pim_VehicleEquipment()->Equipment3, VEHICLE_EQUIPMENT_EQUIPMENT3_SIZE))
      {
         /* #40 Change persistent Equipment3 to the retrieved one. */
         CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_VehicleEquipment()->Equipment3, vehicleEquipment, VEHICLE_EQUIPMENT_EQUIPMENT3_SIZE);
      }
      break;
   case VEHICLE_EQUIPMENT_4:
      if (!Coding_CompareData(vehicleEquipment, Rte_Pim_VehicleEquipment()->Equipment4, VEHICLE_EQUIPMENT_EQUIPMENT4_SIZE))
      {
         /* #40 Change persistent Equipment4 to the retrieved one. */
         CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_VehicleEquipment()->Equipment4, vehicleEquipment, VEHICLE_EQUIPMENT_EQUIPMENT4_SIZE);
      }
      break;
   case VEHICLE_EQUIPMENT_5:
      if (!Coding_CompareData(vehicleEquipment, Rte_Pim_VehicleEquipment()->Equipment5, VEHICLE_EQUIPMENT_EQUIPMENT5_SIZE))
      {
         /* #40 Change persistent Equipment5 to the retrieved one. */
         CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_VehicleEquipment()->Equipment5, vehicleEquipment, VEHICLE_EQUIPMENT_EQUIPMENT5_SIZE);
      }
      break;
   case VEHICLE_EQUIPMENT_6:
      if (!Coding_CompareData(vehicleEquipment, Rte_Pim_VehicleEquipment()->Equipment6, VEHICLE_EQUIPMENT_EQUIPMENT6_SIZE))
      {
         /* #40 Change persistent Equipment6 to the retrieved one. */
         CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_VehicleEquipment()->Equipment6, vehicleEquipment, VEHICLE_EQUIPMENT_EQUIPMENT6_SIZE);
      }

      break;
   case UNTERSPANNUNGSABBRUCHSCHWELLE:
      if (!Coding_CompareData(vehicleEquipment, Rte_Pim_VehicleEquipment()->Unterspannungsabbruchschwelle, VEHICLE_EQUIPMENT_UBERSPANNUNGSBEREICHSSCHWELLE_SIZE))
      {
         /* #40 Change persistent Unterspannungsabbruchschwelle to the retrieved one. */
         CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_VehicleEquipment()->Unterspannungsabbruchschwelle, vehicleEquipment, VEHICLE_EQUIPMENT_UBERSPANNUNGSBEREICHSSCHWELLE_SIZE);
      }
      break;
   case UNTERSPANNUNGSBEREICHSSCHWELLE:
      if (!Coding_CompareData(vehicleEquipment, Rte_Pim_VehicleEquipment()->Unterspannungsbereichsschwelle, VEHICLE_EQUIPMENT_UBERSPANNUNGSABBRUCHSCHWELLE_SIZE))
      {
         /* #40 Change persistent Unterspannungsbereichsschwelle to the retrieved one. */
         CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_VehicleEquipment()->Unterspannungsbereichsschwelle, vehicleEquipment, VEHICLE_EQUIPMENT_UBERSPANNUNGSABBRUCHSCHWELLE_SIZE);
      }
      break;
   case UBERSPANNUNGSBEREICHSSCHWELLE:
      if (!Coding_CompareData(vehicleEquipment, Rte_Pim_VehicleEquipment()->Uberspannungsbereichsschwelle, VEHICLE_EQUIPMENT_UNTERSPANNUNGSBEREICHSSCHWELLE_SIZE))
      {
         /* #40 Change persistent Uberspannungsbereichsschwelle to the retrieved one. */
         CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_VehicleEquipment()->Uberspannungsbereichsschwelle, vehicleEquipment, VEHICLE_EQUIPMENT_UNTERSPANNUNGSBEREICHSSCHWELLE_SIZE);
      }
      break;
   case UBERSPANNUNGSABBRUCHSCHWELLE:
      if (!Coding_CompareData(vehicleEquipment, Rte_Pim_VehicleEquipment()->Uberspannungsabbruchschwelle, VEHICLE_EQUIPMENT_UNTERSPANNUNGSABBRUCHSCHWELLE_SIZE))
      {
         /* #40 Change persistent Uberspannungsabbruchschwelle to the retrieved one. */
         CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_VehicleEquipment()->Uberspannungsabbruchschwelle, vehicleEquipment, VEHICLE_EQUIPMENT_UNTERSPANNUNGSABBRUCHSCHWELLE_SIZE);
      }

      break;
   default:
      break;
   }


   Rte_Exit_Coding_ExclusiveArea_VehicleEquipment();

   return retVal;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 * Coding_ChangeTensioningCycleBSR()
 *********************************************************************************************************************/
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangeTensioningCycleBSR(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) tensioningCycleBSR)
{
    Std_ReturnType retVal = E_OK;

    Rte_Enter_Coding_ExclusiveArea_TensioningCycleBSR();

    /* #30 Proceed only if the new TensioningCycleBSR is different from the current TensioningCycleBSR. */
    if (!Coding_CompareData(tensioningCycleBSR, Rte_Pim_TensioningCycleBSR(), TENSIONING_CYCLE_BSR_SIZE))
    {
        /* #40 Change persistent TensioningCycleBSR to the retrieved one. */
        CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_TensioningCycleBSR(), tensioningCycleBSR, TENSIONING_CYCLE_BSR_SIZE);
    }

    Rte_Exit_Coding_ExclusiveArea_TensioningCycleBSR();

    return retVal;
}

/**********************************************************************************************************************
 * Coding_ChangePreSafeCyclesLevel()
 *********************************************************************************************************************/
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangePreSafeCyclesLevel(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) preSafeCyclesLevel)
{
    Std_ReturnType retVal = E_OK;

    Rte_Enter_Coding_ExclusiveArea_PreSafeCyclesLevel();

    /* #30 Proceed only if the new PreSafeCyclesLevel is different from the current PreSafeCyclesLevel. */
    if (!Coding_CompareData(preSafeCyclesLevel, Rte_Pim_PreSafeCyclesLevel(), PRESAFE_CYCLES_LEVEL_SIZE))
    {
        /* #40 Change persistent PreSafeCyclesLevel to the retrieved one. */
        CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_PreSafeCyclesLevel(), preSafeCyclesLevel, PRESAFE_CYCLES_LEVEL_SIZE);
    }


    Rte_Exit_Coding_ExclusiveArea_PreSafeCyclesLevel();

    return retVal;
}

/**********************************************************************************************************************
 * Coding_ChangeReleaseCyclesBsrAndPreSafe()
 *********************************************************************************************************************/
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangeReleaseCyclesBsrAndPreSafe(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) releaseCyclesBsrAndPreSafe)
{
    Std_ReturnType retVal = E_OK;

    Rte_Enter_Coding_ExclusiveArea_ReleaseCyclesBsrAndPreSafe();

    /* #30 Proceed only if the new ReleaseCyclesBsrAndPreSafe is different from the current ReleaseCyclesBsrAndPreSafe. */
    if (!Coding_CompareData(releaseCyclesBsrAndPreSafe, Rte_Pim_ReleaseCyclesBsrAndPreSafe(), RELEASE_CYCLES_BSR_AND_PRESAFE_SIZE))
    {
        /* #40 Change persistent ReleaseCyclesBsrAndPreSafe to the retrieved one. */
        CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_ReleaseCyclesBsrAndPreSafe(), releaseCyclesBsrAndPreSafe, RELEASE_CYCLES_BSR_AND_PRESAFE_SIZE);
    }

    Rte_Exit_Coding_ExclusiveArea_ReleaseCyclesBsrAndPreSafe();

    return retVal;
}

/**********************************************************************************************************************
 * Coding_ChangeZZZVehicleEquipmentDevelopment()
 *********************************************************************************************************************/
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangeZZZVehicleEquipmentDevelopment(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) zzzVechicleEquipmentDevelopment, uint8 equipmentType)
{
    Std_ReturnType retVal = E_OK;

    Rte_Enter_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment();

    switch (equipmentType)
    {
    case ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_BITFIELD:
        if (!Coding_CompareData(zzzVechicleEquipmentDevelopment, Rte_Pim_ZZZ_VehicleEquipment_Development()->Bitfield, ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_BITFIELD_SIZE))
        {
            /* #40 Change persistent Bitfield to the retrieved one. */
            CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_ZZZ_VehicleEquipment_Development()->Bitfield, zzzVechicleEquipmentDevelopment, ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_BITFIELD_SIZE);
        }
        break;
    case ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_ZYKLUSZEIT_MESSTECHNIK:
        if (!Coding_CompareData(zzzVechicleEquipmentDevelopment, Rte_Pim_ZZZ_VehicleEquipment_Development()->Zykluszeit_Messtechnik, ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_ZYKLUSZEIT_MESSTECHNIK_SIZE))
        {
            /* #40 Change persistent Zykluszeit_Messtechnik to the retrieved one. */
            CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_ZZZ_VehicleEquipment_Development()->Zykluszeit_Messtechnik, zzzVechicleEquipmentDevelopment, ZZZ_VEHICLE_EQUIPMENT_DEVELOPMENT_ZYKLUSZEIT_MESSTECHNIK_SIZE);
        }
        break;
    default:
        break;
    }

    Rte_Exit_Coding_ExclusiveArea_ZZZVehicleEquipmentDevelopment();

    return retVal;
}

/**********************************************************************************************************************
 * Coding_ChangeCalID()
 *********************************************************************************************************************/
CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangeCalID(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) calId)
{
    Std_ReturnType retVal = E_OK;

    Rte_Enter_Coding_ExclusiveArea_CalID();

    /* #30 Proceed only if the new CAL ID is different from the current CAL ID. */
    if (!Coding_CompareData(calId, Rte_Pim_CalibrationID()->CalibrationIdentification, (CAL_ID_SIZE - 1u)))
    {
        /* #40 Change persistent CAL ID to the retrieved one. */
        CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_CalibrationID()->CalibrationIdentification, calId, (CAL_ID_SIZE - 1u));
    }

    Rte_Exit_Coding_ExclusiveArea_CalID();

    return retVal;
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ConditionCheckRead)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_DID_0135_Number_of_SAR_Write_Cycles_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_DID_0135_Max_Number_of_SAR_Write_Cycles_ReadData)  */

    *Data = (*Rte_Pim_PIM_CodingData()).MaxNumberOfSARWriteCycles;
    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_DID_0135_Max_Number_of_SAR_Write_Cycles_ConditionCheckRead)  */

    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_DID_0135_Number_of_SAR_Write_Cycles_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_DID_0135_Max_Number_of_SAR_Write_Cycles_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_DID_0135_Max_Number_of_SAR_Write_Cycles_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_WriteData)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_DID_0135_Number_of_SAR_Write_Cycles_ConditionCheckRead)  */

    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_DID_0135_Number_of_SAR_Write_Cycles_ReadData)  */
    *Data = (*Rte_Pim_PIM_CodingData()).NumberOfSARWriteCycles;
    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadDataLength)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadData)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_1_ReadData)  */

    /* #10 Copy RaceStart_Strafflevel_Stufe_1 Data to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VehicleEquipment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_VehicleEquipment()->RaceStart_Stufe1, VEHICLE_EQUIPMENT_RACESTART_STAFFLEVEL_STUFE1_SIZE);
    Rte_Exit_Coding_ExclusiveArea_VehicleEquipment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_2_ReadData)  */

    /* #10 Copy RaceStart_Strafflevel_Stufe_2 Data to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VehicleEquipment();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_VehicleEquipment()->RaceStart_Stufe2, VEHICLE_EQUIPMENT_RACESTART_STAFFLEVEL_STUFE2_SIZE);
    Rte_Exit_Coding_ExclusiveArea_VehicleEquipment();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_2_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Release_Cycles_BSR_and_PreSafe_Read_Release_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_2_WriteData)  */

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeVehicleEquipment(Data, RACESTART_STRAFFLEVEL_STUFE_2);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_PreSafe_Cycles_Level_1_8_Read_PreSafe_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Tensioning_Cycle_BSR_Read_BSR_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Tensioning_Cycle_BSR_Read_BSR_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Tensioning_Cycle_BSR_Read_BSR_WriteData)  */

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeTensioningCycleBSR(Data);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Release_Cycles_BSR_and_PreSafe_Read_Release_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_2_ConditionCheckRead)  */

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of VehicleEquipment NVRAM block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMVehicleEquipment_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_2_DCM_E_PENDING;
        }
    }

    return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_1_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Release_Cycles_BSR_and_PreSafe_Read_Release_ConditionCheckRead)  */

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of ReleaseCyclesBsrAndPreSafe block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMReleaseCyclesBsrAndPreSafe_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Release_Cycles_BSR_and_PreSafe_Read_Release_E_NOT_OK;
        }
    }

    return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_PreSafe_Cycles_Level_1_8_Read_PreSafe_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_2_WriteData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Release_Cycles_BSR_and_PreSafe_Read_Release_WriteData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_1_WriteData)  */

        uint8 retVal = RTE_E_OK;

        (void)Coding_ChangeVehicleEquipment(Data, RACESTART_STRAFFLEVEL_STUFE_1);

        *ErrorCode = DCM_E_POSITIVERESPONSE;

        return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Tensioning_Cycle_BSR_Read_BSR_WriteData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_1_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_PreSafe_Cycles_Level_1_8_Read_PreSafe_WriteData)  */

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangePreSafeCyclesLevel(Data);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_1_ConditionCheckRead)  */

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of VehicleEquipment NVRAM block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMVehicleEquipment_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_1_DCM_E_PENDING;
        }
    }

    return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Release_Cycles_BSR_and_PreSafe_Read_Release_WriteData)  */

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeReleaseCyclesBsrAndPreSafe(Data);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_PreSafe_Cycles_Level_1_8_Read_PreSafe_ConditionCheckRead)  */

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of PresafeCyclesLevel block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMPresafeCyclesLevel_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_PreSafe_Cycles_Level_1_8_Read_PreSafe_DCM_E_PENDING;
        }
    }

    return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Tensioning_Cycle_BSR_Read_BSR_ReadData)  */

    /* #10 Copy TensioningCycleBSR to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_TensioningCycleBSR();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_TensioningCycleBSR(), TENSIONING_CYCLE_BSR_SIZE);
    Rte_Exit_Coding_ExclusiveArea_TensioningCycleBSR();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_PreSafe_Cycles_Level_1_8_Read_PreSafe_ReadData)  */

    /* #10 Copy PreSafeCyclesLevel to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_PreSafeCyclesLevel();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_PreSafeCyclesLevel(), PRESAFE_CYCLES_LEVEL_SIZE);
    Rte_Exit_Coding_ExclusiveArea_PreSafeCyclesLevel();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Release_Cycles_BSR_and_PreSafe_Read_Release_ReadData)  */

    /* #10 Copy PreSafeCyclesLevel to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_ReleaseCyclesBsrAndPreSafe();
    CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_ReleaseCyclesBsrAndPreSafe(), RELEASE_CYCLES_BSR_AND_PRESAFE_SIZE);
    Rte_Exit_Coding_ExclusiveArea_ReleaseCyclesBsrAndPreSafe();

    /* #20 Always return successfully. */
    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_1_WriteData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Tensioning_Cycle_BSR_Read_BSR_ConditionCheckRead)  */

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of TensioningCycleBSR block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMTensioningCycleBSR_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Tensioning_Cycle_BSR_Read_BSR_DCM_E_PENDING;
        }
    }

    return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Vehicle_Equipment_Read_RaceStart_Strafflevel_Stufe_2_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_PreSafe_Cycles_Level_1_8_Read_PreSafe_WriteData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Tensioning_Cycle_BSR_CombinedSigna_WriteData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Tensioning_Cycle_BSR_CombinedSigna_WriteData)  */

    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Tensioning_Cycle_BSR_CombinedSigna_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Tensioning_Cycle_BSR_CombinedSigna_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Tensioning_Cycle_BSR_CombinedSigna_ReadData)  */

    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Tensioning_Cycle_BSR_CombinedSigna_ConditionCheckRead)  */

    Std_ReturnType retVal = RTE_E_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
        /* #20 Get status of TensioningCycleBSR block and forward it to the diagnostic user. */
        retVal = Rte_Call_NvMTensioningCycleBSR_GetErrorStatus(&errorStatus);
        if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
        {
            retVal = RTE_E_DataServices_Tensioning_Cycle_BSR_Read_BSR_DCM_E_PENDING;
        }
    }
/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_WriteData)  */

    uint8 retVal = RTE_E_OK;

    (void)Coding_ChangeCalID(Data);

    *ErrorCode = DCM_E_POSITIVERESPONSE;

    return retVal;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_WriteData_doc)  */

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
