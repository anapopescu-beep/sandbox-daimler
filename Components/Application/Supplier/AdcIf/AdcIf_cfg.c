
/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version: 
******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.2 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Supplier/AdcIf/project.pj $
*/
/* PRQA S 0288 -- */
/*!****************************************************************************

@details
	Configuration and interfaces for the AdcIf component

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "ADC.h"
#include "Rte_AdcIf.h"
#include "AdcIf_cfg.h"
#include "AdcIf.h"
#include "common.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
/* Initial result values for different ADC channels */
#define KU16_MCU_T                    ((uint16)0)
#define KU16_KL30SW_V                 ((uint16)0)
#define KU16_KL30_V                   ((uint16)0)
#define KU16_KL30BG_V                 ((uint16)0)
#define KU16_HBS_A_V                  ((uint16)0)
#define KU16_MOTOR_IN                 ((uint16)0)
#define KU16_HBS_B_V                  ((uint16)0)
#define KU16_MOTOR_VP                 ((uint16)0)
#define KU16_MOTOR_IP                 ((uint16)0)
#define KU16_MOTOR_VN                 ((uint16)0)

/* Macro to compute the final IIR filtered value to return to the application */
/* QAC_WARNING S 3456 2 */ /* Parameter 'Div' will be evaluated more than once when this macro is used. */
                    /* Only constants are passed as 'Index' argument when this macro is used. */
#define IIR_GET_RESULT(Index,Div)      ((au16IIRValues[(Index)]+((Div)/2u)) / (Div))

/* Macros to define the IIR filtered values indexes in au16IIRValues array */
#define KU8_KL30_V_IIR2_INDEX                                       ((uint8)0)
#define KU8_KL30_V_IIR10_INDEX                                      ((uint8)1)
#define KU8_KL30_V_IIR20_INDEX                                      ((uint8)2)
#define KU8_KL30_V_IIR100_INDEX                                     ((uint8)3)
#define KU8_KL30BG_V_IIR10_INDEX                                    ((uint8)4)
#define KU8_KL30BG_V_IIR100_INDEX                                   ((uint8)5)
#define KU8_MOTOR_VP_IIR2_INDEX                                     ((uint8)6)
#define KU8_MOTOR_VP_IIR20_INDEX                                    ((uint8)7)
#define KU8_MOTOR_VP_IIR100_INDEX                                   ((uint8)8)
#define KU8_MOTOR_VN_IIR2_INDEX                                     ((uint8)9)
#define KU8_MOTOR_VN_IIR20_INDEX                                    ((uint8)10)
#define KU8_MOTOR_VN_IIR100_INDEX                                   ((uint8)11)
#define KU8_KL30SW_V_IIR2_INDEX                                     ((uint8)12)
#define KU8_KL30SW_V_IIR10_INDEX                                    ((uint8)13)
#define KU8_KL30SW_V_IIR20_INDEX                                    ((uint8)14)
#define KU8_KL30SW_V_IIR100_INDEX                                   ((uint8)15)
#define KU8_MOTOR_IP_IIR10_INDEX                                    ((uint8)16)
#define KU8_MOTOR_IN_IIR10_INDEX                                    ((uint8)17)
#define KU8_HBS_A_V_IIR10_INDEX                                     ((uint8)18)
#define KU8_HBS_A_V_IIR100_INDEX                                    ((uint8)19)
#define KU8_HBS_B_V_IIR10_INDEX                                     ((uint8)20)
#define KU8_HBS_B_V_IIR100_INDEX                                    ((uint8)21)
#define KU8_MCU_T_IIR10_INDEX                                       ((uint8)22)
#define KU8_IIR_NUMBER                                              ((uint8)23)

/* Macros to define the IIR "k" value parameters */
#define KU8_KL30_V_IIR2_K                                           ((uint8)1)
#define KU8_KL30_V_IIR10_K                                          ((uint8)1)
#define KU8_KL30_V_IIR20_K                                          ((uint8)2)
#define KU8_KL30_V_IIR100_K                                         ((uint8)15)
#define KU8_KL30BG_V_IIR10_K                                        ((uint8)7)
#define KU8_KL30BG_V_IIR100_K                                       ((uint8)3)
#define KU8_MOTOR_VP_IIR2_K                                         ((uint8)1)
#define KU8_MOTOR_VP_IIR20_K                                        ((uint8)2)
#define KU8_MOTOR_VP_IIR100_K                                       ((uint8)15)
#define KU8_MOTOR_VN_IIR2_K                                         ((uint8)1)
#define KU8_MOTOR_VN_IIR20_K                                        ((uint8)2)
#define KU8_MOTOR_VN_IIR100_K                                       ((uint8)15)
#define KU8_KL30SW_V_IIR2_K                                         ((uint8)1)
#define KU8_KL30SW_V_IIR10_K                                        ((uint8)1)
#define KU8_KL30SW_V_IIR20_K                                        ((uint8)2)
#define KU8_KL30SW_V_IIR100_K                                       ((uint8)15)
#define KU8_MOTOR_IP_IIR10_K                                        ((uint8)7)
#define KU8_MOTOR_IN_IIR10_K                                        ((uint8)7)
#define KU8_HBS_A_V_IIR10_K                                         ((uint8)7)
#define KU8_HBS_A_V_IIR100_K                                        ((uint8)3)
#define KU8_HBS_B_V_IIR10_K                                         ((uint8)7)
#define KU8_HBS_B_V_IIR100_K                                        ((uint8)3)
#define KU8_MCU_T_IIR10_K                                           ((uint8)3)

