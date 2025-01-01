
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
$Revision: 1.11 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/MMG/Quality_Assurance/Static_Analysis/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup TEMPLATE_FILES_Group_Example Group_Example_Name_In_Document
 *  This is a new created group, this will create a new man3 file with 
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file. 
 */
 
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_MMG_AC_ModeManagement.h"
#include "common.h"
#include "MMG_Private.h"
#include "Nvp_Generated.h"
#include "Nvp_Cfg.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 * 		Presafe trigger off
 */
#define MMG_KU8_PRESF_TRIGGER_OFF                 ((uint8)85)
/**
 * \brief
 * 		Presafe trigger on
 */
#define MMG_KU8_PRESF_TRIGGER_ON                  ((uint8)170)

/**
 * \brief
 * 		State DTC not set
 */
#define MMG_KU8_State_DTC_Is_Not_Set              (0u)
/**
 * \brief
 * 		State DTC set
 */
#define MMG_KU8_State_DTC_Is_Set                  (1u)

/**
 * \brief
 * 		Tensioning is succesfull
 */
#define MMG_KU8_Tensioning_Successfull            (0u)
/**
 * \brief
 * 		Tensioning is not started
 */
#define MMG_KU8_Tensioning_NotStarted             (1u)
/**
 * \brief
 * 		Tensioning is aborted
 */
#define MMG_KU8_Tensioning_Abort                  (2u)
/**
 * \brief
 * 		Tensioning is not defined
 */
#define MMG_KU8_Tensioning_NotDefined             (3u)

/**
 * \brief
 * 		Shift belt handover
 */
#define MMG_KU8_SHIFT_BELT_HAND_OVER              (2u)
/**
 * \brief
 * 		Shift impactx
 */
#define MMG_KU8_SHIFT_IMPACTX                     (4u)
/**
 * \brief
 * 		Shift rollover type1
 */
#define MMG_KU8_SHIFT_ROLLOVERTYPE1               (6u)
/**
 * \brief
 * 		Shift rollover type2
 */
#define MMG_KU8_SHIFT_ROLLOVERTYPE2               (7u)

/**
 * \brief
 * 		Shift presafe disabled
 */
#define MMG_KU8_SHIFT_PRESAFE_DISABLED            (2u)
/**
 * \brief
 * 		Shift presafe suppresion
 */
#define MMG_KU8_SHIFT_PRESAFE_SUPP                (3u)
/**
 * \brief
 * 		Shift presafe aborted
 */
#define MMG_KU8_SHIFT_PRESAFE_ABORT               (4u)
/**
 * \brief
 * 		Shift KL15 OFF
 */
#define MMG_KU8_SHIFT_KL15OFF                     (5u)
/**
 * \brief
 * 		Shift overvoltage or undervoltage
 */
#define MMG_KU8_SHIFT_OV_OR_UV                    (6u)

/**
 * \brief
 * 		Shift presafe counter
 */
#define MMG_KU8_SHIFT_PRESAFE_COUNTER             (1u)
/**
 * \brief
 * 		Shift system failure
 */
#define MMG_KU8_SHIFT_SYSTEM_FAILURE              (2u)

/**
 * \brief
 * 		Voltage divider
 */
#define MMG_KU8_VOLTAGE_DIV                       (100u)
/**
 * \brief
 * 		Voltage max value
 */
#define MMG_KU16_VOLTAGE_MAX_VAL                  (254u)
/**
 * \brief
 * 		Seconds to miliseconds
 */
#define MMG_KU16_SEC_TO_MILI                      (1000u)

/**
 * \brief
 * 		Deficiency level low threshold
 */
#define MMG_KU32_DEF_LVL_LOW_THRS                 (uint32)(1200u)
/**
 * \brief
 * 		Deficiency level mid threshold
 */
#define MMG_KU32_DEF_LVL_MID_THRS                 (uint32)(32000u)
/**
 * \brief
 * 		Deficiency level high threshold
 */
#define MMG_KU32_DEF_LVL_HIGH_THRS                (uint32)(150000u)
/**
 * \brief
 * 		Deficiency level hot threshold
 */
#define MMG_KU32_DEF_LVL_HOT_THRS                 (uint32)(160000u)

/**
 *
 * \brief
 * 		ECU Location left
 */
#define KU8_MMG_ECU_SIDE_FRONT_LEFT                   ((uint8) 0x9C)
/**
 * \brief
 * 		ECU Location right
 */
#define KU8_MMG_ECU_SIDE_FRONT_RIGHT                  ((uint8) 0x99)
/**
 * \brief
 *       NVP ECU Location
 */
#define KU8_MMG_ECU_LOCATION                          (NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation)
/**
 *
 * \brief
 * 		PreSafe recorder 1 ID
 */
#define KU8_MMG_PRESAFE_RECORDER_1_ID ((uint8)0x01)
/**
 *
 * \brief
 * 		PreSafe recorder 2 ID
 */
#define KU8_MMG_PRESAFE_RECORDER_2_ID ((uint8)0x02)
/**
 * \brief
 * 		Macro used for checking if Profile is enable in vehicle equipment
 */
#define KU32_MMG_VEH_EQP_CYCLE_ENABLE(bitPosition) (uint32)((KU8_ONE) << ((bitPosition)-KU8_ONE))
/**
 * \brief
 * 		General group mask for AECs that inhibate Presafe cycles
 */
#define KU32_MMG_AEC_GROUP_MASK                   (KU32_AEC_GROUP_MASK_TIMEOUT_PRESAFE | KU32_AEC_GROUP_MASK_TIMEOUT_BUCKLE | KU32_AEC_GROUP_MASK_TIMEOUT_IGNITION |KU32_AEC_GROUP_MASK_TIMEOUT_POWERTRAIN | KU32_AEC_GROUP_MASK_TIMEOUT_BH_L | KU32_AEC_GROUP_MASK_TIMEOUT_BH_R | KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_POWERTRAIN | KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_BUCKLE_ORC | KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_IGNITION | KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_PRESAFE)
/******************************************************************************
MODULE TYPES
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define MMG_AC_ModeManagement_START_SEC_VAR_8
#include "MMG_AC_ModeManagement_MemMap.h"

/**
 * \brief
 *		Structure to define the Pre-Safe Recorder Start Data 
 * \remarks
 *		None.
 */
