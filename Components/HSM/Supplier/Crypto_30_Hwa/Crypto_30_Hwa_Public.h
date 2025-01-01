/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Crypto_30_Hwa_Public.h
 *        \brief  vHsm platform hardware abstraction library API
 *
 *      \details  This declares the hardware abstraction library API which is used by the vHsm Core.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (CRYPTO_30_HWA_PUBLIC_H)
# define CRYPTO_30_HWA_PUBLIC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Crypto_30_Hwa.h"
# include "Crypto_30_Hwa_Cfg.h"

# include "Crypto_30_LibCv.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define CRYPTO_30_HWA_VENDOR_ID                                           (30u)
# define CRYPTO_30_HWA_MODULE_ID                                           (114u)
# define CRYPTO_30_HWA_INSTANCE_ID                                         (0u)

/* AUTOSAR Software Specification Version Information */
# define CRYPTO_30_HWA_AR_RELEASE_MAJOR_VERSION                            (4)
# define CRYPTO_30_HWA_AR_RELEASE_MINOR_VERSION                            (3)
# define CRYPTO_30_HWA_AR_RELEASE_REVISION_VERSION                         (0)

# define CRYPTO_30_HWA_MODULO_8(x)                                         ((x) & (8u - 1u)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define CRYPTO_30_HWA_VHSM_ACTIVE                                         (0u)
# define CRYPTO_30_HWA_VHSM_READY                                          (1u)

/* API service IDs */
# define CRYPTO_30_HWA_SID_INIT                                            (0x00u) /*!< Service ID: Crypto_30_Hwa_Init() */
# define CRYPTO_30_HWA_SID_GET_VERSION_INFO                                (0x01u) /*!< Service ID: Crypto_30_Hwa_GetVersionInfo() */
# define CRYPTO_30_HWA_SID_PROCESS_JOB                                     (0x03u) /*!< Service ID: Crypto_30_Hwa_ProcessJob() */
# define CRYPTO_30_HWA_SID_CANCEL_JOB                                      (0x0Eu) /*!< Service ID: Crypto_30_Hwa_CancelJob() */
# define CRYPTO_30_HWA_SID_KEY_ELEMENT_SET                                 (0x04u) /*!< Service ID: Crypto_30_Hwa_KeyElementSet() */
# define CRYPTO_30_HWA_SID_KEY_VALID_SET                                   (0x05u) /*!< Service ID: Crypto_30_Hwa_KeyValidSet() */
# define CRYPTO_30_HWA_SID_KEY_ELEMENT_GET                                 (0x06u) /*!< Service ID: Crypto_30_Hwa_KeyElementGet() */
# define CRYPTO_30_HWA_SID_KEY_ELEMENT_COPY                                (0x0Fu) /*!< Service ID: Crypto_30_Hwa_KeyElementCopy() */
# define CRYPTO_30_HWA_SID_KEY_COPY                                        (0x10u) /*!< Service ID: Crypto_30_Hwa_KeyCopy() */
# define CRYPTO_30_HWA_SID_KEY_ELEMENT_IDS_GET                             (0x11u) /*!< Service ID: Crypto_30_Hwa_KeyElementIdsGet() */
# define CRYPTO_30_HWA_SID_RANDOM_SEED                                     (0x0Du) /*!< Service ID: Crypto_30_Hwa_RandomSeed() */
# define CRYPTO_30_HWA_SID_KEY_GENERATE                                    (0x07u) /*!< Service ID: Crypto_30_Hwa_KeyGenerate() */
# define CRYPTO_30_HWA_SID_KEY_DERIVE                                      (0x08u) /*!< Service ID: Crypto_30_Hwa_KeyDerive() */
# define CRYPTO_30_HWA_SID_KEY_EXCHANGE_CALC_PUB_VAL                       (0x09u) /*!< Service ID: Crypto_30_Hwa_KeyExchangeCalcPubVal() */
# define CRYPTO_30_HWA_SID_KEY_EXCHANGE_CALC_SECRET                        (0x0Au) /*!< Service ID: Crypto_30_Hwa_KeyExchangeCalcSecret() */
# define CRYPTO_30_HWA_SID_CERTIFICATE_PARSE                               (0x0Bu) /*!< Service ID: Crypto_30_Hwa_CertificateParse() */
# define CRYPTO_30_HWA_SID_CERTIFICATE_VERIFY                              (0x12u) /*!< Service ID: Crypto_30_Hwa_CertificateVerify() */
# define CRYPTO_30_HWA_SID_MAIN_FUNCTION                                   (0x0Cu) /*!< Service ID: Crypto_30_Hwa_MainFunction() */

