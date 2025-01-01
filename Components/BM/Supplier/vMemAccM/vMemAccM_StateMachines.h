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
/*!        \file  vMemAccM_StateMachines.h
 *        \brief  vMemAccM state machines submodule header file
 *
 *      \details  The vMemAccM state machines submodule holds all asynchronous job state machines. The processing
 *                of the state machines will be triggered by the scheduler submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEMACCM_STATEMACHINES_H)
# define VMEMACCM_STATEMACHINES_H

#include "vMemAccM_Types.h"
#include "vMemAccM_SMTypes.h"

#if (VMEMACCM_MINIMAL_SYNC == STD_OFF)

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
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

# define VMEMACCM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMDefaultInit
 *********************************************************************************************************************/
/*!
 * \brief       Initialized the passed pointer to the default state machine.
 * \details     The pointed structure holds the appropriate state machine state pointer and the state
 *              machine main function.
 * \param[out]   SMFuncsPtr pointing to a job state machine structure. Pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMDefaultInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMWriteInit
 *********************************************************************************************************************/
/*!
 * \brief       Initialized the passed pointer to the write state machine.
 * \details     The pointed structure holds the appropriate state machine state pointer and the state
 *              machine main function.
 * \param[out]   SMFuncsPtr pointing to a job state machine structure. Pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMWriteInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMEraseInit
 *********************************************************************************************************************/
/*!
 * \brief       Initialized the passed pointer to the erase state machine.
 * \details     The pointed structure holds the appropriate state machine state pointer and the state
 *              machine main function.
 * \param[out]   SMFuncsPtr pointing to a job state machine structure. Pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMEraseInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadInit
 *********************************************************************************************************************/
/*!
 * \brief       Initialized the passed pointer to the read state machine.
 * \details     The pointed structure holds the appropriate state machine state pointer and the state
 *              machine main function.
 * \param[out]   SMFuncsPtr pointing to a job state machine structure. Pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankInit
 *********************************************************************************************************************/
/*!
 * \brief       Initializes the passed context with the read blank state machine.
 * \details     The pointed structure holds the appropriate state machine state pointer and the state
 *              machine main function.
 * \param[out]   SMFuncsPtr pointing to a job state machine structure. Pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr);

#if (VMEMACCM_COMPARE_API == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_SMCompareInit
 *********************************************************************************************************************/
/*!
 * \brief       Initialized the passed pointer to the compare state machine.
 * \details     The pointed structure holds the appropriate state machine state pointer and the state
 *              machine main function.
 * \param[out]   SMFuncsPtr pointing to a job state machine structure. Pointer must be valid.
 * \pre         Compare API is enabled.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMCompareInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr);
#endif /* (VMEMACCM_COMPARE_API == STD_ON) */

/**********************************************************************************************************************
 *  vMemAccM_SMIsBlankInit
 *********************************************************************************************************************/
/*!
 * \brief       Initialized the passed pointer to the is blank state machine.
 * \details     The pointed structure holds the appropriate state machine state pointer and the state
 *              machine main function.
 * \param[out]   SMFuncsPtr pointing to a job state machine structure. Pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMIsBlankInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr);

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
/**********************************************************************************************************************
 *  vMemAccM_SMHwSpecificInit
 *********************************************************************************************************************/
/*!
 * \brief       Initialized the passed pointer to the HW specific state machine.
 * \details     The pointed structure holds the appropriate state machine state pointer and the state
 *              machine main function.
 * \param[out]   SMFuncsPtr pointing to a job state machine structure. Pointer must be valid.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMHwSpecificInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr);
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */

/**********************************************************************************************************************
 *  vMemAccM_SMMainFunction
 *********************************************************************************************************************/
/*!
 * \brief       Processes the passed state machine, until the state machine "allows" to exit the processing.
 * \details     State machine is allowed to keep the execution busy over several states, for example if the
 *              vMem processing works synchronous, the state machine will process the whole job stap within one
 *              main function.
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMMainFunction(vMemAccM_SMStateContextPtrType ContextPtr);

# define VMEMACCM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

#endif /* VMEMACCM_STATEMACHINES_H */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_StateMachines.h
 *********************************************************************************************************************/
