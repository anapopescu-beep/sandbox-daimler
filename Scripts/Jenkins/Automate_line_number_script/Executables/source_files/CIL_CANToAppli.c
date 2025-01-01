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
#include "Nvp_Generated.h"
#include "CIL.h"
#include "Can_Cfg.h"
#include "EcuM_Cbk.h"
/*************************************************************************
Intra-package inclusions
 *************************************************************************/

/*************************************************************************
Private inclusion
 *************************************************************************/

/*************************************************************************
Declaration of constants
 *************************************************************************/
/**
 * \brief
 * 		ECU Location
 */
#define KU8_ECU_SIDE_FRONT_LEFT             ((uint8) 0x9C)
/**
 * \brief
 * 		ECU Location
 */
#define KU8_ECU_SIDE_FRONT_RIGHT            ((uint8) 0x99)
/**
 * \brief
 * 		ECU Location
 */
#define KU8_ECU_SIDE_REAR_LEFT              ((uint8) 0xCC)
/**
 * \brief
 * 		ECU Location
 */
#define KU8_ECU_SIDE_REAR_RIGHT             ((uint8) 0xC9)
/**
 * \brief
 * 		KNOCKOUT TIMEOUT (1200000ms = 20min)
 *
 */
#define KU32_ECU_KNOCKOUT_TIMEOUT            ((uint32) 0x124F80)
/**
 * \brief
 * 		NVEM_Abschaltstufe signal consecutive received limit
 */
#define KU8_PDU_CONSECUTIVE_RECEIVED_LIMIT    10U

/**
 * \brief
 * 		BUS communication timeout (1000ms)
 */
#define KU32_CAN_NM_TIMEOUT_TIME              ((uint32) (0x3E8))
/**
 * \brief
 * 		Profile execution mapping
 */
static const uint8 kau8ProfileActivation[] =
{
   KU8_NO_ACTION,                   /* KU8_CIL_KEINE_AKTION */
   KU8_CYCLE_ID_PRESAFE_0,          /* KU8_CIL_STRAFFUNG_1_MAXGURTKRAFT */
   KU8_CYCLE_ID_PRESAFE_1,          /* KU8_CIL_STRAFFUNG_2 */
   KU8_CYCLE_ID_PRESAFE_2,          /* KU8_CIL_STRAFFUNG_3 */
   KU8_CYCLE_ID_PRESAFE_3,          /* KU8_CIL_STRAFFUNG_4_NGU */
   KU8_CYCLE_ID_PRESAFE_4,          /* KU8_CIL_STRAFFUNG_5 */
   KU8_CYCLE_ID_PRESAFE_5,          /* KU8_CIL_STRAFFUNG_6 */
   KU8_CYCLE_ID_PRESAFE_6,          /* KU8_CIL_STRAFFUNG_7 */
   KU8_CYCLE_ID_PRESAFE_7,          /* KU8_CIL_STRAFFUNG_8 */
   KU8_CYCLE_ID_PRESAFE_8,          /* KU8_CIL_STRAFFUNG_9 */
   KU8_CYCLE_ID_PRESAFE_9,          /* KU8_CIL_STRAFFUNG_10 */
   KU8_CYCLE_ID_PRESAFE_10,         /* KU8_CIL_STRAFFUNG_11 */
   KU8_CYCLE_ID_PRESAFE_11,         /* KU8_CIL_STRAFFUNG_12 */
   KU8_CYCLE_ID_PRESAFE_12,         /* KU8_CIL_STRAFFUNG_13 */
   KU8_CYCLE_ID_PRESAFE_13,         /* KU8_CIL_STRAFFUNG_14 */
   KU8_CYCLE_ID_PRESAFE_14,         /* KU8_CIL_STRAFFUNG_15 */
   KU8_CYCLE_ID_PRESAFE_15,         /* KU8_CIL_STRAFFUNG_16 */
   KU8_CYCLE_ID_PRESAFE_16,         /* KU8_CIL_STRAFFUNG_17 */
   KU8_CYCLE_ID_PRESAFE_17,         /* KU8_CIL_STRAFFUNG_18 */
   KU8_CYCLE_ID_PRESAFE_18,         /* KU8_CIL_STRAFFUNG_19 */
   KU8_CYCLE_ID_HWA_0,              /* KU8_CIL_STRAFFUNG_20_HAPTIK */
   KU8_INCORRECT_TENSIONING_COMMAND,/* KU8_CIL_RESERVED_P2P */
   KU8_INCORRECT_TENSIONING_COMMAND,/* KU8_CIL_RESERVED */
   KU8_CYCLE_ABORT,                 /* KU8_CIL_CRASHABSCHALTUNG */
   KU8_CYCLE_ID_BSR,                /* KU8_CIL_GURTLOSEREDUZIERUNG */
   KU8_INCORRECT_TENSIONING_COMMAND,/* KU8_CIL_RESERVED_ANTIPATINA */
   KU8_CYCLE_ID_BPDC,               /* KU8_CIL_GURTPARKEN_1 */
   KU8_CYCLE_ID_BPDO,               /* KU8_CIL_GURTPARKEN_2 */
   KU8_CYCLE_ID_HRD,                /* KU8_CIL_FUNKTION_BEENDEN_LOESEKURVE_2 */
   KU8_INCORRECT_TENSIONING_COMMAND,/* KU8_CIL_FEHLERHAFTE_STRAFFANFORDERUNG */
   KU8_INCORRECT_TENSIONING_COMMAND,/* KU8_CIL_FEHLERHAFTE_STRAFFDURCHFUEHRUNG */
   KU8_NO_ACTION	                /* KU8_CIL_INIT */
};
/*************************************************************************
Declaration of macros
 *************************************************************************/

/*************************************************************************
Declaration of types
 *************************************************************************/

/*************************************************************************
LOCAL variables declaration
 *************************************************************************/
/**
 * \brief
 * 		This variable store the value of buckle switch status
 *
 *\var
 *		uint8 cil_u8BuckleSwitchEgde
 */
LOCAL uint8 cil_u8BuckleSwitchEgde = KU8_MAX;
/**
 * \brief
 * 		This variable store the value of door state
 *
 *\var
 *		uint8 cil_u8DoorSwitchEdge
 */
LOCAL uint8 cil_u8DoorSwitchEdge = KU8_MAX;
/**
 * \brief
 * 		This variable store the value of repetition of haptic profile
 *
 *\var
 *		uint16 cil_u16HWACounter
 */
LOCAL uint16 cil_u16HWACounter = KU16_ZERO;

/**
 * \brief
 *		This variable store the value of Ecu knockout counter.
 */
LOCAL uint32 cil_u32EcuKnockout_Counter = 0u;
/**
 * \brief
 *		This variable store the value of Shutdown_Level_1 counter.
 */
LOCAL uint8 cil_u8Shutdown_Level_1_Counter = 0u;
/**
 * \brief
 *		This variable store the value of Shutdown_Level_0 counter.
 */
LOCAL uint8 cil_u8Shutdown_Level_0_Counter = 0u;
/**
 * \brief
 *       This variable is used to update the Nm sleep state.
 * \var
 *       uint8 CIL_u8Startup
 */
LOCAL uint8 cil_u8Shutdown_Level_0_Status = B_TRUE;
/**
 * \brief
 *       This variable is used to update the Nm sleep state.
 * \var
 *       uint8 CIL_u8Startup
 */
LOCAL uint8 cil_u8Shutdown_Level_1_Status = B_FALSE;
/**
 * \brief
 *		This variable store the value of KL15 status.
 */
LOCAL boolean cil_bKST_KL_15 = FALSE;
/**
 * \brief
 *		This variable stores the value of Nachlauf signal.
 */
LOCAL uint8 cil_u8Nachlauf2Request = Cx0_Nachlauf_2_nicht_aktiv;
/*************************************************************************
LOCAL constant data declaration
 **************************************************************************/

/*************************************************************************
EXPORTED variables declaration
 *************************************************************************/
#define CIL_AC_CommunicationInteractionLayer_START_SEC_VAR_INIT_8
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/* [COVERS: DSG_CIL_0064 ] */
/**
 * \brief
 *       This variable is used to execute the initialization , startup cycle (antipatina).
 * \var
 *       uint8 CIL_u8Startup
 */
EXPORTED uint8 CIL_u8Startup = KU8_CIL_INITIALIZATION_PHASE;

/* [COVERS: DSG_CIL_0001 ] */
/**
 * \brief
 *		This variable is used for management of request changed/not changed for BFD module
 *
 *\var
 *		uint8 CIL_u8OldActivationRequest
 */
EXPORTED volatile uint8 CIL_u8OldActivationRequest = KU8_NO_CYCLE;

/**
 * \brief
 *    This variable is used retain the previous belt cycle request.
 *
 *\var
 *    uint8 CIL_u8PreviousRequest
 */
EXPORTED volatile uint8 CIL_u8PreviousRequest = KU8_NO_CYCLE;

/* [COVERS: DSG_CIL_0001 ] */
/**
 * \brief
 *		This variable is used for update the request of BFD module
 *
 *\var
 *		uint8 CIL_u8NewTransitionRequested
 */
EXPORTED volatile uint8 CIL_u8NewTransitionRequested = B_FALSE;

/* [COVERS: DSG_CIL_0006 ] */
/**
 * \brief
 *		This Boolean indicates if an abort request has been received on RGS_ANF_01 frame
 *
 *\var
 *		boolean CIL_bAbortRequested
 */
EXPORTED volatile boolean CIL_bAbortRequested = B_FALSE;

/* [COVERS: DSG_CIL_0044] */
/**
 * \brief
 *		This flag store the value from RGS_Loesen_erlaubt signal
 *
 *\var
 *		uint8 CIL_u8ReleaseAllowedFlag
 */
EXPORTED volatile uint8 CIL_u8ReleaseAllowedFlag = Cx0_Loesen_nicht_erlaubt;

/* [COVERS: DSG_CIL_0044] */
/**
 * \brief
 *		This flag store the old value of RGS_Loesen_erlaubt signal and indicates if release is allowed
 *
 *\var
 *		uint8 CIL_u8OldReleaseAllowedFlag
 */
EXPORTED volatile uint8 CIL_u8OldReleaseAllowedFlag = Cx0_Loesen_nicht_erlaubt;

