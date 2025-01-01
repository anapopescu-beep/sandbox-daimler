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
/*!        \file  Crypto_30_Hwa_Mac.c
 *        \brief  Crypto Hwa Mac implementation
 *
 *      \details  This implements the Mac crypto algorithm.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_MAC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Crypto_30_Hwa.h"
#include "Crypto_30_Hwa_Hw.h"
#include "Crypto_30_Hwa_Private.h"

#include "vHsm_Api.h"
#include "vstdlib.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (CRYPTO_30_HWA_LOCAL) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL                                               static
#endif

#if !defined (CRYPTO_30_HWA_LOCAL_INLINE) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL_INLINE                                        LOCAL_INLINE
#endif

/* Defines for AES */
#define CRYPTO_30_HWA_AES_CMAC_CONST_RB                                    (0x87u)
#define CRYPTO_30_HWA_AES_CMAC_MSB_BITMASK                                 (0x80u)
#define CRYPTO_30_HWA_AES_LAST_ELEMENT                                     (CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES - 1u)
#define CRYPTO_30_HWA_CMAC_TAG_SIZE_BIT                                    (128u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_CmacStart()
 *********************************************************************************************************************/
/*! \brief          Initializes CMAC generation.
 *  \details        -
 *  \param[in,out]  workspace          CMAC Workspace.
 *  \param[in]      cryptoKeyId        Crypto Key ID for CMAC.
 *  \return         E_OK               Starting was successful.
 *                  E_NOT_OK           Starting failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CmacStart(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  uint32 cryptoKeyId);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CmacUpdate()
 *********************************************************************************************************************/
/*! \brief          Performs CMAC operation on the input data.
 *  \details        -
 *  \param[in,out]  workspace          CMAC Workspace.
 *  \param[in]      dataPtr            Input data buffer.
 *  \param[in]      dataLength         Output data length.
 *  \param[in]      isFinish           Indicated if this is the last call with new data.
 *  \return         E_OK               Update was successful.
 *                  E_NOT_OK           Update failed.
 *  \pre            Crypto_30_Hwa_CmacStart() called before.
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CmacUpdate(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) dataPtr,
  uint32 dataLength,
  boolean isFinish);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CmacFinish()
 *********************************************************************************************************************/
/*! \brief          Finishes CMAC generation.
 *  \details        Adds padding, processes last block, outputs CMAC of input data.
 *  \param[in,out]  workspace          CMAC Workspace.
 *  \param[out]     resultPtr          Output data buffer. Buffer needs at least
 *                                     CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES free space.
 *  \return         E_OK               Finish was successful.
 *                  E_NOT_OK           Finish failed.
 *  \pre            Crypto_30_Hwa_CmacStart() called before.
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CmacFinish(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) resultPtr);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CmacProcessBlocksSlicing()
 *********************************************************************************************************************/
/*! \brief         Splits data blocks according a threashold and sends it to the hardware
 *  \details        -
 *  \param[in,out]  workspace          CMAC workspace.
 *  \param[in]      in                 Pointer to input data with (blockCount * CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES) bytes.
 *  \param[in]      blockCount         Number of complete blocks that should be processed. Must be at least 1.
 *  \return         E_OK               Processing was successful.
 *                  E_NOT_OK           Processing failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CmacProcessBlocksSlicing(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in,
  uint32 blockCount);

# if (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_CmacSubKeyGeneration_k1()
 *********************************************************************************************************************/
/*! \brief          Generate the k1 CMAC subkey for a given key.
 *  \details        -
 *  \param[in,out]  workspace          CMAC Workspace.
 *  \param[in]      key                Input key buffer. Length must be CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES.
 *  \return         E_OK               Subkey generation was successful.
 *                  E_NOT_OK           Subkey generation failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CmacSubKeyGeneration_k1(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CmacSubKeyGeneration_k2()
 *********************************************************************************************************************/
