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
 *              File: KeyM_Cfg.h
 *   Generation Time: 2024-01-17 10:56:24
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (KEYM_CFG_H)
#define KEYM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "KeyM_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef KEYM_USE_DUMMY_STATEMENT
#define KEYM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef KEYM_DUMMY_STATEMENT
#define KEYM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef KEYM_DUMMY_STATEMENT_CONST
#define KEYM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef KEYM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define KEYM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef KEYM_ATOMIC_VARIABLE_ACCESS
#define KEYM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef KEYM_PROCESSOR_TC322L
#define KEYM_PROCESSOR_TC322L
#endif
#ifndef KEYM_COMP_TASKING
#define KEYM_COMP_TASKING
#endif
#ifndef KEYM_GEN_GENERATOR_MSR
#define KEYM_GEN_GENERATOR_MSR
#endif
#ifndef KEYM_CPUTYPE_BITORDER_LSB2MSB
#define KEYM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef KEYM_CONFIGURATION_VARIANT_PRECOMPILE
#define KEYM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef KEYM_CONFIGURATION_VARIANT_LINKTIME
#define KEYM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef KEYM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define KEYM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef KEYM_CONFIGURATION_VARIANT
#define KEYM_CONFIGURATION_VARIANT KEYM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef KEYM_POSTBUILD_VARIANT_SUPPORT
#define KEYM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define KEYM_ALGORITHM_RSA_ENABLED                                                                  STD_OFF
#define KEYM_ALGORITHM_ECDSA_ENABLED                                                                STD_OFF
#define KEYM_ALGORITHM_EDDSA_ENABLED                                                                STD_ON
#define KEYM_CERTIFICATEEXTENSION_MAX_LENGTH                                                        170u
#define KEYM_CERTIFICATEISSUERNAME_MAX_LENGTH                                                       20u
#define KEYM_CERTIFICATEISSUERUNIQUEIDENTIFIER_MAX_LENGTH                                           0u
#define KEYM_CERTIFICATESERIALNUMBER_MAX_LENGTH                                                     16u
#define KEYM_CERTIFICATESIGNATURE_MAX_LENGTH                                                        65u
#define KEYM_CERTIFICATESIGNATUREALGORITHM_MAX_LENGTH                                               3u
#define KEYM_CERTIFICATESIGNATUREALGORITHMID_MAX_LENGTH                                             3u
#define KEYM_CERTIFICATESUBJECTNAME_MAX_LENGTH                                                      48u
#define KEYM_CERTIFICATESUBJECTPUBLICKEYINFO_PUBLICKEYALGORITHM_MAX_LENGTH                          3u
#define KEYM_CERTIFICATESUBJECTPUBLICKEYINFO_SUBJECTPUBLICKEY_MAX_LENGTH                            33u
#define KEYM_CERTIFICATESUBJECTUNIQUEIDENTIFIER_MAX_LENGTH                                          0u
#define KEYM_CERTIFICATEVALIDITYPERIODNOTAFTER_MAX_LENGTH                                           15u
#define KEYM_CERTIFICATEVALIDITYPERIODNOTBEFORE_MAX_LENGTH                                          13u
#define KEYM_CERTIFICATEVERSIONNUMBER_MAX_LENGTH                                                    1u
#define KEYM_CERTIFICATESUBJECTAUTHORIZATION_MAX_LENGTH                                             0u
#define KEYM_REVOKEDCERTIFICATES_MAX_LENGTH                                                         0u
#define KEYM_CERTIFICATEREVOCATIONLIST_MAX_LENGTH                                                   0u
#define KEYM_CERTIFICATEATTRIBUTEHOLDER_MAX_LENGTH                                                  0u
#define KEYM_CERTIFICATEATTRIBUTE_MAX_LENGTH                                                        0u
#define KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH                                                         33u
#define KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH                                                       65u
#define KEYM_OPTIONAL_CERTIFICATE_ELEMENT_ENABLED                                                   STD_ON
#define KEYM_HAS_ITERATION_CERTIFICATE_ELEMENT_ENABLED                                              STD_ON
#define KEYM_ROM_CERTIFICATES                                                                       STD_OFF
/* Microsar Define Block for Boolean and Integers */
#define KEYM_CERTIFICATE_CHAIN_MAX_DEPTH                                                            4u 
#define KEYM_CERTIFICATE_MANAGER_ENABLED                                                            STD_ON 
#define KEYM_CRYPTO_KEY_PREPARE_FUNCTION_ENABLED                                                    STD_OFF 
#define KEYM_CRYPTO_KEY_START_FINALIZE_FUNCTION_ENABLED                                             STD_OFF 
#define KEYM_CRYPTO_KEY_VERIFY_ASYNC_MODE                                                           STD_OFF 
#define KEYM_CRYPTO_KEY_VERIFY_FUNCTION_ENABLED                                                     STD_OFF 
#define KEYM_KEY_CERT_NAME_MAX_LENGTH                                                               30u 
#define KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED                                                   STD_ON 
#define KEYM_VERSION_INFO_API                                                                       STD_OFF 
#define KEYM_PARSE_MAX_NESTING_LEVEL                                                                20u 
#define KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED                                                    STD_ON 
#define KEYM_CERTIFICATE_EXTENSION_VALIDATION_ENABLED                                               STD_OFF 
#define KEYM_OCSPRESPONSE_VALIDITY_PERIOD                                                           1209600u 
#define KEYM_OCSPMAX_LENGTH_OF_DISTINGUISHED_NAME                                                   1000u 
#define KEYM_OCSPMAX_LENGTH_OF_CERT_ID_HASH                                                         64u 
#define KEYM_OCSPFORMAT                                                                             STD_OFF 
#define KEYM_CREMAX_NUMBER_OF_ENTRIES                                                               1u 
#define KEYM_CREMAX_LENGTH_OF_ISSUER_NAME                                                           64u 
#define KEYM_CREMAX_LENGTH_OF_SERIAL_NUMBER                                                         32u 
#define KEYM_CRE                                                                                    STD_OFF 
#define KEYM_REMOTE_OCSPENABLED                                                                     STD_OFF 
#define KEYM_REMOTE_CREENABLED                                                                      STD_OFF 
#define KEYM_PUBLISHED_INFORMATION                                                                  STD_OFF 

/* Symbolic Name Define Block */
#define KeyMConf_KeyMCertificate_Ssa_TrustModelBackendCert                                          0u 
#define KeyMConf_KeyMCertificate_Ssa_TrustModelBackendPeerCert                                      1u 
#define KeyMConf_KeyMCertificate_Ssa_TrustModelEcuCert                                              2u 
#define KeyMConf_KeyMCertificate_Ssa_TrustModelEcuCsr                                               3u 
#define KeyMConf_KeyMCertificate_Ssa_TrustModelEcuPeerCert                                          4u 
#define KeyMConf_KeyMCertificate_Ssa_TrustModelIntermediateCert                                     5u 
#define KeyMConf_KeyMCertificate_Ssa_TrustModelIntermediatePeerCert                                 6u 
#define KeyMConf_KeyMCertificate_Ssa_TrustModelRootCert                                             7u 

#define KEYM_AC                                                                                     0x00u 
#define KEYM_CRL                                                                                    0x01u 
#define KEYM_CVC                                                                                    0x02u 
#define KEYM_X509                                                                                   0x03u 
#define KEYM_STORAGE_IN_CSM                                                                         0x00u 
#define KEYM_STORAGE_IN_NVM                                                                         0x01u 
#define KEYM_STORAGE_IN_RAM                                                                         0x02u 
#define KEYM_STORAGE_IN_ROM                                                                         0x03u 
#define KEYM_STORAGE_REMOTE                                                                         0x04u 
#define KEYM_ECDSA                                                                                  0x00u 
#define KEYM_EDDSA                                                                                  0x01u 
#define KEYM_RSA                                                                                    0x02u 
#define KEYM_NONE                                                                                   0x00u 
#define KEYM_PARSE_AND_TRUST                                                                        0x01u 
#define KEYM_PARSE_AND_VERIFY                                                                       0x02u 
#define KEYM_DYNAMIC_MANDATORY_ISSUER                                                               0x00u 
#define KEYM_DYNAMIC_OPTIONAL_ISSUER                                                                0x01u 
#define KEYM_DYNAMIC_SELFSIGNED_OR_MANDATORY_ISSUER                                                 0x02u 
#define KEYM_PRESET_ISSUER                                                                          0x03u 
#define KEYM_CERT                                                                                   0x00u 
#define KEYM_PUBKEY                                                                                 0x01u 

#define KEYM_DEFERRED                                                                               0u
#define KEYM_IMMEDIATE                                                                              1u
#define KEYM_CERTIFICATE_NVMBLOCK                                                                   STD_OFF
#define KEYM_NUMBER_OF_CERTIFICATES                                                                 8u
#define KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO                                                    0x80u
#define KEYM_CERTIFICATE_VALIDITY_PERIOD                                                            0x81u
#define KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ECC_CURVE                               0x82u
#define KeyMConf_KeyMCertificateElement_Version                      0u 
#define KeyMConf_KeyMCertificateElement_Version_002                  0u 
#define KeyMConf_KeyMCertificateElement_Version_003                  0u 
#define KeyMConf_KeyMCertificateElement_Version_004                  0u 
#define KeyMConf_KeyMCertificateElement_Version_005                  0u 
#define KeyMConf_KeyMCertificateElement_Version_006                  0u 
#define KeyMConf_KeyMCertificateElement_Version_007                  0u 
#define KeyMConf_KeyMCertificateElement_Version_008                  0u 
#define KeyMConf_KeyMCertificateElement_SerialNo                     1u 
#define KeyMConf_KeyMCertificateElement_SerialNo_002                 1u 
#define KeyMConf_KeyMCertificateElement_SerialNo_003                 1u 
#define KeyMConf_KeyMCertificateElement_SerialNo_004                 1u 
#define KeyMConf_KeyMCertificateElement_SerialNo_005                 1u 
#define KeyMConf_KeyMCertificateElement_SerialNo_006                 1u 
#define KeyMConf_KeyMCertificateElement_SerialNo_007                 1u 
#define KeyMConf_KeyMCertificateElement_SerialNo_008                 1u 
#define KeyMConf_KeyMCertificateElement_SigAlgoId                    2u 
#define KeyMConf_KeyMCertificateElement_SigAlgoId_002                2u 
#define KeyMConf_KeyMCertificateElement_SigAlgoId_003                2u 
#define KeyMConf_KeyMCertificateElement_SigAlgoId_004                2u 
#define KeyMConf_KeyMCertificateElement_SigAlgoId_005                2u 
#define KeyMConf_KeyMCertificateElement_SigAlgoId_006                2u 
#define KeyMConf_KeyMCertificateElement_SigAlgoId_007                2u 
#define KeyMConf_KeyMCertificateElement_SigAlgoId_008                2u 
#define KeyMConf_KeyMCertificateElement_Issuer                       3u 
#define KeyMConf_KeyMCertificateElement_Issuer_002                   3u 
#define KeyMConf_KeyMCertificateElement_Issuer_003                   3u 
#define KeyMConf_KeyMCertificateElement_Issuer_004                   3u 
#define KeyMConf_KeyMCertificateElement_Issuer_005                   3u 
#define KeyMConf_KeyMCertificateElement_Issuer_006                   3u 
#define KeyMConf_KeyMCertificateElement_Issuer_007                   3u 
#define KeyMConf_KeyMCertificateElement_Issuer_008                   3u 
#define KeyMConf_KeyMCertificateElement_validityNotBefore            4u 
#define KeyMConf_KeyMCertificateElement_validityNotBefore_002        4u 
#define KeyMConf_KeyMCertificateElement_validityNotBefore_003        4u 
#define KeyMConf_KeyMCertificateElement_validityNotBefore_004        4u 
#define KeyMConf_KeyMCertificateElement_validityNotBefore_005        4u 
#define KeyMConf_KeyMCertificateElement_validityNotBefore_006        4u 
#define KeyMConf_KeyMCertificateElement_validityNotBefore_007        4u 
#define KeyMConf_KeyMCertificateElement_validityNotBefore_008        4u 
#define KeyMConf_KeyMCertificateElement_validityNotAfter             5u 
#define KeyMConf_KeyMCertificateElement_validityNotAfter_002         5u 
#define KeyMConf_KeyMCertificateElement_validityNotAfter_003         5u 
#define KeyMConf_KeyMCertificateElement_validityNotAfter_004         5u 
#define KeyMConf_KeyMCertificateElement_validityNotAfter_005         5u 
#define KeyMConf_KeyMCertificateElement_validityNotAfter_006         5u 
#define KeyMConf_KeyMCertificateElement_validityNotAfter_007         5u 
#define KeyMConf_KeyMCertificateElement_validityNotAfter_008         5u 
#define KeyMConf_KeyMCertificateElement_subject                      6u 
#define KeyMConf_KeyMCertificateElement_subject_002                  6u 
#define KeyMConf_KeyMCertificateElement_subject_003                  6u 
#define KeyMConf_KeyMCertificateElement_subject_004                  6u 
#define KeyMConf_KeyMCertificateElement_subject_005                  6u 
#define KeyMConf_KeyMCertificateElement_subject_006                  6u 
#define KeyMConf_KeyMCertificateElement_subject_007                  6u 
#define KeyMConf_KeyMCertificateElement_subject_008                  6u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoAlgo     7u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoAlgo_002 7u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoAlgo_003 7u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoAlgo_004 7u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoAlgo_005 7u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoAlgo_006 7u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoAlgo_007 7u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoAlgo_008 7u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoKey      8u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoKey_002  8u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoKey_003  8u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoKey_004  8u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoKey_005  8u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoKey_006  8u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoKey_007  8u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoKey_008  8u 
#define KeyMConf_KeyMCertificateElement_ext_keyUsage_005             9u 
#define KeyMConf_KeyMCertificateElement_ext_keyUsage_006             9u 
#define KeyMConf_KeyMCertificateElement_ext_subKeyId                 9u 
#define KeyMConf_KeyMCertificateElement_ext_subKeyId_002             9u 
#define KeyMConf_KeyMCertificateElement_ext_subKeyId_003             9u 
#define KeyMConf_KeyMCertificateElement_ext_subKeyId_004             9u 
#define KeyMConf_KeyMCertificateElement_ext_subKeyId_007             9u 
#define KeyMConf_KeyMCertificateElement_ext_subKeyId_008             9u 
#define KeyMConf_KeyMCertificateElement_ext_authKeyId_002            10u 
#define KeyMConf_KeyMCertificateElement_ext_authKeyId_003            10u 
#define KeyMConf_KeyMCertificateElement_ext_authKeyId_004            10u 
#define KeyMConf_KeyMCertificateElement_ext_authKeyId_007            10u 
#define KeyMConf_KeyMCertificateElement_ext_authKeyId_008            10u 
#define KeyMConf_KeyMCertificateElement_ext_basicConstraints         10u 
#define KeyMConf_KeyMCertificateElement_ext_subKeyId_005             10u 
#define KeyMConf_KeyMCertificateElement_ext_subKeyId_006             10u 
#define KeyMConf_KeyMCertificateElement_ext_authKeyId_005            11u 
#define KeyMConf_KeyMCertificateElement_ext_authKeyId_006            11u 
#define KeyMConf_KeyMCertificateElement_ext_basicConstraints_002     11u 
#define KeyMConf_KeyMCertificateElement_ext_basicConstraints_003     11u 
#define KeyMConf_KeyMCertificateElement_ext_basicConstraints_004     11u 
#define KeyMConf_KeyMCertificateElement_ext_basicConstraints_005     11u 
#define KeyMConf_KeyMCertificateElement_ext_keyUsage                 11u 
#define KeyMConf_KeyMCertificateElement_ext_keyUsage_008             11u 
#define KeyMConf_KeyMCertificateElement_ext_authKeyId_009            12u 
#define KeyMConf_KeyMCertificateElement_ext_extKeyUsage_007          12u 
#define KeyMConf_KeyMCertificateElement_ext_keyUsage_002             12u 
#define KeyMConf_KeyMCertificateElement_ext_keyUsage_003             12u 
#define KeyMConf_KeyMCertificateElement_ext_keyUsage_004             12u 
#define KeyMConf_KeyMCertificateElement_ext_keyUsage_007             12u 
#define KeyMConf_KeyMCertificateElement_ext_pkiRole_006              12u 
#define KeyMConf_KeyMCertificateElement_ext_specialEcu_006           12u 
#define KeyMConf_KeyMCertificateElement_ext_extKeyUsage_oid1_007     13u 
#define KeyMConf_KeyMCertificateElement_ext_pkiRole                  13u 
#define KeyMConf_KeyMCertificateElement_ext_pkiRole_002              13u 
#define KeyMConf_KeyMCertificateElement_ext_pkiRole_003              13u 
#define KeyMConf_KeyMCertificateElement_ext_pkiRole_004              13u 
#define KeyMConf_KeyMCertificateElement_ext_pkiRole_005              13u 
#define KeyMConf_KeyMCertificateElement_ext_uniqueECUID_005          13u 
#define KeyMConf_KeyMCertificateElement_ext_uniqueECUID_006          13u 
#define KeyMConf_KeyMCertificateElement_ext_extKeyUsage_oid2_007     14u 
#define KeyMConf_KeyMCertificateElement_ext_specialEcu_005           14u 
#define KeyMConf_KeyMCertificateElement_signatureAlgorithm           14u 
#define KeyMConf_KeyMCertificateElement_signatureAlgorithm_002       14u 
#define KeyMConf_KeyMCertificateElement_signatureAlgorithm_003       14u 
#define KeyMConf_KeyMCertificateElement_signatureAlgorithm_004       14u 
#define KeyMConf_KeyMCertificateElement_signatureAlgorithm_006       14u 
#define KeyMConf_KeyMCertificateElement_signatureAlgorithm_007       14u 
#define KeyMConf_KeyMCertificateElement_ext_extKeyUsage_oid3_007     15u 
#define KeyMConf_KeyMCertificateElement_signatureAlgorithm_005       15u 
#define KeyMConf_KeyMCertificateElement_signatureValue               15u 
#define KeyMConf_KeyMCertificateElement_signatureValue_002           15u 
#define KeyMConf_KeyMCertificateElement_signatureValue_003           15u 
#define KeyMConf_KeyMCertificateElement_signatureValue_004           15u 
#define KeyMConf_KeyMCertificateElement_signatureValue_006           15u 
#define KeyMConf_KeyMCertificateElement_signatureValue_007           15u 
#define KeyMConf_KeyMCertificateElement_ext_pkiRole_008              16u 
#define KeyMConf_KeyMCertificateElement_signatureValue_005           16u 
#define KeyMConf_KeyMCertificateElement_ext_uniqueECUID_007          17u 
#define KeyMConf_KeyMCertificateElement_ext_specialEcu_007           18u 
#define KeyMConf_KeyMCertificateElement_signatureAlgorithm_008       19u 
#define KeyMConf_KeyMCertificateElement_signatureValue_008           20u 

