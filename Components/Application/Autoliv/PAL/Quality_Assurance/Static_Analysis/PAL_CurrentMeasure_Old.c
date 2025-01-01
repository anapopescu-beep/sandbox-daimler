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
$Revision: 1.1.2.7 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/PAL/Quality_Assurance/Static_Analysis/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup PAL_CurrentMeasure.c PAL
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "PAL_private.h"
#include "Math.h"
#include "Nvp_Generated.h"
#include "Dio.h"
#include "Rte_PAL_AC_PowerAbstractionLayer.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
#define PAL_KU8_CONVERT_CENTIAMP_TO_MILLIAMP                   ((uint8)   10)
#define PAL_S32_CONVERT_A_TO_MA                                ((sint32)1000)

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_START_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"
/**
 * \brief
 *		Variable for compute current HalfBridgeP
 */
static void pal_ComputeCurrentHalfBridgeP ( sint32 * const ps32MeasuredCurrent );
/**
 * \brief
 *		Variable for compute current HalfBridgeN
 */
static void pal_ComputeCurrentHalfBridgeN ( sint32 * const ps32MeasuredCurrent );

/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_STOP_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"


/******************************************************************************
MODULE DEFINES
******************************************************************************/

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
 *	    Function that provides the current in Milli Ampere for HP
 *
 * \param
 * 		sint32 * ps32MeasuredCurrent:  Value of the Motor Current extrapolated from Half Bridge P
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
static void pal_ComputeCurrentHalfBridgeP(sint32 *const ps32MeasuredCurrent)
{
   uint16 pal_u16InternalAnalogSignal;

   /* QAC_WARNING S 0310 3 */ /* Casting to different object pointer type */
   const stInterpolationParam_Type pal_cstLookUpTable = {
      (const uint8 *)(&NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CalibADCTens[0]),     /* x_table: vector with axis values */
      (const uint8 *)(&NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CurrentProbeTens[0]), /* y_table: vector with axis values */
      PAL_KU8_NB_INTERP_PTS_HB_CALIB,
      KU8_X16_BIndian | KU8_Y16_BIndian,
      KU8_IN_RANGE_LINEAR_INTER | KU8_BELOW_RANGE_UPPER_INTER | KU8_OVER_RANGE_LOWER_INTER};

   /* Check the enable command */
   /* The goal is to return a null measured current if the enable command is LOW */
   if (((uint8)STD_HIGH == PAL_Cfg_InternalData.u8EnableCommand) && (B_FALSE == PAL_Cfg_InternalData.bIsPwrStgInSelfProtection))
   {
      /* Half bridge is activated. Compute the current consumption */

      /*QAC_WARNING S 3417 4*/ /*The comma operator has been used outside a 'for' statement*/
      /*QAC_WARNING S 3426 3*/ /*Right hand side of comma expression has no side effect and its value is not used*/
      /*The RTE macro is automatically generated by Systemdesk with a comma*/
      /* Input of LuT CurrentConsumption in LSB */
      Rte_Call_pclMotor_Ip_raw_Get(&pal_u16InternalAnalogSignal);

      /* Calculation of CurrentConsumtion in mA */
      *ps32MeasuredCurrent = (sint32)PAL_KU8_CONVERT_CENTIAMP_TO_MILLIAMP * (sint32)u32InterpolateFromTable((uint32)pal_u16InternalAnalogSignal, &pal_cstLookUpTable);
   }
   else
   {
      /* Half bridge is deactivated. Reset the current consumption */
      *ps32MeasuredCurrent = KS32_ZERO;
   }
}

