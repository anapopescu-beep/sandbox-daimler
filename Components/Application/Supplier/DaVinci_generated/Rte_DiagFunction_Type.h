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
 *             File:  Rte_DiagFunction_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application types header file for SW-C <DiagFunction>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DIAGFUNCTION_TYPE_H
# define RTE_DIAGFUNCTION_TYPE_H

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

#  define c03_ADAS_Posn_Idx_LowerLimit (0U)
#  define c03_ADAS_Posn_Idx_UpperLimit (3U)

#  define c08_0_255_1_SNA_na_LowerLimit (0U)
#  define c08_0_255_1_SNA_na_UpperLimit (255U)

#  define c08_UInt_SNA_na_LowerLimit (0U)
#  define c08_UInt_SNA_na_UpperLimit (255U)

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


#  ifndef DCM_E_POSITIVERESPONSE
#   define DCM_E_POSITIVERESPONSE (0U)
#  endif

#  ifndef DCM_E_GENERALREJECT
#   define DCM_E_GENERALREJECT (16U)
#  endif

#  ifndef DCM_E_SERVICENOTSUPPORTED
#   define DCM_E_SERVICENOTSUPPORTED (17U)
#  endif

#  ifndef DCM_E_SUBFUNCTIONNOTSUPPORTED
#   define DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
#  endif

#  ifndef DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT
#   define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
#  endif

#  ifndef DCM_E_RESPONSETOOLONG
#   define DCM_E_RESPONSETOOLONG (20U)
#  endif

#  ifndef DCM_E_BUSYREPEATREQUEST
#   define DCM_E_BUSYREPEATREQUEST (33U)
#  endif

#  ifndef DCM_E_CONDITIONSNOTCORRECT
#   define DCM_E_CONDITIONSNOTCORRECT (34U)
#  endif

#  ifndef DCM_E_REQUESTSEQUENCEERROR
#   define DCM_E_REQUESTSEQUENCEERROR (36U)
#  endif

#  ifndef DCM_E_NORESPONSEFROMSUBNETCOMPONENT
#   define DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
#  endif

#  ifndef DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION
#   define DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
#  endif

#  ifndef DCM_E_REQUESTOUTOFRANGE
#   define DCM_E_REQUESTOUTOFRANGE (49U)
#  endif

#  ifndef DCM_E_SECURITYACCESSDENIED
#   define DCM_E_SECURITYACCESSDENIED (51U)
#  endif

#  ifndef DCM_E_AUTHENTICATIONREQUIRED
#   define DCM_E_AUTHENTICATIONREQUIRED (52U)
#  endif

#  ifndef DCM_E_INVALIDKEY
#   define DCM_E_INVALIDKEY (53U)
#  endif

#  ifndef DCM_E_EXCEEDNUMBEROFATTEMPTS
#   define DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
#  endif

#  ifndef DCM_E_REQUIREDTIMEDELAYNOTEXPIRED
#   define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
#  endif

#  ifndef DCM_E_CVF_INVALIDTIMEPERIOD
#   define DCM_E_CVF_INVALIDTIMEPERIOD (80U)
#  endif

#  ifndef DCM_E_CVF_INVALIDSIGNATURE
#   define DCM_E_CVF_INVALIDSIGNATURE (81U)
#  endif

#  ifndef DCM_E_CVF_INVALIDCHAINOFTRUST
#   define DCM_E_CVF_INVALIDCHAINOFTRUST (82U)
#  endif

#  ifndef DCM_E_CVF_INVALIDTYPE
#   define DCM_E_CVF_INVALIDTYPE (83U)
#  endif

#  ifndef DCM_E_CVF_INVALIDFORMAT
#   define DCM_E_CVF_INVALIDFORMAT (84U)
#  endif

#  ifndef DCM_E_CVF_INVALIDCONTENT
#   define DCM_E_CVF_INVALIDCONTENT (85U)
#  endif

#  ifndef DCM_E_CVF_INVALIDSCOPE
#   define DCM_E_CVF_INVALIDSCOPE (86U)
#  endif

#  ifndef DCM_E_CVF_INVALIDCERTIFICATEREVOKED
#   define DCM_E_CVF_INVALIDCERTIFICATEREVOKED (87U)
#  endif

#  ifndef DCM_E_OWNERSHIPVERIFICATIONFAILED
#   define DCM_E_OWNERSHIPVERIFICATIONFAILED (88U)
#  endif

#  ifndef DCM_E_CHALLENGECALCULATIONFAILED
#   define DCM_E_CHALLENGECALCULATIONFAILED (89U)
#  endif

#  ifndef DCM_E_UPLOADDOWNLOADNOTACCEPTED
#   define DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
#  endif

#  ifndef DCM_E_TRANSFERDATASUSPENDED
#   define DCM_E_TRANSFERDATASUSPENDED (113U)
#  endif

#  ifndef DCM_E_GENERALPROGRAMMINGFAILURE
#   define DCM_E_GENERALPROGRAMMINGFAILURE (114U)
#  endif

#  ifndef DCM_E_WRONGBLOCKSEQUENCECOUNTER
#   define DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
#  endif

#  ifndef DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING
#   define DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
#  endif

#  ifndef DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION
#   define DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
#  endif

#  ifndef DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION
#   define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
#  endif

#  ifndef DCM_E_RPMTOOHIGH
#   define DCM_E_RPMTOOHIGH (129U)
#  endif

#  ifndef DCM_E_RPMTOOLOW
#   define DCM_E_RPMTOOLOW (130U)
#  endif

#  ifndef DCM_E_ENGINEISRUNNING
#   define DCM_E_ENGINEISRUNNING (131U)
#  endif

#  ifndef DCM_E_ENGINEISNOTRUNNING
#   define DCM_E_ENGINEISNOTRUNNING (132U)
#  endif

#  ifndef DCM_E_ENGINERUNTIMETOOLOW
#   define DCM_E_ENGINERUNTIMETOOLOW (133U)
#  endif

#  ifndef DCM_E_TEMPERATURETOOHIGH
#   define DCM_E_TEMPERATURETOOHIGH (134U)
#  endif

#  ifndef DCM_E_TEMPERATURETOOLOW
#   define DCM_E_TEMPERATURETOOLOW (135U)
#  endif

#  ifndef DCM_E_VEHICLESPEEDTOOHIGH
#   define DCM_E_VEHICLESPEEDTOOHIGH (136U)
#  endif

#  ifndef DCM_E_VEHICLESPEEDTOOLOW
#   define DCM_E_VEHICLESPEEDTOOLOW (137U)
#  endif

#  ifndef DCM_E_THROTTLE_PEDALTOOHIGH
#   define DCM_E_THROTTLE_PEDALTOOHIGH (138U)
#  endif

#  ifndef DCM_E_THROTTLE_PEDALTOOLOW
#   define DCM_E_THROTTLE_PEDALTOOLOW (139U)
#  endif

#  ifndef DCM_E_TRANSMISSIONRANGENOTINNEUTRAL
#   define DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
#  endif

#  ifndef DCM_E_TRANSMISSIONRANGENOTINGEAR
#   define DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
#  endif

#  ifndef DCM_E_BRAKESWITCH_NOTCLOSED
#   define DCM_E_BRAKESWITCH_NOTCLOSED (143U)
#  endif

#  ifndef DCM_E_SHIFTERLEVERNOTINPARK
#   define DCM_E_SHIFTERLEVERNOTINPARK (144U)
#  endif

#  ifndef DCM_E_TORQUECONVERTERCLUTCHLOCKED
#   define DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
#  endif

#  ifndef DCM_E_VOLTAGETOOHIGH
#   define DCM_E_VOLTAGETOOHIGH (146U)
#  endif

#  ifndef DCM_E_VOLTAGETOOLOW
#   define DCM_E_VOLTAGETOOLOW (147U)
#  endif

#  ifndef DCM_E_VMSCNC_0
#   define DCM_E_VMSCNC_0 (240U)
#  endif

#  ifndef DCM_E_VMSCNC_1
#   define DCM_E_VMSCNC_1 (241U)
#  endif

#  ifndef DCM_E_VMSCNC_2
#   define DCM_E_VMSCNC_2 (242U)
#  endif

#  ifndef DCM_E_VMSCNC_3
#   define DCM_E_VMSCNC_3 (243U)
#  endif

#  ifndef DCM_E_VMSCNC_4
#   define DCM_E_VMSCNC_4 (244U)
#  endif

#  ifndef DCM_E_VMSCNC_5
#   define DCM_E_VMSCNC_5 (245U)
#  endif

#  ifndef DCM_E_VMSCNC_6
#   define DCM_E_VMSCNC_6 (246U)
#  endif

#  ifndef DCM_E_VMSCNC_7
#   define DCM_E_VMSCNC_7 (247U)
#  endif

#  ifndef DCM_E_VMSCNC_8
#   define DCM_E_VMSCNC_8 (248U)
#  endif

#  ifndef DCM_E_VMSCNC_9
#   define DCM_E_VMSCNC_9 (249U)
#  endif

#  ifndef DCM_E_VMSCNC_A
#   define DCM_E_VMSCNC_A (250U)
#  endif

#  ifndef DCM_E_VMSCNC_B
#   define DCM_E_VMSCNC_B (251U)
#  endif

#  ifndef DCM_E_VMSCNC_C
#   define DCM_E_VMSCNC_C (252U)
#  endif

#  ifndef DCM_E_VMSCNC_D
#   define DCM_E_VMSCNC_D (253U)
#  endif

#  ifndef DCM_E_VMSCNC_E
#   define DCM_E_VMSCNC_E (254U)
#  endif

#  ifndef DCM_INITIAL
#   define DCM_INITIAL (0U)
#  endif

#  ifndef DCM_PENDING
#   define DCM_PENDING (1U)
#  endif

#  ifndef DCM_CANCEL
#   define DCM_CANCEL (2U)
#  endif

#  ifndef DCM_FORCE_RCRRP_OK
#   define DCM_FORCE_RCRRP_OK (3U)
#  endif

#  ifndef DCM_FORCE_RCRRP_NOT_OK
#   define DCM_FORCE_RCRRP_NOT_OK (64U)
#  endif

#  ifndef DCM_DEFAULT_SESSION
#   define DCM_DEFAULT_SESSION (1U)
#  endif

#  ifndef DCM_PROGRAMMING_SESSION
#   define DCM_PROGRAMMING_SESSION (2U)
#  endif

#  ifndef DCM_EXTENDED_DIAGNOSTIC_SESSION
#   define DCM_EXTENDED_DIAGNOSTIC_SESSION (3U)
#  endif

#  ifndef DCM_Development
#   define DCM_Development (126U)
#  endif

#  ifndef DEM_UDS_STATUS_TF
#   define DEM_UDS_STATUS_TF (1U)
#  endif

#  ifndef DEM_UDS_STATUS_TF_BflMask
#   define DEM_UDS_STATUS_TF_BflMask 1U
#  endif

#  ifndef DEM_UDS_STATUS_TF_BflPn
#   define DEM_UDS_STATUS_TF_BflPn 0U
#  endif

#  ifndef DEM_UDS_STATUS_TF_BflLn
#   define DEM_UDS_STATUS_TF_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_TFTOC
#   define DEM_UDS_STATUS_TFTOC (2U)
#  endif

#  ifndef DEM_UDS_STATUS_TFTOC_BflMask
#   define DEM_UDS_STATUS_TFTOC_BflMask 2U
#  endif

#  ifndef DEM_UDS_STATUS_TFTOC_BflPn
#   define DEM_UDS_STATUS_TFTOC_BflPn 1U
#  endif

#  ifndef DEM_UDS_STATUS_TFTOC_BflLn
#   define DEM_UDS_STATUS_TFTOC_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_PDTC
#   define DEM_UDS_STATUS_PDTC (4U)
#  endif

#  ifndef DEM_UDS_STATUS_PDTC_BflMask
#   define DEM_UDS_STATUS_PDTC_BflMask 4U
#  endif

#  ifndef DEM_UDS_STATUS_PDTC_BflPn
#   define DEM_UDS_STATUS_PDTC_BflPn 2U
#  endif

