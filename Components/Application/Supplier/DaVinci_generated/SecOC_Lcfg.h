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
 *            Module: SecOC
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SecOC_Lcfg.h
 *   Generation Time: 2023-07-10 14:36:08
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/



#if !defined (SECOC_LCFG_H)
# define SECOC_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "SecOC_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/* Freshness Management function names */
#define GetTxFreshnessTruncData_FuncName  Rte_Call_FreshnessManagement_GetTxFreshnessTruncData
#define GetTxFreshness_FuncName           Rte_Call_FreshnessManagement_GetTxFreshness
#define SPduTxConfirmation_FuncName       Rte_Call_FreshnessManagement_SPduTxConfirmation
#define GetRxFreshness_FuncName           Rte_Call_FreshnessManagement_GetRxFreshness
#define GetRxFreshnessAuthData_FuncName   Rte_Call_FreshnessManagement_GetRxFreshnessAuthData

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SecOCPCDataSwitches  SecOC Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define SECOC_AUTHENTICPDUDATACONTAINER                                                             STD_ON
#define SECOC_AUTHENTICSPLITPDUTRANSMIT                                                             STD_OFF  /**< Deactivateable: 'SecOC_AuthenticSplitPduTransmit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICATORCACHE                                                                    STD_ON
#define SECOC_CANFDLENGTHCOMPVALUEINFO                                                              STD_OFF  /**< Deactivateable: 'SecOC_CanFDLengthCompValueInfo' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCCanFdPadding] is configured to 'false'' */
#define SECOC_LOWERLENGTHVALUEOFCANFDLENGTHCOMPVALUEINFO                                            STD_OFF  /**< Deactivateable: 'SecOC_CanFDLengthCompValueInfo.LowerLengthValue' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCCanFdPadding] is configured to 'false'' */
#define SECOC_UPPERLENGTHVALUEOFCANFDLENGTHCOMPVALUEINFO                                            STD_OFF  /**< Deactivateable: 'SecOC_CanFDLengthCompValueInfo.UpperLengthValue' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCCanFdPadding] is configured to 'false'' */
#define SECOC_CANCELTXTRANSMIT                                                                      STD_OFF  /**< Deactivateable: 'SecOC_CancelTxTransmit' Reason: '/ActiveEcuC/PduR/SecOc[0:PduRCancelTransmit] is configured to 'false'' */
#define SECOC_CRYPTOGRAPHICPDUTRANSMIT                                                              STD_OFF  /**< Deactivateable: 'SecOC_CryptographicPduTransmit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_CURRENTMESSAGELINKER                                                                  STD_OFF  /**< Deactivateable: 'SecOC_CurrentMessageLinker' Reason: 'The Parameter SecOCMaxMessageLinkerSizeOfRxPdus is == 0, so no Messagelinker is required.' */
#define SECOC_DEVMODEENABLED                                                                        STD_OFF  /**< Deactivateable: 'SecOC_DevModeEnabled' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCEnableDevelopmentMode] is configured to 'false'' */
#define SECOC_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'SecOC_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SECOC_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'SecOC_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SECOC_INITIALIZED                                                                           STD_ON
#define SECOC_NUMBEROFMESSAGESTOOVERRIDE                                                            STD_ON
#define SECOC_PDUSWITHQUEUES                                                                        STD_OFF  /**< Deactivateable: 'SecOC_PdusWithQueues' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SECOC_QUEUEELEMENTINFOENDIDXOFPDUSWITHQUEUES                                                STD_OFF  /**< Deactivateable: 'SecOC_PdusWithQueues.QueueElementInfoEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_QUEUEELEMENTINFOLENGTHOFPDUSWITHQUEUES                                                STD_OFF  /**< Deactivateable: 'SecOC_PdusWithQueues.QueueElementInfoLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_QUEUEELEMENTINFOSTARTIDXOFPDUSWITHQUEUES                                              STD_OFF  /**< Deactivateable: 'SecOC_PdusWithQueues.QueueElementInfoStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_QUEUEARRAY                                                                            STD_OFF  /**< Deactivateable: 'SecOC_QueueArray' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_QUEUEELEMENTINFO                                                                      STD_OFF  /**< Deactivateable: 'SecOC_QueueElementInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SECOC_QUEUEARRAYENDIDXOFQUEUEELEMENTINFO                                                    STD_OFF  /**< Deactivateable: 'SecOC_QueueElementInfo.QueueArrayEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_QUEUEARRAYLENGTHOFQUEUEELEMENTINFO                                                    STD_OFF  /**< Deactivateable: 'SecOC_QueueElementInfo.QueueArrayLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_QUEUEARRAYSTARTIDXOFQUEUEELEMENTINFO                                                  STD_OFF  /**< Deactivateable: 'SecOC_QueueElementInfo.QueueArrayStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_QUEUEDELEMENTLENGTH                                                                   STD_OFF  /**< Deactivateable: 'SecOC_QueuedElementLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_READIDXQUEUEELEMENT                                                                   STD_OFF  /**< Deactivateable: 'SecOC_ReadIdxQueueElement' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_RXAUTHENTICPDUSIZEOFFSET                                                              STD_ON
#define SECOC_RXBUILDATTEMPTSCOUNTER                                                                STD_ON
#define SECOC_RXCSMJOBTIMEOUTCNTVALUE                                                               STD_OFF  /**< Deactivateable: 'SecOC_RxCSMJobTimeoutCntValue' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCEnableAsyncCSMJobTimeout] is configured to 'false'' */
#define SECOC_RXIMMEDIATEPROCESSINGONGOING                                                          STD_OFF  /**< Deactivateable: 'SecOC_RxImmediateProcessingOngoing' Reason: 'Neither immediate Rx callback processing nor immediate Rx Pdu processing is configured.' */
#define SECOC_RXPDUINFO                                                                             STD_ON
#define SECOC_AUTHDATAFRESHNESSLENOFRXPDUINFO                                                       STD_ON
#define SECOC_AUTHDATAFRESHNESSOFRXPDUINFO                                                          STD_ON
#define SECOC_AUTHDATAFRESHNESSSTARTBYTEPOSITIONOFRXPDUINFO                                         STD_ON
#define SECOC_AUTHINFOLENGTHOFRXPDUINFO                                                             STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.AuthInfoLength' Reason: 'Custom API is not configured.' */
#define SECOC_AUTHENTICEXTERNALIDOFRXPDUINFO                                                        STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATAENDIDXOFRXPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataEndIdx' Reason: 'the optional indirection is deactivated because AuthenticPduDataContainerAuthenticPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATALENGTHOFRXPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataLength' Reason: 'the optional indirection is deactivated because AuthenticPduDataContainerAuthenticPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATASTARTIDXOFRXPDUINFO                      STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataStartIdx' Reason: 'the optional indirection is deactivated because AuthenticPduDataContainerAuthenticPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATAUSEDOFRXPDUINFO                          STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataUsed' Reason: 'the optional indirection is deactivated because AuthenticPduDataContainerAuthenticPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                                STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDULENGTHOFRXPDUINFO                                STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                              STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUUSEDOFRXPDUINFO                                  STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATEENDIDXOFRXPDUINFO                          STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATELENGTHOFRXPDUINFO                          STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATESTARTIDXOFRXPDUINFO                        STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEENDIDXOFRXPDUINFO                        STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUELENGTHOFRXPDUINFO                        STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUESTARTIDXOFRXPDUINFO                      STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEUSEDOFRXPDUINFO                          STD_ON
#define SECOC_AUTHENTICATIONLAYERIDOFRXPDUINFO                                                      STD_ON
#define SECOC_AUTHENTICATORCACHEENDIDXOFRXPDUINFO                                                   STD_ON
#define SECOC_AUTHENTICATORCACHELENGTHOFRXPDUINFO                                                   STD_ON
#define SECOC_AUTHENTICATORCACHESTARTIDXOFRXPDUINFO                                                 STD_ON
#define SECOC_BUILDATTEMPTSOFRXPDUINFO                                                              STD_ON
#define SECOC_CLIENTSERVERVERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                              STD_ON
#define SECOC_CONTAINERHEADERSIZEOFRXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.ContainerHeaderSize' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCCanFdPadding] is configured to 'false'' */
#define SECOC_CSMJOBTIMEOUTCNTOFRXPDUINFO                                                           STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.CsmJobTimeoutCnt' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCEnableAsyncCSMJobTimeout] is configured to 'false'' */
#define SECOC_DATAIDFIRSTBYTEOFRXPDUINFO                                                            STD_ON
#define SECOC_DATAIDOFRXPDUINFO                                                                     STD_ON
#define SECOC_DATAIDSECONDBYTEOFRXPDUINFO                                                           STD_ON
#define SECOC_EXTERNALFRESHNESSIDOFRXPDUINFO                                                        STD_ON
#define SECOC_IMMEDIATECBKPROCESSINGOFRXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.ImmediateCbkProcessing' Reason: 'the value of SecOC_ImmediateCbkProcessingOfRxPduInfo is always 'false' due to this, the array is deactivated.' */
#define SECOC_NUMBEROFMESSAGESTOOVERRIDEIDXOFRXPDUINFO                                              STD_ON
#define SECOC_PDUPROCESSINGOFRXPDUINFO                                                              STD_ON
#define SECOC_PDUTYPEOFRXPDUINFO                                                                    STD_ON
#define SECOC_PDUSWITHQUEUESIDXOFRXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.PdusWithQueuesIdx' Reason: 'the optional indirection is deactivated because PdusWithQueuesUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_PDUSWITHQUEUESUSEDOFRXPDUINFO                                                         STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.PdusWithQueuesUsed' Reason: 'the optional indirection is deactivated because PdusWithQueuesUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_RXSECUREDPDUAREAINFOIDXOFRXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.RxSecuredPduAreaInfoIdx' Reason: 'the optional indirection is deactivated because RxSecuredPduAreaInfoUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_RXSECUREDPDUAREAINFOUSEDOFRXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.RxSecuredPduAreaInfoUsed' Reason: 'the optional indirection is deactivated because RxSecuredPduAreaInfoUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_RXSECUREDPDUINFOIDXOFRXPDUINFO                                                        STD_ON
#define SECOC_RXSPLITMESSAGECOUNTERIDXOFRXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.RxSplitMessageCounterIdx' Reason: 'the optional indirection is deactivated because RxSplitMessageCounterUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_RXSPLITMESSAGECOUNTERUSEDOFRXPDUINFO                                                  STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.RxSplitMessageCounterUsed' Reason: 'the optional indirection is deactivated because RxSplitMessageCounterUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDULENGTHOFRXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                                STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDUUSEDOFRXPDUINFO                                    STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATAENDIDXOFRXPDUINFO                            STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataEndIdx' Reason: 'the optional indirection is deactivated because SecuredPduDataContainerSecuredPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATALENGTHOFRXPDUINFO                            STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataLength' Reason: 'the optional indirection is deactivated because SecuredPduDataContainerSecuredPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATASTARTIDXOFRXPDUINFO                          STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataStartIdx' Reason: 'the optional indirection is deactivated because SecuredPduDataContainerSecuredPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATAUSEDOFRXPDUINFO                              STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataUsed' Reason: 'the optional indirection is deactivated because SecuredPduDataContainerSecuredPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUENDIDXOFRXPDUINFO                                    STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDULENGTHOFRXPDUINFO                                    STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUSTARTIDXOFRXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUUSEDOFRXPDUINFO                                      STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTPSECUREDPDUENDIDXOFRXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTPSECUREDPDULENGTHOFRXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTPSECUREDPDUSTARTIDXOFRXPDUINFO                                STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTPSECUREDPDUUSEDOFRXPDUINFO                                    STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORENDIDXOFRXPDUINFO                        STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORLENGTHOFRXPDUINFO                        STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORSTARTIDXOFRXPDUINFO                      STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORUSEDOFRXPDUINFO                          STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEENDIDXOFRXPDUINFO                       STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUELENGTHOFRXPDUINFO                       STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUESTARTIDXOFRXPDUINFO                     STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEUSEDOFRXPDUINFO                         STD_ON
#define SECOC_SECUREDRXPDUVERFICATIONOFRXPDUINFO                                                    STD_ON
#define SECOC_TRUNCAUTHSTARTBITINBYTEOFRXPDUINFO                                                    STD_ON
#define SECOC_TRUNCFRESHNESSVALUEFIRSTBYTESHIFTOFRXPDUINFO                                          STD_ON
#define SECOC_TRUNCFRESHNESSVALUESECONDBYTESHIFTOFRXPDUINFO                                         STD_ON
#define SECOC_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                                          STD_ON
#define SECOC_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO                            STD_ON
#define SECOC_VERIFYATTEMPTSOFRXPDUINFO                                                             STD_ON
#define SECOC_VERIFYOVERRIDESTATUSIDXOFRXPDUINFO                                                    STD_ON
#define SECOC_VERIFYRESULTIDXOFRXPDUINFO                                                            STD_ON
#define SECOC_WAITFORCALLBACKOFRXPDUINFO                                                            STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.WaitForCallback' Reason: 'the value of SecOC_WaitForCallbackOfRxPduInfo is always 'false' due to this, the array is deactivated.' */
#define SECOC_TRUNCATEDAUTHENTICATIONLENGTHOFRXPDUINFO                                              STD_ON
#define SECOC_TRUNCATEDFRESHNESSVALUELENGTHOFRXPDUINFO                                              STD_ON
#define SECOC_RXPDUSTATE                                                                            STD_ON
#define SECOC_RXSECUREDPDUAREABUFFER                                                                STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduAreaBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_RXSECUREDPDUAREAINFO                                                                  STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduAreaInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SECOC_LENGTHOFRXSECUREDPDUAREAINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduAreaInfo.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_OFFSETOFRXSECUREDPDUAREAINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduAreaInfo.Offset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_RXSECUREDPDUINFO                                                                      STD_ON
#define SECOC_AUTHHEADERLENGTHOFRXSECUREDPDUINFO                                                    STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.AuthHeaderLength' Reason: 'the value of SecOC_AuthHeaderLengthOfRxSecuredPduInfo is always '0' due to this, the array is deactivated.' */
#define SECOC_CURRENTMESSAGELINKERENDIDXOFRXSECUREDPDUINFO                                          STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.CurrentMessageLinkerEndIdx' Reason: 'The Parameter SecOCMaxMessageLinkerSizeOfRxPdus is == 0, so no Messagelinker is required.' */
#define SECOC_CURRENTMESSAGELINKERLENGTHOFRXSECUREDPDUINFO                                          STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.CurrentMessageLinkerLength' Reason: 'The Parameter SecOCMaxMessageLinkerSizeOfRxPdus is == 0, so no Messagelinker is required.' */
#define SECOC_CURRENTMESSAGELINKERSTARTIDXOFRXSECUREDPDUINFO                                        STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.CurrentMessageLinkerStartIdx' Reason: 'The Parameter SecOCMaxMessageLinkerSizeOfRxPdus is == 0, so no Messagelinker is required.' */
#define SECOC_CURRENTMESSAGELINKERUSEDOFRXSECUREDPDUINFO                                            STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.CurrentMessageLinkerUsed' Reason: 'The Parameter SecOCMaxMessageLinkerSizeOfRxPdus is == 0, so no Messagelinker is required.' */
#define SECOC_INVALIDHNDOFRXSECUREDPDUINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.InvalidHnd' Reason: 'the value of SecOC_InvalidHndOfRxSecuredPduInfo is always 'false' due to this, the array is deactivated.' */
#define SECOC_MESSAGELINKLENOFRXSECUREDPDUINFO                                                      STD_ON
#define SECOC_MESSAGELINKPOSOFRXSECUREDPDUINFO                                                      STD_ON
#define SECOC_MESSAGELINKERSTARTBYTEINCRYPTOPDUOFRXSECUREDPDUINFO                                   STD_ON
#define SECOC_MESSAGETYPEOFRXSECUREDPDUINFO                                                         STD_ON
#define SECOC_MESSAGESLINKCRYPTOPDUSRCBITOFFSETOFRXSECUREDPDUINFO                                   STD_ON
#define SECOC_MINIMUMPDULENGTHOFRXSECUREDPDUINFO                                                    STD_ON
#define SECOC_PDUFIXLENGTHOFRXSECUREDPDUINFO                                                        STD_ON
#define SECOC_RXPDUINFOIDXOFRXSECUREDPDUINFO                                                        STD_ON
#define SECOC_RXSPLITMESSAGECOUNTERIDXOFRXSECUREDPDUINFO                                            STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.RxSplitMessageCounterIdx' Reason: 'the optional indirection is deactivated because RxSplitMessageCounterUsedOfRxSecuredPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_RXSPLITMESSAGECOUNTERUSEDOFRXSECUREDPDUINFO                                           STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.RxSplitMessageCounterUsed' Reason: 'the optional indirection is deactivated because RxSplitMessageCounterUsedOfRxSecuredPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERENDIDXOFRXSECUREDPDUINFO                                       STD_ON
#define SECOC_SECUREDPDUDATACONTAINERLENGTHOFRXSECUREDPDUINFO                                       STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSTARTIDXOFRXSECUREDPDUINFO                                     STD_ON
#define SECOC_RXSPLITMESSAGECOUNTER                                                                 STD_OFF  /**< Deactivateable: 'SecOC_RxSplitMessageCounter' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_RXTPWRITTENBYTESCOUNTER                                                               STD_ON
#define SECOC_SECUREDPDUDATACONTAINER                                                               STD_ON
#define SECOC_SENDDEFAULTAUTHENTICATION                                                             STD_OFF  /**< Deactivateable: 'SecOC_SendDefaultAuthentication' Reason: 'Rx only or neither SecOCDefaultAuthenticationInformationPattern nor SecOCEnableDevelopmentMode is configured' */
#define SECOC_SIZEOFAUTHENTICPDUDATACONTAINER                                                       STD_ON
#define SECOC_SIZEOFAUTHENTICATORCACHE                                                              STD_ON
#define SECOC_SIZEOFNUMBEROFMESSAGESTOOVERRIDE                                                      STD_ON
#define SECOC_SIZEOFRXAUTHENTICPDUSIZEOFFSET                                                        STD_ON
#define SECOC_SIZEOFRXBUILDATTEMPTSCOUNTER                                                          STD_ON
#define SECOC_SIZEOFRXPDUINFO                                                                       STD_ON
#define SECOC_SIZEOFRXPDUSTATE                                                                      STD_ON
#define SECOC_SIZEOFRXSECUREDPDUINFO                                                                STD_ON
#define SECOC_SIZEOFRXTPWRITTENBYTESCOUNTER                                                         STD_ON
#define SECOC_SIZEOFSECUREDPDUDATACONTAINER                                                         STD_ON
#define SECOC_SIZEOFVERIFYATTEMPTSCOUNTER                                                           STD_ON
#define SECOC_SIZEOFVERIFYOVERRIDESTATUS                                                            STD_ON
#define SECOC_SIZEOFVERIFYRESULT                                                                    STD_ON
#define SECOC_TRANSMITREQUEST                                                                       STD_OFF  /**< Deactivateable: 'SecOC_TransmitRequest' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXAUTHENTICPDUINFO                                                                    STD_OFF  /**< Deactivateable: 'SecOC_TxAuthenticPduInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SECOC_INVALIDHNDOFTXAUTHENTICPDUINFO                                                        STD_OFF  /**< Deactivateable: 'SecOC_TxAuthenticPduInfo.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_MINIMUMPDULENGTHOFTXAUTHENTICPDUINFO                                                  STD_OFF  /**< Deactivateable: 'SecOC_TxAuthenticPduInfo.MinimumPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXPDUINFOIDXOFTXAUTHENTICPDUINFO                                                      STD_OFF  /**< Deactivateable: 'SecOC_TxAuthenticPduInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXAUTHENTICPDUSIZEOFFSET                                                              STD_OFF  /**< Deactivateable: 'SecOC_TxAuthenticPduSizeOffset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXBUILDATTEMPTSCOUNTER                                                                STD_OFF  /**< Deactivateable: 'SecOC_TxBuildAttemptsCounter' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXCSMJOBTIMEOUTCNTVALUE                                                               STD_OFF  /**< Deactivateable: 'SecOC_TxCSMJobTimeoutCntValue' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCEnableAsyncCSMJobTimeout] is configured to 'false'' */
#define SECOC_TXIMMEDIATEPROCESSINGONGOING                                                          STD_OFF  /**< Deactivateable: 'SecOC_TxImmediateProcessingOngoing' Reason: 'Neither immediate Tx callback processing nor immediate Tx Pdu processing is configured.' */
#define SECOC_TXPDUINFO                                                                             STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SECOC_ADDCANFDCONTAINERPDUPADDINGOFTXPDUINFO                                                STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AddCANFDContainerPduPadding' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCCanFdPadding] is configured to 'false'' */
#define SECOC_AUTHINFOLENGTHOFTXPDUINFO                                                             STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthInfoLength' Reason: 'Custom API is not configured.' */
#define SECOC_AUTHENTICEXTERNALIDOFTXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticExternalId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATAENDIDXOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATALENGTHOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATASTARTIDXOFTXPDUINFO                      STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATAUSEDOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFTXPDUINFO                                STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerAuthenticPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDULENGTHOFTXPDUINFO                                STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerAuthenticPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFTXPDUINFO                              STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerAuthenticPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUUSEDOFTXPDUINFO                                  STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerAuthenticPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATEENDIDXOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerDataToAuthenticateEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATELENGTHOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerDataToAuthenticateLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATESTARTIDXOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerDataToAuthenticateStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEENDIDXOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerFreshnessVerifyValueEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUELENGTHOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerFreshnessVerifyValueLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUESTARTIDXOFTXPDUINFO                      STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerFreshnessVerifyValueStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEUSEDOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerFreshnessVerifyValueUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUENDIDXOFTXPDUINFO                            STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerFullAuthenticPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDULENGTHOFTXPDUINFO                            STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerFullAuthenticPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUSTARTIDXOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerFullAuthenticPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUUSEDOFTXPDUINFO                              STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerFullAuthenticPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICATIONLAYERIDOFTXPDUINFO                                                      STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticationLayerId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICATORCACHEENDIDXOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticatorCacheEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICATORCACHELENGTHOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticatorCacheLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICATORCACHESTARTIDXOFTXPDUINFO                                                 STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticatorCacheStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_BUILDATTEMPTSOFTXPDUINFO                                                              STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.BuildAttempts' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_CONFIRMATIONNEEDEDOFTXPDUINFO                                                         STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.ConfirmationNeeded' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_CSMJOBTIMEOUTCNTOFTXPDUINFO                                                           STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.CsmJobTimeoutCnt' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCEnableAsyncCSMJobTimeout] is configured to 'false'' */
#define SECOC_DATAIDFIRSTBYTEOFTXPDUINFO                                                            STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.DataIdFirstByte' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_DATAIDSECONDBYTEOFTXPDUINFO                                                           STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.DataIdSecondByte' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXTERNALFRESHNESSIDOFTXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.ExternalFreshnessId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_IMMEDIATECBKPROCESSINGOFTXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.ImmediateCbkProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_LOWERLAYERPDUTYPEOFTXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.LowerLayerPduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_PDUPROCESSINGOFTXPDUINFO                                                              STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.PduProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_PDUTYPEOFTXPDUINFO                                                                    STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.PduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.ProvideTruncTxFreshness' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SPDUTXCONFIRMATIONNEEDEDOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SPduTxConfirmationNeeded' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDEXTERNALIDOFTXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredExternalId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHINFODATAENDIDXOFTXPDUINFO                                  STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthInfoDataEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHINFODATALENGTHOFTXPDUINFO                                  STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthInfoDataLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHINFODATASTARTIDXOFTXPDUINFO                                STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthInfoDataStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHINFODATAUSEDOFTXPDUINFO                                    STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthInfoDataUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHPDUHEADERLENGTHENDIDXOFTXPDUINFO                           STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthPduHeaderLengthEndIdx' Reason: 'no AuthPduHeaderLength is configured for tx pdus' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHPDUHEADERLENGTHLENGTHOFTXPDUINFO                           STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthPduHeaderLengthLength' Reason: 'no AuthPduHeaderLength is configured for tx pdus' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHPDUHEADERLENGTHSTARTIDXOFTXPDUINFO                         STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthPduHeaderLengthStartIdx' Reason: 'no AuthPduHeaderLength is configured for tx pdus' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHPDUHEADERLENGTHUSEDOFTXPDUINFO                             STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthPduHeaderLengthUsed' Reason: 'no AuthPduHeaderLength is configured for tx pdus' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFTXPDUINFO                                  STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthenticPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDULENGTHOFTXPDUINFO                                  STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthenticPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFTXPDUINFO                                STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthenticPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDUUSEDOFTXPDUINFO                                    STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthenticPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATAENDIDXOFTXPDUINFO                            STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATALENGTHOFTXPDUINFO                            STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATASTARTIDXOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATAUSEDOFTXPDUINFO                              STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUENDIDXOFTXPDUINFO                                    STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerSecuredPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDULENGTHOFTXPDUINFO                                    STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerSecuredPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUSTARTIDXOFTXPDUINFO                                  STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerSecuredPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUUSEDOFTXPDUINFO                                      STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerSecuredPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORENDIDXOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerTruncatedAuthenticatorEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORLENGTHOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerTruncatedAuthenticatorLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORSTARTIDXOFTXPDUINFO                      STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerTruncatedAuthenticatorStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORUSEDOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerTruncatedAuthenticatorUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEENDIDXOFTXPDUINFO                       STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerTruncatedFreshnessValueEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUELENGTHOFTXPDUINFO                       STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerTruncatedFreshnessValueLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUESTARTIDXOFTXPDUINFO                     STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerTruncatedFreshnessValueStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEUSEDOFTXPDUINFO                         STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerTruncatedFreshnessValueUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TRUNCAUTHSTARTBITINBYTEOFTXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.TruncAuthStartBitInByte' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TRUNCFRESHNESSVALUEFIRSTBYTESHIFTOFTXPDUINFO                                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.TruncFreshnessValueFirstByteShift' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TRUNCFRESHNESSVALUESECONDBYTESHIFTOFTXPDUINFO                                         STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.TruncFreshnessValueSecondByteShift' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXSECUREDPDUAREAINFOIDXOFTXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.TxSecuredPduAreaInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXSECUREDPDUAREAINFOUSEDOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.TxSecuredPduAreaInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXSPLITPDUINFOIDXOFTXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.TxSplitPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXSPLITPDUINFOUSEDOFTXPDUINFO                                                         STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.TxSplitPduInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_WAITFORCALLBACKOFTXPDUINFO                                                            STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.WaitForCallback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TRUNCATEDAUTHENTICATIONLENGTHOFTXPDUINFO                                              STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.truncatedAuthenticationLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TRUNCATEDFRESHNESSVALUELENGTHOFTXPDUINFO                                              STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.truncatedFreshnessValueLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXPDUSTATE                                                                            STD_OFF  /**< Deactivateable: 'SecOC_TxPduState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXRESULTLENGTH                                                                        STD_OFF  /**< Deactivateable: 'SecOC_TxResultLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXSECUREDPDUAREABUFFER                                                                STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduAreaBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXSECUREDPDUAREAINFO                                                                  STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduAreaInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SECOC_LENGTHOFTXSECUREDPDUAREAINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduAreaInfo.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_OFFSETOFTXSECUREDPDUAREAINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduAreaInfo.Offset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXSECUREDPDUINFO                                                                      STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SECOC_INVALIDHNDOFTXSECUREDPDUINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduInfo.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXPDUINFOIDXOFTXSECUREDPDUINFO                                                        STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                                    STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduInfo.TxSecuredPduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXSPLITMESSAGECOUNTER                                                                 STD_OFF  /**< Deactivateable: 'SecOC_TxSplitMessageCounter' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXSPLITPDUINFO                                                                        STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SECOC_AUTHSPLITPDUEXTERNALIDOFTXSPLITPDUINFO                                                STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.AuthSplitPduExternalId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_CYPTOGRAPHICPDUEXTERNALIDOFTXSPLITPDUINFO                                             STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.CyptographicPduExternalId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_MESSAGELINKLENOFTXSPLITPDUINFO                                                        STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.MessageLinkLen' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_MESSAGELINKPOSOFTXSPLITPDUINFO                                                        STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.MessageLinkPos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_MESSAGESLINKCRYPTOPDUDESTBITOFFSETOFTXSPLITPDUINFO                                    STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.MessagesLinkCryptoPduDestBitOffset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICSPLITPDUENDIDXOFTXSPLITPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerAuthenticSplitPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICSPLITPDULENGTHOFTXSPLITPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerAuthenticSplitPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICSPLITPDUSTARTIDXOFTXSPLITPDUINFO                      STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerAuthenticSplitPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERCRYPTOGRAPHICPDUENDIDXOFTXSPLITPDUINFO                         STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerCryptographicPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERCRYPTOGRAPHICPDULENGTHOFTXSPLITPDUINFO                         STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerCryptographicPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERCRYPTOGRAPHICPDUSTARTIDXOFTXSPLITPDUINFO                       STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerCryptographicPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERAUTHSPLITPDUENDIDXOFTXSPLITPDUINFO                STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerAuthSplitPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERAUTHSPLITPDULENGTHOFTXSPLITPDUINFO                STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerAuthSplitPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERAUTHSPLITPDUSTARTIDXOFTXSPLITPDUINFO              STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerAuthSplitPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERAUTHSPLITPDUUSEDOFTXSPLITPDUINFO                  STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerAuthSplitPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERCRYPTOPDUENDIDXOFTXSPLITPDUINFO                   STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerCryptoPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERCRYPTOPDULENGTHOFTXSPLITPDUINFO                   STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerCryptoPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERCRYPTOPDUSTARTIDXOFTXSPLITPDUINFO                 STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerCryptoPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERCRYPTOPDUUSEDOFTXSPLITPDUINFO                     STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerCryptoPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXTPWRITTENBYTESCOUNTER                                                               STD_OFF  /**< Deactivateable: 'SecOC_TxTpWrittenBytesCounter' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_VERIFICATIONSTATUSCALLOUT                                                             STD_OFF  /**< Deactivateable: 'SecOC_VerificationStatusCallout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_VERIFICATIONSTATUSCALLOUTWITHSECUREDPDU                                               STD_OFF  /**< Deactivateable: 'SecOC_VerificationStatusCalloutWithSecuredPdu' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_VERIFYATTEMPTSCOUNTER                                                                 STD_ON
#define SECOC_VERIFYOVERRIDESTATUS                                                                  STD_ON
#define SECOC_VERIFYRESULT                                                                          STD_ON
#define SECOC_WRITEIDXQUEUEELEMENT                                                                  STD_OFF  /**< Deactivateable: 'SecOC_WriteIdxQueueElement' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_PCCONFIG                                                                              STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINEROFPCCONFIG                                                   STD_ON
#define SECOC_AUTHENTICATORCACHEOFPCCONFIG                                                          STD_ON
#define SECOC_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'SecOC_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SECOC_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'SecOC_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SECOC_INITIALIZEDOFPCCONFIG                                                                 STD_ON
#define SECOC_NUMBEROFMESSAGESTOOVERRIDEOFPCCONFIG                                                  STD_ON
#define SECOC_RXAUTHENTICPDUSIZEOFFSETOFPCCONFIG                                                    STD_ON
#define SECOC_RXBUILDATTEMPTSCOUNTEROFPCCONFIG                                                      STD_ON
#define SECOC_RXPDUINFOOFPCCONFIG                                                                   STD_ON
#define SECOC_RXPDUSTATEOFPCCONFIG                                                                  STD_ON
#define SECOC_RXSECUREDPDUINFOOFPCCONFIG                                                            STD_ON
#define SECOC_RXTPWRITTENBYTESCOUNTEROFPCCONFIG                                                     STD_ON
#define SECOC_SECUREDPDUDATACONTAINEROFPCCONFIG                                                     STD_ON
#define SECOC_SIZEOFAUTHENTICPDUDATACONTAINEROFPCCONFIG                                             STD_ON
#define SECOC_SIZEOFAUTHENTICATORCACHEOFPCCONFIG                                                    STD_ON
#define SECOC_SIZEOFNUMBEROFMESSAGESTOOVERRIDEOFPCCONFIG                                            STD_ON
#define SECOC_SIZEOFRXAUTHENTICPDUSIZEOFFSETOFPCCONFIG                                              STD_ON
#define SECOC_SIZEOFRXBUILDATTEMPTSCOUNTEROFPCCONFIG                                                STD_ON
#define SECOC_SIZEOFRXPDUINFOOFPCCONFIG                                                             STD_ON
#define SECOC_SIZEOFRXPDUSTATEOFPCCONFIG                                                            STD_ON
#define SECOC_SIZEOFRXSECUREDPDUINFOOFPCCONFIG                                                      STD_ON
#define SECOC_SIZEOFRXTPWRITTENBYTESCOUNTEROFPCCONFIG                                               STD_ON
#define SECOC_SIZEOFSECUREDPDUDATACONTAINEROFPCCONFIG                                               STD_ON
#define SECOC_SIZEOFVERIFYATTEMPTSCOUNTEROFPCCONFIG                                                 STD_ON
#define SECOC_SIZEOFVERIFYOVERRIDESTATUSOFPCCONFIG                                                  STD_ON
#define SECOC_SIZEOFVERIFYRESULTOFPCCONFIG                                                          STD_ON
#define SECOC_VERIFYATTEMPTSCOUNTEROFPCCONFIG                                                       STD_ON
#define SECOC_VERIFYOVERRIDESTATUSOFPCCONFIG                                                        STD_ON
#define SECOC_VERIFYRESULTOFPCCONFIG                                                                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCMinNumericValueDefines  SecOC Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define SECOC_MIN_AUTHENTICPDUDATACONTAINER                                                         0u
#define SECOC_MIN_AUTHENTICATORCACHE                                                                0u
#define SECOC_MIN_NUMBEROFMESSAGESTOOVERRIDE                                                        0u
#define SECOC_MIN_RXAUTHENTICPDUSIZEOFFSET                                                          0u
#define SECOC_MIN_RXBUILDATTEMPTSCOUNTER                                                            0u
#define SECOC_MIN_RXTPWRITTENBYTESCOUNTER                                                           0u
#define SECOC_MIN_SECUREDPDUDATACONTAINER                                                           0u
#define SECOC_MIN_VERIFYATTEMPTSCOUNTER                                                             0u
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCMaxNumericValueDefines  SecOC Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define SECOC_MAX_AUTHENTICPDUDATACONTAINER                                                         255u
#define SECOC_MAX_AUTHENTICATORCACHE                                                                255u
#define SECOC_MAX_NUMBEROFMESSAGESTOOVERRIDE                                                        255u
#define SECOC_MAX_RXAUTHENTICPDUSIZEOFFSET                                                          65535u
#define SECOC_MAX_RXBUILDATTEMPTSCOUNTER                                                            65535u
#define SECOC_MAX_RXTPWRITTENBYTESCOUNTER                                                           65535u
#define SECOC_MAX_SECUREDPDUDATACONTAINER                                                           255u
#define SECOC_MAX_VERIFYATTEMPTSCOUNTER                                                             65535u
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCNoReferenceDefines  SecOC No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define SECOC_NO_AUTHENTICEXTERNALIDOFRXPDUINFO                                                     255u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                             255u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                           255u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEENDIDXOFRXPDUINFO                     255u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUESTARTIDXOFRXPDUINFO                   255u
#define SECOC_NO_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                               255u
#define SECOC_NO_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                             255u
#define SECOC_NO_SECUREDPDUDATACONTAINERSECUREDPDUENDIDXOFRXPDUINFO                                 255u
#define SECOC_NO_SECUREDPDUDATACONTAINERSECUREDPDUSTARTIDXOFRXPDUINFO                               255u
#define SECOC_NO_SECUREDPDUDATACONTAINERTPSECUREDPDUENDIDXOFRXPDUINFO                               255u
#define SECOC_NO_SECUREDPDUDATACONTAINERTPSECUREDPDUSTARTIDXOFRXPDUINFO                             255u
#define SECOC_NO_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORENDIDXOFRXPDUINFO                     255u
#define SECOC_NO_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORSTARTIDXOFRXPDUINFO                   255u
#define SECOC_NO_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEENDIDXOFRXPDUINFO                    255u
#define SECOC_NO_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUESTARTIDXOFRXPDUINFO                  255u
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCEnumExistsDefines  SecOC Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define SECOC_EXISTS_USE_AUTHDATAFRESHNESSOFRXPDUINFO                                               STD_OFF
#define SECOC_EXISTS_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO                                          STD_ON
#define SECOC_EXISTS_BOTH_CLIENTSERVERVERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                  STD_OFF
#define SECOC_EXISTS_FAILURE_ONLY_CLIENTSERVERVERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO          STD_ON
#define SECOC_EXISTS_NONE_CLIENTSERVERVERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                  STD_OFF
#define SECOC_EXISTS_IMMEDIATE_PDUPROCESSINGOFRXPDUINFO                                             STD_OFF
#define SECOC_EXISTS_DEFERRED_PDUPROCESSINGOFRXPDUINFO                                              STD_ON
#define SECOC_EXISTS_IFPDU_PDUTYPEOFRXPDUINFO                                                       STD_ON
#define SECOC_EXISTS_TPPDU_PDUTYPEOFRXPDUINFO                                                       STD_OFF
#define SECOC_EXISTS_CRYPTO_PDUTYPEOFRXPDUINFO                                                      STD_OFF
#define SECOC_EXISTS_AUTHENTIC_PDUTYPEOFRXPDUINFO                                                   STD_OFF
#define SECOC_EXISTS_NORMAL_PDUTYPEOFRXPDUINFO                                                      STD_OFF
#define SECOC_EXISTS_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                              STD_OFF
#define SECOC_EXISTS_FAILURE_ONLY_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                      STD_ON
#define SECOC_EXISTS_NONE_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                              STD_OFF
#define SECOC_EXISTS_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO                STD_OFF
#define SECOC_EXISTS_FAILURE_ONLY_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO        STD_OFF
#define SECOC_EXISTS_NONE_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO                STD_ON
#define SECOC_EXISTS_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO                                           STD_ON
#define SECOC_EXISTS_AUTHENTIC_SPLIT_MESSAGETYPEOFRXSECUREDPDUINFO                                  STD_OFF
#define SECOC_EXISTS_CRYPTOGRAPHIC_MESSAGETYPEOFRXSECUREDPDUINFO                                    STD_OFF
#define SECOC_EXISTS_IFPDU_LOWERLAYERPDUTYPEOFTXPDUINFO                                             STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.LowerLayerPduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_TPPDU_LOWERLAYERPDUTYPEOFTXPDUINFO                                             STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.LowerLayerPduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_CRYPTO_LOWERLAYERPDUTYPEOFTXPDUINFO                                            STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.LowerLayerPduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_AUTHENTIC_LOWERLAYERPDUTYPEOFTXPDUINFO                                         STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.LowerLayerPduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_NORMAL_LOWERLAYERPDUTYPEOFTXPDUINFO                                            STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.LowerLayerPduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_IMMEDIATE_PDUPROCESSINGOFTXPDUINFO                                             STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.PduProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_DEFERRED_PDUPROCESSINGOFTXPDUINFO                                              STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.PduProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_IFPDU_PDUTYPEOFTXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.PduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_TPPDU_PDUTYPEOFTXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.PduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_CRYPTO_PDUTYPEOFTXPDUINFO                                                      STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.PduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_AUTHENTIC_PDUTYPEOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.PduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_NORMAL_PDUTYPEOFTXPDUINFO                                                      STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.PduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO                                     STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.ProvideTruncTxFreshness' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_DONT_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO                                STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.ProvideTruncTxFreshness' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_IFPDU_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                       STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduInfo.TxSecuredPduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_TPPDU_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                       STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduInfo.TxSecuredPduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_CRYPTO_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                      STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduInfo.TxSecuredPduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_AUTHENTIC_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                   STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduInfo.TxSecuredPduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_EXISTS_NORMAL_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                      STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduInfo.TxSecuredPduType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCEnumDefines  SecOC Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO                                                 0x01u
#define SECOC_FAILURE_ONLY_CLIENTSERVERVERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                 0x01u
#define SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO                                                     0x01u
#define SECOC_IFPDU_PDUTYPEOFRXPDUINFO                                                              0x00u
#define SECOC_FAILURE_ONLY_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                             0x01u
#define SECOC_NONE_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO                       0x02u
#define SECOC_IDLE_RXPDUSTATE                                                                       0x00u
#define SECOC_COPYING_RXPDUSTATE                                                                    0x01u
#define SECOC_VERIFIED_RXPDUSTATE                                                                   0x02u
#define SECOC_PRE_VERIFY_START_RXPDUSTATE                                                           0x06u
#define SECOC_COPY_AUTHENTIC_PDU_TO_DATA_TO_AUTHENTICATE_RXPDUSTATE                                 0x03u
#define SECOC_FRESHNESS_VALUE_NEEDED_RXPDUSTATE                                                     0x04u
#define SECOC_ABORTED_RXPDUSTATE                                                                    0x05u
#define SECOC_UNVERIFIED_RXPDUSTATE                                                                 0x10u
#define SECOC_UNVERIFIED_VERIFICATION_TO_BE_STARTED_RXPDUSTATE                                      0x10u
#define SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE                         0x07u
#define SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE                 0x16u
#define SECOC_UNVERIFIED_VERIFICATION_FINISHED_RXPDUSTATE                                           0x17u
#define SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO                                                  0x00u
#define SECOC_CANCEL_VERIFYOVERRIDESTATUS                                                           0x02u
#define SECOC_FAIL_N_TIMES_VERIFYOVERRIDESTATUS                                                     0x01u
#define SECOC_FAIL_INFINETE_VERIFYOVERRIDESTATUS                                                    0x00u
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCIsReducedToDefineDefines  SecOC Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define SECOC_ISDEF_AUTHDATAFRESHNESSLENOFRXPDUINFO                                                 STD_OFF
#define SECOC_ISDEF_AUTHDATAFRESHNESSOFRXPDUINFO                                                    STD_OFF
#define SECOC_ISDEF_AUTHDATAFRESHNESSSTARTBYTEPOSITIONOFRXPDUINFO                                   STD_OFF
#define SECOC_ISDEF_AUTHENTICEXTERNALIDOFRXPDUINFO                                                  STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                          STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERAUTHENTICPDULENGTHOFRXPDUINFO                          STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                        STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERAUTHENTICPDUUSEDOFRXPDUINFO                            STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATEENDIDXOFRXPDUINFO                    STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATELENGTHOFRXPDUINFO                    STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATESTARTIDXOFRXPDUINFO                  STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEENDIDXOFRXPDUINFO                  STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUELENGTHOFRXPDUINFO                  STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUESTARTIDXOFRXPDUINFO                STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEUSEDOFRXPDUINFO                    STD_OFF
#define SECOC_ISDEF_AUTHENTICATIONLAYERIDOFRXPDUINFO                                                STD_OFF
#define SECOC_ISDEF_AUTHENTICATORCACHEENDIDXOFRXPDUINFO                                             STD_OFF
#define SECOC_ISDEF_AUTHENTICATORCACHELENGTHOFRXPDUINFO                                             STD_OFF
#define SECOC_ISDEF_AUTHENTICATORCACHESTARTIDXOFRXPDUINFO                                           STD_OFF
#define SECOC_ISDEF_BUILDATTEMPTSOFRXPDUINFO                                                        STD_OFF
#define SECOC_ISDEF_CLIENTSERVERVERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                        STD_OFF
#define SECOC_ISDEF_DATAIDFIRSTBYTEOFRXPDUINFO                                                      STD_OFF
#define SECOC_ISDEF_DATAIDOFRXPDUINFO                                                               STD_OFF
#define SECOC_ISDEF_DATAIDSECONDBYTEOFRXPDUINFO                                                     STD_OFF
#define SECOC_ISDEF_EXTERNALFRESHNESSIDOFRXPDUINFO                                                  STD_OFF
#define SECOC_ISDEF_NUMBEROFMESSAGESTOOVERRIDEIDXOFRXPDUINFO                                        STD_OFF
#define SECOC_ISDEF_PDUPROCESSINGOFRXPDUINFO                                                        STD_OFF
#define SECOC_ISDEF_PDUTYPEOFRXPDUINFO                                                              STD_OFF
#define SECOC_ISDEF_RXSECUREDPDUINFOIDXOFRXPDUINFO                                                  STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHENTICPDULENGTHOFRXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                          STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHENTICPDUUSEDOFRXPDUINFO                              STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSECUREDPDUENDIDXOFRXPDUINFO                              STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSECUREDPDULENGTHOFRXPDUINFO                              STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSECUREDPDUSTARTIDXOFRXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSECUREDPDUUSEDOFRXPDUINFO                                STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTPSECUREDPDUENDIDXOFRXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTPSECUREDPDULENGTHOFRXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTPSECUREDPDUSTARTIDXOFRXPDUINFO                          STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTPSECUREDPDUUSEDOFRXPDUINFO                              STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORENDIDXOFRXPDUINFO                  STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORLENGTHOFRXPDUINFO                  STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORSTARTIDXOFRXPDUINFO                STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORUSEDOFRXPDUINFO                    STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEENDIDXOFRXPDUINFO                 STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUELENGTHOFRXPDUINFO                 STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUESTARTIDXOFRXPDUINFO               STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEUSEDOFRXPDUINFO                   STD_OFF
#define SECOC_ISDEF_SECUREDRXPDUVERFICATIONOFRXPDUINFO                                              STD_OFF
#define SECOC_ISDEF_TRUNCAUTHSTARTBITINBYTEOFRXPDUINFO                                              STD_OFF
#define SECOC_ISDEF_TRUNCFRESHNESSVALUEFIRSTBYTESHIFTOFRXPDUINFO                                    STD_OFF
#define SECOC_ISDEF_TRUNCFRESHNESSVALUESECONDBYTESHIFTOFRXPDUINFO                                   STD_OFF
#define SECOC_ISDEF_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                                    STD_OFF
#define SECOC_ISDEF_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO                      STD_OFF
#define SECOC_ISDEF_VERIFYATTEMPTSOFRXPDUINFO                                                       STD_OFF
#define SECOC_ISDEF_VERIFYOVERRIDESTATUSIDXOFRXPDUINFO                                              STD_OFF
#define SECOC_ISDEF_VERIFYRESULTIDXOFRXPDUINFO                                                      STD_OFF
#define SECOC_ISDEF_TRUNCATEDAUTHENTICATIONLENGTHOFRXPDUINFO                                        STD_OFF
#define SECOC_ISDEF_TRUNCATEDFRESHNESSVALUELENGTHOFRXPDUINFO                                        STD_OFF
#define SECOC_ISDEF_MESSAGELINKLENOFRXSECUREDPDUINFO                                                STD_OFF
#define SECOC_ISDEF_MESSAGELINKPOSOFRXSECUREDPDUINFO                                                STD_OFF
#define SECOC_ISDEF_MESSAGELINKERSTARTBYTEINCRYPTOPDUOFRXSECUREDPDUINFO                             STD_OFF
#define SECOC_ISDEF_MESSAGETYPEOFRXSECUREDPDUINFO                                                   STD_OFF
#define SECOC_ISDEF_MESSAGESLINKCRYPTOPDUSRCBITOFFSETOFRXSECUREDPDUINFO                             STD_OFF
#define SECOC_ISDEF_MINIMUMPDULENGTHOFRXSECUREDPDUINFO                                              STD_OFF
#define SECOC_ISDEF_PDUFIXLENGTHOFRXSECUREDPDUINFO                                                  STD_OFF
#define SECOC_ISDEF_RXPDUINFOIDXOFRXSECUREDPDUINFO                                                  STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERENDIDXOFRXSECUREDPDUINFO                                 STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERLENGTHOFRXSECUREDPDUINFO                                 STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSTARTIDXOFRXSECUREDPDUINFO                               STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINEROFPCCONFIG                                             STD_ON
#define SECOC_ISDEF_AUTHENTICATORCACHEOFPCCONFIG                                                    STD_ON
#define SECOC_ISDEF_INITIALIZEDOFPCCONFIG                                                           STD_ON
#define SECOC_ISDEF_NUMBEROFMESSAGESTOOVERRIDEOFPCCONFIG                                            STD_ON
#define SECOC_ISDEF_RXAUTHENTICPDUSIZEOFFSETOFPCCONFIG                                              STD_ON
#define SECOC_ISDEF_RXBUILDATTEMPTSCOUNTEROFPCCONFIG                                                STD_ON
#define SECOC_ISDEF_RXPDUINFOOFPCCONFIG                                                             STD_ON
#define SECOC_ISDEF_RXPDUSTATEOFPCCONFIG                                                            STD_ON
#define SECOC_ISDEF_RXSECUREDPDUINFOOFPCCONFIG                                                      STD_ON
#define SECOC_ISDEF_RXTPWRITTENBYTESCOUNTEROFPCCONFIG                                               STD_ON
#define SECOC_ISDEF_SECUREDPDUDATACONTAINEROFPCCONFIG                                               STD_ON
#define SECOC_ISDEF_VERIFYATTEMPTSCOUNTEROFPCCONFIG                                                 STD_ON
#define SECOC_ISDEF_VERIFYOVERRIDESTATUSOFPCCONFIG                                                  STD_ON
#define SECOC_ISDEF_VERIFYRESULTOFPCCONFIG                                                          STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCEqualsAlwaysToDefines  SecOC Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define SECOC_EQ2_AUTHDATAFRESHNESSLENOFRXPDUINFO                                                   
#define SECOC_EQ2_AUTHDATAFRESHNESSOFRXPDUINFO                                                      
#define SECOC_EQ2_AUTHDATAFRESHNESSSTARTBYTEPOSITIONOFRXPDUINFO                                     
#define SECOC_EQ2_AUTHENTICEXTERNALIDOFRXPDUINFO                                                    
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                            
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERAUTHENTICPDULENGTHOFRXPDUINFO                            
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                          
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERAUTHENTICPDUUSEDOFRXPDUINFO                              
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATEENDIDXOFRXPDUINFO                      
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATELENGTHOFRXPDUINFO                      
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATESTARTIDXOFRXPDUINFO                    
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEENDIDXOFRXPDUINFO                    
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUELENGTHOFRXPDUINFO                    
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUESTARTIDXOFRXPDUINFO                  
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEUSEDOFRXPDUINFO                      
#define SECOC_EQ2_AUTHENTICATIONLAYERIDOFRXPDUINFO                                                  
#define SECOC_EQ2_AUTHENTICATORCACHEENDIDXOFRXPDUINFO                                               
#define SECOC_EQ2_AUTHENTICATORCACHELENGTHOFRXPDUINFO                                               
#define SECOC_EQ2_AUTHENTICATORCACHESTARTIDXOFRXPDUINFO                                             
#define SECOC_EQ2_BUILDATTEMPTSOFRXPDUINFO                                                          
#define SECOC_EQ2_CLIENTSERVERVERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                          
#define SECOC_EQ2_DATAIDFIRSTBYTEOFRXPDUINFO                                                        
#define SECOC_EQ2_DATAIDOFRXPDUINFO                                                                 
#define SECOC_EQ2_DATAIDSECONDBYTEOFRXPDUINFO                                                       
#define SECOC_EQ2_EXTERNALFRESHNESSIDOFRXPDUINFO                                                    
#define SECOC_EQ2_NUMBEROFMESSAGESTOOVERRIDEIDXOFRXPDUINFO                                          
#define SECOC_EQ2_PDUPROCESSINGOFRXPDUINFO                                                          
#define SECOC_EQ2_PDUTYPEOFRXPDUINFO                                                                
#define SECOC_EQ2_RXSECUREDPDUINFOIDXOFRXPDUINFO                                                    
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHENTICPDULENGTHOFRXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                            
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHENTICPDUUSEDOFRXPDUINFO                                
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSECUREDPDUENDIDXOFRXPDUINFO                                
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSECUREDPDULENGTHOFRXPDUINFO                                
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSECUREDPDUSTARTIDXOFRXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSECUREDPDUUSEDOFRXPDUINFO                                  
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTPSECUREDPDUENDIDXOFRXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTPSECUREDPDULENGTHOFRXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTPSECUREDPDUSTARTIDXOFRXPDUINFO                            
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTPSECUREDPDUUSEDOFRXPDUINFO                                
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORENDIDXOFRXPDUINFO                    
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORLENGTHOFRXPDUINFO                    
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORSTARTIDXOFRXPDUINFO                  
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORUSEDOFRXPDUINFO                      
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEENDIDXOFRXPDUINFO                   
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUELENGTHOFRXPDUINFO                   
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUESTARTIDXOFRXPDUINFO                 
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEUSEDOFRXPDUINFO                     
#define SECOC_EQ2_SECUREDRXPDUVERFICATIONOFRXPDUINFO                                                
#define SECOC_EQ2_TRUNCAUTHSTARTBITINBYTEOFRXPDUINFO                                                
#define SECOC_EQ2_TRUNCFRESHNESSVALUEFIRSTBYTESHIFTOFRXPDUINFO                                      
#define SECOC_EQ2_TRUNCFRESHNESSVALUESECONDBYTESHIFTOFRXPDUINFO                                     
#define SECOC_EQ2_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                                      
#define SECOC_EQ2_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO                        
#define SECOC_EQ2_VERIFYATTEMPTSOFRXPDUINFO                                                         
#define SECOC_EQ2_VERIFYOVERRIDESTATUSIDXOFRXPDUINFO                                                
#define SECOC_EQ2_VERIFYRESULTIDXOFRXPDUINFO                                                        
#define SECOC_EQ2_TRUNCATEDAUTHENTICATIONLENGTHOFRXPDUINFO                                          
#define SECOC_EQ2_TRUNCATEDFRESHNESSVALUELENGTHOFRXPDUINFO                                          
#define SECOC_EQ2_MESSAGELINKLENOFRXSECUREDPDUINFO                                                  
#define SECOC_EQ2_MESSAGELINKPOSOFRXSECUREDPDUINFO                                                  
#define SECOC_EQ2_MESSAGELINKERSTARTBYTEINCRYPTOPDUOFRXSECUREDPDUINFO                               
#define SECOC_EQ2_MESSAGETYPEOFRXSECUREDPDUINFO                                                     
#define SECOC_EQ2_MESSAGESLINKCRYPTOPDUSRCBITOFFSETOFRXSECUREDPDUINFO                               
#define SECOC_EQ2_MINIMUMPDULENGTHOFRXSECUREDPDUINFO                                                
#define SECOC_EQ2_PDUFIXLENGTHOFRXSECUREDPDUINFO                                                    
#define SECOC_EQ2_RXPDUINFOIDXOFRXSECUREDPDUINFO                                                    
#define SECOC_EQ2_SECUREDPDUDATACONTAINERENDIDXOFRXSECUREDPDUINFO                                   
#define SECOC_EQ2_SECUREDPDUDATACONTAINERLENGTHOFRXSECUREDPDUINFO                                   
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSTARTIDXOFRXSECUREDPDUINFO                                 
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINEROFPCCONFIG                                               SecOC_AuthenticPduDataContainer
#define SECOC_EQ2_AUTHENTICATORCACHEOFPCCONFIG                                                      SecOC_AuthenticatorCache.raw
#define SECOC_EQ2_INITIALIZEDOFPCCONFIG                                                             (&(SecOC_Initialized))
#define SECOC_EQ2_NUMBEROFMESSAGESTOOVERRIDEOFPCCONFIG                                              SecOC_NumberOfMessagesToOverride.raw
#define SECOC_EQ2_RXAUTHENTICPDUSIZEOFFSETOFPCCONFIG                                                SecOC_RxAuthenticPduSizeOffset.raw
#define SECOC_EQ2_RXBUILDATTEMPTSCOUNTEROFPCCONFIG                                                  SecOC_RxBuildAttemptsCounter.raw
#define SECOC_EQ2_RXPDUINFOOFPCCONFIG                                                               SecOC_RxPduInfo
#define SECOC_EQ2_RXPDUSTATEOFPCCONFIG                                                              SecOC_RxPduState.raw
#define SECOC_EQ2_RXSECUREDPDUINFOOFPCCONFIG                                                        SecOC_RxSecuredPduInfo
#define SECOC_EQ2_RXTPWRITTENBYTESCOUNTEROFPCCONFIG                                                 SecOC_RxTpWrittenBytesCounter.raw
#define SECOC_EQ2_SECUREDPDUDATACONTAINEROFPCCONFIG                                                 SecOC_SecuredPduDataContainer
#define SECOC_EQ2_VERIFYATTEMPTSCOUNTEROFPCCONFIG                                                   SecOC_VerifyAttemptsCounter.raw
#define SECOC_EQ2_VERIFYOVERRIDESTATUSOFPCCONFIG                                                    SecOC_VerifyOverrideStatus.raw
#define SECOC_EQ2_VERIFYRESULTOFPCCONFIG                                                            SecOC_VerifyResult.raw
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCSymbolicInitializationPointers  SecOC Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define SecOC_Config_Ptr                                                                            NULL_PTR  /**< symbolic identifier which shall be used to initialize 'SecOC' */
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCInitializationSymbols  SecOC Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define SecOC_Config                                                                                NULL_PTR  /**< symbolic identifier which could be used to initialize 'SecOC */
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCGeneral  SecOC General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define SECOC_CHECK_INIT_POINTER                                                                    STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define SECOC_FINAL_MAGIC_NUMBER                                                                    0x961Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of SecOC */
#define SECOC_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'SecOC' is not configured to be postbuild capable. */
#define SECOC_INIT_DATA                                                                             SECOC_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define SECOC_INIT_DATA_HASH_CODE                                                                   1220421397  /**< the precompile constant to validate the initialization structure at initialization time of SecOC with a hashcode. The seed value is '0x961Eu' */
#define SECOC_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define SECOC_USE_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer SecOC shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SecOCLTDataSwitches  SecOC Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define SECOC_LTCONFIG                                                                              STD_OFF  /**< Deactivateable: 'SecOC_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
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
  \defgroup  SecOCPCGetConstantDuplicatedRootDataMacros  SecOC Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define SecOC_GetAuthenticPduDataContainerOfPCConfig()                                              SecOC_AuthenticPduDataContainer  /**< the pointer to SecOC_AuthenticPduDataContainer */
