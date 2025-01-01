/*************************************************************************

 AUTOLIV ELECTRONIC document.

 -------------------------------------

 DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

 **************************************************************************

COMPONENT CIL

Current revision: $Revision: 1.1 $
Checked in:       $Date: 2021/10/04 07:14:25CEST $

 **************************************************************************


Overview of the component :
   Part of CIL module

------------------------------------------------------------------------

Design document:
<Document reference>

 *************************************************************************/

/*************************************************************************
Packages inclusion
 *************************************************************************/
#include "Rte_CIL_AC_CommunicationInteractionLayer.h"
#include "common.h"
#include "Config.h"
/*************************************************************************
Intra-package inclusions
 *************************************************************************/
#include "CIL.h"

/*************************************************************************
Declaration of macros
 *************************************************************************/
/**
 * \brief
 * 		Error value for Gurtgeschwindigkeit signal
 */
#define GURTGESCHWINDIGKEIT_ERROR                ((uint16) 0x3FF)

/**
 * \brief
 * 		The lower limit of Gurtgeschwindigkeit signal
 */
#define GURTGESCHWINDIGKEIT_LOWER_LIMIT          ((sint16) -2550)

/**
 * \brief
 * 		The upper limit of Gurtgeschwindigkeit signal
 */
#define GURTGESCHWINDIGKEIT_UPPER_LIMIT          ((sint16)  2550)

/**
 * \brief
 * 		Offset to compute Gurtgeschwindigkeit Signal
 */
#define GURTGESCHWINDIGKEIT_OFFSET               ((uint16)  511)

/**
 * \brief
 * 		If value for Gurtgeschwindigkeit signal is less than lower limit then send error payin
 */
#define GURTGESCHWINDIGKEIT_ERROR_PAYIN          ((uint16)  0)

/**
 * \brief
 * 		If value for Gurtgeschwindigkeit signal is greater than upper limit then send error payout
 */
#define GURTGESCHWINDIGKEIT_ERROR_PAYOUT         ((uint16)  0x3FE)


/**
 * \brief
 * 		Value for Gurtbandauszug Signal error
 */
#define GURTBANDAUSZUG_ERROR                     ((uint16) 0xFFF)

/**
 * \brief
 * 		The lower limit of Gurtbandauszug signal
 */
#define GURTBANDAUSZUG_LOWER_LIMIT               ((sint16) -10235)

/**
 * \brief
 * 		The upper limit of Gurtbandauszug signal
 */
#define GURTBANDAUSZUG_UPPER_LIMIT               ((sint16)  10230)

/**
 * \brief
 * 		Offset to compute Gurtbandauszug Signal
 */
#define GURTBANDAUSZUG_OFFSET                    ((uint16)  2047)

/**
 * \brief
 * 		Offset to compute Temp Signal
 */
#define TEMP_OFFSET                              ((uint8) 0x28)

/**
 * \brief
 * 		The lower limit of temperature signal
 */
#define TEMP_LOWER_LIMIT                         ((sint8)  -40)

/**
 * \brief
 * 		The upper limit of temperature signal
 */
#define TEMP_UPPER_LIMIT                         ((uint8) 0xFD)

/**
 * \brief
 * 		The upper limit of motor current
 */
#define MOTOR_CURRENT_UPPER_LIMIT                ((uint8) 0xFD)

/**
 * \brief
 *		Init value of GURTGESCHWINDIGKEIT signal
 */
#define GURTGESCHWINDIGKEIT_INIT                 ((uint16) 0x1FF)

/**
 * \brief
 *		Init value of GURTBANDAUSZUG signal
 */
#define GURTBANDAUSZUG_INIT                      ((uint16) 0xFFE)

/**
 * \brief
 *		Init value of RGS_XY_Temp signal
 */
#define TEMP_INIT                                ((uint8) 0xFE)

/**
 * \brief
 *		Init value for RGS_XY_Strom signal
 */
#define STROM_INIT                               ((uint8) 0xFE)

/**
 * \brief
 *    Init value for helper variable
 */
#define KU8_LOCAL_RGS_STATUS_INIT_VALUE          ((uint8) 0x00)
/**
 * \brief
 *    Qualification time for unterspannung
 */
#define KU8_UNTERSPANNUNG_QUALIFICATION_TIME     ((uint8) 0x28)
/**
 * \brief
 *    Dequalification time for unterspannung
 */
#define KU8_UNTERSPANNUNG_DEQUALIFICATION_TIME   ((uint8) 0X5A)

/*************************************************************************
Declaration of types
 *************************************************************************/

/*************************************************************************
LOCAL variables declaration
 *************************************************************************/
#define CIL_AC_CommunicationInteractionLayer_START_SEC_VAR_INIT_8
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/* COVERS: TR6_EXT_TF_B_2052, TR6_EXT_TF_B_2061, TR6_EXT_TF_B_2070, TR6_EXT_TF_B_2088 */
/* COVERS: TR6_EXT_TF_B_2093, TR6_EXT_TF_B_2115, TR6_EXT_TF_B_2109, TR6_EXT_TF_B_2103 */
/* COVERS: TR6_EXT_TF_B_2120, TR6_EXT_TF_B_2129, TR6_EXT_TF_B_2167, TR6_EXT_TF_B_2162 */
/* COVERS: TR6_EXT_TF_B_2157, TR6_EXT_TF_B_2152, TR6_EXT_TF_B_2147, TR6_EXT_TF_B_2142 */
/* COVERS: TR6_EXT_TF_B_2137, TR6_EXT_TF_B_2178, TR6_EXT_TF_B_2173, TR6_EXT_TF_B_2186 */

/* COVERS: TR6_EXT_TF_B_2451, TR6_EXT_TF_B_2460, TR6_EXT_TF_B_2469, TR6_EXT_TF_B_2475 */
/* COVERS: TR6_EXT_TF_B_2481, TR6_EXT_TF_B_2487, TR6_EXT_TF_B_2492, TR6_EXT_TF_B_2497 */
/* COVERS: TR6_EXT_TF_B_2502, TR6_EXT_TF_B_2510, TR6_EXT_TF_B_2515, TR6_EXT_TF_B_2520 */
/* COVERS: TR6_EXT_TF_B_2525, TR6_EXT_TF_B_2530, TR6_EXT_TF_B_2535, TR6_EXT_TF_B_2541 */
/* COVERS: TR6_EXT_TF_B_2546, TR6_EXT_TF_B_2551, TR6_EXT_TF_B_2556, TR6_EXT_TF_B_2564 */

/* COVERS: TR6_EXT_TF_B_2326, TR6_EXT_TF_B_2335, TR6_EXT_TF_B_2344, TR6_EXT_TF_B_2350 */
/* COVERS: TR6_EXT_TF_B_2356, TR6_EXT_TF_B_2362, TR6_EXT_TF_B_2367, TR6_EXT_TF_B_2372 */
/* COVERS: TR6_EXT_TF_B_2377, TR6_EXT_TF_B_2385, TR6_EXT_TF_B_2390, TR6_EXT_TF_B_2395 */ 
/* COVERS: TR6_EXT_TF_B_2400, TR6_EXT_TF_B_2405, TR6_EXT_TF_B_2410, TR6_EXT_TF_B_2416 */
/* COVERS: TR6_EXT_TF_B_2421, TR6_EXT_TF_B_2426, TR6_EXT_TF_B_2431, TR6_EXT_TF_B_2439 */

/* COVERS: TR6_EXT_TF_B_2201, TR6_EXT_TF_B_2210, TR6_EXT_TF_B_2219, TR6_EXT_TF_B_2225 */
/* COVERS: TR6_EXT_TF_B_2231, TR6_EXT_TF_B_2237, TR6_EXT_TF_B_2242, TR6_EXT_TF_B_2247 */
/* COVERS: TR6_EXT_TF_B_2252, TR6_EXT_TF_B_2260, TR6_EXT_TF_B_2265, TR6_EXT_TF_B_2270 */
/* COVERS: TR6_EXT_TF_B_2275, TR6_EXT_TF_B_2280, TR6_EXT_TF_B_2285, TR6_EXT_TF_B_2291 */
/* COVERS: TR6_EXT_TF_B_2296, TR6_EXT_TF_B_2301, TR6_EXT_TF_B_2306, TR6_EXT_TF_B_2314 */
/* COVERS: TR6_EXT_TF_B_2585, TR6_EXT_TF_B_2586, TR6_EXT_TF_B_2587, TR6_EXT_TF_B_2588 */
/* COVERS: TR6_EXT_TF_B_2738, TR6_EXT_TF_B_2739, TR6_EXT_TF_B_2740, TR6_EXT_TF_B_2658 */
/* COVERS: TR6_EXT_TF_B_2594, TR6_EXT_TF_B_2595 */

/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_keine_Straffung_Unterspg value
 */
LOCAL u8RGS_keine_Straffung_UnterspgType cil_u8RGS_keine_Straffung_Unterspg = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_keine_Straffung_Ueberspg value
 */
LOCAL u8RGS_keine_Straffung_UeberspgType cil_u8RGS_keine_Straffung_Ueberspg = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_nicht_programmiert value
 */
LOCAL u8RGS_nicht_programmiertType cil_u8RGS_nicht_programmiert = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Uebertemperatur_defekt value
 */
LOCAL u8RGS_Uebertemperatur_defektType cil_u8RGS_Uebertemperatur_defekt = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Bauteilfehler value
 */
LOCAL u8BauteilfehlerType cil_u8Bauteilfehler = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Temp value
 */
LOCAL u8RGS_TempType cil_u8RGS_Temp = TEMP_INIT;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Max_Gurtlosezyklen value
 */
LOCAL u8RGS_Max_GurtlosezyklenType cil_u8RGS_Max_Gurtlosezyklen = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_VL_Max_P2P_Zyklenfehler value
 */
LOCAL u8Max_P2P_ZyklenfehlerType cil_u8Max_P2P_Zyklenfehler = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Unterspannung value
 */
LOCAL u8RGS_UnterspannungType cil_u8RGS_Unterspannung = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Max_Straffzyklenfehler value
 */
LOCAL u8RGS_Max_StraffzyklenfehlerType cil_u8RGS_Max_Straffzyklenfehler = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Max_NGU_Zyklenfehler value
 */
LOCAL u8RGS_VL_Max_NGU_ZyklenfehlerType cil_u8RGS_VL_Max_NGU_Zyklenfehler = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Max_Haptikzyklenfehler value
 */
LOCAL u8RGS_Max_HaptikzyklenfehlerType cil_u8RGS_Max_Haptikzyklenfehler = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Crashabschaltung value
 */
LOCAL u8CrashabschaltungType cil_u8Crashabschaltung = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Ueberspannung value
 */
LOCAL u8RGS_UeberspannungType cil_u8RGS_Ueberspannung = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Motorfehler value
 */
LOCAL u8RGS_MotorfehlerType cil_u8RGS_Motorfehler = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_VL_EEPROM_RAM_ROM_Fehler value
 */
LOCAL u8EEPROM_RAM_ROM_FehlerType cil_u8EEPROM_RAM_ROM_Fehler = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_InPos value
 */
LOCAL u8InPosType cil_u8InPos = KU8_ONE;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Strom value
 */
LOCAL u8RGS_StromType cil_u8RGS_Strom = STROM_INIT;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Status value
 */
LOCAL u8RGS_StatusType cil_u8RGS_Status = KU8_CIL_INIT;

/* [COVERS: DSG_CIL_0047] */
/**
 * \brief
 *		This variable store the flag used to send CIL_runIsSetUnterSpannung signal
 */
LOCAL boolean CIL_bUnterSpannungIsSet = B_FALSE;

/* [COVERS: DSG_CIL_0048] */
/**
 * \brief
 *		This variable store the flag used to send CIL_bUeberSpannungIsSet signal
 */
LOCAL  boolean CIL_bUeberSpannungIsSet = B_FALSE;

/* [COVERS: DSG_CIL_0088] */
/**
 * \brief
 *		This variable store the flag used to send CIL_bKeineStraffungIsSet signal
 */
LOCAL  boolean CIL_bKeineStraffungIsSet = B_FALSE;
/**
 * \brief
 *		This Boolean indicates if the Strom Signal it's different by zero or not.
 */
