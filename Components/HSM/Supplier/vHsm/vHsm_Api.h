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
/*!        \file  vHsm_Api.h
 *        \brief  Api functions which can be used by the crypto drivers to minimize dependencies to the LibCv driver
 *
 *      \details  -
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_API_H)
# define VHSM_API_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vHsm_Trace.h"
# include "vHsm_Core_Custom.h"

# include "Crypto_30_LibCv.h"
# include "Crypto_30_LibCv_Services.h"
# include "Crypto_30_LibCv_KeyManagement.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

# define vHsm_Api_TempJob_WriteToJobField(type, field, value)         *((P2VAR(type, AUTOMATIC, VHSM_APPL_VAR))&(field)) = (value)

# define vHsm_JoinUsageRestrictionOfJobObjects(Index, Value)          vHsm_SetUsageRestrictionOfJobObjects(Index, (vHsm_GetUsageRestrictionOfJobObjects(Index) | Value))
# define vHsm_DeleteUsageRestrictionOfJobObjects(Index, Value)        vHsm_SetUsageRestrictionOfJobObjects(Index, (vHsm_GetUsageRestrictionOfJobObjects(Index) & ((uint8)(~Value))))

/* Key storage access */
# define vHsm_Api_KeyStorageIndexType                                 Crypto_30_LibCv_SizeOfKeyStorageType
# define vHsm_Api_GetAddrKeyStorage                                   Crypto_30_LibCv_GetAddrKeyStorage
# define vHsm_Api_KeyStorageOffsetType                                Crypto_30_LibCv_KeyStorageEndIdxOfKeyElementsType

/* Key element set */
# define vHsm_Api_Local_KeyElementSetInternal                         Crypto_30_LibCv_Local_KeyElementSetInternal
# define vHsm_Api_KeyElementSet                                       Crypto_30_LibCv_KeyElementSet

/* Key element get */
# define vHsm_Api_KeyElementGet                                       Crypto_30_LibCv_KeyElementGet

/* Other key element stuff */
# define vHsm_Api_Local_KeyElementGetStorageIndex                     Crypto_30_LibCv_Local_KeyElementGetStorageIndex
# define vHsm_Api_SizeOfKeyElementsType                               Crypto_30_LibCv_SizeOfKeyElementsType
# define vHsm_Api_Local_KeyElementSearch                              Crypto_30_LibCv_Local_KeyElementSearch
# define vHsm_Api_KeyValidSet                                         Crypto_30_LibCv_KeyValidSet
# define vHsm_Api_KeyValidSetAndPersist                               Crypto_30_LibCv_KeyValidSet
# define vHsm_Api_KeyElementsIndexType                                Crypto_30_LibCv_SizeOfKeyElementsType
# define vHsm_Api_KeyReadLockReleaseNotProtected                      Crypto_30_LibCv_Local_KeyReadLockReleaseNotProtected
# define vHsm_Api_KeyReadLockGetNotProtected                          Crypto_30_LibCv_Local_KeyReadLockGetNotProtected
# define vHsm_Api_KeyWriteLockReleaseNotProtected                     Crypto_30_LibCv_Local_KeyWriteLockReleaseNotProtected
# define vHsm_Api_KeyWriteLockGetNotProtected                         Crypto_30_LibCv_Local_KeyWriteLockGetNotProtected
# define vHsm_Api_KeyReadLockRelease                                  Crypto_30_LibCv_Local_KeyReadLockRelease
# define vHsm_Api_KeyReadLockGet                                      Crypto_30_LibCv_Local_KeyReadLockGet
# define vHsm_Api_KeyWriteLockRelease                                 Crypto_30_LibCv_Local_KeyWriteLockRelease
# define vHsm_Api_KeyWriteLockGet                                     Crypto_30_LibCv_Local_KeyWriteLockGet

# define vHsm_Api_GetKeyForSecureBootCmac                             vHsm_Core_SecureBoot_GetKeyForSecureBootCmac

