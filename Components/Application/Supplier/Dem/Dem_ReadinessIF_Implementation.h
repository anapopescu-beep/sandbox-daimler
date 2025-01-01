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
/*! \addtogroup Dem_ReadinessIF
 *  \{
 *  \file       Dem_ReadinessIF_Implementation.h
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

#if !defined (DEM_READINESSIF_IMPLEMENTATION_H)
#define DEM_READINESSIF_IMPLEMENTATION_H

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
#include "Dem_ReadinessIF_Interface.h"

                                                    /* Used unit API */
/* ------------------------------------------------------------------------- */
#include "Dem_Cfg_Declarations.h"
#include "Dem_Core_Interface.h"
#include "Dem_Completion_Interface.h"
#include "Dem_Support_Interface.h"
#include "Dem_DiagnosticObserver_Interface.h"
#include "Dem_Infrastructure_Interface.h"
#include "Dem_GlobalState_Interface.h"
                                                   /* unit callbacks*/
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  UNIT CONSTANT MACROS
 *********************************************************************************************************************/

  /*! Filename declaration */
#define DEM_READINESSIF_IMPLEMENTATION_FILENAME "Dem_ReadinessIF_Implementation.h"

 /* ********************************************************************************************************************
 *  UNIT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  UNIT DATA
 *********************************************************************************************************************/
                                                                                                                                 /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  UNIT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
 
/* ********************************************************************************************************************
 *  UNIT PRIVATE PROPERTIES DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_ReadinessIF_PrivateProperties Private Properties
 * \{
 */

/* ****************************************************************************
 * Dem_GlobalDiagnostics_Readiness_IsPID01CalculationSupported
 *****************************************************************************/
 /*!
 * \brief         Tests if PID01 calculation is supported.
 *
 * \details       Tests if PID01 calculation is supported.
 *
 * \return        TRUE
 *                PID01 calculation is supported.
 * \return        FALSE
 *                PID01 calculation is not supported
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_IsPID01CalculationSupported(
  void
);

/* ****************************************************************************
 * Dem_GlobalDiagnostics_Readiness_IsPIDF501CalculationSupported
 *****************************************************************************/
 /*!
 * \brief         Tests if PIDF501 calculation is supported.
 *
 * \details       Tests if PIDF501 calculation is supported.
 *
 * \return        TRUE
 *                PIDF501 calculation is supported.
 * \return        FALSE
 *                PIDF501 calculation is not supported
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_IsPIDF501CalculationSupported(
  void
);


/* ********************************************************************************************************************
 *  UNIT PRIVATE PROPERTIES DEFINITIONS
 *********************************************************************************************************************/

/* ****************************************************************************
 % Dem_GlobalDiagnostics_Readiness_IsPID01CalculationSupported
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_IsPID01CalculationSupported(
  void
)
{
  return DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON;
}

/* ****************************************************************************
 % Dem_GlobalDiagnostics_Readiness_IsPIDF501CalculationSupported
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_IsPIDF501CalculationSupported(
  void
)
{
  return DEM_FEATURE_NEED_PIDF501_CALCULATION == STD_ON;
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
 * \addtogroup Dem_ReadinessIF_PublicProperties
 * \{
 */



