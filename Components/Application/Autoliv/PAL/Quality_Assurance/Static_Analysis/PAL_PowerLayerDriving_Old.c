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
$Revision: 1.1.2.8 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/PAL/Quality_Assurance/Static_Analysis/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup PAL_PowerLayerDriving.c PAL
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_PAL_AC_PowerAbstractionLayer.h"
#include "Dio.h"
#include "PAL_private.h"
#include "Nvp_Generated.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_START_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"

static void pal_StopMotorRotation (void);
static void pal_DriveMotorInTensioning ( const uint16 cu16AbsoluteMotorCommand );
static void pal_DriveMotorInReleasing ( const uint16 cu16AbsoluteMotorCommand );

/**
 * \brief
 *		Defined macro from C file.
 */
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
 *	    Function used to stop the motor rotation
 *      Local function in charge of the de-activation of the power stage
 *      shall put the PWM signals to their defaults state
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
static void pal_StopMotorRotation (void)
{

   /* reset PWM signals to their default state to break the motor rotation and stop it */
   Rte_Call_pclPwmServices_SetDutyCycle (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u8PwmChannelId ,
                      PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16IdleDutyCycleLevel );

   Rte_Call_pclPwmServices_SetDutyCycle (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u8PwmChannelId ,
                      PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16IdleDutyCycleLevel );
}

/**
 * \brief
 *	    Function used to drive the motor in tensioning direction
 *
 * \param
 * 		 const uint16 cu16AbsoluteMotorCommand: Consign that shall be applied on Half Bridges
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
static void pal_DriveMotorInTensioning ( const uint16 cu16AbsoluteMotorCommand )
{
   sint32 pal_s32LocalDutyCycle;
   uint16 pal_u16FinalDutyCycle;
   
   /* Reset timer for the next free-wheeling phase */
   PAL_u8FreeWheelingTimer = PAL_CFG_FREEWHEELING_TIME;

   /* First set the "not toggling" Half Bridge in its Idle state */
   Rte_Call_pclPwmServices_SetDutyCycle (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u8PwmChannelId ,
                      PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16IdleDutyCycleLevel );

   /* Correct the consign to take into consideration the HW impacts (slew rate etc ...)
    * And rescale the power order to a [0 ; 0x8000] full range
    * */
   pal_s32LocalDutyCycle  = ((sint32)cu16AbsoluteMotorCommand) * ((sint32)PAL_Cfg_InternalData.u32SlopeToApplyNumerator);
   pal_s32LocalDutyCycle += PAL_Cfg_InternalData.s32OffsetToApplyNumerator;
   /* QAC_WARNING S 3103 1 */ /* Result of signed division or remainder operation may be implementation defined. */
   pal_s32LocalDutyCycle /= ((sint32)PAL_CFG_DUTY_CYCLE_ADAPT_DEN);

   /* limits value management */
   if ( KS32_ZERO > pal_s32LocalDutyCycle)
   {
      /* In case of negative motor power order, apply the Idle consign value */
      pal_u16FinalDutyCycle = PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16IdleDutyCycleLevel;
   }
   else if ( ((sint32)PAL_CFG_HIGH_LIMIT_LLD_CMD) < pal_s32LocalDutyCycle )
   {
      /* In case of result out of the upper bound, apply the upper limit */
      pal_u16FinalDutyCycle = KU16_ZERO;
   }
   else
   {
      /* In case of result within the valid range, adapt the consign to HW constraints
       * i.e. the motor is driven with LOW mosfet
       * */
      pal_u16FinalDutyCycle = PAL_CFG_HIGH_LIMIT_LLD_CMD - ((uint16)pal_s32LocalDutyCycle);
   }

   /* Store data in the local data structure */
   PAL_Cfg_InternalData.s16AdaptedDutyCycleCommand = (sint16) pal_u16FinalDutyCycle;
   PAL_Cfg_InternalData.s16RawDutyCycleCommand = (sint16) cu16AbsoluteMotorCommand;

   /* Apply the new duty cycle */
   Rte_Call_pclPwmServices_SetDutyCycle (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u8PwmChannelId ,
                      pal_u16FinalDutyCycle );

   /* Activation of the H-bridges */
   Dio_WriteChannel (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16DriveEnableDioId,(uint8)STD_HIGH);
   Dio_WriteChannel (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16DriveEnableDioId,(uint8)STD_HIGH);

   /* Store the status of Enable Command into local structure */
   PAL_Cfg_InternalData.u8EnableCommand = (uint8)STD_HIGH;
}

