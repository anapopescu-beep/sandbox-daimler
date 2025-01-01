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
 *            Module: IpduM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: IpduM_Lcfg.h
 *   Generation Time: 2023-07-10 14:36:08
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (IPDUM_LCFG_H)
# define IPDUM_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0785, 0786 EOF */ /* MD_CSL_DistinctIdentifiers */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Platform_Types.h"
# include "ComStack_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  IpduMPCDataSwitches  IpduM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define IPDUM_CCONTAINERRXQUEUEINFO                                                                 STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINERRXQUEUEINSTANCEENDIDXOFCONTAINERRXQUEUEINFO                                  STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo.ContainerRxQueueInstanceEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERRXQUEUEINSTANCELENGTHOFCONTAINERRXQUEUEINFO                                  STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo.ContainerRxQueueInstanceLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERRXQUEUEINSTANCESTARTIDXOFCONTAINERRXQUEUEINFO                                STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo.ContainerRxQueueInstanceStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERMAINFUNCTIONBUFFERENDIDXOFCONTAINERRXQUEUEINFO                             STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo.RxContainerMainFunctionBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERMAINFUNCTIONBUFFERLENGTHOFCONTAINERRXQUEUEINFO                             STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo.RxContainerMainFunctionBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERMAINFUNCTIONBUFFERSTARTIDXOFCONTAINERRXQUEUEINFO                           STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInfo.RxContainerMainFunctionBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CCONTAINERRXQUEUEINSTANCE                                                             STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInstance' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINERRXQUEUEBUFFERENDIDXOFCONTAINERRXQUEUEINSTANCE                                STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInstance.ContainerRxQueueBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERRXQUEUEBUFFERLENGTHOFCONTAINERRXQUEUEINSTANCE                                STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInstance.ContainerRxQueueBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERRXQUEUEBUFFERSTARTIDXOFCONTAINERRXQUEUEINSTANCE                              STD_OFF  /**< Deactivateable: 'IpduM_CContainerRxQueueInstance.ContainerRxQueueBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CCONTAINERTXCONFIRMATIONBUFFERINFO                                                    STD_OFF  /**< Deactivateable: 'IpduM_CContainerTxConfirmationBufferInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERENDIDXOFCONTAINERTXCONFIRMATIONBUFFERINFO                STD_OFF  /**< Deactivateable: 'IpduM_CContainerTxConfirmationBufferInfo.ContainerTxConfirmationBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERLENGTHOFCONTAINERTXCONFIRMATIONBUFFERINFO                STD_OFF  /**< Deactivateable: 'IpduM_CContainerTxConfirmationBufferInfo.ContainerTxConfirmationBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERSTARTIDXOFCONTAINERTXCONFIRMATIONBUFFERINFO              STD_OFF  /**< Deactivateable: 'IpduM_CContainerTxConfirmationBufferInfo.ContainerTxConfirmationBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CDATAQUEUEINFO                                                                        STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_DATAQUEUEINSTANCEENDIDXOFDATAQUEUEINFO                                                STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInfo.DataQueueInstanceEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEINSTANCELENGTHOFDATAQUEUEINFO                                                STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInfo.DataQueueInstanceLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEINSTANCESTARTIDXOFDATAQUEUEINFO                                              STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInfo.DataQueueInstanceStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CDATAQUEUEINSTANCE                                                                    STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_DATAQUEUEBUFFERENDIDXOFDATAQUEUEINSTANCE                                              STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance.DataQueueBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEBUFFERLENGTHOFDATAQUEUEINSTANCE                                              STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance.DataQueueBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEBUFFERSTARTIDXOFDATAQUEUEINSTANCE                                            STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance.DataQueueBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEIDBUFFERENDIDXOFDATAQUEUEINSTANCE                                            STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance.DataQueueIdBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEIDBUFFERLENGTHOFDATAQUEUEINSTANCE                                            STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance.DataQueueIdBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEIDBUFFERSTARTIDXOFDATAQUEUEINSTANCE                                          STD_OFF  /**< Deactivateable: 'IpduM_CDataQueueInstance.DataQueueIdBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CREQUESTQUEUEINFO                                                                     STD_OFF  /**< Deactivateable: 'IpduM_CRequestQueueInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_REQUESTQUEUEBUFFERENDIDXOFREQUESTQUEUEINFO                                            STD_OFF  /**< Deactivateable: 'IpduM_CRequestQueueInfo.RequestQueueBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEBUFFERLENGTHOFREQUESTQUEUEINFO                                            STD_OFF  /**< Deactivateable: 'IpduM_CRequestQueueInfo.RequestQueueBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEBUFFERSTARTIDXOFREQUESTQUEUEINFO                                          STD_OFF  /**< Deactivateable: 'IpduM_CRequestQueueInfo.RequestQueueBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CTXCONTAINERPDU                                                                       STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERINFOIDXOFTXCONTAINERPDU                                  STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.ContainerTxConfirmationBufferInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERINFOUSEDOFTXCONTAINERPDU                                 STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.ContainerTxConfirmationBufferInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTYPEOFTXCONTAINERPDU                                                         STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.ContainerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEINFOIDXOFTXCONTAINERPDU                                                      STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.DataQueueInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU                                                     STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.DataQueueInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DIRECTDATAPROVISIONOFTXCONTAINERPDU                                                   STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.DirectDataProvision' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_FIRSTCONTAINEDPDUTRIGGEROFTXCONTAINERPDU                                              STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.FirstContainedPduTrigger' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_HEADERSIZEOFTXCONTAINERPDU                                                            STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_METADATASIZEOFTXCONTAINERPDU                                                          STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.MetaDataSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_PDULENGTHOFTXCONTAINERPDU                                                             STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.PduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEPRIOINDIRECTIONIDXOFTXCONTAINERPDU                                        STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.RequestQueuePrioIndirectionIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU                                       STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.RequestQueuePrioIndirectionUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SENDTIMEOUTOFTXCONTAINERPDU                                                           STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.SendTimeout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SENDTODEFOFTXCONTAINERPDU                                                             STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.SendToDef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU                                                       STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TriggerTransmit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU                                                 STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxConfirmationTimeout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINEDPDUENDIDXOFTXCONTAINERPDU                                                  STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxContainedPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINEDPDUSTARTIDXOFTXCONTAINERPDU                                                STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxContainedPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINEDPDUUSEDOFTXCONTAINERPDU                                                    STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxContainedPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERPDUREFOFTXCONTAINERPDU                                                     STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxContainerPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXLOINFOIDXOFTXCONTAINERPDU                                                           STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxLoInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXLOINFOUSEDOFTXCONTAINERPDU                                                          STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxLoInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXSIZETHRESHOLDOFTXCONTAINERPDU                                                       STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.TxSizeThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_UNUSEDBITPATTERNOFTXCONTAINERPDU                                                      STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.UnusedBitPattern' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CTXLOINFO                                                                             STD_OFF  /**< Deactivateable: 'IpduM_CTxLoInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_PATHWAYTYPEOFCTXLOINFO                                                                STD_OFF  /**< Deactivateable: 'IpduM_CTxLoInfo.PathwayType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERPDUIDXOFCTXLOINFO                                                          STD_OFF  /**< Deactivateable: 'IpduM_CTxLoInfo.TxContainerPduIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERPDUUSEDOFCTXLOINFO                                                         STD_OFF  /**< Deactivateable: 'IpduM_CTxLoInfo.TxContainerPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXPATHWAYIDXOFCTXLOINFO                                                               STD_OFF  /**< Deactivateable: 'IpduM_CTxLoInfo.TxPathwayIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXPATHWAYUSEDOFCTXLOINFO                                                              STD_OFF  /**< Deactivateable: 'IpduM_CTxLoInfo.TxPathwayUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CTXPATHWAY                                                                            STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_JITUPDATEBUFFERENDIDXOFTXPATHWAY                                                      STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.JitUpdateBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_JITUPDATEBUFFERLENGTHOFTXPATHWAY                                                      STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.JitUpdateBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_JITUPDATEBUFFERSTARTIDXOFTXPATHWAY                                                    STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.JitUpdateBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LLPDUREFOFTXPATHWAY                                                                   STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.LlPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TRIGGERTRANSMITBUFFERENDIDXOFTXPATHWAY                                                STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TriggerTransmitBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TRIGGERTRANSMITBUFFERLENGTHOFTXPATHWAY                                                STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TriggerTransmitBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TRIGGERTRANSMITBUFFERSTARTIDXOFTXPATHWAY                                              STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TriggerTransmitBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXBUFFERENDIDXOFTXPATHWAY                                                             STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXBUFFERLENGTHOFTXPATHWAY                                                             STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXBUFFERSTARTIDXOFTXPATHWAY                                                           STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONFIRMATIONTIMEOUTOFTXPATHWAY                                                      STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxConfirmationTimeout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXLOINFOIDXOFTXPATHWAY                                                                STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxLoInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXLOINFOUSEDOFTXPATHWAY                                                               STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxLoInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXPARTINDENDIDXOFTXPATHWAY                                                            STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxPartIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXPARTINDSTARTIDXOFTXPATHWAY                                                          STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxPartIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXPARTINITIALDYNPARTIDXOFTXPATHWAY                                                    STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxPartInitialDynPartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXPARTSTATICPARTIDXOFTXPATHWAY                                                        STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxPartStaticPartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXPARTSTATICPARTUSEDOFTXPATHWAY                                                       STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxPartStaticPartUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXSTATICPDUREFOFTXPATHWAY                                                             STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxStaticPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXSTATICPDUREFUSEDOFTXPATHWAY                                                         STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.TxStaticPduRefUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_UNUSEDAREASDEFAULTOFTXPATHWAY                                                         STD_OFF  /**< Deactivateable: 'IpduM_CTxPathway.UnusedAreasDefault' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERRXQUEUEBUFFER                                                                STD_OFF  /**< Deactivateable: 'IpduM_ContainerRxQueueBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFER                                                         STD_OFF  /**< Deactivateable: 'IpduM_ContainerTxConfirmationBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXLIBBUFFER                                                                  STD_OFF  /**< Deactivateable: 'IpduM_ContainerTxLIBBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEBUFFER                                                                       STD_OFF  /**< Deactivateable: 'IpduM_DataQueueBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DATAQUEUEIDBUFFER                                                                     STD_OFF  /**< Deactivateable: 'IpduM_DataQueueIdBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'IpduM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define IPDUM_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'IpduM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define IPDUM_INITIALIZED                                                                           STD_ON
#define IPDUM_JITUPDATEBUFFER                                                                       STD_OFF  /**< Deactivateable: 'IpduM_JitUpdateBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_MAINFUNCTIONRXINDIRECTION                                                             STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionRxIndirection' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_RXCONTAINERPDUINDENDIDXOFMAINFUNCTIONRXINDIRECTION                                    STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionRxIndirection.RxContainerPduIndEndIdx' Reason: 'the optional indirection is deactivated because RxContainerPduIndUsedOfMainFunctionRxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_RXCONTAINERPDUINDSTARTIDXOFMAINFUNCTIONRXINDIRECTION                                  STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionRxIndirection.RxContainerPduIndStartIdx' Reason: 'the optional indirection is deactivated because RxContainerPduIndUsedOfMainFunctionRxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_RXCONTAINERPDUINDUSEDOFMAINFUNCTIONRXINDIRECTION                                      STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionRxIndirection.RxContainerPduIndUsed' Reason: 'the optional indirection is deactivated because RxContainerPduIndUsedOfMainFunctionRxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_MAINFUNCTIONTXINDIRECTION                                                             STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionTxIndirection' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_TXCONTAINERPDUINDENDIDXOFMAINFUNCTIONTXINDIRECTION                                    STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionTxIndirection.TxContainerPduIndEndIdx' Reason: 'the optional indirection is deactivated because TxContainerPduIndUsedOfMainFunctionTxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXCONTAINERPDUINDSTARTIDXOFMAINFUNCTIONTXINDIRECTION                                  STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionTxIndirection.TxContainerPduIndStartIdx' Reason: 'the optional indirection is deactivated because TxContainerPduIndUsedOfMainFunctionTxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXCONTAINERPDUINDUSEDOFMAINFUNCTIONTXINDIRECTION                                      STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionTxIndirection.TxContainerPduIndUsed' Reason: 'the optional indirection is deactivated because TxContainerPduIndUsedOfMainFunctionTxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXLOINFOINDENDIDXOFMAINFUNCTIONTXINDIRECTION                                          STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionTxIndirection.TxLoInfoIndEndIdx' Reason: 'the optional indirection is deactivated because TxLoInfoIndUsedOfMainFunctionTxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXLOINFOINDSTARTIDXOFMAINFUNCTIONTXINDIRECTION                                        STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionTxIndirection.TxLoInfoIndStartIdx' Reason: 'the optional indirection is deactivated because TxLoInfoIndUsedOfMainFunctionTxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXLOINFOINDUSEDOFMAINFUNCTIONTXINDIRECTION                                            STD_OFF  /**< Deactivateable: 'IpduM_MainFunctionTxIndirection.TxLoInfoIndUsed' Reason: 'the optional indirection is deactivated because TxLoInfoIndUsedOfMainFunctionTxIndirection is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_REQUESTQUEUEBUFFER                                                                    STD_OFF  /**< Deactivateable: 'IpduM_RequestQueueBuffer' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_DLCOFREQUESTQUEUEBUFFER                                                               STD_OFF  /**< Deactivateable: 'IpduM_RequestQueueBuffer.Dlc' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_TXCONTAINEDPDUIDXOFREQUESTQUEUEBUFFER                                                 STD_OFF  /**< Deactivateable: 'IpduM_RequestQueueBuffer.TxContainedPduIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_REQUESTQUEUEPRIOINDIRECTION                                                           STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINERTXLIBBUFFERENDIDXOFREQUESTQUEUEPRIOINDIRECTION                               STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection.ContainerTxLIBBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXLIBBUFFERLENGTHOFREQUESTQUEUEPRIOINDIRECTION                               STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection.ContainerTxLIBBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXLIBBUFFERSTARTIDXOFREQUESTQUEUEPRIOINDIRECTION                             STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection.ContainerTxLIBBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEINFOENDIDXOFREQUESTQUEUEPRIOINDIRECTION                                   STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection.RequestQueueInfoEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEINFOLENGTHOFREQUESTQUEUEPRIOINDIRECTION                                   STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection.RequestQueueInfoLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEINFOSTARTIDXOFREQUESTQUEUEPRIOINDIRECTION                                 STD_OFF  /**< Deactivateable: 'IpduM_RequestQueuePrioIndirection.RequestQueueInfoStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RESTSEGMENT                                                                           STD_OFF  /**< Deactivateable: 'IpduM_RestSegment' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_BITINBYTEPOSOFRESTSEGMENT                                                             STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.BitInBytePos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_ENDBYTEMASKCLEAROFRESTSEGMENT                                                         STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.EndByteMaskClear' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_ENDBYTEMASKWRITEOFRESTSEGMENT                                                         STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.EndByteMaskWrite' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_FIRSTBYTEPOSOFRESTSEGMENT                                                             STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.FirstBytePos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_FIRSTFULLBYTEPOSOFRESTSEGMENT                                                         STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.FirstFullBytePos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_FULLBYTESPRESENTOFRESTSEGMENT                                                         STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.FullBytesPresent' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LASTBYTEPOSOFRESTSEGMENT                                                              STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.LastBytePos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LASTFULLBYTEPOSOFRESTSEGMENT                                                          STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.LastFullBytePos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LENGTHOFRESTSEGMENT                                                                   STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_PARTIALENDBYTEOFRESTSEGMENT                                                           STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.PartialEndByte' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_PARTIALSTARTBYTEOFRESTSEGMENT                                                         STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.PartialStartByte' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_PDUBYTEPOSOFRESTSEGMENT                                                               STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.PduBytePos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_STARTBYTEMASKCLEAROFRESTSEGMENT                                                       STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.StartByteMaskClear' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_STARTBYTEMASKWRITEOFRESTSEGMENT                                                       STD_OFF  /**< Deactivateable: 'IpduM_RestSegment.StartByteMaskWrite' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXBUFFER                                                                              STD_ON
#define IPDUM_RXCONTAINEDPDU                                                                        STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINEDPDUREFOFRXCONTAINEDPDU                                                       STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.ContainedPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_ENDBYTEPOSITIONOFRXCONTAINEDPDU                                                       STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.EndBytePosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_HEADERIDOFRXCONTAINEDPDU                                                              STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.HeaderId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LENGTHOFRXCONTAINEDPDU                                                                STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_OFFSETOFRXCONTAINEDPDU                                                                STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.Offset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERPDUIDXOFRXCONTAINEDPDU                                                     STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.RxContainerPduIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERPDUUSEDOFRXCONTAINEDPDU                                                    STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.RxContainerPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_UPDATEBITUSEDOFRXCONTAINEDPDU                                                         STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.UpdateBitUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_UPDATEINDICATIONBITPOSITIONOFRXCONTAINEDPDU                                           STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.UpdateIndicationBitPosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINEDPDUIND                                                                     STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPduInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERMAINFUNCTIONBUFFER                                                         STD_OFF  /**< Deactivateable: 'IpduM_RxContainerMainFunctionBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERPDU                                                                        STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_ACCEPTALLPDUSOFRXCONTAINERPDU                                                         STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.AcceptAllPdus' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERRXQUEUEINFOIDXOFRXCONTAINERPDU                                               STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.ContainerRxQueueInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERRXQUEUEINFOUSEDOFRXCONTAINERPDU                                              STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.ContainerRxQueueInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_HEADERSIZEOFRXCONTAINERPDU                                                            STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_METADATASIZEOFRXCONTAINERPDU                                                          STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.MetaDataSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINEDPDUINDENDIDXOFRXCONTAINERPDU                                               STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.RxContainedPduIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINEDPDUINDSTARTIDXOFRXCONTAINERPDU                                             STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.RxContainedPduIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINEDPDUINDUSEDOFRXCONTAINERPDU                                                 STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.RxContainedPduIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERPDUIND                                                                     STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPduInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXDYNPDU                                                                              STD_ON
#define IPDUM_MINDLCOFRXDYNPDU                                                                      STD_ON
#define IPDUM_RXSELECTORPATTERNENDIDXOFRXDYNPDU                                                     STD_ON
#define IPDUM_RXSELECTORPATTERNSTARTIDXOFRXDYNPDU                                                   STD_ON
#define IPDUM_SEGMENTENDIDXOFRXDYNPDU                                                               STD_ON
#define IPDUM_SEGMENTSTARTIDXOFRXDYNPDU                                                             STD_ON
#define IPDUM_ULPDUREFOFRXDYNPDU                                                                    STD_ON
#define IPDUM_RXINFO                                                                                STD_ON
#define IPDUM_INVALIDHNDOFRXINFO                                                                    STD_OFF  /**< Deactivateable: 'IpduM_RxInfo.InvalidHnd' Reason: 'the value of IpduM_InvalidHndOfRxInfo is always 'false' due to this, the array is deactivated.' */
#define IPDUM_PATHWAYTYPEOFRXINFO                                                                   STD_ON
#define IPDUM_RXPATHWAYINDIDXOFRXINFO                                                               STD_ON
#define IPDUM_RXPATHWAYINDOFRXINFO                                                                  STD_ON
#define IPDUM_RXMUXPDU                                                                              STD_ON
#define IPDUM_RXBUFFERENDIDXOFRXMUXPDU                                                              STD_ON
#define IPDUM_RXBUFFERSTARTIDXOFRXMUXPDU                                                            STD_ON
#define IPDUM_RXDYNPDUENDIDXOFRXMUXPDU                                                              STD_ON
#define IPDUM_RXDYNPDUSTARTIDXOFRXMUXPDU                                                            STD_ON
#define IPDUM_RXSTATICPDUIDXOFRXMUXPDU                                                              STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu.RxStaticPduIdx' Reason: 'the optional indirection is deactivated because RxStaticPduUsedOfRxMuxPdu is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_RXSTATICPDUUSEDOFRXMUXPDU                                                             STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu.RxStaticPduUsed' Reason: 'the optional indirection is deactivated because RxStaticPduUsedOfRxMuxPdu is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_SELECTORFIELDBYTEPOSITIONOFRXMUXPDU                                                   STD_ON
#define IPDUM_SELECTORFIELDSTARTBITOFRXMUXPDU                                                       STD_ON
#define IPDUM_RXSELECTORPATTERN                                                                     STD_ON
#define IPDUM_SELECTORFIELDSUBMASKOFRXSELECTORPATTERN                                               STD_ON
#define IPDUM_SELECTORFIELDSUBPATTERNOFRXSELECTORPATTERN                                            STD_ON
#define IPDUM_RXSTATICPDU                                                                           STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_MINDLCOFRXSTATICPDU                                                                   STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu.MinDLC' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SEGMENTENDIDXOFRXSTATICPDU                                                            STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu.SegmentEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SEGMENTSTARTIDXOFRXSTATICPDU                                                          STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu.SegmentStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_ULPDUREFOFRXSTATICPDU                                                                 STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu.UlPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SEGMENT                                                                               STD_ON
#define IPDUM_BITINBYTEPOSOFSEGMENT                                                                 STD_ON
#define IPDUM_ENDBYTEMASKCLEAROFSEGMENT                                                             STD_ON
#define IPDUM_ENDBYTEMASKWRITEOFSEGMENT                                                             STD_ON
#define IPDUM_FIRSTBYTEPOSOFSEGMENT                                                                 STD_ON
#define IPDUM_FIRSTFULLBYTEPOSOFSEGMENT                                                             STD_ON
#define IPDUM_FULLBYTESPRESENTOFSEGMENT                                                             STD_ON
#define IPDUM_LASTBYTEPOSOFSEGMENT                                                                  STD_ON
#define IPDUM_LASTFULLBYTEPOSOFSEGMENT                                                              STD_ON
#define IPDUM_LENGTHOFSEGMENT                                                                       STD_ON
#define IPDUM_PARTIALENDBYTEOFSEGMENT                                                               STD_OFF  /**< Deactivateable: 'IpduM_Segment.PartialEndByte' Reason: 'the value of IpduM_PartialEndByteOfSegment is always 'false' due to this, the array is deactivated.' */
#define IPDUM_PARTIALSTARTBYTEOFSEGMENT                                                             STD_OFF  /**< Deactivateable: 'IpduM_Segment.PartialStartByte' Reason: 'the value of IpduM_PartialStartByteOfSegment is always 'false' due to this, the array is deactivated.' */
#define IPDUM_PDUBYTEPOSOFSEGMENT                                                                   STD_ON
#define IPDUM_STARTBYTEMASKCLEAROFSEGMENT                                                           STD_ON
#define IPDUM_STARTBYTEMASKWRITEOFSEGMENT                                                           STD_ON
#define IPDUM_SIZEOFRXBUFFER                                                                        STD_ON
#define IPDUM_SIZEOFRXDYNPDU                                                                        STD_ON
#define IPDUM_SIZEOFRXINFO                                                                          STD_ON
#define IPDUM_SIZEOFRXMUXPDU                                                                        STD_ON
#define IPDUM_SIZEOFRXSELECTORPATTERN                                                               STD_ON
#define IPDUM_SIZEOFSEGMENT                                                                         STD_ON
#define IPDUM_TRIGGERTRANSMITBUFFER                                                                 STD_OFF  /**< Deactivateable: 'IpduM_TriggerTransmitBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXBUFFER                                                                              STD_OFF  /**< Deactivateable: 'IpduM_TxBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINEDPDU                                                                        STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_HEADERIDOFTXCONTAINEDPDU                                                              STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.HeaderId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LASTISBESTOFTXCONTAINEDPDU                                                            STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.LastIsBest' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_OFFSETOFTXCONTAINEDPDU                                                                STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.Offset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEINFOIDXOFTXCONTAINEDPDU                                                   STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.RequestQueueInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_REQUESTQUEUEINFOUSEDOFTXCONTAINEDPDU                                                  STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.RequestQueueInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SENDTIMEOUTOFTXCONTAINEDPDU                                                           STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.SendTimeout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SENDTODEFOFTXCONTAINEDPDU                                                             STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.SendToDef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU                                                        STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.TxConfirmation' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINEDPDUREFOFTXCONTAINEDPDU                                                     STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.TxContainedPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERPDUIDXOFTXCONTAINEDPDU                                                     STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.TxContainerPduIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXPDUTRIGGEROFTXCONTAINEDPDU                                                          STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.TxPduTrigger' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_UPDATEBITUSEDOFTXCONTAINEDPDU                                                         STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.UpdateBitUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_UPDATEINDICATIONBITPOSITIONOFTXCONTAINEDPDU                                           STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.UpdateIndicationBitPosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERPDUIND                                                                     STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPduInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXINITVALUES                                                                          STD_OFF  /**< Deactivateable: 'IpduM_TxInitValues' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXLOINFOIND                                                                           STD_OFF  /**< Deactivateable: 'IpduM_TxLoInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXLOINFOWITHINVALIDINDEXES                                                            STD_OFF  /**< Deactivateable: 'IpduM_TxLoInfoWithInvalidIndexes' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CTXLOINFOIDXOFTXLOINFOWITHINVALIDINDEXES                                              STD_OFF  /**< Deactivateable: 'IpduM_TxLoInfoWithInvalidIndexes.CTxLoInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_INVALIDHNDOFTXLOINFOWITHINVALIDINDEXES                                                STD_OFF  /**< Deactivateable: 'IpduM_TxLoInfoWithInvalidIndexes.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXPART                                                                                STD_OFF  /**< Deactivateable: 'IpduM_TxPart' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_JITUPDATEOFTXPART                                                                     STD_OFF  /**< Deactivateable: 'IpduM_TxPart.JitUpdate' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RESTSEGMENTENDIDXOFTXPART                                                             STD_OFF  /**< Deactivateable: 'IpduM_TxPart.RestSegmentEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RESTSEGMENTSTARTIDXOFTXPART                                                           STD_OFF  /**< Deactivateable: 'IpduM_TxPart.RestSegmentStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RESTSEGMENTUSEDOFTXPART                                                               STD_OFF  /**< Deactivateable: 'IpduM_TxPart.RestSegmentUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SEGMENTENDIDXOFTXPART                                                                 STD_OFF  /**< Deactivateable: 'IpduM_TxPart.SegmentEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SEGMENTSTARTIDXOFTXPART                                                               STD_OFF  /**< Deactivateable: 'IpduM_TxPart.SegmentStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TRIGGEREVENTOFTXPART                                                                  STD_OFF  /**< Deactivateable: 'IpduM_TxPart.TriggerEvent' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONFIRMATIONOFTXPART                                                                STD_OFF  /**< Deactivateable: 'IpduM_TxPart.TxConfirmation' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXPATHWAYIDXOFTXPART                                                                  STD_OFF  /**< Deactivateable: 'IpduM_TxPart.TxPathwayIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_ULPDUREFOFTXPART                                                                      STD_OFF  /**< Deactivateable: 'IpduM_TxPart.UlPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXPARTIND                                                                             STD_OFF  /**< Deactivateable: 'IpduM_TxPartInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXUPINFO                                                                              STD_OFF  /**< Deactivateable: 'IpduM_TxUpInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_INVALIDHNDOFTXUPINFO                                                                  STD_OFF  /**< Deactivateable: 'IpduM_TxUpInfo.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_PATHWAYTYPEOFTXUPINFO                                                                 STD_OFF  /**< Deactivateable: 'IpduM_TxUpInfo.PathwayType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXUPINDIDXOFTXUPINFO                                                                  STD_OFF  /**< Deactivateable: 'IpduM_TxUpInfo.TxUpIndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXUPINDOFTXUPINFO                                                                     STD_OFF  /**< Deactivateable: 'IpduM_TxUpInfo.TxUpInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_VCONTAINERRXQUEUEINFO                                                                 STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInfo' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_CONTAINERRXQUEUEINSTANCEREADIDXOFCONTAINERRXQUEUEINFO                                 STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInfo.ContainerRxQueueInstanceReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_CONTAINERRXQUEUEINSTANCEWRITEIDXOFCONTAINERRXQUEUEINFO                                STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInfo.ContainerRxQueueInstanceWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_READCOUNTOFCONTAINERRXQUEUEINFO                                                       STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInfo.ReadCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_WRITECOUNTOFCONTAINERRXQUEUEINFO                                                      STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInfo.WriteCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VCONTAINERRXQUEUEINSTANCE                                                             STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInstance' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_RECEIVEDSIZEOFCONTAINERRXQUEUEINSTANCE                                                STD_OFF  /**< Deactivateable: 'IpduM_VContainerRxQueueInstance.ReceivedSize' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VCONTAINERTXCONFIRMATIONBUFFERINFO                                                    STD_OFF  /**< Deactivateable: 'IpduM_VContainerTxConfirmationBufferInfo' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERREADIDXOFCONTAINERTXCONFIRMATIONBUFFERINFO               STD_OFF  /**< Deactivateable: 'IpduM_VContainerTxConfirmationBufferInfo.ContainerTxConfirmationBufferReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_CONTAINERTXCONFIRMATIONBUFFERWRITEIDXOFCONTAINERTXCONFIRMATIONBUFFERINFO              STD_OFF  /**< Deactivateable: 'IpduM_VContainerTxConfirmationBufferInfo.ContainerTxConfirmationBufferWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VDATAQUEUEINFO                                                                        STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInfo' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_DATAQUEUEINSTANCEREADIDXOFDATAQUEUEINFO                                               STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInfo.DataQueueInstanceReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_DATAQUEUEINSTANCEWRITEIDXOFDATAQUEUEINFO                                              STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInfo.DataQueueInstanceWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_READCOUNTOFDATAQUEUEINFO                                                              STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInfo.ReadCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_WRITECOUNTOFDATAQUEUEINFO                                                             STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInfo.WriteCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VDATAQUEUEINSTANCE                                                                    STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInstance' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_DATAQUEUEIDBUFFERWRITEIDXOFDATAQUEUEINSTANCE                                          STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInstance.DataQueueIdBufferWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_FILLCOUNTOFDATAQUEUEINSTANCE                                                          STD_OFF  /**< Deactivateable: 'IpduM_VDataQueueInstance.FillCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VREQUESTQUEUEINFO                                                                     STD_OFF  /**< Deactivateable: 'IpduM_VRequestQueueInfo' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_READIDXOFREQUESTQUEUEINFO                                                             STD_OFF  /**< Deactivateable: 'IpduM_VRequestQueueInfo.ReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_READTMPIDXOFREQUESTQUEUEINFO                                                          STD_OFF  /**< Deactivateable: 'IpduM_VRequestQueueInfo.ReadTmpIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_WRITEIDXOFREQUESTQUEUEINFO                                                            STD_OFF  /**< Deactivateable: 'IpduM_VRequestQueueInfo.WriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VTXCONTAINERPDU                                                                       STD_OFF  /**< Deactivateable: 'IpduM_VTxContainerPdu' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_CONTAINERPDUSENDTIMEOUTOFTXCONTAINERPDU                                               STD_OFF  /**< Deactivateable: 'IpduM_VTxContainerPdu.ContainerPduSendTimeout' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_FIRSTCONTAINEDPDUOFTXCONTAINERPDU                                                     STD_OFF  /**< Deactivateable: 'IpduM_VTxContainerPdu.FirstContainedPdu' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VTXLOINFO                                                                             STD_OFF  /**< Deactivateable: 'IpduM_VTxLoInfo' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_TXCONFTIMEOUTCNTOFVTXLOINFO                                                           STD_OFF  /**< Deactivateable: 'IpduM_VTxLoInfo.TxConfTimeoutCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_VTXPATHWAY                                                                            STD_OFF  /**< Deactivateable: 'IpduM_VTxPathway' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_TXPARTDYNAMICPARTIDXOFTXPATHWAY                                                       STD_OFF  /**< Deactivateable: 'IpduM_VTxPathway.TxPartDynamicPartIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define IPDUM_PCCONFIG                                                                              STD_ON
#define IPDUM_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'IpduM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define IPDUM_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'IpduM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define IPDUM_INITIALIZEDOFPCCONFIG                                                                 STD_ON
#define IPDUM_RXBUFFEROFPCCONFIG                                                                    STD_ON
#define IPDUM_RXDYNPDUOFPCCONFIG                                                                    STD_ON
#define IPDUM_RXINFOOFPCCONFIG                                                                      STD_ON
#define IPDUM_RXMUXPDUOFPCCONFIG                                                                    STD_ON
#define IPDUM_RXSELECTORPATTERNOFPCCONFIG                                                           STD_ON
#define IPDUM_SEGMENTOFPCCONFIG                                                                     STD_ON
#define IPDUM_SIZEOFRXBUFFEROFPCCONFIG                                                              STD_ON
#define IPDUM_SIZEOFRXDYNPDUOFPCCONFIG                                                              STD_ON
#define IPDUM_SIZEOFRXINFOOFPCCONFIG                                                                STD_ON
#define IPDUM_SIZEOFRXMUXPDUOFPCCONFIG                                                              STD_ON
#define IPDUM_SIZEOFRXSELECTORPATTERNOFPCCONFIG                                                     STD_ON
#define IPDUM_SIZEOFSEGMENTOFPCCONFIG                                                               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCMinNumericValueDefines  IpduM Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define IPDUM_MIN_RXBUFFER                                                                          0u
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCMaxNumericValueDefines  IpduM Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define IPDUM_MAX_RXBUFFER                                                                          255u
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCEnumExistsDefines  IpduM Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define IPDUM_EXISTS_QUEUED_CONTAINERTYPEOFTXCONTAINERPDU                                           STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.ContainerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_LAST_IS_BEST_CONTAINERTYPEOFTXCONTAINERPDU                                     STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.ContainerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_LONG_HEADERSIZEOFTXCONTAINERPDU                                                STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_SHORT_HEADERSIZEOFTXCONTAINERPDU                                               STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_NONE_HEADERSIZEOFTXCONTAINERPDU                                                STD_OFF  /**< Deactivateable: 'IpduM_CTxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_MUX_PATHWAYTYPEOFCTXLOINFO                                                     STD_OFF  /**< Deactivateable: 'IpduM_CTxLoInfo.PathwayType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFCTXLOINFO                                               STD_OFF  /**< Deactivateable: 'IpduM_CTxLoInfo.PathwayType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU                                                STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU                                               STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_NONE_HEADERSIZEOFRXCONTAINERPDU                                                STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.HeaderSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_MUX_PATHWAYTYPEOFRXINFO                                                        STD_ON
#define IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFRXINFO                                                  STD_OFF
#define IPDUM_EXISTS_RXMUXPDU_RXPATHWAYINDOFRXINFO                                                  STD_ON
#define IPDUM_EXISTS_RXCONTAINERPDU_RXPATHWAYINDOFRXINFO                                            STD_OFF
#define IPDUM_EXISTS_MUX_PATHWAYTYPEOFTXUPINFO                                                      STD_OFF  /**< Deactivateable: 'IpduM_TxUpInfo.PathwayType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFTXUPINFO                                                STD_OFF  /**< Deactivateable: 'IpduM_TxUpInfo.PathwayType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_TXPART_TXUPINDOFTXUPINFO                                                       STD_OFF  /**< Deactivateable: 'IpduM_TxUpInfo.TxUpInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_TXCONTAINEDPDU_TXUPINDOFTXUPINFO                                               STD_OFF  /**< Deactivateable: 'IpduM_TxUpInfo.TxUpInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCEnumDefines  IpduM Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define IPDUM_MUX_PATHWAYTYPEOFRXINFO                                                               0x00u
#define IPDUM_RXMUXPDU_RXPATHWAYINDOFRXINFO                                                         0x00u
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCIsReducedToDefineDefines  IpduM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define IPDUM_ISDEF_MINDLCOFRXDYNPDU                                                                STD_OFF
#define IPDUM_ISDEF_RXSELECTORPATTERNENDIDXOFRXDYNPDU                                               STD_OFF
#define IPDUM_ISDEF_RXSELECTORPATTERNSTARTIDXOFRXDYNPDU                                             STD_OFF
#define IPDUM_ISDEF_SEGMENTENDIDXOFRXDYNPDU                                                         STD_OFF
#define IPDUM_ISDEF_SEGMENTSTARTIDXOFRXDYNPDU                                                       STD_OFF
#define IPDUM_ISDEF_ULPDUREFOFRXDYNPDU                                                              STD_OFF
#define IPDUM_ISDEF_PATHWAYTYPEOFRXINFO                                                             STD_OFF
#define IPDUM_ISDEF_RXPATHWAYINDIDXOFRXINFO                                                         STD_OFF
#define IPDUM_ISDEF_RXPATHWAYINDOFRXINFO                                                            STD_OFF
#define IPDUM_ISDEF_RXBUFFERENDIDXOFRXMUXPDU                                                        STD_OFF
#define IPDUM_ISDEF_RXBUFFERSTARTIDXOFRXMUXPDU                                                      STD_OFF
#define IPDUM_ISDEF_RXDYNPDUENDIDXOFRXMUXPDU                                                        STD_OFF
#define IPDUM_ISDEF_RXDYNPDUSTARTIDXOFRXMUXPDU                                                      STD_OFF
#define IPDUM_ISDEF_SELECTORFIELDBYTEPOSITIONOFRXMUXPDU                                             STD_OFF
#define IPDUM_ISDEF_SELECTORFIELDSTARTBITOFRXMUXPDU                                                 STD_OFF
#define IPDUM_ISDEF_SELECTORFIELDSUBMASKOFRXSELECTORPATTERN                                         STD_OFF
#define IPDUM_ISDEF_SELECTORFIELDSUBPATTERNOFRXSELECTORPATTERN                                      STD_OFF
#define IPDUM_ISDEF_BITINBYTEPOSOFSEGMENT                                                           STD_OFF
#define IPDUM_ISDEF_ENDBYTEMASKCLEAROFSEGMENT                                                       STD_OFF
#define IPDUM_ISDEF_ENDBYTEMASKWRITEOFSEGMENT                                                       STD_OFF
#define IPDUM_ISDEF_FIRSTBYTEPOSOFSEGMENT                                                           STD_OFF
#define IPDUM_ISDEF_FIRSTFULLBYTEPOSOFSEGMENT                                                       STD_OFF
#define IPDUM_ISDEF_FULLBYTESPRESENTOFSEGMENT                                                       STD_OFF
#define IPDUM_ISDEF_LASTBYTEPOSOFSEGMENT                                                            STD_OFF
#define IPDUM_ISDEF_LASTFULLBYTEPOSOFSEGMENT                                                        STD_OFF
#define IPDUM_ISDEF_LENGTHOFSEGMENT                                                                 STD_OFF
#define IPDUM_ISDEF_PDUBYTEPOSOFSEGMENT                                                             STD_OFF
#define IPDUM_ISDEF_STARTBYTEMASKCLEAROFSEGMENT                                                     STD_OFF
#define IPDUM_ISDEF_STARTBYTEMASKWRITEOFSEGMENT                                                     STD_OFF
#define IPDUM_ISDEF_INITIALIZEDOFPCCONFIG                                                           STD_ON
#define IPDUM_ISDEF_RXBUFFEROFPCCONFIG                                                              STD_ON
#define IPDUM_ISDEF_RXDYNPDUOFPCCONFIG                                                              STD_ON
#define IPDUM_ISDEF_RXINFOOFPCCONFIG                                                                STD_ON
#define IPDUM_ISDEF_RXMUXPDUOFPCCONFIG                                                              STD_ON
#define IPDUM_ISDEF_RXSELECTORPATTERNOFPCCONFIG                                                     STD_ON
#define IPDUM_ISDEF_SEGMENTOFPCCONFIG                                                               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCEqualsAlwaysToDefines  IpduM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define IPDUM_EQ2_MINDLCOFRXDYNPDU                                                                  
#define IPDUM_EQ2_RXSELECTORPATTERNENDIDXOFRXDYNPDU                                                 
#define IPDUM_EQ2_RXSELECTORPATTERNSTARTIDXOFRXDYNPDU                                               
#define IPDUM_EQ2_SEGMENTENDIDXOFRXDYNPDU                                                           
#define IPDUM_EQ2_SEGMENTSTARTIDXOFRXDYNPDU                                                         
#define IPDUM_EQ2_ULPDUREFOFRXDYNPDU                                                                
#define IPDUM_EQ2_PATHWAYTYPEOFRXINFO                                                               
#define IPDUM_EQ2_RXPATHWAYINDIDXOFRXINFO                                                           
#define IPDUM_EQ2_RXPATHWAYINDOFRXINFO                                                              
#define IPDUM_EQ2_RXBUFFERENDIDXOFRXMUXPDU                                                          
#define IPDUM_EQ2_RXBUFFERSTARTIDXOFRXMUXPDU                                                        
#define IPDUM_EQ2_RXDYNPDUENDIDXOFRXMUXPDU                                                          
#define IPDUM_EQ2_RXDYNPDUSTARTIDXOFRXMUXPDU                                                        
#define IPDUM_EQ2_SELECTORFIELDBYTEPOSITIONOFRXMUXPDU                                               
#define IPDUM_EQ2_SELECTORFIELDSTARTBITOFRXMUXPDU                                                   
#define IPDUM_EQ2_SELECTORFIELDSUBMASKOFRXSELECTORPATTERN                                           
#define IPDUM_EQ2_SELECTORFIELDSUBPATTERNOFRXSELECTORPATTERN                                        
#define IPDUM_EQ2_BITINBYTEPOSOFSEGMENT                                                             
#define IPDUM_EQ2_ENDBYTEMASKCLEAROFSEGMENT                                                         
#define IPDUM_EQ2_ENDBYTEMASKWRITEOFSEGMENT                                                         
#define IPDUM_EQ2_FIRSTBYTEPOSOFSEGMENT                                                             
#define IPDUM_EQ2_FIRSTFULLBYTEPOSOFSEGMENT                                                         
#define IPDUM_EQ2_FULLBYTESPRESENTOFSEGMENT                                                         
#define IPDUM_EQ2_LASTBYTEPOSOFSEGMENT                                                              
#define IPDUM_EQ2_LASTFULLBYTEPOSOFSEGMENT                                                          
#define IPDUM_EQ2_LENGTHOFSEGMENT                                                                   
#define IPDUM_EQ2_PDUBYTEPOSOFSEGMENT                                                               
#define IPDUM_EQ2_STARTBYTEMASKCLEAROFSEGMENT                                                       
#define IPDUM_EQ2_STARTBYTEMASKWRITEOFSEGMENT                                                       
#define IPDUM_EQ2_INITIALIZEDOFPCCONFIG                                                             (&(IpduM_Initialized))
#define IPDUM_EQ2_RXBUFFEROFPCCONFIG                                                                IpduM_RxBuffer.raw
#define IPDUM_EQ2_RXDYNPDUOFPCCONFIG                                                                IpduM_RxDynPdu
#define IPDUM_EQ2_RXINFOOFPCCONFIG                                                                  IpduM_RxInfo
#define IPDUM_EQ2_RXMUXPDUOFPCCONFIG                                                                IpduM_RxMuxPdu
#define IPDUM_EQ2_RXSELECTORPATTERNOFPCCONFIG                                                       IpduM_RxSelectorPattern
#define IPDUM_EQ2_SEGMENTOFPCCONFIG                                                                 IpduM_Segment
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCSymbolicInitializationPointers  IpduM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define IpduM_Config_Ptr                                                                            NULL_PTR  /**< symbolic identifier which shall be used to initialize 'IpduM' */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCInitializationSymbols  IpduM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define IpduM_Config                                                                                NULL_PTR  /**< symbolic identifier which could be used to initialize 'IpduM */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGeneral  IpduM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define IPDUM_CHECK_INIT_POINTER                                                                    STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define IPDUM_FINAL_MAGIC_NUMBER                                                                    0x341Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of IpduM */
#define IPDUM_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'IpduM' is not configured to be postbuild capable. */
#define IPDUM_INIT_DATA                                                                             IPDUM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define IPDUM_INIT_DATA_HASH_CODE                                                                   966437021  /**< the precompile constant to validate the initialization structure at initialization time of IpduM with a hashcode. The seed value is '0x341Eu' */
#define IPDUM_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define IPDUM_USE_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer IpduM shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  IpduMLTDataSwitches  IpduM Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define IPDUM_LTCONFIG                                                                              STD_OFF  /**< Deactivateable: 'IpduM_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
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
  \defgroup  IpduMPCGetConstantDuplicatedRootDataMacros  IpduM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define IpduM_GetInitializedOfPCConfig()                                                            (&(IpduM_Initialized))  /**< the pointer to IpduM_Initialized */
