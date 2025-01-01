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
/*!        \file  actBigNumGCD.h
 *        \brief  A basic (unsigned) integer and module arithmetic used for elliptic curve point arithmetic.
 *
 *      \details Currently the actClib version is used. 
 *               This file is part of the embedded systems library actCLib
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

#ifndef ACTBIGNUMGCD_H
# define ACTBIGNUMGCD_H

# include "actITypes.h"
# include "actConfig.h"

/****************************************************************************
 ** Function Prototypes
 ***************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C"
{
# endif

/****************************************************************************
 **
 ** void actBNGCDix(const actBNDIGIT* a,
 **                 actBNDIGIT* a_inv,
 **                 const actBNRING* Field,
 **                 actBNDIGIT* t[])
 **
 **  Special version of the extended Euclidian algorithm for field
 **  inversion:   a_inv = a^-1 mod p   (p==Field->m must be prime).
 **  Implementation Reference: MOV 97, algorithm 14.61.
 **
 ** input:                                              (length in digits)
 ** - a:      field element to be inverted (a > 0)        p_length
 ** - a_inv:  field element to store the result             p_length+1
 ** - Field   the underlying field (see assumptions)
 ** - Field->m:        the field prime p                    p_length
 ** - Field->m_length: equals to m_length
 ** - t[0..3]:  4 temporary BigNum variables                4*(p_length+1)
 **
 ** output:
 ** - a_inv:  a_inv = a^-1 mod p                            p_length
 **
 ** assumes:
 ** - a > 0
 **
 ***************************************************************************/
VSECPRIM_FUNC(void) actBNGCDix(
   VSECPRIM_P2CONST_PARA(actBNDIGIT) a, VSECPRIM_P2VAR_PARA(actBNDIGIT) a_inv,
   VSECPRIM_P2CONST_PARA(actBNRING) Field, VSECPRIM_P2VAR_PARA(actBNDIGIT) t[]);

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
}  /* extern "C" */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTBIGNUMGCD_H */

/**********************************************************************************************************************
 *  END OF FILE: actBigNumGCD.h
 *********************************************************************************************************************/