# define VHSM_API_NVM_USED                                            CRYPTO_30_LIBCV_NVBLOCK
# define VHSM_API_PERSIST_SIZE                                        CRYPTO_30_LIBCV_PERSIST_SIZE
# define vHsm_Api_GetSizeOfKeyElements                                Crypto_30_LibCv_GetSizeOfKeyElements
# define vHsm_Api_WriteOfKeyElementInfoType                           Crypto_30_LibCv_WriteOfKeyElementInfoType
# define vHsm_Api_LengthCheckType                                     uint8

# define VHSM_API_RA_ALLOWED                                          CRYPTO_30_LIBCV_RA_ALLOWED
# define VHSM_API_RA_ENCRYPTED                                        CRYPTO_30_LIBCV_RA_ENCRYPTED
# define VHSM_API_RA_INTERNAL_COPY                                    CRYPTO_30_LIBCV_RA_INTERNAL_COPY
# define VHSM_API_RA_DENIED                                           CRYPTO_30_LIBCV_RA_DENIED
# define VHSM_API_WA_ALLOWED                                          CRYPTO_30_LIBCV_WA_ALLOWED
# define VHSM_API_WA_ENCRYPTED                                        CRYPTO_30_LIBCV_WA_ENCRYPTED
# define VHSM_API_WA_INTERNAL_COPY                                    CRYPTO_30_LIBCV_WA_INTERNAL_COPY
# define VHSM_API_WA_DENIED                                           CRYPTO_30_LIBCV_WA_DENIED

# define VHSM_API_LENGTH_CHECK_NONE                                   CRYPTO_30_LIBCV_LENGTH_CHECK_NONE
# define VHSM_API_LENGTH_CHECK_MAX                                    CRYPTO_30_LIBCV_LENGTH_CHECK_MAX
# define VHSM_API_LENGTH_CHECK_EQUAL                                  CRYPTO_30_LIBCV_LENGTH_CHECK_EQUAL

# define VHSM_API_KEYELEMENTSTATE_CLEAR_NORMAL_MASK                   CRYPTO_30_LIBCV_KEYELEMENTSTATE_CLEAR_NORMAL_MASK
# define VHSM_API_KEYELEMENTSTATE_SEED_INIT_MASK                      CRYPTO_30_LIBCV_KEYELEMENTSTATE_SEED_INIT_MASK
# define VHSM_API_KEYELEMENTSTATE_WRITTEN_ONCE_MASK                   CRYPTO_30_LIBCV_KEYELEMENTSTATE_WRITTEN_ONCE_MASK
# define VHSM_API_KEYELEMENTSTATE_VALUE_USED_MASK                     CRYPTO_30_LIBCV_KEYELEMENTSTATE_VALUE_USED_MASK
# define VHSM_API_KEYELEMENTSTATE_VALID_MASK                          CRYPTO_30_LIBCV_KEYELEMENTSTATE_VALID_MASK
# define VHSM_API_KEYELEMENTSTATE_VALID_INV_MASK                      CRYPTO_30_LIBCV_KEYELEMENTSTATE_VALID_INV_MASK
# define VHSM_API_KEYELEMENTSTATE_WRITTEN_ONCE_INV_MASK               CRYPTO_30_LIBCV_KEYELEMENTSTATE_WRITTEN_ONCE_INV_MASK

# define VHSM_API_SHE_SERVICE_ENCRYPT_DECRYPT                         CRYPTO_30_LIBCV_SHE_SERVICE_ENCRYPT_DECRYPT
# define VHSM_API_SHE_SERVICE_MAC_GENERATE                            CRYPTO_30_LIBCV_SHE_SERVICE_MAC_GENERATE
# define VHSM_API_SHE_SERVICE_MAC_VERIFY                              CRYPTO_30_LIBCV_SHE_SERVICE_MAC_VERIFY
# define VHSM_API_SHE_SERVICE_KEY_SERVICE                             CRYPTO_30_LIBCV_SHE_SERVICE_KEY_SERVICE
# define VHSM_API_SHE_SERVICE_OTHER                                   CRYPTO_30_LIBCV_SHE_SERVICE_OTHER

# define VHSM_API_EXTERNAL_JOB_FLAG                                   (0x10000000u)
# define VHSM_API_INTERNAL_JOB_FLAG                                   (0x20000000u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

