#ifndef ERH_PUBLIC_H
#define ERH_PUBLIC_H 1

/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------------------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
H-File Template Version:
Template version: AEM_PROCESS_1.17.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2021-10
*******************************************************************************

Overview of the interfaces:
   <Describes details of this header file>

******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.6.8 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/ERH/Implementation/inc/project.pj $
*/
/* PRQA S 0288 -- */
/*****************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_Types.h"
#include "ERH_cfg_public.h"
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *      Define for block job pending
 */
#define KU8_NVP_BLOCK_JOB_PENDING (4U)
/**
 * \brief
 *      Define for NVP block where are IDs of AEC status
 */
#define NVP_BLOCK_ID_AEC_STATUS     ( 25u )
/**
 * \brief
 *       Define for number of all AECs
 */
#define ERH_KU8_NUMBER_OF_AEC        ((uint8)0x36)
/**
 * \brief
 *       Define for number of all AECs
 */
#define ERH_KU8_NUMBER_OF_GROUPS       (30u )
/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
#define ERH_AC_ErrorHandler_START_SEC_CODE
#include "ERH_AC_ErrorHandler_MemMap.h"

/* Initialization function*/
extern void ERH_Init                           (void);

extern void ERH_runStoreEverQualifiedAECsToNVP (void);

extern Std_ReturnType ERH_ResetAllAECStatus(void);

#define ERH_AC_ErrorHandler_STOP_SEC_CODE
#include "ERH_AC_ErrorHandler_MemMap.h"
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
#endif   /* I_ERH */
