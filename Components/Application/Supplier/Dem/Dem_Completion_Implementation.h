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
/*! \addtogroup Dem_Completion
 *  \{
 *  \file       Dem_Completion_Implementation.h
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

#if !defined (DEM_COMPLETION_IMPLEMENTATION_H)
#define DEM_COMPLETION_IMPLEMENTATION_H

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
#include "Dem_Completion_Interface.h"

                                                    /* Used unit API */
/* ------------------------------------------------------------------------- */
#include "Dem_FaultMemory_Interface.h"
#include "Dem_Infrastructure_Interface.h"
#include "Dem_Core_Interface.h"
#include "Dem_Support_Interface.h"
#include "Dem_ReadinessIF_Interface.h"


                                                   /* unit callbacks*/
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  UNIT CONSTANT MACROS
 *********************************************************************************************************************/

  /*! Filename declaration */
#define DEM_COMPLETION_IMPLEMENTATION_FILENAME "Dem_Completion_Implementation.h"

 /* ********************************************************************************************************************
 *  UNIT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  UNIT DATA
 *********************************************************************************************************************/


#define DEM_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
#if (DEM_FEATURE_NEED_READINESS_CALCULATION == STD_ON)
 /*! Pending updates of readiness groups */
DEM_LOCAL volatile VAR(uint32, DEM_VAR_NOINIT)     Dem_Completion_UpdateFlag;
#endif
#define DEM_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */



/* ********************************************************************************************************************
 *  UNIT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
 
/* ********************************************************************************************************************
 *  UNIT PRIVATE PROPERTIES DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_Completion_PrivateProperties Private Properties
 * \{
 */

/* ****************************************************************************
 * Dem_Readiness_Completion_IsComprehensiveComponentCompletionDynamicallyCalculatedInDidF501
 *****************************************************************************/
/*!
 * \brief         Tests whether the comprehensive component monitor completion is dynamically calculated in PID F501
 *
 * \details       Tests whether the comprehensive component monitor completion is dynamically calculated in PID F501
 *
 * \return        TRUE
 *                The comprehensive component monitor completion is dynamically calculated in PID F501.
 * \return        FALSE
 *                The comprehensive component monitor completion is not dynamically calculated in PID F501.
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Readiness_Completion_IsComprehensiveComponentCompletionDynamicallyCalculatedInDidF501(
  void
  );

/* ********************************************************************************************************************
 *  UNIT PRIVATE PROPERTIES DEFINITIONS
 *********************************************************************************************************************/

/* ****************************************************************************
 % Dem_Readiness_Completion_IsComprehensiveComponentCompletionDynamicallyCalculatedInDidF501
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Readiness_Completion_IsComprehensiveComponentCompletionDynamicallyCalculatedInDidF501(                                       /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  void
  )
{
  boolean lReturnValue = FALSE;

  if (Dem_Cfg_IsObdOnUdsSupportedInVariant() == TRUE)
  {
    lReturnValue = (boolean)(DEM_CFG_PROCESS_PIDF501_COMPREHENSIVE_COMPLETE == STD_OFF);
  }

  return lReturnValue;
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  UNIT PUBLIC PROPERTIES DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_Completion_PublicProperties
 * \{
 */

 /* ****************************************************************************
 % Dem_Readiness_Completion_SetFullReadinessGroupUpdateFlag
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Readiness_Completion_SetFullReadinessGroupUpdateFlag(
  uint32 UpdateFlag
)
{
#if (DEM_FEATURE_NEED_READINESS_CALCULATION  == STD_ON)
  uint32 lOldValue;
  uint32 lNewValue;

  do
  {
    lOldValue = Dem_Completion_UpdateFlag;
    lNewValue = UpdateFlag;
  } while (Dem_Com_SyncCompareAndSwap(&Dem_Completion_UpdateFlag, lOldValue, lNewValue) == FALSE);                               /* SBSW_DEM_CALL_SYNC_COMPARE_AND_SWAP */
#endif
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(UpdateFlag)                                                                                   /* PRQA S 3112 */ /* MD_DEM_14.2 */
}



