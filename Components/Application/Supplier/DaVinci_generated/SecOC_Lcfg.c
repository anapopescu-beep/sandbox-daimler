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
 *            Module: SecOC
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SecOC_Lcfg.c
 *   Generation Time: 2023-07-10 14:36:04
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define V_IL_ASRSECOC_LCFG_SOURCE
/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/
/* PRQA  S 3673 EOF */ /* MD_MSR_Rule8.13 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "SecOC.h"
# include "SecOC_Lcfg.h"
# include "PduR_SecOC.h"
# include "SecOC_Cot.h"

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  SecOC_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    SecOC_RxPduInfo
  \details
  Element                                                   Description
  AuthenticationLayerId                                 
  DataId                                                
  SecuredRxPduVerfication                               
  AuthDataFreshness                                     
  AuthDataFreshnessLen                                  
  AuthDataFreshnessStartBytePosition                    
  AuthenticExternalId                                   
  AuthenticPduDataContainerAuthenticPduEndIdx               the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerAuthenticPduLength               the number of relations pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerAuthenticPduStartIdx             the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerDataToAuthenticateEndIdx         the end index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerDataToAuthenticateLength         the number of relations pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerDataToAuthenticateStartIdx       the start index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFreshnessVerifyValueEndIdx       the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFreshnessVerifyValueLength       the number of relations pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFreshnessVerifyValueStartIdx     the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticatorCacheEndIdx                                  the end index of the 1:n relation pointing to SecOC_AuthenticatorCache
  AuthenticatorCacheLength                                  the number of relations pointing to SecOC_AuthenticatorCache
  AuthenticatorCacheStartIdx                                the start index of the 1:n relation pointing to SecOC_AuthenticatorCache
  BuildAttempts                                         
  ClientServerVerificationStatusPropagationMode         
  DataIdFirstByte                                       
  DataIdSecondByte                                      
  ExternalFreshnessId                                   
  NumberOfMessagesToOverrideIdx                             the index of the 1:1 relation pointing to SecOC_NumberOfMessagesToOverride
  PduProcessing                                         
  PduType                                               
  RxSecuredPduInfoIdx                                       the index of the 1:1 relation pointing to SecOC_RxSecuredPduInfo
  SecuredPduDataContainerAuthenticPduEndIdx                 the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerAuthenticPduLength                 the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerAuthenticPduStartIdx               the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerSecuredPduEndIdx                   the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerSecuredPduLength                   the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerSecuredPduStartIdx                 the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTpSecuredPduEndIdx                 the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTpSecuredPduLength                 the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTpSecuredPduStartIdx               the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedAuthenticatorEndIdx       the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedAuthenticatorLength       the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedAuthenticatorStartIdx     the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedFreshnessValueEndIdx      the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedFreshnessValueLength      the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedFreshnessValueStartIdx    the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  TruncAuthStartBitInByte                               
  TruncFreshnessValueFirstByteShift                     
  TruncFreshnessValueSecondByteShift                    
  VerificationStatusPropagationMode                     
  VerificationStatusWithSecuredPduPropagationMode       
  VerifyAttempts                                        
  VerifyOverrideStatusIdx                                   the index of the 1:1 relation pointing to SecOC_VerifyOverrideStatus
  VerifyResultIdx                                           the index of the 1:1 relation pointing to SecOC_VerifyResult
  truncatedAuthenticationLength                         
  truncatedFreshnessValueLength                         
*/ 
#define SECOC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SecOC_RxPduInfoType, SECOC_CONST) SecOC_RxPduInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AuthenticationLayerId                                                     DataId  SecuredRxPduVerfication  AuthDataFreshness                            AuthDataFreshnessLen  AuthDataFreshnessStartBytePosition  AuthenticExternalId                      AuthenticPduDataContainerAuthenticPduEndIdx  AuthenticPduDataContainerAuthenticPduLength  AuthenticPduDataContainerAuthenticPduStartIdx  AuthenticPduDataContainerDataToAuthenticateEndIdx  AuthenticPduDataContainerDataToAuthenticateLength  AuthenticPduDataContainerDataToAuthenticateStartIdx  AuthenticPduDataContainerFreshnessVerifyValueEndIdx  AuthenticPduDataContainerFreshnessVerifyValueLength  AuthenticPduDataContainerFreshnessVerifyValueStartIdx  AuthenticatorCacheEndIdx  AuthenticatorCacheLength  AuthenticatorCacheStartIdx  BuildAttempts  ClientServerVerificationStatusPropagationMode                                DataIdFirstByte  DataIdSecondByte  ExternalFreshnessId  NumberOfMessagesToOverrideIdx  PduProcessing                            PduType                         RxSecuredPduInfoIdx  SecuredPduDataContainerAuthenticPduEndIdx  SecuredPduDataContainerAuthenticPduLength  SecuredPduDataContainerAuthenticPduStartIdx  SecuredPduDataContainerSecuredPduEndIdx  SecuredPduDataContainerSecuredPduLength  SecuredPduDataContainerSecuredPduStartIdx  SecuredPduDataContainerTpSecuredPduEndIdx  SecuredPduDataContainerTpSecuredPduLength  SecuredPduDataContainerTpSecuredPduStartIdx  SecuredPduDataContainerTruncatedAuthenticatorEndIdx  SecuredPduDataContainerTruncatedAuthenticatorLength  SecuredPduDataContainerTruncatedAuthenticatorStartIdx  SecuredPduDataContainerTruncatedFreshnessValueEndIdx  SecuredPduDataContainerTruncatedFreshnessValueLength  SecuredPduDataContainerTruncatedFreshnessValueStartIdx  TruncAuthStartBitInByte  TruncFreshnessValueFirstByteShift  TruncFreshnessValueSecondByteShift  VerificationStatusPropagationMode                                VerificationStatusWithSecuredPduPropagationMode                        VerifyAttempts  VerifyOverrideStatusIdx  VerifyResultIdx  truncatedAuthenticationLength  truncatedFreshnessValueLength        Referable Keys */
  { /*     0 */ CsmConf_CsmJob_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, 15576u,                    TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_6e617592,                                          6u,                                          4u,                                            2u,                                               11u,                                               11u,                                                  0u,                                                 11u,                                                  5u,                                                    6u,                       3u,                       3u,                         0u,            1u, SECOC_FAILURE_ONLY_CLIENTSERVERVERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO,           0x3Cu,            0xD8u,                  1u,                            1u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                  0u,                                        4u,                                        4u,                                          0u,                                      8u,                                      8u,                                        0u,                                        8u,                                        8u,                                          0u,                                                  8u,                                                  3u,                                                    5u,                                                   5u,                                                   1u,                                                     4u,                      0u,                                0u,                                 0u, SECOC_FAILURE_ONLY_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_NONE_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             0u,                      1u,              0u,                           24u,                            8u },  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx] */
  { /*     1 */ CsmConf_CsmJob_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, 37177u,                    TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_ae29c120,                                         18u,                                          4u,                                           14u,                                               23u,                                               11u,                                                 12u,                                                 23u,                                                  5u,                                                   18u,                       7u,                       3u,                         4u,            1u, SECOC_FAILURE_ONLY_CLIENTSERVERVERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO,           0x91u,            0x39u,                  1u,                            2u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                  1u,                                       12u,                                        4u,                                          8u,                                     16u,                                      8u,                                        8u,                                       16u,                                        8u,                                          8u,                                                 16u,                                                  3u,                                                   13u,                                                  13u,                                                   1u,                                                    12u,                      0u,                                0u,                                 0u, SECOC_FAILURE_ONLY_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_NONE_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             0u,                      2u,              1u,                           24u,                            8u },  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx] */
  { /*     2 */ CsmConf_CsmJob_SSA_SecOC_Int_MacVerify_Ign_Stat                         , 28212u,                    TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_c9c2269b,                                         30u,                                          4u,                                           26u,                                               35u,                                               11u,                                                 24u,                                                 35u,                                                  5u,                                                   30u,                      11u,                       3u,                         8u,            1u, SECOC_FAILURE_ONLY_CLIENTSERVERVERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO,           0x6Eu,            0x34u,                  1u,                            0u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                  2u,                                       20u,                                        4u,                                         16u,                                     24u,                                      8u,                                       16u,                                       24u,                                        8u,                                         16u,                                                 24u,                                                  3u,                                                   21u,                                                  21u,                                                   1u,                                                    20u,                      0u,                                0u,                                 0u, SECOC_FAILURE_ONLY_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_NONE_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             0u,                      0u,              2u,                           24u,                            8u }   /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx] */
};
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxSecuredPduInfo
**********************************************************************************************************************/
/** 
  \var    SecOC_RxSecuredPduInfo
  \details
  Element                              Description
  MessageLinkLen                   
  MessageLinkPos                   
  MessageLinkerStartByteInCryptoPdu
  MessageType                      
  MessagesLinkCryptoPduSrcBitOffset
  MinimumPduLength                 
  PduFixLength                     
  RxPduInfoIdx                         the index of the 1:1 relation pointing to SecOC_RxPduInfo
  SecuredPduDataContainerEndIdx        the end index of the 1:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerLength        the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerStartIdx      the start index of the 1:n relation pointing to SecOC_SecuredPduDataContainer
*/ 
#define SECOC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SecOC_RxSecuredPduInfoType, SECOC_CONST) SecOC_RxSecuredPduInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MessageLinkLen  MessageLinkPos  MessageLinkerStartByteInCryptoPdu  MessageType                                 MessagesLinkCryptoPduSrcBitOffset  MinimumPduLength  PduFixLength  RxPduInfoIdx  SecuredPduDataContainerEndIdx  SecuredPduDataContainerLength  SecuredPduDataContainerStartIdx        Referable Keys */
  { /*     0 */             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               4u,           4u,           0u,                            8u,                            8u,                              0u },  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx/SecOCRxSecuredPduLayer] */
  { /*     1 */             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               4u,           4u,           1u,                           16u,                            8u,                              8u },  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx/SecOCRxSecuredPduLayer] */
  { /*     2 */             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               4u,           4u,           2u,                           24u,                            8u,                             16u }   /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx/SecOCRxSecuredPduLayer] */
};
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_AuthenticPduDataContainer
**********************************************************************************************************************/
#define SECOC_START_SEC_CRYPTO_DRV_ALIGNED_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SecOC_AuthenticPduDataContainerType, SECOC_VAR_NO_INIT) SecOC_AuthenticPduDataContainer[35];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxDataToAuthenticate, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxSecOCDataFirstByteID] */
  /*     1 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxDataToAuthenticate, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxSecOCDataSecondByteID] */
  /*     2 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxDataToAuthenticate, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxDataToAuthenticate, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxFullAuthenticPdu] */
  /*     5 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxDataToAuthenticate, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxFullAuthenticPdu] */
  /*     6 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxDataToAuthenticate] */
  /*    10 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxDataToAuthenticate] */
  /*    11 */  /* [PaddingByte_bed3de0c] */
  /*    12 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxDataToAuthenticate, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxSecOCDataFirstByteID] */
  /*    13 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxDataToAuthenticate, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxSecOCDataSecondByteID] */
  /*    14 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_d97bab99_Rx, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxDataToAuthenticate, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_d97bab99_Rx, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxDataToAuthenticate, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxFullAuthenticPdu] */
  /*    17 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_d97bab99_Rx, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxDataToAuthenticate, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxFullAuthenticPdu] */
  /*    18 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxDataToAuthenticate] */
  /*    22 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxDataToAuthenticate] */
  /*    23 */  /* [PaddingByte_bed3de0c] */
  /*    24 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxDataToAuthenticate, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxSecOCDataFirstByteID] */
  /*    25 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxDataToAuthenticate, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxSecOCDataSecondByteID] */
  /*    26 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_1e3dc39f_Rx, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxDataToAuthenticate, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_1e3dc39f_Rx, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxDataToAuthenticate, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxFullAuthenticPdu] */
  /*    29 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_1e3dc39f_Rx, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxDataToAuthenticate, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxFullAuthenticPdu] */
  /*    30 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxDataToAuthenticate] */
  /*    34 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxDataToAuthenticate] */

