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
 *            Module: vBRS
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: .\vBrs_Lcfg.c
 *   Generation Time: 2022-09-22 10:43:13
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

#define VBRS_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "vBrs_Lcfg.h"

#if (BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u)
/*******************************************************************************
 Logical to phyiscal core assingment
*******************************************************************************/
extern Brs_AddressOfConstType BRSHW_DEFINE_STARTUP_STACK(0);
extern Brs_AddressOfConstType BRSHW_DEFINE_EXCVEC(0);
extern Brs_AddressOfConstType BRSHW_DEFINE_INTVEC(0);

const uint32 BrsMain_CoreConfig_Size = 1;

/* See BrsMain_Types.h for declaration of BrsMain_CoreConfig.
   Information is mainly used for StartupStack pointer initialization in StartupCode and
   call of BrsHw_ExceptionTable_Init() in main().
   For MultiCore setups, the information is mainly based on the actual OS configuration */

const brsMain_CoreType BrsMain_CoreConfig[1u] =
{
  {
    /* .LogicalCoreId        = */ 0u,
    /* .PhysicalCoreId       = */ 0u,
    /* .StartupStackEndLabel = */ (Brs_AddressOfConstType)(&BRSHW_DEFINE_STARTUP_STACK(0)),
    /* .StartupStackSize     = */ 1024u,
    /* .CoreIsAsr            = */ ASR,
    /* .ExcVecLabel          = */ (Brs_AddressOfConstType)(&BRSHW_DEFINE_EXCVEC(0)),
    /* .IntVecLabel          = */ (Brs_AddressOfConstType)(&BRSHW_DEFINE_INTVEC(0))
  }
};
#endif /*BRSHW_SOURCECODE_TEMPLATE_VERSION>=0x0103u*/
