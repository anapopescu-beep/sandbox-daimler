/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version:
Template version: AEM_PROCESS_1.17.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2021-10
******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.4.6.25 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/PAL/Implementation/src/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup PAL_Autotests.c PAL
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_PAL_AC_PowerAbstractionLayer.h"
#include "PAL_private.h"
#include "Nvp_Generated.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
#define PAL_KU16_MAX_ADC_VALUE                               ((uint16)  1024) /* lsb  */
#define PAL_KU16_MAX_ANALOG_CH_VALUE                         ((uint16)  5000) /* [mV] */

#define PAL_KU16_DEFAULT_HW_SELF_PROT_THRS                   ((uint16)   819) /* 4[V]*1024/5[V] */

/* Used for MOSFET Open Circuit state machine */
#define PAL_KU8_OCAT_PREPARE_STEP_1                          ((uint8)1)
#define PAL_KU8_OCAT_EXECUTE_STEP_1_PREPARE_STEP_2           ((uint8)2)
#define PAL_KU8_OCAT_EXECUTE_STEP_2_PREPARE_STEP_3           ((uint8)3)
#define PAL_KU8_OCAT_EXECUTE_STEP_3_PREPARE_STEP_4           ((uint8)4)
#define PAL_KU8_OCAT_EXECUTE_STEP_4                          ((uint8)5)

/* Motor disengagement auto-test parameters */
#define PAL_KU8_EIGHTY                                       ((uint8) 80)
#define PAL_KU8_DIVIDE_BY_64_RIGHT_SHIFT                     ((uint8) 6)
#define PAL_KU8_CONVERT_IN_PERCENT                           ((uint8) 100)

/* Motor current autotest parameters */
#define PAL_KU32_CONVERT_A_TO_MA                             ((uint32) 1000)
#define PAL_KU32_CONVERT_MS_TO_100_MS                        ((uint32) 100)
#define PAL_KU8_PERIODICITY_10_MS                            ((uint8)  10)

/* Motor Short Circuit autotest parameters */
#define PAL_KU32_SIXTEEN                                     ((uint32)16)
/* To select the minimum resistance from the related NVM parameters */
#define PAL_KU8_MOTOR_SHORT_CIRCUIT_RESITANCE_MIN_IDX        ((uint8) 0)
/* Multiplication factor used to convert a duty cycle into PWM order */
#define PAL_KU8_CONVERT_DUTY_CYCLE_TO_PWM_ORDER_FACTOR       ((uint8)64)

/* Used for High Side Switch state machine */
#define PAL_KU8_HIGH_SIDE_SW_REG_INIT                        ((uint8)0)
#define PAL_KU8_HIGH_SIDE_SW_REG_ACTIVATION_STEP_1           ((uint8)1)
#define PAL_KU8_HIGH_SIDE_SW_REG_ALGO_STEP_2                 ((uint8)2)
#define PAL_KU8_HIGH_SIDE_SW_REG_DEAD_TIME                   ((uint8)3)

/*  High Side Switch Free wheeling phase parameters */
#define PAL_KU8_HIGH_SIDE_SW_REG_FREE_WHEELING_PRESCALER     ((uint8)20)

/******************************************************************************
MODULE TYPES
******************************************************************************/
#define PAL_AC_PowerAbstractionLayer_START_SEC_VAR_UNSPECIFIED
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"

/* QAC_WARNING S 2022 1 */ /* These data could be needed in the whole pal module */
PAL_tAutoTestData PAL_Cfg_AT_InternalData;

#define PAL_AC_PowerAbstractionLayer_STOP_SEC_VAR_UNSPECIFIED
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
#define PAL_AC_PowerAbstractionLayer_START_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"
/**
 * \brief
 *		Manage high current failure detection
 */
static uint8 pal_u8MotorCurrent_ManageHighCurrentFailureDetection(const uint32 cu32PhysicalMotorCurrent_mA);
/**
 * \brief
 *		Manage medium current failure detection
 */
static uint8 pal_u8MotorCurrent_ManageMediumCurrentFailureDetection(const uint32 cu32PhysicalMotorCurrent_mA);
/**
 * \brief
 *		Manage medium pwm  failure detection
 */
static uint8 pal_u8MotorOrder_ManageMediumPWMFailureDetection(const uint8 ku8AbsoluteValue_MotorPWMOrder_Percent);
/**
 * \brief
 *		Manage high pwm failure detection
 */
static uint8 pal_u8MotorOrder_ManageHighPWMFailureDetection(const uint8 ku8AbsoluteValue_MotorPWMOrder_Percent);
/**
 * \brief
 *		Power stage in self protection status
 */
static boolean pal_bIsPowerStageInSelfProtection(void);
/**
 * \brief
 *		Manage high side free wheeling phase
 */
static void pal_HighSideSWRegFreeWheelingPhase(void);
/**
 * \brief
 *		High side step 1
 */
static uint8 pal_u8HighSideSWRegStep_1(void);
/**
 * \brief
 *		High side step 2
 */
static uint8 pal_u8HighSideSWRegStep_2(void);

#define PAL_AC_PowerAbstractionLayer_STOP_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

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
/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_START_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"

/**
 * \brief
 *	    This function aims at manage a time counter and a reset counter to detect if the motor has been over a "medium current threshold"
 *  for more than the associated "medium current time threshold", since the last time the motor current was continuously under or equal to the
 *  "medium current threshold" for a "medium current reset time threshold".
 *
 * \param
 * 		const uint32 cu32PhysicalMotorCurrent_mA
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *      The result value on uint8 with the ATM return value format
 *      B_TRUE : Self protection detected
 *      B_FALSE: No self protection detected
 */
static uint8 pal_u8MotorCurrent_ManageMediumCurrentFailureDetection(const uint32 cu32PhysicalMotorCurrent_mA)
{
   /* The value to be returned at the end of the function */
   uint8 pal_u8ReturnState = KU8_ATM_TEST_NOT_DECIDED;

   /* Check if the PWM order is over medium threshold */
   /* Label: COD_ATE_02020 */
   if (cu32PhysicalMotorCurrent_mA > (NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8MotorCurrentMediumThrs * PAL_KU32_CONVERT_A_TO_MA))
   {
      /* Motor current is over medium current threshold */
      /* Reset the medium reset counter */
      PAL_Cfg_AT_InternalData.u16MotorCurrentMediumThrsTimeResetCounter = KU16_ZERO;

      /* Check if the time threshold for medium current is reached */
      if (PAL_Cfg_AT_InternalData.u32MotorCurrentMediumThrsTimeCounter >= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u32MotorCurrentMediumMaxDuration)
      {
         /* Time threshold for medium current is reached: set the return value to "NOK" */
         pal_u8ReturnState = KU8_ATM_TEST_NOK;
      }
      else
      {
         /* Increment the medium time counter */
         PAL_Cfg_AT_InternalData.u32MotorCurrentMediumThrsTimeCounter += ((uint32)PAL_KU8_PERIODICITY_10_MS);

         /* Time threshold for medium PWM is not reached: set the return value to "Not Decided" */
         pal_u8ReturnState = KU8_ATM_TEST_NOT_DECIDED;
      }
   }
   else
   {
      /* Motor current is below medium current threshold */

      /* Check if the medium current reset time is reached */
      if (PAL_Cfg_AT_InternalData.u16MotorCurrentMediumThrsTimeResetCounter >= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorCurrentMediumResetTime)
      {
         /* medium PWM reset time is reached: reset qualification counter only */
         PAL_Cfg_AT_InternalData.u32MotorCurrentMediumThrsTimeCounter = KU32_ZERO;

         /* The medium current reset time counter has reached its maximum */
         /* and the current is below medium threshold */
         /* so return OK */
         pal_u8ReturnState = KU8_ATM_TEST_OK;
      }
      else
      {
         /* Time counter is started: increment the medium reset counter */
         PAL_Cfg_AT_InternalData.u16MotorCurrentMediumThrsTimeResetCounter += ((uint16)PAL_KU8_PERIODICITY_10_MS);

         /* Return "Not Decided" */
         pal_u8ReturnState = KU8_ATM_TEST_NOT_DECIDED;
      }
   }

   /* Return the computed return value */
   return (pal_u8ReturnState);
}

/**
 * \brief
 *	    This function aims at manage a time counter and a reset counter to detect if the motor has been over a "high current threshold"
 *  for more than the associated "high current time threshold", since the last time the motor current was continuously under or equal to the
 *  "high current threshold" for a "high current reset time threshold".
 * \param
 * 		const uint32 cu32PhysicalMotorCurrent_mA
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *      The result value on uint8 with the ATM return value format
 *      B_TRUE : Self protection detected
 *      B_FALSE: No self protection detected
 */
static uint8 pal_u8MotorCurrent_ManageHighCurrentFailureDetection(const uint32 cu32PhysicalMotorCurrent_mA)
{
   /* The value to be returned at the end of the function */
   uint8 pal_u8ReturnState = KU8_ATM_TEST_NOT_DECIDED;

   /* Check if the motor current is over high threshold */
   if (cu32PhysicalMotorCurrent_mA > (NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8MotorCurrentHighThrs * PAL_KU32_CONVERT_A_TO_MA))
   {
      /* Motor current is over high current threshold */

      /* Reset the high reset counter */
      PAL_Cfg_AT_InternalData.u16MotorCurrentHighThrsTimeResetCounter = KU16_ZERO;

      /* Check if the time threshold for high motor current is reached */
      if (PAL_Cfg_AT_InternalData.u16MotorCurrentHighThrsTimeCounter >= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorCurrentHighMaxDuration)
      {
         /* Time threshold for high PWM is reached: set the return value to "NOK" */
         pal_u8ReturnState = KU8_ATM_TEST_NOK;
      }
      else
      {
         /* Increment the high time counter */
         PAL_Cfg_AT_InternalData.u16MotorCurrentHighThrsTimeCounter += ((uint16)PAL_KU8_PERIODICITY_10_MS);

         /* Time threshold for high current is not reached: set the return value to "Not Decided" */
         /* Label: COD_ATE_02036 */
         pal_u8ReturnState = KU8_ATM_TEST_NOT_DECIDED;
      }
   }
   else
   {
      /* Motor current is below or equal to high current threshold */
      /* Check if the high current reset time is reached */
      if (PAL_Cfg_AT_InternalData.u16MotorCurrentHighThrsTimeResetCounter >= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorCurrentHighResetTime)
      {
         /* high PWM reset time is reached: reset qualification counter only */
         PAL_Cfg_AT_InternalData.u16MotorCurrentHighThrsTimeCounter = KU16_ZERO;

         /* so return OK */
         pal_u8ReturnState = KU8_ATM_TEST_OK;
      }
      else
      {
         /* Time counter is started: increment the high reset counter */
         PAL_Cfg_AT_InternalData.u16MotorCurrentHighThrsTimeResetCounter += ((uint16)PAL_KU8_PERIODICITY_10_MS);

         /* Return "Not Decided" */
         pal_u8ReturnState = KU8_ATM_TEST_NOT_DECIDED;
      }
   }

   /* Return the computed return value */
   /* Label: COD_ATE_02031 */
   return (pal_u8ReturnState);
}

/**
 * \brief
 *	    This function aims at manage a time counter and a reset counter to detect if the PWM order has been over a "medium current threshold"
 *  for more than the associated "medium current time threshold", since the last time the PWM order was continuously under or equal to the
 *  "medium current threshold" for a "medium current reset time threshold".
 * \param
 * 		const uint8 ku8AbsoluteValue_MotorPWMOrder_Percent
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *      The result value on uint8 with the ATM return value format
 *      ATM_U8_NOK : failure detected
 *      ATM_U8_NOT_DECIDED: no failure detected
 */
