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
/*!        \file  Crypto_30_KeyM.h
 *        \brief  KeyM crypto driver header file.
 *
 *      \details  Defines the public interface of the vHsm KeyM crypto driver.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2020-01-14  visebj  HSM-703       Initial version
 *  01.01.00  2020-08-12  visebj  HSM-852       Provide CSR using KeyM
 *                                ESCAN00107095 Make CertElement APIs compatible again
 *  01.02.00  2021-06-08  visebj  HSM-1687      Support KeyM Remote Handling
 *  01.02.01  2022-04-07  visebj  ESCAN00110975 Use intended KeyM Dispatch APIs for Remote Handling
 *********************************************************************************************************************/

#if !defined (CRYPTO_30_KEYM_H)
# define CRYPTO_30_KEYM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vHsm_Types.h"
# include "Crypto_30_KeyM_Custom.h"
# include "Crypto_30_KeyM_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define CRYPTO_30_KEYM_VERSION                                       (0x0102u)
# define CRYPTO_30_KEYM_RELEASE_VERSION                               (0x01u)

/* Vendor and module identification */
# define CRYPTO_30_KEYM_VENDOR_ID                                     (30u)
# define CRYPTO_30_KEYM_MODULE_ID                                     (114u)

/* AUTOSAR Software Specification Version Information */
# define CRYPTO_30_KEYM_AR_RELEASE_MAJOR_VERSION                      (0x04)
# define CRYPTO_30_KEYM_AR_RELEASE_MINOR_VERSION                      (0x04)
# define CRYPTO_30_KEYM_AR_RELEASE_REVISION_VERSION                   (0x00)

/* Component Version Information */
/* No u suffix is used for shift operator because some compilers may have problems */
# define CRYPTO_30_KEYM_SW_MAJOR_VERSION                              (CRYPTO_30_KEYM_VERSION >> 8)
# define CRYPTO_30_KEYM_SW_MINOR_VERSION                              (CRYPTO_30_KEYM_VERSION & 0x00FFu)
# define CRYPTO_30_KEYM_SW_PATCH_VERSION                              (CRYPTO_30_KEYM_RELEASE_VERSION)

# define CRYPTO_30_KEYM_INSTANCE_ID_DET                               (0u)

# define CRYPTO_30_KEYM_SERIALIZED_CERTELEMENTITERATOR_SIZE           (7u)  /* size of the KeyM_CertElementIteratorType in bytes */
# define CRYPTO_30_KEYM_SERIALIZED_CERTELEMENTID_SIZE                 (2u)  /* size of the KeyM_CertElementIdType in bytes */
# define CRYPTO_30_KEYM_SERIALIZED_CERTIFICATEID_SIZE                 (2u)  /* size of the KeyM_CertificateIdType in bytes */

/* API service IDs */
# define CRYPTO_30_KEYM_SID_INIT                                      (0x00u) /*!< Service ID: Crypto_30_KeyM_Init() */
# define CRYPTO_30_KEYM_SID_GET_VERSION_INFO                          (0x01u) /*!< Service ID: Crypto_30_KeyM_GetVersionInfo() */
# define CRYPTO_30_KEYM_SID_PROCESS_JOB                               (0x03u) /*!< Service ID: Crypto_30_KeyM_ProcessJob() */
# define CRYPTO_30_KEYM_SID_CANCEL_JOB                                (0x0Eu) /*!< Service ID: Crypto_30_KeyM_CancelJob() */
# define CRYPTO_30_KEYM_SID_KEY_ELEMENT_SET                           (0x04u) /*!< Service ID: Crypto_30_KeyM_KeyElementSet() */
# define CRYPTO_30_KEYM_SID_KEY_VALID_SET                             (0x05u) /*!< Service ID: Crypto_30_KeyM_KeyValidSet() */
# define CRYPTO_30_KEYM_SID_KEY_ELEMENT_GET                           (0x06u) /*!< Service ID: Crypto_30_KeyM_KeyElementGet() */