# if (VHSM_SECURE_BOOT == STD_ON)
typedef enum
{
  VHSM_SECUREBOOTSANCTION_TAG_MISMATCH,
  VHSM_SECUREBOOTSANCTION_SECUREBOOT_ERROR,
  VHSM_SECUREBOOTSANCTION_NONE
}vHsm_SecureBootSanctionReasonType;

typedef enum
{
  VHSM_SECUREBOOTRECOVERY_TAG_MISMATCH,
  VHSM_SECUREBOOTRECOVERY_EMPTY_TAG
}vHsm_SecureBootRecoveryReasonType;

typedef enum
{
  VHSM_VERMETHOD_COMPARE_INTERNAL_TAG = 0u,
  VHSM_VERMETHOD_EXTERNAL_SL
} vHsm_Core_SecureBoot_VerMethodType;
# endif

typedef struct /* PRQA S 3630 */ /* MD_VHSM_TOOL_FALSE_POSITIVE */
{
# if (VHSM_SECURE_BOOT == STD_ON)
  vHsm_SecureBootSegmentIterType segmentIdx;
  vHsm_SecureBootSanctionReasonType sanctionReason;
  Crypto_VerifyResultType resultOverwrite;
  vHsm_Core_SecureBoot_VerMethodType verMethod;
# endif
  boolean isCyclicVerification;
  boolean retry;
  boolean recovery;
}vHsm_SecureBootInfoType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VHSM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_Api_Local_KeyElementGet()
 *********************************************************************************************************************/
/*! \brief         The key element storage index can be provided for all read access rights values.
 *  \details       This interface shall be used internal to get a key element of the key identified by the cryptoKeyId and store
 *                 the key element in the memory location pointed by the result pointer. The key element will be searched and check vor validity.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key element shall be provided.
 *  \param[in]     keyElementId            Holds the Id of the key element which shall be provided.
 *  \param[in,out] resultIndexPtr          Holds the pointer to the storage index which shall be provided.
 *  \param[in,out] resultLengthPtr         Contains the length of the key element in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_KEY_READ_FAIL  Request failed, read access was denied.
 *                 CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
 *                 CRYPTO_E_KEY_NOT_AVAILABLE  Request failed, the key is not available.
 *                 CRYPTO_E_SMALL_BUFFER       Request failed, the provided buffer is too small to store the result.
 *                 CRYPTO_E_KEY_SIZE_MISMATCH  Request failed, the provided buffer is too small to store the result.
 *  \pre           cryptoKeyId has to be a valid identifier to a key in the keyStorage.
 *                 The crypto key has to be locked for read access.
 *                 resultIndexPtr has to be a valid ptr.
 *                 resultLengthPtr has to be a valid ptr.
 *  \context       ANY
 *  \reentrant     TRUE, for different crypto keys.
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_Local_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(vHsm_Api_KeyStorageIndexType, AUTOMATIC, VHSM_APPL_VAR) resultIndexPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) resultLengthPtr);

/**********************************************************************************************************************
 *  vHsm_Api_KeyElementSet_Unchecked()
 *********************************************************************************************************************/
/*! \brief         Sets a key element and ignores write access flags.
 *  \details       Sets the given key element bytes to the key identified by cryptoKeyId.
 *                 The key element is not checked for write access flags.
 *  \param[in]     cryptoKeyId             Holds the identifier of the key whose key element shall be set.
 *  \param[in]     keyElementId            Holds the identifier of the key element which shall be set.
 *  \param[in]     keyPtr                  Holds the pointer to the key data which shall be set as key element.
 *  \param[in]     keyLength               Contains the length of the key element in bytes.
 *  \return        E_OK                    Request successful.
 *                 CRYPTO_E_KEY_NOT_AVAILABLE  Request failed, the key is not available.
 *                 CRYPTO_E_KEY_SIZE_MISMATCH  Request failed, the key element size does not match size of provided
 *                                             data.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_KeyElementSet_Unchecked(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) keyPtr,
  uint32 keyLength);

/**********************************************************************************************************************
 *  vHsm_Api_InitializeTempJob()
 *********************************************************************************************************************/
