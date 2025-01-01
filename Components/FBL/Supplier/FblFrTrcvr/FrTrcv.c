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

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* FlexRay transceiver driver declarations */
#include "FrTrcv.h"
#include "FrTrcv_Cbk.h"
#include "fbl_inc.h"

#if ( FRTRCV_DEV_ERROR_DETECT == STD_ON )
# include "Det.h"
#endif

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* Check consistency of source and header file. */
#if ( FRTRCV_VERSION != 0x0105u ) || \
    ( FRTRCV_RELEASE_VERSION != 0x00u )
# error "Error in FRTRCV.C: Source and header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if !defined( STATIC )
# define STATIC static
#endif

/***********************************************************************************************************************
 *  MACROS
 **********************************************************************************************************************/

#if ( FRTRCV_DEV_ERROR_DETECT == STD_ON )

/* If DET is enabled, a MISRA-C:2004 analysis will yield deviations to the rules:
*  - 14.3 Before preprocessing, a null statement shall only occur on a line by itself; it may be followed by a comment provided that the first character following the null statement is a white-space character.
*  - 14.7 A function shall have a single point of exit at the end of the function
*  - 19.4 C macros shall only expand to a braced initializer, a constant, a parenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct
*  - 19.7 A function should be used in preference to a function-like macro.
*  These deviations are caused by design of the runtime/ressource optimized DET handling and are globally justified.
*/

# define FrTrcv_CheckDetErrorReturnVoid(  CONDITION, INSTANCE_ID, API_ID, ERROR_CODE )           { if (!(CONDITION)) { Det_ReportError( FRTRCV_MODULE_ID, (INSTANCE_ID), (API_ID), (ERROR_CODE)); return; } } /* PRQA S 3458 */   /* MD_MSR_19.4 */
# define FrTrcv_CheckDetErrorReturnValue( CONDITION, INSTANCE_ID, API_ID, ERROR_CODE, RET_VAL )  { if (!(CONDITION)) { Det_ReportError( FRTRCV_MODULE_ID, (INSTANCE_ID), (API_ID), (ERROR_CODE)); return (RET_VAL); } } /* PRQA S 3458 */   /* MD_MSR_19.4 */
# define FrTrcv_CallDetReportError( API_ID, ERROR_CODE )                            Det_ReportError( FRTRCV_MODULE_ID, 0, (API_ID), (ERROR_CODE))
#else
# define FrTrcv_CheckDetErrorReturnVoid(  CONDITION, INSTANCE_ID, API_ID, ERROR_CODE )
# define FrTrcv_CheckDetErrorReturnValue( CONDITION, INSTANCE_ID, API_ID, ERROR_CODE, RET_VAL )
# define FrTrcv_CallDetReportError( API_ID, ERROR_CODE )
#endif

#if ( FRTRCV_PROD_ERROR_DETECT == STD_ON )
  /* PRQA S 3453 1 *//* MISRA-C:2004 Rule 19.7 VIOLATION: A function could probably be used instead of this function like macro */
# define FrTrcv_DemReportError(eventId) ((void)Dem_ReportErrorStatus((Dem_EventIdType)(eventId), (uint8)(DEM_EVENT_STATUS_FAILED)))
#else
# define FrTrcv_DemReportError(eventId)
#endif

/***********************************************************************************************************************
 *  TYPEDEFS AND STRUCTS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  DATA DEFINITIONS
 **********************************************************************************************************************/

/******************************************************************************/
/* Local Data definitions with unspecified size                               */
/******************************************************************************/
#if ( FRTRCV_MEM_MAPPING == STD_ON )
# define FRTRCV_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

STATIC VAR( FrTrcv_TrcvWUReasonType, FRTRCV_VAR_NOINIT ) FrTrcv_TrcvWUReason[MAX_NUM_OF_BTR_BUSSES];
STATIC VAR( FrTrcv_InitStatusType, FRTRCV_VAR_NOINIT )   FrTrcv_IsInitialized[MAX_NUM_OF_BTR_BUSSES];

#if ( FRTRCV_MEM_MAPPING == STD_ON )
# define FRTRCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

#if ( FRTRCV_MEM_MAPPING == STD_ON )
# define FRTRCV_START_SEC_VAR_NOINIT_8BIT
# include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

STATIC VAR( uint8, FRTRCV_VAR_NOINIT ) FrTrcv_WakeupCbEnabled[MAX_NUM_OF_BTR_BUSSES];
STATIC VAR( uint8, FRTRCV_VAR_NOINIT ) FrTrcv_WakeupDetected[MAX_NUM_OF_BTR_BUSSES];