/* ****************************************************************************
 % Dem_GlobalDiagnostics_Readiness_IsMotorTypeCompressionSupported
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_IsMotorTypeCompressionSupported(
  void
)
{
  return DEM_CFG_SUPPORT_IGNITION_COMPRESSION == STD_ON;
}

/* ****************************************************************************
 % Dem_GlobalDiagnostics_Readiness_IsReadinessCalculationSupported
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_IsReadinessCalculationSupported(
  void
)
{
  return DEM_FEATURE_NEED_READINESS_CALCULATION == STD_ON;
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
 * \defgroup Dem_ReadinessIF_Private Private Methods
 * \{
 */

 /* ****************************************************************************
 * Dem_GlobalDiagnostics_Readiness_CalcByteA
 *****************************************************************************/
 /*!
 * \brief         Calculates Byte A value for PID 01 and DID F501.
 *
 * \details       Calculates Byte A value for PID 01 and DID F501.
 *
 * \param[in]     NumConfirmedEvents
 *                Number of Confirmed Events
 * \return        Formated PID01 or DID501 Byte A data
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_CalcByteA(
  uint16 NumConfirmedEvents
);

/* ********************************************************************************************************************
 *  UNIT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/

 /* ****************************************************************************
 % Dem_GlobalDiagnostics_Readiness_CalcByteA
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
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_CalcByteA(
  uint16 NumConfirmedEvents
)
{
  uint8 ByteA;
  uint16 lNumConfirmedEvents; 
  lNumConfirmedEvents = NumConfirmedEvents;

  if (Dem_Cfg_IsObdIIOrObdOnUdsSupportedInVariant())
  {
    /* Number of OBD relevant confirmed events */
    uint8 lGlobalMilState;
    if (lNumConfirmedEvents > 0x7fU)
    {
      lNumConfirmedEvents = 0x7fU;
    }

    /* Get MIL state */
    if (Dem_GlobalState_Indicator_TestMilReportedActive() == TRUE)
    {
      lGlobalMilState = 0x80U;
    }
    else
    {
      lGlobalMilState = 0x00U;
    }

    /* Combine into the output variable */
    ByteA = (uint8)((lGlobalMilState | (uint8)lNumConfirmedEvents));                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
  }
  else
  {
    ByteA = 0x00u;                                                                                                               /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
  }

  return ByteA;
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
 * \addtogroup Dem_ReadinessIF_Public
 * \{
 */

 /* ****************************************************************************
 % Dem_GlobalDiagnostics_Readiness_SetByteInPIDF501Format
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_SetByteInPIDF501Format(
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) DIDF501,
  uint8 ByteValue,
  uint8 BytePos
)
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (BytePos >= DEM_READINESS_PIDF501_SIZE)
  {
    Dem_Error_RunTimeCheckFailed(DEM_READINESSIF_IMPLEMENTATION_FILENAME, __LINE__);                                             /* SBSW_DEM_POINTER_RUNTIME_CHECK */
  }
  else
# endif
  {
    DIDF501[BytePos] = ByteValue;                                                                                                /* SBSW_DEM_WRITE_PIDF501_BUFFER */
  }
}


 /* ****************************************************************************
 % Dem_GlobalDiagnostics_Readiness_ReadDataOfPID01
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
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_ReadDataOfPID01(                                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  PID01value,
  uint8 BufferSize
)
{
  Std_ReturnType lReturn;
  if (Dem_Cfg_IsObdSupportedInVariant() == TRUE)
  {
    DEM_IGNORE_UNUSED_CONST_ARGUMENT(BufferSize)                                                                                 /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if (BufferSize < 4u)
    {
      Dem_Error_RunTimeCheckFailed(DEM_READINESSIF_IMPLEMENTATION_FILENAME, __LINE__);                                           /* SBSW_DEM_POINTER_RUNTIME_CHECK */
    }
    else