/*!
 *
 * \brief       Generate a temporary job
 * \details     The job can be modified to e.g. perform a AES calculation.
 * \param[in]   tmpJob         Pointer to the job which shall be initialized
 * \param[in]   cryptoKeyId    Key which shall be used in the job
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
FUNC(void, VHSM_CODE) vHsm_Api_InitializeTempJob(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  uint32 cryptoKeyId);

/**********************************************************************************************************************
 *  vHsm_Api_ProcessTempJob()
 *********************************************************************************************************************/
/*!
 *
 * \brief       Executes a job
 * \details     The function checks which driver CryIf channel will be used to execute the job.
 * \param[in]   cryIfChannelId   CryIf channel which shall  be used
 * \param[in]   tmpJob           Pointer to the job which shall be executed
 * \return      Result of the job execution
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_ProcessTempJob(
  uint32 cryIfChannelId,
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob);

/**********************************************************************************************************************
 *  vHsm_Api_CancelTempJob()
 *********************************************************************************************************************/
/*!
 *
 * \brief       Cancels a job
 * \details     The function checks which driver CryIf channel will be used to cancel the job.
 * \param[in]   cryIfChannelId   CryIf channel which shall  be used
 * \param[in]   tmpJob           Pointer to the job which shall be cancelled
 * \return      Result of the job cancellation
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_CancelTempJob(
  uint32 cryIfChannelId,
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob);

/**********************************************************************************************************************
 *  vHsm_Api_KeyElementGetForCryptoJobs()
 **********************************************************************************************************************/
/*! \brief       Get a key element from the key storage for a job
 *  \details     This function gets a key element and returns a return code suitable for job processing functions.
 *  \param[in]      cryptoKeyId      key id which shall be searched for the key element
 *  \param[in]      keyElementId     Id of the element
 *  \param[out]     resultIndexPtr   Pointer to the index variable
 *  \param[in]      resultLength  Length of the element which shall be retrieved
 *  \param[in]      serviceType             SHE service Type.
 *  \return      E_OK if request was successful
 *               CRYPTO_E_KEY_NOT_VALID if the key element was invalid
 *               CRYPTO_E_KEY_SIZE_MISMATCH if the size of the key element was not as requested
 *               E_NOT_OK in all other cases
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_KeyElementGetForCryptoJobs(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(vHsm_Api_KeyStorageIndexType, AUTOMATIC, VHSM_APPL_VAR) resultIndexPtr,
  uint32 resultLength,
  uint8 serviceType);

/**********************************************************************************************************************
 *  vHsm_Api_SetKeyElementValidAndPersist()
 **********************************************************************************************************************/
/*! \brief       Set a key element to valid and persist the key if requested
 *  \details     -
 *  \param[in]      cryptoKeyId      key id which shall be searched for the key element
 *  \param[in]      keyElementId     Id of the element
 *  \param[in]      persist          Persist the key after setting it to valid
 *  \return      E_OK if request was successful
 *               CRYPTO_E_KEY_NOT_AVAILABLE if the key element was not available
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_SetKeyElementValidAndPersist(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  boolean persist);

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetService()
 *********************************************************************************************************************/
/*! \brief         Write service to job pointer
 *  \details       -
 *  \param[in]     tmpJob         Pointer to a temporary job
 *  \param[in]     service        Value which shall be written
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
LOCAL_INLINE void vHsm_Api_TempJob_SetService(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  Crypto_ServiceInfoType service);

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetFamily()
 *********************************************************************************************************************/
/*! \brief         Write family to job pointer
 *  \details       -
 *  \param[in]     tmpJob        Pointer to a temporary job
 *  \param[in]     family        Value which shall be written
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
LOCAL_INLINE void vHsm_Api_TempJob_SetFamily(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  Crypto_AlgorithmFamilyType family);

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetSecondaryFamily()
 *********************************************************************************************************************/
