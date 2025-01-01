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
/*! \addtogroup Dem_ActivationMode
 *  \{
 *  \file       Dem_ActivationMode_Implementation.h
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

#if !defined (DEM_ACTIVATIONMODE_IMPLEMENTATION_H)
#define DEM_ACTIVATIONMODE_IMPLEMENTATION_H

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
/* PRQA S 0759 EOF */ /* MD_MSR_Union */

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_ActivationMode_Interface.h"

/* Includes to access public functions belonging to other (top level)/ (logical)/- units to be used by this Unit */
#include "Dem_Infrastructure_Interface.h"
#include "Dem_Indicator_Interface.h"
#include "Dem_Core_Interface.h"
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/*! Filename declaration */
#define DEM_ACTIVATIONMODE_IMPLEMENTATION_FILENAME "Dem_ActivationMode_Implementation.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/

#define DEM_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define DEM_ESM_WWHOBD_NUMBER_DTCCLASS_ARRAY_SIZE (DEM_ESM_WWHOBD_NUMBER_DTCCLASS)

  /*! Number of qualified active and failed events per WWHO-OBD class. Index 0 (no class) is unused. */
  DEM_LOCAL VAR(Dem_EventIdType, DEM_VAR_NOINIT)   Dem_Esm_QualifiedActiveEventCount[DEM_ESM_WWHOBD_NUMBER_DTCCLASS_ARRAY_SIZE];
  /*! Number of MIL requests per WWHO-OBD class. Index 0 (no class) is unused. */
  DEM_LOCAL VAR(Dem_EventIdType, DEM_VAR_NOINIT)   Dem_Esm_DtcClassMILCount[DEM_ESM_WWHOBD_NUMBER_DTCCLASS_ARRAY_SIZE];


#define DEM_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE PROPERTIES DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \defgroup Dem_ActivationMode_PrivateProperties Private Properties
 * \{
 */

/* ****************************************************************************
 * Dem_ActivationMode_SetDtcClassMILCount
 *****************************************************************************/
/*!
 * \brief         Set the number of MIL requests for the WWH-OBD DTC class
 *
 * \details       Set the number of MIL requests for the WWH-OBD DTC class
 *
 * \param[in]     WwhObdDtcClass
 *                Unique handle of the WWH-OBD DTC class
 * \param[in]     DtcClassMILCount
 *                The new number of MIL requests
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ActivationMode_SetDtcClassMILCount(
  CONST(uint8, AUTOMATIC)  WwhObdDtcClass,
  CONST(Dem_EventIdType, AUTOMATIC)  DtcClassMILCount
  );

/* ****************************************************************************
 * Dem_ActivationMode_SetQualifiedActiveEventCount
 *****************************************************************************/
/*!
 * \brief         Set the number of qualified active and failed events for the
 *                WWH-OBD DTC class
 *
 * \details       Set the number of qualified active and failed events for the
 *                WWH-OBD DTC class
 *
 * \param[in]     WwhObdDtcClass
 *                Unique handle of the WWH-OBD DTC class
 * \param[in]     QualifiedActiveEventCount
 *                The new number of qualified active and failed events
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ActivationMode_SetQualifiedActiveEventCount(
  CONST(uint8, AUTOMATIC)  WwhObdDtcClass,
  CONST(Dem_EventIdType, AUTOMATIC)  QualifiedActiveEventCount
  );


/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE PROPERTIES DEFINITIONS
 *********************************************************************************************************************/


/* ****************************************************************************
 % Dem_ActivationMode_SetDtcClassMILCount
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ActivationMode_SetDtcClassMILCount(
  CONST(uint8, AUTOMATIC)  WwhObdDtcClass,
  CONST(Dem_EventIdType, AUTOMATIC)  DtcClassMILCount
  )
{
  if (Dem_Cfg_IsWwhObdSupportedInVariant() == TRUE)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if (WwhObdDtcClass >= DEM_ESM_WWHOBD_NUMBER_DTCCLASS)
    {
      Dem_Error_RunTimeCheckFailed(DEM_ACTIVATIONMODE_IMPLEMENTATION_FILENAME, __LINE__);                                               /* SBSW_DEM_POINTER_RUNTIME_CHECK */
    }
    else
# endif
    {
      Dem_Esm_DtcClassMILCount[WwhObdDtcClass] = DtcClassMILCount;                                                                 /* SBSW_DEM_ARRAY_WRITE_DTCCLASSMILCOUNT */
    }
  }
}

