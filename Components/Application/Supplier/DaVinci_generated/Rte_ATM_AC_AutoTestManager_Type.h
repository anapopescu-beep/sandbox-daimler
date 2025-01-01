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
 *             File:  Rte_ATM_AC_AutoTestManager_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application types header file for SW-C <ATM_AC_AutoTestManager>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_ATM_AC_AUTOTESTMANAGER_TYPE_H
# define RTE_ATM_AC_AUTOTESTMANAGER_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  define Rsrv04_LowerLimit (0U)
#  define Rsrv04_UpperLimit (15U)

#  define InvalidValue_Rsrv04 (15U)

#  define Rsrv08_LowerLimit (0U)
#  define Rsrv08_UpperLimit (255U)

#  define InvalidValue_Rsrv08 (255U)

#  define UInt16_Appl_LowerLimit (0U)
#  define UInt16_Appl_UpperLimit (65535U)

#  define UInt32_Appl_LowerLimit (0U)
#  define UInt32_Appl_UpperLimit (4294967295U)

#  define UInt8_Appl_LowerLimit (0U)
#  define UInt8_Appl_UpperLimit (255U)

#  define b8DefectStatusType_Appl_LowerLimit (0U)
#  define b8DefectStatusType_Appl_UpperLimit (255U)

#  define c08_0_255_1_SNA_na_LowerLimit (0U)
#  define c08_0_255_1_SNA_na_UpperLimit (255U)

#  define c16_CRC_woSNA_LowerLimit (0U)
#  define c16_CRC_woSNA_UpperLimit (65535U)

#  define s16AccelerationPedalPositionRateType_Appl_LowerLimit (-32768)
#  define s16AccelerationPedalPositionRateType_Appl_UpperLimit (32767)

#  define s16AccelerationType_Appl_LowerLimit (-32768)
#  define s16AccelerationType_Appl_UpperLimit (32767)

#  define s16AngleRateType_Appl_LowerLimit (-32768)
#  define s16AngleRateType_Appl_UpperLimit (32767)

#  define s16BeltPosition_degType_Appl_LowerLimit (-32768)
#  define s16BeltPosition_degType_Appl_UpperLimit (32767)

#  define s16BeltPosition_mmType_Appl_LowerLimit (-32768)
#  define s16BeltPosition_mmType_Appl_UpperLimit (32767)

#  define s16BrakePressureRateType_Appl_LowerLimit (-32768)
#  define s16BrakePressureRateType_Appl_UpperLimit (32767)

#  define s16HWAngleType_Appl_LowerLimit (-32768)
#  define s16HWAngleType_Appl_UpperLimit (32767)

#  define s16HWRateType_Appl_LowerLimit (-32768)
#  define s16HWRateType_Appl_UpperLimit (32767)

#  define s16InternalTemperature_deg_Type_Appl_LowerLimit (-32768)
#  define s16InternalTemperature_deg_Type_Appl_UpperLimit (32767)

#  define s16MotorPowerOrderType_Appl_LowerLimit (-32768)
#  define s16MotorPowerOrderType_Appl_UpperLimit (32767)

#  define s32BeltSpeed_deg_sType_Appl_LowerLimit (-2147483647 - 1)
#  define s32BeltSpeed_deg_sType_Appl_UpperLimit (2147483647)

#  define s32BeltSpeed_mm_sType_Appl_LowerLimit (-2147483647 - 1)
#  define s32BeltSpeed_mm_sType_Appl_UpperLimit (2147483647)

#  define s32MotorCurrentInmAType_Appl_LowerLimit (-2147483647 - 1)
#  define s32MotorCurrentInmAType_Appl_UpperLimit (2147483647)

#  define s32OrderValueType_Appl_LowerLimit (-2147483647 - 1)
#  define s32OrderValueType_Appl_UpperLimit (2147483647)

#  define s8MotorCurrentInAType_Appl_LowerLimit (-128)
#  define s8MotorCurrentInAType_Appl_UpperLimit (127)

#  define u16BoostPWMOrderType_Appl_LowerLimit (0U)
#  define u16BoostPWMOrderType_Appl_UpperLimit (65535U)

#  define u16BrakePressureType_Appl_LowerLimit (0U)
#  define u16BrakePressureType_Appl_UpperLimit (65535U)

#  define u16CurrentInLSBType_Appl_LowerLimit (0U)
#  define u16CurrentInLSBType_Appl_UpperLimit (65535U)

#  define u16InternalTemperatureType_Appl_LowerLimit (0U)
#  define u16InternalTemperatureType_Appl_UpperLimit (65535U)

#  define u16Resistance_mOhmType_Appl_LowerLimit (0U)
#  define u16Resistance_mOhmType_Appl_UpperLimit (65535U)

#  define u16SampledSignalType_Appl_LowerLimit (0U)
#  define u16SampledSignalType_Appl_UpperLimit (65535U)

#  define u16StepDurationType_Appl_LowerLimit (0U)
#  define u16StepDurationType_Appl_UpperLimit (65535U)

#  define u16VehicleSpeedType_Appl_LowerLimit (0U)
#  define u16VehicleSpeedType_Appl_UpperLimit (65535U)

#  define u16VoltageType_Appl_LowerLimit (0U)
#  define u16VoltageType_Appl_UpperLimit (65535U)

#  define u32DeficiencyLevelType_Appl_LowerLimit (0U)
#  define u32DeficiencyLevelType_Appl_UpperLimit (4294967295U)

#  define u32InternalCounterType_Appl_LowerLimit (0U)
#  define u32InternalCounterType_Appl_UpperLimit (4294967295U)

#  define u32RelativeSystemTimeType_Appl_LowerLimit (0U)
#  define u32RelativeSystemTimeType_Appl_UpperLimit (4294967295U)

#  define u8AccelerationPedalPositionType_Appl_LowerLimit (0U)
#  define u8AccelerationPedalPositionType_Appl_UpperLimit (255U)

#  define u8SeverityLevelType_Appl_LowerLimit (0U)
#  define u8SeverityLevelType_Appl_UpperLimit (255U)

#  define u8StepNumberType_Appl_LowerLimit (0U)
#  define u8StepNumberType_Appl_UpperLimit (255U)


#  ifndef NVM_BLOCK_ID_INTERNAL
#   define NVM_BLOCK_ID_INTERNAL (0U)
#  endif

#  ifndef NVM_BLOCK_ID_CONFIG_ID
#   define NVM_BLOCK_ID_CONFIG_ID (1U)
#  endif

#  ifndef NVM_BLOCK_ID_DEM
#   define NVM_BLOCK_ID_DEM (2U)
#  endif

#  ifndef NVM_BLOCK_ID_ECU_LOCATION
#   define NVM_BLOCK_ID_ECU_LOCATION (3U)
#  endif

#  ifndef NVM_BLOCK_ID_ECU_LOCATION_MIRROR
#   define NVM_BLOCK_ID_ECU_LOCATION_MIRROR (4U)
#  endif

#  ifndef NVM_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN
#   define NVM_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN (5U)
#  endif

#  ifndef NVM_BLOCK_ID_HB_CALIBRATION
#   define NVM_BLOCK_ID_HB_CALIBRATION (6U)
#  endif

#  ifndef NVM_BLOCK_ID_ECU_UNLOCK
#   define NVM_BLOCK_ID_ECU_UNLOCK (7U)
#  endif

#  ifndef NVM_BLOCK_ID_PROCESS_MODE
#   define NVM_BLOCK_ID_PROCESS_MODE (8U)
#  endif

#  ifndef NVM_BLOCK_ID_HW_PART_NUMBER
#   define NVM_BLOCK_ID_HW_PART_NUMBER (9U)
#  endif

#  ifndef NVM_BLOCK_ID_AEE_TRACEABILITY
#   define NVM_BLOCK_ID_AEE_TRACEABILITY (10U)
#  endif

#  ifndef NVM_BLOCK_ID_ECLK
#   define NVM_BLOCK_ID_ECLK (11U)
#  endif

#  ifndef NVM_BLOCK_ID_ECC_COUNTERS
#   define NVM_BLOCK_ID_ECC_COUNTERS (12U)
#  endif

#  ifndef NVM_BLOCK_ID_WARM_RESET
#   define NVM_BLOCK_ID_WARM_RESET (13U)
#  endif

#  ifndef NVM_BLOCK_ID_SYSTEM_CONTEXT_0
#   define NVM_BLOCK_ID_SYSTEM_CONTEXT_0 (14U)
#  endif

#  ifndef NVM_BLOCK_ID_SYSTEM_CONTEXT_1
#   define NVM_BLOCK_ID_SYSTEM_CONTEXT_1 (15U)
#  endif

#  ifndef NVM_BLOCK_ID_SYSTEM_CONTEXT_2
#   define NVM_BLOCK_ID_SYSTEM_CONTEXT_2 (16U)
#  endif

#  ifndef NVM_BLOCK_ID_EXECUTION_COUNTERS
#   define NVM_BLOCK_ID_EXECUTION_COUNTERS (17U)
#  endif

#  ifndef NVM_BLOCK_ID_EXECUTION_COUNTERS_1
#   define NVM_BLOCK_ID_EXECUTION_COUNTERS_1 (18U)
#  endif

#  ifndef NVM_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG
#   define NVM_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG (19U)
#  endif

#  ifndef NVM_BLOCK_ID_MEASUREMENT_FRAME_CONFIG
#   define NVM_BLOCK_ID_MEASUREMENT_FRAME_CONFIG (20U)
#  endif

#  ifndef NVM_BLOCK_ID_TESTS_PARAM
#   define NVM_BLOCK_ID_TESTS_PARAM (21U)
#  endif

#  ifndef NVM_BLOCK_ID_BPA_PARAM
#   define NVM_BLOCK_ID_BPA_PARAM (22U)
#  endif

#  ifndef NVM_BLOCK_ID_BELT_FUNCTIONS_ENABLE
#   define NVM_BLOCK_ID_BELT_FUNCTIONS_ENABLE (23U)
#  endif

#  ifndef NVM_BLOCK_ID_ATM_ENABLE_PARAM
#   define NVM_BLOCK_ID_ATM_ENABLE_PARAM (24U)
#  endif

#  ifndef NVM_BLOCK_EOL_CHECK
#   define NVM_BLOCK_EOL_CHECK (25U)
#  endif

#  ifndef NVM_BLOCK_AEC
#   define NVM_BLOCK_AEC (26U)
#  endif

#  ifndef NVM_BLOCK_ID_HWA_REPETITION
#   define NVM_BLOCK_ID_HWA_REPETITION (27U)
#  endif

#  ifndef NVM_BLOCK_ID_FAZIT
#   define NVM_BLOCK_ID_FAZIT (28U)
#  endif

#  ifndef NVP_BLOCK_ID_SECURITYATT
#   define NVP_BLOCK_ID_SECURITYATT (29U)
#  endif

#  ifndef NVM_BLOCK_ID_SPARE_PART_NUMBER
#   define NVM_BLOCK_ID_SPARE_PART_NUMBER (30U)
#  endif

#  ifndef NVM_BLOCK_ID_HARDWARE_VERSION_NUMBER
#   define NVM_BLOCK_ID_HARDWARE_VERSION_NUMBER (31U)
#  endif

#  ifndef NVM_BLOCK_ID_HARDWARE_NUMBER
#   define NVM_BLOCK_ID_HARDWARE_NUMBER (32U)
#  endif

#  ifndef NVM_BLOCK_ID_SYSTEM_NAME
#   define NVM_BLOCK_ID_SYSTEM_NAME (33U)
#  endif

#  ifndef NVM_BLOCK_ID_ECU_SERIAL_NUMBER
#   define NVM_BLOCK_ID_ECU_SERIAL_NUMBER (34U)
#  endif

#  ifndef NVM_BLOCK_ID_RGS_CODING_VALUES
#   define NVM_BLOCK_ID_RGS_CODING_VALUES (35U)
#  endif

#  ifndef NVM_BLOCK_AEC_STATUS_COUNTER
#   define NVM_BLOCK_AEC_STATUS_COUNTER (36U)
#  endif

#  ifndef NVM_BLOCK_ID_ALV_NVM_VERSION
#   define NVM_BLOCK_ID_ALV_NVM_VERSION (37U)
#  endif

#  ifndef NVP_BLOCK_FBL
#   define NVP_BLOCK_FBL (38U)
#  endif

#  ifndef NVP_BLOCK_LOW_POWER
#   define NVP_BLOCK_LOW_POWER (39U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_0
#   define NVM_BLOCK_ID_CYCLE_0 (40U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_1
#   define NVM_BLOCK_ID_CYCLE_1 (41U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_2
#   define NVM_BLOCK_ID_CYCLE_2 (42U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_3
#   define NVM_BLOCK_ID_CYCLE_3 (43U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_4
#   define NVM_BLOCK_ID_CYCLE_4 (44U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_5
#   define NVM_BLOCK_ID_CYCLE_5 (45U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_6
#   define NVM_BLOCK_ID_CYCLE_6 (46U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_7
#   define NVM_BLOCK_ID_CYCLE_7 (47U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_8
#   define NVM_BLOCK_ID_CYCLE_8 (48U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_9
#   define NVM_BLOCK_ID_CYCLE_9 (49U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_10
#   define NVM_BLOCK_ID_CYCLE_10 (50U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_11
#   define NVM_BLOCK_ID_CYCLE_11 (51U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_12
#   define NVM_BLOCK_ID_CYCLE_12 (52U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_13
#   define NVM_BLOCK_ID_CYCLE_13 (53U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_14
#   define NVM_BLOCK_ID_CYCLE_14 (54U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_15
#   define NVM_BLOCK_ID_CYCLE_15 (55U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_16
#   define NVM_BLOCK_ID_CYCLE_16 (56U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_17
#   define NVM_BLOCK_ID_CYCLE_17 (57U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_18
#   define NVM_BLOCK_ID_CYCLE_18 (58U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_19
#   define NVM_BLOCK_ID_CYCLE_19 (59U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_20
#   define NVM_BLOCK_ID_CYCLE_20 (60U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_21
#   define NVM_BLOCK_ID_CYCLE_21 (61U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_22
#   define NVM_BLOCK_ID_CYCLE_22 (62U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_23
#   define NVM_BLOCK_ID_CYCLE_23 (63U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_24
#   define NVM_BLOCK_ID_CYCLE_24 (64U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_25
#   define NVM_BLOCK_ID_CYCLE_25 (65U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_26
#   define NVM_BLOCK_ID_CYCLE_26 (66U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_27
#   define NVM_BLOCK_ID_CYCLE_27 (67U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_28
#   define NVM_BLOCK_ID_CYCLE_28 (68U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_29
#   define NVM_BLOCK_ID_CYCLE_29 (69U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_30
#   define NVM_BLOCK_ID_CYCLE_30 (70U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_31
#   define NVM_BLOCK_ID_CYCLE_31 (71U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_32
#   define NVM_BLOCK_ID_CYCLE_32 (72U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_33
#   define NVM_BLOCK_ID_CYCLE_33 (73U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_34
#   define NVM_BLOCK_ID_CYCLE_34 (74U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_35
#   define NVM_BLOCK_ID_CYCLE_35 (75U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_36
#   define NVM_BLOCK_ID_CYCLE_36 (76U)
#  endif

