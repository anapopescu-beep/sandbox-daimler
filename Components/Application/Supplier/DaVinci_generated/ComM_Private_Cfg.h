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
 *            Module: ComM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ComM_Private_Cfg.h
 *   Generation Time: 2023-07-10 14:36:11
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined(COMM_PRIVATE_CFG_H)
#define COMM_PRIVATE_CFG_H
/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
#include "ComM.h"
#include "Com.h"
#include "Appl_Cbk.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCGetRootDataMacros  ComM Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define ComM_GetPCPartitionConfigOfPCConfig()                                                       ComM_ConfigPtr->PCPartitionConfigOfPCConfig
#define ComM_GetChannelOfPCPartitionConfig()                                                        ComM_GetPCPartitionConfigOfPCConfig()[(0)].ChannelOfPCPartitionConfig
#define ComM_GetChannelPbOfPCPartitionConfig()                                                      ComM_GetPCPartitionConfigOfPCConfig()[(0)].ChannelPbOfPCPartitionConfig
#define ComM_GetPncChannelMappingOfPCPartitionConfig()                                              ComM_GetPCPartitionConfigOfPCConfig()[(0)].PncChannelMappingOfPCPartitionConfig
#define ComM_GetPncSignalIndOfPCPartitionConfig()                                                   ComM_GetPCPartitionConfigOfPCConfig()[(0)].PncSignalIndOfPCPartitionConfig
#define ComM_GetPncSignalOfPCPartitionConfig()                                                      ComM_GetPCPartitionConfigOfPCConfig()[(0)].PncSignalOfPCPartitionConfig
#define ComM_GetUserByteMaskOfPCPartitionConfig()                                                   ComM_GetPCPartitionConfigOfPCConfig()[(0)].UserByteMaskOfPCPartitionConfig
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCGetConstantDuplicatedRootDataMacros  ComM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define ComM_GetPartitionIdentifiersOfPCConfig()                                                    ComM_PartitionIdentifiers  /**< the pointer to ComM_PartitionIdentifiers */
#define ComM_GetSizeOfPartitionIdentifiersOfPCConfig()                                              1u  /**< the number of accomplishable value elements in ComM_PartitionIdentifiers */
#define ComM_GetActiveComModeOfPCPartitionConfig(partitionIndex)                                    ComM_ActiveComMode.raw  /**< the pointer to ComM_ActiveComMode */
#define ComM_GetActivePncComModeOfPCPartitionConfig(partitionIndex)                                 ComM_ActivePncComMode.raw  /**< the pointer to ComM_ActivePncComMode */
#define ComM_GetBusComModeReqOfPCPartitionConfig(partitionIndex)                                    ComM_BusComModeReq.raw  /**< the pointer to ComM_BusComModeReq */
#define ComM_GetBusPncComModeReqOfPCPartitionConfig(partitionIndex)                                 ComM_BusPncComModeReq.raw  /**< the pointer to ComM_BusPncComModeReq */
#define ComM_GetBusSmStateOfPCPartitionConfig(partitionIndex)                                       ComM_BusSmState.raw  /**< the pointer to ComM_BusSmState */
#define ComM_GetComAllowedOfPCPartitionConfig(partitionIndex)                                       ComM_ComAllowed.raw  /**< the pointer to ComM_ComAllowed */
#define ComM_GetDcmRequestActiveOfPCPartitionConfig(partitionIndex)                                 ComM_DcmRequestActive.raw  /**< the pointer to ComM_DcmRequestActive */
#define ComM_GetEcuMWakeUpIndicatedOfPCPartitionConfig(partitionIndex)                              ComM_EcuMWakeUpIndicated  /**< the pointer to ComM_EcuMWakeUpIndicated */
#define ComM_GetEiraTxSignalIndirectionOfPCPartitionConfig()                                        ComM_EiraTxSignalIndirection  /**< the pointer to ComM_EiraTxSignalIndirection */
#define ComM_GetInhibitionOfPCPartitionConfig(partitionIndex)                                       (&(ComM_Inhibition))  /**< the pointer to ComM_Inhibition */
#define ComM_GetInitStatusOfPCPartitionConfig(partitionIndex)                                       (&(ComM_InitStatus))  /**< the pointer to ComM_InitStatus */
#define ComM_GetNmStartUpIndicatedOfPCPartitionConfig(partitionIndex)                               ComM_NmStartUpIndicated  /**< the pointer to ComM_NmStartUpIndicated */
#define ComM_GetPncOfPCPartitionConfig()                                                            ComM_Pnc  /**< the pointer to ComM_Pnc */
#define ComM_GetPncPSleepTimerOfPCPartitionConfig(partitionIndex)                                   ComM_PncPSleepTimer.raw  /**< the pointer to ComM_PncPSleepTimer */
#define ComM_GetPncPbIndOfPCPartitionConfig()                                                       ComM_PncPbInd  /**< the pointer to ComM_PncPbInd */
#define ComM_GetPncPbOfPCPartitionConfig()                                                          ComM_PncPb  /**< the pointer to ComM_PncPb */
#define ComM_GetPncSignalValuesOfPCPartitionConfig(partitionIndex)                                  ComM_PncSignalValues.raw  /**< the pointer to ComM_PncSignalValues */
#define ComM_GetPncToChannelRoutingStateOfPCPartitionConfig(partitionIndex)                         ComM_PncToChannelRoutingState.raw  /**< the pointer to ComM_PncToChannelRoutingState */
#define ComM_GetPostInitializedOfPCPartitionConfig(partitionIndex)                                  ComM_PostInitialized  /**< the pointer to ComM_PostInitialized */
#define ComM_GetResetRequiredOfPCPartitionConfig(partitionIndex)                                    ComM_ResetRequired.raw  /**< the pointer to ComM_ResetRequired */
#define ComM_GetSizeOfChannelOfPCPartitionConfig()                                                  2u  /**< the number of accomplishable value elements in ComM_Channel */
#define ComM_GetSizeOfChannelPbOfPCPartitionConfig()                                                2u  /**< the number of accomplishable value elements in ComM_ChannelPb */
#define ComM_GetSizeOfEcuMWakeUpIndicatedOfPCPartitionConfig(partitionIndex)                        1u  /**< the number of accomplishable value elements in ComM_EcuMWakeUpIndicated */
#define ComM_GetSizeOfEiraTxSignalIndirectionOfPCPartitionConfig()                                  3u  /**< the number of accomplishable value elements in ComM_EiraTxSignalIndirection */
#define ComM_GetSizeOfNmStartUpIndicatedOfPCPartitionConfig(partitionIndex)                         1u  /**< the number of accomplishable value elements in ComM_NmStartUpIndicated */
#define ComM_GetSizeOfPncChannelMappingOfPCPartitionConfig()                                        2u  /**< the number of accomplishable value elements in ComM_PncChannelMapping */
#define ComM_GetSizeOfPncOfPCPartitionConfig()                                                      2u  /**< the number of accomplishable value elements in ComM_Pnc */
#define ComM_GetSizeOfPncPbIndOfPCPartitionConfig()                                                 2u  /**< the number of accomplishable value elements in ComM_PncPbInd */
#define ComM_GetSizeOfPncPbOfPCPartitionConfig()                                                    2u  /**< the number of accomplishable value elements in ComM_PncPb */
#define ComM_GetSizeOfPncSignalIndOfPCPartitionConfig()                                             2u  /**< the number of accomplishable value elements in ComM_PncSignalInd */
#define ComM_GetSizeOfPncSignalOfPCPartitionConfig()                                                3u  /**< the number of accomplishable value elements in ComM_PncSignal */
#define ComM_GetSizeOfPncSignalValuesOfPCPartitionConfig(partitionIndex)                            14u  /**< the number of accomplishable value elements in ComM_PncSignalValues */
#define ComM_GetSizeOfPostInitializedOfPCPartitionConfig(partitionIndex)                            1u  /**< the number of accomplishable value elements in ComM_PostInitialized */
#define ComM_GetSizeOfUserByteMaskOfPCPartitionConfig()                                             3u  /**< the number of accomplishable value elements in ComM_UserByteMask */
#define ComM_GetSizeOfUserOfPCPartitionConfig()                                                     3u  /**< the number of accomplishable value elements in ComM_User */
#define ComM_GetSizeOfUserPncByteMaskOfPCPartitionConfig()                                          2u  /**< the number of accomplishable value elements in ComM_UserPncByteMask */
#define ComM_GetSizeOfUserReqFullComOfPCPartitionConfig(partitionIndex)                             1u  /**< the number of accomplishable value elements in ComM_UserReqFullCom */
#define ComM_GetSizeOfUserReqPncFullComOfPCPartitionConfig(partitionIndex)                          2u  /**< the number of accomplishable value elements in ComM_UserReqPncFullCom */
#define ComM_GetUserOfPCPartitionConfig()                                                           ComM_User  /**< the pointer to ComM_User */
#define ComM_GetUserPncByteMaskOfPCPartitionConfig()                                                ComM_UserPncByteMask  /**< the pointer to ComM_UserPncByteMask */
#define ComM_GetUserReqFullComOfPCPartitionConfig(partitionIndex)                                   ComM_UserReqFullCom  /**< the pointer to ComM_UserReqFullCom */
#define ComM_GetUserReqPncFullComOfPCPartitionConfig(partitionIndex)                                ComM_UserReqPncFullCom  /**< the pointer to ComM_UserReqPncFullCom */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCGetDuplicatedRootDataMacros  ComM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define ComM_GetSizeOfActiveComModeOfPCPartitionConfig(partitionIndex)                              ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_ActiveComMode */
#define ComM_GetSizeOfActivePncComModeOfPCPartitionConfig(partitionIndex)                           ComM_GetSizeOfPncOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_ActivePncComMode */
#define ComM_GetSizeOfBusComModeReqOfPCPartitionConfig(partitionIndex)                              ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_BusComModeReq */
#define ComM_GetSizeOfBusPncComModeReqOfPCPartitionConfig(partitionIndex)                           ComM_GetSizeOfPncOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_BusPncComModeReq */
#define ComM_GetSizeOfBusSmStateOfPCPartitionConfig(partitionIndex)                                 ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_BusSmState */
#define ComM_GetSizeOfComAllowedOfPCPartitionConfig(partitionIndex)                                 ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_ComAllowed */
#define ComM_GetSizeOfDcmRequestActiveOfPCPartitionConfig(partitionIndex)                           ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_DcmRequestActive */
#define ComM_GetSizeOfPncPSleepTimerOfPCPartitionConfig(partitionIndex)                             ComM_GetSizeOfPncOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_PncPSleepTimer */
#define ComM_GetSizeOfPncToChannelRoutingStateOfPCPartitionConfig(partitionIndex)                   ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_PncToChannelRoutingState */
#define ComM_GetSizeOfResetRequiredOfPCPartitionConfig(partitionIndex)                              ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_ResetRequired */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCGetDataMacros  ComM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define ComM_GetActiveComMode(Index, partitionIndex)                                                (ComM_GetActiveComModeOfPCPartitionConfig(partitionIndex)[(Index)])
#define ComM_GetActivePncComMode(Index, partitionIndex)                                             (ComM_GetActivePncComModeOfPCPartitionConfig(partitionIndex)[(Index)])
#define ComM_GetBusComModeReq(Index, partitionIndex)                                                (ComM_GetBusComModeReqOfPCPartitionConfig(partitionIndex)[(Index)])
#define ComM_GetBusPncComModeReq(Index, partitionIndex)                                             (ComM_GetBusPncComModeReqOfPCPartitionConfig(partitionIndex)[(Index)])
#define ComM_GetBusSmState(Index, partitionIndex)                                                   (ComM_GetBusSmStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define ComM_IsEnabledOfChannel(Index)                                                              ((ComM_GetChannelOfPCPartitionConfig()[(Index)].EnabledOfChannel) != FALSE)
#define ComM_GetGetCurrentBusSMModeApiOfChannel(Index)                                              (ComM_GetChannelOfPCPartitionConfig()[(Index)].GetCurrentBusSMModeApiOfChannel)
#define ComM_GetNmTypeOfChannel(Index)                                                              (ComM_GetChannelOfPCPartitionConfig()[(Index)].NmTypeOfChannel)
#define ComM_GetRequestBusSMModeApiOfChannel(Index)                                                 (ComM_GetChannelOfPCPartitionConfig()[(Index)].RequestBusSMModeApiOfChannel)
#define ComM_GetPncPbIndEndIdxOfChannelPb(Index)                                                    (ComM_GetChannelPbOfPCPartitionConfig()[(Index)].PncPbIndEndIdxOfChannelPb)
#define ComM_GetPncPbIndStartIdxOfChannelPb(Index)                                                  (ComM_GetChannelPbOfPCPartitionConfig()[(Index)].PncPbIndStartIdxOfChannelPb)
#define ComM_GetUserReqFullComEndIdxOfChannelPb(Index)                                              (ComM_GetChannelPbOfPCPartitionConfig()[(Index)].UserReqFullComEndIdxOfChannelPb)
#define ComM_GetUserReqFullComStartIdxOfChannelPb(Index)                                            (ComM_GetChannelPbOfPCPartitionConfig()[(Index)].UserReqFullComStartIdxOfChannelPb)
#define ComM_IsComAllowed(Index, partitionIndex)                                                    ((ComM_GetComAllowedOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE)
#define ComM_IsDcmRequestActive(Index, partitionIndex)                                              ((ComM_GetDcmRequestActiveOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE)
#define ComM_IsEcuMWakeUpIndicated(Index, partitionIndex)                                           ((ComM_GetEcuMWakeUpIndicatedOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE)
#define ComM_GetSymbolicNameValueOfEiraTxSignalIndirection(Index)                                   (ComM_GetEiraTxSignalIndirectionOfPCPartitionConfig()[(Index)].SymbolicNameValueOfEiraTxSignalIndirection)
#define ComM_GetInhibition(partitionIndex)                                                          ((*(ComM_GetInhibitionOfPCPartitionConfig(partitionIndex))))
#define ComM_GetInitStatus(partitionIndex)                                                          ((*(ComM_GetInitStatusOfPCPartitionConfig(partitionIndex))))
#define ComM_IsNmStartUpIndicated(Index, partitionIndex)                                            ((ComM_GetNmStartUpIndicatedOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE)
#define ComM_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                   (ComM_GetPartitionIdentifiersOfPCConfig()[(Index)].PCPartitionConfigIdxOfPartitionIdentifiers)
#define ComM_GetPartitionSNVOfPartitionIdentifiers(Index)                                           (ComM_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define ComM_GetClearMaskOfPnc(Index)                                                               (ComM_GetPncOfPCPartitionConfig()[(Index)].ClearMaskOfPnc)
#define ComM_GetPncIdOfPnc(Index)                                                                   ((PNCHandleType)ComM_GetPncOfPCPartitionConfig()[(Index)].PncIdOfPnc)
#define ComM_GetSetMaskOfPnc(Index)                                                                 (ComM_GetPncOfPCPartitionConfig()[(Index)].SetMaskOfPnc)
#define ComM_GetPncChannelMapping(Index)                                                            (ComM_GetPncChannelMappingOfPCPartitionConfig()[(Index)])
#define ComM_GetPncPSleepTimer(Index, partitionIndex)                                               (ComM_GetPncPSleepTimerOfPCPartitionConfig(partitionIndex)[(Index)])
#define ComM_GetPncChannelMappingEndIdxOfPncPb(Index)                                               (ComM_GetPncPbOfPCPartitionConfig()[(Index)].PncChannelMappingEndIdxOfPncPb)
#define ComM_GetPncChannelMappingStartIdxOfPncPb(Index)                                             (ComM_GetPncPbOfPCPartitionConfig()[(Index)].PncChannelMappingStartIdxOfPncPb)
#define ComM_GetPncSignalIndEndIdxOfPncPb(Index)                                                    (ComM_GetPncPbOfPCPartitionConfig()[(Index)].PncSignalIndEndIdxOfPncPb)
#define ComM_GetPncSignalIndStartIdxOfPncPb(Index)                                                  (ComM_GetPncPbOfPCPartitionConfig()[(Index)].PncSignalIndStartIdxOfPncPb)
#define ComM_GetSignalByteIndexOfPncPb(Index)                                                       (ComM_GetPncPbOfPCPartitionConfig()[(Index)].SignalByteIndexOfPncPb)
#define ComM_GetUserReqPncFullComEndIdxOfPncPb(Index)                                               (ComM_GetPncPbOfPCPartitionConfig()[(Index)].UserReqPncFullComEndIdxOfPncPb)
#define ComM_GetUserReqPncFullComStartIdxOfPncPb(Index)                                             (ComM_GetPncPbOfPCPartitionConfig()[(Index)].UserReqPncFullComStartIdxOfPncPb)
#define ComM_GetPncPbInd(Index)                                                                     (ComM_GetPncPbIndOfPCPartitionConfig()[(Index)])
#define ComM_GetChannelIdxOfPncSignal(Index)                                                        (ComM_GetPncSignalOfPCPartitionConfig()[(Index)].ChannelIdxOfPncSignal)
#define ComM_GetPncSignalValuesEndIdxOfPncSignal(Index)                                             (ComM_GetPncSignalOfPCPartitionConfig()[(Index)].PncSignalValuesEndIdxOfPncSignal)
#define ComM_GetPncSignalValuesStartIdxOfPncSignal(Index)                                           (ComM_GetPncSignalOfPCPartitionConfig()[(Index)].PncSignalValuesStartIdxOfPncSignal)
#define ComM_GetTypeOfPncSignal(Index)                                                              (ComM_GetPncSignalOfPCPartitionConfig()[(Index)].TypeOfPncSignal)
#define ComM_GetPncSignalInd(Index)                                                                 (ComM_GetPncSignalIndOfPCPartitionConfig()[(Index)])
#define ComM_GetPncSignalValues(Index, partitionIndex)                                              (ComM_GetPncSignalValuesOfPCPartitionConfig(partitionIndex)[(Index)])
#define ComM_GetPncToChannelRoutingState(Index, partitionIndex)                                     (ComM_GetPncToChannelRoutingStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define ComM_IsPostInitialized(Index, partitionIndex)                                               ((ComM_GetPostInitializedOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE)
#define ComM_IsResetRequired(Index, partitionIndex)                                                 ((ComM_GetResetRequiredOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE)
#define ComM_IsPncUserOfUser(Index)                                                                 ((ComM_GetUserOfPCPartitionConfig()[(Index)].PncUserOfUser) != FALSE)
#define ComM_GetUserByteMaskEndIdxOfUser(Index)                                                     (ComM_GetUserOfPCPartitionConfig()[(Index)].UserByteMaskEndIdxOfUser)
#define ComM_GetUserByteMaskStartIdxOfUser(Index)                                                   (ComM_GetUserOfPCPartitionConfig()[(Index)].UserByteMaskStartIdxOfUser)
#define ComM_GetUserPncByteMaskEndIdxOfUser(Index)                                                  (ComM_GetUserOfPCPartitionConfig()[(Index)].UserPncByteMaskEndIdxOfUser)
#define ComM_GetUserPncByteMaskLengthOfUser(Index)                                                  (ComM_GetUserOfPCPartitionConfig()[(Index)].UserPncByteMaskLengthOfUser)
#define ComM_GetUserPncByteMaskStartIdxOfUser(Index)                                                (ComM_GetUserOfPCPartitionConfig()[(Index)].UserPncByteMaskStartIdxOfUser)
#define ComM_GetChannelOfUserByteMask(Index)                                                        ((NetworkHandleType)ComM_GetUserByteMaskOfPCPartitionConfig()[(Index)].ChannelOfUserByteMask)
#define ComM_GetClearMaskOfUserByteMask(Index)                                                      (ComM_GetUserByteMaskOfPCPartitionConfig()[(Index)].ClearMaskOfUserByteMask)
#define ComM_GetSetMaskOfUserByteMask(Index)                                                        (ComM_GetUserByteMaskOfPCPartitionConfig()[(Index)].SetMaskOfUserByteMask)
#define ComM_GetPncIDOfUserPncByteMask(Index)                                                       ((PNCHandleType)ComM_GetUserPncByteMaskOfPCPartitionConfig()[(Index)].PncIDOfUserPncByteMask)
#define ComM_GetPncIdxOfUserPncByteMask(Index)                                                      (ComM_GetUserPncByteMaskOfPCPartitionConfig()[(Index)].PncIdxOfUserPncByteMask)
#define ComM_GetUserReqPncFullComIdxOfUserPncByteMask(Index)                                        (ComM_GetUserPncByteMaskOfPCPartitionConfig()[(Index)].UserReqPncFullComIdxOfUserPncByteMask)
#define ComM_GetUserReqFullCom(Index, partitionIndex)                                               (ComM_GetUserReqFullComOfPCPartitionConfig(partitionIndex)[(Index)])
#define ComM_GetUserReqPncFullCom(Index, partitionIndex)                                            (ComM_GetUserReqPncFullComOfPCPartitionConfig(partitionIndex)[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCGetDeduplicatedDataMacros  ComM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define ComM_GetBusTypeOfChannel(Index)                                                             COMM_BUS_TYPE_CAN  /**< The channel bus type */
#define ComM_GetGwTypeOfChannel(Index)                                                              COMM_GATEWAY_TYPE_NONE  /**< The partial network gateway type, relevant for channels attached to coordinated partial networks */
#define ComM_GetInhibitionInitValueOfChannel(Index)                                                 0x00u  /**< Initial value of the inhibition status of the channel */
#define ComM_IsNmSupportOfChannel(Index)                                                            (((TRUE)) != FALSE)  /**< Decides if the channel has NmType FULL or PASSIVE */
#define ComM_GetPartitionConfigIdxOfChannel(Index)                                                  0u  /**< the index of the 1:1 relation pointing to ComM_PCPartitionConfig */
#define ComM_IsPncNmRequestOfChannel(Index)                                                         (((TRUE)) != FALSE)  /**< Decides if a Nm message shall be sent immediately after partial network state changes */
#define ComM_IsResetAfterForcingNoCommOfChannel(Index)                                              (((TRUE)) != FALSE)  /**< Decides if ComM shall force an ECU reset after limited channel entered NO_COM */
#define ComM_IsSilentSupportOfChannel(Index)                                                        (((TRUE)) != FALSE)  /**< Decides if the channel supports Silent mode (TRUE if ETH or CAN without J1939NM and Nm or NmLightSilentDuration) */
#define ComM_GetWakeupStateOfChannel(Index)                                                         COMM_FULL_COM_READY_SLEEP  /**< Target channel state after a Passive Wake-up */
#define ComM_IsPncPbIndUsedOfChannelPb(Index)                                                       (((boolean)(ComM_GetPncPbIndStartIdxOfChannelPb(Index) != COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to ComM_PncPbInd */
#define ComM_IsUserReqFullComUsedOfChannelPb(Index)                                                 (((boolean)(ComM_GetUserReqFullComStartIdxOfChannelPb(Index) != COMM_NO_USERREQFULLCOMSTARTIDXOFCHANNELPB)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to ComM_UserReqFullCom */
#define ComM_IsPncChannelMappingUsedOfPncPb(Index)                                                  (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to ComM_PncChannelMapping */
#define ComM_IsPncSignalIndUsedOfPncPb(Index)                                                       (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to ComM_PncSignalInd */
#define ComM_GetBusTypeIdOfPncSignal(Index)                                                         0u  /**< For EIRA RX Signals: An internal id for the BusType */
#define ComM_IsChannelUsedOfPncSignal(Index)                                                        (((boolean)(ComM_GetChannelIdxOfPncSignal(Index) != COMM_NO_CHANNELIDXOFPNCSIGNAL)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to ComM_Channel */
#define ComM_IsPncSignalValuesUsedOfPncSignal(Index)                                                (((boolean)(ComM_GetPncSignalValuesStartIdxOfPncSignal(Index) != COMM_NO_PNCSIGNALVALUESSTARTIDXOFPNCSIGNAL)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to ComM_PncSignalValues */
#define ComM_GetSizeOfActiveComMode(partitionIndex)                                                 ComM_GetSizeOfActiveComModeOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfActivePncComMode(partitionIndex)                                              ComM_GetSizeOfActivePncComModeOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfBusComModeReq(partitionIndex)                                                 ComM_GetSizeOfBusComModeReqOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfBusPncComModeReq(partitionIndex)                                              ComM_GetSizeOfBusPncComModeReqOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfBusSmState(partitionIndex)                                                    ComM_GetSizeOfBusSmStateOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfChannel()                                                                     ComM_GetSizeOfChannelOfPCPartitionConfig()
#define ComM_GetSizeOfChannelPb()                                                                   ComM_GetSizeOfChannelPbOfPCPartitionConfig()
#define ComM_GetSizeOfComAllowed(partitionIndex)                                                    ComM_GetSizeOfComAllowedOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfDcmRequestActive(partitionIndex)                                              ComM_GetSizeOfDcmRequestActiveOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfEcuMWakeUpIndicated(partitionIndex)                                           ComM_GetSizeOfEcuMWakeUpIndicatedOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfEiraTxSignalIndirection()                                                     ComM_GetSizeOfEiraTxSignalIndirectionOfPCPartitionConfig()
#define ComM_GetSizeOfNmStartUpIndicated(partitionIndex)                                            ComM_GetSizeOfNmStartUpIndicatedOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfPartitionIdentifiers()                                                        ComM_GetSizeOfPartitionIdentifiersOfPCConfig()
#define ComM_GetSizeOfPnc()                                                                         ComM_GetSizeOfPncOfPCPartitionConfig()
#define ComM_GetSizeOfPncChannelMapping()                                                           ComM_GetSizeOfPncChannelMappingOfPCPartitionConfig()
#define ComM_GetSizeOfPncPSleepTimer(partitionIndex)                                                ComM_GetSizeOfPncPSleepTimerOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfPncPb()                                                                       ComM_GetSizeOfPncPbOfPCPartitionConfig()
#define ComM_GetSizeOfPncPbInd()                                                                    ComM_GetSizeOfPncPbIndOfPCPartitionConfig()
#define ComM_GetSizeOfPncSignal()                                                                   ComM_GetSizeOfPncSignalOfPCPartitionConfig()
#define ComM_GetSizeOfPncSignalInd()                                                                ComM_GetSizeOfPncSignalIndOfPCPartitionConfig()
#define ComM_GetSizeOfPncSignalValues(partitionIndex)                                               ComM_GetSizeOfPncSignalValuesOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfPncToChannelRoutingState(partitionIndex)                                      ComM_GetSizeOfPncToChannelRoutingStateOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfPostInitialized(partitionIndex)                                               ComM_GetSizeOfPostInitializedOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfResetRequired(partitionIndex)                                                 ComM_GetSizeOfResetRequiredOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfUser()                                                                        ComM_GetSizeOfUserOfPCPartitionConfig()
#define ComM_GetSizeOfUserByteMask()                                                                ComM_GetSizeOfUserByteMaskOfPCPartitionConfig()
#define ComM_GetSizeOfUserPncByteMask()                                                             ComM_GetSizeOfUserPncByteMaskOfPCPartitionConfig()
#define ComM_GetSizeOfUserReqFullCom(partitionIndex)                                                ComM_GetSizeOfUserReqFullComOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfUserReqPncFullCom(partitionIndex)                                             ComM_GetSizeOfUserReqPncFullComOfPCPartitionConfig(partitionIndex)
#define ComM_GetPartitionConfigIdxOfUser(Index)                                                     0u  /**< the index of the 1:1 relation pointing to ComM_PCPartitionConfig */
#define ComM_IsUserByteMaskUsedOfUser(Index)                                                        (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to ComM_UserByteMask */
#define ComM_IsUserPncByteMaskUsedOfUser(Index)                                                     (((boolean)(ComM_GetUserPncByteMaskLengthOfUser(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to ComM_UserPncByteMask */
#define ComM_GetUserReqFullComIdxOfUserByteMask(Index)                                              0u  /**< the index of the 1:1 relation pointing to ComM_UserReqFullCom */
#define ComM_GetClearMaskOfUserPncByteMask(Index)                                                   0xFEu  /**< Clear-mask for clearing the bit which corresponds to this user */
#define ComM_GetSetMaskOfUserPncByteMask(Index)                                                     0x01u  /**< Set-mask for setting the bit which corresponds to this user */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCSetDataMacros  ComM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define ComM_SetActiveComMode(Index, Value, partitionIndex)                                         ComM_GetActiveComModeOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetActivePncComMode(Index, Value, partitionIndex)                                      ComM_GetActivePncComModeOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetBusComModeReq(Index, Value, partitionIndex)                                         ComM_GetBusComModeReqOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetBusPncComModeReq(Index, Value, partitionIndex)                                      ComM_GetBusPncComModeReqOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetBusSmState(Index, Value, partitionIndex)                                            ComM_GetBusSmStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetComAllowed(Index, Value, partitionIndex)                                            ComM_GetComAllowedOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetDcmRequestActive(Index, Value, partitionIndex)                                      ComM_GetDcmRequestActiveOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetEcuMWakeUpIndicated(Index, Value, partitionIndex)                                   ComM_GetEcuMWakeUpIndicatedOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetInhibition(Value, partitionIndex)                                                   (*(ComM_GetInhibitionOfPCPartitionConfig(partitionIndex))) = (Value)
#define ComM_SetInitStatus(Value, partitionIndex)                                                   (*(ComM_GetInitStatusOfPCPartitionConfig(partitionIndex))) = (Value)
#define ComM_SetNmStartUpIndicated(Index, Value, partitionIndex)                                    ComM_GetNmStartUpIndicatedOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetPncPSleepTimer(Index, Value, partitionIndex)                                        ComM_GetPncPSleepTimerOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetPncSignalValues(Index, Value, partitionIndex)                                       ComM_GetPncSignalValuesOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetPncToChannelRoutingState(Index, Value, partitionIndex)                              ComM_GetPncToChannelRoutingStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetPostInitialized(Index, Value, partitionIndex)                                       ComM_GetPostInitializedOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetResetRequired(Index, Value, partitionIndex)                                         ComM_GetResetRequiredOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetUserReqFullCom(Index, Value, partitionIndex)                                        ComM_GetUserReqFullComOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetUserReqPncFullCom(Index, Value, partitionIndex)                                     ComM_GetUserReqPncFullComOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCGetAddressOfDataMacros  ComM Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define ComM_GetAddrPncSignalValues(Index, partitionIndex)                                          (&ComM_GetPncSignalValues(((Index)), (partitionIndex)))
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCHasMacros  ComM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define ComM_HasActiveComMode(partitionIndex)                                                       (TRUE != FALSE)
#define ComM_HasActivePncComMode(partitionIndex)                                                    (TRUE != FALSE)
#define ComM_HasBusComModeReq(partitionIndex)                                                       (TRUE != FALSE)
#define ComM_HasBusPncComModeReq(partitionIndex)                                                    (TRUE != FALSE)
#define ComM_HasBusSmState(partitionIndex)                                                          (TRUE != FALSE)
#define ComM_HasChannel()                                                                           (ComM_GetChannelOfPCPartitionConfig() != NULL_PTR)
#define ComM_HasBusTypeOfChannel()                                                                  (TRUE != FALSE)
#define ComM_HasEnabledOfChannel()                                                                  (TRUE != FALSE)
#define ComM_HasGetCurrentBusSMModeApiOfChannel()                                                   (TRUE != FALSE)
#define ComM_HasGwTypeOfChannel()                                                                   (TRUE != FALSE)
#define ComM_HasInhibitionInitValueOfChannel()                                                      (TRUE != FALSE)
#define ComM_HasNmSupportOfChannel()                                                                (TRUE != FALSE)
#define ComM_HasNmTypeOfChannel()                                                                   (TRUE != FALSE)
#define ComM_HasPartitionConfigIdxOfChannel()                                                       (TRUE != FALSE)
#define ComM_HasPncNmRequestOfChannel()                                                             (TRUE != FALSE)
#define ComM_HasRequestBusSMModeApiOfChannel()                                                      (TRUE != FALSE)
#define ComM_HasResetAfterForcingNoCommOfChannel()                                                  (TRUE != FALSE)
#define ComM_HasSilentSupportOfChannel()                                                            (TRUE != FALSE)
#define ComM_HasWakeupStateOfChannel()                                                              (TRUE != FALSE)
#define ComM_HasChannelPb()                                                                         (ComM_GetChannelPbOfPCPartitionConfig() != NULL_PTR)
#define ComM_HasPncPbIndEndIdxOfChannelPb()                                                         (TRUE != FALSE)
#define ComM_HasPncPbIndStartIdxOfChannelPb()                                                       (TRUE != FALSE)
#define ComM_HasPncPbIndUsedOfChannelPb()                                                           (TRUE != FALSE)
#define ComM_HasUserReqFullComEndIdxOfChannelPb()                                                   (TRUE != FALSE)
#define ComM_HasUserReqFullComStartIdxOfChannelPb()                                                 (TRUE != FALSE)
#define ComM_HasUserReqFullComUsedOfChannelPb()                                                     (TRUE != FALSE)
#define ComM_HasComAllowed(partitionIndex)                                                          (TRUE != FALSE)
#define ComM_HasDcmRequestActive(partitionIndex)                                                    (TRUE != FALSE)
#define ComM_HasEcuMWakeUpIndicated(partitionIndex)                                                 (TRUE != FALSE)
#define ComM_HasEiraTxSignalIndirection()                                                           (TRUE != FALSE)
#define ComM_HasSymbolicNameValueOfEiraTxSignalIndirection()                                        (TRUE != FALSE)
#define ComM_HasInhibition(partitionIndex)                                                          (TRUE != FALSE)
#define ComM_HasInitStatus(partitionIndex)                                                          (TRUE != FALSE)
#define ComM_HasNmStartUpIndicated(partitionIndex)                                                  (TRUE != FALSE)
#define ComM_HasPartitionIdentifiers()                                                              (TRUE != FALSE)
#define ComM_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                        (TRUE != FALSE)
#define ComM_HasPartitionSNVOfPartitionIdentifiers()                                                (TRUE != FALSE)
#define ComM_HasPnc()                                                                               (TRUE != FALSE)
#define ComM_HasClearMaskOfPnc()                                                                    (TRUE != FALSE)
#define ComM_HasPncIdOfPnc()                                                                        (TRUE != FALSE)
#define ComM_HasSetMaskOfPnc()                                                                      (TRUE != FALSE)
#define ComM_HasPncChannelMapping()                                                                 (ComM_GetPncChannelMappingOfPCPartitionConfig() != NULL_PTR)
#define ComM_HasPncPSleepTimer(partitionIndex)                                                      (TRUE != FALSE)
#define ComM_HasPncPb()                                                                             (TRUE != FALSE)
#define ComM_HasPncChannelMappingEndIdxOfPncPb()                                                    (TRUE != FALSE)
#define ComM_HasPncChannelMappingStartIdxOfPncPb()                                                  (TRUE != FALSE)
#define ComM_HasPncChannelMappingUsedOfPncPb()                                                      (TRUE != FALSE)
#define ComM_HasPncSignalIndEndIdxOfPncPb()                                                         (TRUE != FALSE)
#define ComM_HasPncSignalIndStartIdxOfPncPb()                                                       (TRUE != FALSE)
#define ComM_HasPncSignalIndUsedOfPncPb()                                                           (TRUE != FALSE)
#define ComM_HasSignalByteIndexOfPncPb()                                                            (TRUE != FALSE)
#define ComM_HasUserReqPncFullComEndIdxOfPncPb()                                                    (TRUE != FALSE)
#define ComM_HasUserReqPncFullComStartIdxOfPncPb()                                                  (TRUE != FALSE)
#define ComM_HasPncPbInd()                                                                          (TRUE != FALSE)
#define ComM_HasPncSignal()                                                                         (ComM_GetPncSignalOfPCPartitionConfig() != NULL_PTR)
#define ComM_HasBusTypeIdOfPncSignal()                                                              (TRUE != FALSE)
#define ComM_HasChannelIdxOfPncSignal()                                                             (TRUE != FALSE)
#define ComM_HasChannelUsedOfPncSignal()                                                            (TRUE != FALSE)
#define ComM_HasPncSignalValuesEndIdxOfPncSignal()                                                  (TRUE != FALSE)
#define ComM_HasPncSignalValuesStartIdxOfPncSignal()                                                (TRUE != FALSE)
#define ComM_HasPncSignalValuesUsedOfPncSignal()                                                    (TRUE != FALSE)
#define ComM_HasTypeOfPncSignal()                                                                   (TRUE != FALSE)
#define ComM_HasPncSignalInd()                                                                      (ComM_GetPncSignalIndOfPCPartitionConfig() != NULL_PTR)
#define ComM_HasPncSignalValues(partitionIndex)                                                     (TRUE != FALSE)
#define ComM_HasPncToChannelRoutingState(partitionIndex)                                            (TRUE != FALSE)
#define ComM_HasPostInitialized(partitionIndex)                                                     (TRUE != FALSE)
#define ComM_HasResetRequired(partitionIndex)                                                       (TRUE != FALSE)
#define ComM_HasSizeOfActiveComMode(partitionIndex)                                                 (TRUE != FALSE)
#define ComM_HasSizeOfActivePncComMode(partitionIndex)                                              (TRUE != FALSE)
#define ComM_HasSizeOfBusComModeReq(partitionIndex)                                                 (TRUE != FALSE)
#define ComM_HasSizeOfBusPncComModeReq(partitionIndex)                                              (TRUE != FALSE)
#define ComM_HasSizeOfBusSmState(partitionIndex)                                                    (TRUE != FALSE)
#define ComM_HasSizeOfChannel()                                                                     (TRUE != FALSE)
#define ComM_HasSizeOfChannelPb()                                                                   (TRUE != FALSE)
#define ComM_HasSizeOfComAllowed(partitionIndex)                                                    (TRUE != FALSE)
#define ComM_HasSizeOfDcmRequestActive(partitionIndex)                                              (TRUE != FALSE)
#define ComM_HasSizeOfEcuMWakeUpIndicated(partitionIndex)                                           (TRUE != FALSE)
#define ComM_HasSizeOfEiraTxSignalIndirection()                                                     (TRUE != FALSE)
#define ComM_HasSizeOfNmStartUpIndicated(partitionIndex)                                            (TRUE != FALSE)
#define ComM_HasSizeOfPartitionIdentifiers()                                                        (TRUE != FALSE)
#define ComM_HasSizeOfPnc()                                                                         (TRUE != FALSE)
#define ComM_HasSizeOfPncChannelMapping()                                                           (TRUE != FALSE)
#define ComM_HasSizeOfPncPSleepTimer(partitionIndex)                                                (TRUE != FALSE)
#define ComM_HasSizeOfPncPb()                                                                       (TRUE != FALSE)
#define ComM_HasSizeOfPncPbInd()                                                                    (TRUE != FALSE)
#define ComM_HasSizeOfPncSignal()                                                                   (TRUE != FALSE)
#define ComM_HasSizeOfPncSignalInd()                                                                (TRUE != FALSE)
#define ComM_HasSizeOfPncSignalValues(partitionIndex)                                               (TRUE != FALSE)
#define ComM_HasSizeOfPncToChannelRoutingState(partitionIndex)                                      (TRUE != FALSE)
#define ComM_HasSizeOfPostInitialized(partitionIndex)                                               (TRUE != FALSE)
#define ComM_HasSizeOfResetRequired(partitionIndex)                                                 (TRUE != FALSE)
#define ComM_HasSizeOfUser()                                                                        (TRUE != FALSE)
#define ComM_HasSizeOfUserByteMask()                                                                (TRUE != FALSE)
#define ComM_HasSizeOfUserPncByteMask()                                                             (TRUE != FALSE)
#define ComM_HasSizeOfUserReqFullCom(partitionIndex)                                                (TRUE != FALSE)
#define ComM_HasSizeOfUserReqPncFullCom(partitionIndex)                                             (TRUE != FALSE)
#define ComM_HasUser()                                                                              (TRUE != FALSE)
#define ComM_HasPartitionConfigIdxOfUser()                                                          (TRUE != FALSE)
#define ComM_HasPncUserOfUser()                                                                     (TRUE != FALSE)
#define ComM_HasUserByteMaskEndIdxOfUser()                                                          (TRUE != FALSE)
#define ComM_HasUserByteMaskStartIdxOfUser()                                                        (TRUE != FALSE)
#define ComM_HasUserByteMaskUsedOfUser()                                                            (TRUE != FALSE)
#define ComM_HasUserPncByteMaskEndIdxOfUser()                                                       (TRUE != FALSE)
#define ComM_HasUserPncByteMaskLengthOfUser()                                                       (TRUE != FALSE)
#define ComM_HasUserPncByteMaskStartIdxOfUser()                                                     (TRUE != FALSE)
#define ComM_HasUserPncByteMaskUsedOfUser()                                                         (TRUE != FALSE)
#define ComM_HasUserByteMask()                                                                      (ComM_GetUserByteMaskOfPCPartitionConfig() != NULL_PTR)
#define ComM_HasChannelOfUserByteMask()                                                             (TRUE != FALSE)
#define ComM_HasClearMaskOfUserByteMask()                                                           (TRUE != FALSE)
#define ComM_HasSetMaskOfUserByteMask()                                                             (TRUE != FALSE)
#define ComM_HasUserReqFullComIdxOfUserByteMask()                                                   (TRUE != FALSE)
#define ComM_HasUserPncByteMask()                                                                   (TRUE != FALSE)
#define ComM_HasClearMaskOfUserPncByteMask()                                                        (TRUE != FALSE)
#define ComM_HasPncIDOfUserPncByteMask()                                                            (TRUE != FALSE)
#define ComM_HasPncIdxOfUserPncByteMask()                                                           (TRUE != FALSE)
#define ComM_HasSetMaskOfUserPncByteMask()                                                          (TRUE != FALSE)
#define ComM_HasUserReqPncFullComIdxOfUserPncByteMask()                                             (TRUE != FALSE)
#define ComM_HasUserReqFullCom(partitionIndex)                                                      (TRUE != FALSE)
#define ComM_HasUserReqPncFullCom(partitionIndex)                                                   (TRUE != FALSE)
#define ComM_HasPCConfig()                                                                          (TRUE != FALSE)
#define ComM_HasPCPartitionConfigOfPCConfig()                                                       (TRUE != FALSE)
#define ComM_HasPartitionIdentifiersOfPCConfig()                                                    (TRUE != FALSE)
#define ComM_HasSizeOfPartitionIdentifiersOfPCConfig()                                              (TRUE != FALSE)
#define ComM_HasPCPartitionConfig()                                                                 (ComM_GetPCPartitionConfigOfPCConfig() != NULL_PTR)
#define ComM_HasActiveComModeOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define ComM_HasActivePncComModeOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define ComM_HasBusComModeReqOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define ComM_HasBusPncComModeReqOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define ComM_HasBusSmStateOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define ComM_HasChannelOfPCPartitionConfig()                                                        (TRUE != FALSE)
#define ComM_HasChannelPbOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define ComM_HasComAllowedOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define ComM_HasDcmRequestActiveOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define ComM_HasEcuMWakeUpIndicatedOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define ComM_HasEiraTxSignalIndirectionOfPCPartitionConfig()                                        (TRUE != FALSE)
#define ComM_HasInhibitionOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define ComM_HasInitStatusOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define ComM_HasNmStartUpIndicatedOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define ComM_HasPncChannelMappingOfPCPartitionConfig()                                              (TRUE != FALSE)
#define ComM_HasPncOfPCPartitionConfig()                                                            (TRUE != FALSE)
#define ComM_HasPncPSleepTimerOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define ComM_HasPncPbIndOfPCPartitionConfig()                                                       (TRUE != FALSE)
#define ComM_HasPncPbOfPCPartitionConfig()                                                          (TRUE != FALSE)
#define ComM_HasPncSignalIndOfPCPartitionConfig()                                                   (TRUE != FALSE)
#define ComM_HasPncSignalOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define ComM_HasPncSignalValuesOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define ComM_HasPncToChannelRoutingStateOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define ComM_HasPostInitializedOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define ComM_HasResetRequiredOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define ComM_HasSizeOfActiveComModeOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define ComM_HasSizeOfActivePncComModeOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define ComM_HasSizeOfBusComModeReqOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define ComM_HasSizeOfBusPncComModeReqOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define ComM_HasSizeOfBusSmStateOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define ComM_HasSizeOfChannelOfPCPartitionConfig()                                                  (TRUE != FALSE)
#define ComM_HasSizeOfChannelPbOfPCPartitionConfig()                                                (TRUE != FALSE)
#define ComM_HasSizeOfComAllowedOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define ComM_HasSizeOfDcmRequestActiveOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define ComM_HasSizeOfEcuMWakeUpIndicatedOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define ComM_HasSizeOfEiraTxSignalIndirectionOfPCPartitionConfig()                                  (TRUE != FALSE)
#define ComM_HasSizeOfNmStartUpIndicatedOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define ComM_HasSizeOfPncChannelMappingOfPCPartitionConfig()                                        (TRUE != FALSE)
#define ComM_HasSizeOfPncOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define ComM_HasSizeOfPncPSleepTimerOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define ComM_HasSizeOfPncPbIndOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define ComM_HasSizeOfPncPbOfPCPartitionConfig()                                                    (TRUE != FALSE)
#define ComM_HasSizeOfPncSignalIndOfPCPartitionConfig()                                             (TRUE != FALSE)
#define ComM_HasSizeOfPncSignalOfPCPartitionConfig()                                                (TRUE != FALSE)
#define ComM_HasSizeOfPncSignalValuesOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define ComM_HasSizeOfPncToChannelRoutingStateOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define ComM_HasSizeOfPostInitializedOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define ComM_HasSizeOfResetRequiredOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define ComM_HasSizeOfUserByteMaskOfPCPartitionConfig()                                             (TRUE != FALSE)
#define ComM_HasSizeOfUserOfPCPartitionConfig()                                                     (TRUE != FALSE)
#define ComM_HasSizeOfUserPncByteMaskOfPCPartitionConfig()                                          (TRUE != FALSE)
#define ComM_HasSizeOfUserReqFullComOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define ComM_HasSizeOfUserReqPncFullComOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define ComM_HasUserByteMaskOfPCPartitionConfig()                                                   (TRUE != FALSE)
#define ComM_HasUserOfPCPartitionConfig()                                                           (TRUE != FALSE)
#define ComM_HasUserPncByteMaskOfPCPartitionConfig()                                                (TRUE != FALSE)
#define ComM_HasUserReqFullComOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define ComM_HasUserReqPncFullComOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCIncrementDataMacros  ComM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define ComM_IncActiveComMode(Index, partitionIndex)                                                ComM_GetActiveComMode(((Index)), (partitionIndex))++
#define ComM_IncActivePncComMode(Index, partitionIndex)                                             ComM_GetActivePncComMode(((Index)), (partitionIndex))++
#define ComM_IncBusComModeReq(Index, partitionIndex)                                                ComM_GetBusComModeReq(((Index)), (partitionIndex))++
#define ComM_IncBusPncComModeReq(Index, partitionIndex)                                             ComM_GetBusPncComModeReq(((Index)), (partitionIndex))++
#define ComM_IncBusSmState(Index, partitionIndex)                                                   ComM_GetBusSmState(((Index)), (partitionIndex))++
#define ComM_IncInhibition(partitionIndex)                                                          ComM_GetInhibition(partitionIndex)++
#define ComM_IncInitStatus(partitionIndex)                                                          ComM_GetInitStatus(partitionIndex)++
#define ComM_IncPncPSleepTimer(Index, partitionIndex)                                               ComM_GetPncPSleepTimer(((Index)), (partitionIndex))++
#define ComM_IncPncSignalValues(Index, partitionIndex)                                              ComM_GetPncSignalValues(((Index)), (partitionIndex))++
#define ComM_IncPncToChannelRoutingState(Index, partitionIndex)                                     ComM_GetPncToChannelRoutingState(((Index)), (partitionIndex))++
#define ComM_IncUserReqFullCom(Index, partitionIndex)                                               ComM_GetUserReqFullCom(((Index)), (partitionIndex))++
#define ComM_IncUserReqPncFullCom(Index, partitionIndex)                                            ComM_GetUserReqPncFullCom(((Index)), (partitionIndex))++
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCDecrementDataMacros  ComM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define ComM_DecActiveComMode(Index, partitionIndex)                                                ComM_GetActiveComMode(((Index)), (partitionIndex))--
#define ComM_DecActivePncComMode(Index, partitionIndex)                                             ComM_GetActivePncComMode(((Index)), (partitionIndex))--
#define ComM_DecBusComModeReq(Index, partitionIndex)                                                ComM_GetBusComModeReq(((Index)), (partitionIndex))--
#define ComM_DecBusPncComModeReq(Index, partitionIndex)                                             ComM_GetBusPncComModeReq(((Index)), (partitionIndex))--
#define ComM_DecBusSmState(Index, partitionIndex)                                                   ComM_GetBusSmState(((Index)), (partitionIndex))--
#define ComM_DecInhibition(partitionIndex)                                                          ComM_GetInhibition(partitionIndex)--
#define ComM_DecInitStatus(partitionIndex)                                                          ComM_GetInitStatus(partitionIndex)--
#define ComM_DecPncPSleepTimer(Index, partitionIndex)                                               ComM_GetPncPSleepTimer(((Index)), (partitionIndex))--
#define ComM_DecPncSignalValues(Index, partitionIndex)                                              ComM_GetPncSignalValues(((Index)), (partitionIndex))--
#define ComM_DecPncToChannelRoutingState(Index, partitionIndex)                                     ComM_GetPncToChannelRoutingState(((Index)), (partitionIndex))--
#define ComM_DecUserReqFullCom(Index, partitionIndex)                                               ComM_GetUserReqFullCom(((Index)), (partitionIndex))--
#define ComM_DecUserReqPncFullCom(Index, partitionIndex)                                            ComM_GetUserReqPncFullCom(((Index)), (partitionIndex))--
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCAddDataMacros  ComM Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define ComM_AddActiveComMode(Index, Value, partitionIndex)                                         ComM_SetActiveComMode(Index, (ComM_GetActiveComMode(((Index)), (partitionIndex)) + Value), partitionIndex)
#define ComM_AddActivePncComMode(Index, Value, partitionIndex)                                      ComM_SetActivePncComMode(Index, (ComM_GetActivePncComMode(((Index)), (partitionIndex)) + Value), partitionIndex)
#define ComM_AddBusComModeReq(Index, Value, partitionIndex)                                         ComM_SetBusComModeReq(Index, (ComM_GetBusComModeReq(((Index)), (partitionIndex)) + Value), partitionIndex)
#define ComM_AddBusPncComModeReq(Index, Value, partitionIndex)                                      ComM_SetBusPncComModeReq(Index, (ComM_GetBusPncComModeReq(((Index)), (partitionIndex)) + Value), partitionIndex)
#define ComM_AddBusSmState(Index, Value, partitionIndex)                                            ComM_SetBusSmState(Index, (ComM_GetBusSmState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define ComM_AddInhibition(Value, partitionIndex)                                                   ComM_SetInhibition((ComM_GetInhibition(partitionIndex) + Value), partitionIndex)
#define ComM_AddInitStatus(Value, partitionIndex)                                                   ComM_SetInitStatus((ComM_GetInitStatus(partitionIndex) + Value), partitionIndex)
#define ComM_AddPncPSleepTimer(Index, Value, partitionIndex)                                        ComM_SetPncPSleepTimer(Index, (ComM_GetPncPSleepTimer(((Index)), (partitionIndex)) + Value), partitionIndex)
#define ComM_AddPncSignalValues(Index, Value, partitionIndex)                                       ComM_SetPncSignalValues(Index, (ComM_GetPncSignalValues(((Index)), (partitionIndex)) + Value), partitionIndex)
#define ComM_AddPncToChannelRoutingState(Index, Value, partitionIndex)                              ComM_SetPncToChannelRoutingState(Index, (ComM_GetPncToChannelRoutingState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define ComM_AddUserReqFullCom(Index, Value, partitionIndex)                                        ComM_SetUserReqFullCom(Index, (ComM_GetUserReqFullCom(((Index)), (partitionIndex)) + Value), partitionIndex)
#define ComM_AddUserReqPncFullCom(Index, Value, partitionIndex)                                     ComM_SetUserReqPncFullCom(Index, (ComM_GetUserReqPncFullCom(((Index)), (partitionIndex)) + Value), partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCSubstractDataMacros  ComM Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define ComM_SubActiveComMode(Index, Value, partitionIndex)                                         ComM_SetActiveComMode(Index, (ComM_GetActiveComMode(((Index)), (partitionIndex)) - Value), partitionIndex)
#define ComM_SubActivePncComMode(Index, Value, partitionIndex)                                      ComM_SetActivePncComMode(Index, (ComM_GetActivePncComMode(((Index)), (partitionIndex)) - Value), partitionIndex)
#define ComM_SubBusComModeReq(Index, Value, partitionIndex)                                         ComM_SetBusComModeReq(Index, (ComM_GetBusComModeReq(((Index)), (partitionIndex)) - Value), partitionIndex)
#define ComM_SubBusPncComModeReq(Index, Value, partitionIndex)                                      ComM_SetBusPncComModeReq(Index, (ComM_GetBusPncComModeReq(((Index)), (partitionIndex)) - Value), partitionIndex)
#define ComM_SubBusSmState(Index, Value, partitionIndex)                                            ComM_SetBusSmState(Index, (ComM_GetBusSmState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define ComM_SubInhibition(Value, partitionIndex)                                                   ComM_SetInhibition((ComM_GetInhibition(partitionIndex) - Value), partitionIndex)
#define ComM_SubInitStatus(Value, partitionIndex)                                                   ComM_SetInitStatus((ComM_GetInitStatus(partitionIndex) - Value), partitionIndex)
#define ComM_SubPncPSleepTimer(Index, Value, partitionIndex)                                        ComM_SetPncPSleepTimer(Index, (ComM_GetPncPSleepTimer(((Index)), (partitionIndex)) - Value), partitionIndex)
#define ComM_SubPncSignalValues(Index, Value, partitionIndex)                                       ComM_SetPncSignalValues(Index, (ComM_GetPncSignalValues(((Index)), (partitionIndex)) - Value), partitionIndex)
#define ComM_SubPncToChannelRoutingState(Index, Value, partitionIndex)                              ComM_SetPncToChannelRoutingState(Index, (ComM_GetPncToChannelRoutingState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define ComM_SubUserReqFullCom(Index, Value, partitionIndex)                                        ComM_SetUserReqFullCom(Index, (ComM_GetUserReqFullCom(((Index)), (partitionIndex)) - Value), partitionIndex)
#define ComM_SubUserReqPncFullCom(Index, Value, partitionIndex)                                     ComM_SetUserReqPncFullCom(Index, (ComM_GetUserReqPncFullCom(((Index)), (partitionIndex)) - Value), partitionIndex)
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/* Postbuild */
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/* Macros for stored PNC signal data manipulation:*/

