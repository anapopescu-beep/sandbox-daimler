/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  KeyM_Remote.c
 *         \unit  *
 *        \brief  Source file for remote service handling
 *      \details  Implementation of remote service handling
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define KEYM_REMOTE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "KeyM.h"
#include "KeyM_Cert.h"
#include "KeyM_Remote.h"
#include "KeyM_Utils.h"
#include "SchM_KeyM.h"
#include "vstdlib.h"
#include "Csm.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (KEYM_LOCAL) /* COV_KEYM_LOCAL_DEFINE */
# define KEYM_LOCAL                                                   static
#endif

#if !defined (KEYM_LOCAL_INLINE) /* COV_KEYM_LOCAL_DEFINE */
# define KEYM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

/* Remote service types */
#define KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_REQUEST_CSR       (0x10u)
#define KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_SIGNED_CSR (0x11u)
#define KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_SET_ROOT          (0x12u)
#define KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_ROOT       (0x13u)
#define KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_SET_INTERMEDIATE  (0x14u)
#define KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_INTERMEDIATE (0x15u)
#define KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_CRL        (0x16u)
#define KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_STATUS_OCSP       (0x17u)
#define KEYM_REMOTE_SERVICE_SETCERTIFICATE                            (0x18u)
#define KEYM_REMOTE_SERVICE_GETCERTIFICATE                            (0x19u)
#define KEYM_REMOTE_SERVICE_VERIFYCERTIFICATE                         (0x1Au)
#define KEYM_REMOTE_SERVICE_VERIFYCERTIFICATES                        (0x1Bu)
#define KEYM_REMOTE_SERVICE_VERIFYCERTIFICATECHAIN                    (0x1Cu)
#define KEYM_REMOTE_SERVICE_CERTELEMENTGET                            (0x1Du)
#define KEYM_REMOTE_SERVICE_CERTGETSTATUS                             (0x1Eu)
#define KEYM_REMOTE_SERVICE_SEARCHCERT                                (0x1Fu)
#define KEYM_REMOTE_SERVICE_CERTELEMENTGETBYINDEX                     (0x20u)
#define KEYM_REMOTE_SERVICE_CERTELEMENTGETCOUNT                       (0x21u)
#define KEYM_REMOTE_SERVICE_SETCERTIFICATEINGROUP                     (0x22u)
#define KEYM_REMOTE_SERVICE_VERIFYGROUP                               (0x23u)
#define KEYM_REMOTE_SERVICE_SETCRE                                    (0x24u)
#define KEYM_REMOTE_SERVICE_CERTSTRUCTUREGET                          (0x25u)
#define KEYM_REMOTE_SERVICE_GETISSUERCERTID                           (0x26u)
#define KEYM_REMOTE_SERVICE_GETCERTHASH                               (0x27u)
#define KEYM_REMOTE_SERVICE_CSRELEMENTSET                             (0x28u)
#define KEYM_REMOTE_SERVICE_CERTDELETE                                (0x29u)
#define KEYM_REMOTE_SERVICE_CERTINFOGET                               (0x2Au)
#define KEYM_REMOTE_SERVICE_GETPUBKEYHASH                             (0x2Bu)

/* Remote service modes */
#define KEYM_REMOTE_SERVICE_MODE_BYCERTNAME                           (0x00u)
#define KEYM_REMOTE_SERVICE_MODE_BYCERTID                             (0x01u)

/* Remote service offsets */
#define KEYM_REMOTE_SERVICE_TYPE_POS                                  (0x00u)
#define KEYM_REMOTE_SERVICE_MODE_POS                                  (0x01u)

/* Remote parameter size in bytes */
#define KEYM_REMOTE_SERVICETYPE_SIZE                                  (0x01u)
#define KEYM_REMOTE_STATUS_SIZE                                       (0x01u)
#define KEYM_REMOTE_NUMOFCERTS_SIZE                                   (0x01u)
#define KEYM_REMOTE_SERVICE_SIZE                                      (0x02u)
#define KEYM_REMOTE_CERTID_SIZE                                       (0x02u)
#define KEYM_REMOTE_GROUPID_SIZE                                      (0x02u)
#define KEYM_REMOTE_CERTID_AND_UPPERCERTID_SIZE                       (0x04u)
#define KEYM_REMOTE_ITERATED_ELEMENT_COUNT_SIZE                       (0x02u)
#define KEYM_REMOTE_SERVICE_MASK                                      (0x000000FFuL)
#define KEYM_REMOTE_CERTELEMENTID_MASK                                (0x00FFFF00uL)
#define KEYM_REMOTE_CERTSTRUCTURE_MASK                                (0x00FFFF00uL)
#define KEYM_REMOTE_CERTINFO_MASK                                     (0x00FFFF00uL)
#define KEYM_REMOTE_INDEX_MASK                                        (0xFF000000uL)
#define KEYM_REMOTE_ENCODINGTYPE_MASK                                 (0xFF000000uL)
#define KEYM_REMOTE_CRE_DATALENGTH_SIZE                               (0x02u)
#define KEYM_REMOTE_CRE_ISSUERNAME_SIZE                               (KEYM_REMOTE_CRE_DATALENGTH_SIZE + KEYM_CREMAX_LENGTH_OF_ISSUER_NAME)
#define KEYM_REMOTE_CRE_SERIALNUMBER_SIZE                             (KEYM_REMOTE_CRE_DATALENGTH_SIZE + KEYM_CREMAX_LENGTH_OF_SERIAL_NUMBER)
#define KEYM_REMOTE_CREINFO_SIZE                                      (KEYM_REMOTE_CRE_ISSUERNAME_SIZE + KEYM_REMOTE_CRE_SERIALNUMBER_SIZE)

#define KEYM_REMOTE_CRE_ISSUERNAME_LENGTH_POS                         (0u)
#define KEYM_REMOTE_CRE_ISSUERNAME_POS                                (2u)
#define KEYM_REMOTE_CRE_SERIALNUMBER_LENGTH_POS                       (KEYM_REMOTE_CRE_ISSUERNAME_SIZE)
#define KEYM_REMOTE_CRE_SERIALNUMBER_POS                              (KEYM_REMOTE_CRE_ISSUERNAME_SIZE + 2u)

#define KEYM_REMOTE_CERTIFICATE_CHAIN_POS_CERTDATA                    (2u)
#define KEYM_REMOTE_CERTIFICATE_CHAIN_MAX_LENGTH                      (KEYM_CERTIFICATE_CHAIN_MAX_DEPTH * (KEYM_MAX_CERTIFICATE_MAX_LENGTH + KEYM_REMOTE_CERTIFICATE_CHAIN_POS_CERTDATA))

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define KEYM_START_SEC_VAR_NO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Remote task busy state */
VAR(uint8, KEYM_VAR_NO_INIT) KeyM_Remote_TaskState;

#define KEYM_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define KEYM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_GetRemoteService()
 *********************************************************************************************************************/
 /*! \brief         Retrieve remote service for service redirection.
  *  \details       -
  *  \param[in]     serviceCertificateType         Holds the service certificate type.
  *  \param[in]     serviceMode                    Holds the service mode.
  *  \param[out]    remoteService                  Pointer to remote service buffer.
  *  \return        E_OK                           Remote service successfully retrieved.
  *                 E_NOT_OK                       Due to an internal error, the remote service could not be retrieved.
  *  \pre           remoteService must be a valid pointer.
  *                 The buffer referenced by remoteService must provide at least KEYM_REMOTE_SERVICE_SIZE bytes.
  *  \context       TASK
  *  \reentrant     TRUE
  *  \synchronous   TRUE
  *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_GetRemoteService(
  KeyM_ServiceCertificateType serviceCertificateType,
  uint8 serviceMode,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) remoteService);
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_GetServiceCertificateType()
 *********************************************************************************************************************/
/*! \brief         Retrieve service certificate type from remote service.
 *  \details       -
 *  \param[in]     remoteServiceType              Holds the remote service type.
 *  \param[out]    serviceCertificateType         Pointer to retrieved service certificate type.
 *                                                could not be retrieved.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Remote_GetServiceCertificateType(
  uint8 remoteServiceType,
  P2VAR(KeyM_ServiceCertificateType, AUTOMATIC, KEYM_APPL_VAR) serviceCertificateType);
# endif /* (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) */
#endif

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_HandleCsmResult()
 *********************************************************************************************************************/
/*! \brief         Handle result of CSM function call.
 *  \details       -
 *  \param[in]     csmResult            Return code of CSM.
 *  \return        E_OK                 The returned CSM result was handled successfully.
 *                 E_NOT_OK             Internal error, due to invalid CSM result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_HandleCsmResult(
  Std_ReturnType csmResult);
#endif /* (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON) */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_ProcessService()
 *********************************************************************************************************************/