LOCAL  boolean CIL_b8RGS_StromIsSet = B_FALSE;

/**
 * \brief
 *		This Boolean indicates if the RGS_VL_Max_NGU_Zyklenfehler Signal it's different by zero or not.
 */
LOCAL  boolean CIL_b8RGS_Max_NGU_ZyklenfehlerIsSet = B_FALSE;

/**
 * \brief
 *		This Boolean indicates if the RGS_VL_Max_P2P_Zyklenfehler Signal it's different by zero or not.
 */
LOCAL  boolean CIL_b8RGS_Max_P2P_ZyklenfehlerIsSet = B_FALSE;

/**
 * \brief
 *		This Boolean indicates if the RGS_VL_EEPROM_RAM_ROM_Fehler Signal it's different by zero or not.
 */
LOCAL  boolean CIL_b8RGS_EEPROM_RAM_ROM_FehlerIsSet = B_FALSE;

#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_VAR_INIT_8
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

#define CIL_AC_CommunicationInteractionLayer_START_SEC_VAR_UNSPECIFIED
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Gurtgeschwindigkeit value
 */
LOCAL u16GurtgeschwindigkeitType cil_u16Gurtgeschwindigkeit = GURTGESCHWINDIGKEIT_INIT;
/**
 * \brief
 *		This variable is used to store CAN signal RGS_XY_Gurtbandauszug value
 */
LOCAL u16GurtbandauszugType cil_u16Gurtbandauszug = GURTBANDAUSZUG_INIT;

#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_VAR_UNSPECIFIED
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/*************************************************************************
LOCAL constant data declaration
 **************************************************************************/

/**************************************************************************
LOCAL Functions
 **************************************************************************/
#define CIL_AC_CommunicationInteractionLayer_START_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/* [COVERS: DSG_CIL_0047] */

/**
 * \brief
 *		This service is used to send CIL_bUnterSpannungIsSet signal
 * \param[in,out]
 * 		boolean CIL_bUnterSpannungIsSet
 * \return
 * 		void
 */
EXPORTED void CIL_runIsSetUnterSpannung(boolean* bIsSetUnterSpannung)
{
   *bIsSetUnterSpannung = CIL_bUnterSpannungIsSet;
}
/* [COVERS: DSG_CIL_0048] */

/**
 * \brief
 *		This service is used to send CIL_bUeberSpannungIsSet signal
 * \param[in,out]
 * 		boolean bIsSetUeberSpannung
 * \return
 * 		void
 */
EXPORTED void CIL_runISetUeberSpannung(boolean* bIsSetUeberSpannung)
{
   *bIsSetUeberSpannung = CIL_bUeberSpannungIsSet;
}

/* [COVERS: DSG_CIL_0046] */
/**
 * \brief
 *		This service is used to send CIL_b8HWErrorPresent
 * \param[in,out]
 * 		boolean bHWErrorPresent
 * \return
 * 		void
 */
EXPORTED void CIL_runIsHWErrorPresent(boolean* bHWErrorPresent)
{
   *bHWErrorPresent = CIL_bHWErrorPresent;
}
/* [COVERS: DSG_CIL_0088] */
/**
 * \brief
 *		This service is used to send cil_u8RGS_keine_Straffung_Unterspg signal
 * \param[in,out]
 * 		boolean bIsSetUeberSpannung
 * \return
 * 		void
 */
EXPORTED void CIL_runIsSetKeineStraffung(boolean* bIsSetKeineStraffung)
{
   *bIsSetKeineStraffung = CIL_bKeineStraffungIsSet;
}
/* [COVERS: DSG_CIL_0007] */
/**
 * \brief
 *		This service is used to compute Signal Gurtgeschwindigkeit
 * \parm
 * 		void
 * \return
 * 		void
 */
LOCAL void cil_ComputeSignalGurtgeschwindigkeit(void)
{
   Dem_EventStatusExtendedType u8FaultStatus;
   s32BeltSpeed_deg_sType s32BeltSpeed_deg_s;

   (void)Rte_Call_pclEvtInfoHallSensor_GetEventStatus(&u8FaultStatus);
   if (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus) )
   {
      cil_u16Gurtgeschwindigkeit =  GURTGESCHWINDIGKEIT_ERROR;
   }
   else
   {
      (void)Rte_Call_pclBelt_S_GetSpeed_deg_s(&s32BeltSpeed_deg_s);
      if ((sint16)s32BeltSpeed_deg_s < GURTGESCHWINDIGKEIT_LOWER_LIMIT)
      {
         cil_u16Gurtgeschwindigkeit =  GURTGESCHWINDIGKEIT_ERROR_PAYIN;
      }
      else if ((sint16)s32BeltSpeed_deg_s > GURTGESCHWINDIGKEIT_UPPER_LIMIT)
      {
         cil_u16Gurtgeschwindigkeit =  GURTGESCHWINDIGKEIT_ERROR_PAYOUT;
      }
      else
      {
         /* QAC_WARNING S 4393 1 */ /*QAC_WARNING S 1850 1 */ /*QAC_WARNING S 1860 1 *//* A composite expression of 'essentially signed' type (signed int) is being cast to a different type category, 'unsigned'.
          * sint32 variable are converted into uint32 variable , because the resulted value will always be positive. */
         cil_u16Gurtgeschwindigkeit = (u16GurtgeschwindigkeitType)(((sint16)s32BeltSpeed_deg_s/KU8_FIVE) + GURTGESCHWINDIGKEIT_OFFSET);
      }
   }
}

/* [COVERS: DSG_CIL_0008] */
/**
 * \brief
 *		The function is called by CIL_runAppliToCAN to compute the value for Signal Gurtbandauszug
 * \parm
 * 		void
 * \return
 * 		void
 */
LOCAL void cil_ComputeSignalGurtbandauszug(void)
{
   Dem_EventStatusExtendedType u8FaultStatus;
   s16BeltPosition_degType  s16BeltPosition_deg;

   (void)Rte_Call_pclEvtInfoHallSensor_GetEventStatus(&u8FaultStatus);
   if (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus) )
   {
      cil_u16Gurtbandauszug =  GURTBANDAUSZUG_ERROR;
   }
   else
   {
      (void)Rte_Call_pclBelt_D_GetFromT0_deg(&s16BeltPosition_deg);
      if (s16BeltPosition_deg < GURTBANDAUSZUG_LOWER_LIMIT)
      {
         cil_u16Gurtbandauszug =  GURTBANDAUSZUG_ERROR;
      }
      else if (s16BeltPosition_deg > GURTBANDAUSZUG_UPPER_LIMIT)
      {
         cil_u16Gurtbandauszug =  GURTBANDAUSZUG_ERROR;
      }
      else
      {
         /* QAC_WARNING S 4393 1 */ /*QAC_WARNING S 1850 1 */ /*QAC_WARNING S 1860 1 *//* A composite expression of 'essentially signed' type (signed int) is being cast to a different type category, 'unsigned'.
          * sint16 variable are converted into uint16 variable , because the resulted value will always be positive. */
         cil_u16Gurtbandauszug = (u16GurtbandauszugType)(((sint16)s16BeltPosition_deg/KU8_FIVE) + GURTBANDAUSZUG_OFFSET);
      }
   }
}

/* [COVERS: DSG_CIL_0023; DSG_CIL_0063; DSG_CIL_0062; DSG_CIL_0065] */
/**
 * \brief
 *		The function is called by CIL_runAppliToCAN to compute the value for Signal Status
 * \parm
 * 		void
 * \return
 * 		void
 */