#define KEYM_MAX_CERTIFICATE_MAX_LENGTH                                                             1000u
#define KEYM_MAX_NUM_CSR_EXTENSIONS                                                                 10u
#define KEYM_MAX_NUM_CERT_ELEMENTS                                                                  21u
#define KEYM_CSM_SYNC_SIGNATURE_VERIFY                                                              STD_OFF
#define KEYM_CSM_ASYNC_SIGNATURE_VERIFY                                                             STD_ON
#define KEYM_MAX_NUM_EXTENSIONS                                                                     10u
#define KEYM_MAX_NUM_SUBJECT_NAME_COMPONENTS                                                        1u
#define KEYM_REMOTE_DISPATCHING_ENABLED                                                             STD_OFF
#define KEYM_REMOTE_REDIRECTION_ENABLED                                                             STD_OFF
#ifndef KEYM_DEV_ERROR_DETECT
#define KEYM_DEV_ERROR_DETECT STD_OFF
#endif
#ifndef KEYM_DEV_ERROR_REPORT
#define KEYM_DEV_ERROR_REPORT STD_OFF
#endif


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  KeyMPCDataSwitches  KeyM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define KEYM_BASICCONSTRAINTSSTORAGE                                                                STD_OFF  /**< Deactivateable: 'KeyM_BasicConstraintsStorage' Reason: 'KeyM not configured for certificate extension validation.' */
#define KEYM_CREINFO                                                                                STD_OFF  /**< Deactivateable: 'KeyM_CREInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define KEYM_CRESTORAGEIDENDIDXOFCREINFO                                                            STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIdEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEIDLENGTHOFCREINFO                                                            STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIdLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEIDSTARTIDXOFCREINFO                                                          STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIdStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEISSUERENDIDXOFCREINFO                                                        STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIssuerEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEISSUERLENGTHOFCREINFO                                                        STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIssuerLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEISSUERSTARTIDXOFCREINFO                                                      STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIssuerStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEISSUERWRITTENLENGTHENDIDXOFCREINFO                                           STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIssuerWrittenLengthEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEISSUERWRITTENLENGTHLENGTHOFCREINFO                                           STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIssuerWrittenLengthLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGEISSUERWRITTENLENGTHSTARTIDXOFCREINFO                                         STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageIssuerWrittenLengthStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGESERIALNUMBERENDIDXOFCREINFO                                                  STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageSerialNumberEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGESERIALNUMBERLENGTHOFCREINFO                                                  STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageSerialNumberLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGESERIALNUMBERSTARTIDXOFCREINFO                                                STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageSerialNumberStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGESERIALNUMBERWRITTENLENGTHENDIDXOFCREINFO                                     STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageSerialNumberWrittenLengthEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGESERIALNUMBERWRITTENLENGTHLENGTHOFCREINFO                                     STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageSerialNumberWrittenLengthLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGESERIALNUMBERWRITTENLENGTHSTARTIDXOFCREINFO                                   STD_OFF  /**< Deactivateable: 'KeyM_CREInfo.CREStorageSerialNumberWrittenLengthStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CRESTORAGE                                                                             STD_OFF  /**< Deactivateable: 'KeyM_CREStorage' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTELEMENTPATH                                                                        STD_OFF  /**< Deactivateable: 'KeyM_CertElementPath' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTHASHSTORAGE                                                                        STD_OFF  /**< Deactivateable: 'KeyM_CertHashStorage' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTINFODATA                                                                           STD_OFF  /**< Deactivateable: 'KeyM_CertInfoData' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTPUBKEYHASHSTORAGE                                                                  STD_OFF  /**< Deactivateable: 'KeyM_CertPubKeyHashStorage' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTSTORAGE                                                                            STD_ON
#define KEYM_CERT_CERTINFO                                                                          STD_ON
#define KEYM_CERT_LEAFCERTSTOVERIFY                                                                 STD_ON
#define KEYM_CERT_LOCK                                                                              STD_ON
#define KEYM_CERT_STORAGETYPE                                                                       STD_ON
#define KEYM_CERT_VERIFYCHAIN                                                                       STD_ON
#define KEYM_CERTIFICATE                                                                            STD_ON
#define KEYM_CERTALGORITHMFAMILYOFCERTIFICATE                                                       STD_ON
#define KEYM_CERTALLOWFLEXIBLEELEMENTORDEROFCERTIFICATE                                             STD_ON
#define KEYM_CERTALLOWUNCONFIGUREDELEMENTSOFCERTIFICATE                                             STD_ON
#define KEYM_CERTATTRIBUTEHOLDERCERTREFIDXOFCERTIFICATE                                             STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertAttributeHolderCertRefIdx' Reason: 'the optional indirection is deactivated because CertificateUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTCSMHASHJOBREFOFCERTIFICATE                                                         STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertCsmHashJobRef' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmHashJobRef not configured.' */
#define KEYM_CERTCSMHASHJOBREFVALIDOFCERTIFICATE                                                    STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertCsmHashJobRefValid' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmHashJobRef not configured.' */
#define KEYM_CERTCSMSIGNATUREGENERATEJOBREFOFCERTIFICATE                                            STD_ON
#define KEYM_CERTCSMSIGNATUREGENERATEJOBREFVALIDOFCERTIFICATE                                       STD_ON
#define KEYM_CERTCSMSIGNATUREVERIFYJOBREFOFCERTIFICATE                                              STD_ON
#define KEYM_CERTCSMSIGNATUREVERIFYKEYREFOFCERTIFICATE                                              STD_ON
#define KEYM_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE                                         STD_ON
#define KEYM_CERTFORMATTYPEOFCERTIFICATE                                                            STD_ON
#define KEYM_CERTHASHSTORAGEENDIDXOFCERTIFICATE                                                     STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashStorageEndIdx' Reason: 'the optional indirection is deactivated because CertHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTHASHSTORAGELENGTHOFCERTIFICATE                                                     STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashStorageLength' Reason: 'the optional indirection is deactivated because CertHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTHASHSTORAGESTARTIDXOFCERTIFICATE                                                   STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashStorageStartIdx' Reason: 'the optional indirection is deactivated because CertHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTHASHSTORAGEUSEDOFCERTIFICATE                                                       STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashStorageUsed' Reason: 'the optional indirection is deactivated because CertHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTHASHTYPEOFCERTIFICATE                                                              STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashType' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertHashType not configured.' */
#define KEYM_CERTHASHTYPEVALIDOFCERTIFICATE                                                         STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashTypeValid' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertHashType not configured.' */
#define KEYM_CERTINFODATAIDXOFCERTIFICATE                                                           STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertInfoDataIdx' Reason: 'the optional indirection is deactivated because CertInfoDataUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTINFODATAUSEDOFCERTIFICATE                                                          STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertInfoDataUsed' Reason: 'the optional indirection is deactivated because CertInfoDataUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTPUBKEYHASHSTORAGEENDIDXOFCERTIFICATE                                               STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertPubKeyHashStorageEndIdx' Reason: 'the optional indirection is deactivated because CertPubKeyHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTPUBKEYHASHSTORAGELENGTHOFCERTIFICATE                                               STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertPubKeyHashStorageLength' Reason: 'the optional indirection is deactivated because CertPubKeyHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTPUBKEYHASHSTORAGESTARTIDXOFCERTIFICATE                                             STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertPubKeyHashStorageStartIdx' Reason: 'the optional indirection is deactivated because CertPubKeyHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTPUBKEYHASHSTORAGEUSEDOFCERTIFICATE                                                 STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertPubKeyHashStorageUsed' Reason: 'the optional indirection is deactivated because CertPubKeyHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTSTARTUPHANDLINGOFCERTIFICATE                                                       STD_ON
#define KEYM_CERTSTORAGEENDIDXOFCERTIFICATE                                                         STD_ON
#define KEYM_CERTSTORAGELENGTHOFCERTIFICATE                                                         STD_ON
#define KEYM_CERTSTORAGESTARTIDXOFCERTIFICATE                                                       STD_ON
#define KEYM_CERTSTORAGESTATUSENDIDXOFCERTIFICATE                                                   STD_ON
#define KEYM_CERTSTORAGESTATUSLENGTHOFCERTIFICATE                                                   STD_ON
#define KEYM_CERTSTORAGESTATUSSTARTIDXOFCERTIFICATE                                                 STD_ON
#define KEYM_CERTSTORAGEUSEDOFCERTIFICATE                                                           STD_ON
#define KEYM_CERTSTORAGEWRITTENLENGTHENDIDXOFCERTIFICATE                                            STD_ON
#define KEYM_CERTSTORAGEWRITTENLENGTHLENGTHOFCERTIFICATE                                            STD_ON
#define KEYM_CERTSTORAGEWRITTENLENGTHSTARTIDXOFCERTIFICATE                                          STD_ON
#define KEYM_CERTSTORAGEWRITTENLENGTHUSEDOFCERTIFICATE                                              STD_ON
#define KEYM_CERTTIMEBASEREFOFCERTIFICATE                                                           STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertTimebaseRef' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertTimebaseRef not configured.' */
#define KEYM_CERTTIMEBASEREFVALIDOFCERTIFICATE                                                      STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertTimebaseRefValid' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertTimebaseRef not configured.' */
#define KEYM_CERTUPPERHIERARCHICALCERTREFIDXOFCERTIFICATE                                           STD_ON
#define KEYM_CERTUPPERHIERARCHICALTYPEOFCERTIFICATE                                                 STD_ON
#define KEYM_CERTIFICATEELEMENTENDIDXOFCERTIFICATE                                                  STD_ON
#define KEYM_CERTIFICATEELEMENTLENGTHOFCERTIFICATE                                                  STD_ON
#define KEYM_CERTIFICATEELEMENTSTARTIDXOFCERTIFICATE                                                STD_ON
#define KEYM_CERTIFICATEELEMENTUSEDOFCERTIFICATE                                                    STD_ON
#define KEYM_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE                                       STD_ON
#define KEYM_CERTIFICATEGETCURRENTTIMECALLOUTUSEDOFCERTIFICATE                                      STD_ON
#define KEYM_CERTIFICATEGROUPIDXOFCERTIFICATE                                                       STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateGroupIdx' Reason: 'the optional indirection is deactivated because CertificateGroupUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE                                                      STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateGroupUsed' Reason: 'the optional indirection is deactivated because CertificateGroupUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE                                               STD_ON
#define KEYM_CERTIFICATEINITVALUEINFOUSEDOFCERTIFICATE                                              STD_ON
#define KEYM_CERTIFICATENAMEENDIDXOFCERTIFICATE                                                     STD_ON
#define KEYM_CERTIFICATENAMELENGTHOFCERTIFICATE                                                     STD_ON
#define KEYM_CERTIFICATENAMESTARTIDXOFCERTIFICATE                                                   STD_ON
#define KEYM_CERTIFICATESETKEYCALLOUTIDXOFCERTIFICATE                                               STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateSetKeyCalloutIdx' Reason: 'the optional indirection is deactivated because CertificateSetKeyCalloutUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATESETKEYCALLOUTUSEDOFCERTIFICATE                                              STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateSetKeyCalloutUsed' Reason: 'the optional indirection is deactivated because CertificateSetKeyCalloutUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE                                                       STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateSlotUsed' Reason: 'the optional indirection is deactivated because CertificateSlotUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEUSEDOFCERTIFICATE                                                           STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateUsed' Reason: 'the optional indirection is deactivated because CertificateUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHIDIDXOFCERTIFICATE                            STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateVerifyCallbackNotificationWithIdIdx' Reason: 'the optional indirection is deactivated because CertificateVerifyCallbackNotificationWithIdUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHIDUSEDOFCERTIFICATE                           STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateVerifyCallbackNotificationWithIdUsed' Reason: 'the optional indirection is deactivated because CertificateVerifyCallbackNotificationWithIdUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDIDXOFCERTIFICATE                         STD_ON
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDUSEDOFCERTIFICATE                        STD_ON
#define KEYM_CSMKEYTARGETREFOFCERTIFICATE                                                           STD_ON
#define KEYM_CSMKEYTARGETREFVALIDOFCERTIFICATE                                                      STD_ON
#define KEYM_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE                                                STD_ON
#define KEYM_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE                                   STD_ON
#define KEYM_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE                                     STD_ON
#define KEYM_MASKEDBITSOFCERTIFICATE                                                                STD_ON
#define KEYM_MAXLENGTHOFCERTIFICATE                                                                 STD_ON
#define KEYM_NVMBLOCKIDXOFCERTIFICATE                                                               STD_OFF  /**< Deactivateable: 'KeyM_Certificate.NvmBlockIdx' Reason: 'the optional indirection is deactivated because NvmBlockUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_NVMBLOCKUSEDOFCERTIFICATE                                                              STD_OFF  /**< Deactivateable: 'KeyM_Certificate.NvmBlockUsed' Reason: 'the optional indirection is deactivated because NvmBlockUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_REMOTECERTIFICATEIDOFCERTIFICATE                                                       STD_ON
#define KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE                                 STD_OFF  /**< Deactivateable: 'KeyM_Certificate.ServiceCertificateCallbackNotificationIdx' Reason: 'the optional indirection is deactivated because ServiceCertificateCallbackNotificationUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONUSEDOFCERTIFICATE                                STD_OFF  /**< Deactivateable: 'KeyM_Certificate.ServiceCertificateCallbackNotificationUsed' Reason: 'the optional indirection is deactivated because ServiceCertificateCallbackNotificationUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_SERVICECERTIFICATERTECALLBACKNOTIFICATION2211IDXOFCERTIFICATE                          STD_OFF  /**< Deactivateable: 'KeyM_Certificate.ServiceCertificateRteCallbackNotification2211Idx' Reason: 'the optional indirection is deactivated because ServiceCertificateRteCallbackNotification2211UsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_SERVICECERTIFICATERTECALLBACKNOTIFICATION2211USEDOFCERTIFICATE                         STD_OFF  /**< Deactivateable: 'KeyM_Certificate.ServiceCertificateRteCallbackNotification2211Used' Reason: 'the optional indirection is deactivated because ServiceCertificateRteCallbackNotification2211UsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_SERVICECERTIFICATERTECALLBACKNOTIFICATION440IDXOFCERTIFICATE                           STD_ON
#define KEYM_SERVICECERTIFICATERTECALLBACKNOTIFICATION440USEDOFCERTIFICATE                          STD_ON
#define KEYM_SLOTREFIDXOFCERTIFICATE                                                                STD_OFF  /**< Deactivateable: 'KeyM_Certificate.SlotRefIdx' Reason: 'the optional indirection is deactivated because CertificateSlotUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_STORAGEOFCERTIFICATE                                                                   STD_ON
#define KEYM_CERTIFICATECHAINMAXDEPTHOFGENERAL                                                      STD_ON
#define KEYM_CERTIFICATEELEMENT                                                                     STD_ON
#define KEYM_CERTELEMENTPATHENDIDXOFCERTIFICATEELEMENT                                              STD_OFF  /**< Deactivateable: 'KeyM_CertificateElement.CertElementPathEndIdx' Reason: 'the optional indirection is deactivated because CertElementPathUsedOfCertificateElement is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTELEMENTPATHLENGTHOFCERTIFICATEELEMENT                                              STD_OFF  /**< Deactivateable: 'KeyM_CertificateElement.CertElementPathLength' Reason: 'the optional indirection is deactivated because CertElementPathUsedOfCertificateElement is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTELEMENTPATHSTARTIDXOFCERTIFICATEELEMENT                                            STD_OFF  /**< Deactivateable: 'KeyM_CertificateElement.CertElementPathStartIdx' Reason: 'the optional indirection is deactivated because CertElementPathUsedOfCertificateElement is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTELEMENTPATHUSEDOFCERTIFICATEELEMENT                                                STD_OFF  /**< Deactivateable: 'KeyM_CertificateElement.CertElementPathUsed' Reason: 'the optional indirection is deactivated because CertElementPathUsedOfCertificateElement is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT                           STD_ON
#define KEYM_CERTIFICATEELEMENTVERIFICATIONCALLOUTUSEDOFCERTIFICATEELEMENT                          STD_ON
#define KEYM_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT                                                   STD_ON
#define KEYM_ELEMENTOIDLENGTHOFCERTIFICATEELEMENT                                                   STD_ON
#define KEYM_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT                                                 STD_ON
#define KEYM_ELEMENTOIDUSEDOFCERTIFICATEELEMENT                                                     STD_ON
#define KEYM_HASITERATIONOFCERTIFICATEELEMENT                                                       STD_ON
#define KEYM_IDOFCERTIFICATEELEMENT                                                                 STD_ON
#define KEYM_MASKEDBITSOFCERTIFICATEELEMENT                                                         STD_ON
#define KEYM_MAXLENGTHOFCERTIFICATEELEMENT                                                          STD_ON
#define KEYM_OBJECTTYPEOFCERTIFICATEELEMENT                                                         STD_ON
#define KEYM_OFSTRUCTUREOFCERTIFICATEELEMENT                                                        STD_ON
#define KEYM_OPTIONALOFCERTIFICATEELEMENT                                                           STD_ON
#define KEYM_CERTIFICATEELEMENTVERIFICATIONCALLOUT                                                  STD_ON
#define KEYM_CERTIFICATEEXTENSIONVALIDATIONENABLEDOFGENERAL                                         STD_ON
#define KEYM_CERTIFICATEGETCURRENTTIMECALLOUT                                                       STD_ON
#define KEYM_CERTIFICATEGROUP                                                                       STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define KEYM_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONIDXOFCERTIFICATEGROUP                        STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.CertificateGroupVerifyCallbackNotificationIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONUSEDOFCERTIFICATEGROUP                       STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.CertificateGroupVerifyCallbackNotificationUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEREMOTEGROUPIDOFCERTIFICATEGROUP                                             STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.CertificateRemoteGroupId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_ELEMENTOIDPRIMARYENDIDXOFCERTIFICATEGROUP                                              STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.ElementOidPrimaryEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_ELEMENTOIDPRIMARYLENGTHOFCERTIFICATEGROUP                                              STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.ElementOidPrimaryLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_ELEMENTOIDPRIMARYSTARTIDXOFCERTIFICATEGROUP                                            STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.ElementOidPrimaryStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_ELEMENTOIDPRIMARYUSEDOFCERTIFICATEGROUP                                                STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.ElementOidPrimaryUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_ELEMENTOIDSECONDARYENDIDXOFCERTIFICATEGROUP                                            STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.ElementOidSecondaryEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_ELEMENTOIDSECONDARYLENGTHOFCERTIFICATEGROUP                                            STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.ElementOidSecondaryLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_ELEMENTOIDSECONDARYSTARTIDXOFCERTIFICATEGROUP                                          STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.ElementOidSecondaryStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_ELEMENTOIDSECONDARYUSEDOFCERTIFICATEGROUP                                              STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.ElementOidSecondaryUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_GROUPINDCERTENDIDXOFCERTIFICATEGROUP                                                   STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.GroupIndCertEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_GROUPINDCERTLENGTHOFCERTIFICATEGROUP                                                   STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.GroupIndCertLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_GROUPINDCERTSTARTIDXOFCERTIFICATEGROUP                                                 STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.GroupIndCertStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_GROUPINDISSUERENDIDXOFCERTIFICATEGROUP                                                 STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.GroupIndIssuerEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_GROUPINDISSUERLENGTHOFCERTIFICATEGROUP                                                 STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.GroupIndIssuerLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_GROUPINDISSUERSTARTIDXOFCERTIFICATEGROUP                                               STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroup.GroupIndIssuerStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEGROUPEXT                                                                    STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroupExt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define KEYM_CERTIFICATEGROUPENDIDXOFCERTIFICATEGROUPEXT                                            STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroupExt.CertificateGroupEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEGROUPLENGTHOFCERTIFICATEGROUPEXT                                            STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroupExt.CertificateGroupLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEGROUPSTARTIDXOFCERTIFICATEGROUPEXT                                          STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroupExt.CertificateGroupStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATION                                             STD_OFF  /**< Deactivateable: 'KeyM_CertificateGroupVerifyCallbackNotification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEINITCALLOUT                                                                 STD_OFF  /**< Deactivateable: 'KeyM_CertificateInitCallout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEINITVALUE                                                                   STD_ON
#define KEYM_CERTIFICATEINITVALUEINFO                                                               STD_ON
#define KEYM_CERTIFICATEINITCALLOUTIDXOFCERTIFICATEINITVALUEINFO                                    STD_OFF  /**< Deactivateable: 'KeyM_CertificateInitValueInfo.CertificateInitCalloutIdx' Reason: 'the optional indirection is deactivated because CertificateInitCalloutUsedOfCertificateInitValueInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEINITCALLOUTUSEDOFCERTIFICATEINITVALUEINFO                                   STD_OFF  /**< Deactivateable: 'KeyM_CertificateInitValueInfo.CertificateInitCalloutUsed' Reason: 'the optional indirection is deactivated because CertificateInitCalloutUsedOfCertificateInitValueInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEINITVALUEENDIDXOFCERTIFICATEINITVALUEINFO                                   STD_ON
#define KEYM_CERTIFICATEINITVALUELENGTHOFCERTIFICATEINITVALUEINFO                                   STD_ON
#define KEYM_CERTIFICATEINITVALUESTARTIDXOFCERTIFICATEINITVALUEINFO                                 STD_ON
#define KEYM_CERTIFICATEINITVALUEUSEDOFCERTIFICATEINITVALUEINFO                                     STD_ON
#define KEYM_CERTIFICATEMANAGERENABLEDOFGENERAL                                                     STD_ON
#define KEYM_CERTIFICATENAME                                                                        STD_ON
#define KEYM_CERTIFICATESETKEYCALLOUT                                                               STD_OFF  /**< Deactivateable: 'KeyM_CertificateSetKeyCallout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATESIGNINGREQUESTENABLEDOFGENERAL                                              STD_ON
#define KEYM_CERTIFICATESLOT                                                                        STD_OFF  /**< Deactivateable: 'KeyM_CertificateSlot' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define KEYM_IDOFCERTIFICATESLOT                                                                    STD_OFF  /**< Deactivateable: 'KeyM_CertificateSlot.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_MAXLENGTHOFCERTIFICATESLOT                                                             STD_OFF  /**< Deactivateable: 'KeyM_CertificateSlot.MaxLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHID                                            STD_OFF  /**< Deactivateable: 'KeyM_CertificateVerifyCallbackNotificationWithId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTID                                         STD_ON
#define KEYM_COMMONCERTDATA                                                                         STD_ON
#define KEYM_CRYPTOKEYPREPAREFUNCTIONENABLEDOFGENERAL                                               STD_ON
#define KEYM_CRYPTOKEYSTARTFINALIZEFUNCTIONENABLEDOFGENERAL                                         STD_ON
#define KEYM_CRYPTOKEYVERIFYASYNCMODEOFGENERAL                                                      STD_ON
#define KEYM_CRYPTOKEYVERIFYFUNCTIONENABLEDOFGENERAL                                                STD_ON
#define KEYM_CSMREMOTEINFOJOBREFOFGENERAL                                                           STD_OFF  /**< Deactivateable: 'KeyM_CsmRemoteInfoJobRefOfGeneral' Reason: 'Reference is not configured!' */
#define KEYM_CSMREMOTEINFOKEYREFOFGENERAL                                                           STD_OFF  /**< Deactivateable: 'KeyM_CsmRemoteInfoKeyRefOfGeneral' Reason: 'Reference is not configured!' */
#define KEYM_ELEMENTOID                                                                             STD_ON
#define KEYM_ELEMENTSTORAGEREF                                                                      STD_ON
#define KEYM_EXPECTEDCOMPATIBILITYVERSION                                                           STD_OFF  /**< Deactivateable: 'KeyM_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define KEYM_FINALMAGICNUMBER                                                                       STD_OFF  /**< Deactivateable: 'KeyM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define KEYM_GENERAL                                                                                STD_ON
#define KEYM_KEYMCSMREMOTEINFOJOBREFASYNCOFGENERAL                                                  STD_ON
#define KEYM_GENERATORCOMPATIBILITYVERSION                                                          STD_OFF  /**< Deactivateable: 'KeyM_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define KEYM_GROUPIND                                                                               STD_OFF  /**< Deactivateable: 'KeyM_GroupInd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define KEYM_CERTIFICATEIDXOFGROUPIND                                                               STD_OFF  /**< Deactivateable: 'KeyM_GroupInd.CertificateIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_INITDATAHASHCODE                                                                       STD_OFF  /**< Deactivateable: 'KeyM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define KEYM_KEYCERTNAMEMAXLENGTHOFGENERAL                                                          STD_ON
#define KEYM_KEYUSAGESTORAGE                                                                        STD_OFF  /**< Deactivateable: 'KeyM_KeyUsageStorage' Reason: 'KeyM not configured for certificate extension validation.' */
#define KEYM_MAINFUNCTIONPERIODOFGENERAL                                                            STD_ON
#define KEYM_MAXLENGTHOFISSUERNAMEOFCRE                                                             STD_OFF  /**< Deactivateable: 'KeyM_MaxLengthOfIssuerNameOfCRE' Reason: 'Parameter is not configured!' */
#define KEYM_MAXLENGTHOFSERIALNUMBEROFCRE                                                           STD_OFF  /**< Deactivateable: 'KeyM_MaxLengthOfSerialNumberOfCRE' Reason: 'Parameter is not configured!' */
#define KEYM_MAXNUMBEROFENTRIESOFCRE                                                                STD_OFF  /**< Deactivateable: 'KeyM_MaxNumberOfEntriesOfCRE' Reason: 'Parameter is not configured!' */
#define KEYM_NVBLOCK_STATE                                                                          STD_OFF  /**< Deactivateable: 'KeyM_NvBlock_State' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_NVMBLOCK                                                                               STD_OFF  /**< Deactivateable: 'KeyM_NvmBlock' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define KEYM_CERTNVBLOCKPROCESSINGOFNVMBLOCK                                                        STD_OFF  /**< Deactivateable: 'KeyM_NvmBlock.CertNvBlockProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_DESCRIPTORREFOFNVMBLOCK                                                                STD_OFF  /**< Deactivateable: 'KeyM_NvmBlock.DescriptorRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_LENGTHOFNVMBLOCK                                                                       STD_OFF  /**< Deactivateable: 'KeyM_NvmBlock.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_OCSP                                                                                   STD_OFF  /**< Deactivateable: 'KeyM_OCSP' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define KEYM_CERTIFICATEGROUPEXTUSEDOFOCSP                                                          STD_OFF  /**< Deactivateable: 'KeyM_OCSP.CertificateGroupExtUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEIDXOFOCSP                                                                   STD_OFF  /**< Deactivateable: 'KeyM_OCSP.CertificateIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_DELEGATEDRESPONDERREFIDXOFOCSP                                                         STD_OFF  /**< Deactivateable: 'KeyM_OCSP.DelegatedResponderRefIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_KEYMOCSPRESPONDERPUBKEYHASHCSMJOBREFASYNCOFOCSP                                        STD_OFF  /**< Deactivateable: 'KeyM_OCSP.KeyMOCSPResponderPubKeyHashCsmJobRefAsync' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_KEYMOCSPRESPONSECERTIDHASHCSMJOBREFASYNCOFOCSP                                         STD_OFF  /**< Deactivateable: 'KeyM_OCSP.KeyMOCSPResponseCertIdHashCsmJobRefAsync' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_RESPONDERPUBKEYHASHCSMJOBREFOFOCSP                                                     STD_OFF  /**< Deactivateable: 'KeyM_OCSP.ResponderPubKeyHashCsmJobRef' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMOCSP/KeyMOCSPResponderPubKeyHashCsmJobRef not configured.' */
#define KEYM_RESPONDERPUBKEYHASHCSMJOBREFVALIDOFOCSP                                                STD_OFF  /**< Deactivateable: 'KeyM_OCSP.ResponderPubKeyHashCsmJobRefValid' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMOCSP/KeyMOCSPResponderPubKeyHashCsmJobRef not configured.' */
#define KEYM_RESPONSECERTIDHASHCSMJOBREFOFOCSP                                                      STD_OFF  /**< Deactivateable: 'KeyM_OCSP.ResponseCertIdHashCsmJobRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_OCSPMAXLENGTHOFCERTIDHASHOFOCSPFORMAT                                                  STD_OFF  /**< Deactivateable: 'KeyM_OCSPMaxLengthOfCertIdHashOfOCSPFormat' Reason: 'Parameter is not configured!' */
#define KEYM_OCSPMAXLENGTHOFDISTINGUISHEDNAMEOFOCSPFORMAT                                           STD_OFF  /**< Deactivateable: 'KeyM_OCSPMaxLengthOfDistinguishedNameOfOCSPFormat' Reason: 'Parameter is not configured!' */
#define KEYM_OCSPRESPONSEVALIDITYPERIODOFGENERAL                                                    STD_OFF  /**< Deactivateable: 'KeyM_OCSPResponseValidityPeriodOfGeneral' Reason: 'Parameter is not configured!' */
#define KEYM_PARSEMAXNESTINGLEVELOFGENERAL                                                          STD_ON
#define KEYM_REMOTECREENABLEDOFPUBLISHEDINFORMATION                                                 STD_OFF  /**< Deactivateable: 'KeyM_RemoteCREEnabledOfPublishedInformation' Reason: 'Parameter is not configured!' */
#define KEYM_REMOTEOCSPENABLEDOFPUBLISHEDINFORMATION                                                STD_OFF  /**< Deactivateable: 'KeyM_RemoteOCSPEnabledOfPublishedInformation' Reason: 'Parameter is not configured!' */
#define KEYM_SERVICECERTIFICATECALLBACKNOTIFICATION                                                 STD_OFF  /**< Deactivateable: 'KeyM_ServiceCertificateCallbackNotification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_SERVICECERTIFICATEFUNCTIONENABLEDOFGENERAL                                             STD_ON
#define KEYM_SERVICECERTIFICATERTECALLBACKNOTIFICATION2211                                          STD_OFF  /**< Deactivateable: 'KeyM_ServiceCertificateRteCallbackNotification2211' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_SERVICECERTIFICATERTECALLBACKNOTIFICATION440                                           STD_ON
#define KEYM_SIZEOFCERTSTORAGE                                                                      STD_ON
#define KEYM_SIZEOFCERT_CERTINFO                                                                    STD_ON
#define KEYM_SIZEOFCERT_LEAFCERTSTOVERIFY                                                           STD_ON
#define KEYM_SIZEOFCERT_LOCK                                                                        STD_ON
#define KEYM_SIZEOFCERT_STORAGETYPE                                                                 STD_ON
#define KEYM_SIZEOFCERT_VERIFYCHAIN                                                                 STD_ON
#define KEYM_SIZEOFCERTIFICATE                                                                      STD_ON
#define KEYM_SIZEOFCERTIFICATEELEMENT                                                               STD_ON
#define KEYM_SIZEOFCERTIFICATEELEMENTVERIFICATIONCALLOUT                                            STD_ON
#define KEYM_SIZEOFCERTIFICATEGETCURRENTTIMECALLOUT                                                 STD_ON
#define KEYM_SIZEOFCERTIFICATEINITVALUE                                                             STD_ON
#define KEYM_SIZEOFCERTIFICATEINITVALUEINFO                                                         STD_ON
#define KEYM_SIZEOFCERTIFICATENAME                                                                  STD_ON
#define KEYM_SIZEOFCERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTID                                   STD_ON
#define KEYM_SIZEOFCOMMONCERTDATA                                                                   STD_ON
#define KEYM_SIZEOFELEMENTOID                                                                       STD_ON
#define KEYM_SIZEOFELEMENTSTORAGEREF                                                                STD_ON
#define KEYM_SIZEOFGENERAL                                                                          STD_ON
#define KEYM_SIZEOFSERVICECERTIFICATERTECALLBACKNOTIFICATION440                                     STD_ON
#define KEYM_SLOTOWNER                                                                              STD_OFF  /**< Deactivateable: 'KeyM_SlotOwner' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_VERSIONINFOAPIOFGENERAL                                                                STD_ON
#define KEYM_PCCONFIG                                                                               STD_ON
#define KEYM_CERTSTORAGEOFPCCONFIG                                                                  STD_ON
#define KEYM_CERT_CERTINFOOFPCCONFIG                                                                STD_ON
#define KEYM_CERT_LEAFCERTSTOVERIFYOFPCCONFIG                                                       STD_ON
#define KEYM_CERT_LOCKOFPCCONFIG                                                                    STD_ON
#define KEYM_CERT_STORAGETYPEOFPCCONFIG                                                             STD_ON
#define KEYM_CERT_VERIFYCHAINOFPCCONFIG                                                             STD_ON
#define KEYM_CERTIFICATECHAINMAXDEPTHOFGENERALOFPCCONFIG                                            STD_ON
#define KEYM_CERTIFICATEELEMENTOFPCCONFIG                                                           STD_ON
#define KEYM_CERTIFICATEELEMENTVERIFICATIONCALLOUTOFPCCONFIG                                        STD_ON
#define KEYM_CERTIFICATEEXTENSIONVALIDATIONENABLEDOFGENERALOFPCCONFIG                               STD_ON
#define KEYM_CERTIFICATEGETCURRENTTIMECALLOUTOFPCCONFIG                                             STD_ON
#define KEYM_CERTIFICATEINITVALUEINFOOFPCCONFIG                                                     STD_ON
#define KEYM_CERTIFICATEINITVALUEOFPCCONFIG                                                         STD_ON
#define KEYM_CERTIFICATEMANAGERENABLEDOFGENERALOFPCCONFIG                                           STD_ON
#define KEYM_CERTIFICATENAMEOFPCCONFIG                                                              STD_ON
#define KEYM_CERTIFICATEOFPCCONFIG                                                                  STD_ON
#define KEYM_CERTIFICATESIGNINGREQUESTENABLEDOFGENERALOFPCCONFIG                                    STD_ON
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDOFPCCONFIG                               STD_ON
#define KEYM_COMMONCERTDATAOFPCCONFIG                                                               STD_ON
#define KEYM_CRYPTOKEYPREPAREFUNCTIONENABLEDOFGENERALOFPCCONFIG                                     STD_ON
#define KEYM_CRYPTOKEYSTARTFINALIZEFUNCTIONENABLEDOFGENERALOFPCCONFIG                               STD_ON
#define KEYM_CRYPTOKEYVERIFYASYNCMODEOFGENERALOFPCCONFIG                                            STD_ON
#define KEYM_CRYPTOKEYVERIFYFUNCTIONENABLEDOFGENERALOFPCCONFIG                                      STD_ON
#define KEYM_CSMREMOTEINFOJOBREFOFGENERALOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.CsmRemoteInfoJobRefOfGeneral' Reason: 'Reference is not configured!' */
#define KEYM_CSMREMOTEINFOKEYREFOFGENERALOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.CsmRemoteInfoKeyRefOfGeneral' Reason: 'Reference is not configured!' */
#define KEYM_ELEMENTOIDOFPCCONFIG                                                                   STD_ON
#define KEYM_ELEMENTSTORAGEREFOFPCCONFIG                                                            STD_ON
#define KEYM_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define KEYM_FINALMAGICNUMBEROFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define KEYM_GENERALOFPCCONFIG                                                                      STD_ON
#define KEYM_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                                STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define KEYM_INITDATAHASHCODEOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define KEYM_KEYCERTNAMEMAXLENGTHOFGENERALOFPCCONFIG                                                STD_ON
#define KEYM_MAINFUNCTIONPERIODOFGENERALOFPCCONFIG                                                  STD_ON
#define KEYM_MAXLENGTHOFISSUERNAMEOFCREOFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.MaxLengthOfIssuerNameOfCRE' Reason: 'Parameter is not configured!' */
#define KEYM_MAXLENGTHOFSERIALNUMBEROFCREOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.MaxLengthOfSerialNumberOfCRE' Reason: 'Parameter is not configured!' */
#define KEYM_MAXNUMBEROFENTRIESOFCREOFPCCONFIG                                                      STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.MaxNumberOfEntriesOfCRE' Reason: 'Parameter is not configured!' */
#define KEYM_OCSPMAXLENGTHOFCERTIDHASHOFOCSPFORMATOFPCCONFIG                                        STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.OCSPMaxLengthOfCertIdHashOfOCSPFormat' Reason: 'Parameter is not configured!' */
#define KEYM_OCSPMAXLENGTHOFDISTINGUISHEDNAMEOFOCSPFORMATOFPCCONFIG                                 STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.OCSPMaxLengthOfDistinguishedNameOfOCSPFormat' Reason: 'Parameter is not configured!' */
#define KEYM_OCSPRESPONSEVALIDITYPERIODOFGENERALOFPCCONFIG                                          STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.OCSPResponseValidityPeriodOfGeneral' Reason: 'Parameter is not configured!' */
#define KEYM_PARSEMAXNESTINGLEVELOFGENERALOFPCCONFIG                                                STD_ON
#define KEYM_REMOTECREENABLEDOFPUBLISHEDINFORMATIONOFPCCONFIG                                       STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.RemoteCREEnabledOfPublishedInformation' Reason: 'Parameter is not configured!' */
#define KEYM_REMOTEOCSPENABLEDOFPUBLISHEDINFORMATIONOFPCCONFIG                                      STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.RemoteOCSPEnabledOfPublishedInformation' Reason: 'Parameter is not configured!' */
#define KEYM_SERVICECERTIFICATEFUNCTIONENABLEDOFGENERALOFPCCONFIG                                   STD_ON
#define KEYM_SERVICECERTIFICATERTECALLBACKNOTIFICATION440OFPCCONFIG                                 STD_ON
#define KEYM_SIZEOFCERTSTORAGEOFPCCONFIG                                                            STD_ON
#define KEYM_SIZEOFCERT_CERTINFOOFPCCONFIG                                                          STD_ON
#define KEYM_SIZEOFCERT_LEAFCERTSTOVERIFYOFPCCONFIG                                                 STD_ON
#define KEYM_SIZEOFCERT_LOCKOFPCCONFIG                                                              STD_ON
#define KEYM_SIZEOFCERT_STORAGETYPEOFPCCONFIG                                                       STD_ON
#define KEYM_SIZEOFCERT_VERIFYCHAINOFPCCONFIG                                                       STD_ON
#define KEYM_SIZEOFCERTIFICATEELEMENTOFPCCONFIG                                                     STD_ON
#define KEYM_SIZEOFCERTIFICATEELEMENTVERIFICATIONCALLOUTOFPCCONFIG                                  STD_ON
#define KEYM_SIZEOFCERTIFICATEGETCURRENTTIMECALLOUTOFPCCONFIG                                       STD_ON
#define KEYM_SIZEOFCERTIFICATEINITVALUEINFOOFPCCONFIG                                               STD_ON
#define KEYM_SIZEOFCERTIFICATEINITVALUEOFPCCONFIG                                                   STD_ON
#define KEYM_SIZEOFCERTIFICATENAMEOFPCCONFIG                                                        STD_ON
#define KEYM_SIZEOFCERTIFICATEOFPCCONFIG                                                            STD_ON
#define KEYM_SIZEOFCERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDOFPCCONFIG                         STD_ON
#define KEYM_SIZEOFCOMMONCERTDATAOFPCCONFIG                                                         STD_ON
#define KEYM_SIZEOFELEMENTOIDOFPCCONFIG                                                             STD_ON
#define KEYM_SIZEOFELEMENTSTORAGEREFOFPCCONFIG                                                      STD_ON
#define KEYM_SIZEOFGENERALOFPCCONFIG                                                                STD_ON
#define KEYM_SIZEOFSERVICECERTIFICATERTECALLBACKNOTIFICATION440OFPCCONFIG                           STD_ON
#define KEYM_VERSIONINFOAPIOFGENERALOFPCCONFIG                                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCMinNumericValueDefines  KeyM Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define KEYM_MIN_CERTSTORAGE                                                                        0u
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCMaxNumericValueDefines  KeyM Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define KEYM_MAX_CERTSTORAGE                                                                        255u
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCNoReferenceDefines  KeyM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define KEYM_NO_CERTSTORAGEENDIDXOFCERTIFICATE                                                      65535u
#define KEYM_NO_CERTSTORAGESTARTIDXOFCERTIFICATE                                                    65535u
#define KEYM_NO_CERTSTORAGEWRITTENLENGTHENDIDXOFCERTIFICATE                                         65535u
#define KEYM_NO_CERTSTORAGEWRITTENLENGTHSTARTIDXOFCERTIFICATE                                       65535u
#define KEYM_NO_CERTIFICATEELEMENTENDIDXOFCERTIFICATE                                               255u
#define KEYM_NO_CERTIFICATEELEMENTSTARTIDXOFCERTIFICATE                                             255u
#define KEYM_NO_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE                                    255u
#define KEYM_NO_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE                                            255u
#define KEYM_NO_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDIDXOFCERTIFICATE                      255u
#define KEYM_NO_SERVICECERTIFICATERTECALLBACKNOTIFICATION440IDXOFCERTIFICATE                        255u
#define KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT                        255u
#define KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT                                                255u
#define KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT                                              255u
#define KEYM_NO_CERTIFICATEINITVALUE                                                                255u
#define KEYM_NO_CERTIFICATEINITVALUEENDIDXOFCERTIFICATEINITVALUEINFO                                65535u
#define KEYM_NO_CERTIFICATEINITVALUESTARTIDXOFCERTIFICATEINITVALUEINFO                              65535u
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCMaskedBitDefines  KeyM Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define KEYM_CERTALLOWFLEXIBLEELEMENTORDEROFCERTIFICATE_MASK                                        0x80u
#define KEYM_CERTALLOWUNCONFIGUREDELEMENTSOFCERTIFICATE_MASK                                        0x40u
#define KEYM_CERTCSMSIGNATUREGENERATEJOBREFVALIDOFCERTIFICATE_MASK                                  0x20u
#define KEYM_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE_MASK                                    0x10u
#define KEYM_CSMKEYTARGETREFVALIDOFCERTIFICATE_MASK                                                 0x08u
#define KEYM_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE_MASK                                           0x04u
#define KEYM_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE_MASK                              0x02u
#define KEYM_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE_MASK                                0x01u
#define KEYM_HASITERATIONOFCERTIFICATEELEMENT_MASK                                                  0x02u
#define KEYM_OPTIONALOFCERTIFICATEELEMENT_MASK                                                      0x01u
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCIsReducedToDefineDefines  KeyM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define KEYM_ISDEF_CERTALGORITHMFAMILYOFCERTIFICATE                                                 STD_OFF
#define KEYM_ISDEF_CERTALLOWFLEXIBLEELEMENTORDEROFCERTIFICATE                                       STD_OFF
#define KEYM_ISDEF_CERTALLOWUNCONFIGUREDELEMENTSOFCERTIFICATE                                       STD_OFF
#define KEYM_ISDEF_CERTCSMSIGNATUREGENERATEJOBREFOFCERTIFICATE                                      STD_OFF
#define KEYM_ISDEF_CERTCSMSIGNATUREGENERATEJOBREFVALIDOFCERTIFICATE                                 STD_OFF
#define KEYM_ISDEF_CERTCSMSIGNATUREVERIFYJOBREFOFCERTIFICATE                                        STD_OFF
#define KEYM_ISDEF_CERTCSMSIGNATUREVERIFYKEYREFOFCERTIFICATE                                        STD_OFF
#define KEYM_ISDEF_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE                                   STD_OFF
#define KEYM_ISDEF_CERTFORMATTYPEOFCERTIFICATE                                                      STD_OFF
#define KEYM_ISDEF_CERTSTARTUPHANDLINGOFCERTIFICATE                                                 STD_OFF
#define KEYM_ISDEF_CERTSTORAGEENDIDXOFCERTIFICATE                                                   STD_OFF
#define KEYM_ISDEF_CERTSTORAGELENGTHOFCERTIFICATE                                                   STD_OFF
#define KEYM_ISDEF_CERTSTORAGESTARTIDXOFCERTIFICATE                                                 STD_OFF
#define KEYM_ISDEF_CERTSTORAGESTATUSENDIDXOFCERTIFICATE                                             STD_OFF
#define KEYM_ISDEF_CERTSTORAGESTATUSLENGTHOFCERTIFICATE                                             STD_OFF
#define KEYM_ISDEF_CERTSTORAGESTATUSSTARTIDXOFCERTIFICATE                                           STD_OFF
#define KEYM_ISDEF_CERTSTORAGEUSEDOFCERTIFICATE                                                     STD_OFF
#define KEYM_ISDEF_CERTSTORAGEWRITTENLENGTHENDIDXOFCERTIFICATE                                      STD_OFF
#define KEYM_ISDEF_CERTSTORAGEWRITTENLENGTHLENGTHOFCERTIFICATE                                      STD_OFF
#define KEYM_ISDEF_CERTSTORAGEWRITTENLENGTHSTARTIDXOFCERTIFICATE                                    STD_OFF
#define KEYM_ISDEF_CERTSTORAGEWRITTENLENGTHUSEDOFCERTIFICATE                                        STD_OFF
#define KEYM_ISDEF_CERTUPPERHIERARCHICALCERTREFIDXOFCERTIFICATE                                     STD_OFF
#define KEYM_ISDEF_CERTUPPERHIERARCHICALTYPEOFCERTIFICATE                                           STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTENDIDXOFCERTIFICATE                                            STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTLENGTHOFCERTIFICATE                                            STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTSTARTIDXOFCERTIFICATE                                          STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTUSEDOFCERTIFICATE                                              STD_OFF
#define KEYM_ISDEF_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE                                 STD_OFF
#define KEYM_ISDEF_CERTIFICATEGETCURRENTTIMECALLOUTUSEDOFCERTIFICATE                                STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE                                         STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUEINFOUSEDOFCERTIFICATE                                        STD_OFF
#define KEYM_ISDEF_CERTIFICATENAMEENDIDXOFCERTIFICATE                                               STD_OFF
#define KEYM_ISDEF_CERTIFICATENAMELENGTHOFCERTIFICATE                                               STD_OFF
#define KEYM_ISDEF_CERTIFICATENAMESTARTIDXOFCERTIFICATE                                             STD_OFF
#define KEYM_ISDEF_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDIDXOFCERTIFICATE                   STD_OFF
#define KEYM_ISDEF_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDUSEDOFCERTIFICATE                  STD_OFF
#define KEYM_ISDEF_CSMKEYTARGETREFOFCERTIFICATE                                                     STD_OFF
#define KEYM_ISDEF_CSMKEYTARGETREFVALIDOFCERTIFICATE                                                STD_OFF
#define KEYM_ISDEF_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE                                          STD_OFF
#define KEYM_ISDEF_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE                             STD_OFF
#define KEYM_ISDEF_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE                               STD_OFF
#define KEYM_ISDEF_MASKEDBITSOFCERTIFICATE                                                          STD_OFF
#define KEYM_ISDEF_MAXLENGTHOFCERTIFICATE                                                           STD_OFF
#define KEYM_ISDEF_REMOTECERTIFICATEIDOFCERTIFICATE                                                 STD_OFF
#define KEYM_ISDEF_SERVICECERTIFICATERTECALLBACKNOTIFICATION440IDXOFCERTIFICATE                     STD_OFF
#define KEYM_ISDEF_SERVICECERTIFICATERTECALLBACKNOTIFICATION440USEDOFCERTIFICATE                    STD_OFF
#define KEYM_ISDEF_STORAGEOFCERTIFICATE                                                             STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT                     STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTVERIFICATIONCALLOUTUSEDOFCERTIFICATEELEMENT                    STD_OFF
#define KEYM_ISDEF_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT                                             STD_OFF
#define KEYM_ISDEF_ELEMENTOIDLENGTHOFCERTIFICATEELEMENT                                             STD_OFF
#define KEYM_ISDEF_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT                                           STD_OFF
#define KEYM_ISDEF_ELEMENTOIDUSEDOFCERTIFICATEELEMENT                                               STD_OFF
#define KEYM_ISDEF_HASITERATIONOFCERTIFICATEELEMENT                                                 STD_OFF
#define KEYM_ISDEF_IDOFCERTIFICATEELEMENT                                                           STD_OFF
#define KEYM_ISDEF_MASKEDBITSOFCERTIFICATEELEMENT                                                   STD_OFF
#define KEYM_ISDEF_MAXLENGTHOFCERTIFICATEELEMENT                                                    STD_OFF
#define KEYM_ISDEF_OBJECTTYPEOFCERTIFICATEELEMENT                                                   STD_OFF
#define KEYM_ISDEF_OFSTRUCTUREOFCERTIFICATEELEMENT                                                  STD_OFF
#define KEYM_ISDEF_OPTIONALOFCERTIFICATEELEMENT                                                     STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTVERIFICATIONCALLOUT                                            STD_OFF
#define KEYM_ISDEF_CERTIFICATEGETCURRENTTIMECALLOUT                                                 STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUE                                                             STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUEENDIDXOFCERTIFICATEINITVALUEINFO                             STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUELENGTHOFCERTIFICATEINITVALUEINFO                             STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUESTARTIDXOFCERTIFICATEINITVALUEINFO                           STD_OFF
#define KEYM_ISDEF_CERTIFICATEINITVALUEUSEDOFCERTIFICATEINITVALUEINFO                               STD_OFF
#define KEYM_ISDEF_CERTIFICATENAME                                                                  STD_OFF
#define KEYM_ISDEF_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTID                                   STD_OFF
#define KEYM_ISDEF_ELEMENTOID                                                                       STD_OFF
#define KEYM_ISDEF_KEYMCSMREMOTEINFOJOBREFASYNCOFGENERAL                                            STD_OFF
#define KEYM_ISDEF_SERVICECERTIFICATERTECALLBACKNOTIFICATION440                                     STD_OFF
#define KEYM_ISDEF_CERTSTORAGEOFPCCONFIG                                                            STD_ON
#define KEYM_ISDEF_CERT_CERTINFOOFPCCONFIG                                                          STD_ON
#define KEYM_ISDEF_CERT_LEAFCERTSTOVERIFYOFPCCONFIG                                                 STD_ON
#define KEYM_ISDEF_CERT_LOCKOFPCCONFIG                                                              STD_ON
#define KEYM_ISDEF_CERT_STORAGETYPEOFPCCONFIG                                                       STD_ON
#define KEYM_ISDEF_CERT_VERIFYCHAINOFPCCONFIG                                                       STD_ON
#define KEYM_ISDEF_CERTIFICATEELEMENTOFPCCONFIG                                                     STD_ON
#define KEYM_ISDEF_CERTIFICATEELEMENTVERIFICATIONCALLOUTOFPCCONFIG                                  STD_ON
#define KEYM_ISDEF_CERTIFICATEGETCURRENTTIMECALLOUTOFPCCONFIG                                       STD_ON
#define KEYM_ISDEF_CERTIFICATEINITVALUEINFOOFPCCONFIG                                               STD_ON
#define KEYM_ISDEF_CERTIFICATEINITVALUEOFPCCONFIG                                                   STD_ON
#define KEYM_ISDEF_CERTIFICATENAMEOFPCCONFIG                                                        STD_ON
#define KEYM_ISDEF_CERTIFICATEOFPCCONFIG                                                            STD_ON
#define KEYM_ISDEF_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDOFPCCONFIG                         STD_ON
#define KEYM_ISDEF_COMMONCERTDATAOFPCCONFIG                                                         STD_ON
#define KEYM_ISDEF_ELEMENTOIDOFPCCONFIG                                                             STD_ON
#define KEYM_ISDEF_ELEMENTSTORAGEREFOFPCCONFIG                                                      STD_ON
#define KEYM_ISDEF_GENERALOFPCCONFIG                                                                STD_ON
#define KEYM_ISDEF_SERVICECERTIFICATERTECALLBACKNOTIFICATION440OFPCCONFIG                           STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCEqualsAlwaysToDefines  KeyM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define KEYM_EQ2_CERTALGORITHMFAMILYOFCERTIFICATE                                                   
#define KEYM_EQ2_CERTALLOWFLEXIBLEELEMENTORDEROFCERTIFICATE                                         
#define KEYM_EQ2_CERTALLOWUNCONFIGUREDELEMENTSOFCERTIFICATE                                         
#define KEYM_EQ2_CERTCSMSIGNATUREGENERATEJOBREFOFCERTIFICATE                                        
#define KEYM_EQ2_CERTCSMSIGNATUREGENERATEJOBREFVALIDOFCERTIFICATE                                   
#define KEYM_EQ2_CERTCSMSIGNATUREVERIFYJOBREFOFCERTIFICATE                                          
#define KEYM_EQ2_CERTCSMSIGNATUREVERIFYKEYREFOFCERTIFICATE                                          
#define KEYM_EQ2_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE                                     
#define KEYM_EQ2_CERTFORMATTYPEOFCERTIFICATE                                                        
#define KEYM_EQ2_CERTSTARTUPHANDLINGOFCERTIFICATE                                                   
#define KEYM_EQ2_CERTSTORAGEENDIDXOFCERTIFICATE                                                     
#define KEYM_EQ2_CERTSTORAGELENGTHOFCERTIFICATE                                                     
#define KEYM_EQ2_CERTSTORAGESTARTIDXOFCERTIFICATE                                                   
#define KEYM_EQ2_CERTSTORAGESTATUSENDIDXOFCERTIFICATE                                               
#define KEYM_EQ2_CERTSTORAGESTATUSLENGTHOFCERTIFICATE                                               
#define KEYM_EQ2_CERTSTORAGESTATUSSTARTIDXOFCERTIFICATE                                             
#define KEYM_EQ2_CERTSTORAGEUSEDOFCERTIFICATE                                                       
#define KEYM_EQ2_CERTSTORAGEWRITTENLENGTHENDIDXOFCERTIFICATE                                        
#define KEYM_EQ2_CERTSTORAGEWRITTENLENGTHLENGTHOFCERTIFICATE                                        
#define KEYM_EQ2_CERTSTORAGEWRITTENLENGTHSTARTIDXOFCERTIFICATE                                      
#define KEYM_EQ2_CERTSTORAGEWRITTENLENGTHUSEDOFCERTIFICATE                                          
#define KEYM_EQ2_CERTUPPERHIERARCHICALCERTREFIDXOFCERTIFICATE                                       
#define KEYM_EQ2_CERTUPPERHIERARCHICALTYPEOFCERTIFICATE                                             
#define KEYM_EQ2_CERTIFICATEELEMENTENDIDXOFCERTIFICATE                                              
#define KEYM_EQ2_CERTIFICATEELEMENTLENGTHOFCERTIFICATE                                              
#define KEYM_EQ2_CERTIFICATEELEMENTSTARTIDXOFCERTIFICATE                                            
#define KEYM_EQ2_CERTIFICATEELEMENTUSEDOFCERTIFICATE                                                
#define KEYM_EQ2_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE                                   
#define KEYM_EQ2_CERTIFICATEGETCURRENTTIMECALLOUTUSEDOFCERTIFICATE                                  
#define KEYM_EQ2_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE                                           
#define KEYM_EQ2_CERTIFICATEINITVALUEINFOUSEDOFCERTIFICATE                                          
#define KEYM_EQ2_CERTIFICATENAMEENDIDXOFCERTIFICATE                                                 
#define KEYM_EQ2_CERTIFICATENAMELENGTHOFCERTIFICATE                                                 
#define KEYM_EQ2_CERTIFICATENAMESTARTIDXOFCERTIFICATE                                               
#define KEYM_EQ2_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDIDXOFCERTIFICATE                     
#define KEYM_EQ2_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDUSEDOFCERTIFICATE                    
#define KEYM_EQ2_CSMKEYTARGETREFOFCERTIFICATE                                                       
#define KEYM_EQ2_CSMKEYTARGETREFVALIDOFCERTIFICATE                                                  
#define KEYM_EQ2_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE                                            
#define KEYM_EQ2_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE                               
#define KEYM_EQ2_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE                                 
#define KEYM_EQ2_MASKEDBITSOFCERTIFICATE                                                            
#define KEYM_EQ2_MAXLENGTHOFCERTIFICATE                                                             
#define KEYM_EQ2_REMOTECERTIFICATEIDOFCERTIFICATE                                                   
#define KEYM_EQ2_SERVICECERTIFICATERTECALLBACKNOTIFICATION440IDXOFCERTIFICATE                       
#define KEYM_EQ2_SERVICECERTIFICATERTECALLBACKNOTIFICATION440USEDOFCERTIFICATE                      
#define KEYM_EQ2_STORAGEOFCERTIFICATE                                                               
#define KEYM_EQ2_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT                       
#define KEYM_EQ2_CERTIFICATEELEMENTVERIFICATIONCALLOUTUSEDOFCERTIFICATEELEMENT                      
#define KEYM_EQ2_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT                                               
#define KEYM_EQ2_ELEMENTOIDLENGTHOFCERTIFICATEELEMENT                                               
#define KEYM_EQ2_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT                                             
#define KEYM_EQ2_ELEMENTOIDUSEDOFCERTIFICATEELEMENT                                                 
#define KEYM_EQ2_HASITERATIONOFCERTIFICATEELEMENT                                                   
#define KEYM_EQ2_IDOFCERTIFICATEELEMENT                                                             
#define KEYM_EQ2_MASKEDBITSOFCERTIFICATEELEMENT                                                     
#define KEYM_EQ2_MAXLENGTHOFCERTIFICATEELEMENT                                                      
#define KEYM_EQ2_OBJECTTYPEOFCERTIFICATEELEMENT                                                     
#define KEYM_EQ2_OFSTRUCTUREOFCERTIFICATEELEMENT                                                    
#define KEYM_EQ2_OPTIONALOFCERTIFICATEELEMENT                                                       
#define KEYM_EQ2_CERTIFICATEELEMENTVERIFICATIONCALLOUT                                              
#define KEYM_EQ2_CERTIFICATEGETCURRENTTIMECALLOUT                                                   
#define KEYM_EQ2_CERTIFICATEINITVALUE                                                               
#define KEYM_EQ2_CERTIFICATEINITVALUEENDIDXOFCERTIFICATEINITVALUEINFO                               
#define KEYM_EQ2_CERTIFICATEINITVALUELENGTHOFCERTIFICATEINITVALUEINFO                               
#define KEYM_EQ2_CERTIFICATEINITVALUESTARTIDXOFCERTIFICATEINITVALUEINFO                             
#define KEYM_EQ2_CERTIFICATEINITVALUEUSEDOFCERTIFICATEINITVALUEINFO                                 
#define KEYM_EQ2_CERTIFICATENAME                                                                    
#define KEYM_EQ2_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTID                                     
#define KEYM_EQ2_ELEMENTOID                                                                         
#define KEYM_EQ2_KEYMCSMREMOTEINFOJOBREFASYNCOFGENERAL                                              
#define KEYM_EQ2_SERVICECERTIFICATERTECALLBACKNOTIFICATION440                                       
#define KEYM_EQ2_CERTSTORAGEOFPCCONFIG                                                              KeyM_CertStorage.raw
#define KEYM_EQ2_CERT_CERTINFOOFPCCONFIG                                                            KeyM_Cert_CertInfo
#define KEYM_EQ2_CERT_LEAFCERTSTOVERIFYOFPCCONFIG                                                   KeyM_Cert_LeafCertsToVerify
#define KEYM_EQ2_CERT_LOCKOFPCCONFIG                                                                KeyM_Cert_Lock
#define KEYM_EQ2_CERT_STORAGETYPEOFPCCONFIG                                                         KeyM_Cert_StorageType
#define KEYM_EQ2_CERT_VERIFYCHAINOFPCCONFIG                                                         KeyM_Cert_VerifyChain
#define KEYM_EQ2_CERTIFICATEELEMENTOFPCCONFIG                                                       KeyM_CertificateElement
#define KEYM_EQ2_CERTIFICATEELEMENTVERIFICATIONCALLOUTOFPCCONFIG                                    KeyM_CertificateElementVerificationCallout
#define KEYM_EQ2_CERTIFICATEGETCURRENTTIMECALLOUTOFPCCONFIG                                         KeyM_CertificateGetCurrentTimeCallout
#define KEYM_EQ2_CERTIFICATEINITVALUEINFOOFPCCONFIG                                                 KeyM_CertificateInitValueInfo
#define KEYM_EQ2_CERTIFICATEINITVALUEOFPCCONFIG                                                     KeyM_CertificateInitValue
#define KEYM_EQ2_CERTIFICATENAMEOFPCCONFIG                                                          KeyM_CertificateName
#define KEYM_EQ2_CERTIFICATEOFPCCONFIG                                                              KeyM_Certificate
#define KEYM_EQ2_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDOFPCCONFIG                           KeyM_CertificateVerifyCallbackNotificationWithoutId
#define KEYM_EQ2_COMMONCERTDATAOFPCCONFIG                                                           KeyM_CommonCertData.raw
#define KEYM_EQ2_ELEMENTOIDOFPCCONFIG                                                               KeyM_ElementOid
#define KEYM_EQ2_ELEMENTSTORAGEREFOFPCCONFIG                                                        KeyM_ElementStorageRef
#define KEYM_EQ2_GENERALOFPCCONFIG                                                                  KeyM_General
#define KEYM_EQ2_SERVICECERTIFICATERTECALLBACKNOTIFICATION440OFPCCONFIG                             KeyM_ServiceCertificateRteCallbackNotification440
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCSymbolicInitializationPointers  KeyM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define KeyM_Config_Ptr                                                                             NULL_PTR  /**< symbolic identifier which shall be used to initialize 'KeyM' */
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCInitializationSymbols  KeyM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define KeyM_Config                                                                                 NULL_PTR  /**< symbolic identifier which could be used to initialize 'KeyM */
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCGeneral  KeyM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define KEYM_CHECK_INIT_POINTER                                                                     STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define KEYM_FINAL_MAGIC_NUMBER                                                                     0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of KeyM */
#define KEYM_INDIVIDUAL_POSTBUILD                                                                   STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'KeyM' is not configured to be postbuild capable. */
#define KEYM_INIT_DATA                                                                              KEYM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define KEYM_INIT_DATA_HASH_CODE                                                                    -492589632  /**< the precompile constant to validate the initialization structure at initialization time of KeyM with a hashcode. The seed value is '0xFF1Eu' */
#define KEYM_USE_ECUM_BSW_ERROR_HOOK                                                                STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define KEYM_USE_INIT_POINTER                                                                       STD_OFF  /**< STD_ON if the init pointer KeyM shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  KeyMPBDataSwitches  KeyM Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define KEYM_PBCONFIG                                                                               STD_OFF  /**< Deactivateable: 'KeyM_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define KEYM_LTCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'KeyM_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define KEYM_PCCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'KeyM_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  KeyMPCGetConstantDuplicatedRootDataMacros  KeyM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define KeyM_GetCertStorageOfPCConfig()                                                             KeyM_CertStorage.raw  /**< the pointer to KeyM_CertStorage */
#define KeyM_GetCert_CertInfoOfPCConfig()                                                           KeyM_Cert_CertInfo  /**< the pointer to KeyM_Cert_CertInfo */
#define KeyM_GetCert_LeafCertsToVerifyOfPCConfig()                                                  KeyM_Cert_LeafCertsToVerify  /**< the pointer to KeyM_Cert_LeafCertsToVerify */
#define KeyM_GetCert_LockOfPCConfig()                                                               KeyM_Cert_Lock  /**< the pointer to KeyM_Cert_Lock */
#define KeyM_GetCert_StorageTypeOfPCConfig()                                                        KeyM_Cert_StorageType  /**< the pointer to KeyM_Cert_StorageType */
#define KeyM_GetCert_VerifyChainOfPCConfig()                                                        KeyM_Cert_VerifyChain  /**< the pointer to KeyM_Cert_VerifyChain */
#define KeyM_GetCertificateChainMaxDepthOfGeneralOfPCConfig()                                       4u
#define KeyM_GetCertificateElementOfPCConfig()                                                      KeyM_CertificateElement  /**< the pointer to KeyM_CertificateElement */
#define KeyM_GetCertificateElementVerificationCalloutOfPCConfig()                                   KeyM_CertificateElementVerificationCallout  /**< the pointer to KeyM_CertificateElementVerificationCallout */
#define KeyM_IsCertificateExtensionValidationEnabledOfGeneralOfPCConfig()                           (((FALSE)) != FALSE)
#define KeyM_GetCertificateGetCurrentTimeCalloutOfPCConfig()                                        KeyM_CertificateGetCurrentTimeCallout  /**< the pointer to KeyM_CertificateGetCurrentTimeCallout */
#define KeyM_GetCertificateInitValueInfoOfPCConfig()                                                KeyM_CertificateInitValueInfo  /**< the pointer to KeyM_CertificateInitValueInfo */
#define KeyM_GetCertificateInitValueOfPCConfig()                                                    KeyM_CertificateInitValue  /**< the pointer to KeyM_CertificateInitValue */
#define KeyM_IsCertificateManagerEnabledOfGeneralOfPCConfig()                                       (((TRUE)) != FALSE)
#define KeyM_GetCertificateNameOfPCConfig()                                                         KeyM_CertificateName  /**< the pointer to KeyM_CertificateName */
#define KeyM_GetCertificateOfPCConfig()                                                             KeyM_Certificate  /**< the pointer to KeyM_Certificate */
#define KeyM_IsCertificateSigningRequestEnabledOfGeneralOfPCConfig()                                (((TRUE)) != FALSE)
#define KeyM_GetCertificateVerifyCallbackNotificationWithoutIdOfPCConfig()                          KeyM_CertificateVerifyCallbackNotificationWithoutId  /**< the pointer to KeyM_CertificateVerifyCallbackNotificationWithoutId */
#define KeyM_GetCommonCertDataOfPCConfig()                                                          KeyM_CommonCertData.raw  /**< the pointer to KeyM_CommonCertData */
#define KeyM_IsCryptoKeyPrepareFunctionEnabledOfGeneralOfPCConfig()                                 (((FALSE)) != FALSE)
#define KeyM_IsCryptoKeyStartFinalizeFunctionEnabledOfGeneralOfPCConfig()                           (((FALSE)) != FALSE)
#define KeyM_IsCryptoKeyVerifyAsyncModeOfGeneralOfPCConfig()                                        (((FALSE)) != FALSE)
#define KeyM_IsCryptoKeyVerifyFunctionEnabledOfGeneralOfPCConfig()                                  (((FALSE)) != FALSE)
#define KeyM_GetElementOidOfPCConfig()                                                              KeyM_ElementOid  /**< the pointer to KeyM_ElementOid */
#define KeyM_GetElementStorageRefOfPCConfig()                                                       KeyM_ElementStorageRef  /**< the pointer to KeyM_ElementStorageRef */
#define KeyM_GetGeneralOfPCConfig()                                                                 KeyM_General  /**< the pointer to KeyM_General */
#define KeyM_GetKeyCertNameMaxLengthOfGeneralOfPCConfig()                                           30u
#define KeyM_GetMainFunctionPeriodOfGeneralOfPCConfig()                                             1u
#define KeyM_GetParseMaxNestingLevelOfGeneralOfPCConfig()                                           20u
#define KeyM_IsServiceCertificateFunctionEnabledOfGeneralOfPCConfig()                               (((TRUE)) != FALSE)
#define KeyM_GetServiceCertificateRteCallbackNotification440OfPCConfig()                            KeyM_ServiceCertificateRteCallbackNotification440  /**< the pointer to KeyM_ServiceCertificateRteCallbackNotification440 */
#define KeyM_GetSizeOfCertStorageOfPCConfig()                                                       8032u  /**< the number of accomplishable value elements in KeyM_CertStorage */
#define KeyM_GetSizeOfCertificateElementOfPCConfig()                                                134u  /**< the number of accomplishable value elements in KeyM_CertificateElement */
#define KeyM_GetSizeOfCertificateElementVerificationCalloutOfPCConfig()                             1u  /**< the number of accomplishable value elements in KeyM_CertificateElementVerificationCallout */
#define KeyM_GetSizeOfCertificateGetCurrentTimeCalloutOfPCConfig()                                  1u  /**< the number of accomplishable value elements in KeyM_CertificateGetCurrentTimeCallout */
#define KeyM_GetSizeOfCertificateInitValueInfoOfPCConfig()                                          1u  /**< the number of accomplishable value elements in KeyM_CertificateInitValueInfo */
#define KeyM_GetSizeOfCertificateInitValueOfPCConfig()                                              292u  /**< the number of accomplishable value elements in KeyM_CertificateInitValue */
#define KeyM_GetSizeOfCertificateNameOfPCConfig()                                                   174u  /**< the number of accomplishable value elements in KeyM_CertificateName */
#define KeyM_GetSizeOfCertificateOfPCConfig()                                                       8u  /**< the number of accomplishable value elements in KeyM_Certificate */
#define KeyM_GetSizeOfCertificateVerifyCallbackNotificationWithoutIdOfPCConfig()                    8u  /**< the number of accomplishable value elements in KeyM_CertificateVerifyCallbackNotificationWithoutId */
#define KeyM_GetSizeOfCommonCertDataOfPCConfig()                                                    8u  /**< the number of accomplishable value elements in KeyM_CommonCertData */
#define KeyM_GetSizeOfElementOidOfPCConfig()                                                        84u  /**< the number of accomplishable value elements in KeyM_ElementOid */
#define KeyM_GetSizeOfGeneralOfPCConfig()                                                           1u  /**< the number of accomplishable value elements in KeyM_General */
#define KeyM_GetSizeOfServiceCertificateRteCallbackNotification440OfPCConfig()                      8u  /**< the number of accomplishable value elements in KeyM_ServiceCertificateRteCallbackNotification440 */
#define KeyM_IsVersionInfoApiOfGeneralOfPCConfig()                                                  (((FALSE)) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCGetDuplicatedRootDataMacros  KeyM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define KeyM_GetSizeOfCert_CertInfoOfPCConfig()                                                     KeyM_GetSizeOfCertificateOfPCConfig()  /**< the number of accomplishable value elements in KeyM_Cert_CertInfo */
#define KeyM_GetSizeOfCert_LeafCertsToVerifyOfPCConfig()                                            KeyM_GetSizeOfCertificateOfPCConfig()  /**< the number of accomplishable value elements in KeyM_Cert_LeafCertsToVerify */
#define KeyM_GetSizeOfCert_LockOfPCConfig()                                                         KeyM_GetSizeOfCertificateOfPCConfig()  /**< the number of accomplishable value elements in KeyM_Cert_Lock */
#define KeyM_GetSizeOfCert_StorageTypeOfPCConfig()                                                  KeyM_GetSizeOfCertificateOfPCConfig()  /**< the number of accomplishable value elements in KeyM_Cert_StorageType */
#define KeyM_GetSizeOfCert_VerifyChainOfPCConfig()                                                  KeyM_GetSizeOfCertificateOfPCConfig()  /**< the number of accomplishable value elements in KeyM_Cert_VerifyChain */
#define KeyM_GetSizeOfElementStorageRefOfPCConfig()                                                 KeyM_GetSizeOfCertificateElementOfPCConfig()  /**< the number of accomplishable value elements in KeyM_ElementStorageRef */
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/* Enum literals for KeyM_CertificateStructureType */
# define KEYM_CERTIFICATE_ATTRIBUTE                                                                 0x00u
# define KEYM_CERTIFICATE_ATTRIBUTE_HOLDER                                                          0x01u
# define KEYM_CERTIFICATE_EXTENSION                                                                 0x02u
# define KEYM_CERTIFICATE_ISSUER_NAME                                                               0x03u
# define KEYM_CERTIFICATE_ISSUER_UNIQUE_IDENTIFIER                                                  0x04u
# define KEYM_CERTIFICATE_REVOCATION_LIST                                                           0x05u
# define KEYM_CERTIFICATE_SERIAL_NUMBER                                                             0x06u
# define KEYM_CERTIFICATE_SIGNATURE                                                                 0x07u
# define KEYM_CERTIFICATE_SIGNATURE_ALGORITHM                                                       0x08u
# define KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID                                                    0x09u
# define KEYM_CERTIFICATE_SUBJECT_NAME                                                              0x0Au
# define KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM                              0x0Bu
# define KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY                                0x0Cu
# define KEYM_CERTIFICATE_SUBJECT_UNIQUE_IDENTIFIER                                                 0x0Du
# define KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER                                                 0x0Eu
# define KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE                                                0x0Fu
# define KEYM_CERTIFICATE_VERSION_NUMBER                                                            0x10u
# define KEYM_CERTIFICATE_SUBJECT_AUTHORIZATION                                                     0x11u
# define KEYM_REVOKED_CERTIFICATES                                                                  0x12u

