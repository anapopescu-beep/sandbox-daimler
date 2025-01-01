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
 *             File:  Rte_Ct_MBBL_ResetPreconditionChecker_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application types header file for SW-C <Ct_MBBL_ResetPreconditionChecker>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CT_MBBL_RESETPRECONDITIONCHECKER_TYPE_H
# define RTE_CT_MBBL_RESETPRECONDITIONCHECKER_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  define Rsrv01_LowerLimit (0U)
#  define Rsrv01_UpperLimit (1U)

#  define InvalidValue_Rsrv01 (1U)

#  define Rsrv02_LowerLimit (0U)
#  define Rsrv02_UpperLimit (3U)

#  define InvalidValue_Rsrv02 (3U)

#  define Rsrv04_LowerLimit (0U)
#  define Rsrv04_UpperLimit (15U)

#  define InvalidValue_Rsrv04 (15U)

#  define Rsrv05_LowerLimit (0U)
#  define Rsrv05_UpperLimit (31U)

#  define InvalidValue_Rsrv05 (31U)

#  define Rsrv08_LowerLimit (0U)
#  define Rsrv08_UpperLimit (255U)

#  define InvalidValue_Rsrv08 (255U)

#  define Rsrv24_LowerLimit (0U)
#  define Rsrv24_UpperLimit (16777215U)

#  define InvalidValue_Rsrv24 (16777215U)

#  define Rsrv27_LowerLimit (0U)
#  define Rsrv27_UpperLimit (134217727U)

#  define InvalidValue_Rsrv27 (134217727U)

#  define c02_0_3_1_nSNA_LowerLimit (0U)
#  define c02_0_3_1_nSNA_UpperLimit (3U)

#  define c02_ADAS_MapVerQuar_LowerLimit (0U)
#  define c02_ADAS_MapVerQuar_UpperLimit (3U)

#  define InvalidValue_c02_Navi_MPP_ResetRsn_ST3 (3U)

#  define c03_0_to_7_1_no_SNA_LowerLimit (0U)
#  define c03_0_to_7_1_no_SNA_UpperLimit (7U)

#  define c03_ADAS_Posn_Idx_LowerLimit (0U)
#  define c03_ADAS_Posn_Idx_UpperLimit (3U)

#  define c04_0_15_1_SNA_na_LowerLimit (0U)
#  define c04_0_15_1_SNA_na_UpperLimit (15U)

#  define InvalidValue_c07_0_111_1_SNA (127U)

#  define InvalidValue_c08_0_254_1_SNA_255 (255U)

#  define c08_0_255_1_SNA_na_LowerLimit (0U)
#  define c08_0_255_1_SNA_na_UpperLimit (255U)

#  define c08_UInt_SNA_na_LowerLimit (0U)
#  define c08_UInt_SNA_na_UpperLimit (255U)

#  define InvalidValue_c08_degC_m40_85_0k5 (255U)

#  define InvalidValue_c08_km_p_h_0_250_1_Blank (255U)

#  define InvalidValue_c08_m_1d6_2d87_0d005 (255U)

#  define InvalidValue_c13_A_m409k6_409k4_0k1 (8191U)

#  define c16_CRC_woSNA_LowerLimit (0U)
#  define c16_CRC_woSNA_UpperLimit (65535U)

#  define cDC_tickCount_ST3_LowerLimit (0ULL)
#  define cDC_tickCount_ST3_UpperLimit (18446744073709551615ULL)

#  define UInt16_Appl_LowerLimit (0U)
#  define UInt16_Appl_UpperLimit (65535U)

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

#  define c01_FalseTrue_LowerLimit (0U)
#  define c01_FalseTrue_UpperLimit (1U)

#  ifndef I_C01_FALSETRUE_FALSE
#   define I_C01_FALSETRUE_FALSE (0U)
#  endif

#  ifndef I_C01_FALSETRUE_TRUE
#   define I_C01_FALSETRUE_TRUE (1U)
#  endif

#  define c01_Right_Left_LowerLimit (0U)
#  define c01_Right_Left_UpperLimit (1U)

#  ifndef I_C01_RIGHT_LEFT_LHD
#   define I_C01_RIGHT_LEFT_LHD (0U)
#  endif

#  ifndef I_C01_RIGHT_LEFT_RHD
#   define I_C01_RIGHT_LEFT_RHD (1U)
#  endif

#  define c01_UnitVehSpd_LowerLimit (0U)
#  define c01_UnitVehSpd_UpperLimit (1U)

#  ifndef I_C01_UNITVEHSPD_KMH
#   define I_C01_UNITVEHSPD_KMH (0U)
#  endif

#  ifndef I_C01_UNITVEHSPD_MPH
#   define I_C01_UNITVEHSPD_MPH (1U)
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

#  define c02_DPC_Md_SSA_LowerLimit (1U)
#  define c02_DPC_Md_SSA_UpperLimit (3U)

#  define InvalidValue_c02_DPC_Md_SSA (3U)

#  ifndef I_C02_DPC_MD_SSA_SSA_ON
#   define I_C02_DPC_MD_SSA_SSA_ON (1U)
#  endif

#  ifndef I_C02_DPC_MD_SSA_SSA_OFF
#   define I_C02_DPC_MD_SSA_SSA_OFF (2U)
#  endif

#  ifndef I_C02_DPC_MD_SSA_SNA
#   define I_C02_DPC_MD_SSA_SNA (3U)
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

#  define c02_HiBmLvr_Stat_LowerLimit (0U)
#  define c02_HiBmLvr_Stat_UpperLimit (3U)

#  define InvalidValue_c02_HiBmLvr_Stat (3U)

#  ifndef I_C02_HIBMLVR_STAT_IDLE
#   define I_C02_HIBMLVR_STAT_IDLE (0U)
#  endif

#  ifndef I_C02_HIBMLVR_STAT_HIBM_ON_PSD
#   define I_C02_HIBMLVR_STAT_HIBM_ON_PSD (1U)
#  endif

#  ifndef I_C02_HIBMLVR_STAT_HIBM_FLSH_ON_PSD
#   define I_C02_HIBMLVR_STAT_HIBM_FLSH_ON_PSD (2U)
#  endif

#  ifndef I_C02_HIBMLVR_STAT_SNA
#   define I_C02_HIBMLVR_STAT_SNA (3U)
#  endif

#  define c02_Inact_Act_ST3_LowerLimit (0U)
#  define c02_Inact_Act_ST3_UpperLimit (3U)

#  define InvalidValue_c02_Inact_Act_ST3 (3U)

#  ifndef I_C02_INACT_ACT_ST3_INACTIVE
#   define I_C02_INACT_ACT_ST3_INACTIVE (0U)
#  endif

#  ifndef I_C02_INACT_ACT_ST3_ACTIVE
#   define I_C02_INACT_ACT_ST3_ACTIVE (1U)
#  endif

#  ifndef I_C02_INACT_ACT_ST3_SNA
#   define I_C02_INACT_ACT_ST3_SNA (3U)
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

#  define c02_NDef_ECO_Comfort_LowerLimit (1U)
#  define c02_NDef_ECO_Comfort_UpperLimit (3U)

#  define InvalidValue_c02_NDef_ECO_Comfort (3U)

#  ifndef I_C02_NDEF_ECO_COMFORT_ECO
#   define I_C02_NDEF_ECO_COMFORT_ECO (1U)
#  endif

#  ifndef I_C02_NDEF_ECO_COMFORT_COMFORT
#   define I_C02_NDEF_ECO_COMFORT_COMFORT (2U)
#  endif

#  ifndef I_C02_NDEF_ECO_COMFORT_SNA
#   define I_C02_NDEF_ECO_COMFORT_SNA (3U)
#  endif

#  define c02_NDef_Off_On_ST3_LowerLimit (1U)
#  define c02_NDef_Off_On_ST3_UpperLimit (3U)

#  define InvalidValue_c02_NDef_Off_On_ST3 (3U)

#  ifndef I_C02_NDEF_OFF_ON_ST3_OFF
#   define I_C02_NDEF_OFF_ON_ST3_OFF (1U)
#  endif

#  ifndef I_C02_NDEF_OFF_ON_ST3_ON
#   define I_C02_NDEF_OFF_ON_ST3_ON (2U)
#  endif

#  ifndef I_C02_NDEF_OFF_ON_ST3_SNA
#   define I_C02_NDEF_OFF_ON_ST3_SNA (3U)
#  endif

#  define c02_NDef_On_Off_LowerLimit (1U)
#  define c02_NDef_On_Off_UpperLimit (3U)

#  define InvalidValue_c02_NDef_On_Off (3U)

#  ifndef I_C02_NDEF_ON_OFF_ON
#   define I_C02_NDEF_ON_OFF_ON (1U)
#  endif

#  ifndef I_C02_NDEF_ON_OFF_OFF
#   define I_C02_NDEF_ON_OFF_OFF (2U)
#  endif

#  ifndef I_C02_NDEF_ON_OFF_SNA
#   define I_C02_NDEF_ON_OFF_SNA (3U)
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

#  define c02_SSA_Standby_Stat_LowerLimit (0U)
#  define c02_SSA_Standby_Stat_UpperLimit (3U)

#  define InvalidValue_c02_SSA_Standby_Stat (3U)

#  ifndef I_C02_SSA_STANDBY_STAT_IDLE
#   define I_C02_SSA_STANDBY_STAT_IDLE (0U)
#  endif

#  ifndef I_C02_SSA_STANDBY_STAT_STANDBY_MD_ACTV
#   define I_C02_SSA_STANDBY_STAT_STANDBY_MD_ACTV (1U)
#  endif

#  ifndef I_C02_SSA_STANDBY_STAT_STANDBY_MD_PSV
#   define I_C02_SSA_STANDBY_STAT_STANDBY_MD_PSV (2U)
#  endif