#  ifndef DEM_UDS_STATUS_PDTC_BflLn
#   define DEM_UDS_STATUS_PDTC_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_CDTC
#   define DEM_UDS_STATUS_CDTC (8U)
#  endif

#  ifndef DEM_UDS_STATUS_CDTC_BflMask
#   define DEM_UDS_STATUS_CDTC_BflMask 8U
#  endif

#  ifndef DEM_UDS_STATUS_CDTC_BflPn
#   define DEM_UDS_STATUS_CDTC_BflPn 3U
#  endif

#  ifndef DEM_UDS_STATUS_CDTC_BflLn
#   define DEM_UDS_STATUS_CDTC_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_TNCSLC
#   define DEM_UDS_STATUS_TNCSLC (16U)
#  endif

#  ifndef DEM_UDS_STATUS_TNCSLC_BflMask
#   define DEM_UDS_STATUS_TNCSLC_BflMask 16U
#  endif

#  ifndef DEM_UDS_STATUS_TNCSLC_BflPn
#   define DEM_UDS_STATUS_TNCSLC_BflPn 4U
#  endif

#  ifndef DEM_UDS_STATUS_TNCSLC_BflLn
#   define DEM_UDS_STATUS_TNCSLC_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_TFSLC
#   define DEM_UDS_STATUS_TFSLC (32U)
#  endif

#  ifndef DEM_UDS_STATUS_TFSLC_BflMask
#   define DEM_UDS_STATUS_TFSLC_BflMask 32U
#  endif

#  ifndef DEM_UDS_STATUS_TFSLC_BflPn
#   define DEM_UDS_STATUS_TFSLC_BflPn 5U
#  endif

#  ifndef DEM_UDS_STATUS_TFSLC_BflLn
#   define DEM_UDS_STATUS_TFSLC_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_TNCTOC
#   define DEM_UDS_STATUS_TNCTOC (64U)
#  endif

#  ifndef DEM_UDS_STATUS_TNCTOC_BflMask
#   define DEM_UDS_STATUS_TNCTOC_BflMask 64U
#  endif

#  ifndef DEM_UDS_STATUS_TNCTOC_BflPn
#   define DEM_UDS_STATUS_TNCTOC_BflPn 6U
#  endif

#  ifndef DEM_UDS_STATUS_TNCTOC_BflLn
#   define DEM_UDS_STATUS_TNCTOC_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_WIR
#   define DEM_UDS_STATUS_WIR (128U)
#  endif

#  ifndef DEM_UDS_STATUS_WIR_BflMask
#   define DEM_UDS_STATUS_WIR_BflMask 128U
#  endif

#  ifndef DEM_UDS_STATUS_WIR_BflPn
#   define DEM_UDS_STATUS_WIR_BflPn 7U
#  endif

#  ifndef DEM_UDS_STATUS_WIR_BflLn
#   define DEM_UDS_STATUS_WIR_BflLn 1U
#  endif

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

#  ifndef TIMEOUT__FALSE
#   define TIMEOUT__FALSE (0U)
#  endif

#  ifndef TIMEOUT_BflMask
#   define TIMEOUT_BflMask 1U
#  endif

#  ifndef TIMEOUT_BflPn
#   define TIMEOUT_BflPn 0U
#  endif

#  ifndef TIMEOUT_BflLn
#   define TIMEOUT_BflLn 1U
#  endif

#  ifndef TIMEOUT
#   define TIMEOUT (1U)
#  endif

#  ifndef SYNC_TO_GATEWAY__FALSE
#   define SYNC_TO_GATEWAY__FALSE (0U)
#  endif

#  ifndef SYNC_TO_GATEWAY_BflMask
#   define SYNC_TO_GATEWAY_BflMask 4U
#  endif

#  ifndef SYNC_TO_GATEWAY_BflPn
#   define SYNC_TO_GATEWAY_BflPn 2U
#  endif

#  ifndef SYNC_TO_GATEWAY_BflLn
#   define SYNC_TO_GATEWAY_BflLn 1U
#  endif

#  ifndef SYNC_TO_GATEWAY
#   define SYNC_TO_GATEWAY (4U)
#  endif

#  ifndef GLOBAL_TIME_BASE__FALSE
#   define GLOBAL_TIME_BASE__FALSE (0U)
#  endif

#  ifndef GLOBAL_TIME_BASE_BflMask
#   define GLOBAL_TIME_BASE_BflMask 8U
#  endif

#  ifndef GLOBAL_TIME_BASE_BflPn
#   define GLOBAL_TIME_BASE_BflPn 3U
#  endif

#  ifndef GLOBAL_TIME_BASE_BflLn
#   define GLOBAL_TIME_BASE_BflLn 1U
#  endif

#  ifndef GLOBAL_TIME_BASE
#   define GLOBAL_TIME_BASE (8U)
#  endif

#  ifndef TIMELEAP_FUTURE__FALSE
#   define TIMELEAP_FUTURE__FALSE (0U)
#  endif

#  ifndef TIMELEAP_FUTURE_BflMask
#   define TIMELEAP_FUTURE_BflMask 16U
#  endif

#  ifndef TIMELEAP_FUTURE_BflPn
#   define TIMELEAP_FUTURE_BflPn 4U
#  endif

#  ifndef TIMELEAP_FUTURE_BflLn
#   define TIMELEAP_FUTURE_BflLn 1U
#  endif

#  ifndef TIMELEAP_FUTURE
#   define TIMELEAP_FUTURE (16U)
#  endif

#  ifndef TIMELEAP_PAST__FALSE
#   define TIMELEAP_PAST__FALSE (0U)
#  endif

#  ifndef TIMELEAP_PAST_BflMask
#   define TIMELEAP_PAST_BflMask 32U
#  endif

#  ifndef TIMELEAP_PAST_BflPn
#   define TIMELEAP_PAST_BflPn 5U
#  endif

#  ifndef TIMELEAP_PAST_BflLn
#   define TIMELEAP_PAST_BflLn 1U
#  endif

#  ifndef TIMELEAP_PAST
#   define TIMELEAP_PAST (32U)
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

#  define c01_FalseTrue_LowerLimit (0U)
#  define c01_FalseTrue_UpperLimit (1U)

#  ifndef I_C01_FALSETRUE_FALSE
#   define I_C01_FALSETRUE_FALSE (0U)
#  endif

#  ifndef I_C01_FALSETRUE_TRUE
#   define I_C01_FALSETRUE_TRUE (1U)
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

#  define c02_Dr_Stat_LowerLimit (1U)
#  define c02_Dr_Stat_UpperLimit (3U)

#  define InvalidValue_c02_Dr_Stat (3U)

#  ifndef I_C02_DR_STAT_CLS
#   define I_C02_DR_STAT_CLS (1U)
#  endif

#  ifndef I_C02_DR_STAT_OPN
#   define I_C02_DR_STAT_OPN (2U)
#  endif

#  ifndef I_C02_DR_STAT_SNA
#   define I_C02_DR_STAT_SNA (3U)
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

#  define c02_Inactv_Silent_Actv_ST3_LowerLimit (0U)
#  define c02_Inactv_Silent_Actv_ST3_UpperLimit (3U)

#  define InvalidValue_c02_Inactv_Silent_Actv_ST3 (3U)

#  ifndef I_C02_INACTV_SILENT_ACTV_ST3_INACTIVE
#   define I_C02_INACTV_SILENT_ACTV_ST3_INACTIVE (0U)
#  endif

#  ifndef I_C02_INACTV_SILENT_ACTV_ST3_SILENT
#   define I_C02_INACTV_SILENT_ACTV_ST3_SILENT (1U)
#  endif

#  ifndef I_C02_INACTV_SILENT_ACTV_ST3_ACTIVE
#   define I_C02_INACTV_SILENT_ACTV_ST3_ACTIVE (2U)
#  endif

#  ifndef I_C02_INACTV_SILENT_ACTV_ST3_SNA
#   define I_C02_INACTV_SILENT_ACTV_ST3_SNA (3U)
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

#  define c02_Off_On_LowerLimit (0U)
#  define c02_Off_On_UpperLimit (3U)

#  define InvalidValue_c02_Off_On (3U)

#  ifndef I_C02_OFF_ON_OFF
#   define I_C02_OFF_ON_OFF (0U)
#  endif

#  ifndef I_C02_OFF_ON_ON
#   define I_C02_OFF_ON_ON (1U)
#  endif

#  ifndef I_C02_OFF_ON_SNA
#   define I_C02_OFF_ON_SNA (3U)
#  endif

#  define c02_Off_Stage1_Stage2_LowerLimit (0U)
#  define c02_Off_Stage1_Stage2_UpperLimit (3U)

#  define InvalidValue_c02_Off_Stage1_Stage2 (3U)

#  ifndef I_C02_OFF_STAGE1_STAGE2_OFF
#   define I_C02_OFF_STAGE1_STAGE2_OFF (0U)
#  endif

#  ifndef I_C02_OFF_STAGE1_STAGE2_STAGE1
#   define I_C02_OFF_STAGE1_STAGE2_STAGE1 (1U)
#  endif

#  ifndef I_C02_OFF_STAGE1_STAGE2_STAGE2
#   define I_C02_OFF_STAGE1_STAGE2_STAGE2 (2U)
#  endif

#  ifndef I_C02_OFF_STAGE1_STAGE2_SNA
#   define I_C02_OFF_STAGE1_STAGE2_SNA (3U)
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

#  define c02_Presf_Disp_Rq_LowerLimit (0U)
#  define c02_Presf_Disp_Rq_UpperLimit (1U)

#  ifndef I_C02_PRESF_DISP_RQ_IDLE
#   define I_C02_PRESF_DISP_RQ_IDLE (0U)
#  endif

#  ifndef I_C02_PRESF_DISP_RQ_SRV_DISP_RQ
#   define I_C02_PRESF_DISP_RQ_SRV_DISP_RQ (1U)
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

#  define c02_TurnIndLvr_Stat_LowerLimit (0U)
#  define c02_TurnIndLvr_Stat_UpperLimit (3U)

#  define InvalidValue_c02_TurnIndLvr_Stat (3U)

#  ifndef I_C02_TURNINDLVR_STAT_IDLE
#   define I_C02_TURNINDLVR_STAT_IDLE (0U)
#  endif

#  ifndef I_C02_TURNINDLVR_STAT_LEFT
#   define I_C02_TURNINDLVR_STAT_LEFT (1U)
#  endif

#  ifndef I_C02_TURNINDLVR_STAT_RIGHT
#   define I_C02_TURNINDLVR_STAT_RIGHT (2U)
#  endif

#  ifndef I_C02_TURNINDLVR_STAT_SNA
#   define I_C02_TURNINDLVR_STAT_SNA (3U)
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

#  define c03_Accel_Md_ST3_LowerLimit (0U)
#  define c03_Accel_Md_ST3_UpperLimit (7U)

#  define InvalidValue_c03_Accel_Md_ST3 (7U)

#  ifndef I_C03_ACCEL_MD_ST3_NORMAL_ACCLRN_MODE
#   define I_C03_ACCEL_MD_ST3_NORMAL_ACCLRN_MODE (0U)
#  endif

#  ifndef I_C03_ACCEL_MD_ST3_OPTMD_FULL_LOAD_WO_OVR_TRQ
#   define I_C03_ACCEL_MD_ST3_OPTMD_FULL_LOAD_WO_OVR_TRQ (1U)
#  endif

#  ifndef I_C03_ACCEL_MD_ST3_OPTMD_FULL_LOAD_WITH_OVR_TRQ
#   define I_C03_ACCEL_MD_ST3_OPTMD_FULL_LOAD_WITH_OVR_TRQ (2U)
#  endif

#  ifndef I_C03_ACCEL_MD_ST3_RACESTRT_PHASE_WO_OVR_TRQ
#   define I_C03_ACCEL_MD_ST3_RACESTRT_PHASE_WO_OVR_TRQ (3U)
#  endif

#  ifndef I_C03_ACCEL_MD_ST3_RACESTRT_PHASE_WITH_OVR_TRQ
#   define I_C03_ACCEL_MD_ST3_RACESTRT_PHASE_WITH_OVR_TRQ (4U)
#  endif