/*! \brief          Wait until KeyM is not busy anymore.
 *  \details        This function calls KeyM_MainFunction until KeyM has finished the requested service.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Remote_ProcessService(void);
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_ServiceCertificate()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_ServiceCertificate based on Crypto job parameters.
 *  \details       This function calls KeyM_ServiceCertificate and obtains the parameter from a crypto job.
 *  \param[in]     job                Pointer to the configuration of the job. Contains structures with job and
 *                                    primitive relevant information but also pointer to result buffers.
 *  \return        E_OK                                 Service data operation successfully accepted.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *                 KEYM_E_BUSY                          Service cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_KEY_CERT_EMPTY                Certificate slot is empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   Invalid chain of trust.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_ServiceCertificate(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job);
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_ServiceCertificateById()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_ServiceCertificateById based on Crypto job parameters.
 *  \details       This function calls KeyM_ServiceCertificateById and obtains the parameter from a crypto job.
 *  \param[in]     job                Pointer to the configuration of the job. Contains structures with job and
 *                                    primitive relevant information but also pointer to result buffers.
 *  \return        E_OK                                 Service data operation successfully accepted.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *                 KEYM_E_BUSY                          Service cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_KEY_CERT_EMPTY                Certificate slot is empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   Invalid chain of trust.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_ServiceCertificateById(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job);
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */
#endif

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_VerifyCertificate()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_VerifyCertificate based on Crypto job parameters.
 *  \details       This function calls KeyM_VerifyCertificate and obtains the parameter from a crypto job.
 *  \param[in]     job                Pointer to the configuration of the job. Contains structures with job and
 *                                    primitive relevant information but also pointer to result buffers.
 *  \return        E_OK                                 Certificate verification request accepted. Operation is
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
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_VerifyCertificate(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job);
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_VerifyCertificates()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_VerifyCertificates based on Crypto job parameters.
 *  \details       This function calls KeyM_VerifyCertificates and obtains the parameter from a crypto job.
 *  \param[in]     job                Pointer to the configuration of the job. Contains structures with job and
 *                                    primitive relevant information but also pointer to result buffers.
 *  \return        E_OK                                 Certificate verification request accepted. Operation is
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
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_VerifyCertificates(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job);
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_VerifyCertificateChain()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_VerifyCertificateChain based on Crypto job parameters.
 *  \details       This function calls KeyM_VerifyCertificateChain and obtains the parameter from a crypto job.
 *  \param[in]     job                Pointer to the configuration of the job. Contains structures with job and
 *                                    primitive relevant information but also pointer to result buffers.
 *  \return        E_OK                                 Certificate verification request accepted. Operation is
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
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_VerifyCertificateChain(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job);
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_SetCertificateInGroup()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_SetCertificateInGroup based on Crypto job parameters.
 *  \details       This function calls KeyM_SetCertificateInGroup and obtains the parameter from a crypto job.
 *  \param[in]     job                Pointer to the configuration of the job. Contains structures with job and
 *                                    primitive relevant information but also pointer to result buffers.
 *  \return        E_OK                                 Certificate accepted.
 *                 E_NOT_OK                             Certificate could not be set.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *                 KEYM_E_BUSY                          Service cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_KEY_CERT_EMPTY                Certificate slot is empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   Invalid chain of trust.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_SetCertificateInGroup(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job);
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_VerifyGroup()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_VerifyGroup based on Crypto job parameters.
 *  \details       This function calls KeyM_VerifyGroup and obtains the parameter from a crypto job.
 *  \param[in]     job                Pointer to the configuration of the job. Contains structures with job and
 *                                    primitive relevant information but also pointer to result buffers.
 *  \return        E_OK               The verification of the certificate group was triggered successfully.
 *                 E_NOT_OK           Certificate data is unavailable and no verification could be triggered.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_VerifyGroup(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job);
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */
#endif

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_SetCertificate()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_SetCertificate based on key management function parameters.
 *  \details       This function calls KeyM_SetCertificate and obtains the parameter from a key management function.
 *  \param[in]     cryptoKeyId                     Holds the identifier of the key whose key element shall be set.
 *  \param[in]     keyPtr                          Holds the pointer to the key data which shall be set as key element.
 *  \param[in]     keyLength                       Contains the length of the key element in bytes.
 *  \return        E_OK                            Certificate accepted.
 *                 E_NOT_OK                        Certificate could not be set.
 *                 KEYM_E_PARAMETER_MISMATCH       Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH   Parameter size doesn't match.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_SetCertificate(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  uint32 keyLength);
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_CertDelete()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_CertDelete based on key management function parameters.
 *  \details       This function calls KeyM_CertDelete and obtains the parameter from a key management function.
 *  \param[in]     cryptoKeyId                     Holds the identifier of the key whose key element shall be set.
 *  \return        E_OK                            Certificate was deleted successfully.
 *                 E_NOT_OK                        Due to internal error, the certificate could not be deleted.
 *                 KEYM_E_BUSY                     Service cannot be performed yet. Certificate is locked by another
 *                                                 service request.
 *                 KEYM_E_PARAMETER_MISMATCH       The referenced certificate identifier is invalid.
 *                 KEYM_E_KEY_CERT_EMPTY           Certificate slot is empty.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertDelete(
  uint32 cryptoKeyId);
#endif

#if (KEYM_CRE == STD_ON)
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_SetCRE()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_SetCRE based on key management function parameters.
 *  \details       This function calls KeyM_SetCRE and obtains the parameter from a key management function.
 *  \param[in]     keyPtr                          Holds the pointer to the key data which shall be set as key element.
 *  \param[in]     keyLength                       Contains the length of the key element in bytes.
 *  \return        E_OK                            Certificate revocation entry was appended successfully.
 *                 E_NOT_OK                        Due to internal error, the certificate revocation entry could
 *                                                 not be appended.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH   Parameter size doesn't match.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_SetCRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  uint32 keyLength);
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */
#endif

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_CsrElementSet()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_CsrElementSet based on key management function parameters.
 *  \details       This function calls KeyM_CsrElementSet and obtains the parameter from a key management function.
 *  \param[in]     cryptoKeyId                     Holds the identifier of the key whose key element shall be set.
 *  \param[in]     keyElementId                    Holds the identifier of the key element which shall be set.
 *  \param[in]     keyPtr                          Holds the pointer to the key data which shall be set as key element.
 *  \param[in]     keyLength                       Contains the length of the key element in bytes.
 *  \return        E_OK                            CSR element was set successfully.
 *                 E_NOT_OK                        Due to internal error, the CSR element could not be set.
 *                 KEYM_E_PARAMETER_MISMATCH       Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH   Parameter size doesn't match.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CsrElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  uint32 keyLength);
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */
#endif

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_GetCertificate()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_GetCertificate based on key management function parameters.
 *  \details       This function calls KeyM_GetCertificate and obtains the parameter from a key management function.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key from which a key element shall be extracted.
 *  \param[out]    keyPtr                  Holds the pointer to the memory location where the key shall be copied to.
 *  \param[in,out] keyLengthPtr            Holds a pointer to the memory location in which the output buffer length in
 *                                         bytes is stored. On calling this function, this parameter shall contain the
 *                                         buffer length in bytes of the keyPtr. When the request has finished, the
 *                                         actual size of the written input bytes shall be stored.
 *  \return        E_OK                            Certificate data available and provided.
 *                 E_NOT_OK                        Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH       Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH   Provided buffer for the certificate too small.
 *                 KEYM_E_KEY_CERT_EMPTY           No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_READ_FAIL       Certificate cannot be provided, access denied.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_GetCertificate(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr);
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_CertElementGet()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_CertElementGet based on key management function parameters.
 *  \details       This function calls KeyM_CertElementGet and obtains the parameter from a key management function.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key from which a key element shall be extracted.
 *  \param[in]     keyElementId            Holds the identifier of the key element to be extracted.
 *  \param[out]    keyPtr                  Holds the pointer to the memory location where the key shall be copied to.
 *  \param[in,out] keyLengthPtr            Holds a pointer to the memory location in which the output buffer length in
 *                                         bytes is stored. On calling this function, this parameter shall contain the
 *                                         buffer length in bytes of the keyPtr. When the request has finished, the
 *                                         actual size of the written input bytes shall be stored.
 *  \return        E_OK                            Element found and data provided in the buffer.
 *                 E_NOT_OK                        Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH       Certificate ID or certificate element ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH   Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY           No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID         The certificate is not valid or has not yet been verified.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr);
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_CertGetStatus()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_CertGetStatus based on key management function parameters.
 *  \details       This function calls KeyM_CertGetStatus and obtains the parameter from a key management function.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key from which a key element shall be extracted.
 *  \param[out]    keyPtr                  Holds the pointer to the memory location where the key shall be copied to.
 *  \param[in]     keyLengthPtr            Holds a pointer to the memory location in which the output buffer length in
 *                                         bytes is stored. On calling this function, this parameter shall contain the
 *                                         buffer length in bytes of the keyPtr.
 *  \return        E_OK                            Certificate status available and provided.
 *                 E_NOT_OK                        Status provisioning currently not possible.
 *                 KEYM_E_PARAMETER_MISMATCH       Certificate identifier is invalid.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertGetStatus(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2CONST(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr);
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_CertificateElementGetByIndex()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_CertificateElementGetByIndex based on key management function parameters.
 *  \details       This function calls KeyM_CertificateElementGetByIndex and obtains the parameter from a key
 *                 management function.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key from which a key element shall be extracted.
 *  \param[in]     keyElementId            Holds the identifier of the key element to be extracted.
 *  \param[out]    keyPtr                  Holds the pointer to the memory location where the key shall be copied to.
 *  \param[in,out] keyLengthPtr            Holds a pointer to the memory location in which the output buffer length in
 *                                         bytes is stored. On calling this function, this parameter shall contain the
 *                                         buffer length in bytes of the keyPtr. When the request has finished, the
 *                                         actual size of the written input bytes shall be stored.
 *  \return        E_OK                                 Element found and data provided in the buffer.
 *                 E_NOT_OK                             Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID or certificate element ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertificateElementGetByIndex(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr);
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_CertificateElementGetCount()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_CertificateElementGetCount based on key management function parameters.
 *  \details       This function calls KeyM_CertificateElementGetCount and obtains the parameter from a key
 *                 management function.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key from which a key element shall be extracted.
 *  \param[in]     keyElementId            Holds the identifier of the key element to be extracted.
 *  \param[out]    keyPtr                  Holds the pointer to the memory location where the key shall be copied to.
 *  \param[in]     keyLengthPtr            Holds a pointer to the memory location in which the output buffer length in
 *                                         bytes is stored. On calling this function, this parameter shall contain the
 *                                         buffer length in bytes of the keyPtr.
 *  \return        E_OK                                 Element found and number of element items provided.
 *                 E_NOT_OK                             Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID or certificate element ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertificateElementGetCount(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2CONST(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr);
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_CertStructureGet()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_CertStructureGet based on key management function parameters.
 *  \details       This function calls KeyM_CertStructureGet and obtains the parameter from a key
 *                 management function.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key from which a key element shall be extracted.
 *  \param[in]     keyElementId            Holds the identifier of the key element to be extracted.
 *  \param[out]    keyPtr                  Holds the pointer to the memory location where the key shall be copied to.
 *  \param[in,out] keyLengthPtr            Holds a pointer to the memory location in which the output buffer length in
 *                                         bytes is stored. On calling this function, this parameter shall contain the
 *                                         buffer length in bytes of the keyPtr. When the request has finished, the
 *                                         actual size of the written input bytes shall be stored.
 *  \return        E_OK                             Certificate structure was retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate structure could not be
 *                                                  retrieved.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *                 KEYM_E_KEY_CERT_INVALID          The certificate is not valid or has not yet been verified.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertStructureGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr);
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_CertInfoGet()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_CertInfoGet based on key management function parameters.
 *  \details       This function calls KeyM_CertInfoGet and obtains the parameter from a key
 *                 management function.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key from which a key element shall be extracted.
 *  \param[in]     keyElementId            Holds the identifier of the key element to be extracted.
 *  \param[out]    keyPtr                  Holds the pointer to the memory location where the key shall be copied to.
 *  \param[in,out] keyLengthPtr            Holds a pointer to the memory location in which the output buffer length in
 *                                         bytes is stored. On calling this function, this parameter shall contain the
 *                                         buffer length in bytes of the keyPtr. When the request has finished, the
 *                                         actual size of the written input bytes shall be stored.
 *  \return        E_OK                             Certificate information was retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate information could not be
 *                                                  retrieved.
 *                 KEYM_E_BUSY                      Service cannot be performed yet. KeyM is currently busy with other jobs.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertInfoGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr);
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_GetIssuerCertId()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_GetIssuerCertId based on key management function parameters.
 *  \details       This function calls KeyM_GetIssuerCertId and obtains the parameter from a key
 *                 management function.
 *  \param[in]     cryptoKeyId           Holds the identifier of the key from which a key element shall be extracted.
 *  \param[out]    keyPtr                Holds the pointer to the memory location where the key shall be copied to.
 *  \param[in]     keyLengthPtr          Holds a pointer to the memory location in which the output buffer length in
 *                                       bytes is stored. On calling this function, this parameter shall contain the
 *                                       buffer length in bytes of the keyPtr.
 *  \return        E_OK                  Issuer's certificate identifier was retrieved successfully.
 *                 E_NOT_OK              Due to internal error, the issuer's certificate identifier could not be
 *                                       retrieved.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_GetIssuerCertId(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2CONST(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr);
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_CERTHASHSTORAGEUSEDOFCERTIFICATE == STD_ON)
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_GetCertHash()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_GetCertHash based on key management function parameters.
 *  \details       This function calls KeyM_GetCertHash and obtains the parameter from a key
 *                 management function.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key from which a key element shall be extracted.
 *  \param[out]    keyPtr                  Holds the pointer to the memory location where the key shall be copied to.
 *  \param[in,out] keyLengthPtr            Holds a pointer to the memory location in which the output buffer length in
 *                                         bytes is stored. On calling this function, this parameter shall contain the
 *                                         buffer length in bytes of the keyPtr. When the request has finished, the
 *                                         actual size of the written input bytes shall be stored.
 *  \return        E_OK                             Certificate hash was retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate hash could not be
 *                                                  retrieved.
 *                 KEYM_E_BUSY                      Service cannot be performed yet. Certificate is locked by another
 *                                                  service request.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_INVALID          Certificate is not valid.
 *                 KEYM_E_KEY_CERT_EMPTY            Certificate slot is empty.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_GetCertHash(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr);
