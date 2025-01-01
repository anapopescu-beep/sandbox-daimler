
#ifndef PMP_CFG_PRIVATE_H_
#define PMP_CFG_PRIVATE_H_ 1

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
   This file defines the information (interfaces, definitions and data) provided
   by the component PMP, part of the package PMP.
   These are globally visible.
   This file is intended to be included in a package header file;
   all components should include the package header file instead of this file.

******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.2.4 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/PMP/Implementation/inc/project.pj $
*/
/* PRQA S 0288 -- */
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"
#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *		ADC Result Alignment is on RIGHT.
 */
#define PMP_RIGHT_ALIGNED_ADC               0u
/**
 * \brief
 *		ADC Result Alignment is on LEFT.
 */
#define PMP_LEFT_ALIGNED_ADC                1u
/**
 * \brief
 *		ADC Result Alignment in the project.
 */
#define PMP_ALIGNMENT_ADC_CHANNELS          PMP_RIGHT_ALIGNED_ADC

/**
 * \brief
 *		ADC 10 bits range = 1024
 */
#define PMP_KU16_ADC_10BIT_RANGE                  ((uint16) 1024)
/**
 * \brief
 *		ADC 8 bits range = 256
 */
#define PMP_KU16_ADC_8BIT_RANGE                   ((uint16) 256)
/**
 * \brief
 *		ADC full range in the project
 */
#define PMP_KU16_ADC_FULL_RANGE                   PMP_KU16_ADC_10BIT_RANGE

/**
 * \brief
 *		ADC voltage reference = 5000 mV
 */
#define PMP_KU16_ADC_REFERENCE_MV                 ((uint16) 5000)

/**
 * \brief
 *		High Voltage Input factor internally applied by the S12Z MCU on high voltage analog inputs (mapped to KL30/KL30BG).
 *              Then, since the normal input Full range is 5V, the high voltage input full range is 6 x (5V) = 30V.
 */
#define PMP_KU32_HVI_INTERNAL_FACTOR                ((uint32) 66)

/**
 * \brief
 *		                                BATTERY SURVEY VOLTAGES
 *              KL30 & KL30bg multiply factor to be applied on voltage threshold parameters to convert from mV into 10 bits ADC raw format.
 */
#define PMP_KU32_KL30_RAW_MUL_FACTOR              ((uint32) PMP_KU16_ADC_FULL_RANGE)
/**
 * \brief
 *		                                BATTERY SURVEY VOLTAGES
 *              KL30 & KL30bg divide factor to be applied on voltage threshold parameters to convert from mV into 10 bits ADC raw format.
 */
#define PMP_KU32_KL30_RAW_DIV_FACTOR              ((PMP_KU32_HVI_INTERNAL_FACTOR * (uint32) PMP_KU16_ADC_REFERENCE_MV) / KU8_TEN)

/**
 * \brief
 *		                                VEHICLE VOLTAGES
 *              KL30 & KL30bg multiply factor to be applied on voltage threshold parameters to convert from mV into 10 bits ADC raw format.
 */
#define PMP_KU32_KL30_MUL_FACTOR                  ((PMP_KU32_HVI_INTERNAL_FACTOR * (uint32) PMP_KU16_ADC_REFERENCE_MV) / KU8_TEN)
/**
 * \brief
 *		                                VEHICLE VOLTAGES
 *              KL30 & KL30bg divide factor to be applied on voltage threshold parameters to convert from mV into 10 bits ADC raw format.
 */
#define PMP_KU32_KL30_DIV_FACTOR                  ((uint32) PMP_KU16_ADC_FULL_RANGE)

/**
 * \brief
 *		                                MOTOR VOLTAGES
 *              Motor V Minus multiply factor : 12 k / (12+100) k Voltage Bridge before ADC input
 */
#define PMP_KU32_VN_MUL_FACTOR                    ((uint32)112 * (uint32) PMP_KU16_ADC_REFERENCE_MV)
/**
 * \brief
 *		                                MOTOR VOLTAGES
 *              Motor V Minus divide factor : 12 k / (12+100) k Voltage Bridge before ADC input
 */
#define PMP_KU32_VN_DIV_FACTOR                    ((uint32)12  * (uint32) PMP_KU16_ADC_FULL_RANGE)

/**
 * \brief
 *		                                MOTOR VOLTAGES
 *              Motor V Plus multiply factor : 12 k / (12+100) k Voltage Bridge before ADC input
 */
#define PMP_KU32_VP_MUL_FACTOR                    ((uint32)112 * (uint32) PMP_KU16_ADC_REFERENCE_MV)
/**
 * \brief
 *		                                MOTOR VOLTAGES
 *              Motor V Plus divide factor : 12 k / (12+100) k Voltage Bridge before ADC input
 */
#define PMP_KU32_VP_DIV_FACTOR                    ((uint32)12  * (uint32) PMP_KU16_ADC_FULL_RANGE)

/**
 * \brief
 *		                                MOTOR VOLTAGES
 *              HS1 multiply factor : 12 k / (12+100) k Voltage Bridge before ADC input
 */
#define PMP_KU32_HS_MUL_FACTOR                    ((uint32)112 * (uint32) PMP_KU16_ADC_REFERENCE_MV)
/**
 * \brief
 *		                                MOTOR VOLTAGES
 *              HS1 divide factor : 12 k / (12+100) k Voltage Bridge before ADC input
 */
#define PMP_KU32_HS_DIV_FACTOR                    ((uint32)12  * (uint32) PMP_KU16_ADC_FULL_RANGE)

/**
 * \brief
 *		                                REFERENCE VOLTAGES
 *              Low reference multiply factor : Read from ADC peripheral
 */
#define PMP_KU32_REFLOW_MUL_FACTOR                ((uint32) PMP_KU16_ADC_REFERENCE_MV)
/**
 * \brief
 *		                                REFERENCE VOLTAGES
 *              Low reference divide factor : Read from ADC peripheral
 */
#define PMP_KU32_REFLOW_DIV_FACTOR                ((uint32) PMP_KU16_ADC_FULL_RANGE)

/**
 * \brief
 *		                                REFERENCE VOLTAGES
 *              Mid reference multiply factor : Read from ADC peripheral
 */
#define PMP_KU32_REFMID_MUL_FACTOR                ((uint32) PMP_KU16_ADC_REFERENCE_MV)
/**
 * \brief
 *		                                REFERENCE VOLTAGES
 *              Mid reference divide factor : Read from ADC peripheral
 */
#define PMP_KU32_REFMID_DIV_FACTOR                ((uint32) PMP_KU16_ADC_FULL_RANGE)

/**
 * \brief
 *		                                REFERENCE VOLTAGES
 *              High reference multiply factor : Read from ADC peripheral
 */
#define PMP_KU32_REFHIGH_MUL_FACTOR               ((uint32) PMP_KU16_ADC_REFERENCE_MV)
/**
 * \brief
 *		                                REFERENCE VOLTAGES
 *              High reference divide factor : Read from ADC peripheral
 */
#define PMP_KU32_REFHIGH_DIV_FACTOR               ((uint32) PMP_KU16_ADC_FULL_RANGE)

/**
 * \brief
 *		                                REFERENCE VOLTAGES
 *              Cpu Regulator Voltage multiply factor : Read from ADC peripheral
 */
#define PMP_KU32_REFCPUREG_MUL_FACTOR             ((uint32) PMP_KU16_ADC_REFERENCE_MV)
/**
 * \brief
 *		                                REFERENCE VOLTAGES
 *              Cpu Regulator Voltage divide factor : Read from ADC peripheral
 */
#define PMP_KU32_REFCPUREG_DIV_FACTOR             ((uint32) PMP_KU16_ADC_FULL_RANGE)

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
/**
 * \brief
 *              6 bits Shift for left coded Raw values
 */
#define PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT       ((uint16) 64)
#endif

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

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* PMP_CFG_PRIVATE_H_ */