#if ( FRTRCV_MEM_MAPPING == STD_ON )
# define FRTRCV_STOP_SEC_VAR_NOINIT_8BIT
# include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

/***********************************************************************************************************************
 *  PROTOTYPES FOR LOCAL FUNCTIONS
 **********************************************************************************************************************/

STATIC FUNC(void, FRTRCV_CODE) FrTrcv_CheckWakeupEvent( FRTRCV_CHANNEL_SYSTEMTYPE_ONLY );

#if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u )
/* PRQA S 3453 1 *//* MISRA-C:2004 Rule 19.7 VIOLATION: A function could probably be used instead of this function-like macro. */
# define FrTrcv_CheckWakeupEvent(TrcvIdx)    FrTrcv_CheckWakeupEvent()
#endif /* #if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u ) */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#if ( FRTRCV_MEM_MAPPING == STD_ON )
# define FRTRCV_START_SEC_CODE
# include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

/***********************************************************************************************************************
 *  FrTrcv_CheckWakeupEvent
 **********************************************************************************************************************/
/*! \brief       Check for current and pending wakeup events
 *  \param[in]   FrTrcv_TrcvIdx The selected FlexRay bus transceiver
 **********************************************************************************************************************/
STATIC FUNC(void, FRTRCV_CODE) FrTrcv_CheckWakeupEvent( FRTRCV_CHANNEL_SYSTEMTYPE_ONLY )
{
   FrTrcv_StatusWordType kTrcvCurrentStatusWord;
   FrTrcv_TrcvModeType   FrTrcv_TrcvMode;
#if ( FRTRCV_TRCV_DIAGNOSIS == STD_ON )
   uint8_least i;
#endif

   /* Get new transceiver status flags */
   if ((BusTrcvErrorType)BUSTRCV_E_OK != ApplFblTrcvPhyReadStatusWord(FRTRCV_CHANNEL_IDX, &kTrcvCurrentStatusWord))
   {
      FrTrcv_DemReportError(FrTrcv_DEM_E_NoControl);
   }
   else
   {
#if ( FRTRCV_TRCV_DIAGNOSIS == STD_ON )
      i = FrTrcv_StatusMaskTableSize;
      while (i > 0u)
      {
         i--;
         if ((kTrcvCurrentStatusWord & FrTrcv_StatusMaskTable[i]) > (FrTrcv_StatusWordType)0u )
         {
            /* We detected an error, notify DEM */
            FrTrcv_DemReportError( FrTrcv_DEM_E_Table[i] );
         }
      }
#endif

      if ((BusTrcvErrorType)BUSTRCV_E_OK == ApplFblTrcvPhyGetMode(FRTRCV_CHANNEL_IDX, &FrTrcv_TrcvMode) )
      {
         /* Without diagnosis, only STANDBY and SLEEP is relevant for wakeup */
         if ((FRTRCV_TRCVMODE_STANDBY == FrTrcv_TrcvMode) || (FRTRCV_TRCVMODE_SLEEP == FrTrcv_TrcvMode) )
         {
            if ((kTrcvCurrentStatusWord & (FrTrcv_StatusWordType)FRTRCV_REMOTEWAKEUP) > (FrTrcv_StatusWordType)0u)
            {
               FrTrcv_TrcvWUReason[FRTRCV_CHANNEL_IDX] = FRTRCV_WU_BY_BUS;
               FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX] = (uint8)1u;
            }
            else if((kTrcvCurrentStatusWord & (FrTrcv_StatusWordType) FRTRCV_LOCALWAKEUP) > (FrTrcv_StatusWordType) 0u)
            {
               FrTrcv_TrcvWUReason[FRTRCV_CHANNEL_IDX] = FRTRCV_WU_INTERNALLY;
               FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX] = (uint8)1u;
            }
            else
            {
               /* Concluding else */
            }
         }
      }
   }

#if ( FRTRCV_WAKEUP_SUPPORT == STD_ON )
  if (((uint8)1u == FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX])
   && ((uint8)1u == FrTrcv_WakeupCbEnabled[FRTRCV_CHANNEL_IDX]) )
  { /* Wakeup callbacks enabled? */
     FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX] = (uint8)0u;
     EcuM_SetWakeupEvent(FrTrcv_Config[FRTRCV_CHANNEL_IDX].FrTrcv_WakeupSourceRef);
  }
