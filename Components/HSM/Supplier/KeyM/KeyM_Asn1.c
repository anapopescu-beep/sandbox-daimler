/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  KeyM_Asn1.c
 *         \unit  *
 *        \brief  Source file of the ASN.1 parser
 *      \details  Implementation of ASN1 Certificate Parsing Submodule
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define KEYM_ASN1_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "KeyM_Asn1.h"
#include "KeyM_Cert.h"
#include "KeyM_Utils.h"
#include "vstdlib.h"

#if (KEYM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (KEYM_LOCAL) /* COV_KEYM_LOCAL_DEFINE */
# define KEYM_LOCAL                                                   static
#endif

#if !defined (KEYM_LOCAL_INLINE) /* COV_KEYM_LOCAL_DEFINE */
# define KEYM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

#define KEYM_ASN1_ROOT_NESTING_LEVEL                                  (2u)
#define KEYM_ASN1_CVC_PUBKEY_SEVERAL_ELEMENTS                         (0x81u)
#define KEYM_ASN1_CVC_PUBKEY_ONLY_PUBLIC_POINT                        (0x86u)

/* Certificate signing request */
#define KEYM_ASN1_CSR_ELEMENT_VERSION                                 (0x00u)
#define KEYM_ASN1_CSR_ELEMENT_OID                                     (0x01u)
#define KEYM_ASN1_CSR_ELEMENT_PUB_KEY                                 (0x03u)
#define KEYM_ASN1_CSR_ELEMENT_SIGNATURE                               (0x04u)
#define KEYM_ASN1_CSR_ELEMENT_SEQUENCE                                (0x05u)
#define KEYM_ASN1_CSR_ELEMENT_SET                                     (0x06u)
#define KEYM_ASN1_CSR_ELEMENT_CERTREQINFO_SEQUENCE                    (0x07u)
#define KEYM_ASN1_CSR_ELEMENT_CONTEXT_SPECIFIC                        (0x08u)
#define KEYM_ASN1_CSR_ELEMENT_CONSTRUCTED_BITSTRING                   (0x09u)
#define KEYM_ASN1_CSR_ELEMENT_NULL                                    (0x0au)

#define KEYM_ASN1_SIZE_OF_X509_CERTELEMENTNESTINGLEVEL                (12u)
#define KEYM_ASN1_SIZE_OF_CRL_CERTELEMENTNESTINGLEVEL                 (9u)
#define KEYM_ASN1_SIZE_OF_CVC_CERTELEMENTNESTINGLEVEL                 (9u)

#define KEYM_ASN1_CSR_VERSIONDATALENGTH                               (1u)
#define KEYM_ASN1_CSR_UNSTRUCTUREDNAMEOIDDATALENGTH                   (9u)
#define KEYM_ASN1_CSR_CHALLENGEPASSWORDOIDDATALENGTH                  (9u)
#define KEYM_ASN1_CSR_EXTENSIONREQUESTOIDDATALENGTH                   (9u)

/* Nesting Levels */
#define KEYM_ASN1_CSR_NL_0                                            (0u)
#define KEYM_ASN1_CSR_NL_1                                            (1u)
#define KEYM_ASN1_CSR_NL_2                                            (2u)
#define KEYM_ASN1_CSR_NL_3                                            (3u)
#define KEYM_ASN1_CSR_NL_4                                            (4u)
#define KEYM_ASN1_CSR_NL_5                                            (5u)
#define KEYM_ASN1_CSR_NL_6                                            (6u)
#define KEYM_ASN1_CSR_NL_7                                            (7u)
/* remember to adapt the check below when adding new nesting levels .   */

#if (KEYM_ASN1_PARSE_MAX_NESTING_LEVEL < KEYM_ASN1_CSR_NL_7)
# error "/MICROSAR/KeyM/KeyMGeneral/KeyMParseMaxNestingLevel is configured too low. Please set it to at least 7."
#endif

/* 2 bytes for potential leading zero and 0x04 for uncompressed coordinate format */
#define KEYM_CERTIFICATE_PUB_KEY_BUFFER_MAX_LENGTH                    (KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH + 2u)

/* Online certificate status protocol */
#define KEYM_ASN1_OCSP_RESPONSE_ROOT_NL                               (6u)

#define KEYM_ASN1_OCSP_RESPONSE_RESPONSESTATUS                        (0x00u)
#define KEYM_ASN1_OCSP_RESPONSE_RESPONSETYPE                          (0x01u)
#define KEYM_ASN1_OCSP_RESPONSE_VERSION                               (0x02u)
#define KEYM_ASN1_OCSP_RESPONSE_RESPONDERID                           (0x03u)
#define KEYM_ASN1_OCSP_RESPONSE_PRODUCEDAT                            (0x04u)
#define KEYM_ASN1_OCSP_RESPONSE_CERTID_HASHALGORITHM                  (0x05u)
#define KEYM_ASN1_OCSP_RESPONSE_CERTID_ISSUERNAMEHASH                 (0x06u)
#define KEYM_ASN1_OCSP_RESPONSE_CERTID_ISSUERKEYHASH                  (0x07u)
#define KEYM_ASN1_OCSP_RESPONSE_CERTID_SERIALNUMBER                   (0x08u)
#define KEYM_ASN1_OCSP_RESPONSE_CERTSTATUS                            (0x09u)
#define KEYM_ASN1_OCSP_RESPONSE_THISUPDATE                            (0x0Au)
#define KEYM_ASN1_OCSP_RESPONSE_NEXTUPDATE                            (0x0Bu)
#define KEYM_ASN1_OCSP_RESPONSE_SINGLEEXTENSIONS                      (0x0Cu)
#define KEYM_ASN1_OCSP_RESPONSE_RESPONSEEXTENSIONS                    (0x0Du)
#define KEYM_ASN1_OCSP_RESPONSE_SIGNATUREALGORITHM                    (0x0Eu)
#define KEYM_ASN1_OCSP_RESPONSE_SIGNATURE                             (0x0Fu)
#define KEYM_ASN1_OCSP_RESPONSE_CERTS                                 (0x10u)

/* Context specific ASN.1 tag identifiers of OCSP response */
#define KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_RESPONDERID               (0xA2u)
#define KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_SINGLEEXTENSIONS          (0xA1u)
#define KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_RESPONSEEXTENSIONS        (0xA1u)
#define KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_CERTSTATUS_GOOD           (0x80u)
#define KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_CERTSTATUS_REVOKED        (0x81u)
#define KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_CERTSTATUS_UNKNOWN        (0x82u)
#define KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_CERTS                     (0xA0u)

/* Nesting level of constructed OCSP response attributes */
#define KEYM_ASN1_OCSP_NL_RESPONDERID                                 (0x06u)
#define KEYM_ASN1_OCSP_NL_SINGLEEXTENSIONS                            (0x08u)
#define KEYM_ASN1_OCSP_NL_RESPONSEEXTENSIONS                          (0x06u)
#define KEYM_ASN1_OCSP_NL_CERTSTATUS                                  (0x08u)
#define KEYM_ASN1_OCSP_NL_CERTS                                       (0x05u)

#define KEYM_ASN1_OCSP_SIZE_OF_OCSP_RESPONSE_ELEMENT                  (0x11u)
#define KEYM_ASN1_OCSP_SIZE_OF_OCSP_RESPONDERID_ELEMENT               (0x06u)

#define KEYM_ASN1_OID_DESCR_X509_MAX_IDX                              (0x05u)
#define KEYM_ASN1_OID_DESCR_CVC_MAX_IDX                               (0x01u)
#define KEYM_ASN1_OID_DESCR_CRL_MAX_IDX                               (0x03u)

#define KEYM_ASN1_OID_DESCR_X509_SIZE                                 (KEYM_ASN1_OID_DESCR_X509_MAX_IDX + 1u)
#define KEYM_ASN1_OID_DESCR_CVC_SIZE                                  (KEYM_ASN1_OID_DESCR_CVC_MAX_IDX + 1u)
#define KEYM_ASN1_OID_DESCR_CRL_SIZE                                  (KEYM_ASN1_OID_DESCR_CRL_MAX_IDX + 1u)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
typedef struct
{
  uint8 ofStructureOfOcspElement;
  uint8 objectTypeOfOcspElement;
  uint8 refIdxOcspElement;
  boolean isOptionalOfOcspElement;
} KeyM_Asn1_OcspElementType;

typedef struct
{
  uint8 responderIdElementOidEndIdx;
  uint8 responderIdElementOidStartIdx;
  uint8 refIdxOcspElement;
} KeyM_Asn1_OcspResponderIdElementType;
#endif

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
typedef struct
{
  uint8 csrElementOidEndIdx;
  uint8 csrElementOidStartIdx;
  uint8 elementType;
} KeyM_Asn1_CsrInfoElementType;
#endif

typedef struct
{
  KeyM_OfStructureOfCertificateElementType structureType;
  uint16 elementNestingLevel;
  uint16 oidNestingLevel;
  boolean isIterative;
} KeyM_Asn1_OidElementDescrType;

typedef struct
{
  KeyM_OfStructureOfCertificateElementType structureType;
  uint16 elementNestingLevel;
  uint16 constructedElementNestingLevel;
} KeyM_Asn1_CertElementDescrType;

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)

# define KEYM_START_SEC_VAR_NO_INIT_8
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

KEYM_LOCAL VAR(uint8, KEYM_VAR_NO_INIT)  KeyM_Asn1_PubKeyBuffer[KEYM_CERTIFICATE_PUB_KEY_BUFFER_MAX_LENGTH];

KEYM_LOCAL VAR(uint8, KEYM_VAR_NO_INIT)  KeyM_Asn1_SecondaryPubKeyBuffer[KEYM_CERTIFICATE_PUB_KEY_BUFFER_MAX_LENGTH]; /* PRQA S 3218 */ /* MD_KEYM_8.9 */

# define KEYM_STOP_SEC_VAR_NO_INIT_8
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define KEYM_START_SEC_VAR_NO_INIT_32
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

KEYM_LOCAL VAR(uint32, KEYM_VAR_NO_INIT) KeyM_Asn1_PubKeyLength;

KEYM_LOCAL VAR(uint32, KEYM_VAR_NO_INIT) KeyM_Asn1_SecondaryPubKeyLength; /* PRQA S 3218 */ /* MD_KEYM_8.9 */

# define KEYM_STOP_SEC_VAR_NO_INIT_32
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

#define KEYM_START_SEC_CONST_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_X509_CertElementPath_Version[4u] =                  { 1, 1, 1, 1 };     /* PRQA S 3218 */ /* MD_KEYM_8.9 */
KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_X509_CertElementPath_SerialNumber[3u] =             { 1, 1, 1 };        /* PRQA S 3218 */ /* MD_KEYM_8.9 */
KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_X509_CertElementPath_SignatureAlgorithmId[4u] =     { 1, 1, 2, 1 };     /* PRQA S 3218 */ /* MD_KEYM_8.9 */
KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_X509_CertElementPath_ValidityPeriodNotBefore[4u] =  { 1, 1, 4, 1 };     /* PRQA S 3218 */ /* MD_KEYM_8.9 */
KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_X509_CertElementPath_ValidityPeriodNotAfter[4u] =   { 1, 1, 4, 2 };     /* PRQA S 3218 */ /* MD_KEYM_8.9 */
KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_X509_CertElementPath_PublicKeyAlgorithm[5u] =       { 1, 1, 6, 1, 1 };  /* PRQA S 3218 */ /* MD_KEYM_8.9 */
KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_X509_CertElementPath_PublicKeyEccCurve[5u] =        { 1, 1, 6, 1, 2 };  /* PRQA S 3218 */ /* MD_KEYM_8.9 */
KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_X509_CertElementPath_PublicKey[4u] =                { 1, 1, 6, 2 };     /* PRQA S 3218 */ /* MD_KEYM_8.9 */
KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_X509_CertElementPath_SignatureAlgorithm[3u] =       { 1, 2, 1 };        /* PRQA S 3218 */ /* MD_KEYM_8.9 */
KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_X509_CertElementPath_Signature[2u] =                { 1, 3 };           /* PRQA S 3218 */ /* MD_KEYM_8.9 */

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)

KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_Csr_Version[1u] = { 0x00 }; /* PRQA S 3218 */ /* MD_KEYM_8.9 */

KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_Csr_UnstructuredNameOid[9u] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x09, 0x02 };

KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_Csr_ChallengePassword[9u] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x09, 0x07 };

KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Asn1_Csr_ExtensionRequest[9u] = { 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x09, 0x0e }; /* PRQA S 3218 */ /* MD_KEYM_8.9 */

#endif

#define KEYM_STOP_SEC_CONST_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)

# define KEYM_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* CSR elements */
KEYM_LOCAL CONST(KeyM_Asn1_CsrInfoElementType, KEYM_CONST) KeyM_Asn1_CsrElement[14u] = { /* PRQA S 3218 */ /* MD_KEYM_8.9 */
    /* Index            csrElementOidEndIdx         csrElementOidStartIdx                                              elementType */
  { /*     0 */                          3u,                           0u,          KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_COUNTRYNAME },
  { /*     1 */                          6u,                           3u,  KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_STATEORPROVINCENAME },
  { /*     2 */                          9u,                           6u,         KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_LOCALITYNAME },
  { /*     3 */                         12u,                           9u,     KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_ORGANIZATIONNAME },
  { /*     4 */                         15u,                          12u, KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_ORGANIZATIONUNITNAME },
  { /*     5 */                         18u,                          15u,           KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_COMMONNAME },
  { /*     6 */                         21u,                          18u,              KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_SURNAME },
  { /*     7 */                         24u,                          21u,         KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_SERIALNUMBER },
  { /*     8 */                         27u,                          24u,        KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_STREETADDRESS },
  { /*     9 */                         30u,                          27u,                KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_TITLE },
  { /*    10 */                         33u,                          30u,            KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_GIVENNAME },
  { /*    11 */                         42u,                          33u,                KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_EMAIL },
  { /*    12 */                         52u,                          42u,               KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_USERID },
  { /*    13 */                         62u,                          52u,      KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_DOMAINCOMPONENT },
};

# define KEYM_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

#if ((KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON) || (KEYM_OCSP == STD_ON)) /* COV_REMOTE_OCSP */
# define KEYM_START_SEC_CONST_8
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Object identifier in distinguished name */
KEYM_LOCAL CONST(KeyM_ElementOidType, KEYM_CONST) KeyM_Asn1_ElementOid[62u] = { /* PRQA S 3218 */ /* MD_KEYM_8.9 */
  /* Index     ElementOid      Comment                       */
  /*     0 */         85u,  /* [2.5.4.6]                     */
  /*     1 */          4u,  /* [2.5.4.6]                     */
  /*     2 */          6u,  /* [2.5.4.6]                     */
  /*     3 */         85u,  /* [2.5.4.8]                     */
  /*     4 */          4u,  /* [2.5.4.8]                     */
  /*     5 */          8u,  /* [2.5.4.8]                     */
  /*     6 */         85u,  /* [2.5.4.7]                     */
  /*     7 */          4u,  /* [2.5.4.7]                     */
  /*     8 */          7u,  /* [2.5.4.7]                     */
  /*     9 */         85u,  /* [2.5.4.10]                    */
  /*    10 */          4u,  /* [2.5.4.10]                    */
  /*    11 */         10u,  /* [2.5.4.10]                    */
  /*    12 */         85u,  /* [2.5.4.11]                    */
  /*    13 */          4u,  /* [2.5.4.11]                    */
  /*    14 */         11u,  /* [2.5.4.11]                    */
  /*    15 */         85u,  /* [2.5.4.3]                     */
  /*    16 */          4u,  /* [2.5.4.3]                     */
  /*    17 */          3u,  /* [2.5.4.3]                     */
  /*    18 */         85u,  /* [2.5.4.4]                     */
  /*    19 */          4u,  /* [2.5.4.4]                     */
  /*    20 */          4u,  /* [2.5.4.4]                     */
  /*    21 */         85u,  /* [2.5.4.5]                     */
  /*    22 */          4u,  /* [2.5.4.5]                     */
  /*    23 */          5u,  /* [2.5.4.5]                     */
  /*    24 */         85u,  /* [2.5.4.9]                     */
  /*    25 */          4u,  /* [2.5.4.9]                     */
  /*    26 */          5u,  /* [2.5.4.9]                     */
  /*    27 */         85u,  /* [2.5.4.12]                    */
  /*    28 */          4u,  /* [2.5.4.12]                    */
  /*    29 */         12u,  /* [2.5.4.12]                    */
  /*    30 */         85u,  /* [2.5.4.42]                    */
  /*    31 */          4u,  /* [2.5.4.42]                    */
  /*    32 */         42u,  /* [2.5.4.42]                    */
  /*    33 */         42u,  /* [1.2.840.113549.1.9.1]        */
  /*    34 */        134u,  /* [1.2.840.113549.1.9.1]        */
  /*    35 */         72u,  /* [1.2.840.113549.1.9.1]        */
  /*    36 */        134u,  /* [1.2.840.113549.1.9.1]        */
  /*    37 */        247u,  /* [1.2.840.113549.1.9.1]        */
  /*    38 */         13u,  /* [1.2.840.113549.1.9.1]        */
  /*    39 */          1u,  /* [1.2.840.113549.1.9.1]        */
  /*    40 */          9u,  /* [1.2.840.113549.1.9.1]        */
  /*    41 */          1u,  /* [1.2.840.113549.1.9.1]        */
  /*    42 */          9u,  /* [0.9.2342.19200300.100.1.1]   */
  /*    43 */        146u,  /* [0.9.2342.19200300.100.1.1]   */
  /*    44 */         38u,  /* [0.9.2342.19200300.100.1.1]   */
  /*    45 */        137u,  /* [0.9.2342.19200300.100.1.1]   */
  /*    46 */        147u,  /* [0.9.2342.19200300.100.1.1]   */
  /*    47 */        242u,  /* [0.9.2342.19200300.100.1.1]   */
  /*    48 */         44u,  /* [0.9.2342.19200300.100.1.1]   */
  /*    49 */        100u,  /* [0.9.2342.19200300.100.1.1]   */
  /*    50 */          1u,  /* [0.9.2342.19200300.100.1.1]   */
  /*    51 */          1u,  /* [0.9.2342.19200300.100.1.1]   */
  /*    52 */          9u,  /* [0.9.2342.19200300.100.1.25]  */
  /*    53 */        146u,  /* [0.9.2342.19200300.100.1.25]  */
  /*    54 */         38u,  /* [0.9.2342.19200300.100.1.25]  */
  /*    55 */        137u,  /* [0.9.2342.19200300.100.1.25]  */
  /*    56 */        147u,  /* [0.9.2342.19200300.100.1.25]  */
  /*    57 */        242u,  /* [0.9.2342.19200300.100.1.25]  */
  /*    58 */         44u,  /* [0.9.2342.19200300.100.1.25]  */
  /*    59 */        100u,  /* [0.9.2342.19200300.100.1.25]  */
  /*    60 */          1u,  /* [0.9.2342.19200300.100.1.25]  */
  /*    61 */         25u,  /* [0.9.2342.19200300.100.1.25]  */
};
# define KEYM_STOP_SEC_CONST_8
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

#define KEYM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* X509 Certificate Element Description */
KEYM_LOCAL CONST(KeyM_Asn1_CertElementDescrType, KEYM_CONST) KeyM_Asn1_CertElementDescr_X509[KEYM_ASN1_SIZE_OF_X509_CERTELEMENTNESTINGLEVEL] = { /* PRQA S 3218 */ /* MD_KEYM_8.9 */
    /* Index                                                    StructureType   ElementNestingLevel  ConstructedElementNestingLevel */
  { /*     0 */                               KEYM_CERTIFICATE_VERSION_NUMBER,                   2u,                             2u },
  { /*     1 */                                KEYM_CERTIFICATE_SERIAL_NUMBER,                   2u,                             2u },
  { /*     2 */                       KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID,                   2u,                             2u },
  { /*     3 */                                  KEYM_CERTIFICATE_ISSUER_NAME,                   4u,                             2u },
  { /*     4 */                   KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE,                   4u,                             2u },
  { /*     5 */                    KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER,                   4u,                             2u },
  { /*     6 */                                 KEYM_CERTIFICATE_SUBJECT_NAME,                   4u,                             2u },
  { /*     7 */ KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM,                   3u,                             3u },
  { /*     8 */   KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY,                   3u,                             3u },
  { /*     9 */                                    KEYM_CERTIFICATE_EXTENSION,                   4u,                             2u },
  { /*    10 */                          KEYM_CERTIFICATE_SIGNATURE_ALGORITHM,                   1u,                             1u },
  { /*    11 */                                    KEYM_CERTIFICATE_SIGNATURE,                   1u,                             1u },
};

/* CRL Certificate Element Description */
KEYM_LOCAL CONST(KeyM_Asn1_CertElementDescrType, KEYM_CONST) KeyM_Asn1_CertElementDescr_CRL[KEYM_ASN1_SIZE_OF_CRL_CERTELEMENTNESTINGLEVEL] = { /* PRQA S 3218 */ /* MD_KEYM_8.9 */
    /* Index                                                    StructureType   ElementNestingLevel  ConstructedElementNestingLevel */
  { /*     0 */                               KEYM_CERTIFICATE_VERSION_NUMBER,                   2u,                             2u },
  { /*     1 */                       KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID,                   2u,                             2u },
  { /*     2 */                                  KEYM_CERTIFICATE_ISSUER_NAME,                   4u,                             2u },
  { /*     3 */                   KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE,                   4u,                             2u },
  { /*     4 */                    KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER,                   4u,                             2u },
  { /*     5 */                              KEYM_CERTIFICATE_REVOCATION_LIST,                   4u,                             2u },
  { /*     6 */                                    KEYM_CERTIFICATE_EXTENSION,                   4u,                             2u },
  { /*     7 */                          KEYM_CERTIFICATE_SIGNATURE_ALGORITHM,                   1u,                             1u },
  { /*     8 */                                    KEYM_CERTIFICATE_SIGNATURE,                   1u,                             1u },
};

/* CVC Certificate Element Description */
KEYM_LOCAL CONST(KeyM_Asn1_CertElementDescrType, KEYM_CONST) KeyM_Asn1_CertElementDescr_CVC[KEYM_ASN1_SIZE_OF_CVC_CERTELEMENTNESTINGLEVEL] = { /* PRQA S 3218 */ /* MD_KEYM_8.9 */
    /* Index                                                    StructureType   ElementNestingLevel  ConstructedElementNestingLevel */
  { /*     0 */                               KEYM_CERTIFICATE_VERSION_NUMBER,                   2u,                             2u },
  { /*     1 */                                  KEYM_CERTIFICATE_ISSUER_NAME,                   2u,                             2u },
  { /*     2 */ KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM,                   3u,                             2u },
  { /*     3 */   KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY,                   3u,                             2u },
  { /*     4 */                                 KEYM_CERTIFICATE_SUBJECT_NAME,                   2u,                             2u },
  { /*     5 */                    KEYM_CERTIFICATE_SUBJECT_UNIQUE_IDENTIFIER,                   3u,                             2u },
  { /*     6 */                   KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE,                   2u,                             2u },
  { /*     7 */                    KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER,                   2u,                             2u },
  { /*     8 */                                    KEYM_CERTIFICATE_SIGNATURE,                   1u,                             1u },
};

/* X509 OID Element Description  */
KEYM_LOCAL CONST(KeyM_Asn1_OidElementDescrType, KEYM_CONST) KeyM_Asn1_OidElementDescr_X509[KEYM_ASN1_OID_DESCR_X509_SIZE] = { /* PRQA S 3218 */ /* MD_KEYM_8.9 */
    /* Index                                                    StructureType   ElementNestingLevel OidNestingLevel  isIterative */
  { /*     0 */                       KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID,                   2u,             3u,       FALSE },
  { /*     1 */                                  KEYM_CERTIFICATE_ISSUER_NAME,                   3u,             5u,        TRUE },
  { /*     2 */                                 KEYM_CERTIFICATE_SUBJECT_NAME,                   3u,             5u,        TRUE },
  { /*     3 */ KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM,                   3u,             4u,       FALSE },
  { /*     4 */                                    KEYM_CERTIFICATE_EXTENSION,                   4u,             5u,        TRUE },
  { /*     5 */                          KEYM_CERTIFICATE_SIGNATURE_ALGORITHM,                   1u,             2u,       FALSE },
};

/* CRL OID Element Description */
KEYM_LOCAL CONST(KeyM_Asn1_OidElementDescrType, KEYM_CONST) KeyM_Asn1_OidElementDescr_CRL[KEYM_ASN1_OID_DESCR_CRL_SIZE] = { /* PRQA S 3218 */ /* MD_KEYM_8.9 */
            /* Index                                                    StructureType   ElementNestingLevel OidNestingLevel  isIterative */
  { /*     0 */                       KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID,                   2u,             3u,       FALSE },
  { /*     1 */                                  KEYM_CERTIFICATE_ISSUER_NAME,                   3u,             5u,        TRUE },
  { /*     2 */                                    KEYM_CERTIFICATE_EXTENSION,                   4u,             5u,        TRUE },
  { /*     3 */                          KEYM_CERTIFICATE_SIGNATURE_ALGORITHM,                   1u,             2u,       FALSE },
};

/* CVC OID Element Description */
KEYM_LOCAL CONST(KeyM_Asn1_OidElementDescrType, KEYM_CONST) KeyM_Asn1_OidElementDescr_CVC[KEYM_ASN1_OID_DESCR_CVC_SIZE] = { /* PRQA S 3218 */ /* MD_KEYM_8.9 */
            /* Index                                                    StructureType   ElementNestingLevel OidNestingLevel  isIterative */
  { /*     0 */ KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM,                   2u,             3u,       FALSE },
  { /*     1 */                    KEYM_CERTIFICATE_SUBJECT_UNIQUE_IDENTIFIER,                   2u,             3u,       FALSE },
};

#define KEYM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
# define KEYM_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Distinguished name elements of ResponderId field in BasicOCSPResponse */
KEYM_LOCAL CONST(KeyM_Asn1_OcspResponderIdElementType, KEYM_CONST) KeyM_Asn1_OCSPResponderIdElement[14u] = { /* PRQA S 3218 */ /* MD_KEYM_8.9 */
  /* Index      responderIdElementOidEndIdx responderIdElementOidStartIdx                                                             RefIdx */
  { /*     0 */                          3u,                           0u,          KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_COUNTRYNAME },
  { /*     1 */                          6u,                           3u,  KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_STATEORPROVINCENAME },
  { /*     2 */                          9u,                           6u,         KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_LOCALITYNAME },
  { /*     3 */                         12u,                           9u,     KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_ORGANIZATIONNAME },
  { /*     4 */                         15u,                          12u, KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_ORGANIZATIONUNITNAME },
  { /*     5 */                         18u,                          15u,           KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_COMMONNAME },
  { /*     6 */                         21u,                          18u,              KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_SURNAME },
  { /*     7 */                         24u,                          21u,         KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_SERIALNUMBER },
  { /*     8 */                         27u,                          24u,        KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_STREETADDRESS },
  { /*     9 */                         30u,                          27u,                KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_TITLE },
  { /*    10 */                         33u,                          30u,            KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_GIVENNAME },
  { /*    11 */                         42u,                          33u,                KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_EMAIL },
  { /*    12 */                         52u,                          42u,               KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_USERID },
  { /*    13 */                         62u,                          52u,      KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_DOMAINCOMPONENT },
};