/* Structure Types */
typedef struct
{
  uint16 offset;
  uint16 length;
} KeyM_Ans1_Element_Ref_Type;

/* Certificate Group Verify Callback Notification Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_APPL_CODE, KeyM_CertificateGroupVerifyCallbackNotificationFctPtrType)(KeyM_CertificateGroupIdType GroupId, KeyM_CertificateGroupStatusType Result);

/* BSW Certificate Verify Callback Notification Typedef / AUTOSAR R22-11+ Rte Certificate Verify Callback Notification Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_APPL_CODE, KeyM_CertificateVerifyCallbackNotificationWithIdFctPtrType)(KeyM_CertificateIdType CertId, KeyM_CertificateStatusType Result);

/* Service Certificate Callback Notification Typedef */
typedef P2FUNC(void, KEYM_APPL_CODE, KeyM_ServiceCertificateCallbackNotificationFctPtrType)(KeyM_CertificateIdType CertId, KeyM_CertificateStatusType Result, uint16 ResultDataLength, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResultDataPtr);

/* Certificate Element Verification Callout Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_APPL_CODE, KeyM_CertificateElementVerificationCalloutFctPtrType)(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertElementData, uint32 CertElementDataLength);

/* Certificate Set Key Callout Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_APPL_CODE, KeyM_CertificateSetKeyCalloutFctPtrType)(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint32 csmKeyId, P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertElementData, uint32 CertElementDataLength);

/* Certificate Init Callout Typedef */
typedef P2FUNC(void, KEYM_APPL_CODE, KeyM_CertificateInitCalloutFctPtrType)(KeyM_CertificateIdType CertId, P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr);