/* [COVERS: DSG_CIL_0004] */
/**
 * \brief
 *		This Boolean indicates if haptic belt function has been started to be used for repetition.
 *
 *\var
 *		boolean CIL_bHaptikStarted
 */
EXPORTED volatile boolean CIL_bHaptikStarted = B_FALSE;

/* [COVERS: DSG_CIL_0002; DSG_CIL_0003] */
/**
 * \brief
 *    This Boolean indicates if BPA function has been started to be used for response
 *
 *\var
 *    boolean CIL_bBPStarted
 */
EXPORTED volatile boolean CIL_bBPStarted = B_FALSE;

/* [ COVERS: DSG_CIL_0042] */
/**
 * \brief
 *		This Boolean indicates if conditions for HWA are inhibited or not.
 *
 *\var
 *		boolean CIL_b8HWAInhibited
 */
EXPORTED volatile boolean CIL_bHWAInhibited = B_FALSE;

/* [COVERS: DSG_CIL_0060] */
/**
 * \brief
 *    This Boolean indicates if RGS_VL_Ueberspannung signal is inhibited or not.
 *
 *\var
 *    boolean CIL_bUeberSpannungInhibited
 */
EXPORTED volatile boolean CIL_bUeberSpannungInhibited = B_FALSE;

/**
 * \brief
 *    This Boolean indicates if RGS_VL_Ueberspannung signal is disqualified.
 *
 *\var
 *    boolean CIL_bUeberSpannungDisqualified
 */
EXPORTED volatile boolean CIL_bUeberSpannungDisqualified = B_TRUE;

/* [COVERS: DSG_CIL_0058] */
/**
 * \brief
 *    This Boolean indicates if RGS_VL_Uebertemperatur_defekt signal is inhibited or not.
 *
 *\var
 *    boolean CIL_bUeberTemperatureInhibited
 */
EXPORTED volatile boolean CIL_bUeberTemperatureInhibited = B_FALSE;

/**
 * \brief
 *    This Boolean indicates if RGS_VL_Uebertemperatur_defekt signal is disqualified.
 *
 *\var
 *    boolean CIL_bUeberTemperatureDisqualified
 */
EXPORTED volatile boolean CIL_bUeberTemperatureDisqualified = B_TRUE;

/* [COVERS: DSG_CIL_0061] */
/**
 * \brief
 *    This Boolean indicates if RGS_VL_Motorfehler signal is inhibited or not.
 *
 *\var
 *    boolean CIL_bMotorfehlerInhibited
 */
EXPORTED volatile boolean CIL_bMotorfehlerInhibited = B_FALSE;

/**
 * \brief
 *    This Boolean indicates if RGS_VL_Motorfehler signal is disqualified.
 *
 *\var
 *    boolean CIL_bMotorfehlerDisqualified
 */
EXPORTED volatile boolean CIL_bMotorfehlerDisqualified = B_TRUE;

/* [COVERS: DSG_CIL_0057] */
/**
 * \brief
 *    This Boolean indicates if RGS_VL_Motorfehler signal is inhibited or not.
 *
 *\var
 *    boolean CIL_bMotorfehlerInhibited
 */
EXPORTED volatile boolean CIL_bNichtProgrammiertInhibited = B_FALSE;

/* [COVERS: DSG_CIL_0056] */
/**
 * \brief
 *    This Boolean indicates if RGS_VL_keineStraffungUnterspg signal is inhibited or not.
 *
 *\var
 *    boolean CIL_bKeineStraffungUnterspgInhibited
 */
EXPORTED volatile boolean CIL_bKeineStraffungUnterspgInhibited = B_FALSE;

/**
 * \brief
 *    This Boolean indicates if RGS_VL_keineStraffungUnterspg signal is disqualified.
 *
 *\var
 *    boolean CIL_bKeineStraffungUnterspgDisqualified
 */
EXPORTED volatile boolean CIL_bKeineStraffungUnterspgDisqualified = B_TRUE;

/* [COVERS: DSG_CIL_0059] */
/**
 * \brief
 *    This Boolean indicates if RGS_VL_Unterspannung signal is inhibited or not.
 *
 *\var
 *    boolean CIL_bUnterspannungInhibited
 */
EXPORTED volatile boolean CIL_bUnterspannungInhibited = B_FALSE;

/**
 * \brief
 *    This Boolean indicates if RGS_VL_Unterspannung signal is disqualified.
 *
 *\var
 *    boolean CIL_bUnterspannungDisqualified
 */
EXPORTED volatile boolean CIL_bUnterspannungDisqualified = B_TRUE;

/**
 * \brief
 *		This Boolean indicates if conditions for BPA are inhibited or not.
 *
 *\var
 *		boolean CIL_bBPAInhibited
 */
EXPORTED volatile boolean CIL_bBPAInhibited = B_FALSE;

/**
 * \brief
 *		This Boolean indicates if conditions for Release are inhibited or not.
 *
 *\var
 *		boolean CIL_bReleaseInhibited
 */
EXPORTED volatile boolean CIL_bReleaseInhibited = B_FALSE;

/**
 * \brief
 *		This Boolean indicates if conditions for Release are fulfilled
 *
 *\var
 *		boolean CIL_bReleaseRequested
 */
EXPORTED volatile boolean CIL_bReleaseRequested = B_FALSE;
/**
 * \brief
 *		This Boolean indicates if HWA1 phase is started
 *
 *\var
 *		boolean CIL_bHWA1PhaseStarted
 */
EXPORTED volatile boolean CIL_bHWA1PhaseStarted = B_FALSE;

/* [COVERS: DSG_CIL_0046] */
/**
 * \brief
 *		This Boolean indicates if conditions for setting Bauteilfehler error are active
 *
 *\var
 *		boolean CIL_bHWErrorPresent
 */
EXPORTED volatile boolean CIL_bHWErrorPresent = B_FALSE;

/**
 * \brief
 *		This Boolean indicates if Cycles should be inhibited by Bauteilfehler
 *
 *\var
 *		boolean CIL_bInhibitCyclesHWError
 */
EXPORTED volatile boolean CIL_bInhibitCyclesHWError = B_FALSE;

/**
 * \brief
 *    This Boolean indicates if that Response for HWA should be prepared in case of abortion
 *
 *\var
 *    boolean CIL_bPrepareResponseHWA
 */
EXPORTED volatile boolean CIL_bPrepareResponseHWA = B_FALSE;

/**
 * \brief
 *    This Boolean indicates if that Response for HRD should be prepared in case of abortion
 *
 *\var
 *    boolean CIL_bPrepareResponseHRD
 */
EXPORTED volatile boolean CIL_bPrepareResponseHRD = B_FALSE;

/**
 * \brief
 *    This Boolean indicates if that Response for BPA should be prepared in case of abortion
 *
 *\var
 *    boolean CIL_bPrepareResponseBPA
 */
EXPORTED volatile boolean CIL_bPrepareResponseBPA = B_FALSE;

/* [COVERS: DSG_CIL_0076] */
/**
 * \brief
 *    This Boolean indicates if one of the critical autotests is not set to error active when start-up cycle is not executed.
 *
 *\var
 *    boolean CIL_bCriticalAutotestsResponse
 */
EXPORTED volatile boolean CIL_bCriticalAutotestsResponse = B_FALSE;


#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_VAR_INIT_8
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"


#define CIL_AC_CommunicationInteractionLayer_START_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/**************************************************************************
LOCAL Functions
 **************************************************************************/

/* [COVERS: DSG_CIL_0002] */
/**
 * \brief
 *		The function is called by CIL_runCANToAppli to simulate BPA conditions to trigger BPDC
 * \parm
 * 		void
 * \return
 * 		void
 */
LOCAL void cil_ManageBPDCCondition(void)
{
   uint8 u8BuckleSwitchStatus;
   uint8 u8DoorSwitchStatus;

   if (CIL_bBPAInhibited == B_FALSE)
   {
      /* Conditions to activate BPDC: buckle rising edge & door falling edge */
      (void)Rte_Read_prrBuckleDoorSwitch_u8BuckleSwitch(&u8BuckleSwitchStatus);
      if (RISING_EDGE != cil_u8BuckleSwitchEgde)
      {
         if (KU8_BUCKLE_SWITCH_CLOSED == u8BuckleSwitchStatus)
         {
            (void)Rte_Write_psrBuckleDoorSwitch_u8BuckleSwitch(KU8_BUCKLE_SWITCH_OPENED);
            cil_u8BuckleSwitchEgde = RISING_EDGE;
         }
         else
         {
            /* Close it so that on the next call rising edge can be obtained */
            (void)Rte_Write_psrBuckleDoorSwitch_u8BuckleSwitch(KU8_BUCKLE_SWITCH_CLOSED);
         }
      }
      else
      {
         /* Nothing to do : Conditions for buckle state are obtained. */
      }

      (void)Rte_Read_prrBuckleDoorSwitch_u8DoorSwitch(&u8DoorSwitchStatus);
      if (FALLING_EDGE != cil_u8DoorSwitchEdge)
      {
         if (KU8_DOOR_SWITCH_OPENED == u8DoorSwitchStatus)
         {
            (void)Rte_Write_psrBuckleDoorSwitch_u8DoorSwitch(KU8_DOOR_SWITCH_CLOSED);
            cil_u8DoorSwitchEdge = FALLING_EDGE;
         }
         else
         {
            (void)Rte_Write_psrBuckleDoorSwitch_u8DoorSwitch(KU8_DOOR_SWITCH_OPENED);
         }
      }
      else
      {
         /* Nothing to do : Conditions for door state are obtained. */
      }
      CIL_bBPStarted = B_TRUE;
   }
   else
   {

   }
}

/* [COVERS: DSG_CIL_0003] */
/**
 * \brief
 *		The function is called by CIL_runCANToAppli to simulate BPA conditions to trigger BPDO
 * \parm
 * 		NA
 * \return
 * 		NA
 */
