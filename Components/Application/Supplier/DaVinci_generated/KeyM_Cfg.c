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
 *            Module: KeyM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: KeyM_Cfg.c
 *   Generation Time: 2024-01-17 10:56:23
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define KEYM_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "KeyM_Cfg.h"
#include "KeyM.h"
#include "KeyM_Cert.h"
#include "Csm.h"
#include "Rte_KeyM.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (KEYM_LOCAL)
# define KEYM_LOCAL static
#endif

#if !defined (KEYM_LOCAL_INLINE)
# define KEYM_LOCAL_INLINE LOCAL_INLINE
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
  KeyM_Certificate
**********************************************************************************************************************/
/** 
  \var    KeyM_Certificate
  \brief  Contains parameters of /MICROSAR/KeyM/KeyMCertificate.
  \details
  Element                                              Description
  CertCsmSignatureGenerateJobRef                       Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureGenerateJobRef.
  CertCsmSignatureVerifyJobRef                         Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureVerifyJobRef.
  CertCsmSignatureVerifyKeyRef                         Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureVerifyKeyRef.
  CsmKeyTargetRef                                      Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateCsmKeyTargetRef.
  CertStorageLength                                    the number of relations pointing to KeyM_CertStorage
  CertStorageStartIdx                                  the start index of the 0:n relation pointing to KeyM_CertStorage
  CertAlgorithmFamily                                  Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertAlgorithmFamily.
  CertFormatType                                       Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertFormatType.
  CertStartUpHandling                                  Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertStartUpHandling.
  CertStorageWrittenLengthLength                       the number of relations pointing to KeyM_CertStorage
  CertUpperHierarchicalCertRefIdx                      the index of the 1:1 relation pointing to KeyM_Certificate
  CertUpperHierarchicalType                            Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertUpperHierarchicalType.
  CertificateElementEndIdx                             the end index of the 0:n relation pointing to KeyM_CertificateElement
  CertificateElementStartIdx                           the start index of the 0:n relation pointing to KeyM_CertificateElement
  CertificateGetCurrentTimeCalloutIdx                  the index of the 0:1 relation pointing to KeyM_CertificateGetCurrentTimeCallout
  CertificateInitValueInfoIdx                          the index of the 0:1 relation pointing to KeyM_CertificateInitValueInfo
  CertificateNameEndIdx                                the end index of the 1:n relation pointing to KeyM_CertificateName
  CertificateNameStartIdx                              the start index of the 1:n relation pointing to KeyM_CertificateName
  CertificateVerifyCallbackNotificationWithoutIdIdx    the index of the 0:1 relation pointing to KeyM_CertificateVerifyCallbackNotificationWithoutId
  MaskedBits                                           contains bitcoded the boolean data of KeyM_CertAllowFlexibleElementOrderOfCertificate, KeyM_CertAllowUnconfiguredElementsOfCertificate, KeyM_CertCsmSignatureGenerateJobRefValidOfCertificate, KeyM_CertCsmSignatureVerifyKeyRefValidOfCertificate, KeyM_CsmKeyTargetRefValidOfCertificate, KeyM_KeyMCertCsmHashJobRefAsyncOfCertificate, KeyM_KeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate, KeyM_KeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate
  ServiceCertificateRteCallbackNotification440Idx      the index of the 0:1 relation pointing to KeyM_ServiceCertificateRteCallbackNotification440
  Storage                                              Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateStorage.
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(KeyM_CertificateType, KEYM_CONST) KeyM_Certificate[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CertCsmSignatureGenerateJobRef                                        CertCsmSignatureVerifyJobRef                                        CertCsmSignatureVerifyKeyRef                                 CsmKeyTargetRef                                             CertStorageLength  CertStorageStartIdx  CertAlgorithmFamily  CertFormatType  CertStartUpHandling    CertStorageWrittenLengthLength  CertUpperHierarchicalCertRefIdx  CertUpperHierarchicalType  CertificateElementEndIdx  CertificateElementStartIdx  CertificateGetCurrentTimeCalloutIdx  CertificateInitValueInfoIdx                       CertificateNameEndIdx  CertificateNameStartIdx  CertificateVerifyCallbackNotificationWithoutIdIdx  MaskedBits  ServiceCertificateRteCallbackNotification440Idx  Storage                    Referable Keys */
  { /*     0 */ 4294967295u                                                         , CsmConf_CsmJob_KeyM_SigVerify_TrustModelBackend                   , CsmConf_CsmKey_KeyM_SigVerifyKey_TrustModelBackend         , CsmConf_CsmKey_CsmKey_Ssa_TrustModelBackendCert_inHSM     ,             1000u,                  4u, KEYM_EDDSA         , KEYM_X509     , KEYM_NONE            ,                             2u,                              7u, KEYM_PRESET_ISSUER       ,                      16u,                         0u,                                  0u, KEYM_NO_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE,                   21u,                      0u,                                                0u,      0xD9u,                                              0u, KEYM_STORAGE_IN_CSM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert:KeyMCertUpperHierarchicalCertRef] */
  { /*     1 */ 4294967295u                                                         , CsmConf_CsmJob_KeyM_SigVerify_TrustModelBackendPeer               , CsmConf_CsmKey_KeyM_SigVerifyKey_TrustModelBackendPeer     , 4294967295u                                               ,             1000u,               1008u, KEYM_EDDSA         , KEYM_X509     , KEYM_NONE            ,                             2u,                              7u, KEYM_PRESET_ISSUER       ,                      32u,                        16u,                                  0u, KEYM_NO_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE,                   46u,                     21u,                                                1u,      0xD1u,                                              1u, KEYM_STORAGE_IN_RAM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert:KeyMCertUpperHierarchicalCertRef] */
  { /*     2 */ 4294967295u                                                         , CsmConf_CsmJob_KeyM_SigVerify_TrustModelEcu                       , CsmConf_CsmKey_CsmKey_Ssa_TrustModelEcuPublic_LiveKey      , CsmConf_CsmKey_CsmKey_Ssa_TrustModelEcuCert_inHSM         ,             1000u,               2012u, KEYM_EDDSA         , KEYM_X509     , KEYM_NONE            ,                             2u,                              5u, KEYM_PRESET_ISSUER       ,                      49u,                        32u,                                  0u, KEYM_NO_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE,                   63u,                     46u,                                                2u,      0xD9u,                                              2u, KEYM_STORAGE_IN_CSM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert, /ActiveEcuC/KeyM, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCertRef] */
  { /*     3 */ CsmConf_CsmJob_KeyM_SigGenerate_TrustModelEcuCsr_with_changeableKeys, CsmConf_CsmJob_KeyM_SigVerify_TrustModelEcuCsr_with_changeableKeys, CsmConf_CsmKey_CsmKey_Ssa_TrustModel_Ecu_CsrPublicKey      , 4294967295u                                               ,             1000u,               3016u, KEYM_EDDSA         , KEYM_X509     , KEYM_NONE            ,                             2u,                              3u, KEYM_PRESET_ISSUER       ,                      70u,                        49u,                                  0u, KEYM_NO_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE,                   79u,                     63u,                                                3u,      0xF1u,                                              3u, KEYM_STORAGE_IN_RAM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCsrRef] */
  { /*     4 */ 4294967295u                                                         , CsmConf_CsmJob_KeyM_SigVerify_TrustModelEcuPeer                   , CsmConf_CsmKey_KeyM_SigVerifyKey_TrustModelEcuPeer         , 4294967295u                                               ,             1000u,               4020u, KEYM_EDDSA         , KEYM_X509     , KEYM_NONE            ,                             2u,                              6u, KEYM_PRESET_ISSUER       ,                      86u,                        70u,                                  0u, KEYM_NO_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE,                  100u,                     79u,                                                4u,      0xD1u,                                              4u, KEYM_STORAGE_IN_RAM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuPeerCertRef] */
  { /*     5 */ 4294967295u                                                         , CsmConf_CsmJob_KeyM_SigVerify_TrustModelIntermediate              , CsmConf_CsmKey_KeyM_SigVerifyKey_TrustModelIntermediate    , CsmConf_CsmKey_CsmKey_Ssa_TrustModelIntermediateCert_inHSM,             1000u,               5024u, KEYM_EDDSA         , KEYM_X509     , KEYM_NONE            ,                             2u,                              0u, KEYM_PRESET_ISSUER       ,                     102u,                        86u,                                  0u, KEYM_NO_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE,                  126u,                    100u,                                                5u,      0xD9u,                                              5u, KEYM_STORAGE_IN_CSM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert:KeyMCertUpperHierarchicalCertRef] */
  { /*     6 */ 4294967295u                                                         , CsmConf_CsmJob_KeyM_SigVerify_TrustModelIntermediatePeer          , CsmConf_CsmKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer, 4294967295u                                               ,             1000u,               6028u, KEYM_EDDSA         , KEYM_X509     , KEYM_NONE            ,                             2u,                              1u, KEYM_PRESET_ISSUER       ,                     118u,                       102u,                                  0u, KEYM_NO_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE,                  156u,                    126u,                                                6u,      0xD1u,                                              6u, KEYM_STORAGE_IN_RAM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert:KeyMCertUpperHierarchicalCertRef] */
  { /*     7 */ 4294967295u                                                         , CsmConf_CsmJob_KeyM_SigVerify_TrustModelRoot                      , CsmConf_CsmKey_KeyM_SigVerifyKey_TrustModelRoot            , CsmConf_CsmKey_CsmKey_Ssa_TrustModelRootCert_inHSM        ,             1000u,               7032u, KEYM_EDDSA         , KEYM_X509     , KEYM_PARSE_AND_VERIFY,                             2u,                              7u, KEYM_PRESET_ISSUER       ,                     134u,                       118u,                                  0u,                                               0u,                  174u,                    156u,                                                7u,      0xD9u,                                              7u, KEYM_STORAGE_IN_CSM }   /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert:KeyMCertUpperHierarchicalCertRef] */
};
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateElement
**********************************************************************************************************************/
/** 
  \var    KeyM_CertificateElement
  \brief  Contains parameters of /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement.
  \details
  Element                                     Description
  CertificateElementVerificationCalloutIdx    the index of the 0:1 relation pointing to KeyM_CertificateElementVerificationCallout
  ElementOidEndIdx                            the end index of the 0:n relation pointing to KeyM_ElementOid
  ElementOidStartIdx                          the start index of the 0:n relation pointing to KeyM_ElementOid
  Id                                          Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId.
  MaskedBits                                  contains bitcoded the boolean data of KeyM_HasIterationOfCertificateElement, KeyM_OptionalOfCertificateElement
  MaxLength                                   Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementMaxLength.
  ObjectType                                  Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementObjectType.
  OfStructure                             
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(KeyM_CertificateElementType, KEYM_CONST) KeyM_CertificateElement[134] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CertificateElementVerificationCalloutIdx                              ElementOidEndIdx                              ElementOidStartIdx                              Id   MaskedBits  MaxLength  ObjectType  OfStructure                                                          Referable Keys */
  { /*     0 */                                                                   0u, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  0u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_VERSION_NUMBER                               },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/Version_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*     1 */                                                                   0u, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  1u,      0x00u,       16u,         2u, KEYM_CERTIFICATE_SERIAL_NUMBER                                },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/SerialNo_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*     2 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  2u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID                       },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/SigAlgoId_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*     3 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  3u,      0x00u,       15u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/Issuer_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*     4 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  4u,      0x00u,       13u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE                   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/validityNotBefore_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*     5 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  5u,      0x00u,       15u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/validityNotAfter_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*     6 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  6u,      0x00u,       30u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/subject_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*     7 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  7u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/SubjectPublicKeyInfoAlgo_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*     8 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  8u,      0x00u,       33u,         3u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/SubjectPublicKeyInfoKey_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*     9 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          12u,                                             9u,  9u,      0x00u,       20u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/ext_subKeyId_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*    10 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          15u,                                            12u, 10u,      0x00u,       20u,       128u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/ext_authKeyId_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*    11 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          18u,                                            15u, 11u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/ext_basicConstraints_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*    12 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           9u,                                             6u, 12u,      0x00u,        1u,         3u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/ext_keyUsage_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*    13 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          34u,                                            21u, 13u,      0x01u,        1u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/ext_pkiRole_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*    14 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u, 14u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM                          },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/signatureAlgorithm_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*    15 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT, 15u,      0x00u,       65u,         3u, KEYM_CERTIFICATE_SIGNATURE                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/signatureValue_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  { /*    16 */                                                                   0u, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  0u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_VERSION_NUMBER                               },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/Version_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    17 */                                                                   0u, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  1u,      0x00u,       16u,         2u, KEYM_CERTIFICATE_SERIAL_NUMBER                                },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/SerialNo_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    18 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  2u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID                       },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/SigAlgoId_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    19 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  3u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/Issuer_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    20 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  4u,      0x00u,       13u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE                   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/validityNotBefore_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    21 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  5u,      0x00u,       15u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/validityNotAfter_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    22 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  6u,      0x00u,       15u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/subject_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    23 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  7u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/SubjectPublicKeyInfoAlgo_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    24 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  8u,      0x00u,       33u,         3u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/SubjectPublicKeyInfoKey_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    25 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          12u,                                             9u,  9u,      0x00u,       20u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/ext_subKeyId_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    26 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          15u,                                            12u, 10u,      0x00u,       20u,       128u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/ext_authKeyId_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    27 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          18u,                                            15u, 11u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/ext_basicConstraints_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    28 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           9u,                                             6u, 12u,      0x00u,        1u,         3u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/ext_keyUsage_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    29 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          34u,                                            21u, 13u,      0x01u,        1u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/ext_pkiRole_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    30 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u, 14u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM                          },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/signatureAlgorithm_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    31 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT, 15u,      0x00u,       65u,         3u, KEYM_CERTIFICATE_SIGNATURE                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/signatureValue_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  { /*    32 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  0u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_VERSION_NUMBER                               },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/Version_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    33 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  1u,      0x00u,       16u,         2u, KEYM_CERTIFICATE_SERIAL_NUMBER                                },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/SerialNo_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    34 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  2u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID                       },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/SigAlgoId_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    35 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  3u,      0x00u,       15u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/Issuer_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    36 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  4u,      0x00u,       13u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE                   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/validityNotBefore_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    37 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  5u,      0x00u,       15u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/validityNotAfter_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    38 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  6u,      0x00u,       30u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/subject_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    39 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  7u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/SubjectPublicKeyInfoAlgo_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    40 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  8u,      0x00u,       33u,         3u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/SubjectPublicKeyInfoKey_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    41 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           9u,                                             6u,  9u,      0x01u,        1u,         3u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/ext_keyUsage_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    42 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          12u,                                             9u, 10u,      0x00u,       20u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/ext_subKeyId_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    43 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          15u,                                            12u, 11u,      0x00u,       20u,       128u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/ext_authKeyId_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    44 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          34u,                                            21u, 12u,      0x01u,        1u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/ext_pkiRole_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    45 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          68u,                                            55u, 13u,      0x02u,      170u,        12u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/ext_uniqueECUID_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    46 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          47u,                                            34u, 14u,      0x01u,        1u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/ext_specialEcu_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    47 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u, 15u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM                          },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/signatureAlgorithm_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    48 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT, 16u,      0x00u,       65u,         3u, KEYM_CERTIFICATE_SIGNATURE                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/signatureValue_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  { /*    49 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  0u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_VERSION_NUMBER                               },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/Version_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
    /* Index    CertificateElementVerificationCalloutIdx                              ElementOidEndIdx                              ElementOidStartIdx                              Id   MaskedBits  MaxLength  ObjectType  OfStructure                                                          Referable Keys */
  { /*    50 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  1u,      0x00u,       16u,         2u, KEYM_CERTIFICATE_SERIAL_NUMBER                                },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/SerialNo_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    51 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  2u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID                       },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/SigAlgoId_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    52 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  3u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/Issuer_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    53 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  4u,      0x00u,        1u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE                   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/validityNotBefore_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    54 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  5u,      0x00u,        1u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/validityNotAfter_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    55 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  6u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/subject_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCsrCertElemCommonNameRef] */
  { /*    56 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  7u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/SubjectPublicKeyInfoAlgo_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    57 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  8u,      0x00u,       33u,         3u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/SubjectPublicKeyInfoKey_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    58 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          12u,                                             9u,  9u,      0x00u,       20u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_subKeyId_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    59 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          15u,                                            12u, 10u,      0x00u,        1u,       128u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_authKeyId_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    60 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           9u,                                             6u, 11u,      0x00u,        1u,         3u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_keyUsage_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    61 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          21u,                                            18u, 12u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_extKeyUsage_007, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    62 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          55u,                                            47u, 13u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_extKeyUsage_oid1_007, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    63 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          76u,                                            68u, 14u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_extKeyUsage_oid2_007, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    64 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          84u,                                            76u, 15u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_extKeyUsage_oid3_007, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    65 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          34u,                                            21u, 16u,      0x00u,        1u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_pkiRole_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    66 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          68u,                                            55u, 17u,      0x02u,        1u,        12u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_uniqueECUID_007, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCsrCertElemUniqueEcuIdRef] */
  { /*    67 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          47u,                                            34u, 18u,      0x01u,        1u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_specialEcu_007, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCsrCertElemSpecialEcuRef] */
  { /*    68 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u, 19u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM                          },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/signatureAlgorithm_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    69 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT, 20u,      0x00u,       65u,         3u, KEYM_CERTIFICATE_SIGNATURE                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/signatureValue_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  { /*    70 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  0u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_VERSION_NUMBER                               },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/Version_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    71 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  1u,      0x00u,       16u,         2u, KEYM_CERTIFICATE_SERIAL_NUMBER                                },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/SerialNo_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    72 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  2u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID                       },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/SigAlgoId_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    73 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  3u,      0x00u,       20u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/Issuer_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    74 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  4u,      0x00u,       13u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE                   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/validityNotBefore_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    75 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  5u,      0x00u,       15u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/validityNotAfter_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    76 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  6u,      0x00u,       48u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/subject_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    77 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  7u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/SubjectPublicKeyInfoAlgo_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    78 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  8u,      0x00u,       33u,         3u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/SubjectPublicKeyInfoKey_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    79 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           9u,                                             6u,  9u,      0x01u,        1u,         3u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/ext_keyUsage_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    80 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          12u,                                             9u, 10u,      0x00u,       20u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/ext_subKeyId_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    81 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          15u,                                            12u, 11u,      0x00u,       20u,       128u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/ext_authKeyId_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    82 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          47u,                                            34u, 12u,      0x01u,        1u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/ext_specialEcu_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    83 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          68u,                                            55u, 13u,      0x02u,       12u,        12u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/ext_uniqueECUID_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    84 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u, 14u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM                          },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/signatureAlgorithm_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    85 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT, 15u,      0x00u,       65u,         3u, KEYM_CERTIFICATE_SIGNATURE                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/signatureValue_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  { /*    86 */                                                                   0u, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  0u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_VERSION_NUMBER                               },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/Version_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*    87 */                                                                   0u, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  1u,      0x00u,       16u,         2u, KEYM_CERTIFICATE_SERIAL_NUMBER                                },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/SerialNo_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*    88 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  2u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID                       },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/SigAlgoId_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*    89 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  3u,      0x00u,       15u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/Issuer_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*    90 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  4u,      0x00u,       13u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE                   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/validityNotBefore_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*    91 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  5u,      0x00u,       15u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/validityNotAfter_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*    92 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  6u,      0x00u,       30u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/subject_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*    93 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  7u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/SubjectPublicKeyInfoAlgo_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*    94 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  8u,      0x00u,       33u,         3u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/SubjectPublicKeyInfoKey_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*    95 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          12u,                                             9u,  9u,      0x00u,       20u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/ext_subKeyId_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*    96 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          15u,                                            12u, 10u,      0x00u,       20u,       128u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/ext_authKeyId_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*    97 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          18u,                                            15u, 11u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/ext_basicConstraints_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*    98 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           9u,                                             6u, 12u,      0x00u,        1u,         3u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/ext_keyUsage_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*    99 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          34u,                                            21u, 13u,      0x01u,        1u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/ext_pkiRole_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
    /* Index    CertificateElementVerificationCalloutIdx                              ElementOidEndIdx                              ElementOidStartIdx                              Id   MaskedBits  MaxLength  ObjectType  OfStructure                                                          Referable Keys */
  { /*   100 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u, 14u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM                          },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/signatureAlgorithm_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*   101 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT, 15u,      0x00u,       65u,         3u, KEYM_CERTIFICATE_SIGNATURE                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/signatureValue_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  { /*   102 */                                                                   0u, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  0u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_VERSION_NUMBER                               },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/Version_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   103 */                                                                   0u, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  1u,      0x00u,       16u,         2u, KEYM_CERTIFICATE_SERIAL_NUMBER                                },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/SerialNo_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   104 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  2u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID                       },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/SigAlgoId_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   105 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  3u,      0x00u,       15u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/Issuer_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   106 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  4u,      0x00u,       13u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE                   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/validityNotBefore_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   107 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  5u,      0x00u,       15u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/validityNotAfter_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   108 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  6u,      0x00u,       20u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/subject_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   109 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  7u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/SubjectPublicKeyInfoAlgo_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   110 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  8u,      0x00u,       33u,         3u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/SubjectPublicKeyInfoKey_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   111 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          12u,                                             9u,  9u,      0x00u,       20u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/ext_subKeyId_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   112 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          15u,                                            12u, 10u,      0x00u,       20u,       128u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/ext_authKeyId_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   113 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          18u,                                            15u, 11u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/ext_basicConstraints_005, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   114 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           9u,                                             6u, 12u,      0x00u,        1u,         3u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/ext_keyUsage_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   115 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          34u,                                            21u, 13u,      0x01u,        1u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/ext_pkiRole_005, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   116 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u, 14u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM                          },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/signatureAlgorithm_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   117 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT, 15u,      0x00u,       65u,         3u, KEYM_CERTIFICATE_SIGNATURE                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/signatureValue_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  { /*   118 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  0u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_VERSION_NUMBER                               },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/Version, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   119 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  1u,      0x00u,       16u,         2u, KEYM_CERTIFICATE_SERIAL_NUMBER                                },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/SerialNo, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   120 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  2u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID                       },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/SigAlgoId, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   121 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  3u,      0x00u,       15u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/Issuer, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   122 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  4u,      0x00u,       13u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE                   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/validityNotBefore, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   123 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  5u,      0x00u,       15u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/validityNotAfter, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   124 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           6u,                                             3u,  6u,      0x00u,       30u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/subject, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   125 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u,  7u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/SubjectPublicKeyInfoAlgo, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   126 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  8u,      0x00u,       33u,         3u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY   },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/SubjectPublicKeyInfoKey, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   127 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          12u,                                             9u,  9u,      0x00u,       20u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/ext_subKeyId, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   128 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          18u,                                            15u, 10u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/ext_basicConstraints, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   129 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           9u,                                             6u, 11u,      0x00u,        2u,         3u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/ext_keyUsage, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   130 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          15u,                                            12u, 12u,      0x01u,       20u,       128u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/ext_authKeyId_009, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   131 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                          34u,                                            21u, 13u,      0x01u,        1u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/ext_pkiRole, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   132 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT,                                           3u,                                             0u, 14u,      0x00u,        3u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM                          },  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/signatureAlgorithm, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  { /*   133 */ KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT, 15u,      0x00u,       65u,         3u, KEYM_CERTIFICATE_SIGNATURE                                    }   /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/signatureValue, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
};
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateElementVerificationCallout
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(KeyM_CertificateElementVerificationCalloutFctPtrType, KEYM_CONST) KeyM_CertificateElementVerificationCallout[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CertificateElementVerificationCallout               Referable Keys */
  /*     0 */ Tsc_Appl_CertificateElementVerificationCallout    /* [Tsc_Appl_CertificateElementVerificationCallout] */
};
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateGetCurrentTimeCallout
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(KeyM_CertificateGetCurrentTimeCalloutFctPtrType, KEYM_CONST) KeyM_CertificateGetCurrentTimeCallout[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CertificateGetCurrentTimeCallout                      Referable Keys */
  /*     0 */ TscAppl_KeyMCertificateGetCurrentTimeCalloutFunc    /* [TscAppl_KeyMCertificateGetCurrentTimeCalloutFunc] */
};
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateInitValue
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(KeyM_CertificateInitValueType, KEYM_CONST) KeyM_CertificateInitValue[292] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CertificateInitValue      Referable Keys */
  /*     0 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*     1 */                 0x82u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*     2 */                 0x01u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*     3 */                 0x20u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*     4 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*     5 */                 0x81u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*     6 */                 0xD3u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*     7 */                 0xA0u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*     8 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*     9 */                 0x02u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    10 */                 0x01u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    11 */                 0x02u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    12 */                 0x02u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    13 */                 0x08u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    14 */                 0x69u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    15 */                 0x43u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    16 */                 0x9Bu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    17 */                 0x49u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    18 */                 0x78u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    19 */                 0x93u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    20 */                 0x6Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    21 */                 0x4Bu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    22 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    23 */                 0x05u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    24 */                 0x06u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    25 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    26 */                 0x2Bu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    27 */                 0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    28 */                 0x70u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    29 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    30 */                 0x12u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    31 */                 0x31u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    32 */                 0x10u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    33 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    34 */                 0x0Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    35 */                 0x06u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    36 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    37 */                 0x55u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    38 */                 0x04u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    39 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    40 */                 0x0Cu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    41 */                 0x07u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    42 */                 0x45u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    43 */                 0x41u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    44 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    45 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    46 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    47 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    48 */                 0x31u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    49 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /* Index     CertificateInitValue      Referable Keys */
  /*    50 */                 0x20u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    51 */                 0x17u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    52 */                 0x0Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    53 */                 0x32u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    54 */                 0x32u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    55 */                 0x31u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    56 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    57 */                 0x31u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    58 */                 0x37u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    59 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    60 */                 0x39u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    61 */                 0x32u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    62 */                 0x37u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    63 */                 0x32u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    64 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    65 */                 0x5Au,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    66 */                 0x18u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    67 */                 0x0Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    68 */                 0x39u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    69 */                 0x39u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    70 */                 0x39u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    71 */                 0x39u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    72 */                 0x31u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    73 */                 0x32u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    74 */                 0x33u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    75 */                 0x31u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    76 */                 0x32u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    77 */                 0x33u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    78 */                 0x35u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    79 */                 0x39u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    80 */                 0x35u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    81 */                 0x39u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    82 */                 0x5Au,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    83 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    84 */                 0x12u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    85 */                 0x31u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    86 */                 0x10u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    87 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    88 */                 0x0Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    89 */                 0x06u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    90 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    91 */                 0x55u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    92 */                 0x04u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    93 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    94 */                 0x0Cu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    95 */                 0x07u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    96 */                 0x45u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    97 */                 0x41u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    98 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*    99 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /* Index     CertificateInitValue      Referable Keys */
  /*   100 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   101 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   102 */                 0x31u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   103 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   104 */                 0x2Au,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   105 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   106 */                 0x05u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   107 */                 0x06u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   108 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   109 */                 0x2Bu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   110 */                 0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   111 */                 0x70u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   112 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   113 */                 0x21u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   114 */                 0x00u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   115 */                 0xE6u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   116 */                 0x1Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   117 */                 0xA2u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   118 */                 0x53u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   119 */                 0x49u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   120 */                 0xAFu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   121 */                 0x0Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   122 */                 0x89u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   123 */                 0xA4u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   124 */                 0xFDu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   125 */                 0x32u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   126 */                 0x43u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   127 */                 0x5Bu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   128 */                 0x21u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   129 */                 0x3Bu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   130 */                 0x1Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   131 */                 0xCAu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   132 */                 0x1Au,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   133 */                 0x02u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   134 */                 0x06u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   135 */                 0x3Bu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   136 */                 0x02u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   137 */                 0xD5u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   138 */                 0x50u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   139 */                 0xBCu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   140 */                 0x1Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   141 */                 0x1Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   142 */                 0x09u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   143 */                 0x18u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   144 */                 0xA7u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   145 */                 0x2Cu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   146 */                 0xBAu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   147 */                 0xA3u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   148 */                 0x45u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   149 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /* Index     CertificateInitValue      Referable Keys */
  /*   150 */                 0x43u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   151 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   152 */                 0x1Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   153 */                 0x06u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   154 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   155 */                 0x55u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   156 */                 0x1Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   157 */                 0x0Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   158 */                 0x04u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   159 */                 0x16u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   160 */                 0x04u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   161 */                 0x14u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   162 */                 0x68u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   163 */                 0x35u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   164 */                 0x0Au,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   165 */                 0x9Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   166 */                 0x2Cu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   167 */                 0xB7u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   168 */                 0xE0u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   169 */                 0x2Au,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   170 */                 0x6Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   171 */                 0x46u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   172 */                 0xD4u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   173 */                 0x29u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   174 */                 0xD0u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   175 */                 0x5Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   176 */                 0x47u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   177 */                 0x84u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   178 */                 0xA2u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   179 */                 0x56u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   180 */                 0x6Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   181 */                 0xF9u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   182 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   183 */                 0x12u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   184 */                 0x06u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   185 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   186 */                 0x55u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   187 */                 0x1Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   188 */                 0x13u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   189 */                 0x01u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   190 */                 0x01u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   191 */                 0xFFu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   192 */                 0x04u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   193 */                 0x08u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   194 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   195 */                 0x06u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   196 */                 0x01u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   197 */                 0x01u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   198 */                 0xFFu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   199 */                 0x02u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /* Index     CertificateInitValue      Referable Keys */
  /*   200 */                 0x01u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   201 */                 0x02u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   202 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   203 */                 0x0Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   204 */                 0x06u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   205 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   206 */                 0x55u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   207 */                 0x1Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   208 */                 0x0Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   209 */                 0x01u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   210 */                 0x01u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   211 */                 0xFFu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   212 */                 0x04u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   213 */                 0x04u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   214 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   215 */                 0x02u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   216 */                 0x02u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   217 */                 0x04u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   218 */                 0x30u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   219 */                 0x05u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   220 */                 0x06u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   221 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   222 */                 0x2Bu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   223 */                 0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   224 */                 0x70u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   225 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   226 */                 0x41u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   227 */                 0x00u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   228 */                 0x5Au,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   229 */                 0x4Au,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   230 */                 0x9Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   231 */                 0x20u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   232 */                 0x50u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   233 */                 0x6Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   234 */                 0xBCu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   235 */                 0x00u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   236 */                 0xF5u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   237 */                 0xEBu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   238 */                 0x16u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   239 */                 0x81u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   240 */                 0x9Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   241 */                 0xC1u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   242 */                 0x0Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   243 */                 0x59u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   244 */                 0x61u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   245 */                 0xFDu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   246 */                 0x03u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   247 */                 0xB6u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   248 */                 0xBDu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   249 */                 0xC2u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /* Index     CertificateInitValue      Referable Keys */
  /*   250 */                 0x68u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   251 */                 0x23u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   252 */                 0x28u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   253 */                 0xAEu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   254 */                 0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   255 */                 0x7Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   256 */                 0x13u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   257 */                 0x61u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   258 */                 0x19u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   259 */                 0x05u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   260 */                 0xC8u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   261 */                 0x1Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   262 */                 0xFDu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   263 */                 0x4Bu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   264 */                 0xA2u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   265 */                 0xF5u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   266 */                 0x80u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   267 */                 0x90u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   268 */                 0x6Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   269 */                 0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   270 */                 0x33u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   271 */                 0x96u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   272 */                 0x43u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   273 */                 0xDCu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   274 */                 0x37u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   275 */                 0x97u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   276 */                 0xD7u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   277 */                 0xB2u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   278 */                 0xADu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   279 */                 0x1Bu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   280 */                 0x3Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   281 */                 0x14u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   282 */                 0x5Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   283 */                 0xADu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   284 */                 0x08u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   285 */                 0x51u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   286 */                 0x70u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   287 */                 0x95u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   288 */                 0xF8u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   289 */                 0x80u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   290 */                 0x0Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   291 */                 0x0Cu   /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
};
#define KEYM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateInitValueInfo
**********************************************************************************************************************/
/** 
  \var    KeyM_CertificateInitValueInfo
  \details
  Element                       Description
  CertificateInitValueLength    the number of relations pointing to KeyM_CertificateInitValue
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(KeyM_CertificateInitValueInfoType, KEYM_CONST) KeyM_CertificateInitValueInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CertificateInitValueLength        Referable Keys */
  { /*     0 */                       292u }   /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
};
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateName
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(KeyM_CertificateNameType, KEYM_CONST) KeyM_CertificateName[174] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CertificateName      Referable Keys */
  /*     0 */            0x54u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     1 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     2 */            0x75u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     3 */            0x73u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     4 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     5 */            0x4Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     6 */            0x6Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     7 */            0x64u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     8 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     9 */            0x6Cu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    10 */            0x42u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    11 */            0x61u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    12 */            0x63u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    13 */            0x6Bu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    14 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    15 */            0x6Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    16 */            0x64u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    17 */            0x43u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    18 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    19 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    20 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    21 */            0x54u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    22 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    23 */            0x75u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    24 */            0x73u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    25 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    26 */            0x4Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    27 */            0x6Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    28 */            0x64u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    29 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    30 */            0x6Cu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    31 */            0x42u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    32 */            0x61u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    33 */            0x63u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    34 */            0x6Bu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    35 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    36 */            0x6Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    37 */            0x64u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    38 */            0x50u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    39 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    40 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    41 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    42 */            0x43u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    43 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    44 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    45 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    46 */            0x54u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    47 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    48 */            0x75u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    49 */            0x73u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /* Index     CertificateName      Referable Keys */
  /*    50 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    51 */            0x4Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    52 */            0x6Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    53 */            0x64u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    54 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    55 */            0x6Cu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    56 */            0x45u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    57 */            0x63u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    58 */            0x75u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    59 */            0x43u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    60 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    61 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    62 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    63 */            0x54u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    64 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    65 */            0x75u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    66 */            0x73u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    67 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    68 */            0x4Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    69 */            0x6Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    70 */            0x64u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    71 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    72 */            0x6Cu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    73 */            0x45u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    74 */            0x63u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    75 */            0x75u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    76 */            0x43u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    77 */            0x73u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    78 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    79 */            0x54u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    80 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    81 */            0x75u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    82 */            0x73u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    83 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    84 */            0x4Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    85 */            0x6Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    86 */            0x64u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    87 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    88 */            0x6Cu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    89 */            0x45u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    90 */            0x63u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    91 */            0x75u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    92 */            0x50u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    93 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    94 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    95 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    96 */            0x43u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    97 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    98 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    99 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /* Index     CertificateName      Referable Keys */
  /*   100 */            0x54u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   101 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   102 */            0x75u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   103 */            0x73u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   104 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   105 */            0x4Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   106 */            0x6Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   107 */            0x64u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   108 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   109 */            0x6Cu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   110 */            0x49u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   111 */            0x6Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   112 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   113 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   114 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   115 */            0x6Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   116 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   117 */            0x64u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   118 */            0x69u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   119 */            0x61u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   120 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   121 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   122 */            0x43u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   123 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   124 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   125 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   126 */            0x54u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   127 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   128 */            0x75u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   129 */            0x73u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   130 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   131 */            0x4Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   132 */            0x6Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   133 */            0x64u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   134 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   135 */            0x6Cu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   136 */            0x49u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   137 */            0x6Eu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   138 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   139 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   140 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   141 */            0x6Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   142 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   143 */            0x64u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   144 */            0x69u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   145 */            0x61u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   146 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   147 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   148 */            0x50u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   149 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /* Index     CertificateName      Referable Keys */
  /*   150 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   151 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   152 */            0x43u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   153 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   154 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   155 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   156 */            0x54u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   157 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   158 */            0x75u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   159 */            0x73u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   160 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   161 */            0x4Du,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   162 */            0x6Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   163 */            0x64u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   164 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   165 */            0x6Cu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   166 */            0x52u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   167 */            0x6Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   168 */            0x6Fu,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   169 */            0x74u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   170 */            0x43u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   171 */            0x65u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   172 */            0x72u,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   173 */            0x74u   /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
};
#define KEYM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertificateVerifyCallbackNotificationWithoutId
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(KeyM_CertificateVerifyCallbackNotificationWithoutIdFctPtrType, KEYM_CONST) KeyM_CertificateVerifyCallbackNotificationWithoutId[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CertificateVerifyCallbackNotificationWithoutId                                                                     Referable Keys */
  /*     0 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelBackendCert_CertificateVerifyCallbackNotification          ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     1 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelBackendPeerCert_CertificateVerifyCallbackNotification      ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*     2 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelEcuCert_CertificateVerifyCallbackNotification              ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*     3 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelEcuCsr_CertificateVerifyCallbackNotification               ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*     4 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelEcuPeerCert_CertificateVerifyCallbackNotification          ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*     5 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelIntermediateCert_CertificateVerifyCallbackNotification     ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*     6 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelIntermediatePeerCert_CertificateVerifyCallbackNotification ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*     7 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelRootCert_CertificateVerifyCallbackNotification                /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
};
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_ElementOid
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(KeyM_ElementOidType, KEYM_CONST) KeyM_ElementOid[84] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ElementOid      Comment                                          Referable Keys */
  /*     0 */         43u,  /* [1.3.101.112 | 1.3:0]                     */  /* [1.3.101.112] */
  /*     1 */        101u,  /* [1.3.101.112 | 101:0]                     */  /* [1.3.101.112] */
  /*     2 */        112u,  /* [1.3.101.112 | 112:0]                     */  /* [1.3.101.112] */
  /*     3 */         85u,  /* [2.5.4.3 | 2.5:0]                         */  /* [2.5.4.3] */
  /*     4 */          4u,  /* [2.5.4.3 | 4:0]                           */  /* [2.5.4.3] */
  /*     5 */          3u,  /* [2.5.4.3 | 3:0]                           */  /* [2.5.4.3] */
  /*     6 */         85u,  /* [2.5.29.15 | 2.5:0]                       */  /* [2.5.29.15] */
  /*     7 */         29u,  /* [2.5.29.15 | 29:0]                        */  /* [2.5.29.15] */
  /*     8 */         15u,  /* [2.5.29.15 | 15:0]                        */  /* [2.5.29.15] */
  /*     9 */         85u,  /* [2.5.29.14 | 2.5:0]                       */  /* [2.5.29.14] */
  /*    10 */         29u,  /* [2.5.29.14 | 29:0]                        */  /* [2.5.29.14] */
  /*    11 */         14u,  /* [2.5.29.14 | 14:0]                        */  /* [2.5.29.14] */
  /*    12 */         85u,  /* [2.5.29.35 | 2.5:0]                       */  /* [2.5.29.35] */
  /*    13 */         29u,  /* [2.5.29.35 | 29:0]                        */  /* [2.5.29.35] */
  /*    14 */         35u,  /* [2.5.29.35 | 35:0]                        */  /* [2.5.29.35] */
  /*    15 */         85u,  /* [2.5.29.19 | 2.5:0]                       */  /* [2.5.29.19] */
  /*    16 */         29u,  /* [2.5.29.19 | 29:0]                        */  /* [2.5.29.19] */
  /*    17 */         19u,  /* [2.5.29.19 | 19:0]                        */  /* [2.5.29.19] */
  /*    18 */         85u,  /* [2.5.29.37 | 2.5:0]                       */  /* [2.5.29.37] */
  /*    19 */         29u,  /* [2.5.29.37 | 29:0]                        */  /* [2.5.29.37] */
  /*    20 */         37u,  /* [2.5.29.37 | 37:0]                        */  /* [2.5.29.37] */
  /*    21 */         43u,  /* [1.3.6.1.4.1.2916.3.6.509.5.101 | 1.3:0]  */  /* [1.3.6.1.4.1.2916.3.6.509.5.101] */
  /*    22 */          6u,  /* [1.3.6.1.4.1.2916.3.6.509.5.101 | 6:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.101] */
  /*    23 */          1u,  /* [1.3.6.1.4.1.2916.3.6.509.5.101 | 1:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.101] */
  /*    24 */          4u,  /* [1.3.6.1.4.1.2916.3.6.509.5.101 | 4:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.101] */
  /*    25 */          1u,  /* [1.3.6.1.4.1.2916.3.6.509.5.101 | 1:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.101] */
  /*    26 */        150u,  /* [1.3.6.1.4.1.2916.3.6.509.5.101 | 2916:0] */  /* [1.3.6.1.4.1.2916.3.6.509.5.101] */
  /*    27 */        100u,  /* [1.3.6.1.4.1.2916.3.6.509.5.101 | 2916:1] */  /* [1.3.6.1.4.1.2916.3.6.509.5.101] */
  /*    28 */          3u,  /* [1.3.6.1.4.1.2916.3.6.509.5.101 | 3:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.101] */
  /*    29 */          6u,  /* [1.3.6.1.4.1.2916.3.6.509.5.101 | 6:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.101] */
  /*    30 */        131u,  /* [1.3.6.1.4.1.2916.3.6.509.5.101 | 509:0]  */  /* [1.3.6.1.4.1.2916.3.6.509.5.101] */
  /*    31 */        125u,  /* [1.3.6.1.4.1.2916.3.6.509.5.101 | 509:1]  */  /* [1.3.6.1.4.1.2916.3.6.509.5.101] */
  /*    32 */          5u,  /* [1.3.6.1.4.1.2916.3.6.509.5.101 | 5:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.101] */
  /*    33 */        101u,  /* [1.3.6.1.4.1.2916.3.6.509.5.101 | 101:0]  */  /* [1.3.6.1.4.1.2916.3.6.509.5.101] */
  /*    34 */         43u,  /* [1.3.6.1.4.1.2916.3.6.509.5.109 | 1.3:0]  */  /* [1.3.6.1.4.1.2916.3.6.509.5.109] */
  /*    35 */          6u,  /* [1.3.6.1.4.1.2916.3.6.509.5.109 | 6:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.109] */
  /*    36 */          1u,  /* [1.3.6.1.4.1.2916.3.6.509.5.109 | 1:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.109] */
  /*    37 */          4u,  /* [1.3.6.1.4.1.2916.3.6.509.5.109 | 4:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.109] */
  /*    38 */          1u,  /* [1.3.6.1.4.1.2916.3.6.509.5.109 | 1:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.109] */
  /*    39 */        150u,  /* [1.3.6.1.4.1.2916.3.6.509.5.109 | 2916:0] */  /* [1.3.6.1.4.1.2916.3.6.509.5.109] */
  /*    40 */        100u,  /* [1.3.6.1.4.1.2916.3.6.509.5.109 | 2916:1] */  /* [1.3.6.1.4.1.2916.3.6.509.5.109] */
  /*    41 */          3u,  /* [1.3.6.1.4.1.2916.3.6.509.5.109 | 3:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.109] */
  /*    42 */          6u,  /* [1.3.6.1.4.1.2916.3.6.509.5.109 | 6:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.109] */
  /*    43 */        131u,  /* [1.3.6.1.4.1.2916.3.6.509.5.109 | 509:0]  */  /* [1.3.6.1.4.1.2916.3.6.509.5.109] */
  /*    44 */        125u,  /* [1.3.6.1.4.1.2916.3.6.509.5.109 | 509:1]  */  /* [1.3.6.1.4.1.2916.3.6.509.5.109] */
  /*    45 */          5u,  /* [1.3.6.1.4.1.2916.3.6.509.5.109 | 5:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.109] */
  /*    46 */        109u,  /* [1.3.6.1.4.1.2916.3.6.509.5.109 | 109:0]  */  /* [1.3.6.1.4.1.2916.3.6.509.5.109] */
  /*    47 */         43u,  /* [1.3.6.1.5.5.7.3.1 | 1.3:0]               */  /* [1.3.6.1.5.5.7.3.1] */
  /*    48 */          6u,  /* [1.3.6.1.5.5.7.3.1 | 6:0]                 */  /* [1.3.6.1.5.5.7.3.1] */
  /*    49 */          1u,  /* [1.3.6.1.5.5.7.3.1 | 1:0]                 */  /* [1.3.6.1.5.5.7.3.1] */
  /* Index     ElementOid      Comment                                          Referable Keys */
  /*    50 */          5u,  /* [1.3.6.1.5.5.7.3.1 | 5:0]                 */  /* [1.3.6.1.5.5.7.3.1] */
  /*    51 */          5u,  /* [1.3.6.1.5.5.7.3.1 | 5:0]                 */  /* [1.3.6.1.5.5.7.3.1] */
  /*    52 */          7u,  /* [1.3.6.1.5.5.7.3.1 | 7:0]                 */  /* [1.3.6.1.5.5.7.3.1] */
  /*    53 */          3u,  /* [1.3.6.1.5.5.7.3.1 | 3:0]                 */  /* [1.3.6.1.5.5.7.3.1] */
  /*    54 */          1u,  /* [1.3.6.1.5.5.7.3.1 | 1:0]                 */  /* [1.3.6.1.5.5.7.3.1] */
  /*    55 */         43u,  /* [1.3.6.1.4.1.2916.3.6.509.5.108 | 1.3:0]  */  /* [1.3.6.1.4.1.2916.3.6.509.5.108] */
  /*    56 */          6u,  /* [1.3.6.1.4.1.2916.3.6.509.5.108 | 6:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.108] */
  /*    57 */          1u,  /* [1.3.6.1.4.1.2916.3.6.509.5.108 | 1:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.108] */
  /*    58 */          4u,  /* [1.3.6.1.4.1.2916.3.6.509.5.108 | 4:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.108] */
  /*    59 */          1u,  /* [1.3.6.1.4.1.2916.3.6.509.5.108 | 1:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.108] */
  /*    60 */        150u,  /* [1.3.6.1.4.1.2916.3.6.509.5.108 | 2916:0] */  /* [1.3.6.1.4.1.2916.3.6.509.5.108] */
  /*    61 */        100u,  /* [1.3.6.1.4.1.2916.3.6.509.5.108 | 2916:1] */  /* [1.3.6.1.4.1.2916.3.6.509.5.108] */
  /*    62 */          3u,  /* [1.3.6.1.4.1.2916.3.6.509.5.108 | 3:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.108] */
  /*    63 */          6u,  /* [1.3.6.1.4.1.2916.3.6.509.5.108 | 6:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.108] */
  /*    64 */        131u,  /* [1.3.6.1.4.1.2916.3.6.509.5.108 | 509:0]  */  /* [1.3.6.1.4.1.2916.3.6.509.5.108] */
  /*    65 */        125u,  /* [1.3.6.1.4.1.2916.3.6.509.5.108 | 509:1]  */  /* [1.3.6.1.4.1.2916.3.6.509.5.108] */
  /*    66 */          5u,  /* [1.3.6.1.4.1.2916.3.6.509.5.108 | 5:0]    */  /* [1.3.6.1.4.1.2916.3.6.509.5.108] */
  /*    67 */        108u,  /* [1.3.6.1.4.1.2916.3.6.509.5.108 | 108:0]  */  /* [1.3.6.1.4.1.2916.3.6.509.5.108] */
  /*    68 */         43u,  /* [1.3.6.1.5.5.7.3.2 | 1.3:0]               */  /* [1.3.6.1.5.5.7.3.2] */
  /*    69 */          6u,  /* [1.3.6.1.5.5.7.3.2 | 6:0]                 */  /* [1.3.6.1.5.5.7.3.2] */
  /*    70 */          1u,  /* [1.3.6.1.5.5.7.3.2 | 1:0]                 */  /* [1.3.6.1.5.5.7.3.2] */
  /*    71 */          5u,  /* [1.3.6.1.5.5.7.3.2 | 5:0]                 */  /* [1.3.6.1.5.5.7.3.2] */
  /*    72 */          5u,  /* [1.3.6.1.5.5.7.3.2 | 5:0]                 */  /* [1.3.6.1.5.5.7.3.2] */
  /*    73 */          7u,  /* [1.3.6.1.5.5.7.3.2 | 7:0]                 */  /* [1.3.6.1.5.5.7.3.2] */
  /*    74 */          3u,  /* [1.3.6.1.5.5.7.3.2 | 3:0]                 */  /* [1.3.6.1.5.5.7.3.2] */
  /*    75 */          2u,  /* [1.3.6.1.5.5.7.3.2 | 2:0]                 */  /* [1.3.6.1.5.5.7.3.2] */
  /*    76 */         43u,  /* [1.3.6.1.5.5.7.3.17 | 1.3:0]              */  /* [1.3.6.1.5.5.7.3.17] */
  /*    77 */          6u,  /* [1.3.6.1.5.5.7.3.17 | 6:0]                */  /* [1.3.6.1.5.5.7.3.17] */
  /*    78 */          1u,  /* [1.3.6.1.5.5.7.3.17 | 1:0]                */  /* [1.3.6.1.5.5.7.3.17] */
  /*    79 */          5u,  /* [1.3.6.1.5.5.7.3.17 | 5:0]                */  /* [1.3.6.1.5.5.7.3.17] */
  /*    80 */          5u,  /* [1.3.6.1.5.5.7.3.17 | 5:0]                */  /* [1.3.6.1.5.5.7.3.17] */
  /*    81 */          7u,  /* [1.3.6.1.5.5.7.3.17 | 7:0]                */  /* [1.3.6.1.5.5.7.3.17] */
  /*    82 */          3u,  /* [1.3.6.1.5.5.7.3.17 | 3:0]                */  /* [1.3.6.1.5.5.7.3.17] */
  /*    83 */         17u   /* [1.3.6.1.5.5.7.3.17 | 17:0]               */  /* [1.3.6.1.5.5.7.3.17] */
};
#define KEYM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_General
**********************************************************************************************************************/
/** 
  \var    KeyM_General
  \brief  Contains parameters of /MICROSAR/KeyM/KeyMGeneral.
  \details
  Element                         Description
  KeyMCsmRemoteInfoJobRefAsync
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(KeyM_GeneralType, KEYM_CONST) KeyM_General[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    KeyMCsmRemoteInfoJobRefAsync        Referable Keys */
  { /*     0 */                        FALSE }   /* [/ActiveEcuC/KeyM/KeyMGeneral, /ActiveEcuC/KeyM] */
};
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_ServiceCertificateRteCallbackNotification440
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(KeyM_ServiceCertificateRteCallbackNotification440FctPtrType, KEYM_CONST) KeyM_ServiceCertificateRteCallbackNotification440[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ServiceCertificateRteCallbackNotification440                                                                        Referable Keys */
  /*     0 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelBackendCert_ServiceCertificateCallbackNotification          ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     1 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelBackendPeerCert_ServiceCertificateCallbackNotification      ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*     2 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelEcuCert_ServiceCertificateCallbackNotification              ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*     3 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelEcuCsr_ServiceCertificateCallbackNotification               ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*     4 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelEcuPeerCert_ServiceCertificateCallbackNotification          ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*     5 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelIntermediateCert_ServiceCertificateCallbackNotification     ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*     6 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelIntermediatePeerCert_ServiceCertificateCallbackNotification ,  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*     7 */ Rte_Call_KeyMCertificateNotification_Ssa_TrustModelRootCert_ServiceCertificateCallbackNotification                /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
};
#define KEYM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CertStorage
**********************************************************************************************************************/
#define KEYM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(KeyM_CertStorageUType, KEYM_VAR_NO_INIT) KeyM_CertStorage;  /* PRQA S 0759, 1514, 1533, 0612, 0613 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
  /* Index        Referable Keys */
  /*     0 */  /* [Ssa_TrustModelBackendCert__WrittenLength__] */
  /*     1 */  /* [Ssa_TrustModelBackendCert__WrittenLength__] */
  /*     2 */  /* [Ssa_TrustModelBackendCert__Status__] */
  /*     3 */  /* [Ssa_TrustModelBackendCert__Status__] */
  /*     4 */  /* [Ssa_TrustModelBackendCert__Data__] */
  /*   ... */  /* [Ssa_TrustModelBackendCert__Data__] */
  /*  1003 */  /* [Ssa_TrustModelBackendCert__Data__] */
  /*  1004 */  /* [Ssa_TrustModelBackendPeerCert__WrittenLength__] */
  /*  1005 */  /* [Ssa_TrustModelBackendPeerCert__WrittenLength__] */
  /*  1006 */  /* [Ssa_TrustModelBackendPeerCert__Status__] */
  /*  1007 */  /* [Ssa_TrustModelBackendPeerCert__Status__] */
  /*  1008 */  /* [Ssa_TrustModelBackendPeerCert__Data__] */
  /*   ... */  /* [Ssa_TrustModelBackendPeerCert__Data__] */
  /*  2007 */  /* [Ssa_TrustModelBackendPeerCert__Data__] */
  /*  2008 */  /* [Ssa_TrustModelEcuCert__WrittenLength__] */
  /*  2009 */  /* [Ssa_TrustModelEcuCert__WrittenLength__] */
  /*  2010 */  /* [Ssa_TrustModelEcuCert__Status__] */
  /*  2011 */  /* [Ssa_TrustModelEcuCert__Status__] */
  /*  2012 */  /* [Ssa_TrustModelEcuCert__Data__] */
  /*   ... */  /* [Ssa_TrustModelEcuCert__Data__] */
  /*  3011 */  /* [Ssa_TrustModelEcuCert__Data__] */
  /*  3012 */  /* [Ssa_TrustModelEcuCsr__WrittenLength__] */
  /*  3013 */  /* [Ssa_TrustModelEcuCsr__WrittenLength__] */
  /*  3014 */  /* [Ssa_TrustModelEcuCsr__Status__] */
  /*  3015 */  /* [Ssa_TrustModelEcuCsr__Status__] */
  /*  3016 */  /* [Ssa_TrustModelEcuCsr__Data__] */
  /*   ... */  /* [Ssa_TrustModelEcuCsr__Data__] */
  /*  4015 */  /* [Ssa_TrustModelEcuCsr__Data__] */
  /*  4016 */  /* [Ssa_TrustModelEcuPeerCert__WrittenLength__] */
  /*  4017 */  /* [Ssa_TrustModelEcuPeerCert__WrittenLength__] */
  /*  4018 */  /* [Ssa_TrustModelEcuPeerCert__Status__] */
  /*  4019 */  /* [Ssa_TrustModelEcuPeerCert__Status__] */
  /*  4020 */  /* [Ssa_TrustModelEcuPeerCert__Data__] */
  /*   ... */  /* [Ssa_TrustModelEcuPeerCert__Data__] */
  /*  5019 */  /* [Ssa_TrustModelEcuPeerCert__Data__] */
  /*  5020 */  /* [Ssa_TrustModelIntermediateCert__WrittenLength__] */
  /*  5021 */  /* [Ssa_TrustModelIntermediateCert__WrittenLength__] */
  /*  5022 */  /* [Ssa_TrustModelIntermediateCert__Status__] */
  /*  5023 */  /* [Ssa_TrustModelIntermediateCert__Status__] */
  /*  5024 */  /* [Ssa_TrustModelIntermediateCert__Data__] */
  /*   ... */  /* [Ssa_TrustModelIntermediateCert__Data__] */
  /*  6023 */  /* [Ssa_TrustModelIntermediateCert__Data__] */
  /*  6024 */  /* [Ssa_TrustModelIntermediatePeerCert__WrittenLength__] */
  /*  6025 */  /* [Ssa_TrustModelIntermediatePeerCert__WrittenLength__] */
  /*  6026 */  /* [Ssa_TrustModelIntermediatePeerCert__Status__] */
  /*  6027 */  /* [Ssa_TrustModelIntermediatePeerCert__Status__] */
  /*  6028 */  /* [Ssa_TrustModelIntermediatePeerCert__Data__] */
  /*   ... */  /* [Ssa_TrustModelIntermediatePeerCert__Data__] */
  /*  7027 */  /* [Ssa_TrustModelIntermediatePeerCert__Data__] */
  /*  7028 */  /* [Ssa_TrustModelRootCert__WrittenLength__] */
  /*  7029 */  /* [Ssa_TrustModelRootCert__WrittenLength__] */
  /* Index        Referable Keys */
  /*  7030 */  /* [Ssa_TrustModelRootCert__Status__] */
  /*  7031 */  /* [Ssa_TrustModelRootCert__Status__] */
  /*  7032 */  /* [Ssa_TrustModelRootCert__Data__] */
  /*   ... */  /* [Ssa_TrustModelRootCert__Data__] */
  /*  8031 */  /* [Ssa_TrustModelRootCert__Data__] */

