
#ifndef PMP_PUBLIC_H_
#define PMP_PUBLIC_H_ 1

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
   by the component PMP, part of the package PMU
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
#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *		ADC input full scale in mV (or ADC reference voltage).
 */
#define PMP_KU16_ADC_RANGE_MV                     ((uint16) 5000u)

/**
 * \brief
 *		ADC full scale output value.
 */
#define PMP_KU16_ADC_OUT_SCALE                    ((uint16) 1024u)

/**
 * \brief
 *		Temperature calibration points.
 */
#define PMP_KU8_NB_INTERP_PTS_TEMP_CALIB          ((uint8)   7)

/**
 * \brief
 *		Maximum threshold for temperature.
 */
#define PMP_KU8_DEG_RANGE                         ((uint8)   135)

/**
 * \brief
 *		Minimum threshold for temperature.
 */
#define PMP_KU8_DEG_LOW_RANGE                     ((uint8)   40)

/**
 * \brief
 *		Half sensor's typical temperature slop (used to round division by PMP_KU16_ADC_OUT_SCALE).
 */
#define PMP_KU32_TYP_H_SLOPE_UV_PER_DEG           ((PMP_KU32_TYP_SLOPE_UV_PER_DEG+1u)/2u)

/**
 * \brief
 *		ADC half scale output value (used to round division by PMP_KU16_ADC_OUT_SCALE).
 */
#define PMP_KU16_ADC_OUT_H_SCALE                  ((PMP_KU16_ADC_OUT_SCALE+1u)/2u)

/**
 * \brief
 *		ADC input full scale in uV.
 */
#define PMP_KU32_ADC_RANGE_UV                     ((uint32) 1000u * PMP_KU16_ADC_RANGE_MV)

/**
 * \brief
 *		ADC input half scale in uV (used to round division by PMP_KU16_ADC_OUT_SCALE).
 */
#define PMP_KU32_ADC_H_RANGE_UV                   ((PMP_KU32_ADC_RANGE_UV+1u)/2u)

/**
 * \brief
 *		Temperature sensor output in uV at its reference temperature.
 */
#define PMP_KU32_REF_TEMP_UV                      ((uint32) 1000u * PMP_KU16_REF_TEMP_MV)

/**
 * \brief
 *		ADC input voltage in uV, for a given ADC output value.
 */
#define PMP_KU32_ADC_INPUT_UV(output)             ((((output) * PMP_KU32_ADC_RANGE_UV) + PMP_KU16_ADC_OUT_H_SCALE) / PMP_KU16_ADC_OUT_SCALE)

/**
 * \brief
 *		ADC output value, for a given ADC input voltage in uV.
 */
#define PMP_KU32_ADC_OUTPUT(input_uv)             ((((input_uv) * PMP_KU16_ADC_OUT_SCALE) + PMP_KU32_ADC_H_RANGE_UV) / PMP_KU32_ADC_RANGE_UV)

/* Temperature sensor output raw value at its reference temperature */
#define PMP_KU32_REF_TEMP_ADC                     PMP_KU32_ADC_OUTPUT(PMP_KU32_REF_TEMP_UV)

/**
 * \brief
 *		Macro to convert a temperature from ADC output scale to degrees C, using a given slope parameter in micro volt per degree before the reference point.
 */
#define PMP_KS16_ADC_TO_DEG(temp_adc)  (sint16)(((PMP_KU8_DEG_RANGE * temp_adc) / PMP_KU16_ADC_OUT_SCALE)  - PMP_KU8_DEG_LOW_RANGE)

/**
 * \brief
 *		Macro to convert a temperature from degrees C to ADC output scale, using a given slope parameter in micro volt per degree before the reference point.
 */
#define PMP_KU16_DEG_TO_ADC(temp_deg,slope)       PMP_KU32_ADC_OUTPUT(PMP_KU32_REF_TEMP_UV - ((KU16_REF_TEMP_DEG - temp_deg) * (uint32)slope))

/**
 * \brief
 *		Macro to compute a slop in uV/degree from the reference point using the real MCU temperature in degree and the ADC scaled temperature read.
 */
#define PMP_KU16_COMPUTE_TEMP_SLOP(temp_deg,temp_adc)                       (uint16)(((PMP_KU32_REF_TEMP_UV - KU32_ADC_INPUT_UV(temp_adc)) + ((((PMP_KU16_REF_TEMP_DEG-(temp_deg))+1u)/2u)+1u)) / (PMP_KU16_REF_TEMP_DEG-(temp_deg)))

/**
 * \brief
 *		Macro to fix a temperature in ADC output scale:
 * - consider that for (temp_adc) temperature, the sensor observed the same slope as during the calibration (Cal_slope)
 * - the new output temperature will respect the sensor typical slope (Typ_slope)
 */
#define PMP_KU16_FIX_TEMP_ADC(temp_adc,Cal_slope,Cal_h_slope,Typ_slope)     (uint16)(PMP_KU32_REF_TEMP_ADC - ((((PMP_KU32_REF_TEMP_ADC - temp_adc) * Typ_slope) + Cal_h_slope) / Cal_slope))

/**
 * \brief
 *		Sensor's typical temperature slop in uV/degree C (value as provided by Freescale reference manual).
 */
#define PMP_KU32_TYP_SLOPE_UV_PER_DEG                  ((uint32) 5220u)

/**
 * \brief
 *		Temperature sensor's reference temperature in degree C (only temperature where Freescale ensure the sensor output level).
 */
#define PMP_KU16_REF_TEMP_DEG                          ((uint16) 150u)

/**
 * \brief
 *		Temperature sensor output in mV at its reference temperature (as calibrated in factory by Freescale).
 */
#define PMP_KU16_REF_TEMP_MV                           ((uint16) 2250u)

/**
 * \brief
 *		High temperature value.
 */
#define PMP_KS16_TEMP_HIGH                             ((sint16)35)

/**
 * \brief
 *		Internal macro for value 2.
 */
#define PMP_KU32_TWO                                   ((uint32)2)

/**
 * \brief
 *		Internal macro for value 100.
 */
#define PMP_KU32_ONE_HUNDRED                            ((uint32)100)

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

#endif /* PMP_PUBLIC_H_ */
