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
 *            Module: CanTSyn
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTSyn_Cfg.h
 *   Generation Time: 2023-07-10 14:36:06
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (CANTSYN_CFG_H)
# define CANTSYN_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "CanTSyn_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* General defines */
#ifndef CANTSYN_USE_DUMMY_STATEMENT
#define CANTSYN_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANTSYN_DUMMY_STATEMENT
#define CANTSYN_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANTSYN_DUMMY_STATEMENT_CONST
#define CANTSYN_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANTSYN_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANTSYN_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CANTSYN_ATOMIC_VARIABLE_ACCESS
#define CANTSYN_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CANTSYN_PROCESSOR_TC322L
#define CANTSYN_PROCESSOR_TC322L
#endif
#ifndef CANTSYN_COMP_TASKING
#define CANTSYN_COMP_TASKING
#endif
#ifndef CANTSYN_GEN_GENERATOR_MSR
#define CANTSYN_GEN_GENERATOR_MSR
#endif
#ifndef CANTSYN_CPUTYPE_BITORDER_LSB2MSB
#define CANTSYN_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CANTSYN_CONFIGURATION_VARIANT_PRECOMPILE
#define CANTSYN_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANTSYN_CONFIGURATION_VARIANT_LINKTIME
#define CANTSYN_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANTSYN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANTSYN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANTSYN_CONFIGURATION_VARIANT
#define CANTSYN_CONFIGURATION_VARIANT CANTSYN_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANTSYN_POSTBUILD_VARIANT_SUPPORT
#define CANTSYN_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Version identification */
# define CANTSYN_CFG_MAJOR_VERSION                         (6u)
# define CANTSYN_CFG_MINOR_VERSION                         (1u)

# define CANTSYN_DEV_ERROR_DETECT                          (STD_ON)
# define CANTSYN_DEV_ERROR_REPORT                          (STD_OFF)
# define CANTSYN_VERSION_INFO_API                          (STD_OFF)
# define CANTSYN_MAIN_FUNCTION_CYCLE                       (5u /*  ms  */ )

# define CANTSYN_CRC_USED                                  (STD_ON)
# define CANTSYN_AR_4_3_X
# define CANTSYN_EXISTS_SHARED_PDUS                        (STD_OFF)
# define CANTSYN_EXTENDED_MESSAGE_USED                     (STD_OFF)
# define CANTSYN_STANDARD_MESSAGE_USED                     (STD_ON)

/* Master debounce counter configuration */
# define CANTSYN_TX_CONF_MIXED_DEBOUNCE_COUNTER            (STD_OFF)

/* Multi-Core/Multi-Partition configuration */
# define CANTSYN_MULTIPARTITION_USED                       (STD_OFF)

/* Message types */
#define CANTSYN_TIME_SYNC_MESSAGE_DLC                      (8u)
#define CANTSYN_TIME_SYNC_EXTENDED_MESSAGE_DLC             (16u)
#define CANTSYN_TIME_SYNC_MAX_MESSAGE_DLC                  (CANTSYN_TIME_SYNC_MESSAGE_DLC)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_NOT_CRC        (0x10u)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_CRC            (0x20u)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_NOT_CRC         (0x18u)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_CRC             (0x28u)
#ifdef CANTSYN_AR_4_3_X
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_NOT_CRC         (0x34u)
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_CRC             (0x44u)
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_NOT_CRC        (0x3Cu)
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_CRC            (0x4Cu)
#endif
#ifdef CANTSYN_AR_4_2_X
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_NOT_CRC         (0x30u)
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_CRC             (0x40u)
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_NOT_CRC        (0x38u)
# define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_CRC            (0x48u)
#endif







/**
 * \defgroup CanTSynHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define CanTSynConf_CanTSynGlobalTimeSlavePdu_GTS_Main_CAN_ST3_dd88dcd5_Rx 0u /**< [PostBuildInvariantValuesModelView] */
