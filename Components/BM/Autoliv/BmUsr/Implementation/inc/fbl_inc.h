/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Include File
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
 *  05.00.00   2019-03-08  visach  ESCAN00102413    Remove generation tool dependent includes for memory tables
 *  05.01.00   2019-08-13  vistbe  FBL-370          Added support for generic MCMP slave
 *  06.00.00   2020-03-02  vistbe  FBL-949          Use ExecutionInstance define to exclude non relevant includes
 *                                 ESCAN00104557    Bootmanager modules are not included
 *  06.01.00   2020-05-14  vistbe  FBL-673          Changed include order for FblLib_SecBoot
 *  06.02.00   2020-05-14  vistbe  FBL-2021         Moved inlcude of vOtaM
 *  06.03.00   2021-12-22  vishor  FBL-4110         Encapsulate Sec_Types include with SecureBoot
 *  06.04.00   2022-04-01  visrie  FBL-1904         Add (automatic) support for additional driver includes
 *  06.05.00   2022-04-13  vismix  FBL-4950         Add include for DrvSwap
 **********************************************************************************************************************/

#ifndef FBL_INC_H
#define FBL_INC_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblInc CQComponent : Implementation */
#define FBLINC_VERSION          0x0605u
#define FBLINC_RELEASE_VERSION  0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Version check file */
#include "v_ver.h"
#include "v_cfg.h"
#if defined( VGEN_GENY )
# include "v_inc.h"
#endif /* VGEN_GENY */

/* Include BM config to have information about the configured instance */
#include "FblBm_Cfg.h"

#if defined( FBLBM_INSTANCE_BOOTLOADER ) ||\
    defined( FBLBM_INSTANCE_APPLICATION)
/* Security module */
#  include "SecM.h"
#else
#  if defined( FBLBM_ENABLE_SECURE_BOOT )
#   include "Sec_Types.h"
#  endif /* FBLBM_ENABLE_SECURE_BOOT */
#endif /* FBLBM_INSTANCE_* */

#include "fbl_def.h"

/* Logical block table types and definitions */
# include "Fbl_Lbt.h"
#  include "fbl_lbt_access.h"

#if defined( FBLBM_INSTANCE_BOOTLOADER ) ||\
    defined( FBLBM_INSTANCE_APPLICATION) ||\
    defined( FBLBM_INSTANCE_UPDATER )
#endif /* FBLBM_INSTANCE_* */

/* Basic types and definitions */


#include "flashdrv.h"
#if defined( kMioDeviceFlash_XD1 )
# include "flashdrv_xd1.h"
#endif
#if defined( kMioDeviceFlash_XD2 )
# include "flashdrv_xd2.h"
#endif
#if defined( kMioDeviceFlash_XD3 )
# include "flashdrv_xd3.h"
#endif

#if defined( FBL_DIAG_ENABLE_FLASHDRV_ROM )
# include "FlashRom.h"
#endif

#include "fbl_wd.h"

#include "iotypes.h"

/* Flash block table */
#include "Fbl_Fbt.h"
#include "fbl_mio.h"
#include "fbl_flio.h"
#if defined( kMioDeviceFlash_XD1 )
# include "fbl_flio_xd1.h"
#endif
#if defined( kMioDeviceFlash_XD2 )
# include "fbl_flio_xd2.h"
#endif
#if defined( kMioDeviceFlash_XD3 )
# include "fbl_flio_xd3.h"
#endif


#if defined( FBL_ENABLE_OTA )
# include "fbl_mem2His.h"
#endif /*  FBL_ENABLE_OTA*/

/* Application vector table */
#include "applvect.h"

/* API of the communication wrapper */
#  if defined( FBLBM_INSTANCE_BOOTLOADER ) || \
      defined( FBLBM_INSTANCE_APPLICATION ) || \
    ( defined( FBLBM_INSTANCE_UPDATER ) && defined( FBL_ENABLE_RESPONSE_AFTER_RESET ) )
#   include "fbl_cw.h"
#  endif

/* Hardware dependent header file */
#include "fbl_hw.h"

#if defined( FBL_ENABLE_WRAPPER_NV )
# include "WrapNv_inc.h"
#endif

# include "fbl_nvpattern.h"

#if defined( kMioDeviceRam )
/* Memory driver for RAM access */
# include "fbl_ramio_inc.h"
#endif
#if defined( kMioDeviceProtected )
/* Pseudo memory driver for protected memory areas */
# include "fbl_protio.h"
#endif

#if defined( FBLBM_INSTANCE_BOOTLOADER ) ||\
    defined( FBLBM_INSTANCE_APPLICATION )
#  if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
#    include "Fbl_Rst.h"
#   endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */

/* Diagnostic layer */

#  include "fbl_diag.h"

#  include "fbl_mem.h"
#endif /* FBLBM_INSTANCE_* */

/* Application call-back functions */
#if defined( FBL_ENABLE_COMMON_DATA )
# include "comdat.h"
#endif /* FBL_ENABLE_COMMON_DATA */

#if defined( FBLBM_ENABLE_SECURE_BOOT )
# include "fbl_secboot.h"
#endif

#if defined( FBL_ENABLE_HARDWARE_SWAP )
# include "fbl_swap.h"
#endif

#if defined( FBL_ENABLE_OTA )
# if defined( FBLBM_INSTANCE_BOOTLOADER ) ||\
     defined( FBLBM_INSTANCE_APPLICATION)
#  include "vOtaM.h"
#  include "vOtaM_Appl.h"
# endif /* FBLBM_INSTANCE_* */
#endif /* FBL_ENABLE_OTA */

#if defined( FBLBM_INSTANCE_BOOTLOADER ) ||\
    defined( FBLBM_INSTANCE_APPLICATION )
# include "fbl_ap.h"
#endif /* FBLBM_INSTANCE_* */

#include "fbl_apwd.h"

#if defined( FBLBM_INSTANCE_BOOTLOADER ) ||\
    defined( FBLBM_INSTANCE_APPLICATION )
#  include "fbl_apdi.h"
#  include "fbl_apnv.h"
#endif /* FBLBM_INSTANCE_* */


# if defined( FBLBM_INSTANCE_BOOTLOADER ) ||\
     defined( FBLBM_INSTANCE_APPLICATION)
#  if defined( FBL_ENABLE_COMPRESSION_MODE )
/* Decompression module */
#   include "cmpr.h"
#  endif /* FBL_ENABLE_COMPRESSION_MODE */
# endif /* FBLBM_INSTANCE_* */



#if defined( FBLBM_INSTANCE_BOOTLOADER ) ||\
    defined( FBLBM_INSTANCE_APPLICATION)
#  include "fbl_main.h"
#endif /* FBLBM_INSTANCE_* */

#include "bm_main.h"

#if defined (FBLBM_INSTANCE_UPDATER)
# include "upd_ap.h"
# include "upd_main.h"
#endif /* FBLBM_INSTANCE_UPDATER */

#endif /* FBL_INC_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_INC.H
 **********************************************************************************************************************/