LOCAL void cil_ComputeSignalStatus(void)
{
   uint8 u8ReturnBFDCycle;
   uint8 u8ExecutedCycle;
   uint8 u8LastInterruptedCycle;
   uint8 u8HrdReleaseTriggeringSource = KU8_TRIGGERING_SOURCE_NONE;
   uint8 u8BpdcTriggeringSource = KU8_TRIGGERING_SOURCE_NONE;
   uint8 u8BpdoTriggeringSource = KU8_TRIGGERING_SOURCE_NONE;
   uint8 u8Hwa0TriggeringSource = KU8_TRIGGERING_SOURCE_NONE;
   uint8 u8Hwa1TriggeringSource = KU8_TRIGGERING_SOURCE_NONE;
   uint8 u8LocalRGS_Status = KU8_LOCAL_RGS_STATUS_INIT_VALUE;
   static uint8 u8ResponseCounter = KU8_ZERO;
   boolean b8HRDAbortionFlag,b8BPAAbortionFlag;

   (void)Rte_Call_pclCanResponse_GetCanResponse(&u8ReturnBFDCycle);
   (void)Rte_Read_prrCycleNumber_u8CycleNumber(&u8ExecutedCycle);
   (void)Rte_Call_pclSystemContextManagement_GetMonitoredCycle(&u8LastInterruptedCycle);
   (void)Rte_Read_prrAlgo_Flags_BPDC_u8TriggeringSource(&u8BpdcTriggeringSource);
   (void)Rte_Read_prrAlgo_Flags_BPDO_u8TriggeringSource(&u8BpdoTriggeringSource);
   (void)Rte_Read_prrAlgo30_Flags_u8TriggeringSource(&u8Hwa0TriggeringSource);
   (void)Rte_Read_prrAlgo31_Flags_u8TriggeringSource(&u8Hwa1TriggeringSource);
   (void)Rte_Read_prrAlgo33_Flags_u8TriggeringSource(&u8HrdReleaseTriggeringSource);

   if (u8ExecutedCycle != KU8_CYCLE_ID_HRD)
   {
      CIL_bReleaseRequested = B_FALSE;
   }

   if(KU8_CIL_INITIALIZATION_PHASE == CIL_u8Startup)
   {
      u8LocalRGS_Status = KU8_CIL_INIT;
   }
   else if( (KU8_CIL_DELAYED_INITIALIZATION_PHASE == CIL_u8Startup) && (KU8_CIL_KEINE_AKTION != CIL_u8RawActivationRequest) )
   {
      u8LocalRGS_Status = KU8_CIL_FEHLERHAFTE_STRAFFDURCHFUEHRUNG;
   }
   else if(KU8_CIL_DELAYED_INITIALIZATION_PHASE == CIL_u8Startup)
   {
      u8LocalRGS_Status = KU8_CIL_KEINE_AKTION;
   }
   /* If an abort was detected and not notified to the master continue refreshing data with this information*/
   else if (B_TRUE == CIL_bAbortRequested)
   {
      u8LocalRGS_Status = KU8_CIL_CRASHABSCHALTUNG;
   }
   else if (KU8_INCORRECT_TENSIONING_COMMAND == CIL_u8ActivationRequest)
   {
      u8LocalRGS_Status = KU8_CIL_FEHLERHAFTE_STRAFFANFORDERUNG;
   }
   else if ((KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION == u8ReturnBFDCycle) && ((CIL_u8ActivationRequest <= KU8_CYCLE_ID_BSR) || (KU8_NO_ACTION == CIL_u8ActivationRequest)) )
   {
      if( ( (CIL_u8ActivationRequest <= KU8_CYCLE_ID_PRESAFE_23) && (KU8_FALSE == CAL_NVP_B8_PRE_TENSIONING_FUNCTION_ENABLED) ) ||
            ( ( (KU8_CYCLE_ID_BSR == CIL_u8ActivationRequest) && (KU8_FALSE == CAL_NVP_B8_BSR_FUNCTION_ENABLED) ) ) )
      {
         u8LocalRGS_Status = KU8_CIL_FEHLERHAFTE_STRAFFANFORDERUNG;
      }
      else
      {
         u8LocalRGS_Status = KU8_CIL_FEHLERHAFTE_STRAFFDURCHFUEHRUNG;
      }
   }
   else if ((KU8_INCORRECT_TENSIONING_EXECUTION_ABORTION_TENS == u8ReturnBFDCycle) && ((CIL_u8ActivationRequest <= KU8_CYCLE_ID_PRESAFE_23) || (KU8_NO_ACTION == CIL_u8ActivationRequest)) )
   {
      u8LocalRGS_Status = KU8_CIL_FEHLERHAFTE_STRAFFDURCHFUEHRUNG;
   }
   else if ((KU8_INCORRECT_TENSIONING_EXECUTION_ABORTION_BSR == u8ReturnBFDCycle) && ((CIL_u8ActivationRequest == KU8_CYCLE_ID_BSR) || (KU8_NO_ACTION == CIL_u8ActivationRequest)) )
   {
      if (KU8_NO_ACTION == CIL_u8ActivationRequest) 
      {
         if (u8ResponseCounter < KU8_TEN)
         {
            u8ResponseCounter++;
            u8LocalRGS_Status = KU8_CIL_FEHLERHAFTE_STRAFFDURCHFUEHRUNG;
         }
         else
         {
            u8LocalRGS_Status = KU8_CIL_KEINE_AKTION;
         }

      }
      else
      {
         u8LocalRGS_Status = KU8_CIL_FEHLERHAFTE_STRAFFDURCHFUEHRUNG;
      }

   }
   else if (KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION == CIL_u8ActivationRequest)
   {
      u8LocalRGS_Status = KU8_CIL_FEHLERHAFTE_STRAFFDURCHFUEHRUNG;
   }
   else
   {
      switch(u8ReturnBFDCycle)
      {
      case KU8_CYCLE_ID_PRESAFE_0:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_1_MAXGURTKRAFT;
         break;
      case KU8_CYCLE_ID_PRESAFE_1:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_2;
         break;
      case KU8_CYCLE_ID_PRESAFE_2:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_3;
         break;
      case KU8_CYCLE_ID_PRESAFE_3:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_4_NGU;
         break;
      case KU8_CYCLE_ID_PRESAFE_4:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_5;
         break;
      case KU8_CYCLE_ID_PRESAFE_5:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_6;
         break;
      case KU8_CYCLE_ID_PRESAFE_6:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_7;
         break;
      case KU8_CYCLE_ID_PRESAFE_7:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_8;
         break;
      case KU8_CYCLE_ID_PRESAFE_8:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_9;
         break;
      case KU8_CYCLE_ID_PRESAFE_9:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_10;
         break;
      case KU8_CYCLE_ID_PRESAFE_10:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_11;
         break;
      case KU8_CYCLE_ID_PRESAFE_11:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_12;
         break;
      case KU8_CYCLE_ID_PRESAFE_12:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_13;
         break;
      case KU8_CYCLE_ID_PRESAFE_13:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_14;
         break;
      case KU8_CYCLE_ID_PRESAFE_14:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_15;
         break;
      case KU8_CYCLE_ID_PRESAFE_15:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_16;
         break;
      case KU8_CYCLE_ID_PRESAFE_16:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_17;
         break;
      case KU8_CYCLE_ID_PRESAFE_17:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_18;
         break;
      case KU8_CYCLE_ID_PRESAFE_18:
         u8LocalRGS_Status = KU8_CIL_STRAFFUNG_19;
         break;
      case KU8_CYCLE_ABORT:
         u8LocalRGS_Status = KU8_CIL_CRASHABSCHALTUNG;
         break;
      case KU8_CYCLE_ID_BSR:
         u8LocalRGS_Status = KU8_CIL_GURTLOSEREDUZIERUNG;
         u8ResponseCounter = KU8_ZERO;
         break;
      default:
         break;
      }

      if (CIL_u8ActivationRequest > KU8_CIL_GURTLOSEREDUZIERUNG)
      {
         if (((B_FALSE == CIL_bHWAInhibited) && ((CIL_bHaptikStarted == B_TRUE) && (KU8_TRIGGERING_SOURCE_TESTER != u8Hwa1TriggeringSource))) ||
               ((B_FALSE == CIL_bHWAInhibited) && ((KU8_CYCLE_ID_HWA_0 == CIL_u8ActivationRequest) && (KU8_TRIGGERING_SOURCE_TESTER != u8Hwa0TriggeringSource))))
         {
            u8LocalRGS_Status = KU8_CIL_STRAFFUNG_20_HAPTIK;
            u8ResponseCounter = KU8_ZERO;
         }
         else if ((B_TRUE == CIL_bBPAInhibited) &&
               (((KU8_CYCLE_ID_BPDC == CIL_u8ActivationRequest) && (KU8_TRIGGERING_SOURCE_TESTER != u8BpdcTriggeringSource)) ||
                     ((KU8_CYCLE_ID_BPDO == CIL_u8ActivationRequest) && (KU8_TRIGGERING_SOURCE_TESTER != u8BpdoTriggeringSource))))
         {
            if(KU8_FALSE == CAL_NVP_B8_BPA_FCT_ENABLED)
            {
               u8LocalRGS_Status = KU8_CIL_FEHLERHAFTE_STRAFFANFORDERUNG;
            }
            else
            {
               u8LocalRGS_Status = KU8_CIL_FEHLERHAFTE_STRAFFDURCHFUEHRUNG;
            }
         }
         else if (((KU8_CYCLE_ID_BPDO == u8ExecutedCycle) || (KU8_CYCLE_ID_BPDO == CIL_u8ActivationRequest)) &&
               (KU8_TRIGGERING_SOURCE_TESTER != u8BpdoTriggeringSource))
         {
            u8LocalRGS_Status = KU8_CIL_GURTPARKEN_2;
            u8ResponseCounter = KU8_ZERO;
         }
         else if (((KU8_CYCLE_ID_BPDC == u8ExecutedCycle) || (KU8_CYCLE_ID_BPDC == CIL_u8ActivationRequest)) &&
               (KU8_TRIGGERING_SOURCE_TESTER != u8BpdcTriggeringSource))
         {
            u8LocalRGS_Status = KU8_CIL_GURTPARKEN_1;
            u8ResponseCounter = KU8_ZERO;
         }
         else if ( ((B_TRUE == CIL_bReleaseRequested) || (KU8_CYCLE_ID_HRD == CIL_u8ActivationRequest) )  &&
                   (B_FALSE == CIL_bReleaseInhibited) &&
                   (KU8_TRIGGERING_SOURCE_TESTER != u8HrdReleaseTriggeringSource) )
         {
            u8LocalRGS_Status = KU8_CIL_FUNKTION_BEENDEN_LOESEKURVE_2;
            u8ResponseCounter = KU8_ZERO;
         }
         else if ((B_TRUE == CIL_bReleaseInhibited) && (KU8_TRIGGERING_SOURCE_TESTER != u8HrdReleaseTriggeringSource))
         {
            u8LocalRGS_Status = KU8_CIL_FEHLERHAFTE_STRAFFDURCHFUEHRUNG;
         }
         else if ((KU8_CIL_KEINE_AKTION != CIL_u8RawActivationRequest) && (KU8_CIL_INITIALIZATION_PHASE != CIL_u8Startup) && (KU8_CIL_INIT != CIL_u8RawActivationRequest))
         {
            u8LocalRGS_Status = CIL_u8RawActivationRequest;
         }
         else if (KU8_LOCAL_RGS_STATUS_INIT_VALUE == u8LocalRGS_Status)
         {
            u8LocalRGS_Status = KU8_CIL_KEINE_AKTION;

            /* Compute HWA+HRD response for abortion */
            (void)Rte_Read_psrAbortionFlagHRD_b8AbortionFlag(&b8HRDAbortionFlag);
            (void)Rte_Read_psrAbortionFlagBPA_b8AbortionFlag(&b8BPAAbortionFlag);
            if( ( (KU8_TRUE == CIL_bPrepareResponseHWA ) && (B_TRUE == CIL_bHWAInhibited) )   ||
                  ( (KU8_TRUE == CIL_bPrepareResponseHRD ) && (KU8_ZERO == b8HRDAbortionFlag) ) ||
                  ( (KU8_TRUE == CIL_bPrepareResponseBPA ) && (KU8_ZERO == b8BPAAbortionFlag) ) )
            {
               if (u8ResponseCounter < KU8_TEN)
               {
                  u8ResponseCounter++;
                  u8LocalRGS_Status = KU8_CIL_FEHLERHAFTE_STRAFFDURCHFUEHRUNG;
               }
               else
               {
                  u8LocalRGS_Status = KU8_CIL_KEINE_AKTION;
               }
            }
            else if( ( (KU8_TRUE == CIL_bPrepareResponseHWA ) && (KU8_TEN > u8ResponseCounter ) && ( KU8_ZERO != u8ResponseCounter ))  ||
            		 ( (KU8_TRUE == CIL_bPrepareResponseHRD ) && (KU8_TEN > u8ResponseCounter ) && ( KU8_ZERO != u8ResponseCounter ))  ||
					 ( (KU8_TRUE == CIL_bPrepareResponseBPA ) && (KU8_TEN > u8ResponseCounter ) && ( KU8_ZERO != u8ResponseCounter )) )
            {
               u8ResponseCounter++;
               u8LocalRGS_Status = KU8_CIL_FEHLERHAFTE_STRAFFDURCHFUEHRUNG;
            }
            else
            {
               u8LocalRGS_Status = KU8_CIL_KEINE_AKTION;
               CIL_bPrepareResponseHWA = KU8_FALSE;
               CIL_bPrepareResponseHRD = KU8_FALSE;
            }
         }
         else
         {
        	/* do nothing */
         }
      }
   }

   cil_u8RGS_Status = u8LocalRGS_Status;
}

/* [COVERS: DSG_CIL_0022] */
/**
 * \brief
 *		This service is used to compute Signal Strom
 * \parm
 * 		void
 * \return
 * 		void
 */
LOCAL void cil_ComputeSignalStrom(void)
{
   sint8 s8MotorCurrentInA;
   uint8 u8CalcMotorCurrent;

   (void)Rte_Call_pclMotor_I_Get_A(&s8MotorCurrentInA);
   u8CalcMotorCurrent = U8_GET_ABSOLUTE_VALUE_FROM_S8(s8MotorCurrentInA);
   u8CalcMotorCurrent = (uint8)(u8CalcMotorCurrent*KU8_FIVE);
   if (u8CalcMotorCurrent > MOTOR_CURRENT_UPPER_LIMIT)
   {
      cil_u8RGS_Strom = KU8_MAX;
   }
   else
   {
      cil_u8RGS_Strom = u8CalcMotorCurrent;
   }
}

/* [COVERS: DSG_CIL_0014] */
/**
 * \brief
 *		The function is called by CIL_runAppliToCAN to compute the value for Signal Tempp
 * \parm
 * 		void
 * \return
 * 		void
 */
LOCAL void cil_ComputeSignalTemp(void)
{
   sint16 s16InternalTemperature_deg;
   Dem_EventStatusExtendedType u8FaultStatus;

   /* QAC_WARNING S 4393 2 */ /*QAC_WARNING S 1850 2 */ /*QAC_WARNING S 1860 2 *//* A composite expression of 'essentially signed' type (signed int) is being cast to a different type category, 'unsigned'.
    * sint8 variable are converted into uint8 variable , because the resulted value will always be positive. */
   /* Signal RGS_VL_Temp */
   (void)Rte_Call_pclEvtInfoTemperatureSensorFailure_GetEventStatus(&u8FaultStatus);
   if (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus) )
   {
      cil_u8RGS_Temp = KU8_MAX;
   }
   else
   {
      (void)Rte_Call_pclECU_T_GetFiltered_deg(&s16InternalTemperature_deg);

      if (((s16InternalTemperature_deg + (sint16)TEMP_OFFSET)*(sint16)KU8_TWO) > ((sint16)TEMP_UPPER_LIMIT))
      {
         cil_u8RGS_Temp = KU8_TWO_HUNDRED_FIFTY_THREE;
      }
      else if (s16InternalTemperature_deg < TEMP_LOWER_LIMIT)
      {
         cil_u8RGS_Temp = KU8_ZERO;
      }
      else
      {
         cil_u8RGS_Temp = (uint8)((s16InternalTemperature_deg + (sint16)TEMP_OFFSET) * (sint16)KU8_TWO);
      }
   }

}

/* [COVERS: DSG_CIL_0076] */
/**
 * \brief
 *    The function is called by CIL_runAppliToCAN to check if one of the critical auto tests is not set to active error
 * \parm
 *       void
 * \return
 *       void
 */
LOCAL void cil_CheckStatusOfCriticalAutotests(void)
{
   if ( (KU8_CIL_DELAYED_INITIALIZATION_PHASE == CIL_u8Startup) && (KU8_CIL_KEINE_AKTION != CIL_u8RawActivationRequest))
   {
      if((KU8_ZERO == cil_u8RGS_nicht_programmiert) ||
            (KU8_ZERO == cil_u8Bauteilfehler) ||
            (KU8_ZERO == cil_u8RGS_Max_Gurtlosezyklen) ||
            (KU8_ZERO == cil_u8RGS_Max_Straffzyklenfehler) ||
            (KU8_ZERO == cil_u8RGS_VL_Max_NGU_Zyklenfehler) ||
            (KU8_ZERO == cil_u8RGS_Max_Haptikzyklenfehler) ||
            (KU8_ZERO == cil_u8RGS_Motorfehler) ||
            (KU8_ZERO == cil_u8EEPROM_RAM_ROM_Fehler) )
      {
         CIL_bCriticalAutotestsResponse = B_FALSE;
      }
      else
      {
         CIL_bCriticalAutotestsResponse = B_TRUE;
      }
   }
   else
   {
      CIL_bCriticalAutotestsResponse = B_FALSE;
   }
}

#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/*************************************************************************
EXPORTED variables declaration
 *************************************************************************/

/**************************************************************************
Exported Functions
 **************************************************************************/

#define CIL_AC_CommunicationInteractionLayer_START_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/*COVERS: TR6_EXT_TF_B_2050, TR6_EXT_TF_B_2053, TR6_EXT_TF_B_2051, TR6_EXT_TF_B_2054 */
/*COVERS: TR6_EXT_TF_B_2055, TR6_EXT_TF_B_2060, TR6_EXT_TF_B_2061, TR6_EXT_TF_B_2062, TR6_EXT_TF_B_2063 */
/*COVERS: TR6_EXT_TF_B_2064, TR6_EXT_TF_B_2065, TR6_EXT_TF_B_2069, TR6_EXT_TF_B_2072, TR6_EXT_TF_B_2087 */
/*COVERS: TR6_EXT_TF_B_2089, TR6_EXT_TF_B_2092, TR6_EXT_TF_B_2094, TR6_EXT_TF_B_2116, TR6_EXT_TF_B_2110 */
/*COVERS: TR6_EXT_TF_B_2104, TR6_EXT_TF_B_2108, TR6_EXT_TF_B_2102, TR6_EXT_TF_B_2114, TR6_EXT_TF_B_2119 */
/*COVERS: TR6_EXT_TF_B_2122, TR6_EXT_TF_B_2121, TR6_EXT_TF_B_2124, TR6_EXT_TF_B_2125, TR6_EXT_TF_B_2128 */
/*COVERS: TR6_EXT_TF_B_2131, TR6_EXT_TF_B_2168, TR6_EXT_TF_B_2163, TR6_EXT_TF_B_2158, TR6_EXT_TF_B_2153 */
/*COVERS: TR6_EXT_TF_B_2148, TR6_EXT_TF_B_2146, TR6_EXT_TF_B_2141, TR6_EXT_TF_B_2136, TR6_EXT_TF_B_2143 */
/*COVERS: TR6_EXT_TF_B_2138, TR6_EXT_TF_B_2166, TR6_EXT_TF_B_2161, TR6_EXT_TF_B_2174, TR6_EXT_TF_B_2156 */
/*COVERS: TR6_EXT_TF_B_2151, TR6_EXT_TF_B_2172, TR6_EXT_TF_B_2177, TR6_EXT_TF_B_2180, TR6_EXT_TF_B_2179 */
/*COVERS: TR6_EXT_TF_B_2181, TR6_EXT_TF_B_2182, TR6_EXT_TF_B_2185, TR6_EXT_TF_B_2188, TR6_EXT_TF_B_2106 */

/*COVERS: TR6_EXT_TF_B_2450, TR6_EXT_TF_B_2452, TR6_EXT_TF_B_2453, TR6_EXT_TF_B_2454, TR6_EXT_TF_B_2455 */
/*COVERS: TR6_EXT_TF_B_2459, TR6_EXT_TF_B_2461, TR6_EXT_TF_B_2462, TR6_EXT_TF_B_2463, TR6_EXT_TF_B_2464 */
/*COVERS: TR6_EXT_TF_B_2468, TR6_EXT_TF_B_2470, TR6_EXT_TF_B_2474, TR6_EXT_TF_B_2476, TR6_EXT_TF_B_2480 */
/*COVERS: TR6_EXT_TF_B_2482, TR6_EXT_TF_B_2486, TR6_EXT_TF_B_2488, TR6_EXT_TF_B_2491, TR6_EXT_TF_B_2493 */
/*COVERS: TR6_EXT_TF_B_2496, TR6_EXT_TF_B_2498, TR6_EXT_TF_B_2501, TR6_EXT_TF_B_2503, TR6_EXT_TF_B_2504 */
/*COVERS: TR6_EXT_TF_B_2505, TR6_EXT_TF_B_2506, TR6_EXT_TF_B_2509, TR6_EXT_TF_B_2511, TR6_EXT_TF_B_2514 */
/*COVERS: TR6_EXT_TF_B_2516, TR6_EXT_TF_B_2519, TR6_EXT_TF_B_2521, TR6_EXT_TF_B_2524, TR6_EXT_TF_B_2526 */
/*COVERS: TR6_EXT_TF_B_2529, TR6_EXT_TF_B_2531, TR6_EXT_TF_B_2534, TR6_EXT_TF_B_2536, TR6_EXT_TF_B_2540 */
/*COVERS: TR6_EXT_TF_B_2542, TR6_EXT_TF_B_2545, TR6_EXT_TF_B_2552, TR6_EXT_TF_B_2555, TR6_EXT_TF_B_2557 */
/*COVERS: TR6_EXT_TF_B_2558, TR6_EXT_TF_B_2559, TR6_EXT_TF_B_2560, TR6_EXT_TF_B_2563, TR6_EXT_TF_B_2565 */

/*COVERS: TR6_EXT_TF_B_2325, TR6_EXT_TF_B_2327, TR6_EXT_TF_B_2328, TR6_EXT_TF_B_2329, TR6_EXT_TF_B_2330 */
/*COVERS: TR6_EXT_TF_B_2334, TR6_EXT_TF_B_2336, TR6_EXT_TF_B_2337, TR6_EXT_TF_B_2338, TR6_EXT_TF_B_2339 */
/*COVERS: TR6_EXT_TF_B_2343, TR6_EXT_TF_B_2345, TR6_EXT_TF_B_2349, TR6_EXT_TF_B_2351, TR6_EXT_TF_B_2355 */
/*COVERS: TR6_EXT_TF_B_2357, TR6_EXT_TF_B_2361, TR6_EXT_TF_B_2363, TR6_EXT_TF_B_2366, TR6_EXT_TF_B_2368 */
/*COVERS: TR6_EXT_TF_B_2371, TR6_EXT_TF_B_2373, TR6_EXT_TF_B_2376, TR6_EXT_TF_B_2378, TR6_EXT_TF_B_2379 */
/*COVERS: TR6_EXT_TF_B_2380, TR6_EXT_TF_B_2381, TR6_EXT_TF_B_2384, TR6_EXT_TF_B_2386, TR6_EXT_TF_B_2389 */
/*COVERS: TR6_EXT_TF_B_2391, TR6_EXT_TF_B_2394, TR6_EXT_TF_B_2396, TR6_EXT_TF_B_2399, TR6_EXT_TF_B_2401 */ 
/*COVERS: TR6_EXT_TF_B_2404, TR6_EXT_TF_B_2406, TR6_EXT_TF_B_2409, TR6_EXT_TF_B_2411, TR6_EXT_TF_B_2415 */
/*COVERS: TR6_EXT_TF_B_2417, TR6_EXT_TF_B_2420, TR6_EXT_TF_B_2422, TR6_EXT_TF_B_2425, TR6_EXT_TF_B_2427 */
/*COVERS: TR6_EXT_TF_B_2430, TR6_EXT_TF_B_2432, TR6_EXT_TF_B_2433, TR6_EXT_TF_B_2434, TR6_EXT_TF_B_2435 */
/*COVERS: TR6_EXT_TF_B_2438, TR6_EXT_TF_B_2440, TR6_EXT_TF_B_2240, TR6_EXT_TF_B_2365, TR6_EXT_TF_B_2490 */

/*COVERS: TR6_EXT_TF_B_2200, TR6_EXT_TF_B_2202, TR6_EXT_TF_B_2203, TR6_EXT_TF_B_2204, TR6_EXT_TF_B_2205 */
/*COVERS: TR6_EXT_TF_B_2209, TR6_EXT_TF_B_2211, TR6_EXT_TF_B_2212, TR6_EXT_TF_B_2213, TR6_EXT_TF_B_2214 */
/*COVERS: TR6_EXT_TF_B_2218, TR6_EXT_TF_B_2220, TR6_EXT_TF_B_2224, TR6_EXT_TF_B_2226, TR6_EXT_TF_B_2230 */
/*COVERS: TR6_EXT_TF_B_2232, TR6_EXT_TF_B_2236, TR6_EXT_TF_B_2238, TR6_EXT_TF_B_2241, TR6_EXT_TF_B_2243 */
/*COVERS: TR6_EXT_TF_B_2246, TR6_EXT_TF_B_2248, TR6_EXT_TF_B_2251, TR6_EXT_TF_B_2253, TR6_EXT_TF_B_2254 */
/*COVERS: TR6_EXT_TF_B_2255, TR6_EXT_TF_B_2256, TR6_EXT_TF_B_2259, TR6_EXT_TF_B_2261, TR6_EXT_TF_B_2264 */
/*COVERS: TR6_EXT_TF_B_2266, TR6_EXT_TF_B_2269, TR6_EXT_TF_B_2271, TR6_EXT_TF_B_2274 */
/*COVERS: TR6_EXT_TF_B_2279, TR6_EXT_TF_B_2281, TR6_EXT_TF_B_2284, TR6_EXT_TF_B_2286, TR6_EXT_TF_B_2290 */
/*COVERS: TR6_EXT_TF_B_2292, TR6_EXT_TF_B_2295, TR6_EXT_TF_B_2297, TR6_EXT_TF_B_2300, TR6_EXT_TF_B_2302 */
/*COVERS: TR6_EXT_TF_B_2305, TR6_EXT_TF_B_2307, TR6_EXT_TF_B_2308, TR6_EXT_TF_B_2309, TR6_EXT_TF_B_2310 */
/*COVERS: TR6_EXT_TF_B_2313, TR6_EXT_TF_B_2315, TR6_EXT_TF_B_2671, TR6_EXT_TF_B_2818, TR6_EXT_TF_B_2705 */
/*COVERS: DSG_CIL_0009, DSG_CIL_0010, DSG_CIL_0011, DSG_CIL_0012, DSG_CIL_0013, DSG_CIL_0014 */
/*COVERS: DSG_CIL_0016, DSG_CIL_0017, DSG_CIL_0018, DSG_CIL_0019, DSG_CIL_0020, DSG_CIL_0053 */
/**
 * \brief
 *		CIL periodic main function used to update transmitted frames signals values
 *		This service is in charge of computing all signals from RGS_VL_01 frame
 * \parm
 * 		void
 * \return
 * 		void
 * \remark
 * 		This service is in charge of computing all signals from RGS_VL_01 frame:
 * 			Signal RGS_VL_Gurtgeschwindigkeit
 * 			Signal RGS_VL_Gurtbandauszug
 * 			Signal RGS_VL_keineStraffungUnterspg
 * 			Signal RGS_VL_nicht_programmiert
 * 		    Signal RGS_VL_Uebertemperatur_defekt
 * 			Signal RGS_VL_Bauteilfehler
 * 			Signal RGS_VL_Max_Gurtlosezyklen
 * 			Signal RGS_VL_Temp
 * 			Signal RGS_VL_Kommunikationsfehler_ASG
 * 			Signal RGS_VL_Unterspannung
 * 			Signal RGS_VL_Max_Straffzyklenfehler
 * 			Signal RGS_VL_Max_Haptikzyklenfehler
 * 			Signal RGS_VL_Crashabschaltung
 * 			Signal RGS_VL_Ueberspannung
 * 			Signal RGS_VL_Motorfehler
 * 			Signal RGS_VL_EEPROM_Datensatzfehler
 * 			Signal RGS_VL_Strom
 * 			Signal RGS_VL_Status
 */
