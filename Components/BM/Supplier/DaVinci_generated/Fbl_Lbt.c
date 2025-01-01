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
 *              File: Fbl_Lbt.c
 *   Generation Time: 2023-07-17 14:11:51
 *           Project: CBD2000614_Bm - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


/* Includes **********************************************************************************************************/
#include "fbl_inc.h"

/* Global data *******************************************************************************************************/
V_MEMROM0 V_MEMROM1 tLogicalBlockTable V_MEMROM2 FblLogicalBlockTable =
{
  FBL_LBT_MAGIC_FLAG, 
  {
    0x02u
  } /*  Disposability bit field (mandatory/optional)  */ , 
  2u, 
  {
    {
      0u, 
      FALSE /*  Optional  */ , 
      0x00000000u /*  Block Index  */ , 
      kBlockTypeBoot /*  Block Type  */ , 
      0xA0034000u /*  Block Start Address  */ , 
      0x00038000u /*  Block Length (End Address = 0xA006BFFFu)  */ , 
      0xA0034300u /*  BM Header Address  */ , 
      0x0000u /*  Max Prog Attempts  */ , 
      (tExportFct)NULL_PTR /*  Input Verification  */ , 
      (tExportFct)NULL_PTR /*  Processed Verification  */ , 
      (tExportFct)NULL_PTR /*  Pipelined Verification  */ , 
      (tExportFct)NULL_PTR /*  Output Verification  */ 
    } /*  Name 'Bootloader'  */ , 
    {
      1u /*  Demo Application  */ , 
      TRUE /*  Mandatory  */ , 
      0x00000001u /*  Block Index  */ , 
      kBlockTypeCode /*  Block Type  */ , 
      0xA006C000u /*  Block Start Address  */ , 
      0x00094000u /*  Block Length (End Address = 0xA00FFFFFu)  */ , 
      0xA006C0E0u /*  BM Header Address  */ , 
      0x00FFu /*  Max Prog Attempts  */ , 
      (tExportFct)NULL_PTR /*  Input Verification  */ , 
      (tExportFct)NULL_PTR /*  Processed Verification  */ , 
      (tExportFct)NULL_PTR /*  Pipelined Verification  */ , 
      (tExportFct)NULL_PTR /*  Output Verification  */ 
    } /*  Name 'Application'  */ 
  }
};

