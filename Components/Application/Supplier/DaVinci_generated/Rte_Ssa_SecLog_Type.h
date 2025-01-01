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
 *             File:  Rte_Ssa_SecLog_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application types header file for SW-C <Ssa_SecLog>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_SECLOG_TYPE_H
# define RTE_SSA_SECLOG_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef CERTP_PKI_ROLE_ROOT
#   define CERTP_PKI_ROLE_ROOT (1U)
#  endif

#  ifndef CERTP_PKI_ROLE_BACKEND
#   define CERTP_PKI_ROLE_BACKEND (2U)
#  endif

#  ifndef CERTP_PKI_ROLE_TESTER
#   define CERTP_PKI_ROLE_TESTER (3U)
#  endif

#  ifndef CERTP_PKI_ROLE_ECU
#   define CERTP_PKI_ROLE_ECU (4U)
#  endif

#  ifndef CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS
#   define CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS (5U)
#  endif

#  ifndef CERTP_PKI_ROLE_VARIANT_CODING
#   define CERTP_PKI_ROLE_VARIANT_CODING (7U)
#  endif

#  ifndef CERTP_PKI_ROLE_USER_CERT_FOR_CODING
#   define CERTP_PKI_ROLE_USER_CERT_FOR_CODING (9U)
#  endif

#  ifndef CERTP_PKI_ROLE_ROOT_CA_LINK_CERT
#   define CERTP_PKI_ROLE_ROOT_CA_LINK_CERT (10U)
#  endif

#  ifndef CERTP_PKI_ROLE_BACKEND_CA_LINK_CERT
#   define CERTP_PKI_ROLE_BACKEND_CA_LINK_CERT (11U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA
#   define CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA (12U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA
#   define CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA (13U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA
#   define CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA (14U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_ECU
#   define CERTP_PKI_ROLE_TRUST_MODEL_ECU (15U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA_LINK
#   define CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA_LINK (16U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA_LINK
#   define CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA_LINK (17U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA_LINK
#   define CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA_LINK (18U)
#  endif

#  ifndef CERTP_PKI_ROLE_PQC_ROOT_CA
#   define CERTP_PKI_ROLE_PQC_ROOT_CA (19U)
#  endif

#  ifndef CERTP_PKI_ROLE_PQC_BACKEND_CA
#   define CERTP_PKI_ROLE_PQC_BACKEND_CA (20U)
#  endif

#  ifndef CERTP_PKI_ROLE_PQC_TESTER
#   define CERTP_PKI_ROLE_PQC_TESTER (21U)
#  endif

#  ifndef CERTP_PKI_ROLE_PQC_ECU
#   define CERTP_PKI_ROLE_PQC_ECU (22U)
#  endif

#  ifndef CERTP_PKI_ROLE_INVALID
#   define CERTP_PKI_ROLE_INVALID (0U)
#  endif

#  ifndef CERTP_VER_OK
#   define CERTP_VER_OK (0U)
#  endif

#  ifndef CERTP_VER_INVALID_TIME_PERIOD
#   define CERTP_VER_INVALID_TIME_PERIOD (16U)
#  endif

#  ifndef CERTP_VER_INVALID_SIGNATURE
#   define CERTP_VER_INVALID_SIGNATURE (17U)
#  endif

#  ifndef CERTP_VER_INVALID_CHAIN_OF_TRUST
#   define CERTP_VER_INVALID_CHAIN_OF_TRUST (18U)
#  endif

#  ifndef CERTP_VER_INVALID_TYPE
#   define CERTP_VER_INVALID_TYPE (19U)
#  endif

#  ifndef CERTP_VER_INVALID_FORMAT
#   define CERTP_VER_INVALID_FORMAT (20U)
#  endif

#  ifndef CERTP_VER_INVALID_CONTENT
#   define CERTP_VER_INVALID_CONTENT (21U)
#  endif

#  ifndef CERTP_VER_INVALID_SCOPE
#   define CERTP_VER_INVALID_SCOPE (22U)
#  endif

#  ifndef CERTP_VER_SYNCHRONIZE_TIME_FAILED_NONCE_NOT_ACCEPTED
#   define CERTP_VER_SYNCHRONIZE_TIME_FAILED_NONCE_NOT_ACCEPTED (64U)
#  endif