#define IpduM_GetRxBufferOfPCConfig()                                                               IpduM_RxBuffer.raw  /**< the pointer to IpduM_RxBuffer */
#define IpduM_GetRxDynPduOfPCConfig()                                                               IpduM_RxDynPdu  /**< the pointer to IpduM_RxDynPdu */
#define IpduM_GetRxInfoOfPCConfig()                                                                 IpduM_RxInfo  /**< the pointer to IpduM_RxInfo */
#define IpduM_GetRxMuxPduOfPCConfig()                                                               IpduM_RxMuxPdu  /**< the pointer to IpduM_RxMuxPdu */
#define IpduM_GetRxSelectorPatternOfPCConfig()                                                      IpduM_RxSelectorPattern  /**< the pointer to IpduM_RxSelectorPattern */
#define IpduM_GetSegmentOfPCConfig()                                                                IpduM_Segment  /**< the pointer to IpduM_Segment */
#define IpduM_GetSizeOfRxBufferOfPCConfig()                                                         16u  /**< the number of accomplishable value elements in IpduM_RxBuffer */
#define IpduM_GetSizeOfRxDynPduOfPCConfig()                                                         4u  /**< the number of accomplishable value elements in IpduM_RxDynPdu */
#define IpduM_GetSizeOfRxInfoOfPCConfig()                                                           2u  /**< the number of accomplishable value elements in IpduM_RxInfo */
#define IpduM_GetSizeOfRxMuxPduOfPCConfig()                                                         2u  /**< the number of accomplishable value elements in IpduM_RxMuxPdu */
#define IpduM_GetSizeOfRxSelectorPatternOfPCConfig()                                                4u  /**< the number of accomplishable value elements in IpduM_RxSelectorPattern */
#define IpduM_GetSizeOfSegmentOfPCConfig()                                                          1u  /**< the number of accomplishable value elements in IpduM_Segment */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGetDataMacros  IpduM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define IpduM_IsInitialized()                                                                       (((*(IpduM_GetInitializedOfPCConfig()))) != FALSE)
#define IpduM_GetRxBuffer(Index)                                                                    (IpduM_GetRxBufferOfPCConfig()[(Index)])
#define IpduM_GetSegmentEndIdxOfRxDynPdu(Index)                                                     (IpduM_GetRxDynPduOfPCConfig()[(Index)].SegmentEndIdxOfRxDynPdu)
#define IpduM_GetUlPduRefOfRxDynPdu(Index)                                                          (IpduM_GetRxDynPduOfPCConfig()[(Index)].UlPduRefOfRxDynPdu)
#define IpduM_GetRxPathwayIndOfRxInfo(Index)                                                        (IpduM_GetRxInfoOfPCConfig()[(Index)].RxPathwayIndOfRxInfo)
#define IpduM_GetRxBufferStartIdxOfRxMuxPdu(Index)                                                  (IpduM_GetRxMuxPduOfPCConfig()[(Index)].RxBufferStartIdxOfRxMuxPdu)
#define IpduM_GetRxDynPduStartIdxOfRxMuxPdu(Index)                                                  (IpduM_GetRxMuxPduOfPCConfig()[(Index)].RxDynPduStartIdxOfRxMuxPdu)
#define IpduM_GetSelectorFieldStartBitOfRxMuxPdu(Index)                                             (IpduM_GetRxMuxPduOfPCConfig()[(Index)].SelectorFieldStartBitOfRxMuxPdu)
#define IpduM_GetSelectorFieldSubMaskOfRxSelectorPattern(Index)                                     (IpduM_GetRxSelectorPatternOfPCConfig()[(Index)].SelectorFieldSubMaskOfRxSelectorPattern)
#define IpduM_GetSelectorFieldSubPatternOfRxSelectorPattern(Index)                                  (IpduM_GetRxSelectorPatternOfPCConfig()[(Index)].SelectorFieldSubPatternOfRxSelectorPattern)
#define IpduM_IsFullBytesPresentOfSegment(Index)                                                    ((IpduM_GetSegmentOfPCConfig()[(Index)].FullBytesPresentOfSegment) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGetDeduplicatedDataMacros  IpduM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define IpduM_GetMinDLCOfRxDynPdu(Index)                                                            ((IpduM_MinDLCOfRxDynPduType)((IpduM_GetSegmentEndIdxOfRxDynPdu(Index) + 7u)))  /**< the minimum DLC derived from the maximum end bit of the related segments. */
#define IpduM_GetRxSelectorPatternEndIdxOfRxDynPdu(Index)                                           ((IpduM_RxSelectorPatternEndIdxOfRxDynPduType)((((IpduM_RxSelectorPatternEndIdxOfRxDynPduType)(Index)) + 1u)))  /**< the end index of the 1:n relation pointing to IpduM_RxSelectorPattern */
#define IpduM_GetRxSelectorPatternStartIdxOfRxDynPdu(Index)                                         ((IpduM_RxSelectorPatternStartIdxOfRxDynPduType)((Index)))  /**< the start index of the 1:n relation pointing to IpduM_RxSelectorPattern */
#define IpduM_GetSegmentStartIdxOfRxDynPdu(Index)                                                   ((IpduM_SegmentStartIdxOfRxDynPduType)((IpduM_GetSegmentEndIdxOfRxDynPdu(Index) - 1u)))  /**< the start index of the 1:n relation pointing to IpduM_Segment */
#define IpduM_GetPathwayTypeOfRxInfo(Index)                                                         IpduM_GetRxPathwayIndOfRxInfo(Index)  /**< The type of the pathway. */
#define IpduM_GetRxPathwayIndIdxOfRxInfo(Index)                                                     ((IpduM_RxPathwayIndIdxOfRxInfoType)((Index)))  /**< the index of the 1:1 relation pointing to one of IpduM_RxMuxPdu,IpduM_RxContainerPdu */
#define IpduM_GetRxBufferEndIdxOfRxMuxPdu(Index)                                                    ((IpduM_RxBufferEndIdxOfRxMuxPduType)((IpduM_GetRxBufferStartIdxOfRxMuxPdu(Index) + 8u)))  /**< the end index of the 1:n relation pointing to IpduM_RxBuffer */
#define IpduM_GetRxDynPduEndIdxOfRxMuxPdu(Index)                                                    ((IpduM_RxDynPduEndIdxOfRxMuxPduType)((IpduM_GetRxDynPduStartIdxOfRxMuxPdu(Index) + 2u)))  /**< the end index of the 1:n relation pointing to IpduM_RxDynPdu */
#define IpduM_GetSelectorFieldBytePositionOfRxMuxPdu(Index)                                         IpduM_GetSelectorFieldStartBitOfRxMuxPdu(Index)  /**< the byte position of the selector value in the PDU. */
#define IpduM_GetBitInBytePosOfSegment(Index)                                                       ((IpduM_BitInBytePosOfSegmentType)((Index)))  /**< the bit position of the segment in the byte position. */
#define IpduM_GetEndByteMaskClearOfSegment(Index)                                                   ((IpduM_EndByteMaskClearOfSegmentType)((Index)))  /**< Mask for the partial end byte: clearing. */
#define IpduM_GetEndByteMaskWriteOfSegment(Index)                                                   ((IpduM_EndByteMaskWriteOfSegmentType)((((IpduM_EndByteMaskWriteOfSegmentType)(Index)) + 0xFFu)))  /**< Mask for the partial end byte: writing. */
#define IpduM_GetFirstBytePosOfSegment(Index)                                                       ((IpduM_FirstBytePosOfSegmentType)((Index)))  /**< Byte position of the first byte of this segment. */
#define IpduM_GetFirstFullBytePosOfSegment(Index)                                                   ((IpduM_FirstFullBytePosOfSegmentType)((Index)))  /**< Byte position of the first full byte. */
#define IpduM_GetLastBytePosOfSegment(Index)                                                        ((IpduM_LastBytePosOfSegmentType)((((IpduM_LastBytePosOfSegmentType)(Index)) + 7u)))  /**< Byte position of the last byte of this segment. */
#define IpduM_GetLastFullBytePosOfSegment(Index)                                                    ((IpduM_LastFullBytePosOfSegmentType)((((IpduM_LastFullBytePosOfSegmentType)(Index)) + 7u)))  /**< Byte position of the last full byte. */
#define IpduM_GetLengthOfSegment(Index)                                                             ((IpduM_LengthOfSegmentType)((((IpduM_LengthOfSegmentType)(Index)) + 64u)))  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart/IpduMSegment/IpduMSegmentLength. */
#define IpduM_GetPduBytePosOfSegment(Index)                                                         ((IpduM_PduBytePosOfSegmentType)((Index)))  /**< the byte position of the segment in the PDU. */
#define IpduM_GetStartByteMaskClearOfSegment(Index)                                                 ((IpduM_StartByteMaskClearOfSegmentType)((Index)))  /**< Mask for the partial start byte: clearing. */
#define IpduM_GetStartByteMaskWriteOfSegment(Index)                                                 ((IpduM_StartByteMaskWriteOfSegmentType)((((IpduM_StartByteMaskWriteOfSegmentType)(Index)) + 0xFFu)))  /**< Mask for the partial start byte: writing. */
#define IpduM_GetSizeOfRxBuffer()                                                                   IpduM_GetSizeOfRxBufferOfPCConfig()
#define IpduM_GetSizeOfRxDynPdu()                                                                   IpduM_GetSizeOfRxDynPduOfPCConfig()
#define IpduM_GetSizeOfRxInfo()                                                                     IpduM_GetSizeOfRxInfoOfPCConfig()
#define IpduM_GetSizeOfRxMuxPdu()                                                                   IpduM_GetSizeOfRxMuxPduOfPCConfig()
#define IpduM_GetSizeOfRxSelectorPattern()                                                          IpduM_GetSizeOfRxSelectorPatternOfPCConfig()
#define IpduM_GetSizeOfSegment()                                                                    IpduM_GetSizeOfSegmentOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCSetDataMacros  IpduM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define IpduM_SetInitialized(Value)                                                                 (*(IpduM_GetInitializedOfPCConfig())) = (Value)
#define IpduM_SetRxBuffer(Index, Value)                                                             IpduM_GetRxBufferOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGetAddressOfDataMacros  IpduM Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define IpduM_GetAddrRxBuffer(Index)                                                                (&IpduM_GetRxBuffer(Index))
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCHasMacros  IpduM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define IpduM_HasInitialized()                                                                      (TRUE != FALSE)
#define IpduM_HasRxBuffer()                                                                         (TRUE != FALSE)
#define IpduM_HasRxDynPdu()                                                                         (TRUE != FALSE)
#define IpduM_HasMinDLCOfRxDynPdu()                                                                 (TRUE != FALSE)
#define IpduM_HasRxSelectorPatternEndIdxOfRxDynPdu()                                                (TRUE != FALSE)
#define IpduM_HasRxSelectorPatternStartIdxOfRxDynPdu()                                              (TRUE != FALSE)
#define IpduM_HasSegmentEndIdxOfRxDynPdu()                                                          (TRUE != FALSE)
#define IpduM_HasSegmentStartIdxOfRxDynPdu()                                                        (TRUE != FALSE)
#define IpduM_HasUlPduRefOfRxDynPdu()                                                               (TRUE != FALSE)
#define IpduM_HasRxInfo()                                                                           (TRUE != FALSE)
#define IpduM_HasPathwayTypeOfRxInfo()                                                              (TRUE != FALSE)
#define IpduM_HasRxPathwayIndIdxOfRxInfo()                                                          (TRUE != FALSE)
#define IpduM_HasRxPathwayIndOfRxInfo()                                                             (TRUE != FALSE)
#define IpduM_HasRxMuxPdu()                                                                         (TRUE != FALSE)
#define IpduM_HasRxBufferEndIdxOfRxMuxPdu()                                                         (TRUE != FALSE)
#define IpduM_HasRxBufferStartIdxOfRxMuxPdu()                                                       (TRUE != FALSE)
#define IpduM_HasRxDynPduEndIdxOfRxMuxPdu()                                                         (TRUE != FALSE)
#define IpduM_HasRxDynPduStartIdxOfRxMuxPdu()                                                       (TRUE != FALSE)
#define IpduM_HasSelectorFieldBytePositionOfRxMuxPdu()                                              (TRUE != FALSE)
#define IpduM_HasSelectorFieldStartBitOfRxMuxPdu()                                                  (TRUE != FALSE)
#define IpduM_HasRxSelectorPattern()                                                                (TRUE != FALSE)
#define IpduM_HasSelectorFieldSubMaskOfRxSelectorPattern()                                          (TRUE != FALSE)
#define IpduM_HasSelectorFieldSubPatternOfRxSelectorPattern()                                       (TRUE != FALSE)
#define IpduM_HasSegment()                                                                          (TRUE != FALSE)
#define IpduM_HasBitInBytePosOfSegment()                                                            (TRUE != FALSE)
#define IpduM_HasEndByteMaskClearOfSegment()                                                        (TRUE != FALSE)
#define IpduM_HasEndByteMaskWriteOfSegment()                                                        (TRUE != FALSE)
#define IpduM_HasFirstBytePosOfSegment()                                                            (TRUE != FALSE)
#define IpduM_HasFirstFullBytePosOfSegment()                                                        (TRUE != FALSE)
#define IpduM_HasFullBytesPresentOfSegment()                                                        (TRUE != FALSE)
#define IpduM_HasLastBytePosOfSegment()                                                             (TRUE != FALSE)
#define IpduM_HasLastFullBytePosOfSegment()                                                         (TRUE != FALSE)
#define IpduM_HasLengthOfSegment()                                                                  (TRUE != FALSE)
#define IpduM_HasPduBytePosOfSegment()                                                              (TRUE != FALSE)
#define IpduM_HasStartByteMaskClearOfSegment()                                                      (TRUE != FALSE)
#define IpduM_HasStartByteMaskWriteOfSegment()                                                      (TRUE != FALSE)
#define IpduM_HasSizeOfRxBuffer()                                                                   (TRUE != FALSE)
#define IpduM_HasSizeOfRxDynPdu()                                                                   (TRUE != FALSE)
#define IpduM_HasSizeOfRxInfo()                                                                     (TRUE != FALSE)
#define IpduM_HasSizeOfRxMuxPdu()                                                                   (TRUE != FALSE)
#define IpduM_HasSizeOfRxSelectorPattern()                                                          (TRUE != FALSE)
#define IpduM_HasSizeOfSegment()                                                                    (TRUE != FALSE)
#define IpduM_HasPCConfig()                                                                         (TRUE != FALSE)
#define IpduM_HasInitializedOfPCConfig()                                                            (TRUE != FALSE)
#define IpduM_HasRxBufferOfPCConfig()                                                               (TRUE != FALSE)
#define IpduM_HasRxDynPduOfPCConfig()                                                               (TRUE != FALSE)
#define IpduM_HasRxInfoOfPCConfig()                                                                 (TRUE != FALSE)
#define IpduM_HasRxMuxPduOfPCConfig()                                                               (TRUE != FALSE)
#define IpduM_HasRxSelectorPatternOfPCConfig()                                                      (TRUE != FALSE)
#define IpduM_HasSegmentOfPCConfig()                                                                (TRUE != FALSE)
#define IpduM_HasSizeOfRxBufferOfPCConfig()                                                         (TRUE != FALSE)
#define IpduM_HasSizeOfRxDynPduOfPCConfig()                                                         (TRUE != FALSE)
#define IpduM_HasSizeOfRxInfoOfPCConfig()                                                           (TRUE != FALSE)
#define IpduM_HasSizeOfRxMuxPduOfPCConfig()                                                         (TRUE != FALSE)
#define IpduM_HasSizeOfRxSelectorPatternOfPCConfig()                                                (TRUE != FALSE)
#define IpduM_HasSizeOfSegmentOfPCConfig()                                                          (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCIncrementDataMacros  IpduM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define IpduM_IncRxBuffer(Index)                                                                    IpduM_GetRxBuffer(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCDecrementDataMacros  IpduM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define IpduM_DecRxBuffer(Index)                                                                    IpduM_GetRxBuffer(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCAddDataMacros  IpduM Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define IpduM_AddRxBuffer(Index, Value)                                                             IpduM_SetRxBuffer(Index, (IpduM_GetRxBuffer(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCSubstractDataMacros  IpduM Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define IpduM_SubRxBuffer(Index, Value)                                                             IpduM_SetRxBuffer(Index, (IpduM_GetRxBuffer(Index) - Value))
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


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  IpduMPCIterableTypes  IpduM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate IpduM_RxBuffer */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfRxBuffer() } \endspec */ 
typedef uint8_least IpduM_RxBufferIterType;

