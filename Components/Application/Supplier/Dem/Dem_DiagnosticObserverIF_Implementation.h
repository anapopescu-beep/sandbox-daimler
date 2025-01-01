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
/*! \addtogroup Dem_DiagnosticObserverIF
 *  \{
 *  \file       Dem_DiagnosticObserverIF_Implementation.h
 *  \brief      Implementation of unit DiagnosticObserverIF.
 *  \details    Realizes the public interfaces of its parent logical unit, i.e. both Dem external service APIs and Dem internal APIs.
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_DIAGNOSTICOBSERVERIF_IMPLEMENTATION_H)
#define DEM_DIAGNOSTICOBSERVERIF_IMPLEMENTATION_H

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

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_DiagnosticObserverIF_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_Dtr_Interface.h"
#include "Dem_Iumpr_Interface.h"

/* Includes to access public functions belonging to other (top level)/ (logical)/- units to be used by this Unit */
/* ------------------------------------------------------------------------- */
#include "Dem_Core_Interface.h"
#include "Dem_GlobalDiagnostics_Interface.h"
#include "Dem_FaultMemory_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

  /*! Filename declaration */
#define DEM_DIAGNOSTICOBSERVERIF_IMPLEMENTATION_FILENAME "Dem_DiagnosticObserverIF_Implementation.h"

/* ********************************************************************************************************************
 *  UNIT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_GlobalStateIF_Private Private Methods
 * \{
 */
/* ****************************************************************************
 * Dem_DiagnosticObserver_TestEventTriggerConfirmed
 *****************************************************************************/
/*!
 * \brief         Test if bit for CDTC update is set
 *
 * \details       Test if bit for CDTC update is set
 *
 * \param[in]     EventTrigger
 *                Bitmask for event update trigger
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DiagnosticObserver_TestEventTriggerConfirmed(
  CONST(Dem_Cfg_StorageTriggerType, AUTOMATIC) EventTrigger
);

/* ****************************************************************************
 * Dem_DiagnosticObserver_TestEventTriggerWIR
 *****************************************************************************/
/*!
 * \brief         Test if bit for WIR update is set
 *
 * \details       Test if bit for WIR update is set
 *
 * \param[in]     EventTrigger
 *                Bitmask for event update trigger
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DiagnosticObserver_TestEventTriggerWIR(
  CONST(Dem_Cfg_StorageTriggerType, AUTOMATIC) EventTrigger
);

/* ****************************************************************************
 * Dem_DiagnosticObserver_TestEventTriggerTestFailed
 *****************************************************************************/
/*!
 * \brief         Test if bit for TestFailed update is set
 *
 * \details       Test if bit for TestFailed update is set
 *
 * \param[in]     EventTrigger
 *                Bitmask for event update trigger
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DiagnosticObserver_TestEventTriggerTestFailed(
  CONST(Dem_Cfg_StorageTriggerType, AUTOMATIC) EventTrigger
);
/* ********************************************************************************************************************
 *  UNIT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/
/* ****************************************************************************
 % Dem_DiagnosticObserver_TestEventTriggerConfirmed
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DiagnosticObserver_TestEventTriggerConfirmed(
  CONST(Dem_Cfg_StorageTriggerType, AUTOMATIC) EventTrigger
)
{
    return ((EventTrigger & DEM_CFG_TRIGGER_CONFIRMED) != 0u);
}

/* ****************************************************************************
 % Dem_DiagnosticObserver_TestEventTriggerWIR
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DiagnosticObserver_TestEventTriggerWIR(
  CONST(Dem_Cfg_StorageTriggerType, AUTOMATIC) EventTrigger
)
{
    return ((EventTrigger & DEM_CFG_TRIGGER_INDICATOR) != 0u);
}

/* ****************************************************************************
 % Dem_DiagnosticObserver_TestEventTriggerTestFailed
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DiagnosticObserver_TestEventTriggerTestFailed(
  CONST(Dem_Cfg_StorageTriggerType, AUTOMATIC) EventTrigger
)
{
    return ((EventTrigger & DEM_CFG_TRIGGER_TESTFAILED) != 0u);
}
/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"    

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_DiagnosticObserverIF_Public
 * \{
 */