LOCAL void cil_ManageBPDOCondition(void)
{
   uint8 u8BuckleSwitchStatus;
   uint8 u8DoorSwitchStatus;

   if (B_FALSE == CIL_bBPAInhibited)
   {
      /* Conditions to activate BPDO: buckle rising edge & door rising edge */
      (void)Rte_Read_prrBuckleDoorSwitch_u8BuckleSwitch(&u8BuckleSwitchStatus);
      if (RISING_EDGE != cil_u8BuckleSwitchEgde)
      {
         if (KU8_BUCKLE_SWITCH_CLOSED == u8BuckleSwitchStatus)
         {
            (void)Rte_Write_psrBuckleDoorSwitch_u8BuckleSwitch(KU8_BUCKLE_SWITCH_OPENED);
            cil_u8BuckleSwitchEgde = RISING_EDGE;
         }
         else
         {
            /* Close it so that on the next call rising edge can be obtained */
            (void)Rte_Write_psrBuckleDoorSwitch_u8BuckleSwitch(KU8_BUCKLE_SWITCH_CLOSED);
         }
      }
      else
      {
         /* Nothing to do : Conditions for buckle state are obtained. */
      }

      (void)Rte_Read_prrBuckleDoorSwitch_u8DoorSwitch(&u8DoorSwitchStatus);
      if (RISING_EDGE != cil_u8DoorSwitchEdge)
      {
         if (KU8_DOOR_SWITCH_CLOSED == u8DoorSwitchStatus)
         {
            (void)Rte_Write_psrBuckleDoorSwitch_u8DoorSwitch(KU8_DOOR_SWITCH_OPENED);
            cil_u8DoorSwitchEdge = RISING_EDGE;
         }
         else
         {
            /* Close it so that on the next call rising edge can be obtained */
            (void)Rte_Write_psrBuckleDoorSwitch_u8DoorSwitch(KU8_DOOR_SWITCH_CLOSED);
         }
      }
      else
      {
         /* Nothing to do : Conditions for door state are obtained. */
      }
      CIL_bBPStarted = B_TRUE;
   }
   else
   {

   }
}

/* [COVERS: DSG_CIL_0042] */
/**
 * \brief
 *    The function is called by CIL_runCANToAppli to check haptic inhibition and abort conditions.
 * \parm
 *       NA
 * \return
 *       NA
 */
LOCAL void cil_CheckHWACondition(void)
{
   boolean b8HWAAbortionFlag;

   Rte_Read_psrAbortionFlagHWA_b8AbortionFlag(&b8HWAAbortionFlag);
   if (KU8_ZERO == b8HWAAbortionFlag)
   {
      CIL_bHWAInhibited = KU8_TRUE;
   }
}

/* [COVERS: DSG_CIL_0004] */
/**
 * \brief
 *		The function is called by CIL_runCANToAppli to trigger haptic repetition
 * \parm
 * 		void
 * \return
 * 		void
 */
LOCAL void cil_ManageHapticRepetition(void)
{
   uint8 u8ExecutedCycle;

   (void)Rte_Read_prrCycleNumber_u8CycleNumber(&u8ExecutedCycle);

   if( (KU8_CYCLE_ID_HWA_1 == u8ExecutedCycle) && (B_TRUE != CIL_bHWA1PhaseStarted) )
   {
      CIL_bHWA1PhaseStarted = B_TRUE;
   }

   if ( (KU8_CYCLE_ID_HWA_0 != CIL_u8ActivationRequest) && (KU8_NO_ACTION != CIL_u8ActivationRequest) && (KU8_INCORRECT_TENSIONING_COMMAND != CIL_u8ActivationRequest) )
   {
      (void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_NO_HAPTIC_REQUEST);
      CIL_bHWA1PhaseStarted = B_FALSE;
      CIL_bHaptikStarted = B_FALSE;
      cil_u16HWACounter = KU16_ZERO;
      CIL_bHWAInhibited = B_FALSE;
   }
   else if( ( B_TRUE == CIL_bHaptikStarted) && (NVP_u16HWARepetition >= cil_u16HWACounter) )
   {
      if(B_TRUE == CIL_bHWA1PhaseStarted)
      {
         cil_u16HWACounter++;
         cil_CheckHWACondition();
      }
   }
   else if (KU8_CYCLE_ID_HWA_0 == CIL_u8ActivationRequest)
   {
      (void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_NO_HAPTIC_REQUEST);
      CIL_bHWA1PhaseStarted = B_FALSE;
      CIL_bHaptikStarted = B_FALSE;
   }
   else
   {
      (void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_NO_HAPTIC_REQUEST);
      CIL_bHWA1PhaseStarted = B_FALSE;
      CIL_bHaptikStarted = B_FALSE;
      cil_u16HWACounter = KU16_ZERO;
   }
}

/* [COVERS: DSG_CIL_0043] */
/**
 * \brief
 *		CIL function used to verify inhibition conditions for BPA.
 * \parm
 * 		NA
 * \return
 * 		NA
 */
LOCAL void cil_CheckBPAInhibitionCondition(void)
{
   boolean b8BPAAbortionFlag;
   uint8 u8FaultInhibitionStatus;

   (void)Rte_Read_psrAbortionFlagBPA_b8AbortionFlag(&b8BPAAbortionFlag);
   (void)Rte_Call_pclEventInfoBatPwrOverVoltage_GetEventStatus(&u8FaultInhibitionStatus);
   if (KU8_ZERO == b8BPAAbortionFlag)
   {
      if( (B_TRUE == CIL_bBPStarted ) && (DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8FaultInhibitionStatus) ) )
      {
         /* Nothing to do - OVO only inhibits*/
      }
      else
      {
         CIL_bBPAInhibited = KU8_TRUE;
      }

   }
}

/* [COVERS: DSG_CIL_0045] */
/**
 * \brief
 *		CIL function used to verify inhibition conditions for Release.
 * \parm
 * 		NA
 * \return
 * 		NA
 */
LOCAL void cil_CheckReleaseInhibitionCondition(void)
{
   boolean b8HRDAbortionFlag;

   Rte_Read_psrAbortionFlagHRD_b8AbortionFlag(&b8HRDAbortionFlag);
   if (KU8_ZERO == b8HRDAbortionFlag)
   {
      CIL_bReleaseInhibited = KU8_TRUE;
   }
}
#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/**************************************************************************
Exported Functions
 **************************************************************************/
#define CIL_AC_CommunicationInteractionLayer_START_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/* [COVERS: DSG_CIL_0001; DSG_CIL_0049; DSG_CIL_0050; DSG_CIL_0051; DSG_CIL_0052; DSG_CIL_0054; DSG_CIL_0055; DSG_CIL_0065] */
/**
 * \brief
 *		This service evaluates the NVP parameter Ecu location and reads the specific
 *		 signal from frame RGS_Anf_01 value to see which cycle is requested on CAN.
 * \parm
 * 		void
 * \return
 * 		void
 *\remark
 * 		If RGS_ANF_01 is enabled, then this request will be saved in variable CIL_u8ActivationRequest, to be sent to application modules (HWA, BPA, BFD).
 * 		BFD will handle almost every possible request coming from CIL except Belt-Parking Door Open and Belt-Parking Door Close, which will be handled by BPA
 * 		and Haptic cycle (HWA). Haptic Repetition Algorithm will be handled in CIL, in this service.
 *
 */