#define SecOC_GetAuthenticatorCacheOfPCConfig()                                                     SecOC_AuthenticatorCache.raw  /**< the pointer to SecOC_AuthenticatorCache */
#define SecOC_GetInitializedOfPCConfig()                                                            (&(SecOC_Initialized))  /**< the pointer to SecOC_Initialized */
#define SecOC_GetNumberOfMessagesToOverrideOfPCConfig()                                             SecOC_NumberOfMessagesToOverride.raw  /**< the pointer to SecOC_NumberOfMessagesToOverride */
#define SecOC_GetRxAuthenticPduSizeOffsetOfPCConfig()                                               SecOC_RxAuthenticPduSizeOffset.raw  /**< the pointer to SecOC_RxAuthenticPduSizeOffset */
#define SecOC_GetRxBuildAttemptsCounterOfPCConfig()                                                 SecOC_RxBuildAttemptsCounter.raw  /**< the pointer to SecOC_RxBuildAttemptsCounter */
#define SecOC_GetRxPduInfoOfPCConfig()                                                              SecOC_RxPduInfo  /**< the pointer to SecOC_RxPduInfo */
#define SecOC_GetRxPduStateOfPCConfig()                                                             SecOC_RxPduState.raw  /**< the pointer to SecOC_RxPduState */
#define SecOC_GetRxSecuredPduInfoOfPCConfig()                                                       SecOC_RxSecuredPduInfo  /**< the pointer to SecOC_RxSecuredPduInfo */
#define SecOC_GetRxTpWrittenBytesCounterOfPCConfig()                                                SecOC_RxTpWrittenBytesCounter.raw  /**< the pointer to SecOC_RxTpWrittenBytesCounter */
#define SecOC_GetSecuredPduDataContainerOfPCConfig()                                                SecOC_SecuredPduDataContainer  /**< the pointer to SecOC_SecuredPduDataContainer */
#define SecOC_GetSizeOfAuthenticPduDataContainerOfPCConfig()                                        35u  /**< the number of accomplishable value elements in SecOC_AuthenticPduDataContainer */
#define SecOC_GetSizeOfAuthenticatorCacheOfPCConfig()                                               11u  /**< the number of accomplishable value elements in SecOC_AuthenticatorCache */
#define SecOC_GetSizeOfNumberOfMessagesToOverrideOfPCConfig()                                       3u  /**< the number of accomplishable value elements in SecOC_NumberOfMessagesToOverride */
#define SecOC_GetSizeOfRxPduInfoOfPCConfig()                                                        3u  /**< the number of accomplishable value elements in SecOC_RxPduInfo */
#define SecOC_GetSizeOfRxSecuredPduInfoOfPCConfig()                                                 3u  /**< the number of accomplishable value elements in SecOC_RxSecuredPduInfo */
#define SecOC_GetSizeOfSecuredPduDataContainerOfPCConfig()                                          24u  /**< the number of accomplishable value elements in SecOC_SecuredPduDataContainer */
#define SecOC_GetSizeOfVerifyOverrideStatusOfPCConfig()                                             3u  /**< the number of accomplishable value elements in SecOC_VerifyOverrideStatus */
#define SecOC_GetSizeOfVerifyResultOfPCConfig()                                                     3u  /**< the number of accomplishable value elements in SecOC_VerifyResult */
#define SecOC_GetVerifyAttemptsCounterOfPCConfig()                                                  SecOC_VerifyAttemptsCounter.raw  /**< the pointer to SecOC_VerifyAttemptsCounter */
#define SecOC_GetVerifyOverrideStatusOfPCConfig()                                                   SecOC_VerifyOverrideStatus.raw  /**< the pointer to SecOC_VerifyOverrideStatus */
#define SecOC_GetVerifyResultOfPCConfig()                                                           SecOC_VerifyResult.raw  /**< the pointer to SecOC_VerifyResult */
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCGetDuplicatedRootDataMacros  SecOC Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define SecOC_GetSizeOfRxAuthenticPduSizeOffsetOfPCConfig()                                         SecOC_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_RxAuthenticPduSizeOffset */
#define SecOC_GetSizeOfRxBuildAttemptsCounterOfPCConfig()                                           SecOC_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_RxBuildAttemptsCounter */
#define SecOC_GetSizeOfRxPduStateOfPCConfig()                                                       SecOC_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_RxPduState */
#define SecOC_GetSizeOfRxTpWrittenBytesCounterOfPCConfig()                                          SecOC_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_RxTpWrittenBytesCounter */
#define SecOC_GetSizeOfVerifyAttemptsCounterOfPCConfig()                                            SecOC_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_VerifyAttemptsCounter */
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCGetDataMacros  SecOC Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define SecOC_GetAuthenticPduDataContainer(Index)                                                   (SecOC_GetAuthenticPduDataContainerOfPCConfig()[(Index)])
#define SecOC_GetAuthenticatorCache(Index)                                                          (SecOC_GetAuthenticatorCacheOfPCConfig()[(Index)])
#define SecOC_IsInitialized()                                                                       (((*(SecOC_GetInitializedOfPCConfig()))) != FALSE)
#define SecOC_GetNumberOfMessagesToOverride(Index)                                                  (SecOC_GetNumberOfMessagesToOverrideOfPCConfig()[(Index)])
#define SecOC_GetRxAuthenticPduSizeOffset(Index)                                                    (SecOC_GetRxAuthenticPduSizeOffsetOfPCConfig()[(Index)])
#define SecOC_GetRxBuildAttemptsCounter(Index)                                                      (SecOC_GetRxBuildAttemptsCounterOfPCConfig()[(Index)])
#define SecOC_GetAuthDataFreshnessLenOfRxPduInfo(Index)                                             (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthDataFreshnessLenOfRxPduInfo)
#define SecOC_GetAuthDataFreshnessOfRxPduInfo(Index)                                                (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthDataFreshnessOfRxPduInfo)
#define SecOC_GetAuthDataFreshnessStartBytePositionOfRxPduInfo(Index)                               (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthDataFreshnessStartBytePositionOfRxPduInfo)
#define SecOC_GetAuthenticExternalIdOfRxPduInfo(Index)                                              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticExternalIdOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfo(Index)                      (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo(Index)                      (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfo(Index)                    (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfo(Index)                (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo(Index)                (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo(Index)              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo(Index)              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo(Index)              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo(Index)            (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo)
#define SecOC_GetAuthenticationLayerIdOfRxPduInfo(Index)                                            (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticationLayerIdOfRxPduInfo)
#define SecOC_GetAuthenticatorCacheEndIdxOfRxPduInfo(Index)                                         (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticatorCacheEndIdxOfRxPduInfo)
#define SecOC_GetAuthenticatorCacheLengthOfRxPduInfo(Index)                                         (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticatorCacheLengthOfRxPduInfo)
#define SecOC_GetAuthenticatorCacheStartIdxOfRxPduInfo(Index)                                       (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticatorCacheStartIdxOfRxPduInfo)
#define SecOC_GetBuildAttemptsOfRxPduInfo(Index)                                                    (SecOC_GetRxPduInfoOfPCConfig()[(Index)].BuildAttemptsOfRxPduInfo)
#define SecOC_GetClientServerVerificationStatusPropagationModeOfRxPduInfo(Index)                    (SecOC_GetRxPduInfoOfPCConfig()[(Index)].ClientServerVerificationStatusPropagationModeOfRxPduInfo)
#define SecOC_GetDataIdFirstByteOfRxPduInfo(Index)                                                  (SecOC_GetRxPduInfoOfPCConfig()[(Index)].DataIdFirstByteOfRxPduInfo)
#define SecOC_GetDataIdOfRxPduInfo(Index)                                                           (SecOC_GetRxPduInfoOfPCConfig()[(Index)].DataIdOfRxPduInfo)
#define SecOC_GetDataIdSecondByteOfRxPduInfo(Index)                                                 (SecOC_GetRxPduInfoOfPCConfig()[(Index)].DataIdSecondByteOfRxPduInfo)
#define SecOC_GetExternalFreshnessIdOfRxPduInfo(Index)                                              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].ExternalFreshnessIdOfRxPduInfo)
#define SecOC_GetNumberOfMessagesToOverrideIdxOfRxPduInfo(Index)                                    (SecOC_GetRxPduInfoOfPCConfig()[(Index)].NumberOfMessagesToOverrideIdxOfRxPduInfo)
#define SecOC_GetPduProcessingOfRxPduInfo(Index)                                                    (SecOC_GetRxPduInfoOfPCConfig()[(Index)].PduProcessingOfRxPduInfo)
#define SecOC_GetPduTypeOfRxPduInfo(Index)                                                          (SecOC_GetRxPduInfoOfPCConfig()[(Index)].PduTypeOfRxPduInfo)
#define SecOC_GetRxSecuredPduInfoIdxOfRxPduInfo(Index)                                              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].RxSecuredPduInfoIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfo(Index)                        (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerAuthenticPduLengthOfRxPduInfo(Index)                        (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerAuthenticPduLengthOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfo(Index)                      (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerSecuredPduEndIdxOfRxPduInfo(Index)                          (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerSecuredPduEndIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerSecuredPduLengthOfRxPduInfo(Index)                          (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerSecuredPduLengthOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerSecuredPduStartIdxOfRxPduInfo(Index)                        (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerSecuredPduStartIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfo(Index)                        (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo(Index)                        (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfo(Index)                      (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfo(Index)              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo(Index)              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfo(Index)            (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfo(Index)             (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo(Index)             (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfo(Index)           (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfo)
#define SecOC_IsSecuredRxPduVerficationOfRxPduInfo(Index)                                           ((SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredRxPduVerficationOfRxPduInfo) != FALSE)
#define SecOC_GetTruncAuthStartBitInByteOfRxPduInfo(Index)                                          (SecOC_GetRxPduInfoOfPCConfig()[(Index)].TruncAuthStartBitInByteOfRxPduInfo)
#define SecOC_GetTruncFreshnessValueFirstByteShiftOfRxPduInfo(Index)                                (SecOC_GetRxPduInfoOfPCConfig()[(Index)].TruncFreshnessValueFirstByteShiftOfRxPduInfo)
#define SecOC_GetTruncFreshnessValueSecondByteShiftOfRxPduInfo(Index)                               (SecOC_GetRxPduInfoOfPCConfig()[(Index)].TruncFreshnessValueSecondByteShiftOfRxPduInfo)
#define SecOC_GetVerificationStatusPropagationModeOfRxPduInfo(Index)                                (SecOC_GetRxPduInfoOfPCConfig()[(Index)].VerificationStatusPropagationModeOfRxPduInfo)
#define SecOC_GetVerificationStatusWithSecuredPduPropagationModeOfRxPduInfo(Index)                  (SecOC_GetRxPduInfoOfPCConfig()[(Index)].VerificationStatusWithSecuredPduPropagationModeOfRxPduInfo)
#define SecOC_GetVerifyAttemptsOfRxPduInfo(Index)                                                   (SecOC_GetRxPduInfoOfPCConfig()[(Index)].VerifyAttemptsOfRxPduInfo)
#define SecOC_GetVerifyOverrideStatusIdxOfRxPduInfo(Index)                                          (SecOC_GetRxPduInfoOfPCConfig()[(Index)].VerifyOverrideStatusIdxOfRxPduInfo)
#define SecOC_GetVerifyResultIdxOfRxPduInfo(Index)                                                  (SecOC_GetRxPduInfoOfPCConfig()[(Index)].VerifyResultIdxOfRxPduInfo)
#define SecOC_GettruncatedAuthenticationLengthOfRxPduInfo(Index)                                    (SecOC_GetRxPduInfoOfPCConfig()[(Index)].truncatedAuthenticationLengthOfRxPduInfo)
#define SecOC_GettruncatedFreshnessValueLengthOfRxPduInfo(Index)                                    (SecOC_GetRxPduInfoOfPCConfig()[(Index)].truncatedFreshnessValueLengthOfRxPduInfo)
#define SecOC_GetRxPduState(Index)                                                                  (SecOC_GetRxPduStateOfPCConfig()[(Index)])
#define SecOC_GetMessageLinkLenOfRxSecuredPduInfo(Index)                                            (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].MessageLinkLenOfRxSecuredPduInfo)
#define SecOC_GetMessageLinkPosOfRxSecuredPduInfo(Index)                                            (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].MessageLinkPosOfRxSecuredPduInfo)
#define SecOC_GetMessageLinkerStartByteInCryptoPduOfRxSecuredPduInfo(Index)                         (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].MessageLinkerStartByteInCryptoPduOfRxSecuredPduInfo)
#define SecOC_GetMessageTypeOfRxSecuredPduInfo(Index)                                               (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].MessageTypeOfRxSecuredPduInfo)
#define SecOC_GetMessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfo(Index)                         (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].MessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfo)
#define SecOC_GetMinimumPduLengthOfRxSecuredPduInfo(Index)                                          (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].MinimumPduLengthOfRxSecuredPduInfo)
#define SecOC_GetPduFixLengthOfRxSecuredPduInfo(Index)                                              (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].PduFixLengthOfRxSecuredPduInfo)
#define SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(Index)                                              (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxSecuredPduInfo)
#define SecOC_GetSecuredPduDataContainerEndIdxOfRxSecuredPduInfo(Index)                             (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerEndIdxOfRxSecuredPduInfo)
#define SecOC_GetSecuredPduDataContainerLengthOfRxSecuredPduInfo(Index)                             (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerLengthOfRxSecuredPduInfo)
#define SecOC_GetSecuredPduDataContainerStartIdxOfRxSecuredPduInfo(Index)                           (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerStartIdxOfRxSecuredPduInfo)
#define SecOC_GetRxTpWrittenBytesCounter(Index)                                                     (SecOC_GetRxTpWrittenBytesCounterOfPCConfig()[(Index)])
#define SecOC_GetSecuredPduDataContainer(Index)                                                     (SecOC_GetSecuredPduDataContainerOfPCConfig()[(Index)])
#define SecOC_GetVerifyAttemptsCounter(Index)                                                       (SecOC_GetVerifyAttemptsCounterOfPCConfig()[(Index)])
#define SecOC_GetVerifyOverrideStatus(Index)                                                        (SecOC_GetVerifyOverrideStatusOfPCConfig()[(Index)])
#define SecOC_GetVerifyResult(Index)                                                                (SecOC_GetVerifyResultOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCGetDeduplicatedDataMacros  SecOC Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define SecOC_IsAuthenticPduDataContainerAuthenticPduUsedOfRxPduInfo(Index)                         (((boolean)(SecOC_GetAuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_AuthenticPduDataContainer */
#define SecOC_IsAuthenticPduDataContainerFreshnessVerifyValueUsedOfRxPduInfo(Index)                 (((boolean)(SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_AuthenticPduDataContainer */
#define SecOC_IsSecuredPduDataContainerAuthenticPduUsedOfRxPduInfo(Index)                           (((boolean)(SecOC_GetSecuredPduDataContainerAuthenticPduLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_IsSecuredPduDataContainerSecuredPduUsedOfRxPduInfo(Index)                             (((boolean)(SecOC_GetSecuredPduDataContainerSecuredPduLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_IsSecuredPduDataContainerTpSecuredPduUsedOfRxPduInfo(Index)                           (((boolean)(SecOC_GetSecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_IsSecuredPduDataContainerTruncatedAuthenticatorUsedOfRxPduInfo(Index)                 (((boolean)(SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_IsSecuredPduDataContainerTruncatedFreshnessValueUsedOfRxPduInfo(Index)                (((boolean)(SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_GetSizeOfAuthenticPduDataContainer()                                                  SecOC_GetSizeOfAuthenticPduDataContainerOfPCConfig()
#define SecOC_GetSizeOfAuthenticatorCache()                                                         SecOC_GetSizeOfAuthenticatorCacheOfPCConfig()
#define SecOC_GetSizeOfNumberOfMessagesToOverride()                                                 SecOC_GetSizeOfNumberOfMessagesToOverrideOfPCConfig()
#define SecOC_GetSizeOfRxAuthenticPduSizeOffset()                                                   SecOC_GetSizeOfRxAuthenticPduSizeOffsetOfPCConfig()
#define SecOC_GetSizeOfRxBuildAttemptsCounter()                                                     SecOC_GetSizeOfRxBuildAttemptsCounterOfPCConfig()
#define SecOC_GetSizeOfRxPduInfo()                                                                  SecOC_GetSizeOfRxPduInfoOfPCConfig()
#define SecOC_GetSizeOfRxPduState()                                                                 SecOC_GetSizeOfRxPduStateOfPCConfig()
#define SecOC_GetSizeOfRxSecuredPduInfo()                                                           SecOC_GetSizeOfRxSecuredPduInfoOfPCConfig()
#define SecOC_GetSizeOfRxTpWrittenBytesCounter()                                                    SecOC_GetSizeOfRxTpWrittenBytesCounterOfPCConfig()
#define SecOC_GetSizeOfSecuredPduDataContainer()                                                    SecOC_GetSizeOfSecuredPduDataContainerOfPCConfig()
#define SecOC_GetSizeOfVerifyAttemptsCounter()                                                      SecOC_GetSizeOfVerifyAttemptsCounterOfPCConfig()
#define SecOC_GetSizeOfVerifyOverrideStatus()                                                       SecOC_GetSizeOfVerifyOverrideStatusOfPCConfig()
#define SecOC_GetSizeOfVerifyResult()                                                               SecOC_GetSizeOfVerifyResultOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCSetDataMacros  SecOC Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define SecOC_SetAuthenticPduDataContainer(Index, Value)                                            SecOC_GetAuthenticPduDataContainerOfPCConfig()[(Index)] = (Value)
#define SecOC_SetAuthenticatorCache(Index, Value)                                                   SecOC_GetAuthenticatorCacheOfPCConfig()[(Index)] = (Value)
#define SecOC_SetInitialized(Value)                                                                 (*(SecOC_GetInitializedOfPCConfig())) = (Value)
#define SecOC_SetNumberOfMessagesToOverride(Index, Value)                                           SecOC_GetNumberOfMessagesToOverrideOfPCConfig()[(Index)] = (Value)
#define SecOC_SetRxAuthenticPduSizeOffset(Index, Value)                                             SecOC_GetRxAuthenticPduSizeOffsetOfPCConfig()[(Index)] = (Value)
#define SecOC_SetRxBuildAttemptsCounter(Index, Value)                                               SecOC_GetRxBuildAttemptsCounterOfPCConfig()[(Index)] = (Value)
#define SecOC_SetRxPduState(Index, Value)                                                           SecOC_GetRxPduStateOfPCConfig()[(Index)] = (Value)
#define SecOC_SetRxTpWrittenBytesCounter(Index, Value)                                              SecOC_GetRxTpWrittenBytesCounterOfPCConfig()[(Index)] = (Value)
#define SecOC_SetSecuredPduDataContainer(Index, Value)                                              SecOC_GetSecuredPduDataContainerOfPCConfig()[(Index)] = (Value)
#define SecOC_SetVerifyAttemptsCounter(Index, Value)                                                SecOC_GetVerifyAttemptsCounterOfPCConfig()[(Index)] = (Value)
#define SecOC_SetVerifyOverrideStatus(Index, Value)                                                 SecOC_GetVerifyOverrideStatusOfPCConfig()[(Index)] = (Value)
#define SecOC_SetVerifyResult(Index, Value)                                                         SecOC_GetVerifyResultOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCGetAddressOfDataMacros  SecOC Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define SecOC_GetAddrAuthenticPduDataContainer(Index)                                               (&SecOC_GetAuthenticPduDataContainer(Index))
#define SecOC_GetAddrAuthenticatorCache(Index)                                                      (&SecOC_GetAuthenticatorCache(Index))
#define SecOC_GetAddrSecuredPduDataContainer(Index)                                                 (&SecOC_GetSecuredPduDataContainer(Index))
#define SecOC_GetAddrVerifyResult(Index)                                                            (&SecOC_GetVerifyResult(Index))
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCHasMacros  SecOC Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define SecOC_HasAuthenticPduDataContainer()                                                        (TRUE != FALSE)
#define SecOC_HasAuthenticatorCache()                                                               (TRUE != FALSE)
#define SecOC_HasInitialized()                                                                      (TRUE != FALSE)
#define SecOC_HasNumberOfMessagesToOverride()                                                       (TRUE != FALSE)
#define SecOC_HasRxAuthenticPduSizeOffset()                                                         (TRUE != FALSE)
#define SecOC_HasRxBuildAttemptsCounter()                                                           (TRUE != FALSE)
#define SecOC_HasRxPduInfo()                                                                        (TRUE != FALSE)
#define SecOC_HasAuthDataFreshnessLenOfRxPduInfo()                                                  (TRUE != FALSE)
#define SecOC_HasAuthDataFreshnessOfRxPduInfo()                                                     (TRUE != FALSE)
#define SecOC_HasAuthDataFreshnessStartBytePositionOfRxPduInfo()                                    (TRUE != FALSE)
#define SecOC_HasAuthenticExternalIdOfRxPduInfo()                                                   (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfo()                           (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo()                           (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfo()                         (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerAuthenticPduUsedOfRxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfo()                     (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo()                     (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo()                 (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFreshnessVerifyValueUsedOfRxPduInfo()                     (TRUE != FALSE)
#define SecOC_HasAuthenticationLayerIdOfRxPduInfo()                                                 (TRUE != FALSE)
#define SecOC_HasAuthenticatorCacheEndIdxOfRxPduInfo()                                              (TRUE != FALSE)
#define SecOC_HasAuthenticatorCacheLengthOfRxPduInfo()                                              (TRUE != FALSE)
#define SecOC_HasAuthenticatorCacheStartIdxOfRxPduInfo()                                            (TRUE != FALSE)
#define SecOC_HasBuildAttemptsOfRxPduInfo()                                                         (TRUE != FALSE)
#define SecOC_HasClientServerVerificationStatusPropagationModeOfRxPduInfo()                         (TRUE != FALSE)
#define SecOC_HasDataIdFirstByteOfRxPduInfo()                                                       (TRUE != FALSE)
#define SecOC_HasDataIdOfRxPduInfo()                                                                (TRUE != FALSE)
#define SecOC_HasDataIdSecondByteOfRxPduInfo()                                                      (TRUE != FALSE)
#define SecOC_HasExternalFreshnessIdOfRxPduInfo()                                                   (TRUE != FALSE)
#define SecOC_HasNumberOfMessagesToOverrideIdxOfRxPduInfo()                                         (TRUE != FALSE)
#define SecOC_HasPduProcessingOfRxPduInfo()                                                         (TRUE != FALSE)
#define SecOC_HasPduTypeOfRxPduInfo()                                                               (TRUE != FALSE)
#define SecOC_HasRxSecuredPduInfoIdxOfRxPduInfo()                                                   (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthenticPduLengthOfRxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfo()                           (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthenticPduUsedOfRxPduInfo()                               (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerSecuredPduEndIdxOfRxPduInfo()                               (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerSecuredPduLengthOfRxPduInfo()                               (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerSecuredPduStartIdxOfRxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerSecuredPduUsedOfRxPduInfo()                                 (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfo()                           (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTpSecuredPduUsedOfRxPduInfo()                               (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfo()                 (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedAuthenticatorUsedOfRxPduInfo()                     (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfo()                  (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo()                  (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfo()                (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedFreshnessValueUsedOfRxPduInfo()                    (TRUE != FALSE)
#define SecOC_HasSecuredRxPduVerficationOfRxPduInfo()                                               (TRUE != FALSE)
#define SecOC_HasTruncAuthStartBitInByteOfRxPduInfo()                                               (TRUE != FALSE)
#define SecOC_HasTruncFreshnessValueFirstByteShiftOfRxPduInfo()                                     (TRUE != FALSE)
#define SecOC_HasTruncFreshnessValueSecondByteShiftOfRxPduInfo()                                    (TRUE != FALSE)
#define SecOC_HasVerificationStatusPropagationModeOfRxPduInfo()                                     (TRUE != FALSE)
#define SecOC_HasVerificationStatusWithSecuredPduPropagationModeOfRxPduInfo()                       (TRUE != FALSE)
#define SecOC_HasVerifyAttemptsOfRxPduInfo()                                                        (TRUE != FALSE)
#define SecOC_HasVerifyOverrideStatusIdxOfRxPduInfo()                                               (TRUE != FALSE)
#define SecOC_HasVerifyResultIdxOfRxPduInfo()                                                       (TRUE != FALSE)
#define SecOC_HastruncatedAuthenticationLengthOfRxPduInfo()                                         (TRUE != FALSE)
#define SecOC_HastruncatedFreshnessValueLengthOfRxPduInfo()                                         (TRUE != FALSE)
#define SecOC_HasRxPduState()                                                                       (TRUE != FALSE)
#define SecOC_HasRxSecuredPduInfo()                                                                 (TRUE != FALSE)
#define SecOC_HasMessageLinkLenOfRxSecuredPduInfo()                                                 (TRUE != FALSE)
#define SecOC_HasMessageLinkPosOfRxSecuredPduInfo()                                                 (TRUE != FALSE)
#define SecOC_HasMessageLinkerStartByteInCryptoPduOfRxSecuredPduInfo()                              (TRUE != FALSE)
#define SecOC_HasMessageTypeOfRxSecuredPduInfo()                                                    (TRUE != FALSE)
#define SecOC_HasMessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfo()                              (TRUE != FALSE)
#define SecOC_HasMinimumPduLengthOfRxSecuredPduInfo()                                               (TRUE != FALSE)
#define SecOC_HasPduFixLengthOfRxSecuredPduInfo()                                                   (TRUE != FALSE)
#define SecOC_HasRxPduInfoIdxOfRxSecuredPduInfo()                                                   (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerEndIdxOfRxSecuredPduInfo()                                  (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerLengthOfRxSecuredPduInfo()                                  (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerStartIdxOfRxSecuredPduInfo()                                (TRUE != FALSE)
#define SecOC_HasRxTpWrittenBytesCounter()                                                          (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainer()                                                          (TRUE != FALSE)
#define SecOC_HasSizeOfAuthenticPduDataContainer()                                                  (TRUE != FALSE)
#define SecOC_HasSizeOfAuthenticatorCache()                                                         (TRUE != FALSE)
#define SecOC_HasSizeOfNumberOfMessagesToOverride()                                                 (TRUE != FALSE)
#define SecOC_HasSizeOfRxAuthenticPduSizeOffset()                                                   (TRUE != FALSE)
#define SecOC_HasSizeOfRxBuildAttemptsCounter()                                                     (TRUE != FALSE)
#define SecOC_HasSizeOfRxPduInfo()                                                                  (TRUE != FALSE)
#define SecOC_HasSizeOfRxPduState()                                                                 (TRUE != FALSE)
#define SecOC_HasSizeOfRxSecuredPduInfo()                                                           (TRUE != FALSE)
#define SecOC_HasSizeOfRxTpWrittenBytesCounter()                                                    (TRUE != FALSE)
#define SecOC_HasSizeOfSecuredPduDataContainer()                                                    (TRUE != FALSE)
#define SecOC_HasSizeOfVerifyAttemptsCounter()                                                      (TRUE != FALSE)
#define SecOC_HasSizeOfVerifyOverrideStatus()                                                       (TRUE != FALSE)
#define SecOC_HasSizeOfVerifyResult()                                                               (TRUE != FALSE)
#define SecOC_HasVerifyAttemptsCounter()                                                            (TRUE != FALSE)
#define SecOC_HasVerifyOverrideStatus()                                                             (TRUE != FALSE)
#define SecOC_HasVerifyResult()                                                                     (TRUE != FALSE)
#define SecOC_HasPCConfig()                                                                         (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerOfPCConfig()                                              (TRUE != FALSE)
#define SecOC_HasAuthenticatorCacheOfPCConfig()                                                     (TRUE != FALSE)
#define SecOC_HasInitializedOfPCConfig()                                                            (TRUE != FALSE)
#define SecOC_HasNumberOfMessagesToOverrideOfPCConfig()                                             (TRUE != FALSE)
#define SecOC_HasRxAuthenticPduSizeOffsetOfPCConfig()                                               (TRUE != FALSE)
#define SecOC_HasRxBuildAttemptsCounterOfPCConfig()                                                 (TRUE != FALSE)
#define SecOC_HasRxPduInfoOfPCConfig()                                                              (TRUE != FALSE)
#define SecOC_HasRxPduStateOfPCConfig()                                                             (TRUE != FALSE)
#define SecOC_HasRxSecuredPduInfoOfPCConfig()                                                       (TRUE != FALSE)
#define SecOC_HasRxTpWrittenBytesCounterOfPCConfig()                                                (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerOfPCConfig()                                                (TRUE != FALSE)
#define SecOC_HasSizeOfAuthenticPduDataContainerOfPCConfig()                                        (TRUE != FALSE)
#define SecOC_HasSizeOfAuthenticatorCacheOfPCConfig()                                               (TRUE != FALSE)
#define SecOC_HasSizeOfNumberOfMessagesToOverrideOfPCConfig()                                       (TRUE != FALSE)
#define SecOC_HasSizeOfRxAuthenticPduSizeOffsetOfPCConfig()                                         (TRUE != FALSE)
#define SecOC_HasSizeOfRxBuildAttemptsCounterOfPCConfig()                                           (TRUE != FALSE)
#define SecOC_HasSizeOfRxPduInfoOfPCConfig()                                                        (TRUE != FALSE)
#define SecOC_HasSizeOfRxPduStateOfPCConfig()                                                       (TRUE != FALSE)
#define SecOC_HasSizeOfRxSecuredPduInfoOfPCConfig()                                                 (TRUE != FALSE)
#define SecOC_HasSizeOfRxTpWrittenBytesCounterOfPCConfig()                                          (TRUE != FALSE)
#define SecOC_HasSizeOfSecuredPduDataContainerOfPCConfig()                                          (TRUE != FALSE)
#define SecOC_HasSizeOfVerifyAttemptsCounterOfPCConfig()                                            (TRUE != FALSE)
#define SecOC_HasSizeOfVerifyOverrideStatusOfPCConfig()                                             (TRUE != FALSE)
#define SecOC_HasSizeOfVerifyResultOfPCConfig()                                                     (TRUE != FALSE)
#define SecOC_HasVerifyAttemptsCounterOfPCConfig()                                                  (TRUE != FALSE)
#define SecOC_HasVerifyOverrideStatusOfPCConfig()                                                   (TRUE != FALSE)
#define SecOC_HasVerifyResultOfPCConfig()                                                           (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCIncrementDataMacros  SecOC Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define SecOC_IncAuthenticPduDataContainer(Index)                                                   SecOC_GetAuthenticPduDataContainer(Index)++
#define SecOC_IncAuthenticatorCache(Index)                                                          SecOC_GetAuthenticatorCache(Index)++
#define SecOC_IncNumberOfMessagesToOverride(Index)                                                  SecOC_GetNumberOfMessagesToOverride(Index)++
#define SecOC_IncRxAuthenticPduSizeOffset(Index)                                                    SecOC_GetRxAuthenticPduSizeOffset(Index)++
#define SecOC_IncRxBuildAttemptsCounter(Index)                                                      SecOC_GetRxBuildAttemptsCounter(Index)++
#define SecOC_IncRxTpWrittenBytesCounter(Index)                                                     SecOC_GetRxTpWrittenBytesCounter(Index)++
#define SecOC_IncSecuredPduDataContainer(Index)                                                     SecOC_GetSecuredPduDataContainer(Index)++
#define SecOC_IncVerifyAttemptsCounter(Index)                                                       SecOC_GetVerifyAttemptsCounter(Index)++
#define SecOC_IncVerifyResult(Index)                                                                SecOC_GetVerifyResult(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCDecrementDataMacros  SecOC Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define SecOC_DecAuthenticPduDataContainer(Index)                                                   SecOC_GetAuthenticPduDataContainer(Index)--
#define SecOC_DecAuthenticatorCache(Index)                                                          SecOC_GetAuthenticatorCache(Index)--
#define SecOC_DecNumberOfMessagesToOverride(Index)                                                  SecOC_GetNumberOfMessagesToOverride(Index)--
#define SecOC_DecRxAuthenticPduSizeOffset(Index)                                                    SecOC_GetRxAuthenticPduSizeOffset(Index)--
#define SecOC_DecRxBuildAttemptsCounter(Index)                                                      SecOC_GetRxBuildAttemptsCounter(Index)--
#define SecOC_DecRxTpWrittenBytesCounter(Index)                                                     SecOC_GetRxTpWrittenBytesCounter(Index)--
#define SecOC_DecSecuredPduDataContainer(Index)                                                     SecOC_GetSecuredPduDataContainer(Index)--
#define SecOC_DecVerifyAttemptsCounter(Index)                                                       SecOC_GetVerifyAttemptsCounter(Index)--
#define SecOC_DecVerifyResult(Index)                                                                SecOC_GetVerifyResult(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCAddDataMacros  SecOC Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define SecOC_AddAuthenticPduDataContainer(Index, Value)                                            SecOC_SetAuthenticPduDataContainer(Index, (SecOC_GetAuthenticPduDataContainer(Index) + Value))
#define SecOC_AddAuthenticatorCache(Index, Value)                                                   SecOC_SetAuthenticatorCache(Index, (SecOC_GetAuthenticatorCache(Index) + Value))
#define SecOC_AddNumberOfMessagesToOverride(Index, Value)                                           SecOC_SetNumberOfMessagesToOverride(Index, (SecOC_GetNumberOfMessagesToOverride(Index) + Value))
#define SecOC_AddRxAuthenticPduSizeOffset(Index, Value)                                             SecOC_SetRxAuthenticPduSizeOffset(Index, (SecOC_GetRxAuthenticPduSizeOffset(Index) + Value))
#define SecOC_AddRxBuildAttemptsCounter(Index, Value)                                               SecOC_SetRxBuildAttemptsCounter(Index, (SecOC_GetRxBuildAttemptsCounter(Index) + Value))
#define SecOC_AddRxTpWrittenBytesCounter(Index, Value)                                              SecOC_SetRxTpWrittenBytesCounter(Index, (SecOC_GetRxTpWrittenBytesCounter(Index) + Value))
#define SecOC_AddSecuredPduDataContainer(Index, Value)                                              SecOC_SetSecuredPduDataContainer(Index, (SecOC_GetSecuredPduDataContainer(Index) + Value))
#define SecOC_AddVerifyAttemptsCounter(Index, Value)                                                SecOC_SetVerifyAttemptsCounter(Index, (SecOC_GetVerifyAttemptsCounter(Index) + Value))
#define SecOC_AddVerifyResult(Index, Value)                                                         SecOC_SetVerifyResult(Index, (SecOC_GetVerifyResult(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCSubstractDataMacros  SecOC Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define SecOC_SubAuthenticPduDataContainer(Index, Value)                                            SecOC_SetAuthenticPduDataContainer(Index, (SecOC_GetAuthenticPduDataContainer(Index) - Value))
#define SecOC_SubAuthenticatorCache(Index, Value)                                                   SecOC_SetAuthenticatorCache(Index, (SecOC_GetAuthenticatorCache(Index) - Value))
#define SecOC_SubNumberOfMessagesToOverride(Index, Value)                                           SecOC_SetNumberOfMessagesToOverride(Index, (SecOC_GetNumberOfMessagesToOverride(Index) - Value))
#define SecOC_SubRxAuthenticPduSizeOffset(Index, Value)                                             SecOC_SetRxAuthenticPduSizeOffset(Index, (SecOC_GetRxAuthenticPduSizeOffset(Index) - Value))
#define SecOC_SubRxBuildAttemptsCounter(Index, Value)                                               SecOC_SetRxBuildAttemptsCounter(Index, (SecOC_GetRxBuildAttemptsCounter(Index) - Value))
#define SecOC_SubRxTpWrittenBytesCounter(Index, Value)                                              SecOC_SetRxTpWrittenBytesCounter(Index, (SecOC_GetRxTpWrittenBytesCounter(Index) - Value))
#define SecOC_SubSecuredPduDataContainer(Index, Value)                                              SecOC_SetSecuredPduDataContainer(Index, (SecOC_GetSecuredPduDataContainer(Index) - Value))
#define SecOC_SubVerifyAttemptsCounter(Index, Value)                                                SecOC_SetVerifyAttemptsCounter(Index, (SecOC_GetVerifyAttemptsCounter(Index) - Value))
#define SecOC_SubVerifyResult(Index, Value)                                                         SecOC_SetVerifyResult(Index, (SecOC_GetVerifyResult(Index) - Value))
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
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  SecOCPCSizeOfTypes  SecOC SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for SecOC_RxAuthenticPduSizeOffset */
typedef uint16 SecOC_RxAuthenticPduSizeOffsetType;

