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
 *              File: KeyM_Cfg.h
 *   Generation Time: 2023-08-02 09:54:12
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
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
#include "Csm.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef KEYM_USE_DUMMY_STATEMENT
#define KEYM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef KEYM_DUMMY_STATEMENT
#define KEYM_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef KEYM_DUMMY_STATEMENT_CONST
#define KEYM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
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
#define KEYM_ALGORITHM_ECDSA_ENABLED                                                                STD_ON
#define KEYM_ALGORITHM_EDDSA_ENABLED                                                                STD_OFF
#define KEYM_CERTIFICATEEXTENSION_MAX_LENGTH                                                        20u
#define KEYM_CERTIFICATEISSUERNAME_MAX_LENGTH                                                       10u
#define KEYM_CERTIFICATEISSUERUNIQUEIDENTIFIER_MAX_LENGTH                                           0u
#define KEYM_CERTIFICATESERIALNUMBER_MAX_LENGTH                                                     16u
#define KEYM_CERTIFICATESIGNATURE_MAX_LENGTH                                                        64u
#define KEYM_CERTIFICATESIGNATUREALGORITHM_MAX_LENGTH                                               1u
#define KEYM_CERTIFICATESIGNATUREALGORITHMID_MAX_LENGTH                                             1u
#define KEYM_CERTIFICATESUBJECTNAME_MAX_LENGTH                                                      10u
#define KEYM_CERTIFICATESUBJECTPUBLICKEYINFO_PUBLICKEYALGORITHM_MAX_LENGTH                          1u
#define KEYM_CERTIFICATESUBJECTPUBLICKEYINFO_SUBJECTPUBLICKEY_MAX_LENGTH                            32u
#define KEYM_CERTIFICATESUBJECTUNIQUEIDENTIFIER_MAX_LENGTH                                          0u
#define KEYM_CERTIFICATEVALIDITYPERIODNOTAFTER_MAX_LENGTH                                           1u
#define KEYM_CERTIFICATEVALIDITYPERIODNOTBEFORE_MAX_LENGTH                                          1u
#define KEYM_CERTIFICATEVERSIONNUMBER_MAX_LENGTH                                                    1u
#define KEYM_CERTIFICATEREVOCATIONLIST_MAX_LENGTH                                                   0u
#define KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH                                                         32u
#define KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH                                                       64u
#define KEYM_OPTIONAL_CERTIFICATE_ELEMENT_ENABLED                                                   STD_OFF
#define KEYM_HAS_ITERATION_CERTIFICATE_ELEMENT_ENABLED                                              STD_ON
#define KEYM_ROM_CERTIFICATES                                                                       STD_OFF
/* Microsar Define Block for Boolean and Integers */
#define KEYM_CERTIFICATE_CHAIN_MAX_DEPTH                                                            2u 
#define KEYM_CERTIFICATE_MANAGER_ENABLED                                                            STD_ON 
#define KEYM_CRYPTO_KEY_PREPARE_FUNCTION_ENABLED                                                    STD_OFF 
#define KEYM_CRYPTO_KEY_START_FINALIZE_FUNCTION_ENABLED                                             STD_OFF 
#define KEYM_CRYPTO_KEY_VERIFY_ASYNC_MODE                                                           STD_OFF 
#define KEYM_CRYPTO_KEY_VERIFY_FUNCTION_ENABLED                                                     STD_OFF 
#define KEYM_KEY_CERT_NAME_MAX_LENGTH                                                               39u 
#define KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED                                                   STD_ON 
#define KEYM_VERSION_INFO_API                                                                       STD_OFF 
#define KEYM_PARSE_MAX_NESTING_LEVEL                                                                20u 
#define KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED                                                    STD_OFF 
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
#define KeyMConf_KeyMCertificate_KeyMCertificate_OSSL_X509_ECDSA_P384_CA                            0u 
#define KeyMConf_KeyMCertificate_KeyMCertificate_OSSL_X509_ECDSA_P384_IA                            1u 

#define KEYM_CRL                                                                                    0x00u 
#define KEYM_CVC                                                                                    0x01u 
#define KEYM_X509                                                                                   0x02u 
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
#define KEYM_CERTIFICATE_EXTENSION                                                                  0x00u 
#define KEYM_CERTIFICATE_ISSUER_NAME                                                                0x01u 
#define KEYM_CERTIFICATE_ISSUER_UNIQUE_IDENTIFIER                                                   0x02u 
#define KEYM_CERTIFICATE_REVOCATION_LIST                                                            0x03u 
#define KEYM_CERTIFICATE_SERIAL_NUMBER                                                              0x04u 
#define KEYM_CERTIFICATE_SIGNATURE                                                                  0x05u 
#define KEYM_CERTIFICATE_SIGNATURE_ALGORITHM                                                        0x06u 
#define KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID                                                     0x07u 
#define KEYM_CERTIFICATE_SUBJECT_NAME                                                               0x08u 
#define KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM                               0x09u 
#define KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY                                 0x0Au 
#define KEYM_CERTIFICATE_SUBJECT_UNIQUE_IDENTIFIER                                                  0x0Bu 
#define KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER                                                  0x0Cu 
#define KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE                                                 0x0Du 
#define KEYM_CERTIFICATE_VERSION_NUMBER                                                             0x0Eu 

#define KEYM_DEFERRED                                                                               0u
#define KEYM_IMMEDIATE                                                                              1u
#define KEYM_CERTIFICATE_NVMBLOCK                                                                   STD_OFF
#define KEYM_NUMBER_OF_CERTIFICATES                                                                 2u
#define KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO                                                    0x80u
#define KEYM_CERTIFICATE_VALIDITY_PERIOD                                                            0x81u
#define KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ECC_CURVE                               0x82u
#define KeyMConf_KeyMCertificateElement_Version_009                        0u 
#define KeyMConf_KeyMCertificateElement_Version_010                        0u 
#define KeyMConf_KeyMCertificateElement_SerialNo_009                       1u 
#define KeyMConf_KeyMCertificateElement_SerialNo_010                       1u 
#define KeyMConf_KeyMCertificateElement_SigAlgoId_009                      2u 
#define KeyMConf_KeyMCertificateElement_SigAlgoId_010                      2u 
#define KeyMConf_KeyMCertificateElement_Issuer_CountryName_005             3u 
#define KeyMConf_KeyMCertificateElement_Issuer_CountryName_006             3u 
#define KeyMConf_KeyMCertificateElement_Issuer_StateOrProvinceName_005     4u 
#define KeyMConf_KeyMCertificateElement_Issuer_StateOrProvinceName_006     4u 
#define KeyMConf_KeyMCertificateElement_Issuer_LocalityName_005            5u 
#define KeyMConf_KeyMCertificateElement_Issuer_LocalityName_006            5u 
#define KeyMConf_KeyMCertificateElement_Issuer_OrganizationName_005        6u 
#define KeyMConf_KeyMCertificateElement_Issuer_OrganizationName_006        6u 
#define KeyMConf_KeyMCertificateElement_Issuer_CommonName_005              7u 
#define KeyMConf_KeyMCertificateElement_Issuer_CommonName_006              7u 
#define KeyMConf_KeyMCertificateElement_validityNotBefore_009              8u 
#define KeyMConf_KeyMCertificateElement_validityNotBefore_010              8u 
#define KeyMConf_KeyMCertificateElement_validityNotAfter_009               9u 
#define KeyMConf_KeyMCertificateElement_validityNotAfter_010               9u 
#define KeyMConf_KeyMCertificateElement_Subject_CommonName_006             10u 
#define KeyMConf_KeyMCertificateElement_Subject_CountryName_004            10u 
#define KeyMConf_KeyMCertificateElement_Subject_StateOrProvinceName_005    11u 
#define KeyMConf_KeyMCertificateElement_Subject_StateOrProvinceName_006    11u 
#define KeyMConf_KeyMCertificateElement_Subject_CountryName_005            12u 
#define KeyMConf_KeyMCertificateElement_Subject_LocalityName_005           12u 
#define KeyMConf_KeyMCertificateElement_Subject_OrganizationName_005       13u 
#define KeyMConf_KeyMCertificateElement_Subject_OrganizationName_006       13u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoAlgo_010       14u 
#define KeyMConf_KeyMCertificateElement_Subject_CommonName_005             14u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoAlgo_009       15u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoAlgo_Curve_005 15u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoAlgo_Curve_004 16u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoKey_010        16u 
#define KeyMConf_KeyMCertificateElement_SubjectPublicKeyInfoKey_009        17u 
#define KeyMConf_KeyMCertificateElement_ext1_010                           17u 
#define KeyMConf_KeyMCertificateElement_ext1_009                           18u 
#define KeyMConf_KeyMCertificateElement_ext2_010                           18u 
#define KeyMConf_KeyMCertificateElement_ext2_009                           19u 
#define KeyMConf_KeyMCertificateElement_ext3_010                           19u 
#define KeyMConf_KeyMCertificateElement_ext3_009                           20u 
#define KeyMConf_KeyMCertificateElement_signatureAlgorithm_010             20u 
#define KeyMConf_KeyMCertificateElement_signatureAlgorithm_009             21u 
#define KeyMConf_KeyMCertificateElement_signatureValue_010                 21u 
#define KeyMConf_KeyMCertificateElement_signatureValue_009                 22u 