#  ifndef I_C03_ACCEL_MD_ST3_RACESTRT_ACCLN_WO_OVR_TRQ
#   define I_C03_ACCEL_MD_ST3_RACESTRT_ACCLN_WO_OVR_TRQ (5U)
#  endif

#  ifndef I_C03_ACCEL_MD_ST3_RACESTRT_ACCLN_WITH_OVR_TRQ
#   define I_C03_ACCEL_MD_ST3_RACESTRT_ACCLN_WITH_OVR_TRQ (6U)
#  endif

#  ifndef I_C03_ACCEL_MD_ST3_SNA
#   define I_C03_ACCEL_MD_ST3_SNA (7U)
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

#  define c03_MsgTyp_1_to_7_LowerLimit (1U)
#  define c03_MsgTyp_1_to_7_UpperLimit (7U)

#  define InvalidValue_c03_MsgTyp_1_to_7 (7U)

#  ifndef I_C03_MSGTYP_1_TO_7_POSITION
#   define I_C03_MSGTYP_1_TO_7_POSITION (1U)
#  endif

#  ifndef I_C03_MSGTYP_1_TO_7_SEGMENT
#   define I_C03_MSGTYP_1_TO_7_SEGMENT (2U)
#  endif

#  ifndef I_C03_MSGTYP_1_TO_7_STUB
#   define I_C03_MSGTYP_1_TO_7_STUB (3U)
#  endif

#  ifndef I_C03_MSGTYP_1_TO_7_PROFILE_SHORT
#   define I_C03_MSGTYP_1_TO_7_PROFILE_SHORT (4U)
#  endif

#  ifndef I_C03_MSGTYP_1_TO_7_PROFILE_LONG
#   define I_C03_MSGTYP_1_TO_7_PROFILE_LONG (5U)
#  endif

#  ifndef I_C03_MSGTYP_1_TO_7_META_DATA
#   define I_C03_MSGTYP_1_TO_7_META_DATA (6U)
#  endif

#  ifndef I_C03_MSGTYP_1_TO_7_SNA
#   define I_C03_MSGTYP_1_TO_7_SNA (7U)
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

#  define c04_RBTM_ActvClient_LowerLimit (0U)
#  define c04_RBTM_ActvClient_UpperLimit (15U)

#  define InvalidValue_c04_RBTM_ActvClient (15U)

#  ifndef I_C04_RBTM_ACTVCLIENT_NONE
#   define I_C04_RBTM_ACTVCLIENT_NONE (0U)
#  endif

#  ifndef I_C04_RBTM_ACTVCLIENT_PRESAFE
#   define I_C04_RBTM_ACTVCLIENT_PRESAFE (1U)
#  endif

#  ifndef I_C04_RBTM_ACTVCLIENT_POSTCRASH
#   define I_C04_RBTM_ACTVCLIENT_POSTCRASH (2U)
#  endif

#  ifndef I_C04_RBTM_ACTVCLIENT_SERVICE_PROVIDER
#   define I_C04_RBTM_ACTVCLIENT_SERVICE_PROVIDER (3U)
#  endif

#  ifndef I_C04_RBTM_ACTVCLIENT_BELTSLACK_REDUCTION
#   define I_C04_RBTM_ACTVCLIENT_BELTSLACK_REDUCTION (4U)
#  endif

#  ifndef I_C04_RBTM_ACTVCLIENT_BELTPARKING
#   define I_C04_RBTM_ACTVCLIENT_BELTPARKING (5U)
#  endif

#  ifndef I_C04_RBTM_ACTVCLIENT_OTHER
#   define I_C04_RBTM_ACTVCLIENT_OTHER (6U)
#  endif

#  ifndef I_C04_RBTM_ACTVCLIENT_SNA
#   define I_C04_RBTM_ACTVCLIENT_SNA (15U)
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

#  define c05_ADAS_ProfShort_ProfTyp_LowerLimit (1U)
#  define c05_ADAS_ProfShort_ProfTyp_UpperLimit (31U)

#  define InvalidValue_c05_ADAS_ProfShort_ProfTyp (31U)

#  ifndef I_C05_ADAS_PROFSHORT_PROFTYP_CURVATURE_LINEAR
#   define I_C05_ADAS_PROFSHORT_PROFTYP_CURVATURE_LINEAR (1U)
#  endif

#  ifndef I_C05_ADAS_PROFSHORT_PROFTYP_ROUTE_NUMBER_TYPES
#   define I_C05_ADAS_PROFSHORT_PROFTYP_ROUTE_NUMBER_TYPES (2U)
#  endif

#  ifndef I_C05_ADAS_PROFSHORT_PROFTYP_SLOPE_STEP
#   define I_C05_ADAS_PROFSHORT_PROFTYP_SLOPE_STEP (3U)
#  endif

#  ifndef I_C05_ADAS_PROFSHORT_PROFTYP_SLOPE_LINEAR
#   define I_C05_ADAS_PROFSHORT_PROFTYP_SLOPE_LINEAR (4U)
#  endif

#  ifndef I_C05_ADAS_PROFSHORT_PROFTYP_ROAD_ACCESSIBILITY
#   define I_C05_ADAS_PROFSHORT_PROFTYP_ROAD_ACCESSIBILITY (5U)
#  endif

#  ifndef I_C05_ADAS_PROFSHORT_PROFTYP_ROAD_CONDITION
#   define I_C05_ADAS_PROFSHORT_PROFTYP_ROAD_CONDITION (6U)
#  endif

#  ifndef I_C05_ADAS_PROFSHORT_PROFTYP_VARIABLE_SPEED_SIGN_POSITION
#   define I_C05_ADAS_PROFSHORT_PROFTYP_VARIABLE_SPEED_SIGN_POSITION (7U)
#  endif

#  ifndef I_C05_ADAS_PROFSHORT_PROFTYP_HEADING_CHANGE_SPOT
#   define I_C05_ADAS_PROFSHORT_PROFTYP_HEADING_CHANGE_SPOT (8U)
#  endif

#  ifndef I_C05_ADAS_PROFSHORT_PROFTYP_MBC_SLA_LOCATION_TYPE
#   define I_C05_ADAS_PROFSHORT_PROFTYP_MBC_SLA_LOCATION_TYPE (16U)
#  endif

#  ifndef I_C05_ADAS_PROFSHORT_PROFTYP_SNA
#   define I_C05_ADAS_PROFSHORT_PROFTYP_SNA (31U)
#  endif

#  define c05_DPC_Md_PT_HU_LowerLimit (0U)
#  define c05_DPC_Md_PT_HU_UpperLimit (31U)

#  define InvalidValue_c05_DPC_Md_PT_HU (31U)

#  ifndef I_C05_DPC_MD_PT_HU_INIT
#   define I_C05_DPC_MD_PT_HU_INIT (0U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_COMFORT
#   define I_C05_DPC_MD_PT_HU_COMFORT (1U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_ECO
#   define I_C05_DPC_MD_PT_HU_ECO (2U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_SPORT
#   define I_C05_DPC_MD_PT_HU_SPORT (3U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_SPORT_PLUS
#   define I_C05_DPC_MD_PT_HU_SPORT_PLUS (4U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_MANUAL
#   define I_C05_DPC_MD_PT_HU_MANUAL (5U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_OFFROAD1
#   define I_C05_DPC_MD_PT_HU_OFFROAD1 (6U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_OFFROAD2
#   define I_C05_DPC_MD_PT_HU_OFFROAD2 (7U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_EDRIVE
#   define I_C05_DPC_MD_PT_HU_EDRIVE (8U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_RACE
#   define I_C05_DPC_MD_PT_HU_RACE (9U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_BAT_LVL
#   define I_C05_DPC_MD_PT_HU_BAT_LVL (10U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_URBANCRUISEAMG
#   define I_C05_DPC_MD_PT_HU_URBANCRUISEAMG (11U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_ALLROAD
#   define I_C05_DPC_MD_PT_HU_ALLROAD (12U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_MAX_RANGE
#   define I_C05_DPC_MD_PT_HU_MAX_RANGE (13U)
#  endif

#  ifndef I_C05_DPC_MD_PT_HU_SNA
#   define I_C05_DPC_MD_PT_HU_SNA (31U)
#  endif

#  define c06_Idx_0_to_63_1_LowerLimit (0U)
#  define c06_Idx_0_to_63_1_UpperLimit (63U)

#  ifndef I_C06_IDX_0_TO_63_1_UNKNOWN
#   define I_C06_IDX_0_TO_63_1_UNKNOWN (0U)
#  endif

#  ifndef I_C06_IDX_0_TO_63_1_NOT_DIGIT
#   define I_C06_IDX_0_TO_63_1_NOT_DIGIT (1U)
#  endif

#  ifndef I_C06_IDX_0_TO_63_1_NOT_ROAD
#   define I_C06_IDX_0_TO_63_1_NOT_ROAD (2U)
#  endif

#  ifndef I_C06_IDX_0_TO_63_1_NOT_CALIB
#   define I_C06_IDX_0_TO_63_1_NOT_CALIB (3U)
#  endif

#  ifndef I_C06_IDX_0_TO_63_1_CURR_SEG
#   define I_C06_IDX_0_TO_63_1_CURR_SEG (4U)
#  endif

#  ifndef I_C06_IDX_0_TO_63_1_STUB_ONLY
#   define I_C06_IDX_0_TO_63_1_STUB_ONLY (5U)
#  endif

#  ifndef I_C06_IDX_0_TO_63_1_THIS_PATH
#   define I_C06_IDX_0_TO_63_1_THIS_PATH (6U)
#  endif

#  ifndef I_C06_IDX_0_TO_63_1_RES7
#   define I_C06_IDX_0_TO_63_1_RES7 (7U)
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

#  define c06_RBTM_Lvl_Stat_LowerLimit (0U)
#  define c06_RBTM_Lvl_Stat_UpperLimit (63U)

#  define InvalidValue_c06_RBTM_Lvl_Stat (63U)

#  ifndef I_C06_RBTM_LVL_STAT_NONE
#   define I_C06_RBTM_LVL_STAT_NONE (0U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE1
#   define I_C06_RBTM_LVL_STAT_PROFILE1 (1U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE2
#   define I_C06_RBTM_LVL_STAT_PROFILE2 (2U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE3
#   define I_C06_RBTM_LVL_STAT_PROFILE3 (3U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE4
#   define I_C06_RBTM_LVL_STAT_PROFILE4 (4U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE5
#   define I_C06_RBTM_LVL_STAT_PROFILE5 (5U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE6
#   define I_C06_RBTM_LVL_STAT_PROFILE6 (6U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE7
#   define I_C06_RBTM_LVL_STAT_PROFILE7 (7U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE8
#   define I_C06_RBTM_LVL_STAT_PROFILE8 (8U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE9
#   define I_C06_RBTM_LVL_STAT_PROFILE9 (9U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE10
#   define I_C06_RBTM_LVL_STAT_PROFILE10 (10U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE11
#   define I_C06_RBTM_LVL_STAT_PROFILE11 (11U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE12
#   define I_C06_RBTM_LVL_STAT_PROFILE12 (12U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE13
#   define I_C06_RBTM_LVL_STAT_PROFILE13 (13U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE14
#   define I_C06_RBTM_LVL_STAT_PROFILE14 (14U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE15
#   define I_C06_RBTM_LVL_STAT_PROFILE15 (15U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE16
#   define I_C06_RBTM_LVL_STAT_PROFILE16 (16U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE17
#   define I_C06_RBTM_LVL_STAT_PROFILE17 (17U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE18
#   define I_C06_RBTM_LVL_STAT_PROFILE18 (18U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE19
#   define I_C06_RBTM_LVL_STAT_PROFILE19 (19U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE20
#   define I_C06_RBTM_LVL_STAT_PROFILE20 (20U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE21
#   define I_C06_RBTM_LVL_STAT_PROFILE21 (21U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE22
#   define I_C06_RBTM_LVL_STAT_PROFILE22 (22U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE23
#   define I_C06_RBTM_LVL_STAT_PROFILE23 (23U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE24
#   define I_C06_RBTM_LVL_STAT_PROFILE24 (24U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_PROFILE25
#   define I_C06_RBTM_LVL_STAT_PROFILE25 (25U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_REJECTED
#   define I_C06_RBTM_LVL_STAT_REJECTED (62U)
#  endif