/* BasicOCSPResponse elements */
KEYM_LOCAL CONST(KeyM_Asn1_OcspElementType, KEYM_CONST) KeyM_Asn1_OCSPElement[17u] = {
    /* Index                                               OfStructure                           ObjectType                                                RefIdx  IsOptional */
  { /*     0 */                 KEYM_ASN1_OCSP_RESPONSE_RESPONSESTATUS,           KEYM_ASN1_TYPE_ENUMERATED,        KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSESTATUS,      FALSE },
  { /*     1 */                   KEYM_ASN1_OCSP_RESPONSE_RESPONSETYPE,             KEYM_ASN1_TYPE_OBJECTID,          KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSETYPE,      FALSE },
  { /*     2 */                        KEYM_ASN1_OCSP_RESPONSE_VERSION,              KEYM_ASN1_TYPE_INTEGER,               KEYM_ASN1_OCSP_RESPONSE_REFIDX_VERSION,       TRUE },
  { /*     3 */                    KEYM_ASN1_OCSP_RESPONSE_RESPONDERID,    KEYM_ASN1_CLASS_CONTEXT_SPECIFIC,           KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID,      FALSE },
  { /*     4 */                     KEYM_ASN1_OCSP_RESPONSE_PRODUCEDAT, KEYM_ASN1_TYPE_UTC_GENERALIZED_TIME,            KEYM_ASN1_OCSP_RESPONSE_REFIDX_PRODUCEDAT,      FALSE },
  { /*     5 */           KEYM_ASN1_OCSP_RESPONSE_CERTID_HASHALGORITHM,             KEYM_ASN1_TYPE_OBJECTID,  KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_HASHALGORITHM,      FALSE },
  { /*     6 */          KEYM_ASN1_OCSP_RESPONSE_CERTID_ISSUERNAMEHASH,         KEYM_ASN1_TYPE_OCTET_STRING, KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_ISSUERNAMEHASH,      FALSE },
  { /*     7 */           KEYM_ASN1_OCSP_RESPONSE_CERTID_ISSUERKEYHASH,         KEYM_ASN1_TYPE_OCTET_STRING,  KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_ISSUERKEYHASH,      FALSE },
  { /*     8 */            KEYM_ASN1_OCSP_RESPONSE_CERTID_SERIALNUMBER,              KEYM_ASN1_TYPE_INTEGER,   KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_SERIALNUMBER,      FALSE },
  { /*     9 */                     KEYM_ASN1_OCSP_RESPONSE_CERTSTATUS,    KEYM_ASN1_CLASS_CONTEXT_SPECIFIC,            KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTSTATUS,      FALSE },
  { /*    10 */                     KEYM_ASN1_OCSP_RESPONSE_THISUPDATE, KEYM_ASN1_TYPE_UTC_GENERALIZED_TIME,            KEYM_ASN1_OCSP_RESPONSE_REFIDX_THISUPDATE,      FALSE },
  { /*    11 */                     KEYM_ASN1_OCSP_RESPONSE_NEXTUPDATE, KEYM_ASN1_TYPE_UTC_GENERALIZED_TIME,            KEYM_ASN1_OCSP_RESPONSE_REFIDX_NEXTUPDATE,       TRUE },
  { /*    12 */               KEYM_ASN1_OCSP_RESPONSE_SINGLEEXTENSIONS,    KEYM_ASN1_CLASS_CONTEXT_SPECIFIC,      KEYM_ASN1_OCSP_RESPONSE_REFIDX_SINGLEEXTENSIONS,       TRUE },
  { /*    13 */             KEYM_ASN1_OCSP_RESPONSE_RESPONSEEXTENSIONS,    KEYM_ASN1_CLASS_CONTEXT_SPECIFIC,    KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSEEXTENSIONS,       TRUE },
  { /*    14 */             KEYM_ASN1_OCSP_RESPONSE_SIGNATUREALGORITHM,             KEYM_ASN1_TYPE_OBJECTID,    KEYM_ASN1_OCSP_RESPONSE_REFIDX_SIGNATUREALGORITHM,      FALSE },
  { /*    15 */                      KEYM_ASN1_OCSP_RESPONSE_SIGNATURE,           KEYM_ASN1_TYPE_BIT_STRING,             KEYM_ASN1_OCSP_RESPONSE_REFIDX_SIGNATURE,      FALSE },
  { /*    16 */                          KEYM_ASN1_OCSP_RESPONSE_CERTS,    KEYM_ASN1_CLASS_CONTEXT_SPECIFIC,                 KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTS,       TRUE },
};
# define KEYM_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define KEYM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * KeyM_Asn1_ExtractByte()
 *********************************************************************************************************************/
/*! \brief          Extract the byte from the ASN string.
 *  \details        Extracts the byte from the buffer and increments currentPos.
 *  \param[in,out]  paramDataPtr                    Pointer to the ASN descriptor
 *  \param[in,out]  value                           Pointer to the data byte.
 *  \return         KEYM_ASN1_RC_OK                 The following data byte could be extracted successfully.
 *                  KEYM_ASN1_RC_FAILED             No more data bytes available in the ASN.1 string.
 *  \note           Increments currentPos and decrements remainingBytes in the structure.
 *  \pre            All provided pointers must be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ExtractByte(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) value);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseUniversalTag()
 *********************************************************************************************************************/
/*! \brief          Parses universal tag.
 *  \details        -
 *  \param[in]      tagByte                         Parsed tag identifier byte.
 *  \param[out]     objectType                      Ptr to the tag byte.
 *  \param[out]     tag_has_data                    Flag for constructed / primitive structure.
 *  \return         KEYM_ASN1_RC_OK                 The following tag identifier was retrieved successfully.
 *                  KEYM_ASN1_RC_UNSUPPORTED_TAG    Parsed tag identifier is not supported.
 *  \pre            All provided pointers must be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseUniversalTag(
  uint8 tagByte,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) objectType,
  P2VAR(boolean, AUTOMATIC, KEYM_APPL_VAR) tag_has_data);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseApplicationTag()
 *********************************************************************************************************************/
/*! \brief          Parses application tag.
 *  \details        -
 *  \param[in,out]  paramDataPtr                    Pointer to the ASN.1 element descriptor.
 *  \param[in]      tagByte                         Parsed tag identifier byte.
 *  \param[out]     objectType                      Ptr to the tag byte.
 *  \return         KEYM_ASN1_RC_OK                 The following tag identifier was retrieved successfully.
 *                  KEYM_ASN1_RC_UNSUPPORTED_TAG    Parsed tag identifier is not supported.
 *  \pre            All provided pointers must be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseApplicationTag(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr,
  uint8 tagByte,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) objectType);

/**********************************************************************************************************************
 * KeyM_Asn1_GetTagByte()
 *********************************************************************************************************************/
/*! \brief          Extracts and checks the tag byte.
 *  \details       -
 *  \param[in,out]  paramDataPtr                    Pointer to the ASN.1 element descriptor.
 *  \param[out]     objectType                      Ptr to the tag byte.
 *  \param[out]     tag_has_data                    Flag for constructed / primitive structure.
 *  \return         KEYM_ASN1_RC_OK                 The following tag identifier was retrieved successfully.
 *                  KEYM_ASN1_RC_FAILED             Due to internal error, no tag identifier could be retrieved.
 *                  KEYM_ASN1_RC_UNSUPPORTED_TAG    Parsed tag identifier is not supported.
 *  \pre            All provided pointers must be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_GetTagByte(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) objectType,
  P2VAR(boolean, AUTOMATIC, KEYM_APPL_VAR) tag_has_data);

/**********************************************************************************************************************
 * KeyM_Asn1_GetLength()
 *********************************************************************************************************************/
/*! \brief         Gets the length information from the ASN string.
 *  \details       -
 *  \param[in,out] paramDataPtr                    Pointer to the ASN.1 element descriptor.
 *  \param[out]    tag_len                         Pointer to the length information.
 *  \return        KEYM_ASN1_RC_OK                 The following tag length was retrieved successfully.
 *                 KEYM_ASN1_RC_FAILED             Due to internal error, no tag length was retrieved.
 *                 KEYM_ASN1_RC_LEN_OVERFLOW       Length mismatch
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_GetLength(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) tag_len);

#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Asn1_UpdateOCSPNestingDepth()
 *********************************************************************************************************************/
/*! \brief         Reverses to last unparsed nesting level within ASN.1 data structure of OCSP response.
 *  \details       -
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_UpdateOCSPNestingDepth(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param);
#endif

/**********************************************************************************************************************
 * KeyM_Asn1_UpdateNestingDepth()
 *********************************************************************************************************************/
/*! \brief         Reverses to last unparsed nesting level within ASN.1 data structure.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_UpdateNestingDepth(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param);

/**********************************************************************************************************************
 * KeyM_Asn1_HandleUnsupportedTag()
 *********************************************************************************************************************/
/*! \brief         Skip prsent unsupported tag.
 *  \details       -
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \return        KEYM_ASN1_RC_OK                 Present unsupported tag was handled successfully.
 *                 KEYM_ASN1_RC_FAILED             Due to internal error, no tag length was retrieved.
 *                 KEYM_ASN1_RC_LEN_OVERFLOW       Length mismatch
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_HandleUnsupportedTag(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseTL()
 *********************************************************************************************************************/
/*! \brief         Parse tag header including tag identifier and tag length.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \return        KEYM_ASN1_RC_OK                 TL header was retrieved successfully.
 *                 KEYM_ASN1_RC_FAILED             Due to internal error, the TL header could not be retrieved.
 *                 KEYM_ASN1_RC_LEN_OVERFLOW       Length mismatch
 *                 KEYM_ASN1_RC_UNSUPPORTED_TAG    Parsed tag identifier is not supported.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseTL(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param);

/**********************************************************************************************************************
 * KeyM_Asn1_SkipLeadingOctet()
 *********************************************************************************************************************/
/*! \brief         Skip leading octet in parsed tag.
 *  \details       -
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_SkipLeadingOctet(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param);

/**********************************************************************************************************************
 * KeyM_Asn1_UpdateAsn1Param()
 *********************************************************************************************************************/
/*! \brief         Update ASN.1 parsing descriptor according to certificate type and current certificate element
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in]     asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_UpdateAsn1Param(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseConstructedTag()
 *********************************************************************************************************************/
/*! \brief         Parse constructed tag
 *  \details       -
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[in,out] asn1ParseParamBuffer            Pointer to the ASN descriptor buffer.
 *  \return        KEYM_ASN1_RC_OK                 ASN.1 substructure was derived successfully.
 *                 KEYM_ASN1_RC_FAILED             Due to internal error, the ASN.1 substructure could not be derived.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseConstructedTag(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer);

#if (KEYM_CERTELEMENTPATHUSEDOFCERTIFICATEELEMENT == STD_ON)
/**********************************************************************************************************************
 * KeyM_Asn1_GetNestingLevelOfCertElement()
 *********************************************************************************************************************/
/*! \brief         Retrieves the nesting level for a given certificate element type.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in]     elementStructureType            Defines the structure type of a certificate element.
 *  \param[out]    nestingLevel                    Holds the certificate element nesting level.
 *  \return        TRUE                            Found.
 *                 FALSE                           Not found.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Asn1_GetNestingLevelOfCertElement(
  KeyM_CertificateIdType certId,
  KeyM_OfStructureOfCertificateElementType elementStructureType,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) nestingLevel);
#endif

/**********************************************************************************************************************
 * KeyM_Asn1_CheckParsedTag()
 *********************************************************************************************************************/
/*! \brief        Check parsed tag identifier and OID against configuration.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in]     asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \return        KEYM_ASN1_RC_OK                 ASN.1 tag was checked against configuration successfully.
 *                 KEYM_ASN1_RC_FAILED             Internal error or configuration mismatch occurred.
 *                 KEYM_ASN1_RC_LEN_OVERFLOW       Length mismatch.
 *                 KEYM_ASN1_RC_PARSE_CHECK_NEXT   Continue parsing with next tag.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckParsedTag(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param);

/**********************************************************************************************************************
 * KeyM_Asn1_ParsePrimitiveTag()
 *********************************************************************************************************************/
/*! \brief         Parse primitive ASN.1 tag
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in]     asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \return        KEYM_ASN1_RC_OK                 ASN.1 primitive tag was parsed successfully.
 *                 KEYM_ASN1_RC_FAILED             Internal error or configuration mismatch occurred.
 *                 KEYM_ASN1_RC_LEN_OVERFLOW       Length mismatch.
 *                 KEYM_ASN1_RC_PARSE_CHECK_NEXT   Continue parsing with next tag.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE, but not for the same certificate
 *  \synchronous   TRUE
 *  \spec          requires (asn1ParseParam->elementList + asn1ParseParam->noOfElementList) <= KeyM_GetSizeOfCertificateElement(); \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParsePrimitiveTag(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseElementStructure()
 *********************************************************************************************************************/
/*! \brief         Parse current certificate element structure
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[in,out] asn1ParseParamBuffer            Pointer to the ASN descriptor buffer.
 *  \return        KEYM_ASN1_RC_OK                 Certificate element structure was parsed successfully.
 *                 KEYM_ASN1_RC_FAILED             Internal error or configuration mismatch occurred.
 *                 KEYM_ASN1_RC_LEN_OVERFLOW       Length mismatch.
 *                 KEYM_ASN1_RC_PARSE_CHECK_NEXT   Continue parsing with next tag.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE, but not for the same certificate
 *  \synchronous   TRUE
 *  \spec          requires (asn1ParseParam->elementList + asn1ParseParam->noOfElementList) <= KeyM_GetSizeOfCertificateElement(); \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseElementStructure(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseElement()
 *********************************************************************************************************************/
/*! \brief         Parse certificate element.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[in,out] asn1ParseParamBuffer            Pointer to the ASN descriptor buffer.
 *  \return        KEYM_ASN1_RC_OK                 Certificate element was parsed successfully.
 *                 KEYM_ASN1_RC_FAILED             Internal error or configuration mismatch occurred.
 *                 KEYM_ASN1_RC_LEN_OVERFLOW       Length mismatch.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE, but not for the same certificate
 *  \synchronous   TRUE
 *  \spec          requires (asn1ParseParam->elementList + asn1ParseParam->noOfElementList) <= KeyM_GetSizeOfCertificateElement(); \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseElement(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer);

#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Asn1_ParseOCSPElementPrepare()
 *********************************************************************************************************************/
/*! \brief         Initialize ASN.1 description and update nesting depth for next certificate element of a OCSP response.
 *  \details       -
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_ParseOCSPElementPrepare(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param);
#endif

/**********************************************************************************************************************
 * KeyM_Asn1_ParseElementPrepare()
 *********************************************************************************************************************/
/*! \brief         Initialize ASN.1 description and update nesting depth for next certificate element.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_ParseElementPrepare(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param);

/**********************************************************************************************************************
 *  KeyM_Asn1_CheckElementOrder()
 **********************************************************************************************************************/
/*! \brief         Check if the elements have been parsed in ascending order.
 *  \details       -
 *  \param[in]     asn1ParseParam     Pointer to the ASN.1 data descriptor.
 *  \param[in,out] lastPos        Pointer to the offset of the last checked element-
 *  \return        KEYM_ASN1_RC_OK                 Check passed.
 *                 KEYM_ASN1_RC_FAILED             Check failed.
 *  \pre           All pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckElementOrder(
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) lastPos);

/**********************************************************************************************************************
 * KeyM_Asn1_CheckParsedCertElements()
 *********************************************************************************************************************/
/*! \brief         Checks certificate element order and if there are unparsed non-optional elements.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \return        KEYM_ASN1_RC_OK                 Certificate data was parsed successfully.
 *                 KEYM_ASN1_RC_FAILED             Certificate element order is incorrect or there
 *                                                 are unparsed non-optional elements.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE, but not for the same certificate
 *  \synchronous   TRUE
 *  \spec          requires (asn1ParseParam->elementList + asn1ParseParam->noOfElementList) <= KeyM_GetSizeOfCertificateElement(); \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckParsedCertElements(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseProcessing()
 *********************************************************************************************************************/
/*! \brief         Parses the ASN string completely and calls the operation function.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \return        KEYM_ASN1_RC_OK                 Certificate data was parsed successfully.
 *                 KEYM_ASN1_RC_FAILED             Due to internal error, the certificate data could not be parsed.
 *                 KEYM_ASN1_RC_LEN_OVERFLOW       Length mismatch.
 *                 KEYM_ASN1_RC_PARSE_CHECK_NEXT   Continue parsing with next tag.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE, but not for the same certificate
 *  \synchronous   TRUE
 *  \spec          requires (asn1ParseParam->elementList + asn1ParseParam->noOfElementList) <= KeyM_GetSizeOfCertificateElement(); \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseProcessing(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR)  asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR)  asn1Param);

/**********************************************************************************************************************
 * KeyM_Asn1_CheckCertElementOid()
 *********************************************************************************************************************/
/*! \brief         Checks the object identifier of the parsed certificate element.
 *  \details       -
 *  \param[in]     asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \return        KEYM_ASN1_RC_OK                 The object identifier matches with the configuration.
 *                 KEYM_ASN1_RC_FAILED             The object identifier does not match with the configuration.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires KeyM_IsElementOidUsedOfCertificateElement(asn1ParseParam->currentElementIdx);      \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckCertElementOid(
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam);

/**********************************************************************************************************************
 * KeyM_Asn1_CheckCertStructureType()
 *********************************************************************************************************************/
/*! \brief         Checks the structure type of the parsed certificate element.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in]     asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \return        KEYM_ASN1_RC_OK                 The structure type matches with the configuration.
 *                 KEYM_ASN1_RC_FAILED             The structure type does not match with the configuration.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckCertStructureType(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam);

#if (KEYM_CERTELEMENTPATHUSEDOFCERTIFICATEELEMENT == STD_ON)
/**********************************************************************************************************************
 * KeyM_Asn1_CheckCertElementPath()
 *********************************************************************************************************************/
/*! \brief         Checks the element path of the parsed certificate element.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in]     asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \return        KEYM_ASN1_RC_OK                 The element path matches with the configuration.
 *                 KEYM_ASN1_RC_FAILED             The element path does not match with the configuration.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires KeyM_IsCertElementPathUsedOfCertificateElement(asn1ParseParam->currentElementIdx); \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckCertElementPath(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam);
#endif

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Asn1_GetTagIdentifier()
 *********************************************************************************************************************/
/*! \brief         Get ASN1 tag identifier to corresponding certificate element type.
 *  \details       -
 *  \param[in]     certId                            Holds the identifier of the certificate.
 *  \param[in]     elementType                       Defines the certificate element type.
 *  \param[out]    identifierData                    Tag identifier returned by the function. May not be null.
 *  \param[out]    identifierDataLength              Number of bytes written to identifierData. Either 0 or 1.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_GetTagIdentifier(
  KeyM_CertificateIdType certId,
  uint8 elementType,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) identifierData,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) identifierDataLength);

/**********************************************************************************************************************
 * KeyM_Asn1_Csr_IsElementConstructed()
 *********************************************************************************************************************/
/*! \brief         Indicates whether or not the given element type is a constructed one.
 *  \details       -
 *  \param[in]     elementType                       Defines the certificate element type.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Asn1_Csr_IsElementConstructed(uint8 elementType);

/**********************************************************************************************************************
 * KeyM_Asn1_InitCSRInfo()
 *********************************************************************************************************************/
/*! \brief         Initialize ASN.1 description for CSR request data.
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     csrInfo                          Points to an array of request data objects.
 *  \param[in]     elementIds                       Points to an array of certificate element Ids of CSR elements.
 *  \param[in]     numOfReqObjects                  Total number of available request data objects.
 *  \param[in]     descr                            Description of CertReqInfo.
 *  \param[in,out] descrLength                      In: Max number of elements in descr.
 *                                                  Out: Actual number.
 *  \return        KEYM_ASN1_RC_OK                  Description structure for CSR Info was generated successfully
 *                 KEYM_ASN1_RC_FAILED              Due to internal error, the description structure for CSR Info
 *                                                  could not be generated.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *                 csrInfo must reference at least numOfReqObjects many elements.
 *                 elementIds must reference at least numOfReqObjects many elements.
 *                 descr must contain at least KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_MAX_SIZE many elements.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitCSRInfo(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  P2CONST(KeyM_CertElementIdType, AUTOMATIC, KEYM_APPL_DATA) elementIds,
  uint8 numOfReqObjects,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength);

/**********************************************************************************************************************
 * KeyM_Asn1_GetElementIdxByStructureType()
 *********************************************************************************************************************/
/*! \brief         Retrieve certificate element index referenced by structure type.
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     elementStructureType             Defines the structure type of a certificate element.
 *  \param[out]    elementIdx                       Index of the first certificate element matching the given structure.
 *                                                  Must not be NULL.
 *  \return        KEYM_ASN1_RC_OK                  if the specified element was found.
 *                 KEYM_ASN1_RC_FAILED              else.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_GetElementIdxByStructureType(
  KeyM_CertificateIdType certId,
  KeyM_OfStructureOfCertificateElementType elementStructureType,
  KeyM_SizeOfCertificateElementType* elementIdx);

/**********************************************************************************************************************
 * KeyM_Asn1_IsCsrElementAvailable()
 *********************************************************************************************************************/
/*! \brief         Check if a CSR element is available in CsrInfo.
 *  \details       -
 *  \param[in]     csrInfo                           Points to an array of request data objects.
 *  \param[in]     numOfReqObjects                   Total number of available request data objects.
 *  \param[in]     elementType                       Holds the type of a CSR element.
 *  \param[out]    csrInfoIdx                        Element index in CsrInfo array.
 *  \return        TRUE                              CSR element is provided with CsrInfo.
 *                 FALSE                             CSR element is not available.
 *  \pre           All provided pointers must be valid.
 *                 csrInfo must reference at least NumOfReqObjects many elements.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Asn1_IsCsrElementAvailable(
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  uint8 numOfReqObjects,
  uint8 elementType,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) csrInfoIdx);

/**********************************************************************************************************************
 * KeyM_Asn1_InitDescrOfCertReqInfoAttributes()
 *********************************************************************************************************************/
/*! \brief         Init ASN.1 description for CSR attributes.
 *  \details       -
 *  \param[in]     csrInfo                           Points to an array of request data objects.
 *  \param[in]     numOfReqObjects                   Total number of available request data objects.
 *  \param[in]     descr                             Description of CertReqInfo.
 *  \param[in,out] descrLength                       In: Current number of elements in descr.
 *                                                   Out: Updated number of elements in descr including CSR attributes.
 *  \pre           All provided pointers must be valid.
 *                 csrInfo must reference at least numOfReqObjects many elements.
 *                 The current number of elements in descr is valid.
 *                 descr must reference at least (*descrLength + 9) many elements.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoAttributes(
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  uint8 numOfReqObjects,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength);

/**********************************************************************************************************************
 * KeyM_Asn1_InitDescrOfCertReqInfoECCPubKey()
 *********************************************************************************************************************/
/*! \brief         Initialize ASN.1 description for public key according to ECC specific
 *                 certificate structure.
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     pubKeyAlgoElementIdx             Holds the element index for the public key algorithm.
 *  \param[in]     descr                            Description structure of CertReqInfo.
 *  \param[in,out] descrLength                      In: Current number of elements in descr.
 *                                                  Out: Actual number.
 *  \return        KEYM_ASN1_RC_OK                  Operation successful.
 *                 KEYM_ASN1_RC_FAILED              Operation failed.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *                 descr must contain at least KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_MAX_SIZE many elements.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoECCPubKey(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType pubKeyAlgoElementIdx,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength);

/**********************************************************************************************************************
 * KeyM_Asn1_InitDescrOfCertReqInfoExtensions()
 *********************************************************************************************************************/
/*! \brief         Init ASN.1 description for CSR extensions.
 *  \details       -
 *  \param[in]     certId                            Holds the identifier of the certificate.
 *  \param[in]     csrInfo                           Points to an array of request data objects.
 *  \param[in]     elementIds                        Points to an array of certificate element Ids of CSR elements.
 *  \param[in]     numOfReqObjects                   Total number of available request data objects.
 *  \param[out]    descr                             Description returned by the function.
 *  \param[in,out] descrLength                       In: Current number of elements in descr.
 *                                                   Out: Updated number of elements in descr including CSR extensions.
 *  \return        KEYM_ASN1_RC_OK                   The description was initialized successfully.
 *                 KEYM_ASN1_RC_FAILED               Due to internal error, the description could not be initialized.
 *  \pre           All provided pointers must be valid (with the exception of elementIds, this is checked at runtime).
 *                 csrInfo must reference at least numOfReqObjects many elements.
 *                 If elementIds is not a null pointer, the buffer referenced by elementIds must provide at least
 *                 numOfReqObjects many bytes.
 *                 The current number of elements in descr is valid.
 *                 descr must contain at least KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_MAX_SIZE many elements.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoExtensions(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  P2CONST(KeyM_CertElementIdType, AUTOMATIC, KEYM_APPL_DATA) elementIds,
  uint8 numOfReqObjects,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength);

/**********************************************************************************************************************
 * KeyM_Asn1_GetConfSubjectNameInfo()
 *********************************************************************************************************************/
/*! \brief         Retrieve subject name info from configuration.
 *  \details       -
 *  \param[in]     certId                       Holds the identifier of the certificate.
 *  \param[out]    elementStartIdx              Index of first subject name certificate element for a given certificate.
 *  \param[out]    numOfConfSubjectNameObjects  Number of subject name certificate elements for a given certificate.
 *                                              The function guarantees that this statement is true on return:
 *                                              *elementStartIdx + *numOfConfSubjectNameObjects <= KeyM_GetSizeOfCertificateElement()
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_GetConfSubjectNameInfo(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, KEYM_APPL_VAR) elementStartIdx,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, KEYM_APPL_VAR) numOfConfSubjectNameObjects);

/**********************************************************************************************************************
 * KeyM_Asn1_GetConfExtensionsInfo()
 *********************************************************************************************************************/
/*! \brief         Retrieve extensions info from configuration.
 *  \details       -
 *  \param[in]     certId                       Holds the identifier of the certificate.
 *  \param[out]    numOfConfExtensionsObjects   Number of extension certificate elements for a given certificate.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_GetConfExtensionsInfo(
  KeyM_CertificateIdType certId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) numOfConfExtensionsObjects);

/**********************************************************************************************************************
 * KeyM_Asn1_GetInputSubjectNameInfo()
 *********************************************************************************************************************/
/*! \brief         Retrieve subject name info from input data.
 *  \details       -
 *  \param[in]     csrInfo                       Points to an array of request data objects.
 *  \param[in]     numOfReqObjects               Total number of available request data objects.
 *  \param[in,out] elementStartIdx               Index of first subject name certificate element for a given
 *                                               certificate.
 *  \param[in,out] numOfInputSubjectNameObjects  Number of subject name certificate elements for a given certificate.
 *  \pre           All provided pointers must be valid.
 *                 csrInfo must reference at least numOfReqObjects many elements.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_GetInputSubjectNameInfo(
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  uint8 numOfReqObjects,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) elementStartIdx,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) numOfInputSubjectNameObjects);

/**********************************************************************************************************************
 * KeyM_Asn1_GetInputExtensionsInfo()
 *********************************************************************************************************************/
/*! \brief         Retrieve extension info from input data.
 *  \details       -
 *  \param[in]     csrInfo                       Points to an array of request data objects.
 *  \param[in]     numOfReqObjects               Total number of available request data objects.
 *  \param[in,out] elementStartIdx               Index of first extension certificate element for a given
 *                                               certificate.
 *  \param[in,out] numOfInputExtensionObjects    Number of extension certificate elements for a given certificate.
 *  \pre           All provided pointers must be valid.
 *                 csrInfo must reference at least numOfReqObjects many elements.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_GetInputExtensionsInfo(
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  uint8 numOfReqObjects,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) elementStartIdx,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) numOfInputExtensionObjects);

/**********************************************************************************************************************
 * KeyM_Asn1_InitDescrOfCertReqInfoSubject()
 *********************************************************************************************************************/
/*! \brief         Init ASN.1 description for CSR subject.
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     csrInfo                          Points to an array of request data objects
 *  \param[in]     numOfReqObjects                  Total number of available request data objects.
 *  \param[out]    descr                            Description returned by the function.
 *  \param[in,out] descrLength                      In: Max number of elements in descr.
 *                                                  Out: Actual number.
 *  \return        KEYM_ASN1_RC_OK                  Description structure for CSR subject was generated successfully.
 *                 KEYM_ASN1_RC_FAILED              Due to internal error, the description structure for CSR subject
 *                                                  could not be generated.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 csrInfo must reference at least numOfReqObjects many elements.
 *                 descr must contain at least KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_MAX_SIZE
 *                 or (*descrLength + 4*numOfReqObjects + 1) many elements
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoSubject(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  uint8 numOfReqObjects,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength);

/**********************************************************************************************************************
 * KeyM_Asn1_InitDescrOfCertReqInfoEncodePubKeyECC()
 *********************************************************************************************************************/
/*! \brief         Encode ECC public key for CertificationRequestInfo.
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoEncodePubKeyECC(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Asn1_InitDescrOfCertReqInfoEncodePubKeyRSA()
 *********************************************************************************************************************/
/*! \brief         Encode RSA public key for CertificationRequestInfo.
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoEncodePubKeyRSA(void);

/**********************************************************************************************************************
 * KeyM_Asn1_InitDescrOfCertReqInfoECC()
 *********************************************************************************************************************/
/*! \brief         Initialize ASN.1 description for CertificationRequestInfo according to ECC specific
 *                 certificate structure.
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     csrInfo                          Points to an array of request data objects
 *  \param[in]     elementIds                       Points to an array of certificate element Ids of CSR elements.
 *  \param[in]     numOfReqObjects                  Total number of available request data objects.
 *  \param[in]     descr                            Description of CertReqInfo.
 *  \param[in,out] descrLength                      In: Current number of elements in descr.
 *                                                  Out: Actual number.
 *  \return        KEYM_ASN1_RC_OK                  Operation successful.
 *                 KEYM_ASN1_RC_FAILED              Operation failed.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *                 csrInfo must reference at least numOfReqObject many elements.
 *                 The buffer referenced by elementIds must provide at least numOfReqObjects many objects.
 *                 descr must contain at least KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_MAX_SIZE many elements.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoECC(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  P2CONST(KeyM_CertElementIdType, AUTOMATIC, KEYM_APPL_DATA) elementIds,
  uint8 numOfReqObjects,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength);

/**********************************************************************************************************************
 * KeyM_Asn1_AppendToDescr()
 *********************************************************************************************************************/
/*! \brief         Append a new instance of KeyM_Asn1_ElementType to the descr buffer.
 *  \details       -
 *  \param[in]     descr                            Description structure of CertReqInfo.
 *  \param[in,out] descrLength                      In:  Current number of elements in descr.
 *                                                  Out: Updated number.
 *  \param[in]     nestingLevel                     nestingLevel of the appended element in the buffer
 *  \param[in]     elementType                      elementType of the appended element in the buffer
 *  \param[in]     dataPtr                          dataPtr of the appended element in the buffer. May be NULL if
 *                                                  dataLength is also 0.
 *  \param[in]     dataLength                       dataLength of the appended element in the buffer
 *  \pre           descrLength must be a valid, non-NULL pointer to a valid index into descr.data.
 *  \context       TASK
 *  \reentrant     TRUE only for different buffers in descr
 *  \synchronous   TRUE
 *  \spec          requires $lengthOf(dataPtr) >= dataLength;
 *                 requires nestingLevel <= KEYM_ASN1_PARSE_MAX_NESTING_LEVEL;                                 \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_AppendToDescr(
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength,
  uint8 nestingLevel,
  uint8 elementType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) dataPtr,
  uint16 dataLength);

/**********************************************************************************************************************
 * KeyM_Asn1_InitDescrOfCertReqInfoRSA()
 *********************************************************************************************************************/
