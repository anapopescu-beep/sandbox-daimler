/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Ssa_TimeM_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application types header file for SW-C <Ssa_TimeM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_TIMEM_TYPE_H
# define RTE_SSA_TIMEM_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef CODING_OK
#   define CODING_OK (0U)
#  endif

#  ifndef CODING_FAILED
#   define CODING_FAILED (1U)
#  endif

#  ifndef CODING_ACTIVE
#   define CODING_ACTIVE (2U)
#  endif

#  ifndef CODING_OK
#   define CODING_OK (0U)
#  endif

#  ifndef CODING_FAILED
#   define CODING_FAILED (1U)
#  endif

#  ifndef CODING_ACTIVE
#   define CODING_ACTIVE (2U)
#  endif

#  ifndef DCM_E_POSITIVERESPONSE
#   define DCM_E_POSITIVERESPONSE (0U)
#  endif

#  ifndef DCM_E_GENERALREJECT
#   define DCM_E_GENERALREJECT (16U)
#  endif

#  ifndef DCM_E_SERVICENOTSUPPORTED
#   define DCM_E_SERVICENOTSUPPORTED (17U)
#  endif

#  ifndef DCM_E_SUBFUNCTIONNOTSUPPORTED
#   define DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
#  endif

#  ifndef DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT
#   define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
#  endif

#  ifndef DCM_E_RESPONSETOOLONG
#   define DCM_E_RESPONSETOOLONG (20U)
#  endif

#  ifndef DCM_E_BUSYREPEATREQUEST
#   define DCM_E_BUSYREPEATREQUEST (33U)
#  endif

#  ifndef DCM_E_CONDITIONSNOTCORRECT
#   define DCM_E_CONDITIONSNOTCORRECT (34U)
#  endif

#  ifndef DCM_E_REQUESTSEQUENCEERROR
#   define DCM_E_REQUESTSEQUENCEERROR (36U)
#  endif

#  ifndef DCM_E_NORESPONSEFROMSUBNETCOMPONENT
#   define DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
#  endif

#  ifndef DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION
#   define DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
#  endif

#  ifndef DCM_E_REQUESTOUTOFRANGE
#   define DCM_E_REQUESTOUTOFRANGE (49U)
#  endif

#  ifndef DCM_E_SECURITYACCESSDENIED
#   define DCM_E_SECURITYACCESSDENIED (51U)
#  endif

#  ifndef DCM_E_INVALIDKEY
#   define DCM_E_INVALIDKEY (53U)
#  endif

#  ifndef DCM_E_EXCEEDNUMBEROFATTEMPTS
#   define DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
#  endif

#  ifndef DCM_E_REQUIREDTIMEDELAYNOTEXPIRED
#   define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
#  endif

#  ifndef DCM_E_UPLOADDOWNLOADNOTACCEPTED
#   define DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
#  endif

#  ifndef DCM_E_TRANSFERDATASUSPENDED
#   define DCM_E_TRANSFERDATASUSPENDED (113U)
#  endif

#  ifndef DCM_E_GENERALPROGRAMMINGFAILURE
#   define DCM_E_GENERALPROGRAMMINGFAILURE (114U)
#  endif

#  ifndef DCM_E_WRONGBLOCKSEQUENCECOUNTER
#   define DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
#  endif

#  ifndef DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING
#   define DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
#  endif

#  ifndef DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION
#   define DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
#  endif

#  ifndef DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION
#   define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
#  endif

#  ifndef DCM_E_RPMTOOHIGH
#   define DCM_E_RPMTOOHIGH (129U)
#  endif

#  ifndef DCM_E_RPMTOOLOW
#   define DCM_E_RPMTOOLOW (130U)
#  endif

#  ifndef DCM_E_ENGINEISRUNNING
#   define DCM_E_ENGINEISRUNNING (131U)
#  endif