/*! \brief          Generate the k2 CMAC subkey.
 *  \details        -
 *  \param[in,out]  workspace          CMAC Workspace.
 *  \pre            Crypto_30_Hwa_CmacSubKeyGeneration_k1() must be called before without error.
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CmacSubKeyGeneration_k2(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace);
# endif /* (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
# if (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_CmacSubKeyGeneration_k1()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CmacSubKeyGeneration_k1(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 msb;
  uint8_least i;

  /* Prepare buffer */
  VStdLib_MemClr(workspace->k1, CRYPTO_30_HWA_AES_KEY_SIZE); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  /* Reset and setup AES accelerator with key */
  /* L := AES-128(K, const_Zero); */
  SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
  retVal = Crypto_30_Hwa_Hw_CmacSubkeys(workspace, key);
  SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();

  if (retVal == E_OK)
  {
    /* if MSB(L) is equal to 0
    then    K1 : = L << 1;
    else    K1 : = (L << 1) XOR const_Rb; */
    msb = workspace->k1[0] & (uint8)CRYPTO_30_HWA_AES_CMAC_MSB_BITMASK;
    for (i = 0u; i < CRYPTO_30_HWA_AES_LAST_ELEMENT; i++)
    {
      workspace->k1[i] = (uint8)((workspace->k1[i] << 1u) | (workspace->k1[i + 1u] >> 7u));
    }
    workspace->k1[CRYPTO_30_HWA_AES_LAST_ELEMENT] = (uint8)(workspace->k1[CRYPTO_30_HWA_AES_LAST_ELEMENT] << 1u);

    if (msb != 0u)
    {
      workspace->k1[CRYPTO_30_HWA_AES_KEY_SIZE - 1u] ^= CRYPTO_30_HWA_AES_CMAC_CONST_RB;
    }
  }

  return retVal;
} /* Crypto_30_Hwa_CmacSubKeyGeneration_k1() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CmacSubKeyGeneration_k2()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CmacSubKeyGeneration_k2(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace)
{
  uint8 msb;
  uint8_least i;

  /* if MSB(K1) is equal to 0
  then    K2 : = K1 << 1;
  else    K2 : = (K1 << 1) XOR const_Rb; */
  msb = workspace->k1[0] & (uint8)CRYPTO_30_HWA_AES_CMAC_MSB_BITMASK;
  for (i = 0u; i < CRYPTO_30_HWA_AES_LAST_ELEMENT; i++)
  {
    workspace->k2[i] = (uint8)((workspace->k1[i] << 1u) | (workspace->k1[i + 1u] >> 7u));
  }
  workspace->k2[CRYPTO_30_HWA_AES_LAST_ELEMENT] = (uint8)(workspace->k1[CRYPTO_30_HWA_AES_LAST_ELEMENT] << 1u);

  if (msb != 0u)
  {
    workspace->k2[CRYPTO_30_HWA_AES_KEY_SIZE - 1u] ^= CRYPTO_30_HWA_AES_CMAC_CONST_RB;
  }
} /* Crypto_30_Hwa_CmacSubKeyGeneration_k2() */
# endif /* (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CmacProcessBlocksSlicing()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CmacProcessBlocksSlicing(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in,
  uint32 blockCount)
{
  Std_ReturnType retVal = E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
#if (CRYPTO_30_HWA_DATA_SLICING == STD_ON)
  uint32 i;
  uint32 offset;
  uint32 reminder = blockCount % CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES;

  /* Process multiples of CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE */
  for (i = 0; i < (blockCount / CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES); ++i)
  {
    offset = i * CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES * CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES;
    SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
    retVal |= Crypto_30_Hwa_Hw_CmacProcessBlocks(workspace, &in[offset], CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES);
    SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
  }

  /* Process not multiples of CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE */
  if (reminder > 0u)
  {
    offset = i * CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES * CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES;
    SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
    retVal |= Crypto_30_Hwa_Hw_CmacProcessBlocks(workspace, &in[offset], reminder);
    SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
  }

#else
  retVal = Crypto_30_Hwa_Hw_CmacProcessBlocks(workspace, in, blockCount);
#endif /* (CRYPTO_30_HWA_DATA_SLICING == STD_ON) */

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CmacStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CmacStart(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  uint32 cryptoKeyId)
{
  Std_ReturnType retVal = E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  vHsm_Api_KeyStorageIndexType index = 0u;
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key = NULL_PTR; /* PRQA S 2981 */ /* MD_CRYPTO_30_HWA_2981_REDUNDANT_INITIALIZATION */
  uint8 serviceType;

#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  workspace->romKeyMapIndex = 0u;
#endif  /* if (CRYPTO_30_HWA_ROMKEY == STD_ON) */

  /* #20 Init workspace */
  workspace->bufferFillLevel = 0u;
  workspace->cryptoKeyId = cryptoKeyId;

  if (workspace->primitiveInfo->service == CRYPTO_MACGENERATE)
  {
    serviceType = VHSM_API_SHE_SERVICE_MAC_GENERATE;
  }
  else
  {
    serviceType = VHSM_API_SHE_SERVICE_MAC_VERIFY;
  }

  /* #30 Get CMACAES key */
#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  Crypto_30_Hwa_CheckRomKeyUsage(workspace->cryptoKeyId, &workspace->romKeyMapIndex);

  if (workspace->romKeyMapIndex == CRYPTO_30_HWA_ROMKEY_USE_IMPORTED_KEY)
#endif /* (CRYPTO_30_HWA_ROMKEY == STD_ON) */
  {
    /* Get AES key */
    retVal = vHsm_Api_KeyElementGetForCryptoJobs(cryptoKeyId, CRYPTO_KE_CIPHER_KEY,
      &index, CRYPTO_30_HWA_AES_KEY_SIZE, serviceType);

    if (retVal == E_OK)
    {
      key = vHsm_Api_GetAddrKeyStorage(index);
    }
  }

  if (retVal == E_OK)
  {
    /* #40 Generate CMAC subkey k1 with AES engine */
# if (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    retVal = Crypto_30_Hwa_CmacSubKeyGeneration_k1(workspace, key);
    if (retVal == E_OK)
# endif /* (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) */
    {
      SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
      retVal = Crypto_30_Hwa_Hw_CmacStart(workspace, key);
      SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
    }
  }

  return retVal;
} /* Crypto_30_Hwa_CmacStart() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CmacUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CmacUpdate(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) dataPtr,
  uint32 dataLength,
  boolean isFinish)
{
  Std_ReturnType retVal = E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint32 inputProcessed = 0u;

  if ((workspace->bufferFillLevel + dataLength) > CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES)
  {
    uint32 blockCount = CRYPTO_30_HWA_AES_BYTES_TO_BLOCKS(workspace->bufferFillLevel + dataLength - 1u);

    /* If there is something in the buffer, process it first */
    if (workspace->bufferFillLevel > 0u)
    {
      /* Complete buffer with input data */
      inputProcessed = CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES - workspace->bufferFillLevel;
      VStdLib_MemCpy(&workspace->buffer[workspace->bufferFillLevel], dataPtr, inputProcessed); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      /* Push to hardware */
      SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
      retVal = Crypto_30_Hwa_Hw_CmacProcessBlocks(workspace, workspace->buffer, 1u);
      SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
      blockCount--;
      workspace->bufferFillLevel = 0u;
      if (blockCount > 0u)
      {
        retVal |= Crypto_30_Hwa_CmacProcessBlocksSlicing(workspace, &dataPtr[inputProcessed], blockCount);
      }
    }
    else
    {
      retVal = Crypto_30_Hwa_CmacProcessBlocksSlicing(workspace, &dataPtr[inputProcessed], blockCount);
    }
    inputProcessed += CRYPTO_30_HWA_AES_BLOCKS_TO_BYTES(blockCount);
  }

  /* Keep remaining data for finish call */
