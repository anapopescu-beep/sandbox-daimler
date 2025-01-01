/* ********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 */
/*!
 *  \defgroup   Dem_Completion Completion
 *  \{
 *  \file       Dem_Completion_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_COMPLETION_INTERFACE_H)
#define DEM_COMPLETION_INTERFACE_H

/* ********************************************************************************************************************
 *  GLOBAL MISRA JUSTIFICATIONS
 *********************************************************************************************************************/
/* PRQA S 2880 EOF */ /* MD_DEM_2.1_UNREACHABLE_STATEMENT */
/* PRQA S 2982 EOF */ /* MD_DEM_2982 */
/* PRQA S 2983 EOF */ /* MD_DEM_2983 */
/* PRQA S 2985 EOF */ /* MD_DEM_2985 */
/* PRQA S 2986 EOF */ /* MD_DEM_2986 */
/* PRQA S 2987 EOF */ /* MD_DEM_2987 */
/* PRQA S 2991 EOF */ /* MD_DEM_2991 */
/* PRQA S 2992 EOF */ /* MD_DEM_2992 */
/* PRQA S 2995 EOF */ /* MD_DEM_2995 */
/* PRQA S 2996 EOF */ /* MD_DEM_2996 */
/* PRQA S 3415 EOF */ /* MD_DEM_13.5_cf */

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own unit header */
/* ------------------------------------------------------------------------- */
#include "Dem_Completion_Types.h"

/* ********************************************************************************************************************
 *  UNIT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  UNIT PUBLIC PROPERTIES DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_Completion_PublicProperties Public Properties
 * \{
 */

/* ****************************************************************************
 * Dem_Readiness_Completion_SetFullReadinessGroupUpdateFlag
 *****************************************************************************/
 /*!
 * \brief         Set the update flag for Readiness Completion Calculation
 *
 * \details       Set the update flag for Readiness Completion Calculation,
 *                on the Dem MainFunction.
 *
 * \param[in]     UpdateFlag
 *                Value to set
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Readiness_Completion_SetFullReadinessGroupUpdateFlag(
  uint32 UpdateFlag
);

/* ****************************************************************************
 * Dem_Readiness_Completion_GetFullReadinessGroupUpdateFlag
 *****************************************************************************/
/*!
 * \brief         Get the global update flags for Readiness Completion Calculation.
 *
 * \details       Get the global update flags for Readiness Completion Calculation.
 *                The flags indicate, if an update of a Readiness Group 
 *                completion state is necessary during the main function.
 *
 * \return        Readiness Completion update flags
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(uint32, DEM_CODE)
Dem_Readiness_Completion_GetFullReadinessGroupUpdateFlag(
  void
);


/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  UNIT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_Completion_Public Public Methods
 * \{
 */

 /* ****************************************************************************
 *  Dem_Readiness_Completion_CalculateCompletionMainFunction
 *****************************************************************************/
 /*!
 * \brief         Calculates Readiness Completion.
 *
 * \details       Calculates Readiness Completion.
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
 Dem_Readiness_Completion_CalculateCompletionMainFunction(
  void
);


/* ****************************************************************************
 * Dem_Readiness_Completion_CalculateCompletionOnTPSLC
 *****************************************************************************/
/*!
 * \brief         Calculates Reainess Group completion value for a given Readiness
 *                Group
 *
 * \details       Calculates Readiness Group completion value for a given Readiness
 *                Group. Set the Readiness Group to completed, if all available
 *                events were tested passed since last clear and are not pending.
 *
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE) Dem_Readiness_Completion_CalculateCompletionOnTPSLC(
  uint8  ReadinessGroup
);



/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_COMPLETION_INTERFACE_H */



/* ****************************************************************************
 * Dem_Readiness_Completion_SetReadinessGroupUpdateFlag
 *****************************************************************************/
