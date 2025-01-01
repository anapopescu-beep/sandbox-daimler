/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: NvM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: NvM_Cfg.h
 *   Generation Time: 2024-03-19 15:15:17
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


/* PRQA S 5087 MemMap */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
/* public section - to be used by NvM itself and its users */
#if (!defined NVM_CFG_H_PUBLIC)
#define NVM_CFG_H_PUBLIC

/**********************************************************************************************************************
 * VERSION IDENTIFICATION
 *********************************************************************************************************************/
#define NVM_CFG_MAJOR_VERSION    (9u)
#define NVM_CFG_MINOR_VERSION    (2u)
#define NVM_CFG_PATCH_VERSION    (0u)

/**********************************************************************************************************************
 * NVM API TYPE INCLUDES
 *********************************************************************************************************************/
#include "NvM_Types.h"

/**********************************************************************************************************************
 * API CFG TYPE DEFINITIONS
 *********************************************************************************************************************/
/* Type for an the additional published parameter Compiled Configuration ID (see CompiledConfigurationId in NvM.h). */
/* Compiled Config Id Type */
typedef union
{ /* PRQA S 0750 */ /* MD_MSR_Union */
    uint16 Word_u16;
    uint8  Bytes_au8[2u];
} NvM_CompiledConfigIdType;

/**********************************************************************************************************************
 * CFG COMMON PARAMETER
 *********************************************************************************************************************/
/* --------------------  DEVELOPMENT / PRODUCTION MODE -------------------- */
/* switch between Debug- or Production-Mode */
#define NVM_DEV_ERROR_DETECT                  (STD_ON)

/* Preprocessor switch that is used in NvM_ReadAll() */
#define NVM_DYNAMIC_CONFIGURATION             (STD_OFF)

#define NVM_API_CONFIG_CLASS_1                (1u)
#define NVM_API_CONFIG_CLASS_2                (3u)
#define NVM_API_CONFIG_CLASS_3                (7u)

#define NVM_API_CONFIG_CLASS                  (NVM_API_CONFIG_CLASS_3)

#define NVM_JOB_PRIORISATION                  STD_OFF

/* define compiled Block ID */
#define NVM_COMPILED_CONFIG_ID                (1u)

/* switch for enablinig fast mode during multi block requests */
#define NVM_DRV_MODE_SWITCH                   (STD_ON)

/* switch for enablinig polling mode and disabling notifications */
#define NVM_POLLING_MODE                      (STD_ON)

/* switch for enabling the internal buffer for data integrity handling */
#define NVM_DATA_INTEGRITY_INT_BUFFER         (STD_ON)

/* number of defined NV blocks */
#define NVM_TOTAL_NUM_OF_NVRAM_BLOCKS         (103u)

/* internal buffer size */
#define NVM_INTERNAL_BUFFER_LENGTH            1164u

/* internal immediate data buffer size */
#define NVM_INTERNAL_IMMEDIATE_DATA_BUFFER_LENGTH  96u

/* version info api switch */
#define NVM_VERSION_INFO_API                  (STD_ON)

/* switch to enable the ram block status api */
#define NVM_SET_RAM_BLOCK_STATUS_API          (STD_ON)

/* switch that gives the user (EcuM) the possibility to time-out WriteAll cancellation */
#define NVM_KILL_WRITEALL_API                 (STD_ON)

/* enabled or disable the whole repair redundant blocks feature */
#define NVM_REPAIR_REDUNDANT_BLOCKS_API       (STD_ON)

/* switch to enable the pre readall api to be able to split the readall into two phases */
#define NVM_PRE_READALL_API                   (STD_OFF)

/* NVM does not need this macro. It is intended for underlying modules,
 * relying on its existence
 */
#define NVM_DATASET_SELECTION_BITS            (2u)

/* switch for enabling the job forwading from the application to the memory core */
#define  NVM_JOB_FORWARDING_TO_MEMORY_CORE    (STD_OFF) 

/* block offset for DCM blocks */
#define NVM_DCM_BLOCK_OFFSET                  0x8000u

/* Enabled if at least one block used NvMCalcRamblockCrc and ExplicitSync mechanisms */
#define NVM_CRC_USE_INTERNAL_EXPLICIT_SYNC_BUFFER (STD_OFF)


