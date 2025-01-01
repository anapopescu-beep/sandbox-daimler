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
 *            Module: FblCw
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FblCw_Lcfg.h
 *   Generation Time: 2023-07-05 16:23:58
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (FBLCW_LCFG_H)
# define FBLCW_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "ComStack_Types.h"
/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  FblCwPCDataSwitches  FblCw Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define FBLCW_BUSNMRXINDCYCLEMS                                                                     STD_ON
#define FBLCW_BUSNMRXINDDATA                                                                        STD_OFF  /**< Deactivateable: 'FblCw_BusNmRxIndData' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'FblCw_BusNmRxIndData' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define FBLCW_BUSNMRXINDFCTPTROFBUSNMRXINDDATA                                                      STD_OFF  /**< Deactivateable: 'FblCw_BusNmRxIndData.BusNmRxIndFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'FblCw_BusNmRxIndData.BusNmRxIndFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FBLCW_PDUINFOOFBUSNMRXINDDATA                                                               STD_OFF  /**< Deactivateable: 'FblCw_BusNmRxIndData.PduInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'FblCw_BusNmRxIndData.PduInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FBLCW_SDULENGTHOFBUSNMRXINDDATA                                                             STD_OFF  /**< Deactivateable: 'FblCw_BusNmRxIndData.SduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'FblCw_BusNmRxIndData.SduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FBLCW_CANIFCTRLINFO                                                                         STD_ON
#define FBLCW_COMMETHCHANNELINFO                                                                    STD_OFF  /**< Deactivateable: 'FblCw_ComMEthChannelInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'FblCw_ComMEthChannelInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FBLCW_COMMFRCHANNELINFO                                                                     STD_OFF  /**< Deactivateable: 'FblCw_ComMFrChannelInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'FblCw_ComMFrChannelInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FBLCW_COMMFRNMCHANNELINFO                                                                   STD_OFF  /**< Deactivateable: 'FblCw_ComMFrNmChannelInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'FblCw_ComMFrNmChannelInfo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FBLCW_CWDCMCOMMCHANNELMAPPING                                                               STD_ON
#define FBLCW_DCMDSLBROADCASTGROUPINFO                                                              STD_OFF  /**< Deactivateable: 'FblCw_DcmDslBroadcastGroupInfo' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'FblCw_DcmDslBroadcastGroupInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define FBLCW_SNVOFDCMDSLBROADCASTGROUPINFO                                                         STD_OFF  /**< Deactivateable: 'FblCw_DcmDslBroadcastGroupInfo.Snv' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'FblCw_DcmDslBroadcastGroupInfo.Snv' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FBLCW_DCMDSLBROADCASTGROUPINFOIND                                                           STD_OFF  /**< Deactivateable: 'FblCw_DcmDslBroadcastGroupInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'FblCw_DcmDslBroadcastGroupInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FBLCW_DCMDSLCONNECTIONGROUPINFO                                                             STD_OFF  /**< Deactivateable: 'FblCw_DcmDslConnectionGroupInfo' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'FblCw_DcmDslConnectionGroupInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define FBLCW_SNVOFDCMDSLCONNECTIONGROUPINFO                                                        STD_OFF  /**< Deactivateable: 'FblCw_DcmDslConnectionGroupInfo.Snv' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'FblCw_DcmDslConnectionGroupInfo.Snv' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FBLCW_DCMDSLCONNECTIONGROUPINFOIND                                                          STD_OFF  /**< Deactivateable: 'FblCw_DcmDslConnectionGroupInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'FblCw_DcmDslConnectionGroupInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FBLCW_DCMDSLCONNECTIONINFO                                                                  STD_ON
#define FBLCW_BUSTYPEOFDCMDSLCONNECTIONINFO                                                         STD_ON
#define FBLCW_CONTROLLEROFDCMDSLCONNECTIONINFO                                                      STD_ON
#define FBLCW_DCMDSLBROADCASTGROUPINFOIDXOFDCMDSLCONNECTIONINFO                                     STD_OFF  /**< Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FL.DcmDslBroadcastGroupInfoIdx' Reason: 'the optional indirection is deactivated because DcmDslBroadcastGroupInfoUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FR.DcmDslBroadcastGroupInfoIdx' Reason: 'the optional indirection is deactivated because DcmDslBroadcastGroupInfoUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define FBLCW_DCMDSLBROADCASTGROUPINFOINDENDIDXOFDCMDSLCONNECTIONINFO                               STD_OFF  /**< Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FL.DcmDslBroadcastGroupInfoIndEndIdx' Reason: 'the optional indirection is deactivated because DcmDslBroadcastGroupInfoIndUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FR.DcmDslBroadcastGroupInfoIndEndIdx' Reason: 'the optional indirection is deactivated because DcmDslBroadcastGroupInfoIndUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define FBLCW_DCMDSLBROADCASTGROUPINFOINDSTARTIDXOFDCMDSLCONNECTIONINFO                             STD_OFF  /**< Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FL.DcmDslBroadcastGroupInfoIndStartIdx' Reason: 'the optional indirection is deactivated because DcmDslBroadcastGroupInfoIndUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FR.DcmDslBroadcastGroupInfoIndStartIdx' Reason: 'the optional indirection is deactivated because DcmDslBroadcastGroupInfoIndUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define FBLCW_DCMDSLBROADCASTGROUPINFOINDUSEDOFDCMDSLCONNECTIONINFO                                 STD_OFF  /**< Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FL.DcmDslBroadcastGroupInfoIndUsed' Reason: 'the optional indirection is deactivated because DcmDslBroadcastGroupInfoIndUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FR.DcmDslBroadcastGroupInfoIndUsed' Reason: 'the optional indirection is deactivated because DcmDslBroadcastGroupInfoIndUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define FBLCW_DCMDSLBROADCASTGROUPINFOUSEDOFDCMDSLCONNECTIONINFO                                    STD_OFF  /**< Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FL.DcmDslBroadcastGroupInfoUsed' Reason: 'the optional indirection is deactivated because DcmDslBroadcastGroupInfoUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FR.DcmDslBroadcastGroupInfoUsed' Reason: 'the optional indirection is deactivated because DcmDslBroadcastGroupInfoUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define FBLCW_DCMDSLCONNECTIONGROUPINFOINDENDIDXOFDCMDSLCONNECTIONINFO                              STD_OFF  /**< Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FL.DcmDslConnectionGroupInfoIndEndIdx' Reason: 'the optional indirection is deactivated because DcmDslConnectionGroupInfoIndUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FR.DcmDslConnectionGroupInfoIndEndIdx' Reason: 'the optional indirection is deactivated because DcmDslConnectionGroupInfoIndUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define FBLCW_DCMDSLCONNECTIONGROUPINFOINDSTARTIDXOFDCMDSLCONNECTIONINFO                            STD_OFF  /**< Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FL.DcmDslConnectionGroupInfoIndStartIdx' Reason: 'the optional indirection is deactivated because DcmDslConnectionGroupInfoIndUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FR.DcmDslConnectionGroupInfoIndStartIdx' Reason: 'the optional indirection is deactivated because DcmDslConnectionGroupInfoIndUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define FBLCW_DCMDSLCONNECTIONGROUPINFOINDUSEDOFDCMDSLCONNECTIONINFO                                STD_OFF  /**< Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FL.DcmDslConnectionGroupInfoIndUsed' Reason: 'the optional indirection is deactivated because DcmDslConnectionGroupInfoIndUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'FblCw_DcmDslConnectionInfoRBTM_FR.DcmDslConnectionGroupInfoIndUsed' Reason: 'the optional indirection is deactivated because DcmDslConnectionGroupInfoIndUsedOfDcmDslConnectionInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define FBLCW_PARAMETERINFOIDXOFDCMDSLCONNECTIONINFO                                                STD_ON
#define FBLCW_PARAMETERINFOUSEDOFDCMDSLCONNECTIONINFO                                               STD_ON
#define FBLCW_PAYLOADLIMITOFDCMDSLCONNECTIONINFO                                                    STD_ON
#define FBLCW_RXTESTERSOURCEADDRESSOFDCMDSLCONNECTIONINFO                                           STD_ON
#define FBLCW_TXREMOTEPDUIDOFDCMDSLCONNECTIONINFO                                                   STD_ON
#define FBLCW_DCMDSLPROTOCOLRXINFO                                                                  STD_ON
#define FBLCW_ADDRTYPEOFDCMDSLPROTOCOLRXINFO                                                        STD_ON
#define FBLCW_DCMDSLCONNECTIONINFOIDXOFDCMDSLPROTOCOLRXINFO                                         STD_ON
#define FBLCW_INVALIDHNDOFDCMDSLPROTOCOLRXINFO                                                      STD_OFF  /**< Deactivateable: 'FblCw_DcmDslProtocolRxInfoRBTM_FL.InvalidHnd' Reason: 'the value of FblCw_InvalidHndOfDcmDslProtocolRxInfo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'FblCw_DcmDslProtocolRxInfoRBTM_FR.InvalidHnd' Reason: 'the value of FblCw_InvalidHndOfDcmDslProtocolRxInfo is always 'false' due to this, the array is deactivated.' */
#define FBLCW_DCMDSLPROTOCOLTXINFO                                                                  STD_ON
#define FBLCW_DCMDSLCONNECTIONINFOIDXOFDCMDSLPROTOCOLTXINFO                                         STD_ON
#define FBLCW_INVALIDHNDOFDCMDSLPROTOCOLTXINFO                                                      STD_OFF  /**< Deactivateable: 'FblCw_DcmDslProtocolTxInfoRBTM_FL.InvalidHnd' Reason: 'the value of FblCw_InvalidHndOfDcmDslProtocolTxInfo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'FblCw_DcmDslProtocolTxInfoRBTM_FR.InvalidHnd' Reason: 'the value of FblCw_InvalidHndOfDcmDslProtocolTxInfo is always 'false' due to this, the array is deactivated.' */
#define FBLCW_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'FblCw_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define FBLCW_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'FblCw_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define FBLCW_INITIALBC                                                                             STD_ON
#define FBLCW_INITIALBS                                                                             STD_ON
#define FBLCW_INITIALSTMIN                                                                          STD_ON
#define FBLCW_INITIALIZED                                                                           STD_ON
#define FBLCW_PARAMETERINFO                                                                         STD_ON
#define FBLCW_CANTPIDOFPARAMETERINFO                                                                STD_ON
#define FBLCW_PDURIDOFPARAMETERINFO                                                                 STD_ON
#define FBLCW_SIZEOFCANIFCTRLINFO                                                                   STD_ON
#define FBLCW_SIZEOFCWDCMCOMMCHANNELMAPPING                                                         STD_ON
#define FBLCW_SIZEOFDCMDSLCONNECTIONINFO                                                            STD_ON
#define FBLCW_SIZEOFDCMDSLPROTOCOLRXINFO                                                            STD_ON
#define FBLCW_SIZEOFDCMDSLPROTOCOLTXINFO                                                            STD_ON
#define FBLCW_SIZEOFINITIALBC                                                                       STD_ON
#define FBLCW_SIZEOFINITIALBS                                                                       STD_ON
#define FBLCW_SIZEOFINITIALSTMIN                                                                    STD_ON
#define FBLCW_SIZEOFPARAMETERINFO                                                                   STD_ON
#define FBLCW_VARIANTIDX                                                                            STD_ON
#define FBLCW_PCCONFIG                                                                              STD_ON
#define FBLCW_BUSNMRXINDCYCLEMSOFPCCONFIG                                                           STD_ON
#define FBLCW_CANIFCTRLINFOOFPCCONFIG                                                               STD_ON
#define FBLCW_CWDCMCOMMCHANNELMAPPINGOFPCCONFIG                                                     STD_ON
#define FBLCW_DCMDSLCONNECTIONINFOOFPCCONFIG                                                        STD_ON
#define FBLCW_DCMDSLPROTOCOLRXINFOOFPCCONFIG                                                        STD_ON
#define FBLCW_DCMDSLPROTOCOLTXINFOOFPCCONFIG                                                        STD_ON
#define FBLCW_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'FblCw_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define FBLCW_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'FblCw_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define FBLCW_INITIALBCOFPCCONFIG                                                                   STD_ON
#define FBLCW_INITIALBSOFPCCONFIG                                                                   STD_ON
#define FBLCW_INITIALSTMINOFPCCONFIG                                                                STD_ON
#define FBLCW_INITIALIZEDOFPCCONFIG                                                                 STD_ON
#define FBLCW_PARAMETERINFOOFPCCONFIG                                                               STD_ON
#define FBLCW_SIZEOFCANIFCTRLINFOOFPCCONFIG                                                         STD_ON
#define FBLCW_SIZEOFCWDCMCOMMCHANNELMAPPINGOFPCCONFIG                                               STD_ON
#define FBLCW_SIZEOFDCMDSLCONNECTIONINFOOFPCCONFIG                                                  STD_ON
#define FBLCW_SIZEOFDCMDSLPROTOCOLRXINFOOFPCCONFIG                                                  STD_ON
#define FBLCW_SIZEOFDCMDSLPROTOCOLTXINFOOFPCCONFIG                                                  STD_ON
#define FBLCW_SIZEOFINITIALBCOFPCCONFIG                                                             STD_ON
#define FBLCW_SIZEOFINITIALBSOFPCCONFIG                                                             STD_ON
#define FBLCW_SIZEOFINITIALSTMINOFPCCONFIG                                                          STD_ON
#define FBLCW_SIZEOFPARAMETERINFOOFPCCONFIG                                                         STD_ON
#define FBLCW_VARIANTIDXOFPCCONFIG                                                                  STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCMinNumericValueDefines  FblCw Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define FBLCW_MIN_INITIALBC                                                                         0u
#define FBLCW_MIN_INITIALBS                                                                         0u
#define FBLCW_MIN_INITIALSTMIN                                                                      0u
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCMaxNumericValueDefines  FblCw Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define FBLCW_MAX_INITIALBC                                                                         65535u
#define FBLCW_MAX_INITIALBS                                                                         65535u
#define FBLCW_MAX_INITIALSTMIN                                                                      65535u
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCNoReferenceDefines  FblCw No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define FBLCW_NO_PARAMETERINFOIDXOFDCMDSLCONNECTIONINFO                                             255u
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCEnumExistsDefines  FblCw Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO                                              STD_ON
#define FBLCW_EXISTS_FR_BUSTYPEOFDCMDSLCONNECTIONINFO                                               STD_OFF
#define FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO                                              STD_OFF
#define FBLCW_EXISTS_LIN_BUSTYPEOFDCMDSLCONNECTIONINFO                                              STD_OFF
#define FBLCW_EXISTS_CDD_BUSTYPEOFDCMDSLCONNECTIONINFO                                              STD_OFF
#define FBLCW_EXISTS_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO                                      STD_ON
#define FBLCW_EXISTS_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO                                        STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCEnumDefines  FblCw Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO                                                     0x00u
#define FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO                                             0x00u
#define FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO                                               0x01u
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCIsReducedToDefineDefines  FblCw Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define FBLCW_ISDEF_CANIFCTRLINFO                                                                   STD_OFF
#define FBLCW_ISDEF_CWDCMCOMMCHANNELMAPPING                                                         STD_OFF
#define FBLCW_ISDEF_BUSTYPEOFDCMDSLCONNECTIONINFO                                                   STD_OFF
#define FBLCW_ISDEF_CONTROLLEROFDCMDSLCONNECTIONINFO                                                STD_OFF
#define FBLCW_ISDEF_PARAMETERINFOIDXOFDCMDSLCONNECTIONINFO                                          STD_OFF
#define FBLCW_ISDEF_PARAMETERINFOUSEDOFDCMDSLCONNECTIONINFO                                         STD_OFF
#define FBLCW_ISDEF_PAYLOADLIMITOFDCMDSLCONNECTIONINFO                                              STD_OFF
#define FBLCW_ISDEF_RXTESTERSOURCEADDRESSOFDCMDSLCONNECTIONINFO                                     STD_OFF
#define FBLCW_ISDEF_TXREMOTEPDUIDOFDCMDSLCONNECTIONINFO                                             STD_OFF
#define FBLCW_ISDEF_ADDRTYPEOFDCMDSLPROTOCOLRXINFO                                                  STD_OFF
#define FBLCW_ISDEF_DCMDSLCONNECTIONINFOIDXOFDCMDSLPROTOCOLRXINFO                                   STD_OFF
#define FBLCW_ISDEF_DCMDSLCONNECTIONINFOIDXOFDCMDSLPROTOCOLTXINFO                                   STD_OFF
#define FBLCW_ISDEF_CANTPIDOFPARAMETERINFO                                                          STD_OFF
#define FBLCW_ISDEF_PDURIDOFPARAMETERINFO                                                           STD_OFF
#define FBLCW_ISDEF_CANIFCTRLINFOOFPCCONFIG                                                         STD_ON
#define FBLCW_ISDEF_CWDCMCOMMCHANNELMAPPINGOFPCCONFIG                                               STD_OFF
#define FBLCW_ISDEF_DCMDSLCONNECTIONINFOOFPCCONFIG                                                  STD_OFF
#define FBLCW_ISDEF_DCMDSLPROTOCOLRXINFOOFPCCONFIG                                                  STD_OFF
#define FBLCW_ISDEF_DCMDSLPROTOCOLTXINFOOFPCCONFIG                                                  STD_OFF
#define FBLCW_ISDEF_INITIALBCOFPCCONFIG                                                             STD_ON
#define FBLCW_ISDEF_INITIALBSOFPCCONFIG                                                             STD_ON
#define FBLCW_ISDEF_INITIALSTMINOFPCCONFIG                                                          STD_ON
#define FBLCW_ISDEF_INITIALIZEDOFPCCONFIG                                                           STD_ON
#define FBLCW_ISDEF_PARAMETERINFOOFPCCONFIG                                                         STD_OFF
#define FBLCW_ISDEF_VARIANTIDXOFPCCONFIG                                                            STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCEqualsAlwaysToDefines  FblCw Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define FBLCW_EQ2_CANIFCTRLINFO                                                                     
#define FBLCW_EQ2_CWDCMCOMMCHANNELMAPPING                                                           
#define FBLCW_EQ2_BUSTYPEOFDCMDSLCONNECTIONINFO                                                     
#define FBLCW_EQ2_CONTROLLEROFDCMDSLCONNECTIONINFO                                                  
#define FBLCW_EQ2_PARAMETERINFOIDXOFDCMDSLCONNECTIONINFO                                            
#define FBLCW_EQ2_PARAMETERINFOUSEDOFDCMDSLCONNECTIONINFO                                           
#define FBLCW_EQ2_PAYLOADLIMITOFDCMDSLCONNECTIONINFO                                                
#define FBLCW_EQ2_RXTESTERSOURCEADDRESSOFDCMDSLCONNECTIONINFO                                       
#define FBLCW_EQ2_TXREMOTEPDUIDOFDCMDSLCONNECTIONINFO                                               
#define FBLCW_EQ2_ADDRTYPEOFDCMDSLPROTOCOLRXINFO                                                    
#define FBLCW_EQ2_DCMDSLCONNECTIONINFOIDXOFDCMDSLPROTOCOLRXINFO                                     
#define FBLCW_EQ2_DCMDSLCONNECTIONINFOIDXOFDCMDSLPROTOCOLTXINFO                                     
#define FBLCW_EQ2_CANTPIDOFPARAMETERINFO                                                            
#define FBLCW_EQ2_PDURIDOFPARAMETERINFO                                                             
#define FBLCW_EQ2_CANIFCTRLINFOOFPCCONFIG                                                           FblCw_CanIfCtrlInfo
#define FBLCW_EQ2_CWDCMCOMMCHANNELMAPPINGOFPCCONFIG                                                 
#define FBLCW_EQ2_DCMDSLCONNECTIONINFOOFPCCONFIG                                                    
#define FBLCW_EQ2_DCMDSLPROTOCOLRXINFOOFPCCONFIG                                                    
#define FBLCW_EQ2_DCMDSLPROTOCOLTXINFOOFPCCONFIG                                                    
#define FBLCW_EQ2_INITIALBCOFPCCONFIG                                                               FblCw_InitialBC.raw
#define FBLCW_EQ2_INITIALBSOFPCCONFIG                                                               FblCw_InitialBS.raw
#define FBLCW_EQ2_INITIALSTMINOFPCCONFIG                                                            FblCw_InitialSTmin.raw
#define FBLCW_EQ2_INITIALIZEDOFPCCONFIG                                                             (&(FblCw_Initialized))
#define FBLCW_EQ2_PARAMETERINFOOFPCCONFIG                                                           
#define FBLCW_EQ2_VARIANTIDXOFPCCONFIG                                                              
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCSymbolicInitializationPointers  FblCw Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define FblCw_Config_RBTM_FL_Ptr                                                                    &(FblCw_PCConfig.Config_RBTM_FL)  /**< symbolic identifier which shall be used to initialize 'FblCw' */
#define FblCw_Config_RBTM_FR_Ptr                                                                    &(FblCw_PCConfig.Config_RBTM_FR)  /**< symbolic identifier which shall be used to initialize 'FblCw' */
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCInitializationSymbols  FblCw Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define FblCw_Config_RBTM_FL                                                                        FblCw_PCConfig.Config_RBTM_FL  /**< symbolic identifier which could be used to initialize 'FblCw */
#define FblCw_Config_RBTM_FR                                                                        FblCw_PCConfig.Config_RBTM_FR  /**< symbolic identifier which could be used to initialize 'FblCw */
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCGeneral  FblCw General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define FBLCW_CHECK_INIT_POINTER                                                                    STD_ON  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define FBLCW_FINAL_MAGIC_NUMBER                                                                    0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of FblCw */
#define FBLCW_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'FblCw' is not configured to be postbuild capable. */
#define FBLCW_INIT_DATA                                                                             FBLCW_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define FBLCW_INIT_DATA_HASH_CODE                                                                   1053157586  /**< the precompile constant to validate the initialization structure at initialization time of FblCw with a hashcode. The seed value is '0xFF1Eu' */
#define FBLCW_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define FBLCW_USE_INIT_POINTER                                                                      STD_ON  /**< STD_ON if the init pointer FblCw shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  FblCwLTDataSwitches  FblCw Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define FBLCW_LTCONFIG                                                                              STD_OFF  /**< Deactivateable: 'FblCw_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
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
  \defgroup  FblCwPCGetRootDataMacros  FblCw Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define FblCw_GetCwDcmComMChannelMappingOfPCConfig()                                                FblCw_ConfigDataPtr->CwDcmComMChannelMappingOfPCConfig
