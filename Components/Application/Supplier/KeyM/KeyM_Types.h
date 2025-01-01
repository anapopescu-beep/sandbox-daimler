/***********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  KeyM_Types.h
 *         \unit  *
 *        \brief  KeyM types header file
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (KEYM_TYPES_H)
# define KEYM_TYPES_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
# include "Std_Types.h"
# include "Rte_KeyM_Type.h"
# include "Csm.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
# if !defined (KEYM_LOCAL_INLINE)
#  define KEYM_LOCAL_INLINE                                           LOCAL_INLINE
# endif

/* [SWS_KeyM_00040] KeyM Error Codes */
# define KEYM_E_BUSY                                                  (0x02u)
# define KEYM_E_PENDING                                               (0x03u)
# define KEYM_E_KEY_CERT_SIZE_MISMATCH                                (0x04u)
# define KEYM_E_PARAMETER_MISMATCH                                    (0x05u)
# define KEYM_E_KEY_CERT_INVALID                                      (0x06u)
# define KEYM_E_CERT_INVALID                                          (0x06u) /* Undefined within [SWS_KeyM_00040], but used in client-service interfaces */
# define KEYM_E_KEY_CERT_WRITE_FAIL                                   (0x07u)
# define KEYM_E_KEY_CERT_UPDATE_FAIL                                  (0x08u)
# define KEYM_E_KEY_CERT_READ_FAIL                                    (0x09u)
# define KEYM_E_KEY_CERT_EMPTY                                        (0x0Au)
# define KEYM_E_CERT_INVALID_CHAIN_OF_TRUST                           (0x0Bu)

/* CSR Subject Names */
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_COUNTRYNAME               (0x80u)
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_STATEORPROVINCENAME       (0x81u)
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_LOCALITYNAME              (0x82u)
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_ORGANIZATIONNAME          (0x83u)
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_ORGANIZATIONUNITNAME      (0x84u)
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_COMMONNAME                (0x85u)
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_SURNAME                   (0x86u)
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_SERIALNUMBER              (0x87u)
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_STREETADDRESS             (0x88u)
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_TITLE                     (0x89u)
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_GIVENNAME                 (0x8au)
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_EMAIL                     (0x8bu)
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_USERID                    (0x8cu)
# define KEYM_CERT_ASN1_CSR_ELEMENT_SUBJECT_DOMAINCOMPONENT           (0x8du)

/* CSR Optional Elements */
# define KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_UNSTRUCTUREDNAME        (0x8eu)
# define KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_CHALLENGEPASSWORD       (0x8fu)
# define KEYM_CERT_ASN1_CSR_ELEMENT_ATTRIBUTE_EXTENSION               (0x90u)

/* CSR Element Encoding */
# ifndef KEYM_CSR_ENCODING_NONE /* COV_KEYM_NON_RTE */
#  define KEYM_CSR_ENCODING_NONE                                      (0U)
# endif

# ifndef KEYM_CSR_ENCODING_DER /* COV_KEYM_NON_RTE */
#  define KEYM_CSR_ENCODING_DER                                       (1U)
# endif

# define KEYM_CERT_INFO_OCSP_RESPONSE_STATUS                          (0x00)
# define KEYM_CERT_INFO_OCSP_RESPONSE_CERT_STATUS                     (0x01)
# define KEYM_CERT_INFO_OCSP_RESPONSE_THISUPDATE                      (0x02)

/* Key operation starts in OEM production mode */
# define KEYM_START_OEM_PRODUCTIONMODE                                (0x01u)
/* Key operation starts in workshop mode */
# define KEYM_START_WORKSHOPMODE                                      (0x02u)

/* [SWS_KeyM_00039] KeyM_ServiceCertificateType */
/* This type specifies the requested service operation and what information is provided with this function. */
# ifndef Rte_TypeDef_KeyM_ServiceCertificateType /* COV_KEYM_NON_RTE */
typedef uint8 KeyM_ServiceCertificateType;
# endif

/* Key server requests to generate a certificate from the key client. */
# ifndef KEYM_SERVICE_CERT_REQUEST_CSR /* COV_KEYM_NON_RTE */
#  define KEYM_SERVICE_CERT_REQUEST_CSR                               (0x01u)
# endif

/* Key server returns a previously received certificate that has been now signed by the CA. */
# ifndef KEYM_SERVICE_CERT_UPDATE_SIGNED_CSR /* COV_KEYM_NON_RTE */
#  define KEYM_SERVICE_CERT_UPDATE_SIGNED_CSR                         (0x02u)
# endif

