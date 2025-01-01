
#ifndef ADCIF_CFG_H_
#define ADCIF_CFG_H_

/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------------------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
H-File Template Version: 
*******************************************************************************

Overview of the interfaces:
   This file defines the information (interfaces, definitions and data) provided
	by the module AdcIf, part of the component AdcIf.

******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Supplier/AdcIf/project.pj $
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

#define u16SampledSignalType uint16

/* Configuration of possible application treatments which have to be synchronized ADC conversion events:
* The macro is left blank if no associated treatment, else external function(s) to be executed are sequenced here. */
#define ADC_CFG_ON_CONVERSION_COMPLETION          \
           Rte_Call_pclSystemContextManagement_SuperviseKL30bg(astLastResList.u16KL30BG_V);  \
           Rte_Call_pclSurveyBatteryVoltage_Monitor();

/* Number of ADC sample used to filter Motor IP */
#define KU8_NB_MOTOR_IP_ADC_SAMPLES                            ((uint8) 3)

/* Indexes used to store each Motor IP ADC sample at the right place  */
#define KU8_MOTOR_IP_ADC_SAMPLE_IDX_0                          ((uint8) 0)
#define KU8_MOTOR_IP_ADC_SAMPLE_IDX_1                          ((uint8) 1)
#define KU8_MOTOR_IP_ADC_SAMPLE_IDX_2                          ((uint8) 2)

/*************************************************************************
Object: ADC 10 bits range = 1024
**************************************************************************/
#define ADC_KU16_ADC_10BIT_RANGE				((uint16) 1024)

/*************************************************************************
Object: ADC full range (Star12Z with 10 bit ADC peripheral)
**************************************************************************/
#define ADC_KU16_ADC_FULL_RANGE					ADC_KU16_ADC_10BIT_RANGE

/*************************************************************************
Object: ADC voltage reference = 5000 mV
**************************************************************************/
#define ADC_KU16_ADC_REFERENCE_MV				((uint16) 5000)

/*************************************************************************
Object: Low reference conversion factors : Read from ADC peripheral
**************************************************************************/
#define ADC_KU32_REFLOW_MUL_FACTOR				((uint32) ADC_KU16_ADC_REFERENCE_MV)
#define ADC_KU32_REFLOW_DIV_FACTOR				((uint32) ADC_KU16_ADC_FULL_RANGE)

/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/
#define AdcIf_START_SEC_VAR_16
#include "AdcIf_MemMap.h"

/* Last results list where data from ADC is stored */
//extern AdcIf_CFG_ResultList_Type astLastResList;

/* Table used to store all Motor IP sample. An array is used for a better filter implementation */
extern uint16 au16MotorIpAdcSamples[KU8_NB_MOTOR_IP_ADC_SAMPLES];

#define AdcIf_STOP_SEC_VAR_16
#include "AdcIf_MemMap.h"

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
#define AdcIf_START_SEC_CODE
#include "AdcIf_MemMap.h"

extern void AdcIf_cfg_IIRFilterEvery1ms(void);
extern void AdcIf_cfg_IIRFilterEvery2ms(void);
extern void AdcIf_cfg_IIRFilterEvery10ms(void);
extern void AdcIf_cfg_InitResults(void);
extern void AdcIf_cfg_IIRInit(void);
extern void AdcIf_cfg_IIRFilterIpEvery1ms(void);

#define AdcIf_STOP_SEC_CODE
#include "AdcIf_MemMap.h"

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* ADCIF_CFG_H_ */