/* ****************************************************************************
 % Dem_ActivationMode_SetQualifiedActiveEventCount
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ActivationMode_SetQualifiedActiveEventCount(                                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  CONST(uint8, AUTOMATIC)  WwhObdDtcClass,
  CONST(Dem_EventIdType, AUTOMATIC)  QualifiedActiveEventCount
  )
{

# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (WwhObdDtcClass >= DEM_ESM_WWHOBD_NUMBER_DTCCLASS)
  {
    Dem_Error_RunTimeCheckFailed(DEM_ACTIVATIONMODE_IMPLEMENTATION_FILENAME, __LINE__);                                               /* SBSW_DEM_POINTER_RUNTIME_CHECK */
  }
  else
# endif
  {
    Dem_Esm_QualifiedActiveEventCount[WwhObdDtcClass] = QualifiedActiveEventCount;                                               /* SBSW_DEM_ARRAY_WRITE_QUALIFIEDACTIVEEVENTCOUNT */
  }
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ********************************************************************************************************************
 *  SUBCOMPONENT PUBLIC PROPERTIES DEFINITIONS
 *********************************************************************************************************************/

#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \addtogroup Dem_ActivationMode_PublicProperties
 * \{
 */




/* ****************************************************************************
 % Dem_ActivationMode_GetQualifiedActiveEventCount
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_ActivationMode_GetQualifiedActiveEventCount(                                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  CONST(uint8, AUTOMATIC)  WwhObdDtcClass
  )
{
  Dem_EventIdType lReturn;
  if (Dem_Cfg_IsWwhObdSupportedInVariant() == TRUE)                                                                              /* COV_DEM_UNIT_ENTRY_CONFIGURATION_CHECK */
  {
    lReturn = Dem_Esm_QualifiedActiveEventCount[WwhObdDtcClass];
  }
  else
  {
    lReturn = 0;
  }
  return lReturn;
}



/* ****************************************************************************
 % Dem_ActivationMode_GetDtcClassMILCount
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_ActivationMode_GetDtcClassMILCount(
  CONST(uint8, AUTOMATIC)  WwhObdDtcClass
  )
{
  Dem_EventIdType lReturn;
  if (Dem_Cfg_IsWwhObdSupportedInVariant() == TRUE)                                                                              /* COV_DEM_UNIT_ENTRY_CONFIGURATION_CHECK */
  {
    lReturn = Dem_Esm_DtcClassMILCount[WwhObdDtcClass];
  }
  else
  {
    lReturn = 0;
  }
  return lReturn;
}



/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \defgroup Dem_ActivationMode_Private Private Methods
 * \{
 */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \addtogroup Dem_ActivationMode_Public
 * \{
 */                                                                                                                         /* PRQA S 6050 */ /* MD_MSR_STCAL */


/* ****************************************************************************
 % Dem_GlobalState_ActivationMode_Init
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_GlobalState_ActivationMode_Init(
  void
  )
{
  if (Dem_Cfg_IsWwhObdSupportedInVariant() == TRUE)
  {
    Dem_EventIdType lEventId;

    Dem_GlobalState_ActivationMode_ResetEventCounter();

    for (lEventId = DEM_EVENT_FIRST; lEventId < Dem_Cfg_GlobalEventCount(); ++lEventId)
    {
      if (Dem_Event_TestEventAvailable(lEventId) == TRUE)
      {
        Dem_UDSStatus_Type lExternalEventStatus = Dem_Event_GetExternalUDSStatus(lEventId, Dem_Event_GetUDSStatus(lEventId));

        if (Dem_UDSStatus_Test_WIR(lExternalEventStatus) == TRUE)
        {
          Dem_GlobalState_ActivationMode_IncrementDtcClassMILCount(lEventId);
        }

        /* Permanent entry is restored from NVRAM -> skip it's processing */
        Dem_GlobalState_ActivationMode_ProcessQualifiedActiveEvent(lEventId, FALSE);
      }
    }
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */



/* ****************************************************************************
 % Dem_GlobalState_ActivationMode_ResetEventCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_GlobalState_ActivationMode_ResetEventCounter(
  void
  )
{
#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)

  uint8 lDtcClassIndex;

  lDtcClassIndex = DEM_ESM_WWHOBD_NUMBER_DTCCLASS;

  while (lDtcClassIndex != 0u)
  {
    --lDtcClassIndex;

    Dem_ActivationMode_SetQualifiedActiveEventCount(lDtcClassIndex, 0);
    Dem_ActivationMode_SetDtcClassMILCount(lDtcClassIndex, 0);
  }
#endif
}

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/* ****************************************************************************
 % Dem_ActivationMode_GlobalIndicatorActivationMode
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
DEM_LOCAL_INLINE FUNC(Dem_IndicatorStatusType, DEM_CODE)
Dem_ActivationMode_GlobalIndicatorActivationMode(
  void
  )
{
  Dem_IndicatorStatusType lReturnValue;

  /* calculate the current activation mode */
  if ( (Dem_ActivationMode_GetQualifiedActiveEventCount(DEM_ESM_WWHOBD_DTCCLASS_A) != 0u)
    || (DEM_DATA_B1COUNTER_200H <= Dem_Mem_GetB1Counter()) )
  { /* Class A event currently active or B1 counter exceeds threshold */
    lReturnValue = DEM_INDICATOR_CONTINUOUS;
  }
  else if ( (Dem_ActivationMode_GetDtcClassMILCount(DEM_ESM_WWHOBD_DTCCLASS_A) != 0u) 
         || (Dem_ActivationMode_GetDtcClassMILCount(DEM_ESM_WWHOBD_DTCCLASS_B1) != 0u)                                                                                                  
         || (Dem_ActivationMode_GetDtcClassMILCount(DEM_ESM_WWHOBD_DTCCLASS_B2) != 0u) )                                               
  {
    lReturnValue = DEM_INDICATOR_SHORT;
  }
  else if (Dem_ActivationMode_GetDtcClassMILCount(DEM_ESM_WWHOBD_DTCCLASS_C) != 0u)
  {
    lReturnValue = DEM_INDICATOR_ON_DEMAND;
  }
  else /* DEM_ESM_WWHOBD_DTCCLASS_NO */
  {
    lReturnValue = DEM_INDICATOR_OFF;
  }
  return lReturnValue;
}
#endif

/* ****************************************************************************
 % Dem_GlobalState_ActivationMode_IncrementDtcClassMILCount
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_GlobalState_ActivationMode_IncrementDtcClassMILCount(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  if (Dem_Cfg_IsWwhObdSupportedInVariant() == TRUE)
  {
    if (Dem_Core_Event_TestMilAssigned(EventId))
    {
      uint8 lWwhObdDtcClass;
      lWwhObdDtcClass = Dem_Util_SeverityWwhObdDtcClass(Dem_Cfg_EventSeverity(EventId));
      Dem_ActivationMode_SetDtcClassMILCount(lWwhObdDtcClass, Dem_ActivationMode_GetDtcClassMILCount(lWwhObdDtcClass) + 1u);
    }
  }
}

/* ****************************************************************************
 % Dem_GlobalState_ActivationMode_DecrementDtcClassMILCount
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_GlobalState_ActivationMode_DecrementDtcClassMILCount(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  if (Dem_Cfg_IsWwhObdSupportedInVariant() == TRUE)
  {
    if (Dem_Core_Event_TestMilAssigned(EventId))
    {
      uint8 lWwhObdDtcClass;
      lWwhObdDtcClass = Dem_Util_SeverityWwhObdDtcClass(Dem_Cfg_EventSeverity(EventId));
      Dem_ActivationMode_SetDtcClassMILCount(lWwhObdDtcClass, Dem_ActivationMode_GetDtcClassMILCount(lWwhObdDtcClass) - 1u);
    }
  }
}


/* ****************************************************************************
 % Dem_GlobalState_ActivationMode_ProcessQualifiedActiveEvent
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
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_GlobalState_ActivationMode_ProcessQualifiedActiveEvent(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(boolean, AUTOMATIC)  AddPermanentEntry
  )
{
#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
  if (Dem_Cfg_IsWwhObdSupportedInVariant() == TRUE)                                                                              /* COV_DEM_UNIT_ENTRY_CONFIGURATION_CHECK */
  {
    if ((Dem_Core_Event_TestMilAssigned(EventId) == TRUE)
      && (Dem_EventInternalStatus_Test_QualifyStatus_CDTC(Dem_Event_GetQualifyStatus(EventId)) == TRUE)
      && (Dem_UDSStatus_Test_TF(Dem_Event_GetUDSStatus(EventId)) == TRUE))
    {
      uint8 lWwhObdDtcClass;
      lWwhObdDtcClass = Dem_Util_SeverityWwhObdDtcClass(Dem_Cfg_EventSeverity(EventId));

      if (Dem_DTC_TestEventStoresPermanentDTC(EventId) == TRUE)
      {
        if (AddPermanentEntry == TRUE)
        { /* Always try to store a permanent DTC */
          if ((lWwhObdDtcClass == DEM_ESM_WWHOBD_DTCCLASS_A)
            || (Dem_Mem_GetB1Counter() > DEM_DATA_B1COUNTER_200H))
          {
            Dem_Data_PermanentEntryAdd(EventId);
          }
        }
      }

      Dem_ActivationMode_SetQualifiedActiveEventCount(lWwhObdDtcClass, Dem_ActivationMode_GetQualifiedActiveEventCount(lWwhObdDtcClass) + 1u);

      /* if continuous MI counter is not active yet and activation mode 4 becomes active , set to Run state */
      if ((Dem_Mem_GetContinuousMiHealingCounter() != DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_INVALID)
        && (Dem_ActivationMode_GlobalIndicatorActivationMode() == DEM_INDICATOR_CONTINUOUS))
      {
        /* if continuous MI counter was healed and is currently aging, reset continuous MI counter */
        if (Dem_Mem_GetContinuousMiAgingCounter() < DEM_DATA_CONTINUOUS_MI_AGING_COUNTER_AGED)
        {
          Dem_Mem_SetContinuousMiCounter(0);
        }
        Dem_Mem_SetContinuousMiHealingCounter(DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_INVALID);
        Dem_Mem_SetContinuousMiAgingCounter(DEM_DATA_CONTINUOUS_MI_AGING_COUNTER_INVALID);
        Dem_Mem_SetContinuousMiAgingTimer(DEM_DATA_CONTINUOUS_MI_AGING_TIMER_INVALID);
      }
    }
  }