/**   \brief  value based type definition for SecOC_SizeOfAuthenticPduDataContainer */
typedef uint8 SecOC_SizeOfAuthenticPduDataContainerType;

/**   \brief  value based type definition for SecOC_SizeOfAuthenticatorCache */
typedef uint8 SecOC_SizeOfAuthenticatorCacheType;

/**   \brief  value based type definition for SecOC_SizeOfNumberOfMessagesToOverride */
typedef uint8 SecOC_SizeOfNumberOfMessagesToOverrideType;

/**   \brief  value based type definition for SecOC_SizeOfRxAuthenticPduSizeOffset */
typedef uint8 SecOC_SizeOfRxAuthenticPduSizeOffsetType;

/**   \brief  value based type definition for SecOC_SizeOfRxBuildAttemptsCounter */
typedef uint8 SecOC_SizeOfRxBuildAttemptsCounterType;

/**   \brief  value based type definition for SecOC_SizeOfRxPduInfo */
typedef uint8 SecOC_SizeOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SizeOfRxPduState */
typedef uint8 SecOC_SizeOfRxPduStateType;

/**   \brief  value based type definition for SecOC_SizeOfRxSecuredPduInfo */
typedef uint8 SecOC_SizeOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_SizeOfRxTpWrittenBytesCounter */
typedef uint8 SecOC_SizeOfRxTpWrittenBytesCounterType;