/**   \brief  type used to iterate IpduM_RxDynPdu */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfRxDynPdu() } \endspec */ 
typedef uint8_least IpduM_RxDynPduIterType;

/**   \brief  type used to iterate IpduM_RxInfo */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfRxInfo() } \endspec */ 
typedef uint8_least IpduM_RxInfoIterType;

/**   \brief  type used to iterate IpduM_RxMuxPdu */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfRxMuxPdu() } \endspec */ 
typedef uint8_least IpduM_RxMuxPduIterType;

/**   \brief  type used to iterate IpduM_RxSelectorPattern */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfRxSelectorPattern() } \endspec */ 
typedef uint8_least IpduM_RxSelectorPatternIterType;

/**   \brief  type used to iterate IpduM_Segment */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfSegment() } \endspec */ 
typedef uint8_least IpduM_SegmentIterType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCValueTypes  IpduM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for IpduM_Initialized */
typedef boolean IpduM_InitializedType;

/**   \brief  value based type definition for IpduM_RxBuffer */
typedef uint8 IpduM_RxBufferType;

/**   \brief  value based type definition for IpduM_MinDLCOfRxDynPdu */
typedef uint8 IpduM_MinDLCOfRxDynPduType;

/**   \brief  value based type definition for IpduM_RxSelectorPatternEndIdxOfRxDynPdu */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfRxSelectorPattern() } \endspec */ 
typedef uint8 IpduM_RxSelectorPatternEndIdxOfRxDynPduType;