/* ****************************************************************************
 % Dem_Readiness_Completion_GetFullReadinessGroupUpdateFlag
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL FUNC(uint32, DEM_CODE)
Dem_Readiness_Completion_GetFullReadinessGroupUpdateFlag(
void
)
{
#if (DEM_FEATURE_NEED_READINESS_CALCULATION  == STD_ON)
  return Dem_Completion_UpdateFlag;
#else
  return 0u;
#endif
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  UNIT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_Completion_Private Private Methods
 * \{
 */

 /* ****************************************************************************
 * Dem_Readiness_Completion_SetReadinessGroupCompletedInDIDF501
 *****************************************************************************/
 /*!
 * \brief         Sets OBD Readiness Group completion state in PID Format.
 *
 * \details       Sets bit corresponding to readiness group in given variable
 *                to completed or not completed (PID Format).
 *                (0 = completed, 1 = not complete)
 *
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 * \param[in,out] DIDF501
 *                DID F501 formated data block
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Completion_SetReadinessGroupCompletedInDIDF501(
  uint8  ReadinessGroup,
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) DIDF501
);

/* ****************************************************************************
 * Dem_Readiness_Completion_ResetFullReadinessGroupUpdateFlag
 *****************************************************************************/
 /*!
 * \brief         Reset the update flag for Readiness Completion Calculation.
 *
 * \details       Set the update flag for Readiness Completion Calculation,
 *                and return the previous value.
 *
 * \return        Update flag values before the reset
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(uint32, DEM_CODE)
Dem_Readiness_Completion_ResetFullReadinessGroupUpdateFlag(
  void
);

/* ****************************************************************************
 * Dem_Readiness_Completion_GetAlwaysCompletedMaskByteB
 *****************************************************************************/
 /*!
 * \brief         Get the always completed Mask for Byte B.
 *
 * \details       Get the always completed Mask for Byte B.
 *
 * \param[in]     PIDContext
 *                Indicates if the function is invoked for processing PID 0x01
 *                or PIDF501 or PID 0x41.

 * \return        The always completed Mask for Byte B.
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_Readiness_Completion_GetAlwaysCompletedMaskByteB(
  uint8  PIDContext
);

/* ********************************************************************************************************************
 *  UNIT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/


 /* ****************************************************************************
 % Dem_Readiness_Completion_SetReadinessGroupCompletedInDIDF501
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Completion_SetReadinessGroupCompletedInDIDF501(
  uint8  ReadinessGroup,
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) DIDF501
)
{
  uint8 lByteMask;
  uint8 lBytePos;

  Dem_Readiness_Support_GetMaskAndBytePosDIDF501Format(ReadinessGroup, &lByteMask, &lBytePos);                                   /* SBSW_DEM_POINTER_FORWARD_STACK */

  lByteMask = (uint8)((uint8)lByteMask << 4u); /* Not Completed Bits of a Readiness Group in F501 Format are always 4 bits to the left, of the supported bit*/

  if (lByteMask != 0u)
  {
    Dem_GlobalDiagnostics_Readiness_SetByteInPIDF501Format(DIDF501, DIDF501[lBytePos] & ((uint8)~lByteMask), lBytePos);                   /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  }
}

/* ****************************************************************************
 % Dem_Readiness_Completion_ResetFullReadinessGroupUpdateFlag
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL FUNC(uint32, DEM_CODE)
Dem_Readiness_Completion_ResetFullReadinessGroupUpdateFlag(
  void
)
{
#if (DEM_FEATURE_NEED_READINESS_CALCULATION  == STD_ON)
  uint32 lOldValue;
  uint32 lNewValue;

  do
  {
    lOldValue = Dem_Completion_UpdateFlag;
    lNewValue = 0u;
  } while (Dem_Com_SyncCompareAndSwap(&Dem_Completion_UpdateFlag, lOldValue, lNewValue) == FALSE);                               /* SBSW_DEM_CALL_SYNC_COMPARE_AND_SWAP */

  /* Old value always contains the value before it was cleared */
  return lOldValue;
