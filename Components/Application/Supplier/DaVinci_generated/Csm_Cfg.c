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
 *            Module: Csm
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Csm_Cfg.c
 *   Generation Time: 2023-12-05 12:39:07
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define CSM_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Csm_Cfg.h"
#include "CryIf.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CSM_LOCAL)
# define CSM_LOCAL static
#endif

#if !defined (CSM_LOCAL_INLINE)
# define CSM_LOCAL_INLINE LOCAL_INLINE
#endif




/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Csm_BswCallbacks
**********************************************************************************************************************/
/** 
  \var    Csm_BswCallbacks
  \details
  Element           Description
  CallbackFunc43
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_BswCallbacksType, CSM_CONST) Csm_BswCallbacks[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CallbackFunc43                            Referable Keys */
  { /*     0 */ KeyM_CallbackNotificationSignature }   /* [/ActiveEcuC/Csm/CsmCallbacks/CsmCallback_SigVerify_TrustModelBackend, /ActiveEcuC/Csm/CsmCallbacks/CsmCallback_SigVerify_TrustModelEcu, /ActiveEcuC/Csm/CsmCallbacks/CsmCallback_SigVerify_TrustModelIntermediate, /ActiveEcuC/Csm/CsmCallbacks/CsmCallback_SigVerify_TrustModelRoot, /ActiveEcuC/Csm/CsmCallbacks/CsmCallback_SigVerify_TrustModelBackendPeer, /ActiveEcuC/Csm/CsmCallbacks/CsmCallback_SigVerify_TrustModelEcuPeer, /ActiveEcuC/Csm/CsmCallbacks/CsmCallback_SigVerify_TrustModelIntermediatePeer, /ActiveEcuC/Csm/CsmCallbacks/CsmCallback_SigVerify_AsrKeyM_Callback] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo[42] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     JobInfo         Referable Keys */
  /*     0 */ {0u, 0u}   ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_MacGenerate_PduKeyMac] */
  /*     1 */ {1u, 1u}   ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigGenerate_TrustModelEcuCsr_with_changeableKeys] */
  /*     2 */ {2u, 1u}   ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackend] */
  /*     3 */ {3u, 1u}   ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackendPeer] */
  /*     4 */ {4u, 1u}   ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcu] */
  /*     5 */ {5u, 1u}   ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuCsr_with_changeableKeys] */
  /*     6 */ {6u, 1u}   ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuPeer] */
  /*     7 */ {7u, 1u}   ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediate] */
  /*     8 */ {8u, 1u}   ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediatePeer] */
  /*     9 */ {9u, 1u}   ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelRoot] */
  /*    10 */ {10u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Bckl_Sw_Fx_Stat_ST3_010732c3] */
  /*    11 */ {11u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_ELC_Lvr_Stat_ST3_4a443aad] */
  /*    12 */ {12u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Ign_Stat_ST3_8f01dfcb] */
  /*    13 */ {13u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Impact2_ST3_0071e663] */
  /*    14 */ {14u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx] */
  /*    15 */ {15u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx] */
  /*    16 */ {16u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx] */
  /*    17 */ {17u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx] */
  /*    18 */ {18u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx] */
  /*    19 */ {19u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer] */
  /*    20 */ {20u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_Ign_Stat] */
  /*    21 */ {21u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1] */
  /*    22 */ {22u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PT4_PTCoor4] */
  /*    23 */ {23u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_VehSpd_8] */
  /*    24 */ {24u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SigVerify_KeyM_TrustModel] */
  /*    25 */ {25u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Decrypt_Aes128] */
  /*    26 */ {26u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Hash_Sha2_512] */
  /*    27 */ {27u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_RealTime] */
  /*    28 */ {28u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_TickCount] */
  /*    29 */ {29u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_Authentication] */
  /*    30 */ {30u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_RealTime] */
  /*    31 */ {31u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_TickCount] */
  /*    32 */ {32u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_VIN] */
  /*    33 */ {33u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Random_TRNG] */
  /*    34 */ {34u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_LiveKey] */
  /*    35 */ {35u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_changeableKey] */
  /*    36 */ {36u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding] */
  /*    37 */ {37u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding_HWA] */
  /*    38 */ {38u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey] */
  /*    39 */ {39u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey_HWA] */
  /*    40 */ {40u, 12u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_SecurityAccess] */
  /*    41 */ {41u, 1u}     /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_replacementAuthority] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobPrimitiveInfo
**********************************************************************************************************************/
/** 
  \var    Csm_JobPrimitiveInfo
  \brief  const uint32 callbackId; const Crypto_PrimitiveInfoType* primitiveInfo; const uint32 secureCounterId; const uint32 cryIfKeyId; const Crypto_ProcessingType processingType; const bool callbackUpdateNotification
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo[39] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     JobPrimitiveInfo                                                                                                                                            Referable Keys */
  /*     0 */ {0u, &Csm_PrimitiveInfo[4], 0x000000FFu, CryIfConf_CryIfKey_Ssa_PduKeysMac, CRYPTO_PROCESSING_SYNC, FALSE}                                             ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_MacGenerate_PduKeyMac] */
  /*     1 */ {0u, &Csm_PrimitiveInfo[8], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPrivateKey, CRYPTO_PROCESSING_SYNC, FALSE}         ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigGenerate_TrustModelEcuCsr_with_changeableKeys, /ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_changeableKey] */
  /*     2 */ {1u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelBackend, CRYPTO_PROCESSING_ASYNC, FALSE}                       ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackend] */
  /*     3 */ {2u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelBackendPeer, CRYPTO_PROCESSING_ASYNC, FALSE}                   ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackendPeer] */
  /*     4 */ {3u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelEcu, CRYPTO_PROCESSING_ASYNC, FALSE}                           ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcu] */
  /*     5 */ {0u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPublicKey, CRYPTO_PROCESSING_ASYNC, FALSE}         ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuCsr_with_changeableKeys] */
  /*     6 */ {5u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelEcuPeer, CRYPTO_PROCESSING_ASYNC, FALSE}                       ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuPeer] */
  /*     7 */ {6u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelIntermediate, CRYPTO_PROCESSING_ASYNC, FALSE}                  ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediate] */
  /*     8 */ {7u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer, CRYPTO_PROCESSING_ASYNC, FALSE}              ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediatePeer] */
  /*     9 */ {8u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelRoot, CRYPTO_PROCESSING_ASYNC, FALSE}                          ,  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelRoot] */
  /*    10 */ {0u, &Csm_PrimitiveInfo[9], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CSK_15576CRYPTO_ALGOFAM_AES128_3d4fd2d7, CRYPTO_PROCESSING_SYNC, FALSE}           ,  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Bckl_Sw_Fx_Stat_ST3_010732c3] */
  /*    11 */ {0u, &Csm_PrimitiveInfo[9], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CSK_37177CRYPTO_ALGOFAM_AES128_c64d457a, CRYPTO_PROCESSING_SYNC, FALSE}           ,  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_ELC_Lvr_Stat_ST3_4a443aad] */
  /*    12 */ {0u, &Csm_PrimitiveInfo[9], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CSK_28212CRYPTO_ALGOFAM_AES128_3d56a060, CRYPTO_PROCESSING_SYNC, FALSE}           ,  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Ign_Stat_ST3_8f01dfcb] */
  /*    13 */ {0u, &Csm_PrimitiveInfo[9], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CSK_27103CRYPTO_ALGOFAM_AES128_0b48e843, CRYPTO_PROCESSING_SYNC, FALSE}           ,  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Impact2_ST3_0071e663] */
  /*    14 */ {0u, &Csm_PrimitiveInfo[4], 0x000000FFu, CryIfConf_CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx, CRYPTO_PROCESSING_SYNC, FALSE}     ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx] */
  /*    15 */ {0u, &Csm_PrimitiveInfo[4], 0x000000FFu, CryIfConf_CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx, CRYPTO_PROCESSING_SYNC, FALSE}     ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx] */
  /*    16 */ {0u, &Csm_PrimitiveInfo[4], 0x000000FFu, CryIfConf_CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx, CRYPTO_PROCESSING_SYNC, FALSE}     ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx] */
  /*    17 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, CRYPTO_PROCESSING_SYNC, FALSE}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx] */
  /*    18 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, CRYPTO_PROCESSING_SYNC, FALSE}  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx] */
  /*    19 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer, CRYPTO_PROCESSING_SYNC, FALSE}                  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer] */
  /*    20 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_Ign_Stat, CRYPTO_PROCESSING_SYNC, FALSE}                           ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_Ign_Stat] */
  /*    21 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1, CRYPTO_PROCESSING_SYNC, FALSE}                  ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1] */
  /*    22 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4, CRYPTO_PROCESSING_SYNC, FALSE}                        ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PT4_PTCoor4] */
  /*    23 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_VehSpd_8, CRYPTO_PROCESSING_SYNC, FALSE}                           ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_VehSpd_8] */
  /*    24 */ {0u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelEcuPeer, CRYPTO_PROCESSING_SYNC, FALSE}                        ,  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SigVerify_KeyM_TrustModel] */
  /*    25 */ {0u, &Csm_PrimitiveInfo[5], 0x000000FFu, CryIfConf_CryIfKey_Ssa_AesRamKey, CRYPTO_PROCESSING_SYNC, FALSE}                                              ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Decrypt_Aes128] */
  /*    26 */ {0u, &Csm_PrimitiveInfo[3], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Ssa_Hash, CRYPTO_PROCESSING_SYNC, FALSE}                                          ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Hash_Sha2_512] */
  /*    27 */ {0u, &Csm_PrimitiveInfo[4], 0x000000FFu, CryIfConf_CryIfKey_Ssa_RealTime, CRYPTO_PROCESSING_SYNC, FALSE}                                               ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_RealTime] */
  /*    28 */ {0u, &Csm_PrimitiveInfo[4], 0x000000FFu, CryIfConf_CryIfKey_Ssa_TickCount, CRYPTO_PROCESSING_SYNC, FALSE}                                              ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_TickCount] */
  /*    29 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_Ssa_Authentication, CRYPTO_PROCESSING_SYNC, FALSE}                                         ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_Authentication] */
  /*    30 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_Ssa_RealTime, CRYPTO_PROCESSING_SYNC, FALSE}                                               ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_RealTime] */
  /*    31 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_Ssa_TickCount, CRYPTO_PROCESSING_SYNC, FALSE}                                              ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_TickCount] */
  /*    32 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_Ssa_VIN, CRYPTO_PROCESSING_SYNC, FALSE}                                                    ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_VIN] */
  /*    33 */ {0u, &Csm_PrimitiveInfo[6], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_TRNG, CRYPTO_PROCESSING_SYNC, FALSE}                                              ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Random_TRNG] */
  /*    34 */ {0u, &Csm_PrimitiveInfo[8], 0x000000FFu, CryIfConf_CryIfKey_Ssa_TrustModelEcuPrivateKey, CRYPTO_PROCESSING_SYNC, FALSE}                                ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_LiveKey] */
  /*    35 */ {0u, &Csm_PrimitiveInfo[1], 0x000000FFu, CryIfConf_CryIfKey_Ssa_SignatureRamKey, CRYPTO_PROCESSING_SYNC, FALSE}                                        ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey] */
  /*    36 */ {0u, &Csm_PrimitiveInfo[10], 0x000000FFu, CryIfConf_CryIfKey_Ssa_SignatureRamKey, CRYPTO_PROCESSING_SYNC, FALSE}                                       ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding_HWA, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey_HWA] */
  /*    37 */ {0u, &Csm_PrimitiveInfo[1], 0x000000FFu, CryIfConf_CryIfKey_Ssa_SecurityAccessPublicKey, CRYPTO_PROCESSING_SYNC, FALSE}                                ,  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_SecurityAccess] */
  /*    38 */ {0u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_SignatureRamKey_replacementAuthority, CRYPTO_PROCESSING_SYNC, FALSE}    /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_replacementAuthority] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobTable
**********************************************************************************************************************/
/** 
  \var    Csm_JobTable
  \brief  Contains parameters of /MICROSAR/Csm/CsmJobs/CsmJob.
  \details
  Element                Description
  BswCallbacksIdx        the index of the 0:1 relation pointing to Csm_BswCallbacks
  CsmKeyIdIdx            the index of the 1:1 relation pointing to one of Csm_Key
  JobIdx                 the index of the 0:1 relation pointing to Csm_Job
  JobPrimitiveInfoIdx    the index of the 1:1 relation pointing to Csm_JobPrimitiveInfo
  MaskedBits             contains bitcoded the boolean data of Csm_AsynchronousOfJobTable, Csm_BswCallbacksUsedOfJobTable, Csm_JobUsedOfJobTable, Csm_PrimitiveCallbackUpdateNotificationOfJobTable
  Priority               Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPriority.
  QueueRefIdx            the index of the 1:1 relation pointing to one of Csm_QueueInfo
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_JobTableType, CSM_CONST) Csm_JobTable[42] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BswCallbacksIdx                   CsmKeyIdIdx  JobIdx                   JobPrimitiveInfoIdx  MaskedBits  Priority  QueueRefIdx        Referable Keys */
  { /*     0 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         40u,                      0u,                  0u,      0x02u,       0u,          0u },  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_MacGenerate_PduKeyMac, /ActiveEcuC/Csm/CsmJobs] */
  { /*     1 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         15u, CSM_NO_JOBIDXOFJOBTABLE,                  1u,      0x00u,       1u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigGenerate_TrustModelEcuCsr_with_changeableKeys, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr:KeyMCertCsmSignatureGenerateJobRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmTrustModelEcuCsrSignatureGenerateJobRef] */
  { /*     2 */                               0u,         20u, CSM_NO_JOBIDXOFJOBTABLE,                  2u,      0x0Cu,       1u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackend, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert:KeyMCertCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmTrustModelBackendSignatureVerifyJobRef] */
  { /*     3 */                               0u,         21u, CSM_NO_JOBIDXOFJOBTABLE,                  3u,      0x0Cu,       1u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackendPeer, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert:KeyMCertCsmSignatureVerifyJobRef] */
  { /*     4 */                               0u,          9u, CSM_NO_JOBIDXOFJOBTABLE,                  4u,      0x0Cu,       1u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcu, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert:KeyMCertCsmSignatureVerifyJobRef] */
  { /*     5 */                               0u,         16u, CSM_NO_JOBIDXOFJOBTABLE,                  5u,      0x0Cu,       1u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuCsr_with_changeableKeys, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr:KeyMCertCsmSignatureVerifyJobRef] */
  { /*     6 */                               0u,         22u, CSM_NO_JOBIDXOFJOBTABLE,                  6u,      0x0Cu,       1u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuPeer, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert:KeyMCertCsmSignatureVerifyJobRef] */
  { /*     7 */                               0u,         23u, CSM_NO_JOBIDXOFJOBTABLE,                  7u,      0x0Cu,       1u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert:KeyMCertCsmSignatureVerifyJobRef] */
  { /*     8 */                               0u,         24u, CSM_NO_JOBIDXOFJOBTABLE,                  8u,      0x0Cu,       1u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediatePeer, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert:KeyMCertCsmSignatureVerifyJobRef] */
  { /*     9 */                               0u,         25u, CSM_NO_JOBIDXOFJOBTABLE,                  9u,      0x0Cu,       1u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelRoot, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert:KeyMCertCsmSignatureVerifyJobRef] */
  { /*    10 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          0u, CSM_NO_JOBIDXOFJOBTABLE,                 10u,      0x00u,       0u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Bckl_Sw_Fx_Stat_ST3_010732c3, /ActiveEcuC/Csm/CsmJobs] */
  { /*    11 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          3u, CSM_NO_JOBIDXOFJOBTABLE,                 11u,      0x00u,       0u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_ELC_Lvr_Stat_ST3_4a443aad, /ActiveEcuC/Csm/CsmJobs] */
  { /*    12 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          2u, CSM_NO_JOBIDXOFJOBTABLE,                 12u,      0x00u,       0u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Ign_Stat_ST3_8f01dfcb, /ActiveEcuC/Csm/CsmJobs] */
  { /*    13 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          1u, CSM_NO_JOBIDXOFJOBTABLE,                 13u,      0x00u,       0u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Impact2_ST3_0071e663, /ActiveEcuC/Csm/CsmJobs] */
  { /*    14 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         27u, CSM_NO_JOBIDXOFJOBTABLE,                 14u,      0x00u,       1u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx, /ActiveEcuC/Csm/CsmJobs] */
  { /*    15 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         28u, CSM_NO_JOBIDXOFJOBTABLE,                 15u,      0x00u,       1u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx, /ActiveEcuC/Csm/CsmJobs] */
  { /*    16 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         29u, CSM_NO_JOBIDXOFJOBTABLE,                 16u,      0x00u,       1u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx, /ActiveEcuC/Csm/CsmJobs] */
  { /*    17 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         30u, CSM_NO_JOBIDXOFJOBTABLE,                 17u,      0x00u,       1u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    18 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         31u, CSM_NO_JOBIDXOFJOBTABLE,                 18u,      0x00u,       1u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    19 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         32u, CSM_NO_JOBIDXOFJOBTABLE,                 19u,      0x00u,       1u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer, /ActiveEcuC/Csm/CsmJobs] */
  { /*    20 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         33u, CSM_NO_JOBIDXOFJOBTABLE,                 20u,      0x00u,       1u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_Ign_Stat, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    21 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         34u, CSM_NO_JOBIDXOFJOBTABLE,                 21u,      0x00u,       1u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1, /ActiveEcuC/Csm/CsmJobs] */
  { /*    22 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         35u, CSM_NO_JOBIDXOFJOBTABLE,                 22u,      0x00u,       1u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PT4_PTCoor4, /ActiveEcuC/Csm/CsmJobs] */
  { /*    23 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         36u, CSM_NO_JOBIDXOFJOBTABLE,                 23u,      0x00u,       1u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_VehSpd_8, /ActiveEcuC/Csm/CsmJobs] */
  { /*    24 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         22u, CSM_NO_JOBIDXOFJOBTABLE,                 24u,      0x00u,       1u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SigVerify_KeyM_TrustModel, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmTrustModelTempSignatureVerifyJobRef] */
  { /*    25 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         37u,                      1u,                 25u,      0x02u,       1u,          0u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Decrypt_Aes128, /ActiveEcuC/Csm/CsmJobs] */
  { /*    26 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          4u, CSM_NO_JOBIDXOFJOBTABLE,                 26u,      0x00u,       1u,          4u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Hash_Sha2_512, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmHashJobRef, /ActiveEcuC/Ssa/SsaRightsM:SsaRightsMCsmHashJobRef] */
  { /*    27 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         42u, CSM_NO_JOBIDXOFJOBTABLE,                 27u,      0x00u,       1u,          1u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_RealTime, /ActiveEcuC/Csm/CsmJobs] */
  { /*    28 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         48u, CSM_NO_JOBIDXOFJOBTABLE,                 28u,      0x00u,       1u,          1u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_TickCount, /ActiveEcuC/Csm/CsmJobs] */
  { /*    29 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         38u, CSM_NO_JOBIDXOFJOBTABLE,                 29u,      0x00u,       1u,          1u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_Authentication, /ActiveEcuC/Csm/CsmJobs] */
  { /*    30 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         42u, CSM_NO_JOBIDXOFJOBTABLE,                 30u,      0x00u,       1u,          1u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_RealTime, /ActiveEcuC/Csm/CsmJobs] */
  { /*    31 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         48u, CSM_NO_JOBIDXOFJOBTABLE,                 31u,      0x00u,       1u,          1u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_TickCount, /ActiveEcuC/Csm/CsmJobs] */
  { /*    32 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         49u, CSM_NO_JOBIDXOFJOBTABLE,                 32u,      0x00u,       1u,          1u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_VIN, /ActiveEcuC/Csm/CsmJobs] */
  { /*    33 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         17u, CSM_NO_JOBIDXOFJOBTABLE,                 33u,      0x00u,       0u,          2u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Random_TRNG, /ActiveEcuC/Csm/CsmJobs] */
  { /*    34 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         13u,                      2u,                 34u,      0x02u,       1u,          0u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_LiveKey, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmTrustModelEcuLiveSignatureGenerateJobRef] */
  { /*    35 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         15u,                      3u,                  1u,      0x02u,       1u,          0u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_changeableKey, /ActiveEcuC/Csm/CsmJobs] */
  { /*    36 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         47u,                      4u,                 35u,      0x02u,       1u,          0u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding, /ActiveEcuC/Csm/CsmJobs] */
  { /*    37 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         47u, CSM_NO_JOBIDXOFJOBTABLE,                 36u,      0x00u,       1u,          2u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding_HWA, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaCoding:SsaSignatureVerifyJob] */
  { /*    38 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         47u,                      5u,                 35u,      0x02u,       1u,          0u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey, /ActiveEcuC/Csm/CsmJobs] */
  { /*    39 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         47u, CSM_NO_JOBIDXOFJOBTABLE,                 36u,      0x00u,       0u,          2u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey_HWA, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaCertP:SsaCertPCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaRightsM:SsaRightsMCsmSignatureVerifyJobRef] */
  { /*    40 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         44u,                      6u,                 37u,      0x02u,      12u,          0u },  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_SecurityAccess, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_3:SsaCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_5F:SsaCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_SAR_Read:SsaCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_SAR_Remove:SsaCsmSignatureVerifyJobRef] */
  { /*    41 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          5u,                      7u,                 38u,      0x02u,       1u,          0u }   /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_replacementAuthority, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmSignatureVerifyReplacmentAuthorityJobRef] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Key
**********************************************************************************************************************/
/** 
  \var    Csm_Key
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmKeys/CsmKey.
  \details
  Element       Description
  CryIfKeyId    Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyRef.
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_KeyType, CSM_CONST) Csm_Key[50] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CryIfKeyId                                                                           Referable Keys */
  { /*     0 */ CryIfConf_CryIfKey_CryIfKey_CSK_15576CRYPTO_ALGOFAM_AES128_3d4fd2d7           },  /* [/ActiveEcuC/Csm/CsmKeys/CSK_15576CRYPTO_ALGOFAM_AES128_3d4fd2d7, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SECPDU_Bckl_Sw_Fx_Stat_ST3_010732c3:CsmJobKeyRef] */
  { /*     1 */ CryIfConf_CryIfKey_CryIfKey_CSK_27103CRYPTO_ALGOFAM_AES128_0b48e843           },  /* [/ActiveEcuC/Csm/CsmKeys/CSK_27103CRYPTO_ALGOFAM_AES128_0b48e843, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SECPDU_Impact2_ST3_0071e663:CsmJobKeyRef] */
  { /*     2 */ CryIfConf_CryIfKey_CryIfKey_CSK_28212CRYPTO_ALGOFAM_AES128_3d56a060           },  /* [/ActiveEcuC/Csm/CsmKeys/CSK_28212CRYPTO_ALGOFAM_AES128_3d56a060, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SECPDU_Ign_Stat_ST3_8f01dfcb:CsmJobKeyRef] */
  { /*     3 */ CryIfConf_CryIfKey_CryIfKey_CSK_37177CRYPTO_ALGOFAM_AES128_c64d457a           },  /* [/ActiveEcuC/Csm/CsmKeys/CSK_37177CRYPTO_ALGOFAM_AES128_c64d457a, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SECPDU_ELC_Lvr_Stat_ST3_4a443aad:CsmJobKeyRef] */
  { /*     4 */ CryIfConf_CryIfKey_CryIfKey_Ssa_Hash                                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_Hash, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Ssa_Hash_Sha2_512:CsmJobKeyRef] */
  { /*     5 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_SignatureRamKey_replacementAuthority },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SignatureRamKey_replacementAuthority, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_replacementAuthority:CsmJobKeyRef] */
  { /*     6 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModelBackendCert_inHSM          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelBackendCert_inHSM, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert:KeyMCertificateCsmKeyTargetRef] */
  { /*     7 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModelEcuCert_inHSM              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuCert_inHSM, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert:KeyMCertificateCsmKeyTargetRef] */
  { /*     8 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelEcuCsr                         },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Ssa/SsaKeyM:SsaCsmTrustModelEcuStagingPublicKeyRef] */
  { /*     9 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelEcu                            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuPublic_LiveKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcu:CsmJobKeyRef, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    10 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModelIntermediateCert_inHSM     },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelIntermediateCert_inHSM, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert:KeyMCertificateCsmKeyTargetRef] */
  { /*    11 */ CryIfConf_CryIfKey_Ssa_TrustModelEcuPrivateUniqueKey                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Ssa/SsaKeyM:SsaCsmTrustModelEcuStagingPrivateKeyRef] */
  { /*    12 */ CryIfConf_CryIfKey_Ssa_TrustModelEcuPrivateUniqueKey                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey_01, /ActiveEcuC/Csm/CsmKeys] */
  { /*    13 */ CryIfConf_CryIfKey_Ssa_TrustModelEcuPrivateKey                                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcu_LiveKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_LiveKey:CsmJobKeyRef, /ActiveEcuC/Ssa/SsaKeyM:SsaCsmTrustModelEcuLivePrivateKeyRef] */
  { /*    14 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModelRootCert_inHSM             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelRootCert_inHSM, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert:KeyMCertificateCsmKeyTargetRef] */
  { /*    15 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPrivateKey         },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModel_Ecu_CsrPrivateKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/KeyM_SigGenerate_TrustModelEcuCsr_with_changeableKeys:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_changeableKey:CsmJobKeyRef, /ActiveEcuC/Ssa/SsaKeyM:SsaCsmTrustModelEcuCsrPrivateKeyRef] */
  { /*    16 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPublicKey          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModel_Ecu_CsrPublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuCsr_with_changeableKeys:CsmJobKeyRef, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr:KeyMCertCsmSignatureVerifyKeyRef, /ActiveEcuC/Ssa/SsaKeyM:SsaCsmTrustModelEcuCsrPublicKeyRef] */
  { /*    17 */ CryIfConf_CryIfKey_CryIfKey_TRNG                                              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_TRNG, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Ssa_Random_TRNG:CsmJobKeyRef] */
  { /*    18 */ CryIfConf_CryIfKey_CryIfKey_vHsm_Info                                         },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Info, /ActiveEcuC/Csm/CsmKeys] */
  { /*    19 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_vHsm_Info                                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Info_01, /ActiveEcuC/Csm/CsmKeys] */
  { /*    20 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelBackend                        },  /* [/ActiveEcuC/Csm/CsmKeys/KeyM_SigVerifyKey_TrustModelBackend, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackend:CsmJobKeyRef, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    21 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelBackendPeer                    },  /* [/ActiveEcuC/Csm/CsmKeys/KeyM_SigVerifyKey_TrustModelBackendPeer, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackendPeer:CsmJobKeyRef, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    22 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelEcuPeer                        },  /* [/ActiveEcuC/Csm/CsmKeys/KeyM_SigVerifyKey_TrustModelEcuPeer, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuPeer:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/SSA_SigVerify_KeyM_TrustModel:CsmJobKeyRef, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    23 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelIntermediate                   },  /* [/ActiveEcuC/Csm/CsmKeys/KeyM_SigVerifyKey_TrustModelIntermediate, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediate:CsmJobKeyRef, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    24 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer               },  /* [/ActiveEcuC/Csm/CsmKeys/KeyM_SigVerifyKey_TrustModelIntermediatePeer, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediatePeer:CsmJobKeyRef, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    25 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelRoot                           },  /* [/ActiveEcuC/Csm/CsmKeys/KeyM_SigVerifyKey_TrustModelRoot, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelRoot:CsmJobKeyRef, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    26 */ CryIfConf_CryIfKey_vHSM_Version                                               },  /* [/ActiveEcuC/Csm/CsmKeys/Key_Custom_HSM_Version, /ActiveEcuC/Csm/CsmKeys] */
  { /*    27 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx     },  /* [/ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx:CsmJobKeyRef] */
  { /*    28 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx     },  /* [/ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx:CsmJobKeyRef] */
  { /*    29 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx     },  /* [/ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx:CsmJobKeyRef] */
  { /*    30 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx  },  /* [/ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx:CsmJobKeyRef] */
  { /*    31 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx  },  /* [/ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx:CsmJobKeyRef] */
  { /*    32 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer                  },  /* [/ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer:CsmJobKeyRef] */
  { /*    33 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_Ign_Stat                           },  /* [/ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_Ign_Stat, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_Ign_Stat:CsmJobKeyRef] */
  { /*    34 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1                  },  /* [/ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1:CsmJobKeyRef] */
  { /*    35 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4                        },  /* [/ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_PT4_PTCoor4, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PT4_PTCoor4:CsmJobKeyRef] */
  { /*    36 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_VehSpd_8                           },  /* [/ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_VehSpd_8, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_VehSpd_8:CsmJobKeyRef] */
  { /*    37 */ CryIfConf_CryIfKey_Ssa_AesRamKey                                              },  /* [/ActiveEcuC/Csm/CsmKeys/Ssa_AesRamKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Ssa_Decrypt_Aes128:CsmJobKeyRef] */
  { /*    38 */ CryIfConf_CryIfKey_Ssa_Authentication                                         },  /* [/ActiveEcuC/Csm/CsmKeys/Ssa_Authentication, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_Authentication:CsmJobKeyRef, /ActiveEcuC/Ssa/SsaSpecialDataIds/Ssa_AuthenticationBroadcast:SsaCsmKeyRef] */
  { /*    39 */ CryIfConf_CryIfKey_Saa_BackendCert                                            },  /* [/ActiveEcuC/Csm/CsmKeys/Ssa_BackendCert, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Ssa/SsaKeyM:SsaCsmDiagChainBackendCertKeyRef] */
  { /*    40 */ CryIfConf_CryIfKey_Ssa_PduKeysMac                                             },  /* [/ActiveEcuC/Csm/CsmKeys/Ssa_PduKeysMac, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/KeyM_MacGenerate_PduKeyMac:CsmJobKeyRef, /ActiveEcuC/Ssa/SsaKeyM:SsaCsmPduKeysMacKeyRef] */
  { /*    41 */ CryIfConf_CryIfKey_Ssa_RandomSeed                                             },  /* [/ActiveEcuC/Csm/CsmKeys/Ssa_RandomSeed, /ActiveEcuC/Csm/CsmKeys] */
  { /*    42 */ CryIfConf_CryIfKey_Ssa_RealTime                                               },  /* [/ActiveEcuC/Csm/CsmKeys/Ssa_RealTime, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_RealTime:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_RealTime:CsmJobKeyRef, /ActiveEcuC/Ssa/SsaSpecialDataIds/Ssa_RealtimeBroadcast:SsaCsmKeyRef] */
  { /*    43 */ CryIfConf_CryIfKey_Saa_RootCert                                               },  /* [/ActiveEcuC/Csm/CsmKeys/Ssa_RootCert, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Ssa/SsaKeyM:SsaCsmDiagChainRootCertKeyRef] */
  { /*    44 */ CryIfConf_CryIfKey_Ssa_SecurityAccessPublicKey                                },  /* [/ActiveEcuC/Csm/CsmKeys/Ssa_SecurityAccessPublicKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_SecurityAccess:CsmJobKeyRef] */
  { /*    45 */ CryIfConf_CryIfKey_Ssa_SharedSecretHash                                       },  /* [/ActiveEcuC/Csm/CsmKeys/Ssa_SharedSecretHash, /ActiveEcuC/Csm/CsmKeys] */
  { /*    46 */ CryIfConf_CryIfKey_Ssa_SharedSecretExchangeKey                                },  /* [/ActiveEcuC/Csm/CsmKeys/Ssa_SharedSecretKeyExchange, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Ssa/SsaKeyM:SsaCsmKeyExchangeKeyRef] */
  { /*    47 */ CryIfConf_CryIfKey_Ssa_SignatureRamKey                                        },  /* [/ActiveEcuC/Csm/CsmKeys/Ssa_SignatureRamKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding_HWA:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey_HWA:CsmJobKeyRef] */
  { /*    48 */ CryIfConf_CryIfKey_Ssa_TickCount                                              },  /* [/ActiveEcuC/Csm/CsmKeys/Ssa_TickCount, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_TickCount:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_TickCount:CsmJobKeyRef, /ActiveEcuC/Ssa/SsaSpecialDataIds/Ssa_TickcountBroadcast:SsaCsmKeyRef] */
  { /*    49 */ CryIfConf_CryIfKey_Ssa_VIN                                                    }   /* [/ActiveEcuC/Csm/CsmKeys/Ssa_VIN, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_VIN:CsmJobKeyRef, /ActiveEcuC/Ssa/SsaSpecialDataIds/Ssa_VINBroadcast:SsaCsmKeyRef] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_PrimitiveInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PrimitiveInfo                                                                                                                                Referable Keys */
  /*     0 */ {0u, CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_ED25519, 32u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}                            ,  /* [/ActiveEcuC/Csm/SigVerifyEd25519_Async/CsmSignatureVerify/SigVerifyEd25519_Async, /ActiveEcuC/Csm/SigVerifyEd25519_SSA/CsmSignatureVerify/SigVerifyEd25519_SSA] */
  /*     1 */ {0u, CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_ED25519, 32u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_SHA2_512}}                           ,  /* [/ActiveEcuC/Csm/SigVerifyEd25519ph_SyncAsync/CsmSignatureVerify/SigVerifyEd25519ph_SyncAsync] */
  /*     2 */ {0u, CRYPTO_MACVERIFY, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CMAC, CRYPTO_ALGOFAM_NOT_SET}}                                         ,  /* [/ActiveEcuC/Csm/MacVerifyAesCmac/CsmMacVerify/MacVerifyAesCmac] */
  /*     3 */ {64u, CRYPTO_HASH, {CRYPTO_ALGOFAM_SHA2_512, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}                                      ,  /* [/ActiveEcuC/Csm/Sha2_512/CsmHash/Sha2_512] */
  /*     4 */ {16u, CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CMAC, CRYPTO_ALGOFAM_NOT_SET}}                                      ,  /* [/ActiveEcuC/Csm/MacGenAesCmac/CsmMacGenerate/MacGenAesCmac] */
  /*     5 */ {80u, CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CBC, CRYPTO_ALGOFAM_NOT_SET}}                                           ,  /* [/ActiveEcuC/Csm/AES128Decrypt/CsmDecrypt/AES128Decrypt] */
  /*     6 */ {32u, CRYPTO_RANDOMGENERATE, {CRYPTO_ALGOFAM_RNG, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}                                 ,  /* [/ActiveEcuC/Csm/Random_TRNG/CsmRandom/Random_TRNG] */
  /*     7 */ {0u, CRYPTO_ENCRYPT, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CBC, CRYPTO_ALGOFAM_NOT_SET}}                                            ,  /* [/ActiveEcuC/Csm/AES128Encrypt/CsmEncrypt/AES128Encrypt] */
  /*     8 */ {64u, CRYPTO_SIGNATUREGENERATE, {CRYPTO_ALGOFAM_ED25519, 32u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}                         ,  /* [/ActiveEcuC/Csm/SigGenEd25519/CsmSignatureGenerate/SigGenEd25519, /ActiveEcuC/Csm/SigGenEd25519_Sync/CsmSignatureGenerate/SigGenEd25519_Sync] */
  /*     9 */ {0u, CRYPTO_MACVERIFY, {CRYPTO_ALGOFAM_AES, 128u, CRYPTO_ALGOMODE_CMAC, CRYPTO_ALGOFAM_NOT_SET}}                                        ,  /* [/ActiveEcuC/Csm/CMAC_AES_128_88396350/CsmMacVerify/CsmMacVerifyConfig] */
  /*    10 */ {0u, CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_ED25519, 32u, 176u, CRYPTO_ALGOFAM_SHA2_512} /*  Mode = Crypto_30_vHsm_Hwa_Ed25519Ph  */ }    /* [/ActiveEcuC/Csm/SigVerifyEd25519ph_SyncAsync_HWA/CsmSignatureVerify/SigVerifyEd25519ph_SyncAsync_HWA] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueInfo
**********************************************************************************************************************/
/** 
  \var    Csm_QueueInfo
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmQueues/CsmQueue.
  \details
  Element                 Description
  ChannelId               Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmChannelRef.
  JobObjSynchronousIdx    the index of the 0:1 relation pointing to Csm_Job
  JobPoolEndIdx           the end index of the 0:n relation pointing to Csm_Job
  JobPoolStartIdx         the start index of the 0:n relation pointing to Csm_Job
  MaskedBits              contains bitcoded the boolean data of Csm_JobObjSynchronousUsedOfQueueInfo, Csm_JobPoolUsedOfQueueInfo, Csm_JobSharingOfQueueInfo
  QueueEndIdx             the end index of the 1:n relation pointing to Csm_Queue
  QueueStartIdx           the start index of the 1:n relation pointing to Csm_Queue
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_QueueInfoType, CSM_CONST) Csm_QueueInfo[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ChannelId                                          JobObjSynchronousIdx                    JobPoolEndIdx                    JobPoolStartIdx                    MaskedBits  QueueEndIdx  QueueStartIdx        Referable Keys */
  { /*     0 */ CryIfConf_CryIfChannel_CryIfChannel              , CSM_NO_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO, CSM_NO_JOBPOOLENDIDXOFQUEUEINFO, CSM_NO_JOBPOOLSTARTIDXOFQUEUEINFO,      0x00u,          4u,            3u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/KeyM_MacGenerate_PduKeyMac:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_Decrypt_Aes128:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_LiveKey:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_changeableKey:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_SecurityAccess:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_replacementAuthority:CsmJobQueueRef] */
  { /*     1 */ CryIfConf_CryIfChannel_CryIfChannel_BcTp         ,                                    13u,                             14u,                               13u,      0x07u,          6u,            5u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_BcTp, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_RealTime:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_TickCount:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_Authentication:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_RealTime:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_TickCount:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_VIN:CsmJobQueueRef] */
  { /*     2 */ CryIfConf_CryIfChannel_CryIfChannel_Hwa          ,                                    15u,                             16u,                               15u,      0x07u,          8u,            7u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hwa, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Ssa_Random_TRNG:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding_HWA:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey_HWA:CsmJobQueueRef] */
  { /*     3 */ CryIfConf_CryIfChannel_CryIfChannel_KeyM         ,                                     8u,                             11u,                                9u,      0x07u,          2u,            0u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_KeyM, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/KeyM_SigGenerate_TrustModelEcuCsr_with_changeableKeys:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackend:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackendPeer:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcu:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuCsr_with_changeableKeys:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuPeer:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediatePeer:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelRoot:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SigVerify_KeyM_TrustModel:CsmJobQueueRef] */
  { /*     4 */ CryIfConf_CryIfChannel_CryIfChannel_Ssa_Hash     ,                                    14u,                             15u,                               14u,      0x07u,          7u,            6u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Ssa_Hash, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Ssa_Hash_Sha2_512:CsmJobQueueRef] */
  { /*     5 */ CryIfConf_CryIfChannel_CryIfChannel_TRNG         ,                                    12u,                             13u,                               12u,      0x07u,          5u,            4u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_TRNG, /ActiveEcuC/Csm/CsmQueues] */
  { /*     6 */ CryIfConf_CryIfChannel_SSA_SecOC_Int_CryIfChannel,                                    11u,                             12u,                               11u,      0x07u,          3u,            2u }   /* [/ActiveEcuC/Csm/CsmQueues/SSA_SecOC_Int_CsmQueue, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/SECPDU_Bckl_Sw_Fx_Stat_ST3_010732c3:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SECPDU_ELC_Lvr_Stat_ST3_4a443aad:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SECPDU_Ign_Stat_ST3_8f01dfcb:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SECPDU_Impact2_ST3_0071e663:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_Ign_Stat:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PT4_PTCoor4:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_VehSpd_8:CsmJobQueueRef] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Job
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_JobType, CSM_VAR_NOINIT) Csm_Job[16];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_MacGenerate_PduKeyMac] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Decrypt_Aes128] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_LiveKey] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_changeableKey] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_SecurityAccess] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_replacementAuthority] */
  /*     8 */  /* [CsmQueue_KeyM_SyncObj] */
  /*     9 */  /* [CsmQueue_KeyM_AsyncPool] */
  /*    10 */  /* [CsmQueue_KeyM_AsyncPool] */
  /*    11 */  /* [SSA_SecOC_Int_CsmQueue_AsyncPool, SSA_SecOC_Int_CsmQueue_SyncObj] */
  /*    12 */  /* [CsmQueue_TRNG_AsyncPool, CsmQueue_TRNG_SyncObj] */
  /*    13 */  /* [CsmQueue_BcTp_AsyncPool, CsmQueue_BcTp_SyncObj] */
  /*    14 */  /* [CsmQueue_Ssa_Hash_AsyncPool, CsmQueue_Ssa_Hash_SyncObj] */
  /*    15 */  /* [CsmQueue_Hwa_AsyncPool, CsmQueue_Hwa_SyncObj] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobState
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_JobStateType, CSM_VAR_NOINIT) Csm_JobState[42];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_MacGenerate_PduKeyMac, /ActiveEcuC/Csm/CsmJobs] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigGenerate_TrustModelEcuCsr_with_changeableKeys, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr:KeyMCertCsmSignatureGenerateJobRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmTrustModelEcuCsrSignatureGenerateJobRef] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackend, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert:KeyMCertCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmTrustModelBackendSignatureVerifyJobRef] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackendPeer, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert:KeyMCertCsmSignatureVerifyJobRef] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcu, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert:KeyMCertCsmSignatureVerifyJobRef] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuCsr_with_changeableKeys, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr:KeyMCertCsmSignatureVerifyJobRef] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuPeer, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert:KeyMCertCsmSignatureVerifyJobRef] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert:KeyMCertCsmSignatureVerifyJobRef] */
  /*     8 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediatePeer, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert:KeyMCertCsmSignatureVerifyJobRef] */
  /*     9 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelRoot, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert:KeyMCertCsmSignatureVerifyJobRef] */
  /*    10 */  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Bckl_Sw_Fx_Stat_ST3_010732c3, /ActiveEcuC/Csm/CsmJobs] */
  /*    11 */  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_ELC_Lvr_Stat_ST3_4a443aad, /ActiveEcuC/Csm/CsmJobs] */
  /*    12 */  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Ign_Stat_ST3_8f01dfcb, /ActiveEcuC/Csm/CsmJobs] */
  /*    13 */  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Impact2_ST3_0071e663, /ActiveEcuC/Csm/CsmJobs] */
  /*    14 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx, /ActiveEcuC/Csm/CsmJobs] */
  /*    15 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx, /ActiveEcuC/Csm/CsmJobs] */
  /*    16 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx, /ActiveEcuC/Csm/CsmJobs] */
  /*    17 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx:SecOCRxAuthServiceConfigRef] */
  /*    18 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx:SecOCRxAuthServiceConfigRef] */
  /*    19 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer, /ActiveEcuC/Csm/CsmJobs] */
  /*    20 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_Ign_Stat, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx:SecOCRxAuthServiceConfigRef] */
  /*    21 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1, /ActiveEcuC/Csm/CsmJobs] */
  /*    22 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PT4_PTCoor4, /ActiveEcuC/Csm/CsmJobs] */
  /*    23 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_VehSpd_8, /ActiveEcuC/Csm/CsmJobs] */
  /*    24 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SigVerify_KeyM_TrustModel, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmTrustModelTempSignatureVerifyJobRef] */
  /*    25 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Decrypt_Aes128, /ActiveEcuC/Csm/CsmJobs] */
  /*    26 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Hash_Sha2_512, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmHashJobRef, /ActiveEcuC/Ssa/SsaRightsM:SsaRightsMCsmHashJobRef] */
  /*    27 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_RealTime, /ActiveEcuC/Csm/CsmJobs] */
  /*    28 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_TickCount, /ActiveEcuC/Csm/CsmJobs] */
  /*    29 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_Authentication, /ActiveEcuC/Csm/CsmJobs] */
  /*    30 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_RealTime, /ActiveEcuC/Csm/CsmJobs] */
  /*    31 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_TickCount, /ActiveEcuC/Csm/CsmJobs] */
  /*    32 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_VIN, /ActiveEcuC/Csm/CsmJobs] */
  /*    33 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Random_TRNG, /ActiveEcuC/Csm/CsmJobs] */
  /*    34 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_LiveKey, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmTrustModelEcuLiveSignatureGenerateJobRef] */
  /*    35 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_changeableKey, /ActiveEcuC/Csm/CsmJobs] */
  /*    36 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding, /ActiveEcuC/Csm/CsmJobs] */
  /*    37 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding_HWA, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaCoding:SsaSignatureVerifyJob] */
  /*    38 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey, /ActiveEcuC/Csm/CsmJobs] */
  /*    39 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey_HWA, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaCertP:SsaCertPCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaRightsM:SsaRightsMCsmSignatureVerifyJobRef] */
  /*    40 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_SecurityAccess, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_3:SsaCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_5F:SsaCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_SAR_Read:SsaCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_SAR_Remove:SsaCsmSignatureVerifyJobRef] */
  /*    41 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_replacementAuthority, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmSignatureVerifyReplacmentAuthorityJobRef] */

#define CSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobToObjMap
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_SizeOfJobType, CSM_VAR_NOINIT) Csm_JobToObjMap[42];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_MacGenerate_PduKeyMac, /ActiveEcuC/Csm/CsmJobs] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigGenerate_TrustModelEcuCsr_with_changeableKeys, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr:KeyMCertCsmSignatureGenerateJobRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmTrustModelEcuCsrSignatureGenerateJobRef] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackend, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert:KeyMCertCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmTrustModelBackendSignatureVerifyJobRef] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackendPeer, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert:KeyMCertCsmSignatureVerifyJobRef] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcu, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert:KeyMCertCsmSignatureVerifyJobRef] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuCsr_with_changeableKeys, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr:KeyMCertCsmSignatureVerifyJobRef] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuPeer, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert:KeyMCertCsmSignatureVerifyJobRef] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert:KeyMCertCsmSignatureVerifyJobRef] */
  /*     8 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediatePeer, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert:KeyMCertCsmSignatureVerifyJobRef] */
  /*     9 */  /* [/ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelRoot, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert:KeyMCertCsmSignatureVerifyJobRef] */
  /*    10 */  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Bckl_Sw_Fx_Stat_ST3_010732c3, /ActiveEcuC/Csm/CsmJobs] */
  /*    11 */  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_ELC_Lvr_Stat_ST3_4a443aad, /ActiveEcuC/Csm/CsmJobs] */
  /*    12 */  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Ign_Stat_ST3_8f01dfcb, /ActiveEcuC/Csm/CsmJobs] */
  /*    13 */  /* [/ActiveEcuC/Csm/CsmJobs/SECPDU_Impact2_ST3_0071e663, /ActiveEcuC/Csm/CsmJobs] */
  /*    14 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx, /ActiveEcuC/Csm/CsmJobs] */
  /*    15 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx, /ActiveEcuC/Csm/CsmJobs] */
  /*    16 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx, /ActiveEcuC/Csm/CsmJobs] */
  /*    17 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx:SecOCRxAuthServiceConfigRef] */
  /*    18 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx:SecOCRxAuthServiceConfigRef] */
  /*    19 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer, /ActiveEcuC/Csm/CsmJobs] */
  /*    20 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_Ign_Stat, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/Ign_Stat_ST3_secured_87afaf29_Rx:SecOCRxAuthServiceConfigRef] */
  /*    21 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1, /ActiveEcuC/Csm/CsmJobs] */
  /*    22 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PT4_PTCoor4, /ActiveEcuC/Csm/CsmJobs] */
  /*    23 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_VehSpd_8, /ActiveEcuC/Csm/CsmJobs] */
  /*    24 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_SigVerify_KeyM_TrustModel, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmTrustModelTempSignatureVerifyJobRef] */
  /*    25 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Decrypt_Aes128, /ActiveEcuC/Csm/CsmJobs] */
  /*    26 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Hash_Sha2_512, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmHashJobRef, /ActiveEcuC/Ssa/SsaRightsM:SsaRightsMCsmHashJobRef] */
  /*    27 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_RealTime, /ActiveEcuC/Csm/CsmJobs] */
  /*    28 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_TickCount, /ActiveEcuC/Csm/CsmJobs] */
  /*    29 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_Authentication, /ActiveEcuC/Csm/CsmJobs] */
  /*    30 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_RealTime, /ActiveEcuC/Csm/CsmJobs] */
  /*    31 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_TickCount, /ActiveEcuC/Csm/CsmJobs] */
  /*    32 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_VIN, /ActiveEcuC/Csm/CsmJobs] */
  /*    33 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_Random_TRNG, /ActiveEcuC/Csm/CsmJobs] */
  /*    34 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_LiveKey, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmTrustModelEcuLiveSignatureGenerateJobRef] */
  /*    35 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_changeableKey, /ActiveEcuC/Csm/CsmJobs] */
  /*    36 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding, /ActiveEcuC/Csm/CsmJobs] */
  /*    37 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding_HWA, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaCoding:SsaSignatureVerifyJob] */
  /*    38 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey, /ActiveEcuC/Csm/CsmJobs] */
  /*    39 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey_HWA, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaCertP:SsaCertPCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaRightsM:SsaRightsMCsmSignatureVerifyJobRef] */
  /*    40 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_SecurityAccess, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_3:SsaCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_5F:SsaCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_SAR_Read:SsaCsmSignatureVerifyJobRef, /ActiveEcuC/Ssa/SsaRightsM/SsaSecurityAccessLevel_SAR_Remove:SsaCsmSignatureVerifyJobRef] */
  /*    41 */  /* [/ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_replacementAuthority, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMCsmSignatureVerifyReplacmentAuthorityJobRef] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Queue
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_QueueUType, CSM_VAR_NOINIT) Csm_Queue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_KeyM] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_KeyM] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/SSA_SecOC_Int_CsmQueue] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_TRNG] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_BcTp] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Ssa_Hash] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hwa] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueState
**********************************************************************************************************************/
/** 
  \var    Csm_QueueState
  \brief  Stores state of the asynchronous job queue.
  \details
  Element     Description
  Lock    
  QueueIdx    the index of the 1:1 relation pointing to Csm_Queue
*/ 
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_QueueStateType, CSM_VAR_NOINIT) Csm_QueueState[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/KeyM_MacGenerate_PduKeyMac:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_Decrypt_Aes128:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_LiveKey:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigGenerate_KeyM_TrustModel_with_changeableKey:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_SecurityAccess:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_replacementAuthority:CsmJobQueueRef] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_BcTp, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_RealTime:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_MacGen_TickCount:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_Authentication:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_RealTime:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_TickCount:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_MacVerify_VIN:CsmJobQueueRef] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hwa, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Ssa_Random_TRNG:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_Coding_HWA:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Ssa_SigVerify_RamKey_HWA:CsmJobQueueRef] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_KeyM, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/KeyM_SigGenerate_TrustModelEcuCsr_with_changeableKeys:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackend:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelBackendPeer:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcu:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuCsr_with_changeableKeys:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelEcuPeer:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelIntermediatePeer:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/KeyM_SigVerify_TrustModelRoot:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SigVerify_KeyM_TrustModel:CsmJobQueueRef] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Ssa_Hash, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Ssa_Hash_Sha2_512:CsmJobQueueRef] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_TRNG, /ActiveEcuC/Csm/CsmQueues] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmQueues/SSA_SecOC_Int_CsmQueue, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/SECPDU_Bckl_Sw_Fx_Stat_ST3_010732c3:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SECPDU_ELC_Lvr_Stat_ST3_4a443aad:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SECPDU_Ign_Stat_ST3_8f01dfcb:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SECPDU_Impact2_ST3_0071e663:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_Ign_Stat:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_PT4_PTCoor4:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_SecOC_Int_MacVerify_VehSpd_8:CsmJobQueueRef] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/





