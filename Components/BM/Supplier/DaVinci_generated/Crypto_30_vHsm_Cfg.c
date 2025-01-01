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
 *            Module: Crypto_30_vHsm
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_vHsm_Cfg.c
 *   Generation Time: 2023-07-17 14:11:52
 *           Project: CBD2000614_Bm - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_vHsm_Cfg.h"
#include "Crypto_30_vHsm.h"
#include "Crypto_30_vHsm_Ipc_Types.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CRYPTO_30_VHSM_LOCAL)
# define CRYPTO_30_VHSM_LOCAL static
#endif

#if !defined (CRYPTO_30_VHSM_LOCAL_INLINE)
# define CRYPTO_30_VHSM_LOCAL_INLINE LOCAL_INLINE
#endif




/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Crypto_30_vHsm_KeyMgmObj
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_KeyMgmObj
  \details
  Element          Description
  ObjectInfoIdx    the index of the 1:1 relation pointing to Crypto_30_vHsm_ObjectInfo
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_vHsm_KeyMgmObjType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_KeyMgmObj[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ObjectInfoIdx        Referable Keys */
  { /*     0 */            4u }   /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_MemoryArea
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_MemoryArea
  \brief  Memory to which vHsm has direct access without the need of a copy.
  \details
  Element      Description
  AreaStart    Start address of area
  AreaStop     Stop address of area
  AreaType     Access type of area
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_vHsm_MemoryAreaType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_MemoryArea[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AreaStart    AreaStop     AreaType                                        Referable Keys */
  { /*     0 */ 0x50000000u, 0x7FFFFFFFu, CRYPTO_30_VHSM_AREA_HSM_READ_ACCESS      },  /* [/ActiveEcuC/Crypto_vHsm/CryptovHsm/TC3xx_CPU0_CPU1_CPU2] */
  { /*     1 */ 0x30000000u, 0x41FFFFFFu, CRYPTO_30_VHSM_AREA_HSM_READ_ACCESS      },  /* [/ActiveEcuC/Crypto_vHsm/CryptovHsm/TC3xx_CPU3_CPU4] */
  { /*     2 */ 0x10000000u, 0x1FFFFFFFu, CRYPTO_30_VHSM_AREA_HSM_READ_ACCESS      },  /* [/ActiveEcuC/Crypto_vHsm/CryptovHsm/TC3xx_CPU5] */
  { /*     3 */ 0x90000000u, 0x9011FFFFu, CRYPTO_30_VHSM_AREA_HSM_READWRITE_ACCESS },  /* [/ActiveEcuC/Crypto_vHsm/CryptovHsm/TC3xx_LMURAM_cached_HOST] */
  { /*     4 */ 0xB0000000u, 0xB011FFFFu, CRYPTO_30_VHSM_AREA_HSM_READWRITE_ACCESS },  /* [/ActiveEcuC/Crypto_vHsm/CryptovHsm/TC3xx_LMURAM_noncached] */
  { /*     5 */ 0x80040000u, 0x80FFFFFFu, CRYPTO_30_VHSM_AREA_HSM_READ_ACCESS      },  /* [/ActiveEcuC/Crypto_vHsm/CryptovHsm/TC3xx_PFLASH_cached] */
  { /*     6 */ 0xA0040000u, 0xA0FFFFFFu, CRYPTO_30_VHSM_AREA_HSM_READ_ACCESS      }   /* [/ActiveEcuC/Crypto_vHsm/CryptovHsm/TC3xx_PFLASH_noncached] */
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ObjMap
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ObjMap
  \details
  Element          Description
  ObjectInfoIdx    the index of the 0:1 relation pointing to Crypto_30_vHsm_ObjectInfo
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_vHsm_ObjMapType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ObjMap[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ObjectInfoIdx                                  Referable Keys */
  { /*     0 */                                      0u },  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  { /*     1 */                                      1u },  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa] */
  { /*     2 */                                      2u },  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa_HighPrio] */
  { /*     3 */ CRYPTO_30_VHSM_NO_OBJECTINFOIDXOFOBJMAP },  /* [INVALID] */
  { /*     4 */                                      3u },  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyM_LibCv] */
  { /*     5 */                                      4u },  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  { /*     6 */                                      5u },  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  { /*     7 */                                      6u }   /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ObjectInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ObjectInfo
  \details
  Element                     Description
  SharedDataBufferEndIdx      the end index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer
  SharedDataBufferStartIdx    the start index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer
  BufferUsed              
  HsmObjId                
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_vHsm_ObjectInfoType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ObjectInfo[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SharedDataBufferEndIdx  SharedDataBufferStartIdx  BufferUsed  HsmObjId        Referable Keys */
  { /*     0 */                    67u,                       0u,       TRUE,       0u },  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  { /*     1 */                   102u,                      67u,       TRUE,       1u },  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa] */
  { /*     2 */                   137u,                     102u,       TRUE,       2u },  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa_HighPrio] */
  { /*     3 */                   204u,                     137u,       TRUE,       4u },  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyM_LibCv] */
  { /*     4 */                   271u,                     204u,       TRUE,       5u },  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  { /*     5 */                   338u,                     271u,       TRUE,       6u },  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  { /*     6 */                   373u,                     338u,       TRUE,       7u }   /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ChannelState
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ChannelState
  \brief  Tracks which IPC channel is currently used.