/* Certificate Get Current Time Callout Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_APPL_CODE, KeyM_CertificateGetCurrentTimeCalloutFctPtrType)(KeyM_CertificateIdType CertId, P2VAR(uint64, AUTOMATIC, KEYM_APPL_VAR) timeStamp);

/* Rte Certificate Callback Notification Typedef according to AUTOSAR 4.4.0 */
typedef P2FUNC(Std_ReturnType, KEYM_RTE_CODE, KeyM_ServiceCertificateRteCallbackNotification440FctPtrType)(KeyM_CertificateStatusType Result, uint16 ResultDataLength, P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) ResultDataPtr);

/* Rte Certificate Callback Notification Typedef according to AUTOSAR R22-11 */
typedef P2FUNC(Std_ReturnType, KEYM_RTE_CODE, KeyM_ServiceCertificateRteCallbackNotification2211FctPtrType)(KeyM_CertificateStatusType Result, uint16 ResultDataLength, P2CONST(void, AUTOMATIC, KEYM_APPL_DATA) ResultDataPtr);

/* AUTOSAR R21-11 and below Rte Certificate Verify Callback Notification Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_RTE_CODE, KeyM_CertificateVerifyCallbackNotificationWithoutIdFctPtrType)(KeyM_CertificateStatusType Result);



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  KeyMPCIterableTypes  KeyM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate KeyM_CertStorage */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint32_least KeyM_CertStorageIterType;

/**   \brief  type used to iterate KeyM_Certificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificate() } \endspec */ 
typedef uint8_least KeyM_CertificateIterType;

/**   \brief  type used to iterate KeyM_CertificateElement */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateElement() } \endspec */ 
typedef uint8_least KeyM_CertificateElementIterType;

/**   \brief  type used to iterate KeyM_CertificateElementVerificationCallout */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateElementVerificationCallout() } \endspec */ 
typedef uint8_least KeyM_CertificateElementVerificationCalloutIterType;

/**   \brief  type used to iterate KeyM_CertificateGetCurrentTimeCallout */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateGetCurrentTimeCallout() } \endspec */ 
typedef uint8_least KeyM_CertificateGetCurrentTimeCalloutIterType;

/**   \brief  type used to iterate KeyM_CertificateInitValue */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateInitValue() } \endspec */ 
typedef uint16_least KeyM_CertificateInitValueIterType;

/**   \brief  type used to iterate KeyM_CertificateInitValueInfo */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateInitValueInfo() } \endspec */ 
typedef uint8_least KeyM_CertificateInitValueInfoIterType;

/**   \brief  type used to iterate KeyM_CertificateName */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateName() } \endspec */ 
typedef uint8_least KeyM_CertificateNameIterType;

/**   \brief  type used to iterate KeyM_CertificateVerifyCallbackNotificationWithoutId */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateVerifyCallbackNotificationWithoutId() } \endspec */ 
typedef uint8_least KeyM_CertificateVerifyCallbackNotificationWithoutIdIterType;

/**   \brief  type used to iterate KeyM_CommonCertData */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCommonCertData() } \endspec */ 
typedef uint8_least KeyM_CommonCertDataIterType;

/**   \brief  type used to iterate KeyM_ElementOid */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfElementOid() } \endspec */ 
typedef uint8_least KeyM_ElementOidIterType;

/**   \brief  type used to iterate KeyM_General */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfGeneral() } \endspec */ 
typedef uint8_least KeyM_GeneralIterType;

/**   \brief  type used to iterate KeyM_ServiceCertificateRteCallbackNotification440 */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfServiceCertificateRteCallbackNotification440() } \endspec */ 
typedef uint8_least KeyM_ServiceCertificateRteCallbackNotification440IterType;

/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCIterableTypesWithSizeRelations  KeyM Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate KeyM_Cert_CertInfo */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_CertInfo() } \endspec */ 
typedef KeyM_CertificateIterType KeyM_Cert_CertInfoIterType;

/**   \brief  type used to iterate KeyM_Cert_LeafCertsToVerify */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_LeafCertsToVerify() } \endspec */ 
typedef KeyM_CertificateIterType KeyM_Cert_LeafCertsToVerifyIterType;

/**   \brief  type used to iterate KeyM_Cert_Lock */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_Lock() } \endspec */ 
typedef KeyM_CertificateIterType KeyM_Cert_LockIterType;

/**   \brief  type used to iterate KeyM_Cert_StorageType */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_StorageType() } \endspec */ 
typedef KeyM_CertificateIterType KeyM_Cert_StorageTypeIterType;

/**   \brief  type used to iterate KeyM_Cert_VerifyChain */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_VerifyChain() } \endspec */ 
typedef KeyM_CertificateIterType KeyM_Cert_VerifyChainIterType;

/**   \brief  type used to iterate KeyM_ElementStorageRef */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfElementStorageRef() } \endspec */ 
typedef KeyM_CertificateElementIterType KeyM_ElementStorageRefIterType;

/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCValueTypes  KeyM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for KeyM_CertStorage */
typedef uint8 KeyM_CertStorageType;

/**   \brief  value based type definition for KeyM_Cert_Lock */
typedef boolean KeyM_Cert_LockType;

/**   \brief  value based type definition for KeyM_CertAlgorithmFamilyOfCertificate */
typedef uint8 KeyM_CertAlgorithmFamilyOfCertificateType;

/**   \brief  value based type definition for KeyM_CertAllowFlexibleElementOrderOfCertificate */
typedef boolean KeyM_CertAllowFlexibleElementOrderOfCertificateType;

/**   \brief  value based type definition for KeyM_CertAllowUnconfiguredElementsOfCertificate */
typedef boolean KeyM_CertAllowUnconfiguredElementsOfCertificateType;

/**   \brief  value based type definition for KeyM_CertCsmSignatureGenerateJobRefOfCertificate */
typedef uint32 KeyM_CertCsmSignatureGenerateJobRefOfCertificateType;

/**   \brief  value based type definition for KeyM_CertCsmSignatureGenerateJobRefValidOfCertificate */
typedef boolean KeyM_CertCsmSignatureGenerateJobRefValidOfCertificateType;

/**   \brief  value based type definition for KeyM_CertCsmSignatureVerifyJobRefOfCertificate */
typedef uint32 KeyM_CertCsmSignatureVerifyJobRefOfCertificateType;

/**   \brief  value based type definition for KeyM_CertCsmSignatureVerifyKeyRefOfCertificate */
typedef uint32 KeyM_CertCsmSignatureVerifyKeyRefOfCertificateType;

/**   \brief  value based type definition for KeyM_CertCsmSignatureVerifyKeyRefValidOfCertificate */
typedef boolean KeyM_CertCsmSignatureVerifyKeyRefValidOfCertificateType;

