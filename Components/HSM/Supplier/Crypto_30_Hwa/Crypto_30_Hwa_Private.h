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
/*!        \file  Crypto_30_Hwa_Private.h
 *        \brief  vHsm platform hardware abstraction library
 *
 *      \details  This header declares the internal interfaces for HWA services
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (CRYPTO_30_HWA_PRIVATE_H)
# define CRYPTO_30_HWA_PRIVATE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Crypto_30_Hwa_Public.h"
#include "Crypto_30_Hwa_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

 /* Custom Return Types */
# ifndef CRYPTO_E_NOT_HANDLED /* COV_CRYPTO_30_HWA_CSM_DEFINES */
#  define CRYPTO_E_NOT_HANDLED                             (3u)
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

 /* Check job mode macro */
#define Crypto_30_Hwa_IsJobMode(Job, Mask) ((((Job)->jobPrimitiveInputOutput.mode) & (Mask)) == (Mask)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

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

#if (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
#if (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_TrngPrefetch()
 *********************************************************************************************************************/
/*! \brief          Function for prefetching random numbers.
 *  \details        Random numbers are generated with the TRNG module and stored in an local buffer
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TrngPrefetch(void);
#endif /* (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_OFF) */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_InitTrngPrefetching()
 *********************************************************************************************************************/
/*! \brief          Initialization for Trng prefetching
 *  \details        Initialize the ring buffer and start random number generation
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_InitTrngPrefetching(void);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_TrngProcessDataReady()
 *********************************************************************************************************************/
/*! \brief         Process valid data from trng module.
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TrngProcessDataReady(void);
#endif /* (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) */

#if ((CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_GCMSIV == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_MacCompare()
 *********************************************************************************************************************/
/*! \brief          Compares two MACs and returns if they are equal.
 *  \details        Compares "lengthInBit" bits of two CMACs and tells if they are the same.
 *  \param[in]      mac1                MAC 1.
 *  \param[in]      mac2                MAC 2.
 *  \param[in]      lengthInBit         Length in bits to compares.
 *  \return         CRYPTO_E_VER_OK     Verification OK.
 *                  CRYPTO_E_VER_NOT_OK Verification not OK.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Crypto_VerifyResultType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_MacCompare(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) mac1,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) mac2,
  uint32 lengthInBit);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_GCMSIV == STD_ON)) */

# if (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessAesJob()
 *********************************************************************************************************************/
/*! \brief         Process AES job
 *  \details       -
 *  \param[in]     objectId            Object ID
 *  \param[out]    errorIdPtr          Error ID
 *  \param[in,out] job                 Job
 *  \param[in,out] workspace           Workspace to use for AES operation
 *  \return        E_OK                No error detected
 *                 E_NOT_OK            Error detected
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE on different driver objects
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessAesJob(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace);
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) */

# if (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessAeadJobAesGcm()
 *********************************************************************************************************************/
/*! \brief         Process AES job
 *  \details       -
 *  \param[in]     objectId            Object ID
 *  \param[out]    errorIdPtr          Error ID
 *  \param[in,out] job                 Job
 *  \param[in,out] workspace           Workspace to use for AES operation
 *  \return        E_OK                No error detected
 *                 E_NOT_OK            Error detected
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE on different driver objects
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessAeadJobAesGcm(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace);
# endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON) */

# if (CRYPTO_30_HWA_PRIMITIVE_AES_GCMSIV == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessAeadJobAesGcmSiv()
 *********************************************************************************************************************/
/*! \brief         Process AES job
 *  \details       -
 *  \param[in]     objectId            Object ID
 *  \param[out]    errorIdPtr          Error ID
 *  \param[in,out] job                 Job
 *  \param[in,out] workspace           Workspace to use for AES operation
 *  \return        E_OK                No error detected
 *                 E_NOT_OK            Error detected
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE on different driver objects
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessAeadJobAesGcmSiv(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  Crypto_30_Hwa_WorkSpaceGCMSIV_PtrType workspace);
# endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_GCMSIV == STD_ON) */

# if (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessCmacJob()
 *********************************************************************************************************************/
/*! \brief         Process CMAC job
 *  \details       -
 *  \param[in]     objectId            Object ID
 *  \param[out]    errorIdPtr          Error ID
 *  \param[in,out] job                 Job
 *  \param[in]     verifyMac           TRUE to verify MAC. FALSE to generate MAC.
 *  \param[in,out] workspace           Workspace to use for AES operation
 *  \return        E_OK                No error detected
 *                 E_NOT_OK            Error detected
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE on different driver objects
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessCmacJob(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  boolean verifyMac,
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace);
# endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) */