#  ifndef DCM_E_ENGINEISNOTRUNNING
#   define DCM_E_ENGINEISNOTRUNNING (132U)
#  endif

#  ifndef DCM_E_ENGINERUNTIMETOOLOW
#   define DCM_E_ENGINERUNTIMETOOLOW (133U)
#  endif

#  ifndef DCM_E_TEMPERATURETOOHIGH
#   define DCM_E_TEMPERATURETOOHIGH (134U)
#  endif

#  ifndef DCM_E_TEMPERATURETOOLOW
#   define DCM_E_TEMPERATURETOOLOW (135U)
#  endif

#  ifndef DCM_E_VEHICLESPEEDTOOHIGH
#   define DCM_E_VEHICLESPEEDTOOHIGH (136U)
#  endif

#  ifndef DCM_E_VEHICLESPEEDTOOLOW
#   define DCM_E_VEHICLESPEEDTOOLOW (137U)
#  endif

#  ifndef DCM_E_THROTTLE_PEDALTOOHIGH
#   define DCM_E_THROTTLE_PEDALTOOHIGH (138U)
#  endif

#  ifndef DCM_E_THROTTLE_PEDALTOOLOW
#   define DCM_E_THROTTLE_PEDALTOOLOW (139U)
#  endif

#  ifndef DCM_E_TRANSMISSIONRANGENOTINNEUTRAL
#   define DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
#  endif

#  ifndef DCM_E_TRANSMISSIONRANGENOTINGEAR
#   define DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
#  endif

#  ifndef DCM_E_BRAKESWITCH_NOTCLOSED
#   define DCM_E_BRAKESWITCH_NOTCLOSED (143U)
#  endif

#  ifndef DCM_E_SHIFTERLEVERNOTINPARK
#   define DCM_E_SHIFTERLEVERNOTINPARK (144U)
#  endif

#  ifndef DCM_E_TORQUECONVERTERCLUTCHLOCKED
#   define DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
#  endif

#  ifndef DCM_E_VOLTAGETOOHIGH
#   define DCM_E_VOLTAGETOOHIGH (146U)
#  endif

#  ifndef DCM_E_VOLTAGETOOLOW
#   define DCM_E_VOLTAGETOOLOW (147U)
#  endif

#  ifndef DCM_E_VMSCNC_0
#   define DCM_E_VMSCNC_0 (240U)
#  endif

#  ifndef DCM_E_VMSCNC_1
#   define DCM_E_VMSCNC_1 (241U)
#  endif

#  ifndef DCM_E_VMSCNC_2
#   define DCM_E_VMSCNC_2 (242U)
#  endif

#  ifndef DCM_E_VMSCNC_3
#   define DCM_E_VMSCNC_3 (243U)
#  endif

#  ifndef DCM_E_VMSCNC_4
#   define DCM_E_VMSCNC_4 (244U)
#  endif

#  ifndef DCM_E_VMSCNC_5
#   define DCM_E_VMSCNC_5 (245U)
#  endif

#  ifndef DCM_E_VMSCNC_6
#   define DCM_E_VMSCNC_6 (246U)
#  endif

#  ifndef DCM_E_VMSCNC_7
#   define DCM_E_VMSCNC_7 (247U)
#  endif

#  ifndef DCM_E_VMSCNC_8
#   define DCM_E_VMSCNC_8 (248U)
#  endif

#  ifndef DCM_E_VMSCNC_9
#   define DCM_E_VMSCNC_9 (249U)
#  endif

#  ifndef DCM_E_VMSCNC_A
#   define DCM_E_VMSCNC_A (250U)
#  endif

#  ifndef DCM_E_VMSCNC_B
#   define DCM_E_VMSCNC_B (251U)
#  endif

#  ifndef DCM_E_VMSCNC_C
#   define DCM_E_VMSCNC_C (252U)
#  endif

#  ifndef DCM_E_VMSCNC_D
#   define DCM_E_VMSCNC_D (253U)
#  endif