/*! \brief         Write secondary family to job pointer
 *  \details       -
 *  \param[in]     tmpJob            Pointer to a temporary job
 *  \param[in]     secondaryfamily   Value which shall be written
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
LOCAL_INLINE void vHsm_Api_TempJob_SetSecondaryFamily(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  Crypto_AlgorithmSecondaryFamilyType secondaryFamily);

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetMode()
 *********************************************************************************************************************/
/*! \brief         Write mode to job pointer
 *  \details       -
 *  \param[in]     tmpJob         Pointer to a temporary job
 *  \param[in]     mode           Value which shall be written
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
LOCAL_INLINE void vHsm_Api_TempJob_SetMode(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  Crypto_AlgorithmModeType mode);

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetKeyLength()
 *********************************************************************************************************************/
/*! \brief         Write keyLength to job pointer
 *  \details       -
 *  \param[in]     tmpJob         Pointer to a temporary job
 *  \param[in]     keyLength      Value which shall be written
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
LOCAL_INLINE void vHsm_Api_TempJob_SetKeyLength(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  uint32 keyLength);

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetPrimitive()
 *********************************************************************************************************************/
/*! \brief         Write primitive information to job pointer
 *  \details       -
 *  \param[in]     tmpJob            Pointer to a temporary job
 *  \param[in]     service           Service value which shall be written
 *  \param[in]     family            Family value which shall be written
 *  \param[in]     mode              Mode value which shall be written
 *  \param[in]     secondaryfamily   Secondary Family value which shall be written
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
LOCAL_INLINE void vHsm_Api_TempJob_SetPrimitive(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  Crypto_ServiceInfoType service,
  Crypto_AlgorithmFamilyType family,
  Crypto_AlgorithmModeType mode,
  Crypto_AlgorithmSecondaryFamilyType secondaryFamily);

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetProcessing()
 *********************************************************************************************************************/
/*! \brief         Write processing to job pointer
 *  \details       -
 *  \param[in]     tmpJob            Pointer to a temporary job
 *  \param[in]     processing        Value which shall be written
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
LOCAL_INLINE void vHsm_Api_TempJob_SetProcessing(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  Crypto_ProcessingType processing);

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetJobId()
 *********************************************************************************************************************/
/*! \brief         Write jobId to job pointer
 *  \details       -
 *  \param[in]     tmpJob         Pointer to a temporary job
 *  \param[in]     jobId          Value which shall be written
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
LOCAL_INLINE void vHsm_Api_TempJob_SetJobId(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  uint32 jobId);

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetCryptoKeyId()
 *********************************************************************************************************************/
/*! \brief         Write crypto key id to job pointer
 *  \details       -
 *  \param[in]     tmpJob         Pointer to a temporary job
 *  \param[in]     cryptoKeyId    Value which shall be written
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
LOCAL_INLINE void vHsm_Api_TempJob_SetCryptoKeyId(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  uint32 cryptoKeyId);

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetCryIfKeyId()
 *********************************************************************************************************************/
/*! \brief         Write crypto interface key id to job pointer
 *  \details       -
 *  \param[in]     tmpJob         Pointer to a temporary job
 *  \param[in]     cryIfKeyId     Value which shall be written
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
LOCAL_INLINE void vHsm_Api_TempJob_SetCryIfKeyId(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  uint32 cryIfKeyId);

/**********************************************************************************************************************
 *  vHsm_Api_DisallowKeyUsage()
 *********************************************************************************************************************/
/*! \brief         Disallow crypto interface key usage
 *  \details       -
 *  \param[in]     cryIfKeyId     Id of key which usage shall be disallowed
 *  \return        E_OK           Request successful.
 *                 E_NOT_OK       Invalid cryIfKeyId was passed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_DisallowKeyUsage(uint32 cryIfKeyId);

/**********************************************************************************************************************
 *  vHsm_Api_AllowKeyUsage()
 *********************************************************************************************************************/
/*! \brief         Allow crypto interface key usage
 *  \details       -
 *  \param[in]     cryIfKeyId     Id  of key which usage shall be allowed
 *  \return        E_OK           Request successful.
 *                 E_NOT_OK       Invalid cryIfKeyId was passed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_AllowKeyUsage(uint32 cryIfKeyId);

/**********************************************************************************************************************
 *  vHsm_Api_Ramloop_PrepareExecution()
 *********************************************************************************************************************/