#  ifndef I_C02_SSA_STANDBY_STAT_SNA
#   define I_C02_SSA_STANDBY_STAT_SNA (3U)
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

#  define c02_TxBurnOut_Stat_LowerLimit (0U)
#  define c02_TxBurnOut_Stat_UpperLimit (3U)

#  ifndef I_C02_TXBURNOUT_STAT_INACTIVE
#   define I_C02_TXBURNOUT_STAT_INACTIVE (0U)
#  endif

#  ifndef I_C02_TXBURNOUT_STAT_ENBL
#   define I_C02_TXBURNOUT_STAT_ENBL (1U)
#  endif

#  ifndef I_C02_TXBURNOUT_STAT_ACTIVE
#   define I_C02_TXBURNOUT_STAT_ACTIVE (2U)
#  endif

#  ifndef I_C02_TXBURNOUT_STAT_ABORT
#   define I_C02_TXBURNOUT_STAT_ABORT (3U)
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

#  define c03_0_6_1_LowerLimit (0U)
#  define c03_0_6_1_UpperLimit (7U)

#  define InvalidValue_c03_0_6_1 (7U)

#  ifndef I_C03_0_6_1_SNA
#   define I_C03_0_6_1_SNA (7U)
#  endif

#  define c03_ADAS_MapProvid_LowerLimit (0U)
#  define c03_ADAS_MapProvid_UpperLimit (7U)

#  define InvalidValue_c03_ADAS_MapProvid (7U)

#  ifndef I_C03_ADAS_MAPPROVID_UNKNOWN
#   define I_C03_ADAS_MAPPROVID_UNKNOWN (0U)
#  endif

#  ifndef I_C03_ADAS_MAPPROVID_NAVTEQ
#   define I_C03_ADAS_MAPPROVID_NAVTEQ (1U)
#  endif

#  ifndef I_C03_ADAS_MAPPROVID_TELEATLAS
#   define I_C03_ADAS_MAPPROVID_TELEATLAS (2U)
#  endif

#  ifndef I_C03_ADAS_MAPPROVID_ZENRIN
#   define I_C03_ADAS_MAPPROVID_ZENRIN (3U)
#  endif

#  ifndef I_C03_ADAS_MAPPROVID_IPC
#   define I_C03_ADAS_MAPPROVID_IPC (4U)
#  endif

#  ifndef I_C03_ADAS_MAPPROVID_NAVINFO
#   define I_C03_ADAS_MAPPROVID_NAVINFO (5U)
#  endif

#  ifndef I_C03_ADAS_MAPPROVID_OTHER
#   define I_C03_ADAS_MAPPROVID_OTHER (6U)
#  endif

#  ifndef I_C03_ADAS_MAPPROVID_SNA
#   define I_C03_ADAS_MAPPROVID_SNA (7U)
#  endif

#  define c03_ADAS_Posn_CurLane_LowerLimit (0U)
#  define c03_ADAS_Posn_CurLane_UpperLimit (7U)

#  define InvalidValue_c03_ADAS_Posn_CurLane (7U)

#  ifndef I_C03_ADAS_POSN_CURLANE_UNKWN
#   define I_C03_ADAS_POSN_CURLANE_UNKWN (0U)
#  endif

#  ifndef I_C03_ADAS_POSN_CURLANE_EMG_L
#   define I_C03_ADAS_POSN_CURLANE_EMG_L (1U)
#  endif

#  ifndef I_C03_ADAS_POSN_CURLANE_SINGLE_L
#   define I_C03_ADAS_POSN_CURLANE_SINGLE_L (2U)
#  endif

#  ifndef I_C03_ADAS_POSN_CURLANE_LM_L
#   define I_C03_ADAS_POSN_CURLANE_LM_L (3U)
#  endif

#  ifndef I_C03_ADAS_POSN_CURLANE_RM_L
#   define I_C03_ADAS_POSN_CURLANE_RM_L (4U)
#  endif

#  ifndef I_C03_ADAS_POSN_CURLANE_MID_L
#   define I_C03_ADAS_POSN_CURLANE_MID_L (5U)
#  endif

#  ifndef I_C03_ADAS_POSN_CURLANE_RES
#   define I_C03_ADAS_POSN_CURLANE_RES (6U)
#  endif

#  ifndef I_C03_ADAS_POSN_CURLANE_SNA
#   define I_C03_ADAS_POSN_CURLANE_SNA (7U)
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

#  define c03_DCDCBuckSuprtStat_ST3_LowerLimit (0U)
#  define c03_DCDCBuckSuprtStat_ST3_UpperLimit (7U)

#  define InvalidValue_c03_DCDCBuckSuprtStat_ST3 (7U)

#  ifndef I_C03_DCDCBUCKSUPRTSTAT_ST3_NO_DCDC
#   define I_C03_DCDCBUCKSUPRTSTAT_ST3_NO_DCDC (0U)
#  endif

#  ifndef I_C03_DCDCBUCKSUPRTSTAT_ST3_DCDC_BUCKSUPRT_ACTV
#   define I_C03_DCDCBUCKSUPRTSTAT_ST3_DCDC_BUCKSUPRT_ACTV (1U)
#  endif

#  ifndef I_C03_DCDCBUCKSUPRTSTAT_ST3_DCDC_BUCKSUPRT_STOP
#   define I_C03_DCDCBUCKSUPRTSTAT_ST3_DCDC_BUCKSUPRT_STOP (2U)
#  endif

#  ifndef I_C03_DCDCBUCKSUPRTSTAT_ST3_SNA
#   define I_C03_DCDCBUCKSUPRTSTAT_ST3_SNA (7U)
#  endif

#  define c03_DPC_Md_ExhaustFlap_LowerLimit (1U)
#  define c03_DPC_Md_ExhaustFlap_UpperLimit (7U)

#  define InvalidValue_c03_DPC_Md_ExhaustFlap (7U)

#  ifndef I_C03_DPC_MD_EXHAUSTFLAP_COMFORT
#   define I_C03_DPC_MD_EXHAUSTFLAP_COMFORT (1U)
#  endif

#  ifndef I_C03_DPC_MD_EXHAUSTFLAP_SPORT
#   define I_C03_DPC_MD_EXHAUSTFLAP_SPORT (2U)
#  endif

#  ifndef I_C03_DPC_MD_EXHAUSTFLAP_SPORTPLUS
#   define I_C03_DPC_MD_EXHAUSTFLAP_SPORTPLUS (3U)
#  endif

#  ifndef I_C03_DPC_MD_EXHAUSTFLAP_RACE
#   define I_C03_DPC_MD_EXHAUSTFLAP_RACE (4U)
#  endif

#  ifndef I_C03_DPC_MD_EXHAUSTFLAP_SNA
#   define I_C03_DPC_MD_EXHAUSTFLAP_SNA (7U)
#  endif

#  define c03_DPC_Md_St_LowerLimit (1U)
#  define c03_DPC_Md_St_UpperLimit (7U)

#  define InvalidValue_c03_DPC_Md_St (7U)

#  ifndef I_C03_DPC_MD_ST_COMFORT
#   define I_C03_DPC_MD_ST_COMFORT (1U)
#  endif

#  ifndef I_C03_DPC_MD_ST_SPORT
#   define I_C03_DPC_MD_ST_SPORT (2U)
#  endif

#  ifndef I_C03_DPC_MD_ST_SPORTPLUS
#   define I_C03_DPC_MD_ST_SPORTPLUS (3U)
#  endif

#  ifndef I_C03_DPC_MD_ST_OFFROAD
#   define I_C03_DPC_MD_ST_OFFROAD (4U)
#  endif

#  ifndef I_C03_DPC_MD_ST_SNA
#   define I_C03_DPC_MD_ST_SNA (7U)
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

#  define c03_VehPos_ST3_LowerLimit (0U)
#  define c03_VehPos_ST3_UpperLimit (7U)

#  define InvalidValue_c03_VehPos_ST3 (7U)

#  ifndef I_C03_VEHPOS_ST3_VEHPOSI_UNKNOWN
#   define I_C03_VEHPOS_ST3_VEHPOSI_UNKNOWN (0U)
#  endif

#  ifndef I_C03_VEHPOS_ST3_VEHPOSI_ROOF
#   define I_C03_VEHPOS_ST3_VEHPOSI_ROOF (1U)
#  endif

#  ifndef I_C03_VEHPOS_ST3_VEHPOSI_SIDE_LEFT
#   define I_C03_VEHPOS_ST3_VEHPOSI_SIDE_LEFT (2U)
#  endif

#  ifndef I_C03_VEHPOS_ST3_VEHPOSI_SIDE_RIGHT
#   define I_C03_VEHPOS_ST3_VEHPOSI_SIDE_RIGHT (3U)
#  endif

#  ifndef I_C03_VEHPOS_ST3_SNA
#   define I_C03_VEHPOS_ST3_SNA (7U)
#  endif

#  define c03_m2_p3_1_Init_LowerLimit (0U)
#  define c03_m2_p3_1_Init_UpperLimit (7U)

#  define InvalidValue_c03_m2_p3_1_Init (7U)

#  ifndef I_C03_M2_P3_1_INIT_INIT
#   define I_C03_M2_P3_1_INIT_INIT (0U)
#  endif

#  ifndef I_C03_M2_P3_1_INIT_SNA
#   define I_C03_M2_P3_1_INIT_SNA (7U)
#  endif

#  define c04_DPC_GlobalMd_Rq_LowerLimit (0U)
#  define c04_DPC_GlobalMd_Rq_UpperLimit (15U)

#  define InvalidValue_c04_DPC_GlobalMd_Rq (15U)

