/* Kernbauer Version: 1.12 Konfiguration: FBL Erzeugungsgangnummer: 1 */

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application dependent diagnostic routines
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
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2017-07-28  viscb                    Initial implementation based on FblKbApi_FrameDiag_DC
 *  02.00.00   2021-01-19  viscb   FBL-2244         - Minor improvements
 *                                                  - Migration to MISRA 2012
 *  02.00.01   2021-02-02  viscb   ESCAN00108449    QM release
 *  02.00.02   2021-05-04  viscb   ESCAN00109251    No changes
 *  02.00.03   2021-12-21  vishor  ESCAN00109451    No changes
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


#ifndef FBL_APDI_H
#define FBL_APDI_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblKbApi_FrameDiag_Daimler CQComponent : Implementation */
#define FBLKBAPI_FRAMEDIAG_DAIMLER_VERSION           0x0200u
#define FBLKBAPI_FRAMEDIAG_DAIMLER_RELEASE_VERSION   0x03u

/***********************************************************************************************************************
 *  PROTOTYPES
 **********************************************************************************************************************/

tFblResult ApplFblCheckConditions( vuint8 * pbDiagData, tTpDataType diagReqDataLen );
#if defined( FBL_ENABLE_USERSERVICE )
void ApplDiagUserService( vuint8 * pbDiagData, tTpDataType diagReqDataLen );
#endif /* FBL_ENABLE_USERSERVICE */
#if defined( FBL_ENABLE_USERSUBFUNCTION )
void ApplDiagUserSubFunction( vuint8 * pbDiagData, tTpDataType diagReqDataLen );
#endif /* FBL_ENABLE_USERSUBFUNCTION */
void ApplFblReadDataByIdentifier( vuint8 * pbDiagData, tTpDataType diagReqDataLen );
#if defined( FBL_ENABLE_DEBUG_STATUS )
void ApplFblInitErrStatus( void );
#endif
tFblResult ApplFblCheckProgPreconditions( vuint8 * pbDiagData, tTpDataType diagReqDataLen );

tFblResult ApplFblControlFailSafeReaction( vuint8 * pbDiagData, tTpDataType diagReqDataLen );
tFblResult ApplFblPrepVehicleSystForReprog( vuint8 * pbDiagData, tTpDataType diagReqDataLen );

#endif /* FBL_APDI_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_APDI.H
 **********************************************************************************************************************/