#  ifndef CERTP_VER_PARSE_OK
#   define CERTP_VER_PARSE_OK (253U)
#  endif

#  ifndef CERTP_VER_PARSE_FAILED
#   define CERTP_VER_PARSE_FAILED (254U)
#  endif

#  ifndef CERTP_VER_NOT_PARSED
#   define CERTP_VER_NOT_PARSED (255U)
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

#  ifndef DEM_INIT_MONITOR_CLEAR
#   define DEM_INIT_MONITOR_CLEAR (1U)
#  endif

#  ifndef DEM_INIT_MONITOR_RESTART
#   define DEM_INIT_MONITOR_RESTART (2U)
#  endif

#  ifndef DEM_INIT_MONITOR_REENABLED
#   define DEM_INIT_MONITOR_REENABLED (3U)
#  endif

#  ifndef DEM_INIT_MONITOR_STORAGE_REENABLED
#   define DEM_INIT_MONITOR_STORAGE_REENABLED (4U)
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

#  ifndef SECOC_VERIFICATIONSUCCESS
#   define SECOC_VERIFICATIONSUCCESS (0U)
#  endif

#  ifndef SECOC_VERIFICATIONFAILURE
#   define SECOC_VERIFICATIONFAILURE (1U)
#  endif

#  ifndef SECOC_FRESHNESSFAILURE
#   define SECOC_FRESHNESSFAILURE (2U)
#  endif

#  ifndef SECOC_AUTHENTICATIONBUILDFAILURE
#   define SECOC_AUTHENTICATIONBUILDFAILURE (3U)
#  endif

#  ifndef SECOC_NO_VERIFICATION
#   define SECOC_NO_VERIFICATION (4U)
#  endif

#  ifndef SECOC_VERIFICATIONFAILURE_OVERWRITTEN
#   define SECOC_VERIFICATIONFAILURE_OVERWRITTEN (5U)
#  endif

#  define InvalidValue_Ssa_IgnitionStatus_Prim (7U)

#  ifndef I_C03_ISW_STAT_IGN_LOCK
#   define I_C03_ISW_STAT_IGN_LOCK (0U)
#  endif

#  ifndef I_C03_ISW_STAT_IGN_OFF
#   define I_C03_ISW_STAT_IGN_OFF (1U)
#  endif

#  ifndef I_C03_ISW_STAT_IGN_ACC
#   define I_C03_ISW_STAT_IGN_ACC (2U)
#  endif

#  ifndef I_C03_ISW_STAT_IGN_ON
#   define I_C03_ISW_STAT_IGN_ON (4U)
#  endif

#  ifndef I_C03_ISW_STAT_IGN_START
#   define I_C03_ISW_STAT_IGN_START (5U)
#  endif

#  ifndef I_C03_ISW_STAT_SNA
#   define I_C03_ISW_STAT_SNA (7U)
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

#  ifndef SSA_THRESHOLD_EXCEEDED_NONE
#   define SSA_THRESHOLD_EXCEEDED_NONE (0U)
#  endif

#  ifndef SSA_THRESHOLD_EXCEEDED_TH1
#   define SSA_THRESHOLD_EXCEEDED_TH1 (1U)
#  endif

#  ifndef SSA_THRESHOLD_EXCEEDED_TH2
#   define SSA_THRESHOLD_EXCEEDED_TH2 (2U)
#  endif

#  ifndef SSA_THRESHOLD_EXCEEDED_TH3
#   define SSA_THRESHOLD_EXCEEDED_TH3 (3U)
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

# define RTE_MODE_Ssa_SecLog_Coding_MemoryStatus_CODING_MEMSTAT_FAILED (0U)
# ifndef RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_FAILED
#  define RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_FAILED (0U)
# endif
# define RTE_MODE_Ssa_SecLog_Coding_MemoryStatus_CODING_MEMSTAT_OK (1U)
# ifndef RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_OK
#  define RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_OK (1U)
# endif
# define RTE_MODE_Ssa_SecLog_Coding_MemoryStatus_CODING_MEMSTAT_PENDING (2U)
# ifndef RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_PENDING
#  define RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_PENDING (2U)
# endif
# define RTE_TRANSITION_Ssa_SecLog_Coding_MemoryStatus (3U)
# ifndef RTE_TRANSITION_Coding_MemoryStatus
#  define RTE_TRANSITION_Coding_MemoryStatus (3U)
# endif

