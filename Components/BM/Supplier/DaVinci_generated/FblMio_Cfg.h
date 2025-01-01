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
 *            Module: FblMio_vMemAccM
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FblMio_Cfg.h
 *   Generation Time: 2023-07-17 14:11:51
 *           Project: CBD2000614_Bm - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef FBLMIO_CFG_H
#define FBLMIO_CFG_H

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define FBL_MIO_DISABLE_USE_IS_BLANK 
#define FBL_MIO_DISABLE_COMPARE_AFTER_WRITE 
#define FBL_MIO_DISABLE_USER_INIT_FUNCTION 
#define FBL_MIO_DISABLE_USER_MAIN_FUNCTION 
#define FBL_MIO_DISABLE_MEM_DRIVER_READY 
#define FBL_MIO_SIZE_OF_INSTANCE_MAPPING    1u 

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

typedef struct
{
   vMemAccM_HwIdType hwId;
   boolean isHis;
   vuint8 erasedValue;
} tFblMemInstanceMapping;

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

V_MEMROM0 extern V_MEMROM1 tFblMemInstanceMapping V_MEMROM2 FblMemInstanceMapping[FBL_MIO_SIZE_OF_INSTANCE_MAPPING];

#endif /* FBLMIO_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: FblMio_Cfg.h
 *********************************************************************************************************************/
