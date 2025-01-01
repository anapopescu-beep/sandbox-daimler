
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

*/
/* PRQA S 0288 -- */
/*!****************************************************************************

@details
   <Describes details of this module 'Template.c' file within overall
    context of component implementation>

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/

#include "AdcIf.h"
#include "AdcIf_cfg.h"
#include "Rte_AdcIf.h"
#include "Os.h"
#include "Adc.h"
#include "Dma.h"
#include "SchM_Dma.h"
#include "common.h"
#include "Irq_Cfg.h"
#include "Nvp_Generated.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/

#define KU8_2MS_FACTOR            ((uint8)2)
#define KU8_10MS_FACTOR            ((uint8)10)
#define KU8_20MS_FACTOR            ((uint8)20)

#define KB8_PYRO_DEVICE_NOT_ACTIVATED 85U
#define KB8_PYRO_DEVICE_ACTIVATED 170U

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
/* Buffers for raw ADC results used by DMA */
uint16 BufferList0[DMA0_ELEM];
uint16 BufferList1[DMA1_ELEM];
uint16 BufferList2[DMA2_ELEM];

/* Source & Destination offsets */
uint8 SrceOffset[ADC_TOTAL];
uint8 DestOffset[ADC_TOTAL];

/* Buffers to store the read ADC values */
uint16 astLastResList0[ADC0_ELEM];
uint16 astLastResList1[ADC1_ELEM];
uint16 astLastResList2[ADC2_ELEM];

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/


/******************************************************************************
IMPLEMENTATION
******************************************************************************/

void AdcIf_Init(void)
{
   /* Init configuration */
   AdcIf_cfg_InitResults();
	AdcIf_cfg_IIRInit();

   /* Calibrate ADC */
   Adc_TriggerStartupCal();
   while (Adc_GetStartupCalStatus() != ADC_STARTUP_CALIB_OVER)
   {
      /* Wait till the StartUp calibration is over */
   }

   /* Offset calculation for determining the index mapping in buffers */
   SrceOffset[ADC_GROUP0] = (MASK_DMA0 - ((uint32)&BufferList0[ADC0_ELEM - 1] & MASK_DMA0))/2;
   DestOffset[ADC_GROUP0] = SrceOffset[ADC_GROUP0] + 1;

   SrceOffset[ADC_GROUP1] = (MASK_DMA1 - ((uint32)&BufferList1[ADC1_ELEM - 1] & MASK_DMA1))/2;
   DestOffset[ADC_GROUP1] = SrceOffset[ADC_GROUP1] + 1;

   SrceOffset[ADC_GROUP2] = (MASK_DMA2 - ((uint32)&BufferList2[ADC2_ELEM - 1] & MASK_DMA2))/2;
   DestOffset[ADC_GROUP2] = SrceOffset[ADC_GROUP2] + 1;

   /* Set ADC End Of Conversion as trigger for DMA */
   SRC_VADCG0SR0.B.TOS = 1; /* DMA as Service Provider */
   SRC_VADCG0SR0.B.SRPN = 0; /* DMA Channel as Result Priority */
   
   SRC_VADCG1SR0.B.TOS = 1; /* DMA as Service Provider */
   SRC_VADCG1SR0.B.SRPN = 1; /* DMA Channel as Result Priority */
   
   SRC_VADCG8SR0.B.TOS = 1; /* DMA as Service Provider */
   SRC_VADCG8SR0.B.SRPN = 2; /* DMA Channel as Result Priority */
   
   /* Enable DMA channels */
   Dma_ChEnableHardwareTrigger(0);
   Dma_ChEnableHardwareTrigger(1);
   Dma_ChEnableHardwareTrigger(2);

   /* Enable ADC Interrupts */
   SRC_VADCG0SR0.B.SRE = 1;
   SRC_VADCG1SR0.B.SRE = 1;
   SRC_VADCG8SR0.B.SRE = 1;

   /* Start ADC conversion */
	Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_0);
   Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_1);
	Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_2);
}

