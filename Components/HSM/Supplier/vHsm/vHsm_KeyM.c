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
/*!        \file  vHsm_KeyM.c
 *        \brief  Key manager source file
 *
 *      \details  Implements the public interface of the key manager.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSM_KEYM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm.h"
#include "vHsm_KeyM.h"
#include "vHsm_ApiInternal.h"
#include "vHsm_Core.h"

#include "vHsm_Hal.h"
#include "vHsm_Custom.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (VHSM_LOCAL) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL                                                   static
#endif

#if !defined (VHSM_LOCAL_INLINE) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

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

#define VHSM_START_SEC_CONST_8BIT
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

CONST(boolean, VHSM_CONST) vHsm_KeyM_SecondaryKeyUsage[VHSM_KEYM_ACTION_SIZE] = /* PRQA S 1514 */ /* MD_VHSM_ONE_USAGE */
{
  FALSE, /* VHSM_KEYM_ACTION_KEYELEMENTSET          */
  FALSE, /* VHSM_KEYM_ACTION_KEYELEMENTGET          */
  TRUE,  /* VHSM_KEYM_ACTION_KEYELEMENTCOPY         */
  TRUE,  /* VHSM_KEYM_ACTION_KEYCOPY                */
  TRUE,  /* VHSM_KEYM_ACTION_KEYDERIVE              */
  FALSE, /* VHSM_KEYM_ACTION_KEYGENERATE            */
  FALSE, /* VHSM_KEYM_ACTION_KEYVALIDSET            */
  FALSE, /* VHSM_KEYM_ACTION_RANDOMSEED             */
  FALSE, /* VHSM_KEYM_ACTION_CERTIFICATEPARSE       */
  FALSE, /* VHSM_KEYM_ACTION_CERTIFICATEVERIFY      */
  FALSE, /* VHSM_KEYM_ACTION_KEYEXCHANGECALCPUBVAL  */
  FALSE, /* VHSM_KEYM_ACTION_KEYEXCHANGECALCSECRET  */
  FALSE, /* VHSM_KEYM_ACTION_KEYELEMENTIDSGET       */
  TRUE   /* VHSM_KEYM_ACTION_KEYELEMENTCOPYPARTIAL  */
};

#define VHSM_STOP_SEC_CONST_8BIT
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_KeyM_ProcessJob_SecondaryKeyCheck()
 *********************************************************************************************************************/
/*! \brief         The function makes additional robustness checks for the secondary key
 *  \details       -
 *  \param[in]     action      Key API which shall be used
 *  \param[in]     cryIfKeyId  Id of the first key of the API
 *  \param[in]     secondaryCryIfKeyId    id of the secondary key (target key)
 *  \return        E_OK if allowed, otherwise E_NOT_OK
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_KeyM_ProcessJob_SecondaryKeyCheck(
  vHsm_KeyM_ActionType action,
  uint32 cryIfKeyId,
  uint32 secondaryCryIfKeyId);

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_KeyM_ProcessJob_SecondaryKeyCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_KeyM_ProcessJob_SecondaryKeyCheck(
  vHsm_KeyM_ActionType action,
  uint32 cryIfKeyId,
  uint32 secondaryCryIfKeyId)
{
  Std_ReturnType retVal = E_OK;
  uint32 cryIfKeyIdTmp;
  boolean restricted = FALSE;

  /* #10 Check if the API makes use of the secondary Key */
  if (vHsm_KeyM_SecondaryKeyUsage[action] == TRUE)
  {
    for (cryIfKeyIdTmp = 0u; cryIfKeyIdTmp < vHsm_GetSizeOfKeyInfo(); cryIfKeyIdTmp++)
    {
      if (vHsm_IsKeyUsageDisallowed(cryIfKeyIdTmp))
      {
        /* #11 Check that the cryptoKeyId of the secondarykeyId is not the same as the cryptoKeyId of an protected key */
        if (vHsm_GetCryptoKeyIdOfKeyInfo(cryIfKeyIdTmp) == vHsm_GetCryptoKeyIdOfKeyInfo(secondaryCryIfKeyId))
        {
          restricted = TRUE;
          break;
        }
      }
    }

    /* #12 Make sure that there is no keyId overlap with other crypto drivers and
      that the secondaryCryIfKey has the same function mapping as the cryIfKeyId
      or
      that the secondary key is not remapped which means the normal mapping applies and remapping does not lead to unintended behaviour. */
    if (( restricted == FALSE)
      &&  ( (vHsm_GetCryptoFunctionsIdxOfKeyInfo(cryIfKeyId) == vHsm_GetCryptoFunctionsIdxOfKeyInfo(secondaryCryIfKeyId))
        || (FALSE == vHsm_IsRoutedOfKeyInfo(secondaryCryIfKeyId))))
    {
      retVal = E_OK;
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }
  return retVal;
}

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_KeyM_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_KeyM_Init(void)
{
  /* #10 Do nothing */
} /* vHsm_KeyM_Init */

