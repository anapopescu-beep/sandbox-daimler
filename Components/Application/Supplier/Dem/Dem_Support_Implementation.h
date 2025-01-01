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
/*! \addtogroup Dem_Support
 *  \{
 *  \file       Dem_Support_Implementation.h
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

#if !defined (DEM_SUPPORT_IMPLEMENTATION_H)
#define DEM_SUPPORT_IMPLEMENTATION_H

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
#include "Dem_Support_Interface.h"

                                                    /* Used unit API */
/* ------------------------------------------------------------------------- */
#include "Dem_FaultMemory_Interface.h"
#include "Dem_Infrastructure_Interface.h"
#include "Dem_FaultMemory_Interface.h"
#include "Dem_Core_Interface.h"
#include "Dem_ReadinessIF_Interface.h"
                                                   /* unit callbacks*/
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  UNIT CONSTANT MACROS
 *********************************************************************************************************************/

  /*! Filename declaration */
#define DEM_SUPPORT_IMPLEMENTATION_FILENAME "Dem_Support_Implementation.h"

 /* ********************************************************************************************************************
 *  UNIT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  UNIT DATA
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  UNIT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
 
/* ********************************************************************************************************************
 *  UNIT PRIVATE PROPERTIES DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_Support_PrivateProperties Private Properties
 * \{
 */