#define KEYM_MAX_CERTIFICATE_MAX_LENGTH                                                             600u
#define KEYM_MAX_NUM_CSR_EXTENSIONS                                                                 1u
#define KEYM_MAX_NUM_CERT_ELEMENTS                                                                  23u
#define KEYM_CSM_SYNC_SIGNATURE_VERIFY                                                              STD_ON
#define KEYM_CSM_ASYNC_SIGNATURE_VERIFY                                                             STD_OFF
#define KEYM_MAX_NUM_EXTENSIONS                                                                     3u
#define KEYM_MAX_NUM_SUBJECT_NAME_COMPONENTS                                                        5u
#define KEYM_REMOTE_DISPATCHING_ENABLED                                                             STD_OFF
#define KEYM_REMOTE_REDIRECTION_ENABLED                                                             STD_OFF
#ifndef KEYM_DEV_ERROR_DETECT
#define KEYM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef KEYM_DEV_ERROR_REPORT
#define KEYM_DEV_ERROR_REPORT STD_ON
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
#define KEYM_CERTSTORAGE                                                                            STD_ON
#define KEYM_CERT_CERTINFO                                                                          STD_ON
#define KEYM_CERT_LEAFCERTSTOVERIFY                                                                 STD_ON
#define KEYM_CERT_STORAGETYPE                                                                       STD_ON
#define KEYM_CERT_VERIFYCHAIN                                                                       STD_ON
#define KEYM_CERTIFICATE                                                                            STD_ON
#define KEYM_CERTALGORITHMFAMILYOFCERTIFICATE                                                       STD_ON
#define KEYM_CERTALLOWFLEXIBLEELEMENTORDEROFCERTIFICATE                                             STD_ON
#define KEYM_CERTALLOWUNCONFIGUREDELEMENTSOFCERTIFICATE                                             STD_ON
#define KEYM_CERTCSMHASHJOBREFOFCERTIFICATE                                                         STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertCsmHashJobRef' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmHashJobRef not configured.' */
#define KEYM_CERTCSMHASHJOBREFVALIDOFCERTIFICATE                                                    STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertCsmHashJobRefValid' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmHashJobRef not configured.' */
#define KEYM_CERTCSMSIGNATUREGENERATEJOBREFOFCERTIFICATE                                            STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertCsmSignatureGenerateJobRef' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureGenerateJobRef not configured.' */
#define KEYM_CERTCSMSIGNATUREGENERATEJOBREFVALIDOFCERTIFICATE                                       STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertCsmSignatureGenerateJobRefValid' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureGenerateJobRef not configured.' */
#define KEYM_CERTCSMSIGNATUREVERIFYJOBREFOFCERTIFICATE                                              STD_ON
#define KEYM_CERTCSMSIGNATUREVERIFYKEYREFOFCERTIFICATE                                              STD_ON
#define KEYM_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE                                         STD_ON
#define KEYM_CERTFORMATTYPEOFCERTIFICATE                                                            STD_ON
#define KEYM_CERTHASHSTORAGEENDIDXOFCERTIFICATE                                                     STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashStorageEndIdx' Reason: 'the optional indirection is deactivated because CertHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTHASHSTORAGELENGTHOFCERTIFICATE                                                     STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashStorageLength' Reason: 'the optional indirection is deactivated because CertHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTHASHSTORAGESTARTIDXOFCERTIFICATE                                                   STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashStorageStartIdx' Reason: 'the optional indirection is deactivated because CertHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTHASHSTORAGEUSEDOFCERTIFICATE                                                       STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertHashStorageUsed' Reason: 'the optional indirection is deactivated because CertHashStorageUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
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
#define KEYM_CERTUSEPORTOFCERTIFICATE                                                               STD_ON
#define KEYM_CERTIFICATEELEMENTENDIDXOFCERTIFICATE                                                  STD_ON
#define KEYM_CERTIFICATEELEMENTLENGTHOFCERTIFICATE                                                  STD_ON
#define KEYM_CERTIFICATEELEMENTSTARTIDXOFCERTIFICATE                                                STD_ON
#define KEYM_CERTIFICATEELEMENTUSEDOFCERTIFICATE                                                    STD_ON
#define KEYM_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE                                       STD_ON
#define KEYM_CERTIFICATEGETCURRENTTIMECALLOUTUSEDOFCERTIFICATE                                      STD_ON
#define KEYM_CERTIFICATEGROUPIDXOFCERTIFICATE                                                       STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateGroupIdx' Reason: 'the optional indirection is deactivated because CertificateGroupUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE                                                      STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateGroupUsed' Reason: 'the optional indirection is deactivated because CertificateGroupUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEINITVALUEINFOIDXOFCERTIFICATE                                               STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateInitValueInfoIdx' Reason: 'the optional indirection is deactivated because CertificateInitValueInfoUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEINITVALUEINFOUSEDOFCERTIFICATE                                              STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateInitValueInfoUsed' Reason: 'the optional indirection is deactivated because CertificateInitValueInfoUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATENAMEENDIDXOFCERTIFICATE                                                     STD_ON
#define KEYM_CERTIFICATENAMELENGTHOFCERTIFICATE                                                     STD_ON
#define KEYM_CERTIFICATENAMESTARTIDXOFCERTIFICATE                                                   STD_ON
#define KEYM_CERTIFICATESETKEYCALLOUTIDXOFCERTIFICATE                                               STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateSetKeyCalloutIdx' Reason: 'the optional indirection is deactivated because CertificateSetKeyCalloutUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATESETKEYCALLOUTUSEDOFCERTIFICATE                                              STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateSetKeyCalloutUsed' Reason: 'the optional indirection is deactivated because CertificateSetKeyCalloutUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE                                                       STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateSlotUsed' Reason: 'the optional indirection is deactivated because CertificateSlotUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONIDXOFCERTIFICATE                                  STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateVerifyCallbackNotificationIdx' Reason: 'the optional indirection is deactivated because CertificateVerifyCallbackNotificationUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONUSEDOFCERTIFICATE                                 STD_OFF  /**< Deactivateable: 'KeyM_Certificate.CertificateVerifyCallbackNotificationUsed' Reason: 'the optional indirection is deactivated because CertificateVerifyCallbackNotificationUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
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
#define KEYM_RTECALLBACKNOTIFICATIONIDXOFCERTIFICATE                                                STD_OFF  /**< Deactivateable: 'KeyM_Certificate.RteCallbackNotificationIdx' Reason: 'the optional indirection is deactivated because RteCallbackNotificationUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_RTECALLBACKNOTIFICATIONUSEDOFCERTIFICATE                                               STD_OFF  /**< Deactivateable: 'KeyM_Certificate.RteCallbackNotificationUsed' Reason: 'the optional indirection is deactivated because RteCallbackNotificationUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE                                 STD_OFF  /**< Deactivateable: 'KeyM_Certificate.ServiceCertificateCallbackNotificationIdx' Reason: 'the optional indirection is deactivated because ServiceCertificateCallbackNotificationUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONUSEDOFCERTIFICATE                                STD_OFF  /**< Deactivateable: 'KeyM_Certificate.ServiceCertificateCallbackNotificationUsed' Reason: 'the optional indirection is deactivated because ServiceCertificateCallbackNotificationUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_SLOTREFIDXOFCERTIFICATE                                                                STD_OFF  /**< Deactivateable: 'KeyM_Certificate.SlotRefIdx' Reason: 'the optional indirection is deactivated because CertificateSlotUsedOfCertificate is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_STORAGEOFCERTIFICATE                                                                   STD_ON
#define KEYM_CERTIFICATECHAINMAXDEPTHOFGENERAL                                                      STD_ON
#define KEYM_CERTIFICATEELEMENT                                                                     STD_ON
#define KEYM_CERTELEMENTPATHENDIDXOFCERTIFICATEELEMENT                                              STD_OFF  /**< Deactivateable: 'KeyM_CertificateElement.CertElementPathEndIdx' Reason: 'the optional indirection is deactivated because CertElementPathUsedOfCertificateElement is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTELEMENTPATHLENGTHOFCERTIFICATEELEMENT                                              STD_OFF  /**< Deactivateable: 'KeyM_CertificateElement.CertElementPathLength' Reason: 'the optional indirection is deactivated because CertElementPathUsedOfCertificateElement is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTELEMENTPATHSTARTIDXOFCERTIFICATEELEMENT                                            STD_OFF  /**< Deactivateable: 'KeyM_CertificateElement.CertElementPathStartIdx' Reason: 'the optional indirection is deactivated because CertElementPathUsedOfCertificateElement is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTELEMENTPATHUSEDOFCERTIFICATEELEMENT                                                STD_OFF  /**< Deactivateable: 'KeyM_CertificateElement.CertElementPathUsed' Reason: 'the optional indirection is deactivated because CertElementPathUsedOfCertificateElement is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEELEMENTVERIFICATIONCALLOUTIDXOFCERTIFICATEELEMENT                           STD_OFF  /**< Deactivateable: 'KeyM_CertificateElement.CertificateElementVerificationCalloutIdx' Reason: 'the optional indirection is deactivated because CertificateElementVerificationCalloutUsedOfCertificateElement is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define KEYM_CERTIFICATEELEMENTVERIFICATIONCALLOUTUSEDOFCERTIFICATEELEMENT                          STD_OFF  /**< Deactivateable: 'KeyM_CertificateElement.CertificateElementVerificationCalloutUsed' Reason: 'the optional indirection is deactivated because CertificateElementVerificationCalloutUsedOfCertificateElement is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
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
#define KEYM_CERTIFICATEELEMENTVERIFICATIONCALLOUT                                                  STD_OFF  /**< Deactivateable: 'KeyM_CertificateElementVerificationCallout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
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
#define KEYM_CERTIFICATEINITVALUE                                                                   STD_OFF  /**< Deactivateable: 'KeyM_CertificateInitValue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEINITVALUEINFO                                                               STD_OFF  /**< Deactivateable: 'KeyM_CertificateInitValueInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define KEYM_CERTIFICATEINITCALLOUTIDXOFCERTIFICATEINITVALUEINFO                                    STD_OFF  /**< Deactivateable: 'KeyM_CertificateInitValueInfo.CertificateInitCalloutIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEINITCALLOUTUSEDOFCERTIFICATEINITVALUEINFO                                   STD_OFF  /**< Deactivateable: 'KeyM_CertificateInitValueInfo.CertificateInitCalloutUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEINITVALUEENDIDXOFCERTIFICATEINITVALUEINFO                                   STD_OFF  /**< Deactivateable: 'KeyM_CertificateInitValueInfo.CertificateInitValueEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEINITVALUELENGTHOFCERTIFICATEINITVALUEINFO                                   STD_OFF  /**< Deactivateable: 'KeyM_CertificateInitValueInfo.CertificateInitValueLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEINITVALUESTARTIDXOFCERTIFICATEINITVALUEINFO                                 STD_OFF  /**< Deactivateable: 'KeyM_CertificateInitValueInfo.CertificateInitValueStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEINITVALUEUSEDOFCERTIFICATEINITVALUEINFO                                     STD_OFF  /**< Deactivateable: 'KeyM_CertificateInitValueInfo.CertificateInitValueUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEMANAGERENABLEDOFGENERAL                                                     STD_ON
#define KEYM_CERTIFICATENAME                                                                        STD_ON
#define KEYM_CERTIFICATESETKEYCALLOUT                                                               STD_OFF  /**< Deactivateable: 'KeyM_CertificateSetKeyCallout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATESIGNINGREQUESTENABLEDOFGENERAL                                              STD_ON
#define KEYM_CERTIFICATESLOT                                                                        STD_OFF  /**< Deactivateable: 'KeyM_CertificateSlot' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define KEYM_IDOFCERTIFICATESLOT                                                                    STD_OFF  /**< Deactivateable: 'KeyM_CertificateSlot.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_MAXLENGTHOFCERTIFICATESLOT                                                             STD_OFF  /**< Deactivateable: 'KeyM_CertificateSlot.MaxLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATION                                                  STD_OFF  /**< Deactivateable: 'KeyM_CertificateVerifyCallbackNotification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_COMMONCERTDATA                                                                         STD_ON
#define KEYM_CRYPTOKEYPREPAREFUNCTIONENABLEDOFGENERAL                                               STD_OFF  /**< Deactivateable: 'KeyM_CryptoKeyPrepareFunctionEnabledOfGeneral' Reason: 'Parameter is not configured!' */
#define KEYM_CRYPTOKEYSTARTFINALIZEFUNCTIONENABLEDOFGENERAL                                         STD_OFF  /**< Deactivateable: 'KeyM_CryptoKeyStartFinalizeFunctionEnabledOfGeneral' Reason: 'Parameter is not configured!' */
#define KEYM_CRYPTOKEYVERIFYASYNCMODEOFGENERAL                                                      STD_OFF  /**< Deactivateable: 'KeyM_CryptoKeyVerifyAsyncModeOfGeneral' Reason: 'Parameter is not configured!' */
#define KEYM_CRYPTOKEYVERIFYFUNCTIONENABLEDOFGENERAL                                                STD_OFF  /**< Deactivateable: 'KeyM_CryptoKeyVerifyFunctionEnabledOfGeneral' Reason: 'Parameter is not configured!' */
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
#define KEYM_CERTIFICATEGROUPUSEDOFOCSP                                                             STD_OFF  /**< Deactivateable: 'KeyM_OCSP.CertificateGroupUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_CERTIFICATEIDXOFOCSP                                                                   STD_OFF  /**< Deactivateable: 'KeyM_OCSP.CertificateIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_DELEGATEDRESPONDERREFIDXOFOCSP                                                         STD_OFF  /**< Deactivateable: 'KeyM_OCSP.DelegatedResponderRefIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_KEYMOCSPRESPONDERPUBKEYHASHCSMJOBREFASYNCOFOCSP                                        STD_OFF  /**< Deactivateable: 'KeyM_OCSP.KeyMOCSPResponderPubKeyHashCsmJobRefAsync' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_KEYMOCSPRESPONSECERTIDHASHCSMJOBREFASYNCOFOCSP                                         STD_OFF  /**< Deactivateable: 'KeyM_OCSP.KeyMOCSPResponseCertIdHashCsmJobRefAsync' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_RESPONDERPUBKEYHASHCSMJOBREFOFOCSP                                                     STD_OFF  /**< Deactivateable: 'KeyM_OCSP.ResponderPubKeyHashCsmJobRef' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMOCSP/KeyMOCSPResponderPubKeyHashCsmJobRef not configured.' */
#define KEYM_RESPONDERPUBKEYHASHCSMJOBREFVALIDOFOCSP                                                STD_OFF  /**< Deactivateable: 'KeyM_OCSP.ResponderPubKeyHashCsmJobRefValid' Reason: 'DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMOCSP/KeyMOCSPResponderPubKeyHashCsmJobRef not configured.' */
#define KEYM_RESPONSECERTIDHASHCSMJOBREFOFOCSP                                                      STD_OFF  /**< Deactivateable: 'KeyM_OCSP.ResponseCertIdHashCsmJobRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_OCSPMAXLENGTHOFCERTIDHASHOFOCSPFORMAT                                                  STD_OFF  /**< Deactivateable: 'KeyM_OCSPMaxLengthOfCertIdHashOfOCSPFormat' Reason: 'Parameter is not configured!' */
#define KEYM_OCSPMAXLENGTHOFDISTINGUISHEDNAMEOFOCSPFORMAT                                           STD_OFF  /**< Deactivateable: 'KeyM_OCSPMaxLengthOfDistinguishedNameOfOCSPFormat' Reason: 'Parameter is not configured!' */
#define KEYM_PARSEMAXNESTINGLEVELOFGENERAL                                                          STD_ON
#define KEYM_REMOTECREENABLEDOFPUBLISHEDINFORMATION                                                 STD_OFF  /**< Deactivateable: 'KeyM_RemoteCREEnabledOfPublishedInformation' Reason: 'Parameter is not configured!' */
#define KEYM_REMOTEOCSPENABLEDOFPUBLISHEDINFORMATION                                                STD_OFF  /**< Deactivateable: 'KeyM_RemoteOCSPEnabledOfPublishedInformation' Reason: 'Parameter is not configured!' */
#define KEYM_RTECALLBACKNOTIFICATION                                                                STD_OFF  /**< Deactivateable: 'KeyM_RteCallbackNotification' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define KEYM_CERTIFICATEVERIFYOFRTECALLBACKNOTIFICATION                                             STD_OFF  /**< Deactivateable: 'KeyM_RteCallbackNotification.CertificateVerify' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_SERVICECERTIFICATEOFRTECALLBACKNOTIFICATION                                            STD_OFF  /**< Deactivateable: 'KeyM_RteCallbackNotification.ServiceCertificate' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_SERVICECERTIFICATECALLBACKNOTIFICATION                                                 STD_OFF  /**< Deactivateable: 'KeyM_ServiceCertificateCallbackNotification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_SERVICECERTIFICATEFUNCTIONENABLEDOFGENERAL                                             STD_ON
#define KEYM_SIZEOFCERTSTORAGE                                                                      STD_ON
#define KEYM_SIZEOFCERT_CERTINFO                                                                    STD_ON
#define KEYM_SIZEOFCERT_LEAFCERTSTOVERIFY                                                           STD_ON
#define KEYM_SIZEOFCERT_STORAGETYPE                                                                 STD_ON
#define KEYM_SIZEOFCERT_VERIFYCHAIN                                                                 STD_ON
#define KEYM_SIZEOFCERTIFICATE                                                                      STD_ON
#define KEYM_SIZEOFCERTIFICATEELEMENT                                                               STD_ON
#define KEYM_SIZEOFCERTIFICATEGETCURRENTTIMECALLOUT                                                 STD_ON
#define KEYM_SIZEOFCERTIFICATENAME                                                                  STD_ON
#define KEYM_SIZEOFCOMMONCERTDATA                                                                   STD_ON
#define KEYM_SIZEOFELEMENTOID                                                                       STD_ON
#define KEYM_SIZEOFELEMENTSTORAGEREF                                                                STD_ON
#define KEYM_SIZEOFGENERAL                                                                          STD_ON
#define KEYM_SLOTOWNER                                                                              STD_OFF  /**< Deactivateable: 'KeyM_SlotOwner' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define KEYM_VERSIONINFOAPIOFGENERAL                                                                STD_ON
#define KEYM_PCCONFIG                                                                               STD_ON
#define KEYM_CERTSTORAGEOFPCCONFIG                                                                  STD_ON
#define KEYM_CERT_CERTINFOOFPCCONFIG                                                                STD_ON
#define KEYM_CERT_LEAFCERTSTOVERIFYOFPCCONFIG                                                       STD_ON
#define KEYM_CERT_STORAGETYPEOFPCCONFIG                                                             STD_ON
#define KEYM_CERT_VERIFYCHAINOFPCCONFIG                                                             STD_ON
#define KEYM_CERTIFICATECHAINMAXDEPTHOFGENERALOFPCCONFIG                                            STD_ON
#define KEYM_CERTIFICATEELEMENTOFPCCONFIG                                                           STD_ON
#define KEYM_CERTIFICATEGETCURRENTTIMECALLOUTOFPCCONFIG                                             STD_ON
#define KEYM_CERTIFICATEMANAGERENABLEDOFGENERALOFPCCONFIG                                           STD_ON
#define KEYM_CERTIFICATENAMEOFPCCONFIG                                                              STD_ON
#define KEYM_CERTIFICATEOFPCCONFIG                                                                  STD_ON
#define KEYM_CERTIFICATESIGNINGREQUESTENABLEDOFGENERALOFPCCONFIG                                    STD_ON
#define KEYM_COMMONCERTDATAOFPCCONFIG                                                               STD_ON
#define KEYM_CRYPTOKEYPREPAREFUNCTIONENABLEDOFGENERALOFPCCONFIG                                     STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.CryptoKeyPrepareFunctionEnabledOfGeneral' Reason: 'Parameter is not configured!' */
#define KEYM_CRYPTOKEYSTARTFINALIZEFUNCTIONENABLEDOFGENERALOFPCCONFIG                               STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.CryptoKeyStartFinalizeFunctionEnabledOfGeneral' Reason: 'Parameter is not configured!' */
#define KEYM_CRYPTOKEYVERIFYASYNCMODEOFGENERALOFPCCONFIG                                            STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.CryptoKeyVerifyAsyncModeOfGeneral' Reason: 'Parameter is not configured!' */
#define KEYM_CRYPTOKEYVERIFYFUNCTIONENABLEDOFGENERALOFPCCONFIG                                      STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.CryptoKeyVerifyFunctionEnabledOfGeneral' Reason: 'Parameter is not configured!' */
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
#define KEYM_PARSEMAXNESTINGLEVELOFGENERALOFPCCONFIG                                                STD_ON
#define KEYM_REMOTECREENABLEDOFPUBLISHEDINFORMATIONOFPCCONFIG                                       STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.RemoteCREEnabledOfPublishedInformation' Reason: 'Parameter is not configured!' */
#define KEYM_REMOTEOCSPENABLEDOFPUBLISHEDINFORMATIONOFPCCONFIG                                      STD_OFF  /**< Deactivateable: 'KeyM_PCConfig.RemoteOCSPEnabledOfPublishedInformation' Reason: 'Parameter is not configured!' */
#define KEYM_SERVICECERTIFICATEFUNCTIONENABLEDOFGENERALOFPCCONFIG                                   STD_ON
#define KEYM_SIZEOFCERTSTORAGEOFPCCONFIG                                                            STD_ON
#define KEYM_SIZEOFCERT_CERTINFOOFPCCONFIG                                                          STD_ON
#define KEYM_SIZEOFCERT_LEAFCERTSTOVERIFYOFPCCONFIG                                                 STD_ON
#define KEYM_SIZEOFCERT_STORAGETYPEOFPCCONFIG                                                       STD_ON
#define KEYM_SIZEOFCERT_VERIFYCHAINOFPCCONFIG                                                       STD_ON
#define KEYM_SIZEOFCERTIFICATEELEMENTOFPCCONFIG                                                     STD_ON
#define KEYM_SIZEOFCERTIFICATEGETCURRENTTIMECALLOUTOFPCCONFIG                                       STD_ON
#define KEYM_SIZEOFCERTIFICATENAMEOFPCCONFIG                                                        STD_ON
#define KEYM_SIZEOFCERTIFICATEOFPCCONFIG                                                            STD_ON
#define KEYM_SIZEOFCOMMONCERTDATAOFPCCONFIG                                                         STD_ON
#define KEYM_SIZEOFELEMENTOIDOFPCCONFIG                                                             STD_ON
#define KEYM_SIZEOFELEMENTSTORAGEREFOFPCCONFIG                                                      STD_ON
#define KEYM_SIZEOFGENERALOFPCCONFIG                                                                STD_ON
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
#define KEYM_NO_ELEMENTOIDENDIDXOFCERTIFICATEELEMENT                                                255u
#define KEYM_NO_ELEMENTOIDSTARTIDXOFCERTIFICATEELEMENT                                              255u
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
#define KEYM_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE_MASK                                    0x20u
#define KEYM_CERTUSEPORTOFCERTIFICATE_MASK                                                          0x10u
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
#define KEYM_ISDEF_CERTUSEPORTOFCERTIFICATE                                                         STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTENDIDXOFCERTIFICATE                                            STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTLENGTHOFCERTIFICATE                                            STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTSTARTIDXOFCERTIFICATE                                          STD_OFF
#define KEYM_ISDEF_CERTIFICATEELEMENTUSEDOFCERTIFICATE                                              STD_OFF
#define KEYM_ISDEF_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE                                 STD_OFF
#define KEYM_ISDEF_CERTIFICATEGETCURRENTTIMECALLOUTUSEDOFCERTIFICATE                                STD_OFF
#define KEYM_ISDEF_CERTIFICATENAMEENDIDXOFCERTIFICATE                                               STD_OFF
#define KEYM_ISDEF_CERTIFICATENAMELENGTHOFCERTIFICATE                                               STD_OFF
#define KEYM_ISDEF_CERTIFICATENAMESTARTIDXOFCERTIFICATE                                             STD_OFF
#define KEYM_ISDEF_CSMKEYTARGETREFOFCERTIFICATE                                                     STD_OFF
#define KEYM_ISDEF_CSMKEYTARGETREFVALIDOFCERTIFICATE                                                STD_OFF
#define KEYM_ISDEF_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE                                          STD_OFF
#define KEYM_ISDEF_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE                             STD_OFF
#define KEYM_ISDEF_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE                               STD_OFF
#define KEYM_ISDEF_MASKEDBITSOFCERTIFICATE                                                          STD_OFF
#define KEYM_ISDEF_MAXLENGTHOFCERTIFICATE                                                           STD_OFF
#define KEYM_ISDEF_REMOTECERTIFICATEIDOFCERTIFICATE                                                 STD_OFF
#define KEYM_ISDEF_STORAGEOFCERTIFICATE                                                             STD_OFF
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
#define KEYM_ISDEF_CERTIFICATEGETCURRENTTIMECALLOUT                                                 STD_OFF
#define KEYM_ISDEF_CERTIFICATENAME                                                                  STD_OFF
#define KEYM_ISDEF_ELEMENTOID                                                                       STD_OFF
#define KEYM_ISDEF_KEYMCSMREMOTEINFOJOBREFASYNCOFGENERAL                                            STD_OFF
#define KEYM_ISDEF_CERTSTORAGEOFPCCONFIG                                                            STD_ON
#define KEYM_ISDEF_CERT_CERTINFOOFPCCONFIG                                                          STD_ON
#define KEYM_ISDEF_CERT_LEAFCERTSTOVERIFYOFPCCONFIG                                                 STD_ON
#define KEYM_ISDEF_CERT_STORAGETYPEOFPCCONFIG                                                       STD_ON
#define KEYM_ISDEF_CERT_VERIFYCHAINOFPCCONFIG                                                       STD_ON
#define KEYM_ISDEF_CERTIFICATEELEMENTOFPCCONFIG                                                     STD_ON
#define KEYM_ISDEF_CERTIFICATEGETCURRENTTIMECALLOUTOFPCCONFIG                                       STD_ON
#define KEYM_ISDEF_CERTIFICATENAMEOFPCCONFIG                                                        STD_ON
#define KEYM_ISDEF_CERTIFICATEOFPCCONFIG                                                            STD_ON
#define KEYM_ISDEF_COMMONCERTDATAOFPCCONFIG                                                         STD_ON
#define KEYM_ISDEF_ELEMENTOIDOFPCCONFIG                                                             STD_ON
#define KEYM_ISDEF_ELEMENTSTORAGEREFOFPCCONFIG                                                      STD_ON
#define KEYM_ISDEF_GENERALOFPCCONFIG                                                                STD_ON
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
#define KEYM_EQ2_CERTUSEPORTOFCERTIFICATE                                                           
#define KEYM_EQ2_CERTIFICATEELEMENTENDIDXOFCERTIFICATE                                              
#define KEYM_EQ2_CERTIFICATEELEMENTLENGTHOFCERTIFICATE                                              
#define KEYM_EQ2_CERTIFICATEELEMENTSTARTIDXOFCERTIFICATE                                            
#define KEYM_EQ2_CERTIFICATEELEMENTUSEDOFCERTIFICATE                                                
#define KEYM_EQ2_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE                                   
#define KEYM_EQ2_CERTIFICATEGETCURRENTTIMECALLOUTUSEDOFCERTIFICATE                                  
#define KEYM_EQ2_CERTIFICATENAMEENDIDXOFCERTIFICATE                                                 
#define KEYM_EQ2_CERTIFICATENAMELENGTHOFCERTIFICATE                                                 
#define KEYM_EQ2_CERTIFICATENAMESTARTIDXOFCERTIFICATE                                               
#define KEYM_EQ2_CSMKEYTARGETREFOFCERTIFICATE                                                       
#define KEYM_EQ2_CSMKEYTARGETREFVALIDOFCERTIFICATE                                                  
#define KEYM_EQ2_KEYMCERTCSMHASHJOBREFASYNCOFCERTIFICATE                                            
#define KEYM_EQ2_KEYMCERTCSMSIGNATUREGENERATEJOBREFASYNCOFCERTIFICATE                               
#define KEYM_EQ2_KEYMCERTCSMSIGNATUREVERIFYJOBREFASYNCOFCERTIFICATE                                 
#define KEYM_EQ2_MASKEDBITSOFCERTIFICATE                                                            
#define KEYM_EQ2_MAXLENGTHOFCERTIFICATE                                                             
#define KEYM_EQ2_REMOTECERTIFICATEIDOFCERTIFICATE                                                   
#define KEYM_EQ2_STORAGEOFCERTIFICATE                                                               
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
#define KEYM_EQ2_CERTIFICATEGETCURRENTTIMECALLOUT                                                   
#define KEYM_EQ2_CERTIFICATENAME                                                                    
#define KEYM_EQ2_ELEMENTOID                                                                         
#define KEYM_EQ2_KEYMCSMREMOTEINFOJOBREFASYNCOFGENERAL                                              
#define KEYM_EQ2_CERTSTORAGEOFPCCONFIG                                                              KeyM_CertStorage.raw
#define KEYM_EQ2_CERT_CERTINFOOFPCCONFIG                                                            KeyM_Cert_CertInfo
#define KEYM_EQ2_CERT_LEAFCERTSTOVERIFYOFPCCONFIG                                                   KeyM_Cert_LeafCertsToVerify
#define KEYM_EQ2_CERT_STORAGETYPEOFPCCONFIG                                                         KeyM_Cert_StorageType
#define KEYM_EQ2_CERT_VERIFYCHAINOFPCCONFIG                                                         KeyM_Cert_VerifyChain
#define KEYM_EQ2_CERTIFICATEELEMENTOFPCCONFIG                                                       KeyM_CertificateElement
#define KEYM_EQ2_CERTIFICATEGETCURRENTTIMECALLOUTOFPCCONFIG                                         KeyM_CertificateGetCurrentTimeCallout
#define KEYM_EQ2_CERTIFICATENAMEOFPCCONFIG                                                          KeyM_CertificateName
#define KEYM_EQ2_CERTIFICATEOFPCCONFIG                                                              KeyM_Certificate
#define KEYM_EQ2_COMMONCERTDATAOFPCCONFIG                                                           KeyM_CommonCertData.raw
#define KEYM_EQ2_ELEMENTOIDOFPCCONFIG                                                               KeyM_ElementOid
#define KEYM_EQ2_ELEMENTSTORAGEREFOFPCCONFIG                                                        KeyM_ElementStorageRef
#define KEYM_EQ2_GENERALOFPCCONFIG                                                                  KeyM_General
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
#define KeyM_GetCert_StorageTypeOfPCConfig()                                                        KeyM_Cert_StorageType  /**< the pointer to KeyM_Cert_StorageType */
#define KeyM_GetCert_VerifyChainOfPCConfig()                                                        KeyM_Cert_VerifyChain  /**< the pointer to KeyM_Cert_VerifyChain */
#define KeyM_GetCertificateChainMaxDepthOfGeneralOfPCConfig()                                       2u
#define KeyM_GetCertificateElementOfPCConfig()                                                      KeyM_CertificateElement  /**< the pointer to KeyM_CertificateElement */
#define KeyM_GetCertificateGetCurrentTimeCalloutOfPCConfig()                                        KeyM_CertificateGetCurrentTimeCallout  /**< the pointer to KeyM_CertificateGetCurrentTimeCallout */
#define KeyM_IsCertificateManagerEnabledOfGeneralOfPCConfig()                                       (((TRUE)) != FALSE)
#define KeyM_GetCertificateNameOfPCConfig()                                                         KeyM_CertificateName  /**< the pointer to KeyM_CertificateName */
#define KeyM_GetCertificateOfPCConfig()                                                             KeyM_Certificate  /**< the pointer to KeyM_Certificate */
#define KeyM_IsCertificateSigningRequestEnabledOfGeneralOfPCConfig()                                (((FALSE)) != FALSE)
#define KeyM_GetCommonCertDataOfPCConfig()                                                          KeyM_CommonCertData.raw  /**< the pointer to KeyM_CommonCertData */
#define KeyM_GetElementOidOfPCConfig()                                                              KeyM_ElementOid  /**< the pointer to KeyM_ElementOid */
#define KeyM_GetElementStorageRefOfPCConfig()                                                       KeyM_ElementStorageRef  /**< the pointer to KeyM_ElementStorageRef */
#define KeyM_GetGeneralOfPCConfig()                                                                 KeyM_General  /**< the pointer to KeyM_General */
#define KeyM_GetKeyCertNameMaxLengthOfGeneralOfPCConfig()                                           39u
#define KeyM_GetMainFunctionPeriodOfGeneralOfPCConfig()                                             1u
#define KeyM_GetParseMaxNestingLevelOfGeneralOfPCConfig()                                           20u
#define KeyM_IsServiceCertificateFunctionEnabledOfGeneralOfPCConfig()                               (((TRUE)) != FALSE)
#define KeyM_GetSizeOfCertStorageOfPCConfig()                                                       1208u  /**< the number of accomplishable value elements in KeyM_CertStorage */
#define KeyM_GetSizeOfCert_CertInfoOfPCConfig()                                                     2u  /**< the number of accomplishable value elements in KeyM_Cert_CertInfo */
#define KeyM_GetSizeOfCert_LeafCertsToVerifyOfPCConfig()                                            2u  /**< the number of accomplishable value elements in KeyM_Cert_LeafCertsToVerify */
#define KeyM_GetSizeOfCert_StorageTypeOfPCConfig()                                                  2u  /**< the number of accomplishable value elements in KeyM_Cert_StorageType */
#define KeyM_GetSizeOfCert_VerifyChainOfPCConfig()                                                  2u  /**< the number of accomplishable value elements in KeyM_Cert_VerifyChain */
#define KeyM_GetSizeOfCertificateElementOfPCConfig()                                                45u  /**< the number of accomplishable value elements in KeyM_CertificateElement */
#define KeyM_GetSizeOfCertificateGetCurrentTimeCalloutOfPCConfig()                                  1u  /**< the number of accomplishable value elements in KeyM_CertificateGetCurrentTimeCallout */
#define KeyM_GetSizeOfCertificateNameOfPCConfig()                                                   78u  /**< the number of accomplishable value elements in KeyM_CertificateName */
#define KeyM_GetSizeOfCertificateOfPCConfig()                                                       2u  /**< the number of accomplishable value elements in KeyM_Certificate */
#define KeyM_GetSizeOfCommonCertDataOfPCConfig()                                                    2u  /**< the number of accomplishable value elements in KeyM_CommonCertData */
#define KeyM_GetSizeOfElementOidOfPCConfig()                                                        44u  /**< the number of accomplishable value elements in KeyM_ElementOid */
#define KeyM_GetSizeOfGeneralOfPCConfig()                                                           1u  /**< the number of accomplishable value elements in KeyM_General */
#define KeyM_IsVersionInfoApiOfGeneralOfPCConfig()                                                  (((FALSE)) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCGetDuplicatedRootDataMacros  KeyM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
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

