/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  KeyM_Asn1.h
 *         \unit  *
 *        \brief  Header file of the ASN.1 parser
 *      \details  Implementation of ASN1 Certificate Parsing Submodule
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined KEYM_ASN1_H
# define KEYM_ASN1_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "KeyM.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ---- KEYM_ASN1 tag BER encoded definition ---- */
# define KEYM_ASN1_TYPE_UNKNOWN                                       (0x00u)
# define KEYM_ASN1_TYPE_BOOLEAN                                       (0x01u)
# define KEYM_ASN1_TYPE_INTEGER                                       (0x02u)
# define KEYM_ASN1_TYPE_BIT_STRING                                    (0x03u)
# define KEYM_ASN1_TYPE_OCTET_STRING                                  (0x04u)
# define KEYM_ASN1_TYPE_NULL                                          (0x05u)
# define KEYM_ASN1_TYPE_OBJECTID                                      (0x06u)
# define KEYM_ASN1_TYPE_ENUMERATED                                    (0x0Au)
# define KEYM_ASN1_TYPE_UTF8                                          (0x0Cu)
# define KEYM_ASN1_TYPE_PRINTABLE_STRING                              (0x13u)
# define KEYM_ASN1_TYPE_IA5_STRING                                    (0x16u)
# define KEYM_ASN1_TYPE_BMPSTRING                                     (0x1Eu)
# define KEYM_ASN1_TYPE_SEQUENCE                                      (0x10u)
# define KEYM_ASN1_TYPE_SET                                           (0x11u)
# define KEYM_ASN1_TYPE_UTC_TIME                                      (0x17u)
# define KEYM_ASN1_TYPE_UTC_GENERALIZED_TIME                          (0x18u)

/* ---- KEYM_ASN1 context specific tags for constructed elements ---- */
# define KEYM_ASN1_TYPE_CONTEXT_SPECIFIC_CONSTRUCTED_0                (0xa0u)
# define KEYM_ASN1_TYPE_CONTEXT_SPECIFIC_CONSTRUCTED_1                (0xa1u)
# define KEYM_ASN1_TYPE_CONTEXT_SPECIFIC_CONSTRUCTED_2                (0xa2u)

/* ---- KEYM_ASN1 tag DER encoded definition ---- */
# define KEYM_ASN1_CVC_TAG_CERTIFICATION_AUTHORITY_REFERENCE          (0x42u)
# define KEYM_ASN1_CVC_TAG_DISCRETIONARY_DATA                         (0x53u)
# define KEYM_ASN1_CVC_TAG_CERTIFICATE_HOLDER_REFERENCE               (0x5F20u)
# define KEYM_ASN1_CVC_TAG_CERTIFICATE_EXPIRATION_DATE                (0x5F24u)
# define KEYM_ASN1_CVC_TAG_CERTIFICATE_EFFECTIVE_DATE                 (0x5F25u)
# define KEYM_ASN1_CVC_TAG_CERTIFICATE_PROFILE_IDENTIFIER             (0x5F29u)
# define KEYM_ASN1_CVC_TAG_SIGNATURE                                  (0x5F37u)
# define KEYM_ASN1_CVC_TAG_CERTIFICATE_EXTENSIONS                     (0x65u)
# define KEYM_ASN1_CVC_TAG_AUTHENTICATION                             (0x67u)
# define KEYM_ASN1_CVC_TAG_DISCRETIONARY_DATA_TEMPLATE                (0x73u)
# define KEYM_ASN1_CVC_TAG_CV_CERTIFICATE                             (0x7F21u)
# define KEYM_ASN1_CVC_TAG_PUBLIC_KEY                                 (0x7F49u)
# define KEYM_ASN1_CVC_TAG_CERTIFICATE_HOLDER_AUTHORIZATION_TEMPLATE  (0x7F4Cu)
# define KEYM_ASN1_CVC_TAG_CERTIFICATE_BODY                           (0x7F4Eu)

/* User specific class types */
# define KEYM_ASN1_TYPE_USER_CONTEXT                                  (0x80u)
# define KEYM_ASN1_TYPE_USER_PRIVATE                                  (0xC0u)