/**   \brief  value based type definition for SecOC_SizeOfSecuredPduDataContainer */
typedef uint8 SecOC_SizeOfSecuredPduDataContainerType;

/**   \brief  value based type definition for SecOC_SizeOfVerifyAttemptsCounter */
typedef uint8 SecOC_SizeOfVerifyAttemptsCounterType;

/**   \brief  value based type definition for SecOC_SizeOfVerifyOverrideStatus */
typedef uint8 SecOC_SizeOfVerifyOverrideStatusType;

/**   \brief  value based type definition for SecOC_SizeOfVerifyResult */
typedef uint8 SecOC_SizeOfVerifyResultType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SecOCPCIterableTypes  SecOC Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate SecOC_AuthenticPduDataContainer */
typedef uint8_least SecOC_AuthenticPduDataContainerIterType;

/**   \brief  type used to iterate SecOC_AuthenticatorCache */
typedef uint8_least SecOC_AuthenticatorCacheIterType;

/**   \brief  type used to iterate SecOC_NumberOfMessagesToOverride */
typedef uint8_least SecOC_NumberOfMessagesToOverrideIterType;

/**   \brief  type used to iterate SecOC_RxPduInfo */
typedef uint8_least SecOC_RxPduInfoIterType;

/**   \brief  type used to iterate SecOC_RxSecuredPduInfo */
typedef uint8_least SecOC_RxSecuredPduInfoIterType;

