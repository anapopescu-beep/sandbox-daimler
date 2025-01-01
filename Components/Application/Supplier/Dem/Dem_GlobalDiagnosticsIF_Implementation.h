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
/*! \addtogroup Dem_GlobalDiagnosticsIF
 *  \{
 *  \file       Dem_GlobalDiagnosticsIF_Implementation.h
 *  \brief      Implementation of unit GlobalDiagnosticsIF.
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

#if !defined (DEM_GLOBALDIAGNOSTICSIF_IMPLEMENTATION_H)
#define DEM_GLOBALDIAGNOSTICSIF_IMPLEMENTATION_H

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
#include "Dem_GlobalDiagnosticsIF_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_Readiness_Interface.h"
#include "Dem_Conditions_Interface.h"
#include "Dem_GlobalState_Interface.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Infrastructure_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

  /*! Filename declaration */
#define DEM_GLOBALDIAGNOSTICSIF_IMPLEMENTATION_FILENAME "Dem_GlobalDiagnosticsIF_Implementation.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_GlobalDiagnosticsIF_Public
 * \{
 */

/* ****************************************************************************
 % Dem_GlobalDiagnostics_PreInit
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_GlobalDiagnostics_PreInit(
  void
)
{
  Dem_GlobalDiagnostics_Conditions_PreInit();
}

/* ****************************************************************************
 % Dem_GlobalDiagnostics_InitPreCore
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_GlobalDiagnostics_InitPreCore(
  void
)
{
  Dem_GlobalDiagnostics_Conditions_Init();
}

/* ****************************************************************************
 % Dem_GlobalDiagnostics_InitPostCore
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_GlobalDiagnostics_InitPostCore(
  void
)
{
  Dem_GlobalDiagnostics_GlobalState_Init();
}

/* ****************************************************************************
 % Dem_GlobalDiagnostics_ProcessDcyOfEventQualified
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
Dem_GlobalDiagnostics_ProcessDcyOfEventQualified(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(boolean, AUTOMATIC)  CDTCQualified,
  CONST(boolean, AUTOMATIC)  WIRQualified
  )
{
  if (CDTCQualified == TRUE)
  {
    if (Dem_GlobalDiagnostics_Readiness_IsReadinessCalculationSupported() == TRUE)
    {
      /* Set readiness group to completed */
      uint8 lEventReadinessGroup;
      lEventReadinessGroup = Dem_Cfg_EventReadinessGroup(EventId);
      if (Dem_Readiness_Completion_TestStaticallyCalculatedCompletionStates(lEventReadinessGroup, DEM_COMPLETION_PIDCONTEXT_PID01_AND_PIDF501) == FALSE)
      {
        Dem_Readiness_Completion_SetReadinessGroupCompleted(TRUE, lEventReadinessGroup);                       /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
      }
    }

    if (Dem_Cfg_IsWwhObdSupportedInVariant() == TRUE)
    {
      Dem_GlobalState_ActivationMode_ProcessQualifiedActiveEvent(EventId, TRUE);
    }
  }

  if (WIRQualified == TRUE)                                                                         
  { 
    /* Process the indicators */
    Dem_GlobalDiagnostics_GlobalState_ProcessEventWirEnabled(EventId);
  }
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_GLOBALDIAGNOSTICSIF_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_GlobalDiagnosticsIF_Implementation.h
 *********************************************************************************************************************/
