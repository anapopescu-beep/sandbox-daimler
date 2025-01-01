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
/*!        \file  actDES.c
 *        \brief  This file contains a DES implementation.
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

#define ACTDES_SOURCE

#include "actDES.h"
#include "actUtilities.h"
#include "actWatchdog.h"
#include "actConfig.h"

#if (VSECPRIM_ACTDES_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/* PRQA S 5209 EOF */ /* MD_VSECPRIM_USE_OF_BASIC_TYPES */

/****************************************************************************
 ** Look up tables
 ***************************************************************************/
# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


VSECPRIM_ROM(VSECPRIM_LOCAL, unsigned char) PC1[56] =
{ /* permutation choice 1  value-1 */
      56, 48, 40, 32, 24, 16,  8,  0, 57, 49, 41, 33, 25, 17,
       9,  1, 58, 50, 42, 34, 26, 18, 10,  2, 59, 51, 43, 35,
      62, 54, 46, 38, 30, 22, 14,  6, 61, 53, 45, 37, 29, 21,
      13,  5, 60, 52, 44, 36, 28, 20, 12,  4, 27, 19, 11,  3
};

VSECPRIM_ROM(VSECPRIM_LOCAL, unsigned char) PC2[48] =
{ /* permutation choice 2  value-1 */
      13, 16, 10, 23,  0,  4,  2, 27, 14,  5, 20,  9,
      22, 18, 11,  3, 25,  7, 15,  6, 26, 19, 12,  1,
      40, 51, 30, 36, 46, 54, 29, 39, 50, 44, 32, 47,
      43, 48, 38, 55, 33, 52, 45, 41, 49, 35, 28, 31
};

VSECPRIM_ROM(VSECPRIM_LOCAL, unsigned int) bytebit[8] =
{ /* bit Mask: MSB to LSB */
      0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01
};

VSECPRIM_ROM(VSECPRIM_LOCAL, unsigned long) bigbyte[24] =
{ /* bit Mask: MSB to LSB */
      0x00800000, 0x00400000, 0x00200000, 0x00100000,
      0x00080000, 0x00040000, 0x00020000, 0x00010000,
      0x00008000, 0x00004000, 0x00002000, 0x00001000,
      0x00000800, 0x00000400, 0x00000200, 0x00000100,
      0x00000080, 0x00000040, 0x00000020, 0x00000010,
      0x00000008, 0x00000004, 0x00000002, 0x00000001
};

VSECPRIM_ROM(VSECPRIM_LOCAL, char) totrotation[16] =
{
      1, 2, 4, 6, 8, 10, 12, 14, 15, 17, 19, 21, 23, 25, 27, 28
};

/****************************************************************************
 ** SBox tables
 ***************************************************************************/
VSECPRIM_ROM(VSECPRIM_LOCAL, unsigned long) SP1[64] =
{
   0x01010400, 0x00000000, 0x00010000, 0x01010404,
   0x01010004, 0x00010404, 0x00000004, 0x00010000,
   0x00000400, 0x01010400, 0x01010404, 0x00000400,
   0x01000404, 0x01010004, 0x01000000, 0x00000004,
   0x00000404, 0x01000400, 0x01000400, 0x00010400,
   0x00010400, 0x01010000, 0x01010000, 0x01000404,
   0x00010004, 0x01000004, 0x01000004, 0x00010004,
   0x00000000, 0x00000404, 0x00010404, 0x01000000,
   0x00010000, 0x01010404, 0x00000004, 0x01010000,
   0x01010400, 0x01000000, 0x01000000, 0x00000400,
   0x01010004, 0x00010000, 0x00010400, 0x01000004,
   0x00000400, 0x00000004, 0x01000404, 0x00010404,
   0x01010404, 0x00010004, 0x01010000, 0x01000404,
   0x01000004, 0x00000404, 0x00010404, 0x01010400,
   0x00000404, 0x01000400, 0x01000400, 0x00000000,
   0x00010004, 0x00010400, 0x00000000, 0x01010004
};

