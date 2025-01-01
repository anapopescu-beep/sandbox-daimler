/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the HIS security module - job handling
 *
 *  \description  Offers interface to CSM
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#ifndef SEC_JOB_H
#define SEC_JOB_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Security module configuration settings */
#include "Sec_Inc.h"

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if defined( __cplusplus )
extern "C" {
#endif

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_ENABLE_CRYPTOGRAPHIC_KEYS )
SecM_CryptographicKeyValuePtrType SecM_GetKeyValueByElementId(SecM_WordType smhKeyId, uint32 keyElementId);
#endif /* SEC_ENABLE_CRYPTOGRAPHIC_KEYS */

#if defined( SEC_ENABLE_JOB_HASH )
SecM_StatusType SecM_HashJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_ConstRamDataType dataPtr,
   SecM_WordType dataLength, SecM_RamDataType hashPtr, SecM_WordType * hashLengthPtr);
#endif /* SEC_ENABLE_JOB_HASH */
#if defined( SEC_ENABLE_JOB_MACVERIFY )
SecM_StatusType SecM_MacVerifyJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr,
   SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_ConstRamDataType macPtr, SecM_WordType macLength);
#endif /* SEC_ENABLE_JOB_MACVERIFY */
#if defined( SEC_ENABLE_JOB_MACGENERATE )
SecM_StatusType SecM_MacGenerateJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr,
   SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_RamDataType macPtr, SecM_WordType * macLengthPtr);
#endif /* SEC_ENABLE_JOB_MACGENERATE */
#if defined( SEC_ENABLE_JOB_ENCRYPTION )
SecM_StatusType SecM_EncryptionJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr,
   SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_RamDataType resultPtr, SecM_WordType * resultLengthPtr);
#endif /* SEC_ENABLE_JOB_ENCRYPTION */
#if defined( SEC_ENABLE_JOB_DECRYPTION ) ||\
    defined( SEC_ENABLE_JOB_AEADDECRYPT )
SecM_StatusType SecM_DecryptionJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr,
   SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_RamDataType resultPtr, SecM_WordType * resultLengthPtr);
#endif /* SEC_ENABLE_JOB_DECRYPTION */
#if defined( SEC_ENABLE_JOB_RANDOMGENERATE )
SecM_StatusType SecM_RandomGenerateJob(SecM_WordType jobId, SecM_RamDataType resultPtr, SecM_WordType * resultLengthPtr);
#endif /* SEC_ENABLE_JOB_RANDOMGENERATE */
#if defined( SEC_ENABLE_JOB_RANDOMSEED )
SecM_StatusType SecM_RandomSeedJob(SecM_WordType jobId, SecM_ConstRamDataType seedPtr, SecM_WordType seedLength);
#endif /* SEC_ENABLE_JOB_RANDOMSEED */
#if defined( SEC_ENABLE_JOB_SIGNATUREVERIFY )
SecM_StatusType SecM_SignatureVerifyJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr,
   SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_ConstRamDataType signaturePtr, SecM_WordType signatureLength);
#endif /* SEC_ENABLE_JOB_SIGNATUREVERIFY */
#if defined( SEC_ENABLE_JOB_AEADENCRYPT )
SecM_StatusType SecM_AEADEncrypt_Job(SecM_WordType jobId,  SecM_OperationModeType mode,
   SecM_ConstRamDataType plaintextPtr, SecM_WordType plaintextLength,
   SecM_ConstRamDataType associatedDataPtr, SecM_WordType associatedDataLength,
   SecM_RamDataType ciphertextPtr, SecM_RamWordType ciphertextLengthPtr,
   SecM_RamDataType tagPtr, SecM_RamWordType tagLengthPtr);
#endif /* SEC_ENABLE_JOB_AEADENCRYPT */
#if defined( SEC_ENABLE_JOB_AEADDECRYPT )
SecM_StatusType SecM_AEADDecrypt_Job(SecM_WordType jobId, SecM_OperationModeType mode,
   SecM_ConstRamDataType ciphertextPtr, SecM_WordType ciphertextLength,
   SecM_ConstRamDataType associatedDataPtr, SecM_WordType associatedDataLength,
   SecM_ConstRamDataType tagPtr, SecM_WordType tagLength,
   SecM_RamDataType plaintextPtr, SecM_RamWordType plaintextLengthPtr);
