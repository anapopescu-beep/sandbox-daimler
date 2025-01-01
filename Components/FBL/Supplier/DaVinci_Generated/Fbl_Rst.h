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
 *              File: Fbl_Rst.h
 *   Generation Time: 2023-07-05 16:23:54
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined(__FBL_RST_H__)
#define __FBL_RST_H__

#ifdef FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING
/* Typedefs **********************************************************************************************************/
typedef struct tResumeSectionTag {
  tFblAddress begin;
  tFblAddress end;
} tResumeSection;

/* Global data *******************************************************************************************************/
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 kNrOfResumeSections;
V_MEMROM0 extern  V_MEMROM1 tResumeSection V_MEMROM2 FblResumeSectionTable[];
#endif

#endif /* __FBL_RST_H__ */