#  ifndef I_C06_RBTM_LVL_STAT_SNA
#   define I_C06_RBTM_LVL_STAT_SNA (63U)
#  endif

#  define c08_ROE_0_LowerLimit (0U)
#  define c08_ROE_0_UpperLimit (6U)

#  ifndef I_C08_ROE_0_IDLE
#   define I_C08_ROE_0_IDLE (0U)
#  endif

#  ifndef I_C08_ROE_0_DTC_STATUS_CHANGE
#   define I_C08_ROE_0_DTC_STATUS_CHANGE (1U)
#  endif

#  ifndef I_C08_ROE_0_OBSOLESCENCE_DATA
#   define I_C08_ROE_0_OBSOLESCENCE_DATA (2U)
#  endif

#  ifndef I_C08_ROE_0_CONSUMABLE_DATA
#   define I_C08_ROE_0_CONSUMABLE_DATA (3U)
#  endif

#  ifndef I_C08_ROE_0_AVAILABILITY_DATA
#   define I_C08_ROE_0_AVAILABILITY_DATA (4U)
#  endif

#  ifndef I_C08_ROE_0_DIAG_SESSION_CHANGE
#   define I_C08_ROE_0_DIAG_SESSION_CHANGE (5U)
#  endif

#  ifndef I_C08_ROE_0_SECURITY_EVENT_NOTIFICATION
#   define I_C08_ROE_0_SECURITY_EVENT_NOTIFICATION (6U)
#  endif

#  define c08_km_p_h_0_254_1_LowerLimit (0U)
#  define c08_km_p_h_0_254_1_UpperLimit (255U)

#  define InvalidValue_c08_km_p_h_0_254_1 (255U)

#  ifndef I_C08_KM_P_H_0_254_1_SNA
#   define I_C08_KM_P_H_0_254_1_SNA (255U)
#  endif

#  define c09_m_p_s_m12k8_89k2_0k2_LowerLimit (0U)
#  define c09_m_p_s_m12k8_89k2_0k2_UpperLimit (511U)

#  define InvalidValue_c09_m_p_s_m12k8_89k2_0k2 (511U)

#  ifndef I_C09_M_P_S_M12K8_89K2_0K2_SNA
#   define I_C09_M_P_S_M12K8_89K2_0K2_SNA (511U)
#  endif

#  define c09_ms_0_510_5_LowerLimit (0U)
#  define c09_ms_0_510_5_UpperLimit (511U)

#  define InvalidValue_c09_ms_0_510_5 (511U)

#  ifndef I_C09_MS_0_510_5_OLDER
#   define I_C09_MS_0_510_5_OLDER (510U)
#  endif

#  ifndef I_C09_MS_0_510_5_SNA
#   define I_C09_MS_0_510_5_SNA (511U)
#  endif

#  define c10_ADAS_CountryCode_LowerLimit (0U)
#  define c10_ADAS_CountryCode_UpperLimit (1023U)

#  define InvalidValue_c10_ADAS_CountryCode (1023U)