/*! \brief         Prepares vHsm to enter ram loop.
 *  \details       Ram loop is entered in next cycle of the main function.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Api_Ramloop_PrepareExecution(void);

/**********************************************************************************************************************
 *  vHsm_Api_Ramloop_Exit()
 *********************************************************************************************************************/
/*! \brief         Removes vHsm from ram loop.
 *  \details       Ram loop is exited and vHsm runs back in code flash.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Api_Ramloop_Exit(void);

# if (VHSM_SECURE_BOOT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Api_SecureBoot_ResetTag()
 *********************************************************************************************************************/
/*! \brief         Resets a group tag information.
 *  \details       The calculated tag of all contained segments will be resetted.
 *  \param[in]     groupIdx     group to reset
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_SecureBoot_ResetTag(vHsm_SecureBootGroupIterType groupIdx);
# endif

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetService()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE void vHsm_Api_TempJob_SetService( /* PRQA S 3219 */ /* MD_VHSM_3219_INLINE_FUNCT */
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  Crypto_ServiceInfoType service)
{
  vHsm_Api_TempJob_WriteToJobField( /* PRQA S 0311 */ /* MD_VHSM_0311_CSM_JOB_AS_VAR */
    Crypto_ServiceInfoType,
    tmpJob->primitiveInfo.service,
    service);
}

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetFamily()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE void vHsm_Api_TempJob_SetFamily( /* PRQA S 3219 */ /* MD_VHSM_3219_INLINE_FUNCT */
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  Crypto_AlgorithmFamilyType family)
{
  vHsm_Api_TempJob_WriteToJobField( /* PRQA S 0311 */ /* MD_VHSM_0311_CSM_JOB_AS_VAR */
    Crypto_AlgorithmFamilyType,
    tmpJob->primitiveInfo.algorithm.family,
    family);
}

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetSecondaryFamily()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE void vHsm_Api_TempJob_SetSecondaryFamily( /* PRQA S 3219 */ /* MD_VHSM_3219_INLINE_FUNCT */
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  Crypto_AlgorithmSecondaryFamilyType secondaryFamily)
{
  vHsm_Api_TempJob_WriteToJobField( /* PRQA S 0311 */ /* MD_VHSM_0311_CSM_JOB_AS_VAR */
    Crypto_AlgorithmSecondaryFamilyType,
    tmpJob->primitiveInfo.algorithm.secondaryFamily,
    secondaryFamily);
}

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetMode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE void vHsm_Api_TempJob_SetMode( /* PRQA S 3219 */ /* MD_VHSM_3219_INLINE_FUNCT */
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  Crypto_AlgorithmModeType mode)
{
  vHsm_Api_TempJob_WriteToJobField( /* PRQA S 0311 */ /* MD_VHSM_0311_CSM_JOB_AS_VAR */
    Crypto_AlgorithmModeType,
    tmpJob->primitiveInfo.algorithm.mode,
    mode);
}

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetKeyLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE void vHsm_Api_TempJob_SetKeyLength( /* PRQA S 3219 */ /* MD_VHSM_3219_INLINE_FUNCT */
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  uint32 keyLength)
{
  vHsm_Api_TempJob_WriteToJobField( /* PRQA S 0311 */ /* MD_VHSM_0311_CSM_JOB_AS_VAR */
    uint32,
    tmpJob->primitiveInfo.algorithm.keyLength,
    keyLength);
}

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetPrimitive()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
LOCAL_INLINE void vHsm_Api_TempJob_SetPrimitive( /* PRQA S 3219 */ /* MD_VHSM_3219_INLINE_FUNCT */
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  Crypto_ServiceInfoType service,
  Crypto_AlgorithmFamilyType family,
  Crypto_AlgorithmModeType mode,
  Crypto_AlgorithmSecondaryFamilyType secondaryFamily)
{
  /* #10 Write algorithm service */
  vHsm_Api_TempJob_SetService(tmpJob, service);

  /* #20 Write algorithm algorithm */
  vHsm_Api_TempJob_SetFamily(tmpJob, family);

  /* #30 Write algorithm mode */
  vHsm_Api_TempJob_SetMode(tmpJob, mode);

  /* #40 Write algorithm secondary algorithm */
  vHsm_Api_TempJob_SetSecondaryFamily(tmpJob, secondaryFamily);
}

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetProcessing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE void vHsm_Api_TempJob_SetProcessing( /* PRQA S 3219 */ /* MD_VHSM_3219_INLINE_FUNCT */
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  Crypto_ProcessingType processing)
{
  vHsm_Api_TempJob_WriteToJobField( /* PRQA S 0311 */ /* MD_VHSM_0311_CSM_JOB_AS_VAR */
    Crypto_ProcessingType,
    tmpJob->jobPrimitiveInfo.processingType, processing);
}

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetJobId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE void vHsm_Api_TempJob_SetJobId( /* PRQA S 3219 */ /* MD_VHSM_3219_INLINE_FUNCT */
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  uint32 jobId)
{
  vHsm_Api_TempJob_WriteToJobField( /* PRQA S 0311 */ /* MD_VHSM_0311_CSM_JOB_AS_VAR */
    uint32,
    tmpJob->jobInfo.jobId,
    jobId);
}

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetCryptoKeyId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE void vHsm_Api_TempJob_SetCryptoKeyId( /* PRQA S 3219 */ /* MD_VHSM_3219_INLINE_FUNCT */
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  uint32 cryptoKeyId)
{
  tmpJob->job.cryptoKeyId = cryptoKeyId;
}

