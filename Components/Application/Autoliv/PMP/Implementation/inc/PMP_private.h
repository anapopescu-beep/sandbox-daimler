
#ifndef PMP_PRIVATE_H_
#define PMP_PRIVATE_H_ 1

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
   This file defines the information (interfaces, definitions and data) used
   by the component PMP.
   These are private data.
   This file is not intended to be included in a package header file;

******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.2.7 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/PMP/Implementation/inc/project.pj $
*/
/* PRQA S 0288 -- */
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *    Internal macro for conversion of signal PN14_SupBat_Volt_ST3 in V
 */
#define PMP_KU8_VOLTAGE_CONVERSION                      ((uint8)25)
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
#define PMP_AC_PhysicalMeasuresProvider_START_SEC_CODE
#include "PMP_AC_PhysicalMeasuresProvider_MemMap.h"

extern void pmp_GetCorrectedTemperature(uint16 * const  pu16Temperature);

#define PMP_AC_PhysicalMeasuresProvider_STOP_SEC_CODE
#include "PMP_AC_PhysicalMeasuresProvider_MemMap.h"

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* PMP_PRIVATE_H_ */
