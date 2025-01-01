/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         FlexRay transceiver driver implementation
 *                 This file contains an example implementation for the TJA1080 transceiver
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *
 *  \par Note
 *  \verbatim
 *  Please note, that this file contains a collection of callback functions to be used with the Flash Bootloader.
 *  These functions may influence the behavior of the bootloader in principle.
 *  Therefore, great care must be taken to verify the correctness of the implementation.
 *
 *  The contents of the originally delivered files are only examples resp. implementation proposals.
 *  With regard to the fact that these functions are meant for demonstration purposes only, Vector Informatiks
 *  liability shall be expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *  \endverbatim
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Achim Strobelt                Ach           Vector Informatik GmbH
 *  Marco Riedl                   Rie           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  03.00.00   2015-05-28  Ach     -                Migrated component to ALM
 *  04.00.01   2016-11-22  Rie     -                Updated version number
 **********************************************************************************************************************/

#ifndef FRTRCV_H
#define FRTRCV_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "ComStack_Types.h"
#include "Fr_GeneralTypes.h"
#include "FrTrcv_Cfg.h"
#include "SchM_FrTrcv.h"

#if ( FRTRCV_PROD_ERROR_DETECT == STD_ON )
# include "Dem.h"
#endif

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#define FRTRCV_VERSION                     0x0105
#define FRTRCV_RELEASE_VERSION             0x00u

/***********************************************************************************************************************
 *  GLOBAL DEFINES
 **********************************************************************************************************************/

#define FrTrcv_EnterCritical() SchM_Enter_FrTrcv(FRTRCV_EXCLUSIVE_AREA_0)
#define FrTrcv_LeaveCritical() SchM_Exit_FrTrcv(FRTRCV_EXCLUSIVE_AREA_0)

#if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u )
  /* The channel handle can be optimized in single channel configurations. */
  /* Definition of channel parameter. */
# define FRTRCV_CHANNEL_SYSTEMTYPE_ONLY    void
# define FRTRCV_CHANNEL_SYSTEMTYPE_FIRST
# define FRTRCV_CHANNEL_IDX                0u
#else
  /* Definition of channel parameter. */
# define FRTRCV_CHANNEL_SYSTEMTYPE_ONLY    uint8 FrTrcv_TrcvIdx
# define FRTRCV_CHANNEL_SYSTEMTYPE_FIRST   uint8 FrTrcv_TrcvIdx,
# define FRTRCV_CHANNEL_IDX                FrTrcv_TrcvIdx
#endif

/* Development errors */
/* Definition of the API ID */
#define FRTRCV_TRCVINIT_SERVICE_ID                     0u
#define FRTRCV_SETTRANSCEIVERMODE_SERVICE_ID           1u
#define FRTRCV_GETTRANSCEIVERMODE_SERVICE_ID           5u
#define FRTRCV_GETTRANSCEIVERWUREASON_SERVICE_ID       6u
#define FRTRCV_GETVERSIONINFO_SERVICE_ID               7u
#define FRTRCV_GETTRANSCEIVERERROR_SERVICE_ID          8u
#define FRTRCV_DISABLETRANSCEIVERWAKEUP_SERVICE_ID    10u
#define FRTRCV_ENABLETRANSCEIVERWAKEUP_SERVICE_ID     11u
#define FRTRCV_CLEARTRANSCEIVERWAKEUP_SERVICE_ID      12u
#define FRTRCV_MAINFUNCTION_SERVICE_ID                13u
#define FRTRCV_CBK_WAKEUPBYTRANSCEIVER                14u
#define FRTRCV_DISABLETRANSCEIVERBRANCH_SERVICE_ID    15u
#define FRTRCV_ENABLETRANSCEIVERBRANCH_SERVICE_ID     16u

/* Definition of errors/exceptions */
#define FRTRCV_E_FR_INVALID_TRCVIDX                 0x01u
#define FRTRCV_E_FR_UNINIT                          0x10u
#define FRTRCV_E_FR_TRCV_NOT_STANDBY                0x11u
#define FRTRCV_E_FR_TRCV_NOT_NORMAL                 0x12u
#define FRTRCV_E_FR_TRCV_NOT_SLEEP                  0x13u
#define FRTRCV_E_FR_TRCV_NOT_RECEIVEONLY            0x14u
/* Additional development errors, not officially specified yet */
#define FRTRCV_E_FR_INVALID_POINTER                 0x20u
#define FRTRCV_E_FR_GENERATOR_COMPATIBILITY_ERROR   0x21u

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

#define FRTRCV_WAKEUP_NONE              (uint8)0u
#define FRTRCV_WAKEUP_POLLING           (uint8)1u
#define FRTRCV_WAKEUP_INTERRUPT         (uint8)2u

