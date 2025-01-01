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
/*! \addtogroup Dem_Esm
 *  \{
 *  \file       Dem_Esm_Implementation.h
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

#if !defined (DEM_ESM_IMPLEMENTATION_H)
#define DEM_ESM_IMPLEMENTATION_H

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
#include "Dem_Esm_Interface.h"

/* Includes to access public functions belonging to other (top level)/ (logical)/- units to be used by this Unit */
/* ------------------------------------------------------------------------- */
#include "Dem_Infrastructure_Interface.h"
#include "Dem_GlobalDiagnostics_Interface.h"
#include "Dem_FaultMemory_Interface.h"
#include "Dem_DiagnosticObserver_Interface.h"
#include "Dem_RecordReader_Interface.h"
#include "Dem_OperationCycle_Interface.h"
#include "Dem_Event_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/*! Filename declaration */
#define DEM_ESM_IMPLEMENTATION_FILENAME "Dem_Esm_Implementation.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \addtogroup Dem_Esm_Public
 * \{
 */

/* ****************************************************************************
 % Dem_Util_SeverityWwhObdDtcClass
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
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Util_SeverityWwhObdDtcClass(                                                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  CONST(Dem_DTCSeverityType, AUTOMATIC)  Severity
  )
{
  uint8 lReturnValue;

  switch (Severity & 0x1fU) /* ignore the UDS severity bits */
  {
  case DEM_SEVERITY_WWHOBD_CLASS_A:
    lReturnValue = DEM_ESM_WWHOBD_DTCCLASS_A;
    break;
  case DEM_SEVERITY_WWHOBD_CLASS_B1:
    lReturnValue = DEM_ESM_WWHOBD_DTCCLASS_B1;
    break;
  case DEM_SEVERITY_WWHOBD_CLASS_B2:
    lReturnValue = DEM_ESM_WWHOBD_DTCCLASS_B2;
    break;
  case DEM_SEVERITY_WWHOBD_CLASS_C:
    lReturnValue = DEM_ESM_WWHOBD_DTCCLASS_C;
    break;
  case DEM_SEVERITY_WWHOBD_CLASS_NO_CLASS:
    lReturnValue = DEM_ESM_WWHOBD_DTCCLASS_NO;
    break;
  default:
    Dem_Error_ReportError(DEM_INTERNAL_APIID, DEM_E_INCONSISTENT_STATE);
    lReturnValue = 0x00U;
    break;
  }
  return lReturnValue;
}

#if (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) || (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON)
/* ****************************************************************************
 % Dem_Util_J1939OccurrenceCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Util_J1939OccurrenceCounter(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  uint8 lReturnValue;

  if (Dem_DTC_TestStoredStatus(EventId) == TRUE)
  {
    /* Stored DTC, so occurrence counter is available in primary memory */
    Dem_MemoryEntry_OccurrenceCounterType lOccurrenceCounter;
    lOccurrenceCounter = Dem_MemoryEntry_GetOccurrenceCounter(Dem_MemoryEntry_GetId(Dem_Memory_FindMemoryIndex_StoredEvent(EventId)));

    /* Latch the counter value at 126 */
    if (lOccurrenceCounter > 0x7eU)
    {
      lOccurrenceCounter = 0x7eU;
    }
    lReturnValue = (uint8)lOccurrenceCounter;
  }
  else
  {
    lReturnValue = 0x7fU;
  }

  return lReturnValue;
}
#endif /* (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) || (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON) */



