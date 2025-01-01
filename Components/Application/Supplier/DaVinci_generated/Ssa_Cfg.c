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
 *            Module: Ssa
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Ssa_Cfg.c
 *   Generation Time: 2023-09-25 13:39:34
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define SSA_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Ssa_Cfg.h"
#include "NvM.h"
#include "Csm.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (SSA_LOCAL)
# define SSA_LOCAL static
#endif

#if !defined (SSA_LOCAL_INLINE)
# define SSA_LOCAL_INLINE LOCAL_INLINE
#endif




/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Ssa_CodingDid
**********************************************************************************************************************/
#define SSA_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_CodingDidType, SSA_CONST) Ssa_CodingDid[9] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CodingDid      Referable Keys */
  /*     0 */       305u,  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/Activate_SAR_Data_Storage] */
  /*     1 */       310u,  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/Configure_SAR_Trigger_Events] */
  /*     2 */       768u,  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_PreSafe_Cycles_Level_1_8_Read] */
  /*     3 */       769u,  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_Release_Cycles_BSR_and_PreSafe_Read] */
  /*     4 */       770u,  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_Tensioning_Cycle_BSR_Read] */
  /*     5 */       784u,  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_Vehicle_Equipment_Read] */
  /*     6 */       785u,  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_ZZZ_Vehicle_Equipment_Development_Read] */
  /*     7 */     57604u,  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_Calibration_Identifications_CAL_ID_Read] */
  /*     8 */     63492u   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_Calibration_Identifications_CAL_ID_Write] */
};
#define SSA_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_CodingNvMBlock
**********************************************************************************************************************/
/** 
  \var    Ssa_CodingNvMBlock
  \brief  Contains values of DefinitionRef: /MICROSAR/Ssa/SsaCoding/SsaCodingNvMBlock.
*/ 
#define SSA_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_CodingNvMBlockType, SSA_CONST) Ssa_CodingNvMBlock[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CodingNvMBlock                                                                                 Referable Keys */
  /*     0 */ NvMConf_NvMBlockDescriptor_Cp_MBBL_SsaAppl_CodingNvBlockNeed_CodingData                   ,  /* [/ActiveEcuC/Ssa/SsaCoding[0:SsaCodingNvMBlock], /ActiveEcuC/Ssa/SsaCoding, /ActiveEcuC/NvM/Cp_MBBL_SsaAppl_CodingNvBlockNeed_CodingData] */
  /*     1 */ NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_CurrentVehicleEquipment        ,  /* [/ActiveEcuC/Ssa/SsaCoding[1:SsaCodingNvMBlock], /ActiveEcuC/Ssa/SsaCoding, /ActiveEcuC/NvM/Ct_MBBL_SsaAppl_CodingNvmCoding_CurrentVehicleEquipment] */
  /*     2 */ NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_TensioningCycleBSR             ,  /* [/ActiveEcuC/Ssa/SsaCoding[2:SsaCodingNvMBlock], /ActiveEcuC/Ssa/SsaCoding, /ActiveEcuC/NvM/Ct_MBBL_SsaAppl_CodingNvmCoding_TensioningCycleBSR] */
  /*     3 */ NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_ReleaseCyclesBsrAndPreSafe     ,  /* [/ActiveEcuC/Ssa/SsaCoding[3:SsaCodingNvMBlock], /ActiveEcuC/Ssa/SsaCoding, /ActiveEcuC/NvM/Ct_MBBL_SsaAppl_CodingNvmCoding_ReleaseCyclesBsrAndPreSafe] */
  /*     4 */ NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_PreSafeCyclesLevel             ,  /* [/ActiveEcuC/Ssa/SsaCoding[4:SsaCodingNvMBlock], /ActiveEcuC/Ssa/SsaCoding, /ActiveEcuC/NvM/Ct_MBBL_SsaAppl_CodingNvmCoding_PreSafeCyclesLevel] */
  /*     5 */ NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_ZZZVehicleEquipmentDevelopment ,  /* [/ActiveEcuC/Ssa/SsaCoding[5:SsaCodingNvMBlock], /ActiveEcuC/Ssa/SsaCoding, /ActiveEcuC/NvM/Ct_MBBL_SsaAppl_CodingNvmCoding_ZZZVehicleEquipmentDevelopment] */
  /*     6 */ NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_CalibrationID                     /* [/ActiveEcuC/Ssa/SsaCoding[6:SsaCodingNvMBlock], /ActiveEcuC/Ssa/SsaCoding, /ActiveEcuC/NvM/Ct_MBBL_SsaAppl_CodingNvmCoding_CalibrationID] */
};
#define SSA_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_DataIdInfo
**********************************************************************************************************************/
/** 
  \var    Ssa_DataIdInfo
  \details
  Element      Description
  KeyId    
  DataId   
  Threshold
*/ 
#define SSA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_DataIdInfoType, SSA_CONST) Ssa_DataIdInfo[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    KeyId                                                                     DataId  Threshold        Referable Keys */
  { /*     0 */ CsmConf_CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, 15576u,      100u },  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx, 15576_CsmConf_CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx] */
  { /*     1 */ CsmConf_CsmKey_SSA_SecOC_Int_MacVerify_Ign_Stat                         , 28212u,      100u },  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx, 28212_CsmConf_CsmKey_SSA_SecOC_Int_MacVerify_Ign_Stat] */
  { /*     2 */ CsmConf_CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, 37177u,      100u },  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx, 37177_CsmConf_CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx] */
  { /*     3 */ CsmConf_CsmKey_Ssa_Authentication                                       , 65532u,      100u },  /* [/ActiveEcuC/Ssa/SsaSpecialDataIds/Ssa_AuthenticationBroadcast, 65532_CsmConf_CsmKey_Ssa_Authentication] */
  { /*     4 */ CsmConf_CsmKey_Ssa_VIN                                                  , 65533u,      100u },  /* [/ActiveEcuC/Ssa/SsaSpecialDataIds/Ssa_VINBroadcast, 65533_CsmConf_CsmKey_Ssa_VIN] */
  { /*     5 */ CsmConf_CsmKey_Ssa_RealTime                                             , 65534u,      100u },  /* [/ActiveEcuC/Ssa/SsaSpecialDataIds/Ssa_RealtimeBroadcast, 65534_CsmConf_CsmKey_Ssa_RealTime] */
  { /*     6 */ CsmConf_CsmKey_Ssa_TickCount                                            , 65535u,      100u }   /* [/ActiveEcuC/Ssa/SsaSpecialDataIds/Ssa_TickcountBroadcast, 65535_CsmConf_CsmKey_Ssa_TickCount] */
};
#define SSA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_RightsM_TesterToChannel
**********************************************************************************************************************/
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_RightsM_TesterToChannelType, SSA_CONST) Ssa_RightsM_TesterToChannel[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RightsM_TesterToChannel      Referable Keys */
  /*     0 */                     255u,  /* [INVALID] */
  /*     1 */                     255u,  /* [INVALID] */
  /*     2 */                     255u,  /* [INVALID] */
  /*     3 */                     255u,  /* [INVALID] */
  /*     4 */                     255u,  /* [INVALID] */
  /*     5 */                     255u,  /* [INVALID] */
  /*     6 */                     255u,  /* [INVALID] */
  /*     7 */                     255u,  /* [INVALID] */
  /*     8 */                       0u,  /* [SSA_SOURCEADDR_ENHANCED_ETHERNET, /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3/DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3{Left}, /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987/DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987{Right}] */
  /*     9 */                       1u,  /* [SSA_SOURCEADDR_ENHANCED_CAN, /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42/DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42{Left}, /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76/DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76{Right}] */
  /*    10 */                       2u,  /* [SSA_SOURCEADDR_PTI_CAN] */
  /*    11 */                     255u,  /* [INVALID] */
  /*    12 */                     255u,  /* [INVALID] */
  /*    13 */                       3u,  /* [SSA_SOURCEADDR_INTERNAL_ETHERNET, /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c/DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c{Left}, /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528/DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528{Right}] */
  /*    14 */                     255u,  /* [INVALID] */
  /*    15 */                     255u   /* [INVALID] */
};
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_SecurityAccessLevel
**********************************************************************************************************************/
/** 
  \var    Ssa_SecurityAccessLevel
  \brief  Contains parameters of /MICROSAR/Ssa/SsaRightsM/SsaSecurityAccessLevel.
  \details
  Element    Description
  JobId  
  Level  
*/ 
#define SSA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_SecurityAccessLevelType, SSA_CONST) Ssa_SecurityAccessLevel[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    JobId  Level        Referable Keys */
  { /*     0 */   40u,    2u },  /* [/ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_3, /ActiveEcuC/Ssa/SsaRightsM] */
  { /*     1 */   40u,   48u },  /* [/ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_5F, /ActiveEcuC/Ssa/SsaRightsM] */
  { /*     2 */   40u,   26u },  /* [/ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_SAR_Read, /ActiveEcuC/Ssa/SsaRightsM] */
  { /*     3 */   40u,   27u }   /* [/ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_SAR_Remove, /ActiveEcuC/Ssa/SsaRightsM] */
};
#define SSA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelBackendCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelBackendCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert (Value: TrustModelBackendCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_TrustModelBackendCertNameType, SSA_CONST) Ssa_TrustModelBackendCertName[21] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TrustModelBackendCertName  */
  /*     0 */                      0x54u,
  /*     1 */                      0x72u,
  /*     2 */                      0x75u,
  /*     3 */                      0x73u,
  /*     4 */                      0x74u,
  /*     5 */                      0x4Du,
  /*     6 */                      0x6Fu,
  /*     7 */                      0x64u,
  /*     8 */                      0x65u,
  /*     9 */                      0x6Cu,
  /*    10 */                      0x42u,
  /*    11 */                      0x61u,
  /*    12 */                      0x63u,
  /*    13 */                      0x6Bu,
  /*    14 */                      0x65u,
  /*    15 */                      0x6Eu,
  /*    16 */                      0x64u,
  /*    17 */                      0x43u,
  /*    18 */                      0x65u,
  /*    19 */                      0x72u,
  /*    20 */                      0x74u
};
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelBackendPeerCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelBackendPeerCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert (Value: TrustModelBackendPeerCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_TrustModelBackendPeerCertNameType, SSA_CONST) Ssa_TrustModelBackendPeerCertName[25] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TrustModelBackendPeerCertName  */
  /*     0 */                          0x54u,
  /*     1 */                          0x72u,
  /*     2 */                          0x75u,
  /*     3 */                          0x73u,
  /*     4 */                          0x74u,
  /*     5 */                          0x4Du,
  /*     6 */                          0x6Fu,
  /*     7 */                          0x64u,
  /*     8 */                          0x65u,
  /*     9 */                          0x6Cu,
  /*    10 */                          0x42u,
  /*    11 */                          0x61u,
  /*    12 */                          0x63u,
  /*    13 */                          0x6Bu,
  /*    14 */                          0x65u,
  /*    15 */                          0x6Eu,
  /*    16 */                          0x64u,
  /*    17 */                          0x50u,
  /*    18 */                          0x65u,
  /*    19 */                          0x65u,
  /*    20 */                          0x72u,
  /*    21 */                          0x43u,
  /*    22 */                          0x65u,
  /*    23 */                          0x72u,
  /*    24 */                          0x74u
};
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelEcuCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelEcuCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert (Value: TrustModelEcuCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_TrustModelEcuCertNameType, SSA_CONST) Ssa_TrustModelEcuCertName[17] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TrustModelEcuCertName  */
  /*     0 */                  0x54u,
  /*     1 */                  0x72u,
  /*     2 */                  0x75u,
  /*     3 */                  0x73u,
  /*     4 */                  0x74u,
  /*     5 */                  0x4Du,
  /*     6 */                  0x6Fu,
  /*     7 */                  0x64u,
  /*     8 */                  0x65u,
  /*     9 */                  0x6Cu,
  /*    10 */                  0x45u,
  /*    11 */                  0x63u,
  /*    12 */                  0x75u,
  /*    13 */                  0x43u,
  /*    14 */                  0x65u,
  /*    15 */                  0x72u,
  /*    16 */                  0x74u
};
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelEcuCsrCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelEcuCsrCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr (Value: TrustModelEcuCsr).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_TrustModelEcuCsrCertNameType, SSA_CONST) Ssa_TrustModelEcuCsrCertName[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TrustModelEcuCsrCertName  */
  /*     0 */                     0x54u,
  /*     1 */                     0x72u,
  /*     2 */                     0x75u,
  /*     3 */                     0x73u,
  /*     4 */                     0x74u,
  /*     5 */                     0x4Du,
  /*     6 */                     0x6Fu,
  /*     7 */                     0x64u,
  /*     8 */                     0x65u,
  /*     9 */                     0x6Cu,
  /*    10 */                     0x45u,
  /*    11 */                     0x63u,
  /*    12 */                     0x75u,
  /*    13 */                     0x43u,
  /*    14 */                     0x73u,
  /*    15 */                     0x72u
};
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelEcuPeerCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelEcuPeerCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert (Value: TrustModelEcuPeerCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_TrustModelEcuPeerCertNameType, SSA_CONST) Ssa_TrustModelEcuPeerCertName[21] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TrustModelEcuPeerCertName  */
  /*     0 */                      0x54u,
  /*     1 */                      0x72u,
  /*     2 */                      0x75u,
  /*     3 */                      0x73u,
  /*     4 */                      0x74u,
  /*     5 */                      0x4Du,
  /*     6 */                      0x6Fu,
  /*     7 */                      0x64u,
  /*     8 */                      0x65u,
  /*     9 */                      0x6Cu,
  /*    10 */                      0x45u,
  /*    11 */                      0x63u,
  /*    12 */                      0x75u,
  /*    13 */                      0x50u,
  /*    14 */                      0x65u,
  /*    15 */                      0x65u,
  /*    16 */                      0x72u,
  /*    17 */                      0x43u,
  /*    18 */                      0x65u,
  /*    19 */                      0x72u,
  /*    20 */                      0x74u
};
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelIntermediateCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelIntermediateCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert (Value: TrustModelIntermediateCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_TrustModelIntermediateCertNameType, SSA_CONST) Ssa_TrustModelIntermediateCertName[26] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TrustModelIntermediateCertName  */
  /*     0 */                           0x54u,
  /*     1 */                           0x72u,
  /*     2 */                           0x75u,
  /*     3 */                           0x73u,
  /*     4 */                           0x74u,
  /*     5 */                           0x4Du,
  /*     6 */                           0x6Fu,
  /*     7 */                           0x64u,
  /*     8 */                           0x65u,
  /*     9 */                           0x6Cu,
  /*    10 */                           0x49u,
  /*    11 */                           0x6Eu,
  /*    12 */                           0x74u,
  /*    13 */                           0x65u,
  /*    14 */                           0x72u,
  /*    15 */                           0x6Du,
  /*    16 */                           0x65u,
  /*    17 */                           0x64u,
  /*    18 */                           0x69u,
  /*    19 */                           0x61u,
  /*    20 */                           0x74u,
  /*    21 */                           0x65u,
  /*    22 */                           0x43u,
  /*    23 */                           0x65u,
  /*    24 */                           0x72u,
  /*    25 */                           0x74u
};
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelIntermediatePeerCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelIntermediatePeerCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert (Value: TrustModelIntermediatePeerCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_TrustModelIntermediatePeerCertNameType, SSA_CONST) Ssa_TrustModelIntermediatePeerCertName[30] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TrustModelIntermediatePeerCertName  */
  /*     0 */                               0x54u,
  /*     1 */                               0x72u,
  /*     2 */                               0x75u,
  /*     3 */                               0x73u,
  /*     4 */                               0x74u,
  /*     5 */                               0x4Du,
  /*     6 */                               0x6Fu,
  /*     7 */                               0x64u,
  /*     8 */                               0x65u,
  /*     9 */                               0x6Cu,
  /*    10 */                               0x49u,
  /*    11 */                               0x6Eu,
  /*    12 */                               0x74u,
  /*    13 */                               0x65u,
  /*    14 */                               0x72u,
  /*    15 */                               0x6Du,
  /*    16 */                               0x65u,
  /*    17 */                               0x64u,
  /*    18 */                               0x69u,
  /*    19 */                               0x61u,
  /*    20 */                               0x74u,
  /*    21 */                               0x65u,
  /*    22 */                               0x50u,
  /*    23 */                               0x65u,
  /*    24 */                               0x65u,
  /*    25 */                               0x72u,
  /*    26 */                               0x43u,
  /*    27 */                               0x65u,
  /*    28 */                               0x72u,
  /*    29 */                               0x74u
};
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelRootCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelRootCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelRootCert (Value: TrustModelRootCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_TrustModelRootCertNameType, SSA_CONST) Ssa_TrustModelRootCertName[18] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TrustModelRootCertName  */
  /*     0 */                   0x54u,
  /*     1 */                   0x72u,
  /*     2 */                   0x75u,
  /*     3 */                   0x73u,
  /*     4 */                   0x74u,
  /*     5 */                   0x4Du,
  /*     6 */                   0x6Fu,
  /*     7 */                   0x64u,
  /*     8 */                   0x65u,
  /*     9 */                   0x6Cu,
  /*    10 */                   0x52u,
  /*    11 */                   0x6Fu,
  /*    12 */                   0x6Fu,
  /*    13 */                   0x74u,
  /*    14 */                   0x43u,
  /*    15 */                   0x65u,
  /*    16 */                   0x72u,
  /*    17 */                   0x74u
};
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_UniqueEcuId
**********************************************************************************************************************/
/** 
  \var    Ssa_UniqueEcuId
  \details
  Element                             Description
  UniqueEcuIdsUniqueEcuIdsEndIdx      the end index of the 1:n relation pointing to Ssa_UniqueEcuIds
  UniqueEcuIdsUniqueEcuIdsStartIdx    the start index of the 1:n relation pointing to Ssa_UniqueEcuIds
*/ 
#define SSA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_UniqueEcuIdType, SSA_CONST) Ssa_UniqueEcuId[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    UniqueEcuIdsUniqueEcuIdsEndIdx  UniqueEcuIdsUniqueEcuIdsStartIdx */
  { /*     0 */                             9u,                               0u },
  { /*     1 */                            18u,                               9u }
};
#define SSA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_UniqueEcuIds
**********************************************************************************************************************/
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Ssa_UniqueEcuIdsType, SSA_CONST) Ssa_UniqueEcuIds[18] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     UniqueEcuIds      Referable Keys */
  /*     0 */         0x52u,  /* [RBTMFL174] */
  /*     1 */         0x42u,  /* [RBTMFL174] */
  /*     2 */         0x54u,  /* [RBTMFL174] */
  /*     3 */         0x4Du,  /* [RBTMFL174] */
  /*     4 */         0x46u,  /* [RBTMFL174] */
  /*     5 */         0x4Cu,  /* [RBTMFL174] */
  /*     6 */         0x31u,  /* [RBTMFL174] */
  /*     7 */         0x37u,  /* [RBTMFL174] */
  /*     8 */         0x34u,  /* [RBTMFL174] */
  /*     9 */         0x52u,  /* [RBTMFR174] */
  /*    10 */         0x42u,  /* [RBTMFR174] */
  /*    11 */         0x54u,  /* [RBTMFR174] */
  /*    12 */         0x4Du,  /* [RBTMFR174] */
  /*    13 */         0x46u,  /* [RBTMFR174] */
  /*    14 */         0x52u,  /* [RBTMFR174] */
  /*    15 */         0x31u,  /* [RBTMFR174] */
  /*    16 */         0x37u,  /* [RBTMFR174] */
  /*    17 */         0x34u   /* [RBTMFR174] */
};
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_DidHandled
**********************************************************************************************************************/
#define SSA_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Ssa_DidHandledType, SSA_VAR_NOINIT) Ssa_DidHandled[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define SSA_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  END OF FILE: Ssa_Cfg.c
 *********************************************************************************************************************/