static uint8 pal_u8MotorOrder_ManageMediumPWMFailureDetection(const uint8 ku8AbsoluteValue_MotorPWMOrder_Percent)
{
   /* The value to be returned at the end of the function */
   uint8 u8ReturnValue;

   /* Check if the PWM order is over medium threshold */
   if (ku8AbsoluteValue_MotorPWMOrder_Percent > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8checkMotorOrderMediumThrs)
   {
      /* PWM order is over medium PWM threshold */
      /* Reset the medium reset counter */
      PAL_Cfg_AT_InternalData.u16MotorOrderMediumThrsTimeResetCounter = KU16_ZERO;

      /* Check if the time threshold for medium PWM is reached */
      if (PAL_Cfg_AT_InternalData.u32MotorOrderMediumThrsTimeCounter >= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u32CheckMotorOrderMediumMaxDuration)
      {
         /* Time threshold for medium PWM is reached: set the return value to "NOK" */
         u8ReturnValue = KU8_ATM_TEST_NOK;
      }
      else
      {
         /* Increment the medium time counter */
         PAL_Cfg_AT_InternalData.u32MotorOrderMediumThrsTimeCounter += PAL_KU8_PERIODICITY_10_MS;

         /* Time threshold for medium PWM is not reached: set the return value to "Not Decided" */
         u8ReturnValue = KU8_ATM_TEST_NOT_DECIDED;
      }
   }
   else
   {
      /* PWM order is below or equal to medium PWM threshold */

      /* Check if the medium PWM reset time is reached */
      if (PAL_Cfg_AT_InternalData.u16MotorOrderMediumThrsTimeResetCounter >= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16CheckMotorOrderMediumResetTime)
      {
         /* medium PWM reset time is reached: reset qualification counter only */
         PAL_Cfg_AT_InternalData.u32MotorOrderMediumThrsTimeCounter = KU32_ZERO;

         /* The medium current reset time counter has reached its maximum */
         /* and the current is below medium threshold */
         /* so return OK */
         u8ReturnValue = KU8_ATM_TEST_OK;
      }
      else
      {
         /* Time counter is started: increment the medium reset counter */
         PAL_Cfg_AT_InternalData.u16MotorOrderMediumThrsTimeResetCounter += PAL_KU8_PERIODICITY_10_MS;

         /* Return "Not Decided" */
         u8ReturnValue = KU8_ATM_TEST_NOT_DECIDED;
      }
   }

   /* Return the computed return value */
   return (u8ReturnValue);
}

/**
 * \brief
 *	    This function aims at manage a time counter and a reset counter to detect if the PWM order has been over a "high current threshold"
 *  for more than the associated "high current time threshold", since the last time the PWM order was continuously under or equal to the
 *  "high current threshold" for a "high current reset time threshold".
 * \param
 * 		const uint8 ku8AbsoluteValue_MotorPWMOrder_Percent
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *      The result value on uint8 with the ATM return value format
 *      ATM_U8_NOK : failure detected
 *      ATM_U8_NOT_DECIDED: no failure detected
 */
static uint8 pal_u8MotorOrder_ManageHighPWMFailureDetection(const uint8 ku8AbsoluteValue_MotorPWMOrder_Percent)
{
   /* The value to be returned at the end of the function */
   uint8 u8ReturnValue;

   /* Check if the PWM order is over high threshold */
   if (ku8AbsoluteValue_MotorPWMOrder_Percent > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8CheckMotorOrderHighThrs)
   {
      /* PWM order is over high PWM threshold */
      /* Reset the high reset counter */
      PAL_Cfg_AT_InternalData.u16MotorOrderHighThrsTimeResetCounter = KU16_ZERO;

      /* Check if the time threshold for high PWM is reached */
      if (PAL_Cfg_AT_InternalData.u16MotorOrderHighThrsTimeCounter >= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16CheckMotorOrderHighMaxDuration)
      {
         /* Time threshold for high PWM is reached: set the return value to "NOK" */
         u8ReturnValue = KU8_ATM_TEST_NOK;
      }
      else
      {
         /* PWM order is over high PWM threshold */
         /* Increment the high time counter */
         PAL_Cfg_AT_InternalData.u16MotorOrderHighThrsTimeCounter += PAL_KU8_PERIODICITY_10_MS;

         /* Time threshold for high PWM is not reached: set the return value to "Not Decided" */
         u8ReturnValue = KU8_ATM_TEST_NOT_DECIDED;
      }
   }
   else
   {
      /* PWM order is below or equal to high PWM threshold */
      /* Check if the high PWM reset time is reached */
      if (PAL_Cfg_AT_InternalData.u16MotorOrderHighThrsTimeResetCounter >= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16CheckMotorOrderHighResetTime)
      {
         /* high PWM reset time is reached: reset qualification counter only */
         PAL_Cfg_AT_InternalData.u16MotorOrderHighThrsTimeCounter = KU16_ZERO;

         /* The medium current reset time counter has reached its maximum */
         /* and the current is below medium threshold */
         /* so return OK */
         u8ReturnValue = KU8_ATM_TEST_OK;
      }
      else
      {
         /* Time counter is started: increment the high reset counter */
         PAL_Cfg_AT_InternalData.u16MotorOrderHighThrsTimeResetCounter += PAL_KU8_PERIODICITY_10_MS;

         /* Return "Not Decided" */
         u8ReturnValue = KU8_ATM_TEST_NOT_DECIDED;
      }
   }

   /* Return the computed return value */
   return (u8ReturnValue);
}

/**
 * \brief
 *	    This function aims at detect the HW self protection
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *      The result value on uint8 with the ATM return value format
 *      B_TRUE : Self protection detected
 *      B_FALSE: No self protection detected
 */
static boolean pal_bIsPowerStageInSelfProtection(void)
{
   /* Current sense thrs after rescaling */
   uint16 pal_u16CurrentSenseThrs;

   /* Analog signal */
   uint16 pal_u16InternalAnalogSignalIn;
   uint16 pal_u16InternalAnalogSignalIp;

   boolean pal_bReturnValue;

   /* Rescale Self protection thrs in LSB */
   if (PAL_KU16_MAX_ANALOG_CH_VALUE > CALIB_BLOCK_ID_ECU_PROPERTIES_RomBlockData.NVP_u16HWSelfProtectionCurrentThrs)
   {
      pal_u16CurrentSenseThrs = (uint16)(((uint32)CALIB_BLOCK_ID_ECU_PROPERTIES_RomBlockData.NVP_u16HWSelfProtectionCurrentThrs * (uint32)PAL_KU16_MAX_ADC_VALUE) / ((uint32)PAL_KU16_MAX_ANALOG_CH_VALUE));
   }
   else
   {
      pal_u16CurrentSenseThrs = PAL_KU16_DEFAULT_HW_SELF_PROT_THRS;
   }

   /* Capture I sense on H-Bridge */
   Rte_Call_pclMotor_In_raw_Get_10ms(&pal_u16InternalAnalogSignalIn);
   Rte_Call_pclMotor_Ip_raw_Get_10ms(&pal_u16InternalAnalogSignalIp);

   /* Check the hardware self protection status */
   if ((pal_u16InternalAnalogSignalIn < pal_u16CurrentSenseThrs) &&
       (pal_u16InternalAnalogSignalIp < pal_u16CurrentSenseThrs))
   {
      /* HW protection not activated, return B_FALSE */
      /* [COVERS: DSG_PAL_0022] */
      PAL_Cfg_InternalData.bIsPwrStgInSelfProtection = B_FALSE;
      pal_bReturnValue = B_FALSE;
   }
   else
   {
      /* HW protection activated on almost one half bridge, return B_TRUE */
      /* [COVERS: DSG_PAL_0023, DSG_PAL_0024] */
      PAL_Cfg_InternalData.bIsPwrStgInSelfProtection = B_TRUE;
      pal_bReturnValue = B_TRUE;
   }

   return pal_bReturnValue;
}

/**
 * \brief
 *	    This function is called in case of a failed occurrence of HS SW auto test
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *     None
 */
static void pal_HighSideSWRegFreeWheelingPhase(void)
{
   /* Check if start free wheeling is needed */
   if (PAL_CFG_FREEWHEELING_TIME == PAL_Cfg_AT_InternalData.u8HighSideSw_FreeWheelingTimer)
   {
      /* Set Both half bridge in free wheeling state */
      PAL_StartFreeWheelingState();

      /* Free wheeling phase still in progress decrease the timer */
      PAL_Cfg_AT_InternalData.u8HighSideSw_FreeWheelingTimer -= PAL_KU8_HIGH_SIDE_SW_REG_FREE_WHEELING_PRESCALER;
   }
   else if (PAL_Cfg_AT_InternalData.u8HighSideSw_FreeWheelingTimer >= PAL_KU8_HIGH_SIDE_SW_REG_FREE_WHEELING_PRESCALER)
   {
      /* Free wheeling phase still in progress decrease the timer */
      PAL_Cfg_AT_InternalData.u8HighSideSw_FreeWheelingTimer -= PAL_KU8_HIGH_SIDE_SW_REG_FREE_WHEELING_PRESCALER;

      /* Stay in current state */
   }
   else
   {
      /* End of Free wheeling phase */
      /* Reset free wheeling timer */
      PAL_Cfg_AT_InternalData.u8HighSideSw_FreeWheelingTimer = PAL_CFG_FREEWHEELING_TIME;

      /* Reset power stage activation */
      PAL_DisablePowerStage();

      /* Go to activation state */
      PAL_Cfg_AT_InternalData.u8HighSideSw_TestState = PAL_KU8_HIGH_SIDE_SW_REG_ACTIVATION_STEP_1;
   }
}

/**
 * \brief
 *	    This function has to manage the step 1 for HS SW auto test
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *      The result value on uint8 with the ATM return value format
 *      B_TRUE : Self protection detected
 *      B_FALSE: No self protection detected
 */
static uint8 pal_u8HighSideSWRegStep_1(void)
{
   /* To store the high side switch voltage */
   uint16 u16HSSWLevel;

   /* To store actual step result */
   u8TestResultType u8StepResult = KU8_ATM_TEST_NOT_DECIDED;

   Dio_WriteChannel (DioConf_DioChannel_KL30_SW_EN,STD_LOW);

   /*  Get the HS_SW level */
   Rte_Call_pclHS1_V_Get(&u16HSSWLevel);

   /* Check [HS_SW] > NVP_u16HSSWRegTestInitThreshold */
   if (NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HSSWRegTestInitThreshold < u16HSSWLevel)
   {
      /* High side switch level not equal to 0, activation disabled => return NOT_OK  */
      PAL_Cfg_AT_InternalData.u8HighSideSw_NbTries++;

      /* Test if the maximum number of try is reached */
      if (PAL_Cfg_AT_InternalData.u8HighSideSw_NbTries < NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8HSSWRegMaxTries)
      {
         /* Go to DEAD TIME state */
         PAL_Cfg_AT_InternalData.u8HighSideSw_TestState = PAL_KU8_HIGH_SIDE_SW_REG_DEAD_TIME;

         /* Return NOT_DECIDED */
         u8StepResult = KU8_ATM_TEST_NOT_DECIDED;
      }
      else
      {
         /* Maximum number of tries reached, test not successful, return NOK */
         u8StepResult = KU8_ATM_TEST_NOK;
      }
   }
   else
   {
      Dio_WriteChannel (DioConf_DioChannel_KL30_SW_EN,STD_HIGH);

      /* Go to next state */
      PAL_Cfg_AT_InternalData.u8HighSideSw_TestState = PAL_KU8_HIGH_SIDE_SW_REG_ALGO_STEP_2;

      /* Return NOT_DECIDED */
      u8StepResult = KU8_ATM_TEST_NOT_DECIDED;
   }

   return (u8StepResult);
}

