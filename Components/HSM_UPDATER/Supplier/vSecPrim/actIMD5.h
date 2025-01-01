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
/*!        \file  actIMD5.h
 *        \brief  This file contains the interface for MD5 hash algorithm.
 *
 *      \details  Currently the actClib version is used.
 *                This file is part of the embedded systems library cvActLib/ES
 *********************************************************************************************************************/

#ifndef ACTIMD5_H
# define ACTIMD5_H

# include "actITypes.h"

/****************************************************************************
 ** Types and constants
 ***************************************************************************/

# define actHASH_SIZE_MD5                                             (16u)
# define actHASH_BLOCK_SIZE_MD5                                       (64u)

/* Workspace structure for MD5 */
typedef struct
{
   actU32 digest [4];                       /* message digest state buffer */
   actU32 count  [2];                       /* 64 bit input count */
   actLengthType buffer_used;            /* number of bytes saved in buffer */
   actU8  buffer [actHASH_BLOCK_SIZE_MD5];  /* remaining data buffer */
} actMD5STRUCT;

/****************************************************************************
 ** Function Prototypes
 ***************************************************************************/

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C" {
# endif

# define VSECPRIM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actMD5Init(actMD5STRUCT* info)
 **
 **  This function initializes the MD5 algorithm.
 **
 ** input:
 ** - info:       pointer to hash context structure
 **
 ** output:
 ** - info:       initialized hash context structure
 ** - returns:    actOK always
 **
 ** assumes:
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actMD5Init (VSECPRIM_P2VAR_PARA(actMD5STRUCT) info);

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actMD5Update(actMD5STRUCT* info,
 **                            const actU8* dataIN,
 **                            int length,
 **                            void (*watchdog) (void));
 **
 **  This function hashes the given data and can be called arbitrary
 **  often between an initialize and finalize of the MD5 algorithm.
 **  Uses any data already in the actMD5STRUCT structure and leaves
 **  any partial data block there.
 **
 ** input:
 ** - info:       pointer to hash context structure
 ** - dataIN:     pointer to data to be hashed
 ** - length:     length of data in bytes
 ** - watchdog:   pointer to watchdog reset function
 **
 ** output:
 ** - info:       actualized hash context structure
 ** - returns:    actEXCEPTION_LENGTH   total input more than 2^64 - 1 bit
 **               actOK                 else
 **
 ** assumes:
 ** - actMD5Init() is called once before calling this function
 ** - dataIN != NULL is a valid pointer
 ** - length >= 0
 **
 ** uses:
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actMD5Update(
   VSECPRIM_P2VAR_PARA(actMD5STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actMD5Finalize(actMD5STRUCT* info,
 **                              actU8 hash[actHASH_SIZE_MD5],
 **                              void (*watchdog) (void));
 **
 **  This function finalizes the MD5 algorithm and delivers the hash value.
 **
 ** input:
 ** - info:       pointer to hash context structure
 ** - hash:       byte array to contain the hash value
 ** - watchdog:   pointer to watchdog reset function
 **
 ** output:
 ** - info:       finalized hash context structure
 ** - hash:       the final hash value,
 **                  (big endian of length actHASH_SIZE_MD5)
 ** - returns:    actOK always
 **
 ** assumes:
 ** - actMD5Init() is called once before calling this function
 **
 ** uses:
 ** - actHASH_SIZE_MD5
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actMD5Finalize (
   VSECPRIM_P2VAR_PARA(actMD5STRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

#endif /* ACTIMD5_H */

