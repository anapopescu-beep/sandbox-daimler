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
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CryIf_Cfg.c
 *   Generation Time: 2023-08-16 14:35:31
 *           Project: CBD2000614_Bm - Version 1.0
 *          Delivery: CBD2200332_D02
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
#include "Crypto_30_LibCv.h"
#include "Crypto_30_vHsm.h"



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
CONST(CryIf_ChannelType, CRYIF_CONST) CryIf_Channel[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DriverObjectRef                                    CryptoFunctionsIdx  Id        Referable Keys */
  { /*     0 */ CryptoConf_CryptoDriverObject_Crypto_30_LibCv_Aes,                 0u, 0u },  /* [/ActiveEcuC/CryIf/CryIfChannel_CryptoCv_Fbl_Aes, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Aes:CsmChannelRef] */
  { /*     1 */ CryptoConf_CryptoDriverObject_Crypto_30_LibCv_Rng,                 0u, 1u },  /* [/ActiveEcuC/CryIf/CryIfChannel_CryptoCv_Fbl_Rng, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Rng:CsmChannelRef] */
  { /*     2 */ CryptoConf_CryptoDriverObject_Crypto_30_LibCv    ,                 0u, 2u },  /* [/ActiveEcuC/CryIf/CryIfChannel_CryptoCv_Fbl_Signature, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Standard:CsmChannelRef] */
  { /*     3 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Core,                 1u, 3u }   /* [/ActiveEcuC/CryIf/CryIfChannel_vHsm_Core, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Core:CsmChannelRef] */
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
  { /*     0 */                          TRUE, Crypto_30_LibCv_CancelJob, Crypto_30_LibCv_CertificateParse, Crypto_30_LibCv_CertificateVerify, Crypto_30_LibCv_KeyCopy, Crypto_30_LibCv_KeyDerive, Crypto_30_LibCv_KeyElementCopy, Crypto_30_LibCv_KeyElementCopyPartial, Crypto_30_LibCv_KeyElementGet, Crypto_30_LibCv_KeyElementIdsGet, Crypto_30_LibCv_KeyElementSet, Crypto_30_LibCv_KeyExchangeCalcPubVal, Crypto_30_LibCv_KeyExchangeCalcSecret, Crypto_30_LibCv_KeyGenerate, Crypto_30_LibCv_KeyValidSet, Crypto_30_LibCv_ProcessJob, Crypto_30_LibCv_RandomSeed },  /* [/ActiveEcuC/Crypto] */
  { /*     1 */                          TRUE, Crypto_30_vHsm_CancelJob , Crypto_30_vHsm_CertificateParse , Crypto_30_vHsm_CertificateVerify , Crypto_30_vHsm_KeyCopy , Crypto_30_vHsm_KeyDerive , Crypto_30_vHsm_KeyElementCopy , Crypto_30_vHsm_KeyElementCopyPartial , Crypto_30_vHsm_KeyElementGet , Crypto_30_vHsm_KeyElementIdsGet , Crypto_30_vHsm_KeyElementSet , Crypto_30_vHsm_KeyExchangeCalcPubVal , Crypto_30_vHsm_KeyExchangeCalcSecret , Crypto_30_vHsm_KeyGenerate , Crypto_30_vHsm_KeyValidSet , Crypto_30_vHsm_ProcessJob , Crypto_30_vHsm_RandomSeed  }   /* [/ActiveEcuC/Crypto_vHsm] */
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
CONST(CryIf_KeyType, CRYIF_CONST) CryIf_Key[63] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Ref                                                                             CryptoFunctionsIdx        Referable Keys */
  { /*     0 */ CryptoConf_CryptoKey_CryIfKey_Fbl_Decrypt_Aes128                              ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Fbl_Decrypt_Aes128, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Decrypt_Aes128_01:CsmKeyRef] */
  { /*     1 */ CryptoConf_CryptoKey_CryIfKey_Fbl_HashDummy                                   ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Fbl_HashDummy, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_HashDummy_01:CsmKeyRef] */
  { /*     2 */ CryptoConf_CryptoKey_CryIfKey_Fbl_Rng_Fips186                                 ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Fbl_Rng_Fips186, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Rng_Fips186_01:CsmKeyRef] */
  { /*     3 */ CryptoConf_CryptoKey_CryIfKey_Fbl_SecurityAccess_Ed25519                      ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Fbl_SecurityAccess_Ed25519, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_SecurityAccess_Ed25519:CsmKeyRef] */
  { /*     4 */ CryptoConf_CryptoKey_CryIfKey_Fbl_Signature_Ed25519                           ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Fbl_Signature_Ed25519, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Signature_Ed25519_01:CsmKeyRef] */
  { /*     5 */ CryptoConf_CryptoKey_CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA         ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA_01:CsmKeyRef] */
  { /*     6 */ CryptoConf_CryptoKey_CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA         ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA_01:CsmKeyRef] */
  { /*     7 */ CryptoConf_CryptoKey_CryIfKey_Ssa_SignatureRamKey_replacementAuthority        ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_SignatureRamKey_replacementAuthority, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SignatureRamKey_replacementAuthority:CsmKeyRef] */
  { /*     8 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelBackendCert_inHSM                 ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_TrustModelBackendCert_inHSM, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelBackendCert_inHSM:CsmKeyRef] */
  { /*     9 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelEcuCert_inHSM                     ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_TrustModelEcuCert_inHSM, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuCert_inHSM:CsmKeyRef] */
  { /*    10 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelIntermediateCert_inHSM            ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_TrustModelIntermediateCert_inHSM, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelIntermediateCert_inHSM:CsmKeyRef] */
  { /*    11 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelPrivateEcuUnique_StagingKey       ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_TrustModelPrivateEcuUnique_StagingKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey:CsmKeyRef] */
  { /*    12 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelRootCert_inHSM                    ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_TrustModelRootCert_inHSM, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelRootCert_inHSM:CsmKeyRef] */
  { /*    13 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPrivateKey                ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPrivateKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModel_Ecu_CsrPrivateKey:CsmKeyRef] */
  { /*    14 */ CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPublicKey                 ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModel_Ecu_CsrPublicKey:CsmKeyRef] */
  { /*    15 */ CryptoConf_CryptoKey_CryIfKey_vHsm_Info                                       ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_CryIfKey_vHsm_Info, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Info_01:CsmKeyRef] */
  { /*    16 */ CryptoConf_CryptoKey_CryptoKey_Fbl_Decrypt_Aes128                             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_Decrypt_Aes128, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Decrypt_Aes128:CsmKeyRef, /MICROSAR/Csm_Rec/CsmKeys/CsmKey_Fbl_Decrypt_Aes128:CsmKeyRef] */
  { /*    17 */ CryptoConf_CryptoKey_CryptoKey_Fbl_HashDummy                                  ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_HashDummy, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_HashDummy:CsmKeyRef, /MICROSAR/Csm_Rec/CsmKeys/CsmKey_Fbl_HashDummy:CsmKeyRef] */
  { /*    18 */ CryptoConf_CryptoKey_CryptoKey_Fbl_Fips186                                    ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_Rng_Fips186, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Rng_Fips186:CsmKeyRef, /MICROSAR/Csm_Rec/CsmKeys/CsmKey_Fbl_Rng_Fips186:CsmKeyRef] */
  { /*    19 */ CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Ed25519                          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_Signature_Ed25519, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Signature_Ed25519:CsmKeyRef, /MICROSAR/Csm_Rec/CsmKeys/CsmKey_Fbl_Signature_Ed25519:CsmKeyRef] */
  { /*    20 */ CryptoConf_CryptoKey_KeyM_Cert_Root                                           ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_KeyM_Cert_Root, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_Cert_Intermediate:CsmKeyRef, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_Cert_Root:CsmKeyRef] */
  { /*    21 */ CryptoConf_CryptoKey_KeyM_ECC_Intermediate                                    ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_KeyM_ECC_Intermediate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_ECC_Intermediate:CsmKeyRef] */
  { /*    22 */ CryptoConf_CryptoKey_KeyM_ECC_Root                                            ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_KeyM_ECC_Root, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_ECC_Root:CsmKeyRef] */
  { /*    23 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelBackend                      ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_KeyM_SigVerifyKey_TrustModelBackend, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelBackend:CsmKeyRef] */
  { /*    24 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelBackendPeer                  ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_KeyM_SigVerifyKey_TrustModelBackendPeer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelBackendPeer:CsmKeyRef] */
  { /*    25 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelEcuPeer                      ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_KeyM_SigVerifyKey_TrustModelEcuPeer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelEcuPeer:CsmKeyRef] */
  { /*    26 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelIntermediate                 ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_KeyM_SigVerifyKey_TrustModelIntermediate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelIntermediate:CsmKeyRef] */
  { /*    27 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer             ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer:CsmKeyRef] */
  { /*    28 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelRoot                         ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_KeyM_SigVerifyKey_TrustModelRoot, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelRoot:CsmKeyRef] */
  { /*    29 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx   ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx:CsmKeyRef] */
  { /*    30 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx   ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx:CsmKeyRef] */
  { /*    31 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx   ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx:CsmKeyRef] */
  { /*    32 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx:CsmKeyRef] */
  { /*    33 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx:CsmKeyRef] */
  { /*    34 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer                ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer:CsmKeyRef] */
  { /*    35 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_Ign_Stat                         ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_SSA_SecOC_Int_MacVerify_Ign_Stat, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_Ign_Stat:CsmKeyRef] */
  { /*    36 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1                ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1:CsmKeyRef] */
  { /*    37 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4                      ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4:CsmKeyRef] */
  { /*    38 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_VehSpd_8                         ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_SSA_SecOC_Int_MacVerify_VehSpd_8, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_VehSpd_8:CsmKeyRef] */
  { /*    39 */ CryptoConf_CryptoKey_Ssa_AesRamKey                                            ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_AesRamKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_AesRamKey:CsmKeyRef] */
  { /*    40 */ CryptoConf_CryptoKey_Ssa_Authentication                                       ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_Authentication, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_Authentication:CsmKeyRef] */
  { /*    41 */ CryptoConf_CryptoKey_Ssa_BackendCert                                          ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_BackendCert, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_BackendCert:CsmKeyRef] */
  { /*    42 */ CryptoConf_CryptoKey_Ssa_PduKeysMac                                           ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_PduKeysMac, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_PduKeysMac:CsmKeyRef] */
  { /*    43 */ CryptoConf_CryptoKey_Ssa_RandomSeed                                           ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_RandomSeed, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_RandomSeed:CsmKeyRef] */
  { /*    44 */ CryptoConf_CryptoKey_Ssa_RealTime                                             ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_RealTime, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_RealTime:CsmKeyRef] */
  { /*    45 */ CryptoConf_CryptoKey_Ssa_RootCert                                             ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_RootCert, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_RootCert:CsmKeyRef] */
  { /*    46 */ CryptoConf_CryptoKey_Ssa_SecurityAccessPublicKey                              ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_SecurityAccessPublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SecurityAccessPublicKey:CsmKeyRef] */
  { /*    47 */ CryptoConf_CryptoKey_Ssa_SharedSecretExchangeKey                              ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_SharedSecretExchangeKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SharedSecretExchangeKey:CsmKeyRef] */
  { /*    48 */ CryptoConf_CryptoKey_Ssa_SharedSecretHash                                     ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_SharedSecretHash, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SharedSecretHash:CsmKeyRef] */
  { /*    49 */ CryptoConf_CryptoKey_Ssa_SignatureRamKey                                      ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_SignatureRamKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SignatureRamKey:CsmKeyRef] */
    /* Index    Ref                                                                             CryptoFunctionsIdx        Referable Keys */
  { /*    50 */ CryptoConf_CryptoKey_Ssa_TickCount                                            ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TickCount, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TickCount:CsmKeyRef] */
  { /*    51 */ CryptoConf_CryptoKey_Ssa_TrustModelEcuPublicCsr_StagingKey                    ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModelEcuPublicCsr_StagingKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey:CsmKeyRef] */
  { /*    52 */ CryptoConf_CryptoKey_Ssa_TrustModelEcuPublic_LiveKey                          ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModelEcuPublic_LiveKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuPublic_LiveKey:CsmKeyRef] */
  { /*    53 */ CryptoConf_CryptoKey_Ssa_TrustModelPrivateEcu_LiveKey                         ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModelPrivateEcu_LiveKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcu_LiveKey:CsmKeyRef] */
  { /*    54 */ CryptoConf_CryptoKey_Ssa_VIN                                                  ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_VIN, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_VIN:CsmKeyRef] */
  { /*    55 */ CryptoConf_CryptoKey_vHSM_Custom_HSM_Version                                  ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_vHSM_Custom_HSM_Version, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHSM_Custom_HSM_Version:CsmKeyRef] */
  { /*    56 */ CryptoConf_CryptoKey_vHsm_Custom                                              ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_vHsm_Custom, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Custom:CsmKeyRef] */
  { /*    57 */ CryptoConf_CryptoKey_vHsm_FirmwareUpdate_Signature                            ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_vHsm_FirmwareUpdate_Signature, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_FirmwareUpdate_Signature:CsmKeyRef] */
  { /*    58 */ CryptoConf_CryptoKey_vHsm_Hardware                                            ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_vHsm_Hardware, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Hardware:CsmKeyRef] */
  { /*    59 */ CryptoConf_CryptoKey_vHsm_Info                                                ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_vHsm_Info, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Info:CsmKeyRef] */
  { /*    60 */ CryptoConf_CryptoKey_vHsm_Log                                                 ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_vHsm_Log, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Log:CsmKeyRef] */
  { /*    61 */ CryptoConf_CryptoKey_vHsm_RomKey0                                             ,                 1u },  /* [/ActiveEcuC/CryIf/CryIfKey_vHsm_RomKey0, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_RomKey0:CsmKeyRef] */
  { /*    62 */ CryptoConf_CryptoKey_vHsm_TRNG                                                ,                 1u }   /* [/ActiveEcuC/CryIf/CryIfKey_vHsm_TRNG, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_TRNG:CsmKeyRef] */
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