/**   \brief  value based type definition for IpduM_RxSelectorPatternStartIdxOfRxDynPdu */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfRxSelectorPattern() } \endspec */ 
typedef uint8 IpduM_RxSelectorPatternStartIdxOfRxDynPduType;

/**   \brief  value based type definition for IpduM_SegmentEndIdxOfRxDynPdu */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfSegment() } \endspec */ 
typedef uint8 IpduM_SegmentEndIdxOfRxDynPduType;

/**   \brief  value based type definition for IpduM_SegmentStartIdxOfRxDynPdu */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfSegment() } \endspec */ 
typedef uint8 IpduM_SegmentStartIdxOfRxDynPduType;

/**   \brief  value based type definition for IpduM_UlPduRefOfRxDynPdu */
typedef uint8 IpduM_UlPduRefOfRxDynPduType;

/**   \brief  value based type definition for IpduM_PathwayTypeOfRxInfo */
typedef uint8 IpduM_PathwayTypeOfRxInfoType;

/**   \brief  value based type definition for IpduM_RxPathwayIndIdxOfRxInfo */
/*! \spec strong type invariant () { (self < IpduM_GetSizeOfRxMuxPdu()) } \endspec */ 
typedef uint8 IpduM_RxPathwayIndIdxOfRxInfoType;