/*! \brief         Initialize ASN.1 description for CertificationRequestInfo according to RSA specific
 *                 certificate structure.
 *  \details       -
 *  \param[in]     certId                       Holds the identifier of the certificate.
 *  \param[in]     csrInfo                      Points to an array of request data objects
 *  \param[in]     elementIds                   Points to an array of certificate element Ids of CSR elements.
 *  \param[in]     numOfReqObjects              Total number of available request data objects.
 *  \param[in]     descr                        Description of CertReqInfo.
 *  \param[in,out] descrLength                  In: Current number of elements in descr.
 *                                              Out: Actual number.
 *  \return        KEYM_ASN1_RC_OK              Description structure was generated successfully.
 *                 KEYM_ASN1_RC_FAILED          Due to internal error, description structure could not be generated.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *                 csrInfo must reference at least numOfReqObject many elements.
 *                 The buffer referenced by elementIds must provide at least numOfReqObjects many objects.
 *                 descr must contain at least KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_MAX_SIZE many elements.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoRSA(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  P2CONST(KeyM_CertElementIdType, AUTOMATIC, KEYM_APPL_DATA) elementIds,
  uint8 numOfReqObjects,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength);

/**********************************************************************************************************************
 * KeyM_Asn1_HandleCsmResult()
 *********************************************************************************************************************/
/*! \brief         Handles the return value of the CSM job.
 *  \details       -
 *  \param[in]     csmResult                        Holds the result of the CSM job.
 *  \return        KEYM_ASN1_RC_OK                  Operation successful.
 *                 KEYM_ASN1_RC_FAILED              Operation failed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_HandleCsmResult(
  Std_ReturnType csmResult);

/**********************************************************************************************************************
 * KeyM_Asn1_SignatureGenerate()
 *********************************************************************************************************************/
/*! \brief         Generate Signature according to DER encoding rules.
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     certReqInfo                      Holds the CertificationRequestInfo data to be signed
 *  \param[in,out] sig                              Holds the returned signature.
 *  \return        KEYM_ASN1_RC_OK                  Signature was generated and encoded successfully.
 *                 KEYM_ASN1_RC_FAILED              Due to internal error, signature could not be generated or encoded.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_SignatureGenerate(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_Asn1_CsrType, AUTOMATIC, KEYM_APPL_VAR) certReqInfo,
  P2VAR(KeyM_Asn1_SignatureType, AUTOMATIC, KEYM_APPL_VAR) sig);

/**********************************************************************************************************************
 * KeyM_Asn1_BuildCertificationRequest()
 *********************************************************************************************************************/
/*! \brief         Build ASN1 string for CertificationRequest.
 *  \details       -
 *  \param[in]     certId                             Holds the identifier of the certificate.
 *  \param[in]     certReqInfo                        Holds the CertificationRequestInfo data. Must not be NULL.
 *  \param[in]     sig                                Holds the generated signature.
 *  \param[out]    certReq                            Holds the generated CertificationRequest data. Must not be NULL.
 *  \return        KEYM_ASN1_RC_OK                    The CSR was created successfully.
 *                 KEYM_ASN1_RC_FAILED                Due to internal error, the CSR could not be created.
 *                 KEYM_ASN1_RC_LEN_OVERFLOW          Length mismatch.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 The data ptr contained in certReq must be valid and the buffer referenced by certReq->data
 *                 must provide at least KEYM_ASN1_MAX_CSR_SIZE many bytes.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires certReqInfo != NULL_PTR;
 *                 requires sig != NULL_PTR;
 *                 requires certReq != NULL_PTR;                                                               \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_BuildCertificationRequest(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_Asn1_CsrType, AUTOMATIC, KEYM_APPL_VAR) certReqInfo,
  P2CONST(KeyM_Asn1_SignatureType, AUTOMATIC, KEYM_APPL_VAR) sig,
  P2VAR(KeyM_Asn1_CsrType, AUTOMATIC, KEYM_APPL_VAR) certReq);

/**********************************************************************************************************************
 * KeyM_Asn1_InitDescrOfCertReq()
 *********************************************************************************************************************/
/*! \brief         Init ASN.1 description for CertificationRequest.
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     certReqInfo                      Holds the CertificationRequestInfo data
 *  \param[in]     sig                              Holds the generated signature. Must not be NULL.
 *  \param[out]    descr                            Description returned by the function.
 *  \param[in,out] descrLength                      In: Max number of elements in descr.
 *                                                  Out: Actual number.
 *  \return        KEYM_ASN1_RC_OK                  Description was initialized successfully.
 *                 KEYM_ASN1_RC_FAILED              Due to internal error, the description could not be initialized.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *                 descr must contain at least KEYM_ASN1_CSR_CERTIFICATIONREQUEST_DESCR_MAX_SIZE elements.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires sig != NULL_PTR;                                                                   \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReq(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_Asn1_CsrType, AUTOMATIC, KEYM_APPL_DATA) certReqInfo,
  P2CONST(KeyM_Asn1_SignatureType, AUTOMATIC, KEYM_APPL_DATA) sig,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength);

/**********************************************************************************************************************
 * KeyM_Asn1_InsertTagAndLength()
 *********************************************************************************************************************/
/*! \brief         Write an ASN.1 tag and length into the responseData buffer.
 *  \details       Refer to ASN.1 specification for detailed encoding rules.
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     elementType                      Certificate element type.
 *  \param[in]     tagDataLength                    Content length for the given tag.
 *  \param[out]    responseData                     Tag returned by the function. Must not be NULL.
 *  \param[out]    responseDataLength               Number of bytes written to the responseData buffer.
 *  \return        KEYM_ASN1_RC_OK                  The data was written completely to the responseData buffer.
 *                 KEYM_ASN1_RC_LEN_OVERFLOW        The data was not or only partially written to the responseData
 *                                                  buffer because it was too small to hold all of the data.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 The buffer referenced by responseData must provide at least 4 bytes.
 *  \context       TASK
 *  \reentrant     TRUE for different responseData buffers
 *  \synchronous   TRUE
 *  \spec          requires responseData != NULL_PTR;
 *                 requires *responseDataLength <= $lengthOf(responseData);                                    \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_InsertTagAndLength(
  KeyM_CertificateIdType certId,
  uint8 elementType,
  uint16 tagDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) responseDataLength);

/**********************************************************************************************************************
 * KeyM_Asn1_BuildTag()
 *********************************************************************************************************************/
/*! \brief         Build complete ASN.1 tag, length and value for the given element.
 *  \details       Refer to ASN.1 specification for detailed encoding rules.
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     elementType                      Certificate element type.
 *  \param[in]     tagData                          Plain tag value. May be NULL.
 *  \param[in]     tagDataLength                    Length of plain tag value.
 *  \param[out]    responseData                     Tag returned by the function. Must not be NULL.
 *  \param[in,out] responseDataLength               In:  Capacity of the responseData buffer.
 *                                                  Out: Number of bytes written to the responseData buffer.
 *  \return        KEYM_ASN1_RC_OK                  The data was written completely to the responseData buffer.
 *                 KEYM_ASN1_RC_LEN_OVERFLOW        The data was not or only partially written to the responseData
 *                                                  buffer because it was too small to hold all of the data.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 The buffer referenced by responseData must provide at least (tagDataLength + 4) many bytes.
 *  \context       TASK
 *  \reentrant     TRUE for different responseData buffers
 *  \synchronous   TRUE
 *  \spec          requires responseData != NULL_PTR;
 *                 requires *responseDataLength <= $lengthOf(responseData);                                    \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_BuildTag(
  KeyM_CertificateIdType certId,
  uint8 elementType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) tagData,
  uint16 tagDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) responseDataLength);
#endif

#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Asn1_StoreOCSPResponderIdParseInfo()
 *********************************************************************************************************************/
/*! \brief         Store parsing information for ResponderId attributes.
 *  \details       -
 *  \param[in]     asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[in,out] ocspResp                        Holds the parsing information of the OCSP response.
 *  \param[in]     refIdx                          Holds the reference index for the parsing information.
 *  \return        KEYM_ASN1_RC_OK                 The parsing information could be stored successfully.
 *                 KEYM_ASN1_RC_FAILED             Invalid tag identifier.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_StoreOCSPResponderIdParseInfo(
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) refIdx);

/**********************************************************************************************************************
 * KeyM_Asn1_StoreOCSPParseInfo()
 *********************************************************************************************************************/
/*! \brief         Store parsing information for constructed and primitive elements of OCSPResponse structure.
 *  \details       -
 *  \param[in]     asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in]     asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[in,out] ocspResp                        Holds the parsing information of the OCSP response.
 *  \return        KEYM_ASN1_RC_OK                 The parsing information could be stored successfully.
 *                 KEYM_ASN1_RC_FAILED             Invalid tag identifier.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_StoreOCSPParseInfo(
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp);

/**********************************************************************************************************************
 * KeyM_Asn1_CheckParsedOCSPResponderIdTag()
 *********************************************************************************************************************/
/*! \brief         Check tag identifier of parsed ResponderId tag and initiate storage of parsing information.
 *  \details       -
 *  \param[in]     asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[in,out] ocspResp                        Holds the parsing information of the OCSP response.
 *  \param[in,out] refIdx                          Holds the reference index for the parsing information.
 *  \return        KEYM_ASN1_RC_OK                 Valid tag identifier.
 *                 KEYM_ASN1_RC_FAILED             Invalid tag identifier.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckParsedOCSPResponderIdTag(
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) refIdx);

/**********************************************************************************************************************
 * KeyM_Asn1_CheckParsedOCSPTag()
 *********************************************************************************************************************/
/*! \brief         Check tag identifier of parsed tag.
 *  \details       -
 *  \param[in]     asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in]     asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \return        KEYM_ASN1_RC_OK                 Valid tag identifier.
 *                 KEYM_ASN1_RC_FAILED             Invalid tag identifier.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckParsedOCSPTag(
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseOCSPResponderIdPrimitiveTag()
 *********************************************************************************************************************/
/*! \brief         Parse primitive tag of ResponderId structure.
 *  \details       -
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in]     asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[in,out] ocspResp                        Holds the parsing information of the OCSP response.
 *  \param[in,out] refIdx                          Holds the reference index for the parsing information.
 *  \return        KEYM_ASN1_RC_OK                 Primitive tag was parsed successfully.
 *                 KEYM_ASN1_RC_FAILED             Due to an internal error, the primitive tag could not be parsed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPResponderIdPrimitiveTag(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) refIdx);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseOCSPPrimitiveTag()
 *********************************************************************************************************************/
/*! \brief         Parse primitive tag of OCSPResponse structure.
 *  \details       -
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in]     asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[in,out] ocspResp                        Holds the parsing information of the OCSP response.
 *  \return        KEYM_ASN1_RC_OK                 Primitive tag was parsed successfully.
 *                 KEYM_ASN1_RC_FAILED             Due to an internal error, the primitive tag could not be parsed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPPrimitiveTag(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseOCSPConstructedTag()
 *********************************************************************************************************************/
/*! \brief         Parse constructed tag.
 *  \details       -
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[in,out] asn1ParseParamBuffer            Pointer to the ASN descriptor buffer.
 *  \return        KEYM_ASN1_RC_OK                 ASN.1 substructure was derived successfully.
 *                 KEYM_ASN1_RC_FAILED             Due to internal error, the ASN.1 substructure could not be derived.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPConstructedTag(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseOCSPResponderIdElementStructure()
 *********************************************************************************************************************/
/*! \brief         Initiate parsing of primitive or constructed tag of ResponderId structure.
 *  \details       -
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[in,out] asn1ParseParamBuffer            Pointer to the ASN descriptor buffer.
 *  \param[in,out] ocspResp                        Holds the parsing information of the OCSP response.
 *  \param[in,out] refIdx                          Holds the reference index for the parsing information.
 *  \return        KEYM_ASN1_RC_OK                 ASN.1 tag was parsed successfully.
 *                 KEYM_ASN1_RC_FAILED             Due to internal error, the ASN.1 tag could not be parsed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPResponderIdElementStructure(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) refIdx);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseOCSPElementStructure()
 *********************************************************************************************************************/
/*! \brief         Initiate parsing of primitive or constructed tag of OCSPResponse structure.
 *  \details       -
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[in,out] asn1ParseParamBuffer            Pointer to the ASN descriptor buffer.
 *  \param[in,out] ocspResp                        Holds the parsing information of the OCSP response.
 *  \return        KEYM_ASN1_RC_OK                 ASN.1 tag was parsed successfully.
 *                 KEYM_ASN1_RC_FAILED             Due to internal error, the ASN.1 tag could not be parsed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPElementStructure(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp);

/**********************************************************************************************************************
 * KeyM_Asn1_UpdateOCSPAsn1Param()
 *********************************************************************************************************************/
/*! \brief         Update ASN.1 parsing descriptor.
 *  \details       -
 *  \param[in]     asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_UpdateOCSPAsn1Param(
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseOCSPResponderIdElement()
 *********************************************************************************************************************/
/*! \brief         Parse ResponderId structure.
 *  \details       -
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[in,out] asn1ParseParamBuffer            Pointer to the ASN descriptor buffer.
 *  \param[in,out] ocspResp                        Holds the parsing information of the OCSP response.
 *  \param[in,out] refIdx                          Holds the reference index for the parsing information.
 *  \return        KEYM_ASN1_RC_OK                 ResponderId element was parsed successfully.
 *                 KEYM_ASN1_RC_FAILED             Due to internal error, the ResponderId element could not be parsed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPResponderIdElement(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) refIdx);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseOCSPElement()
 *********************************************************************************************************************/
/*! \brief         Parse OCSPResponse structure.
 *  \details       -
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[in,out] asn1ParseParamBuffer            Pointer to the ASN descriptor buffer.
 *  \param[in,out] ocspResp                        Holds the parsing information of the OCSP response.
 *  \return        KEYM_ASN1_RC_OK                 OCSP element was parsed successfully.
 *                 KEYM_ASN1_RC_FAILED             Due to internal error, the OCSP element could not be parsed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPElement(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp);
#endif

/**********************************************************************************************************************
 * KeyM_Asn1_StoreRawDataInfo()
 **********************************************************************************************************************/
/*! \brief         Copy data from current ASN tag position into internal data buffer.
 *  \details       -
 *  \param[in]     asn1ParseParam        Pointer to the ASN.1 data descriptor.
 *  \param[in]     paramDataPtr          Pointer to the ASN.1 element descriptor.
 *  \param[in]     elementIdx            Index of certificate element.
 *  \return        KEYM_ASN1_RC_OK            Element Ref information successfully stored.
 *  \return        KEYM_ASN1_RC_LEN_OVERFLOW  Element Ref information exceeds the bounds of the buffer.
 *  \note          The data content is not null terminated.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE, but not for the same certificate
 *  \synchronous   TRUE
 *  \spec          requires elementIdx < KeyM_GetSizeOfCertificateElement();                                   \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_StoreRawDataInfo(
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr,
  KeyM_SizeOfCertificateElementType elementIdx);

/**********************************************************************************************************************
 * KeyM_Asn1_SetElementRefInfo()
 **********************************************************************************************************************/
/*! \brief         Stores length and offset of a parsed element into the element's Ref Storage.
 *  \details       -
 *  \param[in]     elementIdx                 Index of the CertificateElement in whose Ref Storage the information
 *                                            shall be stored.
 *  \param[in]     elementRefInfo             Information that shall be stored in the Ref Storage.
 *  \param[in]     bufferLength               Total length of the data buffer that is being parsed, i.e., that shall
 *                                            be accessed with the offset and length information from elementRefInfo
 *  \return        KEYM_ASN1_RC_OK            Element Ref information successfully stored.
 *  \return        KEYM_ASN1_RC_LEN_OVERFLOW  Element Ref information exceeds the bounds of the buffer.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, but not for the same certificate element
 *  \synchronous   TRUE
 *  \spec          requires elementIdx < KeyM_GetSizeOfCertificateElement();                                   \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_SetElementRefInfo(
  KeyM_SizeOfCertificateElementType elementIdx,
  KeyM_Ans1_Element_Ref_Type elementRefInfo,
  uint16 bufferLength);

/**********************************************************************************************************************
 * KeyM_Asn1_InitDerived()
 **********************************************************************************************************************/
/*! \brief         Creates a sub structure for an ASN.1 string out of a root structure.
 *  \details       last tag of a root structure points to a constructed type.
 *                 This function initializes the new structure as if it points to an initial string.
 *                 This allows to use it for all further functions of the KEYM_ASN1 scanning process.
 *  \param[out]    deriveParamDataPtr    Configuration structure for initializing the module
 *  \param[in]     rootParamDataPtr      Initialized structure pointing to a currently used constructed KEYM_ASN1 string.
 *  \return        KEYM_ASN1_RC_OK       ASN.1 sub structure was generated successfully.
 *                 KEYM_ASN1_RC_FAILED   ASN.1 root structure already reached its end.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 **********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDerived(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) deriveParamDataPtr,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) rootParamDataPtr);

/**********************************************************************************************************************
 * KeyM_Asn1_GetElementPathByStructureType()
 *********************************************************************************************************************/
/*! \brief         Retrieves element path for referenced certificate structure.
 *  \details       -
 *  \param[in]     certStructure                        Holds the certificate structure type.
 *  \param[out]    certElementPath                      Pointer to a valid buffer which will hold the data returned by the
 *                                                      function.
 *  \param[in,out] certElementPathDataLength            In: Max number of bytes available in CertElementPath.
 *                                                      Out: Actual number.
 *  \return        KEYM_ASN1_RC_OK                      Element path found.
 *                 KEYM_ASN1_RC_PARAMETER_MISMATCH      Invalid cert structure.
 *                 KEYM_ASN1_RC_LEN_OVERFLOW            Provided buffer for the certificate element path too small.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_GetElementPathByStructureType(
  KeyM_CertificateStructureType certStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) certElementPath,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) certElementPathDataLength);

/**********************************************************************************************************************
 * KeyM_Asn1_ConvertToKeyMRetVal()
 *********************************************************************************************************************/
/*! \brief         Maps an Asn1 return value to a KeyM return value.
 *  \details       -
 *  \param[in]     asn1RetVal   The Asn1 return value to map
 *  \return                     The mapped KeyM return value or E_NOT_OK if no more specific KeyM return value exists
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ConvertToKeyMRetVal(
  Std_ReturnType asn1RetVal);

/**********************************************************************************************************************
 * KeyM_Asn1_ConvertToAsn1RetVal()
 *********************************************************************************************************************/
/*! \brief         Maps a KeyM return value to an Asn1 return value.
 *  \details       -
 *  \param[in]     keyMRetVal   The KeyM return value to map
 *  \return                     The mapped Asn1 return value or KEYM_ASN1_RC_FAILED if no more specific KeyM return
 *                              value exists
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ConvertToAsn1RetVal(
  Std_ReturnType keyMRetVal);

/**********************************************************************************************************************
 * KeyM_Asn1_GetOidElementDescr()
 *********************************************************************************************************************/
/*! \brief         Returns pointer to const array for OID element description based on certificate format type.
 *  \details       -
 *  \param[in]     certId       Holds the identifier of the certificate.
 *  \return                     Pointer to const array for OID element description
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(P2CONST(KeyM_Asn1_OidElementDescrType, AUTOMATIC, KEYM_CONST), KEYM_CODE) KeyM_Asn1_GetOidElementDescr(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Asn1_GetSizeOfOidElementDescr()
 *********************************************************************************************************************/
/*! \brief         Returns size of const array for OID element description based on certificate format type.
 *  \details       -
 *  \param[in]     certId       Holds the identifier of the certificate.
 *  \return                     Size of const array for OID element description
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(uint8, KEYM_CODE) KeyM_Asn1_GetSizeOfOidElementDescr(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Asn1_GetSizeOfCertElementDescr()
 *********************************************************************************************************************/
/*! \brief         Returns size of const array for certificate element description based on certificate format type.
 *  \details       -
 *  \param[in]     certId       Holds the identifier of the certificate.
 *  \return                     Size of const array for certificate element description
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(uint8, KEYM_CODE) KeyM_Asn1_GetSizeOfCertElementDescr(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Asn1_GetCertElementDescr()
 *********************************************************************************************************************/
