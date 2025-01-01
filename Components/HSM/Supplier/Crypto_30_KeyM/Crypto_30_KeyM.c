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
/*!        \file  Crypto_30_KeyM.c
 *        \brief  KeyM crypto driver source file.
 *      \details  Implements the the vHsm crypto driver for KeyM.
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_KEYM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_KeyM.h"
#include "KeyM.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* vendor specific version information is BCD coded */
#if (  (CRYPTO_30_KEYM_SW_MAJOR_VERSION != (0x01)) \
    || (CRYPTO_30_KEYM_SW_MINOR_VERSION != (0x02)) \
    || (CRYPTO_30_KEYM_SW_PATCH_VERSION != (0x01)) )
# error "Vendor specific version numbers of Crypto_30_KeyM.c and Crypto_30_KeyM.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (CRYPTO_30_KEYM_LOCAL)
# define CRYPTO_30_KEYM_LOCAL                                         static
#endif

#if !defined (CRYPTO_30_KEYM_LOCAL_INLINE)
# define CRYPTO_30_KEYM_LOCAL_INLINE                                  LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
 /* PRQA S 3453 8 */ /* MD_MSR_FctLikeMacro */
#define Crypto_30_KeyM_IsErrorState(status)                           (  (status == KEYM_CERTIFICATE_INVALID)                     \
                                                                      || (status == KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL)      \
                                                                      || (status == KEYM_E_CERTIFICATE_SIGNATURE_FAIL)            \
                                                                      || (status == KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST)    \
                                                                      || (status == KEYM_E_CERTIFICATE_INVALID_TYPE)              \
                                                                      || (status == KEYM_E_CERTIFICATE_INVALID_FORMAT)            \
                                                                      || (status == KEYM_E_CERTIFICATE_INVALID_CONTENT)           \
                                                                      || (status == KEYM_E_CERTIFICATE_REVOKED)                   )

  /*(De-)Serialization macros for the CertElement iterator and CSRInfo */ /* PRQA S 3453 3 */ /* MD_MSR_FctLikeMacro */
#define Crypto_30_KeyM_Uint16ToBigEndHiByte( value )                  (uint8)((uint16)(value) >> 8)
#define Crypto_30_KeyM_Uint16ToBigEndLoByte( value )                  (uint8)((uint16)(value) & 0x00FFu)
#define Crypto_30_KeyM_BigEndByteArrayToUint16( ptr, offset )         ((uint16)((((uint16)(ptr[offset])) << 8) | (uint8)(ptr[offset+1u])))

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CRYPTO_30_KEYM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

 /**********************************************************************************************************************
 *  Crypto_30_KeyM_GetMappedReturnValue()
 *********************************************************************************************************************/
 /*! \brief         Maps the input KeyM return value to a suitable Crypto return value.
 *  \details        This function implements a map of incoming KeyM return values to suitable Crypto values.
 *  \param[in]      rVal                        KeyM return value needs to be mapped.
 *  \return         E_OK                        Incoming return value was E_OK.
 *                  E_NOT_OK                    Incoming return value was E_NOT_OK or unknown.
 *                  CRYPTO_E_BUSY               Incoming return value was E_OK.
 *                  CRYPTO_E_QUEUE_FULL         Incoming return value was KEYM_E_PENDING.
 *                  CRYPTO_E_KEY_SIZE_MISMATCH  Incoming return value was KEYM_E_KEY_CERT_SIZE_MISMATCH.
 *                  CRYPTO_E_KEY_NOT_AVAILABLE  Incoming return value was KEYM_E_PARAMETER_MISMATCH.
 *                  CRYPTO_E_KEY_NOT_VALID      Incoming return value was KEYM_E_KEY_CERT_INVALID.
 *                  CRYPTO_E_KEY_READ_FAIL      Incoming return value was KEYM_E_KEY_CERT_READ_FAIL.
 *                  CRYPTO_E_KEY_EMPTY          Incoming return value was KEYM_E_KEY_CERT_EMPTY.
 *                  CRYPTO_E_KEY_WRITE_FAIL     Incoming return value was KEYM_E_CERT_INVALID_CHAIN_OF_TRUST.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_GetMappedReturnValue(
  Std_ReturnType rVal);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_GetCertElementIterator()
 *********************************************************************************************************************/
/*! \brief          De-serializes a KeyM_CertElementIteratorType.
 *  \details        This function de-serializes from a given input pointer a cerificate element iterator.
 *  \param[in]      inputPtr          Pointer to the serialized iterator.
 *  \param[in]      inputLength       Length of input pointer.
 *  \param[in,out]  iteratorPtr       Pointer to the resulting CertElementIterator.
 *  \return         E_OK              Deserialization succeed.
 *                  E_NOT_OK          Deserialization failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_GetCertElementIterator(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) inputPtr,
  uint32 inputLength,
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, AUTOMATIC) iteratorPtr);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_SetCertElementIterator()
 *********************************************************************************************************************/
