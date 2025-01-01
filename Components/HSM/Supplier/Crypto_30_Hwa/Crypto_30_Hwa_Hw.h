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
/*!        \file  Crypto_30_Hwa_Hw.h
 *        \brief  vHsm platform hardware abstractions
 *
 *      \details  This declares the hardware access functions which are used by the platform code. All functions must
 *                be defined by the platform specific hardware abstraction. If a function is not required the function
 *                can be left empty.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (CRYPTO_30_HWA_HW_H)
# define CRYPTO_30_HWA_HW_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Crypto_30_Hwa.h"
# include "Crypto_30_Hwa_Cfg.h"
# include "Crypto_30_Hwa_Private.h"

# include "Os.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

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
 *  Crypto_30_Hwa_Hw_InitMemory()
 *********************************************************************************************************************/
/*! \brief          Function for *_INIT_*-variable initialization.
 *  \details        Service to initialize module global variables at power up. This function initializes the
 *                  variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \pre            Module is uninitialized.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_InitMemory(void);

/**********************************************************************************************************************
 * Crypto_30_Hwa_Hw_Init()
 *********************************************************************************************************************/
/*! \brief          Initialization function.
 *  \details        This function initializes the module Crypto_30_Hwa_Hw. It initializes all variables and sets the
 *                  module state to initialized.
 *  \pre            Crypto_30_Hwa_Hw_InitMemory has been called before.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Init(void);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_MainFunction()
 *********************************************************************************************************************/
/*! \brief          vHsm hardware abstractions main function.
 *  \details        -
 *  \pre            -
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_MainFunction(void);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CancelJob()
 *********************************************************************************************************************/
/*! \brief          Cancel Job callout for hardware depended job cancelation.
 *  \details        -
 *  \param[in]      objectId              Object ID
 *  \param[in]      job                   Job object
 *  \pre            -
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CancelJob(
  uint32 objectId,
  Crypto_30_Hwa_JobPtrType job);

#if (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_MemRand()
 *********************************************************************************************************************/
/*! \brief          Generate random number.
 *  \details        Uses the TRNG of the hardware to produce random bytes
 *  \param[out]     dstPtr              Output buffer
 *  \param[in]      length              Amount of random bytes to generate
 *  \return         E_OK                No error detected
 *                  E_NOT_OK            Error detected or random not available
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_MemRand(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) dstPtr, uint32 length);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngRestart()
 *********************************************************************************************************************/
/*! \brief          Restarts the TRNG.
 *  \details        Restart the TRNG and clear error flags.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_TrngRestart(void);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngDisableGenerator()
 *********************************************************************************************************************/
/*! \brief          Disable TRNG.
 *  \details        TRNG needs to be shut down, if not needed any more.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_TrngDisableGenerator(void);
#endif /* (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) */

#if (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON)

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngGetData()
 *********************************************************************************************************************/
/*! \brief          Get random data from the TRNG.
 *  \details        Get random word from TRNG module.
 *  \param[in,out]  dstPtr              Where the random number should be copied to.
 *  \param[in,out]  lengthPtr           Number of random bytes to copy, number of random bytes written.
 *  \return         E_OK                Random number available.
 *                  E_NOT_OK            Error detected or random not available
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_TrngGetData(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) dstPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) lengthPtr);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_IsTrngOn()
 **********************************************************************************************************************/
/*! \brief          Get status if TRNG module is on.
 *  \details        -
 *  \pre            -
 *  \return         TRUE                   Trng module is on.
 *                  FALSE                  Trng module is off.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_IsTrngOn(void);

#if (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngEnableIrq()
 **********************************************************************************************************************/
/*! \brief          Enable TRNG interrupt.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_TrngEnableIrq(void);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngDisableIrq()
 **********************************************************************************************************************/
/*! \brief          Disable TRNG interrupt.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_TrngDisableIrq(void);
#endif /* (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_ON) */

#endif /* (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_KeyElementGet()
 *********************************************************************************************************************/
