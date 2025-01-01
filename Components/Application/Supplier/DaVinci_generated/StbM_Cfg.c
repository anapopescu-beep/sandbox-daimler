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
 *            Module: StbM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: StbM_Cfg.c
 *   Generation Time: 2023-07-10 14:36:09
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define STBM_CFG_SOURCE

/**********************************************************************************************************************
 *  LOCAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "StbM.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Dummy symbolic name value for the shared memory memory section */
#define CommonSharedMemory                                 (INVALID_OSAPPLICATION)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  StbM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    StbM_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to StbM_PCPartitionConfig
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_PartitionIdentifiersType, STBM_CONST) StbM_PartitionIdentifiers[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV                 PCPartitionConfigIdx                                    */
  { /*     0 */ CommonSharedMemory         ,                   0u  /* CommonSharedMemory */          },
  { /*     1 */ OsApplication_Trusted_Core0,                   1u  /* OsApplication_Trusted_Core0 */ }
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeBasePartitionMapping
**********************************************************************************************************************/
/** 
  \var    StbM_TimeBasePartitionMapping
  \brief  Time base to partition mapping
  \details
  Element                                           Description
  IndirectionToGptClockStateIdx                     the index of the 0:1 relation pointing to StbM_GptClockState,StbM_GptClockState
  IndirectionToGptClockStatePartitionIdx            the partition index of the 0:1 relation pointing to StbM_GptClockState,StbM_GptClockState
  IndirectionToLocalClockStateIdx                   the index of the 0:1 relation pointing to StbM_LocalClockState,StbM_LocalClockState
  IndirectionToLocalClockStatePartitionIdx          the partition index of the 0:1 relation pointing to StbM_LocalClockState,StbM_LocalClockState
  IndirectionToLocalTimeStateIdx                    the index of the 1:1 relation pointing to one of StbM_LocalTimeState,StbM_LocalTimeState
  IndirectionToLocalTimeStatePartitionIdx           the partition index of the 1:1 relation pointing to one of StbM_LocalTimeState,StbM_LocalTimeState
  IndirectionToMainTimeStateIdx                     the index of the 1:1 relation pointing to one of StbM_MainTimeState,StbM_MainTimeState
  IndirectionToMainTimeStatePartitionIdx            the partition index of the 1:1 relation pointing to one of StbM_MainTimeState,StbM_MainTimeState
  IndirectionToTimeBaseConfigIdx                    the index of the 1:1 relation pointing to one of StbM_TimeBaseConfig,StbM_TimeBaseConfig
  IndirectionToTimeBaseConfigPartitionIdx           the partition index of the 1:1 relation pointing to one of StbM_TimeBaseConfig,StbM_TimeBaseConfig
  IndirectionToVirtualLocalTimeStateIdx             the index of the 1:1 relation pointing to one of StbM_VirtualLocalTimeState,StbM_VirtualLocalTimeState
  IndirectionToVirtualLocalTimeStatePartitionIdx    the partition index of the 1:1 relation pointing to one of StbM_VirtualLocalTimeState,StbM_VirtualLocalTimeState
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_TimeBasePartitionMappingType, STBM_CONST) StbM_TimeBasePartitionMapping[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IndirectionToGptClockStateIdx                                                                                    IndirectionToGptClockStatePartitionIdx                            IndirectionToLocalClockStateIdx                                               IndirectionToLocalClockStatePartitionIdx                            IndirectionToLocalTimeStateIdx                                               IndirectionToLocalTimeStatePartitionIdx                            IndirectionToMainTimeStateIdx                                               IndirectionToMainTimeStatePartitionIdx                            IndirectionToTimeBaseConfigIdx                                               IndirectionToTimeBaseConfigPartitionIdx                                     IndirectionToVirtualLocalTimeStateIdx                                               IndirectionToVirtualLocalTimeStatePartitionIdx                                  Referable Keys */
  { /*     0 */                            0u  /* /ActiveEcuC/Gpt/GptChannelConfigSet/GptChannelConfiguration_StbM_LocalTime */,                                     0u  /* CommonSharedMemory */,                              0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,                                       0u  /* CommonSharedMemory */,                             0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,                                      0u  /* CommonSharedMemory */,                            0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,                                     0u  /* CommonSharedMemory */,                             0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,                                      1u  /* OsApplication_Trusted_Core0 */,                                    0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,                                             0u  /* CommonSharedMemory */ }   /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_PCPartitionConfig
**********************************************************************************************************************/
/** 
  \var    StbM_PCPartitionConfig
  \details
  Element                            Description
  GptClockConfig                     the pointer to StbM_GptClockConfig
  GptClockState                      the pointer to StbM_GptClockState
  Initialized                        the pointer to StbM_Initialized
  LocalClockConfig                   the pointer to StbM_LocalClockConfig
  LocalClockState                    the pointer to StbM_LocalClockState
  LocalTimeConfig                    the pointer to StbM_LocalTimeConfig
  LocalTimeState                     the pointer to StbM_LocalTimeState
  MainTimeState                      the pointer to StbM_MainTimeState
  ReceivedTimeState                  the pointer to StbM_ReceivedTimeState
  Status                             the pointer to StbM_Status
  SyncTimeRecordingBlock             the pointer to StbM_SyncTimeRecordingBlock
  SyncTimeRecordingHeader            the pointer to StbM_SyncTimeRecordingHeader
  TimeBaseConfig                     the pointer to StbM_TimeBaseConfig
  TimeBaseState                      the pointer to StbM_TimeBaseState
  TimeLeapClearState                 the pointer to StbM_TimeLeapClearState
  TimeLeapConfig                     the pointer to StbM_TimeLeapConfig
  TimeLeapState                      the pointer to StbM_TimeLeapState
  TimeRecordingConfig                the pointer to StbM_TimeRecordingConfig
  TimeRecordingState                 the pointer to StbM_TimeRecordingState
  TimeRecordingSyncCallback          the pointer to StbM_TimeRecordingSyncCallback
  TimeoutConfig                      the pointer to StbM_TimeoutConfig
  TimeoutState                       the pointer to StbM_TimeoutState
  UserDataState                      the pointer to StbM_UserDataState
  VirtualLocalTimeState              the pointer to StbM_VirtualLocalTimeState
  SizeOfGptClockConfig               the number of accomplishable value elements in StbM_GptClockConfig
  SizeOfGptClockState                the number of accomplishable value elements in StbM_GptClockState
  SizeOfLocalClockConfig             the number of accomplishable value elements in StbM_LocalClockConfig
  SizeOfLocalClockState              the number of accomplishable value elements in StbM_LocalClockState
  SizeOfLocalTimeConfig              the number of accomplishable value elements in StbM_LocalTimeConfig
  SizeOfLocalTimeState               the number of accomplishable value elements in StbM_LocalTimeState
  SizeOfMainTimeState                the number of accomplishable value elements in StbM_MainTimeState
  SizeOfSyncTimeRecordingBlock       the number of accomplishable value elements in StbM_SyncTimeRecordingBlock
  SizeOfSyncTimeRecordingHeader      the number of accomplishable value elements in StbM_SyncTimeRecordingHeader
  SizeOfTimeBaseConfig               the number of accomplishable value elements in StbM_TimeBaseConfig
  SizeOfTimeLeapConfig               the number of accomplishable value elements in StbM_TimeLeapConfig
  SizeOfTimeRecordingConfig          the number of accomplishable value elements in StbM_TimeRecordingConfig
  SizeOfTimeRecordingSyncCallback    the number of accomplishable value elements in StbM_TimeRecordingSyncCallback
  SizeOfTimeoutConfig                the number of accomplishable value elements in StbM_TimeoutConfig
  SizeOfUserDataState                the number of accomplishable value elements in StbM_UserDataState
  SizeOfVirtualLocalTimeState        the number of accomplishable value elements in StbM_VirtualLocalTimeState
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_PCPartitionConfigType, STBM_CONST) StbM_PCPartitionConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CommonSharedMemory] */
      NULL_PTR                                          /**< the struct is deactivated because all elements are deactivated. */
    , StbM_GptClockState.raw                            /**< the pointer to StbM_GptClockState in CommonSharedMemory */
    , (&(StbM_InitializedCommonSharedMemory))           /**< the pointer to StbM_Initialized in CommonSharedMemory */
    , NULL_PTR                                          /**< the struct is deactivated because all elements are deactivated. */
    , StbM_LocalClockState.raw                          /**< the pointer to StbM_LocalClockState in CommonSharedMemory */
    , NULL_PTR                                          /**< the struct is deactivated because all elements are deactivated. */
    , StbM_LocalTimeState.raw                           /**< the pointer to StbM_LocalTimeState in CommonSharedMemory */
    , StbM_MainTimeState.raw                            /**< the pointer to StbM_MainTimeState in CommonSharedMemory */
    , NULL_PTR                                          /**< the pointer to StbM_ReceivedTimeState in CommonSharedMemory */
    , NULL_PTR                                          /**< the pointer to StbM_Status in CommonSharedMemory */
    , NULL_PTR                                          /**< the pointer to StbM_SyncTimeRecordingBlock in CommonSharedMemory */
    , NULL_PTR                                          /**< the struct is deactivated because all elements are deactivated. */
    , NULL_PTR                                          /**< the struct is deactivated because all elements are deactivated. */
    , NULL_PTR                                          /**< the pointer to StbM_TimeBaseState in CommonSharedMemory */
    , NULL_PTR                                          /**< the pointer to StbM_TimeLeapClearState in CommonSharedMemory */
    , NULL_PTR                                          /**< the struct is deactivated because all elements are deactivated. */
    , NULL_PTR                                          /**< the pointer to StbM_TimeLeapState in CommonSharedMemory */
    , NULL_PTR                                          /**< the struct is deactivated because all elements are deactivated. */
    , NULL_PTR                                          /**< the pointer to StbM_TimeRecordingState in CommonSharedMemory */
    , NULL_PTR                                          /**< the struct is deactivated because all elements are deactivated. */
    , NULL_PTR                                          /**< the struct is deactivated because all elements are deactivated. */
    , NULL_PTR                                          /**< the pointer to StbM_TimeoutState in CommonSharedMemory */
    , NULL_PTR                                          /**< the pointer to StbM_UserDataState in CommonSharedMemory */
    , StbM_VirtualLocalTimeState.raw                    /**< the pointer to StbM_VirtualLocalTimeState in CommonSharedMemory */
    , 0u                                                /**< the number of elements in StbM_GptClockConfig in CommonSharedMemory */
    , 1u                                                /**< the number of elements in StbM_GptClockState in CommonSharedMemory */
    , 0u                                                /**< the number of elements in StbM_LocalClockConfig in CommonSharedMemory */
    , 1u                                                /**< the number of elements in StbM_LocalClockState in CommonSharedMemory */
    , 0u                                                /**< the number of elements in StbM_LocalTimeConfig in CommonSharedMemory */
    , 1u                                                /**< the number of elements in StbM_LocalTimeState in CommonSharedMemory */
    , 1u                                                /**< the number of elements in StbM_MainTimeState in CommonSharedMemory */
    , 0u                                                /**< the number of elements in StbM_SyncTimeRecordingBlock in CommonSharedMemory */
    , 0u                                                /**< the number of elements in StbM_SyncTimeRecordingHeader in CommonSharedMemory */
    , 0u                                                /**< the number of elements in StbM_TimeBaseConfig in CommonSharedMemory */
    , 0u                                                /**< the number of elements in StbM_TimeLeapConfig in CommonSharedMemory */
    , 0u                                                /**< the number of elements in StbM_TimeRecordingConfig in CommonSharedMemory */
    , 0u                                                /**< the number of elements in StbM_TimeRecordingSyncCallback in CommonSharedMemory */
    , 0u                                                /**< the number of elements in StbM_TimeoutConfig in CommonSharedMemory */
    , 0u                                                /**< the number of elements in StbM_UserDataState in CommonSharedMemory */
    , 1u                                                /**< the number of elements in StbM_VirtualLocalTimeState in CommonSharedMemory */
  },
  { /* Index: 1 Keys: [OsApplication_Trusted_Core0] */
      StbM_GptClockConfig                               /**< the pointer to StbM_GptClockConfig in OsApplication_Trusted_Core0 */
    , NULL_PTR                                          /**< the pointer to StbM_GptClockState in OsApplication_Trusted_Core0 */
    , (&(StbM_InitializedOsApplication_Trusted_Core0))  /**< the pointer to StbM_Initialized in OsApplication_Trusted_Core0 */
    , StbM_LocalClockConfig                             /**< the pointer to StbM_LocalClockConfig in OsApplication_Trusted_Core0 */
    , NULL_PTR                                          /**< the pointer to StbM_LocalClockState in OsApplication_Trusted_Core0 */
    , StbM_LocalTimeConfig                              /**< the pointer to StbM_LocalTimeConfig in OsApplication_Trusted_Core0 */
    , NULL_PTR                                          /**< the pointer to StbM_LocalTimeState in OsApplication_Trusted_Core0 */
    , NULL_PTR                                          /**< the pointer to StbM_MainTimeState in OsApplication_Trusted_Core0 */
    , StbM_ReceivedTimeState.raw                        /**< the pointer to StbM_ReceivedTimeState in OsApplication_Trusted_Core0 */
    , StbM_Status.raw                                   /**< the pointer to StbM_Status in OsApplication_Trusted_Core0 */
    , StbM_SyncTimeRecordingBlock.raw                   /**< the pointer to StbM_SyncTimeRecordingBlock in OsApplication_Trusted_Core0 */
    , StbM_SyncTimeRecordingHeader                      /**< the pointer to StbM_SyncTimeRecordingHeader in OsApplication_Trusted_Core0 */
    , StbM_TimeBaseConfig                               /**< the pointer to StbM_TimeBaseConfig in OsApplication_Trusted_Core0 */
    , StbM_TimeBaseState.raw                            /**< the pointer to StbM_TimeBaseState in OsApplication_Trusted_Core0 */
    , StbM_TimeLeapClearState.raw                       /**< the pointer to StbM_TimeLeapClearState in OsApplication_Trusted_Core0 */
    , StbM_TimeLeapConfig                               /**< the pointer to StbM_TimeLeapConfig in OsApplication_Trusted_Core0 */
    , StbM_TimeLeapState.raw                            /**< the pointer to StbM_TimeLeapState in OsApplication_Trusted_Core0 */
    , StbM_TimeRecordingConfig                          /**< the pointer to StbM_TimeRecordingConfig in OsApplication_Trusted_Core0 */
    , StbM_TimeRecordingState.raw                       /**< the pointer to StbM_TimeRecordingState in OsApplication_Trusted_Core0 */
    , StbM_TimeRecordingSyncCallback                    /**< the pointer to StbM_TimeRecordingSyncCallback in OsApplication_Trusted_Core0 */
    , StbM_TimeoutConfig                                /**< the pointer to StbM_TimeoutConfig in OsApplication_Trusted_Core0 */
    , StbM_TimeoutState.raw                             /**< the pointer to StbM_TimeoutState in OsApplication_Trusted_Core0 */
    , StbM_UserDataState.raw                            /**< the pointer to StbM_UserDataState in OsApplication_Trusted_Core0 */
    , NULL_PTR                                          /**< the pointer to StbM_VirtualLocalTimeState in OsApplication_Trusted_Core0 */
    , 1u                                                /**< the number of elements in StbM_GptClockConfig in OsApplication_Trusted_Core0 */
    , 0u                                                /**< the number of elements in StbM_GptClockState in OsApplication_Trusted_Core0 */
    , 1u                                                /**< the number of elements in StbM_LocalClockConfig in OsApplication_Trusted_Core0 */
    , 0u                                                /**< the number of elements in StbM_LocalClockState in OsApplication_Trusted_Core0 */
    , 1u                                                /**< the number of elements in StbM_LocalTimeConfig in OsApplication_Trusted_Core0 */
    , 0u                                                /**< the number of elements in StbM_LocalTimeState in OsApplication_Trusted_Core0 */
    , 0u                                                /**< the number of elements in StbM_MainTimeState in OsApplication_Trusted_Core0 */
    , 1u                                                /**< the number of elements in StbM_SyncTimeRecordingBlock in OsApplication_Trusted_Core0 */
    , 1u                                                /**< the number of elements in StbM_SyncTimeRecordingHeader in OsApplication_Trusted_Core0 */
    , 1u                                                /**< the number of elements in StbM_TimeBaseConfig in OsApplication_Trusted_Core0 */
    , 1u                                                /**< the number of elements in StbM_TimeLeapConfig in OsApplication_Trusted_Core0 */
    , 1u                                                /**< the number of elements in StbM_TimeRecordingConfig in OsApplication_Trusted_Core0 */
    , 1u                                                /**< the number of elements in StbM_TimeRecordingSyncCallback in OsApplication_Trusted_Core0 */
    , 1u                                                /**< the number of elements in StbM_TimeoutConfig in OsApplication_Trusted_Core0 */
    , 1u                                                /**< the number of elements in StbM_UserDataState in OsApplication_Trusted_Core0 */
    , 0u                                                /**< the number of elements in StbM_VirtualLocalTimeState in OsApplication_Trusted_Core0 */
  }
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  StbM_GptClockState
**********************************************************************************************************************/
/** 
  \var    StbM_GptClockState
  \brief  All relevant state data for Gpt local clock.
  \details
  Element             Description
  GptChannelActive    Indicates if the used Gpt channel is active.
*/ 
#define STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_GptClockStateUType, STBM_VAR_NO_INIT) StbM_GptClockState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Gpt/GptChannelConfigSet/GptChannelConfiguration_StbM_LocalTime] */