/* Enabled if at least one block used immediate data */
#define NVM_INTERNAL_IMMEDIATE_DATA_BUFFER  (STD_ON)

/* returns corresponding DCM BlockId of an original NVRAM Block */
#define NvM_GetDcmBlockId(MyApplBlockId)      ((MyApplBlockId) | NVM_DCM_BLOCK_OFFSET) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* BlockId's:
 * Note: The numbers of the following list must meet the configured blocks in the NvM_BlockDescriptorTable_at
 *
 * Alignment of the handles of all blocks
 * Id 0 is reserved for multiblock calls
 * Id 1 is reserved for config ID
 */
#define NvMConf___MultiBlockRequest (0u) 
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock (1u) 
#define NvMConf_NvMBlockDescriptor_Cp_MBBL_SsaAppl_CodingNvBlockNeed_CodingData (2u) 
#define NvMConf_NvMBlockDescriptor_Ssa_CodingNvM_Coding_CodingVIN (3u) 
#define NvMConf_NvMBlockDescriptor_Ssa_CodingNvM_Coding_CurrentVIN (4u) 
#define NvMConf_NvMBlockDescriptor_Ssa_RightsM_NvM_RightsM_AclVersion (5u) 
#define NvMConf_NvMBlockDescriptor_Ssa_RightsM_NvM_RightsM_Nonce (6u) 
#define NvMConf_NvMBlockDescriptor_Ssa_RightsM_NvM_RightsM_PostProductionStatus (7u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogDataEvnt10_FailedPduMacVerif (8u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogDataEvnt11_SecOrAuthBoot (9u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogDataEvnt12_ChangeOfVin (10u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogDataEvnt13_AclReplacement (11u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogDataEvnt1_FailedCertVerif (12u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogDataEvnt2_SucCertVerif (13u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights (14u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogDataEvnt4_AuthBySecAccess (15u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogDataEvnt5_SucDiagServiceExec (16u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogDataEvnt6_RightsMgmt (17u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogDataEvnt7_SigVerif (18u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogDataEvnt8_TickCountDateAndTime (19u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogDataEvnt9_SecOcMisconfig (20u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogFailedMacVerifCount_ExceededTh1 (21u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogFailedMacVerifCount_ExceededTh2 (22u) 
#define NvMConf_NvMBlockDescriptor_Ssa_SecLogNvM_SecLog_LogFailedMacVerifCount_ExceededTh3 (23u) 
#define NvMConf_NvMBlockDescriptor_Ssa_TimeM_NvM_TimeM_RealTimeOffset (24u) 
#define NvMConf_NvMBlockDescriptor_Ssa_TimeM_NvM_TimeM_TickCount (25u) 
#define NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvBlockNeed_CodingData (26u) 
#define NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_CurrentVehicleEquipment (27u) 
#define NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_TensioningCycleBSR (28u) 
#define NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_PreSafeCyclesLevel (29u) 
#define NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_ReleaseCyclesBsrAndPreSafe (30u) 
#define NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_ZZZVehicleEquipmentDevelopment (31u) 
#define NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_CalibrationID (32u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_FblMetaData (33u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_ECU_LOCATION (34u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN (35u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_HB_CALIBRATION (36u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_HW_VERSION (37u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_AEE_TRACEABILITY (38u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_EXECUTION_COUNTERS (39u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_TESTS_PARAM (40u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG (41u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG (42u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_CYCLE (43u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_CYCLE_DELAYS_MB (44u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_HAPTIC_CONFIG_MB (45u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_EOL_MAPPING_MB (46u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_STEP (47u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_EOL_PARAM (48u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_BFS_PRIO_PARAM (49u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_PID_PARAM (50u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_WEIGHT_REL_TABLE (51u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_WEIGHT_TENS0_TABLE (52u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_WEIGHT_TENS1_TABLE (53u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_WEIGHT_TENS2_TABLE (54u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_WEIGHT_TENS3_TABLE (55u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_INT_CURRENT_CORR (56u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_INT_CURRENT_TABLE (57u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_ECPL_ALPHA_TABLE (58u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_POWER_DEGRADATION (59u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_ECPL_BETA_TABLE (60u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_ECPL_OTHER_PARAM (61u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_BPA_MOTOR_CURRENT (62u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_VOLT_THRS (63u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_BATTERY_LOSS_DETECTION_THRS (64u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_BOOST (65u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_ECU_PROPERTIES (66u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_SW_SELF_PROTECTION_THRS (67u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_MOTOR_RESIST_PARAM (68u) 
#define NvMConf_NvMBlockDescriptor_CALIB_BLOCK_ID_BOOST_ACTIVATION (69u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_WARM_RESET (70u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_PRE_SAFE_RECORDER_1 (71u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_PRE_SAFE_RECORDER_ID (72u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_CAN_INPUT_SIGNALS (73u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_PRE_SAFE_RECORDER_2 (74u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_HWA_REPETITION (75u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_TEMP_SENSOR_TABLE (76u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_SYSTEM_CONTEXT_0 (77u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_SYSTEM_CONTEXT_1 (78u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_SYSTEM_CONTEXT_2 (79u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_VELOCITY_PID_PARAM (80u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_AEC_STATUS (81u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_ATM_ENABLE_PARAM (82u) 
#define NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_0 (83u) 
#define NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_1 (84u) 
#define NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_2 (85u) 
#define NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_3 (86u) 
#define NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_4 (87u) 
#define NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_5 (88u) 
#define NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_6 (89u) 
#define NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_7 (90u) 
#define NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_8 (91u) 
#define NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_9 (92u) 
#define NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Status (93u) 
#define NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Admin_Data (94u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_SecAccessDelayFlag (95u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_VerificationKey (96u) 
#define NvMConf_NvMBlockDescriptor_Ssa_KeyM_NvM_KeyM_TrustModelChainOfTrustState (97u) 
#define NvMConf_NvMBlockDescriptor_Rtm_CpuLoadPersistencyData (98u) 
#define NvMConf_NvMBlockDescriptor_Rtm_MaxTaskStackUsage (99u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_PCBA_PPN (100u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE (101u) 
#define NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_HW_PARTNUMBER (102u) 


/* CONST_DESCRIPTOR_TABLE contains all block relevant data, including the compiled config ID
 */
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

/* Additional published parameter because e.g. in case of validate all RAM
 * Blocks it is nice to know the number of Blocks. But take care: this number
 * of Blocks includes Block 0 and Block 1, which are the MultiBlock and the
 * Configuration Block - user Blocks start wiht index 2!
 */
extern CONST(NvM_BlockIdType, NVM_PUBLIC_CONST) NvM_NoOfBlockIds_t;

/* Additional published parameter because in case of a clear EEPROM, it is
 * necessary, to write the Configuration Block containing this Compiled
 * Configuration ID to EEPROM
 */
/* Compiled Configuration ID as defined in NvM_Cfg.c */
extern CONST(NvM_CompiledConfigIdType, NVM_PUBLIC_CONST) NvM_CompiledConfigId_t; /* PRQA S 0759 */ /* MD_MSR_Union */

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

/* Component define block (available, if EcuC module is active, otherwise only NVM_DUMMY_STATEMENTs are defined*/
#ifndef NVM_USE_DUMMY_STATEMENT
#define NVM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_DUMMY_STATEMENT
#define NVM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_DUMMY_STATEMENT_CONST
#define NVM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef NVM_ATOMIC_VARIABLE_ACCESS
#define NVM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef NVM_PROCESSOR_TC322L
#define NVM_PROCESSOR_TC322L
#endif
#ifndef NVM_COMP_TASKING
#define NVM_COMP_TASKING
#endif
#ifndef NVM_GEN_GENERATOR_MSR
#define NVM_GEN_GENERATOR_MSR
#endif
#ifndef NVM_CPUTYPE_BITORDER_LSB2MSB
#define NVM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef NVM_CONFIGURATION_VARIANT_PRECOMPILE
#define NVM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef NVM_CONFIGURATION_VARIANT_LINKTIME
#define NVM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef NVM_CONFIGURATION_VARIANT
#define NVM_CONFIGURATION_VARIANT NVM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef NVM_POSTBUILD_VARIANT_SUPPORT
#define NVM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* ---- end public configuration section ---------------------------------- */
#endif /* NVM_CFG_H_PUBLIC */

/* PRQA L:MemMap */

/**********************************************************************************************************************
 *  END OF FILE: NvM_Cfg.h
 *********************************************************************************************************************/