#else
  return 0u;
#endif
}


/* ****************************************************************************
 % Dem_Readiness_Completion_GetAlwaysCompletedMaskByteB
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_Readiness_Completion_GetAlwaysCompletedMaskByteB(                                                                            /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  uint8  PIDContext
)
{
  uint8 lReturnValue = 0u;
#if (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON)
  if ( PIDContext == DEM_COMPLETION_PIDCONTEXT_PID01 )
  {
    lReturnValue = (uint8)Dem_Cfg_GetGlobalPID01AlwaysCompletedMaskByteB();
  }
  else
  if ( PIDContext == DEM_COMPLETION_PIDCONTEXT_PID41)
  {
    lReturnValue = (uint8)Dem_Cfg_GetGlobalPID41AlwaysCompletedMaskByteB();
  }
  else
  if ( PIDContext == DEM_COMPLETION_PIDCONTEXT_PIDF501)                                                                          /* COV_DEM_MISRA_BRANCH */
  {
    lReturnValue = (uint8)Dem_Cfg_GetGlobalPIDF501AlwaysCompletedMaskByteB();
  }
  else
  {
    /* MISRA */
  }
#endif
  DEM_IGNORE_UNUSED_ARGUMENT(PIDContext)                                                                                         /* PRQA S 1338, 3112 */ /* MD_MSR_DummyStmt, MD_DEM_14.2 */

  return lReturnValue;
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  UNIT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_Completion_Public
 * \{
 */

 /* ****************************************************************************
 %  Dem_Readiness_Completion_CalculateCompletionMainFunction
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
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Completion_CalculateCompletionMainFunction(
  void
)
{
  if ((Dem_Cfg_IsObdSupportedInVariant() == TRUE) && (Dem_GlobalDiagnostics_Readiness_IsReadinessCalculationSupported() == TRUE))
  {
    uint32 lReadinessUpdateFlag;
    
    /* Get and reset all update flags for every readiness group to recalculate monitor completion state*/
    lReadinessUpdateFlag = Dem_Readiness_Completion_ResetFullReadinessGroupUpdateFlag();
    
    /* If a flag of a readiness group is set  */
    if (lReadinessUpdateFlag != 0u)
    {
      Dem_EventIdType lEventId;
      uint8 lReadinessGroupIter;

      /* Iterate over all primary events */
      for (lEventId = Dem_MemState_MemoryGetFirstEvent(DEM_CFG_MEMORYID_PRIMARY);
           lEventId <= Dem_MemState_MemoryGetLastEvent(DEM_CFG_MEMORYID_PRIMARY);
           lEventId++)
      {
        uint8 lReadinessGroup;

        /* If all flags are reset stop iterating events */
        if (lReadinessUpdateFlag == 0u)
        {
          break;
        }

        lReadinessGroup = Dem_Cfg_EventReadinessGroup(lEventId);

        /* If flag for event readiness group is not set continue with next event*/
        if (Dem_Readiness_Completion_GetReadinessGroupUpdateFlag(lReadinessUpdateFlag, lReadinessGroup) == FALSE)
        {
          continue;
        }

        if (Dem_Readiness_Completion_TestStaticallyCalculatedCompletionStates(lReadinessGroup, DEM_COMPLETION_PIDCONTEXT_PID01_AND_PIDF501) == TRUE)
        {
          /* Reset flag for this group and continue with next event  */
          lReadinessUpdateFlag = Dem_Readiness_Completion_ResetReadinessGroupUpdateFlag(lReadinessUpdateFlag, lReadinessGroup);
          continue;
        }

        /* If event readiness group is already completed  */
        if (Dem_Readiness_Completion_TestReadinessGroupCompleted(lReadinessGroup) == TRUE)
        {
          /* Reset flag for this group and continue with next event  */
          lReadinessUpdateFlag = Dem_Readiness_Completion_ResetReadinessGroupUpdateFlag(lReadinessUpdateFlag, lReadinessGroup);
          continue;
        }

        /* If event is available */
        if (Dem_Event_TestEventUnavailable(lEventId) == FALSE)
        {
          Dem_UDSStatus_Type lEventStatus;
          Dem_DTC_ExtendedStatusType lExtStatus;
          lEventStatus = Dem_Event_GetUDSStatus(lEventId);
          lExtStatus = Dem_Event_GetExtendedStatus(lEventId);

          /* If event is pending or event was not tested passed since last clear */
          if ((Dem_Event_ExtendedStatus_GetTPSLC(lExtStatus) == FALSE)
            || (Dem_UDSStatus_Test_PDTC(lEventStatus) == TRUE))
          {
            /* Reset flag of this readiness group  */
            lReadinessUpdateFlag = Dem_Readiness_Completion_ResetReadinessGroupUpdateFlag(lReadinessUpdateFlag, lReadinessGroup);
          }
        }
      }

      /* Start with first OBD readiness group */
      lReadinessGroupIter = 1U;

      /* For all flags that are still set change the related readiness group state to completed.
      Second loop exit criteria required to break out of loop in case statically calculated
      readiness groups with no referenced events are indicated in Dem_Completion_UpdateFlag */
      while ((lReadinessUpdateFlag != 0u) && (lReadinessGroupIter < DEM_CFG_READINESS_GROUP_SIZE))
      {
        if ((Dem_Readiness_Completion_TestStaticallyCalculatedCompletionStates(lReadinessGroupIter, DEM_COMPLETION_PIDCONTEXT_PID01_AND_PIDF501) == FALSE)
          && (Dem_Readiness_Completion_GetReadinessGroupUpdateFlag(lReadinessUpdateFlag, lReadinessGroupIter) == TRUE))
        {
          Dem_Readiness_Completion_SetReadinessGroupCompleted(TRUE, lReadinessGroupIter);                                        /* SBSW_DEM_POINTER_FORWARD_GLOBAL */

          /* Reset flag of this readiness group  */
          lReadinessUpdateFlag = Dem_Readiness_Completion_ResetReadinessGroupUpdateFlag(lReadinessUpdateFlag, lReadinessGroupIter);
        }

        lReadinessGroupIter++;
      }
    }
  }
}                                                                                                                                /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_Readiness_Completion_CalculateCompletionOnTPSLC
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
 */