#  ifndef I_C04_DPC_GLOBALMD_RQ_COMFORT
#   define I_C04_DPC_GLOBALMD_RQ_COMFORT (0U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_SPORT
#   define I_C04_DPC_GLOBALMD_RQ_SPORT (1U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_SPORT_PLUS
#   define I_C04_DPC_GLOBALMD_RQ_SPORT_PLUS (2U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_ALLROAD
#   define I_C04_DPC_GLOBALMD_RQ_ALLROAD (3U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_ECO
#   define I_C04_DPC_GLOBALMD_RQ_ECO (4U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_INDIVIDUAL
#   define I_C04_DPC_GLOBALMD_RQ_INDIVIDUAL (5U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_MANUAL
#   define I_C04_DPC_GLOBALMD_RQ_MANUAL (6U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_CURVEURBANCRUISEAMG
#   define I_C04_DPC_GLOBALMD_RQ_CURVEURBANCRUISEAMG (7U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_SLIPPERY_WET
#   define I_C04_DPC_GLOBALMD_RQ_SLIPPERY_WET (8U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_TERRAIN
#   define I_C04_DPC_GLOBALMD_RQ_TERRAIN (9U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_UPHILL
#   define I_C04_DPC_GLOBALMD_RQ_UPHILL (10U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_TRAILER
#   define I_C04_DPC_GLOBALMD_RQ_TRAILER (11U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_ROCKING_FREE
#   define I_C04_DPC_GLOBALMD_RQ_ROCKING_FREE (12U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_TERRAIN_PLUS
#   define I_C04_DPC_GLOBALMD_RQ_TERRAIN_PLUS (13U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_NO_DPC
#   define I_C04_DPC_GLOBALMD_RQ_NO_DPC (14U)
#  endif

#  ifndef I_C04_DPC_GLOBALMD_RQ_SNA
#   define I_C04_DPC_GLOBALMD_RQ_SNA (15U)
#  endif

#  define c04_DPC_Md_ESP_Rq_ST3_LowerLimit (0U)
#  define c04_DPC_Md_ESP_Rq_ST3_UpperLimit (15U)

#  define InvalidValue_c04_DPC_Md_ESP_Rq_ST3 (15U)

#  ifndef I_C04_DPC_MD_ESP_RQ_ST3_INIT
#   define I_C04_DPC_MD_ESP_RQ_ST3_INIT (0U)
#  endif

#  ifndef I_C04_DPC_MD_ESP_RQ_ST3_COMFORT
#   define I_C04_DPC_MD_ESP_RQ_ST3_COMFORT (1U)
#  endif

#  ifndef I_C04_DPC_MD_ESP_RQ_ST3_SPORT
#   define I_C04_DPC_MD_ESP_RQ_ST3_SPORT (2U)
#  endif

#  ifndef I_C04_DPC_MD_ESP_RQ_ST3_OFF
#   define I_C04_DPC_MD_ESP_RQ_ST3_OFF (3U)
#  endif

#  ifndef I_C04_DPC_MD_ESP_RQ_ST3_SPORT_PLUS
#   define I_C04_DPC_MD_ESP_RQ_ST3_SPORT_PLUS (4U)
#  endif

#  ifndef I_C04_DPC_MD_ESP_RQ_ST3_OFFROAD
#   define I_C04_DPC_MD_ESP_RQ_ST3_OFFROAD (5U)
#  endif

#  ifndef I_C04_DPC_MD_ESP_RQ_ST3_OFFROAD_PLUS
#   define I_C04_DPC_MD_ESP_RQ_ST3_OFFROAD_PLUS (6U)
#  endif

#  ifndef I_C04_DPC_MD_ESP_RQ_ST3_SNOW
#   define I_C04_DPC_MD_ESP_RQ_ST3_SNOW (7U)
#  endif

#  ifndef I_C04_DPC_MD_ESP_RQ_ST3_SNA
#   define I_C04_DPC_MD_ESP_RQ_ST3_SNA (15U)
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

#  define c04_EVC_HL_Style_ST3_LowerLimit (0U)
#  define c04_EVC_HL_Style_ST3_UpperLimit (15U)

#  ifndef I_C04_EVC_HL_STYLE_ST3_LED_STAT_LHT
#   define I_C04_EVC_HL_STYLE_ST3_LED_STAT_LHT (0U)
#  endif

#  ifndef I_C04_EVC_HL_STYLE_ST3_LED_STAT_RHT
#   define I_C04_EVC_HL_STYLE_ST3_LED_STAT_RHT (1U)
#  endif

#  ifndef I_C04_EVC_HL_STYLE_ST3_LED_DYN_SAE_RHT
#   define I_C04_EVC_HL_STYLE_ST3_LED_DYN_SAE_RHT (2U)
#  endif

#  ifndef I_C04_EVC_HL_STYLE_ST3_LED_DYN_LHT
#   define I_C04_EVC_HL_STYLE_ST3_LED_DYN_LHT (3U)
#  endif

#  ifndef I_C04_EVC_HL_STYLE_ST3_LED_DYN_RHT
#   define I_C04_EVC_HL_STYLE_ST3_LED_DYN_RHT (4U)
#  endif

#  ifndef I_C04_EVC_HL_STYLE_ST3_HEADLIGHT_LHT
#   define I_C04_EVC_HL_STYLE_ST3_HEADLIGHT_LHT (5U)
#  endif

#  ifndef I_C04_EVC_HL_STYLE_ST3_HEADLIGHT_RHT
#   define I_C04_EVC_HL_STYLE_ST3_HEADLIGHT_RHT (6U)
#  endif

#  ifndef I_C04_EVC_HL_STYLE_ST3_DIGITAL_SAE_RHT
#   define I_C04_EVC_HL_STYLE_ST3_DIGITAL_SAE_RHT (7U)
#  endif

#  ifndef I_C04_EVC_HL_STYLE_ST3_DIGITAL_LHT
#   define I_C04_EVC_HL_STYLE_ST3_DIGITAL_LHT (8U)
#  endif

#  ifndef I_C04_EVC_HL_STYLE_ST3_DIGITAL_RHT
#   define I_C04_EVC_HL_STYLE_ST3_DIGITAL_RHT (9U)
#  endif

#  ifndef I_C04_EVC_HL_STYLE_ST3_OTHER
#   define I_C04_EVC_HL_STYLE_ST3_OTHER (15U)
#  endif

#  define c04_EVC_TxStyle_ST3_LowerLimit (0U)
#  define c04_EVC_TxStyle_ST3_UpperLimit (15U)

#  ifndef I_C04_EVC_TXSTYLE_ST3_MANUAL_6
#   define I_C04_EVC_TXSTYLE_ST3_MANUAL_6 (0U)
#  endif

#  ifndef I_C04_EVC_TXSTYLE_ST3_AUTOM_7
#   define I_C04_EVC_TXSTYLE_ST3_AUTOM_7 (2U)
#  endif

#  ifndef I_C04_EVC_TXSTYLE_ST3_AUTOM_9
#   define I_C04_EVC_TXSTYLE_ST3_AUTOM_9 (3U)
#  endif

#  ifndef I_C04_EVC_TXSTYLE_ST3_MANUAL_6_NSG2
#   define I_C04_EVC_TXSTYLE_ST3_MANUAL_6_NSG2 (4U)
#  endif

#  ifndef I_C04_EVC_TXSTYLE_ST3_AUTOM_7_DCT
#   define I_C04_EVC_TXSTYLE_ST3_AUTOM_7_DCT (5U)
#  endif

#  ifndef I_C04_EVC_TXSTYLE_ST3_AUTOM_9_DCT
#   define I_C04_EVC_TXSTYLE_ST3_AUTOM_9_DCT (6U)
#  endif

#  ifndef I_C04_EVC_TXSTYLE_ST3_E_DRIVE
#   define I_C04_EVC_TXSTYLE_ST3_E_DRIVE (7U)
#  endif

#  ifndef I_C04_EVC_TXSTYLE_ST3_OTHER
#   define I_C04_EVC_TXSTYLE_ST3_OTHER (15U)
#  endif

#  define c04_EVC_YrOfModf_1_ST3_LowerLimit (0U)
#  define c04_EVC_YrOfModf_1_ST3_UpperLimit (15U)

#  ifndef I_C04_EVC_YROFMODF_1_ST3_YOM800
#   define I_C04_EVC_YROFMODF_1_ST3_YOM800 (0U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_1_ST3_YOM801
#   define I_C04_EVC_YROFMODF_1_ST3_YOM801 (1U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_1_ST3_YOM802
#   define I_C04_EVC_YROFMODF_1_ST3_YOM802 (2U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_1_ST3_YOM803
#   define I_C04_EVC_YROFMODF_1_ST3_YOM803 (3U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_1_ST3_YOM804
#   define I_C04_EVC_YROFMODF_1_ST3_YOM804 (4U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_1_ST3_YOM805
#   define I_C04_EVC_YROFMODF_1_ST3_YOM805 (5U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_1_ST3_YOM806
#   define I_C04_EVC_YROFMODF_1_ST3_YOM806 (6U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_1_ST3_YOM807
#   define I_C04_EVC_YROFMODF_1_ST3_YOM807 (7U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_1_ST3_YOM808
#   define I_C04_EVC_YROFMODF_1_ST3_YOM808 (8U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_1_ST3_YOM809
#   define I_C04_EVC_YROFMODF_1_ST3_YOM809 (9U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_1_ST3_OTHER
#   define I_C04_EVC_YROFMODF_1_ST3_OTHER (15U)
#  endif

#  define c04_EVC_YrOfModf_2_ST3_LowerLimit (0U)
#  define c04_EVC_YrOfModf_2_ST3_UpperLimit (15U)

