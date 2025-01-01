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
 *              File: SecOC_Cbk.h
 *   Generation Time: 2023-07-10 14:36:03
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (SECOC_CBK_H)
# define SECOC_CBK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "SecOC_Types.h"
#include "SecOC_Cot.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define SECOC_START_SEC_CODE
#include "SecOC_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#if (SECOC_COMMUNICATION_INTERFACE == STD_ON)
/***********************************************************************************************************************
 *  SecOC_RxIndication()
 **********************************************************************************************************************/
/*! \brief      Callback is called when a Secured I-PDU is received.
 *  \details    Called by the PduR to indicate direct reception of a Secured I-PDU from a lower layer communication 
 *              interface. This call triggers the verification of the received Secured I-PDU. 
 *  \param[in]  id              ID of the received Secured I-PDU.
 *  \param[in]  info            A pointer to a structure with Secured I-PDU related data: 
 *                              data length and pointer to I-SDU buffer.
 *  \trace      SPEC-2697652, SPEC-2697665, SPEC-2697666
 *  \context    TASK|ISR2
 *  \synchronous TRUE
 *  \reentrant  TRUE, for different PduIds.
 **********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_RxIndication(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) info);

# if (SECOC_TX_CONFIRMATION_API == STD_ON)
/***********************************************************************************************************************
 *  SecOC_TxConfirmation()
 **********************************************************************************************************************/
/*! \brief     Callback is called to confirm a transmission. 
 *  \details   The lower layer communication interface module confirms the transmission of a Secured I-PDU via PduR. 
 *  \param[in] id             ID of the transmitted Secured I-PDU.  
 *  \trace     SPEC-2697632, SPEC-2697633, SPEC-2697665, SPEC-2697666
 *  \context    TASK|ISR2
 *  \synchronous TRUE
 *  \reentrant  TRUE, for different PduIds.
 **********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_TxConfirmation(PduIdType id);
# endif

# if (SECOC_TRIGGER_TRANSMIT_API == STD_ON)
/***********************************************************************************************************************
 *  SecOC_TriggerTransmit()
 **********************************************************************************************************************/
/*! \brief     Callback is called ba the Lower Layer to get a Secured I-PDU.
 *  \details   The function is called when a lower layer communication module expects a Secured I-PDU to be transmitted.
 *             The SecOC module copies the Secured I-PDU into the buffer of the lower layer communication module.
 *  \param[in]      id            ID of the Authentic I-PDU to be transmitted.
 *  \param[in,out]  info          Contains a pointer to a buffer (SduDataPtr) where the SDU
 *                                data shall be copied to, and the available buffer size in SduLengh.
 *                                On return, the service will indicate the length of the copied SDU
 *                                data in SduLength.
 *  \return         E_OK          SDU has been copied and SduLength indicates the number of copied bytes.
 *  \return         E_NOT_OK      No data has been copied, because
 *                                SecOC is not initialized
 *                                or TxPduId is not valid
 *                                or PduInfoPtr is NULL_PTR
 *                                or SduDataPtr is NULL_PTR
 *                                or SduLength is too small
 *  \trace     SPEC-2697637, SPEC-2697638, SPEC-2697665, SPEC-2697666
 *  \context    TASK|ISR2
 *  \synchronous TRUE
 *  \reentrant  TRUE, for different PduIds.
 **********************************************************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_TriggerTransmit(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, SECOC_APPL_VAR) info);
# endif
#endif

#if (SECOC_TRANSPORT_PROTOCOL == STD_ON)
/***********************************************************************************************************************
 *  SecOC_TpRxIndication()
 **********************************************************************************************************************/
/*! \brief     Callback is called to indicate a completed reception.
 *  \details   The function is called after an I-PDU has been received via the TP API, the result indicates whether
 *             the transmission was successful or not. 
 *  \param[in] id             Identification of the received I-PDU. 
 *  \param[in] result         Result of the reception. 
 *  \trace     SPEC-2697657, SPEC-2697661, SPEC-2697665, SPEC-2697666
 *  \context    TASK|ISR2
 *  \synchronous TRUE
 *  \reentrant  TRUE, for different PduIds.
 **********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_TpRxIndication(PduIdType id, Std_ReturnType result);

/***********************************************************************************************************************
 *  SecOC_TpTxConfirmation()
 **********************************************************************************************************************/
