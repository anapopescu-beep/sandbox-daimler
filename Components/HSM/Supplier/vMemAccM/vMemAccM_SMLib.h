/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMemAccM_SMLib.h
 *        \brief  vMemAccM state machine library sub module header file
 *
 *      \details  The vMemAccM state machine library unit provides auxillary functionality which is used by several states.
 * 
 *         \unit  vMemAccM_SMLib
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEMACCM_SMLIB_H)
# define VMEMACCM_SMLIB_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMemAccM_Types.h"
#include "vMemAccM_IntCfg.h"
#include "vMemAccM_SMTypes.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VMEMACCM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMemAccM_SMLibCalcJobPointer
 *********************************************************************************************************************/
/*!
 * \brief       Assigns the data pointer to the user data pointer at the right position.
 * \details     -
 * \param[out]  JobParamsPtr holding a structure with job relevant values. Parameter must not be NULL_PTR.
 * \param[in]   DataPtr pointing to the job related buffer. The pointer must be valid.
 * \param[in]   Offset Stores the already done bytes from start address.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Some jobs do not use the data pointer, or use another one - therefore this separate function.
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMLibCalcJobPointer
(
  vMemAccM_SubAddrAreaJobParamsPtrType JobParamsPtr,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_AddressType Offset 
);

/**********************************************************************************************************************
 *  vMemAccM_SMLibCalcJobParams
 *********************************************************************************************************************/
/*!
 * \brief       Calculates all non pointer values within the given structure (pointer).
 * \details     -
 * \param[out]  JobParamsPtr holds a structure with job relevant values. Parameter must not be NULL_PTR.
 * \param[in]   SubAddrAreaId Id of the sub address area of the job.
 * \param[in]   Address of the Job.
 * \param[in]   Length of the Job.
 * \param[in]   Offset of the Management Area.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMLibCalcJobParams
(
    vMemAccM_SubAddrAreaJobParamsPtrType JobParamsPtr,
    vMemAccM_AddressAreaIdType SubAddrAreaId,
    vMemAccM_AddressType Address,
    vMemAccM_LengthType Length,
    vMemAccM_AddressType Offset
);

#endif /* VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF */

# define VMEMACCM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_SMLib.h
 *********************************************************************************************************************/