/* Modes */
/* State: Uninitialized */
# define CRYPTO_30_HWA_UNINIT                                              (0u)
/* State: Initialized */
# define CRYPTO_30_HWA_INITIALIZED                                         (1u)

/* Development Error Types [SWS_Crypto_00040] */
# ifndef CRYPTO_E_NO_ERROR /* COV_CRYPTO_30_HWA_CSM_DEFINES */
#  define CRYPTO_E_NO_ERROR                                           (255u)
# endif
# ifndef CRYPTO_E_UNINIT /* COV_CRYPTO_30_HWA_CSM_DEFINES */
#  define CRYPTO_E_UNINIT                                             (0u)
# endif
# ifndef CRYPTO_E_INIT_FAILED /* COV_CRYPTO_30_HWA_CSM_DEFINES */
#  define CRYPTO_E_INIT_FAILED                                        (1u)
# endif
# ifndef CRYPTO_E_PARAM_POINTER /* COV_CRYPTO_30_HWA_CSM_DEFINES */
#  define CRYPTO_E_PARAM_POINTER                                      (2u)
# endif
# ifndef CRYPTO_E_PARAM_HANDLE /* COV_CRYPTO_30_HWA_CSM_DEFINES */
#  define CRYPTO_E_PARAM_HANDLE                                       (4u)
# endif
# ifndef CRYPTO_E_PARAM_VALUE /* COV_CRYPTO_30_HWA_CSM_DEFINES */
#  define CRYPTO_E_PARAM_VALUE                                        (5u)
# endif

/* Redirect to LibCv Crypto Driver */
# define Crypto_30_Hwa_CertificateParse                          Crypto_30_LibCv_CertificateParse
# define Crypto_30_Hwa_CertificateVerify                         Crypto_30_LibCv_CertificateVerify
# define Crypto_30_Hwa_KeyCopy                                   Crypto_30_LibCv_KeyCopy
# define Crypto_30_Hwa_KeyElementCopy                            Crypto_30_LibCv_KeyElementCopy
# define Crypto_30_Hwa_KeyElementIdsGet                          Crypto_30_LibCv_KeyElementIdsGet
# define Crypto_30_Hwa_KeyExchangeCalcPubVal                     Crypto_30_LibCv_KeyExchangeCalcPubVal
# define Crypto_30_Hwa_KeyExchangeCalcSecret                     Crypto_30_LibCv_KeyExchangeCalcSecret
# define Crypto_30_Hwa_KeyGenerate                               Crypto_30_LibCv_KeyGenerate
# define Crypto_30_Hwa_RandomSeed                                Crypto_30_LibCv_RandomSeed

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

# define CRYPTO_30_HWA_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Init()
 *********************************************************************************************************************/
/*! \brief         Initializes the vHsm Hardware Abstraction Library.
 *  \details       This function initializes the module Crypto_30_Hwa. It initializes all variables and sets the
 *                 module state to initialized.
 *  \pre           Module is uninitialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Init(void);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_InitMemory()
 *********************************************************************************************************************/
/*! \brief         Initializes variables and memory areas that cannot be initialized with the startup code.
 *  \details       Initialize component variables at power up.
 *  \pre           Module is uninitialized.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_InitMemory(void);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CancelJob()
 *********************************************************************************************************************/