EXPORTED void CIL_runAppliToCAN(void)
{
   Dem_EventStatusExtendedType u8FaultStatus;
   Dem_EventStatusExtendedType u8FaultStatus1;
   Dem_EventStatusExtendedType u8FaultStatus2;
   Dem_EventStatusExtendedType u8AecAllBauteil[KU8_TWELVE];
   Dem_EventStatusExtendedType u8AecAllMotor[KU8_FIVE];
   boolean bLocalNewTransitionRequested = B_FALSE;
   uint8 u8InPositionState = B_FALSE;
   uint8 u8TestResult;
   static uint8 u8QualificationCounter = KU8_ZERO;
   static uint8 u8DequalificationCounter = KU8_ZERO;

   /* Signal RGS_VL_Gurtgeschwindigkeit */
   cil_ComputeSignalGurtgeschwindigkeit();

   /* Signal RGS_VL_Gurtbandauszug */
   cil_ComputeSignalGurtbandauszug();

   /* Signal RGS_VL_Status */
   cil_ComputeSignalStatus();

   if(((B_TRUE == CIL_u8NewTransitionRequested) || (KU8_NO_ACTION == CIL_u8ActivationRequest)) &&
      ((cil_u8RGS_Status != KU8_CIL_FEHLERHAFTE_STRAFFDURCHFUEHRUNG) && (cil_u8RGS_Status != KU8_CIL_FEHLERHAFTE_STRAFFANFORDERUNG)))
   {
      bLocalNewTransitionRequested = B_TRUE;
   }

   /* Signal RGS_VL_keineStraffungUnterspg */
   (void)Rte_Call_pclEvtInfoBatPwrUnderVoltageDuringTens_GetEventStatus(&u8FaultStatus);
   if( (KU8_ZERO == cil_u8RGS_keine_Straffung_Unterspg) && (DEM_UDS_STATUS_TF != (DEM_UDS_STATUS_TF & u8FaultStatus)) )
   {
      CIL_bKeineStraffungUnterspgDisqualified = B_TRUE;
   }
   if (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus) )
   {
      cil_u8RGS_keine_Straffung_Unterspg = KU8_ZERO;
      CIL_bKeineStraffungUnterspgInhibited = B_TRUE;
      CIL_bKeineStraffungUnterspgDisqualified = B_FALSE;
      CIL_bKeineStraffungIsSet = B_TRUE;
   }
   /* reset signal only if a valid belt profile request is received */
   else if(B_TRUE == bLocalNewTransitionRequested)
   {
      cil_u8RGS_keine_Straffung_Unterspg = KU8_ONE;
      CIL_bKeineStraffungIsSet = B_FALSE;
   }
   else
   {
      /* do nothing */
   }

   /* Signal RGS_VL_nicht_programmiert */
   (void)Rte_Call_pclEvtInfoNvmNotPrg_GetEventStatus(&u8FaultStatus);
   if (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus) )
   {
      cil_u8RGS_nicht_programmiert = KU8_ZERO;
      CIL_bNichtProgrammiertInhibited = B_TRUE;
   }
   else if(B_TRUE == CIL_u8NewTransitionRequested)
   {
      cil_u8RGS_nicht_programmiert = KU8_ONE;
      CIL_bNichtProgrammiertInhibited = B_FALSE;
   }
   else
   {
      /* do nothing */
   }

   /* Signal RGS_VL_Uebertemperatur_defekt */
   (void)Rte_Call_pclEvtInfoSwSelfProtection_GetEventStatus(&u8FaultStatus);
   (void)Rte_Call_pclEvtInfoHwSelfProtection_GetEventStatus(&u8FaultStatus1);
   if( ( (DEM_UDS_STATUS_TF != (DEM_UDS_STATUS_TF & u8FaultStatus)) ||
         (DEM_UDS_STATUS_TF != (DEM_UDS_STATUS_TF & u8FaultStatus1)) ) &&
         (KU8_ZERO == cil_u8RGS_Uebertemperatur_defekt) )
   {
      CIL_bUeberTemperatureDisqualified = B_TRUE;
   }
   if ((DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus)) ||
       (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus1)) )
   {
      cil_u8RGS_Uebertemperatur_defekt = KU8_ZERO;
      CIL_bUeberTemperatureDisqualified = B_FALSE;
      CIL_bUeberTemperatureInhibited = B_TRUE;
   }
   else if(B_TRUE == bLocalNewTransitionRequested)
   {
      cil_u8RGS_Uebertemperatur_defekt = KU8_ONE;
   }
   else
   {
      /* do nothing */
   }

   /* Signal RGS_VL_Bauteilfehler */
   (void)Rte_Call_pclEvitInfoSpiEHWError_GetEventStatus(&u8AecAllBauteil[KU8_ZERO]);
   (void)Rte_Call_pclEvtInfoAdcOutOfOrder_GetEventStatus(&u8AecAllBauteil[KU8_ONE]);
   (void)Rte_Call_pclEvtInfoExtWdgOutOfOrder_GetEventStatus(&u8AecAllBauteil[KU8_TWO]);
   (void)Rte_Call_pclEvtInfoMosfetHighSC_GetEventStatus(&u8AecAllBauteil[KU8_THREE]);
   (void)Rte_Call_pclEvtInfoMosfetLowSC_GetEventStatus(&u8AecAllBauteil[KU8_FOUR]);
   (void)Rte_Call_pclEvtInfoMosfetOC_GetEventStatus(&u8AecAllBauteil[KU8_FIVE]);
   (void)Rte_Call_pclEvtInfoHallSensor_GetEventStatus(&u8AecAllBauteil[KU8_SIX]);
   (void)Rte_Call_pclEvtInfoEnableOutOfOrder_GetEventStatus(&u8AecAllBauteil[KU8_SEVEN]);
   (void)Rte_Call_pclEvtInfoHighSideSwitch_GetEventStatus(&u8AecAllBauteil[KU8_EIGHT]);
   (void)Rte_Call_pclEvtAdcCalibration_GetEventStatus(&u8AecAllBauteil[KU8_NINE]);
   (void)Rte_Call_pclEvtBatLogImplausible_GetEventStatus(&u8AecAllBauteil[KU8_TEN]);
   /* Verify that at least one AEC is qualified */
   u8FaultStatus = (u8AecAllBauteil[KU8_ZERO]     |
         u8AecAllBauteil[KU8_ONE]                 |
         u8AecAllBauteil[KU8_TWO]                 |
         u8AecAllBauteil[KU8_THREE]               |
         u8AecAllBauteil[KU8_FOUR]                |
         u8AecAllBauteil[KU8_FIVE]                |
         u8AecAllBauteil[KU8_SIX]                 |
         u8AecAllBauteil[KU8_SEVEN]               |
         u8AecAllBauteil[KU8_EIGHT]               |
         u8AecAllBauteil[KU8_NINE]                |
         u8AecAllBauteil[KU8_TEN]
   );
   if (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus) )
   {
      cil_u8Bauteilfehler = KU8_ZERO;
      CIL_bHWErrorPresent = B_TRUE;
   }
   else
   {
      /* do nothing */
   }

   /* not implemented yet Signal RGS_VL_keineStraffungUeberspg */

   /* Signal RGS_VL_Max_Gurtlosezyklen */
   (void)Rte_Call_pclEvtInfoComfortEndOfLife_GetEventStatus(&u8FaultStatus);
   if (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus) )
   {
      cil_u8RGS_Max_Gurtlosezyklen = KU8_ZERO;
   }
   else
   {
      cil_u8RGS_Max_Gurtlosezyklen = KU8_ONE;
   }

   /* Signal RGS_VL_Temp */
   cil_ComputeSignalTemp();

   /* Check critical autotests when antipatina is not done */
   cil_CheckStatusOfCriticalAutotests();

   /* Signal RGS_VL_Unterspannung */
   (void)Rte_Call_pclAutoTestCheckPowerUV_AutotestCallback(&u8TestResult);
   if ((u8TestResult == KU8_ATM_TEST_OK) && ((KU8_ZERO == cil_u8RGS_Unterspannung) && (B_FALSE == CIL_bCriticalAutotestsResponse)))
   {
	   CIL_bUnterspannungDisqualified = B_TRUE;
	   u8DequalificationCounter++;
   }
   if((u8TestResult == KU8_ATM_TEST_NOT_DECIDED) || (u8TestResult == KU8_ATM_TEST_OK))
   {
	   u8QualificationCounter = 0;
   }
   if((u8TestResult == KU8_ATM_TEST_NOT_DECIDED) || (u8TestResult == KU8_ATM_TEST_NOK))
   {
	   u8DequalificationCounter = 0;
   }
   if((u8TestResult == KU8_ATM_TEST_NOK)  && (u8QualificationCounter < KU8_UNTERSPANNUNG_QUALIFICATION_TIME))
   {
	   u8QualificationCounter++;
   }
   if(((u8TestResult == KU8_ATM_TEST_NOK) && (u8QualificationCounter >= KU8_UNTERSPANNUNG_QUALIFICATION_TIME))
		   ||
	  (B_TRUE == CIL_bCriticalAutotestsResponse) )
   {
	   /* Set flag to B_TRUE - use in DIA*/
	   CIL_bUnterSpannungIsSet = B_TRUE;
	   cil_u8RGS_Unterspannung = KU8_ZERO;
	   CIL_bUnterspannungInhibited = B_TRUE;
	   CIL_bUnterspannungDisqualified = B_FALSE;
   }
   else if ((B_TRUE == bLocalNewTransitionRequested) && (u8DequalificationCounter >= KU8_UNTERSPANNUNG_DEQUALIFICATION_TIME))
   {
	   /* Set flag to B_FALSE - use in DIA*/
	   CIL_bUnterSpannungIsSet = B_FALSE;
	   cil_u8RGS_Unterspannung = KU8_ONE;
   }
   else
   {
	   /* nothing to do */
   }

   /* Signal RGS_VL_Max_Straffzyklenfehler */
   (void)Rte_Call_pclEvtInfoLowForceEndOfLife_GetEventStatus(&u8FaultStatus);
   if (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus) )
   {
      cil_u8RGS_Max_Straffzyklenfehler = KU8_ZERO;
   }
   else
   {
      cil_u8RGS_Max_Straffzyklenfehler = KU8_ONE;
   }

   /* Signal RGS_VL_Max_NGU_Zyklenfehler */
   (void)Rte_Call_pclEvtInfoHighForceEndOfLife_GetEventStatus(&u8FaultStatus);
   if (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus) )
   {
      cil_u8RGS_VL_Max_NGU_Zyklenfehler = KU8_ZERO;
   }
   else
   {
      cil_u8RGS_VL_Max_NGU_Zyklenfehler = KU8_ONE;
   }

   /* Signal RGS_VL_Max_Haptikzyklenfehler */
   (void)Rte_Call_pclEvtInfoHapticWarningEndOfLife_GetEventStatus(&u8FaultStatus);
   if (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus) )
   {
      cil_u8RGS_Max_Haptikzyklenfehler = KU8_ZERO;
   }
   else
   {
      cil_u8RGS_Max_Haptikzyklenfehler = KU8_ONE;
   }

   /* Signal RGS_VL_Crashabschaltung */
   if ( CIL_bAbortRequested == B_TRUE )
   {
      cil_u8Crashabschaltung = KU8_ZERO;
   }
   else
   {
      /* Nothing to do */
   }


   /* Signal RGS_VL_Ueberspannung */
   (void)Rte_Call_pclEventInfoBatPwrOverVoltage_GetEventStatus(&u8FaultStatus1);
   (void)Rte_Call_pclEventInfoBatLogOverVoltage_GetEventStatus(&u8FaultStatus2);
   if( ( (DEM_UDS_STATUS_TF != (DEM_UDS_STATUS_TF & u8FaultStatus1)) ||
         (DEM_UDS_STATUS_TF != (DEM_UDS_STATUS_TF & u8FaultStatus2)) ) &&
         (KU8_ZERO == cil_u8RGS_Ueberspannung) )
   {
      CIL_bUeberSpannungDisqualified = B_TRUE;
   }
   if ( (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus1)) ||
        (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus2)) )
   {
      /* Set flag to B_TRUE - use in DIA */
      CIL_bUeberSpannungIsSet = B_TRUE;
      cil_u8RGS_Ueberspannung = KU8_ZERO;
      CIL_bUeberSpannungInhibited = B_TRUE;
      CIL_bUeberSpannungDisqualified = B_FALSE;
   }
   else if(B_TRUE == bLocalNewTransitionRequested)
   {
      /* Set flag to B_FALSE - use in DIA */
      CIL_bUeberSpannungIsSet = B_FALSE;
      cil_u8RGS_Ueberspannung = KU8_ONE;
   }
   else
   {
      /* nothing to do */
   }

   /* Signal RGS_VL_Motorfehler */
   (void)Rte_Call_pclEvtInfoMotorDisconnected_GetEventStatus(&u8AecAllMotor[KU8_ZERO]);
   (void)Rte_Call_pclEvtInfoMotorOrder_GetEventStatus(&u8AecAllMotor[KU8_ONE]);
   (void)Rte_Call_pclEvtInfoMotorCurrent_GetEventStatus(&u8AecAllMotor[KU8_TWO]);
   (void)Rte_Call_pclEvtInfoMotorInSC_GetEventStatus(&u8AecAllMotor[KU8_THREE]);
   (void)Rte_Call_pclEvtInfoMotorBlocked_GetEventStatus(&u8AecAllMotor[KU8_FOUR]);
   /* Verify that at least one AEC is qualified */
   u8FaultStatus = (u8AecAllMotor[KU8_ZERO]     |
         u8AecAllMotor[KU8_ONE]                 |
         u8AecAllMotor[KU8_TWO]                 |
         u8AecAllMotor[KU8_THREE]               |
         u8AecAllMotor[KU8_FOUR] );
   if( (KU8_ZERO == cil_u8RGS_Motorfehler) && (DEM_UDS_STATUS_TF != (DEM_UDS_STATUS_TF & u8FaultStatus)) )
   {
      CIL_bMotorfehlerDisqualified = B_TRUE;
   }
   if( DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus) )
   {
      cil_u8RGS_Motorfehler = KU8_ZERO;
      CIL_bMotorfehlerInhibited = B_TRUE;
      CIL_bMotorfehlerDisqualified = B_FALSE;
   }
   else if(B_TRUE == bLocalNewTransitionRequested)
   {
      cil_u8RGS_Motorfehler = KU8_ONE;
   }
   else
   {
      /* nothing to do */
   }

   /* Signal RGS_VL_EEPROM_RAM_ROM_Fehler */
   (void)Rte_Call_pclEventInfoFlsECC_GetEventStatus(&u8FaultStatus);
   (void)Rte_Call_pclEventInfoRamECC_GetEventStatus(&u8FaultStatus1);
   if( (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus) )
         ||
         (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultStatus1)) )
   {
      cil_u8EEPROM_RAM_ROM_Fehler = KU8_ZERO;
   }
   else
   {
      cil_u8EEPROM_RAM_ROM_Fehler = KU8_ONE;
   }

   /* Signal RGS_VL_Strom */
   cil_ComputeSignalStrom();

   if(KU8_ZERO != cil_u8RGS_Strom)
   {
      (void)Rte_Write_SP_IF_RGS_VL_Strom_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Strom(cil_u8RGS_Strom);
      CIL_b8RGS_StromIsSet = B_FALSE;
   }
   else
   {
      if(B_FALSE == CIL_b8RGS_StromIsSet)
      {
         (void)Rte_Write_SP_IF_RGS_VL_Strom_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Strom(cil_u8RGS_Strom);
         CIL_b8RGS_StromIsSet = B_TRUE;
      }
   }

   if(KU8_ZERO == cil_u8RGS_VL_Max_NGU_Zyklenfehler)
   {
      (void)Rte_Write_SP_IF_RGS_VL_Max_NGU_Zyklenfehler_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Max_NGU_Zyklenfehler(cil_u8RGS_VL_Max_NGU_Zyklenfehler);
      CIL_b8RGS_Max_NGU_ZyklenfehlerIsSet = B_FALSE;
   }
   else
   {
      if(B_FALSE == CIL_b8RGS_Max_NGU_ZyklenfehlerIsSet)
      {
         (void)Rte_Write_SP_IF_RGS_VL_Max_NGU_Zyklenfehler_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Max_NGU_Zyklenfehler(cil_u8RGS_VL_Max_NGU_Zyklenfehler);
         CIL_b8RGS_Max_NGU_ZyklenfehlerIsSet = B_TRUE;
      }
   }

   if(KU8_ZERO == cil_u8Max_P2P_Zyklenfehler)
   {
      (void)Rte_Write_SP_IF_RGS_VL_Max_P2P_Zyklenfehler_ASG_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Max_P2P_Zyklenfehler(cil_u8Max_P2P_Zyklenfehler);
      CIL_b8RGS_Max_P2P_ZyklenfehlerIsSet = B_FALSE;
   }
   else
   {
      if(B_FALSE == CIL_b8RGS_Max_P2P_ZyklenfehlerIsSet)
      {
         (void)Rte_Write_SP_IF_RGS_VL_Max_P2P_Zyklenfehler_ASG_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Max_P2P_Zyklenfehler(cil_u8Max_P2P_Zyklenfehler);
         CIL_b8RGS_Max_P2P_ZyklenfehlerIsSet = B_TRUE;
      }
   }

   if(KU8_ZERO == cil_u8EEPROM_RAM_ROM_Fehler)
   {
      (void)Rte_Write_SP_IF_RGS_VL_EEPROM_RAM_ROM_Fehler_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_EEPROM_RAM_ROM_Fehler(cil_u8EEPROM_RAM_ROM_Fehler);
      CIL_b8RGS_EEPROM_RAM_ROM_FehlerIsSet = B_FALSE;
   }
   else
   {
      if(B_FALSE == CIL_b8RGS_EEPROM_RAM_ROM_FehlerIsSet)
      {
         (void)Rte_Write_SP_IF_RGS_VL_EEPROM_RAM_ROM_Fehler_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_EEPROM_RAM_ROM_Fehler(cil_u8EEPROM_RAM_ROM_Fehler);
         CIL_b8RGS_EEPROM_RAM_ROM_FehlerIsSet = B_TRUE;
      }
   }

   /* signal RGS_VL_InPos */
   Rte_Call_prrInPositionState_GetInPositionState(&u8InPositionState);
   if (u8InPositionState == KU8_ONE)
   {
      cil_u8InPos = KU8_ONE;
   }
   else
   {
      cil_u8InPos = KU8_ZERO;
   }

   (void)Rte_Write_SP_IF_RGS_VL_Gurtgeschwindigkeit_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Gurtgeschwindigkeit(cil_u16Gurtgeschwindigkeit);
   (void)Rte_Write_SP_IF_RGS_VL_Gurtbandauszug_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Gurtbandauszug(cil_u16Gurtbandauszug);
   (void)Rte_Write_SP_IF_RGS_VL_keine_Straffung_Unterspg_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_keineStraffungUnterspg(cil_u8RGS_keine_Straffung_Unterspg);
   (void)Rte_Write_SP_IF_RGS_VL_nicht_programmiert_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_nicht_programmiert(cil_u8RGS_nicht_programmiert);
   (void)Rte_Write_SP_IF_RGS_VL_Uebertemperatur_defekt_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Uebertemperatur_defekt(cil_u8RGS_Uebertemperatur_defekt);
   (void)Rte_Write_SP_IF_RGS_VL_Bauteilfehler_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Bauteilfehler(cil_u8Bauteilfehler);
   (void)Rte_Write_SP_IF_RGS_VL_keine_Straffung_Ueberspg_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_keineStraffungUeberspg(cil_u8RGS_keine_Straffung_Ueberspg);
   (void)Rte_Write_SP_IF_RGS_VL_Max_Gurtlosezyklen_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Max_Gurtlosezyklen(cil_u8RGS_Max_Gurtlosezyklen);
   (void)Rte_Write_SP_IF_RGS_VL_Temp_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Temp(cil_u8RGS_Temp);
   (void)Rte_Write_SP_IF_RGS_VL_Unterspannung_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Unterspannung(cil_u8RGS_Unterspannung);
   (void)Rte_Write_SP_IF_RGS_VL_Max_Straffzyklenfehler_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Max_Straffzyklenfehler(cil_u8RGS_Max_Straffzyklenfehler);
   (void)Rte_Write_SP_IF_RGS_VL_Max_Haptikzyklenfehler_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Max_Haptikzyklenfehler(cil_u8RGS_Max_Haptikzyklenfehler);
   (void)Rte_Write_SP_IF_RGS_VL_Crashabschaltung_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Crashabschaltung(cil_u8Crashabschaltung);
   (void)Rte_Write_SP_IF_RGS_VL_Ueberspannung_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Ueberspannung(cil_u8RGS_Ueberspannung);
   (void)Rte_Write_SP_IF_RGS_VL_Motorfehler_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Motorfehler(cil_u8RGS_Motorfehler);
   (void)Rte_Write_SP_IF_RGS_VL_InPos_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_InPos(cil_u8InPos);
   (void)Rte_Write_SP_IF_RGS_VL_Status_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Status(cil_u8RGS_Status);

   if (B_TRUE == CIL_u8NewTransitionRequested)
   {
      CIL_u8NewTransitionRequested = B_FALSE;
      bLocalNewTransitionRequested = B_FALSE;
   }
   else
   {
      /* nothing to do */
   }
}
/* QAC_WARNING S 3417 ++ */ /* QAC warning due to comma operator into RTE macro */
/* QAC_WARNING S 3426 ++ */ /* QAC does not recognize RTE macros */