/**
 * \brief
 *	    This function has to manage the step 2 for HS SW auto test
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *      The result value on uint8 with the ATM return value format
 *      B_TRUE : Self protection detected
 *      B_FALSE: No self protection detected
 */
static uint8 pal_u8HighSideSWRegStep_2(void)
{
   /* To store the high side switch voltage */
   uint16 u16HSSWLevel;
   /* This is the filtered physical value measured on ADC Power Vbat pin that will
        be provided by PMP */
   u16VoltageType u16FilteredVbatPowerVoltage;
   /* To store actual step result */
   u8TestResultType u8StepResult = KU8_ATM_TEST_NOT_DECIDED;

   /* Get the HS_SW level */
   Rte_Call_pclHS1_V_Get(&u16HSSWLevel);

   Rte_Call_pclKL30_V_Get_10ms(&u16FilteredVbatPowerVoltage);

   if (((u16FilteredVbatPowerVoltage - (u16FilteredVbatPowerVoltage / KU8_FIVE)) < u16HSSWLevel) &&
       ((u16FilteredVbatPowerVoltage + (u16FilteredVbatPowerVoltage / KU8_FIVE)) > u16HSSWLevel))
      /* [COVERS: DSG_PAL_0052] */

   {
      /* Keep High Side switch EN_HS_SW ON */

      /* High Side SW voltage is inside the functional range, return OK */
      u8StepResult = KU8_ATM_TEST_OK;
   }
   else
   {
      PAL_Cfg_AT_InternalData.u8HighSideSw_NbTries++;

      /* Test if the maximum number of try is reached */
      if (PAL_Cfg_AT_InternalData.u8HighSideSw_NbTries < NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8HSSWRegMaxTries)
      {
         Dio_WriteChannel (DioConf_DioChannel_KL30_SW_EN,STD_LOW);
         
         /* Wait a delay before retrying the test, go to DEAD time state */
         PAL_Cfg_AT_InternalData.u8HighSideSw_TestState = PAL_KU8_HIGH_SIDE_SW_REG_DEAD_TIME;

         /* Return NOT_DECIDED */
         u8StepResult = KU8_ATM_TEST_NOT_DECIDED;
      }
      else
      {
         /* Maximum number of tries reached, test not successful, return NOK */
         u8StepResult = KU8_ATM_TEST_NOK;

         Dio_WriteChannel (DioConf_DioChannel_KL30_SW_EN,STD_LOW);
      }
   }

   return (u8StepResult);
}

/**
 * \brief
 *	   This function initializes all static data used during PAL auto tests.
 * \param
 * 		const uint32 cu32PhysicalMotorCurrent_mA
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
void pal_AT_Init(void)
{
   /* Initialization of static data for auto tests execution */
   PAL_Cfg_AT_InternalData.u8MosfetOC_NbTries                        = KU8_ZERO;
   PAL_Cfg_AT_InternalData.u8MosfetOC_State                          = PAL_KU8_OCAT_PREPARE_STEP_1;
   PAL_Cfg_AT_InternalData.u8MotorBlockedFailedCntr                  = KU8_ZERO;
   PAL_Cfg_AT_InternalData.u8MotorBlockedPassedCntr                  = KU8_ZERO;
   PAL_Cfg_AT_InternalData.u8MotorSCFailedCntr                       = KU8_ZERO;
   PAL_Cfg_AT_InternalData.u8MotorSCPassedCntr                       = NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8NbOccurenceToDeskillMotorSC;
   /* Initialization of static data for auto tests execution */
   PAL_Cfg_AT_InternalData.u8MotorBlockedFailedCntr = KU8_ZERO;
   PAL_Cfg_AT_InternalData.u8MotorBlockedPassedCntr = KU8_ZERO;

   PAL_Cfg_AT_InternalData.u8PowerOrderExecutedCycleMemory   = KU8_NO_CYCLE;
   PAL_Cfg_AT_InternalData.u8PowerCurrentExecutedCycleMemory = KU8_NO_CYCLE;

   PAL_Cfg_AT_InternalData.u16MotorOrderErrorResetTimeCounter      = KU16_ZERO;
   PAL_Cfg_AT_InternalData.u16MotorOrderHighThrsTimeCounter        = KU16_ZERO;
   PAL_Cfg_AT_InternalData.u16MotorOrderHighThrsTimeResetCounter   = KU16_ZERO;
   PAL_Cfg_AT_InternalData.u16MotorOrderMediumThrsTimeResetCounter = KU16_ZERO;
   PAL_Cfg_AT_InternalData.u32MotorOrderMediumThrsTimeCounter      = KU32_ZERO;

   PAL_Cfg_AT_InternalData.u16MotorCurrentErrorResetTimeCounter      = KU16_ZERO;
   PAL_Cfg_AT_InternalData.u16MotorCurrentHighThrsTimeCounter        = KU16_ZERO;
   PAL_Cfg_AT_InternalData.u16MotorCurrentHighThrsTimeResetCounter   = KU16_ZERO;
   PAL_Cfg_AT_InternalData.u16MotorCurrentMediumThrsTimeResetCounter = KU16_ZERO;
   PAL_Cfg_AT_InternalData.u32MotorCurrentMediumThrsTimeCounter      = KU32_ZERO;

   PAL_Cfg_AT_InternalData.u16HighSideSw_DeadTimeCounter             = KU16_ZERO;
   PAL_Cfg_AT_InternalData.u8HighSideSw_NbTries                      = KU8_ZERO;
   PAL_Cfg_AT_InternalData.u8HighSideSw_TestState                    = PAL_KU8_HIGH_SIDE_SW_REG_INIT;
   PAL_Cfg_AT_InternalData.u8HighSideSw_FreeWheelingTimer            = PAL_CFG_FREEWHEELING_TIME;
}

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
 * \brief
 *	   This function is in charge of HB Enable signals checks.
 * \param
 * 		pu8TestResult: Pointer used to store the auto test result
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		NA
 */