#else
    DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                    /* PRQA S 3112 */ /* MD_DEM_14.2 */
    DEM_IGNORE_UNUSED_CONST_ARGUMENT(AddPermanentEntry)                                                                          /* PRQA S 3112 */ /* MD_DEM_14.2 */
#endif
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_GlobalState_ActivationMode_DecrementQualifiedActiveEventCount
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
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_GlobalState_ActivationMode_DecrementQualifiedActiveEventCount(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(boolean, AUTOMATIC) StartB1Healing
  )
{
#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
  if ( (Dem_Core_Event_TestMilAssigned(EventId) == TRUE)
    && (Dem_EventInternalStatus_Test_QualifyStatus_CDTC(Dem_Event_GetQualifyStatus(EventId)) == TRUE) )                          
  {
    uint16 lEventCountB1Old;
    uint8 lWwhObdDtcClass;

    lEventCountB1Old = Dem_ActivationMode_GetQualifiedActiveEventCount(DEM_ESM_WWHOBD_DTCCLASS_B1);
    lWwhObdDtcClass = Dem_Util_SeverityWwhObdDtcClass(Dem_Cfg_EventSeverity(EventId));
    Dem_ActivationMode_SetQualifiedActiveEventCount(lWwhObdDtcClass, Dem_ActivationMode_GetQualifiedActiveEventCount(lWwhObdDtcClass) - 1u);

    if ( (lEventCountB1Old != 0u)
      && (Dem_ActivationMode_GetQualifiedActiveEventCount(DEM_ESM_WWHOBD_DTCCLASS_B1) == 0u) )                                         
    {
      if (Dem_Mem_GetB1Counter() >= DEM_DATA_B1COUNTER_200H)
      { /* set B1Counter to 190h (11400min) if no B1 event is confirmed and failed and B1 counter is greater than 200h (12000min)
        also clear the healing counter */
        Dem_Mem_SetB1Counter(DEM_DATA_B1COUNTER_190H);
      }

      if (StartB1Healing == TRUE)
      {
        Dem_Mem_SetB1HealingCounter(0);
      }
      else
      {
        Dem_Mem_SetB1HealingCounter(DEM_DATA_B1_HEALING_COUNTER_THRESHOLD);
      }
    }

    /* prepare continuous MI Healing if activation mode 4 is not active */
    if ( (Dem_Mem_GetContinuousMiHealingCounter() == DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_INVALID)
      && (Dem_ActivationMode_GlobalIndicatorActivationMode() != DEM_INDICATOR_CONTINUOUS) )                                           
    {
      Dem_Mem_SetContinuousMiHealingCounter(DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_LOCKED);
    }
  }
#else
    DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                    /* PRQA S 3112 */ /* MD_DEM_14.2 */
    DEM_IGNORE_UNUSED_CONST_ARGUMENT(StartB1Healing)                                                                             /* PRQA S 3112 */ /* MD_DEM_14.2 */

#endif
}                                                                                                                               /* PRQA S 6050 */ /* MD_MSR_STCAL */ 

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* DEM_ACTIVATIONMODE_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_ActivationMode_Implementation.h
 *********************************************************************************************************************/