/*! \brief         Cancels the given job
 *  \details       Tries to remove the provided job from the queue and cancels the processing of the job if possible.
 *  \param[in]     objectId                Holds the identifier of the Crypto Driver Object.
 *  \param[in,out] job                     Pointer to the job object.
 *  \return        E_OK                    Request successful, job has been removed.
 *                 E_NOT_OK                Request failed, job could not be removed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CancelJob(
  uint32 objectId,
  Crypto_30_Hwa_JobPtrType job);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessJob()
 *********************************************************************************************************************/
/*! \brief         Processes the received job
 *  \details       Execute the crypto primitive which is given by the job
 *  \param[in]     objectId                Holds the identifier of the Crypto Driver Object.
 *  \param[in,out] job                     Pointer to the job object.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
 *                 CRYPTO_E_QUEUE_FULL     Request failed, the queue is full.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE|FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessJob(
  uint32 objectId,
  Crypto_30_Hwa_JobPtrType job);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_KeyDerive()
 *********************************************************************************************************************/
/*! \brief          Derives a new key based on the key elements in cryptoKeyId.
 *  \details        Derives a new key based on the key elements in cryptoKeyId and stores the key in targetCryptoKeyId
 *  \param[in]      cryptoKeyId             Key used for key derivation
 *  \param[in]      targetCryptoKeyId       Key which stores the result
 *  \return         E_OK                    Request successful
 *  \return         E_NOT_OK                Request Failed
 *  \return         E_BUSY                  Request failed, Crypto Driver Object is busy
 *  \return         CRYPTO_E_KEY_EMPTY      Request failed because of uninitialized source key element.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_KeyDerive(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_KeyElementSet()
 *********************************************************************************************************************/
/*! \brief         Writes a key element of a key
 *  \details       Writes the key element of key cryptoKeyId
 *  \param[in]     cryptoKeyId                 Key containing the key elment.
 *  \param[in]     keyElementId                Key element.
 *  \param[in]     keyPtr                      Data that shall be copied to key element.
 *  \param[in]     keyLength                   Length of the key element in bytes.
 *  \return        E_OK                        Request successful.
 *                 E_NOT_OK                    Request failed.
 *                 CRYPTO_E_BUSY               Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_KEY_WRITE_FAIL     Request failed, write access was denied.
 *                 CRYPTO_E_KEY_NOT_AVAILABLE  Request failed, the key is not available.
 *                 CRYPTO_E_KEY_SIZE_MISMATCH  Request failed, the key element size does not match size of provided
 *                                             data.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_KeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) keyPtr,
  uint32 keyLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_KeyElementGet()
 *********************************************************************************************************************/
/*! \brief         Reads a key element from a key
 *  \details       Reads a key element from key cryptoKeyId ans store result to resultPtr.
 *  \param[in]     cryptoKeyId                 Key containing the key element.
 *  \param[in]     keyElementId                Key element.
 *  \param[out]    resultPtr                   Buffer where the data shall be written.
 *  \param[in,out] resultLengthPtr             Length of key element
 *  \return        E_OK                        Request successful.
 *                 E_NOT_OK                    Request failed.
 *                 CRYPTO_E_BUSY               Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_KEY_READ_FAIL      Request failed, read access was denied.
 *                 CRYPTO_E_KEY_NOT_AVAILABLE  Request failed, the key is not available.
 *                 CRYPTO_E_KEY_SIZE_MISMATCH  Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) resultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) resultLengthPtr);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_KeyValidSet()
 *********************************************************************************************************************/
/*! \brief         Sets a key to valid
 *  \details       Sets the state of the key identified by cryptoKeyId to valid.
 *  \param[in]     cryptoKeyId             Key
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, for different crypto keys
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_KeyValidSet(
  uint32 cryptoKeyId);

# define CRYPTO_30_HWA_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* CRYPTO_30_HWA_PUBLIC_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Public.h
 *********************************************************************************************************************/