# define CRYPTO_30_KEYM_GENERIC

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define CRYPTO_30_KEYM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_KeyM_Init()
 *********************************************************************************************************************/
/*! \brief       Initializes the Crypto Driver
 *  \details     This function initializes the module Crypto_30_KeyM. It initializes all variables and sets the
 *               module state to initialized.
 *  \pre         Interrupts are disabled.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Specification of module initialization
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_Init(void);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_InitMemory()
 *********************************************************************************************************************/
/*! \brief       The function initializes variables, which cannot be initialized with the startup code.
 *  \details     Initialize component variables at power up.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_InitMemory(void);

/**********************************************************************************************************************
 * Crypto_30_KeyM_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief         Returns the version information.
 *  \details       Crypto_30_KeyM_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]    VersionInfo             Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) VersionInfo);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_ProcessJob()
 *********************************************************************************************************************/
/*! \brief         Processes the received job
 *  \details       Performs the crypto primitive, that is configured in the job parameter.
 *  \param[in]     objectId                Holds the identifier of the Crypto Driver Object.
 *  \param[in,out] job                     Pointer to the configuration of the job. Contains structures with job and
 *                                         primitive relevant information but also pointer to result buffers.
 *  \return        E_OK                    Request successful.
 *  \return        E_NOT_OK                Request failed.
 *  \return        CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \return        CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
 *  \return        CRYPTO_E_QUEUE_FULL     Request failed, the queue is full.
 *  \return        CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE|FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_ProcessJob(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_CancelJob()
 *********************************************************************************************************************/
/*! \brief         Cancels the received job
 *  \details       This function exists for compatibility reasons.
 *                 Functionality is not implemented and will return always E_NOT_OK.
 *  \param[in]     objectId                Holds the identifier of the Crypto Driver Object.
 *  \param[in,out] job                     Pointer to the configuration of the job. Contains structures with user and
 *                                         primitive relevant information.
 *  \return        E_NOT_OK                Request failed, job could not be removed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_CancelJob(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyElementSet()
 *********************************************************************************************************************/
/*! \brief         Sets a key element
 *  \details       Sets the given key element bytes to the key identified by cryptoKeyId.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key element shall be set.
 *  \param[in]     keyElementId            Holds the identifier of the key element which shall be set.
 *  \param[in]     keyPtr                  Holds the pointer to the key data which shall be set as key element.
 *  \param[in]     keyLength               Contains the length of the key element in bytes.
 *  \return        E_OK                    Request successful.
 *  \return        E_NOT_OK                Request failed.
 *  \return        CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \return        CRYPTO_E_KEY_WRITE_FAIL Request failed, write access was denied.
 *  \return        CRYPTO_E_KEY_NOT_AVAILABLE  Request failed, the key is not available.
 *  \return        CRYPTO_E_KEY_SIZE_MISMATCH  Request failed, the key element size does not match size of provided
 *                                             data.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) keyPtr,
  uint32 keyLength);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyValidSet()
 *********************************************************************************************************************/
/*! \brief         Sets the key to valid
 *  \details       Sets the key state of the key identified by cryptoKeyId to valid.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key elements shall be set to valid.
 *  \return        E_OK                    Request successful.
 *  \return        E_NOT_OK                Request failed.
 *  \return        CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyValidSet(
  uint32 cryptoKeyId);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyElementGet()
 *********************************************************************************************************************/