/**   \brief  value based type definition for KeyM_CertFormatTypeOfCertificate */
typedef uint8 KeyM_CertFormatTypeOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStartUpHandlingOfCertificate */
typedef uint8 KeyM_CertStartUpHandlingOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageEndIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint16 KeyM_CertStorageEndIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageLengthOfCertificate */
typedef uint16 KeyM_CertStorageLengthOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageStartIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint16 KeyM_CertStorageStartIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageStatusEndIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint16 KeyM_CertStorageStatusEndIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageStatusLengthOfCertificate */
typedef uint8 KeyM_CertStorageStatusLengthOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageStatusStartIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint16 KeyM_CertStorageStatusStartIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageUsedOfCertificate */
typedef boolean KeyM_CertStorageUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageWrittenLengthEndIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint16 KeyM_CertStorageWrittenLengthEndIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageWrittenLengthLengthOfCertificate */
typedef uint8 KeyM_CertStorageWrittenLengthLengthOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageWrittenLengthStartIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertStorage() } \endspec */ 
typedef uint16 KeyM_CertStorageWrittenLengthStartIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertStorageWrittenLengthUsedOfCertificate */
typedef boolean KeyM_CertStorageWrittenLengthUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_CertUpperHierarchicalCertRefIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificate() } \endspec */ 
typedef uint8 KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertUpperHierarchicalTypeOfCertificate */
typedef uint8 KeyM_CertUpperHierarchicalTypeOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateElementEndIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateElement() } \endspec */ 
typedef uint8 KeyM_CertificateElementEndIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateElementLengthOfCertificate */
typedef uint8 KeyM_CertificateElementLengthOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateElementStartIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateElement() } \endspec */ 
typedef uint8 KeyM_CertificateElementStartIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateElementUsedOfCertificate */
typedef boolean KeyM_CertificateElementUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateGetCurrentTimeCallout() } \endspec */ 
typedef uint8 KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateGetCurrentTimeCalloutUsedOfCertificate */
typedef boolean KeyM_CertificateGetCurrentTimeCalloutUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateInitValueInfoIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateInitValueInfo() } \endspec */ 
typedef uint8 KeyM_CertificateInitValueInfoIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateInitValueInfoUsedOfCertificate */
typedef boolean KeyM_CertificateInitValueInfoUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateNameEndIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateName() } \endspec */ 
typedef uint8 KeyM_CertificateNameEndIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateNameLengthOfCertificate */
typedef uint8 KeyM_CertificateNameLengthOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateNameStartIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateName() } \endspec */ 
typedef uint8 KeyM_CertificateNameStartIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateVerifyCallbackNotificationWithoutIdIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateVerifyCallbackNotificationWithoutId() } \endspec */ 
typedef uint8 KeyM_CertificateVerifyCallbackNotificationWithoutIdIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateVerifyCallbackNotificationWithoutIdUsedOfCertificate */
typedef boolean KeyM_CertificateVerifyCallbackNotificationWithoutIdUsedOfCertificateType;

/**   \brief  value based type definition for KeyM_CsmKeyTargetRefOfCertificate */
typedef uint32 KeyM_CsmKeyTargetRefOfCertificateType;

/**   \brief  value based type definition for KeyM_CsmKeyTargetRefValidOfCertificate */
typedef boolean KeyM_CsmKeyTargetRefValidOfCertificateType;

/**   \brief  value based type definition for KeyM_KeyMCertCsmHashJobRefAsyncOfCertificate */
typedef boolean KeyM_KeyMCertCsmHashJobRefAsyncOfCertificateType;

/**   \brief  value based type definition for KeyM_KeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate */
typedef boolean KeyM_KeyMCertCsmSignatureGenerateJobRefAsyncOfCertificateType;

/**   \brief  value based type definition for KeyM_KeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate */
typedef boolean KeyM_KeyMCertCsmSignatureVerifyJobRefAsyncOfCertificateType;

/**   \brief  value based type definition for KeyM_MaskedBitsOfCertificate */
typedef uint8 KeyM_MaskedBitsOfCertificateType;

/**   \brief  value based type definition for KeyM_MaxLengthOfCertificate */
typedef uint16 KeyM_MaxLengthOfCertificateType;

/**   \brief  value based type definition for KeyM_RemoteCertificateIdOfCertificate */
typedef uint8 KeyM_RemoteCertificateIdOfCertificateType;

/**   \brief  value based type definition for KeyM_ServiceCertificateRteCallbackNotification440IdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfServiceCertificateRteCallbackNotification440() } \endspec */ 
typedef uint8 KeyM_ServiceCertificateRteCallbackNotification440IdxOfCertificateType;

/**   \brief  value based type definition for KeyM_ServiceCertificateRteCallbackNotification440UsedOfCertificate */
typedef boolean KeyM_ServiceCertificateRteCallbackNotification440UsedOfCertificateType;

/**   \brief  value based type definition for KeyM_StorageOfCertificate */
typedef uint8 KeyM_StorageOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateChainMaxDepthOfGeneral */
typedef uint8 KeyM_CertificateChainMaxDepthOfGeneralType;

/**   \brief  value based type definition for KeyM_CertificateElementVerificationCalloutIdxOfCertificateElement */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateElementVerificationCallout() } \endspec */ 
typedef uint8 KeyM_CertificateElementVerificationCalloutIdxOfCertificateElementType;

/**   \brief  value based type definition for KeyM_CertificateElementVerificationCalloutUsedOfCertificateElement */
typedef boolean KeyM_CertificateElementVerificationCalloutUsedOfCertificateElementType;

/**   \brief  value based type definition for KeyM_ElementOidEndIdxOfCertificateElement */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfElementOid() } \endspec */ 
typedef uint8 KeyM_ElementOidEndIdxOfCertificateElementType;

/**   \brief  value based type definition for KeyM_ElementOidLengthOfCertificateElement */
typedef uint8 KeyM_ElementOidLengthOfCertificateElementType;

/**   \brief  value based type definition for KeyM_ElementOidStartIdxOfCertificateElement */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfElementOid() } \endspec */ 
typedef uint8 KeyM_ElementOidStartIdxOfCertificateElementType;

/**   \brief  value based type definition for KeyM_ElementOidUsedOfCertificateElement */
typedef boolean KeyM_ElementOidUsedOfCertificateElementType;

/**   \brief  value based type definition for KeyM_HasIterationOfCertificateElement */
typedef boolean KeyM_HasIterationOfCertificateElementType;

/**   \brief  value based type definition for KeyM_IdOfCertificateElement */
typedef uint8 KeyM_IdOfCertificateElementType;

/**   \brief  value based type definition for KeyM_MaskedBitsOfCertificateElement */
typedef uint8 KeyM_MaskedBitsOfCertificateElementType;

/**   \brief  value based type definition for KeyM_MaxLengthOfCertificateElement */
typedef uint8 KeyM_MaxLengthOfCertificateElementType;

/**   \brief  value based type definition for KeyM_ObjectTypeOfCertificateElement */
typedef uint8 KeyM_ObjectTypeOfCertificateElementType;

/**   \brief  value based type definition for KeyM_OptionalOfCertificateElement */
typedef boolean KeyM_OptionalOfCertificateElementType;

/**   \brief  value based type definition for KeyM_CertificateExtensionValidationEnabledOfGeneral */
typedef boolean KeyM_CertificateExtensionValidationEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_CertificateInitValue */
typedef uint8 KeyM_CertificateInitValueType;

/**   \brief  value based type definition for KeyM_CertificateInitValueEndIdxOfCertificateInitValueInfo */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateInitValue() } \endspec */ 
typedef uint16 KeyM_CertificateInitValueEndIdxOfCertificateInitValueInfoType;

/**   \brief  value based type definition for KeyM_CertificateInitValueLengthOfCertificateInitValueInfo */
typedef uint16 KeyM_CertificateInitValueLengthOfCertificateInitValueInfoType;

/**   \brief  value based type definition for KeyM_CertificateInitValueStartIdxOfCertificateInitValueInfo */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateInitValue() } \endspec */ 
typedef uint16 KeyM_CertificateInitValueStartIdxOfCertificateInitValueInfoType;

/**   \brief  value based type definition for KeyM_CertificateInitValueUsedOfCertificateInitValueInfo */
typedef boolean KeyM_CertificateInitValueUsedOfCertificateInitValueInfoType;

/**   \brief  value based type definition for KeyM_CertificateManagerEnabledOfGeneral */
typedef boolean KeyM_CertificateManagerEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_CertificateName */
typedef uint8 KeyM_CertificateNameType;

/**   \brief  value based type definition for KeyM_CertificateSigningRequestEnabledOfGeneral */
typedef boolean KeyM_CertificateSigningRequestEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_CryptoKeyPrepareFunctionEnabledOfGeneral */
typedef boolean KeyM_CryptoKeyPrepareFunctionEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_CryptoKeyStartFinalizeFunctionEnabledOfGeneral */
typedef boolean KeyM_CryptoKeyStartFinalizeFunctionEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_CryptoKeyVerifyAsyncModeOfGeneral */
typedef boolean KeyM_CryptoKeyVerifyAsyncModeOfGeneralType;

/**   \brief  value based type definition for KeyM_CryptoKeyVerifyFunctionEnabledOfGeneral */
typedef boolean KeyM_CryptoKeyVerifyFunctionEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_ElementOid */
typedef uint8 KeyM_ElementOidType;

/**   \brief  value based type definition for KeyM_KeyMCsmRemoteInfoJobRefAsyncOfGeneral */
typedef boolean KeyM_KeyMCsmRemoteInfoJobRefAsyncOfGeneralType;

/**   \brief  value based type definition for KeyM_KeyCertNameMaxLengthOfGeneral */
typedef uint8 KeyM_KeyCertNameMaxLengthOfGeneralType;

/**   \brief  value based type definition for KeyM_MainFunctionPeriodOfGeneral */
typedef uint8 KeyM_MainFunctionPeriodOfGeneralType;

/**   \brief  value based type definition for KeyM_ParseMaxNestingLevelOfGeneral */
typedef uint8 KeyM_ParseMaxNestingLevelOfGeneralType;

/**   \brief  value based type definition for KeyM_ServiceCertificateFunctionEnabledOfGeneral */
typedef boolean KeyM_ServiceCertificateFunctionEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_SizeOfCertStorage */
typedef uint16 KeyM_SizeOfCertStorageType;

/**   \brief  value based type definition for KeyM_SizeOfCert_CertInfo */
typedef uint8 KeyM_SizeOfCert_CertInfoType;

/**   \brief  value based type definition for KeyM_SizeOfCert_LeafCertsToVerify */
typedef uint8 KeyM_SizeOfCert_LeafCertsToVerifyType;

/**   \brief  value based type definition for KeyM_SizeOfCert_Lock */
typedef uint8 KeyM_SizeOfCert_LockType;

/**   \brief  value based type definition for KeyM_SizeOfCert_StorageType */
typedef uint8 KeyM_SizeOfCert_StorageTypeType;

/**   \brief  value based type definition for KeyM_SizeOfCert_VerifyChain */
typedef uint8 KeyM_SizeOfCert_VerifyChainType;

/**   \brief  value based type definition for KeyM_SizeOfCertificate */
typedef uint8 KeyM_SizeOfCertificateType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateElement */
typedef uint8 KeyM_SizeOfCertificateElementType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateElementVerificationCallout */
typedef uint8 KeyM_SizeOfCertificateElementVerificationCalloutType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateGetCurrentTimeCallout */
typedef uint8 KeyM_SizeOfCertificateGetCurrentTimeCalloutType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateInitValue */
typedef uint16 KeyM_SizeOfCertificateInitValueType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateInitValueInfo */
typedef uint8 KeyM_SizeOfCertificateInitValueInfoType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateName */
typedef uint8 KeyM_SizeOfCertificateNameType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateVerifyCallbackNotificationWithoutId */
typedef uint8 KeyM_SizeOfCertificateVerifyCallbackNotificationWithoutIdType;

/**   \brief  value based type definition for KeyM_SizeOfCommonCertData */
typedef uint8 KeyM_SizeOfCommonCertDataType;

/**   \brief  value based type definition for KeyM_SizeOfElementOid */
typedef uint8 KeyM_SizeOfElementOidType;

/**   \brief  value based type definition for KeyM_SizeOfElementStorageRef */
typedef uint8 KeyM_SizeOfElementStorageRefType;

/**   \brief  value based type definition for KeyM_SizeOfGeneral */
typedef uint8 KeyM_SizeOfGeneralType;

/**   \brief  value based type definition for KeyM_SizeOfServiceCertificateRteCallbackNotification440 */
typedef uint8 KeyM_SizeOfServiceCertificateRteCallbackNotification440Type;

/**   \brief  value based type definition for KeyM_VersionInfoApiOfGeneral */
typedef boolean KeyM_VersionInfoApiOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  KeyMPCStructTypes  KeyM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in KeyM_Certificate */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.CertStorageLengthOfCertificate != 0u) || (self.CertStorageStartIdxOfCertificate < KeyM_GetSizeOfCertStorage())) &&
 *   (self.CertUpperHierarchicalCertRefIdxOfCertificate < KeyM_GetSizeOfCertificate()) &&
 *   (!(self.CertificateElementLengthOfCertificate != 0u) || (self.CertificateElementEndIdxOfCertificate < KeyM_GetSizeOfCertificateElement())) &&
 *   (!(self.CertificateElementLengthOfCertificate != 0u) || (self.CertificateElementStartIdxOfCertificate < KeyM_GetSizeOfCertificateElement())) &&
 *   (!(self.CertificateGetCurrentTimeCalloutIdxOfCertificate != KEYM_NO_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE) || (self.CertificateGetCurrentTimeCalloutIdxOfCertificate < KeyM_GetSizeOfCertificateGetCurrentTimeCallout())) &&
 *   (!(self.CertificateInitValueInfoIdxOfCertificate != KEYM_NO_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE) || (self.CertificateInitValueInfoIdxOfCertificate < KeyM_GetSizeOfCertificateInitValueInfo())) &&
 *   (self.CertificateNameEndIdxOfCertificate < KeyM_GetSizeOfCertificateName()) &&
 *   (self.CertificateNameStartIdxOfCertificate < KeyM_GetSizeOfCertificateName()) &&
 *   (!(self.CertificateVerifyCallbackNotificationWithoutIdIdxOfCertificate != KEYM_NO_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDIDXOFCERTIFICATE) || (self.CertificateVerifyCallbackNotificationWithoutIdIdxOfCertificate < KeyM_GetSizeOfCertificateVerifyCallbackNotificationWithoutId())) &&
 *   (!(self.ServiceCertificateRteCallbackNotification440IdxOfCertificate != KEYM_NO_SERVICECERTIFICATERTECALLBACKNOTIFICATION440IDXOFCERTIFICATE) || (self.ServiceCertificateRteCallbackNotification440IdxOfCertificate < KeyM_GetSizeOfServiceCertificateRteCallbackNotification440()))
 * }
 * \endspec 
 */ 
typedef struct sKeyM_CertificateType
{
  KeyM_CertCsmSignatureGenerateJobRefOfCertificateType CertCsmSignatureGenerateJobRefOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureGenerateJobRef. */
  KeyM_CertCsmSignatureVerifyJobRefOfCertificateType CertCsmSignatureVerifyJobRefOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureVerifyJobRef. */
  KeyM_CertCsmSignatureVerifyKeyRefOfCertificateType CertCsmSignatureVerifyKeyRefOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureVerifyKeyRef. */
  KeyM_CsmKeyTargetRefOfCertificateType CsmKeyTargetRefOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateCsmKeyTargetRef. */
  KeyM_CertStorageLengthOfCertificateType CertStorageLengthOfCertificate;  /**< the number of relations pointing to KeyM_CertStorage */
  KeyM_CertStorageStartIdxOfCertificateType CertStorageStartIdxOfCertificate;  /**< the start index of the 0:n relation pointing to KeyM_CertStorage */
  KeyM_CertAlgorithmFamilyOfCertificateType CertAlgorithmFamilyOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertAlgorithmFamily. */
  KeyM_CertFormatTypeOfCertificateType CertFormatTypeOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertFormatType. */
  KeyM_CertStartUpHandlingOfCertificateType CertStartUpHandlingOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertStartUpHandling. */
  KeyM_CertStorageWrittenLengthLengthOfCertificateType CertStorageWrittenLengthLengthOfCertificate;  /**< the number of relations pointing to KeyM_CertStorage */
  KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType CertUpperHierarchicalCertRefIdxOfCertificate;  /**< the index of the 1:1 relation pointing to KeyM_Certificate */
  KeyM_CertUpperHierarchicalTypeOfCertificateType CertUpperHierarchicalTypeOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertUpperHierarchicalType. */
  KeyM_CertificateElementEndIdxOfCertificateType CertificateElementEndIdxOfCertificate;  /**< the end index of the 0:n relation pointing to KeyM_CertificateElement */
  KeyM_CertificateElementStartIdxOfCertificateType CertificateElementStartIdxOfCertificate;  /**< the start index of the 0:n relation pointing to KeyM_CertificateElement */
  KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificateType CertificateGetCurrentTimeCalloutIdxOfCertificate;  /**< the index of the 0:1 relation pointing to KeyM_CertificateGetCurrentTimeCallout */
  KeyM_CertificateInitValueInfoIdxOfCertificateType CertificateInitValueInfoIdxOfCertificate;  /**< the index of the 0:1 relation pointing to KeyM_CertificateInitValueInfo */
  KeyM_CertificateNameEndIdxOfCertificateType CertificateNameEndIdxOfCertificate;  /**< the end index of the 1:n relation pointing to KeyM_CertificateName */
  KeyM_CertificateNameStartIdxOfCertificateType CertificateNameStartIdxOfCertificate;  /**< the start index of the 1:n relation pointing to KeyM_CertificateName */
  KeyM_CertificateVerifyCallbackNotificationWithoutIdIdxOfCertificateType CertificateVerifyCallbackNotificationWithoutIdIdxOfCertificate;  /**< the index of the 0:1 relation pointing to KeyM_CertificateVerifyCallbackNotificationWithoutId */
  KeyM_MaskedBitsOfCertificateType MaskedBitsOfCertificate;  /**< contains bitcoded the boolean data of KeyM_CertAllowFlexibleElementOrderOfCertificate, KeyM_CertAllowUnconfiguredElementsOfCertificate, KeyM_CertCsmSignatureGenerateJobRefValidOfCertificate, KeyM_CertCsmSignatureVerifyKeyRefValidOfCertificate, KeyM_CsmKeyTargetRefValidOfCertificate, KeyM_KeyMCertCsmHashJobRefAsyncOfCertificate, KeyM_KeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate, KeyM_KeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate */
  KeyM_ServiceCertificateRteCallbackNotification440IdxOfCertificateType ServiceCertificateRteCallbackNotification440IdxOfCertificate;  /**< the index of the 0:1 relation pointing to KeyM_ServiceCertificateRteCallbackNotification440 */
  KeyM_StorageOfCertificateType StorageOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateStorage. */
} KeyM_CertificateType;

/**   \brief  type used in KeyM_CertificateElement */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.CertificateElementVerificationCalloutIdxOfCertificateElement != KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT) || (self.CertificateElementVerificationCalloutIdxOfCertificateElement < KeyM_GetSizeOfCertificateElementVerificationCallout())) &&
 *   (!(self.ElementOidLengthOfCertificateElement != 0u) || (self.ElementOidEndIdxOfCertificateElement < KeyM_GetSizeOfElementOid())) &&
 *   (!(self.ElementOidLengthOfCertificateElement != 0u) || (self.ElementOidStartIdxOfCertificateElement < KeyM_GetSizeOfElementOid()))
 * }
 * \endspec 
 */ 
typedef struct sKeyM_CertificateElementType
{
  KeyM_CertificateElementVerificationCalloutIdxOfCertificateElementType CertificateElementVerificationCalloutIdxOfCertificateElement;  /**< the index of the 0:1 relation pointing to KeyM_CertificateElementVerificationCallout */
  KeyM_ElementOidEndIdxOfCertificateElementType ElementOidEndIdxOfCertificateElement;  /**< the end index of the 0:n relation pointing to KeyM_ElementOid */
  KeyM_ElementOidStartIdxOfCertificateElementType ElementOidStartIdxOfCertificateElement;  /**< the start index of the 0:n relation pointing to KeyM_ElementOid */
  KeyM_IdOfCertificateElementType IdOfCertificateElement;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId. */
  KeyM_MaskedBitsOfCertificateElementType MaskedBitsOfCertificateElement;  /**< contains bitcoded the boolean data of KeyM_HasIterationOfCertificateElement, KeyM_OptionalOfCertificateElement */
  KeyM_MaxLengthOfCertificateElementType MaxLengthOfCertificateElement;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementMaxLength. */
  KeyM_ObjectTypeOfCertificateElementType ObjectTypeOfCertificateElement;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementObjectType. */
  KeyM_CertificateStructureType OfStructureOfCertificateElement;
} KeyM_CertificateElementType;

/**   \brief  type used in KeyM_CertificateInitValueInfo */
typedef struct sKeyM_CertificateInitValueInfoType
{
  KeyM_CertificateInitValueLengthOfCertificateInitValueInfoType CertificateInitValueLengthOfCertificateInitValueInfo;  /**< the number of relations pointing to KeyM_CertificateInitValue */
} KeyM_CertificateInitValueInfoType;

/**   \brief  type used in KeyM_General */
typedef struct sKeyM_GeneralType
{
  KeyM_KeyMCsmRemoteInfoJobRefAsyncOfGeneralType KeyMCsmRemoteInfoJobRefAsyncOfGeneral;
} KeyM_GeneralType;

/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCSymbolicStructTypes  KeyM Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to KeyM_CertStorage */
typedef struct KeyM_CertStorageStructSTag
{
  KeyM_CertStorageType Ssa_TrustModelBackendCert__WrittenLength__[2];
  KeyM_CertStorageType Ssa_TrustModelBackendCert__Status__[2];
  KeyM_CertStorageType Ssa_TrustModelBackendCert__Data__[1000];
  KeyM_CertStorageType Ssa_TrustModelBackendPeerCert__WrittenLength__[2];
  KeyM_CertStorageType Ssa_TrustModelBackendPeerCert__Status__[2];
  KeyM_CertStorageType Ssa_TrustModelBackendPeerCert__Data__[1000];
  KeyM_CertStorageType Ssa_TrustModelEcuCert__WrittenLength__[2];
  KeyM_CertStorageType Ssa_TrustModelEcuCert__Status__[2];
  KeyM_CertStorageType Ssa_TrustModelEcuCert__Data__[1000];
  KeyM_CertStorageType Ssa_TrustModelEcuCsr__WrittenLength__[2];
  KeyM_CertStorageType Ssa_TrustModelEcuCsr__Status__[2];
  KeyM_CertStorageType Ssa_TrustModelEcuCsr__Data__[1000];
  KeyM_CertStorageType Ssa_TrustModelEcuPeerCert__WrittenLength__[2];
  KeyM_CertStorageType Ssa_TrustModelEcuPeerCert__Status__[2];
  KeyM_CertStorageType Ssa_TrustModelEcuPeerCert__Data__[1000];
  KeyM_CertStorageType Ssa_TrustModelIntermediateCert__WrittenLength__[2];
  KeyM_CertStorageType Ssa_TrustModelIntermediateCert__Status__[2];
  KeyM_CertStorageType Ssa_TrustModelIntermediateCert__Data__[1000];
  KeyM_CertStorageType Ssa_TrustModelIntermediatePeerCert__WrittenLength__[2];
  KeyM_CertStorageType Ssa_TrustModelIntermediatePeerCert__Status__[2];
  KeyM_CertStorageType Ssa_TrustModelIntermediatePeerCert__Data__[1000];
  KeyM_CertStorageType Ssa_TrustModelRootCert__WrittenLength__[2];
  KeyM_CertStorageType Ssa_TrustModelRootCert__Status__[2];
  KeyM_CertStorageType Ssa_TrustModelRootCert__Data__[1000];
} KeyM_CertStorageStructSType;

/**   \brief  type to be used as symbolic data element access to KeyM_CommonCertData */
typedef struct KeyM_CommonCertDataStructSTag
{
  KeyM_ConstCertDataType Ssa_TrustModelBackendCert;
  KeyM_ConstCertDataType Ssa_TrustModelBackendPeerCert;
  KeyM_ConstCertDataType Ssa_TrustModelEcuCert;
  KeyM_ConstCertDataType Ssa_TrustModelEcuCsr;
  KeyM_ConstCertDataType Ssa_TrustModelEcuPeerCert;
  KeyM_ConstCertDataType Ssa_TrustModelIntermediateCert;
  KeyM_ConstCertDataType Ssa_TrustModelIntermediatePeerCert;
  KeyM_ConstCertDataType Ssa_TrustModelRootCert;
} KeyM_CommonCertDataStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCUnionIndexAndSymbolTypes  KeyM Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access KeyM_CertStorage in an index and symbol based style. */
typedef union KeyM_CertStorageUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  KeyM_CertStorageType raw[8032];
  KeyM_CertStorageStructSType str;
} KeyM_CertStorageUType;

/**   \brief  type to access KeyM_CommonCertData in an index and symbol based style. */
typedef union KeyM_CommonCertDataUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  KeyM_ConstCertDataType raw[8];
  KeyM_CommonCertDataStructSType str;
} KeyM_CommonCertDataUType;

