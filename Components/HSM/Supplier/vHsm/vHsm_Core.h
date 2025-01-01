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
/*!        \file  vHsm_Core.h
 *        \brief  Header file for the core driver
 *
 *      \details  Defines the public interface of the Core crypto driver.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_CORE_H)
# define VHSM_CORE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vHsm_Types.h"
# include "vHsm_Cfg.h"
# include "vHsm_Core_SecureBoot.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define CryptoConf_CryptoDriverObject_vHsm_Core                      (0x0000000UL)
# define CryptoConf_CryptoDriverObject_vHsm_KeyManagement             (0x0000001UL)
# define CryptoConf_CryptoKey_vHsm_Core_Admin                         (1u)
# define CryptoConf_CryptoKey_vHsm_Core_Info                          (2u)
# define VHSM_CORE_MODULO_8(x)                                        ((x) & (8u - 1u))

 /* API service IDs */
# define VHSM_SID_INIT                                                (0x00u) /*!< Service ID: vHsm_Init() */
# define VHSM_SID_GET_VERSION_INFO                                    (0x01u) /*!< Service ID: vHsm_GetVersionInfo() */
# define VHSM_SID_PROCESS_JOB                                         (0x03u) /*!< Service ID: vHsm_JobProcessor_Execute() */
# define VHSM_SID_CANCEL_JOB                                          (0x0Eu) /*!< Service ID: vHsm_CancelJob() */
# define VHSM_SID_KEY_ELEMENT_SET                                     (0x04u) /*!< Service ID: vHsm_KeyElementSet() */
# define VHSM_SID_KEY_VALID_SET                                       (0x05u) /*!< Service ID: vHsm_KeyValidSet() */
# define VHSM_SID_KEY_ELEMENT_GET                                     (0x06u) /*!< Service ID: vHsm_KeyElementGet() */
# define VHSM_SID_KEY_ELEMENT_COPY                                    (0x0Fu) /*!< Service ID: vHsm_KeyElementCopy() */
# define VHSM_SID_KEY_COPY                                            (0x10u) /*!< Service ID: vHsm_KeyCopy() */
# define VHSM_SID_KEY_ELEMENT_IDS_GET                                 (0x11u) /*!< Service ID: vHsm_KeyElementIdsGet() */
# define VHSM_SID_RANDOM_SEED                                         (0x0Du) /*!< Service ID: vHsm_RandomSeed() */
# define VHSM_SID_KEY_GENERATE                                        (0x07u) /*!< Service ID: vHsm_KeyGenerate() */
# define VHSM_SID_KEY_DERIVE                                          (0x08u) /*!< Service ID: vHsm_KeyDerive() */
# define VHSM_SID_KEY_EXCHANGE_CALC_PUB_VAL                           (0x09u) /*!< Service ID: vHsm_KeyExchangeCalcPubVal() */
# define VHSM_SID_KEY_EXCHANGE_CALC_SECRET                            (0x0Au) /*!< Service ID: vHsm_KeyExchangeCalcSecret() */
# define VHSM_SID_CERTIFICATE_PARSE                                   (0x0Bu) /*!< Service ID: vHsm_CertificateParse() */
# define VHSM_SID_CERTIFICATE_VERIFY                                  (0x12u) /*!< Service ID: vHsm_CertificateVerify() */
# define VHSM_SID_MAIN_FUNCTION                                       (0x0Cu) /*!< Service ID: vHsm_MainFunction() */

 /* Modes */
 /* State: Uninitialized */
# define VHSM_UNINIT                                                  (0x00u)
 /* State: Initialized */
# define VHSM_INITIALIZED                                             (0x01u)

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

# define VHSM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (VHSM_FIRMWARE_UPDATE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_GetUpdaterAddressOfFirmwareUpdate()
 *********************************************************************************************************************/
/*! \brief       Function to jump to the vHsm Firmware Updater. The Label must be defined in the linker script.
 *  \details     Call to this function will never return
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
extern FUNC(void, VHSM_CODE) vHsm_GetUpdaterAddressOfFirmwareUpdate()(void);
# endif

/**********************************************************************************************************************
 *  vHsm_Core_Init()
 *********************************************************************************************************************/