/*! \brief         This interface shall be used to get a key element of the key identified by the cryptoKeyId and store
 *                 the key element in the memory location pointed by the result pointer.
 *  \details       -
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key element shall be set.
 *  \param[in]     keyElementId            Holds the identifier of the key element which shall be set.
 *  \param[out]    resultPtr               Holds the pointer to the key data which shall be set as key element.
 *  \param[out]    resultLengthPtr         Contains the length of the key element in bytes.
 *  \return        E_OK                    Request successful.
 *  \return        E_NOT_OK                Request failed.
 *  \return        CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \return        CRYPTO_E_KEY_READ_FAIL  Request failed, read access was denied.
 *  \return        CRYPTO_E_KEY_NOT_AVAILABLE  Request failed, the key is not available.
 *  \return        CRYPTO_E_KEY_SIZE_MISMATCH  Request failed, the provided buffer is too small to store the result.
 *  \return        CRYPTO_E_KEY_EMPTY      Request failed, key is empty.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) resultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) resultLengthPtr);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyCopy()
 *********************************************************************************************************************/
/*! \brief         Copy the key
 *  \details       This function exists for compatibility reasons.
 *                 Functionality is not implemented and will return always E_NOT_OK.
 *  \param[in]     cryptoKeyId                  Holds the identifier of the key whose key element shall be the source
 *                                              element.
 *  \param[in]     targetCryptoKeyId            Holds the identifier of the key whose key element shall be the destination
 *                                              element.
 *  \return        E_NOT_OK                     Since functionality is not provided.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyCopy(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyElementCopy()
 *********************************************************************************************************************/
/*! \brief         Copy key element
 *  \details       This function exists for compatibility reasons.
 *                 Functionality is not implemented and will return always E_NOT_OK.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key element shall be the source
 *                                         element.
 *  \param[in]     keyElementId            Holds the identifier of the key element which shall be the source for the
 *                                         copy operation.
 *  \param[in]     targetCryptoKeyId       Holds the identifier of the key whose key element shall be the destination
 *                                         element.
 *  \param[in]     targetKeyElementId      Holds the identifier of the key element which shall be the destination for
 *                                         the copy operation.
 *  \return        E_NOT_OK                Since functionality is not provided.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, for different crypto keys
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyElementCopy(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  uint32 targetCryptoKeyId,
  uint32 targetKeyElementId);

/**********************************************************************************************************************
 * Crypto_30_KeyM_KeyElementCopyPartial()
 **********************************************************************************************************************/
/*! \brief         Copy key element partial
 *  \details       This function exists for compatibility reasons.
 *                 Functionality is not implemented and will return always E_NOT_OK.
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
 *  \return        E_NOT_OK                Since functionality is not provided.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, for different crypto keys
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyElementCopyPartial(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  uint32 keyElementSourceOffset,
  uint32 keyElementTargetOffset,
  uint32 keyElementCopyLength,
  uint32 targetCryptoKeyId,
  uint32 targetKeyElementId);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyElementIdsGet()
 *********************************************************************************************************************/
/*! \brief         Used to retrieve information which key elements are available in a given key.
 *  \details       This function exists for compatibility reasons.
 *                 Functionality is not implemented and will return always E_NOT_OK.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose available element ids shall be exported.
 *  \param[out]    keyElementIdsPtr        Contains the pointer to the array where the ids of the key
 *                                         elements shall be stored.
 *  \param[out]     keyElementIdsLengthPtr  Holds a pointer to the memory location in which the number of key element
 *                                         in the given key is stored. On calling this function, this parameter
 *                                         shall contain the size of the buffer provided by keyElementIdsPtr. When the
 *                                         request has finished, the actual number of key elements is stored.
 *  \return        E_NOT_OK                Since functionality is not provided.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyElementIdsGet(
  uint32 cryptoKeyId,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) keyElementIdsPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) keyElementIdsLengthPtr);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_RandomSeed()
 *********************************************************************************************************************/
/*! \brief         Initialize the seed
 *  \details       This function exists for compatibility reasons.
 *                 Functionality is not implemented and will return always E_NOT_OK.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_NOT_OK                Since functionality is not provided.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, for different crypto keys
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_RandomSeed(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) entropyPtr,
  uint32 entropyLength);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyGenerate()
 *********************************************************************************************************************/