#  ifndef DCM_E_VMSCNC_E
#   define DCM_E_VMSCNC_E (254U)
#  endif

#  ifndef DCM_INITIAL
#   define DCM_INITIAL (0U)
#  endif

#  ifndef DCM_PENDING
#   define DCM_PENDING (1U)
#  endif

#  ifndef DCM_CANCEL
#   define DCM_CANCEL (2U)
#  endif

#  ifndef DCM_FORCE_RCRRP_OK
#   define DCM_FORCE_RCRRP_OK (3U)
#  endif

#  ifndef DCM_FORCE_RCRRP_NOT_OK
#   define DCM_FORCE_RCRRP_NOT_OK (64U)
#  endif

#  ifndef DEM_EVENT_STATUS_PASSED
#   define DEM_EVENT_STATUS_PASSED (0U)
#  endif

#  ifndef DEM_EVENT_STATUS_FAILED
#   define DEM_EVENT_STATUS_FAILED (1U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREPASSED
#   define DEM_EVENT_STATUS_PREPASSED (2U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREFAILED
#   define DEM_EVENT_STATUS_PREFAILED (3U)
#  endif

#  ifndef DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED
#   define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
#  endif

#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif

#  ifndef RIGHTSM_UNAUTHENTICATED
#   define RIGHTSM_UNAUTHENTICATED (0U)
#  endif

#  ifndef RIGHTSM_AUTHENTICATED
#   define RIGHTSM_AUTHENTICATED (1U)
#  endif

#  ifndef SSA_CHANGETICKCOUNTEVENTID_ACCEPTED
#   define SSA_CHANGETICKCOUNTEVENTID_ACCEPTED (0U)
#  endif

#  ifndef SSA_CHANGETICKCOUNTEVENTID_ACCEPTED_THRESHOLD_EXCEEDED
#   define SSA_CHANGETICKCOUNTEVENTID_ACCEPTED_THRESHOLD_EXCEEDED (1U)
#  endif

#  ifndef SSA_CHANGETICKCOUNTEVENTID_REJECTED
#   define SSA_CHANGETICKCOUNTEVENTID_REJECTED (2U)
#  endif

#  ifndef SSA_CHANGETICKCOUNTEVENTID_ERROR_TIMEOUT
#   define SSA_CHANGETICKCOUNTEVENTID_ERROR_TIMEOUT (3U)
#  endif

#  ifndef SSA_CHANGETICKCOUNTEVENTID_UNDEFINED
#   define SSA_CHANGETICKCOUNTEVENTID_UNDEFINED (4U)
#  endif

#  ifndef SSA_STATE_OFF
#   define SSA_STATE_OFF (0U)
#  endif

#  ifndef SSA_STATE_ON
#   define SSA_STATE_ON (1U)
#  endif

#  ifndef SSA_ACTIVE
#   define SSA_ACTIVE (0U)
#  endif

#  ifndef SSA_INACTIVE
#   define SSA_INACTIVE (1U)
#  endif

#  define InvalidValue_Ssa_PowernetMgmtStateType (7U)

#  ifndef I_C03_PN14_TDP_SW_STAT_CLS
#   define I_C03_PN14_TDP_SW_STAT_CLS (0U)
#  endif

#  ifndef I_C03_PN14_TDP_SW_STAT_PRE_RESET
#   define I_C03_PN14_TDP_SW_STAT_PRE_RESET (1U)
#  endif

#  ifndef I_C03_PN14_TDP_SW_STAT_RESET
#   define I_C03_PN14_TDP_SW_STAT_RESET (2U)
#  endif

#  ifndef I_C03_PN14_TDP_SW_STAT_PRE_OPN
#   define I_C03_PN14_TDP_SW_STAT_PRE_OPN (3U)
#  endif