#define SECOC_STOP_SEC_CRYPTO_DRV_ALIGNED_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_AuthenticatorCache
**********************************************************************************************************************/
#define SECOC_START_SEC_CRYPTO_DRV_ALIGNED_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SecOC_AuthenticatorCacheUType, SECOC_VAR_NO_INIT) SecOC_AuthenticatorCache;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxAuthenticatorCache] */
  /*     2 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxAuthenticatorCache] */
  /*     3 */  /* [PaddingByte_bed3de0c] */
  /*     4 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxAuthenticatorCache] */
  /*     6 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxAuthenticatorCache] */
  /*     7 */  /* [PaddingByte_bed3de0c] */
  /*     8 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxAuthenticatorCache] */
  /*    10 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxAuthenticatorCache] */

#define SECOC_STOP_SEC_CRYPTO_DRV_ALIGNED_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_Initialized
**********************************************************************************************************************/
/** 
  \var    SecOC_Initialized
  \brief  Initialization state of SecOC. TRUE, if SecOC_Init() has been called, else FALSE.
*/ 
#define SECOC_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SecOC_InitializedType, SECOC_VAR_CLEARED) SecOC_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define SECOC_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_NumberOfMessagesToOverride
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SecOC_NumberOfMessagesToOverrideUType, SECOC_VAR_NO_INIT) SecOC_NumberOfMessagesToOverride;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx] */

#define SECOC_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxAuthenticPduSizeOffset
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SecOC_RxAuthenticPduSizeOffsetUType, SECOC_VAR_NO_INIT) SecOC_RxAuthenticPduSizeOffset;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx] */

#define SECOC_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxBuildAttemptsCounter
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SecOC_RxBuildAttemptsCounterUType, SECOC_VAR_NO_INIT) SecOC_RxBuildAttemptsCounter;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx] */

#define SECOC_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxPduState
**********************************************************************************************************************/
/** 
  \var    SecOC_RxPduState
  \brief  The state variable is volatile because it is used to ensure data consistency
*/ 
#define SECOC_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(SecOC_RxPduStateUType, SECOC_VAR_NO_INIT) SecOC_RxPduState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx] */

#define SECOC_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxTpWrittenBytesCounter
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SecOC_RxTpWrittenBytesCounterUType, SECOC_VAR_NO_INIT) SecOC_RxTpWrittenBytesCounter;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx] */

#define SECOC_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_SecuredPduDataContainer
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SecOC_SecuredPduDataContainerType, SECOC_VAR_NO_INIT) SecOC_SecuredPduDataContainer[24];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxTpSecuredPdu] */
  /*     3 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxTpSecuredPdu] */
  /*     4 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxFullSecuredPdu, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxAuthenticInfo, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxTpSecuredPdu] */
  /*     5 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxFullSecuredPdu, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxAuthenticInfo, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxFullSecuredPdu, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxAuthenticInfo, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxTpSecuredPdu] */
  /*     7 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxFullSecuredPdu, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxAuthenticInfo, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxTpSecuredPdu] */
  /*     8 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_d97bab99_Rx, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_d97bab99_Rx, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxTpSecuredPdu] */
  /*    11 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_d97bab99_Rx, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxTpSecuredPdu] */
  /*    12 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxFullSecuredPdu, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxAuthenticInfo, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxTpSecuredPdu] */
  /*    13 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxFullSecuredPdu, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxAuthenticInfo, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxFullSecuredPdu, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxAuthenticInfo, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxTpSecuredPdu] */
  /*    15 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxFullSecuredPdu, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxAuthenticInfo, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxTpSecuredPdu] */
  /*    16 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_secured_87afaf29_Rx, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_1e3dc39f_Rx, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_secured_87afaf29_Rx, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_1e3dc39f_Rx, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxTpSecuredPdu] */
  /*    19 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_secured_87afaf29_Rx, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_1e3dc39f_Rx, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxTpSecuredPdu] */
  /*    20 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_secured_87afaf29_Rx, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxFullSecuredPdu, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxAuthenticInfo, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxTpSecuredPdu] */
  /*    21 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_secured_87afaf29_Rx, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxFullSecuredPdu, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxAuthenticInfo, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_secured_87afaf29_Rx, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxFullSecuredPdu, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxAuthenticInfo, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxTpSecuredPdu] */
  /*    23 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_secured_87afaf29_Rx, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxFullSecuredPdu, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxAuthenticInfo, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxTpSecuredPdu] */

#define SECOC_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_VerifyAttemptsCounter
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SecOC_VerifyAttemptsCounterUType, SECOC_VAR_NO_INIT) SecOC_VerifyAttemptsCounter;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx] */

#define SECOC_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_VerifyOverrideStatus
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SecOC_VerifyOverrideStatusUType, SECOC_VAR_NO_INIT) SecOC_VerifyOverrideStatus;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx] */

#define SECOC_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_VerifyResult
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SecOC_VerifyResultUType, SECOC_VAR_NO_INIT) SecOC_VerifyResult;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx] */

#define SECOC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


/* CSM callback functions */


/**********************************************************************************************************************
  END OF FILE: SecOC_Lcfg.c
**********************************************************************************************************************/