/* ********************************************************************************************************************
 *  UNIT PRIVATE PROPERTIES DEFINITIONS
 *********************************************************************************************************************/

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
 * \addtogroup Dem_Support_PublicProperties
 * \{
 */

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
 * \defgroup Dem_Support_Private Private Methods
 * \{
 */

 /* ****************************************************************************
 * Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01Obd
 *****************************************************************************/
 /*!
 * \brief         Get supported states for PID 01 Data Block and
 *                Confirmed DTC count.
 *
 * \details       Get supported states for PID 01 Data Block and
 *                Confirmed DTC count. For OBDII and OBD on UDS.
 *
 * \param[out]    ConfirmedEvents
 *                Number of OBD relevant DTC which are confirmed
 *                
 * \return        PID Formated Data Structure with supported bits and
 *                not completed bits set, for supported readiness groups
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01Obd(
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) ConfirmedEvents
);

/* ****************************************************************************
 * Dem_Readiness_Support_GetSupportedStateAndConfirmedCountDIDF501OBDonUDS
 *****************************************************************************/
/*!
 * \brief         Get supported states for PID F501 Data Block and
 *                Confirmed DTC count.
 *
 * \details       Get supported states for PID F501 Data Block and
 *                Confirmed DTC count. For OBD on UDS.
 *
 * \param[out]    ConfirmedEvents
 *                Number of OBD relevant DTC which are confirmed
 * \param[in,out] DIDF501
 *                DID F501 DataBlock
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Support_GetSupportedStateAndConfirmedCountDIDF501OBDonUDS(                                                         /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) ConfirmedEvents,
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) DIDF501
);

/* ****************************************************************************
 * Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01WwhObd
 *****************************************************************************/
/*!
 * \brief         Get supported states for PID 01 Data Block.
 *
 * \details       Get supported states for PID 01 Data Block.
 *                For WWHOBD.
 *
 * \param[out]    ConfirmedEvents
 *                Number of OBD relevant DTC which are confirmed
 *
 * \return        PID Formated Data Structure with supported bits and
 *                not completed bits set, for supported readiness groups
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01WwhObd(
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) ConfirmedEvents
);

/* ****************************************************************************
 * Dem_Readiness_Support_SetReadinessGroupSupportedAndNCInDIDF501
 *****************************************************************************/
/*!
 * \brief         Sets OBD Readiness Group to supported and not completed
 *
 * \details       Sets bit corresponding to readiness group in DID F501 Data Block
 *                (0 = not supported, 1= Supported)
 *
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 * \param[in,out] DIDF501
 *                DID F501 Data Block
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Support_SetReadinessGroupSupportedAndNCInDIDF501(
  uint8  ReadinessGroup,
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC)  DIDF501
);


/* ****************************************************************************
 * Dem_Readiness_Support_SetReadinessGroupSupportedAndNCInPIDFormat
 *****************************************************************************/
/*!
 * \brief         Sets OBD Readiness Group to supported and not completed
 *
 * \details       Sets bit corresponding to readiness group in PID Data Block
 *                (0 = not supported, 1= Supported)
 *
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 * \param[in,out] PIDSupportedStates
 *                PID Data Block
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Readiness_Support_SetReadinessGroupSupportedAndNCInPIDFormat(
  uint8  ReadinessGroup,
  CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC)  PIDSupportedStates
);


/* ********************************************************************************************************************
 *  UNIT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/

 /* ****************************************************************************
 % Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01Obd
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
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01Obd(                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) ConfirmedEvents
)
{
  Dem_Cfg_ProcessedCombinedDTCGroupType lProcessedCombinedDTCGroups;
  Dem_EventIdType lEventId;
  uint32 lSupportedStates;

  Dem_DTC_InitCombinedGroupProcessed(lProcessedCombinedDTCGroups);                                                               /* SBSW_DEM_POINTER_FORWARD_STACK */
  lSupportedStates = 0u;
  *ConfirmedEvents = 0u;                                                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */

  /* Scan for events in confirmed state */
  for (lEventId = Dem_MemState_MemoryGetFirstEvent(DEM_CFG_MEMORYID_PRIMARY);
       lEventId <= Dem_MemState_MemoryGetLastEvent(DEM_CFG_MEMORYID_PRIMARY);
       lEventId++)
  {
# if (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON && DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
    uint8 lReadinessGroup;
    lReadinessGroup = Dem_Cfg_EventReadinessGroup(lEventId);
    /* If event is available and assigned to a valid readiness group */
    if ((lReadinessGroup != DEM_CFG_READINESS_NONE)
      && (Dem_Event_TestEventUnavailable(lEventId) == FALSE))                                                                    /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
    {
        /* Set readiness group to supported*/
        Dem_Readiness_Support_SetReadinessGroupSupportedAndNCInPIDFormat(lReadinessGroup, &lSupportedStates);                      /* SBSW_DEM_POINTER_FORWARD_STACK */
    }
# endif
    { /* count Event if it is OBD related and confirmed bit is qualified */
      if ((Dem_Cfg_EventObdRelated(lEventId) == TRUE)
        && (lEventId == Dem_Cfg_GetMasterEvent(lEventId))
        && (Dem_DTC_TestCombinedGroupProcessed(Dem_Cfg_EventCombinedGroup(lEventId), lProcessedCombinedDTCGroups) == FALSE)      /* PRQA S 3415 */ /* MD_DEM_13.5_volatile */ /* SBSW_DEM_POINTER_FORWARD_STACK */
        )
      {
        uint8 lDtcStatus;
        lDtcStatus = Dem_DTC_GenerateExternalOnlyStatus(lEventId, Dem_DTC_GetDTCStatus(lEventId));
        if (Dem_UDSStatus_Test_CDTC(lDtcStatus) == TRUE)
        {
          (*ConfirmedEvents)++;                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        }
        Dem_DTC_SetCombinedGroupProcessed(Dem_Cfg_EventCombinedGroup(lEventId), lProcessedCombinedDTCGroups);                    /* SBSW_DEM_POINTER_FORWARD_STACK */
      }
    }
  }
  return lSupportedStates;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Readiness_Support_GetSupportedStateAndConfirmedCountDIDF501OBDonUDS
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
Dem_Readiness_Support_GetSupportedStateAndConfirmedCountDIDF501OBDonUDS(                                                         /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) ConfirmedEvents,
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) DIDF501                                                                                /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_8.13_fp */
)
{
  Dem_EventIdType lEventId;

  *ConfirmedEvents = 0u;                                                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DIDF501);                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */

  /* Scan for events in confirmed state */
  for (lEventId = Dem_MemState_MemoryGetFirstEvent(DEM_CFG_MEMORYID_PRIMARY);
       lEventId <= Dem_MemState_MemoryGetLastEvent(DEM_CFG_MEMORYID_PRIMARY);
       lEventId++)
  {
# if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON && (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON || DEM_CFG_PROCESS_PIDF501_COMPREHENSIVE_COMPLETE == STD_OFF))
    uint8 lReadinessGroup;
    lReadinessGroup = Dem_Cfg_EventReadinessGroup(lEventId);
    /* If event is available and assigned to a valid readiness group */
    if ((lReadinessGroup != DEM_CFG_READINESS_NONE)
      && (Dem_Event_TestEventUnavailable(lEventId) == FALSE))                                                                    /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
    {
      /* Set readiness group to supported*/
      Dem_Readiness_Support_SetReadinessGroupSupportedAndNCInDIDF501(lReadinessGroup, DIDF501);                                  /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
# endif
    { /* count Event if it is OBD related and confirmed bit is qualified */
      if ((Dem_Cfg_EventObdRelated(lEventId) == TRUE)
        && (lEventId == Dem_Cfg_GetMasterEvent(lEventId))
          )
      {
        uint8 lDtcStatus;
        lDtcStatus = Dem_DTC_GenerateExternalOnlyStatus(lEventId, Dem_DTC_GetDTCStatus(lEventId));
        if (Dem_UDSStatus_Test_CDTC(lDtcStatus) == TRUE)
        {
          (*ConfirmedEvents)++;                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        }
      }
    }
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01WwhObd
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
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01WwhObd(                                                             /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) ConfirmedEvents
)
{
  uint32 lSupportedStates;
  lSupportedStates = 0u;
  *ConfirmedEvents = 0u;                                                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */

  /* If major monitors and event availablity is supported */
#if (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON && DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
  {
    Dem_EventIdType lEventId;
    for (lEventId = Dem_MemState_MemoryGetFirstEvent(DEM_CFG_MEMORYID_PRIMARY); 
         lEventId <= Dem_MemState_MemoryGetLastEvent(DEM_CFG_MEMORYID_PRIMARY); 
         lEventId++)
    {
      uint8 lReadinessGroup;
      lReadinessGroup = Dem_Cfg_EventReadinessGroup(lEventId);
      /* If event is assigned to readiness group and available */
      if ((lReadinessGroup != DEM_CFG_READINESS_NONE)
        && (Dem_Event_TestEventUnavailable(lEventId) == FALSE)                                                                     /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
        )
      {
        /* Set readiness group to supported*/
        Dem_Readiness_Support_SetReadinessGroupSupportedAndNCInPIDFormat(Dem_Cfg_EventReadinessGroup(lEventId), &lSupportedStates); /* SBSW_DEM_POINTER_FORWARD_STACK */
      }
    }
  }
#endif
  return lSupportedStates;
}



/* ****************************************************************************
 % Dem_Readiness_Support_SetReadinessGroupSupportedAndNCInDIDF501
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Support_SetReadinessGroupSupportedAndNCInDIDF501(                                                                  /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  uint8  ReadinessGroup,
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC)  DIDF501
)
{
  uint8 lByteMask;
  uint8 lBytePos;

  Dem_Readiness_Support_GetMaskAndBytePosDIDF501Format(ReadinessGroup, &lByteMask, &lBytePos);                                   /* SBSW_DEM_POINTER_FORWARD_STACK */

  lByteMask = lByteMask | ((uint8)((uint8)lByteMask << 4u)); /* Not Completed Bits of a Readiness Group in F501 Format are always 4 bits to the left */


  Dem_GlobalDiagnostics_Readiness_SetByteInPIDF501Format(DIDF501, DIDF501[lBytePos] | lByteMask, lBytePos);                      /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
}


