/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 1999 - 2006 cv cryptovision GmbH.                                                All rights reserved.
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
/*!        \file  actTDES.c
 *        \brief  This file contains the implementation of the TDES algorithm.
 *
 *      \details  Currently the actClib version is used.
 *                This file is part of the embedded systems library cvActLib/ES
 *********************************************************************************************************************/
#define ACTTDES_SOURCE

#include "actTDES.h"
#include "actUtilities.h"
#include "actWatchdog.h"
#include "actConfig.h"

#if (VSECPRIM_ACTTDES_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/* PRQA S 5209 EOF */ /* MD_VSECPRIM_USE_OF_BASIC_TYPES */

/****************************************************************************
 ** Macros for rotate, get block ... etc
 ***************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/****************************************************************************
 ** Local functions
 ***************************************************************************/

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actTDESInit()
 **
 **  This function initializes the TDES algorithm (key setup etc.).
 **
 ** input:
 ** - info:       pointer to TDES context structure
 ** - key:        pointer to user key
 ** - key_len     length of user key
 ** - crypt_mode: encryption, decryption mode switch
 ** - iv:         pointer to initialization vector (only in CBC mode;
 **               of length actDES_BLOCK_SIZE; if iv==NULL, a zeroized
 **               block is used as iv)
 ** - block_mode: ECB, CBC mode switch
 **
 ** output:
 ** - info:       initialized TDES context structure
 ** - mode:       initialized mode switch of context structure
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actEXCEPTION_ALGOID    mode is invalid
 **               actOK                  else
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actTDESInit(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actU8 key_len,
   actU8 crypt_mode, VSECPRIM_P2CONST_PARA(actU8) iv,
   actU8 block_mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   /* initialization mode, buffers, etc. */
   info->mode = block_mode;
   info->buffer_used = 0;
   switch (block_mode)
   {
      case actDES_ECB:
      {
         break;
      }
      case actDES_CBC:
      {
         if (iv == 0)
         {
            actMemset(info->prev_block, 0, actDES_BLOCK_SIZE); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
         }
         else
         {
            actMemCpyByteArray(info->prev_block, iv, actDES_BLOCK_SIZE); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
         }
         break;
      }
      default:
      {
         return actEXCEPTION_ALGOID;
      }
   }

   /* key setup */
   return actTDESKeySetup(info, key, key_len, crypt_mode, watchdog);
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actTDESKeySetup()
 **
 **  This function initializes round keys
 **
 ** input:
 ** - info:       pointer to TDES context structure
 ** - key:        pointer to user key
 ** - key_len     length of user key
 ** - crypt_mode  switch for decryption keys
 **
 ** output:
 ** - info:       modified TDES context structure
 **
 ** assumes:
 ** - actTDESInit(info) is called once before calling this function
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actOK                  else
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actTDESKeySetup(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actU8 key_len,
   actU8 crypt_mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
      /* init key pointers */
      info->k1_ptr = key;
      info->k2_ptr = key + 8;
      if (key_len == 24)
      {
         info->k3_ptr = key + 16;
      }
      else
      {
         info->k3_ptr = key;
      }

      if (crypt_mode == EN0)
      {
         actDESKeySetup(&info->k1, info->k1_ptr, EN0, watchdog);
         actDESKeySetup(&info->k2, info->k2_ptr, DE1, watchdog);
         actDESKeySetup(&info->k3, info->k3_ptr, EN0, watchdog);
      }
      else
      {
         actDESKeySetup(&info->k1, info->k3_ptr, DE1, watchdog);
         actDESKeySetup(&info->k2, info->k2_ptr, EN0, watchdog);
         actDESKeySetup(&info->k3, info->k1_ptr, DE1, watchdog);
      }

      return actOK;
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actTDESInitEncrypt()
 **
 **  This function initializes the TDES algorithm (key setup etc.).
 **
 ** input:
 ** - info:       pointer to TDES context structure
 ** - key:        pointer to user key
 ** - key_len     length of user key
 ** - iv:         pointer to initialization vector (only in CBC mode;
 **               of length actDES_BLOCK_SIZE; if iv==NULL, a zeroized
 **               block is used as iv)
 ** - mode:       ECB, CBC mode switch
 **
 ** output:
 ** - info:       initialized TDES context structure
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actEXCEPTION_ALGOID    mode is invalid
 **               actOK                  else
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actTDESInitEncrypt(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actU8  key_len,
   VSECPRIM_P2CONST_PARA(actU8) iv, actU8 mode,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   return actTDESInit(info, key, key_len, EN0, iv, mode, watchdog);
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actTDESEncrypt()
 **
 **  This function encrypts input data of any length.
 **  If final==0, ((in_length+buffered_bytes)/8) blocks will be encrypted
 **  and written to out_buffer, ((in_length+buffered_bytes)%8) bytes will
 **  be buffered, where 0 <= buffered_bytes < 8.
 **  If final!=0, (((in_length+buffered_bytes)/8)+1) blocks will be
 **  encrypted and written to out_buffer.
 **  PKCS 5 padding is used for the last block padding.
 **
 ** input:
 ** - info:        pointer to initialized TDES context structure
 ** - in:          pointer to data to be encrypted
 ** - in_length:   length of data in bytes
 ** - out_buffer:  pointer to encrypted data buffer
 ** - *out_length: out_buffer size in bytes, a safe length is:
 **                  (((in_length+7)/8)+1)*8       (see output)
 ** - final:       flag for padding
 **
 ** output:
 ** - info->prev_block:   updated previous block
 ** - out_buffer:         encrypted data blocks
 ** - *out_length:        number of encrypted bytes:
 **                  ((in_length+buffered_bytes)/8)*8       if final==0
 **                  (((in_length+buffered_bytes)/8)+1)*8   else
 ** - returns:    actEXCEPTION_LENGTH   *out_length is too small
 **               actOK                 else
 **
 ** assumes:
 ** - actTDESInitEncrypt() is called once before calling this function
 ** - in!=NULL, out_buffer!=NULL are a valid pointers
 ** - in_length>=0, *out_length>=0 (at input)
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actTDESEncrypt(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, int in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(int) out_length,
   int final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   /* out_size = blocks*8 */
   int out_size = ((in_length+info->buffer_used)/actDES_BLOCK_SIZE) * actDES_BLOCK_SIZE;

   /* check out_buffer size */
   if (in_length > (0xFFFFFFFFuL - actDES_BLOCK_SIZE))
   {
     return actEXCEPTION_LENGTH;
   }

   if (final == 0)
   {
      if (*out_length < out_size)
      {
         return actEXCEPTION_LENGTH;
      }
      *out_length = out_size;
   }
   else
   {
      if (*out_length < (int)(out_size+actDES_BLOCK_SIZE))
      {
         return actEXCEPTION_LENGTH;
      }
      *out_length = out_size + actDES_BLOCK_SIZE;
   }

   /* transform input */
   if (in_length > 0)
   {
      actTDESTransform(info, in, in_length, out_buffer, actTDESEncryptMultipleBlocks, watchdog);
   }

   /* finalize ? */
   if (final != 0)
   {
      /* PKCS 5 padding of last buffered block */
      actU8 pad = (actU8)(actDES_BLOCK_SIZE - info->buffer_used);
      actMemset(info->buffer + info->buffer_used, pad, (unsigned int)pad); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
      /* encryption of last block */
      actTDESEncryptMultipleBlocks(info, info->buffer, out_buffer+out_size, 1, watchdog);
   }

   actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
   return actOK;
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actTDESInitDecrypt()
 **
 **  This function initializes the TDES decryption.
 **
 ** input:
 ** - info:       pointer to TDES context structure
 ** - key:        pointer to user key
 ** - key_len     length of user key
 ** - iv:         pointer to initialization vector (only in CBC mode;
 **               of length actDES_BLOCK_SIZE; if iv==NULL, a zeroized
 **               block is used as iv)
 ** - mode:       ECB, CBC mode switch
 **
 ** output:
 ** - info:       initialized TDES context structure
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actEXCEPTION_ALGOID    mode is invalid
 **               actOK                  else
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actTDESInitDecrypt(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actU8 key_len,
   VSECPRIM_P2CONST_PARA(actU8) iv, actU8 mode,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   return actTDESInit(info, key, key_len, DE1, iv, mode, watchdog);
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actTDESDecrypt()
 **
 **  This function decrypts input data of any length.
 **  If final==0, ((in_length+buffered_bytes)/8) blocks will be decrypted
 **  and written to out_buffer, ((in_length+buffered_bytes)%8) bytes will
 **  be buffered, where 0 <= buffered_bytes < 8.
 **  If final!=0, ((in_length+buffered_bytes)/8) blocks will be decrypted
 **  and written to out_buffer, where (in_length+buffered_bytes) is a
 **  multiple of 8. PKCS 5 padding is used to unpad the last block.
 **
 ** input:
 ** - info:        pointer to initialized TDES context structure
 ** - in:          pointer to data to be decrypted
 ** - in_length:   length of data in bytes (multiple of 8)
 ** - out_buffer:  pointer to decrypted data buffer of length in_length
 ** - *out_length: out_buffer size in bytes, a safe length is:
 **                  ((in_length+7)/8)*8       (see output)
 ** - final:       flag for unpadding
 **
 ** output:
 ** - info->prev_block:   updated previous block
 ** - out_buffer:         decrypted data blocks
 ** - *out_length:        number of decrypted bytes:
 **                       ((in_length+buffered_bytes)/8)*8          if final==0
 **                       (in_length+buffered_bytes)/8)*8 - pad     else, where 1<=pad<=8
 ** - returns:    actEXCEPTION_LENGTH   *out_length is too small
 ** (if final!=0) actEXCEPTION_INPUT_LENGTH (in_length+buffered_bytes)%8!=0
 **               actEXCEPTION_PADDING  PKCS 5 unpad error
 **               actOK                 else
 **
 ** assumes:
 ** - actTDESInitDecrypt() is called once before calling this function
 ** - in!=NULL, out_buffer!=NULL are a valid pointers
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actTDESDecrypt(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, int in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(int) out_length,
   int final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   int total_bytes = in_length+info->buffer_used;
   int out_size;

   /* if finalize: check (in_length+buffer_length)%8==0 */
   if (final != 0)
   {
      if ((!total_bytes) || ((total_bytes % actDES_BLOCK_SIZE) != 0))
      {
         return actEXCEPTION_INPUT_LENGTH;
      }
   }

   if (total_bytes > 0)
   {
     /* out_size = blocks*8 */
     out_size = ((total_bytes-1) / actDES_BLOCK_SIZE) * actDES_BLOCK_SIZE;
   }
   else
   {
     /* No ouput data will be produced as no input data present */
     out_size = 0;
   }

   /* check out_buffer size */
   if (*out_length < out_size)
   {
      return actEXCEPTION_LENGTH;
   }

   /* transform input */
   if (in_length > 0)
   {
      if (total_bytes <= actDES_BLOCK_SIZE)
      {
         actMemCpyByteArray(info->buffer + info->buffer_used, in, (unsigned int)in_length); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
         info->buffer_used += in_length;
      }
      else
      {
         if ((total_bytes % actDES_BLOCK_SIZE) == 0)
         {
            actTDESTransform(info, in, (int) (in_length-actDES_BLOCK_SIZE), out_buffer, actTDESDecryptMultipleBlocks, watchdog);
            actMemCpyByteArray(info->buffer, in + in_length - actDES_BLOCK_SIZE, actDES_BLOCK_SIZE); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
            info->buffer_used = actDES_BLOCK_SIZE;
         }
         else
         {
            actTDESTransform(info, in, in_length, out_buffer, actTDESDecryptMultipleBlocks, watchdog);
         }
      }
   }

   if (final != 0)
   {
      /* decryption of the last buffered block */
      actTDESDecryptMultipleBlocks(info, info->buffer, info->buffer, 1, watchdog);
      {
         /* PKCS 5 unpad of the last block */
         actU8 unpad = (actU8)(actDES_BLOCK_SIZE - info->buffer[actDES_BLOCK_SIZE-1]);
         if (unpad >= actDES_BLOCK_SIZE)
         {
            return actEXCEPTION_PADDING;
         }
         else
         {
            if (*out_length < out_size+unpad)
            {
               return actEXCEPTION_LENGTH;
            }
            actMemCpyByteArray(out_buffer + out_size, info->buffer, (unsigned int)unpad); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
            *out_length = out_size + unpad;
         }
      }
   }
   else
   {
      *out_length = out_size;
   }

   actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
   return actOK;
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actTDESInitEncryptBlock()
 **
 **
 **  This function initializes the TDES block encryption.
 **
 ** input:
 ** - info:       pointer to TDES context structure
 ** - key:        pointer to user key
 ** - key_len     length of user key
 **
 ** output:
 ** - info:       initialized TDES context structure
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actOK                  else
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actTDESInitEncryptBlock(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actU8 key_len,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   return actTDESKeySetup(info, key, key_len, EN0, watchdog);
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actTDESInitDecryptBlock()
 **
 **
 **  This function initializes the TDES block decryption.
 **
 ** input:
 ** - info:       pointer to TDES context structure
 ** - key:        pointer to user key
 ** - key_len     length of user key
 **
 ** output:
 ** - info:       initialized TDES context structure
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actOK                  else
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actTDESInitDecryptBlock(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actU8  key_len,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   return actTDESKeySetup(info, key, key_len, DE1, watchdog);
}

/****************************************************************************
 **
 ** FUNCTION:
 ** void actTDESCryptBlock()
 **
 **  This function encrypts the given blocks in different modes.
 **
 ** input:
 ** - info:        pointer to TDES context structure
 ** - in_block:    pointer to block to be encrypted
 ** - out_block:   pointer to allocated output block
 **
 ** output:
 ** - out_block:   encrypted output block
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(void) actTDESCryptBlock(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   actU8 tmp_block[actDES_BLOCK_SIZE];

   actDESCryptBlock(&info->k1, in_block, out_block, watchdog);
   actDESCryptBlock(&info->k2, out_block, tmp_block, watchdog);
   actDESCryptBlock(&info->k3, tmp_block, out_block, watchdog);

}

/****************************************************************************
 **
 ** FUNCTION:
 ** void actTDESEncryptMultipleBlocks()
 **
 **  This function encrypts the given blocks in different modes.
 **
 ** input:
 ** - info:        pointer to TDES context structure
 ** - in:          pointer to blocks to be encrypted
 ** - out_buffer:  pointer to allocated output blocks
 ** - blocks:      number of blocks
 **
 ** output:
 ** - out_block:  encrypted output blocks
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(void) actTDESEncryptMultipleBlocks(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer,
   int blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   VSECPRIM_P2VAR_PARA(actU8) prev_block = info->prev_block;
   int i, bcount;

   switch (info->mode)
   {
      case actDES_CBC:
      {
         for (bcount = 0; bcount < blocks; ++bcount)
         {
            /* out_block = prev_block ^ in_block */
            for (i = 0; i < actDES_BLOCK_SIZE; ++i)
            {
               out_buffer[i] = (actU8)(prev_block[i] ^ *in++);
            }
            /* out_block = Encrypt(out_block) */
            actTDESCryptBlock(info, out_buffer, out_buffer, watchdog);
            /* prev_block = out_block */
            for (i = 0; i < actDES_BLOCK_SIZE; ++i)
            {
               prev_block[i] = *out_buffer++;
            }
         }
         break;
      }
      default:   /* ECB */
      {
         for (bcount = 0; bcount < blocks; ++bcount, in += actDES_BLOCK_SIZE, out_buffer += actDES_BLOCK_SIZE)
         {
            /* out_block = Encrypt(in_block) */
            actTDESCryptBlock(info, in, out_buffer, watchdog);
         }
         break;
      }
   }
}

/****************************************************************************
 **
 ** FUNCTION:
 ** void actTDESDecryptMultipleBlocks()
 **
 **  This function decrypts the given blocks in different modes.
 **
 ** input:
 ** - info:        pointer to TDES context structure
 ** - in:          pointer to blocks to be decrypted
 ** - out_buffer:  pointer to allocated output blocks
 ** - blocks:      number of blocks
 **
 ** output:
 ** - out_block:  decrypted output blocks
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(void) actTDESDecryptMultipleBlocks(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer,
   int blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   VSECPRIM_P2VAR_PARA(actU8) prev_block = info->prev_block;
   int i, bcount;

   switch (info->mode)
   {
      case actDES_CBC:
      {
         for (bcount=0; bcount<blocks; ++bcount)
         {
             /* out_block = Decrypt(in_block) */
             actTDESCryptBlock(info, in, out_buffer, watchdog);
             /* out_block = prev_block ^ out_block */
             /* prev_block = in_block */
             for (i = 0; i < actDES_BLOCK_SIZE; ++i)
             {
                *out_buffer++ ^= prev_block[i];
                 prev_block[i] = *in++;
             }
         }
         break;
      }
      default:   /* ECB */
      {
         for (bcount = 0; bcount < blocks; ++bcount, in += actDES_BLOCK_SIZE, out_buffer += actDES_BLOCK_SIZE)
         {
            /* out_block = Decrypt(in_block) */
            actTDESCryptBlock(info, in, out_buffer, watchdog);
         }
         break;
      }
   }
}