/*! \brief       Initializes the Crypto Driver
 *  \details     This function initializes the module Crypto_30_vHsm. It initializes all variables and sets the
 *               module state to initialized.
 *  \pre         Interrupts are disabled.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Specification of module initialization
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Core_Init(void);

/**********************************************************************************************************************
 *  vHsm_Core_InitMemory()
 *********************************************************************************************************************/
/*! \brief       The function initializes variables, which cannot be initialized with the startup code.
 *  \details     Initialize component variables at power up.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Core_InitMemory(void);

/**********************************************************************************************************************
 *  vHsm_Core_MainFunction()
 *********************************************************************************************************************/
/*! \brief         Main function of the Core which is cyclically called.
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 */
FUNC(void, VHSM_CODE) vHsm_Core_MainFunction(void);

/**********************************************************************************************************************
 *  vHsm_Core_ProcessJob()
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
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE|FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_ProcessJob(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job);

/**********************************************************************************************************************
 *  vHsm_Core_CancelJob()
 *********************************************************************************************************************/
/*! \brief         Cancels the received job
 *  \details       This interface removes the provided job from the queue and cancels the processing of the job if possible.
 *  \param[in]     objectId                Holds the identifier of the Crypto Driver Object.
 *  \param[in,out] job                     Pointer to the configuration of the job. Contains structures with user and
 *                                         primitive relevant information.
 *  \return        E_OK                    Request successful, job has been removed.
 *  \return        E_NOT_OK                Request failed, job could not be removed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_CancelJob(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job);

/**********************************************************************************************************************
 *  vHsm_Core_KeyElementSet()
 *********************************************************************************************************************/
/*! \brief         Sets a key element
 *  \details       Sets the given key element bytes to the key identified by cryptoKeyId. .
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
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) keyPtr,
  uint32 keyLength);

/**********************************************************************************************************************
 *  vHsm_Core_KeyElementGet()
 *********************************************************************************************************************/
/*! \brief         This interface shall be used to get a key element of the key identified by the cryptoKeyId and store
 *                 the key element in the memory location pointed by the result pointer.
 *  \details       -
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key element shall be set.
 *  \param[in]     keyElementId            Holds the identifier of the key element which shall be set.
 *  \param[out]    resultPtr               Holds the pointer to the key data which shall be set as key element.
 *  \param[in,out] resultLengthPtr         Contains the length of the key element in bytes.
 *  \return        E_OK                    Request successful.
 *  \return        E_NOT_OK                Request failed.
 *  \return        CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \return        CRYPTO_E_KEY_READ_FAIL  Request failed, read access was denied.
 *  \return        CRYPTO_E_KEY_NOT_AVAILABLE  Request failed, the key is not available.
 *  \return        CRYPTO_E_KEY_SIZE_MISMATCH  Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) resultPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) resultLengthPtr);

/**********************************************************************************************************************
 *  vHsm_Core_KeyValidSet()
 *********************************************************************************************************************/
/*! \brief         Sets the key to valid
 *  \details       Sets the key state of the key identified by cryptoKeyId to valid.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key elements shall be set to valid.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE, for different crypto keys
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyValidSet(
  uint32 cryptoKeyId);

# if(VHSM_ERRORLOGEVENTLOGREFOFGENERAL == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_WriteErrorLog()
 *********************************************************************************************************************/
/*! \brief         Write an error entry to the Key Storage
 *  \details       The error entry consists of an id and a data value which will be placed at the beginning
 *                 of the memory space of the key element. The older entries will be moved to the back.
 *                 If there is not enough space for old elements, they will be discarded.
 *  \param[in]     errorId                 Id of the error
 *  \param[in]     errorData               Data of the error. VHSM_LOG_DATA_NO_ERROR_DATA indicates not data.
 *  \return        E_OK                    Request successful.
 *  \return        E_NOT_OK                Request failed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_WriteErrorLog(
  uint32 errorId,
  uint32 errorData);
# endif

# define VHSM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (VHSM_FIRMWARE_UPDATE == STD_ON)
#  define VHSM_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  vHsm_FirmwareUpdate_PreJmpToUpdater_Callout()
 *********************************************************************************************************************/