#define FblCw_GetDcmDslConnectionInfoOfPCConfig()                                                   FblCw_ConfigDataPtr->DcmDslConnectionInfoOfPCConfig
#define FblCw_GetDcmDslProtocolRxInfoOfPCConfig()                                                   FblCw_ConfigDataPtr->DcmDslProtocolRxInfoOfPCConfig
#define FblCw_GetDcmDslProtocolTxInfoOfPCConfig()                                                   FblCw_ConfigDataPtr->DcmDslProtocolTxInfoOfPCConfig
#define FblCw_GetParameterInfoOfPCConfig()                                                          FblCw_ConfigDataPtr->ParameterInfoOfPCConfig
#define FblCw_GetVariantIdxOfPCConfig()                                                             FblCw_ConfigDataPtr->VariantIdxOfPCConfig
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCGetConstantDuplicatedRootDataMacros  FblCw Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define FblCw_GetBusNmRxIndCycleMsOfPCConfig()                                                      65535u
#define FblCw_GetCanIfCtrlInfoOfPCConfig()                                                          FblCw_CanIfCtrlInfo  /**< the pointer to FblCw_CanIfCtrlInfo */
#define FblCw_GetInitialBCOfPCConfig()                                                              FblCw_InitialBC.raw  /**< the pointer to FblCw_InitialBC */
#define FblCw_GetInitialBSOfPCConfig()                                                              FblCw_InitialBS.raw  /**< the pointer to FblCw_InitialBS */
#define FblCw_GetInitialSTminOfPCConfig()                                                           FblCw_InitialSTmin.raw  /**< the pointer to FblCw_InitialSTmin */
#define FblCw_GetInitializedOfPCConfig()                                                            (&(FblCw_Initialized))  /**< the pointer to FblCw_Initialized */
#define FblCw_GetSizeOfCanIfCtrlInfoOfPCConfig()                                                    1u  /**< the number of accomplishable value elements in FblCw_CanIfCtrlInfo */
#define FblCw_GetSizeOfCwDcmComMChannelMappingOfPCConfig()                                          3u  /**< the number of accomplishable value elements in FblCw_CwDcmComMChannelMapping */
#define FblCw_GetSizeOfDcmDslConnectionInfoOfPCConfig()                                             3u  /**< the number of accomplishable value elements in FblCw_DcmDslConnectionInfo */
#define FblCw_GetSizeOfDcmDslProtocolRxInfoOfPCConfig()                                             6u  /**< the number of accomplishable value elements in FblCw_DcmDslProtocolRxInfo */
#define FblCw_GetSizeOfDcmDslProtocolTxInfoOfPCConfig()                                             3u  /**< the number of accomplishable value elements in FblCw_DcmDslProtocolTxInfo */
#define FblCw_GetSizeOfParameterInfoOfPCConfig()                                                    3u  /**< the number of accomplishable value elements in FblCw_ParameterInfo */
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCGetDuplicatedRootDataMacros  FblCw Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define FblCw_GetSizeOfInitialBCOfPCConfig()                                                        FblCw_GetSizeOfParameterInfoOfPCConfig()  /**< the number of accomplishable value elements in FblCw_InitialBC */
#define FblCw_GetSizeOfInitialBSOfPCConfig()                                                        FblCw_GetSizeOfParameterInfoOfPCConfig()  /**< the number of accomplishable value elements in FblCw_InitialBS */
#define FblCw_GetSizeOfInitialSTminOfPCConfig()                                                     FblCw_GetSizeOfParameterInfoOfPCConfig()  /**< the number of accomplishable value elements in FblCw_InitialSTmin */
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCGetDataMacros  FblCw Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define FblCw_GetCanIfCtrlInfo(Index)                                                               (FblCw_GetCanIfCtrlInfoOfPCConfig()[(Index)])
#define FblCw_GetCwDcmComMChannelMapping(Index)                                                     (FblCw_GetCwDcmComMChannelMappingOfPCConfig()[(Index)])
#define FblCw_GetControllerOfDcmDslConnectionInfo(Index)                                            (FblCw_GetDcmDslConnectionInfoOfPCConfig()[(Index)].ControllerOfDcmDslConnectionInfo)
#define FblCw_GetParameterInfoIdxOfDcmDslConnectionInfo(Index)                                      (FblCw_GetDcmDslConnectionInfoOfPCConfig()[(Index)].ParameterInfoIdxOfDcmDslConnectionInfo)
#define FblCw_GetPayloadLimitOfDcmDslConnectionInfo(Index)                                          (FblCw_GetDcmDslConnectionInfoOfPCConfig()[(Index)].PayloadLimitOfDcmDslConnectionInfo)
#define FblCw_GetRxTesterSourceAddressOfDcmDslConnectionInfo(Index)                                 (FblCw_GetDcmDslConnectionInfoOfPCConfig()[(Index)].RxTesterSourceAddressOfDcmDslConnectionInfo)
#define FblCw_GetTxRemotePduIdOfDcmDslConnectionInfo(Index)                                         (FblCw_GetDcmDslConnectionInfoOfPCConfig()[(Index)].TxRemotePduIdOfDcmDslConnectionInfo)
#define FblCw_GetAddrTypeOfDcmDslProtocolRxInfo(Index)                                              (FblCw_GetDcmDslProtocolRxInfoOfPCConfig()[(Index)].AddrTypeOfDcmDslProtocolRxInfo)
#define FblCw_GetDcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo(Index)                               (FblCw_GetDcmDslProtocolRxInfoOfPCConfig()[(Index)].DcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo)
#define FblCw_GetDcmDslConnectionInfoIdxOfDcmDslProtocolTxInfo(Index)                               (FblCw_GetDcmDslProtocolTxInfoOfPCConfig()[(Index)].DcmDslConnectionInfoIdxOfDcmDslProtocolTxInfo)
#define FblCw_GetInitialBC(Index)                                                                   (FblCw_GetInitialBCOfPCConfig()[(Index)])
#define FblCw_GetInitialBS(Index)                                                                   (FblCw_GetInitialBSOfPCConfig()[(Index)])
#define FblCw_GetInitialSTmin(Index)                                                                (FblCw_GetInitialSTminOfPCConfig()[(Index)])
#define FblCw_IsInitialized()                                                                       (((*(FblCw_GetInitializedOfPCConfig()))) != FALSE)
#define FblCw_GetPduRIdOfParameterInfo(Index)                                                       (FblCw_GetParameterInfoOfPCConfig()[(Index)].PduRIdOfParameterInfo)
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCGetDeduplicatedDataMacros  FblCw Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define FblCw_GetBusNmRxIndCycleMs()                                                                FblCw_GetBusNmRxIndCycleMsOfPCConfig()
#define FblCw_GetBusTypeOfDcmDslConnectionInfo(Index)                                               FblCw_GetControllerOfDcmDslConnectionInfo(Index)  /**< the bustype of the connection */
#define FblCw_IsParameterInfoUsedOfDcmDslConnectionInfo(Index)                                      (((boolean)(FblCw_GetParameterInfoIdxOfDcmDslConnectionInfo(Index) != FBLCW_NO_PARAMETERINFOIDXOFDCMDSLCONNECTIONINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to FblCw_ParameterInfo */
#define FblCw_GetCanTpIdOfParameterInfo(Index)                                                      FblCw_GetPduRIdOfParameterInfo(Index)  /**< CanTp SNVs of DefinitionRef: /MICROSAR/CanTp/CanTpConfig/CanTpChannel/CanTpRxNSdu/CanTpRxNSduId */
#define FblCw_GetSizeOfCanIfCtrlInfo()                                                              FblCw_GetSizeOfCanIfCtrlInfoOfPCConfig()
#define FblCw_GetSizeOfCwDcmComMChannelMapping()                                                    FblCw_GetSizeOfCwDcmComMChannelMappingOfPCConfig()
#define FblCw_GetSizeOfDcmDslConnectionInfo()                                                       FblCw_GetSizeOfDcmDslConnectionInfoOfPCConfig()
#define FblCw_GetSizeOfDcmDslProtocolRxInfo()                                                       FblCw_GetSizeOfDcmDslProtocolRxInfoOfPCConfig()
#define FblCw_GetSizeOfDcmDslProtocolTxInfo()                                                       FblCw_GetSizeOfDcmDslProtocolTxInfoOfPCConfig()
#define FblCw_GetSizeOfInitialBC()                                                                  FblCw_GetSizeOfInitialBCOfPCConfig()
#define FblCw_GetSizeOfInitialBS()                                                                  FblCw_GetSizeOfInitialBSOfPCConfig()
#define FblCw_GetSizeOfInitialSTmin()                                                               FblCw_GetSizeOfInitialSTminOfPCConfig()
#define FblCw_GetSizeOfParameterInfo()                                                              FblCw_GetSizeOfParameterInfoOfPCConfig()
#define FblCw_GetVariantIdx()                                                                       FblCw_GetVariantIdxOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCSetDataMacros  FblCw Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define FblCw_SetInitialBC(Index, Value)                                                            FblCw_GetInitialBCOfPCConfig()[(Index)] = (Value)
#define FblCw_SetInitialBS(Index, Value)                                                            FblCw_GetInitialBSOfPCConfig()[(Index)] = (Value)
#define FblCw_SetInitialSTmin(Index, Value)                                                         FblCw_GetInitialSTminOfPCConfig()[(Index)] = (Value)
#define FblCw_SetInitialized(Value)                                                                 (*(FblCw_GetInitializedOfPCConfig())) = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCGetAddressOfDataMacros  FblCw Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define FblCw_GetAddrInitialBC(Index)                                                               (&FblCw_GetInitialBC(Index))
#define FblCw_GetAddrInitialBS(Index)                                                               (&FblCw_GetInitialBS(Index))
#define FblCw_GetAddrInitialSTmin(Index)                                                            (&FblCw_GetInitialSTmin(Index))
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCHasMacros  FblCw Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define FblCw_HasBusNmRxIndCycleMs()                                                                (TRUE != FALSE)
#define FblCw_HasCanIfCtrlInfo()                                                                    (TRUE != FALSE)
#define FblCw_HasCwDcmComMChannelMapping()                                                          (FblCw_GetCwDcmComMChannelMappingOfPCConfig() != NULL_PTR)
#define FblCw_HasDcmDslConnectionInfo()                                                             (FblCw_GetDcmDslConnectionInfoOfPCConfig() != NULL_PTR)
#define FblCw_HasBusTypeOfDcmDslConnectionInfo()                                                    (TRUE != FALSE)
#define FblCw_HasControllerOfDcmDslConnectionInfo()                                                 (TRUE != FALSE)
#define FblCw_HasParameterInfoIdxOfDcmDslConnectionInfo()                                           (TRUE != FALSE)
#define FblCw_HasParameterInfoUsedOfDcmDslConnectionInfo()                                          (TRUE != FALSE)
#define FblCw_HasPayloadLimitOfDcmDslConnectionInfo()                                               (TRUE != FALSE)
#define FblCw_HasRxTesterSourceAddressOfDcmDslConnectionInfo()                                      (TRUE != FALSE)
#define FblCw_HasTxRemotePduIdOfDcmDslConnectionInfo()                                              (TRUE != FALSE)
#define FblCw_HasDcmDslProtocolRxInfo()                                                             (FblCw_GetDcmDslProtocolRxInfoOfPCConfig() != NULL_PTR)
#define FblCw_HasAddrTypeOfDcmDslProtocolRxInfo()                                                   (TRUE != FALSE)
#define FblCw_HasDcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo()                                    (TRUE != FALSE)
#define FblCw_HasDcmDslProtocolTxInfo()                                                             (FblCw_GetDcmDslProtocolTxInfoOfPCConfig() != NULL_PTR)
#define FblCw_HasDcmDslConnectionInfoIdxOfDcmDslProtocolTxInfo()                                    (TRUE != FALSE)
#define FblCw_HasInitialBC()                                                                        (TRUE != FALSE)
#define FblCw_HasInitialBS()                                                                        (TRUE != FALSE)
#define FblCw_HasInitialSTmin()                                                                     (TRUE != FALSE)
#define FblCw_HasInitialized()                                                                      (TRUE != FALSE)
#define FblCw_HasParameterInfo()                                                                    (FblCw_GetParameterInfoOfPCConfig() != NULL_PTR)
#define FblCw_HasCanTpIdOfParameterInfo()                                                           (TRUE != FALSE)
#define FblCw_HasPduRIdOfParameterInfo()                                                            (TRUE != FALSE)
#define FblCw_HasSizeOfCanIfCtrlInfo()                                                              (TRUE != FALSE)
#define FblCw_HasSizeOfCwDcmComMChannelMapping()                                                    (TRUE != FALSE)
#define FblCw_HasSizeOfDcmDslConnectionInfo()                                                       (TRUE != FALSE)
#define FblCw_HasSizeOfDcmDslProtocolRxInfo()                                                       (TRUE != FALSE)
#define FblCw_HasSizeOfDcmDslProtocolTxInfo()                                                       (TRUE != FALSE)
#define FblCw_HasSizeOfInitialBC()                                                                  (TRUE != FALSE)
#define FblCw_HasSizeOfInitialBS()                                                                  (TRUE != FALSE)
#define FblCw_HasSizeOfInitialSTmin()                                                               (TRUE != FALSE)
#define FblCw_HasSizeOfParameterInfo()                                                              (TRUE != FALSE)
#define FblCw_HasVariantIdx()                                                                       (TRUE != FALSE)
#define FblCw_HasPCConfig()                                                                         (TRUE != FALSE)
#define FblCw_HasBusNmRxIndCycleMsOfPCConfig()                                                      (TRUE != FALSE)
#define FblCw_HasCanIfCtrlInfoOfPCConfig()                                                          (TRUE != FALSE)
#define FblCw_HasCwDcmComMChannelMappingOfPCConfig()                                                (TRUE != FALSE)
#define FblCw_HasDcmDslConnectionInfoOfPCConfig()                                                   (TRUE != FALSE)
#define FblCw_HasDcmDslProtocolRxInfoOfPCConfig()                                                   (TRUE != FALSE)
#define FblCw_HasDcmDslProtocolTxInfoOfPCConfig()                                                   (TRUE != FALSE)
#define FblCw_HasInitialBCOfPCConfig()                                                              (TRUE != FALSE)
#define FblCw_HasInitialBSOfPCConfig()                                                              (TRUE != FALSE)
#define FblCw_HasInitialSTminOfPCConfig()                                                           (TRUE != FALSE)
#define FblCw_HasInitializedOfPCConfig()                                                            (TRUE != FALSE)
#define FblCw_HasParameterInfoOfPCConfig()                                                          (TRUE != FALSE)
#define FblCw_HasSizeOfCanIfCtrlInfoOfPCConfig()                                                    (TRUE != FALSE)
#define FblCw_HasSizeOfCwDcmComMChannelMappingOfPCConfig()                                          (TRUE != FALSE)
#define FblCw_HasSizeOfDcmDslConnectionInfoOfPCConfig()                                             (TRUE != FALSE)
#define FblCw_HasSizeOfDcmDslProtocolRxInfoOfPCConfig()                                             (TRUE != FALSE)
#define FblCw_HasSizeOfDcmDslProtocolTxInfoOfPCConfig()                                             (TRUE != FALSE)
#define FblCw_HasSizeOfInitialBCOfPCConfig()                                                        (TRUE != FALSE)
#define FblCw_HasSizeOfInitialBSOfPCConfig()                                                        (TRUE != FALSE)
#define FblCw_HasSizeOfInitialSTminOfPCConfig()                                                     (TRUE != FALSE)
#define FblCw_HasSizeOfParameterInfoOfPCConfig()                                                    (TRUE != FALSE)
#define FblCw_HasVariantIdxOfPCConfig()                                                             (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCIncrementDataMacros  FblCw Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define FblCw_IncInitialBC(Index)                                                                   FblCw_GetInitialBC(Index)++
#define FblCw_IncInitialBS(Index)                                                                   FblCw_GetInitialBS(Index)++
#define FblCw_IncInitialSTmin(Index)                                                                FblCw_GetInitialSTmin(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCDecrementDataMacros  FblCw Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define FblCw_DecInitialBC(Index)                                                                   FblCw_GetInitialBC(Index)--
#define FblCw_DecInitialBS(Index)                                                                   FblCw_GetInitialBS(Index)--
#define FblCw_DecInitialSTmin(Index)                                                                FblCw_GetInitialSTmin(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCAddDataMacros  FblCw Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define FblCw_AddInitialBC(Index, Value)                                                            FblCw_SetInitialBC(Index, (FblCw_GetInitialBC(Index) + Value))
#define FblCw_AddInitialBS(Index, Value)                                                            FblCw_SetInitialBS(Index, (FblCw_GetInitialBS(Index) + Value))
#define FblCw_AddInitialSTmin(Index, Value)                                                         FblCw_SetInitialSTmin(Index, (FblCw_GetInitialSTmin(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCSubstractDataMacros  FblCw Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define FblCw_SubInitialBC(Index, Value)                                                            FblCw_SetInitialBC(Index, (FblCw_GetInitialBC(Index) - Value))
#define FblCw_SubInitialBS(Index, Value)                                                            FblCw_SetInitialBS(Index, (FblCw_GetInitialBS(Index) - Value))
#define FblCw_SubInitialSTmin(Index, Value)                                                         FblCw_SetInitialSTmin(Index, (FblCw_GetInitialSTmin(Index) - Value))
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

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/** 
  \defgroup  FblCw_GetSizeOfBusNmRxIndDataMacro  FblCw Get Size of BusNmRx Macro (PRE_COMPILE)
  \brief  This macro is the size information used to initialize pduBuff in FblCwInternalMainFunctionTimerTask.
  \{
*/ 
#define FblCw_GetSizeOfPduBuff()                                                                    0u