VSECPRIM_ROM(VSECPRIM_LOCAL, unsigned long) SP2[64] =
{
   0x80108020, 0x80008000, 0x00008000, 0x00108020,
   0x00100000, 0x00000020, 0x80100020, 0x80008020,
   0x80000020, 0x80108020, 0x80108000, 0x80000000,
   0x80008000, 0x00100000, 0x00000020, 0x80100020,
   0x00108000, 0x00100020, 0x80008020, 0x00000000,
   0x80000000, 0x00008000, 0x00108020, 0x80100000,
   0x00100020, 0x80000020, 0x00000000, 0x00108000,
   0x00008020, 0x80108000, 0x80100000, 0x00008020,
   0x00000000, 0x00108020, 0x80100020, 0x00100000,
   0x80008020, 0x80100000, 0x80108000, 0x00008000,
   0x80100000, 0x80008000, 0x00000020, 0x80108020,
   0x00108020, 0x00000020, 0x00008000, 0x80000000,
   0x00008020, 0x80108000, 0x00100000, 0x80000020,
   0x00100020, 0x80008020, 0x80000020, 0x00100020,
   0x00108000, 0x00000000, 0x80008000, 0x00008020,
   0x80000000, 0x80100020, 0x80108020, 0x00108000
};

VSECPRIM_ROM(VSECPRIM_LOCAL, unsigned long) SP3[64] =
{
   0x00000208, 0x08020200, 0x00000000, 0x08020008,
   0x08000200, 0x00000000, 0x00020208, 0x08000200,
   0x00020008, 0x08000008, 0x08000008, 0x00020000,
   0x08020208, 0x00020008, 0x08020000, 0x00000208,
   0x08000000, 0x00000008, 0x08020200, 0x00000200,
   0x00020200, 0x08020000, 0x08020008, 0x00020208,
   0x08000208, 0x00020200, 0x00020000, 0x08000208,
   0x00000008, 0x08020208, 0x00000200, 0x08000000,
   0x08020200, 0x08000000, 0x00020008, 0x00000208,
   0x00020000, 0x08020200, 0x08000200, 0x00000000,
   0x00000200, 0x00020008, 0x08020208, 0x08000200,
   0x08000008, 0x00000200, 0x00000000, 0x08020008,
   0x08000208, 0x00020000, 0x08000000, 0x08020208,
   0x00000008, 0x00020208, 0x00020200, 0x08000008,
   0x08020000, 0x08000208, 0x00000208, 0x08020000,
   0x00020208, 0x00000008, 0x08020008, 0x00020200
};

VSECPRIM_ROM(VSECPRIM_LOCAL, unsigned long) SP4[64] =
{
   0x00802001, 0x00002081, 0x00002081, 0x00000080,
   0x00802080, 0x00800081, 0x00800001, 0x00002001,
   0x00000000, 0x00802000, 0x00802000, 0x00802081,
   0x00000081, 0x00000000, 0x00800080, 0x00800001,
   0x00000001, 0x00002000, 0x00800000, 0x00802001,
   0x00000080, 0x00800000, 0x00002001, 0x00002080,
   0x00800081, 0x00000001, 0x00002080, 0x00800080,
   0x00002000, 0x00802080, 0x00802081, 0x00000081,
   0x00800080, 0x00800001, 0x00802000, 0x00802081,
   0x00000081, 0x00000000, 0x00000000, 0x00802000,
   0x00002080, 0x00800080, 0x00800081, 0x00000001,
   0x00802001, 0x00002081, 0x00002081, 0x00000080,
   0x00802081, 0x00000081, 0x00000001, 0x00002000,
   0x00800001, 0x00002001, 0x00802080, 0x00800081,
   0x00002001, 0x00002080, 0x00800000, 0x00802001,
   0x00000080, 0x00800000, 0x00002000, 0x00802080
};