/* Macros to define the divisor parameters used to get IIR final results */
#define KU8_KL30_V_IIR2_DIVISOR                                     ((uint8)2)
#define KU8_KL30_V_IIR10_DIVISOR                                    ((uint8)4)
#define KU8_KL30_V_IIR20_DIVISOR                                    ((uint8)6)
#define KU8_KL30_V_IIR100_DIVISOR                                   ((uint8)32)
#define KU8_KL30BG_V_IIR10_DIVISOR                                  ((uint8)8)
#define KU8_KL30BG_V_IIR100_DIVISOR                                 ((uint8)32)
#define KU8_MOTOR_VP_IIR2_DIVISOR                                   ((uint8)2)
#define KU8_MOTOR_VP_IIR20_DIVISOR                                  ((uint8)6)
#define KU8_MOTOR_VP_IIR100_DIVISOR                                 ((uint8)32)
#define KU8_MOTOR_VN_IIR2_DIVISOR                                   ((uint8)2)
#define KU8_MOTOR_VN_IIR20_DIVISOR                                  ((uint8)6)
#define KU8_MOTOR_VN_IIR100_DIVISOR                                 ((uint8)32)
#define KU8_KL30SW_V_IIR2_DIVISOR                                   ((uint8)2)
#define KU8_KL30SW_V_IIR10_DIVISOR                                  ((uint8)4)
#define KU8_KL30SW_V_IIR20_DIVISOR                                  ((uint8)6)
#define KU8_KL30SW_V_IIR100_DIVISOR                                 ((uint8)32)
#define KU8_MOTOR_IP_IIR10_DIVISOR                                  ((uint8)8)
#define KU8_MOTOR_IN_IIR10_DIVISOR                                  ((uint8)8)
#define KU8_HBS_A_V_IIR10_DIVISOR                                   ((uint8)8)
#define KU8_HBS_A_V_IIR100_DIVISOR                                  ((uint8)32)
#define KU8_HBS_B_V_IIR10_DIVISOR                                   ((uint8)8)
#define KU8_HBS_B_V_IIR100_DIVISOR                                  ((uint8)32)
#define KU8_MCU_T_IIR10_DIVISOR

/* Definition of coefficients for the low pass IIR filter applied on tensioning
* current signal results (15 bits fixed point precision < 16 bits to avoid
* overflow during accumulation.) */
/* Second order Butterworth filter coefficients */
/* x[n-k] coeffcients - ADC values */
#define KS16_ADC_IIR_X_B0_COEFF                                     ((sint16) 3200)
#define KS16_ADC_IIR_X_B1_COEFF                                     ((sint16) 6400)
#define KS16_ADC_IIR_X_B2_COEFF                                     ((sint16) 3200)
/* y[n-m] coeffcients - Previous filtered values */
#define KS16_ADC_IIR_Y_A1_COEFF                                     ((sint16) -30894)
#define KS16_ADC_IIR_Y_A2_COEFF                                     ((sint16) 10922)


/* Motor IP IIR filter fixed point resolution is set to 15 bits (2^15) */
#define KS32_ADC_IIR_MOTOR_IP_FIXED_POINT_RESOLUTION                ((sint32) 32768)

/* Number of previous ADC and filtered value kept in memory */
#define KU8_NB_PREVIOUS_MOTOR_IP_IIR_SAMPLES                        ((uint8) 2)

/* Indexes of N-1 and N-2 values stored in memory arrays */
#define KU8_MOTOR_IP_IIR_IN_IDX_N_1                                 ((uint8) 0)
#define KU8_MOTOR_IP_IIR_IN_IDX_N_2                                 ((uint8) 1)
#define KU8_MOTOR_IP_IIR_OUT_IDX_N_1                                ((uint8) 0)
#define KU8_MOTOR_IP_IIR_OUT_IDX_N_2                                ((uint8) 1)

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define AdcIf_START_SEC_VAR_16
#include "AdcIf_MemMap.h"
/* Storage of IIR filtered values */
/* QAC_WARNING S 2022 2 */ /* A tentative definition is being used. Is it appropriate to include an explicit initializer ? */
                    /* This array content is initialized with the first conversion results. */
static uint16 au16IIRValues[KU8_IIR_NUMBER];