/**********************************************************************************************************************
  GLOBAL FUNCTION POINTERS
**********************************************************************************************************************/
/** 
  \var    FblCw_BusNmRxIndFctPtrType
  \brief  Function pointer to FblCw_BusNmRxIndFctPtrType
*/
#if (FBLCW_BUSNMRXINDDATA == STD_ON)
/* This is the function pointer type */
typedef void (*FblCw_BusNmRxIndFctPtrType)( PduIdType RxPduId, const PduInfoType * PduInfoPtr );
#endif

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  FblCwPCIterableTypes  FblCw Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate FblCw_CanIfCtrlInfo */
typedef uint8_least FblCw_CanIfCtrlInfoIterType;

/**   \brief  type used to iterate FblCw_CwDcmComMChannelMapping */
typedef uint8_least FblCw_CwDcmComMChannelMappingIterType;

/**   \brief  type used to iterate FblCw_DcmDslConnectionInfo */
typedef uint8_least FblCw_DcmDslConnectionInfoIterType;

/**   \brief  type used to iterate FblCw_DcmDslProtocolRxInfo */
typedef uint8_least FblCw_DcmDslProtocolRxInfoIterType;

/**   \brief  type used to iterate FblCw_DcmDslProtocolTxInfo */
typedef uint8_least FblCw_DcmDslProtocolTxInfoIterType;