/**
 * \brief
 *	    Function that provides the current in Milli Ampere for HN
 *
 * \param
 * 		sint32 * ps32MeasuredCurrent:  Value of the Motor Current extrapolated from Half Bridge N
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
static void pal_ComputeCurrentHalfBridgeN(sint32 *const ps32MeasuredCurrent)
{
   uint16 pal_u16InternalAnalogSignal;

   /* QAC_WARNING S 0310 3 */ /* Casting to different object pointer type */
   const stInterpolationParam_Type pal_cstLookUpTable = {
      (const uint8 *)(&NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CalibADCRel[0]),     /* x_table: vector with axis values */
      (const uint8 *)(&NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData.NVP_au16CurrentProbeRel[0]), /* y_table: vector with axis values */
      PAL_KU8_NB_INTERP_PTS_HB_CALIB,
      KU8_X16_BIndian | KU8_Y16_BIndian,
      KU8_IN_RANGE_LINEAR_INTER | KU8_BELOW_RANGE_UPPER_INTER | KU8_OVER_RANGE_LOWER_INTER};

   /* Check the enable command */
   /* The goal is to return a null measured current if the enable command is LOW */
   if (((uint8)STD_HIGH == PAL_Cfg_InternalData.u8EnableCommand) && (B_FALSE == PAL_Cfg_InternalData.bIsPwrStgInSelfProtection))
   {
      /* Half bridge is activated. Compute the current consumption */

      /*QAC_WARNING S 3417 4*/ /*The comma operator has been used outside a 'for' statement*/
      /*QAC_WARNING S 3426 3*/ /*Right hand side of comma expression has no side effect and its value is not used*/
      /*The RTE macro is automatically generated by Systemdesk with a comma*/
      /* Input of LuT CurrentConsumption in LSB */
      Rte_Call_pclMotor_In_raw_Get(&pal_u16InternalAnalogSignal);

      /* Calculation of CurrentConsumtion in mA */
      *ps32MeasuredCurrent = ((sint32)KU32_ZERO) - (((sint32)PAL_KU8_CONVERT_CENTIAMP_TO_MILLIAMP) * ((sint32)u32InterpolateFromTable((uint32)pal_u16InternalAnalogSignal, &pal_cstLookUpTable)));
   }
   else
   {
      /* Half bridge is deactivated. Reset the current consumption */
      *ps32MeasuredCurrent = KS32_ZERO;
   }
}

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
 * \brief
 *	    Function that provides the current in Milli Ampere
 *
 * \param
 * 		s32MotorCurrentInmAType * ps32MotorCurrentInmA:  Value of the Motor Current
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
/* QAC_WARNING S 3227 1 */ /* Pointer is never modified but not declared as const, before of RTE definition */
/* [COVERS: DSG_PAL_0011, DSG_PAL_0013] */
void PAL_runReadMotorCurrentInmA(s32MotorCurrentInmAType *ps32MotorCurrentInmA)
{
   /* Data */
   sint32 pal_s32MotorCurrentMilliAmpP;
   sint32 pal_s32MotorCurrentMilliAmpN;
   sint16 pal_s16MotorPowerOrder;

   pal_s16MotorPowerOrder = PAL_Cfg_InternalData.s16RawDutyCycleCommand;

   if (KS16_ZERO != pal_s16MotorPowerOrder)
   {
      /* Check sign for the motor power order and select the Isense accordingly */
      /* Motor is driven in tensioning direction */
      if (pal_s16MotorPowerOrder > KS16_ZERO)
      {
         /* [COVERS: DSG_PAL_0014] */
         pal_ComputeCurrentHalfBridgeP(ps32MotorCurrentInmA);
      }
      /* Motor is driven in releasing direction */
      else
      {
         /* [COVERS: DSG_PAL_0015] */
         pal_ComputeCurrentHalfBridgeN(ps32MotorCurrentInmA);
      }
   }
   /* In case of a Null power order, the motor current is the sum of the both Isense */
   else
   /* [COVERS: DSG_PAL_0016] */
   {
      pal_ComputeCurrentHalfBridgeP(&pal_s32MotorCurrentMilliAmpP);
      pal_ComputeCurrentHalfBridgeN(&pal_s32MotorCurrentMilliAmpN);

      *ps32MotorCurrentInmA = (sint32)(pal_s32MotorCurrentMilliAmpP - pal_s32MotorCurrentMilliAmpN);
   }
}

/**
 * \brief
 *	    Function that provides the current in Ampere
 *
 * \param
 * 		s8MotorCurrentInAType * ps8MotorCurrentInA:  Value of the Motor Current
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
/* QAC_WARNING S 3227 1 */ /* Pointer is never modified but not declared as const, before of RTE definition */
/* [COVERS: DSG_PAL_0011, DSG_PAL_0012] */
void PAL_runReadMotorCurrentInA(s8MotorCurrentInAType *ps8MotorCurrentInA)
{
   sint32 pal_s32MotorCurrentInmA;
   sint8 pal_s8MotorCurrentInA;

   PAL_runReadMotorCurrentInmA(&pal_s32MotorCurrentInmA);

   /* QAC_WARNING S 3103 1 */ /* Result of signed division or remainder operation may be implementation defined */
   pal_s8MotorCurrentInA = (sint8)((sint32)(pal_s32MotorCurrentInmA / PAL_S32_CONVERT_A_TO_MA));

   *ps8MotorCurrentInA = pal_s8MotorCurrentInA;
}
/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_STOP_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/