/* Structure Types */
typedef struct 
{
  uint16 offset;
  uint16 length;
} KeyM_Ans1_Element_Ref_Type;

/* Certificate Group Verify Callback Notification Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_APPL_CODE, KeyM_CertificateGroupVerifyCallbackNotificationFctPtrType)(KeyM_CertificateGroupIdType GroupId, KeyM_CertificateGroupStatusType Result);

/* Certificate Verify Callback Notification Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_APPL_CODE, KeyM_CertificateVerifyCallbackNotificationFctPtrType)(KeyM_CertificateIdType CertId, KeyM_CertificateStatusType Result);

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

/* Rte Certificate Callback Notification Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_RTE_CODE, KeyM_ServiceCertificateRteCallbackNotificationFctPtrType)(KeyM_CertificateStatusType Result, uint16 ResultDataLength, P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) ResultDataPtr);

/* Rte Certificate Verify Callback Notification Typedef */
typedef P2FUNC(Std_ReturnType, KEYM_RTE_CODE, KeyM_CertificateVerifyRteCallbackNotificationFctPtrType)(KeyM_CertificateStatusType Result);



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

/**   \brief  type used to iterate KeyM_Cert_CertInfo */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_CertInfo() } \endspec */ 
typedef uint8_least KeyM_Cert_CertInfoIterType;