DEM_LOCAL FUNC(void, DEM_CODE) 
Dem_Readiness_Completion_CalculateCompletionOnTPSLC(
  uint8  ReadinessGroup
  )
{
  /* If readiness group is valid */
  if ( (ReadinessGroup != DEM_CFG_READINESS_NONE)
    && (Dem_Readiness_Completion_TestStaticallyCalculatedCompletionStates(ReadinessGroup, DEM_COMPLETION_PIDCONTEXT_PID01_AND_PIDF501) == FALSE))
  {
    /* If readiness group is not completed */
    if (Dem_Readiness_Completion_TestReadinessGroupCompleted(ReadinessGroup) == FALSE)
    {
      Dem_EventIdType lEventId;
      boolean lIsCompleted;
      
      lIsCompleted = TRUE;

      for (lEventId = Dem_MemState_MemoryGetFirstEvent(DEM_CFG_MEMORYID_PRIMARY);
           lEventId <= Dem_MemState_MemoryGetLastEvent(DEM_CFG_MEMORYID_PRIMARY);
           lEventId++)
      {
        uint8 lReadinessGroup;
        lReadinessGroup = Dem_Cfg_EventReadinessGroup(lEventId);
        /* If event is assigned to passed group */
        if (lReadinessGroup == ReadinessGroup)
        {
          /* If event is available */
          if (Dem_Event_TestEventUnavailable(lEventId) == FALSE)
          {
            Dem_UDSStatus_Type lEventStatus;
            Dem_DTC_ExtendedStatusType lExtStatus;
            lEventStatus = Dem_Event_GetUDSStatus(lEventId);
            lExtStatus = Dem_Event_GetExtendedStatus(lEventId);
            if ((Dem_Event_ExtendedStatus_GetTPSLC(lExtStatus) == FALSE)
              || (Dem_UDSStatus_Test_PDTC(lEventStatus) == TRUE))
            {
              /* Leave readiness group not completed */
              lIsCompleted = FALSE;
              break;
            }
          }
        }
      }

      /* Otherwise set readiness group to completed */
      if (lIsCompleted == TRUE)
      {
        Dem_Readiness_Completion_SetReadinessGroupCompleted(TRUE, ReadinessGroup);                                               /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
      }
    }
  }
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */



/* ****************************************************************************
 % Dem_Readiness_Completion_SetReadinessGroupUpdateFlag
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Completion_SetReadinessGroupUpdateFlag(
  uint8 ReadinessGroup
  )
{
#if (DEM_FEATURE_NEED_READINESS_CALCULATION == STD_ON)
  if (ReadinessGroup != DEM_CFG_READINESS_NONE)
  {
    Dem_Com_SyncSetBitInBitfield(&Dem_Completion_UpdateFlag, DEM_CFG_READINESS_GROUP_WORDSIZE, ReadinessGroup);                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
#endif
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ReadinessGroup)                                                                               /* PRQA S 3112 */ /* MD_DEM_14.2 */
}