#define KEYM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_Cert_CertInfo
**********************************************************************************************************************/
/** 
  \var    KeyM_Cert_CertInfo
  \brief  Certificate data for signature verification, service request information and verification result
*/ 
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(tKeyMCertInfoType, KEYM_VAR_NO_INIT) KeyM_Cert_CertInfo[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert:KeyMCertUpperHierarchicalCertRef] */
  /*     1 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert:KeyMCertUpperHierarchicalCertRef] */
  /*     2 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert, /ActiveEcuC/KeyM, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCertRef] */
  /*     3 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCsrRef] */
  /*     4 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuPeerCertRef] */
  /*     5 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert:KeyMCertUpperHierarchicalCertRef] */
  /*     6 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert:KeyMCertUpperHierarchicalCertRef] */
  /*     7 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert:KeyMCertUpperHierarchicalCertRef] */

#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_Cert_LeafCertsToVerify
**********************************************************************************************************************/
/** 
  \var    KeyM_Cert_LeafCertsToVerify
  \brief  Buffer that contains certificate IDs of leaf certificates that shall be verified
*/ 
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(KeyM_CertificateIdType, KEYM_VAR_NO_INIT) KeyM_Cert_LeafCertsToVerify[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert:KeyMCertUpperHierarchicalCertRef] */
  /*     1 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert:KeyMCertUpperHierarchicalCertRef] */
  /*     2 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert, /ActiveEcuC/KeyM, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCertRef] */
  /*     3 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCsrRef] */
  /*     4 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuPeerCertRef] */
  /*     5 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert:KeyMCertUpperHierarchicalCertRef] */
  /*     6 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert:KeyMCertUpperHierarchicalCertRef] */
  /*     7 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert:KeyMCertUpperHierarchicalCertRef] */