#  ifndef I_C10_ADAS_COUNTRYCODE_ESC_CODE
#   define I_C10_ADAS_COUNTRYCODE_ESC_CODE (0U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_AFG
#   define I_C10_ADAS_COUNTRYCODE_AFG (4U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ALB
#   define I_C10_ADAS_COUNTRYCODE_ALB (8U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ATA
#   define I_C10_ADAS_COUNTRYCODE_ATA (10U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_DZA
#   define I_C10_ADAS_COUNTRYCODE_DZA (12U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ASM
#   define I_C10_ADAS_COUNTRYCODE_ASM (16U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_AND
#   define I_C10_ADAS_COUNTRYCODE_AND (20U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_AGO
#   define I_C10_ADAS_COUNTRYCODE_AGO (24U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ATG
#   define I_C10_ADAS_COUNTRYCODE_ATG (28U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_AZE
#   define I_C10_ADAS_COUNTRYCODE_AZE (31U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ARG
#   define I_C10_ADAS_COUNTRYCODE_ARG (32U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_AUS
#   define I_C10_ADAS_COUNTRYCODE_AUS (36U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_AUT
#   define I_C10_ADAS_COUNTRYCODE_AUT (40U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BHS
#   define I_C10_ADAS_COUNTRYCODE_BHS (44U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BHR
#   define I_C10_ADAS_COUNTRYCODE_BHR (48U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BGD
#   define I_C10_ADAS_COUNTRYCODE_BGD (50U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ARM
#   define I_C10_ADAS_COUNTRYCODE_ARM (51U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BRB
#   define I_C10_ADAS_COUNTRYCODE_BRB (52U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BEL
#   define I_C10_ADAS_COUNTRYCODE_BEL (56U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BMU
#   define I_C10_ADAS_COUNTRYCODE_BMU (60U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BTN
#   define I_C10_ADAS_COUNTRYCODE_BTN (64U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BOL
#   define I_C10_ADAS_COUNTRYCODE_BOL (68U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BIH
#   define I_C10_ADAS_COUNTRYCODE_BIH (70U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BWA
#   define I_C10_ADAS_COUNTRYCODE_BWA (72U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BVT
#   define I_C10_ADAS_COUNTRYCODE_BVT (74U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BRA
#   define I_C10_ADAS_COUNTRYCODE_BRA (76U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BLZ
#   define I_C10_ADAS_COUNTRYCODE_BLZ (84U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_IOT
#   define I_C10_ADAS_COUNTRYCODE_IOT (86U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SLB
#   define I_C10_ADAS_COUNTRYCODE_SLB (90U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_VGB
#   define I_C10_ADAS_COUNTRYCODE_VGB (92U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BRN
#   define I_C10_ADAS_COUNTRYCODE_BRN (96U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BGR
#   define I_C10_ADAS_COUNTRYCODE_BGR (100U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MMR
#   define I_C10_ADAS_COUNTRYCODE_MMR (104U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BDI
#   define I_C10_ADAS_COUNTRYCODE_BDI (108U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BLR
#   define I_C10_ADAS_COUNTRYCODE_BLR (112U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_KHM
#   define I_C10_ADAS_COUNTRYCODE_KHM (116U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CMR
#   define I_C10_ADAS_COUNTRYCODE_CMR (120U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CAN
#   define I_C10_ADAS_COUNTRYCODE_CAN (124U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CPV
#   define I_C10_ADAS_COUNTRYCODE_CPV (132U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CYM
#   define I_C10_ADAS_COUNTRYCODE_CYM (136U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CAF
#   define I_C10_ADAS_COUNTRYCODE_CAF (140U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_LKA
#   define I_C10_ADAS_COUNTRYCODE_LKA (144U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TCD
#   define I_C10_ADAS_COUNTRYCODE_TCD (148U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CHL
#   define I_C10_ADAS_COUNTRYCODE_CHL (152U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CHN
#   define I_C10_ADAS_COUNTRYCODE_CHN (156U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TWN
#   define I_C10_ADAS_COUNTRYCODE_TWN (158U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CXR
#   define I_C10_ADAS_COUNTRYCODE_CXR (162U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CCK
#   define I_C10_ADAS_COUNTRYCODE_CCK (166U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_COL
#   define I_C10_ADAS_COUNTRYCODE_COL (170U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_COM
#   define I_C10_ADAS_COUNTRYCODE_COM (174U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MYT
#   define I_C10_ADAS_COUNTRYCODE_MYT (175U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_COG
#   define I_C10_ADAS_COUNTRYCODE_COG (178U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_COD
#   define I_C10_ADAS_COUNTRYCODE_COD (180U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_COK
#   define I_C10_ADAS_COUNTRYCODE_COK (184U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CRI
#   define I_C10_ADAS_COUNTRYCODE_CRI (188U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_HRV
#   define I_C10_ADAS_COUNTRYCODE_HRV (191U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CUB
#   define I_C10_ADAS_COUNTRYCODE_CUB (192U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CYP
#   define I_C10_ADAS_COUNTRYCODE_CYP (196U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CZE
#   define I_C10_ADAS_COUNTRYCODE_CZE (203U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BEN
#   define I_C10_ADAS_COUNTRYCODE_BEN (204U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_DNK
#   define I_C10_ADAS_COUNTRYCODE_DNK (208U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_DMA
#   define I_C10_ADAS_COUNTRYCODE_DMA (212U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_DOM
#   define I_C10_ADAS_COUNTRYCODE_DOM (214U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ECU
#   define I_C10_ADAS_COUNTRYCODE_ECU (218U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SLV
#   define I_C10_ADAS_COUNTRYCODE_SLV (222U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GNQ
#   define I_C10_ADAS_COUNTRYCODE_GNQ (226U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ETH
#   define I_C10_ADAS_COUNTRYCODE_ETH (231U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ERI
#   define I_C10_ADAS_COUNTRYCODE_ERI (232U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_EST
#   define I_C10_ADAS_COUNTRYCODE_EST (233U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_FRO
#   define I_C10_ADAS_COUNTRYCODE_FRO (234U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_FLK
#   define I_C10_ADAS_COUNTRYCODE_FLK (238U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SGS
#   define I_C10_ADAS_COUNTRYCODE_SGS (239U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_FJI
#   define I_C10_ADAS_COUNTRYCODE_FJI (242U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_FIN
#   define I_C10_ADAS_COUNTRYCODE_FIN (246U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ALA
#   define I_C10_ADAS_COUNTRYCODE_ALA (248U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_FRA
#   define I_C10_ADAS_COUNTRYCODE_FRA (250U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GUF
#   define I_C10_ADAS_COUNTRYCODE_GUF (254U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_PYF
#   define I_C10_ADAS_COUNTRYCODE_PYF (258U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ATF
#   define I_C10_ADAS_COUNTRYCODE_ATF (260U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_DJI
#   define I_C10_ADAS_COUNTRYCODE_DJI (262U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GAB
#   define I_C10_ADAS_COUNTRYCODE_GAB (266U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GEO
#   define I_C10_ADAS_COUNTRYCODE_GEO (268U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GMB
#   define I_C10_ADAS_COUNTRYCODE_GMB (270U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_PSE
#   define I_C10_ADAS_COUNTRYCODE_PSE (275U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_DEU
#   define I_C10_ADAS_COUNTRYCODE_DEU (276U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GHA
#   define I_C10_ADAS_COUNTRYCODE_GHA (288U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GIB
#   define I_C10_ADAS_COUNTRYCODE_GIB (292U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_KIR
#   define I_C10_ADAS_COUNTRYCODE_KIR (296U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GRC
#   define I_C10_ADAS_COUNTRYCODE_GRC (300U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GRL
#   define I_C10_ADAS_COUNTRYCODE_GRL (304U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GRD
#   define I_C10_ADAS_COUNTRYCODE_GRD (308U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GLP
#   define I_C10_ADAS_COUNTRYCODE_GLP (312U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GUM
#   define I_C10_ADAS_COUNTRYCODE_GUM (316U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GTM
#   define I_C10_ADAS_COUNTRYCODE_GTM (320U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GIN
#   define I_C10_ADAS_COUNTRYCODE_GIN (324U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GUY
#   define I_C10_ADAS_COUNTRYCODE_GUY (328U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_HTI
#   define I_C10_ADAS_COUNTRYCODE_HTI (332U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_HMD
#   define I_C10_ADAS_COUNTRYCODE_HMD (334U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_VAT
#   define I_C10_ADAS_COUNTRYCODE_VAT (336U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_HND
#   define I_C10_ADAS_COUNTRYCODE_HND (340U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_HKG
#   define I_C10_ADAS_COUNTRYCODE_HKG (344U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_HUN
#   define I_C10_ADAS_COUNTRYCODE_HUN (348U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ISL
#   define I_C10_ADAS_COUNTRYCODE_ISL (352U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_IND
#   define I_C10_ADAS_COUNTRYCODE_IND (356U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_IDN
#   define I_C10_ADAS_COUNTRYCODE_IDN (360U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_IRN
#   define I_C10_ADAS_COUNTRYCODE_IRN (364U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_IRQ
#   define I_C10_ADAS_COUNTRYCODE_IRQ (368U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_IRL
#   define I_C10_ADAS_COUNTRYCODE_IRL (372U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ISR
#   define I_C10_ADAS_COUNTRYCODE_ISR (376U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ITA
#   define I_C10_ADAS_COUNTRYCODE_ITA (380U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CIV
#   define I_C10_ADAS_COUNTRYCODE_CIV (384U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_JAM
#   define I_C10_ADAS_COUNTRYCODE_JAM (388U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_JPN
#   define I_C10_ADAS_COUNTRYCODE_JPN (392U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_KAZ
#   define I_C10_ADAS_COUNTRYCODE_KAZ (398U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_JOR
#   define I_C10_ADAS_COUNTRYCODE_JOR (400U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_KEN
#   define I_C10_ADAS_COUNTRYCODE_KEN (404U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_PRK
#   define I_C10_ADAS_COUNTRYCODE_PRK (408U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_KOR
#   define I_C10_ADAS_COUNTRYCODE_KOR (410U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_KWT
#   define I_C10_ADAS_COUNTRYCODE_KWT (414U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_KGZ
#   define I_C10_ADAS_COUNTRYCODE_KGZ (417U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_LAO
#   define I_C10_ADAS_COUNTRYCODE_LAO (418U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_LBN
#   define I_C10_ADAS_COUNTRYCODE_LBN (422U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_LSO
#   define I_C10_ADAS_COUNTRYCODE_LSO (426U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_LVA
#   define I_C10_ADAS_COUNTRYCODE_LVA (428U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_LBR
#   define I_C10_ADAS_COUNTRYCODE_LBR (430U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_LBY
#   define I_C10_ADAS_COUNTRYCODE_LBY (434U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_LIE
#   define I_C10_ADAS_COUNTRYCODE_LIE (438U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_LTU
#   define I_C10_ADAS_COUNTRYCODE_LTU (440U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_LUX
#   define I_C10_ADAS_COUNTRYCODE_LUX (442U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MAC
#   define I_C10_ADAS_COUNTRYCODE_MAC (446U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MDG
#   define I_C10_ADAS_COUNTRYCODE_MDG (450U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MWI
#   define I_C10_ADAS_COUNTRYCODE_MWI (454U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MYS
#   define I_C10_ADAS_COUNTRYCODE_MYS (458U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MDV
#   define I_C10_ADAS_COUNTRYCODE_MDV (462U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MLI
#   define I_C10_ADAS_COUNTRYCODE_MLI (466U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MLT
#   define I_C10_ADAS_COUNTRYCODE_MLT (470U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MTQ
#   define I_C10_ADAS_COUNTRYCODE_MTQ (474U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MRT
#   define I_C10_ADAS_COUNTRYCODE_MRT (478U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MUS
#   define I_C10_ADAS_COUNTRYCODE_MUS (480U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MEX
#   define I_C10_ADAS_COUNTRYCODE_MEX (484U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MCO
#   define I_C10_ADAS_COUNTRYCODE_MCO (492U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MNG
#   define I_C10_ADAS_COUNTRYCODE_MNG (496U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MDA
#   define I_C10_ADAS_COUNTRYCODE_MDA (498U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MNE
#   define I_C10_ADAS_COUNTRYCODE_MNE (499U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MSR
#   define I_C10_ADAS_COUNTRYCODE_MSR (500U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MAR
#   define I_C10_ADAS_COUNTRYCODE_MAR (504U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MOZ
#   define I_C10_ADAS_COUNTRYCODE_MOZ (508U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_OMN
#   define I_C10_ADAS_COUNTRYCODE_OMN (512U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_NAM
#   define I_C10_ADAS_COUNTRYCODE_NAM (516U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_NRU
#   define I_C10_ADAS_COUNTRYCODE_NRU (520U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_NPL
#   define I_C10_ADAS_COUNTRYCODE_NPL (524U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_NLD
#   define I_C10_ADAS_COUNTRYCODE_NLD (528U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ANT
#   define I_C10_ADAS_COUNTRYCODE_ANT (530U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ABW
#   define I_C10_ADAS_COUNTRYCODE_ABW (533U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_NCL
#   define I_C10_ADAS_COUNTRYCODE_NCL (540U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_VUT
#   define I_C10_ADAS_COUNTRYCODE_VUT (548U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_NZL
#   define I_C10_ADAS_COUNTRYCODE_NZL (554U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_NIC
#   define I_C10_ADAS_COUNTRYCODE_NIC (558U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_NER
#   define I_C10_ADAS_COUNTRYCODE_NER (562U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_NGA
#   define I_C10_ADAS_COUNTRYCODE_NGA (566U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_NIU
#   define I_C10_ADAS_COUNTRYCODE_NIU (570U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_NFK
#   define I_C10_ADAS_COUNTRYCODE_NFK (574U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_NOR
#   define I_C10_ADAS_COUNTRYCODE_NOR (578U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MNP
#   define I_C10_ADAS_COUNTRYCODE_MNP (580U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_UMI
#   define I_C10_ADAS_COUNTRYCODE_UMI (581U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_FSM
#   define I_C10_ADAS_COUNTRYCODE_FSM (583U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MHL
#   define I_C10_ADAS_COUNTRYCODE_MHL (584U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_PLW
#   define I_C10_ADAS_COUNTRYCODE_PLW (585U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_PAK
#   define I_C10_ADAS_COUNTRYCODE_PAK (586U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_PAN
#   define I_C10_ADAS_COUNTRYCODE_PAN (591U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_PNG
#   define I_C10_ADAS_COUNTRYCODE_PNG (598U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_PRY
#   define I_C10_ADAS_COUNTRYCODE_PRY (600U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_PER
#   define I_C10_ADAS_COUNTRYCODE_PER (604U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_PHL
#   define I_C10_ADAS_COUNTRYCODE_PHL (608U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_PCN
#   define I_C10_ADAS_COUNTRYCODE_PCN (612U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_POL
#   define I_C10_ADAS_COUNTRYCODE_POL (616U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_PRT
#   define I_C10_ADAS_COUNTRYCODE_PRT (620U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GNB
#   define I_C10_ADAS_COUNTRYCODE_GNB (624U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TLS
#   define I_C10_ADAS_COUNTRYCODE_TLS (626U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_PRI
#   define I_C10_ADAS_COUNTRYCODE_PRI (630U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_QAT
#   define I_C10_ADAS_COUNTRYCODE_QAT (634U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_REU
#   define I_C10_ADAS_COUNTRYCODE_REU (638U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ROU
#   define I_C10_ADAS_COUNTRYCODE_ROU (642U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_RUS
#   define I_C10_ADAS_COUNTRYCODE_RUS (643U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_RWA
#   define I_C10_ADAS_COUNTRYCODE_RWA (646U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SHN
#   define I_C10_ADAS_COUNTRYCODE_SHN (654U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_KNA
#   define I_C10_ADAS_COUNTRYCODE_KNA (659U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_AIA
#   define I_C10_ADAS_COUNTRYCODE_AIA (660U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_LCA
#   define I_C10_ADAS_COUNTRYCODE_LCA (662U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SPM
#   define I_C10_ADAS_COUNTRYCODE_SPM (666U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_VCT
#   define I_C10_ADAS_COUNTRYCODE_VCT (670U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SMR
#   define I_C10_ADAS_COUNTRYCODE_SMR (674U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_STP
#   define I_C10_ADAS_COUNTRYCODE_STP (678U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SAU
#   define I_C10_ADAS_COUNTRYCODE_SAU (682U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SEN
#   define I_C10_ADAS_COUNTRYCODE_SEN (686U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SRB
#   define I_C10_ADAS_COUNTRYCODE_SRB (688U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SYC
#   define I_C10_ADAS_COUNTRYCODE_SYC (690U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SLE
#   define I_C10_ADAS_COUNTRYCODE_SLE (694U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SGP
#   define I_C10_ADAS_COUNTRYCODE_SGP (702U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SVK
#   define I_C10_ADAS_COUNTRYCODE_SVK (703U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_VNM
#   define I_C10_ADAS_COUNTRYCODE_VNM (704U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SVN
#   define I_C10_ADAS_COUNTRYCODE_SVN (705U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SOM
#   define I_C10_ADAS_COUNTRYCODE_SOM (706U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ZAF
#   define I_C10_ADAS_COUNTRYCODE_ZAF (710U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ZWE
#   define I_C10_ADAS_COUNTRYCODE_ZWE (716U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ESP
#   define I_C10_ADAS_COUNTRYCODE_ESP (724U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ESH
#   define I_C10_ADAS_COUNTRYCODE_ESH (732U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SDN
#   define I_C10_ADAS_COUNTRYCODE_SDN (736U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SUR
#   define I_C10_ADAS_COUNTRYCODE_SUR (740U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SJM
#   define I_C10_ADAS_COUNTRYCODE_SJM (744U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SWZ
#   define I_C10_ADAS_COUNTRYCODE_SWZ (748U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SWE
#   define I_C10_ADAS_COUNTRYCODE_SWE (752U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_CHE
#   define I_C10_ADAS_COUNTRYCODE_CHE (756U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SYR
#   define I_C10_ADAS_COUNTRYCODE_SYR (760U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TJK
#   define I_C10_ADAS_COUNTRYCODE_TJK (762U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_THA
#   define I_C10_ADAS_COUNTRYCODE_THA (764U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TGO
#   define I_C10_ADAS_COUNTRYCODE_TGO (768U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TKL
#   define I_C10_ADAS_COUNTRYCODE_TKL (772U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TON
#   define I_C10_ADAS_COUNTRYCODE_TON (776U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TTO
#   define I_C10_ADAS_COUNTRYCODE_TTO (780U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ARE
#   define I_C10_ADAS_COUNTRYCODE_ARE (784U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TUN
#   define I_C10_ADAS_COUNTRYCODE_TUN (788U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TUR
#   define I_C10_ADAS_COUNTRYCODE_TUR (792U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TKM
#   define I_C10_ADAS_COUNTRYCODE_TKM (795U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TCA
#   define I_C10_ADAS_COUNTRYCODE_TCA (796U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TUV
#   define I_C10_ADAS_COUNTRYCODE_TUV (798U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_UGA
#   define I_C10_ADAS_COUNTRYCODE_UGA (800U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_UKR
#   define I_C10_ADAS_COUNTRYCODE_UKR (804U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_MKD
#   define I_C10_ADAS_COUNTRYCODE_MKD (807U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_EGY
#   define I_C10_ADAS_COUNTRYCODE_EGY (818U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GBR
#   define I_C10_ADAS_COUNTRYCODE_GBR (826U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_GGY
#   define I_C10_ADAS_COUNTRYCODE_GGY (831U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_JEY
#   define I_C10_ADAS_COUNTRYCODE_JEY (832U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_IMN
#   define I_C10_ADAS_COUNTRYCODE_IMN (833U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_TZA
#   define I_C10_ADAS_COUNTRYCODE_TZA (834U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_USA
#   define I_C10_ADAS_COUNTRYCODE_USA (840U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_VIR
#   define I_C10_ADAS_COUNTRYCODE_VIR (850U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_BFA
#   define I_C10_ADAS_COUNTRYCODE_BFA (854U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_URY
#   define I_C10_ADAS_COUNTRYCODE_URY (858U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_UZB
#   define I_C10_ADAS_COUNTRYCODE_UZB (860U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_VEN
#   define I_C10_ADAS_COUNTRYCODE_VEN (862U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_WLF
#   define I_C10_ADAS_COUNTRYCODE_WLF (876U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_WSM
#   define I_C10_ADAS_COUNTRYCODE_WSM (882U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_YEM
#   define I_C10_ADAS_COUNTRYCODE_YEM (887U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_ZMB
#   define I_C10_ADAS_COUNTRYCODE_ZMB (894U)
#  endif