/**
 * \brief
 *	    Function used to drive the motor in releasing direction
 *
 * \param
 * 		 const uint16 cu16AbsoluteMotorCommand: Consign that shall be applied on Half Bridges
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
static void pal_DriveMotorInReleasing ( const uint16 cu16AbsoluteMotorCommand )
{
   sint32 pal_s32LocalDutyCycle;
   uint16 pal_u16FinalDutyCycle;

   /* Reset timer for the next free-wheeling phase */
   PAL_u8FreeWheelingTimer = PAL_CFG_FREEWHEELING_TIME;

   /* First set the "not toggling" Half Bridge in its Idle state */
   Rte_Call_pclPwmServices_SetDutyCycle (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u8PwmChannelId ,
                      PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16IdleDutyCycleLevel );

   /* Correct the consign to take into consideration the HW impacts (slew rate etc ...)
    * And rescale the power order to a [0 ; 0x8000] full range
    * */
   pal_s32LocalDutyCycle  = ((sint32)cu16AbsoluteMotorCommand) * ((sint32)PAL_Cfg_InternalData.u32SlopeToApplyNumerator);
   pal_s32LocalDutyCycle += PAL_Cfg_InternalData.s32OffsetToApplyNumerator;
   /* QAC_WARNING S 3103 1 */ /* Result of signed division or remainder operation may be implementation defined. */
   pal_s32LocalDutyCycle /= ((sint32)PAL_CFG_DUTY_CYCLE_ADAPT_DEN);

   /* limits value management */
   if ( KS32_ZERO > pal_s32LocalDutyCycle)
   {
      /* In case of negative motor power order, apply the Idle consign value */
      pal_u16FinalDutyCycle = PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16IdleDutyCycleLevel;
   }
   else if ( ((sint32)PAL_CFG_HIGH_LIMIT_LLD_CMD) < pal_s32LocalDutyCycle )
   {
      /* In case of result out of the upper bound, apply the upper limit */
      pal_u16FinalDutyCycle = KU16_ZERO;
   }
   else
   {
      /* In case of result within the valid range, adapt the consign to HW constraints
       * i.e. the motor is driven with LOW mosfet
       * */
      pal_u16FinalDutyCycle = PAL_CFG_HIGH_LIMIT_LLD_CMD - ((uint16)pal_s32LocalDutyCycle);
   }

   /* Store data in the local data structure */
   PAL_Cfg_InternalData.s16AdaptedDutyCycleCommand = (sint16)pal_u16FinalDutyCycle;
   PAL_Cfg_InternalData.s16RawDutyCycleCommand = -((sint16)cu16AbsoluteMotorCommand);

   /* Apply the new duty cycle */
   Rte_Call_pclPwmServices_SetDutyCycle (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u8PwmChannelId ,
                      pal_u16FinalDutyCycle );

   /* Activation of the H-bridges */
   Dio_WriteChannel (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16DriveEnableDioId,(uint8)STD_HIGH);
   Dio_WriteChannel (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16DriveEnableDioId,(uint8)STD_HIGH);

   /* Store the status of Enable Command into local structure */
   PAL_Cfg_InternalData.u8EnableCommand = (uint8)STD_HIGH;
}
/**
 * \brief
 *	     External service that will disable the HW components that drive the motor
 *
 * \param
 * 		 void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
/* [COVERS: DSG_PAL_0038, DSG_PAL_0040] */
void PAL_DisablePowerStage (void)
{
   /* DeActivation of the H-bridges */
   Dio_WriteChannel (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16DriveEnableDioId,(uint8)STD_LOW);
   Dio_WriteChannel (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16DriveEnableDioId,(uint8)STD_LOW);

   PAL_Cfg_InternalData.u8EnableCommand = (uint8)STD_LOW;
}

