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
/*!        \file  ESLib_TDESkey.c
 *        \brief  TDES (generate key) implementation.
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

#define ESLIB_TDESKEY_SOURCE

#include "ESLib.h"

/* actCLib includes */
#include "actTDES.h"

#if (VSECPRIM_TDES_ENABLED == STD_ON) /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

# define VSECPRIM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/****************************************************************************
 ** parity check function
 ***************************************************************************/
# define ESL_PARITY_CHECK_EVEN                                        /* switch for even and odd parity mode */

# ifdef ESL_PARITY_CHECK_EVEN
VSECPRIM_FUNC(eslt_Byte) parity(eslt_Byte value)  /* even parity mode */
{
  eslt_Byte value_tmp = value;
  value_tmp ^= value_tmp >> 4;
  value_tmp ^= value_tmp >> 2;
  value_tmp ^= value_tmp >> 1;
  value_tmp &= 0x01;
  value ^= value_tmp;
  return value;
}
# else
VSECPRIM_FUNC(eslt_Byte) parity(eslt_Byte value)  /* odd parity mode */
{
  eslt_Byte value_tmp = value;
  value_tmp ^= value_tmp >> 4;
  value_tmp ^= value_tmp >> 2;
  value_tmp ^= value_tmp >> 1;
  value_tmp &= 0x00;
  value ^= value_tmp;
  return value;
}
# endif

/****************************************************************************
 ** Global Functions
 ***************************************************************************/

/****************************************************************************
 * esl_generateKey3TDES
 ***************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKey3TDES(VSECPRIM_P2VAR_PARA(eslt_Byte) key)
{
  eslt_ErrorCode result = esl_getBytesRNG(ESL_SIZEOF_3TDES_KEY, key);
  /* parity check */
  char i;
  for (i = 0; i < ESL_SIZEOF_3TDES_KEY; i++)
  {
    *key = parity(*key);
    key++;
  }
  return (result);
}

/****************************************************************************
 * esl_generateKey2TDES
 ***************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKey2TDES(VSECPRIM_P2VAR_PARA(eslt_Byte) key)
{
  eslt_ErrorCode result = esl_getBytesRNG(ESL_SIZEOF_2TDES_KEY, key);
  /* parity check */
  char i;
  for (i = 0; i < ESL_SIZEOF_2TDES_KEY; i++)
  {
    *key = parity(*key);
    key++;
  }
  return (result);
}

# define VSECPRIM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VSECPRIM_TDES_ENABLED == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: ESLib_TDESkey.c
 *********************************************************************************************************************/
