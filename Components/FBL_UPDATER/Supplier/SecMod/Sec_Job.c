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

#define SEC_JOB_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Security module configuration settings */
#include "Sec.h"
#if defined ( SEC_ENABLE_CSM )
# include "Csm.h"
#endif /* SEC_ENABLE_CSM */

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( SEC_ENABLE_JOB_MACVERIFY )         || \
    defined( SEC_ENABLE_JOB_MACGENERATE )       || \
    defined( SEC_ENABLE_JOB_ENCRYPTION )        || \
    defined( SEC_ENABLE_JOB_DECRYPTION )        || \
    defined( SEC_ENABLE_JOB_AEADDECRYPT )       || \
    defined( SEC_ENABLE_JOB_SIGNATUREVERIFY )   || \
    defined( SEC_ENABLE_JOB_KEYDERIVE )
# define SEC_ENABLE_JOB_INITKEY
#else
# define SEC_DISABLE_JOB_INITKEY
#endif

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#if defined( SEC_ENABLE_JOB_AEADDECRYPT )
V_MEMRAM0 static V_MEMRAM1 SecM_ByteType V_MEMRAM2 SecM_AuthBufferData[SEC_BUFFER_AUTHDATA_SIZE];  /* PRQA S 3218 */ /* MD_SecJob_3218 */
V_MEMRAM0 static V_MEMRAM1 SecM_ByteType V_MEMRAM2 SecM_TagBufferData[SEC_BUFFER_TAGDATA_SIZE];    /* PRQA S 3218 */ /* MD_SecJob_3218 */
V_MEMRAM0 static V_MEMRAM1 SecM_RamBufferProcessingType V_MEMRAM2 SecM_AuthBuffer;
V_MEMRAM0 static V_MEMRAM1 SecM_RamBufferProcessingType V_MEMRAM2 SecM_TagBuffer;
V_MEMRAM0 static V_MEMRAM1 SecM_DecrStatusFsm V_MEMRAM2 SecM_AeadFsmSts;
V_MEMRAM0 static V_MEMRAM1 SecM_ByteType V_MEMRAM2 SecM_AeadAuthDataSent;
#endif

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_ENABLE_JOB_INITKEY )
# if defined( SEC_ENABLE_JOB_INITKEY_AES )
static SecM_StatusType SecM_InitKeyAes(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr);
# endif /* SEC_ENABLE_JOB_INITKEY_AES */
# if defined( SEC_ENABLE_JOB_INITKEY_MAC )
static SecM_StatusType SecM_InitKeyMac(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr);
# endif /* SEC_ENABLE_JOB_INITKEY_MAC */
# if defined( SEC_ENABLE_JOB_INITKEY_SYMMETRIC )
static SecM_StatusType SecM_InitKeySymmetric(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr);
# endif /* SEC_ENABLE_JOB_INITKEY_SYMMETRIC */
# if defined( SEC_ENABLE_JOB_INITKEY_ASYMMETRIC )
static SecM_StatusType SecM_InitKeyAsymmetric(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr);
# endif /* SEC_ENABLE_JOB_INITKEY_ASYMMETRIC */
# if defined( SEC_ENABLE_JOB_INITKEY_PBKDF2 )
static SecM_StatusType SecM_InitKeyPBKDF2(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr);
# endif /* SEC_ENABLE_JOB_INITKEY_PBKDF2 */
static SecM_StatusType SecM_InitKey(SecM_JobInfoPtrType pJobInfo, SecM_VoidPtrType keyPtr);
#endif /* SEC_ENABLE_JOB_INITKEY */

#if defined( SEC_ENABLE_JOB_AEADDECRYPT )
static void SecM_DecryptAEADInit(SecM_JobInfoPtrType pJobInfo);
static SecM_StatusType SecM_DecryptAEAD(SecM_WordType jobId, V_MEMRAM1 SecM_OperationModeType V_MEMRAM2 V_MEMRAM3 * localMode,
   SecM_ConstRamDataType dataPtr, SecM_RamWordType dataLength, SecM_RamDataType resultPtr, SecM_RamWordType resultLengthPtr);
#endif /* SEC_ENABLE_JOB_AEADDECRYPT */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#if defined( SEC_ENABLE_JOB_INITKEY )
# if defined( SEC_ENABLE_JOB_INITKEY_AES )
/***********************************************************************************************************************
 *  SecM_InitKeyAes
 **********************************************************************************************************************/
/*! \brief         Initializes the given AES key (key and IV)
 *  \param[in]     csmKeyId ID of the key configured in CSM
 *  \param[in]     smhKeyId ID of the key configured in SMH
 *  \param[in]     keyPtr Pointer to the AES key
 *  \return        SECM_OK if initialization successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static SecM_StatusType SecM_InitKeyAes(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr)
{
   SecM_StatusType result = SECM_OK;
   Std_ReturnType csmResult = E_OK;
   SecM_AesKeyType * aesKey; /* PRQA S 3678 */ /* MD_MSR_Rule8.13 */
   SecM_CryptographicKeyValuePtrType ivKeyElement;
   SecM_CryptographicKeyValuePtrType aesKeyElement;

   if (smhKeyId < SecM_GetSizeOfCryptogrphicKeys())
   {
      aesKey = (SecM_AesKeyType*)keyPtr; /* PRQA S 0316 */ /* MD_SecJob_0316 */
      ivKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_CIPHER_IV);
      aesKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_CIPHER_KEY);

      /* Initialize the IV */
      if (ivKeyElement != NULL_PTR)
      {
         if ((aesKey != NULL_PTR) && (aesKey->iv.size == ivKeyElement->size))
         {
            /* Use provided IV */
            csmResult = Csm_KeyElementSet(csmKeyId, ivKeyElement->cryptoElementId, aesKey->iv.data, aesKey->iv.size);
         }
         else if (ivKeyElement->data != NULL_PTR)
         {
            /* Use IV configured in SMH module */
            csmResult = Csm_KeyElementSet(csmKeyId, ivKeyElement->cryptoElementId, ivKeyElement->data, ivKeyElement->size);
         }
         else
         {
            /* Nothing to do, IV is not written by SecModHis */
         }
      }
      /* Initialize the AesKey */
      if (aesKeyElement != NULL_PTR)
      {
         if ((aesKey != NULL_PTR) && (aesKey->key.size == aesKeyElement->size))
         {
            /* Use provided key */
            csmResult |= Csm_KeyElementSet(csmKeyId, aesKeyElement->cryptoElementId, aesKey->key.data, aesKey->key.size);
         }
         else if (aesKeyElement->data != NULL_PTR)
         {
            /* Use key configured in SMH module */
            csmResult |= Csm_KeyElementSet(csmKeyId, aesKeyElement->cryptoElementId, aesKeyElement->data, aesKeyElement->size);
         }
         else
         {
            /* Nothing to do, AES Key is not written by SecModHis */
         }
      }
   }

   if (csmResult != E_OK)
   {
      result = SECM_NOT_OK;
   }

   return result;
}
# endif /* SEC_ENABLE_JOB_INITKEY_AES */

# if defined( SEC_ENABLE_JOB_INITKEY_MAC )
/***********************************************************************************************************************
 *  SecM_InitKeyMac
 **********************************************************************************************************************/
/*! \brief         Initializes the given mac key
 *  \param[in]     csmKeyId ID of the key configured in CSM
 *  \param[in]     smhKeyId ID of the key configured in SMH
 *  \param[in]     keyPtr Pointer to the mac key
 *  \return        SECM_OK if initialization successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static SecM_StatusType SecM_InitKeyMac(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr)
{
   SecM_StatusType result = SECM_OK;
   Std_ReturnType csmResult = E_OK;
   SecM_SymKeyType * macKey; /* PRQA S 3678 */ /* MD_MSR_Rule8.13 */
   SecM_CryptographicKeyValuePtrType macKeyElement;

   if (smhKeyId < SecM_GetSizeOfCryptogrphicKeys())
   {
      macKey = (SecM_SymKeyType*)keyPtr; /* PRQA S 0316 */ /* MD_SecJob_0316 */
      macKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_MAC_KEY);

      /* Initialize the mac key */
      if (macKeyElement != NULL_PTR)
      {
         if ((macKey != NULL_PTR) && (macKey->size == macKeyElement->size))
         {
            /* Use provided mac key */
            csmResult = Csm_KeyElementSet(csmKeyId, macKeyElement->cryptoElementId, macKey->data, macKey->size);
         }
         else if (macKeyElement->data != NULL_PTR)
         {
            /* Use mac key configured in SMH module */
            csmResult = Csm_KeyElementSet(csmKeyId, macKeyElement->cryptoElementId, macKeyElement->data, macKeyElement->size);
         }
         else
         {
            /* Nothing to do, mac key is not written by SecModHis */
         }
      }
   }

   if (csmResult != E_OK)
   {
      result = SECM_NOT_OK;
   }

   return result;
}
# endif /* SEC_ENABLE_JOB_INITKEY_MAC */

# if defined( SEC_ENABLE_JOB_INITKEY_SYMMETRIC )
/***********************************************************************************************************************
 *  SecM_InitKeySymmetric
 **********************************************************************************************************************/