/**********************************************************************************************************************
 *  vHsm_KeyM_PrepareSecureProtectedKeyStates()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_KeyM_PrepareSecureProtectedKeyStates(void)
{
#if (VHSM_SECUREBOOTPROTECTEDKEYS == STD_ON)
  uint32 cryIfKeyId;

  for (cryIfKeyId = 0u; cryIfKeyId < vHsm_GetSizeOfKeyInfo(); cryIfKeyId++)
  {
    if (vHsm_IsSecureBootProtectedOfKeyInfo(cryIfKeyId) == TRUE)
    {
      vHsm_State.vHsm_KeyUsageRestriction[cryIfKeyId] |= VHSM_KEY_USAGE_SECURE_BOOT_PROTECTED;
    }
  }
#endif /* (VHSM_SECUREBOOTPROTECTEDKEYS == STD_ON) */
}

#if (VHSM_SECURE_BOOT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_KeyM_RestoreSecureProtectedKeyStates()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_KeyM_RestoreSecureProtectedKeyStates(void)
{
# if (VHSM_SECUREBOOTPROTECTEDKEYS == STD_ON)
  uint32 cryIfKeyId;

  for (cryIfKeyId = 0u; cryIfKeyId < vHsm_GetSizeOfKeyInfo(); cryIfKeyId++)
  {
    if (vHsm_IsSecureBootProtectedOfKeyInfo(cryIfKeyId) == TRUE)
    {
      vHsm_State.vHsm_KeyUsageRestriction[cryIfKeyId] &= (uint8)(~VHSM_KEY_USAGE_SECURE_BOOT_PROTECTED);
    }
  }
# endif /* (VHSM_SECUREBOOTPROTECTEDKEYS = STD_ON) */
}
#endif