/*! \brief     Callback is called to indicate a completed transmission.
 *  \details   This function is called after the I-PDU has been transmitted on its network, the 
 *             result indicates whether the transmission was successful or not.
 *  \param[in] id             Identification of the transmitted I-PDU.
 *  \param[in] result         Result of the transmission of the I-PDU. 
 *  \trace     SPEC-2697645, SPEC-2697665, SPEC-2697666
 *  \context    TASK|ISR2
 *  \synchronous TRUE
 *  \reentrant  TRUE, for different PduIds.
 **********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_TpTxConfirmation(PduIdType id, Std_ReturnType result);

/***********************************************************************************************************************
 *  SecOC_CopyRxData()
 **********************************************************************************************************************/
/*! \brief      This callback copies the received I-PDU segment.
 *  \details    This function is called to provide the received data of an I-PDU segment (N-PDU) to the upper layer. 
 *              Each call to this function provides the next part of the I-PDU data. 
 *              The size of the remaining data is written to the position indicated by bufferSizePtr.
 *  \param[in]  id            Identification of the received I-PDU.
 *  \param[in]  info          Provides the source buffer (SduDataPtr) and the number of bytes to be copied (SduLength). 
 *                            An SduLength of 0 can be used to query the current amount of available buffer in the upper
 *                            layer module. In this case, the SduDataPtr may be a NULL_PTR. 
 *  \param[out] bufferSizePtr Available receive buffer after data has been copied.
 *  \return     BufReq_ReturnType
 *              BUFREQ_OK:       Data copied successfully.
 *              BUFREQ_E_NOT_OK: Data was not copied because an error occurred. 
 *  \trace      SPEC-3053579, SPEC-2697665, SPEC-2697666
 *  \context    TASK|ISR2
 *  \synchronous TRUE
 *  \reentrant  TRUE, for different PduIds.
 **********************************************************************************************************************/
FUNC(BufReq_ReturnType, SECOC_CODE) SecOC_CopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) bufferSizePtr);

/***********************************************************************************************************************
 *  SecOC_CopyTxData()
 **********************************************************************************************************************/
/*! \brief      This callback copies the transmitted I-PDU segment.
 *  \details    This function is called to acquire the transmit data of an I-PDU segment (N-PDU). 
 *              Each call to this function provides the next part of the I-PDU data unless retry->TpDataState is TP_DATARETRY.
 *              In this case the function restarts to copy the data beginning at the offset from the current position 
 *              indicated by retry->TxTpDataCnt. The size of the remaining data is written to the position indicated 
 *              by availableDataPtr. 
 *  \param[in]  id            Identification of the transmitted I-PDU.
 *  \param[in]  info          Provides the destination buffer (SduDataPtr) and the number of bytes to be copied (SduLength). 
 *                            If not enough transmit data is available, no data is copied by the upper layer module and 
 *                            BUFREQ_E_BUSY is returned. The lower layer module may retry the call. 
 *                            An SduLength of 0 can be used to indicate state changes in the retry parameter or to query 
 *                            the current amount of available data in the upper layer module. In this case, the 
 *                            SduDataPtr may be a NULL_PTR.
 *  \param[in]  retry         This parameter is used to acknowledge transmitted data or to retransmit data after transmission problems. 
 *                            If the retry parameter is a NULL_PTR, it indicates that the transmit data can be removed from the buffer immediately 
 *                            after it has been copied. Otherwise, the retry parameter must point to a valid RetryInfoType element. 
 *                            If TpDataState indicates TP_CONFPENDING, the previously copied data must remain in the TP buffer to be available for error recovery. 
 *                            TP_DATACONF indicates that all data that has been copied before this call is confirmed and can be removed from the 
 *                            TP buffer. Data copied by this API call is excluded and will be confirmed later. 
 *                            TP_DATARETRY this parameter will lead to the negative return of BUFREQ_E_NOT_OK.
 *  \param[out] availableDataPtr Indicates the remaining number of bytes that are available in the upper layer module's Tx buffer. 
 *                               availableDataPtr can be used by TP modules that support dynamic payload lengths 
 *                               (e.g. FrIsoTp) to determine the size of the following CFs.
 *  \return     BufReq_ReturnType
 *              BUFREQ_OK:       Data has been copied to the transmit buffer completely as requested. 
 *              BUFREQ_E_BUSY:   Request could not be fulfilled, because the required amount of Tx data is not available. 
 *                               The lower layer module may retry this call later on. No data has been copied.
 *              BUFREQ_E_NOT_OK: Data has not been copied. Request failed. 
 *  \trace      SPEC-2697643, SPEC-2697665, SPEC-2697666
 *  \context    TASK|ISR2
 *  \synchronous TRUE
 *  \reentrant  TRUE, for different PduIds.
 **********************************************************************************************************************/