void PAL_Autotest_CheckCommandConsistency(u8TestResultType * pu8TestResult)
{
   uint8   u8ReadEnableHBP;
   uint8   u8ReadEnableHBN;

   /* This is the test result that will be returned */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   u8ReadEnableHBP = Dio_ReadChannel( PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16ReadEnableDioId);
   u8ReadEnableHBN = Dio_ReadChannel( PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16ReadEnableDioId);

   /* Check if power stage enable signal of the 2 Half-Bridge are consistent */
   if( (u8ReadEnableHBP == PAL_Cfg_InternalData.u8EnableCommand) &&
       (u8ReadEnableHBP == u8ReadEnableHBN                     )   )
      /* [COVERS: DSG_PAL_0041] */
   {
      /* Signals are consistent: return OK */
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }
   else
   {
      /* Signals are not consistent: return NOK */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }

   /* Return the computed test result */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
 * \brief
 *	   This function has to test the Short Circuit failure for Low Mosfets
 * \param
 * 		pu8TestResult: Pointer used to store the auto test result
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		NA
 */
void PAL_Autotest_CheckMosfetLowSC(u8TestResultType * pu8TestResult)
{
   /* This is the Ground level that will be provided by VSA */
   u16VoltageType u16FilteredGroundLevel = KU8_TEN;

   /* This is the filtered physical value measured on "Motor -" Voltage pin that will
   be provided by VSA */
   uint16 u16FilteredMotorMinusVoltage;

   /* This is the filtered physical value measured on "Motor +" Voltage pin that will
    * be provided by VSA */
   uint16 u16FilteredMotorPlusVoltage;

   /* This is the test result that will be returned */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* To store the Adc auto-test status from ATM */
   u8TestResultType u8PreviousAdcTestResult;

   /* To store High Side SW auto-test status from ATM */
   u8TestResultType u8PreviousHighSideSWTestResult;

   /* To store the Command Consistency auto-test status from ATM */
   u8TestResultType u8PreviousDriverCommandTestResult;

   /* This is a variable to hold result of Vbat and Vp voltages difference computation */
   uint16 u16DeltaVbatVp;

   /* This is a variable to hold result of Vbat and Vm voltages difference computation */
   uint16 u16DeltaVbatVm;

   /* Get Adc auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC, &u8PreviousAdcTestResult);

   /* Get High Side Switch auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_HIGH_SIDE_SWITCH, &u8PreviousHighSideSWTestResult);

   /* Get Driver Command Consistency auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_DRIVER_COMMAND, &u8PreviousDriverCommandTestResult);

   /* Check if test pre-condition are met */
   if( (KU8_ATM_TEST_OK == u8PreviousAdcTestResult)
    && (KU8_ATM_TEST_OK == u8PreviousHighSideSWTestResult)
    && (KU8_ATM_TEST_OK == u8PreviousDriverCommandTestResult))
   {

      /* Get the filtered physical value measured on "Motor +" Voltage pin from VSA */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
      Rte_Call_pclMotor_Vp_Get_100ms( &u16FilteredMotorPlusVoltage );

      /* Get the filtered physical value measured on "Motor -" Voltage pin from VSA */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
      Rte_Call_pclMotor_Vn_Get_100ms( &u16FilteredMotorMinusVoltage );

      if (u16FilteredMotorMinusVoltage >= u16FilteredGroundLevel)
      {
         u16DeltaVbatVm = u16FilteredMotorMinusVoltage - u16FilteredGroundLevel;
      }
      else
      {
         u16DeltaVbatVm = u16FilteredGroundLevel - u16FilteredMotorMinusVoltage;
      }
      if (u16FilteredMotorPlusVoltage >= u16FilteredGroundLevel)
      {
         u16DeltaVbatVp = u16FilteredMotorPlusVoltage - u16FilteredGroundLevel;
      }
      else
      {
         u16DeltaVbatVp = u16FilteredGroundLevel - u16FilteredMotorPlusVoltage;
      }

      /* Check if the voltage drop between V+ and GND && V- and GND is lower than a threshold */
      if( (u16DeltaVbatVm < NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MOSFETinSCMaxDropVoltage)
       || (u16DeltaVbatVp < NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MOSFETinSCMaxDropVoltage))
         /* [COVERS: DSG_PAL_0043] */
      {
         /* One of the mosfet is in short circuit with KL return NOK */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
      else
         /* [COVERS: DSG_PAL_0044] */
      {
         /* V+ and V- are in the correct zone, no short circuit detected with KL30
          * Return OK */
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
   }
   else
      /* [COVERS: DSG_PAL_0042] */
   {
      /* Pre-condition not met, test cannot be executed
       * return NOT_DECIDED */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   }

   /* Return the computed test result */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
 * \brief
 *	   This function has to test the Short Circuit failure for High Mosfets
 * \param
 * 		pu8TestResult: Pointer used to store the auto test result
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		NA
 */
void PAL_Autotest_CheckMosfetHighSC(u8TestResultType * pu8TestResult)
{
   /* This is the KL30 battery voltage that will be provided by VSA */
   u16VoltageType u16FilteredVbatPowerVoltage_mV;

   /* This is the filtered physical value measured on "Motor +" Voltage pin that will
   be provided by VSA */
   u16VoltageType u16FilteredMotorPlusVoltage;

   /* This is the filtered physical value measured on "Motor -" Voltage pin that will
   be provided by VSA */
   u16VoltageType u16FilteredMotorMinusVoltage;

   /* This is the test result that will be returned */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* To store the Adc auto-test status from ATM */
   u8TestResultType u8PreviousAdcTestResult;

   /* To store High Side SW auto-test status from ATM */
   u8TestResultType u8PreviousHighSideSWTestResult;

   /* To store the Command Consistency auto-test status from ATM */
   u8TestResultType u8PreviousDriverCommandTestResult;

   /* This is a variable to hold result of Vbat and Vp voltages difference computation */
   uint16 u16DeltaVbatVp;

   /* This is a variable to hold result of Vbat and Vm voltages difference computation */
   uint16 u16DeltaVbatVm;

   /* Get Adc auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC, &u8PreviousAdcTestResult);

   /* Get High Side Switch auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_HIGH_SIDE_SWITCH, &u8PreviousHighSideSWTestResult);

   /* Get Driver Command Consistency auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_DRIVER_COMMAND, &u8PreviousDriverCommandTestResult);

   /* Check if test pre-condition are met */
   if( (KU8_ATM_TEST_OK == u8PreviousAdcTestResult)
    && (KU8_ATM_TEST_OK == u8PreviousHighSideSWTestResult)
    && (KU8_ATM_TEST_OK == u8PreviousDriverCommandTestResult))
   {
      /* Get the KL30 battery voltage from VSA */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
      Rte_Call_pclKL30_V_Get_100ms( &u16FilteredVbatPowerVoltage_mV );

      /* Get the filtered physical value measured on "Motor +" Voltage pin from VSA */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
      Rte_Call_pclMotor_Vp_Get_100ms( &u16FilteredMotorPlusVoltage );

      /* Get the filtered physical value measured on "Motor -" Voltage pin from VSA */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
      Rte_Call_pclMotor_Vn_Get_100ms( &u16FilteredMotorMinusVoltage );

      if(u16FilteredVbatPowerVoltage_mV >= u16FilteredMotorMinusVoltage)
      {
         u16DeltaVbatVm = u16FilteredVbatPowerVoltage_mV - u16FilteredMotorMinusVoltage;
      }
      else
      {
         u16DeltaVbatVm = u16FilteredMotorMinusVoltage - u16FilteredVbatPowerVoltage_mV;
      }

      if(u16FilteredVbatPowerVoltage_mV >= u16FilteredMotorPlusVoltage)
      {
         u16DeltaVbatVp = u16FilteredVbatPowerVoltage_mV - u16FilteredMotorPlusVoltage;
      }
      else
      {
         u16DeltaVbatVp = u16FilteredMotorPlusVoltage - u16FilteredVbatPowerVoltage_mV;
      }

      /* Check if the voltage drop between KL30 and V+ && KL30 and V- is lower than a threshold */
      if( (u16DeltaVbatVm < NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MOSFETinSCMaxDropVoltage)
       || (u16DeltaVbatVp < NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MOSFETinSCMaxDropVoltage))
         /* [COVERS: DSG_PAL_0046] */
      {
         /* One of the mosfet is in short circuit with KL return NOK */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
      else
         /* [COVERS: DSG_PAL_0047] */
      {
         /* V+ and V- are in the correct zone, no short circuit detected with KL30
          * Return OK */
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
   }
   else
      /* [COVERS: DSG_PAL_0045] */
   {
      /* Pre-condition not met, test cannot be executed
       * return NOT_DECIDED */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
 * \brief
 *	   This function has to test the Open Circuit Auto Test on Mosfets
 * \param
 * 		pu8TestResult: Pointer used to store the auto test result
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		NA
 */
void PAL_Autotest_CheckMosfetOCAT(u8TestResultType *pu8TestResult)
{
   /* This is the KL30 battery voltage that will be provided by VSA */
   u16VoltageType u16FilteredVbatPowerVoltage_mV;

   /* This is the Ground level that will be provided by VSA */
   const u16VoltageType u16FilteredGroundLevel = KU8_TEN;

   /* This is the filtered physical value measured on "Motor +" Voltage pin that will
   be provided by VSA */
   uint16 u16FilteredMotorPlusVoltage;

   /* This is the filtered physical value measured on "Motor -" Voltage pin that will
   be provided by VSA */
   uint16 u16FilteredMotorMinusVoltage;

   /* This is a variable to hold result of Vbat and Vp voltages difference computation */
   uint16 u16DeltaVbatVp;

   /* This is a variable to hold result of Vbat and Vm voltages difference computation */
   uint16 u16DeltaVbatVm;

   /* This is the test result that will be returned */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* To store HW self protection auto-test status from ATM */
   u8TestResultType u8HWSelfProtectionStatus;

   /* To store the Motor disconnected auto-test status from ATM */
   u8TestResultType u8PreviousMotorDisconnectedTestResult;

   /* To store the Mosfet short circuit auto-tests status from ATM */
   u8TestResultType u8PreviousMosfetHighShortCircuitTestResult;
   u8TestResultType u8PreviousMosfetLowShortCircuitTestResult;

   /* To store the HB enable signals auto-test status from ATM */
   u8TestResultType u8PreviousHBEnableSignalsTestResult;

   /* To store ADC auto-test status from ATM */
   u8TestResultType u8PreviousADCTestresult;

   /* Get auto-test pre-conditons */

   /* Get the ADC auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC, &u8PreviousADCTestresult);

   /* Get the current hardware self protection auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_DRIVER_SELF_PROTECTION, &u8HWSelfProtectionStatus);

   /* Get Motor Disconnected auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_MOTOR_DISCONNECTION, &u8PreviousMotorDisconnectedTestResult);

   /* Get MOSFET short circuit auto-tests status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_MOSFET_HIGH_SHORT_CIRCUIT, &u8PreviousMosfetHighShortCircuitTestResult);
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_MOSFET_LOW_SHORT_CIRCUIT, &u8PreviousMosfetLowShortCircuitTestResult);

   /* Get HB enable signals auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_DRIVER_COMMAND, &u8PreviousHBEnableSignalsTestResult);

   /* Check if all pre-conditions are met */
   if ((KU8_ATM_TEST_OK == u8PreviousADCTestresult) && (KU8_ATM_TEST_OK == u8HWSelfProtectionStatus) && (KU8_ATM_TEST_OK == u8PreviousMotorDisconnectedTestResult) && (KU8_ATM_TEST_OK == u8PreviousMosfetHighShortCircuitTestResult) && (KU8_ATM_TEST_OK == u8PreviousMosfetLowShortCircuitTestResult) && (KU8_ATM_TEST_OK == u8PreviousHBEnableSignalsTestResult))
   {
      /* All pre-conditions are met */
      /* Get the KL30 battery voltage from VSA */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
      Rte_Call_pclKL30_V_Get_20ms(&u16FilteredVbatPowerVoltage_mV);

      /* Get the filtered physical value measured on "Motor +" Voltage pin from VSA */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
      Rte_Call_pclMotor_Vp_Get_20ms(&u16FilteredMotorPlusVoltage);

      /* Get the filtered physical value measured on "Motor -" Voltage pin from VSA */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
      Rte_Call_pclMotor_Vn_Get_20ms(&u16FilteredMotorMinusVoltage);

      switch (PAL_Cfg_AT_InternalData.u8MosfetOC_State)
      {
      case PAL_KU8_OCAT_PREPARE_STEP_1:
         /* Setup NE MOSFET and set state machine to the next state */
         Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u8PwmChannelId, PAL_CFG_HIGH_LIMIT_LLD_CMD);
         Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u8PwmChannelId, PAL_CFG_HIGH_LIMIT_LLD_CMD);

         Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16DriveEnableDioId, (uint8)STD_LOW);
         Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16DriveEnableDioId, (uint8)STD_HIGH);

         PAL_Cfg_AT_InternalData.u8MosfetOC_State = PAL_KU8_OCAT_EXECUTE_STEP_1_PREPARE_STEP_2;
         break;

      case PAL_KU8_OCAT_EXECUTE_STEP_1_PREPARE_STEP_2:

         /* Compute difference between Vbat and motor Vp */
         if (u16FilteredVbatPowerVoltage_mV >= u16FilteredMotorPlusVoltage)
         {
            u16DeltaVbatVp = u16FilteredVbatPowerVoltage_mV - u16FilteredMotorPlusVoltage;
         }
         else
         {
            u16DeltaVbatVp = u16FilteredMotorPlusVoltage - u16FilteredVbatPowerVoltage_mV;
         }

         /* Compare the result of the NE MOSFET test */
         if (u16DeltaVbatVp > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MOSFETinOCMinDropVoltage)
         {
            /* Step 1 is failed, return NOK */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
         else
         {
            /* Step 1 is passed, prepare step 2 */
            /* Setup SE MOSFET */
            Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u8PwmChannelId, KU16_ONE_HUNDRED);
            Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u8PwmChannelId, PAL_CFG_HIGH_LIMIT_LLD_CMD);

            Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16DriveEnableDioId, (uint8)STD_LOW);
            Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16DriveEnableDioId, (uint8)STD_HIGH);

            /* Go to next step */
            PAL_Cfg_AT_InternalData.u8MosfetOC_State = PAL_KU8_OCAT_EXECUTE_STEP_2_PREPARE_STEP_3;

            /* Return NOT_DECIDED */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
         }
         break;

      case PAL_KU8_OCAT_EXECUTE_STEP_2_PREPARE_STEP_3:
         /* Compare the result of the SE MOSFET test */
         if (u16FilteredMotorPlusVoltage >= u16FilteredGroundLevel)
         {
            u16DeltaVbatVp = u16FilteredMotorPlusVoltage - u16FilteredGroundLevel;
         }
         else
         {
            u16DeltaVbatVp = u16FilteredGroundLevel - u16FilteredMotorPlusVoltage;
         }

         if (u16DeltaVbatVp > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MOSFETinOCMinDropVoltage)
         {
            /* Step 2 is failed, return NOK */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
         else
         {
            /* Step 2 is passed, prepare step 3 */
            /* Setup NW MOSFET */
            Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u8PwmChannelId, PAL_CFG_HIGH_LIMIT_LLD_CMD);
            Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u8PwmChannelId, PAL_CFG_HIGH_LIMIT_LLD_CMD);

            Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16DriveEnableDioId, (uint8)STD_LOW);
            Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16DriveEnableDioId, (uint8)STD_HIGH);
            /* Go to next step */
            PAL_Cfg_AT_InternalData.u8MosfetOC_State = PAL_KU8_OCAT_EXECUTE_STEP_3_PREPARE_STEP_4;

            /* Return NOT_DECIDED */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
         }
         break;
      case PAL_KU8_OCAT_EXECUTE_STEP_3_PREPARE_STEP_4:

         /* Compute difference between Vbat and motor Vp */
         if (u16FilteredVbatPowerVoltage_mV >= u16FilteredMotorMinusVoltage)
         {
            u16DeltaVbatVm = u16FilteredVbatPowerVoltage_mV - u16FilteredMotorMinusVoltage;
         }
         else
         {
            u16DeltaVbatVm = u16FilteredMotorMinusVoltage - u16FilteredVbatPowerVoltage_mV;
         }

         /* Compare the result of the SE MOSFET test */
         if (u16DeltaVbatVm > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MOSFETinOCMinDropVoltage)
         {
            /* Step 3 is failed, return NOK */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
         else
         {
            /* Step 3 is passed, prepare step 3 */
            /* Setup SW MOSFET */
            Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u8PwmChannelId, PAL_CFG_HIGH_LIMIT_LLD_CMD);
            Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u8PwmChannelId, KU8_ZERO);

            Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16DriveEnableDioId, (uint8)STD_LOW);
            Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16DriveEnableDioId, (uint8)STD_HIGH);

            /* Go to next step */
            PAL_Cfg_AT_InternalData.u8MosfetOC_State = PAL_KU8_OCAT_EXECUTE_STEP_4;

            /* Return NOT_DECIDED */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
         }
         break;

      case PAL_KU8_OCAT_EXECUTE_STEP_4:

         if (u16FilteredMotorMinusVoltage >= u16FilteredGroundLevel)
         {
            u16DeltaVbatVm = u16FilteredMotorMinusVoltage - u16FilteredGroundLevel;
         }
         else
         {
            u16DeltaVbatVm = u16FilteredGroundLevel - u16FilteredMotorMinusVoltage;
         }
         /* Compare the result of the SE MOSFET test */
         if (u16DeltaVbatVm > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MOSFETinOCMinDropVoltage)
         {
            /* Step 3 is failed, return NOK */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
         else
         {
            /* Step 4 is OK => Whole test is OK */
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         break;

      default:
         /* This case shall never occurred, nothing to do */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
         break;
      }
   }
   else
   {
      /* One of the pre-conditions is NOK, return NOT_DECIDED */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   }

   /***********************************************************************/
   /*                           TEST OUTPUT                               */
   /***********************************************************************/
   /* Compute auto-test output */
   if (KU8_ATM_TEST_NOK == u8ResultOfAutoTest)
   {
      /* Notify that the step has failed */
      PAL_Cfg_AT_InternalData.u8MosfetOC_NbTries++;

      /* One step is failed, check if the test can be replayed */
      if (PAL_Cfg_AT_InternalData.u8MosfetOC_NbTries < NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8MOSFETinOCMaxTries)
         /* [COVERS: DSG_PAL_0048] */
      {
         /* Test can be replayed, go back to step 1 and return NOT_DECIDED */
         PAL_Cfg_AT_InternalData.u8MosfetOC_State = PAL_KU8_OCAT_PREPARE_STEP_1;

         /* Set Half Bridges in secured state */
         Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u8PwmChannelId, PAL_CFG_HIGH_LIMIT_LLD_CMD);
         Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u8PwmChannelId, PAL_CFG_HIGH_LIMIT_LLD_CMD);

         Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16DriveEnableDioId, (uint8)STD_LOW);
         Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16DriveEnableDioId, (uint8)STD_LOW);

         u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
      }
      else
         /* [COVERS: DSG_PAL_0049] */
      {
         /* Maximum number of retry reached, test is failed */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         /* Set Half Bridges in secured state */
         Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u8PwmChannelId, PAL_CFG_HIGH_LIMIT_LLD_CMD);
         Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u8PwmChannelId, PAL_CFG_HIGH_LIMIT_LLD_CMD);

         Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16DriveEnableDioId, (uint8)STD_LOW);
         Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16DriveEnableDioId, (uint8)STD_LOW);
      }
   }
   else if (KU8_ATM_TEST_OK == u8ResultOfAutoTest)
      /* [COVERS: DSG_PAL_0050] */
   {
      /* Step 4 is OK then whole test is OK */
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;

      /* Post action OK */
      /* Set Half Bridges in secured state */
      Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u8PwmChannelId, PAL_CFG_HIGH_LIMIT_LLD_CMD);
      Rte_Call_pclPwmServices_SetDutyCycle(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u8PwmChannelId, PAL_CFG_HIGH_LIMIT_LLD_CMD);

      Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16DriveEnableDioId, (uint8)STD_LOW);
      Dio_WriteChannel(PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16DriveEnableDioId, (uint8)STD_LOW);
   }
   else
      /* [COVERS: DSG_PAL_0048] */
   {
      /* Test execution still in progress */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   }

   /* Return the computed test result */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
 * \brief
 *	   This function has to test the HardWare self protection on Half Bridges
 * \param
 * 		pu8TestResult: Pointer used to store the auto test result
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		NA
 */