#  ifndef I_C04_EVC_YROFMODF_2_ST3_YOM050
#   define I_C04_EVC_YROFMODF_2_ST3_YOM050 (0U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_2_ST3_YOM051
#   define I_C04_EVC_YROFMODF_2_ST3_YOM051 (1U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_2_ST3_YOM052
#   define I_C04_EVC_YROFMODF_2_ST3_YOM052 (2U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_2_ST3_YOM053
#   define I_C04_EVC_YROFMODF_2_ST3_YOM053 (3U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_2_ST3_YOM054
#   define I_C04_EVC_YROFMODF_2_ST3_YOM054 (4U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_2_ST3_YOM055
#   define I_C04_EVC_YROFMODF_2_ST3_YOM055 (5U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_2_ST3_YOM056
#   define I_C04_EVC_YROFMODF_2_ST3_YOM056 (6U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_2_ST3_YOM057
#   define I_C04_EVC_YROFMODF_2_ST3_YOM057 (7U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_2_ST3_YOM058
#   define I_C04_EVC_YROFMODF_2_ST3_YOM058 (8U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_2_ST3_YOM059
#   define I_C04_EVC_YROFMODF_2_ST3_YOM059 (9U)
#  endif

#  ifndef I_C04_EVC_YROFMODF_2_ST3_OTHER
#   define I_C04_EVC_YROFMODF_2_ST3_OTHER (15U)
#  endif

#  define c04_Gr_LowerLimit (0U)
#  define c04_Gr_UpperLimit (15U)

#  define InvalidValue_c04_Gr (15U)

#  ifndef I_C04_GR_N
#   define I_C04_GR_N (0U)
#  endif

#  ifndef I_C04_GR_D1
#   define I_C04_GR_D1 (1U)
#  endif

#  ifndef I_C04_GR_D2
#   define I_C04_GR_D2 (2U)
#  endif

#  ifndef I_C04_GR_D3
#   define I_C04_GR_D3 (3U)
#  endif

#  ifndef I_C04_GR_D4
#   define I_C04_GR_D4 (4U)
#  endif

#  ifndef I_C04_GR_D5
#   define I_C04_GR_D5 (5U)
#  endif

#  ifndef I_C04_GR_D6
#   define I_C04_GR_D6 (6U)
#  endif

#  ifndef I_C04_GR_D7
#   define I_C04_GR_D7 (7U)
#  endif

#  ifndef I_C04_GR_D8
#   define I_C04_GR_D8 (8U)
#  endif

#  ifndef I_C04_GR_D9
#   define I_C04_GR_D9 (9U)
#  endif

#  ifndef I_C04_GR_R
#   define I_C04_GR_R (11U)
#  endif

#  ifndef I_C04_GR_R2
#   define I_C04_GR_R2 (12U)
#  endif

#  ifndef I_C04_GR_P
#   define I_C04_GR_P (13U)
#  endif

#  ifndef I_C04_GR_PWRFREE
#   define I_C04_GR_PWRFREE (14U)
#  endif

#  ifndef I_C04_GR_SNA
#   define I_C04_GR_SNA (15U)
#  endif

#  define c04_Gr_Target_LowerLimit (0U)
#  define c04_Gr_Target_UpperLimit (15U)

#  define InvalidValue_c04_Gr_Target (15U)

#  ifndef I_C04_GR_TARGET_N
#   define I_C04_GR_TARGET_N (0U)
#  endif

#  ifndef I_C04_GR_TARGET_D1
#   define I_C04_GR_TARGET_D1 (1U)
#  endif

#  ifndef I_C04_GR_TARGET_D2
#   define I_C04_GR_TARGET_D2 (2U)
#  endif

#  ifndef I_C04_GR_TARGET_D3
#   define I_C04_GR_TARGET_D3 (3U)
#  endif

#  ifndef I_C04_GR_TARGET_D4
#   define I_C04_GR_TARGET_D4 (4U)
#  endif

#  ifndef I_C04_GR_TARGET_D5
#   define I_C04_GR_TARGET_D5 (5U)
#  endif

#  ifndef I_C04_GR_TARGET_D6
#   define I_C04_GR_TARGET_D6 (6U)
#  endif

#  ifndef I_C04_GR_TARGET_D7
#   define I_C04_GR_TARGET_D7 (7U)
#  endif

#  ifndef I_C04_GR_TARGET_D8
#   define I_C04_GR_TARGET_D8 (8U)
#  endif

#  ifndef I_C04_GR_TARGET_D9
#   define I_C04_GR_TARGET_D9 (9U)
#  endif

#  ifndef I_C04_GR_TARGET_R
#   define I_C04_GR_TARGET_R (11U)
#  endif

#  ifndef I_C04_GR_TARGET_R2
#   define I_C04_GR_TARGET_R2 (12U)
#  endif

#  ifndef I_C04_GR_TARGET_P
#   define I_C04_GR_TARGET_P (13U)
#  endif

#  ifndef I_C04_GR_TARGET_ABORT
#   define I_C04_GR_TARGET_ABORT (14U)
#  endif

#  ifndef I_C04_GR_TARGET_SNA
#   define I_C04_GR_TARGET_SNA (15U)
#  endif

#  define c04_NDef_Man_Auto_LowerLimit (1U)
#  define c04_NDef_Man_Auto_UpperLimit (15U)

#  define InvalidValue_c04_NDef_Man_Auto (15U)

#  ifndef I_C04_NDEF_MAN_AUTO_MANUAL
#   define I_C04_NDEF_MAN_AUTO_MANUAL (1U)
#  endif

#  ifndef I_C04_NDEF_MAN_AUTO_AUTO
#   define I_C04_NDEF_MAN_AUTO_AUTO (2U)
#  endif

#  ifndef I_C04_NDEF_MAN_AUTO_SNA
#   define I_C04_NDEF_MAN_AUTO_SNA (15U)
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

#  define c05_DPC_Md_Susp_V2_LowerLimit (1U)
#  define c05_DPC_Md_Susp_V2_UpperLimit (31U)

#  define InvalidValue_c05_DPC_Md_Susp_V2 (31U)

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD1URBANCRUISEAMG
#   define I_C05_DPC_MD_SUSP_V2_ONROAD1URBANCRUISEAMG (1U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD2
#   define I_C05_DPC_MD_SUSP_V2_ONROAD2 (2U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD3
#   define I_C05_DPC_MD_SUSP_V2_ONROAD3 (3U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD4
#   define I_C05_DPC_MD_SUSP_V2_ONROAD4 (4U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD5
#   define I_C05_DPC_MD_SUSP_V2_ONROAD5 (5U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD6
#   define I_C05_DPC_MD_SUSP_V2_ONROAD6 (6U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD7
#   define I_C05_DPC_MD_SUSP_V2_ONROAD7 (7U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD8
#   define I_C05_DPC_MD_SUSP_V2_ONROAD8 (8U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD9
#   define I_C05_DPC_MD_SUSP_V2_ONROAD9 (9U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD10
#   define I_C05_DPC_MD_SUSP_V2_ONROAD10 (10U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD11
#   define I_C05_DPC_MD_SUSP_V2_ONROAD11 (11U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD12
#   define I_C05_DPC_MD_SUSP_V2_ONROAD12 (12U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD13
#   define I_C05_DPC_MD_SUSP_V2_ONROAD13 (13U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD14
#   define I_C05_DPC_MD_SUSP_V2_ONROAD14 (14U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD15
#   define I_C05_DPC_MD_SUSP_V2_ONROAD15 (15U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD16
#   define I_C05_DPC_MD_SUSP_V2_ONROAD16 (16U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD17
#   define I_C05_DPC_MD_SUSP_V2_ONROAD17 (17U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD18
#   define I_C05_DPC_MD_SUSP_V2_ONROAD18 (18U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD19
#   define I_C05_DPC_MD_SUSP_V2_ONROAD19 (19U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD20
#   define I_C05_DPC_MD_SUSP_V2_ONROAD20 (20U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD21
#   define I_C05_DPC_MD_SUSP_V2_ONROAD21 (21U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD22
#   define I_C05_DPC_MD_SUSP_V2_ONROAD22 (22U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD23
#   define I_C05_DPC_MD_SUSP_V2_ONROAD23 (23U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD24
#   define I_C05_DPC_MD_SUSP_V2_ONROAD24 (24U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ONROAD25
#   define I_C05_DPC_MD_SUSP_V2_ONROAD25 (25U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_OFFROAD1
#   define I_C05_DPC_MD_SUSP_V2_OFFROAD1 (26U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_OFFROAD2
#   define I_C05_DPC_MD_SUSP_V2_OFFROAD2 (27U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_OFFROAD3
#   define I_C05_DPC_MD_SUSP_V2_OFFROAD3 (28U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_ALLROAD
#   define I_C05_DPC_MD_SUSP_V2_ALLROAD (29U)
#  endif

#  ifndef I_C05_DPC_MD_SUSP_V2_SNA
#   define I_C05_DPC_MD_SUSP_V2_SNA (31U)
#  endif

#  define c05_perc_0_31_3k333_LowerLimit (0U)
#  define c05_perc_0_31_3k333_UpperLimit (31U)

#  define InvalidValue_c05_perc_0_31_3k333 (31U)

#  ifndef I_C05_PERC_0_31_3K333_SNA
#   define I_C05_PERC_0_31_3K333_SNA (31U)
#  endif

#  define c06_ADAS_MapVerYear_LowerLimit (0U)
#  define c06_ADAS_MapVerYear_UpperLimit (63U)

#  define InvalidValue_c06_ADAS_MapVerYear (63U)

#  ifndef I_C06_ADAS_MAPVERYEAR_SNA
#   define I_C06_ADAS_MAPVERYEAR_SNA (63U)
#  endif

#  define c06_EVC_BodyStyle_ST3_LowerLimit (0U)
#  define c06_EVC_BodyStyle_ST3_UpperLimit (63U)

#  ifndef I_C06_EVC_BODYSTYLE_ST3_FW
#   define I_C06_EVC_BODYSTYLE_ST3_FW (0U)
#  endif