/* Previous ADC sample used by the IIR filter */
static uint16 au16PrevMotorIpAdc[KU8_NB_PREVIOUS_MOTOR_IP_IIR_SAMPLES];
/* Previous filtered values used by the IIR filter */
static sint16 as16PrevMotIpFilteredValue[KU8_NB_PREVIOUS_MOTOR_IP_IIR_SAMPLES];

#define AdcIf_STOP_SEC_VAR_16
#include "AdcIf_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
#define AdcIf_START_SEC_VAR_16
#include "AdcIf_MemMap.h"

/* Last results list for Motor IP ADC samples */
uint16 au16MotorIpAdcSamples[KU8_NB_MOTOR_IP_ADC_SAMPLES];

#define AdcIf_STOP_SEC_VAR_16
#include "AdcIf_MemMap.h"

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/
/* Macro to compute the intermediate IIR filtered value when sampling signals */
/* QAC_WARNING S 3456 12 */ /* Parameter 'Index' will be evaluated more than once when this macro is used. */
                     /* Only constants are passed as 'Index' argument when this macro is used. */
#define IIR_UPDATE(Index,Sample,k)     (au16IIRValues[(Index)] = (Sample) +                                              \
                                                                 (uint16) (                                              \
                                                                            (                                            \
                                                                              ((uint32)au16IIRValues[(Index)]*(k))       \
                                                                              +                                          \
                                                                              (((k)+1u)/2u)                              \
                                                                            )                                            \
                                                                            /                                            \
                                                                            ((k)+1u)                                     \
                                                                          )                                              \
                                                   )

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
#define AdcIf_START_SEC_CODE
#include "AdcIf_MemMap.h"
/*!****************************************************************************
* @details
*     Apply an IIR filter on Motor IP based on 3 samples
*     Second order butterworth low pass filter
*     Cutting frequency:  1 kHz
*     Sampling frequency: 8 kHz
* @param[in]
*     none
* @param[out]
*     none
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_cfg_IIRFilterIpEvery1ms(void)
{
   sint32 s32FilteredIp;
   uint8 u8LoopIdx;

   //DISCUTABIL
   Adc_RS0EventInterruptHandler(0U);

   /* Workarround for 3 samples */
   au16MotorIpAdcSamples[KU8_MOTOR_IP_ADC_SAMPLE_IDX_0] = astLastResList0[HB_I_P_tens];
   au16MotorIpAdcSamples[KU8_MOTOR_IP_ADC_SAMPLE_IDX_1] = astLastResList0[HB_I_P_tens];
   au16MotorIpAdcSamples[KU8_MOTOR_IP_ADC_SAMPLE_IDX_2] = astLastResList0[HB_I_P_tens];

   /* Apply IIR filter on 3 samples */
   for (u8LoopIdx = KU8_ZERO; u8LoopIdx < KU8_NB_MOTOR_IP_ADC_SAMPLES; u8LoopIdx++)
   {
      /* Apply B0, B1 and B2 coefficients on ADC values N, N-1 and N-2 */
      s32FilteredIp =  (sint32)au16MotorIpAdcSamples[u8LoopIdx] * (sint32)KS16_ADC_IIR_X_B0_COEFF;
      s32FilteredIp += (sint32)au16PrevMotorIpAdc[KU8_MOTOR_IP_IIR_IN_IDX_N_1] * (sint32)KS16_ADC_IIR_X_B1_COEFF;
      s32FilteredIp += (sint32)au16PrevMotorIpAdc[KU8_MOTOR_IP_IIR_IN_IDX_N_2] * (sint32)KS16_ADC_IIR_X_B2_COEFF;
      /* Apply A1 and A2 coefficient on filtered value N-1 and N-2 */
      s32FilteredIp -= (sint32)as16PrevMotIpFilteredValue[KU8_MOTOR_IP_IIR_OUT_IDX_N_1] * (sint32)KS16_ADC_IIR_Y_A1_COEFF;
      s32FilteredIp -= (sint32)as16PrevMotIpFilteredValue[KU8_MOTOR_IP_IIR_OUT_IDX_N_2] * (sint32)KS16_ADC_IIR_Y_A2_COEFF;
      /* Rescale value to ADC resolution [0 ; 1023] */
      s32FilteredIp /= KS32_ADC_IIR_MOTOR_IP_FIXED_POINT_RESOLUTION;

      /* Update Previous array for next sample */
      as16PrevMotIpFilteredValue[KU8_MOTOR_IP_IIR_OUT_IDX_N_2] = as16PrevMotIpFilteredValue[KU8_MOTOR_IP_IIR_OUT_IDX_N_1];
      as16PrevMotIpFilteredValue[KU8_MOTOR_IP_IIR_OUT_IDX_N_1] = (sint16)s32FilteredIp;
      /* ADC samples */
      au16PrevMotorIpAdc[KU8_MOTOR_IP_IIR_IN_IDX_N_2] = au16PrevMotorIpAdc[KU8_MOTOR_IP_IIR_IN_IDX_N_1];
      au16PrevMotorIpAdc[KU8_MOTOR_IP_IIR_IN_IDX_N_1] = au16MotorIpAdcSamples[u8LoopIdx];
   }

   /* Check for overflow (ADC resolution: 10 bits => Max value = 1024 */
   if( s32FilteredIp > (sint32)ADC_KU16_ADC_10BIT_RANGE )
   {
      /* Force it to maximum ADC value */
      astLastResList0[HB_I_P_tens] = ADC_KU16_ADC_10BIT_RANGE;
   }
   else if( s32FilteredIp < KS16_ZERO )
   {
      /* Force it to 0 */
      astLastResList0[HB_I_P_tens] = KU16_ZERO;
   }
   else
   {
      /* No overflow or underflow, computed value is the right one. The value is strictly positive, we can cast it to unsigned */
      astLastResList0[HB_I_P_tens] = (uint16)s32FilteredIp;
   }
}