# endif /* (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) */
#endif

#if (KEYM_CERTPUBKEYHASHSTORAGEUSEDOFCERTIFICATE == STD_ON)
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_GetPubKeyHash()
 *********************************************************************************************************************/
/*! \brief         Execute KeyM_GetPubKeyHash based on key management function parameters.
 *  \details       This function calls KeyM_GetPubKeyHash and obtains the parameter from a key
 *                 management function.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key from which a key element shall be extracted.
 *  \param[out]    keyPtr                  Holds the pointer to the memory location where the key shall be copied to.
 *  \param[in,out] keyLengthPtr            Holds a pointer to the memory location in which the output buffer length in
 *                                         bytes is stored. On calling this function, this parameter shall contain the
 *                                         buffer length in bytes of the keyPtr. When the request has finished, the
 *                                         actual size of the written input bytes shall be stored.
 *  \return        E_OK                             Public key hash was retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, the public key hash could not be
 *                                                  retrieved.
 *                 KEYM_E_BUSY                      Service cannot be performed yet. Certificate is locked by another
 *                                                  service request.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_INVALID          Certificate is not valid.
 *                 KEYM_E_KEY_CERT_EMPTY            Certificate slot is empty.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_GetPubKeyHash(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr);
# endif /* (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) */
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_GetRemoteService()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_GetRemoteService(
  KeyM_ServiceCertificateType serviceCertificateType,
  uint8 serviceMode,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) remoteService)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve remote service type */
  switch (serviceCertificateType)
  {
  case KEYM_SERVICE_CERT_REQUEST_CSR:
  {
    remoteService[KEYM_REMOTE_SERVICE_TYPE_POS] = KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_REQUEST_CSR;
    break;
  }
  case KEYM_SERVICE_CERT_UPDATE_SIGNED_CSR:
  {
    remoteService[KEYM_REMOTE_SERVICE_TYPE_POS] = KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_SIGNED_CSR;
    break;
  }
  case KEYM_SERVICE_CERT_SET_ROOT:
  {
    remoteService[KEYM_REMOTE_SERVICE_TYPE_POS] = KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_SET_ROOT;
    break;
  }
  case KEYM_SERVICE_CERT_UPDATE_ROOT:
  {
    remoteService[KEYM_REMOTE_SERVICE_TYPE_POS] = KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_ROOT;
    break;
  }
  case KEYM_SERVICE_CERT_SET_INTERMEDIATE:
  {
    remoteService[KEYM_REMOTE_SERVICE_TYPE_POS] = KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_SET_INTERMEDIATE;
    break;
  }
  case KEYM_SERVICE_CERT_UPDATE_INTERMEDIATE:
  {
    remoteService[KEYM_REMOTE_SERVICE_TYPE_POS] = KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_INTERMEDIATE;
    break;
  }
  case KEYM_SERVICE_CERT_UPDATE_CRL:
  {
    remoteService[KEYM_REMOTE_SERVICE_TYPE_POS] = KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_CRL;
    break;
  }
  case KEYM_SERVICE_CERT_STATUS_OCSP:
  {
    remoteService[KEYM_REMOTE_SERVICE_TYPE_POS] = KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_STATUS_OCSP;
    break;
  }
  default:
    /* Invalid service type. */
    retVal = E_NOT_OK;
    break;
  }

  if (retVal == E_OK)
  {
    /* # Retrieve remote service mode */
    remoteService[KEYM_REMOTE_SERVICE_MODE_POS] = serviceMode;
  }

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON) */
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_GetServiceCertificateType()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Remote_GetServiceCertificateType(
  uint8 remoteServiceType,
  P2VAR(KeyM_ServiceCertificateType, AUTOMATIC, KEYM_APPL_VAR) serviceCertificateType)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve service certificate typ based on remote service type */
  switch (remoteServiceType)
  {
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_REQUEST_CSR:
    {
      *serviceCertificateType = KEYM_SERVICE_CERT_REQUEST_CSR;
      break;
    }
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_SIGNED_CSR:
    {
      *serviceCertificateType = KEYM_SERVICE_CERT_UPDATE_SIGNED_CSR;
      break;
    }
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_SET_ROOT:
    {
      *serviceCertificateType = KEYM_SERVICE_CERT_SET_ROOT;
      break;
    }
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_ROOT:
    {
      *serviceCertificateType = KEYM_SERVICE_CERT_UPDATE_ROOT;
      break;
    }
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_SET_INTERMEDIATE:
    {
      *serviceCertificateType = KEYM_SERVICE_CERT_SET_INTERMEDIATE;
      break;
    }
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_INTERMEDIATE:
    {
      *serviceCertificateType = KEYM_SERVICE_CERT_UPDATE_INTERMEDIATE;
      break;
    }
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_CRL:
    {
      *serviceCertificateType = KEYM_SERVICE_CERT_UPDATE_CRL;
      break;
    }
    default: /* KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_STATUS_OCSP */
    {
      *serviceCertificateType = KEYM_SERVICE_CERT_STATUS_OCSP;
      break; /* Invalid service certificate type is checked in a previous step */
    }
  }
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) */
#endif

#ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON) || (KEYM_REMOTE_CREENABLED == STD_ON)
/**********************************************************************************************************************
 *  KeyM_Remote_HandleCsmResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_HandleCsmResult(
  Std_ReturnType csmResult)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Evaluate result of CSM operation */
  return (csmResult == E_OK) ? E_OK : E_NOT_OK;
}
# endif /* (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON) */
#endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_ProcessService()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(void, KEYM_CODE) KeyM_Remote_ProcessService(void)
{
  /* ----- Implementation ----------------------------------------------- */
  do
  {
    /* # Call the cyclic main function until KeyM Cert submodule is idle */
    KeyM_MainFunction();
  }
  while (KeyM_Cert_IsBusy());
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_ServiceCertificate()
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
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_ServiceCertificate(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_ServiceCertificateType service;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve service certificate type */
  KeyM_Remote_GetServiceCertificateType(job->jobPrimitiveInputOutput.inputPtr[KEYM_REMOTE_SERVICE_TYPE_POS], &service);

  /* # Forward call to KeyM_ServiceCertificate to process the requested service */
  retVal = KeyM_ServiceCertificate(
    service,                                                /* uint8 Service */
    job->jobPrimitiveInputOutput.secondaryInputPtr,         /* uint8* CertNamePtr */
    job->jobPrimitiveInputOutput.secondaryInputLength,      /* uint32 CertNameLength */
    job->jobPrimitiveInputOutput.tertiaryInputPtr,          /* uint8* RequestData */
    job->jobPrimitiveInputOutput.tertiaryInputLength,       /* uint32 RequestDataLength */
    job->jobPrimitiveInputOutput.outputPtr,                 /* uint8* ResponseData */
    *job->jobPrimitiveInputOutput.outputLengthPtr);         /* uint32 ResponseDataLength */
  if (retVal == E_OK)
  {
    /* # Wait until KeyM has finished the service */
    KeyM_Remote_ProcessService();
  }
  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_ServiceCertificateById()
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
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_ServiceCertificateById(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_ServiceCertificateType service;
  KeyM_CertificateIdType certId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve service certificate type */
  KeyM_Remote_GetServiceCertificateType(job->jobPrimitiveInputOutput.inputPtr[KEYM_REMOTE_SERVICE_TYPE_POS], &service);

  /* # Retrieve certificate identifier */
  certId = (KeyM_CertificateIdType)job->cryptoKeyId;
  /* # Forward call to KeyM_ServiceCertificateById to process the requested service */
  retVal = KeyM_ServiceCertificateById(
    service,                                                /* uint8 Service */
    certId,                                                 /* uint16 CertId */
    job->jobPrimitiveInputOutput.tertiaryInputPtr,          /* uint8* RequestData */
    job->jobPrimitiveInputOutput.tertiaryInputLength,       /* uint32 RequestDataLength */
    job->jobPrimitiveInputOutput.outputPtr,                 /* uint8* ResponseData */
    *job->jobPrimitiveInputOutput.outputLengthPtr);         /* uint32 ResponseDataLength */
  if (retVal == E_OK)
  {
    /* # Wait until KeyM has finished the service */
    KeyM_Remote_ProcessService();
  }

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */
#endif

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_VerifyCertificate()
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
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_VerifyCertificate(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIdType certId;
  KeyM_CertificateStatusType certStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check input and output parameters */
  if (job->jobPrimitiveInputOutput.verifyPtr == NULL_PTR)
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else
  {
    /* # Retrieve certificate identifier */
    certId = (KeyM_CertificateIdType)job->cryptoKeyId;

    /* # Forward call to KeyM_VerifyCertificate to process the requested service */
    retVal = KeyM_VerifyCertificate(certId);

    if (retVal == E_OK)
    {
      /* # Wait until KeyM has finished the service */
      KeyM_Remote_ProcessService();

      /* # Return verification result */
      retVal = KeyM_CertGetStatus(certId, &certStatus);

      if (retVal == E_OK)
      {
        *job->jobPrimitiveInputOutput.verifyPtr = certStatus;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_VerifyCertificates()
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
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_VerifyCertificates(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIdType certId;
  KeyM_CertificateIdType upperCertId;
  KeyM_CertificateStatusType certStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check input and output parameters */
  if ((job->jobPrimitiveInputOutput.secondaryInputPtr == NULL_PTR)
    || (job->jobPrimitiveInputOutput.secondaryInputLength != KEYM_REMOTE_CERTID_SIZE)
    || (job->jobPrimitiveInputOutput.verifyPtr == NULL_PTR))
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else
  {
    /*@ assert $lengthOf(job->jobPrimitiveInputOutput.secondaryInputPtr) == KEYM_REMOTE_CERTID_SIZE; */ /* VCA_KEYM_REMOTE_JOBDISPATCHING_INPUTOUTPUTLENGTH */

    /* # Retrieve certificate identifier */
    certId = (KeyM_CertificateIdType)job->cryptoKeyId;
    upperCertId = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(job->jobPrimitiveInputOutput.secondaryInputPtr);

    /* # Forward call to KeyM_VerifyCertificates to process the requested service */
    retVal = KeyM_VerifyCertificates(certId, upperCertId);

    if (retVal == E_OK)
    {
      /* # Wait until KeyM has finished the service */
      KeyM_Remote_ProcessService();

      /* # Return verification result */
      retVal = KeyM_CertGetStatus(certId, &certStatus);

      if (retVal == E_OK)
      {
        *job->jobPrimitiveInputOutput.verifyPtr = certStatus;
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_VerifyCertificateChain()
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
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_VerifyCertificateChain(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_CertificateIdType certId;
  uint8 numOfCertificates;
  KeyM_ConstCertDataType certChainData[KEYM_CERTIFICATE_CHAIN_MAX_DEPTH] = { 0u };
  KeyM_CertificateStatusType certStatus;
  uint8_least i;
  uint32 offset = 0u;
  uint32 certDataLength;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check input and output parameters */
  if ((job->jobPrimitiveInputOutput.secondaryInputPtr == NULL_PTR)                                  /* null pointer check for in parameter numOfCertificates */
    || (job->jobPrimitiveInputOutput.tertiaryInputPtr == NULL_PTR)                                  /* null pointer check for in parameter certChainDataLength */
    || (job->jobPrimitiveInputOutput.verifyPtr == NULL_PTR)                                         /* null pointer check for out parameter certStatus */
    || (job->jobPrimitiveInputOutput.secondaryInputLength != KEYM_REMOTE_NUMOFCERTS_SIZE))          /* length check for in parameter numOfCertificates (expected: 1 byte)  */
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* # Retrieve certificate identifier */
    certId = (KeyM_CertificateIdType)job->cryptoKeyId;

    /* # Retrieve number of certificates */
    numOfCertificates = *job->jobPrimitiveInputOutput.secondaryInputPtr;

    /* check if numOfCertificates is < the size of local array certChainData */
    if (numOfCertificates >= KEYM_CERTIFICATE_CHAIN_MAX_DEPTH)
    {
      retVal = E_NOT_OK;
    }

    /* # Deserialize certificate chain data */
    for (i = 0u; (i < numOfCertificates) && (retVal == E_OK); i++)
    {
      /*@ assert i < KEYM_CERTIFICATE_CHAIN_MAX_DEPTH; */ /* VCA_KEYM_REMOTE_VERIFYCERTIFICATECHAIN_NUMOFCERTIFICATES */

      /* Array bounds check */
      if ((offset + KEYM_REMOTE_CERTIFICATE_CHAIN_POS_CERTDATA) > job->jobPrimitiveInputOutput.tertiaryInputLength)
      {
        retVal = E_NOT_OK;
      }
      else
      {
        certDataLength = (uint32)KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(&job->jobPrimitiveInputOutput.tertiaryInputPtr[offset]); /* VCA_KEYM_REMOTE_VERIFYCERTIFICATECHAIN_TERTIARYBUFFERACCESS */

        /* Array bounds check */
        if ((offset + certDataLength + KEYM_REMOTE_CERTIFICATE_CHAIN_POS_CERTDATA) > job->jobPrimitiveInputOutput.tertiaryInputLength)
        {
          retVal = E_NOT_OK;
        }
        else
        {
          certChainData[i].certData = &job->jobPrimitiveInputOutput.tertiaryInputPtr[offset + KEYM_REMOTE_CERTIFICATE_CHAIN_POS_CERTDATA];
          certChainData[i].certDataLength = certDataLength;
          offset += certDataLength + (uint32)KEYM_REMOTE_CERTIFICATE_CHAIN_POS_CERTDATA;
        }
      }
    }

    if (retVal == E_OK)
    {
      /* # Forward call to KeyM_VerifyCertificateChainWithConstPtr to process the requested service */
      retVal = KeyM_VerifyCertificateChainWithConstPtr(certId, certChainData, numOfCertificates);

      if (retVal == E_OK)
      {
        /* # Wait until KeyM has finished the service */
        KeyM_Remote_ProcessService();

        /* # Return verification result */
        retVal = KeyM_CertGetStatus(certId, &certStatus);

        if (retVal == E_OK)
        {
          *job->jobPrimitiveInputOutput.verifyPtr = certStatus;
        }
      }
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_SetCertificateInGroup()
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
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_SetCertificateInGroup(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateGroupIdType groupId;
  KeyM_CertificateIdType certId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check input and output parameters */
  if ((job->jobPrimitiveInputOutput.secondaryInputPtr == NULL_PTR)
    || (job->jobPrimitiveInputOutput.secondaryInputLength != KEYM_REMOTE_GROUPID_SIZE)
    || (job->jobPrimitiveInputOutput.outputPtr == NULL_PTR)
    || (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR)
    || (*job->jobPrimitiveInputOutput.outputLengthPtr != KEYM_REMOTE_CERTID_SIZE))
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else
  {
    /*@ assert $lengthOf(job->jobPrimitiveInputOutput.secondaryInputPtr) == KEYM_REMOTE_GROUPID_SIZE; */ /* VCA_KEYM_REMOTE_JOBDISPATCHING_INPUTOUTPUTLENGTH */
    /*@ assert $lengthOf(job->jobPrimitiveInputOutput.outputPtr) == KEYM_REMOTE_CERTID_SIZE; */ /* VCA_KEYM_REMOTE_JOBDISPATCHING_INPUTOUTPUTLENGTH */

    /* # Retrieve group identifier */
    groupId = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(job->jobPrimitiveInputOutput.secondaryInputPtr);

    /* # Forward call to KeyM_SetCertificateInGroup to process the requested service */
    retVal = KeyM_SetCertificateInGroup(
      groupId,                                                /* KeyM_CertificateGroupIdType GroupId */
      job->jobPrimitiveInputOutput.tertiaryInputPtr,          /* uint8* RequestData */
      job->jobPrimitiveInputOutput.tertiaryInputLength,       /* uint32 RequestDataLength */
      &certId);                                               /* KeyM_CertificateIdType* CertId */

    if (retVal == E_OK)
    {
      /* # Serialize certificate identifier */
      KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(certId, job->jobPrimitiveInputOutput.outputPtr);

      /* # Wait until KeyM has finished the service */
      KeyM_Remote_ProcessService();
    }
  }

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_VerifyGroup()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_VerifyGroup(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateGroupIdType groupId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check input and output parameters */
  if ((job->jobPrimitiveInputOutput.secondaryInputPtr == NULL_PTR)
    || (job->jobPrimitiveInputOutput.secondaryInputLength != KEYM_REMOTE_GROUPID_SIZE))
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else
  {
    /*@ assert $lengthOf(job->jobPrimitiveInputOutput.secondaryInputPtr) == KEYM_REMOTE_GROUPID_SIZE; */ /* VCA_KEYM_REMOTE_JOBDISPATCHING_INPUTOUTPUTLENGTH */

    /* # Retrieve group identifier from job->jobPrimitiveInputOutput.secondaryInputPtr */
    groupId = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(job->jobPrimitiveInputOutput.secondaryInputPtr);

    /* # Forward call to KeyM_VerifyGroup to process the requested service */
    retVal = KeyM_VerifyGroup(groupId);

    if (retVal == E_OK)
    {
      /* # Wait until KeyM has finished the service */
      KeyM_Remote_ProcessService();
    }
  }

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */
#endif

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_SetCertificate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_SetCertificate(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  uint32 keyLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType)cryptoKeyId;
  KeyM_ConstCertDataType cert;

  /* ----- Implementation ----------------------------------------------- */
  cert.certData = (KeyM_ConstCertDataPointerType)keyPtr;
  cert.certDataLength = keyLength;

  /* # Forward call to KeyM_SetCertificateWithConstPtr to process the requested service */
  retVal = KeyM_SetCertificateWithConstPtr(certId, &cert);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_CertDelete()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertDelete(
  uint32 cryptoKeyId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType)cryptoKeyId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Forward call to KeyM_CertDelete to process the requested service */
  retVal = KeyM_CertDelete(certId);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_CRE == STD_ON)
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_SetCRE()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_SetCRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  uint32 keyLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint16 issuerNameDataLength;
  uint16 serialNumberDataLength;

  /* ----- Implementation ----------------------------------------------- */
  if (keyLength == KEYM_REMOTE_CREINFO_SIZE)
  {
    /*@ assert $lengthOf(keyPtr) == KEYM_REMOTE_CREINFO_SIZE; */ /* VCA_KEYM_POINTERLENGTH_APICONTRACT */

    /* # Retrieve issuer name and serial number data length from keyPtr */
    issuerNameDataLength = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(&keyPtr[KEYM_REMOTE_CRE_ISSUERNAME_LENGTH_POS]);
    serialNumberDataLength = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(&keyPtr[KEYM_REMOTE_CRE_SERIALNUMBER_LENGTH_POS]);

    /* # Forward call to KeyM_SetCRE to process the requested service */
    retVal = KeyM_SetCRE(&keyPtr[KEYM_REMOTE_CRE_ISSUERNAME_POS], issuerNameDataLength, &keyPtr[KEYM_REMOTE_CRE_SERIALNUMBER_POS], serialNumberDataLength);
  }
  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */
#endif

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_CsrElementSet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CsrElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  uint32 keyLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType)cryptoKeyId;
  KeyM_CertElementIdType certElementId;
  KeyM_CsrEncodingType encodingType;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve certificate element identifier */
  certElementId = (KeyM_CertElementIdType)((keyElementId & KEYM_REMOTE_CERTELEMENTID_MASK) >> 8u);

  /* # Retrieve encoding type */
  encodingType = (KeyM_CsrEncodingType)((keyElementId & KEYM_REMOTE_ENCODINGTYPE_MASK) >> 24u);

  /* # Forward call to KeyM_CsrElementSet to process the requested service */
  retVal = KeyM_CsrElementSet(certId, certElementId, encodingType, keyPtr, keyLength);

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */
#endif

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_GetCertificate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_GetCertificate(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType)cryptoKeyId;
  KeyM_CertDataType cert;

  /* ----- Implementation ----------------------------------------------- */
  cert.certData = (KeyM_CertDataPointerType)keyPtr;
  cert.certDataLength = *keyLengthPtr;

  /* # Forward call to KeyM_GetCertificate to process the requested service */
  retVal = KeyM_GetCertificate(certId, &cert);
  *keyLengthPtr = cert.certDataLength;

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_CertElementGet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType)cryptoKeyId;
  KeyM_CertElementIdType certElementId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve certificate element identifier */
  certElementId = (KeyM_CertElementIdType)((keyElementId & KEYM_REMOTE_CERTELEMENTID_MASK) >> 8u);

  /* # Forward call to KeyM_CertElementGet to process the requested service */
  retVal = KeyM_CertElementGet(certId, certElementId, keyPtr, keyLengthPtr);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_CertGetStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertGetStatus(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2CONST(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType)cryptoKeyId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Forward call to KeyM_CertGetStatus to process the requested service */
  if (*keyLengthPtr == KEYM_REMOTE_STATUS_SIZE)
  {
    retVal = KeyM_CertGetStatus(certId, keyPtr);
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_CertificateElementGetByIndex()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertificateElementGetByIndex(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType)cryptoKeyId;
  KeyM_CertElementIdType certElementId;
  uint8 index;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve certificate element identifier */
  certElementId = (KeyM_CertElementIdType)((keyElementId & KEYM_REMOTE_CERTELEMENTID_MASK) >> 8u);

  /* # Retrieve certificate element index */
  index = (uint8)((keyElementId & KEYM_REMOTE_INDEX_MASK) >> 24);

  /* # Forward call to KeyM_CertificateElementGetByIndex to process the requested service */
  retVal = KeyM_CertificateElementGetByIndex(certId, certElementId, index, keyPtr, keyLengthPtr);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_CertificateElementGetCount()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertificateElementGetCount(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2CONST(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType)cryptoKeyId;
  KeyM_CertElementIdType certElementId;
  uint16 count;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve certificate element identifier */
  certElementId = (KeyM_CertElementIdType)((keyElementId & KEYM_REMOTE_CERTELEMENTID_MASK) >> 8u);

  /* # Forward call to KeyM_CertificateElementGetByIndex to process the requested service */
  retVal = KeyM_CertificateElementGetCount(certId, certElementId, &count);

  if ((retVal == E_OK) && (*keyLengthPtr == KEYM_REMOTE_ITERATED_ELEMENT_COUNT_SIZE))
  {
    /*@ assert $lengthOf(keyPtr) == KEYM_REMOTE_ITERATED_ELEMENT_COUNT_SIZE; */ /* VCA_KEYM_POINTERLENGTH_APICONTRACT */

    /* # Serialize element count */
    KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(count, keyPtr);
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_CertStructureGet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertStructureGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType)cryptoKeyId;
  uint16 certStructure;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve certificate structure type */
  certStructure = (uint16)((keyElementId & KEYM_REMOTE_CERTSTRUCTURE_MASK) >> 8u);

  /* # Forward call to KeyM_CertStructureGet to process the requested service */
  retVal = KeyM_CertStructureGet(certId, (KeyM_CertificateStructureType)certStructure, keyPtr, keyLengthPtr);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_CertInfoGet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_CertInfoGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType)cryptoKeyId;
  uint16 certInfoType = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve certificate information type */
  certInfoType = (KeyM_CertElementIdType)((keyElementId & KEYM_REMOTE_CERTINFO_MASK) >> 8u);

  /* # Forward call to KeyM_CertInfoGet to process the requested service */
  retVal = KeyM_CertInfoGet(certId, (KeyM_CertificateInfoType)certInfoType, keyPtr, keyLengthPtr);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING
/**********************************************************************************************************************
 *  KeyM_Remote_GetIssuerCertId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_GetIssuerCertId(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2CONST(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType)cryptoKeyId;
  KeyM_CertificateIdType issuerCertId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Forward call to KeyM_GetIssuerCertId to process the requested service */
  retVal = KeyM_GetIssuerCertId(certId, &issuerCertId);

  if ((retVal == E_OK) && (*keyLengthPtr == KEYM_REMOTE_CERTID_SIZE))
  {
    /* # Serialize issuer certificate identifier */
    /*@ assert $lengthOf(keyPtr) == KEYM_REMOTE_CERTID_SIZE; */ /* VCA_KEYM_POINTERLENGTH_APICONTRACT */
    KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(issuerCertId, keyPtr);
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_CERTHASHSTORAGEUSEDOFCERTIFICATE == STD_ON)
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_GetCertHash()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_GetCertHash(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType)cryptoKeyId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Forward call to KeyM_GetCertHash to process the requested service */
  retVal = KeyM_GetCertHash(certId, keyPtr, keyLengthPtr);

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) */
#endif

#if (KEYM_CERTPUBKEYHASHSTORAGEUSEDOFCERTIFICATE == STD_ON)
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_GetPubKeyHash()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_GetPubKeyHash(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType)cryptoKeyId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Forward call to KeyM_GetPubKeyHash to process the requested service */
  retVal = KeyM_GetPubKeyHash(certId, keyPtr, keyLengthPtr);

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) */
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectServiceCertificate()
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
 */
/* PRQA S 6050, 6060 9 */ /* MD_MSR_STCAL, MD_KEYM_6060_LOCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectServiceCertificate(
  KeyM_CertificateIdType CertId,
  KeyM_ServiceCertificateType Service,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  uint8 remoteService[KEYM_REMOTE_SERVICE_SIZE];
  uint32 responseDataLength = ResponseDataLength;
#   if (KEYM_SERVICECALLBACK_USED)
  KeyM_ResultType serviceResult = KEYM_RT_NOT_OK;
#   endif
  Crypto_VerifyResultType verifyRes = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Retrieve remote service */
  retVal = KeyM_Remote_GetRemoteService(Service, KEYM_REMOTE_SERVICE_MODE_BYCERTNAME, remoteService);

  if (retVal == E_OK)
  {
    /* # Check if KeyM is currently busy with other remote jobs */
    SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
    if (KeyM_Remote_TaskState == KEYM_REMOTE_TASKSTATE_IDLE)
    {
      KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_BUSY;
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

      /* # Redirect service request through CSM job */
      csmResult = Csm_AEADDecrypt( /* VCA_KEYM_REMOTE_AEADDECRYPT_SERVICECERTIFICATE */
        KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate((KeyM_CertificateIterType)CertId),
        CRYPTO_OPERATIONMODE_SINGLECALL,
        remoteService,
        KEYM_REMOTE_SERVICE_SIZE,
        CertNamePtr,
        CertNameLength,
        RequestData,
        RequestDataLength,
        ResponseData,
        &responseDataLength,
        &verifyRes);

      /* # Handle CSM result */
      retVal = KeyM_Remote_HandleCsmResult(csmResult);

#   if (KEYM_SERVICECALLBACK_USED)
      if (retVal == E_OK)
      {
        serviceResult = KEYM_RT_OK;
      }

      /* # Notify application  */
      KeyM_Cert_ServiceCertificateCallbackNotificationInternal(CertId, serviceResult, 0u, NULL_PTR);
#   endif
      KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_IDLE;
    }
    else
    {
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
      retVal = KEYM_E_BUSY;
    }
  }

  KEYM_DUMMY_STATEMENT(responseDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(verifyRes); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
#endif

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# if (KEYM_REMOTE_OCSPENABLED == STD_ON)
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectServiceCertificateOCSP()
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
 */
/* PRQA S 6060 8 */ /* MD_KEYM_6060_LOCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectServiceCertificateOCSP(
  KeyM_ServiceCertificateType Service,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  uint8 remoteService[KEYM_REMOTE_SERVICE_SIZE];
  uint32 responseDataLength = ResponseDataLength;
  Crypto_VerifyResultType verifyRes = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if KeyM is currently busy with other remote jobs */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
  if (KeyM_Remote_TaskState == KEYM_REMOTE_TASKSTATE_IDLE)
  {
    KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_BUSY;
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

    /* # Retrieve remote service */
    retVal = KeyM_Remote_GetRemoteService(Service, KEYM_REMOTE_SERVICE_MODE_BYCERTNAME, remoteService);

    if (retVal == E_OK)
    {

      /* # Redirect service request through CSM job */
      csmResult = Csm_AEADDecrypt( /* VCA_KEYM_REMOTE_AEADDECRYPT_SERVICECERTIFICATEOCSP */
        KeyM_GetCsmRemoteInfoJobRefOfGeneral(),
        CRYPTO_OPERATIONMODE_SINGLECALL,
        remoteService,
        KEYM_REMOTE_SERVICE_SIZE,
        CertNamePtr,
        CertNameLength,
        RequestData,
        RequestDataLength,
        ResponseData,
        &responseDataLength,
        &verifyRes);

      /* # Handle CSM result */
      retVal = KeyM_Remote_HandleCsmResult(csmResult);
    }

    KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_IDLE;
  }
  else
  {
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
    retVal = KEYM_E_BUSY;
  }

  KEYM_DUMMY_STATEMENT(responseDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(verifyRes); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectServiceCertificateById()
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
/* PRQA S 6050, 6060 7 */ /* MD_MSR_STCAL, MD_KEYM_6060_LOCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectServiceCertificateById(
  KeyM_ServiceCertificateType Service,
  KeyM_CertificateIdType CertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  uint32 responseDataLength = ResponseDataLength;
  uint8 remoteService[KEYM_REMOTE_SERVICE_SIZE];
#   if (KEYM_SERVICECALLBACK_USED)
  KeyM_ResultType serviceResult = KEYM_RT_NOT_OK;
#   endif

  uint8 secondaryInput = 0u;
  Crypto_VerifyResultType verifyRes = 0u;

  /* ----- Implementation ----------------------------------------------- */

  /* # Retrieve remote service */
  retVal = KeyM_Remote_GetRemoteService(Service, KEYM_REMOTE_SERVICE_MODE_BYCERTID, remoteService);

  if (retVal == E_OK)
  {

    /* # Check if KeyM is currently busy with other remote jobs */
    SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
    if (KeyM_Remote_TaskState == KEYM_REMOTE_TASKSTATE_IDLE)
    {
      KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_BUSY;
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

      /* # Redirect service request through CSM job */
      csmResult = Csm_AEADDecrypt( /* VCA_KEYM_REMOTE_AEADDECRYPT_SERVICECERTIFICATEBYID */
        KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate((KeyM_CertificateIterType)CertId),
        CRYPTO_OPERATIONMODE_SINGLECALL,
        remoteService,
        KEYM_REMOTE_SERVICE_SIZE,
        &secondaryInput,
        0u,
        RequestData,
        RequestDataLength,
        ResponseData,
        &responseDataLength,
        &verifyRes);

      /* # Handle CSM result */
      retVal = KeyM_Remote_HandleCsmResult(csmResult);

#   if (KEYM_SERVICECALLBACK_USED)
      if (retVal == E_OK)
      {
        serviceResult = KEYM_RT_OK;
      }
      /* # Notify application  */
      KeyM_Cert_ServiceCertificateCallbackNotificationInternal(CertId, serviceResult, 0u, NULL_PTR);
#   endif
      KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_IDLE;
    }
    else
    {
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
      retVal = KEYM_E_BUSY;
    }
  }

  KEYM_DUMMY_STATEMENT(responseDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(secondaryInput); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(verifyRes); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
#endif

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectSetCertificate()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectSetCertificate(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Redirect service request through key management module */
  csmResult = Csm_KeyElementSet( /* VCA_KEYM_REMOTE_KEYELEMENTSET_SETCERTIFICATE */
    KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)CertId),
    (uint32)KEYM_REMOTE_SERVICE_SETCERTIFICATE,
    CertificateDataPtr->certData,
    CertificateDataPtr->certDataLength);

  /* # Handle CSM result */
  retVal = KeyM_Remote_HandleCsmResult(csmResult);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectGetCertificate()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectGetCertificate(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertDataType, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Redirect service request through key management module */
  csmResult = Csm_KeyElementGet( /* VCA_KEYM_REMOTE_KEYELEMENTGET_GETCERTIFICATE */
    KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)CertId),
    KEYM_REMOTE_SERVICE_GETCERTIFICATE,
    CertificateDataPtr->certData,
    &CertificateDataPtr->certDataLength);

  /* # Handle CSM result */
  retVal = KeyM_Remote_HandleCsmResult(csmResult);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectCertElementGet()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCertElementGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;
  uint32 keyElementId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Serialize certificate element identifier and remote service */
  keyElementId = (((uint32)CertElementId << 8u) | ((uint32)KEYM_REMOTE_SERVICE_CERTELEMENTGET));

  /* # Redirect service request through key management module */
  csmResult = Csm_KeyElementGet( /* VCA_KEYM_REMOTE_KEYELEMENTGET_CERTELEMENTGET */
    KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)CertId),
    keyElementId,
    CertElementData,
    CertElementDataLength);

  /* # Handle CSM result */
  retVal = KeyM_Remote_HandleCsmResult(csmResult);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectCertificateElementGetByIndex()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCertificateElementGetByIndex(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  uint16 Index,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;
  uint32 keyElementId;
  uint8 localIndex = (uint8)Index;

  /* ----- Implementation ----------------------------------------------- */
  /* # Serialize certificate element index, certificate element identifier and remote service */
  keyElementId = ((((uint32)localIndex << 24u) | ((uint32)CertElementId << 8u) | ((uint32)KEYM_REMOTE_SERVICE_CERTELEMENTGETBYINDEX)));

  /* # Redirect service request through key management module */
  csmResult = Csm_KeyElementGet( /* VCA_KEYM_REMOTE_KEYELEMENTGET_CERTIFICATEELEMENTGETBYINDEX */
    KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)CertId),
    keyElementId,
    CertElementData,
    CertElementDataLength);

  /* # Handle CSM result */
  retVal = KeyM_Remote_HandleCsmResult(csmResult);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectCertificateElementGetCount()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCertificateElementGetCount(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) Count)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;
  uint32 keyElementId;
  uint8 outputBuffer[KEYM_REMOTE_ITERATED_ELEMENT_COUNT_SIZE];
  uint32 outputBufferLength = KEYM_REMOTE_ITERATED_ELEMENT_COUNT_SIZE;

  /* ----- Implementation ----------------------------------------------- */
  /* # Serialize certificate element identifier and remote service */
  keyElementId = (((uint32)CertElementId << 8u) | ((uint32)KEYM_REMOTE_SERVICE_CERTELEMENTGETCOUNT));

  /* # Redirect service request through key management module */
  csmResult = Csm_KeyElementGet(
    KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)CertId),
    keyElementId,
    outputBuffer,
    &outputBufferLength);

  /* # Handle CSM result */
  retVal = KeyM_Remote_HandleCsmResult(csmResult);

  if (outputBufferLength != KEYM_REMOTE_ITERATED_ELEMENT_COUNT_SIZE)
  {
    retVal = E_NOT_OK;
  }

  if (retVal == E_OK)
  {
    *Count = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(outputBuffer);
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectSetCertificateInGroup()
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
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectSetCertificateInGroup(
  KeyM_CertificateGroupIdType GroupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) CertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  uint8 remoteService = KEYM_REMOTE_SERVICE_SETCERTIFICATEINGROUP;
  uint8 remoteGroupId[KEYM_REMOTE_GROUPID_SIZE];
  uint8 outputBuffer[KEYM_REMOTE_CERTID_SIZE];
  uint32 outputBufferLength = KEYM_REMOTE_CERTID_SIZE;
  Crypto_VerifyResultType verifyRes = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if KeyM is currently busy with other remote jobs */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
  if (KeyM_Remote_TaskState == KEYM_REMOTE_TASKSTATE_IDLE)
  {
    KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_BUSY;
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

    /* # Serialize group identifier */
    KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(KeyM_GetCertificateRemoteGroupIdOfCertificateGroup((KeyM_CertificateGroupIterType)GroupId), remoteGroupId);

    /* # Redirect service request through CSM job */
    csmResult = Csm_AEADDecrypt( /* VCA_KEYM_REMOTE_AEADDECRYPT_SETCERTIFICATEINGROUP */
      KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate(KeyM_GetCertificateIdxOfGroupInd(KeyM_GetGroupIndCertStartIdxOfCertificateGroup((KeyM_CertificateGroupIterType)GroupId))),
      CRYPTO_OPERATIONMODE_SINGLECALL,
      &remoteService,
      KEYM_REMOTE_SERVICETYPE_SIZE,
      remoteGroupId,
      KEYM_REMOTE_GROUPID_SIZE,
      RequestData,
      RequestDataLength,
      outputBuffer,
      &outputBufferLength,
      &verifyRes);

    /* # Handle CSM result */
    retVal = KeyM_Remote_HandleCsmResult(csmResult);

    if ((retVal == E_OK) && (outputBufferLength == KEYM_REMOTE_CERTID_SIZE))
    {
      *CertId = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(outputBuffer);
    }
    else
    {
      retVal = E_NOT_OK;
    }
    KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_IDLE;
  }
  else
  {
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
    retVal = KEYM_E_BUSY;
  }

  KEYM_DUMMY_STATEMENT(verifyRes); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectVerifyGroup()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectVerifyGroup(
  KeyM_CertificateGroupIdType GroupId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType csmResult;
  uint8 remoteService = KEYM_REMOTE_SERVICE_VERIFYGROUP;
  uint8 remoteGroupId[KEYM_REMOTE_GROUPID_SIZE];
  uint8 tertiaryInput = 0u;
  uint8 output = 0u;
  uint32 outputBufferLength = 1u;
  Crypto_VerifyResultType verifyRes = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if KeyM is currently busy with other remote jobs */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
  if (KeyM_Remote_TaskState == KEYM_REMOTE_TASKSTATE_IDLE)
  {
    KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_BUSY;
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

    /* # Serialize group identifier */
    KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(KeyM_GetCertificateRemoteGroupIdOfCertificateGroup((KeyM_CertificateGroupIterType)GroupId), remoteGroupId);

    /* # Redirect service request through CSM job */
    csmResult = Csm_AEADDecrypt(
      KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate(KeyM_GetCertificateIdxOfGroupInd(KeyM_GetGroupIndCertStartIdxOfCertificateGroup((KeyM_CertificateGroupIterType)GroupId))),
      CRYPTO_OPERATIONMODE_SINGLECALL,
      &remoteService,
      KEYM_REMOTE_SERVICETYPE_SIZE,
      remoteGroupId,
      KEYM_REMOTE_GROUPID_SIZE,
      &tertiaryInput,
      0u,
      &output,
      &outputBufferLength,
      &verifyRes);

    /* # Handle CSM result */
    retVal = KeyM_Remote_HandleCsmResult(csmResult);
    KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_IDLE;
  }
  else
  {
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
    retVal = KEYM_E_BUSY;
  }

  KEYM_DUMMY_STATEMENT(tertiaryInput); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(output); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(outputBufferLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(verifyRes); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
#endif

#if (KEYM_CRE == STD_ON)
# if (KEYM_REMOTE_CREENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE*/
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectSetCRE()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectSetCRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal = E_NOT_OK;
  uint8 creInfo[KEYM_REMOTE_CREINFO_SIZE];

  /* ----- Implementation ----------------------------------------------- */
  /* # Serialize issuername and serial number data length */
  KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(IssuerNameDataLength, &creInfo[KEYM_REMOTE_CRE_ISSUERNAME_LENGTH_POS]);
  KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(SerialNumberDataLength, &creInfo[KEYM_REMOTE_CRE_SERIALNUMBER_LENGTH_POS]);

  /* Check issuer name and serial number data length */
  if ((IssuerNameDataLength <= KEYM_CREMAX_LENGTH_OF_ISSUER_NAME) && (SerialNumberDataLength <= KEYM_CREMAX_LENGTH_OF_SERIAL_NUMBER))
  {
    /* # Serialize issuername and serial number */
    VStdLib_MemCpyLarge(&creInfo[KEYM_REMOTE_CRE_ISSUERNAME_POS], IssuerNameData, IssuerNameDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    VStdLib_MemCpyLarge(&creInfo[KEYM_REMOTE_CRE_SERIALNUMBER_POS], SerialNumberData, SerialNumberDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

    /* # Redirect service request through key management module */
    csmResult = Csm_KeyElementSet(
      KeyM_GetCsmRemoteInfoKeyRefOfGeneral(),
      (uint32)KEYM_REMOTE_SERVICE_SETCRE,
      creInfo,
      (uint32)KEYM_REMOTE_CREINFO_SIZE);

    /* # Handle CSM result */
    retVal = KeyM_Remote_HandleCsmResult(csmResult);
  }

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif
#endif

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectCertStructureGet()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCertStructureGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertStructureData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertStructureDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;
  uint32 keyElementId;
  uint16 certStructure = (uint16)CertStructure;

  /* ----- Implementation ----------------------------------------------- */
  /* # Serialize certStructure type and remote service */
  keyElementId = (((uint32)certStructure << 8u) | ((uint32)KEYM_REMOTE_SERVICE_CERTSTRUCTUREGET));

  /* # Redirect service request through key management module */
  csmResult = Csm_KeyElementGet( /* VCA_KEYM_REMOTE_KEYELEMENTGET_CERTSTRUCTUREGET */
    KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)CertId),
    keyElementId,
    CertStructureData,
    CertStructureDataLength);

  /* # Handle CSM result */
  retVal = KeyM_Remote_HandleCsmResult(csmResult);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectGetIssuerCertId()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectGetIssuerCertId(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) IssuerCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;
  uint8 outputBuffer[KEYM_REMOTE_CERTID_SIZE];
  uint32 outputBufferLength = KEYM_REMOTE_CERTID_SIZE;

  /* ----- Implementation ----------------------------------------------- */
  /* # Redirect service request through key management module */
  csmResult = Csm_KeyElementGet(
    KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)CertId),
    KEYM_REMOTE_SERVICE_GETISSUERCERTID,
    outputBuffer,
    &outputBufferLength);

  /* # Handle CSM result */
  retVal = KeyM_Remote_HandleCsmResult(csmResult);

  if (outputBufferLength != KEYM_REMOTE_CERTID_SIZE)
  {
    retVal = E_NOT_OK;
  }

  if (retVal == E_OK)
  {
    *IssuerCertId = KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(outputBuffer);
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectGetCertHash()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectGetCertHash(
  KeyM_CertificateIdType CertId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) HashData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) HashDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Redirect service request through key management module */
  csmResult = Csm_KeyElementGet( /* VCA_KEYM_REMOTE_KEYELEMENTGET_GETCERTHASH */
    KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)CertId),
    KEYM_REMOTE_SERVICE_GETCERTHASH,
    HashData,
    HashDataLength);

  /* # Handle CSM result */
  retVal = KeyM_Remote_HandleCsmResult(csmResult);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectGetPubKeyHash()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectGetPubKeyHash(
  KeyM_CertificateIdType CertId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) HashData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) HashDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Redirect service request through key management module */
  csmResult = Csm_KeyElementGet( /* VCA_KEYM_REMOTE_KEYELEMENTGET_GETCERTHASH */
    KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)CertId),
    KEYM_REMOTE_SERVICE_GETPUBKEYHASH,
    HashData,
    HashDataLength);

  /* # Handle CSM result */
  retVal = KeyM_Remote_HandleCsmResult(csmResult);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectCertDelete()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCertDelete(
  KeyM_CertificateIdType CertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;
  uint8 input = 0u;
  uint32 inputLength = 1u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Redirect service request through key management module */
  csmResult = Csm_KeyElementSet( /* VCA_KEYM_REMOTE_KEYELEMENTSET_SETCERTIFICATE */
    KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)CertId),
    (uint32)KEYM_REMOTE_SERVICE_CERTDELETE,
    &input,
    inputLength);

  /* # Handle CSM result */
  retVal = KeyM_Remote_HandleCsmResult(csmResult);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectCertInfoGet()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCertInfoGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateInfoType CertInfoType,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertInfoData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertInfoDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult = E_NOT_OK;
  Std_ReturnType retVal = E_NOT_OK;
  uint32 keyElementId = 0u;
  uint16 certInfoType = (uint16)CertInfoType;

  /* ----- Implementation ----------------------------------------------- */
  /* # Serialize certInfoType and remote service */
  keyElementId = (((uint32)certInfoType << 8u) | ((uint32)KEYM_REMOTE_SERVICE_CERTINFOGET));

  /* # Redirect service request through key management module */
  csmResult = Csm_KeyElementGet( /* VCA_KEYM_REMOTE_KEYELEMENTGET_CERTINFOGET */
    KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)CertId),
    keyElementId,
    CertInfoData,
    CertInfoDataLength);

  /* # Handle CSM result */
  retVal = KeyM_Remote_HandleCsmResult(csmResult);

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
#  ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectCsrElementSet()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCsrElementSet(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  KeyM_CsrEncodingType EncodingType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) ElementData,
  uint32 ElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;
  uint32 keyElementId;

  /* ----- Implementation ----------------------------------------------- */
  /* # Serialize encoding type, certificate element identifier and remote service */
  keyElementId = (((uint32)EncodingType << 24u) | ((uint32)CertElementId << 8u) | ((uint32)KEYM_REMOTE_SERVICE_CSRELEMENTSET));

  /* # Redirect service request through key management module */
  csmResult = Csm_KeyElementSet( /* VCA_KEYM_REMOTE_KEYELEMENTSET_CSRELEMENTSET */
    KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)CertId),
    keyElementId,
    ElementData,
    ElementDataLength);

  /* # Handle CSM result */
  retVal = KeyM_Remote_HandleCsmResult(csmResult);

  return retVal;
}
#  endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
#endif

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectCertGetStatus()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCertGetStatus(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertificateStatusType, AUTOMATIC, KEYM_APPL_VAR) Status)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;
  uint32 keyLength = KEYM_REMOTE_STATUS_SIZE;

  /* ----- Implementation ----------------------------------------------- */
  /* # Redirect service request through key management module */
  csmResult = Csm_KeyElementGet(
    KeyM_GetCertCsmSignatureVerifyKeyRefOfCertificate((KeyM_CertificateIterType)CertId),
    KEYM_REMOTE_SERVICE_CERTGETSTATUS,
    Status,
    &keyLength);

  /* # Handle CSM result */
  retVal = KeyM_Remote_HandleCsmResult(csmResult);

  if (keyLength != KEYM_REMOTE_STATUS_SIZE)
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectVerifyCertificates()
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
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectVerifyCertificates(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateIdType CertUpperId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;
  uint8 remoteService;
  uint8 remoteCertId[KEYM_REMOTE_CERTID_SIZE];
  uint8 tertiaryInput = 0u;
  uint8 output = 0u;
  uint32 outputLength = 1u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if KeyM is currently busy with other remote jobs */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
  if (KeyM_Remote_TaskState == KEYM_REMOTE_TASKSTATE_IDLE)
  {
    /* initialize verifyRes with NOT_OK so we will report an error to the callback even if the CSM call returns an error code */
    Crypto_VerifyResultType verifyRes = CRYPTO_E_VER_NOT_OK;

    KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_BUSY;
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

    /* # Set remote service type */
    remoteService = KEYM_REMOTE_SERVICE_VERIFYCERTIFICATES;

    /* # Serialize certificate identifier */
    KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(KeyM_GetRemoteCertificateIdOfCertificate((KeyM_CertificateIterType)CertUpperId), remoteCertId);

    /* # Redirect service request through CSM job */
    csmResult = Csm_AEADDecrypt(
      KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate((KeyM_CertificateIterType)CertId),
      CRYPTO_OPERATIONMODE_SINGLECALL,
      &remoteService,
      KEYM_REMOTE_SERVICETYPE_SIZE,
      remoteCertId,
      KEYM_REMOTE_CERTID_SIZE,
      &tertiaryInput,
      0u,
      &output,
      &outputLength,
      &verifyRes);

    /* # Handle CSM result */
    retVal = KeyM_Remote_HandleCsmResult(csmResult);

    /* # Call certificate verify callback notification for application */
    KeyM_Cert_VerifyCallbackNotificationInternal(CertId, verifyRes);
    KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_IDLE;
  }
  else
  {
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
    retVal = KEYM_E_BUSY;
  }

  KEYM_DUMMY_STATEMENT(tertiaryInput); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(output); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(outputLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectVerifyCertificate()
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
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectVerifyCertificate(
  KeyM_CertificateIdType CertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal;
  uint8 remoteService;
  uint8 secondaryInput = 0u;
  uint8 tertiaryInput = 0u;
  uint8 output = 0u;
  uint32 outputLength = 1u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if KeyM is currently busy with other remote jobs */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
  if (KeyM_Remote_TaskState == KEYM_REMOTE_TASKSTATE_IDLE)
  {
    /* initialize verifyRes with NOT_OK so we will report an error to the callback even if the CSM call returns an error code */
    Crypto_VerifyResultType verifyRes = CRYPTO_E_VER_NOT_OK;

    KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_BUSY;
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

    /* # Set remote service type */
    remoteService = KEYM_REMOTE_SERVICE_VERIFYCERTIFICATE;

    /* # Redirect service request through CSM job */
    csmResult = Csm_AEADDecrypt(
      KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate((KeyM_CertificateIterType)CertId),
      CRYPTO_OPERATIONMODE_SINGLECALL,
      &remoteService,
      KEYM_REMOTE_SERVICETYPE_SIZE,
      &secondaryInput,
      0u,
      &tertiaryInput,
      0u,
      &output,
      &outputLength,
      &verifyRes);

    /* # Handle CSM result */
    retVal = KeyM_Remote_HandleCsmResult(csmResult);

    /* # Call certificate verify callback notification for application */
    KeyM_Cert_VerifyCallbackNotificationInternal(CertId, verifyRes);
    KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_IDLE;
  }
  else
  {
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
    retVal = KEYM_E_BUSY;
  }

  KEYM_DUMMY_STATEMENT(secondaryInput); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(tertiaryInput); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(output); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(outputLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

#if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_RedirectVerifyCertificateChain()
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
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectVerifyCertificateChain(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 NumberOfCertificates)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType csmResult;
  Std_ReturnType retVal = E_OK;
  Crypto_VerifyResultType verifyRes = 0u;
  uint8 remoteService;
  uint8 numOfCertificates = NumberOfCertificates;
  uint8 output = 0u;
  uint32 outputLength = 1u;
  uint8 serializedCertChainData[KEYM_REMOTE_CERTIFICATE_CHAIN_MAX_LENGTH] = { 0u };
  uint32 serializedCertChainDataLength;
  uint8_least i;
  uint32 writtenLength = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if KeyM is currently busy with other remote jobs */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
  if (KeyM_Remote_TaskState == KEYM_REMOTE_TASKSTATE_IDLE)
  {
    KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_BUSY;
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

    /* # Set remote service type */
    remoteService = KEYM_REMOTE_SERVICE_VERIFYCERTIFICATECHAIN;

    /* # Serialize certificate chain data */
    for (i = 0; i < numOfCertificates; i++)
    {
      /* Array bounds check */
      if ((writtenLength + (certChainData[i].certDataLength) + KEYM_REMOTE_CERTIFICATE_CHAIN_POS_CERTDATA) > KEYM_REMOTE_CERTIFICATE_CHAIN_MAX_LENGTH)
      {
        retVal = E_NOT_OK;
        break;
      }
      else
      {
        /* Set certificate data length */
        KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian((uint16)certChainData[i].certDataLength, &serializedCertChainData[writtenLength]); /* VCA_KEYM_REMOTE_REDIRECTVERIFYCHAIN_CONVERTUINT16 */

        /* Set certificate data */
        VStdLib_MemCpyLarge(&serializedCertChainData[writtenLength + (uint32)KEYM_REMOTE_CERTIFICATE_CHAIN_POS_CERTDATA], certChainData[i].certData, certChainData[i].certDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_REMOTE_REDIRECTVERIFYCHAIN_MEMCPY */
        writtenLength += (uint32)certChainData[i].certDataLength + (uint32)KEYM_REMOTE_CERTIFICATE_CHAIN_POS_CERTDATA;
      }
    }

    if (retVal == E_OK)
    {
      serializedCertChainDataLength = writtenLength;

      /* # Redirect service request through CSM job */
      csmResult = Csm_AEADDecrypt( /* VCA_KEYM_REMOTE_AEADDECRYPT_VERIFYCERTIFICATECHAIN */
        KeyM_GetCertCsmSignatureVerifyJobRefOfCertificate((KeyM_CertificateIterType)CertId),
        CRYPTO_OPERATIONMODE_SINGLECALL,
        &remoteService,
        KEYM_REMOTE_SERVICETYPE_SIZE,
        &numOfCertificates,
        KEYM_REMOTE_NUMOFCERTS_SIZE,
        serializedCertChainData,
        serializedCertChainDataLength,
        &output,
        &outputLength,
        &verifyRes);

      /* # Handle CSM result */
      retVal = KeyM_Remote_HandleCsmResult(csmResult);

      /* # Call certificate verify callback notification for application */
      KeyM_Cert_VerifyCallbackNotificationInternal(CertId, verifyRes);
    }

    KeyM_Remote_TaskState = KEYM_REMOTE_TASKSTATE_IDLE;
  }
  else
  {
    SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
    retVal = KEYM_E_BUSY;
  }

  KEYM_DUMMY_STATEMENT(output); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  KEYM_DUMMY_STATEMENT(outputLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON) */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_DispatchRemoteJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030, 6080 2 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_DispatchRemoteJob(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 remoteServiceType;

#  if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
  uint8 remoteServiceMode;
#  endif

  /* ----- Implementation ----------------------------------------------- */
  if ((job->jobPrimitiveInputOutput.inputPtr != NULL_PTR)
    && (job->jobPrimitiveInputOutput.inputLength >= KEYM_REMOTE_SERVICETYPE_SIZE))
  {
    remoteServiceType = *job->jobPrimitiveInputOutput.inputPtr;

    /* # Dispatch processing based on transferred remote service type */
    switch (remoteServiceType)
    {
#  if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_REQUEST_CSR:
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_SIGNED_CSR:
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_SET_ROOT:
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_ROOT:
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_SET_INTERMEDIATE:
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_INTERMEDIATE:
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_UPDATE_CRL:
    case KEYM_REMOTE_SERVICE_SERVICECERTIFICATE_CERT_STATUS_OCSP:
    {
      if (job->jobPrimitiveInputOutput.inputLength == KEYM_REMOTE_SERVICE_SIZE)
      {
        remoteServiceMode = job->jobPrimitiveInputOutput.inputPtr[KEYM_REMOTE_SERVICE_MODE_POS];

        if (remoteServiceMode == KEYM_REMOTE_SERVICE_MODE_BYCERTNAME)
        {
          retVal = KeyM_Remote_ServiceCertificate(job);
        }
        else if (remoteServiceMode == KEYM_REMOTE_SERVICE_MODE_BYCERTID)
        {
          retVal = KeyM_Remote_ServiceCertificateById(job);
        }
        else
        {
          retVal = E_NOT_OK;
        }
      }
      break;
    }
#  endif
    case KEYM_REMOTE_SERVICE_VERIFYCERTIFICATE:
    {
      retVal = KeyM_Remote_VerifyCertificate(job);
      break;
    }
    case KEYM_REMOTE_SERVICE_VERIFYCERTIFICATES:
    {
      retVal = KeyM_Remote_VerifyCertificates(job);
      break;
    }
    case KEYM_REMOTE_SERVICE_VERIFYCERTIFICATECHAIN:
    {
      retVal = KeyM_Remote_VerifyCertificateChain(job);
      break;
    }
#  if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
    case KEYM_REMOTE_SERVICE_SETCERTIFICATEINGROUP:
    {
      retVal = KeyM_Remote_SetCertificateInGroup(job);
      break;
    }
    case KEYM_REMOTE_SERVICE_VERIFYGROUP:
    {
      retVal = KeyM_Remote_VerifyGroup(job);
      break;
    }
#  endif
    default:
      /* Invalid remote service type. */
      retVal = E_NOT_OK;
      break;
    }
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_DispatchRemoteKeyElementSet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_DispatchRemoteKeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  uint32 keyLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Dispatch processing based on transferred remote service type */
  switch (keyElementId & KEYM_REMOTE_SERVICE_MASK)
  {
  case KEYM_REMOTE_SERVICE_SETCERTIFICATE:
  {
    retVal = KeyM_Remote_SetCertificate(cryptoKeyId, keyPtr, keyLength);
    break;
  }
#  if (KEYM_CRE == STD_ON)
  case KEYM_REMOTE_SERVICE_SETCRE:
  {
    retVal = KeyM_Remote_SetCRE(keyPtr, keyLength);
    break;
  }
#  endif
#  if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
  case KEYM_REMOTE_SERVICE_CSRELEMENTSET:
  {
    retVal = KeyM_Remote_CsrElementSet(cryptoKeyId, keyElementId, keyPtr, keyLength);
    break;
  }
#  endif
  case KEYM_REMOTE_SERVICE_CERTDELETE:
  {
    retVal = KeyM_Remote_CertDelete(cryptoKeyId);
    break;
  }
  default:
    /* Invalid remote service type. */
    retVal = E_NOT_OK;
    break;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

#if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
# ifndef KEYM_NOUNIT_REMOTEHANDLING /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Remote_DispatchRemoteKeyElementGet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030, 6050 5 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_DispatchRemoteKeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Dispatch processing based on transferred remote service type */
  switch (keyElementId & KEYM_REMOTE_SERVICE_MASK)
  {
  case KEYM_REMOTE_SERVICE_GETCERTIFICATE:
  {
    retVal = KeyM_Remote_GetCertificate(cryptoKeyId, keyPtr, keyLengthPtr);
    break;
  }
  case KEYM_REMOTE_SERVICE_CERTELEMENTGET:
  {
    retVal = KeyM_Remote_CertElementGet(cryptoKeyId, keyElementId, keyPtr, keyLengthPtr);
    break;
  }
  case KEYM_REMOTE_SERVICE_CERTGETSTATUS:
  {
    retVal = KeyM_Remote_CertGetStatus(cryptoKeyId, keyPtr, keyLengthPtr);
    break;
  }
  case KEYM_REMOTE_SERVICE_CERTELEMENTGETBYINDEX:
  {
    retVal = KeyM_Remote_CertificateElementGetByIndex(cryptoKeyId, keyElementId, keyPtr, keyLengthPtr);
    break;
  }
  case KEYM_REMOTE_SERVICE_CERTELEMENTGETCOUNT:
  {
    retVal = KeyM_Remote_CertificateElementGetCount(cryptoKeyId, keyElementId, keyPtr, keyLengthPtr);
    break;
  }
  case KEYM_REMOTE_SERVICE_CERTSTRUCTUREGET:
  {
    retVal = KeyM_Remote_CertStructureGet(cryptoKeyId, keyElementId, keyPtr, keyLengthPtr);
    break;
  }
  case KEYM_REMOTE_SERVICE_CERTINFOGET:
  {
    retVal = KeyM_Remote_CertInfoGet(cryptoKeyId, keyElementId, keyPtr, keyLengthPtr);
    break;
  }
  case KEYM_REMOTE_SERVICE_GETISSUERCERTID:
  {
    retVal = KeyM_Remote_GetIssuerCertId(cryptoKeyId, keyPtr, keyLengthPtr);
    break;
  }
# if (KEYM_CERTHASHSTORAGEUSEDOFCERTIFICATE == STD_ON)
  case KEYM_REMOTE_SERVICE_GETCERTHASH:
  {
    retVal = KeyM_Remote_GetCertHash(cryptoKeyId, keyPtr, keyLengthPtr);
    break;
  }
#  endif
# if (KEYM_CERTPUBKEYHASHSTORAGEUSEDOFCERTIFICATE == STD_ON)
  case KEYM_REMOTE_SERVICE_GETPUBKEYHASH:
  {
    retVal = KeyM_Remote_GetPubKeyHash(cryptoKeyId, keyPtr, keyLengthPtr);
    break;
  }
#  endif
  default:
    /* Invalid remote service type. */
    retVal = E_NOT_OK;
    break;
  }
  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_REMOTEHANDLING */
#endif /* (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) */

#define KEYM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/