/* Key server wants to add a new root certificate. */
# ifndef KEYM_SERVICE_CERT_SET_ROOT /* COV_KEYM_NON_RTE */
#  define KEYM_SERVICE_CERT_SET_ROOT                                  (0x03u)
# endif

/* Key server wants to update an existing root certificate. */
# ifndef KEYM_SERVICE_CERT_UPDATE_ROOT /* COV_KEYM_NON_RTE */
#  define KEYM_SERVICE_CERT_UPDATE_ROOT                               (0x04u)
# endif

/* Key server wants to add a new CA certificate. */
# ifndef KEYM_SERVICE_CERT_SET_INTERMEDIATE /* COV_KEYM_NON_RTE */
#  define KEYM_SERVICE_CERT_SET_INTERMEDIATE                          (0x05u)
# endif

/* Key server wants to update an existing CA certificate. */
# ifndef KEYM_SERVICE_CERT_UPDATE_INTERMEDIATE /* COV_KEYM_NON_RTE */
#  define KEYM_SERVICE_CERT_UPDATE_INTERMEDIATE                       (0x06u)
# endif
/* Provide or update a certificate revocation list. */
# ifndef KEYM_SERVICE_CERT_UPDATE_CRL /* COV_KEYM_NON_RTE */
#  define KEYM_SERVICE_CERT_UPDATE_CRL                                (0x07u)
# endif

# define KEYM_SERVICE_CERT_STATUS_OCSP                                (0x81u)

/* Enumeration of the result type of certificate group verification. */
typedef uint8 KeyM_CertificateGroupStatusType;

/* Status of certificate group verification */
# define KEYM_CERT_VERIFY_GROUP_VALID                                 (0x00u)
# define KEYM_CERT_VERIFY_GROUP_INVALID                               (0x01u)

/* [SWS_KeyM_91003] KeyM_CertificateStatusType */
/* Enumeration of the result type of verification operations. */
# ifndef Rte_TypeDef_KeyM_CertificateStatusType /* COV_KEYM_NON_RTE */
typedef uint8 KeyM_CertificateStatusType;
# endif

/* Certificate successfully parsed and verified.*/
# ifndef KEYM_CERTIFICATE_VALID /* COV_KEYM_NON_RTE */
#  define KEYM_CERTIFICATE_VALID                                      (0x00u)
# endif

/* The certificate is invalid (unspecified failure) */
# ifndef KEYM_CERTIFICATE_INVALID /* COV_KEYM_NON_RTE */
#  define KEYM_CERTIFICATE_INVALID                                    (0x01u)
# endif

/* Certificate has not been parsed so far. */
# ifndef KEYM_CERTIFICATE_NOT_PARSED /* COV_KEYM_NON_RTE */
#  define KEYM_CERTIFICATE_NOT_PARSED                                 (0x02u)
# endif

/* Certificate parsed but not yet validated */
# ifndef KEYM_CERTIFICATE_PARSED_NOT_VALIDATED /* COV_KEYM_NON_RTE */
#  define KEYM_CERTIFICATE_PARSED_NOT_VALIDATED                       (0x03u)
# endif

/* Certificate not set */
# ifndef KEYM_CERTIFICATE_NOT_AVAILABLE /* COV_KEYM_NON_RTE */
#  define KEYM_CERTIFICATE_NOT_AVAILABLE                              (0x04u)
# endif

/* Certificate verification failed - Invalid Time Period */
# ifndef KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL                     (0x05u)
# endif

/* Certificate verification failed - Invalid Signature */
# ifndef KEYM_E_CERTIFICATE_SIGNATURE_FAIL /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_SIGNATURE_FAIL                           (0x06u)
# endif

/* Certificate verification failed - Invalid Chain of Trust */
# ifndef KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST                   (0x07u)
# endif

/* Certificate verification failed - Invalid Type */
# ifndef KEYM_E_CERTIFICATE_INVALID_TYPE /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_INVALID_TYPE                             (0x08u)
# endif

/* Certificate verification failed - Invalid Format */
# ifndef KEYM_E_CERTIFICATE_INVALID_FORMAT /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_INVALID_FORMAT                           (0x09u)
# endif

/* Certificate verification failed - Invalid Content */
# ifndef KEYM_E_CERTIFICATE_INVALID_CONTENT /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_INVALID_CONTENT                          (0x0Au)
# endif