/*! \brief          Serializes a KeyM_CertElementIteratorType.
 *  \details        This function serializes a cerificate element iterator into a byte array.
 *  \param[out]     resultPtr         Pointer to the serialized iterator.
 *  \param[out]     resultLengthPtr   Length pointer of result pointer.
 *  \param[in]      iteratorPtr       Pointer to the resulting CertElementIterator
 *  \return         E_OK              Serialization succeed.
 *                  E_NOT_OK          Serialization failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_SetCertElementIterator(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) resultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) resultLengthPtr,
  P2CONST(KeyM_CertElementIteratorType, AUTOMATIC, AUTOMATIC) iteratorPtr);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_WaitForKeyM()
 *********************************************************************************************************************/
/*! \brief          Wait until KeyM is not busy anymore.
 *  \details        This function will call the KeyM_MainFunction until KeyM has finished the requested operation.
 *  \param[in]      certId                Certificate ID of requested certificate.
 *  \param[in]      expectedStatus        Expected status of certificate.
 *  \return         CRYPTO_E_VER_OK       Expected status reached.
 *                  CRYPTO_E_VER_NOT_OK   Erroneous status reached.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL FUNC(Crypto_VerifyResultType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_WaitForKeyM(
  KeyM_CertificateIdType certId,
  KeyM_CertificateStatusType expectedStatus);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_WaitForCertStatus()
 *********************************************************************************************************************/
/*! \brief          Wait until certificate reaches a specific or erroneous status.
 *  \details        This function will call the KeyM_MainFunction until a cerificate has reached a specific or erroneous status.
 *  \param[in]      certId            Certificate ID of requested certificate.
 *  \param[in]      expectedStatus    Expected status of certificate.
 *  \return         E_OK              Expected status reached.
 *                  E_NOT_OK          Erroneous status reached.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_WaitForCertStatus(
  KeyM_CertificateIdType certId,
  KeyM_CertificateStatusType expectedStatus);

#if (CRYPTO_30_KEYM_SERVICE_CERTIFICATE_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_KeyM_ServiceCertificate()
 *********************************************************************************************************************/
/*! \brief          Execute KeyM_ServiceCertificate based on CryptoJob parameters.
 *  \details        This function will call the KeyM_ServiceCertificate and obtain the parameter from a crypto job.
 *  \param[in,out]  job               Pointer to the configuration of the job. Contains structures with job and
 *                                    primitive relevant information but also pointer to result buffers.
 *  \return         E_OK                             Service data operation successfully accepted.
 *                  E_NOT_OK                         Operation not accepted due to an internal error.
 *                  KEYM_E_PARAMETER_MISMATCH        Parameter do not match with expected value.
 *                  KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_ServiceCertificate(
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job);
#endif /* CRYPTO_30_KEYM_SERVICE_CERTIFICATE_ENABLED */

/**********************************************************************************************************************
 *  Crypto_30_KeyM_CertElementGet()
 *********************************************************************************************************************/
/*! \brief          Execute KeyM_CertElementGet based on CryptoJob parameters.
 *  \details        This function will call the KeyM_CertElementGet and obtain the parameter from a crypto job.
 *  \param[in,out]  job               Pointer to the configuration of the job. Contains structures with job and
 *                                    primitive relevant information but also pointer to result buffers.
 *  \return         E_OK                                 Element found and data provided in the buffer.
 *                  E_NOT_OK                             Element data not found.
 *                  KEYM_E_PARAMETER_MISMATCH            Certificate ID or certificate element ID invalid.
 *                  KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                  KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                  KEYM_E_KEY_CERT_INVALID              The certificate is not valid or has not yet been verified.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_CertElementGet(
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_CertElementGetFirst()
 *********************************************************************************************************************/
/*! \brief          Execute KeyM_CertElementGetFirst based on CryptoJob parameters.
 *  \details        This function will call the KeyM_CertElementGetFirst and obtain the parameter from a crypto job.
 *  \param[in,out]  job               Pointer to the configuration of the job. Contains structures with job and
 *                                    primitive relevant information but also pointer to result buffers.
 *  \return         E_OK                                 Element found and data provided in the buffer.
 *                                                       The certElementIterator has been initialized accordingly.
 *                  E_NOT_OK                             Element data not found.
 *                  KEYM_E_PARAMETER_MISMATCH            Certificate ID or certificate element ID invalid.
 *                  KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                  KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                  KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_CertElementGetFirst(
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_CertElementGetNext()
 *********************************************************************************************************************/
/*! \brief          Execute KeyM_CertElementGetNext based on CryptoJob parameters.
 *  \details        This function will call the KeyM_CertElementGetNext and obtain the parameter from a crypto job.
 *  \param[in,out]  job               Pointer to the configuration of the job. Contains structures with job and
 *                                    primitive relevant information but also pointer to result buffers.
 *  \return         E_OK                                 Element found and data provided in the buffer.
 *                                                       The certElementIterator has been initialized accordingly.
 *                  E_NOT_OK                             Element data not found.
 *                  KEYM_E_PARAMETER_MISMATCH            Certificate ID or certificate element ID invalid.
 *                  KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                  KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                  KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_CertElementGetNext(
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job);

#if (CRYPTO_30_KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_KeyM_GetCsrInfo()
 *********************************************************************************************************************/