/**   \brief  value based type definition for IpduM_RxPathwayIndOfRxInfo */
typedef uint8 IpduM_RxPathwayIndOfRxInfoType;

/**   \brief  value based type definition for IpduM_RxBufferEndIdxOfRxMuxPdu */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfRxBuffer() } \endspec */ 
typedef uint8 IpduM_RxBufferEndIdxOfRxMuxPduType;

/**   \brief  value based type definition for IpduM_RxBufferStartIdxOfRxMuxPdu */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfRxBuffer() } \endspec */ 
typedef uint8 IpduM_RxBufferStartIdxOfRxMuxPduType;

/**   \brief  value based type definition for IpduM_RxDynPduEndIdxOfRxMuxPdu */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfRxDynPdu() } \endspec */ 
typedef uint8 IpduM_RxDynPduEndIdxOfRxMuxPduType;

/**   \brief  value based type definition for IpduM_RxDynPduStartIdxOfRxMuxPdu */
/*! \spec strong type invariant () { self < IpduM_GetSizeOfRxDynPdu() } \endspec */ 
typedef uint8 IpduM_RxDynPduStartIdxOfRxMuxPduType;

/**   \brief  value based type definition for IpduM_SelectorFieldBytePositionOfRxMuxPdu */
typedef uint8 IpduM_SelectorFieldBytePositionOfRxMuxPduType;