# if (CRYPTO_30_HWA_HARDWARE_CMAC == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  if ((isFinish == TRUE) && (workspace->bufferFillLevel == 0u))
  {
    /* If this is the last update call before finish and the buffer is not used,
     * point directly to input data */
    workspace->remainingDataPtr = &dataPtr[inputProcessed];
    workspace->bufferFillLevel = (dataLength - inputProcessed);
  }
  else
# else /* (CRYPTO_30_HWA_HARDWARE_CMAC == STD_ON) */
  CRYPTO_30_HWA_DUMMY_STATEMENT(isFinish); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CRYPTO_30_HWA_HARDWARE_CMAC == STD_ON) */
  {
    VStdLib_MemCpy(&(workspace->buffer[workspace->bufferFillLevel]), &dataPtr[inputProcessed], (dataLength - inputProcessed)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    workspace->remainingDataPtr = workspace->buffer;
    workspace->bufferFillLevel += (dataLength - inputProcessed);
  }
  return retVal;
} /* Crypto_30_Hwa_CmacUpdate() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CmacFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CmacFinish(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) resultPtr)
{
  Std_ReturnType retVal = E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

# if (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key;
  uint8_least i;

  if (workspace->bufferFillLevel < CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES)
  {
    /* Not a multiple of AES blocks */
    /* Add padding high bit */
    workspace->buffer[workspace->bufferFillLevel] = 0x80u;
    workspace->bufferFillLevel += 1u;

    /* Add padding zeroes */
    VStdLib_MemSet(&workspace->buffer[workspace->bufferFillLevel], 0x00u, (CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES - workspace->bufferFillLevel)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    workspace->bufferFillLevel = CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;

    /* Generate subkey k2 and use it */
    Crypto_30_Hwa_CmacSubKeyGeneration_k2(workspace);
    key = workspace->k2;
  }
  else
  {
    /* Use key k1 */
    key = workspace->k1;
  }

  /* XOR with key k1 or k2 */
  for (i = 0u; i < CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES; i++)
  {
    workspace->buffer[i] ^= key[i];
  }

  /* Process last block */
  retVal = Crypto_30_Hwa_CmacProcessBlocksSlicing(workspace, workspace->buffer, 1u);