#endif
}

/***********************************************************************************************************************
 *  FrTrcv_InitMemory
 **********************************************************************************************************************/
/*! \brief       Initialize static variables
 **********************************************************************************************************************/
FUNC(void, FRTRCV_CODE) FrTrcv_InitMemory( void )
{
   uint8_least kTrcvChannel;

   for(kTrcvChannel = (uint8_least)0u; kTrcvChannel < FrTrcv_MaxNumOfBtrBusses; kTrcvChannel++ )
   {
      FrTrcv_IsInitialized[kTrcvChannel] = FRTRCV_UNINIT;
   }
}

/***********************************************************************************************************************
 *  FrTrcv_TrcvInit
 **********************************************************************************************************************/
/*! \brief       Initialize the FlexRay Transceiver
 *  \param[in]   FrTrcv_TrcvIdx The selected FlexRay bus transceiver
 **********************************************************************************************************************/
FUNC(void, FRTRCV_CODE) FrTrcv_TrcvInit( FRTRCV_CHANNEL_SYSTEMTYPE_ONLY )
{
   uint8 i;
   i = FRTRCV_CHANNEL_IDX;
   FrTrcv_CheckDetErrorReturnVoid(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                                            FRTRCV_TRCVINIT_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX)
   {
      FrTrcv_IsInitialized[i] = FRTRCV_UNINIT;

#if !defined( V_SUPPRESS_EXTENDED_VERSION_CHECK )
   if (((FrTrcv_GeneratorVersion & 0x00FFFF00)!=
     (((uint32)DRVTRANS_TJA1080FRASR_GENTOOL_GENY_MAJOR_VERSION<<16) | ((uint32)DRVTRANS_TJA1080FRASR_GENTOOL_GENY_MINOR_VERSION<<8)))
# if defined( DRVTRANS_TJA1080FRASR_GENTOOL_GENY_PATCH_VERSION )
#  if ( DRVTRANS_TJA1080FRASR_GENTOOL_GENY_PATCH_VERSION != 0 )
     || ((FrTrcv_GeneratorVersion & (uint32)0x000000FF) < DRVTRANS_TJA1080FRASR_GENTOOL_GENY_PATCH_VERSION)
#  endif
# endif
     )
      {
# if ( FRTRCV_WAKEUP_SUPPORT == STD_ON )
         /* Ms: Call the Vector specific EcuM Error callback and do NOT Call Det_ReportError. */
         EcuM_GeneratorCompatibilityError((uint16) FRTRCV_MODULE_ID, (uint8) 0);
# else
         FrTrcv_CallDetReportError( FRTRCV_TRCVINIT_SERVICE_ID, FRTRCV_E_FR_GENERATOR_COMPATIBILITY_ERROR );
# endif
         return; /* Do not continue with the initialization of the component the Application may be influenced critically. */
      }
#endif

#if ( FRTRCV_CRC_CHECK == STD_ON )
      if (FrTrcv_PreCompileCRC32 != FRTRCV_PRECOMPILE_CRC32)
      {
# if ( FRTRCV_WAKEUP_SUPPORT == STD_ON )
         /* Ms: Call the Vector specific EcuM Error callback and do NOT Call Det_ReportError. */
         EcuM_GeneratorCompatibilityError((uint16) FRTRCV_MODULE_ID, (uint8) 0);
# else
         FrTrcv_CallDetReportError( FRTRCV_TRCVINIT_SERVICE_ID, FRTRCV_E_FR_GENERATOR_COMPATIBILITY_ERROR );
# endif
         return;
      }
#endif

      /* Initialize physical Transceiver, if required */
      ApplFblTrcvPhyTrcvInit(i);

      /* Set the transceiver to a default state */
      if ((BusTrcvErrorType)BUSTRCV_E_OK != ApplFblTrcvPhySetMode(i, FrTrcv_Config[i].FrTrcv_InitState) )
      {
         FrTrcv_DemReportError(FrTrcv_DEM_E_NoControl);
      }

      FrTrcv_WakeupDetected[i]  = (uint8)0u;
      FrTrcv_WakeupCbEnabled[i] = (uint8)0u;
      FrTrcv_TrcvWUReason[i] = FRTRCV_WU_NOT_SUPPORTED;
      if (FrTrcv_Config[i].FrTrcv_WakeupByNodeUsedPolling > FRTRCV_WAKEUP_NONE)
      {
         FrTrcv_WakeupCbEnabled[i] = (uint8)1u;
         FrTrcv_TrcvWUReason[i] = FRTRCV_WU_RESET;
         /* Check for pending wakeup events */
         FrTrcv_CheckWakeupEvent( i );
      }
      FrTrcv_IsInitialized[i] = FRTRCV_INIT;
   }
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

#if ( FRTRCV_MAIN_FUNCTION_CYCLE_TIME > 0 )

/***********************************************************************************************************************
 *  FrTrcv_MainFunction
 **********************************************************************************************************************/
/*! \brief       Cyclic task
 *  \param[in]   FrTrcv_TrcvIdx The selected FlexRay bus transceiver
 **********************************************************************************************************************/
FUNC(void, FRTRCV_CODE) FrTrcv_MainFunction( void )
{
   uint8 kTrcvChannel;

   for(kTrcvChannel = (uint8)0u; kTrcvChannel < FrTrcv_MaxNumOfBtrBusses; kTrcvChannel++ )
   {
      if (FRTRCV_INIT == FrTrcv_IsInitialized[kTrcvChannel] )
      {
         if (FRTRCV_WAKEUP_POLLING == FrTrcv_Config[kTrcvChannel].FrTrcv_WakeupByNodeUsedPolling )
         {
            /* Check for pending wakeup events */
            FrTrcv_CheckWakeupEvent(kTrcvChannel);
         }
      }
   }
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */
#endif

/***********************************************************************************************************************
 *  FrTrcv_SetTransceiverMode
 **********************************************************************************************************************/
/*! \brief       Changes the operation mode of the selected transceiver
 *  \param[in]   FrTrcv_TrcvIdx The selected FlexRay bus transceiver
 *  \param[in]   FrTrcv_TrcvModeType The Transceive mode that shall be set
 *  \return      FrTrcv_StatusType BUSTRCV_E_OK - Transceiver state change was successful
 *                                 BUSTRCV_E_ERROR -  Transceiver state change failed or parameter is out of range.
 *                                                    The previous state has not been changed.
 **********************************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_SetTransceiverMode(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY, FrTrcv_TrcvModeType FrTrcv_TrcvMode)
{
   BusTrcvErrorType result;

   FrTrcv_CheckDetErrorReturnValue(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                                   FRTRCV_SETTRANSCEIVERMODE_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX, (BusTrcvErrorType)BUSTRCV_E_ERROR)
   FrTrcv_CheckDetErrorReturnValue(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
                                   FRTRCV_SETTRANSCEIVERMODE_SERVICE_ID, FRTRCV_E_FR_UNINIT, (BusTrcvErrorType)BUSTRCV_E_ERROR)

  result = (BusTrcvErrorType)BUSTRCV_E_ERROR;
   if (FrTrcv_Config[FRTRCV_CHANNEL_IDX].FrTrcv_BusLowPowerMode >= FrTrcv_TrcvMode)
   {
      switch (FrTrcv_TrcvMode)
      {
        case FRTRCV_TRCVMODE_NORMAL :
        case FRTRCV_TRCVMODE_STANDBY :
        case FRTRCV_TRCVMODE_SLEEP :
        case FRTRCV_TRCVMODE_RECEIVEONLY :
        {
           result = ApplFblTrcvPhySetMode(FRTRCV_CHANNEL_IDX, FrTrcv_TrcvMode);
        }
           break;
        default:
        {
           return ((BusTrcvErrorType) BUSTRCV_E_ERROR);
        }
      }
   }

   if ((BusTrcvErrorType)BUSTRCV_E_OK != result )
   {
      FrTrcv_DemReportError(FrTrcv_DEM_E_NoControl);
   }
   return(result);
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

/***********************************************************************************************************************
 *  FrTrcv_GetTransceiverMode
 **********************************************************************************************************************/
/*! \brief       Reads the operation mode of the selected transceiver
 *  \param[in]   FrTrcv_TrcvIdx The selected FlexRay bus transceiver
 *  \return      FrTrcv_StatusType: BUSTRCV_E_OK - Transceiver state change was successful
 *                                  BUSTRCV_E_ERROR -  Transceiver state change failed or parameter is out of range.
 *                                                     The previous state has not been changed.
 **********************************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_GetTransceiverMode(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY, P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRTRCV_APPL_DATA) FrTrcv_TrcvModePtr)
{
   FrTrcv_CheckDetErrorReturnValue(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                                   FRTRCV_GETTRANSCEIVERMODE_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX, (BusTrcvErrorType)BUSTRCV_E_ERROR)
   FrTrcv_CheckDetErrorReturnValue(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
                                   FRTRCV_GETTRANSCEIVERMODE_SERVICE_ID, FRTRCV_E_FR_UNINIT, (BusTrcvErrorType)BUSTRCV_E_ERROR)
   FrTrcv_CheckDetErrorReturnValue(NULL_PTR != FrTrcv_TrcvModePtr, FRTRCV_CHANNEL_IDX,
                                   FRTRCV_GETTRANSCEIVERMODE_SERVICE_ID, FRTRCV_E_FR_INVALID_POINTER, (BusTrcvErrorType)BUSTRCV_E_ERROR)

      if ((BusTrcvErrorType)BUSTRCV_E_ERROR == ApplFblTrcvPhyGetMode(FRTRCV_CHANNEL_IDX, FrTrcv_TrcvModePtr) )
   {
      FrTrcv_DemReportError(FrTrcv_DEM_E_NoControl);
      return((BusTrcvErrorType)BUSTRCV_E_ERROR);
   }
   return((BusTrcvErrorType)BUSTRCV_E_OK);
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

/***********************************************************************************************************************
 *  FrTrcv_GetTransceiverWUReason
 **********************************************************************************************************************/
/*! \brief       Returns the wakeup reason of the selected bus
 *  \param[in]   FrTrcv_TrcvIdx The selected FlexRay bus transceiver
 *  \return      BUSTRCV_E_OK if no error occured
 *               BUSTRCV_E_ERROR if the transceiver index is out of range
 **********************************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_GetTransceiverWUReason(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY, P2VAR(FrTrcv_TrcvWUReasonType, AUTOMATIC, FRTRCV_APPL_DATA) FrTrcv_TrcvWUReasonPtr)
{
  FrTrcv_CheckDetErrorReturnValue(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                                  FRTRCV_GETTRANSCEIVERWUREASON_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX, (BusTrcvErrorType)BUSTRCV_E_ERROR)
  FrTrcv_CheckDetErrorReturnValue(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
                                  FRTRCV_GETTRANSCEIVERWUREASON_SERVICE_ID, FRTRCV_E_FR_UNINIT, (BusTrcvErrorType)BUSTRCV_E_ERROR)
  FrTrcv_CheckDetErrorReturnValue(NULL_PTR != FrTrcv_TrcvWUReasonPtr, FRTRCV_CHANNEL_IDX,
                                             FRTRCV_GETTRANSCEIVERWUREASON_SERVICE_ID, FRTRCV_E_FR_INVALID_POINTER, (BusTrcvErrorType)BUSTRCV_E_ERROR)

  *FrTrcv_TrcvWUReasonPtr = FrTrcv_TrcvWUReason[FRTRCV_CHANNEL_IDX];
   return((BusTrcvErrorType)BUSTRCV_E_OK);
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

/***********************************************************************************************************************
 *  FrTrcv_DisableTransceiverWakeup
 **********************************************************************************************************************/
/*! \brief       Disables the notification for wakeup events on the selected bus
 *  \param[in]   FrTrcv_TrcvIdx The selected FlexRay bus transceiver
 *  \return      BUSTRCV_E_OK if no error occured
 *               BUSTRCV_E_ERROR if the transceiver index is out of range
 **********************************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_DisableTransceiverWakeup(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY)
{
   FrTrcv_CheckDetErrorReturnValue(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                                   FRTRCV_DISABLETRANSCEIVERWAKEUP_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX, (BusTrcvErrorType)BUSTRCV_E_ERROR)
   FrTrcv_CheckDetErrorReturnValue(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
                                   FRTRCV_DISABLETRANSCEIVERWAKEUP_SERVICE_ID, FRTRCV_E_FR_UNINIT, (BusTrcvErrorType)BUSTRCV_E_ERROR)

   FrTrcv_WakeupCbEnabled[FRTRCV_CHANNEL_IDX] = (uint8)0u;
   return((BusTrcvErrorType)BUSTRCV_E_OK);
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

/***********************************************************************************************************************
 *  FrTrcv_EnableTransceiverWakeup
 **********************************************************************************************************************/
/*! \brief       Enables the notification for wakeup events on the selected bus
 *  \param[in]   FrTrcv_TrcvIdx The selected FlexRay bus transceiver
 *  \return      BUSTRCV_E_OK if no error occured
 *               BUSTRCV_E_ERROR  if the transceiver index is out of range
 **********************************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_EnableTransceiverWakeup(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY)
{
   FrTrcv_CheckDetErrorReturnValue(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                                   FRTRCV_ENABLETRANSCEIVERWAKEUP_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX, (BusTrcvErrorType)BUSTRCV_E_ERROR)
   FrTrcv_CheckDetErrorReturnValue(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
                                   FRTRCV_ENABLETRANSCEIVERWAKEUP_SERVICE_ID, FRTRCV_E_FR_UNINIT, (BusTrcvErrorType)BUSTRCV_E_ERROR)

   FrTrcv_WakeupCbEnabled[FRTRCV_CHANNEL_IDX] = (uint8)1u;
#if ( FRTRCV_WAKEUP_SUPPORT == STD_ON )
   /* FRTRCV300 */
   FrTrcv_EnterCritical();
   if ((uint8)1u == FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX])
   {
      FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX] = (uint8)0u;
      FrTrcv_LeaveCritical();
      EcuM_SetWakeupEvent(FrTrcv_Config[FRTRCV_CHANNEL_IDX].FrTrcv_WakeupSourceRef);
   }
   else
   {
      FrTrcv_LeaveCritical();
   }