/* Evaluate if the bit for InternalPncId is set in the stored data for signal specified by InternalSignalId */
#define ComM_IsSignalStoredPncBitSet(InternalSignalId, InternalPncId, partitionIdx) ((ComM_GetPncSignalValues(ComM_GetPncSignalValuesStartIdxOfPncSignal(InternalSignalId) + ComM_GetSignalByteIndexOfPncPb(InternalPncId), partitionIdx) & ComM_GetSetMaskOfPnc(InternalPncId)) > 0u) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/* PRQA S 3451 EXTERNDECLARATIONS */ /* MD_ComM_3451_3449 */ 
/* PRQA S 3449 EXTERNALDECLARATIONS_3449 */ /* MD_ComM_3451_3449 */ 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  ComM_ChannelLeft
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelLeft
  \brief  Contains PreCompile configuration parameters of channels
  \details
  Element                   Description
  Enabled                   Decides if the channel is enabled in the variant
  NmType                    The Network Management type of the channel
  GetCurrentBusSMModeApi    Query the current communication mode from the corresponding BusSM
  RequestBusSMModeApi       Request the communication mode from the corresponding BusSM
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelType, COMM_CONST) ComM_ChannelLeft[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelRight
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelRight
  \brief  Contains PreCompile configuration parameters of channels
  \details
  Element                   Description
  Enabled                   Decides if the channel is enabled in the variant
  NmType                    The Network Management type of the channel
  GetCurrentBusSMModeApi    Query the current communication mode from the corresponding BusSM
  RequestBusSMModeApi       Request the communication mode from the corresponding BusSM
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelType, COMM_CONST) ComM_ChannelRight[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelPbLeft
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelPbLeft
  \brief  Contains PostBuild configuration parameters of channels
  \details
  Element                   Description
  PncPbIndEndIdx            the end index of the 0:n relation pointing to ComM_PncPbInd
  PncPbIndStartIdx          the start index of the 0:n relation pointing to ComM_PncPbInd
  UserReqFullComEndIdx      the end index of the 0:n relation pointing to ComM_UserReqFullCom
  UserReqFullComStartIdx    the start index of the 0:n relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelPbType, COMM_CONST) ComM_ChannelPbLeft[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelPbRight
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelPbRight
  \brief  Contains PostBuild configuration parameters of channels
  \details
  Element                   Description
  PncPbIndEndIdx            the end index of the 0:n relation pointing to ComM_PncPbInd
  PncPbIndStartIdx          the start index of the 0:n relation pointing to ComM_PncPbInd
  UserReqFullComEndIdx      the end index of the 0:n relation pointing to ComM_UserReqFullCom
  UserReqFullComStartIdx    the start index of the 0:n relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelPbType, COMM_CONST) ComM_ChannelPbRight[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_EiraTxSignalIndirection
**********************************************************************************************************************/
/** 
  \var    ComM_EiraTxSignalIndirection
  \brief  Indirection of internal signal id to the actual Eira Tx Symbolic Name Value
  \details
  Element              Description
  SymbolicNameValue    SymbolicNameValue of Tx Eira Signal
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_EiraTxSignalIndirectionType, COMM_CONST) ComM_EiraTxSignalIndirection[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    ComM_PartitionIdentifiers
  \brief  the partition context in Config_Left
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to ComM_PCPartitionConfig
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PartitionIdentifiersType, COMM_CONST) ComM_PartitionIdentifiers[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_Pnc
**********************************************************************************************************************/
/** 
  \var    ComM_Pnc
  \brief  Contains PreCompile configuration parameters of partial networks
  \details
  Element      Description
  ClearMask    Clear mask for the partial network related signals (EIRA, ERA)
  PncId        System ID of the partial network
  SetMask      Set mask for the partial network related signals (EIRA, ERA)
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncType, COMM_CONST) ComM_Pnc[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncChannelMappingLeft
**********************************************************************************************************************/
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncChannelMappingType, COMM_CONST) ComM_PncChannelMappingLeft[2];
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncChannelMappingRight
**********************************************************************************************************************/
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncChannelMappingType, COMM_CONST) ComM_PncChannelMappingRight[2];
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncPb
**********************************************************************************************************************/
/** 
  \var    ComM_PncPb
  \brief  Contains PostBuild configuration parameters of partial networks
  \details
  Element                      Description
  PncChannelMappingEndIdx      the end index of the 0:n relation pointing to ComM_PncChannelMapping
  PncChannelMappingStartIdx    the start index of the 0:n relation pointing to ComM_PncChannelMapping
  PncSignalIndEndIdx           the end index of the 0:n relation pointing to ComM_PncSignalInd
  PncSignalIndStartIdx         the start index of the 0:n relation pointing to ComM_PncSignalInd
  SignalByteIndex              Byte index in the partial network related signals (EIRA, ERA)
  UserReqPncFullComEndIdx      the end index of the 1:n relation pointing to ComM_UserReqPncFullCom
  UserReqPncFullComStartIdx    the start index of the 1:n relation pointing to ComM_UserReqPncFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncPbType, COMM_CONST) ComM_PncPb[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncPbInd
**********************************************************************************************************************/
/** 
  \var    ComM_PncPbInd
  \brief  the indexes of the 1:1 sorted relation pointing to ComM_PncPb
*/ 
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncPbIndType, COMM_CONST) ComM_PncPbInd[2];
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalLeft
**********************************************************************************************************************/
/** 
  \var    ComM_PncSignalLeft
  \brief  Information about partial network signals (EIRA, ERA)
  \details
  Element                    Description
  ChannelIdx                 the index of the 0:1 relation pointing to ComM_Channel
  PncSignalValuesEndIdx      the end index of the 0:n relation pointing to ComM_PncSignalValues
  PncSignalValuesStartIdx    the start index of the 0:n relation pointing to ComM_PncSignalValues
  Type                       Partial network signal type
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncSignalType, COMM_CONST) ComM_PncSignalLeft[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalRight
**********************************************************************************************************************/
/** 
  \var    ComM_PncSignalRight
  \brief  Information about partial network signals (EIRA, ERA)
  \details
  Element                    Description
  ChannelIdx                 the index of the 0:1 relation pointing to ComM_Channel
  PncSignalValuesEndIdx      the end index of the 0:n relation pointing to ComM_PncSignalValues
  PncSignalValuesStartIdx    the start index of the 0:n relation pointing to ComM_PncSignalValues
  Type                       Partial network signal type
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncSignalType, COMM_CONST) ComM_PncSignalRight[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalIndLeft
**********************************************************************************************************************/
/** 
  \var    ComM_PncSignalIndLeft
  \brief  the indexes of the 1:1 sorted relation pointing to ComM_PncSignal
*/ 
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncSignalIndType, COMM_CONST) ComM_PncSignalIndLeft[2];
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalIndRight
**********************************************************************************************************************/
/** 
  \var    ComM_PncSignalIndRight
  \brief  the indexes of the 1:1 sorted relation pointing to ComM_PncSignal
*/ 
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncSignalIndType, COMM_CONST) ComM_PncSignalIndRight[2];
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_User
**********************************************************************************************************************/
/** 
  \var    ComM_User
  \brief  Information about ComM users
  \details
  Element                    Description
  PncUser                    decides if a user is a partial network user or a direct channel user
  UserByteMaskEndIdx         the end index of the 0:n relation pointing to ComM_UserByteMask
  UserByteMaskStartIdx       the start index of the 0:n relation pointing to ComM_UserByteMask
  UserPncByteMaskEndIdx      the end index of the 0:n relation pointing to ComM_UserPncByteMask
  UserPncByteMaskLength      the number of relations pointing to ComM_UserPncByteMask
  UserPncByteMaskStartIdx    the start index of the 0:n relation pointing to ComM_UserPncByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserType, COMM_CONST) ComM_User[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserByteMaskLeft
**********************************************************************************************************************/
/** 
  \var    ComM_UserByteMaskLeft
  \brief  Each user has N entries in this array (N = # channels attached to this user, directly or through PNC). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqFullCom
  \details
  Element      Description
  Channel      ID of the channel which is requested by this entry.
  ClearMask    Clear-mask for clearing the bit which corresponds to this user
  SetMask      Set-mask for setting the bit which corresponds to this user
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserByteMaskType, COMM_CONST) ComM_UserByteMaskLeft[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserByteMaskRight
**********************************************************************************************************************/
/** 
  \var    ComM_UserByteMaskRight
  \brief  Each user has N entries in this array (N = # channels attached to this user, directly or through PNC). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqFullCom
  \details
  Element      Description
  Channel      ID of the channel which is requested by this entry.
  ClearMask    Clear-mask for clearing the bit which corresponds to this user
  SetMask      Set-mask for setting the bit which corresponds to this user
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserByteMaskType, COMM_CONST) ComM_UserByteMaskRight[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserPncByteMask
**********************************************************************************************************************/
/** 
  \var    ComM_UserPncByteMask
  \brief  Each partial network user has N entries in this array (N = # pncs attached to this user). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqPncFullCom
  \details
  Element                 Description
  PncID                   System Id of the partial network which is requested by this entry
  PncIdx                  the index of the 1:1 relation pointing to ComM_Pnc
  UserReqPncFullComIdx    the index of the 1:1 relation pointing to ComM_UserReqPncFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserPncByteMaskType, COMM_CONST) ComM_UserPncByteMask[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ActiveComMode
**********************************************************************************************************************/
/** 
  \var    ComM_ActiveComMode
  \brief  Current state of a channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ActiveComModeUType, COMM_VAR_NO_INIT) ComM_ActiveComMode;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ActivePncComMode
**********************************************************************************************************************/
/** 
  \var    ComM_ActivePncComMode
  \brief  stores the current partial network state
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ActivePncComModeUType, COMM_VAR_NO_INIT) ComM_ActivePncComMode;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusComModeReq
**********************************************************************************************************************/
/** 
  \var    ComM_BusComModeReq
  \brief  State requested externally (bus)
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_BusComModeReqUType, COMM_VAR_NO_INIT) ComM_BusComModeReq;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusPncComModeReq
**********************************************************************************************************************/
/** 
  \var    ComM_BusPncComModeReq
  \brief  Stores the partial network state requested by external requests
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_BusPncComModeReqUType, COMM_VAR_NO_INIT) ComM_BusPncComModeReq;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusSmState
**********************************************************************************************************************/
/** 
  \var    ComM_BusSmState
  \brief  Communication state of a channel provided by BusSM
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_BusSmStateUType, COMM_VAR_NO_INIT) ComM_BusSmState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ComAllowed
**********************************************************************************************************************/
/** 
  \var    ComM_ComAllowed
  \brief  Communication allowed status of a channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ComAllowedUType, COMM_VAR_NO_INIT) ComM_ComAllowed;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_DcmRequestActive
**********************************************************************************************************************/
/** 
  \var    ComM_DcmRequestActive
  \brief  Status of Dcm active diagnostic request, TRUE if requested, FALSE otherwise
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_DcmRequestActiveUType, COMM_VAR_NO_INIT) ComM_DcmRequestActive;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_EcuMWakeUpIndicated
**********************************************************************************************************************/
/** 
  \var    ComM_EcuMWakeUpIndicated
  \brief  Passive Wakeup indicated by EcuM (ComM_EcuM_WakeUpIndication()). TRUE if indicated, FALSE otherwise.
*/ 
#define COMM_START_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(ComM_EcuMWakeUpIndicatedType, COMM_VAR_NO_INIT) ComM_EcuMWakeUpIndicated[1];
#define COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_Inhibition
**********************************************************************************************************************/
/** 
  \var    ComM_Inhibition
  \brief  Status of mode limitation (inhibition)
*/ 
#define COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_InhibitionType, COMM_NVM_DATA_NO_INIT) ComM_Inhibition;
#define COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_InitStatus
**********************************************************************************************************************/
/** 
  \var    ComM_InitStatus
  \brief  Initialization state of ComM
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_InitStatusType, COMM_VAR_NO_INIT) ComM_InitStatus;
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_NmStartUpIndicated
**********************************************************************************************************************/
/** 
  \var    ComM_NmStartUpIndicated
  \brief  Passive Wakeup indicated by Nm (ComM_Nm_NetworkStartIndication() or ComM_Nm_RestartIndication()). TRUE if indicated, FALSE otherwise.
*/ 
#define COMM_START_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(ComM_NmStartUpIndicatedType, COMM_VAR_NO_INIT) ComM_NmStartUpIndicated[1];
#define COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncPSleepTimer
**********************************************************************************************************************/
/** 
  \var    ComM_PncPSleepTimer
  \brief  partial network prepare sleep timer
*/ 
#define COMM_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_PncPSleepTimerUType, COMM_VAR_NO_INIT) ComM_PncPSleepTimer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalValues
**********************************************************************************************************************/
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_PncSignalValuesUType, COMM_VAR_NO_INIT) ComM_PncSignalValues;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncToChannelRoutingState
**********************************************************************************************************************/
/** 
  \var    ComM_PncToChannelRoutingState
  \brief  Bit flags describing the current PNC Routing state per channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_PncToChannelRoutingStateUType, COMM_VAR_NO_INIT) ComM_PncToChannelRoutingState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PostInitialized
**********************************************************************************************************************/
/** 
  \var    ComM_PostInitialized
  \brief  Post-Initialized state
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_PostInitializedType, COMM_VAR_NO_INIT) ComM_PostInitialized[1];
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ResetRequired
**********************************************************************************************************************/
/** 
  \var    ComM_ResetRequired
  \brief  TRUE if a reset has to be performed
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ResetRequiredUType, COMM_VAR_NO_INIT) ComM_ResetRequired;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserReqFullCom
**********************************************************************************************************************/
/** 
  \var    ComM_UserReqFullCom
  \brief  RAM array used to store user requests for channels as bitmasks. Each channel 'owns' 1..n bytes in this array, depending on the number of users assigned to it.
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_UserReqFullComType, COMM_VAR_NO_INIT) ComM_UserReqFullCom[1];
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserReqPncFullCom
**********************************************************************************************************************/
/** 
  \var    ComM_UserReqPncFullCom
  \brief  RAM array used to store user requests for PNCs as bitmasks. Each PNC 'owns' 1..n bytes in this array, depending on the number of users assigned to it.
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_UserReqPncFullComType, COMM_VAR_NO_INIT) ComM_UserReqPncFullCom[2];
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PCConfig
**********************************************************************************************************************/
/** 
  \var    ComM_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to ComM_PCPartitionConfig
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PCConfigsType, COMM_CONST) ComM_PCConfig;
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PCPartitionConfigLeft
**********************************************************************************************************************/
/** 
  \var    ComM_PCPartitionConfigLeft
  \details
  Element              Description
  Channel              the pointer to ComM_Channel
  ChannelPb            the pointer to ComM_ChannelPb
  PncChannelMapping    the pointer to ComM_PncChannelMapping
  PncSignal            the pointer to ComM_PncSignal
  PncSignalInd         the pointer to ComM_PncSignalInd
  UserByteMask         the pointer to ComM_UserByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PCPartitionConfigType, COMM_CONST) ComM_PCPartitionConfigLeft[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PCPartitionConfigRight
**********************************************************************************************************************/
/** 
  \var    ComM_PCPartitionConfigRight
  \details
  Element              Description
  Channel              the pointer to ComM_Channel
  ChannelPb            the pointer to ComM_ChannelPb
  PncChannelMapping    the pointer to ComM_PncChannelMapping
  PncSignal            the pointer to ComM_PncSignal
  PncSignalInd         the pointer to ComM_PncSignalInd
  UserByteMask         the pointer to ComM_UserByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PCPartitionConfigType, COMM_CONST) ComM_PCPartitionConfigRight[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/* PRQA L:EXTERNALDECLARATIONS_3449 */