/****************************************************************************
 **
 ** FUNCTION:
 ** void actTDESTransform()
 **
 **  This function transforms input data of any length.
 **  ((in_length+buffered_bytes)/8) blocks will be transformed and written
 **  to out_buffer, ((in_length+buffered_bytes)%8) bytes will be buffered,
 **  where 0 <= buffered_bytes < 8.
 **
 ** input:
 ** - info:        pointer to initialized TDES context structure
 ** - in:          pointer to data to be transformed
 ** - in_length:   length of data in bytes
 ** - out_buffer:  pointer to encrypted data buffer
 ** - transform:   pointer to transformation function (Encrypt/Decrypt)
 **
 ** output:
 ** - info->prev_block:   updated previous block
 ** - out_buffer:         encrypted data blocks
 **
 ** assumes:
 ** - in!=NULL, out_buffer!=NULL are a valid pointers
 ** - in_length>=0
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(void) actTDESTransform(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, int in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, actTDESTransformFctType transform,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   int blocks, bytes, diff=0;

   /* left overs of the last transform */
   if (info->buffer_used > 0)
   {
      diff = actMin(in_length, (int)(actDES_BLOCK_SIZE-info->buffer_used));
      actMemCpyByteArray(info->buffer + info->buffer_used, in, (unsigned int)diff); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
      info->buffer_used += diff;
      if (info->buffer_used < actDES_BLOCK_SIZE)
      {
         /* no complete block */
         return;
      }
      else
      {
         /* transform buffered block */
# ifdef actNO_INDIRECT_CALLS
         if (transform == actTDESEncryptMultipleBlocks)
            actTDESEncryptMultipleBlocks(info, info->buffer, out_buffer, 1, watchdog);
         else
            actTDESDecryptMultipleBlocks(info, info->buffer, out_buffer, 1, watchdog);
# else
         transform(info, info->buffer, out_buffer, 1, watchdog);
# endif
         in += diff; out_buffer += actDES_BLOCK_SIZE;
      }
   }

   /* transform blocks */
   blocks = (in_length-diff)/actDES_BLOCK_SIZE;
   bytes = actDES_BLOCK_SIZE*blocks;
# ifdef actNO_INDIRECT_CALLS
   if (transform == actTDESEncryptMultipleBlocks)
      actTDESEncryptMultipleBlocks(info, in, out_buffer, blocks, watchdog);
   else
      actTDESDecryptMultipleBlocks(info, in, out_buffer, blocks, watchdog);
# else
   transform(info, in, out_buffer, blocks, watchdog);
# endif

   /* copy left overs into info->buffer */
   info->buffer_used = in_length - (diff + bytes);
   actMemCpyByteArray(info->buffer, in + bytes, (unsigned int)(info->buffer_used)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
}

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTTDES_ENABLED == STD_ON) */