/*! \brief          This interface shall be used to filter calls to KeyElementGet for custom key elements.
 *  \details        -
 *  \param[in]      cryptoKeyId                 Holds the identifier of the key whose key element shall be set.
 *  \param[in]      keyElementId                Holds the identifier of the key element which shall be set.
 *  \param[out]     resultPtr                   Holds the pointer to the key data which shall be set as key element.
 *  \param[in,out]  resultLengthPtr             Contains the length of the key element in bytes.
 *  \return         E_OK                        Request filtered.
 *                  E_NOT_OK                    Request not filtered.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE, for different cryptoKeyId
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) resultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) resultLengthPtr);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_KeyElementSet()
 *********************************************************************************************************************/
/*! \brief          This interface shall be used to filter calls to KeyElementSet for custom key elements.
 *  \details        -
 *  \param[in]      cryptoKeyId                 Holds the identifier of the key whose key element shall be set.
 *  \param[in]      keyElementId                Holds the identifier of the key element which shall be set.
 *  \param[in]      keyPtr                      Holds the pointer to the key data which shall be set as key element.
 *  \param[in]      keyLength                   Contains the length of the key element in bytes.
 *  \return         E_OK                        Request filtered.
 *                  E_NOT_OK                    Request not filtered.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE, for different cryptoKeyId
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_KeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) keyPtr,
  uint32 keyLength);

# if (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesProcessBlocks()
 *********************************************************************************************************************/
/*! \brief          Process multiple (one or more) AES blocks.
 *  \details        -
 *  \param[in,out]  workspace          AES workspace.
 *  \param[in]      in                 Pointer to input data with (blockCount * CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES) bytes.
 *  \param[in]      blockCount         Number of complete blocks that should be processed. Must be at least 1.
 *  \param[out]     out                Pointer to output data with (blockCount * CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES) bytes.
 *  \return         E_OK               Processing was successful.
 *                  E_NOT_OK           Processing failed.
 *  \pre            -
 *  \note           This function may be implemented similar to Crypto_30_Hwa_Hw_CmacProcessBlock().
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesProcessBlocks(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in,
  uint32 blockCount,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesStart()
 *********************************************************************************************************************/
/*! \brief          Start the AES calculation with supplied key and IV.
 *  \details        -
 *  \param[in,out]  workspace          AES Workspace.
 *  \param[in]      key                Pointer to key with size CRYPTO_30_HWA_AES_KEY_SIZE.
 *  \param[in]      iv                 Pointer to IV.
 *  \param[in]      ivLength           Length of IV, this must be CRYPTO_30_HWA_AES_KEY_SIZE or 0 if no IV is used.
 *  \param[in]      mode               Algorithm mode
 *  \param[in]      service            Service type (encrypt/decrypt).
 *                                     Differs only from workspace mode if CTR shall be calculated but hardware has
 *                                     no support for this
 *  \return         E_OK               Starting AES was successful.
 *                  E_NOT_OK           Starting AES failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesStart(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) iv,
  uint8 ivLength,
  Crypto_AlgorithmModeType mode,
  Crypto_ServiceInfoType service);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesFinish()
 *********************************************************************************************************************/
/*! \brief          Finish the AES calculation.
 *  \details        -
 *  \param[in,out]  workspace          AES workspace.
 *  \return         E_OK               Finishing CMAC was successful.
 *                  E_NOT_OK           Finishing CMAC failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesFinish(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace);
# endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) */

# if (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
#  if (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CmacSubkeys()
 **********************************************************************************************************************/
/*! \brief          Just do one AES calculation for the CMAC subkeys.
 *  \details        For this, the supplied key shall be used and workspace->k1 shall be used as input and output
 *                  of AES operation. It is ensured that k1 is cleared before calling this function.
 *  \param[in,out]  workspace          CMACAES Workspace.
 *  \param[in]      key                Pointer to key with length CRYPTO_30_HWA_AES_KEY_SIZE which shall be used.
 *  \return         E_OK               Calculating AES was successful.
 *                  E_NOT_OK           Calculating AES failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CmacSubkeys(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key);
#  endif /* (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CmacProcessBlocks()
 *********************************************************************************************************************/
