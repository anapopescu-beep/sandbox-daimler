/**********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_Callout_Stubs.c
 *   Generation Time: 2022-05-19
 *           Project: DAI_MMA
 *          Delivery: PAI194
 *      Tool Version: DaVinci Configurator (beta) 5.23.10 S-3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
#include "Can.h"
#include "CanIf.h"
#include "CanIf_Cfg.h"
#include "CIL.h"
#include "Nvp_Generated.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
#define ECU_STAT_RBTM_FL_ST3_ID   (0x964201A4u)
#define ECU_STAT_RBTM_FR_ST3_ID   (0x964201A5u)
#define ECU_SIDE_RBTM_FR          (0x99u)

/***********************************************************************************************************************
 *  EXTERNAL DEPENDENCIES
 **********************************************************************************************************************/
extern boolean bNMStateChangedAtStartup;

/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/

/**
* \brief
*     Callback before receiving any PDU
* \param
*     Controller - controller id
*     ID - PDU's Id
*     DataLength - PDU's length
*     DataPtr    - data containing PDU info
* \exception
*     None.
* \pre
*     None
* \post
*     None.
* \return
*     None.
**/
V_DEF_FUNC(extern, Can_ReturnType, APPL_CODE) Appl_GenericPrecopy( uint8 Controller, Can_IdType ID, uint8 DataLength, Can_DataPtrType DataPtr )
{
    static boolean bWakeUpCompleted = FALSE;

    /* Execute the following only if ECU has not been woken up */
    if(bWakeUpCompleted == FALSE)
    {
        /* Set wakeup event only if SBC's wake up reason is not POWER ON(in order to pass Don't wake up on power on test) */

        if (NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation == ECU_SIDE_RBTM_FR)
        {
            EcuM_SetWakeupEvent(ECUM_WKSOURCE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727);
        }
        else
        {
            EcuM_SetWakeupEvent(ECUM_WKSOURCE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6);
        }
        bWakeUpCompleted = TRUE;
    }

    return CAN_OK;
}

/**
* \brief
*     Callback before sending any PDU
* \param
*     Controller - controller id
*     DataPtr    - data containing PDU info
* \exception
*     None.
* \pre
*     None
* \post
*     None.
* \return
*     None.
**/
V_DEF_FUNC(extern, void, APPL_CODE) Appl_GenericPreTransmit( uint8 Controller, Can_PduInfoPtrType_var DataPtr )
{

    /* If NM state callback was not reached in order to set NWStart -> Don't send ECU_STAT PDU */
    if(!bNMStateChangedAtStartup)
    {
        if (NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation == ECU_SIDE_RBTM_FR)
        {
            if(DataPtr->id == ECU_STAT_RBTM_FR_ST3_ID)
            {
                CanIf_CancelTransmit(CanIfTxPduHnd_ECU_Stat_RBTM_FR_ST3_430ba797_Tx);
            }
        }
        else
        {
            if(DataPtr->id == ECU_STAT_RBTM_FL_ST3_ID)
            {
                CanIf_CancelTransmit(CanIfTxPduHnd_ECU_Stat_RBTM_FL_ST3_b7e6aa56_Tx);
            }
        }
    }

   /* [COVERS: DSG_CIL_0031] */
   /* Check PDU CAN Id and update the value of RBTM_Tgl_St3 signal */
   if(DataPtr->id == KU32_CIL_RBTM_FL_CAN_ID)
   {
      if(KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION)
      {
         CIL_bRBTMTgl ^= KB_ONE;
      }
      else
      {
         /*QAC*/
      }
   }
   else if(DataPtr->id == KU32_CIL_RBTM_FR_CAN_ID)
   {
      if(KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)
      {
         CIL_bRBTMTgl ^= KB_ONE;
      }
      else
      {
         /*QAC*/
      }
   }
   else
   {
      /* QAC */
   }
}