#if (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON)
/* ****************************************************************************
 % Dem_Util_SetReadinessGroupDisabled
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Util_SetReadinessGroupDisabled(
  CONST(uint8, AUTOMATIC)  ReadinessGroup
  )
{
  uint16 lPid41DisabledMask;
  uint16 lSetRdyGroupDisabledMask;

  switch (ReadinessGroup)
  {
  case DEM_CFG_READINESS_MISF:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_MISF_MASK;
    break;
  case DEM_CFG_READINESS_FLSYS:
  case DEM_CFG_READINESS_FLSYS_NONCONT:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_FLSYS_MASK;
    break;
  case DEM_CFG_READINESS_CMPRCMPT:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_CMPRCMPT;
    break;
  case DEM_CFG_READINESS_CAT:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_CAT_MASK;
    break;
  case DEM_CFG_READINESS_HCCAT:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_HCCAT_MASK;
    break;
  case DEM_CFG_READINESS_HTCAT:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_HTCAT_MASK;
    break;
  case DEM_CFG_READINESS_NOXCAT:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_NOXCAT_MASK;
    break;
  case DEM_CFG_READINESS_EVAP:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_EVAP_MASK;
    break;
  case DEM_CFG_READINESS_SECAIR:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_SECAIR_MASK;
    break;
  case DEM_CFG_READINESS_BOOSTPR:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_BOOSTPR_MASK;
    break;
  case DEM_CFG_READINESS_O2SENS:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_O2SENS_MASK;
    break;
  case DEM_CFG_READINESS_EGSENS:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_EGSENS_MASK;
    break;
  case DEM_CFG_READINESS_O2SENSHT:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_O2SENSHT_MASK;
    break;
  case DEM_CFG_READINESS_PMFLT:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_PMFLT_MASK;
    break;
  case DEM_CFG_READINESS_EGR:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_EGR_MASK;
    break;
  default:
    lSetRdyGroupDisabledMask = DEM_READINESS_DISABLED_NONE_MASK;
    break;
  }

  /* >>>> -------------------------------- Enter Critical Section: StateManager */
  Dem_EnterCritical_StateManager();

  lPid41DisabledMask = Dem_Mem_GetPid41DisabledMask();
  lPid41DisabledMask |= lSetRdyGroupDisabledMask;
  Dem_Mem_SetPid41DisabledMask(lPid41DisabledMask);

  Dem_LeaveCritical_StateManager();
  /* <<<< -------------------------------- Leave Critical Section: StateManager */
}                                                                                                                                /* PRQA S 6030 */ /* MD_MSR_STCYC */
#endif

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/* ****************************************************************************
 % Dem_Esm_AddAgingTime
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Esm_AddAgingTime(
  CONST(uint32, AUTOMATIC)  CurrentTime,
  CONST(uint16, AUTOMATIC)  DeltaValue
  )
{
  uint32 lTargetTime;

  lTargetTime = (uint32)(CurrentTime + DeltaValue);

  return lTargetTime;
}
#endif
                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

#if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_RESTART_DCY_ON_CLEAR_DTC == STD_ON)
/* ****************************************************************************
 % Dem_Esm_PreOnClear_AllDtc
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_PreOnClear_AllDtc(
  CONST(uint16, AUTOMATIC)  MemoryId
  )
{
  if (MemoryId == DEM_CFG_MEMORYID_PRIMARY)
  {
    Dem_OperationCycle_CycleUpdate(Dem_Cfg_GlobalObdDrivingCycleId(), DEM_OPERATIONCYCLE_CYCLE_RESTARTED);
  }
}
#endif

/* ****************************************************************************
 % Dem_Esm_PostOnClear_AllDtc
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_PostOnClear_AllDtc(
  CONST(uint16, AUTOMATIC)  MemoryId
  )
{
  Dem_Memory_ResetOverflow(MemoryId);

  if (MemoryId == DEM_CFG_MEMORYID_PRIMARY)
  {
    Dem_Statistics_SetFirstFailedEvent(DEM_EVENT_INVALID);
    Dem_Statistics_SetFirstConfirmedEvent(DEM_EVENT_INVALID);
    Dem_Statistics_SetMostRecentFailedEvent(DEM_EVENT_INVALID);
    Dem_Statistics_SetMostRecentConfirmedEvent(DEM_EVENT_INVALID);
    Dem_Dtr_ResetDtrsOfEvent(DEM_EVENT_INVALID);
  }
}

/* ****************************************************************************
 % Dem_Esm_PostOnClear_Always
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
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_PostOnClear_Always(
  CONST(uint16, AUTOMATIC)  MemoryId                                                                                              /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  if (Dem_Cfg_IsObdSupportedInVariant() == TRUE)
  {
    if (MemoryId == DEM_CFG_MEMORYID_PRIMARY)
    {
#if (DEM_FEATURE_NEED_GLOBAL_MIL_STATE == STD_ON)
      if (Dem_GlobalState_Indicator_TestMilReportedActive() == FALSE)
      {
# if (DEM_CFG_SUPPORT_PID21 == STD_ON)
  /* >>>> -------------------------------- Enter Critical Section: NonAtomic32bit */
        Dem_EnterCritical_NonAtomic32bit();
        /* Clear Odometer for MIL on */
        Dem_Mem_SetOdometerMilOn(0);
        Dem_LeaveCritical_NonAtomic32bit();
  /* <<<< -------------------------------- Leave Critical Section: NonAtomic32bit */