#endif

   return((BusTrcvErrorType)BUSTRCV_E_OK);
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

/***********************************************************************************************************************
 *  FrTrcv_ClearTransceiverWakeup
 **********************************************************************************************************************/
/*! \brief       Clears pending wakeup events
 *  \param[in]   FrTrcv_TrcvIdx The selected FlexRay bus transceiver
 *  \return      BUSTRCV_E_OK if no error occured
 *               BUSTRCV_E_ERROR if the transceiver index is out of range
 **********************************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) FrTrcv_ClearTransceiverWakeup(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY)
{
  FrTrcv_CheckDetErrorReturnValue(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                                  FRTRCV_CLEARTRANSCEIVERWAKEUP_SERVICE_ID, FRTRCV_E_FR_INVALID_TRCVIDX, (BusTrcvErrorType)BUSTRCV_E_ERROR)
  FrTrcv_CheckDetErrorReturnValue(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
                                  FRTRCV_CLEARTRANSCEIVERWAKEUP_SERVICE_ID, FRTRCV_E_FR_UNINIT, (BusTrcvErrorType)BUSTRCV_E_ERROR)

  FrTrcv_EnterCritical();
  FrTrcv_WakeupDetected[FRTRCV_CHANNEL_IDX] = (uint8)0u;
  FrTrcv_TrcvWUReason[FRTRCV_CHANNEL_IDX]   = FRTRCV_WU_RESET;
  FrTrcv_LeaveCritical();

   return((BusTrcvErrorType)BUSTRCV_E_OK);
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

/***********************************************************************************************************************
 *  FrTrcv_Cbk_WakeupByTransceiver
 **********************************************************************************************************************/