*/ 
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Crypto_30_vHsm_ChannelStateType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_ChannelState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_DriverObjectLock
**********************************************************************************************************************/
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Crypto_30_vHsm_DriverObjectLockUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_DriverObjectLock;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     1 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa] */
  /*     2 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa_HighPrio] */
  /*     3 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyM_LibCv] */
  /*     4 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     5 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     6 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_JobRequest
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_JobRequest
  \brief  Stores data for a job request sent to vHSM.
  \details
  Element                  Description
  OutputOffset         
  SecondaryOutputOffset
  UsedBuffer           
  Cancel               
  Counter              
  Kind                 
  Lock                 
  ProcessingType       
  Result               
  State                
  TrimmedOutputBuffer  
  CryptoJob            
  JobState             
  KeyMJob              
*/ 
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Crypto_30_vHsm_JobRequestUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_JobRequest;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     1 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa] */
  /*     2 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa_HighPrio] */
  /*     3 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyM_LibCv] */
  /*     4 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     5 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     6 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_OutputLengthPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_OutputLengthPtrDataBuffer
  \brief  Buffer for the outputLengthPtr data on the shared RAM.
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_OutputLengthPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_OutputLengthPtrDataBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     1 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa] */
  /*     2 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa_HighPrio] */
  /*     3 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyM_LibCv] */
  /*     4 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     5 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     6 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer
  \brief  Buffer for the secondaryOutputLengthPtr data on the shared RAM.
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     1 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa] */
  /*     2 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa_HighPrio] */
  /*     3 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyM_LibCv] */
  /*     4 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     5 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     6 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_SharedDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_SharedDataBuffer
  \brief  Buffer for input and output data on the shared RAM
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_SharedDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SharedDataBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*   ... */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*    66 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*    67 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa] */
  /*   ... */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa] */
  /*   101 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa] */
  /*   102 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa_HighPrio] */
  /*   ... */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa_HighPrio] */
  /*   136 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa_HighPrio] */
  /*   137 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyM_LibCv] */
  /*   ... */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyM_LibCv] */
  /*   203 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyM_LibCv] */
  /*   204 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*   ... */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*   270 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*   271 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*   ... */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*   337 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*   338 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */
  /*   ... */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */
  /*   372 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_VerifyPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_VerifyPtrDataBuffer
  \brief  Buffer for the verifyPtr data on the shared RAM.
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_VerifyPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_VerifyPtrDataBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     1 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa] */
  /*     2 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hwa_HighPrio] */
  /*     3 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyM_LibCv] */
  /*     4 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     5 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     6 */  /* [/ActiveEcuC/Crypto_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
CONST(Crypto_30_vHsm_Ipc_MemoryLayoutType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_Ipc_MemoryLayout =
{
  /* protocolInformationOffset */
  0u,
  /* txChannelMemoryLayout[CRYPTO_30_VHSM_IPC_NUM_TX_CHANNELS] */
  {
    { Crypto_30_vHsm_Ipc_GetTxChannelWriteIndexOffset(0u), Crypto_30_vHsm_Ipc_GetTxChannelReadIndexOffset(0u), Crypto_30_vHsm_Ipc_GetTxChannelBufferOffset(0u) },
    { Crypto_30_vHsm_Ipc_GetTxChannelWriteIndexOffset(1u), Crypto_30_vHsm_Ipc_GetTxChannelReadIndexOffset(1u), Crypto_30_vHsm_Ipc_GetTxChannelBufferOffset(1u) }  
  },
  /* rxChannelMemoryLayout[CRYPTO_30_VHSM_IPC_NUM_RX_CHANNELS] */
  {
    { Crypto_30_vHsm_Ipc_GetRxChannelWriteIndexOffset(0u), Crypto_30_vHsm_Ipc_GetRxChannelReadIndexOffset(0u), Crypto_30_vHsm_Ipc_GetRxChannelBufferOffset(0u) },
    { Crypto_30_vHsm_Ipc_GetRxChannelWriteIndexOffset(1u), Crypto_30_vHsm_Ipc_GetRxChannelReadIndexOffset(1u), Crypto_30_vHsm_Ipc_GetRxChannelBufferOffset(1u) }  
  },
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (0u),  /* stackProtectionCanaryPE1Offset */  
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (4u),  /* stackProtectionCanaryPE2Offset */  
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (8u),  /* seedOffset */                      
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (12u), /* detModuleIdOffset */               
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (16u), /* detInstanceIdOffset */             
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (20u), /* detApiIdOffset */                  
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (24u), /* detErrorIdOffset */                
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (28u), /* readyFlagOffset */                 
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (32u), /* endRamExecFlagOffset */            
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (36u), /* ramExecFlagOffset */               
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (40u)  /* detReportFlag */                   
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Cfg.c
 *********************************************************************************************************************/