/**   \brief  type used to iterate SecOC_SecuredPduDataContainer */
typedef uint8_least SecOC_SecuredPduDataContainerIterType;

/**   \brief  type used to iterate SecOC_VerifyOverrideStatus */
typedef uint8_least SecOC_VerifyOverrideStatusIterType;

/**   \brief  type used to iterate SecOC_VerifyResult */
typedef uint8_least SecOC_VerifyResultIterType;

/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCIterableTypesWithSizeRelations  SecOC Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate SecOC_RxAuthenticPduSizeOffset */
typedef SecOC_RxPduInfoIterType SecOC_RxAuthenticPduSizeOffsetIterType;

/**   \brief  type used to iterate SecOC_RxBuildAttemptsCounter */
typedef SecOC_RxPduInfoIterType SecOC_RxBuildAttemptsCounterIterType;

/**   \brief  type used to iterate SecOC_RxPduState */
typedef SecOC_RxPduInfoIterType SecOC_RxPduStateIterType;

/**   \brief  type used to iterate SecOC_RxTpWrittenBytesCounter */
typedef SecOC_RxPduInfoIterType SecOC_RxTpWrittenBytesCounterIterType;

/**   \brief  type used to iterate SecOC_VerifyAttemptsCounter */
typedef SecOC_RxPduInfoIterType SecOC_VerifyAttemptsCounterIterType;