/*! \brief          Process multiple (one or more) CMACAES blocks.
 *  \details        -
 *  \param[in,out]  workspace          CMACAES workspace.
 *  \param[in]      in                 Pointer to input data with (blockCount * CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES) bytes.
 *  \param[in]      blockCount         Number of complete blocks that should be processed. Must be at least 1.
 *  \return         E_OK               Processing was successful.
 *                  E_NOT_OK           Processing failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CmacProcessBlocks(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in,
  uint32 blockCount);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CmacStart()
 *********************************************************************************************************************/
/*! \brief          Start the CMACAES calculation with supplied key.
 *  \details        -
 *  \param[in,out]  workspace          CMACAES Workspace.
 *  \param[in]      key                Pointer to key with size CRYPTO_30_HWA_AES_KEY_SIZE.
 *  \return         E_OK               Starting CMAC was successful.
 *                  E_NOT_OK           Starting CMAC failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CmacStart(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CmacFinish()
 *********************************************************************************************************************/
/*! \brief          Finish calculation and disable the CMACAES module.
 *  \details        This function processed remaining data if CRYPTO_30_HWA_HARDWARE_CMAC is STD_ON.
 *                  Use the data in workspace->remainingDataPtr and workspace->bufferFillLevel as input data.
 *                  The data shall not be changed/written.
 *                  If CRYPTO_30_HWA_HARDWARE_CMAC is STD_OFF, software takes care of the last block
 *                  (padding and subkey XOR) and calls Crypto_30_Hwa_Hw_CmacProcessBlock() as usual.
 *  \param[in,out]  workspace          CMACAES workspace.
 *  \param[out]     outPtr             Output buffer where the MAC result shall be stored.
 *  \param[in]      outLength          Length available in outPtr buffer.
 *  \return         E_OK               Finishing CMAC was successful.
 *                  E_NOT_OK           Finishing CMAC failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CmacFinish(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outPtr,
  uint32 outLength);
# endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) */

# if (CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Sha256ProcessBlocks()
 **********************************************************************************************************************/
/*! \brief          Process a chunk of data with SHA256.
 *  \details        This function expects complete blocks the hardware can process.
 *  \param[in,out]  workspace          SHA256 workspace.
 *  \param[in]      inputPtr           Pointer to input data.
 *  \param[in]      inputLength        Length of the input data.
 *  \return         E_OK               Processing was successful.
 *                  E_NOT_OK           Processing failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Sha256ProcessBlocks(
  Crypto_30_Hwa_WorkSpaceSHA256_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Sha256Start()
 **********************************************************************************************************************/
/*! \brief          Start the SHA256 calculation.
 *  \details        -
 *  \param[in,out]  workspace          SHA256 Workspace.
 *  \return         E_OK               Starting SHA256 was successful.
 *                  E_NOT_OK           Starting SHA256 failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Sha256Start(
  Crypto_30_Hwa_WorkSpaceSHA256_PtrType workspace);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Sha256Finish()
 **********************************************************************************************************************/
/*! \brief          Finish the SHA256 calculation. Returns the calculated hashsum.
 *  \details        This function is also responsible for processing remaining data in the workspace buffer.
 *                  The totalLength parameter in the workspace is already incremented with the amount of buffer data.
 *  \param[in,out]  workspace          SHA256 workspace.
 *  \param[out]     hashsum            Destination pointer where the hashsum is written.
 *  \param[in,out]  hashsumLength      Maximum available space in destination. Will be set to written length.
 *  \return         E_OK               Finishing SHA256 was successful.
 *                  E_NOT_OK           Finishing SHA256 failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Sha256Finish(
  Crypto_30_Hwa_WorkSpaceSHA256_PtrType workspace,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) hashsum,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) hashsumLength);
# endif /* (CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_ON) */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_GCMSIV == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmSivStart()
 **********************************************************************************************************************/
/*! \brief          Initializes AES GCM SIV calculation.
 *  \details        Derives the GHASH key and the cipher key from the inital key and the IV.
 *  \param[in,out]  workspace   GCM Workspace.
 *  \param[in]      key         Key used for crypto operation.
 *  \param[in]      keyLength   Length of key.
 *  \param[in]      iv          Initialisation vector used for crypto operation
 *  \param[in]      ivLength    Length of IV.
 *  \return         E_OK        Starting AES GCM SIV calculation was successful.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmSivStart(
  Crypto_30_Hwa_WorkSpaceGCMSIV_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key,
  uint8 keyLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) iv,
  uint32 ivLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmSivTagFinalize()
 **********************************************************************************************************************/
