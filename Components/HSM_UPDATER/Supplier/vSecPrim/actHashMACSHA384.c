/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is protected under intellectual property laws and proprietary to cv cryptovision GmbH
 *                and/or Vector Informatik GmbH.
 *                No right or license is granted save as expressly set out in the applicable license conditions.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  actHashMACSHA384.c
 *        \brief  Hash MAC SHA-384 implementation.
 *
 *      \details Currently the actClib version is used.
 *               This file is part of the embedded systems library cvActLib/ES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to module's header file.
 *********************************************************************************************************************/

#define ACTHASHMACSHA384_SOURCE

#include "actIHashMACSHA384.h"
#include "actUtilities.h"

#if (VSECPRIM_ACTHASHMACSHA384_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/****************************************************************************
 ** Global Functions
 ***************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actHashMACSHA384Init(actHASHMACSHA384STRUCT* info),
 **                              const actU8* key,
 **                              actLengthType key_length,
 **                              void (*watchdog) (void))
 **
 **  This function initializes the HashMAC algorithm.
 **
 ** input:
 ** - info:       pointer to context structure
 ** - key:        MAC key
 ** - key_length: length of key in bytes
 ** - watchdog:   pointer to watchdog reset function
 **
 ** output:
 ** - info:       initialized context structure
 ** - returns:    actEXCEPTION_LENGTH    if key_len < 1
 **               actOK                  else
 **
 ** assumes:
 **
 ** uses:
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA384Init(
  VSECPRIM_P2VAR_PARA(actHASHMACSHA384STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* ----- Local Variables ------------------------------------------------ */
  VSECPRIM_P2VAR_PARA(actSHA384STRUCT) sha384 = &info->sha384;
  VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->sha384.buffer;
  actRETURNCODE retVal = actOK;
  actLengthType i;

  /* ----- Implementation ------------------------------------------------- */
  /* store key */
  if (key_length < 1u)
  {
    retVal = actEXCEPTION_LENGTH;
  }
  else if (key_length <= actHASH_BLOCK_SIZE_SHA512)
  {
    /* copy key to key_buf */
    actMemCpyByteArray(info->key_buf, key, key_length); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
    info->key_length = key_length;
  }
  else
  {
    /* use SHA-384(key) */
    (void)actSHA384Init(sha384);
    (void)actSHA384Update(sha384, key, key_length, watchdog);
    (void)actSHA384Finalize(sha384, info->key_buf, watchdog);
    info->key_length = actHASH_SIZE_SHA384;
  }

  if (retVal == actOK)
  {
    /* ipad */
    actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
    actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_SHA512 - info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
    for (i = 0u; i < actHASH_BLOCK_SIZE_SHA512; ++i)
    {
      tmp_block[i] ^= (actU8)(0x36u);
    }

    (void)actSHA384Init(sha384);
    (void)actSHA384Update(sha384, tmp_block, actHASH_BLOCK_SIZE_SHA512, watchdog);
  }

  return retVal;
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actHashMACSHA384Update(actHASHMACSHA384STRUCT* info,
 **                   const actU8* dataIN,
 **                   actLengthType length,
 **                   void (*watchdog) (void)))
 **
 **  This function hashes the given data and can be called arbitrary
 **  often between an initialize and finalize of the HashMAC algorithm.
 **  Uses any data already in the actSHA384STRUCT structure and leaves
 **  any partial data block there.
 **
 ** input:
 ** - info:       pointer to context structure
 ** - dataIN:     pointer to data to be hashed
 ** - length:     length of data in bytes
 ** - watchdog:   pointer to watchdog reset function
 **
 ** output:
 ** - info:       actualized context structure
 ** - returns:    actEXCEPTION_LENGTH   total input more than 2^64 - 1 bit
 **               actOK                 else
 **
 ** assumes:
 ** - actHashMACInit() is called once before calling this function
 ** - dataIN != NULL is a valid pointer
 ** - length >= 0
 **
 ** uses:
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA384Update(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA384STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   return actSHA384Update(&info->sha384, dataIN, length, watchdog);
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actHashMACSHA384Finalize(actHASHMACSHA384STRUCT* info,
 **                     actU8 hash[actHASH_SIZE_SHA384]),
 **                     void (*watchdog) (void))
 **
 **  This function finalizes the HashMAC algorithm and
 **  delivers the hash value.
 **
 ** input:
 ** - info:       pointer to context structure
 ** - hash:       byte array to contain the hash value
 ** - watchdog:   pointer to watchdog reset function
 **
 ** output:
 ** - info:       finalized context structure
 ** - hash:       the final hash value,
 **                  (big endian of length actHASH_SIZE_SHA384)
 ** - returns:    actOK always
 **
 ** assumes:
 ** - actHashMACSHA384Init() is called once before calling this function
 **
 ** uses:
 ** - actHASH_SIZE_SHA384
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA384Finalize(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA384STRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   VSECPRIM_P2VAR_PARA(actSHA384STRUCT) sha384 = &info->sha384;
   VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->sha384.buffer;
   actLengthType i;

   (void)actSHA384Finalize(sha384, hash, watchdog);

   /* opad */
   actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
   actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_SHA512 - info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
   for (i=0u; i < actHASH_BLOCK_SIZE_SHA512; ++i)
   {
      tmp_block[i] ^= (actU8)(0x5cu);
   }

   (void)actSHA384Init(sha384);
   (void)actSHA384Update(sha384, tmp_block, actHASH_BLOCK_SIZE_SHA512, watchdog);
   (void)actSHA384Update(sha384, hash, actHASH_SIZE_SHA384, watchdog);
   (void)actSHA384Finalize(sha384, hash, watchdog);

   return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTHASHMACSHA384_ENABLED == STD_ON) */