/* KEYM_ASN1 classes (two MSBs of tag byte)  */
# define KEYM_ASN1_CLASS_MASK                                         (0xC0u)
# define KEYM_ASN1_CLASS_UNIVERSAL                                    (0x00u)
# define KEYM_ASN1_CLASS_APPLICATION                                  (0x40u)
# define KEYM_ASN1_CLASS_CONTEXT_SPECIFIC                             (0x80u)
# define KEYM_ASN1_CLASS_PRIVATE                                      (0xC0u)

/* KEYM_ASN1 primitive/constructed flag */
# define KEYM_ASN1_TAG_CONSTRUCTED                                    (0x20u)

/* KEYM_ASN1 tag length */
# define KEYM_ASN1_TAG_LENGTH_MASK                                    (0x1Fu)
# define KEYM_ASN1_TAG_LENGTH                                         (0x1Fu)

/* KEYM_ASN1 tag mask for universal tag number (excludes class and constructed flag) */
# define KEYM_ASN1_TAG_NUMBER_MASK                                    (0x1Fu)
# define KEYM_ASN1_TAG_TWO_OCTETS_NUMBER_MASK                         (0xFFu)

/* ----- Modes ----- */
# define KEYM_ASN1_MODULE_UNINIT                                      (0x00u)
# define KEYM_ASN1_MODULE_INIT                                        (0x01u)

# define KEYM_ASN1_RC_OK                                              E_OK
# define KEYM_ASN1_RC_FAILED                                          E_NOT_OK
# define KEYM_ASN1_RC_LEN_OVERFLOW                                    (0x02u)
# define KEYM_ASN1_RC_PARSE_CHECK_NEXT                                (0x03u)
# define KEYM_ASN1_RC_UNSUPPORTED_TAG                                 (0x04u)
# define KEYM_ASN1_RC_PARAMETER_MISMATCH                              (0x05u)

# define KEYM_ASN1_PARSE_MAX_NESTING_LEVEL                            KEYM_PARSE_MAX_NESTING_LEVEL

/* Certificate signing request */
# if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
#  define KEYM_ASN1_MAX_CSR_SIZE                                      (KEYM_MAX_CERTIFICATE_MAX_LENGTH)
#  define KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_EXTENSIONS     ((KEYM_MAX_NUM_CSR_EXTENSIONS * 3u) + 4u)
#  define KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_ATTRIBUTES     (9u)
#  define KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_PUBKEY         (8u)
#  define KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_SUBJECTNAME    ((KEYM_MAX_NUM_SUBJECT_NAME_COMPONENTS * 4u) + 1u)
#  define KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_VERSION        (8u)
#  define KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_SEQUENCE       (8u)
#  define KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_MAX_SIZE       (KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_EXTENSIONS \
                                                                      + KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_ATTRIBUTES \
                                                                      + KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_PUBKEY \
                                                                      + KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_SUBJECTNAME \
                                                                      + KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_VERSION \
                                                                      + KEYM_ASN1_CSR_CERTIFICATIONREQUESTINFO_DESCR_SEQUENCE)
#  define KEYM_ASN1_CSR_CERTIFICATIONREQUEST_DESCR_MAX_SIZE           (10u)
#  define KEYM_ASN1_SIZE_OF_DN_CSR_ELEMENTS                           (14u)
# endif

# if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSESTATUS                           (0x00u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSETYPE                             (0x01u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSEDATA                             (0x02u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_VERSION                                  (0x03u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID                              (0x04u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_COUNTRYNAME           (0x05u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_STATEORPROVINCENAME   (0x06u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_LOCALITYNAME          (0x07u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_ORGANIZATIONNAME      (0x08u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_ORGANIZATIONUNITNAME  (0x09u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_COMMONNAME            (0x0Au)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_SURNAME               (0x0Bu)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_SERIALNUMBER          (0x0Cu)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_STREETADDRESS         (0x0Du)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_TITLE                 (0x0Eu)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_GIVENNAME             (0x0Fu)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_EMAIL                 (0x10u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_USERID                (0x11u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_DOMAINCOMPONENT       (0x12u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYKEY                        (0x13u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_PRODUCEDAT                               (0x14u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_HASHALGORITHM                     (0x15u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_ISSUERNAMEHASH                    (0x16u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_ISSUERKEYHASH                     (0x17u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_SERIALNUMBER                      (0x18u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTSTATUS                               (0x19u)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_THISUPDATE                               (0x1au)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_NEXTUPDATE                               (0x1bu)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_SINGLEEXTENSIONS                         (0x1cu)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSEEXTENSIONS                       (0x1du)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_SIGNATUREALGORITHM                       (0x1eu)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_SIGNATURE                                (0x1fu)
#  define KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTS                                    (0x20u)