/* ****************************************************************************
 % Dem_DiagnosticObserver_ProcessEventFailed
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DiagnosticObserver_ProcessEventFailed(
  CONSTP2CONST(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
)
{
  if (EventContext->EventEffects != DEM_CFG_TRIGGER_NONE)
  {
    if (Dem_DiagnosticObserver_TestEventTriggerWIR(EventContext->EventEffects) == TRUE)
    {
      /* Suppress the Indicators if the driving cycle is not qualified yet */
      if ((Dem_Cfg_IsObdSupportedInVariant() == FALSE)
        || (Dem_EventInternalStatus_Test_QualifyStatus_WIR(Dem_Event_GetQualifyStatus(EventContext->EventId)) == TRUE))
      {
        Dem_GlobalDiagnostics_GlobalState_ProcessEventWirEnabled(EventContext->EventId);
      }
    }

    if (Dem_Cfg_IsWwhObdSupportedInVariant() == TRUE)
    {
      /* increment counter only if event initially becomes confirmed or
         if it is still confirmed and test failed changes from 0 to 1 */
      if ((Dem_DiagnosticObserver_TestEventTriggerConfirmed(EventContext->EventEffects) == TRUE)
        || ((Dem_DiagnosticObserver_TestEventTriggerTestFailed(EventContext->EventEffects) == TRUE)
          && (Dem_UDSStatus_Test_CDTC(EventContext->OldEventStatus) == TRUE)))
      {
        Dem_GlobalState_ActivationMode_ProcessQualifiedActiveEvent(EventContext->EventId, TRUE);
      }
    }
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_DiagnosticObserver_ProcessEventPassed
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DiagnosticObserver_ProcessEventPassed(
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext,                                                            /* PRQA S 3673 */ /* MD_DEM_8.13_Internal */
CONSTP2VAR(Dem_DTC_ContextType, AUTOMATIC, AUTOMATIC) DTCContext                                                                 /* PRQA S 3673 */ /* MD_DEM_8.13_Internal */
)
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventContext);                                                                                /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DTCContext);                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
  if (Dem_Cfg_IsWwhObdSupportedInVariant() == TRUE)
  {
    if ((EventContext->EventEffects & DEM_CFG_TRIGGER_PASSED) != DEM_CFG_TRIGGER_NONE)
    {
      Dem_GlobalState_ActivationMode_DecrementQualifiedActiveEventCount(EventContext->EventId, FALSE);

# if (DEM_CFG_SUPPORT_PERMANENT == STD_ON)
      if (Dem_DTC_TestEventStoresPermanentDTC(DTCContext->EventId) == TRUE)
      {
        if ((Dem_DTC_IsEventCombinationEnabled() == FALSE)
          || ((Dem_UDSStatus_Test_TF(DTCContext->OldDtcStatus) == TRUE)
            && (Dem_UDSStatus_Test_TF(DTCContext->NewDtcStatus) == FALSE)))
        {
          uint8 lPermanentIndex;

          /* If the event has a permanent DTC */
          lPermanentIndex = Dem_Data_PermanentEntryFind(Dem_Cfg_GetMasterEvent(DTCContext->EventId));
          if (lPermanentIndex != Dem_Cfg_GlobalPermanentMaxCount())
          {
            uint8 lPermanentState;
            lPermanentState = Dem_Mem_PermanentGetStatus(lPermanentIndex);

            if (DEM_ESM_GET_PERMANENT_STATE(lPermanentState) == DEM_ESM_PERMANENT_ACTIVE)
            {
              Dem_Data_PermanentEntryRemove(lPermanentIndex);
              Dem_Memory_PermanentFillUp();
            }
          }
        }
      }
# endif
    }
  }
#endif
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_DiagnosticObserver_ProcessEventCleared
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DiagnosticObserver_ProcessEventCleared(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_UdsStatusByteType, AUTOMATIC) OldEventStatus
)
{

  Dem_Dtr_ResetDtrsOfEvent(EventId);


  if (Dem_UDSStatus_Test_WIR(OldEventStatus) == TRUE)
  {
    Dem_GlobalDiagnostics_GlobalState_ProcessEventWirDisabled(EventId); 
  }

}

/* ****************************************************************************
 % Dem_DiagnosticObserver_ProcessEventHealed
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DiagnosticObserver_ProcessEventHealed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
)
{
    Dem_GlobalDiagnostics_GlobalState_ProcessEventWirDisabled(EventId);
}

/* ****************************************************************************
 % Dem_DiagnosticObserver_ProcessDcyOfEventQualified
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DiagnosticObserver_ProcessDcyOfEventQualified(                                                                               /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_Cfg_StorageTriggerType, AUTOMATIC) EventQualificationTrigger
  )
{
  Dem_GlobalDiagnostics_ProcessDcyOfEventQualified(EventId,
    Dem_DiagnosticObserver_TestEventTriggerConfirmed(EventQualificationTrigger),
    Dem_DiagnosticObserver_TestEventTriggerWIR(EventQualificationTrigger));
 
}
/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DIAGNOSTICOBSERVERIF_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_DiagnosticObserverIF_Implementation.h
 *********************************************************************************************************************/
