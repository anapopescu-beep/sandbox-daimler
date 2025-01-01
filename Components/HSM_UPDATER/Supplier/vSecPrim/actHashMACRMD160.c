 /**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 1999 - 2005 cv cryptovision GmbH.                                                All rights reserved.
 *
 *  For modifications by Vector Informatik GmbH:
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is protected under intellectual property laws and proprietary to cv cryptovision GmbH
 *                and/or Vector Informatik GmbH.
 *                No right or license is granted save as expressly set out in the applicable license conditions.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  actHashMACRMD160.c
 *        \brief  This file contains the interface for RIPEMD160 based Hash MAC algorithm.
 *
 *      \details  Currently the actClib version is used.
 *                This file is part of the embedded systems library cvActLib/ES
 *********************************************************************************************************************/

/****************************************************************************
 **
 **     Part of the actCLibrary
 **
 **     Layer: User Module - Interface
 **
 ***************************************************************************/

/****************************************************************************
 **
 ** This file contains: The interface for RIPEMD-160 based Hash MAC algorithm.
 **
 ** constants:
 **
 ** types:
 **
 ** macros:
 **
 ** functions:
 **   actHashMACInit
 **   actHashMACUpdate
 **   actHashMACFinalize
 **
 ***************************************************************************/
#define ACTHASHMACRMD160_SOURCE

#include "actIHashMACRMD160.h"
#include "actUtilities.h"

#if (VSECPRIM_ACTHASHMACRMD160_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/****************************************************************************
 ** Global Functions
 ***************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actHashMACRMD160Init(actHASHMACRMD160STRUCT* info),
 **                                    const actU8* key,
 **                                    int key_length,
 **                                    void (*watchdog) (void))
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
VSECPRIM_FUNC(actRETURNCODE) actHashMACRMD160Init(
   VSECPRIM_P2VAR_PARA(actHASHMACRMD160STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* ----- Local Variables ------------------------------------------------ */
   VSECPRIM_P2VAR_PARA(actRMD160STRUCT) rmd160 = &info->rmd160;
   VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->rmd160.buffer;
   actRETURNCODE retVal = actOK;
   actLengthType i;

  /* ----- Implementation ------------------------------------------------- */
   /* store key */
   if (key_length < 1u)
   {
      retVal = actEXCEPTION_LENGTH;
   }
   else if (key_length <= actHASH_BLOCK_SIZE_RMD160)
   {
      /* copy key to key_buf */
      actMemCpyByteArray(info->key_buf, key, key_length); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
      info->key_length = key_length;
   }
   else
   {
      /* use RMD-160(key) */
      (void)actRMD160Init(rmd160);
      (void)actRMD160Update(rmd160, key, key_length, watchdog);
      (void)actRMD160Finalize(rmd160, info->key_buf, watchdog);
      info->key_length = actHASH_SIZE_RMD160;
   }

   if (retVal == actOK)
   {
     /* ipad */
     actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
     actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_RMD160 - info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
     for (i = 0u; i < actHASH_BLOCK_SIZE_RMD160; ++i)
     {
       tmp_block[i] ^= (actU8)(0x36u);
     }

     (void)actRMD160Init(rmd160);
     (void)actRMD160Update(rmd160, tmp_block, actHASH_BLOCK_SIZE_RMD160, watchdog);
   }

   return retVal;
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actHashMACRMD160Update(actHASHMACRMD160STRUCT* info,
 **                                      const actU8* dataIN,
 **                                      int length,
 **                                      void (*watchdog) (void))
 **
 **  This function hashes the given data and can be called arbitrary
 **  often between an initialize and finalize of the HashMAC algorithm.
 **  Uses any data already in the actRMD160STRUCT structure and leaves
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
 ** - actHashMACRMD160Init() is called once before calling this function
 ** - dataIN != NULL is a valid pointer
 ** - length >= 0
 **
 ** uses:
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actHashMACRMD160Update(
   VSECPRIM_P2VAR_PARA(actHASHMACRMD160STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   return actRMD160Update(&info->rmd160, dataIN, length, watchdog);
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actHashMACRMD160Finalize(actHASHMACSTRUCT* info,
 **                     actU8 hash[actHASH_SIZE_RMD160],
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
 **                  (big endian of length actHASH_SIZE_RMD160)
 ** - returns:    actOK always
 **
 ** assumes:
 ** - actHashMACRMD160Init() is called once before calling this function
 **
 ** uses:
 ** - actHASH_SIZE_RMD160
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actHashMACRMD160Finalize(
   VSECPRIM_P2VAR_PARA(actHASHMACRMD160STRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   VSECPRIM_P2VAR_PARA(actRMD160STRUCT) rmd160 = &info->rmd160;
   VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->rmd160.buffer;
   actLengthType i;

   (void)actRMD160Finalize(rmd160, hash, watchdog);

   /* opad */
   actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
   actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_RMD160 - info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
   for (i=0u; i < actHASH_BLOCK_SIZE_RMD160; ++i)
   {
      tmp_block[i] ^= (actU8)(0x5cu);
   }

   (void)actRMD160Init(rmd160);
   (void)actRMD160Update(rmd160, tmp_block, actHASH_BLOCK_SIZE_RMD160, watchdog);
   (void)actRMD160Update(rmd160, hash, actHASH_SIZE_RMD160, watchdog);
   (void)actRMD160Finalize(rmd160, hash, watchdog);

   return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTHASHMACRMD160_ENABLED == STD_ON) */
