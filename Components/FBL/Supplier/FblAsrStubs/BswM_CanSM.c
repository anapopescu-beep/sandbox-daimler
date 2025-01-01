/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief BswM_CanSM ASR4 stub for flash bootloader
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "BswM_CanSM.h"

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#define FBLASRSTUBS_BSWM_CANSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  BswM_CanSM_CurrentState
 **********************************************************************************************************************/
/*! \brief       Function called by CanSM to indicate its current state
 *  \param[in]   Network        The CAN channel that the indicated state corresponds to.
 *  \param[in]   CurrentState   The current state of the CAN channel.
 **********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_CanSM_CurrentState(NetworkHandleType Network, CanSM_BswMCurrentStateType CurrentState)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)Network;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
   (void)CurrentState;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif
}

#define FBLASRSTUBS_BSWM_CANSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  END OF FILE: BSWMM_CANSM.C
 **********************************************************************************************************************/
