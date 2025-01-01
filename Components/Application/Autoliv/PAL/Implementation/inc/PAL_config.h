/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the information (interfaces, definitions and data) provided
by the module PAL.

These are globally visible.

Current revision: $Revision: 1.2.1.5 $
Checked in:       $Date: 2022/08/09 17:21:08CEST $

*************************************************************************/
#ifndef PAL_V2_INC_PAL_CONFIG_H_
#define PAL_V2_INC_PAL_CONFIG_H_


/************************************************************************
Inclusions
*************************************************************************/
#include "common.h"
#include "Std_Types.h"

#include "Dio.h"
#include "Port.h"
#include "Port_Cfg.h"

#include "Pwm_17_GtmCcu6_Cfg.h"

/************************************************************************
Declaration of constants
*************************************************************************/

#define PAL_CFG_TOPO_HBRIDGE_NB                          (2u)
#define PAL_CFG_KU8_HB_P_ID                              (0u)
#define PAL_CFG_KU8_HB_N_ID                              (1u)

/* To enable/disable the booster function */
/* 0 = Disabled, 1 = Enabled (1 booster stage) */
#define PAL_CFG_TOPO_SHUNT_NB                            (0u)
#define PAL_CFG_TOPO_FULL_BRIDGE_NB                      (0u)

#define PAL_CFG_FREEWHEELING_TIME                        ((uint8)   100)
#define PAL_CFG_PERIODIC_FCT_CALL                        ((uint8)     2)

/* Output limits for duty cycle values sent to PWM driver */
#define PAL_CFG_HIGH_LIMIT_LLD_CMD                       ((uint16)0x8000u)
#define KU16_ONE_HUNDRED                                 ((uint16)0x0100u)

/* Constant values used to adapt duty cycle to HW constraints */
#define PAL_CFG_DUTY_CYCLE_ADAPT_DEN                     ((uint16)  625)
#define PAL_CFG_DUTY_CYCLE_ADAPT_ROUND                   ((uint16)  312) /* PAL_CFG_DUTY_CYCLE_ADAPT_DEN / 2 */
#define PAL_CFG_DUTY_CYCLE_ADAPT_A_NUM                   ((uint16)   32)
#define PAL_CFG_DUTY_CYCLE_ADAPT_B_NUM                   ((uint16) 2048)

#define PAL_CFG_SLOPE_CTRL_MAX_VALUE                     ((uint16)  200)   /* 1lsb=0.01  => a = [0;2]    */
#define PAL_CFG_SLOPE_DEFAULT_VALUE                      ((uint16)  100)   /* 1lsb=0.01  => a = 1.00     */
#define PAL_CFG_OFFSET_CTRL_MAX_VALUE                    ((sint16)10000)   /* 1lsb=0.01% => b = [0;100%] */
#define PAL_CFG_OFFSET_CTRL_MIN_VALUE                    ((sint16)-10000)   /* 1lsb=0.01% => b = [0;100%] */
#define PAL_CFG_OFFSET_DEFAULT_VALUE                     ((sint16)    0)   /* 1lsb=0.01% => b = 0%       */

#define PAL_KU8_NB_INTERP_PTS_HB_CALIB                       ((uint8)   5)

/*************************************************************************
Declaration of macros
*************************************************************************/

/*************************************************************************
Declaration of types
*************************************************************************/
typedef struct PAL_tHBridgeDefinition_Tag
{
   uint16      u16LinarSlopeDutyCycle;
   sint16      s16LinarOffsetDutyCycle;
   uint16      u16IdleDutyCycleLevel;
   uint16      u16ReadEnableDioId;
   uint16      u16DriveEnableDioId;
   uint8       u8PwmChannelId;
}PAL_tHBridgeDefinition;

typedef struct PAL_tHBridgeCurrentValues_Tag
{
   uint32      u32SlopeToApplyNumerator;
   sint32      s32OffsetToApplyNumerator;
   sint16      s16RawDutyCycleCommand;
   sint16      s16AdaptedDutyCycleCommand;
   uint8       u8EnableCommand;
   boolean     bIsPwrStgInSelfProtection;
}PAL_tHBridgeCurrentValues;

typedef struct PAL_tBoostDriverDefinition_Tag
{
   uint16      u16IdleDutyCycleLevel;
   uint8       u8PwmChannelId;
   uint8       u8PwmCPChannelId;
   uint16      u8DioChannelHighId;
   uint16      u8DioChannelLowId;
}PAL_tBoostDriverDefinition;