typedef struct
{
   /* START 1 */
   /* To store the Start1 Buckle Switch*/
   uint8 Start1BuckleSwitch : 2;
   /* To store the Start1 Belt Hand Over*/
   uint8 Start1BeltHandOver : 2;

   /* START 2*/
   uint8 Start2PreSafeLvl    : 4;       /* To store the Start2 PreSafe Lvl*/
   uint8 Start2ImpactX       : 1;       /* To store the Start2 ImpactX*/
   uint8 Start2RollOverType1 : 1;       /* To store the Start2 RollOverType1*/
   uint8 Start2RollOverType2 : 1;       /* To store the Start2 RollOverType2*/
   /* START Voltage */
   uint8 StartVoltage        : 8;       /* To store the Start Voltage*/
   /* START Temperature */
   uint8 StartTemperature1   : 8;       /* To store the Start Temperature1*/
   uint8 StartTemperature2   : 8;       /* To store the Start Temperature2*/
   /* START System Time */
   uint8 StartSystemTime1   : 8;        /* To store the Start SystemTime1*/
   uint8 StartSystemTime2   : 8;        /* To store the Start SystemTime2*/
   uint8 StartSystemTime3   : 8;        /* To store the Start SystemTime3*/
   uint8 StartSystemTime4   : 8;        /* To store the Start SystemTime4*/
   uint8 StartSystemTime5   : 8;        /* To store the Start SystemTime5*/      
} mmg_stPreSafeRecorderStartData;   

/**
 * \brief
 *		Structure to define the Pre-Safe Recorder Stop Data 
 * \remarks
 *		None.
 */
typedef struct
{
   /* STOP 1*/
   uint8 Stop1BuckleSwitch  : 2;       /* To store the Stop1 Buckle Switch*/
   uint8 Stop1BeltHandOver  : 2;       /* To store the Stop1 Belt Hand Over*/
   /* STOP 2*/
   uint8 Stop2PreSafeLvl    : 4;       /* To store the Stop2 PreSafe Lvl*/
   uint8 Stop2ImpactX       : 1;       /* To store the Stop2 ImpactX*/
   uint8 Stop2RollOverType1 : 1;       /* To store the Stop2 RollOverType1*/
   uint8 Stop2RollOverType2 : 1;       /* To store the Stop1 RollOverType2*/
   /* STOP Voltage */
   uint8 StopVoltage        : 8;       /* To store the Stop Voltage*/
   /* STOP Temperature */
   uint8 StopTemperature1   : 8;       /* To store the Stop Temperature1*/
   uint8 StopTemperature2   : 8;       /* To store the Stop Temperature2*/
   /* STOP System Time */
   uint8 StopSystemTime1   : 8;        /* To store the Stop SystemTime1*/
   uint8 StopSystemTime2   : 8;        /* To store the Stop SystemTime2*/
   uint8 StopSystemTime3   : 8;        /* To store the Stop SystemTime3*/
   uint8 StopSystemTime4   : 8;        /* To store the Stop SystemTime4*/
   uint8 StopSystemTime5   : 8;        /* To store the Stop SystemTime5*/       
} mmg_stPreSafeRecorderStopData; 

/**
 * \brief
 *		Structure to define the Pre-Safe Recorder State Data 
 * \remarks
 *		None.
 */
typedef struct
{
   /* STATE 1*/
   uint8 State1TensioningState  : 2;       /* To store the State1 Tensioning State*/
   uint8 State1PreSafeDisabled  : 1;       /* To store the State1 PreSafe disabled*/
   uint8 State1PreSafeSupp      : 1;       /* To store the State1 PreSafe suppresion*/
   uint8 State1PreSafeAbort     : 1;       /* To store the State1 PreSafe abortion*/
   uint8 State1KL15             : 1;       /* To store the State1 KL15 */
   uint8 State1UvOROV           : 1;       /* To store the State1 Overvoltage or Undervoltafe*/
   /* STATE 2*/
   uint8 State2OverTemp         : 1;       /* To store the State2 Overtemperature*/
   uint8 State2PreSafeCounter   : 1;       /* To store the State2 EOL PreSafe Counter */
   uint8 State2SystemFailure    : 1;       /* To store the State2 System/Component failure */

       
} mmg_stPreSafeRecorderStateData; 

/**
 * \brief
 *		Structure to define the Pre-Safe Recorder State Data 
 * \remarks
 *		None.
 */
typedef struct
{
   uint8 StartedProfile;          /* To store the started profile */
   uint8 ProfileInterrupedStatus; /* To store the status of a new profile interrupted */
   uint8 NewProfileExecuted;      /* To store the new profile interrupted */
   uint8 OldReqestedProfileLvl;   /* To store the requested profile */
   uint8 PreSafeState;            /* To store the PreSafe state */
   uint8 PreSafePreviousState;    /* To store the PreSafe previous state */
   uint8 PreSafeWriteTrigger;     /* To store the PreSafe write trigger */
   uint8 PreSafeBufferID;         /* To store the PreSafe ID to be written */
} mmg_stPreSafeRecorderManagement;

/**
 * \brief
 *		Defined macro from C file.
 */
