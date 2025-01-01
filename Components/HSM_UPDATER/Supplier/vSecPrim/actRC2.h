/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 1999 - 2016 cv cryptovision GmbH.                                                All rights reserved.
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
/*!        \file  actRC2.h
 *        \brief  This file contains the interface for the RC2 implementation.
 *
 *      \details  Currently the actClib version is used.
 *                This file is part of the embedded systems library cvActLib/ES
 *********************************************************************************************************************/
#ifndef ACTRC2_H
# define ACTRC2_H

# include "actITypes.h"

/* PRQA S 5209 EOF */ /* MD_VSECPRIM_USE_OF_BASIC_TYPES */


/****************************************************************************
 ** Types and constants
 ***************************************************************************/

# define RC2_MAX_KEY_LENGTH                                           128u   /* max user key length set to 128 byte  */
# define actRC2_MIN_KEY_SIZE                                          5u     /* min key size in bytes */
# define RC2_MASK                                                     0xff   /* TM - mask based on eff. key length in bits - implementation requires effective_key modulo 8 !=0 */
# define MAX_ROUNDS                                                   16u    /* constant: 16 rounds */
# define actRC2_BLOCK_SIZE                                            8u     /* block size in bytes */


/* Context structure of the RC2 algorithm */
typedef struct
{
   actU16 e_key[RC2_MAX_KEY_LENGTH/2u];
   int key_word_len;
   int eff_key_word_len;
   int max_key_len;
   int mode;
   actU8 prev_block[actRC2_BLOCK_SIZE];
   int buffer_used;
   actU8 buffer[actRC2_BLOCK_SIZE];
   actU8 copyInputData[actRC2_BLOCK_SIZE];
} actRC2STRUCT;

/* PRQA S 0850 3 */ /* MD_MSR_MacroArgumentEmpty */
typedef VSECPRIM_P2FUNC(VSECPRIM_NONE, void, actRC2TransformFctType)(
   VSECPRIM_P2VAR_PARA(actRC2STRUCT) info, VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer,
   int blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/****************************************************************************
 ** RC2 mode identifiers
 **
 **    actRC2_[mode_id]
 ***************************************************************************/
/* ECB */
# define actRC2_ECB                                                   (0x20u)
/* CBC */
# define actRC2_CBC                                                   (0x21u)

# define VSECPRIM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* block I/O */
extern VSECPRIM_FUNC(void) RC2BlockIO(VSECPRIM_P2CONST_PARA(void) in,
                                      VSECPRIM_P2VAR_PARA(void) out);

/****************************************************************************
 **
 ** FUNCTION:
 ** static actRETURNCODE actRC2KeySetup()
 **
 **  This function intializes info->e_key
 **
 ** input:
 ** - info:       initialized RC2 context structure
 ** - key:        pointer to user key
 ** - key_len:    length of key in byte
 ** - eff_key_len length of effective key in byte
 **
 ** output:
 ** - info:       modified RC2 context structure
 **
 ** assumes:
 ** - actRC2Init(info) is called once before calling this function
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actEXCEPTION_LENGTH    if key_len is invalid
 **               actOK                  else
 **
 ** uses:
 **
 ***************************************************************************/
extern VSECPRIM_FUNC(actRETURNCODE) actRC2KeySetup(
   VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, int key_len,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));