/*! \brief         Generates a key
 *  \details       This function exists for compatibility reasons.
 *                 Functionality is not implemented and will return always E_NOT_OK.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key which is to be updated with the generated
 *                                         value.
 *  \return        E_NOT_OK                Since functionality is not provided.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, for different crypto keys
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyGenerate(
  uint32 cryptoKeyId);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyDerive()
 *********************************************************************************************************************/
/*! \brief         Derives a key
 *  \details       This function exists for compatibility reasons.
 *                 Functionality is not implemented and will return always E_NOT_OK.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key which is used for key derivation.
 *  \param[in]     targetCryptoKeyId       Holds the identifier of the key which is used to store the derived key.
 *  \return        E_NOT_OK                Since functionality is not provided.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, for different crypto keys
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyDerive(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyExchangeCalcPubVal()
 *********************************************************************************************************************/
/*! \brief         Calculation of the public value
 *  \details       This function exists for compatibility reasons.
 *                 Functionality is not implemented and will return always E_NOT_OK.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key which shall be used for the key exchange
 *                                         protocol.
 *  \param[out]    publicValuePtr          Contains the pointer to the data where the public value shall be stored.
 *  \param[in,out] publicValueLengthPtr    Holds a pointer to the memory location in which the public value length
 *                                         information is stored. On calling this function, this parameter shall
 *                                         contain the size of the buffer provided by publicValuePtr. When the request
 *                                         has finished, the actual length of the returned value shall be stored.
 *  \return        E_NOT_OK                Since functionality is not provided.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, for different crypto keys
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyExchangeCalcPubVal(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) publicValuePtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) publicValueLengthPtr);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_KeyExchangeCalcSecret()
 *********************************************************************************************************************/
/*! \brief         Calculation of the secret
 *  \details       This function exists for compatibility reasons.
 *                 Functionality is not implemented and will return always E_NOT_OK.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key which shall be used for the key exchange
 *                                         protocol.
 *  \param[in]     partnerPublicValuePtr   Holds the pointer to the memory location which contains the partners
 *                                         public value.
 *  \param[in]     partnerPublicValueLength Contains the length of the partners public value in bytes.
 *  \return        E_NOT_OK                Since functionality is not provided.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, for different crypto keys
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_KeyExchangeCalcSecret(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) partnerPublicValuePtr,
  uint32 partnerPublicValueLength);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_CertificateParse()
 *********************************************************************************************************************/
/*! \brief         Parse stored certificate
 *  \details       This function exists for compatibility reasons.
 *                 Functionality is not implemented and will return always E_NOT_OK.
 *  \param[in]     cryptoKeyId              Holds the identifier of the key slot in which the certificate has been
 *                                         stored.
 *  \return        E_NOT_OK                Since functionality is not provided.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, for different crypto keys
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_CertificateParse(
  uint32 cryptoKeyId);

/**********************************************************************************************************************
 *  Crypto_30_KeyM_CertificateVerify()
 *********************************************************************************************************************/
/*! \brief         Certificate verification
 *  \details       This function exists for compatibility reasons.
 *                 Functionality is not implemented and will return always E_NOT_OK.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key which shall be used to validate the
 *                                         certificate.
 *  \param[in]     verifyCryptoKeyId       Holds the identifier of the key containing the certificate, which shall be
 *                                         verified.
 *  \param[out]    verifyPtr               Holds a pointer to the memory location which will contain the result of the
 *                                         certificate verification.
 *  \return        E_NOT_OK                Since functionality is not provided.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, for different crypto keys
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_KEYM_CODE) Crypto_30_KeyM_CertificateVerify(
  uint32 cryptoKeyId,
  uint32 verifyCryptoKeyId,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_30_KEYM_APPL_VAR) verifyPtr);

# define CRYPTO_30_KEYM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* CRYPTO_30_KEYM_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_KeyM.h
 *********************************************************************************************************************/