/**   \brief  type used to iterate FblCw_ParameterInfo */
typedef uint8_least FblCw_ParameterInfoIterType;

/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCIterableTypesWithSizeRelations  FblCw Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate FblCw_InitialBC */
typedef FblCw_ParameterInfoIterType FblCw_InitialBCIterType;

/**   \brief  type used to iterate FblCw_InitialBS */
typedef FblCw_ParameterInfoIterType FblCw_InitialBSIterType;

/**   \brief  type used to iterate FblCw_InitialSTmin */
typedef FblCw_ParameterInfoIterType FblCw_InitialSTminIterType;

/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCValueTypes  FblCw Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for FblCw_BusNmRxIndCycleMs */
typedef uint16 FblCw_BusNmRxIndCycleMsType;

/**   \brief  value based type definition for FblCw_CanIfCtrlInfo */
typedef uint8 FblCw_CanIfCtrlInfoType;

/**   \brief  value based type definition for FblCw_CwDcmComMChannelMapping */
typedef uint8 FblCw_CwDcmComMChannelMappingType;

/**   \brief  value based type definition for FblCw_BusTypeOfDcmDslConnectionInfo */
typedef uint8 FblCw_BusTypeOfDcmDslConnectionInfoType;

/**   \brief  value based type definition for FblCw_ControllerOfDcmDslConnectionInfo */
typedef uint8 FblCw_ControllerOfDcmDslConnectionInfoType;