#define MMG_AC_ModeManagement_STOP_SEC_VAR_8
#include "MMG_AC_ModeManagement_MemMap.h"
/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
/**
* \brief
*    This variable is used for holding Presafe management data
* \remarks
*    None.
*/
static mmg_stPreSafeRecorderManagement mmg_stPreSafeManagement;
/**
* \brief
*    This variable is used for holding Presafe recorder start data
* \remarks
*    None.
*/
/* [COVERS: DSG_MMG_0062, DSG_MMG_0087] */
static mmg_stPreSafeRecorderStartData mmg_stPreSafeStartData;
/* [COVERS: DSG_MMG_0063, DSG_MMG_0087] */
/**
* \brief
*    This variable is used for holding Presafe recorder stop data
* \remarks
*    None.
*/
static mmg_stPreSafeRecorderStopData mmg_stPreSafeStopData;
/**
* \brief
*    This variable is used for holding Presafe recorder state data
* \remarks
*    None.
*/
/* [COVERS: DSG_MMG_0064, DSG_MMG_0087] */
static mmg_stPreSafeRecorderStateData mmg_stPreSafeStateData;
/**
* \brief
*    This variable is used for holding Presafe input data
* \remarks
*    None.
*/
/* [COVERS: DSG_MMG_0057] */
static REC_PreSafeRecInputType mmm_stPreSafeInputData = {KU8_TENSIONING_NONE, I_C02_BCKL_SW_STAT_SNA, I_C04_PRESF_LVL_V2_NOLVL, KU8_ZERO, I_C03_NO_LT_RT_BOTH_NO, KU8_ZERO, KU8_ZERO, I_C03_ISW_STAT_IGN_LOCK, I_C02_BELTHDOVR_STAT_SNA};
/**
* \brief
*    This variable is used for holding deficiency level
* \remarks
*    None.
*/
/* [COVERS: DSG_MMG_0058] */
static u32DeficiencyLevelType mmg_u32DeficiencyLevel = KU32_ZERO;
/**
* \brief
*    This variable is used for holding battery voltage level
* \remarks
*    None.
*/
/* [COVERS: DSG_MMG_0059] */
static u16VoltageType mmg_u16LocalVoltage = KU16_ZERO;
/**
* \brief
*    This variable is used for global time
* \remarks
*    None.
*/
static StbM_TimeStampType mmg_TimeStamp = {KU8_ZERO, KU32_ZERO, KU32_ZERO, KU16_ZERO};
/**
* \brief
*    This variable is used for current time
* \remarks
*    None.
*/
/* [COVERS: DSG_MMG_0060] */
static StbM_UserDataType mmg_TimeUserData = {KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO};
/**
* \brief
*    This variable is used for return value for current time
* \remarks
*    None.
*/
static Std_ReturnType mmg_u8Return = E_NOT_OK;

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
 *      Function is in charge of copying start data to RAM structure
 * \param
 * 		u8PreSafeRecorderID - Recorder ID to be written
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
LOCAL void mmg_PreSafe_CopyStartData(uint8 u8PreSafeRecorderID)
{
   uint8 u8PreSafeRecStart1 = KU8_ZERO;
   uint8 u8PreSafeRecStart2 = KU8_ZERO;

   u8PreSafeRecStart1 = (uint8)(mmg_stPreSafeStartData.Start1BuckleSwitch + (uint8)(mmg_stPreSafeStartData.Start1BeltHandOver << MMG_KU8_SHIFT_BELT_HAND_OVER));
   u8PreSafeRecStart2 = (uint8)(mmg_stPreSafeStartData.Start2PreSafeLvl + (uint8)(mmg_stPreSafeStartData.Start2ImpactX << MMG_KU8_SHIFT_IMPACTX) +
                                (uint8)(mmg_stPreSafeStartData.Start2RollOverType1 << MMG_KU8_SHIFT_ROLLOVERTYPE1) + (uint8)(mmg_stPreSafeStartData.Start2RollOverType2 << MMG_KU8_SHIFT_ROLLOVERTYPE2));

   switch (u8PreSafeRecorderID)
   {
   case KU8_MMG_PRESAFE_RECORDER_1_ID:
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderStart[KU8_ZERO] = u8PreSafeRecStart1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderStart[KU8_ONE] = u8PreSafeRecStart2;

      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8LocalVoltageStart[KU8_ZERO] = mmg_stPreSafeStartData.StartVoltage;

      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8EcuTemperatureStart[KU8_ZERO] = mmg_stPreSafeStartData.StartTemperature1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8EcuTemperatureStart[KU8_ONE] = mmg_stPreSafeStartData.StartTemperature2;

      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStart[KU8_ZERO] = mmg_stPreSafeStartData.StartSystemTime1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStart[KU8_ONE] = mmg_stPreSafeStartData.StartSystemTime2;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStart[KU8_TWO] = mmg_stPreSafeStartData.StartSystemTime3;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStart[KU8_THREE] = mmg_stPreSafeStartData.StartSystemTime4;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStart[KU8_FOUR] = mmg_stPreSafeStartData.StartSystemTime5;
      break;

   case KU8_MMG_PRESAFE_RECORDER_2_ID:
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderStart[KU8_ZERO] = u8PreSafeRecStart1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderStart[KU8_ONE] = u8PreSafeRecStart2;

      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8LocalVoltageStart[KU8_ZERO] = mmg_stPreSafeStartData.StartVoltage;

      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8EcuTemperatureStart[KU8_ZERO] = mmg_stPreSafeStartData.StartTemperature1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8EcuTemperatureStart[KU8_ONE] = mmg_stPreSafeStartData.StartTemperature2;

      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStart[KU8_ZERO] = mmg_stPreSafeStartData.StartSystemTime1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStart[KU8_ONE] = mmg_stPreSafeStartData.StartSystemTime2;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStart[KU8_TWO] = mmg_stPreSafeStartData.StartSystemTime3;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStart[KU8_THREE] = mmg_stPreSafeStartData.StartSystemTime4;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStart[KU8_FOUR] = mmg_stPreSafeStartData.StartSystemTime5;

      break;
   default:
      break;
   }
}

/**
 * \brief
 *      Function is in charge of copying stop data to RAM structure
 * \param
 * 		u8PreSafeRecorderID - Recorder ID to be written
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
LOCAL void mmg_PreSafe_CopyStopData(uint8 u8PreSafeRecorderID)
{
   uint8 u8PreSafeRecStop1 = KU8_ZERO;
   uint8 u8PreSafeRecStop2 = KU8_ZERO;

   u8PreSafeRecStop1 = (uint8)(mmg_stPreSafeStopData.Stop1BuckleSwitch + (uint8)(mmg_stPreSafeStopData.Stop1BeltHandOver << MMG_KU8_SHIFT_BELT_HAND_OVER));
   u8PreSafeRecStop2 = (uint8)(mmg_stPreSafeStopData.Stop2PreSafeLvl + (uint8)(mmg_stPreSafeStopData.Stop2ImpactX << MMG_KU8_SHIFT_IMPACTX) +
                               (uint8)(mmg_stPreSafeStopData.Stop2RollOverType1 << MMG_KU8_SHIFT_ROLLOVERTYPE1) + (uint8)(mmg_stPreSafeStopData.Stop2RollOverType2 << MMG_KU8_SHIFT_ROLLOVERTYPE2));

   switch (u8PreSafeRecorderID)
   {
   case KU8_MMG_PRESAFE_RECORDER_1_ID:
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderStop[KU8_ZERO] = u8PreSafeRecStop1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderStop[KU8_ONE] = u8PreSafeRecStop2;

      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8LocalVoltageStop[KU8_ZERO] = mmg_stPreSafeStopData.StopVoltage;

      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8EcuTemperatureStop[KU8_ZERO] = mmg_stPreSafeStopData.StopTemperature1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8EcuTemperatureStop[KU8_ONE] = mmg_stPreSafeStopData.StopTemperature2;

      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStop[KU8_ZERO] = mmg_stPreSafeStopData.StopSystemTime1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStop[KU8_ONE] = mmg_stPreSafeStopData.StopSystemTime2;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStop[KU8_TWO] = mmg_stPreSafeStopData.StopSystemTime3;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStop[KU8_THREE] = mmg_stPreSafeStopData.StopSystemTime4;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStop[KU8_FOUR] = mmg_stPreSafeStopData.StopSystemTime5;
      break;
   case KU8_MMG_PRESAFE_RECORDER_2_ID:
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderStop[KU8_ZERO] = u8PreSafeRecStop1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderStop[KU8_ONE] = u8PreSafeRecStop2;

      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8LocalVoltageStop[KU8_ZERO] = mmg_stPreSafeStopData.StopVoltage;

      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8EcuTemperatureStop[KU8_ZERO] = mmg_stPreSafeStopData.StopTemperature1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8EcuTemperatureStop[KU8_ONE] = mmg_stPreSafeStopData.StopTemperature2;

      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStop[KU8_ZERO] = mmg_stPreSafeStopData.StopSystemTime1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStop[KU8_ONE] = mmg_stPreSafeStopData.StopSystemTime2;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStop[KU8_TWO] = mmg_stPreSafeStopData.StopSystemTime3;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStop[KU8_THREE] = mmg_stPreSafeStopData.StopSystemTime4;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStop[KU8_FOUR] = mmg_stPreSafeStopData.StopSystemTime5;
      break;
   default:
      break;
   }
}

/**
 * \brief
 *      Function is in charge of copying stop data to RAM structure
 * \param
 * 		u8PreSafeRecorderID - Recorder ID to be written
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
LOCAL void mmg_PreSafe_CopyStateData(uint8 u8PreSafeRecorderID)
{
   uint8 u8PreSafeState1 = KU8_ZERO;
   uint8 u8PreSafeState2 = KU8_ZERO;

   u8PreSafeState1 = (uint8)(mmg_stPreSafeStateData.State1TensioningState + (uint8)(mmg_stPreSafeStateData.State1PreSafeDisabled << MMG_KU8_SHIFT_PRESAFE_DISABLED) +
                             (uint8)(mmg_stPreSafeStateData.State1PreSafeSupp << MMG_KU8_SHIFT_PRESAFE_SUPP) + (uint8)(mmg_stPreSafeStateData.State1PreSafeAbort << MMG_KU8_SHIFT_PRESAFE_ABORT) +
                             (uint8)(mmg_stPreSafeStateData.State1KL15 << MMG_KU8_SHIFT_KL15OFF) + (uint8)(mmg_stPreSafeStateData.State1UvOROV << MMG_KU8_SHIFT_OV_OR_UV));

   u8PreSafeState2 = (uint8)(mmg_stPreSafeStateData.State2OverTemp + (uint8)(mmg_stPreSafeStateData.State2PreSafeCounter << MMG_KU8_SHIFT_PRESAFE_COUNTER) +
                             (uint8)(mmg_stPreSafeStateData.State2SystemFailure << MMG_KU8_SHIFT_SYSTEM_FAILURE));

   switch (u8PreSafeRecorderID)
   {
   case KU8_MMG_PRESAFE_RECORDER_1_ID:
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderState[KU8_ZERO] = u8PreSafeState1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderState[KU8_ONE] = u8PreSafeState2;
      break;
   case KU8_MMG_PRESAFE_RECORDER_2_ID:
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderState[KU8_ZERO] = u8PreSafeState1;
      NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderState[KU8_ONE] = u8PreSafeState2;
      break;
   default:
      break;
   }
}

/**
 * \brief
 *      Function is in charge of checking EOL counter inhibition status
 * \param
 * 	 None
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 	 None
 */