/* ****************************************************************************
 % Dem_Readiness_Completion_ResetReadinessGroupUpdateFlag
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Readiness_Completion_ResetReadinessGroupUpdateFlag(
  uint32 State,
  uint8 ReadinessGroup
  )
{
  uint32 lReturnValue;
  lReturnValue = State;
  if (ReadinessGroup != DEM_CFG_READINESS_NONE)
  {
    lReturnValue &= ~((uint32)((uint32)1U << (uint32)ReadinessGroup));
  }
  return lReturnValue;
}


/* ****************************************************************************
 % Dem_Readiness_Completion_GetReadinessGroupUpdateFlag
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Readiness_Completion_GetReadinessGroupUpdateFlag(
  uint32 State,
  uint8 ReadinessGroup
  )
{
  boolean lReturnValue;
  lReturnValue = FALSE;
  if (ReadinessGroup != DEM_CFG_READINESS_NONE)
  {
    if ((State & (uint32)((uint32)1u << (ReadinessGroup))) != 0u)
    {
      lReturnValue = TRUE;
    }
  }
  return lReturnValue;
}



/* ****************************************************************************
 % Dem_Readiness_Completion_SetReadinessGroupCompleted
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Completion_SetReadinessGroupCompleted(
  boolean Completed,
  uint8 ReadinessGroup
)
{
  uint8 lReadinessGroup;
  lReadinessGroup = ReadinessGroup;
 
  if (lReadinessGroup != DEM_CFG_READINESS_NONE)
  {
#if (DEM_FEATURE_NEED_READINESS_CALCULATION == STD_ON)
    if (Completed == TRUE)
    {
      Dem_Com_SetBitInBitfield(&Dem_Cfg_StatusData.ReadinessGroupCompletedStates, DEM_CFG_READINESS_GROUP_WORDSIZE, ReadinessGroup);  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    else
    {
      Dem_Com_ResetBitInBitfield(&Dem_Cfg_StatusData.ReadinessGroupCompletedStates, DEM_CFG_READINESS_GROUP_WORDSIZE, ReadinessGroup); /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
#endif
  }
  DEM_IGNORE_UNUSED_ARGUMENT(Completed)                                                                                          /* PRQA S 1338, 3112 */ /* MD_MSR_DummyStmt, MD_DEM_14.2 */
}


/* ****************************************************************************
 % Dem_Readiness_Completion_TestReadinessGroupCompleted
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Readiness_Completion_TestReadinessGroupCompleted(
  uint8 ReadinessGroup
)
{
  boolean lReturnValue;
#if (DEM_FEATURE_NEED_READINESS_CALCULATION == STD_ON)
  lReturnValue = Dem_Com_TestBitInBitfield(&Dem_Cfg_StatusData.ReadinessGroupCompletedStates, DEM_CFG_READINESS_GROUP_WORDSIZE, ReadinessGroup); /* SBSW_DEM_POINTER_FORWARD_STACK */