/**
 * \brief
 *		This is the Timeout_RGS_Anf_01 autotest. It consists of checking that the RGS_Anf_01 frame
 * \param[in,out] pu8TestResult
 * \return
 * 		The test result
 * \retval	uint8 KU8_ATM_TEST_OK
 * \retval	uint8 KU8_ATM_TEST_NOK
 * \retval	uint8 KU8_ATM_TEST_NOT_DECIDED
 */
void CIL_Autotest_CheckTimeout_RGS_Anf_01 (P2VAR(u8TestResultType, AUTOMATIC, RTE_APPL_DATA) pu8TestResult)
{

   /* Returned status */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* If the two calibration are OK */
   if (CIL_TimeoutReceived != B_TRUE)
   {

      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }
   /*If one of them is NOK */
   else
   {
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;

   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}


#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/* QAC_WARNING S 3417 -- */ /* QAC warning due to comma operator into RTE macro */
/* QAC_WARNING S 3426 -- */ /* QAC does not recognize RTE macros */

/*************************************************************************
Evolution of the component

Created by : F.GILBERT

$Log: CIL_AppliToCAN.c  $
Revision 1.1 2021/10/04 07:14:25CEST Lucian Ardeleanu (lucian.ardeleanu) 
Initial revision
Member added to project e:/MKSProjects/SBE/Exploration/Python_Workspace/Automate_line_number_script/Executables/source_files/project.pj
Revision 1.1.1.10.2.122 2021/08/02 13:44:15EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Add treaceability
Revision 1.1.1.10.2.121 2021/07/29 14:23:54EEST Anca Vulpe (anca.vulpe) 
Update Did 23e0 and 23e8
Revision 1.1.1.10.2.120 2021/07/20 12:43:20EEST Anca Vulpe (anca.vulpe) 
Add qualification time for unterspannung
Revision 1.1.1.10.2.119 2021/07/16 15:40:35EEST Anca Vulpe (anca.vulpe) 
Update untersparnnung signal
Revision 1.1.1.10.2.118 2021/07/14 18:32:55EEST Andreea Negrea (andreea.negrea) 
Fix QAC warnings
Revision 1.1.1.10.2.117 2021/07/14 17:34:14EEST Andreea Negrea (andreea.negrea) 
Update CIL init for localRgsStatus when response is computed to 0x00
Revision 1.1.1.10.2.116 2021/07/08 12:40:40EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Fix QAC errors
Revision 1.1.1.10.2.115 2021/07/05 16:10:32EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Add new conditions for start up cycle (init phase)
Revision 1.1.1.10.2.114 2021/06/24 17:00:08EEST Anca Vulpe (anca.vulpe) 
Add RamECC error
Revision 1.1.1.10.2.113 2021/06/17 14:26:46EEST Marius Chiriac (marius.chiriac1) 
Com callbacks functions have been moved to CIL_CANToAppli.c file
Revision 1.1.1.10.2.112 2021/06/16 15:42:22EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
remove unused variable
Revision 1.1.1.10.2.111 2021/06/16 15:32:20EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Rework cil_ComputeSignalTemp function
Revision 1.1.1.10.2.110 2021/06/16 10:33:39EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Removing additional conditions for the RGS_VL_Temp signal
Revision 1.1.1.10.2.109 2021/06/14 16:03:31EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Add fix for RGS_VL_Temp signal
Revision 1.1.1.10.2.108 2021/06/07 16:33:16EEST Andreea Negrea (andreea.negrea) 
Update signals with removed errors
Revision 1.1.1.10.2.107 2021/05/25 17:46:05EEST Andreea Negrea (andreea.negrea) 
Add two new tensioning cycles
Revision 1.1.1.10.2.106 2021/05/06 12:38:40EEST Anca Vulpe (anca.vulpe) 
Add condition for HRD over tens
Revision 1.1.1.10.2.105 2021/04/22 11:40:44EEST Andreea Negrea (andreea.negrea) 
Add HWA inhibitted new conditions in CANToAppli and remove the old ones fron AppliToCAN
Revision 1.1.1.10.2.104 2021/04/19 11:04:26EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Add condition that not inhibit profiles if the errors not exist
Revision 1.1.1.10.2.103 2021/04/07 14:24:06EEST Anca Vulpe (anca.vulpe) 
Add condition for HRD over tens
Revision 1.1.1.10.2.102 2021/04/01 11:29:14EEST Andreea Negrea (andreea.negrea) 
Add fix after review
Revision 1.1.1.10.2.101 2021/03/25 12:01:27EET Andreea Negrea (andreea.negrea) 
Merge HWA response with HRD response in case of abortion
Revision 1.1.1.10.2.100 2021/03/10 16:09:47EET Andreea Negrea (andreea.negrea) 
Fix QAC error
Revision 1.1.1.10.2.99 2021/03/10 14:55:50EET Andreea Negrea (andreea.negrea) 
Implementation of 0x1E*10 in case of BSR, HWA and HRD abortion
Revision 1.1.1.10.2.98 2021/01/29 09:08:08EET Andreea Negrea (andreea.negrea) 
Remove NA requirements
Revision 1.1.1.10.2.97 2021/01/14 12:44:58EET Andreea Negrea (andreea.negrea) 
Update doc
Revision 1.1.1.10.2.96 2020/12/15 16:50:42EET Dan Dustinta (dan.dustinta) 
update RGSNichtProgrammiert inhibition
Revision 1.1.1.10.2.95 2020/12/15 12:45:23EET Dan Dustinta (dan.dustinta) 
remove error from Bauteilfehler
Revision 1.1.1.10.2.94 2020/12/11 15:03:43EET Andreea Negrea (andreea.negrea) 
Update RawActivation value
Revision 1.1.1.10.2.93 2020/12/10 16:19:14EET Andreea Negrea (andreea.negrea) 
Signal RGS_VL_Max_P2P_Zyklenfehler always set to 1
Revision 1.1.1.10.2.92 2020/12/09 09:28:12EET Andreea Negrea (andreea.negrea) 
Update HRD response
Revision 1.1.1.10.2.91 2020/12/03 17:57:49EET Andreea Negrea (andreea.negrea) 
Update Interrupt flags
Revision 1.1.1.10.2.90 2020/11/26 11:47:02EET Gheorghita Brasoveanu (gheorghita.brasovean) 
Fix RGS_VL signals conditions
Revision 1.1.1.10.2.89 2020/11/23 14:28:43EET Dan Dustinta (dan.dustinta) 
fix findings from PRWB
Revision 1.1.1.10.2.88 2020/11/19 15:07:51EET Gheorghita Brasoveanu (gheorghita.brasovean) 
Fix RGS_VL inhibition conditions
Revision 1.1.1.10.2.87 2020/11/18 17:42:31EET Andreea Negrea (andreea.negrea) 
Fix response when Release is not allowed, activation request is no action and tensioning is aborted
Revision 1.1.1.10.2.86 2020/11/16 09:31:34EET Andreea Negrea (andreea.negrea) 
Last tensioning is now Presafe 23 , inseated of Presafe7
Revision 1.1.1.10.2.85 2020/11/05 13:00:19EET Mirela Obada (mirela.obada) 
Update code after QAC
Revision 1.1.1.10.2.84 2020/11/04 09:03:08EET Anca Vulpe (anca.vulpe) 
Add RTE interface
Revision 1.1.1.10.2.83 2020/11/03 11:34:49EET Gheorghita Brasoveanu (gheorghita.brasovean) 
Update variables name
Revision 1.1.1.10.2.82 2020/10/30 15:59:16EET Andreea Negrea (andreea.negrea) 
Extend profile limit to 38 and add new 40 steps
Revision 1.1.1.10.2.81 2020/10/30 13:38:39EET Anca Vulpe (anca.vulpe) 
Update InPosition
Revision 1.1.1.10.2.80 2020/10/30 12:47:03EET Gheorghita Brasoveanu (gheorghita.brasovean) 
Update conditions for inhibition RGS_VL signals
Revision 1.1.1.10.2.79 2020/10/30 11:41:18EET Dan Dustinta (dan.dustinta) 
update response handling for init phase
Revision 1.1.1.10.2.78 2020/10/28 11:29:38EET Dan Dustinta (dan.dustinta) 
update response handling
Revision 1.1.1.10.2.77 2020/10/22 08:51:40EEST Marius Chiriac (marius.chiriac1) 
Integrate EcuExtract_V12.03.35.01F_P11_AR430_20201007
Revision 1.1.1.10.2.76 2020/10/20 15:54:32EEST Dan Dustinta (dan.dustinta) 
fix wrong logic
Revision 1.1.1.10.2.75 2020/10/16 14:25:56EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Update condition from cil_ComputeSignalStatus in case of INCORRECT_TENSIONING_EXECUTION_INHIBITION
Revision 1.1.1.10.2.74 2020/10/16 09:26:59EEST Dan Dustinta (dan.dustinta) 
ignore BFD in case of HRD/HWA/BPA
Revision 1.1.1.10.2.73 2020/10/16 09:26:07EEST Dan Dustinta (dan.dustinta) 
rework error bits
Revision 1.1.1.10.2.72 2020/10/14 12:38:31EEST Dan Dustinta (dan.dustinta) 
fix response for diag triggered cycles
Revision 1.1.1.10.2.71 2020/10/13 09:55:35EEST Andreea Negrea (andreea.negrea) 
Move init handle response from BFD to CIL
Revision 1.1.1.10.2.70 2020/10/07 14:45:50EEST Anca Vulpe (anca.vulpe) 
Update Straffzyklenfehler signal
Revision 1.1.1.10.2.69 2020/10/02 16:36:56EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
RGS_VL/VL_Status Signal correction
Revision 1.1.1.10.2.68 2020/09/30 21:53:08EEST Anca Vulpe (anca.vulpe) 
Set "RGS_xx_Motorfehler"  to "Error not active" when NO_ACTION is req.
Revision 1.1.1.10.2.67 2020/09/24 14:18:56EEST Andreea Negrea (andreea.negrea) 
Update HWA manage repetition function
Revision 1.1.1.10.2.66 2020/09/21 13:51:04EEST Andreea Negrea (andreea.negrea) 
Update cycle response in case of Bauteilfehler active
Revision 1.1.1.10.2.65 2020/09/18 12:34:02EEST Andreea Negrea (andreea.negrea) 
Update response for HWA/BPx/BSR/HRD
Revision 1.1.1.10.2.64 2020/09/11 12:48:29EEST Dan Dustinta (dan.dustinta) 
update according to QAC
Revision 1.1.1.10.2.63 2020/09/10 10:57:34EEST Mirela Obada (mirela.obada) 
[TR6][SRC] Update CIL findings Peer Review
Revision 1.1.1.10.2.62 2020/09/07 16:20:29EEST Dan Nitulescu (dan.nitulescu) 
RGS_VL/VR_Temp SIgnal correction
Revision 1.1.1.10.2.61 2020/09/07 15:12:45EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Condition to send strom signal only once
Revision 1.1.1.10.2.60 2020/09/07 13:22:07EEST Dan Nitulescu (dan.nitulescu) 
RGS_VL/VR_Temp SIgnal correction
Revision 1.1.1.10.2.59 2020/09/07 11:47:45EEST Dan Nitulescu (dan.nitulescu) 
RGS_VL/VR_Temp Signal correction
Revision 1.1.1.10.2.58 2020/09/02 10:13:10EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Removing unused conditions from the cil_ComputeSignalStatus function
Revision 1.1.1.10.2.57 2020/08/31 11:25:56EEST Dan Dustinta (dan.dustinta) 
update beltstack for infnite hard release issue
Revision 1.1.1.10.2.56 2020/08/12 10:31:43EEST Mirela Obada (mirela.obada) 
Update traceabilty
Revision 1.1.1.10.2.55 2020/08/11 16:06:05EEST Mirela Obada (mirela.obada) 
Update comments and traceabilty.
Revision 1.1.1.10.2.54 2020/07/21 13:44:38EEST Andreea Negrea (andreea.negrea) 
Modify BSR response
Revision 1.1.1.10.2.53 2020/07/09 17:39:34EEST Andreea Negrea (andreea.negrea) 
Fix Bauteilfehler inhibition for cycles
Revision 1.1.1.10.2.52 2020/07/09 10:06:16EEST Andreea Negrea (andreea.negrea) 
Fix BPA response
Revision 1.1.1.10.2.51 2020/07/08 16:44:28EEST Andreea Negrea (andreea.negrea) 
Fix HRD to be executed only one time
Revision 1.1.1.10.2.50 2020/07/08 11:22:28EEST Anca Vulpe (anca.vulpe) 
Add RGS_VL_Max_NGU_Zyklenfehler signa;
Revision 1.1.1.10.2.49 2020/07/07 14:16:30EEST Anca Vulpe (anca.vulpe) 
Add requirement for traceability
Revision 1.1.1.10.2.48 2020/07/07 13:16:53EEST Anca Vulpe (anca.vulpe) 
Change RGS_VL_Bauteilfehler
Revision 1.1.1.10.2.47 2020/07/06 23:39:28EEST Anca Vulpe (anca.vulpe) 
Remove unused variable
Revision 1.1.1.10.2.46 2020/07/06 09:31:02EEST Anca Vulpe (anca.vulpe) 
Add new conditions
Revision 1.1.1.10.2.45 2020/07/03 14:27:43EEST Andreea Negrea (andreea.negrea) 
Update release allowed algo for HWA BSR and BPDC
Revision 1.1.1.10.2.44 2020/06/30 17:06:05EEST Anca Vulpe (anca.vulpe) 
Add new condition
Revision 1.1.1.10.2.43 2020/06/26 11:14:44EEST Andreea Negrea (andreea.negrea) 
FIX HRD after abortion
Revision 1.1.1.10.2.42 2020/06/16 16:57:29EEST Andreea Negrea (andreea.negrea) 
Update HWA cycle map
Revision 1.1.1.10.2.41 2020/06/11 08:43:58EEST Anca Vulpe (anca.vulpe) 
QAC fix
Revision 1.1.1.10.2.40 2020/06/05 17:52:07EEST Anca Vulpe (anca.vulpe) 
Add new conditions
Revision 1.1.1.10.2.39 2020/06/05 16:14:30EEST Anca Vulpe (anca.vulpe) 
Add new conditions
Revision 1.1.1.10.2.38 2020/06/05 14:14:53EEST Andreea Negrea (andreea.negrea) 
Add interface for last interrupt cycle
Add hrd after aborted cycle
Update cycle enable
Revision 1.1.1.10.2.37 2020/06/05 02:36:08EEST Andreea Negrea (andreea.negrea) 
Add algo and interfaces for release allowed and cycle enable
Revision 1.1.1.10.2.36 2020/06/03 09:12:58EEST Andreea Negrea (andreea.negrea) 
Add HRD response
Revision 1.1.1.10.2.35 2020/06/02 15:43:27EEST Andreea Negrea (andreea.negrea) 
Update cycles map for P20.
Revision 1.1.1.10.2.34 2020/06/02 08:44:42EEST Andreea Negrea (andreea.negrea) 
Add SFR component
Revision 1.1.1.10.2.33 2020/05/29 14:33:27EEST Anca Vulpe (anca.vulpe) 
Gurtgeschwindigkeit error
Revision 1.1.1.10.2.32 2020/05/29 10:17:49EEST Marius Chiriac (marius.chiriac1) 
Add ERR_RGS_ANF01_TIMEOUT Autotest
Revision 1.1.1.10.2.31 2020/05/20 14:25:31EEST Anca Vulpe (anca.vulpe) 
Add traceability
Revision 1.1.1.10.2.30 2020/05/15 13:41:09EEST Dan Nitulescu (dan.nitulescu) 
source files for DIDs 23E0-23EF and 23F0-23F1
Revision 1.1.1.10.2.29 2020/05/11 17:19:37EEST Andreea Negrea (andreea.negrea) 
Fix BPA Status frame response when incorrect tensioning should be transmitted
Revision 1.1.1.10.2.28 2020/05/08 16:06:37EEST Anca Vulpe (anca.vulpe) 
RGS_xx_Gurtgeschwindigkeit: Wrong physical values received.
Revision 1.1.1.10.2.27 2020/05/08 14:39:15EEST Andreea Negrea (andreea.negrea) 
Add changes to :
-set Incoreect tensioning execution when haptik is inhibitted or aborted 
-not start HWA if a fault is deskilling until a new request is sent
-not start HWA counter until init phase is over
Revision 1.1.1.10.2.26 2020/05/08 10:59:32EEST Anca Vulpe (anca.vulpe) 
Status signal during INIT
Revision 1.1.1.10.2.25 2020/04/07 14:01:47EEST Andreea Negrea (andreea.negrea) 
Update traceability
Revision 1.1.1.10.2.24 2020/03/26 17:48:42EET Andreea Negrea (andreea.negrea) 
Traceability updated
Revision 1.1.1.10.2.23 2020/03/17 14:59:31EET Andreea Negrea (andreea.negrea) 
Update CIL treaceability
Revision 1.1.1.10.2.22 2020/02/26 17:59:32EET Andreea Negrea (andreea.negrea) 
Fixed after review
Revision 1.1.1.10.2.21 2020/02/25 09:24:18EET Andreea Negrea (andreea.negrea) 
Update CIL_CantoAppli to handle init value
Revision 1.1.1.10.2.20 2020/02/18 16:59:09EET Andreea Negrea (andreea.negrea) 
CIL update to meet Coding Guidelines
Revision 1.1.1.10.2.19 2020/02/10 16:54:28EET Andreea Negrea (andreea.negrea) 
CIL update to reset flag for IncorrectTensioningExecution
Revision 1.1.1.10.2.18 2020/01/29 11:05:14EET Andreea Negrea (andreea.negrea) 
Com callbacks for frame RGS_Anf_01 are renamed
Revision 1.1.1.10.2.17 2020/01/28 14:13:37EET Andreea Negrea (andreea.negrea) 
Formula and offset for signal RGS_XX_Gurtbandauszug updated
Revision 1.1.1.10.2.16 2020/01/28 12:29:43EET Andreea Negrea (andreea.negrea) 
Formula and offset for Signal RGS_XX_Gurtgeschwindigkeit updated
Revision 1.1.1.10.2.15 2019/12/17 12:32:11EET Andreea Negrea (andreea.negrea) 
Update traceability with TF_B requirements
Revision 1.1.1.10.2.14 2019/12/16 13:05:33EET Andreea Negrea (andreea.negrea) 
Update traceability
Revision 1.1.1.10.2.13 2019/11/22 15:03:54EET Andreea Negrea (andreea.negrea) 
Add CIL design documentation and DES requirements treaceability.
Revision 1.1.1.10.2.12 2019/11/13 13:05:33EET Andreea Negrea (andreea.negrea) 
BPDC should be Gurtparken 1 and BPDO should be Gurtparking2
Revision 1.1.1.10.2.11 2019/11/05 17:37:49EET Andreea Negrea (andreea.negrea) 
CIL modification after QAC run
Revision 1.1.1.10.2.10 2019/10/28 10:49:22EET Andreea Negrea (andreea.negrea) 
Add HWA to last 5s for Audi or 2 s for Proche
Revision 1.1.1.10.2.9 2019/10/21 13:29:10EEST Andreea Negrea (andreea.negrea) 
RGS_Anf_01 timeout error implementation. When timout is received no request should be send to BFD.
Revision 1.1.1.10.2.7 2019/10/15 13:21:12EEST Andreea Negrea (andreea.negrea) 
BPA Algo implementation
Revision 1.1.1.10.2.6 2019/10/10 13:54:34EEST Andreea Negrea (andreea.negrea) 
Manage response in CIL when Incorrect tensioning command should be transmitted.
Revision 1.1.1.10.2.5 2019/10/10 10:59:23EEST Andreea Negrea (andreea.negrea) 
Add response for belt Activation
Revision 1.1.1.10.2.4 2019/10/10 10:19:08EEST Andreea Negrea (andreea.negrea) 
Consider Tensioning NGU to be Cycle Presafe 7 because NGU is the tensioning with the higher force.
Revision 1.1.1.10.2.3 2019/10/04 14:18:20EEST Andreea Negrea (andreea.negrea) 
Add HWA implementation to manage request and response correctly.
Revision 1.1.1.10.2.2 2019/09/23 09:59:28EEST Andreea Negrea (andreea.negrea) 
Implementation of CIL
Revision 1.1.1.10.2.1 2019/09/09 15:43:16EEST Andreea Negrea (andreea.negrea) 
CIL Stubs for integration audi system extract
Revision 1.1.1.10 2018/09/04 18:28:58EEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
Create a 5ms event for MF runnable + create a new task to trigger the runnable
Revision 1.1.1.9 2018/06/20 11:17:07CEST Maxime Bourdon (maxime.bourdon) 
Remove RoE sending when Clear fault
Revision 1.1.1.8 2018/03/30 16:50:11CEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
New RoE frame triggered on DTC event change
 - BSWM module added in architecture (Connexion between CIL and BSWM)
 - Connexion between CIL and DEM to be notified when an event status change
Revision 1.1.1.7 2017/05/30 13:47:05CEST Charlene Dibourg (charlene.dibourg) 
Stub the ESM status bit in the status frame
Revision 1.1.1.6 2017/05/09 15:00:01CEST Irina Caragea (irina.caragea) 
Update and reactivate disabled code (after ERH removal)
Revision 1.1.1.5 2017/04/27 15:22:03EEST Irina Caragea (irina.caragea) 
SNI(Source Node Identifier) signal needs to be managed and enabled by CanNm and can not be treated as NM/ComNm user data
Revision 1.1.1.4 2017/04/19 10:49:43EEST Maxime Bourdon (maxime.bourdon) 
ERH connexions stubed until the architecture is ready
Revision 1.1.1.3 2017/04/13 15:40:59CEST Irina Caragea (irina.caragea) 
CIL integration
Revision 1.1.1.2 2017/02/24 10:47:33EET Michael Pastor (michael.pastor) 
MAJ PP4G R3.1E from Explo since 15/02/2017
Revision 1.3 2017/02/23 11:04:43CET Sabine Flechelle (sabine.flechelle) 
Use expected RTE CAN defines
Revision 1.2 2017/02/21 18:14:31CET Sabine Flechelle (sabine.flechelle) 
To correct compilation errors
Revision 1.1 2016/10/05 18:26:12CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Extended/PP4G_R31E/Components/Application/CIL/Implementation/src/project.pj
Revision 1.1 2016/10/05 18:26:12CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/PP4G_Extended/Components/Application/CIL/Implementation/src/project.pj
Revision 1.1 2016/10/05 10:12:58CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Components/Application/CIL/Implementation/src/project.pj
Revision 1.1 2016/09/20 09:48:06CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Automation/PropagationProject_R3.0M/PP4G/Platform_Mainstream_Phase_01/Core/Components/Application/CIL/Implementation/src/src.pj
Revision 1.14 2016/09/05 10:39:21CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove P R Q A
Revision 1.13 2016/09/05 10:28:07CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove P R Q A
Replace by P R Q A in comments
Revision 1.12 2016/09/05 10:02:23CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove all P R Q As
P R Q A is replaced by QAC_WARNING
Revision 1.11 2016/08/24 15:03:13CEST Nicolas Bianchi (nicolas.bianchi) 
Correction of smooth status on temperature sensor failure is qualified
Revision 1.10 2016/08/19 18:20:59CEST Maxime Bourdon (maxime.bourdon) 
AEC configurator tool integration
Revision 1.9 2016/08/17 18:06:13CEST Charlene Dibourg (charlene.dibourg) 
Issue 401921 - CAN configuration for AEC Groups
Revision 1.8 2016/08/10 17:40:19CEST Charlene Dibourg (charlene.dibourg) 
R3.0 Issue 415780 from R2.3 400012 - SIG_ECU_XX_STATUS signal improvement
Revision 1.7 2016/08/09 16:48:57CEST Charlene Dibourg (charlene.dibourg) 
Integration of R2.3 Issue 415771  - [R3.0M] [PP4G] SIG_ECU_XX_STATUS improvement
Revision 1.6 2016/08/08 18:45:11CEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
Integration of R2.3 issue 400376 - Cycle status in ERR status frames
Revision 1.5 2016/07/28 18:42:36CEST Audrey Vache (audrey.vache) 
Integration of issue 356756
Revision 1.4 2016/06/07 12:52:12CEST Audrey Vache (avache) 
Memory mapping implementation
Revision 1.3 2015/11/06 14:11:20CET Maxime Bourdon (mbourdon) 
Pass ATM Autotests calls through RTE + includes clean up
Revision 1.2 2015/11/03 10:21:40CET Maxime Bourdon (mbourdon) 
RTE files inclusion clean up
Revision 1.1 2015/10/13 15:52:55CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/_CIL/src/project.pj
Revision 1.11 2015/08/19 15:09:19CEST Sabine Flechelle (sflechelle) 
Issue 215817 - QAC corrections
Revision 1.10 2015/04/24 17:43:43CEST Sebastien Claveau (sclaveau) 
Add CRC + Message Counter support in TX status frame
Revision 1.9 2015/02/13 17:53:49CET Sebastien Claveau (sclaveau) 
Fix wrong RTE macro execution
Revision 1.8 2015/02/12 15:08:55CET Sebastien Claveau (sclaveau) 
Add AEC groups status in status frame & rework ERH (add groups, simplify...)
Revision 1.7 2015/01/30 16:19:26CET Sebastien Claveau (sclaveau) 
Set the transmited ECU status (status frame)
Revision 1.6 2014/09/08 15:20:40CEST Sebastien Claveau (sclaveau) 
Remove second argument of BMM_runGetPyroActivationStatus.
Revision 1.5 2014/07/07 18:04:05CEST Sabine Flechelle (sflechelle) 
Issue_160956 - BFE eCPL
BFE_TestHarness.mdl rev 1.16
Archi updates:
- create new runnable BFE _ run ResetMotorStageStatus
  used by TIM as client port
- add boolean b8EcplReactivationDelayMngt input to BRS _ runGetPyroActivationStatus 
  to enable or not counting latch of 2s after pyro detection
- new client port in MMG and CIL to Get PyroActivationStatus
Application updates:
- TIM: Reset Motor Stage (BFE service) at the end of Emergency braking releasing cycle
- BFE: Irv motor stage status is reset by new service and shared with Emergency Braking runnable
- MMG: Context to detect no executed cycle is false during Emergency braking releasing cycle
- CIL: Current executed cycle sent by status frame takes into account Emergency braking releasing cycle
Revision 1.4 2014/06/13 17:24:26CEST Francois.Gilbert (fgilbert) 
Standard ALV and functional measurement frames parameter setting in CIL_Init
Revision 1.3 2014/06/12 17:55:49CEST Francois.Gilbert (fgilbert) 
First correction from what was understood from peer review based on v1.9

 *************************************************************************/

/* end of file */
