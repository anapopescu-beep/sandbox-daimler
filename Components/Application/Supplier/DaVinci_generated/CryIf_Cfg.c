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
 *            Module: CryIf
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CryIf_Cfg.c
 *   Generation Time: 2023-08-15 14:27:58
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define CRYIF_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "CryIf_Cfg.h"
#include "CryIf.h"
#include "Crypto_30_vHsm.h"
#include "Crypto_30_LibCv.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CRYIF_LOCAL)
# define CRYIF_LOCAL static
#endif

#if !defined (CRYIF_LOCAL_INLINE)
# define CRYIF_LOCAL_INLINE LOCAL_INLINE
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
  CryIf_Channel
**********************************************************************************************************************/
/** 
  \var    CryIf_Channel
  \brief  Contains parameters of /MICROSAR/CryIf/CryIfChannel.
  \details
  Element               Description
  DriverObjectRef       Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfChannel/CryIfDriverObjectRef.
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to CryIf_CryptoFunctions
  Id                    Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfChannel/CryIfChannelId.
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CryIf_ChannelType, CRYIF_CONST) CryIf_Channel[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DriverObjectRef                                              CryptoFunctionsIdx  Id        Referable Keys */
  { /*     0 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_LibCv         ,                 0u, 0u },  /* [/ActiveEcuC/CryIf/CryIfChannel, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue:CsmChannelRef] */
  { /*     1 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Hwa           ,                 0u, 1u },  /* [/ActiveEcuC/CryIf/CryIfChannel_Hwa, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Hwa:CsmChannelRef] */
  { /*     2 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_LibCv_HighPrio,                 0u, 2u },  /* [/ActiveEcuC/CryIf/CryIfChannel_BcTp, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_BcTp:CsmChannelRef] */
  { /*     3 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_LibCv         ,                 0u, 3u },  /* [/ActiveEcuC/CryIf/CryIfChannel_KeyM, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_KeyM:CsmChannelRef] */
  { /*     4 */ CryptoConf_CryptoDriverObject_CryptoDriverObject_Ssa_Hash  ,                 1u, 4u },  /* [/ActiveEcuC/CryIf/CryIfChannel_Ssa_Hash, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Ssa_Hash:CsmChannelRef] */
  { /*     5 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Hwa           ,                 0u, 5u },  /* [/ActiveEcuC/CryIf/CryIfChannel_TRNG, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_TRNG:CsmChannelRef] */
  { /*     6 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Hwa_HighPrio  ,                 0u, 6u }   /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_CryIfChannel, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/SSA_SecOC_Int_CsmQueue:CsmChannelRef] */
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CryIf_CryptoFunctions
**********************************************************************************************************************/
/** 
  \var    CryIf_CryptoFunctions
  \details
  Element                          Description
  SupportsKeyElementCopyPartial
  CancelJob                    
  CertificateParse             
  CertificateVerify            
  KeyCopy                      
  KeyDerive                    
  KeyElementCopy               
  KeyElementCopyPartial        
  KeyElementGet                
  KeyElementIdsGet             
  KeyElementSet                
  KeyExchangeCalcPubVal        
  KeyExchangeCalcSecret        
  KeyGenerate                  
  KeyValidSet                  
  ProcessJob                   
  RandomSeed                   
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CryIf_CryptoFunctionsType, CRYIF_CONST) CryIf_CryptoFunctions[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SupportsKeyElementCopyPartial  CancelJob                  CertificateParse                  CertificateVerify                  KeyCopy                  KeyDerive                  KeyElementCopy                  KeyElementCopyPartial                  KeyElementGet                  KeyElementIdsGet                  KeyElementSet                  KeyExchangeCalcPubVal                  KeyExchangeCalcSecret                  KeyGenerate                  KeyValidSet                  ProcessJob                  RandomSeed                        Referable Keys */
  { /*     0 */                          TRUE, Crypto_30_vHsm_CancelJob , Crypto_30_vHsm_CertificateParse , Crypto_30_vHsm_CertificateVerify , Crypto_30_vHsm_KeyCopy , Crypto_30_vHsm_KeyDerive , Crypto_30_vHsm_KeyElementCopy , Crypto_30_vHsm_KeyElementCopyPartial , Crypto_30_vHsm_KeyElementGet , Crypto_30_vHsm_KeyElementIdsGet , Crypto_30_vHsm_KeyElementSet , Crypto_30_vHsm_KeyExchangeCalcPubVal , Crypto_30_vHsm_KeyExchangeCalcSecret , Crypto_30_vHsm_KeyGenerate , Crypto_30_vHsm_KeyValidSet , Crypto_30_vHsm_ProcessJob , Crypto_30_vHsm_RandomSeed  },  /* [/ActiveEcuC/Crypto_30_vHsm] */
  { /*     1 */                          TRUE, Crypto_30_LibCv_CancelJob, Crypto_30_LibCv_CertificateParse, Crypto_30_LibCv_CertificateVerify, Crypto_30_LibCv_KeyCopy, Crypto_30_LibCv_KeyDerive, Crypto_30_LibCv_KeyElementCopy, Crypto_30_LibCv_KeyElementCopyPartial, Crypto_30_LibCv_KeyElementGet, Crypto_30_LibCv_KeyElementIdsGet, Crypto_30_LibCv_KeyElementSet, Crypto_30_LibCv_KeyExchangeCalcPubVal, Crypto_30_LibCv_KeyExchangeCalcSecret, Crypto_30_LibCv_KeyGenerate, Crypto_30_LibCv_KeyValidSet, Crypto_30_LibCv_ProcessJob, Crypto_30_LibCv_RandomSeed }   /* [/ActiveEcuC/Crypto] */
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CryIf_Key
**********************************************************************************************************************/
/** 
  \var    CryIf_Key
  \brief  Contains parameters of /MICROSAR/CryIf/CryIfKey.
  \details
  Element               Description
  Ref                   Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfKey/CryIfKeyRef.
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to CryIf_CryptoFunctions
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CryIf_KeyType, CRYIF_CONST) CryIf_Key[49] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Ref                                                                             CryptoFunctionsIdx        Referable Keys */
  { /*     0 */ CryptoConf_CryptoKey_CryptoKey_CSK_15576CRYPTO_ALGOFAM_AES128_3d4fd2d7        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CSK_15576CRYPTO_ALGOFAM_AES128_3d4fd2d7, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CSK_15576CRYPTO_ALGOFAM_AES128_3d4fd2d7:CsmKeyRef] */
  { /*     1 */ CryptoConf_CryptoKey_CryptoKey_CSK_27103CRYPTO_ALGOFAM_AES128_0b48e843        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CSK_27103CRYPTO_ALGOFAM_AES128_0b48e843, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CSK_27103CRYPTO_ALGOFAM_AES128_0b48e843:CsmKeyRef] */
  { /*     2 */ CryptoConf_CryptoKey_CryptoKey_CSK_28212CRYPTO_ALGOFAM_AES128_3d56a060        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CSK_28212CRYPTO_ALGOFAM_AES128_3d56a060, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CSK_28212CRYPTO_ALGOFAM_AES128_3d56a060:CsmKeyRef] */
  { /*     3 */ CryptoConf_CryptoKey_CryptoKey_CSK_37177CRYPTO_ALGOFAM_AES128_c64d457a        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CSK_37177CRYPTO_ALGOFAM_AES128_c64d457a, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CSK_37177CRYPTO_ALGOFAM_AES128_c64d457a:CsmKeyRef] */
  { /*     4 */ CryptoConf_CryptoKey_CryIfKey_Ssa_SignatureRamKey_replacementAuthority        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_SignatureRamKey_replacementAuthority, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SignatureRamKey_replacementAuthority:CsmKeyRef] */
  { /*     5 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelBackendCert_inHSM                 ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_TrustModelBackendCert_inHSM, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelBackendCert_inHSM:CsmKeyRef] */
  { /*     6 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelEcuCert_inHSM                     ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_TrustModelEcuCert_inHSM, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuCert_inHSM:CsmKeyRef] */
  { /*     7 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelIntermediateCert_inHSM            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_TrustModelIntermediateCert_inHSM, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelIntermediateCert_inHSM:CsmKeyRef] */
  { /*     8 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelRootCert_inHSM                    ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_TrustModelRootCert_inHSM, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelRootCert_inHSM:CsmKeyRef] */
  { /*     9 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPrivateKey                ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPrivateKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModel_Ecu_CsrPrivateKey:CsmKeyRef] */
  { /*    10 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPublicKey                 ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModel_Ecu_CsrPublicKey:CsmKeyRef] */
  { /*    11 */ CryptoConf_CryptoKey_CryIfKey_vHsm_Info                                       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_vHsm_Info, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Info_01:CsmKeyRef] */
  { /*    12 */ CryptoConf_CryptoKey_CryptoKey_Ssa_Hash                                       ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_Hash, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_Hash:CsmKeyRef] */
  { /*    13 */ CryptoConf_CryptoKey_vHsm_TRNG                                                ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_TRNG, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_TRNG:CsmKeyRef] */
  { /*    14 */ CryptoConf_CryptoKey_vHsm_Info                                                ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_vHsm_Info, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Info:CsmKeyRef] */
  { /*    15 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelBackend                      ,                 0u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelBackend, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/KeyM_SigVerifyKey_TrustModelBackend:CsmKeyRef] */
  { /*    16 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelBackendPeer                  ,                 0u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelBackendPeer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/KeyM_SigVerifyKey_TrustModelBackendPeer:CsmKeyRef] */
  { /*    17 */ CryptoConf_CryptoKey_Ssa_TrustModelEcuPublic_LiveKey                          ,                 0u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelEcu, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuPublic_LiveKey:CsmKeyRef] */
  { /*    18 */ CryptoConf_CryptoKey_Ssa_TrustModelEcuPublicCsr_StagingKey                    ,                 0u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelEcuCsr, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey:CsmKeyRef] */
  { /*    19 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelEcuPeer                      ,                 0u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelEcuPeer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/KeyM_SigVerifyKey_TrustModelEcuPeer:CsmKeyRef] */
  { /*    20 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelIntermediate                 ,                 0u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelIntermediate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/KeyM_SigVerifyKey_TrustModelIntermediate:CsmKeyRef] */
  { /*    21 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer             ,                 0u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelIntermediatePeer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/KeyM_SigVerifyKey_TrustModelIntermediatePeer:CsmKeyRef] */
  { /*    22 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelRoot                         ,                 0u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelRoot, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/KeyM_SigVerifyKey_TrustModelRoot:CsmKeyRef] */
  { /*    23 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx   ,                 0u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx:CsmKeyRef] */
  { /*    24 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx   ,                 0u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx:CsmKeyRef] */
  { /*    25 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx   ,                 0u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx:CsmKeyRef] */
  { /*    26 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx,                 0u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx:CsmKeyRef] */
  { /*    27 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx,                 0u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx:CsmKeyRef] */
  { /*    28 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer                ,                 0u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer:CsmKeyRef] */
  { /*    29 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_Ign_Stat                         ,                 0u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_Ign_Stat, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_Ign_Stat:CsmKeyRef] */
  { /*    30 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1                ,                 0u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1:CsmKeyRef] */
  { /*    31 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4                      ,                 0u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_PT4_PTCoor4, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_PT4_PTCoor4:CsmKeyRef] */
  { /*    32 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_VehSpd_8                         ,                 0u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_VehSpd_8, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/SSA_SecOC_Int_MacVerify_VehSpd_8:CsmKeyRef] */
  { /*    33 */ CryptoConf_CryptoKey_Ssa_BackendCert                                          ,                 0u },  /* [/ActiveEcuC/CryIf/Saa_BackendCert, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Ssa_BackendCert:CsmKeyRef] */
  { /*    34 */ CryptoConf_CryptoKey_Ssa_RootCert                                             ,                 0u },  /* [/ActiveEcuC/CryIf/Saa_RootCert, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Ssa_RootCert:CsmKeyRef] */
  { /*    35 */ CryptoConf_CryptoKey_Ssa_AesRamKey                                            ,                 0u },  /* [/ActiveEcuC/CryIf/Ssa_AesRamKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Ssa_AesRamKey:CsmKeyRef] */
  { /*    36 */ CryptoConf_CryptoKey_Ssa_Authentication                                       ,                 0u },  /* [/ActiveEcuC/CryIf/Ssa_Authentication, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Ssa_Authentication:CsmKeyRef] */
  { /*    37 */ CryptoConf_CryptoKey_Ssa_PduKeysMac                                           ,                 0u },  /* [/ActiveEcuC/CryIf/Ssa_PduKeysMac, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Ssa_PduKeysMac:CsmKeyRef] */
  { /*    38 */ CryptoConf_CryptoKey_Ssa_RandomSeed                                           ,                 0u },  /* [/ActiveEcuC/CryIf/Ssa_RandomSeed, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Ssa_RandomSeed:CsmKeyRef] */
  { /*    39 */ CryptoConf_CryptoKey_Ssa_RealTime                                             ,                 0u },  /* [/ActiveEcuC/CryIf/Ssa_RealTime, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Ssa_RealTime:CsmKeyRef] */
  { /*    40 */ CryptoConf_CryptoKey_Ssa_SecurityAccessPublicKey                              ,                 0u },  /* [/ActiveEcuC/CryIf/Ssa_SecurityAccessPublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Ssa_SecurityAccessPublicKey:CsmKeyRef] */
  { /*    41 */ CryptoConf_CryptoKey_Ssa_SharedSecretExchangeKey                              ,                 0u },  /* [/ActiveEcuC/CryIf/Ssa_SharedSecretExchangeKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Ssa_SharedSecretKeyExchange:CsmKeyRef] */
  { /*    42 */ CryptoConf_CryptoKey_Ssa_SharedSecretHash                                     ,                 0u },  /* [/ActiveEcuC/CryIf/Ssa_SharedSecretHash, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Ssa_SharedSecretHash:CsmKeyRef] */
  { /*    43 */ CryptoConf_CryptoKey_Ssa_SignatureRamKey                                      ,                 0u },  /* [/ActiveEcuC/CryIf/Ssa_SignatureRamKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Ssa_SignatureRamKey:CsmKeyRef] */
  { /*    44 */ CryptoConf_CryptoKey_Ssa_TickCount                                            ,                 0u },  /* [/ActiveEcuC/CryIf/Ssa_TickCount, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Ssa_TickCount:CsmKeyRef] */
  { /*    45 */ CryptoConf_CryptoKey_Ssa_TrustModelPrivateEcu_LiveKey                         ,                 0u },  /* [/ActiveEcuC/CryIf/Ssa_TrustModelEcuPrivateKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcu_LiveKey:CsmKeyRef] */
  { /*    46 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelPrivateEcuUnique_StagingKey       ,                 0u },  /* [/ActiveEcuC/CryIf/Ssa_TrustModelEcuPrivateUniqueKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey:CsmKeyRef, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey_01:CsmKeyRef] */
  { /*    47 */ CryptoConf_CryptoKey_Ssa_VIN                                                  ,                 0u },  /* [/ActiveEcuC/CryIf/Ssa_VIN, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Ssa_VIN:CsmKeyRef] */
  { /*    48 */ CryptoConf_CryptoKey_vHSM_Custom_HSM_Version                                  ,                 0u }   /* [/ActiveEcuC/CryIf/vHSM_Version, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/Key_Custom_HSM_Version:CsmKeyRef] */
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/