/**   \brief  value based type definition for FblCw_ParameterInfoIdxOfDcmDslConnectionInfo */
typedef uint8 FblCw_ParameterInfoIdxOfDcmDslConnectionInfoType;

/**   \brief  value based type definition for FblCw_ParameterInfoUsedOfDcmDslConnectionInfo */
typedef boolean FblCw_ParameterInfoUsedOfDcmDslConnectionInfoType;

/**   \brief  value based type definition for FblCw_PayloadLimitOfDcmDslConnectionInfo */
typedef uint16 FblCw_PayloadLimitOfDcmDslConnectionInfoType;

/**   \brief  value based type definition for FblCw_RxTesterSourceAddressOfDcmDslConnectionInfo */
typedef uint16 FblCw_RxTesterSourceAddressOfDcmDslConnectionInfoType;

/**   \brief  value based type definition for FblCw_TxRemotePduIdOfDcmDslConnectionInfo */
typedef uint8 FblCw_TxRemotePduIdOfDcmDslConnectionInfoType;

/**   \brief  value based type definition for FblCw_AddrTypeOfDcmDslProtocolRxInfo */
typedef uint8 FblCw_AddrTypeOfDcmDslProtocolRxInfoType;

/**   \brief  value based type definition for FblCw_DcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo */
typedef uint8 FblCw_DcmDslConnectionInfoIdxOfDcmDslProtocolRxInfoType;

