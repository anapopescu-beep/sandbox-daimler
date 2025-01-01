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
 *  @defgroup PAL_config.c PAL
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "PAL_private.h"
#include "Nvp_Generated.h"
#include "Rte_PAL_AC_PowerAbstractionLayer.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/

/******************************************************************************
MODULE TYPES
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_START_SEC_VAR_UNSPECIFIED
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"
/**
 * \brief
 *		This variable is used to store static data
 */
PAL_tHBridgeCurrentValues PAL_Cfg_InternalData;

/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_STOP_SEC_VAR_UNSPECIFIED
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"
/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_START_SEC_CONST_UNSPECIFIED
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"

/**
 * \brief
 *		Hardware topology used by ECU
 */
const PAL_tTopologyConfiguration PAL_kstHardWareTopology =
{
   { /* astHBridgeDef[PAL_CFG_TOPO_HBRIDGE_NB] - 2 HB on this variant */
      { /* HB_P */
         (uint16)100                                     /* uint16      u16LinarSlopeDutyCycle;        */,
         (sint16)0                                       /* sint16      s16LinarOffsetDutyCycle;       */,
         PAL_CFG_HIGH_LIMIT_LLD_CMD                      /* uint16      u16IdleDutyCycleLevel;         */,
         DioConf_DioChannel_HB_P_EN_RD                   /* uint16      u16ReadEnableDioId;            */,
         DioConf_DioChannel_HB_P_EN_mcu                  /* uint16      u16DriveEnableDioId;           */,
         PWM_KU8_CH_ID_HB_P                              /* uint8       u8PwmChannelId;                */
      },
      { /* HB_N */
         (uint16)100                                     /* uint16      u16LinarSlopeDutyCycle;        */,
         (sint16)0                                       /* sint16      s16LinarOffsetDutyCycle;       */,
         PAL_CFG_HIGH_LIMIT_LLD_CMD                      /* uint16      u16IdleDutyCycleLevel;         */,
         DioConf_DioChannel_HB_N_EN_RD                   /* uint16      u16ReadEnableDioId;            */,
         DioConf_DioChannel_HB_N_EN_mcu                  /* uint16      u16DriveEnableDioId;           */,
         PWM_KU8_CH_ID_HB_N                              /* uint8       u8PwmChannelId;                */
      }
   }
};
/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_STOP_SEC_CONST_UNSPECIFIED
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"
/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
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
 *	    Function that provides the Motor power order applied on Half bridges
 *
 * \param
 * 		s16MotorPowerOrderType * ps16MotorPowerOrder - Value of the duty cycle [-6400 ; 6400]1
 *       Negative value means : releasing direction
 *       Positive value means : tensioning direction
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
/* QAC_WARNING S 3227 1 */ /* Input which is never modified can not be declared as const, due to RTE definition */
/*COVERS: DSG_PAL_0011 */
void PAL_runGetPWMOrder(s16MotorPowerOrderType * ps16MotorPowerOrder)
{
   *ps16MotorPowerOrder = PAL_Cfg_InternalData.s16RawDutyCycleCommand;
}

/**
 * \brief
 *	    Initialization function for the configuration
 *
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
/* [COVERS: DSG_PAL_0038; DSG_PAL_0039] */
void pal_Cfg_Init ( void )
{
   uint16   pal_u16InitSlopeValue;
   sint16   pal_s16InitOffsetValue;

   /* Initialization of static data for PAL component */
   PAL_Cfg_InternalData.s16AdaptedDutyCycleCommand = KS16_ZERO;
   PAL_Cfg_InternalData.s16RawDutyCycleCommand     = KS16_ZERO;
   PAL_Cfg_InternalData.u8EnableCommand            = KU8_ZERO;
   PAL_Cfg_InternalData.bIsPwrStgInSelfProtection  = B_FALSE;

   if ( PAL_CFG_SLOPE_CTRL_MAX_VALUE < PAL_kstHardWareTopology.astHBridgeDef[0].u16LinarSlopeDutyCycle )
   {
      /* Apply default value */
      pal_u16InitSlopeValue = PAL_CFG_SLOPE_DEFAULT_VALUE;
   }
   else
   {
      /* nothing to do : slope value is valid */
      pal_u16InitSlopeValue = PAL_kstHardWareTopology.astHBridgeDef[0].u16LinarSlopeDutyCycle;
   }

   if ( (PAL_CFG_OFFSET_CTRL_MAX_VALUE < PAL_kstHardWareTopology.astHBridgeDef[0].s16LinarOffsetDutyCycle) ||
        (PAL_CFG_OFFSET_CTRL_MIN_VALUE > PAL_kstHardWareTopology.astHBridgeDef[0].s16LinarOffsetDutyCycle)
      )
   {
      /* Apply default value */
      pal_s16InitOffsetValue = PAL_CFG_OFFSET_DEFAULT_VALUE;
   }
   else
   {
      /* nothing to do : offset value is valid */
      pal_s16InitOffsetValue = PAL_kstHardWareTopology.astHBridgeDef[0].s16LinarOffsetDutyCycle;
   }

   PAL_Cfg_InternalData.u32SlopeToApplyNumerator   = ((uint32)PAL_CFG_DUTY_CYCLE_ADAPT_A_NUM) *
                                                     ((uint32)pal_u16InitSlopeValue);

   PAL_Cfg_InternalData.s32OffsetToApplyNumerator  = ((sint32)PAL_CFG_DUTY_CYCLE_ADAPT_B_NUM) *
                                                     ((sint32)pal_s16InitOffsetValue);

   /* Initialization of static data for auto tests execution */
   pal_AT_Init ();
}
/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_STOP_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