/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCValueTypes  SecOC Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for SecOC_AuthenticPduDataContainer */
typedef uint8 SecOC_AuthenticPduDataContainerType;

/**   \brief  value based type definition for SecOC_AuthenticatorCache */
typedef uint8 SecOC_AuthenticatorCacheType;

/**   \brief  value based type definition for SecOC_Initialized */
typedef boolean SecOC_InitializedType;

/**   \brief  value based type definition for SecOC_NumberOfMessagesToOverride */
typedef uint8 SecOC_NumberOfMessagesToOverrideType;

/**   \brief  value based type definition for SecOC_RxBuildAttemptsCounter */
typedef uint16 SecOC_RxBuildAttemptsCounterType;

/**   \brief  value based type definition for SecOC_AuthDataFreshnessLenOfRxPduInfo */
typedef uint8 SecOC_AuthDataFreshnessLenOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthDataFreshnessOfRxPduInfo */
typedef uint8 SecOC_AuthDataFreshnessOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthDataFreshnessStartBytePositionOfRxPduInfo */
typedef uint8 SecOC_AuthDataFreshnessStartBytePositionOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticExternalIdOfRxPduInfo */
typedef uint8 SecOC_AuthenticExternalIdOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerAuthenticPduLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerAuthenticPduUsedOfRxPduInfo */
typedef boolean SecOC_AuthenticPduDataContainerAuthenticPduUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFreshnessVerifyValueUsedOfRxPduInfo */
typedef boolean SecOC_AuthenticPduDataContainerFreshnessVerifyValueUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticationLayerIdOfRxPduInfo */
typedef uint16 SecOC_AuthenticationLayerIdOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticatorCacheEndIdxOfRxPduInfo */
typedef uint8 SecOC_AuthenticatorCacheEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticatorCacheLengthOfRxPduInfo */
typedef uint8 SecOC_AuthenticatorCacheLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticatorCacheStartIdxOfRxPduInfo */
typedef uint8 SecOC_AuthenticatorCacheStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_BuildAttemptsOfRxPduInfo */
typedef uint8 SecOC_BuildAttemptsOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_ClientServerVerificationStatusPropagationModeOfRxPduInfo */
typedef uint8 SecOC_ClientServerVerificationStatusPropagationModeOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_DataIdFirstByteOfRxPduInfo */
typedef uint8 SecOC_DataIdFirstByteOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_DataIdOfRxPduInfo */
typedef uint16 SecOC_DataIdOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_DataIdSecondByteOfRxPduInfo */
typedef uint8 SecOC_DataIdSecondByteOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_ExternalFreshnessIdOfRxPduInfo */
typedef uint8 SecOC_ExternalFreshnessIdOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_NumberOfMessagesToOverrideIdxOfRxPduInfo */
typedef uint8 SecOC_NumberOfMessagesToOverrideIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_PduProcessingOfRxPduInfo */
typedef uint8 SecOC_PduProcessingOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_PduTypeOfRxPduInfo */
typedef uint8 SecOC_PduTypeOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_RxSecuredPduInfoIdxOfRxPduInfo */
typedef uint8 SecOC_RxSecuredPduInfoIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthenticPduLengthOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerAuthenticPduLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthenticPduUsedOfRxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerAuthenticPduUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerSecuredPduEndIdxOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerSecuredPduEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerSecuredPduLengthOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerSecuredPduLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerSecuredPduStartIdxOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerSecuredPduStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerSecuredPduUsedOfRxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerSecuredPduUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTpSecuredPduLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTpSecuredPduUsedOfRxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerTpSecuredPduUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedAuthenticatorUsedOfRxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerTruncatedAuthenticatorUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedFreshnessValueUsedOfRxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerTruncatedFreshnessValueUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredRxPduVerficationOfRxPduInfo */
typedef boolean SecOC_SecuredRxPduVerficationOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_TruncAuthStartBitInByteOfRxPduInfo */
typedef uint8 SecOC_TruncAuthStartBitInByteOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_TruncFreshnessValueFirstByteShiftOfRxPduInfo */
typedef uint8 SecOC_TruncFreshnessValueFirstByteShiftOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_TruncFreshnessValueSecondByteShiftOfRxPduInfo */
typedef uint8 SecOC_TruncFreshnessValueSecondByteShiftOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_VerificationStatusPropagationModeOfRxPduInfo */
typedef uint8 SecOC_VerificationStatusPropagationModeOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_VerificationStatusWithSecuredPduPropagationModeOfRxPduInfo */
typedef uint8 SecOC_VerificationStatusWithSecuredPduPropagationModeOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_VerifyAttemptsOfRxPduInfo */
typedef uint8 SecOC_VerifyAttemptsOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_VerifyOverrideStatusIdxOfRxPduInfo */
typedef uint8 SecOC_VerifyOverrideStatusIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_VerifyResultIdxOfRxPduInfo */
typedef uint8 SecOC_VerifyResultIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_truncatedAuthenticationLengthOfRxPduInfo */
typedef uint8 SecOC_truncatedAuthenticationLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_truncatedFreshnessValueLengthOfRxPduInfo */
typedef uint8 SecOC_truncatedFreshnessValueLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_RxPduState */
typedef uint8 SecOC_RxPduStateType;