/*!****************************************************************************
* @details
*		Do IIR filtering computation based on samples updated after all ADC
*		conversion performed every 400�s.
* @param[in]
*     none
* @param[out]
*     none
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_cfg_IIRFilterEvery1ms(void)
{
   /* QAC_WARNING S 4120 ++ */ /* Implicit conversion: complex expression of integral type to wider type. */
                        /* In "IIR_UPDATE" macro, intermediate multiplying result shall be 32 bits wide */
                        /* to avoid possible overflow (checked at generated assembly code level) */
	IIR_UPDATE(KU8_KL30_V_IIR2_INDEX, astLastResList1[KL30_Vlevel], KU8_KL30_V_IIR2_K);
   IIR_UPDATE(KU8_KL30SW_V_IIR2_INDEX, astLastResList1[KL30_SW_Vlevel], KU8_KL30SW_V_IIR2_K);
   IIR_UPDATE(KU8_KL30BG_V_IIR10_INDEX, astLastResList1[KL30BG_Vlevel], KU8_KL30BG_V_IIR10_K);
   IIR_UPDATE(KU8_MOTOR_VP_IIR2_INDEX, astLastResList1[MOTOR_P_Vlevel], KU8_MOTOR_VP_IIR2_K);
   IIR_UPDATE(KU8_MOTOR_VN_IIR2_INDEX, astLastResList2[MOTOR_N_Vlevel], KU8_MOTOR_VN_IIR2_K);
   IIR_UPDATE(KU8_MOTOR_IP_IIR10_INDEX, astLastResList0[HB_I_P_tens], KU8_MOTOR_IP_IIR10_K);
   IIR_UPDATE(KU8_MOTOR_IN_IIR10_INDEX, astLastResList1[HB_N_I_rel], KU8_MOTOR_IN_IIR10_K);
   IIR_UPDATE(KU8_HBS_A_V_IIR10_INDEX, astLastResList0[HES_A_V], KU8_HBS_A_V_IIR10_K);
   IIR_UPDATE(KU8_HBS_B_V_IIR10_INDEX, astLastResList1[HES_B_V], KU8_HBS_B_V_IIR10_K);
   /* QAC_WARNING S 4120 -- */
}

/*!****************************************************************************
* @details
*     Do IIR filtering computation based on 2 milli-seconds samples,
*		ie values already filtered for such 2ms periodic use.
* @param[in]
*     none
* @param[out]
*     none
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_cfg_IIRFilterEvery2ms(void)
{
   /* QAC_WARNING S 4120 ++ */ /* Implicit conversion: complex expression of integral type to wider type. */
                        /* In "IIR_UPDATE" macro, intermediate multiplying result shall be 32 bits wide */
                        /* to avoid possible overflow (checked at generated assembly code level) */
   IIR_UPDATE(KU8_KL30_V_IIR10_INDEX, au16IIRValues[KU8_KL30_V_IIR2_INDEX], KU8_KL30_V_IIR10_K);
   IIR_UPDATE(KU8_KL30_V_IIR20_INDEX, au16IIRValues[KU8_KL30_V_IIR2_INDEX], KU8_KL30_V_IIR20_K);
   IIR_UPDATE(KU8_KL30_V_IIR100_INDEX, au16IIRValues[KU8_KL30_V_IIR2_INDEX], KU8_KL30_V_IIR100_K);
   IIR_UPDATE(KU8_KL30SW_V_IIR10_INDEX, au16IIRValues[KU8_KL30SW_V_IIR2_INDEX], KU8_KL30SW_V_IIR10_K);
   IIR_UPDATE(KU8_KL30SW_V_IIR20_INDEX, au16IIRValues[KU8_KL30SW_V_IIR2_INDEX], KU8_KL30SW_V_IIR20_K);
   IIR_UPDATE(KU8_KL30SW_V_IIR100_INDEX, au16IIRValues[KU8_KL30SW_V_IIR2_INDEX], KU8_KL30SW_V_IIR100_K);
   IIR_UPDATE(KU8_MOTOR_VP_IIR20_INDEX, au16IIRValues[KU8_MOTOR_VP_IIR2_INDEX], KU8_MOTOR_VP_IIR20_K);
   IIR_UPDATE(KU8_MOTOR_VP_IIR100_INDEX, au16IIRValues[KU8_MOTOR_VP_IIR2_INDEX], KU8_MOTOR_VP_IIR100_K);
   IIR_UPDATE(KU8_MOTOR_VN_IIR20_INDEX, au16IIRValues[KU8_MOTOR_VN_IIR2_INDEX], KU8_MOTOR_VN_IIR20_K);
   IIR_UPDATE(KU8_MOTOR_VN_IIR100_INDEX, au16IIRValues[KU8_MOTOR_VN_IIR2_INDEX], KU8_MOTOR_VN_IIR100_K);
   /* QAC_WARNING S 4120 -- */
}