#  ifndef I_C10_ADAS_COUNTRYCODE_SNA
#   define I_C10_ADAS_COUNTRYCODE_SNA (1023U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Seatbelt_not_buckled_FALSE
#   define c10_RBTM_Fct_Precond_Seatbelt_not_buckled_FALSE (0U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Seatbelt_not_buckled_BflMask
#   define c10_RBTM_Fct_Precond_Seatbelt_not_buckled_BflMask 1U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Seatbelt_not_buckled_BflPn
#   define c10_RBTM_Fct_Precond_Seatbelt_not_buckled_BflPn 0U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Seatbelt_not_buckled_BflLn
#   define c10_RBTM_Fct_Precond_Seatbelt_not_buckled_BflLn 1U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Seatbelt_not_buckled_TRUE
#   define c10_RBTM_Fct_Precond_Seatbelt_not_buckled_TRUE (1U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Seatbelt_Handover_extended_FALSE
#   define c10_RBTM_Fct_Precond_Seatbelt_Handover_extended_FALSE (0U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Seatbelt_Handover_extended_BflMask
#   define c10_RBTM_Fct_Precond_Seatbelt_Handover_extended_BflMask 2U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Seatbelt_Handover_extended_BflPn
#   define c10_RBTM_Fct_Precond_Seatbelt_Handover_extended_BflPn 1U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Seatbelt_Handover_extended_BflLn
#   define c10_RBTM_Fct_Precond_Seatbelt_Handover_extended_BflLn 1U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Seatbelt_Handover_extended_TRUE
#   define c10_RBTM_Fct_Precond_Seatbelt_Handover_extended_TRUE (2U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Overtemperature_FALSE
#   define c10_RBTM_Fct_Precond_Overtemperature_FALSE (0U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Overtemperature_BflMask
#   define c10_RBTM_Fct_Precond_Overtemperature_BflMask 4U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Overtemperature_BflPn
#   define c10_RBTM_Fct_Precond_Overtemperature_BflPn 2U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Overtemperature_BflLn
#   define c10_RBTM_Fct_Precond_Overtemperature_BflLn 1U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Overtemperature_TRUE
#   define c10_RBTM_Fct_Precond_Overtemperature_TRUE (4U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Internal_failure_FALSE
#   define c10_RBTM_Fct_Precond_Internal_failure_FALSE (0U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Internal_failure_BflMask
#   define c10_RBTM_Fct_Precond_Internal_failure_BflMask 8U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Internal_failure_BflPn
#   define c10_RBTM_Fct_Precond_Internal_failure_BflPn 3U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Internal_failure_BflLn
#   define c10_RBTM_Fct_Precond_Internal_failure_BflLn 1U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Internal_failure_TRUE
#   define c10_RBTM_Fct_Precond_Internal_failure_TRUE (8U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Under_overvoltage_FALSE
#   define c10_RBTM_Fct_Precond_Under_overvoltage_FALSE (0U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Under_overvoltage_BflMask
#   define c10_RBTM_Fct_Precond_Under_overvoltage_BflMask 16U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Under_overvoltage_BflPn
#   define c10_RBTM_Fct_Precond_Under_overvoltage_BflPn 4U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Under_overvoltage_BflLn
#   define c10_RBTM_Fct_Precond_Under_overvoltage_BflLn 1U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Under_overvoltage_TRUE
#   define c10_RBTM_Fct_Precond_Under_overvoltage_TRUE (16U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Communication_error_FALSE
#   define c10_RBTM_Fct_Precond_Communication_error_FALSE (0U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Communication_error_BflMask
#   define c10_RBTM_Fct_Precond_Communication_error_BflMask 32U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Communication_error_BflPn
#   define c10_RBTM_Fct_Precond_Communication_error_BflPn 5U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Communication_error_BflLn
#   define c10_RBTM_Fct_Precond_Communication_error_BflLn 1U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Communication_error_TRUE
#   define c10_RBTM_Fct_Precond_Communication_error_TRUE (32U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Profile_not_available_FALSE
#   define c10_RBTM_Fct_Precond_Profile_not_available_FALSE (0U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Profile_not_available_BflMask
#   define c10_RBTM_Fct_Precond_Profile_not_available_BflMask 64U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Profile_not_available_BflPn
#   define c10_RBTM_Fct_Precond_Profile_not_available_BflPn 6U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Profile_not_available_BflLn
#   define c10_RBTM_Fct_Precond_Profile_not_available_BflLn 1U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Profile_not_available_TRUE
#   define c10_RBTM_Fct_Precond_Profile_not_available_TRUE (64U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Other_FALSE
#   define c10_RBTM_Fct_Precond_Other_FALSE (0U)
#  endif

#  ifndef c10_RBTM_Fct_Precond_Other_BflMask
#   define c10_RBTM_Fct_Precond_Other_BflMask 128U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Other_BflPn
#   define c10_RBTM_Fct_Precond_Other_BflPn 7U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Other_BflLn
#   define c10_RBTM_Fct_Precond_Other_BflLn 1U
#  endif

#  ifndef c10_RBTM_Fct_Precond_Other_TRUE
#   define c10_RBTM_Fct_Precond_Other_TRUE (128U)
#  endif

#  define c10_V_0_25k55_0k025_LowerLimit (0U)
#  define c10_V_0_25k55_0k025_UpperLimit (1023U)

#  define InvalidValue_c10_V_0_25k55_0k025 (1023U)

#  ifndef I_C10_V_0_25K55_0K025_SNA
#   define I_C10_V_0_25K55_0K025_SNA (1023U)
#  endif

#  define c10_WakeupRsn_ST3_LowerLimit (0U)
#  define c10_WakeupRsn_ST3_UpperLimit (1023U)

#  define InvalidValue_c10_WakeupRsn_ST3 (1023U)

