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
/*!        \file  actECDH.c
 *        \brief  Implementation file for actECDH.h
 *
 *      \details This file is part of the embedded systems library cvActLib
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

#define ACTECDH_SOURCE

/****************************************************************************
 **
 ** This file contains: Implementation file for actECDH.h
 **
 ** constants:
 **
 ** types:
 **
 ** macros:
 **
 ** functions:
 **   actECDHp
 **
 ***************************************************************************/

#include "actECDH.h"
#include "actECLengthInfo.h"

#if (VSECPRIM_ACTECDH_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/* PRQA S 2889 EOF */ /* MD_VSECPRIM_QM_ONLY_RETURN_PATHS */

# define VSECPRIM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/****************************************************************************
 ** Global Functions
 ***************************************************************************/

/****************************************************************************
 **
 ** FUNCTION:
 **  actECDHp
 **
 **  This function implements the ECDH protocol arithmetic.
 **
 ** input:                                              (length in digits)
 ** - d:     my private key                                 n_length
 ** - Q:     your (affine) public key                       2*p_length
 ** - actPoint: buffer to store d*Q                            3*p_length
 ** - Curve: the underlying curve (see assumptions)
 ** - Curve->p_field: the underlying field GF(p):
 ** -        p_field->m:        the modulus p               p_length
 ** -        p_field->m_length: equals to p_length
 ** -        p_field->RR:       constant for Montgomery     p_length
 ** -        p_field->m_bar:    constant for Montgomery     1
 ** -        p_field->prime_structure==curveid
 ** -        p_field->window_size for modular exponentiation
 ** - Curve->n_field: the field GF(n):
 ** -        n_field->m_length: equals to n_length
 ** - Curve->b_R:    coefficient b of curve equation        p_bytes
 ** - Curve->t[0..(i-1)]:  i temporary BigNum variables,   i*(max_length+1)
 **                        where i = actEC_BIGNUM_TMP
 **        [ Notation: max_length = max(p_length, n_length) ]
 ** - wksp_ptr:  temporary BigNum workspace for Q*d         3*p_length
 ** - watchdog:  Watchdog trigger function pointer
 **
 ** output:
 ** - actPoint: d*Q                                            3*p_length
 ** - returns:    actEXCEPTION_PUBKEY     if Q2 is not on curve
 **               actEXCEPTION_UNKNOWN    internal error (result point
 **                                       not on curve)
 **               actOK                   else
 **
 ** assumes:
 ** - The actECCURVE structure parameter 'Curve' holds all necessary
 **   information and the workspace. It has to be initialized as far as
 **   listed above. Please have a look at the actECCURVE definition in
 **   actECPoint.h; an example for the usage of this function is the
 **   actECDSAVerify(.) implementation in actIECDSA.c, which is basically
 **   a call of actECDSAvp(.) with all previous initializations.
 ** - Q is in affine representation (X, Y, 1)
 **
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actECDHp(
   VSECPRIM_P2CONST_PARA(actBNDIGIT) d, VSECPRIM_P2CONST_PARA(actECPOINT) Q,
   VSECPRIM_P2VAR_PARA(actECPOINT) point, VSECPRIM_P2VAR_PARA(actECCURVE) Curve,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
   /* Convert Q to Montgomery Representation */
   actECPToMont(Q, Curve, watchdog);

   /* check if Q is on curve Q before continue */
   if (actECPointIsOnCurve(Q, Curve, watchdog) != actOK)
   {
      return actEXCEPTION_PUBKEY;
   }

   /* Compute actPoint = d*Q */
   actECPMult(Q, d, point, Curve, watchdog);
   /* Transform actPoint to affine */
   if (actECPToAffineFromMont(point, Curve, 0, watchdog) != actOK) { return actEXCEPTION_UNKNOWN; }

   return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTECDH_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: actECDH.c
 *********************************************************************************************************************/