/**
 * \brief
 *	     External service that see the power stage in IDLE state
 *
 * \param
 * 		 void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
/* [COVERS: DSG_PAL_0069] */
void PAL_StartFreeWheelingState (void)
{
   /* Apply the maximum duty cycle */
   Rte_Call_pclPwmServices_SetDutyCycle ( PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u8PwmChannelId ,
                      PAL_CFG_HIGH_LIMIT_LLD_CMD );
   Rte_Call_pclPwmServices_SetDutyCycle ( PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u8PwmChannelId ,
                      PAL_CFG_HIGH_LIMIT_LLD_CMD );

   /* Activation of the H-bridges */
   Dio_WriteChannel (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_P_ID].u16DriveEnableDioId,(uint8)STD_HIGH);
   Dio_WriteChannel (PAL_kstHardWareTopology.astHBridgeDef[PAL_CFG_KU8_HB_N_ID].u16DriveEnableDioId,(uint8)STD_HIGH);

   PAL_Cfg_InternalData.u8EnableCommand = (uint8)STD_HIGH;
}

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
 * \brief
 *	     External service called by upper layer in order to drive the motor in case of belt function activation
 *
 * \param
 * 		 sint16 s16MotorPowerDutyCycle:
 * 		     Duty cycle for HB power stage
 *           Positive value means tensioning direction
 *           Negative value means releasing direction
 *           Range [ -6400 ; 6400 ]
 * 		 uint16 u16BoostDutyCyle:
 * 		     Duty cycle for Booster stage
 * 		     Range [ 0 ; 512]
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
/* [COVERS: DSG_PAL_0017] */
void PAL_runSetPowerOrder ( s16MotorPowerOrderType s16MotorPowerOrder ,
                                     u16BoostPWMOrderType u16BoostDutyCycle )
{
   uint16         pal_u16AbsoluteMotorCommand;

   /* Mask containing the state where belt functions are allowed */
   const uint8    pal_u8BeltFunctionControlMask = (PAL_KU8_IDLE_MODE_STATE | PAL_KU8_ACTIVATION_MODE_STATE);

   /* Check if this function is allowed to control the power stage */
   if ( KU8_ZERO != (pal_u8BeltFunctionControlMask & PAL_u8ModeState) )
   {
      /* Compute the absolute value of motor command, it will be easier for the next */
      /* QAC_WARNING S 3491 1 */ /* Macro contains a conditional operator */
      pal_u16AbsoluteMotorCommand = U16_GET_ABSOLUTE_VALUE_FROM_S16 ( s16MotorPowerOrder );

      if ( KU16_ZERO == pal_u16AbsoluteMotorCommand )
      {
         /* Store data in the local data structure */
         PAL_Cfg_InternalData.s16AdaptedDutyCycleCommand = KS16_ZERO;
         PAL_Cfg_InternalData.s16RawDutyCycleCommand = KS16_ZERO;

         /* Disable power layer */
         /* [COVERS: DSG_PAL_0018] */
         pal_StopMotorRotation ();
      }
      else if ( KS16_ZERO > s16MotorPowerOrder )
      {
         /* Drive the motor in releasing direction */
         /* [COVERS: DSG_PAL_0019] */
         pal_DriveMotorInReleasing ( pal_u16AbsoluteMotorCommand );
      }
      else
      {
         /* Drive the motor in tensioning direction */
         /* [COVERS: DSG_PAL_0020] */
         pal_DriveMotorInTensioning ( pal_u16AbsoluteMotorCommand );
      }
   }
   else
   {
      /* PAL component is in a mode that does not allow this function call
       * Nothing to do : the power stage could be in auto diagnostic mode
       * */
   }
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