/* ****************************************************************************
 % Dem_Readiness_Support_SetReadinessGroupSupportedAndNCInPIDFormat
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Readiness_Support_SetReadinessGroupSupportedAndNCInPIDFormat(                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  uint8  ReadinessGroup,
  CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC)  PIDSupportedStates
)
{
  uint32 lPidSupportedMask;
  uint8 lReadinessGroup;
  lReadinessGroup = ReadinessGroup;

  switch (lReadinessGroup)
  {
  case DEM_CFG_READINESS_MISF:
    lPidSupportedMask = DEM_READINESS_SUPPORT_MISF_MASK | DEM_READINESS_COMPLETE_MISF_MASK;
    break;
  case DEM_CFG_READINESS_FLSYS:
  case DEM_CFG_READINESS_FLSYS_NONCONT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_FLSYS_MASK | DEM_READINESS_COMPLETE_FLSYS_MASK;
    break;
  case DEM_CFG_READINESS_CMPRCMPT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_CMPRCMPT_MASK | DEM_READINESS_COMPLETE_CMPRCMPT;
    break;
  case DEM_CFG_READINESS_CAT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_CAT_MASK | DEM_READINESS_COMPLETE_CAT_MASK;
    break;
  case DEM_CFG_READINESS_HCCAT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_HCCAT_MASK | DEM_READINESS_COMPLETE_HCCAT_MASK;
    break;
  case DEM_CFG_READINESS_HTCAT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_HTCAT_MASK | DEM_READINESS_COMPLETE_HTCAT_MASK;
    break;
  case DEM_CFG_READINESS_NOXCAT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_NOXCAT_MASK | DEM_READINESS_COMPLETE_NOXCAT_MASK;
    break;
  case DEM_CFG_READINESS_EVAP:
    lPidSupportedMask = DEM_READINESS_SUPPORT_EVAP_MASK | DEM_READINESS_COMPLETE_EVAP_MASK;
    break;
  case DEM_CFG_READINESS_SECAIR:
    lPidSupportedMask = DEM_READINESS_SUPPORT_SECAIR_MASK | DEM_READINESS_COMPLETE_SECAIR_MASK;
    break;
  case DEM_CFG_READINESS_BOOSTPR:
    lPidSupportedMask = DEM_READINESS_SUPPORT_BOOSTPR_MASK | DEM_READINESS_COMPLETE_BOOSTPR_MASK;
    break;
  case DEM_CFG_READINESS_O2SENS:
    lPidSupportedMask = DEM_READINESS_SUPPORT_O2SENS_MASK | DEM_READINESS_COMPLETE_O2SENS_MASK;
    break;
  case DEM_CFG_READINESS_EGSENS:
    if (Dem_GlobalDiagnostics_Readiness_IsMotorTypeCompressionSupported() == TRUE)
    {
      lPidSupportedMask = DEM_READINESS_SUPPORT_EGSENS_MASK | DEM_READINESS_COMPLETE_EGSENS_MASK;
    }
    else
    {
      lPidSupportedMask = DEM_READINESS_SUPPORT_NONE_MASK;
      lReadinessGroup = DEM_CFG_READINESS_NONE;
    }
    break;
  case DEM_CFG_READINESS_O2SENSHT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_O2SENSHT_MASK | DEM_READINESS_COMPLETE_O2SENSHT_MASK;
    break;
  case DEM_CFG_READINESS_PMFLT:
    if (Dem_GlobalDiagnostics_Readiness_IsMotorTypeCompressionSupported() == TRUE)
    {
      lPidSupportedMask = DEM_READINESS_SUPPORT_PMFLT_MASK | DEM_READINESS_COMPLETE_PMFLT_MASK;
    }
    else
    {
      lPidSupportedMask = DEM_READINESS_SUPPORT_NONE_MASK;
      lReadinessGroup = DEM_CFG_READINESS_NONE;
    }
    break;
  case DEM_CFG_READINESS_EGR:
    lPidSupportedMask = DEM_READINESS_SUPPORT_EGR_MASK | DEM_READINESS_COMPLETE_EGR_MASK;
    break;
  default:
    lPidSupportedMask = DEM_READINESS_SUPPORT_NONE_MASK;
    lReadinessGroup = DEM_CFG_READINESS_NONE;
    break;
  }

  if (lReadinessGroup != DEM_CFG_READINESS_NONE)
  {
    *PIDSupportedStates |= lPidSupportedMask;                                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
}                                                                                                                                /* PRQA S 6030 */ /* MD_MSR_STCYC */



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
 * \addtogroup Dem_Support_Public
 * \{
 */


 /* ****************************************************************************
 % Dem_Readiness_Support_SetReadinessGroupSupportedInPidFormat
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
Dem_Readiness_Support_SetReadinessGroupSupportedInPidFormat(                                                                     /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  boolean  Supported,
  uint8  ReadinessGroup,
  CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC)  PIDSupportedStates
)
{
  uint32 lPidSupportedMask;
  uint8 lReadinessGroup;
  lReadinessGroup = ReadinessGroup;

  switch (lReadinessGroup)
  {
  case DEM_CFG_READINESS_MISF:
    lPidSupportedMask = DEM_READINESS_SUPPORT_MISF_MASK;
    break;
  case DEM_CFG_READINESS_FLSYS:
  case DEM_CFG_READINESS_FLSYS_NONCONT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_FLSYS_MASK;
    break;
  case DEM_CFG_READINESS_CMPRCMPT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_CMPRCMPT_MASK;
    break;
  case DEM_CFG_READINESS_CAT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_CAT_MASK;
    break;
  case DEM_CFG_READINESS_HCCAT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_HCCAT_MASK;
    break;
  case DEM_CFG_READINESS_HTCAT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_HTCAT_MASK;
    break;
  case DEM_CFG_READINESS_NOXCAT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_NOXCAT_MASK;
    break;
  case DEM_CFG_READINESS_EVAP:
    lPidSupportedMask = DEM_READINESS_SUPPORT_EVAP_MASK;
    break;
  case DEM_CFG_READINESS_SECAIR:
    lPidSupportedMask = DEM_READINESS_SUPPORT_SECAIR_MASK;
    break;
  case DEM_CFG_READINESS_BOOSTPR:
    lPidSupportedMask = DEM_READINESS_SUPPORT_BOOSTPR_MASK;
    break;
  case DEM_CFG_READINESS_O2SENS:
    lPidSupportedMask = DEM_READINESS_SUPPORT_O2SENS_MASK;
    break;
  case DEM_CFG_READINESS_EGSENS:
    if (Dem_GlobalDiagnostics_Readiness_IsMotorTypeCompressionSupported() == TRUE)
    {
      lPidSupportedMask = DEM_READINESS_SUPPORT_EGSENS_MASK;
    }
    else
    {
      lPidSupportedMask = DEM_READINESS_SUPPORT_NONE_MASK;
      lReadinessGroup = DEM_CFG_READINESS_NONE;
    }
    break;
  case DEM_CFG_READINESS_O2SENSHT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_O2SENSHT_MASK;
    break;
  case DEM_CFG_READINESS_PMFLT:
    if (Dem_GlobalDiagnostics_Readiness_IsMotorTypeCompressionSupported() == TRUE)
    {
      lPidSupportedMask = DEM_READINESS_SUPPORT_PMFLT_MASK;
    }
    else
    {
      lPidSupportedMask = DEM_READINESS_SUPPORT_NONE_MASK;
      lReadinessGroup = DEM_CFG_READINESS_NONE;
    }
    break;
  case DEM_CFG_READINESS_EGR:
    lPidSupportedMask = DEM_READINESS_SUPPORT_EGR_MASK;
    break;
  default:
    lPidSupportedMask = DEM_READINESS_SUPPORT_NONE_MASK;
    lReadinessGroup = DEM_CFG_READINESS_NONE;
    break;
  }

  if (lReadinessGroup != DEM_CFG_READINESS_NONE)
  {
    if (Supported == TRUE)
    {
      *PIDSupportedStates |= lPidSupportedMask;                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    else
    {
      *PIDSupportedStates &= (uint32)(~lPidSupportedMask);                                                                       /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}                                                                                                                                /* PRQA S 6030 */ /* MD_MSR_STCYC */



/* ****************************************************************************
 % Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01
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
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01(                                                                   /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) ConfirmedEvents
)
{
  uint32 lSupportedStatesPIDFormat;
  lSupportedStatesPIDFormat = 0u;

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_OFF) && (DEM_CFG_SUPPORT_PID01 == STD_ON) && (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON)
  lSupportedStatesPIDFormat = ((uint32)((uint32)Dem_Cfg_GetGlobalPID01SupportedAndCompletedMaskByteB() << 16u))
                            | ((uint32)((uint32)Dem_Cfg_GetGlobalPID01SupportedAndCompletedMaskByteC() << 8u))
                            | ((uint32)((uint32)Dem_Cfg_GetGlobalPID01SupportedAndCompletedMaskByteD()));
    
#endif

  if (Dem_Cfg_IsObdIIOrObdOnUdsSupportedInVariant() == TRUE)
  {
    lSupportedStatesPIDFormat |= Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01Obd(ConfirmedEvents);              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  }
  else
  /* Otherwise if WWHOBD is supported */
  {
    lSupportedStatesPIDFormat |= Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01WwhObd(ConfirmedEvents);           /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  }

  return lSupportedStatesPIDFormat;
}     

/* ****************************************************************************
 % Dem_Readiness_Support_GetMaskAndBytePosDIDF501Format
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Support_GetMaskAndBytePosDIDF501Format(                                                                            /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  uint8  ReadinessGroup,
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC)  ByteMask,
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC)  BytePos
)
{

  switch (ReadinessGroup)
  {
  case DEM_CFG_READINESS_MISF:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_MISF_MASK;                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_MISF_BYTE;                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_FLSYS:
  case DEM_CFG_READINESS_FLSYS_NONCONT:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_FLSYS_MASK;                                                                        /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_FLSYS_BYTE;                                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_CMPRCMPT:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_CMPRCMPT_MASK;                                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_CMPRCMPT_BYTE;                                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_ECS:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_ECS_MASK;                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_ECS_BYTE;                                                                                   /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_CAT:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_CAT_MASK;                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_CAT_BYTE;                                                                                   /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_HCCAT:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_HCCAT_MASK;                                                                        /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_HCCAT_BYTE;                                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_HTCAT:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_HTCAT_MASK;                                                                        /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_HTCAT_BYTE;                                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_NOXCAT:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_NOXCAT_MASK;                                                                       /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_NOXCAT_BYTE;                                                                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_EVAP:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_EVAP_MASK;                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_EVAP_BYTE;                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_SECAIR:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_SECAIR_MASK;                                                                       /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_SECAIR_BYTE;                                                                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_BOOSTPR:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_BOOSTPR_MASK;                                                                      /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_BOOSTPR_BYTE;                                                                               /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_PMFLT:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_PMFLT_MASK;                                                                        /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_PMFLT_BYTE;                                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_EGSENS:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_EGSENS_MASK;                                                                       /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_EGSENS_BYTE;                                                                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_PCV:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_PCV_MASK;                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_PCV_BYTE;                                                                                   /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_EGR:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_EGR_MASK;                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_EGR_BYTE;                                                                                   /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_VVT:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_VVT_MASK;                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_VVT_BYTE;                                                                                   /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_DOR:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_DOR_MASK;                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_DOR_BYTE;                                                                                   /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_CSER:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_CSER_MASK;                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_CSER_BYTE;                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_NOXADSORB:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_NOXADSORB_MASK;                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_NOXADSORB_BYTE;                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  case DEM_CFG_READINESS_OTHER:
    *ByteMask = DEM_READINESS_DIDF501_SUPPORT_OTHER_MASK;                                                                        /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = DEM_READINESS_DIDF501_OTHER_BYTE;                                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  default:
    *ByteMask = 0u;                                                                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *BytePos = 0u;                                                                                                               /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    break;
  }
}                                                                                                                                /* PRQA S 6030 */ /* MD_MSR_STCYC */

/* ****************************************************************************
 % Dem_Readiness_Support_GetSupportedStateAndConfirmedCountDIDF501
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
Dem_Readiness_Support_GetSupportedStateAndConfirmedCountDIDF501(                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) ConfirmedEvents,
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) DIDF501
)
{
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_OFF) && (DEM_CFG_SUPPORT_OBDONUDS == STD_ON) && ((DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON) || (DEM_CFG_PROCESS_PIDF501_COMPREHENSIVE_COMPLETE == STD_OFF))
  DIDF501[1] = Dem_Cfg_GetGlobalDIDF501SupportedAndCompletedMaskByteB();                                                         /* SBSW_DEM_WRITE_PIDF501_BUFFER */
  DIDF501[2] = Dem_Cfg_GetGlobalDIDF501SupportedAndCompletedMaskByteC();                                                         /* SBSW_DEM_WRITE_PIDF501_BUFFER */
  DIDF501[3] = Dem_Cfg_GetGlobalDIDF501SupportedAndCompletedMaskByteD();                                                         /* SBSW_DEM_WRITE_PIDF501_BUFFER */
  DIDF501[4] = Dem_Cfg_GetGlobalDIDF501SupportedAndCompletedMaskByteE();                                                         /* SBSW_DEM_WRITE_PIDF501_BUFFER */
  DIDF501[5] = Dem_Cfg_GetGlobalDIDF501SupportedAndCompletedMaskByteF();                                                         /* SBSW_DEM_WRITE_PIDF501_BUFFER */
#else
  DIDF501[1] = 0x00u; /* not supported */                                                                                        /* SBSW_DEM_WRITE_PIDF501_BUFFER */
  DIDF501[2] = 0x00u; /* not supported */                                                                                        /* SBSW_DEM_WRITE_PIDF501_BUFFER */
  DIDF501[3] = 0x00u; /* not supported */                                                                                        /* SBSW_DEM_WRITE_PIDF501_BUFFER */
  DIDF501[4] = 0x00u; /* not supported */                                                                                        /* SBSW_DEM_WRITE_PIDF501_BUFFER */
  DIDF501[5] = 0x00u; /* not supported */                                                                                        /* SBSW_DEM_WRITE_PIDF501_BUFFER */
#endif

  Dem_Readiness_Support_GetSupportedStateAndConfirmedCountDIDF501OBDonUDS(ConfirmedEvents, DIDF501);                             /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
}

#if  (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON)
/* ****************************************************************************
 % Dem_Readiness_Support_GlobalPid41SupportedMask
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Readiness_Support_GlobalPid41SupportedMask(                                                                                  /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  void
)
{
  uint32 lSupportedStatesPIDFormat;
  lSupportedStatesPIDFormat = 0u;

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_OFF) && (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON)
  lSupportedStatesPIDFormat = (((uint32)Dem_Cfg_GetGlobalPID01SupportedAndCompletedMaskByteB() << 16u) & DEM_READINESS_SUPPORT_PID41_BYTE_B_MASK)
                            |  ((uint32)Dem_Cfg_GetGlobalPID01SupportedAndCompletedMaskByteC() << 8u);
#endif

  return lSupportedStatesPIDFormat;
}
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_SUPPORT_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Support_Implementation.h
 *********************************************************************************************************************/
