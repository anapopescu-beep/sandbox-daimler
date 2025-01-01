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
 *  File: Crypto_Callout_Stubs
 *  Description: Callouts for Crypto_30_vHsm
 *                 
 *********************************************************************************************************************/

#include "Crypto_30_vHsm_Types.h"

#ifdef _MICROSOFT_C_VTT_
#include "CANoeAPI.h"
#endif

FUNC(void, CRYPTO_30_VHSM_APPL_CODE) Appl_Crypto_30_vHsm_WaitLoopCallout(void)
{
#ifdef _MICROSOFT_C_VTT_
  CANoeAPI_ConsumeTicks(1);
#endif
}