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
$Revision: 1.1.5.17 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/MMG/Implementation/src/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup MMG_DowngradedModes.c MMG
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
 * 		Mask for AECs that set green status
 */
#define MMG_KU32_AEC_MASK_GREEN_STATUS (KU32_AEC_GROUP_MASK_OVER_VO | KU32_AEC_GROUP_MASK_UNDER_VO | KU32_AEC_GROUP_MASK_OVER_VO_TENS | KU32_AEC_GROUP_MASK_UNDER_VO_TENS | KU32_AEC_GROUP_MASK_NVM | KU32_AEC_GROUP_MASK_WARM_RESET | KU32_AEC_GROUP_MASK_EOL_COMFORT | KU32_AEC_GROUP_MASK_EOL_MAX | KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_POWERTRAIN | KU32_AEC_GROUP_MASK_TIMEOUT_IGNITION | KU32_AEC_GROUP_MASK_TIMEOUT_BH_R | KU32_AEC_GROUP_MASK_TIMEOUT_BH_L | KU32_AEC_GROUP_MASK_TIMEOUT_POWERTRAIN | KU32_AEC_GROUP_MASK_SYSTEM_OV | KU32_AEC_GROUP_MASK_SYSTEM_UV)
/**
 * \brief
 * 		Mask for AECs that set red status
 */
#define MMG_KU32_AEC_MASK_RED_STATUS         (KU32_AEC_GROUP_MASK_HARDWARE | KU32_AEC_GROUP_MASK_SELF_PROTECTION | KU32_AEC_GROUP_MASK_MOTOR | KU32_AEC_GROUP_MASK_EOL_LOW_HIGH | KU32_AEC_GROUP_MASK_STEERING_CONFIG | KU32_AEC_GROUP_MASK_TIMEOUT_PRESAFE | KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_PRESAFE | KU32_AEC_GROUP_MASK_TIMEOUT_BUCKLE | KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_BUCKLE_ORC | KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_IGNITION)
/**
 * \brief
 * 		Macro use as return for green status
 */
#define MMG_STATUS_IS_GREEN                   ((uint8)0x00)
/**
 * \brief
 * 		Macro use as return for default status
 */
#define MMG_STATUS_IS_DEFAULT                  ((uint8)0x01)
/**
 * \brief
 * 		Macro use as return for red status
 */
#define MMG_STATUS_IS_RED                     ((uint8)0x02)

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
#define MMG_AC_ModeManagement_START_SEC_VAR_INIT_8
#include "MMG_AC_ModeManagement_MemMap.h"
/**
 * \brief
 *		Previous status of Hall Effect Sensor mode
 * \remarks
 *		None.
 */
static uint8 MMG_u8PrevHESModeStatus = KU8_FALSE;

/**
 * \brief
 *		Default status of AvailabilityDataCategory
 * \remarks
 *		None.
 */
static uint8 u8oldAvailabilityDataCategory = MMG_STATUS_IS_DEFAULT;

/**
 * \brief
 *		Defined macro from C file.
 */
#define MMG_AC_ModeManagement_STOP_SEC_VAR_INIT_8
#include "MMG_AC_ModeManagement_MemMap.h"

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
#define MMG_AC_ModeManagement_START_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"
/**
 * \brief
 *	    This is the executing mode function in charge of manages the �no hall effect sensor� mode.
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
void mmg_UpdateModeStatus_NoHallEffectSensor(void)
{
   /* Aec status */
   u8AecStatusType mmg_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

   /* Read AEC status */
   /* [COVERS: DSG_MMG_0021] */
   (void) Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_HALL_SENSOR_AEC_CFG, &mmg_u8AECStatus);

   if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK != (ERH_KU8_AEC_QUALIFIED_STATUS_MASK & mmg_u8AECStatus))
   {
      /* AEC not qualified : set mode as OFF */
      M_SET_MODE_MASK_OFF(MMG_KU32_MASK_NO_HALL_EFFECT_SENSOR);

      /* Test if the HES mode was previously ON */
      if (KU8_TRUE == MMG_u8PrevHESModeStatus)
      {
         /* Notify the BMM to restore the pulse counting */
         /* [COVERS: DSG_MMG_0039] */
         Rte_Call_pcl_HBSControl_EnableHBSMonitoring();

         /* Set previous mode state to OFF */
         MMG_u8PrevHESModeStatus = KU8_FALSE;
      }
      else
      {
         /* Do nothing */
      }
   }
   else
   {
      /* AEC qualified : set mode as ON */
      M_SET_MODE_MASK_ON(MMG_KU32_MASK_NO_HALL_EFFECT_SENSOR);

      /* Test if the HES mode was previously OFF */
      if (KU8_FALSE == MMG_u8PrevHESModeStatus)
      {
         /* Notify the BMM to inhibit the pulse counting */
         Rte_Call_pcl_HBSControl_DisableHBSMonitoring();

         /* Set previous mode state to ON */
         MMG_u8PrevHESModeStatus = KU8_TRUE;
      }
      else
      {
         /* Do nothing */
      }
   }
}

void mmg_AvailabilityDataStatus(void)
{
   uint32 u32AECGroupStatus;
   uint32 u32AECGroup_GreenStatus = KU32_ZERO;
   uint32 u32AECGroup_RedStatus = KU32_ZERO;
   uint8 u8newAvailabilityDataCategory = MMG_STATUS_IS_DEFAULT;

   /* Get AEC Group status from ERH */
   (void) Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);
   
   u32AECGroup_GreenStatus = (u32AECGroupStatus & MMG_KU32_AEC_MASK_GREEN_STATUS);
   u32AECGroup_RedStatus = (u32AECGroupStatus & MMG_KU32_AEC_MASK_RED_STATUS);

	/* Check which status is active */
   if(KU32_ZERO != u32AECGroup_RedStatus)
   {
      u8newAvailabilityDataCategory = MMG_STATUS_IS_RED;
   }
   else if(KU32_ZERO != u32AECGroup_GreenStatus)
   {
      u8newAvailabilityDataCategory = MMG_STATUS_IS_GREEN;
   }
   else if (KU32_ZERO == u32AECGroupStatus)
   {
      u8newAvailabilityDataCategory = MMG_STATUS_IS_GREEN;
   }
   else
   {
      /* Do nothing */
   }

   if (u8oldAvailabilityDataCategory != u8newAvailabilityDataCategory)
   {
      u8oldAvailabilityDataCategory = u8newAvailabilityDataCategory;
      Rte_Write_AvailabilityDataHandler_AvailabilityDataCategory(u8newAvailabilityDataCategory);
   }
   else
   {
      /* Do nothing */
   }
}



/**
 * \brief
 *		Defined macro from C file.
 */
#define MMG_AC_ModeManagement_STOP_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
