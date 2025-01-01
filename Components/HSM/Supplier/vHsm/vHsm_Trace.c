/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsm_Trace.c
 *        \brief  Vector Hardware Security Module Firmware (vHsm)
 *
 *      \details
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSM_TRACE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm_Trace.h"

#ifdef VHSM_TRACE_USED
/*lint -save -e10 -e17 -e116 */
# include <stdio.h>
# include <stdarg.h> /* PRQA S 5130 */ /* MD_VHSM_5130_STDIO */
/*lint -restore */
#endif

#if (VHSM_TRACE_KEY_STORAGE == STD_ON)
# include "vHsm_Core_Custom.h"
# include "vHsm_Custom_Custom.h"
# include "vHsm_ApiInternal.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#ifdef VHSM_TRACE_USED
/**********************************************************************************************************************
 *  vHsm_Trace()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Trace(vHsm_TraceType traceType, P2CONST(char, AUTOMATIC, VHSM_APPL_VAR) format, ...) /* PRQA S 1337 */ /* MD_VHSM_1337_TRACE_VARIADIC_FUNCTION */
{
  va_list arglist;
  /* PRQA S 0310 4 */ /* MD_VHSM_0310_API_SPECIFIC_CAST */
  /* PRQA S 0488 4 */ /* MD_VHSM_0488_STD_LIB */
  /* PRQA S 3393 4 */ /* MD_VHSM_3393_STD_LIB */
  va_start(arglist, format); /* PRQA S 5140 */ /* MD_VHSM_5140_TRACE_VARIADIC_FUNCTION */

  /* #10 Check the type of the debug message */
  switch (traceType)
  {
# if (VHSM_TRACE_INFO == STD_ON)
  /* #20 Print a info message */
  case VHSM_TRACETYPE_INFO: /* COV_VHSM_TRACE_OCCURRENCE */
    /* PRQA S 5124 2 */ /* MD_VHSM_5124_STDIO */
    (void)printf("%-8s%-7s", "INFO", VHSM_TRACE_IDENTIFIER);
    (void)vprintf((P2CONST(char, AUTOMATIC, VHSM_APPL_VAR))format, arglist);
    break;
# endif
# if (VHSM_TRACE_DEBUG == STD_ON)
  /* #30 Print a debug message */
  case VHSM_TRACETYPE_DEBUG: /* COV_VHSM_TRACE_OCCURRENCE */
    /* PRQA S 5124 2 */ /* MD_VHSM_5124_STDIO */
    (void)printf("%-8s%-7s", "DEBUG", VHSM_TRACE_IDENTIFIER);
    (void)vprintf((P2CONST(char, AUTOMATIC, VHSM_APPL_VAR))format, arglist);
    break;
# endif
# if (VHSM_TRACE_ERROR == STD_ON)
  /* #40 Print a error message */
  case VHSM_TRACETYPE_ERROR: /* COV_VHSM_TRACE_OCCURRENCE */
    /* PRQA S 5124 2 */ /* MD_VHSM_5124_STDIO */
    (void)printf("%-8s%-7s", "ERROR", VHSM_TRACE_IDENTIFIER);
    (void)vprintf((P2CONST(char, AUTOMATIC, VHSM_APPL_VAR))format, arglist);
    break;
# endif
# if (VHSM_TRACE_WARNING == STD_ON)
  /* #50 Print a warning message */
  case VHSM_TRACETYPE_WARNING: /* COV_VHSM_TRACE_OCCURRENCE */
    /* PRQA S 5124 2 */ /* MD_VHSM_5124_STDIO */
    (void)printf("%-8s%-7s", "WARNING", VHSM_TRACE_IDENTIFIER);
    (void)vprintf((P2CONST(char, AUTOMATIC, VHSM_APPL_VAR))format, arglist);
    break;
# endif
  /* #60 Print a message */
  case VHSM_TRACETYPE_NONE: /* COV_VHSM_TRACE_OCCURRENCE */
    /* PRQA S 5124 1 */ /* MD_VHSM_5124_STDIO */
    (void)vprintf((P2CONST(char, AUTOMATIC, VHSM_APPL_VAR))format, arglist);
    break;
  default: /* COV_VHSM_CASE_DEFAULT */ /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
    break;
  }
  va_end(arglist); /* PRQA S 5140 */ /* MD_VHSM_5140_TRACE_VARIADIC_FUNCTION */
} /*lint !e438 */

#endif /* VHSM_TRACE_USED */