#  define KEYM_ASN1_OCSP_RESPONSE_STATUS_SUCCESSFUL                               (0x00u)
#  define KEYM_ASN1_OCSP_RESPONSE_STATUS_MALFORMEDREQUEST                         (0x01u)
#  define KEYM_ASN1_OCSP_RESPONSE_STATUS_INTERNALERROR                            (0x02u)
#  define KEYM_ASN1_OCSP_RESPONSE_STATUS_TRYLATER                                 (0x03u)
#  define KEYM_ASN1_OCSP_RESPONSE_STATUS_SIGREQUIRED                              (0x05u)
#  define KEYM_ASN1_OCSP_RESPONSE_STATUS_UNAUTHORIZED                             (0x06u)

#  define KEYM_ASN1_OCSP_CERT_STATUS_GOOD                                         (0x80u)
#  define KEYM_ASN1_OCSP_CERT_STATUS_REVOKED                                      (0xa1u)
#  define KEYM_ASN1_OCSP_CERT_STATUS_UNKNOWN                                      (0x82u)
# endif

/*! This algorithm type combines the certificate format and signature format into one single value for easy handling in switch statements */
# define KEYM_ASN1_ALGO_X509_EDDSA                                                ((uint16)(((uint16)KEYM_X509 << 8u) | ((uint16)KEYM_EDDSA)))
# define KEYM_ASN1_ALGO_X509_ECDSA                                                ((uint16)(((uint16)KEYM_X509 << 8u) | ((uint16)KEYM_ECDSA)))
# define KEYM_ASN1_ALGO_X509_RSA                                                  ((uint16)(((uint16)KEYM_X509 << 8u) | ((uint16)KEYM_RSA  )))
# define KEYM_ASN1_ALGO_CVC_EDDSA                                                 ((uint16)(((uint16)KEYM_CVC  << 8u) | ((uint16)KEYM_EDDSA)))
# define KEYM_ASN1_ALGO_CVC_ECDSA                                                 ((uint16)(((uint16)KEYM_CVC  << 8u) | ((uint16)KEYM_ECDSA)))
# define KEYM_ASN1_ALGO_CVC_RSA                                                   ((uint16)(((uint16)KEYM_CVC  << 8u) | ((uint16)KEYM_RSA  )))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/* KEYM_ASN1 primary parameter structure definition */
typedef struct
{
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) base_data_ptr; /**< Points to the root of the KEYM_ASN1 string */
  uint16 remaining_len;                                   /**< remaining data len of the currently processed KEYM_ASN1 string */
  uint16 current_pos;                                     /**< Current position where KEYM_ASN1 string is processed on */
  uint16 last_tag_len;                                    /**< Current tag data len */
  uint16 last_tag_data_pos;                               /**< The position of the data of the current tag */
  uint16 last_tag_base_pos;                               /**< The position of the tag, actually where the currently processed tag starts */
  uint16 root_tag_base_pos;                               /**< Relative Position to the root sequence */
  uint8 last_tag;                                         /**< Current tag value */
  boolean last_tag_valid;                                 /**< Indicator if the last_* values are valid or not */
  boolean last_tag_has_data;                              /**< If tag has data, resp. if it is !constructed */
  boolean current_at_initial_pos;                         /**< current_pos points to an initial position of a TLV */
} KeyM_Asn1_ParamType;

/* KEYM_ASN1 struct definition for the parsing process */
/* This requires a list of elements that contains data */

