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
 *  File: Appl_KeyM.c 
 *  Description: KeyM Callout functions 
 *                 
 *********************************************************************************************************************/

/* Definition of KeyM Callout Functions */
#include "KeyM.h"

extern FUNC(Std_ReturnType, KEYM_APPL_CODE) Appl_KeyMCertificateGetCurrentTimeCalloutFunc( KeyM_CertificateIdType CertId,  P2VAR(uint64, AUTOMATIC, KEYM_APPL_VAR) timeStamp)
{
  /* Add implementation to provide a timestamp */
  /* Thu Jun 17 2021 09:35:04 GMT */
  if (timeStamp != NULL_PTR) *(timeStamp) = 0x5dd3d8fa;


  return E_OK;
}
