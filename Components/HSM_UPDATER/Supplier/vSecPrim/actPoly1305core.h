/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 1999 - 2017 cv cryptovision GmbH.                                                All rights reserved.
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
/*!        \file  actPoly1305core.h
 *        \brief  Poly1305core implementation.
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

/****************************************************************************
 **
 ** Core Poly1305 implementation
 **
 ** constants:
 **
 ** types:
 **
 ** macros:
 **
 ** local functions:
 **
 ** global functions:
 **   actEd25519_initCore
 **   actEd25519_importKeyPair
 **   actEd25519_sign
 **   actEd25519_verify
 **
 ***************************************************************************/

#ifndef ACTPOLY1305CORE_H
# define ACTPOLY1305CORE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "actIPoly1305.h"

 /* PRQA S 5209 EOF */ /* MD_VSECPRIM_USE_OF_BASIC_TYPES */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C"
{
# endif

/**********************************************************************************************************************
 *  MACROS
 *********************************************************************************************************************/

# define BNBYTES_128                                                  ((128u + (8u -1u)) /8u)
# define BNBYTES_129                                                  ((129u + (8u -1u)) /8u)
# define BNBYTES_130                                                  ((130u + (8u -1u)) /8u)
# define BNDIGITS_128                                                 ((BNBYTES_128 + (actBN_BYTES_PER_DIGIT -1u)) /actBN_BYTES_PER_DIGIT)
# define BNDIGITS_129                                                 ((BNBYTES_129 + (actBN_BYTES_PER_DIGIT -1u)) /actBN_BYTES_PER_DIGIT)
# define BNDIGITS_130                                                 ((BNBYTES_130 + (actBN_BYTES_PER_DIGIT -1u)) /actBN_BYTES_PER_DIGIT)

typedef struct
{
  actBNDIGIT r[BNDIGITS_128]; /* key.r */
  actBNDIGIT s[BNDIGITS_128]; /* key.s */

  actBNDIGIT a[BNDIGITS_130 + 1u]; /* accu - actBNReduce needs one extra digit!! */
  actBNDIGIT p[BNDIGITS_130]; /* prime (2**130-5) */
  actBNDIGIT d[BNDIGITS_129]; /* padded data (in BNDIGIT representation) */
  actBNDIGIT tmp[BNDIGITS_130 + /* temp - stores (accu * r) */
    BNDIGITS_128 + 1u]; /* actBNReduce needs one extra digit!! */
} poly1305context;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VSECPRIM_FUNC(void) actPoly1305_init(VSECPRIM_P2VAR_PARA(actPoly1305Context) context, VSECPRIM_P2CONST_PARA(actU8) key);
VSECPRIM_FUNC(void) actPoly1305_block(VSECPRIM_P2VAR_PARA(actPoly1305Context) context, VSECPRIM_P2CONST_PARA(actU8) data, const actU8 pad, VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));
VSECPRIM_FUNC(void) actPoly1305_finish(VSECPRIM_P2VAR_PARA( actPoly1305Context ) context, VSECPRIM_P2VAR_PARA( actU8 ) tag);

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

#endif /* ACTPOLY1305CORE_H */

/**********************************************************************************************************************
 *  END OF FILE: actIAES.h
 *********************************************************************************************************************/