/**********************************************************************************************************************
 *  vHsm_KeyM_ProcessJob()
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
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_KeyM_ProcessJob(
  P2VAR(vHsm_KeyM_JobType, AUTOMATIC, VHSM_APPL_VAR) job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Check function mapping of secondary key */
  retVal = vHsm_KeyM_ProcessJob_SecondaryKeyCheck(job->action, job->cryIfKeyId, job->secondaryCryIfKeyId);
  if (retVal == E_OK)
  {
    /* #20 Dispatch the action which shall be performed */
    switch (job->action)
    {
      /* #30 If KeyElementSet: */
    case VHSM_KEYM_ACTION_KEYELEMENTSET:
    {
      /* #35 Perform KeyElementSet */
      retVal = vHsm_GetKeyElementSetOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(
        vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId),
        job->keyElementId,
        job->inputOutput.inputPtr,
        job->inputOutput.inputLength);
    }
    break;
    /* #40 If KeyElementGet: */
    case VHSM_KEYM_ACTION_KEYELEMENTGET:
    {
      /* #45 Perform KeyElementGet */
      retVal = vHsm_GetKeyElementGetOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(
        vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId),
        job->keyElementId,
        job->inputOutput.outputPtr,
        job->inputOutput.outputLengthPtr);
    }
    break;
    /* #50 If KeyValidSet: */
    case VHSM_KEYM_ACTION_KEYVALIDSET:
    {
      retVal = vHsm_GetKeyValidSetOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId));
    }
    break;
    /* #60 If KeyElementCopy: */
    case VHSM_KEYM_ACTION_KEYELEMENTCOPY:
    {
      /* #62 Copy the key element */
      retVal = vHsm_GetKeyElementCopyOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(
        vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId),
        job->keyElementId,
        vHsm_GetCryptoKeyIdOfKeyInfo(job->secondaryCryIfKeyId),
        job->secondaryKeyElementId);
    }
    break;
    /* #66 If KeyElementCopyPartial: */
    case VHSM_KEYM_ACTION_KEYELEMENTCOPYPARTIAL:
    {
      /* Copy the key element partial */
      retVal = vHsm_GetKeyElementCopyPartialOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(
        vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId),
        job->keyElementId,
        job->inputOutput.keyElementSourceOffset,
        job->inputOutput.keyElementTargetOffset,
        job->inputOutput.keyElementCopyLength,
        vHsm_GetCryptoKeyIdOfKeyInfo(job->secondaryCryIfKeyId),
        job->secondaryKeyElementId);
    }
    break;
    /* #70 If KeyCopy: */
    case VHSM_KEYM_ACTION_KEYCOPY:
    {
      /* #72 Copy the key */
      retVal = vHsm_GetKeyCopyOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(
        vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId),
        vHsm_GetCryptoKeyIdOfKeyInfo(job->secondaryCryIfKeyId));
    }
    break;
    /* #80 If KeyDerive: */
    case VHSM_KEYM_ACTION_KEYDERIVE:
    {
      /* #82 Derive the key */
      retVal = vHsm_GetKeyDeriveOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(
        vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId),
        vHsm_GetCryptoKeyIdOfKeyInfo(job->secondaryCryIfKeyId));
    }
    break;
    /* #90 If RandomSeed: */
    case VHSM_KEYM_ACTION_RANDOMSEED:
    {
      /* #92 Initialize the random seed */
      retVal = vHsm_GetRandomSeedOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(
        vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId),
        job->inputOutput.inputPtr,
        job->inputOutput.inputLength);
    }
    break;
    /* #100 If KeyExchangeCalcPubVal: */
    case VHSM_KEYM_ACTION_KEYEXCHANGECALCPUBVAL:
    {
      /* #102 Calculate the key exchange public value */
      retVal = vHsm_GetKeyExchangeCalcPubValOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(
        vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId),
        job->inputOutput.outputPtr,
        job->inputOutput.outputLengthPtr);
    }
    break;
    /* #110 If KeyExchangeCalcSecret: */
    case VHSM_KEYM_ACTION_KEYEXCHANGECALCSECRET:
    {
      /* #112 Calculate the key exchange secret */
      retVal = vHsm_GetKeyExchangeCalcSecretOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(
        vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId),
        job->inputOutput.inputPtr,
        job->inputOutput.inputLength);
    }
    break;
    /* #120 If KeyElementIdsGet: */
    case VHSM_KEYM_ACTION_KEYELEMENTIDSGET:
    {
      /* #121 Divide by 4 because size is the number of uint32 elements. */
      /* This way, there is no special handling in the IPC. */
      *job->inputOutput.outputLengthPtr = *job->inputOutput.outputLengthPtr / 4u;

      /* #122 Get the key element ids */
      retVal = vHsm_GetKeyElementIdsGetOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(
        vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId),
        (P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR))job->inputOutput.outputPtr, /* PRQA S 0310, 3305 */ /* MD_VHSM_KEYELEMENTIDSGET_BUFFER */
        job->inputOutput.outputLengthPtr);

      /* #123 Multiply by 4 because size is the number of uint32 elements. */
      /* This way, there is no special handling in the IPC. */
      *job->inputOutput.outputLengthPtr = *job->inputOutput.outputLengthPtr * 4u;
    }
    break;
    /* #130 If CertificateParse: */
    case VHSM_KEYM_ACTION_CERTIFICATEPARSE:
    {
      /* #132 Parse the certificate */
      retVal = vHsm_GetCertificateParseOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(
        vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId));
    }
    break;
    /* #140 If CertificateVerify: */
    case VHSM_KEYM_ACTION_CERTIFICATEVERIFY:
    {
      /* #141 Verify the certificate */
      retVal = vHsm_GetCertificateVerifyOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(
        vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId),
        vHsm_GetCryptoKeyIdOfKeyInfo(job->secondaryCryIfKeyId),
        job->inputOutput.outputPtr);
    }
    break;
    /* #150 If KeyGenerate: */
    case VHSM_KEYM_ACTION_KEYGENERATE:
    {
      /* #152 Generate the key */
      retVal = vHsm_GetKeyGenerateOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(job->cryIfKeyId))(
        vHsm_GetCryptoKeyIdOfKeyInfo(job->cryIfKeyId));
    }
    break;
    default: /* COV_VHSM_CASE_DEFAULT */
    {
      break;
    }
    }
  }

  return retVal;

} /* vHsm_KeyM_ProcessJob */ /* PRQA S 6030 */ /* MD_MSR_STCYC */

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_KeyM.c
 *********************************************************************************************************************/
