
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
$Revision: 1.2.3.9 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/PMP/Quality_Assurance/Static_Analysis/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup PMP.c PMP
 *  This is a new created group, this will create a new man3 file with 
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file. 
 */
 
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"
#include "Rte_PMP_AC_PhysicalMeasuresProvider.h"

#include "PMP_public.h"
#include "PMP_cfg_private.h"
#include "PMP_private.h"
#include "Math.h"
#include "Nvp_Generated.h"


/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *		Number of points used in motor resistance linear interpolation.
 */
#define PMP_KU8_MOTOR_RESISTANCE_LINEAR_INTERPOLATION_NB_POINTS ((uint8) 7)

/******************************************************************************
MODULE TYPES
******************************************************************************/
typedef struct
{
   uint16 u16OldRawBatteryVoltage;
   uint16 u16MinBatteryVoltageADCFormat;
   uint16 u16MaxBatteryVoltageADCFormat;
   uint16 u16MinDiffVoltageToValidateBatterySurvey;
   uint8 u8CounterToValidateBatterySurvey;
   u8BatteryVoltageSurveyStatusType u8BatteryVoltageSurveyState;
}PMP_stBatterySurveyParamType;

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/**
 * \brief
 *		Defined macro from C file.
 */
#define PMP_AC_PhysicalMeasuresProvider_START_SEC_VAR_UNSPECIFIED
#include "PMP_AC_PhysicalMeasuresProvider_MemMap.h"
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		Structure containing all variables used by the battery survey mechanism.
 * \remarks
 *		QAC_WARNING S 2022 1 */ /* Initialization done in PMP_Init().
 */
static PMP_stBatterySurveyParamType PMP_stBatterySurveyParam;

/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		To store old temperature read from ADC.
 * \remarks
 *		QAC_WARNING S 2022 1 */ /* Initialization done in PMP_Init().
 */
static u16InternalTemperatureType PMP_u16OldADCTemperature_LSB;

/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		To store old corrected temperature.
 * \remarks
 *		QAC_WARNING S 2022 1 */ /* Initialization done in PMP_Init().
 */
static u16InternalTemperatureType PMP_u16OldCorrectedTemperature_LSB;

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
*     Function to provide the CORRECTED Temperature of the ECU in LSB (not FILTERED).
* \param
*     [u16InternalTemperatureType * pu16Temperature]
*     Value of the temperature directly taken out from the ADC
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0011] */
void pmp_GetCorrectedTemperature(u16InternalTemperatureType * const pu16Temperature)
{
   uint16 pmp_u16ReadADCTemperature;

   const stInterpolationParam_Type pmp_cstLookUpTable = {
      (const uint8*)(&NVP_BLOCK_TEMP_SENSOR_TABLE_RamBlockData.NVP_au16TempTableVol[0]), /* x_table: vector with axis values */
      (const uint8*)(&NVP_BLOCK_TEMP_SENSOR_TABLE_RamBlockData.NVP_au16TempTableLSB[0]), /* y_table: vector with axis values */
      PMP_KU8_NB_INTERP_PTS_TEMP_CALIB,
      KU8_X16_BIndian | KU8_Y16_BIndian,
      KU8_IN_RANGE_LINEAR_INTER | KU8_BELOW_RANGE_UPPER_INTER | KU8_OVER_RANGE_LOWER_INTER

   };

   /*QAC_WARNING S 3417 4*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 3*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   /*  Get ADC value of the MCU Temperature (considered to be the ECU Temperature) */
   Rte_Call_pclMcu_T_raw_Get_10ms(&pmp_u16ReadADCTemperature);

   /* Check if Temperature has changed */
   /* Or if Temperature correction has been updated */
   if(pmp_u16ReadADCTemperature != PMP_u16OldADCTemperature_LSB)
   {
      /* Temperature has changed */
      *pu16Temperature = (u16InternalTemperatureType)u32InterpolateFromTable((uint32)pmp_u16ReadADCTemperature, &pmp_cstLookUpTable);

      /* Store ADC measure */
      PMP_u16OldADCTemperature_LSB = pmp_u16ReadADCTemperature;

      /* Store corrected temperature */
      PMP_u16OldCorrectedTemperature_LSB = *pu16Temperature;
   }
   else
   {
      /* Temperature has not changed */
      *pu16Temperature = PMP_u16OldCorrectedTemperature_LSB;
   }
}
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define PMP_AC_PhysicalMeasuresProvider_START_SEC_CODE
#include "PMP_AC_PhysicalMeasuresProvider_MemMap.h"