typedef struct PAL_tFullBridgeDefinition_Tag
{
   uint16      u16LinarSlopeNumDutyCycle;
   uint16      u16LinarSlopeDenDutyCycle;
   uint16      u16LinarOffsetNumDutyCycle;
   uint16      u16LinarOffsetDenDutyCycle;
   uint16      u16IdleDutyCycleLevel;
   uint16      u16ReadEnableDioId;
   uint16      u16DriveEnableDioId;
   uint8       u8DirectionDioId;
   uint8       u8PwmChannelId;
}PAL_tFullBridgeDefinition;

typedef struct PAL_tPrelBoostTestData_Tag
{
   uint16      u16PreBoostDeadTimeCounter;
   uint8       u8PreliminaryBoostTestState;
   uint8       u8PreBoostStep1State;
   uint8       u8PreBoostStep2State;
   uint8       u8PreBoostStep3State;
   uint8       u8PreBoostStep4State;
   uint8       u8PreBoostNbTries;
   uint8       u8PreBoostStep1ChargeCounter;
   uint8       u8PreBoostStep1DischargeCounter;
}PAL_tPrelBoostTestData;

typedef struct PAL_tVBoostTestData_Tag
{
   uint16      u16BoostStep1VPMotorStart;
   uint16      u16DeadTimeCounter;
   uint8       u8BoostTestState;
   uint8       u8BoostStep1State;
   uint8       u8BoostStep2State;
   uint8       u8BoostStep1StateMachineCounter;
   uint8       u8BoostStep2StateMachineCounter;
   uint8       u8BoostNbrOfTryCounter;
   uint8       u8BoostBatteryConditions;
   uint8       u8LostBatteryConditionsCounter;
}PAL_tVBoostTestData;

typedef struct PAL_tAutoTestData_Tag
{
   PAL_tPrelBoostTestData  stPreliminaryBoostData;
   PAL_tVBoostTestData     stVboostData;
   uint32                  u32MotorOrderMediumThrsTimeCounter;
   uint32                  u32MotorCurrentMediumThrsTimeCounter;
   uint16                  u16HighSideSw_DeadTimeCounter;
   uint16                  u16MotorOrderMediumThrsTimeResetCounter;
   uint16                  u16MotorCurrentMediumThrsTimeResetCounter;
   uint16                  u16MotorOrderHighThrsTimeCounter;
   uint16                  u16MotorCurrentHighThrsTimeCounter;
   uint16                  u16MotorOrderHighThrsTimeResetCounter;
   uint16                  u16MotorCurrentHighThrsTimeResetCounter;
   uint16                  u16MotorOrderErrorResetTimeCounter;
   uint16                  u16MotorCurrentErrorResetTimeCounter;
   uint8                   u8PowerOrderExecutedCycleMemory;
   uint8                   u8PowerCurrentExecutedCycleMemory;
   uint8                   u8MosfetOC_State;
   uint8                   u8MosfetOC_NbTries;
   uint8                   u8MotorBlockedFailedCntr;
   uint8                   u8MotorBlockedPassedCntr;
   uint8                   u8MotorSCFailedCntr;
   uint8                   u8MotorSCPassedCntr;
   uint8                   u8HighSideSw_TestState;
   uint8                   u8HighSideSw_NbTries;
   uint8                   u8HighSideSw_FreeWheelingTimer;
} PAL_tAutoTestData;


typedef struct PAL_tTopologyConfiguration_Tag
{
#if (PAL_CFG_TOPO_HBRIDGE_NB == 1u)
   PAL_tHBridgeDefinition        stHBridgeDef;
#elif (PAL_CFG_TOPO_HBRIDGE_NB > 1u)
   PAL_tHBridgeDefinition        astHBridgeDef[PAL_CFG_TOPO_HBRIDGE_NB];
#else
#endif

   PAL_tBoostDriverDefinition   stBoosterDef;

#if (PAL_CFG_TOPO_SHUNT_NB == 1u)
#else
#endif
#if (PAL_CFG_TOPO_FULL_BRIDGE_NB == 1u)
   PAL_tFullBridgeDefinition     stFullBridgeDef;
#else
#endif
}PAL_tTopologyConfiguration;


/*************************************************************************
Declaration of variables
*************************************************************************/
#define PAL_AC_PowerAbstractionLayer_START_SEC_VAR_UNSPECIFIED
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"

extern PAL_tHBridgeCurrentValues PAL_Cfg_InternalData;
extern PAL_tAutoTestData         PAL_Cfg_AT_InternalData;

#define PAL_AC_PowerAbstractionLayer_STOP_SEC_VAR_UNSPECIFIED
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"
/*************************************************************************
Declaration of functions
*************************************************************************/
#define PAL_AC_PowerAbstractionLayer_START_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"
extern void pal_Cfg_Init (void);
extern void pal_AT_Init  (void);
#define PAL_AC_PowerAbstractionLayer_STOP_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"