#else
  DEM_IGNORE_UNUSED_ARGUMENT(ReadinessGroup)                                                                                     /* PRQA S 1338, 3112 */ /* MD_MSR_DummyStmt, MD_DEM_14.2 */
  lReturnValue = FALSE;
#endif
  return lReturnValue;
}                                                                                                                                /* PRQA S 6030 */ /* MD_MSR_STCYC */

/* ****************************************************************************
 % Dem_Readiness_Completion_SetReadinessGroupCompletedInPidFormat
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
Dem_Readiness_Completion_SetReadinessGroupCompletedInPidFormat(
  boolean Completed,
  uint8  ReadinessGroup,
  CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC) PidResult
)
{
  uint8 lReadinessGroup;
  uint32 lPidCompletionState;

  lReadinessGroup = ReadinessGroup;
  lPidCompletionState = DEM_READINESS_SUPPORT_NONE_MASK;

  switch (lReadinessGroup)
  {
  case DEM_CFG_READINESS_MISF:
    lPidCompletionState = DEM_READINESS_COMPLETE_MISF_MASK;
    break;
  case DEM_CFG_READINESS_FLSYS:
  case DEM_CFG_READINESS_FLSYS_NONCONT:
    lPidCompletionState = DEM_READINESS_COMPLETE_FLSYS_MASK;
    break;
  case DEM_CFG_READINESS_CMPRCMPT:
    lPidCompletionState = DEM_READINESS_COMPLETE_CMPRCMPT;
    break;
  case DEM_CFG_READINESS_CAT:
    lPidCompletionState = DEM_READINESS_COMPLETE_CAT_MASK;
    break;
  case DEM_CFG_READINESS_HCCAT:
    lPidCompletionState = DEM_READINESS_COMPLETE_HCCAT_MASK;
    break;
  case DEM_CFG_READINESS_HTCAT:
    lPidCompletionState = DEM_READINESS_COMPLETE_HTCAT_MASK;
    break;
  case DEM_CFG_READINESS_NOXCAT:
    lPidCompletionState = DEM_READINESS_COMPLETE_NOXCAT_MASK;
    break;
  case DEM_CFG_READINESS_EVAP:
    lPidCompletionState = DEM_READINESS_COMPLETE_EVAP_MASK;
    break;
  case DEM_CFG_READINESS_SECAIR:
    lPidCompletionState = DEM_READINESS_COMPLETE_SECAIR_MASK;
    break;
  case DEM_CFG_READINESS_BOOSTPR:
    lPidCompletionState = DEM_READINESS_COMPLETE_BOOSTPR_MASK;
    break;
  case DEM_CFG_READINESS_O2SENS:
    lPidCompletionState = DEM_READINESS_COMPLETE_O2SENS_MASK;
    break;
  case DEM_CFG_READINESS_EGSENS:
    if (Dem_GlobalDiagnostics_Readiness_IsMotorTypeCompressionSupported() == TRUE)
    {
      lPidCompletionState = DEM_READINESS_COMPLETE_EGSENS_MASK;
    }
    else
    {
      lPidCompletionState = DEM_READINESS_SUPPORT_NONE_MASK;
      lReadinessGroup = DEM_CFG_READINESS_NONE;
    }
    break;
  case DEM_CFG_READINESS_O2SENSHT:
    lPidCompletionState = DEM_READINESS_COMPLETE_O2SENSHT_MASK;
    break;
  case DEM_CFG_READINESS_PMFLT:
    if (Dem_GlobalDiagnostics_Readiness_IsMotorTypeCompressionSupported() == TRUE)
    {
      lPidCompletionState = DEM_READINESS_COMPLETE_PMFLT_MASK;
    }
    else
    {
      lPidCompletionState = DEM_READINESS_SUPPORT_NONE_MASK;
      lReadinessGroup = DEM_CFG_READINESS_NONE;
    }
    break;
  case DEM_CFG_READINESS_EGR:
    lPidCompletionState = DEM_READINESS_COMPLETE_EGR_MASK;
    break;
  default:
    lReadinessGroup = DEM_CFG_READINESS_NONE;
    break;
  }

  if (lReadinessGroup != DEM_CFG_READINESS_NONE)
  {
    if (Completed == TRUE)
    {
      /* Negated output, since completion is represented by 0, not completion is represented by 1 */
      *PidResult &= (uint32) (~lPidCompletionState);                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    else
    {
      *PidResult |= lPidCompletionState;                                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}                                                                                                                                /* PRQA S 6030 */ /* MD_MSR_STCYC */