/* \spec weak type invariant () { self.asn1_nestingLevel < KEYM_ASN1_PARSE_MAX_NESTING_LEVEL }; \endspec */
typedef struct
{
  P2VAR(KeyM_Asn1_ParamType, KEYM_APPL_VAR, KEYM_APPL_VAR) asn1_parseParamDerivedBuffers;
  P2CONST(uint8, KEYM_APPL_VAR, AUTOMATIC) asn1_baseAddress;
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) refOidDataPtr;
  uint16 totalDataLength;
  uint16 asn1_baseLength;
  uint16 asn1_nestingLevel;
  KeyM_SizeOfCertificateElementType asn1_element_idx; /* 0-based index of "the how-many-th element is currently parsed" */
  KeyM_SizeOfCertificateElementType iterableElementIdx;
  KeyM_SizeOfCertificateElementType parsedElementsCount;
  uint16 noOfParseParamDerivedBufferElements;
  uint16 refOidDataLength;
  uint16 unsupportedTagCount;
  KeyM_SizeOfCertificateElementType noOfElementList;
  KeyM_SizeOfCertificateElementType elementList;
  KeyM_SizeOfCertificateElementType currentElementIdx; /* index of current KeyM_CertificateElement, starting at elementList */
  uint8 elementPath[KEYM_ASN1_PARSE_MAX_NESTING_LEVEL];
  uint8 refIdx;
  uint8 structureTypeIdx;
  boolean parsedElements[KEYM_MAX_NUM_CERT_ELEMENTS];
  boolean isOidAvailable;
  boolean isElementParsed;
  boolean isTagSkipped;
  boolean isIterableElementIdx;
} KeyM_Asn1_ParseType;

# if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/*! \spec weak type invariant () { self.dataLength <= $lengthOf(self.dataPtr) };
 *        weak type invariant () { self.nestingLevel <= KEYM_ASN1_PARSE_MAX_NESTING_LEVEL };                 \endspec */
typedef struct
{
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) dataPtr;
  uint16 dataLength;
  uint8 nestingLevel;
  uint8 elementType;
} KeyM_Asn1_ElementType;

typedef struct
{
  P2VAR(KeyM_Asn1_ElementType, AUTOMATIC, KEYM_APPL_VAR) data;
  uint8 size;
} KeyM_Asn1_ElementType_Buffer;

/*! \spec weak type invariant () { self.dataLength <= $lengthOf(self.data) };                                \endspec */
typedef struct
{
  uint16 dataLength;
  uint8 data[KEYM_ASN1_MAX_CSR_SIZE];
} KeyM_Asn1_CsrType;

/*! \spec weak type invariant () { self.primaryDataLength   <= $lengthOf(self.primaryData) };
 *        weak type invariant () { self.secondaryDataLength <= $lengthOf(self.secondaryData) };              \endspec */
typedef struct
{
  uint16 primaryDataLength;
  uint16 secondaryDataLength;
  uint8 primaryData[KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH];
  uint8 secondaryData[KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH];
} KeyM_Asn1_SignatureType;
# endif

# if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
typedef struct
{
  uint16 elementOffset;
  uint16 elementLength;
  boolean isPresent;
} KeyM_Asn1_OCSPResponseElementInfoType;

typedef struct
{
  KeyM_Asn1_OCSPResponseElementInfoType responseStatus;
  KeyM_Asn1_OCSPResponseElementInfoType responseType;

  KeyM_Asn1_OCSPResponseElementInfoType version;
  KeyM_Asn1_OCSPResponseElementInfoType responderId;
  KeyM_Asn1_OCSPResponseElementInfoType producedAt;
  KeyM_Asn1_OCSPResponseElementInfoType certId_hashAlgorithm;
  KeyM_Asn1_OCSPResponseElementInfoType certId_issuerNameHash;
  KeyM_Asn1_OCSPResponseElementInfoType certId_issuerKeyHash;
  KeyM_Asn1_OCSPResponseElementInfoType certId_serialNumber;
  KeyM_Asn1_OCSPResponseElementInfoType certStatus;
  KeyM_Asn1_OCSPResponseElementInfoType thisUpdate;
  KeyM_Asn1_OCSPResponseElementInfoType nextUpdate;
  KeyM_Asn1_OCSPResponseElementInfoType singleExtensions;
  KeyM_Asn1_OCSPResponseElementInfoType responseExtensions;
  KeyM_Asn1_OCSPResponseElementInfoType signatureAlgorithm;
  KeyM_Asn1_OCSPResponseElementInfoType signature;
  KeyM_Asn1_OCSPResponseElementInfoType certs;

} KeyM_Asn1_OCSPResponseDescriptionType;
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define KEYM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * KeyM_Asn1_NextTag()
 *********************************************************************************************************************/