VSECPRIM_ROM(VSECPRIM_LOCAL, unsigned long) SP5[64] =
{
   0x00000100, 0x02080100, 0x02080000, 0x42000100,
   0x00080000, 0x00000100, 0x40000000, 0x02080000,
   0x40080100, 0x00080000, 0x02000100, 0x40080100,
   0x42000100, 0x42080000, 0x00080100, 0x40000000,
   0x02000000, 0x40080000, 0x40080000, 0x00000000,
   0x40000100, 0x42080100, 0x42080100, 0x02000100,
   0x42080000, 0x40000100, 0x00000000, 0x42000000,
   0x02080100, 0x02000000, 0x42000000, 0x00080100,
   0x00080000, 0x42000100, 0x00000100, 0x02000000,
   0x40000000, 0x02080000, 0x42000100, 0x40080100,
   0x02000100, 0x40000000, 0x42080000, 0x02080100,
   0x40080100, 0x00000100, 0x02000000, 0x42080000,
   0x42080100, 0x00080100, 0x42000000, 0x42080100,
   0x02080000, 0x00000000, 0x40080000, 0x42000000,
   0x00080100, 0x02000100, 0x40000100, 0x00080000,
   0x00000000, 0x40080000, 0x02080100, 0x40000100
};

VSECPRIM_ROM(VSECPRIM_LOCAL, unsigned long) SP6[64] =
{
   0x20000010, 0x20400000, 0x00004000, 0x20404010,
   0x20400000, 0x00000010, 0x20404010, 0x00400000,
   0x20004000, 0x00404010, 0x00400000, 0x20000010,
   0x00400010, 0x20004000, 0x20000000, 0x00004010,
   0x00000000, 0x00400010, 0x20004010, 0x00004000,
   0x00404000, 0x20004010, 0x00000010, 0x20400010,
   0x20400010, 0x00000000, 0x00404010, 0x20404000,
   0x00004010, 0x00404000, 0x20404000, 0x20000000,
   0x20004000, 0x00000010, 0x20400010, 0x00404000,
   0x20404010, 0x00400000, 0x00004010, 0x20000010,
   0x00400000, 0x20004000, 0x20000000, 0x00004010,
   0x20000010, 0x20404010, 0x00404000, 0x20400000,
   0x00404010, 0x20404000, 0x00000000, 0x20400010,
   0x00000010, 0x00004000, 0x20400000, 0x00404010,
   0x00004000, 0x00400010, 0x20004010, 0x00000000,
   0x20404000, 0x20000000, 0x00400010, 0x20004010
};

VSECPRIM_ROM(VSECPRIM_LOCAL, unsigned long) SP7[64] =
{
   0x00200000, 0x04200002, 0x04000802, 0x00000000,
   0x00000800, 0x04000802, 0x00200802, 0x04200800,
   0x04200802, 0x00200000, 0x00000000, 0x04000002,
   0x00000002, 0x04000000, 0x04200002, 0x00000802,
   0x04000800, 0x00200802, 0x00200002, 0x04000800,
   0x04000002, 0x04200000, 0x04200800, 0x00200002,
   0x04200000, 0x00000800, 0x00000802, 0x04200802,
   0x00200800, 0x00000002, 0x04000000, 0x00200800,
   0x04000000, 0x00200800, 0x00200000, 0x04000802,
   0x04000802, 0x04200002, 0x04200002, 0x00000002,
   0x00200002, 0x04000000, 0x04000800, 0x00200000,
   0x04200800, 0x00000802, 0x00200802, 0x04200800,
   0x00000802, 0x04000002, 0x04200802, 0x04200000,
   0x00200800, 0x00000000, 0x00000002, 0x04200802,
   0x00000000, 0x00200802, 0x04200000, 0x00000800,
   0x04000002, 0x04000800, 0x00000800, 0x00200002
};

VSECPRIM_ROM(VSECPRIM_LOCAL, unsigned long) SP8[64] =
{
   0x10001040, 0x00001000, 0x00040000, 0x10041040,
   0x10000000, 0x10001040, 0x00000040, 0x10000000,
   0x00040040, 0x10040000, 0x10041040, 0x00041000,
   0x10041000, 0x00041040, 0x00001000, 0x00000040,
   0x10040000, 0x10000040, 0x10001000, 0x00001040,
   0x00041000, 0x00040040, 0x10040040, 0x10041000,
   0x00001040, 0x00000000, 0x00000000, 0x10040040,
   0x10000040, 0x10001000, 0x00041040, 0x00040000,
   0x00041040, 0x00040000, 0x10041000, 0x00001000,
   0x00000040, 0x10040040, 0x00001000, 0x00041040,
   0x10001000, 0x00000040, 0x10000040, 0x10040000,
   0x10040040, 0x10000000, 0x00040000, 0x10001040,
   0x00000000, 0x10041040, 0x00040040, 0x10000040,
   0x10040000, 0x10001000, 0x10001040, 0x00000000,
   0x10041040, 0x00041000, 0x00041000, 0x00001040,
   0x00001040, 0x00040040, 0x10000000, 0x10041000
};

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/****************************************************************************
 ** Local functions
 ***************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/****************************************************************************
 ** Macros for rotate, get block ... etc
 ***************************************************************************/
