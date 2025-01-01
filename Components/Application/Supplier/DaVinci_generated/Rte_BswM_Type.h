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
 *             File:  Rte_BswM_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application types header file for SW-C <BswM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_BSWM_TYPE_H
# define RTE_BSWM_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef RELEASED
#   define RELEASED (0U)
#  endif

#  ifndef REQUESTED
#   define REQUESTED (1U)
#  endif

#  ifndef STARTUP
#   define STARTUP (0U)
#  endif

#  ifndef RUN
#   define RUN (1U)
#  endif

#  ifndef POSTRUN
#   define POSTRUN (2U)
#  endif

#  ifndef WAKEUP
#   define WAKEUP (3U)
#  endif

#  ifndef SHUTDOWN
#   define SHUTDOWN (4U)
#  endif

#  ifndef RELEASED
#   define RELEASED (0U)
#  endif

#  ifndef REQUESTED
#   define REQUESTED (1U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_CommunicationMode
#  define RTE_MODETYPE_CommunicationMode
typedef uint8 Rte_ModeType_CommunicationMode;
# endif
# ifndef RTE_MODETYPE_ESH_KillAllRun
#  define RTE_MODETYPE_ESH_KillAllRun
typedef BswM_ESH_KillAllRun Rte_ModeType_ESH_KillAllRun;
# endif
# ifndef RTE_MODETYPE_ESH_Mode
#  define RTE_MODETYPE_ESH_Mode
typedef BswM_ESH_Mode Rte_ModeType_ESH_Mode;
# endif
# ifndef RTE_MODETYPE_ESH_RunRequest
#  define RTE_MODETYPE_ESH_RunRequest
typedef BswM_ESH_RunRequest Rte_ModeType_ESH_RunRequest;
# endif

# define RTE_MODE_BswM_CommunicationMode_COMM_NO_COMMUNICATION (0U)
# ifndef RTE_MODE_CommunicationMode_COMM_NO_COMMUNICATION
#  define RTE_MODE_CommunicationMode_COMM_NO_COMMUNICATION (0U)
# endif
# define RTE_MODE_BswM_CommunicationMode_COMM_SILENT_COMMUNICATION (1U)
# ifndef RTE_MODE_CommunicationMode_COMM_SILENT_COMMUNICATION
#  define RTE_MODE_CommunicationMode_COMM_SILENT_COMMUNICATION (1U)
# endif
# define RTE_MODE_BswM_CommunicationMode_COMM_FULL_COMMUNICATION (2U)
# ifndef RTE_MODE_CommunicationMode_COMM_FULL_COMMUNICATION
#  define RTE_MODE_CommunicationMode_COMM_FULL_COMMUNICATION (2U)
# endif
# define RTE_TRANSITION_BswM_CommunicationMode (3U)
# ifndef RTE_TRANSITION_CommunicationMode
#  define RTE_TRANSITION_CommunicationMode (3U)
# endif

# define RTE_MODE_BswM_ESH_KillAllRun_RELEASED (0U)
# ifndef RTE_MODE_ESH_KillAllRun_RELEASED
#  define RTE_MODE_ESH_KillAllRun_RELEASED (0U)
# endif
# define RTE_MODE_BswM_ESH_KillAllRun_REQUESTED (1U)
# ifndef RTE_MODE_ESH_KillAllRun_REQUESTED
#  define RTE_MODE_ESH_KillAllRun_REQUESTED (1U)
# endif
# define RTE_TRANSITION_BswM_ESH_KillAllRun (2U)
# ifndef RTE_TRANSITION_ESH_KillAllRun
#  define RTE_TRANSITION_ESH_KillAllRun (2U)
# endif

# define RTE_MODE_BswM_ESH_Mode_STARTUP (0U)
# ifndef RTE_MODE_ESH_Mode_STARTUP
#  define RTE_MODE_ESH_Mode_STARTUP (0U)
# endif
# define RTE_MODE_BswM_ESH_Mode_RUN (1U)
# ifndef RTE_MODE_ESH_Mode_RUN
#  define RTE_MODE_ESH_Mode_RUN (1U)
# endif
# define RTE_MODE_BswM_ESH_Mode_POSTRUN (2U)
# ifndef RTE_MODE_ESH_Mode_POSTRUN
#  define RTE_MODE_ESH_Mode_POSTRUN (2U)
# endif
# define RTE_MODE_BswM_ESH_Mode_WAKEUP (3U)
# ifndef RTE_MODE_ESH_Mode_WAKEUP
#  define RTE_MODE_ESH_Mode_WAKEUP (3U)
# endif
# define RTE_MODE_BswM_ESH_Mode_SHUTDOWN (4U)
# ifndef RTE_MODE_ESH_Mode_SHUTDOWN
#  define RTE_MODE_ESH_Mode_SHUTDOWN (4U)
# endif
# define RTE_TRANSITION_BswM_ESH_Mode (5U)
# ifndef RTE_TRANSITION_ESH_Mode
#  define RTE_TRANSITION_ESH_Mode (5U)
# endif

# define RTE_MODE_BswM_ESH_RunRequest_RELEASED (0U)
# ifndef RTE_MODE_ESH_RunRequest_RELEASED
#  define RTE_MODE_ESH_RunRequest_RELEASED (0U)
# endif
# define RTE_MODE_BswM_ESH_RunRequest_REQUESTED (1U)
# ifndef RTE_MODE_ESH_RunRequest_REQUESTED
#  define RTE_MODE_ESH_RunRequest_REQUESTED (1U)
# endif
# define RTE_TRANSITION_BswM_ESH_RunRequest (2U)
# ifndef RTE_TRANSITION_ESH_RunRequest
#  define RTE_TRANSITION_ESH_RunRequest (2U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_BSWM_TYPE_H */