FUNC(BufReq_ReturnType, SECOC_CODE) SecOC_CopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, SECOC_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) availableDataPtr);

/***********************************************************************************************************************
 *  SecOC_StartOfReception()
 **********************************************************************************************************************/
/*! \brief      This callback is called to indicate the start of a segmented reception.
 *  \details    This function is called at the start of receiving an N-SDU. The N-SDU might be fragmented into multiple N-PDUs 
 *              (FF with one or more following CFs) or might consist of a single N-PDU (SF). 
 *  \param[in]  id            Identification of the I-PDU.
 *  \param[in]  info          Pointer to a PduInfoType structure containing the payload data (without protocol information) 
 *                            and payload length of the first frame or single frame of a transport protocol I-PDU reception. 
 *                            Depending on the global parameter MetaDataLength, additional bytes containing MetaData 
 *                            (e.g. the CAN ID) are appended after the payload data, increasing the length accordingly. 
 *                            If neither first/single frame data nor MetaData are available, this parameter is set to NULL_PTR. 
 *  \param[in]  TpSduLength   Total length of the N-SDU to be received. 
 *  \param[out] bufferSizePtr Available receive buffer in the receiving module. This parameter will be used to compute the 
 *                            Block Size (BS) in the transport protocol module. 
 *  \return     BufReq_ReturnType 
 *              BUFREQ_OK:       Connection has been accepted. bufferSizePtr indicates the available receive buffer; reception is continued. 
 *                               If no buffer of the requested size is available, a receive buffer size of 0 shall be indicated by bufferSizePtr. 
 *              BUFREQ_E_NOT_OK: Connection has been rejected; reception is aborted. bufferSizePtr remains unchanged. 
 *              BUFREQ_E_OVFL:   No buffer of the required length can be provided; reception is aborted. bufferSizePtr remains unchanged. 
 *  \trace      SPEC-2968991, SPEC-2697665, SPEC-2697666
 *  \context    TASK|ISR2
 *  \synchronous TRUE
 *  \reentrant  TRUE, for different PduIds.
 **********************************************************************************************************************/
FUNC(BufReq_ReturnType, SECOC_CODE) SecOC_StartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) bufferSizePtr);
#endif /* (SECOC_TRANSPORT_PROTOCOL == STD_ON) */

#if (SECOC_CANCEL_TRANSMIT_API == STD_ON)
/***********************************************************************************************************************
 *  SecOC_CancelTransmit()
 **********************************************************************************************************************/
/*! \brief      Requests cancellation of an ongoing transmission of a PDU in a lower layer communication module. 
 *  \details    This function forwards the cancellation request to the lower layer transport module.
 *  \param[in]  TxPduId     Identification of the I-PDU. 
 *  \return     Std_ReturnType 
 *              E_OK: Cancellation was executed successfully by the destination module. 
 *              E_NOT_OK: Cancellation was rejected by the destination module. 
 *  \context    TASK|ISR2
 *  \synchronous TRUE
 *  \reentrant  TRUE, for different PduIds.
 **********************************************************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_CancelTransmit(PduIdType TxPduId);
#endif

#define SECOC_STOP_SEC_CODE
#include "SecOC_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif  /* SECOC_CBK_H */
/**********************************************************************************************************************
  END OF FILE: SecOC_Cbk.h
**********************************************************************************************************************/