/*! \brief         Initializes the given symmetric key for signatures (e.g. Ed25519)
 *  \param[in]     csmKeyId ID of the key configured in CSM
 *  \param[in]     smhKeyId ID of the key configured in SMH
 *  \param[in]     keyPtr Pointer to the symmetric key
 *  \return        SECM_OK if initialization successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static SecM_StatusType SecM_InitKeySymmetric(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr)
{
   SecM_StatusType result = SECM_OK;
   Std_ReturnType csmResult = E_OK;
   SecM_SymKeyType * symKey; /* PRQA S 3678 */ /* MD_MSR_Rule8.13 */
   SecM_CryptographicKeyValuePtrType symKeyElement;

   if (smhKeyId < SecM_GetSizeOfCryptogrphicKeys())
   {
      symKey = (SecM_SymKeyType*)keyPtr; /* PRQA S 0316 */ /* MD_SecJob_0316 */
      symKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_SIGNATURE_KEY);

      /* Initialize the symmetric key */
      if (symKeyElement != NULL_PTR)
      {
         if ((symKey != NULL_PTR) && (symKey->size == symKeyElement->size))
         {
            /* Use provided symmetric key */
            csmResult = Csm_KeyElementSet(csmKeyId, symKeyElement->cryptoElementId, symKey->data, symKey->size);
         }
         else if (symKeyElement->data != NULL_PTR)
         {
            /* Use symmetric key configured in SMH module */
            csmResult = Csm_KeyElementSet(csmKeyId, symKeyElement->cryptoElementId, symKeyElement->data, symKeyElement->size);
         }
         else
         {
            /* Nothing to do, symmetric key is not written by SecModHis */
         }
      }
   }

   if (csmResult != E_OK)
   {
      result = SECM_NOT_OK;
   }

   return result;
}
# endif /* SEC_ENABLE_JOB_INITKEY_SYMMETRIC */

# if defined( SEC_ENABLE_JOB_INITKEY_ASYMMETRIC )
/***********************************************************************************************************************
 *  SecM_InitKeyAsymmetric
 **********************************************************************************************************************/
/*! \brief         Initializes the given asymmetric keys for RSA signatures (public exponent and modulus)
 *  \param[in]     csmKeyId ID of the key configured in CSM
 *  \param[in]     smhKeyId ID of the key configured in SMH
 *  \param[in]     keyPtr Pointer to the asymmetric key
 *  \return        SECM_OK if initialization successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 3673, 6010, 6030 1 */ /* MD_MSR_Rule8.13, MD_MSR_STPTH, MD_MSR_STCYC */
static SecM_StatusType SecM_InitKeyAsymmetric(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr)
{
   SecM_StatusType result = SECM_OK;
   Std_ReturnType csmResult = E_OK;
   SecM_AsymKeyType * asymKey; /* PRQA S 3678 */ /* MD_MSR_Rule8.13 */
   SecM_CryptographicKeyValuePtrType sharedKeyElement;
   SecM_CryptographicKeyValuePtrType publicKeyElement;
   SecM_CryptographicKeyValuePtrType privateKeyElement;

   if (smhKeyId < SecM_GetSizeOfCryptogrphicKeys())
   {
      asymKey = (SecM_AsymKeyType*)keyPtr; /* PRQA S 0316 */ /* MD_SecJob_0316 */
      sharedKeyElement = SecM_GetKeyValueByElementId(smhKeyId, SEC_KE_RSA_MODULUS);
      publicKeyElement = SecM_GetKeyValueByElementId(smhKeyId, SEC_KE_RSA_PUBLIC_EXPONENT);
      privateKeyElement = SecM_GetKeyValueByElementId(smhKeyId, SEC_KE_RSA_PRIVATE_EXPONENT);

      /* Initialize the shared key (modulus) */
      if (sharedKeyElement != NULL_PTR)
      {
         if ((asymKey != NULL_PTR) && (asymKey->shared.size == sharedKeyElement->size))
         {
            /* Use provided shared key */
            csmResult = Csm_KeyElementSet(csmKeyId, sharedKeyElement->cryptoElementId, asymKey->shared.data, asymKey->shared.size);
         }
         else if (sharedKeyElement->data != NULL_PTR)
         {
            /* Use shared key configured in SMH module */
            csmResult = Csm_KeyElementSet(csmKeyId, sharedKeyElement->cryptoElementId, sharedKeyElement->data, sharedKeyElement->size);
         }
         else
         {
            /* Nothing to do, shared key is not written by SecModHis */
         }
      }
      /* Initialize the public key (public exponent), if the public key is used */
      if (publicKeyElement != NULL_PTR)
      {
         if ((asymKey != NULL_PTR) && (asymKey->individual.size == publicKeyElement->size))
         {
            /* Use provided individual key */
            csmResult |= Csm_KeyElementSet(csmKeyId, publicKeyElement->cryptoElementId, asymKey->individual.data, asymKey->individual.size);
         }
         else if (publicKeyElement->data != NULL_PTR)
         {
            /* Use individual key configured in SMH module */
            csmResult |= Csm_KeyElementSet(csmKeyId, publicKeyElement->cryptoElementId, publicKeyElement->data, publicKeyElement->size);
         }
         else
         {
            /* Nothing to do, individual key is not written by SecModHis */
         }
      }
      /* Initialize the private key (private exponent), if the private key is used */
      if (privateKeyElement != NULL_PTR)
      {
         if ((asymKey != NULL_PTR) && (asymKey->individual.size == privateKeyElement->size))
         {
            /* Use provided individual key */
            csmResult |= Csm_KeyElementSet(csmKeyId, privateKeyElement->cryptoElementId, asymKey->individual.data, asymKey->individual.size);
         }
         else if (privateKeyElement->data != NULL_PTR)
         {
            /* Use individual key configured in SMH module */
            csmResult |= Csm_KeyElementSet(csmKeyId, privateKeyElement->cryptoElementId, privateKeyElement->data, privateKeyElement->size);
         }
         else
         {
            /* Nothing to do, individual key is not written by SecModHis */
         }
      }
   }

   if (csmResult != E_OK)
   {
      result = SECM_NOT_OK;
   }

   return result;
}
# endif /* SEC_ENABLE_JOB_INITKEY_ASYMMETRIC */

# if defined( SEC_ENABLE_JOB_INITKEY_PBKDF2 )
/**********************************************************************************************************************
 *  SecM_InitKeyPBKDF2()
 *********************************************************************************************************************/
/*! \brief         Initializes the given parameters (treated as CSM keys) for a PBKDF2 key derive
 *  \param[in]     csmKeyId ID of the key configured in CSM
 *  \param[in]     smhKeyId ID of the key configured in SMH
 *  \param[in]     keyPtr Pointer to an external key
 *  \return        SECM_OK if initialization successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 3673, 6010, 6030 1 */ /* MD_MSR_Rule8.13, MD_MSR_STPTH, MD_MSR_STCYC */
static SecM_StatusType SecM_InitKeyPBKDF2(uint32 csmKeyId, SecM_WordType smhKeyId, SecM_VoidPtrType keyPtr)
{
   SecM_StatusType result = SECM_OK;
   Std_ReturnType csmResult = E_OK;
   SecM_PBKDF2KeyType * PBKDF2Key; /* PRQA S 3678 */ /* MD_MSR_Rule8.13 */
   SecM_CryptographicKeyValuePtrType iterationsKeyElement;
   SecM_CryptographicKeyValuePtrType saltKeyElement;
   SecM_CryptographicKeyValuePtrType passwordKeyElement;
   SecM_CryptographicKeyValuePtrType functionKeyElement;

   if (smhKeyId < SecM_GetSizeOfCryptogrphicKeys())
   {
      PBKDF2Key = (SecM_PBKDF2KeyType*)keyPtr; /* PRQA S 0316 */ /* MD_SecJob_0316 */
      iterationsKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_KEYDERIVATION_ITERATIONS);
      saltKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_KEYDERIVATION_SALT);
      passwordKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_KEYDERIVATION_PASSWORD);
      functionKeyElement = SecM_GetKeyValueByElementId(smhKeyId, CRYPTO_KE_KEYDERIVATION_ALGORITHM);

      /* Initialize the key derive iterations */
      if (iterationsKeyElement != NULL_PTR)
      {
         if ((PBKDF2Key != NULL_PTR) && (PBKDF2Key->iterations.size == iterationsKeyElement->size))
         {
            /* Use provided key derive iterations */
            csmResult = Csm_KeyElementSet(csmKeyId, iterationsKeyElement->cryptoElementId, PBKDF2Key->iterations.data, PBKDF2Key->iterations.size);
         }
         else if (iterationsKeyElement->data != NULL_PTR)
         {
            /* Use key derive iterations configured in SMH module */
            csmResult = Csm_KeyElementSet(csmKeyId, iterationsKeyElement->cryptoElementId, iterationsKeyElement->data, iterationsKeyElement->size);
         }
         else
         {
            /* Nothing to do, key derive iterations is not written by SecModHis */
         }
      }

      /* Initialize the key derive salt */
      if (saltKeyElement != NULL_PTR)
      {
         if ((PBKDF2Key != NULL_PTR) && (PBKDF2Key->salt.size == saltKeyElement->size))
         {
            /* Use provided key derive salt */
            csmResult |= Csm_KeyElementSet(csmKeyId, saltKeyElement->cryptoElementId, PBKDF2Key->salt.data, PBKDF2Key->salt.size);
         }
         else if (saltKeyElement->data != NULL_PTR)
         {
            /* Use key derive salt configured in SMH module */
            csmResult |= Csm_KeyElementSet(csmKeyId, saltKeyElement->cryptoElementId, saltKeyElement->data, saltKeyElement->size);
         }
         else
         {
            /* Nothing to do, key derive salt is not written by SecModHis */
         }
      }

      /* Initialize the key derive password */
      if (passwordKeyElement != NULL_PTR)
      {
         if ((PBKDF2Key != NULL_PTR) && (PBKDF2Key->password.size == passwordKeyElement->size))
         {
            /* Use provided key derive password */
            csmResult |= Csm_KeyElementSet(csmKeyId, passwordKeyElement->cryptoElementId, PBKDF2Key->password.data, PBKDF2Key->password.size);
         }
         else if (passwordKeyElement->data != NULL_PTR)
         {
            /* Use key derive password configured in SMH module */
            csmResult |= Csm_KeyElementSet(csmKeyId, passwordKeyElement->cryptoElementId, passwordKeyElement->data, passwordKeyElement->size);
         }
         else
         {
            /* Nothing to do, key derive password is not written by SecModHis */
         }
      }

      /* Initialize the key derive function */
      if (functionKeyElement != NULL_PTR)
      {
         if ((PBKDF2Key != NULL_PTR) && (PBKDF2Key->function.size == functionKeyElement->size))
         {
            /* Use provided key derive function */
            csmResult |= Csm_KeyElementSet(csmKeyId, functionKeyElement->cryptoElementId, PBKDF2Key->function.data, PBKDF2Key->function.size);
         }
         else if (functionKeyElement->data != NULL_PTR)
         {
            /* Use key derive function configured in SMH module */
            csmResult |= Csm_KeyElementSet(csmKeyId, functionKeyElement->cryptoElementId, functionKeyElement->data, functionKeyElement->size);
         }
         else
         {
            /* Nothing to do, key derive function is not written by SecModHis */
         }
      }
   }

   if (csmResult != E_OK)
   {
      result = SECM_NOT_OK;
   }

   return result;
}
# endif /* SEC_ENABLE_JOB_INITKEY_PBKDF2 */