/**   \brief  type used to iterate KeyM_Cert_LeafCertsToVerify */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_LeafCertsToVerify() } \endspec */ 
typedef uint8_least KeyM_Cert_LeafCertsToVerifyIterType;

/**   \brief  type used to iterate KeyM_Cert_StorageType */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_StorageType() } \endspec */ 
typedef uint8_least KeyM_Cert_StorageTypeIterType;

/**   \brief  type used to iterate KeyM_Cert_VerifyChain */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCert_VerifyChain() } \endspec */ 
typedef uint8_least KeyM_Cert_VerifyChainIterType;

/**   \brief  type used to iterate KeyM_Certificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificate() } \endspec */ 
typedef uint8_least KeyM_CertificateIterType;

/**   \brief  type used to iterate KeyM_CertificateElement */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateElement() } \endspec */ 
typedef uint8_least KeyM_CertificateElementIterType;

/**   \brief  type used to iterate KeyM_CertificateGetCurrentTimeCallout */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateGetCurrentTimeCallout() } \endspec */ 
typedef uint8_least KeyM_CertificateGetCurrentTimeCalloutIterType;

/**   \brief  type used to iterate KeyM_CertificateName */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateName() } \endspec */ 
typedef uint8_least KeyM_CertificateNameIterType;

