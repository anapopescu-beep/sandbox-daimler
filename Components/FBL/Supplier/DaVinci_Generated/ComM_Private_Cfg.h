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
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ComM_Private_Cfg.h
 *   Generation Time: 2023-07-05 16:23:57
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
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
#define ComM_GetBusComModeReqOfPCPartitionConfig(partitionIndex)                                    ComM_BusComModeReq.raw  /**< the pointer to ComM_BusComModeReq */
#define ComM_GetBusSmStateOfPCPartitionConfig(partitionIndex)                                       ComM_BusSmState.raw  /**< the pointer to ComM_BusSmState */
#define ComM_GetComAllowedOfPCPartitionConfig(partitionIndex)                                       ComM_ComAllowed.raw  /**< the pointer to ComM_ComAllowed */
#define ComM_GetDcmRequestActiveOfPCPartitionConfig(partitionIndex)                                 ComM_DcmRequestActive.raw  /**< the pointer to ComM_DcmRequestActive */
#define ComM_GetInhibitionOfPCPartitionConfig(partitionIndex)                                       (&(ComM_Inhibition))  /**< the pointer to ComM_Inhibition */
#define ComM_GetInitStatusOfPCPartitionConfig(partitionIndex)                                       (&(ComM_InitStatus))  /**< the pointer to ComM_InitStatus */
#define ComM_GetPostInitializedOfPCPartitionConfig(partitionIndex)                                  ComM_PostInitialized  /**< the pointer to ComM_PostInitialized */
#define ComM_GetSizeOfChannelOfPCPartitionConfig()                                                  2u  /**< the number of accomplishable value elements in ComM_Channel */
#define ComM_GetSizeOfChannelPbOfPCPartitionConfig()                                                2u  /**< the number of accomplishable value elements in ComM_ChannelPb */
#define ComM_GetSizeOfPostInitializedOfPCPartitionConfig(partitionIndex)                            1u  /**< the number of accomplishable value elements in ComM_PostInitialized */
#define ComM_GetSizeOfUserByteMaskOfPCPartitionConfig()                                             1u  /**< the number of accomplishable value elements in ComM_UserByteMask */
#define ComM_GetSizeOfUserOfPCPartitionConfig()                                                     1u  /**< the number of accomplishable value elements in ComM_User */
#define ComM_GetSizeOfUserReqFullComOfPCPartitionConfig(partitionIndex)                             1u  /**< the number of accomplishable value elements in ComM_UserReqFullCom */
#define ComM_GetUserOfPCPartitionConfig()                                                           ComM_User  /**< the pointer to ComM_User */
#define ComM_GetUserReqFullComOfPCPartitionConfig(partitionIndex)                                   ComM_UserReqFullCom  /**< the pointer to ComM_UserReqFullCom */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCGetDuplicatedRootDataMacros  ComM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define ComM_GetSizeOfActiveComModeOfPCPartitionConfig(partitionIndex)                              ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_ActiveComMode */
#define ComM_GetSizeOfBusComModeReqOfPCPartitionConfig(partitionIndex)                              ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_BusComModeReq */
#define ComM_GetSizeOfBusSmStateOfPCPartitionConfig(partitionIndex)                                 ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_BusSmState */
#define ComM_GetSizeOfComAllowedOfPCPartitionConfig(partitionIndex)                                 ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_ComAllowed */
#define ComM_GetSizeOfDcmRequestActiveOfPCPartitionConfig(partitionIndex)                           ComM_GetSizeOfChannelOfPCPartitionConfig()  /**< the number of accomplishable value elements in ComM_DcmRequestActive */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCGetDataMacros  ComM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define ComM_GetActiveComMode(Index, partitionIndex)                                                (ComM_GetActiveComModeOfPCPartitionConfig(partitionIndex)[(Index)])
#define ComM_GetBusComModeReq(Index, partitionIndex)                                                (ComM_GetBusComModeReqOfPCPartitionConfig(partitionIndex)[(Index)])
#define ComM_GetBusSmState(Index, partitionIndex)                                                   (ComM_GetBusSmStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define ComM_IsEnabledOfChannel(Index)                                                              ((ComM_GetChannelOfPCPartitionConfig()[(Index)].EnabledOfChannel) != FALSE)
#define ComM_GetGetCurrentBusSMModeApiOfChannel(Index)                                              (ComM_GetChannelOfPCPartitionConfig()[(Index)].GetCurrentBusSMModeApiOfChannel)
#define ComM_GetNmTypeOfChannel(Index)                                                              (ComM_GetChannelOfPCPartitionConfig()[(Index)].NmTypeOfChannel)
#define ComM_GetRequestBusSMModeApiOfChannel(Index)                                                 (ComM_GetChannelOfPCPartitionConfig()[(Index)].RequestBusSMModeApiOfChannel)
#define ComM_GetUserReqFullComEndIdxOfChannelPb(Index)                                              (ComM_GetChannelPbOfPCPartitionConfig()[(Index)].UserReqFullComEndIdxOfChannelPb)
#define ComM_GetUserReqFullComStartIdxOfChannelPb(Index)                                            (ComM_GetChannelPbOfPCPartitionConfig()[(Index)].UserReqFullComStartIdxOfChannelPb)
#define ComM_IsComAllowed(Index, partitionIndex)                                                    ((ComM_GetComAllowedOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE)
#define ComM_IsDcmRequestActive(Index, partitionIndex)                                              ((ComM_GetDcmRequestActiveOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE)
#define ComM_GetInhibition(partitionIndex)                                                          ((*(ComM_GetInhibitionOfPCPartitionConfig(partitionIndex))))
#define ComM_GetInitStatus(partitionIndex)                                                          ((*(ComM_GetInitStatusOfPCPartitionConfig(partitionIndex))))
#define ComM_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                   (ComM_GetPartitionIdentifiersOfPCConfig()[(Index)].PCPartitionConfigIdxOfPartitionIdentifiers)
#define ComM_GetPartitionSNVOfPartitionIdentifiers(Index)                                           (ComM_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define ComM_IsPostInitialized(Index, partitionIndex)                                               ((ComM_GetPostInitializedOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE)
#define ComM_IsPncUserOfUser(Index)                                                                 ((ComM_GetUserOfPCPartitionConfig()[(Index)].PncUserOfUser) != FALSE)
#define ComM_GetChannelOfUserByteMask(Index)                                                        ((NetworkHandleType)ComM_GetUserByteMaskOfPCPartitionConfig()[(Index)].ChannelOfUserByteMask)
#define ComM_GetUserReqFullCom(Index, partitionIndex)                                               (ComM_GetUserReqFullComOfPCPartitionConfig(partitionIndex)[(Index)])
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
#define ComM_GetPartitionConfigIdxOfChannel(Index)                                                  0u  /**< the index of the 1:1 relation pointing to ComM_PCPartitionConfig */
#define ComM_GetWakeupStateOfChannel(Index)                                                         COMM_FULL_COM_NETWORK_REQUESTED  /**< Target channel state after a Passive Wake-up */
#define ComM_IsUserReqFullComUsedOfChannelPb(Index)                                                 (((boolean)(ComM_GetUserReqFullComStartIdxOfChannelPb(Index) != COMM_NO_USERREQFULLCOMSTARTIDXOFCHANNELPB)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to ComM_UserReqFullCom */
#define ComM_GetSizeOfActiveComMode(partitionIndex)                                                 ComM_GetSizeOfActiveComModeOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfBusComModeReq(partitionIndex)                                                 ComM_GetSizeOfBusComModeReqOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfBusSmState(partitionIndex)                                                    ComM_GetSizeOfBusSmStateOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfChannel()                                                                     ComM_GetSizeOfChannelOfPCPartitionConfig()
#define ComM_GetSizeOfChannelPb()                                                                   ComM_GetSizeOfChannelPbOfPCPartitionConfig()
#define ComM_GetSizeOfComAllowed(partitionIndex)                                                    ComM_GetSizeOfComAllowedOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfDcmRequestActive(partitionIndex)                                              ComM_GetSizeOfDcmRequestActiveOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfPartitionIdentifiers()                                                        ComM_GetSizeOfPartitionIdentifiersOfPCConfig()
#define ComM_GetSizeOfPostInitialized(partitionIndex)                                               ComM_GetSizeOfPostInitializedOfPCPartitionConfig(partitionIndex)
#define ComM_GetSizeOfUser()                                                                        ComM_GetSizeOfUserOfPCPartitionConfig()
#define ComM_GetSizeOfUserByteMask()                                                                ComM_GetSizeOfUserByteMaskOfPCPartitionConfig()
#define ComM_GetSizeOfUserReqFullCom(partitionIndex)                                                ComM_GetSizeOfUserReqFullComOfPCPartitionConfig(partitionIndex)
#define ComM_GetUserByteMaskEndIdxOfUser(Index)                                                     1u  /**< the end index of the 0:n relation pointing to ComM_UserByteMask */
#define ComM_GetUserByteMaskStartIdxOfUser(Index)                                                   0u  /**< the start index of the 0:n relation pointing to ComM_UserByteMask */
#define ComM_IsUserByteMaskUsedOfUser(Index)                                                        (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to ComM_UserByteMask */
#define ComM_GetClearMaskOfUserByteMask(Index)                                                      0xFEu  /**< Clear-mask for clearing the bit which corresponds to this user */
#define ComM_GetSetMaskOfUserByteMask(Index)                                                        0x01u  /**< Set-mask for setting the bit which corresponds to this user */
#define ComM_GetUserReqFullComIdxOfUserByteMask(Index)                                              0u  /**< the index of the 1:1 relation pointing to ComM_UserReqFullCom */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCSetDataMacros  ComM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define ComM_SetActiveComMode(Index, Value, partitionIndex)                                         ComM_GetActiveComModeOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetBusComModeReq(Index, Value, partitionIndex)                                         ComM_GetBusComModeReqOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetBusSmState(Index, Value, partitionIndex)                                            ComM_GetBusSmStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetComAllowed(Index, Value, partitionIndex)                                            ComM_GetComAllowedOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetDcmRequestActive(Index, Value, partitionIndex)                                      ComM_GetDcmRequestActiveOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetInhibition(Value, partitionIndex)                                                   (*(ComM_GetInhibitionOfPCPartitionConfig(partitionIndex))) = (Value)
#define ComM_SetInitStatus(Value, partitionIndex)                                                   (*(ComM_GetInitStatusOfPCPartitionConfig(partitionIndex))) = (Value)
#define ComM_SetPostInitialized(Index, Value, partitionIndex)                                       ComM_GetPostInitializedOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define ComM_SetUserReqFullCom(Index, Value, partitionIndex)                                        ComM_GetUserReqFullComOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCHasMacros  ComM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define ComM_HasActiveComMode(partitionIndex)                                                       (TRUE != FALSE)
#define ComM_HasBusComModeReq(partitionIndex)                                                       (TRUE != FALSE)
#define ComM_HasBusSmState(partitionIndex)                                                          (TRUE != FALSE)
#define ComM_HasChannel()                                                                           (ComM_GetChannelOfPCPartitionConfig() != NULL_PTR)
#define ComM_HasBusTypeOfChannel()                                                                  (TRUE != FALSE)
#define ComM_HasEnabledOfChannel()                                                                  (TRUE != FALSE)
#define ComM_HasGetCurrentBusSMModeApiOfChannel()                                                   (TRUE != FALSE)
#define ComM_HasGwTypeOfChannel()                                                                   (TRUE != FALSE)
#define ComM_HasInhibitionInitValueOfChannel()                                                      (TRUE != FALSE)
#define ComM_HasNmTypeOfChannel()                                                                   (TRUE != FALSE)
#define ComM_HasPartitionConfigIdxOfChannel()                                                       (TRUE != FALSE)
#define ComM_HasRequestBusSMModeApiOfChannel()                                                      (TRUE != FALSE)
#define ComM_HasWakeupStateOfChannel()                                                              (TRUE != FALSE)
#define ComM_HasChannelPb()                                                                         (ComM_GetChannelPbOfPCPartitionConfig() != NULL_PTR)
#define ComM_HasUserReqFullComEndIdxOfChannelPb()                                                   (TRUE != FALSE)
#define ComM_HasUserReqFullComStartIdxOfChannelPb()                                                 (TRUE != FALSE)
#define ComM_HasUserReqFullComUsedOfChannelPb()                                                     (TRUE != FALSE)
#define ComM_HasComAllowed(partitionIndex)                                                          (TRUE != FALSE)
#define ComM_HasDcmRequestActive(partitionIndex)                                                    (TRUE != FALSE)
#define ComM_HasInhibition(partitionIndex)                                                          (TRUE != FALSE)
#define ComM_HasInitStatus(partitionIndex)                                                          (TRUE != FALSE)
#define ComM_HasPartitionIdentifiers()                                                              (TRUE != FALSE)
#define ComM_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                        (TRUE != FALSE)
#define ComM_HasPartitionSNVOfPartitionIdentifiers()                                                (TRUE != FALSE)
#define ComM_HasPostInitialized(partitionIndex)                                                     (TRUE != FALSE)
#define ComM_HasSizeOfActiveComMode(partitionIndex)                                                 (TRUE != FALSE)
#define ComM_HasSizeOfBusComModeReq(partitionIndex)                                                 (TRUE != FALSE)
#define ComM_HasSizeOfBusSmState(partitionIndex)                                                    (TRUE != FALSE)
#define ComM_HasSizeOfChannel()                                                                     (TRUE != FALSE)
#define ComM_HasSizeOfChannelPb()                                                                   (TRUE != FALSE)
#define ComM_HasSizeOfComAllowed(partitionIndex)                                                    (TRUE != FALSE)
#define ComM_HasSizeOfDcmRequestActive(partitionIndex)                                              (TRUE != FALSE)
#define ComM_HasSizeOfPartitionIdentifiers()                                                        (TRUE != FALSE)
#define ComM_HasSizeOfPostInitialized(partitionIndex)                                               (TRUE != FALSE)
#define ComM_HasSizeOfUser()                                                                        (TRUE != FALSE)
#define ComM_HasSizeOfUserByteMask()                                                                (TRUE != FALSE)
#define ComM_HasSizeOfUserReqFullCom(partitionIndex)                                                (TRUE != FALSE)
#define ComM_HasUser()                                                                              (TRUE != FALSE)
#define ComM_HasPncUserOfUser()                                                                     (TRUE != FALSE)
#define ComM_HasUserByteMaskEndIdxOfUser()                                                          (TRUE != FALSE)
#define ComM_HasUserByteMaskStartIdxOfUser()                                                        (TRUE != FALSE)
#define ComM_HasUserByteMaskUsedOfUser()                                                            (TRUE != FALSE)
#define ComM_HasUserByteMask()                                                                      (ComM_GetUserByteMaskOfPCPartitionConfig() != NULL_PTR)
#define ComM_HasChannelOfUserByteMask()                                                             (TRUE != FALSE)
#define ComM_HasClearMaskOfUserByteMask()                                                           (TRUE != FALSE)
#define ComM_HasSetMaskOfUserByteMask()                                                             (TRUE != FALSE)
#define ComM_HasUserReqFullComIdxOfUserByteMask()                                                   (TRUE != FALSE)
#define ComM_HasUserReqFullCom(partitionIndex)                                                      (TRUE != FALSE)
#define ComM_HasPCConfig()                                                                          (TRUE != FALSE)
#define ComM_HasPCPartitionConfigOfPCConfig()                                                       (TRUE != FALSE)
#define ComM_HasPartitionIdentifiersOfPCConfig()                                                    (TRUE != FALSE)
#define ComM_HasSizeOfPartitionIdentifiersOfPCConfig()                                              (TRUE != FALSE)
#define ComM_HasPCPartitionConfig()                                                                 (ComM_GetPCPartitionConfigOfPCConfig() != NULL_PTR)
#define ComM_HasActiveComModeOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define ComM_HasBusComModeReqOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define ComM_HasBusSmStateOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define ComM_HasChannelOfPCPartitionConfig()                                                        (TRUE != FALSE)
#define ComM_HasChannelPbOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define ComM_HasComAllowedOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define ComM_HasDcmRequestActiveOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define ComM_HasInhibitionOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define ComM_HasInitStatusOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define ComM_HasPostInitializedOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define ComM_HasSizeOfActiveComModeOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define ComM_HasSizeOfBusComModeReqOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define ComM_HasSizeOfBusSmStateOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define ComM_HasSizeOfChannelOfPCPartitionConfig()                                                  (TRUE != FALSE)
#define ComM_HasSizeOfChannelPbOfPCPartitionConfig()                                                (TRUE != FALSE)
#define ComM_HasSizeOfComAllowedOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define ComM_HasSizeOfDcmRequestActiveOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define ComM_HasSizeOfPostInitializedOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define ComM_HasSizeOfUserByteMaskOfPCPartitionConfig()                                             (TRUE != FALSE)
#define ComM_HasSizeOfUserOfPCPartitionConfig()                                                     (TRUE != FALSE)
#define ComM_HasSizeOfUserReqFullComOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define ComM_HasUserByteMaskOfPCPartitionConfig()                                                   (TRUE != FALSE)
#define ComM_HasUserOfPCPartitionConfig()                                                           (TRUE != FALSE)
#define ComM_HasUserReqFullComOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCIncrementDataMacros  ComM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define ComM_IncActiveComMode(Index, partitionIndex)                                                ComM_GetActiveComMode(((Index)), (partitionIndex))++
#define ComM_IncBusComModeReq(Index, partitionIndex)                                                ComM_GetBusComModeReq(((Index)), (partitionIndex))++
#define ComM_IncBusSmState(Index, partitionIndex)                                                   ComM_GetBusSmState(((Index)), (partitionIndex))++
#define ComM_IncInhibition(partitionIndex)                                                          ComM_GetInhibition(partitionIndex)++
#define ComM_IncInitStatus(partitionIndex)                                                          ComM_GetInitStatus(partitionIndex)++
#define ComM_IncUserReqFullCom(Index, partitionIndex)                                               ComM_GetUserReqFullCom(((Index)), (partitionIndex))++
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCDecrementDataMacros  ComM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define ComM_DecActiveComMode(Index, partitionIndex)                                                ComM_GetActiveComMode(((Index)), (partitionIndex))--
#define ComM_DecBusComModeReq(Index, partitionIndex)                                                ComM_GetBusComModeReq(((Index)), (partitionIndex))--
#define ComM_DecBusSmState(Index, partitionIndex)                                                   ComM_GetBusSmState(((Index)), (partitionIndex))--
#define ComM_DecInhibition(partitionIndex)                                                          ComM_GetInhibition(partitionIndex)--
#define ComM_DecInitStatus(partitionIndex)                                                          ComM_GetInitStatus(partitionIndex)--
#define ComM_DecUserReqFullCom(Index, partitionIndex)                                               ComM_GetUserReqFullCom(((Index)), (partitionIndex))--
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCAddDataMacros  ComM Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define ComM_AddActiveComMode(Index, Value, partitionIndex)                                         ComM_SetActiveComMode(Index, (ComM_GetActiveComMode(((Index)), (partitionIndex)) + Value), partitionIndex)
#define ComM_AddBusComModeReq(Index, Value, partitionIndex)                                         ComM_SetBusComModeReq(Index, (ComM_GetBusComModeReq(((Index)), (partitionIndex)) + Value), partitionIndex)
#define ComM_AddBusSmState(Index, Value, partitionIndex)                                            ComM_SetBusSmState(Index, (ComM_GetBusSmState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define ComM_AddInhibition(Value, partitionIndex)                                                   ComM_SetInhibition((ComM_GetInhibition(partitionIndex) + Value), partitionIndex)
#define ComM_AddInitStatus(Value, partitionIndex)                                                   ComM_SetInitStatus((ComM_GetInitStatus(partitionIndex) + Value), partitionIndex)
#define ComM_AddUserReqFullCom(Index, Value, partitionIndex)                                        ComM_SetUserReqFullCom(Index, (ComM_GetUserReqFullCom(((Index)), (partitionIndex)) + Value), partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCSubstractDataMacros  ComM Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define ComM_SubActiveComMode(Index, Value, partitionIndex)                                         ComM_SetActiveComMode(Index, (ComM_GetActiveComMode(((Index)), (partitionIndex)) - Value), partitionIndex)
#define ComM_SubBusComModeReq(Index, Value, partitionIndex)                                         ComM_SetBusComModeReq(Index, (ComM_GetBusComModeReq(((Index)), (partitionIndex)) - Value), partitionIndex)
#define ComM_SubBusSmState(Index, Value, partitionIndex)                                            ComM_SetBusSmState(Index, (ComM_GetBusSmState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define ComM_SubInhibition(Value, partitionIndex)                                                   ComM_SetInhibition((ComM_GetInhibition(partitionIndex) - Value), partitionIndex)
#define ComM_SubInitStatus(Value, partitionIndex)                                                   ComM_SetInitStatus((ComM_GetInitStatus(partitionIndex) - Value), partitionIndex)
#define ComM_SubUserReqFullCom(Index, Value, partitionIndex)                                        ComM_SetUserReqFullCom(Index, (ComM_GetUserReqFullCom(((Index)), (partitionIndex)) - Value), partitionIndex)
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
  ComM_ChannelRBTM_FL
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelRBTM_FL
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
extern CONST(ComM_ChannelType, COMM_CONST) ComM_ChannelRBTM_FL[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelRBTM_FR
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelRBTM_FR
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
extern CONST(ComM_ChannelType, COMM_CONST) ComM_ChannelRBTM_FR[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelPbRBTM_FL
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelPbRBTM_FL
  \brief  Contains PostBuild configuration parameters of channels
  \details
  Element                   Description
  UserReqFullComEndIdx      the end index of the 0:n relation pointing to ComM_UserReqFullCom
  UserReqFullComStartIdx    the start index of the 0:n relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelPbType, COMM_CONST) ComM_ChannelPbRBTM_FL[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelPbRBTM_FR
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelPbRBTM_FR
  \brief  Contains PostBuild configuration parameters of channels
  \details
  Element                   Description
  UserReqFullComEndIdx      the end index of the 0:n relation pointing to ComM_UserReqFullCom
  UserReqFullComStartIdx    the start index of the 0:n relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelPbType, COMM_CONST) ComM_ChannelPbRBTM_FR[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    ComM_PartitionIdentifiers
  \brief  the partition context in Config_RBTM_FL
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
  ComM_User
**********************************************************************************************************************/
/** 
  \var    ComM_User
  \brief  Information about ComM users
  \details
  Element    Description
  PncUser    decides if a user is a partial network user or a direct channel user
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserType, COMM_CONST) ComM_User[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserByteMaskRBTM_FL
**********************************************************************************************************************/
/** 
  \var    ComM_UserByteMaskRBTM_FL
  \brief  Each user has N entries in this array (N = # channels attached to this user, directly or through PNC). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqFullCom
  \details
  Element    Description
  Channel    ID of the channel which is requested by this entry.
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserByteMaskType, COMM_CONST) ComM_UserByteMaskRBTM_FL[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserByteMaskRBTM_FR
**********************************************************************************************************************/
/** 
  \var    ComM_UserByteMaskRBTM_FR
  \brief  Each user has N entries in this array (N = # channels attached to this user, directly or through PNC). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqFullCom
  \details
  Element    Description
  Channel    ID of the channel which is requested by this entry.
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserByteMaskType, COMM_CONST) ComM_UserByteMaskRBTM_FR[1];
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
  ComM_PCPartitionConfigRBTM_FL
**********************************************************************************************************************/
/** 
  \var    ComM_PCPartitionConfigRBTM_FL
  \details
  Element         Description
  Channel         the pointer to ComM_Channel
  ChannelPb       the pointer to ComM_ChannelPb
  UserByteMask    the pointer to ComM_UserByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PCPartitionConfigType, COMM_CONST) ComM_PCPartitionConfigRBTM_FL[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PCPartitionConfigRBTM_FR
**********************************************************************************************************************/
/** 
  \var    ComM_PCPartitionConfigRBTM_FR
  \details
  Element         Description
  Channel         the pointer to ComM_Channel
  ChannelPb       the pointer to ComM_ChannelPb
  UserByteMask    the pointer to ComM_UserByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PCPartitionConfigType, COMM_CONST) ComM_PCPartitionConfigRBTM_FR[1];
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

