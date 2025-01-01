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
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: KeyM_Cfg.c
 *   Generation Time: 2022-09-22 10:43:14
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
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
  Element                                Description
  CertCsmSignatureVerifyJobRef           Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureVerifyJobRef.
  CertCsmSignatureVerifyKeyRef           Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureVerifyKeyRef.
  CsmKeyTargetRef                        Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateCsmKeyTargetRef.
  CertStorageLength                      the number of relations pointing to KeyM_CertStorage
  CertStorageStartIdx                    the start index of the 0:n relation pointing to KeyM_CertStorage
  CertAlgorithmFamily                    Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertAlgorithmFamily.
  CertFormatType                         Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertFormatType.
  CertStartUpHandling                    Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertStartUpHandling.
  CertStorageWrittenLengthLength         the number of relations pointing to KeyM_CertStorage
  CertUpperHierarchicalType              Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertUpperHierarchicalType.
  CertificateElementEndIdx               the end index of the 0:n relation pointing to KeyM_CertificateElement
  CertificateElementStartIdx             the start index of the 0:n relation pointing to KeyM_CertificateElement
  CertificateGetCurrentTimeCalloutIdx    the index of the 0:1 relation pointing to KeyM_CertificateGetCurrentTimeCallout
  CertificateNameStartIdx                the start index of the 1:n relation pointing to KeyM_CertificateName
  Storage                                Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateStorage.
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(KeyM_CertificateType, KEYM_CONST) KeyM_Certificate[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CertCsmSignatureVerifyJobRef                 CertCsmSignatureVerifyKeyRef                 CsmKeyTargetRef                               CertStorageLength  CertStorageStartIdx  CertAlgorithmFamily  CertFormatType  CertStartUpHandling  CertStorageWrittenLengthLength  CertUpperHierarchicalType  CertificateElementEndIdx  CertificateElementStartIdx  CertificateGetCurrentTimeCalloutIdx  CertificateNameStartIdx  Storage                    Referable Keys */
  { /*     0 */ CsmConf_CsmJob_CsmJob_KeyM_ECC_Root        , CsmConf_CsmKey_CsmKey_KeyM_ECC_Root        , CsmConf_CsmKey_CsmKey_KeyM_Cert_Root        ,              600u,                  4u, KEYM_ECDSA         , KEYM_X509     , KEYM_NONE          ,                             2u, KEYM_PRESET_ISSUER       ,                      23u,                         0u,                                  0u,                      0u, KEYM_STORAGE_IN_CSM },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA, /ActiveEcuC/KeyM, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA:KeyMCertUpperHierarchicalCertRef, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA:KeyMCertUpperHierarchicalCertRef] */
  { /*     1 */ CsmConf_CsmJob_CsmJob_KeyM_ECC_Intermediate, CsmConf_CsmKey_CsmKey_KeyM_ECC_Intermediate, CsmConf_CsmKey_CsmKey_KeyM_Cert_Intermediate,              600u,                608u, KEYM_ECDSA         , KEYM_X509     , KEYM_NONE          ,                             2u, KEYM_PRESET_ISSUER       ,                      45u,                        23u,                                  0u,                     39u, KEYM_STORAGE_IN_CSM }   /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA, /ActiveEcuC/KeyM] */
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
  Element               Description
  ElementOidEndIdx      the end index of the 0:n relation pointing to KeyM_ElementOid
  ElementOidStartIdx    the start index of the 0:n relation pointing to KeyM_ElementOid
  Id                    Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId.
  MaskedBits            contains bitcoded the boolean data of KeyM_HasIterationOfCertificateElement, KeyM_OptionalOfCertificateElement
  MaxLength             Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementMaxLength.
  ObjectType            Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementObjectType.
  OfStructure           Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementOfStructure.
