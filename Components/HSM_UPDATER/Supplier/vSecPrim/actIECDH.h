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
/*!        \file  actIECDH.h
 *        \brief  Interface for ECDSA verification.
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

#ifndef ACTIECDH_H
# define ACTIECDH_H

# include "actITypes.h"

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
 ** FUNCTION:
 **   actECDSAGetSecretCompLength
 **
 **  This function returns the secret component length in bytes
 **  for the desired curve.
 **
 ** input:
 ** - domain:      domain parameter
 **
 ** output:
 ** - returns:    length of each secret component (x, y) in bytes
 **                 (0, if domain not valid)
 **
 ** assumes:
 **
 ** uses:
 ***************************************************************************/
  VSECPRIM_FUNC(actLengthType) actECDSAGetSecretCompLength(VSECPRIM_P2ROMCONST_PARA(actU8) domain);

/****************************************************************************
 **
 ** FUNCTION:
 **  actECDHInitGetSecret
 **
 **  This function initializes the ECC workspace.
 **
 ** input:
 ** - domain:      domain parameter
 ** - domain_ext:  domain parameter extensions (Montgomery constants etc.)
 ** - wksp:        workspace
 ** - wksp_len:    length of workspace in bytes
 **
 ** output:
 ** - wksp:       initialized workspace
 ** - returns:    actEXCEPTION_NULL         if an input parameter is NULL
 **               actEXCEPTION_DOMAIN       domain decoding error
 **               actEXCEPTION_DOMAIN_EXT   domain_ext decoding error
 **               actEXCEPTION_MEMORY       wksp_len to small
 **               actOK                     else
 **
 ** assumes:
 **
 ** uses:
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actECDHInitGetSecret(VSECPRIM_P2ROMCONST_PARA(actU8) domain, VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp, actLengthType wksp_len);

/****************************************************************************
 **
 ** FUNCTION:
 **   actECDHGetSecret
 **
 **  This function calculates the common secret d1 * Q2 (= d1 * d2 * G)
 **
 ** input:
 ** - privatekey:  the private key d1 of the key pair (d1, Q1)
 ** - publickey_x: x-coordinate of the public key Q2 of the key pair (d2, Q2)
 ** - publickey_y: y-coordinate of the public key Q2 of the key pair (d2, Q2)
 ** - secret_x:    buffer to store x-coordinate of the secret d1 * Q2
 ** - secret_y:    buffer to store y-coordinate of the secret d1 * Q2
 **                  (optional secret_y maybe NULL)
 ** - wksp:        initialized workspace
 ** - watchdog:    Watchdog trigger function pointer
 **
 ** output:
 ** - secret_x:    x-coordinate of the secret d1 * Q2
 ** - secret_y:    y-coordinate of the secret d1 * Q2
 ** - returns:    actEXCEPTION_NULL       if an input parameter is NULL
 **               actEXCEPTION_PRIVKEY    if (d==0||d>=n)
 **               actEXCEPTION_PUBKEY     if Q2 is invalid
 **               actEXCEPTION_UNKNOWN    internal error (result point
 **                                       not on curve)
 **               actOK                   else
 **
 ** assumes:
 ** - wksp has been initialized with actECDHInitGetSecret
 **
 ** uses:
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actECDHGetSecret(VSECPRIM_P2CONST_PARA(actU8) privatekey,
                                              VSECPRIM_P2CONST_PARA(actU8) publickey_x, VSECPRIM_P2CONST_PARA(actU8) publickey_y,
                                              VSECPRIM_P2VAR_PARA(actU8) secret_x, VSECPRIM_P2VAR_PARA(actU8) secret_y, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp,
                                              VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/****************************************************************************
 **
 ** FUNCTION:
 **  actECDHInitKeyDerive
 **
 **  This function initializes the ECC workspace.
 **
 ** input:
 ** - domain:      domain parameter
 ** - domain_ext:  domain parameter extensions (Montgomery constants etc.)
 ** - wksp:        workspace
 ** - wksp_len:    length of workspace in bytes
 **
 ** output:
 ** - wksp:       initialized workspace
 ** - returns:    actEXCEPTION_NULL         if an input parameter is NULL
 **               actEXCEPTION_DOMAIN       domain decoding error
 **               actEXCEPTION_DOMAIN_EXT   domain_ext decoding error
 **               actEXCEPTION_MEMORY       wksp_len to small
 **               actOK                     else
 **
 ** assumes:
 **
 ** uses:
 ***************************************************************************/
    VSECPRIM_FUNC(actRETURNCODE) actECDHInitKeyDerive(VSECPRIM_P2ROMCONST_PARA(actU8) domain, VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp, actLengthType wksp_len);

/****************************************************************************
 **
 ** FUNCTION:
 **   actECDHKeyDerive
 **
 **  This function calculates the common secret d1 * Q2 (= d1 * d2 * G)
 **  and derives the output key from the x-coordinate of the secret with
 **  the KDF2HMACSHA1 derivation function of the library.
 **
 **
 ** input:
 ** - privatekey:  the private key d1 of the key pair (d1, Q1)
 ** - publickey_x: x-coordinate of the public key Q2 of the key pair (d2, Q2)
 ** - publickey_y: y-coordinate of the public key Q2 of the key pair (d2, Q2)
 ** - iteration_count:  number of iterations used for the key derivation,
 **                     if zero, actKDF2_DEFAULT_ITERATION_COUNT is used.
 ** - salt:        pointer to the optional salt (if NULL, no salt is used)
 ** - salt_length: length of salt in bytes
 ** - key:         pointer to the output key buffer
 ** - key_length:  length of output key buffer in bytes
 ** - wksp:        initialized workspace
 ** - watchdog:    Watchdog trigger function pointer
 **
 ** output:
 ** - key:         the derived key of length key_length
 ** - returns:    actEXCEPTION_NULL       if an input parameter is NULL
 **               actEXCEPTION_PRIVKEY    if (d==0||d>=n)
 **               actEXCEPTION_PUBKEY     if Q2 is invalid
 **               actEXCEPTION_UNKNOWN    internal error (result point
 **                                       not on curve)
 **               actOK                   else
 **
 ** assumes:
 ** - wksp has been initialized with actECDHInitGetSecret
 **
 ** uses:
 ***************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actECDHKeyDerive(VSECPRIM_P2CONST_PARA(actU8) privatekey, VSECPRIM_P2CONST_PARA(actU8) publickey_x,
                                              VSECPRIM_P2CONST_PARA(actU8) publickey_y, actLengthType iteration_count,
                                              VSECPRIM_P2CONST_PARA(actU8) salt, actLengthType salt_length, VSECPRIM_P2VAR_PARA(actU8) key, actLengthType key_length, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp,
                                              VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
}                               /* extern "C" */
# endif

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTIECDH_H */

/**********************************************************************************************************************
 *  END OF FILE: actIECDH.h
 *********************************************************************************************************************/