/**
* \brief
*     Initialize the PMP and computes all parameters used by the battery survey.
* \param
*     None.
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
void PMP_Init(void)
{
   /* Initialize the old voltage to 0V */
   /* [COVERS: DSG_PMP_0001] */
   PMP_stBatterySurveyParam.u16OldRawBatteryVoltage = KU16_ZERO;

   PMP_u16OldADCTemperature_LSB = KU16_ZERO;

   PMP_u16OldCorrectedTemperature_LSB = KU16_ZERO;

   /* Maximum value allowed for KL30 */
   /* Convert the physical value read from NVP to an ADC format (10 bits left shifted on a uint16) */
   /* [COVERS: DSG_PMP_0002] */
   PMP_stBatterySurveyParam.u16MaxBatteryVoltageADCFormat = (uint16) ((((uint32)CALIB_BLOCK_ID_VOLT_THRS_RomBlockData.NVP_u16KL30MaximumThr) * PMP_KU32_KL30_RAW_MUL_FACTOR) / PMP_KU32_KL30_RAW_DIV_FACTOR);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in left side */
   PMP_stBatterySurveyParam.u16MaxBatteryVoltageADCFormat *= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   /* Minimum value allowed for KL30 */
   /* Convert the physical value read from NVP to an ADC format (10 bits left shifted on a uint16) */
   /* [COVERS: DSG_PMP_0003] */
   PMP_stBatterySurveyParam.u16MinBatteryVoltageADCFormat = (uint16) ((((uint32)CALIB_BLOCK_ID_VOLT_THRS_RomBlockData.NVP_u16KL30MinimumThr) * PMP_KU32_KL30_RAW_MUL_FACTOR) / PMP_KU32_KL30_RAW_DIV_FACTOR);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in left side */
   PMP_stBatterySurveyParam.u16MinBatteryVoltageADCFormat *= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   /* Lowest difference allowed between two KL30 measurement */
   /* Convert the physical value read from NVP to an ADC format (10 bits left shifted on a uint16) */
   PMP_stBatterySurveyParam.u16MinDiffVoltageToValidateBatterySurvey = (uint16) ((((uint32)NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MinDiffVoltageToValidateBatterySurvey) * PMP_KU32_KL30_RAW_MUL_FACTOR) / PMP_KU32_KL30_RAW_DIV_FACTOR);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in left side */
   PMP_stBatterySurveyParam.u16MinDiffVoltageToValidateBatterySurvey *= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   /* Initialize battery survey state to "UNSTABLE" */
   /* [COVERS: DSG_PMP_0004] */
   PMP_stBatterySurveyParam.u8BatteryVoltageSurveyState = KU8_BATTERY_UNSTABLE;

   /* Initialize occurrences counter to 0 */
   /* [COVERS: DSG_PMP_0005] */
   PMP_stBatterySurveyParam.u8CounterToValidateBatterySurvey = KU8_ZERO;
}

/**
* \brief
*     Function to provide the Resistance of the ECU
* \param
*     u16ResistanceinOhmType * pu16ResistanceinOhm
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0062] */
/* QAC_WARNING S 3206 4 */ /* The parameter 'u16ECUInternalTemperature' is not used in this function. */
                    /* The prototype is defined in RTE by the architecture, and at this time
                     * the resistance doesn't depend from the temperature */
void PMP_runGetBoardResistance(u16InternalTemperatureType u16ECUInternalTemperature,
  u16Resistance_mOhmType * pu16Resistance_mOhm)
{
   /*Returns a NVP Parameter that indicates the ECU Resistance*/
   *pu16Resistance_mOhm = (uint16)(CALIB_BLOCK_ID_ECU_PROPERTIES_RomBlockData.NVP_u16EcuResistance);
}