/**   \brief  type used to iterate KeyM_CommonCertData */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCommonCertData() } \endspec */ 
typedef uint8_least KeyM_CommonCertDataIterType;

/**   \brief  type used to iterate KeyM_ElementOid */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfElementOid() } \endspec */ 
typedef uint8_least KeyM_ElementOidIterType;

/**   \brief  type used to iterate KeyM_General */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfGeneral() } \endspec */ 
typedef uint8_least KeyM_GeneralIterType;

/** 
  \}
*/ 

/** 
  \defgroup  KeyMPCIterableTypesWithSizeRelations  KeyM Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
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

/**   \brief  value based type definition for KeyM_CertAlgorithmFamilyOfCertificate */
typedef uint8 KeyM_CertAlgorithmFamilyOfCertificateType;

/**   \brief  value based type definition for KeyM_CertAllowFlexibleElementOrderOfCertificate */
typedef boolean KeyM_CertAllowFlexibleElementOrderOfCertificateType;

/**   \brief  value based type definition for KeyM_CertAllowUnconfiguredElementsOfCertificate */
typedef boolean KeyM_CertAllowUnconfiguredElementsOfCertificateType;

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

/**   \brief  value based type definition for KeyM_CertUsePortOfCertificate */
typedef boolean KeyM_CertUsePortOfCertificateType;

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

