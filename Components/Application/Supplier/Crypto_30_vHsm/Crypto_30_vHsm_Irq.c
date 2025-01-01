/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*      \file  Crypto_30_vHsm_Irq.c
 *      \brief  MICROSAR vHsm Crypto Driver (Crypto)
 *
 *      \details  Interrupt service routines of the Vector Hardware Security Module Firmware driver.
 *
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_IRQ_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_vHsm_Ipc.h"
#include "Os.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_START_SEC_CODE_ISR
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*********************************************************************************************************************
 *  vHsmResponseIsr()
 *********************************************************************************************************************/
/*! \brief       Hardware Security Module Interrupt Service Routine #0
 *  \details     -
 *  \fn          vHsmResponseIsr
 *  \pre         -
 *  \context     ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ISR(vHsmResponseIsr);

/*********************************************************************************************************************
 *  vHsmResponseIsr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
ISR(vHsmResponseIsr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear interrupt flag if not already done by OS */
  Crypto_30_vHsm_ClearInterrupt(); /* PRQA S 0303 */ /* MD_CRYPTO_30_VHSM_REGISTER_ACCESS */ /* SBSW_CRYPTO_30_VHSM_REGISTER_ACCESS */

#if (CRYPTO_30_VHSM_INTERRUPT_MODE == STD_ON)
  /* #20 Process the job response available in the IPC */
  Crypto_30_vHsm_Ipc_ProcessChannels();

  /* #30 Process the callbacks of async jobs */
  Crypto_30_vHsm_Ipc_ProcessCallbacks();
#endif
}

#define CRYPTO_30_VHSM_STOP_SEC_CODE_ISR
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Irq.c
 ********************************************************************************************************************/