/*! \brief          De-serializes multiple elements of KeyM_CSRInfoType and the total number of available elements.
 *  \details        This function de-serializes from a given input pointer to an array of CSR info.
 *  \param[in]      inputPtr          Pointer to the serialized csrInfo array.
 *  \param[in]      inputLength       Length of input pointer.
 *  \param[in,out]  csrInfoPtr        Pointer to the resulting CsrInfo.
 *  \param[in,out]  numOfReqObjPtr    Pointer to the total number of available request objects.
 *  \return         E_OK              Deserialization succeed.
 *                  E_NOT_OK          Deserialization failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_GetCsrInfo(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) inputPtr,
  uint32 inputLength,
  P2VAR(KeyM_CSRInfoType, AUTOMATIC, AUTOMATIC) csrInfoPtr,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) numOfReqObjPtr);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_InitCSR()
 *********************************************************************************************************************/
/*! \brief          Execute KeyM_InitCSR based on CryptoJob parameters.
 *  \details        This function will call the KeyM_InitCSR and obtain the parameter from a crypto job.
 *  \param[in,out]  job               Pointer to the configuration of the job. Contains structures with job and
 *                                    primitive relevant information but also pointer to result buffers.
 *  \return         E_OK                                 Operation successful.
 *                  E_NOT_OK                             Internal error.
 *                  KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_InitCSR(
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job);
#endif

/**********************************************************************************************************************
 *  Crypto_30_KeyM_VerifyCertificate()
 *********************************************************************************************************************/
/*! \brief          Execute KeyM_VerifyCertificate
 *  \details        This function will call the KeyM_VerifyCertificate and wait until operation is finished.
 *  \param[in]      certId            Holds the identifier of the certificate.
 *  \return         E_OK                                 Certificate verification request accepted. Operation will be
 *                                                       performed in the background and response is given through a callback.
 *                  E_NOT_OK                             Operation not accepted due to an internal error.
 *                  KEYM_E_BUSY                          Validation cannot be performed yet. KeyM is
 *                                                       currently busy with other jobs.
 *                  KEYM_E_PARAMETER_MISMATCH            Certificate ID invalid.
 *                  KEYM_E_KEY_CERT_EMPTY                One of the certificate slots are empty.
 *                  KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   An upper certificate is not valid.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_VerifyCertificate(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_VerifyCertificates()
 *********************************************************************************************************************/
/*! \brief          Execute KeyM_VerifyCertificates
 *  \details        This function will call the KeyM_VerifyCertificates and wait until operation is finished.
 *  \param[in]      certId            Holds the identifier of the lower certificate in the chain.
 *  \param[in]      certUpperId       Holds the identifier of the upper certificate in the chain.
 *  \return         E_OK                                 Certificate verification request accepted. Operation will be
 *                                                       performed in the background and response is given through a callback.
 *                  E_NOT_OK                             Operation not accepted due to an internal error.
 *                  KEYM_E_BUSY                          Validation cannot be performed yet. KeyM is
 *                                                       currently busy with other jobs.
 *                  KEYM_E_PARAMETER_MISMATCH            Certificate ID invalid.
 *                  KEYM_E_KEY_CERT_EMPTY                One of the certificate slots are empty.
 *                  KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   An upper certificate is not valid.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_VerifyCertificates(
  KeyM_CertificateIdType certId,
  KeyM_CertificateIdType certUpperId);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_SetCertificate()
 *********************************************************************************************************************/