#endif
    {
      uint32 lPid01;
      uint16 lNumConfirmedEvents;
      lNumConfirmedEvents = 0u;

      /* Get support values of Byte B-D */
      lPid01 = Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01(&lNumConfirmedEvents);                                               /* SBSW_DEM_POINTER_FORWARD_STACK */

      if (Dem_GlobalDiagnostics_Readiness_IsPID01CalculationSupported() == TRUE)
      {
        /* Set Engine Type in Byte B */
        if (Dem_GlobalDiagnostics_Readiness_IsMotorTypeCompressionSupported() == TRUE)
        {
          lPid01 |= DEM_READINESS_SUPPORT_COMPRESSION;
        }

        /* Get completion values of Byte B-D */
        /* Get completed state of readiness groups and set value of remaining bytes in Pid01 (completed = 0, not completed = 1u) */
        lPid01 = Dem_Readiness_Completion_MapCompletedStatePID01(lPid01);

        PID01value[1] = Dem_GetHiLoByte(lPid01);                                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
        PID01value[2] = Dem_GetLoHiByte(lPid01);                                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
        PID01value[3] = Dem_GetLoLoByte(lPid01);                                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
      }
      else
      {
        PID01value[1] = 0x04u; /* Comprehensive component monitoring supported and completed */                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
        PID01value[2] = 0x00u; /* not supported */                                                                               /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
        PID01value[3] = 0x00u; /* not supported */                                                                               /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
      }
      /* Byte A */
      PID01value[0] = Dem_GlobalDiagnostics_Readiness_CalcByteA(lNumConfirmedEvents);                                            /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
    }
    lReturn = E_OK;
  }
  else
  {
    lReturn = E_NOT_OK;
  }
  return lReturn;
}

 /* ****************************************************************************
 % Dem_GlobalDiagnostics_Readiness_ReadDataOfDIDF501
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_ReadDataOfDIDF501(                                                                               /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DIDF501value,
  uint8 BufferSize
)
{
  Std_ReturnType lReturn;
  if (Dem_Cfg_IsObdOnUdsSupportedInVariant() == TRUE)
  {
    DEM_IGNORE_UNUSED_CONST_ARGUMENT(BufferSize)                                                                                 /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if (BufferSize < 6u)
    {
      Dem_Error_RunTimeCheckFailed(DEM_READINESSIF_IMPLEMENTATION_FILENAME, __LINE__);                                           /* SBSW_DEM_POINTER_RUNTIME_CHECK */
    }
    else
#endif
    {
      uint16 lNumConfirmedEvents;
      lNumConfirmedEvents = 0u;
     
      /* Get support values of Byte B-F */
      Dem_Readiness_Support_GetSupportedStateAndConfirmedCountDIDF501(&lNumConfirmedEvents, DIDF501value);                       /* SBSW_DEM_POINTER_FORWARD_STACK */
      
      if (Dem_GlobalDiagnostics_Readiness_IsPIDF501CalculationSupported() == TRUE)
      {
        /* Get completion values of Byte B-F */
        /* Get completed state of readiness groups and set value of remaining bytes in Pid01 (completed = 0, not completed = 1u) */
        Dem_Readiness_Completion_MapCompletedStateDIDF501(DIDF501value);                                                         /* SBSW_DEM_POINTER_FORWARD_STACK */
      }
      else
      {
        /* Otherwise set remaining bytes in DidF501 to static values (Byte B = 0x04, Byte C = 0x00, Byte D = 0x00) */
        DIDF501value[1] = 0x04u; /* Comprehensive component monitoring supported and ready */                                    /* SBSW_DEM_WRITE_PIDF501_BUFFER */
        DIDF501value[2] = 0x00u; /* not supported */                                                                             /* SBSW_DEM_WRITE_PIDF501_BUFFER */
        DIDF501value[3] = 0x00u; /* not supported */                                                                             /* SBSW_DEM_WRITE_PIDF501_BUFFER */
        DIDF501value[4] = 0x00u; /* not supported */                                                                             /* SBSW_DEM_WRITE_PIDF501_BUFFER */
        DIDF501value[5] = 0x00u; /* not supported */                                                                             /* SBSW_DEM_WRITE_PIDF501_BUFFER */
      }
     
      /* Byte A */
      DIDF501value[0] = Dem_GlobalDiagnostics_Readiness_CalcByteA(lNumConfirmedEvents);                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
    }
    lReturn = E_OK;
  }
  else
  {
    lReturn = E_NOT_OK;
  }
  return lReturn;
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_READINESSIF_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_ReadinessIF_Implementation.h
 *********************************************************************************************************************/