/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCRootPointerTypes  KeyM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to KeyM_CertStorage */
typedef P2VAR(KeyM_CertStorageType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_CertStoragePtrType;

/**   \brief  type used to point to KeyM_Cert_CertInfo */
typedef P2VAR(tKeyMCertInfoType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_Cert_CertInfoPtrType;

/**   \brief  type used to point to KeyM_Cert_LeafCertsToVerify */
typedef P2VAR(KeyM_CertificateIdType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_Cert_LeafCertsToVerifyPtrType;

/**   \brief  type used to point to KeyM_Cert_Lock */
typedef P2VAR(KeyM_Cert_LockType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_Cert_LockPtrType;

/**   \brief  type used to point to KeyM_Cert_StorageType */
typedef P2VAR(tKeyMCertStorageType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_Cert_StorageTypePtrType;

/**   \brief  type used to point to KeyM_Cert_VerifyChain */
typedef P2VAR(KeyM_CertificateIdType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_Cert_VerifyChainPtrType;

/**   \brief  type used to point to KeyM_Certificate */
typedef P2CONST(KeyM_CertificateType, TYPEDEF, KEYM_CONST) KeyM_CertificatePtrType;

/**   \brief  type used to point to KeyM_CertificateElement */
typedef P2CONST(KeyM_CertificateElementType, TYPEDEF, KEYM_CONST) KeyM_CertificateElementPtrType;

/**   \brief  type used to point to KeyM_CertificateElementVerificationCallout */
typedef P2CONST(KeyM_CertificateElementVerificationCalloutFctPtrType, TYPEDEF, KEYM_CONST) KeyM_CertificateElementVerificationCalloutPtrType;

/**   \brief  type used to point to KeyM_CertificateGetCurrentTimeCallout */
typedef P2CONST(KeyM_CertificateGetCurrentTimeCalloutFctPtrType, TYPEDEF, KEYM_CONST) KeyM_CertificateGetCurrentTimeCalloutPtrType;

/**   \brief  type used to point to KeyM_CertificateInitValue */
typedef P2CONST(KeyM_CertificateInitValueType, TYPEDEF, KEYM_CONST) KeyM_CertificateInitValuePtrType;

/**   \brief  type used to point to KeyM_CertificateInitValueInfo */
typedef P2CONST(KeyM_CertificateInitValueInfoType, TYPEDEF, KEYM_CONST) KeyM_CertificateInitValueInfoPtrType;

/**   \brief  type used to point to KeyM_CertificateName */
typedef P2CONST(KeyM_CertificateNameType, TYPEDEF, KEYM_CONST) KeyM_CertificateNamePtrType;

/**   \brief  type used to point to KeyM_CertificateVerifyCallbackNotificationWithoutId */
typedef P2CONST(KeyM_CertificateVerifyCallbackNotificationWithoutIdFctPtrType, TYPEDEF, KEYM_CONST) KeyM_CertificateVerifyCallbackNotificationWithoutIdPtrType;

/**   \brief  type used to point to KeyM_CommonCertData */
typedef P2VAR(KeyM_ConstCertDataType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_CommonCertDataPtrType;

/**   \brief  type used to point to KeyM_ElementOid */
typedef P2CONST(KeyM_ElementOidType, TYPEDEF, KEYM_CONST) KeyM_ElementOidPtrType;

/**   \brief  type used to point to KeyM_ElementStorageRef */
typedef P2VAR(KeyM_Ans1_Element_Ref_Type, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_ElementStorageRefPtrType;

/**   \brief  type used to point to KeyM_General */
typedef P2CONST(KeyM_GeneralType, TYPEDEF, KEYM_CONST) KeyM_GeneralPtrType;

/**   \brief  type used to point to KeyM_ServiceCertificateRteCallbackNotification440 */
typedef P2CONST(KeyM_ServiceCertificateRteCallbackNotification440FctPtrType, TYPEDEF, KEYM_CONST) KeyM_ServiceCertificateRteCallbackNotification440PtrType;

/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCRootValueTypes  KeyM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in KeyM_PCConfig */
typedef struct sKeyM_PCConfigType
{
  uint8 KeyM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} KeyM_PCConfigType;

typedef KeyM_PCConfigType KeyM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
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
extern CONST(KeyM_CertificateType, KEYM_CONST) KeyM_Certificate[8];
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
extern CONST(KeyM_CertificateElementType, KEYM_CONST) KeyM_CertificateElement[134];
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
extern CONST(KeyM_CertificateElementVerificationCalloutFctPtrType, KEYM_CONST) KeyM_CertificateElementVerificationCallout[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(KeyM_CertificateGetCurrentTimeCalloutFctPtrType, KEYM_CONST) KeyM_CertificateGetCurrentTimeCallout[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(KeyM_CertificateInitValueType, KEYM_CONST) KeyM_CertificateInitValue[292];
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
extern CONST(KeyM_CertificateInitValueInfoType, KEYM_CONST) KeyM_CertificateInitValueInfo[1];
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
extern CONST(KeyM_CertificateNameType, KEYM_CONST) KeyM_CertificateName[174];
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
extern CONST(KeyM_CertificateVerifyCallbackNotificationWithoutIdFctPtrType, KEYM_CONST) KeyM_CertificateVerifyCallbackNotificationWithoutId[8];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(KeyM_ElementOidType, KEYM_CONST) KeyM_ElementOid[84];
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
extern CONST(KeyM_GeneralType, KEYM_CONST) KeyM_General[1];
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
extern CONST(KeyM_ServiceCertificateRteCallbackNotification440FctPtrType, KEYM_CONST) KeyM_ServiceCertificateRteCallbackNotification440[8];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern VAR(KeyM_CertStorageUType, KEYM_VAR_NO_INIT) KeyM_CertStorage;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(tKeyMCertInfoType, KEYM_VAR_NO_INIT) KeyM_Cert_CertInfo[8];
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
extern VAR(KeyM_CertificateIdType, KEYM_VAR_NO_INIT) KeyM_Cert_LeafCertsToVerify[8];
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
extern VAR(KeyM_Cert_LockType, KEYM_VAR_NO_INIT) KeyM_Cert_Lock[8];
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
extern VAR(tKeyMCertStorageType, KEYM_VAR_NO_INIT) KeyM_Cert_StorageType[8];
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
extern VAR(KeyM_CertificateIdType, KEYM_VAR_NO_INIT) KeyM_Cert_VerifyChain[8];
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
extern VAR(KeyM_CommonCertDataUType, KEYM_VAR_NO_INIT) KeyM_CommonCertData;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(KeyM_Ans1_Element_Ref_Type, KEYM_VAR_NO_INIT) KeyM_ElementStorageRef[134];
#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetDataInlineFunctionPrototypes  Get Data Inline Function Prototypes
  \brief  These inline functions can be used to read CONST and VAR data.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageType, KEYM_CODE) KeyM_GetCertStorage(KeyM_CertStorageIterType Index);
KEYM_LOCAL_INLINE FUNC(tKeyMCertInfoType, KEYM_CODE) KeyM_GetCert_CertInfo(KeyM_Cert_CertInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_GetCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_LockType, KEYM_CODE) KeyM_IsCert_Lock(KeyM_Cert_LockIterType Index);
KEYM_LOCAL_INLINE FUNC(tKeyMCertStorageType, KEYM_CODE) KeyM_GetCert_StorageType(KeyM_Cert_StorageTypeIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_GetCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertAlgorithmFamilyOfCertificateType, KEYM_CODE) KeyM_GetCertAlgorithmFamilyOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertCsmSignatureGenerateJobRefOfCertificateType, KEYM_CODE) KeyM_GetCertCsmSignatureGenerateJobRefOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertCsmSignatureVerifyJobRefOfCertificateType, KEYM_CODE) KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertCsmSignatureVerifyKeyRefOfCertificateType, KEYM_CODE) KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertFormatTypeOfCertificateType, KEYM_CODE) KeyM_GetCertFormatTypeOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStartUpHandlingOfCertificateType, KEYM_CODE) KeyM_GetCertStartUpHandlingOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStartIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageWrittenLengthLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType, KEYM_CODE) KeyM_GetCertUpperHierarchicalCertRefIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertUpperHierarchicalTypeOfCertificateType, KEYM_CODE) KeyM_GetCertUpperHierarchicalTypeOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementEndIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementStartIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateGetCurrentTimeCalloutIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueInfoIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateInitValueInfoIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameEndIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameStartIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateVerifyCallbackNotificationWithoutIdIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateVerifyCallbackNotificationWithoutIdIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CsmKeyTargetRefOfCertificateType, KEYM_CODE) KeyM_GetCsmKeyTargetRefOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_MaskedBitsOfCertificateType, KEYM_CODE) KeyM_GetMaskedBitsOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ServiceCertificateRteCallbackNotification440IdxOfCertificateType, KEYM_CODE) KeyM_GetServiceCertificateRteCallbackNotification440IdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_StorageOfCertificateType, KEYM_CODE) KeyM_GetStorageOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementVerificationCalloutIdxOfCertificateElementType, KEYM_CODE) KeyM_GetCertificateElementVerificationCalloutIdxOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidEndIdxOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidEndIdxOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidStartIdxOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidStartIdxOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_IdOfCertificateElementType, KEYM_CODE) KeyM_GetIdOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_MaskedBitsOfCertificateElementType, KEYM_CODE) KeyM_GetMaskedBitsOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_MaxLengthOfCertificateElementType, KEYM_CODE) KeyM_GetMaxLengthOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ObjectTypeOfCertificateElementType, KEYM_CODE) KeyM_GetObjectTypeOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateStructureType, KEYM_CODE) KeyM_GetOfStructureOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementVerificationCalloutFctPtrType, KEYM_CODE) KeyM_GetCertificateElementVerificationCallout(KeyM_CertificateElementVerificationCalloutIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutFctPtrType, KEYM_CODE) KeyM_GetCertificateGetCurrentTimeCallout(KeyM_CertificateGetCurrentTimeCalloutIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueType, KEYM_CODE) KeyM_GetCertificateInitValue(KeyM_CertificateInitValueIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueLengthOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitValueLengthOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameType, KEYM_CODE) KeyM_GetCertificateName(KeyM_CertificateNameIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateVerifyCallbackNotificationWithoutIdFctPtrType, KEYM_CODE) KeyM_GetCertificateVerifyCallbackNotificationWithoutId(KeyM_CertificateVerifyCallbackNotificationWithoutIdIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ConstCertDataType, KEYM_CODE) KeyM_GetCommonCertData(KeyM_CommonCertDataIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidType, KEYM_CODE) KeyM_GetElementOid(KeyM_ElementOidIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_Ans1_Element_Ref_Type, KEYM_CODE) KeyM_GetElementStorageRef(KeyM_ElementStorageRefIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_KeyMCsmRemoteInfoJobRefAsyncOfGeneralType, KEYM_CODE) KeyM_IsKeyMCsmRemoteInfoJobRefAsyncOfGeneral(KeyM_GeneralIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ServiceCertificateRteCallbackNotification440FctPtrType, KEYM_CODE) KeyM_GetServiceCertificateRteCallbackNotification440(KeyM_ServiceCertificateRteCallbackNotification440IterType Index);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetBitDataInlineFunctionPrototypes  Get Bit Data Inline Function Prototypes
  \brief  These inline functions can be used to read bitcoded data elements.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertAllowFlexibleElementOrderOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertAllowUnconfiguredElementsOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertCsmSignatureGenerateJobRefValidOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertCsmSignatureVerifyKeyRefValidOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCsmKeyTargetRefValidOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsKeyMCertCsmHashJobRefAsyncOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsKeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsKeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsHasIterationOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsOptionalOfCertificateElement(KeyM_CertificateElementIterType Index);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetDeduplicatedInlineFunctionPrototypes  Get Deduplicated Inline Function Prototypes
  \brief  These inline functions  can be used to read deduplicated data elements.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageEndIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStatusEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStatusEndIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStatusLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStatusLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStatusStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStatusStartIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageUsedOfCertificateType, KEYM_CODE) KeyM_IsCertStorageUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageWrittenLengthEndIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageWrittenLengthStartIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthUsedOfCertificateType, KEYM_CODE) KeyM_IsCertStorageWrittenLengthUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementLengthOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateElementUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateGetCurrentTimeCalloutUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueInfoUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateInitValueInfoUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameLengthOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateVerifyCallbackNotificationWithoutIdUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateVerifyCallbackNotificationWithoutIdUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_MaxLengthOfCertificateType, KEYM_CODE) KeyM_GetMaxLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_RemoteCertificateIdOfCertificateType, KEYM_CODE) KeyM_GetRemoteCertificateIdOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ServiceCertificateRteCallbackNotification440UsedOfCertificateType, KEYM_CODE) KeyM_IsServiceCertificateRteCallbackNotification440UsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateChainMaxDepthOfGeneralType, KEYM_CODE) KeyM_GetCertificateChainMaxDepthOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementVerificationCalloutUsedOfCertificateElementType, KEYM_CODE) KeyM_IsCertificateElementVerificationCalloutUsedOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidLengthOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidLengthOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidUsedOfCertificateElementType, KEYM_CODE) KeyM_IsElementOidUsedOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateExtensionValidationEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateExtensionValidationEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueEndIdxOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitValueEndIdxOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueStartIdxOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitValueStartIdxOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueUsedOfCertificateInitValueInfoType, KEYM_CODE) KeyM_IsCertificateInitValueUsedOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateManagerEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateManagerEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateSigningRequestEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateSigningRequestEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyPrepareFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyPrepareFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyStartFinalizeFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyStartFinalizeFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyVerifyAsyncModeOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyVerifyAsyncModeOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyVerifyFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyVerifyFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_KeyCertNameMaxLengthOfGeneralType, KEYM_CODE) KeyM_GetKeyCertNameMaxLengthOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_MainFunctionPeriodOfGeneralType, KEYM_CODE) KeyM_GetMainFunctionPeriodOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_ParseMaxNestingLevelOfGeneralType, KEYM_CODE) KeyM_GetParseMaxNestingLevelOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_ServiceCertificateFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsServiceCertificateFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertStorageType, KEYM_CODE) KeyM_GetSizeOfCertStorage(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_CertInfoType, KEYM_CODE) KeyM_GetSizeOfCert_CertInfo(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_LeafCertsToVerifyType, KEYM_CODE) KeyM_GetSizeOfCert_LeafCertsToVerify(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_LockType, KEYM_CODE) KeyM_GetSizeOfCert_Lock(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_StorageTypeType, KEYM_CODE) KeyM_GetSizeOfCert_StorageType(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_VerifyChainType, KEYM_CODE) KeyM_GetSizeOfCert_VerifyChain(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateType, KEYM_CODE) KeyM_GetSizeOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateElementType, KEYM_CODE) KeyM_GetSizeOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateElementVerificationCalloutType, KEYM_CODE) KeyM_GetSizeOfCertificateElementVerificationCallout(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateGetCurrentTimeCalloutType, KEYM_CODE) KeyM_GetSizeOfCertificateGetCurrentTimeCallout(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateInitValueType, KEYM_CODE) KeyM_GetSizeOfCertificateInitValue(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetSizeOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateNameType, KEYM_CODE) KeyM_GetSizeOfCertificateName(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateVerifyCallbackNotificationWithoutIdType, KEYM_CODE) KeyM_GetSizeOfCertificateVerifyCallbackNotificationWithoutId(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCommonCertDataType, KEYM_CODE) KeyM_GetSizeOfCommonCertData(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfElementOidType, KEYM_CODE) KeyM_GetSizeOfElementOid(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfElementStorageRefType, KEYM_CODE) KeyM_GetSizeOfElementStorageRef(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfGeneralType, KEYM_CODE) KeyM_GetSizeOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfServiceCertificateRteCallbackNotification440Type, KEYM_CODE) KeyM_GetSizeOfServiceCertificateRteCallbackNotification440(void);