*/ 
#define KEYM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(KeyM_CertificateElementType, KEYM_CONST) KeyM_CertificateElement[45] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ElementOidEndIdx                              ElementOidStartIdx                              Id   MaskedBits  MaxLength  ObjectType  OfStructure                                                          Referable Keys */
  { /*     0 */ KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  0u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_VERSION_NUMBER                               },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Version_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*     1 */ KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  1u,      0x00u,       16u,         2u, KEYM_CERTIFICATE_SERIAL_NUMBER                                },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/SerialNo_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*     2 */                                           8u,                                             0u,  2u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID                       },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/SigAlgoId_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*     3 */                                          11u,                                             8u,  3u,      0x00u,       10u,        19u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Issuer_CountryName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*     4 */                                          14u,                                            11u,  4u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Issuer_StateOrProvinceName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*     5 */                                          17u,                                            14u,  5u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Issuer_LocalityName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*     6 */                                          20u,                                            17u,  6u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Issuer_OrganizationName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*     7 */                                          23u,                                            20u,  7u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Issuer_CommonName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*     8 */ KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  8u,      0x00u,        1u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE                   },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/validityNotBefore_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*     9 */ KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  9u,      0x00u,        1u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER                    },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/validityNotAfter_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    10 */                                          11u,                                             8u, 10u,      0x00u,       10u,        19u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Subject_CountryName_004, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    11 */                                          14u,                                            11u, 11u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Subject_StateOrProvinceName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    12 */                                          17u,                                            14u, 12u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Subject_LocalityName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    13 */                                          20u,                                            17u, 13u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Subject_OrganizationName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    14 */                                          23u,                                            20u, 14u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Subject_CommonName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    15 */                                          30u,                                            23u, 15u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/SubjectPublicKeyInfoAlgo_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    16 */                                          35u,                                            30u, 16u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/SubjectPublicKeyInfoAlgo_Curve_004, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    17 */ KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT, 17u,      0x00u,       32u,         3u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY   },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/SubjectPublicKeyInfoKey_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    18 */                                          41u,                                            38u, 18u,      0x00u,        1u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/ext1_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    19 */                                          44u,                                            41u, 19u,      0x00u,        1u,       128u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/ext2_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    20 */                                          38u,                                            35u, 20u,      0x00u,       20u,         6u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/ext3_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    21 */                                           8u,                                             0u, 21u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM                          },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/signatureAlgorithm_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    22 */ KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT, 22u,      0x02u,       64u,         2u, KEYM_CERTIFICATE_SIGNATURE                                    },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/signatureValue_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*    23 */ KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  0u,      0x00u,        1u,         2u, KEYM_CERTIFICATE_VERSION_NUMBER                               },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Version_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    24 */ KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  1u,      0x00u,       16u,         2u, KEYM_CERTIFICATE_SERIAL_NUMBER                                },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/SerialNo_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    25 */                                           8u,                                             0u,  2u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID                       },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/SigAlgoId_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    26 */                                          11u,                                             8u,  3u,      0x00u,       10u,        19u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Issuer_CountryName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    27 */                                          14u,                                            11u,  4u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Issuer_StateOrProvinceName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    28 */                                          17u,                                            14u,  5u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Issuer_LocalityName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    29 */                                          20u,                                            17u,  6u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Issuer_OrganizationName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    30 */                                          23u,                                            20u,  7u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_ISSUER_NAME                                  },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Issuer_CommonName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    31 */ KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  8u,      0x00u,        1u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE                   },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/validityNotBefore_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    32 */ KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT,  9u,      0x00u,        1u,        23u, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER                    },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/validityNotAfter_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    33 */                                          23u,                                            20u, 10u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Subject_CommonName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    34 */                                          14u,                                            11u, 11u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Subject_StateOrProvinceName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    35 */                                          11u,                                             8u, 12u,      0x00u,       10u,        19u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Subject_CountryName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    36 */                                          20u,                                            17u, 13u,      0x00u,       10u,        12u, KEYM_CERTIFICATE_SUBJECT_NAME                                 },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Subject_OrganizationName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    37 */                                          30u,                                            23u, 14u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/SubjectPublicKeyInfoAlgo_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    38 */                                          35u,                                            30u, 15u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/SubjectPublicKeyInfoAlgo_Curve_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    39 */ KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT, 16u,      0x00u,       32u,         3u, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY   },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/SubjectPublicKeyInfoKey_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    40 */                                          38u,                                            35u, 17u,      0x00u,       20u,         1u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/ext1_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    41 */                                          41u,                                            38u, 18u,      0x00u,        1u,         4u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/ext2_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    42 */                                          44u,                                            41u, 19u,      0x00u,        1u,       128u, KEYM_CERTIFICATE_EXTENSION                                    },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/ext3_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    43 */                                           8u,                                             0u, 20u,      0x00u,        1u,         6u, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM                          },  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/signatureAlgorithm_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*    44 */ KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT, KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT, 21u,      0x02u,       64u,         2u, KEYM_CERTIFICATE_SIGNATURE                                    }   /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/signatureValue_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
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
  /* Index     CertificateGetCurrentTimeCallout                   Referable Keys */
  /*     0 */ Appl_KeyMCertificateGetCurrentTimeCalloutFunc    /* [Appl_KeyMCertificateGetCurrentTimeCalloutFunc] */
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
CONST(KeyM_CertificateNameType, KEYM_CONST) KeyM_CertificateName[78] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CertificateName      Referable Keys */
  /*     0 */            0x4Bu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     1 */            0x65u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     2 */            0x79u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     3 */            0x4Du,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     4 */            0x43u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     5 */            0x65u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     6 */            0x72u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     7 */            0x74u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     8 */            0x69u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     9 */            0x66u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    10 */            0x69u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    11 */            0x63u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    12 */            0x61u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    13 */            0x74u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    14 */            0x65u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    15 */            0x5Fu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    16 */            0x4Fu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    17 */            0x53u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    18 */            0x53u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    19 */            0x4Cu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    20 */            0x5Fu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    21 */            0x58u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    22 */            0x35u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    23 */            0x30u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    24 */            0x39u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    25 */            0x5Fu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    26 */            0x45u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    27 */            0x43u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    28 */            0x44u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    29 */            0x53u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    30 */            0x41u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    31 */            0x5Fu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    32 */            0x50u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    33 */            0x33u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    34 */            0x38u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    35 */            0x34u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    36 */            0x5Fu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    37 */            0x43u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    38 */            0x41u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    39 */            0x4Bu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    40 */            0x65u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    41 */            0x79u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    42 */            0x4Du,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    43 */            0x43u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    44 */            0x65u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    45 */            0x72u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    46 */            0x74u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    47 */            0x69u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    48 */            0x66u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    49 */            0x69u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /* Index     CertificateName      Referable Keys */
  /*    50 */            0x63u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    51 */            0x61u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    52 */            0x74u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    53 */            0x65u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    54 */            0x5Fu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    55 */            0x4Fu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    56 */            0x53u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    57 */            0x53u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    58 */            0x4Cu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    59 */            0x5Fu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    60 */            0x58u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    61 */            0x35u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    62 */            0x30u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    63 */            0x39u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    64 */            0x5Fu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    65 */            0x45u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    66 */            0x43u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    67 */            0x44u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    68 */            0x53u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    69 */            0x41u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    70 */            0x5Fu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    71 */            0x50u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    72 */            0x33u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    73 */            0x38u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    74 */            0x34u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    75 */            0x5Fu,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    76 */            0x49u,  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    77 */            0x41u   /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
};
#define KEYM_STOP_SEC_CONST_8
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
CONST(KeyM_ElementOidType, KEYM_CONST) KeyM_ElementOid[44] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ElementOid      Comment                                Referable Keys */
  /*     0 */         42u,  /* [1.2.840.10045.4.3.4 | 1.2:0]   */  /* [1.2.840.10045.4.3.4] */
  /*     1 */        134u,  /* [1.2.840.10045.4.3.4 | 840:0]   */  /* [1.2.840.10045.4.3.4] */
  /*     2 */         72u,  /* [1.2.840.10045.4.3.4 | 840:1]   */  /* [1.2.840.10045.4.3.4] */
  /*     3 */        206u,  /* [1.2.840.10045.4.3.4 | 10045:0] */  /* [1.2.840.10045.4.3.4] */
  /*     4 */         61u,  /* [1.2.840.10045.4.3.4 | 10045:1] */  /* [1.2.840.10045.4.3.4] */
  /*     5 */          4u,  /* [1.2.840.10045.4.3.4 | 4:0]     */  /* [1.2.840.10045.4.3.4] */
  /*     6 */          3u,  /* [1.2.840.10045.4.3.4 | 3:0]     */  /* [1.2.840.10045.4.3.4] */
  /*     7 */          4u,  /* [1.2.840.10045.4.3.4 | 4:0]     */  /* [1.2.840.10045.4.3.4] */
  /*     8 */         85u,  /* [2.5.4.6 | 2.5:0]               */  /* [2.5.4.6] */
  /*     9 */          4u,  /* [2.5.4.6 | 4:0]                 */  /* [2.5.4.6] */
  /*    10 */          6u,  /* [2.5.4.6 | 6:0]                 */  /* [2.5.4.6] */
  /*    11 */         85u,  /* [2.5.4.8 | 2.5:0]               */  /* [2.5.4.8] */
  /*    12 */          4u,  /* [2.5.4.8 | 4:0]                 */  /* [2.5.4.8] */
  /*    13 */          8u,  /* [2.5.4.8 | 8:0]                 */  /* [2.5.4.8] */
  /*    14 */         85u,  /* [2.5.4.7 | 2.5:0]               */  /* [2.5.4.7] */
  /*    15 */          4u,  /* [2.5.4.7 | 4:0]                 */  /* [2.5.4.7] */
  /*    16 */          7u,  /* [2.5.4.7 | 7:0]                 */  /* [2.5.4.7] */
  /*    17 */         85u,  /* [2.5.4.10 | 2.5:0]              */  /* [2.5.4.10] */
  /*    18 */          4u,  /* [2.5.4.10 | 4:0]                */  /* [2.5.4.10] */
  /*    19 */         10u,  /* [2.5.4.10 | 10:0]               */  /* [2.5.4.10] */
  /*    20 */         85u,  /* [2.5.4.3 | 2.5:0]               */  /* [2.5.4.3] */
  /*    21 */          4u,  /* [2.5.4.3 | 4:0]                 */  /* [2.5.4.3] */
  /*    22 */          3u,  /* [2.5.4.3 | 3:0]                 */  /* [2.5.4.3] */
  /*    23 */         42u,  /* [1.2.840.10045.2.1 | 1.2:0]     */  /* [1.2.840.10045.2.1] */
  /*    24 */        134u,  /* [1.2.840.10045.2.1 | 840:0]     */  /* [1.2.840.10045.2.1] */
  /*    25 */         72u,  /* [1.2.840.10045.2.1 | 840:1]     */  /* [1.2.840.10045.2.1] */
  /*    26 */        206u,  /* [1.2.840.10045.2.1 | 10045:0]   */  /* [1.2.840.10045.2.1] */
  /*    27 */         61u,  /* [1.2.840.10045.2.1 | 10045:1]   */  /* [1.2.840.10045.2.1] */
  /*    28 */          2u,  /* [1.2.840.10045.2.1 | 2:0]       */  /* [1.2.840.10045.2.1] */
  /*    29 */          1u,  /* [1.2.840.10045.2.1 | 1:0]       */  /* [1.2.840.10045.2.1] */
  /*    30 */         43u,  /* [1.3.132.0.34 | 1.3:0]          */  /* [1.3.132.0.34] */
  /*    31 */        129u,  /* [1.3.132.0.34 | 132:0]          */  /* [1.3.132.0.34] */
  /*    32 */          4u,  /* [1.3.132.0.34 | 132:1]          */  /* [1.3.132.0.34] */
  /*    33 */          0u,  /* [1.3.132.0.34 | 0:0]            */  /* [1.3.132.0.34] */
  /*    34 */         34u,  /* [1.3.132.0.34 | 34:0]           */  /* [1.3.132.0.34] */
  /*    35 */         85u,  /* [2.5.29.19 | 2.5:0]             */  /* [2.5.29.19] */
  /*    36 */         29u,  /* [2.5.29.19 | 29:0]              */  /* [2.5.29.19] */
  /*    37 */         19u,  /* [2.5.29.19 | 19:0]              */  /* [2.5.29.19] */
  /*    38 */         85u,  /* [2.5.29.14 | 2.5:0]             */  /* [2.5.29.14] */
  /*    39 */         29u,  /* [2.5.29.14 | 29:0]              */  /* [2.5.29.14] */
  /*    40 */         14u,  /* [2.5.29.14 | 14:0]              */  /* [2.5.29.14] */
  /*    41 */         85u,  /* [2.5.29.35 | 2.5:0]             */  /* [2.5.29.35] */
  /*    42 */         29u,  /* [2.5.29.35 | 29:0]              */  /* [2.5.29.35] */
  /*    43 */         35u   /* [2.5.29.35 | 35:0]              */  /* [2.5.29.35] */
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
  KeyM_CertStorage