/**   \brief  value based type definition for IpduM_SelectorFieldStartBitOfRxMuxPdu */
typedef uint8 IpduM_SelectorFieldStartBitOfRxMuxPduType;

/**   \brief  value based type definition for IpduM_SelectorFieldSubMaskOfRxSelectorPattern */
typedef uint8 IpduM_SelectorFieldSubMaskOfRxSelectorPatternType;

/**   \brief  value based type definition for IpduM_SelectorFieldSubPatternOfRxSelectorPattern */
typedef uint8 IpduM_SelectorFieldSubPatternOfRxSelectorPatternType;

/**   \brief  value based type definition for IpduM_BitInBytePosOfSegment */
typedef uint8 IpduM_BitInBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_EndByteMaskClearOfSegment */
typedef uint8 IpduM_EndByteMaskClearOfSegmentType;

/**   \brief  value based type definition for IpduM_EndByteMaskWriteOfSegment */
typedef uint8 IpduM_EndByteMaskWriteOfSegmentType;

/**   \brief  value based type definition for IpduM_FirstBytePosOfSegment */
typedef uint8 IpduM_FirstBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_FirstFullBytePosOfSegment */
typedef uint8 IpduM_FirstFullBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_FullBytesPresentOfSegment */
typedef boolean IpduM_FullBytesPresentOfSegmentType;

