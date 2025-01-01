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
 *  \defgroup   Dem_Support Support
 *  \{
 *  \file       Dem_Support_Interface.h
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

#if !defined (DEM_SUPPORT_INTERFACE_H)
#define DEM_SUPPORT_INTERFACE_H

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
#include "Dem_Support_Types.h"

/* ********************************************************************************************************************
 *  UNIT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  UNIT PUBLIC PROPERTIES DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_Support_PublicProperties Public Properties
 * \{
 */

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
 * \defgroup Dem_Support_Public Public Methods
 * \{
 */


 /* ****************************************************************************
 * Dem_Readiness_Support_SetReadinessGroupSupportedInPidFormat
 *****************************************************************************/
 /*!
 * \brief         Sets OBD Readiness Group to supported or not supported
 *
 * \details       Sets bit corresponding to readiness group in PID Data Block
 *                (0 = not supported, 1= Supported)
 *
 * \param[in]     Supported
 *                TRUE    Readiness group is set to supported
 *                FALSE   Readiness group is set to not supported
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
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Support_SetReadinessGroupSupportedInPidFormat(
  boolean  Supported,
  uint8  ReadinessGroup,
  CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC)  PIDSupportedStates
);




/* ****************************************************************************
 * Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01
 *****************************************************************************/
/*!
 * \brief         Gets the PID 01 Data Block with supported bits set and
 *                corresponding completion bits set to not completed.
 *
 * \details       Gets the PID 01 Data Block with supported bits set and
 *                corresponding completion bits set to not completed.
 *
 * \param[out]    ConfirmedEvents
 *                Number of OBD relevant events, with the CDTC bit set
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Readiness_Support_GetSupportedStateAndConfirmedCountPID01(
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) ConfirmedEvents
  );

/* ****************************************************************************
 * Dem_Readiness_Support_GetMaskAndBytePosDIDF501Format
 *****************************************************************************/
/*!
 * \brief         Provides Byte Mask and Byte Position for a Readiness Group in 
 *                DID F501 Data Block.
 *
 * \details       Provides Byte Mask and Byte Position for a Readiness Group in 
 *                DID F501 Data Block.
 *
 * \param[in]     ReadinessGroup
 *                Readiness Group Identifier
 * \param[out]    ByteMask
 *                Byte Mask for the corresponding DID F501 Data Block
 * \param[out]    BytePos
 *                Byte Position of the corresponding DID F501 Data Block
 *
 *
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Support_GetMaskAndBytePosDIDF501Format(                                                                            /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  uint8  ReadinessGroup,
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC)  ByteMask,
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC)  BytePos
);

/* ****************************************************************************
 * Dem_Readiness_Support_GetSupportedStateAndConfirmedCountDIDF501
 *****************************************************************************/
/*!
 * \brief         Gets the PID F501 Data Block with supported bits set and
 *                corresponding completion bits set to not completed.
 *
 * \details       Gets the PID F501 Data Block with supported bits set and
 *                corresponding completion bits set to not completed.
 *
 * \param[out]    ConfirmedEvents
 *                Number of OBD relevant events, with the CDTC bit set
 * \param[in,out] DIDF501
 *                DID F501 Data Block
 * \pre           -
 * \config        -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Readiness_Support_GetSupportedStateAndConfirmedCountDIDF501(                                                                                  /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) ConfirmedEvents,
  CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) DIDF501
  );

#if (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON)
/* ****************************************************************************
 * Dem_Readiness_Support_GlobalPid41SupportedMask
 *****************************************************************************/
/*!
 * \brief         Get the readiness group supported mask
 *
 * \details       Get the readiness group supported mask
 *
 * \return        The readiness group supported mask
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Readiness_Support_GlobalPid41SupportedMask(
  void
);
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_SUPPORT_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Support_Interface.h
 *********************************************************************************************************************/