/* Certificate verification failed - Invalid Scope */
# ifndef KEYM_E_CERTIFICATE_REVOKED /* COV_KEYM_NON_RTE */
#  define KEYM_E_CERTIFICATE_REVOKED                                  (0x0Bu)
# endif

/* No configured period validity check for processing certificate */
# define KEYM_E_NO_PERIOD_VALIDITY_CHECK                              (0x80u)

/* [SWS_KeyM_91012] KeyM_CryptoKeyDataType */
/* Byte-pointer to the input or output data */
# ifndef Rte_TypeDef_KeyM_CryptoKeyDataType /* COV_KEYM_NON_RTE */
typedef P2VAR(uint8, AUTOMATIC, AUTOMATIC) KeyM_CryptoKeyDataType;
# endif

/* [SWS_KeyM_91008] KeyM_ResultType */
/* Specifies the result type of an asynchronous key management function. */
# ifndef Rte_TypeDef_KeyM_ResultType /* COV_KEYM_NON_RTE */
typedef uint8 KeyM_ResultType;
# endif

/* Key management operation successful. */
# ifndef KEYM_RT_OK /* COV_KEYM_NON_RTE */
#  define KEYM_RT_OK                                                  (0x00u)
# endif

/* General error occurred during key management operation. */
# ifndef KEYM_RT_NOT_OK /* COV_KEYM_NON_RTE */
#  define KEYM_RT_NOT_OK                                              (0x01u)
# endif

/* Key or certificate is invalid and cannot be used for the operation. */
# ifndef KEYM_RT_KEY_CERT_INVALID /* COV_KEYM_NON_RTE */
#  define KEYM_RT_KEY_CERT_INVALID                                    (0x02u)
# endif

/* Key or certificate could not be written to designated storage. */
# ifndef KEYM_RT_KEY_CERT_WRITE_FAIL /* COV_KEYM_NON_RTE */
#  define KEYM_RT_KEY_CERT_WRITE_FAIL                                 (0x03u)
# endif

/* General failure while updating a key or certificate */
# ifndef KEYM_RT_KEY_CERT_UPDATE_FAIL /* COV_KEYM_NON_RTE */
#  define KEYM_RT_KEY_CERT_UPDATE_FAIL                                (0x04u)
# endif

/* Certificate verification failed - Invalid Chain of Trust */
# ifndef KEYM_RT_CERT_INVALID_CHAIN_OF_TRUST /* COV_KEYM_NON_RTE */
#  define KEYM_RT_CERT_INVALID_CHAIN_OF_TRUST                         (0x05u)
# endif

/* OCSP Response thisUpdate timestamp data length */
# define KEYM_CERTINFO_SIZEOF_OCSP_RESPONSE_THISUPDATE                (15u)

/* RSA Crypto key element identifier */
# ifndef CRYPTO_KE_CUSTOM_RSA_MODULUS /* COV_KEYM_NON_MICROSAR_CRYPTO_DRIVER */
#  define CRYPTO_KE_CUSTOM_RSA_MODULUS                                (0xFFFFu)
# endif

# ifndef CRYPTO_KE_CUSTOM_RSA_PUBLIC_EXPONENT /* COV_KEYM_NON_MICROSAR_CRYPTO_DRIVER */
#  define CRYPTO_KE_CUSTOM_RSA_PUBLIC_EXPONENT                        (0xFFFFu)
# endif

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* [SWS_KeyM_00055] KeyM_KH_UpdateOperationType */
/* Specifies the type of key handler update operation that was performed in the callback.*/
typedef uint8 KeyM_KH_UpdateOperationType;
/* Key handler has successfully performed the operation and provides new key data that shall be further operated by
   the update function of the key manager. A next call to key handler is requested. */
# define KEYM_KH_UPDATE_KEY_UPDATE_REPEAT
/* Key handler has successfully performed all update operation. The update operation is finished and the result data
   can be provided back for a final result of the KeyM_Update operation. */
# define KEYM_KH_UPDATE_FINISH

/* [SWS_KeyM_00302] KeyM_CryptoKeyIdType */
/* Crypto key handle. */
typedef uint16 KeyM_CryptoKeyIdType;

# ifndef Rte_TypeDef_KeyM_CertDataPointerType /* COV_KEYM_NON_RTE */
typedef P2VAR(uint8, AUTOMATIC, KEYM_APPL_DATA) KeyM_CertDataPointerType;
# endif

