/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*      \file  Crypto_30_vHsm_KeyManagement.h
 *      \brief  MICROSAR vHsm Crypto Driver (Crypto)
 *
 *      \details  Internal header file for service key management function prototypes
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#ifndef CRYPTO_30_VHSM_KEYMANAGEMENT_H
# define CRYPTO_30_VHSM_KEYMANAGEMENT_H
# include "Csm_Types.h"

# define CRYPTO_30_VHSM_START_SEC_CODE
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyCopy()
 *********************************************************************************************************************/
/*! \brief         Copy the key
 *  \details       Copies a key with all its elements to another key in the same crypto driver.
 *  \param[in]     cryptoKeyId                  Holds the identifier of the key whose key element shall be the source
 *                                              element.
 *  \param[in]     targetCryptoKeyId            Holds the identifier of the key whose key element shall be the destination
 *                                              element.
 *  \return        E_OK                         Request successful.
 *                 E_NOT_OK                     Request failed.
 *                 CRYPTO_E_BUSY                Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_KEY_READ_FAIL       Request failed, read access was denied.
 *                 CRYPTO_E_KEY_WRITE_FAIL      Request failed, write access was denied.
 *                 CRYPTO_E_KEY_NOT_AVAILABLE   Request failed, the key is not available.
 *                 CRYPTO_E_KEY_SIZE_MISMATCH   Request failed, the key element sizes are not compatible.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyCopy(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyElementCopy()
 *********************************************************************************************************************/
/*! \brief         Copy key element
 *  \details       Copies a key element to another key element in the same crypto driver.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key element shall be the source
 *                                         element.
 *  \param[in]     keyElementId            Holds the identifier of the key element which shall be the source for the
 *                                         copy operation.
 *  \param[in]     targetCryptoKeyId       Holds the identifier of the key whose key element shall be the destination
 *                                         element.
 *  \param[in]     targetKeyElementId      Holds the identifier of the key element which shall be the destination for
 *                                         the copy operation.
 *  \return        E_OK                         Request successful.
 *                 E_NOT_OK                     Request failed.
 *                 CRYPTO_E_BUSY                Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_KEY_READ_FAIL       Request failed, read access was denied.
 *                 CRYPTO_E_KEY_WRITE_FAIL      Request failed, write access was denied.
 *                 CRYPTO_E_KEY_EXTRACT_DENIED  Request failed, not allowed to extract key material.
 *                 CRYPTO_E_KEY_NOT_AVAILABLE   Request failed, the key is not available.
 *                 CRYPTO_E_KEY_SIZE_MISMATCH   Request failed, the key element sizes are not compatible.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyElementCopy(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  uint32 targetCryptoKeyId,
  uint32 targetKeyElementId);

/**********************************************************************************************************************
 * Crypto_30_vHsm_KeyElementCopyPartial()
 **********************************************************************************************************************/