/**
* \brief
*     This function returns an estimated motor resistance from the ECU measured temperature, using linear interpolation.
* \param
*     [u16InternalTemperatureType u16ECUInternalTemperature]
*     ECU temperature as input
*     [u16ResistanceinOhmType * pu16ResistanceinOhm]
*     Resolution: 1 lsb = 1mOhm 
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0020] */
void PMP_runGetMotorResistance(u16InternalTemperatureType u16ECUInternalTemperature,
  u16Resistance_mOhmType * pu16Resistance_mOhm)
{
   /* QAC_WARNING S 0310 5 */ /* Casting to different object pointer type. */
                       /* pu8X structure member supports to point 8, 16, or 32 bits array (16 bits in this case
                        * as specified with the KU8_X16_BIndian constant */
   /* Parameters of the interpolation performed by the function */
   const stInterpolationParam_Type pmp_cstMotorResistLookUpTable = {
      (const uint8*)(&CALIB_BLOCK_ID_MOTOR_RESIST_PARAM_RomBlockData.NVP_au16MotorResistTempIndex[0]),    /* x_table: vector with axis values */
      &CALIB_BLOCK_ID_MOTOR_RESIST_PARAM_RomBlockData.NVP_au8MotorResistReferences[0],                    /* y_table: vector with axis values */
      PMP_KU8_MOTOR_RESISTANCE_LINEAR_INTERPOLATION_NB_POINTS,
      KU8_X16_LIndian | KU8_Y8,
      KU8_IN_RANGE_LINEAR_INTER | KU8_BELOW_RANGE_UPPER_INTER | KU8_OVER_RANGE_LOWER_INTER
   };

   /* Use NVP look-up table to get motor resistance regarding the temperature */
   *pu16Resistance_mOhm = (uint16)u32InterpolateFromTable((uint32)u16ECUInternalTemperature, &pmp_cstMotorResistLookUpTable);
}

/**
* \brief
*     Function to provide the FILTERED and CORRECTED value of the ECU temperature in LSB.
* \param
*     [u16InternalTemperatureType * pu16FilteredTemperature]
*     Value of the temperature with filtering in case of out of ranges value taken out from the ADC conversion
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0010] */
void PMP_runGetFilteredTemperature(u16InternalTemperatureType * pu16FilteredTemperature)
{
   uint16 pmp_u16TemperatureRawValue;

   /* Read ADC corrected temperature */
   /* [COVERS: DSG_PMP_0034] */
   pmp_GetCorrectedTemperature(&pmp_u16TemperatureRawValue);

   /* Check temperature is in acceptable range */
   if (pmp_u16TemperatureRawValue > CALIB_BLOCK_ID_ECU_PROPERTIES_RomBlockData.NVP_u16TemperatureFunctionalHighThrs)
   {
      /* Return the HIGH default value */
      *pu16FilteredTemperature = (u16InternalTemperatureType) CALIB_BLOCK_ID_ECU_PROPERTIES_RomBlockData.NVP_u16TemperatureFunctionalHighThrs;
   }
   /* Check if temperature is below low functional threshold */
   else if (pmp_u16TemperatureRawValue < CALIB_BLOCK_ID_ECU_PROPERTIES_RomBlockData.NVP_u16TemperatureFunctionalLowThrs)
   {
      /* Return the LOW default value */
      *pu16FilteredTemperature = (u16InternalTemperatureType) CALIB_BLOCK_ID_ECU_PROPERTIES_RomBlockData.NVP_u16TemperatureFunctionalLowThrs;
   }
   else
   {
      /* internal temperature is correct */
      *pu16FilteredTemperature = (u16InternalTemperatureType) pmp_u16TemperatureRawValue;
   }
}

/**
* \brief
*     Function to provide the FILTERED and CORRECTED value of the ECU temperature in DEG.
* \param
*     [u16InternalTemperatureType * pu16FilteredTemperature]
*     Value of the temperature with filtering in case of out of ranges value taken out from the ADC conversion
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0010] */
void PMP_runGetFilteredTemperature_deg(s16InternalTemperature_deg_Type * ps16InternalTemperature_deg)
{
   /* Data */
   u16InternalTemperatureType pmp_u16TemperatureValue_LSB;

   /* Code */
   PMP_runGetFilteredTemperature(&pmp_u16TemperatureValue_LSB);
   /* Convert temperature from LSB to Deg */
   /* QAC_WARNING S 4394 3 */ /* May be negative due to offset */
   *ps16InternalTemperature_deg = (s16InternalTemperature_deg_Type)(PMP_KS16_ADC_TO_DEG(pmp_u16TemperatureValue_LSB));
   *ps16InternalTemperature_deg = (*ps16InternalTemperature_deg) + (s16InternalTemperature_deg_Type)NVP_BLOCK_TEMP_SENSOR_TABLE_RamBlockData.NVP_s8TempOffsetChamberNTC;

}

