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
/*!        \file  actIRMD160.h
 *        \brief  This file contains the interface for RMD160 hash algorithm.
 *
 *      \details  Currently the actClib version is used.
 *                This file is part of the embedded systems library cvActLib/ES
 *********************************************************************************************************************/

#ifndef ACTIRMD160_H
# define ACTIRMD160_H

# include "actITypes.h"

/* PRQA S 5209 EOF */ /* MD_VSECPRIM_USE_OF_BASIC_TYPES */

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
 ** actRETURNCODE actRMD160Init(actRMD160STRUCT* info)
 **
 **  This function initializes the RMD160 algorithm.
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
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actRMD160Init(VSECPRIM_P2VAR_PARA(actRMD160STRUCT) info);

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actRMD160Update(actRMD160STRUCT* info,
 **                               const actU8* dataIN,
 **                               int length,
 **                               void (*watchdog) (void));
 **
 **  This function hashes the given data and can be called arbitrary
 **  often between an initialize and finalize of the RMD160 algorithm.
 **  Uses any data already in the actRMD160STRUCT structure and leaves
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
 ** - actRMD160Init() is called once before calling this function
 ** - dataIN != NULL is a valid pointer
 ** - length >= 0
 **
 ** uses:
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actRMD160Update(
   VSECPRIM_P2VAR_PARA(actRMD160STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/****************************************************************************
 **
 ** FUNCTION:
 ** actRETURNCODE actRMD160Finalize(actRMD160STRUCT* info,
 **                                 actU8 hash[actHASH_SIZE_RMD160],
 **                                 void (*watchdog) (void));
 **
 **  This function finalizes the RMD160 algorithm and delivers the hash value.
 **
 ** input:
 ** - info:       pointer to hash context structure
 ** - hash:       byte array to contain the hash value
 ** - watchdog:   pointer to watchdog reset function
 **
 ** output:
 ** - info:       finalized hash context structure
 ** - hash:       the final hash value,
 **                  (big endian of length actHASH_SIZE_RMD160)
 ** - returns:    actOK always
 **
 ** assumes:
 ** - actRMD160Init() is called once before calling this function
 **
 ** uses:
 ** - actHASH_SIZE_RMD160
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actRMD160Finalize(
   VSECPRIM_P2VAR_PARA(actRMD160STRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

#endif /* ACTIRMD160_H */