#  ifndef I_C03_PN14_TDP_SW_STAT_OPN
#   define I_C03_PN14_TDP_SW_STAT_OPN (4U)
#  endif

#  ifndef I_C03_PN14_TDP_SW_STAT_SNA
#   define I_C03_PN14_TDP_SW_STAT_SNA (7U)
#  endif

#  ifndef SSA_TICKCOUNT_SYNC_STATE_NOT_SYNCHRONIZED
#   define SSA_TICKCOUNT_SYNC_STATE_NOT_SYNCHRONIZED (0U)
#  endif

#  ifndef SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_MASTER
#   define SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_MASTER (1U)
#  endif

#  ifndef SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_VSM
#   define SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_VSM (2U)
#  endif

#  ifndef TIMEM_IS_GREATER
#   define TIMEM_IS_GREATER (0U)
#  endif

#  ifndef TIMEM_IS_LESS
#   define TIMEM_IS_LESS (1U)
#  endif

#  ifndef TIMEM_REALTIMECHANGEREASON_NOTBEFORE
#   define TIMEM_REALTIMECHANGEREASON_NOTBEFORE (0U)
#  endif

#  ifndef TIMEM_REALTIMECHANGEREASON_NONCE
#   define TIMEM_REALTIMECHANGEREASON_NONCE (1U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_Coding_MemoryStatus
#  define RTE_MODETYPE_Coding_MemoryStatus
typedef Coding_MemoryStatusType Rte_ModeType_Coding_MemoryStatus;
# endif
# ifndef RTE_MODETYPE_Coding_Mode
#  define RTE_MODETYPE_Coding_Mode
typedef Coding_ModeType Rte_ModeType_Coding_Mode;
# endif
# ifndef RTE_MODETYPE_DcmDiagnosticSessionControl
#  define RTE_MODETYPE_DcmDiagnosticSessionControl
typedef Dcm_DiagnosticSessionControlType Rte_ModeType_DcmDiagnosticSessionControl;
# endif
# ifndef RTE_MODETYPE_RightsM_AuthenticationMode
#  define RTE_MODETYPE_RightsM_AuthenticationMode
typedef RightsM_AuthenticationModeType Rte_ModeType_RightsM_AuthenticationMode;
# endif
# ifndef RTE_MODETYPE_Ssa_MacKeyGeneration_State
#  define RTE_MODETYPE_Ssa_MacKeyGeneration_State
typedef Ssa_OnOff_StateType Rte_ModeType_Ssa_MacKeyGeneration_State;
# endif
# ifndef RTE_MODETYPE_Ssa_OperationMode
#  define RTE_MODETYPE_Ssa_OperationMode
typedef Ssa_OperationModeType Rte_ModeType_Ssa_OperationMode;
# endif

# define RTE_MODE_Ssa_TimeM_Coding_MemoryStatus_CODING_MEMSTAT_FAILED (0U)
# ifndef RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_FAILED
#  define RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_FAILED (0U)
# endif
# define RTE_MODE_Ssa_TimeM_Coding_MemoryStatus_CODING_MEMSTAT_OK (1U)
# ifndef RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_OK
#  define RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_OK (1U)
# endif
# define RTE_MODE_Ssa_TimeM_Coding_MemoryStatus_CODING_MEMSTAT_PENDING (2U)
# ifndef RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_PENDING
#  define RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_PENDING (2U)
# endif
# define RTE_TRANSITION_Ssa_TimeM_Coding_MemoryStatus (3U)
# ifndef RTE_TRANSITION_Coding_MemoryStatus
#  define RTE_TRANSITION_Coding_MemoryStatus (3U)
# endif

