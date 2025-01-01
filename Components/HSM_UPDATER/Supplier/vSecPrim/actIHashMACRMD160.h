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
/*!        \file  actIHashMACRMD160.h
 *        \brief  This file contains the interface for RIPEMD-160 based Hash MAC algorithm.
 *
 *      \details  Currently the actClib version is used.
 *                This file is part of the embedded systems library cvActLib/ES
 *********************************************************************************************************************/

#ifndef ACTIHASHMACRMD160_H
# define ACTIHASHMACRMD160_H

# include "actITypes.h"
# include "actIRMD160.h"

/****************************************************************************
 ** Types and constants
 ***************************************************************************/

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
 ** actRETURNCODE actHashMACRMD160Init(actHASHMACRMD160STRUCT* info,
 **                                    const actU8* key,
 **                                    int key_length,
 **                                    void (*watchdog) (void));
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
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actHashMACRMD160Update(actHASHMACRMD160STRUCT* info,
 **                                      const actU8* dataIN,
 **                                      int length,
 **                                      void (*watchdog) (void));
 **
 **  This function hashes the given data and can be called arbitrary
 **  often between an initialize and finalize of the HashMAC algorithm.
 **  Uses any data already in the actSHASTRUCT structure and leaves
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
VSECPRIM_FUNC(actRETURNCODE) actHashMACRMD160Update(
   VSECPRIM_P2VAR_PARA(actHASHMACRMD160STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actHashMACRMD160Finalize(actHASHMACRMD160STRUCT* info,
 **                                        actU8 hash[actHASH_SIZE_RMD160],
 **                                        void (*watchdog) (void));
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
 **                  (big endian of length actHASH_SIZE_SHA)
 ** - returns:    actOK always
 **
 ** assumes:
 ** - actHashMACInit() is called once before calling this function
 **
 ** uses:
 ** - actHASH_SIZE_SHA
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actHashMACRMD160Finalize(
   VSECPRIM_P2VAR_PARA(actHASHMACRMD160STRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

#endif /* ACTIHASHMAC_H */

