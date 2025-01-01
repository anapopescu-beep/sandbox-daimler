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
 *              File: Fbl_Rst.c
 *   Generation Time: 2023-07-26 12:58:40
 *           Project: CBD2000614_fblbm_Upd - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


/* Includes **********************************************************************************************************/
#include "fbl_inc.h"

#ifdef FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING
/* Global data *******************************************************************************************************/
/* Resume section boundaries must be alligned with */
/* the flash block table entries and logical blocks. */
V_MEMROM0 V_MEMROM1 tResumeSection V_MEMROM2 FblResumeSectionTable[] = 
{
  {
    0xA0048000u, 
    0xA006BFFFu
  }, 
  {
    0xA006C000u, 
    0xA00FFFFFu
  }
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kNrOfResumeSections = sizeof(FblResumeSectionTable) / sizeof(FblResumeSectionTable[0]);
#endif