# if (CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Sha256Start()
 *********************************************************************************************************************/
/*! \brief          Initializes the SHA256 generation.
 *  \details        -
 *  \param[in,out]  workspace          SHA256 Workspace.
 *  \return         E_OK               Initialization was successful.
 *                  E_NOT_OK           Initialization failed.
 *  \pre            SHA256 module enabled.
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Sha256Start(
  Crypto_30_Hwa_WorkSpaceSHA256_PtrType workspace);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Sha256Update()
 *********************************************************************************************************************/
/*! \brief          Performs SHA256 operation on input data and writes to output buffer.
 *  \details        -
 *  \param[in,out]  workspace          SHA256 Workspace.
 *  \param[in]      inputPtr           Input buffer.
 *  \param[in]      inputLength        Input buffer length.
 *  \return         E_OK               Update was successful.
 *                  E_NOT_OK           Update failed.
 *  \pre            Crypto_30_Hwa_Sha256Start() called before first update.
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Sha256Update(
  Crypto_30_Hwa_WorkSpaceSHA256_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Sha256Finish()
 *********************************************************************************************************************/
/*! \brief          Finish SHA256 generation.
 *  \details        -
 *  \param[in,out]  workspace          SHA256 Workspace.
 *  \param[out]     hashsum            Hash destination.
 *  \param[in,out]  hashsumLength      Hash destination length.
 *  \return         E_OK               Finish was successful.
 *                  E_NOT_OK           Finish failed.
 *  \pre            Crypto_30_Hwa_Sha256Update() called before.
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Sha256Finish(
  Crypto_30_Hwa_WorkSpaceSHA256_PtrType workspace,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) hashsum,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) hashsumLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessSha256Job()
 *********************************************************************************************************************/
/*! \brief         Process SHA256 job
 *  \details       -
 *  \param[in]     objectId            Object ID
 *  \param[out]    errorIdPtr          Error ID
 *  \param[in,out] job                 Job
 *  \return        E_OK                No error detected
 *                 E_NOT_OK            Error detected
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE on different driver objects
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessSha256Job(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job);
# endif /* (CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_ON) */

# if (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessTrngJob()
 *********************************************************************************************************************/
/*! \brief         Process TRNG job
 *  \details       -
 *  \param[out]    errorIdPtr          Error ID
 *  \param[in,out] job                 Job
 *  \return        E_OK                No error detected
 *                 E_NOT_OK            Error detected
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE on different driver objects
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessTrngJob(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job);
# endif /* (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) */

# if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON)  && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessEcdsaSignatureVerifyJob()
 *********************************************************************************************************************/
/*! \brief         Process ECDSA signature verify job
 *  \details       -
 *  \param[in]     objectId            Object ID
 *  \param[out]    errorIdPtr          Error ID
 *  \param[in,out] job                 Job
 *  \param[in]     workspace           Workspace
 *  \return        E_OK                No error detected
 *                 E_NOT_OK            Error detected
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessEcdsaSignatureVerifyJob(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace);
# endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON)  && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) */

# if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON)  && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessEcdsaSignatureGenerateJob()
 *********************************************************************************************************************/
/*! \brief         Process ECDSA signature generate job
 *  \details       -
 *  \param[in]     objectId            Object ID
 *  \param[out]    errorIdPtr          Error ID
 *  \param[in,out] job                 Job
 *  \param[in]     workspace           Workspace
 *  \return        E_OK                No error detected
 *                 E_NOT_OK            Error detected
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessEcdsaSignatureGenerateJob(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace);
# endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON)  && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

# if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessEddsaSignatureVerifyJob()
 *********************************************************************************************************************/
/*! \brief         Process EDDSA signature verify job
 *  \details       -
 *  \param[in]     objectId            Object ID
 *  \param[out]    errorIdPtr          Error ID
 *  \param[in,out] job                 Job
 *  \param[in]     workspace           Workspace
 *  \return        E_OK                No error detected
 *                 E_NOT_OK            Error detected
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessEddsaSignatureVerifyJob(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace);
# endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) */

# if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessEddsaSignatureGenerateJob()
 *********************************************************************************************************************/
/*! \brief         Process EDDSA signature generate job
 *  \details       -
 *  \param[in]     objectId            Object ID
 *  \param[out]    errorIdPtr          Error ID
 *  \param[in,out] job                 Job
 *  \param[in]     workspace           Workspace
 *  \return        E_OK                No error detected
 *                 E_NOT_OK            Error detected
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessEddsaSignatureGenerateJob(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CheckAggregatedKeyId()
 *********************************************************************************************************************/
