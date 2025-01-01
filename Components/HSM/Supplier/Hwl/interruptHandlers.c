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
 *  File: interruptHandlers.c 
 *  Description: Example interrupt handlers 
 *                 
 *********************************************************************************************************************/

#include "vHsm_Hal_Cfg.h"
#include "vHsm_Hal.h"
#include "Os.h"

#include "IFX_HSM.h"
#include "core_cm3.h"

/* If Hal does not provide the ISRs, then we do in the Demo project */

#if (VHSM_HAL_PROVIDE_ISRS == STD_OFF)
/**********************************************************************************************************************
 *  Default_Handler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_ISR1(Default_Handler)
{
  /* Clear the fault in System Control Block (SCB) */
  SCB->SHCSR = ((uint32)(SCB->SHCSR) & 0xFFFF0000U); /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
  vHsm_Hal_TriggerSoftwareReset(); /* PRQA S 2987 */ /* MD_VHSM_HAL_2987_HARDWARE_ACCESS */
}

/**********************************************************************************************************************
 * Bridge_Error_Handler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_ISR1(Bridge_Error_Handler)
{
  /* Save error information */
  volatile boolean softReset = FALSE;
  volatile uint32 ERRADDR;
  volatile uint32 ERRCTRL;

  ERRADDR = HSM_BRIDGE->ERRADDR; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
  ERRCTRL = HSM_BRIDGE->ERRCTRL; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */

  /* Clear the fault in System Control Block (SCB) */
  SCB->SHCSR = ((uint32)(SCB->SHCSR) & 0xFFFF0000U); /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */

  /* Check for bus error, local RAM, cache, cache tag field */
  if ((ERRCTRL & (ERRCTRL_BERR_Msk | ERRCTRL_ADRAM_Msk | ERRCTRL_ADCD_Msk | ERRCTRL_ADCT_Msk)) != 0u)
  {
    softReset = TRUE;
  }

  /* Check for ECC boot ROM errors */
  switch ((ERRCTRL & ERRCTRL_ECCROM_Msk) >> ERRCTRL_ECCROM_Pos)
  {
  case ERRCTRL_ECCROM_ROMUE: /* Uncorrectable error detected */
  case ERRCTRL_ECCROM_ROMCU: /* Correctable and uncorrectable error detected */
    softReset = TRUE;
    break;
  default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
    break;
  }

  /* Check for ECC RAM errors */
  switch ((ERRCTRL & ERRCTRL_ECCRAM_Msk) >> ERRCTRL_ECCRAM_Pos)
  {
  case ERRCTRL_ECCRAM_RAMUE: /* Uncorrectable error detected */
  case ERRCTRL_ECCRAM_RAMCU: /* Correctable and uncorrectable error detected */
    softReset = TRUE;
    break;
  default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
    break;
  }

  /* Check for ECC cache errors */
  switch ((ERRCTRL & ERRCTRL_ECCCD_Msk) >> ERRCTRL_ECCCD_Pos)
  {
  case ERRCTRL_ECCCD_CDUE: /* Uncorrectable error detected */
  case ERRCTRL_ECCCD_CDCU: /* Correctable and uncorrectable error detected */
    softReset = TRUE;
    break;
  default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
    break;
  }

  if (softReset == TRUE)
  {
    vHsm_Hal_TriggerSoftwareReset();
  }

  /* Reset error flags */
  HSM_BRIDGE->ERRCTRL = 0xffffffffu; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
  VHSM_HAL_DUMMY_STATEMENT_CONST(ERRADDR); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
#endif /* (VHSM_HAL_PROVIDE_ISRS == STD_ON) */