/**
* \brief
*     Computation of the SW protection based on the measured current.
* \param
*     None.
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
void PMP_runComputeDeficiencyLevel(void)
{
   /* Deficiency level local variables */
   u32DeficiencyLevelType pmp_u32PreviousDeficiencyLevel;
   uint32 pmp_u32NewDeficiencyLevel;

   /* Intermediate sum */
   uint32 pmp_u32Sum;

   /* To calculate the absolute value of measured motor current */
   uint16 pmp_u16AbsoluteValueOfMotorCurrent;

   /* Measured current to compute the SW self protection */
   s8MotorCurrentInAType pmp_s8MotorCurrentInA;

   /*Used to get internal temp value*/
   s16InternalTemperature_deg_Type pmp_s16InternalTemperature_deg = 0;

   /*Square of the motor current*/
   uint32 pmp_u32SquareCUrrent = KU32_ZERO;

   /*QAC_WARNING S 3417 4*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 3*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   /* Read measured motor current in A */
   Rte_Call_pclMotor_I_Get_A(&pmp_s8MotorCurrentInA);

   /* Read deficiency level IRV to get Previous value */
   pmp_u32PreviousDeficiencyLevel = Rte_IrvRead_PMP_runComputeDeficiencyLevel_u32DeficiencyLevel();

   /* Check if motor curent is not null */
   if (KS8_ZERO != pmp_s8MotorCurrentInA)
   /* [COVERS: DSG_PMP_0006] */
   {
      /* Calculate the absolute value of measured motor current */
      if (KS8_ZERO > pmp_s8MotorCurrentInA)
      {
         /* Take the opposite */
         pmp_u16AbsoluteValueOfMotorCurrent = (uint16) (-((sint16) pmp_s8MotorCurrentInA));
      }
      else
      {
         /* Take itself */
         pmp_u16AbsoluteValueOfMotorCurrent = (uint16) (sint16) pmp_s8MotorCurrentInA;
      }

      pmp_u32SquareCUrrent = (uint32) ( (uint32)pmp_u16AbsoluteValueOfMotorCurrent * (uint32) pmp_u16AbsoluteValueOfMotorCurrent );

      /*Get the internal temperature*/
      PMP_runGetFilteredTemperature_deg(&pmp_s16InternalTemperature_deg);

      if(pmp_s16InternalTemperature_deg > PMP_KS16_TEMP_HIGH)
      {
         /* Add the square of the motor current to the previous level */
         pmp_u32Sum = pmp_u32PreviousDeficiencyLevel + pmp_u32SquareCUrrent +
                   (uint32) ( ( pmp_u32SquareCUrrent * PMP_KU32_TWO * ( (uint32)(pmp_s16InternalTemperature_deg - PMP_KS16_TEMP_HIGH) ) ) / PMP_KU32_ONE_HUNDRED ) ;
      }
      else
      {
         /* Add the square of the motor current to the previous level */
         pmp_u32Sum = pmp_u32PreviousDeficiencyLevel + pmp_u32SquareCUrrent;
      }


      /* Check over U32 size */
      if (pmp_u32Sum < pmp_u32PreviousDeficiencyLevel)
      {
         /* Saturate to the maximum */
         pmp_u32Sum = KU32_MAX;
      }
      else
      {
         /* Do nothing as no saturation */
      }


      /* Set new deficiency level */
      pmp_u32NewDeficiencyLevel = pmp_u32Sum;
   }
   else
   {
      /* If motor current is null */

      if (pmp_u32PreviousDeficiencyLevel < ((uint32) NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8SWThermalProtecDecStep))
      {
         /* Level becomes null */
         /* [COVERS: DSG_PMP_0007] */
         pmp_u32NewDeficiencyLevel = KU32_ZERO;
      }
      else
      {
         /* Decrement level */
         /* [COVERS: DSG_PMP_0008] */
         pmp_u32NewDeficiencyLevel = pmp_u32PreviousDeficiencyLevel - ((uint32) NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8SWThermalProtecDecStep);
      }
   }

   /* Check deficiency level range */
   if (NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u32SWThermalProtectionValidationThrs < pmp_u32NewDeficiencyLevel)
   {
      /* Clamp the deficiency level to its maximum value */
      /* [COVERS: DSG_PMP_0009] */
      pmp_u32NewDeficiencyLevel = NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u32SWThermalProtectionValidationThrs;
   }
   else
   {
      /* Value is in the correct range, do nothing */
   }

   /* Write deficiency level IRV */
   Rte_IrvWrite_PMP_runComputeDeficiencyLevel_u32DeficiencyLevel(pmp_u32NewDeficiencyLevel);
}