#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_Cert_Lock
**********************************************************************************************************************/
/** 
  \var    KeyM_Cert_Lock
  \brief  Certificate Lock
*/ 
#define KEYM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(KeyM_Cert_LockType, KEYM_VAR_NO_INIT) KeyM_Cert_Lock[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert:KeyMCertUpperHierarchicalCertRef] */
  /*     1 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert:KeyMCertUpperHierarchicalCertRef] */
  /*     2 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert, /ActiveEcuC/KeyM, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCertRef] */
  /*     3 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCsrRef] */
  /*     4 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuPeerCertRef] */
  /*     5 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert:KeyMCertUpperHierarchicalCertRef] */
  /*     6 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert:KeyMCertUpperHierarchicalCertRef] */
  /*     7 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert:KeyMCertUpperHierarchicalCertRef] */

#define KEYM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_Cert_StorageType
**********************************************************************************************************************/
/** 
  \var    KeyM_Cert_StorageType
  \brief  Storage type of certificate
*/ 
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(tKeyMCertStorageType, KEYM_VAR_NO_INIT) KeyM_Cert_StorageType[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert:KeyMCertUpperHierarchicalCertRef] */
  /*     1 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert:KeyMCertUpperHierarchicalCertRef] */
  /*     2 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert, /ActiveEcuC/KeyM, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCertRef] */
  /*     3 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCsrRef] */
  /*     4 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuPeerCertRef] */
  /*     5 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert:KeyMCertUpperHierarchicalCertRef] */
  /*     6 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert:KeyMCertUpperHierarchicalCertRef] */
  /*     7 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert:KeyMCertUpperHierarchicalCertRef] */