/*!
 * \brief         Marks the Readiness Completion of a given readiness group to
 *                be updated.
 *
 * \details       Marks the Readiness Completion of a given readiness group to
 *                be updated.
 *
 *
 * \param[in]     ReadinessGroup
 *                Identifier for readiness group
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Completion_SetReadinessGroupUpdateFlag(
  uint8 ReadinessGroup
);


/* ****************************************************************************
 * Dem_Readiness_Completion_ResetReadinessGroupUpdateFlag
 *****************************************************************************/
/*!
 * \brief         Removes the mark for updating the Readiness Completion of the
 *                given readiness group.
 *
 * \details       Removes the mark for updating the Readiness Completion of the
 *                given readiness group.
 *
 * \param[in]     State
 *                Current readiness state as 32 bit bitmap
 *
 * \param[in]     ReadinessGroup
 *                Identifier for readiness group
 *
 * \return        New readiness state
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Readiness_Completion_ResetReadinessGroupUpdateFlag(
  uint32 State,
  uint8 ReadinessGroup
);

/* ****************************************************************************
 * Dem_Readiness_Completion_GetReadinessGroupUpdateFlag
 *****************************************************************************/
/*!
 * \brief         Tests if Readiness Completion of the given readiness group has
 *                to be updated
 *
 * \details       Tests if Readiness Completion of the given readiness group has
 *                to be updated
 *
 * \param[in]     State
 *                Current readiness state as 32 bit bitmap
 *
 * \param[in]     ReadinessGroup
 *                Identifier for readiness group
 *
 * \return        TRUE
 *                Readiness Completion of given readiness group has to be updated
 * \return        FALSE
 *                Readiness Completion of given readiness group doesn't have to
 *                be updated
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Readiness_Completion_GetReadinessGroupUpdateFlag(
  uint32 State,
  uint8 ReadinessGroup
);


/* ****************************************************************************
 * Dem_Readiness_Completion_SetReadinessGroupCompleted
 *****************************************************************************/
/*!
 * \brief         Sets OBD Readiness Group completion state.
 *
 * \details       Sets bit corresponding completion status to readiness group
 *
 * \param[in]     Completed
 *                TRUE    Readiness group is set to completed
 *                FALSE   Readiness group is set to not completed
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Completion_SetReadinessGroupCompleted(
  boolean Completed,
  uint8 ReadinessGroup);


/* ****************************************************************************
 * Dem_Readiness_Completion_TestReadinessGroupCompleted
 *****************************************************************************/
/*!
 * \brief         Checks if Readiness Group is completed
 *
 * \details       Checks if Readiness Group is completed
 *
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 *
 * \return        TRUE
 *                Readiness group is completed
 * \return        FALSE
 *                Readiness group is not completed
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Readiness_Completion_TestReadinessGroupCompleted(
  uint8 ReadinessGroup
);


/* ****************************************************************************
 * Dem_Readiness_Completion_SetReadinessGroupCompletedInPidFormat
 *****************************************************************************/
/*!
 * \brief         Sets OBD Readiness Group completion state in PID Format.
 *
 * \details       Sets bit corresponding to readiness group in given variable
 *                to completed or not completed (PID Format).
 *                (0 = completed, 1 = not complete)
 *
 * \param[in]     Completed
 *                TRUE    Readiness group is set to completed
 *                FALSE   Readiness group is set to not completed
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 * \param[in,out] PidResult
 *                PID formated data block
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Completion_SetReadinessGroupCompletedInPidFormat(
  boolean  Completed,
  uint8  ReadinessGroup,
  CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC)  PidResult
);


/* ****************************************************************************
 * Dem_Readiness_Completion_TestReadinessGroupCompletedInPidFormat
 *****************************************************************************/