/*! \brief         Advances parameter in asn1Param to walk to the next ASN tag.
 *  \details       -
 *  \param[in,out] asn1Param   Pointer to the ASN descriptor
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires asn1Param != NULL_PTR;                                                             \endspec
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Asn1_NextTag(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_CONST) asn1Param);

/*****************************************************************************M*****************************************
 * KeyM_Asn1_Init()
 **********************************************************************************************************************/
/*! \brief         Initialization function.
 *  \details       This function initializes the Asn1 module. It initializes all variables and and sets the module state to
 *                 initialized.
 *  \param[in,out] paramDataPtr    Pointer to the ASN.1 element descriptor.
 *  \param[in]     asn1_data_ptr   Pointer to certificate data.
 *  \param[in]     asn1_data_len   Certificate data length.
 *  \pre           All provided pointers must be valid.
 *  \note          Specification of module initialization.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires paramDataPtr != NULL_PTR;
 *                 requires asn1_data_ptr != NULL_PTR;                                                          \endspec
 **********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Asn1_Init(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) asn1_data_ptr,
  uint16 asn1_data_len);

/**********************************************************************************************************************
 * KeyM_Asn1_GetTL()
 **********************************************************************************************************************/
/*! \brief         Extracts the TLV (Tag, Length and Value) info from current ASN position and puts the result into
 *                 the data structure element.
 *  \details       -
 *  \param[in,out] paramDataPtr                    Pointer to the ASN.1 element descriptor.
 *  \return        KEYM_ASN1_RC_OK                 TLV element was retrieved successfully.
 *                 KEYM_ASN1_RC_FAILED             Due to internal error, the TLV element could not be retrieved.
 *                 KEYM_ASN1_RC_LEN_OVERFLOW       Length mismatch
 *                 KEYM_ASN1_RC_UNSUPPORTED_TAG    Parsed tag identifier is not supported.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires paramDataPtr != NULL_PTR;                                                          \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_GetTL(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseInit()
 **********************************************************************************************************************/
/*! \brief         Parses the ASN string completely and calls the operation function.
 *  \details       -
 *  \param[out]    asn1ParseParam             Pointer to the ASN.1 data descriptor.
 *  \param[in]     asn1ParseDerivedBuffers    Pointer to derived ASN.1 descriptor buffer.
 *  \param[in]     noOfParsedBufferElements   Number of configured certificate elements.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires asn1ParseParam != NULL_PTR;
 *                 requires asn1ParseDerivedBuffers != NULL_PTR;                                               \endspec
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Asn1_ParseInit(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseDerivedBuffers,
  uint16 noOfParsedBufferElements);

# if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Asn1_ParseOCSPResponseResponderId()
 *********************************************************************************************************************/
/*! \brief         Parses ResponderId elements.
 *  \details       -
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[out]    ocspResp                        Holds the parsing information of the OCSP response.
 *  \return        E_OK                            ResponderId was parsed successfully.
 *                 E_NOT_OK                        Due to an internal error, the ResponderId could not be parsed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires asn1ParseParam != NULL_PTR;
 *                 requires asn1Param != NULL_PTR;
 *                 requires ocspResp != NULL_PTR;                                                              \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPResponseResponderId(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp);

/**********************************************************************************************************************
 * KeyM_Asn1_ParseOCSPResponse()
 *********************************************************************************************************************/
/*! \brief         Parses constructed OCSP Response structure.
 *  \details       -
 *  \param[in,out] asn1ParseParam                  Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                       Pointer to the ASN.1 element descriptor.
 *  \param[out]    ocspResp                        Holds the parsing information of the OCSP response.
 *  \return        E_OK                            OCSP Response was parsed successfully.
 *                 E_NOT_OK                        Due to an internal error, the OCSP Response could not be parsed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires asn1ParseParam != NULL_PTR;
 *                 requires asn1Param != NULL_PTR;
 *                 requires ocspResp != NULL_PTR;                                                              \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseOCSPResponse(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp);
# endif

/**********************************************************************************************************************
 * KeyM_Asn1_ParseData()
 *********************************************************************************************************************/