/**\} */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanTSynPCDataSwitches  CanTSyn Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANTSYN_CONTROLLERINFO                                                                      STD_OFF  /**< Deactivateable: 'CanTSyn_ControllerInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CANTSYN_SNVOFCONTROLLERINFO                                                                 STD_OFF  /**< Deactivateable: 'CanTSyn_ControllerInfo.Snv' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_CONTROLLERPDUPARTITIONMAPPING                                                       STD_OFF  /**< Deactivateable: 'CanTSyn_ControllerPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CANTSYN_CONTROLLERIDOFCONTROLLERPDUPARTITIONMAPPING                                         STD_OFF  /**< Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.ControllerId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_PARTITIONINDEXOFCSLSTRINGSNVOFCONTROLLERPDUPARTITIONMAPPING                         STD_OFF  /**< Deactivateable: 'CanTSyn_ControllerPduPartitionMapping.PartitionIndexOfCslStringSNV' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_DOMAINCONFIG                                                                        STD_ON
#define CANTSYN_CRCANDDOMAINTYPEOFDOMAINCONFIG                                                      STD_ON
#define CANTSYN_DOMAINIDOFDOMAINCONFIG                                                              STD_ON
#define CANTSYN_FUPDATAIDLISTENDIDXOFDOMAINCONFIG                                                   STD_ON
#define CANTSYN_FUPDATAIDLISTSTARTIDXOFDOMAINCONFIG                                                 STD_ON
#define CANTSYN_FUPDATAIDLISTUSEDOFDOMAINCONFIG                                                     STD_ON
#define CANTSYN_MASTERCONFIGENDIDXOFDOMAINCONFIG                                                    STD_OFF  /**< Deactivateable: 'CanTSyn_DomainConfig.MasterConfigEndIdx' Reason: 'the optional indirection is deactivated because MasterConfigUsedOfDomainConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANTSYN_MASTERCONFIGLENGTHOFDOMAINCONFIG                                                    STD_OFF  /**< Deactivateable: 'CanTSyn_DomainConfig.MasterConfigLength' Reason: 'the optional indirection is deactivated because MasterConfigUsedOfDomainConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANTSYN_MASTERCONFIGSTARTIDXOFDOMAINCONFIG                                                  STD_OFF  /**< Deactivateable: 'CanTSyn_DomainConfig.MasterConfigStartIdx' Reason: 'the optional indirection is deactivated because MasterConfigUsedOfDomainConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANTSYN_MASTERCONFIGUSEDOFDOMAINCONFIG                                                      STD_OFF  /**< Deactivateable: 'CanTSyn_DomainConfig.MasterConfigUsed' Reason: 'the optional indirection is deactivated because MasterConfigUsedOfDomainConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANTSYN_MESSAGEDLCOFDOMAINCONFIG                                                            STD_ON
#define CANTSYN_OFFSETDOMAINOFDOMAINCONFIG                                                          STD_ON
#define CANTSYN_SLAVECONFIGIDXOFDOMAINCONFIG                                                        STD_ON
#define CANTSYN_SLAVECONFIGUSEDOFDOMAINCONFIG                                                       STD_ON
#define CANTSYN_SYNCDATAIDLISTENDIDXOFDOMAINCONFIG                                                  STD_ON
#define CANTSYN_SYNCDATAIDLISTSTARTIDXOFDOMAINCONFIG                                                STD_ON
#define CANTSYN_SYNCDATAIDLISTUSEDOFDOMAINCONFIG                                                    STD_ON
#define CANTSYN_TIMEBASEIDOFDOMAINCONFIG                                                            STD_ON
#define CANTSYN_FINALMAGICNUMBER                                                                    STD_OFF  /**< Deactivateable: 'CanTSyn_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANTSYN_FUPDATAIDLIST                                                                       STD_ON
#define CANTSYN_INITDATAHASHCODE                                                                    STD_OFF  /**< Deactivateable: 'CanTSyn_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANTSYN_INITIALIZED                                                                         STD_ON
#define CANTSYN_MASTERCONFIG                                                                        STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CANTSYN_CONTROLLERINFOIDXOFMASTERCONFIG                                                     STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.ControllerInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_CYCLICMSGRESUMETIMEOFMASTERCONFIG                                                   STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.CyclicMsgResumeTime' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_DEBOUNCETIMEOFMASTERCONFIG                                                          STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.DebounceTime' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_DOMAINCONFIGIDXOFMASTERCONFIG                                                       STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.DomainConfigIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_FUPMESSAGETYPEOFMASTERCONFIG                                                        STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.FupMessageType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_IMMEDIATETIMESYNCOFMASTERCONFIG                                                     STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.ImmediateTimeSync' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_MASTERCONFHANDLEIDOFMASTERCONFIG                                                    STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.MasterConfHandleId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_MASTERCONFTIMEOUTOFMASTERCONFIG                                                     STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.MasterConfTimeout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_MESSAGEDOMAINIDOFMASTERCONFIG                                                       STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.MessageDomainId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_PARTITIONINDEXOFCSLSTRINGSNVOFMASTERCONFIG                                          STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.PartitionIndexOfCslStringSNV' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_PDUIDSTATESIDXOFMASTERCONFIG                                                        STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.PduIdStatesIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_SYNCMESSAGETYPEOFMASTERCONFIG                                                       STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.SyncMessageType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_TXCRCSECUREDOFMASTERCONFIG                                                          STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.TxCrcSecured' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG                                                  STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.TxDebounceCounterIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_TXDEBOUNCECOUNTERUSEDOFMASTERCONFIG                                                 STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.TxDebounceCounterUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_TXPDUIDOFMASTERCONFIG                                                               STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.TxPduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_TXPERIODOFMASTERCONFIG                                                              STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.TxPeriod' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_MASTERPDUPARTITIONMAPPING                                                           STD_OFF  /**< Deactivateable: 'CanTSyn_MasterPduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CANTSYN_PARTITIONINDEXOFCSLSTRINGSNVOFMASTERPDUPARTITIONMAPPING                             STD_OFF  /**< Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PartitionIndexOfCslStringSNV' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_PDUIDOFMASTERPDUPARTITIONMAPPING                                                    STD_OFF  /**< Deactivateable: 'CanTSyn_MasterPduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_MASTERSTATE                                                                         STD_OFF  /**< Deactivateable: 'CanTSyn_MasterState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CANTSYN_CYCLICMSGRESUMECOUNTEROFMASTERSTATE                                                 STD_OFF  /**< Deactivateable: 'CanTSyn_MasterState.CyclicMsgResumeCounter' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CANTSYN_FUPTIMESTAMPOFMASTERSTATE                                                           STD_OFF  /**< Deactivateable: 'CanTSyn_MasterState.FupTimeStamp' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CANTSYN_LASTUPDATECOUNTEROFMASTERSTATE                                                      STD_OFF  /**< Deactivateable: 'CanTSyn_MasterState.LastUpdateCounter' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CANTSYN_STATEOFMASTERSTATE                                                                  STD_OFF  /**< Deactivateable: 'CanTSyn_MasterState.State' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CANTSYN_SYNCTIMESTAMPOFMASTERSTATE                                                          STD_OFF  /**< Deactivateable: 'CanTSyn_MasterState.SyncTimestamp' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CANTSYN_TRANSMITIMMEDIATESYNCOFMASTERSTATE                                                  STD_OFF  /**< Deactivateable: 'CanTSyn_MasterState.TransmitImmediateSync' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CANTSYN_TXCONFIRMATIONTIMEOUTCOUNTEROFMASTERSTATE                                           STD_OFF  /**< Deactivateable: 'CanTSyn_MasterState.TxConfirmationTimeoutCounter' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CANTSYN_TXPERIODCOUNTEROFMASTERSTATE                                                        STD_OFF  /**< Deactivateable: 'CanTSyn_MasterState.TxPeriodCounter' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CANTSYN_TXSEQUENCECOUNTEROFMASTERSTATE                                                      STD_OFF  /**< Deactivateable: 'CanTSyn_MasterState.TxSequenceCounter' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CANTSYN_USERDATAOFMASTERSTATE                                                               STD_OFF  /**< Deactivateable: 'CanTSyn_MasterState.UserData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CANTSYN_VIRTUALLOCALTIMEOFMASTERSTATE                                                       STD_OFF  /**< Deactivateable: 'CanTSyn_MasterState.VirtualLocalTime' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CANTSYN_PARTITIONIDENTIFIERS                                                                STD_ON
#define CANTSYN_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                          STD_ON
#define CANTSYN_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                  STD_ON
#define CANTSYN_PDUIDSTATES                                                                         STD_OFF  /**< Deactivateable: 'CanTSyn_PduIdStates' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_SIZEOFCONTROLLERINFO                                                                STD_OFF  /**< Deactivateable: 'CanTSyn_SizeOfControllerInfo' Reason: 'Deactivateable: 'CanTSyn_ControllerInfo' Reason: 'the struct is deactivated because all elements are deactivated.'' */
#define CANTSYN_SIZEOFDOMAINCONFIG                                                                  STD_ON
#define CANTSYN_SIZEOFFUPDATAIDLIST                                                                 STD_ON
#define CANTSYN_SIZEOFMASTERCONFIG                                                                  STD_OFF  /**< Deactivateable: 'CanTSyn_SizeOfMasterConfig' Reason: 'Deactivateable: 'CanTSyn_MasterConfig' Reason: 'the struct is deactivated because all elements are deactivated.'' */
#define CANTSYN_SIZEOFMASTERSTATE                                                                   STD_OFF  /**< Deactivateable: 'CanTSyn_SizeOfMasterState' Reason: 'Deactivateable: 'CanTSyn_MasterState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.'' */
#define CANTSYN_SIZEOFPARTITIONIDENTIFIERS                                                          STD_ON
#define CANTSYN_SIZEOFSLAVECONFIG                                                                   STD_ON
#define CANTSYN_SIZEOFSLAVESTATE                                                                    STD_ON
#define CANTSYN_SIZEOFSYNCDATAIDLIST                                                                STD_ON
#define CANTSYN_SIZEOFTRANSMISSIONCONTROLLERSTATE                                                   STD_OFF  /**< Deactivateable: 'CanTSyn_SizeOfTransmissionControllerState' Reason: 'Deactivateable: 'CanTSyn_TransmissionControllerState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE'' */
#define CANTSYN_SLAVECONFIG                                                                         STD_ON
#define CANTSYN_DOMAINCONFIGIDXOFSLAVECONFIG                                                        STD_ON
#define CANTSYN_FOLLOWUPTIMEOUTOFSLAVECONFIG                                                        STD_ON
#define CANTSYN_PARTITIONCONFIGIDXOFSLAVECONFIG                                                     STD_ON
#define CANTSYN_RXCRCVALIDATEDOFSLAVECONFIG                                                         STD_ON
#define CANTSYN_SEQUENCECOUNTERJUMPWIDTHOFSLAVECONFIG                                               STD_ON
#define CANTSYN_SLAVEHANDLEIDOFSLAVECONFIG                                                          STD_ON
#define CANTSYN_SLAVEPDUPARTITIONMAPPING                                                            STD_OFF  /**< Deactivateable: 'CanTSyn_SlavePduPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CANTSYN_PARTITIONINDEXOFCSLSTRINGSNVOFSLAVEPDUPARTITIONMAPPING                              STD_OFF  /**< Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PartitionIndexOfCslStringSNV' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_PDUIDOFSLAVEPDUPARTITIONMAPPING                                                     STD_OFF  /**< Deactivateable: 'CanTSyn_SlavePduPartitionMapping.PduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_SLAVESTATE                                                                          STD_ON
#define CANTSYN_RXFOLLOWUPTIMEOUTCOUNTOFSLAVESTATE                                                  STD_ON
#define CANTSYN_RXSEQUENCECOUNTEROFSLAVESTATE                                                       STD_ON
#define CANTSYN_STATEOFSLAVESTATE                                                                   STD_ON
#define CANTSYN_SYNCMSGOFSLAVESTATE                                                                 STD_ON
#define CANTSYN_VIRTUALLOCALTIMEOFSLAVESTATE                                                        STD_ON
#define CANTSYN_SYNCDATAIDLIST                                                                      STD_ON
#define CANTSYN_TRANSMISSIONCONTROLLERSTATE                                                         STD_OFF  /**< Deactivateable: 'CanTSyn_TransmissionControllerState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_TXDEBOUNCECOUNTER                                                                   STD_OFF  /**< Deactivateable: 'CanTSyn_TxDebounceCounter' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_PCCONFIG                                                                            STD_ON
#define CANTSYN_FINALMAGICNUMBEROFPCCONFIG                                                          STD_OFF  /**< Deactivateable: 'CanTSyn_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANTSYN_INITDATAHASHCODEOFPCCONFIG                                                          STD_OFF  /**< Deactivateable: 'CanTSyn_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANTSYN_PCPARTITIONCONFIGOFPCCONFIG                                                         STD_ON
#define CANTSYN_PARTITIONIDENTIFIERSOFPCCONFIG                                                      STD_ON
#define CANTSYN_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                STD_ON
#define CANTSYN_PCPARTITIONCONFIG                                                                   STD_ON
#define CANTSYN_DOMAINCONFIGOFPCPARTITIONCONFIG                                                     STD_ON
#define CANTSYN_FUPDATAIDLISTOFPCPARTITIONCONFIG                                                    STD_ON
#define CANTSYN_INITIALIZEDOFPCPARTITIONCONFIG                                                      STD_ON
#define CANTSYN_SIZEOFCONTROLLERINFOOFPCPARTITIONCONFIG                                             STD_OFF  /**< Deactivateable: 'CanTSyn_PCPartitionConfig.SizeOfControllerInfo' Reason: 'Deactivateable: 'CanTSyn_ControllerInfo' Reason: 'the struct is deactivated because all elements are deactivated.'' */
#define CANTSYN_SIZEOFDOMAINCONFIGOFPCPARTITIONCONFIG                                               STD_ON
#define CANTSYN_SIZEOFFUPDATAIDLISTOFPCPARTITIONCONFIG                                              STD_ON
#define CANTSYN_SIZEOFMASTERCONFIGOFPCPARTITIONCONFIG                                               STD_OFF  /**< Deactivateable: 'CanTSyn_PCPartitionConfig.SizeOfMasterConfig' Reason: 'Deactivateable: 'CanTSyn_MasterConfig' Reason: 'the struct is deactivated because all elements are deactivated.'' */
#define CANTSYN_SIZEOFMASTERSTATEOFPCPARTITIONCONFIG                                                STD_OFF  /**< Deactivateable: 'CanTSyn_PCPartitionConfig.SizeOfMasterState' Reason: 'Deactivateable: 'CanTSyn_MasterState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.'' */
#define CANTSYN_SIZEOFSLAVECONFIGOFPCPARTITIONCONFIG                                                STD_ON
#define CANTSYN_SIZEOFSLAVESTATEOFPCPARTITIONCONFIG                                                 STD_ON
#define CANTSYN_SIZEOFSYNCDATAIDLISTOFPCPARTITIONCONFIG                                             STD_ON
#define CANTSYN_SIZEOFTRANSMISSIONCONTROLLERSTATEOFPCPARTITIONCONFIG                                STD_OFF  /**< Deactivateable: 'CanTSyn_PCPartitionConfig.SizeOfTransmissionControllerState' Reason: 'Deactivateable: 'CanTSyn_TransmissionControllerState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE'' */
#define CANTSYN_SLAVECONFIGOFPCPARTITIONCONFIG                                                      STD_ON
#define CANTSYN_SLAVESTATEOFPCPARTITIONCONFIG                                                       STD_ON
#define CANTSYN_SYNCDATAIDLISTOFPCPARTITIONCONFIG                                                   STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCMinNumericValueDefines  CanTSyn Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CANTSYN_MIN_RXFOLLOWUPTIMEOUTCOUNTOFSLAVESTATE                                              0u
#define CANTSYN_MIN_RXSEQUENCECOUNTEROFSLAVESTATE                                                   0u
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCMaxNumericValueDefines  CanTSyn Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CANTSYN_MAX_RXFOLLOWUPTIMEOUTCOUNTOFSLAVESTATE                                              4294967295u
#define CANTSYN_MAX_RXSEQUENCECOUNTEROFSLAVESTATE                                                   255u
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCNoReferenceDefines  CanTSyn No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CANTSYN_NO_FUPDATAIDLISTENDIDXOFDOMAINCONFIG                                                255u
#define CANTSYN_NO_FUPDATAIDLISTSTARTIDXOFDOMAINCONFIG                                              255u
#define CANTSYN_NO_SLAVECONFIGIDXOFDOMAINCONFIG                                                     255u
#define CANTSYN_NO_SYNCDATAIDLISTENDIDXOFDOMAINCONFIG                                               255u
#define CANTSYN_NO_SYNCDATAIDLISTSTARTIDXOFDOMAINCONFIG                                             255u
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCEnumExistsDefines  CanTSyn Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define CANTSYN_EXISTS_CRC_OFFSET_CRCANDDOMAINTYPEOFDOMAINCONFIG                                    STD_OFF
#define CANTSYN_EXISTS_NOT_CRC_OFFSET_CRCANDDOMAINTYPEOFDOMAINCONFIG                                STD_OFF
#define CANTSYN_EXISTS_CRC_SYNC_CRCANDDOMAINTYPEOFDOMAINCONFIG                                      STD_OFF
#define CANTSYN_EXISTS_NOT_CRC_SYNC_CRCANDDOMAINTYPEOFDOMAINCONFIG                                  STD_ON
#define CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG                                            STD_OFF
#define CANTSYN_EXISTS_NOT_OFFSET_OFFSETDOMAINOFDOMAINCONFIG                                        STD_ON
#define CANTSYN_EXISTS_NOT_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG                                STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.ImmediateTimeSync' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG                                    STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.ImmediateTimeSync' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_EXISTS_SYNC_TXCRCSECUREDOFMASTERCONFIG                                              STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.TxCrcSecured' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_EXISTS_SYNC_CRC_TXCRCSECUREDOFMASTERCONFIG                                          STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.TxCrcSecured' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_EXISTS_OFS_TXCRCSECUREDOFMASTERCONFIG                                               STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.TxCrcSecured' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_EXISTS_OFS_CRC_TXCRCSECUREDOFMASTERCONFIG                                           STD_OFF  /**< Deactivateable: 'CanTSyn_MasterConfig.TxCrcSecured' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG                                          STD_OFF
#define CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG                                    STD_OFF
#define CANTSYN_EXISTS_OPTIONAL_RXCRCVALIDATEDOFSLAVECONFIG                                         STD_OFF
#define CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG                                        STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCEnumDefines  CanTSyn Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define CANTSYN_NOT_CRC_SYNC_CRCANDDOMAINTYPEOFDOMAINCONFIG                                         0x03u
#define CANTSYN_NOT_OFFSET_OFFSETDOMAINOFDOMAINCONFIG                                               0x01u
#define CANTSYN_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG                                               0x03u
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCIsReducedToDefineDefines  CanTSyn Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CANTSYN_ISDEF_CRCANDDOMAINTYPEOFDOMAINCONFIG                                                STD_OFF
#define CANTSYN_ISDEF_DOMAINIDOFDOMAINCONFIG                                                        STD_OFF
#define CANTSYN_ISDEF_FUPDATAIDLISTENDIDXOFDOMAINCONFIG                                             STD_OFF
#define CANTSYN_ISDEF_FUPDATAIDLISTSTARTIDXOFDOMAINCONFIG                                           STD_OFF
#define CANTSYN_ISDEF_FUPDATAIDLISTUSEDOFDOMAINCONFIG                                               STD_OFF
#define CANTSYN_ISDEF_MESSAGEDLCOFDOMAINCONFIG                                                      STD_OFF
#define CANTSYN_ISDEF_OFFSETDOMAINOFDOMAINCONFIG                                                    STD_OFF
#define CANTSYN_ISDEF_SLAVECONFIGIDXOFDOMAINCONFIG                                                  STD_OFF
#define CANTSYN_ISDEF_SLAVECONFIGUSEDOFDOMAINCONFIG                                                 STD_OFF
#define CANTSYN_ISDEF_SYNCDATAIDLISTENDIDXOFDOMAINCONFIG                                            STD_OFF
#define CANTSYN_ISDEF_SYNCDATAIDLISTSTARTIDXOFDOMAINCONFIG                                          STD_OFF
#define CANTSYN_ISDEF_SYNCDATAIDLISTUSEDOFDOMAINCONFIG                                              STD_OFF
#define CANTSYN_ISDEF_TIMEBASEIDOFDOMAINCONFIG                                                      STD_OFF
#define CANTSYN_ISDEF_FUPDATAIDLIST                                                                 STD_OFF
#define CANTSYN_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                    STD_OFF
#define CANTSYN_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                            STD_OFF
#define CANTSYN_ISDEF_DOMAINCONFIGIDXOFSLAVECONFIG                                                  STD_OFF
#define CANTSYN_ISDEF_FOLLOWUPTIMEOUTOFSLAVECONFIG                                                  STD_OFF
#define CANTSYN_ISDEF_PARTITIONCONFIGIDXOFSLAVECONFIG                                               STD_OFF
#define CANTSYN_ISDEF_RXCRCVALIDATEDOFSLAVECONFIG                                                   STD_OFF
#define CANTSYN_ISDEF_SEQUENCECOUNTERJUMPWIDTHOFSLAVECONFIG                                         STD_OFF
#define CANTSYN_ISDEF_SLAVEHANDLEIDOFSLAVECONFIG                                                    STD_OFF
#define CANTSYN_ISDEF_SYNCDATAIDLIST                                                                STD_OFF
#define CANTSYN_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                   STD_ON
#define CANTSYN_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                STD_ON
#define CANTSYN_ISDEF_DOMAINCONFIGOFPCPARTITIONCONFIG                                               STD_ON
#define CANTSYN_ISDEF_FUPDATAIDLISTOFPCPARTITIONCONFIG                                              STD_ON
#define CANTSYN_ISDEF_INITIALIZEDOFPCPARTITIONCONFIG                                                STD_ON
#define CANTSYN_ISDEF_SLAVECONFIGOFPCPARTITIONCONFIG                                                STD_ON
#define CANTSYN_ISDEF_SLAVESTATEOFPCPARTITIONCONFIG                                                 STD_ON
#define CANTSYN_ISDEF_SYNCDATAIDLISTOFPCPARTITIONCONFIG                                             STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCEqualsAlwaysToDefines  CanTSyn Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CANTSYN_EQ2_CRCANDDOMAINTYPEOFDOMAINCONFIG                                                  
#define CANTSYN_EQ2_DOMAINIDOFDOMAINCONFIG                                                          
#define CANTSYN_EQ2_FUPDATAIDLISTENDIDXOFDOMAINCONFIG                                               
#define CANTSYN_EQ2_FUPDATAIDLISTSTARTIDXOFDOMAINCONFIG                                             
#define CANTSYN_EQ2_FUPDATAIDLISTUSEDOFDOMAINCONFIG                                                 
#define CANTSYN_EQ2_MESSAGEDLCOFDOMAINCONFIG                                                        
#define CANTSYN_EQ2_OFFSETDOMAINOFDOMAINCONFIG                                                      
#define CANTSYN_EQ2_SLAVECONFIGIDXOFDOMAINCONFIG                                                    
#define CANTSYN_EQ2_SLAVECONFIGUSEDOFDOMAINCONFIG                                                   
#define CANTSYN_EQ2_SYNCDATAIDLISTENDIDXOFDOMAINCONFIG                                              
#define CANTSYN_EQ2_SYNCDATAIDLISTSTARTIDXOFDOMAINCONFIG                                            
#define CANTSYN_EQ2_SYNCDATAIDLISTUSEDOFDOMAINCONFIG                                                
#define CANTSYN_EQ2_TIMEBASEIDOFDOMAINCONFIG                                                        
#define CANTSYN_EQ2_FUPDATAIDLIST                                                                   
#define CANTSYN_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                      
#define CANTSYN_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                              
#define CANTSYN_EQ2_DOMAINCONFIGIDXOFSLAVECONFIG                                                    
#define CANTSYN_EQ2_FOLLOWUPTIMEOUTOFSLAVECONFIG                                                    
#define CANTSYN_EQ2_PARTITIONCONFIGIDXOFSLAVECONFIG                                                 
#define CANTSYN_EQ2_RXCRCVALIDATEDOFSLAVECONFIG                                                     
#define CANTSYN_EQ2_SEQUENCECOUNTERJUMPWIDTHOFSLAVECONFIG                                           
#define CANTSYN_EQ2_SLAVEHANDLEIDOFSLAVECONFIG                                                      
#define CANTSYN_EQ2_SYNCDATAIDLIST                                                                  
#define CANTSYN_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                     CanTSyn_PCPartitionConfig
#define CANTSYN_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                  CanTSyn_PartitionIdentifiers
#define CANTSYN_EQ2_DOMAINCONFIGOFPCPARTITIONCONFIG                                                 CanTSyn_DomainConfig
#define CANTSYN_EQ2_FUPDATAIDLISTOFPCPARTITIONCONFIG                                                CanTSyn_FupDataIDList
#define CANTSYN_EQ2_INITIALIZEDOFPCPARTITIONCONFIG                                                  (&(CanTSyn_Initialized))
#define CANTSYN_EQ2_SLAVECONFIGOFPCPARTITIONCONFIG                                                  CanTSyn_SlaveConfig
#define CANTSYN_EQ2_SLAVESTATEOFPCPARTITIONCONFIG                                                   CanTSyn_SlaveState.raw
#define CANTSYN_EQ2_SYNCDATAIDLISTOFPCPARTITIONCONFIG                                               CanTSyn_SyncDataIDList
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCSymbolicInitializationPointers  CanTSyn Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define CanTSyn_Config_Ptr                                                                          NULL_PTR  /**< symbolic identifier which shall be used to initialize 'CanTSyn' */
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCInitializationSymbols  CanTSyn Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define CanTSyn_Config                                                                              NULL_PTR  /**< symbolic identifier which could be used to initialize 'CanTSyn */
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCGeneral  CanTSyn General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CANTSYN_CHECK_INIT_POINTER                                                                  STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CANTSYN_FINAL_MAGIC_NUMBER                                                                  0xA11Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of CanTSyn */
#define CANTSYN_INDIVIDUAL_POSTBUILD                                                                STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'CanTSyn' is not configured to be postbuild capable. */
#define CANTSYN_INIT_DATA                                                                           CANTSYN_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CANTSYN_INIT_DATA_HASH_CODE                                                                 248192596  /**< the precompile constant to validate the initialization structure at initialization time of CanTSyn with a hashcode. The seed value is '0xA11Eu' */
#define CANTSYN_USE_ECUM_BSW_ERROR_HOOK                                                             STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CANTSYN_USE_INIT_POINTER                                                                    STD_OFF  /**< STD_ON if the init pointer CanTSyn shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
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
  \defgroup  CanTSynPCGetConstantDuplicatedRootDataMacros  CanTSyn Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define CanTSyn_GetPartitionIdentifiersOfPCConfig()                                                 CanTSyn_PartitionIdentifiers  /**< the pointer to CanTSyn_PartitionIdentifiers */