/**   \brief  value based type definition for KeyM_CertificateNameEndIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateName() } \endspec */ 
typedef uint8 KeyM_CertificateNameEndIdxOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateNameLengthOfCertificate */
typedef uint8 KeyM_CertificateNameLengthOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateNameStartIdxOfCertificate */
/*! \spec strong type invariant () { self < KeyM_GetSizeOfCertificateName() } \endspec */ 
typedef uint8 KeyM_CertificateNameStartIdxOfCertificateType;

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

/**   \brief  value based type definition for KeyM_StorageOfCertificate */
typedef uint8 KeyM_StorageOfCertificateType;

/**   \brief  value based type definition for KeyM_CertificateChainMaxDepthOfGeneral */
typedef uint8 KeyM_CertificateChainMaxDepthOfGeneralType;

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

/**   \brief  value based type definition for KeyM_OfStructureOfCertificateElement */
typedef uint8 KeyM_OfStructureOfCertificateElementType;

/**   \brief  value based type definition for KeyM_OptionalOfCertificateElement */
typedef boolean KeyM_OptionalOfCertificateElementType;

/**   \brief  value based type definition for KeyM_CertificateManagerEnabledOfGeneral */
typedef boolean KeyM_CertificateManagerEnabledOfGeneralType;

/**   \brief  value based type definition for KeyM_CertificateName */
typedef uint8 KeyM_CertificateNameType;

/**   \brief  value based type definition for KeyM_CertificateSigningRequestEnabledOfGeneral */
typedef boolean KeyM_CertificateSigningRequestEnabledOfGeneralType;

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

/**   \brief  value based type definition for KeyM_SizeOfCert_StorageType */
typedef uint8 KeyM_SizeOfCert_StorageTypeType;

/**   \brief  value based type definition for KeyM_SizeOfCert_VerifyChain */
typedef uint8 KeyM_SizeOfCert_VerifyChainType;

/**   \brief  value based type definition for KeyM_SizeOfCertificate */
typedef uint8 KeyM_SizeOfCertificateType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateElement */
typedef uint8 KeyM_SizeOfCertificateElementType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateGetCurrentTimeCallout */
typedef uint8 KeyM_SizeOfCertificateGetCurrentTimeCalloutType;

/**   \brief  value based type definition for KeyM_SizeOfCertificateName */
typedef uint8 KeyM_SizeOfCertificateNameType;

/**   \brief  value based type definition for KeyM_SizeOfCommonCertData */
typedef uint8 KeyM_SizeOfCommonCertDataType;

/**   \brief  value based type definition for KeyM_SizeOfElementOid */
typedef uint8 KeyM_SizeOfElementOidType;

/**   \brief  value based type definition for KeyM_SizeOfElementStorageRef */
typedef uint8 KeyM_SizeOfElementStorageRefType;

/**   \brief  value based type definition for KeyM_SizeOfGeneral */
typedef uint8 KeyM_SizeOfGeneralType;

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
 *   (!(self.CertificateElementLengthOfCertificate != 0u) || (self.CertificateElementEndIdxOfCertificate < KeyM_GetSizeOfCertificateElement())) &&
 *   (!(self.CertificateElementLengthOfCertificate != 0u) || (self.CertificateElementStartIdxOfCertificate < KeyM_GetSizeOfCertificateElement())) &&
 *   (!(self.CertificateGetCurrentTimeCalloutIdxOfCertificate != KEYM_NO_CERTIFICATEGETCURRENTTIMECALLOUTIDXOFCERTIFICATE) || (self.CertificateGetCurrentTimeCalloutIdxOfCertificate < KeyM_GetSizeOfCertificateGetCurrentTimeCallout())) &&
 *   (self.CertificateNameStartIdxOfCertificate < KeyM_GetSizeOfCertificateName())
 * }
 * \endspec 
 */ 
typedef struct sKeyM_CertificateType
{
  KeyM_CertCsmSignatureVerifyJobRefOfCertificateType CertCsmSignatureVerifyJobRefOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureVerifyJobRef. */
  KeyM_CertCsmSignatureVerifyKeyRefOfCertificateType CertCsmSignatureVerifyKeyRefOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertCsmSignatureVerifyKeyRef. */
  KeyM_CsmKeyTargetRefOfCertificateType CsmKeyTargetRefOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateCsmKeyTargetRef. */
  KeyM_CertStorageLengthOfCertificateType CertStorageLengthOfCertificate;  /**< the number of relations pointing to KeyM_CertStorage */
  KeyM_CertStorageStartIdxOfCertificateType CertStorageStartIdxOfCertificate;  /**< the start index of the 0:n relation pointing to KeyM_CertStorage */
  KeyM_CertAlgorithmFamilyOfCertificateType CertAlgorithmFamilyOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertAlgorithmFamily. */
  KeyM_CertFormatTypeOfCertificateType CertFormatTypeOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertFormatType. */
  KeyM_CertStartUpHandlingOfCertificateType CertStartUpHandlingOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertStartUpHandling. */
  KeyM_CertStorageWrittenLengthLengthOfCertificateType CertStorageWrittenLengthLengthOfCertificate;  /**< the number of relations pointing to KeyM_CertStorage */
  KeyM_CertUpperHierarchicalTypeOfCertificateType CertUpperHierarchicalTypeOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertUpperHierarchicalType. */
  KeyM_CertificateElementEndIdxOfCertificateType CertificateElementEndIdxOfCertificate;  /**< the end index of the 0:n relation pointing to KeyM_CertificateElement */
  KeyM_CertificateElementStartIdxOfCertificateType CertificateElementStartIdxOfCertificate;  /**< the start index of the 0:n relation pointing to KeyM_CertificateElement */
  KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificateType CertificateGetCurrentTimeCalloutIdxOfCertificate;  /**< the index of the 0:1 relation pointing to KeyM_CertificateGetCurrentTimeCallout */
  KeyM_CertificateNameStartIdxOfCertificateType CertificateNameStartIdxOfCertificate;  /**< the start index of the 1:n relation pointing to KeyM_CertificateName */
  KeyM_StorageOfCertificateType StorageOfCertificate;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateStorage. */
} KeyM_CertificateType;

/**   \brief  type used in KeyM_CertificateElement */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.ElementOidLengthOfCertificateElement != 0u) || (self.ElementOidEndIdxOfCertificateElement < KeyM_GetSizeOfElementOid())) &&
 *   (!(self.ElementOidLengthOfCertificateElement != 0u) || (self.ElementOidStartIdxOfCertificateElement < KeyM_GetSizeOfElementOid()))
 * }
 * \endspec 
 */ 
typedef struct sKeyM_CertificateElementType
{
  KeyM_ElementOidEndIdxOfCertificateElementType ElementOidEndIdxOfCertificateElement;  /**< the end index of the 0:n relation pointing to KeyM_ElementOid */
  KeyM_ElementOidStartIdxOfCertificateElementType ElementOidStartIdxOfCertificateElement;  /**< the start index of the 0:n relation pointing to KeyM_ElementOid */
  KeyM_IdOfCertificateElementType IdOfCertificateElement;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId. */
  KeyM_MaskedBitsOfCertificateElementType MaskedBitsOfCertificateElement;  /**< contains bitcoded the boolean data of KeyM_HasIterationOfCertificateElement, KeyM_OptionalOfCertificateElement */
  KeyM_MaxLengthOfCertificateElementType MaxLengthOfCertificateElement;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementMaxLength. */
  KeyM_ObjectTypeOfCertificateElementType ObjectTypeOfCertificateElement;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementObjectType. */
  KeyM_OfStructureOfCertificateElementType OfStructureOfCertificateElement;  /**< Contains values of DefinitionRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementOfStructure. */
} KeyM_CertificateElementType;

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
  KeyM_CertStorageType KeyMCertificate_OSSL_X509_ECDSA_P384_CA__WrittenLength__[2];
  KeyM_CertStorageType KeyMCertificate_OSSL_X509_ECDSA_P384_CA__Status__[2];
  KeyM_CertStorageType KeyMCertificate_OSSL_X509_ECDSA_P384_CA__Data__[600];
  KeyM_CertStorageType KeyMCertificate_OSSL_X509_ECDSA_P384_IA__WrittenLength__[2];
  KeyM_CertStorageType KeyMCertificate_OSSL_X509_ECDSA_P384_IA__Status__[2];
  KeyM_CertStorageType KeyMCertificate_OSSL_X509_ECDSA_P384_IA__Data__[600];
} KeyM_CertStorageStructSType;