#  ifndef NVM_BLOCK_ID_CYCLE_37
#   define NVM_BLOCK_ID_CYCLE_37 (77U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_0
#   define NVM_BLOCK_ID_STEP_0 (78U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_1
#   define NVM_BLOCK_ID_STEP_1 (79U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_2
#   define NVM_BLOCK_ID_STEP_2 (80U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_3
#   define NVM_BLOCK_ID_STEP_3 (81U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_4
#   define NVM_BLOCK_ID_STEP_4 (82U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_5
#   define NVM_BLOCK_ID_STEP_5 (83U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_6
#   define NVM_BLOCK_ID_STEP_6 (84U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_7
#   define NVM_BLOCK_ID_STEP_7 (85U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_8
#   define NVM_BLOCK_ID_STEP_8 (86U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_9
#   define NVM_BLOCK_ID_STEP_9 (87U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_10
#   define NVM_BLOCK_ID_STEP_10 (88U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_11
#   define NVM_BLOCK_ID_STEP_11 (89U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_12
#   define NVM_BLOCK_ID_STEP_12 (90U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_13
#   define NVM_BLOCK_ID_STEP_13 (91U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_14
#   define NVM_BLOCK_ID_STEP_14 (92U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_15
#   define NVM_BLOCK_ID_STEP_15 (93U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_16
#   define NVM_BLOCK_ID_STEP_16 (94U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_17
#   define NVM_BLOCK_ID_STEP_17 (95U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_18
#   define NVM_BLOCK_ID_STEP_18 (96U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_19
#   define NVM_BLOCK_ID_STEP_19 (97U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_20
#   define NVM_BLOCK_ID_STEP_20 (98U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_21
#   define NVM_BLOCK_ID_STEP_21 (99U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_22
#   define NVM_BLOCK_ID_STEP_22 (100U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_23
#   define NVM_BLOCK_ID_STEP_23 (101U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_24
#   define NVM_BLOCK_ID_STEP_24 (102U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_25
#   define NVM_BLOCK_ID_STEP_25 (103U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_26
#   define NVM_BLOCK_ID_STEP_26 (104U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_27
#   define NVM_BLOCK_ID_STEP_27 (105U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_28
#   define NVM_BLOCK_ID_STEP_28 (106U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_29
#   define NVM_BLOCK_ID_STEP_29 (107U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_30
#   define NVM_BLOCK_ID_STEP_30 (108U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_31
#   define NVM_BLOCK_ID_STEP_31 (109U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_32
#   define NVM_BLOCK_ID_STEP_32 (110U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_33
#   define NVM_BLOCK_ID_STEP_33 (111U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_34
#   define NVM_BLOCK_ID_STEP_34 (112U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_35
#   define NVM_BLOCK_ID_STEP_35 (113U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_36
#   define NVM_BLOCK_ID_STEP_36 (114U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_37
#   define NVM_BLOCK_ID_STEP_37 (115U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_38
#   define NVM_BLOCK_ID_STEP_38 (116U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_39
#   define NVM_BLOCK_ID_STEP_39 (117U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_40
#   define NVM_BLOCK_ID_STEP_40 (118U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_41
#   define NVM_BLOCK_ID_STEP_41 (119U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_42
#   define NVM_BLOCK_ID_STEP_42 (120U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_43
#   define NVM_BLOCK_ID_STEP_43 (121U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_44
#   define NVM_BLOCK_ID_STEP_44 (122U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_45
#   define NVM_BLOCK_ID_STEP_45 (123U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_46
#   define NVM_BLOCK_ID_STEP_46 (124U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_47
#   define NVM_BLOCK_ID_STEP_47 (125U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_48
#   define NVM_BLOCK_ID_STEP_48 (126U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_49
#   define NVM_BLOCK_ID_STEP_49 (127U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_50
#   define NVM_BLOCK_ID_STEP_50 (128U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_51
#   define NVM_BLOCK_ID_STEP_51 (129U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_52
#   define NVM_BLOCK_ID_STEP_52 (130U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_53
#   define NVM_BLOCK_ID_STEP_53 (131U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_54
#   define NVM_BLOCK_ID_STEP_54 (132U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_55
#   define NVM_BLOCK_ID_STEP_55 (133U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_56
#   define NVM_BLOCK_ID_STEP_56 (134U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_57
#   define NVM_BLOCK_ID_STEP_57 (135U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_58
#   define NVM_BLOCK_ID_STEP_58 (136U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_59
#   define NVM_BLOCK_ID_STEP_59 (137U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_60
#   define NVM_BLOCK_ID_STEP_60 (138U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_61
#   define NVM_BLOCK_ID_STEP_61 (139U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_62
#   define NVM_BLOCK_ID_STEP_62 (140U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_63
#   define NVM_BLOCK_ID_STEP_63 (141U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_64
#   define NVM_BLOCK_ID_STEP_64 (142U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_65
#   define NVM_BLOCK_ID_STEP_65 (143U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_66
#   define NVM_BLOCK_ID_STEP_66 (144U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_67
#   define NVM_BLOCK_ID_STEP_67 (145U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_68
#   define NVM_BLOCK_ID_STEP_68 (146U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_69
#   define NVM_BLOCK_ID_STEP_69 (147U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_70
#   define NVM_BLOCK_ID_STEP_70 (148U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_71
#   define NVM_BLOCK_ID_STEP_71 (149U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_72
#   define NVM_BLOCK_ID_STEP_72 (150U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_73
#   define NVM_BLOCK_ID_STEP_73 (151U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_74
#   define NVM_BLOCK_ID_STEP_74 (152U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_75
#   define NVM_BLOCK_ID_STEP_75 (153U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_76
#   define NVM_BLOCK_ID_STEP_76 (154U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_77
#   define NVM_BLOCK_ID_STEP_77 (155U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_78
#   define NVM_BLOCK_ID_STEP_78 (156U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_79
#   define NVM_BLOCK_ID_STEP_79 (157U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_80
#   define NVM_BLOCK_ID_STEP_80 (158U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_81
#   define NVM_BLOCK_ID_STEP_81 (159U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_82
#   define NVM_BLOCK_ID_STEP_82 (160U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_83
#   define NVM_BLOCK_ID_STEP_83 (161U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_84
#   define NVM_BLOCK_ID_STEP_84 (162U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_85
#   define NVM_BLOCK_ID_STEP_85 (163U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_86
#   define NVM_BLOCK_ID_STEP_86 (164U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_87
#   define NVM_BLOCK_ID_STEP_87 (165U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_88
#   define NVM_BLOCK_ID_STEP_88 (166U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_89
#   define NVM_BLOCK_ID_STEP_89 (167U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_90
#   define NVM_BLOCK_ID_STEP_90 (168U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_91
#   define NVM_BLOCK_ID_STEP_91 (169U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_92
#   define NVM_BLOCK_ID_STEP_92 (170U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_93
#   define NVM_BLOCK_ID_STEP_93 (171U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_94
#   define NVM_BLOCK_ID_STEP_94 (172U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_95
#   define NVM_BLOCK_ID_STEP_95 (173U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_96
#   define NVM_BLOCK_ID_STEP_96 (174U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_97
#   define NVM_BLOCK_ID_STEP_97 (175U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_98
#   define NVM_BLOCK_ID_STEP_98 (176U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_99
#   define NVM_BLOCK_ID_STEP_99 (177U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_100
#   define NVM_BLOCK_ID_STEP_100 (178U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_101
#   define NVM_BLOCK_ID_STEP_101 (179U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_102
#   define NVM_BLOCK_ID_STEP_102 (180U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_103
#   define NVM_BLOCK_ID_STEP_103 (181U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_104
#   define NVM_BLOCK_ID_STEP_104 (182U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_105
#   define NVM_BLOCK_ID_STEP_105 (183U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_106
#   define NVM_BLOCK_ID_STEP_106 (184U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_107
#   define NVM_BLOCK_ID_STEP_107 (185U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_108
#   define NVM_BLOCK_ID_STEP_108 (186U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_109
#   define NVM_BLOCK_ID_STEP_109 (187U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_110
#   define NVM_BLOCK_ID_STEP_110 (188U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_111
#   define NVM_BLOCK_ID_STEP_111 (189U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_112
#   define NVM_BLOCK_ID_STEP_112 (190U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_113
#   define NVM_BLOCK_ID_STEP_113 (191U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_114
#   define NVM_BLOCK_ID_STEP_114 (192U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_115
#   define NVM_BLOCK_ID_STEP_115 (193U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_116
#   define NVM_BLOCK_ID_STEP_116 (194U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_117
#   define NVM_BLOCK_ID_STEP_117 (195U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_118
#   define NVM_BLOCK_ID_STEP_118 (196U)
#  endif

#  ifndef NVM_BLOCK_ID_STEP_119
#   define NVM_BLOCK_ID_STEP_119 (197U)
#  endif

#  ifndef NVM_BLOCK_ID_IN_POSITION_FACTOR
#   define NVM_BLOCK_ID_IN_POSITION_FACTOR (198U)
#  endif

#  ifndef NVM_BLOCK_ID_IDENTIFICATION
#   define NVM_BLOCK_ID_IDENTIFICATION (199U)
#  endif

#  ifndef NVM_BLOCK_ID_VELOCITY_CTRL_PARAM
#   define NVM_BLOCK_ID_VELOCITY_CTRL_PARAM (200U)
#  endif

#  ifndef NVM_BLOCK_CRC
#   define NVM_BLOCK_CRC (201U)
#  endif

#  ifndef NVM_BLOCK_TEMP_SENSOR_TABLE
#   define NVM_BLOCK_TEMP_SENSOR_TABLE (202U)
#  endif

#  ifndef NVM_BLOCK_ID_SFR_PARAM
#   define NVM_BLOCK_ID_SFR_PARAM (203U)
#  endif

#  ifndef NVM_BLOCK_ID_MAX_LIMIT
#   define NVM_BLOCK_ID_MAX_LIMIT (204U)
#  endif

#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif

#  ifndef NVM_REQ_OK_BLK_INCREASED
#   define NVM_REQ_OK_BLK_INCREASED (9U)
#  endif

#  ifndef NVM_REQ_OK_BLK_DECREASED
#   define NVM_REQ_OK_BLK_DECREASED (10U)
#  endif

#  define b8AlgorithmFlagsStatusType_Appl_LowerLimit (0U)
#  define b8AlgorithmFlagsStatusType_Appl_UpperLimit (255U)

#  ifndef KB8_ALGO_FLAG_OFF
#   define KB8_ALGO_FLAG_OFF (85U)
#  endif

#  ifndef KB8_ALGO_FLAG_ON
#   define KB8_ALGO_FLAG_ON (170U)
#  endif

#  define b8BooleanType_Appl_LowerLimit (0U)
#  define b8BooleanType_Appl_UpperLimit (255U)

#  ifndef KU8_FALSE
#   define KU8_FALSE (85U)
#  endif

#  ifndef KU8_TRUE
#   define KU8_TRUE (170U)
#  endif

#  define b8IsCarAccelerationLowType_Appl_LowerLimit (0U)
#  define b8IsCarAccelerationLowType_Appl_UpperLimit (255U)

#  ifndef KU8_FALSE
#   define KU8_FALSE (85U)
#  endif

#  ifndef KU8_TRUE
#   define KU8_TRUE (170U)
#  endif

#  define b8IsCarCrankingActiveType_Appl_LowerLimit (0U)
#  define b8IsCarCrankingActiveType_Appl_UpperLimit (255U)

#  ifndef KU8_FALSE
#   define KU8_FALSE (85U)
#  endif

#  ifndef KU8_TRUE
#   define KU8_TRUE (170U)
#  endif

#  define b8IsCarCrashDetectedType_Appl_LowerLimit (0U)
#  define b8IsCarCrashDetectedType_Appl_UpperLimit (255U)

#  ifndef KU8_FALSE
#   define KU8_FALSE (85U)
#  endif

#  ifndef KU8_TRUE
#   define KU8_TRUE (170U)
#  endif

#  define b8PyroActivationStatusType_Appl_LowerLimit (0U)
#  define b8PyroActivationStatusType_Appl_UpperLimit (255U)

#  ifndef KB8_PYRO_DEVICE_NOT_ACTIVATED
#   define KB8_PYRO_DEVICE_NOT_ACTIVATED (85U)
#  endif

#  ifndef KB8_PYRO_DEVICE_ACTIVATED
#   define KB8_PYRO_DEVICE_ACTIVATED (170U)
#  endif

#  define c02_Bckl_Sw_Stat_LowerLimit (0U)
#  define c02_Bckl_Sw_Stat_UpperLimit (3U)

#  define InvalidValue_c02_Bckl_Sw_Stat (3U)

#  ifndef I_C02_BCKL_SW_STAT_OK
#   define I_C02_BCKL_SW_STAT_OK (0U)
#  endif

#  ifndef I_C02_BCKL_SW_STAT_NOT
#   define I_C02_BCKL_SW_STAT_NOT (1U)
#  endif

#  ifndef I_C02_BCKL_SW_STAT_FLT
#   define I_C02_BCKL_SW_STAT_FLT (2U)
#  endif

#  ifndef I_C02_BCKL_SW_STAT_SNA
#   define I_C02_BCKL_SW_STAT_SNA (3U)
#  endif

#  define c02_BeltHdOvr_Stat_LowerLimit (0U)
#  define c02_BeltHdOvr_Stat_UpperLimit (3U)

#  define InvalidValue_c02_BeltHdOvr_Stat (3U)

#  ifndef I_C02_BELTHDOVR_STAT_RETRACT
#   define I_C02_BELTHDOVR_STAT_RETRACT (0U)
#  endif

#  ifndef I_C02_BELTHDOVR_STAT_OUT_OF_END
#   define I_C02_BELTHDOVR_STAT_OUT_OF_END (1U)
#  endif

#  ifndef I_C02_BELTHDOVR_STAT_EXTEND
#   define I_C02_BELTHDOVR_STAT_EXTEND (2U)
#  endif

#  ifndef I_C02_BELTHDOVR_STAT_SNA
#   define I_C02_BELTHDOVR_STAT_SNA (3U)
#  endif

#  define c02_EVC_Stat_LowerLimit (1U)
#  define c02_EVC_Stat_UpperLimit (3U)

#  define InvalidValue_c02_EVC_Stat (3U)

#  ifndef I_C02_EVC_STAT_PROG
#   define I_C02_EVC_STAT_PROG (1U)
#  endif

#  ifndef I_C02_EVC_STAT_REQ
#   define I_C02_EVC_STAT_REQ (2U)
#  endif