/*!****************************************************************************
* @details
*     Do IIR filtering computation based on 10 milli-seconds samples,
*		ie values already filtered for such 10ms periodic use.
* @param[in]
*     ThisIsIn input parameter
* @param[out]
*     ThisIsOut output parameter
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_cfg_IIRFilterEvery10ms(void)
{
   /* QAC_WARNING S 4120 ++ */ /* Implicit conversion: complex expression of integral type to wider type. */
                        /* In "IIR_UPDATE" macro, intermediate multiplying result shall be 32 bits wide */
                        /* to avoid possible overflow (checked at generated assembly code level) */
   IIR_UPDATE(KU8_KL30BG_V_IIR100_INDEX, au16IIRValues[KU8_KL30BG_V_IIR10_INDEX], KU8_KL30BG_V_IIR100_K);
   IIR_UPDATE(KU8_HBS_A_V_IIR100_INDEX, au16IIRValues[KU8_HBS_A_V_IIR10_INDEX], KU8_HBS_A_V_IIR100_K);
   IIR_UPDATE(KU8_HBS_B_V_IIR100_INDEX, au16IIRValues[KU8_HBS_B_V_IIR10_INDEX], KU8_HBS_B_V_IIR100_K);
   /* QAC_WARNING S 4120 -- */
}


/*!****************************************************************************
* @details
*     Initialize the raw result list to default values
* @param[in]
*     none
* @param[out]
*     none
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_cfg_InitResults(void)
{
   astLastResList1[TEMP_SENSOR_Vlevel] = KU16_MCU_T;
   astLastResList1[KL30_Vlevel]	      = KU16_KL30_V;
   astLastResList1[KL30_SW_Vlevel]     = KU16_KL30SW_V;
   astLastResList1[KL30BG_Vlevel]      = KU16_KL30BG_V;
   astLastResList1[MOTOR_P_Vlevel]     = KU16_MOTOR_VP;
   astLastResList2[MOTOR_N_Vlevel]     = KU16_MOTOR_VN;
   astLastResList0[HB_I_P_tens]	      = KU16_MOTOR_IP;
   astLastResList1[HB_N_I_rel]	      = KU16_MOTOR_IN;
   astLastResList0[HES_A_V]		      = KU16_HBS_A_V;
   astLastResList1[HES_B_V]		      = KU16_HBS_B_V;
   
   /* Motor IP samples used by the IIR filter */
   au16MotorIpAdcSamples[KU8_MOTOR_IP_ADC_SAMPLE_IDX_0] = KU16_MOTOR_IP;
   au16MotorIpAdcSamples[KU8_MOTOR_IP_ADC_SAMPLE_IDX_1] = KU16_MOTOR_IP;
   au16MotorIpAdcSamples[KU8_MOTOR_IP_ADC_SAMPLE_IDX_2] = KU16_MOTOR_IP;
}