#  ifndef I_C10_WAKEUPRSN_ST3_NETWORK
#   define I_C10_WAKEUPRSN_ST3_NETWORK (0U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_MAIN
#   define I_C10_WAKEUPRSN_ST3_NW_MAIN (1U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_HEADUNIT1
#   define I_C10_WAKEUPRSN_ST3_NW_HEADUNIT1 (11U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_HEADUNIT2
#   define I_C10_WAKEUPRSN_ST3_NW_HEADUNIT2 (12U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_PERIPHERY
#   define I_C10_WAKEUPRSN_ST3_NW_PERIPHERY (13U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_BODY1
#   define I_C10_WAKEUPRSN_ST3_NW_BODY1 (14U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_CHASSIS
#   define I_C10_WAKEUPRSN_ST3_NW_CHASSIS (15U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_RADAR_R
#   define I_C10_WAKEUPRSN_ST3_NW_RADAR_R (16U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_RADAR_F
#   define I_C10_WAKEUPRSN_ST3_NW_RADAR_F (17U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_OBD_PTI
#   define I_C10_WAKEUPRSN_ST3_NW_OBD_PTI (18U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_STEERING_WHEEL
#   define I_C10_WAKEUPRSN_ST3_NW_STEERING_WHEEL (19U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_CPC
#   define I_C10_WAKEUPRSN_ST3_NW_CPC (20U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_ECM
#   define I_C10_WAKEUPRSN_ST3_NW_ECM (21U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_ENERGY
#   define I_C10_WAKEUPRSN_ST3_NW_ENERGY (22U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_INV
#   define I_C10_WAKEUPRSN_ST3_NW_INV (23U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_TCM
#   define I_C10_WAKEUPRSN_ST3_NW_TCM (24U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_AEPU
#   define I_C10_WAKEUPRSN_ST3_NW_AEPU (25U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_BODY2
#   define I_C10_WAKEUPRSN_ST3_NW_BODY2 (26U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_BODY3
#   define I_C10_WAKEUPRSN_ST3_NW_BODY3 (27U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_CAL_COC
#   define I_C10_WAKEUPRSN_ST3_NW_CAL_COC (28U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_CAL_DL
#   define I_C10_WAKEUPRSN_ST3_NW_CAL_DL (29U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_CAL_DR
#   define I_C10_WAKEUPRSN_ST3_NW_CAL_DR (30U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_ECM_PERIPHERY1
#   define I_C10_WAKEUPRSN_ST3_NW_ECM_PERIPHERY1 (31U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_ECM_PERIPHERY2
#   define I_C10_WAKEUPRSN_ST3_NW_ECM_PERIPHERY2 (32U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_ENGINE_PT3
#   define I_C10_WAKEUPRSN_ST3_NW_ENGINE_PT3 (33U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_HAD_BACKUP
#   define I_C10_WAKEUPRSN_ST3_NW_HAD_BACKUP (34U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_HYBRID_PT3
#   define I_C10_WAKEUPRSN_ST3_NW_HYBRID_PT3 (35U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_LSM_F
#   define I_C10_WAKEUPRSN_ST3_NW_LSM_F (36U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_POWERTRAIN_PT3
#   define I_C10_WAKEUPRSN_ST3_NW_POWERTRAIN_PT3 (37U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_PT_SENSOR_PT3
#   define I_C10_WAKEUPRSN_ST3_NW_PT_SENSOR_PT3 (38U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_RVC_HSVL
#   define I_C10_WAKEUPRSN_ST3_NW_RVC_HSVL (39U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_SPV
#   define I_C10_WAKEUPRSN_ST3_NW_SPV (40U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_SUSPENSION_F
#   define I_C10_WAKEUPRSN_ST3_NW_SUSPENSION_F (41U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_SUSPENSION_R
#   define I_C10_WAKEUPRSN_ST3_NW_SUSPENSION_R (42U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_EIS_BASE_GW
#   define I_C10_WAKEUPRSN_ST3_NW_EIS_BASE_GW (43U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_EIS_GW_BASE
#   define I_C10_WAKEUPRSN_ST3_NW_EIS_GW_BASE (44U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_AUXILIARY1
#   define I_C10_WAKEUPRSN_ST3_NW_AUXILIARY1 (45U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_AUXILIARY2
#   define I_C10_WAKEUPRSN_ST3_NW_AUXILIARY2 (46U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_DRIVE_UNIT
#   define I_C10_WAKEUPRSN_ST3_NW_DRIVE_UNIT (47U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_INLET
#   define I_C10_WAKEUPRSN_ST3_NW_INLET (48U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_BODY4
#   define I_C10_WAKEUPRSN_ST3_NW_BODY4 (49U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_DRIVING
#   define I_C10_WAKEUPRSN_ST3_NW_DRIVING (50U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_EDS1
#   define I_C10_WAKEUPRSN_ST3_NW_EDS1 (51U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_EDS2
#   define I_C10_WAKEUPRSN_ST3_NW_EDS2 (52U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_HAD_IMU
#   define I_C10_WAKEUPRSN_ST3_NW_HAD_IMU (53U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_MULTIPURPOSE
#   define I_C10_WAKEUPRSN_ST3_NW_MULTIPURPOSE (54U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_PERIPHERY2
#   define I_C10_WAKEUPRSN_ST3_NW_PERIPHERY2 (55U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_SUSPENSION_AMG
#   define I_C10_WAKEUPRSN_ST3_NW_SUSPENSION_AMG (56U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NW_BMS_SENSOR
#   define I_C10_WAKEUPRSN_ST3_NW_BMS_SENSOR (57U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_HVAC_F
#   define I_C10_WAKEUPRSN_ST3_LIN_HVAC_F (115U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_HVAC_R
#   define I_C10_WAKEUPRSN_ST3_LIN_HVAC_R (116U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_VCS
#   define I_C10_WAKEUPRSN_ST3_LIN_VCS (117U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_WPRA
#   define I_C10_WAKEUPRSN_ST3_LIN_WPRA (118U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_IHTM_RC
#   define I_C10_WAKEUPRSN_ST3_LIN_IHTM_RC (119U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_PTC48_R
#   define I_C10_WAKEUPRSN_ST3_LIN_PTC48_R (120U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_AQS
#   define I_C10_WAKEUPRSN_ST3_LIN_AQS (121U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_ECP2_1
#   define I_C10_WAKEUPRSN_ST3_LIN_ECP2_1 (122U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_EXV1
#   define I_C10_WAKEUPRSN_ST3_LIN_EXV1 (123U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_IHTM
#   define I_C10_WAKEUPRSN_ST3_LIN_IHTM (124U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_EAC
#   define I_C10_WAKEUPRSN_ST3_LIN_EAC (125U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_EAC48
#   define I_C10_WAKEUPRSN_ST3_LIN_EAC48 (126U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_PTC_HV
#   define I_C10_WAKEUPRSN_ST3_LIN_PTC_HV (127U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_TERM_15
#   define I_C10_WAKEUPRSN_ST3_TERM_15 (128U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_SBW_LVR_PSD
#   define I_C10_WAKEUPRSN_ST3_SBW_LVR_PSD (129U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_TERM_54
#   define I_C10_WAKEUPRSN_ST3_TERM_54 (130U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_HFA
#   define I_C10_WAKEUPRSN_ST3_LIN_HFA (131U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_IBS
#   define I_C10_WAKEUPRSN_ST3_LIN_IBS (132U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_DOOR_HANDLE
#   define I_C10_WAKEUPRSN_ST3_LIN_DOOR_HANDLE (133U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_LISB48
#   define I_C10_WAKEUPRSN_ST3_LIN_LISB48 (134U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CMN_ECU_RST_POR
#   define I_C10_WAKEUPRSN_ST3_CMN_ECU_RST_POR (135U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CMN_ECU_RST_DIAG
#   define I_C10_WAKEUPRSN_ST3_CMN_ECU_RST_DIAG (136U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CMN_ECU_RST_TEST
#   define I_C10_WAKEUPRSN_ST3_CMN_ECU_RST_TEST (137U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CMN_ECU_RST_ERR
#   define I_C10_WAKEUPRSN_ST3_CMN_ECU_RST_ERR (138U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CMN_ETH_WAKEUPLINE
#   define I_C10_WAKEUPRSN_ST3_CMN_ETH_WAKEUPLINE (139U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CMN_AFTERRUN
#   define I_C10_WAKEUPRSN_ST3_CMN_AFTERRUN (140U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CRASH
#   define I_C10_WAKEUPRSN_ST3_CRASH (141U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_VCI
#   define I_C10_WAKEUPRSN_ST3_LIN_VCI (142U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_LIN_CIS
#   define I_C10_WAKEUPRSN_ST3_LIN_CIS (143U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_HANDLE_TAG2
#   define I_C10_WAKEUPRSN_ST3_HANDLE_TAG2 (150U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_DAC_MOBILE
#   define I_C10_WAKEUPRSN_ST3_DAC_MOBILE (151U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_EASY_ENTRY_ACTV
#   define I_C10_WAKEUPRSN_ST3_EASY_ENTRY_ACTV (181U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_ERR_SEAT_HTVN
#   define I_C10_WAKEUPRSN_ST3_ERR_SEAT_HTVN (183U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_ERR_SEAT_CHM
#   define I_C10_WAKEUPRSN_ST3_ERR_SEAT_CHM (184U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_VEHSL_EVENT
#   define I_C10_WAKEUPRSN_ST3_VEHSL_EVENT (199U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_RLS
#   define I_C10_WAKEUPRSN_ST3_RLS (200U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_EF_KEY
#   define I_C10_WAKEUPRSN_ST3_EF_KEY (201U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_RHU_FT
#   define I_C10_WAKEUPRSN_ST3_RHU_FT (202U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_RHU_R
#   define I_C10_WAKEUPRSN_ST3_RHU_R (203U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_ICH_RQ
#   define I_C10_WAKEUPRSN_ST3_ICH_RQ (204U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_VPRZR_VN
#   define I_C10_WAKEUPRSN_ST3_VPRZR_VN (205U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PRECON
#   define I_C10_WAKEUPRSN_ST3_PRECON (206U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_SOL_VN
#   define I_C10_WAKEUPRSN_ST3_SOL_VN (207U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_EXTLGT_ACTV
#   define I_C10_WAKEUPRSN_ST3_EXTLGT_ACTV (208U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_INTLGT_ACTV
#   define I_C10_WAKEUPRSN_ST3_INTLGT_ACTV (209U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_TSSR_ACTV
#   define I_C10_WAKEUPRSN_ST3_TSSR_ACTV (210U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_SEAT_HT_F_ACTV
#   define I_C10_WAKEUPRSN_ST3_SEAT_HT_F_ACTV (211U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_SEAT_HT_R_ACTV
#   define I_C10_WAKEUPRSN_ST3_SEAT_HT_R_ACTV (212U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_SEAT_VN_F_ACTV
#   define I_C10_WAKEUPRSN_ST3_SEAT_VN_F_ACTV (213U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_SEAT_VN_R_ACTV
#   define I_C10_WAKEUPRSN_ST3_SEAT_VN_R_ACTV (214U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_EHS_3S
#   define I_C10_WAKEUPRSN_ST3_EHS_3S (215U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_T58D_POTI
#   define I_C10_WAKEUPRSN_ST3_T58D_POTI (216U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_DRB
#   define I_C10_WAKEUPRSN_ST3_DRB (217U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BKRST_UNLK_RM
#   define I_C10_WAKEUPRSN_ST3_BKRST_UNLK_RM (218U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_DL_SW2_PSD
#   define I_C10_WAKEUPRSN_ST3_DL_SW2_PSD (219U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_DL_SW
#   define I_C10_WAKEUPRSN_ST3_DL_SW (220U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BGC_SW
#   define I_C10_WAKEUPRSN_ST3_BGC_SW (221U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BKRST_RL_LK_UNLK
#   define I_C10_WAKEUPRSN_ST3_BKRST_RL_LK_UNLK (222U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BKRST_RR_LK_UNLK
#   define I_C10_WAKEUPRSN_ST3_BKRST_RR_LK_UNLK (223U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_DL_CLS_LK_SW
#   define I_C10_WAKEUPRSN_ST3_DL_CLS_LK_SW (224U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_DL_RLTCH
#   define I_C10_WAKEUPRSN_ST3_DL_RLTCH (225U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BKRST_3L_LK_UNLK
#   define I_C10_WAKEUPRSN_ST3_BKRST_3L_LK_UNLK (226U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BKRST_3R_LK_UNLK
#   define I_C10_WAKEUPRSN_ST3_BKRST_3R_LK_UNLK (227U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_GAS_DR_SW
#   define I_C10_WAKEUPRSN_ST3_GAS_DR_SW (228U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_AILCF
#   define I_C10_WAKEUPRSN_ST3_AILCF (229U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_AILCC
#   define I_C10_WAKEUPRSN_ST3_AILCC (230U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_FRONT_TRUNK_SWITCH
#   define I_C10_WAKEUPRSN_ST3_FRONT_TRUNK_SWITCH (250U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_FRONT_TRUNK_LATCH_PRSD
#   define I_C10_WAKEUPRSN_ST3_FRONT_TRUNK_LATCH_PRSD (251U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BIG_FLIP_WNDW_SWITCH
#   define I_C10_WAKEUPRSN_ST3_BIG_FLIP_WNDW_SWITCH (252U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BIG_FLIP_WNDW_STATE
#   define I_C10_WAKEUPRSN_ST3_BIG_FLIP_WNDW_STATE (253U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_TRLR_ELEC_ACT
#   define I_C10_WAKEUPRSN_ST3_TRLR_ELEC_ACT (256U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_TRLR_DET
#   define I_C10_WAKEUPRSN_ST3_TRLR_DET (257U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_DL_LK
#   define I_C10_WAKEUPRSN_ST3_DL_LK (258U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_START_SW_PSD
#   define I_C10_WAKEUPRSN_ST3_START_SW_PSD (259U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_RADIO_DATA
#   define I_C10_WAKEUPRSN_ST3_RADIO_DATA (260U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_RLTCH_DR
#   define I_C10_WAKEUPRSN_ST3_RLTCH_DR (261U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PKBRKSW
#   define I_C10_WAKEUPRSN_ST3_PKBRKSW (263U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_KEYLESS_GO
#   define I_C10_WAKEUPRSN_ST3_KEYLESS_GO (264U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PNM12
#   define I_C10_WAKEUPRSN_ST3_PNM12 (265U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PNM48
#   define I_C10_WAKEUPRSN_ST3_PNM48 (266U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BAT48_LOWCHARGE
#   define I_C10_WAKEUPRSN_ST3_BAT48_LOWCHARGE (267U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PN14_IODM
#   define I_C10_WAKEUPRSN_ST3_PN14_IODM (270U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PN14_REMSRV_STAT
#   define I_C10_WAKEUPRSN_ST3_PN14_REMSRV_STAT (271U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PN14_DDP
#   define I_C10_WAKEUPRSN_ST3_PN14_DDP (272U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PN14_LOWCHARGE
#   define I_C10_WAKEUPRSN_ST3_PN14_LOWCHARGE (273U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PN14_REMODHV12V
#   define I_C10_WAKEUPRSN_ST3_PN14_REMODHV12V (274U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PN14_DLM
#   define I_C10_WAKEUPRSN_ST3_PN14_DLM (275U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_SDC_PN2_LOWCHARGE
#   define I_C10_WAKEUPRSN_ST3_SDC_PN2_LOWCHARGE (276U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_SDC_PN2_REMODHV12V
#   define I_C10_WAKEUPRSN_ST3_SDC_PN2_REMODHV12V (277U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PN14_REM_ENGINE_START
#   define I_C10_WAKEUPRSN_ST3_PN14_REM_ENGINE_START (278U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_DATA_EXCHG
#   define I_C10_WAKEUPRSN_ST3_DATA_EXCHG (280U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_INTERNET_CON
#   define I_C10_WAKEUPRSN_ST3_INTERNET_CON (281U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CMN_USER_DATA
#   define I_C10_WAKEUPRSN_ST3_CMN_USER_DATA (282U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CMN_SERV_LOCAL
#   define I_C10_WAKEUPRSN_ST3_CMN_SERV_LOCAL (290U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CMN_SERV_REM
#   define I_C10_WAKEUPRSN_ST3_CMN_SERV_REM (291U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_VEH_REAR_LOWERING
#   define I_C10_WAKEUPRSN_ST3_VEH_REAR_LOWERING (292U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CMN_BTN_PSD
#   define I_C10_WAKEUPRSN_ST3_CMN_BTN_PSD (300U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_FLAP_PSD
#   define I_C10_WAKEUPRSN_ST3_FLAP_PSD (301U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CHADEMO
#   define I_C10_WAKEUPRSN_ST3_CHADEMO (302U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_GBT
#   define I_C10_WAKEUPRSN_ST3_GBT (303U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CMN_PROXIMITY
#   define I_C10_WAKEUPRSN_ST3_CMN_PROXIMITY (304U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CTRL_PILOT
#   define I_C10_WAKEUPRSN_ST3_CTRL_PILOT (305U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CMN_HV_DET
#   define I_C10_WAKEUPRSN_ST3_CMN_HV_DET (306U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CMN_CHRG_TMR
#   define I_C10_WAKEUPRSN_ST3_CMN_CHRG_TMR (307U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_TRCT_BAT_OP_STRATEGY
#   define I_C10_WAKEUPRSN_ST3_TRCT_BAT_OP_STRATEGY (308U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_VTA
#   define I_C10_WAKEUPRSN_ST3_VTA (309U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PDD
#   define I_C10_WAKEUPRSN_ST3_PDD (310U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_UNEQUAL_STRING_VOLT
#   define I_C10_WAKEUPRSN_ST3_UNEQUAL_STRING_VOLT (311U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_MUTE_ACTV
#   define I_C10_WAKEUPRSN_ST3_MUTE_ACTV (312U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_VIDEO_RQ
#   define I_C10_WAKEUPRSN_ST3_VIDEO_RQ (313U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_ALARM_ACTV
#   define I_C10_WAKEUPRSN_ST3_ALARM_ACTV (314U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_RECIRC_AIR_RQ
#   define I_C10_WAKEUPRSN_ST3_RECIRC_AIR_RQ (315U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_TPM_SYNC
#   define I_C10_WAKEUPRSN_ST3_TPM_SYNC (316U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_DI_DISP_RQ
#   define I_C10_WAKEUPRSN_ST3_DI_DISP_RQ (320U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_DI_IND_RQ
#   define I_C10_WAKEUPRSN_ST3_DI_IND_RQ (321U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_HUD_RQ
#   define I_C10_WAKEUPRSN_ST3_HUD_RQ (322U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_ON_KEY
#   define I_C10_WAKEUPRSN_ST3_ON_KEY (323U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_MSG_DISP_RQ
#   define I_C10_WAKEUPRSN_ST3_MSG_DISP_RQ (325U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_ROOF_LMP_ON_RQ
#   define I_C10_WAKEUPRSN_ST3_ROOF_LMP_ON_RQ (326U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_IL_ON_RQ
#   define I_C10_WAKEUPRSN_ST3_IL_ON_RQ (327U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_SPS_APPL
#   define I_C10_WAKEUPRSN_ST3_SPS_APPL (328U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PWC_WRAPPER
#   define I_C10_WAKEUPRSN_ST3_PWC_WRAPPER (330U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PW_SW
#   define I_C10_WAKEUPRSN_ST3_PW_SW (331U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CLKS_SW
#   define I_C10_WAKEUPRSN_ST3_CLKS_SW (332U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_SEAT_SW
#   define I_C10_WAKEUPRSN_ST3_SEAT_SW (333U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_DL_REM_SW
#   define I_C10_WAKEUPRSN_ST3_DL_REM_SW (334U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_TANK_UNLK_SW
#   define I_C10_WAKEUPRSN_ST3_TANK_UNLK_SW (335U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_SLTCH_DR
#   define I_C10_WAKEUPRSN_ST3_SLTCH_DR (336U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_INSRLVR_SW
#   define I_C10_WAKEUPRSN_ST3_INSRLVR_SW (337U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_OUTSRLVR_SW
#   define I_C10_WAKEUPRSN_ST3_OUTSRLVR_SW (338U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_TRL_HTCH_SW
#   define I_C10_WAKEUPRSN_ST3_TRL_HTCH_SW (339U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_TSSR_R_RB_SW
#   define I_C10_WAKEUPRSN_ST3_TSSR_R_RB_SW (340U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CSL_SW
#   define I_C10_WAKEUPRSN_ST3_CSL_SW (341U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_GEAR_SW
#   define I_C10_WAKEUPRSN_ST3_GEAR_SW (342U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_AD_SW
#   define I_C10_WAKEUPRSN_ST3_AD_SW (343U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_T2R_SW
#   define I_C10_WAKEUPRSN_ST3_T2R_SW (344U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_HV_INTERLOCK_ERR
#   define I_C10_WAKEUPRSN_ST3_HV_INTERLOCK_ERR (345U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_NFC
#   define I_C10_WAKEUPRSN_ST3_NFC (346U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_POLLING
#   define I_C10_WAKEUPRSN_ST3_POLLING (347U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_TSL_P_PSD
#   define I_C10_WAKEUPRSN_ST3_TSL_P_PSD (348U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_STWHL_LVR_PSD
#   define I_C10_WAKEUPRSN_ST3_STWHL_LVR_PSD (349U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BAT14_DDP
#   define I_C10_WAKEUPRSN_ST3_BAT14_DDP (350U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BAT14_LOWCHARGE
#   define I_C10_WAKEUPRSN_ST3_BAT14_LOWCHARGE (351U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BAT14_CHARGECURR
#   define I_C10_WAKEUPRSN_ST3_BAT14_CHARGECURR (352U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BAT14_IODM
#   define I_C10_WAKEUPRSN_ST3_BAT14_IODM (353U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BAT14_IODAVG
#   define I_C10_WAKEUPRSN_ST3_BAT14_IODAVG (354U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BMS_TMR
#   define I_C10_WAKEUPRSN_ST3_BMS_TMR (355U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CPD
#   define I_C10_WAKEUPRSN_ST3_CPD (356U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BMS_TP_EVENT
#   define I_C10_WAKEUPRSN_ST3_BMS_TP_EVENT (357U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BMS_TEMP_CHANGE
#   define I_C10_WAKEUPRSN_ST3_BMS_TEMP_CHANGE (358U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BMS_CHARGE_OVER_MAX_OCV
#   define I_C10_WAKEUPRSN_ST3_BMS_CHARGE_OVER_MAX_OCV (359U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BRK_PDL
#   define I_C10_WAKEUPRSN_ST3_BRK_PDL (360U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_VEPM_TMR
#   define I_C10_WAKEUPRSN_ST3_VEPM_TMR (361U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PNM_TMR
#   define I_C10_WAKEUPRSN_ST3_PNM_TMR (362U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BAT14_PREOPEN
#   define I_C10_WAKEUPRSN_ST3_BAT14_PREOPEN (363U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BAT14_HIGHCHARGE
#   define I_C10_WAKEUPRSN_ST3_BAT14_HIGHCHARGE (364U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BAT14_FULLCHRGEMG
#   define I_C10_WAKEUPRSN_ST3_BAT14_FULLCHRGEMG (365U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_BAT14_CTREMG
#   define I_C10_WAKEUPRSN_ST3_BAT14_CTREMG (366U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PNSEC
#   define I_C10_WAKEUPRSN_ST3_PNSEC (380U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PNSEC_BCM
#   define I_C10_WAKEUPRSN_ST3_PNSEC_BCM (381U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PNSEC_DCDCCTRL
#   define I_C10_WAKEUPRSN_ST3_PNSEC_DCDCCTRL (382U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PNSEC_DDP
#   define I_C10_WAKEUPRSN_ST3_PNSEC_DDP (383U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_PNSEC_ICC
#   define I_C10_WAKEUPRSN_ST3_PNSEC_ICC (384U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_DEPTM_TMR
#   define I_C10_WAKEUPRSN_ST3_DEPTM_TMR (385U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CNM_ETH_WAKEUPLINE_CS
#   define I_C10_WAKEUPRSN_ST3_CNM_ETH_WAKEUPLINE_CS (390U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_CNM_DIAGNOSTIC_ETH_ACT_LINE
#   define I_C10_WAKEUPRSN_ST3_CNM_DIAGNOSTIC_ETH_ACT_LINE (391U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_FOTA_TMR
#   define I_C10_WAKEUPRSN_ST3_FOTA_TMR (400U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_RESERVE_3
#   define I_C10_WAKEUPRSN_ST3_RESERVE_3 (1020U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_RESERVE_2
#   define I_C10_WAKEUPRSN_ST3_RESERVE_2 (1021U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_RESERVE_1
#   define I_C10_WAKEUPRSN_ST3_RESERVE_1 (1022U)
#  endif