/**
* \brief
*     This function returns the calculated deficiency level.
* \param
*     [u32DeficiencyLevelType *pu32DeficiencyLevel]
*     Address to variable that will be filled with the calculated deficiency level.
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
 /* [COVERS: DSG_PMP_0021] */
void PMP_runGetDeficiencyLevel(u32DeficiencyLevelType * pu32DeficiencyLevel)
{
   /* Get deficiency level irv */
   *pu32DeficiencyLevel = Rte_IrvRead_PMP_runGetDeficiencyLevel_u32DeficiencyLevel();
}

/**
* \brief
*     This function initialize the deficiency level.
* \param
*     [u32DeficiencyLevelType *pu32DeficiencyLevel]
*     Address to variable that will be filled with the calculated deficiency level.
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
void PMP_runInitializeDeficiencyLevel(u32DeficiencyLevelType u32DeficiencyLevel)
{
   /* Write deficiency level IRV */
   Rte_IrvWrite_PMP_runInitializeDeficiencyLevel_u32DeficiencyLevel(u32DeficiencyLevel);
}

/**
* \brief
*     Function to provide the Battery Voltage  (KL30).
* \param
*     [u16VoltageType * pu16Voltage]
*     Address to variable that will be filled with auxiliary battery voltage
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0016] */
void PMP_runGetBatteryVoltage (u16VoltageType * pu16Voltage)
{
   /* Data */
   uint16 pmp_u16InternalAnalogSignal;

   /* Code */
   /*  Get ADC value of battery level */
   /*QAC_WARNING S 3417 3*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 2*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   Rte_Call_pclKL30_V_raw_Get(& pmp_u16InternalAnalogSignal);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in right side */
   pmp_u16InternalAnalogSignal /= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   *pu16Voltage = (uint16) ((((uint32)pmp_u16InternalAnalogSignal) * PMP_KU32_KL30_MUL_FACTOR) / PMP_KU32_KL30_DIV_FACTOR);
}

/**
* \brief
*     Function to provide the Battery Voltage filtered for 100ms periodic use (KL30).
* \param
*     [u16VoltageType * pu16Voltage]
*     Address to variable that will be filled with auxiliary battery voltage
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0019] */
void PMP_runGetBatteryVoltage_100ms (u16VoltageType * pu16Voltage)
{
   /* Data */
   uint16 pmp_u16InternalAnalogSignal;

   /* Code */
   /*  Get ADC value of battery level */
   /*QAC_WARNING S 3417 3*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 2*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   Rte_Call_pclKL30_V_raw_Get_100ms(&pmp_u16InternalAnalogSignal);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in right side */
   pmp_u16InternalAnalogSignal /= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   *pu16Voltage = (uint16) ((((uint32)pmp_u16InternalAnalogSignal) * PMP_KU32_KL30_MUL_FACTOR) / PMP_KU32_KL30_DIV_FACTOR);
}

/**
* \brief
*     Function to provide the Battery Voltage filtered for 10ms periodic use  (KL30).
* \param
*     [u16VoltageType * pu16Voltage]
*     Address to variable that will be filled with auxiliary battery voltage
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0018] */
void PMP_runGetBatteryVoltage_10ms (u16VoltageType * pu16Voltage)
{
   /* Data */
   uint16 pmp_u16InternalAnalogSignal;

   /* Code */
   /*  Get ADC value of battery level */
   /*QAC_WARNING S 3417 3*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 2*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   Rte_Call_pclKL30_V_raw_Get_10ms(&pmp_u16InternalAnalogSignal);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in right side */
   pmp_u16InternalAnalogSignal /= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   *pu16Voltage = (uint16) ((((uint32)pmp_u16InternalAnalogSignal) * PMP_KU32_KL30_MUL_FACTOR) / PMP_KU32_KL30_DIV_FACTOR);
}

