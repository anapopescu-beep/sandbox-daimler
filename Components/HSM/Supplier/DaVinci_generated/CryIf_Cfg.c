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
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CryIf_Cfg.c
 *   Generation Time: 2023-08-16 13:28:24
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

#define CRYIF_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "CryIf_Cfg.h"
#include "CryIf.h"
#include "Crypto_30_Hwa.h"
#include "Crypto_30_vHsm_Core.h"
#include "Crypto_30_LibCv.h"
#include "Crypto_30_vHsm_Custom.h"
#include "Crypto_30_KeyM.h"



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
CONST(CryIf_ChannelType, CRYIF_CONST) CryIf_Channel[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DriverObjectRef                                       CryptoFunctionsIdx  Id         Referable Keys */
  { /*     0 */ CryptoConf_CryptoDriverObject_vHsm_Core             ,                 1u,  0u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_Core, /ActiveEcuC/CryIf, /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance:vHsmDriverObjectMapping, /ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped:vHsmChannelRef] */
  { /*     1 */ CryptoConf_CryptoDriverObject_vHsm_Hwa              ,                 0u,  1u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_Hwa, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Hwa:CsmChannelRef, /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance:vHsmDriverObjectMapping, /ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped:vHsmChannelRef] */
  { /*     2 */ CryptoConf_CryptoDriverObject_vHsm_Hwa_HighPrio     ,                 0u,  2u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_Hwa_HighPrio, /ActiveEcuC/CryIf, /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance:vHsmDriverObjectMapping, /ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_HighPrio:vHsmChannelRef] */
  { /*     3 */ CryptoConf_CryptoDriverObject_Crypto_30_KeyM        ,                 4u,  3u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_KeyM, /ActiveEcuC/CryIf, /ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped:vHsmChannelRef] */
  { /*     4 */ CryptoConf_CryptoDriverObject_vHsm_LibCv_KeyM       ,                 2u,  4u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_KeyM_LibCv, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_KeyM:CsmChannelRef, /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance:vHsmDriverObjectMapping, /ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped:vHsmChannelRef] */
  { /*     5 */ CryptoConf_CryptoDriverObject_vHsm_KeyManagement    ,                 1u,  5u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_KeyManagement, /ActiveEcuC/CryIf, /ActiveEcuC/vHsm/vHsmChannelMapping:vHsmKeyManagementChannel, /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance:vHsmDriverObjectMapping, /ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped:vHsmChannelRef] */
  { /*     6 */ CryptoConf_CryptoDriverObject_vHsm_LibCv            ,                 2u,  6u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_LibCv:CsmChannelRef, /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance:vHsmDriverObjectMapping, /ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped:vHsmChannelRef] */
  { /*     7 */ CryptoConf_CryptoDriverObject_vHsm_LibCv_HighPrio   ,                 2u,  7u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_HighPrio, /ActiveEcuC/CryIf, /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance:vHsmDriverObjectMapping, /ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_HighPrio:vHsmChannelRef] */
  { /*     8 */ CryptoConf_CryptoDriverObject_vHsm_LibCv_vHsmUpd_Dec,                 2u,  8u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_vHsmUpd_Dec, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_Decrypt:CsmChannelRef, /ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped:vHsmChannelRef] */
  { /*     9 */ CryptoConf_CryptoDriverObject_vHsm_LibCv_vHsmUpd_Enc,                 2u,  9u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_vHsmUpd_Enc, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_Encrypt:CsmChannelRef, /ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped:vHsmChannelRef] */
  { /*    10 */ CryptoConf_CryptoDriverObject_vHsm_LibCv_vHsmUpd_Mac,                 2u, 10u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_vHsmUpd_Mac, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_MacGenerate:CsmChannelRef, /ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped:vHsmChannelRef] */
  { /*    11 */ CryptoConf_CryptoDriverObject_vHsm_LibCv_vHsmUpd_Sig,                 2u, 11u }   /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_vHsmUpd_Sig, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_SignatureVerify:CsmChannelRef, /ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped:vHsmChannelRef] */
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
CONST(CryIf_CryptoFunctionsType, CRYIF_CONST) CryIf_CryptoFunctions[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SupportsKeyElementCopyPartial  CancelJob                        CertificateParse                        CertificateVerify                        KeyCopy                        KeyDerive                        KeyElementCopy                        KeyElementCopyPartial                  KeyElementGet                        KeyElementIdsGet                        KeyElementSet                        KeyExchangeCalcPubVal                        KeyExchangeCalcSecret                        KeyGenerate                        KeyValidSet                        ProcessJob                        RandomSeed                              Referable Keys */
  { /*     0 */                         FALSE, Crypto_30_Hwa_CancelJob        , Crypto_30_Hwa_CertificateParse        , Crypto_30_Hwa_CertificateVerify        , Crypto_30_Hwa_KeyCopy        , Crypto_30_Hwa_KeyDerive        , Crypto_30_Hwa_KeyElementCopy        , CryIf_KeyElementCopyPartial_Stub     , Crypto_30_Hwa_KeyElementGet        , Crypto_30_Hwa_KeyElementIdsGet        , Crypto_30_Hwa_KeyElementSet        , Crypto_30_Hwa_KeyExchangeCalcPubVal        , Crypto_30_Hwa_KeyExchangeCalcSecret        , Crypto_30_Hwa_KeyGenerate        , Crypto_30_Hwa_KeyValidSet        , Crypto_30_Hwa_ProcessJob        , Crypto_30_Hwa_RandomSeed         },  /* [/ActiveEcuC/Crypto_30_Hwa] */
  { /*     1 */                         FALSE, Crypto_30_vHsm_Core_CancelJob  , Crypto_30_vHsm_Core_CertificateParse  , Crypto_30_vHsm_Core_CertificateVerify  , Crypto_30_vHsm_Core_KeyCopy  , Crypto_30_vHsm_Core_KeyDerive  , Crypto_30_vHsm_Core_KeyElementCopy  , CryIf_KeyElementCopyPartial_Stub     , Crypto_30_vHsm_Core_KeyElementGet  , Crypto_30_vHsm_Core_KeyElementIdsGet  , Crypto_30_vHsm_Core_KeyElementSet  , Crypto_30_vHsm_Core_KeyExchangeCalcPubVal  , Crypto_30_vHsm_Core_KeyExchangeCalcSecret  , Crypto_30_vHsm_Core_KeyGenerate  , Crypto_30_vHsm_Core_KeyValidSet  , Crypto_30_vHsm_Core_ProcessJob  , Crypto_30_vHsm_Core_RandomSeed   },  /* [/ActiveEcuC/vHsm_Core] */
  { /*     2 */                          TRUE, Crypto_30_LibCv_CancelJob      , Crypto_30_LibCv_CertificateParse      , Crypto_30_LibCv_CertificateVerify      , Crypto_30_LibCv_KeyCopy      , Crypto_30_LibCv_KeyDerive      , Crypto_30_LibCv_KeyElementCopy      , Crypto_30_LibCv_KeyElementCopyPartial, Crypto_30_LibCv_KeyElementGet      , Crypto_30_LibCv_KeyElementIdsGet      , Crypto_30_LibCv_KeyElementSet      , Crypto_30_LibCv_KeyExchangeCalcPubVal      , Crypto_30_LibCv_KeyExchangeCalcSecret      , Crypto_30_LibCv_KeyGenerate      , Crypto_30_LibCv_KeyValidSet      , Crypto_30_LibCv_ProcessJob      , Crypto_30_LibCv_RandomSeed       },  /* [/ActiveEcuC/Crypto_30_LibCv] */
  { /*     3 */                         FALSE, Crypto_30_vHsm_Custom_CancelJob, Crypto_30_vHsm_Custom_CertificateParse, Crypto_30_vHsm_Custom_CertificateVerify, Crypto_30_vHsm_Custom_KeyCopy, Crypto_30_vHsm_Custom_KeyDerive, Crypto_30_vHsm_Custom_KeyElementCopy, CryIf_KeyElementCopyPartial_Stub     , Crypto_30_vHsm_Custom_KeyElementGet, Crypto_30_vHsm_Custom_KeyElementIdsGet, Crypto_30_vHsm_Custom_KeyElementSet, Crypto_30_vHsm_Custom_KeyExchangeCalcPubVal, Crypto_30_vHsm_Custom_KeyExchangeCalcSecret, Crypto_30_vHsm_Custom_KeyGenerate, Crypto_30_vHsm_Custom_KeyValidSet, Crypto_30_vHsm_Custom_ProcessJob, Crypto_30_vHsm_Custom_RandomSeed },  /* [/ActiveEcuC/vHsm_Custom] */
  { /*     4 */                         FALSE, Crypto_30_KeyM_CancelJob       , Crypto_30_KeyM_CertificateParse       , Crypto_30_KeyM_CertificateVerify       , Crypto_30_KeyM_KeyCopy       , Crypto_30_KeyM_KeyDerive       , Crypto_30_KeyM_KeyElementCopy       , CryIf_KeyElementCopyPartial_Stub     , Crypto_30_KeyM_KeyElementGet       , Crypto_30_KeyM_KeyElementIdsGet       , Crypto_30_KeyM_KeyElementSet       , Crypto_30_KeyM_KeyExchangeCalcPubVal       , Crypto_30_KeyM_KeyExchangeCalcSecret       , Crypto_30_KeyM_KeyGenerate       , Crypto_30_KeyM_KeyValidSet       , Crypto_30_KeyM_ProcessJob       , Crypto_30_KeyM_RandomSeed        }   /* [/ActiveEcuC/Crypto_30_KeyM] */
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
CONST(CryIf_KeyType, CRYIF_CONST) CryIf_Key[62] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Ref                                                                             CryptoFunctionsIdx        Referable Keys */
  { /*     0 */ CryptoConf_CryptoKey_CryptoKey_Fbl_Decrypt_Aes128                             ,                 2u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_Decrypt_Aes128, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Decrypt_Aes128:CsmKeyRef] */
  { /*     1 */ CryptoConf_CryptoKey_CryptoKey_Fbl_HashDummy                                  ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_HashDummy, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_HashDummy:CsmKeyRef] */
  { /*     2 */ CryptoConf_CryptoKey_CryptoKey_Fbl_Fips186                                    ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_Rng_Fips186, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Rng_Fips186:CsmKeyRef] */
  { /*     3 */ CryptoConf_CryptoKey_CryptoKey_Fbl_SecurityAccess_Ed25519                     ,                 2u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_SecurityAccess_Ed25519, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_SecurityAccess_Ed25519:CsmKeyRef] */
  { /*     4 */ CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Ed25519                          ,                 2u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_Signature_Ed25519, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Signature_Ed25519:CsmKeyRef] */
  { /*     5 */ CryptoConf_CryptoKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA                  ,                 4u },  /* [/ActiveEcuC/CryIf/CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA:CsmKeyRef] */
  { /*     6 */ CryptoConf_CryptoKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA                  ,                 4u },  /* [/ActiveEcuC/CryIf/CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA:CsmKeyRef] */
  { /*     7 */ CryptoConf_CryptoKey_Ssa_SignatureRamKey_replacementAuthority                 ,                 2u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_SignatureRamKey_replacementAuthority, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SignatureRamKey_replacementAuthority:CsmKeyRef] */
  { /*     8 */ CryptoConf_CryptoKey_Ssa_TrustModelBackendCert_inHSM                          ,                 2u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModelBackendCert_inHSM, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelBackendCert_inHSM:CsmKeyRef] */
  { /*     9 */ CryptoConf_CryptoKey_Ssa_TrustModelEcuCert_inHSM                              ,                 2u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModelEcuCert_inHSM, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuCert_inHSM:CsmKeyRef] */
  { /*    10 */ CryptoConf_CryptoKey_Ssa_TrustModelIntermediateCert_inHSM                     ,                 2u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModelIntermediateCert_inHSM, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelIntermediateCert_inHSM:CsmKeyRef] */
  { /*    11 */ CryptoConf_CryptoKey_Ssa_TrustModelPrivateEcuUnique_StagingKey                ,                 2u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModelPrivateEcuUnique_StagingKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey:CsmKeyRef] */
  { /*    12 */ CryptoConf_CryptoKey_Ssa_TrustModelRootCert_inHSM                             ,                 2u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModelRootCert_inHSM, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelRootCert_inHSM:CsmKeyRef] */
  { /*    13 */ CryptoConf_CryptoKey_Ssa_TrustModel_Ecu_CsrPrivateKey                         ,                 2u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModel_Ecu_CsrPrivateKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModel_Ecu_CsrPrivateKey:CsmKeyRef] */
  { /*    14 */ CryptoConf_CryptoKey_Ssa_TrustModel_Ecu_CsrPublicKey                          ,                 2u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModel_Ecu_CsrPublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModel_Ecu_CsrPublicKey:CsmKeyRef] */
  { /*    15 */ CryptoConf_CryptoKey_vHsm_Info                                                ,                 2u },  /* [/ActiveEcuC/CryIf/CryIfKey_vHsm_Info, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Info_01:CsmKeyRef] */
  { /*    16 */ CryptoConf_CryptoKey_KeyM_Cert_Root                                           ,                 2u },  /* [/ActiveEcuC/CryIf/KeyM_Cert_Root, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_Cert_Intermediate:CsmKeyRef, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_Cert_Root:CsmKeyRef] */
  { /*    17 */ CryptoConf_CryptoKey_KeyM_ECC_Intermediate                                    ,                 2u },  /* [/ActiveEcuC/CryIf/KeyM_ECC_Intermediate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_ECC_Intermediate:CsmKeyRef] */
  { /*    18 */ CryptoConf_CryptoKey_KeyM_ECC_Root                                            ,                 2u },  /* [/ActiveEcuC/CryIf/KeyM_ECC_Root, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_ECC_Root:CsmKeyRef] */
  { /*    19 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelBackend                      ,                 2u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelBackend, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelBackend:CsmKeyRef] */
  { /*    20 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelBackendPeer                  ,                 2u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelBackendPeer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelBackendPeer:CsmKeyRef] */
  { /*    21 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelEcuPeer                      ,                 2u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelEcuPeer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelEcuPeer:CsmKeyRef] */
  { /*    22 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelIntermediate                 ,                 2u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelIntermediate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelIntermediate:CsmKeyRef] */
  { /*    23 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer             ,                 2u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelIntermediatePeer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer:CsmKeyRef] */
  { /*    24 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelRoot                         ,                 2u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelRoot, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelRoot:CsmKeyRef] */
  { /*    25 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx   ,                 2u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx:CsmKeyRef] */
  { /*    26 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx   ,                 2u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx:CsmKeyRef] */
  { /*    27 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx   ,                 2u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx:CsmKeyRef] */
  { /*    28 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx,                 2u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx:CsmKeyRef] */
  { /*    29 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx,                 2u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx:CsmKeyRef] */
  { /*    30 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer                ,                 2u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer:CsmKeyRef] */
  { /*    31 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_Ign_Stat                         ,                 2u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_Ign_Stat, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_Ign_Stat:CsmKeyRef] */
  { /*    32 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1                ,                 2u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1:CsmKeyRef] */
  { /*    33 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4                      ,                 2u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_PT4_PTCoor4, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4:CsmKeyRef] */
  { /*    34 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_VehSpd_8                         ,                 2u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_VehSpd_8, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_VehSpd_8:CsmKeyRef] */
  { /*    35 */ CryptoConf_CryptoKey_Ssa_AesRamKey                                            ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_AesRamKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_AesRamKey:CsmKeyRef] */
  { /*    36 */ CryptoConf_CryptoKey_Ssa_Authentication                                       ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_Authentication, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_Authentication:CsmKeyRef] */
  { /*    37 */ CryptoConf_CryptoKey_Ssa_BackendCert                                          ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_BackendCert, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_BackendCert:CsmKeyRef] */
  { /*    38 */ CryptoConf_CryptoKey_Ssa_PduKeysMac                                           ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_PduKeysMac, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_PduKeysMac:CsmKeyRef] */
  { /*    39 */ CryptoConf_CryptoKey_Ssa_RandomSeed                                           ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_RandomSeed, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_RandomSeed:CsmKeyRef] */
  { /*    40 */ CryptoConf_CryptoKey_Ssa_RealTime                                             ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_RealTime, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_RealTime:CsmKeyRef] */
  { /*    41 */ CryptoConf_CryptoKey_Ssa_RootCert                                             ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_RootCert, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_RootCert:CsmKeyRef] */
  { /*    42 */ CryptoConf_CryptoKey_Ssa_SecurityAccessPublicKey                              ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_SecurityAccessPublicKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SecurityAccessPublicKey:CsmKeyRef] */
  { /*    43 */ CryptoConf_CryptoKey_Ssa_SharedSecretExchangeKey                              ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_SharedSecretExchangeKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SharedSecretExchangeKey:CsmKeyRef] */
  { /*    44 */ CryptoConf_CryptoKey_Ssa_SharedSecretHash                                     ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_SharedSecretHash, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SharedSecretHash:CsmKeyRef] */
  { /*    45 */ CryptoConf_CryptoKey_Ssa_SignatureRamKey                                      ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_SignatureRamKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SignatureRamKey:CsmKeyRef] */
  { /*    46 */ CryptoConf_CryptoKey_Ssa_TickCount                                            ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_TickCount, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TickCount:CsmKeyRef] */
  { /*    47 */ CryptoConf_CryptoKey_Ssa_TrustModelEcuPublicCsr_StagingKey                    ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_TrustModelEcuPublicCsr_StagingKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey:CsmKeyRef] */
  { /*    48 */ CryptoConf_CryptoKey_vHsm_Custom                                              ,                 2u },  /* [/ActiveEcuC/CryIf/vHsm_Custom, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Custom:CsmKeyRef] */
  { /*    49 */ CryptoConf_CryptoKey_Ssa_TrustModelEcuPublic_LiveKey                          ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_TrustModelEcuPublic_LiveKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuPublic_LiveKey:CsmKeyRef] */
    /* Index    Ref                                                                             CryptoFunctionsIdx        Referable Keys */
  { /*    50 */ CryptoConf_CryptoKey_Ssa_TrustModelPrivateEcu_LiveKey                         ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_TrustModelPrivateEcu_LiveKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcu_LiveKey:CsmKeyRef] */
  { /*    51 */ CryptoConf_CryptoKey_Ssa_VIN                                                  ,                 2u },  /* [/ActiveEcuC/CryIf/Ssa_VIN, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_VIN:CsmKeyRef] */
  { /*    52 */ CryptoConf_CryptoKey_vHSM_Custom_HSM_Version                                  ,                 2u },  /* [/ActiveEcuC/CryIf/vHSM_Custom_HSM_Version, /ActiveEcuC/CryIf, /ActiveEcuC/vHsm/vHsmKeyMapping/vHsm_Custom:vHsmRoutedKeys] */
  { /*    53 */ CryptoConf_CryptoKey_vHsm_Hal_Hardware                                        ,                 0u },  /* [/ActiveEcuC/CryIf/vHsm_Hardware, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Hardware:CsmKeyRef] */
  { /*    54 */ CryptoConf_CryptoKey_vHsmInfo                                                 ,                 1u },  /* [/ActiveEcuC/CryIf/vHsm_Info, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsmInfo:CsmKeyRef, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Info:CsmKeyRef] */
  { /*    55 */ CryptoConf_CryptoKey_vHsm_FirmwareUpdate_Decrypt                              ,                 2u },  /* [/ActiveEcuC/CryIf/vHsm_FirmwareUpdate_Decrypt, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_FirmwareUpdate_Decrypt:CsmKeyRef, /ActiveEcuC/vHsm/vHsmKeyMapping:vHsmInternalOnlyKeys] */
  { /*    56 */ CryptoConf_CryptoKey_vHsmLog                                                  ,                 1u },  /* [/ActiveEcuC/CryIf/vHsm_Log, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsmLog:CsmKeyRef] */
  { /*    57 */ CryptoConf_CryptoKey_RomKey0                                                  ,                 0u },  /* [/ActiveEcuC/CryIf/vHsm_RomKey0, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ROM_KEY_0:CsmKeyRef] */
  { /*    58 */ CryptoConf_CryptoKey_vHsm_FirmwareUpdate_Encrypt                              ,                 2u },  /* [/ActiveEcuC/CryIf/vHsm_FirmwareUpdate_Encrypt, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_FirmwareUpdate_Encrypt:CsmKeyRef, /ActiveEcuC/vHsm/vHsmKeyMapping:vHsmInternalOnlyKeys] */
  { /*    59 */ CryptoConf_CryptoKey_vHsm_FirmwareUpdate_Mac                                  ,                 2u },  /* [/ActiveEcuC/CryIf/vHsm_FirmwareUpdate_Mac, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_FirmwareUpdate_Mac:CsmKeyRef, /ActiveEcuC/vHsm/vHsmKeyMapping:vHsmInternalOnlyKeys] */
  { /*    60 */ CryptoConf_CryptoKey_vHsm_TRNG                                                ,                 2u },  /* [/ActiveEcuC/CryIf/vHsm_TRNG, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_TRNG:CsmKeyRef] */
  { /*    61 */ CryptoConf_CryptoKey_vHsm_FirmwareUpdate_Signature                            ,                 2u }   /* [/ActiveEcuC/CryIf/vHsm_FirmwareUpdate_Signature, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_FirmwareUpdate_Signature:CsmKeyRef] */
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