void AdcIf_MainFunction(void)
{
	uint8 i;
   static uint8 u8IIRPeriodCnt = KU8_ZERO;
	b8PyroActivationStatusType b8PyroActivationStatus;
	static b8PyroActivationStatusType M_b8PreviousPyroActivationStatus = KB8_PYRO_DEVICE_NOT_ACTIVATED;

   /* Get Pyro activation status*/
	Rte_Call_pclPyroDevice_GetPyroActivationStatus(&b8PyroActivationStatus);

   /* If the pyro device is fired (priority is set to the motor braking sequence) */
   if (KB8_PYRO_DEVICE_ACTIVATED == b8PyroActivationStatus)
   {
      /* Execution of the motor braking sequence */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
      Rte_Call_pclSynchronousMotorControl_ExecuteEmergencyBrakingSequence();
   }
      /* If the pyro device is NOT fired (nominal case) */
   else
   {
      /* If pyro device was activated and 2s timeout expired -> reset motor stage status */
      if(KB8_PYRO_DEVICE_ACTIVATED == M_b8PreviousPyroActivationStatus)
      {
         /* Reset motor stage status */
         /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
         Rte_Call_pclSynchronousMotorControl_ResetMotorStageStatus();
      }

      /* Pyro device is not activated and motor stage status has been reset */
      else if (KB8_PYRO_DEVICE_NOT_ACTIVATED == M_b8PreviousPyroActivationStatus)
      {
         /* If Boost function is activated */
         if (B_TRUE == CALIB_BLOCK_ID_BOOST_ACTIVATION_RomBlockData.NVP_u8BoostActivation)
         {
            /* Call to the High Power function */
            /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
            Rte_Call_pclSynchronousMotorControl_ExecuteHighPowerStep();
         }
         else
         {
            /* Do nothing */
         }
      }

      else
      {
         /* Do nothing */
      }
   }
   /* Update value of previous pyro status with the new one */
   M_b8PreviousPyroActivationStatus = b8PyroActivationStatus;

   /* Get ADC results */
   SchM_Enter_Dma_ChEventStatus();

   /* ADC GR0 with DMA CH0 */
   for (i=0; i<ADC0_ELEM; i++)
   {
      astLastResList0[(i+DestOffset[ADC_GROUP0])%ADC0_ELEM]=(BufferList0[(i+SrceOffset[ADC_GROUP0])%DMA0_ELEM] >> 2);
   }

   /* ADC GR1 with DMA CH1 */
   for (i=0; i<ADC1_ELEM; i++)
   {
      astLastResList1[(i+DestOffset[ADC_GROUP1])%ADC1_ELEM]=(BufferList1[(i+SrceOffset[ADC_GROUP1])%DMA1_ELEM] >> 2);
   }

   /* ADC GR2 with DMA CH2 */
   for (i=0; i<ADC2_ELEM; i++)
   {
      astLastResList2[(i+DestOffset[ADC_GROUP2])%ADC2_ELEM]=(BufferList2[(i+SrceOffset[ADC_GROUP2])%DMA2_ELEM] >> 2);
   }   

   SchM_Exit_Dma_ChEventStatus();

   /* Apply IIR filter on Motor IP */
   AdcIf_cfg_IIRFilterIpEvery1ms();

   /* Apply IIR filter on other signals */
   AdcIf_cfg_IIRFilterEvery1ms();

   /* Run the battery supervision */
   Rte_Call_pclSurveyBatteryVoltage_Monitor();

   /* Run the battery supervision */
   Rte_Call_pclSystemContextSuperviseKL30bg_SuperviseKL30bg(astLastResList1[KL30_Vlevel]);

   /* High power step regulation */
   Rte_Call_pclSynchronousMotorControl_ExecuteHighPowerStep();

   /* Executes 2ms updates 1/2 of time */
	if (KU8_ZERO == (u8IIRPeriodCnt % KU8_2MS_FACTOR))
	{
		AdcIf_cfg_IIRFilterEvery2ms();
	}

	/* Executes 10ms updates 1/10 of time */
	if (KU8_ZERO == (u8IIRPeriodCnt % KU8_10MS_FACTOR))
	{
	   AdcIf_cfg_IIRFilterEvery10ms();
	}

	/* Overflow intended */
	u8IIRPeriodCnt++;
}