/*! \brief         Parses the ASN.1 string completely and calls the operation function from a table.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \param[in,out] asn1ParseParam        Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param             Pointer to the ASN.1 element descriptor.
 *  \param[in]     elementList           Start index of certificate element list.
 *  \param[in]     noOfElementList       Number of configured elements.
 *  \return        E_OK                  ASN.1 string was parsed successfully.
 *                 E_NOT_OK              Due to invalid data length, the ASN.1 string could not be parsed.
 *  \note          The function uses local functions. Thus, the function is not re-entrant.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();
 *                 requires asn1ParseParam != NULL_PTR;
 *                 requires asn1Param != NULL_PTR;
 *                 requires elementList < KeyM_GetSizeOfCertificateElement();
 *                 requires noOfElementList <= KEYM_MAX_NUM_CERT_ELEMENTS;
 *                 requires (elementList + noOfElementList) <= KeyM_GetSizeOfCertificateElement();             \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_ParseData(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  KeyM_SizeOfCertificateElementType elementList,
  KeyM_SizeOfCertificateElementType noOfElementList);

# if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Asn1_InitCSR()
 *********************************************************************************************************************/
/*! \brief         Initialize description and build ASN.1 string for CSR Info.
 *  \details       -
 *  \param[in]     certId                    Holds the identifier of the certificate.
 *  \param[in]     csrInfo                   Points to an array of request data objects. May not be NULL.
 *  \param[in]     elementIds                Points to an array of certificate element Ids of CSR elements. MAY BE NULL.
 *  \param[in]     numOfReqObjects           Total number of available request data objects.
 *  \param[out]    responseData              CertificationRequestInfo returned by the function. May not be NULL.
 *  \param[in,out] responseDataLength        In: Max number of bytes available in responseData.
 *                                           Out: Actual number.
 *                                           May not be NULL.
 *  \return        E_OK                          CertificationRequestInfo data structure was generated successfully.
 *                 E_NOT_OK                      Due to internal error, the CertificationRequestInfo data structure
 *                                               could not be generated.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH Parameter size does not match.
 *  \pre           Nullability preconditions apply: see above.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 csrInfo must reference at least numOfReqObjects many elements.
 *                 If it is not a nullpointer, elementIds must reference at least numOfReqObjects many elements.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();
 *                 requires csrInfo != NULL_PTR;
 *                 requires responseData != NULL_PTR;
 *                 requires responseDataLength != NULL_PTR;
 *                 requires $lengthOf(responseData) >= *responseDataLength;                                    \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_InitCSR(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) csrInfo,
  P2CONST(KeyM_CertElementIdType, AUTOMATIC, KEYM_APPL_DATA) elementIds,
  uint8 numOfReqObjects,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) responseDataLength);

/**********************************************************************************************************************
 * KeyM_Asn1_GetCsrElementType()
 *********************************************************************************************************************/
/*! \brief         Retrieve CSR element type.
 *  \details       Works only for subject name and extensions.
 *  \param[in]     certId                Holds the identifier of the certificate. Must be valid.
 *  \param[in]     elementId             Holds the identifier of the certificate element.
 *  \param[out]    elementType           Holds the returned CSR element type.
 *  \return        E_OK                  The CSR element type could be retrieved successfully.
 *                 E_NOT_OK              Due to an internal error, the CSR element type could not be retrieved.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();
 *                 requires elementType != NULL_PTR;                                                           \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_GetCsrElementType(
  KeyM_CertificateIdType certId,
  uint16 elementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) elementType);

/**********************************************************************************************************************
 * KeyM_Asn1_IsCsrElementAttribute()
 *********************************************************************************************************************/