#define CanTSyn_GetSizeOfPartitionIdentifiersOfPCConfig()                                           1u  /**< the number of accomplishable value elements in CanTSyn_PartitionIdentifiers */
#define CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)                                  CanTSyn_DomainConfig  /**< the pointer to CanTSyn_DomainConfig */
#define CanTSyn_GetFupDataIDListOfPCPartitionConfig(partitionIndex)                                 CanTSyn_FupDataIDList  /**< the pointer to CanTSyn_FupDataIDList */
#define CanTSyn_GetInitializedOfPCPartitionConfig(partitionIndex)                                   (&(CanTSyn_Initialized))  /**< the pointer to CanTSyn_Initialized */
#define CanTSyn_GetSizeOfDomainConfigOfPCPartitionConfig(partitionIndex)                            1u  /**< the number of accomplishable value elements in CanTSyn_DomainConfig */
#define CanTSyn_GetSizeOfFupDataIDListOfPCPartitionConfig(partitionIndex)                           16u  /**< the number of accomplishable value elements in CanTSyn_FupDataIDList */
#define CanTSyn_GetSizeOfSlaveConfigOfPCPartitionConfig(partitionIndex)                             1u  /**< the number of accomplishable value elements in CanTSyn_SlaveConfig */
#define CanTSyn_GetSizeOfSyncDataIDListOfPCPartitionConfig(partitionIndex)                          16u  /**< the number of accomplishable value elements in CanTSyn_SyncDataIDList */
#define CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)                                   CanTSyn_SlaveConfig  /**< the pointer to CanTSyn_SlaveConfig */
#define CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)                                    CanTSyn_SlaveState.raw  /**< the pointer to CanTSyn_SlaveState */
#define CanTSyn_GetSyncDataIDListOfPCPartitionConfig(partitionIndex)                                CanTSyn_SyncDataIDList  /**< the pointer to CanTSyn_SyncDataIDList */
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCGetDuplicatedRootDataMacros  CanTSyn Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define CanTSyn_GetSizeOfSlaveStateOfPCPartitionConfig(partitionIndex)                              CanTSyn_GetSizeOfSlaveConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in CanTSyn_SlaveState */
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCGetDataMacros  CanTSyn Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define CanTSyn_GetCrcAndDomainTypeOfDomainConfig(Index, partitionIndex)                            (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].CrcAndDomainTypeOfDomainConfig)
#define CanTSyn_GetDomainIdOfDomainConfig(Index, partitionIndex)                                    (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].DomainIdOfDomainConfig)
#define CanTSyn_GetFupDataIDListEndIdxOfDomainConfig(Index, partitionIndex)                         (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].FupDataIDListEndIdxOfDomainConfig)
#define CanTSyn_GetFupDataIDListStartIdxOfDomainConfig(Index, partitionIndex)                       (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].FupDataIDListStartIdxOfDomainConfig)
#define CanTSyn_GetMessageDlcOfDomainConfig(Index, partitionIndex)                                  (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].MessageDlcOfDomainConfig)
#define CanTSyn_GetOffsetDomainOfDomainConfig(Index, partitionIndex)                                (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].OffsetDomainOfDomainConfig)
#define CanTSyn_GetSlaveConfigIdxOfDomainConfig(Index, partitionIndex)                              (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].SlaveConfigIdxOfDomainConfig)
#define CanTSyn_GetSyncDataIDListEndIdxOfDomainConfig(Index, partitionIndex)                        (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].SyncDataIDListEndIdxOfDomainConfig)
#define CanTSyn_GetSyncDataIDListStartIdxOfDomainConfig(Index, partitionIndex)                      (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].SyncDataIDListStartIdxOfDomainConfig)
#define CanTSyn_GetTimeBaseIdOfDomainConfig(Index, partitionIndex)                                  (CanTSyn_GetDomainConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeBaseIdOfDomainConfig)
#define CanTSyn_GetFupDataIDList(Index, partitionIndex)                                             (CanTSyn_GetFupDataIDListOfPCPartitionConfig(partitionIndex)[(Index)])
#define CanTSyn_IsInitialized(partitionIndex)                                                       (((*(CanTSyn_GetInitializedOfPCPartitionConfig(partitionIndex)))) != FALSE)
#define CanTSyn_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                (CanTSyn_GetPartitionIdentifiersOfPCConfig()[(Index)].PCPartitionConfigIdxOfPartitionIdentifiers)
#define CanTSyn_GetPartitionSNVOfPartitionIdentifiers(Index)                                        (CanTSyn_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define CanTSyn_GetDomainConfigIdxOfSlaveConfig(Index, partitionIndex)                              (CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)[(Index)].DomainConfigIdxOfSlaveConfig)
#define CanTSyn_GetFollowUpTimeoutOfSlaveConfig(Index, partitionIndex)                              (CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)[(Index)].FollowUpTimeoutOfSlaveConfig)
#define CanTSyn_GetPartitionConfigIdxOfSlaveConfig(Index, partitionIndex)                           (CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)[(Index)].PartitionConfigIdxOfSlaveConfig)
#define CanTSyn_GetRxCrcValidatedOfSlaveConfig(Index, partitionIndex)                               (CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)[(Index)].RxCrcValidatedOfSlaveConfig)
#define CanTSyn_GetSequenceCounterJumpWidthOfSlaveConfig(Index, partitionIndex)                     (CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)[(Index)].SequenceCounterJumpWidthOfSlaveConfig)
#define CanTSyn_GetSlaveHandleIdOfSlaveConfig(Index, partitionIndex)                                (CanTSyn_GetSlaveConfigOfPCPartitionConfig(partitionIndex)[(Index)].SlaveHandleIdOfSlaveConfig)
#define CanTSyn_GetRxFollowUpTimeoutCountOfSlaveState(Index, partitionIndex)                        (CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].RxFollowUpTimeoutCountOfSlaveState)
#define CanTSyn_GetRxSequenceCounterOfSlaveState(Index, partitionIndex)                             (CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].RxSequenceCounterOfSlaveState)
#define CanTSyn_GetStateOfSlaveState(Index, partitionIndex)                                         (CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].StateOfSlaveState)
#define CanTSyn_GetVirtualLocalTimeOfSlaveState(Index, partitionIndex)                              (CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeOfSlaveState)
#define CanTSyn_GetSyncDataIDList(Index, partitionIndex)                                            (CanTSyn_GetSyncDataIDListOfPCPartitionConfig(partitionIndex)[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCGetDeduplicatedDataMacros  CanTSyn Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define CanTSyn_IsFupDataIDListUsedOfDomainConfig(Index, partitionIndex)                            (((boolean)(CanTSyn_GetFupDataIDListStartIdxOfDomainConfig(((Index)), (partitionIndex)) != CANTSYN_NO_FUPDATAIDLISTSTARTIDXOFDOMAINCONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanTSyn_FupDataIDList */
#define CanTSyn_IsSlaveConfigUsedOfDomainConfig(Index, partitionIndex)                              (((boolean)(CanTSyn_GetSlaveConfigIdxOfDomainConfig(((Index)), (partitionIndex)) != CANTSYN_NO_SLAVECONFIGIDXOFDOMAINCONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanTSyn_SlaveConfig */
#define CanTSyn_IsSyncDataIDListUsedOfDomainConfig(Index, partitionIndex)                           (((boolean)(CanTSyn_GetSyncDataIDListStartIdxOfDomainConfig(((Index)), (partitionIndex)) != CANTSYN_NO_SYNCDATAIDLISTSTARTIDXOFDOMAINCONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanTSyn_SyncDataIDList */
#define CanTSyn_GetSizeOfDomainConfig(partitionIndex)                                               CanTSyn_GetSizeOfDomainConfigOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfFupDataIDList(partitionIndex)                                              CanTSyn_GetSizeOfFupDataIDListOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfPartitionIdentifiers()                                                     CanTSyn_GetSizeOfPartitionIdentifiersOfPCConfig()
#define CanTSyn_GetSizeOfSlaveConfig(partitionIndex)                                                CanTSyn_GetSizeOfSlaveConfigOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfSlaveState(partitionIndex)                                                 CanTSyn_GetSizeOfSlaveStateOfPCPartitionConfig(partitionIndex)
#define CanTSyn_GetSizeOfSyncDataIDList(partitionIndex)                                             CanTSyn_GetSizeOfSyncDataIDListOfPCPartitionConfig(partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCSetDataMacros  CanTSyn Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define CanTSyn_SetInitialized(Value, partitionIndex)                                               (*(CanTSyn_GetInitializedOfPCPartitionConfig(partitionIndex))) = (Value)
#define CanTSyn_SetRxFollowUpTimeoutCountOfSlaveState(Index, Value, partitionIndex)                 CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].RxFollowUpTimeoutCountOfSlaveState = (Value)
#define CanTSyn_SetRxSequenceCounterOfSlaveState(Index, Value, partitionIndex)                      CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].RxSequenceCounterOfSlaveState = (Value)
#define CanTSyn_SetStateOfSlaveState(Index, Value, partitionIndex)                                  CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].StateOfSlaveState = (Value)
#define CanTSyn_SetVirtualLocalTimeOfSlaveState(Index, Value, partitionIndex)                       CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeOfSlaveState = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCGetAddressOfDataMacros  CanTSyn Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define CanTSyn_GetAddrSyncMsgOfSlaveState(Index, partitionIndex)                                   (&(CanTSyn_GetSlaveStateOfPCPartitionConfig(partitionIndex)[(Index)].SyncMsgOfSlaveState))
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCHasMacros  CanTSyn Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CanTSyn_HasDomainConfig(partitionIndex)                                                     (TRUE != FALSE)
#define CanTSyn_HasCrcAndDomainTypeOfDomainConfig(partitionIndex)                                   (TRUE != FALSE)
#define CanTSyn_HasDomainIdOfDomainConfig(partitionIndex)                                           (TRUE != FALSE)
#define CanTSyn_HasFupDataIDListEndIdxOfDomainConfig(partitionIndex)                                (TRUE != FALSE)
#define CanTSyn_HasFupDataIDListStartIdxOfDomainConfig(partitionIndex)                              (TRUE != FALSE)
#define CanTSyn_HasFupDataIDListUsedOfDomainConfig(partitionIndex)                                  (TRUE != FALSE)
#define CanTSyn_HasMessageDlcOfDomainConfig(partitionIndex)                                         (TRUE != FALSE)
#define CanTSyn_HasOffsetDomainOfDomainConfig(partitionIndex)                                       (TRUE != FALSE)
#define CanTSyn_HasSlaveConfigIdxOfDomainConfig(partitionIndex)                                     (TRUE != FALSE)
#define CanTSyn_HasSlaveConfigUsedOfDomainConfig(partitionIndex)                                    (TRUE != FALSE)
#define CanTSyn_HasSyncDataIDListEndIdxOfDomainConfig(partitionIndex)                               (TRUE != FALSE)
#define CanTSyn_HasSyncDataIDListStartIdxOfDomainConfig(partitionIndex)                             (TRUE != FALSE)
#define CanTSyn_HasSyncDataIDListUsedOfDomainConfig(partitionIndex)                                 (TRUE != FALSE)
#define CanTSyn_HasTimeBaseIdOfDomainConfig(partitionIndex)                                         (TRUE != FALSE)
#define CanTSyn_HasFupDataIDList(partitionIndex)                                                    (TRUE != FALSE)
#define CanTSyn_HasInitialized(partitionIndex)                                                      (TRUE != FALSE)
#define CanTSyn_HasPartitionIdentifiers()                                                           (TRUE != FALSE)
#define CanTSyn_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                     (TRUE != FALSE)
#define CanTSyn_HasPartitionSNVOfPartitionIdentifiers()                                             (TRUE != FALSE)
#define CanTSyn_HasSizeOfDomainConfig(partitionIndex)                                               (TRUE != FALSE)
#define CanTSyn_HasSizeOfFupDataIDList(partitionIndex)                                              (TRUE != FALSE)
#define CanTSyn_HasSizeOfPartitionIdentifiers()                                                     (TRUE != FALSE)
#define CanTSyn_HasSizeOfSlaveConfig(partitionIndex)                                                (TRUE != FALSE)
#define CanTSyn_HasSizeOfSlaveState(partitionIndex)                                                 (TRUE != FALSE)
#define CanTSyn_HasSizeOfSyncDataIDList(partitionIndex)                                             (TRUE != FALSE)
#define CanTSyn_HasSlaveConfig(partitionIndex)                                                      (TRUE != FALSE)
#define CanTSyn_HasDomainConfigIdxOfSlaveConfig(partitionIndex)                                     (TRUE != FALSE)
#define CanTSyn_HasFollowUpTimeoutOfSlaveConfig(partitionIndex)                                     (TRUE != FALSE)
#define CanTSyn_HasPartitionConfigIdxOfSlaveConfig(partitionIndex)                                  (TRUE != FALSE)
#define CanTSyn_HasRxCrcValidatedOfSlaveConfig(partitionIndex)                                      (TRUE != FALSE)
#define CanTSyn_HasSequenceCounterJumpWidthOfSlaveConfig(partitionIndex)                            (TRUE != FALSE)
#define CanTSyn_HasSlaveHandleIdOfSlaveConfig(partitionIndex)                                       (TRUE != FALSE)
#define CanTSyn_HasSlaveState(partitionIndex)                                                       (TRUE != FALSE)
#define CanTSyn_HasRxFollowUpTimeoutCountOfSlaveState(partitionIndex)                               (TRUE != FALSE)
#define CanTSyn_HasRxSequenceCounterOfSlaveState(partitionIndex)                                    (TRUE != FALSE)
#define CanTSyn_HasStateOfSlaveState(partitionIndex)                                                (TRUE != FALSE)
#define CanTSyn_HasSyncMsgOfSlaveState(partitionIndex)                                              (TRUE != FALSE)
#define CanTSyn_HasVirtualLocalTimeOfSlaveState(partitionIndex)                                     (TRUE != FALSE)
#define CanTSyn_HasSyncDataIDList(partitionIndex)                                                   (TRUE != FALSE)
#define CanTSyn_HasPCConfig()                                                                       (TRUE != FALSE)
#define CanTSyn_HasPCPartitionConfigOfPCConfig()                                                    (TRUE != FALSE)
#define CanTSyn_HasPartitionIdentifiersOfPCConfig()                                                 (TRUE != FALSE)
#define CanTSyn_HasSizeOfPartitionIdentifiersOfPCConfig()                                           (TRUE != FALSE)
#define CanTSyn_HasPCPartitionConfig()                                                              (TRUE != FALSE)
#define CanTSyn_HasDomainConfigOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define CanTSyn_HasFupDataIDListOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define CanTSyn_HasInitializedOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define CanTSyn_HasSizeOfDomainConfigOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define CanTSyn_HasSizeOfFupDataIDListOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define CanTSyn_HasSizeOfSlaveConfigOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define CanTSyn_HasSizeOfSlaveStateOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define CanTSyn_HasSizeOfSyncDataIDListOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define CanTSyn_HasSlaveConfigOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define CanTSyn_HasSlaveStateOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define CanTSyn_HasSyncDataIDListOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCIncrementDataMacros  CanTSyn Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define CanTSyn_IncRxFollowUpTimeoutCountOfSlaveState(Index, partitionIndex)                        CanTSyn_GetRxFollowUpTimeoutCountOfSlaveState(((Index)), (partitionIndex))++
#define CanTSyn_IncRxSequenceCounterOfSlaveState(Index, partitionIndex)                             CanTSyn_GetRxSequenceCounterOfSlaveState(((Index)), (partitionIndex))++
#define CanTSyn_IncStateOfSlaveState(Index, partitionIndex)                                         CanTSyn_GetStateOfSlaveState(((Index)), (partitionIndex))++
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCDecrementDataMacros  CanTSyn Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define CanTSyn_DecRxFollowUpTimeoutCountOfSlaveState(Index, partitionIndex)                        CanTSyn_GetRxFollowUpTimeoutCountOfSlaveState(((Index)), (partitionIndex))--
#define CanTSyn_DecRxSequenceCounterOfSlaveState(Index, partitionIndex)                             CanTSyn_GetRxSequenceCounterOfSlaveState(((Index)), (partitionIndex))--
#define CanTSyn_DecStateOfSlaveState(Index, partitionIndex)                                         CanTSyn_GetStateOfSlaveState(((Index)), (partitionIndex))--
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCAddDataMacros  CanTSyn Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define CanTSyn_AddRxFollowUpTimeoutCountOfSlaveState(Index, Value, partitionIndex)                 CanTSyn_SetRxFollowUpTimeoutCountOfSlaveState(Index, (CanTSyn_GetRxFollowUpTimeoutCountOfSlaveState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define CanTSyn_AddRxSequenceCounterOfSlaveState(Index, Value, partitionIndex)                      CanTSyn_SetRxSequenceCounterOfSlaveState(Index, (CanTSyn_GetRxSequenceCounterOfSlaveState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define CanTSyn_AddStateOfSlaveState(Index, Value, partitionIndex)                                  CanTSyn_SetStateOfSlaveState(Index, (CanTSyn_GetStateOfSlaveState(((Index)), (partitionIndex)) + Value), partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCSubstractDataMacros  CanTSyn Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define CanTSyn_SubRxFollowUpTimeoutCountOfSlaveState(Index, Value, partitionIndex)                 CanTSyn_SetRxFollowUpTimeoutCountOfSlaveState(Index, (CanTSyn_GetRxFollowUpTimeoutCountOfSlaveState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define CanTSyn_SubRxSequenceCounterOfSlaveState(Index, Value, partitionIndex)                      CanTSyn_SetRxSequenceCounterOfSlaveState(Index, (CanTSyn_GetRxSequenceCounterOfSlaveState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define CanTSyn_SubStateOfSlaveState(Index, Value, partitionIndex)                                  CanTSyn_SetStateOfSlaveState(Index, (CanTSyn_GetStateOfSlaveState(((Index)), (partitionIndex)) - Value), partitionIndex)
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


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint8 CanTSyn_CanMsgType[CANTSYN_TIME_SYNC_MAX_MESSAGE_DLC];
typedef uint8 CanTSyn_CanStdMsgType[CANTSYN_TIME_SYNC_MESSAGE_DLC];

/* CANTSYN State-Machine State Definitions */
typedef uint8 CanTSyn_StateMachineStateType;
# define CANTSYN_STATE_RECEIVE_WAITING_FOR_SYNC                    (0u)
# define CANTSYN_STATE_RECEIVE_WAITING_FOR_FOLLOW_UP               (1u)

# define CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND                  (0u)
# define CANTSYN_STATE_SEND_WAITING_FOR_SYNC_TX_CONFIRMATION       (1u)
# define CANTSYN_STATE_SEND_WAITING_FOR_FOLLOW_UP_SEND             (2u)
# define CANTSYN_STATE_SEND_WAITING_FOR_FOLLOW_UP_TX_CONFIRMATION  (3u)

# define CANTSYN_STATE_SEND_WAITING_FOR_SEND                       (4u)
# define CANTSYN_STATE_SEND_WAITING_FOR_TX_CONFIRMATION            (5u) 


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  CanTSynPCSizeOfTypes  CanTSyn SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for CanTSyn_SizeOfDomainConfig */
typedef uint8 CanTSyn_SizeOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_SizeOfFupDataIDList */
typedef uint8 CanTSyn_SizeOfFupDataIDListType;

/**   \brief  value based type definition for CanTSyn_SizeOfPartitionIdentifiers */
typedef uint8 CanTSyn_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for CanTSyn_SizeOfSlaveConfig */
typedef uint8 CanTSyn_SizeOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_SizeOfSlaveState */
typedef uint8 CanTSyn_SizeOfSlaveStateType;

/**   \brief  value based type definition for CanTSyn_SizeOfSyncDataIDList */
typedef uint8 CanTSyn_SizeOfSyncDataIDListType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanTSynPCIterableTypes  CanTSyn Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CanTSyn_DomainConfig */
typedef uint8_least CanTSyn_DomainConfigIterType;

/**   \brief  type used to iterate CanTSyn_FupDataIDList */
typedef uint8_least CanTSyn_FupDataIDListIterType;

/**   \brief  type used to iterate CanTSyn_PartitionIdentifiers */
typedef uint8_least CanTSyn_PartitionIdentifiersIterType;

/**   \brief  type used to iterate CanTSyn_SlaveConfig */
typedef uint8_least CanTSyn_SlaveConfigIterType;

/**   \brief  type used to iterate CanTSyn_SyncDataIDList */
typedef uint8_least CanTSyn_SyncDataIDListIterType;

/**   \brief  type used to iterate CanTSyn_PCPartitionConfig */
typedef uint8_least CanTSyn_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCIterableTypesWithSizeRelations  CanTSyn Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate CanTSyn_SlaveState */
typedef CanTSyn_SlaveConfigIterType CanTSyn_SlaveStateIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCValueTypes  CanTSyn Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CanTSyn_CrcAndDomainTypeOfDomainConfig */
typedef uint8 CanTSyn_CrcAndDomainTypeOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_DomainIdOfDomainConfig */
typedef uint8 CanTSyn_DomainIdOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_FupDataIDListEndIdxOfDomainConfig */
typedef uint8 CanTSyn_FupDataIDListEndIdxOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_FupDataIDListStartIdxOfDomainConfig */
typedef uint8 CanTSyn_FupDataIDListStartIdxOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_FupDataIDListUsedOfDomainConfig */
typedef boolean CanTSyn_FupDataIDListUsedOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_MessageDlcOfDomainConfig */
typedef uint8 CanTSyn_MessageDlcOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_OffsetDomainOfDomainConfig */
typedef uint8 CanTSyn_OffsetDomainOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_SlaveConfigIdxOfDomainConfig */
typedef uint8 CanTSyn_SlaveConfigIdxOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_SlaveConfigUsedOfDomainConfig */
typedef boolean CanTSyn_SlaveConfigUsedOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_SyncDataIDListEndIdxOfDomainConfig */
typedef uint8 CanTSyn_SyncDataIDListEndIdxOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_SyncDataIDListStartIdxOfDomainConfig */
typedef uint8 CanTSyn_SyncDataIDListStartIdxOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_SyncDataIDListUsedOfDomainConfig */
typedef boolean CanTSyn_SyncDataIDListUsedOfDomainConfigType;

/**   \brief  value based type definition for CanTSyn_FupDataIDList */
typedef uint8 CanTSyn_FupDataIDListType;

/**   \brief  value based type definition for CanTSyn_Initialized */
typedef boolean CanTSyn_InitializedType;

/**   \brief  value based type definition for CanTSyn_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 CanTSyn_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for CanTSyn_PartitionSNVOfPartitionIdentifiers */
typedef uint32 CanTSyn_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for CanTSyn_DomainConfigIdxOfSlaveConfig */
typedef uint8 CanTSyn_DomainConfigIdxOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_FollowUpTimeoutOfSlaveConfig */
typedef uint8 CanTSyn_FollowUpTimeoutOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_PartitionConfigIdxOfSlaveConfig */
typedef uint8 CanTSyn_PartitionConfigIdxOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_RxCrcValidatedOfSlaveConfig */
typedef uint8 CanTSyn_RxCrcValidatedOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_SequenceCounterJumpWidthOfSlaveConfig */
typedef uint8 CanTSyn_SequenceCounterJumpWidthOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_SlaveHandleIdOfSlaveConfig */
typedef uint8 CanTSyn_SlaveHandleIdOfSlaveConfigType;

/**   \brief  value based type definition for CanTSyn_RxFollowUpTimeoutCountOfSlaveState */
typedef uint32 CanTSyn_RxFollowUpTimeoutCountOfSlaveStateType;

/**   \brief  value based type definition for CanTSyn_RxSequenceCounterOfSlaveState */
typedef uint8 CanTSyn_RxSequenceCounterOfSlaveStateType;

/**   \brief  value based type definition for CanTSyn_SyncDataIDList */
typedef uint8 CanTSyn_SyncDataIDListType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanTSynPCStructTypes  CanTSyn Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CanTSyn_DomainConfig */
typedef struct sCanTSyn_DomainConfigType
{
  CanTSyn_CrcAndDomainTypeOfDomainConfigType CrcAndDomainTypeOfDomainConfig;  /**< Sets the domain to crc supported if it contains a master that supports txCrc. */
  CanTSyn_DomainIdOfDomainConfigType DomainIdOfDomainConfig;  /**< Domain Id */
  CanTSyn_FupDataIDListEndIdxOfDomainConfigType FupDataIDListEndIdxOfDomainConfig;  /**< the end index of the 0:n relation pointing to CanTSyn_FupDataIDList */
  CanTSyn_FupDataIDListStartIdxOfDomainConfigType FupDataIDListStartIdxOfDomainConfig;  /**< the start index of the 0:n relation pointing to CanTSyn_FupDataIDList */
  CanTSyn_MessageDlcOfDomainConfigType MessageDlcOfDomainConfig;  /**< Indicates if the Extended Message Format for CAN-FD is used. */
  CanTSyn_OffsetDomainOfDomainConfigType OffsetDomainOfDomainConfig;  /**< Sets the domain to supported is domain transmits offset message. */
  CanTSyn_SlaveConfigIdxOfDomainConfigType SlaveConfigIdxOfDomainConfig;  /**< the index of the 0:1 relation pointing to CanTSyn_SlaveConfig */
  CanTSyn_SyncDataIDListEndIdxOfDomainConfigType SyncDataIDListEndIdxOfDomainConfig;  /**< the end index of the 0:n relation pointing to CanTSyn_SyncDataIDList */
  CanTSyn_SyncDataIDListStartIdxOfDomainConfigType SyncDataIDListStartIdxOfDomainConfig;  /**< the start index of the 0:n relation pointing to CanTSyn_SyncDataIDList */
  StbM_SynchronizedTimeBaseType TimeBaseIdOfDomainConfig;  /**< Mandatory reference to the required synchronized time-base. */
} CanTSyn_DomainConfigType;

/**   \brief  type used in CanTSyn_PartitionIdentifiers */
typedef struct sCanTSyn_PartitionIdentifiersType
{
  CanTSyn_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
  CanTSyn_PCPartitionConfigIdxOfPartitionIdentifiersType PCPartitionConfigIdxOfPartitionIdentifiers;  /**< the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig */
} CanTSyn_PartitionIdentifiersType;

/**   \brief  type used in CanTSyn_SlaveConfig */
typedef struct sCanTSyn_SlaveConfigType
{
  CanTSyn_DomainConfigIdxOfSlaveConfigType DomainConfigIdxOfSlaveConfig;  /**< the index of the 1:1 relation pointing to CanTSyn_DomainConfig */
  CanTSyn_FollowUpTimeoutOfSlaveConfigType FollowUpTimeoutOfSlaveConfig;  /**< Rx timeout for the follow-up message. This is only relevant for selected bus systems. */
  CanTSyn_PartitionConfigIdxOfSlaveConfigType PartitionConfigIdxOfSlaveConfig;  /**< the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig */
  CanTSyn_RxCrcValidatedOfSlaveConfigType RxCrcValidatedOfSlaveConfig;  /**< Validation of the CRC is supported or not */
  CanTSyn_SequenceCounterJumpWidthOfSlaveConfigType SequenceCounterJumpWidthOfSlaveConfig;  /**< The SequenceCounterJumpWidth specifies the maximum allowed gap of the sequence counter between two SYNC resp. two OFS messages. */
  CanTSyn_SlaveHandleIdOfSlaveConfigType SlaveHandleIdOfSlaveConfig;  /**< This represents the handle ID of the PDU that contains the global time information. */
} CanTSyn_SlaveConfigType;

/**   \brief  type used in CanTSyn_SlaveState */
typedef struct sCanTSyn_SlaveStateType
{
  CanTSyn_RxFollowUpTimeoutCountOfSlaveStateType RxFollowUpTimeoutCountOfSlaveState;  /**< Count of number of Rx timeouts for follow-up messages. */
  CanTSyn_RxSequenceCounterOfSlaveStateType RxSequenceCounterOfSlaveState;  /**< Sequence counter for Rx messages. */
  CanTSyn_StateMachineStateType StateOfSlaveState;  /**< State of the slave */
  CanTSyn_CanStdMsgType SyncMsgOfSlaveState;  /**< This represents the synchronized message type. */
  StbM_VirtualLocalTimeType VirtualLocalTimeOfSlaveState;  /**< This represents Virtual Local Time value from StbM. */
} CanTSyn_SlaveStateType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCSymbolicStructTypes  CanTSyn Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to CanTSyn_SlaveState in the partition context  */
typedef struct CanTSyn_SlaveStateStructSTag
{
  CanTSyn_SlaveStateType GTD_BODY3_0_14e64f11;
} CanTSyn_SlaveStateStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCUnionIndexAndSymbolTypes  CanTSyn Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access CanTSyn_SlaveState in an index and symbol based style. */
typedef union CanTSyn_SlaveStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanTSyn_SlaveStateType raw[1];
  CanTSyn_SlaveStateStructSType str;
} CanTSyn_SlaveStateUType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCRootPointerTypes  CanTSyn Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to CanTSyn_DomainConfig */
typedef P2CONST(CanTSyn_DomainConfigType, TYPEDEF, CANTSYN_CONST) CanTSyn_DomainConfigPtrType;

/**   \brief  type used to point to CanTSyn_FupDataIDList */
typedef P2CONST(CanTSyn_FupDataIDListType, TYPEDEF, CANTSYN_CONST) CanTSyn_FupDataIDListPtrType;

/**   \brief  type used to point to CanTSyn_Initialized */
typedef P2VAR(CanTSyn_InitializedType, TYPEDEF, CANTSYN_VAR_CLEARED) CanTSyn_InitializedPtrType;

/**   \brief  type used to point to CanTSyn_PartitionIdentifiers */
typedef P2CONST(CanTSyn_PartitionIdentifiersType, TYPEDEF, CANTSYN_CONST) CanTSyn_PartitionIdentifiersPtrType;

/**   \brief  type used to point to CanTSyn_SlaveConfig */
typedef P2CONST(CanTSyn_SlaveConfigType, TYPEDEF, CANTSYN_CONST) CanTSyn_SlaveConfigPtrType;

/**   \brief  type used to point to CanTSyn_SlaveState */
typedef P2VAR(CanTSyn_SlaveStateType, TYPEDEF, CANTSYN_VAR_NO_INIT) CanTSyn_SlaveStatePtrType;

/**   \brief  type used to point to CanTSyn_SyncMsgOfSlaveState */
typedef P2VAR(CanTSyn_CanStdMsgType, TYPEDEF, CANTSYN_VAR_NO_INIT) CanTSyn_SyncMsgOfSlaveStatePtrType;

/**   \brief  type used to point to CanTSyn_SyncDataIDList */
typedef P2CONST(CanTSyn_SyncDataIDListType, TYPEDEF, CANTSYN_CONST) CanTSyn_SyncDataIDListPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCPartitionRootPointer  CanTSyn Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in CanTSyn_PCPartitionConfig */
typedef struct sCanTSyn_PCPartitionConfigType
{
  uint8 CanTSyn_PCPartitionConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} CanTSyn_PCPartitionConfigType;

/**   \brief  type used to point to CanTSyn_PCPartitionConfig */
typedef P2CONST(CanTSyn_PCPartitionConfigType, TYPEDEF, CANTSYN_CONST) CanTSyn_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTSynPCRootValueTypes  CanTSyn Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CanTSyn_PCConfig */
typedef struct sCanTSyn_PCConfigType
{
  uint8 CanTSyn_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} CanTSyn_PCConfigType;

typedef CanTSyn_PCConfigType CanTSyn_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define CANTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTSyn_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

extern VAR(boolean, CANTSYN_VAR_NO_INIT) CanTSyn_PreInitialized;

#define CANTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTSyn_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanTSyn_DomainConfig
**********************************************************************************************************************/
/** 
  \var    CanTSyn_DomainConfig
  \brief  Table containing data about the time domain.
  \details
  Element                   Description
  CrcAndDomainType          Sets the domain to crc supported if it contains a master that supports txCrc.
  DomainId                  Domain Id
  FupDataIDListEndIdx       the end index of the 0:n relation pointing to CanTSyn_FupDataIDList
  FupDataIDListStartIdx     the start index of the 0:n relation pointing to CanTSyn_FupDataIDList
  MessageDlc                Indicates if the Extended Message Format for CAN-FD is used.
  OffsetDomain              Sets the domain to supported is domain transmits offset message.
  SlaveConfigIdx            the index of the 0:1 relation pointing to CanTSyn_SlaveConfig
  SyncDataIDListEndIdx      the end index of the 0:n relation pointing to CanTSyn_SyncDataIDList
  SyncDataIDListStartIdx    the start index of the 0:n relation pointing to CanTSyn_SyncDataIDList
  TimeBaseId                Mandatory reference to the required synchronized time-base.
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_DomainConfigType, CANTSYN_CONST) CanTSyn_DomainConfig[1];
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_FupDataIDList
**********************************************************************************************************************/
/** 
  \var    CanTSyn_FupDataIDList
  \brief  Element of the DataIDList for FUP/OFNS messages ensures the identification of data elements due to CRC calculation process.
*/ 
#define CANTSYN_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_FupDataIDListType, CANTSYN_CONST) CanTSyn_FupDataIDList[16];
#define CANTSYN_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    CanTSyn_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_PartitionIdentifiersType, CANTSYN_CONST) CanTSyn_PartitionIdentifiers[1];
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_SlaveConfig
**********************************************************************************************************************/
/** 
  \var    CanTSyn_SlaveConfig
  \brief  Contains configuration parameters of slave.
  \details
  Element                     Description
  DomainConfigIdx             the index of the 1:1 relation pointing to CanTSyn_DomainConfig
  FollowUpTimeout             Rx timeout for the follow-up message. This is only relevant for selected bus systems.
  PartitionConfigIdx          the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig
  RxCrcValidated              Validation of the CRC is supported or not
  SequenceCounterJumpWidth    The SequenceCounterJumpWidth specifies the maximum allowed gap of the sequence counter between two SYNC resp. two OFS messages.
  SlaveHandleId               This represents the handle ID of the PDU that contains the global time information.
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_SlaveConfigType, CANTSYN_CONST) CanTSyn_SlaveConfig[1];
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_SyncDataIDList
**********************************************************************************************************************/
/** 
  \var    CanTSyn_SyncDataIDList
  \brief  Element of the DataIDList for SYNC/OFS messages ensures the identification of data elements due to CRC calculation process.
*/ 
#define CANTSYN_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTSyn_SyncDataIDListType, CANTSYN_CONST) CanTSyn_SyncDataIDList[16];
#define CANTSYN_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_Initialized
**********************************************************************************************************************/
/** 
  \var    CanTSyn_Initialized
  \brief  Initialization state of the CanTSyn. TRUE, if CanTSyn_Init() has been called, else FALSE.
*/ 
#define CANTSYN_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTSyn_InitializedType, CANTSYN_VAR_CLEARED) CanTSyn_Initialized;
#define CANTSYN_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_SlaveState
**********************************************************************************************************************/
/** 
  \var    CanTSyn_SlaveState
  \details
  Element                   Description
  RxFollowUpTimeoutCount    Count of number of Rx timeouts for follow-up messages.
  RxSequenceCounter         Sequence counter for Rx messages.
  State                     State of the slave
  SyncMsg                   This represents the synchronized message type.
  VirtualLocalTime          This represents Virtual Local Time value from StbM.
*/ 
#define CANTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTSyn_SlaveStateUType, CANTSYN_VAR_NO_INIT) CanTSyn_SlaveState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */




/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



#endif  /* CANTSYN_CFG_H */
/**********************************************************************************************************************
 *  END OF FILE: CanTSyn_Cfg.h
 *********************************************************************************************************************/