/* ****************************************************************************
 % Dem_Readiness_Completion_TestReadinessGroupCompletedInPidFormat
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Readiness_Completion_TestReadinessGroupCompletedInPidFormat(                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  uint8  ReadinessGroup,
  uint32  Pid01Data
)
{
  boolean lReturnValue;

  switch (ReadinessGroup)
  {
  case DEM_CFG_READINESS_MISF:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_MISF_MASK) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_FLSYS:
  case DEM_CFG_READINESS_FLSYS_NONCONT:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_FLSYS_MASK) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_CMPRCMPT:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_CMPRCMPT) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_CAT:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_CAT_MASK) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_HCCAT:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_HCCAT_MASK) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_HTCAT:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_HTCAT_MASK) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_NOXCAT:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_NOXCAT_MASK) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_EVAP:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_EVAP_MASK) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_SECAIR:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_SECAIR_MASK) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_BOOSTPR:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_BOOSTPR_MASK) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_O2SENS:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_O2SENS_MASK) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_EGSENS:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_EGSENS_MASK) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_O2SENSHT:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_O2SENSHT_MASK) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_PMFLT:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_PMFLT_MASK) == 0u) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_EGR:
    lReturnValue = (boolean)(((Pid01Data & DEM_READINESS_COMPLETE_EGR_MASK) == 0u) ? TRUE : FALSE);
    break;
  default:
    /* case DEM_CFG_READINESS_NONE: */
    lReturnValue = FALSE;
    break;
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030 */ /* MD_MSR_STCYC */


/* ****************************************************************************
 % Dem_Readiness_Completion_MapCompletedStatePID01
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Readiness_Completion_MapCompletedStatePID01(                                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  uint32 Pid01Data
  )
{
  uint32 lPid01Data;
  uint8 lReadinessGroup;
  lPid01Data = Pid01Data;

  for (lReadinessGroup = 1u; lReadinessGroup < DEM_CFG_READINESS_GROUP_SIZE; lReadinessGroup++)
  {
    if (Dem_Readiness_Completion_TestReadinessGroupCompleted(lReadinessGroup) == TRUE)
    {
      Dem_Readiness_Completion_SetReadinessGroupCompletedInPidFormat(TRUE, lReadinessGroup, &lPid01Data);                        /* SBSW_DEM_POINTER_FORWARD_STACK */
    }
  }

  /* Overwrite Completion Result with always completed staticall results */
  Dem_Readiness_Completion_SetStaticallyCalculatedCompletionStatesPID(&lPid01Data, DEM_COMPLETION_PIDCONTEXT_PID01); /* SBSW_DEM_POINTER_FORWARD_STACK */

  return lPid01Data;
}   



/* ****************************************************************************
 % Dem_Readiness_Completion_SetStaticallyCalculatedCompletionStatesPID
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
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Readiness_Completion_SetStaticallyCalculatedCompletionStatesPID(
  CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC) PidValue,                                                                             /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_8.13_fp */
  uint8  PIDContext
)
{
#if ((DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON))
  uint32 lStaticCompletionMask;
  lStaticCompletionMask = 0xFF00FFFFu | ((uint32)((uint32)Dem_Readiness_Completion_GetAlwaysCompletedMaskByteB(PIDContext) << 16u));
  *PidValue &= lStaticCompletionMask;                                                                                            /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
#else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(PidValue);                                                                                    /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_ARGUMENT(PIDContext)                                                                                         /* PRQA S 1338, 3112 */ /* MD_MSR_DummyStmt, MD_DEM_14.2 */
#endif
}