#  ifndef I_C06_EVC_BODYSTYLE_ST3_FV
#   define I_C06_EVC_BODYSTYLE_ST3_FV (1U)
#  endif

#  ifndef I_C06_EVC_BODYSTYLE_ST3_FC
#   define I_C06_EVC_BODYSTYLE_ST3_FC (2U)
#  endif

#  ifndef I_C06_EVC_BODYSTYLE_ST3_FS
#   define I_C06_EVC_BODYSTYLE_ST3_FS (3U)
#  endif

#  ifndef I_C06_EVC_BODYSTYLE_ST3_FA
#   define I_C06_EVC_BODYSTYLE_ST3_FA (4U)
#  endif

#  ifndef I_C06_EVC_BODYSTYLE_ST3_FR
#   define I_C06_EVC_BODYSTYLE_ST3_FR (5U)
#  endif

#  ifndef I_C06_EVC_BODYSTYLE_ST3_FF
#   define I_C06_EVC_BODYSTYLE_ST3_FF (9U)
#  endif

#  ifndef I_C06_EVC_BODYSTYLE_ST3_FT
#   define I_C06_EVC_BODYSTYLE_ST3_FT (12U)
#  endif

#  ifndef I_C06_EVC_BODYSTYLE_ST3_FX
#   define I_C06_EVC_BODYSTYLE_ST3_FX (13U)
#  endif

#  ifndef I_C06_EVC_BODYSTYLE_ST3_FH
#   define I_C06_EVC_BODYSTYLE_ST3_FH (15U)
#  endif

#  ifndef I_C06_EVC_BODYSTYLE_ST3_FZ
#   define I_C06_EVC_BODYSTYLE_ST3_FZ (16U)
#  endif

#  ifndef I_C06_EVC_BODYSTYLE_ST3_FN
#   define I_C06_EVC_BODYSTYLE_ST3_FN (17U)
#  endif

#  ifndef I_C06_EVC_BODYSTYLE_ST3_OTHER
#   define I_C06_EVC_BODYSTYLE_ST3_OTHER (63U)
#  endif

#  define c06_EVC_VehLine_ST3_LowerLimit (0U)
#  define c06_EVC_VehLine_ST3_UpperLimit (63U)

#  ifndef I_C06_EVC_VEHLINE_ST3_BR223
#   define I_C06_EVC_VEHLINE_ST3_BR223 (0U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR231
#   define I_C06_EVC_VEHLINE_ST3_BR231 (1U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR214
#   define I_C06_EVC_VEHLINE_ST3_BR214 (2U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR206
#   define I_C06_EVC_VEHLINE_ST3_BR206 (3U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR463
#   define I_C06_EVC_VEHLINE_ST3_BR463 (10U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR232
#   define I_C06_EVC_VEHLINE_ST3_BR232 (12U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR213
#   define I_C06_EVC_VEHLINE_ST3_BR213 (13U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR238
#   define I_C06_EVC_VEHLINE_ST3_BR238 (14U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR590
#   define I_C06_EVC_VEHLINE_ST3_BR590 (15U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR591
#   define I_C06_EVC_VEHLINE_ST3_BR591 (16U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR592
#   define I_C06_EVC_VEHLINE_ST3_BR592 (17U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR167
#   define I_C06_EVC_VEHLINE_ST3_BR167 (19U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR177
#   define I_C06_EVC_VEHLINE_ST3_BR177 (20U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR190
#   define I_C06_EVC_VEHLINE_ST3_BR190 (21U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR257
#   define I_C06_EVC_VEHLINE_ST3_BR257 (23U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR174
#   define I_C06_EVC_VEHLINE_ST3_BR174 (24U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR178
#   define I_C06_EVC_VEHLINE_ST3_BR178 (25U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR244
#   define I_C06_EVC_VEHLINE_ST3_BR244 (26U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR248
#   define I_C06_EVC_VEHLINE_ST3_BR248 (27U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR520
#   define I_C06_EVC_VEHLINE_ST3_BR520 (28U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR540
#   define I_C06_EVC_VEHLINE_ST3_BR540 (29U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR258
#   define I_C06_EVC_VEHLINE_ST3_BR258 (32U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR290
#   define I_C06_EVC_VEHLINE_ST3_BR290 (34U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR447
#   define I_C06_EVC_VEHLINE_ST3_BR447 (38U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR253
#   define I_C06_EVC_VEHLINE_ST3_BR253 (39U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR292
#   define I_C06_EVC_VEHLINE_ST3_BR292 (40U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR252
#   define I_C06_EVC_VEHLINE_ST3_BR252 (41U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR247
#   define I_C06_EVC_VEHLINE_ST3_BR247 (42U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR118
#   define I_C06_EVC_VEHLINE_ST3_BR118 (43U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR907
#   define I_C06_EVC_VEHLINE_ST3_BR907 (44U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR910
#   define I_C06_EVC_VEHLINE_ST3_BR910 (45U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR293
#   define I_C06_EVC_VEHLINE_ST3_BR293 (47U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR243
#   define I_C06_EVC_VEHLINE_ST3_BR243 (48U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR298
#   define I_C06_EVC_VEHLINE_ST3_BR298 (49U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR226
#   define I_C06_EVC_VEHLINE_ST3_BR226 (50U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR236
#   define I_C06_EVC_VEHLINE_ST3_BR236 (51U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR239
#   define I_C06_EVC_VEHLINE_ST3_BR239 (52U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR254
#   define I_C06_EVC_VEHLINE_ST3_BR254 (53U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR294
#   define I_C06_EVC_VEHLINE_ST3_BR294 (54U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR295
#   define I_C06_EVC_VEHLINE_ST3_BR295 (55U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR296
#   define I_C06_EVC_VEHLINE_ST3_BR296 (56U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR297
#   define I_C06_EVC_VEHLINE_ST3_BR297 (57U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR446
#   define I_C06_EVC_VEHLINE_ST3_BR446 (58U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_BR449
#   define I_C06_EVC_VEHLINE_ST3_BR449 (59U)
#  endif

#  ifndef I_C06_EVC_VEHLINE_ST3_OTHER
#   define I_C06_EVC_VEHLINE_ST3_OTHER (63U)
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

#  define c07_per_0to100_1_SNA_LowerLimit (0U)
#  define c07_per_0to100_1_SNA_UpperLimit (127U)

#  define InvalidValue_c07_per_0to100_1_SNA (127U)

#  ifndef I_C07_PER_0TO100_1_SNA_SNA
#   define I_C07_PER_0TO100_1_SNA_SNA (127U)
#  endif