/*! \brief         Checks whether CSR element is an optional attribute.
 *  \details       -
 *  \param[in]     elementIdx            Holds the identifier of the certificate element in the ComStackLib table
 *                                       KeyM_CertificateElement.
 *  \param[out]    isAttribute           Must not be NULL. If E_OK is returned, these values are written to it:
 *                                       TRUE      The referenced CSR element is an optional attribute.
 *                                       FALSE     The referenced CSR element is not an optional attribute.
 *  \return        E_OK                  The attribute status of the element could be successfully determined.
 *                 E_NOT_OK              Due to an invalid configuration, the attribute status could not be determined
 *                                       or a precondition was violated.
 *                                       isAttribute was not written.
 *  \pre           See parameter descriptions.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires elementIdx < KeyM_GetSizeOfCertificateElement();                                   \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_IsCsrElementAttribute(
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(boolean, AUTOMATIC, KEYM_APPL_VAR) isAttribute);

/**********************************************************************************************************************
 * KeyM_Asn1_BuildCSR()
 *********************************************************************************************************************/
/*! \brief         Build ASN.1 string for complete CSR.
 *  \details        -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \param[in]     requestData           Information that comes along with the request.
 *  \param[in]     requestDataLength     Length of data in the requestData array.
 *  \param[out]    responseData          CSR returned by the function.
 *  \param[in]     responseDataLength    In: Max number of bytes available in responseData.
 *  \return        E_OK                           ASN.1 string for the CSR was generated successfully.
 *                 E_NOT_OK                       Due to internal error, the ASN.1 string for the CSR could not be
 *                                                generated.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH  either responseDataLength or the config parameter
 *                                                /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateMaxLength was too small
 *                                                to hold the generated CSR.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();
 *                 requires requestData != NULL_PTR;
 *                 requires responseData != NULL_PTR;                                                          \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_BuildCSR(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint16 requestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  uint32 responseDataLength);
# endif

/**********************************************************************************************************************
 * KeyM_Asn1_InitElementStorage()
 *********************************************************************************************************************/
/*! \brief         Initializes element storage of ASN.1 parser.
 *  \details       -
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Asn1_InitElementStorage(void);

/**********************************************************************************************************************
 * KeyM_Asn1_ClearCertificateElementStorage()
 *********************************************************************************************************************/
/*! \brief         Invalidates all parsed elements for a certificate.
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \details       -
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Asn1_ClearCertificateElementStorage(KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Asn1_CertElementGetByStructureType()
 *********************************************************************************************************************/
/*! \brief         Parses certificate data and retrieves certificate element referenced by certificate structure type.
 *  \details       -
 *  \param[in,out] asn1ParseParam                       Pointer to the ASN.1 data descriptor.
 *  \param[in,out] asn1Param                            Pointer to the ASN.1 element descriptor.
 *  \param[in]     certStructure                        Holds the certificate structure type.
 *  \param[out]    certElementData                      Pointer to a valid buffer which will hold the data returned by the
 *                                                      function.
 *  \param[in,out] certElementDataLength                In: Max number of bytes available in certElementData.
 *                                                      Out: Actual number.
 *  \return        E_OK                                 Element found and data provided in the buffer.
 *                 E_NOT_OK                             Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate structure type is invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires asn1ParseParam != NULL_PTR;
 *                 requires asn1Param != NULL_PTR;
 *                 requires certElementData != NULL_PTR;
 *                 requires certElementDataLength != NULL_PTR;
 *                 requires $lengthOf(certElementData) >= *certElementDataLength;                              \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Asn1_CertElementGetByStructureType(
  P2VAR(KeyM_Asn1_ParseType, AUTOMATIC, KEYM_APPL_VAR) asn1ParseParam,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  KeyM_CertificateStructureType certStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) certElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) certElementDataLength);

/**********************************************************************************************************************
 * KeyM_Asn1_GetAlgoType()
 *********************************************************************************************************************/
/*! \brief         Returns the 16-bit concatenation of the 8-bit certificate format and the 8-bit algorithm family.
 *  \details       -
 *  \param[in]     certId       Holds the identifier of the certificate.
 *  \return                     An uint16 that is the concatenation of the uint8 certificate format (first byte)
 *                              and the algorithm family (second byte)
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();                                              \endspec
 *********************************************************************************************************************/
FUNC(uint16, KEYM_CODE) KeyM_Asn1_GetAlgoType(
  KeyM_CertificateIdType certId);

# define KEYM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* KEYM_ASN1_H */
/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/