# endif
# if (DEM_CFG_SUPPORT_PID4D == STD_ON)
        Dem_Mem_SetEngineTimeMilOn(0);
# endif
      }
#endif
    Dem_Iumpr_ResetPendingFids();
#if (DEM_CFG_SUPPORT_PID30 == STD_ON)
      /* Clear WarmUpCycle since last clear counter */
      Dem_Mem_SetWarmUpCountSinceClear(0x00U);
#endif
#if (DEM_CFG_SUPPORT_PID31 == STD_ON)
  /* >>>> -------------------------------- Enter Critical Section: NonAtomic32bit */
      Dem_EnterCritical_NonAtomic32bit();

      /* Set current Odometer value to invalid */
      Dem_Mem_SetOdometerAtClear(DEM_MEM_SET_ODOMETER_INVALID(0u));
      Dem_LeaveCritical_NonAtomic32bit();
  /* <<<< -------------------------------- Leave Critical Section: NonAtomic32bit */
#endif
#if (DEM_CFG_SUPPORT_PID4E == STD_ON)
      Dem_Mem_SetEngineTimeSinceClear(0x0000U);
#endif
#if (DEM_CFG_SUPPORT_OBDII_OR_OBDONUDS == STD_ON)
      if (Dem_Cfg_IsObdIIOrObdOnUdsSupportedInVariant() == TRUE)
      {
        /* >>>> -------------------------------- Enter Critical Section: StateManager */
        Dem_EnterCritical_StateManager();
        Dem_OperationCycle_SetObdCycleStates(DEM_OPERATIONCYCLE_RESET_PFC_CYCLE(Dem_OperationCycle_GetObdCycleStates()));
        Dem_LeaveCritical_StateManager();
        /* <<<< -------------------------------- Leave Critical Section: StateManager */
      }

#endif
#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
      if (Dem_Cfg_IsWwhObdSupportedInVariant() == TRUE)
      {
        Dem_Mem_SetContinuousMiAgingCounter(DEM_DATA_CONTINUOUS_MI_AGING_COUNTER_AGED);
        Dem_Mem_SetContinuousMiHealingCounter(DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_HEALED);
        Dem_Mem_SetContinuousMiAgingTimer(DEM_DATA_CONTINUOUS_MI_AGING_TIMER_AGED);
        Dem_Mem_SetContinuousMiCounter(0);
      }
#endif


      if (Dem_GlobalDiagnostics_Readiness_IsReadinessCalculationSupported() == TRUE)
      {
        /* all readiness groups are set to not complete */
        Dem_Readiness_Completion_ResetGlobalCompletionStates();

        /* set flag for all readiness group supported by engine type to recalculate monitor state -> not supported groups will be set to N/A = completed*/
        if (Dem_GlobalDiagnostics_Readiness_IsMotorTypeCompressionSupported() == TRUE)
        {
          Dem_Readiness_Completion_SetFullReadinessGroupUpdateFlag(DEM_READINESS_INITIALIZE_UPDATE_COMPRESSION);
        }
        else
        {
          Dem_Readiness_Completion_SetFullReadinessGroupUpdateFlag(DEM_READINESS_INITIALIZE_UPDATE_SPARK);
        }
      }
    }
  }


  /* copy debounce values from debounce array to nvram mirror */
  Dem_Mem_CopyDataDebounceNv(DEM_NVM_BLOCKSTATE_DIRTYCLEAREDIMMEDIATE);

  Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_ADMIN),
                              DEM_NVM_BLOCKSTATE_DIRTYCLEAREDIMMEDIATE);

#if (DEM_FEATURE_NEED_AGING_DATA == STD_ON)
  Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_AGINGDATA),
                              DEM_NVM_BLOCKSTATE_DIRTYCLEAREDIMMEDIATE);
#endif
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* DEM_ESM_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Esm_Implementation.h
 *********************************************************************************************************************/