/*! \brief         Checks if the given key has an aggregated key set
 *  \details       Checks if the given key is a ROM_KEY and has an aggregated key
 *  \param[in,out] cryptoKeyIdPtr          Holds the identifier of the key which is checked and returns the keyID of
 *                                         the aggregated key.
 *  \return        E_OK                    Given key is either LibCV-Key or ROM_KEY and has an aggregated key set.
 *                 E_NOT_OK                Given key is ROM_KEY and has no aggregated key set.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckAggregatedKeyId(P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) cryptoKeyIdPtr);

#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_CheckRomKeyUsage()
 *********************************************************************************************************************/
/*! \brief          Checks if provided key id is a ROM_KEY.
 *  \details        If the given key id is a ROM_KEY, the corresponding ROM_KEY in the hardware is used.
 *                  If the given key id is not a ROM_KEY, the key is treated as LibCv-key.
 *  \param[in]      keyID           ID ouf provided key.
 *  \param[out]     romKeyMapIndex  Index of ROM_KEY or indicator of LibCv-Key.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckRomKeyUsage(
  uint32 keyID,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) romKeyMapIndex);
#endif /* (CRYPTO_30_HWA_ROMKEY == STD_ON) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_IsBignumZeroBe()
 *********************************************************************************************************************/
/*! \brief        Compares a big endian bignum against zero
 *  \details      Returns whether the bignum is equal to zero or not. It is expected that the numbers is in big endian
 *                format.
 *  \param[in]    a       Bignum
 *  \param[in]    length  Length of the bignum
 *  \return               true - Bignum is equal to zero
 *                        false - Bignum is not equal to zero
 *  \pre          a, must be valid pointer
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(boolean, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_IsBignumZeroBe(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) a,
  const uint32 length);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */

#if (CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_CompareBignumsBe()
 *********************************************************************************************************************/
/*! \brief        Compares two big endian bignums with each other.
 *  \details      Returns whether both numbers are equal or one number is bigger than the other. It is expected that
 *                both numbers are in big endian format.
 *  \param[in]    a       Bignum one
 *  \param[in]    b       Bignum two
 *  \param[in]    length  Length of both bignums
 *  \return               uint8 0x10u - Bignum a is smaller than bignum b
 *                        uint8 0x11u - Bignum a is greater than bignum b
 *                        uint8 0x12u - Both bignums are equal
 *  \pre          a, b must be valid pointers
 *                a, b must be at least of size length
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CompareBignumsBe(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) a,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) b,
  const uint32 length);
#endif /* (CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) */

#if (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessDom2Data()
 *********************************************************************************************************************/
/*! \brief        Processes the dom2 part during the hashing phase of the Ed25519 signature verification.
 *  \details      -
 *  \param[in]    job            Job pointer.
 *  \param[in]    workspace      Workspace of the current job.
 *  \param[in]    context        Buffer for the context data.
 *  \param[in]    contextLength  Length of the context data.
 *  \return       E_OK           Processing Dom2 and context was successfull.
 *                E_NOT_OK       Processing Dom2 and context was not successfull.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessDom2Data(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) context,
  uint32 contextLength);
#endif /* (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) */

#if (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_TrngFinish()
 *********************************************************************************************************************/
/*! \brief          Finalize random number generation.
 *  \details        Uses the TRNG-prefetch buffer to fetch random data (if configured) or directly calls hardware function.
 *  \param[in,out]  dstPtr             Output buffer.
 *  \param[in,out]  LengthPtr          Output buffer length.
 *  \return         E_OK               Random number generation was successful.
 *                  E_NOT_OK           Random number generation failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TrngFinish(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) dstPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) LengthPtr);
#endif /* (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_ArrayToUint32()
 *********************************************************************************************************************/
/*! \brief        Converts 4 byte from input data to Uint32.
 *  \details      -
 *  \param[in]    source       Input data
 *  \return                    Uint32 data
 *  \pre          -
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(uint32, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ArrayToUint32(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) source);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Uint32ToArray()
 *********************************************************************************************************************/
/*! \brief        Convert Uint32 to byte array.
 *  \details      -
 *  \param[in]    source          32 bit word
 *  \param[out]   destination     byte array
 *  \pre          -
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Uint32ToArray(
  uint32 source,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) destination);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_UpdateJobState()
 *********************************************************************************************************************/
/*! \brief          Updates the state of the job according to a return type.
 *  \details        -
 *  \param[in]      retVal             Return value
 *  \param[in,out]  job                The job whose state shall be updated
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_UpdateJobState(
  Std_ReturnType retVal,
  Crypto_30_Hwa_JobPtrType job);

# define CRYPTO_30_HWA_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* CRYPTO_30_HWA_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Private.h
 *********************************************************************************************************************/
