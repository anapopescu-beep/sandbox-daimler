/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsm_Hal_Irq.c
 *        \brief  vHsm platform hardware abstractions
 *
 *      \details  This source file implements interrupt service handlers.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSM_HAL_IRQ_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "vHsm_Hal.h"

#include "vHsm.h"
#include "Os.h"

#include "IFX_HSM.h"
#include "core_cm3.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (VHSM_HAL_LOCAL) /* COV_VHSM_HAL_LOCAL_DEFINE */
# define VHSM_HAL_LOCAL                                               static
#endif

#if !defined (VHSM_HAL_LOCAL_INLINE) /* COV_VHSM_HAL_LOCAL_DEFINE */
# define VHSM_HAL_LOCAL_INLINE                                        LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VHSM_HAL_START_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VHSM_HAL_PROVIDE_ISRS == STD_ON)
/**********************************************************************************************************************
 *  Default_Handler()
 *********************************************************************************************************************/
/*! \brief       Default interrupt handler.
 *  \details     This default handler fires a system reset.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
OS_ISR1(Default_Handler);

/**********************************************************************************************************************
 *  Bridge_Error_Handler()
 *********************************************************************************************************************/
/*! \brief       Bridge Error handler.
 *  \details     This handler can be used to handle errors from the HSM bridge module.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
OS_ISR1(Bridge_Error_Handler);
#endif /* (VHSM_HAL_PROVIDE_ISRS == STD_ON) */

#define VHSM_HAL_STOP_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_HAL_START_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VHSM_HAL_PROVIDE_ISRS == STD_ON)
/**********************************************************************************************************************
 *  Default_Handler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_ISR1(Default_Handler) /* COV_VHSM_HAL_NOTESTING */
{
  /* Trace and report error */
  vHsm_Trace(VHSM_TRACETYPE_ERROR, "Exception/Interrupt occured in default handler");
  /* Clear the fault in System Control Block (SCB) */
  SCB->SHCSR = ((uint32)(SCB->SHCSR) & 0xFFFF0000U); /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
  vHsm_Hal_TriggerSoftwareReset(); /* PRQA S 2987 */ /* MD_VHSM_HAL_2987_HARDWARE_ACCESS */
} /* ISR(Default_Handler)() */

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
OS_ISR1(Bridge_Error_Handler) /* COV_VHSM_HAL_NOTESTING */
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
    /* Trace and report error */
    vHsm_Trace(VHSM_TRACETYPE_ERROR, "Bus error occured with ERRCTRL=0x%X", ERRCTRL);
    softReset = TRUE;
  }

  /* Check for ECC boot ROM errors */
  switch ((ERRCTRL & ERRCTRL_ECCROM_Msk) >> ERRCTRL_ECCROM_Pos)
  {
  case ERRCTRL_ECCROM_ROMUE: /* Uncorrectable error detected */
  case ERRCTRL_ECCROM_ROMCU: /* Correctable and uncorrectable error detected */
                             /* Trace and report error */
    vHsm_Trace(VHSM_TRACETYPE_ERROR, "ECC error occured in boot ROM with ERRCTRL=0x%X", ERRCTRL);
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
                             /* Trace and report error */
    vHsm_Trace(VHSM_TRACETYPE_ERROR, "ECC error occured in RAM with ERRCTRL=0x%X", ERRCTRL);
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
                           /* Trace and report error */
    vHsm_Trace(VHSM_TRACETYPE_ERROR, "ECC error occured in cache with ERRCTRL=0x%X", ERRCTRL);
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
} /* OS_ISR1(Bridge_Error_Handler)() */ /* PRQA S 6010, 6030 */ /* MD_MSR_STPTH, MD_MSR_STCYC */

#endif /* (VHSM_HAL_PROVIDE_ISRS == STD_ON) */

#define VHSM_HAL_STOP_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSM_HAL_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if(VHSM_HAL_VHSM_ISR_FOR_PROCESSING == VHSM_HAL_CATEGORY_1) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_ExternalRequestIsr()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_ISR1(vHsm_Hal_ExternalRequestIsr)
{
  vHsm_ExternalIsr(VHSM_CALL_CONTEXT_ISR1, 0u);

  /* Clear Flag */
  HSM_BRIDGE->HT2HSMF = HSM_BRIDGE->HT2HSMF; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
} /* vHsm_Hal_ExternalRequestIsr */
#endif

#if(VHSM_HAL_VHSM_ISR_FOR_PROCESSING == VHSM_HAL_CATEGORY_2) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_ExternalRequestIsr()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
ISR(vHsm_Hal_ExternalRequestIsr)
{
  vHsm_ExternalIsr(VHSM_CALL_CONTEXT_ISR2, 0u);
} /* vHsm_Hal_ExternalRequestIsr */
#endif

/**********************************************************************************************************************
 *  vHsm_Hal_InternalRequestIsr()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
ISR(vHsm_Hal_InternalRequestIsr)
{
  vHsm_InternalIsr(0u);
  NVIC_ClearPendingIRQ(TIM1_IRQn);
} /* vHsm_Hal_InternalRequestIsr */

/**********************************************************************************************************************
 *  vHsm_Hal_TriggerInternalIrq()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_HAL_CODE_ISR) vHsm_Hal_TriggerInternalIrq(void)
{
  /* Trigger vHsm_Hal_InternalRequestIsr */
  NVIC_SetPendingIRQ(TIM1_IRQn);
} /* vHsm_Hal_TriggerInternalIrq */

#define VHSM_HAL_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSM_HAL_START_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_Hal_EnableInterruptSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_EnableInterruptSource(uint32 sources)
{
  /* Enable Bridge service interrupts */
  HSM_BRIDGE->HT2HSMIE |= sources; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
} /* vHsm_Hal_EnableInterruptSource */

/**********************************************************************************************************************
 *  vHsm_Hal_DisableInterruptSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_DisableInterruptSource(uint32 sources)
{
  /* Disable Bridge service interrupts */
  HSM_BRIDGE->HT2HSMIE &= ~sources; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
} /* vHsm_Hal_DisableInterruptSource */

#define VHSM_HAL_STOP_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Hal_Irq.c
 *********************************************************************************************************************/