/* [COVERS: DSG_MMG_0061] */
LOCAL void mmg_PreSafe_CheckEOLLimit(void)
{
   uint8 u8AutotestResult;

   if ((I_C04_PRESF_LVL_V2_LVL1 == mmm_stPreSafeInputData.u8PresafeLevelType) || (I_C04_PRESF_LVL_V2_LVL3 == mmm_stPreSafeInputData.u8PresafeLevelType))
   {
      Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_END_OF_LIFE_LOW_FORCE, &u8AutotestResult);
      if (KU8_ATM_TEST_NOK == u8AutotestResult)
      {
         /* [COVERS: DSG_MMG_0110] */
         mmg_stPreSafeStateData.State2PreSafeCounter = MMG_KU8_State_DTC_Is_Set;
      }
   }
   else if ((I_C04_PRESF_LVL_V2_LVL6 >= mmm_stPreSafeInputData.u8PresafeLevelType) && (I_C04_PRESF_LVL_V2_LVL4 <= mmm_stPreSafeInputData.u8PresafeLevelType))
   {
      Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_END_OF_LIFE_HIGH_FORCE, &u8AutotestResult);
      if (u8AutotestResult == KU8_ATM_TEST_NOK)
      {
         /* [COVERS: DSG_MMG_0110] */
         mmg_stPreSafeStateData.State2PreSafeCounter = MMG_KU8_State_DTC_Is_Set;
      }
   }
   else if ((I_C04_PRESF_LVL_V2_LVL7 == mmm_stPreSafeInputData.u8PresafeLevelType) || (I_C04_PRESF_LVL_V2_LVL8 == mmm_stPreSafeInputData.u8PresafeLevelType))
   {
      Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_END_OF_LIFE_MAX_FORCE, &u8AutotestResult);
      if (KU8_ATM_TEST_NOK == u8AutotestResult)
      {
         /* [COVERS: DSG_MMG_0110] */
         mmg_stPreSafeStateData.State2PreSafeCounter = MMG_KU8_State_DTC_Is_Set;
      }
   }
   else
   {
      /* SNA */
   }
}