/*! \brief         Copy key element partial
 *  \details       Copies a key element to another key element in the same crypto driver. The keyElementSourceOffset
 *                 and keyElementCopyLength allows to copy just a part of the source key element into the destination.
 *                 The offset of the target key is also specified with this function.
 *                 The target key element needs to have partial access.
 *                 The key element can only be copied, if the destination key element write access right is less than
 *                 WA_INTERNAL_COPY.
 *                 Additional the read access right of the source must be less than RA_INTERNAL_COPY and the destination
 *                 read access right must be higher or equal than the source read access right.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key element shall be the source
 *                                         element.
 *  \param[in]     keyElementId            Holds the identifier of the key element which shall be the source for the
 *                                         copy operation.
 *  \param[in]     keyElementSourceOffset  Holds the offset of the of the source key element indicating the start index
 *                                         of the copy operation.
 *  \param[in]     keyElementTargetOffset  Holds the offset of the of the target key element indicating the start index
 *                                         of the copy operation.
 *  \param[in]     keyElementCopyLength    Holds the number of bytes that shall be copied.
 *  \param[in]     targetCryptoKeyId       Holds the identifier of the key whose key element shall be the
 *                                         destination element.
 *  \param[in]     targetKeyElementId      Holds the identifier of the key element which shall be the destination for
 *                                         the copy operation.
 *  \return        E_OK                         Request successful.
 *                 E_NOT_OK                     Request failed.
 *                 CRYPTO_E_BUSY                Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_KEY_READ_FAIL       Request failed, read access was denied.
 *                 CRYPTO_E_KEY_WRITE_FAIL      Request failed, write access was denied.
 *                 CRYPTO_E_KEY_NOT_AVAILABLE   Request failed, the key is not available.
 *                 CRYPTO_E_KEY_SIZE_MISMATCH   Request failed, the key element sizes are not compatible.
 *                 CRYPTO_E_KEY_EMPTY           Request failed, uninitialized source key element.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, for different crypto keys
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyElementCopyPartial(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  uint32 keyElementSourceOffset,
  uint32 keyElementTargetOffset,
  uint32 keyElementCopyLength,
  uint32 targetCryptoKeyId,
  uint32 targetKeyElementId);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyElementIdsGet()
 *********************************************************************************************************************/
/*! \brief         Used to retrieve information which key elements are available in a given key.
 *  \details       -
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose available element ids shall be exported.
 *  \param[out]    keyElementIdsPtr        Contains the pointer to the array where the ids of the key
 *                                         elements shall be stored.
 *  \param[in,out] keyElementIdsLengthPtr  Holds a pointer to the memory location in which the number of key element
 *                                         in the given key is stored. On calling this function, this parameter
 *                                         shall contain the size of the buffer provided by keyElementIdsPtr. When the
 *                                         request has finished, the actual number of key elements is stored.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyElementIdsGet(
  uint32 cryptoKeyId,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) keyElementIdsPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) keyElementIdsLengthPtr);

/* [SWS_Crypto_91004] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyElementSet()
 *********************************************************************************************************************/
/*! \brief         Sets a key element
 *  \details       Sets the given key element bytes to the key identified by cryptoKeyId. .
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key element shall be set.
 *  \param[in]     keyElementId            Holds the identifier of the key element which shall be set.
 *  \param[in]     keyPtr                  Holds the pointer to the key data which shall be set as key element.
 *  \param[in]     keyLength               Contains the length of the key element in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_KEY_WRITE_FAIL Request failed, write access was denied.
 *                 CRYPTO_E_KEY_NOT_AVAILABLE  Request failed, the key is not available.
 *                 CRYPTO_E_KEY_SIZE_MISMATCH  Request failed, the key element size does not match size of provided
 *                                             data.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) keyPtr,
  uint32 keyLength);

/* [SWS_Crypto_91005] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyValidSet()
 *********************************************************************************************************************/
/*! \brief         Sets the key to valid
 *  \details       Sets the key state of the key identified by cryptoKeyId to valid.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key elements shall be set to valid.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyValidSet(
  uint32 cryptoKeyId);

/* [SWS_Crypto_91006] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyElementGet()
 *********************************************************************************************************************/
/*! \brief         This interface shall be used to get a key element of the key identified by the cryptoKeyId and store
 *                 the key element in the memory location pointed by the result pointer.
 *  \details       -
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key element shall be set.
 *  \param[in]     keyElementId            Holds the identifier of the key element which shall be set.
 *  \param[out]    resultPtr               Holds the pointer to the key data which shall be set as key element.
 *  \param[in,out] resultLengthPtr         Contains the length of the key element in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_KEY_READ_FAIL  Request failed, read access was denied.
 *                 CRYPTO_E_KEY_NOT_AVAILABLE  Request failed, the key is not available.
 *                 CRYPTO_E_KEY_SIZE_MISMATCH  Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) resultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) resultLengthPtr);

/* [SWS_Crypto_91013] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_RandomSeed()
 *********************************************************************************************************************/