#  ifndef I_C02_EVC_STAT_SNA
#   define I_C02_EVC_STAT_SNA (3U)
#  endif

#  define c02_Ndef_False_True_ST3_LowerLimit (1U)
#  define c02_Ndef_False_True_ST3_UpperLimit (3U)

#  define InvalidValue_c02_Ndef_False_True_ST3 (3U)

#  ifndef I_C02_NDEF_FALSE_TRUE_ST3_FALSE
#   define I_C02_NDEF_FALSE_TRUE_ST3_FALSE (1U)
#  endif

#  ifndef I_C02_NDEF_FALSE_TRUE_ST3_TRUE
#   define I_C02_NDEF_FALSE_TRUE_ST3_TRUE (2U)
#  endif

#  ifndef I_C02_NDEF_FALSE_TRUE_ST3_SNA
#   define I_C02_NDEF_FALSE_TRUE_ST3_SNA (3U)
#  endif

#  define c02_PT_Rdy_V2_LowerLimit (0U)
#  define c02_PT_Rdy_V2_UpperLimit (3U)

#  define InvalidValue_c02_PT_Rdy_V2 (3U)

#  ifndef I_C02_PT_RDY_V2_PT_NOT_RDY
#   define I_C02_PT_RDY_V2_PT_NOT_RDY (0U)
#  endif

#  ifndef I_C02_PT_RDY_V2_PT_RDY
#   define I_C02_PT_RDY_V2_PT_RDY (1U)
#  endif

#  ifndef I_C02_PT_RDY_V2_SNA
#   define I_C02_PT_RDY_V2_SNA (3U)
#  endif

#  define c02_Presf_Snd_LowerLimit (0U)
#  define c02_Presf_Snd_UpperLimit (3U)

#  define InvalidValue_c02_Presf_Snd (3U)

#  ifndef I_C02_PRESF_SND_IDLE
#   define I_C02_PRESF_SND_IDLE (0U)
#  endif

#  ifndef I_C02_PRESF_SND_PINK_NOISE1
#   define I_C02_PRESF_SND_PINK_NOISE1 (1U)
#  endif

#  ifndef I_C02_PRESF_SND_PINK_NOISE2
#   define I_C02_PRESF_SND_PINK_NOISE2 (2U)
#  endif

#  ifndef I_C02_PRESF_SND_SNA
#   define I_C02_PRESF_SND_SNA (3U)
#  endif

#  define c02_StStyle_LowerLimit (1U)
#  define c02_StStyle_UpperLimit (3U)

#  define InvalidValue_c02_StStyle (3U)

#  ifndef I_C02_STSTYLE_LHD
#   define I_C02_STSTYLE_LHD (1U)
#  endif

#  ifndef I_C02_STSTYLE_RHD
#   define I_C02_STSTYLE_RHD (2U)
#  endif

#  ifndef I_C02_STSTYLE_SNA
#   define I_C02_STSTYLE_SNA (3U)
#  endif

#  define c02_TransMd_Stat_LowerLimit (0U)
#  define c02_TransMd_Stat_UpperLimit (3U)

#  define InvalidValue_c02_TransMd_Stat (3U)

#  ifndef I_C02_TRANSMD_STAT_OFF
#   define I_C02_TRANSMD_STAT_OFF (0U)
#  endif

#  ifndef I_C02_TRANSMD_STAT_TEMP_OFF
#   define I_C02_TRANSMD_STAT_TEMP_OFF (1U)
#  endif

#  ifndef I_C02_TRANSMD_STAT_ACTV
#   define I_C02_TRANSMD_STAT_ACTV (2U)
#  endif

#  ifndef I_C02_TRANSMD_STAT_SNA
#   define I_C02_TRANSMD_STAT_SNA (3U)
#  endif

#  define c02_false_true_sna_LowerLimit (0U)
#  define c02_false_true_sna_UpperLimit (3U)

#  define InvalidValue_c02_false_true_sna (3U)

#  ifndef I_C02_FALSE_TRUE_SNA_FALSE
#   define I_C02_FALSE_TRUE_SNA_FALSE (0U)
#  endif

#  ifndef I_C02_FALSE_TRUE_SNA_TRUE
#   define I_C02_FALSE_TRUE_SNA_TRUE (1U)
#  endif

#  ifndef I_C02_FALSE_TRUE_SNA_SNA
#   define I_C02_FALSE_TRUE_SNA_SNA (3U)
#  endif

#  define c03_EngStartPN14_Stat_LowerLimit (0U)
#  define c03_EngStartPN14_Stat_UpperLimit (7U)

#  define InvalidValue_c03_EngStartPN14_Stat (7U)

#  ifndef I_C03_ENGSTARTPN14_STAT_NO_COMBUSTIONSTART_RQ
#   define I_C03_ENGSTARTPN14_STAT_NO_COMBUSTIONSTART_RQ (0U)
#  endif

#  ifndef I_C03_ENGSTARTPN14_STAT_CUSTOMER_START_RQ
#   define I_C03_ENGSTARTPN14_STAT_CUSTOMER_START_RQ (1U)
#  endif

#  ifndef I_C03_ENGSTARTPN14_STAT_AUTO_START_NO_PN_SUP_RQ
#   define I_C03_ENGSTARTPN14_STAT_AUTO_START_NO_PN_SUP_RQ (2U)
#  endif

#  ifndef I_C03_ENGSTARTPN14_STAT_AUTO_START_PN_SUP_RQ
#   define I_C03_ENGSTARTPN14_STAT_AUTO_START_PN_SUP_RQ (3U)
#  endif

#  ifndef I_C03_ENGSTARTPN14_STAT_SNA
#   define I_C03_ENGSTARTPN14_STAT_SNA (7U)
#  endif

#  define c03_ISw_Stat_LowerLimit (0U)
#  define c03_ISw_Stat_UpperLimit (7U)

#  define InvalidValue_c03_ISw_Stat (7U)

#  ifndef I_C03_ISW_STAT_IGN_LOCK
#   define I_C03_ISW_STAT_IGN_LOCK (0U)
#  endif

#  ifndef I_C03_ISW_STAT_IGN_OFF
#   define I_C03_ISW_STAT_IGN_OFF (1U)
#  endif

#  ifndef I_C03_ISW_STAT_IGN_ACC
#   define I_C03_ISW_STAT_IGN_ACC (2U)
#  endif

#  ifndef I_C03_ISW_STAT_IGN_ON
#   define I_C03_ISW_STAT_IGN_ON (4U)
#  endif

#  ifndef I_C03_ISW_STAT_IGN_START
#   define I_C03_ISW_STAT_IGN_START (5U)
#  endif

#  ifndef I_C03_ISW_STAT_SNA
#   define I_C03_ISW_STAT_SNA (7U)
#  endif

#  define c03_No_Lt_Rt_Both_LowerLimit (0U)
#  define c03_No_Lt_Rt_Both_UpperLimit (7U)

#  define InvalidValue_c03_No_Lt_Rt_Both (7U)

#  ifndef I_C03_NO_LT_RT_BOTH_NO
#   define I_C03_NO_LT_RT_BOTH_NO (0U)
#  endif

#  ifndef I_C03_NO_LT_RT_BOTH_LEFT
#   define I_C03_NO_LT_RT_BOTH_LEFT (1U)
#  endif

#  ifndef I_C03_NO_LT_RT_BOTH_RIGHT
#   define I_C03_NO_LT_RT_BOTH_RIGHT (2U)
#  endif

#  ifndef I_C03_NO_LT_RT_BOTH_BOTH
#   define I_C03_NO_LT_RT_BOTH_BOTH (3U)
#  endif

#  ifndef I_C03_NO_LT_RT_BOTH_SNA
#   define I_C03_NO_LT_RT_BOTH_SNA (7U)
#  endif

#  define c03_PN14_ProdMd_Stat_ST3_LowerLimit (0U)
#  define c03_PN14_ProdMd_Stat_ST3_UpperLimit (7U)

#  define InvalidValue_c03_PN14_ProdMd_Stat_ST3 (7U)

#  ifndef I_C03_PN14_PRODMD_STAT_ST3_OFF
#   define I_C03_PN14_PRODMD_STAT_ST3_OFF (0U)
#  endif

#  ifndef I_C03_PN14_PRODMD_STAT_ST3_ON
#   define I_C03_PN14_PRODMD_STAT_ST3_ON (1U)
#  endif

#  ifndef I_C03_PN14_PRODMD_STAT_ST3_SF01
#   define I_C03_PN14_PRODMD_STAT_ST3_SF01 (2U)
#  endif

#  ifndef I_C03_PN14_PRODMD_STAT_ST3_SF02
#   define I_C03_PN14_PRODMD_STAT_ST3_SF02 (3U)
#  endif

#  ifndef I_C03_PN14_PRODMD_STAT_ST3_SF03
#   define I_C03_PN14_PRODMD_STAT_ST3_SF03 (4U)
#  endif

#  ifndef I_C03_PN14_PRODMD_STAT_ST3_SNA
#   define I_C03_PN14_PRODMD_STAT_ST3_SNA (7U)
#  endif

#  define c03_PN14_TDP_Sw_Stat_LowerLimit (0U)
#  define c03_PN14_TDP_Sw_Stat_UpperLimit (7U)

#  define InvalidValue_c03_PN14_TDP_Sw_Stat (7U)

#  ifndef I_C03_PN14_TDP_SW_STAT_CLS
#   define I_C03_PN14_TDP_SW_STAT_CLS (0U)
#  endif

#  ifndef I_C03_PN14_TDP_SW_STAT_PRE_RESET
#   define I_C03_PN14_TDP_SW_STAT_PRE_RESET (1U)
#  endif

#  ifndef I_C03_PN14_TDP_SW_STAT_RESET
#   define I_C03_PN14_TDP_SW_STAT_RESET (2U)
#  endif

#  ifndef I_C03_PN14_TDP_SW_STAT_PRE_OPN
#   define I_C03_PN14_TDP_SW_STAT_PRE_OPN (3U)
#  endif

#  ifndef I_C03_PN14_TDP_SW_STAT_OPN
#   define I_C03_PN14_TDP_SW_STAT_OPN (4U)
#  endif

#  ifndef I_C03_PN14_TDP_SW_STAT_SNA
#   define I_C03_PN14_TDP_SW_STAT_SNA (7U)
#  endif

#  define c04_DrvPosn_ST3_LowerLimit (1U)
#  define c04_DrvPosn_ST3_UpperLimit (15U)

#  define InvalidValue_c04_DrvPosn_ST3 (15U)

#  ifndef I_C04_DRVPOSN_ST3_D
#   define I_C04_DRVPOSN_ST3_D (1U)
#  endif

#  ifndef I_C04_DRVPOSN_ST3_N
#   define I_C04_DRVPOSN_ST3_N (2U)
#  endif

#  ifndef I_C04_DRVPOSN_ST3_R
#   define I_C04_DRVPOSN_ST3_R (3U)
#  endif

#  ifndef I_C04_DRVPOSN_ST3_P
#   define I_C04_DRVPOSN_ST3_P (4U)
#  endif

#  ifndef I_C04_DRVPOSN_ST3_SNA
#   define I_C04_DRVPOSN_ST3_SNA (15U)
#  endif

#  define c04_Presf_Frct_ST3_LowerLimit (0U)
#  define c04_Presf_Frct_ST3_UpperLimit (15U)

#  define InvalidValue_c04_Presf_Frct_ST3 (15U)

#  ifndef I_C04_PRESF_FRCT_ST3_FRICT_0D0
#   define I_C04_PRESF_FRCT_ST3_FRICT_0D0 (0U)
#  endif

#  ifndef I_C04_PRESF_FRCT_ST3_FRICT_0D1
#   define I_C04_PRESF_FRCT_ST3_FRICT_0D1 (1U)
#  endif

#  ifndef I_C04_PRESF_FRCT_ST3_FRICT_0D2
#   define I_C04_PRESF_FRCT_ST3_FRICT_0D2 (2U)
#  endif

#  ifndef I_C04_PRESF_FRCT_ST3_FRICT_0D3
#   define I_C04_PRESF_FRCT_ST3_FRICT_0D3 (3U)
#  endif

#  ifndef I_C04_PRESF_FRCT_ST3_FRICT_0D4
#   define I_C04_PRESF_FRCT_ST3_FRICT_0D4 (4U)
#  endif

#  ifndef I_C04_PRESF_FRCT_ST3_FRICT_0D5
#   define I_C04_PRESF_FRCT_ST3_FRICT_0D5 (5U)
#  endif

#  ifndef I_C04_PRESF_FRCT_ST3_FRICT_0D6
#   define I_C04_PRESF_FRCT_ST3_FRICT_0D6 (6U)
#  endif

#  ifndef I_C04_PRESF_FRCT_ST3_FRICT_0D7
#   define I_C04_PRESF_FRCT_ST3_FRICT_0D7 (7U)
#  endif

#  ifndef I_C04_PRESF_FRCT_ST3_FRICT_0D8
#   define I_C04_PRESF_FRCT_ST3_FRICT_0D8 (8U)
#  endif

#  ifndef I_C04_PRESF_FRCT_ST3_FRICT_0D9
#   define I_C04_PRESF_FRCT_ST3_FRICT_0D9 (9U)
#  endif

#  ifndef I_C04_PRESF_FRCT_ST3_FRICT_1D0
#   define I_C04_PRESF_FRCT_ST3_FRICT_1D0 (10U)
#  endif

#  ifndef I_C04_PRESF_FRCT_ST3_SNA
#   define I_C04_PRESF_FRCT_ST3_SNA (15U)
#  endif

#  define c04_Presf_Lvl_V2_LowerLimit (0U)
#  define c04_Presf_Lvl_V2_UpperLimit (15U)

#  define InvalidValue_c04_Presf_Lvl_V2 (15U)

#  ifndef I_C04_PRESF_LVL_V2_NOLVL
#   define I_C04_PRESF_LVL_V2_NOLVL (0U)
#  endif

#  ifndef I_C04_PRESF_LVL_V2_LVL1
#   define I_C04_PRESF_LVL_V2_LVL1 (1U)
#  endif

#  ifndef I_C04_PRESF_LVL_V2_LVL2
#   define I_C04_PRESF_LVL_V2_LVL2 (2U)
#  endif

#  ifndef I_C04_PRESF_LVL_V2_LVL3
#   define I_C04_PRESF_LVL_V2_LVL3 (3U)
#  endif

#  ifndef I_C04_PRESF_LVL_V2_LVL4
#   define I_C04_PRESF_LVL_V2_LVL4 (4U)
#  endif

#  ifndef I_C04_PRESF_LVL_V2_LVL5
#   define I_C04_PRESF_LVL_V2_LVL5 (5U)
#  endif

#  ifndef I_C04_PRESF_LVL_V2_LVL6
#   define I_C04_PRESF_LVL_V2_LVL6 (6U)
#  endif

