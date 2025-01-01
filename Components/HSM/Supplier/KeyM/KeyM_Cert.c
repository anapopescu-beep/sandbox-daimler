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
/*!        \file  KeyM_Cert.c
 *         \unit  *
 *        \brief  KeyM certificate submodule source file
 *      \details  Implementation of AUTOSAR Key Manager
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define KEYM_CERT_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "KeyM_Cert.h"
#include "KeyM_Asn1.h"
#include "KeyM_Remote.h"
#include "KeyM_Utils.h"
#include "KeyM_Cbk.h"
#include "SchM_KeyM.h"

#if (KEYM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

#include "vstdlib.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (KEYM_LOCAL) /* COV_KEYM_LOCAL_DEFINE */
# define KEYM_LOCAL                                                   static
#endif

#if !defined (KEYM_LOCAL_INLINE) /* COV_KEYM_LOCAL_DEFINE */
# define KEYM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

/* States of state machine */
#define KEYM_CERT_STATE_IDLE                                          (0x00u)
#define KEYM_CERT_STATE_INIT                                          (0x01u)
#define KEYM_CERT_STATE_PARSE_CERT                                    (0x02u)
#define KEYM_CERT_STATE_VERIFY_CERT_ELEMENTS                          (0x03u)
#define KEYM_CERT_STATE_CHECK_SUBJECT                                 (0x04u)
#define KEYM_CERT_STATE_CHECK_TIME_STAMP                              (0x05u)
#define KEYM_CERT_STATE_SET_KEY                                       (0x06u)
#define KEYM_CERT_STATE_VERIFY_SIGNATURE                              (0x07u)
#define KEYM_CERT_STATE_STORE                                         (0x08u)
#define KEYM_CERT_STATE_NOTIFY                                        (0x09u)
#define KEYM_CERT_STATE_VERIFY_SIGNATURE_PENDING                      (0x0Au)

/* States of startup */
#define KEYM_CERT_STARTUP_STATE_IDLE                                  (0x00u)
#define KEYM_CERT_STARTUP_STATE_ACTIVE                                (0x01u)
#define KEYM_CERT_STARTUP_STATE_FINISHED                              (0x02u)

/* Storage types */
#define KEYM_CERT_STORAGE_EMPTY                                       (0x00u)
#define KEYM_CERT_STORAGE_MASK_CSM                                    (0x01u)
#define KEYM_CERT_STORAGE_MASK_NVM                                    (0x02u)
#define KEYM_CERT_STORAGE_MASK_ROM                                    (0x04u)
#define KEYM_CERT_STORAGE_MASK_DATA_BUFFER                            (0x08u)
#define KEYM_CERT_STORAGE_MASK_PARSE_BUFFER                           (0x10u)
#define KEYM_CERT_STORAGE_MASK_DIRTY                                  (0x20u)

/* Request types */
#define KEYM_CERT_REQUEST_NOT_SET                                     (0x00u)
#define KEYM_CERT_REQUEST_SERVICE                                     (0x01u)
#define KEYM_CERT_REQUEST_VERIFY                                      (0x02u)

/* Public key extraction */
#define KEYM_CERT_PUBLIC_POINT_FORMAT_LENGTH_CVC                      (1u)
#define KEYM_CERT_PUBLIC_POINT_TAG_VALUE_CVC                          (0x06u)

/* Invalid parameter */
#define KEYM_CERT_INVALID_ID                                          (0xFFFFu)
#define KEYM_CERT_INVALID_STATE                                       (0xFFu)

/* Iteration status */
#define KEYM_CERT_ELEMENT_ITERATION_NOT_INITIALIZED                   (0x00u)
#define KEYM_CERT_ELEMENT_ITERATION_INITIALIZED                       (0x01u)
#define KEYM_CERT_ELEMENT_ITERATION_VALID                             (0x02u)
#define KEYM_CERT_ELEMENT_ITERATION_INVALID                           (0x03u)

#define KEYM_ASN1_GENERALIZEDTIME_UTC_MAX_LENGTH                      (0x06u)

/* NvM Block Handling */
/* State:
 * 1Byte State: [ Bit7-3 not used | DataCopied | WriteRequested| DataChanged ]
 */
#define KEYM_CERT_NVBLOCK_STATE_MASK_DATA_CHANGE                      (0x01u)
#define KEYM_CERT_NVBLOCK_STATE_MASK_WRITE_REQUESTED                  (0x02u)
#define KEYM_CERT_NVBLOCK_STATE_MASK_WRITE_COPIED                     (0x04u)
#define KEYM_CERT_NVBLOCK_STATE_MASK_CLEAR_WRITE_COPIED               (0xFBu)
#define KEYM_CERT_NVBLOCK_STATE_MASK_CLEAR_WRITE_REQUESTED            (0xFDu)

#define KEYM_CERT_NVBLOCK_STATE_IDLE                                  (0x00u)
#define KEYM_CERT_NVBLOCK_STATE_WRITE_REQ_PENDING                     (KEYM_CERT_NVBLOCK_STATE_MASK_DATA_CHANGE)
#define KEYM_CERT_NVBLOCK_STATE_WRITE_REQ                             (KEYM_CERT_NVBLOCK_STATE_MASK_DATA_CHANGE|KEYM_CERT_NVBLOCK_STATE_MASK_WRITE_REQUESTED)
#define KEYM_CERT_NVBLOCK_STATE_COPY_DATA                             (KEYM_CERT_NVBLOCK_STATE_MASK_WRITE_COPIED)
#define KEYM_CERT_NVBLOCK_STATE_REQ_WHILE_PENDING                     (KEYM_CERT_NVBLOCK_STATE_MASK_WRITE_COPIED|KEYM_CERT_NVBLOCK_STATE_MASK_DATA_CHANGE)

/* Nv Header Length and Position */
#define KEYM_CERT_POS_NVBLOCK_VERSION                                 (0u)
#define KEYM_CERT_SIZEOF_NVBLOCK_VERSION                              (1u)
#define KEYM_CERT_POS_NVBLOCK_UNSPECIFIED                             (KEYM_CERT_SIZEOF_NVBLOCK_VERSION)
#define KEYM_CERT_SIZEOF_NVBLOCK_UNSPECIFIED                          (1u)
#define KEYM_CERT_POS_NVBLOCK_LENGTH                                  (KEYM_CERT_POS_NVBLOCK_UNSPECIFIED + KEYM_CERT_SIZEOF_NVBLOCK_UNSPECIFIED)
#define KEYM_CERT_SIZEOF_NVBLOCK_LENGTH                               (2u)
#define KEYM_CERT_SIZEOF_NVBLOCK_HEADER                               (KEYM_CERT_POS_NVBLOCK_LENGTH + KEYM_CERT_SIZEOF_NVBLOCK_LENGTH)

#define KEYM_CERT_POS_NVBLOCK_CRE_VERSION                             (0u)
#define KEYM_CERT_SIZEOF_NVBLOCK_CRE_VERSION                          (1u)
#define KEYM_CERT_POS_NVBLOCK_CRE_UNSPECIFIED                         (KEYM_CERT_SIZEOF_NVBLOCK_VERSION)
#define KEYM_CERT_SIZEOF_NVBLOCK_CRE_UNSPECIFIED                      (1u)
#define KEYM_CERT_POS_NVBLOCK_CRE_NUMBER_OF_ENTRIES                   (KEYM_CERT_POS_NVBLOCK_UNSPECIFIED + KEYM_CERT_SIZEOF_NVBLOCK_UNSPECIFIED)
#define KEYM_CERT_SIZEOF_NVBLOCK_CRE_NUMBER_OF_ENTRIES                (2u)
#define KEYM_CERT_SIZEOF_NVBLOCK_CRE_HEADER                           (KEYM_CERT_POS_NVBLOCK_CRE_NUMBER_OF_ENTRIES + KEYM_CERT_SIZEOF_NVBLOCK_CRE_NUMBER_OF_ENTRIES)

#define KEYM_CERT_NVBLOCK_VERSION_0                                   (0u)
#define KEYM_CERT_NVBLOCK_UNSPECIFIED                                 (0u)

#define KEYM_CERT_NVBLOCK_CRE_VERSION_0                               (0u)
#define KEYM_CERT_NVBLOCK_CRE_UNSPECIFIED                             (0u)

#define KEYM_CERT_LENGTH_OF_CRE_ID                                    (2u)
#define KEYM_CERT_LENGTH_OF_CRE_ISSUER_WRITTENLENGTH                  (2u)
#define KEYM_CERT_LENGTH_OF_CRE_SERIALNUMBER_WRITTENLENGTH            (2u)
#define KEYM_CERT_LENGTH_OF_CRE_SINGLE_ENTRY                          (KEYM_CERT_LENGTH_OF_CRE_ID + KEYM_CERT_LENGTH_OF_CRE_ISSUER_WRITTENLENGTH + KEYM_CREMAX_LENGTH_OF_ISSUER_NAME + KEYM_CERT_LENGTH_OF_CRE_SERIALNUMBER_WRITTENLENGTH + KEYM_CREMAX_LENGTH_OF_SERIAL_NUMBER)

/* Nvm Service Id for NvM_WriteBlock */
#ifndef KEYM_CERT_NVM_WRITE_BLOCK /* COV_KEYM_COMPATIBILITY_DEFINE */
# define KEYM_CERT_NVM_WRITE_BLOCK                                    (7u) /* Service ID NvM_WriteBlock() */
#endif

/* Nvm Service Id for NvM_WriteBlock */
#ifndef KEYM_CERT_NVM_WRITE_ALL /* COV_KEYM_COMPATIBILITY_DEFINE */
# define KEYM_CERT_NVM_WRITE_ALL                                      (13u) /* Service ID NvM_WriteAll() */
#endif

#if ((KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_CRE_APPL */
# define KEYM_CERT_X509_COMMONNAMEOIDDATA                             (KeyM_Cert_X509_CommonName_OID)
# define KEYM_CERT_X509_COMMONNAMEOIDDATALENGTH                       (3u)
#endif

#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
# define KEYM_CERT_OCSP_BASIC_RESPONSE_OIDDATA                        (KeyM_Cert_OCSPResponseTypeBasicOID)
# define KEYM_CERT_OCSP_BASIC_RESPONSE_OIDDATALENGTH                  (9u)

# define KEYM_CERT_X509_MAX_SERIAL_NUMBER_DATALENGTH                  (20u)
# define KEYM_CERT_X509_MAX_ISSUER_DN_DATALENGTH                      KEYM_OCSPMAX_LENGTH_OF_DISTINGUISHED_NAME
# define KEYM_CERT_X509_MAX_HASH_DATALENGTH                           KEYM_OCSPMAX_LENGTH_OF_CERT_ID_HASH

# define KEYM_ASN1_OCSP_SIZE_OF_OCSP_RESPONSE_ELEMENT_STORAGE         (0x21u)
#endif

#define KEYM_CERT_CSR_SIZEOF_ELEMENTID                                (2u)
#define KEYM_CERT_CSR_POS_ELEMENTLENGTH                               (KEYM_CERT_CSR_SIZEOF_ELEMENTID)
#define KEYM_CERT_CSR_SIZEOF_ELEMENTLENGTH                            (2u)
#define KEYM_CERT_CSR_POS_ELEMENTDATA                                 (KEYM_CERT_CSR_POS_ELEMENTLENGTH + KEYM_CERT_CSR_SIZEOF_ELEMENTLENGTH)

#ifndef KeyM_NvM_WriteBlock /* COV_KEYM_COMPATIBILITY_DEFINE */
# define KeyM_NvM_WriteBlock                                          KEYM_NVM_WRITE_BLOCK_FCT_NAME
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* state of state machine */
typedef uint8 tKeyMCertState;
/* state of startup */
typedef uint8 tKeyMCertStartUpState;

/* Time stamp */
typedef struct
{
  uint16 year;
  uint8 month;
  uint8 day;
  uint8 hour;
  uint8 minute;
  uint8 second;
} tKeyMCertDateTimeType;

/* Certificate public key */
typedef struct
{
  uint16 firstElementOffset;
  uint16 firstElementLength;
  uint16 secondElementOffset;
  uint16 secondElementLength;
} KeyM_CertPubKeyType;

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/* Certificate group info */
typedef struct
{
  KeyM_CertificateGroupIdType groupId;
  KeyM_CertificateGroupStatusType groupStatus;
} KeyM_CertGroupInfoType;
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define KEYM_START_SEC_VAR_NO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Task busy state */
VAR(tKeyMCertTaskState, KEYM_VAR_NO_INIT) KeyM_Cert_TaskState;

/*! Sync task busy state */
VAR(tKeyMCertTaskState, KEYM_VAR_NO_INIT) KeyM_Cert_GlobalState;

/*! State of state machine */
KEYM_LOCAL VAR(tKeyMCertState, KEYM_VAR_NO_INIT) KeyM_Cert_State;

/*! State of startup phase */
KEYM_LOCAL VAR(tKeyMCertStartUpState, KEYM_VAR_NO_INIT) KeyM_Cert_StartUpState;

/*! Callback result */
#if (KEYM_CSM_ASYNC_SIGNATURE_VERIFY == STD_ON)
KEYM_LOCAL VAR(Std_ReturnType, KEYM_VAR_NO_INIT) KeyM_Cert_SignatureCallbackResult;
#endif

/*! Index for KeyM_Cert_VerifyChain */
KEYM_LOCAL VAR(KeyM_SizeOfCert_VerifyChainType, KEYM_VAR_NO_INIT) KeyM_Cert_NumLinksInVerifyChain;

/*! Index for Cert_LeafCertsToVerify */
KEYM_LOCAL VAR(KeyM_SizeOfCert_LeafCertsToVerifyType, KEYM_VAR_NO_INIT) KeyM_Cert_NumLeafCertsToVerify;

/*! Callback status */
#if (KEYM_CSM_ASYNC_SIGNATURE_VERIFY == STD_ON)
KEYM_LOCAL VAR(boolean, KEYM_VAR_NO_INIT) KeyM_Cert_CallbackOccurred;
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/*! Flag for certificate update operation */
KEYM_LOCAL VAR(boolean, KEYM_VAR_NO_INIT) KeyM_Cert_UpdateFlag;
#endif

/*! Flag for chain verification requests during startup handling, certificate update or verification of dynamic group
 *  If this is true, chain verification will continue even if one individual certificate verification pair fails */
KEYM_LOCAL VAR(boolean, KEYM_VAR_NO_INIT) KeyM_Cert_ChainVerificationFlag;

/*! Public key buffer of processing certificate */
KEYM_LOCAL VAR(uint8, KEYM_VAR_NO_INIT) KeyM_Cert_PubKeyBuffer[KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH];

/*! Signature buffer of processing certificate */
KEYM_LOCAL VAR(uint8, KEYM_VAR_NO_INIT) KeyM_Cert_SigBuffer[KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH];

#if (KEYM_CERTCSMHASHJOBREFOFCERTIFICATE == STD_ON)
/*! Certificate Hash Status */
KEYM_LOCAL VAR(boolean, KEYM_VAR_NO_INIT) KeyM_Cert_HashStatus[KEYM_NUMBER_OF_CERTIFICATES];
#endif

#define KEYM_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define KEYM_START_SEC_CONST_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_CRE_APPL */
KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Cert_X509_CommonName_OID[3u] = { 0x55u, 0x04u, 0x03u }; /* PRQA S 3218 */ /* MD_KEYM_8.9 */
#endif

#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
/* [RFC6960] */
KEYM_LOCAL CONST(uint8, KEYM_CONST) KeyM_Cert_OCSPResponseTypeBasicOID[9u] = { 0x2BU, 0x06U, 0x01U, 0x05U, 0x05U, 0x07U, 0x30U, 0x01U, 0x01 }; /* PRQA S 3218 */ /* MD_KEYM_8.9 */
#endif

#define KEYM_STOP_SEC_CONST_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define KEYM_START_SEC_VAR_NO_INIT_16
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Processing certificate identifier */
KEYM_LOCAL VAR(KeyM_CertificateIdType, KEYM_VAR_NO_INIT) KeyM_Cert_CertId;

/*! Requested certificate identifier */
KEYM_LOCAL VAR(KeyM_CertificateIdType, KEYM_VAR_NO_INIT) KeyM_Cert_RequestId;

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/*! Number of Certificate Revocation Entries */
KEYM_LOCAL VAR(uint16, KEYM_VAR_NO_INIT) KeyM_Cert_NumOfCRE;
#endif

#define KEYM_STOP_SEC_VAR_NO_INIT_16
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define KEYM_START_SEC_VAR_NO_INIT_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Public key length of processing certificate */
KEYM_LOCAL VAR(uint32, KEYM_VAR_NO_INIT) KeyM_Cert_PubKeyLength;

/*! Signature length of processing certificate */
KEYM_LOCAL VAR(uint32, KEYM_VAR_NO_INIT) KeyM_Cert_SigLength;

#define KEYM_STOP_SEC_VAR_NO_INIT_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
KEYM_LOCAL VAR(KeyM_UpperHierarachicalRefInfoType, KEYM_VAR_NO_INIT) KeyM_Cert_UpperHierarachicalRefInfo[KEYM_NUMBER_OF_CERTIFICATES];
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/*! Status information about processed certificate group */
KEYM_LOCAL VAR(KeyM_CertGroupInfoType, KEYM_VAR_NO_INIT) KeyM_Cert_GroupInfo;
#endif

#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define KEYM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * KeyM_Cert_GetTL()
 **********************************************************************************************************************/
/*! \brief         Extracts the TLV (Tag, Length and Value) info from current ASN position and puts the result into
 *                 the data structure element.
 *  \details       Refer to description of KeyM_Asn1_GetTL().
 *  \param[in,out] paramDataPtr                    Pointer to the ASN.1 element descriptor.
 *  \return        E_OK                            TLV element was retrieved successfully.
 *                 E_NOT_OK                        Due to internal error, the TLV element could not be retrieved.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires paramDataPtr != NULL_PTR;                                                          \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetTL(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr);

/**********************************************************************************************************************
 * KeyM_Cert_GetCertificateWrittenLength()
 *********************************************************************************************************************/
/*! \brief         Get written length of certificate data.
 *  \details       -
 *  \param[in]     CertId              Holds the identifier of the certificate.
 *  \return        written length
 *  \pre           CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires CertId < KeyM_GetSizeOfCertificate();                                              \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(uint16, KEYM_CODE) KeyM_Cert_GetCertificateWrittenLength(
  KeyM_CertificateIdType CertId);

/**********************************************************************************************************************
 * KeyM_Cert_SetCertificateWrittenLength()
 *********************************************************************************************************************/
/*! \brief         Set written length of certificate data.
 *  \details       -
 *  \param[in]     CertId              Holds the identifier of the certificate.
 *  \param[in]     writtenLength       Holds the certificate data length.
 *  \pre           CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires CertId < KeyM_GetSizeOfCertificate();                                              \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_SetCertificateWrittenLength(
  KeyM_CertificateIdType CertId,
  uint16 writtenLength);

/**********************************************************************************************************************
 * KeyM_Cert_GetStatusInfo()
 *********************************************************************************************************************/
/*! \brief         Get current status of processing certificate.
 *  \details       -
 *  \param[in]     CertId              Holds the identifier of the certificate.
 *  \return        status
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires CertId < KeyM_GetSizeOfCertificate();                                              \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateStatusType, KEYM_CODE) KeyM_Cert_GetStatusInfo(
  KeyM_CertificateIdType CertId);

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_GetCREIssuerNameWrittenLength()
 *********************************************************************************************************************/
/*! \brief         Get written length of issuer name.
 *  \details       -
 *  \param[in]     creId              Holds the identifier of the certificate revocation entry.
 *  \return        issuer name written length
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires creId < KeyM_GetSizeOfCREInfo();                                                   \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(uint16, KEYM_CODE) KeyM_Cert_GetCREIssuerNameWrittenLength(
  KeyM_SizeOfCREInfoType creId);
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_SetCREIssuerNameWrittenLength()
 *********************************************************************************************************************/
/*! \brief         Set written length of issuer name.
 *  \details       -
 *  \param[in]     creId               Holds the identifier of the certificate revocation entry.
 *  \param[in]     writtenLength       Holds the issuer name data length.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires creId < KeyM_GetSizeOfCREInfo();                                                   \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_SetCREIssuerNameWrittenLength(
  KeyM_SizeOfCREInfoType creId,
  uint16 writtenLength);
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_GetCRESerialNumberWrittenLength()
 *********************************************************************************************************************/
/*! \brief         Get written length of serial number.
 *  \details       -
 *  \param[in]     creId              Holds the identifier of the certificate revocation entry.
 *  \return        serial number written length
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires creId < KeyM_GetSizeOfCREInfo();                                                   \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(uint16, KEYM_CODE) KeyM_Cert_GetCRESerialNumberWrittenLength(
  KeyM_SizeOfCREInfoType creId);
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_SetCRESerialNumberWrittenLength()
 *********************************************************************************************************************/
/*! \brief         Set written length of serial number.
 *  \details       -
 *  \param[in]     creId               Holds the identifier of the certificate revocation entry.
 *  \param[in]     writtenLength       Holds the serial number data length.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires creId < KeyM_GetSizeOfCREInfo();                                                   \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_SetCRESerialNumberWrittenLength(
  KeyM_SizeOfCREInfoType creId,
  uint16 writtenLength);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_GetCertElementDataPointer()
 *********************************************************************************************************************/
/*! \brief         Return the certificate element data pointer.
 *  \details       -
 *  \param[in]     certId              Holds the identifier of the certificate.
 *  \param[in]     elementIdx          Holds the certificate element index.
 *  \return        Certificate element data pointer.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();
 *                 requires elementIdx < KeyM_GetSizeOfCertificateElement();                                   \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(KeyM_ConstCertDataPointerType, KEYM_CODE) KeyM_Cert_GetCertElementDataPointer(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx);

/**********************************************************************************************************************
 * KeyM_Cert_SetStatusInfo()
 *********************************************************************************************************************/
/*! \brief         Set current status of processing certificate.
 *  \details       -
 *  \param[in]     CertId              Holds the identifier of the certificate.
 *  \param[in]     status              Holds the status information.
 *  \pre           CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires CertId < KeyM_GetSizeOfCertificate();                                              \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_SetStatusInfo(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStatusType status);

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_IsCsrElementSet()
 *********************************************************************************************************************/
/*! \brief         Checks whether CSR element is set.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \param[in]     certElementId         Holds the identifier of the certificate element.
 *  \param[out]    csrElementOffset      Offset of the CSR element relative to the certificate slot's data buffer.
 *  \param[out]    csrElementDataLength  Data length of the CSR element.
 *  \return        TRUE                  The referenced CSR element has been already set.
 *                 FALSE                 The referenced CSR element has not been set yet.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCsrElementSet(
  KeyM_CertificateIdType certId,
  KeyM_CertElementIdType certElementId,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) csrElementOffset,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) csrElementDataLength);
#endif

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_UpdateCsrElement()
 *********************************************************************************************************************/
/*! \brief         Updates previously set CSR element.
 *  \details       -
 *  \param[in]     certId                   Holds the identifier of the certificate.
 *  \param[in]     csrElementOffset         Offset of the CSR element.
 *  \param[in]     oldCsrElementDataLength  Data length of the previously set CSR element.
 *  \param[in]     newCsrElementData        Pointer to the new CSR element data. Must not be NULL.
 *  \param[in]     newCsrElementDataLength  Data length of the new CSR element.
 *  \return        E_OK                             The CSR element is updated successfully.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    The CSR element could not be updated.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_UpdateCsrElement(
  KeyM_CertificateIdType certId,
  uint16 csrElementOffset,
  uint16 oldCsrElementDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) newCsrElementData,
  uint16 newCsrElementDataLength);
#endif

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_ServiceRequestCSR()
 *********************************************************************************************************************/
/*! \brief         Handle certificate signing request.
 *  \details       Refer to KeyM_ServiceCertificate.
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in]     RequestData                      Information that comes along with the request.
 *  \param[in]     RequestDataLength                Length of data in the RequestData array.
 *  \param[out]    ResponseData                     CSR returned by the function.
 *  \param[in]     ResponseDataLength               Max number of bytes available in ResponseData.
 *  \return        E_OK                             Service data operation successfully accepted.
 *                 E_NOT_OK                         Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    either responseDataLength or the config parameter
 *                                                  /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateMaxLength was too
 *                                                  small to hold the generated CSR.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceRequestCSR(
  KeyM_CertificateIdType CertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength);
#endif

#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_ParseOCSPResponseConstructed()
 *********************************************************************************************************************/
/*! \brief         Parse constructed OCSPResponse structure.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     requestDataLength                Length of data in the requestData array.
 *  \param[out]    ocspResp                         Holds the parsing information of the OCSP response.
 *  \return        E_OK                             Constructed ASN.1 tag of OCSP response was parsed successfully.
 *                 E_NOT_OK                         The parsing failed due to an internal error.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseOCSPResponseConstructed(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp);

/**********************************************************************************************************************
 * KeyM_Cert_ParseOCSPResponseResponderId()
 *********************************************************************************************************************/
/*! \brief         Parse constructed ResponderId structure.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[out]    ocspResp                         Holds the parsing information of the OCSP response.
 *  \return        E_OK                             Constructed ASN.1 tag of OCSP ResponderId was parsed successfully.
 *                 E_NOT_OK                         The parsing failed due to an internal error.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseOCSPResponseResponderId(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp);

/**********************************************************************************************************************
 * KeyM_Cert_ParseOCSPResponse()
 *********************************************************************************************************************/
/*! \brief         Parse OCSP response.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     requestDataLength                Length of data in the requestData array.
 *  \param[out]    ocspResp                         Holds the parsing information of the OCSP response.
 *  \return        E_OK                             OCSP response was parsed successfully.
 *                 E_NOT_OK                         The parsing failed due to an internal error.
 *  \pre           The passed array by ocspResp is always of size
 *                 KEYM_ASN1_OCSP_SIZE_OF_OCSP_RESPONSE_ELEMENT_STORAGE
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseOCSPResponse(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseStatus()
 *********************************************************************************************************************/
/*! \brief         Verify ResponseStatus element of OCSP response.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[out]    responseData                     OCSP status returned by the function.
 *  \param[in]     responseDataLength               Max number of bytes available in ResponseData.
 *  \return        E_OK                             Valid ResponseStatus.
 *                 E_NOT_OK                         Invalid ResponseStatus.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseStatus(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  uint32 responseDataLength);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseType()
 *********************************************************************************************************************/
/*! \brief         Verify ResponseType element of OCSP response.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \return        E_OK                             Valid ResponseType.
 *                 E_NOT_OK                         Invalid ResponseType.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseType(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseCertIdSerialNumber()
 *********************************************************************************************************************/
/*! \brief         Verify serial number in CertId element of OCSP response.
 *  \details       -
 *  \param[in]     certId                           Holds the certificate identifier of the certificate to be checked
 *                                                  for revocation.
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \return        E_OK                             Valid serial number.
 *                 E_NOT_OK                         Invalid serial number.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseCertIdSerialNumber(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp);

/**********************************************************************************************************************
 * KeyM_Cert_GetRSAPublicKey()
 *********************************************************************************************************************/
/*! \brief         Retrieves RSA public key.
 *  \details       -
 *  \param[in]     certId                           Holds the certificate identifier.
 *  \param[out]    responseData                     Pointer to output buffer.
 *  \param[out]    responseDataLength               Length of output buffer.
 *  \return        E_OK                             The public key could be retrieved successfully.
 *                 E_NOT_OK                         Due to an internal error, the public key could not be retrieved.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetRSAPublicKey(
  KeyM_CertificateIdType certId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) responseDataLength);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseCertIdIssuerNameHash()
 *********************************************************************************************************************/
/*! \brief         Verify name hash in CertId element of OCSP response.
 *  \details       -
 *  \param[in]     issuerCertId                     Holds the certificate identifier of the issuer of certificate
 *                                                  to be checked for revocation.
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     ocspId                           Holds the identifier of OCSP response configuration instance.
 *  \return        E_OK                             Valid hash over issuer's distinguished name.
 *                 E_NOT_OK                         Invalid hash over issuer's distinguished name.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseCertIdIssuerNameHash(
  KeyM_CertificateIdType issuerCertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseCertIdIssuerKeyHash()
 *********************************************************************************************************************/
/*! \brief         Verify public key hash in CertId element of OCSP response.
 *  \details       -
 *  \param[in]     issuerCertId                     Holds the certificate identifier of the issuer of certificate
 *                                                  to be checked for revocation.
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     ocspId                           Holds the identifier of OCSP response configuration instance.
 *  \return        E_OK                             Valid hash over issuer's public key hash.
 *                 E_NOT_OK                         Invalid hash over issuer's public key hash.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseCertIdIssuerKeyHash(
  KeyM_CertificateIdType issuerCertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseCertIdAttributes()
 *********************************************************************************************************************/
/*! \brief         Verify attributes in CertId element of OCSP response.
 *  \details       -
 *  \param[in]     certId                           Holds the certificate identifier of the certificate to be checked
 *                                                  for revocation.
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     ocspId                           Holds the identifier of OCSP response configuration instance.
 *  \return        E_OK                             Valid CertId attributes.
 *                 E_NOT_OK                         Invalid CertId attributes.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseCertIdAttributes(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseCertId()
 *********************************************************************************************************************/
/*! \brief         Verify CertId element of OCSP response.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[out]    certId                           Holds the certificate identifier of the certificate to be checked
 *                                                  for revocation.
 *  \param[out]    ocspId                           Holds the identifier of OCSP response configuration instance.
 *  \return        E_OK                             Valid CertId.
 *                 E_NOT_OK                         Invalid CertId.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseCertId(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) certId,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) ocspId);

# if ((KEYM_DELEGATEDRESPONDERREFIDXOFOCSP == STD_ON) && (KEYM_RESPONDERPUBKEYHASHCSMJOBREFOFOCSP == STD_ON))
/**********************************************************************************************************************
 * KeyM_Cert_GetOCSPResponderCertIdOfCertDataByKey()
 *********************************************************************************************************************/
/*! \brief         Retrieve certificate identifier of the OCSP responder.
 *  \details       -
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     ocspId                           Holds the identifier of OCSP response configuration instance.
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     certId                           Holds the certificate identifier of the certificate to be checked
 *                                                  for revocation.
 *  \param[out]    responderCertId                  Holds the certificate identifier of the OCSP responder.
 *  \param[out]    isResponderCertIdFound           Availability flag for certificate identifier of the OCSP responder.
 *  \return        E_OK                             The certificate identifier could be retrieved successfully.
 *                 E_NOT_OK                         Due to an internal error, the certificate identifier could not be
 *                                                  retrieved.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertIdOfCertDataByKey(
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) isResponderCertIdFound);
# endif

# if (KEYM_DELEGATEDRESPONDERREFIDXOFOCSP == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetOCSPResponderCertIdOfCertDataByName()
 *********************************************************************************************************************/
/*! \brief         Retrieve certificate identifier of the OCSP responder.
 *  \details       -
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     certId                           Holds the certificate identifier of the certificate to be checked
 *                                                  for revocation.
 *  \param[out]    responderCertId                  Holds the certificate identifier of the OCSP responder.
 *  \param[out]    isResponderCertIdFound           Availability flag for certificate identifier of the OCSP responder.
 *  \return        E_OK                             The certificate identifier could be retrieved successfully.
 *                 E_NOT_OK                         Due to an internal error, the certificate identifier could not be
 *                                                  retrieved.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertIdOfCertDataByName(
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) isResponderCertIdFound);
# endif

# if (KEYM_DELEGATEDRESPONDERREFIDXOFOCSP == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_SetOCSPCertificateInGroup()
 *********************************************************************************************************************/
/*! \brief         Set OCSP certificate dynamically.
 *  \details       -
 *  \param[in]     groupId                              Holds the identifier of the internal certificate group.
 *  \param[in]     requestData                          Pointer to OCSP response.
 *  \param[in]     requestDataLength                    Length of data in the requestData array.
 *  \param[out]    certId                               Holds the certificate identifier of the slot where data has
 *                                                      been installed.
 *  \return        E_OK                                 Service data operation successfully accepted.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_SetOCSPCertificateInGroup(
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certId);
# endif

# if (KEYM_DELEGATEDRESPONDERREFIDXOFOCSP == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetOCSPResponderCertIdOfCertData()
 *********************************************************************************************************************/
/*! \brief         Retrieve OCSP responder's certificate identifier of included certificate data.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     ocspId                           Holds the identifier of OCSP response configuration instance.
 *  \param[in]     groupId                          Holds the certificate group identifier.
 *  \param[in]     certData                         Included certificate data in OCSP response.
 *  \param[in]     certDataLength                   Length of included certificate data.
 *  \param[out]    responderCertId                  Holds the certificate identifier of the OCSP responder.
 *  \return        E_OK                             The OCSP responder's certificate identifier was retrieved successfully.
 *                 E_NOT_OK                         Due to internal the OCSP responder's certificate identifier could
 *                                                  be retrieved.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertIdOfCertData(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId,
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) certData,
  uint32 certDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId);
# endif

# if (KEYM_RESPONDERPUBKEYHASHCSMJOBREFOFOCSP == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetOCSPResponderCertIdOfIssuerByKey()
 *********************************************************************************************************************/
/*! \brief         Retrieve OCSP responder's certificate identifier for the case of key hash identification.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     ocspId                           Holds the identifier of OCSP response configuration instance.
 *  \param[in]     issuerCertId                     Holds the certificate identifier of the issuer of certificate
 *                                                  to be checked for revocation.
 *  \param[out]    responderCertId                  Holds the certificate identifier of the OCSP responder.
 *  \return        E_OK                             The OCSP responder's certificate identifier was retrieved successfully.
 *                 E_NOT_OK                         Due to internal the OCSP responder's certificate identifier could
 *                                                  be retrieved.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertIdOfIssuerByKey(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId,
  KeyM_CertificateIdType issuerCertId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId);
# endif

/**********************************************************************************************************************
 * KeyM_Cert_GetOCSPResponderCertIdOfIssuerByName()
 *********************************************************************************************************************/
/*! \brief         Retrieve OCSP responder's certificate identifier for the case of name hash identification.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     issuerCertId                     Holds the certificate identifier of the issuer of certificate
 *                                                  to be checked for revocation.
 *  \param[out]    responderCertId                  Holds the certificate identifier of the OCSP responder.
 *  \return        E_OK                             The OCSP responder's certificate identifier was retrieved successfully.
 *                 E_NOT_OK                         Due to internal the OCSP responder's certificate identifier could
 *                                                  be retrieved.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertIdOfIssuerByName(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  KeyM_CertificateIdType issuerCertId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId);

/**********************************************************************************************************************
 * KeyM_Cert_GetOCSPResponderCertIdOfIssuer()
 *********************************************************************************************************************/
/*! \brief         Retrieve OCSP responder's certificate identifier of certificate's issuer.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     ocspId                           Holds the identifier of OCSP response configuration instance.
 *  \param[in]     certId                           Holds the certificate identifier of the certificate to be checked
 *                                                  for revocation.
 *  \param[out]    responderCertId                  Holds the certificate identifier of the OCSP responder.
 *  \return        E_OK                             The OCSP responder's certificate identifier was retrieved successfully.
 *                 E_NOT_OK                         Due to internal the OCSP responder's certificate identifier could
 *                                                  be retrieved.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertIdOfIssuer(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId,
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId);

/**********************************************************************************************************************
 * KeyM_Cert_GetOCSPResponderCertId()
 *********************************************************************************************************************/
/*! \brief         Retrieve OCSP responder's certificate identifier.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     ocspId                           Holds the identifier of OCSP response configuration instance.
 *  \param[in]     certId                           Holds the certificate identifier of the certificate to be checked
 *                                                  for revocation.
 *  \param[in,out] responderCertId                  Holds the certificate identifier of the OCSP responder.
 *  \return        E_OK                             The OCSP responder's certificate identifier was retrieved successfully.
 *                 E_NOT_OK                         Due to internal the OCSP responder's certificate identifier could
 *                                                  be retrieved.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertId(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId,
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId);

/**********************************************************************************************************************
 * KeyM_Cert_GetOCSPResponseSignatureElement_X509_ECDSA()
 *********************************************************************************************************************/
/*! \brief         Return signature element of OCSP response.
 *  \details       -
 *  \param[in]     requestData           Pointer to OCSP response.
 *  \param[in]     requestDataLength     Length of data in the requestData array.
 *  \param[out]    responseData          Pointer to output buffer.
 *  \param[in,out] responseDataLength    Length of output buffer.
 *  \return        E_OK                  The signature element was retrieved successfully.
 *                 E_NOT_OK              Due to internal error, the signature element could not be retrieved.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponseSignatureElement_X509_ECDSA(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) responseDataLength);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseSignature()
 *********************************************************************************************************************/
/*! \brief         Verify signature element of OCSP response.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     ocspId                           Holds the identifier of OCSP response configuration instance.
 *  \param[in]     certId                           Holds the certificate identifier of the certificate to be checked.
 *  \param[out]    responderCertId                  Holds the certificate identifier of the responder certificate
 *                                                  for revocation.
 *  \return        E_OK                             Valid OCSP response signature.
 *  \return        E_NOT_OK                         Due to internal error the response signature could not be verified.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseSignature(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId,
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponderSignature()
 *********************************************************************************************************************/
/*! \brief         Verify signature of certificate in chain of responder.
 *  \details       -
 *  \param[in,out] localCertId                      In:  Holds the certificate identifier of the current certificate.
 *                                                  Out: Holds the certificate identifier of the certificate for the
 *                                                       following verification cycle.
 *  \param[in,out] issuerCertId                     In:  Holds the certificate identifier of the current issuer.
 *                                                  Out: Holds the certificate identifier of the issuer for the
 *                                                       following verification cycle.
 *  \return        E_OK
 *  \return        E_NOT_OK
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponderSignature(
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) localCertId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) issuerCertId);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponder()
 *********************************************************************************************************************/
/*! \brief         Verify the responder certificate.
 *  \details       -
 *  \param[in]     responderCertId                   Holds the certificate identifier of responder certificate.
 *  \return        E_OK                              Valid OCSP responder certificate.
 *  \return        E_NOT_OK                          Due to internal error the responder certificate could not be verified.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponder(
  KeyM_CertificateIdType responderCertId);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseNextUpdateTime()
 *********************************************************************************************************************/
/*! \brief         Verify optional nextUpdate time element of OCSP response.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     certTime                         Current timestamp in unix format.
 *  \return        E_OK                             Validity period was validated successfully.
 *                 E_NOT_OK                         Invalid validity period.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseNextUpdateTime(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint64 certTime);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseThisUpdateTime()
 *********************************************************************************************************************/
/*! \brief         Verify thisUpdate time element of OCSP response.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     certTime                         Current timestamp in unix format.
 *  \return        E_OK                             Validity period was validated successfully.
 *                 E_NOT_OK                         Invalid validity period.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseThisUpdateTime(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint64 certTime);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseTime()
 *********************************************************************************************************************/
/*! \brief         Verify validity period of OCSP response.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     certId                           Holds the certificate identifier of the certificate to be checked
 *                                                  for revocation.
 *  \return        E_OK                             Validity period was validated successfully.
 *                 E_NOT_OK                         Invalid validity period.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseTime(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseVersion()
 *********************************************************************************************************************/
/*! \brief         Verify version element of OCSP response.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \return        E_OK                             Valid version.
 *                 E_NOT_OK                         Invalid version.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseVersion(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp);

/**********************************************************************************************************************
 * KeyM_Cert_OCSPResponseRevokeCert()
 *********************************************************************************************************************/
/*! \brief         Initiate certificate revocation.
 *  \details       -
 *  \param[in]     certId                           Holds the certificate identifier of the certificate to be checked
 *                                                  for revocation.
 *  \return        E_OK                             Certificate revocation was initiated successfully.
 *                 E_NOT_OK                         Due to an internal error, the certificate revocation could
 *                                                  not be handled.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_OCSPResponseRevokeCert(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseCertStatus()
 *********************************************************************************************************************/
/*! \brief         Verify CertStatus element of OCSP response.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[in]     certId                           Holds the certificate identifier of the certificate to be checked
 *                                                  for revocation.
 *  \return        E_OK                             Valid CertStatus.
 *                 E_NOT_OK                         Invalid CertStatus.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseCertStatus(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponseData()
 *********************************************************************************************************************/
/*! \brief         Verify OCSP response attributes .
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[out]    responseData                     OCSP status returned by the function.
 *  \param[in]     responseDataLength               Max number of bytes available in responseData.
 *  \param[out]    certId                           Holds the certificate identifier of the certificate
 *                                                  with status information.
 *  \param[out]    responderCertId                  Holds the certificate identifier of the responder certificate.
 *  \return        E_OK                             The OCSP Response could be verified successfully.
 *                 E_NOT_OK                         Due to internal error, the OCSP Response could not be verified.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseData(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  uint32 responseDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyOCSPResponse()
 *********************************************************************************************************************/
/*! \brief         Verify OCSP response.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     ocspResp                         Holds the parsing information of the OCSP response.
 *  \param[out]    responseData                     OCSP status returned by the function.
 *  \param[in]     responseDataLength               Max number of bytes available in responseData.
 *  \return        E_OK                             The OCSP Response could be verified successfully.
 *                 E_NOT_OK                         Due to internal error, the OCSP Response could not be verified.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponse(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  uint32 responseDataLength);

/**********************************************************************************************************************
 * KeyM_Cert_HandleOCSPResponse()
 *********************************************************************************************************************/
/*! \brief         Handle parsing and verification of OCSP Response.
 *  \details       -
 *  \param[in]     requestData                      Pointer to OCSP response.
 *  \param[in]     requestDataLength                Length of data in the requestData array.
 *  \param[out]    responseData                     OCSP status returned by the function.
 *  \param[in]     responseDataLength               Max number of bytes available in ResponseData.
 *  \return        E_OK                             The OCSP Response could be parsed and verified successfully.
 *                 E_NOT_OK                         Due to internal error, the OCSP Response could not be processed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_HandleOCSPResponse(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  uint32 responseDataLength);
#endif

#if ((KEYM_OCSP == STD_ON) || ((KEYM_REMOTE_OCSPENABLED == STD_ON))) /* COV_REMOTE_OCSP */
/**********************************************************************************************************************
 * KeyM_Cert_ServiceCertStatusOCSP()
 *********************************************************************************************************************/
/*! \brief         Handle certificate status message of TLS handshake with OCSP stapling.
 *  \details       -
 *  \param[in]     Service                          Provides the type of service the key manager has to perform.
 *  \param[in]     CertNamePtr                      Points to an array that defines the name of the certificate.
 *  \param[in]     CertNameLength                   Specifies the number of bytes in CertNamePtr.
 *  \param[in]     RequestData                      Information that comes along with the request.
 *  \param[in]     RequestDataLength                Length of data in the RequestData array.
 *  \param[out]    ResponseData                     OCSP status returned by the function.
 *  \param[in]     ResponseDataLength               Max number of bytes available in ResponseData.
 *  \return        E_OK                             Service data operation successfully accepted.
 *                 E_NOT_OK                         Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertStatusOCSP(
  KeyM_ServiceCertificateType Service,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength);
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_ServiceCertSet()
 *********************************************************************************************************************/
/*! \brief         Sets root or intermediate certificate.
 *  \details       Refer to KeyM_ServiceCertificate.
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in]     RequestData                      Information that comes along with the request.
 *  \param[in]     RequestDataLength                Length of data in the RequestData array.
 *  \return        E_OK                             Service data operation successfully accepted.
 *                 E_NOT_OK                         Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertSet(
  KeyM_CertificateIdType CertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength);
#endif

#if ((KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON) && (KEYM_ELEMENTOIDPRIMARYUSEDOFCERTIFICATEGROUP == STD_ON))
/**********************************************************************************************************************
 * KeyM_Cert_IsGroupHeterogeneous()
 *********************************************************************************************************************/
/*! \brief         Checks if a given (external) group has certificates of heterogeneous configurations.
 *  \details       Heterogeneous groups are groups where the contained certificates do not all have the same
 *                 configurations. A group where all certificates have the same configuration, in contrast, is called
 *                 homogenous.
 *  \param[in]     groupId                          Holds the certificate group identifier.
 *  \return        TRUE                             Group is heterogeneous.
 *                 FALSE                            Group is homogenous.
 *  \pre           groupId must be a valid external group ID, i.e., groupId < KeyM_GetSizeOfCertificateGroupExt()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires groupId < KeyM_GetSizeOfCertificateGroupExt();                                     \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsGroupHeterogeneous(
  KeyM_CertificateGroupIdType groupId);
#endif

#if ((KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON) && (KEYM_ELEMENTOIDPRIMARYUSEDOFCERTIFICATEGROUP == STD_ON))
/**********************************************************************************************************************
 * KeyM_Cert_GetSubGroupId()
 *********************************************************************************************************************/
/*! \brief         Retrieves the sub group ID for a given external group and certificate data.
 *  \details       -
 *  \param[in]     groupId                          Holds the (external) certificate group identifier.
 *  \param[in]     certData                         Certificate data for which a sub group ID shall be determined.
 *  \param[in]     certDataLength                   Length of data in the certDataLength array.
 *  \param[out]    subGroupId                       Holds the certificate group identifier of the sub group.
 *  \return        E_OK                             Group identifier of sub group could be retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, group identifier of sub group could
 *                                                  not be retrieved.
 *  \pre           groupId must be a valid external group ID, i.e., groupId < KeyM_GetSizeOfCertificateGroupExt()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires groupId < KeyM_GetSizeOfCertificateGroupExt();
 *                 requires certData != NULL_PTR;
 *                 requires subGroupId != NULL_PTR;                                                            \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetSubGroupId(
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) certData,
  uint32 certDataLength,
  P2VAR(KeyM_CertificateGroupIdType, AUTOMATIC, KEYM_APPL_VAR) subGroupId);
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_IsCertDataLengthOfGroupInvalid()
 *********************************************************************************************************************/
/*! \brief         Check validity of certificate data length for a dynamic group.
 *  \details       -
 *  \param[in]     groupId                          Holds the certificate group identifier.
 *  \param[in]     RequestDataLength                Data length of data.
 *  \return        TRUE                             Data length is invalid.
 *                 FALSE                            Data length is valid.
 *  \pre           groupId must be a valid group ID, i.e., groupId < KeyM_GetSizeOfCertificateGroup()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertDataLengthOfGroupInvalid(
  KeyM_CertificateGroupIdType groupId,
  uint32 RequestDataLength);
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetSubjectCommonName()
 *********************************************************************************************************************/
/*! \brief         Get subject common name of certificate data.
 *  \details       -
 *  \param[in]     requestData                      Pointer to the certificate data.
 *  \param[in]     requestDataLength                Holds the length of the certificate data.
 *  \param[out]    subjectCommonNameData            Subject common name data returned by this function.
 *  \param[in,out] subjectCommonNameDataLength      In: Max number of bytes available in subjectCommonNameData.
 *                                                  Out: Actual number of bytes in subjectCommonNameData
 *  \return        E_OK                             The subject common name was retrieved successfully.
 *                 E_NOT_OK                         The subject common name was not found within the certificate data.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires $lengthOf(subjectCommonNameData) >= *subjectCommonNameDataLength;                  \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetSubjectCommonName(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) subjectCommonNameData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) subjectCommonNameDataLength);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_IsLowerCertAvailable()
 *********************************************************************************************************************/
/*! \brief         Checks if a certificate in the lower hierarchy of the chain has been set.
 *  \details       -
 *  \param[in]     certId              Holds the identifier of the certificate.
 *  \return        TRUE                Certificate in lower hierarchy is available.
 *                 FALSE               Certificate in lower hierarchy is not available.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsLowerCertAvailable(
  KeyM_CertificateIdType certId);

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_IsCRESet()
 *********************************************************************************************************************/
/*! \brief         Checks if a certificate revocation entry is set.
 *  \details       -
 *  \param[in]     IssuerNameData                   Points to an array that defines the issuer common name of the
 *                                                  revoked certificate.
 *  \param[in]     IssuerNameDataLength             Length of issuer common name data.
 *  \param[in]     SerialNumberData                 Points to an array that defines the serial number of the
 *                                                  revoked certificate.
 *  \param[in]     SerialNumberDataLength           Length of serial number data.
 *  \return        TRUE                             Certificate revocation entry is set
 *                 FALSE                            Certificate revocation entry is not set yet
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCRESet(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength);
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_AppendCRE()
 *********************************************************************************************************************/
/*! \brief         Appends a new certificate revocation entry to previously set ones.
 *  \details       -
 *  \param[in]     IssuerNameData                   Points to an array that defines the issuer common name of the
 *                                                  revoked certificate.
 *  \param[in]     IssuerNameDataLength             Length of issuer common name data.
 *  \param[in]     SerialNumberData                 Points to an array that defines the serial number of the
 *                                                  revoked certificate.
 *  \param[in]     SerialNumberDataLength           Length of serial number data.
 *  \return        E_OK                             Certificate revocation entry was appended successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate revocation entry could not
 *                                                  be appended.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_AppendCRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength);
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_UpdateCertStatusForCRE()
 *********************************************************************************************************************/
/*! \brief         Updates certificate status for revoked certificate and certificates in lower hierarchy.
 *  \details       -
 *  \param[in]     IssuerNameData                   Points to an array that defines the issuer common name of the
 *                                                  revoked certificate.
 *  \param[in]     IssuerNameDataLength             Length of issuer common name data.
 *  \param[in]     SerialNumberData                 Points to an array that defines the serial number of the revoked
 *                                                  certificate.
 *  \param[in]     SerialNumberDataLength           Length of serial number data.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_UpdateCertStatusForCRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength);
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_IsCertRevokedBySingleCRE()
 *********************************************************************************************************************/
/*! \brief         Checks the revocation status of a referenced certificate by a single certificate revocation entry.
 *  \details       -
 *  \param[in]     certId                           Holds the certificate identifier.
 *  \param[in]     IssuerNameData                   Points to an array that defines the issuer common name of the
 *                                                  revoked certificate.
 *  \param[in]     IssuerNameDataLength             Length of issuer common name data.
 *  \param[in]     SerialNumberData                 Points to an array that defines the serial number of the revoked
 *                                                  certificate.
 *  \param[in]     SerialNumberDataLength           Length of serial number data.
 *  \return        TRUE                             Certificate is revoked.
 *                 FALSE                            Certificate is not revoked.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertRevokedBySingleCRE(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength);
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_InvalidateLowerCert()
 *********************************************************************************************************************/
/*! \brief         Invalidates certificates in lower hierarchy according to referenced certificate.
 *  \details       -
 *  \param[in]     certId                           Holds the certificate identifier.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_InvalidateLowerCert(
  KeyM_CertificateIdType certId);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_CheckChainStorageInternal()
 *********************************************************************************************************************/
/*! \brief         Parse chain from top to bottom and check storage.
 *  \details       -
 *  \param[in,out] certId                Holds the identifier of the certificate.
 *  \param[in]     certChain             Holds pointer to an array for the current certificate chain.
 *  \param[in]     certIdx               Holds the identifier of the certificate from which the parsing of the chain
 *                                       will start with.
 *  \return        E_OK                  The storage type of the certificates in the current chain was checked
 *                                       successfully.
 *                 E_NOT_OK              Due to internal error, the storage type could not be checked.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CheckChainStorageInternal(
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) certId,
  P2CONST(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) certChain,
  KeyM_CertificateIterType certIdx);

/**********************************************************************************************************************
 * KeyM_Cert_CheckChainStorage()
 *********************************************************************************************************************/
/*! \brief         Check storage type of certificates in chain of referenced certificate.
 *  \details       Return certificate identifier of lowest certificate in chain that is not set yet.
 *  \param[in,out] certId                Holds the identifier of the certificate.
 *  \return        E_OK                  The storage type of the certificates in the current chain was checked
 *                                       successfully.
 *                 E_NOT_OK              Due to internal error, the storage type could not be checked.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CheckChainStorage(
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) certId);

#if ((KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_IsCertInChainOfCA()
 *********************************************************************************************************************/
/*! \brief         Check whether a certificate is part of the certificate chain of an CA certificate.
 *  \details       -
 *  \param[in]     wCertId              Holds the identifier of the working certificate.
 *  \param[in]     caCertId             Holds the identifier of the CA certificate.
 *  \return        TRUE                 Working certificate is part of chain.
 *                 FALSE                Working certificate is not part of chain.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertInChainOfCA(
  KeyM_CertificateIdType wCertId,
  KeyM_CertificateIdType caCertId);
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_IsCertLeaf()
 *********************************************************************************************************************/
/*! \brief         Check if referenced certificate is a leaf.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of certificate.
 *  \return        TRUE                 Certificate is a leaf.
 *                 FALSE                Certificate is not a leaf.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertLeaf(
  KeyM_CertificateIdType certId);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_IsCertRoot()
 *********************************************************************************************************************/
/*! \brief         Check if given certificate is a root.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of certificate.
 *  \return        TRUE                 Certificate is a root.
 *                 FALSE                Certificate is not a root.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertRoot(
  KeyM_CertificateIdType certId);

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_IsCertIntermediate()
 *********************************************************************************************************************/
/*! \brief         Check if given certificate is an intermediate.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of certificate.
 *  \return        TRUE                 Certificate is an intermediate.
 *                 FALSE                Certificate is not an intermediate.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertIntermediate(
  KeyM_CertificateIdType certId);
#endif

#if ((KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_GetRootCertId()
 *********************************************************************************************************************/
/*! \brief         Retrieves root certificate identifier.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of a certificate in the chain.
 *  \param[in,out] rootCertId           Holds the identifier of the root certificate.
 *  \return        E_OK                 The certificate identifier of the root certificate was retrieved successfully.
 *                 E_NOT_OK             Due to invalid chain, the root certificate identifier could not be retrieved.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetRootCertId(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) rootCertId);
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetEmptyGroupCertId()
 *********************************************************************************************************************/
/*! \brief         Get certificate identifier of an empty dynamic group slot.
 *  \details       All certificate slots of the referenced group are iterated and the certificate identifier for a slot
 *                 without certificate data is returned.
 *  \param[in]     groupId              Holds the certificate group identifier.
 *  \param[out]    certId               Holds the identifier of the certificate.
 *  \return        E_OK                 The certificate identifier of an empty group slot was retrieved successfully.
 *                 E_NOT_OK             No empty group slot was found.
 *  \pre           All provided pointers must be valid.
 *                 groupId must be a valid group ID, i.e., groupId < KeyM_GetSizeOfCertificateGroup()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetEmptyGroupCertId(
  KeyM_CertificateGroupIdType groupId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) certId);
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_SearchSubjectCommonNameDataInGroup()
 *********************************************************************************************************************/
/*! \brief         Search subject common name within group certificates.
 *  \details       -
 *  \param[in]     groupId                          Holds the identifier of the certificate group.
 *  \param[in]     subjectCommonNameData            Pointer to the subject common name data.
 *  \param[in]     subjectCommonNameDataLength      Holds the length of the subject common name data.
 *  \param[out]    refCertId                        Holds the certificate identifier of the certificate
 *                                                  with the subject name of interest.
 *  \return        E_OK                             Referenced subject common name was found successfully.
 *                 E_NOT_OK                         Referenced subject common name was not found within the group.
 *  \pre           All provided pointers must be valid.
 *                 groupId must be a valid group ID, i.e., groupId < KeyM_GetSizeOfCertificateGroup()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_SearchSubjectCommonNameDataInGroup(
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) subjectCommonNameData,
  uint32 subjectCommonNameDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) refCertId);
#endif

#if ((KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_IsCertInPKI()
 *********************************************************************************************************************/
/*! \brief         Check whether a certificate is part of the PKI.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate to be checked.
 *  \param[in]     refCertId            Holds the identifier of the reference certificate.
 *  \return        TRUE                 Certificate is part of PKI.
 *                 FALSE                Certificate is not part of PKI.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertInPKI(
  KeyM_CertificateIdType certId,
  KeyM_CertificateIdType refCertId);
#endif

  /**********************************************************************************************************************
 * KeyM_Cert_IsSameIssuer()
 *********************************************************************************************************************/
/*! \brief         Checks whether two certificates have the same issuer.
 *  \details       -
 *  \param[in]     certId1              Holds the identifier of the first certificate to be checked.
 *  \param[in]     certId2              Holds the identifier of the second certificate to be checked.
 *  \return        TRUE                 Certificates have the same issuer.
 *                 FALSE                Certificates have different issuers.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsSameIssuer(
  KeyM_CertificateIdType certId1,
  KeyM_CertificateIdType certId2);

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_ServiceCertUpdateTriggerVerification()
 *********************************************************************************************************************/
/*! \brief         Trigger verification of certificates in the context of a certificate update service request.
 *  \details       -
 *  \param[in]     certId                               Holds the identifier of the certificate.
 *  \return        E_OK                                 Certificate verification request accepted. Operation will be
 *                                                      performed in the background and response is given through a
 *                                                      callback.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_BUSY                          Validation cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_EMPTY                One of the certificate slots are empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   An upper certificate is not valid.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertUpdateTriggerVerification(
  KeyM_CertificateIdType certId);
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_ServiceCertUpdateData()
 *********************************************************************************************************************/
/*! \brief         Update certificate data in RAM slot.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \param[in]     requestData          Certificate data that comes along with the request.
 *  \param[in]     requestDataLength    Length of certificate data in the requestData array.
 *  \return        E_OK                 Certificate data was updated successfully.
 *                 E_NOT_OK             Internal error occurred due to invalid dynamic issuer.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertUpdateData(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength);
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_ServiceCertUpdateCertId()
 *********************************************************************************************************************/
/*! \brief         Identify certificate identifier of available certificates in the lowest chain hierarchy.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \return        E_OK                 The certificate identifiers of available certificates in the lowest chain
 *                                      hierarchy were stored successfully.
 *                 E_NOT_OK             Internal error occurred due to an invalid chain.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertUpdateCertId(
  KeyM_CertificateIdType certId);
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_ServiceCertUpdateStatus()
 *********************************************************************************************************************/
/*! \brief         Update certificate status of certificates in lower chain hierarchies in the context of a
 *                 certificate update service request.
 *  \details       -
 *  \param[in]     certIdOfUpdate       Holds the identifier of the certificate to be updated.
 *  \param[in]     certIdOfInvalidation Holds the identifier of the certificate to be invalidated.
 *  \return        E_OK                 The certificate status could be updated successfully.
 *                 E_NOT_OK             Internal error occurred due to an invalid chain.
 *  \pre           certIdOfUpdate must be a valid certificate Id.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertUpdateStatus(
  KeyM_CertificateIdType certIdOfUpdate,
  KeyM_CertificateIdType certIdOfInvalidation);
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_ServiceCertUpdatePrepare()
 *********************************************************************************************************************/
/*! \brief         Prepare verification triggered in the context of a certificate update service request.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \return        E_OK                 The certificate update request was prepared successfully.
 *                 E_NOT_OK             Internal error occurred.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertUpdatePrepare(
  KeyM_CertificateIdType certId);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_StateCheckSubjectCommonNameCmp()
 *********************************************************************************************************************/
/*! \brief         Compare subject and issuer common name fields.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \param[in]     issuerCertId         Holds the identifier of the issuer certificate.
 *  \return        E_OK                 Subject common name field of the certificate in the upper hierarchy matches
 *                                      the issuer common names field of the certificate in the lower hierarchy.
 *                 E_NOT_OK             Check fails, due to non-matching common names.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 issuerCertId must be a valid certificate ID, i.e., issuerCertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateCheckSubjectCommonNameCmp(
  KeyM_CertificateIdType certId,
  KeyM_CertificateIdType issuerCertId);

/**********************************************************************************************************************
 * KeyM_Cert_CheckValidityPeriod()
 *********************************************************************************************************************/
/*! \brief         Check current time in respect to certificate validity period.
 *  \details       -
 *  \param[in]     certTime             Current timestamp in unix format.
 *  \param[in]     notBeforeTime        Not before time in standard time format.
 *  \param[in]     notAfterTime         Not after time in standard time format.
 *  \return        E_OK                 Certificate is within its validity period.
 *                 E_NOT_OK             Check fails, due to invalid period.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CheckValidityPeriod(
  uint64 certTime,
  P2CONST(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) notBeforeTime,
  P2CONST(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) notAfterTime);

/**********************************************************************************************************************
 * KeyM_Cert_ParseValidityPeriod()
 *********************************************************************************************************************/
/*! \brief         Retrieve certificate validity period from certificate data.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \param[out]    notBeforeTime        Pointer to output buffer for parsed not before time.
 *  \param[out]    notAfterTime         Pointer to output buffer for parsed not after time.
 *  \return        E_OK                 The validity period was retrieved successfully from the certificate data.
 *                 E_NOT_OK             Due to internal error, the validity period could not be retrieved.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseValidityPeriod(
  KeyM_CertificateIdType certId,
  P2VAR(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) notBeforeTime,
  P2VAR(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) notAfterTime);

/**********************************************************************************************************************
 * KeyM_Cert_GetCurrentTime()
 *********************************************************************************************************************/
/*! \brief         Retrieve current timestamp via callout or StbM.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \param[out]    certTime             Returned current timestamp in unix format.
 *  \param[out]    isPeriodValidityUsed Returned usage status of the period validity.
 *  \return        E_OK                 The current timestamp was retrieved successfully.
 *                 E_NOT_OK             Due to internal error, the current timestamp could not be retrieved.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCurrentTime(
  KeyM_CertificateIdType certId,
  P2VAR(uint64, AUTOMATIC, AUTOMATIC) certTime,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) isPeriodValidityUsed);

/**********************************************************************************************************************
 * KeyM_Cert_GetPubKeyElementsRSA()
 *********************************************************************************************************************/
/*! \brief         Retrieve public key elements for RSA signature verification operation.
 *  \details       -
 *  \param[in]     certId                      Holds the identifier of the certificate.
 *  \param[in]     elementIdx                  Holds the certificate element index.
 *  \param[out]    pubKey                      Pointer to the offset and length for the public key sub-elements.
 *  \return        E_OK                        The public key elements were retrieved successfully.
 *                 E_NOT_OK                    Due to internal error, the public key elements could not be retrieved.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetPubKeyElementsRSA(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(KeyM_CertPubKeyType, AUTOMATIC, AUTOMATIC) pubKey);

/**********************************************************************************************************************
 * KeyM_Cert_GetPubKeyElementsECC()
 *********************************************************************************************************************/
/*! \brief         Retrieve public key elements for ECC signature verification operation.
 *  \details       -
 *  \param[in]     certId                      Holds the identifier of the certificate.
 *  \param[in]     elementIdx                  Holds the certificate element index.
 *  \param[out]    pubKey                      Pointer to the offset and length for the public key sub-elements.
 *  \return        E_OK                        The public key elements were retrieved successfully.
 *                 E_NOT_OK                    Due to internal error, the public key elements could not be retrieved.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetPubKeyElementsECC(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(KeyM_CertPubKeyType, AUTOMATIC, AUTOMATIC) pubKey);

/**********************************************************************************************************************
 * KeyM_Cert_StateSetKeyX509ECC()
 *********************************************************************************************************************/
/*! \brief         Set X509 ECC public key in corresponding CSM key element.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \return        E_OK                            The public key was set successfully.
 *                 E_NOT_OK                        Due to internal error, the public key could not be set.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateSetKeyX509ECC(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_StateSetKeyCVCECC()
 *********************************************************************************************************************/
/*! \brief         Set CVC ECC public key in corresponding CSM key element.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \return        E_OK                            The public key was set successfully.
 *                 E_NOT_OK                        Due to internal error, the public key could not be set.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateSetKeyCVCECC(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_StateSetKeyRSA()
 *********************************************************************************************************************/
/*! \brief         Set RSA public key in corresponding CSM key element.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \return        E_OK                            The public key was set successfully.
 *                 E_NOT_OK                        Due to internal error, the public key could not be set.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateSetKeyRSA(
  KeyM_CertificateIdType certId);

#if (KEYM_CERTIFICATESETKEYCALLOUT == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_StateSetKeyCallout()
 *********************************************************************************************************************/
/*! \brief         Call to configurable callout to set public key in corresponding CSM key element.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \return        E_OK                            The public key was set successfully.
 *                 E_NOT_OK                        Due to internal error, the public key could not be set.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires KeyM_IsCertificateSetKeyCalloutUsedOfCertificate(certId);                          \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateSetKeyCallout(
  KeyM_CertificateIdType certId);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_ParseCRL()
 *********************************************************************************************************************/
/*! \brief         Parse certificate revocation list data and return revocation status of referenced certificate.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \param[in]     crlCertId            Holds the identifier of the certificate revocation list.
 *  \param[in]     crlElementIdx        Holds the certificate element index of the list element of revoked certificates.
 *  \param[in]     serialNumElementIdx  Holds the certificate element index of the serial number.
 *  \param[out]    isRevoked            Holds the returned revocation status.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 crlCertId must be a valid certificate ID, i.e., crlCertId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_ParseCRL(
  KeyM_CertificateIdType certId,
  KeyM_CertificateIdType crlCertId,
  KeyM_SizeOfCertificateElementType crlElementIdx,
  KeyM_SizeOfCertificateElementType serialNumElementIdx,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) isRevoked);

/**********************************************************************************************************************
 * KeyM_Cert_StateNotifyErrorHandling()
 *********************************************************************************************************************/
/*! \brief         Handle error during service request.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[out]    localTaskState                  Holds the returned task state.
 *  \param[out]    serviceResult                   Holds the returned service result.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateNotifyErrorHandling(
  KeyM_CertificateIdType certId,
  P2VAR(tKeyMCertTaskState, AUTOMATIC, AUTOMATIC) localTaskState,
  P2VAR(KeyM_ResultType, AUTOMATIC, AUTOMATIC) serviceResult);

/**********************************************************************************************************************
 * KeyM_Cert_StateNotifyValidateChainIncomplete()
 *********************************************************************************************************************/
/*! \brief         Trigger verification for certificates in the current chain that need to be validated.
 *  \details       -
 *  \param[out]    localTaskState                  Holds the returned task state.
 *  \param[out]    serviceResult                   Holds the returned service result.
 *  \param[out]    isVerificationTriggered         Holds the returned verification status.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateNotifyValidateChainIncomplete(
  P2VAR(tKeyMCertTaskState, AUTOMATIC, AUTOMATIC) localTaskState,
  P2VAR(KeyM_ResultType, AUTOMATIC, AUTOMATIC) serviceResult,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) isVerificationTriggered);

/**********************************************************************************************************************
 * KeyM_Cert_StateNotifyValidateChain()
 *********************************************************************************************************************/
/*! \brief         Trigger verification for certificates in different certificate chain that need to be validated.
 *  \details       -
 *  \param[out]    localTaskState                  Holds the returned task state.
 *  \param[out]    serviceResult                   Holds the returned service result.
 *  \param[out]    isVerificationTriggered         Holds the returned verification status.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateNotifyValidateChain(
  P2VAR(tKeyMCertTaskState, AUTOMATIC, AUTOMATIC) localTaskState,
  P2VAR(KeyM_ResultType, AUTOMATIC, AUTOMATIC) serviceResult,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) isVerificationTriggered);

/**********************************************************************************************************************
 * KeyM_Cert_StateNotifyFinish()
 *********************************************************************************************************************/
/*! \brief         Update global RAM variables after finished service request.
 *  \details       -
 *  \param[out]    localTaskState                  Holds the returned task state.
 *  \param[out]    serviceResult                   Holds the returned service result.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateNotifyFinish(
  P2VAR(tKeyMCertTaskState, AUTOMATIC, AUTOMATIC) localTaskState,
  P2VAR(KeyM_ResultType, AUTOMATIC, AUTOMATIC) serviceResult);

/**********************************************************************************************************************
 * KeyM_Cert_ServiceCertificateCallbackNotification()
 *********************************************************************************************************************/
/*! \brief         Call configured service certificate callback notification for the application.
 *  \details       -
 *  \param[in]     serviceResult                   Holds the service result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_ServiceCertificateCallbackNotification(
  KeyM_ResultType serviceResult);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyCallbackNotification()
 *********************************************************************************************************************/
/*! \brief         Call configured verify callback notification for the application.
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_VerifyCallbackNotification(void);

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_VerifyGroupCallbackNotification()
 *********************************************************************************************************************/
/*! \brief         Call configured certificate group verification callback notification for the application.
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_VerifyGroupCallbackNotification(void);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_StateNotifyAppl()
 *********************************************************************************************************************/
/*! \brief         Call configured callback notifications for the application.
 *  \details       -
 *  \param[in]     serviceResult                   Holds the service result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateNotifyAppl(
  KeyM_ResultType serviceResult);

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_ServiceCertUpdate()
 *********************************************************************************************************************/
/*! \brief         Updates root or intermediate certificate.
 *  \details       Refer to KeyM_ServiceCertificate.
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     RequestData                          Information that comes along with the request.
 *  \param[in]     RequestDataLength                    Length of data in the RequestData array.
 *  \return        E_OK                                 Service data operation successfully accepted.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *                 KEYM_E_BUSY                          Service cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_KEY_CERT_EMPTY                Certificate slot is empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   Invalid chain of trust.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertUpdate(
  KeyM_CertificateIdType CertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_IdentifyInvalidChain()
 *********************************************************************************************************************/
/*! \brief         Identify upper certificate pair to continue verification with
 *  \details       -
 *  \param[in,out] certId               Holds the identifier of lower certificate.
 *  \param[in,out] certUpperId          Holds the identifier of upper certificate.
 *  \return        E_OK                 Upper certificate pair was determined successfully.
 *                 E_NOT_OK             Internal error, due to invalid chain references.
 *  \pre           All provided pointers must be valid.
 *                 The values referenced by certId and certUpperId must be valid certificate IDs, i.e.,
 *                 certId < KeyM_GetSizeOfCertificate() and certUpperId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires certId != NULL_PTR;
 *                 requires certUpperId != NULL_PTR;
 *                 requires *certId < KeyM_GetSizeOfCertificate();
 *                 requires *certUpperId < KeyM_GetSizeOfCertificate();                                        \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_IdentifyInvalidChain(
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certUpperId);

/**********************************************************************************************************************
 * KeyM_Cert_ChainCpyToDataBuffer()
 *********************************************************************************************************************/
/*! \brief         Copy passed certificate data to associated certificate slots in global RAM buffer.
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     certChainData                    Holds an array with certificate data.
 *  \param[in]     numberOfCertificates             Number of certificates in input array
 *  \return        E_OK                             Certificate data was copied successfully to the associated
 *                                                  certificate slots.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *  \pre           certChainData and all contained certData pointers must be valid
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate(); \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ChainCpyToDataBuffer(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 numberOfCertificates);

/**********************************************************************************************************************
 * KeyM_Cert_TriggerStateAfterVerification()
 *********************************************************************************************************************/
/*! \brief         Advance state machine after verification.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_TriggerStateAfterVerification(
  KeyM_CertificateIdType certId);

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_CheckIssuerValidity()
 *********************************************************************************************************************/
/*! \brief         Check if issuer certificate is valid.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CheckIssuerValidity(
  KeyM_CertificateIdType certId);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_TriggerStateAfterCertElementVerification()
 *********************************************************************************************************************/
/*! \brief         Advance state machine after certificate element verification.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_TriggerStateAfterCertElementVerification(
  KeyM_CertificateIdType certId);

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_InvalidateChildCertStatus()
 *********************************************************************************************************************/
/*! \brief         Invalidates certificate status of certificates in lower hierarchies of the referenced certificate.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_InvalidateChildCertStatus(
  KeyM_CertificateIdType certId);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_TriggerState()
 *********************************************************************************************************************/
/*! \brief         Advance state machine depending on CSM result.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_TriggerState(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_HandleCsmResult()
 *********************************************************************************************************************/
/*! \brief         Handle result of CSM function call.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \param[in]     csmResult            Return code of CSM (synchronous call or asynchronous notification).
 *  \param[in]     prevState            State active before CSM call was issued.
 *  \return        E_OK                 The returned CSM result was handled successfully.
 *                 E_NOT_OK             Internal error, due to invalid CSM result.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_HandleCsmResult(
  KeyM_CertificateIdType certId,
  Std_ReturnType csmResult,
  tKeyMCertState prevState);

/**********************************************************************************************************************
 * KeyM_Cert_StateInit()
 *********************************************************************************************************************/
/*! \brief         Initialization of global RAM buffers for processing certificate.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateInit(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_Parse()
 *********************************************************************************************************************/
/*! \brief         Parsing certificate data.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \param[in]     cert                 Pointer to the certificate data
 *  \param[in]     certLength           Certificate data length
 *  \return        E_OK                 Certificate data was parsed successfully.
 *                 E_NOT_OK             Due to internal error, the certificate data could not be parsed.
 *  \pre           certId must be valid certificate ID.
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE, but not for the same certificate
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();                                              \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_Parse(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) cert,
  uint32 certLength);

/**********************************************************************************************************************
 * KeyM_Cert_SearchElementByStructureType()
 *********************************************************************************************************************/
/*! \brief         Search certificate element by structure type and return element index by reference.
 *  \details       -
 *  \param[in]     certIdx               Holds the identifier of the certificate.
 *  \param[in]     elementStructureType  Holds the structure type of the certificate element.
 *  \param[in,out] elementIdxPtr         Referenced element index.
 *  \return        TRUE                  Element is available in configuration.
 *                 FALSE                 Element is not available in configuration.
 *  \pre           certIdx must be a valid certificate ID.
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_SearchElementByStructureType(
  KeyM_CertificateIdType certIdx,
  KeyM_OfStructureOfCertificateElementType elementStructureType,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdxPtr);

#if ((KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_CRE_APPL */
/**********************************************************************************************************************
 * KeyM_Cert_IsCertElementFound()
 *********************************************************************************************************************/
/*! \brief         Search certificate element by structure type and object identifier and return element index
 *                 by reference.
 *  \details       -
 *  \param[in]     certIdx               Holds the identifier of the certificate.
 *  \param[in]     elementStructureType  Holds the structure type of the certificate element.
 *  \param[in]     oidData               Holds a pointer to the object identifier data.
 *  \param[in]     oidDataLength         Holds the length of the object identifier data.
 *  \param[out]    elementIdxPtr         Returned element index.
 *  \return        TRUE                  Element is available in configuration.
 *                 FALSE                 Element is not available in configuration.
 *  \pre           certIdx must be a valid certificate ID.
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertElementFound(
  KeyM_CertificateIdType certIdx,
  KeyM_OfStructureOfCertificateElementType elementStructureType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) oidData,
  uint32 oidDataLength,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdxPtr);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_GetSignatureElement_X509_ECDSA()
 *********************************************************************************************************************/
/*! \brief         Return signature element by reference.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \param[in]     elementIdx            Holds the certificate element index.
 *  \param[out]    dataPtr               Pointer to output buffer.
 *  \param[in,out] dataLengthPtr         In:  Maximum length of output buffer
 *                                       Out: Number of bytes written to output buffer
 *  \return        E_OK                  The signature element was retrieved successfully.
 *                 E_NOT_OK              Due to internal error, the signature element could not be retrieved.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetSignatureElement_X509_ECDSA(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) dataPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) dataLengthPtr);

/**********************************************************************************************************************
 * KeyM_Cert_FormatECDSASignature()
 *********************************************************************************************************************/
/*! \brief         Formats ECDSA signature elements for crypto driver.
 *  \details       Brings the ECDSA coordinates into a format where both coordinates have the same length.
 *                 This function prefixes coordinates with leading zeroes as needed.
 *  \param[in]     r                     Pointer to a buffer containing the R coordinate of the ECDSA signature.
 *  \param[in]     rLength               Number of bytes in r.
 *  \param[in]     s                     Pointer to a buffer containing the S coordinate of the ECDSA signature.
 *  \param[in]     sLength               Number of bytes in s.
 *  \param[out]    outputBuffer          Buffer into which the formated and concatenated signature coordinates shall
 *                                       be written.
 *  \param[in,out] outputBufferLen       In:  Maximum size of outputBuffer
 *                                       Out: Number of bytes written to outputBuffer
 *  \return        E_OK                           ECDSA signature was successfully written to outputBuffer.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH  outputBuffer is too small to contain ECDSA signature.
 *  \pre           outputBuffer must be a valid pointer to a buffer with at least size *outputBufferLen
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_FormatECDSASignature(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) r,
  uint32 rLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) s,
  uint32 sLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) outputBuffer,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) outputBufferLen);

/**********************************************************************************************************************
 * KeyM_Cert_GetElementByStructureType()
 *********************************************************************************************************************/
/*! \brief         Return certificate element by reference of structure type.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \param[in]     elementStructureType  Holds the structure type of the certificate element.
 *  \param[out]    dataPtr               Pointer to output buffer.
 *  \param[in,out] dataLengthPtr         In:  Maximum length of output buffer
 *                                       Out: Number of bytes written to output buffer
 *  \return        E_OK                  The certificate element was retrieved successfully.
 *                 E_NOT_OK              Due to internal error, the certificate element could not be retrieved.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires dataPtr != NULL_PTR;
 *                 requires $lengthOf(dataPtr) >= *dataLengthPtr;                                              \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetElementByStructureType(
  KeyM_CertificateIdType certId,
  KeyM_OfStructureOfCertificateElementType elementStructureType,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) dataPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) dataLengthPtr);

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_GetElementByStructureTypeAndOid()
 *********************************************************************************************************************/
/*! \brief         Return certificate element by reference of structure type and object identifier.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \param[in]     elementStructureType  Holds the structure type of the certificate element.
 *  \param[in]     oidData               Pointer to object identifier data
 *  \param[in]     oidDataLength         Holds the length of the object identifier data.
 *  \param[out]    dataPtr               Pointer to output buffer.
 *  \param[out]    dataLengthPtr         Length of output buffer.
 *  \return        E_OK                  The certificate element was retrieved successfully.
 *                 E_NOT_OK              Due to internal error, the certificate element could not be retrieved.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetElementByStructureTypeAndOid(
  KeyM_CertificateIdType certId,
  KeyM_OfStructureOfCertificateElementType elementStructureType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) oidData,
  uint32 oidDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) dataPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) dataLengthPtr);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_StateParseCert()
 *********************************************************************************************************************/
/*! \brief         Parsing state.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \return        E_OK                  Certificate data was parsed successfully.
 *                 E_NOT_OK              Due to internal error, the certificate data could not be parsed.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateParseCert(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_StateVerifyCertElements()
 *********************************************************************************************************************/
/*! \brief         Verify parsed certificate elements.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \return        E_OK                  The parsed certificate elements are verified successfully.
 *                 E_NOT_OK              Invalid certificate elements.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateVerifyCertElements(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_StateCheckSubject()
 *********************************************************************************************************************/
/*! \brief         Compare issuer with subject of certificate in upper hierarchy.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \return        E_OK                  Chain reference was checked successfully.
 *                 E_NOT_OK              Internal error, due to invalid chain reference.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateCheckSubject(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_ParseUTCGeneralizedTime()
 *********************************************************************************************************************/
/*! \brief         Parse UTC or Generalized Time element for period validity.
 *  \details       -
 *  \param[in]     timeElementPtr                   Pointer to time element.
 *  \param[in]     timeElementDataLength            Data length of time element.
 *  \param[out]    parsedTimePtr                    Pointer to output buffer for parsed time
 *  \return        E_OK                             Period validity was parsed successfully.
 *                 E_NOT_OK                         Due to internal error, the period validity could not be parsed.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseUTCGeneralizedTime(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) timeElementPtr,
  uint16 timeElementDataLength,
  P2VAR(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) parsedTimePtr);

/**********************************************************************************************************************
 * KeyM_Cert_ParseTime()
 *********************************************************************************************************************/
/*! \brief         Parse certificate element for period validity.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \param[in]     elementIdx            Holds the certificate element index.
 *  \param[out]    parsedTimePtr         Pointer to output buffer for parsed time
 *  \return        E_OK                  Period validity was parsed successfully.
 *                 E_NOT_OK              Due to internal error, the period validity could not be parsed.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseTime(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) parsedTimePtr);

/**********************************************************************************************************************
 * KeyM_Cert_ConvertDateToUnixTime()
 *********************************************************************************************************************/
/*! \brief         Convert parsed time to Unix format.
 *  \details       -
 *  \param[in]     date                  Pointer to parsed time.
 *  \param[in,out] unixTime              Pointer to converted unix time.
 *  \return        E_OK                  Parsed time was converted successfully to unix format.
 *                 E_NOT_OK              Due to internal error, the parsed time could not be converted.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ConvertDateToUnixTime(
  P2CONST(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) date,
  P2VAR(uint64, AUTOMATIC, AUTOMATIC) unixTime);

/**********************************************************************************************************************
 * KeyM_Cert_StateCheckTimeStamp()
 *********************************************************************************************************************/
/*! \brief         Check certificate validation period.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \return        E_OK                  Validity period was validated successfully.
 *                 E_NOT_OK              Invalid validity period.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateCheckTimeStamp(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_GetPubKeyElements()
 *********************************************************************************************************************/
/*! \brief         Retrieve public key elements for signature verification operation.
 *  \details       -
 *  \param[in]     certId                          Holds the identifier of the certificate.
 *  \param[in]     elementIdx                      Holds the certificate element index.
 *  \param[out]    pubKey                          Pointer to the offset and length for the public key sub-elements.
 *  \return        E_OK                            The public key elements were retrieved successfully.
 *                 E_NOT_OK                        Due to internal error, the public key elements could not be retrieved.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetPubKeyElements(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(KeyM_CertPubKeyType, AUTOMATIC, AUTOMATIC) pubKey);

/**********************************************************************************************************************
 * KeyM_Cert_BigToLittleEndian()
 *********************************************************************************************************************/
/*! \brief         Convert data from big to little endian.
 *  \details       -
 *  \param[out]    dstPtr      Pointer to destination data buffer.
 *  \param[in]     srcPtr      Pointer to source data buffer.
 *  \param[in]     length      Data length.
 *  \pre           All provided pointers must be valid.
 *                 The buffers referenced by dstPtr and srcPtr must provide at least length many bytes.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_BigToLittleEndian(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) dstPtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) srcPtr,
  uint16 length);

/**********************************************************************************************************************
 * KeyM_Cert_ConvertPublicPoint_ECDSA()
 *********************************************************************************************************************/
/*! \brief         Convert parsed public point into the right format for ECDSA.
 *  \details       -
 *  \param[in]     coordinateDataPtr               Pointer to input data buffer for the coordinates.
 *  \param[in]     coordinateDataLength            Input data length for single coordinate.
 *  \return        E_OK                            The parsed public point was converted successfully.
 *                 E_NOT_OK                        Due to invalid data lengths, the public point could not be converted.
 *  \pre           All provided pointers must be valid.
 *  \note          For detailed information on conversion refer to RFC 5480
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ConvertPublicPoint_ECDSA(
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) coordinateDataPtr,
  uint16 coordinateDataLength);

/**********************************************************************************************************************
 * KeyM_Cert_ConvertPublicPoint_EdDSA()
 *********************************************************************************************************************/
/*! \brief         Convert parsed public point into the right format for EdDSA.
 *  \details       -
 *  \param[in]     xCoordinateDataPtr              Pointer to input data buffer for x-coordinate.
 *  \param[in]     yCoordinateDataPtr              Pointer to input data buffer for y-coordinate.
 *  \param[in]     coordinateDataLength            Input data length for single coordinate.
 *  \return        E_OK                            The parsed public point was converted successfully.
 *                 E_NOT_OK                        Due to invalid data lengths, the public point could not be converted.
 *  \pre           All provided pointers must be valid.
 *  \note          For detailed information on conversion refer to RFC 8032
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ConvertPublicPoint_EdDSA(
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) xCoordinateDataPtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) yCoordinateDataPtr,
  uint16 coordinateDataLength);

/**********************************************************************************************************************
 * KeyM_Cert_StateSetKey()
 *********************************************************************************************************************/
/*! \brief         Set public key in associated CSM key element.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \return        E_OK                  The public key was set successfully.
 *                 E_NOT_OK              Due to internal error, the public key could not be set.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateSetKey(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_GetCrlCertId()
 *********************************************************************************************************************/
/*! \brief         Get certificate identifier of CRL.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the referenced certificate.
 *  \param[out]    crlCertId             Holds the identifier of the CRL certificate.
 *  \return        E_OK                  Operation successful.
 *                 E_NOT_OK              Operation failed.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCrlCertId(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) crlCertId);

/**********************************************************************************************************************
 * KeyM_Cert_IsCertRevoked()
 *********************************************************************************************************************/
/*! \brief         Check revocation list for referenced certificate.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the referenced certificate.
 *  \param[in]     crlCertId             Holds the identifier of the CRL certificate.
 *  \return        TRUE                  Referenced certificate is revoked.
 *                 FALSE                 Referenced certificate is not revoked.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 crlCertId must be a valid certificate ID, i.e., crlCertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertRevoked(
  KeyM_CertificateIdType certId,
  KeyM_CertificateIdType crlCertId);

/**********************************************************************************************************************
 * KeyM_Cert_CheckRevocation()
 *********************************************************************************************************************/
/*! \brief         Checks revocation status for referenced certificate.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the referenced certificate.
 *  \param[out]    revocationStatus      Returned revocation status.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *                 revocationStatus needs to be FALSE before this function is called.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_CheckRevocation(
  KeyM_CertificateIdType certId,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) revocationStatus);

/**********************************************************************************************************************
 * KeyM_Cert_CheckRevocationByCRL()
 *********************************************************************************************************************/
/*! \brief         Validates certificate revocation list and initiates revocation check.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the referenced certificate.
 *  \param[out]    revocationStatus      Holds the revocation status of the referenced certificate.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *                 revocationStatus needs to be FALSE before this function is called.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_CheckRevocationByCRL(
  KeyM_CertificateIdType certId,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) revocationStatus);

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_CheckRevocationByCRE()
 *********************************************************************************************************************/
/*! \brief         Checks revocation status according to certificate revocation entries.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the referenced certificate.
 *  \param[out]    revocationStatus      Holds the revocation status of the referenced certificate.
 *  \pre           revocationStatus needs to be FALSE before this function is called.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_CheckRevocationByCRE(
  KeyM_CertificateIdType certId,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) revocationStatus);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_StateSignatureVerify()
 *********************************************************************************************************************/
/*! \brief         Perform signature verification operation.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \return        E_OK                  The signature was verified successfully.
 *                 E_NOT_OK              The signature is invalid or certificate is revoked.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateSignatureVerify(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_StateStore()
 *********************************************************************************************************************/
/*! \brief         Store certificate data after successful verification.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \return        E_OK                  The certificate data was stored successfully.
 *                 E_NOT_OK              Due to internal error, the certificate data could not be stored.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateStore(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_IsCertSlotEmpty()
 *********************************************************************************************************************/
/*! \brief         Check if certificate slot is empty.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \return        TRUE                  Certificate is already set.
 *  \return        FALSE                 Certificate is not set yet.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();                                              \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertSlotEmpty(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyCertificatesTriggerState()
 *********************************************************************************************************************/
/*! \brief         Advances state machine and copies necessary global data.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate that shall be verified.
 *  \param[out]    state                                The state which the verification process will continue with.
 *  \return        E_OK                                 Certificate verification request accepted.
 *                 E_NOT_OK                             Internal error occurred.
 *  \pre           state must be a valid pointer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyCertificatesTriggerState(
  KeyM_CertificateIdType CertId,
  P2VAR(tKeyMCertState, AUTOMATIC, KEYM_APPL_VAR) state);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyCertificatesProcess()
 *********************************************************************************************************************/
/*! \brief         Verifies two certificates against each other.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate that shall be verified.
 *  \param[in]     CertUpperId                          Holds the identifier of the certificate that shall verify the
 *                                                      certificate referenced by CertId.
 *  \param[in,out] state                                The state which the verification process will continue with.
 *  \return        E_OK                                 Certificate verification request accepted. Operation will be
 *                                                      performed in the background and response is given through a
 *                                                      callback.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_BUSY                          Validation cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_EMPTY                One of the certificate slots are empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   An upper certificate is not valid.
 *  \pre           state must be a valid pointer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyCertificatesProcess(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateIdType CertUpperId,
  P2VAR(tKeyMCertState, AUTOMATIC, KEYM_APPL_VAR) state);

#if ((KEYM_CERTIFICATEINITVALUE == STD_ON) || (KEYM_CERTIFICATEINITCALLOUT == STD_ON))
/**********************************************************************************************************************
 * KeyM_Cert_LoadCertificateInitValue()
 *********************************************************************************************************************/
/*! \brief         Loads a certificate's init value.
 *  \details       Loads a certificate's init value from the configuration of from a callback into the RAM buffer.
 *  \param[in]     certId                    Holds the identifier of the certificate.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 KeyM_IsCertificateInitValueInfoUsedOfCertificate(certId) must be TRUE
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires KeyM_IsCertificateInitValueInfoUsedOfCertificate(certId);                          \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_LoadCertificateInitValue(
  KeyM_CertificateIdType certId);
#endif

#if (KEYM_CSMKEYTARGETREFOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_LoadCertificateFromCsm()
 *********************************************************************************************************************/
/*! \brief         Copies certificate data from CSM key storage to global RAM buffer.
 *  \details       If CSM retrieval fails, certificate init value is restored if the certificate has init values.
 *  \param[in]     certId                    Holds the identifier of the certificate.
 *  \return        E_OK                      The certificate data was retrieved from CSM key storage or init value
 *                                           was restored successfully.
 *                 KEYM_E_KEY_CERT_READ_FAIL Certificate could not be provided due to a read or permission failure.
 *                 KEYM_E_KEY_CERT_EMPTY     The requested key or certificate is not available, slot is empty.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 KeyM_GetStorageOfCertificate(certId) must be KEYM_STORAGE_IN_CSM
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();                                              \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_LoadCertificateFromCsm(
  KeyM_CertificateIdType certId);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_LoadCertificateFromStorage()
 *********************************************************************************************************************/
/*! \brief         Copies certificate data from storage to global RAM buffer.
 *  \details       -
 *  \param[in]     certId                    Holds the identifier of the certificate.
 *  \return        E_OK                      The certificate data was retrieved storage and copied successfully.
 *                 E_NOT_OK                  Certificate does not have storage configured.
 *                 KEYM_E_KEY_CERT_READ_FAIL Certificate could not be provided due to a read or permission failure.
 *                 KEYM_E_KEY_CERT_EMPTY     The requested key or certificate is not available, slot is empty.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_LoadCertificateFromStorage(
  KeyM_CertificateIdType certId);

#if ((KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON) || (KEYM_RTECALLBACKNOTIFICATION == STD_ON))
/**********************************************************************************************************************
 * KeyM_Cert_GetServiceResult()
 *********************************************************************************************************************/
/*! \brief         Return service result according to final state of certificate.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \param[in,out] result                Holds the service result.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_GetServiceResult(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_ResultType, AUTOMATIC, KEYM_APPL_VAR) result);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_StateNotify()
 *********************************************************************************************************************/
/*! \brief         Notify application about end of service operation and verification result.
 *  \details       -
 *  \param[in]     certId                Holds the identifier of the certificate.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateNotify(
  KeyM_CertificateIdType certId);

#if ((KEYM_CERTIFICATE_NVMBLOCK == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_CRE_APPL */
/**********************************************************************************************************************
 * KeyM_NvBlock_Write_Req()
 *********************************************************************************************************************/
/*! \brief         Set write request.
 *  \details       Set request to write block.
 *  \param[in]     blockIdx             Holds the identifier of the nv block.
 *  \pre           blockIdx has to be a valid identifier.
 *  \context       TASK
 *  \reentrant     TRUE, for different blocks.
 *  \synchronous   TRUE
 *  \spec          requires blockIdx < KeyM_GetSizeOfNvmBlock();                                               \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_Write_Req(
  KeyM_SizeOfNvmBlockType blockIdx);

/**********************************************************************************************************************
 *  KeyM_NvBlock_State_Init()
 *********************************************************************************************************************/
/*! \brief         Init Nv State.
 *  \details       Init Nv state for the given block.
 *  \param[in]     blockIdx             Holds the identifier of the block.
 *  \pre           blockIdx needs to be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires blockIdx < KeyM_GetSizeOfNvmBlock();                                               \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_State_Init(
  KeyM_SizeOfNvmBlockType blockIdx);

  /**********************************************************************************************************************
 * KeyM_NvBlock_Trigger_Write_Req()
 *********************************************************************************************************************/
/*! \brief         Trigger write request.
 *  \details       Call NvM_SetRamBlockStatus and NvM_WriteBlock dependent on the block processing
 *  \param[in]     blockIdx             Holds the identifier of the nv block.
 *  \pre           blockIdx has to be a valid identifier.
 *  \context       TASK
 *  \reentrant     TRUE, for different blocks.
 *  \synchronous   TRUE
 *  \spec          requires blockIdx < KeyM_GetSizeOfNvmBlock();                                               \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Trigger_Write_Req(
  KeyM_SizeOfNvmBlockType blockIdx);

/**********************************************************************************************************************
 * KeyM_NvBlock_State_CallbackWrittenToBlock()
 *********************************************************************************************************************/
/*! \brief         Write Block request finished Block callback routine.
 *  \details       Block specific callback routine which is called by NvM in order to notify the KeyM that an
 *                 asynchronous single block request has been finished.
 *  \param[in]     blockIdx               Holds the identifier of the block.
 *  \pre           blockIdx has to be a valid identifier.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires blockIdx < KeyM_GetSizeOfNvmBlock();                                               \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_State_CallbackWrittenToBlock(
  KeyM_SizeOfNvmBlockType blockIdx);

/**********************************************************************************************************************
 * KeyM_NvBlock_State_WrittenToBlock()
 *********************************************************************************************************************/
/*! \brief         Update State for WrittenToBlock.
 *  \details       -
 *  \param[in]     blockIdx               Holds the identifier of the block.
 *  \pre           blockIdx has to be a valid identifier.
 *                 Must be called within exclusive area KEYM_EXCLUSIVE_AREA_1
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires blockIdx < KeyM_GetSizeOfNvmBlock();                                               \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_State_WrittenToBlock(
  KeyM_SizeOfNvmBlockType blockIdx);
#endif /* ((KEYM_CERTIFICATE_NVMBLOCK == STD_ON) || (KEYM_CRE_APPL == STD_ON)) */

#if(KEYM_CERTIFICATE_NVMBLOCK == STD_ON)
/**********************************************************************************************************************
 * KeyM_NvBlock_Persist()
 **********************************************************************************************************************/
/*! \brief         Persist NvM Data.
 *  \details       -
 *  \param[in]     certId             Holds the identifier of the certificate.
 *  \pre           certId needs to be valid.
 *                 NvM storage needs to be preconfigured for referenced certificate.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();                                              \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_Persist(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_NvBlock_WriteToBlock_Header()
 *********************************************************************************************************************/
/*! \brief         Copy Header.
 *  \details       -
 *  \param[in]     certDataLength       Length of the certificate which shall be written.
 *  \param[out]    NvMBufferPtr         RAM mirror where Ram block data shall be written to.
 *  \pre           The buffer referenced by NvMBufferPtr must be valid and
 *                 provide at least KEYM_CERT_SIZEOF_NVBLOCK_HEADER bytes.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires $lengthOf(NvMBufferPtr) >= KEYM_CERT_SIZEOF_NVBLOCK_HEADER;                        \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_WriteToBlock_Header(
  uint16 certDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) NvMBufferPtr);

/**********************************************************************************************************************
 * KeyM_NvBlock_ReadFromBlock_Header()
 *********************************************************************************************************************/
/*! \brief         Check Header.
 *  \details       -
 *  \param[in]     NvMBufferPtr         RAM mirror where Ram block data can be read from.
 *  \return        TRUE                 Header valid.
 *  \return        FALSE                Header not valid.
 *  \pre           NvMBufferPtr must be a valid pointer.
 *                 The buffer referenced by NvMBufferPtr must provide
 *                 at least KEYM_CERT_POS_NVBLOCK_VERSION many bytes.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_NvBlock_ReadFromBlock_Header(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) NvMBufferPtr);

/**********************************************************************************************************************
 * KeyM_NvBlock_WriteToBlock_Copy()
 *********************************************************************************************************************/
/*! \brief         Copy data to NvMBufferPtr
 *  \details       Copy header and data.
 *  \param[in]     certIdx         Holds the identifier of the certificate.
 *  \param[out]    NvMBufferPtr    RAM mirror where Ram block data shall be written to.
 *  \return        E_OK            Data was copied to buffer.
 *  \return        E_NOT_OK        No data was copied.
 *  \pre           certIdx must be a valid certificate ID.
 *                 NvMBufferPtr needs to be a valid pointer.
 *                 The buffer referenced by NvMBuffer must provide at least
 *                 KeyM_GetLengthOfNvmBlock(KeyM_GetNvmBlockIdxOfCertificate(certIdx)) byte.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires certIdx < KeyM_GetSizeOfCertificate();                                             \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteToBlock_Copy(
  KeyM_SizeOfCertificateType certIdx,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) NvMBufferPtr);

/**********************************************************************************************************************
 * KeyM_NvBlock_ReadFromBlock_Copy()
 *********************************************************************************************************************/
/*! \brief         Read from Block callback routine.
 *  \details       Block specific callback routine which is called by NvM in order to let the KeyM copy data from
 *                 NvM RAM mirror to RAM block.
 *  \param[in]     certIdx         Holds the identifier of the certificate.
 *  \param[in]     NvMBufferPtr    RAM mirror where Ram block data can be read from.
 *  \return        E_OK            Data was either copied from buffer or restored.
 *                 E_NOT_OK        Failure during parsing or verifying of elements.
 *  \pre           certIdx needs to be valid.
 *                 NvMBufferPtr needs to be a valid pointer.
 *                 The buffer referenced by NvMBufferPtr must provide
 *                 at least KEYM_CERT_POS_NVBLOCK_VERSION many bytes.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires certIdx < KeyM_GetSizeOfCertificate();                                             \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFromBlock_Copy(
  KeyM_SizeOfCertificateType certIdx,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) NvMBufferPtr);
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_NvBlock_Persist_CRE()
 **********************************************************************************************************************/
/*! \brief         Persist CRE to NvM.
 *  \details       -
 *  \pre           NvM storage needs to be preconfigured for referenced certificate
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_Persist_CRE(void);

/**********************************************************************************************************************
 * KeyM_NvBlock_WriteToBlock_Header_CRE()
 *********************************************************************************************************************/
/*! \brief         Copy Header.
 *  \details       -
 *  \param[out]    NvMBufferPtr        RAM mirror where Ram block data shall be written to.
 *  \pre           The buffer referenced by NvMBufferPtr must be valid and
 *                 provide at least KEYM_CERT_SIZEOF_NVBLOCK_CRE_HEADER bytes.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires $lengthOf(NvMBufferPtr) >= KEYM_CERT_SIZEOF_NVBLOCK_CRE_HEADER;                    \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_WriteToBlock_Header_CRE(
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) NvMBufferPtr);

/**********************************************************************************************************************
 * KeyM_NvBlock_ReadFromBlock_Header_CRE()
 *********************************************************************************************************************/
/*! \brief         Check Header.
 *  \details       -
 *  \param[in]     NvMBufferPtr         RAM mirror where Ram block data can be read from.
 *  \return        TRUE                 Header valid.
 *  \return        FALSE                Header not valid.
 *  \pre           NvMBufferPtr needs to be a valid pointer.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_NvBlock_ReadFromBlock_Header_CRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) NvMBufferPtr);

/**********************************************************************************************************************
 * KeyM_NvBlock_WriteToBlock_Copy_CRE()
 *********************************************************************************************************************/
/*! \brief         Copy data to NvMBufferPtr.
 *  \details       Copy header and data.
 *  \param[out]    NvMBufferPtr    RAM mirror where Ram block data shall be written to.
 *  \return        E_OK            Data was copied to buffer.
 *  \return        E_NOT_OK        No data was copied.
 *  \pre           NvMBufferPtr needs to be a valid pointer.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteToBlock_Copy_CRE(
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) NvMBufferPtr);

/**********************************************************************************************************************
 * KeyM_NvBlock_ReadFromBlock_Copy_CRE()
 *********************************************************************************************************************/
/*! \brief         Read from Block callback routine.
 *  \details       Block specific callback routine which is called by NvM in order to let the KeyM copy data from
 *                 NvM RAM mirror to RAM block.
 *  \param[in]     NvMBufferPtr    RAM mirror where Ram block data can be read from.
 *  \return        E_OK            Data was either copied from buffer or restored.
 *                 E_NOT_OK        Failure during parsing or verifying of elements.
 *  \pre           NvMBufferPtr needs to be a valid pointer.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFromBlock_Copy_CRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) NvMBufferPtr);
#endif
/**********************************************************************************************************************
 * KeyM_Cert_CopyLowestCertId()
 *********************************************************************************************************************/
/*! \brief         Copy certificate identifier of preinstalled certificates in the lowest chain hierarchy.
 *  \details       The certificate identifier in the lowest chain hierarchy is used to verify the whole chain.
 *  \param[in]     certId          Holds the identifier of the certificate.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_CopyLowestCertId(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_TriggerChainVerification()
 *********************************************************************************************************************/
/*! \brief         Trigger verification of analyzed certificate chains.
 *  \details       -
 *  \return        E_OK                  The chain verification was triggered successfully.
 *                 E_NOT_OK              Due to internal error, the chain verification could not be triggered.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_TriggerChainVerification(void);

/**********************************************************************************************************************
 * KeyM_Cert_ParseAvailableCertData()
 *********************************************************************************************************************/
/*!\brief         Parses available certificate data.
 * \details       Parses all available certificates that are in state KEYM_CERTIFICATE_NOT_PARSED.
 *                A certificate is considered as "available" if its entry in the certAvailable input parameter is TRUE
 *                or if it is a ROM certificate.
 * \param[in]     certAvailable          Contains the information whether RAM data is present for every certificate.
 * \pre           certAvailable must point to a boolean buffer of size >= KEYM_NUMBER_OF_CERTIFICATES.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_ParseAvailableCertData(
  P2CONST(boolean, AUTOMATIC, KEYM_APPL_DATA) certAvailable);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyCertificatesAtStartUp()
 *********************************************************************************************************************/
/*!\brief         Handle verification of permanently stored certificates at startup.
 * \details       -
 * \param[in,out] isStartUpTriggered     Flag for triggering verification
 * \return        E_OK                   The startup handling is processed successfully.
 *                E_NOT_OK               Internal error during startup handling.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyCertificatesAtStartUp(
  P2VAR(boolean, AUTOMATIC, KEYM_APPL_VAR) isStartUpTriggered);

#if (KEYM_CSM_ASYNC_SIGNATURE_VERIFY == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_HandleCsmCallback()
 *********************************************************************************************************************/
/*!\brief         Handle Callback Notification.
 *  \details      Notifies the KeyM that the job has finished. Update the state according to the callback result.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_HandleCsmCallback(void);
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_IsCertAvailable()
 *********************************************************************************************************************/
/*! \brief         Check if certificate data is available.
 *  \details       -
 *  \param[in]     certId          Holds the certificate identifier.
 *  \return        TRUE            Certificate data is available.
 *                 FALSE           Not available.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertAvailable(
  KeyM_CertificateIdType certId);
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_ResetUpperHierarchicalRefInfo()
 *********************************************************************************************************************/
/*! \brief         Resets upper hierarchical reference for dynamic issuer.
 *  \details       -
 *  \param[in]     certId          Holds the certificate identifier.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_ResetUpperHierarchicalRefInfo(
  KeyM_CertificateIdType certId);
#endif

#if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_IsCertIdSlotOwner()
 *********************************************************************************************************************/
/*! \brief         Checks if referenced certificate identifier matches the certificate slot owner.
 *  \details       -
 *  \param[in]     certId          Holds the certificate identifier.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \return        TRUE            Certificate identifier matches slot owner.
 *                 FALSE           Certificate identifier does not match the slot owner.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertIdSlotOwner(
  KeyM_CertificateIdType certId);
#endif

#if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_SetSlotOwner()
 *********************************************************************************************************************/
/*! \brief         Set certificate slot owner.
 *  \details       -
 *  \param[in]     certId          Holds the certificate identifier.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_SetSlotOwner(
  KeyM_CertificateIdType certId);
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_CheckDynamicIssuer()
 *********************************************************************************************************************/
/*! \brief         Checks validity of dynamic issuer.
 *  \details       -
 *  \param[in]     certId          Holds the certificate identifier.
 *  \return        E_OK            Dynamic issuer is valid
 *                 E_NOT_OK        Dynamic issuer is invalid or operation failed.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CheckDynamicIssuer(
  KeyM_CertificateIdType certId);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_IsReferenceElementFound()
 *********************************************************************************************************************/
/*! \brief         Retrieve reference element index.
 *  \details       -
 *  \param[in]     CertId                Holds the certificate identifier.
 *  \param[in]     CertStructure         Holds the certificate structure type of the reference element.
 *  \param[out]    ElementIdx            Returned element index.
 *  \return        TRUE                  Element is available in configuration.
 *                 FALSE                 Element is not available in configuration.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsReferenceElementFound(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, KEYM_APPL_VAR) ElementIdx);

/**********************************************************************************************************************
 * KeyM_Cert_CertStructureGetReference()
 *********************************************************************************************************************/
/*! \brief         Retrieve reference structure type.
 *  \details       "Reference Structure" refers to the structure type that comes before the structure identified by
 *                 the CertStructure parameter.
 *  \param[in]     CertId               Holds the certificate identifier.
 *  \param[in]     CertStructure        Holds the certificate structure type.
 *  \param[out]    CertStructureRef     Holds the reference certificate structure type.
 *  \return        E_OK                 The reference structure type was retrieved successfully.
 *                 E_NOT_OK             Certificate structure is not available within certificate data.
 *                 KEYM_E_PARAMETER_MISMATCH Invalid reference structure type.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertStructureGetReference(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(KeyM_CertificateStructureType, AUTOMATIC, KEYM_APPL_VAR) CertStructureRef);

#if (KEYM_CERTCSMHASHJOBREFOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_ComputeCertHash()
 *********************************************************************************************************************/
/*! \brief         Compute hash over certificate data.
 *  \details       -
 *  \param[in]     certId               Holds the certificate identifier.
 *  \return        E_OK                 The hash was computed successfully.
 *                 E_NOT_OK             Due to an internal error, the hash could not be computed.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires KeyM_IsCertHashStorageUsedOfCertificate(certId);                                   \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ComputeCertHash(
  KeyM_CertificateIdType certId);
#endif

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_CsrInfoGenerate()
 *********************************************************************************************************************/
/*! \brief         Generate CertificationRequestInfo ASN.1 data structure.
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[out]    csrInfo                          CertificationRequestInfo in ASN.1.
 *  \param[in,out] csrInfoLength                    In: Max number of bytes available in csrInfo.
 *                                                  Out: Actual number.
 *  \return        E_OK                             CertificationRequestInfo data structure was generated successfully.
 *                 E_NOT_OK                         Due to internal error, the CertificationRequestInfo data structure
 *                                                  could not be generated.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires csrInfo != NULL_PTR;
 *                 requires csrInfoLength != NULL_PTR;
 *                 requires $lengthOf(csrInfo) >= *csrInfoLength;                                              \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CsrInfoGenerate(
  KeyM_CertificateIdType certId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) csrInfo,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) csrInfoLength);
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_CertificateSubjectEquals()
 *********************************************************************************************************************/
/*! \brief         Checks certificate's subject for equality with a passed string.
 *  \details       Returns TRUE if the certificate's subject is equal to the passed string.
 *  \param[in]     certId                              Identifier of the certificate to check.
 *  \param[in]     subject                             String to check the certificate's subject against.
 *  \param[in]     subjectLength                       Length of subject.
 *  \return        TRUE                                Certificate's subject is equal to the passed string.
 *                 FALSE                               Certificate's subject is not equal to the passed string or
 *                                                     retrieving certificate's subject failed.
 *  \pre           certId must be < KEYM_NUMBER_OF_CERTIFICATES.
 *                 subject must point to an uint8 buffer with length subjectLength.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_CertificateSubjectEquals(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) subject,
  uint16 subjectLength);

/**********************************************************************************************************************
 * KeyM_Cert_FindGroupCertificateBySubject()
 *********************************************************************************************************************/
/*! \brief         Searches a certificate group for a certificate with the provided subject.
 *  \details       -
 *  \param[in]     groupId                    Identifier of the certificate group to search.
 *  \param[in]     subject                    Subject of the certificate that is sought-after.
 *  \param[in]     subjectLength              Length of subject.
 *  \param[out]    certId                     Identifier of the group certificate with the provided subject.
 *  \return        E_OK                       A certificate with the provided subject was found within the group.
 *                 E_NOT_OK                   The provided subject was not found in any certificate in the group.
 *  \pre           groupId must be a valid group ID, i.e., groupId < KeyM_GetSizeOfCertificateGroup()
 *                 subject must be a valid pointer and point to an uint8 buffer with length subjectLength.
 *                 certId must be a valid pointer to a KeyM_CertificateIdType.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_FindGroupCertificateBySubject(
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) subject,
  uint16 subjectLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certId);

/**********************************************************************************************************************
 * KeyM_Cert_GetDynamicIssuerCertId()
 *********************************************************************************************************************/
/*! \brief         Retrieves the identifier of the dynamic certificate's issuer.
 *  \details       Determines the group certificate's issuer at runtime and returns it.
 *  \param[in]     certId                    Identifier of the certificate for which the issuer shall be returned.
 *  \param[out]    issuerCertId              Identifier of the issuer of the certificate identified by certId.
 *  \return        E_OK                      Issuer was successfully determined.
 *                 E_NOT_OK                  Issuer could not be determined.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 issuerCertId must be a valid pointer to a KeyM_CertificateIdType.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();
 *                 requires issuerCertId != NULL_PTR;                                                          \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetDynamicIssuerCertId(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) issuerCertId);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_ParseAndVerifyElements()
 *********************************************************************************************************************/
/*! \brief         Parses a certificate and verifies its elements.
 *  \details       Calls KeyM_Cert_StateParseCert and KeyM_Cert_StateVerifyCertElements on the certificate.
 *  \param[in]     certId                    Identifier of the certificate that shall be parsed.
 *  \return        E_OK                      Certificate was successfully parsed an elements are valid.
 *                 E_NOT_OK                  Parsing error occurred or certificate has invalid elements.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseAndVerifyElements(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_TriggerStartUpHandling()
 *********************************************************************************************************************/
/*! \brief         Initiates startup handling if necessary.
 *  \details       On the first call to this function, this function initiates (i.e., prepares the certificate state
 *                 machine for) certificate startup handling. Subsequent calls to this functions do nothing.
 *  \return        TRUE                      Startup handling has been initiated.
 *                 FALSE                     Startup handling has already been initiated; function did nothing.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_TriggerStartUpHandling(void);

/**********************************************************************************************************************
 * KeyM_Cert_ProcessCertificateState()
 *********************************************************************************************************************/
/*! \brief         Runs the certificate state machine.
 *  \details       Advances the certificate state machine on the currently active certificate.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_ProcessCertificateState(void);

/**********************************************************************************************************************
 * KeyM_Cert_PushLeafCertToVerify()
 *********************************************************************************************************************/
/*! \brief         Places a new element on top of the LeafCertsToVerify stack.
 *  \details       -
 *  \return        TRUE                      Element has been pushed to the top of the LeafCertsToVerify stack.
 *                 FALSE                     Element has not been pushed on top of the LeafCertsToVerify stack.
 *                                           Reasons: Stack is full or element was already present in the stack.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();                                              \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_PushLeafCertToVerify(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_PopLeafCertToVerify()
 *********************************************************************************************************************/
/*! \brief         Removes the element on top of the LeafCertsToVerify stack and returns it.
 *  \details       If there are no elements in the LeafCertsToVerify stack, another valid certificate ID is returned.
 *                 Use KeyM_Cert_HasLeafCertsToVerify() beforehand to check whether there are elements in the stack.
 *  \return        The certificate ID that was previously on top of the LeafCertsToVerify stack.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_Cert_PopLeafCertToVerify(void);

/**********************************************************************************************************************
 * KeyM_Cert_HasLeafCertsToVerify()
 *********************************************************************************************************************/
/*! \brief         Checks whether there are elements in the LeafCertsToVerify stack.
 *  \details       -
 *  \return        TRUE                      There are elements in the LeafCertsToVerify stack.
 *                 FALSE                     There are no elements in the LeafCertsToVerify stack.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_HasLeafCertsToVerify(void);

/**********************************************************************************************************************
 * KeyM_Cert_ClearLeafCertsToVerify()
 *********************************************************************************************************************/
/*! \brief         Clears the LeafCertsToVerify buffer.
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_ClearLeafCertsToVerify(void);

/**********************************************************************************************************************
 * KeyM_Cert_PushVerifyChainLink()
 *********************************************************************************************************************/
/*! \brief         Places a new element on top of the VerifyChain stack.
 *  \details       -
 *  \return        TRUE                      Element has been pushed to the top of the VerifyChain stack.
 *                 FALSE                     Element has not been pushed on top of the VerifyChain stack.
 *                                           Reason: Stack is full.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();                                              \endspec
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_PushVerifyChainLink(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_PopVerifyChainLink()
 *********************************************************************************************************************/
/*! \brief         Removes the element on top of the VerifyChain stack and returns it.
 *  \details       If there are no elements in the VerifyChain stack, another valid certificate ID is returned.
 *                 Use KeyM_Cert_HasVerifyChainLinks() beforehand to check whether there are elements in the stack.
 *  \return        The certificate ID that was previously on top of the VerifyChain stack.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_Cert_PopVerifyChainLink(void);

/**********************************************************************************************************************
 * KeyM_Cert_HasVerifyChainLinks()
 *********************************************************************************************************************/
/*! \brief         Checks whether there are elements in the VerifyChain stack.
 *  \details       -
 *  \return        TRUE                      There are elements in the VerifyChain stack.
 *                 FALSE                     There are no elements in the VerifyChain stack.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_HasVerifyChainLinks(void);

/**********************************************************************************************************************
 * KeyM_Cert_ClearVerifyChain()
 *********************************************************************************************************************/
/*! \brief         Clears the VerifyChain buffer.
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_ClearVerifyChain(void);

/**********************************************************************************************************************
 * KeyM_Cert_InitCertificateReadBufferData()
 *********************************************************************************************************************/
/*! \brief         Initializes storage for read data buffers for all certificates.
 *  \details       To be called in init function
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_InitCertificateReadBufferData(void);

/**********************************************************************************************************************
 * KeyM_Cert_GetCertificateReadBufferData()
 *********************************************************************************************************************/
/*! \brief         Retrieves a pointer and length where a specified certificate's data can be read.
 *  \details       -
 *  \param[in]     certId                    Identifier of the certificate
 *  \return        Struct containing a const pointer to and the length of the certificate's data slot
 *  \pre           KeyM_Cert_InitCertificateReadBufferData() must have been called before (e.g., in init function)
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \note          The precondition of this function can currently not be implemented as a VCA spec.
 *                 This is a limitation of VCA. The function begins with a respective assertion.
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(KeyM_ConstCertDataType, KEYM_CODE) KeyM_Cert_GetCertificateReadBufferData(KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_GetCertificateWriteBufferData()
 *********************************************************************************************************************/
/*! \brief         Retrieves a pointer and length where a specified certificate's data can be written.
 *  \details       Returns length 0 for certificates that have no RAM buffer.
 *  \param[in]     certId                    Identifier of the certificate
 *  \return        Struct containing a var pointer to and the length of the certificate's data slot
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \note          The precondition of this function can currently not be implemented as a VCA spec.
 *                 This is a limitation of VCA. The function begins with a respective assertion.
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(KeyM_CertDataType, KEYM_CODE) KeyM_Cert_GetCertificateWriteBufferData(KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_IsCertRequestEqualTo()
 *********************************************************************************************************************/
/*! \brief         Checks whether the stored certificate request is equal to a specified value.
 *  \details       -
 *  \param[in]     requestType            Request type to check for
 *  \return        TRUE                   The stored certificate request type is equal to the passed value.
 *  \return        FALSE                  The stored certificate request type is not equal to the passed value or no
 *                                        valid certificate request ID is stored.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertRequestEqualTo(tKeyMCertRequestType requestType);

#if (KEYM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_InitChecks()
 *********************************************************************************************************************/
/*! \brief         Checks the constant tables in KeyM's configuration for consistency.
 *  \details       This function verifies some necessary preconditions for KeyM's generated KeyM_Cfg.c and KeyM_Cfg.h
 *                 that are necessary to guarantee freedom from interference with respect to memory.
 *  \return        E_OK                   The configuration passes the checks.
 *  \return        E_NOT_OK               The configuration is erroneous.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_InitChecks(void);
#endif

/**********************************************************************************************************************
 * KeyM_Cert_CertElementGetFirstStaticChecks()
 *********************************************************************************************************************/
/*! \brief         Performs static checks for service KeyM_CertElementGetFirst.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Holds the identifier of the iterable certificate element.
 *  \param[out]    elementIdx                           Holds the reference index of the iterable certificate element.
 *  \return        E_OK                                 Certificate iterator was initialized successfully.
 *                 E_NOT_OK                             Due to internal error, the certificate iterator could not be
 *                                                      initialized.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetFirstStaticChecks(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdx);

/**********************************************************************************************************************
 * KeyM_Cert_CertElementGetNextStaticChecks()
 *********************************************************************************************************************/
/*! \brief         Performs static checks for service KeyM_CertElementGetNext.
 *  \details       -
 *  \param[in]     CertElementIterator                Pointer to a structure that is allocated by the caller and
 *                                                    used by the function. It shall not be destroyed or altered
 *                                                    by the application until all elements have been read from the
 *                                                    list.
 *  \return        E_OK                               Certificate iterator was updated successfully.
 *                 E_NOT_OK                           Due to internal error, the certificate iterator could not be
 *                                                    updated.
 *                 KEYM_E_KEY_CERT_EMPTY              No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID            Certificate is not valid or not verified successfully
 *                 KEYM_E_PARAMETER_MISMATCH          Element ID is invalid
 *  \pre           The iterator passed to this function must be one that was previously retrieved via
 *                 KeyM_Cert_CertElementGetFirstInitializeIterator().
 *                 CertElementIterator must be a valid pointer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetNextStaticChecks(
  P2CONST(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator);

/**********************************************************************************************************************
 * KeyM_Cert_CertStructureGetInternal()
 *********************************************************************************************************************/
/*! \brief         Parse and retrieve certificate structure.
 *  \details       -
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in]     CertStructure                    Holds the certificate structure type.
 *  \param[out]    CertStructureData                Cerificate structure data returned by the function.
 *  \param[in,out] CertStructureDataLength          In: Max number of bytes available in CertStructureData.
 *                                                  Out: Actual number.
 *  \return        E_OK                             Certificate structure was retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate structure could not be
 *                                                  retrieved.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertStructureGetInternal(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertStructureData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertStructureDataLength);


/**********************************************************************************************************************
 *  KeyM_Cert_CertificateElementGetCountStaticChecks()
 *********************************************************************************************************************/
/*! \brief         Performs static checks for service KeyM_CertificateElementGetCount.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Holds the identifier of the certificate element.
 *  \param[out]    elementIdx                           Holds the reference index of the iterable certificate element.
 *  \return        E_OK                                 Element found and number of element items provided.
 *                 E_NOT_OK                             Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID or certificate element ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertificateElementGetCountStaticChecks(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdx);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetTL()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetTL(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Call KeyM_Asn1_GetTL and convert return code */
  retVal = KeyM_Asn1_GetTL(paramDataPtr);

  /* # Map return value */
  if(retVal == KEYM_ASN1_RC_OK)
  {
    retVal = E_OK;
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetCertificateWrittenLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(uint16, KEYM_CODE) KeyM_Cert_GetCertificateWrittenLength(
  KeyM_CertificateIdType CertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Read certificate written length in temporary storage buffer */
  if (KeyM_GetCertStorageWrittenLengthLengthOfCertificate((KeyM_CertificateIterType)CertId) >= 2u)
  {
    KeyM_SizeOfCertStorageType storageWrittenLengthStartIdx = KeyM_GetCertStorageWrittenLengthStartIdxOfCertificate((KeyM_CertificateIterType)CertId);
    /*@ assert storageWrittenLengthStartIdx <= (KeyM_GetSizeOfCertStorage() - 2u); */ /* VCA_KEYM_CERT_STORAGEWRITTENLENGTHSTARTIDX */

    retVal =  KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(KeyM_GetAddrCertStorage(storageWrittenLengthStartIdx));

    /* establish that the certificate identified by CertId has a RAM buffer and the retrieved length is a valid length for its RAM buffer */
    /*@ assert KeyM_IsCertStorageUsedOfCertificate(CertId); */ /* VCA_KEYM_CERT_INITCHECK03_CERTSTORAGE */
    /*@ assert retVal <= $lengthOf(KeyM_GetAddrCertStorage(KeyM_GetCertStorageStartIdxOfCertificate(CertId))); */ /* VCA_KEYM_CERT_GETWRITTENLENGTH */
  }
  else
  {
    retVal = 0u;
  }

  /*@ assert retVal <= $lengthOf(KeyM_GetAddrCertStorage(KeyM_GetCertStorageStartIdxOfCertificate(CertId))); */ /* VCA_KEYM_CERT_GETWRITTENLENGTH2 */
  return retVal;
} /* KeyM_Cert_GetCertificateWrittenLength() */
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_SetCertificateWrittenLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_SetCertificateWrittenLength(
  KeyM_CertificateIdType CertId,
  uint16 writtenLength)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Set certificate written length in temporary storage buffer */
  if (KeyM_GetCertStorageWrittenLengthLengthOfCertificate((KeyM_CertificateIterType)CertId) >= 2u)
  {
    uint16 lengthToWrite;
    KeyM_SizeOfCertStorageType storageWrittenLengthStartIdx = KeyM_GetCertStorageWrittenLengthStartIdxOfCertificate((KeyM_CertificateIterType)CertId);
    /*@ assert storageWrittenLengthStartIdx <= (KeyM_GetSizeOfCertStorage() - 2u); */ /* VCA_KEYM_CERT_STORAGEWRITTENLENGTHSTARTIDX */

    if (writtenLength > KeyM_GetCertStorageLengthOfCertificate((KeyM_CertificateIterType)CertId))
    {
      lengthToWrite = 0u;
    }
    else
    {
      lengthToWrite = writtenLength;
    }
    /*@ assert lengthToWrite <= $lengthOf(KeyM_GetAddrCertStorage(KeyM_GetCertStorageStartIdxOfCertificate(CertId))); */ /* VCA_KEYM_CERT_SETWRITTENLENGTH */ /* ensure that writtenLength is a valid length for the buffer */

    KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(lengthToWrite, KeyM_GetAddrCertStorage(storageWrittenLengthStartIdx));
  }

} /* KeyM_Cert_SetCertificateWrittenLength() */
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetStatusInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(KeyM_CertificateStatusType, KEYM_CODE) KeyM_Cert_GetStatusInfo(
  KeyM_CertificateIdType CertId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Read certificate status in temporary storage buffer */
  /*@ assert KeyM_GetCertStorageStatusLengthOfCertificate(CertId) >= 2u; */ /* check that CSL buffer has room reserved for the uint16 */
  return (KeyM_CertificateStatusType)KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(KeyM_GetAddrCertStorage(KeyM_GetCertStorageStatusStartIdxOfCertificate((KeyM_CertificateIterType)(CertId))));
} /* KeyM_Cert_GetStatusInfo() */
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_CREHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetCREIssuerNameWrittenLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(uint16, KEYM_CODE) KeyM_Cert_GetCREIssuerNameWrittenLength(
  KeyM_SizeOfCREInfoType creId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Read issuer name written length from temporary storage buffer */
  /*@ assert KeyM_GetCREStorageIssuerWrittenLengthLengthOfCREInfo(creId) >= 2u; */ /* check that CSL buffer has room reserved for the uint16 */
  return KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(KeyM_GetAddrCREStorage(KeyM_GetCREStorageIssuerWrittenLengthStartIdxOfCREInfo(creId)));
} /* KeyM_Cert_GetCREIssuerNameWrittenLength() */
# endif /* ifndef KEYM_NOUNIT_CREHANDLING */
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_CREHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_SetCREIssuerNameWrittenLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_SetCREIssuerNameWrittenLength(
  KeyM_SizeOfCREInfoType creId,
  uint16 writtenLength)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Set CRE issuer name written length in temporary storage buffer */
  /*@ assert KeyM_GetCREStorageIssuerWrittenLengthLengthOfCREInfo(creId) >= 2u; */ /* check that CSL buffer has room reserved for the uint16 */
  KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(writtenLength, KeyM_GetAddrCREStorage(KeyM_GetCREStorageIssuerWrittenLengthStartIdxOfCREInfo(creId)));
} /* KeyM_Cert_SetCREIssuerNameWrittenLength() */
# endif /* ifndef KEYM_NOUNIT_CREHANDLING */
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_CREHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetCRESerialNumberWrittenLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(uint16, KEYM_CODE) KeyM_Cert_GetCRESerialNumberWrittenLength(
  KeyM_SizeOfCREInfoType creId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Read serial number written length from temporary storage buffer */
  /*@ assert KeyM_GetCREStorageSerialNumberWrittenLengthLengthOfCREInfo(creId) >= 2u; */ /* check that CSL buffer has room reserved for the uint16 */
  return KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(KeyM_GetAddrCREStorage(KeyM_GetCREStorageSerialNumberWrittenLengthStartIdxOfCREInfo(creId)));
}
# endif /* ifndef KEYM_NOUNIT_CREHANDLING */
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_CREHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_SetCRESerialNumberWrittenLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_SetCRESerialNumberWrittenLength(
  KeyM_SizeOfCREInfoType creId,
  uint16 writtenLength)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Set CRE serial number written length in temporary storage buffer */
  /*@ assert KeyM_GetCREStorageSerialNumberWrittenLengthLengthOfCREInfo(creId) >= 2u; */ /* check that CSL buffer has room reserved for the uint16 */
  KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(writtenLength, KeyM_GetAddrCREStorage(KeyM_GetCREStorageSerialNumberWrittenLengthStartIdxOfCREInfo(creId)));
}
# endif /* ifndef KEYM_NOUNIT_CREHANDLING */
#endif

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetCertElementDataPointer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(KeyM_ConstCertDataPointerType, KEYM_CODE) KeyM_Cert_GetCertElementDataPointer(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_ConstCertDataType certData;

  /* ----- Implementation ----------------------------------------------- */
  certData = KeyM_Cert_GetCertificateReadBufferData(certId);

  return &certData.certData[KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)elementIdx).offset];
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_SetStatusInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_SetStatusInfo(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStatusType status)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Set certificate status in temporary storage buffer */
  /*@ assert KeyM_GetCertStorageStatusLengthOfCertificate(CertId) >= 2u; */ /* check that CSL buffer has room reserved for the uint16 */
  KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(status, KeyM_GetAddrCertStorage(KeyM_GetCertStorageStatusStartIdxOfCertificate((KeyM_CertificateIterType)(CertId))));
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_CERTIFICATESIGNINGREQUEST /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCsrElementSet()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCsrElementSet(
  KeyM_CertificateIdType certId,
  KeyM_CertElementIdType certElementId,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) csrElementOffset,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) csrElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;
  uint16 offset;
  KeyM_CertElementIdType currentCsrElementId;
  uint16 currentCsrElementDataLength;
  KeyM_ConstCertDataType certData;
  certData = KeyM_Cert_GetCertificateReadBufferData(certId);

  /* ----- Implementation ----------------------------------------------- */
  if (certData.certDataLength > 0u)
  {
    /* Iterate through set CSR elements in certificate slot */
    for (offset = 0u;
         ((uint32)offset + KEYM_CERT_CSR_POS_ELEMENTDATA) < certData.certDataLength;
         offset = offset + KEYM_CERT_CSR_POS_ELEMENTDATA + currentCsrElementDataLength)
    {
      /* Retrieve CSR element identifier */
      currentCsrElementId = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(&certData.certData[offset]); /* VCA_KEYM_CERT_ISCSRELEMENTSET_CONVERTUINT16 */

      /* Retrieve CSR element data length */
      currentCsrElementDataLength = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(&certData.certData[offset + KEYM_CERT_CSR_POS_ELEMENTLENGTH]); /* VCA_KEYM_CERT_ISCSRELEMENTSET_CONVERTUINT16 */

      /* Check whether CSR element is set by comparing element identifier */
      if(certElementId == currentCsrElementId)
      {
        retVal = TRUE;
        *csrElementOffset = offset;
        *csrElementDataLength = currentCsrElementDataLength;
        break;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESIGNINGREQUEST */
#endif

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_CERTIFICATESIGNINGREQUEST /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_UpdateCsrElement()
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
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_UpdateCsrElement(
  KeyM_CertificateIdType certId,
  uint16 csrElementOffset,
  uint16 oldCsrElementDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) newCsrElementData,
  uint16 newCsrElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
  uint8 remainderCsrData[KEYM_ASN1_MAX_CSR_SIZE];
  uint32 certificateSlotLength;
  uint32 remainderCsrDataOffset;
  uint16 remainderCsrDataLength;
  uint16 oldCsrLength;
  uint32 newCsrLength;
  KeyM_CertDataType ramBuffer;
  KeyM_CertDataPointerType csrDataPtr;

  /* ----- Implementation ----------------------------------------------- */
  ramBuffer = KeyM_Cert_GetCertificateWriteBufferData(certId);
  csrDataPtr = ramBuffer.certData;
  certificateSlotLength = ramBuffer.certDataLength;
  oldCsrLength = KeyM_Cert_GetCertificateWrittenLength(certId);
  remainderCsrDataOffset = (uint32)csrElementOffset + oldCsrElementDataLength;
  remainderCsrDataLength = (uint16)((uint32)oldCsrLength - remainderCsrDataOffset);
  newCsrLength = (uint32)csrElementOffset + newCsrElementDataLength + remainderCsrDataLength;

  /* # Perform length check */
  if((oldCsrLength > remainderCsrDataOffset)
   && (remainderCsrDataLength <= KEYM_ASN1_MAX_CSR_SIZE)
   && (newCsrLength <= certificateSlotLength))
  {
    /* # Copy the data after the to be updated element as remainder to a buffer */
    VStdLib_MemCpyLarge(remainderCsrData, &csrDataPtr[remainderCsrDataOffset], remainderCsrDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_UPDATECSRELEMENT_REMAINDERBACKUP */

    /* # Copy the new CSR element data at the offset of the old CSR element */
    VStdLib_MemCpyLarge(&csrDataPtr[csrElementOffset], newCsrElementData, newCsrElementDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_UPDATECSRELEMENT_NEWELEMENTCOPY */

    /* # Append the shifted remainder CSR data to the new CSR element */
    VStdLib_MemCpyLarge(&csrDataPtr[csrElementOffset + newCsrElementDataLength], remainderCsrData, remainderCsrDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_UPDATECSRELEMENT_REMAINDERRESTORE */
    KeyM_Cert_SetCertificateWrittenLength(certId, (uint16)newCsrLength);
    retVal = E_OK;
  }

  return retVal;
} /* KeyM_Cert_UpdateCsrElement() */
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESIGNINGREQUEST */
#endif

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_CERTIFICATESIGNINGREQUEST /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ServiceRequestCSR()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceRequestCSR(
  KeyM_CertificateIdType CertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertDataType ramBuffer;
  ramBuffer = KeyM_Cert_GetCertificateWriteBufferData(CertId);

  /* ----- Implementation ----------------------------------------------- */
  /* # Get CertificationRequestInfo */
  if (RequestDataLength == 0u)
  {
    /* Generate CertificationRequestInfo */
    retVal = KeyM_Cert_CsrInfoGenerate(CertId, ramBuffer.certData, &ramBuffer.certDataLength); /* VCA_KEYM_CERT_SERVICEREQUESTCSR_CSRINFOGENERATE */

    if (retVal == E_OK)
    {
      retVal = KeyM_Asn1_BuildCSR(CertId, ramBuffer.certData, (uint16)ramBuffer.certDataLength, ResponseData, ResponseDataLength);

      /* Reset written length for subsequent requests */
      KeyM_Cert_SetCertificateWrittenLength(CertId, 0u);
    }
  }
  else
  {
    /* Use pregenerated CertificationRequestInfo */
    /* # Build ASN.1 CSR structure */
    retVal = KeyM_Asn1_BuildCSR(CertId, RequestData, (uint16)RequestDataLength, ResponseData, ResponseDataLength);
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESIGNINGREQUEST */
#endif

#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ParseOCSPResponseConstructed()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseOCSPResponseConstructed(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_ParamType asn1Param;
  KeyM_Asn1_ParseType asn1Parse;
  KeyM_Asn1_ParamType asn1ParamDerived[KEYM_ASN1_PARSE_MAX_NESTING_LEVEL];

  /* ----- Implementation ----------------------------------------------- */
  /* # Setup ASN reader */
  KeyM_Asn1_Init(&asn1Param, requestData, (uint16)requestDataLength);

  /* # Init the parser */
  KeyM_Asn1_ParseInit(&asn1Parse, asn1ParamDerived, KEYM_ASN1_PARSE_MAX_NESTING_LEVEL);

  /* # Parse OCSP response */
  retVal = KeyM_Asn1_ParseOCSPResponse(&asn1Parse, &asn1Param, ocspResp);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ParseOCSPResponseResponderId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseOCSPResponseResponderId(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_ParamType asn1Param;
  KeyM_Asn1_ParseType asn1Parse;
  KeyM_Asn1_ParamType asn1ParamDerived[KEYM_ASN1_PARSE_MAX_NESTING_LEVEL];

  /* ----- Implementation ----------------------------------------------- */
  /* # Setup ASN reader */
  KeyM_Asn1_Init(&asn1Param, &requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID].elementLength);

  /* # Init the parser */
  KeyM_Asn1_ParseInit(&asn1Parse, asn1ParamDerived, KEYM_ASN1_PARSE_MAX_NESTING_LEVEL);

  /* # Parse ResponderId */
  retVal = KeyM_Asn1_ParseOCSPResponseResponderId(&asn1Parse, &asn1Param, ocspResp);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ParseOCSPResponse()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseOCSPResponse(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Parse constructed OCSPResponse structure */
  retVal = KeyM_Cert_ParseOCSPResponseConstructed(requestData, requestDataLength, ocspResp);

  if (retVal == E_OK)
  {
    /* # Parse constructed ResponderId structure */
    retVal = KeyM_Cert_ParseOCSPResponseResponderId(requestData, ocspResp);
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseStatus(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  uint32 responseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  uint8 responseStatus = requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSESTATUS].elementOffset];

  /* # Check Validity of ResponseStatus */
  if ((((responseStatus == KEYM_ASN1_OCSP_RESPONSE_STATUS_SUCCESSFUL)
      || (responseStatus == KEYM_ASN1_OCSP_RESPONSE_STATUS_MALFORMEDREQUEST)
      || (responseStatus == KEYM_ASN1_OCSP_RESPONSE_STATUS_INTERNALERROR)
      || (responseStatus == KEYM_ASN1_OCSP_RESPONSE_STATUS_TRYLATER)
      || (responseStatus == KEYM_ASN1_OCSP_RESPONSE_STATUS_SIGREQUIRED)
      || (responseStatus == KEYM_ASN1_OCSP_RESPONSE_STATUS_UNAUTHORIZED))
    && (ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSESTATUS].elementLength == 1u))
    && (responseDataLength > 0u))
  {
    /* # Return ResponseStatus byte */
    *responseData = responseStatus;

    if ((responseStatus == KEYM_ASN1_OCSP_RESPONSE_STATUS_SUCCESSFUL))
    {
      retVal = E_OK;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseType()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseType(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check Validity of ResponseType */
  if (KeyM_Utils_BufferCmp(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSETYPE].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSETYPE].elementLength, KEYM_CERT_OCSP_BASIC_RESPONSE_OIDDATA, KEYM_CERT_OCSP_BASIC_RESPONSE_OIDDATALENGTH))
  {
    retVal = E_OK;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseCertIdSerialNumber()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseCertIdSerialNumber(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 serialNumber[KEYM_CERT_X509_MAX_SERIAL_NUMBER_DATALENGTH];
  uint32 serialNumberDataLength = KEYM_CERT_X509_MAX_SERIAL_NUMBER_DATALENGTH;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve parsed serial number of certificate which is checked for revocation */
  retVal = KeyM_Cert_GetElementByStructureType(certId, KEYM_CERTIFICATE_SERIAL_NUMBER, serialNumber, &serialNumberDataLength);

  if (retVal == E_OK)
  {
    retVal = E_NOT_OK;

    /* # Compare serial number of certificate with serial number in CertId structure of OCSP response */
    if (KeyM_Utils_BufferCmp(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_SERIALNUMBER].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_SERIALNUMBER].elementLength, serialNumber, serialNumberDataLength))
    {
      retVal = E_OK;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseCertIdIssuerNameHash()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseCertIdIssuerNameHash(
  KeyM_CertificateIdType issuerCertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  uint8 issuerName[KEYM_CERT_X509_MAX_ISSUER_DN_DATALENGTH];
  uint32 issuerNameDataLength = KEYM_CERT_X509_MAX_ISSUER_DN_DATALENGTH;
  uint8 issuerNameHash[KEYM_CERT_X509_MAX_HASH_DATALENGTH];
  uint32 issuerNameHashDataLength = KEYM_CERT_X509_MAX_HASH_DATALENGTH;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve issuer's distinguished name of certificate which is checked for revocation */
  retVal = KeyM_Cert_CertStructureGet(issuerCertId, KEYM_CERTIFICATE_SUBJECT_NAME, issuerName, &issuerNameDataLength);

  if (retVal == E_OK)
  {
    retVal = E_NOT_OK;

    /* # Compute hash over issuer's distinguished name */
    csmResult = Csm_Hash(KeyM_GetResponseCertIdHashCsmJobRefOfOCSP(ocspId), CRYPTO_OPERATIONMODE_SINGLECALL, issuerName, issuerNameDataLength, issuerNameHash, &issuerNameHashDataLength);

    if (csmResult == E_OK)
    {
      /* # Compare computed hash of issuer's distinguished name with hash in CertId structure of OCSP response */
      if (KeyM_Utils_BufferCmp(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_ISSUERNAMEHASH].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_ISSUERNAMEHASH].elementLength, issuerNameHash, issuerNameHashDataLength))
      {
        retVal = E_OK;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetRSAPublicKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetRSAPublicKey(
  KeyM_CertificateIdType certId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) responseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_ParamType asn1Param;
  uint16 offset;

  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) responseDataConst = responseData;

  /* ----- Implementation ----------------------------------------------- */
  retVal = KeyM_Cert_CertStructureGet(certId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO, responseData, responseDataLength);

  if (retVal == E_OK)
  {
    /* # Initialize basic structure */
    KeyM_Asn1_Init(&asn1Param, responseDataConst, (uint16)*responseDataLength);

    retVal = KeyM_Cert_GetTL(&asn1Param);

    if (retVal == E_OK)
    {
      offset = asn1Param.current_pos;

      /* # Update ASN reader with parsed offset of sequence element */
      KeyM_Asn1_Init(&asn1Param, &responseDataConst[offset], ((uint16)*responseDataLength - offset));
      KeyM_Asn1_NextTag(&asn1Param);

      retVal = KeyM_Cert_GetTL(&asn1Param);

      if (retVal == E_OK)
      {
        KeyM_Asn1_NextTag(&asn1Param);
        retVal = KeyM_Cert_GetTL(&asn1Param);

        if ((retVal == E_OK) && (asn1Param.last_tag == KEYM_ASN1_TYPE_BIT_STRING))
        {
          VStdLib_MemCpyLarge(responseData, &responseData[asn1Param.current_pos + (asn1Param.last_tag_data_pos - asn1Param.last_tag_base_pos)], (*responseDataLength - (uint32)asn1Param.current_pos - ((uint32)asn1Param.last_tag_data_pos - (uint32)asn1Param.last_tag_base_pos))); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
          *responseDataLength -= (uint32)asn1Param.current_pos + ((uint32)asn1Param.last_tag_data_pos - (uint32)asn1Param.last_tag_base_pos);
        }
        else
        {
          retVal = E_NOT_OK;
        }
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseCertIdIssuerKeyHash()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseCertIdIssuerKeyHash(
  KeyM_CertificateIdType issuerCertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  uint8 issuerPubKey[KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH];
  uint32 issuerPubKeyDataLength = KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH;
  uint8 issuerPubKeyHash[KEYM_CERT_X509_MAX_HASH_DATALENGTH];
  uint32 issuerPubKeyHashDataLength = KEYM_CERT_X509_MAX_HASH_DATALENGTH;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve issuer's public key of certificate which is checked for revocation */
  if (KeyM_Asn1_GetAlgoType(issuerCertId) == KEYM_ASN1_ALGO_X509_RSA)
  {
    retVal = KeyM_Cert_GetRSAPublicKey(issuerCertId, issuerPubKey, &issuerPubKeyDataLength);
  }
  else
  {
    retVal = KeyM_Cert_GetElementByStructureType(issuerCertId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY, issuerPubKey, &issuerPubKeyDataLength);
  }

  if (retVal == E_OK)
  {
    retVal = E_NOT_OK;

    /* # Compute hash over issuer's public key */
    csmResult = Csm_Hash(KeyM_GetResponseCertIdHashCsmJobRefOfOCSP(ocspId), CRYPTO_OPERATIONMODE_SINGLECALL, &issuerPubKey[1u], issuerPubKeyDataLength - 1u, issuerPubKeyHash, &issuerPubKeyHashDataLength);

    if (csmResult == E_OK)
    {
      /* # Compare computed hash of issuer's public key with hash in CertId structure of OCSP response */
      if (KeyM_Utils_BufferCmp(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_ISSUERKEYHASH].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTID_ISSUERKEYHASH].elementLength, issuerPubKeyHash, issuerPubKeyHashDataLength))
      {
        retVal = E_OK;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseCertIdAttributes()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseCertIdAttributes(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType issuerCertId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Verify serial number */
  retVal = KeyM_Cert_VerifyOCSPResponseCertIdSerialNumber(certId, requestData, ocspResp);

  if (retVal == E_OK)
  {
    /* # Get issuer's certificate identifier */
    retVal = KeyM_Cert_GetIssuerCertId(certId, &issuerCertId);

    if (retVal == E_OK)
    {
      /* # Verify issuer's distinguished name hash */
      retVal = KeyM_Cert_VerifyOCSPResponseCertIdIssuerNameHash(issuerCertId, requestData, ocspResp, ocspId);

      if (retVal == E_OK)
      {
        /* # Verify issuer's public key hash */
        retVal = KeyM_Cert_VerifyOCSPResponseCertIdIssuerKeyHash(issuerCertId, requestData, ocspResp, ocspId);
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseCertId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseCertId(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) certId,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) ocspId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIdType localCertId;
  KeyM_CertificateStatusType certStatus;
  uint8_least ocspIdx;
  boolean isParsed;

  /* ----- Implementation ----------------------------------------------- */
  for (ocspIdx = 0u; ocspIdx < KeyM_GetSizeOfOCSP(); ocspIdx++)
  {
    isParsed = TRUE;

    /* # Retrieve referenced certificate identifier of OCSP Response configuration */
    localCertId = (KeyM_CertificateIdType)KeyM_GetCertificateIdxOfOCSP(ocspIdx);

    /* # Retrieve certificate status */
    certStatus = KeyM_Cert_GetStatusInfo(localCertId);

    if ((certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE) || (certStatus == KEYM_CERTIFICATE_INVALID))
    {
      continue;
    }
    else
    {
      if (certStatus == KEYM_CERTIFICATE_NOT_PARSED)
      {
        isParsed = FALSE;

        /* # Parse certificate */
        /* # Verify certificate elements */
        retVal = KeyM_Cert_ParseAndVerifyElements(localCertId);
      }

      if (((!isParsed) && (retVal == E_OK)) || (isParsed))
      {
        /* # Verify attributes of CertId element in OCSP response */
        retVal = KeyM_Cert_VerifyOCSPResponseCertIdAttributes(localCertId, requestData, ocspResp, (uint16)ocspIdx);

        if (retVal == E_OK)
        {
          *certId = localCertId;
          *ocspId = (uint16)ocspIdx;
          break;
        }
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# if ((KEYM_DELEGATEDRESPONDERREFIDXOFOCSP == STD_ON) && (KEYM_RESPONDERPUBKEYHASHCSMJOBREFOFOCSP == STD_ON))
#  ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetOCSPResponderCertIdOfCertDataByKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6060 7 */ /* MD_KEYM_6060_LOCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertIdOfCertDataByKey(
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) isResponderCertIdFound)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  uint8 responderPubKey[KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH];
  uint32 responderPubKeyDataLength = KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH;
  uint8 responderPubKeyHash[KEYM_CERT_X509_MAX_HASH_DATALENGTH];
  uint32 responderPubKeyHashDataLength = KEYM_CERT_X509_MAX_HASH_DATALENGTH;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve responder's public key */
  if (KeyM_Asn1_GetAlgoType(certId) == KEYM_ASN1_ALGO_X509_RSA)
  {
    retVal = KeyM_Cert_GetRSAPublicKey(certId, responderPubKey, &responderPubKeyDataLength);
  }
  else
  {
    retVal = KeyM_Cert_GetElementByStructureType(certId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY, responderPubKey, &responderPubKeyDataLength);
  }

  if (retVal == E_OK)
  {
    retVal = E_NOT_OK;

    /* # Compute hash over responder's public key */
    csmResult = Csm_Hash(KeyM_GetResponderPubKeyHashCsmJobRefOfOCSP(ocspId), CRYPTO_OPERATIONMODE_SINGLECALL, &responderPubKey[1], responderPubKeyDataLength - 1u, responderPubKeyHash, &responderPubKeyHashDataLength);

    if (csmResult == E_OK)
    {
      retVal = E_OK;

      /* # Compare computed responder's public key hash with public key hash in OCSP response */
      if (KeyM_Utils_BufferCmp(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYKEY].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYKEY].elementLength, responderPubKeyHash, responderPubKeyHashDataLength))
      {
        *responderCertId = certId;
        *isResponderCertIdFound = TRUE;
      }
    }
  }

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */
# endif

# if (KEYM_DELEGATEDRESPONDERREFIDXOFOCSP == STD_ON)
#  ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetOCSPResponderCertIdOfCertDataByName()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertIdOfCertDataByName(
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) isResponderCertIdFound)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 responderCommonName[KEYM_CERTIFICATEISSUERNAME_MAX_LENGTH];
  uint32 responderCommonNameDataLength = KEYM_CERTIFICATEISSUERNAME_MAX_LENGTH;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve responder's common name from certificate data */
  retVal = KeyM_Cert_GetElementByStructureTypeAndOid(certId, KEYM_CERTIFICATE_SUBJECT_NAME, KEYM_CERT_X509_COMMONNAMEOIDDATA, KEYM_CERT_X509_COMMONNAMEOIDDATALENGTH, responderCommonName, &responderCommonNameDataLength);

  if (retVal == E_OK)
  {
    /* # Compare retrieved common name with common name in OCSP response */
    if (KeyM_Utils_BufferCmp(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_COMMONNAME].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_COMMONNAME].elementLength, responderCommonName, responderCommonNameDataLength))
    {
      *responderCertId = certId;
      *isResponderCertIdFound = TRUE;
    }
  }

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */
# endif

# if (KEYM_DELEGATEDRESPONDERREFIDXOFOCSP == STD_ON)
#  ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_SetOCSPCertificateInGroup()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050, 6080 5 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_SetOCSPCertificateInGroup(
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType localCertId = 0u;
  KeyM_CertificateIdType refCertId = 0u;
  uint8 subjectCommonName[KEYM_CERTIFICATESUBJECTNAME_MAX_LENGTH] = { 0u };
  uint32 subjectCommonNameDataLength = KEYM_CERTIFICATESUBJECTNAME_MAX_LENGTH;
  KeyM_ConstCertDataType certificateData;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if groupId is invalid */
  if (groupId >= KeyM_GetSizeOfCertificateGroup())
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  /* # Check if certificate data length is invalid */
  else if (KeyM_Cert_IsCertDataLengthOfGroupInvalid(groupId, requestDataLength))
  {
    retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
  }
  else
  {
    /* # Extract subject common name from RequestData */
    retVal = KeyM_Cert_GetSubjectCommonName(requestData, requestDataLength, subjectCommonName, &subjectCommonNameDataLength);

    if (retVal == E_OK)
    {
      /* # Search subject common name in group */
      if (KeyM_Cert_SearchSubjectCommonNameDataInGroup(groupId, subjectCommonName, subjectCommonNameDataLength, &refCertId))
      {
        /* # Responder certificate already set */
        *certId = refCertId;
        retVal = E_OK;
      }
      else
      {
        /* # Determine empty dynamic group slot */
        retVal = KeyM_Cert_GetEmptyGroupCertId(groupId, &localCertId);

        if (retVal == E_OK)
        {
          /*# Copy certificate identifier */
          *certId = localCertId;

          /* # Set certificate data */
          certificateData.certData = requestData;
          certificateData.certDataLength = requestDataLength;

          retVal = KeyM_Cert_SetCertificate(localCertId, &certificateData);
        }
      }
    }
  }

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */
# endif

# if (KEYM_DELEGATEDRESPONDERREFIDXOFOCSP == STD_ON)
#  ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetOCSPResponderCertIdOfCertData()
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
 */
/* PRQA S 6060, 6080 8 */ /* MD_KEYM_6060_LOCAL, MD_MSR_STMIF */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertIdOfCertData(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId,
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) certData,
  uint32 certDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_ParamType asn1Param;
  uint8_least i;
  uint16 offset;
  KeyM_CertificateIdType certId;
  boolean isResponderCertIdFound = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* # Setup ASN reader */
  KeyM_Asn1_Init(&asn1Param, certData, (uint16)certDataLength);

  /* # Skip constructed sequence element */
  retVal = KeyM_Cert_GetTL(&asn1Param);

  if (retVal == E_OK)
  {
    offset = asn1Param.current_pos;

    /* # Update ASN reader with parsed offset of sequence element */
    KeyM_Asn1_Init(&asn1Param, &certData[offset], (uint16)certDataLength - offset);

    /* Iterate through included certs */
    for (i = 0u; i < KeyM_GetSizeOfOCSP(); i++)
    {
      /* # Get TL information from the current tag */
      retVal = KeyM_Cert_GetTL(&asn1Param);

      if (retVal == E_OK)
      {
        /* # Set certificate data in reference certificate group */
        retVal = KeyM_Cert_SetOCSPCertificateInGroup(groupId, &certData[asn1Param.last_tag_base_pos + offset], (uint32)asn1Param.current_pos + (uint32)asn1Param.last_tag_len - (uint32)asn1Param.last_tag_base_pos, &certId);

        if ((retVal == E_OK) && (!isResponderCertIdFound))
        {
#   if (KEYM_RESPONDERPUBKEYHASHCSMJOBREFOFOCSP == STD_ON)
          /* # Retrieve certificate identifier of OCSP repsonder */
          if (ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYKEY].isPresent)
          {
            retVal = KeyM_Cert_GetOCSPResponderCertIdOfCertDataByKey(ocspResp, ocspId, requestData, certId, responderCertId, &isResponderCertIdFound);
          }
          else
#   endif
          {
            retVal = KeyM_Cert_GetOCSPResponderCertIdOfCertDataByName(ocspResp, requestData, certId, responderCertId, &isResponderCertIdFound);
          }
        }

        if (retVal == E_OK)
        {
          /* # Update remaining length and current position */
          KeyM_Asn1_NextTag(&asn1Param);
        }
      }

      if ((retVal != E_OK) || (asn1Param.remaining_len == 0u))
      {
        break;
      }
    }
  }

  if (!isResponderCertIdFound)
  {
    retVal = E_NOT_OK;
  }

#   if (KEYM_RESPONDERPUBKEYHASHCSMJOBREFOFOCSP == STD_OFF)
  KEYM_DUMMY_STATEMENT(ocspId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */
# endif

# if (KEYM_RESPONDERPUBKEYHASHCSMJOBREFOFOCSP == STD_ON)
#  ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetOCSPResponderCertIdOfIssuerByKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertIdOfIssuerByKey(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId,
  KeyM_CertificateIdType issuerCertId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  uint8 responderPubKey[KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH];
  uint32 responderPubKeyDataLength = KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH;
  uint8 responderPubKeyHash[KEYM_CERT_X509_MAX_HASH_DATALENGTH];
  uint32 responderPubKeyHashDataLength = KEYM_CERT_X509_MAX_HASH_DATALENGTH;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve OCSP responder's public key */
  if (KeyM_Asn1_GetAlgoType(issuerCertId) == KEYM_ASN1_ALGO_X509_RSA)
  {
    retVal = KeyM_Cert_GetRSAPublicKey(issuerCertId, responderPubKey, &responderPubKeyDataLength);
  }
  else
  {
    retVal = KeyM_Cert_GetElementByStructureType(issuerCertId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY, responderPubKey, &responderPubKeyDataLength);
  }

  if (retVal == E_OK)
  {
    retVal = E_NOT_OK;

    /* # Compute hash over OCSP responder's public key */
    csmResult = Csm_Hash(KeyM_GetResponderPubKeyHashCsmJobRefOfOCSP(ocspId), CRYPTO_OPERATIONMODE_SINGLECALL, &responderPubKey[1], responderPubKeyDataLength - 1u, responderPubKeyHash, &responderPubKeyHashDataLength);

    if (csmResult == E_OK)
    {
      /* # Compare computed hash of OCSP responder's public key with hash in ResponderId element of OCSP Response */
      if (KeyM_Utils_BufferCmp(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYKEY].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYKEY].elementLength, responderPubKeyHash, responderPubKeyHashDataLength))
      {
        *responderCertId = issuerCertId;
        retVal = E_OK;
      }
    }
  }

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */
# endif

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetOCSPResponderCertIdOfIssuerByName()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertIdOfIssuerByName(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  KeyM_CertificateIdType issuerCertId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 responderCommonName[KEYM_CERTIFICATEISSUERNAME_MAX_LENGTH];
  uint32 responderCommonNameDataLength = KEYM_CERTIFICATEISSUERNAME_MAX_LENGTH;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve OCSP responder's common name */
  retVal = KeyM_Cert_GetElementByStructureTypeAndOid(issuerCertId, KEYM_CERTIFICATE_SUBJECT_NAME, KEYM_CERT_X509_COMMONNAMEOIDDATA, KEYM_CERT_X509_COMMONNAMEOIDDATALENGTH, responderCommonName, &responderCommonNameDataLength);

  if (retVal == E_OK)
  {
    retVal = E_NOT_OK;

    /* # Compare retrieved common name with common name attribute in ResponderId element of OCSP Response */
    if (KeyM_Utils_BufferCmp(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_COMMONNAME].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYNAME_COMMONNAME].elementLength, responderCommonName, responderCommonNameDataLength))
    {
      *responderCertId = issuerCertId;
      retVal = E_OK;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetOCSPResponderCertIdOfIssuer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertIdOfIssuer(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId,
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType issuerCertId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve certificate's issuer */
  retVal = KeyM_Cert_GetIssuerCertId(certId, &issuerCertId);

  if (retVal == E_OK)
  {
#  if (KEYM_RESPONDERPUBKEYHASHCSMJOBREFOFOCSP == STD_ON)
    /* # Check retrieved issuer with ResponderId element in OCSP Response */
    if (ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONDERID_BYKEY].isPresent)
    {
      retVal = KeyM_Cert_GetOCSPResponderCertIdOfIssuerByKey(requestData, ocspResp, ocspId, issuerCertId, responderCertId);
    }
    else
#  endif
    {
      retVal = KeyM_Cert_GetOCSPResponderCertIdOfIssuerByName(requestData, ocspResp, issuerCertId, responderCertId);
    }
  }

#  if (KEYM_RESPONDERPUBKEYHASHCSMJOBREFOFOCSP == STD_OFF)
  KEYM_DUMMY_STATEMENT(ocspId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetOCSPResponderCertId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponderCertId(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId,
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
#  if (KEYM_DELEGATEDRESPONDERREFIDXOFOCSP == STD_ON)
  if (ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTS].isPresent)
  {
    /* # Retrieve responder's certificate identifier of included certificate data */
    retVal = KeyM_Cert_GetOCSPResponderCertIdOfCertData(requestData, ocspResp, ocspId, KeyM_GetDelegatedResponderRefIdxOfOCSP(ocspId), &requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTS].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTS].elementLength, responderCertId);
  }
  else
#  endif
  {
    /* # Retrieve responder's certificate identifier of certificate's issuer */
    retVal = KeyM_Cert_GetOCSPResponderCertIdOfIssuer(requestData, ocspResp, ocspId, certId, responderCertId);
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetOCSPResponseSignatureElement_X509_ECDSA()
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
/* PRQA S 6010, 6030 5 */ /* MD_MSR_STPTH, MD_MSR_STCYC */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetOCSPResponseSignatureElement_X509_ECDSA(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) responseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) signaturePtr;
  Std_ReturnType retVal;
  KeyM_Asn1_ParamType asn1Param;
  uint16 firstElementOffset = 0u;
  uint16 firstElementLength = 0u;
  uint16 secondElementOffset = 0u;
  uint16 secondElementLength = 0u;
  uint16 offset = 1u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Setup ASN reader */
  KeyM_Asn1_Init(&asn1Param, &requestData[offset], (uint16)requestDataLength - offset);

  /* # Parse first element */
  retVal = KeyM_Cert_GetTL(&asn1Param);
  offset += asn1Param.current_pos;
  signaturePtr = &requestData[offset];

  /* # Update ASN reader with parsed offset of sequence element */
  KeyM_Asn1_Init(&asn1Param, signaturePtr, ((uint16)requestDataLength - offset));
  KeyM_Asn1_NextTag(&asn1Param);

  if (retVal == E_OK)
  {
    retVal = KeyM_Cert_GetTL(&asn1Param);

    if (retVal == E_OK)
    {
      if (signaturePtr[(uint16)asn1Param.current_pos] == 0x00u)
      {
        firstElementOffset = (uint16)asn1Param.current_pos + 1u;
        firstElementLength = (uint16)asn1Param.last_tag_len - 1u;
      }
      else
      {
        firstElementOffset = (uint16)asn1Param.current_pos;
        firstElementLength = (uint16)asn1Param.last_tag_len;
      }
    }

    /* # Iterate to next tag */
    KeyM_Asn1_NextTag(&asn1Param);

    /* # Parse second element */
    if (retVal == E_OK)
    {
      retVal = KeyM_Cert_GetTL(&asn1Param);

      if (retVal == E_OK)
      {
        if (signaturePtr[(uint16)asn1Param.current_pos] == 0x00u)
        {
          secondElementOffset = firstElementOffset + firstElementLength + (uint16)(asn1Param.last_tag_data_pos - asn1Param.last_tag_base_pos) + 1u;
          secondElementLength = (uint16)asn1Param.last_tag_len - 1u;
        }
        else
        {
          secondElementOffset = firstElementOffset + firstElementLength + (uint16)(asn1Param.last_tag_data_pos - asn1Param.last_tag_base_pos);
          secondElementLength = (uint16)asn1Param.last_tag_len;
        }
      }
    }

    /* # Copy both elements to associated signature buffer */
    if (*responseDataLength >= ((uint32)firstElementLength + (uint32)secondElementLength))
    {
      VStdLib_MemCpyLarge(responseData, &signaturePtr[firstElementOffset], firstElementLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      VStdLib_MemCpyLarge(&responseData[firstElementLength], &signaturePtr[secondElementOffset], secondElementLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

      *responseDataLength = (uint32)firstElementLength + (uint32)secondElementLength;
      retVal = E_OK;
    }
    else
    {
      retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseSignature()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseSignature(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint16 ocspId,
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  Crypto_VerifyResultType verifyRes;
  uint8 ocspSignature[KEYM_CERTIFICATESIGNATURE_MAX_LENGTH];
  uint32 ocspSignatureDataLength = KEYM_CERTIFICATESIGNATURE_MAX_LENGTH;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve OCSP responder's certificate identifier */
  retVal = KeyM_Cert_GetOCSPResponderCertId(requestData, ocspResp, ocspId, certId, responderCertId);

  if (retVal == E_OK)
  {
    if (KeyM_Asn1_GetAlgoType(certId) == KEYM_ASN1_ALGO_X509_RSA)
    {
      VStdLib_MemCpyLarge(ocspSignature, &(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_SIGNATURE].elementOffset])[1u], ((uint32)ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_SIGNATURE].elementLength - 1u)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      ocspSignatureDataLength = (uint32)ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_SIGNATURE].elementLength - 1u;
    }
    else
    {
      retVal = KeyM_Cert_GetOCSPResponseSignatureElement_X509_ECDSA(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_SIGNATURE].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_SIGNATURE].elementLength, ocspSignature, &ocspSignatureDataLength);
    }

    if (retVal == E_OK)
    {
      retVal = E_NOT_OK;

      if (!KeyM_IsKeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate(*responderCertId))
      {
        /* # Verify signature */
        csmResult = Csm_SignatureVerify(KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate(*responderCertId), CRYPTO_OPERATIONMODE_SINGLECALL, &requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSEDATA].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_RESPONSEDATA].elementLength, ocspSignature, ocspSignatureDataLength, &verifyRes);

        if ((csmResult == E_OK) && (verifyRes == CSM_E_VER_OK))
        {
          retVal = E_OK;
        }
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponderSignature()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponderSignature(
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) localCertId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) issuerCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Std_ReturnType csmResult;
  Crypto_VerifyResultType verifyRes;
  boolean certRevoked = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* # Allow only synchronous CSM jobs */
  if (!KeyM_IsKeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate(*localCertId))
  {
    /* # Check revocation */
    KeyM_Cert_CheckRevocation(*localCertId, &certRevoked);

    if (!certRevoked)
    {
      /* # Verify signature */
      csmResult = Csm_SignatureVerify(
        KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate(*issuerCertId),
        CRYPTO_OPERATIONMODE_SINGLECALL,
        KeyM_GetCert_CertInfo((KeyM_Cert_CertInfoIterType)*localCertId).sigProcessDataPtr,
        KeyM_GetCert_CertInfo((KeyM_Cert_CertInfoIterType)*localCertId).sigProcessDataLength,
        KeyM_Cert_SigBuffer, KeyM_Cert_SigLength, &verifyRes);

      if ((csmResult == E_OK) && (verifyRes == CSM_E_VER_OK))
      {
        retVal = E_OK;

        if (KeyM_Cert_HasVerifyChainLinks())
        {
          *localCertId = KeyM_Cert_PopVerifyChainLink();
          retVal = KeyM_Cert_GetIssuerCertId(*localCertId, issuerCertId);
        }
      }
    }
  }

  if (*localCertId == *issuerCertId)
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponder()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 2 */ /* MD_MSR_STMIF */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponder(
  KeyM_CertificateIdType responderCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateStatusType certStatus;
  KeyM_CertificateIdType localCertId;
  KeyM_CertificateIdType issuerCertId = 0u;
  uint8_least i;

  /* ----- Implementation ----------------------------------------------- */
  retVal = KeyM_Cert_CertGetStatus(responderCertId, &certStatus);

  if ((retVal == E_OK) && (certStatus != KEYM_CERTIFICATE_VALID))
  {
    retVal = KeyM_Cert_GetIssuerCertId(responderCertId, &issuerCertId);

    if (retVal == E_OK)
    {
      localCertId = responderCertId;

      retVal = KeyM_Cert_IdentifyInvalidChain(&localCertId, &issuerCertId);

      /* Delegated certificate needs to be issued by the CA, therefore a self-signed certificate is not allowed */
      if ((retVal == E_OK) && (localCertId != issuerCertId))
      {
        /* # Iterate through chain */
        for (i = 0u; i < KEYM_CERTIFICATE_CHAIN_MAX_DEPTH; i++)
        {
          /* # Parse certificate */
          retVal = KeyM_Cert_StateParseCert(localCertId);

          if (retVal == E_OK)
          {
            /* # Set public key */
            retVal = KeyM_Cert_StateSetKey(localCertId);

            if (retVal == E_OK)
            {
              /* # Verify signature */
              retVal = KeyM_Cert_VerifyOCSPResponderSignature(&localCertId, &issuerCertId);
            }
          }

          if ((!KeyM_Cert_HasVerifyChainLinks()) || (retVal != E_OK))
          {
            break;
          }
        }
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseNextUpdateTime()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseNextUpdateTime(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint64 certTime)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  tKeyMCertDateTimeType nextUpdateTime = { 0u };
  uint64 nextUpdateUnixTime = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Parse nextUpdate time */
  retVal = KeyM_Cert_ParseUTCGeneralizedTime(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_NEXTUPDATE].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_NEXTUPDATE].elementLength, &nextUpdateTime);

  if (retVal == E_OK)
  {
    /* # Convert nextUpdateTime standard time to unix time */
    retVal = KeyM_Cert_ConvertDateToUnixTime(&nextUpdateTime, &nextUpdateUnixTime);

    if (retVal == E_OK)
    {
      retVal = E_NOT_OK;

      /* # Check validity */
      if (certTime <= nextUpdateUnixTime)
      {
        retVal = E_OK;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseThisUpdateTime()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseThisUpdateTime(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  uint64 certTime)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  tKeyMCertDateTimeType thisUpdateTime = { 0u };
  uint64 thisUpdateUnixTime = 0u;

  /* ----- Implementation ----------------------------------------------- */
  if (ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_THISUPDATE].isPresent)
  {
    /* # Parse thisUpdate time */
    retVal = KeyM_Cert_ParseUTCGeneralizedTime(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_THISUPDATE].elementOffset], ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_THISUPDATE].elementLength, &thisUpdateTime);

    if (retVal == E_OK)
    {
      /* # Convert thisUpdateTime standard time to unix time */
      retVal = KeyM_Cert_ConvertDateToUnixTime(&thisUpdateTime, &thisUpdateUnixTime);

      if (retVal == E_OK)
      {
        retVal = E_NOT_OK;

        /* # Check validity */
        if (certTime >= thisUpdateUnixTime)
        {
          retVal = E_OK;
        }
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseTime()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseTime(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  boolean isPeriodValidityUsed = TRUE;
  uint64 certTime;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get unix timestamp */
  retVal = KeyM_Cert_GetCurrentTime(certId, &certTime, &isPeriodValidityUsed);

  if ((retVal == E_OK) && (isPeriodValidityUsed))
  {
    /* # Verify thisUpdate time element */
    retVal = KeyM_Cert_VerifyOCSPResponseThisUpdateTime(requestData, ocspResp, certTime);

    if ((retVal == E_OK) && (ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_NEXTUPDATE].isPresent))
    {
      /* # Verify optional nextUpdate time element */
      retVal = KeyM_Cert_VerifyOCSPResponseNextUpdateTime(requestData, ocspResp, certTime);
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseVersion()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseVersion(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_VERSION].isPresent)
  {
    /* # Check version element of OCSP response */
    if ((*(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_VERSION].elementOffset]) != 0u) || (ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_VERSION].elementLength != 1u))
    {
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_OCSPResponseRevokeCert()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_OCSPResponseRevokeCert(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 issuerName[KEYM_CREMAX_LENGTH_OF_ISSUER_NAME];
  uint32 issuerNameLength = KEYM_CREMAX_LENGTH_OF_ISSUER_NAME;
  uint8 serialNumber[KEYM_CREMAX_LENGTH_OF_SERIAL_NUMBER];
  uint32 serialNumberLength = KEYM_CREMAX_LENGTH_OF_SERIAL_NUMBER;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve certificate's issuer common name */
  retVal = KeyM_Cert_GetElementByStructureTypeAndOid(certId, KEYM_CERTIFICATE_ISSUER_NAME, KEYM_CERT_X509_COMMONNAMEOIDDATA, KEYM_CERT_X509_COMMONNAMEOIDDATALENGTH, issuerName, &issuerNameLength);

  if (retVal == E_OK)
  {
    /* # Retrieve certificate's serial number */
    retVal = KeyM_Cert_GetElementByStructureType(certId, KEYM_CERTIFICATE_SERIAL_NUMBER, serialNumber, &serialNumberLength);

    if (retVal == E_OK)
    {
      /* # Set a certificate revocation entry */
      retVal = KeyM_Cert_SetCRE(issuerName, (uint16)issuerNameLength, serialNumber, (uint16)serialNumberLength);
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseCertStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseCertStatus(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTSTATUS].isPresent)
  {
    /* # Check CertStatus element for revocation of referenced certificate */
    switch (*(&requestData[ocspResp[KEYM_ASN1_OCSP_RESPONSE_REFIDX_CERTSTATUS].elementOffset]))
    {
      case KEYM_ASN1_OCSP_CERT_STATUS_REVOKED:
      {
        /* # Initiate certificate revocation */
        retVal = KeyM_Cert_OCSPResponseRevokeCert(certId);
        break;
      }
      case KEYM_ASN1_OCSP_CERT_STATUS_GOOD:
      case KEYM_ASN1_OCSP_CERT_STATUS_UNKNOWN:
      {
        retVal = E_OK;
        break;
      }
      default:
      {
        retVal = E_NOT_OK;
        break;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */


# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponseData()
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
 */
/* PRQA S 6060 5 */ /*  MD_KEYM_STPAR_VERIFYOCSPRESPONSEDATA */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponseData(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  uint32 responseDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) responderCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint16 ocspId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Verify response status */
  retVal = KeyM_Cert_VerifyOCSPResponseStatus(requestData, ocspResp, responseData, responseDataLength);

  /* # Verify basic response type of OCSP response */
  if (retVal == E_OK)
  {
    retVal = KeyM_Cert_VerifyOCSPResponseType(requestData, ocspResp);
  }

  /* # Confirm that the certificate identified in a received response corresponds to
     the certificate that was identified in the corresponding request */
  if (retVal == E_OK)
  {
    retVal = KeyM_Cert_VerifyOCSPResponseCertId(requestData, ocspResp, certId, &ocspId);
  }

  /* # Verify the validity period of the OCSP response */
  if (retVal == E_OK)
  {
    retVal = KeyM_Cert_VerifyOCSPResponseTime(requestData, ocspResp, *certId);
  }

  /* # Verify version of the response, which MUST be v1 (value is 0) */
  if (retVal == E_OK)
  {
    retVal = KeyM_Cert_VerifyOCSPResponseVersion(requestData, ocspResp);
  }

  /* # Confirm that the signature on the response is valid */
  if (retVal == E_OK)
  {
    retVal = KeyM_Cert_VerifyOCSPResponseSignature(requestData, ocspResp, ocspId, *certId, responderCertId);
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyOCSPResponse()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyOCSPResponse(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  P2CONST(KeyM_Asn1_OCSPResponseElementInfoType, AUTOMATIC, KEYM_APPL_VAR) ocspResp,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  uint32 responseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType certId = 0u;
  KeyM_CertificateIdType responderCertId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Verify response attributes */
  retVal = KeyM_Cert_VerifyOCSPResponseData(requestData, ocspResp, responseData, responseDataLength, &certId, &responderCertId);

  /* # Confirm that the responder is valid */
  if (retVal == E_OK)
  {
    retVal = KeyM_Cert_VerifyOCSPResponder(responderCertId);
  }

  /* # Verify certificate status value */
  if (retVal == E_OK)
  {
    retVal = KeyM_Cert_VerifyOCSPResponseCertStatus(requestData, ocspResp, certId);
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */

# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_HandleOCSPResponse()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_HandleOCSPResponse(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) responseData,
  uint32 responseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_OCSPResponseElementInfoType ocspResp[KEYM_ASN1_OCSP_SIZE_OF_OCSP_RESPONSE_ELEMENT_STORAGE] = { 0u };

  /* ----- Implementation ----------------------------------------------- */
  /* # Parse OCSP response */
  retVal = KeyM_Cert_ParseOCSPResponse(requestData, requestDataLength, ocspResp);

  if (retVal == E_OK)
  {
    /* # Verify OCSP Response */
    retVal = KeyM_Cert_VerifyOCSPResponse(requestData, ocspResp, responseData, responseDataLength);
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */
#endif

#if ((KEYM_OCSP == STD_ON) || ((KEYM_REMOTE_OCSPENABLED == STD_ON))) /* COV_REMOTE_OCSP */
# ifndef KEYM_NOUNIT_OCSPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ServiceCertStatusOCSP()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6060 8 */ /* MD_KEYM_6060_LOCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertStatusOCSP(
  KeyM_ServiceCertificateType Service,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

#  if (KEYM_REMOTE_OCSPENABLED == STD_OFF) /* COV_KEYM_UNSUPPORTED */
  KeyM_Asn1_ParamType asn1Param;
  uint8_least i;
#  endif

  /* ----- Implementation ----------------------------------------------- */
#  if (KEYM_REMOTE_OCSPENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
  retVal = KeyM_Remote_RedirectServiceCertificateOCSP(Service, CertNamePtr, CertNameLength, RequestData, RequestDataLength, ResponseData, ResponseDataLength);
#  else

  KeyM_Asn1_Init(&asn1Param, RequestData, (uint16)RequestDataLength);

  /* # Iterate through OCSP response list */
  for (i = 0u; i < KeyM_GetSizeOfOCSP(); i++)
  {
    retVal = KeyM_Cert_GetTL(&asn1Param);

    if (retVal == E_OK)
    {
      /* # Handle single OCSP response */
      retVal = KeyM_Cert_HandleOCSPResponse(&RequestData[asn1Param.last_tag_base_pos], (uint32)asn1Param.current_pos + (uint32)asn1Param.last_tag_len - (uint32)asn1Param.last_tag_base_pos, ResponseData, ResponseDataLength);
      KeyM_Asn1_NextTag(&asn1Param);
    }

    if ((retVal != E_OK) || (asn1Param.remaining_len == 0u))
    {
      break;
    }
  }

  KEYM_DUMMY_STATEMENT(CertNamePtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(CertNameLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(Service); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_OCSPHANDLING */
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ServiceCertSet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6050, 6080 4 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertSet(
  KeyM_CertificateIdType CertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertDataType ramBuffer;
  ramBuffer = KeyM_Cert_GetCertificateWriteBufferData(CertId);

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if certificate data length is invalid */
  if (ramBuffer.certDataLength < RequestDataLength)
  {
    retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
  }
  /* # Check if certificate slot is empty */
  else if (!KeyM_Cert_IsCertSlotEmpty(CertId))
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* Check if KeyM is currently busy with other jobs */
    SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
    if (KeyM_Cert_TaskState == KEYM_CERT_TASKSTATE_IDLE)
    {
      KeyM_Cert_TaskState = KEYM_CERT_TASKSTATE_BUSY;
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

      /* # Copy certificate to local buffer */
      /* Copy within exclusive area. Data might be being accessed by
       * - NVM copy callouts */
      SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();
      VStdLib_MemCpyLarge(ramBuffer.certData, RequestData, RequestDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_MEMCPY_WRITEBUFFER */
      KeyM_Cert_SetCertificateWrittenLength(CertId, (uint16)RequestDataLength);
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

      KeyM_Asn1_ClearCertificateElementStorage(CertId);
      KeyM_Cert_SetStatusInfo(CertId, KEYM_CERTIFICATE_NOT_PARSED);

      /* Set storage type */
      KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)(CertId), (tKeyMCertStorageType)((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)CertId)) | (KEYM_CERT_STORAGE_MASK_DATA_BUFFER | KEYM_CERT_STORAGE_MASK_DIRTY)));

      /* Set certificate request type */
      KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)CertId)->request = (tKeyMCertRequestType)(KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)CertId)->request | (tKeyMCertRequestType)(KEYM_CERT_REQUEST_SERVICE));
      KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)CertId)->request = (tKeyMCertRequestType)(KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)CertId)->request | (tKeyMCertRequestType)(KEYM_CERT_REQUEST_VERIFY));

#  if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
      KeyM_Cert_SetSlotOwner(CertId);
#  endif

#  if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
      KeyM_Cert_ResetUpperHierarchicalRefInfo(CertId);
      retVal = KeyM_Cert_CheckDynamicIssuer(CertId);

      if (retVal == E_OK)
#  endif
      {
        /* # Check if issuer certificate is valid */
        retVal = KeyM_Cert_CheckIssuerValidity(CertId);

        if (retVal == E_OK)
        {
          /* # Parse certificate */
          /* # Verify certificate elements */
          retVal = KeyM_Cert_ParseAndVerifyElements(CertId);

#  if (KEYM_CERTCSMHASHJOBREFOFCERTIFICATE == STD_ON)
          if ((retVal == E_OK) && (KeyM_IsCertHashStorageUsedOfCertificate((KeyM_CertificateIterType)CertId))) /* PRQA S 2995 */ /* MD_KEYM_2.2 */
          {
              retVal = KeyM_Cert_ComputeCertHash(CertId); /* VCA_KEYM_FUNCTION_REQUIREMENT_CHECKED */
          }
#  endif
        }
      }
      if (retVal == E_OK)
      {
        SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
        KeyM_Cert_TriggerStateAfterCertElementVerification(CertId);
        KeyM_Cert_CertId = CertId;
        KeyM_Cert_RequestId = CertId;
        SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
      }
      else
      {
        KeyM_Cert_TaskState = KEYM_CERT_TASKSTATE_IDLE;
      }
    }
    else
    {
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
      retVal = KEYM_E_BUSY;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SETCERT */
#endif

#if ((KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON) && (KEYM_ELEMENTOIDPRIMARYUSEDOFCERTIFICATEGROUP == STD_ON))
# ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsGroupHeterogeneous()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsGroupHeterogeneous(
  KeyM_CertificateGroupIdType groupId)
{
  return KeyM_GetCertificateGroupLengthOfCertificateGroupExt((KeyM_CertificateGroupExtIterType)groupId) > 1u;
}
# endif /* ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING */
#endif

#if ((KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON) && (KEYM_ELEMENTOIDPRIMARYUSEDOFCERTIFICATEGROUP == STD_ON))
# ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetSubGroupId()
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
/* PRQA S 6050, 6080 1 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetSubGroupId(
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) certData,
  uint32 certDataLength,
  P2VAR(KeyM_CertificateGroupIdType, AUTOMATIC, KEYM_APPL_VAR) subGroupId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateGroupIterType groupIdx;
  uint8 oidData[KEYM_CERTIFICATESUBJECTPUBLICKEYINFO_PUBLICKEYALGORITHM_MAX_LENGTH] = { 0u };
  uint32 oidDataLength = KEYM_CERTIFICATESUBJECTPUBLICKEYINFO_PUBLICKEYALGORITHM_MAX_LENGTH;
  boolean isSubGroupFound = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through sub groups of external group */
  for (groupIdx = KeyM_GetCertificateGroupStartIdxOfCertificateGroupExt((KeyM_CertificateGroupExtIterType)groupId); groupIdx < KeyM_GetCertificateGroupEndIdxOfCertificateGroupExt((KeyM_CertificateGroupExtIterType)groupId); groupIdx++)
  {
    /* # Check if sub group contains a primary OID for the public key algorithm */
    if (KeyM_IsElementOidPrimaryUsedOfCertificateGroup(groupIdx))
    {
      /* # Retrieve the public key algorithm from the passed certificate data */
      retVal = KeyM_Cert_CertElementGetByStructureType(certData, certDataLength, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM, oidData, &oidDataLength);

      if (retVal == E_OK)
      {
        KeyM_ElementOidPrimaryStartIdxOfCertificateGroupType primaryOidStartIdx = KeyM_GetElementOidPrimaryStartIdxOfCertificateGroup(groupIdx);
        /*@ assert primaryOidStartIdx < KeyM_GetSizeOfElementOid(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

        /* # Compare retrieved primary OID from certificate data with configured public key algorithm OID of current sub group */
        isSubGroupFound = KeyM_Utils_BufferCmp(
          KeyM_GetAddrElementOid(primaryOidStartIdx),
          KeyM_GetElementOidPrimaryLengthOfCertificateGroup(groupIdx),
          oidData,
          oidDataLength);

#  if (KEYM_ELEMENTOIDSECONDARYUSEDOFCERTIFICATEGROUP == STD_ON)
        /* # Check if sub group contains a secondary OID in case of ECDSA algorithm */
        if (KeyM_IsElementOidSecondaryUsedOfCertificateGroup(groupIdx) && isSubGroupFound)
        {
          isSubGroupFound = FALSE;

          /* # Retrieve the secondary OID that specifies the ECC curve */
          oidDataLength = KEYM_CERTIFICATESUBJECTPUBLICKEYINFO_PUBLICKEYALGORITHM_MAX_LENGTH;
          retVal = KeyM_Cert_CertElementGetByStructureType(certData, certDataLength, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ECC_CURVE, oidData, &oidDataLength);

          if (retVal == E_OK)
          {
            KeyM_ElementOidSecondaryStartIdxOfCertificateGroupType secondaryOidStartIdx = KeyM_GetElementOidSecondaryStartIdxOfCertificateGroup(groupIdx);
            /*@ assert secondaryOidStartIdx < KeyM_GetSizeOfElementOid(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

            /* # Compare retrieved secondary OID from certificate data with configured ECC curve OID of current sub group */
            isSubGroupFound = KeyM_Utils_BufferCmp(
                  KeyM_GetAddrElementOid(secondaryOidStartIdx),
                  KeyM_GetElementOidSecondaryLengthOfCertificateGroup(groupIdx),
                  oidData,
              oidDataLength);
          }
        }
#  endif

        if(isSubGroupFound)
        {
          /* # Return the current certificate group index */
          *subGroupId = (KeyM_CertificateGroupIdType)groupIdx;
        }
      }
    }
    else
    {
      retVal = E_NOT_OK;
    }

    if (isSubGroupFound || (retVal == E_NOT_OK))
    {
      break;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING */
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertDataLengthOfGroupInvalid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertDataLengthOfGroupInvalid(
  KeyM_CertificateGroupIdType groupId,
  uint32 RequestDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = TRUE;
  KeyM_CertificateIdType certId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get certificate identifier of one of group member certificates */
  certId = KeyM_GetCertificateIdxOfGroupInd(KeyM_GetGroupIndCertStartIdxOfCertificateGroup((KeyM_CertificateGroupIterType)groupId));

  /* # Check input data length with configured maximum data length */
  if (RequestDataLength <= KeyM_GetMaxLengthOfCertificate((KeyM_CertificateIterType)certId))
  {
    retVal = FALSE;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING */
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetSubjectCommonName()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6080 5 */ /* MD_MSR_STMIF */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetSubjectCommonName(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) subjectCommonNameData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) subjectCommonNameDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_ParamType asn1Param;
  boolean isIssuerCommonNameFound = FALSE;
  boolean isSubjectCommonNameFound = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* # Initialize parser */
  KeyM_Asn1_Init(&asn1Param, requestData, (uint16)requestDataLength);
  retVal = KeyM_Cert_GetTL(&asn1Param);

  /* # Parse certificate data until subject common name is found */
  while ((retVal == E_OK) && (asn1Param.remaining_len != 0u))
  {
    if (isSubjectCommonNameFound)
    {
      if (*subjectCommonNameDataLength < asn1Param.last_tag_len)
      {
        retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
      }
      else
      {
        /* Copy subject common name to output buffer */
        VStdLib_MemCpyLarge(subjectCommonNameData, &requestData[asn1Param.current_pos], asn1Param.last_tag_len); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_GETSUBJECTCOMMONNAME_MEMCPY */
        *subjectCommonNameDataLength = asn1Param.last_tag_len;
      }
      break;
    }

    /* Check if tag is constructed */
    if (asn1Param.last_tag_has_data)
    {
      /* Check object identifier for common name */
      if ((asn1Param.last_tag == KEYM_ASN1_TYPE_OBJECTID))
      {
        if (KeyM_Utils_MemCmp(&requestData[asn1Param.current_pos], KEYM_CERT_X509_COMMONNAMEOIDDATA, KEYM_CERT_X509_COMMONNAMEOIDDATALENGTH))
        {
          if (isIssuerCommonNameFound)
          {
            /* Second object identifier match */
            isSubjectCommonNameFound = TRUE;
          }
          else
          {
            /* First object identifier match */
            isIssuerCommonNameFound = TRUE;
          }
        }
      }
      /* # Iterate to next tag */
      KeyM_Asn1_NextTag(&asn1Param);
    }

    retVal = KeyM_Cert_GetTL(&asn1Param);
  }

  if (!isSubjectCommonNameFound)
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */
#endif

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsLowerCertAvailable()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsLowerCertAvailable(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType subRetVal;
  KeyM_CertificateIterType certIdx;
  KeyM_CertificateIdType issuerCertId = 0u;
  boolean isCertSlotEmpty = TRUE;
  boolean isLowerCertAvailable = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through configured certificates */
  for (certIdx = 0u; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
  {
    if (KeyM_GetStorageOfCertificate(certIdx) != KEYM_STORAGE_IN_ROM)
    {
      isCertSlotEmpty = KeyM_Cert_IsCertSlotEmpty((KeyM_CertificateIdType)certIdx); /* PRQA S 2983 */ /* MD_KEYM_2.2 */
    }

    /* # Check if certificate in lower hierarchy is configured and set */
    if ((!isCertSlotEmpty) || (KeyM_GetStorageOfCertificate(certIdx) == KEYM_STORAGE_IN_ROM))
    {
      subRetVal = KeyM_Cert_GetIssuerCertId((KeyM_CertificateIdType)certIdx, &issuerCertId);

      if ((subRetVal == E_OK)
        && (((certId == issuerCertId)
# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
        /* Check if certificate is a group certificate */
        && (!((KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_DYNAMIC_MANDATORY_ISSUER)
              || (KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_DYNAMIC_OPTIONAL_ISSUER)
              || (KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_DYNAMIC_SELFSIGNED_OR_MANDATORY_ISSUER)))
# endif
          )
# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
          || ((certId == issuerCertId)
          /* Check if certificate is a group certificate */
          && (((KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)certIdx) == KEYM_DYNAMIC_MANDATORY_ISSUER)
              || (KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)certIdx) == KEYM_DYNAMIC_OPTIONAL_ISSUER)
              || (KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)certIdx) == KEYM_DYNAMIC_SELFSIGNED_OR_MANDATORY_ISSUER)))
            && (KeyM_GetCertificateGroupIdxOfCertificate((KeyM_CertificateIterType)certId) == KeyM_GetCertificateGroupIdxOfCertificate((KeyM_CertificateIterType)certIdx)))
# endif
          )
        && (certId != certIdx)) /* PRQA S 2992, 2996 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
      {
        isLowerCertAvailable = TRUE; /* PRQA S 2880 */ /* MD_MSR_Unreachable */
        break;
      }
    }
  }

  return isLowerCertAvailable;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_CREHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCRESet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCRESet(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isCRESet = FALSE;
  KeyM_CREInfoIterType creIdx;
  KeyM_CREInfoIterType numCres;
  uint16 setIssuerNameDataLength;
  uint16 setSerialNumberDataLength;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through previously set CREs */

  /* defensive programming: mistrust content of global variable KeyM_Cert_NumOfCRE and make sure that the index we use for CSL accesses is always in-bounds */
  numCres = (((KeyM_Cert_NumOfCRE) < (KeyM_GetSizeOfCREInfo())) ? (KeyM_Cert_NumOfCRE) : (KeyM_GetSizeOfCREInfo()));

  for (creIdx = 0u; creIdx < numCres; creIdx++)
  {
    /* # Compare issuer name and serial number */
    setIssuerNameDataLength = KeyM_Cert_GetCREIssuerNameWrittenLength((KeyM_SizeOfCREInfoType)creIdx);
    setSerialNumberDataLength = KeyM_Cert_GetCRESerialNumberWrittenLength((KeyM_SizeOfCREInfoType)creIdx);

    if (KeyM_Utils_BufferCmp(IssuerNameData, IssuerNameDataLength, KeyM_GetAddrCREStorage(KeyM_GetCREStorageIssuerStartIdxOfCREInfo(creIdx)), setIssuerNameDataLength))
    {
      if (KeyM_Utils_BufferCmp(SerialNumberData, SerialNumberDataLength, KeyM_GetAddrCREStorage(KeyM_GetCREStorageSerialNumberStartIdxOfCREInfo(creIdx)), setSerialNumberDataLength))
      {
        isCRESet = TRUE;
        break;
      }
    }
  }

  return isCRESet;
}
# endif /* ifndef KEYM_NOUNIT_CREHANDLING */
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_CREHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_AppendCRE()
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
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_AppendCRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (KeyM_Cert_NumOfCRE < KeyM_GetSizeOfCREInfo())
  {
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) creStorageId = KeyM_GetAddrCREStorage(KeyM_GetCREStorageIdStartIdxOfCREInfo(KeyM_Cert_NumOfCRE));
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) creStorageIssuer = KeyM_GetAddrCREStorage(KeyM_GetCREStorageIssuerStartIdxOfCREInfo(KeyM_Cert_NumOfCRE));
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) creStorageSerial = KeyM_GetAddrCREStorage(KeyM_GetCREStorageSerialNumberStartIdxOfCREInfo(KeyM_Cert_NumOfCRE));
    KeyM_SizeOfCREStorageType creStorageIdLength = (KeyM_SizeOfCREStorageType)KeyM_GetCREStorageIdLengthOfCREInfo(KeyM_Cert_NumOfCRE);
    KeyM_SizeOfCREStorageType creStorageIssuerLength = (KeyM_SizeOfCREStorageType)KeyM_GetCREStorageIssuerLengthOfCREInfo(KeyM_Cert_NumOfCRE);
    KeyM_SizeOfCREStorageType creStorageSerialLength = (KeyM_SizeOfCREStorageType)KeyM_GetCREStorageSerialNumberLengthOfCREInfo(KeyM_Cert_NumOfCRE);

    if ((IssuerNameDataLength <= creStorageIssuerLength)      /* check that issuer name fits in storage */
      && (SerialNumberDataLength <= creStorageSerialLength))  /* check that serial number fits in storage */
    {
      /* Copy within exclusive area. Data might be being accessed by
       * - NVM copy callouts */
      SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();

      /* # Clear bytes of Id field */
      VStdLib_MemClr(creStorageId, creStorageIdLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CSL03_PASSING_BUFFER */

      /* # Set issuer name */
      KeyM_Cert_SetCREIssuerNameWrittenLength((KeyM_SizeOfCREInfoType)KeyM_Cert_NumOfCRE, IssuerNameDataLength);
      VStdLib_MemCpy(creStorageIssuer, IssuerNameData, IssuerNameDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_APPENDCRE_MEMCPY_ISSUERNAME */

      /* # Clear remaining bytes of issuer name buffer to have a specified value */
      VStdLib_MemClr(&creStorageIssuer[IssuerNameDataLength], ((VStdLib_CntType)creStorageIssuerLength - (VStdLib_CntType)(IssuerNameDataLength)));  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CSL03_PASSING_BUFFER_WITH_OFFSET */

      /* # Set serial number */
      KeyM_Cert_SetCRESerialNumberWrittenLength((KeyM_SizeOfCREInfoType)KeyM_Cert_NumOfCRE, SerialNumberDataLength);
      VStdLib_MemCpy(creStorageSerial, SerialNumberData, SerialNumberDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_APPENDCRE_MEMCPY_SERIAL */

      /* # Clear remaining bytes of serial number buffer to have a specified value */
      VStdLib_MemClr(&creStorageSerial[SerialNumberDataLength], ((VStdLib_CntType)creStorageSerialLength - (VStdLib_CntType)(SerialNumberDataLength)));  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CSL03_PASSING_BUFFER_WITH_OFFSET */

      /* # Update number of CRE */
      KeyM_Cert_NumOfCRE++;

      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

      /* # Persist CRE to NvM */
      KeyM_NvBlock_Persist_CRE();

      retVal = E_OK;
    }
    else
    {
      retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_CREHANDLING */
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_CREHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_UpdateCertStatusForCRE()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_UpdateCertStatusForCRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_CertificateIterType certIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through all certificates */
  for (certIdx = 0u; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
  {
    if (KeyM_Cert_IsCertRevokedBySingleCRE((KeyM_CertificateIdType)certIdx, IssuerNameData, IssuerNameDataLength, SerialNumberData, SerialNumberDataLength))
    {
      /* # Revoke certificate */
      KeyM_Cert_SetStatusInfo((KeyM_CertificateIdType)certIdx, KEYM_E_CERTIFICATE_REVOKED);

      /* # Invalidate certificates in lower hierarchy */
      KeyM_Cert_InvalidateLowerCert((KeyM_CertificateIdType)certIdx);

      break;
    }
  }
}
# endif /* ifndef KEYM_NOUNIT_CREHANDLING */
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_CREHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertRevokedBySingleCRE()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertRevokedBySingleCRE(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType subRetVal;
  uint8 issuerName[KEYM_CREMAX_LENGTH_OF_ISSUER_NAME];
  uint32 issuerNameLength = KEYM_CREMAX_LENGTH_OF_ISSUER_NAME;
  uint8 serialNumber[KEYM_CREMAX_LENGTH_OF_SERIAL_NUMBER];
  uint32 serialNumberLength = KEYM_CREMAX_LENGTH_OF_SERIAL_NUMBER;
  boolean isCertRevoked = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get issuer common name of referenced certificate */
  subRetVal = KeyM_Cert_GetElementByStructureTypeAndOid(certId, KEYM_CERTIFICATE_ISSUER_NAME, KEYM_CERT_X509_COMMONNAMEOIDDATA, KEYM_CERT_X509_COMMONNAMEOIDDATALENGTH, issuerName, &issuerNameLength);

  if (subRetVal == E_OK)
  {
    /* # Get serial number of referenced certificate */
    subRetVal = KeyM_Cert_GetElementByStructureType(certId, KEYM_CERTIFICATE_SERIAL_NUMBER, serialNumber, &serialNumberLength);

    if (subRetVal == E_OK)
    {

      /* # Compare common name and serial number */
      if (KeyM_Utils_BufferCmp(IssuerNameData, IssuerNameDataLength, issuerName, issuerNameLength))
      {
        if (KeyM_Utils_BufferCmp(SerialNumberData, SerialNumberDataLength, serialNumber, serialNumberLength))
        {
          isCertRevoked = TRUE;
        }
      }
    }
  }
  return isCertRevoked;
}
# endif /* ifndef KEYM_NOUNIT_CREHANDLING */
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_CREHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_InvalidateLowerCert()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_InvalidateLowerCert(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_CertificateIterType certIdx;
  KeyM_CertificateStatusType certStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through all certificates */
  for (certIdx = 0u; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
  {
    /* # Consider only certificates within PKI of referenced certificate */
    if (KeyM_Cert_IsCertInPKI((KeyM_CertificateIdType)certIdx, certId))
    {
      /* # Consider only certificates within chain of referenced certificate */
      if (KeyM_Cert_IsCertInChainOfCA((KeyM_CertificateIdType)certIdx, certId))
      {
        certStatus = KeyM_Cert_GetStatusInfo((KeyM_CertificateIdType)certIdx);

        /* # Invalidate valid certificates */
        if (certStatus == KEYM_CERTIFICATE_VALID)
        {
          KeyM_Cert_SetStatusInfo((KeyM_CertificateIdType)certIdx, KEYM_CERTIFICATE_PARSED_NOT_VALIDATED);
        }
      }
    }
  }
}
# endif /* ifndef KEYM_NOUNIT_CREHANDLING */
#endif

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CheckChainStorageInternal()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010 1 */ /* MD_MSR_STPTH */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CheckChainStorageInternal(
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) certId,
  P2CONST(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) certChain,
  KeyM_CertificateIterType certIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIterType certNum;
  KeyM_CertificateIterType certIdxLocal = certIdx;

  /* ----- Implementation ----------------------------------------------- */
  certNum = certIdxLocal + 1u; /* number of certificates in chain */

  /* # Parse chain from top to bottom and check storage */
  for (certIdxLocal = 0u; certIdxLocal < certNum; certIdxLocal++)
  {
    KeyM_CertificateIdType currentCertId = certChain[certNum - 1u - certIdxLocal];

    /*@ assert currentCertId < KeyM_GetSizeOfCertificate(); */ /* VCA_KEYM_CERT_CHECKCHAINSTORAGE_CERTCHAINID */
    if ((!KeyM_Cert_IsCertSlotEmpty(currentCertId)) || (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)currentCertId) == KEYM_STORAGE_IN_ROM))
    {
      /* After finished startup or for all available certificates configured with startup handling */
      if ((KeyM_Cert_StartUpState == KEYM_CERT_STARTUP_STATE_FINISHED) || (KeyM_GetCertStartUpHandlingOfCertificate((KeyM_CertificateIterType)currentCertId) != KEYM_NONE))
      {
        *certId = currentCertId;
        retVal = E_OK;
      }
      else
      {
        continue;
      }
    }
    else
    {
      break;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CheckChainStorage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CheckChainStorage(
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIdType certChain[KEYM_CERTIFICATE_CHAIN_MAX_DEPTH];
  KeyM_CertificateIdType localCertId = *certId;
  KeyM_CertificateIterType certIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* # Identify identify all certificates in chain */
  for (certIdx = 0u; certIdx < KEYM_CERTIFICATE_CHAIN_MAX_DEPTH; certIdx++)
  {
    boolean isRoot = KeyM_Cert_IsCertRoot(localCertId);
    KeyM_CertificateIdType issuerCertId;

    /*@ assert localCertId < KeyM_GetSizeOfCertificate(); */
    certChain[certIdx] = localCertId;
    retVal = KeyM_Cert_GetIssuerCertId(localCertId, &issuerCertId);

    /* move one certificate upward in the chain */
    if (retVal == E_OK)
    {
      localCertId = issuerCertId;
    }

    if (isRoot || (retVal == E_NOT_OK)) /* PRQA S 2991, 2995 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
    {
      /* highest (available) certificate in chain found */
      break;
    }
  }

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
  /* If certificate's issuer is optional, it is OK if we did not find it */
  if ((retVal == E_NOT_OK) && ((KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)localCertId) == KEYM_DYNAMIC_OPTIONAL_ISSUER) && (!(KeyM_Cert_UpperHierarachicalRefInfo[localCertId].isIssuerCertIdAvailable))))
  {
    retVal = E_OK;
  }
# endif

  /* if the loop above terminated without finding an issuer (or our issuer is optional), this is a problem */
  if (certIdx >= KEYM_CERTIFICATE_CHAIN_MAX_DEPTH)
  {
    retVal = E_NOT_OK;
  }

  if (retVal == E_OK)
  {
    /*@ assert certIdx < KEYM_CERTIFICATE_CHAIN_MAX_DEPTH; */
    /* # Parse chain from top to bottom and check storage */
    retVal = KeyM_Cert_CheckChainStorageInternal(certId, certChain, certIdx);
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#if ((KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertInChainOfCA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertInChainOfCA(
  KeyM_CertificateIdType wCertId,
  KeyM_CertificateIdType caCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIterType certIdx;
  KeyM_CertificateIdType localCertId = wCertId;
  KeyM_CertificateIdType issuerCertId = 0u;
  boolean isCertInChainOfIntermediate = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  retVal = KeyM_Cert_GetIssuerCertId(localCertId, &issuerCertId);

  if (retVal == E_OK)
  {
    /* # Iterate through certificate chain */
    for (certIdx = 0u; (certIdx < KeyM_GetCertificateChainMaxDepthOfGeneral()) && (localCertId != issuerCertId) && (retVal == E_OK); certIdx++) /* PRQA S 2994 */ /* MD_KEYM_14.3 */
    {
      localCertId = issuerCertId;

      /* # If referenced CA is found, return TRUE */
      if (localCertId == caCertId) /* PRQA S 2880 */ /* MD_MSR_Unreachable */
      {
        isCertInChainOfIntermediate = TRUE;
        break;
      }

      retVal = KeyM_Cert_GetIssuerCertId(localCertId, &issuerCertId);
    }
  }

  return isCertInChainOfIntermediate;
}
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertLeaf()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertLeaf(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  boolean isCertLeaf = TRUE;
  KeyM_CertificateIdType issuerCertId = 0u;
  KeyM_CertificateIterType certIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through configured certificates */
  for (certIdx = 0u; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
  {
    /* # Certificate is not a leaf if it is referenced as upper hierarchical certificate */
    retVal = KeyM_Cert_GetIssuerCertId((KeyM_CertificateIdType)certIdx, &issuerCertId);

    if ((retVal == E_OK) && (issuerCertId == certId))
    {
      isCertLeaf = FALSE;
      break;
    }
  }

  return isCertLeaf;
}
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */
#endif

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertRoot()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertRoot(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  boolean isCertRoot = FALSE;
  KeyM_CertificateIdType issuerCertId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get issuer certificate identifier */
  retVal = KeyM_Cert_GetIssuerCertId(certId, &issuerCertId);

  /* # Compare working certificate identifier with issuer certificate identifier */
  if ((retVal == E_OK) && (certId == issuerCertId)) /* PRQA S 2995 */ /* MD_KEYM_2.2 */
  {
    isCertRoot = TRUE;
  }

  return isCertRoot;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertIntermediate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertIntermediate(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isCertIntermediate = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if leaf certificate */
  if (!KeyM_Cert_IsCertLeaf(certId))
  {
    /* # Check if root or CRL certificate */
    if ((!KeyM_Cert_IsCertRoot(certId)) && (!(KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CRL)))
    {
      isCertIntermediate = TRUE;
    }
  }

  return isCertIntermediate;
}
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */
#endif

#if ((KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetRootCertId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetRootCertId(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) rootCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_CertificateIterType certIdx;
  boolean rootFound = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  *rootCertId = certId;

  /* # Iterate through certificate chain */
  for (certIdx = 0; (certIdx < KeyM_GetCertificateChainMaxDepthOfGeneral()) && (retVal == E_OK); certIdx++)
  {
    /* # Return if root certificate is reached */
    if (KeyM_Cert_IsCertRoot(*rootCertId))
    {
      rootFound = TRUE;
      break;
    }

    retVal = KeyM_Cert_GetIssuerCertId(*rootCertId, rootCertId);
  }

  if (!rootFound)
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetEmptyGroupCertId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetEmptyGroupCertId(
  KeyM_CertificateGroupIdType groupId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_GroupIndIterType groupIndIdx;
  KeyM_CertificateIdType localCertId;
  KeyM_CertificateStatusType certStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through group certificates */
  for (groupIndIdx = KeyM_GetGroupIndCertStartIdxOfCertificateGroup((KeyM_CertificateGroupIterType)groupId); groupIndIdx < KeyM_GetGroupIndCertEndIdxOfCertificateGroup((KeyM_CertificateGroupIterType)groupId); groupIndIdx++)
  {
    localCertId = KeyM_GetCertificateIdxOfGroupInd(groupIndIdx);

    certStatus = KeyM_Cert_GetStatusInfo(localCertId);;

    /* # Return certificate identifier for empty certificate slot */
    if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
    {
      *certId = localCertId;
      retVal = E_OK;
      break;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING */
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_SearchSubjectCommonNameDataInGroup()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_SearchSubjectCommonNameDataInGroup(
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) subjectCommonNameData,
  uint32 subjectCommonNameDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) refCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;
  KeyM_CertificateIdType certId;
  KeyM_CertificateStatusType certStatus;
  KeyM_SizeOfCertificateElementType refSubjectElementIdx = 0u;
  KeyM_GroupIndIterType groupIndIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through group certificates */
  for (groupIndIdx = KeyM_GetGroupIndCertStartIdxOfCertificateGroup((KeyM_CertificateGroupIterType)groupId); groupIndIdx < KeyM_GetGroupIndCertEndIdxOfCertificateGroup((KeyM_CertificateGroupIterType)groupId); groupIndIdx++)
  {
    certId = KeyM_GetCertificateIdxOfGroupInd(groupIndIdx);

    certStatus = KeyM_Cert_GetStatusInfo(certId);

    /* # Consider only parsed certificates */
    if (((certStatus == KEYM_CERTIFICATE_PARSED_NOT_VALIDATED) || (certStatus == KEYM_CERTIFICATE_VALID)))
    {
      /* # Search subject common name by structure type and oid in configuration */
      if (KeyM_Cert_IsCertElementFound((KeyM_CertificateIdType)certId, KEYM_CERTIFICATE_SUBJECT_NAME, KEYM_CERT_X509_COMMONNAMEOIDDATA, KEYM_CERT_X509_COMMONNAMEOIDDATALENGTH, &refSubjectElementIdx))
      {
        /* # Compare subject common name */
        if (KeyM_Utils_BufferCmp(KeyM_Cert_GetCertElementDataPointer((KeyM_CertificateIdType)certId, refSubjectElementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(refSubjectElementIdx)).length, subjectCommonNameData, subjectCommonNameDataLength))
        {
          *refCertId = (KeyM_CertificateIdType)certId;
          retVal = TRUE;
          break;
        }
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING */
#endif

#if ((KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertInPKI()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertInPKI(
  KeyM_CertificateIdType certId,
  KeyM_CertificateIdType refCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isCertInPKI = FALSE;
  Std_ReturnType retVal;
  KeyM_CertificateIdType rootCertId;
  KeyM_CertificateIdType refRootCertId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get root of working certificate */
  retVal = KeyM_Cert_GetRootCertId(certId, &rootCertId);

  if (retVal == E_OK)
  {
    /* # Get root of reference certificate */
    retVal = KeyM_Cert_GetRootCertId(refCertId, &refRootCertId);

    if (retVal == E_OK)
    {
      /* # Compare root certificates */
      if (rootCertId == refRootCertId)
      {
        isCertInPKI = TRUE;
      }
    }
  }

  return isCertInPKI;
}
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */
#endif

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsSameIssuer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsSameIssuer(
  KeyM_CertificateIdType certId1,
  KeyM_CertificateIdType certId2)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isSameIssuer = FALSE;
  Std_ReturnType retVal;
  KeyM_CertificateIdType issuerCertId1;
  KeyM_CertificateIdType issuerCertId2;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get issuer of first certificate */
  retVal = KeyM_Cert_GetIssuerCertId(certId1, &issuerCertId1);

  if (retVal == E_OK)
  {
    /* # Get issuer of second certificate */
    retVal = KeyM_Cert_GetIssuerCertId(certId2, &issuerCertId2);

    if (retVal == E_OK)
    {
      /* # Compare both certificates' issuers */
      if (issuerCertId1 == issuerCertId2)
      {
        isSameIssuer = TRUE;
      }
    }
  }

  return isSameIssuer;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ServiceCertUpdateTriggerVerification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertUpdateTriggerVerification(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  tKeyMCertState localState = KEYM_CERT_STATE_IDLE;
  KeyM_CertificateIdType upperCertId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Trigger certificate verification */
  if (KeyM_Cert_IsCertRoot(certId))
  {
    KeyM_Cert_ChainVerificationFlag = TRUE;
    /* For a root update, the verification has to start with the root itself */
    retVal = KeyM_Cert_VerifyCertificatesProcess(certId, certId, &localState);
  }
  else
  {
    retVal = KeyM_Cert_GetIssuerCertId(certId, &upperCertId);

    if (retVal == E_OK)
    {
      KeyM_Cert_ChainVerificationFlag = TRUE;
      retVal = KeyM_Cert_VerifyCertificatesProcess(certId, upperCertId, &localState);
    }
  }

  if (retVal == E_OK)
  {
    /* Set request type */
    KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certId)->request = (tKeyMCertRequestType)(KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certId)->request | (tKeyMCertRequestType)(KEYM_CERT_REQUEST_SERVICE));
    KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certId)->request = (tKeyMCertRequestType)(KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certId)->request | (tKeyMCertRequestType)(KEYM_CERT_REQUEST_VERIFY));

    /* Update global RAM variables */
    SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
    KeyM_Cert_State = localState;
    KeyM_Cert_CertId = certId;
    KeyM_Cert_RequestId = certId;
    KeyM_Cert_UpdateFlag = TRUE;
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SETCERT */
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ServiceCertUpdateData()
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
 */
/* PRQA S 6050 4 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertUpdateData(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK; /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  KeyM_CertDataType ramBuffer;
  ramBuffer = KeyM_Cert_GetCertificateWriteBufferData(certId);

  /* ----- Implementation ----------------------------------------------- */
  /* # Copy new certificate data */
  if (ramBuffer.certDataLength < requestDataLength)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* Copy within exclusive area. Data might be being accessed by
     * - NVM copy callouts */
    SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();
    VStdLib_MemCpyLarge(ramBuffer.certData, requestData, requestDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_MEMCPY_WRITEBUFFER */

    /* # Set certificate data written length */
    KeyM_Cert_SetCertificateWrittenLength(certId, (uint16)requestDataLength);
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

    /* # Clear certificate element reference storage */
    KeyM_Asn1_ClearCertificateElementStorage(certId);

    /* # Set certificate status */
    KeyM_Cert_SetStatusInfo(certId, KEYM_CERTIFICATE_NOT_PARSED);

    /* # Set storage type */
    KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)(certId), (tKeyMCertStorageType)((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)certId)) | (KEYM_CERT_STORAGE_MASK_DATA_BUFFER | KEYM_CERT_STORAGE_MASK_DIRTY)));

#  if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
    KeyM_Cert_SetSlotOwner(certId);
#  endif

#  if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
    /* # Reset previously determined dynamic issuer references */
    KeyM_Cert_ResetUpperHierarchicalRefInfo(certId);

    /* # Check validity of dynamic issuer  */
    retVal = KeyM_Cert_CheckDynamicIssuer(certId);
#  endif
  }

  if (retVal == E_OK)
  {
    /* # Check if issuer certificate is valid */
    retVal = KeyM_Cert_CheckIssuerValidity(certId);

    if (retVal == E_OK)
    {
      /* # Parse certificate */
      /* # Verify certificate elements */
      retVal = KeyM_Cert_ParseAndVerifyElements(certId);

#  if (KEYM_CERTCSMHASHJOBREFOFCERTIFICATE == STD_ON)
      if ((retVal == E_OK) && (KeyM_IsCertHashStorageUsedOfCertificate((KeyM_CertificateIterType)certId))) /* PRQA S 2995 */ /* MD_KEYM_2.2 */
      {
          retVal = KeyM_Cert_ComputeCertHash(certId); /* VCA_KEYM_FUNCTION_REQUIREMENT_CHECKED */
      }
#  endif
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SETCERT */
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ServiceCertUpdateCertId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertUpdateCertId(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  boolean isCertSlotEmpty;
  KeyM_CertificateIdType lowestCertId;

  /* ----- Implementation ----------------------------------------------- */
  isCertSlotEmpty = KeyM_Cert_IsCertSlotEmpty((KeyM_CertificateIdType)certId);

  /* # Find lowest certificates in chain */
  if ((!KeyM_Cert_IsLowerCertAvailable((KeyM_CertificateIdType)certId)) && (!isCertSlotEmpty)) /* PRQA S 2995 */ /* MD_KEYM_2.2 */
  {
    /* Check for incomplete chain */
    lowestCertId = (KeyM_CertificateIdType)certId;
    retVal = KeyM_Cert_CheckChainStorage(&lowestCertId);

    if (retVal == E_OK)
    {
      if (!KeyM_Cert_IsCertRoot(lowestCertId))
      {
        /* # Copy certificate Id to buffer for further verification */
        (void)KeyM_Cert_PushLeafCertToVerify(lowestCertId);
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SETCERT */
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ServiceCertUpdateStatus()
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
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertUpdateStatus(
  KeyM_CertificateIdType certIdOfUpdate,
  KeyM_CertificateIdType certIdOfInvalidation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateStatusType localCertStatus;
  KeyM_CertificateIdType crlIssuerCertId;

  /* ----- Implementation ----------------------------------------------- */
  if (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certIdOfUpdate) == KEYM_CRL)
  {
    retVal = KeyM_Cert_GetIssuerCertId(certIdOfUpdate, &crlIssuerCertId);

    if ((retVal == E_OK) && (certIdOfInvalidation != crlIssuerCertId))
    {
      boolean isRoot, isInChain;

      /* # ensure that CRL does not invalidate its issuer, but only certificates in the same chain of the CRL's issuer */
      isRoot = KeyM_Cert_IsCertRoot((KeyM_CertificateIdType)certIdOfInvalidation);
      isInChain = KeyM_Cert_IsCertInChainOfCA(certIdOfInvalidation, crlIssuerCertId);

      /* Get certificate status */
      localCertStatus = KeyM_Cert_GetStatusInfo(certIdOfInvalidation);

      if ( !isRoot && isInChain
        && ((localCertStatus == KEYM_CERTIFICATE_VALID) || (localCertStatus == KEYM_E_CERTIFICATE_REVOKED))
        && (KeyM_GetCertStartUpHandlingOfCertificate((KeyM_CertificateIterType)certIdOfInvalidation) != KEYM_PARSE_AND_TRUST))
      {
        /* # Invalidate certificate if status is valid or revoked */
        KeyM_Cert_SetStatusInfo(certIdOfInvalidation, KEYM_CERTIFICATE_PARSED_NOT_VALIDATED);
      }
    }
  }
  else
  {
    /* Get certificate status */
    localCertStatus = KeyM_Cert_GetStatusInfo(certIdOfInvalidation);

    if ((localCertStatus == KEYM_CERTIFICATE_VALID) && (KeyM_GetCertStartUpHandlingOfCertificate((KeyM_CertificateIterType)certIdOfInvalidation) != KEYM_PARSE_AND_TRUST))
    {
      /* # Invalidate certificate status if status is valid */
      KeyM_Cert_SetStatusInfo(certIdOfInvalidation, KEYM_CERTIFICATE_PARSED_NOT_VALIDATED);
    }
    retVal = E_OK;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SETCERT */
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ServiceCertUpdatePrepare()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertUpdatePrepare(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_CertificateIterType certIdx;
  boolean isCertIntermediate;
  boolean isCertLeaf;
  boolean isCRL;

  /* ----- Implementation ----------------------------------------------- */
  /* # Initialize iterator for further verification */
  KeyM_Cert_ClearLeafCertsToVerify();

  isCertIntermediate = KeyM_Cert_IsCertIntermediate(certId);
  isCertLeaf = KeyM_Cert_IsCertLeaf(certId);
  isCRL = KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CRL;

  /* Updating a leaf certificate has no effect on the rest of the certificates, therefore
     no certificate status needs to be updated and no further certificates need to be verified */
  if (!isCertLeaf || isCRL)
  {
    /* # Iterate through configured certificates */
    for (certIdx = 0u; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
    {
      if (!KeyM_Cert_IsCertInPKI((KeyM_CertificateIdType)certIdx, certId))
      {
        continue;
      }

      if (isCertIntermediate)
      {
        if (!KeyM_Cert_IsCertInChainOfCA((KeyM_CertificateIdType)certIdx, certId)) /* PRQA S 2991, 2995 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
        {
          continue;
        }
      }

      /* # Update certificate status */
      retVal = KeyM_Cert_ServiceCertUpdateStatus(certId, (KeyM_CertificateIdType)certIdx);

      if (retVal == E_OK)
      {
        /* # Store Ids of certificates in the lowest hierarchy */
        retVal = KeyM_Cert_ServiceCertUpdateCertId((KeyM_CertificateIdType)certIdx);
      }

      if (retVal == E_NOT_OK)
      {
        break;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SETCERT */
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ServiceCertUpdate()
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
/* PRQA S 6050, 6080 4 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertUpdate(
  KeyM_CertificateIdType CertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType localCertId = CertId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if certificate data length is invalid */
  if (RequestDataLength > KeyM_GetMaxLengthOfCertificate((KeyM_CertificateIterType)localCertId))
  {
    retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
  }
  /* # Check if certificate slot is empty */
  else if (KeyM_Cert_IsCertSlotEmpty(localCertId)
        && !(KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)localCertId) == KEYM_CRL)) /* AUTOSAR always expects CRLs to be set via service update */
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* # Check if KeyM is currently busy with other jobs */
    SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
    if (KeyM_Cert_TaskState == KEYM_CERT_TASKSTATE_IDLE)
    {
      KeyM_Cert_TaskState = KEYM_CERT_TASKSTATE_BUSY;
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

      /* # Prepare verification */
      retVal = KeyM_Cert_ServiceCertUpdatePrepare(localCertId);

      if (retVal == E_OK)
      {
        /* # Update certificate data */
        retVal = KeyM_Cert_ServiceCertUpdateData(localCertId, RequestData, RequestDataLength);

        if (retVal == E_OK) /* PRQA S 2991, 2995 */ /* MD_KEYM_2.2 */
        {
          /* # Trigger verification */
          retVal = KeyM_Cert_ServiceCertUpdateTriggerVerification(localCertId);
        }
      }
      if (retVal != E_OK)
      {
        KeyM_Cert_TaskState = KEYM_CERT_TASKSTATE_IDLE;
      }
    }
    else
    {
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
      retVal = KEYM_E_BUSY;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SETCERT */
#endif

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IdentifyInvalidChain()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_IdentifyInvalidChain(
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certUpperId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_CertificateIdType issuerCertId = 0u;
  KeyM_CertificateIterType certIdx;
  boolean isCertSlotEmpty;
  boolean isCertInChainToBeValidated;
  KeyM_CertificateIdType localCertId = *certId;
  KeyM_CertificateIdType localCertUpperId = *certUpperId;
# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
  boolean isVerificationExcluded = FALSE;
# endif

  /* ----- Implementation ----------------------------------------------- */
  KeyM_Cert_ClearVerifyChain();

  /* # Iterate through configured certificates in chain */
  for (certIdx = 0u; certIdx < KEYM_CERTIFICATE_CHAIN_MAX_DEPTH; certIdx++)
  {
    isCertInChainToBeValidated = FALSE;
    isCertSlotEmpty = KeyM_Cert_IsCertSlotEmpty(localCertId);

    if ((KeyM_Cert_GetStatusInfo(localCertUpperId) != (KEYM_CERTIFICATE_VALID))
    && ((!isCertSlotEmpty) || (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)localCertId) == KEYM_STORAGE_IN_ROM))
    && (localCertId != localCertUpperId))
    {
      isCertInChainToBeValidated = TRUE;

      /* # Store certId for later verification cycle */
      (void)KeyM_Cert_PushVerifyChainLink(localCertId);

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
      /* Check if optional issuer is available */
      if ((KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)localCertUpperId) == KEYM_DYNAMIC_OPTIONAL_ISSUER) && (!(KeyM_Cert_UpperHierarachicalRefInfo[localCertUpperId].isIssuerCertIdAvailable)))
      {
        localCertId = localCertUpperId;
        isVerificationExcluded = TRUE;
      }
      else
# endif
      {
        /* # Set upper certificates as new pair */
        retVal = KeyM_Cert_GetIssuerCertId(localCertUpperId, &issuerCertId);

        if (retVal == E_OK)
        {
          localCertId = localCertUpperId;
          localCertUpperId = issuerCertId;
        }
      }
    }

    if ((retVal != E_OK) || (!isCertInChainToBeValidated)
# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
      || (isVerificationExcluded)
# endif
      )
    {
      break;
    }
  }

  /* check that function only returns valid CertIds */
  /*@ assert localCertId < KeyM_GetSizeOfCertificate(); */
  /*@ assert localCertUpperId < KeyM_GetSizeOfCertificate(); */

  *certId = localCertId;
  *certUpperId = localCertUpperId;
  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_VERIFYCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ChainCpyToDataBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ChainCpyToDataBuffer(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 numberOfCertificates)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  uint8 certChainDataIdx;
  KeyM_CertificateIdType localCertId;

  /* ----- Implementation ----------------------------------------------- */
  localCertId = certId;

  certChainDataIdx = numberOfCertificates - 1u;
  /* # Iterate through certificate chain while storage type is permanent */
  while (((((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)localCertId)) & (KEYM_CERT_STORAGE_MASK_CSM)) == (KEYM_CERT_STORAGE_EMPTY))
  && (((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)localCertId)) & (KEYM_CERT_STORAGE_MASK_NVM)) == (KEYM_CERT_STORAGE_EMPTY))))
  {
    KeyM_CertDataType ramBuffer;
    ramBuffer = KeyM_Cert_GetCertificateWriteBufferData(localCertId);
    if (certChainData[certChainDataIdx].certDataLength <= ramBuffer.certDataLength)
    {
      /* Copy within exclusive area. Data might be being accessed by
      * - NVM copy callouts */
      SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();
      /* # Copy certificate data to associated certificate slots */
      VStdLib_MemCpyLarge(ramBuffer.certData, certChainData[certChainDataIdx].certData, certChainData[certChainDataIdx].certDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_MEMCPY_WRITEBUFFER */
      KeyM_Cert_SetCertificateWrittenLength(localCertId, (uint16)certChainData[certChainDataIdx].certDataLength);
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

      KeyM_Asn1_ClearCertificateElementStorage(certId);
      /* Set storage type */
      KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)(localCertId), (tKeyMCertStorageType)((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)localCertId)) | (KEYM_CERT_STORAGE_MASK_DATA_BUFFER | KEYM_CERT_STORAGE_MASK_DIRTY)));
      KeyM_Cert_SetStatusInfo(localCertId, KEYM_CERTIFICATE_NOT_PARSED);
      retVal = KeyM_Cert_GetIssuerCertId(localCertId, &localCertId);
    }
    else
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    if ((retVal == E_OK) && (certChainDataIdx > 0u))
    {
      certChainDataIdx--;
    }
    else
    {
      /* all temporary certificates copied or error occurred */
      break;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERT */

#ifndef KEYM_NOUNIT_STATEMACHINECONTROL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_TriggerStateAfterVerification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_TriggerStateAfterVerification(
  KeyM_CertificateIdType certId)
{
  /* ----- Implementation ----------------------------------------------- */
  if ((KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)certId) == KEYM_STORAGE_IN_ROM))
  {
    KeyM_Cert_State = KEYM_CERT_STATE_NOTIFY;
  }
  else
  {
    KeyM_Cert_State = KEYM_CERT_STATE_STORE;
  }

  return;
}
#endif /* ifndef KEYM_NOUNIT_STATEMACHINECONTROL */

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CheckIssuerValidity()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CheckIssuerValidity(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_CertificateIdType issuerCertId = 0u;
  KeyM_CertificateStatusType issuerCertStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;

  /* ----- Implementation ----------------------------------------------- */
  if (!KeyM_Cert_IsCertRoot(certId))
  {
    /* # Get issuer certificate identifier */
    retVal = KeyM_Cert_GetIssuerCertId(certId, &issuerCertId);

    if (retVal == E_OK)
    {
      /* # Get issuer certificate status */
      retVal = KeyM_Cert_CertGetStatus(issuerCertId, &issuerCertStatus);

      if ((retVal != E_OK) /* PRQA S 2996 */ /* MD_KEYM_2.2 */
        || (issuerCertStatus != KEYM_CERTIFICATE_VALID))
      {
        retVal = E_NOT_OK;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SETCERT */
#endif

#ifndef KEYM_NOUNIT_STATEMACHINECONTROL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_TriggerStateAfterCertElementVerification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_TriggerStateAfterCertElementVerification(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  tKeyMCertRequestType request;

  /* ----- Implementation ----------------------------------------------- */
  request = KeyM_GetCert_CertInfo((KeyM_Cert_CertInfoIterType)certId).request;

  if (((KeyM_Cert_StartUpState == KEYM_CERT_STARTUP_STATE_ACTIVE) && (KeyM_GetCertStartUpHandlingOfCertificate((KeyM_CertificateIterType)certId) == KEYM_PARSE_AND_VERIFY))
    || (request != KEYM_CERT_REQUEST_NOT_SET))
  {
    /* Continue with verification process */
    KeyM_Cert_State = KEYM_CERT_STATE_CHECK_SUBJECT;
  }
  else if ((KeyM_Cert_StartUpState == KEYM_CERT_STARTUP_STATE_ACTIVE)
# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
    /* Check if certificate identifier of upper hierarchical certificate of an certificate with dynamic optional issuer is available */
    || ((KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_DYNAMIC_OPTIONAL_ISSUER) && (!(KeyM_Cert_UpperHierarachicalRefInfo[certId].isIssuerCertIdAvailable)))
# endif
    )
  {
    /* Continue with notify state since verification not needed */
    KeyM_Cert_State = KEYM_CERT_STATE_NOTIFY;
  }
  else
  {
    /* Do nothing */
  }

  return;
}
#endif /* ifndef KEYM_NOUNIT_STATEMACHINECONTROL */

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_InvalidateChildCertStatus()
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
 */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_InvalidateChildCertStatus(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isCertLeaf;

  KeyM_CertificateIterType certIdx;
  KeyM_CertificateStatusType certStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if referenced certificate is a leaf certificate */
  isCertLeaf = KeyM_Cert_IsCertLeaf(certId);

  /* # Invalidate certificate status only for CA certificates */
  if (!isCertLeaf)
  {
    /* # Iterate through configured certificates */
    for (certIdx = 0u; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
    {
      /* # Invalidate status of certificates in lower hierarchies of referenced certificate */
      if (KeyM_Cert_IsCertInChainOfCA((KeyM_CertificateIdType)certIdx, certId)) /* PRQA S 2991, 2995 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
      {
        /* # Get certificate status */
        certStatus = KeyM_Cert_GetStatusInfo((KeyM_CertificateIdType)certIdx);

        if (certStatus == KEYM_CERTIFICATE_VALID)
        {
          /* # Invalidate certificate status if status is valid */
          KeyM_Cert_SetStatusInfo((KeyM_CertificateIdType)certIdx, KEYM_CERTIFICATE_PARSED_NOT_VALIDATED);
        }
      }
    }
  }
}
# endif /* ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING */
#endif

#ifndef KEYM_NOUNIT_STATEMACHINECONTROL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_TriggerState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030, 6050 1 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_TriggerState(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
# if (KEYM_CSM_SYNC_SIGNATURE_VERIFY == STD_ON)
  KeyM_CertificateIdType issuerCertId = 0u;
# endif
  tKeyMCertRequestType request;

  /* ----- Implementation ----------------------------------------------- */
  request = KeyM_GetCert_CertInfo((KeyM_Cert_CertInfoIterType)certId).request;

  /* Advance state */
  switch (KeyM_Cert_State)
  {
    case KEYM_CERT_STATE_INIT:
    {
      KeyM_Cert_State = KEYM_CERT_STATE_PARSE_CERT;
      break;
    }
    case KEYM_CERT_STATE_PARSE_CERT:
    {
      if ((request != KEYM_CERT_REQUEST_NOT_SET) || (KeyM_Cert_StartUpState == KEYM_CERT_STARTUP_STATE_ACTIVE))
      {
        KeyM_Cert_State = KEYM_CERT_STATE_VERIFY_CERT_ELEMENTS;
      }
      break;
    }
    case KEYM_CERT_STATE_VERIFY_CERT_ELEMENTS:
    {
      KeyM_Cert_TriggerStateAfterCertElementVerification(certId);
      break;
    }
    case KEYM_CERT_STATE_CHECK_SUBJECT:
    {
      KeyM_Cert_State = KEYM_CERT_STATE_CHECK_TIME_STAMP;
      break;
    }
    case KEYM_CERT_STATE_CHECK_TIME_STAMP:
    {
      /* Since the root certificate is self-signed, the own public key has to be set prior to the verification */
      if (KeyM_Cert_IsCertRoot(certId))
      {
        KeyM_Cert_State = KEYM_CERT_STATE_SET_KEY;
      }
      else
      {
        KeyM_Cert_State = KEYM_CERT_STATE_VERIFY_SIGNATURE;
      }
      break;
    }
    case KEYM_CERT_STATE_SET_KEY:
    {
      if (KeyM_Cert_IsCertRoot(certId))
      {
        KeyM_Cert_State = KEYM_CERT_STATE_VERIFY_SIGNATURE;
      }
# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
      /* Check if optional issuer is available */
      else if ((KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_DYNAMIC_OPTIONAL_ISSUER) && (!(KeyM_Cert_UpperHierarachicalRefInfo[certId].isIssuerCertIdAvailable)))
      {
        /* Verification is skipped */
        KeyM_Cert_State = KEYM_CERT_STATE_STORE;
      }
# endif
      else
      {
        KeyM_Cert_TriggerStateAfterVerification(certId);
      }

      break;
    }
# if (KEYM_CSM_SYNC_SIGNATURE_VERIFY == STD_ON)
    case KEYM_CERT_STATE_VERIFY_SIGNATURE_PENDING:
    {
      (void)KeyM_Cert_GetIssuerCertId(certId, &issuerCertId);

      if (!KeyM_IsKeyMCertCsmSignatureVerifyJobRefAsyncOfCertificate((KeyM_CertificateIterType)issuerCertId))
      {
        if (KeyM_GetCert_CertInfo((KeyM_Cert_CertInfoIterType)certId).verifyRes == CSM_E_VER_OK)
        {
          /* The public key of root certificates is set prior to the verification [SWS_KeyM_00126] */
          if ((KeyM_Cert_IsCertRoot(certId)))
          {
            KeyM_Cert_TriggerStateAfterVerification(certId);
          }
          else
          {
            KeyM_Cert_State = KEYM_CERT_STATE_SET_KEY;
          }
        }
        else
        {
          KeyM_Cert_SetStatusInfo(certId, KEYM_E_CERTIFICATE_SIGNATURE_FAIL);
          KeyM_Cert_State = KEYM_CERT_STATE_NOTIFY;
        }
      }

      break;
    }
# endif
    case KEYM_CERT_STATE_STORE:
    {
      KeyM_Cert_State = KEYM_CERT_STATE_NOTIFY;
      break;
    }
    default:
    {
      /* Do nothing */
      break;
    }
  }
}
#endif /* ifndef KEYM_NOUNIT_STATEMACHINECONTROL */

#ifndef KEYM_NOUNIT_STATEMACHINECONTROL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_HandleCsmResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_HandleCsmResult(
  KeyM_CertificateIdType certId,
  Std_ReturnType csmResult,
  tKeyMCertState prevState)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Evaluate result of CSM operation */
  switch (csmResult)
  {
    case E_OK:
    {
      /* Operation successful */
      KeyM_Cert_TriggerState(certId);

      break;
    }
    case CRYPTO_E_QUEUE_FULL:
    case CRYPTO_E_BUSY:
    {
      /* CSM busy, retry operation by restoring previous state */
      KeyM_Cert_State = prevState;

      break;
    }
    default:
    {
      /* Operation failed */
      KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certId)->csmRes = (Crypto_VerifyResultType)(csmResult);

      retVal = E_NOT_OK;

      break;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_STATEMACHINECONTROL */

#ifndef KEYM_NOUNIT_STATEMACHINECONTROL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateInit(KeyM_CertificateIdType certId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Set certificate status */
  KeyM_Cert_SetStatusInfo(certId, KEYM_CERTIFICATE_NOT_PARSED);

  /* Proceed with next state */
  KeyM_Cert_TriggerState(certId);
}
#endif /* ifndef KEYM_NOUNIT_STATEMACHINECONTROL */

#ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_Parse()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_Parse(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) cert,
  uint32 certLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  KeyM_Asn1_ParamType asn1Param;
  KeyM_Asn1_ParseType asn1Parse;
  KeyM_Asn1_ParamType asn1ParamDerived[KEYM_ASN1_PARSE_MAX_NESTING_LEVEL];

  KeyM_SizeOfCertificateElementType start, length;

  /* ----- Implementation ----------------------------------------------- */
  start = KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)certId);
  length = (KeyM_SizeOfCertificateElementType)KeyM_GetCertificateElementLengthOfCertificate((KeyM_CertificateIterType)certId);
  /*@ assert length <= KEYM_MAX_NUM_CERT_ELEMENTS; */ /* VCA_KEYM_CERT_INITCHECK04 */

  /* # Setup ASN reader */
  KeyM_Asn1_Init(&asn1Param, cert, (uint16)certLength);

  /* # Init the parser */
  KeyM_Asn1_ParseInit(&asn1Parse, asn1ParamDerived, KEYM_ASN1_PARSE_MAX_NESTING_LEVEL); /* VCA_KEYM_CERT_PARSE_INIT */

  /* # Parse the certificate */
  /*@ assert ((certId < KeyM_GetSizeOfCertificate()) && (start < KeyM_GetSizeOfCertificateElement()) && (length <= KEYM_MAX_NUM_CERT_ELEMENTS)); */
  retVal = KeyM_Asn1_ParseData(certId, &asn1Parse, &asn1Param, start, length); /* VCA_KEYM_CERT_PARSE */

  KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certId)->sigProcessDataPtr = asn1Parse.asn1_baseAddress;
  KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certId)->sigProcessDataLength = (uint32)(asn1Parse.asn1_baseLength);

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SETCERT */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_SearchElementByStructureType()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_SearchElementByStructureType(
  KeyM_CertificateIdType certIdx,
  KeyM_OfStructureOfCertificateElementType elementStructureType,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdxPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;
  KeyM_CertificateElementIterType i;
  KeyM_SizeOfCertificateElementType elementIdxLocal = 0u;

  /* ----- Implementation ----------------------------------------------- */

  /* # Iterate through configured certificate elements */
  for (i = KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)certIdx); i < KeyM_GetCertificateElementEndIdxOfCertificate((KeyM_CertificateIterType)certIdx); i++)
  {
    /*@ assert i < KeyM_GetSizeOfCertificateElement(); */
    /* # Return element identifier if element structure matches */
    if (KeyM_GetOfStructureOfCertificateElement(i) == elementStructureType)
    {
      elementIdxLocal = (KeyM_SizeOfCertificateElementType)i;

      if (KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdxLocal)).length > 0u)
      {
        retVal = TRUE;
        break;
      }
    }
  }

  /* ensure that function always returns a valid element idx */
  /*@ assert elementIdxLocal < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_CERT_SEARCHELEMENTBYSTRUCTURETYPE */
  *elementIdxPtr = elementIdxLocal;
  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#if ((KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_CRE_APPL */
# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertElementFound()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertElementFound(
  KeyM_CertificateIdType certIdx,
  KeyM_OfStructureOfCertificateElementType elementStructureType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) oidData,
  uint32 oidDataLength,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdxPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;
  KeyM_CertificateElementIterType i;
  KeyM_SizeOfCertificateElementType elementIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through configured certificates */
  for (i = KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)certIdx); i < KeyM_GetCertificateElementEndIdxOfCertificate((KeyM_CertificateIterType)certIdx); i++)
  {
    /*@ assert i < KeyM_GetSizeOfCertificateElement(); */
    if ((KeyM_GetOfStructureOfCertificateElement(i) == elementStructureType) && KeyM_IsElementOidUsedOfCertificateElement(i))
    {
      KeyM_ElementOidStartIdxOfCertificateElementType oidStartIdx = KeyM_GetElementOidStartIdxOfCertificateElement(i);
      /*@ assert oidStartIdx < KeyM_GetSizeOfElementOid(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

      /* # Compare oid */
      if (
        KeyM_Utils_BufferCmp(
          KeyM_GetAddrElementOid(oidStartIdx),
          KeyM_GetElementOidLengthOfCertificateElement(i),
          oidData,
          oidDataLength))
      {
        elementIdx = (KeyM_SizeOfCertificateElementType)i;
        retVal = TRUE;
        break;
      }
    }
  }

  *elementIdxPtr = elementIdx;
  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */
#endif

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetSignatureElement_X509_ECDSA()
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
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetSignatureElement_X509_ECDSA(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) dataPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) dataLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_ParamType asn1Param;
  uint16 firstElementOffset = 0u; /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  uint16 firstElementLength = 0u; /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  uint16 secondElementOffset = 0u; /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  uint16 secondElementLength = 0u; /* PRQA S 2981 */ /* MD_KEYM_2.2 */

  /* ----- Implementation ----------------------------------------------- */
  /* # Setup ASN reader */
  KeyM_Asn1_Init(&asn1Param, KeyM_Cert_GetCertElementDataPointer(certId, elementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length);

  /* # Parse first element */
  retVal = KeyM_Cert_GetTL(&asn1Param);

  if (retVal == E_OK)
  {
    if (KeyM_Cert_GetCertElementDataPointer(certId, elementIdx)[(uint16)asn1Param.current_pos] == 0x00u)
    {
      firstElementOffset = (uint16)asn1Param.current_pos + 1u;
      firstElementLength = (uint16)asn1Param.last_tag_len - 1u;
    }
    else
    {
      firstElementOffset = (uint16)asn1Param.current_pos;
      firstElementLength = (uint16)asn1Param.last_tag_len;
    }

    /* # Iterate to next tag */
    KeyM_Asn1_NextTag(&asn1Param);

    /* # Parse second element */
    retVal = KeyM_Cert_GetTL(&asn1Param);

    if (retVal == E_OK)
    {
      if (KeyM_Cert_GetCertElementDataPointer(certId, elementIdx)[(uint16)asn1Param.current_pos] == 0x00u)
      {
        secondElementOffset = firstElementOffset + firstElementLength + (uint16)(asn1Param.last_tag_data_pos - asn1Param.last_tag_base_pos) + 1u;
        secondElementLength = (uint16)asn1Param.last_tag_len - 1u;
      }
      else
      {
        secondElementOffset = firstElementOffset + firstElementLength + (uint16)(asn1Param.last_tag_data_pos - asn1Param.last_tag_base_pos);
        secondElementLength = (uint16)asn1Param.last_tag_len;
      }

      retVal = KeyM_Cert_FormatECDSASignature(
        &KeyM_Cert_GetCertElementDataPointer(certId, elementIdx)[firstElementOffset],
        firstElementLength,
        &KeyM_Cert_GetCertElementDataPointer(certId, elementIdx)[secondElementOffset],
        secondElementLength,
        dataPtr,
        dataLengthPtr);
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_FormatECDSASignature()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6060 7 */ /* MD_KEYM_6060_LOCAL */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_FormatECDSASignature(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) r,
  uint32 rLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) s,
  uint32 sLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) outputBuffer,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) outputBufferLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 rPadLength = 0u;
  uint32 rModLength;
  uint32 sPadLength = 0u;
  uint32 sModLength;
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Determine need for padding */
  rModLength = rLength % 8u;
  sModLength = sLength % 8u;

  if (rModLength != 0u)
  {
    rPadLength = 8u - rModLength;
  }

  if (sModLength != 0u)
  {
    sPadLength = 8u - sModLength;
  }

  /* check if padded coordinates will fit into output buffer */
  if (*outputBufferLen < (rPadLength + rLength + sPadLength + sLength)) /* PRQA S 2985 */ /* MD_KEYM_2.2 */
  {
    retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
  }
  else
  {
    uint32 currentOffset = 0u;
    retVal = E_OK;

    /* # Write padded coordinates to output buffer */

    /* Write padding for R (if any) */
    VStdMemClr(&outputBuffer[currentOffset], rPadLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    currentOffset += rPadLength; /* PRQA S 2986 */ /* MD_KEYM_2.2 */
    /* Write R */
    VStdMemCpy(&outputBuffer[currentOffset], r, rLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    currentOffset += rLength;
    /* Write padding for S (if any) */
    VStdMemClr(&outputBuffer[currentOffset], sPadLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    currentOffset += sPadLength; /* PRQA S 2985 */ /* MD_KEYM_2.2 */
    /* Write S */
    VStdMemCpy(&outputBuffer[currentOffset], s, sLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    currentOffset += sLength;

    /* set length of output buffer to number of written bytes */
    *outputBufferLen = currentOffset;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetElementByStructureType()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetElementByStructureType(
  KeyM_CertificateIdType certId,
  KeyM_OfStructureOfCertificateElementType elementStructureType,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) dataPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) dataLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_SizeOfCertificateElementType elementIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Search element by structure type in configuration */
  if (KeyM_Cert_SearchElementByStructureType(certId, elementStructureType, &elementIdx))
  {
    /* # Copy element data */
    if (((KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_X509) || (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CRL)) && (KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_ECDSA) && (KeyM_GetOfStructureOfCertificateElement(elementIdx) == KEYM_CERTIFICATE_SIGNATURE))
    {
      retVal = KeyM_Cert_GetSignatureElement_X509_ECDSA(certId, elementIdx, dataPtr, dataLengthPtr);
    }
    else
    {
      uint16 elementLength = KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length;

      if (*dataLengthPtr >= elementLength)
      {
        VStdLib_MemCpyLarge(dataPtr, KeyM_Cert_GetCertElementDataPointer(certId, elementIdx), elementLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_GETELEMENTBYSTRUCTURETYPE_MEMCPY */
        *dataLengthPtr = elementLength;
        retVal = E_OK;
      }
      else
      {
        retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetElementByStructureTypeAndOid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6060 7 */ /* MD_KEYM_6060_LOCAL */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetElementByStructureTypeAndOid(
  KeyM_CertificateIdType certId,
  KeyM_OfStructureOfCertificateElementType elementStructureType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) oidData,
  uint32 oidDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) dataPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) dataLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_SizeOfCertificateElementType elementIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Search element by structure type and oid in configuration */
  if (KeyM_Cert_IsCertElementFound(certId, elementStructureType, oidData, oidDataLength, &elementIdx))
  {
    /* # Check if element is available */
    if (KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length > 0u)
    {
      /* # Copy element data */
      if (*dataLengthPtr >= KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length)
      {
        VStdLib_MemCpyLarge(dataPtr, KeyM_Cert_GetCertElementDataPointer(certId, elementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
        *dataLengthPtr = KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length;
        retVal = E_OK;
      }
      else
      {
        retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */
#endif

#ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateParseCert()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateParseCert(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_ConstCertDataType certData;
  certData = KeyM_Cert_GetCertificateReadBufferData(certId);

  /* ----- Implementation ----------------------------------------------- */
  /* # Initialize parse data */
  KeyM_Cert_PubKeyLength = KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH;
  KeyM_Cert_SigLength = KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH;

  /* # Parse certificate */
  retVal = KeyM_Cert_Parse(certId, certData.certData, certData.certDataLength);

  if (retVal == E_OK)
  {
    /* # Copy public key in associated buffer */
    if (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) != KEYM_CRL)
    {
      retVal = KeyM_Cert_GetElementByStructureType(certId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY, KeyM_Cert_PubKeyBuffer, &KeyM_Cert_PubKeyLength);
    }

    if (retVal == E_OK)
    {
      /* # Copy signature in associated buffer */
      retVal = KeyM_Cert_GetElementByStructureType(certId, KEYM_CERTIFICATE_SIGNATURE, KeyM_Cert_SigBuffer, &KeyM_Cert_SigLength);

      if (retVal == E_OK)
      {
        /* Set storage type */
        KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)(certId), (tKeyMCertStorageType)((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)certId)) | (KEYM_CERT_STORAGE_MASK_PARSE_BUFFER)));

        /* Proceed with next state */
        KeyM_Cert_TriggerState(certId);
      }
    }
  }

  if (retVal != E_OK)
  {
    KeyM_Cert_SetStatusInfo(certId, KEYM_CERTIFICATE_INVALID);
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SETCERT */

#ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateVerifyCertElements()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6050 1 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateVerifyCertElements(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

# if (KEYM_CERTIFICATEELEMENTVERIFICATIONCALLOUT == STD_ON)
  KeyM_CertificateElementIterType elementIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through configured elements */
  for (elementIdx = KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)certId); elementIdx < KeyM_GetCertificateElementEndIdxOfCertificate((KeyM_CertificateIterType)certId); elementIdx++)
  {
    /* # Check for configured verification callout */
    if (KeyM_IsCertificateElementVerificationCalloutUsedOfCertificateElement(elementIdx))
    {
      KeyM_CertificateElementVerificationCalloutIdxOfCertificateElementType calloutIdx;
      KeyM_CertificateElementVerificationCalloutFctPtrType calloutFunction;

      calloutIdx = KeyM_GetCertificateElementVerificationCalloutIdxOfCertificateElement(elementIdx);
      /*@ assert calloutIdx < KeyM_GetSizeOfCertificateElementVerificationCallout(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

      calloutFunction = KeyM_GetCertificateElementVerificationCallout(calloutIdx);

#  ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
      /* VCA does not analyze customer-provided callbacks. The API contract for customer-provided callbacks is
       * annotated in the VCA stub. So no problems can arise with customer-provided callbacks if they uphold the
       * API contract. */
      calloutFunction = &Vcastub_Appl_CertificateElementVerificationCallout;
#  endif

      if (calloutFunction(certId, KeyM_GetIdOfCertificateElement(elementIdx), KeyM_Cert_GetCertElementDataPointer(certId, (KeyM_SizeOfCertificateElementType)elementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length) != E_OK)
      {
        /* Element verification failed */
        retVal = E_NOT_OK;
        if ((KeyM_GetOfStructureOfCertificateElement(elementIdx) == KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE)
            || (KeyM_GetOfStructureOfCertificateElement(elementIdx) == KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER))
        {
          KeyM_Cert_SetStatusInfo(certId, KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL);
        }
        else
        {
          KeyM_Cert_SetStatusInfo(certId, KEYM_E_CERTIFICATE_INVALID_CONTENT);
        }
      }
    }
  }

  if (retVal == E_OK)
# endif
  {
    /* # Set certificate status */
    KeyM_Cert_SetStatusInfo(certId, KEYM_CERTIFICATE_PARSED_NOT_VALIDATED);

    /* Proceed with next state */
    KeyM_Cert_TriggerState(certId);
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SETCERT */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateCheckSubjectCommonNameCmp()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateCheckSubjectCommonNameCmp(
  KeyM_CertificateIdType certId,
  KeyM_CertificateIdType issuerCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_SizeOfCertificateElementType elementSubjectNameIdx = 0u;
  KeyM_SizeOfCertificateElementType elementIssuerNameIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get subject field of certificate in the upper hierarchy */
  if (KeyM_Cert_SearchElementByStructureType(issuerCertId, KEYM_CERTIFICATE_SUBJECT_NAME, &elementSubjectNameIdx))
  {
    /* # Get issuer field of certificate in the lower hierarchy */
    if (KeyM_Cert_SearchElementByStructureType(certId, KEYM_CERTIFICATE_ISSUER_NAME, &elementIssuerNameIdx))
    {
      /* # Compare common name */
      if (KeyM_Utils_BufferCmp(KeyM_Cert_GetCertElementDataPointer(issuerCertId, elementSubjectNameIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementSubjectNameIdx)).length, KeyM_Cert_GetCertElementDataPointer(certId, elementIssuerNameIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIssuerNameIdx)).length))
      {
        retVal = E_OK;
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateCheckSubject()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateCheckSubject(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType issuerCertId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get subject field of certificate in the upper hierarchy */
  retVal = KeyM_Cert_GetIssuerCertId(certId, &issuerCertId);

  if (retVal == E_OK)
  {
    /* # Compare issuer common name with subject common name of certificate in upper hierarchy */
    retVal = KeyM_Cert_StateCheckSubjectCommonNameCmp(certId, issuerCertId);
  }

  if (retVal == E_OK)
  {
    /* Proceed with next state */
    KeyM_Cert_TriggerState(certId);
  }
  else
  {
    /* Invalid chain of trust */
    KeyM_Cert_SetStatusInfo(certId, KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST);
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ParseUTCGeneralizedTime()
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
 */
/* PRQA S 6030 4 */ /* MD_MSR_STCYC */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseUTCGeneralizedTime(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) timeElementPtr,
  uint16 timeElementDataLength,
  P2VAR(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) parsedTimePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) timeElement = timeElementPtr;

  /* ----- Implementation ----------------------------------------------- */
  /* Generally:
  * UTC Formats:
  *    YYMMDDhhmm[ss]Z
  *    YYMMDDhhmm[ss](+|-)hhmm
  *  Generalized Time Formats:
  *    YYYYMMDDHH[MM[SS[.fff]]]
  *    YYYYMMDDHH[MM[SS[.fff]]]Z
  *    YYYYMMDDHH[MM[SS[.fff]]](+|-)HHMM
  */

  /* # Only UTC or Generalized Time with non-optional minutes and seconds are supported,
  *  milliseconds [.fff] and difference to local time (+|-)HHMM is not supported. */

  /* # Check that last sign is a 'Z' 0x5A. */
  if (timeElement[timeElementDataLength - 1u] != 0x5Au)
  {
    retVal = E_NOT_OK;
  }

  if (retVal == E_OK)
  {
    /* # If the element data length is 13, extract the year according to the UTC format. */
    if (timeElementDataLength == 13u)
    {
      /* UTC time with 2 digits Year */
      parsedTimePtr->year = ((uint16)timeElement[0] - 0x30u) * 10u;
      parsedTimePtr->year += (uint16)timeElement[1u] - 0x30u;

      if (parsedTimePtr->year >= 50u)
      {
        parsedTimePtr->year += 1900u;
      }
      else
      {
        parsedTimePtr->year += 2000u;
      }
      timeElement = &(timeElement[2u]);
    }
    /* # If the element data length is 15, extract the year according to the Generalized Time format. */
    else if (timeElementDataLength == 15u)
    {
      /* Generalized time with 4 digits Year */
      parsedTimePtr->year = (((uint16)timeElement[0u] - 0x30u) * 1000u);
      parsedTimePtr->year += ((((uint16)timeElement[1u] - 0x30u) * 100u));
      parsedTimePtr->year += ((((uint16)timeElement[2u] - 0x30u) * 10u));
      parsedTimePtr->year += (((uint16)timeElement[3u] - 0x30u));
      timeElement = &(timeElement[4u]);
    }
    else
    {
      /* invalid time format */
      retVal = E_NOT_OK;
    }
  }

  if (retVal == E_OK)
  {
    /* # Extract the remaining date and time information without differentiating between UTC and
    * Generalized Time format. */
    parsedTimePtr->month = (uint8)((timeElement[0u] - 0x30u) * 10u);
    parsedTimePtr->month += ((uint8)(timeElement[1u] - 0x30u));
    parsedTimePtr->day = (uint8)((timeElement[2u] - 0x30u) * 10u);
    parsedTimePtr->day += ((uint8)(timeElement[3u] - 0x30u));
    parsedTimePtr->hour = (uint8)((timeElement[4u] - 0x30u) * 10u);
    parsedTimePtr->hour += ((uint8)(timeElement[5u] - 0x30u));
    parsedTimePtr->minute = (uint8)((timeElement[6u] - 0x30u) * 10u);
    parsedTimePtr->minute += ((uint8)(timeElement[7u] - 0x30u));
    parsedTimePtr->second = (uint8)((timeElement[8u] - 0x30u) * 10u);
    parsedTimePtr->second += ((uint8)(timeElement[9u] - 0x30u));
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ParseTime()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6030 4 */ /* MD_MSR_STCYC */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseTime(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) parsedTimePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) timeElementPtr = KeyM_Cert_GetCertElementDataPointer(certId, elementIdx);
  uint16 timeElementDataLength = KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length;

  /* ----- Implementation ----------------------------------------------- */
  if ((KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_X509) || (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CRL))
  {
    /* # For certificates and CRLs according to X.509, use to KeyM_Cert_ParseUTCGeneralizedTime to parse time element */
    retVal = KeyM_Cert_ParseUTCGeneralizedTime(timeElementPtr, timeElementDataLength, parsedTimePtr);
  }
  /* Handle format type KEYM_CVC */
  else
  {
    /* # For CVC certificates, parse CVC-specific time format */

    /* # Check that time element has length KEYM_ASN1_GENERALIZEDTIME_UTC_MAX_LENGTH */
    if (timeElementDataLength != KEYM_ASN1_GENERALIZEDTIME_UTC_MAX_LENGTH)
    {
      retVal = E_NOT_OK;
    }

    if (retVal == E_OK)
    {
      /* # Parse CVC-specific time format */
      parsedTimePtr->year = (uint16)(timeElementPtr[0u]) * 10u;
      parsedTimePtr->year += timeElementPtr[1u];

      if (parsedTimePtr->year >= 50u)
      {
        parsedTimePtr->year += 1900u;
      }
      else
      {
        parsedTimePtr->year += 2000u;
      }

      parsedTimePtr->month = (uint8)(timeElementPtr[2u] * 10u);
      parsedTimePtr->month += timeElementPtr[3u];
      parsedTimePtr->day = (uint8)(timeElementPtr[4u] * 10u);
      parsedTimePtr->day += timeElementPtr[5u];
      parsedTimePtr->hour = 0u;
      parsedTimePtr->minute = 0u;
      parsedTimePtr->second = 0u;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ConvertDateToUnixTime()
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
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ConvertDateToUnixTime(
  P2CONST(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) date,
  P2VAR(uint64, AUTOMATIC, AUTOMATIC) unixTime)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  uint64 y;
  uint64 m;
  uint64 d;

  /* ----- Implementation ----------------------------------------------- */
  /* Year */
  y = date->year;
  /* Month of year */
  m = date->month;
  /* Day of month */
  d = date->day;

  /* January and February are counted as months 13 and 14 of the previous year */
  if (m <= 2u)
  {
    m += 12u;
    y -= 1u;
  }

  /* # Convert years to days */
  /* A leap year must be evenly divisible by 4. If the year can also be evenly divided by 100, it is not a leap year, unless
     the year is also evenly divisible by 400. */
  *unixTime = ((365u * y) + (y / 4u) - (y / 100u) + (y / 400u));

  /* # Convert months to days */
  /* This formula takes into account the uneven number of days in the months across a year */
  *unixTime += ((30u * m) + (3u * (m + 1u) / 5u) + d);

  /* # Unix time starts on January 1st, 1970 */
  if (*unixTime < 719561u)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    *unixTime -= 719561u;
    /* # Convert days to seconds */
    *unixTime *= 86400u;
    /* # Add hours, minutes and seconds */
    *unixTime += ((3600u * (uint64)(date->hour)) + (60u * (uint64)(date->minute)) + (uint64)(date->second));
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CheckValidityPeriod()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CheckValidityPeriod(
  uint64 certTime,
  P2CONST(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) notBeforeTime,
  P2CONST(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) notAfterTime)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint64 notBeforeUnixTime = 0u;
  uint64 notAfterUnixTime = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Convert notBefore standard time to unix time */
  retVal = KeyM_Cert_ConvertDateToUnixTime(notBeforeTime, &notBeforeUnixTime);

  if (retVal == E_OK)
  {
    /* # Convert notAfter standard time to unix time */
    retVal = KeyM_Cert_ConvertDateToUnixTime(notAfterTime, &notAfterUnixTime);

    if (retVal == E_OK)
    {
      retVal = E_NOT_OK;

      /* # Check validity period */
      if ((certTime >= notBeforeUnixTime) && (certTime <= notAfterUnixTime))
      {
        retVal = E_OK;
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ParseValidityPeriod()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseValidityPeriod(
  KeyM_CertificateIdType certId,
  P2VAR(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) notBeforeTime,
  P2VAR(tKeyMCertDateTimeType, AUTOMATIC, AUTOMATIC) notAfterTime)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_SizeOfCertificateElementType elementNotBeforeIdx = 0u;
  KeyM_SizeOfCertificateElementType elementNotAfterIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  if (KeyM_Cert_SearchElementByStructureType(certId, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE, &elementNotBeforeIdx))
  {
    /* # Parse notBefore Time */
    retVal = KeyM_Cert_ParseTime(certId, elementNotBeforeIdx, notBeforeTime);

    if (retVal == E_OK)
    {
      if (KeyM_Cert_SearchElementByStructureType(certId, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER, &elementNotAfterIdx))
      {
        /* # Parse notAfter Time */
        retVal = KeyM_Cert_ParseTime(certId, elementNotAfterIdx, notAfterTime);
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetCurrentTime()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3673 4 */ /* MD_KEYM_8.13_DeactivateableFeature */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCurrentTime(
  KeyM_CertificateIdType certId,
  P2VAR(uint64, AUTOMATIC, AUTOMATIC) certTime,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) isPeriodValidityUsed)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_KEYM_2.2 */

# if (KEYM_CERTTIMEBASEREFOFCERTIFICATE == STD_ON)
  StbM_TimeStampType timeStamp;
  StbM_UserDataType userData;
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* # Get unix timestamp for referenced certificate */
# if (KEYM_CERTIFICATEGETCURRENTTIMECALLOUT == STD_ON)
  if (KeyM_IsCertificateGetCurrentTimeCalloutUsedOfCertificate((KeyM_CertificateIterType)certId))
  {
    KeyM_CertificateGetCurrentTimeCalloutIdxOfCertificateType calloutIdx;
    KeyM_CertificateGetCurrentTimeCalloutFctPtrType calloutFunction;

    calloutIdx = KeyM_GetCertificateGetCurrentTimeCalloutIdxOfCertificate((KeyM_CertificateIterType)certId);
    /*@ assert calloutIdx < KeyM_GetSizeOfCertificateGetCurrentTimeCallout(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

    calloutFunction = KeyM_GetCertificateGetCurrentTimeCallout(calloutIdx);

#  ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
    /* VCA does not analyze customer-provided callbacks. The API contract for customer-provided callbacks is
     * annotated in the VCA stub. So no problems can arise with customer-provided callbacks if they uphold the
     * API contract. */
    calloutFunction = &Vcastub_Appl_CertificateGetCurrentTimeCallout;
#  endif

    retVal = calloutFunction(certId, certTime);
    if (retVal == KEYM_E_NO_PERIOD_VALIDITY_CHECK)
    {
      *isPeriodValidityUsed = FALSE;
      retVal = E_OK;
    }
  }
  else
# else
    KEYM_DUMMY_STATEMENT(certId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(certTime); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(isPeriodValidityUsed); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  {
# if (KEYM_CERTTIMEBASEREFOFCERTIFICATE == STD_ON)
    retVal = StbM_GetCurrentTime((StbM_SynchronizedTimeBaseType)KeyM_GetCertTimebaseRefOfCertificate((KeyM_CertificateIterType)certId), &timeStamp, &userData);
    *certTime = ((uint64)(timeStamp.secondsHi) << 32u) | timeStamp.seconds;
# else
    KEYM_DUMMY_STATEMENT(certId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(certTime); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateCheckTimeStamp()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateCheckTimeStamp(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  tKeyMCertDateTimeType notBeforeTime = { 0u }; /* PRQA S 2983 */ /* MD_KEYM_2.2 */
  tKeyMCertDateTimeType notAfterTime = { 0u }; /* PRQA S 2983 */ /* MD_KEYM_2.2 */
  boolean isPeriodValidityUsed = TRUE;
  uint64 certTime;

  /* ----- Implementation ----------------------------------------------- */
  /* # Get unix timestamp for referenced certificate */
  retVal = KeyM_Cert_GetCurrentTime(certId, &certTime, &isPeriodValidityUsed);

  if ((retVal == E_OK)
# if (KEYM_CERTIFICATEGETCURRENTTIMECALLOUT == STD_ON)
  && (isPeriodValidityUsed)
# endif
  )
  {
    retVal = KeyM_Cert_ParseValidityPeriod(certId, &notBeforeTime, &notAfterTime);

    if (retVal == E_OK)
    {
      /* # Check validity period */
      retVal = KeyM_Cert_CheckValidityPeriod(certTime, &notBeforeTime, &notAfterTime);
    }
  }

  if (retVal == E_OK) /* PRQA S 2992, 2996 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
  {
    /* Proceed with next state */
    KeyM_Cert_TriggerState(certId);
  }
  else
  {
    /* Invalid time period */
    KeyM_Cert_SetStatusInfo(certId, KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL);
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetPubKeyElementsRSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetPubKeyElementsRSA(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(KeyM_CertPubKeyType, AUTOMATIC, AUTOMATIC) pubKey)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  KeyM_Asn1_ParamType asn1Param;

  /* ----- Implementation ----------------------------------------------- */
  /* # Setup ASN reader */
  KeyM_Asn1_Init(&asn1Param, KeyM_Cert_GetCertElementDataPointer(certId, elementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length);

  /* # Parse first element */
  retVal = KeyM_Cert_GetTL(&asn1Param);

  if (retVal == E_OK)
  {
    if (KeyM_Cert_GetCertElementDataPointer(certId, elementIdx)[(uint16)asn1Param.current_pos] == 0x00u)
    {
      /* modulus */
      pubKey->firstElementOffset = (uint16)asn1Param.last_tag_data_pos + 1u;
      pubKey->firstElementLength = (uint16)asn1Param.last_tag_len - 1u;
    }
    else
    {
      /* modulus */
      pubKey->firstElementOffset = (uint16)asn1Param.last_tag_data_pos;
      pubKey->firstElementLength = (uint16)asn1Param.last_tag_len;
    }
    /* # Iterate to next tag */
    KeyM_Asn1_NextTag(&asn1Param);

    /* # Parse second element */
    retVal = KeyM_Cert_GetTL(&asn1Param);

    if (retVal == E_OK)
    {
      /* exponent */
      pubKey->secondElementOffset = (uint16)asn1Param.last_tag_data_pos;
      pubKey->secondElementLength = (uint16)asn1Param.last_tag_len;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetPubKeyElementsECC()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetPubKeyElementsECC(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(KeyM_CertPubKeyType, AUTOMATIC, AUTOMATIC) pubKey)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  KeyM_Asn1_ParamType asn1Param;
  uint8_least i;

  /* ----- Implementation ----------------------------------------------- */
  /* # Setup ASN reader */
  KeyM_Asn1_Init(&asn1Param, KeyM_Cert_GetCertElementDataPointer(certId, elementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length);

  for (i = 0; i < KEYM_CERT_PUBLIC_POINT_TAG_VALUE_CVC; i++)
  {
    /* # Parse first and second element */
    retVal = KeyM_Cert_GetTL(&asn1Param);

    if (retVal == E_OK)
    {
      retVal = E_NOT_OK;
      if ((asn1Param.last_tag & KEYM_ASN1_TAG_NUMBER_MASK) == KEYM_CERT_PUBLIC_POINT_TAG_VALUE_CVC)
      {

        /* x-coordinate */
        pubKey->firstElementOffset = (uint16)asn1Param.last_tag_data_pos + KEYM_CERT_PUBLIC_POINT_FORMAT_LENGTH_CVC;
        pubKey->firstElementLength = ((uint16)asn1Param.last_tag_len - KEYM_CERT_PUBLIC_POINT_FORMAT_LENGTH_CVC) / 2u;

        /* y-coordinate */
        pubKey->secondElementOffset = (uint16)asn1Param.last_tag_data_pos + KEYM_CERT_PUBLIC_POINT_FORMAT_LENGTH_CVC + pubKey->firstElementLength;
        pubKey->secondElementLength = ((uint16)asn1Param.last_tag_len - KEYM_CERT_PUBLIC_POINT_FORMAT_LENGTH_CVC) / 2u;

        retVal = E_OK;
        break;
      }
      KeyM_Asn1_NextTag(&asn1Param);
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetPubKeyElements()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetPubKeyElements(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(KeyM_CertPubKeyType, AUTOMATIC, AUTOMATIC) pubKey)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_KEYM_2.2 */

  /* ----- Implementation ----------------------------------------------- */
  /* Check if element is available */
  if (KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length > 0u)
  {
    /* # Retrieve public key elements according to algorithm type */
    if (KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_RSA)
    {
      retVal = KeyM_Cert_GetPubKeyElementsRSA(certId, elementIdx, pubKey);
    }
    else
    {
      retVal = KeyM_Cert_GetPubKeyElementsECC(certId, elementIdx, pubKey);
    }
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_BigToLittleEndian()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_BigToLittleEndian(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) dstPtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) srcPtr,
  uint16 length)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 hi;
  uint16 lo;
  /* ----- Implementation ----------------------------------------------- */
  /* # Encode y-coordinate as a little-endian string of 32 octets */
  hi = length - 1u;

  for (lo = 0; hi > lo; lo++)
  {
    uint8 tmp = srcPtr[lo];
    dstPtr[lo] = srcPtr[hi];
    dstPtr[hi] = tmp;
    hi--;
  }
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ConvertPublicPoint_ECDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ConvertPublicPoint_ECDSA(
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) coordinateDataPtr,
  uint16 coordinateDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint32 pubKeyLength = (uint32)coordinateDataLength * 2u;

  /* ----- Implementation ----------------------------------------------- */
  if (pubKeyLength > KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* # Copy public point consisting of x- and y-coordinate to parse buffer */
    VStdLib_MemCpyLarge(KeyM_Cert_PubKeyBuffer, coordinateDataPtr, pubKeyLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    KeyM_Cert_PubKeyLength = pubKeyLength;
    retVal = E_OK;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ConvertPublicPoint_EdDSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ConvertPublicPoint_EdDSA(
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) xCoordinateDataPtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) yCoordinateDataPtr,
  uint16 coordinateDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 elementLength;
  uint8 y[KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH];

  /* ----- Implementation ----------------------------------------------- */
  elementLength = (uint8)coordinateDataLength;
  /* # Encode y-coordinate as a little-endian string of 32 octets */
  KeyM_Cert_BigToLittleEndian(y, yCoordinateDataPtr, elementLength);
  /* # Check most significant bit of the final octet */
  if ((y[elementLength - 1u] & 0x80u) == 0x00u)
  {
    retVal = E_OK;
    /* # Copy the least significant bit of the x-coordinate to the most significant bit of the final octet */
    y[elementLength - 1u] |= (xCoordinateDataPtr[elementLength - 1u] & 0x01u) << 7u;
    /* # Copy converted data to public key buffer */
    VStdLib_MemCpyLarge(KeyM_Cert_PubKeyBuffer, y, elementLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    KeyM_Cert_PubKeyLength = elementLength;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateSetKeyX509ECC()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateSetKeyX509ECC(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;

  /* ----- Implementation ----------------------------------------------- */
  /* # Set CSM key element */
  if (KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_ECDSA)
  {
    /* Skip leading octet and format octet in parsed element */
    csmResult = Csm_KeyElementSet(KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)certId), CRYPTO_KE_SIGNATURE_KEY, &KeyM_Cert_PubKeyBuffer[2u], KeyM_Cert_PubKeyLength - 2u);
  }
  else
  {
    /* Skip leading octet in parsed element */
    csmResult = Csm_KeyElementSet(KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)certId), CRYPTO_KE_SIGNATURE_KEY, &KeyM_Cert_PubKeyBuffer[1u], KeyM_Cert_PubKeyLength - 1u);
  }

  /* # Set CSM key status */
  csmResult |= Csm_KeySetValid(KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)certId));

  retVal = KeyM_Cert_HandleCsmResult(certId, csmResult, KEYM_CERT_STATE_SET_KEY);

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateSetKeyCVCECC()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 2 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateSetKeyCVCECC(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_SizeOfCertificateElementType elementIdx = 0u;

  Std_ReturnType csmResult;
  KeyM_CertPubKeyType pubKey = { 0u };

  /* ----- Implementation ----------------------------------------------- */
  if (KeyM_Cert_SearchElementByStructureType(certId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY, &elementIdx))
  {
    /* # Retrieve public key coordinates */
    retVal = KeyM_Cert_GetPubKeyElements(certId, elementIdx, &pubKey);

    if (retVal == E_OK)
    {
      /* # Convert public point */
      if (KeyM_GetCertAlgorithmFamilyOfCertificate((KeyM_CertificateIterType)certId) == KEYM_EDDSA)
      {
        retVal = KeyM_Cert_ConvertPublicPoint_EdDSA(&KeyM_Cert_GetCertElementDataPointer(certId, elementIdx)[pubKey.firstElementOffset], &KeyM_Cert_GetCertElementDataPointer(certId, elementIdx)[pubKey.secondElementOffset], pubKey.firstElementLength);
      }
      else /* KeyM_GetCertAlgorithmFamilyOfCertificate(certId) == KEYM_ECDSA */
      {
        retVal = KeyM_Cert_ConvertPublicPoint_ECDSA(&KeyM_Cert_GetCertElementDataPointer(certId, elementIdx)[pubKey.firstElementOffset], pubKey.firstElementLength);
      }

      if (retVal == E_OK)
      {
        /* # Set CSM key element and key status */
        csmResult = Csm_KeyElementSet(KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)certId), CRYPTO_KE_SIGNATURE_KEY, KeyM_Cert_PubKeyBuffer, KeyM_Cert_PubKeyLength);
        csmResult |= Csm_KeySetValid(KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)certId));

        retVal = KeyM_Cert_HandleCsmResult(certId, csmResult, KEYM_CERT_STATE_SET_KEY);
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateSetKeyRSA()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateSetKeyRSA(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_SizeOfCertificateElementType elementIdx = 0u;

  Std_ReturnType csmResult;
  KeyM_CertPubKeyType pubKey = { 0u };

  /* ----- Implementation ----------------------------------------------- */
  if (KeyM_Cert_SearchElementByStructureType(certId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY, &elementIdx))
  {
    /* # Retrieve modulus and exponent of parsed data */
    retVal = KeyM_Cert_GetPubKeyElements(certId, elementIdx, &pubKey);

    if (retVal == E_OK)
    {
      /* # Set CSM key element and key status */
      csmResult = Csm_KeyElementSet(KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)certId), CRYPTO_KE_CUSTOM_RSA_MODULUS, &KeyM_Cert_GetCertElementDataPointer(certId, elementIdx)[pubKey.firstElementOffset], pubKey.firstElementLength);
      csmResult |= Csm_KeyElementSet(KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)certId), CRYPTO_KE_CUSTOM_RSA_PUBLIC_EXPONENT, &KeyM_Cert_GetCertElementDataPointer(certId, elementIdx)[pubKey.secondElementOffset], pubKey.secondElementLength);
      csmResult |= Csm_KeySetValid(KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)certId));

      retVal = KeyM_Cert_HandleCsmResult(certId, csmResult, KEYM_CERT_STATE_SET_KEY);
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#if (KEYM_CERTIFICATESETKEYCALLOUT == STD_ON)
# ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateSetKeyCallout()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateSetKeyCallout(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_SizeOfCertificateElementType elementIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Call configurable callout to set public key in corresponding CSM key element */
  if (KeyM_Cert_SearchElementByStructureType(certId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY, &elementIdx))
  {
    KeyM_SizeOfCertificateSetKeyCalloutType calloutIdx;
    KeyM_CertificateSetKeyCalloutFctPtrType calloutFunction;

    calloutIdx = KeyM_GetCertificateSetKeyCalloutIdxOfCertificate((KeyM_CertificateIterType)certId);
    /*@ assert calloutIdx < KeyM_GetSizeOfCertificateSetKeyCallout(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION_WITH_REQUIREMENT */

    calloutFunction = KeyM_GetCertificateSetKeyCallout(calloutIdx);

#  ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
    /* VCA does not analyze customer-provided callbacks. The API contract for customer-provided callbacks is
     * annotated in the VCA stub. So no problems can arise with customer-provided callbacks if they uphold the
     * API contract. */
    calloutFunction = &Vcastub_Appl_CertificateSetKeyCallout;
#  endif

    if ((calloutFunction(
      certId,
      KeyM_GetIdOfCertificateElement(elementIdx),
      KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)certId),
      KeyM_Cert_GetCertElementDataPointer(certId, elementIdx),
      KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length)) == E_OK)
    {
      retVal = E_OK;
      KeyM_Cert_TriggerState(certId);
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */
#endif

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateSetKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateSetKey(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check for configured callout */
# if (KEYM_CERTIFICATESETKEYCALLOUT == STD_ON)
  if (KeyM_IsCertificateSetKeyCalloutUsedOfCertificate((KeyM_CertificateIterType)certId))
  {
    retVal = KeyM_Cert_StateSetKeyCallout(certId); /* VCA_KEYM_FUNCTION_REQUIREMENT_CHECKED */
  }
  else
# endif
  {
    /* # Set and validate key element for public key */
    switch (KeyM_Asn1_GetAlgoType(certId))
    {
      case KEYM_ASN1_ALGO_X509_ECDSA:
      case KEYM_ASN1_ALGO_X509_EDDSA:
      {
        retVal = KeyM_Cert_StateSetKeyX509ECC(certId);
        break;
      }
      case KEYM_ASN1_ALGO_CVC_ECDSA:
      case KEYM_ASN1_ALGO_CVC_EDDSA:
      {
        retVal = KeyM_Cert_StateSetKeyCVCECC(certId);
        break;
      }
      case KEYM_ASN1_ALGO_X509_RSA:
      case KEYM_ASN1_ALGO_CVC_RSA:
      {
        retVal = KeyM_Cert_StateSetKeyRSA(certId);
        break;
      }
      default:
      {
        retVal = E_NOT_OK;
        break;
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_CRLHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetCrlCertId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCrlCertId(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, AUTOMATIC) crlCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIterType certIdx;
  KeyM_CertificateIdType crlCertIdLocal = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through configured certificates. Search CRL that has the same issuer as the certificate to be verified. */
  for (certIdx = 0; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
  {
    /* # Get crl certificate identifier */
    if ((KeyM_Cert_IsSameIssuer((KeyM_CertificateIdType)certIdx, certId) && (KeyM_GetCertFormatTypeOfCertificate(certIdx) == KEYM_CRL)))
    {
      crlCertIdLocal = (KeyM_CertificateIdType)certIdx;
      retVal = E_OK;
      break;
    }
  }

  *crlCertId = crlCertIdLocal;
  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_CRLHANDLING */

#ifndef KEYM_NOUNIT_CRLHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ParseCRL()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_ParseCRL(
  KeyM_CertificateIdType certId,
  KeyM_CertificateIdType crlCertId,
  KeyM_SizeOfCertificateElementType crlElementIdx,
  KeyM_SizeOfCertificateElementType serialNumElementIdx,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) isRevoked)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_Asn1_ParamType asn1Param;
  uint16_least i;

  /* ----- Implementation ----------------------------------------------- */
  /* # Initialize parser */
  KeyM_Asn1_Init(&asn1Param, KeyM_Cert_GetCertElementDataPointer(crlCertId, crlElementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(crlElementIdx)).length);

  /* # Iterate through CRL */
  for (i = 0u; (i < KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(crlElementIdx)).length) && (asn1Param.remaining_len != 0u) && (retVal == E_OK); i++)
  {
    retVal = KeyM_Cert_GetTL(&asn1Param);

    if (retVal == E_OK)
    {
      if (asn1Param.last_tag == KEYM_ASN1_TYPE_INTEGER)
      {
        /* # Compare serial numbers */
        if (KeyM_Utils_BufferCmp(KeyM_Cert_GetCertElementDataPointer(certId, serialNumElementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(serialNumElementIdx)).length, &KeyM_Cert_GetCertElementDataPointer(crlCertId, crlElementIdx)[asn1Param.current_pos], asn1Param.last_tag_len))
        {
          *isRevoked = TRUE;
          break;
        }
      }

      if (asn1Param.last_tag_has_data)
      {
        KeyM_Asn1_NextTag(&asn1Param);
      }
    }
  }
}
#endif /* ifndef KEYM_NOUNIT_CRLHANDLING */

#ifndef KEYM_NOUNIT_CRLHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertRevoked()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertRevoked(
  KeyM_CertificateIdType certId,
  KeyM_CertificateIdType crlCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_SizeOfCertificateElementType serialNumElementIdx = 0u;
  KeyM_CertificateElementIterType crlElementIdx;
  boolean isRevoked = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  if (KeyM_Cert_SearchElementByStructureType(certId, KEYM_CERTIFICATE_SERIAL_NUMBER, &serialNumElementIdx))
  {
    /* # Check if certificate is revoked */
    for (crlElementIdx = KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)crlCertId); crlElementIdx < KeyM_GetCertificateElementEndIdxOfCertificate((KeyM_CertificateIterType)crlCertId); crlElementIdx++)
    {
      if (KeyM_GetOfStructureOfCertificateElement(crlElementIdx) == KEYM_CERTIFICATE_REVOCATION_LIST)
      {
        KeyM_Cert_ParseCRL(certId, crlCertId, (KeyM_SizeOfCertificateElementType)crlElementIdx, serialNumElementIdx, &isRevoked);
      }
    }
  }

  return isRevoked;
}
#endif /* ifndef KEYM_NOUNIT_CRLHANDLING */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CheckRevocation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_CheckRevocation(
  KeyM_CertificateIdType certId,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) revocationStatus)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Check certificate revocation list */
  KeyM_Cert_CheckRevocationByCRL(certId, revocationStatus);

# if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
  if (!*revocationStatus)
  {
    /* # Check certificate revocation entries */
    KeyM_Cert_CheckRevocationByCRE(certId, revocationStatus);
  }
# endif
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_CRLHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CheckRevocationByCRL()
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
/* PRQA S 6050, 6080 1 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_CheckRevocationByCRL(
  KeyM_CertificateIdType certId,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) revocationStatus)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_CertificateIdType crlCertId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* Root certificate is self-signed and therefore can not be revoked */
  if (!KeyM_Cert_IsCertRoot(certId) && !(KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_CRL))
  {
    /* # Get CRL cert Id */
    if (KeyM_Cert_GetCrlCertId(certId, &crlCertId) == E_OK)
    {
      /* # Check if CRL is set */
      if ((!KeyM_Cert_IsCertSlotEmpty(crlCertId)) || (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)crlCertId) == KEYM_STORAGE_IN_ROM))
      {
        /* # Check if CRL is valid */
        if ((KeyM_Cert_GetStatusInfo(crlCertId) == KEYM_CERTIFICATE_VALID))
        {
          /* # Check revocation state */
          if (KeyM_Cert_IsCertRevoked(certId, crlCertId))
          {
            *revocationStatus = TRUE;

            /* # Set certificate status */
            KeyM_Cert_SetStatusInfo(certId, KEYM_E_CERTIFICATE_REVOKED);
          }
        }
      }
    }
  }
}
#endif /* ifndef KEYM_NOUNIT_CRLHANDLING */

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_CREHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CheckRevocationByCRE()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_CheckRevocationByCRE(
  KeyM_CertificateIdType certId,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) revocationStatus)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_CREInfoIterType creIdx;
  uint16 issuerNameDataLength;
  uint16 serialNumberDataLength;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through certificate revocation entries */
  for (creIdx = 0u; creIdx < KeyM_Cert_NumOfCRE; creIdx++)
  {
    issuerNameDataLength = KeyM_Cert_GetCREIssuerNameWrittenLength((KeyM_SizeOfCREInfoType)creIdx);
    serialNumberDataLength = KeyM_Cert_GetCRESerialNumberWrittenLength((KeyM_SizeOfCREInfoType)creIdx);

    /* # Check revocation status by each entry */

    if (KeyM_Cert_IsCertRevokedBySingleCRE(certId, KeyM_GetAddrCREStorage(KeyM_GetCREStorageIssuerStartIdxOfCREInfo((KeyM_SizeOfCREInfoType)creIdx)), issuerNameDataLength, KeyM_GetAddrCREStorage(KeyM_GetCREStorageSerialNumberStartIdxOfCREInfo((KeyM_SizeOfCREInfoType)creIdx)), serialNumberDataLength))
    {
      *revocationStatus = TRUE;

      /* # Set certificate status */
      KeyM_Cert_SetStatusInfo(certId, KEYM_E_CERTIFICATE_REVOKED);

      break;
    }
  }
}
# endif /* ifndef KEYM_NOUNIT_CREHANDLING */
#endif

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateSignatureVerify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateSignatureVerify(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Std_ReturnType csmResult;
  boolean certRevoked = FALSE;
  KeyM_CertificateIdType issuerCertId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check revocation */
  KeyM_Cert_CheckRevocation(certId, &certRevoked);

  if (!certRevoked)
  {
    KeyM_Cert_State = KEYM_CERT_STATE_VERIFY_SIGNATURE_PENDING;

    /* # Verify signature */
    retVal = KeyM_Cert_GetIssuerCertId(certId, &issuerCertId);

    if (retVal == E_OK)
    {
      csmResult = Csm_SignatureVerify(
          KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate((KeyM_CertificateIterType)issuerCertId),
          CRYPTO_OPERATIONMODE_SINGLECALL,
          KeyM_GetCert_CertInfo((KeyM_Cert_CertInfoIterType)certId).sigProcessDataPtr,
          KeyM_GetCert_CertInfo((KeyM_Cert_CertInfoIterType)certId).sigProcessDataLength,
          KeyM_Cert_SigBuffer,
          KeyM_Cert_SigLength,
          &(KeyM_GetAddrCert_CertInfo(((KeyM_Cert_CertInfoIterType)certId))->verifyRes));
      retVal = KeyM_Cert_HandleCsmResult(certId, csmResult, KEYM_CERT_STATE_VERIFY_SIGNATURE);
    }
# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
    else
    {
      KeyM_Cert_SetStatusInfo(certId, KEYM_E_CERTIFICATE_SIGNATURE_FAIL);
      KeyM_Cert_State = KEYM_CERT_STATE_NOTIFY;
    }
# endif
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateStore()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_StateStore(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

# if (KEYM_CSMKEYTARGETREFOFCERTIFICATE == STD_ON)
  Std_ReturnType csmResult;
# endif

  /* ----- Implementation ----------------------------------------------- */
  if ((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)certId) & KEYM_CERT_STORAGE_MASK_DIRTY) != KEYM_CERT_STORAGE_MASK_DIRTY)
  {
    KeyM_Cert_TriggerState(certId);
    retVal = E_OK;
  }
  else
  {
    /* # Store certificate data in permanent storage */
    switch (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)certId))
    {
# if (KEYM_CSMKEYTARGETREFOFCERTIFICATE == STD_ON)
      case KEYM_STORAGE_IN_CSM:
      {
        KeyM_ConstCertDataType certData;
        certData = KeyM_Cert_GetCertificateReadBufferData(certId);

        csmResult = Csm_KeyElementSet(KeyM_GetCsmKeyTargetRefOfCertificate((KeyM_CertificateIterType)certId), CRYPTO_KE_CERTIFICATE_DATA, certData.certData, certData.certDataLength); /* VCA_KEYM_CERT_KEYELEMENTSET_READBUFFER */
        csmResult |= Csm_KeySetValid(KeyM_GetCsmKeyTargetRefOfCertificate((KeyM_CertificateIterType)certId));

        retVal = KeyM_Cert_HandleCsmResult(certId, csmResult, KEYM_CERT_STATE_STORE);

        if (retVal == E_OK)
        {
          /* Set storage type to CSM */
          KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)(certId), (tKeyMCertStorageType)((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)certId)) | (KEYM_CERT_STORAGE_MASK_CSM)));
          /* Remove dirty flag */
          KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)certId, KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)certId) & ~KEYM_CERT_STORAGE_MASK_DIRTY);
        }
        break;
      }
# endif
# if(KEYM_CERTIFICATE_NVMBLOCK == STD_ON)
      case KEYM_STORAGE_IN_NVM:
      {
        KeyM_NvBlock_Persist(certId);
        /* Remove dirty flag */
        KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)certId, KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)certId) & ~KEYM_CERT_STORAGE_MASK_DIRTY);
        KeyM_Cert_TriggerState(certId);
        retVal = E_OK;
        break;
      }
# endif
      case KEYM_STORAGE_IN_RAM:
      {
        KeyM_Cert_TriggerState(certId);
        retVal = E_OK;
        break;
      }
      default:
      {
        retVal = E_NOT_OK;
        break;
      }
    }
  }
# if (KEYM_CSMKEYTARGETREFOFCERTIFICATE == STD_ON)
  /* # Set certificate status */
  if (retVal != E_OK)
  {
    KeyM_Cert_SetStatusInfo(certId, KEYM_CERTIFICATE_INVALID);
  }
# endif

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertSlotEmpty()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertSlotEmpty(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = TRUE;
  uint16 certStatus;

  /* ----- Implementation ----------------------------------------------- */
  if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)certId) != KEYM_STORAGE_IN_ROM)
  {
    certStatus = KeyM_Cert_GetStatusInfo(certId);

    /* # Check storage type and status of certificate */
    if ((((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)certId)) & (KEYM_CERT_STORAGE_MASK_DATA_BUFFER)) == (KEYM_CERT_STORAGE_MASK_DATA_BUFFER))
    && (certStatus != KEYM_CERTIFICATE_NOT_AVAILABLE)
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
    && (KeyM_Cert_IsCertIdSlotOwner(certId))
# endif
    )
    {
      retVal = FALSE;
    }

# if (KEYM_CSMKEYTARGETREFOFCERTIFICATE == STD_ON)
    else
    {
      /* # Load certificate from permanent storage */
      if (KeyM_Cert_LoadCertificateFromStorage(certId) == E_OK)
      {
        retVal = FALSE; /* PRQA S 2880 */ /* MD_MSR_Unreachable */
      }
    }
# endif
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_VERIFYCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyCertificatesTriggerState()
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
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyCertificatesTriggerState(
  KeyM_CertificateIdType CertId,
  P2VAR(tKeyMCertState, AUTOMATIC, KEYM_APPL_VAR) state)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_CertificateStatusType lowerCertStatus;

  /* ----- Implementation ----------------------------------------------- */
  lowerCertStatus = KeyM_Cert_GetStatusInfo(CertId);

  /* # Check if certificate has already been parsed */
  if ((lowerCertStatus == KEYM_CERTIFICATE_VALID) || (lowerCertStatus == KEYM_CERTIFICATE_PARSED_NOT_VALIDATED))
  {
    if (((KeyM_GetCertStartUpHandlingOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_PARSE_AND_TRUST) && (KeyM_Cert_StartUpState == KEYM_CERT_STARTUP_STATE_ACTIVE)))
    {
      /* Continue with notify state since verification not needed */
      *state = (tKeyMCertState)KEYM_CERT_STATE_NOTIFY;
    }
# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
    else if (((KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_DYNAMIC_OPTIONAL_ISSUER) && (!(KeyM_Cert_UpperHierarachicalRefInfo[CertId].isIssuerCertIdAvailable))))
    {
      /* Set public key for further verification */
      *state = (tKeyMCertState)KEYM_CERT_STATE_SET_KEY;

      /* Copy public key in associated buffer */
      KeyM_Cert_PubKeyLength = KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH;
      retVal = KeyM_Cert_GetElementByStructureType(CertId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY, KeyM_Cert_PubKeyBuffer, &KeyM_Cert_PubKeyLength);

      if (retVal == E_OK)
      {
        /* Copy signature in associated buffer */
        KeyM_Cert_SigLength = KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH;
        retVal = KeyM_Cert_GetElementByStructureType(CertId, KEYM_CERTIFICATE_SIGNATURE, KeyM_Cert_SigBuffer, &KeyM_Cert_SigLength);
      }
    }
# endif
    else
    {
      KeyM_Cert_PubKeyLength = KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH;
      KeyM_Cert_SigLength = KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH;

      /* Continue with verification process */
      *state = (tKeyMCertState)KEYM_CERT_STATE_CHECK_SUBJECT;

      /* # Copy public key in associated buffer */
      if (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)CertId) != KEYM_CRL)
      {
        retVal = KeyM_Cert_GetElementByStructureType(CertId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY, KeyM_Cert_PubKeyBuffer, &KeyM_Cert_PubKeyLength);
      }

      if (retVal == E_OK)
      {
        /* Copy signature in associated buffer */
        retVal = KeyM_Cert_GetElementByStructureType(CertId, KEYM_CERTIFICATE_SIGNATURE, KeyM_Cert_SigBuffer, &KeyM_Cert_SigLength);
      }
    }
  }
  else if (KeyM_Cert_GetStatusInfo(CertId) == (KEYM_CERTIFICATE_NOT_PARSED))
  {
    *state = (tKeyMCertState)KEYM_CERT_STATE_INIT;
  }
  else
  {
    /* Return with error if certificate data is not parsed or not available */
    retVal = E_NOT_OK;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERT */

#ifndef KEYM_NOUNIT_VERIFYCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyCertificatesProcess()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6050, 6080 4 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyCertificatesProcess(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateIdType CertUpperId,
  P2VAR(tKeyMCertState, AUTOMATIC, KEYM_APPL_VAR) state)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateStatusType upperCertStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
  boolean isLowerCertSlotEmpty;
  boolean isUpperCertSlotEmpty;
  boolean isCertRoot;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if CertIds are invalid */
  if ((CertId >= KeyM_GetSizeOfCertificate()) || (CertUpperId >= KeyM_GetSizeOfCertificate()))
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  else if((!KeyM_Cert_IsCertIdSlotOwner(CertId)) || (!KeyM_Cert_IsCertIdSlotOwner(CertUpperId)))
  {
    /* leave retVal at E_NOT_OK */
  }
# endif
  else
  {
    (void)KeyM_Cert_CertGetStatus(CertUpperId, &upperCertStatus);

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
    retVal = KeyM_Cert_CheckDynamicIssuer(CertId);

    if (retVal == E_OK)
# endif
    {
      isLowerCertSlotEmpty = KeyM_Cert_IsCertSlotEmpty(CertId);
      isUpperCertSlotEmpty = KeyM_Cert_IsCertSlotEmpty(CertUpperId);
      isCertRoot = KeyM_Cert_IsCertRoot(CertId);

      /* # Check if one of the certificate slots are empty */
      if ((isLowerCertSlotEmpty && (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) != KEYM_STORAGE_IN_ROM)) || (isUpperCertSlotEmpty && (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertUpperId) != KEYM_STORAGE_IN_ROM)))
      {
        retVal = KEYM_E_KEY_CERT_EMPTY;
      }
      /* # Check status of upper certificate */
      else if ((upperCertStatus != KEYM_CERTIFICATE_VALID)
      && (!((upperCertStatus == KEYM_CERTIFICATE_PARSED_NOT_VALIDATED) && isCertRoot)) /* An unverified root is a valid case */
# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
      /* Check if optional issuer is available */
      && (!((KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)CertUpperId) == KEYM_DYNAMIC_OPTIONAL_ISSUER) && (!(KeyM_Cert_UpperHierarachicalRefInfo[CertUpperId].isIssuerCertIdAvailable)))) /* An upper certificate with optional issuer which is not available is a valid case */
# endif
      )
      {
        retVal = KEYM_E_CERT_INVALID_CHAIN_OF_TRUST;
      }
      else
      {
        retVal = KeyM_Cert_VerifyCertificatesTriggerState(CertId, state);
      }
    }
  }

  if (retVal != E_OK)
  {
    if (KeyM_Cert_ChainVerificationFlag)
    {
      retVal = E_OK;
      /* Continue with notify state and check if there are other certificates to be verified */
      *state = (tKeyMCertState)KEYM_CERT_STATE_NOTIFY;
    }
    else
    {
      KeyM_Cert_ClearVerifyChain();
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERT */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ParseAndVerifyElements()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ParseAndVerifyElements(
  KeyM_CertificateIdType certId)
{
  /* # Call KeyM_Cert_StateParseCert() */
  Std_ReturnType retVal = KeyM_Cert_StateParseCert(certId);

  if (retVal == E_OK)
  {
    /* # If successful, call KeyM_Cert_StateVerifyCertElements() */
    retVal = KeyM_Cert_StateVerifyCertElements(certId);
  }

  /* # Return error code that was returned by state handlers */
  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#if ((KEYM_CERTIFICATEINITVALUE == STD_ON) || (KEYM_CERTIFICATEINITCALLOUT == STD_ON))
# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_LoadCertificateInitValue()
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
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_LoadCertificateInitValue(
  KeyM_CertificateIdType certId)
{
  KeyM_CertDataType ramBuffer;
  KeyM_ConstCertDataPointerType initValuePtr = KeyM_GetAddrCertStorage(0u);
  uint32 initValueLength = 0u;
  KeyM_CertificateInitValueInfoIdxOfCertificateType initValueInfoIdx = KeyM_GetCertificateInitValueInfoIdxOfCertificate((KeyM_CertificateIterType)certId);
  /*@ assert initValueInfoIdx < KeyM_GetSizeOfCertificateInitValueInfo(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION_WITH_REQUIREMENT */

  /*@ assert initValuePtr != NULL_PTR; */
  /*@ assert initValueLength <= $lengthOf(initValuePtr); */

  ramBuffer = KeyM_Cert_GetCertificateWriteBufferData(certId);

#  if (KEYM_CERTIFICATEINITVALUE == STD_ON)
  if (KeyM_IsCertificateInitValueUsedOfCertificateInitValueInfo(initValueInfoIdx))
  {
    KeyM_SizeOfCertificateInitValueType initValueStartIdx = KeyM_GetCertificateInitValueStartIdxOfCertificateInitValueInfo(initValueInfoIdx);
    /*@ assert initValueStartIdx < KeyM_GetSizeOfCertificateInitValue(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

    initValuePtr = (KeyM_ConstCertDataPointerType)KeyM_GetAddrCertificateInitValue(initValueStartIdx);
    initValueLength = (uint32)KeyM_GetCertificateInitValueLengthOfCertificateInitValueInfo(initValueInfoIdx);
    /*@ assert initValuePtr != NULL_PTR; */
    /*@ assert initValueLength <= $lengthOf(initValuePtr); */ /* VCA_KEYM_CSL03_LENGTHASSERTION */
  }
  else
#  endif
  {
#  if (KEYM_CERTIFICATEINITCALLOUT == STD_ON)
    if (KeyM_IsCertificateInitCalloutUsedOfCertificateInitValueInfo(initValueInfoIdx))
    {
      KeyM_CertificateInitCalloutIdxOfCertificateInitValueInfoType calloutIdx;
      KeyM_CertificateInitCalloutFctPtrType calloutFunction;
      KeyM_ConstCertDataType certInitValue;

      certInitValue.certDataLength = ramBuffer.certDataLength; /* contract of Appl_CertInitCallout states that supplied KeyM_ConstCertDataType struct provides the maximum init value length on call */

      calloutIdx = KeyM_GetCertificateInitCalloutIdxOfCertificateInitValueInfo(initValueInfoIdx);
      /*@ assert calloutIdx < KeyM_GetSizeOfCertificateInitCallout(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

      calloutFunction = KeyM_GetCertificateInitCallout(calloutIdx);

#   ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
      /* VCA does not analyze customer-provided callbacks. The API contract for customer-provided callbacks is
       * annotated in the VCA stub. So no problems can arise with customer-provided callbacks if they uphold the
       * API contract. */
      calloutFunction = &Vcastub_Appl_CertificateInitCallout;
#   endif

      calloutFunction(certId, &certInitValue);
      initValuePtr = certInitValue.certData;
      initValueLength = certInitValue.certDataLength;
      /*@ assert initValuePtr != NULL_PTR; */
      /*@ assert initValueLength <= $lengthOf(initValuePtr); */ /* VCA_KEYM_CERT_INITVALUECALLOUT */
    }
#  endif
  }

  if (ramBuffer.certDataLength >= initValueLength)
  {
    /* no exclusive area since being during startup */
    VStdLib_MemCpyLarge(ramBuffer.certData, initValuePtr, initValueLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_LOADCERTIFICATEINITVALUE_MEMCPY */
    KeyM_Cert_SetCertificateWrittenLength(certId, (uint16)initValueLength);
    KeyM_Asn1_ClearCertificateElementStorage(certId);
    /* Set storage type */
    KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)(certId), (tKeyMCertStorageType)((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)certId)) | (KEYM_CERT_STORAGE_MASK_DATA_BUFFER | KEYM_CERT_STORAGE_MASK_DIRTY)));

    KeyM_Cert_SetStatusInfo(certId, KEYM_CERTIFICATE_NOT_PARSED);
  }
#  if (KEYM_CERTIFICATEINITCALLOUT == STD_ON)
  else
  {
#   if (KEYM_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CERT_LOADCERTIFICATEINITVALUE, KEYM_E_CERTIFICATE_INIT_VALUE_INVALID_LENGTH);
    KeyM_Cert_SetStatusInfo(certId, KEYM_CERTIFICATE_NOT_AVAILABLE);
#   endif
  }
#  endif

} /* KeyM_Cert_LoadCertificateInitValue() */
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */
#endif

#if (KEYM_CSMKEYTARGETREFOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_LoadCertificateFromCsm()
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
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_LoadCertificateFromCsm(
  KeyM_CertificateIdType certId)
{
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  KeyM_CertDataType ramBuffer;
  ramBuffer = KeyM_Cert_GetCertificateWriteBufferData(certId);

  csmResult = Csm_KeyElementGet(KeyM_GetCsmKeyTargetRefOfCertificate((KeyM_CertificateIterType)certId), CRYPTO_KE_CERTIFICATE_DATA, ramBuffer.certData, &ramBuffer.certDataLength); /* VCA_KEYM_CERT_KEYELEMENTGET_WRITEBUFFER */

  if (csmResult == E_OK)
  {
    KeyM_Cert_SetCertificateWrittenLength(certId, (uint16)ramBuffer.certDataLength);
    KeyM_Asn1_ClearCertificateElementStorage(certId);
    /* Set storage type */
    KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)(certId), (tKeyMCertStorageType)((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)certId)) | (KEYM_CERT_STORAGE_MASK_CSM | KEYM_CERT_STORAGE_MASK_DATA_BUFFER)));

    KeyM_Cert_SetStatusInfo(certId, KEYM_CERTIFICATE_NOT_PARSED);

    retVal = E_OK;
  }
  else
  {
#  if ((KEYM_CERTIFICATEINITVALUE == STD_ON) || (KEYM_CERTIFICATEINITCALLOUT == STD_ON))
    if (KeyM_IsCertificateInitValueInfoUsedOfCertificate((KeyM_CertificateIterType)certId))
    {
      KeyM_Cert_LoadCertificateInitValue(certId); /* VCA_KEYM_FUNCTION_REQUIREMENT_CHECKED */
      retVal = E_OK;
    }
    else
#  endif
    {
      retVal = (csmResult == CRYPTO_E_KEY_NOT_AVAILABLE) ? KEYM_E_KEY_CERT_EMPTY : KEYM_E_KEY_CERT_READ_FAIL;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */
#endif

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_LoadCertificateFromStorage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_LoadCertificateFromStorage(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Handle certificate loading differently depending on storage: */
  switch (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)certId))
  {
# if (KEYM_CSMKEYTARGETREFOFCERTIFICATE == STD_ON)
  case KEYM_STORAGE_IN_CSM:
  {
    /* # For storage in CSM, forward call to KeyM_Cert_LoadCertificateFromCsm() */
    retVal = KeyM_Cert_LoadCertificateFromCsm(certId);
    break;
  }
# endif
  case KEYM_STORAGE_IN_NVM:
  {
    /* # For storage in NVM, certificate should already have been provided by NvM_ReadAll at startup
     *        --> return KEYM_E_KEY_CERT_EMPTY */
    retVal = KEYM_E_KEY_CERT_EMPTY;
    break;
  }
  default:
  {
    /* # If there is no storage to load the certificate from, return E_NOT_OK */
    retVal = E_NOT_OK;
    break;
  }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#if ((KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON) || (KEYM_RTECALLBACKNOTIFICATION == STD_ON))
# ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetServiceResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_GetServiceResult(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_ResultType, AUTOMATIC, KEYM_APPL_VAR) result)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Map certificate status to result type for application */
  switch (KeyM_Cert_GetStatusInfo(certId))
  {
    case KEYM_CERTIFICATE_VALID:
    {
      *result = KEYM_RT_OK;
      break;
    }
    case KEYM_CERTIFICATE_PARSED_NOT_VALIDATED:
    {
      if (KeyM_GetCert_CertInfo((KeyM_Cert_CertInfoIterType)certId).csmRes != E_OK)
      {
        *result = KEYM_RT_NOT_OK;
      }
      else
      {
        *result = KEYM_RT_OK;
      }

      break;
    }
    case KEYM_CERTIFICATE_INVALID:
    case KEYM_CERTIFICATE_NOT_PARSED:
    case KEYM_CERTIFICATE_NOT_AVAILABLE:
    case KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL:
    case KEYM_E_CERTIFICATE_SIGNATURE_FAIL:
    case KEYM_E_CERTIFICATE_INVALID_TYPE:
    case KEYM_E_CERTIFICATE_INVALID_FORMAT:
    case KEYM_E_CERTIFICATE_INVALID_CONTENT:
    case KEYM_E_CERTIFICATE_REVOKED:
    {
      *result = KEYM_RT_KEY_CERT_INVALID;
      break;
    }
    case KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST:
    {
      *result = KEYM_RT_CERT_INVALID_CHAIN_OF_TRUST;
      break;
    }
    default:
    {
      /* Do nothing */
      break;
    }
  }
}
# endif /* ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING */
#endif

#ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateNotifyErrorHandling()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 3673, 6050 4 */ /* MD_KEYM_8.13_DeactivateableFeature, MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateNotifyErrorHandling(
  KeyM_CertificateIdType certId,
  P2VAR(tKeyMCertTaskState, AUTOMATIC, AUTOMATIC) localTaskState,
  P2VAR(KeyM_ResultType, AUTOMATIC, AUTOMATIC) serviceResult)
{
  /* ----- Local Variables ---------------------------------------------- */
# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
  Std_ReturnType subRetVal;
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* # Set TaskState to Idle */
  *localTaskState = KEYM_CERT_TASKSTATE_IDLE;

  /* # Restore certificate data for a certificate update service request */
# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
  if (KeyM_Cert_UpdateFlag)
  {
    /* Copy certificate data from permanent storage */
    KeyM_Cert_UpdateFlag = FALSE;

    if (KeyM_Cert_RequestId == certId)
    {
      /* Load old certificate from storage */
      subRetVal = KeyM_Cert_LoadCertificateFromStorage(certId);

#  if (KEYM_CSMKEYTARGETREFOFCERTIFICATE == STD_ON)
      if ((KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)certId) == KEYM_STORAGE_IN_CSM) && (subRetVal == E_OK)) /* PRQA S 2992, 2996 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
      {
        subRetVal = KeyM_Cert_ParseAndVerifyElements(certId);
      }

#   if (KEYM_CERTCSMHASHJOBREFOFCERTIFICATE == STD_ON)
      if ((subRetVal == E_OK) && (KeyM_IsCertHashStorageUsedOfCertificate((KeyM_CertificateIterType)certId))) /* PRQA S 2992, 2996 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
      {
        subRetVal = KeyM_Cert_ComputeCertHash(certId); /* VCA_KEYM_FUNCTION_REQUIREMENT_CHECKED */
      }
#   endif
#  endif

      if (subRetVal != E_OK) /* PRQA S 2991, 2995 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
      {
        KeyM_Cert_SetStatusInfo(certId, KEYM_CERTIFICATE_NOT_AVAILABLE);
      }
#  if ((KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON) || (KEYM_RTECALLBACKNOTIFICATION == STD_ON))
      /* Root or intermediate could not be updated */
      *serviceResult = KEYM_RT_KEY_CERT_UPDATE_FAIL;
#  endif
    }
#  if ((KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON) || (KEYM_RTECALLBACKNOTIFICATION == STD_ON))
    else
    {
      /* Root or intermediate was updated successfully since they are handled first during update */
      *serviceResult = KEYM_RT_OK;
    }
#  endif
  }
#  if ((KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON) || (KEYM_RTECALLBACKNOTIFICATION == STD_ON))
  else
  {
    KeyM_Cert_GetServiceResult(certId, serviceResult);
  }
#  endif
# else
  KEYM_DUMMY_STATEMENT(serviceResult); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* Initialize CSM result */
  KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certId)->csmRes = (Crypto_VerifyResultType)(E_OK);

# if ((KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_OFF) && (KEYM_RTECALLBACKNOTIFICATION == STD_OFF))
  KEYM_DUMMY_STATEMENT(serviceResult); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif /* ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING */

#ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateNotifyValidateChainIncomplete()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 3673 4 */ /* MD_KEYM_8.13_DeactivateableFeature */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateNotifyValidateChainIncomplete(
  P2VAR(tKeyMCertTaskState, AUTOMATIC, AUTOMATIC) localTaskState,
  P2VAR(KeyM_ResultType, AUTOMATIC, AUTOMATIC) serviceResult,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) isVerificationTriggered)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType localLowerCertId;
  KeyM_CertificateIdType localUpperCertId = 0u;
  tKeyMCertState localState;

  /* ----- Implementation ----------------------------------------------- */
  localLowerCertId = KeyM_Cert_PopVerifyChainLink();

  /* # Get certificate identifier for further verification */
  retVal = KeyM_Cert_GetIssuerCertId(localLowerCertId, &localUpperCertId);

  if (retVal == E_OK)
  {
    /* # Trigger verification */
    retVal = KeyM_Cert_VerifyCertificatesProcess(localLowerCertId, localUpperCertId, &localState);

    if (retVal == E_OK)
    {
      /* # Call certificate verify callback notification for application */
      KeyM_Cert_VerifyCallbackNotification(); /* PRQA S 2987 */ /* MD_KEYM_2.2 */

      if ((KeyM_Cert_StartUpState == KEYM_CERT_STARTUP_STATE_FINISHED))
      {
        /* Set request type */
        KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)localLowerCertId)->request = (tKeyMCertRequestType)(KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)localLowerCertId)->request | (tKeyMCertRequestType)(KEYM_CERT_REQUEST_VERIFY));
      }

      KeyM_Cert_State = localState;
      KeyM_Cert_CertId = localLowerCertId;
      *isVerificationTriggered = TRUE;
    }
    else
    {
      /* Set TaskState to Idle */
      *localTaskState = KEYM_CERT_TASKSTATE_IDLE;

# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
      if (KeyM_Cert_IsCertRequestEqualTo(KEYM_CERT_REQUEST_SERVICE))
      {
        KeyM_Cert_UpdateFlag = FALSE;
#  if ((KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON) || (KEYM_RTECALLBACKNOTIFICATION == STD_ON))
        *serviceResult = KEYM_RT_OK;
#  else
        KEYM_DUMMY_STATEMENT(serviceResult); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
      }
# else
      KEYM_DUMMY_STATEMENT(serviceResult); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
    }
  }
}
#endif /* ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING */

#ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateNotifyValidateChain()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 3673 4 */ /* MD_KEYM_8.13_DeactivateableFeature */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateNotifyValidateChain(
  P2VAR(tKeyMCertTaskState, AUTOMATIC, AUTOMATIC) localTaskState,
  P2VAR(KeyM_ResultType, AUTOMATIC, AUTOMATIC) serviceResult,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) isVerificationTriggered)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType localLowerCertId;
  KeyM_CertificateIdType localUpperCertId = 0u;
  tKeyMCertState localState;

  /* ----- Implementation ----------------------------------------------- */
  localLowerCertId = KeyM_Cert_PopLeafCertToVerify();

  /* # Get certificate identifier for further verification */
  retVal = KeyM_Cert_GetIssuerCertId(localLowerCertId, &localUpperCertId);

  if (retVal == E_OK)
  {
    /* # Identify invalid chain of certificates */
    retVal = KeyM_Cert_IdentifyInvalidChain(&localLowerCertId, &localUpperCertId);

    if (retVal == E_OK)
    {
      /* # Trigger verification */
      retVal = KeyM_Cert_VerifyCertificatesProcess(localLowerCertId, localUpperCertId, &localState);

      if (retVal == E_OK)
      {
        /* # Call certificate verify callback notification for application */
        KeyM_Cert_VerifyCallbackNotification(); /* PRQA S 2987 */ /* MD_KEYM_2.2 */

        if ((KeyM_Cert_StartUpState == KEYM_CERT_STARTUP_STATE_FINISHED))
        {
          KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)localLowerCertId)->request = (tKeyMCertRequestType)(KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)localLowerCertId)->request | (tKeyMCertRequestType)(KEYM_CERT_REQUEST_VERIFY));
        }

        KeyM_Cert_State = localState;
        KeyM_Cert_CertId = localLowerCertId;
        *isVerificationTriggered = TRUE;
      }
      else
      {
        /* Set TaskState to Idle */
        *localTaskState = KEYM_CERT_TASKSTATE_IDLE;

# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
        if (KeyM_Cert_IsCertRequestEqualTo(KEYM_CERT_REQUEST_SERVICE))
        {
          KeyM_Cert_UpdateFlag = FALSE;
#  if ((KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON) || (KEYM_RTECALLBACKNOTIFICATION == STD_ON))
          *serviceResult = KEYM_RT_OK;
#  else
          KEYM_DUMMY_STATEMENT(serviceResult); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
        }
# else
        KEYM_DUMMY_STATEMENT(serviceResult); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
      }
    }
  }
}
#endif /* ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING */

#ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateNotifyFinish()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 3673 4 */ /* MD_KEYM_8.13_DeactivateableFeature */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateNotifyFinish(
  P2VAR(tKeyMCertTaskState, AUTOMATIC, AUTOMATIC) localTaskState,
  P2VAR(KeyM_ResultType, AUTOMATIC, AUTOMATIC) serviceResult)
{
  KeyM_ResultType serviceResultLocal = KEYM_RT_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  KeyM_Cert_StartUpState = KEYM_CERT_STARTUP_STATE_FINISHED;

  /* # Set TaskState to Idle */
  *localTaskState = KEYM_CERT_TASKSTATE_IDLE;

  if (KeyM_Cert_RequestId < KeyM_GetSizeOfCertificate())
  {

# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
    if (KeyM_Cert_UpdateFlag)
    {
      /* Update certificate in permanent storage */
      Std_ReturnType retVal = KeyM_Cert_StateStore(KeyM_Cert_RequestId);
      KeyM_Cert_UpdateFlag = FALSE;

#  if ((KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON) || (KEYM_RTECALLBACKNOTIFICATION == STD_ON))
      if (retVal != E_OK)
      {
        serviceResultLocal = KEYM_RT_KEY_CERT_WRITE_FAIL;
      }
#  else
      KEYM_DUMMY_STATEMENT(retVal); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
    }
# endif

# if ((KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON) || (KEYM_RTECALLBACKNOTIFICATION == STD_ON))
    if (serviceResultLocal != KEYM_RT_KEY_CERT_WRITE_FAIL)
    {
      KeyM_Cert_GetServiceResult(KeyM_Cert_RequestId, &serviceResultLocal);
    }
# endif
  }

  /* # Reset chain verification flag */
  KeyM_Cert_ChainVerificationFlag = FALSE;

  *serviceResult = serviceResultLocal;
}
#endif /* ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING */

#ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ServiceCertificateCallbackNotification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_ServiceCertificateCallbackNotification(
  KeyM_ResultType serviceResult)
{
  /* ----- Implementation ----------------------------------------------- */
  if (KeyM_Cert_IsCertRequestEqualTo(KEYM_CERT_REQUEST_SERVICE))
  {
    /*@ assert KeyM_Cert_RequestId < KeyM_GetSizeOfCertificate(); */ /* VCA_CERT_SERVICECERTIFICATECALLBACKNOTIFICATION_REQUESTID */
# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
#  if (KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON)
    /* Call service certificate callback notification for application */
    if (KeyM_IsServiceCertificateCallbackNotificationUsedOfCertificate((KeyM_CertificateIterType)KeyM_Cert_RequestId))
    {
      KeyM_SizeOfServiceCertificateCallbackNotificationType callbackIdx;
      KeyM_ServiceCertificateCallbackNotificationFctPtrType callbackFunction;

      callbackIdx = KeyM_GetServiceCertificateCallbackNotificationIdxOfCertificate((KeyM_CertificateIterType)KeyM_Cert_RequestId);
      /*@ assert callbackIdx < KeyM_GetSizeOfServiceCertificateCallbackNotification(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

      callbackFunction = KeyM_GetServiceCertificateCallbackNotification(callbackIdx);

#   ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
      /* VCA does not analyze customer-provided callbacks. The API contract for customer-provided callbacks is
       * annotated in the VCA stub. So no problems can arise with customer-provided callbacks if they uphold the
       * API contract. */
      callbackFunction = &Vcastub_Appl_ServiceCertificateCallbackNotification;
#   endif

      callbackFunction(KeyM_Cert_RequestId, serviceResult, 0, NULL_PTR);
    }
    else
#  endif
    {
#  if (KEYM_RTECALLBACKNOTIFICATION == STD_ON)
      if (KeyM_IsRteCallbackNotificationUsedOfCertificate((KeyM_CertificateIterType)KeyM_Cert_RequestId))
      {
        KeyM_SizeOfRteCallbackNotificationType callbackIdx;
        KeyM_ServiceCertificateRteCallbackNotificationFctPtrType callbackFunction;

        callbackIdx = KeyM_GetRteCallbackNotificationIdxOfCertificate((KeyM_CertificateIterType)KeyM_Cert_RequestId);
        /*@ assert callbackIdx < KeyM_GetSizeOfRteCallbackNotification(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

        callbackFunction = KeyM_GetServiceCertificateOfRteCallbackNotification(callbackIdx);

#   ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
        /* VCA does not analyze customer-provided callbacks. The API contract for customer-provided callbacks is
         * annotated in the VCA stub. So no problems can arise with customer-provided callbacks if they uphold the
         * API contract. */
        callbackFunction = &Vcastub_Appl_ServiceCertificateRteCallbackNotification;
#   endif

        (void)callbackFunction(serviceResult, 0, NULL_PTR);
      }
#  endif
    }
# endif

# if ((KEYM_SERVICECERTIFICATECALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_OFF) && (KEYM_RTECALLBACKNOTIFICATION == STD_OFF))
  KEYM_DUMMY_STATEMENT(serviceResult); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  }
}
#endif /* ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING */

#ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyCallbackNotification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_VerifyCallbackNotification(void)
{
  /* ----- Implementation ----------------------------------------------- */
  if (KeyM_Cert_IsCertRequestEqualTo(KEYM_CERT_REQUEST_VERIFY))
  {
    /* # Call certificate verify callback notification for application */
# if (KEYM_CERTIFICATEVERIFYCALLBACKNOTIFICATIONIDXOFCERTIFICATE == STD_ON)
    if (KeyM_IsCertificateVerifyCallbackNotificationUsedOfCertificate((KeyM_CertificateIterType)KeyM_Cert_CertId))
    {
      KeyM_SizeOfCertificateVerifyCallbackNotificationType callbackIdx;
      KeyM_CertificateVerifyCallbackNotificationFctPtrType callbackFunction;

      callbackIdx = KeyM_GetCertificateVerifyCallbackNotificationIdxOfCertificate((KeyM_CertificateIterType)KeyM_Cert_CertId);
      /*@ assert callbackIdx < KeyM_GetSizeOfCertificateVerifyCallbackNotification(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

      callbackFunction = KeyM_GetCertificateVerifyCallbackNotification(callbackIdx);

#  ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
      /* VCA does not analyze customer-provided callbacks. The API contract for customer-provided callbacks is
       * annotated in the VCA stub. So no problems can arise with customer-provided callbacks if they uphold the
       * API contract. */
      callbackFunction = &Vcastub_Appl_CertificateVerifyCallbackNotification;
#  endif

      (void)callbackFunction(KeyM_Cert_CertId, KeyM_Cert_GetStatusInfo(KeyM_Cert_CertId));
    }
    else
# endif
    {
# if (KEYM_RTECALLBACKNOTIFICATION == STD_ON)
      if (KeyM_IsRteCallbackNotificationUsedOfCertificate((KeyM_CertificateIterType)KeyM_Cert_CertId))
      {
        KeyM_SizeOfRteCallbackNotificationType callbackIdx;
        KeyM_CertificateVerifyRteCallbackNotificationFctPtrType callbackFunction;

        callbackIdx = KeyM_GetRteCallbackNotificationIdxOfCertificate((KeyM_CertificateIterType)KeyM_Cert_CertId);
        /*@ assert callbackIdx < KeyM_GetSizeOfRteCallbackNotification(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

        callbackFunction = KeyM_GetCertificateVerifyOfRteCallbackNotification(callbackIdx);

#  ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
        /* VCA does not analyze customer-provided callbacks. The API contract for customer-provided callbacks is
       * annotated in the VCA stub. So no problems can arise with customer-provided callbacks if they uphold the
       * API contract. */
        callbackFunction = &Vcastub_Appl_CertificateVerifyRteCallbackNotification;
#  endif

        (void)callbackFunction(KeyM_Cert_GetStatusInfo(KeyM_Cert_CertId));
      }
# endif
    }
  }
}
#endif /* ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING */

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyGroupCallbackNotification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_VerifyGroupCallbackNotification(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Check if certificate group identifier is valid */
  if (KeyM_Cert_GroupInfo.groupId < KeyM_GetSizeOfCertificateGroupExt())
  {
#  if (KEYM_CERTIFICATEGROUPVERIFYCALLBACKNOTIFICATIONIDXOFCERTIFICATEGROUP == STD_ON)
    KeyM_CertificateGroupIterType subGroupIdx = (KeyM_CertificateGroupIterType)KeyM_GetCertificateGroupStartIdxOfCertificateGroupExt((KeyM_CertificateGroupExtIterType)KeyM_Cert_GroupInfo.groupId);
    if (KeyM_IsCertificateGroupVerifyCallbackNotificationUsedOfCertificateGroup(subGroupIdx))
    {
      KeyM_SizeOfCertificateGroupVerifyCallbackNotificationType callbackIdx;
      KeyM_CertificateGroupVerifyCallbackNotificationFctPtrType callbackFunction;

      callbackIdx = KeyM_GetCertificateGroupVerifyCallbackNotificationIdxOfCertificateGroup(subGroupIdx);
      /*@ assert callbackIdx < KeyM_GetSizeOfCertificateGroupVerifyCallbackNotification(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

      callbackFunction = KeyM_GetCertificateGroupVerifyCallbackNotification(callbackIdx);

#   ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
      /* VCA does not analyze customer-provided callbacks. The API contract for customer-provided callbacks is
       * annotated in the VCA stub. So no problems can arise with customer-provided callbacks if they uphold the
       * API contract. */
      callbackFunction = &Vcastub_Appl_CertificateGroupVerifyCallbackNotification;
#   endif

      (void)callbackFunction(KeyM_Cert_GroupInfo.groupId, KeyM_Cert_GroupInfo.groupStatus);
    }
#  endif
    /* # Reset certificate group info */
    KeyM_Cert_GroupInfo.groupId = KEYM_CERT_INVALID_ID;
    KeyM_Cert_GroupInfo.groupStatus = KEYM_CERT_VERIFY_GROUP_VALID;
  }
}
# endif /* ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING */
#endif

#ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateNotifyAppl()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateNotifyAppl(
  KeyM_ResultType serviceResult)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Call service certificate callback notification for application */
  KeyM_Cert_ServiceCertificateCallbackNotification(serviceResult);

  /* # Call certificate verify callback notification for application */
  KeyM_Cert_VerifyCallbackNotification(); /* PRQA S 2987 */ /* MD_KEYM_2.2 */

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
  /* # Call certificate group verification callback notification for application */
  KeyM_Cert_VerifyGroupCallbackNotification(); /* PRQA S 2987 */ /* MD_KEYM_2.2 */
# endif
}
#endif /* ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING */

#ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_StateNotify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 2 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_StateNotify(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  tKeyMCertTaskState localTaskState = KEYM_CERT_TASKSTATE_BUSY;
  KeyM_CertificateStatusType certStatus;
  boolean isVerificationTriggered = FALSE;
  KeyM_ResultType serviceResult = KEYM_RT_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* # Handling failure during state operation */
  certStatus = KeyM_Cert_GetStatusInfo(certId);

  /* Startup handling shall be not terminated if a single certificate could not be verified */
  if ((((certStatus != KEYM_CERTIFICATE_VALID) && (certStatus != KEYM_CERTIFICATE_PARSED_NOT_VALIDATED)) || (KeyM_GetCert_CertInfo((KeyM_Cert_CertInfoIterType)certId).csmRes != E_OK)) && ((!KeyM_Cert_ChainVerificationFlag) || (KeyM_Cert_RequestId == certId)))
  {
    KeyM_Cert_StateNotifyErrorHandling(certId, &localTaskState, &serviceResult);
  }
  /* No failure during state operation occurred */
  else
  {
    if (certStatus == KEYM_CERTIFICATE_PARSED_NOT_VALIDATED)
    {
      KeyM_Cert_SetStatusInfo(certId, KEYM_CERTIFICATE_VALID);
      certStatus = KEYM_CERTIFICATE_VALID;
    }

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
    if ((KeyM_Cert_GroupInfo.groupId < KeyM_GetSizeOfCertificateGroupExt()) && (certStatus != KEYM_CERTIFICATE_VALID))
    {
      KeyM_Cert_GroupInfo.groupStatus = KEYM_CERT_VERIFY_GROUP_INVALID;
      KeyM_Cert_InvalidateChildCertStatus(certId);
    }
# endif

    /* # Check if there are certificates in the chain that need to be validated */
    if (KeyM_Cert_HasVerifyChainLinks() && (certStatus == KEYM_CERTIFICATE_VALID)) /* If a certificate could not be verified successfully, the verification of the certificates in the same chain can be skipped */
    {
      KeyM_Cert_StateNotifyValidateChainIncomplete(&localTaskState, &serviceResult, &isVerificationTriggered);
    }
    /* # Check if there are other chains that need to be validated */
    else if (KeyM_Cert_HasLeafCertsToVerify())
    {
      KeyM_Cert_StateNotifyValidateChain(&localTaskState, &serviceResult, &isVerificationTriggered);
    }
    /* All certificates were verified */
    else
    {
      KeyM_Cert_StateNotifyFinish(&localTaskState, &serviceResult);
    }
  }

  if (!isVerificationTriggered)
  {
    /* # Notify application */
    KeyM_Cert_StateNotifyAppl(serviceResult);

    if (localTaskState == KEYM_CERT_TASKSTATE_IDLE) /* PRQA S 2991, 2995 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
    {
      KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certId)->request = (tKeyMCertRequestType)(KEYM_CERT_REQUEST_NOT_SET);

      SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
      KeyM_Cert_State = KEYM_CERT_STATE_IDLE;
      KeyM_Cert_TaskState = localTaskState;
      KeyM_Cert_RequestId = KEYM_CERT_INVALID_ID;
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
    }
  }

  return;
}
#endif /* ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING */

#if ((KEYM_CERTIFICATE_NVMBLOCK == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_CRE_APPL */
# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_Write_Req()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_Write_Req(
  KeyM_SizeOfNvmBlockType blockIdx)
{
  /* ----- Local Variables ------------------------------------------------ */
  boolean setBlockStatus = FALSE;

  /* ----- Implementation ------------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();
  /* # If idle trigger new request */
  if (KeyM_GetNvBlock_State(blockIdx) == KEYM_CERT_NVBLOCK_STATE_IDLE)
  {
    KeyM_SetNvBlock_State(blockIdx, KEYM_CERT_NVBLOCK_STATE_WRITE_REQ);
    setBlockStatus = TRUE;
  }
  /* # Otherwise set only flag for changed data .*/
  else
  {
    /* Set NvBlock state */
    KeyM_SetNvBlock_State(blockIdx, ((tKeyMCertNvBlockStateType)(KeyM_GetNvBlock_State(blockIdx) | (KEYM_CERT_NVBLOCK_STATE_MASK_DATA_CHANGE))));
  }
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

  if (setBlockStatus)
  {
    (void)KeyM_NvBlock_Trigger_Write_Req(blockIdx);
  }
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_State_Init()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_State_Init(
  KeyM_SizeOfNvmBlockType blockIdx)
{
  /* # Init State */
  KeyM_SetNvBlock_State(blockIdx, KEYM_CERT_NVBLOCK_STATE_IDLE);
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_Trigger_Write_Req()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Trigger_Write_Req(
  KeyM_SizeOfNvmBlockType blockIdx)
{
  Std_ReturnType retVal = E_NOT_OK, localRet;

  /* ----- Implementation ------------------------------------------------- */
  /* # Set Ram Block Status */
  localRet = NvM_SetRamBlockStatus((NvM_BlockIdType)KeyM_GetDescriptorRefOfNvmBlock(blockIdx), TRUE);

  /* # Trigger write request */
  if ((localRet == E_OK) && (KeyM_GetCertNvBlockProcessingOfNvmBlock(blockIdx) == KEYM_IMMEDIATE))
  {
    localRet = KeyM_NvM_WriteBlock((NvM_BlockIdType)KeyM_GetDescriptorRefOfNvmBlock(blockIdx), NULL_PTR);
  }

  /* # If an error occurred clear write requested bit mask in state. */
  if (localRet == E_OK)
  {
    retVal = E_OK;
  }
  else
  {
    SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();
    /* Clear NvBlock state */
    KeyM_SetNvBlock_State(blockIdx, ((tKeyMCertNvBlockStateType)(KeyM_GetNvBlock_State(blockIdx) & (KEYM_CERT_NVBLOCK_STATE_MASK_CLEAR_WRITE_REQUESTED))));
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();
  }
  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_State_CallbackWrittenToBlock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_State_CallbackWrittenToBlock(
  KeyM_SizeOfNvmBlockType blockIdx)
{
  /* ----- Local Variables ------------------------------------------------ */
  /* ----- Implementation ------------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();
  /* # Update state  */
  /* Clear NvBlock state */
  KeyM_SetNvBlock_State(blockIdx, ((tKeyMCertNvBlockStateType)(KeyM_GetNvBlock_State(blockIdx) & (KEYM_CERT_NVBLOCK_STATE_MASK_CLEAR_WRITE_COPIED))));
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_State_WrittenToBlock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_State_WrittenToBlock(
  KeyM_SizeOfNvmBlockType blockIdx)
{
  /* Update state if data is marked as changed. */
  if (((KeyM_GetNvBlock_State(blockIdx)) & (KEYM_CERT_NVBLOCK_STATE_MASK_DATA_CHANGE)) == (KEYM_CERT_NVBLOCK_STATE_MASK_DATA_CHANGE))
  {
    /* Set NvBlock state */
    KeyM_SetNvBlock_State(blockIdx, KEYM_CERT_NVBLOCK_STATE_COPY_DATA);
  }
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */
#endif /* ((KEYM_CERTIFICATE_NVMBLOCK == STD_ON) || (KEYM_CRE_APPL == STD_ON)) */

#if (KEYM_CERTIFICATE_NVMBLOCK == STD_ON)
# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_Persist()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_Persist(
  KeyM_CertificateIdType certId)
{
  /* # Check if certificate has an NvM block configured */
  if (KeyM_IsNvmBlockUsedOfCertificate((KeyM_CertificateIterType)certId))
  {
    KeyM_SizeOfNvmBlockType nvmBlockIdx = KeyM_GetNvmBlockIdxOfCertificate((KeyM_CertificateIterType)certId);
    /*@ assert nvmBlockIdx < KeyM_GetSizeOfNvmBlock(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

    /* # Set write request  */
    KeyM_NvBlock_Write_Req(nvmBlockIdx);
  }
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_WriteToBlock_Header()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_WriteToBlock_Header(
  uint16 certDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) NvMBufferPtr)
{
  /* ----- Local Variables ------------------------------------------------ */

  /* ----- Implementation ------------------------------------------------- */
  /* Version */
  NvMBufferPtr[KEYM_CERT_POS_NVBLOCK_VERSION] = KEYM_CERT_NVBLOCK_VERSION_0;

  /* Unspecified */
  NvMBufferPtr[KEYM_CERT_POS_NVBLOCK_UNSPECIFIED] = KEYM_CERT_NVBLOCK_UNSPECIFIED;

  /* Length */
  KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(certDataLength, &NvMBufferPtr[KEYM_CERT_POS_NVBLOCK_LENGTH]);
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_ReadFromBlock_Header()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_NvBlock_ReadFromBlock_Header(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) NvMBufferPtr)
{
  /* ----- Local Variables ------------------------------------------------ */
  boolean validHeader = TRUE;

  /* ----- Implementation ------------------------------------------------- */
  /* Version */
  if (NvMBufferPtr[KEYM_CERT_POS_NVBLOCK_VERSION] != KEYM_CERT_NVBLOCK_VERSION_0)
  {
    validHeader = FALSE;
  }

  return validHeader;
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_WriteToBlock_Copy()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteToBlock_Copy(
  KeyM_SizeOfCertificateType certIdx,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) NvMBufferPtr)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------- */
  /* # Check if certificate has an NvM block configured */
  if (KeyM_IsNvmBlockUsedOfCertificate(certIdx))
  {
    KeyM_SizeOfNvmBlockType nvmBlockIdx = KeyM_GetNvmBlockIdxOfCertificate(certIdx);
    /*@ assert nvmBlockIdx < KeyM_GetSizeOfNvmBlock(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */
    uint32 nvmDataLength;
    uint32 nvmBlockLength;
    KeyM_ConstCertDataType certData;

    /* Copy within exclusive area. Data might be being accessed by
     * - set certificate API  and similar */
    SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();

    certData = KeyM_Cert_GetCertificateReadBufferData(certIdx);
    nvmDataLength = KEYM_CERT_SIZEOF_NVBLOCK_HEADER + certData.certDataLength;  /* length of the data that shall be written to the block (certificate data + header) */
    nvmBlockLength = (uint32)KeyM_GetLengthOfNvmBlock(nvmBlockIdx);             /* length of the NvM block that data shall be written to */

    /* # Check if NvM block is large enough for the data that is about to be written */
    if (nvmBlockLength >= nvmDataLength)
    {
      /* # Update State */
      KeyM_NvBlock_State_WrittenToBlock(nvmBlockIdx);

      /* # Set header */
      KeyM_NvBlock_WriteToBlock_Header((uint16)certData.certDataLength, NvMBufferPtr); /* VCA_KEYM_NVBLOCK_WRITETOBLOCK_COPY_WRITEHEADER */

      /* # Copy certificate data to buffer */
      VStdLib_MemCpyLarge(&NvMBufferPtr[KEYM_CERT_SIZEOF_NVBLOCK_HEADER], certData.certData, certData.certDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_NVBLOCK_WRITETOBLOCK_COPY_WRITEDATA */

      /* # Clear remaining Bytes of Buffer to have a specified value */
      VStdLib_MemClr(&NvMBufferPtr[nvmDataLength], nvmBlockLength - nvmDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_NVBLOCK_WRITETOBLOCK_COPY_WRITEZEROS */

      retVal = E_OK;
    }
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();
  }

  return retVal;
} /* KeyM_NvBlock_WriteToBlock_Copy() */
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_ReadFromBlock_Copy()
 **********************************************************************************************************************/
/*!
 *
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
 */
/* PRQA S 6050 3 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFromBlock_Copy(
  KeyM_SizeOfCertificateType certIdx,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) NvMBufferPtr)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------- */
  /* # Check if certificate has an NvM block configured */
  if (KeyM_IsNvmBlockUsedOfCertificate(certIdx))
  {
    KeyM_SizeOfNvmBlockType nvmBlockIdx = KeyM_GetNvmBlockIdxOfCertificate(certIdx);
    /*@ assert nvmBlockIdx < KeyM_GetSizeOfNvmBlock(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */
    boolean validBlock = FALSE;
    KeyM_CertDataType ramBuffer;
    uint32 nvmBlockLength = (uint32)KeyM_GetLengthOfNvmBlock(nvmBlockIdx); /* length of the NvM block that data shall be written to */
    ramBuffer = KeyM_Cert_GetCertificateWriteBufferData(certIdx);

    retVal = E_OK;

    /* # Check that NvM block contains at least a header */
    if (nvmBlockLength >= KEYM_CERT_SIZEOF_NVBLOCK_HEADER) /* PRQA S 2991, 2995 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
    {
      /* # Init block state */
      KeyM_NvBlock_State_Init(nvmBlockIdx);

      /* # Check header */
      validBlock = KeyM_NvBlock_ReadFromBlock_Header(NvMBufferPtr);

      if (validBlock)
      {
        /* # Read stored certificate written length */
        uint16 certLength = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(&NvMBufferPtr[KEYM_CERT_POS_NVBLOCK_LENGTH]); /* VCA_KEYM_NVBLOCK_READFROMBLOCK_COPY_READHEADER */

        /* # Check if NvM block is long enough to hold the complete claimed certificate */
        /* # Check if RAM buffer is long enough to hold the certificate */
        if ((nvmBlockLength >= (KEYM_CERT_SIZEOF_NVBLOCK_HEADER + (uint32)certLength))  /* check that NvM block contains the whole claimed certificate data */
          && (ramBuffer.certDataLength >= certLength))                                  /* check that RAM buffer can hold the certificate data from the NvM block */
        {
          /* # Restore certificate from NvM block */
          /* no exclsuive area needed during startup phase */
          VStdLib_MemCpyLarge(ramBuffer.certData, &NvMBufferPtr[KEYM_CERT_SIZEOF_NVBLOCK_HEADER], certLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_NVBLOCK_READFROMBLOCK_COPY_COPYDATA */
          KeyM_Cert_SetCertificateWrittenLength(certIdx, (uint16)certLength);
          KeyM_Asn1_ClearCertificateElementStorage(certIdx);
          /* Set storage type */
          KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)(certIdx), (tKeyMCertStorageType)((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)certIdx)) | (KEYM_CERT_STORAGE_MASK_NVM | KEYM_CERT_STORAGE_MASK_DATA_BUFFER)));

          KeyM_Cert_SetStatusInfo(certIdx, KEYM_CERTIFICATE_NOT_PARSED);

          /* # Parse certificate */
          (void)KeyM_Cert_StateParseCert(certIdx);

          /* # Verify certificate elements */
          (void)KeyM_Cert_StateVerifyCertElements(certIdx);
        }
        else
        {
          validBlock = FALSE;
        }
      }
    }

    if (!validBlock)
    {
      /* Restore new init values for the given block. */
      (void)KeyM_NvBlock_Init(certIdx);
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */
#endif /* (KEYM_CERTIFICATE_NVMBLOCK == STD_ON) */

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_Persist_CRE()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_Persist_CRE(void)
{
  /* # Set write request  */
  KeyM_NvBlock_Write_Req(KEYM_GETNVMBLOCKIDXOFCRE);
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_WriteToBlock_Header_CRE()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_NvBlock_WriteToBlock_Header_CRE(
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) NvMBufferPtr)
{
  /* ----- Implementation ------------------------------------------------- */
  /* Version */
  NvMBufferPtr[KEYM_CERT_POS_NVBLOCK_CRE_VERSION] = KEYM_CERT_NVBLOCK_CRE_VERSION_0;

  /* Unspecified */
  NvMBufferPtr[KEYM_CERT_POS_NVBLOCK_CRE_UNSPECIFIED] = KEYM_CERT_NVBLOCK_CRE_UNSPECIFIED;

  /* Number of Entries */
  KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(KeyM_Cert_NumOfCRE, &NvMBufferPtr[KEYM_CERT_POS_NVBLOCK_CRE_NUMBER_OF_ENTRIES]);
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_ReadFromBlock_Header_CRE()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_NvBlock_ReadFromBlock_Header_CRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) NvMBufferPtr)
{
  /* ----- Local Variables ------------------------------------------------ */
  uint16 numOfEntries = 0u;
  boolean validHeader;

  /* ----- Implementation ------------------------------------------------- */

  numOfEntries = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(&NvMBufferPtr[KEYM_CERT_POS_NVBLOCK_CRE_NUMBER_OF_ENTRIES]);

  if (NvMBufferPtr[KEYM_CERT_POS_NVBLOCK_CRE_VERSION] != KEYM_CERT_NVBLOCK_CRE_VERSION_0)
  {
    validHeader = FALSE;
  }
  else if (numOfEntries > KEYM_CREMAX_NUMBER_OF_ENTRIES)
  {
    validHeader = FALSE;
  }
  else
  {
    validHeader = TRUE;
  }

  return validHeader;
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_WriteToBlock_Copy_CRE()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteToBlock_Copy_CRE(
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) NvMBufferPtr)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;
  uint32 nvmDataLength;
  KeyM_LengthOfNvmBlockType nvmBlockLength;

  /* Copy within exclusive area. Data might be being accessed by
   * - set certificate API  and similar */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();

  nvmDataLength = KEYM_CERT_SIZEOF_NVBLOCK_CRE_HEADER + (uint32)KeyM_GetSizeOfCREStorage();   /* length of the data that shall be written to the block (CREs + header) */
  nvmBlockLength = KeyM_GetLengthOfNvmBlock(KEYM_GETNVMBLOCKIDXOFCRE);                /* length of the NvM block that data shall be written to */

  /* ----- Implementation ------------------------------------------------- */
  /* # Check if NvM block is large enough for the data that is about to be written */
  if (nvmBlockLength >= nvmDataLength)
  {
    /* # Update State */
    KeyM_NvBlock_State_WrittenToBlock(KEYM_GETNVMBLOCKIDXOFCRE);

    /* # Set header */
    KeyM_NvBlock_WriteToBlock_Header_CRE(NvMBufferPtr);

    /* # Copy certificate data to buffer */
    VStdLib_MemCpyLarge(&NvMBufferPtr[KEYM_CERT_SIZEOF_NVBLOCK_CRE_HEADER], KeyM_GetAddrCREStorage(0u), KeyM_GetSizeOfCREStorage());  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

    /* # Clear remaining Bytes of Buffer to have a specified value */
    VStdLib_MemClr(&NvMBufferPtr[nvmDataLength], nvmBlockLength - nvmDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

    retVal = E_OK;
  }

  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

  return retVal;
} /* KeyM_NvBlock_WriteToBlock_Copy_CRE() */
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_ReadFromBlock_Copy_CRE()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 2 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFromBlock_Copy_CRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) NvMBufferPtr)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_OK;
  boolean validBlock = FALSE;
  uint32 nvmBlockLength = KeyM_GetLengthOfNvmBlock(KEYM_GETNVMBLOCKIDXOFCRE); /* length of the NvM block that data shall be written to */

  /* ----- Implementation ------------------------------------------------- */
  /* # Check that NvM block contains at least a header */
  if (nvmBlockLength >= KEYM_CERT_SIZEOF_NVBLOCK_CRE_HEADER)
  {
    /* # Init block state */
    KeyM_NvBlock_State_Init(KEYM_GETNVMBLOCKIDXOFCRE);

    /* # Check header */
    validBlock = KeyM_NvBlock_ReadFromBlock_Header_CRE(NvMBufferPtr);

    if (validBlock)
    {
      uint16 numberOfEntries = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(&NvMBufferPtr[KEYM_CERT_POS_NVBLOCK_CRE_NUMBER_OF_ENTRIES]);

      /* no exclsuive area needed during startup phase */
      VStdLib_MemCpyLarge(KeyM_GetAddrCREStorage(0u), &NvMBufferPtr[KEYM_CERT_SIZEOF_NVBLOCK_CRE_HEADER], KeyM_GetSizeOfCREStorage());  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      KeyM_Cert_NumOfCRE = numberOfEntries;
    }
  }

  if (!validBlock)
  {
    /* Restore new init values for the given block. */
    (void)KeyM_NvBlock_Init_CRE();
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */
#endif /* (KEYM_CRE_APPL == STD_ON) */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_Cert_CopyLowestCertId()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_CopyLowestCertId(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal;
  KeyM_CertificateIdType lowestCertId;

  /* ----- Implementation ------------------------------------------------- */
  /* # Consider only available certificates in the lowest chain hierarchy */
  if (!KeyM_Cert_IsLowerCertAvailable((KeyM_CertificateIdType)certId)) /* PRQA S 2991, 2995 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
  {
    /* # Check for incomplete chain */
    lowestCertId = (KeyM_CertificateIdType)certId;
    retVal = KeyM_Cert_CheckChainStorage(&lowestCertId);

    if (retVal == E_OK)
    {
      /* # Copy certificate Id to buffer for further verification */
      (void)KeyM_Cert_PushLeafCertToVerify(lowestCertId);
    }
  }
}
#endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_VERIFYCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_Cert_TriggerChainVerification()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050, 6080 1 */ /* MD_MSR_STMIF, MD_MSR_STCAL */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_TriggerChainVerification(void)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal;
  KeyM_CertificateIdType localCertId;
  KeyM_CertificateIdType upperCertId = 0u;
  uint8 localState = KEYM_CERT_STATE_IDLE;

  /* ----- Implementation ------------------------------------------------- */
  /* # Store Ids of certificates in the lowest hierarchy */
  localCertId = KeyM_Cert_PopLeafCertToVerify();

  retVal = KeyM_Cert_GetIssuerCertId(localCertId, &upperCertId);

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
  /* Check if optional issuer is available */
  if ((retVal != E_OK) && ((KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)localCertId) == KEYM_DYNAMIC_OPTIONAL_ISSUER) && (!(KeyM_Cert_UpperHierarachicalRefInfo[localCertId].isIssuerCertIdAvailable))))
  {
    upperCertId = localCertId;
    retVal = E_OK;
  }
# endif

  if (retVal == E_OK)
  {
    retVal = KeyM_Cert_IdentifyInvalidChain(&localCertId, &upperCertId);

    if (retVal == E_OK) /* PRQA S 2991, 2995 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
    {
      KeyM_Cert_ChainVerificationFlag = TRUE;

      /* # Trigger verification; retVal will always be E_OK, since KeyM_Cert_ChainVerificationFlag = TRUE */
      (void)KeyM_Cert_VerifyCertificatesProcess(localCertId, upperCertId, &localState);

      /* Set request type */
      KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)localCertId)->request = (tKeyMCertRequestType)(KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)localCertId)->request | (tKeyMCertRequestType)(KEYM_CERT_REQUEST_VERIFY));

      if (KeyM_Cert_StartUpState == KEYM_CERT_STARTUP_STATE_ACTIVE)
      {
        KeyM_Cert_State = localState;
        KeyM_Cert_CertId = localCertId;
      }
      else
      {
        /* Check if KeyM is currently busy with other jobs */
        SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
        if (KeyM_Cert_TaskState == KEYM_CERT_TASKSTATE_IDLE)
        {
          /* set all global data inside the critical section.
            * this function is used in KeyM_Cert_VerifyGroup, which is an external API
            * that may run in a different task than the KeyM main function. Setting all globals
            * in the critical section ensures that the important data for the state machine is all
            * set at once and the MainFunction will not mistakenly start the state machine while
            * the KeyM_Cert_CertId is not set yet */
          KeyM_Cert_TaskState = KEYM_CERT_TASKSTATE_BUSY;
          KeyM_Cert_State = localState;
          KeyM_Cert_CertId = localCertId;
        }
        else
        {
          retVal = KEYM_E_BUSY;
        }
        SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERT */

#ifndef KEYM_NOUNIT_STARTUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_Cert_ParseAvailableCertData()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_ParseAvailableCertData(
  P2CONST(boolean, AUTOMATIC, KEYM_APPL_DATA) certAvailable)
{
  /* ----- Local Variables ------------------------------------------------ */
  KeyM_CertificateIterType certIdx;
  KeyM_CertificateStatusType certStatus;

  /* ----- Implementation ------------------------------------------------- */
  /* # Iterate through configured certificates */
  for (certIdx = 0u; certIdx < KEYM_NUMBER_OF_CERTIFICATES; certIdx++)
  {
    certStatus = KeyM_Cert_GetStatusInfo((KeyM_CertificateIdType)certIdx);

    if (((certAvailable[certIdx]) || (KeyM_GetStorageOfCertificate((KeyM_CertificateIdType)certIdx) == KEYM_STORAGE_IN_ROM))
      && (certStatus == KEYM_CERTIFICATE_NOT_PARSED))
    {
      /* # Parse certificate */
      /* # Verify certificate elements */
      /* If a certificate can not be parsed, startup handling should be still continued
       * with other certificates. Return value is ignored. */
      (void)KeyM_Cert_ParseAndVerifyElements((KeyM_CertificateIdType)certIdx);
    }
  }
}
#endif /* ifndef KEYM_NOUNIT_STARTUPHANDLING */

#ifndef KEYM_NOUNIT_STARTUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_Cert_VerifyCertificatesAtStartUp()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyCertificatesAtStartUp(
  P2VAR(boolean, AUTOMATIC, KEYM_APPL_VAR) isStartUpTriggered)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_OK;  /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  KeyM_CertificateIterType certIdx;
  KeyM_CertificateStatusType certStatus;
  boolean certAvailable[KEYM_NUMBER_OF_CERTIFICATES];

  /* ----- Implementation ------------------------------------------------- */
  for (certIdx = 0u; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
  {
    certAvailable[certIdx] = !KeyM_Cert_IsCertSlotEmpty((KeyM_CertificateIdType)certIdx);
  }

  *isStartUpTriggered = FALSE;
  KeyM_Cert_ParseAvailableCertData(certAvailable);

  /* # Store Ids of certificates in the lowest hierarchy */
  for (certIdx = 0u; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
  {
    certStatus = KeyM_Cert_GetStatusInfo((KeyM_CertificateIdType)certIdx);

    /* Find lowest certificates in chain */
    if (((certAvailable[certIdx]) || (KeyM_GetStorageOfCertificate((KeyM_CertificateIdType)certIdx) == KEYM_STORAGE_IN_ROM))
      && (certStatus == KEYM_CERTIFICATE_PARSED_NOT_VALIDATED))
    {
      KeyM_Cert_CopyLowestCertId((KeyM_CertificateIdType)certIdx);

# if (KEYM_CERTCSMHASHJOBREFOFCERTIFICATE == STD_ON)
      if (KeyM_IsCertHashStorageUsedOfCertificate((KeyM_CertificateIdType)certIdx))
      {
        (void)KeyM_Cert_ComputeCertHash((KeyM_CertificateIdType)certIdx); /* VCA_KEYM_FUNCTION_REQUIREMENT_CHECKED */
      }
# endif
    }
  }

  /* # Trigger verification */
  if (KeyM_Cert_HasLeafCertsToVerify())
  {
    *isStartUpTriggered = TRUE;
    retVal = KeyM_Cert_TriggerChainVerification();
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_STARTUPHANDLING */

#if (KEYM_CSM_ASYNC_SIGNATURE_VERIFY == STD_ON)
# ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_HandleCsmCallback()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050, 6080 1 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_HandleCsmCallback(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult = E_NOT_OK; /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  boolean callbackOccurred = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
  if (KeyM_Cert_CallbackOccurred)
  {
    callbackOccurred = TRUE;
    KeyM_Cert_CallbackOccurred = FALSE;
    csmResult = KeyM_Cert_SignatureCallbackResult;
  }
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

  if (callbackOccurred)
  {
    if (csmResult == E_OK)
    {
      if (KeyM_GetCert_CertInfo((KeyM_Cert_CertInfoIterType)KeyM_Cert_CertId).verifyRes == CSM_E_VER_OK)
      {
        if (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)KeyM_Cert_CertId) == KEYM_CRL)
        {
          KeyM_Cert_SetStatusInfo(KeyM_Cert_CertId, KEYM_CERTIFICATE_VALID);
          KeyM_Cert_State = KEYM_CERT_STATE_STORE;
        }
        else
        {
          if (KeyM_Cert_IsCertRoot(KeyM_Cert_CertId))
          {
            KeyM_Cert_SetStatusInfo(KeyM_Cert_CertId, KEYM_CERTIFICATE_VALID);

            KeyM_Cert_TriggerStateAfterVerification(KeyM_Cert_CertId);
          }
          else
          {
            KeyM_Cert_State = KEYM_CERT_STATE_SET_KEY;
          }
        }
      }
      else
      {
        KeyM_Cert_SetStatusInfo(KeyM_Cert_CertId, KEYM_E_CERTIFICATE_SIGNATURE_FAIL);
        KeyM_Cert_State = KEYM_CERT_STATE_NOTIFY;
      }
    }
    else
    {
      KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)KeyM_Cert_CertId)->csmRes = (Crypto_VerifyResultType)(csmResult);
      KeyM_Cert_State = KEYM_CERT_STATE_NOTIFY;
    }

  }
}
# endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */
#endif /* KEYM_CSM_ASYNC_SIGNATURE_VERIFY */

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertAvailable()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertAvailable(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isCertAvailable;

  /* ----- Implementation ----------------------------------------------- */
  /* # If working certificate is not a ROM certificate, check certificate slot */
  if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)certId) == KEYM_STORAGE_IN_ROM)
  {
    isCertAvailable = TRUE;
  }
  else
  {
    isCertAvailable = !(KeyM_Cert_IsCertSlotEmpty(certId));
  }

  return isCertAvailable;
}
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ResetUpperHierarchicalRefInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_ResetUpperHierarchicalRefInfo(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_CertificateIterType certIdx;
  KeyM_CertificateIdType issuerCertId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Reset availability flag for referenced certificate */
  KeyM_Cert_UpperHierarachicalRefInfo[certId].isIssuerCertIdAvailable = FALSE;

  /* # Reset availability flag for certificates where the referenced certificate is an issuer */
  /* Iterate through all certificates */
  for (certIdx = 0u; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
  {
    if (KeyM_Cert_UpperHierarachicalRefInfo[certIdx].isIssuerCertIdAvailable)
    {
      issuerCertId = KeyM_Cert_UpperHierarachicalRefInfo[certIdx].issuerCertId;

      if (certId == issuerCertId)
      {
        KeyM_Cert_UpperHierarachicalRefInfo[certIdx].isIssuerCertIdAvailable = FALSE;
      }
    }
  }
}
# endif /* ifndef KEYM_NOUNIT_SETCERT */
#endif


#if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertIdSlotOwner()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertIdSlotOwner(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = TRUE;
  KeyM_CertificateIdType slotOwnerCertId;
  KeyM_IdOfCertificateSlotType slotId;
  KeyM_CertificateStatusType certStatus = KeyM_Cert_GetStatusInfo(certId);

  /* ----- Implementation ----------------------------------------------- */
  /* # If certificate shares a common slot and data is already installed, referenced certificate identifier
       needs to be validated against set slot owner. */
  if (KeyM_IsCertificateSlotUsedOfCertificate((KeyM_CertificateIterType)certId)
  && (certStatus != KEYM_CERTIFICATE_NOT_AVAILABLE))
  {
    KeyM_SlotRefIdxOfCertificateType slotIdx = KeyM_GetSlotRefIdxOfCertificate((KeyM_CertificateIterType)certId);
    /*@ assert slotIdx < KeyM_GetSizeOfCertificate(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

    /* # Determine corresponding certificate slot id for referenced certificate */
    slotId = KeyM_GetIdOfCertificateSlot(slotIdx);

    /* # Retrieve certificate identifier of slot owner */
    slotOwnerCertId = KeyM_GetSlotOwner((KeyM_SlotOwnerIterType)slotId);

    /* # Check if set certificate identifier of slot owner corresponds to referenced certificate identifier */
    if(slotOwnerCertId != certId)
    {
      retVal = FALSE;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */
#endif

#if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_SetSlotOwner()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_SetSlotOwner(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_IdOfCertificateSlotType slotId;

  /* ----- Implementation ----------------------------------------------- */
  /* # If certificate shares a common slot referenced certificate identifier is set as slot owner. */
  if (KeyM_IsCertificateSlotUsedOfCertificate((KeyM_CertificateIterType)certId))
  {
    KeyM_SlotRefIdxOfCertificateType slotIdx = KeyM_GetSlotRefIdxOfCertificate((KeyM_CertificateIterType)certId);
    /*@ assert slotIdx < KeyM_GetSizeOfCertificate(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

    /* # Determine corresponding certificate slot id for referenced certificate */
    slotId = KeyM_GetIdOfCertificateSlot(slotIdx);

    /* # Set certificate slot owner for referenced certificate */
    KeyM_SetSlotOwner((KeyM_SlotOwnerIterType)slotId, certId);
  }
}
# endif /* ifndef KEYM_NOUNIT_SHAREDCERTUTILS */
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CheckDynamicIssuer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CheckDynamicIssuer(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_CertificateIdType issuerCertId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if dynamic issuer is configured */
  if (KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)certId) != KEYM_PRESET_ISSUER)
  {
    /* # Determine issuer */
    retVal = KeyM_Cert_GetIssuerCertId(certId, &issuerCertId);

    if (((retVal == E_NOT_OK) && (KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)certId) != KEYM_DYNAMIC_OPTIONAL_ISSUER))
      || ((certId == issuerCertId) && (KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_DYNAMIC_MANDATORY_ISSUER)))
    {
      /* # Invalidate certificate status if dynamic issuer could not be determined or if self-signed certificate is not allowed */
      retVal = E_NOT_OK;
      KeyM_Cert_SetStatusInfo(certId, KEYM_CERTIFICATE_INVALID);
    }
    else
    {
      retVal = E_OK;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING */
#endif

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsReferenceElementFound()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsReferenceElementFound(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, KEYM_APPL_VAR) ElementIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;
  KeyM_CertificateElementIterType i;
  KeyM_SizeOfCertificateElementType elementIdxLocal = 0u;
  KeyM_CertificateStructureType localCertStructure = CertStructure;

  /* ----- Implementation ----------------------------------------------- */
  /* # For constructed elements, iterate through subelements */
  if ((localCertStructure == KEYM_CERTIFICATE_SUBJECT_NAME) || (localCertStructure == KEYM_CERTIFICATE_ISSUER_NAME) || (localCertStructure == KEYM_CERTIFICATE_EXTENSION))
  {
    /* # Get last configured element */
    for (i = KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)CertId); i < KeyM_GetCertificateElementEndIdxOfCertificate((KeyM_CertificateIterType)CertId); i++)
    {
      /*@ assert i < KeyM_GetSizeOfCertificateElement(); */

      if (KeyM_GetOfStructureOfCertificateElement(i) == localCertStructure)
      {
        elementIdxLocal = (KeyM_SizeOfCertificateElementType)i;
        retVal = TRUE;
      }
    }
    /*@ assert elementIdxLocal < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_CERT_ISREFERENCEELEMENTFOUND_ELEMENTIDXLOCAL */
  }
  else
  {
    retVal = KeyM_Cert_SearchElementByStructureType(CertId, (KeyM_OfStructureOfCertificateElementType)localCertStructure, &elementIdxLocal);
  }

  if (((retVal == FALSE) || (!(KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdxLocal)).length > 0u)))  /* If element could not be found across configured elements or if element is optional and not parsed */
  && (localCertStructure == KEYM_CERTIFICATE_EXTENSION))                       /* and if it is an extension, then take public key element as reference element */
  {
    localCertStructure = KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY;
    retVal = KeyM_Cert_SearchElementByStructureType(CertId, (KeyM_OfStructureOfCertificateElementType)localCertStructure, &elementIdxLocal);
  }

  /* ensure that function always returns a valid element idx */
  /*@ assert elementIdxLocal < KeyM_GetSizeOfCertificateElement(); */
  /* # Return element index */
  *ElementIdx = elementIdxLocal;

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertStructureGetReference()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertStructureGetReference(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(KeyM_CertificateStructureType, AUTOMATIC, KEYM_APPL_VAR) CertStructureRef)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  boolean isStructureAvailable = FALSE;
  KeyM_SizeOfCertificateElementType elementIdxLocal = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Return reference structure */
  switch (CertStructure)
  {
  case KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID:
  {
    isStructureAvailable = KeyM_Cert_SearchElementByStructureType(CertId, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID, &elementIdxLocal);
    *CertStructureRef = KEYM_CERTIFICATE_SERIAL_NUMBER;
    break;
  }
  case KEYM_CERTIFICATE_ISSUER_NAME:
  {
    isStructureAvailable = KeyM_Cert_SearchElementByStructureType(CertId, KEYM_CERTIFICATE_ISSUER_NAME, &elementIdxLocal);
    *CertStructureRef = KEYM_CERTIFICATE_SIGNATURE_ALGORITHM_ID;
    break;
  }
  case KEYM_CERTIFICATE_VALIDITY_PERIOD:
  {
    isStructureAvailable = KeyM_Cert_SearchElementByStructureType(CertId, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_BEFORE, &elementIdxLocal);

    if(isStructureAvailable)
    {
      isStructureAvailable = KeyM_Cert_SearchElementByStructureType(CertId, KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER, &elementIdxLocal);
    }

    *CertStructureRef = KEYM_CERTIFICATE_ISSUER_NAME;
    break;
  }
  case KEYM_CERTIFICATE_SUBJECT_NAME:
  {
    isStructureAvailable = KeyM_Cert_SearchElementByStructureType(CertId, KEYM_CERTIFICATE_SUBJECT_NAME, &elementIdxLocal);
    *CertStructureRef = KEYM_CERTIFICATE_VALIDITY_PERIOD_NOT_AFTER;
    break;
  }
  case KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO:
  {
    isStructureAvailable = KeyM_Cert_SearchElementByStructureType(CertId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_PUBLIC_KEY_ALGORITHM, &elementIdxLocal);

    if(isStructureAvailable)
    {
      isStructureAvailable = KeyM_Cert_SearchElementByStructureType(CertId, KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY, &elementIdxLocal);
    }

    *CertStructureRef = KEYM_CERTIFICATE_SUBJECT_NAME;
    break;
  }
  case KEYM_CERTIFICATE_EXTENSION:
  {
    isStructureAvailable = KeyM_Cert_SearchElementByStructureType(CertId, KEYM_CERTIFICATE_EXTENSION, &elementIdxLocal);
    *CertStructureRef = KEYM_CERTIFICATE_SUBJECT_PUBLIC_KEY_INFO_SUBJECT_PUBLIC_KEY;
    break;
  }
  case KEYM_CERTIFICATE_SIGNATURE_ALGORITHM:
  {
    isStructureAvailable = KeyM_Cert_SearchElementByStructureType(CertId, KEYM_CERTIFICATE_SIGNATURE_ALGORITHM, &elementIdxLocal);
    *CertStructureRef = KEYM_CERTIFICATE_EXTENSION;
    break;
  }
  case KEYM_CERTIFICATE_SIGNATURE:
  {
    isStructureAvailable = KeyM_Cert_SearchElementByStructureType(CertId, KEYM_CERTIFICATE_SIGNATURE, &elementIdxLocal);
    *CertStructureRef = KEYM_CERTIFICATE_SIGNATURE_ALGORITHM;
    break;
  }
  default:
    /* Certificate structure not handled. */
    retVal = KEYM_E_PARAMETER_MISMATCH;
    break;
  }

  /* If passed structure type is valid but not available within certificate data, return with E_NOT_OK */
  if ((retVal == E_OK) && (!isStructureAvailable))
  {
    retVal = E_NOT_OK;
  }

  KEYM_DUMMY_STATEMENT(elementIdxLocal); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#if (KEYM_CERTCSMHASHJOBREFOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ComputeCertHash()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ComputeCertHash(
  KeyM_CertificateIdType certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Std_ReturnType csmResult;
  uint32 hashLength = (uint32)KeyM_GetCertHashStorageLengthOfCertificate((KeyM_CertificateIterType)certId);
  KeyM_SizeOfCertHashStorageType hashStorageStartIdx = KeyM_GetCertHashStorageStartIdxOfCertificate((KeyM_CertificateIterType)certId);
  /*@ assert hashStorageStartIdx < KeyM_GetSizeOfCertHashStorage(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION_WITH_REQUIREMENT */
  KeyM_ConstCertDataType certData;
  certData = KeyM_Cert_GetCertificateReadBufferData(certId);

  /* ----- Implementation ----------------------------------------------- */

  /* # Compute hash over certificate data */
  csmResult = Csm_Hash( /* VCA_KEYM_CERT_COMPUTECERTHASH_CSMHASH */
    KeyM_GetCertCsmHashJobRefOfCertificate((KeyM_CertificateIterType)certId),
    CRYPTO_OPERATIONMODE_SINGLECALL,
    certData.certData,
    certData.certDataLength,
    KeyM_GetAddrCertHashStorage(hashStorageStartIdx),
    &hashLength);

  if (csmResult == E_OK)
  {
    retVal = E_OK;
    KeyM_Cert_HashStatus[certId] = TRUE;
  }
  else
  {
    KeyM_Cert_HashStatus[certId] = FALSE;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SETCERT */
#endif

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_CERTIFICATESIGNINGREQUEST /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CsrInfoGenerate()
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
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CsrInfoGenerate(
  KeyM_CertificateIdType certId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) csrInfo,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) csrInfoLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CSRInfoType CsrInfoElements[KEYM_MAX_NUM_CERT_ELEMENTS] = { 0u };
  KeyM_CertElementIdType CsrInfoElementIds[KEYM_MAX_NUM_CERT_ELEMENTS] = { 0u };
  uint8 numOfReqObjects = 0;
  KeyM_CertificateStatusType certStatus = KeyM_Cert_GetStatusInfo(certId);

  /* ----- Implementation ----------------------------------------------- */

  /* # Check that no certificate is yet installed in the slot */
  if (certStatus != KEYM_CERTIFICATE_NOT_AVAILABLE)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* # Build csrInfo and elementIds parameters for later call to KeyM_Asn1_InitCSR */
    uint32 writtenLength = (uint32)KeyM_Cert_GetCertificateWrittenLength(certId);
    uint32 offset = 0u;
    uint8_least i;
    Std_ReturnType loopInternalRetVal = E_OK;
    KeyM_CertDataType ramBuffer;
    ramBuffer = KeyM_Cert_GetCertificateWriteBufferData(certId);

    /* # Iterate through CSR elements that are stored in certificate's RAM buffer; for each: */
    retVal = E_NOT_OK; /* make sure that control flow only continues after loop if loop exited via the break statement */
    for (i = 0u; (i < KEYM_MAX_NUM_CERT_ELEMENTS) && (loopInternalRetVal == E_OK); i++)
    {
      /* check that certificate buffer still contains one more CSR element */
      if ((offset + KEYM_CERT_CSR_POS_ELEMENTDATA) > writtenLength)
      {
        loopInternalRetVal = E_NOT_OK;
      }
      else
      {
        /* # Retrieve two-byte elementId from certificate storage */
        uint8 elementType = 0u;
        /* # Retrieve two-byte element dataLength from certificate storage */
        KeyM_CertElementIdType elementId = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(&ramBuffer.certData[offset]); /* VCA_KEYM_CERT_CSRINFOGENERATE_CONVERTUINT16 */
        /*  # Get two byte element dataLength from certificate storage */
        uint16 elementDataLength = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(&ramBuffer.certData[offset + KEYM_CERT_CSR_POS_ELEMENTLENGTH]); /* VCA_KEYM_CERT_CSRINFOGENERATE_CONVERTUINT16 */
        offset += KEYM_CERT_CSR_POS_ELEMENTDATA;

        /* # Retrieve elementType for the element by calling KeyM_Asn1_GetCsrElementType */
        loopInternalRetVal = KeyM_Asn1_GetCsrElementType(certId, elementId, &elementType);

        /* check that CSR element is completely contained within certificate storage */
        if (((offset + (uint32)elementDataLength) > writtenLength) || (loopInternalRetVal != E_OK))
        {
          loopInternalRetVal = E_NOT_OK;
        }
        else
        {
          /* # Save all retrieved info in csrInfo and elementIds parameters that are being built */
          CsrInfoElementIds[i] = elementId;
          CsrInfoElements[i].elementType = elementType;
          CsrInfoElements[i].dataLength = elementDataLength;
          CsrInfoElements[i].dataPtr = &ramBuffer.certData[offset];
          /*@ assert $lengthOf(CsrInfoElements[i].dataPtr) >= CsrInfoElements[i].dataLength; */ /* VCA_KEYM_CERT_CSRINFOGENERATE_CSRINFOELEMENTS */

          offset += elementDataLength;
          numOfReqObjects++;

          if (offset == writtenLength)
          {
            /* finished successfully */
            retVal = E_OK;
            break;
          }
        }
      }
    }
  }

  /* # Call KeyM_Asn1_InitCSR with built csrInfo and elementIds parameters to generate CSR data */
  if (retVal == E_OK)
  {
    /*@ assert certId < KeyM_GetSizeOfCertificate(); */
    /*@ assert CsrInfoElements != NULL_PTR; */
    retVal = KeyM_Asn1_InitCSR(certId, CsrInfoElements, CsrInfoElementIds, numOfReqObjects, csrInfo, csrInfoLength); /* VCA_KEYM_CERT_CSRINFOGENERATE_INITCSR */
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESIGNINGREQUEST */
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertificateSubjectEquals()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_CertificateSubjectEquals(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) subject,
  uint16 subjectLength)
{
  KeyM_SizeOfCertificateElementType subjectElementIdx = 0u;
  boolean result = FALSE;

  if (KeyM_Cert_IsCertElementFound(certId, KEYM_CERTIFICATE_SUBJECT_NAME, KEYM_CERT_X509_COMMONNAMEOIDDATA, KEYM_CERT_X509_COMMONNAMEOIDDATALENGTH, &subjectElementIdx))
  {
    result = KeyM_Utils_BufferCmp(KeyM_Cert_GetCertElementDataPointer(certId, subjectElementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(subjectElementIdx)).length, subject, subjectLength);
  }

  return result;
} /* KeyM_Cert_CertificateSubjectEquals() */
# endif /* ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING */

# ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_FindGroupCertificateBySubject()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_FindGroupCertificateBySubject(
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) subject,
  uint16 subjectLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certId)
{
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_GroupIndIterType groupIndIdx;

  /* Iterate through group certificates */
  for (groupIndIdx = KeyM_GetGroupIndIssuerStartIdxOfCertificateGroup((KeyM_CertificateGroupIterType)groupId); groupIndIdx < KeyM_GetGroupIndIssuerEndIdxOfCertificateGroup((KeyM_CertificateGroupIterType)groupId); groupIndIdx++)
  {
    KeyM_CertificateIdType localCertId = KeyM_GetCertificateIdxOfGroupInd(groupIndIdx);
    KeyM_CertificateStatusType certStatus = KeyM_Cert_GetStatusInfo(localCertId);

    /* Consider only parsed certificates */
    if ((certStatus == KEYM_CERTIFICATE_PARSED_NOT_VALIDATED) || (certStatus == KEYM_CERTIFICATE_VALID))
    {
      /* Check if subject matches */
      if (KeyM_Cert_CertificateSubjectEquals(localCertId, subject, subjectLength))
      {
        *certId = localCertId;
        retVal = E_OK;
        break;
      }
    }
  }

  return retVal;
} /* KeyM_Cert_FindGroupCertificateBySubject() */
# endif /* ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING */

# ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_GetDynamicIssuerCertId()
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
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetDynamicIssuerCertId(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) issuerCertId)
{
  Std_ReturnType retVal;
  /* defensive programming: set issuerCertIdLocal to a valid value in case user mistakenly uses it even though an error code is returned */
  KeyM_CertificateIdType issuerCertIdLocal = 0u;

  /* check if issuer is already present */
if (KeyM_Cert_UpperHierarachicalRefInfo[certId].isIssuerCertIdAvailable)
  {
    /* return present issuer */
    issuerCertIdLocal = KeyM_Cert_UpperHierarachicalRefInfo[certId].issuerCertId;
    retVal = E_OK;
  }
  else
  {
    KeyM_SizeOfCertificateElementType issuerElementIdx = 0u;

    /* check that certificate is available */
    retVal = KeyM_Cert_IsCertAvailable(certId) ? E_OK : E_NOT_OK;

    /* if certificate is not yet parsed, parse it */
    if (retVal == E_OK)
    {
      if (KeyM_Cert_GetStatusInfo(certId) == KEYM_CERTIFICATE_NOT_PARSED)
      {
        KeyM_ConstCertDataType certData;
        certData = KeyM_Cert_GetCertificateReadBufferData(certId);

        retVal = KeyM_Cert_Parse(certId, certData.certData, certData.certDataLength);
      }
    }

    /* extract certificate issuer name */
    if (retVal == E_OK)
    {
      retVal =
        KeyM_Cert_IsCertElementFound(certId, KEYM_CERTIFICATE_ISSUER_NAME, KEYM_CERT_X509_COMMONNAMEOIDDATA, KEYM_CERT_X509_COMMONNAMEOIDDATALENGTH, &issuerElementIdx)
        ? E_OK : E_NOT_OK;
    }

    /* search certificate's group for a certificate with that subject name */
    if (retVal == E_OK)
    {
      P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) subject = KeyM_Cert_GetCertElementDataPointer(certId, issuerElementIdx);
      uint16 subjectLength = KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(issuerElementIdx)).length;

      retVal = KeyM_Cert_FindGroupCertificateBySubject(KeyM_GetCertificateGroupIdxOfCertificate((KeyM_CertificateIterType)certId), subject, subjectLength, &issuerCertIdLocal);

      /* if none was found, check if certificate is its own issuer */
      if (retVal != E_OK)
      {
        if (KeyM_Cert_CertificateSubjectEquals(certId, subject, subjectLength))
        {
          retVal = E_OK;
          issuerCertIdLocal = certId;
        }
      }

    }

    /* set found group certificate as certificate's issuer */
    if (retVal == E_OK)
    {
      KeyM_Cert_UpperHierarachicalRefInfo[certId].issuerCertId = issuerCertIdLocal;
      KeyM_Cert_UpperHierarachicalRefInfo[certId].isIssuerCertIdAvailable = TRUE;
    }
  }

  /* check that function only return valid certificate IDs */
  /*@ assert issuerCertIdLocal < KeyM_GetSizeOfCertificate(); */
  *issuerCertId = issuerCertIdLocal;
  return retVal;
} /* KeyM_Cert_GetDynamicIssuerCertId() */
# endif /* ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING */
#endif

#ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_INTERNAL_STUB */
/**********************************************************************************************************************
 * KeyM_Asn1_GetDynamicIssuerCertIdVcaStub()
 *********************************************************************************************************************/
/*! \brief         Part of VCA stub implementation for KeyM_Cert_GetDynamicIssuerCertId
 *  \details       This is never active in productive code
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Asn1_GetDynamicIssuerCertIdVcaStub(void);

/**********************************************************************************************************************
 *  KeyM_Cert_GetDynamicIssuerCertIdVcaStub()
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
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetDynamicIssuerCertIdVcaStub(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) issuerCertId)
{
  /* check parameters passed to KeyM_Cert_GetDynamicIssuerCertId */
  /*@ assert certId < KeyM_GetSizeOfCertificate(); */
  /*@ assert issuerCertId != NULL_PTR; */

  /* invalidate all buffers that are potentially modified by KeyM_Cert_GetDynamicIssuerCertId to simulate its side-effects */
  KeyM_GetAddrCertStorage(0u)[$range(0u, KeyM_GetSizeOfCertStorage() - 1u)] = (uint8)$undef();
  KeyM_GetAddrCert_CertInfo(0u)[$range(0u, KeyM_GetSizeOfCert_CertInfo() - 1u)].sigProcessDataLength = (uint32)$undef();
  KeyM_GetAddrCert_CertInfo(0u)[$range(0u, KeyM_GetSizeOfCert_CertInfo() - 1u)].sigProcessDataPtr = (P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA))$undef();
  KeyM_GetAddrCert_CertInfo(0u)[$range(0u, KeyM_GetSizeOfCert_CertInfo() - 1u)].request = (tKeyMCertRequestType)$undef();
  KeyM_GetAddrCert_CertInfo(0u)[$range(0u, KeyM_GetSizeOfCert_CertInfo() - 1u)].verifyRes = (Crypto_VerifyResultType)$undef();
  KeyM_GetAddrCert_CertInfo(0u)[$range(0u, KeyM_GetSizeOfCert_CertInfo() - 1u)].csmRes = (Std_ReturnType)$undef();
  KeyM_Cert_PubKeyBuffer[$range(0u, KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH - 1u)] = (uint8)$undef();
  KeyM_Cert_SigBuffer[$range(0u, KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH - 1u)] = (uint8)$undef();
  KeyM_GetAddrCert_StorageType(0u)[$range(0u, KeyM_GetSizeOfCert_StorageType() - 1u)] = (tKeyMCertStorageType)$undef();
  KeyM_GetAddrElementStorageRef(0u)[$range(0u, KeyM_GetSizeOfElementStorageRef() - 1u)].offset = (KeyM_CertificateIdType)$undef();
  KeyM_GetAddrElementStorageRef(0u)[$range(0u, KeyM_GetSizeOfElementStorageRef() - 1u)].length = (boolean)$undef();

  /* invalidate potentially manipulated buffers that only exist in some configurations to simulate its side-effects */
# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON) /* COV_KEYM_VECTOR_CODE_ANALYZER_INTERNAL_STUB */
  KeyM_Cert_UpperHierarachicalRefInfo[$range(0u, KEYM_NUMBER_OF_CERTIFICATES - 1u)].issuerCertId = (KeyM_CertificateIdType)$undef();
  KeyM_Cert_UpperHierarachicalRefInfo[$range(0u, KEYM_NUMBER_OF_CERTIFICATES - 1u)].isIssuerCertIdAvailable = (boolean)$undef();
# endif
# if (KEYM_CERTHASHSTORAGE == STD_ON) /* COV_KEYM_VECTOR_CODE_ANALYZER_INTERNAL_STUB */
  KeyM_GetAddrCertHashStorage(0u)[$range(0u, KeyM_GetSizeOfCertHashStorage() - 1u)] = (uint8)$undef();
# endif

  /* invalidate potentially manipulated buffers that are local to Asn1 compilatioin unit */
  KeyM_Asn1_GetDynamicIssuerCertIdVcaStub();

  /* make realistic assumptions about the outputs of KeyM_Cert_GetDynamicIssuerCertId */
  *issuerCertId = (KeyM_CertificateIdType)$range(0, KeyM_GetSizeOfCertificate() - 1u);
  return (Std_ReturnType)$undef();
} /* KeyM_Cert_GetDynamicIssuerCertIdVcaStub() */
#endif

#ifndef KEYM_NOUNIT_STARTUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_TriggerStartUpHandling()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_TriggerStartUpHandling(void)
{
  boolean isStartingUp = KeyM_Cert_StartUpState == KEYM_CERT_STARTUP_STATE_IDLE;

  if (isStartingUp)
  {
    boolean isStartUpTriggered;
    Std_ReturnType retVal;

    KeyM_Cert_StartUpState = KEYM_CERT_STARTUP_STATE_ACTIVE;
    retVal = KeyM_Cert_VerifyCertificatesAtStartUp(&isStartUpTriggered);

    if ((retVal != E_OK) || (!isStartUpTriggered))
    {
      KeyM_Cert_StartUpState = KEYM_CERT_STARTUP_STATE_FINISHED;
      isStartingUp = FALSE;

      SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
      KeyM_Cert_TaskState = KEYM_CERT_TASKSTATE_IDLE;
      KeyM_Cert_State = KEYM_CERT_STATE_IDLE;
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
    }
  }

  return isStartingUp;
} /* KeyM_Cert_TriggerStartUpHandling() */
#endif /* ifndef KEYM_NOUNIT_STARTUPHANDLING */

#ifndef KEYM_NOUNIT_STATEMACHINECONTROL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ProcessCertificateState()
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
 */
/* PRQA S 6030, 6050 1 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_ProcessCertificateState(void)
{
  if (((KeyM_Cert_CertId) < KeyM_GetSizeOfCertificate()) && (KeyM_Cert_TaskState == KEYM_CERT_TASKSTATE_BUSY))
  {
    boolean continueProcessing = TRUE;
    tKeyMCertState oldState = KEYM_CERT_INVALID_STATE;

    while (continueProcessing && (KeyM_Cert_State != oldState))
    {
      Std_ReturnType substateHandlerRetVal = E_NOT_OK;

      oldState = KeyM_Cert_State;
      continueProcessing = FALSE;

      switch (KeyM_Cert_State)
      {
        case KEYM_CERT_STATE_IDLE:
        {
          substateHandlerRetVal = E_OK;
          /* Continue processing of state machine within same main function call */
          continueProcessing = TRUE;
          break;
        }
        case KEYM_CERT_STATE_INIT:
        {
          KeyM_Cert_StateInit(KeyM_Cert_CertId);
          substateHandlerRetVal = E_OK;
          continueProcessing = TRUE;
          break;
        }
        case KEYM_CERT_STATE_PARSE_CERT:
        {
          substateHandlerRetVal = KeyM_Cert_StateParseCert(KeyM_Cert_CertId);
          continueProcessing = FALSE;
          break;
        }
        case KEYM_CERT_STATE_VERIFY_CERT_ELEMENTS:
        {
          substateHandlerRetVal = KeyM_Cert_StateVerifyCertElements(KeyM_Cert_CertId);
          continueProcessing = TRUE;
          break;
        }
        case KEYM_CERT_STATE_CHECK_SUBJECT:
        {
          substateHandlerRetVal = KeyM_Cert_StateCheckSubject(KeyM_Cert_CertId);
          continueProcessing = TRUE;
          break;
        }
        case KEYM_CERT_STATE_CHECK_TIME_STAMP:
        {
          substateHandlerRetVal = KeyM_Cert_StateCheckTimeStamp(KeyM_Cert_CertId);
          continueProcessing = TRUE; /* PRQA S 2982 */ /* MD_KEYM_2.2 */
          break;
        }
        case KEYM_CERT_STATE_SET_KEY:
        {
          substateHandlerRetVal = KeyM_Cert_StateSetKey(KeyM_Cert_CertId);
          continueProcessing = TRUE;
          break;
        }
        case KEYM_CERT_STATE_VERIFY_SIGNATURE:
        {
          substateHandlerRetVal = KeyM_Cert_StateSignatureVerify(KeyM_Cert_CertId);
          /* Processing of state machine is not continued */
          continueProcessing = FALSE;
          break;
        }
        case KEYM_CERT_STATE_STORE:
        {
          substateHandlerRetVal = KeyM_Cert_StateStore(KeyM_Cert_CertId);
          continueProcessing = TRUE;
          break;
        }
        case KEYM_CERT_STATE_NOTIFY:
        {
          KeyM_Cert_StateNotify(KeyM_Cert_CertId);
          substateHandlerRetVal = E_OK;
          continueProcessing = TRUE;
          break;
        }
# if (KEYM_CSM_ASYNC_SIGNATURE_VERIFY == STD_ON)
        case KEYM_CERT_STATE_VERIFY_SIGNATURE_PENDING:
        {
          KeyM_Cert_HandleCsmCallback();
          substateHandlerRetVal = E_OK;
          break;
        }
# endif
        default:
        {
          /* invalid state; do nothing */
          break;
        }
      }

      if (substateHandlerRetVal != E_OK)
      {
        continueProcessing = FALSE;
        KeyM_Cert_State = KEYM_CERT_STATE_NOTIFY;
      }
    }
  }
} /* KeyM_Cert_ProcessCertificateState() */
#endif /* ifndef KEYM_NOUNIT_STATEMACHINECONTROL */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_PushLeafCertToVerify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_PushLeafCertToVerify(
  KeyM_CertificateIdType certId)
{
  /*@ assert KeyM_Cert_NumLeafCertsToVerify <= KeyM_GetSizeOfCert_LeafCertsToVerify(); */ /* VCA_KEYM_CERT_NUMLEAFCERTSTOVERIFY */
  boolean pushedCertId = FALSE;

  /* Check that stack still has room for the new CertId */
  if (KeyM_Cert_NumLeafCertsToVerify < KeyM_GetSizeOfCert_LeafCertsToVerify())
  {
    boolean alreadyPresentInStack = FALSE;
    KeyM_Cert_LeafCertsToVerifyIterType bufferIdx;

    /* Check if certificate identifier is already in the stack */
    for (bufferIdx = 0u; bufferIdx < KeyM_Cert_NumLeafCertsToVerify; bufferIdx++)
    {
      if (KeyM_GetCert_LeafCertsToVerify(bufferIdx) == certId)
      {
        alreadyPresentInStack = TRUE;
      }
    }

    if (!alreadyPresentInStack)
    {
      /* add new CertId on top of stack */

      /*@ assert certId < KeyM_GetSizeOfCertificate(); */
      KeyM_SetCert_LeafCertsToVerify(KeyM_Cert_NumLeafCertsToVerify, certId);
      KeyM_Cert_NumLeafCertsToVerify++;
      pushedCertId = TRUE;
    }
  }

  /*@ assert KeyM_Cert_NumLeafCertsToVerify <= KeyM_GetSizeOfCert_LeafCertsToVerify(); */
  return pushedCertId;
} /* KeyM_Cert_PushLeafCertToVerify() */
#endif /* KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_PopLeafCertToVerify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_Cert_PopLeafCertToVerify(void)
{
  /*@ assert KeyM_Cert_NumLeafCertsToVerify <= KeyM_GetSizeOfCert_LeafCertsToVerify(); */ /* VCA_KEYM_CERT_NUMLEAFCERTSTOVERIFY */
  KeyM_CertificateIdType poppedCertId = 0u;

  /* defensive programming: if no element is present in the stack, always return a valid CertId (0) */
  if (KeyM_Cert_HasLeafCertsToVerify())
  {
    poppedCertId = KeyM_GetCert_LeafCertsToVerify((KeyM_Cert_LeafCertsToVerifyIterType)KeyM_Cert_NumLeafCertsToVerify - 1u);
    KeyM_Cert_NumLeafCertsToVerify--;
  }

  /*@ assert poppedCertId < KeyM_GetSizeOfCertificate(); */ /* VCA_KEYM_CERT_LEAFCERTSTOVERIFY_ELEMENTS */
  /*@ assert KeyM_Cert_NumLeafCertsToVerify <= KeyM_GetSizeOfCert_LeafCertsToVerify(); */
  return poppedCertId;
} /* KeyM_Cert_PopLeafCertToVerify() */
#endif /* KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_HasLeafCertsToVerify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_HasLeafCertsToVerify(void)
{
  return KeyM_Cert_NumLeafCertsToVerify > 0u;
} /* KeyM_Cert_HasLeafCertsToVerify() */
#endif /* KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ClearLeafCertsToVerify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_ClearLeafCertsToVerify(void)
{
  KeyM_Cert_NumLeafCertsToVerify = 0u;
} /* KeyM_Cert_ClearLeafCertsToVerify() */
#endif /* KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_PushVerifyChainLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(boolean, KEYM_CODE) KeyM_Cert_PushVerifyChainLink(
  KeyM_CertificateIdType certId)
{
  /*@ assert KeyM_Cert_NumLinksInVerifyChain <= KeyM_GetSizeOfCert_VerifyChain(); */ /* VCA_KEYM_CERT_NUMLINKSINVERIFYCHAIN */
  boolean pushedCertId = FALSE;

  /* Check that stack still has room for the new CertId */
  if (KeyM_Cert_NumLinksInVerifyChain < KeyM_GetSizeOfCert_VerifyChain())
  {
    /* add new CertId on top of stack */

    /*@ assert certId < KeyM_GetSizeOfCertificate(); */
    KeyM_SetCert_VerifyChain(KeyM_Cert_NumLinksInVerifyChain, certId);
    KeyM_Cert_NumLinksInVerifyChain++;
    pushedCertId = TRUE;
  }

  /*@ assert KeyM_Cert_NumLinksInVerifyChain <= KeyM_GetSizeOfCert_VerifyChain(); */
  return pushedCertId;
} /* KeyM_Cert_PushVerifyChainLink() */
#endif /* KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_PopVerifyChainLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(KeyM_CertificateIdType, KEYM_CODE) KeyM_Cert_PopVerifyChainLink(void)
{
  /*@ assert KeyM_Cert_NumLinksInVerifyChain <= KeyM_GetSizeOfCert_VerifyChain(); */ /* VCA_KEYM_CERT_NUMLINKSINVERIFYCHAIN */
  KeyM_CertificateIdType poppedCertId = 0u;

  /* defensive programming: if no element is present in the stack, always return a valid CertId (0) */
  if (KeyM_Cert_HasVerifyChainLinks())
  {
    poppedCertId = KeyM_GetCert_VerifyChain((KeyM_Cert_VerifyChainIterType)KeyM_Cert_NumLinksInVerifyChain - 1u);
    KeyM_Cert_NumLinksInVerifyChain--;
  }

  /*@ assert poppedCertId < KeyM_GetSizeOfCertificate(); */ /* VCA_KEYM_CERT_VERIFYCHAIN_ELEMENTS */
  /*@ assert KeyM_Cert_NumLinksInVerifyChain <= KeyM_GetSizeOfCert_VerifyChain(); */
  return poppedCertId;
} /* KeyM_Cert_PopVerifyChainLink() */
#endif /* KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_HasVerifyChainLinks()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_HasVerifyChainLinks(void)
{
  return KeyM_Cert_NumLinksInVerifyChain > 0u;
} /* KeyM_Cert_HasVerifyChainLinks() */
#endif /* KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ClearVerifyChain()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Cert_ClearVerifyChain(void)
{
  KeyM_Cert_NumLinksInVerifyChain = 0u;
} /* KeyM_Cert_ClearVerifyChain() */
#endif /* KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_InitCertificateReadBufferData()
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
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Cert_InitCertificateReadBufferData(void)
{
  KeyM_CertificateIterType certIdx;

  /* initialize ReadDataBufferData for all configured certificates */
  for (certIdx = 0u; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
  {
    KeyM_ConstCertDataPointerType dataBufferPtr;
    uint32 dataBufferLength = 0u;

    dataBufferPtr = KeyM_GetAddrCertStorage(0u); /* PRQA S 2982 */ /* MD_KEYM_2.2 */

# if(KEYM_ROM_CERTIFICATES == STD_ON)
    if (KeyM_GetStorageOfCertificate(certIdx) == KEYM_STORAGE_IN_ROM)
    {
      /*@ assert KeyM_IsCertificateInitValueInfoUsedOfCertificate(certIdx); */ /* VCA_KEYM_CERT_INITCHECK01 */
      KeyM_CertificateInitValueInfoIdxOfCertificateType initValueInfoIdx = KeyM_GetCertificateInitValueInfoIdxOfCertificate(certIdx);
      /*@ assert initValueInfoIdx < KeyM_GetSizeOfCertificateInitValueInfo(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

      /* for ROM certificates, make sure the pointer points to the respective constant certificate data */
#  if (KEYM_CERTIFICATEINITVALUE == STD_ON)
      if (KeyM_IsCertificateInitValueUsedOfCertificateInitValueInfo(initValueInfoIdx))
      {
        KeyM_SizeOfCertificateInitValueType initValueStartIdx = KeyM_GetCertificateInitValueStartIdxOfCertificateInitValueInfo(initValueInfoIdx);
        /*@ assert initValueStartIdx < KeyM_GetSizeOfCertificateInitValue(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

        /* in case of pre-configured init-values, set the pointer to KeyM's InitValue const table */
        dataBufferPtr = (KeyM_ConstCertDataPointerType)KeyM_GetAddrCertificateInitValue(initValueStartIdx);
        dataBufferLength = (uint32)KeyM_GetCertificateInitValueLengthOfCertificateInitValueInfo(initValueInfoIdx);
        /*@ assert dataBufferPtr != NULL_PTR; */
        /*@ assert dataBufferLength <= $lengthOf(dataBufferPtr); */ /* VCA_KEYM_CSL03_LENGTHASSERTION */
      }
      else
#  endif
      {
#  if (KEYM_CERTIFICATEINITCALLOUT == STD_ON)
        if (KeyM_IsCertificateInitCalloutUsedOfCertificateInitValueInfo(initValueInfoIdx))
        {
          KeyM_CertificateInitCalloutIdxOfCertificateInitValueInfoType calloutIdx;
          KeyM_CertificateInitCalloutFctPtrType calloutFunction;
          KeyM_ConstCertDataType certInitValue;

          calloutIdx = KeyM_GetCertificateInitCalloutIdxOfCertificateInitValueInfo(initValueInfoIdx);
          /*@ assert calloutIdx < KeyM_GetSizeOfCertificateInitCallout(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

          calloutFunction = KeyM_GetCertificateInitCallout(calloutIdx);

#   ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
          /* VCA does not analyze customer-provided callbacks. The API contract for customer-provided callbacks is
           * annotated in the VCA stub. So no problems can arise with customer-provided callbacks if they uphold the
           * API contract. */
          calloutFunction = &Vcastub_Appl_CertificateInitCallout;
#   endif

          /* in case init callouts are configured, retrieve the ReadBufferPtr and length from the configured callout */
          calloutFunction((KeyM_CertificateIdType)certIdx, &certInitValue);
          dataBufferPtr = certInitValue.certData;
          dataBufferLength = certInitValue.certDataLength;
          /*@ assert dataBufferPtr != NULL_PTR; */
          /*@ assert dataBufferLength <= $lengthOf(dataBufferPtr); */ /* VCA_KEYM_CERT_INITVALUECALLOUT */
        }
#  endif
      }
    }
    else
# endif
    {
      /*@ assert KeyM_IsCertStorageUsedOfCertificate(certIdx); */ /* VCA_KEYM_CERT_INITCHECK02 */
      KeyM_SizeOfCertStorageType certStorageStartIdx = KeyM_GetCertStorageStartIdxOfCertificate(certIdx);
      /*@ assert certStorageStartIdx < KeyM_GetSizeOfCertStorage(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

      /* certificates that are not read-only have a RAM mirror. Use this RAM mirror as ReadDataBufferPtr */
      dataBufferPtr = (KeyM_ConstCertDataPointerType)KeyM_GetAddrCertStorage(certStorageStartIdx);
      dataBufferLength = KeyM_GetCertStorageLengthOfCertificate((KeyM_CertificateIdType)certIdx);
      /*@ assert dataBufferPtr != NULL_PTR; */
      /*@ assert dataBufferLength <= $lengthOf(dataBufferPtr); */ /* VCA_KEYM_CERT_USING_STORAGELENGTH */
    }

    /*@ assert dataBufferPtr != NULL_PTR; */
    /*@ assert dataBufferLength <= $lengthOf(dataBufferPtr); */ /* VCA_KEYM_REPEATED_ASSERTION */
    KeyM_GetAddrCommonCertData(certIdx)->certData = dataBufferPtr;
    KeyM_GetAddrCommonCertData(certIdx)->certDataLength = dataBufferLength;
  }

} /* KeyM_Cert_InitCertificateReadBufferData() */
#endif /* KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetCertificateReadBufferData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(KeyM_ConstCertDataType, KEYM_CODE) KeyM_Cert_GetCertificateReadBufferData(KeyM_CertificateIdType certId)
{
  /*@ assert certId < KeyM_GetSizeOfCertificate(); */ /* check parameter integrity */

  KeyM_ConstCertDataType readBufferData;
  readBufferData = KeyM_GetCommonCertData((KeyM_CommonCertDataIterType)certId);

  /*@ assert readBufferData.certData != NULL_PTR; */ /* VCA_KEYM_CERT_COMMONCERTDATA_READ */
  /*@ assert readBufferData.certDataLength <= $lengthOf(readBufferData.certData); */ /* VCA_KEYM_CERT_COMMONCERTDATA_READ */

# if(KEYM_ROM_CERTIFICATES == STD_ON)
  if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)certId) != KEYM_STORAGE_IN_ROM)
# endif
  {
    readBufferData.certDataLength = KeyM_Cert_GetCertificateWrittenLength(certId);
    /*@ assert readBufferData.certDataLength <= $lengthOf(readBufferData.certData); */ /* VCA_KEYM_CERT_GETCERTIFICATEREADBUFFERDATA_WRITTENLENGTH */
  }

  return readBufferData;
} /* KeyM_Cert_GetCertificateReadBufferData() */
#endif /* KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_SHAREDCERTUTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetCertificateWriteBufferData()
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
KEYM_LOCAL_INLINE FUNC(KeyM_CertDataType, KEYM_CODE) KeyM_Cert_GetCertificateWriteBufferData(KeyM_CertificateIdType certId)
{
  /*@ assert certId < KeyM_GetSizeOfCertificate(); */ /* check parameter integrity */

  KeyM_CertDataType writeBufferData;

  if (KeyM_IsCertStorageUsedOfCertificate((KeyM_CertificateIterType)certId))
  {
    KeyM_SizeOfCertStorageType certStorageStartIdx = KeyM_GetCertStorageStartIdxOfCertificate((KeyM_CertificateIterType)certId);
    /*@ assert certStorageStartIdx < KeyM_GetSizeOfCertStorage(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

    writeBufferData.certData = KeyM_GetAddrCertStorage(certStorageStartIdx);
    writeBufferData.certDataLength = KeyM_GetCertStorageLengthOfCertificate((KeyM_CertificateIterType)certId);
    /*@ assert writeBufferData.certData != NULL_PTR; */
    /*@ assert writeBufferData.certDataLength <= $lengthOf(writeBufferData.certData); */ /* VCA_KEYM_CERT_USING_STORAGELENGTH */
  }
  else
  {
    writeBufferData.certData = KeyM_GetAddrCertStorage(0u);
    writeBufferData.certDataLength = 0u;
    /*@ assert writeBufferData.certData != NULL_PTR; */
    /*@ assert writeBufferData.certDataLength <= $lengthOf(writeBufferData.certData); */
  }

  /*@ assert writeBufferData.certData != NULL_PTR; */
  /*@ assert writeBufferData.certDataLength <= $lengthOf(writeBufferData.certData); */ /* VCA_KEYM_REPEATED_ASSERTION */
  return writeBufferData;
} /* KeyM_Cert_GetCertificateReadBufferData() */
#endif /* KEYM_NOUNIT_SHAREDCERTUTILS */

#ifndef KEYM_NOUNIT_STATEMACHINERESULTHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertRequestEqualTo()
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
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertRequestEqualTo(tKeyMCertRequestType requestType)
{
  boolean retVal = FALSE;

  /* this check is used for justified assertions in other functions and should not be removed */
  if(requestType == KEYM_CERT_REQUEST_SERVICE)
  {
    if (KeyM_Cert_RequestId < KeyM_GetSizeOfCertificate())
    {
      retVal = (KeyM_GetCert_CertInfo((KeyM_Cert_CertInfoIterType)KeyM_Cert_RequestId).request & requestType)== requestType;
    }
  }
  else /* requestType == KEYM_CERT_REQUEST_VERIFY */
  {
    retVal = (KeyM_GetCert_CertInfo((KeyM_Cert_CertInfoIterType)KeyM_Cert_CertId).request & requestType) == requestType;
  }

  return retVal;
} /* KeyM_Cert_IsCertRequestEqualTo() */
#endif /* KEYM_NOUNIT_STATEMACHINERESULTHANDLING */

#if (KEYM_DEV_ERROR_DETECT == STD_ON)
# ifndef KEYM_NOUNIT_CERTGENERAL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_InitChecks()
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
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_InitChecks(void)
{
  KeyM_CertificateIterType certIdx;
  Std_ReturnType retVal = E_OK;

  for (certIdx = 0u; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
  {

#  if(KEYM_ROM_CERTIFICATES == STD_ON)
    /* INITCHECK01: If certificate storage is ROM, an InitValueInfo indirection must exist */
    if ((KeyM_GetStorageOfCertificate(certIdx) == KEYM_STORAGE_IN_ROM) && (!KeyM_IsCertificateInitValueInfoUsedOfCertificate(certIdx)))
    {
      retVal = E_NOT_OK;
    }
#  endif

    /* INITCHECK02: If certificate storage is not ROM, a CertStorage indirection must exist */
    if ((KeyM_GetStorageOfCertificate(certIdx) != KEYM_STORAGE_IN_ROM) && (!KeyM_IsCertStorageUsedOfCertificate(certIdx)))
    {
      retVal = E_NOT_OK;
    }

    /* INITCHECK03: If certificate has a CertStorage indirection, it must also have a CertStorageWrittenLength indirection and vice versa */
    if (KeyM_IsCertStorageUsedOfCertificate(certIdx) != KeyM_IsCertStorageWrittenLengthUsedOfCertificate(certIdx))
    {
      retVal = E_NOT_OK;
    }

    /* INITCHECK04: The CertificateElement 1:N indirection references no more than KEYM_MAX_NUM_CERT_ELEMENTS CertificateElements */
    if (KeyM_GetCertificateElementLengthOfCertificate(certIdx) > KEYM_MAX_NUM_CERT_ELEMENTS)
    {
      retVal = E_NOT_OK;
    }
  }

  return retVal;
} /* KeyM_Cert_InitChecks() */
# endif /* KEYM_NOUNIT_CERTGENERAL */
#endif

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetFirstStaticChecks()
 *********************************************************************************************************************/
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
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetFirstStaticChecks(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  boolean isCertSlotEmpty;
  KeyM_CertificateStatusType certStatus;
  boolean isCertElementAvailable;

  /* ----- Implementation ----------------------------------------------- */
  isCertSlotEmpty = KeyM_Cert_IsCertSlotEmpty(CertId);
  certStatus = KeyM_Cert_GetStatusInfo(CertId);;
  isCertElementAvailable = KeyM_Cert_IsCertElementAvailable(CertId, CertElementId, elementIdx);

  /* # Check if certificate element Id is invalid */
  if (!isCertElementAvailable)
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  /* # Check if element has iteration */
  else if (!KeyM_IsHasIterationOfCertificateElement(*elementIdx))
  {
    retVal = KEYM_E_KEY_CERT_INVALID;
  }
  /* # Check if certificate slot is empty */
  else if (isCertSlotEmpty && (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) != KEYM_STORAGE_IN_ROM))
  {
    retVal = KEYM_E_KEY_CERT_EMPTY;
  }
  /* # Check certificate status */
  else if (certStatus == KEYM_CERTIFICATE_INVALID)
  {
    retVal = KEYM_E_KEY_CERT_INVALID;
  }
  /* # Check if element is available */
  else if (KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(*elementIdx)).length == 0u)
  {
    /* Return value already set */
  }
  else
  {
    retVal = E_OK;
  }

  /*@ assert *elementIdx < KeyM_GetSizeOfCertificateElement(); */
  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetNextStaticChecks()
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
/* PRQA S 6080 4 */ /* MD_MSR_STMIF */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetNextStaticChecks(
  P2CONST(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  boolean isCertSlotEmpty;
  KeyM_CertificateStatusType certStatus;

  /* ----- Implementation ----------------------------------------------- */
  isCertSlotEmpty = KeyM_Cert_IsCertSlotEmpty(CertElementIterator->certId);
  certStatus = KeyM_Cert_GetStatusInfo(CertElementIterator->certId);

  /* # Check if certificate slot is empty */
  if (isCertSlotEmpty && (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)(CertElementIterator->certId)) != KEYM_STORAGE_IN_ROM))
  {
    retVal = KEYM_E_KEY_CERT_EMPTY;
  }
  /* # Check certificate status */
  else if (certStatus == KEYM_CERTIFICATE_INVALID)
  {
    retVal = KEYM_E_KEY_CERT_INVALID;
  }
  /* # Check if rootElementIdx identifies a valid element within the certificate */
  else if ((CertElementIterator->rootElementIdx < KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)(CertElementIterator->certId)))
        || (CertElementIterator->rootElementIdx >= KeyM_GetCertificateElementEndIdxOfCertificate((KeyM_CertificateIterType)(CertElementIterator->certId))))
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  else
  {
    /*@ assert CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_CERT_CERTELEMENTGETNEXTSTATICCHECKS_ROOTELEMENTIDX */

    /* # Check if element has iteration */
    if (!KeyM_IsHasIterationOfCertificateElement((KeyM_CertificateElementIterType)(CertElementIterator->rootElementIdx)))
    {
      retVal = KEYM_E_KEY_CERT_INVALID; /* SWS_KeyM_00148 */
    }
    /* # Check iteration status */
    else if ((CertElementIterator->iterationStatus == KEYM_CERT_ELEMENT_ITERATION_NOT_INITIALIZED) || (CertElementIterator->iterationStatus == KEYM_CERT_ELEMENT_ITERATION_INVALID))
    {
      /* Do nothing */
  }
    /* # Check validity of current iterator offset and length */
    /* # This check automatically implies that the element is available */
    else if ((CertElementIterator->offset + CertElementIterator->elementLength) >= ((uint16)KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(CertElementIterator->rootElementIdx)).length))
    {
      /* Do nothing */
    }
    else
    {
      retVal = E_OK;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertStructureGetInternal()
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
/* PRQA S 6030, 6050, 6080 5 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertStructureGetInternal(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertStructureData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertStructureDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_CertificateStructureType refStructure = 0u;
  KeyM_SizeOfCertificateElementType refElementIdx = 0u;
  uint16 structureOffset;
  KeyM_Asn1_ParamType asn1Param;
  uint16 structureLength;

  /* ----- Implementation ----------------------------------------------- */
  if ((CertStructure == KEYM_CERTIFICATE_VERSION_NUMBER) || (CertStructure == KEYM_CERTIFICATE_SERIAL_NUMBER))
  {
    /* # Primitive elements without constructed structure can be retrieved directly */
    retVal = KeyM_Cert_GetElementByStructureType(CertId, (KeyM_OfStructureOfCertificateElementType)CertStructure, CertStructureData, CertStructureDataLength); /* VCA_KEYM_CERT_CERTSTRUCTUREGET_GETELEMENTBYSTRUCTURETYPE */
  }
  else
  {
    /* # Get reference structure */
    retVal = KeyM_Cert_CertStructureGetReference(CertId, CertStructure, &refStructure);

    if (retVal == E_OK)
    {
      /* # Get reference element index */
      if (KeyM_Cert_IsReferenceElementFound(CertId, refStructure, &refElementIdx))
      {
        KeyM_ConstCertDataType certData;
        certData = KeyM_Cert_GetCertificateReadBufferData(CertId);

        /* # Get structure offset */
        structureOffset = KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)refElementIdx).offset + KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(refElementIdx)).length;

        /* # Initialize parser and read first TLV element to determine structure length */
        KeyM_Asn1_Init(&asn1Param, &certData.certData[structureOffset], (uint16)certData.certDataLength - structureOffset);
        retVal = KeyM_Cert_GetTL(&asn1Param);

        structureLength = asn1Param.last_tag_len + (asn1Param.last_tag_data_pos - asn1Param.last_tag_base_pos);

        if (retVal == E_OK)
        {
          if (*CertStructureDataLength < structureLength)
          {
            retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
          }
          else
          {
            /* # Copy structure data */
            VStdLib_MemCpyLarge(CertStructureData, &certData.certData[structureOffset], structureLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_CERTSTRUCTUREGET_MEMCPY */
            *CertStructureDataLength = structureLength;
          }
        }
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertificateElementGetCountStaticChecks()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6050, 6080 4 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertificateElementGetCountStaticChecks(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  boolean isCertElementAvailable;
  boolean isCertSlotEmpty;
  KeyM_CertificateStatusType certStatus;

  /* ----- Implementation ----------------------------------------------- */
  isCertElementAvailable = KeyM_Cert_IsCertElementAvailable(CertId, CertElementId, elementIdx);
  isCertSlotEmpty = KeyM_Cert_IsCertSlotEmpty(CertId);
  certStatus = KeyM_Cert_GetStatusInfo(CertId);

    /* # Check if certificate element Id is invalid */
  if (!isCertElementAvailable)
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  /* # Check if certificate slot is empty */
  else if (isCertSlotEmpty && (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) != KEYM_STORAGE_IN_ROM))
  {
    retVal = KEYM_E_KEY_CERT_EMPTY;
  }
  /* # Check certificate status */
  else if (certStatus == KEYM_CERTIFICATE_INVALID)
  {
    retVal = KEYM_E_KEY_CERT_INVALID;
  }
  /* # Check if certificate element has iteration */
  else if (!KeyM_IsHasIterationOfCertificateElement(*elementIdx))
  {
    retVal = E_NOT_OK;
  }
  /* # Check if element is available */
  else if (KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(*elementIdx)).length == 0u)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsCertElementAvailable()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertElementAvailable(
  KeyM_CertificateIdType certIdx,
  KeyM_CertElementIdType elementId,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdxPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;
  KeyM_CertificateElementIterType i;
  KeyM_SizeOfCertificateElementType elementIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through configured certificate elements */
  for (i = KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)certIdx); i < KeyM_GetCertificateElementEndIdxOfCertificate((KeyM_CertificateIterType)certIdx); i++)
  {
    /* # Return TRUE if certificate element Id matches with referenced one */
    if (KeyM_GetIdOfCertificateElement(i) == elementId)
    {
      elementIdx = (KeyM_SizeOfCertificateElementType)i;
      retVal = TRUE;
      break;
    }
  }

  /*@ assert elementIdx < KeyM_GetSizeOfCertificateElement(); */
  *elementIdxPtr = elementIdx;
  return retVal;
} /* KeyM_Cert_IsCertElementAvailable() */
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetFirstInitializeIterator()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6050 4 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetFirstInitializeIterator(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_CertificateStatusType certStatus;
  KeyM_Asn1_ParamType asn1Param;
  KeyM_SizeOfCertificateElementType elementIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  certStatus = KeyM_Cert_GetStatusInfo(CertId);

  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  if(!KeyM_Cert_IsCertIdSlotOwner(CertId))
  {
    retVal = E_NOT_OK;
  }
  else
# endif
  {
    /* if certificate is not yet parsed, parse it now */
    if (certStatus == KEYM_CERTIFICATE_NOT_PARSED)
    {
      retVal = KeyM_Cert_ParseAndVerifyElements(CertId);
    }
  }

  if (retVal == E_OK)
  {
    /* # Perform static checks */
    retVal = KeyM_Cert_CertElementGetFirstStaticChecks(CertId, CertElementId, &elementIdx);

    if (retVal == E_OK)
    {
      /* # Parse first element */
      KeyM_Asn1_Init(&asn1Param, KeyM_Cert_GetCertElementDataPointer(CertId, elementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length);
      retVal = KeyM_Cert_GetTL(&asn1Param);
      if (retVal == E_OK)
      {
        /* # Check validity of iterator offset and length */
        if (((uint16)asn1Param.last_tag_data_pos + (uint16)asn1Param.last_tag_len) > ((uint16)KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length))
        {
          retVal = E_NOT_OK;
        }
        else
        {
          /* # Initialize iterator */
          CertElementIterator->offset = (uint16)asn1Param.last_tag_data_pos;
          CertElementIterator->elementLength = (uint16)asn1Param.last_tag_len;
          CertElementIterator->rootElementIdx = elementIdx;
          CertElementIterator->iterationStatus = KEYM_CERT_ELEMENT_ITERATION_INITIALIZED;
          CertElementIterator->certId = CertId;
          /* these unjustified assertions are used in the argumentation for assertions justified with VCA_KEYM_CERT_CERTELEMENTFIRSTINITIALIZEITERATOR_RETURNED_E_OK */
          /*@ assert CertElementIterator->certId < KeyM_GetSizeOfCertificate(); */
          /*@ assert CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement(); */
        }
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetNextUpdateIterator()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 2 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetNextUpdateIterator(
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_ParamType asn1Param;

  /* ----- Implementation ----------------------------------------------- */
  /* # Perform static checks */
  retVal = KeyM_Cert_CertElementGetNextStaticChecks(CertElementIterator);

  if (retVal == E_OK)
  {
    /*@ assert CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_CERT_CERTELEMENTGETNEXTUPDATEITERATOR_ROOTELEMENTIDX */

    /* # Parse next element */
    KeyM_Asn1_Init(&asn1Param, &KeyM_Cert_GetCertElementDataPointer(CertElementIterator->certId, (KeyM_SizeOfCertificateElementType)CertElementIterator->rootElementIdx)[CertElementIterator->offset + CertElementIterator->elementLength], KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(CertElementIterator->rootElementIdx)).length);
    retVal = KeyM_Cert_GetTL(&asn1Param);
    if (retVal == E_OK)
    {
      /* # Check validity of new iterator offset and length */
      if (((CertElementIterator->offset + CertElementIterator->elementLength + (uint16)asn1Param.last_tag_data_pos) + (uint16)asn1Param.last_tag_len) > ((uint16)KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(CertElementIterator->rootElementIdx)).length))
      {
        retVal = E_NOT_OK;
      }
      else
      {
        /* # Update iterator */
        CertElementIterator->offset = CertElementIterator->offset + CertElementIterator->elementLength + (uint16)asn1Param.last_tag_data_pos;
        CertElementIterator->elementLength = (uint16)asn1Param.last_tag_len;
        CertElementIterator->iterationStatus = KEYM_CERT_ELEMENT_ITERATION_VALID;
        /* this unjustified assertion is used in the argumentation for a justified assertion in KeyM_Cert_CertElementGetNext */
        /*@ assert CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement(); */
      }
    }
  }
  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetNextCopyData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetNextCopyData(
  P2CONST(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check provided buffer length */
  if (*CertElementDataLength < CertElementIterator->elementLength)
  {
    retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
  }
  else
  {
    /* # Copy element */
    VStdLib_MemCpyLarge(CertElementData, &KeyM_Cert_GetCertElementDataPointer(CertElementIterator->certId, (KeyM_SizeOfCertificateElementType)CertElementIterator->rootElementIdx)[CertElementIterator->offset], CertElementIterator->elementLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_CERTELEMENTGETNEXTCOPYDATA_MEMCPY */
    *CertElementDataLength = CertElementIterator->elementLength;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#ifndef KEYM_NOUNIT_CERTGENERAL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Perform consistency check of configuration if applicable */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  retVal = KeyM_Cert_InitChecks();
  if (retVal == E_OK)
# else
  retVal = E_OK;
# endif
  {
    KeyM_CertificateIterType certIdx;
# if ((KEYM_CERTIFICATE_NVMBLOCK == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_CRE_APPL */
    KeyM_CertificateIterType blockIdx;
# endif
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
    KeyM_CertificateSlotIterType slotIdx;
# endif
    /* # Initialize global variables and buffers */
    KeyM_Asn1_InitElementStorage();

    KeyM_Cert_TaskState = KEYM_CERT_TASKSTATE_BUSY;
    KeyM_Cert_GlobalState = KEYM_CERT_TASKSTATE_IDLE;
    KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_IDLE;
    KeyM_Cert_State = KEYM_CERT_STATE_IDLE;
    KeyM_Cert_CertId = KEYM_CERT_INVALID_ID;
    KeyM_Cert_ClearVerifyChain();

# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
    KeyM_Cert_UpdateFlag = FALSE;
# endif
    KeyM_Cert_ChainVerificationFlag = FALSE;

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
    KeyM_Cert_GroupInfo.groupId = KEYM_CERT_INVALID_ID;
    KeyM_Cert_GroupInfo.groupStatus = KEYM_CERT_VERIFY_GROUP_VALID;
# endif

    KeyM_Cert_StartUpState = KEYM_CERT_STARTUP_STATE_IDLE;
    KeyM_Cert_RequestId = KEYM_CERT_INVALID_ID;
    KeyM_Cert_ClearLeafCertsToVerify();

# if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
    KeyM_Cert_NumOfCRE = 0u;
# endif

    KeyM_Cert_InitCertificateReadBufferData();

    for (certIdx = 0u; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
    {
      KeyM_Cert_SetCertificateWrittenLength((KeyM_CertificateIdType)certIdx, 0u);

      KeyM_Cert_PubKeyLength = 0u;
      KeyM_Cert_SigLength = 0u;

      if (KeyM_GetStorageOfCertificate(certIdx) == KEYM_STORAGE_IN_NVM)
      {
        KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)(certIdx), (tKeyMCertStorageType)(KEYM_CERT_STORAGE_MASK_DATA_BUFFER));
      }
      else if (KeyM_GetStorageOfCertificate(certIdx) == KEYM_STORAGE_IN_ROM)
      {
        KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)(certIdx), (tKeyMCertStorageType)(KEYM_CERT_STORAGE_MASK_ROM));
      }
      else
      {
        KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)(certIdx), (tKeyMCertStorageType)(KEYM_CERT_STORAGE_EMPTY));
      }

      KeyM_Cert_SetStatusInfo((KeyM_CertificateIdType)certIdx, KEYM_CERTIFICATE_NOT_AVAILABLE);
      KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certIdx)->request = (tKeyMCertRequestType)(KEYM_CERT_REQUEST_NOT_SET);

      KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certIdx)->sigProcessDataPtr = (P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA))(NULL_PTR);
      KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certIdx)->sigProcessDataLength = 0u;
      KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certIdx)->verifyRes = CSM_E_VER_NOT_OK;
      KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)certIdx)->csmRes = (Crypto_VerifyResultType)(E_OK);
# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
      KeyM_Cert_UpperHierarachicalRefInfo[certIdx].isIssuerCertIdAvailable = FALSE;
# endif
# if ((KEYM_CERTIFICATEINITVALUE == STD_ON) || (KEYM_CERTIFICATEINITCALLOUT == STD_ON))
      if (KeyM_IsCertificateInitValueInfoUsedOfCertificate(certIdx))
      {
        if (KeyM_GetStorageOfCertificate(certIdx) == KEYM_STORAGE_IN_RAM)
        {
          KeyM_Cert_LoadCertificateInitValue((KeyM_CertificateIdType)certIdx); /* VCA_KEYM_FUNCTION_REQUIREMENT_CHECKED */
        }
#  if(KEYM_ROM_CERTIFICATES == STD_ON)
        else if (KeyM_GetStorageOfCertificate(certIdx) == KEYM_STORAGE_IN_ROM)
        {
          /* Set storage type */
          KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)(certIdx), (tKeyMCertStorageType)((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)certIdx)) | (KEYM_CERT_STORAGE_MASK_ROM)));

          KeyM_Cert_SetStatusInfo((KeyM_CertificateIdType)certIdx, KEYM_CERTIFICATE_NOT_PARSED);
        }
        else
        {
          /* Do nothing */
        }
#  endif
      }
# endif

# if(KEYM_CERTCSMHASHJOBREFOFCERTIFICATE == STD_ON)
      /*! Certificate Hash Status */
      KeyM_Cert_HashStatus[certIdx] = FALSE;
# endif
    }
# if ((KEYM_CERTIFICATE_NVMBLOCK == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_CRE_APPL */
    for (blockIdx = 0u; blockIdx < KeyM_GetSizeOfNvmBlock(); blockIdx++)
    {
      KeyM_NvBlock_State_Init((KeyM_SizeOfCertificateType)blockIdx);
    }
# endif

# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
    /* Initialize certificate slot mapping array with invalid certificate identifier */
    for (slotIdx = 0u; slotIdx < KeyM_GetSizeOfSlotOwner(); slotIdx++)
    {
      KeyM_SetSlotOwner(slotIdx, KEYM_CERT_INVALID_ID);
    }
# endif
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_CERTGENERAL */

#ifndef KEYM_NOUNIT_CERTGENERAL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_Cert_MainFunction(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Process Start Up Handling */
  if (KeyM_Cert_TriggerStartUpHandling())
  {
    /* startup handling has been triggered in this main function cycle; do nothing else for now and wait for next main function */
  }
  else
  {
    /* # Process NvM handling  */
# if ((KEYM_CERTIFICATE_NVMBLOCK == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_CRE_APPL */
    KeyM_NvBlock_MainFunction();
# endif

    KeyM_Cert_ProcessCertificateState();
  }
} /* KeyM_Cert_MainFunction() */
#endif /* ifndef KEYM_NOUNIT_CERTGENERAL */

#if ((KEYM_CERTIFICATE_NVMBLOCK == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_CRE_APPL */
# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_MainFunction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_NvBlock_MainFunction(void)
{
  /* ----- Local Variables ------------------------------------------------ */
  KeyM_NvmBlockIterType blockIdx;

  /* ----- Implementation ------------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();
  /* # Check if write request need to be triggered for any block. */
  for (blockIdx = 0; blockIdx < KeyM_GetSizeOfNvmBlock(); blockIdx++)
  {
    if (KeyM_GetNvBlock_State(blockIdx) == KEYM_CERT_NVBLOCK_STATE_WRITE_REQ_PENDING)
    {
      KeyM_SetNvBlock_State(blockIdx, KEYM_CERT_NVBLOCK_STATE_WRITE_REQ);
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

      (void)KeyM_NvBlock_Trigger_Write_Req((KeyM_SizeOfNvmBlockType)blockIdx);

      SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();
    }
  }
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */
#endif /* (KEYM_CERTIFICATE_NVMBLOCK == STD_ON) */

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ServiceCertificateById()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 3673, 6060 7 */ /* MD_KEYM_8.13_DeactivateableFeature, MD_MSR_STPAR */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertificateById(
  KeyM_ServiceCertificateType Service,
  KeyM_CertificateIdType CertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Implementation ----------------------------------------------- */
  /* # Return error code if certificate is read-only */
  if (((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)CertId)) & (KEYM_CERT_STORAGE_MASK_ROM)) == (KEYM_CERT_STORAGE_MASK_ROM))
  {
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
    errorId = KEYM_E_WRITE_ACCESS_FAILED;
#  else
    /* retVal is still set to E_NOT_OK */
#  endif
  }
  else
  {
    /* # Dispatch requested service */
    switch (Service)
    {
#  if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
      case KEYM_SERVICE_CERT_REQUEST_CSR:
      {
        retVal = KeyM_Cert_ServiceRequestCSR(CertId, RequestData, RequestDataLength, ResponseData, ResponseDataLength);
        break;
      }
      case KEYM_SERVICE_CERT_UPDATE_SIGNED_CSR:
#  endif
      case KEYM_SERVICE_CERT_SET_ROOT:
      case KEYM_SERVICE_CERT_SET_INTERMEDIATE:
      {
        retVal = KeyM_Cert_ServiceCertSet(CertId, RequestData, RequestDataLength);
        break;
      }
      case KEYM_SERVICE_CERT_UPDATE_ROOT:
      case KEYM_SERVICE_CERT_UPDATE_INTERMEDIATE:
      {
        retVal = KeyM_Cert_ServiceCertUpdate(CertId, RequestData, RequestDataLength);
        break;
      }
      case KEYM_SERVICE_CERT_UPDATE_CRL:
      {
        retVal = KeyM_Cert_ServiceCertUpdate(CertId, RequestData, RequestDataLength);
        break;
      }
      default:
      {
        /* Do nothing */
        break;
      }
    }
  }

#  if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_OFF)
  KEYM_DUMMY_STATEMENT(ResponseData); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(ResponseDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_SERVICE_CERTIFICATE, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SETCERT */
#endif

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_CREHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_SetCRE()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_SetCRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if certificate revocation entry is already set */
  if (KeyM_Cert_IsCRESet(IssuerNameData, IssuerNameDataLength, SerialNumberData, SerialNumberDataLength))
  {
    retVal = E_OK;
  }
  else
  {
    /* # Append new certificate revocation entry */
    retVal = KeyM_Cert_AppendCRE(IssuerNameData, IssuerNameDataLength, SerialNumberData, SerialNumberDataLength);

    if (retVal == E_OK)
    {
      /* # Invalidate certificate status if certificate revocation entry matches with previously installed certificate */
      KeyM_Cert_UpdateCertStatusForCRE(IssuerNameData, IssuerNameDataLength, SerialNumberData, SerialNumberDataLength);
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_CREHANDLING */
#endif

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertStructureGet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6050 5 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertStructureGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertStructureData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertStructureDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_CertificateStatusType certStatus;
  boolean isCertSlotEmpty;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if certificate Id is invalid */
  if (CertId >= KeyM_GetSizeOfCertificate())
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  else if(!KeyM_Cert_IsCertIdSlotOwner(CertId))
  {
    retVal = E_NOT_OK;
  }
# endif
  else
  {
    /* no error yet, leave retVal at E_OK for now */
  }

  if (retVal == E_OK)
  {
    isCertSlotEmpty = KeyM_Cert_IsCertSlotEmpty(CertId);
    certStatus = KeyM_Cert_GetStatusInfo(CertId);

    /* if certificate is not yet parsed, parse it now */
    if (certStatus == KEYM_CERTIFICATE_NOT_PARSED)
    {
      retVal = KeyM_Cert_ParseAndVerifyElements(CertId);
      certStatus = KeyM_Cert_GetStatusInfo(CertId);
    }

    if (retVal == E_OK)
    {
      /* # Check if certificate slot is empty */
      if (isCertSlotEmpty && (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) != KEYM_STORAGE_IN_ROM))
      {
        retVal = KEYM_E_KEY_CERT_EMPTY;
      }
      /* # Check certificate status */
      else if (certStatus == KEYM_CERTIFICATE_INVALID)
      {
        retVal = KEYM_E_KEY_CERT_INVALID;
      }
      else
      {
        /* # Retrieve certificate structure */
        retVal = KeyM_Cert_CertStructureGetInternal(CertId, CertStructure, CertStructureData, CertStructureDataLength);
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_ServiceCertificate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6060 8 */ /* MD_MSR_STPAR */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertificate(
  KeyM_ServiceCertificateType Service,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  boolean isCertNameConfigured;
  KeyM_CertificateIdType localCertId;

  /* ----- Implementation ----------------------------------------------- */
#  if ((KEYM_OCSP == STD_ON) || ((KEYM_REMOTE_OCSPENABLED == STD_ON))) /* COV_REMOTE_OCSP */
  if (Service == KEYM_SERVICE_CERT_STATUS_OCSP)
  {
    retVal = KeyM_Cert_ServiceCertStatusOCSP(Service, CertNamePtr, CertNameLength, RequestData, RequestDataLength, ResponseData, ResponseDataLength);
  }
  else
#  endif
  {
    /* # Search name of referenced certificate in configuration */
    isCertNameConfigured = KeyM_Cert_SearchCert(CertNamePtr, CertNameLength, &localCertId);

    /* # Check certificate name */
    if (!isCertNameConfigured)
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # Redirect remote service request */
#  if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)localCertId) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectServiceCertificate(localCertId, Service, CertNamePtr, CertNameLength, RequestData, RequestDataLength, ResponseData, ResponseDataLength);
    }
#  endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    else
    {
      /* # Process requested service */
      retVal = KeyM_Cert_ServiceCertificateById(Service, localCertId, RequestData, RequestDataLength, ResponseData, ResponseDataLength);
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_SETCERT */
#endif

#ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_SetCertificate()
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
 */
/* PRQA S 6050, 6080 3 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_SetCertificate(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = KEYM_E_NO_ERROR;
  KeyM_CertDataType ramBuffer;
  ramBuffer = KeyM_Cert_GetCertificateWriteBufferData(CertId);

  /* ----- Implementation ----------------------------------------------- */
  if (KeyM_Cert_State == KEYM_CERT_STATE_IDLE)
  {
    /* # Check if CertId is invalid */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
    /* # Check for write access */
    else if (((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)CertId)) & (KEYM_CERT_STORAGE_MASK_ROM)) == (KEYM_CERT_STORAGE_MASK_ROM))
    {
      errorId = KEYM_E_WRITE_ACCESS_FAILED;
    }
# endif
    /* # Check if certificate data length is invalid */
    else if (ramBuffer.certDataLength < CertificateDataPtr->certDataLength)
    {
      retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
    }
    /* # Check certificate length */
    else if (CertificateDataPtr->certDataLength == 0u)
    {
      KeyM_Cert_SetStatusInfo(CertId, KEYM_CERTIFICATE_NOT_AVAILABLE);
      retVal = E_OK;
    }
    else
    {
      /* # Copy certificate to local buffer */
      /* Copy within exclusive area. Data might be being accessed by
       * - NVM copy callouts */
      SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();
      VStdLib_MemCpyLarge(ramBuffer.certData, CertificateDataPtr->certData, CertificateDataPtr->certDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_MEMCPY_WRITEBUFFER */
      KeyM_Cert_SetCertificateWrittenLength(CertId, (uint16)(CertificateDataPtr->certDataLength));
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();
      KeyM_Asn1_ClearCertificateElementStorage(CertId);
      /* Set storage type */
      KeyM_SetCert_StorageType((KeyM_Cert_StorageTypeIterType)(CertId), (tKeyMCertStorageType)((KeyM_GetCert_StorageType((KeyM_Cert_StorageTypeIterType)CertId)) | (KEYM_CERT_STORAGE_MASK_DATA_BUFFER | KEYM_CERT_STORAGE_MASK_DIRTY)));

      KeyM_Cert_SetStatusInfo(CertId, KEYM_CERTIFICATE_NOT_PARSED);

# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
    KeyM_Cert_SetSlotOwner(CertId);
# endif

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
      KeyM_Cert_ResetUpperHierarchicalRefInfo(CertId);
# endif

      /* # Parse certificate */
      /* # Verify certificate elements */
      retVal = KeyM_Cert_ParseAndVerifyElements(CertId);

# if (KEYM_CERTCSMHASHJOBREFOFCERTIFICATE == STD_ON)
      if ((retVal == E_OK) && (KeyM_IsCertHashStorageUsedOfCertificate((KeyM_CertificateIterType)CertId))) /* PRQA S 2995 */ /* MD_KEYM_2.2 */
      {
        retVal = KeyM_Cert_ComputeCertHash(CertId); /* VCA_KEYM_FUNCTION_REQUIREMENT_CHECKED */
      }
# endif
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_SET_CERTIFICATE, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_SETCERT */

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_SetCertificateInGroup()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050, 6080 5 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_SetCertificateInGroup(
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIdType localCertId = 0u;
  KeyM_CertificateIdType refCertId = 0u;
  KeyM_CertificateGroupIdType localGroupId = groupId;
  uint8 subjectCommonName[KEYM_CERTIFICATESUBJECTNAME_MAX_LENGTH] = { 0u };
  uint32 subjectCommonNameDataLength = KEYM_CERTIFICATESUBJECTNAME_MAX_LENGTH;
  KeyM_ConstCertDataType certificateData;

  /* ----- Implementation ----------------------------------------------- */
  /* # Map external group ID to internal group ID */
#  if (KEYM_ELEMENTOIDPRIMARYUSEDOFCERTIFICATEGROUP == STD_ON)
  if (KeyM_Cert_IsGroupHeterogeneous(localGroupId))
  {
    retVal = KeyM_Cert_GetSubGroupId(localGroupId, requestData, requestDataLength, &localGroupId);
  }
  else
#  endif
  {
    localGroupId = KeyM_GetCertificateGroupStartIdxOfCertificateGroupExt((KeyM_CertificateGroupExtIterType)localGroupId);
    retVal = E_OK; /* PRQA S 2982 */ /* MD_KEYM_2.2 */
  }

#  if (KEYM_ELEMENTOIDPRIMARYUSEDOFCERTIFICATEGROUP == STD_ON)
  if (retVal == E_OK)
#  endif
  {
    /* # Check if certificate data length is invalid */
    if (KeyM_Cert_IsCertDataLengthOfGroupInvalid(localGroupId, requestDataLength))
    {
      retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
    }
    else
    {
      /* # Extract subject common name from RequestData */
      retVal = KeyM_Cert_GetSubjectCommonName(requestData, requestDataLength, subjectCommonName, &subjectCommonNameDataLength);

      if (retVal == E_OK)
      {
        /* # Search subject common name in group */
        if (KeyM_Cert_SearchSubjectCommonNameDataInGroup(localGroupId, subjectCommonName, subjectCommonNameDataLength, &refCertId))
        {
          /* # Update certificate data */
          retVal = KeyM_Cert_ServiceCertUpdate(refCertId, requestData, requestDataLength);
          *certId = refCertId;
        }
        else
        {
          /* # Determine empty dynamic group slot */
          retVal = KeyM_Cert_GetEmptyGroupCertId(localGroupId, &localCertId);

          if (retVal == E_OK)
          {
            /*# Copy certificate identifier */
            *certId = localCertId;

            /* # Set certificate data */
            certificateData.certData = requestData;
            certificateData.certDataLength = requestDataLength;

            retVal = KeyM_Cert_SetCertificate(localCertId, &certificateData);
          }
        }
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING */
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetGroupCertId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetGroupCertId(
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) subjectCommonNameData,
  uint32 subjectCommonNameDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIdType localCertId = 0u;
  KeyM_CertificateGroupIterType groupIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* # Search subject common name in all sub groups */
  for (groupIdx = KeyM_GetCertificateGroupStartIdxOfCertificateGroupExt((KeyM_CertificateGroupExtIterType)groupId); groupIdx < KeyM_GetCertificateGroupEndIdxOfCertificateGroupExt((KeyM_CertificateGroupExtIterType)groupId); groupIdx++)
  {
    if (KeyM_Cert_SearchSubjectCommonNameDataInGroup((KeyM_CertificateGroupIdType)groupIdx, subjectCommonNameData, subjectCommonNameDataLength, &localCertId))
    {
      retVal = E_OK;
      *certId = localCertId;
      break;
    }
  }
  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING */
#endif

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetCertificate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertificate(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertDataType, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if CertId is invalid */
  if (CertId >= KeyM_GetSizeOfCertificate())
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  else if(!KeyM_Cert_IsCertIdSlotOwner(CertId))
  {
    retVal = E_NOT_OK;
  }
# endif
  else
  {
    KeyM_ConstCertDataType certDataLocal;
    certDataLocal = KeyM_Cert_GetCertificateReadBufferData(CertId);

    /* # Check availability of certificate data */
    if (certDataLocal.certDataLength == 0u)
    {
      retVal = KEYM_E_KEY_CERT_EMPTY;
    }
    /* # Check provided buffer length */
    else if (CertificateDataPtr->certDataLength < certDataLocal.certDataLength)
    {
      retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
    }
    else
    {
      /* # Copy certificate to provided buffer */
      /* no exclusive area since no interaction with NVM copy callout */
      VStdLib_MemCpyLarge(CertificateDataPtr->certData, certDataLocal.certData, certDataLocal.certDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_GETCERTIFICATE_MEMCPY */
      CertificateDataPtr->certDataLength = certDataLocal.certDataLength;
    }
  }
  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#ifndef KEYM_NOUNIT_VERIFYCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyCertificates()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyCertificates(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateIdType CertUpperId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  tKeyMCertState localState;

  /* ----- Implementation ----------------------------------------------- */
  /* # Process verification */
  retVal = KeyM_Cert_VerifyCertificatesProcess(CertId, CertUpperId, &localState);
  /* # Check if KeyM is currently busy with other jobs */
  if (retVal == E_OK)
  {
    /* Set request type */
    KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)CertId)->request = (tKeyMCertRequestType)(KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)CertId)->request | (tKeyMCertRequestType)(KEYM_CERT_REQUEST_VERIFY));

    SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
    if (KeyM_Cert_TaskState == KEYM_CERT_TASKSTATE_IDLE)
    {
      KeyM_Cert_TaskState = KEYM_CERT_TASKSTATE_BUSY;
      KeyM_Cert_State = localState;
      KeyM_Cert_CertId = CertId;
    }
    else
    {
      retVal =  KEYM_E_BUSY;
    }
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERT */

#ifndef KEYM_NOUNIT_VERIFYCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyCertificate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6080 2 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyCertificate(
  KeyM_CertificateIdType CertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType localCertId = CertId;
  KeyM_CertificateIdType certUpperId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  if (localCertId >= KeyM_GetSizeOfCertificate())
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  else
  {
    /* just to avoid further processing in state BUSY, locking is done by callee */
    if (KeyM_Cert_TaskState == KEYM_CERT_TASKSTATE_IDLE)
    {
      retVal = KeyM_Cert_GetIssuerCertId(localCertId, &certUpperId);

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
      /* Check if optional issuer is available */
      if ((retVal != E_OK) && ((KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)localCertId) == KEYM_DYNAMIC_OPTIONAL_ISSUER) && (!(KeyM_Cert_UpperHierarachicalRefInfo[localCertId].isIssuerCertIdAvailable))))
      {
        certUpperId = localCertId;
        retVal = E_OK;
      }
# endif

      if (retVal == E_OK)
      {
        /* Set request type */
        KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)localCertId)->request = (tKeyMCertRequestType)(KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)localCertId)->request | (tKeyMCertRequestType)(KEYM_CERT_REQUEST_VERIFY));

        /* # Identify invalid chain of certificates */
        retVal = KeyM_Cert_IdentifyInvalidChain(&localCertId, &certUpperId);

        if (retVal == E_OK) /* PRQA S 2991, 2995 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
        {
          retVal = KeyM_Cert_VerifyCertificates(localCertId, certUpperId);
        }
      }
    }
    else
    {
      retVal = KEYM_E_BUSY;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERT */

#ifndef KEYM_NOUNIT_VERIFYCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyCertificateChain()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 4 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyCertificateChain(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 NumberOfCertificates)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType localCertId = CertId;
  KeyM_CertificateIdType certUpperId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  if ((localCertId >= KeyM_GetSizeOfCertificate())
  || (NumberOfCertificates >= (KEYM_CERTIFICATE_CHAIN_MAX_DEPTH))
  || (NumberOfCertificates == 0u))
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  else
  {
    retVal = KeyM_Cert_GetIssuerCertId(localCertId, &certUpperId);

    if (retVal == E_OK)
    {
      if (KeyM_Cert_TaskState == KEYM_CERT_TASKSTATE_IDLE)
      {
        /* just to avoid further processing in state BUSY, locking is done by callee */
        KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)CertId)->request = (tKeyMCertRequestType)(KeyM_GetAddrCert_CertInfo((KeyM_Cert_CertInfoIterType)CertId)->request | (tKeyMCertRequestType)(KEYM_CERT_REQUEST_VERIFY));

        /* # Copy missing certificates to working databuffer */
        retVal = KeyM_Cert_ChainCpyToDataBuffer(certUpperId, certChainData, NumberOfCertificates);

        if (retVal == E_OK) /* PRQA S 2991, 2995 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
        {
          /* # Identify invalid chain of certificates */
          retVal = KeyM_Cert_IdentifyInvalidChain(&localCertId, &certUpperId);

          if (retVal == E_OK) /* PRQA S 2991, 2995 */ /* MD_KEYM_14.3, MD_KEYM_2.2 */
          {
            retVal = KeyM_Cert_VerifyCertificates(localCertId, certUpperId);
          }
        }
      }
      else
      {
        retVal = KEYM_E_BUSY;
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_VERIFYCERT */

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_VerifyGroup()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyGroup(
  KeyM_CertificateGroupIdType groupId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateGroupIterType groupIdx;
  KeyM_GroupIndIterType groupIndIdx;
  KeyM_CertificateIdType certId;
  boolean isCertSlotEmpty;

  /* ----- Implementation ----------------------------------------------- */
  KeyM_Cert_ClearLeafCertsToVerify();

  /* # Iterate through sub groups of external group */
  for (groupIdx = KeyM_GetCertificateGroupStartIdxOfCertificateGroupExt((KeyM_CertificateGroupExtIterType)groupId); groupIdx < KeyM_GetCertificateGroupEndIdxOfCertificateGroupExt((KeyM_CertificateGroupExtIterType)groupId); groupIdx++)
  {
    /* # Iterate through group certificates */
    for (groupIndIdx = KeyM_GetGroupIndCertStartIdxOfCertificateGroup(groupIdx); groupIndIdx < KeyM_GetGroupIndCertEndIdxOfCertificateGroup(groupIdx); groupIndIdx++)
    {
      certId = KeyM_GetCertificateIdxOfGroupInd(groupIndIdx);

      isCertSlotEmpty = KeyM_Cert_IsCertSlotEmpty(certId);

      if ((!isCertSlotEmpty) || (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)certId) == KEYM_STORAGE_IN_ROM))
      {
        /* # Find lowest certificates in chain */
        KeyM_Cert_CopyLowestCertId(certId);
      }
    }
  }

  /* # Trigger verification */
  if (KeyM_Cert_HasLeafCertsToVerify())
  {
    retVal = KeyM_Cert_TriggerChainVerification();

    if (retVal == E_OK)
    {
      KeyM_Cert_GroupInfo.groupId = groupId;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_DYNAMICGROUPHANDLING */
#endif

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertGetStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertGetStatus(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertificateStatusType, AUTOMATIC, KEYM_APPL_VAR) Status)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if certificate Id is invalid */
  if (CertId >= KeyM_GetSizeOfCertificate())
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  else if(!KeyM_Cert_IsCertIdSlotOwner(CertId))
  {
    retVal = E_NOT_OK;
  }
# endif
  else
  {
    /* Get status for referenced certificate */
    *Status = KeyM_Cert_GetStatusInfo(CertId);
    retVal = E_OK;
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGet()
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
/* PRQA S 6050, 6080 5 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  boolean isCertElementAvailable;
  KeyM_CertificateStatusType certStatus;
  boolean isCertSlotEmpty;
  KeyM_SizeOfCertificateElementType elementIdx = 0u;
  uint16 parsedElementLength;

  /* ----- Implementation ----------------------------------------------- */
  isCertElementAvailable = KeyM_Cert_IsCertElementAvailable(CertId, CertElementId, &elementIdx);
  parsedElementLength = KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length;
  isCertSlotEmpty = KeyM_Cert_IsCertSlotEmpty(CertId);
  certStatus = KeyM_Cert_GetStatusInfo(CertId);

  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  if(!KeyM_Cert_IsCertIdSlotOwner(CertId))
  {
    retVal = E_NOT_OK; /* PRQA S 2982 */ /* MD_KEYM_2.2 */
  }
  else
# endif
  {
    /* # Check if certificate element Id is invalid */
    if (!isCertElementAvailable)
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # Check if certificate slot is empty */
    else if (isCertSlotEmpty && (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) != KEYM_STORAGE_IN_ROM))
    {
      retVal = KEYM_E_KEY_CERT_EMPTY;
    }
    /* # Check provided buffer length */
    else if (*CertElementDataLength < parsedElementLength)
    {
      retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
    }
    else if ((certStatus == KEYM_CERTIFICATE_INVALID) || (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE))
    {
      retVal = KEYM_E_KEY_CERT_INVALID;
    }
    else
    {
      /* # Check if element is available */
      if (KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length > 0u)
      {
        /* # Copy certificate element data */
        VStdLib_MemCpyLarge(CertElementData, KeyM_Cert_GetCertElementDataPointer(CertId, elementIdx), parsedElementLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_CERTELEMENTGET_MEMCPY */
        *CertElementDataLength = parsedElementLength;
        retVal = E_OK;
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetByStructureType()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetByStructureType(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertData,
  uint32 CertDataLength,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_ParamType asn1Param;
  KeyM_Asn1_ParseType asn1Parse;
  KeyM_Asn1_ParamType asn1ParamDerived[KEYM_ASN1_PARSE_MAX_NESTING_LEVEL];

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if certificate data is available */
  if (CertDataLength == 0u)
  {
    retVal = KEYM_E_KEY_CERT_EMPTY;
  }
  else
  {
    /* # Setup ASN reader */
    KeyM_Asn1_Init(&asn1Param, CertData, (uint16)CertDataLength);

    /* # Init the parser */
    KeyM_Asn1_ParseInit(&asn1Parse, asn1ParamDerived, KEYM_ASN1_PARSE_MAX_NESTING_LEVEL); /* VCA_KEYM_CERT_PARSE_INIT */

    /* # Parse certificate data */

    /*@ assert CertElementData != NULL_PTR; */
    /*@ assert CertElementDataLength != NULL_PTR; */
    retVal = KeyM_Asn1_CertElementGetByStructureType(&asn1Parse, &asn1Param, CertStructure, CertElementData, CertElementDataLength); /* VCA_KEYM_CERT_CERTELEMENTGETBYSTRUCTURETYPE_ASN1CALL */
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetFirst()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6080 6 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetFirst(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Initialize iterator */
  retVal = KeyM_Cert_CertElementGetFirstInitializeIterator(CertId, CertElementId, CertElementIterator);

  if (retVal == E_OK)
  {
    /*@ assert CertElementIterator->certId < KeyM_GetSizeOfCertificate(); */ /* VCA_KEYM_CERT_CERTELEMENTFIRSTINITIALIZEITERATOR_RETURNED_E_OK */
    /*@ assert CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_CERT_CERTELEMENTFIRSTINITIALIZEITERATOR_RETURNED_E_OK */
    /* # Copy first element data to out parameters */
    retVal = KeyM_Cert_CertElementGetNextCopyData(CertElementIterator, CertElementData, CertElementDataLength);
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetNext()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6080 4 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetNext(
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  if(!KeyM_Cert_IsCertIdSlotOwner(CertElementIterator->certId))
  {
    retVal = E_NOT_OK;
  }
  else
# endif
  {
    /* # Advance iterator to next element */
    retVal = KeyM_Cert_CertElementGetNextUpdateIterator(CertElementIterator);

    if (retVal == E_OK)
    {
      /*@ assert CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_CERT_CERTELEMENTGETNEXT */
      /* # Copy certificate element data to out parameters */
      retVal = KeyM_Cert_CertElementGetNextCopyData(CertElementIterator, CertElementData, CertElementDataLength);
    }
    else
    {
      CertElementIterator->iterationStatus = KEYM_CERT_ELEMENT_ITERATION_INVALID;
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#if (KEYM_CERTIFICATE_NVMBLOCK == STD_ON)
# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_WriteToBlock()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteToBlock(
  KeyM_SizeOfCertificateType certIdx,
  P2VAR(void, AUTOMATIC, KEYM_APPL_VAR) NvMBuffer)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;  /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) NvMBufferPtr;
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if (NvMBuffer == NULL_PTR)
  {
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ------------------------------------------------- */
    /* # Check if certificate ID is valid */
    if (certIdx < KeyM_GetSizeOfCertificate())
    {
      /* # Copy certificate to buffer. */
      NvMBufferPtr = (P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR))NvMBuffer; /* PRQA S 0316 */ /* MD_KEYM_0316 */
      retVal = KeyM_NvBlock_WriteToBlock_Copy(certIdx, NvMBufferPtr);
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_NVBLOCK_WRITETOBLOCK, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_ReadFromBlock()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFromBlock(
  KeyM_SizeOfCertificateType certIdx,
  P2CONST(void, AUTOMATIC, KEYM_APPL_DATA) NvMBuffer)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;  /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) NvMBufferPtr;
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if (NvMBuffer == NULL_PTR)
  {
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ------------------------------------------------- */
    /* # Check if certificate ID is valid */
    if (certIdx < KeyM_GetSizeOfCertificate())
    {
      /* # Copy buffer to certificate storage. */
      NvMBufferPtr = (P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA))NvMBuffer; /* PRQA S 0316 */ /* MD_KEYM_0316 */
      retVal = KeyM_NvBlock_ReadFromBlock_Copy(certIdx, NvMBufferPtr);
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_NVBLOCK_READFROMBLOCK, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_Init()
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
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Init(
  KeyM_SizeOfCertificateType certIdx)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;  /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  else
#  endif
  {
    /* ----- Implementation ------------------------------------------------- */
    /* # Check if certificate ID is valid */
    if (certIdx < KeyM_GetSizeOfCertificate())
    {
      /* # Check if certificate has an NvM block configured */
      if (KeyM_IsNvmBlockUsedOfCertificate(certIdx))
      {
        KeyM_SizeOfNvmBlockType nvmBlockIdx = KeyM_GetNvmBlockIdxOfCertificate(certIdx);
        /*@ assert nvmBlockIdx < KeyM_GetSizeOfNvmBlock(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

        /* # Initialize certificate slot */
        KeyM_NvBlock_State_Init(nvmBlockIdx);

#  if ((KEYM_CERTIFICATEINITVALUE == STD_ON) || (KEYM_CERTIFICATEINITCALLOUT == STD_ON))
        if (KeyM_IsCertificateInitValueInfoUsedOfCertificate(certIdx))
        {
          KeyM_Cert_LoadCertificateInitValue(certIdx); /* VCA_KEYM_FUNCTION_REQUIREMENT_CHECKED */
        }
        else
#  endif
        {
          KeyM_Cert_SetCertificateWrittenLength((KeyM_CertificateIdType)certIdx, 0u);
          KeyM_Cert_SetStatusInfo((KeyM_CertificateIdType)certIdx, KEYM_CERTIFICATE_NOT_AVAILABLE);
        }

        retVal = E_OK;
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_NVBLOCK_INIT, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_Callback()
 **********************************************************************************************************************/
/*!
 *
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
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Callback(
  KeyM_SizeOfCertificateType certIdx,
  NvM_ServiceIdType ServiceId,
  NvM_RequestResultType JobResult)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;  /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  else
#  endif
  {
    /* ----- Implementation ------------------------------------------------- */
    retVal = E_OK;

    /* # Check if certificate ID is valid */
    if (certIdx < KeyM_GetSizeOfCertificate())
    {
      /* # Check if certificate has an NvM block configured */
      if (KeyM_IsNvmBlockUsedOfCertificate(certIdx))
      {
        KeyM_SizeOfNvmBlockType nvmBlockIdx = KeyM_GetNvmBlockIdxOfCertificate(certIdx);
        /*@ assert nvmBlockIdx < KeyM_GetSizeOfNvmBlock(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

        /* # Handle callback function for service api: */
        switch (ServiceId)
        {
          /* # NVM_WRITE_BLOCK and NVM_WRITE_ALL: */
          case KEYM_CERT_NVM_WRITE_BLOCK:
          case KEYM_CERT_NVM_WRITE_ALL:
          {
            /* # Call KeyM_NvBlock_State_CallbackWrittenToBlock */
            KeyM_NvBlock_State_CallbackWrittenToBlock(nvmBlockIdx);
            break;
          }
          /* # All other services: */
          default:
            /* # Service is unsupported */
            break;
        }
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_NVBLOCK_CALLBACK, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  KEYM_DUMMY_STATEMENT(JobResult); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */
#endif /* (KEYM_CERTIFICATE_NVMBLOCK == STD_ON) */

#if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_ReadFrom_CRE()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFrom_CRE(
  P2CONST(void, AUTOMATIC, KEYM_APPL_DATA) NvMBuffer)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;  /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) NvMBufferPtr = (P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA))NvMBuffer; /* PRQA S 0316 */ /* MD_KEYM_0316 */
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if (NvMBuffer == NULL_PTR)
  {
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ------------------------------------------------- */

    /* # Lock certificate for write access. */
    /* # Copy CRE to CRE storage. */
    retVal = KeyM_NvBlock_ReadFromBlock_Copy_CRE(NvMBufferPtr);
    /* # Release certificate for write access. */
  }
  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_NVBLOCK_READFROM_CRE, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_WriteTo_CRE()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteTo_CRE(
  P2VAR(void, AUTOMATIC, KEYM_APPL_VAR) NvMBuffer)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;  /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) NvMBufferPtr = (P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR))NvMBuffer; /* PRQA S 0316 */ /* MD_KEYM_0316 */
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if (NvMBuffer == NULL_PTR)
  {
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ------------------------------------------------- */
    /* # Copy CRE to buffer. */
    retVal = KeyM_NvBlock_WriteToBlock_Copy_CRE(NvMBufferPtr);
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_NVBLOCK_WRITETO_CRE, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_Init_CRE()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Init_CRE(void)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;  /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  else
#  endif
  {
    /* ----- Implementation ------------------------------------------------- */
    retVal = E_OK;
    /* no exclusive area since being during startup */
    KeyM_NvBlock_State_Init(KEYM_GETNVMBLOCKIDXOFCRE);
    VStdLib_MemClr(KeyM_GetAddrCREStorage(0), KeyM_GetSizeOfCREStorage()); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
  }
  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_NVBLOCK_INIT_CRE, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */

# ifndef KEYM_NOUNIT_NVMHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_NvBlock_Callback_CRE()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Callback_CRE(
  NvM_ServiceIdType ServiceId,
  NvM_RequestResultType JobResult)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;  /* PRQA S 2981 */ /* MD_KEYM_2.2 */
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  else
#  endif
  {
    /* ----- Implementation ------------------------------------------------- */
    retVal = E_OK;
    switch (ServiceId)
    {
    case KEYM_CERT_NVM_WRITE_BLOCK:
    case KEYM_CERT_NVM_WRITE_ALL:
    {
      KeyM_NvBlock_State_CallbackWrittenToBlock(KEYM_GETNVMBLOCKIDXOFCRE);
      break;
    }

    default:
      /* Service not handled. */
      break;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_NVBLOCK_CALLBACK_CRE, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  KEYM_DUMMY_STATEMENT(JobResult); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_NVMHANDLING */
#endif /* (KEYM_CRE_APPL == STD_ON) */

#ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_SearchCert()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(boolean, KEYM_CODE) KeyM_Cert_SearchCert(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) certNamePtr,
  uint32 certNameLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certId)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean found = FALSE;
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((certNamePtr == NULL_PTR) || (certId == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    KeyM_CertificateIterType certIdx;
    KeyM_CertificateIdType certIdLocal = 0u;

    /* ----- Implementation ----------------------------------------------- */
    /* # Iterate through configured certificates */
    for (certIdx = 0u; certIdx < KeyM_GetSizeOfCertificate(); certIdx++)
    {
      KeyM_SizeOfCertificateNameType intCertNameStartIdx = KeyM_GetCertificateNameStartIdxOfCertificate(certIdx);
      KeyM_SizeOfCertificateNameType intCertNameLength = KeyM_GetCertificateNameLengthOfCertificate(certIdx);

      /* # Compare certificate name */
      if (KeyM_Utils_BufferCmp(certNamePtr, certNameLength, KeyM_GetAddrCertificateName(intCertNameStartIdx), intCertNameLength))
      {
        /* # If name matches passed name, return certificate id */
        certIdLocal = (KeyM_CertificateIdType)certIdx;
        found = TRUE;
        break;
      }
    }

    *certId = certIdLocal;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CERT_SEARCHCERT, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return found;
}
#endif /* ifndef KEYM_NOUNIT_SETCERT */

#ifndef KEYM_NOUNIT_CERTGENERAL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_IsBusy()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, KEYM_CODE) KeyM_Cert_IsBusy(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isModuleBusy = TRUE;
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------- */
  /* no need to check for KeyM_Cert_GlobalState since no dependency to main function processing */
    if ((KeyM_Cert_TaskState == KEYM_CERT_TASKSTATE_IDLE) && (KeyM_Remote_TaskState == KEYM_REMOTE_TASKSTATE_IDLE))
    {
      isModuleBusy = FALSE;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CERT_ISBUSY, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return isModuleBusy;
}
#endif /* ifndef KEYM_NOUNIT_CERTGENERAL */



#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CertificateElementGetCount()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6050 4 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertificateElementGetCount(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) Count)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_CertificateStatusType certStatus;
  KeyM_SizeOfCertificateElementType elementIdx = 0u;
  KeyM_Asn1_ParamType asn1Param;
  uint16 numOfIterableElements = 0u;

  /* ----- Implementation ----------------------------------------------- */
  certStatus = KeyM_Cert_GetStatusInfo(CertId);

  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  if(!KeyM_Cert_IsCertIdSlotOwner(CertId))
  {
    retVal = E_NOT_OK;
  }
  else
# endif
  {
    /* if certificate is not yet parsed, parse it now */
    if (certStatus == KEYM_CERTIFICATE_NOT_PARSED)
    {
      retVal = KeyM_Cert_ParseAndVerifyElements(CertId);
    }
  }

  if (retVal == E_OK)
  {
    /* # Perform static checks */
    retVal = KeyM_Cert_CertificateElementGetCountStaticChecks(CertId, CertElementId, &elementIdx);

    if (retVal == E_OK)
    {
      /* # Initialize parser */
      KeyM_Asn1_Init(&asn1Param, KeyM_Cert_GetCertElementDataPointer(CertId, elementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length);

      /* # Iterate through element data and increment counter */
      while ((retVal == E_OK) && (asn1Param.remaining_len != 0u))
      {
        retVal = KeyM_Cert_GetTL(&asn1Param);
        KeyM_Asn1_NextTag(&asn1Param);
        numOfIterableElements++;
      }

      if (retVal == E_OK)
      {
        *Count = numOfIterableElements;
      }
      else
      {
        *Count = 0u;
      }
    }
  }

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_CERTIFICATESIGNINGREQUEST /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_InitCSR()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6060 7 */ /* MD_KEYM_6060_LOCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_InitCSR(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) CsrInfo,
  uint8 numOfReqObjects,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) ResponseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  boolean isCertNameConfigured;
  KeyM_CertificateIdType localCertId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Search name of referenced certificate in configuration */
  isCertNameConfigured = KeyM_Cert_SearchCert(CertNamePtr, CertNameLength, &localCertId);

  /* # Check certificate name */
  if (!isCertNameConfigured)
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  else
  {
    /* # Build ASN.1 CSR structure */
    /*@ assert localCertId < KeyM_GetSizeOfCertificate(); */
    /*@ assert CsrInfo != NULL_PTR; */
    /*@ assert ResponseData != NULL_PTR; */
    /*@ assert ResponseDataLength != NULL_PTR; */
    retVal = KeyM_Asn1_InitCSR(localCertId, CsrInfo, NULL_PTR, numOfReqObjects, ResponseData, ResponseDataLength); /* VCA_KEYM_CERT_INITCSR */
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESIGNINGREQUEST */
#endif

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_CERTIFICATESIGNINGREQUEST /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_CsrElementSet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050, 6080 6 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CsrElementSet(
  KeyM_CertificateIdType certId,
  KeyM_CertElementIdType certElementId,
  KeyM_CsrEncodingType encodingType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) elementData,
  uint32 elementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_SizeOfCertStorageType writtenLength;
  KeyM_CertificateStatusType certStatus;
  KeyM_SizeOfCertificateElementType elementIdx;
  boolean isAttribute;
  boolean isCertElementAvailable;
  boolean isCsrElementSet;
  uint16 csrElementOffset = 0u;
  uint16 csrElementDataLength = 0u;
  KeyM_CertDataType ramBuffer;
  ramBuffer = KeyM_Cert_GetCertificateWriteBufferData(certId);

  /* ----- Implementation ----------------------------------------------- */
  /* # Check validity of request */
  writtenLength = KeyM_Cert_GetCertificateWrittenLength(certId);
  certStatus = KeyM_Cert_GetStatusInfo(certId);
  isCertElementAvailable = KeyM_Cert_IsCertElementAvailable(certId, certElementId, &elementIdx);
  isCsrElementSet = KeyM_Cert_IsCsrElementSet(certId, certElementId, &csrElementOffset, &csrElementDataLength);

  /* Check if cert element with requested ID exists */
  if (!isCertElementAvailable)
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  else
  {
    retVal = KeyM_Asn1_IsCsrElementAttribute(elementIdx, &isAttribute);

    if (retVal != E_OK)
    {
      /* Could not determine whether the element is an attribute */
      retVal = KEYM_E_KEY_CERT_INVALID;
    }
    /* Check certificate status for certificate slot */
    else if (certStatus != KEYM_CERTIFICATE_NOT_AVAILABLE)
    {
      retVal = E_NOT_OK;
    }
    /* # Check whether CSR element needs to be updated */
    else if (isCsrElementSet)
    {
      retVal = KeyM_Cert_UpdateCsrElement(certId, csrElementOffset, csrElementDataLength, elementData, (uint16)elementDataLength);
    }
    /* Check for size mismatch */
    else if ((writtenLength + elementDataLength + KEYM_CERT_CSR_POS_ELEMENTDATA) > ramBuffer.certDataLength)
    {
      retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
    }
    /* Support only primitive subject names and attributes as well as encoded extension elements */
    else if (((KeyM_GetOfStructureOfCertificateElement(elementIdx) == KEYM_CERTIFICATE_SUBJECT_NAME) && (encodingType == KEYM_CSR_ENCODING_NONE))
      || ((KeyM_GetOfStructureOfCertificateElement(elementIdx) == KEYM_CERTIFICATE_EXTENSION) && (isAttribute) && (encodingType == KEYM_CSR_ENCODING_NONE))
      || ((KeyM_GetOfStructureOfCertificateElement(elementIdx) == KEYM_CERTIFICATE_EXTENSION) && (!isAttribute) && (encodingType == KEYM_CSR_ENCODING_DER)))
    {
      retVal = E_OK;

      /* # Set elementId in certificate slot */
      KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(certElementId, &ramBuffer.certData[writtenLength]); /* VCA_KEYM_CERT_CSRELEMENTSET_CONVERTUINT16 */

      /* # Set elementDataLength in certificate slot */
      KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian((uint16)elementDataLength, &ramBuffer.certData[writtenLength + KEYM_CERT_CSR_POS_ELEMENTLENGTH]); /* VCA_KEYM_CERT_CSRELEMENTSET_CONVERTUINT16 */

      /* # Set elementData in certificate slot */
      VStdLib_MemCpyLarge(&ramBuffer.certData[writtenLength + KEYM_CERT_CSR_POS_ELEMENTDATA], elementData, elementDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_CSRELEMENTSET_MEMCPY */
      writtenLength += (KeyM_SizeOfCertStorageType)elementDataLength + (KeyM_SizeOfCertStorageType)KEYM_CERT_CSR_POS_ELEMENTDATA;

      KeyM_Cert_SetCertificateWrittenLength(certId, writtenLength);
    }
    else
    {
      /* Not supported yet */
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESIGNINGREQUEST */
#endif

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetIssuerCertId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetIssuerCertId(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) issuerCertId)
{
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIdType issuerCertIdLocal = 0u;
  /* defensive programming: set issuerCertIdLocal to a valid value in case user mistakenly uses it even though an error
   * code is returned. furthermore, this helps VCA with silent analysis. do not remove this initialization */

  if (certId >= KeyM_GetSizeOfCertificate())
  {
    /* Do nothing; retVal is already set to E_NOT_OK */
  }
  /* Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  else if(!KeyM_Cert_IsCertIdSlotOwner(certId))
  {
    /* Do nothing; retVal is already set to E_NOT_OK */
  }
# endif
  else if (KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_PRESET_ISSUER)
  {
    issuerCertIdLocal = KeyM_GetCertUpperHierarchicalCertRefIdxOfCertificate((KeyM_CertificateIterType)certId);
    retVal = E_OK;
  }
  else
  {
# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
#  ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_INTERNAL_STUB */
    /* leave out KeyM_Cert_GetDynamicIssuerCertId calltree for VCA analysis
     * the calltree is analyzed separately to improve VCA analysis time */
    retVal = KeyM_Cert_GetDynamicIssuerCertIdVcaStub(certId, &issuerCertIdLocal);
#  else
    retVal = KeyM_Cert_GetDynamicIssuerCertId(certId, &issuerCertIdLocal);
#  endif
# else
    /* else branch to comply with MISRA; nothing to do since retVal is already set to E_NOT_OK */
# endif
  }

  /*@ assert issuerCertIdLocal < KeyM_GetSizeOfCertificate(); */ /* function ensures that issuerCertId is a valid certificate ID */
  *issuerCertId = issuerCertIdLocal;
  return retVal;
} /* KeyM_Cert_GetIssuerCertId() */
#endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */

#if (KEYM_CERTCSMHASHJOBREFOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_GetCertHash()
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
 */
/* PRQA S 6050, 6080 4 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertHash(
  KeyM_CertificateIdType certId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) hashData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) hashDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_CertificateStatusType certStatus;
  boolean isCertSlotEmpty;

  /* ----- Implementation ----------------------------------------------- */
  isCertSlotEmpty = KeyM_Cert_IsCertSlotEmpty(certId);
  certStatus = KeyM_Cert_GetStatusInfo(certId);

  /* # Check certificate slot owner */
#  if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  if(!KeyM_Cert_IsCertIdSlotOwner(certId))
  {
    retVal = E_NOT_OK;
  }
  else
#  endif
  {
    /* # Check if certificate slot is empty */
    if (isCertSlotEmpty && (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)certId) != KEYM_STORAGE_IN_ROM))
    {
      retVal = KEYM_E_KEY_CERT_EMPTY;
    }
    /* # Check if computed hash is available */
    else if (KeyM_Cert_HashStatus[certId] == FALSE)
    {
      retVal = E_NOT_OK;
    }
    /* # Check certificate status */
    else if ((certStatus != KEYM_CERTIFICATE_VALID) && (certStatus != KEYM_CERTIFICATE_PARSED_NOT_VALIDATED))
    {
      retVal = KEYM_E_KEY_CERT_INVALID;
    }
    /* # Check if hash job is configured for given certificate */
    else if (!KeyM_IsCertHashStorageUsedOfCertificate((KeyM_CertificateIterType)certId))
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    else
    {
      uint32 hashLength = (uint32)KeyM_GetCertHashStorageLengthOfCertificate((KeyM_CertificateIterType)certId);

      /* # Check output buffer data length */
      if (*hashDataLength >= hashLength)
      {
        KeyM_SizeOfCertHashStorageType hashStorageStartIdx = KeyM_GetCertHashStorageStartIdxOfCertificate((KeyM_CertificateIterType)certId);
        /*@ assert hashStorageStartIdx < KeyM_GetSizeOfCertHashStorage(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

        /* # Copy precomputed hash to output buffer */
        VStdLib_MemCpyLarge(hashData, KeyM_GetAddrCertHashStorage(hashStorageStartIdx), hashLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_GETHASH_MEMCPY */
        *hashDataLength = hashLength;
        retVal = E_OK;
      }
      else
      {
        retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_RETRIEVECERTINFO */
#endif

#ifndef KEYM_NOUNIT_SETCERT /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Cert_SetCertificateRteWrapper()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_SetCertificateRteWrapper(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) certData,
  uint32 certDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_ConstCertDataType certDataLocal;

  /* ----- Implementation ----------------------------------------------- */
  certDataLocal.certData = certData;
  certDataLocal.certDataLength = certDataLength;
  return KeyM_SetCertificateWithConstPtr(certId, &certDataLocal);
}
#endif /* ifndef KEYM_NOUNIT_SETCERT */

#if (KEYM_CSM_ASYNC_SIGNATURE_VERIFY == STD_ON)
# ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_CallbackNotificationSignature()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
 /* PRQA S 3673 1 */ /* MD_KEYM_8.13_AutosarAPI */
FUNC(void, KEYM_CODE) KeyM_CallbackNotificationSignature(P2VAR(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job, Std_ReturnType result)
{
  /* ----- Local Variables ------------------------------------------------ */
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  else
#  endif
  {
    /* ----- Implementation ------------------------------------------------- */
    SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();

    /* # Set global flag for the occurrence of callback. */
    KeyM_Cert_CallbackOccurred = TRUE;

    /* # Copy callback result to global variable. */
    KeyM_Cert_SignatureCallbackResult = result;

    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CALLBACKNOTIFICATIONSIGNATURE, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  KEYM_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
# endif /* ifndef KEYM_NOUNIT_VERIFYCERTSTATEMACHINE */
#endif /* KEYM_CSM_ASYNC_SIGNATURE_VERIFY */

#define KEYM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/
