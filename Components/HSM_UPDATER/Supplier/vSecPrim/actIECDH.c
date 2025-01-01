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
/*!        \file  actIECDH.c
 *        \brief  Implementation file for actIECDH.h
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
#define ACTIECDH_SOURCE

/****************************************************************************
 **
 ** This file contains: Implementation file for actIECDH.h
 **
 ** constants:
 **
 ** types:
 **
 ** global variables:
 **
 ** macros:
 **
 ** functions:
 **   actECDHGetSecret
 **
 ***************************************************************************/

#include "actIECDH.h"
#include "actIECKey.h"
#include "actIKDF2.h"
#include "actECTools.h"
#include "actECDH.h"
#include "actECPoint.h"
#include "actECLengthInfo.h"
#include "actUtilities.h"
#include "actConfig.h"

#if (VSECPRIM_ACTIECDH_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/* PRQA S 2889 EOF */ /* MD_VSECPRIM_QM_ONLY_RETURN_PATHS */
/* PRQA S 6060 EOF */ /* MD_VSECPRIM_QM_ONLY_METRIC */
/* PRQA S 0310 EOF */ /* MD_VSECPRIM_QM_ONLY_CASTING_POINTER_TYPE */

/****************************************************************************
 ** Global Functions
 ***************************************************************************/
# define VSECPRIM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
 **
 ***************************************************************************/
VSECPRIM_FUNC(actLengthType) actECDSAGetSecretCompLength(VSECPRIM_P2ROMCONST_PARA(actU8) domain)
{
  return actECGetPublicKeyCompLength(domain);
}

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
VSECPRIM_FUNC(actRETURNCODE) actECDHInitGetSecret(VSECPRIM_P2ROMCONST_PARA(actU8) domain, VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp, actLengthType wksp_len)
{
  return actECInit(domain, domain_ext, (VSECPRIM_P2CONST_PARA(actU8)) NULL_PTR, actEC_ALGO_FLAG_DH_PRIM, &(wksp->baseData), wksp_len);
}

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
                                              VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE returncode;
  VSECPRIM_P2VAR_PARA(actECCURVE) Curve = &(wksp->baseData.Curve);
  actLengthType p_length = Curve->p_field.m_length;
  actLengthType p_bytes = Curve->p_field.m_byte_length;
  actLengthType n_length = Curve->n_field.m_length;
  actLengthType n_bytes = Curve->n_field.m_byte_length;
  actECPOINT Q, point;
  VSECPRIM_P2VAR_PARA(actBNDIGIT) d;

  /* any null pointers ? */
  if ((privatekey == NULL_PTR) || (publickey_x == NULL_PTR) || (publickey_y == NULL_PTR) || (secret_x == NULL_PTR))
  {
    return actEXCEPTION_NULL;
  }

  d = wksp->dataPair.privKeys.privKey; /* In fact, d is the private key; however, the buffer wksp->hashed_message has the correct length */
  Q.x = wksp->public_key_x;
  Q.y = wksp->public_key_y;
  point.x = wksp->multG.kG.xcoord;
  point.y = wksp->multG.kG.ycoord;
  point.z = wksp->multG.kG.zcoord;

  /* initialization of d */
  actBNSetOctetString(d, n_length, privatekey, n_bytes);

  /* check 0 < d < n before continue */
  if (actBNIsZero(d, n_length) == TRUE)
  {
    return actEXCEPTION_PRIVKEY;
  }
  if (actBNCompare(d, Curve->n_field.m, n_length) >= actCOMPARE_EQUAL)
  {
    return actEXCEPTION_PRIVKEY;
  }

  /* initialization of Q */
  actBNSetOctetString(Q.x, p_length, publickey_x, p_bytes);
  actBNSetOctetString(Q.y, p_length, publickey_y, p_bytes);
  Q.is_affine = TRUE;
  Q.is_infinity = FALSE;

  /*
     Call ECDHp and extract secret
   */

  /* calculate d*Q */
  returncode = actECDHp(d, &Q, &point, Curve, watchdog);

  /* if ok, write secret to output */
  if (returncode == actOK)
  {
    /* secret_x = x-coordinate of d*Q */
    actBNOctetString(secret_x, p_bytes, point.x, p_length);
    /* secret_y = x-coordinate of d*Q */
    if (secret_y != NULL_PTR)
    {
      actBNOctetString(secret_y, p_bytes, point.y, p_length);
    }
  }

  /* wipe local d */
  actBNSetZero(d, n_length);

  return returncode;
}

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
VSECPRIM_FUNC(actRETURNCODE) actECDHInitKeyDerive(VSECPRIM_P2ROMCONST_PARA(actU8) domain, VSECPRIM_P2ROMCONST_PARA(actU8) domain_ext, VSECPRIM_P2VAR_PARA(actECPSTRUCT) wksp, actLengthType wksp_len)
{
  return actECInit(domain, domain_ext, (VSECPRIM_P2CONST_PARA(actU8)) NULL_PTR, actEC_ALGO_FLAG_DH, &(wksp->baseData), wksp_len);
}

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
                                              VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  actRETURNCODE returncode;
  actLengthType p_length = wksp->baseData.Curve.p_field.m_length;
  VSECPRIM_P2VAR_PARA(actU8) secret_x = (VSECPRIM_P2VAR_PARA(actU8))(wksp->msg.secret_x);

  /* calculate secret_x */
  returncode = actECDHGetSecret(privatekey, publickey_x, publickey_y, secret_x, (VSECPRIM_P2VAR_PARA(actU8)) NULL_PTR, wksp, watchdog);
  if (returncode != actOK)
  {
    return returncode;
  }

  /* derive key from secret_x */
  returncode = actKDF2Init((VSECPRIM_P2VAR_PARA(actKDF2STRUCT)) wksp, iteration_count);
  if (returncode != actOK)
  {
    return returncode;
  }
  returncode = actKDF2Derive((VSECPRIM_P2VAR_PARA(actKDF2STRUCT)) wksp, secret_x, p_length, salt, salt_length, key, key_length, actHASHMACSHA1_ALGO_ID, actHASH_SIZE_SHA);
  if (returncode != actOK)
  {
    return returncode;
  }

  return actOK;
}

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_ACTIECDH_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: actIECDH.c
 *********************************************************************************************************************/