VSECPRIM_LOCAL_FUNC(void) usekey(VSECPRIM_P2VAR_PARA(actU32) from, VSECPRIM_P2VAR_PARA(actU32) returned_key)
{
  VSECPRIM_P2VAR_PARA(actU32) to;
  VSECPRIM_P2VAR_PARA(actU32) endp;

  to = returned_key;
  endp = &returned_key[32];
  while (to < endp) *to++ = *from++;
}

VSECPRIM_LOCAL_FUNC(void) cookey(VSECPRIM_P2VAR_PARA(actU32) raw1, VSECPRIM_P2VAR_PARA(actU32) returned_key)
{
  VSECPRIM_P2VAR_PARA(actU32) cook;
  VSECPRIM_P2VAR_PARA(actU32) raw0;
  actU32 dough[32];
  int i;

  for (i = 0; i < 32; i++)
    dough[i] = 0;

  cook = dough;
  for (i = 0; i < 16; i++, raw1++)
  {
    raw0 = raw1++;
    *cook = (*raw0 & 0x00fc0000L) << 6;
    *cook |= (*raw0 & 0x00000fc0L) << 10;
    *cook |= (*raw1 & 0x00fc0000L) >> 10;
    *cook++ |= (*raw1 & 0x00000fc0L) >> 6;
    *cook = (*raw0 & 0x0003f000L) << 12;
    *cook |= (*raw0 & 0x0000003fL) << 16;
    *cook |= (*raw1 & 0x0003f000L) >> 4;
    *cook++ |= (*raw1 & 0x0000003fL);
  }
  usekey(dough, returned_key);
}

VSECPRIM_LOCAL_FUNC(void) scrunch(VSECPRIM_P2CONST_PARA(actU8) outof, VSECPRIM_P2VAR_PARA(actU32) into)
{
  *into = (*outof++ & 0xffL) << 24;
  *into |= (*outof++ & 0xffL) << 16;
  *into |= (*outof++ & 0xffL) << 8;
  *into++ |= (*outof++ & 0xffL);
  *into = (*outof++ & 0xffL) << 24;
  *into |= (*outof++ & 0xffL) << 16;
  *into |= (*outof++ & 0xffL) << 8;
  *into |= (*outof & 0xffL);
}

VSECPRIM_LOCAL_FUNC(void) unscrun(VSECPRIM_P2VAR_PARA(actU32) outof, VSECPRIM_P2VAR_PARA(actU8) into)
{
  *into++ = (actU8)((*outof >> 24) & 0xff);
  *into++ = (actU8)((*outof >> 16) & 0xff);
  *into++ = (actU8)((*outof >> 8) & 0xff);
  *into++ = (actU8)(*outof++ & 0xff);
  *into++ = (actU8)((*outof >> 24) & 0xff);
  *into++ = (actU8)((*outof >> 16) & 0xff);
  *into++ = (actU8)((*outof >> 8) & 0xff);
  *into = (actU8)(*outof & 0xff);
}


