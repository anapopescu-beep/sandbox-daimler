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
 *  File: MBBL_EcuStatHandler.h
 *  Description: This header file contains the function definition of the state change callback required by the NM.
 *
 *********************************************************************************************************************/
#if !defined MBBL_ECUSTATHANDLER_H
# define MBBL_ECUSTATHANDLER_H

#include "NmStack_Types.h"
#include "Rte_Type.h"

/**********************************************************************************************************************
  FUNCTIONS
**********************************************************************************************************************/
  void EcuStatHandler_NmStateChangeInd(
    const NetworkHandleType nmNetworkHandle,
    const Nm_StateType nmPreviousState,
    const Nm_StateType nmCurrentState);

FUNC(void, Cdd_MBBL_EcuStatHandler_CODE) IgnStatReception(  Std_ReturnType sigStatVal, REC_Ign_Stat_Pr5_ST3 loc_IgnStat ); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

#endif