/**
 * \brief
 *      Function is in charge handling the errors read from ERH
 * \param
 * 		u8PreSafeRecorderID - Recorder ID to be written
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
LOCAL void mmg_PreSafe_HandleStateData(uint8 u8PreSafeRecorderID)
{
   uint32 u32AECGroupStatus;

   /* Get AEC Group status from ERH */
   /* [COVERS: DSG_MMG_0053, DSG_MMG_0054, DSG_MMG_0055, DSG_MMG_0056] */
   Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);

   /* State1 bit0-1 - Tensioning state*/
   switch (mmm_stPreSafeInputData.u8TensioningStateType)
   {
   case KU8_TENSIONING_START:
      /* [COVERS: DSG_MMG_0088] */
      mmg_stPreSafeStateData.State1TensioningState = MMG_KU8_Tensioning_Successfull;
      break;
   case KU8_TENSIONING_END:
      /* [COVERS: DSG_MMG_0089] */
      mmg_stPreSafeStateData.State1TensioningState = MMG_KU8_Tensioning_Successfull;
      break;
   case KU8_TENSIONING_INHIBIT:
      /* [COVERS: DSG_MMG_0090] */
      mmg_stPreSafeStateData.State1TensioningState = MMG_KU8_Tensioning_NotStarted;
      break;
   case KU8_TENSIONING_ABORT:
      /* [COVERS: DSG_MMG_0091] */
      mmg_stPreSafeStateData.State1TensioningState = MMG_KU8_Tensioning_Abort;
      break;
   default:
      break;
   }

   /* State1 bit2 - PreSafe cycle disable */
   if (KU8_ONE == NVP_stVehicleEquipmentData.PreSafeFuncActivation)
   {
      /* [COVERS: DSG_MMG_0092] */
      mmg_stPreSafeStateData.State1PreSafeDisabled = MMG_KU8_State_DTC_Is_Set;
   }
   else
   {
      if (KU32_ZERO != (NVP_stVehicleEquipmentData.PreSafeCycleActivation & KU32_MMG_VEH_EQP_CYCLE_ENABLE(mmm_stPreSafeInputData.u8PresafeLevelType)))
      {
         /* [COVERS: DSG_MMG_0092] */
         mmg_stPreSafeStateData.State1PreSafeDisabled = MMG_KU8_State_DTC_Is_Set;
      }
      else
      {
         /* [COVERS: DSG_MMG_0093] */
         mmg_stPreSafeStateData.State1PreSafeDisabled = MMG_KU8_State_DTC_Is_Not_Set;
      }
   }

   /* State1 bit3 - Suppresion of PreSafe cycle*/
   switch (mmm_stPreSafeInputData.u8TensSuppType)
   {
   case I_C03_NO_LT_RT_BOTH_NO:
      /* [COVERS: DSG_MMG_0094] */
      mmg_stPreSafeStateData.State1PreSafeSupp = MMG_KU8_State_DTC_Is_Not_Set;
      break;
   case I_C03_NO_LT_RT_BOTH_LEFT:
      if (KU8_MMG_ECU_LOCATION == KU8_MMG_ECU_SIDE_FRONT_LEFT)
      {
         /* [COVERS: DSG_MMG_0095] */
         mmg_stPreSafeStateData.State1PreSafeSupp = MMG_KU8_State_DTC_Is_Set;
      }
      else
      {
         /* [COVERS: DSG_MMG_0096] */
         mmg_stPreSafeStateData.State1PreSafeSupp = MMG_KU8_State_DTC_Is_Not_Set;
      }
      break;
   case I_C03_NO_LT_RT_BOTH_RIGHT:
      if (KU8_MMG_ECU_LOCATION == KU8_MMG_ECU_SIDE_FRONT_RIGHT)
      {
         /* [COVERS: DSG_MMG_0097] */
         mmg_stPreSafeStateData.State1PreSafeSupp = MMG_KU8_State_DTC_Is_Set;
      }
      else
      {
         /* [COVERS: DSG_MMG_0098] */
         mmg_stPreSafeStateData.State1PreSafeSupp = MMG_KU8_State_DTC_Is_Not_Set;
      }
      break;
   case I_C03_NO_LT_RT_BOTH_BOTH:
      /* [COVERS: DSG_MMG_0099] */
      mmg_stPreSafeStateData.State1PreSafeSupp = MMG_KU8_State_DTC_Is_Set;
      break;
   default:
      mmg_stPreSafeStateData.State1PreSafeSupp = MMG_KU8_State_DTC_Is_Not_Set;
      break;
   }

   /* State1 bit4 - Abortion of a PreSafe cycle */
   if ( (KU32_ZERO != (u32AECGroupStatus &  KU32_MMG_AEC_GROUP_MASK)) )
   {
      /* [COVERS: DSG_MMG_0100] */
      mmg_stPreSafeStateData.State1PreSafeAbort = MMG_KU8_State_DTC_Is_Set;
   }
   else
   {
      /* [COVERS: DSG_MMG_0101] */
      mmg_stPreSafeStateData.State1PreSafeAbort = MMG_KU8_State_DTC_Is_Not_Set;
   }

   /* State1 bit5 - KL15 */
   if (I_C03_ISW_STAT_IGN_ON != mmm_stPreSafeInputData.u8IgnStat)
   {
      /* [COVERS: DSG_MMG_0102] */
      mmg_stPreSafeStateData.State1KL15 = MMG_KU8_State_DTC_Is_Set;
   }
   else
   {
      /* [COVERS: DSG_MMG_0103] */
      mmg_stPreSafeStateData.State1KL15 = MMG_KU8_State_DTC_Is_Not_Set;
   }

   /* State1 bit6 - Under or Over voltage*/
   if ((KB_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_UNDER_VO)) ||
       (KB_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_OVER_VO)))
   {
      /* [COVERS: DSG_MMG_0104] */
      mmg_stPreSafeStateData.State1UvOROV = MMG_KU8_State_DTC_Is_Set;
   }
   else
   {
      /* [COVERS: DSG_MMG_0105] */
      mmg_stPreSafeStateData.State1UvOROV = MMG_KU8_State_DTC_Is_Not_Set;
   }

   /* State2 bit0 - Overtemperature*/
   if (KB_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_SELF_PROTECTION))
   {
      /* [COVERS: DSG_MMG_0106] */
      mmg_stPreSafeStateData.State2OverTemp = MMG_KU8_State_DTC_Is_Set;
   }
   else
   {
      /* [COVERS: DSG_MMG_0107] */
      mmg_stPreSafeStateData.State2OverTemp = MMG_KU8_State_DTC_Is_Not_Set;
   }

   /* State2 bit1 - PreSafe counter failure */
   mmg_PreSafe_CheckEOLLimit();

   /* State2 bit2 - System/Component failure*/
   if (KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_HARDWARE))
   {
      /* [COVERS: DSG_MMG_0108] */
      mmg_stPreSafeStateData.State2SystemFailure = MMG_KU8_State_DTC_Is_Set;
   }
   else
   {
      /* [COVERS: DSG_MMG_0109] */
      mmg_stPreSafeStateData.State2SystemFailure = MMG_KU8_State_DTC_Is_Not_Set;
   }

   mmg_PreSafe_CopyStateData(u8PreSafeRecorderID);
}

/**
 * \brief
 *      Function is in charge handling the errors read from ERH
 * \param
 * 		u8PreSafeRecorderID - Recorder ID to be written
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
LOCAL void mmg_PreSafe_HandleStartData(uint8 u8PreSafeRecorderID)
{
   uint8 u8StartTemperature = KU8_ZERO;
   uint16 u16StartVoltage = KU16_ZERO;

   /* Start1 bits 0-1 Buckle Switch State */
   /* [COVERS: DSG_MMG_0068] */
   mmg_stPreSafeStartData.Start1BuckleSwitch = mmm_stPreSafeInputData.u8BuckleStateType;

   /* Start1 bits 2-3 Belt Hand Over State */
   /* [COVERS: DSG_MMG_0069] */
   mmg_stPreSafeStartData.Start1BeltHandOver = mmm_stPreSafeInputData.u8BeltHdOvStat;

   /* Start2 bits 0-3 PreSafe Lvl */
   /* [COVERS: DSG_MMG_0070] */
   mmg_stPreSafeStartData.Start2PreSafeLvl = mmm_stPreSafeInputData.u8PresafeLevelType;

   /* Start2 bit 4 Impact X*/
   /* [COVERS: DSG_MMG_0071] */
   if (KU8_ONE == mmm_stPreSafeInputData.bImpactXType)
   {
      mmg_stPreSafeStartData.Start2ImpactX = KB_ONE;
   }
   else
   {
      mmg_stPreSafeStartData.Start2ImpactX = KB_ZERO;
   }

   /* Start2 bit 6 RollOver Event Type 1*/
   /* [COVERS: DSG_MMG_0072] */
   if (KU8_ONE == mmm_stPreSafeInputData.bRoEventType1)
   {
      mmg_stPreSafeStartData.Start2RollOverType1 = KB_ONE;
   }
   else
   {
      mmg_stPreSafeStartData.Start2RollOverType1 = KB_ZERO;
   }

   /* Start2 bit 7 RollOver Event Type 2*/
   /* [COVERS: DSG_MMG_0073] */
   if (KU8_ONE == mmm_stPreSafeInputData.bRoEventType2)
   {
      mmg_stPreSafeStartData.Start2RollOverType2 = KB_ONE;
   }
   else
   {
      mmg_stPreSafeStartData.Start2RollOverType2 = KB_ZERO;
   }

   u16StartVoltage = mmg_u16LocalVoltage / MMG_KU8_VOLTAGE_DIV;

   if (MMG_KU16_VOLTAGE_MAX_VAL < u16StartVoltage)
   {
      u16StartVoltage = MMG_KU16_VOLTAGE_MAX_VAL;
   }
   else
   {
      /* QAC */
   }

   /* Start Local Voltage */
   /* [COVERS: DSG_MMG_0074] */
   mmg_stPreSafeStartData.StartVoltage = (uint8)(u16StartVoltage);

   if (MMG_KU32_DEF_LVL_LOW_THRS > mmg_u32DeficiencyLevel)
   {
      /* [COVERS: DSG_MMG_0076] */
      u8StartTemperature = KU8_ZERO;
   }
   else if ((MMG_KU32_DEF_LVL_LOW_THRS <= mmg_u32DeficiencyLevel) && (MMG_KU32_DEF_LVL_MID_THRS > mmg_u32DeficiencyLevel))
   {
      /* [COVERS: DSG_MMG_0077] */
      u8StartTemperature = KU8_ONE;
   }
   else if ((MMG_KU32_DEF_LVL_MID_THRS <= mmg_u32DeficiencyLevel) && (MMG_KU32_DEF_LVL_HIGH_THRS > mmg_u32DeficiencyLevel))
   {
      /* [COVERS: DSG_MMG_0078] */
      u8StartTemperature = KU8_TWO;
   }
   else if ((MMG_KU32_DEF_LVL_HIGH_THRS <= mmg_u32DeficiencyLevel) && (MMG_KU32_DEF_LVL_HOT_THRS > mmg_u32DeficiencyLevel))
   {
      /* [COVERS: DSG_MMG_0079] */
      u8StartTemperature = KU8_THREE;
   }
   else if (MMG_KU32_DEF_LVL_HOT_THRS <= mmg_u32DeficiencyLevel)
   {
      /* [COVERS: DSG_MMG_0080] */
      u8StartTemperature = KU8_FOUR;
   }
   else
   {
      /* [COVERS: DSG_MMG_0081] */
      u8StartTemperature = KU8_MAX;
   }

   /* Start Temperature */
   mmg_stPreSafeStartData.StartTemperature1 = u8StartTemperature;
   /* [COVERS: DSG_MMG_0075] */
   mmg_stPreSafeStartData.StartTemperature2 = KU8_ZERO;

   /* Start System time */
   if (E_NOT_OK != mmg_u8Return)
   {
      /* [COVERS: DSG_MMG_0086] */
      mmg_stPreSafeStartData.StartSystemTime5 = KU8_ZERO;
      /* [COVERS: DSG_MMG_0085] */
      mmg_stPreSafeStartData.StartSystemTime4 = (uint8)mmg_TimeStamp.seconds;
      /* [COVERS: DSG_MMG_0084] */
      mmg_stPreSafeStartData.StartSystemTime3 = (uint8)(mmg_TimeStamp.seconds >> KU8_EIGHT);
      /* [COVERS: DSG_MMG_0083] */
      mmg_stPreSafeStartData.StartSystemTime2 = (uint8)(mmg_TimeStamp.seconds >> KU8_SIXTEEN);
      /* [COVERS: DSG_MMG_0082] */
      mmg_stPreSafeStartData.StartSystemTime1 = (uint8)(mmg_TimeStamp.seconds >> KU8_TWENTY_FOUR);
   }
   else
   {
      /* System time return NOK*/
   }

   mmg_PreSafe_CopyStartData(u8PreSafeRecorderID);

   mmg_PreSafe_HandleStateData(u8PreSafeRecorderID);
}