/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actDESInit()
 **
 **  This function initializes the DES algorithm (key setup etc.).
 **
 ** input:
 ** - info:       pointer to DES context structure
 ** - key:        pointer to user key
 ** - crypt_mode: encryption, decryption mode switch
 ** - iv:         pointer to initialization vector (only in CBC mode;
 **               of length actDES_BLOCK_SIZE; if iv==NULL, a zeroized
 **               block is used as iv)
 ** - block_mode: ECB, CBC mode switch
 **
 ** output:
 ** - info:       initialized DES context structure
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
VSECPRIM_FUNC(actRETURNCODE) actDESInit(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) key,
   actU8 crypt_mode, VSECPRIM_P2CONST_PARA(actU8) iv, actU8 block_mode,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   /* initialization mode, buffers, etc. */
   info->mode = block_mode;
   info->buffer_used = 0;
   switch (block_mode)
   {
   case actDES_ECB:
      break;
   case actDES_CBC:
      if (iv == 0)
      {
         actMemset(info->prev_block, 0, actDES_BLOCK_SIZE); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
      }
      else
      {
         actMemCpyByteArray(info->prev_block, iv, actDES_BLOCK_SIZE); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
      }
      break;
   default:
      return actEXCEPTION_ALGOID;
   }

   /* key setup */
   return actDESKeySetup(info, key, crypt_mode, watchdog);
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actDESKeySetup()
 **
 **  This function initializes round keys
 **
 ** input:
 ** - key:        pointer to user key
 ** - mode        switch for decryption keys
 **
 ** output:
 ** - info:       modified DES context structure
 **
 ** assumes:
 ** - actDESInit(info) is called once before calling this function
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actOK                  else
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actDESKeySetup(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) key,
   actU8 crypt_mode, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   if (!key)
   {
      return actEXCEPTION_NULL;
   }
   else
   {
      int i, j, l, m;
      char key_pc1[56], key_buff[56];
      actU32 subkeyn[32];

      /* user key permutation with PC1 */
      for (j = 0; j < 56; j++)
      {
         l = PC1[j];
         m = l & 0x07;
         key_pc1[j] = (key[l >> 3] & bytebit[m]) ? 1 : 0;
      }

      /* generate 16 subkeys */
      for (i = 0; i < 16; i++)
      {
         actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

         if (crypt_mode == DE1)
             m = (15 - i) << 1;
         else
             m = i << 1;

         subkeyn[m] = subkeyn[m+1] = 0L;

         /* shift upper 28 bits */
         for (j = 0; j < 28; j++)
         {
            l = j + totrotation[i];
            if (l < 28) key_buff[j] = key_pc1[l];
            else key_buff[j] = key_pc1[l - 28];
         }
         /* shift lower 28 bits */
         for (j = 28; j < 56; j++)
         {
            l = j + totrotation[i];
            if (l < 56) key_buff[j] = key_pc1[l];
            else key_buff[j] = key_pc1[l - 28];
         }

         /* subkey permutation with PC2 */
         for (j = 0; j < 24; j++)
         {
            if (key_buff[PC2[j]])    subkeyn[m]   |= bigbyte[j];
            if (key_buff[PC2[j+24]]) subkeyn[m+1] |= bigbyte[j];
         }
      }
      cookey(subkeyn, info->n_keys);

      actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
      return actOK;
   }
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actDESInitEncrypt()
 **
 **  This function initializes the DES algorithm (key setup etc.).
 **
 ** input:
 ** - info:       pointer to DES context structure
 ** - key:        pointer to user key
 ** - iv:         pointer to initialization vector (only in CBC mode;
 **               of length actDES_BLOCK_SIZE; if iv==NULL, a zeroized
 **               block is used as iv)
 ** - mode:       ECB, CBC mode switch
 **
 ** output:
 ** - info:       initialized DES context structure
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actEXCEPTION_ALGOID    mode is invalid
 **               actOK                  else
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actDESInitEncrypt(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) key,
   VSECPRIM_P2CONST_PARA(actU8) iv, actU8 mode,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   return actDESInit(info, key, EN0, iv, mode, watchdog);
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actDESEncrypt()
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
 ** - info:        pointer to initialized DES context structure
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
 ** - actDESInitEncrypt() is called once before calling this function
 ** - in!=NULL, out_buffer!=NULL are a valid pointers
 ** - in_length>=0, *out_length>=0 (at input)
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actDESEncrypt(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, int in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(int) out_length,
   int final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   /* out_size = blocks*8 */
   int out_size = ((in_length+info->buffer_used)/actDES_BLOCK_SIZE)*actDES_BLOCK_SIZE;

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
      actDESTransform(info, in, in_length, out_buffer, actDESEncryptMultipleBlocks, watchdog);
   }

   /* finalize ? */
   if (final != 0)
   {
      /* PKCS 5 padding of last buffered block */
      actU8 pad = (actU8)(actDES_BLOCK_SIZE - info->buffer_used);
      actMemset(info->buffer + info->buffer_used, pad, (unsigned int)pad); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
      /* encryption of last block */
      actDESEncryptMultipleBlocks(info, info->buffer, out_buffer+out_size, 1, watchdog);
   }

   actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
   return actOK;
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actDESInitDecrypt()
 **
 **  This function initializes the DES decryption.
 **
 ** input:
 ** - info:       pointer to DES context structure
 ** - key:        pointer to user key
 ** - iv:         pointer to initialization vector (only in CBC mode;
 **               of length actDES_BLOCK_SIZE; if iv==NULL, a zeroized
 **               block is used as iv)
 ** - mode:       ECB, CBC mode switch
 **
 ** output:
 ** - info:       initialized DES context structure
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actEXCEPTION_ALGOID    mode is invalid
 **               actOK                  else
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actDESInitDecrypt(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) key,
   VSECPRIM_P2CONST_PARA(actU8) iv, actU8 mode,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   return actDESInit(info, key, DE1, iv, mode, watchdog);
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actDESDecrypt()
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
 ** - info:        pointer to initialized DES context structure
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
 ** - actDESInitDecrypt() is called once before calling this function
 ** - in!=NULL, out_buffer!=NULL are a valid pointers
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actDESDecrypt(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, int in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, VSECPRIM_P2VAR_PARA(int) out_length,
   int final, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   int total_bytes = in_length+info->buffer_used;
   int out_size;

   /* if finalize: check (in_length+buffer_length)%8==0 */
   if (final!=0)
   {
      if ((!total_bytes) || ((total_bytes%actDES_BLOCK_SIZE)!=0))
      {
         return actEXCEPTION_INPUT_LENGTH;
      }
   }

   if (total_bytes > 0)
   {
     /* out_size = blocks*8 */
     out_size = ((total_bytes-1)/actDES_BLOCK_SIZE)*actDES_BLOCK_SIZE;
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
   if (in_length>0)
   {
      if (total_bytes<=actDES_BLOCK_SIZE)
      {
         actMemCpyByteArray(info->buffer + info->buffer_used, in, (unsigned int)in_length); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
         info->buffer_used += in_length;
      }
      else
      {
         if ((total_bytes%actDES_BLOCK_SIZE)==0)
         {
            actDESTransform(info, in, (int) (in_length-actDES_BLOCK_SIZE), out_buffer, actDESDecryptMultipleBlocks, watchdog);
            actMemCpyByteArray(info->buffer, in + in_length - actDES_BLOCK_SIZE, actDES_BLOCK_SIZE); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
            info->buffer_used = actDES_BLOCK_SIZE;
         }
         else
         {
            actDESTransform(info, in, in_length, out_buffer, actDESDecryptMultipleBlocks, watchdog);
         }
      }
   }

   if (final!=0)
   {
      /* decryption of the last buffered block */
      actDESDecryptMultipleBlocks(info, info->buffer, info->buffer, 1, watchdog);
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
 ** actRETURNCODE actDESInitEncryptBlock()
 **
 **
 **  This function initializes the DES block encryption.
 **
 ** input:
 ** - info:       pointer to DES context structure
 ** - key:        pointer to user key
 **
 ** output:
 ** - info:       initialized DES context structure
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actOK                  else
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actDESInitEncryptBlock(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) key,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   return actDESKeySetup(info, key, EN0, watchdog);
}

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actDESInitDecryptBlock()
 **
 **
 **  This function initializes the DES block decryption.
 **
 ** input:
 ** - info:       pointer to DES context structure
 ** - key:        pointer to user key
 **
 ** output:
 ** - info:       initialized DES context structure
 ** - returns:    actEXCEPTION_NULL      if key parameter is NULL
 **               actOK                  else
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actDESInitDecryptBlock(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info, VSECPRIM_P2CONST_PARA(actU8) key,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   return actDESKeySetup(info, key, DE1, watchdog);
}

/****************************************************************************
 **
 ** FUNCTION:
 ** void actDESCryptBlock()
 **
 **  This function encrypts the given blocks in different modes.
 **
 ** input:
 ** - key:         pointer to DES context structure
 ** - in_block:    pointer to blocks to be encrypted
 ** - out_block:   pointer to allocated output blocks
 **
 ** output:
 ** - out_block:   encrypted output blocks
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(void) actDESCryptBlock(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in_block, VSECPRIM_P2VAR_PARA(actU8) out_block,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   actU32 fval, work, right, leftt;
   VSECPRIM_P2VAR_PARA(actU32) key;
   actU32 inBlocktmp[2], outBlocktmp[2];
   int round;

   scrunch(in_block, inBlocktmp);

   leftt = inBlocktmp[0];
   right = inBlocktmp[1];
   key = info->n_keys;

   actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */

   /* initial permutation */
   work   = ((leftt >> 4)  ^ right) & 0x0f0f0f0f;
   right ^=    work;
   leftt ^=   (work << 4);
   work   = ((leftt >> 16) ^ right) & 0x0000ffff;
   right ^=    work;
   leftt ^=   (work << 16);
   work   = ((right >> 2)  ^ leftt) & 0x33333333;
   leftt ^=    work;
   right ^=   (work << 2);
   work   = ((right >> 8)  ^ leftt) & 0x00ff00ff;
   leftt ^=    work;
   right ^=   (work << 8);
   right  = ((right << 1) | ((right >> 31) & 1)) & 0xffffffff;
   work   = (leftt ^ right) & 0xaaaaaaaa;
   leftt ^=    work;
   right ^=    work;
   leftt  = ((leftt << 1) | ((leftt >> 31) & 1)) & 0xffffffff;


   for (round = 0; round < 8; round++)
   {
      work  = (right << 28) | (right >> 4);
      work ^= *key++;
      fval  = SP7[ work        & 0x3f];
      fval |= SP5[(work >>  8) & 0x3f];
      fval |= SP3[(work >> 16) & 0x3f];
      fval |= SP1[(work >> 24) & 0x3f];
      work  = right ^ *key++;
      fval |= SP8[ work        & 0x3f];
      fval |= SP6[(work >>  8) & 0x3f];
      fval |= SP4[(work >> 16) & 0x3f];
      fval |= SP2[(work >> 24) & 0x3f];
      leftt ^= fval;

      work  = (leftt << 28) | (leftt >> 4);
      work ^= *key++;
      fval  = SP7[ work        & 0x3f];
      fval |= SP5[(work >>  8) & 0x3f];
      fval |= SP3[(work >> 16) & 0x3f];
      fval |= SP1[(work >> 24) & 0x3f];
      work  = leftt ^ *key++;
      fval |= SP8[ work        & 0x3f];
      fval |= SP6[(work >>  8) & 0x3f];
      fval |= SP4[(work >> 16) & 0x3f];
      fval |= SP2[(work >> 24) & 0x3f];
      right ^= fval;

      actL2trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */ /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
   }

   right  = (right << 31) | (right >> 1);
   work   = (leftt ^ right) & 0xaaaaaaaa;
   leftt ^= work;
   right ^= work;
   leftt  = (leftt << 31) | (leftt >> 1);
   work   = ((leftt >> 8) ^ right) & 0x00ff00ff;
   right ^= work;
   leftt ^= (work << 8);
   work   = ((leftt >> 2) ^ right) & 0x33333333;
   right ^= work;
   leftt ^= (work << 2);
   work   = ((right >> 16) ^ leftt) & 0x0000ffff;
   leftt ^= work;
   right ^= (work << 16);
   work   = ((right >> 4) ^ leftt) & 0x0f0f0f0f;
   leftt ^= work;
   right ^= (work << 4);

   outBlocktmp[1] = leftt;
   outBlocktmp[0] = right;

   unscrun(outBlocktmp, out_block);
   actL1trigger(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */  /* SBSW_VSECPRIM_FUNCTION_CALL_WATCHDOG */
}

/****************************************************************************
 **
 ** FUNCTION:
 ** void actDESEncryptMultipleBlocks()
 **
 **  This function encrypts the given blocks in different modes.
 **
 ** input:
 ** - info:        pointer to DES context structure
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
VSECPRIM_FUNC(void) actDESEncryptMultipleBlocks(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer,
   int blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   VSECPRIM_P2VAR_PARA(actU8) prev_block = info->prev_block;
   int i, bcount;

   switch (info->mode)
   {
   case actDES_CBC:
      for (bcount=0; bcount<blocks; ++bcount)
      {
         /* out_block = prev_block ^ in_block */
         for (i=0; i<actDES_BLOCK_SIZE; ++i)
         {
            out_buffer[i] = (actU8)(prev_block[i] ^ *in++);
         }
         /* out_block = Encrypt(out_block) */
         actDESCryptBlock(info, out_buffer, out_buffer, watchdog);
         /* prev_block = out_block */
         for (i=0; i<actDES_BLOCK_SIZE; ++i)
         {
            prev_block[i] = *out_buffer++;
         }
      }
      break;
   default:   /* ECB */
      for (bcount=0; bcount<blocks; ++bcount, in += actDES_BLOCK_SIZE, out_buffer += actDES_BLOCK_SIZE)
      {
         /* out_block = Encrypt(in_block) */
         actDESCryptBlock(info, in, out_buffer, watchdog);
      }
      break;
   }
}