#if (VHSM_TRACE_KEY_STORAGE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Trace_PrintKeyStorage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Trace_PrintKeyStorage(void)
{
  uint32 cryptoKeyId;

  /* #10 For all available Keys:*/
  for (cryptoKeyId = 0u; cryptoKeyId < vHsm_Api_GetSizeOfKey(); cryptoKeyId++)
  {
    vHsm_Api_KeyElementsIterType elementIdx;
    vHsm_Trace(VHSM_TRACETYPE_DEBUG, "\n");
    vHsm_Trace(VHSM_TRACETYPE_DEBUG, "CryptoKeyId=%i\n", cryptoKeyId);
    /* #11 For all key elements in the key: */
    for (elementIdx = vHsm_Api_GetKeyElementsStartIdxOfKey(cryptoKeyId); elementIdx < vHsm_Api_GetKeyElementsEndIdxOfKey(cryptoKeyId); elementIdx++)
    {
      uint32_least i;

      /* #20 Print the properties of the key element */
      vHsm_Trace(VHSM_TRACETYPE_DEBUG, "Id=%*i v=%i w=%*i p=%i ",
        4u, vHsm_Api_GetIdOfKeyElements(elementIdx),
        vHsm_Api_IsKeyElementValid(elementIdx),
        3u, ((uint32)(((uint32)vHsm_Api_GetKeyStorage(vHsm_Api_GetKeyStorageWrittenLengthStartIdxOfKeyElements((elementIdx))) << 8u) | vHsm_Api_GetKeyStorage(vHsm_Api_GetKeyStorageWrittenLengthStartIdxOfKeyElements((elementIdx)) + 1u))),
        vHsm_Api_IsPersistOfKeyElementInfo(vHsm_Api_GetKeyElementInfoIdxOfKeyElements((elementIdx))));

      switch (vHsm_Api_GetIdOfKeyElements(elementIdx))
      {
      case CRYPTO_KE_MAC_PROOF:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "MAC_PROOF                             ");
        break;
      case CRYPTO_KE_CIPHER_PROOF:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CIPHER_PROOF                          ");
        break;
      case CRYPTO_KE_CIPHER_IV:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CIPHER_IV                             ");
        break;
      case CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS  ");
        break;
      case CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SIZE:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CUSTOM_VHSM_SECURE_BOOT_SLOT_SIZE     ");
        break;
      case CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_CMAC:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CUSTOM_VHSM_SECURE_BOOT_SLOT_CMAC     ");
        break;
      case CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_KEY:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "KEY                                   ");
        break;
      case CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_MODE:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CUSTOM_VHSM_SECURE_BOOT_SLOT_MODE     ");
        break;
      case CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SANCTION:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CUSTOM_VHSM_SECURE_BOOT_SLOT_SANCTION ");
        break;
      case CRYPTO_KE_CUSTOM_VHSM_UID:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CUSTOM_VHSM_UID                       ");
        break;
      case CRYPTO_KE_CUSTOM_VHSM_BUNDLING_COUNTER:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CUSTOM_VHSM_BUNDLING_COUNTER          ");
        break;
      case CRYPTO_KE_CUSTOM_VHSM_BUNDLING_REQ:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CUSTOM_VHSM_BUNDLING_REQ              ");
        break;
      case CRYPTO_KE_CUSTOM_VHSM_BUNDLING_RESP:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CUSTOM_VHSM_BUNDLING_RESP             ");
        break;
      case CRYPTO_KE_CUSTOM_VHSM_ERRORLOG:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CUSTOM_VHSM_ERRORLOG                  ");
        break;
      case CRYPTO_KE_CUSTOM_RSA_MODULUS:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CUSTOM_RSA_MODULUS                    ");
        break;
      case CRYPTO_KE_CUSTOM_RSA_PRIVATE_EXPONENT:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CUSTOM_RSA_PRIVATE_EXPONENT           ");
        break;
      case CRYPTO_KE_CUSTOM_RSA_PUBLIC_EXPONENT:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "CUSTOM_RSA_PUBLIC_EXPONENT            ");
        break;
      default:
        vHsm_Trace(VHSM_TRACETYPE_NONE, "");
        break;
      }

      /* #30 Print the element data as Hex values to the console */
      for (i = 0u; i < ((uint32)(((uint32)vHsm_Api_GetKeyStorage(vHsm_Api_GetKeyStorageWrittenLengthStartIdxOfKeyElements((elementIdx))) << 8u) | vHsm_Api_GetKeyStorage(vHsm_Api_GetKeyStorageWrittenLengthStartIdxOfKeyElements((elementIdx)) + 1u))); i++)
      {
        if (((i % 16u) == 0u) && (i != 0u))
        {
          vHsm_Trace(VHSM_TRACETYPE_NONE, "\n                                                                          ");
        }
        vHsm_Trace(VHSM_TRACETYPE_NONE, "%02x", vHsm_Api_GetAddrKeyStorage(vHsm_Api_GetKeyStorageStartIdxOfKeyElements(elementIdx))[i]);
      }
      vHsm_Trace(VHSM_TRACETYPE_NONE, "\n");
    }
  }
} /* PRQA S 6030 */ /* MD_MSR_STCYC */
#endif /* VHSM_PRINT_KEYSTORAGE == STD_ON */

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Trace.c
 *********************************************************************************************************************/