/****************************************************************************
 **
 ** FUNCTION:
 ** static actRETURNCODE actRC2Init()
 **
 **  This function initializes the RC2 algorithm (key setup etc.).
 **
 ** input:
 ** - info:       pointer to RC2 context structure
 ** - key:        pointer to user key
 ** - key_len:    length of key in byte
 ** - iv:         pointer to initialization vector (only in CBC mode;
 **               of length actRC2_BLOCK_SIZE; if iv==NULL, a zeroized
 **               block is used as iv)
 ** - mode:       ECB, CBC mode switch
 ** - key_setup_only:  if not 0: only key setup is done
 **
 ** output:
 ** - info:       initialized RC2 context structure
 ** - mode:       initialized mode switch of context structure
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actEXCEPTION_LENGTH    if key_len is invalid
 **               actEXCEPTION_ALGOID    mode is invalid
 **               actOK                  else
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
extern VSECPRIM_FUNC(actRETURNCODE) actRC2Init(
   VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, int key_len, int eff_key_len,
   VSECPRIM_P2CONST_PARA(actU8) iv, actU8 mode,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));


/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actRC2Encrypt()
 **
 **  This function encrypts input data of any length.
 **  If final==0, ((in_length+buffered_bytes)/8) blocks will be encrypted
 **  and written to out_buffer, ((in_length+buffered_bytes)%8) bytes will
 **  be buffered, where 0 <= buffered_bytes < 8.
 **  If final!=0, (((in_length+buffered_bytes)/8)+1) blocks will be
 **  encrypted and written to out_buffer. PKCS 5 padding is used for the
 **  last block padding.
 **
 ** input:
 ** - info:        pointer to initialized RC2 context structure
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
 ** - actRC2Init() is called once before calling this function
 ** - in!=NULL, out_buffer!=NULL are a valid pointers
 ** - in_length>=0, *out_length>=0 (at input)
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actRC2Encrypt(
   VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, int in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(int) out_length,
   int final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));


/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actRC2Decrypt()
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
 ** - info:        pointer to initialized RC2 context structure
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
 **    ((in_length+buffered_bytes)/8)*8          if final==0
 **    (in_length+buffered_bytes)/8)*8 - pad    else, where 1<=pad<=8
 ** - returns:    actEXCEPTION_LENGTH   *out_length is too small
 ** (if final!=0) actEXCEPTION_INPUT_LENGTH (in_length+buffered_bytes)%8!=0
 **               actEXCEPTION_PADDING  PKCS 5 unpad error
 **               actOK                 else
 **
 ** assumes:
 ** - actRC2Init() is called once before calling this function
 ** - in!=NULL, out_buffer!=NULL are a valid pointers
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actRC2Decrypt(
   VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, int in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(int) out_length,
   int final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actRC2InitCryptBlock()
 **
 **
 **  This function initializes the RC2 block encryption.
 **
 ** input:
 ** - info:       pointer to RC2 context structure
 ** - key:        pointer to user key
 ** - key_len:    length of key in byte
 ** - eff_key_len length of effective key in byte
 **
 ** output:
 ** - info:       initialized RC2 context structure
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actEXCEPTION_LENGTH    if key_len is invalid
 **               actOK                  else
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actRC2InitCryptBlock(
   VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, int key_len, int eff_key_len,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));


/****************************************************************************
 **
 ** FUNCTION:
 **  void actRC2EncryptBlock()
 **
 **  This function encrypts the given block.
 **
 ** input:
 ** - info->e_key: pointer to expanded encryption key
 ** - in_block:    pointer to block to be encrypted
 ** - out_block:   pointer to allocated output block
 **
 ** output:
 ** - out_block:  encrypted output block
 **
 ** assumes:
 ** - actRC2InitEncryptBlock(info) is called once before calling
 **   this function
 ** - 'in_block' and 'out_block' are of size actRC2_BLOCK_SIZE
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(void)  actRC2EncryptBlock(
   VSECPRIM_P2CONST_PARA(actRC2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));


/****************************************************************************
 **
 ** FUNCTION:
 **  void actRC2DecryptBlock()
 **
 **  This function decrypts the given block.
 **
 ** input:
 ** - info->e_key: pointer to expanded decryption key
 ** - in_block:    pointer to block to be decrypted
 ** - out_block:   pointer to allocated output block
 **
 ** output:
 ** - out_block:  decrypted output block
 **
 ** assumes:
 ** - actRC2InitDecryptBlock(info) is called once before calling
 **   this function
 ** - 'in_block' and 'out_block' are of size actRC2_BLOCK_SIZE
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(void) actRC2DecryptBlock(
   VSECPRIM_P2CONST_PARA(actRC2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));


/****************************************************************************
 **
 ** FUNCTION:
 ** static void actRC2EncryptMultipleBlocks()
 **
 **  This function encrypts the given blocks in different modes.
 **
 ** input:
 ** - info:        pointer to RC2 context structure
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
extern VSECPRIM_FUNC(void) actRC2EncryptMultipleBlocks(
   VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer,
   int blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));


/****************************************************************************
 **
 ** FUNCTION:
 ** static void actRC2DecryptMultipleBlocks()
 **
 **  This function decrypts the given blocks in different modes.
 **
 ** input:
 ** - info:        pointer to RC2 context structure
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
extern VSECPRIM_FUNC(void) actRC2DecryptMultipleBlocks(
   VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer,
   int blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));


/****************************************************************************
 **
 ** FUNCTION:
 ** static void actRC2Transform()
 **
 **  This function transforms input data of any length.
 **  ((in_length+buffered_bytes)/8) blocks will be transformed and written
 **  to out_buffer, ((in_length+buffered_bytes)%8) bytes will be buffered,
 **  where 0 <= buffered_bytes < 8.
 **
 ** input:
 ** - info:        pointer to initialized RC2 context structure
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
extern VSECPRIM_FUNC(void) actRC2Transform(
   VSECPRIM_P2VAR_PARA(actRC2STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, int in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, actRC2TransformFctType transform,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif
