#ifndef ADCIF_H_
#define ADCIF_H_

/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------------------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
H-File Template Version: 
*******************************************************************************


******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*

*/
/* PRQA S 0288 -- */
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Platform_Types.h"
#include "Ifx_reg.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/


/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
enum resADC0
{
	HES_A_V,
	HB_I_P_tens,
	ADC0_ELEM
};

enum resADC1
{
	TEMP_SENSOR_Vlevel,
	KL30_SW_Vlevel,
	MOTOR_P_Vlevel,
	KL30_Vlevel,
	KL30BG_Vlevel,
	HES_B_V,
	HB_N_I_rel,
	ADC1_DUMMY,
	ADC1_ELEM
};

enum resADC2
{
	MOTOR_N_Vlevel,
	ADC2_ELEM
};

enum groupsADC
{
	ADC_GROUP0,
	ADC_GROUP1,
	ADC_GROUP2,
	ADC_TOTAL
};

/* DMA buffers number of elements (double ADC without 1) */
#define DMA0_ELEM (ADC0_ELEM*2 - 1)
#define DMA1_ELEM (ADC1_ELEM*2 - 1)
#define DMA2_ELEM (ADC2_ELEM*2 - 1)

/* DMA update mask => (2^update bits) - 1 */
#define MASK_DMA0 3
#define MASK_DMA1 15
#define MASK_DMA2 0

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

extern uint16 BufferList0[DMA0_ELEM];
extern uint16 BufferList1[DMA1_ELEM];
extern uint16 BufferList2[DMA2_ELEM];

extern uint16 astLastResList0[ADC0_ELEM];
extern uint16 astLastResList1[ADC1_ELEM];
extern uint16 astLastResList2[ADC2_ELEM];

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/

void AdcIf_Init(void);

//Stubs:
extern void AdcIf_runGetKL30_V_10ms(uint16 * pu16SampledSignal);


/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* _ADCIF_H_ */