/*!****************************************************************************
* @details
*     Initialize the IIR filtered values using conversion results
* @param[in]
*     none
* @param[out]
*     none
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_cfg_IIRInit(void)
{
   au16IIRValues[KU8_KL30_V_IIR2_INDEX] = astLastResList1[KL30_Vlevel] * (KU8_KL30_V_IIR2_K + 1u);
   au16IIRValues[KU8_KL30_V_IIR10_INDEX] = au16IIRValues [KU8_KL30_V_IIR2_INDEX] * (KU8_KL30_V_IIR10_K + 1u);
   au16IIRValues[KU8_KL30_V_IIR20_INDEX] = au16IIRValues [KU8_KL30_V_IIR2_INDEX] * (KU8_KL30_V_IIR20_K + 1u);
   au16IIRValues[KU8_KL30_V_IIR100_INDEX] = au16IIRValues [KU8_KL30_V_IIR2_INDEX] * (KU8_KL30_V_IIR100_K + 1u);
   au16IIRValues[KU8_KL30SW_V_IIR2_INDEX] = astLastResList1[KL30_SW_Vlevel] * (KU8_KL30SW_V_IIR2_K + 1u);
   au16IIRValues[KU8_KL30SW_V_IIR10_INDEX] = au16IIRValues [KU8_KL30SW_V_IIR2_INDEX] * (KU8_KL30SW_V_IIR10_K + 1u);
   au16IIRValues[KU8_KL30SW_V_IIR20_INDEX] = au16IIRValues [KU8_KL30SW_V_IIR2_INDEX] * (KU8_KL30SW_V_IIR20_K + 1u);
   au16IIRValues[KU8_KL30SW_V_IIR100_INDEX] = au16IIRValues [KU8_KL30SW_V_IIR2_INDEX] * (KU8_KL30SW_V_IIR100_K + 1u);
   au16IIRValues[KU8_KL30BG_V_IIR10_INDEX] = astLastResList1[KL30BG_Vlevel] * (KU8_KL30BG_V_IIR10_K + 1u);
   au16IIRValues[KU8_KL30BG_V_IIR100_INDEX] = au16IIRValues [KU8_KL30BG_V_IIR10_INDEX] * (KU8_KL30BG_V_IIR100_K + 1u);
   au16IIRValues[KU8_MOTOR_VP_IIR2_INDEX] = astLastResList1[MOTOR_P_Vlevel] * (KU8_MOTOR_VP_IIR2_K + 1u);
   au16IIRValues[KU8_MOTOR_VP_IIR20_INDEX] = au16IIRValues [KU8_MOTOR_VP_IIR2_INDEX] * (KU8_MOTOR_VP_IIR20_K + 1u);
   au16IIRValues[KU8_MOTOR_VP_IIR100_INDEX] = au16IIRValues [KU8_MOTOR_VP_IIR2_INDEX] * (KU8_MOTOR_VP_IIR100_K + 1u);
   au16IIRValues[KU8_MOTOR_VN_IIR2_INDEX] = astLastResList2[MOTOR_N_Vlevel] * (KU8_MOTOR_VN_IIR2_K + 1u);
   au16IIRValues[KU8_MOTOR_VN_IIR20_INDEX] = au16IIRValues [KU8_MOTOR_VN_IIR2_INDEX] * (KU8_MOTOR_VN_IIR20_K + 1u);
   au16IIRValues[KU8_MOTOR_VN_IIR100_INDEX] = au16IIRValues [KU8_MOTOR_VN_IIR2_INDEX] * (KU8_MOTOR_VN_IIR100_K + 1u);
   au16IIRValues[KU8_MOTOR_IP_IIR10_INDEX] = astLastResList0[HB_I_P_tens] * (KU8_MOTOR_IP_IIR10_K + 1u);
   au16IIRValues[KU8_MOTOR_IN_IIR10_INDEX] = astLastResList1[HB_N_I_rel] * (KU8_MOTOR_IN_IIR10_K + 1u);
   au16IIRValues[KU8_HBS_A_V_IIR10_INDEX] = astLastResList0[HES_A_V] * (KU8_HBS_A_V_IIR10_K + 1u);
   au16IIRValues[KU8_HBS_A_V_IIR100_INDEX] = au16IIRValues [KU8_HBS_A_V_IIR10_INDEX] * (KU8_HBS_A_V_IIR100_K + 1u);
   au16IIRValues[KU8_HBS_B_V_IIR10_INDEX] = astLastResList1[HES_B_V] * (KU8_HBS_B_V_IIR10_K + 1u);
   au16IIRValues[KU8_HBS_B_V_IIR100_INDEX] = au16IIRValues [KU8_HBS_B_V_IIR10_INDEX] * (KU8_HBS_B_V_IIR100_K + 1u);
   au16IIRValues[KU8_MCU_T_IIR10_INDEX] = astLastResList1[TEMP_SENSOR_Vlevel] * (KU8_MCU_T_IIR10_K + 1u);
}

/*!****************************************************************************
* @details
*     This function shall provide Tensioning Current raw value sampled and converted by the HW A/D converter.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMotor_Ip(u16SampledSignalType * pu16SampledSignal)
{
   /* This result is directly taken from the ADC last result list */
   /* Note: The pointer is loaded in S12Z address register thru an atomic instruction,
    * making this function interruptible by the end of conversion interrupt (which
    * modify this pointer) without protection mechanism. */
   /* QAC_WARNING S 0506 2 */ /* Possible dereference of NULL pointer */
                       /* Use of this service assumes that the argument points an instantiated variable */
   *pu16SampledSignal = (u16SampledSignalType)astLastResList0[HB_I_P_tens];
}

/*!****************************************************************************
* @details
*     This function shall provide TEMPERATURE raw value sampled and converted by the HW A/D converter.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMcu_T(u16SampledSignalType * pu16SampledSignal)
{
   /* TEMPERATURE is available only on result list 0. */
   /* QAC_WARNING S 0506 2 */ /* Possible dereference of NULL pointer */
   /* Use of this service assumes that the argument points an instantiated variable */
   *pu16SampledSignal = (u16SampledSignalType)astLastResList1[TEMP_SENSOR_Vlevel];
}