/**   \brief  value based type definition for SecOC_MessageLinkLenOfRxSecuredPduInfo */
typedef uint8 SecOC_MessageLinkLenOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_MessageLinkPosOfRxSecuredPduInfo */
typedef uint8 SecOC_MessageLinkPosOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_MessageLinkerStartByteInCryptoPduOfRxSecuredPduInfo */
typedef uint8 SecOC_MessageLinkerStartByteInCryptoPduOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_MessageTypeOfRxSecuredPduInfo */
typedef uint8 SecOC_MessageTypeOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_MessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfo */
typedef uint8 SecOC_MessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_MinimumPduLengthOfRxSecuredPduInfo */
typedef uint8 SecOC_MinimumPduLengthOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_PduFixLengthOfRxSecuredPduInfo */
typedef uint8 SecOC_PduFixLengthOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_RxPduInfoIdxOfRxSecuredPduInfo */
typedef uint8 SecOC_RxPduInfoIdxOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerEndIdxOfRxSecuredPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerEndIdxOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerLengthOfRxSecuredPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerLengthOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerStartIdxOfRxSecuredPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerStartIdxOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_RxTpWrittenBytesCounter */
typedef PduLengthType SecOC_RxTpWrittenBytesCounterType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainer */
typedef uint8 SecOC_SecuredPduDataContainerType;

/**   \brief  value based type definition for SecOC_VerifyAttemptsCounter */
typedef uint16 SecOC_VerifyAttemptsCounterType;

/**   \brief  value based type definition for SecOC_VerifyOverrideStatus */
typedef uint8 SecOC_VerifyOverrideStatusType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SecOCPCStructTypes  SecOC Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in SecOC_RxPduInfo */
typedef struct sSecOC_RxPduInfoType
{
  SecOC_AuthenticationLayerIdOfRxPduInfoType AuthenticationLayerIdOfRxPduInfo;
  SecOC_DataIdOfRxPduInfoType DataIdOfRxPduInfo;
  SecOC_SecuredRxPduVerficationOfRxPduInfoType SecuredRxPduVerficationOfRxPduInfo;
  SecOC_AuthDataFreshnessOfRxPduInfoType AuthDataFreshnessOfRxPduInfo;
  SecOC_AuthDataFreshnessLenOfRxPduInfoType AuthDataFreshnessLenOfRxPduInfo;
  SecOC_AuthDataFreshnessStartBytePositionOfRxPduInfoType AuthDataFreshnessStartBytePositionOfRxPduInfo;
  SecOC_AuthenticExternalIdOfRxPduInfoType AuthenticExternalIdOfRxPduInfo;
  SecOC_AuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfoType AuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerAuthenticPduLengthOfRxPduInfoType AuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfoType AuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfoType AuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfo;  /**< the end index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfoType AuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfoType AuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo;  /**< the start index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfoType AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfoType AuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfoType AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticatorCacheEndIdxOfRxPduInfoType AuthenticatorCacheEndIdxOfRxPduInfo;  /**< the end index of the 1:n relation pointing to SecOC_AuthenticatorCache */
  SecOC_AuthenticatorCacheLengthOfRxPduInfoType AuthenticatorCacheLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_AuthenticatorCache */
  SecOC_AuthenticatorCacheStartIdxOfRxPduInfoType AuthenticatorCacheStartIdxOfRxPduInfo;  /**< the start index of the 1:n relation pointing to SecOC_AuthenticatorCache */
  SecOC_BuildAttemptsOfRxPduInfoType BuildAttemptsOfRxPduInfo;
  SecOC_ClientServerVerificationStatusPropagationModeOfRxPduInfoType ClientServerVerificationStatusPropagationModeOfRxPduInfo;
  SecOC_DataIdFirstByteOfRxPduInfoType DataIdFirstByteOfRxPduInfo;
  SecOC_DataIdSecondByteOfRxPduInfoType DataIdSecondByteOfRxPduInfo;
  SecOC_ExternalFreshnessIdOfRxPduInfoType ExternalFreshnessIdOfRxPduInfo;
  SecOC_NumberOfMessagesToOverrideIdxOfRxPduInfoType NumberOfMessagesToOverrideIdxOfRxPduInfo;  /**< the index of the 1:1 relation pointing to SecOC_NumberOfMessagesToOverride */
  SecOC_PduProcessingOfRxPduInfoType PduProcessingOfRxPduInfo;
  SecOC_PduTypeOfRxPduInfoType PduTypeOfRxPduInfo;
  SecOC_RxSecuredPduInfoIdxOfRxPduInfoType RxSecuredPduInfoIdxOfRxPduInfo;  /**< the index of the 1:1 relation pointing to SecOC_RxSecuredPduInfo */
  SecOC_SecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfoType SecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerAuthenticPduLengthOfRxPduInfoType SecuredPduDataContainerAuthenticPduLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfoType SecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerSecuredPduEndIdxOfRxPduInfoType SecuredPduDataContainerSecuredPduEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerSecuredPduLengthOfRxPduInfoType SecuredPduDataContainerSecuredPduLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerSecuredPduStartIdxOfRxPduInfoType SecuredPduDataContainerSecuredPduStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfoType SecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTpSecuredPduLengthOfRxPduInfoType SecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfoType SecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfoType SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfoType SecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfoType SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfoType SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfoType SecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfoType SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_TruncAuthStartBitInByteOfRxPduInfoType TruncAuthStartBitInByteOfRxPduInfo;
  SecOC_TruncFreshnessValueFirstByteShiftOfRxPduInfoType TruncFreshnessValueFirstByteShiftOfRxPduInfo;
  SecOC_TruncFreshnessValueSecondByteShiftOfRxPduInfoType TruncFreshnessValueSecondByteShiftOfRxPduInfo;
  SecOC_VerificationStatusPropagationModeOfRxPduInfoType VerificationStatusPropagationModeOfRxPduInfo;
  SecOC_VerificationStatusWithSecuredPduPropagationModeOfRxPduInfoType VerificationStatusWithSecuredPduPropagationModeOfRxPduInfo;
  SecOC_VerifyAttemptsOfRxPduInfoType VerifyAttemptsOfRxPduInfo;
  SecOC_VerifyOverrideStatusIdxOfRxPduInfoType VerifyOverrideStatusIdxOfRxPduInfo;  /**< the index of the 1:1 relation pointing to SecOC_VerifyOverrideStatus */
  SecOC_VerifyResultIdxOfRxPduInfoType VerifyResultIdxOfRxPduInfo;  /**< the index of the 1:1 relation pointing to SecOC_VerifyResult */
  SecOC_truncatedAuthenticationLengthOfRxPduInfoType truncatedAuthenticationLengthOfRxPduInfo;
  SecOC_truncatedFreshnessValueLengthOfRxPduInfoType truncatedFreshnessValueLengthOfRxPduInfo;
} SecOC_RxPduInfoType;

