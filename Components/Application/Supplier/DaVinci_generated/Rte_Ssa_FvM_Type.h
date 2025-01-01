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
 *             File:  Rte_Ssa_FvM_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application types header file for SW-C <Ssa_FvM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_FVM_TYPE_H
# define RTE_SSA_FVM_TYPE_H

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

# define RTE_MODE_Ssa_FvM_Coding_MemoryStatus_CODING_MEMSTAT_FAILED (0U)
# ifndef RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_FAILED
#  define RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_FAILED (0U)
# endif
# define RTE_MODE_Ssa_FvM_Coding_MemoryStatus_CODING_MEMSTAT_OK (1U)
# ifndef RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_OK
#  define RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_OK (1U)
# endif
# define RTE_MODE_Ssa_FvM_Coding_MemoryStatus_CODING_MEMSTAT_PENDING (2U)
# ifndef RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_PENDING
#  define RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_PENDING (2U)
# endif
# define RTE_TRANSITION_Ssa_FvM_Coding_MemoryStatus (3U)
# ifndef RTE_TRANSITION_Coding_MemoryStatus
#  define RTE_TRANSITION_Coding_MemoryStatus (3U)
# endif

# define RTE_MODE_Ssa_FvM_Coding_Mode_CODING_ACTIVE (0U)
# ifndef RTE_MODE_Coding_Mode_CODING_ACTIVE
#  define RTE_MODE_Coding_Mode_CODING_ACTIVE (0U)
# endif
# define RTE_MODE_Ssa_FvM_Coding_Mode_CODING_FAILED (1U)
# ifndef RTE_MODE_Coding_Mode_CODING_FAILED
#  define RTE_MODE_Coding_Mode_CODING_FAILED (1U)
# endif
# define RTE_MODE_Ssa_FvM_Coding_Mode_CODING_OK (2U)
# ifndef RTE_MODE_Coding_Mode_CODING_OK
#  define RTE_MODE_Coding_Mode_CODING_OK (2U)
# endif
# define RTE_TRANSITION_Ssa_FvM_Coding_Mode (3U)
# ifndef RTE_TRANSITION_Coding_Mode
#  define RTE_TRANSITION_Coding_Mode (3U)
# endif

# define RTE_MODE_Ssa_FvM_DcmDiagnosticSessionControl_DEFAULT_SESSION (1U)
# ifndef RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION (1U)
# endif
# define RTE_MODE_Ssa_FvM_DcmDiagnosticSessionControl_PROGRAMMING_SESSION (2U)
# ifndef RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION (2U)
# endif
# define RTE_MODE_Ssa_FvM_DcmDiagnosticSessionControl_EXTENDED_SESSION (3U)
# ifndef RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION (3U)
# endif
# define RTE_MODE_Ssa_FvM_DcmDiagnosticSessionControl_Development (126U)
# ifndef RTE_MODE_DcmDiagnosticSessionControl_Development
#  define RTE_MODE_DcmDiagnosticSessionControl_Development (126U)
# endif
# define RTE_TRANSITION_Ssa_FvM_DcmDiagnosticSessionControl (255U)
# ifndef RTE_TRANSITION_DcmDiagnosticSessionControl
#  define RTE_TRANSITION_DcmDiagnosticSessionControl (255U)
# endif

# define RTE_MODE_Ssa_FvM_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED (0U)
# ifndef RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED
#  define RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED (0U)
# endif
# define RTE_MODE_Ssa_FvM_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED (1U)
# ifndef RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED
#  define RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED (1U)
# endif
# define RTE_TRANSITION_Ssa_FvM_RightsM_AuthenticationMode (2U)
# ifndef RTE_TRANSITION_RightsM_AuthenticationMode
#  define RTE_TRANSITION_RightsM_AuthenticationMode (2U)
# endif

# define RTE_MODE_Ssa_FvM_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_OFF (0U)
# ifndef RTE_MODE_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_OFF
#  define RTE_MODE_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_OFF (0U)
# endif
# define RTE_MODE_Ssa_FvM_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_ON (1U)
# ifndef RTE_MODE_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_ON
#  define RTE_MODE_Ssa_MacKeyGeneration_State_SSA_MAC_KEY_GEN_STATE_ON (1U)
# endif
# define RTE_TRANSITION_Ssa_FvM_Ssa_MacKeyGeneration_State (2U)
# ifndef RTE_TRANSITION_Ssa_MacKeyGeneration_State
#  define RTE_TRANSITION_Ssa_MacKeyGeneration_State (2U)
# endif

# define RTE_MODE_Ssa_FvM_Ssa_OperationMode_SSA_ACTIVE (0U)
# ifndef RTE_MODE_Ssa_OperationMode_SSA_ACTIVE
#  define RTE_MODE_Ssa_OperationMode_SSA_ACTIVE (0U)
# endif
# define RTE_MODE_Ssa_FvM_Ssa_OperationMode_SSA_INACTIVE (1U)
# ifndef RTE_MODE_Ssa_OperationMode_SSA_INACTIVE
#  define RTE_MODE_Ssa_OperationMode_SSA_INACTIVE (1U)
# endif
# define RTE_TRANSITION_Ssa_FvM_Ssa_OperationMode (2U)
# ifndef RTE_TRANSITION_Ssa_OperationMode
#  define RTE_TRANSITION_Ssa_OperationMode (2U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_FVM_TYPE_H */