/**   \brief  value based type definition for FblCw_DcmDslConnectionInfoIdxOfDcmDslProtocolTxInfo */
typedef uint8 FblCw_DcmDslConnectionInfoIdxOfDcmDslProtocolTxInfoType;

/**   \brief  value based type definition for FblCw_InitialBC */
typedef uint16 FblCw_InitialBCType;

/**   \brief  value based type definition for FblCw_InitialBS */
typedef uint16 FblCw_InitialBSType;

/**   \brief  value based type definition for FblCw_InitialSTmin */
typedef uint16 FblCw_InitialSTminType;

/**   \brief  value based type definition for FblCw_Initialized */
typedef boolean FblCw_InitializedType;

/**   \brief  value based type definition for FblCw_CanTpIdOfParameterInfo */
typedef uint8 FblCw_CanTpIdOfParameterInfoType;

/**   \brief  value based type definition for FblCw_PduRIdOfParameterInfo */
typedef uint8 FblCw_PduRIdOfParameterInfoType;

/**   \brief  value based type definition for FblCw_SizeOfCanIfCtrlInfo */
typedef uint8 FblCw_SizeOfCanIfCtrlInfoType;

/**   \brief  value based type definition for FblCw_SizeOfCwDcmComMChannelMapping */
typedef uint8 FblCw_SizeOfCwDcmComMChannelMappingType;

/**   \brief  value based type definition for FblCw_SizeOfDcmDslConnectionInfo */
typedef uint8 FblCw_SizeOfDcmDslConnectionInfoType;

/**   \brief  value based type definition for FblCw_SizeOfDcmDslProtocolRxInfo */
typedef uint8 FblCw_SizeOfDcmDslProtocolRxInfoType;

/**   \brief  value based type definition for FblCw_SizeOfDcmDslProtocolTxInfo */
typedef uint8 FblCw_SizeOfDcmDslProtocolTxInfoType;

/**   \brief  value based type definition for FblCw_SizeOfInitialBC */
typedef uint8 FblCw_SizeOfInitialBCType;

/**   \brief  value based type definition for FblCw_SizeOfInitialBS */
typedef uint8 FblCw_SizeOfInitialBSType;

/**   \brief  value based type definition for FblCw_SizeOfInitialSTmin */
typedef uint8 FblCw_SizeOfInitialSTminType;

/**   \brief  value based type definition for FblCw_SizeOfParameterInfo */
typedef uint8 FblCw_SizeOfParameterInfoType;

/**   \brief  value based type definition for FblCw_VariantIdx */
typedef uint8 FblCw_VariantIdxType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  FblCwPCStructTypes  FblCw Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in FblCw_DcmDslConnectionInfo */
/*! \spec weak type invariant () { 
 * (!((self.ParameterInfoIdxOfDcmDslConnectionInfo != FBLCW_NO_PARAMETERINFOIDXOFDCMDSLCONNECTIONINFO)) || (self.ParameterInfoIdxOfDcmDslConnectionInfo < FblCw_GetSizeOfParameterInfo()))
 * } */
typedef struct sFblCw_DcmDslConnectionInfoType
{
  FblCw_PayloadLimitOfDcmDslConnectionInfoType PayloadLimitOfDcmDslConnectionInfo;  /**< DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslPayloadLimit */
  FblCw_RxTesterSourceAddressOfDcmDslConnectionInfoType RxTesterSourceAddressOfDcmDslConnectionInfo;  /**< DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRxTesterSourceAddr */
  FblCw_ControllerOfDcmDslConnectionInfoType ControllerOfDcmDslConnectionInfo;  /**< controller handle */
  FblCw_ParameterInfoIdxOfDcmDslConnectionInfoType ParameterInfoIdxOfDcmDslConnectionInfo;  /**< the index of the 0:1 relation pointing to FblCw_ParameterInfo */
  FblCw_TxRemotePduIdOfDcmDslConnectionInfoType TxRemotePduIdOfDcmDslConnectionInfo;  /**< DefinitionRef: /[ANY]/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu based symbolic name value */
} FblCw_DcmDslConnectionInfoType;