/*!****************************************************************************
* @details
*     This function shall provideHall Sensor A Power Supply level control
*		raw value sampled and converted by the HW A/D converter.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetHBS_A_V(u16SampledSignalType * pu16SampledSignal)
{
   /* This result is directly taken from the ADC last result list */
   /* Note: The pointer is loaded in S12Z address register thru an atomic instruction,
    * making this function interruptible by the end of conversion interrupt (which
    * modify this pointer) without protection mechanism. */
   /* QAC_WARNING S 0506 2 */ /* Possible dereference of NULL pointer */
                       /* Use of this service assumes that the argument points an instantiated variable */
   *pu16SampledSignal = (u16SampledSignalType)astLastResList0[HES_A_V];
}

/*!****************************************************************************
* @details
*     This function shall provideHall Sensor B Power Supply level control
*		raw value sampled and converted by the HW A/D converter.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetHBS_B_V(u16SampledSignalType * pu16SampledSignal)
{
   /* This result is directly taken from the ADC last result list */
   /* Note: The pointer is loaded in S12Z address register thru an atomic instruction,
    * making this function interruptible by the end of conversion interrupt (which
    * modify this pointer) without protection mechanism. */
   /* QAC_WARNING S 0506 2 */ /* Possible dereference of NULL pointer */
                       /* Use of this service assumes that the argument points an instantiated variable */
   *pu16SampledSignal = (u16SampledSignalType)astLastResList1[HES_B_V];
}

/*!****************************************************************************
* @details
*     This function shall provideHalf bridge V+ voltage control
*		raw value sampled and converted by the HW A/D converter.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMotor_Vp(u16SampledSignalType * pu16SampledSignal)
{
   /* This result is directly taken from the ADC last result list */
   /* Note: The pointer is loaded in S12Z address register thru an atomic instruction,
    * making this function interruptible by the end of conversion interrupt (which
    * modify this pointer) without protection mechanism. */
   /* QAC_WARNING S 0506 2 */ /* Possible dereference of NULL pointer */
                       /* Use of this service assumes that the argument points an instantiated variable */
   *pu16SampledSignal = (u16SampledSignalType)astLastResList1[MOTOR_P_Vlevel];
}

/*!****************************************************************************
* @details
*     This function shall provideHalf bridge V- voltage control
*		raw value sampled and converted by the HW A/D converter.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMotor_Vn(u16SampledSignalType * pu16SampledSignal)
{
   /* This result is directly taken from the ADC last result list */
   /* Note: The pointer is loaded in S12Z address register thru an atomic instruction,
    * making this function interruptible by the end of conversion interrupt (which
    * modify this pointer) without protection mechanism. */
   /* QAC_WARNING S 0506 2 */ /* Possible dereference of NULL pointer */
                       /* Use of this service assumes that the argument points an instantiated variable */
   *pu16SampledSignal = (u16SampledSignalType)astLastResList2[MOTOR_N_Vlevel];
}

/*!****************************************************************************
* @details
*     This function shall provideKL30BG power supply control
*		raw value sampled and converted by the HW A/D converter.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetKL30BG_V(u16SampledSignalType * pu16SampledSignal)
{
   /* This result is directly taken from the ADC last result list */
   /* Note: The pointer is loaded in S12Z address register thru an atomic instruction,
    * making this function interruptible by the end of conversion interrupt (which
    * modify this pointer) without protection mechanism. */
   /* QAC_WARNING S 0506 2 */ /* Possible dereference of NULL pointer */
                       /* Use of this service assumes that the argument points an instantiated variable */
   *pu16SampledSignal = (u16SampledSignalType)astLastResList1[KL30BG_Vlevel];
}

/*!****************************************************************************
* @details
*     This function shall provideKL30 power supply control
*     raw value sampled and converted by the HW A/D converter.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetKL30_V(u16SampledSignalType * pu16SampledSignal)
{
   /* This result is directly taken from the ADC last result list */
   /* Note: The pointer is loaded in S12Z address register thru an atomic instruction,
    * making this function interruptible by the end of conversion interrupt (which
    * modify this pointer) without protection mechanism. */
   /* QAC_WARNING S 0506 2 */ /* Possible dereference of NULL pointer */
                       /* Use of this service assumes that the argument points an instantiated variable */
   *pu16SampledSignal = (u16SampledSignalType)astLastResList1[KL30_Vlevel];
}

/*!****************************************************************************
* @details
*     This function shall provideReleasing Current
*     raw value sampled and converted by the HW A/D converter.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMotor_In(u16SampledSignalType * pu16SampledSignal)
{
   /* This result is directly taken from the ADC last result list */
   /* Note: The pointer is loaded in S12Z address register thru an atomic instruction,
    * making this function interruptible by the end of conversion interrupt (which
    * modify this pointer) without protection mechanism. */
   /* QAC_WARNING S 0506 2 */ /* Possible dereference of NULL pointer */
                       /* Use of this service assumes that the argument points an instantiated variable */
   *pu16SampledSignal = (u16SampledSignalType)astLastResList1[HB_N_I_rel];
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the KL30_V
*     analog signal, for a 2ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetKL30_V_2ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_KL30_V_IIR2_INDEX, KU8_KL30_V_IIR2_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the HS1_V
*     analog signal, for a 2ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetHS1_V(u16SampledSignalType * pu16SampledSignal)
{
   /* This result is directly taken from the ADC last result list */
   /* Note: The pointer is loaded in S12Z address register thru an atomic instruction,
    * making this function interruptible by the end of conversion interrupt (which
    * modify this pointer) without protection mechanism. */
   /* QAC_WARNING S 0506 2 */ /* Possible dereference of NULL pointer */
                       /* Use of this service assumes that the argument points an instantiated variable */
   *pu16SampledSignal = (u16SampledSignalType)astLastResList1[KL30_SW_Vlevel];
}