/* [COVERS: DSG_PAL_0021] */
void PAL_Autotest_CheckHWSelfProtection(u8TestResultType *pu8TestResult)
{
   /* This is the test result that will be returned */
   u8TestResultType pal_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* To store driver command consistency auto-test result from ATM */
   u8TestResultType pal_u8PreviousDriverCommandTestResult;

   boolean pal_IsPowerStageInSelfProtection;

   /* Get Driver Command Consistency auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_DRIVER_COMMAND, &pal_u8PreviousDriverCommandTestResult);

   /* Check if all pre-conditions are met to execute the test */
   if (KU8_ATM_TEST_OK == pal_u8PreviousDriverCommandTestResult)
   {

      pal_IsPowerStageInSelfProtection = pal_bIsPowerStageInSelfProtection();

      if (B_FALSE == pal_IsPowerStageInSelfProtection)
      {
         pal_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
      else
      {
         pal_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
   }
   else
   {
      /* At least on pre-condition is not set, return NOT_DECIDED */
      pal_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   }

   /* Return the computed test result */
   /*Label: COD_ATE_00313 */
   *pu8TestResult = pal_u8ResultOfAutoTest;
}

/**
 * \brief
 *	   This function has to test the High Side Switch regulation
 * \param
 * 		pu8TestResult: Pointer used to store the auto test result
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		NA
 */
/*COVERS: DSG_PAL_0033; DSG_PAL-0037; DSG_PAL_0054; */
void PAL_Autotest_CheckHighSideSwRegulation(u8TestResultType *pu8TestResult)
{
   /* To store the auto-test result */
   u8TestResultType u8AutoTestResult = KU8_ATM_TEST_NOT_DECIDED;

   /* To store ADC auto-test status from ATM */
   u8TestResultType u8PreviousADCTestResult;

   /* To store the last tensioning state */
   static u8CycleNumberType u8LastTensioningState = KU8_NO_CYCLE;

   /* Get ADC auto-test result */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC, &u8PreviousADCTestResult);

   /* ADC auto-test passed */
   if (KU8_ATM_TEST_OK == u8PreviousADCTestResult)
   {
      /* Run the state machine */
      switch (PAL_Cfg_AT_InternalData.u8HighSideSw_TestState)
      {
      /* Possible state transitions:
       * PAL_KU8_HIGH_SIDE_SW_REG_INIT -> PAL_KU8_HIGH_SIDE_SW_REG_INIT (Motor activation before a reset)
       * PAL_KU8_HIGH_SIDE_SW_REG_INIT -> PAL_KU8_HIGH_SIDE_SW_REG_ACTIVATION_STEP_1  (Common case)*/
      case PAL_KU8_HIGH_SIDE_SW_REG_INIT:

         /* Return Not_decided */
         u8AutoTestResult = KU8_ATM_TEST_NOT_DECIDED;

         (void)Rte_Call_pclSystemContextManagement_GetLastTensionningState(&u8LastTensioningState);

         /* Check if a cycle has been aborted by reset */
         if (KU8_NB_MAX_CYCLES >= u8LastTensioningState)
         {
            /* A tensioning cycle has been aborted by a reset, add a free wheeling phase */
            pal_HighSideSWRegFreeWheelingPhase();

            /* Stay in the same state until end of free wheeling phase */
            /* QAC_WARNING S 3333 1 */ /* Break is needed here to exit state machine here */
            break;
         }
         else
         {
            /* Everything is OK, bypass the free wheeling phase and go to High Side switch activation state */
            PAL_Cfg_AT_InternalData.u8HighSideSw_TestState = PAL_KU8_HIGH_SIDE_SW_REG_ACTIVATION_STEP_1;
         }

         /* No break here, as following action has to be executed immediately */

         /* Possible state transitions
          *   -PAL_KU8_HIGH_SIDE_SW_REG_ACTIVATION_STEP_1 -> PAL_KU8_HIGH_SIDE_SW_REG_ACTIVATION_STEP_1
          *   -PAL_KU8_HIGH_SIDE_SW_REG_ACTIVATION_STEP_1 -> PAL_KU8_HIGH_SIDE_SW_REG_ALGO_STEP_2 */
         /* QAC_WARNING S 2003 2 */ /* The preceding switch case does not finish with a break. */
         /* Goal is to execute immediately the next case if cycle has not been aborted by reset */
         /* [COVERS: DSG_PAL_0051, DSG_PAL_0053] */
      case PAL_KU8_HIGH_SIDE_SW_REG_ACTIVATION_STEP_1:

         /* Execute step 1 */
         u8AutoTestResult = pal_u8HighSideSWRegStep_1();

         break;

         /* Possible state transitions:
          *   -PAL_KU8_HIGH_SIDE_SW_REG_ALGO -> PAL_KU8_HIGH_SIDE_SW_REG_DEAD_TIME */
         /* [COVERS: DSG_PAL_0052; DSG_PAL_0051; DSG_PAL_0053] */
      case PAL_KU8_HIGH_SIDE_SW_REG_ALGO_STEP_2:

         /* Execute step 2 */
         u8AutoTestResult = pal_u8HighSideSWRegStep_2();

         break;

         /* Possible state transitions:
          *   -KU8_ATF_HIGH_SIDE_SW_REG_DEAD_TIME -> PAL_KU8_HIGH_SIDE_SW_REG_DEAD_TIME
          *   -PAL_KU8_HIGH_SIDE_SW_REG_DEAD_TIME -> PAL_KU8_HIGH_SIDE_SW_REG_ALGO */
      case PAL_KU8_HIGH_SIDE_SW_REG_DEAD_TIME:

         /* Increment the counter */
         PAL_Cfg_AT_InternalData.u16HighSideSw_DeadTimeCounter++;
         /* Wait before the next test execution */
         if (PAL_Cfg_AT_InternalData.u16HighSideSw_DeadTimeCounter > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HSSWRegTestDeadTime)
         {
            /* Delay passed, return to init state and reset the dead time counter */
            PAL_Cfg_AT_InternalData.u8HighSideSw_TestState = PAL_KU8_HIGH_SIDE_SW_REG_ACTIVATION_STEP_1;
            PAL_Cfg_AT_InternalData.u16HighSideSw_DeadTimeCounter = KU16_ZERO;
         }
         else
         {
            /* Do nothing, stay in the current state */
         }
         /* Return not decided */
         u8AutoTestResult = KU8_ATM_TEST_NOT_DECIDED;
         break;

      default:
         /* This case shall never occurs */
         break;
      }
   }
   else
   {
      /* ADC out of order, nothing to do, test output has already been assigned to NOT_DECIDED */
   }

   /* return the Autotest result */
   *pu8TestResult = u8AutoTestResult;
}

/**
 * \brief
 *	   This function has to test that the motor is present and connected
 * \param
 * 		pu8TestResult: Pointer used to store the auto test result
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		NA
 */
/*COVERS: DSG_PAL_0032 */
void PAL_Autotest_CheckMotorConnection(u8TestResultType *pu8TestResult)
{
   /* This is the filtered physical value measured on "Motor +" Voltage pin that will
   be provided by VSA */
   uint16 u16FilteredMotorPlusVoltage;

   /* This is the filtered physical value measured on "Motor -" Voltage pin that will
   be provided by VSA */
   uint16 u16FilteredMotorMinusVoltage;

   /* This is the absolute difference voltage between "Motor +" Voltage and "Motor -" Voltage */
   uint16 u16AbsoluteMotorDifferenceVoltage;

   /* This is the test result that will be returned */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* To store the MOSFET short circuit auto-test status from ATM */
   u8TestResultType u8PreviousMosfetHighSCTestResult;
   u8TestResultType u8PreviousMosfetLowSCTestResult;

   /* To store the High Side Switch regulation auto-test status from ATM */
   u8TestResultType u8PreviousHighSideSWregTestResult;

   /* To store ADC auto-test status from ATM */
   u8TestResultType u8PreviousADCTestResult;

   /* To store battery survey status */
   u8BatteryVoltageSurveyStatusType u8BatterySurveyStatus;

   /* Get MOSFET short circuit auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_MOSFET_HIGH_SHORT_CIRCUIT, &u8PreviousMosfetHighSCTestResult);
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_MOSFET_LOW_SHORT_CIRCUIT, &u8PreviousMosfetLowSCTestResult);

   /* Get ADC auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC, &u8PreviousADCTestResult);

   /* Get High Side switch auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_HIGH_SIDE_SWITCH, &u8PreviousHighSideSWregTestResult);

   /* Check if all pre conditions are set */
   if ((KU8_ATM_TEST_OK == u8PreviousADCTestResult) && (KU8_ATM_TEST_OK == u8PreviousHighSideSWregTestResult) && (KU8_ATM_TEST_OK == u8PreviousMosfetLowSCTestResult) && (KU8_ATM_TEST_OK == u8PreviousMosfetHighSCTestResult))
   {

      /* All pre conditions are set */

      /* Get the filtered physical value measured on "Motor +" Voltage pin from ASM */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
      Rte_Call_pclMotor_Vp_Get_100ms(&u16FilteredMotorPlusVoltage);

      /* Get the filtered physical value measured on "Motor +" Voltage pin from ASM */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
      Rte_Call_pclMotor_Vn_Get_100ms(&u16FilteredMotorMinusVoltage);

      /* Compute the absolute difference voltage between "Motor +" Voltage and "Motor -" Voltage */
      if (u16FilteredMotorPlusVoltage >= u16FilteredMotorMinusVoltage)
      {
         u16AbsoluteMotorDifferenceVoltage = u16FilteredMotorPlusVoltage - u16FilteredMotorMinusVoltage;
      }
      else
      {
         u16AbsoluteMotorDifferenceVoltage = u16FilteredMotorMinusVoltage - u16FilteredMotorPlusVoltage;
      }

      /* Compare the absolute voltage difference to the motor disconnected threshold */
      if (u16AbsoluteMotorDifferenceVoltage < NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorDisconnectedVoltageThrs)
      {
         /* The voltage drop is lower than the disconnected threshold */
         /* Check if the battery was stable during the test */
         /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
         Rte_Call_pclSurveyBatteryVoltage_GetStatus(&u8BatterySurveyStatus);

         if (KU8_BATTERY_STABLE == u8BatterySurveyStatus)
            /* [COVERS: DSG_PAL_0057] */
         {
            /* Battery was stable during test execution return OK */
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         else
            /* [COVERS: DSG_PAL_0056] */
         {
            /* Battery unstable during test execution return NOT_DECIDED */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
         }
      }
      else
         /* [COVERS: DSG_PAL_0055] */
      {
         /* The voltage drop is higher than the disconnected threshold, return NOK */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
   }
   else
   {
      /* Nothing to do, return status has already been initialized to NOT_DECIDED */
   }

   /* Return the computed test result */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
 * \brief
 *	   This function has to test that a high motor current will not be applied
 *	    for a too long time (scope is to protect motor and HW components)
 * \param
 * 		pu8TestResult: Pointer used to store the auto test result
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		NA
 */
/* [COVERS: DSG_PAL_0025] */
void PAL_Autotest_CheckMotorCurrent(u8TestResultType *pu8TestResult)
{
   /* This is the raw value of the Motor current that will be provided
    * by PAL Sensor trough the WRA module */
   s32MotorCurrentInmAType pal_s32SignedPhysicalMotorCurrent_mA;
   uint32 pal_u32PhysicalMotorCurrent_mA;

   /* This is the test result that will be returned */
   u8TestResultType pal_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* This variable is used to get the return values from the test sub functions */
   uint8 pal_u8LocalMediumReturnedResult;
   uint8 pal_u8LocalHighReturnedResult;

   /* To get the executed cycle number */
   uint8 pal_u8ExecutedCycleNumber;

   /* To store the previous Motor current DTC state */
   u8TestResultType pal_tMotorCurrentEventStatus;

   /* Read the current executed cycle number */
   /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
   Rte_Read_prrExecutedCycle_u8CycleNumber(&pal_u8ExecutedCycleNumber);

   /* Get Motor Current DTC state */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_MOTOR_CURRENT, &pal_tMotorCurrentEventStatus);

   /* Check if the test can be executed */
   /* Check if no PRO cycle is running */
   if ((KU8_BELT_FUNCTION_33 != pal_u8ExecutedCycleNumber) && (KU8_BELT_FUNCTION_34 != pal_u8ExecutedCycleNumber))
   {
      /* Counters to detect motor current fault (for high and medium thresholds) are reinitialized
       * if a new cycle is played or if no cycle is played */
      if ((KU8_NO_CYCLE != PAL_Cfg_AT_InternalData.u8PowerCurrentExecutedCycleMemory) && (pal_u8ExecutedCycleNumber == PAL_Cfg_AT_InternalData.u8PowerCurrentExecutedCycleMemory))
      {
         /* Same cycle executed */
         /***************************************************************/
         /* Motor current main operations with 10 ms periodicity       */
         /***************************************************************/

         /* Get the Motor current from WRA */
         /* Label: COD_ATE_00317 */
         /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
         PAL_runReadMotorCurrentInmA((sint32 *)(&pal_s32SignedPhysicalMotorCurrent_mA));
         /* Get absolute value of motor current */
         /* QAC_WARNING S 3491 1 */ /* warnings due to a tri state operator used to inline the absolute value operation */
         pal_u32PhysicalMotorCurrent_mA = U32_GET_ABSOLUTE_VALUE_FROM_S32(pal_s32SignedPhysicalMotorCurrent_mA);

         /* Call the local sub-function to manage the medium current detection */
         /* Label: COD_ATE_02003 */
         pal_u8LocalMediumReturnedResult = pal_u8MotorCurrent_ManageMediumCurrentFailureDetection(pal_u32PhysicalMotorCurrent_mA);

         /* No failure with the medium current threshold */
         /* Call the local sub-function to manage the high current detection */
         /* Label: COD_ATE_02005 */
         pal_u8LocalHighReturnedResult = pal_u8MotorCurrent_ManageHighCurrentFailureDetection(pal_u32PhysicalMotorCurrent_mA);

         /* Label: COD_ATE_02006 */
         if ((KU8_ATM_TEST_NOK == pal_u8LocalMediumReturnedResult) || (KU8_ATM_TEST_NOK == pal_u8LocalHighReturnedResult))
         {
            /* Return "NOK" status */
            /* Label: COD_ATE_02009 */
            /* [COVERS: DSG_PAL_0028, DSG_PAL_0029] */
            pal_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
         else if ((KU8_ATM_TEST_OK == pal_u8LocalMediumReturnedResult) && (KU8_ATM_TEST_OK == pal_u8LocalHighReturnedResult))
         {
            /* Return "OK" status */
            /* [COVERS: DSG_PAL_0027] */
            pal_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         else
         {
            /* Return "Not Decided" */
            /* Label: COD_ATE_02007 */
            /* [COVERS: DSG_PAL_0030] */
            pal_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
         }
      }
      /* Different cycle or no tensioning cycle played */
      else
      {
         if ((KU8_ATM_TEST_NOK == pal_tMotorCurrentEventStatus) && (PAL_Cfg_AT_InternalData.u16MotorCurrentErrorResetTimeCounter < NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorCurrentResetTime))
         /* [COVERS: DSG_PAL_0031] */
         {
            /* Deskill time spend here */
            PAL_Cfg_AT_InternalData.u16MotorCurrentErrorResetTimeCounter += PAL_KU8_PERIODICITY_10_MS;

            /* Return NOK */
            pal_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
         else
         /* [COVERS: DSG_PAL_0032] */
         {
            /* Deskill time expired OR no error detected during last cycle
             * reset all counters */
            PAL_Cfg_AT_InternalData.u16MotorCurrentHighThrsTimeCounter = KU16_ZERO;
            PAL_Cfg_AT_InternalData.u32MotorCurrentMediumThrsTimeCounter = KU32_ZERO;
            PAL_Cfg_AT_InternalData.u16MotorCurrentErrorResetTimeCounter = KU16_ZERO;

            /* Return OK */
            pal_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
      }
   }
   else
   {
      /* Test can not be executed, return NOT_DECIDED */
      /* [COVERS: DSG_PAL_0026] */
      pal_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   }

   /* Save cycle number */
   PAL_Cfg_AT_InternalData.u8PowerCurrentExecutedCycleMemory = pal_u8ExecutedCycleNumber;

   /* Return the computed test result */
   *pu8TestResult = pal_u8ResultOfAutoTest;
}

/**
 * \brief
 *	   This function has to test that a high PWM duty cycle will not be applied for a too long time.
 *    It's to protect motor and HW components and it can be used to detect a problem with the mechanic
 * \param
 * 		pu8TestResult: Pointer used to store the auto test result
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		NA
 */
/*COVERS: DSG_PAL_0026 */
void PAL_Autotest_CheckMotorPowerOrder(u8TestResultType * pu8TestResult)
{
   /* This is the raw value of the Motor PWM order that will be provided
    * by PAL Actuators trough the WRA module */
   s16MotorPowerOrderType s16MotorPWMOrder;
   /* To store the absolute value of the Motor power order */
   uint16 u16AbsoluteValueOfMotorPWMOrder;

   /* This is the value of the PWM order converted to percent from 0 to 100% */
   uint8 u8AbsoluteValue_MotorPWMOrder_Percent;

   /* To get the executed cycle number */
   uint8 u8ExecutedCycleNumber;

   /* To check there is a tensioning cycle */
   u8ModeStatusType u8TensioningModeStatus;

   /* This variable is used to get the return values from the test sub functions */
   uint8 u8LocalMediumReturnedResult;
   uint8 u8LocalHighReturnedResult;

   /* To store ADC auto-test result from ATM */
   u8TestResultType u8PreviousADCTestResult;

   /* To store the previous Motor Order DTC state */
   u8AecStatusType tMotorOrderEventStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

   /* This is the test result that will be returned */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /***************************************************************/
   /* With the same periodicity as BFE_runScheduleStep 10 ms task */
   /***************************************************************/
   /* Get Motor Order AEC State */
   Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_MOTOR_ORDER_AEC_CFG, &tMotorOrderEventStatus);

   /* Get ADC auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC, &u8PreviousADCTestResult);

   /* Read the current executed cycle number */
   /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
   Rte_Read_prrExecutedCycle_u8CycleNumber(&u8ExecutedCycleNumber);

   /* Get the "no tensioning" system context status */
   /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
   Rte_Call_pclModeManagement_CheckModeStatus(MMG_KU32_MASK_TENSIONING, &u8TensioningModeStatus);

   /* Check if the test can be executed */
   /* Check if the ADC auto test is ok */
   /* AND */
   /* Check if no PRO cycle is running */
   if(    (KU8_ATM_TEST_OK == u8PreviousADCTestResult )
       && (KU8_BELT_FUNCTION_33 != u8ExecutedCycleNumber)
       && (KU8_BELT_FUNCTION_34 != u8ExecutedCycleNumber))
   { /* Check if a valid cycle context is present */
      if ((u8ExecutedCycleNumber == PAL_Cfg_AT_InternalData.u8PowerOrderExecutedCycleMemory) && (u8TensioningModeStatus == KU8_MODE_STATUS_ON))
      {
         /* Same cycle as previous call AND its a tensioning cycle */
         /* Get the Motor PWM order to check if it is null */
         /* Returned value range: -6400, 6400 */
         s16MotorPWMOrder = PAL_Cfg_InternalData.s16RawDutyCycleCommand;

         /* Get absolute value of PWM order in percent: the raw value from belt functions, divided by 64
         using shift by 5 to get value from 0 -> 100 (0% -> 100%) */

         if( s16MotorPWMOrder < KS16_ZERO )
         {
            u16AbsoluteValueOfMotorPWMOrder = (uint16)(-s16MotorPWMOrder);
         }
         else
         {
            u16AbsoluteValueOfMotorPWMOrder = (uint16)s16MotorPWMOrder;
         }
         u8AbsoluteValue_MotorPWMOrder_Percent = (uint8) (u16AbsoluteValueOfMotorPWMOrder >> PAL_KU8_DIVIDE_BY_64_RIGHT_SHIFT);

         /*** Detect a failure on medium or high PWM thresholds ***/

         /* Call the local subfunction to manage the medium PWM detection */
         u8LocalMediumReturnedResult = pal_u8MotorOrder_ManageMediumPWMFailureDetection (u8AbsoluteValue_MotorPWMOrder_Percent);

         /* Call the local subfunction to manage the high PWM detection */
         u8LocalHighReturnedResult = pal_u8MotorOrder_ManageHighPWMFailureDetection (u8AbsoluteValue_MotorPWMOrder_Percent);

         if ( (KU8_ATM_TEST_NOK == u8LocalMediumReturnedResult) || (KU8_ATM_TEST_NOK == u8LocalHighReturnedResult))
            /* [COVERS: DSG_PAL_0059] */
         {
            /* Return "NOK" status */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
         else if((KU8_ATM_TEST_OK == u8LocalMediumReturnedResult) && (KU8_ATM_TEST_OK == u8LocalHighReturnedResult))
            /* [COVERS: DSG_PAL_0060] */
         {
            /* Return "OK" status */
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         else
         {
            /* Return "Not Decided" */
            /* [COVERS: DSG_PAL_0058] */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
         }
      }
      /* Different cycle or no tensioning cycle played */
      else
      {
         if( ( ERH_KU8_AEC_QUALIFIED_STATUS_MASK == (tMotorOrderEventStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK) )
           &&(PAL_Cfg_AT_InternalData.u16MotorOrderErrorResetTimeCounter < NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16CheckMotorOrderResetTime))
            /* [COVERS: DSG_PAL_0061] */
         {
            /* Deskill time spend here */
            PAL_Cfg_AT_InternalData.u16MotorOrderErrorResetTimeCounter += PAL_KU8_PERIODICITY_10_MS;

            /* Return NOK */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
         else
         {
            /* Deskill time expired OR no error detected during last cycle
             * reset all counters */
            /* [COVERS: DSG_PAL_0070] */
            PAL_Cfg_AT_InternalData.u16MotorOrderHighThrsTimeCounter   = KU16_ZERO;
            PAL_Cfg_AT_InternalData.u32MotorOrderMediumThrsTimeCounter = KU32_ZERO;
            PAL_Cfg_AT_InternalData.u16MotorOrderErrorResetTimeCounter = KU16_ZERO;

            /* Return OK */
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
      }
   }
   else
   {
      /* ADC out of order, return NOT_DECIDED */
      /* [COVERS: DSG_PAL_0058] */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   }

   /* Save the cycle number */
   PAL_Cfg_AT_InternalData.u8PowerOrderExecutedCycleMemory = u8ExecutedCycleNumber;

   /* Return the computed test result */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
 * \brief
 *	   This function has to test that the motor is coupled with the mechanic
 * \param
 * 		pu8TestResult: Pointer used to store the auto test result
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		NA
 */
void PAL_Autotest_CheckMotorDisengagement(u8TestResultType * pu8TestResult)
{
   /* This is the raw value of the Motor current that will be provided
   by PAL Sensor trough the WRA module*/
   uint32 u32PhysicalMotorCurrent_mA;
   sint32 s32SignedPhysicalMotorCurrent_mA;

   /* This is the calculated current threshold allowing to detect if the motor
   is blocked or not.*/
   uint32 u32BlockedMotorCurrentThreshold_mA ;

   /* This is the value of the Motor resistance */
   uint16 u16MotorResistance_mOhm;

   /* This is the KL30 battery voltage that will be provided by VSA */
   u16VoltageType u16KL30Voltage_mV;

   /* This is the filtered raw value of the ECU internal temperature that will be provided by SBC */
   sint16 s16ECUInternalTemperature;

   /* This is the raw value of the Motor PWM order that will be provided
    * by PAL Actuators trough the WRA module */
   s16MotorPowerOrderType s16MotorPWMOrder;
   uint16 u16MotorPWMOrder;

   /* To get the executed cycle number */
   uint8 u8ExecutedCycleNumber;

   /* To store ADC auto-test result from ATM */
   u8TestResultType u8PreviousADCTestResult;

   /* To store Self-Protection auto-test result from ATM */
   u8TestResultType u8PreviousSelfProtectionTestResult;

   /* This is the test result that will be returned */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* Get ADC auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC, &u8PreviousADCTestResult);

   /* Get Self protection auto-test status */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_DRIVER_SELF_PROTECTION, &u8PreviousSelfProtectionTestResult);

   /* Read the current executed cycle number */
   /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
   Rte_Read_prrExecutedCycle_u8CycleNumber(&u8ExecutedCycleNumber);

   /* Check if all pre-conditions are set */
   if((KU8_ATM_TEST_OK == u8PreviousADCTestResult)
   && (KU8_ATM_TEST_OK == u8PreviousSelfProtectionTestResult)
   && (     (KU8_BELT_FUNCTION_29 == u8ExecutedCycleNumber)
         || (KU8_BELT_FUNCTION_30 == u8ExecutedCycleNumber)
         || (KU8_BELT_FUNCTION_31 == u8ExecutedCycleNumber)))
   {
      /* Read and check if the ECU temperature is in the right range */
      /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
	   Rte_Call_pclECU_T_GetFiltered_deg ( &s16ECUInternalTemperature);

      if (PAL_KS16_DEG_TO_ADC(s16ECUInternalTemperature) > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorDisengagementMinTemp)
      {
         /* Get the Motor PWM order from PAL */
         /* Returned value range: -6400, 6400 */
         s16MotorPWMOrder = PAL_Cfg_InternalData.s16RawDutyCycleCommand;

         /* Check if MOT_POW_order is in the acceptable range. In releasing cycle, PWM orders are negative */
         if((s16MotorPWMOrder < NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_s16MotorDisengagementMinPowerOrder)
         && (s16MotorPWMOrder > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_s16MotorDisengagementMaxPowerOrder))
         {
            /* Motor PWM order inside the correct range */
            /* Get the KL30 battery voltage (and not HS1 see issue 113320) from VSA */
            /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
            Rte_Call_pclKL30_V_Get_10ms ( &u16KL30Voltage_mV);

            /* Get absolute value of Motor PWM order */
            if(s16MotorPWMOrder < KS16_ZERO)
            {
               u16MotorPWMOrder = (uint16)-s16MotorPWMOrder;
            }
            else
            {
               u16MotorPWMOrder = (uint16)s16MotorPWMOrder;
            }

            /* Get the Motor resistance from RCA */
            /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
            Rte_Call_pclResistance_Get(PAL_KS16_DEG_TO_ADC(s16ECUInternalTemperature), &u16MotorResistance_mOhm);

            /* Compute the motor blocked current threshold (80% of Imax ; Imax = (KL30[mV] * MOT_PWM_Order[%]) / (MOT_res[mOhms] + HW_res[mOhms])) */
            u32BlockedMotorCurrentThreshold_mA =
            (
               /* The multiplication of the motor bias bridge voltage by PWM order has to be made on 32bits */
               ((uint32)u16KL30Voltage_mV * (uint32)u16MotorPWMOrder)
               /
               /* The sum of the 2 16 bits resistances times 8 requires also 32 bits */
               (((uint32)KU8_EIGHT) * ((uint32)u16MotorResistance_mOhm + (uint32)CALIB_BLOCK_ID_ECU_PROPERTIES_RomBlockData.NVP_u16EcuResistance))
            );

            /* Get the Motor current from PAL */
            /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
            PAL_runReadMotorCurrentInmA(&s32SignedPhysicalMotorCurrent_mA);

            /* Get the absolute value of motor current */
            if(s32SignedPhysicalMotorCurrent_mA < KS32_ZERO)
            {
               u32PhysicalMotorCurrent_mA = (uint32)-s32SignedPhysicalMotorCurrent_mA;
            }
            else
            {
               u32PhysicalMotorCurrent_mA = (uint32)s32SignedPhysicalMotorCurrent_mA;
            }
            /* [COVERS: DSG_PAL_0062] */
            /* Check if the motor current is above threshold */
            if (u32PhysicalMotorCurrent_mA > u32BlockedMotorCurrentThreshold_mA)
            {
               /* Motor current over the maximum current threshold */
               /* Check if the maximum number of failed occurrences is reached */
               if (PAL_Cfg_AT_InternalData.u8MotorBlockedFailedCntr >= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8NbOccurenceToValidateMotorBlocked)
               {
                  /* Maximum number of failed attempts reached, return NOK */
                  u8ResultOfAutoTest = KU8_ATM_TEST_NOK;

                  /* Reset the passed counter to its default value */
                  PAL_Cfg_AT_InternalData.u8MotorBlockedPassedCntr = KU8_ZERO;
               }
               else
               {
                  PAL_Cfg_AT_InternalData.u8MotorBlockedFailedCntr++;
                  /* Test can be replayed return NOT_DECIDED */
                  u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
               }
            }
            else
            {
               /* Motor current below the maximum current threshold */
               /* Check if the maximum number of passed occurrences is reached */
               if(PAL_Cfg_AT_InternalData.u8MotorBlockedPassedCntr >= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8NbOccurenceToDeskillMotorBlocked)
               {
                  /* Maximum number of passed attempts reached, return OK */
                  u8ResultOfAutoTest = KU8_ATM_TEST_OK;

                  /* Reset the failed counter to its default value */
                  PAL_Cfg_AT_InternalData.u8MotorBlockedFailedCntr = KU8_ZERO;
               }
               else
                  /* [COVERS: DSG_PAL_0063] */
               {
                  PAL_Cfg_AT_InternalData.u8MotorBlockedPassedCntr++;
                  /* Test still on going return NOT_DECIDED */
                  u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
               }
            }
         }
         else
         {
            /* Motor PMW order outside the correct range, test cannot be executed => NOT_DECIDED (already initialized) */
         }
      }
      else
      {
         /* Internal ECU temperature too low, test cannot be executed => NOT_DECIDED (already initialized) */
      }
   }
   else
   {
      /* Nothing to do, return status has already been initialized to NOT_DECIDED */
   }

   /* Return the computed test result */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
 * \brief
 *	   This function has to test that the motor is not shortcut with Vbat or GND
 * \param
 * 		pu8TestResult: Pointer used to store the auto test result
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		NA
 */
void PAL_Autotest_CheckMotorSC(u8TestResultType *pu8TestResult)
{
   /* This is the raw value of the Motor current that will be provided by PAL Sensor */
   s32MotorCurrentInmAType s32SignedPhysicalMotorCurrent_mA;
   uint32 u32AbsolutePhysicalMotorCurrent_mA;

   /* This is the calculated current threshold allowing to detect if the motor is in short circuit or not */
   uint32 u32MotorShortCircuitCurrentThreshold_mA;

   /* This is the KL30 battery voltage that will be provided by VSA */
   u16VoltageType u16FilteredVbatPowerVoltage_mV;

   /* This is the raw value of the Motor PWM order that will be provided by PAL module */
   s16MotorPowerOrderType s16MotorPWMOrder;
   uint16 u16MotorPWMOrder;

   /* Used to store the ADC auto-test status from ATM */
   u8TestResultType u8ADCTestResult;

   /* To get the executed cycle number */
   uint8 u8ExecutedCycleNumber;

   /* This is the test result that will be returned */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* This is the hardware self protection state returned by the PAL Sensor module */
   boolean bHWSelfProtectionStatus;

   /* This is the value of the Motor resistance */
   uint16 u16MotorResistance_mOhm;

   /* This is the filtered raw value of the ECU internal temperature that will be provided by SBC */
   sint16 s16ECUInternalTemperature;

   uint8 u8HBIndex;

   boolean bIsHBCalibrationErased = B_FALSE;

   /* Read the current executed cycle number */
   /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
   Rte_Read_prrExecutedCycle_u8CycleNumber(&u8ExecutedCycleNumber);

   /* Get ADC auto-test result */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC, &u8ADCTestResult);

   for (u8HBIndex = 0; u8HBIndex < sizeof(NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CalibADCRel); u8HBIndex++)
   {
      if ((NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CalibADCRel[u8HBIndex] != KU16_MAX) || (bIsHBCalibrationErased == B_TRUE))
      {
         break;
      }
      else if (u8HBIndex == ((sizeof(NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CalibADCRel) / sizeof(uint16)) - KU8_ONE))
      {
         bIsHBCalibrationErased = B_TRUE;
      }
      else
      {
         /* do nothing */
      }
   }

   for (u8HBIndex = 0; u8HBIndex < sizeof(NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CalibADCTens); u8HBIndex++)
   {
      if ((NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CalibADCTens[u8HBIndex] != KU16_MAX) || (bIsHBCalibrationErased == B_TRUE))
      {
         break;
      }
      else if (u8HBIndex == ((sizeof(NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CalibADCTens) / sizeof(uint16)) - KU8_ONE))
      {
         bIsHBCalibrationErased = B_TRUE;
      }
      else
      {
         /* do nothing */
      }
   }

   for (u8HBIndex = 0; u8HBIndex < sizeof(NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CurrentProbeRel); u8HBIndex++)
   {
      if ((NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CurrentProbeRel[u8HBIndex] != KU16_MAX) || (bIsHBCalibrationErased == B_TRUE))
      {
         break;
      }
      else if (u8HBIndex == ((sizeof(NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CurrentProbeRel) / sizeof(uint16)) - KU8_ONE))
      {
         bIsHBCalibrationErased = B_TRUE;
      }
      else
      {
         /* do nothing */
      }
   }

   for (u8HBIndex = 0; u8HBIndex < sizeof(NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CurrentProbeTens); u8HBIndex++)
   {
      if ((NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CurrentProbeTens[u8HBIndex] != KU16_MAX) || (bIsHBCalibrationErased == B_TRUE))
      {
         break;
      }
      else if (u8HBIndex == ((sizeof(NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CurrentProbeTens) / sizeof(uint16)) - KU8_ONE))
      {
         bIsHBCalibrationErased = B_TRUE;
      }
      else
      {
         /* do nothing */
      }
   }

   /* Get the power stage self protection from local function */
   bHWSelfProtectionStatus = pal_bIsPowerStageInSelfProtection();

   /* Check if a releasing cycle is not executed */
   /* OR */
   /* Check if MOSFET Short Circuit, ADC or HW selfprotection auto-tests results are failed */
   if ((KU8_BELT_FUNCTION_32 != u8ExecutedCycleNumber) ||
       (KU8_ATM_TEST_OK != u8ADCTestResult) ||
       (KU8_TRUE == bIsHBCalibrationErased) ||
       (B_TRUE == bHWSelfProtectionStatus))
   {
      /* MOSFET Short Circuit OR ADC OR HW Self protection auto-tests results are failed */
      /* OR, no releasing cycle executed */

      /* return NOT_DECIDED */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   }
   /* All conditions are met, execute the test */
   else
   {
      /* Get the Motor PWM order from internal data structure */
      /* Returned value range: -6400, 6400 */
      s16MotorPWMOrder = PAL_Cfg_InternalData.s16RawDutyCycleCommand;

      /* Check if the PWM is out of minimum/maximum thresholds range (Info: in releasing, the PWM order is negative)*/
      if (((sint16)((sint16)NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_s8MotorSCMinDutyCycle * (sint16)PAL_KU8_CONVERT_DUTY_CYCLE_TO_PWM_ORDER_FACTOR) > s16MotorPWMOrder) &&
          ((sint16)((sint16)NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_s8MotorSCMaxDutyCycle * (sint16)PAL_KU8_CONVERT_DUTY_CYCLE_TO_PWM_ORDER_FACTOR) < s16MotorPWMOrder))
      {
         /* PWM is OK */
         /* Get the Motor current from PAL module */
         /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
         PAL_runReadMotorCurrentInmA(&s32SignedPhysicalMotorCurrent_mA);
         /* QAC_WARNING S 3491 4 */ /* Using conditional operator in a macro.
                                     * Operator "<" is used to determine the expression sign */
         /* QAC_WARNING S 4393 2 */ /* A composite expression of 'essentially unsigned' type is being cast to a different type category, signed.
                                     * uint16 variable are converted into sint32 variable in order to avoid a wrong calculation (eg. 0xFFFF u16 interpreted as -1 in S16) */
         u32AbsolutePhysicalMotorCurrent_mA = U32_GET_ABSOLUTE_VALUE_FROM_S32(s32SignedPhysicalMotorCurrent_mA);

         /* Check the measured motor short circuit current threshold */
         /* TODO : NVP_u16MinimumCurrentThresholdToCheckMotorSC shall be set to 5A */
         if (u32AbsolutePhysicalMotorCurrent_mA > ((uint32)NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorSCCurrentThrsMin))
         {
            /* The measured motor short circuit current threshold is higher than a specified threshold */
            /* Get the KL30 battery voltage from VSA */
            /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
            Rte_Call_pclKL30_V_Get_10ms(&u16FilteredVbatPowerVoltage_mV);

            /* Get absolute value of PWM */
            /* QAC_WARNING S 3491 4 */ /* Using conditional operator in a macro.
                                        * Operator "<" is used to determine the expression sign */
            /* QAC_WARNING S 4393 2 */ /* A composite expression of 'essentially unsigned' type is being cast to a different type category, signed.
                                        * uint16 variable are converted into sint32 variable in order to avoid a wrong calculation (eg. 0xFFFF u16 interpreted as -1 in S16) */
            u16MotorPWMOrder = U16_GET_ABSOLUTE_VALUE_FROM_S16(s16MotorPWMOrder);

            Rte_Call_pclECU_T_GetFiltered_deg(&s16ECUInternalTemperature);

            /* Get the Motor resistance from RCA */
            /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
            Rte_Call_pclResistance_Get(PAL_KS16_DEG_TO_ADC(s16ECUInternalTemperature), &u16MotorResistance_mOhm);

            /* Calculation of the motor short circuit current threshold */
            u32MotorShortCircuitCurrentThreshold_mA =
                (
                    /* The multiplication of the motor bias bridge voltage by PWM order has to be made on 32bits */
                    ((uint32)KU8_THREE * (uint32)u16FilteredVbatPowerVoltage_mV * (uint32)u16MotorPWMOrder) /
                    /* The sum of the 2 16 bits resistances times 8 requires also 32 bits */
                    (PAL_KU32_SIXTEEN * ((uint32)u16MotorResistance_mOhm + (uint32)CALIB_BLOCK_ID_ECU_PROPERTIES_RomBlockData.NVP_u16EcuResistance)));

            /* Check if the measured Motor current is higher than the calculated current threshold */
            if (u32AbsolutePhysicalMotorCurrent_mA > u32MotorShortCircuitCurrentThreshold_mA)
            {
               /* The measured Motor current is above than calculated current threshold
               thus there is Motor Short Circuit fault */

               /* Filter counter has reach the Failed threshold */
               /* [COVERS: DSG_PAL_0065] */
               if (PAL_Cfg_AT_InternalData.u8MotorSCFailedCntr >= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8NbOccurenceToValidateMotorSC)
               {
                  /* Reset the passed filter counter */
                  PAL_Cfg_AT_InternalData.u8MotorSCPassedCntr = KU8_ZERO;

                  /* return NOK */
                  u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
               }
               else
               { /* Filter counter has not reach the Failed threshold yet */
                  /* Increment the Failed Filter counter */
                  PAL_Cfg_AT_InternalData.u8MotorSCFailedCntr++;

                  /* return NOT_DECIDED */
                  u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
               }
            }
            else
            {
               /* The measured Motor current is below than calculated current threshold
               thus there is no Motor Short Circuit */

               if (PAL_Cfg_AT_InternalData.u8MotorSCPassedCntr < NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8NbOccurenceToDeskillMotorSC)
                  /* [COVERS: DSG_PAL_0066] */
               {
                  /* Increment the Passed Filter counter */
                  PAL_Cfg_AT_InternalData.u8MotorSCPassedCntr++;

                  /* return NOK */
                  u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
               }
               /* Filter counter has reach the Passed threshold */
               else
                  /* [COVERS: DSG_PAL_0067] */
               {
                  /* return OK */
                  u8ResultOfAutoTest = KU8_ATM_TEST_OK;

                  /* Reset failed filter counter */
                  PAL_Cfg_AT_InternalData.u8MotorSCFailedCntr = KU8_ZERO;
               }
            }
         }
         else
            /* [COVERS: DSG_PAL_0068] */
         {
            /* The measured motor short circuit current threshold is below than a specified threshold */
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
      }
      else
         /* [COVERS: DSG_PAL_0064] */
      {
         /* PWM is out of minimum/maximum thresholds range */
         /* return NOT_DECIDED */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
      }
   }

   /* Return the computed test result */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
 * \brief
 *	   This function has to test that the motor is not too hot
 *	   (high temperature will damage the motor and the electronic)
 * \param
 * 		pu8TestResult: Pointer used to store the auto test result
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		NA
 */
/* [COVERS: DSG_PAL_0033] */
void PAL_Autotest_CheckMotorThermalProctection(u8TestResultType *pu8TestResult)
{
   /* Deficiency level */
   u32DeficiencyLevelType pal_u32DeficiencyLevel;

   /* This is the test result that will be returned */
   u8TestResultType pal_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* To store the SW thermal protection DTC status from Dem */
   u8TestResultType pal_tSwThermalProtectionEventStatus;

   /* All pre-condition are met */
   /* Get the deficiency level from TSA */
   /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
   Rte_Call_pclMotor_T_GetDeficiencyLevel(&pal_u32DeficiencyLevel);

   /* Get DTC status */
   /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_MOTOR_TEMPERATURE, &pal_tSwThermalProtectionEventStatus);

   /* Select the right threshold depending on the AEC status */
   if (KU8_ATM_TEST_NOK == pal_tSwThermalProtectionEventStatus)
   {
      /* AEC is qualified, used the deskill threshold */
      if (pal_u32DeficiencyLevel > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u32SWThermalProtectionDeskillingThrs)
      /* [COVERS: DSG_PAL_0034] */
      {
         /* Deficiency level over the deskill threshold, test is NOK */
         pal_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
      else
      /* [COVERS: DSG_PAL_0035] */
      {
         /* Deficiency level under the deskill threshold, test is OK */
         pal_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
   }
   else
   {
      /* AEC not qualified, used the qualification threshold */
      if (pal_u32DeficiencyLevel >= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u32SWThermalProtectionValidationThrs)
      /* COVERS: DSG_PAL_0036 */
      {
         /* Deficiency level over the qualification threshold, test is NOK */
         pal_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
      else
      /* [COVERS: DSG_PAL_0037] */
      {
         /* Deficiency level under the qualification threshold, test is OK */
         pal_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
   }
   /* Return the computed test result */
   /*Label: COD_ATE_00218*/
   *pu8TestResult = pal_u8ResultOfAutoTest;
}

#pragma restore optimize
#define PAL_AC_PowerAbstractionLayer_STOP_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