#endif /* PAL_V2_INC_PAL_CONFIG_H_ */

/*************************************************************************
Evolution of the component

Created by : cedric.sauvage

$Log: PAL_config.h  $
Revision 1.2.1.5 2022/08/09 17:21:08CEST Mirela Obada (mirela.obada) 
Add new limit for duty cycle
Revision 1.2.1.4 2022/02/15 12:33:58EET Septimiu Vintila (septimiu.vintila) 
Fixes after review.
Revision 1.2.1.3 2022/01/17 07:48:12EET Septimiu Vintila (septimiu.vintila) 
Autotests and interfaces for PAL, PMP added
Revision 1.2.1.2 2021/12/24 14:13:33EET Septimiu Vintila (septimiu.vintila) 
Initial revision
Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/PAL/Implementation/inc/project.pj
Revision 1.1.1.8 2019/08/14 12:21:58EEST Hamza Zetti (hamza.zetti) 
Correcting warnings
Revision 1.1.1.7 2019/08/13 16:38:10CEST Hamza Zetti (hamza.zetti) 
Correcting warnings
Revision 1.1.1.6 2018/11/08 18:48:15CET Pierre-Olivier Pilot (pierre-olivier.pilot) 
ACG 8.5.1 integration
Revision 1.1.1.5 2018/03/30 18:05:05EEST Lory Medas (lory.medas) 
Added conditions to enable or disable the boost function
Revision 1.1.1.4 2017/05/24 17:28:23CEST Cedric Sauvage (cedric.sauvage) 
Update PAL implementation for extended 
In particular : Auto tests
Revision 1.1.1.3 2017/03/03 16:21:48CET Audrey Vache (audrey.vache) 
PAL update for standardization of component between mainstream and extended
Revision 1.1.1.2 2017/02/24 09:50:16CET Michael Pastor (michael.pastor) 
MAJ PP4G R3.1E from Explo since 15/02/2017
Revision 1.1.1.1 2017/02/15 17:20:00CET Michael Pastor (michael.pastor) 
Check In modified already present files
Revision 1.1 2016/10/05 18:27:18CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Extended/PP4G_R31E/Components/Application/PAL/Implementation/inc/project.pj
Revision 1.1 2016/10/05 18:27:18CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/PP4G_Extended/Components/Application/PAL/Implementation/inc/project.pj
Revision 1.1 2016/10/05 10:13:17CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Components/Application/PAL/Implementation/inc/project.pj
Revision 1.1 2016/09/20 09:48:08CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Automation/PropagationProject_R3.0M/PP4G/Platform_Mainstream_Phase_01/Core/Components/Application/PAL/Implementation/inc/inc.pj
Revision 1.4 2016/08/31 16:14:19CEST Audrey Vache (audrey.vache) 
issue 417595 - VBoost design update
Revision 1.3 2016/06/07 12:52:15CEST Audrey Vache (audrey.vache) 
Memory mapping implementation
Revision 1.2 2016/05/23 18:10:22CEST Maxime Bourdon (mbourdon) 
PAL migration completion
Revision 1.1 2015/10/13 15:52:59CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/_PAL/inc/project.pj
Revision 1.7 2015/10/09 17:04:41CEST Pierre-Olivier Pilot (ppilot) 
Enhance SW selfprotection mechanism:
- Now, if one of the two mosfet is in HW selfprotection, the current returned by the PAL is 0.
-If the computed SW protection current is over the NVP threshold, the value is saturated to this threshold.
-SW self protection AEC state is now recorded in the system context field: DeficiencyLevel (The most significant byte is used to store the value. 0xAA means AEC qualified and 0x00 Deskill)
Revision 1.6 2015/08/25 10:21:17CEST Cedric Sauvage (csauvage) 
Code clean up after internal review during design document creation
Revision 1.5 2015/06/22 16:14:40CEST Sabine Flechelle (sflechelle) 
Issue 196836 - Complete HSW auto test
To follow TF-H97
Create NVP _ u16HSSWRegTestInitThreshold
Add Free wheeling phase if cycle was aborted
Integration test OK: SW_IT_ATM_094
Revision 1.3 2015/04/24 09:15:22CEST Cedric Sauvage (csauvage) 
Code improvement
Revision 1.2 2015/04/23 10:31:36CEST Cedric Sauvage (csauvage) 
Code template update
Revision 1.1 2015/04/23 08:39:59CEST Cedric Sauvage (csauvage)
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/_PAL/src/src.pj

*************************************************************************/

/* end of file */
