/**********************************************************************************************************************
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
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!       \file   StbM_Cbk.h
 *        \unit   LocalTime
 *        \unit   TimeNotification
 *        \brief  Vector AUTOSAR StbM callback header file
 *
 *      \details  This header file contains the callback function declarations of the Vector AUTOSAR module StbM.

 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (STBM_CBK_H)
# define STBM_CBK_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "StbM_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# ifndef STBM_USE_SYNCHRONIZED_LOCAL_CLOCK
#  define STBM_USE_SYNCHRONIZED_LOCAL_CLOCK            (STD_OFF)
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
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
# define STBM_START_SEC_CODE
# include "StbM_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

# if (STBM_CONFIG_TIME_NOTIFICATION == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimerCallback
 *********************************************************************************************************************/
/*! \brief       Notifies the StbM, that the GPT timer, which is used to trigger the StbM_TimeNotificationCallback, has expired.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      STBM_CONFIG_TIME_NOTIFICATION
 *********************************************************************************************************************/
FUNC(void, STBM_CODE) StbM_TimerCallback(void);
# endif /* (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) */

# if (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON)
/**********************************************************************************************************************
*  StbM_LocalClockSyncCallback
*********************************************************************************************************************/
/*! \brief      Hook function for synchronization of local clock
*  \details     This function allows the customers to synchronize the local clock.
*  \param[in]   timeBaseId              The synchronized time-base, whose local clock could be synchronized.
*  \param[in]   ethIfCtrlIdx            Index of the ethernet controller used as local clock.
*  \param[in]   globalTimeSyncPtr       Global time sync.
*  \param[in]   localTimeSyncPtr        Virtual local time sync.
*  \param[in]   rateDeviation           Current rate deviation.
*  \param[in]   timeLeap                Current time leap.
*  \param[in]   updateCounter           Current update counter.
*  \return      type of clock adjustment (major|minor|none).
*  \pre         -
*  \context     TASK|ISR2
*  \reentrant   FALSE
*  \synchronous TRUE
*********************************************************************************************************************/
FUNC(uint8, STBM_CODE) StbM_LocalClockSyncCallback(
        StbM_SynchronizedTimeBaseType timeBaseId,
        uint8 ethIfCtrlIdx,
        P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) globalTimeSyncPtr,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) localTimeSyncPtr,
        StbM_RateDeviationType rateDeviation,
        StbM_TimeDiffType timeLeap,
        uint8 updateCounter);
# endif /* (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON) */

# define STBM_STOP_SEC_CODE
# include "StbM_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* STBM_CBK_H */

/**********************************************************************************************************************
 *  END OF FILE: StbM_Cbk.h
 *********************************************************************************************************************/