EXPORTED void CIL_runCANToAppli(void)
{
   uint8 u8CycleRequest = KU8_NO_CYCLE;
   uint8 u8NachlaufAllgRequest;
   uint8 u8FrameValid = KU8_TRUE;
   Dem_EventStatusExtendedType u8FaultStatus;
   uint8 b8IsCycleEnable,u8ExecutedCycle;
   boolean b8AntipatinaFinished;
   boolean b8TriggerFlag0;
   boolean b8TriggerFlag1;
   static uint8 u8InitPhaseCounter = KU8_ONE;

   if(KU8_ECU_SIDE_FRONT_LEFT == NVP_u8ECULocation)
   {
      (void)Rte_Read_RP_IF_RGS_VL_Anforderung_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Anforderung(&u8CycleRequest);
      (void)Rte_Read_RP_IF_RGS_VL_Nachlauf_2_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_VL_Nachlauf_2(&cil_u8Nachlauf2Request);
   }
   else if(KU8_ECU_SIDE_FRONT_RIGHT == NVP_u8ECULocation)
   {
      (void)Rte_Read_RP_IF_RGS_VR_Anforderung_XIX_ReversiblenGurtStraffen_VR_XIX_Gurtfunktionen_XIX_RGS_VR_DE_RGS_VR_Anforderung(&u8CycleRequest);
      (void)Rte_Read_RP_IF_RGS_VR_Nachlauf_2_XIX_ReversiblenGurtStraffen_VR_XIX_Gurtfunktionen_XIX_RGS_VR_DE_RGS_VR_Nachlauf_2(&cil_u8Nachlauf2Request);
   }
   else if(KU8_ECU_SIDE_REAR_LEFT == NVP_u8ECULocation)
   {
      (void)Rte_Read_RP_IF_RGS_HL_Anforderung_XIX_ReversiblenGurtStraffen_HL_XIX_Gurtfunktionen_XIX_RGS_HL_DE_RGS_HL_Anforderung(&u8CycleRequest);
      (void)Rte_Read_RP_IF_RGS_HL_Nachlauf_2_XIX_ReversiblenGurtStraffen_HL_XIX_Gurtfunktionen_XIX_RGS_HL_DE_RGS_HL_Nachlauf_2(&cil_u8Nachlauf2Request);
   }
   else if(KU8_ECU_SIDE_REAR_RIGHT == NVP_u8ECULocation)
   {
      (void)Rte_Read_RP_IF_RGS_HR_Anforderung_XIX_ReversiblenGurtStraffen_HR_XIX_Gurtfunktionen_XIX_RGS_HR_DE_RGS_HR_Anforderung(&u8CycleRequest);
      (void)Rte_Read_RP_IF_RGS_HL_Nachlauf_2_XIX_ReversiblenGurtStraffen_HL_XIX_Gurtfunktionen_XIX_RGS_HL_DE_RGS_HL_Nachlauf_2(&cil_u8Nachlauf2Request);
   }
   else
   {
      /* Should not happened */
      u8CycleRequest = KU8_NO_CYCLE;
      cil_u8Nachlauf2Request = Cx0_Nachlauf_2_nicht_aktiv;
   }

   CIL_u8RawActivationRequest = u8CycleRequest;

   (void)Rte_Read_RP_IF_RGS_Nachlauf_allg_XIX_ReversiblenGurtStraffen_allg_XIX_Gurtfunktionen_XIX_RGS_allg_DE_RGS_Nachlauf_allg(&u8NachlaufAllgRequest);

   (void) Rte_Read_RP_IF_RGS_Loesen_erlaubt_XIX_ReversiblenGurtStraffen_VL_XIX_Gurtfunktionen_XIX_RGS_VL_DE_RGS_Loesen_erlaubt((void*)&CIL_u8ReleaseAllowedFlag);

   (void)Rte_Call_pclEventInfoRGSAnf01Timeout_GetEventStatus(&u8FaultStatus);

   if (CIL_TimeoutReceived == B_TRUE)
   {
      /* Error is still qualified --> frame is invalid */
      u8FrameValid = KU8_FALSE;
   }

   /* If there is a new request */
   if( (kau8ProfileActivation[u8CycleRequest] != CIL_u8OldActivationRequest) && (B_TRUE == CIL_bHWErrorPresent) )
   {
      /* Inhibit all cycles */
      CIL_bInhibitCyclesHWError = B_TRUE;
   }

   /* Reset inhibitions if there is a new request and the errors are not qualified */
   if(kau8ProfileActivation[u8CycleRequest] != CIL_u8OldActivationRequest)
   {
      if( (CIL_u8PreviousRequest != kau8ProfileActivation[u8CycleRequest]) && (B_TRUE == CIL_bMotorfehlerDisqualified) && (B_TRUE == CIL_bUeberSpannungDisqualified) &&
          (B_TRUE == CIL_bUnterspannungDisqualified) && (B_TRUE == CIL_bKeineStraffungUnterspgDisqualified) && (B_TRUE == CIL_bUeberTemperatureDisqualified) )
      {
         CIL_bMotorfehlerInhibited = B_FALSE;
         CIL_bUeberSpannungInhibited = B_FALSE;
         CIL_bUnterspannungInhibited = B_FALSE;
         CIL_bUeberTemperatureInhibited = B_FALSE;
         CIL_bKeineStraffungUnterspgInhibited = B_FALSE;
      }

      CIL_u8PreviousRequest = kau8ProfileActivation[u8CycleRequest];
   }

   /* Reset BpStarted if there is a new request */
   if( kau8ProfileActivation[u8CycleRequest] != CIL_u8OldActivationRequest )
   {
      CIL_bBPStarted = B_FALSE;
   }

   (void)Rte_Read_prrBeltStackAntipatina_b8BeltStack(&b8AntipatinaFinished);
   (void)Rte_Read_prrCycleNumber_u8CycleNumber(&u8ExecutedCycle);

   switch(CIL_u8Startup)
   {
   case KU8_CIL_INITIALIZATION_PHASE:
      u8InitPhaseCounter++;
      /* handle startup cycle response if is not done and 1200ms have passed */
      if((B_TRUE != b8AntipatinaFinished) && (KU8_ONE_HUNDRED_TWENTY == u8InitPhaseCounter))
      {
         CIL_u8Startup = KU8_CIL_DELAYED_INITIALIZATION_PHASE;
      }
      /* handle startup(antipatina) */
      else if(((B_TRUE == b8AntipatinaFinished) && ((KU8_CYCLE_ID_STARTUP > u8ExecutedCycle) || (KU8_NO_ACTION == u8ExecutedCycle))))
      {
         CIL_u8Startup = KU8_CIL_RUNTIME_PHASE;
      }
      else
      {
         /* ignore requests until antipatina is done */
      }
      break;

   case KU8_CIL_DELAYED_INITIALIZATION_PHASE:
      /* handle startup(antipatina) */
      if(((B_TRUE == b8AntipatinaFinished) && ((KU8_CYCLE_ID_STARTUP > u8ExecutedCycle) || (KU8_NO_ACTION == u8ExecutedCycle))))
      {
         CIL_u8Startup = KU8_CIL_RUNTIME_PHASE;
         CIL_bCriticalAutotestsResponse = B_FALSE;
      }
      else
      {
         /* ignore requests until antipatina is done */
      }
      break;

   default:
      break;
   }

   /* If no abort was requested and frame is valid and antipatina is finished */       /* Adapt the incoming request to internal values */
   if ( (KU8_TRUE == u8FrameValid) && (KU8_FALSE == CIL_bAbortRequested) && (KU8_CIL_RUNTIME_PHASE == CIL_u8Startup) )
   {
      switch (u8CycleRequest)
      {
      case KU8_CIL_INIT:
      case KU8_CIL_KEINE_AKTION:
         u8InitPhaseCounter = KU8_ONE;
         cil_u8DoorSwitchEdge = KU8_MAX;
         cil_u8BuckleSwitchEgde = KU8_MAX;
         CIL_u8ActivationRequest = KU8_NO_ACTION;
         if ( (KU8_CYCLE_ID_HWA_0 == u8ExecutedCycle) || (KU8_CYCLE_ID_HWA_1 == u8ExecutedCycle))
         {
            CIL_bPrepareResponseHWA = KU8_TRUE;
         }
         if (KU8_CYCLE_ID_HRD == u8ExecutedCycle)
         {
            CIL_bPrepareResponseHRD = KU8_TRUE;
         }
         if( (KU8_CYCLE_ID_BPDC == u8ExecutedCycle) || (KU8_CYCLE_ID_BPDO == u8ExecutedCycle))
         {
            CIL_bPrepareResponseBPA = KU8_TRUE;
         }
         if( ( (NVP_u16HWARepetition == cil_u16HWACounter) || (KU8_ZERO == cil_u16HWACounter) ) && (B_FALSE == CIL_bHaptikStarted))
         {
            CIL_bHWAInhibited = B_FALSE;
         }
         CIL_bBPAInhibited = B_FALSE;
         CIL_bReleaseInhibited = B_FALSE;
         CIL_bUeberSpannungInhibited = B_FALSE;
         CIL_bUeberTemperatureInhibited = B_FALSE;
         CIL_bMotorfehlerInhibited = B_FALSE;
         CIL_bKeineStraffungUnterspgInhibited = B_FALSE;
         CIL_bUnterspannungInhibited = B_FALSE;
         break;

      case KU8_CIL_STRAFFUNG_1_MAXGURTKRAFT:
         Rte_Read_prrCycleEnable_EnableCycle0(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_0 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_0;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_2:
         Rte_Read_prrCycleEnable_EnableCycle1(&b8IsCycleEnable);
         if (B_TRUE ==b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_1 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_1;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_3:
         Rte_Read_prrCycleEnable_EnableCycle2(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_2 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_2;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_4_NGU:
         Rte_Read_prrCycleEnable_EnableCycle3(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_3 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_3;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_5:
         Rte_Read_prrCycleEnable_EnableCycle4(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_4 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_4;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_6:
         Rte_Read_prrCycleEnable_EnableCycle5(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_5 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_5;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_7:
         Rte_Read_prrCycleEnable_EnableCycle6(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_6 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_6;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_8:
         Rte_Read_prrCycleEnable_EnableCycle7(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_7 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_7;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;


      case KU8_CIL_STRAFFUNG_9:
         Rte_Read_prrCycleEnable_EnableCycle8(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_8 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_8;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;


      case KU8_CIL_STRAFFUNG_10:
         Rte_Read_prrCycleEnable_EnableCycle9(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_9 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_9;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_11:
         Rte_Read_prrCycleEnable_EnableCycle10(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_10 == CIL_u8ActivationRequest)) ) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_10;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_12:
         Rte_Read_prrCycleEnable_EnableCycle11(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_11 == CIL_u8ActivationRequest)) ) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_11;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_13:
         Rte_Read_prrCycleEnable_EnableCycle12(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_12 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_12;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_14:
         Rte_Read_prrCycleEnable_EnableCycle13(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_13 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_13;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_15:
         Rte_Read_prrCycleEnable_EnableCycle14(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_14 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_14;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_16:
         Rte_Read_prrCycleEnable_EnableCycle15(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_15 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_15;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;


      case KU8_CIL_STRAFFUNG_17:
         Rte_Read_prrCycleEnable_EnableCycle16(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_16 == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_16;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;


      case KU8_CIL_STRAFFUNG_18:
         Rte_Read_prrCycleEnable_EnableCycle17(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                  (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_17 == CIL_u8ActivationRequest))) &&
                  (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_17;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_19:
         Rte_Read_prrCycleEnable_EnableCycle18(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                  (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_PRESAFE_18 == CIL_u8ActivationRequest))) &&
                  (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited) )
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_PRESAFE_18;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_STRAFFUNG_20_HAPTIK:
         Rte_Read_prrCycleEnable_EnableCycle29(&b8IsCycleEnable);
         Rte_Read_prrAlgo30_Flags_b8TriggerFlag(&b8TriggerFlag0);
         Rte_Read_prrAlgo31_Flags_b8TriggerFlag(&b8TriggerFlag1);

         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bInhibitCyclesHWError) && (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && ((b8TriggerFlag0 == B_TRUE) || (b8TriggerFlag1 == B_TRUE)))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited))
            {
               cil_CheckHWACondition();

               if (B_FALSE == CIL_bHWAInhibited)
               {
                  CIL_u8ActivationRequest = KU8_CYCLE_ID_HWA_0;
                  CIL_bPrepareResponseHWA = KU8_FALSE;
                  CIL_bHaptikStarted = B_TRUE;
                  (void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_HAPTIC_REQUEST_0);
               }
               else
               {
                  if (KU8_FALSE == CAL_NVP_B8_HWA_FUNCTION_ENABLED)
                  {
                     CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
                  }
                  else
                  {
                     CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
                  }

                  CIL_bHaptikStarted = B_FALSE;
                  (void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_NO_HAPTIC_REQUEST);
               }
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_RESERVED_P2P:
         CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         break;

      case KU8_CIL_RESERVED:
         CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         break;

      case KU8_CIL_CRASHABSCHALTUNG:
         CIL_u8ActivationRequest = KU8_CYCLE_ABORT;
         CIL_bAbortRequested = B_TRUE;
         (void)Rte_Write_psrCustomerSpecific_b8IsCarCrashDetected(KU8_TRUE);
         break;

      case KU8_CIL_GURTLOSEREDUZIERUNG:
         Rte_Read_prrCycleEnable_EnableCycle24(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_BSR == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited))
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_BSR;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }

         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_RESERVED_ANTIPATINA:
         CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         break;

      case KU8_CIL_GURTPARKEN_1:
         (void)Rte_Read_prrCycleEnable_EnableCycle28(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bInhibitCyclesHWError) && (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_BPDC == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited))
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_BPDC;
               cil_CheckBPAInhibitionCondition();
               cil_ManageBPDCCondition();
               CIL_bPrepareResponseBPA = B_FALSE;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_GURTPARKEN_2:
         (void)Rte_Read_prrCycleEnable_EnableCycle27(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bInhibitCyclesHWError) && (B_FALSE == CIL_bMotorfehlerInhibited) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
                 (B_FALSE == CIL_bUeberTemperatureInhibited) && ((B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_BPDO == CIL_u8ActivationRequest))) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited))
            {
               CIL_u8ActivationRequest = KU8_CYCLE_ID_BPDO;
               cil_CheckBPAInhibitionCondition();
               cil_ManageBPDOCondition();
               CIL_bPrepareResponseBPA = B_FALSE;
            }
            else
            {
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      case KU8_CIL_FUNKTION_BEENDEN_LOESEKURVE_2:
         Rte_Read_prrCycleEnable_EnableCycle32(&b8IsCycleEnable);
         if (B_TRUE == b8IsCycleEnable)
         {
            if ( (B_FALSE == CIL_bInhibitCyclesHWError) && (B_FALSE == CIL_bNichtProgrammiertInhibited) &&
               ( (B_FALSE == CIL_bMotorfehlerInhibited) || ((B_TRUE == CIL_bMotorfehlerInhibited) && (KU8_CYCLE_ID_HRD == CIL_u8ActivationRequest)) ) &&
               ( (B_FALSE == CIL_bUeberSpannungInhibited) || ((B_TRUE == CIL_bUeberSpannungInhibited) && (KU8_CYCLE_ID_HRD == CIL_u8ActivationRequest)) ) &&
               ( (B_FALSE == CIL_bUeberTemperatureInhibited) || ((B_TRUE == CIL_bUeberTemperatureInhibited) && (KU8_CYCLE_ID_HRD == CIL_u8ActivationRequest)) ) &&
                 (B_FALSE == CIL_bKeineStraffungUnterspgInhibited) && (B_FALSE == CIL_bUnterspannungInhibited))
            {
               (void)Rte_Read_prrCycleNumber_u8CycleNumber(&u8ExecutedCycle);
               cil_CheckReleaseInhibitionCondition();
               CIL_bReleaseRequested = B_TRUE;
               if ( (KU8_CYCLE_ID_HRD != CIL_u8ActivationRequest) && (B_FALSE == CIL_bReleaseInhibited) )
               {
                  (void)Rte_Write_psrCustomerSpecific_b8HardReleaseRequest(KU8_TRUE);
                  if (KU8_CYCLE_ID_HRD == u8ExecutedCycle)
                  {
                     CIL_u8ActivationRequest = KU8_CYCLE_ID_HRD;
                     CIL_bPrepareResponseHRD = KU8_FALSE;
                  }
                  else
                  {
                     /* Nothing to do */
                  }
               }
               else
               {
                  (void)Rte_Write_psrCustomerSpecific_b8HardReleaseRequest(KU8_FALSE);
               }
            }
            else
            {
               (void)Rte_Write_psrCustomerSpecific_b8HardReleaseRequest(KU8_FALSE);
               CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_EXECUTION_INHIBITION;
            }
         }
         else
         {
            CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         }
         break;

      default: /* If the request is not defined => Incorrect Tensioning command should be acknowledged */
         CIL_u8ActivationRequest = KU8_INCORRECT_TENSIONING_COMMAND;
         break;
      }
   }
   /* If frame is not valid and abort was not requested */
   else if ((KU8_FALSE == u8FrameValid) && (B_FALSE == CIL_bAbortRequested) )
   {
      CIL_u8ActivationRequest = KU8_NO_ACTION;
      CIL_u8ReleaseAllowedFlag = Cx0_Loesen_nicht_erlaubt;
      cil_u8Nachlauf2Request = Cx0_Nachlauf_2_nicht_aktiv;
      u8NachlaufAllgRequest = KU8_ZERO;
   }
   else
   {
      /* Frame is not valid (TIMEOUT failure) and abort was received
      --> do not modify last request. It is the last known request */
   }
   (void) Rte_Write_psrNmInterfaces_u8BpaStopMode_Appl(cil_u8Nachlauf2Request);

   (void) Rte_Write_psrNmInterfaces_u8AfterRunMode_Appl(u8NachlaufAllgRequest);

   /* Overwrite an incoming request if abort was received */
   if (B_TRUE == CIL_bAbortRequested)
   {
      CIL_u8ActivationRequest = KU8_CYCLE_ABORT;
   }
   else
   {
      /* Nothing to do */
   }

   cil_ManageHapticRepetition();
} /* end of function CIL_runCANToAppli */

/* [COVERS: DSG_CIL_0001] */
/**
 * \brief
 *		 CIL function used to send to all application the activation request.
 * \param[in,out]
 * 		uint8 cpu8ReleaseAllowed
 * \return
 * 		void
 */
EXPORTED void CIL_runGetReleaseAllowed(RGS_Loesen_erlaubtType* u8ReleaseAllowed)
{
	if (NULL_PTR != u8ReleaseAllowed)
	{
		* u8ReleaseAllowed = CIL_u8ReleaseAllowedFlag;
	}
	else
	{
		/*Misra*/
	}
}

/* [COVERS: DSG_CIL_0044] */
/**
 * \brief
 *		 This service is an interface that can be used by all applications module, to read variable
 *		  CIL_u8ActivationRequest, to see what cycle is requested on Anforderung signal.
 * \param[in,out]
 * 		uint8 cpu8ActivationRequest
 * 		boolean bNewValueReceived
 * \param[in]
 * 		boolean bClearNewRequestNotification
 * \return
 * 		void
 */
EXPORTED void CIL_runGetActivationRequest(uint8* cpu8ActivationRequest, boolean* bNewValueReceived)
{
	uint8 const u8ReleaseAllowed = CIL_u8ReleaseAllowedFlag;

	if (NULL_PTR != bNewValueReceived)
	{
		*bNewValueReceived = B_FALSE;

		/* Check if the passed pointer is not NULL */
		if (KPU8_NULL != cpu8ActivationRequest)
		{
			/* Prepare the return value : TRUE if a new frame has been received */
			*bNewValueReceived = CIL_bNewActivationRequestAvailable;

			/* Then clear the new frame received flag */
			CIL_bNewActivationRequestAvailable = B_FALSE;

			/* Read the value of CIL_bActivationRequest and write it to the pointed value */
			*cpu8ActivationRequest = CIL_u8ActivationRequest;

			/*If there is a new request*/
			if (*cpu8ActivationRequest != CIL_u8OldActivationRequest)
			{
				/*Update the request*/
				CIL_u8OldActivationRequest = CIL_u8ActivationRequest;

				CIL_u8NewTransitionRequested = B_TRUE;

				/* The request has internally changed. Return B_TRUE */
				*bNewValueReceived = B_TRUE;
			}
			else if (u8ReleaseAllowed != CIL_u8OldReleaseAllowedFlag)
			{
				if (KU8_NO_CYCLE == CIL_u8ActivationRequest)
				{
					*bNewValueReceived = B_TRUE;
				}
				else
				{
					/*Misra*/
				}
				CIL_u8OldReleaseAllowedFlag = CIL_u8ReleaseAllowedFlag;
			}
			else
			{
				/*The request is the same. Return B_FALSE*/
				*bNewValueReceived = B_FALSE;
			}
		}
		else
		{
			/*Misra*/
		}
	}
	else
	{
		/*Misra*/
	}
} /* end of function CIL_runGetActivationRequest */


/* QAC_WARNING S 3408 1 */ /* QAC warning due implementation of callback for timeout error */
/**
 * \brief
 *		This service is a callback that is called when the frame RGS_ANf_01 is received. *
 * \param
 * 		void
 * \return
 * 		void
 */
 /* [COVERS: DSG_CIL_0071] */
FUNC(void, COM_APPL_CODE) CIL_CbkRxAck_RGS_Anf_01(void)
{
   CIL_TimeoutReceived = B_FALSE;

   return;
}  /* end of function CIL_CbkRxAck_RGS_Anf_01 */

/* QAC_WARNING S 3408 1 */ /* QAC warning due implementation of callback for timeout error */
/**
 * \brief
 *		This service is a callback that is called when the timeout for RGS_ANf_01 frame is detected. *
 * \param
 * 		void
 * \return
 * 		void
 */
/* [COVERS: DSG_CIL_0005] */
FUNC(void, COM_APPL_CODE) CIL_CbkRxTout_RGS_Anf_01 (void)
{
   CIL_TimeoutReceived = B_TRUE;

   return;
} /* end of function CIL_CbkRxTout_RGS_Anf_01 */

/**
 * \brief
 *		This service is a callback that is called when the frame NVEM_12 is received. *
 * \param
 * 		void
 * \return
 * 		void
 */
/* [COVERS: DSG_CIL_0068] */
FUNC(void, COM_APPL_CODE) CIL_CbkRxAck_NVEM_12(void)
{
	uint8 u8NVEM_Abschaltstufe_SignalValue = 0u;

	/* Get the NVEM_Abschaltstufe signal value from Com module */
	if ((uint8) E_OK == Rte_Read_RP_IF_NVEM_Abschaltstufe_XIX_ReversiblenGurtStraffen_XIX_Gurtfunktionen_IF_NVEM_Abschaltstufe(&u8NVEM_Abschaltstufe_SignalValue))
	{
		if (u8NVEM_Abschaltstufe_SignalValue == 1u)
		{
			cil_u8Shutdown_Level_0_Counter = 0u;

			if (cil_u8Shutdown_Level_1_Counter < KU8_PDU_CONSECUTIVE_RECEIVED_LIMIT)
			{
				cil_u8Shutdown_Level_1_Counter++;
			}
			else
			{
				/* Shutdown Level_1 shall activated if NVEM_Abschaltstufe signal has been received 10 times with value 0x01 */
				cil_u8Shutdown_Level_1_Status = B_TRUE;
				cil_u8Shutdown_Level_0_Status = B_FALSE;
			}
		}
		else if (u8NVEM_Abschaltstufe_SignalValue == 0u)
		{
			cil_u8Shutdown_Level_1_Counter = 0u;

			if (cil_u8Shutdown_Level_0_Counter < KU8_PDU_CONSECUTIVE_RECEIVED_LIMIT)
			{
				cil_u8Shutdown_Level_0_Counter++;
			}
			else
			{
				/* Shutdown Level_0 shall activated if NVEM_Abschaltstufe signal has been received 10 times with value 0x00 */
				cil_u8Shutdown_Level_0_Status = B_TRUE;
				cil_u8Shutdown_Level_1_Status = B_FALSE;
			}
		}
		else
		{
			/*Misra*/
		}
	}
	else
	{
		/*Misra*/
	}
	return;
}  /* end of function CIL_CbkRxAck_NVEM_12 */

/**
 * \brief
 *		This service is a callback that is called when the timeout for NVEM_12 frame is detected. *
 * \param
 * 		void
 * \return
 * 		void
 */
/* [COVERS: DSG_CIL_0069] */
FUNC(void, COM_APPL_CODE) CIL_CbkRxTout_NVEM_12(void)
 {
	/* Reset the Shutdown_Level status */
	cil_u8Shutdown_Level_0_Status = B_TRUE;
	cil_u8Shutdown_Level_1_Status = B_FALSE;

	/* Reset the Shutdown_Level counters */
	cil_u8Shutdown_Level_1_Counter = 0u;
	cil_u8Shutdown_Level_0_Counter = 0u;

	return;
 } /* end of function CIL_CbkRxTout_NVEM_12 */

/**
 * \brief
 *		This service is a callback that is called when the frame ClampControl_01 is received. *
 * \param
 * 		void
 * \return
 * 		void
 */
/* [COVERS: DSG_CIL_0072] */
FUNC(void, COM_APPL_CODE) CIL_CbkRxAck_ClampControl_01(void)
 {
	boolean bKL15_LocalStatus = FALSE;

	/* Read the KL15 status from ClampControl_KST_KL_15 signal */
	if ((uint8)E_OK == Rte_Read_RP_IF_KST_KL_15_XIX_ReversiblenGurtStraffen_XIX_Gurtfunktionen_XIX_DE_KST_KL_15(&bKL15_LocalStatus))
	{
		cil_bKST_KL_15 = bKL15_LocalStatus;
	}
	else
	{
		/* MISRA */
	}
	return;
} /* end of function CIL_CbkRxAck_ClampControl_01 */

/**
 * \brief
 *		This service is a callback that is called when the timeout for frame ClampControl_01 is detected. *
 * \param
 * 		void
 * \return
 * 		void
 */
/* [COVERS: DSG_CIL_0067] */
FUNC(void, COM_APPL_CODE) CIL_CbkRxTout_ClampControl_01(void)
 {
	/* Reset the KL15 status */
	cil_bKST_KL_15 = FALSE;

	return;
} /* end of function CIL_CbkRxTout_ClampControl_01 */

/**
 * \brief
 *		This is the EcuKnockout_Timeout autotest. It consists of checking the EcuKnockout counter.
 * \param[in,out] pu8TestResult - result of the EcuKnockout_Timeout autotest
 *  * 		The test result:
 * \ - KU8_ATM_TEST_OK - Immediately after the first communication frame has been received
 * \ - KU8_ATM_TEST_NOK - If the EcuKnockout_Counter is greater than EcuKnockoutTimeoutThreshold (20min)
 * \ - KU8_ATM_TEST_NOT_DECIDED - The autotest has not been run yet
 * \return none
 */
/* [COVERS: DSG_CIL_0070] */
FUNC(void, RTE_CODE) CIL_Autotest_CheckEcuKnockout_Timeout (P2VAR(u8TestResultType, AUTOMATIC, RTE_APPL_DATA) pu8TestResult, u8AutoTestPeriodicityType u8TestPeriodicity)
{
	/* Returned autotest status */
	u8TestResultType u8ResultOfAutoTest;

	/* Increase the Ecu knockout counter*/
	cil_u32EcuKnockout_Counter += u8TestPeriodicity;

	if (NULL_PTR != pu8TestResult)
	{
		if ((cil_u32EcuKnockout_Counter >= KU32_ECU_KNOCKOUT_TIMEOUT) && (KU8_NVP_PROCESS_MODE_INACTIVE == NVP_u8ProcessMode))
		{
			u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
		}
		else
		{
			/* If no frames are received for maximum 20 min. */
			u8ResultOfAutoTest = KU8_ATM_TEST_OK;
		}

		/* Get the auto test status */
		*pu8TestResult = u8ResultOfAutoTest;
	}
	else
	{
		/* MISRA */
	}
   return;
} /* end of function CIL_Autotest_CheckEcuKnockout_Timeout */

/**
 * \brief
 *		This function shall check if the conditions to enter in sleep mode are fulfilled (no bus communication)
 * \param[in,out] pu8CommunicationTimeoutStatus - communication timeout status
 * \ - B_TRUE - no frames are received for maximum 1000ms
 * \ - B_FALSE - frames are received
 * \return none
 */
/* [COVERS: DSG_CIL_0073] */
FUNC(void, RTE_CODE) CIL_CheckBusCommunication_Timeout (P2VAR(u8CommunicationTimeoutStatusType, AUTOMATIC, RTE_APPL_DATA) BusCommunicationTimeoutStatus)
{
	uint8 u8CommunicationTimeoutResult;

	if (NULL_PTR != BusCommunicationTimeoutStatus)
	{
		if (cil_u32EcuKnockout_Counter >= KU32_CAN_NM_TIMEOUT_TIME)
		{
			/* If no frames are received for maximum 1000ms */
			u8CommunicationTimeoutResult = B_TRUE;
		}
		else
		{
			u8CommunicationTimeoutResult = B_FALSE;
		}

		/* Get the Comunication timeout status */
		*BusCommunicationTimeoutStatus = u8CommunicationTimeoutResult;
	}
	else
	{
		/* MISRA */
	}
	return;
} /* end of function CIL_CheckBusCommunication_Timeout */

/**
 * \brief
 *		This function shall get the Shutdown_Level_0_Status and Shutdown_Level_1_Status
 * \param[in,out] - pu8Shutdown_Level_0_Status - used to update the Nm sleep state
 * - pu8Shutdown_Level_1_Status - used to update the Nm sleep state
 * \ - B_TRUE - if Shutdown_Level_x_Status is activated
 * \ - B_FALSE - if Shutdown_Level_x_Status is deactivated
 * \return none
 */
/* [COVERS: DSG_CIL_0074] */
FUNC(void, RTE_CODE) CIL_GetShutdownLevel_Status (P2VAR(u8Shutdown_Level_0_Type, AUTOMATIC, RTE_APPL_DATA) ShutdownLevel_0, P2VAR(u8Shutdown_Level_1_Type, AUTOMATIC, RTE_APPL_DATA) ShutdownLevel_1)
{
	if((NULL_PTR != ShutdownLevel_0) && (NULL_PTR != ShutdownLevel_1))
	{
		*ShutdownLevel_0 = cil_u8Shutdown_Level_0_Status;
		*ShutdownLevel_1 = cil_u8Shutdown_Level_1_Status;
	}
	else
	{
		/* MISRA */
	}
	return;
} /* end of function CIL_GetShutdownLevel_Status */

/**
 * \brief
 *		This function shall get the KST_KL_15 Status
 * \param[in,out] - bKST_KL_15_Status - used to update the KST_KL_15 status
 * \ - TRUE  - if KST_KL_15 siganl value is ON (1)
 * \ - FALSE - if KST_KL_15 siganl value is OFF (0)
 * \return none
 */
/* [COVERS: DSG_CIL_0075] */
FUNC(void, RTE_CODE) CIL_GetClampControl_01_KST_KL_15_Status (P2VAR(u8KST_KL_15Type, AUTOMATIC, RTE_APPL_DATA)  bKST_KL_15_Status)
{
	if(NULL_PTR != bKST_KL_15_Status)
	{
		*bKST_KL_15_Status = cil_bKST_KL_15;
	}
	else
	{
		/* MISRA */
	}

	return;
} /* end of function CIL_GetClampControl_01_KST_KL_15_Status */

/**
 * \brief
 *		This service is a callback that is called when any CAN frame is received. *
 * \param
 * 		void
 * \return
 * 		boolean - always returns TRUE to continue processing all messages in CanIf module
 */
/* [COVERS: DSG_CIL_0066] */
FUNC(boolean, CAN_CODE) CIL_PduReceiveCallout(void)
 {
	/* Reset the Ecu knockout counter */
	cil_u32EcuKnockout_Counter = 0u;

    /* If any frame has been received a valid wakeup shall be reported to EcuM */
	EcuM_ValidateWakeupEvent(EcuM_ECUM_WKSOURCE_CAN);

	return TRUE;
}  /* end of function CIL_PduReceiveCallout */

#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"


/*************************************************************************
Evolution of the component

Created by : F.GILBERT

$Log: CIL_CANToAppli.c  $
Revision 1.1 2021/10/04 07:14:25CEST Lucian Ardeleanu (lucian.ardeleanu) 
Initial revision
Member added to project e:/MKSProjects/SBE/Exploration/Python_Workspace/Automate_line_number_script/Executables/source_files/project.pj
Revision 1.1.1.3.4.109 2021/08/02 13:45:06EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Add treaceability
Revision 1.1.1.3.4.108 2021/08/02 11:20:19EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Add fix after review
Revision 1.1.1.3.4.107 2021/07/27 14:32:43EEST Mirela Obada (mirela.obada) 
Update transability
Revision 1.1.1.3.4.106 2021/07/23 10:08:58EEST Marius Chiriac (marius.chiriac1) 
Inhibit knockout function during Ecu Process Mode
Revision 1.1.1.3.4.105 2021/07/21 15:23:25EEST Mirela Obada (mirela.obada) 
Update traceability
Revision 1.1.1.3.4.104 2021/07/16 09:55:14EEST Anca Vulpe (anca.vulpe) 
Update NachlaufAllg
Revision 1.1.1.3.4.103 2021/07/15 11:22:47EEST Anca Vulpe (anca.vulpe) 
RGS_Anf timeout
Revision 1.1.1.3.4.102 2021/07/13 13:49:09EEST Anca Vulpe (anca.vulpe) 
Update nachlauf
Revision 1.1.1.3.4.101 2021/07/13 10:46:48EEST Anca Vulpe (anca.vulpe) 
cil_u8Nachlauf2Request = 0 whwn RGS_Anf timeout occurs
Revision 1.1.1.3.4.100 2021/07/08 12:40:40EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Fix QAC errors
Revision 1.1.1.3.4.99 2021/07/05 16:28:49EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
remove unused variable
Revision 1.1.1.3.4.98 2021/07/05 16:10:32EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Add new conditions for start up cycle (init phase)
Revision 1.1.1.3.4.97 2021/07/05 11:04:29EEST Dan Dustinta (dan.dustinta) 
update behaviour when rgs anf has a timeout
Revision 1.1.1.3.4.96 2021/06/24 11:58:33EEST Marius Chiriac (marius.chiriac1) 
QAC corrections
Revision 1.1.1.3.4.95 2021/06/18 14:50:22EEST Marius Chiriac (marius.chiriac1) 
Validate wake up at any frame received
Revision 1.1.1.3.4.94 2021/06/17 14:27:42EEST Marius Chiriac (marius.chiriac1) 
Add QRS and Knockout mechanisms
Revision 1.1.1.3.4.93 2021/05/26 14:49:17EEST Andreea Negrea (andreea.negrea) 
Fix indentation for HWA
Revision 1.1.1.3.4.92 2021/05/26 14:31:54EEST Andreea Negrea (andreea.negrea) 
Update indentation for new code
Revision 1.1.1.3.4.91 2021/05/25 17:46:05EEST Andreea Negrea (andreea.negrea) 
Add two new tensioning cycles
Revision 1.1.1.3.4.90 2021/05/11 15:48:28EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Fix HWA request
Revision 1.1.1.3.4.89 2021/04/26 10:26:14EEST Andreea Negrea (andreea.negrea) 
Update HWA Repetition conditions
Revision 1.1.1.3.4.88 2021/04/22 11:40:45EEST Andreea Negrea (andreea.negrea) 
Add HWA inhibitted new conditions in CANToAppli and remove the old ones fron AppliToCAN
Revision 1.1.1.3.4.87 2021/04/19 11:04:27EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Add condition that not inhibit profiles if the errors not exist
Revision 1.1.1.3.4.86 2021/04/05 13:31:56EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Add fix for end of profile
Revision 1.1.1.3.4.85 2021/04/05 12:52:53EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
rework statement for CIL_bUeberTemperatureInhibited in HRD case
Revision 1.1.1.3.4.84 2021/04/05 12:35:42EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Rework statemet for CIL_bMotorfehlerInhibited in HARD_RELEASE case
Revision 1.1.1.3.4.83 2021/04/01 11:29:14EEST Andreea Negrea (andreea.negrea) 
Add fix after review
Revision 1.1.1.3.4.82 2021/03/10 14:55:51EET Andreea Negrea (andreea.negrea) 
Implementation of 0x1E*10 in case of BSR, HWA and HRD abortion
Revision 1.1.1.3.4.81 2021/02/02 11:57:18EET Andreea Negrea (andreea.negrea) 
Update traceability
Revision 1.1.1.3.4.80 2021/01/14 12:44:58EET Andreea Negrea (andreea.negrea) 
Update doc
Revision 1.1.1.3.4.79 2020/12/17 14:41:27EET Dan Dustinta (dan.dustinta) 
remove double if clause
Revision 1.1.1.3.4.78 2020/12/16 16:51:51EET Dan Dustinta (dan.dustinta) 
Rework status signal for OVO
Revision 1.1.1.3.4.77 2020/12/15 16:50:43EET Dan Dustinta (dan.dustinta) 
update RGSNichtProgrammiert inhibition
Revision 1.1.1.3.4.76 2020/12/10 16:22:47EET Andreea Negrea (andreea.negrea) 
Add inhibitions from status frame signals to all cycles
Revision 1.1.1.3.4.75 2020/12/08 12:27:21EET Andreea Negrea (andreea.negrea) 
Update toggle Motorfehler
Revision 1.1.1.3.4.74 2020/11/26 10:07:11EET Andreea Negrea (andreea.negrea) 
Update Reset flags
Revision 1.1.1.3.4.73 2020/11/26 08:06:24EET Andreea Negrea (andreea.negrea) 
Update BPA response when OVO is not aborting.
Reset all flags when new request is received
Revision 1.1.1.3.4.72 2020/11/23 14:28:43EET Dan Dustinta (dan.dustinta) 
fix findings from PRWB
Revision 1.1.1.3.4.71 2020/11/19 15:07:51EET Gheorghita Brasoveanu (gheorghita.brasovean) 
Fix RGS_VL inhibition conditions
Revision 1.1.1.3.4.70 2020/11/18 14:54:49EET Andreea Negrea (andreea.negrea) 
Fix Init value for CIL_u8ActivationRequest
Revision 1.1.1.3.4.69 2020/11/16 09:32:05EET Andreea Negrea (andreea.negrea) 
Fix release Allowed signal toggle
Revision 1.1.1.3.4.68 2020/11/10 11:26:21EET Gheorghita Brasoveanu (gheorghita.brasovean) 
Fix Warnings
Revision 1.1.1.3.4.67 2020/11/05 13:00:19EET Mirela Obada (mirela.obada) 
Update code after QAC
Revision 1.1.1.3.4.66 2020/11/03 11:34:50EET Gheorghita Brasoveanu (gheorghita.brasovean) 
Update variables name
Revision 1.1.1.3.4.65 2020/10/30 15:59:16EET Andreea Negrea (andreea.negrea) 
Extend profile limit to 38 and add new 40 steps
Revision 1.1.1.3.4.64 2020/10/30 15:02:29EET Gheorghita Brasoveanu (gheorghita.brasovean) 
Fix variables type
Revision 1.1.1.3.4.63 2020/10/30 12:47:03EET Gheorghita Brasoveanu (gheorghita.brasovean) 
Update conditions for inhibition RGS_VL signals
Revision 1.1.1.3.4.62 2020/10/30 11:41:18EET Dan Dustinta (dan.dustinta) 
update response handling for init phase
Revision 1.1.1.3.4.61 2020/10/16 10:46:19EEST Mirela Obada (mirela.obada) 
Update code after QAC
Revision 1.1.1.3.4.60 2020/10/16 09:23:53EEST Dan Dustinta (dan.dustinta) 
rework HWA request
Revision 1.1.1.3.4.59 2020/10/13 09:55:35EEST Andreea Negrea (andreea.negrea) 
Move init handle response from BFD to CIL
Revision 1.1.1.3.4.58 2020/10/06 14:31:25EEST Mirela Obada (mirela.obada) 
Update code after QAC
Revision 1.1.1.3.4.57 2020/10/06 13:24:13EEST Mirela Obada (mirela.obada) 
Update code after QAC
Revision 1.1.1.3.4.56 2020/10/06 12:50:51EEST Mirela Obada (mirela.obada) 
Update code after QAC
Revision 1.1.1.3.4.55 2020/10/02 16:05:26EEST Dan Dustinta (dan.dustinta) 
fix init status when PAT is replaced by SMO/HRD/BKUP
Revision 1.1.1.3.4.54 2020/09/30 17:39:02EEST Andreea Negrea (andreea.negrea) 
Update Bauteilfehler inhibition
Revision 1.1.1.3.4.53 2020/09/29 14:42:27EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Removing the unnecessary parameter from CIL_runGetActivationRequest function
Revision 1.1.1.3.4.52 2020/09/28 15:49:46EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Remove do while condition
Revision 1.1.1.3.4.51 2020/09/28 14:59:04EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Back to the old version, "do while" condition must be rebuild
Revision 1.1.1.3.4.50 2020/09/28 11:54:33EEST Dan Dustinta (dan.dustinta) 
update Rte Interfaces for NmIf
Revision 1.1.1.3.4.49 2020/09/28 11:06:19EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Update CIL and BFD according to Peer Review issues
Revision 1.1.1.3.4.48 2020/09/24 14:18:56EEST Andreea Negrea (andreea.negrea) 
Update HWA manage repetition function
Revision 1.1.1.3.4.47 2020/09/21 13:51:04EEST Andreea Negrea (andreea.negrea) 
Update cycle response in case of Bauteilfehler active
Revision 1.1.1.3.4.46 2020/09/18 12:34:02EEST Andreea Negrea (andreea.negrea) 
Update response for HWA/BPx/BSR/HRD
Revision 1.1.1.3.4.45 2020/09/11 13:42:28EEST Mirela Obada (mirela.obada) 
Fix the Peer Review findings
Revision 1.1.1.3.4.44 2020/09/11 12:48:29EEST Dan Dustinta (dan.dustinta) 
update according to QAC
Revision 1.1.1.3.4.43 2020/09/10 17:58:07EEST Andreea Negrea (andreea.negrea) 
Update on release allowed should lead to newValueReceived for BFD
Revision 1.1.1.3.4.42 2020/09/10 17:01:58EEST Andreea Negrea (andreea.negrea) 
Update init behavior for Crashabshaltung and tensioning cycles .
Revision 1.1.1.3.4.41 2020/09/10 15:11:06EEST Mirela Obada (mirela.obada) 
Update peer review
Revision 1.1.1.3.4.40 2020/09/10 10:57:34EEST Mirela Obada (mirela.obada) 
[TR6][SRC] Update CIL findings Peer Review
Revision 1.1.1.3.4.39 2020/09/07 15:47:57EEST Andreea Negrea (andreea.negrea) 
Update functions for inhibition of HWA/BPA/SFR cycles
Revision 1.1.1.3.4.38 2020/09/04 12:45:02EEST Dan Dustinta (dan.dustinta) 
stub belt buckle signal from HWA
Revision 1.1.1.3.4.37 2020/09/02 14:49:53EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Fix HWA to be repeated only in phase 2 and after the status frame does not report that HWA is performed it was stopped on the measurement frame.
Revision 1.1.1.3.4.36 2020/08/31 11:25:56EEST Dan Dustinta (dan.dustinta) 
update beltstack for infnite hard release issue
Revision 1.1.1.3.4.35 2020/08/11 16:06:05EEST Mirela Obada (mirela.obada) 
Update comments and traceabilty.
Revision 1.1.1.3.4.34 2020/07/09 17:39:33EEST Andreea Negrea (andreea.negrea) 
Fix Bauteilfehler inhibition for cycles
Revision 1.1.1.3.4.33 2020/07/08 16:44:28EEST Andreea Negrea (andreea.negrea) 
Fix HRD to be executed only one time
Revision 1.1.1.3.4.32 2020/07/08 09:36:31EEST Andreea Negrea (andreea.negrea) 
Fix Crashabshaltung during INIT
Revision 1.1.1.3.4.31 2020/07/07 16:40:50EEST Andreea Negrea (andreea.negrea) 
Fix HWA start after INIT
Revision 1.1.1.3.4.30 2020/06/25 14:05:37EEST Andreea Negrea (andreea.negrea) 
Fix BPA strat after init
Revision 1.1.1.3.4.29 2020/06/16 16:57:29EEST Andreea Negrea (andreea.negrea) 
Update HWA cycle map
Revision 1.1.1.3.4.28 2020/06/05 16:14:40EEST Anca Vulpe (anca.vulpe) 
Add new conditions
Revision 1.1.1.3.4.27 2020/06/05 14:14:53EEST Andreea Negrea (andreea.negrea) 
Add interface for last interrupt cycle
Add hrd after aborted cycle
Update cycle enable
Revision 1.1.1.3.4.26 2020/06/05 10:16:16EEST Dan Dustinta (dan.dustinta) 
ecpl Adaptations
Revision 1.1.1.3.4.25 2020/06/05 02:36:08EEST Andreea Negrea (andreea.negrea) 
Add algo and interfaces for release allowed and cycle enable
Revision 1.1.1.3.4.24 2020/06/03 11:47:37EEST Andreea Negrea (andreea.negrea) 
Update IncorrectTEnsionindCommand behaviour
Revision 1.1.1.3.4.23 2020/06/03 09:12:58EEST Andreea Negrea (andreea.negrea) 
Add HRD response
Revision 1.1.1.3.4.22 2020/06/02 15:43:27EEST Andreea Negrea (andreea.negrea) 
Update cycles map for P20.
Revision 1.1.1.3.4.21 2020/06/01 17:41:30EEST Andreea Negrea (andreea.negrea) 
Add SFR component
Revision 1.1.1.3.4.20 2020/05/12 14:29:01EEST Andreea Negrea (andreea.negrea) 
Update traceability after design was updated with new function that verifies  BPA inhibition .
Revision 1.1.1.3.4.19 2020/05/12 10:24:57EEST Andreea Negrea (andreea.negrea) 
Update architecture and design and traceability for HWA inhibition response
Revision 1.1.1.3.4.18 2020/05/11 17:19:37EEST Andreea Negrea (andreea.negrea) 
Fix BPA Status frame response when incorrect tensioning should be transmitted
Revision 1.1.1.3.4.17 2020/05/08 14:39:16EEST Andreea Negrea (andreea.negrea) 
Add changes to :
-set Incoreect tensioning execution when haptik is inhibitted or aborted 
-not start HWA if a fault is deskilling until a new request is sent
-not start HWA counter until init phase is over
Revision 1.1.1.3.4.16 2020/03/17 14:59:32EET Andreea Negrea (andreea.negrea) 
Update CIL treaceability
Revision 1.1.1.3.4.15 2020/02/28 18:12:12EET Razvan Badiu (razvan.badiu) 
abort haptic by crash signal
Revision 1.1.1.3.4.14 2020/02/28 17:12:39EET Daniel Andris (daniel.andris) 
Fix Haptic buffering reinitialization
Revision 1.1.1.3.4.13 2020/02/26 17:59:32EET Andreea Negrea (andreea.negrea) 
Fixed after review
Revision 1.1.1.3.4.12 2020/02/18 16:59:09EET Andreea Negrea (andreea.negrea) 
CIL update to meet Coding Guidelines
Revision 1.1.1.3.4.11 2019/11/13 13:05:33EET Andreea Negrea (andreea.negrea) 
BPDC should be Gurtparken 1 and BPDO should be Gurtparking2
Revision 1.1.1.3.4.10 2019/11/12 13:31:22EET Andreea Negrea (andreea.negrea) 
Send No action when Funktion Beenden is requested.
Revision 1.1.1.3.4.9 2019/11/11 19:39:14EET Andreea Negrea (andreea.negrea) 
Add fix to handle all signals from frame RGS_Anf_01
Revision 1.1.1.3.4.8 2019/11/05 17:37:49EET Andreea Negrea (andreea.negrea) 
CIL modification after QAC run
Revision 1.1.1.3.4.7 2019/10/28 10:49:22EET Andreea Negrea (andreea.negrea) 
Add HWA to last 5s for Audi or 2 s for Proche
Revision 1.1.1.3.4.6 2019/10/21 13:29:10EEST Andreea Negrea (andreea.negrea) 
RGS_Anf_01 timeout error implementation. When timout is received no request should be send to BFD.
Revision 1.1.1.3.4.5 2019/10/15 13:21:12EEST Andreea Negrea (andreea.negrea) 
BPA Algo implementation
Revision 1.1.1.3.4.4 2019/10/10 10:19:08EEST Andreea Negrea (andreea.negrea) 
Consider Tensioning NGU to be Cycle Presafe 7 because NGU is the tensioning with the higher force.
Revision 1.1.1.3.4.3 2019/10/04 14:18:20EEST Andreea Negrea (andreea.negrea) 
Add HWA implementation to manage request and response correctly.
Revision 1.1.1.3.4.2 2019/09/23 09:59:28EEST Andreea Negrea (andreea.negrea) 
Implementation of CIL
Revision 1.1.1.3.4.1 2019/09/09 15:43:16EEST Andreea Negrea (andreea.negrea) 
CIL Stubs for integration audi system extract
Revision 1.1.1.3 2017/04/13 16:40:59EEST Irina Caragea (irina.caragea) 
CIL integration
Revision 1.1.1.2 2017/02/24 10:47:34EET Michael Pastor (michael.pastor) 
MAJ PP4G R3.1E from Explo since 15/02/2017
Revision 1.3 2017/02/21 18:14:32CET Sabine Flechelle (sabine.flechelle) 
To correct compilation errors
Revision 1.2 2017/02/17 18:00:20CET Sabine Flechelle (sabine.flechelle) 
CAN typedef interfaces
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
Revision 1.7 2016/09/05 10:41:36CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove P R Q A
Revision 1.6 2016/09/05 10:02:11CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove all P R Q As
P R Q A is replaced by QAC_WARNING
Revision 1.5 2016/08/04 13:20:22CEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
Integration of issue 376449 (R2.3) to R3.0
Revision 1.4 2016/06/07 12:52:38CEST Audrey Vache (audrey.vache) 
Memory mapping implementation
Revision 1.3 2015/11/06 14:11:21CET Maxime Bourdon (mbourdon) 
Pass ATM Autotests calls through RTE + includes clean up
Revision 1.2 2015/11/03 10:21:40CET Maxime Bourdon (mbourdon) 
RTE files inclusion clean up
Revision 1.1 2015/10/13 15:52:55CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/_CIL/src/project.pj
Revision 1.28 2015/08/19 15:09:20CEST Sabine Flechelle (sflechelle) 
Issue 215817 - QAC corrections
Revision 1.27 2015/06/09 13:45:30CEST Sabine Flechelle (sflechelle) 
Issue 196827 - Rename Autosar Types and Scalings
Revision 1.26 2015/06/02 16:16:13CEST Sabine Flechelle (sflechelle) 
Issue 207763 - Very little corrections after code review
Revision 1.25 2015/04/17 16:42:53CEST Sebastien Claveau (sclaveau) 
Cover all "Car Cranking" related requirements (status change timing...)
Revision 1.24 2014/09/08 15:40:13CEST fgilbert 
Update of CIL
CAN types are defined in CIL file, generic platform types olny are defined in RTE
Revision 1.23 2014/09/01 16:31:50CEST Francois.Gilbert (fgilbert) 
Haptic requests managed into HWA module instead of CIL
Revision 1.22 2014/08/12 14:29:16CEST Francois.Gilbert (fgilbert) 
Quality improvement QAC_WARNING
Revision 1.21 2014/08/11 11:22:25CEST Francois.Gilbert (fgilbert) 
HWA requests managed by CIL
Revision 1.20 2014/07/24 17:32:18CEST Francois.Gilbert (fgilbert) 
HWA interfaces
Revision 1.19 2014/07/11 16:14:42CEST Francois.Gilbert (fgilbert) 
Provide HWA signals from CAN to HWA module
Revision 1.18 2014/06/25 18:31:32CEST Francois.Gilbert (fgilbert) 
Comments changed
Revision 1.17 2014/06/23 11:39:49CEST Sabine Flechelle (sflechelle) 
Issue_143099 - BSR enable CAN signal is transmitted to BSR algo
CIL output sender port Belt Slack Status has the scaling:
    If BSR enable CAN signal = 1, 
    then  Belt Slack Status = BELT SLACK ON = 1 
    else Belt Slack Status = BELT SLACK ON = 0
BSR is enabled when BSR enable CAN signal equals ON = 1, 
that is to say when  Belt Slack Status = BELT SLACK ON = 1.
Revision 1.16 2014/06/18 11:25:11CEST Francois.Gilbert (fgilbert) 
Measurement frames are activated without reset
Revision 1.15 2014/06/13 17:24:27CEST Francois.Gilbert (fgilbert) 
Standard ALV and functional measurement frames parameter setting in CIL_Init
Revision 1.14 2014/06/12 17:55:50CEST Francois.Gilbert (fgilbert) 
First correction from what was understood from peer review based on v1.9

 *************************************************************************/

/* end of file */