/**   \brief  type to be used as symbolic data element access to KeyM_CommonCertData */
typedef struct KeyM_CommonCertDataStructSTag
{
  KeyM_ConstCertDataType KeyMCertificate_OSSL_X509_ECDSA_P384_CA;
  KeyM_ConstCertDataType KeyMCertificate_OSSL_X509_ECDSA_P384_IA;
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
  KeyM_CertStorageType raw[1208];
  KeyM_CertStorageStructSType str;
} KeyM_CertStorageUType;

/**   \brief  type to access KeyM_CommonCertData in an index and symbol based style. */
typedef union KeyM_CommonCertDataUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  KeyM_ConstCertDataType raw[2];
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

/**   \brief  type used to point to KeyM_Cert_StorageType */
typedef P2VAR(tKeyMCertStorageType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_Cert_StorageTypePtrType;

/**   \brief  type used to point to KeyM_Cert_VerifyChain */
typedef P2VAR(KeyM_CertificateIdType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_Cert_VerifyChainPtrType;

/**   \brief  type used to point to KeyM_Certificate */
typedef P2CONST(KeyM_CertificateType, TYPEDEF, KEYM_CONST) KeyM_CertificatePtrType;

/**   \brief  type used to point to KeyM_CertificateElement */
typedef P2CONST(KeyM_CertificateElementType, TYPEDEF, KEYM_CONST) KeyM_CertificateElementPtrType;

/**   \brief  type used to point to KeyM_CertificateGetCurrentTimeCallout */
typedef P2CONST(KeyM_CertificateGetCurrentTimeCalloutFctPtrType, TYPEDEF, KEYM_CONST) KeyM_CertificateGetCurrentTimeCalloutPtrType;

/**   \brief  type used to point to KeyM_CertificateName */
typedef P2CONST(KeyM_CertificateNameType, TYPEDEF, KEYM_CONST) KeyM_CertificateNamePtrType;

/**   \brief  type used to point to KeyM_CommonCertData */
typedef P2VAR(KeyM_ConstCertDataType, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_CommonCertDataPtrType;

/**   \brief  type used to point to KeyM_ElementOid */
typedef P2CONST(KeyM_ElementOidType, TYPEDEF, KEYM_CONST) KeyM_ElementOidPtrType;

/**   \brief  type used to point to KeyM_ElementStorageRef */
typedef P2VAR(KeyM_Ans1_Element_Ref_Type, TYPEDEF, KEYM_VAR_NO_INIT) KeyM_ElementStorageRefPtrType;

/**   \brief  type used to point to KeyM_General */
typedef P2CONST(KeyM_GeneralType, TYPEDEF, KEYM_CONST) KeyM_GeneralPtrType;

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
extern CONST(KeyM_CertificateType, KEYM_CONST) KeyM_Certificate[2];
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
extern CONST(KeyM_CertificateElementType, KEYM_CONST) KeyM_CertificateElement[45];
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
  KeyM_CertificateName
**********************************************************************************************************************/
#define KEYM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(KeyM_CertificateNameType, KEYM_CONST) KeyM_CertificateName[78];
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
extern CONST(KeyM_ElementOidType, KEYM_CONST) KeyM_ElementOid[44];
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
extern VAR(tKeyMCertInfoType, KEYM_VAR_NO_INIT) KeyM_Cert_CertInfo[2];
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
extern VAR(KeyM_CertificateIdType, KEYM_VAR_NO_INIT) KeyM_Cert_LeafCertsToVerify[2];
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
extern VAR(tKeyMCertStorageType, KEYM_VAR_NO_INIT) KeyM_Cert_StorageType[2];
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
extern VAR(KeyM_CertificateIdType, KEYM_VAR_NO_INIT) KeyM_Cert_VerifyChain[2];
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
extern VAR(KeyM_Ans1_Element_Ref_Type, KEYM_VAR_NO_INIT) KeyM_ElementStorageRef[45];
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
KEYM_LOCAL_INLINE FUNC(tKeyMCertStorageType, KEYM_CODE) KeyM_GetCert_StorageType(KeyM_Cert_StorageTypeIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_GetCert_VerifyChain(KeyM_Cert_VerifyChainIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertAlgorithmFamilyOfCertificateType, KEYM_CODE) KeyM_GetCertAlgorithmFamilyOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertCsmSignatureVerifyJobRefOfCertificateType, KEYM_CODE) KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertCsmSignatureVerifyKeyRefOfCertificateType, KEYM_CODE) KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertFormatTypeOfCertificateType, KEYM_CODE) KeyM_GetCertFormatTypeOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStartUpHandlingOfCertificateType, KEYM_CODE) KeyM_GetCertStartUpHandlingOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertStorageStartIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertStorageWrittenLengthLengthOfCertificateType, KEYM_CODE) KeyM_GetCertStorageWrittenLengthLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertUpperHierarchicalTypeOfCertificateType, KEYM_CODE) KeyM_GetCertUpperHierarchicalTypeOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementEndIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementStartIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateGetCurrentTimeCalloutIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameStartIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CsmKeyTargetRefOfCertificateType, KEYM_CODE) KeyM_GetCsmKeyTargetRefOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_StorageOfCertificateType, KEYM_CODE) KeyM_GetStorageOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidEndIdxOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidEndIdxOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidStartIdxOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidStartIdxOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_IdOfCertificateElementType, KEYM_CODE) KeyM_GetIdOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_MaskedBitsOfCertificateElementType, KEYM_CODE) KeyM_GetMaskedBitsOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_MaxLengthOfCertificateElementType, KEYM_CODE) KeyM_GetMaxLengthOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ObjectTypeOfCertificateElementType, KEYM_CODE) KeyM_GetObjectTypeOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_OfStructureOfCertificateElementType, KEYM_CODE) KeyM_GetOfStructureOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutFctPtrType, KEYM_CODE) KeyM_GetCertificateGetCurrentTimeCallout(KeyM_CertificateGetCurrentTimeCalloutIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameType, KEYM_CODE) KeyM_GetCertificateName(KeyM_CertificateNameIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ConstCertDataType, KEYM_CODE) KeyM_GetCommonCertData(KeyM_CommonCertDataIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidType, KEYM_CODE) KeyM_GetElementOid(KeyM_ElementOidIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_Ans1_Element_Ref_Type, KEYM_CODE) KeyM_GetElementStorageRef(KeyM_ElementStorageRefIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_KeyMCsmRemoteInfoJobRefAsyncOfGeneralType, KEYM_CODE) KeyM_IsKeyMCsmRemoteInfoJobRefAsyncOfGeneral(KeyM_GeneralIterType Index);
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
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertCsmSignatureVerifyKeyRefValidOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertUsePortOfCertificate(KeyM_CertificateIterType Index);
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
KEYM_LOCAL_INLINE FUNC(KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType, KEYM_CODE) KeyM_GetCertUpperHierarchicalCertRefIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementLengthOfCertificateType, KEYM_CODE) KeyM_GetCertificateElementLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateElementUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateElementUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutUsedOfCertificateType, KEYM_CODE) KeyM_IsCertificateGetCurrentTimeCalloutUsedOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameEndIdxOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameLengthOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_MaskedBitsOfCertificateType, KEYM_CODE) KeyM_GetMaskedBitsOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_MaxLengthOfCertificateType, KEYM_CODE) KeyM_GetMaxLengthOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_RemoteCertificateIdOfCertificateType, KEYM_CODE) KeyM_GetRemoteCertificateIdOfCertificate(KeyM_CertificateIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateChainMaxDepthOfGeneralType, KEYM_CODE) KeyM_GetCertificateChainMaxDepthOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidLengthOfCertificateElementType, KEYM_CODE) KeyM_GetElementOidLengthOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_ElementOidUsedOfCertificateElementType, KEYM_CODE) KeyM_IsElementOidUsedOfCertificateElement(KeyM_CertificateElementIterType Index);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateManagerEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateManagerEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateSigningRequestEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateSigningRequestEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_KeyCertNameMaxLengthOfGeneralType, KEYM_CODE) KeyM_GetKeyCertNameMaxLengthOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_MainFunctionPeriodOfGeneralType, KEYM_CODE) KeyM_GetMainFunctionPeriodOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_ParseMaxNestingLevelOfGeneralType, KEYM_CODE) KeyM_GetParseMaxNestingLevelOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_ServiceCertificateFunctionEnabledOfGeneralType, KEYM_CODE) KeyM_IsServiceCertificateFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertStorageType, KEYM_CODE) KeyM_GetSizeOfCertStorage(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_CertInfoType, KEYM_CODE) KeyM_GetSizeOfCert_CertInfo(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_LeafCertsToVerifyType, KEYM_CODE) KeyM_GetSizeOfCert_LeafCertsToVerify(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_StorageTypeType, KEYM_CODE) KeyM_GetSizeOfCert_StorageType(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCert_VerifyChainType, KEYM_CODE) KeyM_GetSizeOfCert_VerifyChain(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateType, KEYM_CODE) KeyM_GetSizeOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateElementType, KEYM_CODE) KeyM_GetSizeOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateGetCurrentTimeCalloutType, KEYM_CODE) KeyM_GetSizeOfCertificateGetCurrentTimeCallout(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateNameType, KEYM_CODE) KeyM_GetSizeOfCertificateName(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCommonCertDataType, KEYM_CODE) KeyM_GetSizeOfCommonCertData(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfElementOidType, KEYM_CODE) KeyM_GetSizeOfElementOid(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfElementStorageRefType, KEYM_CODE) KeyM_GetSizeOfElementStorageRef(void);
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfGeneralType, KEYM_CODE) KeyM_GetSizeOfGeneral(void);
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
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_StorageTypePtrType, KEYM_CODE) KeyM_GetAddrCert_StorageType(KeyM_Cert_StorageTypeIterType Index);
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
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_StorageType(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_VerifyChain(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAlgorithmFamilyOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAllowFlexibleElementOrderOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertAllowUnconfiguredElementsOfCertificate(void);
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
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertUsePortOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementEndIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementStartIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutUsedOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameEndIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameStartIdxOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCsmKeyTargetRefOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCsmKeyTargetRefValidOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmHashJobRefAsyncOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmSignatureGenerateJobRefAsyncOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaskedBitsOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMaxLengthOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasRemoteCertificateIdOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasStorageOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateChainMaxDepthOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElement(void);
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
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCallout(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateManagerEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateName(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSigningRequestEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCommonCertData(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOid(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementStorageRef(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyMCsmRemoteInfoJobRefAsyncOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyCertNameMaxLengthOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMainFunctionPeriodOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasParseMaxNestingLevelOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateFunctionEnabledOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertStorage(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_CertInfo(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LeafCertsToVerify(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_StorageType(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_VerifyChain(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificate(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElement(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGetCurrentTimeCallout(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateName(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCommonCertData(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementOid(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementStorageRef(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasVersionInfoApiOfGeneral(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertStorageOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_CertInfoOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_LeafCertsToVerifyOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_StorageTypeOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCert_VerifyChainOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateChainMaxDepthOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateElementOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateManagerEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateNameOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateSigningRequestEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCommonCertDataOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementOidOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasElementStorageRefOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasKeyCertNameMaxLengthOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasMainFunctionPeriodOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasParseMaxNestingLevelOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasServiceCertificateFunctionEnabledOfGeneralOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertStorageOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_CertInfoOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_LeafCertsToVerifyOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_StorageTypeOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCert_VerifyChainOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateElementOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGetCurrentTimeCalloutOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateNameOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCommonCertDataOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementOidOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfElementStorageRefOfPCConfig(void);
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfGeneralOfPCConfig(void);
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
 *  Certificate Get Current Time Callout Prototypes
 *********************************************************************************************************************/
/*!
 * \fn          Appl_KeyMCertificateGetCurrentTimeCalloutFunc
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
extern FUNC(Std_ReturnType, KEYM_APPL_CODE) Appl_KeyMCertificateGetCurrentTimeCalloutFunc( KeyM_CertificateIdType CertId,  P2VAR(uint64, AUTOMATIC, KEYM_APPL_VAR) timeStamp);

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
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameStartIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameStartIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateNameStartIdxOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CertificateNameStartIdxOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CsmKeyTargetRefOfCertificateType, KEYM_CODE) KeyM_GetCsmKeyTargetRefOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CsmKeyTargetRefOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].CsmKeyTargetRefOfCertificate);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_StorageOfCertificateType, KEYM_CODE) KeyM_GetStorageOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_StorageOfCertificateType) (KeyM_GetCertificateOfPCConfig()[(Index)].StorageOfCertificate);
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
KEYM_LOCAL_INLINE FUNC(KeyM_OfStructureOfCertificateElementType, KEYM_CODE) KeyM_GetOfStructureOfCertificateElement(KeyM_CertificateElementIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_OfStructureOfCertificateElementType) (KeyM_GetCertificateElementOfPCConfig()[(Index)].OfStructureOfCertificateElement);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateGetCurrentTimeCallout(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateGetCurrentTimeCalloutFctPtrType, KEYM_CODE) KeyM_GetCertificateGetCurrentTimeCallout(KeyM_CertificateGetCurrentTimeCalloutIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateGetCurrentTimeCalloutFctPtrType) (KeyM_GetCertificateGetCurrentTimeCalloutOfPCConfig()[(Index)]);
}
/*! \spec requires Index < KeyM_GetSizeOfCertificateName(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameType, KEYM_CODE) KeyM_GetCertificateName(KeyM_CertificateNameIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateNameType) (KeyM_GetCertificateNameOfPCConfig()[(Index)]);
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
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertCsmSignatureVerifyKeyRefValidOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_CERTCSMSIGNATUREVERIFYKEYREFVALIDOFCERTIFICATE_MASK));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_IsCertUsePortOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (KEYM_CERTUSEPORTOFCERTIFICATE_MASK == (KeyM_GetMaskedBitsOfCertificate(Index) & KEYM_CERTUSEPORTOFCERTIFICATE_MASK));
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
  return (KeyM_CertStorageEndIdxOfCertificateType) ((KeyM_CertStorageEndIdxOfCertificateType)((KeyM_GetCertStorageStartIdxOfCertificate(Index) + 600u)));
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
  return (KeyM_CertStorageStatusLengthOfCertificateType) ((KeyM_CertStorageStatusLengthOfCertificateType)((KeyM_GetCertStorageLengthOfCertificate(Index) - 598u)));
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
KEYM_LOCAL_INLINE FUNC(KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType, KEYM_CODE) KeyM_GetCertUpperHierarchicalCertRefIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType) ((KeyM_CertUpperHierarchicalCertRefIdxOfCertificateType)((KeyM_GetCertStorageLengthOfCertificate(Index) - 600u)));
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
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameEndIdxOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameEndIdxOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateNameEndIdxOfCertificateType) ((KeyM_CertificateNameEndIdxOfCertificateType)((KeyM_GetCertificateNameStartIdxOfCertificate(Index) + 39u)));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateNameLengthOfCertificateType, KEYM_CODE) KeyM_GetCertificateNameLengthOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_CertificateNameLengthOfCertificateType) ((KeyM_CertificateNameLengthOfCertificateType)((KeyM_GetCertStorageLengthOfCertificate(Index) - 561u)));
}
/*! \spec requires Index < KeyM_GetSizeOfCertificate(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_MaskedBitsOfCertificateType, KEYM_CODE) KeyM_GetMaskedBitsOfCertificate(KeyM_CertificateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  KEYM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (KeyM_MaskedBitsOfCertificateType) ((KeyM_MaskedBitsOfCertificateType)((KeyM_GetCertStorageWrittenLengthLengthOfCertificate(Index) + 166u)));
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
  return (KeyM_RemoteCertificateIdOfCertificateType) ((KeyM_RemoteCertificateIdOfCertificateType)((KeyM_GetCertStorageLengthOfCertificate(Index) - 600u)));
}
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateChainMaxDepthOfGeneralType, KEYM_CODE) KeyM_GetCertificateChainMaxDepthOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateChainMaxDepthOfGeneralType) KeyM_GetCertificateChainMaxDepthOfGeneralOfPCConfig();
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
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateManagerEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateManagerEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateManagerEnabledOfGeneralType) KeyM_IsCertificateManagerEnabledOfGeneralOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateSigningRequestEnabledOfGeneralType, KEYM_CODE) KeyM_IsCertificateSigningRequestEnabledOfGeneral(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_CertificateSigningRequestEnabledOfGeneralType) KeyM_IsCertificateSigningRequestEnabledOfGeneralOfPCConfig();
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
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateGetCurrentTimeCalloutType, KEYM_CODE) KeyM_GetSizeOfCertificateGetCurrentTimeCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateGetCurrentTimeCalloutType) KeyM_GetSizeOfCertificateGetCurrentTimeCalloutOfPCConfig();
}
KEYM_LOCAL_INLINE FUNC(KeyM_SizeOfCertificateNameType, KEYM_CODE) KeyM_GetSizeOfCertificateName(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_SizeOfCertificateNameType) KeyM_GetSizeOfCertificateNameOfPCConfig();
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
/*! \spec requires Index < KeyM_GetSizeOfCert_StorageType(); \endspec */ 
KEYM_LOCAL_INLINE FUNC(KeyM_Cert_StorageTypePtrType, KEYM_CODE) KeyM_GetAddrCert_StorageType(KeyM_Cert_StorageTypeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (KeyM_Cert_StorageTypePtrType) (&(KeyM_GetCert_StorageTypeOfPCConfig()[(Index)]));
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
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertUsePortOfCertificate(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCommonCertData(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGetCurrentTimeCallout(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateName(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCertificateGetCurrentTimeCalloutOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasCommonCertDataOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_HasSizeOfCertificateGetCurrentTimeCalloutOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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