#  ifndef I_C04_PRESF_LVL_V2_LVL7
#   define I_C04_PRESF_LVL_V2_LVL7 (7U)
#  endif

#  ifndef I_C04_PRESF_LVL_V2_LVL8
#   define I_C04_PRESF_LVL_V2_LVL8 (8U)
#  endif

#  ifndef I_C04_PRESF_LVL_V2_SNA
#   define I_C04_PRESF_LVL_V2_SNA (15U)
#  endif

#  define c04_VehOpMode_LowerLimit (0U)
#  define c04_VehOpMode_UpperLimit (15U)

#  define InvalidValue_c04_VehOpMode (15U)

#  ifndef I_C04_VEHOPMODE_DRV
#   define I_C04_VEHOPMODE_DRV (0U)
#  endif

#  ifndef I_C04_VEHOPMODE_DIAG
#   define I_C04_VEHOPMODE_DIAG (1U)
#  endif

#  ifndef I_C04_VEHOPMODE_REMSTART_PRECON
#   define I_C04_VEHOPMODE_REMSTART_PRECON (2U)
#  endif

#  ifndef I_C04_VEHOPMODE_ENG_RUN_CONT
#   define I_C04_VEHOPMODE_ENG_RUN_CONT (3U)
#  endif

#  ifndef I_C04_VEHOPMODE_KEY_PARK
#   define I_C04_VEHOPMODE_KEY_PARK (4U)
#  endif

#  ifndef I_C04_VEHOPMODE_REMSTART_BAT_CHRG
#   define I_C04_VEHOPMODE_REMSTART_BAT_CHRG (5U)
#  endif

#  ifndef I_C04_VEHOPMODE_AVP
#   define I_C04_VEHOPMODE_AVP (6U)
#  endif

#  ifndef I_C04_VEHOPMODE_SDC
#   define I_C04_VEHOPMODE_SDC (7U)
#  endif

#  ifndef I_C04_VEHOPMODE_ADSE
#   define I_C04_VEHOPMODE_ADSE (8U)
#  endif

#  ifndef I_C04_VEHOPMODE_SNA
#   define I_C04_VEHOPMODE_SNA (15U)
#  endif

#  define c06_RBTM_LVL_Rq_LowerLimit (0U)
#  define c06_RBTM_LVL_Rq_UpperLimit (63U)

#  define InvalidValue_c06_RBTM_LVL_Rq (63U)

#  ifndef I_C06_RBTM_LVL_RQ_NONE
#   define I_C06_RBTM_LVL_RQ_NONE (0U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE1
#   define I_C06_RBTM_LVL_RQ_PROFILE1 (1U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE2
#   define I_C06_RBTM_LVL_RQ_PROFILE2 (2U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE3
#   define I_C06_RBTM_LVL_RQ_PROFILE3 (3U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE4
#   define I_C06_RBTM_LVL_RQ_PROFILE4 (4U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE5
#   define I_C06_RBTM_LVL_RQ_PROFILE5 (5U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE6
#   define I_C06_RBTM_LVL_RQ_PROFILE6 (6U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE7
#   define I_C06_RBTM_LVL_RQ_PROFILE7 (7U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE8
#   define I_C06_RBTM_LVL_RQ_PROFILE8 (8U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE9
#   define I_C06_RBTM_LVL_RQ_PROFILE9 (9U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE10
#   define I_C06_RBTM_LVL_RQ_PROFILE10 (10U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE11
#   define I_C06_RBTM_LVL_RQ_PROFILE11 (11U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE12
#   define I_C06_RBTM_LVL_RQ_PROFILE12 (12U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE13
#   define I_C06_RBTM_LVL_RQ_PROFILE13 (13U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE14
#   define I_C06_RBTM_LVL_RQ_PROFILE14 (14U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE15
#   define I_C06_RBTM_LVL_RQ_PROFILE15 (15U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE16
#   define I_C06_RBTM_LVL_RQ_PROFILE16 (16U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE17
#   define I_C06_RBTM_LVL_RQ_PROFILE17 (17U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE18
#   define I_C06_RBTM_LVL_RQ_PROFILE18 (18U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE19
#   define I_C06_RBTM_LVL_RQ_PROFILE19 (19U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE20
#   define I_C06_RBTM_LVL_RQ_PROFILE20 (20U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE21
#   define I_C06_RBTM_LVL_RQ_PROFILE21 (21U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE22
#   define I_C06_RBTM_LVL_RQ_PROFILE22 (22U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE23
#   define I_C06_RBTM_LVL_RQ_PROFILE23 (23U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE24
#   define I_C06_RBTM_LVL_RQ_PROFILE24 (24U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_PROFILE25
#   define I_C06_RBTM_LVL_RQ_PROFILE25 (25U)
#  endif

#  ifndef I_C06_RBTM_LVL_RQ_SNA
#   define I_C06_RBTM_LVL_RQ_SNA (63U)
#  endif

#  define c10_V_0_25k55_0k025_LowerLimit (0U)
#  define c10_V_0_25k55_0k025_UpperLimit (1023U)

#  define InvalidValue_c10_V_0_25k55_0k025 (1023U)

#  ifndef I_C10_V_0_25K55_0K025_SNA
#   define I_C10_V_0_25K55_0K025_SNA (1023U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_FALSE
#   define c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_FALSE (0U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_BflMask
#   define c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_BflMask 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_BflPn
#   define c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_BflPn 0U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_BflLn
#   define c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_BflLn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_TRUE
#   define c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_TRUE (1U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_FALSE
#   define c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_FALSE (0U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_BflMask
#   define c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_BflMask 2U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_BflPn
#   define c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_BflPn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_BflLn
#   define c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_BflLn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_TRUE
#   define c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_TRUE (2U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_FALSE
#   define c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_FALSE (0U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_BflMask
#   define c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_BflMask 4U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_BflPn
#   define c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_BflPn 2U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_BflLn
#   define c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_BflLn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_TRUE
#   define c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_TRUE (4U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_FALSE
#   define c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_FALSE (0U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_BflMask
#   define c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_BflMask 8U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_BflPn
#   define c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_BflPn 3U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_BflLn
#   define c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_BflLn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_TRUE
#   define c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_TRUE (8U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_FALSE
#   define c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_FALSE (0U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_BflMask
#   define c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_BflMask 16U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_BflPn
#   define c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_BflPn 4U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_BflLn
#   define c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_BflLn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_TRUE
#   define c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_TRUE (16U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_FALSE
#   define c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_FALSE (0U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_BflMask
#   define c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_BflMask 32U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_BflPn
#   define c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_BflPn 5U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_BflLn
#   define c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_BflLn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_TRUE
#   define c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_TRUE (32U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_FALSE
#   define c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_FALSE (0U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_BflMask
#   define c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_BflMask 64U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_BflPn
#   define c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_BflPn 6U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_BflLn
#   define c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_BflLn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_TRUE
#   define c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_TRUE (64U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_FALSE
#   define c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_FALSE (0U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_BflMask
#   define c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_BflMask 128U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_BflPn
#   define c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_BflPn 7U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_BflLn
#   define c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_BflLn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_TRUE
#   define c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_TRUE (128U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_FALSE
#   define c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_FALSE (0U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_BflMask
#   define c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_BflMask 256U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_BflPn
#   define c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_BflPn 8U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_BflLn
#   define c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_BflLn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_TRUE
#   define c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_TRUE (256U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_FALSE
#   define c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_FALSE (0U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_BflMask
#   define c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_BflMask 512U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_BflPn
#   define c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_BflPn 9U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_BflLn
#   define c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_BflLn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_TRUE
#   define c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_TRUE (512U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_FALSE
#   define c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_FALSE (0U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_BflMask
#   define c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_BflMask 1024U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_BflPn
#   define c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_BflPn 10U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_BflLn
#   define c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_BflLn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_TRUE
#   define c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_TRUE (1024U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_FALSE
#   define c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_FALSE (0U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_BflMask
#   define c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_BflMask 2048U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_BflPn
#   define c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_BflPn 11U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_BflLn
#   define c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_BflLn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_TRUE
#   define c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_TRUE (2048U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_FALSE
#   define c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_FALSE (0U)
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_BflMask
#   define c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_BflMask 4096U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_BflPn
#   define c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_BflPn 12U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_BflLn
#   define c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_BflLn 1U
#  endif

#  ifndef c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_TRUE
#   define c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_TRUE (4096U)
#  endif

#  ifndef CALIB_BLOCK_ID_EOL_PARAM
#   define CALIB_BLOCK_ID_EOL_PARAM (0U)
#  endif

#  ifndef CALIB_BLOCK_ID_BFS_PRIO_PARAM
#   define CALIB_BLOCK_ID_BFS_PRIO_PARAM (1U)
#  endif

#  ifndef CALIB_BLOCK_ID_PID_PARAM
#   define CALIB_BLOCK_ID_PID_PARAM (2U)
#  endif

#  ifndef CALIB_BLOCK_ID_WEIGHT_REL_TABLE
#   define CALIB_BLOCK_ID_WEIGHT_REL_TABLE (3U)
#  endif

#  ifndef CALIB_BLOCK_ID_WEIGHT_TENS0_TABLE
#   define CALIB_BLOCK_ID_WEIGHT_TENS0_TABLE (4U)
#  endif

#  ifndef CALIB_BLOCK_ID_WEIGHT_TENS1_TABLE
#   define CALIB_BLOCK_ID_WEIGHT_TENS1_TABLE (5U)
#  endif

#  ifndef CALIB_BLOCK_ID_WEIGHT_TENS2_TABLE
#   define CALIB_BLOCK_ID_WEIGHT_TENS2_TABLE (6U)
#  endif

#  ifndef CALIB_BLOCK_ID_WEIGHT_TENS3_TABLE
#   define CALIB_BLOCK_ID_WEIGHT_TENS3_TABLE (7U)
#  endif

#  ifndef CALIB_BLOCK_ID_INT_CURRENT_CORR
#   define CALIB_BLOCK_ID_INT_CURRENT_CORR (8U)
#  endif

#  ifndef CALIB_BLOCK_ID_INT_CURRENT_TABLE
#   define CALIB_BLOCK_ID_INT_CURRENT_TABLE (9U)
#  endif

#  ifndef CALIB_BLOCK_ID_POWER_DEGRADATION
#   define CALIB_BLOCK_ID_POWER_DEGRADATION (10U)
#  endif

#  ifndef CALIB_BLOCK_ID_ECPL_ALPHA_TABLE
#   define CALIB_BLOCK_ID_ECPL_ALPHA_TABLE (11U)
#  endif

#  ifndef CALIB_BLOCK_ID_ECPL_BETA_TABLE
#   define CALIB_BLOCK_ID_ECPL_BETA_TABLE (12U)
#  endif

#  ifndef CALIB_BLOCK_ID_ECPL_OTHER_PARAM
#   define CALIB_BLOCK_ID_ECPL_OTHER_PARAM (13U)
#  endif

#  ifndef CALIB_BLOCK_ID_BPA_MOTOR_CURRENT
#   define CALIB_BLOCK_ID_BPA_MOTOR_CURRENT (14U)
#  endif

#  ifndef CALIB_BLOCK_ID_VOLT_THRS
#   define CALIB_BLOCK_ID_VOLT_THRS (15U)
#  endif

#  ifndef CALIB_BLOCK_ID_BATTERY_LOSS_DETECTION_THRS
#   define CALIB_BLOCK_ID_BATTERY_LOSS_DETECTION_THRS (16U)
#  endif

#  ifndef CALIB_BLOCK_ID_BOOST
#   define CALIB_BLOCK_ID_BOOST (17U)
#  endif

#  ifndef CALIB_BLOCK_ID_ECU_PROPERTIES
#   define CALIB_BLOCK_ID_ECU_PROPERTIES (18U)
#  endif

#  ifndef CALIB_BLOCK_ID_SW_SELF_PROTECTION_THRS
#   define CALIB_BLOCK_ID_SW_SELF_PROTECTION_THRS (19U)
#  endif

#  ifndef CALIB_BLOCK_ID_MOTOR_RESIST_PARAM
#   define CALIB_BLOCK_ID_MOTOR_RESIST_PARAM (20U)
#  endif

#  ifndef CALIB_BLOCK_ID_BOOST_ACTIVATION
#   define CALIB_BLOCK_ID_BOOST_ACTIVATION (21U)
#  endif

#  ifndef CALIB_BLOCK_ID_MAX_LIMIT
#   define CALIB_BLOCK_ID_MAX_LIMIT (22U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_HARDWARE
#   define KU32_AEC_GROUP_MASK_HARDWARE (1U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_MOTOR
#   define KU32_AEC_GROUP_MASK_MOTOR (2U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_OVER_VO
#   define KU32_AEC_GROUP_MASK_OVER_VO (4U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_UNDER_VO
#   define KU32_AEC_GROUP_MASK_UNDER_VO (8U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_OVER_VO_TENS
#   define KU32_AEC_GROUP_MASK_OVER_VO_TENS (16U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_UNDER_VO_TENS
#   define KU32_AEC_GROUP_MASK_UNDER_VO_TENS (32U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_NVM
#   define KU32_AEC_GROUP_MASK_NVM (64U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_EOL_LOW_HIGH
#   define KU32_AEC_GROUP_MASK_EOL_LOW_HIGH (128U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_EOL_COMFORT
#   define KU32_AEC_GROUP_MASK_EOL_COMFORT (256U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_EOL_MAX
#   define KU32_AEC_GROUP_MASK_EOL_MAX (512U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_WARM_RESET
#   define KU32_AEC_GROUP_MASK_WARM_RESET (1024U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_SELF_PROTECTION
#   define KU32_AEC_GROUP_MASK_SELF_PROTECTION (2048U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_TIMEOUT_PRESAFE
#   define KU32_AEC_GROUP_MASK_TIMEOUT_PRESAFE (4096U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_TIMEOUT_BUCKLE
#   define KU32_AEC_GROUP_MASK_TIMEOUT_BUCKLE (8192U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_PRESAFE
#   define KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_PRESAFE (16384U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_IGNITION
#   define KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_IGNITION (32768U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_BUCKLE_ORC
#   define KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_BUCKLE_ORC (65536U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_POWERTRAIN
#   define KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_POWERTRAIN (131072U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_TIMEOUT_IGNITION
#   define KU32_AEC_GROUP_MASK_TIMEOUT_IGNITION (262144U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_TIMEOUT_API
#   define KU32_AEC_GROUP_MASK_TIMEOUT_API (524288U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_TIMEOUT_BH_R
#   define KU32_AEC_GROUP_MASK_TIMEOUT_BH_R (1048576U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_TIMEOUT_BH_L
#   define KU32_AEC_GROUP_MASK_TIMEOUT_BH_L (2097152U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_TIMEOUT_POWERTRAIN
#   define KU32_AEC_GROUP_MASK_TIMEOUT_POWERTRAIN (4194304U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_STEERING_CONFIG
#   define KU32_AEC_GROUP_MASK_STEERING_CONFIG (8388608U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_SYSTEM_OV
#   define KU32_AEC_GROUP_MASK_SYSTEM_OV (16777216U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_SYSTEM_UV
#   define KU32_AEC_GROUP_MASK_SYSTEM_UV (33554432U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_ODOSEEPDOMETER
#   define KU32_AEC_GROUP_MASK_ODOSEEPDOMETER (67108864U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_API
#   define KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_API (134217728U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_VARIANT_CODING
#   define KU32_AEC_GROUP_MASK_VARIANT_CODING (268435456U)
#  endif