/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the HS1_V
*     analog signal, for a 10ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
/*COVERS: DSG_AdcIf_0046*/
void AdcIf_runGetHS1_V_10ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_KL30SW_V_IIR10_INDEX, KU8_KL30SW_V_IIR10_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the HS1_V
*     analog signal, for a 20ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
/*COVERS: DSG_AdcIf_0047*/
void AdcIf_runGetHS1_V_20ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_KL30SW_V_IIR20_INDEX, KU8_KL30SW_V_IIR20_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the HS1_V
*     analog signal, for a 100ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
/*COVERS: DSG_AdcIf_0048*/
void AdcIf_runGetHS1_V_100ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_KL30SW_V_IIR100_INDEX, KU8_KL30SW_V_IIR100_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the KL30_V
*     analog signal, for a 10ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetKL30_V_10ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_KL30_V_IIR10_INDEX, KU8_KL30_V_IIR10_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the KL30_V
*     analog signal, for a 20ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetKL30_V_20ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_KL30_V_IIR20_INDEX, KU8_KL30_V_IIR20_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the KL30_V
*     analog signal, for a 100ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetKL30_V_100ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_KL30_V_IIR100_INDEX, KU8_KL30_V_IIR100_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the KL30BG_V
*     analog signal, for a 10ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetKL30BG_V_10ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_KL30BG_V_IIR10_INDEX, KU8_KL30BG_V_IIR10_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the KL30BG_V
*     analog signal, for a 100ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetKL30BG_V_100ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_KL30BG_V_IIR100_INDEX, KU8_KL30BG_V_IIR100_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the Motor_Vp
*     analog signal, for a 2ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMotor_Vp_2ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_MOTOR_VP_IIR2_INDEX, KU8_MOTOR_VP_IIR2_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the Motor_Vp
*     analog signal, for a 20ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMotor_Vp_20ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_MOTOR_VP_IIR20_INDEX, KU8_MOTOR_VP_IIR20_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the Motor_Vp
*     analog signal, for a 100ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMotor_Vp_100ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_MOTOR_VP_IIR100_INDEX, KU8_MOTOR_VP_IIR100_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the Motor_Vn
*     analog signal, for a 2ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMotor_Vn_2ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_MOTOR_VN_IIR2_INDEX, KU8_MOTOR_VN_IIR2_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the Motor_Vn
*     analog signal, for a 20ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMotor_Vn_20ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_MOTOR_VN_IIR20_INDEX, KU8_MOTOR_VN_IIR20_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the Motor_Vn
*     analog signal, for a 100ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMotor_Vn_100ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_MOTOR_VN_IIR100_INDEX, KU8_MOTOR_VN_IIR100_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the Motor_Ip
*     analog signal, for a 10ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMotor_Ip_10ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_MOTOR_IP_IIR10_INDEX, KU8_MOTOR_IP_IIR10_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the Motor_In
*     analog signal, for a 10ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMotor_In_10ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_MOTOR_IN_IIR10_INDEX, KU8_MOTOR_IN_IIR10_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the HBS_A_V
*     analog signal, for a 10ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetHBS_A_V_10ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_HBS_A_V_IIR10_INDEX, KU8_HBS_A_V_IIR10_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the HBS_A_V
*     analog signal, for a 100ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetHBS_A_V_100ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_HBS_A_V_IIR100_INDEX, KU8_HBS_A_V_IIR100_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the HBS_B_V
*     analog signal, for a 10ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetHBS_B_V_10ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_HBS_B_V_IIR10_INDEX, KU8_HBS_B_V_IIR10_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the HBS_B_V
*     analog signal, for a 100ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetHBS_B_V_100ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = IIR_GET_RESULT(KU8_HBS_B_V_IIR100_INDEX, KU8_HBS_B_V_IIR100_DIVISOR);
}

/*!****************************************************************************
* @details
*     This function shall provide the filtered value of the Mcu_T
*     analog signal, for a 10ms periodic usage.
* @param[in]
*     none
* @param[out]
*     pu16SampledSignal : Output value address
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void AdcIf_runGetMcu_T_10ms(u16SampledSignalType * pu16SampledSignal)
{
   *pu16SampledSignal = (u16SampledSignalType)astLastResList1[TEMP_SENSOR_Vlevel];
}

#define AdcIf_STOP_SEC_CODE
#include "AdcIf_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
