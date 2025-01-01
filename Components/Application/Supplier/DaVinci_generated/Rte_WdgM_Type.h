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
 *             File:  Rte_WdgM_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application types header file for SW-C <WdgM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_WDGM_TYPE_H
# define RTE_WDGM_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef SUPERVISION_OK
#   define SUPERVISION_OK (0U)
#  endif

#  ifndef SUPERVISION_FAILED
#   define SUPERVISION_FAILED (1U)
#  endif

#  ifndef SUPERVISION_EXPIRED
#   define SUPERVISION_EXPIRED (2U)
#  endif

#  ifndef SUPERVISION_STOPPED
#   define SUPERVISION_STOPPED (3U)
#  endif

#  ifndef SUPERVISION_DEACTIVATED
#   define SUPERVISION_DEACTIVATED (4U)
#  endif

#  ifndef WDGM_GLOBAL_STATUS_OK
#   define WDGM_GLOBAL_STATUS_OK (0U)
#  endif

#  ifndef WDGM_GLOBAL_STATUS_FAILED
#   define WDGM_GLOBAL_STATUS_FAILED (1U)
#  endif

#  ifndef WDGM_GLOBAL_STATUS_EXPIRED
#   define WDGM_GLOBAL_STATUS_EXPIRED (2U)
#  endif

#  ifndef WDGM_GLOBAL_STATUS_STOPPED
#   define WDGM_GLOBAL_STATUS_STOPPED (3U)
#  endif

#  ifndef WDGM_GLOBAL_STATUS_DEACTIVATED
#   define WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
#  endif

#  ifndef WDGM_LOCAL_STATUS_OK
#   define WDGM_LOCAL_STATUS_OK (0U)
#  endif

#  ifndef WDGM_LOCAL_STATUS_FAILED
#   define WDGM_LOCAL_STATUS_FAILED (1U)
#  endif

#  ifndef WDGM_LOCAL_STATUS_EXPIRED
#   define WDGM_LOCAL_STATUS_EXPIRED (2U)
#  endif

#  ifndef WDGM_LOCAL_STATUS_DEACTIVATED
#   define WDGM_LOCAL_STATUS_DEACTIVATED (4U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_WdgM_Mode
#  define RTE_MODETYPE_WdgM_Mode
typedef WdgMMode Rte_ModeType_WdgM_Mode;
# endif

# define RTE_MODE_WdgM_WdgM_Mode_SUPERVISION_OK (0U)
# ifndef RTE_MODE_WdgM_Mode_SUPERVISION_OK
#  define RTE_MODE_WdgM_Mode_SUPERVISION_OK (0U)
# endif
# define RTE_MODE_WdgM_WdgM_Mode_SUPERVISION_FAILED (1U)
# ifndef RTE_MODE_WdgM_Mode_SUPERVISION_FAILED
#  define RTE_MODE_WdgM_Mode_SUPERVISION_FAILED (1U)
# endif
# define RTE_MODE_WdgM_WdgM_Mode_SUPERVISION_EXPIRED (2U)
# ifndef RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED
#  define RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED (2U)
# endif
# define RTE_MODE_WdgM_WdgM_Mode_SUPERVISION_STOPPED (3U)
# ifndef RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED
#  define RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED (3U)
# endif
# define RTE_MODE_WdgM_WdgM_Mode_SUPERVISION_DEACTIVATED (4U)
# ifndef RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED
#  define RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED (4U)
# endif
# define RTE_TRANSITION_WdgM_WdgM_Mode (255U)
# ifndef RTE_TRANSITION_WdgM_Mode
#  define RTE_TRANSITION_WdgM_Mode (255U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_WDGM_TYPE_H */