/**   \brief  type used in FblCw_DcmDslProtocolRxInfo */
/*! \spec weak type invariant () { 
 * (self.DcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo < FblCw_GetSizeOfDcmDslConnectionInfo())
 * } */
typedef struct sFblCw_DcmDslProtocolRxInfoType
{
  FblCw_AddrTypeOfDcmDslProtocolRxInfoType AddrTypeOfDcmDslProtocolRxInfo;  /**< DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx/DcmDslProtocolRxAddrType */
  FblCw_DcmDslConnectionInfoIdxOfDcmDslProtocolRxInfoType DcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo;  /**< the index of the 1:1 relation pointing to FblCw_DcmDslConnectionInfo */
} FblCw_DcmDslProtocolRxInfoType;

/**   \brief  type used in FblCw_DcmDslProtocolTxInfo */
/*! \spec weak type invariant () { 
 * (self.DcmDslConnectionInfoIdxOfDcmDslProtocolTxInfo < FblCw_GetSizeOfDcmDslConnectionInfo())
 * } */
typedef struct sFblCw_DcmDslProtocolTxInfoType
{
  FblCw_DcmDslConnectionInfoIdxOfDcmDslProtocolTxInfoType DcmDslConnectionInfoIdxOfDcmDslProtocolTxInfo;  /**< the index of the 1:1 relation pointing to FblCw_DcmDslConnectionInfo */
} FblCw_DcmDslProtocolTxInfoType;

/**   \brief  type used in FblCw_ParameterInfo */
typedef struct sFblCw_ParameterInfoType
{
  FblCw_PduRIdOfParameterInfoType PduRIdOfParameterInfo;  /**< PduR SNVs of DefinitionRef: /[ANY]/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu/PduRSourcePduHandleId */
} FblCw_ParameterInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCSymbolicStructTypes  FblCw Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to FblCw_InitialBC in the predefined variant RBTM_FL */
typedef struct FblCw_InitialBCRBTM_FLStructSTag
{
  FblCw_InitialBCType DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42;
  FblCw_InitialBCType DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3;
  FblCw_InitialBCType DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c;
} FblCw_InitialBCRBTM_FLStructSType;

/**   \brief  type to be used as symbolic data element access to FblCw_InitialBC in the predefined variant RBTM_FR */
typedef struct FblCw_InitialBCRBTM_FRStructSTag
{
  FblCw_InitialBCType DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987;
  FblCw_InitialBCType DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76;
  FblCw_InitialBCType DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528;
} FblCw_InitialBCRBTM_FRStructSType;

/**   \brief  type to be used as symbolic data element access to FblCw_InitialBS in the predefined variant RBTM_FL */
typedef struct FblCw_InitialBSRBTM_FLStructSTag
{
  FblCw_InitialBSType DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42;
  FblCw_InitialBSType DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3;
  FblCw_InitialBSType DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c;
} FblCw_InitialBSRBTM_FLStructSType;

/**   \brief  type to be used as symbolic data element access to FblCw_InitialBS in the predefined variant RBTM_FR */
typedef struct FblCw_InitialBSRBTM_FRStructSTag
{
  FblCw_InitialBSType DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987;
  FblCw_InitialBSType DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76;
  FblCw_InitialBSType DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528;
} FblCw_InitialBSRBTM_FRStructSType;

/**   \brief  type to be used as symbolic data element access to FblCw_InitialSTmin in the predefined variant RBTM_FL */
typedef struct FblCw_InitialSTminRBTM_FLStructSTag
{
  FblCw_InitialSTminType DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42;
  FblCw_InitialSTminType DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3;
  FblCw_InitialSTminType DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c;
} FblCw_InitialSTminRBTM_FLStructSType;

/**   \brief  type to be used as symbolic data element access to FblCw_InitialSTmin in the predefined variant RBTM_FR */
typedef struct FblCw_InitialSTminRBTM_FRStructSTag
{
  FblCw_InitialSTminType DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987;
  FblCw_InitialSTminType DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76;
  FblCw_InitialSTminType DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528;
} FblCw_InitialSTminRBTM_FRStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCUnionIndexAndSymbolTypes  FblCw Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access FblCw_InitialBC in an index and symbol based style. */
typedef union FblCw_InitialBCUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  FblCw_InitialBCType raw[3];
  FblCw_InitialBCRBTM_FLStructSType strRBTM_FL;
  FblCw_InitialBCRBTM_FRStructSType strRBTM_FR;
} FblCw_InitialBCUType;

/**   \brief  type to access FblCw_InitialBS in an index and symbol based style. */
typedef union FblCw_InitialBSUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  FblCw_InitialBSType raw[3];
  FblCw_InitialBSRBTM_FLStructSType strRBTM_FL;
  FblCw_InitialBSRBTM_FRStructSType strRBTM_FR;
} FblCw_InitialBSUType;

/**   \brief  type to access FblCw_InitialSTmin in an index and symbol based style. */
typedef union FblCw_InitialSTminUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  FblCw_InitialSTminType raw[3];
  FblCw_InitialSTminRBTM_FLStructSType strRBTM_FL;
  FblCw_InitialSTminRBTM_FRStructSType strRBTM_FR;
} FblCw_InitialSTminUType;

/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCRootPointerTypes  FblCw Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to FblCw_CanIfCtrlInfo */
typedef P2CONST(FblCw_CanIfCtrlInfoType, TYPEDEF, FBLCW_CONST) FblCw_CanIfCtrlInfoPtrType;

/**   \brief  type used to point to FblCw_CwDcmComMChannelMapping */
typedef P2CONST(FblCw_CwDcmComMChannelMappingType, TYPEDEF, FBLCW_CONST) FblCw_CwDcmComMChannelMappingPtrType;

/**   \brief  type used to point to FblCw_DcmDslConnectionInfo */
typedef P2CONST(FblCw_DcmDslConnectionInfoType, TYPEDEF, FBLCW_CONST) FblCw_DcmDslConnectionInfoPtrType;

/**   \brief  type used to point to FblCw_DcmDslProtocolRxInfo */
typedef P2CONST(FblCw_DcmDslProtocolRxInfoType, TYPEDEF, FBLCW_CONST) FblCw_DcmDslProtocolRxInfoPtrType;

/**   \brief  type used to point to FblCw_DcmDslProtocolTxInfo */
typedef P2CONST(FblCw_DcmDslProtocolTxInfoType, TYPEDEF, FBLCW_CONST) FblCw_DcmDslProtocolTxInfoPtrType;

/**   \brief  type used to point to FblCw_InitialBC */
typedef P2VAR(FblCw_InitialBCType, TYPEDEF, FBLCW_VAR_NOINIT) FblCw_InitialBCPtrType;

/**   \brief  type used to point to FblCw_InitialBS */
typedef P2VAR(FblCw_InitialBSType, TYPEDEF, FBLCW_VAR_NOINIT) FblCw_InitialBSPtrType;

/**   \brief  type used to point to FblCw_InitialSTmin */
typedef P2VAR(FblCw_InitialSTminType, TYPEDEF, FBLCW_VAR_NOINIT) FblCw_InitialSTminPtrType;

/**   \brief  type used to point to FblCw_Initialized */
typedef P2VAR(FblCw_InitializedType, TYPEDEF, FBLCW_VAR_ZERO_INIT) FblCw_InitializedPtrType;