#  ifndef KU32_AEC_GROUP_MASK_MAX_COUNTER
#   define KU32_AEC_GROUP_MASK_MAX_COUNTER (536870912U)
#  endif

#  define u32ModeMaskType_Appl_LowerLimit (0U)
#  define u32ModeMaskType_Appl_UpperLimit (4294967295U)

#  ifndef KU32_MASK_NO_MODE
#   define KU32_MASK_NO_MODE (0U)
#  endif

#  ifndef MMG_KU32_MASK_EOL_LOW_FORCE
#   define MMG_KU32_MASK_EOL_LOW_FORCE (16U)
#  endif

#  ifndef MMG_KU32_MASK_AEC_ECU_DEFECT_ALL_CYCLES
#   define MMG_KU32_MASK_AEC_ECU_DEFECT_ALL_CYCLES (32U)
#  endif

#  ifndef MMG_KU32_MASK_EOL_COMFORT
#   define MMG_KU32_MASK_EOL_COMFORT (64U)
#  endif

#  ifndef MMG_KU32_MASK_ENABLE_IGNITION_ON
#   define MMG_KU32_MASK_ENABLE_IGNITION_ON (128U)
#  endif

#  ifndef MMG_KU32_MASK_ENABLE_CODING_API
#   define MMG_KU32_MASK_ENABLE_CODING_API (256U)
#  endif

#  ifndef MMG_KU32_MASK_BELTFUNCTIONS_DELAY_UV
#   define MMG_KU32_MASK_BELTFUNCTIONS_DELAY_UV (262144U)
#  endif

#  ifndef MMG_KU32_MASK_BELTFUNCTIONS
#   define MMG_KU32_MASK_BELTFUNCTIONS (524288U)
#  endif

#  ifndef MMG_KU32_MASK_ENABLE_CODING_BLT
#   define MMG_KU32_MASK_ENABLE_CODING_BLT (1048576U)
#  endif

#  ifndef MMG_KU32_MASK_AEC_INHIB_TENSIONING_CYCLES
#   define MMG_KU32_MASK_AEC_INHIB_TENSIONING_CYCLES (2097152U)
#  endif

#  ifndef MMG_KU32_MASK_AEC_INHIB_ALL_CYCLES
#   define MMG_KU32_MASK_AEC_INHIB_ALL_CYCLES (4194304U)
#  endif

#  ifndef MMG_KU32_MASK_NO_HALL_EFFECT_SENSOR
#   define MMG_KU32_MASK_NO_HALL_EFFECT_SENSOR (16777216U)
#  endif

#  ifndef MMG_KU32_MASK_SIGNAL_RELEASE_INHIBITION
#   define MMG_KU32_MASK_SIGNAL_RELEASE_INHIBITION (33554432U)
#  endif

#  ifndef MMG_KU32_MASK_ENABLE_CODING_RBTMFR
#   define MMG_KU32_MASK_ENABLE_CODING_RBTMFR (134217728U)
#  endif

#  ifndef MMG_KU32_MASK_TENSIONING
#   define MMG_KU32_MASK_TENSIONING (268435456U)
#  endif

#  ifndef MMG_KU32_MASK_BELTFUNCTIONS_DELAY
#   define MMG_KU32_MASK_BELTFUNCTIONS_DELAY (536870912U)
#  endif

#  ifndef MMG_KU32_MASK_POWER_VOLTAGE_UNSTABLE
#   define MMG_KU32_MASK_POWER_VOLTAGE_UNSTABLE (1073741824U)
#  endif

#  ifndef MMG_KU32_MASK_CRITICAL_AT_NOK
#   define MMG_KU32_MASK_CRITICAL_AT_NOK (2147483648U)
#  endif

#  define u32ResetCauseType_Appl_LowerLimit (0U)
#  define u32ResetCauseType_Appl_UpperLimit (4294967295U)

#  ifndef KU32_POWER_ON_RESET_MASK
#   define KU32_POWER_ON_RESET_MASK (1U)
#  endif

#  ifndef KU32_BATTERY_LOSS_MASK
#   define KU32_BATTERY_LOSS_MASK (2U)
#  endif

#  ifndef KU32_CRYSTAL_FAILURE_MASK
#   define KU32_CRYSTAL_FAILURE_MASK (4U)
#  endif

#  ifndef KU32_PLL_FAILURE_MASK
#   define KU32_PLL_FAILURE_MASK (8U)
#  endif

#  ifndef KU32_INTERNAL_WDG_MASK
#   define KU32_INTERNAL_WDG_MASK (16U)
#  endif

#  ifndef KU32_SW_INTERNAL_WDG_MASK
#   define KU32_SW_INTERNAL_WDG_MASK (32U)
#  endif

#  ifndef KU32_SW_RESET_MASK
#   define KU32_SW_RESET_MASK (64U)
#  endif

#  ifndef KU32_BTLD_RESET_MASK
#   define KU32_BTLD_RESET_MASK (128U)
#  endif

#  ifndef KU32_ECC_RAM_MASK
#   define KU32_ECC_RAM_MASK (256U)
#  endif

#  ifndef KU32_ECC_PFLASH_MASK
#   define KU32_ECC_PFLASH_MASK (512U)
#  endif

#  ifndef KU32_OS_EXCEPTION_MASK
#   define KU32_OS_EXCEPTION_MASK (1024U)
#  endif

#  ifndef KU32_INVALID_INTERRUPT_MASK
#   define KU32_INVALID_INTERRUPT_MASK (2048U)
#  endif

#  ifndef KU32_WAKE_UP_EVENT_MASK
#   define KU32_WAKE_UP_EVENT_MASK (4096U)
#  endif

#  ifndef KU32_SW_WDG_TEST_MASK
#   define KU32_SW_WDG_TEST_MASK (8192U)
#  endif

#  ifndef KU32_ECC_UNIDENTIFIED_MASK
#   define KU32_ECC_UNIDENTIFIED_MASK (16384U)
#  endif

#  ifndef KU32_RESET_CAUSE_UNKNOWN
#   define KU32_RESET_CAUSE_UNKNOWN (0U)
#  endif

#  ifndef KU32_ECC_E2P_MASK
#   define KU32_ECC_E2P_MASK (32768U)
#  endif

#  ifndef KU32_MACHINE_EXCEPTION_MASK
#   define KU32_MACHINE_EXCEPTION_MASK (65536U)
#  endif

#  ifndef KU32_STACK_OVERFLOW_MASK
#   define KU32_STACK_OVERFLOW_MASK (131072U)
#  endif

#  ifndef KU32_RAM_DATA_CORRUPTED
#   define KU32_RAM_DATA_CORRUPTED (262144U)
#  endif

#  ifndef KU32_EXTERNAL_WDG_MASK
#   define KU32_EXTERNAL_WDG_MASK (524288U)
#  endif

#  define u32ResetReasonNotificationStatusType_Appl_LowerLimit (0U)
#  define u32ResetReasonNotificationStatusType_Appl_UpperLimit (4294967295U)

#  ifndef KU32_RESET_CAUSE_INACTIVE
#   define KU32_RESET_CAUSE_INACTIVE (85U)
#  endif

#  ifndef KU32_RESET_CAUSE_ACTIVE
#   define KU32_RESET_CAUSE_ACTIVE (170U)
#  endif

#  define u32ResetReasonNotificationType_Appl_LowerLimit (0U)
#  define u32ResetReasonNotificationType_Appl_UpperLimit (4294967295U)

#  ifndef KU32_INVALID_INTERRUPT_NOTIFICATION
#   define KU32_INVALID_INTERRUPT_NOTIFICATION (0U)
#  endif

#  ifndef KU32_OS_EXCEPTION_NOTIFICATION
#   define KU32_OS_EXCEPTION_NOTIFICATION (1U)
#  endif

#  ifndef KU32_BATTERY_LOSS_NOTIFICATION
#   define KU32_BATTERY_LOSS_NOTIFICATION (2U)
#  endif

#  ifndef KU32_ECC_RAM_NOTIFICATION
#   define KU32_ECC_RAM_NOTIFICATION (3U)
#  endif

#  ifndef KU32_ECC_PFLASH_NOTIFICATION
#   define KU32_ECC_PFLASH_NOTIFICATION (4U)
#  endif

#  ifndef KU32_ECC_E2P_NOTIFICATION
#   define KU32_ECC_E2P_NOTIFICATION (5U)
#  endif

#  ifndef KU32_MACHINE_EXCEPTION_NOTIFICATION
#   define KU32_MACHINE_EXCEPTION_NOTIFICATION (6U)
#  endif

#  ifndef KU32_SW_IWD_NOTIFICATION
#   define KU32_SW_IWD_NOTIFICATION (7U)
#  endif

#  ifndef KU32_SW_WDG_TEST_NOTIFICATION
#   define KU32_SW_WDG_TEST_NOTIFICATION (8U)
#  endif

#  ifndef KU32_WAKE_UP_EVENT_NOTIFICATION
#   define KU32_WAKE_UP_EVENT_NOTIFICATION (9U)
#  endif

#  ifndef KU32_ECC_UNIDENTIFIED_NOTIFICATION
#   define KU32_ECC_UNIDENTIFIED_NOTIFICATION (10U)
#  endif

#  ifndef KU32_BTLD_RESET_NOTIFICATION
#   define KU32_BTLD_RESET_NOTIFICATION (11U)
#  endif

#  ifndef KU32_STACK_OVERFLOW_NOTIFICATION
#   define KU32_STACK_OVERFLOW_NOTIFICATION (12U)
#  endif

#  ifndef KU32_RAM_DATA_CORRUPTED_NOTIFICATION
#   define KU32_RAM_DATA_CORRUPTED_NOTIFICATION (13U)
#  endif

#  ifndef KU32_DIAG_HARD_RESET_NOTIFICATION
#   define KU32_DIAG_HARD_RESET_NOTIFICATION (14U)
#  endif

#  ifndef KU32_DIAG_SOFT_RESET_NOTIFICATION
#   define KU32_DIAG_SOFT_RESET_NOTIFICATION (15U)
#  endif

#  ifndef KU32_PLL_LOCK_LOSS_NOTIFICATION
#   define KU32_PLL_LOCK_LOSS_NOTIFICATION (16U)
#  endif

#  ifndef KU32_OSC_FAILURE_NOTIFICATION
#   define KU32_OSC_FAILURE_NOTIFICATION (17U)
#  endif

#  ifndef KU32_MAX_RESET_NOTIFICATION
#   define KU32_MAX_RESET_NOTIFICATION (18U)
#  endif

#  define u8AecCommandType_Appl_LowerLimit (0U)
#  define u8AecCommandType_Appl_UpperLimit (255U)

#  ifndef KU8_AEC_FAILED
#   define KU8_AEC_FAILED (0U)
#  endif

#  ifndef KU8_AEC_PASSED
#   define KU8_AEC_PASSED (1U)
#  endif

#  ifndef KU8_AEC_RST_COUNTER
#   define KU8_AEC_RST_COUNTER (2U)
#  endif

#  ifndef KU8_AEC_RST_ALL
#   define KU8_AEC_RST_ALL (3U)
#  endif

#  define u8AecIdentifierType_Appl_LowerLimit (0U)
#  define u8AecIdentifierType_Appl_UpperLimit (255U)

#  ifndef ERH_KU8_UNDEFINED_AEC_CFG
#   define ERH_KU8_UNDEFINED_AEC_CFG (0U)
#  endif

#  ifndef ERH_KU8_ADC_AEC_CFG
#   define ERH_KU8_ADC_AEC_CFG (1U)
#  endif

#  ifndef ERH_KU8_HIGH_SIDE_SWITCH_AEC_CFG
#   define ERH_KU8_HIGH_SIDE_SWITCH_AEC_CFG (2U)
#  endif

#  ifndef ERH_KU8_ENABLE_OUT_OF_ORDER_AEC_CFG
#   define ERH_KU8_ENABLE_OUT_OF_ORDER_AEC_CFG (3U)
#  endif

#  ifndef ERH_KU8_MOSFET_HIGH_SC_AEC_CFG
#   define ERH_KU8_MOSFET_HIGH_SC_AEC_CFG (4U)
#  endif

#  ifndef ERH_KU8_MOSFET_LOW_SC_AEC_CFG
#   define ERH_KU8_MOSFET_LOW_SC_AEC_CFG (5U)
#  endif

#  ifndef ERH_KU8_MOTOR_DISCONNECTED_AEC_CFG
#   define ERH_KU8_MOTOR_DISCONNECTED_AEC_CFG (6U)
#  endif

#  ifndef ERH_KU8_HW_SELF_PROTECTION_AEC_CFG
#   define ERH_KU8_HW_SELF_PROTECTION_AEC_CFG (7U)
#  endif

#  ifndef ERH_KU8_MOSFET_OC_AEC_CFG
#   define ERH_KU8_MOSFET_OC_AEC_CFG (8U)
#  endif

#  ifndef ERH_KU8_SPI_ERROR_AEC_CFG
#   define ERH_KU8_SPI_ERROR_AEC_CFG (9U)
#  endif

#  ifndef ERH_KU8_HALL_SENSOR_AEC_CFG
#   define ERH_KU8_HALL_SENSOR_AEC_CFG (10U)
#  endif

#  ifndef ERH_KU8_MOTOR_CURRENT_AEC_CFG
#   define ERH_KU8_MOTOR_CURRENT_AEC_CFG (11U)
#  endif

#  ifndef ERH_KU8_MOTOR_BLOCKED_AEC_CFG
#   define ERH_KU8_MOTOR_BLOCKED_AEC_CFG (12U)
#  endif

#  ifndef ERH_KU8_SW_SELF_PROTECTION_AEC_CFG
#   define ERH_KU8_SW_SELF_PROTECTION_AEC_CFG (13U)
#  endif

#  ifndef ERH_KU8_TEMPERATURE_SENSOR_FAILURE_AEC_CFG
#   define ERH_KU8_TEMPERATURE_SENSOR_FAILURE_AEC_CFG (14U)
#  endif

#  ifndef ERH_KU8_MOTOR_IN_SC_AEC_CFG
#   define ERH_KU8_MOTOR_IN_SC_AEC_CFG (15U)
#  endif

#  ifndef ERH_KU8_MOTOR_ORDER_AEC_CFG
#   define ERH_KU8_MOTOR_ORDER_AEC_CFG (16U)
#  endif