/*! \brief          Execute KeyM_SetCertificate
 *  \details        This function will call the KeyM_SetCertificate and wait until operation is finished.
 *  \param[in]      certId               Holds the identifier of the certificate.
 *  \param[in]      CertificateDataPtr   Pointer to a structure that provides the certificate data.
 *  \return         E_OK                             Certificate accepted.
 *                  E_NOT_OK                         Certificate could not be set.
 *                  KEYM_E_PARAMETER_MISMATCH        Parameter do not match with expected value.
 *                  KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_SetCertificate(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CertDataType, AUTOMATIC, AUTOMATIC) CertificateDataPtr);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  Crypto_30_KeyM_GetMappedReturnValue()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_KEYM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_GetMappedReturnValue(
  Std_ReturnType rVal)
{
  Std_ReturnType retVal;

  switch (rVal)
  {
    case E_OK:
      retVal = E_OK;
      break;
    case KEYM_E_BUSY:
      retVal = CRYPTO_E_BUSY;
      break;
    case KEYM_E_PENDING:
      retVal = CRYPTO_E_QUEUE_FULL;
      break;
    case KEYM_E_KEY_CERT_SIZE_MISMATCH:
      retVal = CRYPTO_E_KEY_SIZE_MISMATCH;
      break;
    case KEYM_E_PARAMETER_MISMATCH:
      retVal = CRYPTO_E_KEY_NOT_AVAILABLE;
      break;
    case KEYM_E_KEY_CERT_INVALID:
      retVal = CRYPTO_E_KEY_NOT_VALID;
      break;
    case KEYM_E_KEY_CERT_READ_FAIL:
      retVal = CRYPTO_E_KEY_READ_FAIL;
      break;
    case KEYM_E_KEY_CERT_EMPTY:
      retVal = CRYPTO_E_KEY_EMPTY;
      break;
    case KEYM_E_CERT_INVALID_CHAIN_OF_TRUST:
      retVal = CRYPTO_E_KEY_WRITE_FAIL;
      break;
    default:
      retVal = E_NOT_OK;
      break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_GetCertElementIterator()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_KEYM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_GetCertElementIterator(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) inputPtr,
  uint32 inputLength,
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, AUTOMATIC) iteratorPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* Check input pointer and length */
  if ((inputLength == CRYPTO_30_KEYM_SERIALIZED_CERTELEMENTITERATOR_SIZE)
    && (inputPtr != NULL_PTR))
  {
    /* Deserialize the KeyM_CertElementIteratorType */
    iteratorPtr->offset = Crypto_30_KeyM_BigEndByteArrayToUint16(inputPtr, 0u);
    iteratorPtr->elementLength = Crypto_30_KeyM_BigEndByteArrayToUint16(inputPtr, 2u);
    iteratorPtr->rootElementIdx = Crypto_30_KeyM_BigEndByteArrayToUint16(inputPtr, 4u);
    iteratorPtr->iterationStatus = inputPtr[6];
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_SetCertElementIterator()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_KEYM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_SetCertElementIterator(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) resultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) resultLengthPtr,
  P2CONST(KeyM_CertElementIteratorType, AUTOMATIC, AUTOMATIC) iteratorPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* Check result pointer and length */
  if ((resultLengthPtr != NULL_PTR)
    && (resultPtr != NULL_PTR))
  {
    /* Serialize the KeyM_CertElementIteratorType */
    resultPtr[0] = Crypto_30_KeyM_Uint16ToBigEndHiByte(iteratorPtr->offset);
    resultPtr[1] = Crypto_30_KeyM_Uint16ToBigEndLoByte(iteratorPtr->offset);
    resultPtr[2] = Crypto_30_KeyM_Uint16ToBigEndHiByte(iteratorPtr->elementLength);
    resultPtr[3] = Crypto_30_KeyM_Uint16ToBigEndLoByte(iteratorPtr->elementLength);
    resultPtr[4] = Crypto_30_KeyM_Uint16ToBigEndHiByte(iteratorPtr->rootElementIdx);
    resultPtr[5] = Crypto_30_KeyM_Uint16ToBigEndLoByte(iteratorPtr->rootElementIdx);
    resultPtr[6] = iteratorPtr->iterationStatus;
    *resultLengthPtr = CRYPTO_30_KEYM_SERIALIZED_CERTELEMENTITERATOR_SIZE;
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_WaitForKeyM()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_KEYM_LOCAL FUNC(Crypto_VerifyResultType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_WaitForKeyM(
  KeyM_CertificateIdType certId,
  KeyM_CertificateStatusType expectedStatus)
{
  Crypto_VerifyResultType retVal = CRYPTO_E_VER_NOT_OK;
  KeyM_CertificateStatusType status = KEYM_CERTIFICATE_NOT_AVAILABLE;

  do
  {
    /* Call the cyclic main function until KeyM Cert submodule is idle */
    KeyM_MainFunction();
  } while (KeyM_Cert_IsBusy());

  /* Check status */
  (void) KeyM_CertGetStatus(certId, &status); /* According AUTOSAR this KeyM API always returns E_OK */
  if (status == expectedStatus)
  {
    retVal = CRYPTO_E_VER_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_WaitForCertStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_KEYM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_WaitForCertStatus(
  KeyM_CertificateIdType certId,
  KeyM_CertificateStatusType expectedStatus)
{
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateStatusType status = KEYM_CERTIFICATE_INVALID;

  do
  {
    /* Call the cyclic main function until desired or error status has been reached */
    KeyM_MainFunction();
    (void)KeyM_CertGetStatus(certId, &status); /* According AUTOSAR this KeyM API always returns E_OK */
  } while ((status != expectedStatus) && (!Crypto_30_KeyM_IsErrorState(status)));

  /* Check status */
  if (status == expectedStatus)
  {
    retVal = E_OK;
  }

  return retVal;
}

#if (CRYPTO_30_KEYM_SERVICE_CERTIFICATE_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_KeyM_ServiceCertificate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_ServiceCertificate(
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIdType certId;

  /* #10 Check input and output parameters */
  if ( job->jobPrimitiveInputOutput.inputLength != sizeof(KeyM_ServiceCertificateType))
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else if (job->jobPrimitiveInputOutput.inputPtr == NULL_PTR)
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else if (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR)
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  /* Check if CertName and corresponding certId are available */
  else if (FALSE == KeyM_Cert_SearchCert(job->jobPrimitiveInputOutput.secondaryInputPtr,
    job->jobPrimitiveInputOutput.secondaryInputLength,
    &certId))
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else
  {
    KeyM_ServiceCertificateType service = *job->jobPrimitiveInputOutput.inputPtr;

    /* #20 Forward call to KeyM_ServiceCertificate to process the requested service */
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
      /* #30 Wait that KeyM has finished the operation */
      *job->jobPrimitiveInputOutput.verifyPtr =
        Crypto_30_KeyM_WaitForKeyM(certId, KEYM_CERTIFICATE_VALID);
    }
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* CRYPTO_30_KEYM_SERVICE_CERTIFICATE_ENABLED */

/**********************************************************************************************************************
 *  Crypto_30_KeyM_CertElementGet()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_CertElementGet(
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType) job->cryptoKeyId;

  /* #10 Check input and output parameters */
  if (job->jobPrimitiveInputOutput.inputLength != CRYPTO_30_KEYM_SERIALIZED_CERTELEMENTID_SIZE)
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else if (job->jobPrimitiveInputOutput.inputPtr == NULL_PTR)
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else
  {
    KeyM_CertElementIdType certElementId =
      (KeyM_CertElementIdType) Crypto_30_KeyM_BigEndByteArrayToUint16(job->jobPrimitiveInputOutput.inputPtr, 0u);

    /* Call KeyM_CertElementGet */
    retVal = KeyM_CertElementGet(
      certId,                                                               /* uint8 CertId */
      certElementId,                                                        /* uint16 CertElementId */
      job->jobPrimitiveInputOutput.outputPtr,                               /* uint8* CertElementData */
      job->jobPrimitiveInputOutput.outputLengthPtr);                        /* uint32* CertElementDataLength  */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_CertElementGetFirst()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_CertElementGetFirst(
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertElementIteratorType tmpCertElementIterator;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType) job->cryptoKeyId;

  /* #10 Check input and output parameters */
  if (job->jobPrimitiveInputOutput.inputLength != CRYPTO_30_KEYM_SERIALIZED_CERTELEMENTID_SIZE)
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else if (job->jobPrimitiveInputOutput.inputPtr == NULL_PTR)
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  /* Deserialize secondaryInputPtr to KeyM_CertElementIteratorType */
  else if (Crypto_30_KeyM_GetCertElementIterator(job->jobPrimitiveInputOutput.secondaryInputPtr,
      job->jobPrimitiveInputOutput.secondaryInputLength,
      &tmpCertElementIterator) != E_OK)
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else
  {
    KeyM_CertElementIdType certElementId =
      (KeyM_CertElementIdType)Crypto_30_KeyM_BigEndByteArrayToUint16(job->jobPrimitiveInputOutput.inputPtr, 0u);

    /* Make iterator compatible to KeyM changes after 1.03.00 (ESCAN00107095) */
    tmpCertElementIterator.certId = certId;

    /* #20 Forward call to KeyM_CertElementGetFirst to receive the first part of date from a certificate element */
    retVal = KeyM_CertElementGetFirst(
      certId,                                                                   /* uint8 CertId */
      certElementId,                                                            /* uint16 CertElementId */
      &tmpCertElementIterator,                                                  /* KeyM_CertElementIteratorType* CertElementIterator */
      job->jobPrimitiveInputOutput.outputPtr,                                   /* uint8* CertElementData */
      job->jobPrimitiveInputOutput.outputLengthPtr);                            /* uint32* CertElementDataLength  */

    if (retVal == E_OK)
    {
      /* Serialize KeyM_CertElementIteratorType into secondaryOutputPtr */
      retVal = Crypto_30_KeyM_SetCertElementIterator(job->jobPrimitiveInputOutput.secondaryOutputPtr,
        job->jobPrimitiveInputOutput.secondaryOutputLengthPtr,
        &tmpCertElementIterator);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_CertElementGetNext()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_CertElementGetNext(
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  KeyM_CertElementIteratorType tmpCertElementIterator;

  /* Deserialize secondaryInputPtr to KeyM_CertElementIteratorType */
  if (Crypto_30_KeyM_GetCertElementIterator(job->jobPrimitiveInputOutput.secondaryInputPtr,
      job->jobPrimitiveInputOutput.secondaryInputLength,
      &tmpCertElementIterator) == E_OK)
  {
    /* Make iterator compatible to KeyM changes after 1.03.00 (ESCAN00107095) */
    tmpCertElementIterator.certId = (KeyM_CertificateIdType) job->cryptoKeyId;

    /* #20 Forward call to KeyM_CertElementGetNext to receive the first part of date from a certificate element */
    retVal = KeyM_CertElementGetNext(
      &tmpCertElementIterator,                                                   /* KeyM_CertElementIteratorType* CertElementIterator */
      job->jobPrimitiveInputOutput.outputPtr,                                    /* uint8* CertElementData */
      job->jobPrimitiveInputOutput.outputLengthPtr);                             /* uint32* CertElementDataLength  */

    if (retVal == E_OK)
    {
      /* Serialize KeyM_CertElementIteratorType into secondaryOutputPtr */
      retVal = Crypto_30_KeyM_SetCertElementIterator(job->jobPrimitiveInputOutput.secondaryOutputPtr,
        job->jobPrimitiveInputOutput.secondaryOutputLengthPtr,
        &tmpCertElementIterator);
    }
  }

  return retVal;
}

#if (CRYPTO_30_KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_KeyM_GetCsrInfo()
 *********************************************************************************************************************/
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
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_GetCsrInfo(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) inputPtr,
  uint32 inputLength,
  P2VAR(KeyM_CSRInfoType, AUTOMATIC, AUTOMATIC) csrInfoPtr,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) numOfReqObjPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8_least csrInfoIdx;
  uint32 offset = 1u;

  /* #10 Check input pointer and length */
  if ((inputPtr != NULL_PTR) && (inputLength > 4u))
  {
    *numOfReqObjPtr = (uint8) inputPtr[0];

    /* #15 De-serializes requested objects and check against maximum available entries. */
    if (*numOfReqObjPtr <= CRYPTO_30_KEYM_MAX_ENTRIES_CSR_INFO)
    {
      retVal = E_OK;
      /* Fill the array of csrInfo */
      for (csrInfoIdx = 0; csrInfoIdx < *numOfReqObjPtr; csrInfoIdx++)
      {
        /* Check boundaries of input */
        if ((offset + 4u) <= inputLength)
        {
          csrInfoPtr[csrInfoIdx].elementType = inputPtr[offset];
          csrInfoPtr[csrInfoIdx].dataLength = Crypto_30_KeyM_BigEndByteArrayToUint16(inputPtr, (offset + 1u));
          csrInfoPtr[csrInfoIdx].dataPtr = &inputPtr[offset + 3u];

          offset += ((uint32) csrInfoPtr[csrInfoIdx].dataLength + 3u);
        }
        else
        {
          /* Inconsistency between inputLength and offset */
          retVal = E_NOT_OK;
          break;
        }
      }

      /* Inconsistency between inputLength and offset.*/
      if(offset != inputLength)
      {

        retVal = E_NOT_OK;
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_InitCSR()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_InitCSR(
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 numOfReqObj = 0u;
  KeyM_CSRInfoType csrInfo[CRYPTO_30_KEYM_MAX_ENTRIES_CSR_INFO];

  /* #10 Check input parameters */
  if (job->jobPrimitiveInputOutput.inputLength == 0u)
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else if (job->jobPrimitiveInputOutput.inputPtr == NULL_PTR)
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else if (Crypto_30_KeyM_GetCsrInfo(job->jobPrimitiveInputOutput.secondaryInputPtr,
    job->jobPrimitiveInputOutput.secondaryInputLength,
    csrInfo, &numOfReqObj) != E_OK)
  {
    /* Nothing to be done, retVal already set to E_NOT_OK */
  }
  else
  {
    /* #20 Forward received data to KeyM_InitCSR to initialize an certificate signing request (CSR) */
    retVal = KeyM_InitCSR(
      job->jobPrimitiveInputOutput.inputPtr,                                    /* uint8* CertNamePtr */
      job->jobPrimitiveInputOutput.inputLength,                                 /* uint32 CertNameLength */
      csrInfo,                                                                  /* KeyM_CSRInfoType* CsrInfo */
      numOfReqObj,                                                              /* uint8 numOfReqObjects */
      job->jobPrimitiveInputOutput.outputPtr,                                   /* uint8* ResponseData */
      job->jobPrimitiveInputOutput.outputLengthPtr);                            /* uint32* ResponseDataLength */
  }
  return retVal;
}
#endif

/**********************************************************************************************************************
 *  Crypto_30_KeyM_VerifyCertificate()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_KEYM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_VerifyCertificate(
  KeyM_CertificateIdType certId)
{
  Std_ReturnType retVal;

  /* #10 Forward call to KeyM_VerifyCertificate to verify the requested certificate */
  retVal = KeyM_VerifyCertificate(certId);
  if (retVal == E_OK)
  {
    /* #20 Wait that KeyM has finished the operation */
    (void) Crypto_30_KeyM_WaitForKeyM(certId, KEYM_CERTIFICATE_VALID);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_VerifyCertificates()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_VerifyCertificates(
  KeyM_CertificateIdType certId,
  KeyM_CertificateIdType certUpperId)
{
  Std_ReturnType retVal;

  /* #10 Forward call to KeyM_VerifyCertificates to verify two certificates against each other */
  retVal = KeyM_VerifyCertificates(certId, certUpperId);
  if (retVal == E_OK)
  {
    /* #20 Wait that KeyM has finished the operation */
    (void) Crypto_30_KeyM_WaitForKeyM(certId, KEYM_CERTIFICATE_VALID);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_SetCertificate()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_KEYM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_SetCertificate(
  KeyM_CertificateIdType certId,
  P2CONST(KeyM_CertDataType, AUTOMATIC, AUTOMATIC) CertificateDataPtr)
{
  Std_ReturnType retVal;

  /* #10 Forward call to KeyM_SetCertificate to store the provided certificate temporarily */
  retVal = KeyM_SetCertificate(certId, CertificateDataPtr);
  if (retVal == E_OK)
  {
    /* #20 Wait that KeyM has finished the operation */
    if (CertificateDataPtr->certDataLength == 0u)
    {
      /* Reset certificate was triggered [SWS_KeyM_00141] */
      (void) Crypto_30_KeyM_WaitForCertStatus(certId, KEYM_CERTIFICATE_NOT_AVAILABLE);
    }
    else
    {
      (void)Crypto_30_KeyM_WaitForCertStatus(certId, KEYM_CERTIFICATE_PARSED_NOT_VALIDATED);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Crypto_30_KeyM_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_Init(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Do nothing */
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Do nothing */
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_ProcessJob()
 *********************************************************************************************************************/
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
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_ProcessJob(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Ensure that operation mode is singlecall */
  if (job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_SINGLECALL)
  {
    if (job->jobPrimitiveInfo->primitiveInfo->service == CRYPTO_AEADDECRYPT)
    {
      /* -------------------------------------- KeyM_ServiceCertificate -------------------------------------- */
      if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_CUSTOM_VHSM_KEYM)
      {
#if (CRYPTO_30_KEYM_SERVICE_CERTIFICATE_ENABLED == STD_ON)
        retVal = Crypto_30_KeyM_ServiceCertificate(job);
#endif
      }
      /* -------------------------------------- KeyM_DispatchRemoteJob --------------------------------------- */
      else
      {
        /* Use Remote Handling of KeyM */
        retVal = KeyM_DispatchRemoteJob(job);
      }
    }
    else if (job->jobPrimitiveInfo->primitiveInfo->service == CRYPTO_AEADENCRYPT)
    {
      if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_CUSTOM_VHSM_KEYM)
      {
        /* Check which KeyM API must be called */
        switch (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
        {
          /* -------------------------------------- KeyM_CertElementGet -------------------------------------- */
          case CRYPTO_ALGOMODE_CUSTOM_CERTELEMENT_GET:
          {
            retVal = Crypto_30_KeyM_CertElementGet(job);
            break;
          }
          /* -------------------------------------- KeyM_CertElementGetFirst -------------------------------------- */
          case CRYPTO_ALGOMODE_CUSTOM_CERTELEMENT_GETFIRST:
          {
            retVal = Crypto_30_KeyM_CertElementGetFirst(job);
            break;
          }
          /* -------------------------------------- KeyM_CertElementGetNext --------------------------------------- */
          case CRYPTO_ALGOMODE_CUSTOM_CERTELEMENT_GETNEXT:
          {
            retVal = Crypto_30_KeyM_CertElementGetNext(job);
            break;
          }
          case CRYPTO_ALGOMODE_CUSTOM_INIT_CSR:
          {
#if (CRYPTO_30_KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
            retVal = Crypto_30_KeyM_InitCSR(job);
#endif
            break;
          }
          default:
            /* Algorithm Mode not supported */
            break;
        }
      }
    }
    else
    {
      /* Algorithm not supported */
    }
  }

  CRYPTO_30_KEYM_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  return Crypto_30_KeyM_GetMappedReturnValue(retVal);
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Crypto_30_KeyM_CancelJob()
 *********************************************************************************************************************/
 /*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_CancelJob(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return always with an error because crypto KeyM jobs can not be canceled */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyElementSet()
 *********************************************************************************************************************/
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
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) keyPtr,
  uint32 keyLength)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  KeyM_CertDataType cert;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType) cryptoKeyId;

  /* Key pointer check */
  if ((keyPtr == NULL_PTR))
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* #10 Operations are identified by KeyElement ID */
    switch (keyElementId)
    {
        /* -------------------------------------- KeyM_SetCertificate -------------------------------------- */
      case CRYPTO_KE_CUSTOM_VHSM_KEYM_CERTIFICATE:
      {
        cert.certData = (KeyM_CertDataPointerType)keyPtr; /* PRQA S 0311 */ /* MD_Crypto_30_KeyM_311 */
        cert.certDataLength = keyLength;

        /* Set certificate */
        retVal = Crypto_30_KeyM_SetCertificate(certId, &cert);
        break;
      }
        /* -------------------------------------- KeyM_VerifyCertificate -------------------------------------- */
      case CRYPTO_KE_CUSTOM_VHSM_KEYM_VERIFY_CERT:
      {
        retVal = Crypto_30_KeyM_VerifyCertificate(certId);
        break;
      }
        /* -------------------------------------- KeyM_VerifyCertificates -------------------------------------- */
      case CRYPTO_KE_CUSTOM_VHSM_KEYM_VERIFY_CERTS:
      {
        /* Input pointer and length check */
        if ((keyLength != CRYPTO_30_KEYM_SERIALIZED_CERTIFICATEID_SIZE))
        {
          retVal = E_NOT_OK;
        }
        else
        {
          /* Verify certificates */
          retVal = Crypto_30_KeyM_VerifyCertificates(
            certId,
            (KeyM_CertificateIdType)Crypto_30_KeyM_BigEndByteArrayToUint16(keyPtr, 0u));
        }
        break;
      }
      default:
      {
        /* Use Remote Handling of KeyM */
        retVal = KeyM_DispatchRemoteKeyElementSet(cryptoKeyId, keyElementId, keyPtr, keyLength);
        break;
      }
    }

  }

  return Crypto_30_KeyM_GetMappedReturnValue(retVal);
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyValidSet()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyValidSet(
  uint32 cryptoKeyId)
{
  Std_ReturnType retVal;

  retVal = Crypto_30_KeyM_VerifyCertificate((KeyM_CertificateIdType)cryptoKeyId);

  return Crypto_30_KeyM_GetMappedReturnValue(retVal);
}
/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyElementGet()
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
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) resultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) resultLengthPtr)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  KeyM_CertDataType cert;
  KeyM_CertificateStatusType status = KEYM_CERTIFICATE_NOT_AVAILABLE;
  KeyM_CertificateIdType certId = (KeyM_CertificateIdType) cryptoKeyId;

  /* Result pointer and length check */
  if ( (*resultLengthPtr == 0u)
    || (resultPtr == NULL_PTR))
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* #10 Operations are identified by KeyElement ID */
    switch (keyElementId)
    {
      case CRYPTO_KE_CUSTOM_VHSM_KEYM_CERTIFICATE:
      {
        cert.certDataLength = *resultLengthPtr;
        cert.certData = resultPtr;

        retVal = KeyM_GetCertificate(certId, &cert);

        *resultLengthPtr = cert.certDataLength;
        break;
      }
      case CRYPTO_KE_CUSTOM_VHSM_KEYM_CERT_GETSTATUS:
      {
        retVal = KeyM_CertGetStatus(certId, &status);

        *resultLengthPtr = sizeof(status);
        *resultPtr = status;
        break;
      }
      default:
      {
        /* Use Remote Handling of KeyM */
        retVal = KeyM_DispatchRemoteKeyElementGet(cryptoKeyId, keyElementId, resultPtr, resultLengthPtr);
        break;
      }
    }
  }

  return Crypto_30_KeyM_GetMappedReturnValue(retVal);
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) VersionInfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = E_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* #5 Check plausibility of parameters. */
  if (VersionInfo == NULL_PTR)
  {
    /* Nothing to be done */
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Write versionInfo pointer with modules versions. */
    VersionInfo->vendorID = (uint16)CRYPTO_30_KEYM_VENDOR_ID; /* SBSW_CRYPTO_30_KEYM_GETVERSIONINFO */
    VersionInfo->moduleID = (uint8)CRYPTO_30_KEYM_MODULE_ID; /* SBSW_CRYPTO_30_KEYM_GETVERSIONINFO */
    VersionInfo->sw_major_version = (uint8)CRYPTO_30_KEYM_SW_MAJOR_VERSION; /* SBSW_CRYPTO_30_KEYM_GETVERSIONINFO */
    VersionInfo->sw_minor_version = (uint8)CRYPTO_30_KEYM_SW_MINOR_VERSION; /* SBSW_CRYPTO_30_KEYM_GETVERSIONINFO */
    VersionInfo->sw_patch_version = (uint8)CRYPTO_30_KEYM_SW_PATCH_VERSION; /* SBSW_CRYPTO_30_KEYM_GETVERSIONINFO */
  }

  /* ----- Development Error Report --------------------------------------- */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyCopy()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyCopy(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId)
{
  /* ----- Implementation ------------------------------------------------- */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(targetCryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  return E_NOT_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyElementCopy()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyElementCopy(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  uint32 targetCryptoKeyId,
  uint32 targetKeyElementId)
{
  /* ----- Implementation ------------------------------------------------- */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(targetCryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(keyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(targetKeyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  return E_NOT_OK;
}
/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyElementCopyPartial()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyElementCopyPartial(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  uint32 keyElementSourceOffset,
  uint32 keyElementTargetOffset,
  uint32 keyElementCopyLength,
  uint32 targetCryptoKeyId,
  uint32 targetKeyElementId)
{
  /* ----- Implementation ------------------------------------------------- */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(keyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(keyElementSourceOffset); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(keyElementTargetOffset); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(keyElementCopyLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(targetCryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(targetKeyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  return E_NOT_OK;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyElementIdsGet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyElementIdsGet(
  uint32 cryptoKeyId,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) keyElementIdsPtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) keyElementIdsLengthPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  /* ----- Implementation ------------------------------------------------- */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(keyElementIdsPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(keyElementIdsLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  return E_NOT_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_RandomSeed()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_RandomSeed(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) entropyPtr,
  uint32 entropyLength)
{
  /* ----- Implementation ------------------------------------------------- */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(entropyPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(entropyLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  return E_NOT_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyGenerate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyGenerate(
  uint32 cryptoKeyId)
{
  /* ----- Implementation ------------------------------------------------- */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  return E_NOT_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyDerive()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyDerive(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId)
{
  /* ----- Implementation ------------------------------------------------- */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(targetCryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  return E_NOT_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyExchangeCalcPubVal()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyExchangeCalcPubVal(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) publicValuePtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) publicValueLengthPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  /* ----- Implementation ------------------------------------------------- */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(publicValuePtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(publicValueLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  return E_NOT_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyExchangeCalcSecret()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyExchangeCalcSecret(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) partnerPublicValuePtr,
  uint32 partnerPublicValueLength)
{
  /* ----- Implementation ------------------------------------------------- */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(partnerPublicValuePtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(partnerPublicValueLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  return E_NOT_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_CertificateParse()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_CertificateParse(
  uint32 cryptoKeyId)
{
  /* ----- Implementation ------------------------------------------------- */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  return E_NOT_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_KeyM_CertificateVerify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_CertificateVerify(
  uint32 cryptoKeyId,
  uint32 verifyCryptoKeyId,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) verifyPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  /* ----- Implementation ------------------------------------------------- */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(verifyCryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
  CRYPTO_30_KEYM_DUMMY_STATEMENT(verifyPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */

  return E_NOT_OK;
}

#define CRYPTO_30_KEYM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/
/* Justification for module-specific MISRA deviations:
  MD_Crypto_30_KeyM_311:
    Reason:       KeyM declares a pointer to certificate not as a const pointer.
    Risk:         Possibility to write into an as initial const declared pointer.
    Prevention:   The MSR module KeyM ensures that no write operation is done for this pointer. See KeyM_SetCertificate doxygen
 */

/* SBSW_JUSTIFICATION_BEGIN
SBSW_JUSTIFICATION_END */

/* START_COVERAGE_JUSTIFICATION
END_COVERAGE_JUSTIFICATION
 */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_KeyM.c
 *********************************************************************************************************************/