/*! \brief          Apply the final steps to generate the tag.
 *  \details        XOR GHASH tag with IV. Apply tag mask. Encrypt tag.
 *  \param[in,out]  workspace  GCM Workspace.
 *  \return         E_OK       Tag finalization was successful.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmSivTagFinalize(
  Crypto_30_Hwa_WorkSpaceGCMSIV_PtrType workspace);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmSivAesCtrCryptionInit()
 **********************************************************************************************************************/
/*! \brief          Prepares the AES engine for encrypting/decryping the message with AES CTR.
 *  \details        -
 *  \param[in,out]  workspace  GCM SIV workspace.
 *  \return         E_OK       Preparing the AES engine was successfull.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmSivAesCtrCryptionInit(
  Crypto_30_Hwa_WorkSpaceGCMSIV_PtrType workspace);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmSivAesCtrCryptionUpdate()
 **********************************************************************************************************************/
/*! \brief          Performes a AES CTR encryption on one block of input.
 *  \details        -
 *  \param[in]      workspace        GCM SIV workspace.
 *  \param[in]      inputPtr         Input buffer with data to be processed.
 *  \param[in]      inputLength      Length of input.
 *  \param[out]     outputPtr        Output buffer to store result.
 *  \param[out]     outputLengthPtr  Length of output buffer.
 *  \return         E_OK             Processing of Input was successful.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmSivAesCtrCryptionUpdate(
  Crypto_30_Hwa_WorkSpaceGCMSIV_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputLengthPtr);
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_GCMSIV == STD_ON) */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmStart()
 **********************************************************************************************************************/
/*! \brief          Initializes AES GCM calculation.
 *  \details        Sets the key and IV. Calculates the key for GHASH.
 *                  Starts the GCM operation.
 *  \param[in,out]  workspace            GCM Workspace.
 *  \param[in]      key                  Key used for crypto operation.
 *  \param[in]      keyLength            Length of key.
 *  \param[in,out]  iv                   Initialisation vector used for crypto operation
 *  \param[in]      ivLength             Length of IV.
 *  \return         E_OK                 Starting AES GCM was successful.
 *                  E_NOT_OK             Starting AES GCM was not successful.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmStart(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key,
  uint8 keyLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) iv,
  uint32 ivLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmProcessBlocksAad()
 **********************************************************************************************************************/
/*! \brief          Process multiple (one or more) AES GCM AAD blocks with full AES block length.
 *  \details        -
 *  \param[in,out]  workspace          AES GCM workspace.
 *  \param[in]      blockCount         Number of complete blocks that should be processed. Must be at least 1.
 *  \param[in]      inputPtr           Pointer to input data.
 *  \return         E_OK               Processing was successful.
 *                  E_NOT_OK           Processing failed.
 *  \pre            BlockCount has to be at least 1.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmProcessBlocksAad(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace,
  uint32 blockCount,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmProcessLastBlockAad()
 **********************************************************************************************************************/
/*! \brief          Process last block of AAD data, if input length is not multiple of AES block size.
 *  \details        Processes AAD data if last block is less than 16 bytes or if total length of AAD is less
 *                  than 16 bytes.
 *  \param[in,out]  workspace          AES GCM workspace.
 *  \param[in]      inputPtr           Pointer to input data.
 *  \param[in]      inputLength        Length of input in bytes.
 *  \return         E_OK               Processing was successful.
 *                  E_NOT_OK           Processing failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmProcessLastBlockAad(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmProcessBlocksInput()
 **********************************************************************************************************************/
/*! \brief          Process multiple (one or more) AES GCM input blocks with full AES block length.
 *  \details        -
 *  \param[in,out]  workspace          AES GCM workspace.
 *  \param[in]      blockCount         Number of complete blocks that should be processed. Must be at least 1.
 *  \param[in]      inputPtr           Pointer to input data.
 *  \param[out]     outputPtr          Pointer to output data bytes.
 *  \return         E_OK               Processing was successful.
 *                  E_NOT_OK           Processing failed.
 *  \pre            BlockCount has to be at least 1.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmProcessBlocksInput(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace,
  uint32 blockCount,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmProcessLastBlockInput()
 **********************************************************************************************************************/
