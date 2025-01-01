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
/*!        \file  Crypto_30_Hwa_Crypto.c
 *        \brief  Crypto Hwa shared crypto functionality
 *
 *      \details  This implements functionality that is shared between crypto primitives
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_CRYPTO_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Crypto_30_Hwa.h"
#include "Crypto_30_Hwa_Hw.h"
#include "Crypto_30_Hwa_Private.h"
#include "Crypto_30_Hwa_Custom.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (CRYPTO_30_HWA_LOCAL) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL                                              static
#endif

#if !defined (CRYPTO_30_HWA_LOCAL_INLINE) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL_INLINE                                       LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_ESL_RETVAL(x)                                        (uint8)((x == ESL_ERC_NO_ERROR) ? E_OK : E_NOT_OK)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#if (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
# define CRYPTO_30_HWA_START_SEC_CONST_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

 /* ASCII-Hex interpretation of the string "SigEd25519 no Ed25519 collisions" */
CRYPTO_30_HWA_LOCAL CONST(uint8, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_Dom2_Data[CRYPTO_30_HWA_EDDSA_ED25519_DOM2_LENGTH] = /* PRQA S 3218 */ /* MD_CRYPTO_30_HWA_3218_DOM2_DATA */
{
  0x53, 0x69, 0x67, 0x45, 0x64, 0x32, 0x35, 0x35, 0x31, 0x39, 0x20, 0x6e, 0x6f, 0x20, 0x45, 0x64,
  0x32, 0x35, 0x35, 0x31, 0x39, 0x20, 0x63, 0x6f, 0x6c, 0x6c, 0x69, 0x73, 0x69, 0x6f, 0x6e, 0x73
};

# define CRYPTO_30_HWA_STOP_SEC_CONST_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_GCMSIV == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_MacCompare()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Crypto_VerifyResultType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_MacCompare(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) mac1,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) mac2,
  uint32 lengthInBit)
{
  volatile Crypto_VerifyResultType result = CRYPTO_E_VER_OK;
  volatile Crypto_VerifyResultType dummyResult = CRYPTO_E_VER_OK;
  uint8 verifyBitMask;
  uint32 numberBitsInLastByte;
  uint8 numberOfFullBytesInMac = (uint8)(lengthInBit >> 3u);
  uint8_least i;

  /* #10 Compare full bytes of both MACs. */
  for (i = 0u; i < (numberOfFullBytesInMac); i++)
  {
    if (mac1[i] != mac2[i])
    {
      /* Verification does not match */
      result = CRYPTO_E_VER_NOT_OK;
    }
    else
    {
      /* This is for obfuscation of branches and their runtimes */
      dummyResult = CRYPTO_E_VER_NOT_OK;
    }
  }

  /* #20 Compare remaining bits. */
  /* Compute number of bits to verify in the last byte */
  numberBitsInLastByte = CRYPTO_30_HWA_MODULO_8(lengthInBit);  /* Calculate modulo */
  if (numberBitsInLastByte != 0u)
  {
    /* #21 Generate bit mask which contains all bits to be verified */
    verifyBitMask = (uint8)~((1u << (8u - numberBitsInLastByte)) - 1u);

    /* #22 Verify the last masked byte */
    if ((mac1[numberOfFullBytesInMac] & verifyBitMask)
      != (mac2[numberOfFullBytesInMac] & verifyBitMask))
    {
      result = CRYPTO_E_VER_NOT_OK;
    }
    else
    {
      /* This is for obfuscation of branches and their runtimes */
      dummyResult = CRYPTO_E_VER_NOT_OK;
    }
  }

  CRYPTO_30_HWA_DUMMY_STATEMENT(dummyResult); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return result;
} /* Crypto_30_Hwa_MacCompare() */ /*lint !e550 */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_GCMSIV == STD_ON)) */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_ArrayToUint32()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(uint32, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ArrayToUint32(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) source)
{
  /* Copy 4 byte array to Uint32 */
  return ((uint32)source[0] | (((uint32)source[1]) << 8u) | (((uint32)source[2]) << 16u) | (((uint32)source[3]) << 24u));
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Uint32ToArray()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Uint32ToArray(
  uint32 source,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) destination)
{
  /* Copy Uint32 to Array */
  destination[0] = (uint8)(source & 0xFFu);
  destination[1] = (uint8)((source >> 8u) & 0xFFu);
  destination[2] = (uint8)((source >> 16u) & 0xFFu);
  destination[3] = (uint8)((source >> 24u));
}

#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_CheckRomKeyUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckRomKeyUsage(
  uint32 keyID,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) romKeyMapIndex)
{
  /* #10 Verify whether hardware key or imported key is used */
  if (keyID >= CRYPTO_30_HWA_ROMKEY_MASK)
  {
    /* Store corresponding key index in workspace */
    *romKeyMapIndex = keyID - CRYPTO_30_HWA_ROMKEY_MASK;
  }
  else
  {
    /* #20 Set key index to a value that indicates that no hardware key is used */
    *romKeyMapIndex = CRYPTO_30_HWA_ROMKEY_USE_IMPORTED_KEY;
  }

} /* Crypto_30_Hwa_CheckRomKeyUsageAead() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* (CRYPTO_30_HWA_ROMKEY == STD_ON) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_IsBignumZeroBe()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_IsBignumZeroBe(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) a,
  const uint32 length)
{
  boolean compareReturnValue = TRUE;
  uint32 i;

  for (i = 0u; i < length; i++)
  {
    if (compareReturnValue == TRUE)
    {
      if (a[i] == 0u)
      {
        compareReturnValue = TRUE;
      }
      else
      {
        compareReturnValue = FALSE;
      }
    }
  }

  return compareReturnValue;
}
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) */

#if (CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_CompareBignumsBe()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CompareBignumsBe(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) a,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) b,
  const uint32 length)
{
  uint8 compareReturnValue = CRYPTO_30_HWA_ECDSA_BIGNUM_EQUAL;
  uint32 i;

  for (i = 0u; i < length; i++)
  {
    if (compareReturnValue == CRYPTO_30_HWA_ECDSA_BIGNUM_EQUAL)
    {
      if (a[i] < b[i])
      {
        compareReturnValue = CRYPTO_30_HWA_ECDSA_BIGNUM_SMALLER;
      }
      else if (a[i] > b[i])
      {
        compareReturnValue = CRYPTO_30_HWA_ECDSA_BIGNUM_LARGER;
      }
      else
      {
        /* Do nothing. Return value already set. */
      }
    }
  }

  return compareReturnValue;
}
#endif /* (CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) */

#if (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessDom2Data()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessDom2Data(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) context,
  uint32 contextLength)
{
  Std_ReturnType retVal;

  /* Process DOM2 tag */
  uint8 ph_len[2] = {0u, 0u};

  /* #10 If mode is PH, set ph_len index to 1 */
  if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PH)
  {
    ph_len[0] = 1u;
  }

  /* #11 If context is provided, set ph_len index to length of context */
  if (context != NULL_PTR)
  {
    ph_len[1] = (uint8)(contextLength & 0xFFu);
  }

  /* #12 Update hash calculation with dom2 value and ph_len */
  retVal = CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_ED25519_DOM2_LENGTH, Crypto_30_Hwa_Dom2_Data));
  retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, 2u, ph_len));

  if (context != NULL_PTR)
  {
    if (contextLength != 0u)
    {
      retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, contextLength, context));
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}
#endif /* (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Crypto.c
 *********************************************************************************************************************/