/**
* \brief
*     Function to provide the Battery Voltage filtered for 20ms periodic use  (KL30)
* \param
*     [u16VoltageType * pu16Voltage]
*     Address to variable that will be filled with auxiliary battery voltage
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0021] */
void PMP_runGetBatteryVoltage_20ms (u16VoltageType * pu16Voltage)
{
   /* Data */
   uint16 u16InternalAnalogSignal;

   /* Code */
   /*  Get ADC value of battery level */
   /*QAC_WARNING S 3417 3*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 2*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   Rte_Call_pclKL30_V_raw_Get_20ms(&u16InternalAnalogSignal);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in right side */
   u16InternalAnalogSignal /= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   *pu16Voltage = (uint16) ((((uint32)u16InternalAnalogSignal) * PMP_KU32_KL30_MUL_FACTOR) / PMP_KU32_KL30_DIV_FACTOR);
}

/**
* \brief
*     Function to provide the Battery Voltage filtered for 2ms periodic use  (KL30).
* \param
*     [u16VoltageType * pu16Voltage]
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0017] */
void PMP_runGetBatteryVoltage_2ms (u16VoltageType * pu16Voltage)
{
   /* Data */
   uint16 pmp_u16InternalAnalogSignal;

   /* Code */
   /*  Get ADC value of battery level */
   /*QAC_WARNING S 3417 3*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 2*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   /* ToDO ANE_ */
   Rte_Call_pclKL30_V_raw_Get_2ms(&pmp_u16InternalAnalogSignal);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in right side */
   pmp_u16InternalAnalogSignal /= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   *pu16Voltage = (uint16) ((((uint32)pmp_u16InternalAnalogSignal) * PMP_KU32_KL30_MUL_FACTOR) / PMP_KU32_KL30_DIV_FACTOR);
}

/**
* \brief
*     Function to get the V- voltage value from Half bridge power stage
* \param
*     [u16VoltageType * pu16Voltage]
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0064] */
void PMP_runGetMotorVn (u16VoltageType * pu16Voltage)
{
   /* Data */
   uint16 u16InternalAnalogSignal;

   /* Code */
   /*  Get ADC value of the Negative Motor Voltage */
   /*QAC_WARNING S 3417 3*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 2*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   Rte_Call_pclMotor_Vn_raw_Get(&u16InternalAnalogSignal);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in right side */
   u16InternalAnalogSignal /= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   *pu16Voltage = (uint16) ((((uint32)u16InternalAnalogSignal) * PMP_KU32_VN_MUL_FACTOR) / PMP_KU32_VN_DIV_FACTOR);
}

/**
* \brief
*     Function to get the V- voltage value from Half bridge power stage filtered for 20ms periodic use.
* \param
*     [u16VoltageType * pu16Voltage]
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0064] */
void PMP_runGetMotorVn_20ms (u16VoltageType * pu16Voltage)
{
   /* Data */
   uint16 u16InternalAnalogSignal;

   /* Code */
   /*  Get ADC value of the Negative Motor Voltage */
   /*QAC_WARNING S 3417 3*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 2*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   Rte_Call_pclMotor_Vn_raw_Get_20ms(&u16InternalAnalogSignal);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in right side */
   u16InternalAnalogSignal /= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   *pu16Voltage = (uint16) ((((uint32)u16InternalAnalogSignal) * PMP_KU32_VN_MUL_FACTOR) / PMP_KU32_VN_DIV_FACTOR);
}

