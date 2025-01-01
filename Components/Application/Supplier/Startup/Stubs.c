/********************************************************************************************************************** 
 *  COPYRIGHT 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  Copyright (c) 2020 by Mercedes Benz AG - Alle Rechte vorbehalten -  All rights reserved. 
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
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  File: Stubs.c 
 *  Description: This file contains stubs of functions which have not (yet) been implemented properly but are  
 *               required for compilation.
 *                 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dcm.h"
#include "ESLib_RNG.h"
#include "Os.h"
#include "vstdlib.h"
#include "KeyM.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SIZE_OF_RANDOM_NUMBER	8 /* Random number is 64 Bit */
#define STATIC_RANDOM_NUMBER	0x7BA5D04E478112D8 /* Just to prevent the function from only returning 0s */

/**********************************************************************************************************************
  FUNCTIONS
**********************************************************************************************************************/
/* Pseudo-Random Number Generation */
FUNC(eslt_ErrorCode, CRYPTO_30_LIBCV_CODE) esl_getBytesRNG(const eslt_Length targetLength, VSECPRIM_P2VAR_PARA(eslt_Byte) target)
 {
  uint64 locTickCount = 0, additionalEntropy = 0, randomNumber = 0u;  
  
  /* Fetch additional entropy */
  GetCounterValue(0, (TickRefType)&additionalEntropy);
  
  /* Assemble random number */
  randomNumber = additionalEntropy ^ locTickCount ^ STATIC_RANDOM_NUMBER; 
  
  /* Copy the random number to the target address */
  if(SIZE_OF_RANDOM_NUMBER >= targetLength)
  {
  	VStdLib_MemCpy(target, &randomNumber, targetLength);
  }
  else
  {
  	VStdLib_MemCpy(target, &randomNumber, SIZE_OF_RANDOM_NUMBER);
  }
  
  return ESL_ERC_NO_ERROR;
 } 

FUNC(Std_ReturnType, KEYM_APPL_CODE) Tsc_Appl_CertificateElementVerificationCallout(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData, uint32 CertElementDataLength)
{
  return E_OK;
}