typedef P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) KeyM_ConstCertDataPointerType;
/* NvM Block Handling */
typedef uint8 tKeyMCertNvBlockStateType;

/* storage location for certificate */
typedef uint8 tKeyMCertStorageType;

/* type of service request */
typedef uint8 tKeyMCertRequestType;

/* type of certificate information */
typedef uint8 KeyM_CertificateInfoType;

/* [SWS_KeyM_00038] KeyM_StartType */
# ifndef Rte_TypeDef_KeyM_StartType /* COV_KEYM_NON_RTE */
typedef uint8 KeyM_StartType;
# endif

/* type of certificate structure */
typedef uint8 KeyM_CertificateStructureType;

/* [SWS_KeyM_00300] KeyM_CertElementIdType */
/* Certificate Element handle. */
# ifndef Rte_TypeDef_KeyM_CertElementIdType /* COV_KEYM_NON_RTE */
typedef uint16 KeyM_CertElementIdType;
# endif

/* [SWS_KeyM_00300] KeyM_CertificateIdType */
/* Certificate handle. */
# ifndef Rte_TypeDef_KeyM_CertificateIdType /* COV_KEYM_NON_RTE */
typedef uint16 KeyM_CertificateIdType;
# endif

# ifndef Rte_TypeDef_KeyM_CsrEncodingType /* COV_KEYM_NON_RTE */
typedef uint8 KeyM_CsrEncodingType;
# endif

/* [SWS_KeyM_00041]  KeyM_CertDataType */
typedef struct
{
  uint32 certDataLength;
  KeyM_ConstCertDataPointerType certData;
} KeyM_ConstCertDataType;

# ifndef Rte_TypeDef_KeyM_CertDataType /* COV_KEYM_NON_RTE */
typedef struct
{
  uint32 certDataLength;
  KeyM_CertDataPointerType certData;
} KeyM_CertDataType;
# endif

/* Certificate data for signature verification, service request information and verification result */
typedef struct
{
  uint32 sigProcessDataLength;
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) sigProcessDataPtr;
  tKeyMCertRequestType request;
  Crypto_VerifyResultType verifyRes;
  Std_ReturnType csmRes;
} tKeyMCertInfoType;

/* [SWS_KeyM_00042] KeyM_CertElementIteratorType */
typedef struct
{
  KeyM_CertificateIdType certId;
  uint16 offset;
  uint16 elementLength;
  uint16 rootElementIdx;
  uint8 iterationStatus;
} KeyM_CertElementIteratorType;

/* Certificate signing request info data */
typedef struct
{
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) dataPtr;
  uint16 dataLength;
  uint8 elementType;
}
KeyM_CSRInfoType;

/* Certificate signing request element type */
typedef struct
{
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) dataPtr;
  uint16 dataLength;
  uint16 elementId;
}
KeyM_CSRElementType;

/* UpperHierarachicalRef Info */
typedef struct
{
  KeyM_CertificateIdType issuerCertId;
  boolean isIssuerCertIdAvailable;
}
KeyM_UpperHierarachicalRefInfoType;

/* CertInfo data */
typedef struct
{
  uint8 ocspResponseStatus;
  uint8 ocspResponseCertStatus;
  uint8 ocspResponseThisUpdate[KEYM_CERTINFO_SIZEOF_OCSP_RESPONSE_THISUPDATE];
  boolean isValid;
} KeyM_CertInfoDataType;

/* Basic Constraints Extension Type */
typedef struct
{
  uint32 pathLenConstraint;
  boolean hasBasicConstraints;
  boolean isCritical;
  boolean isCA;
  boolean hasPathLenConstraint;
} KeyM_BasicConstraintsType;

/* Key Usage Extension Type */
typedef struct
{
  boolean hasKeyUsage;
  boolean isCritical;
  boolean digitalSignature;
  boolean nonRepudiation;
  boolean keyEncipherment;
  boolean dataEncipherment;
  boolean keyAgreement;
  boolean keyCertSign;
  boolean cRLSign;
  boolean encipherOnly;
  boolean decipherOnly;
} KeyM_KeyUsageType;

/* Certificate Group Identifier */
typedef uint16 KeyM_CertificateGroupIdType;

#endif /* KEYM_TYPES_H */
/***********************************************************************************************************************
 *  END OF FILE: KeyM_Types.h
 **********************************************************************************************************************/