#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_Cert_VerifyChain
**********************************************************************************************************************/
/** 
  \var    KeyM_Cert_VerifyChain
  \brief  Buffer for certificates to be verified
*/ 
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(KeyM_CertificateIdType, KEYM_VAR_NO_INIT) KeyM_Cert_VerifyChain[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert:KeyMCertUpperHierarchicalCertRef] */
  /*     1 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert:KeyMCertUpperHierarchicalCertRef] */
  /*     2 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert, /ActiveEcuC/KeyM, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCertRef] */
  /*     3 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCsrRef] */
  /*     4 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuPeerCertRef] */
  /*     5 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert:KeyMCertUpperHierarchicalCertRef] */
  /*     6 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert:KeyMCertUpperHierarchicalCertRef] */
  /*     7 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert:KeyMCertUpperHierarchicalCertRef] */

#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_CommonCertData
**********************************************************************************************************************/
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(KeyM_CommonCertDataUType, KEYM_VAR_NO_INIT) KeyM_CommonCertData;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     1 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*     2 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*     3 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*     4 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*     5 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*     6 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*     7 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */

#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  KeyM_ElementStorageRef
**********************************************************************************************************************/
#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(KeyM_Ans1_Element_Ref_Type, KEYM_VAR_NO_INIT) KeyM_ElementStorageRef[134];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/Version_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     1 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/SerialNo_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     2 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/SigAlgoId_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     3 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/Issuer_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     4 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/validityNotBefore_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     5 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/validityNotAfter_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     6 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/subject_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     7 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/SubjectPublicKeyInfoAlgo_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     8 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/SubjectPublicKeyInfoKey_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*     9 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/ext_subKeyId_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    10 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/ext_authKeyId_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    11 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/ext_basicConstraints_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    12 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/ext_keyUsage_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    13 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/ext_pkiRole_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    14 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/signatureAlgorithm_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    15 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendCert/signatureValue_002, /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert] */
  /*    16 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/Version_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    17 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/SerialNo_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    18 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/SigAlgoId_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    19 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/Issuer_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    20 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/validityNotBefore_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    21 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/validityNotAfter_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    22 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/subject_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    23 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/SubjectPublicKeyInfoAlgo_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    24 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/SubjectPublicKeyInfoKey_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    25 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/ext_subKeyId_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    26 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/ext_authKeyId_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    27 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/ext_basicConstraints_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    28 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/ext_keyUsage_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    29 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/ext_pkiRole_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    30 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/signatureAlgorithm_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    31 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert/signatureValue_004, /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert] */
  /*    32 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/Version_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    33 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/SerialNo_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    34 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/SigAlgoId_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    35 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/Issuer_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    36 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/validityNotBefore_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    37 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/validityNotAfter_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    38 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/subject_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    39 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/SubjectPublicKeyInfoAlgo_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    40 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/SubjectPublicKeyInfoKey_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    41 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/ext_keyUsage_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    42 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/ext_subKeyId_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    43 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/ext_authKeyId_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    44 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/ext_pkiRole_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    45 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/ext_uniqueECUID_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    46 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/ext_specialEcu_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    47 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/signatureAlgorithm_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    48 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCert/signatureValue_005, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert] */
  /*    49 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/Version_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /* Index        Referable Keys */
  /*    50 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/SerialNo_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    51 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/SigAlgoId_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    52 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/Issuer_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    53 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/validityNotBefore_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    54 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/validityNotAfter_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    55 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/subject_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCsrCertElemCommonNameRef] */
  /*    56 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/SubjectPublicKeyInfoAlgo_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    57 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/SubjectPublicKeyInfoKey_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    58 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_subKeyId_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    59 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_authKeyId_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    60 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_keyUsage_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    61 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_extKeyUsage_007, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    62 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_extKeyUsage_oid1_007, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    63 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_extKeyUsage_oid2_007, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    64 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_extKeyUsage_oid3_007, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    65 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_pkiRole_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    66 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_uniqueECUID_007, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCsrCertElemUniqueEcuIdRef] */
  /*    67 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/ext_specialEcu_007, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr, /ActiveEcuC/Ssa/SsaKeyM:SsaKeyMTrustModelEcuCsrCertElemSpecialEcuRef] */
  /*    68 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/signatureAlgorithm_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    69 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr/signatureValue_008, /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr] */
  /*    70 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/Version_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    71 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/SerialNo_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    72 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/SigAlgoId_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    73 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/Issuer_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    74 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/validityNotBefore_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    75 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/validityNotAfter_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    76 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/subject_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    77 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/SubjectPublicKeyInfoAlgo_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    78 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/SubjectPublicKeyInfoKey_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    79 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/ext_keyUsage_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    80 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/ext_subKeyId_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    81 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/ext_authKeyId_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    82 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/ext_specialEcu_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    83 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/ext_uniqueECUID_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    84 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/signatureAlgorithm_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    85 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert/signatureValue_006, /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert] */
  /*    86 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/Version_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*    87 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/SerialNo_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*    88 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/SigAlgoId_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*    89 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/Issuer_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*    90 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/validityNotBefore_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*    91 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/validityNotAfter_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*    92 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/subject_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*    93 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/SubjectPublicKeyInfoAlgo_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*    94 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/SubjectPublicKeyInfoKey_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*    95 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/ext_subKeyId_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*    96 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/ext_authKeyId_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*    97 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/ext_basicConstraints_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*    98 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/ext_keyUsage_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*    99 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/ext_pkiRole_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /* Index        Referable Keys */
  /*   100 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/signatureAlgorithm_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   101 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert/signatureValue_003, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert] */
  /*   102 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/Version_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   103 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/SerialNo_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   104 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/SigAlgoId_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   105 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/Issuer_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   106 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/validityNotBefore_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   107 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/validityNotAfter_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   108 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/subject_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   109 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/SubjectPublicKeyInfoAlgo_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   110 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/SubjectPublicKeyInfoKey_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   111 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/ext_subKeyId_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   112 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/ext_authKeyId_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   113 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/ext_basicConstraints_005, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   114 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/ext_keyUsage_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   115 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/ext_pkiRole_005, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   116 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/signatureAlgorithm_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   117 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert/signatureValue_007, /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert] */
  /*   118 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/Version, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   119 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/SerialNo, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   120 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/SigAlgoId, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   121 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/Issuer, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   122 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/validityNotBefore, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   123 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/validityNotAfter, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   124 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/subject, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   125 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/SubjectPublicKeyInfoAlgo, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   126 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/SubjectPublicKeyInfoKey, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   127 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/ext_subKeyId, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   128 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/ext_basicConstraints, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   129 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/ext_keyUsage, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   130 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/ext_authKeyId_009, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   131 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/ext_pkiRole, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   132 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/signatureAlgorithm, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */
  /*   133 */  /* [/ActiveEcuC/KeyM/Ssa_TrustModelRootCert/signatureValue, /ActiveEcuC/KeyM/Ssa_TrustModelRootCert] */