/*! \brief         Returns pointer to const array for certificate element description based on certificate format type.
 *  \details       -
 *  \param[in]     certId       Holds the identifier of the certificate.
 *  \return                     Pointer to const array for certificate element description
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(P2CONST(KeyM_Asn1_CertElementDescrType, AUTOMATIC, KEYM_CONST), KEYM_CODE) KeyM_Asn1_GetCertElementDescr(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ExtractByte()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ExtractByte(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) value)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if there are still bytes in the ASN string */
  if (paramDataPtr->remaining_len == 0u)
  {
    retVal = KEYM_ASN1_RC_FAILED;
  }
  else
  {
    /* # Extract the byte from the current position */
    *value = paramDataPtr->base_data_ptr[paramDataPtr->current_pos];

    (paramDataPtr->current_pos)++;         /* Increment the position index */
    (paramDataPtr->remaining_len)--;       /* Decrement the remaining length */

    paramDataPtr->current_at_initial_pos = FALSE;

    /* All OK */
    retVal = KEYM_ASN1_RC_OK;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseUniversalTag()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseUniversalTag(
  uint8 tagByte,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) objectType,
  P2VAR(boolean, AUTOMATIC, KEYM_APPL_VAR) tag_has_data)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType  retVal;
  uint8 tagNumber = tagByte & KEYM_ASN1_TAG_NUMBER_MASK;

  /* ----- Implementation ----------------------------------------------- */
  /* # Map universal tags to object types and set flag for constructed and primitive tags */
  switch (tagNumber)
  {
    /* types that are known to be primitive */
    case KEYM_ASN1_TYPE_UTC_GENERALIZED_TIME:
      /* treat UTC_GENERALIZED_TIME like UTC_TIME */
      tagNumber = KEYM_ASN1_TYPE_UTC_TIME;
      /* fall through */ /* PRQA S 2003 1 */ /* MD_KEYM_16.3_Fallthrough */
    case KEYM_ASN1_TYPE_INTEGER:
    case KEYM_ASN1_TYPE_BOOLEAN:
    case KEYM_ASN1_TYPE_BIT_STRING:
    case KEYM_ASN1_TYPE_OCTET_STRING:
    case KEYM_ASN1_TYPE_NULL:
    case KEYM_ASN1_TYPE_OBJECTID:
    case KEYM_ASN1_TYPE_ENUMERATED:
    case KEYM_ASN1_TYPE_UTF8:
    case KEYM_ASN1_TYPE_PRINTABLE_STRING:
    case KEYM_ASN1_TYPE_IA5_STRING:
    case KEYM_ASN1_TYPE_BMPSTRING:
    case KEYM_ASN1_TYPE_UTC_TIME:
      (*objectType) = tagNumber;
      (*tag_has_data) = TRUE;
      retVal = KEYM_ASN1_RC_OK;
      break;

    /* types that are known to be constructed */
    case KEYM_ASN1_TYPE_SEQUENCE:
    case KEYM_ASN1_TYPE_SET:
      (*objectType) = tagNumber;
      (*tag_has_data) = FALSE;
      retVal = KEYM_ASN1_RC_OK;
      break;

      /* unsupported tag */
    default:
      retVal = KEYM_ASN1_RC_UNSUPPORTED_TAG;
      break;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseApplicationTag()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseApplicationTag(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr,
  uint8 tagByte,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) objectType)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check encoding length of tag identifier */
  if ((tagByte & KEYM_ASN1_TAG_LENGTH) == KEYM_ASN1_TAG_LENGTH)
  {
    /* Tag is encoded in two octets */
    uint8 currentByte = tagByte;
    uint16 tagValue = currentByte;

    /* Extract second octet */
    retVal = KeyM_Asn1_ExtractByte(paramDataPtr, &currentByte);
    tagValue = (tagValue << 8u) | currentByte;

    /* # Map CVC tags to universal object types */
    switch (tagValue)
    {
      case KEYM_ASN1_CVC_TAG_CV_CERTIFICATE:
        (*objectType) = KEYM_ASN1_TYPE_SEQUENCE;
        break;
      case KEYM_ASN1_CVC_TAG_CERTIFICATE_BODY:
        (*objectType) = KEYM_ASN1_TYPE_SEQUENCE;
        break;
      case KEYM_ASN1_CVC_TAG_CERTIFICATE_PROFILE_IDENTIFIER:
        (*objectType) = KEYM_ASN1_TYPE_INTEGER;
        break;
      case KEYM_ASN1_CVC_TAG_PUBLIC_KEY:
        (*objectType) = KEYM_ASN1_TYPE_SEQUENCE;
        break;
      case KEYM_ASN1_CVC_TAG_CERTIFICATE_HOLDER_REFERENCE:
        (*objectType) = KEYM_ASN1_TYPE_UTF8;
        break;
      case KEYM_ASN1_CVC_TAG_CERTIFICATE_HOLDER_AUTHORIZATION_TEMPLATE:
        (*objectType) = KEYM_ASN1_TYPE_SEQUENCE;
        break;
      case KEYM_ASN1_CVC_TAG_CERTIFICATE_EFFECTIVE_DATE:
        (*objectType) = KEYM_ASN1_TYPE_UTC_TIME;
        break;
      case KEYM_ASN1_CVC_TAG_CERTIFICATE_EXPIRATION_DATE:
        (*objectType) = KEYM_ASN1_TYPE_UTC_TIME;
        break;
      case KEYM_ASN1_CVC_TAG_SIGNATURE:
        (*objectType) = KEYM_ASN1_TYPE_OCTET_STRING;
        break;
      default:
        /* Unsupported TAG */
        retVal = KEYM_ASN1_RC_UNSUPPORTED_TAG;
        break;
    }
  }
  else
  {
    /* Tag is encoded in one octet */
    switch (tagByte)
    {
      case KEYM_ASN1_CVC_TAG_CERTIFICATION_AUTHORITY_REFERENCE:
        (*objectType) = KEYM_ASN1_TYPE_UTF8;
        break;
      case KEYM_ASN1_CVC_TAG_DISCRETIONARY_DATA:
        (*objectType) = KEYM_ASN1_TYPE_OCTET_STRING;
        break;
      case KEYM_ASN1_CVC_TAG_AUTHENTICATION:
        (*objectType) = KEYM_ASN1_TYPE_SEQUENCE;
        break;
      case KEYM_ASN1_CVC_TAG_CERTIFICATE_EXTENSIONS:
        (*objectType) = KEYM_ASN1_TYPE_SEQUENCE;
        break;
      default:
        /* Unsupported TAG */
        retVal = KEYM_ASN1_RC_UNSUPPORTED_TAG;
        break;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_GetTagByte()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_GetTagByte(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) objectType,
  P2VAR(boolean, AUTOMATIC, KEYM_APPL_VAR) tag_has_data)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 byteValue;
  Std_ReturnType retVal;

  /* # Extract first octet */
  retVal = KeyM_Asn1_ExtractByte(paramDataPtr, &byteValue);

  /* ----- Implementation ----------------------------------------------- */
  if (retVal == KEYM_ASN1_RC_OK)
  {
    uint8 class = byteValue & KEYM_ASN1_CLASS_MASK;

    (*tag_has_data) = ((byteValue & KEYM_ASN1_TAG_CONSTRUCTED) != KEYM_ASN1_TAG_CONSTRUCTED);

    switch (class)
    {
      case KEYM_ASN1_CLASS_UNIVERSAL:
        retVal = KeyM_Asn1_ParseUniversalTag(byteValue, objectType, tag_has_data);
        break;
      case KEYM_ASN1_CLASS_APPLICATION:
        retVal = KeyM_Asn1_ParseApplicationTag(paramDataPtr, byteValue, objectType);
        break;
      case KEYM_ASN1_CLASS_CONTEXT_SPECIFIC:
        (*objectType) = byteValue;
        break;
      case KEYM_ASN1_CLASS_PRIVATE:
        (*objectType) = KEYM_ASN1_TYPE_USER_PRIVATE;
        /* This ASN.1 class type is not supported */
        retVal = KEYM_ASN1_RC_FAILED;
        break;
      default: /* COV_KEYM_MISRA */
        /* Not reachable; this default case is for MISRA compliance only */
        retVal = KEYM_ASN1_RC_FAILED;
        break;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_GetLength()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_GetLength(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) tag_len)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 op_byte;
  uint8 i;
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Read one byte from ASN string */
  retVal = KeyM_Asn1_ExtractByte(paramDataPtr, &op_byte);
  if (retVal == KEYM_ASN1_RC_OK)
  {
    /* # If length is < 0x80, the byte contains the length */
    if (op_byte < 0x80u)
    {
      (*tag_len) = (uint16)op_byte;
    }
    else
    {
      /* # If >= 0x80, it contains number of length bytes */
      i = op_byte & 0x7Fu;

      /* uint16 is the limited length for ASN in this implementation (0x81-0x82) */
      if (i > sizeof(uint16))
      {
        retVal = KEYM_ASN1_RC_FAILED;
      }
      else
      {
        (*tag_len) = 0u;

        for (; (i > 0u) && (retVal == KEYM_ASN1_RC_OK); --i)
        {
          retVal = KeyM_Asn1_ExtractByte(paramDataPtr, &op_byte);  /* Get the byte from ASN string */
          (*tag_len) <<= 8u;                                       /* Concatenate with previous value */
          (*tag_len) |= (uint16)op_byte;
        }
      }
    }

    /* # Check for illegal value */
    if (retVal == KEYM_ASN1_RC_OK)
    {
      if ((*tag_len) > (paramDataPtr->remaining_len))
      {
        retVal = KEYM_ASN1_RC_LEN_OVERFLOW;
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_UpdateOCSPNestingDepth()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_UpdateOCSPNestingDepth(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Reverse to last unparsed nesting level */
  while ((asn1ParseParam->asn1_nestingLevel > 0u) && (asn1Param->remaining_len == 0u))
  {
    asn1ParseParam->asn1_nestingLevel--;
    *asn1Param = asn1ParseParam->asn1_parseParamDerivedBuffers[(asn1ParseParam->asn1_nestingLevel)];
    KeyM_Asn1_NextTag(asn1Param);
  }
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */
#endif

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_UpdateNestingDepth()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_UpdateNestingDepth(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param)
{
  P2CONST(KeyM_Asn1_OidElementDescrType, AUTOMATIC, KEYM_CONST) oidDescriptor;
  P2CONST(KeyM_Asn1_CertElementDescrType, AUTOMATIC, KEYM_CONST) certDescriptor;

  /* ----- Implementation ----------------------------------------------- */
  /* # Reverse to last unparsed nesting level */
  while ((asn1ParseParam->asn1_nestingLevel > 0u) && (asn1Param->remaining_len == 0u))
  {
    asn1ParseParam->elementPath[asn1ParseParam->asn1_nestingLevel] = 0u;
    asn1ParseParam->asn1_nestingLevel--;
    *asn1Param = asn1ParseParam->asn1_parseParamDerivedBuffers[(asn1ParseParam->asn1_nestingLevel)];
    KeyM_Asn1_NextTag(asn1Param);

    oidDescriptor=&KeyM_Asn1_GetOidElementDescr(certId)[asn1ParseParam->refIdx];

    /* Check if increment of reference index is in bounds */
    if ((asn1ParseParam->refIdx <= (KeyM_Asn1_GetSizeOfOidElementDescr(certId) - 2u))
        && ((((   (asn1ParseParam->asn1_nestingLevel == oidDescriptor->elementNestingLevel) && (!oidDescriptor->isIterative))
              ||  ((asn1ParseParam->asn1_nestingLevel < oidDescriptor->elementNestingLevel) && (oidDescriptor->isIterative)))
            && (asn1ParseParam->isOidAvailable))
          ||  ((  (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_X509)
              &&  (oidDescriptor->structureType == KEYM_CERTIFICATE_EXTENSION)
              &&  (asn1ParseParam->asn1_nestingLevel == KeyM_Asn1_OidElementDescr_X509[asn1ParseParam->refIdx + 1u].elementNestingLevel))
            || (  (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CRL)
              &&  (oidDescriptor->structureType == KEYM_CERTIFICATE_EXTENSION)
              &&  (asn1ParseParam->asn1_nestingLevel == KeyM_Asn1_OidElementDescr_CRL[asn1ParseParam->refIdx + 1u].elementNestingLevel)))))
    {
      /* After all subelements of constructed OID element are parsed, move to next OID element in reference table */
      asn1ParseParam->refIdx++;
      asn1ParseParam->isOidAvailable = FALSE;
    }
  }

  oidDescriptor = &KeyM_Asn1_GetOidElementDescr(certId)[asn1ParseParam->refIdx];

  /* Check if oid element was entered.
   * In case of ECDSA, two OIDs (algorithm identified and curve identifier) need to be parsed.
   * The isOidAvailable flag needs to be reset in order for the second OID to be parsed. */
  if (((asn1ParseParam->asn1_nestingLevel == oidDescriptor->elementNestingLevel)
        && (asn1ParseParam->isOidAvailable))
      || ((KeyM_Asn1_OidElementDescr_X509[asn1ParseParam->refIdx].structureType == KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM)
        && (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_X509)
        && (KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_ECDSA)))
  {
    /* Reset flag when constructed OID element is entered initially */
    asn1ParseParam->isOidAvailable = FALSE;
  }

  certDescriptor = &KeyM_Asn1_GetCertElementDescr(certId)[asn1ParseParam->structureTypeIdx];
  /* Check if element is parsed */
  if ((asn1ParseParam->refIdx <= (KeyM_Asn1_GetSizeOfCertElementDescr(certId) - 2u))
      && (((asn1ParseParam->asn1_nestingLevel <= certDescriptor->constructedElementNestingLevel)
          || ((KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_X509) && (certDescriptor->structureType == KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE))
          || ((KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CVC) && (certDescriptor->structureType == KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM)))
          && (asn1ParseParam->asn1_nestingLevel != 0u)))
  {
    /* Increment structure type index after certificate element is parsed */
    asn1ParseParam->structureTypeIdx++;
    asn1ParseParam->isOidAvailable = FALSE;
  }
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_HandleUnsupportedTag()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_HandleUnsupportedTag(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get tag length */
  retVal = KeyM_Asn1_GetLength(asn1Param, &(asn1Param->last_tag_len));

  if (retVal == KEYM_ASN1_RC_OK)
  {
    asn1Param->last_tag_data_pos = asn1Param->current_pos;
    asn1Param->last_tag_valid = TRUE;

    /* # Skip tag value and increment element index */
    KeyM_Asn1_NextTag(asn1Param);
    asn1ParseParam->isTagSkipped = TRUE;
    asn1ParseParam->unsupportedTagCount++;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseTL()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseTL(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get TL information from the current tag */
  retVal = KeyM_Asn1_GetTL(asn1Param);

  if ((retVal == KEYM_ASN1_RC_UNSUPPORTED_TAG) && (KeyM_IsCertAllowUnconfiguredElementsOfCertificate((KeyM_CertificateIterType)certId)))
  {
    /* # Handle unsupported tag */
    retVal = KeyM_Asn1_HandleUnsupportedTag(asn1ParseParam, asn1Param);
  }

  /* # Update certificate element path */
  if (retVal == KEYM_ASN1_RC_OK)
  {
    asn1ParseParam->elementPath[asn1ParseParam->asn1_nestingLevel]++;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_SkipLeadingOctet()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_SkipLeadingOctet(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param)
{
  /* ----- Implementation ----------------------------------------------- */
  if ((asn1Param->remaining_len > 0u) && (asn1Param->last_tag_len > 0u)) /* This check is due to defensive-programming, to ensure underflow protection */
  {
    (asn1Param->last_tag_data_pos)++;  /* Increment the position index */
    (asn1Param->current_pos)++;
    (asn1Param->last_tag_len)--;       /* Decrement the remaining length */
    (asn1Param->remaining_len)--;
    asn1Param->current_at_initial_pos = FALSE;
  }
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_UpdateAsn1Param()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_UpdateAsn1Param(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_Asn1_ParamType localAsn1Param;
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Handle tag type for octet string */
  if (asn1Param->last_tag == KEYM_ASN1_TYPE_OCTET_STRING)
  {
    retVal = KeyM_Asn1_InitDerived(&localAsn1Param, asn1Param);

    if (retVal == KEYM_ASN1_RC_OK)
    {
      /* Update working ASN.1 structure */
      localAsn1Param.root_tag_base_pos = asn1Param->root_tag_base_pos + asn1Param->current_pos;

      /* Get TL information from the current tag */
      retVal = KeyM_Asn1_GetTL(&localAsn1Param);

      if ((retVal == E_OK) && (localAsn1Param.last_tag_len == (asn1Param->last_tag_len - localAsn1Param.current_pos)))
      {
        asn1Param->last_tag_has_data = FALSE;
      }
    }
  }

  /* # Handle tag type for CRL */
  if ((KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CRL) && ((asn1Param->last_tag) == KEYM_ASN1_TYPE_SEQUENCE) && (KeyM_Asn1_CertElementDescr_CRL[asn1ParseParam->structureTypeIdx].structureType == KEYM_CERTIFICATE_REVOCATION_LIST) && (asn1Param->last_tag_base_pos == 0u))
  {
    asn1Param->last_tag_has_data = TRUE;
  }

  /* # Skip present leading octet */
  /* Handle constructed bit string */
  if (((asn1Param->last_tag) == KEYM_ASN1_TYPE_BIT_STRING) &&
    ((((KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_X509) && (
      ((KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_ECDSA) && (KeyM_Asn1_CertElementDescr_X509[asn1ParseParam->structureTypeIdx].structureType == KEYM_CERTIFICATE_SIGNATURE)) ||
      (((KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_RSA) && (KeyM_Asn1_CertElementDescr_X509[asn1ParseParam->structureTypeIdx].structureType == KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY))))))
      || (((KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CRL)
      && (((KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_ECDSA) && (KeyM_Asn1_CertElementDescr_CRL[asn1ParseParam->structureTypeIdx].structureType == KEYM_CERTIFICATE_SIGNATURE)))
      ))
      ))
  {
    asn1Param->last_tag_has_data = FALSE;
    /* Skip leading octet containing the count of added padding bits for constructed bit string tag */
    KeyM_Asn1_SkipLeadingOctet(asn1Param);
  }

  /* Handle primitive bit string */
  if (((asn1Param->last_tag) == KEYM_ASN1_TYPE_BIT_STRING) &&
    ((KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_EDDSA) || (KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_RSA)) &&
      (((KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_X509)
      && (KeyM_Asn1_CertElementDescr_X509[asn1ParseParam->structureTypeIdx].structureType == KEYM_CERTIFICATE_SIGNATURE))
      || ((KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CRL)
      && (KeyM_Asn1_CertElementDescr_CRL[asn1ParseParam->structureTypeIdx].structureType == KEYM_CERTIFICATE_SIGNATURE))
      ))
  {
    /* Skip leading octet containing the count of added padding bits for constructed bit string tag */
    KeyM_Asn1_SkipLeadingOctet(asn1Param);
  }
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseConstructedTag()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseConstructedTag(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_FAILED;

  /* ----- Implementation ----------------------------------------------- */
  /* Check nesting level */
  if (asn1ParseParam->asn1_nestingLevel < asn1ParseParam->noOfParseParamDerivedBufferElements)
  {
    /* Get Root element for signature calculation */
    if ((asn1ParseParam->asn1_nestingLevel) == (KEYM_ASN1_ROOT_NESTING_LEVEL - 1u))
    {
      if (asn1ParseParam->asn1_baseAddress == NULL_PTR)
      {
        asn1ParseParam->asn1_baseAddress = asn1Param->base_data_ptr;
        asn1ParseParam->asn1_baseLength = asn1Param->last_tag_len + asn1Param->current_pos;
      }
    }

    /* # Creates sub structure for an ASN.1 string out of a root structure. */
    asn1ParseParam->asn1_parseParamDerivedBuffers[asn1ParseParam->asn1_nestingLevel] = *asn1Param;
    retVal = KeyM_Asn1_InitDerived(asn1ParseParamBuffer, asn1Param);

    if ((retVal == KEYM_ASN1_RC_OK)
     && ((asn1ParseParam->asn1_nestingLevel + 1u) < KEYM_ASN1_PARSE_MAX_NESTING_LEVEL)) /* check that asn1ParseParam->asn1_nestingLevel++; will still yield a valid value */
    {
      /* # Update working ASN.1 structure */
      asn1ParseParamBuffer->root_tag_base_pos = asn1Param->root_tag_base_pos + asn1Param->current_pos;
      *asn1Param = *asn1ParseParamBuffer;

      asn1ParseParam->asn1_nestingLevel++;
    }
    else
    {
      retVal = KEYM_ASN1_RC_FAILED;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#if (KEYM_CERTELEMENTPATHUSEDOFCERTIFICATEELEMENT == STD_ON)
# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_GetNestingLevelOfCertElement()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6080 4 */ /* MD_MSR_STMIF */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Asn1_GetNestingLevelOfCertElement(
  KeyM_CertificateIdType certId,
  KeyM_OfStructureOfCertificateElementType elementStructureType,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) nestingLevel)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean found = FALSE;
  P2CONST(KeyM_Asn1_CertElementDescrType, AUTOMATIC, KEYM_APPL_DATA) certElementDescrPtr = NULL_PTR;
  uint8 certElementDescrLength = 0u;
  uint8_least i;
  boolean isValidCertFormatType = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  switch (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId))
  {
    case KEYM_X509:
    {
      certElementDescrPtr = KeyM_Asn1_CertElementDescr_X509;
      certElementDescrLength = KEYM_ASN1_SIZE_OF_X509_CERTELEMENTNESTINGLEVEL;
      isValidCertFormatType = TRUE;
      break;
    }
    case KEYM_CRL:
    {
      certElementDescrPtr = KeyM_Asn1_CertElementDescr_CRL;
      certElementDescrLength = KEYM_ASN1_SIZE_OF_CRL_CERTELEMENTNESTINGLEVEL;
      isValidCertFormatType = TRUE;
      break;
    }
    case KEYM_CVC:
    {
      certElementDescrPtr = KeyM_Asn1_CertElementDescr_CVC;
      certElementDescrLength = KEYM_ASN1_SIZE_OF_CVC_CERTELEMENTNESTINGLEVEL;
      isValidCertFormatType = TRUE;
      break;
    }
    default:
    {
      /* Do nothing */
      break;
    }
  }

  /* # Retrieve nesting level from certificate element description */
  if (isValidCertFormatType)
  {
    for (i = 0; i < certElementDescrLength; i++)
    {
      if (certElementDescrPtr[i].structureType == elementStructureType)
      {
        *nestingLevel = certElementDescrPtr[i].elementNestingLevel;
        found = TRUE;
        break;
      }
    }
  }

  return found;
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */
#endif

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_CheckParsedTag()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6050 1 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckParsedTag(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check certificate element path */
# if (KEYM_CERTELEMENTPATHUSEDOFCERTIFICATEELEMENT == STD_ON)
  if (KeyM_IsCertElementPathUsedOfCertificateElement(asn1ParseParam->currentElementIdx)) /* PRQA S 2995 */ /* MD_KEYM_2.2 */
  {
    retVal = KeyM_Asn1_CheckCertElementPath(certId, asn1ParseParam); /* VCA_KEYM_FUNCTION_REQUIREMENT_CHECKED */
  }
# endif

  /* # Check certificate element object identifier */
# if (KEYM_CERTELEMENTPATHUSEDOFCERTIFICATEELEMENT == STD_ON)
  if (KeyM_IsElementOidUsedOfCertificateElement(asn1ParseParam->currentElementIdx) && (retVal == KEYM_ASN1_RC_OK)) /* PRQA S 2995 */ /* MD_KEYM_2.2 */
# else
  if (KeyM_IsElementOidUsedOfCertificateElement(asn1ParseParam->currentElementIdx)) /* PRQA S 2995 */ /* MD_KEYM_2.2 */
# endif
  {
    retVal = KeyM_Asn1_CheckCertElementOid(asn1ParseParam); /* VCA_KEYM_FUNCTION_REQUIREMENT_CHECKED */
  }

  /* # Check certificate element structure type */
  if (retVal == KEYM_ASN1_RC_OK)
  {
    retVal = KeyM_Asn1_CheckCertStructureType(certId, asn1ParseParam);
  }

  /* # Check certificate element tag identifier */
  if ((((KeyM_GetObjectTypeOfCertificateElement(asn1ParseParam->currentElementIdx) == (asn1Param->last_tag))
      || ((KeyM_GetObjectTypeOfCertificateElement(asn1ParseParam->currentElementIdx) == KEYM_ASN1_TYPE_UTC_GENERALIZED_TIME) && ((asn1Param->last_tag) == KEYM_ASN1_TYPE_UTC_TIME))
      ) && (retVal == KEYM_ASN1_RC_OK)))
  {
    retVal = KEYM_ASN1_RC_OK;

    /* Check for CVC iterable element */
    if (KeyM_IsHasIterationOfCertificateElement(asn1ParseParam->currentElementIdx)
        || (((asn1Param->last_tag & KEYM_ASN1_TYPE_USER_CONTEXT) == KEYM_ASN1_TYPE_USER_CONTEXT)
        && (((asn1Param->last_tag) == KEYM_ASN1_CVC_PUBKEY_SEVERAL_ELEMENTS) || ((asn1Param->last_tag) == KEYM_ASN1_CVC_PUBKEY_ONLY_PUBLIC_POINT))
        && (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CVC)))
    {
      if ((!asn1ParseParam->isIterableElementIdx))
      {
        asn1ParseParam->isIterableElementIdx = TRUE;
        asn1ParseParam->iterableElementIdx = asn1ParseParam->asn1_element_idx;
      }
      else
      {
        retVal = KEYM_ASN1_RC_PARSE_CHECK_NEXT;
      }
    }
  }
  else if (((asn1Param->last_tag & KEYM_ASN1_TYPE_USER_CONTEXT) == KEYM_ASN1_TYPE_USER_CONTEXT)
           && ((asn1Param->last_tag) != KEYM_ASN1_CVC_PUBKEY_SEVERAL_ELEMENTS)
           && (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CVC)
           && (asn1ParseParam->iterableElementIdx == asn1ParseParam->asn1_element_idx)
           && (asn1ParseParam->isIterableElementIdx))
  {
    KeyM_Ans1_Element_Ref_Type elementInfo;
    elementInfo = KeyM_GetElementStorageRef(asn1ParseParam->currentElementIdx);
    /* Sum up element length for CVC iterable element */
    elementInfo.length += asn1Param->last_tag_len + 2u;
    retVal = KeyM_Asn1_SetElementRefInfo(asn1ParseParam->currentElementIdx, elementInfo, asn1ParseParam->totalDataLength);
    if (retVal == KEYM_ASN1_RC_OK)
    {
      retVal = KEYM_ASN1_RC_PARSE_CHECK_NEXT;
    }
  }
  else if ((KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CRL)
           && (KeyM_Asn1_CertElementDescr_CRL[asn1ParseParam->structureTypeIdx].structureType == KEYM_CERTIFICATE_REVOCATION_LIST)
           && (asn1ParseParam->isIterableElementIdx))
  {
    retVal = KEYM_ASN1_RC_PARSE_CHECK_NEXT;
  }
  else if (asn1Param->last_tag == KEYM_ASN1_TYPE_NULL)
  {
    retVal = KEYM_ASN1_RC_PARSE_CHECK_NEXT;
  }
  else
  {
    retVal = KEYM_ASN1_RC_FAILED;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParsePrimitiveTag()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6030 4 */ /* MD_MSR_STCYC */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParsePrimitiveTag(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_FAILED;

  /* ----- Implementation ----------------------------------------------- */
  /* # Set reference object identifier for certificate element if the current element is an OID. */
  if ((asn1Param->last_tag == KEYM_ASN1_TYPE_OBJECTID)
        && (!(asn1ParseParam->isOidAvailable)
          && (asn1ParseParam->asn1_nestingLevel == KeyM_Asn1_GetOidElementDescr(certId)[asn1ParseParam->refIdx].oidNestingLevel)))
  {
    asn1ParseParam->refOidDataPtr = &asn1Param->base_data_ptr[asn1Param->last_tag_data_pos];
    asn1ParseParam->refOidDataLength = asn1Param->last_tag_len;
    asn1ParseParam->isOidAvailable = TRUE;
  }

  /*@ assert asn1ParseParam->noOfElementList <= KEYM_MAX_NUM_CERT_ELEMENTS; */
  /* Iterate through configured certificate elements */
  for (asn1ParseParam->asn1_element_idx = 0u; asn1ParseParam->asn1_element_idx < asn1ParseParam->noOfElementList; asn1ParseParam->asn1_element_idx++)
  {
    /*@ assert asn1ParseParam->asn1_element_idx < KEYM_MAX_NUM_CERT_ELEMENTS; */ /* VCA_KEYM_ASN1_ASN1PARAM_ASN1ELEMENTIDX */
    asn1ParseParam->currentElementIdx = asn1ParseParam->elementList + asn1ParseParam->asn1_element_idx;
    /*@ assert asn1ParseParam->currentElementIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_ASN1_ASN1PARAM_CURRENTELEMENTIDX */

    /* Check if element is already parsed */
    if ((asn1ParseParam->parsedElements[asn1ParseParam->asn1_element_idx] == TRUE))
    {
      if ((asn1ParseParam->isIterableElementIdx) && (asn1ParseParam->iterableElementIdx == asn1ParseParam->asn1_element_idx))
      {
        /* Try to check parsed tag */
      }
      else
      {
        /* check next element */
        continue;
      }
    }

    /* Check parsed tag against configuration */
    retVal = KeyM_Asn1_CheckParsedTag(certId, asn1ParseParam, asn1Param);

    if ((retVal == KEYM_ASN1_RC_OK) || (retVal == KEYM_ASN1_RC_PARSE_CHECK_NEXT))
    {
      if ((!KeyM_IsHasIterationOfCertificateElement(asn1ParseParam->currentElementIdx)
          && (asn1ParseParam->isIterableElementIdx) && ((KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_X509) || (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CRL)))
          || (((asn1Param->last_tag & KEYM_ASN1_TYPE_USER_CONTEXT) != KEYM_ASN1_TYPE_USER_CONTEXT) && (asn1ParseParam->isIterableElementIdx) && (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CVC)))
      {
        asn1ParseParam->isIterableElementIdx = FALSE;
      }

      break;
    }
  }

  if ((retVal == KEYM_ASN1_RC_FAILED) && (KeyM_IsCertAllowUnconfiguredElementsOfCertificate((KeyM_CertificateIterType)certId)))
  {
    /* # Handle unconfigured certificate element */
    retVal = KEYM_ASN1_RC_OK;
    asn1ParseParam->isElementParsed = TRUE;
  }
  else if (retVal == KEYM_ASN1_RC_OK)
  {
    /*@ assert asn1ParseParam->currentElementIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_ASN1_PARSEPRIMITIVETAG_LOOPRETVAL_OK */
    /*@ assert asn1ParseParam->asn1_element_idx < KEYM_MAX_NUM_CERT_ELEMENTS; */ /* VCA_KEYM_ASN1_PARSEPRIMITIVETAG_LOOPRETVAL_OK */

    /* # Store offset and length of parsed elements */
    retVal = KeyM_Asn1_StoreRawDataInfo(asn1ParseParam, asn1Param, asn1ParseParam->currentElementIdx);

    if (retVal == KEYM_ASN1_RC_OK)
    {
      /* Configured certificate element successfully parsed */
      asn1ParseParam->isElementParsed = TRUE;
      asn1ParseParam->parsedElementsCount++;
      asn1ParseParam->parsedElements[asn1ParseParam->asn1_element_idx] = TRUE;
    }
  }
  else
  {
    /* Do nothing */
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseElementStructure()
 **********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 *
 *
  */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseElementStructure(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check current tag type */
  if (!(asn1Param->last_tag_has_data))
  {
    /* # Parse constructed tag */
    retVal = KeyM_Asn1_ParseConstructedTag(asn1ParseParam, asn1Param, asn1ParseParamBuffer);
  }
  else
  {
    /* # Parse primitive tag */
    retVal = KeyM_Asn1_ParsePrimitiveTag(certId, asn1ParseParam, asn1Param); /* VCA_KEYM_CALLEE_REQUIREMENTS_IDENTICAL_TO_CALLER */
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseElement()
 **********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 *
 *
  */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseElement(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Parse tag header including tag identifier and tag length */
  retVal = KeyM_Asn1_ParseTL(certId, asn1ParseParam, asn1Param);

  /* Parsing successful */
  if (!(asn1ParseParam->isTagSkipped) && (retVal == KEYM_ASN1_RC_OK))
  {
    /* Check if an optional element is not available */
    if (((asn1ParseParam->refIdx <= (KeyM_Asn1_GetSizeOfCertElementDescr(certId) - 2u))
        && (((KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_X509)
              &&((asn1ParseParam->asn1_nestingLevel == KeyM_Asn1_CertElementDescr_X509[asn1ParseParam->structureTypeIdx].constructedElementNestingLevel)
              && ((KeyM_Asn1_CertElementDescr_X509[asn1ParseParam->structureTypeIdx].structureType == KEYM_CERTIFICATE_VERSION_NUMBER) || (KeyM_Asn1_CertElementDescr_X509[asn1ParseParam->structureTypeIdx].structureType == KEYM_CERTIFICATE_EXTENSION))
              && ((asn1Param->last_tag & KEYM_ASN1_TYPE_USER_CONTEXT) != KEYM_ASN1_TYPE_USER_CONTEXT)))
            || ((KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CRL)
              && (asn1ParseParam->asn1_nestingLevel == KeyM_Asn1_CertElementDescr_CRL[asn1ParseParam->structureTypeIdx].constructedElementNestingLevel)
              && (((KeyM_Asn1_CertElementDescr_CRL[asn1ParseParam->structureTypeIdx].structureType == KEYM_CERTIFICATE_VERSION_NUMBER) && (asn1Param->last_tag != KEYM_ASN1_TYPE_INTEGER))
                  || ((KeyM_Asn1_CertElementDescr_CRL[asn1ParseParam->structureTypeIdx].structureType == KEYM_CERTIFICATE_EXTENSION) && ((asn1Param->last_tag & KEYM_ASN1_TYPE_USER_CONTEXT) != KEYM_ASN1_TYPE_USER_CONTEXT)))))))
    {
      asn1ParseParam->structureTypeIdx++;
    }

    /* # Update ASN.1 parse structure */
    KeyM_Asn1_UpdateAsn1Param(certId, asn1ParseParam, asn1Param);

    /* # Parse current tag */
    retVal = KeyM_Asn1_ParseElementStructure(certId, asn1ParseParam, asn1Param, asn1ParseParamBuffer); /* VCA_KEYM_CALLEE_REQUIREMENTS_IDENTICAL_TO_CALLER */

    if ((retVal == KEYM_ASN1_RC_OK) || (retVal == KEYM_ASN1_RC_PARSE_CHECK_NEXT))
    {
      /* # Update remaining length and current position */
      KeyM_Asn1_NextTag(asn1Param);

      if (retVal == KEYM_ASN1_RC_PARSE_CHECK_NEXT)
      {
        retVal = KEYM_ASN1_RC_OK;
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseOCSPElementPrepare()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_ParseOCSPElementPrepare(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Initialize ASN.1 parse structure  */
  asn1ParseParam->isElementParsed = FALSE;

  /* # Update nesting depth */
  KeyM_Asn1_UpdateOCSPNestingDepth(asn1ParseParam, asn1Param);
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */
#endif

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseElementPrepare()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_ParseElementPrepare(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Initialize ASN.1 parse structure  */
  asn1ParseParam->isElementParsed = FALSE;

  /* # Update nesting depth */
  KeyM_Asn1_UpdateNestingDepth(certId, asn1ParseParam, asn1Param);
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_CheckElementOrder()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckElementOrder(
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) lastPos)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_OK;
  uint16 currentElementOffset;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check validity of two consecutive certificate element offsets */
  currentElementOffset = KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)asn1ParseParam->currentElementIdx).offset;

  if (currentElementOffset < *lastPos)
  {
    retVal = KEYM_ASN1_RC_FAILED;
  }
  else
  {
    *lastPos = currentElementOffset;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_CheckParsedCertElements()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckParsedCertElements(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_OK;
  uint16 numOfNonOptionalUnparsedElements = 0u;

  /* ----- Implementation ----------------------------------------------- */
  if ((asn1ParseParam->parsedElementsCount < asn1ParseParam->noOfElementList)
      || !KeyM_IsCertAllowFlexibleElementOrderOfCertificate((KeyM_CertificateIterType)certId))
  {
    uint16 lastPos = 0;

    /*@ assert asn1ParseParam->noOfElementList <= KEYM_MAX_NUM_CERT_ELEMENTS; */
    /* # Iterate through configured certificate elements */
    for (asn1ParseParam->asn1_element_idx = 0u; asn1ParseParam->asn1_element_idx < asn1ParseParam->noOfElementList; asn1ParseParam->asn1_element_idx++)
    {
      /*@ assert asn1ParseParam->asn1_element_idx < KEYM_MAX_NUM_CERT_ELEMENTS; */ /* VCA_KEYM_ASN1_ASN1PARAM_ASN1ELEMENTIDX */
      asn1ParseParam->currentElementIdx = asn1ParseParam->elementList + asn1ParseParam->asn1_element_idx;
      /*@ assert asn1ParseParam->currentElementIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_ASN1_ASN1PARAM_CURRENTELEMENTIDX */
      if (!KeyM_IsCertAllowFlexibleElementOrderOfCertificate((KeyM_CertificateIterType)certId)
          && (asn1ParseParam->parsedElementsCount > 0u)
          && (asn1ParseParam->parsedElements[asn1ParseParam->asn1_element_idx]))
      {
        /* # Check certificate element order */
        retVal = KeyM_Asn1_CheckElementOrder(asn1ParseParam, &lastPos);
      }
      if ((asn1ParseParam->parsedElements[asn1ParseParam->asn1_element_idx] == FALSE)
          && (!KeyM_IsOptionalOfCertificateElement(asn1ParseParam->currentElementIdx)))
      {
        /* # Count number non-optional unparsed certificate elements */
        numOfNonOptionalUnparsedElements++;
        if (!KeyM_IsCertAllowUnconfiguredElementsOfCertificate((KeyM_CertificateIterType)certId))
        {
          retVal = KEYM_ASN1_RC_FAILED;
        }
      }
      if (retVal != KEYM_ASN1_RC_OK)
      {
        break;
      }
    }
    /* # Throw a parsing error for unparsed non-optional elements */
    if (numOfNonOptionalUnparsedElements > asn1ParseParam->unsupportedTagCount)
    {
      retVal = KEYM_ASN1_RC_FAILED;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseProcessing()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6050, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseProcessing(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_OK;
  KeyM_Asn1_ParamType asn1ParseParamBuffer;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through configured elements */
  while ((asn1ParseParam->parsedElementsCount < asn1ParseParam->noOfElementList)
         && (retVal == KEYM_ASN1_RC_OK))
  {
    KeyM_Asn1_ParseElementPrepare(certId, asn1ParseParam, asn1Param);

    /* # Iterate through constructed tag */
    while ((asn1Param->remaining_len > 0u)
           && ((!(asn1ParseParam->isElementParsed)) || ((asn1Param->last_tag & KEYM_ASN1_TYPE_USER_CONTEXT) == KEYM_ASN1_TYPE_USER_CONTEXT))
           && (retVal == KEYM_ASN1_RC_OK))
    {
      /* # Parse certificate element data */
      retVal = KeyM_Asn1_ParseElement(certId, asn1ParseParam, asn1Param, &asn1ParseParamBuffer); /* VCA_KEYM_CALLEE_REQUIREMENTS_IDENTICAL_TO_CALLER */

      if (asn1ParseParam->isTagSkipped)
      {
        asn1ParseParam->isTagSkipped = FALSE;
        break;
      }
    }
    /* Exit loop at end of certificate data */
    if ((asn1Param->remaining_len == 0u) && (asn1ParseParam->asn1_nestingLevel == 0u))
    {
      break;
    }
  }

  if (retVal == KEYM_ASN1_RC_OK)
  {
    /* # Check for unparsed certificate elements */
    retVal = KeyM_Asn1_CheckParsedCertElements(certId, asn1ParseParam); /* VCA_KEYM_ASN1_PARSEPROCESSING_CHECKPARSEDCERTELEMENTS */
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_CheckCertElementOid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckCertElementOid(
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_FAILED;
  KeyM_SizeOfElementOidType oidStartIdx = KeyM_GetElementOidStartIdxOfCertificateElement(asn1ParseParam->currentElementIdx);
  /*@ assert oidStartIdx < KeyM_GetSizeOfElementOid(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION_WITH_REQUIREMENT */

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if object identifier is available and compare length and data of configured object identifier */
  if ((asn1ParseParam->isOidAvailable) && (KeyM_GetElementOidLengthOfCertificateElement(asn1ParseParam->currentElementIdx) == asn1ParseParam->refOidDataLength))
  {
    if (KeyM_Utils_MemCmp(KeyM_GetAddrElementOid(oidStartIdx), asn1ParseParam->refOidDataPtr, KeyM_GetElementOidLengthOfCertificateElement(asn1ParseParam->currentElementIdx)))
    {
      retVal = KEYM_ASN1_RC_OK;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_CheckCertStructureType()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckCertStructureType(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_FAILED;

  /* ----- Implementation ----------------------------------------------- */
  /* # Compare certificate element structure type */
  if (KeyM_GetOfStructureOfCertificateElement(asn1ParseParam->currentElementIdx) == KeyM_Asn1_GetCertElementDescr(certId)[asn1ParseParam->structureTypeIdx].structureType)
  {
    retVal = KEYM_ASN1_RC_OK;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#if (KEYM_CERTELEMENTPATHUSEDOFCERTIFICATEELEMENT == STD_ON)
# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_CheckCertElementPath()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckCertElementPath(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_FAILED;
  uint16 nestingLevel = 0u;
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) elementPath;
  uint16 elementPathLength;
  KeyM_OfStructureOfCertificateElementType structureType;
  KeyM_CertElementPathIterType pathStartIdx;

  /* ----- Implementation ----------------------------------------------- */
  structureType = KeyM_GetOfStructureOfCertificateElement(asn1ParseParam->currentElementIdx);
  elementPathLength = KeyM_GetCertElementPathLengthOfCertificateElement(asn1ParseParam->currentElementIdx);
  pathStartIdx = KeyM_GetCertElementPathStartIdxOfCertificateElement(asn1ParseParam->currentElementIdx);
  /*@ assert pathStartIdx < KeyM_GetSizeOfCertElementPath(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION_WITH_REQUIREMENT */

  if ((structureType == KEYM_CERTIFICATE_EXTENSION) && (elementPathLength > 0u))
  {
    /*@ assert pathStartIdx < (KeyM_GetSizeOfCertElementPath() - 1u); */

    (void)KeyM_Asn1_GetNestingLevelOfCertElement(certId, structureType, &nestingLevel);

    if (KeyM_Asn1_OidElementDescr_X509[asn1ParseParam->refIdx].isIterative)
    {
      /* First element path integer is skipped for iterative elements */
      elementPath = KeyM_GetAddrCertElementPath(pathStartIdx + 1u);
      elementPathLength--;
      nestingLevel++;
    }
    else
    {
      elementPath = KeyM_GetAddrCertElementPath(pathStartIdx);
    }

    /* # Compare certificate element path */
    if (KeyM_Utils_BufferCmp(elementPath, elementPathLength, &asn1ParseParam->elementPath[nestingLevel], (uint32)asn1ParseParam->asn1_nestingLevel - nestingLevel + 1u))
    {
      retVal = KEYM_ASN1_RC_OK;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */
#endif

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_GetTagIdentifier()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 5 */ /* MD_MSR_STCYC */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_GetTagIdentifier(
  KeyM_CertificateIdType certId,
  uint8 elementType,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) identifierData,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) identifierDataLength)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Set ASN1 tag identifier and corresponding identifier length for each element type */
  switch (elementType)
  {
    case KEYM_ASN1_CSR_ELEMENT_VERSION:
    {
      identifierData[0u] = KEYM_ASN1_TYPE_INTEGER;
      *identifierDataLength = 1u;
      break;
    }
    case KEYM_ASN1_CSR_ELEMENT_OID:
    {
      identifierData[0u] = KEYM_ASN1_TYPE_OBJECTID;
      *identifierDataLength = 1u;
      break;
    }
    case KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_STATEORPROVINCENAME:
    case KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_LOCALITYNAME:
    case KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_ORGANIZATIONNAME:
    case KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_ORGANIZATIONUNITNAME:
    case KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_COMMONNAME:
    case KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_UNSTRUCTUREDNAME:
    case KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_CHALLENGEPASSWORD:
    {
      identifierData[0u] = KEYM_ASN1_TYPE_UTF8;
      *identifierDataLength = 1u;
      break;
    }
    case KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_EMAIL:
    {
      identifierData[0u] = KEYM_ASN1_TYPE_IA5_STRING;
      *identifierDataLength = 1u;
      break;
    }
    case KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_COUNTRYNAME:
    {
      identifierData[0u] = KEYM_ASN1_TYPE_PRINTABLE_STRING;
      *identifierDataLength = 1u;
      break;
    }
    case KEYM_ASN1_CSR_ELEMENT_PUB_KEY:
    {
      if (KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) != KEYM_RSA)
      {
        identifierData[0u] = KEYM_ASN1_TYPE_BIT_STRING;
        *identifierDataLength = 1u;
      }
      else
      {
        identifierData[0u] = KEYM_ASN1_TYPE_INTEGER;
        *identifierDataLength = 1u;
      }

      break;
    }
    case KEYM_ASN1_CSR_ELEMENT_SIGNATURE:
    {
      if (KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_ECDSA)
      {
        identifierData[0u] = KEYM_ASN1_TYPE_INTEGER;
      }
      else
      {
        identifierData[0u] = KEYM_ASN1_TYPE_BIT_STRING;
      }

      *identifierDataLength = 1u;

      break;
    }
    case KEYM_ASN1_CSR_ELEMENT_SEQUENCE:
    {
      identifierData[0u] = KEYM_ASN1_TYPE_SEQUENCE | 0x20u;
      *identifierDataLength = 1u;
      break;
    }
    case KEYM_ASN1_CSR_ELEMENT_SET:
    {
      identifierData[0u] = KEYM_ASN1_TYPE_SET | 0x20u;
      *identifierDataLength = 1u;
      break;
    }
    case KEYM_ASN1_CSR_ELEMENT_CONSTRUCTED_BITSTRING:
    {
      identifierData[0u] = KEYM_ASN1_TYPE_BIT_STRING;
      *identifierDataLength = 1u;
      break;
    }
    case KEYM_ASN1_CSR_ELEMENT_CONTEXT_SPECIFIC:
    {
      identifierData[0u] = 0xA0;
      *identifierDataLength = 1u;
      break;
    }
    case KEYM_ASN1_CSR_ELEMENT_NULL:
    {
      identifierData[0u] = KEYM_ASN1_TYPE_NULL;
      *identifierDataLength = 1u;
      break;
    }
    default:
    {
      /* unknown identifier - this should never happen */
      *identifierDataLength = 0u;
      break;
    }
  }
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_Csr_IsElementConstructed()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Asn1_Csr_IsElementConstructed(uint8 elementType)
{
  return (elementType == KEYM_ASN1_CSR_ELEMENT_SEQUENCE) ||
         (elementType == KEYM_ASN1_CSR_ELEMENT_SET) ||
         (elementType == KEYM_ASN1_CSR_ELEMENT_CONTEXT_SPECIFIC) ||
         (elementType == KEYM_ASN1_CSR_ELEMENT_CONSTRUCTED_BITSTRING);
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InitCSRInfo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6060 7 */ /* MD_KEYM_6060_LOCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitCSRInfo(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  P2CONST(KeyM_CertElementIdType, AUTOMATIC, KEYM_APPL_DATA) elementIds,
  uint8 numOfReqObjects,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Dispatch to algorithm specific init functions */
  switch (KeyM_Asn1_GetAlgoType(certId))
  {
    case KEYM_ASN1_ALGO_X509_ECDSA:
    case KEYM_ASN1_ALGO_X509_EDDSA:
    {
      retVal = KeyM_Asn1_InitDescrOfCertReqInfoECC(certId, csrInfo, elementIds, numOfReqObjects, descr, descrLength);
      break;
    }
    case KEYM_ASN1_ALGO_X509_RSA:
    {
      retVal = KeyM_Asn1_InitDescrOfCertReqInfoRSA(certId, csrInfo, elementIds, numOfReqObjects, descr, descrLength);
      break;
    }
    default:
    {
      retVal = KEYM_ASN1_RC_FAILED;
      break;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_GetElementIdxByStructureType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_GetElementIdxByStructureType(
  KeyM_CertificateIdType certId,
  KeyM_OfStructureOfCertificateElementType elementStructureType,
  KeyM_SizeOfCertificateElementType* elementIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_FAILED;
  KeyM_CertificateElementIterType i;
  KeyM_SizeOfCertificateElementType position = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through configured certificates */
  for (i = KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)certId); i < KeyM_GetCertificateElementEndIdxOfCertificate((KeyM_CertificateIterType)certId); i++)
  {
    /* # Return element index for matching element structure type */
    if (KeyM_GetOfStructureOfCertificateElement(i) == elementStructureType)
    {
      retVal = KEYM_ASN1_RC_OK;
      position = (KeyM_SizeOfCertificateElementType)i;
      break;
    }
  }

  *elementIdx = position;
  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_IsCsrElementAvailable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Asn1_IsCsrElementAvailable(
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  uint8 numOfReqObjects,
  uint8 elementType,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) csrInfoIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isElementAvailable = FALSE;
  uint8_least i;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through CsrInfo objects */
  for (i = 0u; i < numOfReqObjects; i++)
  {
    /* # Return true and corresponding index in CsrInfo for matching element type */
    if (csrInfo[i].elementType == elementType)
    {
      *csrInfoIdx = (uint8)i;
      isElementAvailable = TRUE;
      break;
    }
  }

  return isElementAvailable;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InitDescrOfCertReqInfoAttributes()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoAttributes(
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  uint8 numOfReqObjects,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 descrIdx = *descrLength;
  uint8 unstructuredNameCsrInfoIdx = 0u;
  uint8 challengePasswordCsrInfoIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Init description for challenge password attribute */
  if (KeyM_Asn1_IsCsrElementAvailable(csrInfo, numOfReqObjects, KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_CHALLENGEPASSWORD, &challengePasswordCsrInfoIdx))
  {
    /* UTF8String */
    KeyM_Asn1_AppendToDescr( /* VCA_KEYM_ASN1CSR_USER_SUPPLIED_BUFFER_AND_LENGTH */
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_5,
        KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_CHALLENGEPASSWORD,
        csrInfo[challengePasswordCsrInfoIdx].dataPtr,
        csrInfo[challengePasswordCsrInfoIdx].dataLength);

    /* Set */
    KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_4,
        KEYM_ASN1_CSR_ELEMENT_SET,
        NULL_PTR,
        0u);

    /* OID */
    KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_4,
        KEYM_ASN1_CSR_ELEMENT_OID,
        KeyM_Asn1_Csr_ChallengePassword,
        KEYM_ASN1_CSR_CHALLENGEPASSWORDOIDDATALENGTH);

    /* Sequence */
    KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_3,
        KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
        NULL_PTR,
        0u);
  }

  /* # Init description for unstructured name attribute */
  if (KeyM_Asn1_IsCsrElementAvailable(csrInfo, numOfReqObjects, KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_UNSTRUCTUREDNAME, &unstructuredNameCsrInfoIdx))
  {
    /* UTF8String */
    KeyM_Asn1_AppendToDescr( /* VCA_KEYM_ASN1CSR_USER_SUPPLIED_BUFFER_AND_LENGTH */
      descr,
      &descrIdx,
      KEYM_ASN1_CSR_NL_5,
      KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_UNSTRUCTUREDNAME,
      csrInfo[unstructuredNameCsrInfoIdx].dataPtr,
      csrInfo[unstructuredNameCsrInfoIdx].dataLength);

    /* Set */
    KeyM_Asn1_AppendToDescr(
      descr,
      &descrIdx,
      KEYM_ASN1_CSR_NL_4,
      KEYM_ASN1_CSR_ELEMENT_SET,
      NULL_PTR,
      0u);

    /* OID */
    KeyM_Asn1_AppendToDescr(
      descr,
      &descrIdx,
      KEYM_ASN1_CSR_NL_4,
      KEYM_ASN1_CSR_ELEMENT_OID,
      KeyM_Asn1_Csr_UnstructuredNameOid,
      KEYM_ASN1_CSR_UNSTRUCTUREDNAMEOIDDATALENGTH);

    /* Sequence */
    KeyM_Asn1_AppendToDescr(
      descr,
      &descrIdx,
      KEYM_ASN1_CSR_NL_3,
      KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
      NULL_PTR,
      0u);
  }

  /* # Append context specific element */
  KeyM_Asn1_AppendToDescr(
    descr,
    &descrIdx,
    KEYM_ASN1_CSR_NL_2,
    KEYM_ASN1_CSR_ELEMENT_CONTEXT_SPECIFIC,
    NULL_PTR,
    0u);

  *descrLength = descrIdx;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InitDescrOfCertReqInfoECCPubKey()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoECCPubKey(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType pubKeyAlgoElementIdx,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_OK;
  uint8 descrIdx = *descrLength;

  /* ----- Implementation ----------------------------------------------- */
  /* Public Key Data */
  KeyM_Asn1_AppendToDescr(
    descr,
    &descrIdx,
    KEYM_ASN1_CSR_NL_3,
    KEYM_ASN1_CSR_ELEMENT_PUB_KEY,
    KeyM_Asn1_PubKeyBuffer,
    (uint16)KeyM_Asn1_PubKeyLength);

  /* Public Key Curve OID */
  if (KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_ECDSA)
  {
    KeyM_SizeOfCertificateElementType oidElementIndex = pubKeyAlgoElementIdx + 1u;
    if ((oidElementIndex < KeyM_GetSizeOfCertificateElement()) &&
        KeyM_IsElementOidUsedOfCertificateElement(oidElementIndex))
    {
      /*@ assert KEYM_ASN1_CSR_NL_4 <= KEYM_ASN1_PARSE_MAX_NESTING_LEVEL; */
      KeyM_Asn1_AppendToDescr( /* VCA_KEYM_ASN1CSR_READ_OID_FROM_CSL */
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_4,
        KEYM_ASN1_CSR_ELEMENT_OID,
        KeyM_GetAddrElementOid(KeyM_GetElementOidStartIdxOfCertificateElement(oidElementIndex)), /* VCA_KEYM_OID_EXISTENCE_WAS_CHECKED_BEFORE */
        KeyM_GetElementOidLengthOfCertificateElement(oidElementIndex));
    }
    else
    {
      retVal = KEYM_ASN1_RC_FAILED;
    }
  }

  if (retVal == E_OK)
  {
    KeyM_SizeOfCertificateElementType oidElementIndex = pubKeyAlgoElementIdx;
    if (KeyM_IsElementOidUsedOfCertificateElement(oidElementIndex))
    {
      /* Public Key Algorithm OID */
      /*@ assert KEYM_ASN1_CSR_NL_4 <= KEYM_ASN1_PARSE_MAX_NESTING_LEVEL; */
      KeyM_Asn1_AppendToDescr( /* VCA_KEYM_ASN1CSR_READ_OID_FROM_CSL */
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_4,
        KEYM_ASN1_CSR_ELEMENT_OID,
        KeyM_GetAddrElementOid(KeyM_GetElementOidStartIdxOfCertificateElement(oidElementIndex)), /* VCA_KEYM_OID_EXISTENCE_WAS_CHECKED_BEFORE */
        KeyM_GetElementOidLengthOfCertificateElement(oidElementIndex));
    }
    else
    {
      retVal = KEYM_ASN1_RC_FAILED;
    }
  }

  if (retVal == E_OK)
  {
    /* Public Key Algorithm Sequence */
    KeyM_Asn1_AppendToDescr(
      descr,
      &descrIdx,
      KEYM_ASN1_CSR_NL_3,
      KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
      NULL_PTR,
      0u);

    /* Public Key Sequence */
    KeyM_Asn1_AppendToDescr(
      descr,
      &descrIdx,
      KEYM_ASN1_CSR_NL_2,
      KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
      NULL_PTR,
      0u);
  }

  *descrLength = descrIdx;

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InitDescrOfCertReqInfoExtensions()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050, 6060 7 */ /* MD_MSR_STCAL, MD_KEYM_6060_LOCAL */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoExtensions(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  P2CONST(KeyM_CertElementIdType, AUTOMATIC, KEYM_APPL_DATA) elementIds,
  uint8 numOfReqObjects,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_OK;
  uint8 csrInfoElementIdx = 0u;
  uint8 numOfConfExtensionObjects;
  uint8 numOfInputExtensionObjects;
  uint8 descrIdx = *descrLength;
  uint8_least i;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get number of configured extension elements */
  KeyM_Asn1_GetConfExtensionsInfo(certId, &numOfConfExtensionObjects);

  /* # Get element start index and number of request objects in CsrInfo */
  KeyM_Asn1_GetInputExtensionsInfo(csrInfo, numOfReqObjects, &csrInfoElementIdx, &numOfInputExtensionObjects);

  if ((numOfConfExtensionObjects >= numOfInputExtensionObjects) && (numOfInputExtensionObjects > 0u) && (elementIds != NULL_PTR))
  {
    /* # Iterate through configured subject name objects and initialize ASN.1 description for CSR extensions */
    for (i = 0u; i < numOfInputExtensionObjects; i++)
    {
      KeyM_SizeOfCertificateElementType oidElementIndex;
      uint8 extensionIndex = csrInfoElementIdx + numOfInputExtensionObjects - (uint8)i - 1u;
      boolean oidElementExists = KeyM_Cert_IsCertElementAvailable(certId, elementIds[extensionIndex], &oidElementIndex);
      boolean oidIsAvailable = oidElementExists && KeyM_IsElementOidUsedOfCertificateElement(oidElementIndex);
      if (!oidIsAvailable)
      {
        /* mandatory OID is missing => abort */
        retVal = KEYM_ASN1_RC_FAILED;
        break;
      }

      /* Extension Data */
      KeyM_Asn1_AppendToDescr( /* VCA_KEYM_ASN1CSR_USER_SUPPLIED_BUFFER_AND_LENGTH */
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_7,
        csrInfo[extensionIndex].elementType,
        csrInfo[extensionIndex].dataPtr,
        csrInfo[extensionIndex].dataLength);

      /* OID */
      /*@ assert KEYM_ASN1_CSR_NL_7 <= KEYM_ASN1_PARSE_MAX_NESTING_LEVEL; */
      KeyM_Asn1_AppendToDescr( /* VCA_KEYM_ASN1CSR_READ_OID_FROM_CSL */
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_7,
        KEYM_ASN1_CSR_ELEMENT_OID,
        KeyM_GetAddrElementOid(KeyM_GetElementOidStartIdxOfCertificateElement(oidElementIndex)), /* VCA_KEYM_OID_EXISTENCE_WAS_CHECKED_BEFORE */
        KeyM_GetElementOidLengthOfCertificateElement(oidElementIndex));

      /* Sequence */
      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_6,
        KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
        NULL_PTR,
        0u);
    }

    if (retVal == KEYM_ASN1_RC_OK)
    {
      /* Sequence */
      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_5,
        KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
        NULL_PTR,
        0u);

      /* SET */
      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_4,
        KEYM_ASN1_CSR_ELEMENT_SET,
        NULL_PTR,
        0u);

      /* OID */
      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_4,
        KEYM_ASN1_CSR_ELEMENT_OID,
        KeyM_Asn1_Csr_ExtensionRequest,
        KEYM_ASN1_CSR_EXTENSIONREQUESTOIDDATALENGTH);

      /* Sequence */
      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_3,
        KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
        NULL_PTR,
        0u);
    }

    *descrLength = descrIdx;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_GetConfSubjectNameInfo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_GetConfSubjectNameInfo(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, KEYM_APPL_VAR) elementStartIdx,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, KEYM_APPL_VAR) numOfConfSubjectNameObjects)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_CertificateElementIterType elementIdx;
  KeyM_SizeOfCertificateElementType localElementStartIdx = 0u;
  KeyM_SizeOfCertificateElementType num = 0u;

  /* ----- Implementation ----------------------------------------------- */

  /* # Iterate through configured certificate elements */
  for (elementIdx = KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)certId);
       elementIdx < KeyM_GetCertificateElementEndIdxOfCertificate((KeyM_CertificateIterType)certId);
       elementIdx++)
  {
    if (KeyM_GetOfStructureOfCertificateElement(elementIdx) == KEYM_CERTIFICATE_SUBJECT_NAME)
    {
      if (num == 0u)
      {
        /* # Retrieve index of first subject name element */
        localElementStartIdx = (KeyM_SizeOfCertificateElementType)elementIdx;
      }
      num++;
    }
  }

  /*@ assert localElementStartIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_ASN1CSR_BOUNDS_OF_ELEMENTSTARTIDX */

  /* # Retrieve number of subject name elements */
  *elementStartIdx = localElementStartIdx;
  *numOfConfSubjectNameObjects = num;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_GetConfExtensionsInfo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_GetConfExtensionsInfo(
  KeyM_CertificateIdType certId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) numOfConfExtensionsObjects)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_CertificateElementIterType elementIdx;
  uint8 num = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through configured certificate elements */
  for (elementIdx = KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)certId); elementIdx < KeyM_GetCertificateElementEndIdxOfCertificate((KeyM_CertificateIterType)certId); elementIdx++)
  {
    if (KeyM_GetOfStructureOfCertificateElement(elementIdx) == KEYM_CERTIFICATE_EXTENSION)
    {
      num++;
    }
  }

  /* # Retrieve number of extension elements */
  *numOfConfExtensionsObjects = num;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_GetInputSubjectNameInfo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_GetInputSubjectNameInfo(
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  uint8 numOfReqObjects,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) elementStartIdx,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) numOfInputSubjectNameObjects)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least elementIdx;
  uint8 num = 0u;
  uint8 elementType = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through CsrInfo objects
   * Note: After iterating through the for-loop has ended, it will hold that
   * num + *elementStartIdx < (numOfReqObjects - 1u) */
  for (elementIdx = 0u; elementIdx < numOfReqObjects; elementIdx++)
  {
    elementType = csrInfo[elementIdx].elementType;

    /* Is certificate element a valid subject name attribute */
    if ((elementType == KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_COUNTRYNAME)
    || (elementType == KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_STATEORPROVINCENAME)
    || (elementType == KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_LOCALITYNAME)
    || (elementType == KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_ORGANIZATIONNAME)
    || (elementType == KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_ORGANIZATIONUNITNAME)
    || (elementType == KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_COMMONNAME)
    || (elementType == KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_EMAIL))
    {
      if (num == 0u)
      {
        /* # Retrieve index of first subject name element */
        *elementStartIdx = (uint8)elementIdx;
      }
      num++;
    }
  }
  /* # Retrieve number of subject name elements */
  *numOfInputSubjectNameObjects = num;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_GetInputExtensionsInfo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_GetInputExtensionsInfo(
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  uint8 numOfReqObjects,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) elementStartIdx,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) numOfInputExtensionObjects)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least elementIdx;
  uint8 num = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through CsrInfo objects
   * Note: After iterating through the for-loop has ended, it will hold that
   * num + *elementStartIdx < (numOfReqObjects - 1u) */
  for (elementIdx = 0u; elementIdx < numOfReqObjects; elementIdx++)
  {
    if (csrInfo[elementIdx].elementType == KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_EXTENSION)
    {
      if (num == 0u)
      {
        /* # Retrieve index of first extension element */
        *elementStartIdx = (uint8)elementIdx;
      }
      num++;
    }
  }
  /* # Retrieve number of extension elements */
  *numOfInputExtensionObjects = num;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InitDescrOfCertReqInfoSubject()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoSubject(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  uint8 numOfReqObjects,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_SizeOfCertificateElementType firstConfElementIdx = 0u;
  KeyM_SizeOfCertificateElementType confElementEndIdx = 0u;
  KeyM_SizeOfCertificateElementType oidElementIndex;
  KeyM_SizeOfCertificateElementType numOfConfSubjectNameObjects;
  uint8 csrInfoElementIdx = 0u;
  uint8 numOfInputSubjectNameObjects;
  uint8 descrIdx = *descrLength;
  uint8_least i;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get element start index and number of configured subject name elements */
  KeyM_Asn1_GetConfSubjectNameInfo(certId, &firstConfElementIdx, &numOfConfSubjectNameObjects);
  confElementEndIdx = firstConfElementIdx + numOfConfSubjectNameObjects;
  /*@ assert firstConfElementIdx < KeyM_GetSizeOfCertificateElement(); */
  /*@ assert confElementEndIdx <= KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_ASN1CSR_BOUNDS_OF_CONFELEMENTENDIDX */

  /* # Get element start index and number of request objects in CsrInfo */
  KeyM_Asn1_GetInputSubjectNameInfo(csrInfo, numOfReqObjects, &csrInfoElementIdx, &numOfInputSubjectNameObjects);

  if (numOfConfSubjectNameObjects == numOfInputSubjectNameObjects)
  {
    retVal = E_OK;

    /* # Iterate through configured subject name objects */
    for (i = 0u; i < numOfConfSubjectNameObjects; i++)
    {
      oidElementIndex = confElementEndIdx - (KeyM_SizeOfCertificateElementType)i - 1u;
      /*@ assert oidElementIndex < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_ASN1CSR_BOUNDS_OF_OIDELEMENTIDX */

      /* # Check if all required elements are actually configured */
      if (!KeyM_IsElementOidUsedOfCertificateElement(oidElementIndex))
      {
        /* OID configuration is missing for the element => abort */
        retVal = KEYM_ASN1_RC_FAILED;
        break;
      }

      /* Subject Name */
      KeyM_Asn1_AppendToDescr( /* VCA_KEYM_ASN1CSR_USER_SUPPLIED_BUFFER_AND_LENGTH */
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_5,
        csrInfo[csrInfoElementIdx + numOfInputSubjectNameObjects - (uint8)i - 1u].elementType,
        csrInfo[csrInfoElementIdx + numOfInputSubjectNameObjects - (uint8)i - 1u].dataPtr,
        csrInfo[csrInfoElementIdx + numOfInputSubjectNameObjects - (uint8)i - 1u].dataLength);

      /* OID */
      /*@ assert KEYM_ASN1_CSR_NL_5 <= KEYM_ASN1_PARSE_MAX_NESTING_LEVEL; */
      KeyM_Asn1_AppendToDescr( /* VCA_KEYM_ASN1CSR_READ_OID_FROM_CSL */
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_5,
        KEYM_ASN1_CSR_ELEMENT_OID,
        KeyM_GetAddrElementOid(KeyM_GetElementOidStartIdxOfCertificateElement(oidElementIndex)), /* VCA_KEYM_OID_EXISTENCE_WAS_CHECKED_BEFORE */
        KeyM_GetElementOidLengthOfCertificateElement(oidElementIndex));

      /* Sequence */
      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_4,
        KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
        NULL_PTR,
        0u);

      /* Set */
      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_3,
        KEYM_ASN1_CSR_ELEMENT_SET,
        NULL_PTR,
        0u);
    }

    /* Sequence */
    KeyM_Asn1_AppendToDescr(
      descr,
      &descrIdx,
      KEYM_ASN1_CSR_NL_2,
      KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
      NULL_PTR,
      0u);

    *descrLength = descrIdx;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InitDescrOfCertReqInfoEncodePubKeyECC()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoEncodePubKeyECC(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 pubKeyBuffer[KEYM_CERTIFICATE_PUB_KEY_BUFFER_MAX_LENGTH];
  uint32 pubKeyBufferDataLength;
  uint8 offset = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check whether public key data needs to be encoded */
  if ((KeyM_Asn1_PubKeyLength % 8u) == 0u)
  {
    /* 0x00 specifies the number of unused bits that exist in the last content byte of the BITSTRING */
    pubKeyBuffer[offset] = 0x00u;
    offset++;

    if (KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_ECDSA)
    {
      /* 0x04 indicates that the public key is in uncompressed form */
      pubKeyBuffer[offset] = 0x04u;
      offset++;
    }
    pubKeyBufferDataLength = offset;

    VStdLib_MemCpyLarge(&pubKeyBuffer[offset], KeyM_Asn1_PubKeyBuffer, KeyM_Asn1_PubKeyLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    pubKeyBufferDataLength += KeyM_Asn1_PubKeyLength;

    VStdLib_MemCpyLarge(KeyM_Asn1_PubKeyBuffer, pubKeyBuffer, pubKeyBufferDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    KeyM_Asn1_PubKeyLength = pubKeyBufferDataLength;
  }
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InitDescrOfCertReqInfoEncodePubKeyRSA()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoEncodePubKeyRSA(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 pubKeyBuffer[KEYM_CERTIFICATE_PUB_KEY_BUFFER_MAX_LENGTH];
  uint32 pubKeyBufferDataLength;
  uint8 offset = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check whether modulus needs to be encoded */
  if (((KeyM_Asn1_PubKeyLength % 8u) == 0u) && ((KeyM_Asn1_PubKeyBuffer[0u] & 0x80u) == 0x80u))
  {
    /* 0x00, is added to the content to indicate that the INTEGER is indeed a positive value */
    pubKeyBuffer[offset] = 0x00u;
    offset++;

    pubKeyBufferDataLength = offset;

    VStdLib_MemCpyLarge(&pubKeyBuffer[offset], KeyM_Asn1_PubKeyBuffer, KeyM_Asn1_PubKeyLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    pubKeyBufferDataLength += KeyM_Asn1_PubKeyLength;

    VStdLib_MemCpyLarge(KeyM_Asn1_PubKeyBuffer, pubKeyBuffer, pubKeyBufferDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    KeyM_Asn1_PubKeyLength = pubKeyBufferDataLength;
  }

  offset = 0u;

  /* # Check whether exponent needs to be encoded */
  if ((KeyM_Asn1_SecondaryPubKeyBuffer[0u] & 0x80u) == 0x80u)
  {
    /* 0x00, is added to the content to indicate that the INTEGER is indeed a positive value */
    pubKeyBuffer[offset] = 0x00u;
    offset++;

    pubKeyBufferDataLength = offset;

    VStdLib_MemCpyLarge(&pubKeyBuffer[offset], KeyM_Asn1_SecondaryPubKeyBuffer, KeyM_Asn1_SecondaryPubKeyLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    pubKeyBufferDataLength += KeyM_Asn1_SecondaryPubKeyLength;

    VStdLib_MemCpyLarge(KeyM_Asn1_SecondaryPubKeyBuffer, pubKeyBuffer, pubKeyBufferDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    KeyM_Asn1_SecondaryPubKeyLength = (uint32)(pubKeyBufferDataLength);
  }
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InitDescrOfCertReqInfoECC()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050, 6060 7 */ /* MD_MSR_STCAL, MD_KEYM_6060_LOCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoECC(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  P2CONST(KeyM_CertElementIdType, AUTOMATIC, KEYM_APPL_DATA) elementIds,
  uint8 numOfReqObjects,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  uint8 descrIdx = 0u;
  KeyM_SizeOfCertificateElementType pubKeyAlgoElementIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get Public Key from CSM Key Storage */
  KeyM_Asn1_PubKeyLength = KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH;
  csmResult = Csm_KeyElementGet(KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)certId), CRYPTO_KE_SIGNATURE_KEY, KeyM_Asn1_PubKeyBuffer, &KeyM_Asn1_PubKeyLength);
  retVal = KeyM_Asn1_HandleCsmResult(csmResult);

  if (retVal == E_OK)
  {
    /* # Handle public key encoding */
    KeyM_Asn1_InitDescrOfCertReqInfoEncodePubKeyECC(certId);

    /* # Append CertificationRequestInfo elements */
    retVal = KeyM_Asn1_GetElementIdxByStructureType(
      certId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM, &pubKeyAlgoElementIdx);
  }

  if (retVal == E_OK)
  {
    /* Extensions */
    retVal = KeyM_Asn1_InitDescrOfCertReqInfoExtensions(certId, csrInfo, elementIds, numOfReqObjects, descr, &descrIdx);
  }

  if (retVal == E_OK)
  {
    /* Attributes */
    KeyM_Asn1_InitDescrOfCertReqInfoAttributes(csrInfo, numOfReqObjects, descr, &descrIdx);

    /* Public Key */
    retVal = KeyM_Asn1_InitDescrOfCertReqInfoECCPubKey(certId, pubKeyAlgoElementIdx, descr, &descrIdx);

    if (retVal == E_OK)
    {
      /* Constructed Subject Name */
      retVal = KeyM_Asn1_InitDescrOfCertReqInfoSubject(certId, csrInfo, numOfReqObjects, descr, &descrIdx);

      /* Version */
      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_2,
        KEYM_ASN1_CSR_ELEMENT_VERSION,
        KeyM_Asn1_Csr_Version,
        KEYM_ASN1_CSR_VERSIONDATALENGTH);

      /* Sequence of CertificationRequestInfo */
      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_1,
        KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
        NULL_PTR,
        0u);

      *descrLength = descrIdx;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_AppendToDescr()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6060 1 */ /* MD_KEYM_6060_LOCAL */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_AppendToDescr(
    KeyM_Asn1_ElementType_Buffer descr,
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength,
    uint8 nestingLevel,
    uint8 elementType,
    P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) dataPtr,
    uint16 dataLength)
{
  if (*descrLength < descr.size)
  {
    KeyM_Asn1_ElementType* element = &descr.data[*descrLength];
    element->nestingLevel = nestingLevel;
    element->elementType = elementType;
    element->dataPtr = dataPtr;
    element->dataLength = dataLength;

    *descrLength = (*descrLength) + 1u;
  }
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InitDescrOfCertReqInfoRSA()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050, 6060 7 */ /* MD_MSR_STCAL, MD_KEYM_6060_LOCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReqInfoRSA(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  P2CONST(KeyM_CertElementIdType, AUTOMATIC, KEYM_APPL_DATA) elementIds,
  uint8 numOfReqObjects,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  uint8 descrIdx = 0u;
  KeyM_SizeOfCertificateElementType pubKeyAlgoElementIdx = 0;
  KeyM_CertificateElementIterType oidElementIndex;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get Public Key from CSM Key Storage */
  KeyM_Asn1_PubKeyLength = KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH;
  csmResult = Csm_KeyElementGet(KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)certId), CRYPTO_KE_CUSTOM_RSA_MODULUS, KeyM_Asn1_PubKeyBuffer, &KeyM_Asn1_PubKeyLength);
  retVal = KeyM_Asn1_HandleCsmResult(csmResult);

  if (retVal == E_OK)
  {
    KeyM_Asn1_SecondaryPubKeyLength = (uint32)(KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH);
    csmResult = Csm_KeyElementGet(KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)certId), CRYPTO_KE_CUSTOM_RSA_PUBLIC_EXPONENT, KeyM_Asn1_SecondaryPubKeyBuffer, &KeyM_Asn1_SecondaryPubKeyLength);
    retVal = KeyM_Asn1_HandleCsmResult(csmResult);

    if (retVal == E_OK)
    {
      /* # Handle public key encoding */
      KeyM_Asn1_InitDescrOfCertReqInfoEncodePubKeyRSA();

      /* # Append CertificationRequestInfo elements */
      retVal = KeyM_Asn1_GetElementIdxByStructureType(
        certId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM, &pubKeyAlgoElementIdx);
    }

    if (retVal == E_OK)
    {
      /* Extensions */
      retVal = KeyM_Asn1_InitDescrOfCertReqInfoExtensions(certId, csrInfo, elementIds, numOfReqObjects, descr, &descrIdx);
    }

    if (retVal == E_OK)
    {
      /* Attributes */
      KeyM_Asn1_InitDescrOfCertReqInfoAttributes(csrInfo, numOfReqObjects, descr, &descrIdx);

      /* Public Key */
      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_5,
        KEYM_ASN1_CSR_ELEMENT_PUB_KEY,
        KeyM_Asn1_SecondaryPubKeyBuffer,
        (uint16)KeyM_Asn1_SecondaryPubKeyLength);

      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_5,
        KEYM_ASN1_CSR_ELEMENT_PUB_KEY,
        KeyM_Asn1_PubKeyBuffer,
        (uint16)KeyM_Asn1_PubKeyLength);

      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_4,
        KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
        NULL_PTR,
        0u);

      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_3,
        KEYM_ASN1_CSR_ELEMENT_CONSTRUCTED_BITSTRING,
        NULL_PTR,
        0u);

      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_4,
        KEYM_ASN1_CSR_ELEMENT_NULL,
        NULL_PTR,
        0u);

      oidElementIndex = pubKeyAlgoElementIdx;
      if (KeyM_IsElementOidUsedOfCertificateElement(oidElementIndex))
      {
        /*@ assert KEYM_ASN1_CSR_NL_4 <= KEYM_ASN1_PARSE_MAX_NESTING_LEVEL; */
        KeyM_Asn1_AppendToDescr( /* VCA_KEYM_ASN1CSR_READ_OID_FROM_CSL */
          descr,
          &descrIdx,
          KEYM_ASN1_CSR_NL_4,
          KEYM_ASN1_CSR_ELEMENT_OID,
          KeyM_GetAddrElementOid(KeyM_GetElementOidStartIdxOfCertificateElement(oidElementIndex)), /* VCA_KEYM_OID_EXISTENCE_WAS_CHECKED_BEFORE */
          KeyM_GetElementOidLengthOfCertificateElement(oidElementIndex));
      }
      else
      {
        retVal = KEYM_ASN1_RC_FAILED;
      }

      if (retVal == E_OK)
      {
        KeyM_Asn1_AppendToDescr(
          descr,
          &descrIdx,
          KEYM_ASN1_CSR_NL_3,
          KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
          NULL_PTR,
          0u);

        KeyM_Asn1_AppendToDescr(
          descr,
          &descrIdx,
          KEYM_ASN1_CSR_NL_2,
          KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
          NULL_PTR,
          0u);

        /* Constructed Subject Name */
        retVal = KeyM_Asn1_InitDescrOfCertReqInfoSubject(certId, csrInfo, numOfReqObjects, descr, &descrIdx);
      }

      if (retVal == E_OK)
      {
        /* Version */
        KeyM_Asn1_AppendToDescr(
          descr,
          &descrIdx,
          KEYM_ASN1_CSR_NL_2,
          KEYM_ASN1_CSR_ELEMENT_VERSION,
          KeyM_Asn1_Csr_Version,
          KEYM_ASN1_CSR_VERSIONDATALENGTH);

        /* Sequence of CertificationRequestInfo */
        KeyM_Asn1_AppendToDescr(
          descr,
          &descrIdx,
          KEYM_ASN1_CSR_NL_1,
          KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
          NULL_PTR,
          0u);

        *descrLength = descrIdx;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_HandleCsmResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_HandleCsmResult(
  Std_ReturnType csmResult)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Evaluate result of CSM operation */
  if (csmResult == E_OK)
  {
    /* Operation successful */
    retVal = KEYM_ASN1_RC_OK;
  }
  else
  {
    /* Operation unsuccessful */
    retVal = KEYM_ASN1_RC_FAILED;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_SignatureGenerate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_SignatureGenerate(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_Asn1_CsrType, AUTOMATIC, KEYM_APPL_VAR) certReqInfo,
  P2VAR(KeyM_Asn1_SignatureType, AUTOMATIC, KEYM_APPL_VAR) sig)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  uint8 sigBuffer[KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH];
  uint32 sigBufferLength = KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH;

  /* ----- Implementation ----------------------------------------------- */
  sig->primaryDataLength = 0;
  sig->secondaryDataLength = 0;

  /* # Generate Signature */
  csmResult = Csm_SignatureGenerate(KeyM_GetCertCsmSignatureGenerateJobRefOfCertificate((KeyM_CertificateIterType)certId), CRYPTO_OPERATIONMODE_SINGLECALL, certReqInfo->data, certReqInfo->dataLength, sigBuffer, &sigBufferLength);
  retVal = KeyM_Asn1_HandleCsmResult(csmResult);

  /* # Handle CSR encoding rules */
  if (retVal == E_OK)
  {
    switch (KeyM_Asn1_GetAlgoType(certId))
    {
      case KEYM_ASN1_ALGO_X509_ECDSA:
      case KEYM_ASN1_ALGO_X509_EDDSA:
      {
        if (KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_ECDSA)
        {
          /* Check if most signitificant bit is set */
          if ((sigBuffer[0] & 0x80u) == 0x80u)
          {
            /* Add leading zero to returned primary signature component */
            VStdLib_MemCpyLarge(&sig->primaryData[1], sigBuffer, sigBufferLength / 2u); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
            sig->primaryData[0] = 0x00u;
            sig->primaryDataLength = ((uint16)sigBufferLength / 2u) + 1u;
          }
          else
          {
            VStdLib_MemCpyLarge(sig->primaryData, sigBuffer, sigBufferLength / 2u); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
            sig->primaryDataLength = (uint16)sigBufferLength / 2u;
          }

          /* Check if most signitificant bit is set */
          if ((sigBuffer[sigBufferLength / 2u] & 0x80u) == 0x80u)
          {
            /* Add leading zero to returned secondary signature component */
            VStdLib_MemCpyLarge(&sig->secondaryData[1], &sigBuffer[sigBufferLength / 2u], sigBufferLength / 2u); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
            sig->secondaryData[0] = 0x00u;
            sig->secondaryDataLength = ((uint16)sigBufferLength / 2u) + 1u;
          }
          else
          {
            VStdLib_MemCpyLarge(sig->secondaryData, &sigBuffer[sigBufferLength / 2u], sigBufferLength / 2u); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
            sig->secondaryDataLength = (uint16)sigBufferLength / 2u;
          }
        }
        else
        {
          /* Add leading zero to returned signature */
          VStdLib_MemCpyLarge(&sig->primaryData[1], sigBuffer, sigBufferLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
          sig->primaryData[0] = 0x00u;
          sig->primaryDataLength = (uint16)sigBufferLength + 1u;
        }

        break;
      }
      case KEYM_ASN1_ALGO_X509_RSA:
      {
        /* Add leading zero to returned signature */
        VStdLib_MemCpyLarge(&sig->primaryData[1], sigBuffer, sigBufferLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
        sig->primaryData[0] = 0x00u;
        sig->primaryDataLength = (uint16)sigBufferLength + 1u;
        break;
      }
      default:
      {
        retVal = KEYM_ASN1_RC_FAILED;
        break;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_BuildCertificationRequest()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_BuildCertificationRequest(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_Asn1_CsrType, AUTOMATIC, KEYM_APPL_VAR) certReqInfo,
  P2CONST(KeyM_Asn1_SignatureType, AUTOMATIC, KEYM_APPL_VAR) sig,
  P2VAR(KeyM_Asn1_CsrType, AUTOMATIC, KEYM_APPL_VAR) certReq)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_ElementType certReqDescr[KEYM_ASN1_CSR_CERTIFICATIONREQUEST_DESCR_MAX_SIZE];
  KeyM_Asn1_ElementType_Buffer certReqDescrAndSize;
  uint8 certReqDescrLength = 0u;
  uint8 tagBuffer[KEYM_ASN1_MAX_CSR_SIZE];
  uint16 tagBufferLength;
  uint16 certReqPos = 0u;
  uint8 certReqDescrIdx;
  uint16 nestingLevelDataLength[KEYM_ASN1_PARSE_MAX_NESTING_LEVEL + 1u] = { 0u };
  KeyM_Asn1_ElementType element;

  /* ----- Implementation ----------------------------------------------- */
  /* # Init description for CertificationRequest */
  certReqDescrAndSize.data = &certReqDescr[0];
  certReqDescrAndSize.size = KEYM_ASN1_CSR_CERTIFICATIONREQUEST_DESCR_MAX_SIZE;
  retVal = KeyM_Asn1_InitDescrOfCertReq(certId, certReqInfo, sig, certReqDescrAndSize, &certReqDescrLength);

  if (retVal == KEYM_ASN1_RC_OK)
  {
    /* # Build ASN.1 string for CertificationRequest */
    for (certReqDescrIdx = 0u; certReqDescrIdx < certReqDescrLength; certReqDescrIdx++)
    {
      element = certReqDescr[certReqDescrIdx];
      /* Set tagBufferLength to zero to not overwrite detected issues in the overflow check at the end of the loop */
      tagBufferLength = 0u;

      /* Bounds check for nestingLevelDataLength array access */
      if (KeyM_Utils_IsLess(KEYM_ASN1_PARSE_MAX_NESTING_LEVEL, ((uint32)element.nestingLevel + 1u)))
      {
        retVal = KEYM_ASN1_RC_LEN_OVERFLOW;
      }
      /* Add CertificationRequestInfo data */
      else if (element.elementType == KEYM_ASN1_CSR_ELEMENT_CERTREQINFO_SEQUENCE)
      {
        /*@ assert $lengthOf(tagBuffer) >= KEYM_ASN1_MAX_CSR_SIZE; */
        VStdLib_MemCpyLarge(tagBuffer, element.dataPtr, element.dataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_ASN1CSR_MEMCPY_INTO_TAGBUFFER */
        tagBufferLength = element.dataLength;
        nestingLevelDataLength[element.nestingLevel] += tagBufferLength;
      }
      /* Build ASN.1 string for constructed certificate elements */
      else if (KeyM_Asn1_Csr_IsElementConstructed(element.elementType))
      {
        KeyM_Asn1_InsertTagAndLength(
            certId,
            element.elementType,
            nestingLevelDataLength[element.nestingLevel + 1u],
            tagBuffer,
            &tagBufferLength);

        /* Append zero octet for constructed bitstring element */
        if (element.elementType == KEYM_ASN1_CSR_ELEMENT_CONSTRUCTED_BITSTRING)
        {
          /* Increment length value */
          tagBuffer[tagBufferLength - 1u] += 1u;
          /* Add zero octet */
          tagBuffer[tagBufferLength] = 0x00;
          /* Increment tag length */
          tagBufferLength++;
        }

        nestingLevelDataLength[element.nestingLevel] += tagBufferLength + nestingLevelDataLength[element.nestingLevel + 1u];
        nestingLevelDataLength[element.nestingLevel + 1u] = 0u;
      }
      /* Build ASN.1 string for primitive certificate elements */
      else
      {
        tagBufferLength = KEYM_ASN1_MAX_CSR_SIZE;
        retVal = KeyM_Asn1_BuildTag(certId, element.elementType, element.dataPtr, element.dataLength, tagBuffer, &tagBufferLength);
        nestingLevelDataLength[element.nestingLevel] += tagBufferLength;
      }

      certReqPos += tagBufferLength;
      if (certReqPos > KEYM_ASN1_MAX_CSR_SIZE) {
        /* What needs to be written does not fit into the buffer => abort */
        certReqPos = 0;
        retVal = KEYM_ASN1_RC_LEN_OVERFLOW;
      }

      if (retVal != KEYM_ASN1_RC_OK)
      {
        break;
      }

      /*@ assert $lengthOf(certReq->data) >= KEYM_ASN1_MAX_CSR_SIZE; */
      /*@ assert $lengthOf(tagBuffer)     >= KEYM_ASN1_MAX_CSR_SIZE; */
      VStdLib_MemCpyLarge(&(certReq->data[KEYM_ASN1_MAX_CSR_SIZE - certReqPos]), tagBuffer, tagBufferLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_ASN1CSR_MEMCPY_INTO_CERTREQ */
    }

    /*@ assert certReqPos <= KEYM_ASN1_MAX_CSR_SIZE; */
    certReq->dataLength = certReqPos;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InitDescrOfCertReq()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDescrOfCertReq(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_Asn1_CsrType, AUTOMATIC, KEYM_APPL_DATA) certReqInfo,
  P2CONST(KeyM_Asn1_SignatureType, AUTOMATIC, KEYM_APPL_DATA) sig,
  KeyM_Asn1_ElementType_Buffer descr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) descrLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 descrIdx = 0u;
  KeyM_SizeOfCertificateElementType elementIdx;

  /* ----- Implementation ----------------------------------------------- */
  retVal = KeyM_Asn1_GetElementIdxByStructureType(certId, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM, &elementIdx);

  if (retVal == KEYM_ASN1_RC_OK)
  {
    if (!KeyM_IsElementOidUsedOfCertificateElement(elementIdx))
    {
      /* OID is missing => abort! */
      retVal = KEYM_ASN1_RC_FAILED;
    }
    else
    {
      /* # Init description elements for CertificationRequest */
      if (KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_ECDSA)
      {
        /* Signature */
        KeyM_Asn1_AppendToDescr(
          descr,
          &descrIdx,
          KEYM_ASN1_CSR_NL_3,
          KEYM_ASN1_CSR_ELEMENT_SIGNATURE,
          sig->secondaryData,
          sig->secondaryDataLength);

        KeyM_Asn1_AppendToDescr(
          descr,
          &descrIdx,
          KEYM_ASN1_CSR_NL_3,
          KEYM_ASN1_CSR_ELEMENT_SIGNATURE,
          sig->primaryData,
          sig->primaryDataLength);

        KeyM_Asn1_AppendToDescr(
          descr,
          &descrIdx,
          KEYM_ASN1_CSR_NL_2,
          KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
          NULL_PTR,
          0u);

        KeyM_Asn1_AppendToDescr(
          descr,
          &descrIdx,
          KEYM_ASN1_CSR_NL_1,
          KEYM_ASN1_CSR_ELEMENT_CONSTRUCTED_BITSTRING,
          NULL_PTR,
          0u);
      }
      else
      {
        /* Signature */
        KeyM_Asn1_AppendToDescr(
          descr,
          &descrIdx,
          KEYM_ASN1_CSR_NL_1,
          KEYM_ASN1_CSR_ELEMENT_SIGNATURE,
          sig->primaryData,
          sig->primaryDataLength);
      }

      if (KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_RSA)
      {
        KeyM_Asn1_AppendToDescr(
          descr,
          &descrIdx,
          KEYM_ASN1_CSR_NL_2,
          KEYM_ASN1_CSR_ELEMENT_NULL,
          NULL_PTR,
          0u);
      }

      /*@ assert KEYM_ASN1_CSR_NL_2 <= KEYM_ASN1_PARSE_MAX_NESTING_LEVEL; */
      KeyM_Asn1_AppendToDescr( /* VCA_KEYM_ASN1CSR_READ_OID_FROM_CSL */
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_2,
        KEYM_ASN1_CSR_ELEMENT_OID,
        KeyM_GetAddrElementOid(KeyM_GetElementOidStartIdxOfCertificateElement(elementIdx)), /* VCA_KEYM_OID_EXISTENCE_WAS_CHECKED_BEFORE */
        KeyM_GetElementOidLengthOfCertificateElement(elementIdx));

      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_1,
        KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
        NULL_PTR,
        0u);

      /* Constructed CertificationRequestInfo */
      /*@ assert certReqInfo->data != NULL_PTR; */
      /*@ assert certReqInfo->dataLength <= KEYM_ASN1_MAX_CSR_SIZE; */
      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_1,
        KEYM_ASN1_CSR_ELEMENT_CERTREQINFO_SEQUENCE,
        certReqInfo->data,
        certReqInfo->dataLength);

      /* CertificationRequest */
      KeyM_Asn1_AppendToDescr(
        descr,
        &descrIdx,
        KEYM_ASN1_CSR_NL_0,
        KEYM_ASN1_CSR_ELEMENT_SEQUENCE,
        NULL_PTR,
        0u);

      *descrLength = descrIdx;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InsertTagAndLength()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_InsertTagAndLength(
  KeyM_CertificateIdType certId,
  uint8 elementType,
  uint16 tagDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) responseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 firstLengthOctet;
  uint8 secondLengthOctet;
  uint16 res;
  uint16 pos = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve identifier octets */
  KeyM_Asn1_GetTagIdentifier(certId, elementType, responseData, &pos);

  /* # Retrieve length octets */
  if (tagDataLength < 0x80u)
  {
    /* Short form */
    responseData[pos] = (uint8)tagDataLength;
    pos++;
  }
  else
  {
    /* Long form */
    if (tagDataLength < 0xFFu)
    {
      firstLengthOctet = (uint8)tagDataLength;

      /* Set header octet */
      responseData[pos] = 0x81u;
      pos++;

      /* Set length */
      responseData[pos] = firstLengthOctet;
      pos++;
    }
    else
    {
      /* 256-base representation of length */
      res = (tagDataLength >> 8u);
      firstLengthOctet = (uint8)res;

      res = (res << 8u);
      res = tagDataLength - res;
      secondLengthOctet = (uint8)res;

      /* Set header octet */
      responseData[pos] = 0x82u;
      pos++;

      /* Set length */
      responseData[pos] = firstLengthOctet;
      pos++;

      responseData[pos] = secondLengthOctet;
      pos++;
    }
  }

  *responseDataLength = pos;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_BuildTag()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6060 7 */ /* MD_KEYM_6060_LOCAL */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_BuildTag(
  KeyM_CertificateIdType certId,
  uint8 elementType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) tagData,
  uint16 tagDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) responseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_OK;
  uint16 pos = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Write tag and length bytes into responseData if not encoded */
  if (elementType == KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_EXTENSION)
  {
    /* Encoded data is already in TLV format and only needs to be copied */
  }
  else
  {
    KeyM_Asn1_InsertTagAndLength(certId, elementType, tagDataLength, responseData, &pos);
  }

  /* # Write tagData into responseData */
  if (tagData != NULL_PTR)
  {
    if ((pos + tagDataLength) > *responseDataLength)
    {
      retVal = KEYM_ASN1_RC_LEN_OVERFLOW;
    }
    else
    {
      /* Content octets */
      VStdLib_MemCpyLarge(&responseData[pos], tagData, tagDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_ASN1CSR_MEMCPY_ELEMENT_INTO_RESPONSEDATA */
      pos += tagDataLength;
    }
  }

  /* Return total tag length */
  *responseDataLength = pos;
  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */
#endif /* (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON) */

#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_StoreOCSPResponderIdParseInfo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_StoreOCSPResponderIdParseInfo(
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) refIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_FAILED;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if the tag is valid */
  if (asn1Param->last_tag_valid)
  {
    /* # Store parsing information for ResponderId attributes */
    ocspResp[*refIdx].elementOffset = asn1Param->root_tag_base_pos + asn1Param->last_tag_data_pos + ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID].elementOffset;
    ocspResp[*refIdx].elementLength = asn1Param->last_tag_len;
    ocspResp[*refIdx].isPresent = TRUE;
    retVal = KEYM_ASN1_RC_OK;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_StoreOCSPParseInfo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_StoreOCSPParseInfo(
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_FAILED;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if the tag is valid */
  if (asn1Param->last_tag_valid)
  {
    /* # Store parsing information for constructed ResponderId element */
    if ((((asn1Param->last_tag) & (KEYM_ASN1_CLASS_MASK)) == KEYM_ASN1_CLASS_CONTEXT_SPECIFIC) &&
      (KeyM_Asn1_OCSPElement[asn1ParseParam->asn1_element_idx].ofStructureOfOcspElement == KEYM_ASN1_OCSP_RESPONSE_RESPONDERID))
    {
      ocspResp[KeyM_Asn1_OCSPElement[asn1ParseParam->asn1_element_idx].refIdxOcspElement].elementOffset = (asn1Param->root_tag_base_pos + asn1Param->last_tag_base_pos);
      ocspResp[KeyM_Asn1_OCSPElement[asn1ParseParam->asn1_element_idx].refIdxOcspElement].elementLength = (asn1Param->last_tag_len + (asn1Param->last_tag_data_pos - asn1Param->last_tag_base_pos));
    }
    /* # Store parsing information for constructed CertStatus element */
    else if ((((asn1Param->last_tag) & (KEYM_ASN1_CLASS_MASK)) == KEYM_ASN1_CLASS_CONTEXT_SPECIFIC) &&
      (KeyM_Asn1_OCSPElement[asn1ParseParam->asn1_element_idx].ofStructureOfOcspElement == KEYM_ASN1_OCSP_RESPONSE_CERTSTATUS))
    {
      /* Only tag identifier of CertStatus is stored, therefore element offset needs to be subtracted by one byte for tag identifier and one byte for tag length */
      ocspResp[KeyM_Asn1_OCSPElement[asn1ParseParam->asn1_element_idx].refIdxOcspElement].elementOffset = (asn1Param->root_tag_base_pos + asn1Param->last_tag_data_pos - 2u);
      ocspResp[KeyM_Asn1_OCSPElement[asn1ParseParam->asn1_element_idx].refIdxOcspElement].elementLength = 1u;
    }
    /* # Store parsing information for primitive elements */
    else
    {
      ocspResp[KeyM_Asn1_OCSPElement[asn1ParseParam->asn1_element_idx].refIdxOcspElement].elementOffset = (asn1Param->root_tag_base_pos + asn1Param->last_tag_data_pos);
      ocspResp[KeyM_Asn1_OCSPElement[asn1ParseParam->asn1_element_idx].refIdxOcspElement].elementLength = asn1Param->last_tag_len;
    }

    /* # Set flag for each parsed element */
    ocspResp[KeyM_Asn1_OCSPElement[asn1ParseParam->asn1_element_idx].refIdxOcspElement].isPresent = TRUE;
    retVal = KEYM_ASN1_RC_OK;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_CheckParsedOCSPResponderIdTag()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 4 */ /* MD_MSR_STMIF */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckParsedOCSPResponderIdTag(
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) refIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_FAILED;
  uint8 oidLength;
  uint8_least i;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check validity of parsed tag identifier */
  if (((asn1Param->last_tag) == (KEYM_ASN1_TYPE_UTF8))
      || ((asn1Param->last_tag) == (KEYM_ASN1_TYPE_PRINTABLE_STRING)))
  {
    /* # Store parsing information for ResponderId attributes */
    retVal = KeyM_Asn1_StoreOCSPResponderIdParseInfo(asn1Param, ocspResp, refIdx);
  }
  else if ((asn1Param->last_tag) == (KEYM_ASN1_TYPE_OBJECTID))
  {
    /* # Iterate through reference table of ResponderId elements */
    for (i = 0u; i < KEYM_ASN1_OCSP_SIZE_OF_OCSP_RESPONDERID_ELEMENT; i++)
    {
      oidLength = (uint8)(KeyM_Asn1_OCSPResponderIdElement[i].responderIdElementOidEndIdx - KeyM_Asn1_OCSPResponderIdElement[i].responderIdElementOidStartIdx);

      /* # Check object identifier of ResponderId name attributes */
      if ((uint16)oidLength == asn1Param->last_tag_len)
      {
        if (KeyM_Utils_MemCmp(&KeyM_Asn1_ElementOid[KeyM_Asn1_OCSPResponderIdElement[i].responderIdElementOidStartIdx], &asn1Param->base_data_ptr[asn1Param->last_tag_data_pos], (uint32)oidLength))
        {
          /* # Retrieve reference index for parsing information */
          *refIdx = KeyM_Asn1_OCSPResponderIdElement[i].refIdxOcspElement;
          retVal = KEYM_ASN1_RC_OK;
          break;
        }
      }
    }
  }
  else
  {
    /* Current tag doesn't match the expected one */
    retVal = KEYM_ASN1_RC_FAILED;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_CheckParsedOCSPTag()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CheckParsedOCSPTag(
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check validity of parsed tag identifier */
  if ((((asn1Param->last_tag)) == (KeyM_Asn1_OCSPElement[asn1ParseParam->asn1_element_idx].objectTypeOfOcspElement))
      || (((asn1Param->last_tag) & (KEYM_ASN1_CLASS_MASK)) == (KeyM_Asn1_OCSPElement[asn1ParseParam->asn1_element_idx].objectTypeOfOcspElement)))
  {
    retVal = KEYM_ASN1_RC_OK;
  }
  /* # Skip boolean and null elements */
  else if (((asn1Param->last_tag == KEYM_ASN1_TYPE_BOOLEAN) && (asn1Param->remaining_len > 1u))
           || (asn1Param->last_tag == KEYM_ASN1_TYPE_NULL))
  {
    retVal = KEYM_ASN1_RC_PARSE_CHECK_NEXT;
  }
  else
  {
    /* Current tag doesn't match the expected one */
    retVal = KEYM_ASN1_RC_FAILED;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseOCSPResponderIdPrimitiveTag()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPResponderIdPrimitiveTag(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) refIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check parsed primitive tag of ResponderId structure */
  retVal = KeyM_Asn1_CheckParsedOCSPResponderIdTag(asn1Param, ocspResp, refIdx);

  if (retVal == KEYM_ASN1_RC_OK)
  {
    /* Configured certificate element successfully parsed */
    asn1ParseParam->isElementParsed = TRUE;

    if (((asn1Param->last_tag) == (KEYM_ASN1_TYPE_UTF8))
        || ((asn1Param->last_tag) == (KEYM_ASN1_TYPE_PRINTABLE_STRING)))
    {
      asn1ParseParam->asn1_element_idx++;
      /* asn1ParseParam->currentElementIdx is currently unused for OCSP and does not need to be incremented along with asn1_element_idx */
    }
  }
  else
  {
    /* Do nothing */
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseOCSPPrimitiveTag()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPPrimitiveTag(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_FAILED;

  /* ----- Implementation ----------------------------------------------- */
  /* Iterate through configured certificate elements */
  for (asn1ParseParam->asn1_element_idx = asn1ParseParam->currentElementIdx; asn1ParseParam->asn1_element_idx < KEYM_ASN1_OCSP_SIZE_OF_OCSP_RESPONSE_ELEMENT; asn1ParseParam->asn1_element_idx++)
  {
    /* # Check parsed primitive tag of OCSPResponse structure */
    retVal = KeyM_Asn1_CheckParsedOCSPTag(asn1ParseParam, asn1Param);

    if ((retVal == KEYM_ASN1_RC_OK) || (retVal == KEYM_ASN1_RC_PARSE_CHECK_NEXT))
    {
      break;
    }
  }

  if (retVal == KEYM_ASN1_RC_OK)
  {
    /* # Store parsing information */
    retVal = KeyM_Asn1_StoreOCSPParseInfo(asn1ParseParam, asn1Param, ocspResp);

    if (retVal == KEYM_ASN1_RC_OK)
    {
      /* OCSP response element successfully parsed */
      asn1ParseParam->isElementParsed = TRUE;
      asn1ParseParam->parsedElementsCount++;
      asn1ParseParam->parsedElements[asn1ParseParam->asn1_element_idx] = TRUE;
      asn1ParseParam->currentElementIdx = asn1ParseParam->asn1_element_idx + 1u;
    }
  }
  else if (retVal == KEYM_ASN1_RC_PARSE_CHECK_NEXT)
  {
    /* Element is skipped */
    retVal = KEYM_ASN1_RC_OK;
  }
  else
  {
    /* Do nothing */
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseOCSPConstructedTag()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPConstructedTag(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_FAILED;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check nesting level */
  if (asn1ParseParam->asn1_nestingLevel < asn1ParseParam->noOfParseParamDerivedBufferElements)
  {
    /* # Create sub structure for an ASN.1 string out of a root structure. */
    asn1ParseParam->asn1_parseParamDerivedBuffers[(asn1ParseParam->asn1_nestingLevel)] = *asn1Param;
    retVal = KeyM_Asn1_InitDerived(asn1ParseParamBuffer, asn1Param);

    if ((retVal == KEYM_ASN1_RC_OK)
      && ((asn1ParseParam->asn1_nestingLevel + 1u) < KEYM_ASN1_PARSE_MAX_NESTING_LEVEL)) /* check that asn1ParseParam->asn1_nestingLevel++; will still yield a valid value */
    {
      /* # Update working ASN.1 structure */
      asn1ParseParamBuffer->root_tag_base_pos = asn1Param->root_tag_base_pos + asn1Param->current_pos;
      *asn1Param = *asn1ParseParamBuffer;

      asn1ParseParam->asn1_nestingLevel++;
    }
    else
    {
      retVal = KEYM_ASN1_RC_FAILED;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseOCSPResponderIdElementStructure()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPResponderIdElementStructure(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) refIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check current tag type */
  if (asn1Param->last_tag_has_data)
  {
    /* # Parse primitive tag */
    retVal = KeyM_Asn1_ParseOCSPResponderIdPrimitiveTag(asn1ParseParam, asn1Param, ocspResp, refIdx);
  }
  else
  {
    /* # Parse constructed tag */
    retVal = KeyM_Asn1_ParseOCSPConstructedTag(asn1ParseParam, asn1Param, asn1ParseParamBuffer);

  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseOCSPElementStructure()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPElementStructure(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check current tag type whether it is primitive or constructed */
  if (asn1Param->last_tag_has_data)
  {
    /* # Parse primitive tag */
    retVal = KeyM_Asn1_ParseOCSPPrimitiveTag(asn1ParseParam, asn1Param, ocspResp);
  }
  else
  {
    /* Get root element for signature calculation */
    if ((asn1ParseParam->asn1_nestingLevel < asn1ParseParam->noOfParseParamDerivedBufferElements)
        && ((asn1ParseParam->asn1_nestingLevel) == (KEYM_ASN1_OCSP_RESPONSE_ROOT_NL - 1u))
        && ((ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSEDATA].isPresent != TRUE)))
    {
      ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSEDATA].elementOffset = (asn1Param->root_tag_base_pos + asn1Param->last_tag_base_pos);
      ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSEDATA].elementLength = (asn1Param->last_tag_len + asn1Param->current_pos);
      ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSEDATA].isPresent = TRUE;
    }

    /* # Parse constructed tag */
    retVal = KeyM_Asn1_ParseOCSPConstructedTag(asn1ParseParam, asn1Param, asn1ParseParamBuffer);
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_UpdateOCSPAsn1Param()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Asn1_UpdateOCSPAsn1Param(
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_Asn1_ParamType localAsn1Param;
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Handle tag type for octet string */
  if (asn1Param->last_tag == KEYM_ASN1_TYPE_OCTET_STRING)
  {
    retVal = KeyM_Asn1_InitDerived(&localAsn1Param, asn1Param);

    if (retVal == KEYM_ASN1_RC_OK)
    {
      /* # Update working ASN.1 structure */
      localAsn1Param.root_tag_base_pos = asn1Param->root_tag_base_pos + asn1Param->current_pos;

      /* # Get TL information from the current tag */
      retVal = KeyM_Asn1_GetTL(&localAsn1Param);

      if ((retVal == E_OK) && (localAsn1Param.last_tag_len == (asn1Param->last_tag_len - localAsn1Param.current_pos)))
      {
        asn1Param->last_tag_has_data = FALSE;
      }
    }
  }

  /* # Handle constructed OCSP response attributes as primitive ASN.1 elements */
  if (((asn1Param->last_tag == KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_RESPONDERID) && (asn1ParseParam->asn1_nestingLevel == KEYM_ASN1_OCSP_NL_RESPONDERID))
    || ((asn1Param->last_tag == KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_SINGLEEXTENSIONS) && (asn1ParseParam->asn1_nestingLevel == KEYM_ASN1_OCSP_NL_SINGLEEXTENSIONS))
    || ((asn1Param->last_tag == KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_RESPONSEEXTENSIONS) && (asn1ParseParam->asn1_nestingLevel == KEYM_ASN1_OCSP_NL_RESPONSEEXTENSIONS))
    || ((asn1Param->last_tag == KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_CERTSTATUS_GOOD) && (asn1ParseParam->asn1_nestingLevel == KEYM_ASN1_OCSP_NL_CERTSTATUS))
    || ((asn1Param->last_tag == KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_CERTSTATUS_REVOKED) && (asn1ParseParam->asn1_nestingLevel == KEYM_ASN1_OCSP_NL_CERTSTATUS)) /* PRQA S 2996 */ /* MD_KEYM_2.2 */
    || ((asn1Param->last_tag == KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_CERTSTATUS_UNKNOWN) && (asn1ParseParam->asn1_nestingLevel == KEYM_ASN1_OCSP_NL_CERTSTATUS))
    || ((asn1Param->last_tag == KEYM_ASN1_OCSP_CONTEXT_SPECIFIC_TAG_CERTS) && (asn1ParseParam->asn1_nestingLevel == KEYM_ASN1_OCSP_NL_CERTS)))
  {
    asn1Param->last_tag_has_data = TRUE;
  }

  /* # Remap parsed time tag */
  if (asn1Param->last_tag == KEYM_ASN1_TYPE_UTC_TIME)
  {
    asn1Param->last_tag = KEYM_ASN1_TYPE_UTC_GENERALIZED_TIME;
  }
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseOCSPResponderIdElement()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPResponderIdElement(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) refIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get TL information from the current tag */
  retVal = KeyM_Asn1_GetTL(asn1Param);

  /* Parsing successful */
  if (retVal == KEYM_ASN1_RC_OK)
  {
    /* # Parse current tag */
    retVal = KeyM_Asn1_ParseOCSPResponderIdElementStructure(asn1ParseParam, asn1Param, asn1ParseParamBuffer, ocspResp, refIdx);
  }

  if (retVal == KEYM_ASN1_RC_OK)
  {
    /* # Update remaining length and current position */
    KeyM_Asn1_NextTag(asn1Param);
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseOCSPElement()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPElement(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParamBuffer,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get TL information from the current tag */
  retVal = KeyM_Asn1_GetTL(asn1Param);

  /* Parsing successful */
  if (retVal == KEYM_ASN1_RC_OK)
  {
    /* # Update ASN.1 parse structure */
    KeyM_Asn1_UpdateOCSPAsn1Param(asn1ParseParam, asn1Param);

    /* # Parse current tag */
    retVal = KeyM_Asn1_ParseOCSPElementStructure(asn1ParseParam, asn1Param, asn1ParseParamBuffer, ocspResp);
  }

  if (retVal == KEYM_ASN1_RC_OK)
  {
    /* # Update remaining length and current position */
    KeyM_Asn1_NextTag(asn1Param);
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */
#endif

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_StoreRawDataInfo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_StoreRawDataInfo(
  P2CONST(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr,
  KeyM_SizeOfCertificateElementType elementIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_Ans1_Element_Ref_Type elementInfo;

  /* ----- Implementation ----------------------------------------------- */
    /* Handling public key format of CVC certificates, depending on how many elements are present */
  if ((paramDataPtr->last_tag == KeyM_GetObjectTypeOfCertificateElement(elementIdx))
      && ((paramDataPtr->last_tag == KEYM_ASN1_CVC_PUBKEY_SEVERAL_ELEMENTS) || (paramDataPtr->last_tag == KEYM_ASN1_CVC_PUBKEY_ONLY_PUBLIC_POINT)))
  {
    /* Include tag and length fields into element */
    elementInfo.offset = paramDataPtr->root_tag_base_pos + paramDataPtr->last_tag_data_pos - (paramDataPtr->last_tag_data_pos - paramDataPtr->last_tag_base_pos);
    elementInfo.length = paramDataPtr->last_tag_len + (paramDataPtr->last_tag_data_pos - paramDataPtr->last_tag_base_pos);
  }
  else if (KeyM_IsHasIterationOfCertificateElement(elementIdx))
  {
    elementInfo.offset = asn1ParseParam->asn1_parseParamDerivedBuffers[(asn1ParseParam->asn1_nestingLevel - 1u)].root_tag_base_pos + asn1ParseParam->asn1_parseParamDerivedBuffers[(asn1ParseParam->asn1_nestingLevel - 1u)].last_tag_data_pos;
    elementInfo.length = asn1ParseParam->asn1_parseParamDerivedBuffers[(asn1ParseParam->asn1_nestingLevel - 1u)].last_tag_len;
  }
  else
  {
    /* Return the pointer to the data */
    elementInfo.offset = paramDataPtr->root_tag_base_pos + paramDataPtr->last_tag_data_pos;
    elementInfo.length = paramDataPtr->last_tag_len;
  }

  return KeyM_Asn1_SetElementRefInfo(elementIdx, elementInfo, asn1ParseParam->totalDataLength);
} /* KeyM_Asn1_StoreRawDataInfo() */
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_SetElementRefInfo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_SetElementRefInfo(
  KeyM_SizeOfCertificateElementType elementIdx,
  KeyM_Ans1_Element_Ref_Type elementRefInfo,
  uint16 bufferLength)
{
  Std_ReturnType retVal;
  KeyM_ElementStorageRefPtrType elementStoragePtr = KeyM_GetAddrElementStorageRef(elementIdx);

  if ((elementRefInfo.offset + elementRefInfo.length) <= bufferLength)
  {
    elementStoragePtr->length = elementRefInfo.length;
    elementStoragePtr->offset = elementRefInfo.offset;
    retVal = KEYM_ASN1_RC_OK;
  }
  else
  {
    elementStoragePtr->length = 0u;
    elementStoragePtr->offset = 0u;
    retVal = KEYM_ASN1_RC_LEN_OVERFLOW;
  }

  return retVal;
} /* KeyM_Asn1_SetElementRefInfo() */
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InitDerived()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitDerived(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) deriveParamDataPtr,
  P2CONST(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) rootParamDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check remaining length */
  if ((rootParamDataPtr->last_tag_len > rootParamDataPtr->remaining_len) ||
      (rootParamDataPtr->base_data_ptr == NULL_PTR))
  {
    retVal = KEYM_ASN1_RC_FAILED;
  }
  else
  {
    /* # Initialize basic structure */
    /*@ assert rootParamDataPtr->base_data_ptr != NULL_PTR; */ /* VCA_KEYM_ASN1_INITDERIVED_BASEPTR */
    KeyM_Asn1_Init(deriveParamDataPtr, &rootParamDataPtr->base_data_ptr[rootParamDataPtr->last_tag_data_pos], rootParamDataPtr->last_tag_len);
    retVal = KEYM_ASN1_RC_OK;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_GetElementPathByStructureType()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 4 */ /* MD_MSR_STCYC */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_GetElementPathByStructureType(
  KeyM_CertificateStructureType certStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) certElementPath,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) certElementPathDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_OK;
  P2CONST(uint8, AUTOMATIC, KEYM_CONST) certPathPtr = KeyM_Asn1_X509_CertElementPath_Version; /* valid initial value to assist VCA in analysis */
  uint32 certPathLength = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* determine location of requested path */
  switch (certStructure)
  {
  case KEYM_CERTIFICATE_VERSION_NUMBER:
  {
    /* KeyM_Asn1_X509_CertElementPath_Version is already set to KeyM_Asn1_X509_CertElementPath_Version */
    certPathLength = KeyM_SizeOfArray(KeyM_Asn1_X509_CertElementPath_Version);
    break;
  }
  case KEYM_CERTIFICATE_SERIAL_NUMBER:
  {
    certPathPtr = KeyM_Asn1_X509_CertElementPath_SerialNumber;
    certPathLength = KeyM_SizeOfArray(KeyM_Asn1_X509_CertElementPath_SerialNumber);
    break;
  }
  case KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID:
  {
    certPathPtr = KeyM_Asn1_X509_CertElementPath_SignatureAlgorithmId;
    certPathLength = KeyM_SizeOfArray(KeyM_Asn1_X509_CertElementPath_SignatureAlgorithmId);
    break;
  }
  case KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE:
  {
    certPathPtr = KeyM_Asn1_X509_CertElementPath_ValidityPeriodNotBefore;
    certPathLength = KeyM_SizeOfArray(KeyM_Asn1_X509_CertElementPath_ValidityPeriodNotBefore);
    break;
  }
  case KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER:
  {
    certPathPtr = KeyM_Asn1_X509_CertElementPath_ValidityPeriodNotAfter;
    certPathLength = KeyM_SizeOfArray(KeyM_Asn1_X509_CertElementPath_ValidityPeriodNotAfter);
    break;
  }
  case KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM:
  {
    certPathPtr = KeyM_Asn1_X509_CertElementPath_PublicKeyAlgorithm;
    certPathLength = KeyM_SizeOfArray(KeyM_Asn1_X509_CertElementPath_PublicKeyAlgorithm);
    break;
  }
  case KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ECC_CURVE:
  {
    certPathPtr = KeyM_Asn1_X509_CertElementPath_PublicKeyEccCurve;
    certPathLength = KeyM_SizeOfArray(KeyM_Asn1_X509_CertElementPath_PublicKeyEccCurve);
    break;
  }
  case KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY:
  {
    certPathPtr = KeyM_Asn1_X509_CertElementPath_PublicKey;
    certPathLength = KeyM_SizeOfArray(KeyM_Asn1_X509_CertElementPath_PublicKey);
    break;
  }
  case KEYM_CERTIFICATE_SIGNATURE_ALGORITHM:
  {
    certPathPtr = KeyM_Asn1_X509_CertElementPath_SignatureAlgorithm;
    certPathLength = KeyM_SizeOfArray(KeyM_Asn1_X509_CertElementPath_SignatureAlgorithm);
    break;
  }
  case KEYM_CERTIFICATE_SIGNATURE:
  {
    certPathPtr = KeyM_Asn1_X509_CertElementPath_Signature;
    certPathLength = KeyM_SizeOfArray(KeyM_Asn1_X509_CertElementPath_Signature);
    break;
  }
  default:
  {
    /* Certificate structure not handled. */
    retVal = KEYM_ASN1_RC_PARAMETER_MISMATCH;
    break;
  }
  }

  if (retVal == KEYM_ASN1_RC_OK)
  {
    retVal = KeyM_Utils_MemCpyWithSizeCheck(certElementPath, certElementPathDataLength, certPathPtr, certPathLength);
    retVal = KeyM_Asn1_ConvertToAsn1RetVal(retVal);
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
*  KeyM_Asn1_ConvertToKeyMRetVal()
*********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *

 *
 *
*/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ConvertToKeyMRetVal(
  Std_ReturnType asn1RetVal)
{
  Std_ReturnType keyMRetVal;

  switch (asn1RetVal)
  {
    case KEYM_ASN1_RC_OK:
      keyMRetVal = E_OK;
      break;
    case KEYM_ASN1_RC_LEN_OVERFLOW:
      keyMRetVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
      break;
    case KEYM_ASN1_RC_PARAMETER_MISMATCH:
      keyMRetVal = KEYM_E_PARAMETER_MISMATCH;
      break;
    default:
      keyMRetVal = E_NOT_OK;
      break;
  }

  return keyMRetVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
*  KeyM_Asn1_ConvertToAsn1RetVal()
*********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ConvertToAsn1RetVal(
  Std_ReturnType keyMRetVal)
{
  Std_ReturnType asn1RetVal;

  switch (keyMRetVal)
  {
    case E_OK:
      asn1RetVal = KEYM_ASN1_RC_OK;
      break;
    case KEYM_E_KEY_CERT_SIZE_MISMATCH:
      asn1RetVal = KEYM_ASN1_RC_LEN_OVERFLOW;
      break;
    case KEYM_E_PARAMETER_MISMATCH:
      asn1RetVal = KEYM_ASN1_RC_PARAMETER_MISMATCH;
      break;
    default:
      asn1RetVal = KEYM_ASN1_RC_FAILED;
      break;
  }

  return asn1RetVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
*  KeyM_Asn1_GetOidElementDescr()
*********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
*/
KEYM_LOCAL FUNC(P2CONST(KeyM_Asn1_OidElementDescrType, AUTOMATIC, KEYM_CONST), KEYM_CODE) KeyM_Asn1_GetOidElementDescr(
  KeyM_CertificateIdType certId)
{
  P2CONST(KeyM_Asn1_OidElementDescrType, AUTOMATIC, KEYM_CONST) oidDescriptor;

  switch (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId))
  {
    case KEYM_X509:
      oidDescriptor = KeyM_Asn1_OidElementDescr_X509;
      break;
    case KEYM_CRL:
      oidDescriptor = KeyM_Asn1_OidElementDescr_CRL;
      break;
    default:
      oidDescriptor = KeyM_Asn1_OidElementDescr_CVC;
      break;
  }

  return oidDescriptor;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
*  KeyM_Asn1_GetSizeOfOidElementDescr()
*********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
*/
KEYM_LOCAL FUNC(uint8, KEYM_CODE) KeyM_Asn1_GetSizeOfOidElementDescr(
  KeyM_CertificateIdType certId)
{
  uint8 sizeOfOidElementDescr = 0u;

  switch (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId))
  {
    case KEYM_X509:
      sizeOfOidElementDescr = KEYM_ASN1_OID_DESCR_X509_SIZE;
      break;
    case KEYM_CRL:
      sizeOfOidElementDescr = KEYM_ASN1_OID_DESCR_CRL_SIZE;
      break;
    default:
      sizeOfOidElementDescr = KEYM_ASN1_OID_DESCR_CVC_SIZE;
      break;
  }

  return sizeOfOidElementDescr;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
*  KeyM_Asn1_GetSizeOfCertElementDescr()
*********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
*/
KEYM_LOCAL FUNC(uint8, KEYM_CODE) KeyM_Asn1_GetSizeOfCertElementDescr(
  KeyM_CertificateIdType certId)
{
  uint8 sizeOfCertElementDescr = 0u;

  switch (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId))
  {
    case KEYM_X509:
      sizeOfCertElementDescr = KEYM_ASN1_SIZE_OF_X509_CERTELEMENTNESTINGLEVEL;
      break;
    case KEYM_CRL:
      sizeOfCertElementDescr = KEYM_ASN1_SIZE_OF_CRL_CERTELEMENTNESTINGLEVEL;
      break;
    default:
      sizeOfCertElementDescr = KEYM_ASN1_SIZE_OF_CVC_CERTELEMENTNESTINGLEVEL;
      break;
  }

  return sizeOfCertElementDescr;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
*  KeyM_Asn1_GetCertElementDescr()
*********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
*/
KEYM_LOCAL FUNC(P2CONST(KeyM_Asn1_CertElementDescrType, AUTOMATIC, KEYM_CONST), KEYM_CODE) KeyM_Asn1_GetCertElementDescr(
  KeyM_CertificateIdType certId)
{
  P2CONST(KeyM_Asn1_CertElementDescrType, AUTOMATIC, KEYM_CONST) certElementDescriptor;

  switch (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId))
  {
    case KEYM_X509:
      certElementDescriptor = KeyM_Asn1_CertElementDescr_X509;
      break;
    case KEYM_CRL:
      certElementDescriptor = KeyM_Asn1_CertElementDescr_CRL;
      break;
    default:
      certElementDescriptor = KeyM_Asn1_CertElementDescr_CVC;
      break;
  }

  return certElementDescriptor;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_NextTag()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_Asn1_NextTag(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_CONST) asn1Param)
{
  if ((asn1Param->last_tag_valid)
      && (!(asn1Param->current_at_initial_pos))
      && (asn1Param->remaining_len >= asn1Param->last_tag_len))
  {
    asn1Param->remaining_len -= asn1Param->last_tag_len;
    asn1Param->current_pos += asn1Param->last_tag_len;

    asn1Param->current_at_initial_pos = TRUE;
  }
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_GetTL()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_GetTL(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  paramDataPtr->last_tag_valid = FALSE;
  paramDataPtr->last_tag_base_pos = paramDataPtr->current_pos;      /* Base position of current tag */

  /* # Parse tag */
  retVal = KeyM_Asn1_GetTagByte(paramDataPtr, &(paramDataPtr->last_tag), &(paramDataPtr->last_tag_has_data));
  if (retVal == KEYM_ASN1_RC_OK)
  {
    /* # Parse length */
    retVal = KeyM_Asn1_GetLength(paramDataPtr, &(paramDataPtr->last_tag_len));
    if (retVal == KEYM_ASN1_RC_OK)
    {
      paramDataPtr->last_tag_data_pos = paramDataPtr->current_pos;
      paramDataPtr->last_tag_valid = TRUE;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_Init()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_Asn1_Init(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) asn1_data_ptr,
  uint16 asn1_data_len)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Initialize basic structure */
  paramDataPtr->base_data_ptr = asn1_data_ptr;
  paramDataPtr->remaining_len = asn1_data_len;
  paramDataPtr->current_pos = 0;
  paramDataPtr->root_tag_base_pos = 0;
  paramDataPtr->last_tag_valid = FALSE;
  paramDataPtr->current_at_initial_pos = TRUE;
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_Asn1_ParseInit(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseDerivedBuffers,
  uint16 noOfParsedBufferElements)
{
  /* ----- Implementation ----------------------------------------------- */
  asn1ParseParam->asn1_element_idx = 0;
  asn1ParseParam->currentElementIdx = 0;
  asn1ParseParam->asn1_nestingLevel = 0;

  asn1ParseParam->asn1_baseAddress = NULL_PTR;
  asn1ParseParam->asn1_baseLength = 0u;

  asn1ParseParam->asn1_parseParamDerivedBuffers = asn1ParseDerivedBuffers;
  asn1ParseParam->noOfParseParamDerivedBufferElements = noOfParsedBufferElements;

  asn1ParseParam->isTagSkipped = FALSE;
  asn1ParseParam->unsupportedTagCount = 0u;

  asn1ParseParam->isIterableElementIdx = FALSE;
  asn1ParseParam->iterableElementIdx = 0u;

  asn1ParseParam->parsedElementsCount = 0u;
  VStdLib_MemClr(asn1ParseParam->elementPath, KEYM_ASN1_PARSE_MAX_NESTING_LEVEL);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
  asn1ParseParam->refIdx = 0u;
  asn1ParseParam->isOidAvailable = FALSE;
  asn1ParseParam->structureTypeIdx = 0u;
  VStdLib_MemClr(asn1ParseParam->parsedElements, KEYM_MAX_NUM_CERT_ELEMENTS); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseOCSPResponseResponderId()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 4 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPResponseResponderId(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_ParamType asn1ParseParamBuffer;
  uint8 refIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  if (asn1Param->remaining_len == 0u)
  {
    retVal = KEYM_ASN1_RC_FAILED;
  }
  else
  {
    retVal = KeyM_Asn1_GetTL(asn1Param);

    if (retVal == E_OK)
    {
      /* ResponderId byKey */
      if (asn1Param->last_tag == KEYM_ASN1_TYPE_CONTEXT_SPECIFIC_CONSTRUCTED_2)
      {
        /* # Update ASN reader with parsed offset of constructed context specific element */
        KeyM_Asn1_Init(asn1Param, &asn1Param->base_data_ptr[asn1Param->last_tag_data_pos], asn1Param->last_tag_len);
        asn1Param->root_tag_base_pos += asn1Param->last_tag_data_pos; /* PRQA S 2986 */ /* MD_KEYM_2.2 */

        KeyM_Asn1_NextTag(asn1Param);

        /* # Retrieve octet string for key hash */
        retVal = KeyM_Asn1_GetTL(asn1Param);

        if ((retVal == E_OK) && (asn1Param->last_tag == KEYM_ASN1_TYPE_OCTET_STRING))
        {
          ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYKEY].elementOffset = ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID].elementOffset + asn1Param->root_tag_base_pos + asn1Param->last_tag_data_pos;
          ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYKEY].elementLength = asn1Param->last_tag_len;
          ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYKEY].isPresent = TRUE;
        }
      }
      /* ResponderId byName */
      else if (asn1Param->last_tag == KEYM_ASN1_TYPE_CONTEXT_SPECIFIC_CONSTRUCTED_1)
      {
        /* # Iterate through ResponderId elements */
        while ((asn1ParseParam->asn1_element_idx < KEYM_ASN1_OCSP_SIZE_OF_OCSP_RESPONDERID_ELEMENT) && (retVal == KEYM_ASN1_RC_OK))
        {
          KeyM_Asn1_ParseOCSPElementPrepare(asn1ParseParam, asn1Param);

          if (asn1Param->remaining_len == 0u)
          {
            break;
          }

          /* # Iterate through constructed tag */
          while ((asn1Param->remaining_len > 0u) && (!(asn1ParseParam->isElementParsed)))
          {
            /* # Parse OCSP element data */
            retVal = KeyM_Asn1_ParseOCSPResponderIdElement(asn1ParseParam, asn1Param, &asn1ParseParamBuffer, ocspResp, &refIdx);
          }
        }
      }
      else
      {
        retVal = KEYM_ASN1_RC_FAILED;
      }
    }
  }

  return KeyM_Asn1_ConvertToKeyMRetVal(retVal);
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

# ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseOCSPResponse()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 4 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPResponse(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_OK;
  KeyM_Asn1_ParamType asn1ParseParamBuffer;
  uint8 numOfNonOptionalUnparsedElements = 0u;

  /* ----- Implementation ----------------------------------------------- */
  if (asn1Param->remaining_len == 0u)
  {
    retVal = KEYM_ASN1_RC_FAILED;
  }
  else
  {
    /* # Iterate through OCSP Response elements */
    while ((asn1ParseParam->parsedElementsCount < KEYM_ASN1_OCSP_SIZE_OF_OCSP_RESPONSE_ELEMENT) && (retVal == KEYM_ASN1_RC_OK))
    {
      KeyM_Asn1_ParseOCSPElementPrepare(asn1ParseParam, asn1Param);

      /* # Iterate through constructed tag */
      while ((asn1Param->remaining_len > 0u) && (!(asn1ParseParam->isElementParsed)) && (retVal == KEYM_ASN1_RC_OK))
      {
        /* # Parse OCSP element data */
        retVal = KeyM_Asn1_ParseOCSPElement(asn1ParseParam, asn1Param, &asn1ParseParamBuffer, ocspResp);
      }

      if ((asn1Param->remaining_len == 0u) && (asn1ParseParam->asn1_nestingLevel == 0u))
      {
        break;
      }
    }

    if (retVal == KEYM_ASN1_RC_OK)
    {
      /* # Check for unparsed OCSP Response elements */
      if (asn1ParseParam->parsedElementsCount < KEYM_ASN1_OCSP_SIZE_OF_OCSP_RESPONSE_ELEMENT)
      {
        /* Iterate through configured OCSP Response elements */
        for (asn1ParseParam->asn1_element_idx = 0u; asn1ParseParam->asn1_element_idx < KEYM_ASN1_OCSP_SIZE_OF_OCSP_RESPONSE_ELEMENT; asn1ParseParam->asn1_element_idx++)
        {
          if ((asn1ParseParam->parsedElements[asn1ParseParam->asn1_element_idx] == FALSE)
              && (!(KeyM_Asn1_OCSPElement[asn1ParseParam->asn1_element_idx].isOptionalOfOcspElement)))
          {
            /* Count number non-optional unparsed OCSP Response elements */
            numOfNonOptionalUnparsedElements++;
          }
        }

        /* Throw a parsing error for unparsed non-optional OCSP Response elements */
        if (numOfNonOptionalUnparsedElements > 0u)
        {
          retVal = KEYM_ASN1_RC_FAILED;
        }
      }
    }
  }

  return KeyM_Asn1_ConvertToKeyMRetVal(retVal);
}
# endif /* ifndef KEYM_NOUNIT_ASN1PARSER */
#endif

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ParseData()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseData(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  KeyM_SizeOfCertificateElementType elementList,
  KeyM_SizeOfCertificateElementType noOfElementList)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  if (asn1Param->remaining_len == 0u)
  {
    retVal = KEYM_ASN1_RC_FAILED;
  }
  else
  {
    asn1ParseParam->totalDataLength = asn1Param->remaining_len;

    /* # Set pointer to the KEYM_ASN1 element table for the scan process. */
    asn1ParseParam->elementList = elementList;
    asn1ParseParam->noOfElementList = noOfElementList;

    /* # Perform the parse process */
    retVal = KeyM_Asn1_ParseProcessing(certId, asn1ParseParam, asn1Param); /* VCA_KEYM_ASN1_PARSEDATA_PARSEPROCESSING */
  }

  return KeyM_Asn1_ConvertToKeyMRetVal(retVal);
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InitCSR()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6060, 6080 7 */ /* MD_MSR_STCYC, MD_KEYM_6060_LOCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitCSR(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  P2CONST(KeyM_CertElementIdType, AUTOMATIC, KEYM_APPL_DATA) elementIds,
  uint8 numOfReqObjects,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) responseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_ElementType csrInfoDescr[KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_MAX_SIZE];
  KeyM_Asn1_ElementType_Buffer csrInfoDescrAndSize;
  uint8 csrInfoDescrLength = 0u;
  uint8 csrInfoAsn1[KEYM_ASN1_MAX_CSR_SIZE] = { 0u };
  uint8 tmpBuffer[KEYM_ASN1_MAX_CSR_SIZE];
  uint16 nestingLevelDataLength[KEYM_ASN1_PARSE_MAX_NESTING_LEVEL + 2u] = { 0u };
  uint16 tmpBufferLength;
  uint32 csrInfoAsn1Pos = 0u;
  uint8_least i;
  uint8 currentNestingLevel;

  /* ----- Implementation ----------------------------------------------- */
  /* # Init ASN.1 description for CSR Info */
  csrInfoDescrAndSize.data = &csrInfoDescr[0];
  csrInfoDescrAndSize.size = KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_MAX_SIZE;
  retVal = KeyM_Asn1_InitCSRInfo(
    certId,
    csrInfo,
    elementIds,
    numOfReqObjects,
    csrInfoDescrAndSize,
    &csrInfoDescrLength);

  if (retVal == E_OK)
  {
    /* # Build ASN.1 string for CertificationRequestInfo */
    for (i = 0; i < csrInfoDescrLength; i++)
    {
      tmpBufferLength = KEYM_ASN1_MAX_CSR_SIZE;

      currentNestingLevel = csrInfoDescr[i].nestingLevel;
      /*@ assert currentNestingLevel <= KEYM_ASN1_PARSE_MAX_NESTING_LEVEL; */ /* VCA_KEYM_ASN1CSR_NESTINGLEVEL_IS_IN_VALID_RANGE */

      if (KeyM_Asn1_Csr_IsElementConstructed(csrInfoDescr[i].elementType))
      {

        KeyM_Asn1_InsertTagAndLength(
            certId,
            csrInfoDescr[i].elementType,
            nestingLevelDataLength[csrInfoDescr[i].nestingLevel + 1u],
            tmpBuffer,
            &tmpBufferLength);

        /*@ assert tmpBufferLength >= 1; */
        if (csrInfoDescr[i].elementType == KEYM_ASN1_CSR_ELEMENT_CONSTRUCTED_BITSTRING)
        {
          /* Append zero octet */
          tmpBuffer[tmpBufferLength - 1u] += 1u;
          tmpBuffer[tmpBufferLength] = 0x00;
          tmpBufferLength++;
        }

        nestingLevelDataLength[currentNestingLevel] += tmpBufferLength + nestingLevelDataLength[currentNestingLevel + 1u];
        nestingLevelDataLength[currentNestingLevel + 1u] = 0u;
      }
      else
      {
        retVal = KeyM_Asn1_BuildTag(
            certId,
            csrInfoDescr[i].elementType,
            csrInfoDescr[i].dataPtr,
            csrInfoDescr[i].dataLength,
            tmpBuffer,
            &tmpBufferLength);

        if (retVal == KEYM_ASN1_RC_OK)
        {
          nestingLevelDataLength[currentNestingLevel] += tmpBufferLength;
        }
      }

      csrInfoAsn1Pos += tmpBufferLength;

      if ((retVal == KEYM_ASN1_RC_OK) && (csrInfoAsn1Pos > KEYM_ASN1_MAX_CSR_SIZE))
      {
        /* CSR does not fit into the csrInfoAsn1 buffer => abort */
        retVal = KEYM_ASN1_RC_LEN_OVERFLOW;
      }

      if (retVal != KEYM_ASN1_RC_OK)
      {
        break;
      }

      /*@ assert $lengthOf(csrInfoAsn1) >= KEYM_ASN1_MAX_CSR_SIZE; */
      /*@ assert $lengthOf(tmpBuffer)   >= KEYM_ASN1_MAX_CSR_SIZE; */
      VStdLib_MemCpyLarge(&csrInfoAsn1[KEYM_ASN1_MAX_CSR_SIZE - csrInfoAsn1Pos], tmpBuffer, tmpBufferLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_ASN1CSR_MEMCPY_INTO_CSRINFOASN1 */
    }

    if (retVal != E_OK)
    {
      /* Error while filling the responseData buffer */
    }
    else if (csrInfoAsn1Pos <= *responseDataLength)
    {
      /*@ assert responseData != NULL_PTR; */
      /*@ assert $lengthOf(csrInfoAsn1) >= KEYM_ASN1_MAX_CSR_SIZE; */
      VStdLib_MemCpyLarge(responseData, &csrInfoAsn1[KEYM_ASN1_MAX_CSR_SIZE - csrInfoAsn1Pos], csrInfoAsn1Pos); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_ASN1CSR_MEMCPY_CSRINFOASN1_INTO_RESPONSEDATA */
      *responseDataLength = csrInfoAsn1Pos;
      retVal = KEYM_ASN1_RC_OK;
    }
    else
    {
      retVal = KEYM_ASN1_RC_LEN_OVERFLOW;
    }
  }

  return KeyM_Asn1_ConvertToKeyMRetVal(retVal);
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/***********************************************************************************************************************
 *  KeyM_Asn1_GetCsrElementType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6080 4 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_GetCsrElementType(
  KeyM_CertificateIdType certId,
  uint16 elementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) elementType)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_ASN1_RC_FAILED;
  KeyM_SizeOfCertificateElementType elementIdx;
  uint8 oidLengthOfCsrElement;
  uint8_least i;
  boolean certElementExists;

  /* ----- Implementation ----------------------------------------------- */
  certElementExists = KeyM_Cert_IsCertElementAvailable(certId, elementId, &elementIdx);

  if (certElementExists && KeyM_IsElementOidUsedOfCertificateElement(elementIdx))
  {
    /* # Retrieve element type for subject name elements */
    if (KeyM_GetOfStructureOfCertificateElement(elementIdx) == KEYM_CERTIFICATE_SUBJECT_NAME)
    {
      for (i = 0u; i < KEYM_ASN1_SIZE_OF_DN_CSR_ELEMENTS; i++)
      {
        if (KeyM_GetElementOidLengthOfCertificateElement(elementIdx) == (KeyM_Asn1_CsrElement[i].csrElementOidEndIdx - KeyM_Asn1_CsrElement[i].csrElementOidStartIdx))
        {
          oidLengthOfCsrElement = (KeyM_Asn1_CsrElement[i].csrElementOidEndIdx - KeyM_Asn1_CsrElement[i].csrElementOidStartIdx);
          if (KeyM_Utils_MemCmp(KeyM_GetAddrElementOid(KeyM_GetElementOidStartIdxOfCertificateElement(elementIdx)), &KeyM_Asn1_ElementOid[KeyM_Asn1_CsrElement[i].csrElementOidStartIdx], oidLengthOfCsrElement)) /* VCA_KEYM_OID_EXISTENCE_WAS_CHECKED_BEFORE */
          {
            *elementType = KeyM_Asn1_CsrElement[i].elementType;
            retVal = KEYM_ASN1_RC_OK;
            break;
          }
        }
      }
    }
    /* # Retrieve element type for extension elements */
    else if (KeyM_GetOfStructureOfCertificateElement(elementIdx) == KEYM_CERTIFICATE_EXTENSION)
    {
      if (KeyM_GetElementOidLengthOfCertificateElement(elementIdx) == KEYM_ASN1_CSR_UNSTRUCTUREDNAMEOIDDATALENGTH)
      {
        if (KeyM_Utils_MemCmp(KeyM_GetAddrElementOid(KeyM_GetElementOidStartIdxOfCertificateElement(elementIdx)), KeyM_Asn1_Csr_UnstructuredNameOid, KEYM_ASN1_CSR_UNSTRUCTUREDNAMEOIDDATALENGTH)) /* VCA_KEYM_OID_EXISTENCE_WAS_CHECKED_BEFORE */
        {
          *elementType = KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_UNSTRUCTUREDNAME;
          retVal = KEYM_ASN1_RC_OK;
        }
      }

      if ((retVal != KEYM_ASN1_RC_OK) && (KeyM_GetElementOidLengthOfCertificateElement(elementIdx) == KEYM_ASN1_CSR_CHALLENGEPASSWORDOIDDATALENGTH))
      {
        if (KeyM_Utils_MemCmp(KeyM_GetAddrElementOid(KeyM_GetElementOidStartIdxOfCertificateElement(elementIdx)), KeyM_Asn1_Csr_ChallengePassword, KEYM_ASN1_CSR_CHALLENGEPASSWORDOIDDATALENGTH)) /* VCA_KEYM_OID_EXISTENCE_WAS_CHECKED_BEFORE */
        {
          *elementType = KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_CHALLENGEPASSWORD;
          retVal = KEYM_ASN1_RC_OK;
        }
      }

      if (retVal != KEYM_ASN1_RC_OK)
      {
        *elementType = KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_EXTENSION;
        retVal = KEYM_ASN1_RC_OK;
      }
    }
    else
    {
      retVal = KEYM_ASN1_RC_FAILED;
    }
  }

  return KeyM_Asn1_ConvertToKeyMRetVal(retVal); /* PRQA S 2998, 2996 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_IsCsrElementAttribute()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_IsCsrElementAttribute(
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(boolean, AUTOMATIC, KEYM_APPL_VAR) isAttribute)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (isAttribute == NULL_PTR)
  {
    /* Precondition was violated */
    retVal = E_NOT_OK;
  }
  else if (elementIdx >= KeyM_GetSizeOfCertificateElement())
  {
    /* Element at given index does not exist */
    retVal = E_NOT_OK;
  }
  else if (KeyM_GetOfStructureOfCertificateElement(elementIdx) != KEYM_CERTIFICATE_EXTENSION)
  {
    /* Not an extension element - this cannot be an attribute. */
    retVal = E_OK;
    *isAttribute = FALSE;
  }
  else if (!KeyM_IsElementOidUsedOfCertificateElement(elementIdx))
  {
    /* Any extension element must have an OID configured. This element is invalid. */
    retVal = E_NOT_OK;
  }
  else
  {
    retVal = E_OK;
    *isAttribute = FALSE;

    /* # Check whether CSR element is an unstructured name */
    if (KeyM_GetElementOidLengthOfCertificateElement(elementIdx) == KEYM_ASN1_CSR_UNSTRUCTUREDNAMEOIDDATALENGTH)
    {
      if (KeyM_Utils_MemCmp(KeyM_GetAddrElementOid(KeyM_GetElementOidStartIdxOfCertificateElement(elementIdx)), KeyM_Asn1_Csr_UnstructuredNameOid, KEYM_ASN1_CSR_UNSTRUCTUREDNAMEOIDDATALENGTH)) /* VCA_KEYM_OID_EXISTENCE_WAS_CHECKED_BEFORE */
      {
        *isAttribute = TRUE;
      }
    }

    /* # Check whether CSR element is a challenge password */
    if ((*isAttribute != TRUE) && (KeyM_GetElementOidLengthOfCertificateElement(elementIdx) == KEYM_ASN1_CSR_CHALLENGEPASSWORDOIDDATALENGTH))
    {
      if (KeyM_Utils_MemCmp(KeyM_GetAddrElementOid(KeyM_GetElementOidStartIdxOfCertificateElement(elementIdx)), KeyM_Asn1_Csr_ChallengePassword, KEYM_ASN1_CSR_CHALLENGEPASSWORDOIDDATALENGTH)) /* VCA_KEYM_OID_EXISTENCE_WAS_CHECKED_BEFORE */
      {
        *isAttribute = TRUE;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */

# ifndef KEYM_NOUNIT_ASN1CSR /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_BuildCSR()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6050, 6030, 6080 6 */ /* MD_MSR_STPTH, MD_MSR_STCAL, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_BuildCSR(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint16 requestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  uint32 responseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_CsrType certReqInfo;
  KeyM_Asn1_CsrType certReq;

#  if ((KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON) || (KEYM_RTECALLBACKNOTIFICATION == STD_ON))
  KeyM_ResultType serviceResult;
#  endif

  /* ----- Implementation ----------------------------------------------- */
  if (requestDataLength > KEYM_ASN1_MAX_CSR_SIZE)
  {
    retVal = KEYM_ASN1_RC_LEN_OVERFLOW;
  }
  else
  {
    KeyM_Asn1_SignatureType sig;
    sig.primaryDataLength = 0;
    sig.secondaryDataLength = 0;

    /* # Copy CertificationRequestInfo */
    VStdLib_MemCpyLarge(certReqInfo.data, requestData, requestDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    certReqInfo.dataLength = requestDataLength;

    /* # Generate Signature */
    retVal = KeyM_Asn1_SignatureGenerate(certId, &certReqInfo, &sig);

    if (retVal == E_OK)
    {
#  if ((KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON) || (KEYM_RTECALLBACKNOTIFICATION == STD_ON))
      serviceResult = KEYM_RT_OK;
#  endif
      /* # Build CertificationRequest */
      certReq.dataLength = 0;
      retVal = KeyM_Asn1_BuildCertificationRequest(certId, &certReqInfo, &sig, &certReq);

      if (retVal != KEYM_ASN1_RC_OK)
      {
        /* could not build CSR - leave the return value as is */
      }
      else if (certReq.dataLength > responseDataLength)
      {
        /* caller's buffer is too small to hold the generated CSR */
        retVal = KEYM_ASN1_RC_LEN_OVERFLOW;
      }
      else
      {
        /*@ assert $lengthOf(certReq.data) >= KEYM_ASN1_MAX_CSR_SIZE; */
        /*@ assert certReq.dataLength <= KEYM_ASN1_MAX_CSR_SIZE; */
        VStdLib_MemCpyLarge(responseData, &(certReq.data[KEYM_ASN1_MAX_CSR_SIZE - certReq.dataLength]), certReq.dataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_ASN1CSR_MEMCPY_CERTREQ_INTO_RESPONSEDATA */

        /* # Notify application and return CSR */
#  if (KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON)
        /* Call CallbackNotification for application */
        if (KeyM_IsServiceCertificateCallbackNotificationUsedOfCertificate((KeyM_CertificateIterType)certId))
        {
          KeyM_ServiceCertificateCallbackNotificationIdxOfCertificateType callbackIdx;
          KeyM_ServiceCertificateCallbackNotificationFctPtrType callbackFunction;

          callbackIdx = KeyM_GetServiceCertificateCallbackNotificationIdxOfCertificate((KeyM_CertificateIterType)certId);
          /*@ assert callbackIdx < KeyM_GetSizeOfServiceCertificateCallbackNotification(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

          callbackFunction = KeyM_GetServiceCertificateCallbackNotification(callbackIdx);

#   ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
          /* VCA does not analyze customer-provided callbacks. The API contract for customer-provided callbacks is
           * annotated in the VCA stub. So no problems can arise with customer-provided callbacks if they uphold the
           * API contract. */
          callbackFunction = &Vcastub_Appl_ServiceCertificateCallbackNotification;
#   endif

          /*@ assert certId < KeyM_GetSizeOfCertificate(); */
          /*@ assert certReq.data != NULL_PTR; */
          callbackFunction(certId, serviceResult, certReq.dataLength, &(certReq.data[KEYM_ASN1_MAX_CSR_SIZE - certReq.dataLength])); /* VCA_KEYM_SERVICECERT_CALLBACK_NOTIFICATION */
        }
        else
#  endif
        {
#  if (KEYM_RTECALLBACKNOTIFICATION == STD_ON)
          if (KeyM_IsRteCallbackNotificationUsedOfCertificate((KeyM_CertificateIterType)certId))
          {
            KeyM_RteCallbackNotificationIdxOfCertificateType callbackIdx;
            KeyM_ServiceCertificateRteCallbackNotificationFctPtrType callbackFunction;

            callbackIdx = KeyM_GetRteCallbackNotificationIdxOfCertificate((KeyM_CertificateIterType)certId);
            /*@ assert callbackIdx < KeyM_GetSizeOfRteCallbackNotification(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

            callbackFunction = KeyM_GetServiceCertificateOfRteCallbackNotification(callbackIdx);

#   ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
            /* VCA does not analyze customer-provided callbacks. The API contract for customer-provided callbacks is
             * annotated in the VCA stub. So no problems can arise with customer-provided callbacks if they uphold the
             * API contract. */
            callbackFunction = &Vcastub_Appl_ServiceCertificateRteCallbackNotification;
#   endif

            /*@ assert certReq.data != NULL_PTR; */
            (void)callbackFunction(serviceResult, certReq.dataLength, &(certReq.data[KEYM_ASN1_MAX_CSR_SIZE - certReq.dataLength]));
          }
#  endif
        }
      }
    }
  }

  return KeyM_Asn1_ConvertToKeyMRetVal(retVal); /* PRQA S 2998, 2996 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
}
# endif /* ifndef KEYM_NOUNIT_ASN1CSR */
#endif

#ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_INTERNAL_STUB */
/**********************************************************************************************************************
 *  KeyM_Asn1_GetDynamicIssuerCertIdVcaStub()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_Asn1_GetDynamicIssuerCertIdVcaStub(void)
{
# if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON) /* COV_KEYM_VECTOR_CODE_ANALYZER_INTERNAL_STUB */
  KeyM_Asn1_PubKeyLength = (uint32)$undef();
  KeyM_Asn1_SecondaryPubKeyLength = (uint32)$undef();
  KeyM_Asn1_PubKeyBuffer[$range(0u, sizeof(KeyM_Asn1_PubKeyBuffer) - 1u)] = (uint8)$undef();
  KeyM_Asn1_SecondaryPubKeyBuffer[$range(0u, sizeof(KeyM_Asn1_SecondaryPubKeyBuffer) - 1u)] = (uint8)$undef();
# endif
} /* KeyM_Asn1_GetDynamicIssuerCertIdVcaStub() */
#endif

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_InitElementStorage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_Asn1_InitElementStorage(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_ElementStorageRefIterType elementIdx;

  /* ----- Implementation ----------------------------------------------- */
  for (elementIdx = 0u; elementIdx < KeyM_GetSizeOfElementStorageRef(); elementIdx++)
  {
    KeyM_ElementStorageRefPtrType elementStoragePtr = KeyM_GetAddrElementStorageRef(elementIdx);

    elementStoragePtr->length = 0u;
    elementStoragePtr->offset = 0u;
  }
} /* KeyM_Asn1_InitElementStorage */
#endif /* KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_ClearCertificateElementStorage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_Asn1_ClearCertificateElementStorage(KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_ElementStorageRefIterType elementIdx;

  /* ----- Implementation ----------------------------------------------- */
  for (elementIdx = KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)certId); elementIdx < KeyM_GetCertificateElementEndIdxOfCertificate((KeyM_CertificateIterType)certId); elementIdx++)
  {
    KeyM_ElementStorageRefPtrType elementStoragePtr = KeyM_GetAddrElementStorageRef(elementIdx);

    elementStoragePtr->length = 0u;
    elementStoragePtr->offset = 0u;
  }
} /* KeyM_Asn1_ClearCertificateElementStorage */
#endif /* KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Asn1_CertElementGetByStructureType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6080 6 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CertElementGetByStructureType(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  KeyM_CertificateStructureType certStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) certElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) certElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) basePtr =  asn1Param->base_data_ptr;
  KeyM_Asn1_ParamType asn1ParseParamBuffer = { 0u };
  uint32 elementDataLength = 0u;
  uint32 certElementPathDataLength = KEYM_ASN1_PARSE_MAX_NESTING_LEVEL;
  uint16 elementOffset = 0u;
  uint8 certElementPathLevel = 0u;
  uint8 certElementPath[KEYM_ASN1_PARSE_MAX_NESTING_LEVEL] = { 0u };
  uint32_least i = 0u;
  uint32_least j = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve certificate element specific path according to referenced certificate structure type */
  retVal = KeyM_Asn1_GetElementPathByStructureType(certStructure, certElementPath, &certElementPathDataLength);

  /* Iterate through all nesting levels of given certificate element path */
  for (i = 0u; (i < certElementPathDataLength) && (retVal == KEYM_ASN1_RC_OK); i++)
  {
    retVal = KeyM_Asn1_GetTL(asn1Param);

    if (retVal != KEYM_ASN1_RC_OK)
    {
      break;
    }

    asn1ParseParam->elementPath[asn1ParseParam->asn1_nestingLevel]++;

    /* Current certificate element level needs to be incremented if an optional version element is available in certificate data */
    if ((asn1ParseParam->asn1_nestingLevel == 2u) && (asn1Param->last_tag == KEYM_ASN1_TYPE_CONTEXT_SPECIFIC_CONSTRUCTED_0) && (certStructure != KEYM_CERTIFICATE_VERSION_NUMBER))
    {
      certElementPathLevel = certElementPath[i] + 1u;
    }
    else
    {
      certElementPathLevel = certElementPath[i];
    }

    /* Iterate through ASN.1 elements for current nesting level */
    for (j = 0u; j < certElementPathLevel; j++)
    {
      /* Check if the current nesting level matches element path for requested certificate element */
      if (asn1ParseParam->elementPath[i] == certElementPathLevel)
      {
        /* If last element path nesting level is reached and parsed tag is primitive, element data can be retrieved */
        if (i == (certElementPathDataLength - 1u))
        {
          if  (asn1Param->last_tag_has_data == TRUE)
          {
            /* Retrieve parse information for requested certificate element */
            if((certStructure == KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY) || (certStructure == KEYM_CERTIFICATE_SIGNATURE))
            {
              /* In case of public key or signature request, the complete constructed BITSTRING ASN.1 data is retrieved */
              elementOffset = asn1Param->root_tag_base_pos + asn1Param->last_tag_data_pos - (asn1Param->last_tag_data_pos - asn1Param->last_tag_base_pos);
              elementDataLength = (uint32)(asn1Param->last_tag_len) + ((uint32)(asn1Param->last_tag_data_pos) - (uint32)(asn1Param->last_tag_base_pos));
            }
            else
            {
              elementOffset = asn1Param->root_tag_base_pos + asn1Param->last_tag_data_pos;
              elementDataLength = (uint32)(asn1Param->last_tag_len);
            }

            /* Check for size mismatch */
            if (elementDataLength > *certElementDataLength)
            {
              retVal = KEYM_ASN1_RC_LEN_OVERFLOW;
            }
            else
            {
              /* Copy certificate element data to output buffer */
              /*@ assert basePtr != NULL_PTR; */
              /*@ assert certElementData != NULL_PTR; */
              VStdLib_MemCpyLarge(certElementData, &basePtr[elementOffset], elementDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_ASN1_CERTELEMENTGETBYSTRUCTURETYPE_MEMCPY */
              *certElementDataLength = elementDataLength;
            }
          }
          else
          {
            retVal = E_NOT_OK;
          }
        }
        else
        {
          /* Else, parse constructed tag and continue one nesting level deeper */
          retVal = KeyM_Asn1_ParseConstructedTag(asn1ParseParam, asn1Param, &asn1ParseParamBuffer);
        }
      }
      else
      {
        /* Parse next ASN.1 tag and increment element path value for current netsting level*/
        /*@ assert asn1ParseParam->asn1_nestingLevel < KEYM_ASN1_PARSE_MAX_NESTING_LEVEL; */
        KeyM_Asn1_NextTag(asn1Param);
        asn1ParseParam->elementPath[asn1ParseParam->asn1_nestingLevel]++;

        retVal = KeyM_Asn1_GetTL(asn1Param);
      }

      if (retVal != KEYM_ASN1_RC_OK)
      {
        break;
      }
    }
  }

  return KeyM_Asn1_ConvertToKeyMRetVal(retVal);
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#ifndef KEYM_NOUNIT_ASN1PARSER /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
*  KeyM_Asn1_GetAlgoType()
*********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
*/
FUNC(uint16, KEYM_CODE) KeyM_Asn1_GetAlgoType(
  KeyM_CertificateIdType certId)
{
  KeyM_CertFormatTypeOfCertificateType certFormat = KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId);
  KeyM_CertAlgorithmFamilyOfCertificateType certAlgoFamily = KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId);

  return (uint16)((((uint16)certFormat) << 8u) | ((uint16)certAlgoFamily));
}
#endif /* ifndef KEYM_NOUNIT_ASN1PARSER */

#define KEYM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/
