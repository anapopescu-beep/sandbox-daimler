/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsm_Custom.h
 *        \brief  Custom driver header file.
 *
 *      \details  Defines the public interface of the Custom crypto driver.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Tobias Finke                  vistof         Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2018-05-14  vistof  -             Initial version
 *  01.01.00  2018-07-02  vistof  STORYC-5837   Release of component
 *********************************************************************************************************************/

#if !defined (VHSM_CUSTOM_H)
# define VHSM_CUSTOM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vHsm_Types.h"
# include "vHsm_Custom_Custom.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define VHSM_CUSTOM_VENDOR_ID                       (30u)
# define VHSM_CUSTOM_MODULE_ID                       (114u)
# define VHSM_CUSTOM_INSTANCE_ID                     (0u)

/* AUTOSAR Software Specification Version Information */
# define VHSM_CUSTOM_AR_RELEASE_MAJOR_VERSION        (0x04)
# define VHSM_CUSTOM_AR_RELEASE_MINOR_VERSION        (0x03)
# define VHSM_CUSTOM_AR_RELEASE_REVISION_VERSION     (0x00)

/* Component Version Information */
/* No u suffix is used for shift operator because some compilers may have problems */
# define VHSM_CUSTOM_SW_MAJOR_VERSION                (24u)
# define VHSM_CUSTOM_SW_MINOR_VERSION                (03u)
# define VHSM_CUSTOM_SW_PATCH_VERSION                (00u)

# define CryptoConf_CryptoDriverObject_vHsm_Custom   (0x00000000UL)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* Redirect Key Management API to LibCv Crypto module */
# define vHsm_Custom_KeyCopy                        Crypto_30_LibCv_KeyCopy
# define vHsm_Custom_KeyElementCopy                 Crypto_30_LibCv_KeyElementCopy
# define vHsm_Custom_KeyElementIdsGet               Crypto_30_LibCv_KeyElementIdsGet
# define vHsm_Custom_KeyValidSet                    Crypto_30_LibCv_KeyValidSet
# define vHsm_Custom_RandomSeed                     Crypto_30_LibCv_RandomSeed
# define vHsm_Custom_KeyGenerate                    Crypto_30_LibCv_KeyGenerate
# define vHsm_Custom_KeyDerive                      Crypto_30_LibCv_KeyDerive
# define vHsm_Custom_KeyExchangeCalcPubVal          Crypto_30_LibCv_KeyExchangeCalcPubVal
# define vHsm_Custom_KeyExchangeCalcSecret          Crypto_30_LibCv_KeyExchangeCalcSecret
# define vHsm_Custom_CertificateParse               Crypto_30_LibCv_CertificateParse
# define vHsm_Custom_CertificateVerify              Crypto_30_LibCv_CertificateVerify

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VHSM_CUSTOM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  vHsm_Custom_Init()
 *********************************************************************************************************************/
/*! \brief       Initializes the Crypto Driver
 *  \details     This function initializes the module vHsm_Custom. It initializes all variables and sets the
 *               module state to initialized.
 *  \pre         Interrupts are disabled.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Specification of module initialization
 *********************************************************************************************************************/
FUNC(void, VHSM_CUSTOM_CODE) vHsm_Custom_Init(void);

/**********************************************************************************************************************
 *  vHsm_Custom_InitMemory()
 *********************************************************************************************************************/
/*! \brief       The function initializes variables, which cannot be initialized with the startup code.
 *  \details     Initialize component variables at power up.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CUSTOM_CODE) vHsm_Custom_InitMemory(void);

/**********************************************************************************************************************
 *  vHsm_Custom_MainFunction()
 *********************************************************************************************************************/
/*! \brief         Main function of the Custom driver which is cyclically called.
 *  \details       -
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 */
FUNC(void, VHSM_CODE) vHsm_Custom_MainFunction(void);

/**********************************************************************************************************************
 *  vHsm_Custom_ProcessJob()
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
FUNC(Std_ReturnType, VHSM_CUSTOM_CODE) vHsm_Custom_ProcessJob(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_CUSTOM_APPL_VAR) job);

/**********************************************************************************************************************
 *  vHsm_Custom_CancelJob()
 *********************************************************************************************************************/
/*! \brief         Cancels the received job
 *  \details       This interface removes the provided job from the queue and cancels the processing of the job if possible.
 *  \param[in]     objectId                Holds the identifier of the Crypto Driver Object.
 *  \param[in,out] job                     Pointer to the configuration of the job. Contains structures with user and
 *                                         primitive relevant information.
 *  \return        E_OK                    Request successful, job has been removed.
 *  \return        E_NOT_OK                Request failed, job could not be removed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CUSTOM_CODE) vHsm_Custom_CancelJob(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_CUSTOM_APPL_VAR) job);

/**********************************************************************************************************************
 *  vHsm_Custom_KeyElementSet()
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
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         SPEC-2894755, SPEC-2894756, SPEC-2894757, SPEC-2894759, SPEC-2894760, SPEC-2894761
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CUSTOM_CODE) vHsm_Custom_KeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, VHSM_CUSTOM_APPL_VAR) keyPtr,
  uint32 keyLength);

/**********************************************************************************************************************
 *  vHsm_Custom_KeyElementGet()
 *********************************************************************************************************************/
/*! \brief         This interface shall be used to get a key element of the key identified by the cryptoKeyId and store
 *                 the key element in the memory location pointed by the result pointer.
 *  \details       -
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key element shall be set.
 *  \param[in]     keyElementId            Holds the identifier of the key element which shall be set.
 *  \param[in]     resultPtr               Holds the pointer to the key data which shall be set as key element.
 *  \param[in]     resultLengthPtr         Contains the length of the key element in bytes.
 *  \return        E_OK                    Request successful.
 *  \return        E_NOT_OK                Request failed.
 *  \return        CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \return        CRYPTO_E_KEY_READ_FAIL  Request failed, read access was denied.
 *  \return        CRYPTO_E_KEY_NOT_AVAILABLE  Request failed, the key is not available.
 *  \return        CRYPTO_E_KEY_SIZE_MISMATCH  Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CUSTOM_CODE) vHsm_Custom_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, VHSM_CUSTOM_APPL_VAR) resultPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_CUSTOM_APPL_VAR) resultLengthPtr);

# define VHSM_CUSTOM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* VHSM_CUSTOM_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Custom.h
 *********************************************************************************************************************/