/*! \brief         Initialize the seed
 *  \details       This function generates the internal seed state using the provided entropy source.
 *                 Furthermore, this function can be used to update the seed state with new entropy
 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_RandomSeed(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) entropyPtr,
  uint32 entropyLength);

/* [SWS_Crypto_91007] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyGenerate()
 *********************************************************************************************************************/
/*! \brief         Generates a key
 *  \details       This function shall dispatch the key generate function to the configured crypto driver object.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key which is to be updated with the generated
 *                                         value.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyGenerate(
  uint32 cryptoKeyId);

/* [SWS_Crypto_91008] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyDerive()
 *********************************************************************************************************************/
/*! \brief         Derives a key
 *  \details       Derives a new key by using the key elements in the given key identified by the cryptoKeyId.
 *                 The given key contains the key elements for the password, salt. The derived key is stored
 *                 in the key element with the id 1 of the key identified by targetCryptoKeyId.
 *                 The number of iterations is given in the key element CRYPTO_KE_KEYDERIVATION_ITERATIONS.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key which is used for key derivation.
 *  \param[in]     targetCryptoKeyId       Holds the identifier of the key which is used to store the derived key.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyDerive(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId);

/* [SWS_Crypto_91009] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyExchangeCalcPubVal()
 *********************************************************************************************************************/
/*! \brief         Calculation of the public value
 *  \details       Calculates the public value for the key exchange and stores the public key in the
 *                 memory location pointed by the public value pointer.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key which shall be used for the key exchange
 *                                         protocol.
 *  \param[out]    publicValuePtr          Contains the pointer to the data where the public value shall be stored.
 *  \param[in,out] publicValueLengthPtr    Holds a pointer to the memory location in which the public value length
 *                                         information is stored. On calling this function, this parameter shall
 *                                         contain the size of the buffer provided by publicValuePtr. When the request
 *                                         has finished, the actual length of the returned value shall be stored.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyExchangeCalcPubVal(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) publicValuePtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) publicValueLengthPtr);

/* [SWS_Crypto_91010] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyExchangeCalcSecret()
 *********************************************************************************************************************/
/*! \brief         Calculation of the secret
 *  \details       Calculates the shared secret key for the key exchange with the key material of the key identified
 *                 by the cryptoKeyId and the partner public key. The shared secret key is stored
 *                 as a key element in the same key.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key which shall be used for the key exchange
 *                                         protocol.
 *  \param[in]     partnerPublicValuePtr   Holds the pointer to the memory location which contains the partners
 *                                         public value.
 *  \param[in]     partnerPublicValueLength Contains the length of the partners public value in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyExchangeCalcSecret(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) partnerPublicValuePtr,
  uint32 partnerPublicValueLength);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_CertificateParse()
 *********************************************************************************************************************/
/*! \brief         Parse stored certificate
 *  \details       Parses the certificate data stored in the key element CRYPTO_KE_CERT_DATA and fills the key elements
 *                 CRYPTO_KE_CERT_SIGNEDDATA, CRYPTO_KE_CERT_PARSEDPUBLICKEY and CRYPTO_KE_CERT_SIGNATURE
 *  \param[in]     cryptoKeyId              Holds the identifier of the key slot in which the certificate has been
 *                                         stored.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_CertificateParse(
  uint32 cryptoKeyId);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_CertificateVerify()
 *********************************************************************************************************************/
/*! \brief         Certificate verification
 *  \details       Verifies the certificate stored in the key referenced by verifyCryptoKeyId with the
 *                 certificate stored in the key referenced by cryptoKeyId.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key which shall be used to validate the
 *                                         certificate.
 *  \param[in]     verifyCryptoKeyId       Holds the identifier of the key containing the certificate, which shall be
 *                                         verified.
 *  \param[out]    verifyPtr               Holds a pointer to the memory location which will contain the result of the
 *                                         certificate verification.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_CertificateVerify(
  uint32 cryptoKeyId,
  uint32 verifyCryptoKeyId,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) verifyPtr);

# define CRYPTO_30_VHSM_STOP_SEC_CODE
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif
