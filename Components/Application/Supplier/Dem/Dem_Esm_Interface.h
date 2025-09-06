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
 *  \defgroup   Dem_Esm Event State Manager
 *  \{
 *  \file       Dem_Esm_Interface.h
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

#if !defined (DEM_ESM_INTERFACE_H)
#define DEM_ESM_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Esm_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \defgroup Dem_Esm_Public Public Methods
 * \{
 */

/* ****************************************************************************
 * Dem_Util_SeverityWwhObdDtcClass
 *****************************************************************************/
/*!
 * \brief         Maps the given severity to the WWH-OBD DTC Class
 *
 * \details       This function maps the given severity to the WWH-OBD DTC
 *                Class
 *                DEM_SEVERITY_WWHOBD_CLASS_NO_CLASS -> 0x00
 *                DEM_SEVERITY_WWHOBD_CLASS_C        -> 0x01
 *                DEM_SEVERITY_WWHOBD_CLASS_B2       -> 0x02
 *                DEM_SEVERITY_WWHOBD_CLASS_B1       -> 0x03
 *                DEM_SEVERITY_WWHOBD_CLASS_A        -> 0x04
 *
 * \param[in]     Severity
 *                The severity byte
 *
 * \return        The WWH-OBD DTC Class
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Util_SeverityWwhObdDtcClass(
  CONST(Dem_DTCSeverityType, AUTOMATIC)  Severity
  );

#if (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) || (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON)
/* ****************************************************************************
 * Dem_Util_J1939OccurrenceCounter
 *****************************************************************************/
/*!
 * \brief         Gets an event's occurrence counter for J1939 reporting.
 *
 * \details       Gets an event's occurrence counter for J1939 reporting
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        Occurrence counter value in J1939 format
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON ||
 *                DEM_CFG_SUPPORT_J1939_DM31 == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Util_J1939OccurrenceCounter(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON)
/* ****************************************************************************
 * Dem_Util_SetReadinessGroupDisabled
 *****************************************************************************/
/*!
 * \brief         Disable OBD Readiness Group
 *
 * \details       Sets bit corresponding to readiness group Pid41DisabledMask
 *                (0 = enabled, 1= disabled)
 *
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Util_SetReadinessGroupDisabled(
  CONST(uint8, AUTOMATIC)  ReadinessGroup
  );
#endif

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/* ****************************************************************************
 * Dem_Esm_AddAgingTime
 *****************************************************************************/
/*!
 * \brief         Calculates target aging time
 *
 * \details       This function increments and wraps the timer value avoiding
 *                overflow and 'magic numbers'.
 *
 * \param[in]     CurrentTime
 *                Current value of the aging timer
 * \param[in]     DeltaValue
 *                Value by which CurrentTime is incremented.
 *
 * \return        Value of (CurrentTime + DeltaValue) mod X
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Esm_AddAgingTime(
  CONST(uint32, AUTOMATIC)  CurrentTime,
  CONST(uint16, AUTOMATIC)  DeltaValue
  );
#endif




#if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_RESTART_DCY_ON_CLEAR_DTC == STD_ON)
/* ****************************************************************************
 * Dem_Esm_PreOnClear_AllDtc
 *****************************************************************************/
/*!
 * \brief         Restarts the DCY before Clear DTC is processed
 *
 * \details       This function is called before ClearAllDTC is processed.
 *
 * \param[in]     MemoryId
 *                Unique identifier of the event memory
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OBD == STD_ON &&
 *                DEM_CFG_SUPPORT_RESTART_DCY_ON_CLEAR_DTC == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_PreOnClear_AllDtc(
  CONST(uint16, AUTOMATIC)  MemoryId
  );
#endif

/* ****************************************************************************
 * Dem_Esm_PostOnClear_AllDtc
 *****************************************************************************/
/*!
 * \brief         Clears global statistics after Clear DTC was processed
 *
 * \details       This function is called when ClearAllDTC was finished.
 *                It clears all global statistic data which is cleared only
 *                on ClearAllDTC requests.
 *
 * \param[in]     MemoryId
 *                Unique identifier of the event memory
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_PostOnClear_AllDtc(
  CONST(uint16, AUTOMATIC)  MemoryId
  );

/* ****************************************************************************
 * Dem_Esm_PostOnClear_Always
 *****************************************************************************/
/*!
 * \brief         Clears global OBD statistics after Clear DTC was processed
 *
 * \details       This function is called after a ClearDTC request was processed.
 *                It clears all global statistic data which is cleared with
 *                all clear requests.
 *
 * \param[in]     MemoryId
 *                Unique identifier of the event memory
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_PostOnClear_Always(
  CONST(uint16, AUTOMATIC)  MemoryId
  );




/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* DEM_ESM_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Esm_Interface.h
 *********************************************************************************************************************/