#define STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_InitializedCommonSharedMemory
**********************************************************************************************************************/
/** 
  \var    StbM_InitializedCommonSharedMemory
  \brief  Initialization state of the StbM. TRUE, if StbM_Init() has been called, else FALSE.
*/ 
#define STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_InitializedType, STBM_VAR_CLEARED) StbM_InitializedCommonSharedMemory = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_LocalClockState
**********************************************************************************************************************/
/** 
  \var    StbM_LocalClockState
  \brief  State table for Local Time unit.
  \details
  Element         Description
  ElapsedTime     Elapsed time of the local clock since last synchronization event. This can be either a counter value or a real time.
  LastReadTime    Last read time of the local clock. This can be either a counter value or a real time.
*/ 
#define STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_LocalClockStateUType, STBM_VAR_NO_INIT) StbM_LocalClockState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */

#define STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_LocalTimeState
**********************************************************************************************************************/
/** 
  \var    StbM_LocalTimeState
  \brief  Local time state table.
  \details
  Element             Description
  LocalTimeUpdated    Indicate if LocalTime is updated and therefore valid, hence can be used without recalculating it. (E_OK | E_NOT_OK)
  LocalTime           TL (current corrected local time).
*/ 
#define STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_LocalTimeStateUType, STBM_VAR_NO_INIT) StbM_LocalTimeState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */

#define STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_MainTimeState
**********************************************************************************************************************/
/** 
  \var    StbM_MainTimeState
  \brief  Main time state table.
  \details
  Element                 Description
  GlobalTimeSync          TGsync (local time after update).
  VirtualLocalTimeSync    TVsync (virtual local time at last synchronization event).
*/ 
#define STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_MainTimeStateUType, STBM_VAR_NO_INIT) StbM_MainTimeState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */

#define STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_VirtualLocalTimeState
**********************************************************************************************************************/
/** 
  \var    StbM_VirtualLocalTimeState
  \brief  Virtual local time state table.
  \details
  Element                                         Description
  VirtualLocalTime                                TV (current virtual local time).
  VirtualLocalTimeElapsedAfterAdaptionInterval    TV elapsed after adaption interval (virtual local time elapsed after offset correction adaption interval).
*/ 
#define STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_VirtualLocalTimeStateUType, STBM_VAR_NO_INIT) StbM_VirtualLocalTimeState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */

#define STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


#define STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
#include "StbM_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

VAR(boolean, STBM_VAR_NO_INIT) StbM_PreInitialized;
VAR(boolean, STBM_VAR_NO_INIT) StbM_PostInitialized;

#define STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
#include "StbM_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: StbM_Cfg.c
 *********************************************************************************************************************/
