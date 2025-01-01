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
/*!        \file  actTDES.h
 *        \brief  This file contains the interface for TDES algorithm.
 *
 *      \details  Currently the actClib version is used.
 *                This file is part of the embedded systems library cvActLib/ES
 *********************************************************************************************************************/

#ifndef ACTTDES_H
# define ACTTDES_H

# include "actDES.h"
# include "actITypes.h"
# include "actConfig.h"

/* PRQA S 5209 EOF */ /* MD_VSECPRIM_USE_OF_BASIC_TYPES */

/****************************************************************************
 ** Types and constants
 ***************************************************************************/

/* Context structure of the TDES algorithm */
typedef struct
{
   actDESSTRUCT k1;
   actDESSTRUCT k2;
   actDESSTRUCT k3;
   VSECPRIM_P2CONST_PARA(actU8) k1_ptr;
   VSECPRIM_P2CONST_PARA(actU8) k2_ptr;
   VSECPRIM_P2CONST_PARA(actU8) k3_ptr;
   int mode;
   actU8 prev_block[actDES_BLOCK_SIZE];
   int buffer_used;
   actU8 buffer[actDES_BLOCK_SIZE];
} actTDESSTRUCT;

/* PRQA S 0850 4 */ /* MD_MSR_MacroArgumentEmpty */
typedef VSECPRIM_P2FUNC(VSECPRIM_NONE, void, actTDESTransformFctType)(
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer,
   int blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/****************************************************************************
 ** Function Prototypes
 ***************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
   actU8 block_mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

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
   actU8 crypt_mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

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
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

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
   int final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

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
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

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
   int final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

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
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

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
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

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
VSECPRIM_FUNC(void) actTDESCryptBlock (
   VSECPRIM_P2VAR_PARA(actTDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

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
   int blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

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
   int blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

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
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTTDES_H */

