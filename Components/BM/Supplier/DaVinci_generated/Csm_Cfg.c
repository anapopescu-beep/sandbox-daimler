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
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Csm_Cfg.c
 *   Generation Time: 2023-08-16 14:35:31
 *           Project: CBD2000614_Bm - Version 1.0
 *          Delivery: CBD2200332_D02
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
  Csm_JobInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     JobInfo       Referable Keys */
  /*     0 */ {0u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc] */
  /*     1 */ {1u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc] */
  /*     2 */ {2u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate] */
  /*     3 */ {3u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512] */
  /*     4 */ {4u, 0u}    /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512] */
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
CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     JobPrimitiveInfo                                                                                                                Referable Keys */
  /*     0 */ {0u, &Csm_PrimitiveInfo[1], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_Decrypt_Aes128, CRYPTO_PROCESSING_SYNC, FALSE}    ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc] */
  /*     1 */ {0u, &Csm_PrimitiveInfo[4], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_Decrypt_Aes128, CRYPTO_PROCESSING_SYNC, FALSE}    ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc] */
  /*     2 */ {0u, &Csm_PrimitiveInfo[0], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_Rng_Fips186, CRYPTO_PROCESSING_SYNC, FALSE}       ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate] */
  /*     3 */ {0u, &Csm_PrimitiveInfo[2], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_HashDummy, CRYPTO_PROCESSING_SYNC, FALSE}         ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512] */
  /*     4 */ {0u, &Csm_PrimitiveInfo[3], 0x000000FFu, CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Ed25519, CRYPTO_PROCESSING_SYNC, FALSE}    /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512] */
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
  Priority       Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPriority.
  QueueRefIdx    the index of the 1:1 relation pointing to one of Csm_QueueInfo
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_JobTableType, CSM_CONST) Csm_JobTable[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CsmKeyIdIdx  Priority  QueueRefIdx        Referable Keys */
  { /*     0 */          0u,       0u,          0u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc, /ActiveEcuC/Csm/CsmJobs] */
  { /*     1 */          0u,       0u,          0u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc, /ActiveEcuC/Csm/CsmJobs] */
  { /*     2 */          4u,       0u,          1u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate, /ActiveEcuC/Csm/CsmJobs] */
  { /*     3 */          2u,       0u,          2u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512, /ActiveEcuC/Csm/CsmJobs] */
  { /*     4 */          7u,       0u,          2u }   /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512, /ActiveEcuC/Csm/CsmJobs] */
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
CONST(Csm_KeyType, CSM_CONST) Csm_Key[64] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CryIfKeyId                                                                                   Referable Keys */
  { /*     0 */ CryIfConf_CryIfKey_CryIfKey_Fbl_Decrypt_Aes128                                        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Decrypt_Aes128, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc:CsmJobKeyRef] */
  { /*     1 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Fbl_Decrypt_Aes128                               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Decrypt_Aes128_01, /ActiveEcuC/Csm/CsmKeys] */
  { /*     2 */ CryIfConf_CryIfKey_CryIfKey_Fbl_HashDummy                                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_HashDummy, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512:CsmJobKeyRef, /MICROSAR/Csm_Rec/CsmJobs/CsmJob_Sha512:CsmJobKeyRef] */
  { /*     3 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Fbl_HashDummy                                    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_HashDummy_01, /ActiveEcuC/Csm/CsmKeys] */
  { /*     4 */ CryIfConf_CryIfKey_CryIfKey_Fbl_Rng_Fips186                                           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Rng_Fips186, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate:CsmJobKeyRef] */
  { /*     5 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Fbl_Rng_Fips186                                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Rng_Fips186_01, /ActiveEcuC/Csm/CsmKeys] */
  { /*     6 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Fbl_SecurityAccess_Ed25519                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_SecurityAccess_Ed25519, /ActiveEcuC/Csm/CsmKeys] */
  { /*     7 */ CryIfConf_CryIfKey_CryIfKey_Fbl_Signature_Ed25519                                     },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Signature_Ed25519, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512:CsmJobKeyRef] */
  { /*     8 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Fbl_Signature_Ed25519                            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Fbl_Signature_Ed25519_01, /ActiveEcuC/Csm/CsmKeys] */
  { /*     9 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA_01, /ActiveEcuC/Csm/CsmKeys] */
  { /*    10 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA_01, /ActiveEcuC/Csm/CsmKeys] */
  { /*    11 */ CryIfConf_CryIfKey_CryIfKey_KeyM_Cert_Root                                            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_Cert_Intermediate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    12 */ CryIfConf_CryIfKey_CryIfKey_KeyM_Cert_Root                                            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_Cert_Root, /ActiveEcuC/Csm/CsmKeys] */
  { /*    13 */ CryIfConf_CryIfKey_CryIfKey_KeyM_ECC_Intermediate                                     },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_ECC_Intermediate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    14 */ CryIfConf_CryIfKey_CryIfKey_KeyM_ECC_Root                                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_ECC_Root, /ActiveEcuC/Csm/CsmKeys] */
  { /*    15 */ CryIfConf_CryIfKey_CryIfKey_KeyM_SigVerifyKey_TrustModelBackend                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelBackend, /ActiveEcuC/Csm/CsmKeys] */
  { /*    16 */ CryIfConf_CryIfKey_CryIfKey_KeyM_SigVerifyKey_TrustModelBackendPeer                   },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelBackendPeer, /ActiveEcuC/Csm/CsmKeys] */
  { /*    17 */ CryIfConf_CryIfKey_CryIfKey_KeyM_SigVerifyKey_TrustModelEcuPeer                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelEcuPeer, /ActiveEcuC/Csm/CsmKeys] */
  { /*    18 */ CryIfConf_CryIfKey_CryIfKey_KeyM_SigVerifyKey_TrustModelIntermediate                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelIntermediate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    19 */ CryIfConf_CryIfKey_CryIfKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer, /ActiveEcuC/Csm/CsmKeys] */
  { /*    20 */ CryIfConf_CryIfKey_CryIfKey_KeyM_SigVerifyKey_TrustModelRoot                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_KeyM_SigVerifyKey_TrustModelRoot, /ActiveEcuC/Csm/CsmKeys] */
  { /*    21 */ CryIfConf_CryIfKey_CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx, /ActiveEcuC/Csm/CsmKeys] */
  { /*    22 */ CryIfConf_CryIfKey_CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx, /ActiveEcuC/Csm/CsmKeys] */
  { /*    23 */ CryIfConf_CryIfKey_CryIfKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx, /ActiveEcuC/Csm/CsmKeys] */
  { /*    24 */ CryIfConf_CryIfKey_CryIfKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, /ActiveEcuC/Csm/CsmKeys] */
  { /*    25 */ CryIfConf_CryIfKey_CryIfKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, /ActiveEcuC/Csm/CsmKeys] */
  { /*    26 */ CryIfConf_CryIfKey_CryIfKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer, /ActiveEcuC/Csm/CsmKeys] */
  { /*    27 */ CryIfConf_CryIfKey_CryIfKey_SSA_SecOC_Int_MacVerify_Ign_Stat                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_Ign_Stat, /ActiveEcuC/Csm/CsmKeys] */
  { /*    28 */ CryIfConf_CryIfKey_CryIfKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1, /ActiveEcuC/Csm/CsmKeys] */
  { /*    29 */ CryIfConf_CryIfKey_CryIfKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4, /ActiveEcuC/Csm/CsmKeys] */
  { /*    30 */ CryIfConf_CryIfKey_CryIfKey_SSA_SecOC_Int_MacVerify_VehSpd_8                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SSA_SecOC_Int_MacVerify_VehSpd_8, /ActiveEcuC/Csm/CsmKeys] */
  { /*    31 */ CryIfConf_CryIfKey_CryIfKey_Ssa_AesRamKey                                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_AesRamKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    32 */ CryIfConf_CryIfKey_CryIfKey_Ssa_Authentication                                        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_Authentication, /ActiveEcuC/Csm/CsmKeys] */
  { /*    33 */ CryIfConf_CryIfKey_CryIfKey_Ssa_BackendCert                                           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_BackendCert, /ActiveEcuC/Csm/CsmKeys] */
  { /*    34 */ CryIfConf_CryIfKey_CryIfKey_Ssa_PduKeysMac                                            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_PduKeysMac, /ActiveEcuC/Csm/CsmKeys] */
  { /*    35 */ CryIfConf_CryIfKey_CryIfKey_Ssa_RandomSeed                                            },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_RandomSeed, /ActiveEcuC/Csm/CsmKeys] */
  { /*    36 */ CryIfConf_CryIfKey_CryIfKey_Ssa_RealTime                                              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_RealTime, /ActiveEcuC/Csm/CsmKeys] */
  { /*    37 */ CryIfConf_CryIfKey_CryIfKey_Ssa_RootCert                                              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_RootCert, /ActiveEcuC/Csm/CsmKeys] */
  { /*    38 */ CryIfConf_CryIfKey_CryIfKey_Ssa_SecurityAccessPublicKey                               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SecurityAccessPublicKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    39 */ CryIfConf_CryIfKey_CryIfKey_Ssa_SharedSecretExchangeKey                               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SharedSecretExchangeKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    40 */ CryIfConf_CryIfKey_CryIfKey_Ssa_SharedSecretHash                                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SharedSecretHash, /ActiveEcuC/Csm/CsmKeys] */
  { /*    41 */ CryIfConf_CryIfKey_CryIfKey_Ssa_SignatureRamKey                                       },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SignatureRamKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    42 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_SignatureRamKey_replacementAuthority         },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_SignatureRamKey_replacementAuthority, /ActiveEcuC/Csm/CsmKeys] */
  { /*    43 */ CryIfConf_CryIfKey_CryIfKey_Ssa_TickCount                                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TickCount, /ActiveEcuC/Csm/CsmKeys] */
  { /*    44 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModelBackendCert_inHSM                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelBackendCert_inHSM, /ActiveEcuC/Csm/CsmKeys] */
  { /*    45 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModelEcuCert_inHSM                      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuCert_inHSM, /ActiveEcuC/Csm/CsmKeys] */
  { /*    46 */ CryIfConf_CryIfKey_CryIfKey_Ssa_TrustModelEcuPublicCsr_StagingKey                     },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    47 */ CryIfConf_CryIfKey_CryIfKey_Ssa_TrustModelEcuPublic_LiveKey                           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelEcuPublic_LiveKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    48 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModelIntermediateCert_inHSM             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelIntermediateCert_inHSM, /ActiveEcuC/Csm/CsmKeys] */
  { /*    49 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModelPrivateEcuUnique_StagingKey        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey, /ActiveEcuC/Csm/CsmKeys] */
    /* Index    CryIfKeyId                                                                                   Referable Keys */
  { /*    50 */ CryIfConf_CryIfKey_CryIfKey_Ssa_TrustModelPrivateEcu_LiveKey                          },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelPrivateEcu_LiveKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    51 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModelRootCert_inHSM                     },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModelRootCert_inHSM, /ActiveEcuC/Csm/CsmKeys] */
  { /*    52 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPrivateKey                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModel_Ecu_CsrPrivateKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    53 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPublicKey                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_TrustModel_Ecu_CsrPublicKey, /ActiveEcuC/Csm/CsmKeys] */
  { /*    54 */ CryIfConf_CryIfKey_CryIfKey_Ssa_VIN                                                   },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Ssa_VIN, /ActiveEcuC/Csm/CsmKeys] */
  { /*    55 */ CryIfConf_CryIfKey_CryIfKey_vHSM_Custom_HSM_Version                                   },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHSM_Custom_HSM_Version, /ActiveEcuC/Csm/CsmKeys] */
  { /*    56 */ CryIfConf_CryIfKey_CryIfKey_vHsm_Custom                                               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Custom, /ActiveEcuC/Csm/CsmKeys] */
  { /*    57 */ CryIfConf_CryIfKey_CryIfKey_vHsm_FirmwareUpdate_Signature                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_FirmwareUpdate_Signature, /ActiveEcuC/Csm/CsmKeys] */
  { /*    58 */ CryIfConf_CryIfKey_CryIfKey_vHsm_Hardware                                             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Hardware, /ActiveEcuC/Csm/CsmKeys] */
  { /*    59 */ CryIfConf_CryIfKey_CryIfKey_vHsm_Info                                                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Info, /ActiveEcuC/Csm/CsmKeys] */
  { /*    60 */ CryIfConf_CryIfKey_CryIfKey_CryIfKey_vHsm_Info                                        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Info_01, /ActiveEcuC/Csm/CsmKeys] */
  { /*    61 */ CryIfConf_CryIfKey_CryIfKey_vHsm_Log                                                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_Log, /ActiveEcuC/Csm/CsmKeys] */
  { /*    62 */ CryIfConf_CryIfKey_CryIfKey_vHsm_RomKey0                                              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_RomKey0, /ActiveEcuC/Csm/CsmKeys] */
  { /*    63 */ CryIfConf_CryIfKey_CryIfKey_vHsm_TRNG                                                 }   /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_vHsm_TRNG, /ActiveEcuC/Csm/CsmKeys] */
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
CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PrimitiveInfo                                                                                                      Referable Keys */
  /*     0 */ {4u, CRYPTO_RANDOMGENERATE, {CRYPTO_ALGOFAM_RNG, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}        ,  /* [/ActiveEcuC/Csm/CsmPrimitives_RandomGenerate/CsmRandomGenerate/CsmPrimitives_RandomGenerate] */
  /*     1 */ {0u, CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CBC, CRYPTO_ALGOFAM_NOT_SET}}                  ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Dec_Aes128NoneCbc/CsmDecrypt/CsmPrimitives_Dec_Aes128NoneCbc] */
  /*     2 */ {64u, CRYPTO_HASH, {CRYPTO_ALGOFAM_SHA2_512, 0u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}}            ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Sha512/CsmHash/CsmPrimitives_Sha512] */
  /*     3 */ {0u, CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_ED25519, 32u, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_SHA2_512}} ,  /* [/ActiveEcuC/Csm/CsmPrimitives_SigAsymVer_EdDsa25519Sha512/CsmSignatureVerify/CsmPrimitives_SigAsymVer_EdDsa25519Sha512] */
  /*     4 */ {0u, CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, 16u, CRYPTO_ALGOMODE_CBC, CRYPTO_ALGOFAM_CUSTOM_PADDING_PKCS7}}        /* [/ActiveEcuC/Csm/CsmPrimitives_Dec_Aes128PkcsCbc/CsmDecrypt/CsmPrimitives_Dec_Aes128PkcsCbc] */
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
CONST(Csm_QueueInfoType, CSM_CONST) Csm_QueueInfo[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ChannelId                                                   JobPoolStartIdx  MaskedBits  QueueEndIdx        Referable Keys */
  { /*     0 */ CryIfConf_CryIfChannel_CryIfChannel_CryptoCv_Fbl_Aes      ,              1u,      0x07u,          2u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Aes, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc:CsmJobQueueRef, /MICROSAR/Csm_Rec/CsmJobs/CsmJob_DecryptionAes128NoneCbc:CsmJobQueueRef, /MICROSAR/Csm_Rec/CsmJobs/CsmJob_DecryptionAes128NoneGcm:CsmJobQueueRef, /MICROSAR/Csm_Rec/CsmJobs/CsmJob_DecryptionAes128PkcsCbc:CsmJobQueueRef] */
  { /*     1 */ CryIfConf_CryIfChannel_CryIfChannel_CryptoCv_Fbl_Rng      ,              2u,      0x07u,          3u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Rng, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate:CsmJobQueueRef] */
  { /*     2 */ CryIfConf_CryIfChannel_CryIfChannel_CryptoCv_Fbl_Signature,              0u,      0x07u,          1u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Standard, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512:CsmJobQueueRef, /MICROSAR/Csm_Rec/CsmJobs/CsmJob_RandomGenerate:CsmJobQueueRef, /MICROSAR/Csm_Rec/CsmJobs/CsmJob_Sha512:CsmJobQueueRef, /MICROSAR/Csm_Rec/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512:CsmJobQueueRef] */
  { /*     3 */ CryIfConf_CryIfChannel_CryIfChannel_vHsm_Core             ,              3u,      0x07u,          4u }   /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Core, /ActiveEcuC/Csm/CsmQueues] */
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
VAR(Crypto_JobType, CSM_VAR_NOINIT) Csm_Job[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [CsmQueue_Standard_AsyncPool, CsmQueue_Standard_SyncObj] */
  /*     1 */  /* [CsmQueue_Aes_AsyncPool, CsmQueue_Aes_SyncObj] */
  /*     2 */  /* [CsmQueue_Rng_AsyncPool, CsmQueue_Rng_SyncObj] */
  /*     3 */  /* [CsmQueue_vHsm_Core_AsyncPool, CsmQueue_vHsm_Core_SyncObj] */

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
VAR(Csm_JobStateType, CSM_VAR_NOINIT) Csm_JobState[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc, /ActiveEcuC/Csm/CsmJobs] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc, /ActiveEcuC/Csm/CsmJobs] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate, /ActiveEcuC/Csm/CsmJobs] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512, /ActiveEcuC/Csm/CsmJobs] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512, /ActiveEcuC/Csm/CsmJobs] */

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
VAR(Csm_SizeOfJobType, CSM_VAR_NOINIT) Csm_JobToObjMap[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc, /ActiveEcuC/Csm/CsmJobs] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc, /ActiveEcuC/Csm/CsmJobs] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate, /ActiveEcuC/Csm/CsmJobs] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512, /ActiveEcuC/Csm/CsmJobs] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512, /ActiveEcuC/Csm/CsmJobs] */

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
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Standard] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Aes] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Rng] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Core] */

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
VAR(Csm_QueueStateType, CSM_VAR_NOINIT) Csm_QueueState[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Aes, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128NoneCbc:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_DecryptionAes128PkcsCbc:CsmJobQueueRef, /MICROSAR/Csm_Rec/CsmJobs/CsmJob_DecryptionAes128NoneCbc:CsmJobQueueRef, /MICROSAR/Csm_Rec/CsmJobs/CsmJob_DecryptionAes128NoneGcm:CsmJobQueueRef, /MICROSAR/Csm_Rec/CsmJobs/CsmJob_DecryptionAes128PkcsCbc:CsmJobQueueRef] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Rng, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_RandomGenerate:CsmJobQueueRef] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Standard, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Sha512:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512:CsmJobQueueRef, /MICROSAR/Csm_Rec/CsmJobs/CsmJob_RandomGenerate:CsmJobQueueRef, /MICROSAR/Csm_Rec/CsmJobs/CsmJob_Sha512:CsmJobQueueRef, /MICROSAR/Csm_Rec/CsmJobs/CsmJob_SigAsymVer_Ed25519Sha512:CsmJobQueueRef] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_vHsm_Core, /ActiveEcuC/Csm/CsmQueues] */

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