/**
* \brief
*     Function to get the V- voltage value from Half bridge power stage filtered for 100ms periodic use.
* \param
*     [u16VoltageType * pu16Voltage]
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0064] */
void PMP_runGetMotorVn_100ms (u16VoltageType * pu16Voltage)
{
   /* Data */
   uint16 u16InternalAnalogSignal;

   /* Code */
   /*  Get ADC value of the Negative Motor Voltage */
   /*QAC_WARNING S 3417 3*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 2*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   Rte_Call_pclMotor_Vn_raw_Get_100ms(&u16InternalAnalogSignal);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in right side */
   u16InternalAnalogSignal /= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   *pu16Voltage = (uint16) ((((uint32)u16InternalAnalogSignal) * PMP_KU32_VN_MUL_FACTOR) / PMP_KU32_VN_DIV_FACTOR);
}

/**
* \brief
*     Function to get the V+ voltage value from Half bridge power stage
* \param
*     [u16VoltageType * pu16Voltage]
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0065] */
void PMP_runGetMotorVp (u16VoltageType * pu16Voltage)
{
   /* Data */
   uint16 u16InternalAnalogSignal;

   /* Code */
   /*  Get ADC value of the Positive Motor Voltage */
   /*QAC_WARNING S 3417 3*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 2*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   Rte_Call_pclMotor_Vp_raw_Get(&u16InternalAnalogSignal);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in right side */
   u16InternalAnalogSignal /= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   *pu16Voltage = (uint16) ((((uint32)u16InternalAnalogSignal) * PMP_KU32_VP_MUL_FACTOR) / PMP_KU32_VP_DIV_FACTOR);
}

/**
* \brief
*     Function to get the V+ voltage value from Half bridge power stage filtered for 20ms periodic use.
* \param
*     [u16VoltageType * pu16Voltage]
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0065] */
void PMP_runGetMotorVp_20ms(u16VoltageType * pu16Voltage)
{
   /* Data */
   uint16 u16InternalAnalogSignal;

   /* Code */
   /*  Get ADC value of the Positive Motor Voltage */
   /*QAC_WARNING S 3417 3*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 2*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   Rte_Call_pclMotor_Vp_raw_Get_20ms(&u16InternalAnalogSignal);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in right side */
   u16InternalAnalogSignal /= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   *pu16Voltage = (uint16) ((((uint32)u16InternalAnalogSignal) * PMP_KU32_VP_MUL_FACTOR) / PMP_KU32_VP_DIV_FACTOR);
}

/**
* \brief
*     Function to get the V+ voltage value from Half bridge power stage filtered for 100ms periodic use.
* \param
*     [u16VoltageType * pu16Voltage]
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0065] */
void PMP_runGetMotorVp_100ms(u16VoltageType * pu16Voltage)
{
   /* Data */
   uint16 u16InternalAnalogSignal;

   /* Code */
   /*  Get ADC value of the Positive Motor Voltage */
   /*QAC_WARNING S 3417 3*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 2*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   Rte_Call_pclMotor_Vp_raw_Get_100ms(&u16InternalAnalogSignal);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in right side */
   u16InternalAnalogSignal /= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   *pu16Voltage = (uint16) ((((uint32)u16InternalAnalogSignal) * PMP_KU32_VP_MUL_FACTOR) / PMP_KU32_VP_DIV_FACTOR);
}

/**
* \brief
*     Function to get the HS voltage value
* \param
*     [u16VoltageType * pu16Voltage]
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0063] */
void PMP_runGetHS1Level (u16VoltageType * pu16Voltage)
{
   /* Data */
   uint16 u16InternalAnalogSignal;

   /* Code */
   /*  Get ADC value of HighSide Switch Voltage */
   /*QAC_WARNING S 3417 3*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 2*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   Rte_Call_pclHS1_V_raw_Get(&u16InternalAnalogSignal);

#if (PMP_ALIGNMENT_ADC_CHANNELS == PMP_LEFT_ALIGNED_ADC)
   /* Realign the ADC results in right side */
   u16InternalAnalogSignal /= PMP_KU16_ADC_LEFT_ALIGNED_BIT_SHIFT;
#endif

   *pu16Voltage = (uint16) ((((uint32)u16InternalAnalogSignal) * PMP_KU32_HS_MUL_FACTOR) / PMP_KU32_HS_DIV_FACTOR);
}

