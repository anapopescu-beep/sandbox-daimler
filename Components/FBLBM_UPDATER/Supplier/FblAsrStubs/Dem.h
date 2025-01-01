/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief Dem ASR4 stub for flash bootloader
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#ifndef DEM_H
#define DEM_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Std_Types.h"                            /* AUTOSAR standard types */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define DEM_EVENT_STATUS_FAILED                1
#define DEM_EVENT_STATUS_PASSED                2
#define DEM_EVENT_STATUS_PREPASSED             3
#define DEM_EVENT_STATUS_PREFAILED             4

#define Dem_FR_E_ACCESS                        5
#define Dem_FRIF_E_JLE_SYNC                    6
#define Dem_FRSM_E_CLUSTER_STARTUP             7

#define DemConf_DemEventParameter_DemEventParameter 1u

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint16 Dem_EventIdType;
typedef uint8  Dem_EventStatusType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FBLASRSTUBS_DEM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern void Dem_ReportErrorStatus( Dem_EventIdType EventId, Dem_EventStatusType EventStatus);

#define FBLASRSTUBS_DEM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* DEM_H */

/***********************************************************************************************************************
 *  END OF FILE: DEM.H
 **********************************************************************************************************************/