#  ifndef ERH_KU8_UVO_POWER_AEC_CFG
#   define ERH_KU8_UVO_POWER_AEC_CFG (17U)
#  endif

#  ifndef ERH_KU8_OVO_POWER_AEC_CFG
#   define ERH_KU8_OVO_POWER_AEC_CFG (18U)
#  endif

#  ifndef ERH_KU8_UVO_TENSIONING_POWER_AEC_CFG
#   define ERH_KU8_UVO_TENSIONING_POWER_AEC_CFG (19U)
#  endif

#  ifndef ERH_KU8_OVO_TENSIONING_POWER_AEC_CFG
#   define ERH_KU8_OVO_TENSIONING_POWER_AEC_CFG (20U)
#  endif

#  ifndef ERH_KU8_EXT_WDG_OUT_OF_ORDER_AEC_CFG
#   define ERH_KU8_EXT_WDG_OUT_OF_ORDER_AEC_CFG (21U)
#  endif

#  ifndef ERH_KU8_FLS_OUT_OF_ORDER_AEC_CFG
#   define ERH_KU8_FLS_OUT_OF_ORDER_AEC_CFG (22U)
#  endif

#  ifndef ERH_KU8_NVM_NOT_PROG_AEC_CFG
#   define ERH_KU8_NVM_NOT_PROG_AEC_CFG (23U)
#  endif

#  ifndef ERH_KU8_NVM_INTEGRITY_AEC_CFG
#   define ERH_KU8_NVM_INTEGRITY_AEC_CFG (24U)
#  endif

#  ifndef ERH_KU8_RAM_ECC_AEC_CFG
#   define ERH_KU8_RAM_ECC_AEC_CFG (25U)
#  endif

#  ifndef ERH_KU8_CAN_BUS_OFF_AEC_CFG
#   define ERH_KU8_CAN_BUS_OFF_AEC_CFG (26U)
#  endif

#  ifndef ERH_KU8_WARM_RESET_AEC_CFG
#   define ERH_KU8_WARM_RESET_AEC_CFG (27U)
#  endif

#  ifndef ERH_KU8_END_OF_LIFE_COMFORT_AEC_CFG
#   define ERH_KU8_END_OF_LIFE_COMFORT_AEC_CFG (28U)
#  endif

#  ifndef ERH_KU8_END_OF_LIFE_LOW_AEC_CFG
#   define ERH_KU8_END_OF_LIFE_LOW_AEC_CFG (29U)
#  endif

#  ifndef ERH_KU8_END_OF_LIFE_HIGH_AEC_CFG
#   define ERH_KU8_END_OF_LIFE_HIGH_AEC_CFG (30U)
#  endif

#  ifndef ERH_KU8_END_OF_LIFE_MAX_FORCE_AEC_CFG
#   define ERH_KU8_END_OF_LIFE_MAX_FORCE_AEC_CFG (31U)
#  endif

#  ifndef ERH_KU8_NVM_CHECKSUM_AEC_CFG
#   define ERH_KU8_NVM_CHECKSUM_AEC_CFG (32U)
#  endif

#  ifndef ERH_KU8_TIMEOUT_PRESAFE_AEC_CFG
#   define ERH_KU8_TIMEOUT_PRESAFE_AEC_CFG (33U)
#  endif

#  ifndef ERH_KU8_TIMEOUT_BUCKLE_AEC_CFG
#   define ERH_KU8_TIMEOUT_BUCKLE_AEC_CFG (34U)
#  endif

#  ifndef ERH_KU8_IMPLAUSIBLE_DATA_PRESAFE_AEC_CFG
#   define ERH_KU8_IMPLAUSIBLE_DATA_PRESAFE_AEC_CFG (35U)
#  endif

#  ifndef ERH_KU8_IMPLAUSIBLE_DATA_IGNITION_AEC_CFG
#   define ERH_KU8_IMPLAUSIBLE_DATA_IGNITION_AEC_CFG (36U)
#  endif

#  ifndef ERH_KU8_IMPLAUSIBLE_DATA_BUCKLE_AEC_CFG
#   define ERH_KU8_IMPLAUSIBLE_DATA_BUCKLE_AEC_CFG (37U)
#  endif

#  ifndef ERH_KU8_TIMEOUT_IGNITION_AEC_CFG
#   define ERH_KU8_TIMEOUT_IGNITION_AEC_CFG (38U)
#  endif

#  ifndef ERH_KU8_TIMEOUT_POWERTRAIN_AEC_CFG
#   define ERH_KU8_TIMEOUT_POWERTRAIN_AEC_CFG (39U)
#  endif

#  ifndef ERH_KU8_IMPLAUSIBLE_DATA_POWERTRAIN_RDY_AEC_CFG
#   define ERH_KU8_IMPLAUSIBLE_DATA_POWERTRAIN_RDY_AEC_CFG (40U)
#  endif

#  ifndef ERH_KU8_IMPLAUSIBLE_DATA_ORC_AEC_CFG
#   define ERH_KU8_IMPLAUSIBLE_DATA_ORC_AEC_CFG (41U)
#  endif

#  ifndef ERH_KU8_TIMEOUT_BLTHD_L_AEC_CFG
#   define ERH_KU8_TIMEOUT_BLTHD_L_AEC_CFG (42U)
#  endif

#  ifndef ERH_KU8_TIMEOUT_BLTHD_R_AEC_CFG
#   define ERH_KU8_TIMEOUT_BLTHD_R_AEC_CFG (43U)
#  endif

#  ifndef ERH_KU8_SYSTEM_OV_AEC_CFG
#   define ERH_KU8_SYSTEM_OV_AEC_CFG (44U)
#  endif

#  ifndef ERH_KU8_SYSTEM_UV_AEC_CFG
#   define ERH_KU8_SYSTEM_UV_AEC_CFG (45U)
#  endif

#  ifndef ERH_KU8_STEERING_CONFIG_AEC_CFG
#   define ERH_KU8_STEERING_CONFIG_AEC_CFG (46U)
#  endif

#  ifndef ERH_KU8_TIMEOUT_API
#   define ERH_KU8_TIMEOUT_API (47U)
#  endif

#  ifndef ERH_KU8_IMPLAUSIBLE_DATA_POWERTRAIN_DRV_AEC_CFG
#   define ERH_KU8_IMPLAUSIBLE_DATA_POWERTRAIN_DRV_AEC_CFG (48U)
#  endif

#  ifndef ERH_KU8_TIMEOUT_ODOSPEEDOMETER_AEC_CFG
#   define ERH_KU8_TIMEOUT_ODOSPEEDOMETER_AEC_CFG (49U)
#  endif

#  ifndef ERH_KU8_IMPLAUSIBLE_DATA_API_AEC_CFG
#   define ERH_KU8_IMPLAUSIBLE_DATA_API_AEC_CFG (50U)
#  endif

#  ifndef ERH_KU8_VARIANT_CODING_AEC_CFG
#   define ERH_KU8_VARIANT_CODING_AEC_CFG (51U)
#  endif

#  ifndef ERH_KU8_TIMEOUT_BELT_ADJ_AEC_CFG
#   define ERH_KU8_TIMEOUT_BELT_ADJ_AEC_CFG (52U)
#  endif

#  ifndef ERH_KU8_AEC_QUALIFIED_STATUS_MASK
#   define ERH_KU8_AEC_QUALIFIED_STATUS_MASK (1U)
#  endif

#  ifndef ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK
#   define ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK (2U)
#  endif

#  ifndef ERH_KU8_AEC_EVER_TESTED_STATUS_MASK
#   define ERH_KU8_AEC_EVER_TESTED_STATUS_MASK (4U)
#  endif

#  ifndef ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK
#   define ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK (8U)
#  endif

#  ifndef ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK
#   define ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK (16U)
#  endif

#  ifndef ERH_KU8_AEC_UNPLAUSIBLE_STATUS
#   define ERH_KU8_AEC_UNPLAUSIBLE_STATUS (251U)
#  endif

#  ifndef ATM_KU8_ID_TEST_ADC
#   define ATM_KU8_ID_TEST_ADC (0U)
#  endif

#  ifndef ATM_KU8_ID_TEST_HIGH_SIDE_SWITCH
#   define ATM_KU8_ID_TEST_HIGH_SIDE_SWITCH (1U)
#  endif

#  ifndef ATM_KU8_ID_TEST_DRIVER_COMMAND
#   define ATM_KU8_ID_TEST_DRIVER_COMMAND (2U)
#  endif

#  ifndef ATM_KU8_ID_TEST_MOSFET_HIGH_SHORT_CIRCUIT
#   define ATM_KU8_ID_TEST_MOSFET_HIGH_SHORT_CIRCUIT (3U)
#  endif

#  ifndef ATM_KU8_ID_TEST_MOSFET_LOW_SHORT_CIRCUIT
#   define ATM_KU8_ID_TEST_MOSFET_LOW_SHORT_CIRCUIT (4U)
#  endif

#  ifndef ATM_KU8_ID_TEST_MOTOR_DISCONNECTION
#   define ATM_KU8_ID_TEST_MOTOR_DISCONNECTION (5U)
#  endif

#  ifndef ATM_KU8_ID_TEST_DRIVER_SELF_PROTECTION
#   define ATM_KU8_ID_TEST_DRIVER_SELF_PROTECTION (6U)
#  endif

#  ifndef ATM_KU8_ID_TEST_MOSFET_OPEN_CIRCUIT
#   define ATM_KU8_ID_TEST_MOSFET_OPEN_CIRCUIT (7U)
#  endif

#  ifndef ATM_KU8_ID_SPI_ERROR
#   define ATM_KU8_ID_SPI_ERROR (8U)
#  endif

#  ifndef ATM_KU8_ID_TEST_HALL_EFFECT_SENSORS
#   define ATM_KU8_ID_TEST_HALL_EFFECT_SENSORS (9U)
#  endif

#  ifndef ATM_KU8_ID_TEST_MOTOR_CURRENT
#   define ATM_KU8_ID_TEST_MOTOR_CURRENT (10U)
#  endif

#  ifndef ATM_KU8_ID_TEST_MOTOR_BLOCKED
#   define ATM_KU8_ID_TEST_MOTOR_BLOCKED (11U)
#  endif

#  ifndef ATM_KU8_ID_TEST_MOTOR_TEMPERATURE
#   define ATM_KU8_ID_TEST_MOTOR_TEMPERATURE (12U)
#  endif

#  ifndef ATM_KU8_ID_TEST_SENSOR_TEMPERATURE
#   define ATM_KU8_ID_TEST_SENSOR_TEMPERATURE (13U)
#  endif

#  ifndef ATM_KU8_ID_TEST_MOTOR_SHORT_CIRCUIT
#   define ATM_KU8_ID_TEST_MOTOR_SHORT_CIRCUIT (14U)
#  endif

#  ifndef ATM_KU8_ID_TEST_PWM_ORDER
#   define ATM_KU8_ID_TEST_PWM_ORDER (15U)
#  endif

#  ifndef ATM_KU8_ID_TEST_UNDER_VOLTAGE_POWER
#   define ATM_KU8_ID_TEST_UNDER_VOLTAGE_POWER (16U)
#  endif

#  ifndef ATM_KU8_ID_TEST_OVER_VOLTAGE_POWER
#   define ATM_KU8_ID_TEST_OVER_VOLTAGE_POWER (17U)
#  endif

#  ifndef ATM_KU8_ID_TEST_UNDER_VOLTAGE_TENSIONING_POWER
#   define ATM_KU8_ID_TEST_UNDER_VOLTAGE_TENSIONING_POWER (18U)
#  endif

#  ifndef ATM_KU8_ID_TEST_OVER_VOLTAGE_TENSIONING_POWER
#   define ATM_KU8_ID_TEST_OVER_VOLTAGE_TENSIONING_POWER (19U)
#  endif

#  ifndef ATM_KU8_ID_EXT_WDG_OUT_OF_ORDER
#   define ATM_KU8_ID_EXT_WDG_OUT_OF_ORDER (20U)
#  endif

#  ifndef ATM_KU8_ID_FLS_OUT_OF_ORDER
#   define ATM_KU8_ID_FLS_OUT_OF_ORDER (21U)
#  endif

#  ifndef ATM_KU8_ID_NVM_NOT_PROG
#   define ATM_KU8_ID_NVM_NOT_PROG (22U)
#  endif

#  ifndef ATM_KU8_ID_NVM_MEMORY_CORRUPTION
#   define ATM_KU8_ID_NVM_MEMORY_CORRUPTION (23U)
#  endif

#  ifndef ATM_KU8_ID_RAM_MEMORY_CORRUPTION
#   define ATM_KU8_ID_RAM_MEMORY_CORRUPTION (24U)
#  endif

#  ifndef ATM_KU8_ID_TFLASH_MEMORY_CORRUPTION
#   define ATM_KU8_ID_TFLASH_MEMORY_CORRUPTION (25U)
#  endif

#  ifndef ATM_KU8_ID_TEST_CAN_BUS_OFF
#   define ATM_KU8_ID_TEST_CAN_BUS_OFF (26U)
#  endif

#  ifndef ATM_KU8_ID_RESET_CAUSE
#   define ATM_KU8_ID_RESET_CAUSE (27U)
#  endif

#  ifndef ATM_KU8_ID_END_OF_LIFE_LOW_FORCE
#   define ATM_KU8_ID_END_OF_LIFE_LOW_FORCE (28U)
#  endif

#  ifndef ATM_KU8_ID_END_OF_LIFE_HIGH_FORCE
#   define ATM_KU8_ID_END_OF_LIFE_HIGH_FORCE (29U)
#  endif

#  ifndef ATM_KU8_ID_END_OF_LIFE_COMFORT
#   define ATM_KU8_ID_END_OF_LIFE_COMFORT (30U)
#  endif

#  ifndef ATM_KU8_ID_END_OF_LIFE_MAX_FORCE
#   define ATM_KU8_ID_END_OF_LIFE_MAX_FORCE (31U)
#  endif

#  ifndef ATM_KU8_ID_TEST_NVM_CHECKSUM
#   define ATM_KU8_ID_TEST_NVM_CHECKSUM (32U)
#  endif

#  ifndef ATM_KU8_ID_TIMEOUT_PRESAFE
#   define ATM_KU8_ID_TIMEOUT_PRESAFE (33U)
#  endif

#  ifndef ATM_KU8_ID_TIMEOUT_BUCKLE
#   define ATM_KU8_ID_TIMEOUT_BUCKLE (34U)
#  endif

#  ifndef ATM_KU8_ID_IMPLAUSIBLE_DATA_PRESAFE
#   define ATM_KU8_ID_IMPLAUSIBLE_DATA_PRESAFE (35U)
#  endif

#  ifndef ATM_KU8_ID_IMPLAUSIBLE_DATA_IGNITION
#   define ATM_KU8_ID_IMPLAUSIBLE_DATA_IGNITION (36U)
#  endif

