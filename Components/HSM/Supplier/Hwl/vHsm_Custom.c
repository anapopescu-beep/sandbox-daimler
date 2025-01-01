/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  EXAMPLE CODE ONLY 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW 
 *  configuration. The Example Code has not passed any quality control measures and may be incomplete. The 
 *  Example Code is neither intended nor qualified for use in series production. The Example Code as well 
 *  as any of its modifications and/or implementations must be tested with diligent care and must comply 
 *  with all quality requirements which are necessary according to the state of the art before their use. 
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsm_Custom.c
 *        \brief  Custom crypto driver source file.
 *
 *      \details  Implements the the custom crypto driver.
 *
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSM_CUSTOM_SOURCE
 
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm.h"
#include "vHsm_KeyM.h"
#include "Crypto_30_LibCv.h"

#include "vHsm_Custom.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* vendor specific version information is BCD coded */
#if (  (VHSM_CUSTOM_SW_MAJOR_VERSION != (24u)) \
    || (VHSM_CUSTOM_SW_MINOR_VERSION != (03u)) \
    || (VHSM_CUSTOM_SW_PATCH_VERSION != (00u)) )
# error "Vendor specific version numbers of vHsm_Custom.c and vHsm_Custom.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (VHSM_CUSTOM_LOCAL) /* COV_VHSM_CUSTOM_LOCAL_DEFINE */
# define VHSM_CUSTOM_LOCAL static
#endif

#if !defined (VHSM_CUSTOM_LOCAL_INLINE) /* COV_VHSM_CUSTOM_LOCAL_DEFINE */
# define VHSM_CUSTOM_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VHSM_CUSTOM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vHsm_Custom_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_CUSTOM_CODE) vHsm_Custom_Init(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Do nothing */
}

/**********************************************************************************************************************
 *  vHsm_Custom_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_CUSTOM_CODE) vHsm_Custom_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Do nothing */
}

/**********************************************************************************************************************
 *  vHsm_Custom_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Custom_MainFunction(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* This function is called from the main loop of the vHsm.
   * Special functionality can be implemented here.
   */
}

/**********************************************************************************************************************
 *  vHsm_Custom_ProcessJob()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CUSTOM_CODE) vHsm_Custom_ProcessJob( /* COV_VHSM_CUSTOM_NOTUSED */
  uint32 objectId, /* PRQA S 3206 */ /* MD_VHSM_CUSTOM_UNUSED_PARAMETER */
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_CUSTOM_APPL_VAR) job)  /* PRQA S 3206 */ /* MD_VHSM_CUSTOM_UNUSED_PARAMETER */
{
  /* ----- Implementation ----------------------------------------------- */
  /* Special functionality can be implemented here.
   * The function is executed when Crypto_30_vHsm_ProcessJob() is called with the Custom driver used as CryptoDriverObject.
   * Custom algorithm modes and families can be used to specify special functionalities or existing algorithms can be used.
   *   
   * switch(job->jobPrimitiveInfo->primitiveInfo->service)
   * {
   *   case CRYPTO_MACVERIFY:
   *     if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_CUSTOM_TBD)
   *     {
   *       if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CUSTOM_TBD)
   *       {
   *         // perform custom algorithm
   *       }
   *     }
   *     break;
   * }
   *
   */
  return E_NOT_OK; /* COV_VHSM_CUSTOM_NOTUSED */
}

/**********************************************************************************************************************
 *  vHsm_Custom_CancelJob()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CUSTOM_CODE) vHsm_Custom_CancelJob( /* COV_VHSM_CUSTOM_NOTUSED */
  uint32 objectId, /* PRQA S 3206 */ /* MD_VHSM_CUSTOM_UNUSED_PARAMETER */
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_CUSTOM_APPL_VAR) job) /* PRQA S 3206 */ /* MD_VHSM_CUSTOM_UNUSED_PARAMETER */
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return always with an error because core jobs can not be canceled */
  return E_NOT_OK; /* COV_VHSM_CUSTOM_NOTUSED */
}

/**********************************************************************************************************************
 *  vHsm_Custom_KeyElementSet()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CUSTOM_CODE) vHsm_Custom_KeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, VHSM_CUSTOM_APPL_VAR) keyPtr,
  uint32 keyLength)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* Special functionality can be implemented here when specific key elements are requested.
   * The function is executed when Crypto_30_vHsm_KeyElementSet() is called with a key referenced as vHsmCustomKey in the vHsmKeyMapping.
   *
   * Example implementation:
   *
   * switch (keyElementId)
   * {
   * case CRYPTO_KE_CUSTOM_ToBeDefined1:
   *   // Perform custom operation1
   *   break;
   * case CRYPTO_KE_CUSTOM_ToBeDefined2:
   *   // Perform custom operation2
   *   break;
   * default:
   *   // No custom operation. Let the LibCv handle the request
   *   retVal = vHsm_KeyM_WriteOnceHandling_KeyElementSet(cryptoKeyId, keyElementId, keyPtr, keyLength);
   *   break;
   * }
   *
   */

  /* #100 If no custom element is requested, redirect the request to the Cryopto_30_LibCv */
  retVal = vHsm_KeyM_WriteOnceHandling_KeyElementSet(cryptoKeyId, keyElementId, keyPtr, keyLength);
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Custom_KeyElementGet()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CUSTOM_CODE) vHsm_Custom_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, VHSM_CUSTOM_APPL_VAR) resultPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_CUSTOM_APPL_VAR) resultLengthPtr)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* Special functionality can be implemented here when specific key elements are requested.
    The function is executed when Crypto_30_vHsm_KeyElementGet() is called with a key referenced as vHsmCustomKey in the vHsmKeyMapping. */
   
    switch (keyElementId)
    {
      case 1:
        /* write the version info to the output */
        resultPtr[0] = (uint8)VHSM_CUSTOM_SW_MAJOR_VERSION;
        resultPtr[1] = (uint8)VHSM_CUSTOM_SW_MINOR_VERSION;
        resultPtr[2] = (uint8)VHSM_CUSTOM_SW_PATCH_VERSION;

        *resultLengthPtr = 3u;

        retVal = E_OK;
        break;
      // case CRYPTO_KE_CUSTOM_ToBeDefined2:
      //   // Perform custom operation2
      //   break;
      default:
        // No custom operation. Let the LibCv handle the request
        retVal = Crypto_30_LibCv_KeyElementGet(cryptoKeyId, keyElementId, resultPtr, resultLengthPtr);
        break;
    }
   
  return retVal;
}

#define VHSM_CUSTOM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Module specific MISRA deviations
 *********************************************************************************************************************/
/* Module specific MISRA deviations:


MD_VHSM_CUSTOM_UNUSED_PARAMETER
Reason:       The API is designed to be the same for multiple sub components. Some implementations don't use a parameter.
Risk:         Unused parameter may be less efficient
Prevention:   Code review, tests

 */

/* SBSW_JUSTIFICATION_BEGIN
SBSW_JUSTIFICATION_END */

/* COV_JUSTIFICATION_BEGIN

\ID COV_VHSM_CUSTOM_LOCAL_DEFINE
\ACCEPT TX
\REASON VHSM_LOCAL is always defined externally.

\ID COV_VHSM_CUSTOM_NOTUSED
\ACCEPT X
\REASON Function is never referenced and therefore not used. For comparability reasons it should still be available for future vHsm Versions.

\ID COV_VHSM_CUSTOM_CUSTOM_KEY_ELEMENTS
\ACCEPT TX
\REASON The Crypto needs custom key elements, which could be defined in other modules as well.

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Custom.c
 *********************************************************************************************************************/
 