/**********************************************************************************************************************
 *  vHsm_Api_TempJob_SetCryIfKeyId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE void vHsm_Api_TempJob_SetCryIfKeyId( /* PRQA S 3219 */ /* MD_VHSM_3219_INLINE_FUNCT */
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  uint32 cryIfKeyId)
{
  vHsm_Api_TempJob_WriteToJobField( /* PRQA S 0311 */ /* MD_VHSM_0311_CSM_JOB_AS_VAR */
    uint32,
    tmpJob->jobPrimitiveInfo.cryIfKeyId,
    cryIfKeyId);
}

# if (VHSM_NVM_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Api_NvM_WriteBlock()
 *********************************************************************************************************************/
/*! \brief       Setups a write job for given NvM block and processes it directly afterwards (synchronous).
 *  \details     Request to copy the data of the RAM block to its corresponding NV block. If the block to be written is
 *               permanent a NULL_PTR shall be given as parameter, otherwise a pointer to the ram block shall be given.
 *  \param[in]   BlockId in range [1, (number of blocks - 1)].
 *  \param[in]   NvM_SrcPtr as a pointer to the RAM buffer NvM shall write. The length of the buffer depends on passed
 *               BlockId (block configuration). May be NULL_PTR for specific blocks.
 *  \return      E_OK job was setup and processed
 *  \return      E_NOT_OK otherwise
 *  \pre -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_NvM_WriteBlock(
  NvM_BlockIdType BlockId,
  P2CONST(void, AUTOMATIC, VHSM_APPL_VAR) NvM_SrcPtr);
# endif

/**********************************************************************************************************************
 *  vHsm_Api_DeactivateChannel()
 *********************************************************************************************************************/
/*! \brief         Prevents a channel from being used outside of the vHsm.
 *  \details       Only channels referenced in the IPC configuration can be used.
 *  \param[in]     channelId      Id of the channel to deactivate.
 *  \return        E_OK           Request successful.
 *                 E_NOT_OK       Invalid objectId was passed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_DeactivateChannel(uint32 channelId);

/**********************************************************************************************************************
 *  vHsm_Api_ActivateChannel()
 *********************************************************************************************************************/
/*! \brief         Enables a channel to be used outside of the vHsm.
 *  \details       Only channels referenced in the IPC configuration can be used.
 *  \param[in]     channelId      Id of the channel to activate.
 *  \return        E_OK           Request successful.
 *                 E_NOT_OK       Invalid objectId was passed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_ActivateChannel(uint32 channelId);

# define VHSM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSM_API_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Api.h
 *********************************************************************************************************************/