#  ifndef I_C10_WAKEUPRSN_ST3_SNA
#   define I_C10_WAKEUPRSN_ST3_SNA (1023U)
#  endif

#  define c10_m_0_510_1_LowerLimit (0U)
#  define c10_m_0_510_1_UpperLimit (1023U)

#  define InvalidValue_c10_m_0_510_1 (1023U)

#  ifndef I_C10_M_0_510_1_SNA
#   define I_C10_M_0_510_1_SNA (1023U)
#  endif

#  define c10_to_1022_1_LowerLimit (0U)
#  define c10_to_1022_1_UpperLimit (1023U)

#  define InvalidValue_c10_to_1022_1 (1023U)

#  ifndef I_C10_TO_1022_1_SNA
#   define I_C10_TO_1022_1_SNA (1023U)
#  endif

#  define c12_0_4094_1_SNA_LowerLimit (0U)
#  define c12_0_4094_1_SNA_UpperLimit (4095U)

#  define InvalidValue_c12_0_4094_1_SNA (4095U)

#  ifndef I_C12_0_4094_1_SNA_SNA
#   define I_C12_0_4094_1_SNA_SNA (4095U)
#  endif

#  define c12_km_p_h_0_409k4_0k1_LowerLimit (0U)
#  define c12_km_p_h_0_409k4_0k1_UpperLimit (4095U)

#  define InvalidValue_c12_km_p_h_0_409k4_0k1 (4095U)

#  ifndef I_C12_KM_P_H_0_409K4_0K1_SNA
#   define I_C12_KM_P_H_0_409K4_0K1_SNA (4095U)
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

#  define c13_m_0_8190_1_LowerLimit (0U)
#  define c13_m_0_8190_1_UpperLimit (8191U)

#  define InvalidValue_c13_m_0_8190_1 (8191U)

#  ifndef I_C13_M_0_8190_1_SNA
#   define I_C13_M_0_8190_1_SNA (8191U)
#  endif

#  define c15_ADAS_RegionCode_LowerLimit (0U)
#  define c15_ADAS_RegionCode_UpperLimit (32767U)

#  define InvalidValue_c15_ADAS_RegionCode (32767U)

#  ifndef I_C15_ADAS_REGIONCODE_UNKWN
#   define I_C15_ADAS_REGIONCODE_UNKWN (0U)
#  endif

#  ifndef I_C15_ADAS_REGIONCODE_SNA
#   define I_C15_ADAS_REGIONCODE_SNA (32767U)
#  endif

#  define c24_km_0_999999k9_0k1_Invld_SNA_LowerLimit (0U)
#  define c24_km_0_999999k9_0k1_Invld_SNA_UpperLimit (16777215U)

#  define InvalidValue_c24_km_0_999999k9_0k1_Invld_SNA (16777215U)

#  ifndef I_C24_KM_0_999999K9_0K1_INVLD_SNA_INVLD
#   define I_C24_KM_0_999999K9_0K1_INVLD_SNA_INVLD (16777214U)
#  endif

#  ifndef I_C24_KM_0_999999K9_0K1_INVLD_SNA_SNA
#   define I_C24_KM_0_999999K9_0K1_INVLD_SNA_SNA (16777215U)
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


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_CommunicationMode
#  define RTE_MODETYPE_CommunicationMode
typedef uint8 Rte_ModeType_CommunicationMode;
# endif
# ifndef RTE_MODETYPE_DcmEcuReset
#  define RTE_MODETYPE_DcmEcuReset
typedef uint8 Rte_ModeType_DcmEcuReset;
# endif

# define RTE_MODE_DiagFunction_CommunicationMode_COMM_NO_COMMUNICATION (0U)
# ifndef RTE_MODE_CommunicationMode_COMM_NO_COMMUNICATION
#  define RTE_MODE_CommunicationMode_COMM_NO_COMMUNICATION (0U)
# endif
# define RTE_MODE_DiagFunction_CommunicationMode_COMM_SILENT_COMMUNICATION (1U)
# ifndef RTE_MODE_CommunicationMode_COMM_SILENT_COMMUNICATION
#  define RTE_MODE_CommunicationMode_COMM_SILENT_COMMUNICATION (1U)
# endif
# define RTE_MODE_DiagFunction_CommunicationMode_COMM_FULL_COMMUNICATION (2U)
# ifndef RTE_MODE_CommunicationMode_COMM_FULL_COMMUNICATION
#  define RTE_MODE_CommunicationMode_COMM_FULL_COMMUNICATION (2U)
# endif
# define RTE_TRANSITION_DiagFunction_CommunicationMode (3U)
# ifndef RTE_TRANSITION_CommunicationMode
#  define RTE_TRANSITION_CommunicationMode (3U)
# endif

# define RTE_MODE_DiagFunction_DcmEcuReset_NONE (0U)
# ifndef RTE_MODE_DcmEcuReset_NONE
#  define RTE_MODE_DcmEcuReset_NONE (0U)
# endif
# define RTE_MODE_DiagFunction_DcmEcuReset_HARD (1U)
# ifndef RTE_MODE_DcmEcuReset_HARD
#  define RTE_MODE_DcmEcuReset_HARD (1U)
# endif
# define RTE_MODE_DiagFunction_DcmEcuReset_KEYONOFF (2U)
# ifndef RTE_MODE_DcmEcuReset_KEYONOFF
#  define RTE_MODE_DcmEcuReset_KEYONOFF (2U)
# endif
# define RTE_MODE_DiagFunction_DcmEcuReset_SOFT (3U)
# ifndef RTE_MODE_DcmEcuReset_SOFT
#  define RTE_MODE_DcmEcuReset_SOFT (3U)
# endif
# define RTE_MODE_DiagFunction_DcmEcuReset_JUMPTOBOOTLOADER (4U)
# ifndef RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
#  define RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER (4U)
# endif
# define RTE_MODE_DiagFunction_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER (5U)
# ifndef RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
#  define RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER (5U)
# endif
# define RTE_MODE_DiagFunction_DcmEcuReset_EXECUTE (6U)
# ifndef RTE_MODE_DcmEcuReset_EXECUTE
#  define RTE_MODE_DcmEcuReset_EXECUTE (6U)
# endif
# define RTE_TRANSITION_DiagFunction_DcmEcuReset (7U)
# ifndef RTE_TRANSITION_DcmEcuReset
#  define RTE_TRANSITION_DcmEcuReset (7U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_DIAGFUNCTION_TYPE_H */