typedef uint8 FrTrcv_InitStatusType;
#define FRTRCV_UNINIT  (FrTrcv_InitStatusType)0u   /**< The FrTrcv is not initialized and is not usable. */
#define FRTRCV_INIT    (FrTrcv_InitStatusType)1u   /**< The FrTrcv is initialized and is usable. */

typedef struct
{
   FrTrcv_TrcvModeType    FrTrcv_BusLowPowerMode;          /**< The lowest allowed operation mode */
   FrTrcv_TrcvModeType    FrTrcv_InitState;                /**< The initial operation mode */
   EcuM_WakeupSourceType  FrTrcv_WakeupSourceRef;          /**< Wake Up Source Reference */
   uint8                  FrTrcv_WakeupByNodeUsedPolling;  /**< Is Wakeup detected by polling oder isr */
   uint8                  FrTrcv_ReadOutWS;                /**< Wait states used for status word read out */
} FrTrcv_GenConfigType;

/***********************************************************************************************************************
 *  PROTOTYPES OF EXPORT VARIABLES
 **********************************************************************************************************************/

/****************************************************************************/
/* Constants for export with unspecified size                               */
/****************************************************************************/
#if ( FRTRCV_MEM_MAPPING == STD_ON )
# define FRTRCV_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

extern CONST( uint8, FRTRCV_CONST ) FrTrcv_MaxNumOfBtrBusses;
extern CONST( FrTrcv_GenConfigType, FRTRCV_CONST ) FrTrcv_Config[MAX_NUM_OF_BTR_BUSSES];

#if ( FRTRCV_PROD_ERROR_DETECT == STD_ON )
extern CONST( Dem_EventIdType, FRTRCV_CONST ) FrTrcv_DEM_E_NoControl;
#endif

#if ( FRTRCV_MEM_MAPPING == STD_ON )
# define FRTRCV_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

/***********************************************************************************************************************
 *  PROTOTYPES OF EXPORT FUNCTIONS
 **********************************************************************************************************************/

#if ( FRTRCV_MEM_MAPPING == STD_ON )
# define FRTRCV_START_SEC_CODE
# include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

extern FUNC(void, FRTRCV_CODE) FrTrcv_InitMemory( void );
extern FUNC(void, FRTRCV_CODE) FrTrcv_TrcvInit(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY);
#if ( FRTRCV_MAIN_FUNCTION_CYCLE_TIME > 0 )
  extern FUNC(void, FRTRCV_CODE) FrTrcv_MainFunction( void );
#else
# define FrTrcv_MainFunction()
#endif
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_SetTransceiverMode(FRTRCV_CHANNEL_SYSTEMTYPE_FIRST FrTrcv_TrcvModeType FrTrcv_TrcvMode);
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_GetTransceiverMode(FRTRCV_CHANNEL_SYSTEMTYPE_FIRST P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRTRCV_APPL_DATA) FrTrcv_TrcvModePtr);
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_GetTransceiverWUReason(FRTRCV_CHANNEL_SYSTEMTYPE_FIRST P2VAR(FrTrcv_TrcvWUReasonType, AUTOMATIC, FRTRCV_APPL_DATA) FrTrcv_TrcvWUReasonPtr);
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_DisableTransceiverWakeup(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY);
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_EnableTransceiverWakeup(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY);
extern FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_ClearTransceiverWakeup(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY);

#if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u )
/* PRQA S 3453 7 *//* MISRA-C:2004 Rule 19.7 VIOLATION: A function could probably be used instead of this function-like macro. */
# define FrTrcv_TrcvInit(TrcvIdx)                                FrTrcv_TrcvInit()
# define FrTrcv_SetTransceiverMode(TrcvIdx, FrTrcv_TrcvMode)     FrTrcv_SetTransceiverMode(FrTrcv_TrcvMode)
# define FrTrcv_GetTransceiverMode(TrcvIdx, FrTrcv_TrcvModePtr)  FrTrcv_GetTransceiverMode(FrTrcv_TrcvModePtr)
# define FrTrcv_GetTransceiverWUReason(TrcvIdx, FrTrcv_TrcvWUReasonPtr) FrTrcv_GetTransceiverWUReason(FrTrcv_TrcvWUReasonPtr)
# define FrTrcv_DisableTransceiverWakeup(TrcvIdx)                FrTrcv_DisableTransceiverWakeup()
# define FrTrcv_EnableTransceiverWakeup(TrcvIdx)                 FrTrcv_EnableTransceiverWakeup()
# define FrTrcv_ClearTransceiverWakeup(TrcvIdx)                  FrTrcv_ClearTransceiverWakeup()
#endif /* #if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u ) */

#if ( FRTRCV_MEM_MAPPING == STD_ON )
# define FRTRCV_STOP_SEC_CODE
# include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

#endif /* FRTRCV_H */

/***********************************************************************************************************************
 *  END OF FILE: FRTRCV.H
 **********************************************************************************************************************/