/*! \brief          Process the last AES GCM input block.
 *  \details        Always processes last block of input data regardless of length.
 *  \param[in,out]  workspace          AES GCM workspace.
 *  \param[in,out]  inputPtr           Pointer to input data.
 *  \param[in]      inputLength        Length of input in bytes.
 *  \param[out]     outputPtr          Pointer to output data bytes.
 *  \return         E_OK               Processing was successful.
 *                  E_NOT_OK           Processing failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmProcessLastBlockInput(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmFinish()
 **********************************************************************************************************************/
/*! \brief          Finish the AES GCM calculation.
 *  \details        -
 *  \param[in,out]  workspace                 AES workspace.
 *  \param[out]     outputPtr                 Output buffer where written plaintext or ciphertext is stored.
 *  \param[out]     outputLengthPtr           Length available in outPtr buffer.
 *  \param[out]     secondaryOutputPtr        Output buffer where tag is stored.
 *  \param[out]     secondaryOutputLengthPtr  Length available in secondaryOutput buffer.
 *  \param[in]      aadProcessedLength        Total length of processed AAD.
 *  \param[in]      inputProcessedLength      Total length of processed input.
 *  \param[in]      ivPadded                  IV that was prepared in start function.
 *  \return         E_OK                      Finishing AES GCM was successful.
 *                  E_NOT_OK                  Finishing AES GCM failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmFinish(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputLengthPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) secondaryOutputPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) secondaryOutputLengthPtr,
  uint32 aadProcessedLength,
  uint32 inputProcessedLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) ivPadded);
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_EcdsaGenerateFinish()
 **********************************************************************************************************************/
/*! \brief          Finish the Signature Verify calculation.
 *  \details        -
 *  \param[in]      job                  Pointer to current job
 *  \param[in,out]  workspace            Signature workspace
 *  \param[in]      curveParameters      Pointer to the curve parameters
 *  \param[in]      privateKeyPtr        Private key for signature generation
 *  \param[in]      ephemeralKeyPtr      Random generated key for signature generation
 *  \param[in]      inputDataPtr         Buffer for the data for which the signature is calculated
 *  \param[in]      inputDataLength      Length of the input data
 *  \param[out]     outputDataPtr        Buffer for the calculated signature.
 *  \param[in,out]  outputDataLengthPtr  Buffer for the length of the calculated signature.
 *  \return         E_OK                 Generating the signature was successful.
 *                  E_NOT_OK             Generating the signature failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_EcdsaGenerateFinish(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) curveParameters,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) privateKeyPtr,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) ephemeralKeyPtr,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputDataPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputDataLengthPtr);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_EcdsaVerifyFinish()
 **********************************************************************************************************************/
/*! \brief          Finish the Signature Verify calculation.
 *  \details        -
 *  \param[in]      job                   Pointer to current job
 *  \param[in,out]  workspace             Signature workspace
 *  \param[in]      curveParameters       Pointer to the curve parameters
 *  \param[in]      publicKeyPtr          Public key for signature verification
 *  \param[in]      inputDataPtr          Buffer of the input for which the signature is verified
 *  \param[in]      inputDataLength       Length of the input data
 *  \param[in]      signatureDataPtr      Buffer for the signature to be verified against
 *  \param[in]      signatureDataLength   Length of the signature
 *  \param[out]     verifyPtr             Variable to store the result of the verification
 *  \return         E_OK                  Verifying the signature was successful.
 *                  E_NOT_OK              Verifying the signature failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_EcdsaVerifyFinish(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) curveParameters,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) publicKeyPtr,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) signatureDataPtr,
  uint32 signatureDataLength,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) verifyPtr);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Ed25519GenerateStart()
 **********************************************************************************************************************/
/*! \brief          Initialize the generation of an ED25519 signature.
 *  \details        -
 *  \param[in]      job              Pointer to current job
 *  \param[in,out]  workspace        Signature workspace
 *  \return         E_OK             Generating the signature was successful.
 *                  E_NOT_OK         Generating the signature failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Ed25519GenerateStart(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Ed25519GenerateUpdate()
 **********************************************************************************************************************/