KEYM_LOCAL_INLINE FUNC(KeyM_VersionInfoApiOfGeneralType, KEYM_CODE) KeyM_IsVersionInfoApiOfGeneral(void);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCSetDataInlineFunctionPrototypes  Set Data Inline Function Prototypes
  \brief  These inline functions can be used to write data.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCertStorage(KeyM_CertStorageIterType Index, KeyM_CertStorageType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_CertInfo(KeyM_Cert_CertInfoIterType Index, tKeyMCertInfoType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index, KeyM_CertificateIdType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_Lock(KeyM_Cert_LockIterType Index, KeyM_Cert_LockType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_StorageType(KeyM_Cert_StorageTypeIterType Index, tKeyMCertStorageType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index, KeyM_CertificateIdType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCommonCertData(KeyM_CommonCertDataIterType Index, KeyM_ConstCertDataType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetElementStorageRef(KeyM_ElementStorageRefIterType Index, KeyM_Ans1_Element_Ref_Type Value);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetAddressOfDataInlineFunctionPrototypes  Get Address Of Data Inline Function Prototypes
  \brief  These inline functions can be used to get the data by the address operator.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStoragePtrType, KEYM_CODE) KeyM_GetAddrCertStorage(KeyM_CertStorageIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_CertInfoPtrType, KEYM_CODE) KeyM_GetAddrCert_CertInfo(KeyM_Cert_CertInfoIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_LockPtrType, KEYM_CODE) KeyM_GetAddrCert_Lock(KeyM_Cert_LockIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_StorageTypePtrType, KEYM_CODE) KeyM_GetAddrCert_StorageType(KeyM_Cert_StorageTypeIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValuePtrType, KEYM_CODE) KeyM_GetAddrCertificateInitValue(KeyM_CertificateInitValueIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNamePtrType, KEYM_CODE) KeyM_GetAddrCertificateName(KeyM_CertificateNameIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CommonCertDataPtrType, KEYM_CODE) KeyM_GetAddrCommonCertData(KeyM_CommonCertDataIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidPtrType, KEYM_CODE) KeyM_GetAddrElementOid(KeyM_ElementOidIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementStorageRefPtrType, KEYM_CODE) KeyM_GetAddrElementStorageRef(KeyM_ElementStorageRefIterType Index);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCHasInlineFunctionPrototypes  Has Inline Function Prototypes
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorage(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_CertInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_LeafCertsToVerify(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_Lock(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_StorageType(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_VerifyChain(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAlgorithmFamilyOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAllowFlexibleElementOrderOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAllowUnconfiguredElementsOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureGenerateJobRefOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureGenerateJobRefValidOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureVerifyJobRefOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureVerifyKeyRefOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureVerifyKeyRefValidOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertFormatTypeOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStartUpHandlingOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageEndIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStartIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStatusEndIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStatusLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStatusStartIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthEndIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthStartIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertUpperHierarchicalCertRefIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertUpperHierarchicalTypeOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementEndIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementStartIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfoIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfoUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameEndIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameStartIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateVerifyCallbackNotificationWithoutIdIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateVerifyCallbackNotificationWithoutIdUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCsmKeyTargetRefOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCsmKeyTargetRefValidOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmHashJobRefAsyncOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaskedBitsOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaxLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasRemoteCertificateIdOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateRteCallbackNotification440IdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateRteCallbackNotification440UsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasStorageOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateChainMaxDepthOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementVerificationCalloutIdxOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementVerificationCalloutUsedOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidEndIdxOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidLengthOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidStartIdxOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidUsedOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasHasIterationOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasIdOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaskedBitsOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaxLengthOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasObjectTypeOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasOfStructureOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasOptionalOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementVerificationCallout(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateExtensionValidationEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCallout(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValue(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueEndIdxOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueLengthOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueStartIdxOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueUsedOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateManagerEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateName(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSigningRequestEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateVerifyCallbackNotificationWithoutId(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCommonCertData(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyPrepareFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyStartFinalizeFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyAsyncModeOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOid(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementStorageRef(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCsmRemoteInfoJobRefAsyncOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyCertNameMaxLengthOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMainFunctionPeriodOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasParseMaxNestingLevelOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateRteCallbackNotification440(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertStorage(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_CertInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LeafCertsToVerify(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_Lock(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_StorageType(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_VerifyChain(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElementVerificationCallout(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGetCurrentTimeCallout(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValue(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValueInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateName(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateVerifyCallbackNotificationWithoutId(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCommonCertData(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementOid(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementStorageRef(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfServiceCertificateRteCallbackNotification440(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasVersionInfoApiOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_CertInfoOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_LeafCertsToVerifyOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_LockOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_StorageTypeOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_VerifyChainOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateChainMaxDepthOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementVerificationCalloutOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateExtensionValidationEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfoOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateManagerEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSigningRequestEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateVerifyCallbackNotificationWithoutIdOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCommonCertDataOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyPrepareFunctionEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyStartFinalizeFunctionEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyAsyncModeOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyFunctionEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementStorageRefOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyCertNameMaxLengthOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMainFunctionPeriodOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasParseMaxNestingLevelOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateFunctionEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateRteCallbackNotification440OfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertStorageOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_CertInfoOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LeafCertsToVerifyOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LockOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_StorageTypeOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_VerifyChainOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElementOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElementVerificationCalloutOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGetCurrentTimeCalloutOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValueInfoOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValueOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateNameOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateVerifyCallbackNotificationWithoutIdOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCommonCertDataOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementOidOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementStorageRefOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfServiceCertificateRteCallbackNotification440OfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasVersionInfoApiOfGeneralOfPCConfig(void);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCIncrementInlineFunctionPrototypes  Increment Inline Function Prototypes
  \brief  These inline functions can be used to increment VAR data with numerical nature.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCertStorage(KeyM_CertStorageIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCert_StorageType(KeyM_Cert_StorageTypeIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCDecrementInlineFunctionPrototypes  Decrement Inline Function Prototypes
  \brief  These inline functions can be used to decrement VAR data with numerical nature.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCertStorage(KeyM_CertStorageIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCert_StorageType(KeyM_Cert_StorageTypeIterType Index);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCAddInlineFunctionPrototypes  Add Inline Function Prototypes
  \brief  These inline functions can be used to add VAR data with numerical nature.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCertStorage(KeyM_CertStorageIterType Index, KeyM_CertStorageType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index, KeyM_CertificateIdType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCert_StorageType(KeyM_Cert_StorageTypeIterType Index, tKeyMCertStorageType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index, KeyM_CertificateIdType Value);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCSubstractInlineFunctionPrototypes  Substract Inline Function Prototypes
  \brief  These inline functions can be used to substract VAR data with numerical nature.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCertStorage(KeyM_CertStorageIterType Index, KeyM_CertStorageType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index, KeyM_CertificateIdType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCert_StorageType(KeyM_Cert_StorageTypeIterType Index, tKeyMCertStorageType Value);
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index, KeyM_CertificateIdType Value);
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
 *  GetCertificate
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_GetCertificate_Ssa_TrustModelEcuCert
 * \fn          KeyM_GetCertificate_Ssa_TrustModelIntermediateCert
 * \fn          KeyM_GetCertificate_Ssa_TrustModelBackendCert
 * \fn          KeyM_GetCertificate_Ssa_TrustModelRootCert
 * \fn          KeyM_GetCertificate_Ssa_TrustModelEcuPeerCert
 * \fn          KeyM_GetCertificate_Ssa_TrustModelBackendPeerCert
 * \fn          KeyM_GetCertificate_Ssa_TrustModelIntermediatePeerCert
 * \fn          KeyM_GetCertificate_Ssa_TrustModelEcuCsr
 * \brief       Provide certificate.
 * \details     This function provides the certificate data.
 * \param[in]   CertId              Holds the identifier of the certificate.
 * \param[out]  CertificateDataPtr  Provides a pointer to a certificate data structure. If E_OK is returned, the length
 *                                  information inside the structure indicates the length of the certificate data that
 *                                  was written to array inside the structure.
 * \return      E_OK                           Certificate data available and provided.
 * \return      E_NOT_OK                       Operation not accepted due to an internal error.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_READ_FAIL      Certificate cannot be provided, access denied.
 * \pre         CertificateDataPtr must be a valid (i.e., not null) pointer to an instance of the certificate's
 *              respective struct type.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different GetCertificate operations with different
 *              data types in the RTE and the KeyM_GetCertificate C API
 * \spec        requires CertificateDataPtr != NULL_PTR;  \endspec
 */

/**********************************************************************************************************************
 *  SetCertificate
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_SetCertificate_Ssa_TrustModelEcuCert
 * \fn          KeyM_SetCertificate_Ssa_TrustModelIntermediateCert
 * \fn          KeyM_SetCertificate_Ssa_TrustModelBackendCert
 * \fn          KeyM_SetCertificate_Ssa_TrustModelRootCert
 * \fn          KeyM_SetCertificate_Ssa_TrustModelEcuPeerCert
 * \fn          KeyM_SetCertificate_Ssa_TrustModelBackendPeerCert
 * \fn          KeyM_SetCertificate_Ssa_TrustModelIntermediatePeerCert
 * \fn          KeyM_SetCertificate_Ssa_TrustModelEcuCsr
 * \brief       Temporarily store certificate.
 * \details     This function provides the certificate data to the key management module to temporarily store the
 *              certificate.
 * \param[in]   CertId              Holds the identifier of the certificate.
 * \param[in]   CertificateDataPtr  Pointer to a structure that provides the certificate data. This pointer is only used
 *                                  as read-only.
 * \return      E_OK                           Certificate accepted.
 * \return      E_NOT_OK                       Certificate could not be set.
 * \return      KEYM_E_PARAMETER_MISMATCH      Parameter does not match with expected value.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Parameter size doesn't match.
 * \pre         CertificateDataPtr must be a valid (i.e., not null) pointer to an instance of the certificate's
 *              respective struct type.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different SetCertificate operations with different
 *              data types in the RTE and the KeyM_SetCertificate C API
 * \spec        requires CertificateDataPtr != NULL_PTR;  \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_authKeyId_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_authKeyId_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_authKeyId_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_authKeyId_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_authKeyId_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_authKeyId_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_authKeyId_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_authKeyId_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_subKeyId_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_subKeyId_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_subKeyId_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_subKeyId_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_subKeyId_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_subKeyId_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_subKeyId_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_subKeyId_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_keyUsage_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_keyUsage_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_keyUsage_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_keyUsage_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_keyUsage_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_keyUsage_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_keyUsage_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_keyUsage_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_pkiRole_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_pkiRole_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_pkiRole_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_pkiRole_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_pkiRole_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_pkiRole_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_pkiRole_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_pkiRole_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_Version_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_Version_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Version_005) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Version_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_Version_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_Version_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Version_005) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Version_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_SerialNo_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_SerialNo_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SerialNo_005) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SerialNo_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SerialNo_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SerialNo_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SerialNo_005) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SerialNo_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_SigAlgoId_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_SigAlgoId_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SigAlgoId_005) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SigAlgoId_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SigAlgoId_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SigAlgoId_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SigAlgoId_005) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SigAlgoId_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_validityNotBefore_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_validityNotBefore_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotBefore_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotBefore_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_validityNotBefore_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_validityNotBefore_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotBefore_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotBefore_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_validityNotAfter_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_validityNotAfter_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotAfter_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotAfter_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_validityNotAfter_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_validityNotAfter_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotAfter_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotAfter_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_subject_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_subject_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_subject_005) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_subject_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_subject_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_subject_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_subject_005) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_subject_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_Issuer_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_Issuer_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Issuer_005) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Issuer_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_Issuer_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_Issuer_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Issuer_005) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Issuer_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_signatureAlgorithm_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_signatureAlgorithm_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureAlgorithm_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureAlgorithm_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_signatureAlgorithm_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_signatureAlgorithm_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureAlgorithm_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureAlgorithm_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_signatureValue_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_signatureValue_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureValue_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureValue_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_signatureValue_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_signatureValue_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureValue_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureValue_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_uniqueECUID_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_uniqueECUID_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_uniqueECUID_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_uniqueECUID_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_uniqueECUID_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_uniqueECUID_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_uniqueECUID_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_uniqueECUID_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_specialEcu_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_specialEcu_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_specialEcu_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_specialEcu_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_specialEcu_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCert_ext_specialEcu_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_specialEcu_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_specialEcu_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_authKeyId_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_authKeyId_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_authKeyId_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_authKeyId_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_authKeyId_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_authKeyId_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_authKeyId_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_authKeyId_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_subKeyId_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_subKeyId_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_subKeyId_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_subKeyId_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_subKeyId_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_subKeyId_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_subKeyId_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_subKeyId_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_keyUsage_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_keyUsage_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_keyUsage_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_keyUsage_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_keyUsage_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_keyUsage_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_keyUsage_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_keyUsage_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_pkiRole_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_pkiRole_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_pkiRole_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_pkiRole_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_pkiRole_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_ext_pkiRole_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_pkiRole_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_pkiRole_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_Version_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_Version_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Version_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Version_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_Version_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_Version_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Version_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Version_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SerialNo_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SerialNo_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SerialNo_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SerialNo_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SerialNo_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SerialNo_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SerialNo_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SerialNo_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SigAlgoId_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SigAlgoId_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SigAlgoId_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SigAlgoId_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SigAlgoId_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SigAlgoId_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SigAlgoId_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SigAlgoId_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_validityNotBefore_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_validityNotBefore_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotBefore_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotBefore_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_validityNotBefore_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_validityNotBefore_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotBefore_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotBefore_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_validityNotAfter_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_validityNotAfter_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotAfter_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotAfter_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_validityNotAfter_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_validityNotAfter_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotAfter_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotAfter_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_subject_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_subject_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_subject_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_subject_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_subject_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_subject_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_subject_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_subject_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003)
 *              elements. CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003)
 *              elements. CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_Issuer_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_Issuer_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Issuer_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Issuer_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_Issuer_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_Issuer_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Issuer_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Issuer_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_signatureValue_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_signatureValue_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureValue_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureValue_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_signatureValue_003
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediateCert_signatureValue_003
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureValue_003) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureValue_003);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_authKeyId_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_authKeyId_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_authKeyId_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_authKeyId_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_authKeyId_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_authKeyId_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_authKeyId_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_authKeyId_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_subKeyId_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_subKeyId_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_subKeyId_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_subKeyId_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_subKeyId_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_subKeyId_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_subKeyId_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_subKeyId_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_basicConstraints_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_basicConstraints_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_basicConstraints_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_basicConstraints_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_basicConstraints_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_basicConstraints_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_basicConstraints_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_basicConstraints_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_keyUsage_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_keyUsage_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_keyUsage_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_keyUsage_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_keyUsage_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_keyUsage_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_keyUsage_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_keyUsage_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_pkiRole_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_pkiRole_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_pkiRole_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_pkiRole_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_pkiRole_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_ext_pkiRole_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_pkiRole_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_pkiRole_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_Version_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_Version_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Version_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Version_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_Version_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_Version_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Version_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Version_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_SerialNo_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_SerialNo_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SerialNo_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SerialNo_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SerialNo_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SerialNo_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SerialNo_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SerialNo_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_SigAlgoId_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_SigAlgoId_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SigAlgoId_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SigAlgoId_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SigAlgoId_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SigAlgoId_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SigAlgoId_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SigAlgoId_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_validityNotBefore_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_validityNotBefore_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotBefore_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotBefore_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_validityNotBefore_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_validityNotBefore_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotBefore_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotBefore_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_validityNotAfter_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_validityNotAfter_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotAfter_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotAfter_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_validityNotAfter_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_validityNotAfter_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotAfter_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotAfter_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_subject_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_subject_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_subject_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_subject_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_subject_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_subject_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_subject_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_subject_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_Issuer_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_Issuer_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Issuer_002) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Issuer_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_Issuer_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_Issuer_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Issuer_002) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Issuer_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_signatureAlgorithm_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_signatureAlgorithm_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureAlgorithm_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureAlgorithm_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_signatureAlgorithm_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_signatureAlgorithm_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureAlgorithm_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureAlgorithm_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendCert_signatureValue_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendCert_signatureValue_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureValue_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureValue_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_signatureValue_002
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendCert_signatureValue_002
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureValue_002) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureValue_002);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_authKeyId_009
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_authKeyId_009
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_authKeyId_009) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_authKeyId_009);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_authKeyId_009
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_authKeyId_009
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_authKeyId_009) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_authKeyId_009);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_Version
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_Version
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Version) elements. CertElementDataLength must
 *              be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Version);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_Version
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_Version
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Version) elements. CertElementDataLength must
 *              be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Version);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_SerialNo
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_SerialNo
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SerialNo) elements. CertElementDataLength must
 *              be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SerialNo);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SerialNo
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SerialNo
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SerialNo) elements. CertElementDataLength must
 *              be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SerialNo);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_SigAlgoId
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_SigAlgoId
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SigAlgoId) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SigAlgoId);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SigAlgoId
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SigAlgoId
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SigAlgoId) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SigAlgoId);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_validityNotBefore
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_validityNotBefore
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotBefore) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotBefore);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_validityNotBefore
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_validityNotBefore
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotBefore) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotBefore);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_validityNotAfter
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_validityNotAfter
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotAfter) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotAfter);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_validityNotAfter
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_validityNotAfter
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotAfter) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotAfter);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_subject
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_subject
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_subject) elements. CertElementDataLength must
 *              be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_subject);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_subject
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_subject
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_subject) elements. CertElementDataLength must
 *              be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_subject);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_Issuer
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_Issuer
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Issuer) elements. CertElementDataLength must
 *              be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Issuer);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_Issuer
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_Issuer
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Issuer) elements. CertElementDataLength must
 *              be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Issuer);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_signatureAlgorithm
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_signatureAlgorithm
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureAlgorithm) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureAlgorithm);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_signatureAlgorithm
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_signatureAlgorithm
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureAlgorithm) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureAlgorithm);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_signatureValue
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_signatureValue
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureValue) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureValue);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_signatureValue
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_signatureValue
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureValue) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureValue);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_subKeyId
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_subKeyId
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_subKeyId) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_subKeyId);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_subKeyId
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_subKeyId
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_subKeyId) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_subKeyId);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_basicConstraints
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_basicConstraints
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_basicConstraints) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_basicConstraints);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_basicConstraints
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_basicConstraints
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_basicConstraints) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_basicConstraints);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_keyUsage
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_keyUsage
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_keyUsage) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_keyUsage);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_keyUsage
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_keyUsage
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_keyUsage) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_keyUsage);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_pkiRole
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_pkiRole
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_pkiRole) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_pkiRole);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_pkiRole
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelRootCert_ext_pkiRole
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_pkiRole) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_pkiRole);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_Version_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_Version_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Version_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Version_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_Version_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_Version_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Version_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Version_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SerialNo_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SerialNo_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SerialNo_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SerialNo_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SerialNo_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SerialNo_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SerialNo_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SerialNo_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SigAlgoId_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SigAlgoId_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SigAlgoId_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SigAlgoId_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SigAlgoId_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SigAlgoId_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SigAlgoId_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SigAlgoId_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_validityNotBefore_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_validityNotBefore_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotBefore_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotBefore_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_validityNotBefore_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_validityNotBefore_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotBefore_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotBefore_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_validityNotAfter_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_validityNotAfter_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotAfter_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotAfter_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_validityNotAfter_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_validityNotAfter_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotAfter_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotAfter_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_subject_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_subject_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_subject_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_subject_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_subject_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_subject_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_subject_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_subject_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_Issuer_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_Issuer_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Issuer_006) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Issuer_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_Issuer_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_Issuer_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Issuer_006) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Issuer_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_signatureValue_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_signatureValue_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureValue_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureValue_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_signatureValue_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_signatureValue_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureValue_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureValue_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_Version_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_Version_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Version_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Version_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_Version_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_Version_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Version_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Version_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SerialNo_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SerialNo_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SerialNo_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SerialNo_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SerialNo_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SerialNo_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SerialNo_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SerialNo_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SigAlgoId_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SigAlgoId_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SigAlgoId_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SigAlgoId_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SigAlgoId_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SigAlgoId_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SigAlgoId_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SigAlgoId_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_validityNotBefore_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_validityNotBefore_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotBefore_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotBefore_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_validityNotBefore_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_validityNotBefore_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotBefore_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotBefore_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_validityNotAfter_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_validityNotAfter_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotAfter_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotAfter_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_validityNotAfter_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_validityNotAfter_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotAfter_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotAfter_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_subject_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_subject_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_subject_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_subject_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_subject_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_subject_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_subject_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_subject_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_Issuer_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_Issuer_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Issuer_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Issuer_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_Issuer_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_Issuer_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Issuer_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Issuer_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_signatureValue_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_signatureValue_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureValue_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureValue_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_signatureValue_004
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelBackendPeerCert_signatureValue_004
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureValue_004) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureValue_004);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005)
 *              elements. CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005)
 *              elements. CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_Version_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_Version_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Version_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Version_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_Version_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_Version_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Version_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Version_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SerialNo_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SerialNo_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SerialNo_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SerialNo_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SerialNo_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SerialNo_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SerialNo_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SerialNo_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_subject_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_subject_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_subject_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_subject_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_subject_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_subject_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_subject_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_subject_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007)
 *              elements. CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007)
 *              elements. CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007)
 *              elements. CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007)
 *              elements. CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_Issuer_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_Issuer_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Issuer_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Issuer_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_Issuer_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_Issuer_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Issuer_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Issuer_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_signatureValue_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_signatureValue_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureValue_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureValue_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_signatureValue_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelIntermediatePeerCert_signatureValue_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureValue_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureValue_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_authKeyId_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_authKeyId_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_authKeyId_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_authKeyId_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_authKeyId_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_authKeyId_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_authKeyId_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_authKeyId_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_subKeyId_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_subKeyId_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_subKeyId_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_subKeyId_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_subKeyId_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_subKeyId_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_subKeyId_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_subKeyId_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_keyUsage_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_keyUsage_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_keyUsage_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_keyUsage_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_keyUsage_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_keyUsage_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_keyUsage_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_keyUsage_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_pkiRole_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_pkiRole_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_pkiRole_008) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_pkiRole_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_pkiRole_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_pkiRole_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_pkiRole_008) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_pkiRole_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_Version_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_Version_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Version_008) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Version_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_Version_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_Version_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Version_008) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Version_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SerialNo_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SerialNo_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SerialNo_008) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SerialNo_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SerialNo_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SerialNo_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SerialNo_008) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SerialNo_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SigAlgoId_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SigAlgoId_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SigAlgoId_008) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SigAlgoId_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SigAlgoId_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SigAlgoId_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SigAlgoId_008) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SigAlgoId_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_validityNotBefore_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_validityNotBefore_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotBefore_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotBefore_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_validityNotBefore_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_validityNotBefore_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotBefore_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotBefore_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_validityNotAfter_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_validityNotAfter_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotAfter_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotAfter_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_validityNotAfter_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_validityNotAfter_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotAfter_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotAfter_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_subject_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_subject_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_subject_008) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_subject_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_subject_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_subject_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_subject_008) elements. CertElementDataLength
 *              must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_subject_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_Issuer_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_Issuer_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Issuer_008) elements. CertElementDataLength must
 *              be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Issuer_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_Issuer_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_Issuer_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Issuer_008) elements. CertElementDataLength must
 *              be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Issuer_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_signatureAlgorithm_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_signatureAlgorithm_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureAlgorithm_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureAlgorithm_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_signatureAlgorithm_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_signatureAlgorithm_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureAlgorithm_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureAlgorithm_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_signatureValue_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_signatureValue_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureValue_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureValue_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_signatureValue_008
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_signatureValue_008
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureValue_008) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureValue_008);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_specialEcu_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_specialEcu_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_specialEcu_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_specialEcu_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_specialEcu_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_specialEcu_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_specialEcu_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_specialEcu_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertElementGet_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Specifies the ElementId where the data shall be read from.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertElementGet operations with different
 *              data types in the RTE and the KeyM_CertElementGet BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */

/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007
 *********************************************************************************************************************/
/*!
 * \fn          KeyM_CertificateElementGetByIndex_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007
 * \brief       Provide certificate element.
 * \details     Provides the content of a specific certificate element.
 * \param[in]   CertId                 Holds the identifier of the certificate.
 * \param[in]   CertElementId          Holds the identifier of the iterable certificate element.
 * \param[in]   Index                  This is the index to the respective element in the list of iterable elements.
 * \param[out]  CertElementData        Pointer to a data buffer allocated by the caller of this function.
 * \param[out]  CertElementDataLength  The length of data placed into CertElementData.
 * \return      E_OK                           Element found and data provided in the buffer.
 * \return      E_NOT_OK                       Element data not found.
 * \return      KEYM_E_PARAMETER_MISMATCH      Certificate ID or certificate element ID invalid.
 * \return      KEYM_E_KEY_CERT_SIZE_MISMATCH  Provided buffer for the certificate element too small.
 * \return      KEYM_E_KEY_CERT_EMPTY          No certificate data available, the certificate slot is empty.
 * \return      KEYM_E_KEY_CERT_INVALID        The certificate is not valid or has not yet been verified.
 * \pre         CertElementData must point to a buffer of at least
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007) elements.
 *              CertElementDataLength must be a valid pointer to a uint32.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function is needed as an adapter between the different CertificateElementGetByIndex operations with
 *              different data types in the RTE and the KeyM_CertificateElementGetByIndex BSW API
 * \spec
 *              requires $lengthOf(CertElementData) >=
 *              sizeof(KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007);
 *              requires CertElementDataLength != NULL_PTR;
 * \endspec
 */
#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



# define KEYM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * KeyM_Cert_IsBusy()
 *********************************************************************************************************************/
/*! \brief         Check if KeyM Cert submodule is busy.
 *  \details       -
 *  \return        TRUE            KeyM is busy with a task.
 *                 FALSE           KeyM is in idle state.
 *  \pre           The KeyM is initialized in advance.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, KEYM_CODE) KeyM_Cert_IsBusy(void);

# define KEYM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define KEYM_START_SEC_APPL_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Certificate Element Verification Callout Prototypes
 *********************************************************************************************************************/
/*!
 * \fn          Tsc_Appl_CertificateElementVerificationCallout
 * \brief       Verify certificate elements.
 * \details     Callout to verify that a given certificate fulfills the specified rules and conditions.
 * \param[in]   CertId                 Certificate identifier.
 * \param[in]   CertElementId          Certificate element identifier.
 * \param[in]   CertElementData        Pointer to certificate element data.
 * \param[in]   CertElementDataLength  Length of certificate element data.
 * \return      E_OK      Operation successful
 * \return      E_NOT_OK  Operation failed
 * \pre         -
 * \reentrant   TRUE
 * \synchronous TRUE
 */
extern FUNC(Std_ReturnType, KEYM_APPL_CODE) Tsc_Appl_CertificateElementVerificationCallout( KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, uint32 CertElementDataLength);

/**********************************************************************************************************************
 *  Certificate Get Current Time Callout Prototypes
 *********************************************************************************************************************/
/*!
 * \fn          TscAppl_KeyMCertificateGetCurrentTimeCalloutFunc
 * \brief       Provide current time
 * \details     Provide current time to verify certificate time stamp.
 * \param[in]   CertId     Certificate identifier.
 * \param[out]  timeStamp  Current time in Unix time format.
 * \return      E_OK                             Operation successful
 * \return      E_NOT_OK                         Operation failed
 * \return      KEYM_E_NO_PERIOD_VALIDITY_CHECK  Skip time stamp validation
 * \pre         -
 * \reentrant   TRUE
 * \synchronous TRUE
 */
extern FUNC(Std_ReturnType, KEYM_APPL_CODE) TscAppl_KeyMCertificateGetCurrentTimeCalloutFunc( KeyM_CertificateIdType CertId,  P2VAR(uint64, AUTOMATIC, KEYM_APPL_VAR) timeStamp);

# define KEYM_STOP_SEC_APPL_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* PRQA S 2995, 2996 InlineFunctions_2995_2996 */ /* MD_KEYM_2.2, MD_KEYM_2.2 */


#if !defined (KEYM_NOUNIT_CSLUNIT)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetDataInlineFunctions  KeyM Get Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to read CONST and VAR data.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageType, KEYM_CODE) KeyM_GetCertStorage(KeyM_CertStorageIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageType) (KeyM_GetCertStorageOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_CertInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(tKeyMCertInfoType, KEYM_CODE) KeyM_GetCert_CertInfo(KeyM_Cert_CertInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_GetCert_CertInfoOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_LeafCertsToVerify(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_GetCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateIdType) (KeyM_GetCert_LeafCertsToVerifyOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_Lock(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_LockType, KEYM_CODE) KeyM_IsCert_Lock(KeyM_Cert_LockIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_Cert_LockType) ((KeyM_GetCert_LockOfPCConfig()[(Index)]) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(tKeyMCertStorageType, KEYM_CODE) KeyM_GetCert_StorageType(KeyM_Cert_StorageTypeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (tKeyMCertStorageType) (KeyM_GetCert_StorageTypeOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_VerifyChain(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_GetCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateIdType) (KeyM_GetCert_VerifyChainOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertAlgorithmFamilyOfCertificateType, KEYM_CODE) KeyM_GetCertAlgorithmFamilyOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertAlgorithmFamilyOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertAlgorithmFamilyOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertCsmSignatureGenerateJobRefOfCertificateType, KEYM_CODE) KeyM_GetCertCsmSignatureGenerateJobRefOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertCsmSignatureGenerateJobRefOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertCsmSignatureGenerateJobRefOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertCsmSignatureVerifyJobRefOfCertificateType, KEYM_CODE) KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertCsmSignatureVerifyJobRefOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertCsmSignatureVerifyJobRefOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertCsmSignatureVerifyKeyRefOfCertificateType, KEYM_CODE) KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertCsmSignatureVerifyKeyRefOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertCsmSignatureVerifyKeyRefOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertFormatTypeOfCertificateType, KEYM_CODE) KeyM_GetCertFormatTypeOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertFormatTypeOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertFormatTypeOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStartUpHandlingOfCertificateType, KEYM_CODE) KeyM_GetCertStartUpHandlingOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStartUpHandlingOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertStartUpHandlingOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageLengthOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageLengthOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertStorageLengthOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStartIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageStartIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertStorageStartIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageWrittenLengthLengthOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageWrittenLengthLengthOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertStorageWrittenLengthLengthOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType, KEYM_CODE) KeyM_GetCertUpperHierarchicalCertRefIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertUpperHierarchicalCertRefIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertUpperHierarchicalTypeOfCertificateType, KEYM_CODE) KeyM_GetCertUpperHierarchicalTypeOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertUpperHierarchicalTypeOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertUpperHierarchicalTypeOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementEndIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateElementEndIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateElementEndIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementStartIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateElementStartIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateElementStartIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateGetCurrentTimeCalloutIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateGetCurrentTimeCalloutIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueInfoIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateInitValueInfoIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueInfoIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateInitValueInfoIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameEndIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateNameEndIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateNameEndIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameStartIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateNameStartIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateNameStartIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateVerifyCallbackNotificationWithoutIdIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateVerifyCallbackNotificationWithoutIdIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateVerifyCallbackNotificationWithoutIdIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateVerifyCallbackNotificationWithoutIdIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CsmKeyTargetRefOfCertificateType, KEYM_CODE) KeyM_GetCsmKeyTargetRefOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CsmKeyTargetRefOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CsmKeyTargetRefOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_MaskedBitsOfCertificateType, KEYM_CODE) KeyM_GetMaskedBitsOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_MaskedBitsOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].MaskedBitsOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ServiceCertificateRteCallbackNotification440IdxOfCertificateType, KEYM_CODE) KeyM_GetServiceCertificateRteCallbackNotification440IdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ServiceCertificateRteCallbackNotification440IdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].ServiceCertificateRteCallbackNotification440IdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_StorageOfCertificateType, KEYM_CODE) KeyM_GetStorageOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_StorageOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].StorageOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementVerificationCalloutIdxOfCertificateElementType, KEYM_CODE) KeyM_GetCertificateElementVerificationCalloutIdxOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateElementVerificationCalloutIdxOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].CertificateElementVerificationCalloutIdxOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidEndIdxOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidEndIdxOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidEndIdxOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].ElementOidEndIdxOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidStartIdxOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidStartIdxOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidStartIdxOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].ElementOidStartIdxOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_IdOfCertificateElementType, KEYM_CODE) KeyM_GetIdOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_IdOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].IdOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_MaskedBitsOfCertificateElementType, KEYM_CODE) KeyM_GetMaskedBitsOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_MaskedBitsOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].MaskedBitsOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_MaxLengthOfCertificateElementType, KEYM_CODE) KeyM_GetMaxLengthOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_MaxLengthOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].MaxLengthOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ObjectTypeOfCertificateElementType, KEYM_CODE) KeyM_GetObjectTypeOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ObjectTypeOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].ObjectTypeOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateStructureType, KEYM_CODE) KeyM_GetOfStructureOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateStructureType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].OfStructureOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElementVerificationCallout(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementVerificationCalloutFctPtrType, KEYM_CODE) KeyM_GetCertificateElementVerificationCallout(KeyM_CertificateElementVerificationCalloutIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateElementVerificationCalloutFctPtrType) (KeyM_GetCertificateElementVerificationCalloutOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGetCurrentTimeCallout(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutFctPtrType, KEYM_CODE) KeyM_GetCertificateGetCurrentTimeCallout(KeyM_CertificateGetCurrentTimeCalloutIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGetCurrentTimeCalloutFctPtrType) (KeyM_GetCertificateGetCurrentTimeCalloutOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValue(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueType, KEYM_CODE) KeyM_GetCertificateInitValue(KeyM_CertificateInitValueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueType) (KeyM_GetCertificateInitValueOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValueInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueLengthOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitValueLengthOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueLengthOfCertificateInitValueInfoType) (KeyM_GetCertificateInitValueInfoOfPCConfig()[(Index)].CertificateInitValueLengthOfCertificateInitValueInfo);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateName(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameType, KEYM_CODE) KeyM_GetCertificateName(KeyM_CertificateNameIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateNameType) (KeyM_GetCertificateNameOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateVerifyCallbackNotificationWithoutId(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateVerifyCallbackNotificationWithoutIdFctPtrType, KEYM_CODE) KeyM_GetCertificateVerifyCallbackNotificationWithoutId(KeyM_CertificateVerifyCallbackNotificationWithoutIdIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateVerifyCallbackNotificationWithoutIdFctPtrType) (KeyM_GetCertificateVerifyCallbackNotificationWithoutIdOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCommonCertData(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ConstCertDataType, KEYM_CODE) KeyM_GetCommonCertData(KeyM_CommonCertDataIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_GetCommonCertDataOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfElementOid(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidType, KEYM_CODE) KeyM_GetElementOid(KeyM_ElementOidIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidType) (KeyM_GetElementOidOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfElementStorageRef(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_Ans1_Element_Ref_Type, KEYM_CODE) KeyM_GetElementStorageRef(KeyM_ElementStorageRefIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_GetElementStorageRefOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfGeneral(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_KeyMCsmRemoteInfoJobRefAsyncOfGeneralType, KEYM_CODE) KeyM_IsKeyMCsmRemoteInfoJobRefAsyncOfGeneral(KeyM_GeneralIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_KeyMCsmRemoteInfoJobRefAsyncOfGeneralType) ((KeyM_GetGeneralOfPCConfig()[(Index)].KeyMCsmRemoteInfoJobRefAsyncOfGeneral) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfServiceCertificateRteCallbackNotification440(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ServiceCertificateRteCallbackNotification440FctPtrType, KEYM_CODE) KeyM_GetServiceCertificateRteCallbackNotification440(KeyM_ServiceCertificateRteCallbackNotification440IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ServiceCertificateRteCallbackNotification440FctPtrType) (KeyM_GetServiceCertificateRteCallbackNotification440OfPCConfig()[(Index)]);
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetBitDataInlineFunctions  KeyM Get Bit Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to read bitcoded data elements.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertAllowFlexibleElementOrderOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_CERTALLOWFLEXIBLEELEMENTORDEROFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_CERTALLOWFLEXIBLEELEMENTORDEROFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertAllowUnconfiguredElementsOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_CERTALLOWUNCONFIGUREDELEMENTSOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_CERTALLOWUNCONFIGUREDELEMENTSOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertCsmSignatureGenerateJobRefValidOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_CERTCSMSIGNATUREGENERATEJOBREFVALIDOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_CERTCSMSIGNATUREGENERATEJOBREFVALIDOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertCsmSignatureVerifyKeyRefValidOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCsmKeyTargetRefValidOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_CSMKEYTARGETREFVALIDOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_CSMKEYTARGETREFVALIDOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsKeyMCertCsmHashJobRefAsyncOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsKeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsKeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsHasIterationOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_HASITERATIONOFCERTIFICATEELEMENT_MASK == (KeyM_GetMaskedBitsOfCertificateElement(Index) & KEYM_HASITERATIONOFCERTIFICATEELEMENT_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsOptionalOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_OPTIONALOFCERTIFICATEELEMENT_MASK == (KeyM_GetMaskedBitsOfCertificateElement(Index) & KEYM_OPTIONALOFCERTIFICATEELEMENT_MASK));
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetDeduplicatedInlineFunctions  KeyM Get Deduplicated Inline Functions (PRE_COMPILE)
  \brief  These inline functions  can be used to read deduplicated data elements.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageEndIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageEndIdxOfCertificateType) ((KeyM_CertStorageEndIdxOfCertificateType)((KeyM_GetCertStorageStartIdxOfCertificate(Index) + 1000u)));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStatusEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStatusEndIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageStatusEndIdxOfCertificateType) KeyM_GetCertStorageStartIdxOfCertificate(Index);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStatusLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStatusLengthOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageStatusLengthOfCertificateType) ((KeyM_CertStorageStatusLengthOfCertificateType)((KeyM_GetCertStorageLengthOfCertificate(Index) - 998u)));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStatusStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStatusStartIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageStatusStartIdxOfCertificateType) ((KeyM_CertStorageStatusStartIdxOfCertificateType)((KeyM_GetCertStorageStartIdxOfCertificate(Index) - 2u)));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageUsedOfCertificateType, KEYM_CODE) KeyM_IsCertStorageUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageUsedOfCertificateType) (((boolean)(KeyM_GetCertStorageLengthOfCertificate(Index) != 0u)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageWrittenLengthEndIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageWrittenLengthEndIdxOfCertificateType) ((KeyM_CertStorageWrittenLengthEndIdxOfCertificateType)((KeyM_GetCertStorageStartIdxOfCertificate(Index) - 2u)));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageWrittenLengthStartIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageWrittenLengthStartIdxOfCertificateType) ((KeyM_CertStorageWrittenLengthStartIdxOfCertificateType)((KeyM_GetCertStorageStartIdxOfCertificate(Index) - 4u)));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthUsedOfCertificateType, KEYM_CODE) KeyM_IsCertStorageWrittenLengthUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertStorageWrittenLengthUsedOfCertificateType) (((boolean)(KeyM_GetCertStorageWrittenLengthLengthOfCertificate(Index) != 0u)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementLengthOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementLengthOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateElementLengthOfCertificateType) ((KeyM_CertificateElementLengthOfCertificateType)((KeyM_GetCertificateElementEndIdxOfCertificate(Index) - KeyM_GetCertificateElementStartIdxOfCertificate(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateElementUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateElementUsedOfCertificateType) (((boolean)(KeyM_GetCertificateElementLengthOfCertificate(Index) != 0u)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateGetCurrentTimeCalloutUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGetCurrentTimeCalloutUsedOfCertificateType) (((boolean)(KeyM_GetCertificateGetCurrentTimeCalloutIdxOfCertificate(Index) != KEYM_NO_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueInfoUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateInitValueInfoUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueInfoUsedOfCertificateType) (((boolean)(KeyM_GetCertificateInitValueInfoIdxOfCertificate(Index) != KEYM_NO_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameLengthOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameLengthOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateNameLengthOfCertificateType) ((KeyM_CertificateNameLengthOfCertificateType)((KeyM_GetCertificateNameEndIdxOfCertificate(Index) - KeyM_GetCertificateNameStartIdxOfCertificate(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateVerifyCallbackNotificationWithoutIdUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateVerifyCallbackNotificationWithoutIdUsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateVerifyCallbackNotificationWithoutIdUsedOfCertificateType) (((boolean)(KeyM_GetCertificateVerifyCallbackNotificationWithoutIdIdxOfCertificate(Index) != KEYM_NO_CERTIFICATEVERIFYCALLBACKNOTIFICATIONWITHOUTIDIDXOFCERTIFICATE)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_MaxLengthOfCertificateType, KEYM_CODE) KeyM_GetMaxLengthOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_MaxLengthOfCertificateType) KeyM_GetCertStorageLengthOfCertificate(Index);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_RemoteCertificateIdOfCertificateType, KEYM_CODE) KeyM_GetRemoteCertificateIdOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_RemoteCertificateIdOfCertificateType) ((KeyM_RemoteCertificateIdOfCertificateType)((KeyM_GetCertStorageLengthOfCertificate(Index) - 1000u)));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ServiceCertificateRteCallbackNotification440UsedOfCertificateType, KEYM_CODE) KeyM_IsServiceCertificateRteCallbackNotification440UsedOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ServiceCertificateRteCallbackNotification440UsedOfCertificateType) (((boolean)(KeyM_GetServiceCertificateRteCallbackNotification440IdxOfCertificate(Index) != KEYM_NO_SERVICECERTIFICATERTECALLBACKNOTIFICATION440IDXOFCERTIFICATE)) != FALSE);
}
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateChainMaxDepthOfGeneralType, KEYM_CODE) KeyM_GetCertificateChainMaxDepthOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateChainMaxDepthOfGeneralType) KeyM_GetCertificateChainMaxDepthOfGeneralOfPCConfig();
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementVerificationCalloutUsedOfCertificateElementType, KEYM_CODE) KeyM_IsCertificateElementVerificationCalloutUsedOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateElementVerificationCalloutUsedOfCertificateElementType) (((boolean)(KeyM_GetCertificateElementVerificationCalloutIdxOfCertificateElement(Index) != KEYM_NO_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT)) != FALSE);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidLengthOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidLengthOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidLengthOfCertificateElementType) ((KeyM_ElementOidLengthOfCertificateElementType)((KeyM_GetElementOidEndIdxOfCertificateElement(Index) - KeyM_GetElementOidStartIdxOfCertificateElement(Index))));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateElement(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidUsedOfCertificateElementType, KEYM_CODE) KeyM_IsElementOidUsedOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_ElementOidUsedOfCertificateElementType) (((boolean)(KeyM_GetElementOidLengthOfCertificateElement(Index) != 0u)) != FALSE);
}
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateExtensionValidationEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateExtensionValidationEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateExtensionValidationEnabledOfGeneralType) KeyM_IsCertificateExtensionValidationEnabledOfGeneralOfPCConfig();
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValueInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueEndIdxOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitValueEndIdxOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueEndIdxOfCertificateInitValueInfoType) ((KeyM_CertificateInitValueEndIdxOfCertificateInitValueInfoType)((((KeyM_CertificateInitValueEndIdxOfCertificateInitValueInfoType)(Index)) + 292u)));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValueInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueStartIdxOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetCertificateInitValueStartIdxOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueStartIdxOfCertificateInitValueInfoType) ((KeyM_CertificateInitValueStartIdxOfCertificateInitValueInfoType)((Index)));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValueInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValueUsedOfCertificateInitValueInfoType, KEYM_CODE) KeyM_IsCertificateInitValueUsedOfCertificateInitValueInfo(KeyM_CertificateInitValueInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateInitValueUsedOfCertificateInitValueInfoType) (((boolean)(KeyM_GetCertificateInitValueLengthOfCertificateInitValueInfo(Index) != 0u)) != FALSE);
}
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateManagerEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateManagerEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateManagerEnabledOfGeneralType) KeyM_IsCertificateManagerEnabledOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateSigningRequestEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateSigningRequestEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateSigningRequestEnabledOfGeneralType) KeyM_IsCertificateSigningRequestEnabledOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyPrepareFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyPrepareFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CryptoKeyPrepareFunctionEnabledOfGeneralType) KeyM_IsCryptoKeyPrepareFunctionEnabledOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyStartFinalizeFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyStartFinalizeFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CryptoKeyStartFinalizeFunctionEnabledOfGeneralType) KeyM_IsCryptoKeyStartFinalizeFunctionEnabledOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyVerifyAsyncModeOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyVerifyAsyncModeOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CryptoKeyVerifyAsyncModeOfGeneralType) KeyM_IsCryptoKeyVerifyAsyncModeOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_CryptoKeyVerifyFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsCryptoKeyVerifyFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CryptoKeyVerifyFunctionEnabledOfGeneralType) KeyM_IsCryptoKeyVerifyFunctionEnabledOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_KeyCertNameMaxLengthOfGeneralType, KEYM_CODE) KeyM_GetKeyCertNameMaxLengthOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_KeyCertNameMaxLengthOfGeneralType) KeyM_GetKeyCertNameMaxLengthOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_MainFunctionPeriodOfGeneralType, KEYM_CODE) KeyM_GetMainFunctionPeriodOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_MainFunctionPeriodOfGeneralType) KeyM_GetMainFunctionPeriodOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_ParseMaxNestingLevelOfGeneralType, KEYM_CODE) KeyM_GetParseMaxNestingLevelOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_ParseMaxNestingLevelOfGeneralType) KeyM_GetParseMaxNestingLevelOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_ServiceCertificateFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsServiceCertificateFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_ServiceCertificateFunctionEnabledOfGeneralType) KeyM_IsServiceCertificateFunctionEnabledOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertStorageType, KEYM_CODE) KeyM_GetSizeOfCertStorage(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertStorageType) KeyM_GetSizeOfCertStorageOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_CertInfoType, KEYM_CODE) KeyM_GetSizeOfCert_CertInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCert_CertInfoType) KeyM_GetSizeOfCert_CertInfoOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_LeafCertsToVerifyType, KEYM_CODE) KeyM_GetSizeOfCert_LeafCertsToVerify(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCert_LeafCertsToVerifyType) KeyM_GetSizeOfCert_LeafCertsToVerifyOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_LockType, KEYM_CODE) KeyM_GetSizeOfCert_Lock(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCert_LockType) KeyM_GetSizeOfCert_LockOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_StorageTypeType, KEYM_CODE) KeyM_GetSizeOfCert_StorageType(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCert_StorageTypeType) KeyM_GetSizeOfCert_StorageTypeOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_VerifyChainType, KEYM_CODE) KeyM_GetSizeOfCert_VerifyChain(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCert_VerifyChainType) KeyM_GetSizeOfCert_VerifyChainOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateType, KEYM_CODE) KeyM_GetSizeOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateType) KeyM_GetSizeOfCertificateOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateElementType, KEYM_CODE) KeyM_GetSizeOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateElementType) KeyM_GetSizeOfCertificateElementOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateElementVerificationCalloutType, KEYM_CODE) KeyM_GetSizeOfCertificateElementVerificationCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateElementVerificationCalloutType) KeyM_GetSizeOfCertificateElementVerificationCalloutOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateGetCurrentTimeCalloutType, KEYM_CODE) KeyM_GetSizeOfCertificateGetCurrentTimeCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateGetCurrentTimeCalloutType) KeyM_GetSizeOfCertificateGetCurrentTimeCalloutOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateInitValueType, KEYM_CODE) KeyM_GetSizeOfCertificateInitValue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateInitValueType) KeyM_GetSizeOfCertificateInitValueOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateInitValueInfoType, KEYM_CODE) KeyM_GetSizeOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateInitValueInfoType) KeyM_GetSizeOfCertificateInitValueInfoOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateNameType, KEYM_CODE) KeyM_GetSizeOfCertificateName(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateNameType) KeyM_GetSizeOfCertificateNameOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateVerifyCallbackNotificationWithoutIdType, KEYM_CODE) KeyM_GetSizeOfCertificateVerifyCallbackNotificationWithoutId(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateVerifyCallbackNotificationWithoutIdType) KeyM_GetSizeOfCertificateVerifyCallbackNotificationWithoutIdOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCommonCertDataType, KEYM_CODE) KeyM_GetSizeOfCommonCertData(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCommonCertDataType) KeyM_GetSizeOfCommonCertDataOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfElementOidType, KEYM_CODE) KeyM_GetSizeOfElementOid(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfElementOidType) KeyM_GetSizeOfElementOidOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfElementStorageRefType, KEYM_CODE) KeyM_GetSizeOfElementStorageRef(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfElementStorageRefType) KeyM_GetSizeOfElementStorageRefOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfGeneralType, KEYM_CODE) KeyM_GetSizeOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfGeneralType) KeyM_GetSizeOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfServiceCertificateRteCallbackNotification440Type, KEYM_CODE) KeyM_GetSizeOfServiceCertificateRteCallbackNotification440(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfServiceCertificateRteCallbackNotification440Type) KeyM_GetSizeOfServiceCertificateRteCallbackNotification440OfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_VersionInfoApiOfGeneralType, KEYM_CODE) KeyM_IsVersionInfoApiOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_VersionInfoApiOfGeneralType) KeyM_IsVersionInfoApiOfGeneralOfPCConfig();
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCSetDataInlineFunctions  KeyM Set Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to write data.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCertStorage(KeyM_CertStorageIterType Index, KeyM_CertStorageType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCertStorageOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_CertInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_CertInfo(KeyM_Cert_CertInfoIterType Index, tKeyMCertInfoType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_CertInfoOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_LeafCertsToVerify(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_LeafCertsToVerifyOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_Lock(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_Lock(KeyM_Cert_LockIterType Index, KeyM_Cert_LockType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_LockOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_StorageType(KeyM_Cert_StorageTypeIterType Index, tKeyMCertStorageType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_StorageTypeOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfCert_VerifyChain(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_VerifyChainOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfCommonCertData(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetCommonCertData(KeyM_CommonCertDataIterType Index, KeyM_ConstCertDataType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCommonCertDataOfPCConfig()[(Index)] = (Value);
}
/*! \spec requires Index < KeyM_GetSizeOfElementStorageRef(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SetElementStorageRef(KeyM_ElementStorageRefIterType Index, KeyM_Ans1_Element_Ref_Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetElementStorageRefOfPCConfig()[(Index)] = (Value);
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCGetAddressOfDataInlineFunctions  KeyM Get Address Of Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to get the data by the address operator.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertStoragePtrType, KEYM_CODE) KeyM_GetAddrCertStorage(KeyM_CertStorageIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertStoragePtrType) (&(KeyM_GetCertStorageOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_CertInfo(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_CertInfoPtrType, KEYM_CODE) KeyM_GetAddrCert_CertInfo(KeyM_Cert_CertInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (&(KeyM_GetCert_CertInfoOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_Lock(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_LockPtrType, KEYM_CODE) KeyM_GetAddrCert_Lock(KeyM_Cert_LockIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_Cert_LockPtrType) (&(KeyM_GetCert_LockOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_StorageTypePtrType, KEYM_CODE) KeyM_GetAddrCert_StorageType(KeyM_Cert_StorageTypeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_Cert_StorageTypePtrType) (&(KeyM_GetCert_StorageTypeOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateInitValue(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateInitValuePtrType, KEYM_CODE) KeyM_GetAddrCertificateInitValue(KeyM_CertificateInitValueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateInitValuePtrType) (&(KeyM_GetCertificateInitValueOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateName(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNamePtrType, KEYM_CODE) KeyM_GetAddrCertificateName(KeyM_CertificateNameIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateNamePtrType) (&(KeyM_GetCertificateNameOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfCommonCertData(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CommonCertDataPtrType, KEYM_CODE) KeyM_GetAddrCommonCertData(KeyM_CommonCertDataIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (&(KeyM_GetCommonCertDataOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfElementOid(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidPtrType, KEYM_CODE) KeyM_GetAddrElementOid(KeyM_ElementOidIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_ElementOidPtrType) (&(KeyM_GetElementOidOfPCConfig()[(Index)]));
}
/*! \spec requires Index < KeyM_GetSizeOfElementStorageRef(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_ElementStorageRefPtrType, KEYM_CODE) KeyM_GetAddrElementStorageRef(KeyM_ElementStorageRefIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (&(KeyM_GetElementStorageRefOfPCConfig()[(Index)]));
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCHasInlineFunctions  KeyM Has Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorage(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_CertInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_LeafCertsToVerify(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_Lock(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_StorageType(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_VerifyChain(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAlgorithmFamilyOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAllowFlexibleElementOrderOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAllowUnconfiguredElementsOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureGenerateJobRefOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureGenerateJobRefValidOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureVerifyJobRefOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureVerifyKeyRefOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertCsmSignatureVerifyKeyRefValidOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertFormatTypeOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStartUpHandlingOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageEndIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageLengthOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStartIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStatusEndIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStatusLengthOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageStatusStartIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthEndIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthLengthOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthStartIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageWrittenLengthUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertUpperHierarchicalCertRefIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertUpperHierarchicalTypeOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementEndIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementLengthOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementStartIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfoIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfoUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameEndIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameLengthOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameStartIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateVerifyCallbackNotificationWithoutIdIdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateVerifyCallbackNotificationWithoutIdUsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCsmKeyTargetRefOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCsmKeyTargetRefValidOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmHashJobRefAsyncOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaskedBitsOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaxLengthOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasRemoteCertificateIdOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateRteCallbackNotification440IdxOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateRteCallbackNotification440UsedOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasStorageOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateChainMaxDepthOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementVerificationCalloutIdxOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementVerificationCalloutUsedOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidEndIdxOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidLengthOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidStartIdxOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidUsedOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasHasIterationOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasIdOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaskedBitsOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaxLengthOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasObjectTypeOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasOfStructureOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasOptionalOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementVerificationCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateExtensionValidationEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueEndIdxOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueLengthOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueStartIdxOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueUsedOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateManagerEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateName(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSigningRequestEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateVerifyCallbackNotificationWithoutId(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCommonCertData(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyPrepareFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyStartFinalizeFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyAsyncModeOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOid(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementStorageRef(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCsmRemoteInfoJobRefAsyncOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyCertNameMaxLengthOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMainFunctionPeriodOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasParseMaxNestingLevelOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateFunctionEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateRteCallbackNotification440(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertStorage(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_CertInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LeafCertsToVerify(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_Lock(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_StorageType(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_VerifyChain(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElement(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElementVerificationCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGetCurrentTimeCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValueInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateName(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateVerifyCallbackNotificationWithoutId(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCommonCertData(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementOid(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementStorageRef(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfServiceCertificateRteCallbackNotification440(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasVersionInfoApiOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_CertInfoOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_LeafCertsToVerifyOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_LockOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_StorageTypeOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_VerifyChainOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateChainMaxDepthOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementVerificationCalloutOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateExtensionValidationEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueInfoOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateInitValueOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateManagerEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSigningRequestEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateVerifyCallbackNotificationWithoutIdOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCommonCertDataOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyPrepareFunctionEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyStartFinalizeFunctionEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyAsyncModeOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCryptoKeyVerifyFunctionEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementStorageRefOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyCertNameMaxLengthOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMainFunctionPeriodOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasParseMaxNestingLevelOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateFunctionEnabledOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateRteCallbackNotification440OfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertStorageOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_CertInfoOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LeafCertsToVerifyOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LockOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_StorageTypeOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_VerifyChainOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElementOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElementVerificationCalloutOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGetCurrentTimeCalloutOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValueInfoOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateInitValueOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateNameOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateVerifyCallbackNotificationWithoutIdOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCommonCertDataOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementOidOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementStorageRefOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfServiceCertificateRteCallbackNotification440OfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasVersionInfoApiOfGeneralOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCIncrementInlineFunctions  KeyM Increment Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to increment VAR data with numerical nature.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCertStorage(KeyM_CertStorageIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCertStorageOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfCert_LeafCertsToVerify(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_LeafCertsToVerifyOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCert_StorageType(KeyM_Cert_StorageTypeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_StorageTypeOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfCert_VerifyChain(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_IncCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_VerifyChainOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCDecrementInlineFunctions  KeyM Decrement Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to decrement VAR data with numerical nature.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCertStorage(KeyM_CertStorageIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCertStorageOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfCert_LeafCertsToVerify(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_LeafCertsToVerifyOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCert_StorageType(KeyM_Cert_StorageTypeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_StorageTypeOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/*! \spec requires Index < KeyM_GetSizeOfCert_VerifyChain(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_DecCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_GetCert_VerifyChainOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCAddInlineFunctions  KeyM Add Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to add VAR data with numerical nature.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCertStorage(KeyM_CertStorageIterType Index, KeyM_CertStorageType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCertStorage(Index, (KeyM_GetCertStorageOfPCConfig()[(Index)] + Value));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_LeafCertsToVerify(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCert_LeafCertsToVerify(Index, (KeyM_GetCert_LeafCertsToVerifyOfPCConfig()[(Index)] + Value));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCert_StorageType(KeyM_Cert_StorageTypeIterType Index, tKeyMCertStorageType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCert_StorageType(Index, (KeyM_GetCert_StorageTypeOfPCConfig()[(Index)] + Value));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_VerifyChain(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_AddCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCert_VerifyChain(Index, (KeyM_GetCert_VerifyChainOfPCConfig()[(Index)] + Value));
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define KEYM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  KeyMPCSubstractInlineFunctions  KeyM Substract Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to substract VAR data with numerical nature.
  \{
*/ 
/*! \spec requires Index < KeyM_GetSizeOfCertStorage(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCertStorage(KeyM_CertStorageIterType Index, KeyM_CertStorageType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCertStorage(Index, (KeyM_GetCertStorageOfPCConfig()[(Index)] - Value));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_LeafCertsToVerify(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCert_LeafCertsToVerify(KeyM_Cert_LeafCertsToVerifyIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCert_LeafCertsToVerify(Index, (KeyM_GetCert_LeafCertsToVerifyOfPCConfig()[(Index)] - Value));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCert_StorageType(KeyM_Cert_StorageTypeIterType Index, tKeyMCertStorageType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCert_StorageType(Index, (KeyM_GetCert_StorageTypeOfPCConfig()[(Index)] - Value));
}
/*! \spec requires Index < KeyM_GetSizeOfCert_VerifyChain(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_SubCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index, KeyM_CertificateIdType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KeyM_SetCert_VerifyChain(Index, (KeyM_GetCert_VerifyChainOfPCConfig()[(Index)] - Value));
}
/** 
  \}
*/ 

#define KEYM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


#endif

/* PRQA L:InlineFunctions_2995_2996 */


#endif /* KEYM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: KeyM_Cfg.h
 *********************************************************************************************************************/