/**
 * \brief
 *      Function is in charge of handling stop data
 * \param
 * 		u8PreSafeRecorderID - Recorder ID to be written
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
LOCAL void mmg_PreSafe_HandleStopData(uint8 u8PreSafeRecorderID)
{
   uint8 u8StopTemperature = KU8_ZERO;
   uint16 u16StopVoltage = KU16_ZERO;

   /* Stop1 bits 0-1 Buckle Switch State */
   /* [COVERS: DSG_MMG_0068] */
   mmg_stPreSafeStopData.Stop1BuckleSwitch = mmm_stPreSafeInputData.u8BuckleStateType;

   /* Stop1 bits 2-3 Belt Hand Over State */
   /* [COVERS: DSG_MMG_0069] */
   mmg_stPreSafeStopData.Stop1BeltHandOver = mmm_stPreSafeInputData.u8BeltHdOvStat;

   /* Stop2 bits 0-3 PreSafe Lvl */
   /* [COVERS: DSG_MMG_0070] */
   if (KU8_TRUE == mmg_stPreSafeManagement.ProfileInterrupedStatus)
   {
      mmg_stPreSafeStopData.Stop2PreSafeLvl = mmg_stPreSafeManagement.NewProfileExecuted;
   }
   else
   {
      if (KU8_TENSIONING_END == mmg_stPreSafeManagement.PreSafeState)
      {
         mmg_stPreSafeStopData.Stop2PreSafeLvl = mmg_stPreSafeManagement.StartedProfile;
      }
      else
      {
         mmg_stPreSafeStopData.Stop2PreSafeLvl = mmm_stPreSafeInputData.u8PresafeLevelType;
      }
   }

   /* Stop2 bit 4 Impact X*/
   /* [COVERS: DSG_MMG_0071] */
   if (KU8_ONE == mmm_stPreSafeInputData.bImpactXType)
   {
      mmg_stPreSafeStopData.Stop2ImpactX = KB_ONE;
   }
   else
   {
      mmg_stPreSafeStopData.Stop2ImpactX = KB_ZERO;
   }

   /* Stop2 bit 6 RollOver Event Type 1*/
   /* [COVERS: DSG_MMG_0072] */
   if (KU8_ONE == mmm_stPreSafeInputData.bRoEventType1)
   {
      mmg_stPreSafeStopData.Stop2RollOverType1 = KB_ONE;
   }
   else
   {
      mmg_stPreSafeStopData.Stop2RollOverType1 = KB_ZERO;
   }

   /* Stop2 bit 7 RollOver Event Type 2*/
   /* [COVERS: DSG_MMG_0073] */
   if (KU8_ONE == mmm_stPreSafeInputData.bRoEventType2)
   {
      mmg_stPreSafeStopData.Stop2RollOverType2 = KB_ONE;
   }
   else
   {
      mmg_stPreSafeStopData.Stop2RollOverType2 = KB_ZERO;
   }

   u16StopVoltage = mmg_u16LocalVoltage / MMG_KU8_VOLTAGE_DIV;

   if (MMG_KU16_VOLTAGE_MAX_VAL < u16StopVoltage)
   {
      u16StopVoltage = MMG_KU16_VOLTAGE_MAX_VAL;
   }
   else
   {
      /* QAC */
   }

   /* Stop Local Voltage */
   /* [COVERS: DSG_MMG_0074] */
   mmg_stPreSafeStopData.StopVoltage = (uint8)(u16StopVoltage);

   if (mmg_u32DeficiencyLevel < MMG_KU32_DEF_LVL_LOW_THRS)
   {
      /* [COVERS: DSG_MMG_0076] */
      u8StopTemperature = KU8_ZERO;
   }
   else if ((MMG_KU32_DEF_LVL_LOW_THRS <= mmg_u32DeficiencyLevel) && (MMG_KU32_DEF_LVL_MID_THRS > mmg_u32DeficiencyLevel))
   {
      /* [COVERS: DSG_MMG_0077] */
      u8StopTemperature = KU8_ONE;
   }
   else if ((MMG_KU32_DEF_LVL_MID_THRS <= mmg_u32DeficiencyLevel) && (MMG_KU32_DEF_LVL_HIGH_THRS > mmg_u32DeficiencyLevel))
   {
      /* [COVERS: DSG_MMG_0078] */
      u8StopTemperature = KU8_TWO;
   }
   else if ((MMG_KU32_DEF_LVL_HIGH_THRS <= mmg_u32DeficiencyLevel) && (MMG_KU32_DEF_LVL_HOT_THRS > mmg_u32DeficiencyLevel))
   {
      /* [COVERS: DSG_MMG_0079] */
      u8StopTemperature = KU8_THREE;
   }
   else if (MMG_KU32_DEF_LVL_HOT_THRS <= mmg_u32DeficiencyLevel)
   {
      /* [COVERS: DSG_MMG_0080] */
      u8StopTemperature = KU8_FOUR;
   }
   else
   {
      /* [COVERS: DSG_MMG_0081] */
      u8StopTemperature = KU8_MAX;
   }

   /* Stop Temperature */
   mmg_stPreSafeStopData.StopTemperature1 = u8StopTemperature;
   /* [COVERS: DSG_MMG_0075] */
   mmg_stPreSafeStopData.StopTemperature2 = KU8_ZERO;

   /* Stop System time */
   if (mmg_u8Return != E_NOT_OK)
   {
      /* [COVERS: DSG_MMG_0086] */
      mmg_stPreSafeStopData.StopSystemTime5 = KU8_ZERO;
      /* [COVERS: DSG_MMG_0085] */
      mmg_stPreSafeStopData.StopSystemTime4 = (uint8)mmg_TimeStamp.seconds;
      /* [COVERS: DSG_MMG_0084] */
      mmg_stPreSafeStopData.StopSystemTime3 = (uint8)(mmg_TimeStamp.seconds >> KU8_EIGHT);
      /* [COVERS: DSG_MMG_0083] */
      mmg_stPreSafeStopData.StopSystemTime2 = (uint8)(mmg_TimeStamp.seconds >> KU8_SIXTEEN);
      /* [COVERS: DSG_MMG_0082] */
      mmg_stPreSafeStopData.StopSystemTime1 = (uint8)(mmg_TimeStamp.seconds >> KU8_TWENTY_FOUR);
   }
   else
   {
      /* System time return NOK*/
   }

   mmg_PreSafe_CopyStopData(u8PreSafeRecorderID);

   mmg_PreSafe_HandleStateData(u8PreSafeRecorderID);

   if(KU8_MMG_PRESAFE_RECORDER_1_ID == u8PreSafeRecorderID)
   {
      Rte_IrvWrite_MMG_runPreSafeRecorder_b8PreSafeRecorder1Update(KU8_TRUE);
      Rte_IrvWrite_MMG_runPreSafeRecorder_b8PreSafeRecorder2Update(KU8_FALSE);
   }
   else
   {
      Rte_IrvWrite_MMG_runPreSafeRecorder_b8PreSafeRecorder1Update(KU8_FALSE);
      Rte_IrvWrite_MMG_runPreSafeRecorder_b8PreSafeRecorder2Update(KU8_TRUE);
   }
   
}

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
 * \brief
 *      Function is in charge of copying start data to RAM structure
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
FUNC(void, MMG_AC_ModeManagement_CODE)
mmg_PreSafe_Init(void)
{
   /* Init Start Data */
   mmg_stPreSafeStartData.StartVoltage = KU8_ZERO;
   mmg_stPreSafeStartData.StartTemperature1 = KU8_ZERO;
   mmg_stPreSafeStartData.StartTemperature2 = KU8_ZERO;
   mmg_stPreSafeStartData.StartSystemTime1 = KU8_ZERO;
   mmg_stPreSafeStartData.StartSystemTime2 = KU8_ZERO;
   mmg_stPreSafeStartData.StartSystemTime3 = KU8_ZERO;
   mmg_stPreSafeStartData.StartSystemTime4 = KU8_ZERO;
   mmg_stPreSafeStartData.StartSystemTime5 = KU8_ZERO;

   /* Init Stop Data */
   mmg_stPreSafeStopData.StopVoltage = KU8_ZERO;
   mmg_stPreSafeStopData.StopTemperature1 = KU8_ZERO;
   mmg_stPreSafeStopData.StopTemperature2 = KU8_ZERO;
   mmg_stPreSafeStopData.StopSystemTime1 = KU8_ZERO;
   mmg_stPreSafeStopData.StopSystemTime2 = KU8_ZERO;
   mmg_stPreSafeStopData.StopSystemTime3 = KU8_ZERO;
   mmg_stPreSafeStopData.StopSystemTime4 = KU8_ZERO;
   mmg_stPreSafeStopData.StopSystemTime5 = KU8_ZERO;

   /* Init State Data */
   mmg_stPreSafeStateData.State1TensioningState = KU8_ZERO;
   mmg_stPreSafeStateData.State1PreSafeDisabled = KU8_ZERO;
   mmg_stPreSafeStateData.State1PreSafeAbort = KU8_ZERO;
   mmg_stPreSafeStateData.State1PreSafeSupp = KU8_ZERO;
   mmg_stPreSafeStateData.State1KL15 = KU8_ZERO;
   mmg_stPreSafeStateData.State1UvOROV = KU8_ZERO;
   mmg_stPreSafeStateData.State2OverTemp = KU8_ZERO;
   mmg_stPreSafeStateData.State2PreSafeCounter = KU8_ZERO;
   mmg_stPreSafeStateData.State2SystemFailure = KU8_ZERO;
}

