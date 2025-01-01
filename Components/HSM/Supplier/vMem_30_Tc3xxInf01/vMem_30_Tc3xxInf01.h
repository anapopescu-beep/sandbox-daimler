/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMem_30_Tc3xxInf01.h
 *        \brief  vMem_30_Tc3xxInf01 header file
 *
 *      \details  This is the header file of the vMem_30_Tc3xxInf01. It declares the interfaces of the vMem_30_Tc3xxInf01. 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author          Change Id                Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2018-04-23  virbmz          FEAT-3242/
 *                        viroto          STORY-4004, STORY-3380   Initial version.
 *  01.01.00  2018-05-22  vircre          STORYC-5221              Added pending-check, extracted LowLevel functionality
 *                                                                 to separate files, added hardware software interface,
 *                                                                 reworked state machine of erase and write jobs.
 *            2018-06-04  vircre          STORYC-3501              Implemented new InstanceId handling.
 *            2018-06-05  vircre                                   Added extended functionality GetActiveAddressRegion.
 *                                                                 Added initialization check to MainFunction.
 *  01.02.00  2018-07-12  vircre          STORYC-5975              Support alternate address map of Tc3xx in vMem.
 *            2018-07-18  vircre          ESCAN00100090            Compiler error: component does not compile when 
 *                                                                 Tasking compiler is used.
 *  01.03.00  2018-08-06  vircre          STORYC-6050              vMem_30_Tc3xxInf01 shall fulfill quality status QM
 *            2018-08-06  vircre          ESCAN00099801            vMem_30_Tc3xxInf01 detects error for passed address, 
 *                                                                 that is correct (wrong address alignment check)
 *  01.04.00  2018-10-04  vircre          STORYC-4938              Support write and erase burst in 
 *                                                                 DrvMem_vMem_30_Tc3xxInf01
 *            2019-02-19  vircre          STORY-8867               vMem for Tc3xx shall support Os_Peripheral API
 *  01.05.00  2019-03-19  vircre          STORY-10827              vMem for Tc3xx shall provide service to check for
 *                                                                 erased flash as hardware specific function
 *  01.05.01  2019-05-13  vircre          ESCAN00102982            Hardware specific request for BlankCheck causes trap
 *  01.05.02  2019-06-11  virstl          STORY-12869              vMem Tc3xx shall support PFlash accesses from the 
 *                                                                 HSM Core
 *  01.06.00  2019-06-18  vircre          STORY-9222               Implement Replace Logical Sector feature in vMem
 *                                                                 for Tc3xx
 *  01.07.00  2019-12-06  virstl          MWDG-2501                vMem_Tc3xx shall provide a service to check for 
 *                                                                 hardware error states for latest job
 *  2.00.00   2020-01-02  virstl          MWDG-1902                RAM Alignment check within vMem_Tc3xxInf01
 *            2020-01-07  virstl          MWDG-6                   vMem for Tc3xx shall provide service to check for 
 *                                                                 erased flash
 *  2.00.01   2020-04-09  virpam          ESCAN00106046            Compiler error: vMem_30_Tc3xxInfo_IntShared.h is 
 *                                                                 missing
 *  2.00.02   2020-06-08  virpam          ESCAN00106487            Blank check request sometimes does not indicate 
 *                                                                 failure
 *  2.01.00   2021-02-26  virepm          CTM-2559                 Add compiler abstraction for GHS
 *  2.02.00   2021-02-26  fbatz           CTM-3025                 Add compiler abstraction for Diab
 *  3.00.00   2021-10-06  coberpriller    CTM-3616				         Update to new core version 3.00.00
 *  3.01.00   2022-01-12  virpam          CTM-3659				         Update to latest vMem core (3.01.00)
 *********************************************************************************************************************/

#if !defined (VMEM_30_TC3XXINF01_H)
# define VMEM_30_TC3XXINF01_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vMem_30_Tc3xxInf01_Cfg.h"
# include "vMem_30_Tc3xxInf01_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define VMEM_30_TC3XXINF01_SW_MAJOR_VERSION                    (3u)
# define VMEM_30_TC3XXINF01_SW_MINOR_VERSION                    (1u)
# define VMEM_30_TC3XXINF01_SW_PATCH_VERSION                    (0u)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_TC3XXINF01_START_SEC_HEADER_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Global API pointer table */
extern CONST(vMemAccM_vMemApiType, AUTOMATIC) vMem_30_Tc3xxInf01_FunctionPointerTable;

#define VMEM_30_TC3XXINF01_STOP_SEC_HEADER_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VMEM_30_TC3XXINF01_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Returns the version information. This service is always available.
 *  \details     vMem_30_Tc3xxInf01_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  versioninfo           Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-150071
 *********************************************************************************************************************/
FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, VMEM_30_TC3XXINF01_APPL_VAR) VersionInfo);

# define VMEM_30_TC3XXINF01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* VMEM_30_TC3XXINF01_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Tc3xxInf01.h
 *********************************************************************************************************************/

