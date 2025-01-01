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
 *  \defgroup   Dem_ActivationMode ActivationMode
 *  \{
 *  \file       Dem_ActivationMode_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Manages the User and Special indicator states
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_ACTIVATIONMODE_INTERFACE_H)
#define DEM_ACTIVATIONMODE_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Dem_Int.h"
                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \defgroup Dem_ActivationMode_PublicProperties Public Properties
 * \{
 */


/* ****************************************************************************
 * Dem_ActivationMode_GetQualifiedActiveEventCount
 *****************************************************************************/
/*!
 * \brief         Get the number of qualified active and failed events for the
 *                WWH-OBD DTC class
 *
 * \details       Get the number of qualified active and failed events for the
 *                WWH-OBD DTC class
 *
 * \param[in]     WwhObdDtcClass
 *                Unique handle of the WWH-OBD DTC class
 *
 * \return        The number of qualified active and failed events
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_ActivationMode_GetQualifiedActiveEventCount(
  CONST(uint8, AUTOMATIC)  WwhObdDtcClass
  );


/* ****************************************************************************
 * Dem_ActivationMode_GetDtcClassMILCount
 *****************************************************************************/
/*!
 * \brief         Get the number of MIL requests for the WWHO-OBD DTC class
 *
 * \details       Get the number of MIL requests for the WWHO-OBD DTC class
 *
 * \param[in]     WwhObdDtcClass
 *                Unique handle of the WWH-OBD DTC class
 *
 * \return        The number of MIL requests
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_ActivationMode_GetDtcClassMILCount(
  CONST(uint8, AUTOMATIC)  WwhObdDtcClass
  );

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \defgroup Dem_ActivationMode_Public Public Methods
 * \{
 */

/* ****************************************************************************
 * Dem_GlobalState_ActivationMode_Init
 *****************************************************************************/
/*!
 * \brief         Initializes Unit ActivationMode 
 *
 * \details       Initialize the activation mode of the ECU based on the status
 *                of all events available in this configuration variant.
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_GlobalState_ActivationMode_Init(
  void
  );


#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/* ****************************************************************************
 * Dem_ActivationMode_GlobalIndicatorActivationMode
 *****************************************************************************/
/*!
 * \brief         Gets the current Activation Mode.
 *
 * \details       Gets the current Activation Mode.
 *
 * \return        The current activation mode
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_IndicatorStatusType, DEM_CODE)
Dem_ActivationMode_GlobalIndicatorActivationMode(
  void
  );
#endif


/* ****************************************************************************
 * Dem_GlobalState_ActivationMode_ResetEventCounter
 *****************************************************************************/
/*!
 * \brief         Initializes the WWHOBD Dtc class related statistics
 *
 * \details       Initializes the WWHOBD Dtc class related statistics
 *
 * \pre           May be called only during module initialization
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_GlobalState_ActivationMode_ResetEventCounter(
  void
  );

/* ****************************************************************************
 * Dem_GlobalState_ActivationMode_IncrementDtcClassMILCount
 *****************************************************************************/
/*!
 * \brief         Increment DtcClass MIL Count
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique identifier of the event   
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_GlobalState_ActivationMode_IncrementDtcClassMILCount(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

/* ****************************************************************************
 * Dem_GlobalState_ActivationMode_DecrementDtcClassMILCount
 *****************************************************************************/
/*!
 * \brief         Decrement DtcClass MIL Count
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique identifier of the event   
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_GlobalState_ActivationMode_DecrementDtcClassMILCount(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

/* ****************************************************************************
 * Dem_GlobalState_ActivationMode_ProcessQualifiedActiveEvent
 *****************************************************************************/
/*!
 * \brief         Handles the increment of the qualified active DTC count.
 *
 * \details       This function calculates the qualified active DTC counter
 *                when an event transitions from not active to qualified active.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     AddPermanentEntry
 *                TRUE   A permanent DTC is created for event (if possible).
 *                FALSE  No permanent DTC is created for event.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_GlobalState_ActivationMode_ProcessQualifiedActiveEvent(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(boolean, AUTOMATIC) AddPermanentEntry
  );

/* ****************************************************************************
 * Dem_GlobalState_ActivationMode_DecrementQualifiedActiveEventCount
 *****************************************************************************/
/*!
 * \brief         Handles the decrement of the qualified active DTC count.
 *
 * \details       This function calculates the qualified active DTC counter
 *                when an event transitions from qualified active to a state
 *                with TF == 0.
 *                If the counter reaches 0 this will start healing of the B1
 *                counter, and ContinousMI counter if activation mode 4 is not
 *                active.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     StartB1Healing
 *                Flag to control if B1 counter needs to heal
 *
 * \pre           -  
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_GlobalState_ActivationMode_DecrementQualifiedActiveEventCount(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(boolean, AUTOMATIC)  StartB1Healing
  );

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* Dem_ActivationMode_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_ActivationMode_Interface.h
 *********************************************************************************************************************/