#endif /* SEC_ENABLE_JOB_AEADDECRYPT */
#if defined( SEC_ENABLE_JOB_KEYDERIVE )
SecM_StatusType SecM_KeyDeriveJob(SecM_WordType jobId, SecM_VoidPtrType keyPtr, SecM_RamDataType resultPtr, SecM_RamWordType resultLengthPtr);
#endif /* SEC_ENABLE_JOB_KEYDERIVE */
#if defined( SEC_ENABLE_KEY_OPERATION_ACCESS )
SecM_StatusType SecM_KeyElementSet(uint32 csmKeyId, uint32 keyElementId, SecM_ConstRamDataType keyPtr, SecM_WordType keyLength);
SecM_StatusType SecM_KeyElementGet(uint32 csmKeyId, uint32 keyElementId, SecM_RamDataType keyPtr, SecM_RamWordType keyLengthPtr);
#endif /* SEC_ENABLE_KEY_OPERATION_ACCESS */

#if defined( SEC_ENABLE_KEY_OPERATION_COPY )
SecM_StatusType SecM_KeyCopy(uint32 csmSourceKeyId, uint32 csmTargetKeyId);
#endif /* SEC_ENABLE_KEY_OPERATION_COPY */

#if defined( SEC_ENABLE_KEY_OPERATION_ELEMENT_COPY )
SecM_StatusType SecM_KeyElementCopy(uint32 csmSourceKeyId, uint32 csmTargetKeyId, uint32 keyElementId);
#endif /* SEC_ENABLE_KEY_OPERATION_ELEMENT_COPY */

#if defined( SEC_ENABLE_SAVE_RESTORE_CONTEXT ) && defined( SEC_ENABLE_CSM )
SecM_StatusType SecM_SaveContextCsm(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_RamWordType contextBufferLengthPtr);

# if defined( SEC_ENABLE_SAVE_RESTORE_HASH )
SecM_StatusType SecM_RestoreContextHash(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength);
# endif /* SEC_ENABLE_SAVE_RESTORE_HASH */

# if defined( SEC_ENABLE_SAVE_RESTORE_ENCRYPT )
SecM_StatusType SecM_RestoreContextEncryption(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength);
#endif /* SEC_ENABLE_SAVE_RESTORE_ENCRYPT */

#if defined( SEC_ENABLE_SAVE_RESTORE_DECRYPT )
SecM_StatusType SecM_RestoreContextDecryption(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength);
#endif /* SEC_ENABLE_SAVE_RESTORE_DECRYPT */

#if defined( SEC_ENABLE_SAVE_RESTORE_MAC_GENERATE )
SecM_StatusType SecM_RestoreContextMacGenerate(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength);
#endif /* SEC_ENABLE_SAVE_RESTORE_MAC_GENERATE */

#if defined( SEC_ENABLE_SAVE_RESTORE_MAC_VERIFY )
SecM_StatusType SecM_RestoreContextMacVerify(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength);
#endif /* SEC_ENABLE_SAVE_RESTORE_MAC_VERIFY */

# if defined( SEC_ENABLE_SAVE_RESTORE_SIG_VERIFY )
SecM_StatusType SecM_RestoreContextSignatureVerify(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength);
# endif /* SEC_ENABLE_SAVE_RESTORE_SIG_VERIFY */

# if defined( SEC_ENABLE_SAVE_RESTORE_AEAD_ENCRYPT )
SecM_StatusType SecM_RestoreContextAEADEncrypt(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength);
# endif /* SEC_ENABLE_SAVE_RESTORE_AEAD_ENCRYPT */

# if defined( SEC_ENABLE_SAVE_RESTORE_AEAD_DECRYPT )
SecM_StatusType SecM_RestoreContextAEADDecrypt(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength);
# endif /* SEC_ENABLE_SAVE_RESTORE_AEAD_DECRYPT */
#endif /* SEC_ENABLE_SAVE_RESTORE_CONTEXT && SEC_ENABLE_CSM */

#if (defined( SEC_ENABLE_CSM ) && (SecM_GetSizeOfJobInfo() > 0u))
void SecM_CancelAllJobs(void);
#endif /* SEC_ENABLE_CSM && SecM_GetSizeOfJobInfo() > 0u */
#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( __cplusplus )
} /* extern "C" */
#endif

#endif /* SEC_JOB_H */

/***********************************************************************************************************************
 *  END OF FILE: SEC.H
 **********************************************************************************************************************/