/**   \brief  type used to point to FblCw_ParameterInfo */
typedef P2CONST(FblCw_ParameterInfoType, TYPEDEF, FBLCW_CONST) FblCw_ParameterInfoPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  FblCwPCRootValueTypes  FblCw Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in FblCw_PCConfig */
typedef struct sFblCw_PCConfigType
{
  FblCw_CwDcmComMChannelMappingPtrType CwDcmComMChannelMappingOfPCConfig;  /**< the pointer to FblCw_CwDcmComMChannelMapping */
  FblCw_DcmDslConnectionInfoPtrType DcmDslConnectionInfoOfPCConfig;  /**< the pointer to FblCw_DcmDslConnectionInfo */
  FblCw_DcmDslProtocolRxInfoPtrType DcmDslProtocolRxInfoOfPCConfig;  /**< the pointer to FblCw_DcmDslProtocolRxInfo */
  FblCw_DcmDslProtocolTxInfoPtrType DcmDslProtocolTxInfoOfPCConfig;  /**< the pointer to FblCw_DcmDslProtocolTxInfo */
  FblCw_ParameterInfoPtrType ParameterInfoOfPCConfig;  /**< the pointer to FblCw_ParameterInfo */
  FblCw_VariantIdxType VariantIdxOfPCConfig;
} FblCw_PCConfigType;

typedef FblCw_PCConfigType FblCw_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access FblCw_PCConfig in a symbol based style. */
typedef struct sFblCw_PCConfigsType
{
  FblCw_PCConfigType Config_RBTM_FL;  /**< [Config_RBTM_FL] */
  FblCw_PCConfigType Config_RBTM_FR;  /**< [Config_RBTM_FR] */
} FblCw_PCConfigsType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  FblCw_CanIfCtrlInfo
**********************************************************************************************************************/
/** 
  \var    FblCw_CanIfCtrlInfo
  \brief  DefinitionRef: /[ANY]/CanIf/CanIfCtrlDrvCfg/CanIfCtrlCfg
*/ 
#define FBLCW_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FblCw_CanIfCtrlInfoType, FBLCW_CONST) FblCw_CanIfCtrlInfo[1];
#define FBLCW_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_CwDcmComMChannelMappingRBTM_FL
**********************************************************************************************************************/
/** 
  \var    FblCw_CwDcmComMChannelMappingRBTM_FL
  \brief  Mapping of ComMChannels
*/ 
#define FBLCW_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FblCw_CwDcmComMChannelMappingType, FBLCW_CONST) FblCw_CwDcmComMChannelMappingRBTM_FL[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define FBLCW_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_CwDcmComMChannelMappingRBTM_FR
**********************************************************************************************************************/
/** 
  \var    FblCw_CwDcmComMChannelMappingRBTM_FR
  \brief  Mapping of ComMChannels
*/ 
#define FBLCW_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FblCw_CwDcmComMChannelMappingType, FBLCW_CONST) FblCw_CwDcmComMChannelMappingRBTM_FR[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define FBLCW_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslConnectionInfoRBTM_FL
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslConnectionInfoRBTM_FL
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection
  \details
  Element                  Description
  PayloadLimit             DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslPayloadLimit
  RxTesterSourceAddress    DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRxTesterSourceAddr
  Controller               controller handle
  ParameterInfoIdx         the index of the 0:1 relation pointing to FblCw_ParameterInfo
  TxRemotePduId            DefinitionRef: /[ANY]/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu based symbolic name value
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FblCw_DcmDslConnectionInfoType, FBLCW_CONST) FblCw_DcmDslConnectionInfoRBTM_FL[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslConnectionInfoRBTM_FR
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslConnectionInfoRBTM_FR
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection
  \details
  Element                  Description
  PayloadLimit             DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslPayloadLimit
  RxTesterSourceAddress    DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRxTesterSourceAddr
  Controller               controller handle
  ParameterInfoIdx         the index of the 0:1 relation pointing to FblCw_ParameterInfo
  TxRemotePduId            DefinitionRef: /[ANY]/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu based symbolic name value
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FblCw_DcmDslConnectionInfoType, FBLCW_CONST) FblCw_DcmDslConnectionInfoRBTM_FR[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslProtocolRxInfoRBTM_FL
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslProtocolRxInfoRBTM_FL
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx
  \details
  Element                    Description
  AddrType                   DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx/DcmDslProtocolRxAddrType
  DcmDslConnectionInfoIdx    the index of the 1:1 relation pointing to FblCw_DcmDslConnectionInfo
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FblCw_DcmDslProtocolRxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolRxInfoRBTM_FL[6];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslProtocolRxInfoRBTM_FR
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslProtocolRxInfoRBTM_FR
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx
  \details
  Element                    Description
  AddrType                   DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx/DcmDslProtocolRxAddrType
  DcmDslConnectionInfoIdx    the index of the 1:1 relation pointing to FblCw_DcmDslConnectionInfo
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FblCw_DcmDslProtocolRxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolRxInfoRBTM_FR[6];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslProtocolTxInfoRBTM_FL
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslProtocolTxInfoRBTM_FL
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolTx
  \details
  Element                    Description
  DcmDslConnectionInfoIdx    the index of the 1:1 relation pointing to FblCw_DcmDslConnectionInfo
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FblCw_DcmDslProtocolTxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolTxInfoRBTM_FL[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslProtocolTxInfoRBTM_FR
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslProtocolTxInfoRBTM_FR
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolTx
  \details
  Element                    Description
  DcmDslConnectionInfoIdx    the index of the 1:1 relation pointing to FblCw_DcmDslConnectionInfo
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FblCw_DcmDslProtocolTxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolTxInfoRBTM_FR[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_ParameterInfoRBTM_FL
**********************************************************************************************************************/
/** 
  \var    FblCw_ParameterInfoRBTM_FL
  \brief  all Change and Read parameter infos.
  \details
  Element    Description
  PduRId     PduR SNVs of DefinitionRef: /[ANY]/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu/PduRSourcePduHandleId
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FblCw_ParameterInfoType, FBLCW_CONST) FblCw_ParameterInfoRBTM_FL[3];
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_ParameterInfoRBTM_FR
**********************************************************************************************************************/
/** 
  \var    FblCw_ParameterInfoRBTM_FR
  \brief  all Change and Read parameter infos.
  \details
  Element    Description
  PduRId     PduR SNVs of DefinitionRef: /[ANY]/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu/PduRSourcePduHandleId
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FblCw_ParameterInfoType, FBLCW_CONST) FblCw_ParameterInfoRBTM_FR[3];
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_InitialBC
**********************************************************************************************************************/
/** 
  \var    FblCw_InitialBC
  \brief  initial STmin Values
*/ 
#define FBLCW_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(FblCw_InitialBCUType, FBLCW_VAR_NOINIT) FblCw_InitialBC;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define FBLCW_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_InitialBS
**********************************************************************************************************************/
/** 
  \var    FblCw_InitialBS
  \brief  initial BlockSize Values
*/ 
#define FBLCW_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(FblCw_InitialBSUType, FBLCW_VAR_NOINIT) FblCw_InitialBS;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define FBLCW_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_InitialSTmin
**********************************************************************************************************************/
/** 
  \var    FblCw_InitialSTmin
  \brief  initial STmin Values
*/ 
#define FBLCW_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(FblCw_InitialSTminUType, FBLCW_VAR_NOINIT) FblCw_InitialSTmin;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define FBLCW_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_Initialized
**********************************************************************************************************************/
/** 
  \var    FblCw_Initialized
  \brief  Initialization state of the Dcm. TRUE, if Dcm_Init() has been called, else FALSE.
*/ 
#define FBLCW_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(FblCw_InitializedType, FBLCW_VAR_ZERO_INIT) FblCw_Initialized;
#define FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_PCConfig
**********************************************************************************************************************/
/** 
  \var    FblCw_PCConfig
  \details
  Element                    Description
  CwDcmComMChannelMapping    the pointer to FblCw_CwDcmComMChannelMapping
  DcmDslConnectionInfo       the pointer to FblCw_DcmDslConnectionInfo
  DcmDslProtocolRxInfo       the pointer to FblCw_DcmDslProtocolRxInfo
  DcmDslProtocolTxInfo       the pointer to FblCw_DcmDslProtocolTxInfo
  ParameterInfo              the pointer to FblCw_ParameterInfo
  VariantIdx             
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FblCw_PCConfigsType, FBLCW_CONST) FblCw_PCConfig;
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



#define FBLCW_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define FBLCW_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif  /* FBLCW_LCFG_H */
/**********************************************************************************************************************
  END OF FILE: FblCw_Lcfg.h
**********************************************************************************************************************/