/*! \brief          Update the generation of an ED25519 signature.
 *  \details        -
 *  \param[in]      job              Pointer to current job
 *  \param[in,out]  workspace        Signature workspace
 *  \param[in]      inputDataPtr     Message to be signed
 *  \param[in]      inputDataLength  Length of the message
 *  \return         E_OK             Updating the signature generation was successful.
 *                  E_NOT_OK         Updating the signature generation failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Ed25519GenerateUpdate(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Ed25519GenerateFinish()
 **********************************************************************************************************************/
/*! \brief          Finish the generation of an ED25519 signature.
 *  \details        -
 *  \param[in]      job                    Pointer to current job
 *  \param[in,out]  workspace              Signature workspace
 *  \param[in]      privateKeyPtr          Private key for signature generation
 *  \param[in]      inputDataPtr           Message or hash of message to be verified
 *  \param[in]      inputDataLength        Total length of the message or hash
 *  \param[in]      contextDataPtr         Context data
 *  \param[in]      contextDataLength      Length of context data
 *  \param[out]     outputBufferPtr        Buffer which holds the R and S part of the signature
 *  \param[out]     outputBufferLengthPtr  Total length of the signature
 *  \return         E_OK                   Generating the signature was successful.
 *                  E_NOT_OK               Generating the signature failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Ed25519GenerateFinish(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) privateKeyPtr,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) contextDataPtr,
  uint32 contextDataLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputBufferPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputBufferLengthPtr);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Ed25519VerifyStart()
 **********************************************************************************************************************/
/*! \brief          Initialize the verification of an ED25519 signature.
 *  \details        -
 *  \param[in]      job              Pointer to current job
 *  \param[in,out]  workspace        Signature workspace
 *  \return         E_OK             Initialising the signature verification was successful.
 *                  E_NOT_OK         Initialising the signature verification failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Ed25519VerifyStart(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Ed25519VerifyUpdate()
 **********************************************************************************************************************/
/*! \brief          Update the verification of an ED25519 signature.
 *  \details        -
 *  \param[in]      job              Pointer to current job
 *  \param[in,out]  workspace        Signature workspace
 *  \param[in]      inputDataPtr     Message to be verified
 *  \param[in]      inputDataLength  Total length of the message
 *  \return         E_OK             Updating the signature verification was successful.
 *                  E_NOT_OK         Updating the signature verification failed.
 *  \pre            Crypto_30_Hwa_Hw_Ed25519VerifyStart() is called
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Ed25519VerifyUpdate(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Ed25519VerifyFinish()
 **********************************************************************************************************************/
/*! \brief          Finish the verification of an ED25519 signature.
 *  \details        -
 *  \param[in]      job                  Pointer to current job
 *  \param[in,out]  workspace            Signature workspace
 *  \param[in]      publicKeyPtr         Public key for signature verification
 *  \param[in]      inputDataPtr         Message or hash of message to be verified
 *  \param[in]      inputDataLength      Total length of the message or hash
 *  \param[in]      signatureDataPtr     R and S part of the signature
 *  \param[in]      signatureDataLength  Total length of the signature
 *  \param[out]     verifyPtr            Variable to store the result of the verification
 *  \return         E_OK                 Verifying the signature was successful.
 *                  E_NOT_OK             Verifying the signature failed.
 *  \pre            Crypto_30_Hwa_Hw_Ed25519VerifyUpdate() is called
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Ed25519VerifyFinish(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) publicKeyPtr,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) signatureDataPtr,
  uint32 signatureDataLength,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) verifyPtr);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) */

# define CRYPTO_30_HWA_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define CRYPTO_30_HWA_START_SEC_CODE_ISR
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngIRQHandler()
 **********************************************************************************************************************/
/*! \brief          Interrupt request handler for True Random Number Generator
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
OS_ISR1(Crypto_30_Hwa_Hw_TrngIRQHandler);

# define CRYPTO_30_HWA_STOP_SEC_CODE_ISR
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* CRYPTO_30_HWA_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Hw.h
 *********************************************************************************************************************/