/**
* \brief
*     Function to monitor the battery voltage.
* \param
*     None.
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0012] */
void PMP_runSurveyBatteryVoltage ( void )
{
   uint16 pmp_u16BatteryVoltageAbsDiff;
   uint16 pmp_u16InternalAnalogSignal;

   /* Get the raw value (ADC value) of the KL30 voltage */
   /*QAC_WARNING S 3417 3*/ /*The comma operator has been used outside a 'for' statement*/
   /*QAC_WARNING S 3426 2*/ /*Right hand side of comma expression has no side effect and its value is not used*/
                     /*The RTE macro is automatically generated by Systemdesk with a comma*/
   Rte_Call_pclKL30_V_raw_Get(&pmp_u16InternalAnalogSignal);

   /* initialized to the first value */
   PMP_stBatterySurveyParam.u16OldRawBatteryVoltage = pmp_u16InternalAnalogSignal;

   /* Check if the battery voltage is inside the range */
   if ( ( PMP_stBatterySurveyParam.u16MaxBatteryVoltageADCFormat > pmp_u16InternalAnalogSignal ) &&
        ( PMP_stBatterySurveyParam.u16MinBatteryVoltageADCFormat < pmp_u16InternalAnalogSignal )
      )
   { /* Voltage is inside the range */
      /* QAC_WARNING S 3491 4 */ /* Using conditional operator in a macro.
                           * Operator "<" is used to determine the expression sign */
      /* QAC_WARNING S 4393 2 */ /* A composite expression of 'essentially unsigned' type is being cast to a different type category, signed.
                           * uint16 variable are converted into sint32 variable in order to avoid a wrong calculation (eg. 0xFFFF u16 interpreted as -1 in S16) */
      pmp_u16BatteryVoltageAbsDiff = (uint16)(U16_GET_ABSOLUTE_VALUE_FROM_S16((sint16)(pmp_u16InternalAnalogSignal) - (sint16)(PMP_stBatterySurveyParam.u16OldRawBatteryVoltage) ));

      /* Are the variation inside the authorized range ? */
      if ( PMP_stBatterySurveyParam.u16MinDiffVoltageToValidateBatterySurvey > pmp_u16BatteryVoltageAbsDiff )
      /* [COVERS: DSG_PMP_0014] */
      {
         if( NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8NbOccurenceToValidateBatteryVoltage <= PMP_stBatterySurveyParam.u8CounterToValidateBatterySurvey )
         {
            /* Battery is stable */
            PMP_stBatterySurveyParam.u8BatteryVoltageSurveyState = KU8_BATTERY_STABLE;
         }
         else
         {
            /* Delay to avoid error before qualify the battery as stable (NVP parameter) */
            PMP_stBatterySurveyParam.u8CounterToValidateBatterySurvey += KU8_ONE;
         }
      }
      else
      /* [COVERS: DSG_PMP_0015] */
      {
         /* Voltage difference between two consecutive measurement is greater than NVP_DeltaV => Battery is unstable */
         PMP_stBatterySurveyParam.u8CounterToValidateBatterySurvey = KU8_ZERO;
         PMP_stBatterySurveyParam.u8BatteryVoltageSurveyState = KU8_BATTERY_UNSTABLE;
      }
   }
   else
   /* [COVERS: DSG_PMP_0013] */
   {
      /* Voltage is outside the range => Battery is unstable */
      PMP_stBatterySurveyParam.u8CounterToValidateBatterySurvey = KU8_ZERO;
      PMP_stBatterySurveyParam.u8BatteryVoltageSurveyState = KU8_BATTERY_UNSTABLE;
   }
   /* update the old value */
   PMP_stBatterySurveyParam.u16OldRawBatteryVoltage = pmp_u16InternalAnalogSignal;
}

/**
* \brief
*     Return the actual battery state
* \param
*     u8BatteryVoltageSurveyStatusType *pu8BatteryVoltageSurveyStatus
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
/* [COVERS: DSG_PMP_0066] */
void PMP_runGetBatteryVoltageSurveyStatus(u8BatteryVoltageSurveyStatusType *
  pu8BatteryVoltageSurveyStatus)
{
   *pu8BatteryVoltageSurveyStatus = PMP_stBatterySurveyParam.u8BatteryVoltageSurveyState;
}

/**
 * \brief
 *		Defined macro from C file.
 */
#define PMP_AC_PhysicalMeasuresProvider_STOP_SEC_CODE
#include "PMP_AC_PhysicalMeasuresProvider_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