#  define c08_EVC_Country_extended_LowerLimit (0U)
#  define c08_EVC_Country_extended_UpperLimit (255U)

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_DEU
#   define I_C08_EVC_COUNTRY_EXTENDED_DEU (0U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_DEU_IMPORT
#   define I_C08_EVC_COUNTRY_EXTENDED_DEU_IMPORT (1U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ALB
#   define I_C08_EVC_COUNTRY_EXTENDED_ALB (2U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_AZE
#   define I_C08_EVC_COUNTRY_EXTENDED_AZE (3U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BGR
#   define I_C08_EVC_COUNTRY_EXTENDED_BGR (4U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ARM
#   define I_C08_EVC_COUNTRY_EXTENDED_ARM (5U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MDA
#   define I_C08_EVC_COUNTRY_EXTENDED_MDA (6U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_GEO
#   define I_C08_EVC_COUNTRY_EXTENDED_GEO (7U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_EST
#   define I_C08_EVC_COUNTRY_EXTENDED_EST (8U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_RUS
#   define I_C08_EVC_COUNTRY_EXTENDED_RUS (9U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_LVA
#   define I_C08_EVC_COUNTRY_EXTENDED_LVA (10U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_UKR
#   define I_C08_EVC_COUNTRY_EXTENDED_UKR (11U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_LTU
#   define I_C08_EVC_COUNTRY_EXTENDED_LTU (12U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BLR
#   define I_C08_EVC_COUNTRY_EXTENDED_BLR (13U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_FIN
#   define I_C08_EVC_COUNTRY_EXTENDED_FIN (14U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ISL
#   define I_C08_EVC_COUNTRY_EXTENDED_ISL (15U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_HRV
#   define I_C08_EVC_COUNTRY_EXTENDED_HRV (16U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MKD
#   define I_C08_EVC_COUNTRY_EXTENDED_MKD (17U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MNE
#   define I_C08_EVC_COUNTRY_EXTENDED_MNE (18U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SRB
#   define I_C08_EVC_COUNTRY_EXTENDED_SRB (19U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BEL
#   define I_C08_EVC_COUNTRY_EXTENDED_BEL (20U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_DNK
#   define I_C08_EVC_COUNTRY_EXTENDED_DNK (21U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_FRA
#   define I_C08_EVC_COUNTRY_EXTENDED_FRA (22U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_GRC
#   define I_C08_EVC_COUNTRY_EXTENDED_GRC (23U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_GBR
#   define I_C08_EVC_COUNTRY_EXTENDED_GBR (24U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_IRL
#   define I_C08_EVC_COUNTRY_EXTENDED_IRL (25U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ITA
#   define I_C08_EVC_COUNTRY_EXTENDED_ITA (26U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SVN
#   define I_C08_EVC_COUNTRY_EXTENDED_SVN (27U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_LUX
#   define I_C08_EVC_COUNTRY_EXTENDED_LUX (28U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MLT
#   define I_C08_EVC_COUNTRY_EXTENDED_MLT (29U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_NDL
#   define I_C08_EVC_COUNTRY_EXTENDED_NDL (30U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_AUT
#   define I_C08_EVC_COUNTRY_EXTENDED_AUT (31U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_PRT
#   define I_C08_EVC_COUNTRY_EXTENDED_PRT (32U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SWE
#   define I_C08_EVC_COUNTRY_EXTENDED_SWE (33U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CHE
#   define I_C08_EVC_COUNTRY_EXTENDED_CHE (34U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ESP
#   define I_C08_EVC_COUNTRY_EXTENDED_ESP (35U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_NOR
#   define I_C08_EVC_COUNTRY_EXTENDED_NOR (36U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BIH
#   define I_C08_EVC_COUNTRY_EXTENDED_BIH (37U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_POL
#   define I_C08_EVC_COUNTRY_EXTENDED_POL (38U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ROU
#   define I_C08_EVC_COUNTRY_EXTENDED_ROU (39U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CZE
#   define I_C08_EVC_COUNTRY_EXTENDED_CZE (40U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SVK
#   define I_C08_EVC_COUNTRY_EXTENDED_SVK (41U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_TUR
#   define I_C08_EVC_COUNTRY_EXTENDED_TUR (42U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_HUN
#   define I_C08_EVC_COUNTRY_EXTENDED_HUN (43U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_EGY
#   define I_C08_EVC_COUNTRY_EXTENDED_EGY (44U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_GAB
#   define I_C08_EVC_COUNTRY_EXTENDED_GAB (45U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CAF
#   define I_C08_EVC_COUNTRY_EXTENDED_CAF (46U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ETH
#   define I_C08_EVC_COUNTRY_EXTENDED_ETH (47U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ERI
#   define I_C08_EVC_COUNTRY_EXTENDED_ERI (48U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_DZA
#   define I_C08_EVC_COUNTRY_EXTENDED_DZA (49U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_AGO
#   define I_C08_EVC_COUNTRY_EXTENDED_AGO (50U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_GMB
#   define I_C08_EVC_COUNTRY_EXTENDED_GMB (51U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_GHA
#   define I_C08_EVC_COUNTRY_EXTENDED_GHA (52U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ZAF
#   define I_C08_EVC_COUNTRY_EXTENDED_ZAF (53U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_TZA
#   define I_C08_EVC_COUNTRY_EXTENDED_TZA (54U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_TGO
#   define I_C08_EVC_COUNTRY_EXTENDED_TGO (55U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BEN
#   define I_C08_EVC_COUNTRY_EXTENDED_BEN (56U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_TUN
#   define I_C08_EVC_COUNTRY_EXTENDED_TUN (57U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MRT
#   define I_C08_EVC_COUNTRY_EXTENDED_MRT (58U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SEN
#   define I_C08_EVC_COUNTRY_EXTENDED_SEN (59U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MLI
#   define I_C08_EVC_COUNTRY_EXTENDED_MLI (60U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BFA
#   define I_C08_EVC_COUNTRY_EXTENDED_BFA (61U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_GNB
#   define I_C08_EVC_COUNTRY_EXTENDED_GNB (62U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_GIN
#   define I_C08_EVC_COUNTRY_EXTENDED_GIN (63U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_STP
#   define I_C08_EVC_COUNTRY_EXTENDED_STP (64U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_GNQ
#   define I_C08_EVC_COUNTRY_EXTENDED_GNQ (65U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CPV
#   define I_C08_EVC_COUNTRY_EXTENDED_CPV (66U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_TCD
#   define I_C08_EVC_COUNTRY_EXTENDED_TCD (67U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CMR
#   define I_C08_EVC_COUNTRY_EXTENDED_CMR (68U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_KEN
#   define I_C08_EVC_COUNTRY_EXTENDED_KEN (69U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CAN
#   define I_C08_EVC_COUNTRY_EXTENDED_CAN (70U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_USA
#   define I_C08_EVC_COUNTRY_EXTENDED_USA (71U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_USA_CKD
#   define I_C08_EVC_COUNTRY_EXTENDED_USA_CKD (72U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SX
#   define I_C08_EVC_COUNTRY_EXTENDED_SX (73U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CW
#   define I_C08_EVC_COUNTRY_EXTENDED_CW (74U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_AW
#   define I_C08_EVC_COUNTRY_EXTENDED_AW (75U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CRI
#   define I_C08_EVC_COUNTRY_EXTENDED_CRI (76U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_VGB
#   define I_C08_EVC_COUNTRY_EXTENDED_VGB (77U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_DOM
#   define I_C08_EVC_COUNTRY_EXTENDED_DOM (78U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_GTM
#   define I_C08_EVC_COUNTRY_EXTENDED_GTM (79U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_HTI
#   define I_C08_EVC_COUNTRY_EXTENDED_HTI (80U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_HND
#   define I_C08_EVC_COUNTRY_EXTENDED_HND (81U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CUB
#   define I_C08_EVC_COUNTRY_EXTENDED_CUB (82U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MEX
#   define I_C08_EVC_COUNTRY_EXTENDED_MEX (83U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_NIC
#   define I_C08_EVC_COUNTRY_EXTENDED_NIC (84U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_PAN
#   define I_C08_EVC_COUNTRY_EXTENDED_PAN (85U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SLV
#   define I_C08_EVC_COUNTRY_EXTENDED_SLV (86U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BHS
#   define I_C08_EVC_COUNTRY_EXTENDED_BHS (87U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BRB
#   define I_C08_EVC_COUNTRY_EXTENDED_BRB (88U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_JAM
#   define I_C08_EVC_COUNTRY_EXTENDED_JAM (89U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BHR
#   define I_C08_EVC_COUNTRY_EXTENDED_BHR (90U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_QAT
#   define I_C08_EVC_COUNTRY_EXTENDED_QAT (91U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_TWN
#   define I_C08_EVC_COUNTRY_EXTENDED_TWN (92U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CHN
#   define I_C08_EVC_COUNTRY_EXTENDED_CHN (93U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_HKG
#   define I_C08_EVC_COUNTRY_EXTENDED_HKG (94U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MAC
#   define I_C08_EVC_COUNTRY_EXTENDED_MAC (95U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_JPN
#   define I_C08_EVC_COUNTRY_EXTENDED_JPN (96U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_KOR
#   define I_C08_EVC_COUNTRY_EXTENDED_KOR (97U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_KWT
#   define I_C08_EVC_COUNTRY_EXTENDED_KWT (98U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MYS
#   define I_C08_EVC_COUNTRY_EXTENDED_MYS (99U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_OMN
#   define I_C08_EVC_COUNTRY_EXTENDED_OMN (100U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MNG
#   define I_C08_EVC_COUNTRY_EXTENDED_MNG (101U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SAU
#   define I_C08_EVC_COUNTRY_EXTENDED_SAU (102U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SGP
#   define I_C08_EVC_COUNTRY_EXTENDED_SGP (103U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_AE_AZ
#   define I_C08_EVC_COUNTRY_EXTENDED_AE_AZ (104U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_THA
#   define I_C08_EVC_COUNTRY_EXTENDED_THA (105U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_AE_DU
#   define I_C08_EVC_COUNTRY_EXTENDED_AE_DU (106U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_VNM
#   define I_C08_EVC_COUNTRY_EXTENDED_VNM (107U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_YEM
#   define I_C08_EVC_COUNTRY_EXTENDED_YEM (108U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_JOR
#   define I_C08_EVC_COUNTRY_EXTENDED_JOR (109U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_KHM
#   define I_C08_EVC_COUNTRY_EXTENDED_KHM (110U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_PRK
#   define I_C08_EVC_COUNTRY_EXTENDED_PRK (111U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_LAO
#   define I_C08_EVC_COUNTRY_EXTENDED_LAO (112U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_LBN
#   define I_C08_EVC_COUNTRY_EXTENDED_LBN (113U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MDV
#   define I_C08_EVC_COUNTRY_EXTENDED_MDV (114U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_NPL
#   define I_C08_EVC_COUNTRY_EXTENDED_NPL (115U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_PAK
#   define I_C08_EVC_COUNTRY_EXTENDED_PAK (116U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BGD
#   define I_C08_EVC_COUNTRY_EXTENDED_BGD (117U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_PHL
#   define I_C08_EVC_COUNTRY_EXTENDED_PHL (118U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SYR
#   define I_C08_EVC_COUNTRY_EXTENDED_SYR (119U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_AUS
#   define I_C08_EVC_COUNTRY_EXTENDED_AUS (120U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CAYMAN
#   define I_C08_EVC_COUNTRY_EXTENDED_CAYMAN (121U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_PNG
#   define I_C08_EVC_COUNTRY_EXTENDED_PNG (122U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_NZL
#   define I_C08_EVC_COUNTRY_EXTENDED_NZL (123U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_TTO
#   define I_C08_EVC_COUNTRY_EXTENDED_TTO (124U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_LCA
#   define I_C08_EVC_COUNTRY_EXTENDED_LCA (125U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_PYF
#   define I_C08_EVC_COUNTRY_EXTENDED_PYF (126U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_NCL
#   define I_C08_EVC_COUNTRY_EXTENDED_NCL (127U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_TON
#   define I_C08_EVC_COUNTRY_EXTENDED_TON (128U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_WSM
#   define I_C08_EVC_COUNTRY_EXTENDED_WSM (129U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ARG
#   define I_C08_EVC_COUNTRY_EXTENDED_ARG (130U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BOL
#   define I_C08_EVC_COUNTRY_EXTENDED_BOL (131U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BRA
#   define I_C08_EVC_COUNTRY_EXTENDED_BRA (132U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CHL
#   define I_C08_EVC_COUNTRY_EXTENDED_CHL (133U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ECU
#   define I_C08_EVC_COUNTRY_EXTENDED_ECU (134U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_GUY
#   define I_C08_EVC_COUNTRY_EXTENDED_GUY (135U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_COL
#   define I_C08_EVC_COUNTRY_EXTENDED_COL (136U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_PRY
#   define I_C08_EVC_COUNTRY_EXTENDED_PRY (137U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_PER
#   define I_C08_EVC_COUNTRY_EXTENDED_PER (138U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SUR
#   define I_C08_EVC_COUNTRY_EXTENDED_SUR (139U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_URY
#   define I_C08_EVC_COUNTRY_EXTENDED_URY (140U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_VEN
#   define I_C08_EVC_COUNTRY_EXTENDED_VEN (141U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_AFG
#   define I_C08_EVC_COUNTRY_EXTENDED_AFG (142U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_W_JORDAN
#   define I_C08_EVC_COUNTRY_EXTENDED_W_JORDAN (143U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_KAZ
#   define I_C08_EVC_COUNTRY_EXTENDED_KAZ (144U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MMR
#   define I_C08_EVC_COUNTRY_EXTENDED_MMR (145U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_KGZ
#   define I_C08_EVC_COUNTRY_EXTENDED_KGZ (146U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BRN
#   define I_C08_EVC_COUNTRY_EXTENDED_BRN (147U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_TJK
#   define I_C08_EVC_COUNTRY_EXTENDED_TJK (148U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_LKA
#   define I_C08_EVC_COUNTRY_EXTENDED_LKA (149U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_TKM
#   define I_C08_EVC_COUNTRY_EXTENDED_TKM (150U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_UZB
#   define I_C08_EVC_COUNTRY_EXTENDED_UZB (151U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_PSE
#   define I_C08_EVC_COUNTRY_EXTENDED_PSE (152U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CYP_SOUTH
#   define I_C08_EVC_COUNTRY_EXTENDED_CYP_SOUTH (153U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CYP_NORTH
#   define I_C08_EVC_COUNTRY_EXTENDED_CYP_NORTH (154U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_IND
#   define I_C08_EVC_COUNTRY_EXTENDED_IND (155U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_IDN
#   define I_C08_EVC_COUNTRY_EXTENDED_IDN (156U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_IRQ
#   define I_C08_EVC_COUNTRY_EXTENDED_IRQ (157U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_IRN
#   define I_C08_EVC_COUNTRY_EXTENDED_IRN (158U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ISR
#   define I_C08_EVC_COUNTRY_EXTENDED_ISR (159U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_UGA
#   define I_C08_EVC_COUNTRY_EXTENDED_UGA (160U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_COD
#   define I_C08_EVC_COUNTRY_EXTENDED_COD (161U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_COG
#   define I_C08_EVC_COUNTRY_EXTENDED_COG (162U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_LBR
#   define I_C08_EVC_COUNTRY_EXTENDED_LBR (163U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_CIV
#   define I_C08_EVC_COUNTRY_EXTENDED_CIV (164U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_LBY
#   define I_C08_EVC_COUNTRY_EXTENDED_LBY (165U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MDG
#   define I_C08_EVC_COUNTRY_EXTENDED_MDG (166U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_COM
#   define I_C08_EVC_COUNTRY_EXTENDED_COM (167U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MAR
#   define I_C08_EVC_COUNTRY_EXTENDED_MAR (168U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_NGA
#   define I_C08_EVC_COUNTRY_EXTENDED_NGA (169U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_NER
#   define I_C08_EVC_COUNTRY_EXTENDED_NER (170U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MOZ
#   define I_C08_EVC_COUNTRY_EXTENDED_MOZ (171U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ZWE
#   define I_C08_EVC_COUNTRY_EXTENDED_ZWE (172U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_ZMB
#   define I_C08_EVC_COUNTRY_EXTENDED_ZMB (173U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MWI
#   define I_C08_EVC_COUNTRY_EXTENDED_MWI (174U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_RWA
#   define I_C08_EVC_COUNTRY_EXTENDED_RWA (175U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_BDI
#   define I_C08_EVC_COUNTRY_EXTENDED_BDI (176U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_MUS
#   define I_C08_EVC_COUNTRY_EXTENDED_MUS (177U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SYC
#   define I_C08_EVC_COUNTRY_EXTENDED_SYC (178U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SLE
#   define I_C08_EVC_COUNTRY_EXTENDED_SLE (179U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_DJI
#   define I_C08_EVC_COUNTRY_EXTENDED_DJI (180U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SOM
#   define I_C08_EVC_COUNTRY_EXTENDED_SOM (181U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_SDN
#   define I_C08_EVC_COUNTRY_EXTENDED_SDN (182U)
#  endif