#  ifndef ATM_KU8_ID_IMPLAUSIBLE_DATA_BUCKLE
#   define ATM_KU8_ID_IMPLAUSIBLE_DATA_BUCKLE (37U)
#  endif

#  ifndef ATM_KU8_ID_TIMEOUT_BLTHD_R
#   define ATM_KU8_ID_TIMEOUT_BLTHD_R (38U)
#  endif

#  ifndef ATM_KU8_ID_TIMEOUT_BLTHD_L
#   define ATM_KU8_ID_TIMEOUT_BLTHD_L (39U)
#  endif

#  ifndef ATM_KU8_ID_TIMEOUT_IGNITION
#   define ATM_KU8_ID_TIMEOUT_IGNITION (40U)
#  endif

#  ifndef ATM_KU8_ID_IMPLAUSIBLE_DATA_ORC
#   define ATM_KU8_ID_IMPLAUSIBLE_DATA_ORC (41U)
#  endif

#  ifndef ATM_KU8_ID_IMPLAUSIBLE_DATA_POWERTRAIN_RDY
#   define ATM_KU8_ID_IMPLAUSIBLE_DATA_POWERTRAIN_RDY (42U)
#  endif

#  ifndef ATM_KU8_ID_TIMEOUT_POWERTRAIN
#   define ATM_KU8_ID_TIMEOUT_POWERTRAIN (43U)
#  endif

#  ifndef ATM_KU8_ID_STEERING_CONFIGURATION
#   define ATM_KU8_ID_STEERING_CONFIGURATION (44U)
#  endif

#  ifndef ATM_KU8_ID_SYSTEM_OV
#   define ATM_KU8_ID_SYSTEM_OV (45U)
#  endif

#  ifndef ATM_KU8_ID_SYSTEM_UV
#   define ATM_KU8_ID_SYSTEM_UV (46U)
#  endif

#  ifndef ATM_KU8_ID_TIMEOUT_API
#   define ATM_KU8_ID_TIMEOUT_API (47U)
#  endif

#  ifndef ATM_KU8_ID_IMPLAUSIBLE_DATA_POWERTRAIN_DRV
#   define ATM_KU8_ID_IMPLAUSIBLE_DATA_POWERTRAIN_DRV (48U)
#  endif

#  ifndef ATM_KU8_ID_TIMEOUT_ODOSPEEDOMETER
#   define ATM_KU8_ID_TIMEOUT_ODOSPEEDOMETER (49U)
#  endif

#  ifndef ATM_KU8_ID_IMPLAUSIBLE_DATA_API
#   define ATM_KU8_ID_IMPLAUSIBLE_DATA_API (50U)
#  endif

#  ifndef ATM_KU8_ID_VARIANT_CODING
#   define ATM_KU8_ID_VARIANT_CODING (51U)
#  endif

#  ifndef ATM_KU8_ID_TIMEOUT_BELT_ADJ
#   define ATM_KU8_ID_TIMEOUT_BELT_ADJ (52U)
#  endif

#  ifndef ATM_KU8_NB_OF_AUTOTEST
#   define ATM_KU8_NB_OF_AUTOTEST (53U)
#  endif

#  define u8BatteryVoltageSurveyStatusType_Appl_LowerLimit (0U)
#  define u8BatteryVoltageSurveyStatusType_Appl_UpperLimit (255U)

#  ifndef KU8_BATTERY_STABLE
#   define KU8_BATTERY_STABLE (0U)
#  endif

#  ifndef KU8_BATTERY_UNSTABLE
#   define KU8_BATTERY_UNSTABLE (1U)
#  endif

#  define u8BeltParkingAuthorizationStateType_Appl_LowerLimit (0U)
#  define u8BeltParkingAuthorizationStateType_Appl_UpperLimit (255U)

#  ifndef KU8_BP_AUTHORIZATION_STATE_INIT
#   define KU8_BP_AUTHORIZATION_STATE_INIT (0U)
#  endif

#  ifndef KU8_BP_AUTHORIZATION_STATE_OPS_ALLOWED
#   define KU8_BP_AUTHORIZATION_STATE_OPS_ALLOWED (1U)
#  endif

#  ifndef KU8_BP_AUTHORIZATION_STATE_IDLE
#   define KU8_BP_AUTHORIZATION_STATE_IDLE (2U)
#  endif

#  ifndef KU8_BP_AUTHORIZATION_STATE_BPDO_ALLOWED
#   define KU8_BP_AUTHORIZATION_STATE_BPDO_ALLOWED (3U)
#  endif

#  ifndef KU8_BP_AUTHORIZATION_STATE_BPDC_ALLOWED
#   define KU8_BP_AUTHORIZATION_STATE_BPDC_ALLOWED (4U)
#  endif

#  ifndef KU8_BP_AUTHORIZATION_STATE_BUCKLED
#   define KU8_BP_AUTHORIZATION_STATE_BUCKLED (5U)
#  endif

#  define u8BeltSlackStatusType_Appl_LowerLimit (0U)
#  define u8BeltSlackStatusType_Appl_UpperLimit (255U)

#  ifndef KU8_BELT_SLACK_OFF
#   define KU8_BELT_SLACK_OFF (0U)
#  endif

#  ifndef KU8_BELT_SLACK_ON
#   define KU8_BELT_SLACK_ON (1U)
#  endif

#  ifndef KU8_BELT_SLACK_NOT_DEFINED
#   define KU8_BELT_SLACK_NOT_DEFINED (2U)
#  endif

#  ifndef KU8_BELT_SLACK_INVALID
#   define KU8_BELT_SLACK_INVALID (3U)
#  endif

#  ifndef CAN_NM_U8_BUS_SLEEP
#   define CAN_NM_U8_BUS_SLEEP (1U)
#  endif

#  ifndef CAN_NM_U8_REPEAT_MESSAGE
#   define CAN_NM_U8_REPEAT_MESSAGE (2U)
#  endif

#  ifndef CAN_NM_U8_NORMAL_OPERATION
#   define CAN_NM_U8_NORMAL_OPERATION (4U)
#  endif

#  ifndef CAN_NM_U8_READY_SLEEP
#   define CAN_NM_U8_READY_SLEEP (8U)
#  endif

#  ifndef CAN_NM_U8_PREPARE_SLEEP
#   define CAN_NM_U8_PREPARE_SLEEP (16U)
#  endif

#  ifndef CAN_NM_U8_OFF
#   define CAN_NM_U8_OFF (32U)
#  endif

#  define u8ClkStatusType_Appl_LowerLimit (0U)
#  define u8ClkStatusType_Appl_UpperLimit (255U)

#  ifndef KU8_PRT_EXTERNAL_CLOCK_STATUS_DISABLE
#   define KU8_PRT_EXTERNAL_CLOCK_STATUS_DISABLE (0U)
#  endif

#  ifndef KU8_PRT_EXTERNAL_CLOCK_STATUS_ENABLE
#   define KU8_PRT_EXTERNAL_CLOCK_STATUS_ENABLE (1U)
#  endif

#  ifndef KU8_PRT_EXTERNAL_CLOCK_STATUS_UNKNOWN
#   define KU8_PRT_EXTERNAL_CLOCK_STATUS_UNKNOWN (255U)
#  endif

#  define u8CycleNumberType_Appl_LowerLimit (0U)
#  define u8CycleNumberType_Appl_UpperLimit (255U)

#  ifndef KU8_BELT_FUNCTION_00
#   define KU8_BELT_FUNCTION_00 (0U)
#  endif

#  ifndef KU8_BELT_FUNCTION_01
#   define KU8_BELT_FUNCTION_01 (1U)
#  endif

#  ifndef KU8_BELT_FUNCTION_02
#   define KU8_BELT_FUNCTION_02 (2U)
#  endif

#  ifndef KU8_BELT_FUNCTION_03
#   define KU8_BELT_FUNCTION_03 (3U)
#  endif

#  ifndef KU8_BELT_FUNCTION_04
#   define KU8_BELT_FUNCTION_04 (4U)
#  endif

#  ifndef KU8_BELT_FUNCTION_05
#   define KU8_BELT_FUNCTION_05 (5U)
#  endif

#  ifndef KU8_BELT_FUNCTION_06
#   define KU8_BELT_FUNCTION_06 (6U)
#  endif

#  ifndef KU8_BELT_FUNCTION_07
#   define KU8_BELT_FUNCTION_07 (7U)
#  endif

#  ifndef KU8_BELT_FUNCTION_08
#   define KU8_BELT_FUNCTION_08 (8U)
#  endif

#  ifndef KU8_BELT_FUNCTION_09
#   define KU8_BELT_FUNCTION_09 (9U)
#  endif

#  ifndef KU8_BELT_FUNCTION_10
#   define KU8_BELT_FUNCTION_10 (10U)
#  endif

#  ifndef KU8_BELT_FUNCTION_11
#   define KU8_BELT_FUNCTION_11 (11U)
#  endif

#  ifndef KU8_BELT_FUNCTION_12
#   define KU8_BELT_FUNCTION_12 (12U)
#  endif

#  ifndef KU8_BELT_FUNCTION_13
#   define KU8_BELT_FUNCTION_13 (13U)
#  endif

#  ifndef KU8_BELT_FUNCTION_14
#   define KU8_BELT_FUNCTION_14 (14U)
#  endif

#  ifndef KU8_BELT_FUNCTION_15
#   define KU8_BELT_FUNCTION_15 (15U)
#  endif

#  ifndef KU8_BELT_FUNCTION_16
#   define KU8_BELT_FUNCTION_16 (16U)
#  endif

#  ifndef KU8_BELT_FUNCTION_17
#   define KU8_BELT_FUNCTION_17 (17U)
#  endif

#  ifndef KU8_BELT_FUNCTION_18
#   define KU8_BELT_FUNCTION_18 (18U)
#  endif

#  ifndef KU8_BELT_FUNCTION_19
#   define KU8_BELT_FUNCTION_19 (19U)
#  endif

#  ifndef KU8_BELT_FUNCTION_20
#   define KU8_BELT_FUNCTION_20 (20U)
#  endif

#  ifndef KU8_BELT_FUNCTION_21
#   define KU8_BELT_FUNCTION_21 (21U)
#  endif

#  ifndef KU8_BELT_FUNCTION_22
#   define KU8_BELT_FUNCTION_22 (22U)
#  endif

#  ifndef KU8_BELT_FUNCTION_23
#   define KU8_BELT_FUNCTION_23 (23U)
#  endif

#  ifndef KU8_BELT_FUNCTION_24
#   define KU8_BELT_FUNCTION_24 (24U)
#  endif

#  ifndef KU8_BELT_FUNCTION_25
#   define KU8_BELT_FUNCTION_25 (25U)
#  endif

#  ifndef KU8_BELT_FUNCTION_26
#   define KU8_BELT_FUNCTION_26 (26U)
#  endif

#  ifndef KU8_BELT_FUNCTION_27
#   define KU8_BELT_FUNCTION_27 (27U)
#  endif

#  ifndef KU8_BELT_FUNCTION_28
#   define KU8_BELT_FUNCTION_28 (28U)
#  endif

#  ifndef KU8_BELT_FUNCTION_29
#   define KU8_BELT_FUNCTION_29 (29U)
#  endif

#  ifndef KU8_BELT_FUNCTION_30
#   define KU8_BELT_FUNCTION_30 (30U)
#  endif

#  ifndef KU8_BELT_FUNCTION_31
#   define KU8_BELT_FUNCTION_31 (31U)
#  endif

#  ifndef KU8_BELT_FUNCTION_32
#   define KU8_BELT_FUNCTION_32 (32U)
#  endif

#  ifndef KU8_BELT_FUNCTION_33
#   define KU8_BELT_FUNCTION_33 (33U)
#  endif

#  ifndef KU8_BELT_FUNCTION_34
#   define KU8_BELT_FUNCTION_34 (34U)
#  endif

#  ifndef KU8_NB_MAX_CYCLES
#   define KU8_NB_MAX_CYCLES (35U)
#  endif

#  ifndef KU8_NO_CYCLE
#   define KU8_NO_CYCLE (255U)
#  endif

#  define u8DoorSwitchStatusType_Appl_LowerLimit (0U)
#  define u8DoorSwitchStatusType_Appl_UpperLimit (255U)

#  ifndef KU8_DOOR_SWITCH_OPENED
#   define KU8_DOOR_SWITCH_OPENED (170U)
#  endif

#  ifndef KU8_DOOR_SWITCH_CLOSED
#   define KU8_DOOR_SWITCH_CLOSED (85U)
#  endif

#  ifndef KU8_DOOR_SWITCH_NOT_DEFINED
#   define KU8_DOOR_SWITCH_NOT_DEFINED (255U)
#  endif

#  define u8EccErrorStatusType_Appl_LowerLimit (0U)
#  define u8EccErrorStatusType_Appl_UpperLimit (255U)

#  ifndef KU8_ECC_STATUS_ACTIVE
#   define KU8_ECC_STATUS_ACTIVE (1U)
#  endif

#  ifndef KU8_ECC_STATUS_DETECTED_SINCE_LAST_RESET
#   define KU8_ECC_STATUS_DETECTED_SINCE_LAST_RESET (128U)
#  endif

#  ifndef KU8_ECC_STATUS_NONE
#   define KU8_ECC_STATUS_NONE (0U)
#  endif

#  define u8EccErrorType_Appl_LowerLimit (0U)
#  define u8EccErrorType_Appl_UpperLimit (255U)

#  ifndef KU8_ECC_ERROR_PFLASH
#   define KU8_ECC_ERROR_PFLASH (1U)
#  endif

#  ifndef KU8_ECC_ERROR_RAM
#   define KU8_ECC_ERROR_RAM (3U)
#  endif

#  ifndef KU8_ECC_ERROR_NONE
#   define KU8_ECC_ERROR_NONE (0U)
#  endif

#  ifndef KU8_ECC_ERROR_DFLASH
#   define KU8_ECC_ERROR_DFLASH (2U)
#  endif

#  ifndef KU8_ECC_ERROR_TFLASH
#   define KU8_ECC_ERROR_TFLASH (4U)
#  endif

#  ifndef KU8_ECC_ERROR_UNIDENTIFIED
#   define KU8_ECC_ERROR_UNIDENTIFIED (5U)
#  endif

#  ifndef KU8_ECC_ERROR_NUMBER
#   define KU8_ECC_ERROR_NUMBER (6U)
#  endif

#  ifndef ESM_U8_WAKE_UP_REQUEST_EVENT
#   define ESM_U8_WAKE_UP_REQUEST_EVENT (0U)
#  endif

#  ifndef ESM_U8_KEEP_ALIVE_ABSENT_EVENT
#   define ESM_U8_KEEP_ALIVE_ABSENT_EVENT (1U)
#  endif

#  ifndef ESM_U8_ECU_SHUTDOWN_ON_GOING_EVENT
#   define ESM_U8_ECU_SHUTDOWN_ON_GOING_EVENT (2U)
#  endif

