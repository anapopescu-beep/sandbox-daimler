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
 *  \defgroup   Dem_ReadinessIF ReadinessIF
 *  \{
 *  \file       Dem_ReadinessIF_Interface.h
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

#if !defined (DEM_READINESSIF_INTERFACE_H)
#define DEM_READINESSIF_INTERFACE_H

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
#include "Dem_ReadinessIF_Types.h"

/* ********************************************************************************************************************
 *  UNIT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  UNIT PUBLIC PROPERTIES DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_ReadinessIF_PublicProperties Public Properties
 * \{
 */


/* ****************************************************************************
 * Dem_GlobalDiagnostics_Readiness_IsMotorTypeCompressionSupported
 *****************************************************************************/
 /*!
 * \brief         Tests if motor type compression is supported in configuration.
 *
 * \details       Tests if motor type compression is supported in configuration.
 *
 * \return        TRUE
 *                Motor Type Compression is configured.
 * \return        FALSE
 *                Motor Type Spark is configured.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_IsMotorTypeCompressionSupported(
  void
);

/* ****************************************************************************
 * Dem_GlobalDiagnostics_Readiness_IsReadinessCalculationSupported
 *****************************************************************************/
 /*!
 * \brief         Tests if readiness calculation is supported.
 *
 * \details       Tests if major monitor readiness calculation is supported.
 *
 * \return        TRUE
 *                Readiness calculation is supported.
 * \return        FALSE
 *                Readiness calculation is not supported.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_IsReadinessCalculationSupported(
  void
);


/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  UNIT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_ReadinessIF_Public Public Methods
 * \{
 */

 /* ****************************************************************************
 * Dem_GlobalDiagnostics_Readiness_SetByteInPIDF501Format
 *****************************************************************************/
 /*!
 * \brief         Set the byte value of a PIDF501 data block
 *
 * \details       Set the byte value of a PIDF501 data block
 *
 * \param[in,out] DIDF501
 *                DID F501 formated data block
 * \param[in]     ByteValue
 *                Value to set
 * \param[in]     BytePos
 *                Position of byte in the array to set
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_SetByteInPIDF501Format(
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) DIDF501,
  uint8 ByteValue,
  uint8 BytePos
);

 /* ****************************************************************************
 * Dem_GlobalDiagnostics_Readiness_ReadDataOfPID01
 *****************************************************************************/
 /*!
 * \brief         Provides the monitoring status since DTCs cleared
 *
 * \details       Provides the monitoring status since DTCs cleared, formatted
 *                according to OBD-II
 *
 * \param[out]    PID01value
 *                Pointer to destination buffer, which is filled with PID 01 data.
 *
 * \param[in]     BufferSize
 *                Size of destination buffer
 * \return        E_OK
 *                Read PID01 succesful
 * \return        E_NOT_OK
 *                OBD not supported
 * \pre           -
 * \config        DEM_CFG_SUPPORT_PID01 == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_ReadDataOfPID01(
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  PID01value,
  uint8 BufferSize
);


/* ****************************************************************************
 * Dem_GlobalDiagnostics_Readiness_ReadDataOfDIDF501
 *****************************************************************************/
/*!
 * \brief         Provides the monitoring status since DTCs cleared
 *
 * \details       Provides the monitoring status since DTCs cleared, formatted
 *                according to OBD-II
 *
 * \param[out]    DIDF501value
 *                Pointer to destination buffer, which is filled with PID F501 data.
 *
 * \param[in]     BufferSize
 *                Size of destination buffer
 * \return        E_OK
 *                Read PID F501 succesful
 * \return        E_NOT_OK
 *                OBD not supported
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_GlobalDiagnostics_Readiness_ReadDataOfDIDF501(
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DIDF501value,
  uint8 BufferSize
);

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_READINESSIF_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_ReadinessIF_Interface.h
 *********************************************************************************************************************/