/**   \brief  type used in SecOC_RxSecuredPduInfo */
typedef struct sSecOC_RxSecuredPduInfoType
{
  SecOC_MessageLinkLenOfRxSecuredPduInfoType MessageLinkLenOfRxSecuredPduInfo;
  SecOC_MessageLinkPosOfRxSecuredPduInfoType MessageLinkPosOfRxSecuredPduInfo;
  SecOC_MessageLinkerStartByteInCryptoPduOfRxSecuredPduInfoType MessageLinkerStartByteInCryptoPduOfRxSecuredPduInfo;
  SecOC_MessageTypeOfRxSecuredPduInfoType MessageTypeOfRxSecuredPduInfo;
  SecOC_MessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfoType MessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfo;
  SecOC_MinimumPduLengthOfRxSecuredPduInfoType MinimumPduLengthOfRxSecuredPduInfo;
  SecOC_PduFixLengthOfRxSecuredPduInfoType PduFixLengthOfRxSecuredPduInfo;
  SecOC_RxPduInfoIdxOfRxSecuredPduInfoType RxPduInfoIdxOfRxSecuredPduInfo;  /**< the index of the 1:1 relation pointing to SecOC_RxPduInfo */
  SecOC_SecuredPduDataContainerEndIdxOfRxSecuredPduInfoType SecuredPduDataContainerEndIdxOfRxSecuredPduInfo;  /**< the end index of the 1:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerLengthOfRxSecuredPduInfoType SecuredPduDataContainerLengthOfRxSecuredPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerStartIdxOfRxSecuredPduInfoType SecuredPduDataContainerStartIdxOfRxSecuredPduInfo;  /**< the start index of the 1:n relation pointing to SecOC_SecuredPduDataContainer */
} SecOC_RxSecuredPduInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCSymbolicStructTypes  SecOC Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to SecOC_AuthenticatorCache */
typedef struct SecOC_AuthenticatorCacheStructSTag
{
  SecOC_AuthenticatorCacheType Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxBckl_Sw_Fx_Stat_ST3_secured_b672d5e7_RxAuthenticatorCache[3];
  SecOC_AuthenticatorCacheType PaddingByte_bed3de0c[5];
  SecOC_AuthenticatorCacheType ELC_Lvr_Stat_ST3_secured_7bad7996_RxELC_Lvr_Stat_ST3_secured_7bad7996_RxAuthenticatorCache[3];
  SecOC_AuthenticatorCacheType Ign_Stat_ST3_secured_87afaf29_RxIgn_Stat_ST3_secured_87afaf29_RxAuthenticatorCache[3];
} SecOC_AuthenticatorCacheStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_NumberOfMessagesToOverride */
typedef struct SecOC_NumberOfMessagesToOverrideStructSTag
{
  SecOC_NumberOfMessagesToOverrideType Ign_Stat_ST3_secured_87afaf29_Rx;
  SecOC_NumberOfMessagesToOverrideType Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx;
  SecOC_NumberOfMessagesToOverrideType ELC_Lvr_Stat_ST3_secured_7bad7996_Rx;
} SecOC_NumberOfMessagesToOverrideStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_RxAuthenticPduSizeOffset */
typedef struct SecOC_RxAuthenticPduSizeOffsetStructSTag
{
  SecOC_RxAuthenticPduSizeOffsetType Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx;
  SecOC_RxAuthenticPduSizeOffsetType ELC_Lvr_Stat_ST3_secured_7bad7996_Rx;
  SecOC_RxAuthenticPduSizeOffsetType Ign_Stat_ST3_secured_87afaf29_Rx;
} SecOC_RxAuthenticPduSizeOffsetStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_RxBuildAttemptsCounter */
typedef struct SecOC_RxBuildAttemptsCounterStructSTag
{
  SecOC_RxBuildAttemptsCounterType Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx;
  SecOC_RxBuildAttemptsCounterType ELC_Lvr_Stat_ST3_secured_7bad7996_Rx;
  SecOC_RxBuildAttemptsCounterType Ign_Stat_ST3_secured_87afaf29_Rx;
} SecOC_RxBuildAttemptsCounterStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_RxPduState */
typedef struct SecOC_RxPduStateStructSTag
{
  SecOC_RxPduStateType Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx;
  SecOC_RxPduStateType ELC_Lvr_Stat_ST3_secured_7bad7996_Rx;
  SecOC_RxPduStateType Ign_Stat_ST3_secured_87afaf29_Rx;
} SecOC_RxPduStateStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_RxTpWrittenBytesCounter */
typedef struct SecOC_RxTpWrittenBytesCounterStructSTag
{
  SecOC_RxTpWrittenBytesCounterType Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx;
  SecOC_RxTpWrittenBytesCounterType ELC_Lvr_Stat_ST3_secured_7bad7996_Rx;
  SecOC_RxTpWrittenBytesCounterType Ign_Stat_ST3_secured_87afaf29_Rx;
} SecOC_RxTpWrittenBytesCounterStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_VerifyAttemptsCounter */
typedef struct SecOC_VerifyAttemptsCounterStructSTag
{
  SecOC_VerifyAttemptsCounterType Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx;
  SecOC_VerifyAttemptsCounterType ELC_Lvr_Stat_ST3_secured_7bad7996_Rx;
  SecOC_VerifyAttemptsCounterType Ign_Stat_ST3_secured_87afaf29_Rx;
} SecOC_VerifyAttemptsCounterStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_VerifyOverrideStatus */
typedef struct SecOC_VerifyOverrideStatusStructSTag
{
  SecOC_VerifyOverrideStatusType Ign_Stat_ST3_secured_87afaf29_Rx;
  SecOC_VerifyOverrideStatusType Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx;
  SecOC_VerifyOverrideStatusType ELC_Lvr_Stat_ST3_secured_7bad7996_Rx;
} SecOC_VerifyOverrideStatusStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_VerifyResult */
typedef struct SecOC_VerifyResultStructSTag
{
  Csm_VerifyResultType Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx;
  Csm_VerifyResultType ELC_Lvr_Stat_ST3_secured_7bad7996_Rx;
  Csm_VerifyResultType Ign_Stat_ST3_secured_87afaf29_Rx;
} SecOC_VerifyResultStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCUnionIndexAndSymbolTypes  SecOC Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access SecOC_AuthenticatorCache in an index and symbol based style. */
typedef union SecOC_AuthenticatorCacheUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_AuthenticatorCacheType raw[11];
  SecOC_AuthenticatorCacheStructSType str;
} SecOC_AuthenticatorCacheUType;

/**   \brief  type to access SecOC_NumberOfMessagesToOverride in an index and symbol based style. */
typedef union SecOC_NumberOfMessagesToOverrideUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_NumberOfMessagesToOverrideType raw[3];
  SecOC_NumberOfMessagesToOverrideStructSType str;
} SecOC_NumberOfMessagesToOverrideUType;

/**   \brief  type to access SecOC_RxAuthenticPduSizeOffset in an index and symbol based style. */
typedef union SecOC_RxAuthenticPduSizeOffsetUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_RxAuthenticPduSizeOffsetType raw[3];
  SecOC_RxAuthenticPduSizeOffsetStructSType str;
} SecOC_RxAuthenticPduSizeOffsetUType;

/**   \brief  type to access SecOC_RxBuildAttemptsCounter in an index and symbol based style. */
typedef union SecOC_RxBuildAttemptsCounterUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_RxBuildAttemptsCounterType raw[3];
  SecOC_RxBuildAttemptsCounterStructSType str;
} SecOC_RxBuildAttemptsCounterUType;

/**   \brief  type to access SecOC_RxPduState in an index and symbol based style. */
typedef union SecOC_RxPduStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_RxPduStateType raw[3];
  SecOC_RxPduStateStructSType str;
} SecOC_RxPduStateUType;

/**   \brief  type to access SecOC_RxTpWrittenBytesCounter in an index and symbol based style. */
typedef union SecOC_RxTpWrittenBytesCounterUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_RxTpWrittenBytesCounterType raw[3];
  SecOC_RxTpWrittenBytesCounterStructSType str;
} SecOC_RxTpWrittenBytesCounterUType;

/**   \brief  type to access SecOC_VerifyAttemptsCounter in an index and symbol based style. */
typedef union SecOC_VerifyAttemptsCounterUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_VerifyAttemptsCounterType raw[3];
  SecOC_VerifyAttemptsCounterStructSType str;
} SecOC_VerifyAttemptsCounterUType;

/**   \brief  type to access SecOC_VerifyOverrideStatus in an index and symbol based style. */
typedef union SecOC_VerifyOverrideStatusUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_VerifyOverrideStatusType raw[3];
  SecOC_VerifyOverrideStatusStructSType str;
} SecOC_VerifyOverrideStatusUType;

/**   \brief  type to access SecOC_VerifyResult in an index and symbol based style. */
typedef union SecOC_VerifyResultUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Csm_VerifyResultType raw[3];
  SecOC_VerifyResultStructSType str;
} SecOC_VerifyResultUType;

/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCRootPointerTypes  SecOC Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to SecOC_AuthenticPduDataContainer */
typedef P2VAR(SecOC_AuthenticPduDataContainerType, TYPEDEF, SECOC_VAR_NO_INIT) SecOC_AuthenticPduDataContainerPtrType;

/**   \brief  type used to point to SecOC_AuthenticatorCache */
typedef P2VAR(SecOC_AuthenticatorCacheType, TYPEDEF, SECOC_VAR_NO_INIT) SecOC_AuthenticatorCachePtrType;

/**   \brief  type used to point to SecOC_Initialized */
typedef P2VAR(SecOC_InitializedType, TYPEDEF, SECOC_VAR_CLEARED) SecOC_InitializedPtrType;

/**   \brief  type used to point to SecOC_NumberOfMessagesToOverride */
typedef P2VAR(SecOC_NumberOfMessagesToOverrideType, TYPEDEF, SECOC_VAR_NO_INIT) SecOC_NumberOfMessagesToOverridePtrType;

/**   \brief  type used to point to SecOC_RxAuthenticPduSizeOffset */
typedef P2VAR(SecOC_RxAuthenticPduSizeOffsetType, TYPEDEF, SECOC_VAR_NO_INIT) SecOC_RxAuthenticPduSizeOffsetPtrType;

/**   \brief  type used to point to SecOC_RxBuildAttemptsCounter */
typedef P2VAR(SecOC_RxBuildAttemptsCounterType, TYPEDEF, SECOC_VAR_NO_INIT) SecOC_RxBuildAttemptsCounterPtrType;

/**   \brief  type used to point to SecOC_RxPduInfo */
typedef P2CONST(SecOC_RxPduInfoType, TYPEDEF, SECOC_CONST) SecOC_RxPduInfoPtrType;

/**   \brief  type used to point to SecOC_RxPduState */
typedef P2VAR(volatile SecOC_RxPduStateType, TYPEDEF, SECOC_VAR_NO_INIT) SecOC_RxPduStatePtrType;

/**   \brief  type used to point to SecOC_RxSecuredPduInfo */
typedef P2CONST(SecOC_RxSecuredPduInfoType, TYPEDEF, SECOC_CONST) SecOC_RxSecuredPduInfoPtrType;

/**   \brief  type used to point to SecOC_RxTpWrittenBytesCounter */
typedef P2VAR(SecOC_RxTpWrittenBytesCounterType, TYPEDEF, SECOC_VAR_NO_INIT) SecOC_RxTpWrittenBytesCounterPtrType;

/**   \brief  type used to point to SecOC_SecuredPduDataContainer */
typedef P2VAR(SecOC_SecuredPduDataContainerType, TYPEDEF, SECOC_VAR_NO_INIT) SecOC_SecuredPduDataContainerPtrType;

/**   \brief  type used to point to SecOC_VerifyAttemptsCounter */
typedef P2VAR(SecOC_VerifyAttemptsCounterType, TYPEDEF, SECOC_VAR_NO_INIT) SecOC_VerifyAttemptsCounterPtrType;

/**   \brief  type used to point to SecOC_VerifyOverrideStatus */
typedef P2VAR(SecOC_VerifyOverrideStatusType, TYPEDEF, SECOC_VAR_NO_INIT) SecOC_VerifyOverrideStatusPtrType;

/**   \brief  type used to point to SecOC_VerifyResult */
typedef P2VAR(Csm_VerifyResultType, TYPEDEF, SECOC_VAR_NO_INIT) SecOC_VerifyResultPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCRootValueTypes  SecOC Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in SecOC_PCConfig */
typedef struct sSecOC_PCConfigType
{
  uint8 SecOC_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} SecOC_PCConfigType;

typedef SecOC_PCConfigType SecOC_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
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
  SecOC_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    SecOC_RxPduInfo
  \details
  Element                                                   Description
  AuthenticationLayerId                                 
  DataId                                                
  SecuredRxPduVerfication                               
  AuthDataFreshness                                     
  AuthDataFreshnessLen                                  
  AuthDataFreshnessStartBytePosition                    
  AuthenticExternalId                                   
  AuthenticPduDataContainerAuthenticPduEndIdx               the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerAuthenticPduLength               the number of relations pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerAuthenticPduStartIdx             the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerDataToAuthenticateEndIdx         the end index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerDataToAuthenticateLength         the number of relations pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerDataToAuthenticateStartIdx       the start index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFreshnessVerifyValueEndIdx       the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFreshnessVerifyValueLength       the number of relations pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFreshnessVerifyValueStartIdx     the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticatorCacheEndIdx                                  the end index of the 1:n relation pointing to SecOC_AuthenticatorCache
  AuthenticatorCacheLength                                  the number of relations pointing to SecOC_AuthenticatorCache
  AuthenticatorCacheStartIdx                                the start index of the 1:n relation pointing to SecOC_AuthenticatorCache
  BuildAttempts                                         
  ClientServerVerificationStatusPropagationMode         
  DataIdFirstByte                                       
  DataIdSecondByte                                      
  ExternalFreshnessId                                   
  NumberOfMessagesToOverrideIdx                             the index of the 1:1 relation pointing to SecOC_NumberOfMessagesToOverride
  PduProcessing                                         
  PduType                                               
  RxSecuredPduInfoIdx                                       the index of the 1:1 relation pointing to SecOC_RxSecuredPduInfo
  SecuredPduDataContainerAuthenticPduEndIdx                 the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerAuthenticPduLength                 the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerAuthenticPduStartIdx               the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerSecuredPduEndIdx                   the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerSecuredPduLength                   the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerSecuredPduStartIdx                 the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTpSecuredPduEndIdx                 the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTpSecuredPduLength                 the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTpSecuredPduStartIdx               the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedAuthenticatorEndIdx       the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedAuthenticatorLength       the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedAuthenticatorStartIdx     the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedFreshnessValueEndIdx      the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedFreshnessValueLength      the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedFreshnessValueStartIdx    the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  TruncAuthStartBitInByte                               
  TruncFreshnessValueFirstByteShift                     
  TruncFreshnessValueSecondByteShift                    
  VerificationStatusPropagationMode                     
  VerificationStatusWithSecuredPduPropagationMode       
  VerifyAttempts                                        
  VerifyOverrideStatusIdx                                   the index of the 1:1 relation pointing to SecOC_VerifyOverrideStatus
  VerifyResultIdx                                           the index of the 1:1 relation pointing to SecOC_VerifyResult
  truncatedAuthenticationLength                         
  truncatedFreshnessValueLength                         
*/ 
#define SECOC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SecOC_RxPduInfoType, SECOC_CONST) SecOC_RxPduInfo[3];
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxSecuredPduInfo
**********************************************************************************************************************/
/** 
  \var    SecOC_RxSecuredPduInfo
  \details
  Element                              Description
  MessageLinkLen                   
  MessageLinkPos                   
  MessageLinkerStartByteInCryptoPdu
  MessageType                      
  MessagesLinkCryptoPduSrcBitOffset
  MinimumPduLength                 
  PduFixLength                     
  RxPduInfoIdx                         the index of the 1:1 relation pointing to SecOC_RxPduInfo
  SecuredPduDataContainerEndIdx        the end index of the 1:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerLength        the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerStartIdx      the start index of the 1:n relation pointing to SecOC_SecuredPduDataContainer
*/ 
#define SECOC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SecOC_RxSecuredPduInfoType, SECOC_CONST) SecOC_RxSecuredPduInfo[3];
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_AuthenticPduDataContainer
**********************************************************************************************************************/
#define SECOC_START_SEC_CRYPTO_DRV_ALIGNED_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_AuthenticPduDataContainerType, SECOC_VAR_NO_INIT) SecOC_AuthenticPduDataContainer[35];
#define SECOC_STOP_SEC_CRYPTO_DRV_ALIGNED_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_AuthenticatorCache
**********************************************************************************************************************/
#define SECOC_START_SEC_CRYPTO_DRV_ALIGNED_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_AuthenticatorCacheUType, SECOC_VAR_NO_INIT) SecOC_AuthenticatorCache;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_CRYPTO_DRV_ALIGNED_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_Initialized
**********************************************************************************************************************/
/** 
  \var    SecOC_Initialized
  \brief  Initialization state of SecOC. TRUE, if SecOC_Init() has been called, else FALSE.
*/ 
#define SECOC_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_InitializedType, SECOC_VAR_CLEARED) SecOC_Initialized;
#define SECOC_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_NumberOfMessagesToOverride
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_NumberOfMessagesToOverrideUType, SECOC_VAR_NO_INIT) SecOC_NumberOfMessagesToOverride;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxAuthenticPduSizeOffset
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_RxAuthenticPduSizeOffsetUType, SECOC_VAR_NO_INIT) SecOC_RxAuthenticPduSizeOffset;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxBuildAttemptsCounter
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_RxBuildAttemptsCounterUType, SECOC_VAR_NO_INIT) SecOC_RxBuildAttemptsCounter;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxPduState
**********************************************************************************************************************/
/** 
  \var    SecOC_RxPduState
  \brief  The state variable is volatile because it is used to ensure data consistency
*/ 
#define SECOC_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(SecOC_RxPduStateUType, SECOC_VAR_NO_INIT) SecOC_RxPduState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxTpWrittenBytesCounter
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_RxTpWrittenBytesCounterUType, SECOC_VAR_NO_INIT) SecOC_RxTpWrittenBytesCounter;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_SecuredPduDataContainer
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_SecuredPduDataContainerType, SECOC_VAR_NO_INIT) SecOC_SecuredPduDataContainer[24];
#define SECOC_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_VerifyAttemptsCounter
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_VerifyAttemptsCounterUType, SECOC_VAR_NO_INIT) SecOC_VerifyAttemptsCounter;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_VerifyOverrideStatus
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_VerifyOverrideStatusUType, SECOC_VAR_NO_INIT) SecOC_VerifyOverrideStatus;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_VerifyResult
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_VerifyResultUType, SECOC_VAR_NO_INIT) SecOC_VerifyResult;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SecOC_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
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


#endif  /* SECOC_LCFG_H */
/**********************************************************************************************************************
  END OF FILE: SecOC_Lcfg.h
**********************************************************************************************************************/