# define RTE_MODE_Ssa_SecLog_Coding_Mode_CODING_ACTIVE (0U)
# ifndef RTE_MODE_Coding_Mode_CODING_ACTIVE
#  define RTE_MODE_Coding_Mode_CODING_ACTIVE (0U)
# endif
# define RTE_MODE_Ssa_SecLog_Coding_Mode_CODING_FAILED (1U)
# ifndef RTE_MODE_Coding_Mode_CODING_FAILED
#  define RTE_MODE_Coding_Mode_CODING_FAILED (1U)
# endif
# define RTE_MODE_Ssa_SecLog_Coding_Mode_CODING_OK (2U)
# ifndef RTE_MODE_Coding_Mode_CODING_OK
#  define RTE_MODE_Coding_Mode_CODING_OK (2U)
# endif
# define RTE_TRANSITION_Ssa_SecLog_Coding_Mode (3U)
# ifndef RTE_TRANSITION_Coding_Mode
#  define RTE_TRANSITION_Coding_Mode (3U)
# endif

# define RTE_MODE_Ssa_SecLog_DcmDiagnosticSessionControl_DEFAULT_SESSION (1U)
# ifndef RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION (1U)
# endif
# define RTE_MODE_Ssa_SecLog_DcmDiagnosticSessionControl_PROGRAMMING_SESSION (2U)
# ifndef RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION (2U)
# endif
# define RTE_MODE_Ssa_SecLog_DcmDiagnosticSessionControl_EXTENDED_SESSION (3U)
# ifndef RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION (3U)
# endif
# define RTE_MODE_Ssa_SecLog_DcmDiagnosticSessionControl_Development (126U)
# ifndef RTE_MODE_DcmDiagnosticSessionControl_Development
#  define RTE_MODE_DcmDiagnosticSessionControl_Development (126U)
# endif
# define RTE_TRANSITION_Ssa_SecLog_DcmDiagnosticSessionControl (255U)
# ifndef RTE_TRANSITION_DcmDiagnosticSessionControl
#  define RTE_TRANSITION_DcmDiagnosticSessionControl (255U)
# endif

# define RTE_MODE_Ssa_SecLog_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED (0U)
# ifndef RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED
#  define RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED (0U)
# endif
# define RTE_MODE_Ssa_SecLog_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED (1U)
# ifndef RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED
#  define RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED (1U)
# endif
# define RTE_TRANSITION_Ssa_SecLog_RightsM_AuthenticationMode (2U)
# ifndef RTE_TRANSITION_RightsM_AuthenticationMode
#  define RTE_TRANSITION_RightsM_AuthenticationMode (2U)
# endif

# define RTE_MODE_Ssa_SecLog_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_OFF (0U)
# ifndef RTE_MODE_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_OFF
#  define RTE_MODE_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_OFF (0U)
# endif
# define RTE_MODE_Ssa_SecLog_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_ON (1U)
# ifndef RTE_MODE_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_ON
#  define RTE_MODE_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_ON (1U)
# endif
# define RTE_TRANSITION_Ssa_SecLog_Ssa_MacKeyGeneration_State (2U)
# ifndef RTE_TRANSITION_Ssa_MacKeyGeneration_State
#  define RTE_TRANSITION_Ssa_MacKeyGeneration_State (2U)
# endif

# define RTE_MODE_Ssa_SecLog_Ssa_OperationMode_SSA_ACTIVE (0U)
# ifndef RTE_MODE_Ssa_OperationMode_SSA_ACTIVE
#  define RTE_MODE_Ssa_OperationMode_SSA_ACTIVE (0U)
# endif
# define RTE_MODE_Ssa_SecLog_Ssa_OperationMode_SSA_INACTIVE (1U)
# ifndef RTE_MODE_Ssa_OperationMode_SSA_INACTIVE
#  define RTE_MODE_Ssa_OperationMode_SSA_INACTIVE (1U)
# endif
# define RTE_TRANSITION_Ssa_SecLog_Ssa_OperationMode (2U)
# ifndef RTE_TRANSITION_Ssa_OperationMode
#  define RTE_TRANSITION_Ssa_OperationMode (2U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_SECLOG_TYPE_H */
