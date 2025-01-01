
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
$Revision: 1.7 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Supplier/Startup/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup RCM.c RCM
 *  This is a new created group, this will create a new man3 file with 
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file. 
 */
 
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "RCM_Callout_Stubs.h"
#include "Rte_RCM_AC_ResetCauseManagement_Type.h"
#include "RCM_Public.h"
#include "SBC.h"
#include "Dem.h"
#include "Fee.h"
#include "Fls_17_Dmu.h"
#include "Os.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/

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
DEFINITION OF APIs
******************************************************************************/

void RCM_ClockFailure_Notification(void)
{
   Dem_UdsStatusByteType rcm_EventStatus = KU8_ZERO;

   (void)Dem_GetEventUdsStatus(DemConf_DemEventParameter_MCU_E_OSC_FAILURE, &rcm_EventStatus);
   
   if ((DEM_UDS_STATUS_CDTC & rcm_EventStatus) == DEM_UDS_STATUS_CDTC)
   {
      RCM_runNotifyResetCause(KU32_OSC_FAILURE_NOTIFICATION, KU32_RESET_CAUSE_ACTIVE);
      /* Reset the system */
      SBC_ForceExternalWatchdogReset();
   }
}

void RCM_PllFailure_Notification(void)
{
   Dem_UdsStatusByteType rcm_EventStatus = KU8_ZERO;

   (void)Dem_GetEventUdsStatus(DemConf_DemEventParameter_MCU_E_SYSTEM_PLL_LOCK_LOSS, &rcm_EventStatus);

   if ((DEM_UDS_STATUS_CDTC & rcm_EventStatus) == DEM_UDS_STATUS_CDTC)
   {
      RCM_runNotifyResetCause(KU32_PLL_LOCK_LOSS_NOTIFICATION, KU32_RESET_CAUSE_ACTIVE);
      /* Reset the system */
      SBC_ForceExternalWatchdogReset();
   }
}

void RCM_DFlashEccFailure_Notification(void)
{
   uint32 rcm_u32EccPageAddr;
   Dem_UdsStatusByteType u8_DF_eventStatus;

   (void)Dem_GetEventUdsStatus(DemConf_DemEventParameter_FEE_E_READ, &u8_DF_eventStatus);

   if ( (DEM_UDS_STATUS_CDTC & u8_DF_eventStatus) == DEM_UDS_STATUS_CDTC )
   {
      if (MEMIF_BLOCK_INCONSISTENT == Fee_GetJobResult())
      {
         /* Get ECC error details */
         (void)Fls_17_Dmu_GetEccErrorPageAddress(&rcm_u32EccPageAddr);

         if (0xFFFFFFFF != rcm_u32EccPageAddr)
         {
            /* DFLASH ECC event */
            RCM_runNotifyResetCause(KU32_ECC_E2P_NOTIFICATION, KU32_RESET_CAUSE_ACTIVE);
         }
         else
         {
            /* Unknown ECC event */
            RCM_runNotifyResetCause(KU32_ECC_UNIDENTIFIED_NOTIFICATION, KU32_RESET_CAUSE_ACTIVE);
         }

         /* Reset the system */
         SBC_ForceExternalWatchdogReset();
      }
   }
}

ISR(RCM_PFlashEccFailure_Notification)
{
   uint32 rcm_u32EccPageAddr;

   (void)Fls_17_Dmu_GetEccErrorPageAddress(rcm_u32EccPageAddr);

   if (0xFFFFFFFF != rcm_u32EccPageAddr)
   {
      /* DFLASH ECC event */
      RCM_runNotifyResetCause(KU32_ECC_PFLASH_NOTIFICATION, KU32_RESET_CAUSE_ACTIVE);
   }
   else
   {
      /* Unknown ECC event */
      RCM_runNotifyResetCause(KU32_ECC_UNIDENTIFIED_NOTIFICATION, KU32_RESET_CAUSE_ACTIVE);
   }

   /* Reset the system */
   SBC_ForceExternalWatchdogReset();
}

ISR(RCM_SRamEccFailure_Notification)
{
   RCM_runNotifyResetCause(KU32_ECC_RAM_NOTIFICATION, KU32_RESET_CAUSE_ACTIVE);
   /* Reset the system */
   SBC_ForceExternalWatchdogReset();   
}

/******************************************************************************
End Of File
*****************************************************************************/




