# endif /* (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) */

  /* Get the CMAC */
  SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
  retVal |= Crypto_30_Hwa_Hw_CmacFinish(workspace, resultPtr, CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES); /* PRQA S 2986 */ /* MD_CRYPTO_30_HWA_2986_REDUNDANT_OP */
  SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();

# if (CRYPTO_30_HWA_CLEAR_WORKSPACE_BUFFERS == STD_ON)
  /* PRQA S 0315 3 */ /* MD_MSR_VStdLibCopy */
  VStdLib_MemClr(workspace->buffer, sizeof(workspace->buffer)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
#  if (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  VStdLib_MemClr(workspace->k1, sizeof(workspace->k1)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
  VStdLib_MemClr(workspace->k2, sizeof(workspace->k2)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
#  endif /* (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) */
# endif /* (CRYPTO_30_HWA_CLEAR_WORKSPACE_BUFFERS == STD_ON) */

  return retVal;
} /* Crypto_30_Hwa_CmacFinish() */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessCmacJob()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessCmacJob(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  boolean verifyMac,
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Verify whether primitive info is correct */
  if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)
    && (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CMAC))
  {
    /* [SWS_Crypto_00017] [SWS_Crypto_00020] START while IDLE or ACTIVE */
    if (((job->state == CRYPTO_JOBSTATE_IDLE) || (job->state == CRYPTO_JOBSTATE_ACTIVE))
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_START))
    {
      /* #20 Prepare workspace */
      workspace->primitiveInfo = job->jobPrimitiveInfo->primitiveInfo;
      workspace->driverObjectId = objectId;

      /* #21 Call start operation */
      retVal = Crypto_30_Hwa_CmacStart(workspace, job->cryptoKeyId);
      Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    }

    /* UPDATE while ACTIVE */
    if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) /* [SWS_Crypto_00024] */
    {
      /* #30 Call update operation */
      retVal = Crypto_30_Hwa_CmacUpdate(workspace, job->jobPrimitiveInputOutput.inputPtr,
        job->jobPrimitiveInputOutput.inputLength,
        (boolean)Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH));
      Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    }

    /* [SWS_Crypto_00023] FINISH while ACTIVE */
    if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH)) /* [SWS_Crypto_00024] */
    {
      uint8 macBuffer[CRYPTO_30_HWA_AES_KEY_SIZE] = { 0 };
      P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) macPtr;

      if ((verifyMac == TRUE) || ((*job->jobPrimitiveInputOutput.outputLengthPtr) < CRYPTO_30_HWA_AES_KEY_SIZE))
      {
        macPtr = macBuffer;
      }
      else
      {
        macPtr = job->jobPrimitiveInputOutput.outputPtr;
      }

      /* #40 Call finish operation */
      retVal = Crypto_30_Hwa_CmacFinish(workspace, macPtr);

      if (retVal == E_OK)
      {
        if (verifyMac == TRUE)
        {
          /* Check if input length is not to large */
          if (job->jobPrimitiveInputOutput.secondaryInputLength <= CRYPTO_30_HWA_CMAC_TAG_SIZE_BIT)
          {
            /* #41 Verify MAC */
            *(job->jobPrimitiveInputOutput.verifyPtr) = Crypto_30_Hwa_MacCompare(
              job->jobPrimitiveInputOutput.secondaryInputPtr, macBuffer, job->jobPrimitiveInputOutput.secondaryInputLength);
          }
          else
          {
            retVal = E_NOT_OK;
          }
        }
        else
        {
          /* #42 If output length < MAC size, copy requested amount to output */
          if ((*job->jobPrimitiveInputOutput.outputLengthPtr) < CRYPTO_30_HWA_AES_KEY_SIZE)
          {
            VStdLib_MemCpy(job->jobPrimitiveInputOutput.outputPtr, macBuffer, *job->jobPrimitiveInputOutput.outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
          }
          else
          {
            *job->jobPrimitiveInputOutput.outputLengthPtr = 16u;
          }
        }
      }

      job->state = CRYPTO_JOBSTATE_IDLE; /* SBSW_CRYPTO_30_HWA_DIRECT_ACCESS_TO_JOB_STATE */
    }

    *errorIdPtr = CRYPTO_E_NO_ERROR;
  }

  return retVal;
} /* Crypto_30_Hwa_ProcessCmacJob() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Mac.c
 *********************************************************************************************************************/