/***********************************************************************************************************************
 *  SecM_InitKey
 **********************************************************************************************************************/
/*! \brief         Initializes the given keys
 *  \param[in]     pJobInfo Pointer to the job info structure
 *  \param[in]     keyPtr Pointer to the key. The exact type is determined by the key type.
 *  \return        SECM_OK if initialization successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
static SecM_StatusType SecM_InitKey(SecM_JobInfoPtrType pJobInfo, SecM_VoidPtrType keyPtr)
{
   SecM_StatusType result = SECM_OK;

# if !defined( SEC_ENABLE_JOB_INITKEY_AES )        && \
     !defined( SEC_ENABLE_JOB_INITKEY_MAC )        && \
     !defined( SEC_ENABLE_JOB_INITKEY_SYMMETRIC )  && \
     !defined( SEC_ENABLE_JOB_INITKEY_ASYMMETRIC )
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)keyPtr;
#  endif /* V_ENABLE_USE_DUMMY_STATEMENT */
# endif

   if (pJobInfo->smhKeyId != SEC_INVALID_SMH_KEY_ID)
   {
      switch (pJobInfo->keyType)
      {
         case SEC_KEY_TYPE_NONE:
         {
            /* Nothing to do */
            break;
         }
# if defined( SEC_ENABLE_JOB_INITKEY_AES )
         case SEC_KEY_TYPE_AES:
         {
            result = SecM_InitKeyAes(pJobInfo->csmKeyId, pJobInfo->smhKeyId, keyPtr);
            break;
         }
# endif /* SEC_ENABLE_JOB_INITKEY_AES */
# if defined( SEC_ENABLE_JOB_INITKEY_MAC )
         case SEC_KEY_TYPE_MAC:
         {
            result = SecM_InitKeyMac(pJobInfo->csmKeyId, pJobInfo->smhKeyId, keyPtr);
            break;
         }
# endif /* SEC_ENABLE_JOB_INITKEY_MAC */
# if defined( SEC_ENABLE_JOB_INITKEY_SYMMETRIC )
         case SEC_KEY_TYPE_SYMMETRIC:
         {
            result = SecM_InitKeySymmetric(pJobInfo->csmKeyId, pJobInfo->smhKeyId, keyPtr);
            break;
         }
# endif /* SEC_ENABLE_JOB_INITKEY_SYM */
# if defined( SEC_ENABLE_JOB_INITKEY_ASYMMETRIC )
         case SEC_KEY_TYPE_ASYMMETRIC:
         {
            result = SecM_InitKeyAsymmetric(pJobInfo->csmKeyId, pJobInfo->smhKeyId, keyPtr);
            break;
         }
# endif /* SEC_ENABLE_JOB_INITKEY_ASYMMETRIC */
# if defined( SEC_ENABLE_JOB_INITKEY_PBKDF2 )
         case SEC_KEY_TYPE_PBKDF2:
         {
            result = SecM_InitKeyPBKDF2(pJobInfo->csmKeyId, pJobInfo->smhKeyId, keyPtr);
            break;
         }
#endif /* SEC_ENABLE_JOB_INITKEY_PBKDF2 */
         default:
         {
            /* Unknown key type */
            result = SECM_NOT_OK;
            break;
         }
      }

      if (result == SECM_OK)
      {
         /* Set key to valid */
         if (Csm_KeySetValid(pJobInfo->csmKeyId) != E_OK)
         {
            result = SECM_NOT_OK;
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_JOB_INITKEY */

#if defined( SEC_ENABLE_JOB_AEADDECRYPT )
/**********************************************************************************************************************
*  SecM_DecryptAEADInit
*********************************************************************************************************************/
/*! \brief         This function allows to initialize all the necessary variables for executing AEAD decryption
 *  \param[in]     pJobInfo Pointer to the job info structure
**********************************************************************************************************************/
/* PRQA S 6010, 6030, 6060, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR,MD_MSR_STMIF */
static void SecM_DecryptAEADInit(SecM_JobInfoPtrType pJobInfo)
{
   SecM_AuthBuffer.buffer = SecM_AuthBufferData;
   SecM_AuthBuffer.pos = 0u;
   SecM_AuthBuffer.size = 0u;
   SecM_TagBuffer.buffer = SecM_TagBufferData;
   SecM_TagBuffer.pos = 0u;
   SecM_TagBuffer.size = 0u;
   /* PRQA S 0316 2 */ /* MD_SecJob_0316 */
   SecM_InitBuffer(&SecM_AuthBuffer, ((const SecM_JobDecryptionAEADParamTypes*)pJobInfo->jobParam)->authDataLength);
   SecM_InitBuffer(&SecM_TagBuffer, ((const SecM_JobDecryptionAEADParamTypes*)pJobInfo->jobParam)->dataTagLength);
   SecM_AeadFsmSts = SECM_DECRAEAD_AUTHDATA;
   SecM_AeadAuthDataSent = 0u;
}

/**********************************************************************************************************************
*  SecM_DecryptAEAD()
*********************************************************************************************************************/
/*! \brief         This function act as intermediate layer between the decryption call and the AEAD Decrypt function
 *                 for buffering relevant information like the authentication data and the tag
 *  \details       -
 *  \param[in]     jobId                Identifier of the AEAD DECRYPT job
 *  \param[in,out] localmode            Indicates which operation mode(s) to perform.
 *  \param[in]     dataPtr              Contains the pointer to the data to be decrypted.
 *  \param[in,out] dataLength           Contains the number of bytes to decrypt. On calling this function, this
 *                                      parameter shall containing the length of the data to be decrypted. When the
 *                                      request is finished, the number of consumed bytes is stored.
 *  \param[out]    resultPtr            Contains the pointer to the data where the decrypted data shall be stored.
 *  \param[in,out] resultLengthPtr      Holds a pointer to the memory location in which the output length in bytes of
 *                                      the plaintext is stored. On calling this function, this parameter shall
 *                                      contain the size of the buffer in bytes provided by resultPtr. When the request
 *                                      has finished, the actual length of the returned value shall be stored.
 *  \return        SECM_OK              Request successful
 *                 SECM_NOT_OK          Request failed
**********************************************************************************************************************/
/* PRQA S 6010, 6030, 6060, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR,MD_MSR_STMIF */
static SecM_StatusType SecM_DecryptAEAD(SecM_WordType jobId, V_MEMRAM1 SecM_OperationModeType V_MEMRAM2 V_MEMRAM3 * localMode,
   SecM_ConstRamDataType dataPtr, SecM_RamWordType dataLength, SecM_RamDataType resultPtr, SecM_RamWordType resultLengthPtr)
{
   SecM_JobInfoPtrType pJobInfo;
   const SecM_JobDecryptionAEADParamTypes *jobParamPtr;
   SecM_ByteType localFlushBuff[SEC_BUFFER_TAGDATA_SIZE];
   SecM_ShortType localFlushBuffSize;
   SecM_ShortType localDataLength;
   SecM_WordType buffLen;
   SecM_WordType localCurrentPos = 0u;
   SecM_StatusType result = SECM_OK;
   SecM_WordType outputLen = 0u;

   localDataLength = (SecM_ShortType)*dataLength;
   pJobInfo = &SecM_JobInfo[jobId];
   jobParamPtr = (const SecM_JobDecryptionAEADParamTypes *)pJobInfo->jobParam;   /* PRQA S 0316 */ /* MD_SecJob_0316 */

   switch (SecM_AeadFsmSts)
   {
      case SECM_DECRAEAD_AUTHDATA:
      {
         /* Accumulate the authentication data if present */
         if (SecM_AccumulateBufferStore(&SecM_AuthBuffer, dataPtr, &localDataLength) == SEC_BUFF_FULL)
         {
            /* Authentication data has been extracted, move the decryption phase */
            SecM_AeadFsmSts = SECM_DECRAEAD_DECRYPT;
            SecM_AeadAuthDataSent = 0u;
            *dataLength = localDataLength;
         }
         *resultLengthPtr = 0u;
         break;
      }
      case SECM_DECRAEAD_DECRYPT:
      {
         /* Store always the last data chunk which can be the Tag */
         (void)SecM_FifoBufferStore(&SecM_TagBuffer, dataPtr, &localDataLength, localFlushBuff, &localFlushBuffSize);

         /* If the authentication data has not yet been passed to the crypto stack, keep the START flag set on the mode */
         if (SecM_AeadAuthDataSent == 0u)
         {
            *localMode |= SECM_OPERATIONMODE_START;
         }

         buffLen = *resultLengthPtr;

         if (localFlushBuffSize > 0u)
         {
            /* If there is some data which has been flushed out from the Tag buffer, pass it to the crypto stack */
            if (SecM_AEADDecrypt_Job(jobId, (*localMode & ~SECM_OPERATIONMODE_FINISH), localFlushBuff, localFlushBuffSize, SecM_AuthBuffer.buffer, SecM_AuthBuffer.pos, V_NULL, 0u, resultPtr, resultLengthPtr) != SECM_OK)
            {
               result = SECM_NOT_OK;
            }
            else
            {
               outputLen = *resultLengthPtr;
               localCurrentPos = *resultLengthPtr;
               buffLen -= *resultLengthPtr;
               if (SecM_AeadAuthDataSent == 0u)
               {
                  *localMode &= ~SECM_OPERATIONMODE_START;
                  SecM_InitBuffer(&SecM_AuthBuffer, jobParamPtr->authDataLength);
                  SecM_AeadAuthDataSent = 1u;
               }
            }
         }

         if (result == SECM_OK)
         {
            if (*dataLength > localDataLength)
            {
               *resultLengthPtr = buffLen;
               if (SecM_AEADDecrypt_Job(jobId, (*localMode & ~SECM_OPERATIONMODE_FINISH), dataPtr, (*dataLength - localDataLength), SecM_AuthBuffer.buffer, SecM_AuthBuffer.pos, V_NULL, 0u, &resultPtr[localCurrentPos], resultLengthPtr) != SECM_OK)
               {
                  result = SECM_NOT_OK;
               }
               else
               {
                  outputLen += *resultLengthPtr;
                  localCurrentPos += *resultLengthPtr;
                  buffLen -= *resultLengthPtr;
                  if (SecM_AeadAuthDataSent == 0u)
                  {
                     *localMode &= ~SECM_OPERATIONMODE_START;
                     SecM_InitBuffer(&SecM_AuthBuffer, jobParamPtr->authDataLength);
                     SecM_AeadAuthDataSent = 1u;
                  }
               }
            }
         }

         if (result == SECM_OK)
         {
            *resultLengthPtr = buffLen;
            if ( (*localMode & SECM_OPERATIONMODE_FINISH) == SECM_OPERATIONMODE_FINISH )
            {
               /* If the FINISH flag is set, finalize the decryption passing the Tag */
               if (SecM_AEADDecrypt_Job(jobId, SECM_OPERATIONMODE_FINISH, V_NULL, 0u, V_NULL, 0u, SecM_TagBuffer.buffer, SecM_TagBuffer.size, &resultPtr[localCurrentPos], resultLengthPtr) != SECM_OK)
               {
                  result = SECM_NOT_OK;
               }
               else
               {
                  outputLen += *resultLengthPtr;
               }
            }
         }
         *resultLengthPtr = outputLen;
         break;
      }
      default:
      {
         /* Unknown FSM status */
         result = SECM_NOT_OK;
         break;
      }
   }

   return result;

}
#endif

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#if defined( SEC_ENABLE_CRYPTOGRAPHIC_KEYS )
/***********************************************************************************************************************
 *  SecM_GetKeyValueByElementId
 **********************************************************************************************************************/
/*! \brief         Extracts a specific KeyElement from the provided key
 *  \param[in]     smhKeyId ID of the configured cryptographic key
 *  \param[in]     keyElementId Element ID to be extracted
 *  \return        Pointer to the key element, NULL_PTR in case element ID was not found
 **********************************************************************************************************************/
SecM_CryptographicKeyValuePtrType SecM_GetKeyValueByElementId(SecM_WordType smhKeyId, uint32 keyElementId)
{
   SecM_CryptographicKeyValuePtrType pKeyValue = NULL_PTR;

   if (smhKeyId < SecM_GetSizeOfCryptogrphicKeys()) /* PRQA S 2992, 2996 */ /* MD_SecJob_2991_2992_2995_2996 */
   {
      SecM_ByteFastType index;
      SecM_CryptographicKeyPtrType pKey = &SecM_CryptographicKeys[smhKeyId]; /* PRQA S 2880 */  /* MD_SecJob_2880 */

      for (index = 0u; index < pKey->count; index++)
      {
         if (pKey->keyValues[index].cryptoElementId == keyElementId)
         {
            pKeyValue = &pKey->keyValues[index];
            break;
         }
      }
   }

   return pKeyValue;
}
#endif /* SEC_ENABLE_CRYPTOGRAPHIC_KEYS */

#if defined( SEC_ENABLE_JOB_HASH )
/***********************************************************************************************************************
 *  SecM_HashJob
 **********************************************************************************************************************/
/*! \brief         Calculates the hash over the provided data
 *  \param[in]     jobId Identifier of the HASH job
 *  \param[in]     mode Indicates the operation mode(s)
 *  \param[in]     dataPtr Pointer to the data for which the hash shall be computed
 *  \param[in]     dataLength Length of the data
 *  \param[in]     hashPtr Pointer to the data where the hash value shall be stored
 *  \param[in,out] hashLengthPtr Length of the provided hash (output: actual length of the hash)
 *  \return        SECM_OK Operation successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
SecM_StatusType SecM_HashJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_ConstRamDataType dataPtr,
   SecM_WordType dataLength, SecM_RamDataType hashPtr, SecM_WordType * hashLengthPtr)
{
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   /* Check job range */
   if (jobId < SecM_GetSizeOfJobInfo())
   {
      pJobInfo = &SecM_JobInfo[jobId];

      if (pJobInfo->service == SECM_HASH)
      {
         if (Csm_Hash(pJobInfo->csmJobId, mode, dataPtr, dataLength, hashPtr, hashLengthPtr) == E_OK)
         {
            result = SECM_OK;
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_JOB_HASH */

#if defined( SEC_ENABLE_JOB_MACVERIFY )
/***********************************************************************************************************************
 *  SecM_MacVerifyJob
 **********************************************************************************************************************/
/*! \brief         Verifies the MAC over the provided data
 *  \param[in]     jobId Identifier of the MAC VERIFY job
 *  \param[in]     mode Indicates the operation mode(s)
 *  \param[in]     keyPtr Pointer to the MAC key
 *  \param[in]     dataPtr Pointer to the data for which the MAC shall be verified
 *  \param[in]     dataLength Length of the data
 *  \param[in]     macPtr Pointer to the MAC
 *  \param[in]     macLength Length of the provided MAC
 *  \return        SECM_OK Operation successful
 *                 SECM_VER_SIG MAC was wrong
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
SecM_StatusType SecM_MacVerifyJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr,
   SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_ConstRamDataType macPtr, SecM_WordType macLength)
{
   SecM_StatusType result = SECM_NOT_OK;
   Crypto_VerifyResultType verifyResult = CRYPTO_E_VER_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   /* Check job range */
   if (jobId < SecM_GetSizeOfJobInfo())
   {
      pJobInfo = &SecM_JobInfo[jobId];

      if (pJobInfo->service == SECM_MACVERIFY)
      {
         if ((mode & SECM_OPERATIONMODE_START) == SECM_OPERATIONMODE_START)
         {
            result = SecM_InitKey(pJobInfo, keyPtr);
         }
         else
         {
            result = SECM_OK;
         }

         if (result == SECM_OK)
         {
            if (Csm_MacVerify(pJobInfo->csmJobId, mode, dataPtr, dataLength, macPtr, macLength * 8u, &verifyResult) != E_OK)
            {
               result = SECM_NOT_OK;
            }
         }

         if ((mode & SECM_OPERATIONMODE_FINISH) == SECM_OPERATIONMODE_FINISH)
         {
            /* Check result of verify */
            if ((result == SECM_OK) && (verifyResult != CRYPTO_E_VER_OK))
            {
               result = SECM_VER_SIG;
            }
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_JOB_MACVERIFY */

#if defined( SEC_ENABLE_JOB_MACGENERATE )
/***********************************************************************************************************************
 *  SecM_MacGenerateJob
 **********************************************************************************************************************/
/*! \brief         Generates the MAC over the provided data
 *  \param[in]     jobId Identifier of the MAC GENERATE job
 *  \param[in]     mode Indicates the operation mode(s)
 *  \param[in]     keyPtr Pointer to the MAC key
 *  \param[in]     dataPtr Pointer to the data for which the MAC shall be computed
 *  \param[in]     dataLength Length of the data
 *  \param[in]     macPtr Pointer to the MAC
 *  \param[in]     macLengthPtr Length of the provided MAC (output: actual length of the MAC)
 *  \return        SECM_OK Operation successful
 *                 SECM_VER_SIG MAC was wrong
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
SecM_StatusType SecM_MacGenerateJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr,
   SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_RamDataType macPtr, SecM_WordType * macLengthPtr)
{
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   /* Check job range */
   if (jobId < SecM_GetSizeOfJobInfo())
   {
      pJobInfo = &SecM_JobInfo[jobId];

      if (pJobInfo->service == SECM_MACGENERATE)
      {
         if ((mode & SECM_OPERATIONMODE_START) == SECM_OPERATIONMODE_START)
         {
            result = SecM_InitKey(pJobInfo, keyPtr);
         }
         else
         {
            result = SECM_OK;
         }

         if (result == SECM_OK)
         {
            if (Csm_MacGenerate(pJobInfo->csmJobId, mode, dataPtr, dataLength, macPtr, macLengthPtr) != E_OK)
            {
               result = SECM_NOT_OK;
            }
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_JOB_MACGENERATE */

#if defined( SEC_ENABLE_JOB_ENCRYPTION )
/***********************************************************************************************************************
 *  SecM_EncryptionJob
 **********************************************************************************************************************/
/*! \brief         Encrypts the given data
 *  \param[in]     jobId Identifier of the ENCRYPTION job
 *  \param[in]     mode Indicates the operation mode(s)
 *  \param[in]     keyPtr Pointer to the AES key
 *  \param[in]     dataPtr Pointer to the data to be encrypted
 *  \param[in]     dataLength Length of the data
 *  \param[in]     resultPtr Pointer to the data where the encrypted data shall be stored
 *  \param[in,out] resultLengthPtr Length of the provided output buffer (output: actual length encrypted)
 *  \return        SECM_OK Operation successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6060, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */
SecM_StatusType SecM_EncryptionJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr,
   SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_RamDataType resultPtr, SecM_WordType * resultLengthPtr)
{
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;
   SecM_ByteType byteIndex;
   SecM_RamDataType outputData = resultPtr;
   SecM_WordType ivOutputLength = 0u;
   SecM_OperationModeType localMode = mode;
   SecM_ConstRamDataType localDataPtr = dataPtr;
   SecM_WordType localDataLength = dataLength;

   /* Check job range */
   if (jobId < SecM_GetSizeOfJobInfo())
   {
      pJobInfo = &SecM_JobInfo[jobId];

      if (pJobInfo->service == SECM_ENCRYPTION)
      {
         /* Special handling for explicit IV */
         if (SECM_OPERATIONMODE_IV == (localMode & SECM_OPERATIONMODE_IV))
         {
            /* Check that pointers are valid */
            if ((keyPtr != NULL_PTR)
               && (resultLengthPtr != NULL_PTR))
            {
               SecM_CryptographicKeyValuePtrType ivKeyElement;
               SecM_AesKeyType * aesKey;

               ivKeyElement = SecM_GetKeyValueByElementId(pJobInfo->smhKeyId, CRYPTO_KE_CIPHER_IV);
               aesKey = (SecM_AesKeyType*)keyPtr; /* PRQA S 0316 */ /* MD_SecJob_0316 */

               /* Check if there is enough input data to read the IV */
               if ((ivKeyElement != NULL_PTR) && (ivKeyElement->size <= localDataLength))
               {
                  /* Check if the output length is large enough to hold the IV on encryption mode */
                  if (*resultLengthPtr < ivKeyElement->size)
                  {
                     /* Error code already set */
                  }
                  else
                  {
                     /* IV located at beginning of data */
                     aesKey->iv.data = localDataPtr;
                     aesKey->iv.size = ivKeyElement->size;

                     /* Adjust input data */
                     localDataPtr = &localDataPtr[ivKeyElement->size];
                     localDataLength -= ivKeyElement->size;

                     if (localDataLength == 0u)
                     {
                        /* Remove UPDATE mode in case length is 0 */
                        localMode &= ~(SECM_OPERATIONMODE_UPDATE);
                     }

                     /* Copy IV to output buffer */
                     for (byteIndex = 0u; byteIndex < ivKeyElement->size; byteIndex++)
                     {
                        outputData[byteIndex] = aesKey->iv.data[byteIndex];
                     }
                     /* Skip IV in output */
                     outputData = &outputData[ivKeyElement->size];
                     *resultLengthPtr -= ivKeyElement->size;

                     /* Store size of IV */
                     ivOutputLength = ivKeyElement->size;

                     result = SECM_OK;
                  }
               }
            }
         }
         else
         {
            result = SECM_OK;
         }

         if (result == SECM_OK)
         {
            if ((localMode & SECM_OPERATIONMODE_START) == SECM_OPERATIONMODE_START)
            {
               result = SecM_InitKey(pJobInfo, keyPtr);
            }
         }

         if (result == SECM_OK)
         {
            if (Csm_Encrypt(pJobInfo->csmJobId, localMode, localDataPtr, localDataLength, outputData, resultLengthPtr) != E_OK)
            {
               result = SECM_NOT_OK;
            }
         }

         if (result == SECM_OK)
         {
            if (ivOutputLength != 0u)
            {
               /* Add length of IV to output length */
               *resultLengthPtr += ivOutputLength;
            }
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_JOB_ENCRYPTION */

#if defined( SEC_ENABLE_JOB_DECRYPTION ) ||\
    defined( SEC_ENABLE_JOB_AEADDECRYPT )
/***********************************************************************************************************************
 *  SecM_DecryptionJob
 **********************************************************************************************************************/
/*! \brief         Decrypts the given data
 *  \param[in]     jobId Identifier of the DECRYPTION job
 *  \param[in]     mode Indicates the operation mode(s)
 *  \param[in]     keyPtr Pointer to the AES key
 *  \param[in]     dataPtr Pointer to the data to be decrypted
 *  \param[in]     dataLength Length of the data
 *  \param[in]     resultPtr Pointer to the data where the decrypted data shall be stored
 *  \param[in,out] resultLengthPtr Length of the provided output buffer (output: actual length decrypted)
 *  \return        SECM_OK Operation successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6060, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */
SecM_StatusType SecM_DecryptionJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr,
   SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_RamDataType resultPtr, SecM_WordType * resultLengthPtr)
{
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;
   SecM_OperationModeType localMode = mode;
   SecM_ConstRamDataType localDataPtr = dataPtr;
   SecM_WordType localDataLength = dataLength;

   /* Check job range */
   if (jobId < SecM_GetSizeOfJobInfo())
   {
      pJobInfo = &SecM_JobInfo[jobId];

      if ((pJobInfo->service == SECM_DECRYPTION) || (pJobInfo->service == SECM_AEADDECRYPT))
      {
         /* Special handling for explicit IV */
         if (SECM_OPERATIONMODE_IV == (localMode & SECM_OPERATIONMODE_IV))
         {
            localMode &= ~(SECM_OPERATIONMODE_IV);
            /* Check that pointers are valid */
            if (keyPtr != NULL_PTR)
            {
               SecM_CryptographicKeyValuePtrType ivKeyElement;
               SecM_AesKeyType * aesKey;

               ivKeyElement = SecM_GetKeyValueByElementId(pJobInfo->smhKeyId, CRYPTO_KE_CIPHER_IV);
               aesKey = (SecM_AesKeyType*)keyPtr; /* PRQA S 0316 */ /* MD_SecJob_0316 */

               /* Check if there is enough input data to read the IV */
               if ((ivKeyElement != NULL_PTR) && (ivKeyElement->size <= localDataLength))
               {
                  /* IV located at beginning of data */
                  aesKey->iv.data = localDataPtr;
                  aesKey->iv.size = ivKeyElement->size;

                  /* Adjust input data */
                  localDataPtr = &localDataPtr[ivKeyElement->size];
                  localDataLength -= ivKeyElement->size;

                  if (localDataLength == 0u)
                  {
                     /* Remove UPDATE mode in case length is 0 */
                     localMode &= ~(SECM_OPERATIONMODE_UPDATE);
                  }

                  result = SECM_OK;
               }
            }
         }
         else
         {
            result = SECM_OK;
         }

         if (result == SECM_OK)
         {
            if ((localMode & SECM_OPERATIONMODE_START) == SECM_OPERATIONMODE_START)
            {
               result = SecM_InitKey(pJobInfo, keyPtr);
# if defined( SEC_ENABLE_JOB_AEADDECRYPT )
               /* Initialize AEAD Decryption buffers */
               if (pJobInfo->service == SECM_AEADDECRYPT)
               {
                  /* PRQA S 0316 3 */ /* MD_SecJob_0316 */
                  SecM_DecryptAEADInit(pJobInfo);
               }
# endif
            }
         }

         if (result == SECM_OK)
         {
# if defined( SEC_ENABLE_JOB_AEADDECRYPT )
            if (pJobInfo->service == SECM_AEADDECRYPT)
            {
               SecM_WordType currPos = 0u;
               SecM_WordType remData = 0u;
               SecM_WordType tempLength = *resultLengthPtr;
               remData = localDataLength;

               do
               {
                  *resultLengthPtr = tempLength;
                  if (SecM_DecryptAEAD(jobId, &localMode, &localDataPtr[currPos], &localDataLength, resultPtr, resultLengthPtr) != SECM_OK)
                  {
                     result = SECM_NOT_OK;
                  }
                  else
                  {
                     remData -= localDataLength;
                     currPos += localDataLength;
                     localDataLength = remData;
                  }
               } while ((remData != 0u) && (result == SECM_OK));
            }
            else
# endif
            {
               if (Csm_Decrypt(pJobInfo->csmJobId, localMode, localDataPtr, localDataLength, resultPtr, resultLengthPtr) != E_OK)
               {
                  result = SECM_NOT_OK;
               }
            }
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_JOB_DECRYPTION */

#if defined( SEC_ENABLE_JOB_RANDOMGENERATE )
/***********************************************************************************************************************
 *  SecM_RandomGenerateJob
 **********************************************************************************************************************/
/*! \brief         Generates a random number
 *  \param[in]     jobId Identifier of the RANDOM GENERATE job
 *  \param[in]     resultPtr Pointer to the data where the random number shall be stored
 *  \param[in,out] resultLengthPtr Length of the provided buffer (output: actual length of the random number)
 *  \return        SECM_OK Operation successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_RandomGenerateJob(SecM_WordType jobId, SecM_RamDataType resultPtr, SecM_WordType * resultLengthPtr)
{
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   /* Check job range */
   if (jobId < SecM_GetSizeOfJobInfo())
   {
      pJobInfo = &SecM_JobInfo[jobId];

      if (pJobInfo->service == SECM_RANDOMGENERATE)
      {
         if (Csm_RandomGenerate(pJobInfo->csmJobId, resultPtr, resultLengthPtr) == E_OK)
         {
            result = SECM_OK;
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_JOB_RANDOMGENERATE */

#if defined( SEC_ENABLE_JOB_RANDOMSEED )
/***********************************************************************************************************************
 *  SecM_RandomSeedJob
 **********************************************************************************************************************/
/*! \brief         Initializes a random number generator with a random seed
 *  \param[in]     jobId Identifier of the RANDOM SEED job
 *  \param[in]     seedPtr Pointer to the seed
 *  \param[in]     seedLength Length of the provided seed
 *  \return        SECM_OK Operation successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_RandomSeedJob(SecM_WordType jobId, SecM_ConstRamDataType seedPtr, SecM_WordType seedLength)
{
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   /* Check job range */
   if (jobId < SecM_GetSizeOfJobInfo())
   {
      pJobInfo = &SecM_JobInfo[jobId];

      if (pJobInfo->service == SECM_RANDOMSEED)
      {
         if (Csm_RandomSeed(pJobInfo->csmKeyId, seedPtr, seedLength) == E_OK)
         {
            result = SECM_OK;
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_JOB_RANDOMSEED */

#if defined( SEC_ENABLE_JOB_SIGNATUREVERIFY )
/***********************************************************************************************************************
 *  SecM_SignatureVerifyJob
 **********************************************************************************************************************/
/*! \brief         Verifies the signature over the provided data
 *  \param[in]     jobId Identifier of the SIGNATURE VERIFY job
 *  \param[in]     mode Indicates the operation mode(s)
 *  \param[in]     keyPtr Pointer to the signature key
 *  \param[in]     dataPtr Pointer to the data for which the signature shall be verified
 *  \param[in]     dataLength Length of the data
 *  \param[in]     signaturePtr Pointer to the signature
 *  \param[in]     signatureLength Length of the provided signature
 *  \return        SECM_OK Operation successful
 *                 SECM_VER_SIG MAC was wrong
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
SecM_StatusType SecM_SignatureVerifyJob(SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr,
   SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_ConstRamDataType signaturePtr, SecM_WordType signatureLength)
{
   SecM_StatusType result = SECM_NOT_OK;
   Crypto_VerifyResultType verifyResult = CRYPTO_E_VER_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   /* Check job range */
   if (jobId < SecM_GetSizeOfJobInfo())
   {
      pJobInfo = &SecM_JobInfo[jobId];

      if (pJobInfo->service == SECM_SIGNATUREVERIFY)
      {
         if ((mode & SECM_OPERATIONMODE_START) == SECM_OPERATIONMODE_START)
         {
            result = SecM_InitKey(pJobInfo, keyPtr);
         }
         else
         {
            result = SECM_OK;
         }

         if (result == SECM_OK)
         {
            if (Csm_SignatureVerify(pJobInfo->csmJobId, mode, dataPtr, dataLength, signaturePtr, signatureLength, &verifyResult) != E_OK)
            {
               result = SECM_NOT_OK;
            }
         }

         if ((mode & SECM_OPERATIONMODE_FINISH) == SECM_OPERATIONMODE_FINISH)
         {
            /* Check result of verify */
            if ((result == SECM_OK) && (verifyResult != CRYPTO_E_VER_OK))
            {
               result = SECM_VER_SIG;
            }
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_JOB_SIGNATUREVERIFY */

#if defined( SEC_ENABLE_JOB_AEADENCRYPT )
/**********************************************************************************************************************
 *  SecM_AEADEncrypt_Job()
 *********************************************************************************************************************/
/*! \brief         Uses the given input data to perform a AEAD encryption and stores the ciphertext and the MAC in the
 *                 memory locations pointed by the ciphertext pointer and Tag pointer.
 *  \details       -
 *  \param[in]     jobId                Identifier of the AEAD ENCRYPT job
 *  \param[in]     mode                 Indicates which operation mode(s) to perform.
 *  \param[in]     plaintextPtr         Contains the pointer to the data to be encrypted.
 *  \param[in]     plaintextLength      Contains the number of bytes to encrypt.
 *  \param[in]     associatedDataPtr    Contains the pointer to the associated data.
 *  \param[in]     associatedDataLength Contains the number of bytes of the associated data.
 *  \param[out]    ciphertextPtr        Contains the pointer to the data where the encrypted data shall be stored.
 *  \param[in,out] ciphertextLengthPtr  Holds a pointer to the memory location in which the output length in bytes of
 *                                      the ciphertext is stored. On calling this function, this parameter shall
 *                                      contain the size of the buffer in bytes provided by resultPtr. When the request
 *                                      has finished, the actual length of the returned value shall be stored.
 *  \param[out]    tagPtr               Contains the pointer to the data where the Tag shall be stored.
 *  \param[in,out] tagLengthPtr         Holds a pointer to the memory location in which the output length in bytes of
 *                                      the Tag is stored. On calling this function, this parameter shall contain the
 *                                      size of the buffer in bytes provided by resultPtr. When the request has
 *                                      finished, the actual length of the returned value shall be stored.
 *  \return        SECM_OK              Request successful
 *                 SECM_NOT_OK          Request failed
 *********************************************************************************************************************/
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
SecM_StatusType SecM_AEADEncrypt_Job(SecM_WordType jobId,  SecM_OperationModeType mode,
   SecM_ConstRamDataType plaintextPtr, SecM_WordType plaintextLength,
   SecM_ConstRamDataType associatedDataPtr, SecM_WordType associatedDataLength,
   SecM_RamDataType ciphertextPtr, SecM_RamWordType ciphertextLengthPtr,
   SecM_RamDataType tagPtr, SecM_RamWordType tagLengthPtr)
{
   SecM_StatusType result = SECM_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   /* Check job range */
   if (jobId < SecM_GetSizeOfJobInfo())
   {
      pJobInfo = &SecM_JobInfo[jobId];

      if (pJobInfo->service == SECM_AEADENCRYPT)
      {
         if (Csm_AEADEncrypt(pJobInfo->csmJobId, mode, plaintextPtr, plaintextLength, associatedDataPtr,
            associatedDataLength, ciphertextPtr, ciphertextLengthPtr, tagPtr, tagLengthPtr) == E_OK)
         {
            result = SECM_OK;
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_JOB_AEADENCRYPT */

#if defined( SEC_ENABLE_JOB_AEADDECRYPT )
/**********************************************************************************************************************
 *  SecM_AEADDecrypt_Job()
 *********************************************************************************************************************/
/*! \brief         Uses the given data to perform an AEAD decryption and stores the plaintext and the result of
 *                 verification in the memory locations pointed by the plaintext pointer and verifyPtr pointer.
 *  \details       -
 *  \param[in]     jobId                Identifier of the AEAD DECRYPT job
 *  \param[in]     mode                 Indicates which operation mode(s) to perform.
 *  \param[in]     ciphertextPtr        Contains the pointer to the data to be decrypted.
 *  \param[in]     ciphertextLength     Contains the number of bytes to decrypt.
 *  \param[in]     associatedDataPtr    Contains the pointer to the associated data.
 *  \param[in]     associatedDataLength Contains the number of bytes of the associated data.
 *  \param[in]     tagPtr               Contains the pointer to the data where the Tag shall be stored.
 *  \param[in]     tagLength            Contains the length in bytes of the Tag to be verified.
 *  \param[out]    plaintextPtr         Contains the pointer to the data where the encrypted data shall be stored.
 *  \param[in,out] plaintextLengthPtr   Holds a pointer to the memory location in which the output length in bytes of
 *                                      the ciphertext is stored. On calling this function, this parameter shall
 *                                      contain the size of the buffer in bytes provided by resultPtr. When the request
 *                                      has finished, the actual length of the returned value shall be stored.
 *  \param[out]    verifyPtr            Contains the pointer to the result of the verification.
 *  \return        SECM_OK              Request successful
 *                 SECM_NOT_OK          Request failed
 **********************************************************************************************************************/
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
SecM_StatusType SecM_AEADDecrypt_Job(SecM_WordType jobId, SecM_OperationModeType mode,
   SecM_ConstRamDataType ciphertextPtr, SecM_WordType ciphertextLength,
   SecM_ConstRamDataType associatedDataPtr, SecM_WordType associatedDataLength,
   SecM_ConstRamDataType tagPtr, SecM_WordType tagLength,
   SecM_RamDataType plaintextPtr, SecM_RamWordType plaintextLengthPtr)
{
   SecM_StatusType result = SECM_NOT_OK;
   Crypto_VerifyResultType verifyResult = CRYPTO_E_VER_NOT_OK;
   SecM_JobInfoPtrType pJobInfo;

   /* Check job range */
   if (jobId < SecM_GetSizeOfJobInfo())
   {
      pJobInfo = &SecM_JobInfo[jobId];

      if (pJobInfo->service == SECM_AEADDECRYPT)
      {
         if (Csm_AEADDecrypt(pJobInfo->csmJobId, mode, ciphertextPtr, ciphertextLength, associatedDataPtr,
            associatedDataLength, tagPtr, tagLength, plaintextPtr, plaintextLengthPtr, &verifyResult) == E_OK)
         {
            result = SECM_OK;
         }
         if ((mode & SECM_OPERATIONMODE_FINISH) == SECM_OPERATIONMODE_FINISH)
         {
            /* Check result of verify */
            if ((result == SECM_OK) && (verifyResult != CRYPTO_E_VER_OK))
            {
               result = SECM_NOT_OK;
            }
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_JOB_AEADDECRYPT */

#if defined( SEC_ENABLE_JOB_KEYDERIVE )
/**********************************************************************************************************************
 *  SecM_KeyDeriveJob()
 *********************************************************************************************************************/
/*! \brief         Uses the given data to perform a key derive operation and stores the derived key
 *                 in the memory location pointed to by the resultPtr pointer.
 *  \details       -
 *  \param[in]     jobId                Identifier of the key derive job
 *  \param[in]     keyPtr               Contains the pointer to the key parameters used for the key derive.
 *  \param[out]    resultPtr            Pointer to the buffer where the derived key shall be stored.
 *  \param[in,out] resultLengthPtr      Holds a pointer to the memory location where the output length (in bytes) of
 *                                      the derived key is stored. On calling this function, this parameter shall
 *                                      contain the size of the buffer in bytes provided by resultPtr. When the request
 *                                      has finished, the actual length of the returned value shall be stored.
 *  \return        SECM_OK              Request successful
 *                 SECM_NOT_OK          Request failed
 **********************************************************************************************************************/
/* PRQA S 6010, 6030 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC */
SecM_StatusType SecM_KeyDeriveJob(SecM_WordType jobId, SecM_VoidPtrType keyPtr, SecM_RamDataType resultPtr, SecM_RamWordType resultLengthPtr)
{
   SecM_StatusType result = SECM_NOT_OK;
   vuintx idx = 0u;

   /* Check job range */
   if (jobId < SecM_GetSizeOfJobInfo())
   {
      SecM_JobInfoPtrType pJobInfo = &SecM_JobInfo[jobId];

      /* Always initialize "key" used as input in case of key derive */
      if (pJobInfo->service == SECM_KEYDERIVE)
      {
         result = SecM_InitKey(pJobInfo, keyPtr);
      }

      if (result == SECM_OK)
      {
         result = SECM_NOT_OK;

         /* Get key derive primitive based on Smh job */
         for (idx = 0u; idx < SecM_GetSizeOfKeyDerivePrimitives(); idx++)
         {
            if (SecM_KeyDerivePrimitives[idx].jobId == jobId)
            {
               result = SECM_OK;
               break;
            }
         }
      }

      if (result == SECM_OK)
      {
         /* Derive key. Target key is given by the key derive primitive */
         if (Csm_JobKeyDerive(pJobInfo->csmJobId, pJobInfo->csmKeyId, SecM_KeyDerivePrimitives[idx].targetKeyId) != E_OK)
         {
            result = SECM_NOT_OK;
         }
      }

      /* Only get derived key if derive was successful and target buffer/length indication are not NULL pointers */
      if ((result == SECM_OK) && (resultPtr != NULL_PTR) && (resultLengthPtr != NULL_PTR))
      {
         /* If desired length is 0 do not retrieve key */
         if (*resultLengthPtr != 0u)
         {
            /* Retrieve derived key from CSM. Element ID of target key is always 1 */
            if (Csm_KeyElementGet(SecM_KeyDerivePrimitives[idx].targetKeyId, 1u, resultPtr, resultLengthPtr) != E_OK)
            {
               result = SECM_NOT_OK;
            }
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_JOB_KEYDERIVE */

#if defined( SEC_ENABLE_KEY_OPERATION_ACCESS )
/***********************************************************************************************************************
 *  SecM_KeyElementSet
 **********************************************************************************************************************/
/*! \brief         Initializes the given key element
 *  \param[in]     csmKeyId CSM Key Id
 *  \param[in]     keyElementId Key element ID
 *  \param[in]     keyPtr Pointer to the key.
 *  \param[in]     keyLength Length of the key
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_KeyElementSet(uint32 csmKeyId, uint32 keyElementId, SecM_ConstRamDataType keyPtr, SecM_WordType keyLength)
{
   SecM_StatusType result = SECM_NOT_OK;

   if (Csm_KeyElementSet(csmKeyId, keyElementId, keyPtr, keyLength) == E_OK)
   {
      if (Csm_KeySetValid(csmKeyId) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  SecM_KeyElementGet
 **********************************************************************************************************************/
/*! \brief         Returns the given key element
 *  \param[in]     csmKeyId CSM Key Id
 *  \param[in]     keyElementId Key element ID
 *  \param[out]    keyPtr Pointer to the key.
 *  \param[in,out] keyLengthPtr Length of the key
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_KeyElementGet(uint32 csmKeyId, uint32 keyElementId, SecM_RamDataType keyPtr, SecM_RamWordType keyLengthPtr)
{
   SecM_StatusType result = SECM_NOT_OK;

   if (Csm_KeyElementGet(csmKeyId, keyElementId, keyPtr, keyLengthPtr) == E_OK)
   {
      result = SECM_OK;
   }

   return result;
}
#endif /* SEC_ENABLE_KEY_OPERATION_ACCESS */

#if defined( SEC_ENABLE_KEY_OPERATION_COPY )
/***********************************************************************************************************************
 *  SecM_KeyCopy
 **********************************************************************************************************************/
/*! \brief         Copy a complete key (with all referenced key elements)
 *  \param[in]     csmSourceKeyId CSM Key Id of source key
 *  \param[in]     csmTargetKeyId CSM Key Id of target key
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_KeyCopy(uint32 csmSourceKeyId, uint32 csmTargetKeyId)
{
   SecM_StatusType result = SECM_NOT_OK;

   if (Csm_KeyCopy(csmSourceKeyId, csmTargetKeyId) == E_OK)
   {
      if (Csm_KeySetValid(csmTargetKeyId) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif /* SEC_ENABLE_KEY_OPERATION_COPY */

#if defined( SEC_ENABLE_KEY_OPERATION_ELEMENT_COPY )
/***********************************************************************************************************************
 *  SecM_KeyElementCopy
 **********************************************************************************************************************/
/*! \brief         Copy a single key element
 *  \param[in]     csmSourceKeyId CSM Key Id of source key
 *  \param[in]     csmTargetKeyId CSM Key Id of target key
 *  \param[in]     keyElementId Key element ID
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_KeyElementCopy(uint32 csmSourceKeyId, uint32 csmTargetKeyId, uint32 keyElementId)
{
   SecM_StatusType result = SECM_NOT_OK;

   if (Csm_KeyElementCopy(csmSourceKeyId, keyElementId, csmTargetKeyId, keyElementId) == E_OK)
   {
      if (Csm_KeySetValid(csmTargetKeyId) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif /* SEC_ENABLE_KEY_OPERATION_ELEMENT_COPY */

#if defined( SEC_ENABLE_SAVE_RESTORE_CONTEXT ) && defined( SEC_ENABLE_CSM )
/***********************************************************************************************************************
 *  SecM_SaveContextCsm
 **********************************************************************************************************************/
/*! \brief         Save the context of a job
 *  \param[in]     csmJobId Job ID of the related CSM job
 *  \param[out]    contextBuffer buffer to save the context to
 *  \param[in,out] contextBufferLengthPtr Length of the provided buffer (output: actual length of saved context)
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_SaveContextCsm(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_RamWordType contextBufferLengthPtr)
{
   SecM_StatusType result = SECM_NOT_OK;

   if (Csm_SaveContextJob(csmJobId, contextBuffer, contextBufferLengthPtr) == E_OK)
   {
      result = SECM_OK;
   }

   return result;
}

# if defined( SEC_ENABLE_SAVE_RESTORE_HASH )
/***********************************************************************************************************************
 *  SecM_RestoreContextHash
 **********************************************************************************************************************/
/*! \brief         Restore the context of a Hash job
 *  \param[in]     csmJobId Job ID of the related CSM job
 *  \param[in]     contextBuffer buffer to restore the context from
 *  \param[in]     contextBufferLengthPtr Length of the provided context
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_RestoreContextHash(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength)
{
   SecM_StatusType result = SECM_NOT_OK;

   /* Start job */
   if (Csm_Hash(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, NULL_PTR) == E_OK)
   {
      /* Restore context */
      if (Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
# endif /* SEC_ENABLE_SAVE_RESTORE_HASH */

# if defined( SEC_ENABLE_SAVE_RESTORE_ENCRYPT )
/***********************************************************************************************************************
 *  SecM_RestoreContextEncryption
 **********************************************************************************************************************/
/*! \brief         Restore the context of an Encryption job
 *  \param[in]     csmJobId Job ID of the related CSM job
 *  \param[in]     contextBuffer buffer to restore the context from
 *  \param[in]     contextBufferLengthPtr Length of the provided context
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_RestoreContextEncryption(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength)
{
   SecM_StatusType result = SECM_NOT_OK;

   /* Start job */
   if (Csm_Encrypt(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, NULL_PTR) == E_OK)
   {
      /* Restore context */
      if (Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif /* SEC_ENABLE_SAVE_RESTORE_ENCRYPT */

#if defined( SEC_ENABLE_SAVE_RESTORE_DECRYPT )
/***********************************************************************************************************************
 *  SecM_RestoreContextDecryption
 **********************************************************************************************************************/
/*! \brief         Restore the context of a Decryption job
 *  \param[in]     csmJobId Job ID of the related CSM job
 *  \param[in]     contextBuffer buffer to restore the context from
 *  \param[in]     contextBufferLengthPtr Length of the provided context
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_RestoreContextDecryption(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength)
{
   SecM_StatusType result = SECM_NOT_OK;

   /* Start job */
   if (Csm_Decrypt(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, NULL_PTR) == E_OK)
   {
      /* Restore context */
      if (Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif /* SEC_ENABLE_SAVE_RESTORE_DECRYPT */

#if defined( SEC_ENABLE_SAVE_RESTORE_MAC_GENERATE )
/***********************************************************************************************************************
 *  SecM_RestoreContextMacGenerate
 **********************************************************************************************************************/
/*! \brief         Restore the context of a MAC Generate job
 *  \param[in]     csmJobId Job ID of the related CSM job
 *  \param[in]     contextBuffer buffer to restore the context from
 *  \param[in]     contextBufferLengthPtr Length of the provided context
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_RestoreContextMacGenerate(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength)
{
   SecM_StatusType result = SECM_NOT_OK;

   /* Start job */
   if (Csm_MacGenerate(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, NULL_PTR) == E_OK)
   {
      /* Restore context */
      if (Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif /* SEC_ENABLE_SAVE_RESTORE_MAC_GENERATE */

#if defined( SEC_ENABLE_SAVE_RESTORE_MAC_VERIFY )
/***********************************************************************************************************************
 *  SecM_RestoreContextMacVerify
 **********************************************************************************************************************/
/*! \brief         Restore the context of a MAC Verify job
 *  \param[in]     csmJobId Job ID of the related CSM job
 *  \param[in]     contextBuffer buffer to restore the context from
 *  \param[in]     contextBufferLengthPtr Length of the provided context
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_RestoreContextMacVerify(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength)
{
   SecM_StatusType result = SECM_NOT_OK;

   /* Start job */
   if (Csm_MacVerify(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, 0u, NULL_PTR) == E_OK)
   {
      /* Restore context */
      if (Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
#endif /* SEC_ENABLE_SAVE_RESTORE_MAC_VERIFY */

# if defined( SEC_ENABLE_SAVE_RESTORE_SIG_VERIFY )
/***********************************************************************************************************************
 *  SecM_RestoreContextSignatureVerify
 **********************************************************************************************************************/
/*! \brief         Restore the context of a Signature Verify job
 *  \param[in]     csmJobId Job ID of the related CSM job
 *  \param[in]     contextBuffer buffer to restore the context from
 *  \param[in]     contextBufferLengthPtr Length of the provided context
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_RestoreContextSignatureVerify(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength)
{
   SecM_StatusType result = SECM_NOT_OK;

   /* Start job */
   if (Csm_SignatureVerify(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, 0u, NULL_PTR) == E_OK)
   {
      /* Restore context */
      if (Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
# endif /* SEC_ENABLE_SAVE_RESTORE_SIG_VERIFY */

# if defined( SEC_ENABLE_SAVE_RESTORE_AEAD_ENCRYPT )
/***********************************************************************************************************************
 *  SecM_RestoreContextAEADEncrypt
 **********************************************************************************************************************/
/*! \brief         Restore the context of an AEAD Encrypt job
 *  \param[in]     csmJobId Job ID of the related CSM job
 *  \param[in]     contextBuffer buffer to restore the context from
 *  \param[in]     contextBufferLengthPtr Length of the provided context
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_RestoreContextAEADEncrypt(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength)
{
   SecM_StatusType result = SECM_NOT_OK;

   /* Start job */
   if (Csm_AEADEncrypt(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, 0u, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR) == E_OK)
   {
      /* Restore context */
      if (Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
# endif /* SEC_ENABLE_SAVE_RESTORE_AEAD_ENCRYPT */

# if defined( SEC_ENABLE_SAVE_RESTORE_AEAD_DECRYPT )
/***********************************************************************************************************************
 *  SecM_RestoreContextAEADDecrypt
 **********************************************************************************************************************/
/*! \brief         Restore the context of an AEAD Decrypt job
 *  \param[in]     csmJobId Job ID of the related CSM job
 *  \param[in]     contextBuffer buffer to restore the context from
 *  \param[in]     contextBufferLengthPtr Length of the provided context
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_RestoreContextAEADDecrypt(uint32 csmJobId, SecM_RamDataType contextBuffer, SecM_WordType contextBufferLength)
{
   SecM_StatusType result = SECM_NOT_OK;

   /* Start job */
   if (Csm_AEADDecrypt(csmJobId, CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, 0u, NULL_PTR, 0u, NULL_PTR, NULL_PTR, NULL_PTR) == E_OK)
   {
      /* Restore context */
      if (Csm_RestoreContextJob(csmJobId, contextBuffer, contextBufferLength) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}
# endif /* SEC_ENABLE_SAVE_RESTORE_AEAD_DECRYPT */
#endif /* SEC_ENABLE_SAVE_RESTORE_CONTEXT && SEC_ENABLE_CSM */

#if (defined( SEC_ENABLE_CSM ) && (SecM_GetSizeOfJobInfo() > 0u))
/***********************************************************************************************************************
 *  SecM_CancelAllJobs
 **********************************************************************************************************************/
/*! \brief         Requests cancel of all configured Jobs
 **********************************************************************************************************************/
void SecM_CancelAllJobs(void)
{
   SecM_ByteFastType i;

   for (i = 0u; i < SecM_GetSizeOfJobInfo(); i++)
   {
      if (SecM_JobInfo[i].csmJobId != SEC_INVALID_CSM_JOB_ID)
      {
         (void)Csm_CancelJob(SecM_JobInfo[i].csmJobId, 0u);
      }
   }
}
#endif /* SEC_ENABLE_CSM && SecM_GetSizeOfJobInfo() > 0u */

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_SecJob_0316:
      Reason:     The job functions have a void pointer as a key parameter, which are casted to the correct type.
      Risk:       No risk, because the underlying pointer type is known and the cast is safe.
      Prevention: No prevention necessary.

   MD_SecJob_2880:
      Reason:     If this code is reached or not depends on the configuration.
      Risk:       No risk.
      Prevention: No prevention necessary.

   MD_SecJob_2991_2992_2995_2996:
      Reason:     The value of the if-controlling expression or logical operation depends on the configuration.
      Risk:       No risk.
      Prevention: No prevention necessary.

   MD_SecJob_3218:
      Reason:     The local variables of this module are kept at a central location for a better overview and maintenance.
      Risk:       Scope is larger than required (whole file instead of one function). Some other function could access
                  the variable.
      Prevention: Restrict the functionality in this module to the intended purpose. Don't add functions which shall not
                  be able to access the local data buffers.

*/

/***********************************************************************************************************************
 *  END OF FILE: SEC.C
 **********************************************************************************************************************/

