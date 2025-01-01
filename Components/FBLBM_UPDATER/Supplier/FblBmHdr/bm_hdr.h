/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         BM Header module
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *  01.00.00   2019-31-01  visrie  -                Initial release
 *  01.01.00   2019-02-18  vismvi  -                No changes
 *                         visrie  ESCAN00102184    No changes
 *  01.02.00   2019-07-22  visrie  ESCAN00103790    No changes
 *                                 ESCAN00103791    No changes
 *                                 ESCAN00103803    No changes
 *  02.00.00   2019-12-03  visrie  FBL-456          Added support for new FblLibSecBoot interface
 *  02.00.01   2020-01-15  visrie  ESCAN00105368    Added missing encapsulation
 *  02.01.00   2022-02-25  vistbe  FBL-4128         Added/adapted MemMap sections
 **********************************************************************************************************************/

#ifndef BM_HDR_H
#define BM_HDR_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblBm_Hdr CQComponent : Implementation */
#define FBLBM_HDR_VERSION           0x0201u
#define FBLBM_HDR_RELEASE_VERSION   0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "FblBmHdr_Cfg.h"

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define FBLBMHDR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

tFblResult FblBmHdrCheckConsistency( const V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 V_MEMRAM3 * pBmHeader );
tFblBmHdrCheckBmHeaderResult FblBmHdrGetBmHeader(tFblBmHdrTargetHandle targetHandle, tFblAddress bmHeaderAddress,
   V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 V_MEMRAM3 * bmHeader);
#if defined( FBLBM_INSTANCE_BOOTMANAGER )
tFblBmHdrCheckBmHeaderResult FblBmHdrFindValidHeader(tFblBmHdrTargetHandle targetHandle,
   V_MEMRAM1 tFblBmBlockInfo V_MEMRAM2 V_MEMRAM3 * pBlockInfo);
#endif /* FBLBM_INSTANCE_BOOTMANAGER */

#define FBLBMHDR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* BM_HDR_H */

/***********************************************************************************************************************
 *  END OF FILE: BM_HDR.H
 **********************************************************************************************************************/
