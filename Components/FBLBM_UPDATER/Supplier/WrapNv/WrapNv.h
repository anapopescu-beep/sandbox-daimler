/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file         WrapNv.h
 *  \brief        Wrapper for NV-memory access
 *  -------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/*********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2016-02-22  visrie  ESCAN00088726    Added support for Fee/NvM
 *                                                  Removed unused code
 *  02.01.00   2016-03-09  visrie  ESCAN00088817    Removed function call NvM_Errorhook
 *                                 ESCAN00088819    Abstraction of Fls interface
 *  02.02.00   2016-07-05  visrie  ESCAN00090830    Added support for no NV driver use-case
 *  02.02.01   2016-09-06  visrie  ESCAN00091757    Fixed MISRA findings
 *  02.02.02   2016-10-17  visrie  ESCAN00092351    Configure used FEE functions
 *  02.03.00   2017-09-19  visrie  ESCAN00094172    Fixed compiler warning undefined preprocessor define
 *                                 ESCAN00095574    Added support for EA
 *  02.04.00   2017-11-29  visrie  ESCAN00096851    Updated APIs for MSR-Release 18
 *                                 ESCAN00097590    Added error code for Record ID check
 *                                 ESCAN00097591    Added support for sequential queue handling of asynchronous access
 *  02.04.01   2018-01-11  visrie  ESCAN00097944    Fixed state handling
 *                                 ESCAN00097953    Fixed endless loop
 *  02.05.00   2018-02-08  visrie  ESCAN00097770    Consider main function call cycle
 *  02.06.00   2018-03-21  visrie  ESCAN00098860    Added support for EEL
 *  02.06.01   2018-04-06  visrie  ESCAN00099015    No changes
 *  02.06.02   2018-12-07  visrie  ESCAN00099155    No changes
 *                                 ESCAN00101194    Reworked include structure
 *  03.00.00   2020-04-02  visrie  FBL-1331         Support of new generator
 *  04.00.00   2020-05-26  visrie  FBL-1016         Support EcuM_Init() mechanism
 *  04.00.01   2020-07-16  visrie  FBL-2160         Removed use case filtering
 *  04.00.02   2021-04-01  visrcn  FBL-3009         Make polling function configurable
 *                                 FBL-3095         Add support for DET usage
 *  04.01.00   2022-07-11  vistmo  FBL-5336         Adding support for block access
 *********************************************************************************************************************/

#ifndef WRAPNV_H
#define WRAPNV_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : SysService_WrapperNv CQComponent : Implementation */
# define SYSSERVICE_WRAPPERNV_VERSION              0x0401u
# define SYSSERVICE_WRAPPERNV_RELEASE_VERSION      0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

# include "WrapNv_Cfg.h"
# if defined( WRAPNV_USECASE_FEE ) || \
     defined( WRAPNV_USECASE_EA )  || \
     defined( WRAPNV_USECASE_NVM )
#  include "Std_Types.h"
# endif /* WRAPNV_USECASE_* */

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
# if defined( WRAPNV_USECASE_FEE ) || \
     defined( WRAPNV_USECASE_EA )  || \
     defined( WRAPNV_USECASE_NVM )
/* Vendor and module identification */
#  define WRAPNV_VENDOR_ID           30u
#  define WRAPNV_MODULE_ID           255u
#  define WRAPNV_INSTANCE_ID         0u

/* Service IDs */
#  define WRAPNV_APIID_INIT          0x00u
#  define WRAPNV_APIID_READ          0x01u
#  define WRAPNV_APIID_READPARTIAL   0x02u
#  define WRAPNV_APIID_WRITE         0x03u
#  define WRAPNV_APIID_DELETE        0x04u

/* Development errors */
#  define WRAPNV_E_NO_ERROR          0x10u
#  define WRAPNV_E_NOT_IDLE          0x11u
#  define WRAPNV_E_PARAM_DATASET     0x12u
#  define WRAPNV_E_PARAM_READ        0x13u
#  define WRAPNV_E_PARAM_ID          0x14u
# elif defined( WRAPNV_USECASE_EEPM )
/* PRQA S 3453 3 */ /* MD_MSR_FctLikeMacro */
#  define NV_MK_STRUCT_ID(structure, id)            ((((vuint32)(structure)) << 24uL) | (id))
#  define NV_GET_STRUCT_ID(id)                      ((id) & 0x00FFFFFFuL)
#  define NV_GET_STRUCT_HANDLE(id)                  (((id) & 0xFF000000uL) >> 24uL)
# endif /* WRAPNV_USECASE_* */

/** Positive return value of NV-Wrapper */
# if defined( kFblOk )
#  define WRAPNV_E_OK                kFblOk
# elif defined( kEepMgrOk )
#  define WRAPNV_E_OK                kEepMgrOk
# elif defined( E_OK )
#  define WRAPNV_E_OK                E_OK
# else
#  define WRAPNV_E_OK                0u
# endif

