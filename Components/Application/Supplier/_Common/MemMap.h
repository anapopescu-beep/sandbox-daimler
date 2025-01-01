/********************************************************************************************************************** 
 *  COPYRIGHT 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  Copyright (c) 2020 by Mercedes Benz AG - Alle Rechte vorbehalten -  All rights reserved. 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  EXAMPLE CODE ONLY 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW 
 *  configuration. The Example Code has not passed any quality control measures and may be incomplete. The 
 *  Example Code is neither intended nor qualified for use in series production. The Example Code as well 
 *  as any of its modifications and/or implementations must be tested with diligent care and must comply 
 *  with all quality requirements which are necessary according to the state of the art before their use. 
 * 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  FILE DESCRIPTION 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  File: MemMap.h
 *  Description: This is the sample implementation of the memory map header file.
 *                 
 *********************************************************************************************************************/

 /* PRQA S 0883 1 */ /* MD_MemMap_19.15 */
#undef MEMMAP_VENDOR_ID /* PRQA S 0841 */ /* MD_MSR_19.6 */

#define MEMMAP_VENDOR_ID        (30u)

/* AUTOSAR Software Specification Version Information */


# undef MEMMAP_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_REVISION_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

/* AUTOSAR release 4.0 R3 */
# define MEMMAP_AR_RELEASE_MAJOR_VERSION       (4u)
# define MEMMAP_AR_RELEASE_MINOR_VERSION       (0u)
# define MEMMAP_AR_RELEASE_REVISION_VERSION    (3u)

/* compatiblity to older versions */
# undef MEM_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_AR_RELEASE_MAJOR_VERSION          MEMMAP_AR_RELEASE_MAJOR_VERSION
# define MEM_AR_RELEASE_MINOR_VERSION          MEMMAP_AR_RELEASE_MINOR_VERSION
# define MEM_AR_RELEASE_PATCH_VERSION          MEMMAP_AR_RELEASE_REVISION_VERSION


# undef MEMMAP_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEMMAP_SW_MAJOR_VERSION     (2u)
# define MEMMAP_SW_MINOR_VERSION     (1u)
# define MEMMAP_SW_PATCH_VERSION     (1u)

/* compatiblity to older versions */
# undef MEM_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_SW_MAJOR_VERSION        MEMMAP_SW_MAJOR_VERSION
# define MEM_SW_MINOR_VERSION        MEMMAP_SW_MINOR_VERSION
# define MEM_SW_PATCH_VERSION        MEMMAP_SW_PATCH_VERSION

#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */
//#include "Rte_MemMap.h"

#include "MemMap_MSR4_MBP.h"
#include "MemMap_MSR4_MCP.h"
#include "MemMap_MSR4_MEP.h"
#include "MemMap_MSR4_MOP_Daimler.h"
#include "MemMap_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h"
#include "MemMap_Fbl.h"
#include "MemMap_SWVersions.h"


#ifdef VSWT_USED
#ifdef CDD_MBBL_VSWTDIAGNOSTICAPPL_START_SEC_CODE
# undef CDD_MBBL_VSWTDIAGNOSTICAPPL_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif

#ifdef CDD_MBBL_VSWTDIAGNOSTICAPPL_STOP_SEC_CODE
# undef CDD_MBBL_VSWTDIAGNOSTICAPPL_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#ifdef CDD_MBBL_LINKSTATEMANAGER_START_SEC_CODE
# undef CDD_MBBL_LINKSTATEMANAGER_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif

#ifdef CDD_MBBL_LINKSTATEMANAGER_STOP_SEC_CODE
# undef CDD_MBBL_LINKSTATEMANAGER_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif
#endif

#if defined( RCM_RESET_NOTIFICATIONS_START_SEC_VAR_NOINIT )
# pragma section nearbss "ResetNotificationSection"
# pragma section farbss "ResetNotificationSection"
# undef RCM_RESET_NOTIFICATIONS_START_SEC_VAR_NOINIT
# undef MEMMAP_ERROR
#endif

#if defined( RCM_RESET_NOTIFICATIONS_STOP_SEC_VAR_NOINIT )
# pragma section nearbss restore
# pragma section farbss restore
# undef RCM_RESET_NOTIFICATIONS_STOP_SEC_VAR_NOINIT
# undef MEMMAP_ERROR
#endif

/* contains all configured MemMap Sections -> fallback for compatibility reasons */
#include "MemMap_Compatibility.h" /* generated by module MemMap */

/* MEMMAP_ERROR is
- still defined if MemMap_Compatibility did not contain a matching section
- undefined, if MemMap_Compatibility handled the section define. */
#ifdef MEMMAP_ERROR
# include "MemMap_Common.h"
#endif