/****************************************************************************
 **
 ** FUNCTION:
 ** void actDESDecryptMultipleBlocks()
 **
 **  This function decrypts the given blocks in different modes.
 **
 ** input:
 ** - info:        pointer to DES context structure
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
VSECPRIM_FUNC(void) actDESDecryptMultipleBlocks(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, VSECPRIM_P2VAR_PARA(actU8) out_buffer,
   int blocks, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   VSECPRIM_P2VAR_PARA(actU8) prev_block = info->prev_block;
   int i, bcount;

   switch (info->mode)
   {
   case actDES_CBC:
      for (bcount=0; bcount<blocks; ++bcount)
      {
         /* out_block = Decrypt(in_block) */
         actDESCryptBlock(info, in, out_buffer, watchdog);
         /* out_block = prev_block ^ out_block */
         /* prev_block = in_block */
         for (i=0; i<actDES_BLOCK_SIZE; ++i)
         {
            *out_buffer++ ^= prev_block[i];
            prev_block[i] = *in++;
         }
      }
      break;
   default:   /* ECB */
      for (bcount=0; bcount<blocks; ++bcount, in += actDES_BLOCK_SIZE, out_buffer += actDES_BLOCK_SIZE)
      {
         /* out_block = Decrypt(in_block) */
         actDESCryptBlock(info, in, out_buffer, watchdog);
      }
   break;
   }
}