/*! \brief         Callout just before the vHsm jumps into the vHsmUpdater.
 *  \details       This is needed e.g. if an Os is used and the SysTick-Interrupt needs to be disabled before jumping to the updater.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_FirmwareUpdate_PreJmpToUpdater_Callout(void);
#  define VHSM_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define VHSM_START_SEC_CODE_MAC_CALLOUT
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  vHsm_FirmwareUpdate_GetMacKey_Callout()
 *********************************************************************************************************************/
/*! \brief         Callout to get the value of the MAC key which is used during the vHsm Firmware Update
 *  \details       -
 *  \param[out]    keyPtr     Pointer to the buffer where 16 bytes of key data shall be stored
 *  \param[in,out] length     length of the buffer
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_FirmwareUpdate_GetMacKey_Callout(
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) length);
#  define VHSM_STOP_SEC_CODE_MAC_CALLOUT
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define VHSM_START_SEC_CODE_CIPHER_CALLOUT
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  vHsm_FirmwareUpdate_GetCipherKey_Callout()
 *********************************************************************************************************************/
/*! \brief         Callout to get the value of the Encryption key which is used during the vHsm Firmware Update
 *  \details       -
 *  \param[out]    keyPtr     Pointer to the buffer where 16 bytes of key data shall be stored
 *  \param[in,out] length     length of the buffer
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_FirmwareUpdate_GetCipherKey_Callout(
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) length);
#  define VHSM_STOP_SEC_CODE_CIPHER_CALLOUT
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif

/**********************************************************************************************************************
 * vHsm_Core_CertificateParse()
 **********************************************************************************************************************/
/*! \brief         Stub function because functionality is not provided by core driver
 *  \details       -
 *  \param[in]     cryptoKeyId             Value is not used.
 *  \return        E_NOT_OK                functionality is not provided
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_CertificateParse(
  uint32 cryptoKeyId);

/**********************************************************************************************************************
 * vHsm_Core_CertificateVerify()
 **********************************************************************************************************************/
/*! \brief         Stub function because functionality is not provided by core driver
 *  \details       -
 *  \param[in]     cryptoKeyId           Value is not used.
 *  \param[in]     verifyCryptoKeyId     Value is not used.
 *  \param[in,out] verifyPtr             Value is not used.
 *  \return        E_NOT_OK              functionality is not provided
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_CertificateVerify(
  uint32 cryptoKeyId,
  uint32 verifyCryptoKeyId,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, VHSM_APPL_VAR) verifyPtr);

/**********************************************************************************************************************
 * vHsm_Core_KeyCopy()
 **********************************************************************************************************************/
/*! \brief         Stub function because functionality is not provided by core driver
 *  \details       -
 *  \param[in]     cryptoKeyId           Value is not used.
 *  \param[in]     targetCryptoKeyId     Value is not used.
 *  \return        E_NOT_OK              functionality is not provided
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyCopy(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId);

/**********************************************************************************************************************
 * vHsm_Core_KeyDerive()
 **********************************************************************************************************************/
/*! \brief         Stub function because functionality is not provided by core driver
 *  \details       -
 *  \param[in]     cryptoKeyId           Value is not used.
 *  \param[in]     targetCryptoKeyId     Value is not used.
 *  \return        E_NOT_OK              functionality is not provided
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyDerive(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId);

/**********************************************************************************************************************
 * vHsm_Core_KeyElementCopy()
 **********************************************************************************************************************/
/*! \brief         Stub function because functionality is not provided by core driver
 *  \details       -
 *  \param[in]     cryptoKeyId             Value is not used.
 *  \param[in]     keyElementId            Value is not used.
 *  \param[in]     targetCryptoKeyId       Value is not used.
 *  \param[in]     targetKeyElementId      Value is not used.
 *  \return        E_NOT_OK                functionality is not provided
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyElementCopy(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  uint32 targetCryptoKeyId,
  uint32 targetKeyElementId);

/**********************************************************************************************************************
 * vHsm_Core_KeyElementCopyPartial()
 **********************************************************************************************************************/
/*! \brief         Stub function because functionality is not provided by core driver
 *  \details       Function is also called as stub for modules which do not support this ASR4.4 API
 *  \param[in]     cryptoKeyId             Value is not used.
 *  \param[in]     keyElementId            Value is not used.
 *  \param[in]     keyElementSourceOffset  Value is not used.
 *  \param[in]     keyElementTargetOffset  Value is not used.
 *  \param[in]     keyElementCopyLength    Value is not used.
 *  \param[in]     targetCryptoKeyId       Value is not used.
 *  \param[in]     targetKeyElementId      Value is not used.
 *  \return        E_NOT_OK                functionality is not provided
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyElementCopyPartial(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  uint32 keyElementSourceOffset,
  uint32 keyElementTargetOffset,
  uint32 keyElementCopyLength,
  uint32 targetCryptoKeyId,
  uint32 targetKeyElementId);

/**********************************************************************************************************************
 * vHsm_Core_KeyElementIdsGet()
 **********************************************************************************************************************/
/*! \brief         Stub function because functionality is not provided by core driver
 *  \details       -
 *  \param[in]     cryptoKeyId             Value is not used.
 *  \param[out]    keyElementIdsPtr        Value is not used.
 *  \param[in,out] keyElementIdsLengthPtr  Value is not used.
 *  \return        E_NOT_OK                functionality is not provided
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyElementIdsGet(
  uint32 cryptoKeyId,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) keyElementIdsPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) keyElementIdsLengthPtr);

/**********************************************************************************************************************
 * vHsm_Core_KeyExchangeCalcPubVal()
 **********************************************************************************************************************/
/*! \brief         Stub function because functionality is not provided by core driver
 *  \details       -
 *  \param[in]     cryptoKeyId             Value is not used.
 *  \param[out]    publicValuePtr          Value is not used.
 *  \param[in,out] publicValueLengthPtr    Value is not used.
 *  \return        E_NOT_OK                functionality is not provided
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyExchangeCalcPubVal(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) publicValuePtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) publicValueLengthPtr);

/**********************************************************************************************************************
 * vHsm_Core_KeyExchangeCalcSecret()
 **********************************************************************************************************************/
/*! \brief         Stub function because functionality is not provided by core driver
 *  \details       -
 *  \param[in]     cryptoKeyId                    Value is not used.
 *  \param[in]     partnerPublicValuePtr          Value is not used.
 *  \param[in]     partnerPublicValueLength       Value is not used.
 *  \return        E_NOT_OK                       functionality is not provided
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyExchangeCalcSecret(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) partnerPublicValuePtr,
  uint32 partnerPublicValueLength);

/**********************************************************************************************************************
 * vHsm_Core_KeyGenerate()
 **********************************************************************************************************************/
/*! \brief         Stub function because functionality is not provided by core driver
 *  \details       -
 *  \param[in]     cryptoKeyId             Value is not used.
 *  \return        E_NOT_OK                functionality is not provided
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyGenerate(
  uint32 cryptoKeyId);

/**********************************************************************************************************************
 * vHsm_Core_RandomSeed()
 **********************************************************************************************************************/
/*! \brief         Stub function because functionality is not provided by core driver
 *  \details       -
 *  \param[in]     cryptoKeyId             Value is not used.
 *  \param[in]     entropyPtr              Value is not used.
 *  \param[in]     entropyLength           Value is not used.
 *  \return        E_NOT_OK                functionality is not provided
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_RandomSeed(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_DATA) entropyPtr,
  uint32 entropyLength);

#endif /* VHSM_CORE_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Core.h
 *********************************************************************************************************************/
