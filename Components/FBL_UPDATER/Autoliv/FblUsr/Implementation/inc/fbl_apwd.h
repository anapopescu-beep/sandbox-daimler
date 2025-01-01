/* Kernbauer Version: 1.12 Konfiguration: FBL Erzeugungsgangnummer: 1 */

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application dependent watchdog routines
 *
 *  \note          Please note, that this file contains a collection of callback functions to be used with the
 *                 Flash Bootloader. These functions may influence the behavior of the bootloader in principle.
 *                 Therefore, great care must be taken to verify the correctness of the implementation.
 *                 The contents of the originally delivered files are only examples resp. implementation proposals.
 *                 With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                 Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                 admissible by law or statute.
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Christian Baeuerle            CB            Vector Informatik GmbH
 *  Armin Happel                  Hp            Vector Informatik GmbH
 *  Konrad Lazarus                Ls            Vector Informatik GmbH
 *  Alexandre C. Plombin          ACP           Vector CANtech, Inc.
 *  Ahmad Nasser                  An            Vector CANtech, Inc.
 *  Robert Schaeffner             Rr            Vector Informatik GmbH
 *  Marco Wierer                  WM            Vector Informatik GmbH
 *  Joern Herwig                  JHG           Vector Informatik GmbH
 *  Andre Caspari                 Ci            Vector Informatik GmbH
 *  Michael Radwick               MFR           Vector CANtech, Inc.
 *  Andreas Wenckebach            AWh           Vector Informatik GmbH
 *  Achim Strobelt                Ach           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  03.00.00   2004-07-09  WM                       First implementation
 *  03.01.00   2004-09-22  WM                       No changes
 *  03.02.00   2005-01-21  Rr                       Changed version defines due to naming
 *                                                  conventions
 *  03.03.00   2005-04-20  WM                       No changes
 *  03.04.00   2006-08-03  JHG     ESCAN00017120    Added token for additional functions
 *  03.05.00   2007-01-22  WM                       No changes
 *  03.06.00   2007-03-29  MFR                      No Changes
 *  03.07.00   2008-03-07  Hp                       No ApplFblWDTriggerEnd prototype with copy from startup.
 *  03.08.00   2009-11-11  AWh     ESCAN00039075    Added Kb-includes for own apwd-defines
 *  03.09.00   2012-03-30  QPs     ESCAN00058043    Removed PRE/POST tokens for ApplFblWDTrigger
 *  03.10.00   2012-12-06  Ach     ESCAN00062912    Adapted comments to use Doxygen
 *  03.10.01   2018-02-02  AWh     ESCAN00098254    No changes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2018-09-14  visrie  ESCAN00100739    Added support for FblLib_NvPattern
 *                                                  Removed unused code
 *                         viscb   ESCAN00101418    Callout function for memory condition check
 *                         visach  ESCAN00101686    No changes
 *  02.01.00   2019-02-26  visrie  ESCAN00102257    Added additional callout functions
 *  02.01.01   2019-09-23  visrie  FBL-452          No changes
 *  02.02.00   2019-12-05  visrie  FBL-458          Added FblMio callout functions
 *  02.03.00   2020-05-07  visrie  FBL-1414         Added callout functions for One-Step-Updater
 *  02.03.01   2020-06-02  visjdn  ESCAN00106533    No changes
 *  02.03.02   2020-09-14  visrcn  FBL-2257         No changes
 *  02.03.03   2020-11-23  visrcn  FBL-2564         No changes
 *  02.03.04   2021-03-19  visjdn  FBL-2916         No changes
 *  02.04.00   2021-05-25  vishor  FBL-3165         MISRA corrections and justifications
 *  02.05.00   2021-06-15  visrie  FBL-3591         No changes
 *  02.06.00   2021-07-15  visjdn  FBL-3381         Re-mapping of EcuM_SetWakeupEvent
 *  02.07.00   2021-07-23  visrie  FBL-3822         No changes
 *  02.08.00   2021-09-14  visjdn  FBL-2859         No changes
 *  02.09.00   2021-10-12  vistmo  FBL-3901         Add authentication callbacks
 *  02.10.00   2021-10-15  visrie  FBL-3945         Remove content of ApplFblStartApplication
 *  02.10.01   2021-11-12  vishor  ESCAN00110133    Compiler error: Unknown symbols
 *                                                   ApplFblSave/RestoreStatusSector/Dynamic
 *  02.10.02   2022-06-27  visrie  FBL-4694         No changes
 *  02.10.03   2022-10-20  visjns  FBL-5452         No changes
 *  02.11.00   2022-12-22  vistbe  FBL-5691         No changes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY (KbFbl_apOem.h)
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2019-03-12  visrie  ESCAN00102454    Added support for LibNvPattern, LibLbtAccess and SecureBoot
 *  02.00.01   2019-04-29  viscb   ESCAN00102998    No changes
 *  03.00.00   2020-10-06  viscb   FBL-2177         DRECU2020-01 adaptions, data processing
 *  03.01.00   2021-01-19  viscb   FBL-2244         DRECU2020-01 adaptions
 *                                                    - Simplified updater integration
 *                                                    - Added support for OTA
 *                                                    - Added support for downgrade protection
 *                                                    - Migration to MISRA 2012
 *  03.01.01   2021-02-02  viscb   ESCAN00108447    QM release
 *  03.02.00   2021-04-21  viscb   ESCAN00108550    No changes
 *                                 ESCAN00108549    No changes
 *                                 ESCAN00108532    No changes
 *                                 ESCAN00108591    No changes
 *  03.03.00   2021-07-12  vishor  FBL-3567         No changes
 *  03.03.01   2021-08-24  vishor  ESCAN00109880    No changes
 *  03.03.02   2021-08-27  vishor  ESCAN00109972    No changes
 *  03.03.03   2021-10-19  vistmo  ESCAN00110504    No changes
 *  03.03.04   2021-11-19  visjdn  ESCAN00108780    [XCP] Bootloader does not process XCP messages
 *  03.04.00   2022-03-16  vishor  FBL-4621         No changes
 *                                 ESCAN00107629    No changes
 *                                 ESCAN00110835    No changes
 *                                 ESCAN00110881    No changes
 *  03.05.00   2022-06-01  vishor  FBL-5094         MB MMA Rework
 *                                 ESCAN00112002    No changes
 *  03.05.01   2022-06-23  vishor  ESCAN00112105    No changes
 *                                 ESCAN00112155    No changes
 *  03.05.02   2022-08-29  visjns  ESCAN00112404    No changes
 *                                 ESCAN00112298    No changes
 *  03.05.03   2022-12-12  vismix  ESCAN00112835    No changes
 **********************************************************************************************************************/


#ifndef __FBL_APWD_H__
#define __FBL_APWD_H__

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblKbApi_FrameWd CQComponent : Implementation */
#define FBLKBAPI_FRAMEWD_VERSION                0x0310u
#define FBLKBAPI_FRAMEWD_RELEASE_VERSION        0x01u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  PROTOTYPES
 **********************************************************************************************************************/

void ApplFblWDInit( void );
void ApplFblWDLong( void );
void ApplFblWDShort( void );
# define WDTRIGGER_START_SEC_CODE_EXPORT
# include "MemMap.h"   /* PRQA S 5087 *//* MD_MSR_MemMap */
void V_CALLBACK_NEAR ApplFblWDTrigger( void );
# define WDTRIGGER_STOP_SEC_CODE_EXPORT
# include "MemMap.h"   /* PRQA S 5087 *//* MD_MSR_MemMap */


#endif /* __FBL_APWD_H__ */

/***********************************************************************************************************************
 *  END OF FILE: FBL_APWD.H
 **********************************************************************************************************************/