/**
 * \brief
 *      Function is in charge handling the mode management of Presafe recorder
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
FUNC(void, MMG_AC_ModeManagement_CODE)
MMG_runPreSafeRecorder(void)
{
   boolean bRecorderEnd = B_FALSE;
   uint8 u8PreSafeRecorderNewID = KU8_ZERO;

   /* Rte call for CIL input signals data*/
   Rte_Call_pclPreSafeRecInput_GetInputSignals(&mmm_stPreSafeInputData);
   /* Rte call for ecu temperature */
   Rte_Call_pclMotor_T_GetDeficiencyLevel(&mmg_u32DeficiencyLevel);
   /* Rte call for local voltage */
   Rte_Call_pclKL30_Get(&mmg_u16LocalVoltage);
   /* Rte call for global time */
   mmg_u8Return = Rte_Call_GlobalTime_Slave_GTD_BODY3_0_14e64f11_GetCurrentTime(&mmg_TimeStamp, &mmg_TimeUserData);
   /* Read PreSafe recorder old ID*/
   /* [COVERS: DSG_MMG_0065] */
   mmg_stPreSafeManagement.PreSafeBufferID = NVP_BLOCK_ID_PRE_SAFE_RECORDER_ID_RamBlockData.NVP_u8PreSafeRecorderID;

   /* Update current PreSafe state*/
   mmg_stPreSafeManagement.PreSafeState = mmm_stPreSafeInputData.u8TensioningStateType;

   /* Check if Tensioning state is changed*/
   /* [COVERS: DSG_MMG_0066, DSG_MMG_0067] */
   if (mmg_stPreSafeManagement.PreSafeState != mmg_stPreSafeManagement.PreSafePreviousState)
   {
      if ( (I_C04_PRESF_LVL_V2_LVL2 != mmm_stPreSafeInputData.u8PresafeLevelType) || (I_C04_PRESF_LVL_V2_NOLVL != mmm_stPreSafeInputData.u8PresafeLevelType) )
      {
         /* Data needs to be written*/
         mmg_stPreSafeManagement.PreSafeWriteTrigger = MMG_KU8_PRESF_TRIGGER_ON;
      }
   }
   else
   {
      if ((KU8_TENSIONING_INHIBIT == mmg_stPreSafeManagement.PreSafeState) && (mmg_stPreSafeManagement.OldReqestedProfileLvl != mmm_stPreSafeInputData.u8PresafeLevelType))
      {
         if ((I_C04_PRESF_LVL_V2_LVL2 != mmm_stPreSafeInputData.u8PresafeLevelType) && (I_C04_PRESF_LVL_V2_NOLVL != mmm_stPreSafeInputData.u8PresafeLevelType))
         {
            /* Data needs to be written*/
            mmg_stPreSafeManagement.PreSafeWriteTrigger = MMG_KU8_PRESF_TRIGGER_ON;
         }
      }
      else
      {
         /* No data needs to be written*/
         mmg_stPreSafeManagement.PreSafeWriteTrigger = MMG_KU8_PRESF_TRIGGER_OFF;
      }
   }

   /* Check if a profile was started*/
   if (KU8_TENSIONING_START == mmg_stPreSafeManagement.PreSafeState)
   {
      if (KU8_TENSIONING_START != mmg_stPreSafeManagement.PreSafePreviousState)
      {
         mmg_stPreSafeManagement.StartedProfile = mmm_stPreSafeInputData.u8PresafeLevelType;
      }
   }

   /* Check if a profile is interrupted*/
   if (KU8_TENSIONING_START == mmg_stPreSafeManagement.PreSafeState)
   {
      if ((mmm_stPreSafeInputData.u8PresafeLevelType != KU8_ZERO) && (I_C04_PRESF_LVL_V2_LVL2 != mmm_stPreSafeInputData.u8PresafeLevelType))
      {
         if (mmg_stPreSafeStartData.Start2PreSafeLvl != mmm_stPreSafeInputData.u8PresafeLevelType)
         {
            mmg_stPreSafeManagement.ProfileInterrupedStatus = KU8_TRUE;
            mmg_stPreSafeManagement.NewProfileExecuted = mmm_stPreSafeInputData.u8PresafeLevelType;
         }
         else
         {
            mmg_stPreSafeManagement.ProfileInterrupedStatus = KU8_FALSE;
            mmg_stPreSafeManagement.NewProfileExecuted = KU8_NO_CYCLE;
         }
      }
   }

   /* If data needs to be written */
   if (MMG_KU8_PRESF_TRIGGER_OFF != mmg_stPreSafeManagement.PreSafeWriteTrigger)
   {
      if ((KU8_TENSIONING_END == mmg_stPreSafeManagement.PreSafeState) || (KU8_TENSIONING_ABORT == mmg_stPreSafeManagement.PreSafeState) || (KU8_TENSIONING_NONE == mmg_stPreSafeManagement.PreSafeState))
      {
         bRecorderEnd = B_TRUE;
      }

      /* Check if a block was written before */
      if ((KU8_MMG_PRESAFE_RECORDER_1_ID != mmg_stPreSafeManagement.PreSafeBufferID) &&
          (KU8_MMG_PRESAFE_RECORDER_2_ID != mmg_stPreSafeManagement.PreSafeBufferID))
      {
         u8PreSafeRecorderNewID = KU8_MMG_PRESAFE_RECORDER_1_ID;
      }
      else
      {
         /* Update the new Presafe recorder id to be written */
         if (KU8_MMG_PRESAFE_RECORDER_1_ID == mmg_stPreSafeManagement.PreSafeBufferID)
         {
            u8PreSafeRecorderNewID = KU8_MMG_PRESAFE_RECORDER_2_ID;
         }
         else
         {
            u8PreSafeRecorderNewID = KU8_MMG_PRESAFE_RECORDER_1_ID;
         }
      }

      switch (mmg_stPreSafeManagement.PreSafeState)
      {
      case KU8_TENSIONING_START:
         mmg_PreSafe_HandleStartData(u8PreSafeRecorderNewID);
         break;
      case KU8_TENSIONING_END:
         mmg_PreSafe_HandleStopData(mmg_stPreSafeManagement.PreSafeBufferID);

         mmg_stPreSafeManagement.ProfileInterrupedStatus = KU8_FALSE;
         mmg_stPreSafeManagement.NewProfileExecuted = KU8_NO_CYCLE;
         mmg_stPreSafeManagement.StartedProfile = KU8_NO_CYCLE;
         break;
      case KU8_TENSIONING_INHIBIT:
         mmg_PreSafe_HandleStartData(u8PreSafeRecorderNewID);
         mmg_PreSafe_HandleStopData(u8PreSafeRecorderNewID);
         break;
      case KU8_TENSIONING_ABORT:
         mmg_PreSafe_HandleStopData(mmg_stPreSafeManagement.PreSafeBufferID);
         break;
      case KU8_TENSIONING_NONE:
      default:
         break;
      }

      mmg_stPreSafeManagement.PreSafeWriteTrigger = MMG_KU8_PRESF_TRIGGER_OFF;

      /* Update the ID block only when starting a profile */
      if (B_TRUE != bRecorderEnd)
      {
         NVP_BLOCK_ID_PRE_SAFE_RECORDER_ID_RamBlockData.NVP_u8PreSafeRecorderID = u8PreSafeRecorderNewID;
      }
   }
   else
   {
      /*QAC*/
   }
   /* Update previous PreSafe state*/
   mmg_stPreSafeManagement.PreSafePreviousState = mmg_stPreSafeManagement.PreSafeState;
   mmg_stPreSafeManagement.OldReqestedProfileLvl = mmm_stPreSafeInputData.u8PresafeLevelType;
}

/******************************************************************************
End Of File
*****************************************************************************/