#  ifndef I_C08_EVC_COUNTRY_EXTENDED_OTHER
#   define I_C08_EVC_COUNTRY_EXTENDED_OTHER (255U)
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

#  define c08_TxDrvPosn_LowerLimit (1U)
#  define c08_TxDrvPosn_UpperLimit (255U)

#  define InvalidValue_c08_TxDrvPosn (255U)

#  ifndef I_C08_TXDRVPOSN_M1
#   define I_C08_TXDRVPOSN_M1 (1U)
#  endif

#  ifndef I_C08_TXDRVPOSN_M2
#   define I_C08_TXDRVPOSN_M2 (2U)
#  endif

#  ifndef I_C08_TXDRVPOSN_M3
#   define I_C08_TXDRVPOSN_M3 (3U)
#  endif

#  ifndef I_C08_TXDRVPOSN_M4
#   define I_C08_TXDRVPOSN_M4 (4U)
#  endif

#  ifndef I_C08_TXDRVPOSN_M5
#   define I_C08_TXDRVPOSN_M5 (5U)
#  endif

#  ifndef I_C08_TXDRVPOSN_M6
#   define I_C08_TXDRVPOSN_M6 (6U)
#  endif

#  ifndef I_C08_TXDRVPOSN_M7
#   define I_C08_TXDRVPOSN_M7 (7U)
#  endif

#  ifndef I_C08_TXDRVPOSN_M8
#   define I_C08_TXDRVPOSN_M8 (8U)
#  endif

#  ifndef I_C08_TXDRVPOSN_M9
#   define I_C08_TXDRVPOSN_M9 (9U)
#  endif

#  ifndef I_C08_TXDRVPOSN_BLANK
#   define I_C08_TXDRVPOSN_BLANK (32U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D_AUTO_RADAR_RECUP
#   define I_C08_TXDRVPOSN_D_AUTO_RADAR_RECUP (33U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D_MAN_MIN_RECUP
#   define I_C08_TXDRVPOSN_D_MAN_MIN_RECUP (34U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D_MAN_DEFAULT_RECUP
#   define I_C08_TXDRVPOSN_D_MAN_DEFAULT_RECUP (35U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D_MAN_MAX_RECUP
#   define I_C08_TXDRVPOSN_D_MAN_MAX_RECUP (36U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D_MAN_SPORT_RECUP
#   define I_C08_TXDRVPOSN_D_MAN_SPORT_RECUP (37U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D1
#   define I_C08_TXDRVPOSN_D1 (49U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D2
#   define I_C08_TXDRVPOSN_D2 (50U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D3
#   define I_C08_TXDRVPOSN_D3 (51U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D4
#   define I_C08_TXDRVPOSN_D4 (52U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D5
#   define I_C08_TXDRVPOSN_D5 (53U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D6
#   define I_C08_TXDRVPOSN_D6 (54U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D7
#   define I_C08_TXDRVPOSN_D7 (55U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D8
#   define I_C08_TXDRVPOSN_D8 (56U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D9
#   define I_C08_TXDRVPOSN_D9 (57U)
#  endif

#  ifndef I_C08_TXDRVPOSN_A
#   define I_C08_TXDRVPOSN_A (65U)
#  endif

#  ifndef I_C08_TXDRVPOSN_D
#   define I_C08_TXDRVPOSN_D (68U)
#  endif

#  ifndef I_C08_TXDRVPOSN_F
#   define I_C08_TXDRVPOSN_F (70U)
#  endif

#  ifndef I_C08_TXDRVPOSN_N
#   define I_C08_TXDRVPOSN_N (78U)
#  endif

#  ifndef I_C08_TXDRVPOSN_P
#   define I_C08_TXDRVPOSN_P (80U)
#  endif

#  ifndef I_C08_TXDRVPOSN_R
#   define I_C08_TXDRVPOSN_R (82U)
#  endif

#  ifndef I_C08_TXDRVPOSN_SNA
#   define I_C08_TXDRVPOSN_SNA (255U)
#  endif

#  define c08_V_0_25k4_0k1_LowerLimit (0U)
#  define c08_V_0_25k4_0k1_UpperLimit (255U)

#  define InvalidValue_c08_V_0_25k4_0k1 (255U)

#  ifndef I_C08_V_0_25K4_0K1_SNA
#   define I_C08_V_0_25K4_0K1_SNA (255U)
#  endif

#  define c08_deg_0_358k5_1k417_LowerLimit (0U)
#  define c08_deg_0_358k5_1k417_UpperLimit (255U)

#  define InvalidValue_c08_deg_0_358k5_1k417 (255U)

#  ifndef I_C08_DEG_0_358K5_1K417_UNKNOWN
#   define I_C08_DEG_0_358K5_1K417_UNKNOWN (254U)
#  endif

#  ifndef I_C08_DEG_0_358K5_1K417_SNA
#   define I_C08_DEG_0_358K5_1K417_SNA (255U)
#  endif

#  define c08_km_p_h_0_254_1_LowerLimit (0U)
#  define c08_km_p_h_0_254_1_UpperLimit (255U)

#  define InvalidValue_c08_km_p_h_0_254_1 (255U)

#  ifndef I_C08_KM_P_H_0_254_1_SNA
#   define I_C08_KM_P_H_0_254_1_SNA (255U)
#  endif

#  define c08_km_p_h_30_250_1_NoRcmnd_LowerLimit (30U)
#  define c08_km_p_h_30_250_1_NoRcmnd_UpperLimit (255U)

#  define InvalidValue_c08_km_p_h_30_250_1_NoRcmnd (255U)

#  ifndef I_C08_KM_P_H_30_250_1_NORCMND_NO_RCMND
#   define I_C08_KM_P_H_30_250_1_NORCMND_NO_RCMND (251U)
#  endif