/*! \brief       Is triggered by interrupts or used for polling
 *  \param[in]   FrTrcv_TrcvIdx The selected FlexRay bus transceiver
 **********************************************************************************************************************/
FUNC(void, FRTRCV_CODE) FrTrcv_Cbk_WakeupByTransceiver(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY)
{
   FrTrcv_CheckDetErrorReturnVoid(FRTRCV_CHANNEL_IDX < FrTrcv_MaxNumOfBtrBusses, FRTRCV_CHANNEL_IDX,
                                  FRTRCV_CBK_WAKEUPBYTRANSCEIVER, FRTRCV_E_FR_INVALID_TRCVIDX)
   FrTrcv_CheckDetErrorReturnVoid(FRTRCV_UNINIT != FrTrcv_IsInitialized[FRTRCV_CHANNEL_IDX], FRTRCV_CHANNEL_IDX,
                                  FRTRCV_CBK_WAKEUPBYTRANSCEIVER, FRTRCV_E_FR_UNINIT)

   if (FrTrcv_Config[FRTRCV_CHANNEL_IDX].FrTrcv_WakeupByNodeUsedPolling > FRTRCV_WAKEUP_NONE)
   {
      FrTrcv_CheckWakeupEvent(FRTRCV_CHANNEL_IDX);
   }
} /* PRQA S 2006 *//* MISRA-C:2004 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

#if ( FRTRCV_MEM_MAPPING == STD_ON )
# define FRTRCV_STOP_SEC_CODE
# include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

/***********************************************************************************************************************
 *  END OF FILE: FRTRCV.C
 **********************************************************************************************************************/
