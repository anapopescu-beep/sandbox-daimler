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
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Csm_Cfg.c
 *   Generation Time: 2023-08-07 13:44:29
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
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
  Csm_JobInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     JobInfo        Referable Keys */
  /*     0 */ {0u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc] */
  /*     1 */ {1u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc] */
  /*     2 */ {2u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Decrypt] */
  /*     3 */ {3u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Encrypt] */
  /*     4 */ {4u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_MacGenerate] */
  /*     5 */ {5u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_SignatureVerify] */
  /*     6 */ {6u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Intermediate] */
  /*     7 */ {7u, 1u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Root] */
  /*     8 */ {8u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Decrypt] */
  /*     9 */ {9u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Encrypt] */
  /*    10 */ {10u, 1u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random] */
  /*    11 */ {11u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate] */
  /*    12 */ {12u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecurityAccess_Ed25519Sha512] */
  /*    13 */ {13u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512] */
  /*    14 */ {14u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512] */
  /*    15 */ {15u, 1u}    /* [/ActiveEcuC/Csm/CsmJobs/SSA_KeyPairGenerationEd25519] */
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
CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     JobPrimitiveInfo                                                                                                                                     Referable Keys */
  /*     0 */ {0u, &Csm_PrimitiveInfo[5], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_Decrypt_Aes128, CRYPTO_PROCESSING_SYNC, FALSE}                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc] */
  /*     1 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_Decrypt_Aes128, CRYPTO_PROCESSING_SYNC, FALSE}                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc] */
  /*     2 */ {0u, &Csm_PrimitiveInfo[5], 0x000000FFu, CryIfConf_CryIfKey_vHsm_FirmwareUpdate_Decrypt, CRYPTO_PROCESSING_SYNC, FALSE}                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Decrypt] */
  /*     3 */ {0u, &Csm_PrimitiveInfo[6], 0x000000FFu, CryIfConf_CryIfKey_vHsm_FirmwareUpdate_Encrypt, CRYPTO_PROCESSING_SYNC, FALSE}                         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Encrypt] */
  /*     4 */ {0u, &Csm_PrimitiveInfo[8], 0x000000FFu, CryIfConf_CryIfKey_vHsm_FirmwareUpdate_Mac, CRYPTO_PROCESSING_SYNC, FALSE}                             ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_MacGenerate] */
  /*     5 */ {0u, &Csm_PrimitiveInfo[7], 0x000000FFu, CryIfConf_CryIfKey_vHsm_FirmwareUpdate_Signature, CRYPTO_PROCESSING_SYNC, FALSE}                       ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_SignatureVerify] */
  /*     6 */ {0u, &Csm_PrimitiveInfo[4], 0x000000FFu, CryIfConf_CryIfKey_KeyM_ECC_Intermediate, CRYPTO_PROCESSING_SYNC, FALSE}                               ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Intermediate] */
  /*     7 */ {0u, &Csm_PrimitiveInfo[4], 0x000000FFu, CryIfConf_CryIfKey_KeyM_ECC_Root, CRYPTO_PROCESSING_SYNC, FALSE}                                       ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Root] */
  /*     8 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_vHsm_RomKey0, CRYPTO_PROCESSING_SYNC, FALSE}                                        ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Decrypt] */
  /*     9 */ {0u, &Csm_PrimitiveInfo[1], 0x000000FFu, CryIfConf_CryIfKey_vHsm_RomKey0, CRYPTO_PROCESSING_SYNC, FALSE}                                        ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Encrypt] */
  /*    10 */ {0u, &Csm_PrimitiveInfo[9], 0x000000FFu, CryIfConf_CryIfKey_vHsm_TRNG, CRYPTO_PROCESSING_SYNC, FALSE}                                           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random] */
  /*    11 */ {0u, &Csm_PrimitiveInfo[12], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_Rng_Fips186, CRYPTO_PROCESSING_SYNC, FALSE}                           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate] */
  /*    12 */ {0u, &Csm_PrimitiveInfo[13], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_SecurityAccess_Ed25519, CRYPTO_PROCESSING_SYNC, FALSE}                ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecurityAccess_Ed25519Sha512] */
  /*    13 */ {0u, &Csm_PrimitiveInfo[14], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_HashDummy, CRYPTO_PROCESSING_SYNC, FALSE}                             ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512] */
  /*    14 */ {0u, &Csm_PrimitiveInfo[13], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Ed25519, CRYPTO_PROCESSING_SYNC, FALSE}                     ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512] */
  /*    15 */ {0u, &Csm_PrimitiveInfo[11], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Ssa_TrustModelPrivateEcuUnique_StagingKey, CRYPTO_PROCESSING_SYNC, FALSE}    /* [/ActiveEcuC/Csm/CsmJobs/SSA_KeyPairGenerationEd25519] */
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
  Element        Description
  CsmKeyIdIdx    the index of the 1:1 relation pointing to one of Csm_Key
  MaskedBits     contains bitcoded the boolean data of Csm_AsynchronousOfJobTable, Csm_PrimitiveCallbackUpdateNotificationOfJobTable
  Priority       Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPriority.
  QueueRefIdx    the index of the 1:1 relation pointing to one of Csm_QueueInfo
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_JobTableType, CSM_CONST) Csm_JobTable[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CsmKeyIdIdx  MaskedBits  Priority  QueueRefIdx        Referable Keys */
  { /*     0 */          0u,      0x00u,       0u,          4u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc, /ActiveEcuC/Csm/CsmJobs] */
  { /*     1 */          0u,      0x00u,       0u,          4u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc, /ActiveEcuC/Csm/CsmJobs] */
  { /*     2 */         55u,      0x00u,       1u,          0u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Decrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmFirmwareUpdate:vHsmFirmwareUpdateCsmJobDecryptRef] */
  { /*     3 */         56u,      0x00u,       1u,          1u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Encrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmFirmwareUpdate:vHsmFirmwareUpdateCsmJobEncryptRef] */
  { /*     4 */         57u,      0x00u,       1u,          2u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_MacGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmFirmwareUpdate:vHsmFirmwareUpdateCsmJobMacGenerateRef] */
  { /*     5 */         58u,      0x00u,       1u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_SignatureVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmFirmwareUpdate:vHsmFirmwareUpdateCsmJobSignatureVerifyRef] */
  { /*     6 */          9u,      0x00u,       1u,          5u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Intermediate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA:KeyMCertCsmSignatureVerifyJobRef] */
  { /*     7 */         10u,      0x00u,       1u,          5u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Root, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA:KeyMCertCsmSignatureVerifyJobRef] */
  { /*     8 */         17u,      0x00u,       0u,          4u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Decrypt, /ActiveEcuC/Csm/CsmJobs] */
  { /*     9 */         17u,      0x00u,       0u,          4u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Encrypt, /ActiveEcuC/Csm/CsmJobs] */
  { /*    10 */         62u,      0x00u,       1u,          4u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmGeneral:vHsmRandomCsmJobRef] */
  { /*    11 */          2u,      0x00u,       0u,          4u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate, /ActiveEcuC/Csm/CsmJobs] */
  { /*    12 */          3u,      0x00u,       0u,          4u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecurityAccess_Ed25519Sha512, /ActiveEcuC/Csm/CsmJobs] */
  { /*    13 */          1u,      0x00u,       0u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512, /ActiveEcuC/Csm/CsmJobs] */
  { /*    14 */          4u,      0x00u,       0u,          4u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512, /ActiveEcuC/Csm/CsmJobs] */
  { /*    15 */         46u,      0x00u,       1u,          6u }   /* [/ActiveEcuC/Csm/CsmJobs/SSA_KeyPairGenerationEd25519, /ActiveEcuC/Csm/CsmJobs] */
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
CONST(Csm_KeyType, CSM_CONST) Csm_Key[63] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CryIfKeyId                                                                          Referable Keys */
  { /*     0 */ CryIfConf_CryIfKey_CryIfKey_Fbl_Decrypt_Aes128                               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Decrypt_Aes128, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc:CsmJobKeyRef] */
  { /*     1 */ CryIfConf_CryIfKey_CryIfKey_Fbl_HashDummy                                    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_HashDummy, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512:CsmJobKeyRef] */
  { /*     2 */ CryIfConf_CryIfKey_CryIfKey_Fbl_Rng_Fips186                                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Rng_Fips186, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate:CsmJobKeyRef] */
  { /*     3 */ CryIfConf_CryIfKey_CryIfKey_Fbl_SecurityAccess_Ed25519                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_SecurityAccess_Ed25519, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SecurityAccess_Ed25519Sha512:CsmJobKeyRef] */
  { /*     4 */ CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Ed25519                            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Signature_Ed25519, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512:CsmJobKeyRef] */
  { /*     5 */ CryIfConf_CryIfKey_CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA, /ActiveEcuC/Csm/CsmKeys] */
  { /*     6 */ CryIfConf_CryIfKey_CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA, /ActiveEcuC/Csm/CsmKeys] */
  { /*     7 */ CryIfConf_CryIfKey_KeyM_Cert_Root                                            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_Cert_Intermediate, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA:KeyMCertificateCsmKeyTargetRef] */
  { /*     8 */ CryIfConf_CryIfKey_KeyM_Cert_Root                                            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_Cert_Root, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA:KeyMCertificateCsmKeyTargetRef] */
  { /*     9 */ CryIfConf_CryIfKey_KeyM_ECC_Intermediate                                     },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_ECC_Intermediate, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Intermediate:CsmJobKeyRef, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    10 */ CryIfConf_CryIfKey_KeyM_ECC_Root                                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_ECC_Root, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Root:CsmJobKeyRef, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA:KeyMCertCsmSignatureVerifyKeyRef] */
  { /*    11 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelBackend                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelBackend, /ActiveEcuC/Csm/CsmKeys] */
  { /*    12 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelBackendPeer                   },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelBackendPeer, /ActiveEcuC/Csm/CsmKeys] */
  { /*    13 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelEcuPeer                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelEcuPeer, /ActiveEcuC/Csm/CsmKeys] */
  { /*    14 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelIntermediate                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelIntermediate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    15 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer, /ActiveEcuC/Csm/CsmKeys] */
  { /*    16 */ CryIfConf_CryIfKey_KeyM_SigVerifyKey_TrustModelRoot                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelRoot, /ActiveEcuC/Csm/CsmKeys] */
  { /*    17 */ CryIfConf_CryIfKey_vHsm_RomKey0                                              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ROM_KEY_0, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Decrypt:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Encrypt:CsmJobKeyRef] */
  { /*    18 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx, /ActiveEcuC/Csm/CsmKeys] */
  { /*    19 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx, /ActiveEcuC/Csm/CsmKeys] */
  { /*    20 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx, /ActiveEcuC/Csm/CsmKeys] */
  { /*    21 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, /ActiveEcuC/Csm/CsmKeys] */
  { /*    22 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, /ActiveEcuC/Csm/CsmKeys] */
  { /*    23 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer, /ActiveEcuC/Csm/CsmKeys] */
  { /*    24 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_Ign_Stat                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_Ign_Stat, /ActiveEcuC/Csm/CsmKeys] */
  { /*    25 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1, /ActiveEcuC/Csm/CsmKeys] */
  { /*    26 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4, /ActiveEcuC/Csm/CsmKeys] */
  { /*    27 */ CryIfConf_CryIfKey_SSA_SecOC_Int_MacVerify_VehSpd_8                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_VehSpd_8, /ActiveEcuC/Csm/CsmKeys] */
  { /*    28 */ CryIfConf_CryIfKey_Ssa_AesRamKey                                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_AesRamKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    29 */ CryIfConf_CryIfKey_Ssa_Authentication                                        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_Authentication, /ActiveEcuC/Csm/CsmKeys] */
  { /*    30 */ CryIfConf_CryIfKey_Ssa_BackendCert                                           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_BackendCert, /ActiveEcuC/Csm/CsmKeys] */
  { /*    31 */ CryIfConf_CryIfKey_Ssa_PduKeysMac                                            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_PduKeysMac, /ActiveEcuC/Csm/CsmKeys] */
  { /*    32 */ CryIfConf_CryIfKey_Ssa_RandomSeed                                            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_RandomSeed, /ActiveEcuC/Csm/CsmKeys] */
  { /*    33 */ CryIfConf_CryIfKey_Ssa_RealTime                                              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_RealTime, /ActiveEcuC/Csm/CsmKeys] */
  { /*    34 */ CryIfConf_CryIfKey_Ssa_RootCert                                              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_RootCert, /ActiveEcuC/Csm/CsmKeys] */
  { /*    35 */ CryIfConf_CryIfKey_Ssa_SecurityAccessPublicKey                               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SecurityAccessPublicKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    36 */ CryIfConf_CryIfKey_Ssa_SharedSecretExchangeKey                               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SharedSecretExchangeKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    37 */ CryIfConf_CryIfKey_Ssa_SharedSecretHash                                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SharedSecretHash, /ActiveEcuC/Csm/CsmKeys] */
  { /*    38 */ CryIfConf_CryIfKey_Ssa_SignatureRamKey                                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SignatureRamKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    39 */ CryIfConf_CryIfKey_CryIfKey_Ssa_SignatureRamKey_replacementAuthority         },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SignatureRamKey_replacementAuthority, /ActiveEcuC/Csm/CsmKeys] */
  { /*    40 */ CryIfConf_CryIfKey_Ssa_TickCount                                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TickCount, /ActiveEcuC/Csm/CsmKeys] */
  { /*    41 */ CryIfConf_CryIfKey_CryIfKey_Ssa_TrustModelBackendCert_inHSM                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelBackendCert_inHSM, /ActiveEcuC/Csm/CsmKeys] */
  { /*    42 */ CryIfConf_CryIfKey_CryIfKey_Ssa_TrustModelEcuCert_inHSM                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuCert_inHSM, /ActiveEcuC/Csm/CsmKeys] */
  { /*    43 */ CryIfConf_CryIfKey_Ssa_TrustModelEcuPublicCsr_StagingKey                     },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    44 */ CryIfConf_CryIfKey_Ssa_TrustModelEcuPublic_LiveKey                           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuPublic_LiveKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    45 */ CryIfConf_CryIfKey_CryIfKey_Ssa_TrustModelIntermediateCert_inHSM             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelIntermediateCert_inHSM, /ActiveEcuC/Csm/CsmKeys] */
  { /*    46 */ CryIfConf_CryIfKey_CryIfKey_Ssa_TrustModelPrivateEcuUnique_StagingKey        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/SSA_KeyPairGenerationEd25519:CsmJobKeyRef] */
  { /*    47 */ CryIfConf_CryIfKey_Ssa_TrustModelPrivateEcu_LiveKey                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcu_LiveKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    48 */ CryIfConf_CryIfKey_CryIfKey_Ssa_TrustModelRootCert_inHSM                     },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelRootCert_inHSM, /ActiveEcuC/Csm/CsmKeys] */
  { /*    49 */ CryIfConf_CryIfKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPrivateKey                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModel_Ecu_CsrPrivateKey, /ActiveEcuC/Csm/CsmKeys] */
    /* Index    CryIfKeyId                                                                          Referable Keys */
  { /*    50 */ CryIfConf_CryIfKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPublicKey                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModel_Ecu_CsrPublicKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    51 */ CryIfConf_CryIfKey_Ssa_VIN                                                   },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_VIN, /ActiveEcuC/Csm/CsmKeys] */
  { /*    52 */ CryIfConf_CryIfKey_vHsm_Info                                                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsmInfo, /ActiveEcuC/Csm/CsmKeys] */
  { /*    53 */ CryIfConf_CryIfKey_vHsm_Log                                                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsmLog, /ActiveEcuC/Csm/CsmKeys] */
  { /*    54 */ CryIfConf_CryIfKey_vHsm_Custom                                               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Custom, /ActiveEcuC/Csm/CsmKeys] */
  { /*    55 */ CryIfConf_CryIfKey_vHsm_FirmwareUpdate_Decrypt                               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_FirmwareUpdate_Decrypt, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Decrypt:CsmJobKeyRef] */
  { /*    56 */ CryIfConf_CryIfKey_vHsm_FirmwareUpdate_Encrypt                               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_FirmwareUpdate_Encrypt, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Encrypt:CsmJobKeyRef] */
  { /*    57 */ CryIfConf_CryIfKey_vHsm_FirmwareUpdate_Mac                                   },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_FirmwareUpdate_Mac, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_MacGenerate:CsmJobKeyRef] */
  { /*    58 */ CryIfConf_CryIfKey_vHsm_FirmwareUpdate_Signature                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_FirmwareUpdate_Signature, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_SignatureVerify:CsmJobKeyRef] */
  { /*    59 */ CryIfConf_CryIfKey_vHsm_Hardware                                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Hardware, /ActiveEcuC/Csm/CsmKeys] */
  { /*    60 */ CryIfConf_CryIfKey_vHsm_Info                                                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Info, /ActiveEcuC/Csm/CsmKeys] */
  { /*    61 */ CryIfConf_CryIfKey_CryIfKey_vHsm_Info                                        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Info_01, /ActiveEcuC/Csm/CsmKeys] */
  { /*    62 */ CryIfConf_CryIfKey_vHsm_TRNG                                                 }   /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_TRNG, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Random:CsmJobKeyRef] */
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
CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo[15] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PrimitiveInfo                                                                                                                           Referable Keys */
  /*     0 */ {64u, CRYPTO_SIGNATUREGENERATE, {CRYPTO_ALGOFAM_ED25519, 32u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_SHA2_512}}                   ,  /* [/ActiveEcuC/Csm/SigGenEd25519/CsmSignatureGenerate/SigGenEd25519] */
  /*     1 */ {0u, CRYPTO_ENCRYPT, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CBC, 133u} /*  SecondaryFamily = Crypto_30_Hwa_PaddingPKCS7  */ }   ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Encrypt/CsmEncrypt/CsmPrimitives_Encrypt] */
  /*     2 */ {0u, CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CBC, 133u} /*  SecondaryFamily = Crypto_30_Hwa_PaddingPKCS7  */ }   ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Decrypt/CsmDecrypt/CsmPrimitives_Decrypt, /ActiveEcuC/Csm/CsmPrimitives_Dec_Aes128PkcsCbc/CsmDecrypt/CsmPrimitives_Dec_Aes128PkcsCbc] */
  /*     3 */ {32u, CRYPTO_HASH, {CRYPTO_ALGOFAM_SHA2_256, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}                                 ,  /* [/ActiveEcuC/Csm/CsmPrimitives_CsmHash/CsmHash/CsmPrimitives_CsmHash] */
  /*     4 */ {0u, CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_ECCNIST, 32u, CRYPTO_ALGOMODE_CUSTOM_P256R1, CRYPTO_ALGOFAM_SHA2_256}}                ,  /* [/ActiveEcuC/Csm/CsmPrimitives_ECC_P256R1/CsmSignatureVerify/CsmPrimitives_ECC_P256R1] */
  /*     5 */ {0u, CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CBC, CRYPTO_ALGOFAM_NOT_SET}}                                       ,  /* [/ActiveEcuC/Csm/CsmPrimitives_FirmwareUpdate_Decrypt/CsmDecrypt/CsmPrimitives_FirmwareUpdate_Decrypt, /ActiveEcuC/Csm/CsmPrimitives_Dec_Aes128NoneCbc/CsmDecrypt/CsmPrimitives_Dec_Aes128NoneCbc] */
  /*     6 */ {0u, CRYPTO_ENCRYPT, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CBC, CRYPTO_ALGOFAM_NOT_SET}}                                       ,  /* [/ActiveEcuC/Csm/CsmPrimitives_FirmwareUpdate_Encrypt/CsmEncrypt/CsmPrimitives_FirmwareUpdate_Encrypt] */
  /*     7 */ {0u, CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_ED25519, 32u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_SHA2_512}}                      ,  /* [/ActiveEcuC/Csm/CsmPrimitives_FirmwareUpdate_SignatureVerify/CsmSignatureVerify/CsmPrimitives_FirmwareUpdate_SignatureVerify] */
  /*     8 */ {16u, CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CMAC, CRYPTO_ALGOFAM_NOT_SET}}                                 ,  /* [/ActiveEcuC/Csm/CsmPrimitives_FirmwareUpdate_MacGenerate/CsmMacGenerate/CsmPrimitives_FirmwareUpdate_MacGenerate] */
  /*     9 */ {16u, CRYPTO_RANDOMGENERATE, {CRYPTO_ALGOFAM_RNG, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}                            ,  /* [/ActiveEcuC/Csm/CsmPrimitives_RandomTrng/CsmRandomGenerate/CsmPrimitives_RandomTrng] */
  /*    10 */ {16u, CRYPTO_RANDOMGENERATE, {CRYPTO_ALGOFAM_CUSTOM_DRBG, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_AES}}                        ,  /* [/ActiveEcuC/Csm/CsmPrimitives_RandomDrbg/CsmRandomGenerate/CsmPrimitives_RandomDrbg] */
  /*    11 */ {0u, CRYPTO_KEYGENERATE, {CRYPTO_ALGOFAM_ED25519, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}                            ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Ed25519KeyGen/CsmJobKeyGenerate/CsmPrimitives_Ed25519KeyGen] */
  /*    12 */ {4u, CRYPTO_RANDOMGENERATE, {CRYPTO_ALGOFAM_RNG, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}                             ,  /* [/ActiveEcuC/Csm/CsmPrimitives_RandomGenerate/CsmRandomGenerate/CsmPrimitives_RandomGenerate] */
  /*    13 */ {0u, CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_ED25519, 32u, 176u, CRYPTO_ALGOFAM_SHA2_512} /*  Mode = Crypto_30_Hwa_Ed25519Ph  */ } ,  /* [/ActiveEcuC/Csm/CsmPrimitives_SigAsymVer_EdDsa25519Sha512/CsmSignatureVerify/CsmPrimitives_SigAsymVer_EdDsa25519Sha512] */
  /*    14 */ {64u, CRYPTO_HASH, {CRYPTO_ALGOFAM_SHA2_512, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}                                    /* [/ActiveEcuC/Csm/CsmPrimitives_Sha512/CsmHash/CsmPrimitives_Sha512] */
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
  Element            Description
  ChannelId          Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmChannelRef.
  JobPoolStartIdx    the start index of the 0:n relation pointing to Csm_Job
  MaskedBits         contains bitcoded the boolean data of Csm_JobObjSynchronousUsedOfQueueInfo, Csm_JobPoolUsedOfQueueInfo, Csm_JobSharingOfQueueInfo
  QueueEndIdx        the end index of the 1:n relation pointing to Csm_Queue
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_QueueInfoType, CSM_CONST) Csm_QueueInfo[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ChannelId                                                JobPoolStartIdx  MaskedBits  QueueEndIdx        Referable Keys */
  { /*     0 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_LibCv_vHsmUpd_Dec,              3u,      0x07u,          4u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_Decrypt, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Decrypt:CsmJobQueueRef] */
  { /*     1 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_LibCv_vHsmUpd_Enc,              4u,      0x07u,          5u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_Encrypt, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Encrypt:CsmJobQueueRef] */
  { /*     2 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_LibCv_vHsmUpd_Mac,              6u,      0x07u,          7u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_MacGenerate, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_MacGenerate:CsmJobQueueRef] */
  { /*     3 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_LibCv_vHsmUpd_Sig,              5u,      0x07u,          6u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_SignatureVerify, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_SignatureVerify:CsmJobQueueRef] */
  { /*     4 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_Hwa              ,              2u,      0x07u,          3u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hwa, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Decrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Encrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Random:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SecurityAccess_Ed25519Sha512:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512:CsmJobQueueRef] */
  { /*     5 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_KeyM_LibCv       ,              0u,      0x07u,          1u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_KeyM, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Intermediate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Root:CsmJobQueueRef] */
  { /*     6 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_LibCv            ,              1u,      0x07u,          2u }   /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_LibCv, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_KeyPairGenerationEd25519:CsmJobQueueRef] */
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
VAR(Crypto_JobType, CSM_VAR_NOINIT) Csm_Job[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [CsmQueue_KeyM_AsyncPool, CsmQueue_KeyM_SyncObj] */
  /*     1 */  /* [CsmQueue_LibCv_AsyncPool, CsmQueue_LibCv_SyncObj] */
  /*     2 */  /* [CsmQueue_Hwa_AsyncPool, CsmQueue_Hwa_SyncObj] */
  /*     3 */  /* [CsmQueue_FirmwareUpdate_Decrypt_AsyncPool, CsmQueue_FirmwareUpdate_Decrypt_SyncObj] */
  /*     4 */  /* [CsmQueue_FirmwareUpdate_Encrypt_AsyncPool, CsmQueue_FirmwareUpdate_Encrypt_SyncObj] */
  /*     5 */  /* [CsmQueue_FirmwareUpdate_SignatureVerify_AsyncPool, CsmQueue_FirmwareUpdate_SignatureVerify_SyncObj] */
  /*     6 */  /* [CsmQueue_FirmwareUpdate_MacGenerate_AsyncPool, CsmQueue_FirmwareUpdate_MacGenerate_SyncObj] */

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
VAR(Csm_JobStateType, CSM_VAR_NOINIT) Csm_JobState[16];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc, /ActiveEcuC/Csm/CsmJobs] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc, /ActiveEcuC/Csm/CsmJobs] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Decrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmFirmwareUpdate:vHsmFirmwareUpdateCsmJobDecryptRef] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Encrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmFirmwareUpdate:vHsmFirmwareUpdateCsmJobEncryptRef] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_MacGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmFirmwareUpdate:vHsmFirmwareUpdateCsmJobMacGenerateRef] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_SignatureVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmFirmwareUpdate:vHsmFirmwareUpdateCsmJobSignatureVerifyRef] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Intermediate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA:KeyMCertCsmSignatureVerifyJobRef] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Root, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA:KeyMCertCsmSignatureVerifyJobRef] */
  /*     8 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Decrypt, /ActiveEcuC/Csm/CsmJobs] */
  /*     9 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Encrypt, /ActiveEcuC/Csm/CsmJobs] */
  /*    10 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmGeneral:vHsmRandomCsmJobRef] */
  /*    11 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate, /ActiveEcuC/Csm/CsmJobs] */
  /*    12 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecurityAccess_Ed25519Sha512, /ActiveEcuC/Csm/CsmJobs] */
  /*    13 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512, /ActiveEcuC/Csm/CsmJobs] */
  /*    14 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512, /ActiveEcuC/Csm/CsmJobs] */
  /*    15 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_KeyPairGenerationEd25519, /ActiveEcuC/Csm/CsmJobs] */

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
VAR(Csm_SizeOfJobType, CSM_VAR_NOINIT) Csm_JobToObjMap[16];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc, /ActiveEcuC/Csm/CsmJobs] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc, /ActiveEcuC/Csm/CsmJobs] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Decrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmFirmwareUpdate:vHsmFirmwareUpdateCsmJobDecryptRef] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Encrypt, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmFirmwareUpdate:vHsmFirmwareUpdateCsmJobEncryptRef] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_MacGenerate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmFirmwareUpdate:vHsmFirmwareUpdateCsmJobMacGenerateRef] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_SignatureVerify, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmFirmwareUpdate:vHsmFirmwareUpdateCsmJobSignatureVerifyRef] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Intermediate, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA:KeyMCertCsmSignatureVerifyJobRef] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Root, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA:KeyMCertCsmSignatureVerifyJobRef] */
  /*     8 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Decrypt, /ActiveEcuC/Csm/CsmJobs] */
  /*     9 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Encrypt, /ActiveEcuC/Csm/CsmJobs] */
  /*    10 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/vHsm/vHsmGeneral:vHsmRandomCsmJobRef] */
  /*    11 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate, /ActiveEcuC/Csm/CsmJobs] */
  /*    12 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecurityAccess_Ed25519Sha512, /ActiveEcuC/Csm/CsmJobs] */
  /*    13 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512, /ActiveEcuC/Csm/CsmJobs] */
  /*    14 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512, /ActiveEcuC/Csm/CsmJobs] */
  /*    15 */  /* [/ActiveEcuC/Csm/CsmJobs/SSA_KeyPairGenerationEd25519, /ActiveEcuC/Csm/CsmJobs] */

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
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_LibCv] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hwa] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_Decrypt] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_Encrypt] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_SignatureVerify] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_MacGenerate] */

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
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_Decrypt, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Decrypt:CsmJobQueueRef] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_Encrypt, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_Encrypt:CsmJobQueueRef] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_MacGenerate, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_MacGenerate:CsmJobQueueRef] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_FirmwareUpdate_SignatureVerify, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_FirmwareUpdate_SignatureVerify:CsmJobQueueRef] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hwa, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Decrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeyStorage_Encrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Random:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SecurityAccess_Ed25519Sha512:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512:CsmJobQueueRef] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_KeyM, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Intermediate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeyM_ECC_Root:CsmJobQueueRef] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_LibCv, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/SSA_KeyPairGenerationEd25519:CsmJobQueueRef] */

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