#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
/**********************************************************************************************************************
 *  Function Group GetCertificate
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_GetCertificate_Ssa_TrustModelEcuCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetCertificate_Ssa_TrustModelEcuCert(KeyM_CertificateIdType CertId, P2VAR(KeyM_CertificateType_Ssa_TrustModelEcuCert, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  Std_ReturnType retVal;
  KeyM_CertDataType certData;
  certData.certData = (KeyM_CertDataPointerType)CertificateDataPtr->certData;
  certData.certDataLength = sizeof(KeyM_CertificateDataType_Ssa_TrustModelEcuCert);
  retVal =  KeyM_GetCertificate(CertId, &certData);
  CertificateDataPtr->certDataLength = certData.certDataLength;
  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_GetCertificate_Ssa_TrustModelIntermediateCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetCertificate_Ssa_TrustModelIntermediateCert(KeyM_CertificateIdType CertId, P2VAR(KeyM_CertificateType_Ssa_TrustModelIntermediateCert, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  Std_ReturnType retVal;
  KeyM_CertDataType certData;
  certData.certData = (KeyM_CertDataPointerType)CertificateDataPtr->certData;
  certData.certDataLength = sizeof(KeyM_CertificateDataType_Ssa_TrustModelIntermediateCert);
  retVal =  KeyM_GetCertificate(CertId, &certData);
  CertificateDataPtr->certDataLength = certData.certDataLength;
  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_GetCertificate_Ssa_TrustModelBackendCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetCertificate_Ssa_TrustModelBackendCert(KeyM_CertificateIdType CertId, P2VAR(KeyM_CertificateType_Ssa_TrustModelBackendCert, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  Std_ReturnType retVal;
  KeyM_CertDataType certData;
  certData.certData = (KeyM_CertDataPointerType)CertificateDataPtr->certData;
  certData.certDataLength = sizeof(KeyM_CertificateDataType_Ssa_TrustModelBackendCert);
  retVal =  KeyM_GetCertificate(CertId, &certData);
  CertificateDataPtr->certDataLength = certData.certDataLength;
  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_GetCertificate_Ssa_TrustModelRootCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetCertificate_Ssa_TrustModelRootCert(KeyM_CertificateIdType CertId, P2VAR(KeyM_CertificateType_Ssa_TrustModelRootCert, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  Std_ReturnType retVal;
  KeyM_CertDataType certData;
  certData.certData = (KeyM_CertDataPointerType)CertificateDataPtr->certData;
  certData.certDataLength = sizeof(KeyM_CertificateDataType_Ssa_TrustModelRootCert);
  retVal =  KeyM_GetCertificate(CertId, &certData);
  CertificateDataPtr->certDataLength = certData.certDataLength;
  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_GetCertificate_Ssa_TrustModelEcuPeerCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetCertificate_Ssa_TrustModelEcuPeerCert(KeyM_CertificateIdType CertId, P2VAR(KeyM_CertificateType_Ssa_TrustModelEcuPeerCert, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  Std_ReturnType retVal;
  KeyM_CertDataType certData;
  certData.certData = (KeyM_CertDataPointerType)CertificateDataPtr->certData;
  certData.certDataLength = sizeof(KeyM_CertificateDataType_Ssa_TrustModelEcuPeerCert);
  retVal =  KeyM_GetCertificate(CertId, &certData);
  CertificateDataPtr->certDataLength = certData.certDataLength;
  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_GetCertificate_Ssa_TrustModelBackendPeerCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetCertificate_Ssa_TrustModelBackendPeerCert(KeyM_CertificateIdType CertId, P2VAR(KeyM_CertificateType_Ssa_TrustModelBackendPeerCert, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  Std_ReturnType retVal;
  KeyM_CertDataType certData;
  certData.certData = (KeyM_CertDataPointerType)CertificateDataPtr->certData;
  certData.certDataLength = sizeof(KeyM_CertificateDataType_Ssa_TrustModelBackendPeerCert);
  retVal =  KeyM_GetCertificate(CertId, &certData);
  CertificateDataPtr->certDataLength = certData.certDataLength;
  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_GetCertificate_Ssa_TrustModelIntermediatePeerCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetCertificate_Ssa_TrustModelIntermediatePeerCert(KeyM_CertificateIdType CertId, P2VAR(KeyM_CertificateType_Ssa_TrustModelIntermediatePeerCert, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  Std_ReturnType retVal;
  KeyM_CertDataType certData;
  certData.certData = (KeyM_CertDataPointerType)CertificateDataPtr->certData;
  certData.certDataLength = sizeof(KeyM_CertificateDataType_Ssa_TrustModelIntermediatePeerCert);
  retVal =  KeyM_GetCertificate(CertId, &certData);
  CertificateDataPtr->certDataLength = certData.certDataLength;
  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_GetCertificate_Ssa_TrustModelEcuCsr
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetCertificate_Ssa_TrustModelEcuCsr(KeyM_CertificateIdType CertId, P2VAR(KeyM_CertificateType_Ssa_TrustModelEcuCsr, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  Std_ReturnType retVal;
  KeyM_CertDataType certData;
  certData.certData = (KeyM_CertDataPointerType)CertificateDataPtr->certData;
  certData.certDataLength = sizeof(KeyM_CertificateDataType_Ssa_TrustModelEcuCsr);
  retVal =  KeyM_GetCertificate(CertId, &certData);
  CertificateDataPtr->certDataLength = certData.certDataLength;
  return retVal;
}

/**********************************************************************************************************************
 *  Function Group SetCertificate
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_SetCertificate_Ssa_TrustModelEcuCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificate_Ssa_TrustModelEcuCert(KeyM_CertificateIdType CertId, P2CONST(KeyM_CertificateType_Ssa_TrustModelEcuCert, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
    return KeyM_Cert_SetCertificateRteWrapper(CertId, CertificateDataPtr->certData, CertificateDataPtr->certDataLength);
}

/**********************************************************************************************************************
 *  KeyM_SetCertificate_Ssa_TrustModelIntermediateCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificate_Ssa_TrustModelIntermediateCert(KeyM_CertificateIdType CertId, P2CONST(KeyM_CertificateType_Ssa_TrustModelIntermediateCert, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
    return KeyM_Cert_SetCertificateRteWrapper(CertId, CertificateDataPtr->certData, CertificateDataPtr->certDataLength);
}

/**********************************************************************************************************************
 *  KeyM_SetCertificate_Ssa_TrustModelBackendCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificate_Ssa_TrustModelBackendCert(KeyM_CertificateIdType CertId, P2CONST(KeyM_CertificateType_Ssa_TrustModelBackendCert, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
    return KeyM_Cert_SetCertificateRteWrapper(CertId, CertificateDataPtr->certData, CertificateDataPtr->certDataLength);
}

/**********************************************************************************************************************
 *  KeyM_SetCertificate_Ssa_TrustModelRootCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificate_Ssa_TrustModelRootCert(KeyM_CertificateIdType CertId, P2CONST(KeyM_CertificateType_Ssa_TrustModelRootCert, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
    return KeyM_Cert_SetCertificateRteWrapper(CertId, CertificateDataPtr->certData, CertificateDataPtr->certDataLength);
}

/**********************************************************************************************************************
 *  KeyM_SetCertificate_Ssa_TrustModelEcuPeerCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificate_Ssa_TrustModelEcuPeerCert(KeyM_CertificateIdType CertId, P2CONST(KeyM_CertificateType_Ssa_TrustModelEcuPeerCert, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
    return KeyM_Cert_SetCertificateRteWrapper(CertId, CertificateDataPtr->certData, CertificateDataPtr->certDataLength);
}

/**********************************************************************************************************************
 *  KeyM_SetCertificate_Ssa_TrustModelBackendPeerCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificate_Ssa_TrustModelBackendPeerCert(KeyM_CertificateIdType CertId, P2CONST(KeyM_CertificateType_Ssa_TrustModelBackendPeerCert, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
    return KeyM_Cert_SetCertificateRteWrapper(CertId, CertificateDataPtr->certData, CertificateDataPtr->certDataLength);
}

/**********************************************************************************************************************
 *  KeyM_SetCertificate_Ssa_TrustModelIntermediatePeerCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificate_Ssa_TrustModelIntermediatePeerCert(KeyM_CertificateIdType CertId, P2CONST(KeyM_CertificateType_Ssa_TrustModelIntermediatePeerCert, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
    return KeyM_Cert_SetCertificateRteWrapper(CertId, CertificateDataPtr->certData, CertificateDataPtr->certDataLength);
}

/**********************************************************************************************************************
 *  KeyM_SetCertificate_Ssa_TrustModelEcuCsr
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificate_Ssa_TrustModelEcuCsr(KeyM_CertificateIdType CertId, P2CONST(KeyM_CertificateType_Ssa_TrustModelEcuCsr, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
    return KeyM_Cert_SetCertificateRteWrapper(CertId, CertificateDataPtr->certData, CertificateDataPtr->certDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_authKeyId_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_authKeyId_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_authKeyId_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_authKeyId_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_authKeyId_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_authKeyId_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_authKeyId_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_authKeyId_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_subKeyId_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_subKeyId_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_subKeyId_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_subKeyId_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_subKeyId_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_subKeyId_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_subKeyId_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_subKeyId_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_keyUsage_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_keyUsage_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_keyUsage_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_keyUsage_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_keyUsage_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_keyUsage_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_keyUsage_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_keyUsage_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_pkiRole_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_pkiRole_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_pkiRole_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_pkiRole_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_pkiRole_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_pkiRole_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_pkiRole_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_pkiRole_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_Version_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_Version_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_Version_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Version_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_Version_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_Version_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_Version_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Version_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_SerialNo_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_SerialNo_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_SerialNo_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SerialNo_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SerialNo_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SerialNo_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SerialNo_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SerialNo_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_SigAlgoId_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_SigAlgoId_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_SigAlgoId_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SigAlgoId_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SigAlgoId_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SigAlgoId_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SigAlgoId_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SigAlgoId_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_validityNotBefore_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_validityNotBefore_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_validityNotBefore_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotBefore_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_validityNotBefore_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_validityNotBefore_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_validityNotBefore_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotBefore_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_validityNotAfter_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_validityNotAfter_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_validityNotAfter_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotAfter_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_validityNotAfter_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_validityNotAfter_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_validityNotAfter_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotAfter_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_subject_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_subject_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_subject_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_subject_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_subject_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_subject_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_subject_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_subject_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_Issuer_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_Issuer_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_Issuer_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Issuer_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_Issuer_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_Issuer_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_Issuer_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Issuer_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_signatureAlgorithm_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_signatureAlgorithm_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_signatureAlgorithm_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureAlgorithm_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_signatureAlgorithm_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_signatureAlgorithm_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_signatureAlgorithm_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureAlgorithm_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_signatureValue_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_signatureValue_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_signatureValue_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureValue_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_signatureValue_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_signatureValue_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_signatureValue_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureValue_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_uniqueECUID_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_uniqueECUID_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_uniqueECUID_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_uniqueECUID_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_uniqueECUID_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_uniqueECUID_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_uniqueECUID_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_uniqueECUID_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_specialEcu_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_specialEcu_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_specialEcu_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_specialEcu_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_specialEcu_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_specialEcu_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_specialEcu_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_specialEcu_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_authKeyId_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_authKeyId_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_authKeyId_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_authKeyId_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_authKeyId_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_authKeyId_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_authKeyId_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_authKeyId_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_subKeyId_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_subKeyId_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_subKeyId_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_subKeyId_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_subKeyId_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_subKeyId_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_subKeyId_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_subKeyId_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_keyUsage_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_keyUsage_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_keyUsage_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_keyUsage_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_keyUsage_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_keyUsage_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_keyUsage_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_keyUsage_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_pkiRole_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_pkiRole_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_pkiRole_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_pkiRole_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_pkiRole_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_pkiRole_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_pkiRole_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_pkiRole_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_Version_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_Version_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_Version_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Version_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_Version_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_Version_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_Version_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Version_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SerialNo_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SerialNo_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SerialNo_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SerialNo_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SerialNo_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SerialNo_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SerialNo_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SerialNo_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SigAlgoId_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SigAlgoId_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SigAlgoId_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SigAlgoId_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SigAlgoId_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SigAlgoId_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SigAlgoId_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SigAlgoId_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_validityNotBefore_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_validityNotBefore_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_validityNotBefore_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotBefore_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_validityNotBefore_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_validityNotBefore_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_validityNotBefore_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotBefore_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_validityNotAfter_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_validityNotAfter_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_validityNotAfter_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotAfter_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_validityNotAfter_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_validityNotAfter_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_validityNotAfter_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotAfter_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_subject_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_subject_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_subject_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_subject_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_subject_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_subject_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_subject_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_subject_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_Issuer_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_Issuer_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_Issuer_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Issuer_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_Issuer_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_Issuer_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_Issuer_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Issuer_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_signatureValue_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_signatureValue_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_signatureValue_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureValue_003);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_signatureValue_003
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_signatureValue_003
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_signatureValue_003(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureValue_003);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_authKeyId_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_authKeyId_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_authKeyId_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_authKeyId_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_authKeyId_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_authKeyId_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_authKeyId_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_authKeyId_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_subKeyId_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_subKeyId_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_subKeyId_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_subKeyId_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_subKeyId_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_subKeyId_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_subKeyId_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_subKeyId_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_basicConstraints_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_basicConstraints_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_basicConstraints_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_basicConstraints_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_basicConstraints_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_basicConstraints_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_basicConstraints_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_basicConstraints_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_keyUsage_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_keyUsage_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_keyUsage_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_keyUsage_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_keyUsage_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_keyUsage_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_keyUsage_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_keyUsage_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_pkiRole_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_pkiRole_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_pkiRole_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_pkiRole_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_pkiRole_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_pkiRole_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_pkiRole_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_pkiRole_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_Version_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_Version_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_Version_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Version_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_Version_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_Version_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_Version_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Version_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_SerialNo_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_SerialNo_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_SerialNo_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SerialNo_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SerialNo_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SerialNo_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SerialNo_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SerialNo_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_SigAlgoId_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_SigAlgoId_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_SigAlgoId_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SigAlgoId_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SigAlgoId_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SigAlgoId_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SigAlgoId_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SigAlgoId_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_validityNotBefore_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_validityNotBefore_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_validityNotBefore_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotBefore_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_validityNotBefore_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_validityNotBefore_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_validityNotBefore_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotBefore_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_validityNotAfter_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_validityNotAfter_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_validityNotAfter_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotAfter_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_validityNotAfter_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_validityNotAfter_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_validityNotAfter_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotAfter_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_subject_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_subject_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_subject_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_subject_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_subject_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_subject_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_subject_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_subject_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_Issuer_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_Issuer_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_Issuer_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Issuer_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_Issuer_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_Issuer_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_Issuer_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Issuer_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_signatureAlgorithm_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_signatureAlgorithm_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_signatureAlgorithm_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureAlgorithm_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_signatureAlgorithm_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_signatureAlgorithm_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_signatureAlgorithm_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureAlgorithm_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendCert_signatureValue_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_signatureValue_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendCert_signatureValue_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureValue_002);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_signatureValue_002
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_signatureValue_002
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_signatureValue_002(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureValue_002);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_authKeyId_009
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_authKeyId_009
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_authKeyId_009(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_authKeyId_009);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_authKeyId_009
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_authKeyId_009
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_authKeyId_009(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_authKeyId_009);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_Version
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_Version
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_Version(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Version);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_Version
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_Version
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_Version(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Version);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_SerialNo
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_SerialNo
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_SerialNo(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SerialNo);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SerialNo
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SerialNo
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SerialNo(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SerialNo);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_SigAlgoId
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_SigAlgoId
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_SigAlgoId(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SigAlgoId);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SigAlgoId
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SigAlgoId
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SigAlgoId(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SigAlgoId);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_validityNotBefore
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_validityNotBefore
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_validityNotBefore(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotBefore);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_validityNotBefore
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_validityNotBefore
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_validityNotBefore(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotBefore);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_validityNotAfter
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_validityNotAfter
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_validityNotAfter(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotAfter);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_validityNotAfter
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_validityNotAfter
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_validityNotAfter(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotAfter);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_subject
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_subject
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_subject(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_subject);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_subject
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_subject
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_subject(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_subject);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_Issuer
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_Issuer
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_Issuer(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Issuer);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_Issuer
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_Issuer
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_Issuer(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Issuer);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_signatureAlgorithm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_signatureAlgorithm
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_signatureAlgorithm(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureAlgorithm);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_signatureAlgorithm
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_signatureAlgorithm
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_signatureAlgorithm(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureAlgorithm);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_signatureValue
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_signatureValue
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_signatureValue(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureValue);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_signatureValue
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_signatureValue
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_signatureValue(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureValue);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_subKeyId
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_subKeyId
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_subKeyId(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_subKeyId);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_subKeyId
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_subKeyId
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_subKeyId(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_subKeyId);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_basicConstraints
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_basicConstraints
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_basicConstraints(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_basicConstraints);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_basicConstraints
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_basicConstraints
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_basicConstraints(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_basicConstraints);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_keyUsage
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_keyUsage
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_keyUsage(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_keyUsage);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_keyUsage
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_keyUsage
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_keyUsage(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_keyUsage);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_pkiRole
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_pkiRole
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_pkiRole(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_pkiRole);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_pkiRole
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_pkiRole
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_pkiRole(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_pkiRole);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_Version_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_Version_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_Version_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Version_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_Version_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_Version_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_Version_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Version_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SerialNo_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SerialNo_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SerialNo_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SerialNo_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SerialNo_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SerialNo_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SerialNo_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SerialNo_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SigAlgoId_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SigAlgoId_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SigAlgoId_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SigAlgoId_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SigAlgoId_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SigAlgoId_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SigAlgoId_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SigAlgoId_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_validityNotBefore_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_validityNotBefore_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_validityNotBefore_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotBefore_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_validityNotBefore_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_validityNotBefore_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_validityNotBefore_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotBefore_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_validityNotAfter_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_validityNotAfter_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_validityNotAfter_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotAfter_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_validityNotAfter_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_validityNotAfter_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_validityNotAfter_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotAfter_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_subject_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_subject_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_subject_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_subject_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_subject_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_subject_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_subject_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_subject_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_Issuer_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_Issuer_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_Issuer_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Issuer_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_Issuer_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_Issuer_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_Issuer_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Issuer_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_signatureValue_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_signatureValue_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_signatureValue_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureValue_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_signatureValue_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_signatureValue_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_signatureValue_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureValue_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_Version_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_Version_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_Version_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Version_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_Version_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_Version_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_Version_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Version_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SerialNo_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SerialNo_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SerialNo_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SerialNo_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SerialNo_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SerialNo_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SerialNo_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SerialNo_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SigAlgoId_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SigAlgoId_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SigAlgoId_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SigAlgoId_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SigAlgoId_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SigAlgoId_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SigAlgoId_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SigAlgoId_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_validityNotBefore_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_validityNotBefore_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_validityNotBefore_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotBefore_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_validityNotBefore_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_validityNotBefore_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_validityNotBefore_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotBefore_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_validityNotAfter_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_validityNotAfter_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_validityNotAfter_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotAfter_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_validityNotAfter_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_validityNotAfter_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_validityNotAfter_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotAfter_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_subject_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_subject_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_subject_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_subject_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_subject_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_subject_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_subject_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_subject_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_Issuer_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_Issuer_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_Issuer_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Issuer_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_Issuer_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_Issuer_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_Issuer_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Issuer_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_signatureValue_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_signatureValue_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_signatureValue_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureValue_004);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_signatureValue_004
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_signatureValue_004
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_signatureValue_004(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureValue_004);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_Version_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_Version_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_Version_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Version_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_Version_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_Version_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_Version_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Version_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SerialNo_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SerialNo_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SerialNo_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SerialNo_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SerialNo_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SerialNo_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SerialNo_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SerialNo_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_subject_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_subject_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_subject_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_subject_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_subject_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_subject_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_subject_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_subject_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_Issuer_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_Issuer_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_Issuer_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Issuer_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_Issuer_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_Issuer_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_Issuer_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Issuer_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_signatureValue_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_signatureValue_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_signatureValue_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureValue_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_signatureValue_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_signatureValue_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_signatureValue_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureValue_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_authKeyId_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_authKeyId_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_authKeyId_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_authKeyId_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_authKeyId_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_authKeyId_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_authKeyId_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_authKeyId_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_subKeyId_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_subKeyId_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_subKeyId_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_subKeyId_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_subKeyId_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_subKeyId_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_subKeyId_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_subKeyId_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_keyUsage_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_keyUsage_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_keyUsage_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_keyUsage_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_keyUsage_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_keyUsage_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_keyUsage_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_keyUsage_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_pkiRole_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_pkiRole_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_pkiRole_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_pkiRole_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_pkiRole_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_pkiRole_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_pkiRole_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_pkiRole_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_Version_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_Version_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_Version_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Version_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_Version_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_Version_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_Version_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Version_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SerialNo_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SerialNo_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SerialNo_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SerialNo_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SerialNo_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SerialNo_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SerialNo_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SerialNo_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SigAlgoId_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SigAlgoId_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SigAlgoId_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SigAlgoId_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SigAlgoId_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SigAlgoId_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SigAlgoId_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SigAlgoId_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_validityNotBefore_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_validityNotBefore_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_validityNotBefore_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotBefore_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_validityNotBefore_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_validityNotBefore_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_validityNotBefore_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotBefore_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_validityNotAfter_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_validityNotAfter_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_validityNotAfter_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotAfter_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_validityNotAfter_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_validityNotAfter_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_validityNotAfter_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotAfter_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_subject_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_subject_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_subject_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_subject_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_subject_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_subject_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_subject_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_subject_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_Issuer_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_Issuer_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_Issuer_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Issuer_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_Issuer_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_Issuer_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_Issuer_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Issuer_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_signatureAlgorithm_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_signatureAlgorithm_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_signatureAlgorithm_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureAlgorithm_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_signatureAlgorithm_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_signatureAlgorithm_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_signatureAlgorithm_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureAlgorithm_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_signatureValue_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_signatureValue_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_signatureValue_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureValue_008);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_signatureValue_008
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_signatureValue_008
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_signatureValue_008(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureValue_008);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_specialEcu_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_specialEcu_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_specialEcu_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_specialEcu_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_specialEcu_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_specialEcu_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_specialEcu_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_specialEcu_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007);
  return KeyM_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
}

/**********************************************************************************************************************
 *  Function Group KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint16 Index, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)  /* PRQA S 1330 */ /* MD_KEYM_CFG_SWC_1330 */
{
  *CertElementDataLength = sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007);
  return KeyM_CertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
}

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
 *  END OF FILE: KeyM_Cfg.c
 *********************************************************************************************************************/