/* PRQA L:EXTERNDECLARATIONS */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  INTERNAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "ComM_MemMap.h"

# if (COMM_EXISTS_EIRA_RX_TYPEOFPNCSIGNAL == STD_ON)
/*********************************************************************************************************************
  FUNCTION: ComM_PncProcessRxSignalEira
*********************************************************************************************************************/
/*! \brief       Function to process received EIRA_RX PNC states. It sets the bus-side requested Pnc state accordingly.
 *  \param[in]   InternalSignalId       the internal ID of the signal, which is an index in the ComM_PncSignal table
 *  \param[in]   SignalDataRx           signal data received from Com
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_PncProcessRxSignalEira(ComM_SizeOfPncSignalType InternalSignalId, const uint8 *SignalDataRx);
# endif

# if (COMM_PNC_ACTIVE_COORD == STD_ON)
#  if ( (COMM_PNC_EXISTS_GATEWAY_TYPE_ACTIVE == STD_ON) || (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON) )
/*********************************************************************************************************************
  FUNCTION: ComM_PncProcessRxSignalEra
*********************************************************************************************************************/
/*! \brief       Function to process received ERA PNC states and to request or release system users.
 *  \param[in]   InternalSignalId       the internal ID of the signal, which is an index in the ComM_PncSignal table
 *  \param[in]   SignalDataRx           signal data received from Com
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_PncProcessRxSignalEra(ComM_SizeOfPncSignalType InternalSignalId, const uint8 *SignalDataRx);
#  endif
# endif

#define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "ComM_MemMap.h"


/**********************************************************************************************************************
  CONFIG POINTER
**********************************************************************************************************************/
#if (COMM_USE_INIT_POINTER == STD_ON)
# define COMM_START_SEC_VAR_CLEARED_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
# include "ComM_MemMap.h"

extern P2CONST(ComM_ConfigType, AUTOMATIC, COMM_INIT_DATA) ComM_ConfigPtr;

# define COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
# include "ComM_MemMap.h"
#endif

#endif /* COMM_PRIVATE_CFG_H */