#  ifndef I_C08_KM_P_H_30_250_1_NORCMND_SNA
#   define I_C08_KM_P_H_30_250_1_NORCMND_SNA (255U)
#  endif

#  define c08_perc_0_100_0k4_LowerLimit (0U)
#  define c08_perc_0_100_0k4_UpperLimit (255U)

#  define InvalidValue_c08_perc_0_100_0k4 (255U)

#  ifndef I_C08_PERC_0_100_0K4_SNA
#   define I_C08_PERC_0_100_0K4_SNA (255U)
#  endif

#  define c08_perc_0_100_0k5_LowerLimit (0U)
#  define c08_perc_0_100_0k5_UpperLimit (255U)

#  define InvalidValue_c08_perc_0_100_0k5 (255U)

#  ifndef I_C08_PERC_0_100_0K5_SNA
#   define I_C08_PERC_0_100_0K5_SNA (255U)
#  endif

#  define c09_ADAS_HwVer_LowerLimit (0U)
#  define c09_ADAS_HwVer_UpperLimit (511U)

#  ifndef I_C09_ADAS_HWVER_UNKNOWN
#   define I_C09_ADAS_HWVER_UNKNOWN (0U)
#  endif

#  define c09_km_p_h_0_500_1_LowerLimit (0U)
#  define c09_km_p_h_0_500_1_UpperLimit (511U)

#  define InvalidValue_c09_km_p_h_0_500_1 (511U)

#  ifndef I_C09_KM_P_H_0_500_1_SNA
#   define I_C09_KM_P_H_0_500_1_SNA (511U)
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

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_FALSE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_FALSE (0U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_BflMask
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_BflMask 32768U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_BflPn
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_BflPn 15U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_BflLn
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_BflLn 1U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_TRUE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_TRUE (32768U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Basic_Avl_ST3_FALSE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Basic_Avl_ST3_FALSE (0U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Basic_Avl_ST3_BflMask
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Basic_Avl_ST3_BflMask 32769U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Basic_Avl_ST3_TRUE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Basic_Avl_ST3_TRUE (1U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Full_Avl_ST3_FALSE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Full_Avl_ST3_FALSE (0U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Full_Avl_ST3_BflMask
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Full_Avl_ST3_BflMask 32770U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Full_Avl_ST3_TRUE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Full_Avl_ST3_TRUE (2U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Basic_Avl_ST3_FALSE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Basic_Avl_ST3_FALSE (0U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Basic_Avl_ST3_BflMask
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Basic_Avl_ST3_BflMask 32772U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Basic_Avl_ST3_TRUE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Basic_Avl_ST3_TRUE (4U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Extended_Avl_ST3_FALSE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Extended_Avl_ST3_FALSE (0U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Extended_Avl_ST3_BflMask
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Extended_Avl_ST3_BflMask 32776U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Extended_Avl_ST3_TRUE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Extended_Avl_ST3_TRUE (8U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Full_Avl_ST3_FALSE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Full_Avl_ST3_FALSE (0U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Full_Avl_ST3_BflMask
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Full_Avl_ST3_BflMask 32784U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Full_Avl_ST3_TRUE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Full_Avl_ST3_TRUE (16U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Basic_Avl_ST3_FALSE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Basic_Avl_ST3_FALSE (0U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Basic_Avl_ST3_BflMask
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Basic_Avl_ST3_BflMask 32800U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Basic_Avl_ST3_TRUE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Basic_Avl_ST3_TRUE (32U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Full_Avl_ST3_FALSE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Full_Avl_ST3_FALSE (0U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Full_Avl_ST3_BflMask
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Full_Avl_ST3_BflMask 32832U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Full_Avl_ST3_TRUE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Full_Avl_ST3_TRUE (64U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Basic_Avl_ST3_FALSE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Basic_Avl_ST3_FALSE (0U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Basic_Avl_ST3_BflMask
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Basic_Avl_ST3_BflMask 32896U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Basic_Avl_ST3_TRUE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Basic_Avl_ST3_TRUE (128U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Extended_Avl_ST3_FALSE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Extended_Avl_ST3_FALSE (0U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Extended_Avl_ST3_BflMask
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Extended_Avl_ST3_BflMask 33024U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Extended_Avl_ST3_TRUE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Extended_Avl_ST3_TRUE (256U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Full_Avl_ST3_FALSE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Full_Avl_ST3_FALSE (0U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Full_Avl_ST3_BflMask
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Full_Avl_ST3_BflMask 33280U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Full_Avl_ST3_TRUE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Full_Avl_ST3_TRUE (512U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Extended_Avl_ST3_FALSE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Extended_Avl_ST3_FALSE (0U)
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Extended_Avl_ST3_BflMask
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Extended_Avl_ST3_BflMask 33792U
#  endif

#  ifndef c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Extended_Avl_ST3_TRUE
#   define c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Extended_Avl_ST3_TRUE (1024U)
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

#  define c12_rpm_0_16376_4_LowerLimit (0U)
#  define c12_rpm_0_16376_4_UpperLimit (4095U)

#  define InvalidValue_c12_rpm_0_16376_4 (4095U)

#  ifndef I_C12_RPM_0_16376_4_SNA
#   define I_C12_RPM_0_16376_4_SNA (4095U)
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

#  define c14_rpm_0_16382_1_LowerLimit (0U)
#  define c14_rpm_0_16382_1_UpperLimit (16383U)

#  define InvalidValue_c14_rpm_0_16382_1 (16383U)

#  ifndef I_C14_RPM_0_16382_1_SNA
#   define I_C14_RPM_0_16382_1_SNA (16383U)
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

#  define cDC_errorCode_ST3_LowerLimit (0U)
#  define cDC_errorCode_ST3_UpperLimit (254U)

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

#  ifndef DCM_E_INVALIDKEY
#   define DCM_E_INVALIDKEY (53U)
#  endif

#  ifndef DCM_E_EXCEEDNUMBEROFATTEMPTS
#   define DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
#  endif

#  ifndef DCM_E_REQUIREDTIMEDELAYNOTEXPIRED
#   define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
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

#  define cDC_keyStorageTask_ST3_LowerLimit (0U)
#  define cDC_keyStorageTask_ST3_UpperLimit (2U)

#  ifndef SSA_KEYSTORAGE_TASK_INITIAL
#   define SSA_KEYSTORAGE_TASK_INITIAL (0U)
#  endif

#  ifndef SSA_KEYSTORAGE_TASK_CHECKSTATE
#   define SSA_KEYSTORAGE_TASK_CHECKSTATE (1U)
#  endif

#  ifndef SSA_KEYSTORAGE_TASK_CANCEL
#   define SSA_KEYSTORAGE_TASK_CANCEL (2U)
#  endif

#  define cDC_keyStorageUseCase_ST3_LowerLimit (0U)
#  define cDC_keyStorageUseCase_ST3_UpperLimit (1U)

#  ifndef SSA_KEYSTORAGE_USECASE_CRYPTO
#   define SSA_KEYSTORAGE_USECASE_CRYPTO (0U)
#  endif

#  ifndef SSA_KEYSTORAGE_USECASE_CERTIFICATES
#   define SSA_KEYSTORAGE_USECASE_CERTIFICATES (1U)
#  endif

#  define cDC_syncState_ST3_LowerLimit (0U)
#  define cDC_syncState_ST3_UpperLimit (2U)

#  ifndef SSA_TC_SYNC_ST_NOT_SYNC
#   define SSA_TC_SYNC_ST_NOT_SYNC (0U)
#  endif

#  ifndef SSA_TC_SYNC_ST_SYNC_TO_MASTER
#   define SSA_TC_SYNC_ST_SYNC_TO_MASTER (1U)
#  endif

#  ifndef SSA_TC_SYNC_ST_SYNC_TO_VSM
#   define SSA_TC_SYNC_ST_SYNC_TO_VSM (2U)
#  endif

#  define c_DC_VIN_Stat_ST3_LowerLimit (0U)
#  define c_DC_VIN_Stat_ST3_UpperLimit (2U)

#  ifndef VIN_STATUS_NEW_VIN_RECEIVED
#   define VIN_STATUS_NEW_VIN_RECEIVED (0U)
#  endif

#  ifndef VIN_STATUS_VIN_CORRECT_RECEIVED
#   define VIN_STATUS_VIN_CORRECT_RECEIVED (1U)
#  endif

#  ifndef VIN_STATUS_VIN_NOT_RECEIVED
#   define VIN_STATUS_VIN_NOT_RECEIVED (2U)
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

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_Coding_Mode
#  define RTE_MODETYPE_Coding_Mode
typedef uint8 Rte_ModeType_Coding_Mode;
# endif

# define RTE_MODE_Ct_MBBL_ResetPreconditionChecker_Coding_Mode_CODING_ACTIVE (0U)
# ifndef RTE_MODE_Coding_Mode_CODING_ACTIVE
#  define RTE_MODE_Coding_Mode_CODING_ACTIVE (0U)
# endif
# define RTE_MODE_Ct_MBBL_ResetPreconditionChecker_Coding_Mode_CODING_FAILED (1U)
# ifndef RTE_MODE_Coding_Mode_CODING_FAILED
#  define RTE_MODE_Coding_Mode_CODING_FAILED (1U)
# endif
# define RTE_MODE_Ct_MBBL_ResetPreconditionChecker_Coding_Mode_CODING_OK (2U)
# ifndef RTE_MODE_Coding_Mode_CODING_OK
#  define RTE_MODE_Coding_Mode_CODING_OK (2U)
# endif
# define RTE_TRANSITION_Ct_MBBL_ResetPreconditionChecker_Coding_Mode (3U)
# ifndef RTE_TRANSITION_Coding_Mode
#  define RTE_TRANSITION_Coding_Mode (3U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CT_MBBL_RESETPRECONDITIONCHECKER_TYPE_H */