/*!
 * \brief         Checks if Readiness Group is completed in a given PID formatted
 *                data block
 *
 * \details       Checks if Readiness Group is completed in a given PID formatted
 *                data block
 *
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 * \param[in]     Pid01Data
 *                Pid formatted data block
 *
 * \return        TRUE
 *                Readiness group is completed
 * \return        FALSE
 *                Readiness group is not completed
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Readiness_Completion_TestReadinessGroupCompletedInPidFormat(
  uint8  ReadinessGroup,
  uint32  Pid01Data
);


/* ****************************************************************************
 * Dem_Readiness_Completion_MapCompletedStatePID01
 *****************************************************************************/
/*!
 * \brief         Updates the Completion Bits to completed readiness groups to 0.
 *
 * \details       Updates the Completion Bits to completed readiness groups to 0,
 *                based on in the Main Function calculated completion states.
 *
 * \param[in]     Pid01Data
 *                Pid formatted data block. With the completion of supported 
 *                readiness groups set to not completed .
 *
 * \result        Pid formatted data block 
 *                Completed readiness groups are set to completed state (0)
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Readiness_Completion_MapCompletedStatePID01(
  uint32 Pid01Data
);

/* ****************************************************************************
 * Dem_Readiness_Completion_MapCompletedStateDIDF501
 *****************************************************************************/
/*!
 * \brief         Updates the Completion Bits to completed readiness groups to 0.
 *
 * \details       Updates the Completion Bits to completed readiness groups to 0,
 *                based on in the Main Function calculated completion states.
 *
 * \param[in]     DIDF501
 *                Did F501 formatted data block
 *                with the completion of supported readiness groups set to
 *                not completed
 *
 * \result        Did F501 formatted data block
 *                Completed readiness groups are set to completed state (0)
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Completion_MapCompletedStateDIDF501(
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) DIDF501
);



/* ****************************************************************************
 * Dem_Readiness_Completion_SetStaticallyCalculatedCompletionStatesPID
 *****************************************************************************/
/*!
 * \brief         Function sets readiness groups, which are configured
 *                to be always complete as completed.
 *
 * \details       Function sets readiness groups, which are configured
 *                to be always complete as completed.
 *
 * \param[in]     PidValue
 *                Pid formatted data block
 * \param[in]     PIDContext
 *                Indicates if the function is invoked for processing PID 0x01
 *                or PID 0x41.
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Readiness_Completion_SetStaticallyCalculatedCompletionStatesPID(
  CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC) PidValue,
  uint8  PIDContext
);


/* ****************************************************************************
 * Dem_Readiness_Completion_SetStaticallyCalculatedCompletionStatesDIDF501
 *****************************************************************************/
/*!
 * \brief         Function sets readiness groups, which are configured
 *                to be always complete as completed.
 *
 * \details       Function sets readiness groups, which are configured
 *                to be always complete as completed.
 *
 * \param[in]     DIDF501
 *                DID F501 formatted data block
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Readiness_Completion_SetStaticallyCalculatedCompletionStatesDIDF501(
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) DIDF501
);




/* ****************************************************************************
 * Dem_Readiness_Completion_TestStaticallyCalculatedCompletionStates
 *****************************************************************************/
/*!
 * \brief         Function returns if the completeness for readiness group is
 *                dynamically calculated
 *
 * \details       Function returns if the completeness for readiness group is
 *                dynamically calculated
 *
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 * \param[in]     PIDContext
 *                Indicates if the function is invoked for processing PID 0x01
 *                or PID 0x41.
 *
 * \return        TRUE
 *                Completeness for readiness group is dynamically calculated
 * \return        FALSE
 *                Completeness for readiness group is not dynamically calculated
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_Readiness_Completion_TestStaticallyCalculatedCompletionStates(
  uint8  ReadinessGroup,
  uint8  PIDContext
);



/* ****************************************************************************
 * Dem_Readiness_Completion_ResetGlobalCompletionStates
 *****************************************************************************/
/*!
 * \brief        Resets globally all readiness completions of all readiness groups.
 *
 * \details      Resets globally all readiness completions of all readiness groups.
 *
 *
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Readiness_Completion_ResetGlobalCompletionStates(
  void
);

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Completion_Interface.h
 *********************************************************************************************************************/