/** Negative return value of NV-Wrapper */
# if defined( kFblFailed )
#  define WRAPNV_E_NOT_OK            kFblFailed
# elif defined( kEepMgrFailed )
#  define WRAPNV_E_NOT_OK            kEepMgrFailed
# elif defined( E_NOT_OK )
#  define WRAPNV_E_NOT_OK            E_NOT_OK
# else
#  define WRAPNV_E_NOT_OK            1u
# endif

/** Pending return value of NV-Wrapper */
# if defined( kEepMgrBusy )
#  define WRAPNV_E_PENDING           kEepMgrBusy
# elif defined( E_PENDING )
#  define WRAPNV_E_PENDING           E_PENDING
# else
#  define WRAPNV_E_PENDING           2u
# endif

/** Return type of NV-Wrapper */
# if defined( kFblOk )
#  define WrapNv_ReturnType          tFblResult
# elif defined( kEepMgrOk )
#  define WrapNv_ReturnType          vuint8
# elif defined( E_OK )
#  define WrapNv_ReturnType          Std_ReturnType
# else
#  define WrapNv_ReturnType          WrapNv_DefaultReturntype
# endif

/* Compatibility define for non MSR projects */
# if !defined( FUNC )
# define FUNC(rettype, memclass) rettype
# endif

/**********************************************************************************************************************
 *  TYPEDEFS
 *********************************************************************************************************************/

/** Operation status for asynchronous access */
typedef enum
{
   WRAPNV_OPSTATUS_INIT = 0u,       /**< Operation has been initialized */
   WRAPNV_OPSTATUS_PENDING,         /**< Operation is currently pending */
   WRAPNV_OPSTATUS_CANCEL,          /**< Operation has been canceled */
   WRAPNV_OPSTATUS_IDLE             /**< Internal: Currently no operation is active */
} tWrapNvOpStatus;

/** Type of data access */
typedef enum
{
   WRAPNV_ACCESS_DATAELEMENT = 0u,  /**< Access is performed at element level */
   WRAPNV_ACCESS_BLOCKELEMENT       /**< Access is performed at block level */
} tWrapNvAccessType;

# if defined( WRAPNV_USECASE_FEE ) || \
    defined( WRAPNV_USECASE_EA )  || \
    defined( WRAPNV_USECASE_NVM )
typedef P2VAR(uint8, AUTOMATIC, WRAPNV_DATA) tWrapNvRamData;
typedef P2CONST(uint8, AUTOMATIC, WRAPNV_DATA) tWrapNvConstData;
# endif /* WRAPNV_USECASE_* */

typedef unsigned char WrapNv_DefaultReturntype;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define WRAPNV_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, WRAPNV_CODE) WrapNv_Init( void );

# if defined( WRAPNV_USECASE_FEE ) || \
     defined( WRAPNV_USECASE_EA )  || \
     defined( WRAPNV_USECASE_NVM )
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadSync( uint16 id, uint16 idx, tWrapNvRamData buffer );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadBlockSync(uint16 id, uint16 idx, tWrapNvRamData buffer);
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartialSync( uint16 id, uint16 idx, tWrapNvRamData buffer, uint16 offset, uint16 length );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartialBlockSync(uint16 id, uint16 idx, tWrapNvRamData buffer, uint16 offset, uint16 length);
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_DeleteSync( uint16 id, uint16 idx );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_WriteSync( uint16 id, uint16 idx, tWrapNvConstData buffer );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_WriteBlockSync( uint16 id, uint16 idx, tWrapNvConstData buffer );

FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadAsync( uint16 id, uint16 idx, tWrapNvRamData buffer, tWrapNvOpStatus opStatus );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadBlockAsync(uint16 id, uint16 idx, tWrapNvRamData buffer, tWrapNvOpStatus opStatus);
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartialAsync( uint16 id, uint16 idx, tWrapNvRamData buffer, uint16 offset, uint16 length, tWrapNvOpStatus opStatus );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartialBlockAsync( uint16 id, uint16 idx, tWrapNvRamData buffer, uint16 offset, uint16 length, tWrapNvOpStatus opStatus );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_DeleteAsync( uint16 id, uint16 idx, tWrapNvOpStatus opStatus );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_WriteAsync( uint16 id, uint16 idx, tWrapNvConstData buffer, tWrapNvOpStatus opStatus );
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_WriteBlockAsync(uint16 id, uint16 idx, tWrapNvConstData buffer, tWrapNvOpStatus opStatus);
# endif /* WRAPNV_USECASE_* */

# if (WRAPNV_MAINFUNCTION_POLLING == STD_ON)
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_TriggerFct_Callout( void );
# endif

# define WRAPNV_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* WRAPNV_H */

/***********************************************************************************************************************
 *  END OF FILE: WRAPNV.H
 **********************************************************************************************************************/