/**   \brief  value based type definition for IpduM_LastBytePosOfSegment */
typedef uint8 IpduM_LastBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_LastFullBytePosOfSegment */
typedef uint8 IpduM_LastFullBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_LengthOfSegment */
typedef uint8 IpduM_LengthOfSegmentType;

/**   \brief  value based type definition for IpduM_PduBytePosOfSegment */
typedef uint8 IpduM_PduBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_StartByteMaskClearOfSegment */
typedef uint8 IpduM_StartByteMaskClearOfSegmentType;

/**   \brief  value based type definition for IpduM_StartByteMaskWriteOfSegment */
typedef uint8 IpduM_StartByteMaskWriteOfSegmentType;

/**   \brief  value based type definition for IpduM_SizeOfRxBuffer */
typedef uint8 IpduM_SizeOfRxBufferType;

/**   \brief  value based type definition for IpduM_SizeOfRxDynPdu */
typedef uint8 IpduM_SizeOfRxDynPduType;

/**   \brief  value based type definition for IpduM_SizeOfRxInfo */
typedef uint8 IpduM_SizeOfRxInfoType;

/**   \brief  value based type definition for IpduM_SizeOfRxMuxPdu */
typedef uint8 IpduM_SizeOfRxMuxPduType;

/**   \brief  value based type definition for IpduM_SizeOfRxSelectorPattern */
typedef uint8 IpduM_SizeOfRxSelectorPatternType;