/* ****************************************************************************
 % Dem_Readiness_Completion_MapCompletedStateDIDF501
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Completion_MapCompletedStateDIDF501(                                                                               /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC)  DIDF501
)
{
  uint8 lReadinessGroup;
  for (lReadinessGroup = 1u; lReadinessGroup < DEM_CFG_READINESS_GROUP_SIZE; lReadinessGroup++)
  {
    if (Dem_Readiness_Completion_TestReadinessGroupCompleted(lReadinessGroup) == TRUE)
    {
      Dem_Readiness_Completion_SetReadinessGroupCompletedInDIDF501(lReadinessGroup, DIDF501);                                    /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
  }
  

  /* Overwrite Completion result with always completed, static results */
  Dem_Readiness_Completion_SetStaticallyCalculatedCompletionStatesDIDF501(DIDF501);                                              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
}


/* ****************************************************************************
 % Dem_Readiness_Completion_SetStaticallyCalculatedCompletionStatesDIDF501
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
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Readiness_Completion_SetStaticallyCalculatedCompletionStatesDIDF501(
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) DIDF501                                                                                /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_8.13_fp */
)
{
#if (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON)
  DIDF501[1] = DIDF501[1] & Dem_Readiness_Completion_GetAlwaysCompletedMaskByteB(DEM_COMPLETION_PIDCONTEXT_PIDF501);             /* SBSW_DEM_WRITE_PIDF501_BUFFER */
#else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DIDF501)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */
#endif
}



/* ****************************************************************************
 % Dem_Readiness_Completion_TestStaticallyCalculatedCompletionStates
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
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_Readiness_Completion_TestStaticallyCalculatedCompletionStates(
  uint8  ReadinessGroup,
  uint8  PIDContext
)
{
  boolean lRetVal;
  boolean lSparkEngineSupported;

  lSparkEngineSupported = (boolean)(DEM_CFG_SUPPORT_IGNITION_SPARK == STD_ON);

  if ((ReadinessGroup == DEM_CFG_READINESS_FLSYS)
    || ((ReadinessGroup == DEM_CFG_READINESS_CMPRCMPT) && (PIDContext == DEM_COMPLETION_PIDCONTEXT_PID01_AND_PIDF501)
# if (DEM_CFG_SUPPORT_OBDONUDS == STD_ON)
      && (Dem_Readiness_Completion_IsComprehensiveComponentCompletionDynamicallyCalculatedInDidF501() == FALSE)
# endif
      )
# if (DEM_CFG_PROCESS_PID41_COMPREHENSIVE_COMPLETE == STD_ON)
    || ((ReadinessGroup == DEM_CFG_READINESS_CMPRCMPT) && (PIDContext == DEM_COMPLETION_PIDCONTEXT_PID41))
# endif
    || ((lSparkEngineSupported == TRUE) && (ReadinessGroup == DEM_CFG_READINESS_MISF))
# if (DEM_CFG_PROCESS_COMPRESSION_MISFIRE_ALWAYS_COMPLETE == STD_ON)
    || ((lSparkEngineSupported == FALSE) && (ReadinessGroup == DEM_CFG_READINESS_MISF))
# endif
# if (DEM_CFG_PROCESS_FUELSYSTEM_ALWAYS_COMPLETE == STD_ON)
    || (ReadinessGroup == DEM_CFG_READINESS_FLSYS_NONCONT)
# endif
    )
  {
    lRetVal = TRUE;
  }
  else
  {
    lRetVal = FALSE;
  }

  return lRetVal;
}



/* ****************************************************************************
 % Dem_Readiness_Completion_ResetGlobalCompletionStates
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Readiness_Completion_ResetGlobalCompletionStates(
  void
)
{
#if (DEM_FEATURE_NEED_READINESS_CALCULATION == STD_ON)
  Dem_Cfg_StatusData.ReadinessGroupCompletedStates = 0u;
#endif
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_COMPLETION_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Completion_Implementation.h
 *********************************************************************************************************************/