#  ifndef ESM_U8_GO_TO_SLEEP_REQUEST_EVENT
#   define ESM_U8_GO_TO_SLEEP_REQUEST_EVENT (3U)
#  endif

#  ifndef ESM_U8_FORCE_SHUTDOWN
#   define ESM_U8_FORCE_SHUTDOWN (4U)
#  endif

#  ifndef ESM_U8_NB_EVENTS
#   define ESM_U8_NB_EVENTS (5U)
#  endif

#  ifndef ESM_U8_STATE_WAKE_UP
#   define ESM_U8_STATE_WAKE_UP (1U)
#  endif

#  ifndef ESM_U8_STATE_RUN
#   define ESM_U8_STATE_RUN (2U)
#  endif

#  ifndef ESM_U8_STATE_POST_RUN
#   define ESM_U8_STATE_POST_RUN (4U)
#  endif

#  ifndef ESM_U8_STATE_SHUTDOWN
#   define ESM_U8_STATE_SHUTDOWN (8U)
#  endif

#  define u8HapticRequestType_Appl_LowerLimit (0U)
#  define u8HapticRequestType_Appl_UpperLimit (255U)

#  ifndef KU8_HAPTIC_REQUEST_0
#   define KU8_HAPTIC_REQUEST_0 (0U)
#  endif

#  ifndef KU8_HAPTIC_REQUEST_1
#   define KU8_HAPTIC_REQUEST_1 (1U)
#  endif

#  ifndef KU8_HAPTIC_REQUEST_2
#   define KU8_HAPTIC_REQUEST_2 (2U)
#  endif

#  ifndef KU8_HAPTIC_REQUEST_3
#   define KU8_HAPTIC_REQUEST_3 (3U)
#  endif

#  ifndef KU8_HAPTIC_REQUEST_4
#   define KU8_HAPTIC_REQUEST_4 (4U)
#  endif

#  ifndef KU8_HAPTIC_REQUEST_5
#   define KU8_HAPTIC_REQUEST_5 (5U)
#  endif

#  ifndef KU8_HAPTIC_REQUEST_6
#   define KU8_HAPTIC_REQUEST_6 (6U)
#  endif

#  ifndef KU8_HAPTIC_REQUEST_7
#   define KU8_HAPTIC_REQUEST_7 (7U)
#  endif

#  ifndef KU8_NO_HAPTIC_REQUEST
#   define KU8_NO_HAPTIC_REQUEST (8U)
#  endif

#  define u8JobTypesListType_Appl_LowerLimit (0U)
#  define u8JobTypesListType_Appl_UpperLimit (255U)

#  ifndef KU8_JOB_TO_MONITOR_TIME_SLOT
#   define KU8_JOB_TO_MONITOR_TIME_SLOT (0U)
#  endif

#  ifndef KU8_JOB_TO_MONITOR_ANY_PERIOD
#   define KU8_JOB_TO_MONITOR_ANY_PERIOD (1U)
#  endif

#  ifndef KU8_JOB_TO_MONITOR_TASK_DURATION
#   define KU8_JOB_TO_MONITOR_TASK_DURATION (2U)
#  endif

#  ifndef KU8_JOB_TO_MONITOR_TASK_PERIOD
#   define KU8_JOB_TO_MONITOR_TASK_PERIOD (3U)
#  endif

#  ifndef KU8_JOB_TO_MONITOR_INTERRUPT_DURATION
#   define KU8_JOB_TO_MONITOR_INTERRUPT_DURATION (4U)
#  endif

#  ifndef KU8_JOB_TO_MONITOR_NONE
#   define KU8_JOB_TO_MONITOR_NONE (255U)
#  endif

#  ifndef KU8_KLEMMEN_ACCESSORY
#   define KU8_KLEMMEN_ACCESSORY (2U)
#  endif

#  ifndef KU8_KLEMMEN_OFF
#   define KU8_KLEMMEN_OFF (1U)
#  endif

#  ifndef KU8_KLEMMEN_ON
#   define KU8_KLEMMEN_ON (3U)
#  endif

#  ifndef KU8_KLEMMEN_LOCK
#   define KU8_KLEMMEN_LOCK (0U)
#  endif

#  ifndef KU8_KLEMMEN_START
#   define KU8_KLEMMEN_START (4U)
#  endif

#  define u8ModeStatusType_Appl_LowerLimit (0U)
#  define u8ModeStatusType_Appl_UpperLimit (255U)

#  ifndef KU8_MODE_STATUS_ON
#   define KU8_MODE_STATUS_ON (170U)
#  endif

#  ifndef KU8_MODE_STATUS_OFF
#   define KU8_MODE_STATUS_OFF (85U)
#  endif

#  define u8MotorStageStatusType_Appl_LowerLimit (0U)
#  define u8MotorStageStatusType_Appl_UpperLimit (255U)

#  ifndef KU8_MOTOR_STAGE_EMERGENCY_DEACTIVATION
#   define KU8_MOTOR_STAGE_EMERGENCY_DEACTIVATION (85U)
#  endif

#  ifndef KU8_MOTOR_STAGE_ACTIVATION
#   define KU8_MOTOR_STAGE_ACTIVATION (170U)
#  endif

#  define u8OrdersListType_Appl_LowerLimit (0U)
#  define u8OrdersListType_Appl_UpperLimit (255U)

#  ifndef KU8_ORDER_CURRENT_REGULATION
#   define KU8_ORDER_CURRENT_REGULATION (2U)
#  endif

#  ifndef KU8_ORDER_MOTOR_VOLTAGE
#   define KU8_ORDER_MOTOR_VOLTAGE (4U)
#  endif

#  ifndef KU8_ORDER_PID_MOTOR
#   define KU8_ORDER_PID_MOTOR (32U)
#  endif

#  ifndef KU8_ORDER_HIGH_POWER
#   define KU8_ORDER_HIGH_POWER (64U)
#  endif

#  ifndef KU8_ORDER_RESERVED_1
#   define KU8_ORDER_RESERVED_1 (8U)
#  endif

#  ifndef KU8_ORDER_PWM
#   define KU8_ORDER_PWM (1U)
#  endif

#  ifndef KU8_ORDER_PID_SUPPLY
#   define KU8_ORDER_PID_SUPPLY (16U)
#  endif

#  ifndef KU8_ORDER_RESERVED_2
#   define KU8_ORDER_RESERVED_2 (128U)
#  endif

#  define u8PreCrashRequestType_Appl_LowerLimit (0U)
#  define u8PreCrashRequestType_Appl_UpperLimit (255U)

#  ifndef KU8_PRECRASH_REQUEST_0
#   define KU8_PRECRASH_REQUEST_0 (0U)
#  endif

#  ifndef KU8_PRECRASH_REQUEST_1
#   define KU8_PRECRASH_REQUEST_1 (1U)
#  endif

#  ifndef KU8_PRECRASH_REQUEST_2
#   define KU8_PRECRASH_REQUEST_2 (2U)
#  endif

#  ifndef KU8_PRECRASH_REQUEST_3
#   define KU8_PRECRASH_REQUEST_3 (3U)
#  endif

#  ifndef KU8_PRECRASH_REQUEST_4
#   define KU8_PRECRASH_REQUEST_4 (4U)
#  endif

#  ifndef KU8_PRECRASH_REQUEST_5
#   define KU8_PRECRASH_REQUEST_5 (5U)
#  endif

#  ifndef KU8_PRECRASH_REQUEST_6
#   define KU8_PRECRASH_REQUEST_6 (6U)
#  endif

#  ifndef KU8_PRECRASH_REQUEST_7
#   define KU8_PRECRASH_REQUEST_7 (7U)
#  endif

#  ifndef KU8_NO_PRECRASH_REQUEST
#   define KU8_NO_PRECRASH_REQUEST (255U)
#  endif

#  define u8PreCrashSeverityLevelType_Appl_LowerLimit (0U)
#  define u8PreCrashSeverityLevelType_Appl_UpperLimit (255U)

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_1
#   define KU8_PRECRASH_SEVERITY_LEVEL_1 (0U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_2
#   define KU8_PRECRASH_SEVERITY_LEVEL_2 (1U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_3
#   define KU8_PRECRASH_SEVERITY_LEVEL_3 (2U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_4
#   define KU8_PRECRASH_SEVERITY_LEVEL_4 (3U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_5
#   define KU8_PRECRASH_SEVERITY_LEVEL_5 (4U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_6
#   define KU8_PRECRASH_SEVERITY_LEVEL_6 (5U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_7
#   define KU8_PRECRASH_SEVERITY_LEVEL_7 (6U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_8
#   define KU8_PRECRASH_SEVERITY_LEVEL_8 (7U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_9
#   define KU8_PRECRASH_SEVERITY_LEVEL_9 (8U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_10
#   define KU8_PRECRASH_SEVERITY_LEVEL_10 (9U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_11
#   define KU8_PRECRASH_SEVERITY_LEVEL_11 (10U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_12
#   define KU8_PRECRASH_SEVERITY_LEVEL_12 (11U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_13
#   define KU8_PRECRASH_SEVERITY_LEVEL_13 (12U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_14
#   define KU8_PRECRASH_SEVERITY_LEVEL_14 (13U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_15
#   define KU8_PRECRASH_SEVERITY_LEVEL_15 (14U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_16
#   define KU8_PRECRASH_SEVERITY_LEVEL_16 (15U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_17
#   define KU8_PRECRASH_SEVERITY_LEVEL_17 (16U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_18
#   define KU8_PRECRASH_SEVERITY_LEVEL_18 (17U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_BSR_1
#   define KU8_PRECRASH_SEVERITY_LEVEL_BSR_1 (26U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_BSR_2
#   define KU8_PRECRASH_SEVERITY_LEVEL_BSR_2 (27U)
#  endif

#  ifndef KU8_PRECRASH_SEVERITY_LEVEL_BSR_3
#   define KU8_PRECRASH_SEVERITY_LEVEL_BSR_3 (28U)
#  endif

#  ifndef KU8_NO_PRECRASH_SEVERITY_LEVEL
#   define KU8_NO_PRECRASH_SEVERITY_LEVEL (255U)
#  endif

#  define u8PwmChannelId_Appl_LowerLimit (0U)
#  define u8PwmChannelId_Appl_UpperLimit (4U)

#  ifndef PWM_KU8_CH_ID_HB_P
#   define PWM_KU8_CH_ID_HB_P (0U)
#  endif

#  ifndef PWM_KU8_CH_ID_HB_N
#   define PWM_KU8_CH_ID_HB_N (1U)
#  endif

#  ifndef PWM_KU8_CH_ID_BOOST_DRIVER
#   define PWM_KU8_CH_ID_BOOST_DRIVER (2U)
#  endif

#  ifndef PWM_KU8_CH_ID_BOOST_CP
#   define PWM_KU8_CH_ID_BOOST_CP (3U)
#  endif

#  ifndef PWM_KU8_CH_ID_MAX
#   define PWM_KU8_CH_ID_MAX (4U)
#  endif

#  define u8RetractionStatusType_Appl_LowerLimit (0U)
#  define u8RetractionStatusType_Appl_UpperLimit (255U)

#  ifndef KU8_SPRING_FORCE_HARD_ENOUGH
#   define KU8_SPRING_FORCE_HARD_ENOUGH (170U)
#  endif

#  ifndef KU8_SPRING_FORCE_NOT_HARD_ENOUGH
#   define KU8_SPRING_FORCE_NOT_HARD_ENOUGH (85U)
#  endif

#  ifndef KU8_SPRING_FORCE_ON_GOING
#   define KU8_SPRING_FORCE_ON_GOING (255U)
#  endif

#  ifndef KU8_TENSIONING_START
#   define KU8_TENSIONING_START (0U)
#  endif

#  ifndef KU8_TENSIONING_END
#   define KU8_TENSIONING_END (1U)
#  endif

#  ifndef KU8_TENSIONING_INHIBIT
#   define KU8_TENSIONING_INHIBIT (2U)
#  endif

#  ifndef KU8_TENSIONING_ABORT
#   define KU8_TENSIONING_ABORT (3U)
#  endif

#  ifndef KU8_TENSIONING_NONE
#   define KU8_TENSIONING_NONE (4U)
#  endif

#  define u8TestResultType_Appl_LowerLimit (0U)
#  define u8TestResultType_Appl_UpperLimit (255U)

#  ifndef KU8_ATM_TEST_OK
#   define KU8_ATM_TEST_OK (1U)
#  endif

#  ifndef KU8_ATM_TEST_NOK
#   define KU8_ATM_TEST_NOK (2U)
#  endif

#  ifndef KU8_ATM_TEST_NOT_DECIDED
#   define KU8_ATM_TEST_NOT_DECIDED (4U)
#  endif

#  ifndef KU8_ATM_TEST_NON_EXISTENT
#   define KU8_ATM_TEST_NON_EXISTENT (8U)
#  endif

#  ifndef KU8_ATM_TEST_BAD_CONDITIONS
#   define KU8_ATM_TEST_BAD_CONDITIONS (16U)
#  endif

#  define u8TriggeringSourceType_Appl_LowerLimit (0U)
#  define u8TriggeringSourceType_Appl_UpperLimit (255U)

#  ifndef KU8_TRIGGERING_SOURCE_NONE
#   define KU8_TRIGGERING_SOURCE_NONE (0U)
#  endif

#  ifndef KU8_TRIGGERING_SOURCE_VEHICLE
#   define KU8_TRIGGERING_SOURCE_VEHICLE (1U)
#  endif

#  ifndef KU8_TRIGGERING_SOURCE_TESTER
#   define KU8_TRIGGERING_SOURCE_TESTER (2U)
#  endif

#  define u8WdgTestResultType_Appl_LowerLimit (0U)
#  define u8WdgTestResultType_Appl_UpperLimit (255U)

#  ifndef KU8_WDG_TEST_NOT_EXECUTED
#   define KU8_WDG_TEST_NOT_EXECUTED (0U)
#  endif

#  ifndef KU8_WDG_TEST_PASSED
#   define KU8_WDG_TEST_PASSED (170U)
#  endif

#  ifndef KU8_WDG_TEST_FAILED
#   define KU8_WDG_TEST_FAILED (85U)
#  endif

#  define u8lBuckleSwitchStatusType_Appl_LowerLimit (0U)
#  define u8lBuckleSwitchStatusType_Appl_UpperLimit (255U)

#  ifndef KU8_BUCKLE_SWITCH_OPENED
#   define KU8_BUCKLE_SWITCH_OPENED (170U)
#  endif

#  ifndef KU8_BUCKLE_SWITCH_CLOSED
#   define KU8_BUCKLE_SWITCH_CLOSED (85U)
#  endif

#  ifndef KU8_BUCKLE_SWITCH_NOT_DEFINED
#   define KU8_BUCKLE_SWITCH_NOT_DEFINED (255U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_ATM_AC_AUTOTESTMANAGER_TYPE_H */