**********************************************************************************************************************/
#define KEYM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(KeyM_CertStorageUType, KEYM_VAR_NO_INIT) KeyM_CertStorage;  /* PRQA S 0759, 1514, 1533, 0612, 0613 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
  /* Index        Referable Keys */
  /*     0 */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_CA__WrittenLength__] */
  /*     1 */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_CA__WrittenLength__] */
  /*     2 */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_CA__Status__] */
  /*     3 */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_CA__Status__] */
  /*     4 */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_CA__Data__] */
  /*   ... */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_CA__Data__] */
  /*   603 */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_CA__Data__] */
  /*   604 */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_IA__WrittenLength__] */
  /*   605 */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_IA__WrittenLength__] */
  /*   606 */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_IA__Status__] */
  /*   607 */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_IA__Status__] */
  /*   608 */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_IA__Data__] */
  /*   ... */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_IA__Data__] */
  /*  1207 */  /* [KeyMCertificate_OSSL_X509_ECDSA_P384_IA__Data__] */

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
VAR(tKeyMCertInfoType, KEYM_VAR_NO_INIT) KeyM_Cert_CertInfo[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(KeyM_CertificateIdType, KEYM_VAR_NO_INIT) KeyM_Cert_LeafCertsToVerify[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
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
VAR(tKeyMCertStorageType, KEYM_VAR_NO_INIT) KeyM_Cert_StorageType[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(KeyM_CertificateIdType, KEYM_VAR_NO_INIT) KeyM_Cert_VerifyChain[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
  /*     0 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     1 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */

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
VAR(KeyM_Ans1_Element_Ref_Type, KEYM_VAR_NO_INIT) KeyM_ElementStorageRef[45];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Version_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     1 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/SerialNo_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     2 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/SigAlgoId_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     3 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Issuer_CountryName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     4 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Issuer_StateOrProvinceName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     5 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Issuer_LocalityName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     6 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Issuer_OrganizationName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     7 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Issuer_CommonName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     8 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/validityNotBefore_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*     9 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/validityNotAfter_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    10 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Subject_CountryName_004, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    11 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Subject_StateOrProvinceName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    12 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Subject_LocalityName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    13 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Subject_OrganizationName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    14 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/Subject_CommonName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    15 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/SubjectPublicKeyInfoAlgo_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    16 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/SubjectPublicKeyInfoAlgo_Curve_004, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    17 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/SubjectPublicKeyInfoKey_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    18 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/ext1_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    19 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/ext2_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    20 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/ext3_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    21 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/signatureAlgorithm_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    22 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA/signatureValue_009, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  /*    23 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Version_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    24 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/SerialNo_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    25 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/SigAlgoId_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    26 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Issuer_CountryName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    27 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Issuer_StateOrProvinceName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    28 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Issuer_LocalityName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    29 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Issuer_OrganizationName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    30 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Issuer_CommonName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    31 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/validityNotBefore_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    32 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/validityNotAfter_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    33 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Subject_CommonName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    34 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Subject_StateOrProvinceName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    35 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Subject_CountryName_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    36 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/Subject_OrganizationName_006, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    37 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/SubjectPublicKeyInfoAlgo_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    38 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/SubjectPublicKeyInfoAlgo_Curve_005, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    39 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/SubjectPublicKeyInfoKey_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    40 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/ext1_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    41 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/ext2_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    42 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/ext3_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    43 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/signatureAlgorithm_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  /*    44 */  /* [/ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA/signatureValue_010, /ActiveEcuC/KeyM/KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */

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




/**********************************************************************************************************************
 *  END OF FILE: KeyM_Cfg.c
 *********************************************************************************************************************/