/**   \brief  value based type definition for IpduM_SizeOfSegment */
typedef uint8 IpduM_SizeOfSegmentType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  IpduMPCStructTypes  IpduM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in IpduM_RxDynPdu */
/*! 
 * \spec strong type invariant () { 
 *   (self.SegmentEndIdxOfRxDynPdu < IpduM_GetSizeOfSegment())
 * }
 * \endspec 
 */ 
typedef struct sIpduM_RxDynPduType
{
  IpduM_SegmentEndIdxOfRxDynPduType SegmentEndIdxOfRxDynPdu;  /**< the end index of the 1:n relation pointing to IpduM_Segment */
  IpduM_UlPduRefOfRxDynPduType UlPduRefOfRxDynPdu;  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart/IpduMOutgoingDynamicPduRef */
} IpduM_RxDynPduType;

/**   \brief  type used in IpduM_RxInfo */
typedef struct sIpduM_RxInfoType
{
  IpduM_RxPathwayIndOfRxInfoType RxPathwayIndOfRxInfo;  /**< the enum value of the according target of the 1:1 relation pointing to one of IpduM_RxMuxPdu,IpduM_RxContainerPdu */
} IpduM_RxInfoType;

/**   \brief  type used in IpduM_RxMuxPdu */
/*! 
 * \spec strong type invariant () { 
 *   (self.RxBufferStartIdxOfRxMuxPdu < IpduM_GetSizeOfRxBuffer()) &&
 *   (self.RxDynPduStartIdxOfRxMuxPdu < IpduM_GetSizeOfRxDynPdu())
 * }
 * \endspec 
 */ 
typedef struct sIpduM_RxMuxPduType
{
  IpduM_RxBufferStartIdxOfRxMuxPduType RxBufferStartIdxOfRxMuxPdu;  /**< the start index of the 1:n relation pointing to IpduM_RxBuffer */
  IpduM_RxDynPduStartIdxOfRxMuxPduType RxDynPduStartIdxOfRxMuxPdu;  /**< the start index of the 1:n relation pointing to IpduM_RxDynPdu */
  IpduM_SelectorFieldStartBitOfRxMuxPduType SelectorFieldStartBitOfRxMuxPdu;  /**< the bit position of the selector value in the byte position. */
} IpduM_RxMuxPduType;

/**   \brief  type used in IpduM_RxSelectorPattern */
typedef struct sIpduM_RxSelectorPatternType
{
  IpduM_SelectorFieldSubMaskOfRxSelectorPatternType SelectorFieldSubMaskOfRxSelectorPattern;  /**< One byte of the mask the pattern is masked with for the selector field as it is transmitted. */
  IpduM_SelectorFieldSubPatternOfRxSelectorPatternType SelectorFieldSubPatternOfRxSelectorPattern;  /**< One byte of the masked pattern for the selector field as it is transmitted - calculated from position and length. */
} IpduM_RxSelectorPatternType;

/**   \brief  type used in IpduM_Segment */
typedef struct sIpduM_SegmentType
{
  IpduM_FullBytesPresentOfSegmentType FullBytesPresentOfSegment;  /**< True if full bytes exist in this segment. */
} IpduM_SegmentType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCSymbolicStructTypes  IpduM Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to IpduM_RxBuffer */
typedef struct IpduM_RxBufferStructSTag
{
  IpduM_RxBufferType IpduMRxIndication_33e88c66[8];
  IpduM_RxBufferType IpduMRxIndication_17ccd7a3[8];
} IpduM_RxBufferStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCUnionIndexAndSymbolTypes  IpduM Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access IpduM_RxBuffer in an index and symbol based style. */
typedef union IpduM_RxBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  IpduM_RxBufferType raw[16];
  IpduM_RxBufferStructSType str;
} IpduM_RxBufferUType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCRootPointerTypes  IpduM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to IpduM_Initialized */
typedef P2VAR(IpduM_InitializedType, TYPEDEF, IPDUM_VAR_CLEARED) IpduM_InitializedPtrType;

/**   \brief  type used to point to IpduM_RxBuffer */
typedef P2VAR(IpduM_RxBufferType, TYPEDEF, IPDUM_VAR_NO_INIT) IpduM_RxBufferPtrType;

/**   \brief  type used to point to IpduM_RxDynPdu */
typedef P2CONST(IpduM_RxDynPduType, TYPEDEF, IPDUM_CONST) IpduM_RxDynPduPtrType;

/**   \brief  type used to point to IpduM_RxInfo */
typedef P2CONST(IpduM_RxInfoType, TYPEDEF, IPDUM_CONST) IpduM_RxInfoPtrType;

/**   \brief  type used to point to IpduM_RxMuxPdu */
typedef P2CONST(IpduM_RxMuxPduType, TYPEDEF, IPDUM_CONST) IpduM_RxMuxPduPtrType;

/**   \brief  type used to point to IpduM_RxSelectorPattern */
typedef P2CONST(IpduM_RxSelectorPatternType, TYPEDEF, IPDUM_CONST) IpduM_RxSelectorPatternPtrType;

/**   \brief  type used to point to IpduM_Segment */
typedef P2CONST(IpduM_SegmentType, TYPEDEF, IPDUM_CONST) IpduM_SegmentPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCRootValueTypes  IpduM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in IpduM_PCConfig */
typedef struct sIpduM_PCConfigType
{
  uint8 IpduM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} IpduM_PCConfigType;

typedef IpduM_PCConfigType IpduM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

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
  IpduM_RxDynPdu
**********************************************************************************************************************/
/** 
  \var    IpduM_RxDynPdu
  \brief  DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart
  \details
  Element          Description
  SegmentEndIdx    the end index of the 1:n relation pointing to IpduM_Segment
  UlPduRef         the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart/IpduMOutgoingDynamicPduRef
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(IpduM_RxDynPduType, IPDUM_CONST) IpduM_RxDynPdu[4];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_RxInfo
**********************************************************************************************************************/
/** 
  \var    IpduM_RxInfo
  \brief  All DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway and DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMContainerRxPdu, used for RxIndication().
  \details
  Element         Description
  RxPathwayInd    the enum value of the according target of the 1:1 relation pointing to one of IpduM_RxMuxPdu,IpduM_RxContainerPdu
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(IpduM_RxInfoType, IPDUM_CONST) IpduM_RxInfo[2];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_RxMuxPdu
**********************************************************************************************************************/
/** 
  \var    IpduM_RxMuxPdu
  \brief  DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway
  \details
  Element                  Description
  RxBufferStartIdx         the start index of the 1:n relation pointing to IpduM_RxBuffer
  RxDynPduStartIdx         the start index of the 1:n relation pointing to IpduM_RxDynPdu
  SelectorFieldStartBit    the bit position of the selector value in the byte position.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(IpduM_RxMuxPduType, IPDUM_CONST) IpduM_RxMuxPdu[2];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_RxSelectorPattern
**********************************************************************************************************************/
/** 
  \var    IpduM_RxSelectorPattern
  \brief  Selector patterns for single- and multi-byte selector value matching. This table is sorted for ascending byte number within one DynPdu.
  \details
  Element                    Description
  SelectorFieldSubMask       One byte of the mask the pattern is masked with for the selector field as it is transmitted.
  SelectorFieldSubPattern    One byte of the masked pattern for the selector field as it is transmitted - calculated from position and length.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(IpduM_RxSelectorPatternType, IPDUM_CONST) IpduM_RxSelectorPattern[4];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_Segment
**********************************************************************************************************************/
/** 
  \var    IpduM_Segment
  \brief  all IpduMSegments
  \details
  Element             Description
  FullBytesPresent    True if full bytes exist in this segment.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(IpduM_SegmentType, IPDUM_CONST) IpduM_Segment[1];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_Initialized
**********************************************************************************************************************/
/** 
  \var    IpduM_Initialized
  \brief  Initialization state of the IpduM. TRUE, if IpduM_Init() has been called, else FALSE.
*/ 
#define IPDUM_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(IpduM_InitializedType, IPDUM_VAR_CLEARED) IpduM_Initialized;
#define IPDUM_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_RxBuffer
**********************************************************************************************************************/
/** 
  \var    IpduM_RxBuffer
  \brief  buffer to de-multiplex and forward RX static and dynamic parts from the received multiplex I-PDU.
*/ 
#define IPDUM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(IpduM_RxBufferUType, IPDUM_VAR_NO_INIT) IpduM_RxBuffer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define IPDUM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
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


#endif  /* IPDUM_LCFG_H */
/**********************************************************************************************************************
  END OF FILE: IpduM_Lcfg.h
**********************************************************************************************************************/

