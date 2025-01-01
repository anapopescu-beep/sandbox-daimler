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
/*!        \file  vHsm_Cbk.h
 *        \brief  vHsm callback header file
 *
 *      \details  -
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_CBK_H)
# define VHSM_CBK_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vHsm.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VHSM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_ExternalIsr()
 *********************************************************************************************************************/
/*! \brief       This function is called by the ISR.
 *  \details     This function will fetch jobs from the IPC.
 *               Depending on the configuration:
 *               - the jobs can directly be processed if interrupt processing is enabled for the CryIf channel
 *               - a OS task may be activated if context is Cat2 ISR
 *               - a switch to ISR Cat2 will be performed to activate an OS Task if context is Cat1 ISR
 *               - Only fetching is performed in the ISR
 *  \param[in]   callContext     Context of the caller which can be either VHSM_CALL_CONTEXT_ISR1 or VHSM_CALL_CONTEXT_ISR2
 *  \param[in]   mask            Mask of the interrupt. The value 0 can only be passed when VHSM_SETTING_ENABLE_IPC_INIT_VIA_INTERRUPT is disabled.
 *  \pre         -
 *  \context     ISR1|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_ExternalIsr(
  vHsm_CallContextType callContext,
  uint32 mask);

/**********************************************************************************************************************
 *  vHsm_InternalIsr()
 *********************************************************************************************************************/
/*! \brief       Function which is call by a Cat2 interrupt which has been triggered by vHsm_Hal_TriggerInternalIrq().
 *  \details     OS tasks can not be triggered from a Cat1 interrupt context. Therefore a switch is needed to Cat2.
 *  \param[in]   mask            Mask of the interrupt
 *  \pre         -
 *  \context     ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_InternalIsr(
  uint32 mask);

# define VHSM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSM_CBK_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Cbk.h
 *********************************************************************************************************************/