/****************************************************************************
 **
 ** FUNCTION:
 ** void actDESTransform()
 **
 **  This function transforms input data of any length.
 **  ((in_length+buffered_bytes)/8) blocks will be transformed and written
 **  to out_buffer, ((in_length+buffered_bytes)%8) bytes will be buffered,
 **  where 0 <= buffered_bytes < 8.
 **
 ** input:
 ** - info:        pointer to initialized DES context structure
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
VSECPRIM_FUNC(void) actDESTransform(
   VSECPRIM_P2VAR_PARA(actDESSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) in, int in_length,
   VSECPRIM_P2VAR_PARA(actU8) out_buffer, actDESTransformFctType transform,
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
         if (transform == actDESEncryptMultipleBlocks)
            actDESEncryptMultipleBlocks(info, info->buffer, out_buffer, 1, watchdog);
         else
            actDESDecryptMultipleBlocks(info, info->buffer, out_buffer, 1, watchdog);
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
   if (transform == actDESEncryptMultipleBlocks)
      actDESEncryptMultipleBlocks(info, in, out_buffer, blocks, watchdog);
   else
      actDESDecryptMultipleBlocks(info, in, out_buffer, blocks, watchdog);
# else
   transform(info, in, out_buffer, blocks, watchdog);
# endif

   /* copy left overs into info->buffer */
   info->buffer_used = in_length - (diff + bytes);
   actMemCpyByteArray(info->buffer, in + bytes, (unsigned int)(info->buffer_used)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
}

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTDES_ENABLED == STD_ON) */