# define RTE_MODE_Ssa_TimeM_Coding_Mode_CODING_ACTIVE (0U)
# ifndef RTE_MODE_Coding_Mode_CODING_ACTIVE
#  define RTE_MODE_Coding_Mode_CODING_ACTIVE (0U)
# endif
# define RTE_MODE_Ssa_TimeM_Coding_Mode_CODING_FAILED (1U)
# ifndef RTE_MODE_Coding_Mode_CODING_FAILED
#  define RTE_MODE_Coding_Mode_CODING_FAILED (1U)
# endif
# define RTE_MODE_Ssa_TimeM_Coding_Mode_CODING_OK (2U)
# ifndef RTE_MODE_Coding_Mode_CODING_OK
#  define RTE_MODE_Coding_Mode_CODING_OK (2U)
# endif
# define RTE_TRANSITION_Ssa_TimeM_Coding_Mode (3U)
# ifndef RTE_TRANSITION_Coding_Mode
#  define RTE_TRANSITION_Coding_Mode (3U)
# endif

# define RTE_MODE_Ssa_TimeM_DcmDiagnosticSessionControl_DEFAULT_SESSION (1U)
# ifndef RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION (1U)
# endif
# define RTE_MODE_Ssa_TimeM_DcmDiagnosticSessionControl_PROGRAMMING_SESSION (2U)
# ifndef RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION (2U)
# endif
# define RTE_MODE_Ssa_TimeM_DcmDiagnosticSessionControl_EXTENDED_SESSION (3U)
# ifndef RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION (3U)
# endif
# define RTE_MODE_Ssa_TimeM_DcmDiagnosticSessionControl_Development (126U)
# ifndef RTE_MODE_DcmDiagnosticSessionControl_Development
#  define RTE_MODE_DcmDiagnosticSessionControl_Development (126U)
# endif
# define RTE_TRANSITION_Ssa_TimeM_DcmDiagnosticSessionControl (255U)
# ifndef RTE_TRANSITION_DcmDiagnosticSessionControl
#  define RTE_TRANSITION_DcmDiagnosticSessionControl (255U)
# endif

# define RTE_MODE_Ssa_TimeM_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED (0U)
# ifndef RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED
#  define RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED (0U)
# endif
# define RTE_MODE_Ssa_TimeM_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED (1U)
# ifndef RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED
#  define RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED (1U)
# endif
# define RTE_TRANSITION_Ssa_TimeM_RightsM_AuthenticationMode (2U)
# ifndef RTE_TRANSITION_RightsM_AuthenticationMode
#  define RTE_TRANSITION_RightsM_AuthenticationMode (2U)
# endif

# define RTE_MODE_Ssa_TimeM_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_OFF (0U)
# ifndef RTE_MODE_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_OFF
#  define RTE_MODE_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_OFF (0U)
# endif
# define RTE_MODE_Ssa_TimeM_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_ON (1U)
# ifndef RTE_MODE_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_ON
#  define RTE_MODE_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_ON (1U)
# endif
# define RTE_TRANSITION_Ssa_TimeM_Ssa_MacKeyGeneration_State (2U)
# ifndef RTE_TRANSITION_Ssa_MacKeyGeneration_State
#  define RTE_TRANSITION_Ssa_MacKeyGeneration_State (2U)
# endif

# define RTE_MODE_Ssa_TimeM_Ssa_OperationMode_SSA_ACTIVE (0U)
# ifndef RTE_MODE_Ssa_OperationMode_SSA_ACTIVE
#  define RTE_MODE_Ssa_OperationMode_SSA_ACTIVE (0U)
# endif
# define RTE_MODE_Ssa_TimeM_Ssa_OperationMode_SSA_INACTIVE (1U)
# ifndef RTE_MODE_Ssa_OperationMode_SSA_INACTIVE
#  define RTE_MODE_Ssa_OperationMode_SSA_INACTIVE (1U)
# endif
# define RTE_TRANSITION_Ssa_TimeM_Ssa_OperationMode (2U)
# ifndef RTE_TRANSITION_Ssa_OperationMode
#  define RTE_TRANSITION_Ssa_OperationMode (2U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_TIMEM_TYPE_H */
