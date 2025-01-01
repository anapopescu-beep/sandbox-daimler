/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Fbl
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fbl_Fbt.c
 *   Generation Time: 2023-07-24 13:42:11
 *           Project: CBD2000614_Upd - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


/* Includes **********************************************************************************************************/
#include "fbl_inc.h"

/* Global data *******************************************************************************************************/
V_MEMROM0 V_MEMROM1_FAR tFlashBlock V_MEMROM2_FAR FlashBlock[] =
{
  {
    0xA0034000u /*  PF0 PS0: 64KB Block (BM)  */ , 
    0xA0047FFFu, 
    kMioDeviceFlash
  }, 
  {
    0xA0048000u /*  PF0 PS0: 148KB Block (FBL)  */ , 
    0xA006BFFFu, 
    kMioDeviceFlash
  }, 
  {
    0xA006C000u /*  PF0 PS1: 458KB Block (APPL)  */ , 
    0xA00FFFFFu, 
    kMioDeviceFlash
  }
};
V_MEMROM0 V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kNrOfFlashBlock = sizeof(FlashBlock) / sizeof(FlashBlock[0]);

V_MEMROM0 V_MEMROM1_FAR tMemDrv V_MEMROM2_FAR memDrvLst[] =
{
  {
    FlashDriver_InitSync, 
    FlashDriver_DeinitSync, 
    FlashDriver_REraseSync, 
    FlashDriver_RWriteSync, 
    FlashDriver_RReadSync, 
    0x0020u /*  Segment Size  */ , 
    0x00u /*  Erased Value  */ , 
    FALSE /*  Init Hook  */ , 
    FALSE /*  Deinit Hook  */ , 
    TRUE /*  Erase Hook  */ , 
    TRUE /*  Write Hook  */ , 
    TRUE /*  Read Hook  */ 
  }
};
V_MEMROM0 V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kNrOfMemDrv = sizeof(memDrvLst) / sizeof(memDrvLst[0]);

/* Try to check consistency between memory device driver
 * header files (e.g. flashdrv.h) and Cfg5 configuration */
#if defined( FLASH_SEGMENT_SIZE )
# if ( FLASH_SEGMENT_SIZE != 32u )
#  error "Consistency check failed! Adjust Cfg5 configuration!"
# endif
#endif

#if defined( FBL_FLASH_DELETED )
# if ( FBL_FLASH_DELETED != 0x00u )
#  error "Consistency check failed! Adjust Cfg5 configuration!"
# endif
#endif



